/*
* File:    papi_pfm_events.c
* CVS:     $Id$
* Author:  Dan Terpstra: blantantly extracted from Phil's perfmon.c
*          mucci@cs.utk.edu
*/

/* TODO LIST:
    - Events for all platforms
xxx - Derived events for all platforms
xxx - hwd_ntv_name_to_code
xxx - Make native map carry major events, not umasks
xxx - Enum event uses native_map not pfm()
xxx - bits_to_info uses native_map not pfm()
*/

#include "papi.h"
#include "papi_internal.h"
#include "papi_vector.h"
#include "papi_memory.h"
#include "papi_pfm_events.h"

extern papi_vector_t MY_VECTOR;

/* These routines are defined externally for PERFCTR_PFM_EVENTS == TRUE, or
    internally for PERFCTR_PFM_EVENTS == FALSE */
extern int _papi_pfm_ntv_code_to_bits(unsigned int EventCode, hwd_register_t * bits);
extern int _papi_pfm_ntv_bits_to_info(hwd_register_t *bits, char *names,
                               unsigned int *values, int name_len, int count);

/* Globals declared extern elsewhere */

volatile unsigned int _papi_hwd_lock_data[PAPI_MAX_LOCK];

/* NOTE: PAPI stores umask info in a variable sized bitfield.
    Perfmon2 stores umask info in a 16 element array of values.
    Native event encodings for perfmon2 contain array indices
    encoded as bits in this bitfield. These indices must be converted
    into a umask value before programming the counters. For Perfmon,
    this is done by converting back to an array of values; for 
    perfctr, it must be done by looking up the values.
*/

/* This routine is used to step through all possible combinations of umask
    values. It assumes that mask contains a valid combination of array indices
    for this event. */
static inline int encode_native_event_raw(unsigned int event, unsigned int mask)
{
  unsigned int tmp = event << PAPI_NATIVE_EVENT_SHIFT;
  SUBDBG("Old native index was 0x%08x with 0x%08x mask\n",tmp,mask);
  tmp = tmp | (mask << PAPI_NATIVE_UMASK_SHIFT);
  SUBDBG("New encoding is 0x%08x\n",tmp|PAPI_NATIVE_MASK);
  return(tmp|PAPI_NATIVE_MASK);
}

/* This routine converts array indices contained in the mask_values array
    into bits in the umask field that is OR'd into the native event code.
    These bits are NOT the mask values themselves, but indices into an array
    of mask values contained in the native event table. */
static inline int encode_native_event(unsigned int event, unsigned int num_mask, unsigned int *mask_values)
{
  int i;
  unsigned int tmp = event << PAPI_NATIVE_EVENT_SHIFT;
  SUBDBG("Native base event is 0x%08x with %d masks\n",tmp,num_mask);
  for (i=0;i<num_mask;i++) {
      SUBDBG("Mask index is 0x%08x\n",mask_values[i]);
      tmp = tmp | ((1 << mask_values[i]) << PAPI_NATIVE_UMASK_SHIFT);
  }
  SUBDBG("Full native encoding is 0x%08x\n",tmp|PAPI_NATIVE_MASK);
  return(tmp|PAPI_NATIVE_MASK);
}

static int setup_preset_term(int *native, pfmlib_event_t *event)
{
    /* It seems this could be greatly simplified. If impl_cnt is non-zero,
	the event lives on a counter. Therefore the entire routine could be:
	if (impl_cnt!= 0) encode_native_event.
	Am I wrong?
    */
  pfmlib_regmask_t impl_cnt, evnt_cnt;
  int n, j, ret;

  /* find out which counters it lives on */
  if ((ret = pfm_get_event_counters(event->event,&evnt_cnt)) != PFMLIB_SUCCESS)
    {
      PAPIERROR("pfm_get_event_counters(%d,%p): %s",event->event,&evnt_cnt,pfm_strerror(ret));
      return(PAPI_EBUG);
    }
  if ((ret = pfm_get_impl_counters(&impl_cnt)) != PFMLIB_SUCCESS)
    {
      PAPIERROR("pfm_get_impl_counters(%p): %s", &impl_cnt, pfm_strerror(ret));
      return(PAPI_EBUG);
    }

  /* Make sure this event lives on some counter, if so, put in the description. If not, BUG */
  if ((ret = pfm_get_num_counters(&n)) != PFMLIB_SUCCESS)
    {
      PAPIERROR("pfm_get_num_counters(%d): %s", n, pfm_strerror(ret));
      return(PAPI_EBUG);
    }

  for (j=0;n;j++)
    {
      if (pfm_regmask_isset(&impl_cnt, j))
	{
	  n--;
	  if (pfm_regmask_isset(&evnt_cnt,j))
	    {
	      *native = encode_native_event(event->event,event->num_masks,event->unit_masks);
	      return(PAPI_OK);
	    }
	}
    }

  PAPIERROR("PAPI preset 0x%08x PFM event %d did not have any available counters", event->event, j);
  return(PAPI_ENOEVNT);
}

