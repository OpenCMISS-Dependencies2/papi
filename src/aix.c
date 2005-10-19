/* This substrate should never malloc anything. All allocation should be
   done by the high level API. */

/* This file handles the OS dependent part of the POWERPC architectures.
  It supports both AIX 4 and AIX 5. The switch between AIX 4 and 5 is driven by the 
  system defined value _AIX_VERSION_510.
  Other routines also include minor conditionally compiled differences.
*/

#include "papi.h"
#include "papi_internal.h"

/* Machine dependent info structure */
extern papi_mdi_t _papi_hwi_system_info;

/* Locking variables */
volatile int lock_var[PAPI_MAX_LOCK] = { 0 };
atomic_p lock[PAPI_MAX_LOCK];

/* 
 some heap information, start_of_text, start_of_data .....
 ref: http://publibn.boulder.ibm.com/doc_link/en_US/a_doc_lib/aixprggd/genprogc/sys_mem_alloc.htm#HDRA9E4A4C9921SYLV 
*/
#define START_OF_TEXT &_text
#define END_OF_TEXT   &_etext
#define START_OF_DATA &_data
#define END_OF_DATA   &_edata
#define START_OF_BSS  &_edata
#define END_OF_BSS    &_end

static int maxgroups = 0;
struct utsname AixVer;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
        /* The following is for any POWER hardware */

/* Routines to support an opaque native event table */
char *_papi_hwd_ntv_code_to_name(unsigned int EventCode)
{
   return (native_name_map[EventCode & PAPI_NATIVE_AND_MASK].name);
}

char *_papi_hwd_ntv_code_to_descr(unsigned int EventCode)
{
   return (native_table[native_name_map[EventCode & PAPI_NATIVE_AND_MASK].index].description);
}

int _papi_hwd_ntv_code_to_bits(unsigned int EventCode, hwd_register_t * bits)
{
   bits = &native_table[EventCode & PAPI_NATIVE_AND_MASK].resources; /* it is not right, different type */
   return (PAPI_OK);
}

/* this function would return the next native event code.
    modifer = PAPI_ENUM_ALL
		 it simply returns next native event code
    modifer = PAPI_PWR4_ENUM_GROUPS
		 it would return information of groups this native event lives
                 0x400000ed is the native code of PM_FXLS_FULL_CYC,
		 before it returns 0x400000ee which is the next native event's
		 code, it would return *EventCode=0x400400ed, the digits 16-23
		 indicate group number
   function return value:
     PAPI_OK successful, next event is valid
     PAPI_ENOEVNT  fail, next event is invalid
*/
int _papi_hwd_ntv_enum_events(unsigned int *EventCode, int modifer)
{
   if (modifer == PAPI_ENUM_ALL) {
      int index = *EventCode & PAPI_NATIVE_AND_MASK;

      if (native_table[index + 1].resources.selector) {
         *EventCode = *EventCode + 1;
         return (PAPI_OK);
      } else
         return (PAPI_ENOEVNT);
   } else if (modifer == PAPI_PWR4_ENUM_GROUPS) {
#if defined(_POWER4) || defined (_POWER5)
      unsigned int group = (*EventCode & 0x00FF0000) >> 16;
      int index = *EventCode & 0x000000FF;
      int i;
      unsigned int tmpg;

      *EventCode = *EventCode & 0xFF00FFFF;
      for (i = 0; i < GROUP_INTS; i++) {
         tmpg = native_table[index].resources.group[i];
         if (group != 0) {
            while ((ffs(tmpg) + i * 32) <= group && tmpg != 0)
               tmpg = tmpg ^ (1 << (ffs(tmpg) - 1));
         }
         if (tmpg != 0) {
            group = ffs(tmpg) + i * 32;
            *EventCode = *EventCode | (group << 16);
            return (PAPI_OK);
         }
      }
      if (native_table[index + 1].resources.selector == 0)
         return (PAPI_ENOEVNT);
      *EventCode = *EventCode + 1;
      return (PAPI_OK);
#else
      return (PAPI_EINVAL);
#endif
   }
   else
      return (PAPI_EINVAL);
}

static void set_config(hwd_control_state_t * ptr, int arg1, int arg2)
{
   ptr->counter_cmd.events[arg1] = arg2;
}

static void unset_config(hwd_control_state_t * ptr, int arg1)
{
   ptr->counter_cmd.events[arg1] = 0;
}

int set_domain(hwd_control_state_t * this_state, int domain)
{
   pm_mode_t *mode = &(this_state->counter_cmd.mode);
   int did = 0;

   mode->b.user = 0;
   mode->b.kernel = 0;
   if (domain & PAPI_DOM_USER) {
      did = 1;
      mode->b.user = 1;
   }
   if (domain & PAPI_DOM_KERNEL) {
      did = 1;
      mode->b.kernel = 1;
   }
   if (did)
      return (PAPI_OK);
   else
      return (PAPI_EINVAL);
/*
  switch (domain)
    {
    case PAPI_DOM_USER:
      mode->b.user = 1;
      mode->b.kernel = 0;
      break;
    case PAPI_DOM_KERNEL:
      mode->b.user = 0;
      mode->b.kernel = 1;
      break;
    case PAPI_DOM_ALL:
      mode->b.user = 1;
      mode->b.kernel = 1;
      break;
    default:
      return(PAPI_EINVAL);
    }
  return(PAPI_OK);
*/
}

int set_granularity(hwd_control_state_t * this_state, int domain)
{
   pm_mode_t *mode = &(this_state->counter_cmd.mode);

   switch (domain) {
   case PAPI_GRN_THR:
      mode->b.process = 0;
      mode->b.proctree = 0;
      break;
      /* case PAPI_GRN_PROC:
         mode->b.process = 1;
         mode->b.proctree = 0;
         break;
         case PAPI_GRN_PROCG:
         mode->b.process = 0;
         mode->b.proctree = 1;
         break; */
   default:
      return (PAPI_EINVAL);
   }
   return (PAPI_OK);
}

static int set_default_domain(EventSetInfo_t * zero, int domain)
{
   hwd_control_state_t *current_state = &zero->machdep;
   return (set_domain(current_state, domain));
}

static int set_default_granularity(EventSetInfo_t * zero, int granularity)
{
   hwd_control_state_t *current_state = &zero->machdep;
   return (set_granularity(current_state, granularity));
}

static int set_inherit(int arg)
{
   return (PAPI_ESBSTR);
}

/* Initialize the system-specific settings */
/* Machine info structure. -1 is unused. */
int _papi_hwd_mdi_init()
{
   int retval;

   if ( (retval = uname( &AixVer)) < 0 )
      return(PAPI_ESYS); 
   if (AixVer.version[0] == '4' ) 
   {
      _papi_hwi_system_info.exe_info.address_info.text_start = (caddr_t) START_OF_TEXT;
      _papi_hwi_system_info.exe_info.address_info.text_end = (caddr_t) END_OF_TEXT;
      _papi_hwi_system_info.exe_info.address_info.data_start = (caddr_t) START_OF_DATA;
      _papi_hwi_system_info.exe_info.address_info.data_end = (caddr_t) END_OF_DATA;
      _papi_hwi_system_info.exe_info.address_info.bss_start = (caddr_t) START_OF_BSS;
      _papi_hwi_system_info.exe_info.address_info.bss_end = (caddr_t) END_OF_BSS;
   } else {
      _papi_hwd_update_shlib_info();
   }

   _papi_hwi_system_info.supports_64bit_counters = 1;
   _papi_hwi_system_info.supports_real_usec = 1;
   _papi_hwi_system_info.supports_real_cyc = 1;


   return (PAPI_OK);
}