/*  Trims blank space from both ends of a string (in place).
    Returns pointer to new start address */
static inline char *trim_string(char *in)
{
  int len, i = 0;
  char *start = in;

  if (in == NULL)
    return(in);
  len = strlen(in);
  if (len == 0)
    return(in);
  /* Trim left */
  while (i < len)
    {
      if (isblank(in[i]))
	{
	  in[i] = '\0';
	  start++;
	}
      else
	break;
      i++;
    }
  /* Trim right */
  i = strlen(start) - 1;
  while (i >= 0)
    {
      if (isblank(start[i]))
	start[i] = '\0';
      else
	break;
      i--;
    }
  return(start);
}


/*  Calls trim_string to remove blank space;
    Removes paired punctuation delimiters from
    beginning and end of string. If the same punctuation 
    appears first and last (quotes, slashes) they are trimmed;
    Also checks for the following pairs: () <> {} [] */
static inline char *trim_note(char *in)
{
  int len;
  char *note, start, end;

  note = trim_string(in);
  if (note != NULL) {
    len = strlen(note);
    if (len > 0) {
      if (ispunct(*note)) {
	start = *note;
	end = note[len-1];
	if ((start == end)
	    || ((start == '(') && (end == ')'))
	    || ((start == '<') && (end == '>'))
	    || ((start == '{') && (end == '}'))
	    || ((start == '[') && (end == ']'))) {
	  note[len-1] = '\0';
	  *note = '\0';
	  note++;
	}
      }
    }
  }
  return(note);
}

static inline int find_preset_code(char *tmp, int *code)
{
  int i = 0;
  extern hwi_presets_t _papi_hwi_presets;
  while (_papi_hwi_presets.info[i].symbol != NULL)
    {
      if (strcasecmp(tmp,_papi_hwi_presets.info[i].symbol) == 0)
	{
	  *code = i|PAPI_PRESET_MASK;
	  return(PAPI_OK);
	}
      i++;
    }
  return(PAPI_EINVAL);
}

/* Static version of the perfmon csv file. */
#if defined(STATIC_PERFMON_EVENTS_TABLE)
#include "perfmon_events_table.h"
#endif

/* #define SHOW_LOADS */