static int get_system_info(void)
{
   int retval;
   /* pm_info_t pminfo; */
   struct procsinfo psi = { 0 };
   pid_t pid;
   char maxargs[PAPI_HUGE_STR_LEN];
   char pname[PAPI_HUGE_STR_LEN];
   
#if !defined(_POWER4) && !defined(_POWER5) 
#ifdef _AIXVERSION_510
   pm_groups_info_t pmgroups;
#endif
#endif

   pid = getpid();
   if (pid == -1)
      return (PAPI_ESYS);
   _papi_hwi_system_info.pid = pid;
   psi.pi_pid = pid;
   retval = getargs(&psi, sizeof(psi), maxargs, PAPI_HUGE_STR_LEN);
   if (retval == -1)
      return (PAPI_ESYS);

   if (realpath(maxargs,pname))
     strncpy(_papi_hwi_system_info.exe_info.fullname, pname, PAPI_HUGE_STR_LEN);
   else
     strncpy(_papi_hwi_system_info.exe_info.fullname, maxargs, PAPI_HUGE_STR_LEN);

   strcpy(_papi_hwi_system_info.exe_info.address_info.name,basename(maxargs));

#ifdef _AIXVERSION_510
#if defined(PM_INITIALIZE) && !defined(_POWER4)
   SUBDBG("Calling AIX 5 version of pm_initialize...\n");
   retval = pm_initialize(PM_INIT_FLAGS, &pminfo, &pmgroups, PM_CURRENT);
#else
   SUBDBG("Calling AIX 5 version of pm_init...\n");
   retval = pm_init(PM_INIT_FLAGS, &pminfo, &pmgroups);
#endif

#else
   SUBDBG("Calling AIX 4 version of pm_init...\n");
   retval = pm_init(PM_INIT_FLAGS, &pminfo);
#endif
   SUBDBG("...Back from pm_init\n");

   if (retval > 0)
      return (retval);

   strcpy(_papi_hwi_system_info.substrate, "$Id$");  /* Name of the substrate we're using */

   _papi_hwd_mdi_init();

   _papi_hwi_system_info.hw_info.ncpu = _system_configuration.ncpus;
   _papi_hwi_system_info.hw_info.totalcpus =
       _papi_hwi_system_info.hw_info.ncpu * _papi_hwi_system_info.hw_info.nnodes;
   _papi_hwi_system_info.hw_info.vendor = -1;
   strcpy(_papi_hwi_system_info.hw_info.vendor_string, "IBM");
   _papi_hwi_system_info.hw_info.model = _system_configuration.implementation;
   strcpy(_papi_hwi_system_info.hw_info.model_string, pminfo.proc_name);
   _papi_hwi_system_info.hw_info.revision = (float) _system_configuration.version;
   _papi_hwi_system_info.hw_info.mhz = (float) (pm_cycles() / 1000000.0);
   _papi_hwi_system_info.num_gp_cntrs = pminfo.maxpmcs;
   _papi_hwi_system_info.num_cntrs = pminfo.maxpmcs;
   _papi_hwi_system_info.supports_multiple_threads = 1;  
/* This field doesn't appear to exist in the PAPI 3.0 structure 
  _papi_hwi_system_info.cpunum = mycpu(); 
*/

   return (PAPI_OK);
}

/* Low level functions, should not handle errors, just return codes. */

/* At init time, the higher level library should always allocate and 
   reserve EventSet zero. */

long_long _papi_hwd_get_real_usec(void)
{
   timebasestruct_t t;
   long_long retval;

   read_real_time(&t, TIMEBASE_SZ);
   time_base_to_time(&t, TIMEBASE_SZ);
   retval = (t.tb_high * 1000000) + t.tb_low / 1000;
   return (retval);
}

long_long _papi_hwd_get_real_cycles(void)
{
   return(_papi_hwd_get_real_usec() * (long_long)_papi_hwi_system_info.hw_info.mhz);
}

long_long _papi_hwd_get_virt_usec(const hwd_context_t * context)
{
   long_long retval;
   struct tms buffer;

   times(&buffer);
   SUBDBG("user %d system %d\n",(int)buffer.tms_utime,(int)buffer.tms_stime);
   retval = (long_long)((buffer.tms_utime+buffer.tms_stime)*
     (1000000/CLK_TCK));
   return (retval);
}

long_long _papi_hwd_get_virt_cycles(const hwd_context_t * context)
{
   return (_papi_hwd_get_virt_usec(context) * (long_long)_papi_hwi_system_info.hw_info.mhz);
}

void _papi_hwd_error(int error, char *where)
{
   sprintf(where, "Substrate error");
   pm_error(where, error);
}

static void _papi_lock_init(void)
{
   int i;
   for (i = 0; i < PAPI_MAX_LOCK; i++)
      lock[i] = (int *) (lock_var + i);
}

int _papi_hwd_init_global(void)
{
   int retval=PAPI_OK;

   /* Fill in what we can of the papi_system_info. */

   retval = get_system_info();
   if (retval)
      return (retval);

   retval = get_memory_info(&_papi_hwi_system_info.hw_info);
   if (retval)
      return (retval);

   SUBDBG("Found %d %s %s CPU's at %f Mhz.\n",
        _papi_hwi_system_info.hw_info.totalcpus,
        _papi_hwi_system_info.hw_info.vendor_string,
        _papi_hwi_system_info.hw_info.model_string, _papi_hwi_system_info.hw_info.mhz);

#if !defined(_POWER4) && !defined(_POWER5)
   setup_native_table();
#else
   ppc64_setup_native_table();
#endif
   if (!_papi_hwd_init_preset_search_map(&pminfo)){ 
      return (PAPI_ESBSTR);}

   retval = _papi_hwi_setup_all_presets(preset_search_map, NULL);

   _papi_lock_init();

   return (retval);
}

int _papi_hwd_init(hwd_context_t * context)
{
   int retval;
   /* Initialize our global machdep. */

   _papi_hwd_init_control_state(&context->cntrl);
}

/* Go from highest counter to lowest counter. Why? Because there are usually
   more counters on #1, so we try the least probable first. */

static int get_avail_hwcntr_bits(int cntr_avail_bits)
{
   int tmp = 0, i = 1 << (POWER_MAX_COUNTERS - 1);

   while (i) {
      tmp = i & cntr_avail_bits;
      if (tmp)
         return (tmp);
      i = i >> 1;
   }
   return (0);
}

static void set_hwcntr_codes(int selector, unsigned char *from, int *to)
{
   int useme, i;

   for (i = 0; i < _papi_hwi_system_info.num_cntrs; i++) {
      useme = (1 << i) & selector;
      if (useme) {
         to[i] = from[i];
      }
   }
}


int _papi_hwd_add_prog_event(hwd_control_state_t * this_state,
                             unsigned int event, void *extra, EventInfo_t * out)
{
   return (PAPI_ESBSTR);
}

#ifdef DEBUG
void dump_cmd(pm_prog_t * t)
{
   SUBDBG("mode.b.threshold %d\n", t->mode.b.threshold);
   SUBDBG("mode.b.spare %d\n", t->mode.b.spare);
   SUBDBG("mode.b.process %d\n", t->mode.b.process);
   SUBDBG("mode.b.kernel %d\n", t->mode.b.kernel);
   SUBDBG("mode.b.user %d\n", t->mode.b.user);
   SUBDBG("mode.b.count %d\n", t->mode.b.count);
   SUBDBG("mode.b.proctree %d\n", t->mode.b.proctree);
   SUBDBG("events[0] %d\n", t->events[0]);
   SUBDBG("events[1] %d\n", t->events[1]);
   SUBDBG("events[2] %d\n", t->events[2]);
   SUBDBG("events[3] %d\n", t->events[3]);
   SUBDBG("events[4] %d\n", t->events[4]);
   SUBDBG("events[5] %d\n", t->events[5]);
   SUBDBG("events[6] %d\n", t->events[6]);
   SUBDBG("events[7] %d\n", t->events[7]);
   SUBDBG("reserved %d\n", t->reserved);
}