static int load_preset_table(char *pmu_name, int pmu_type, pfm_preset_search_entry_t *here)
{
  char name[PATH_MAX], line[LINE_MAX];
#if !defined(STATIC_PERFMON_EVENTS_TABLE)
  char *tmpn;
  FILE *table;
#endif
  int line_no = 1, get_presets = 0, derived = 0, insert = 2, preset = 0;

#ifdef SHOW_LOADS
  SUBDBG("%p\n",here);
#endif

  here[0].preset = PAPI_TOT_CYC;
  here[0].derived = NOT_DERIVED;
  here[1].preset = PAPI_TOT_INS;
  here[1].derived = NOT_DERIVED;

#if !defined(STATIC_PERFMON_EVENTS_TABLE)
  if ((tmpn = getenv("PAPI_PERFMON_EVENT_FILE")) && (strlen(tmpn) != 0))
    sprintf(name,"%s",tmpn);
  else
#ifdef PAPI_DATADIR
    sprintf(name,"%s/%s",PAPI_DATADIR,PERFMON_EVENT_FILE);
#else
    sprintf(name,"%s",PERFMON_EVENT_FILE);
#endif
  SUBDBG("Opening %s\n",name);
  table = fopen(name,"r");
  if (table == NULL)
    {
      SUBDBG("Open %s failed, trying ./%s.\n",name,PERFMON_EVENT_FILE);
      table = fopen(PERFMON_EVENT_FILE,"r");
      if (table == NULL)
	{
	  PAPIERROR("fopen(%s): %s, please set the PAPI_PERFMON_EVENT_FILE env. variable",name,strerror(errno));
	  return(PAPI_ESYS);
	}
      strcpy(name,PERFMON_EVENT_FILE);
    }
  SUBDBG("Open %s succeeded.\n",name);
  while (fgets(line,LINE_MAX,table))
    {
      char *t;
      int i;
      i = strlen(line);
      if (line[i-1] == '\n')
	line[i-1] = '\0';
#else
  SUBDBG("Reading from static perfmon_events_table.\n");
  while (*perfmon_events_table)
    {
      char *t;
      int i;
      for (i=0; *perfmon_events_table && *perfmon_events_table != '\n'; i++) {
        line[i] = *perfmon_events_table++;
      }
      if (*perfmon_events_table == '\n') {
        perfmon_events_table++;
      }
      line[i] = '\0';
#endif
      t = trim_string(strtok(line,","));
      if ((t == NULL) || (strlen(t) == 0))
	continue;
      if (t[0] == '#')
	{
/*	  SUBDBG("Comment found on line %d\n",line_no); */
	  goto nextline;
	}
      else if (strcasecmp(t,"CPU") == 0)
	{
#ifdef SHOW_LOADS
	  SUBDBG("CPU token found on line %d\n",line_no);
#endif
	  if (get_presets != 0)
	    {
#ifdef SHOW_LOADS
	      SUBDBG("Ending preset scanning at line %d of %s.\n",line_no,name);
#endif
	      goto done;
	    }
	  t = trim_string(strtok(NULL,","));
	  if ((t == NULL) || (strlen(t) == 0))
	    {
	      PAPIERROR("Expected name after CPU token at line %d of %s -- ignoring",line_no,name);
	      goto nextline;
	    }
#ifdef SHOW_LOADS
	  SUBDBG("Examining CPU (%s) vs. (%s)\n",t,pmu_name);
#endif
	  if (strcasecmp(t, pmu_name) == 0)
	    {
	      int type;

#ifdef SHOW_LOADS
	      SUBDBG("Found CPU %s at line %d of %s.\n",t,line_no,name);
#endif
	      t = trim_string(strtok(NULL,","));
	      if ((t == NULL) || (strlen(t) == 0))
		{
#ifdef SHOW_LOADS
		  SUBDBG("No additional qualifier found, matching on string.\n");
#endif
		  get_presets = 1;
		}
	      else if ((sscanf(t,"%d",&type) == 1) && (type == pmu_type))
		{
#ifdef SHOW_LOADS
		  SUBDBG("Found CPU %s type %d at line %d of %s.\n",pmu_name,type,line_no,name);
#endif
		  get_presets = 1;
		}
	      else
#ifdef SHOW_LOADS
		SUBDBG("Additional qualifier match failed %d vs %d.\n",pmu_type,type)
#endif
	      ;
	    }
	}
      else if (strcasecmp(t,"PRESET") == 0)
	{
#ifdef SHOW_LOADS
	  SUBDBG("PRESET token found on line %d\n",line_no);
#endif
	  if (get_presets == 0)
	    goto nextline;
	  t = trim_string(strtok(NULL,","));
	  if ((t == NULL) || (strlen(t) == 0))
	    {
	      PAPIERROR("Expected name after PRESET token at line %d of %s -- ignoring",line_no,name);
	      goto nextline;
	    }
#ifdef SHOW_LOADS
	  SUBDBG("Examining preset %s\n",t);
#endif
	  if (find_preset_code(t,&preset) != PAPI_OK)
	    {
	      PAPIERROR("Invalid preset name %s after PRESET token at line %d of %s -- ignoring",t,line_no,name);
	      goto nextline;
	    }
#ifdef SHOW_LOADS
	  SUBDBG("Found 0x%08x for %s\n",preset,t);
#endif
	  t = trim_string(strtok(NULL,","));
	  if ((t == NULL) || (strlen(t) == 0))
	    {
	      PAPIERROR("Expected derived type after PRESET token at line %d of %s -- ignoring",line_no,name);
	      goto nextline;
	    }
#ifdef SHOW_LOADS
	  SUBDBG("Examining derived %s\n",t);
#endif
	  if (_papi_hwi_derived_type(t,&derived) != PAPI_OK)
	    {
	      PAPIERROR("Invalid derived name %s after PRESET token at line %d of %s -- ignoring",t,line_no,name);
	      goto nextline;
	    }
#ifdef SHOW_LOADS
	  SUBDBG("Found %d for %s\n",derived,t);
	  SUBDBG("Adding 0x%x,%d to preset search table.\n",preset,derived);
#endif
	  here[insert].preset = preset;
	  here[insert].derived = derived;

	  /* Derived support starts here */
	  /* Special handling for postfix */
	  if (derived == DERIVED_POSTFIX) {
	    t = trim_string(strtok(NULL,","));
	    if ((t == NULL) || (strlen(t) == 0)) {
	      PAPIERROR("Expected Operation string after derived type DERIVED_POSTFIX at line %d of %s -- ignoring",line_no,name);
	      goto nextline;
	    }
#ifdef SHOW_LOADS
	    SUBDBG("Saving PostFix operations %s\n",t);
#endif
	    here[insert].operation = strdup(t);
	  }
	  /* All derived terms collected here */
	  i = 0;
	  do {
	    t = trim_string(strtok(NULL,","));
	    if ((t == NULL) || (strlen(t) == 0)) break;
	    if (strcasecmp(t,"NOTE") == 0) break;
	    here[insert].findme[i] = strdup(t);
#ifdef SHOW_LOADS
	    SUBDBG("Adding term (%d) %s to preset event 0x%x.\n",i,t,preset);
#endif
	  } while (++i < MAX_COUNTER_TERMS);
	  /* End of derived support */

	  if (i == 0) {
	    PAPIERROR("Expected PFM event after DERIVED token at line %d of %s -- ignoring",line_no,name);
	    goto nextline;
	  }
	  if (i == MAX_COUNTER_TERMS)
	    t = trim_string(strtok(NULL,","));

	  /* Handle optional NOTEs */
	  if (t && (strcasecmp(t,"NOTE") == 0)) {
#ifdef SHOW_LOADS
	    SUBDBG("%s found on line %d\n",t,line_no);
#endif
	    t = trim_note(strtok(NULL,"")); /* read the rest of the line */
	    if ((t == NULL) || (strlen(t) == 0))
	      PAPIERROR("Expected Note string at line %d of %s\n",line_no,name);
	    else {
	      here[insert].note = strdup(t);
#ifdef SHOW_LOADS
	      SUBDBG("NOTE: --%s-- found on line %d\n",t,line_no);
#endif
	    }
	  }

	  insert++;
	}
      else
	{
	  PAPIERROR("Unrecognized token %s at line %d of %s -- ignoring",t,line_no,name);
	  goto nextline;
	}
    nextline:
      line_no++;
    }
 done:
#if !defined(STATIC_PERFMON_EVENTS_TABLE)
  fclose(table);
#endif
  if (get_presets != 0) /* It at least found the CPU */
    {
      return(PAPI_OK);
    }

  PAPIERROR("Failed to find events for CPU %s, type %d in %s",pmu_name,pmu_type,name);
  return(PAPI_ESBSTR);
}

/* Frees memory for all the strdup'd char strings in a preset string array.
    Assumes the array is initialized to 0 and has at least one 0 entry at the end.
    free()ing a NULL pointer is a NOP. */
static void free_preset_table(pfm_preset_search_entry_t *here)
{
    int i = 0, j;
    while (here[i].preset) {
      for (j=0;j<MAX_COUNTER_TERMS;j++)
	free(here[i].findme[j]);
      free(here[i].operation);
      free(here[i].note);
      i++;
    }
}

static void free_notes(hwi_dev_notes_t *here)
{
    int i = 0;
    while (here[i].event_code) {
      free(here[i].dev_note);
      i++;
    }
}

static int generate_preset_search_map(hwi_search_t **maploc, hwi_dev_notes_t **noteloc, pfm_preset_search_entry_t *strmap)
{
  int i = 0, j = 0, k = 0, term, ret;
  hwi_search_t *psmap;
  hwi_dev_notes_t *notemap;
  pfmlib_event_t event;

  /* Count up the proposed presets */
  while (strmap[i].preset)
    i++;
  SUBDBG("generate_preset_search_map(%p,%p,%p) %d proposed presets\n",maploc,noteloc,strmap,i);
  i++;

  /* Add null entry */
  psmap = (hwi_search_t *)malloc(i*sizeof(hwi_search_t));
  notemap = (hwi_dev_notes_t *)malloc(i*sizeof(hwi_dev_notes_t));
  if ((psmap == NULL) || (notemap == NULL))
    return(PAPI_ENOMEM);
  memset(psmap,0x0,i*sizeof(hwi_search_t));
  memset(notemap,0x0,i*sizeof(hwi_dev_notes_t));

  i = 0;
  while (strmap[i].preset)
  {
      if (strmap[i].preset == PAPI_TOT_CYC)
      {
	  SUBDBG("pfm_get_cycle_event(%p)\n",&event);
	  if ((ret = pfm_get_cycle_event(&event)) == PFMLIB_SUCCESS)
	  {
	      if (setup_preset_term(&psmap[j].data.native[0], &event) == PAPI_OK)
	      {
		psmap[j].event_code = strmap[i].preset;
		psmap[j].data.derived = strmap[i].derived;
		psmap[j].data.native[1] = PAPI_NULL;
		j++;
	      }
	  }
	  else
	    PAPIERROR("pfm_get_cycle_event(%p): %s",&event, pfm_strerror(ret));
      }
      else if (strmap[i].preset == PAPI_TOT_INS) 
      {
	  SUBDBG("pfm_get_inst_retired_event(%p)\n",&event);
	  if ((ret = pfm_get_inst_retired_event(&event)) == PFMLIB_SUCCESS)
	  {
	      if (setup_preset_term(&psmap[j].data.native[0], &event) == PAPI_OK)
	      {
		psmap[j].event_code = strmap[i].preset;
		psmap[j].data.derived = strmap[i].derived;
		psmap[j].data.native[1] = PAPI_NULL;
		j++;
	      }
	  }
	  else
	    PAPIERROR("pfm_get_inst_retired_event(%p): %s",&event, pfm_strerror(ret));	    
      }
      else
      {
	  /* Handle derived events */
	  term = 0;
	  do {
	      SUBDBG("pfm_find_full_event(%s,%p)\n",strmap[i].findme[term],&event);
	      if ((ret = pfm_find_full_event(strmap[i].findme[term],&event)) == PFMLIB_SUCCESS)
	      {
		if ((ret = setup_preset_term(&psmap[j].data.native[term], &event)) == PAPI_OK)
		{
		    term++;
		}
		else break;
	      }
	      else {
		PAPIERROR("pfm_find_full_event(%s,%p): %s",strmap[i].findme[term],&event,pfm_strerror(ret));
		term++;
	      }
	  } while (strmap[i].findme[term] != NULL && term < MAX_COUNTER_TERMS);

	  /* terminate the native term array with PAPI_NULL */
	  if (term < MAX_COUNTER_TERMS) psmap[j].data.native[term] = PAPI_NULL;

	if (ret == PAPI_OK)
	{
	    psmap[j].event_code = strmap[i].preset;
	    psmap[j].data.derived = strmap[i].derived;
	    if (strmap[i].derived == DERIVED_POSTFIX) {
	      strncpy(psmap[j].data.operation, strmap[i].operation, PAPI_MIN_STR_LEN);
	    }
	    if (strmap[i].note) {
	      notemap[k].event_code = strmap[i].preset;
	      notemap[k].dev_note = strdup(strmap[i].note);
	      k++;
	    }
	    j++;
	}
      }
      i++;
    }
   if (i != j) 
     {
       PAPIERROR("%d of %d events in %s were not valid",i-j,i,PERFMON_EVENT_FILE);
     }
   SUBDBG("generate_preset_search_map(%p,%p,%p) %d actual presets\n",maploc,noteloc,strmap,j);
   *maploc = psmap;
   *noteloc = notemap;
   return (PAPI_OK);
}

/* Break a PAPI native event code into its composite event code and pfm mask bits */
inline int _pfm_decode_native_event(unsigned int EventCode, unsigned int *event, unsigned int *umask)
{
  unsigned int tevent, major, minor;

  tevent = EventCode & PAPI_NATIVE_AND_MASK;
  major = (tevent & PAPI_NATIVE_EVENT_AND_MASK) >> PAPI_NATIVE_EVENT_SHIFT;
  if (major >= MY_VECTOR.cmp_info.num_native_events)
    return(PAPI_ENOEVNT);

  minor = (tevent & PAPI_NATIVE_UMASK_AND_MASK) >> PAPI_NATIVE_UMASK_SHIFT;
  *event = major;
  *umask = minor;
  SUBDBG("EventCode 0x%08x is event %d, umask 0x%x\n",EventCode,major,minor);
  return(PAPI_OK);
}

/* convert a collection of pfm mask bits into an array of pfm mask indices */
static inline int prepare_umask(unsigned int foo,unsigned int *values)
{
  unsigned int tmp = foo, i, j = 0;

  SUBDBG("umask 0x%x\n",tmp);
  while ((i = ffs(tmp)))
    {
      tmp = tmp ^ (1 << (i-1));
      values[j] = i - 1;
      SUBDBG("umask %d is %d\n",j,values[j]);
      j++;
    }
  return(j);
}

/* convert the mask values in a pfm event structure into a PAPI unit mask */
static inline unsigned int convert_pfm_masks(pfmlib_event_t *gete)
{
  int i, ret;
  unsigned int tmp = 0;
  unsigned int code;

  for (i=0;i<gete->num_masks;i++) {
    if ((ret = pfm_get_event_mask_code(gete->event, gete->unit_masks[i], &code)) == PFMLIB_SUCCESS) {
      SUBDBG("Mask value is 0x%08x\n",code);
      tmp |= code;
    } else {
      PAPIERROR("pfm_get_event_mask_code(0x%x,%d,%p): %s",gete->event,i,&code,pfm_strerror(ret));
    }
  }
  return(tmp);
}
/* convert an event code and pfm unit mask into a PAPI unit mask */
inline unsigned int _pfm_convert_umask(unsigned int event, unsigned int umask)
{
  pfmlib_event_t gete;

  memset(&gete,0,sizeof(gete));
  
  gete.event = event;
  gete.num_masks = prepare_umask(umask,gete.unit_masks);
  return(convert_pfm_masks(&gete));
}

int _papi_pfm_setup_presets(char *pmu_name, int pmu_type)
{
  int retval;
  hwi_search_t *preset_search_map;
  hwi_dev_notes_t *notemap = NULL;
  pfm_preset_search_entry_t *_perfmon2_pfm_preset_search_map;

  /* allocate and clear array of search string structures */
  _perfmon2_pfm_preset_search_map = malloc(sizeof(pfm_preset_search_entry_t)*PAPI_MAX_PRESET_EVENTS);
  if (_perfmon2_pfm_preset_search_map == NULL)
    return(PAPI_ENOMEM);
  memset(_perfmon2_pfm_preset_search_map,0x0,sizeof(pfm_preset_search_entry_t)*PAPI_MAX_PRESET_EVENTS);

   retval = load_preset_table(pmu_name, pmu_type, _perfmon2_pfm_preset_search_map);
   if (retval)
     return(retval);

   retval = generate_preset_search_map(&preset_search_map,&notemap,_perfmon2_pfm_preset_search_map);
    free_preset_table(_perfmon2_pfm_preset_search_map);
    free(_perfmon2_pfm_preset_search_map);
    if (retval)
      return (retval);

   retval = _papi_hwi_setup_all_presets(preset_search_map, notemap);
   if (retval)
     {
       free(preset_search_map);
       free_notes(notemap);
       free(notemap);
       return (retval);
     }
   return (PAPI_OK);
}

int _papi_pfm_init()
{
  int retval;
  unsigned int ncnt;

   /* Opened once for all threads. */
   SUBDBG("pfm_initialize()\n");
   if ((retval = pfm_initialize()) != PFMLIB_SUCCESS)
     {
       PAPIERROR("pfm_initialize(): %s", pfm_strerror(retval));
       return (PAPI_ESBSTR);
     }

   /* Fill in MY_VECTOR.cmp_info.num_native_events */

   SUBDBG("pfm_get_num_events(%p)\n",&ncnt);
   if ((retval = pfm_get_num_events(&ncnt)) != PFMLIB_SUCCESS)
   {
      PAPIERROR("pfm_get_num_events(%p): %s", &ncnt, pfm_strerror(retval));
      return(PAPI_ESBSTR);
   }
   SUBDBG("pfm_get_num_events() returns: %d\n",ncnt);
  MY_VECTOR.cmp_info.num_native_events = ncnt;
  return (PAPI_OK);
}

int _papi_pfm_ntv_name_to_code(char *name, unsigned int *EventCode)
{
    pfmlib_event_t event;

    SUBDBG("pfm_find_full_event(%s,%p)\n",name,&event);
    if (pfm_find_full_event(name,&event) == PFMLIB_SUCCESS) {
	*EventCode = encode_native_event(event.event, event.num_masks, event.unit_masks);
	return(PAPI_OK);
    }
    return(PAPI_ENOEVNT);
}

char *_papi_pfm_ntv_code_to_name(unsigned int EventCode)
{
  int ret;
  unsigned int event, umask;
  pfmlib_event_t gete;
  char name[PAPI_2MAX_STR_LEN]; /* hope the caller handles long strings! */

  memset(&gete,0,sizeof(gete));
  
  if (_pfm_decode_native_event(EventCode,&event,&umask) != PAPI_OK)
    return("");
  
  gete.event = event;
  gete.num_masks = prepare_umask(umask,gete.unit_masks);
  if (gete.num_masks == 0)
    ret = pfm_get_event_name(gete.event,name,sizeof(name));
  else
    ret = pfm_get_full_event_name(&gete,name,sizeof(name));
  if (ret != PFMLIB_SUCCESS)
    {
      char tmp[PAPI_2MAX_STR_LEN];
      pfm_get_event_name(gete.event,tmp,sizeof(tmp));
      PAPIERROR("pfm_get_full_event_name(%p(event %d,%s,%d masks),%p,%d): %d -- %s",
		&gete,gete.event,tmp,gete.num_masks,name,sizeof(name),ret,pfm_strerror(ret));
      return("");
    }

  return(strdup(name));
}

char *_papi_pfm_ntv_code_to_descr(unsigned int EventCode)
{
  unsigned int event, umask;
  char *eventd, **maskd, *tmp;
  int i, ret, total_len = 0;
  pfmlib_event_t gete;

  memset(&gete,0,sizeof(gete));
  
  if (_pfm_decode_native_event(EventCode,&event,&umask) != PAPI_OK)
    return(NULL);
  
  ret = pfm_get_event_description(event,&eventd);
  if (ret != PFMLIB_SUCCESS)
    {
      PAPIERROR("pfm_get_event_description(%d,%p): %s",
		event,&eventd,pfm_strerror(ret));
      return(NULL);
    }

  if ((gete.num_masks = prepare_umask(umask,gete.unit_masks)))
    {
      maskd = (char **)malloc(gete.num_masks*sizeof(char *));
      if (maskd == NULL)
	{
	  free(eventd);
	  return(NULL);
	}
      for (i=0;i<gete.num_masks;i++)
	{
	  ret = pfm_get_event_mask_description(event,gete.unit_masks[i],&maskd[i]);
	  if (ret != PFMLIB_SUCCESS)
	    {
	      PAPIERROR("pfm_get_event_mask_description(%d,%d,%p): %s",
			event,umask,&maskd,pfm_strerror(ret));
	      free(eventd);
	      for (;i>=0;i--)
		free(maskd[i]);
	      free(maskd);
	      return(NULL);
	    }
	  total_len += strlen(maskd[i]);
	}
      tmp = (char *)malloc(strlen(eventd)+strlen(", masks:")+total_len+gete.num_masks+1);
      if (tmp == NULL)
	{
	  for (i=gete.num_masks-1;i>=0;i--)
	    free(maskd[i]);
	  free(maskd);
	  free(eventd);
	}
      tmp[0] = '\0';
      strcat(tmp,eventd);
      strcat(tmp,", masks:");
      for (i=0;i<gete.num_masks;i++)
	{
	  if (i!=0)
	    strcat(tmp,",");
	  strcat(tmp,maskd[i]);
	  free(maskd[i]);
	}
      free(maskd);
    }
  else
    {
      tmp = (char *)malloc(strlen(eventd)+1); 
      if (tmp == NULL)
	{
	  free(eventd);
	  return(NULL);
	}
      tmp[0] = '\0';
      strcat(tmp,eventd);
      free(eventd);
    }

  return(tmp);
}

int _papi_pfm_ntv_enum_events(unsigned int *EventCode, int modifier)
{
  unsigned int event, umask, num_masks;
  int ret;

  if (_pfm_decode_native_event(*EventCode,&event,&umask) != PAPI_OK)
    return(PAPI_ENOEVNT);

  ret = pfm_get_num_event_masks(event,&num_masks);
  if (ret != PFMLIB_SUCCESS)
    {
      PAPIERROR("pfm_get_num_event_masks(%d,%p): %s",event,&num_masks,pfm_strerror(ret));
      return(PAPI_ENOEVNT);
    }
  SUBDBG("This is umask %d of %d\n",umask,num_masks);

  if (modifier == PAPI_ENUM_EVENTS)
    {
      if (event < MY_VECTOR.cmp_info.num_native_events - 1) 
	{
	  *EventCode += 1;
	  return (PAPI_OK);
	}
      return (PAPI_ENOEVNT);
    }
  else if (modifier == PAPI_ENUM_ALL)
    {
      if (umask+1 < (1<<num_masks))
	{
	  *EventCode = encode_native_event_raw(event,umask+1);
	  return (PAPI_OK);
	}
      else if (event < MY_VECTOR.cmp_info.num_native_events - 1) 
	{
	  /* Lookup event + 1 and return first umask of group */
	  ret = pfm_get_num_event_masks(event+1,&num_masks);
	  if (ret != PFMLIB_SUCCESS)
	    {
	      PAPIERROR("pfm_get_num_event_masks(%d,%p): %s",event,&num_masks,pfm_strerror(ret));
	      return(PAPI_ENOEVNT);
	    }
	  if (num_masks)
	    *EventCode = encode_native_event_raw(event+1,1);
	  else
	    *EventCode = encode_native_event_raw(event+1,0);
	  return(PAPI_OK);
	}
      return (PAPI_ENOEVNT);
    }
  else if (modifier == PAPI_ENUM_UMASK_COMBOS)
    {
      if (umask+1 < (1<<num_masks))
	{
	  *EventCode = encode_native_event_raw(event,umask+1);
	  return (PAPI_OK);
	}
      return(PAPI_ENOEVNT);
    }
  else if (modifier == PAPI_ENUM_UMASKS)
    {
      int thisbit = ffs(umask);
      
      SUBDBG("First bit is %d in %08x\b",thisbit-1,umask);
      thisbit = 1 << thisbit;

      if (thisbit & ((1<<num_masks)-1))
	{
	  *EventCode = encode_native_event_raw(event,thisbit);
	  return (PAPI_OK);
	}
      return(PAPI_ENOEVNT);
    }
  else
    return(PAPI_EINVAL);
  
}

#ifndef PENTIUM4

int _pfm_get_counter_info(unsigned int event, unsigned int *selector, int *code)
{
    pfmlib_regmask_t cnt, impl;
    unsigned int num;
    int i, first = 1;
    int ret;

    if ((ret = pfm_get_event_counters(event,&cnt)) != PFMLIB_SUCCESS) {
      PAPIERROR("pfm_get_event_counters(%d,%p): %s", event,&cnt,pfm_strerror(ret));
      return(PAPI_ESBSTR);
    }
    if ((ret = pfm_get_num_counters(&num)) != PFMLIB_SUCCESS) {
      PAPIERROR("pfm_get_num_counters(%p): %s", num,pfm_strerror(ret));
      return(PAPI_ESBSTR);
    }
    if ((ret = pfm_get_impl_counters(&impl)) != PFMLIB_SUCCESS) {
      PAPIERROR("pfm_get_impl_counters(%p): %s", &impl, pfm_strerror(ret));
      return(PAPI_ESBSTR);
    }

    *selector = 0;
    for (i=0; num; i++) {
	if (pfm_regmask_isset(&impl, i))
		num--;
	if (pfm_regmask_isset(&cnt, i)) {
	    if (first) {
	      if ((ret = pfm_get_event_code_counter(event,i,code)) != PFMLIB_SUCCESS)
	      {
		PAPIERROR("pfm_get_event_code_counter(%d, %d, %p): %s", event, i, code, pfm_strerror(ret));
		return(PAPI_ESBSTR);
	      }
	      first = 0;
	    }
	    *selector |= 1 << i;
	}
    }
    return(PAPI_OK);
}
#endif


#ifndef PERFCTR_PFM_EVENTS

int _papi_pfm_ntv_code_to_bits(unsigned int EventCode, hwd_register_t *bits)
{
  unsigned int event, umask;
  pfmlib_event_t gete;

  /* For PFM & Perfmon, native info is just an index into the PFM event table. */
  if (_pfm_decode_native_event(EventCode,&event,&umask) != PAPI_OK)
    return(PAPI_ENOEVNT);

  memset(&gete,0x0,sizeof(gete));

  gete.event = event;
  gete.num_masks = prepare_umask(umask,gete.unit_masks);
  
  memcpy(bits,&gete,sizeof(*bits));
  return (PAPI_OK);
}

static void copy_value(unsigned int val, char *nam, char *names, unsigned int *values, int len)
{
   *values = val;
   strncpy(names, nam, len);
   names[len-1] = 0;
}

int _papi_pfm_ntv_bits_to_info(hwd_register_t *bits, char *names,
                               unsigned int *values, int name_len, int count)
{
    unsigned int selector;
   int mask, i = 0;
    int ret, code;

    if ((ret = _pfm_get_counter_info(bits->event, &selector, &code)) != PAPI_OK)
      return(ret);

   copy_value(bits->event, "PFM Event Index", &names[i*name_len], &values[i], name_len);
   if (++i == count) return(i);
   copy_value(code, "Event Code", &names[i*name_len], &values[i], name_len);
   if (++i == count) return(i);
   copy_value(selector, "Counters", &names[i*name_len], &values[i], name_len);
   if (++i == count) return(i);
   mask = convert_pfm_masks(bits);
   copy_value(mask, "Event Unit Mask", &names[i*name_len], &values[i], name_len);
   return(++i);
}

#endif /* PERFCTR_PFM_EVENTS */

/*
papi_svector_t _papi_pfm_event_vectors[] = {
  {(void (*)())_papi_pfm_ntv_enum_events, VEC_PAPI_HWD_NTV_ENUM_EVENTS},
  {(void (*)())_papi_pfm_ntv_code_to_name, VEC_PAPI_HWD_NTV_CODE_TO_NAME},
  {(void (*)())_papi_pfm_ntv_code_to_descr, VEC_PAPI_HWD_NTV_CODE_TO_DESCR},
  {(void (*)())_papi_pfm_ntv_code_to_bits, VEC_PAPI_HWD_NTV_CODE_TO_BITS},
  {(void (*)())_papi_pfm_ntv_bits_to_info, VEC_PAPI_HWD_NTV_BITS_TO_INFO},
 {NULL, VEC_PAPI_END}
};
*/