void dump_data(long long *vals)
{
   int i;

   for (i = 0; i < MAX_COUNTERS; i++) {
      SUBDBG("counter[%d] = %lld\n", i, vals[i]);
   }
}
#endif

/*int _papi_hwd_reset(EventSetInfo_t *ESI, EventSetInfo_t *zero)*/
int _papi_hwd_reset(hwd_context_t * ESI, hwd_control_state_t * zero)
{
  int retval = pm_reset_data_mythread();
  if (retval > 0)
    {
      if (_papi_hwi_error_level != PAPI_QUIET)
	pm_error("PAPI Error: pm_reset_data_mythread",retval);
      return(retval);
    }
   return (PAPI_OK);
}


int _papi_hwd_read(hwd_context_t * ctx, hwd_control_state_t *spc, long_long **vals, int flags)
{
   int retval;

   retval = pm_get_data_mythread(&spc->state);
   if (retval > 0)
      { 
	if (_papi_hwi_error_level != PAPI_QUIET)
	  pm_error("PAPI Error: pm_get_data_mythread",retval); 
	return(retval);
      }

  *vals = spc->state.accu;

#ifdef DEBUG
   if (ISLEVEL(DEBUG_SUBSTRATE))
     dump_data(*vals);
#endif

   return (PAPI_OK);
}

int _papi_hwd_ctl(hwd_context_t * ctx, int code, _papi_int_option_t * option)
{
   switch (code) {
/* I don't understand what it means to set the default domain 
    case PAPI_DEFDOM:
      return(set_default_domain(zero, option->domain.domain));
*/
   case PAPI_DOMAIN:
      return (set_domain(&(option->domain.ESI->machdep), option->domain.domain));
/* I don't understand what it means to set the default granularity 
    case PAPI_DEFGRN:
      return(set_default_granularity(zero, option->granularity.granularity));
*/
   case PAPI_GRANUL:
      return (set_granularity
              (&(option->granularity.ESI->machdep), option->granularity.granularity));
#if 0
   case PAPI_INHERIT:
      return (set_inherit(option->inherit.inherit));
#endif
   default:
      return (PAPI_EINVAL);
   }
}

int _papi_hwd_write(hwd_context_t * ctx, hwd_control_state_t * cntrl, long_long events[])
{
   return (PAPI_ESBSTR);
}

int _papi_hwd_shutdown(hwd_context_t * ctx)
{
  return (PAPI_OK);
}

int _papi_hwd_shutdown_global(void)
{
   return (PAPI_OK);
}


void _papi_hwd_dispatch_timer(int signal, siginfo_t * si, void *i)
{
   _papi_hwi_context_t ctx;
   ThreadInfo_t *t = NULL;

   ctx.si = si;
   ctx.ucontext = (hwd_ucontext_t *) i;
   _papi_hwi_dispatch_overflow_signal(&ctx, NULL, 0, 0, &t);
}

int _papi_hwd_set_overflow(EventSetInfo_t * ESI, int EventIndex, int threshold)
{
   hwd_control_state_t *this_state = &ESI->machdep;

   if (threshold == 0) {
      ESI->overflow.timer_ms = 0;
   } else {
      ESI->overflow.timer_ms = 1;
   }

   return (PAPI_OK);
}

int _papi_hwd_set_profile(EventSetInfo_t * ESI, int EventIndex, int threshold)
{
   /* This function is not used and shouldn't be called. */

   return (PAPI_ESBSTR);
}

int _papi_hwd_stop_profiling(ThreadInfo_t * master, EventSetInfo_t * ESI)
{
   /* This function is not used and shouldn't be called. */

   return (PAPI_ESBSTR);
}

/*void *_papi_hwd_get_overflow_address(void *context)
{
  void *location;
  struct sigcontext *info = (struct sigcontext *)context;
  location = (void *)info->sc_jmpbuf.jmp_context.iar;

  return(location);
}*/


/* Copy the current control_state into the new thread context */
/*int _papi_hwd_start(EventSetInfo_t *ESI, EventSetInfo_t *zero)*/
int _papi_hwd_start(hwd_context_t * ctx, hwd_control_state_t * cntrl)
{
   int i, retval;
   hwd_control_state_t *current_state = &ctx->cntrl;

   /* If we are nested, merge the global counter structure
      with the current eventset */

   SUBDBG("Start\n");

   /* Copy the global counter structure to the current eventset */

   SUBDBG("Copying states\n");
   memcpy(current_state, cntrl, sizeof(hwd_control_state_t));

   retval = pm_set_program_mythread(&current_state->counter_cmd);
   if (retval > 0)
     {
       if (retval == 13)
	 {
	   retval = pm_delete_program_mythread();
	   if (retval > 0)
	     {
	       if (_papi_hwi_error_level != PAPI_QUIET)
		 pm_error("PAPI Error: pm_delete_program_mythread",retval);
	       return(retval);
	     }
	   retval = pm_set_program_mythread(&current_state->counter_cmd);
	   if (retval > 0)
	     {
	       if (_papi_hwi_error_level != PAPI_QUIET)
		 pm_error("PAPI Error: pm_set_program_mythread",retval);
	       return(retval);
	     }
	 }
       else
	 {
	   if (_papi_hwi_error_level != PAPI_QUIET)
	     pm_error("PAPI Error: pm_set_program_mythread",retval);
	   return(retval);
	 }
     }

   /* Set up the new merged control structure */

#if 0
   dump_cmd(&current_state->counter_cmd);
#endif

   /* Start the counters */

   retval = pm_start_mythread();
   if (retval > 0)
     {
       if (_papi_hwi_error_level != PAPI_QUIET)
	 pm_error("pm_start_mythread()",retval);
       return (retval);
     }

   return (PAPI_OK);
}

int _papi_hwd_stop(hwd_context_t * ctx, hwd_control_state_t * cntrl)
{
   int retval;

   retval = pm_stop_mythread();
   if (retval > 0)
      { 
if (_papi_hwi_error_level != PAPI_QUIET)
	  pm_error("pm_stop_mythread()",retval);
	return(retval);
      }

   retval = pm_delete_program_mythread();
   if (retval > 0)
      { 
	if (_papi_hwi_error_level != PAPI_QUIET)
	  pm_error("pm_delete_program_mythread()",retval);
	return(retval);
      }

   return (PAPI_OK);
}

int _papi_hwd_update_shlib_info(void)
{
#if ( ( defined( _AIXVERSION_510) || defined(_AIXVERSION_520)))
      struct ma_msg_s {
          long flag;
          char *name;
      } ma_msgs[] = {
          {MA_MAINEXEC,  "MAINEXEC"},
          {MA_KERNTEXT,  "KERNTEXT"},
          {MA_READ,      "READ"},
          {MA_WRITE,     "WRITE"},
          {MA_EXEC,      "EXEC"},
          {MA_SHARED,    "SHARED"},
          {MA_BREAK,     "BREAK"},
          {MA_STACK,     "STACK"},
      };

      char fname[80], name[PAPI_HUGE_STR_LEN];
      prmap_t newp;
      int count, t_index, retval, i, j, not_first_flag_bit;
      FILE * map_f;
      void * vaddr;
      prmap_t *tmp1 = NULL;
      PAPI_address_map_t *tmp2 = NULL;

      sprintf(fname, "/proc/%d/map", getpid());
      map_f = fopen(fname, "r");
      if (!map_f)
	{
	  PAPIERROR("fopen(%s) returned < 0", fname); 
	  return(PAPI_OK);
	}

      /* count the entries we need */
      count =0;
      t_index=0;
      while ( (retval=fread(&newp, sizeof(prmap_t), 1, map_f)) > 0 ) {
         if (newp.pr_pathoff > 0 && newp.pr_mapname[0]!='\0' ) 
         {
            if ( newp.pr_mflags & MA_STACK ) continue;

            count++;
            SUBDBG("count=%d offset=%ld map=%s\n", count, 
              newp.pr_pathoff, newp.pr_mapname);

            if ((newp.pr_mflags &MA_READ)&&(newp.pr_mflags&MA_EXEC))
               t_index++;
         }
      }
      rewind(map_f);
      tmp1 = (prmap_t *) calloc((count+1), sizeof(prmap_t));
      if (tmp1 == NULL)
         return(PAPI_ENOMEM);

      tmp2 = (PAPI_address_map_t *) calloc(t_index-1, sizeof(PAPI_address_map_t));
      if (tmp2 == NULL)
         return(PAPI_ENOMEM);

      i=0;
      t_index=-1;
      while ( (retval=fread(&tmp1[i], sizeof(prmap_t), 1, map_f)) > 0 ) {
         if (tmp1[i].pr_pathoff > 0 && tmp1[i].pr_mapname[0]!='\0') 
            if (!( tmp1[i].pr_mflags & MA_STACK )) 
               i++;
      }
      for(i=0; i< count; i++ )
      {
         char c;
         int cc=0;
         retval=fseek(map_f, tmp1[i].pr_pathoff, SEEK_SET); 
         if (retval != 0) return(PAPI_ESYS);
         while(fscanf(map_f, "%c", &c) != EOF ) {
             name[cc]=c;
             cc++;
             if(c=='\0') break;
	     }

         if (strcmp(_papi_hwi_system_info.exe_info.address_info.name,
                          basename(name))== 0 )
         {
            if (tmp1[i].pr_mflags & MA_READ) {
               if ( tmp1[i].pr_mflags & MA_EXEC ) {
                  _papi_hwi_system_info.exe_info.address_info.text_start =
                                      (caddr_t) tmp1[i].pr_vaddr;
                  _papi_hwi_system_info.exe_info.address_info.text_end =
                                 (caddr_t) (tmp1[i].pr_vaddr+tmp1[i].pr_size);
               } else if (tmp1[i].pr_mflags &MA_WRITE ) {
                  _papi_hwi_system_info.exe_info.address_info.data_start =
                                   (caddr_t) tmp1[i].pr_vaddr;
                  _papi_hwi_system_info.exe_info.address_info.data_end =
                                (caddr_t) (tmp1[i].pr_vaddr+tmp1[i].pr_size);
               }
            }

         } else {
            if (tmp1[i].pr_mflags & MA_READ ) {
               if ( tmp1[i].pr_mflags & MA_EXEC ) {
                  t_index++;
                  tmp2[t_index].text_start = (caddr_t) tmp1[i].pr_vaddr;
                  tmp2[t_index].text_end =(caddr_t) (tmp1[i].pr_vaddr +
                                                  tmp1[i].pr_size);
                  strncpy(tmp2[t_index].name, name, PAPI_MAX_STR_LEN);
               } else if ( tmp1[i].pr_mflags & MA_WRITE) {
                  tmp2[t_index].data_start = (caddr_t) tmp1[i].pr_vaddr;
                  tmp2[t_index].data_end = (caddr_t) (tmp1[i].pr_vaddr+
                                                tmp1[i].pr_size);
               }
            }

         }
      }
      fclose(map_f);

      if (_papi_hwi_system_info.shlib_info.map)
         free(_papi_hwi_system_info.shlib_info.map);
      _papi_hwi_system_info.shlib_info.map = tmp2;
      _papi_hwi_system_info.shlib_info.count = t_index+1;
      free(tmp1);
      
      return(PAPI_OK);
#else
      return PAPI_ESBSTR;
#endif
}
