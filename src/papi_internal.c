/****************************/
/* THIS IS OPEN SOURCE CODE */
/****************************/

/* 
* File:    papi_internal.c
* CVS:     $Id$
* Author:  Philip Mucci
*          mucci@cs.utk.edu
* Mods:    dan terpstra
*          terpstra@cs.utk.edu
* Mods:    Min Zhou
*          min@cs.utk.edu
* Mods:    Kevin London
*	   london@cs.utk.edu
* Mods:    Per Ekman
*          pek@pdc.kth.se
* Mods:    Haihang You
*          you@cs.utk.edu
* Mods:    Maynard Johnson
*          maynardj@us.ibm.com
* Mods:    <your name here>
*          <your email address>
*/

#include "papi.h"
#include "papi_internal.h"
#include "papi_vector.h"
#include "papi_vector_redefine.h"
#include "papi_memory.h"

/********************/
/* BEGIN PROTOTYPES */
/********************/

static int default_debug_handler(int errorCode);
static long_long handle_derived(EventInfo_t * evi, long_long * from);

extern unsigned long int (*_papi_hwi_thread_id_fn) (void);


/********************/
/*  END PROTOTYPES  */
/********************/

/********************/
/*  BEGIN GLOBALS   */
/********************/

/* Defined in papi_data.c */
extern hwi_presets_t _papi_hwi_presets;

/* Machine dependent info structure */
extern papi_mdi_t _papi_hwi_system_info;

/********************/
/*  BEGIN LOCALS    */
/********************/

int _papi_hwi_error_level = PAPI_QUIET;
PAPI_debug_handler_t _papi_hwi_debug_handler = default_debug_handler;

/********************/
/*    END LOCALS    */
/********************/

/* Utility functions */

void PAPIERROR(char *format, ...)
{
  va_list args;
   if (_papi_hwi_error_level != PAPI_QUIET)
     {
       va_start(args, format); 
       fprintf(stderr, "PAPI Error: ");
       vfprintf(stderr, format, args);
       fprintf(stderr,".\n");
       va_end(args);
     }
}

static int default_debug_handler(int errorCode)
{
   extern hwi_describe_t _papi_hwi_err[];
   char str[PAPI_HUGE_STR_LEN];

   if (errorCode == PAPI_OK)
      return (errorCode);
   if ((errorCode > 0) || (-errorCode > PAPI_NUM_ERRORS))
     {
       PAPIERROR("%s %d,%s,Bug! Unknown error code",PAPI_ERROR_CODE_str,errorCode,"");
       return(PAPI_EBUG);
     }

   switch (_papi_hwi_error_level) {
   case PAPI_VERB_ECONT:
   case PAPI_VERB_ESTOP:
      /* gcc 2.96 bug fix, do not change */
      /* fprintf(stderr,"%s %d: %s: %s\n",PAPI_ERROR_CODE_str,errorCode,_papi_hwi_err[-errorCode].name,_papi_hwi_err[-errorCode].descr); */

      sprintf(str,"%s %d,%s,%s",PAPI_ERROR_CODE_str,errorCode,_papi_hwi_err[-errorCode].name,_papi_hwi_err[-errorCode].descr);
      if (errorCode == PAPI_ESYS) 
         sprintf(str+strlen(str), ": %s", strerror(errno));

      PAPIERROR(str);

      if (_papi_hwi_error_level == PAPI_VERB_ESTOP)
         exit(-errorCode);
      else
         return errorCode;
      break;

   case PAPI_QUIET:
   default:
     return errorCode;
   }
   return(PAPI_EBUG); /* Never get here */
}

static int allocate_eventset_map(DynamicArray_t *map)
{
   /* Allocate and clear the Dynamic Array structure */
   if(map->dataSlotArray!=NULL) papi_free(map->dataSlotArray);
   memset(map, 0x00, sizeof(DynamicArray_t));

   /* Allocate space for the EventSetInfo_t pointers */

   map->dataSlotArray =
       (EventSetInfo_t **) papi_malloc(PAPI_INIT_SLOTS * sizeof(EventSetInfo_t *));
   if (map->dataSlotArray == NULL) {
      return (PAPI_ENOMEM);
   }
   memset(map->dataSlotArray, 0x00, PAPI_INIT_SLOTS * sizeof(EventSetInfo_t *));
   map->totalSlots = PAPI_INIT_SLOTS;
   map->availSlots = PAPI_INIT_SLOTS;
   map->fullSlots = 0;

   return (PAPI_OK);
}

static void free_eventset_map(DynamicArray_t *map)
{
   papi_free(map->dataSlotArray);
   memset(map, 0x00, sizeof(DynamicArray_t));
}

static int expand_dynamic_array(DynamicArray_t * DA)
{
   int number;
   EventSetInfo_t **n;

   /*realloc existing PAPI_EVENTSET_MAP.dataSlotArray */

   number = DA->totalSlots * 2;
   n = (EventSetInfo_t **) papi_realloc(DA->dataSlotArray, number * sizeof(EventSetInfo_t *));
   if (n == NULL)
      return(PAPI_ENOMEM);

   /* Need to assign this value, what if realloc moved it? */

   DA->dataSlotArray = n;

   memset(DA->dataSlotArray + DA->totalSlots, 0x00,
          DA->totalSlots * sizeof(EventSetInfo_t *));

   DA->totalSlots = number;
   DA->availSlots = number - DA->fullSlots;

   return (PAPI_OK);
}

/*========================================================================*/
/* This function allocates space for one EventSetInfo_t structure and for */
/* all of the pointers in this structure.  If any malloc in this function */
/* fails, all memory malloced to the point of failure is freed, and NULL  */
/* is returned.  Upon success, a pointer to the EventSetInfo_t data       */
/* structure is returned.                                                 */
/*========================================================================*/

static int EventInfoArrayLength(const EventSetInfo_t * ESI)
{
   if (ESI->state & PAPI_MULTIPLEXING)
      return (_papi_hwi_system_info.sub_info.num_mpx_cntrs);
   else
      return (_papi_hwi_system_info.sub_info.num_cntrs);
}

static void initialize_EventInfoArray(EventSetInfo_t * ESI)
{
   int i, j, limit = _papi_hwi_system_info.sub_info.num_mpx_cntrs;
   /* Always initialize the whole thing */

   for (i = 0; i < limit; i++) {
      ESI->EventInfoArray[i].event_code = PAPI_NULL;
      for (j = 0; j < MAX_COUNTER_TERMS; j++)
         ESI->EventInfoArray[i].pos[j] = -1;
      ESI->EventInfoArray[i].ops = NULL;
      ESI->EventInfoArray[i].derived = NOT_DERIVED;
   }
}


static void initialize_NativeInfoArray(EventSetInfo_t * ESI)
{
   int i;

   for (i = 0; i < MAX_COUNTERS; i++) {
      ESI->NativeInfoArray[i].ni_event = -1;
      ESI->NativeInfoArray[i].ni_position = -1;
      ESI->NativeInfoArray[i].ni_owners = 0;
   }
   ESI->NativeCount = 0;
}


static int allocate_EventSet(EventSetInfo_t **here)
{
   EventSetInfo_t *ESI;
   int max_counters, ret;

   ESI = (EventSetInfo_t *) papi_malloc(sizeof(EventSetInfo_t));
   if (ESI == NULL)
      return (PAPI_ENOMEM);
   memset(ESI, 0x00, sizeof(EventSetInfo_t));

   ret = _papi_hwd_init_control_state(&ESI->machdep); /* this used to be init_config */
   if (ret != PAPI_OK)
     {
       papi_free(ESI);
       return(ret);
     }

   max_counters = _papi_hwi_system_info.sub_info.num_mpx_cntrs;
/*  ESI->machdep = (hwd_control_state_t *)papi_malloc(sizeof(hwd_control_state_t)); */
   ESI->sw_stop = (long_long *) papi_malloc(max_counters * sizeof(long_long));
   ESI->hw_start = (long_long *) papi_malloc(max_counters * sizeof(long_long));
   ESI->EventInfoArray = (EventInfo_t *) papi_malloc(max_counters * sizeof(EventInfo_t));

   if (
/*    (ESI->machdep        == NULL )  || */
         (ESI->sw_stop == NULL) || (ESI->hw_start == NULL)
         || (ESI->EventInfoArray == NULL)) {
/*      if (ESI->machdep)        papi_free(ESI->machdep); */
      if (ESI->sw_stop)
         papi_free(ESI->sw_stop);
      if (ESI->hw_start)
         papi_free(ESI->hw_start);
      if (ESI->EventInfoArray)
         papi_free(ESI->EventInfoArray);
      papi_free(ESI);
      return (PAPI_ENOMEM);
   }
/*  memset(ESI->machdep,       0x00,_papi_system_info.size_machdep); */
   memset(ESI->sw_stop, 0x00, max_counters * sizeof(long_long));
   memset(ESI->hw_start, 0x00, max_counters * sizeof(long_long));

   initialize_EventInfoArray(ESI);
   initialize_NativeInfoArray(ESI);

   ESI->state = PAPI_STOPPED;

   /* ESI->domain.domain = 0;
      ESI->granularity.granularity = 0; */

   *here = ESI;
   return(PAPI_OK);
}

/*========================================================================*/
/* This function should free memory for one EventSetInfo_t structure.     */
/* The argument list consists of a pointer to the EventSetInfo_t          */
/* structure, *ESI.                                                       */
/* The calling function should check  for ESI==NULL.                      */
/*========================================================================*/

static void free_EventSet(EventSetInfo_t * ESI)
{
   if (ESI->EventInfoArray)
      papi_free(ESI->EventInfoArray);
/*  if (ESI->machdep)        papi_free(ESI->machdep); */
   if (ESI->sw_stop)
      papi_free(ESI->sw_stop);
   if (ESI->hw_start)
      papi_free(ESI->hw_start);
   if ((ESI->state & PAPI_MULTIPLEXING) && ESI->multiplex.mpx_evset)
     papi_free(ESI->multiplex.mpx_evset);

#ifdef DEBUG
   memset(ESI, 0x00, sizeof(EventSetInfo_t));
#endif
   papi_free(ESI);
}

static int add_EventSet(EventSetInfo_t * ESI, ThreadInfo_t * master)
{
   DynamicArray_t *map = &_papi_hwi_system_info.global_eventset_map;
   int i, errorCode;

   _papi_hwi_lock(INTERNAL_LOCK);

   if (map->availSlots == 0) {
      errorCode = expand_dynamic_array(map);
      if (errorCode < PAPI_OK) {
         _papi_hwi_unlock(INTERNAL_LOCK);
         return (errorCode);
      }
   }

   i = 0;
   for (i=0;i<map->totalSlots;i++)
     {
       if (map->dataSlotArray[i] == NULL)
	 {
	   ESI->master = master;
	   ESI->EventSetIndex = i;
	   map->fullSlots++;
	   map->availSlots--;
	   map->dataSlotArray[i] = ESI;
	   _papi_hwi_unlock(INTERNAL_LOCK);
	   return(PAPI_OK);
	 }
     }

   _papi_hwi_unlock(INTERNAL_LOCK);
   return(PAPI_EBUG);
}

int _papi_hwi_create_eventset(int *EventSet, ThreadInfo_t * handle)
{
   EventSetInfo_t *ESI;
   int retval;

   /* Is the EventSet already in existence? */

   if ((EventSet == NULL) || (handle == NULL))
      return (PAPI_EINVAL);

   if ( *EventSet != PAPI_NULL )
      return (PAPI_EINVAL);
   /* Well, then allocate a new one. Use n to keep track of a NEW EventSet */

   retval = allocate_EventSet(&ESI);
   if (retval != PAPI_OK)
      return (retval);

   /* Add it to the global table */

   retval = add_EventSet(ESI, handle);
   if (retval < PAPI_OK) {
      free_EventSet(ESI);
      return (retval);
   }

   *EventSet = ESI->EventSetIndex;
   INTDBG("(%p,%p): new EventSet in slot %d\n",
          (void *) EventSet, handle, *EventSet);

   return (retval);
}

/* This function returns the index of the the next free slot
   in the EventInfoArray. If EventCode is already in the list,
   it returns PAPI_ECNFLCT. */

static int get_free_EventCodeIndex(const EventSetInfo_t * ESI, unsigned int EventCode)
{
   int k;
   int lowslot = PAPI_ECNFLCT;
   int limit = EventInfoArrayLength(ESI);

   /* Check for duplicate events and get the lowest empty slot */

   for (k = 0; k < limit; k++) {
      if (ESI->EventInfoArray[k].event_code == EventCode)
         return(PAPI_ECNFLCT);
      /*if ((ESI->EventInfoArray[k].event_code == PAPI_NULL) && (lowslot == PAPI_ECNFLCT)) */
      if (ESI->EventInfoArray[k].event_code == PAPI_NULL) {
         lowslot = k;
         break;
      }
   }
   return (lowslot);
}

/* This function returns the index of the EventCode or error */
/* Index to what? The index to everything stored EventCode in the */
/* EventSet. */

int _papi_hwi_lookup_EventCodeIndex(const EventSetInfo_t * ESI, unsigned int EventCode)
{
   int i;
   int limit = EventInfoArrayLength(ESI);

   for (i = 0; i < limit; i++) {
      if (ESI->EventInfoArray[i].event_code == EventCode)
         return (i);
   }

   return (PAPI_EINVAL);
}

/* This function only removes empty EventSets */

int _papi_hwi_remove_EventSet(EventSetInfo_t * ESI)
{
   DynamicArray_t *map = &_papi_hwi_system_info.global_eventset_map;
   int i;

   i = ESI->EventSetIndex;

   free_EventSet(ESI);

   /* do bookkeeping for PAPI_EVENTSET_MAP */

   _papi_hwi_lock(INTERNAL_LOCK);

   map->dataSlotArray[i] = NULL;
   map->availSlots++;
   map->fullSlots--;

   _papi_hwi_unlock(INTERNAL_LOCK);

   return (PAPI_OK);
}


/* this function try to find out whether native event has already been mapped. 
     Success, return hwd_native_t array index
     Fail,    return -1;                                                             
*/
int _papi_hwi_add_native_precheck(EventSetInfo_t * ESI, int nevt)
{
   int i;

   /* to find the native event from the native events list */
   for (i = 0; i < ESI->NativeCount; i++) {
      if (nevt == ESI->NativeInfoArray[i].ni_event) {
         ESI->NativeInfoArray[i].ni_owners++;
         INTDBG("found native event already mapped: %s\n",
                _papi_hwd_ntv_code_to_name(nevt));
         return i;
      }
   }
   return -1;
}


/* this function is called after mapping is done
   refill info for every added events
 */
static void remap_event_position(EventSetInfo_t * ESI, int thisindex)
{
   EventInfo_t *out, *head;
   int i, j, k, n, preset_index, nevt, total_events;

   head = ESI->EventInfoArray;
   out = &head[thisindex];
   total_events = ESI->NumberOfEvents;

   j = 0;
   for (i = 0; i <= total_events; i++) {

      /* find the added event in EventInfoArray */
      while (head[j].event_code == PAPI_NULL)
         j++;
      /* fill in the new information */
      if (head[j].event_code & PAPI_PRESET_MASK) {
         preset_index = head[j].event_code & PAPI_PRESET_AND_MASK;
         for (k = 0; k < MAX_COUNTER_TERMS; k++) {
            nevt = _papi_hwi_presets.data[preset_index]->native[k];
            if (nevt == PAPI_NULL)
               break;
            for (n = 0; n < ESI->NativeCount; n++) {
               if (nevt == ESI->NativeInfoArray[n].ni_event) {
                  head[j].pos[k] = ESI->NativeInfoArray[n].ni_position;
                  break;
               }
            }
         }
         /*head[j].pos[k]=-1; */
      } else {

         nevt = head[j].event_code;
         for (n = 0; n < ESI->NativeCount; n++) {
            if (nevt == ESI->NativeInfoArray[n].ni_event) {
               head[j].pos[0] = ESI->NativeInfoArray[n].ni_position;
               /*head[j].pos[1]=-1; */
               break;
            }
         }
      }                         /* end of if */
      j++;
   }                            /* end of for loop */
}


static int add_native_fail_clean(EventSetInfo_t * ESI, int nevt)
{
   int i;

   /* to find the native event from the native events list */
   for (i = 0; i < MAX_COUNTERS; i++) {
      if (nevt == ESI->NativeInfoArray[i].ni_event) {
         ESI->NativeInfoArray[i].ni_owners--;
         /* to clean the entry in the nativeInfo array */
         if (ESI->NativeInfoArray[i].ni_owners == 0) {
            ESI->NativeInfoArray[i].ni_event = 0;
            ESI->NativeInfoArray[i].ni_position = -1;
            ESI->NativeCount--;
         }
         INTDBG("add_events fail, and remove added native events of the event: %s\n",
                _papi_hwd_ntv_code_to_name(nevt));
         return i;
      }
   }
   return -1;
}

/* this function is called by _papi_hwi_add_event when adding native events 
nix: pointer to array of native event table indexes from the preset entry
size: number of native events to add
*/
static int add_native_events(EventSetInfo_t * ESI, int *nevt, int size, EventInfo_t * out)
{
   int nidx, i, j, remap = 0;
   int retval;

   /* if the native event is already mapped, fill in */
   for (i = 0; i < size; i++) {
      if ((nidx = _papi_hwi_add_native_precheck(ESI, nevt[i])) >= 0) {
         out->pos[i] = ESI->NativeInfoArray[nidx].ni_position;
      } else {
         /* all counters have been used, add_native fail */
         if (ESI->NativeCount == MAX_COUNTERS) {
            /* to clean owners for previous added native events */
            for (j = 0; j < i; j++) {
               if ((nidx = add_native_fail_clean(ESI, nevt[j])) >= 0) {
                  out->pos[j] = -1;
                  continue;
               }
               INTDBG("should not happen!\n");
            }
            INTDBG("counters are full!\n");
            return -1;
         }
         /* there is an empty slot for the native event;
            initialize the native index for the new added event */
         INTDBG("Adding %s\n", _papi_hwd_ntv_code_to_name(nevt[i]));
         ESI->NativeInfoArray[ESI->NativeCount].ni_event = nevt[i];
         ESI->NativeInfoArray[ESI->NativeCount].ni_owners = 1;
         ESI->NativeCount++;
         remap++;
      }
   }

   /* if remap!=0, we need reallocate counters */
   if (remap) {
      if (_papi_hwd_allocate_registers(ESI)) {
         retval =
             _papi_hwd_update_control_state(&ESI->machdep, ESI->NativeInfoArray,
                                            ESI->NativeCount,&ESI->master->context);
         if (retval != PAPI_OK)
	   {
	   clean:
	     for (i = 0; i < size; i++) {
	       if ((nidx = add_native_fail_clean(ESI, nevt[i])) >= 0) {
		 out->pos[i] = -1;
		 continue;
	       }
	       INTDBG("should not happen!\n");
	     }
	     return (retval);
	   }
         return 1;
      } else {
	  retval = -1;
	  goto clean;
      }
   }
   return 0;
}


int _papi_hwi_add_event(EventSetInfo_t * ESI, int EventCode)
{
   int i, j, thisindex, remap, retval = PAPI_OK;

   /* Make sure the event is not present and get the next
      free slot. */
   thisindex = get_free_EventCodeIndex(ESI, EventCode);
   if (thisindex < PAPI_OK)
      return (thisindex);

   /* If it is a MPX EventSet, add it to the multiplex data structure and
      this threads multiplex list */

   if (!_papi_hwi_is_sw_multiplex(ESI)) {

      if (EventCode & PAPI_PRESET_MASK) {
         int count;
         int preset_index = EventCode & PAPI_PRESET_AND_MASK;


         /* Check if it's within the valid range */
         if ((preset_index < 0) || (preset_index >= PAPI_MAX_PRESET_EVENTS))
            return (PAPI_EINVAL);

         /* count the number of native events in this preset */
         count = _papi_hwi_presets.count[preset_index];

         /* Check if event exists */
         if (!count)
            return (PAPI_ENOEVNT);

         /* check if the native events have been used as overflow events */
         if (ESI->state & PAPI_OVERFLOWING) {
            for (i = 0; i < count; i++) {
               for (j = 0; j < ESI->overflow.event_counter; j++) {
                  if (ESI->overflow.EventCode[j] ==
                      (_papi_hwi_presets.data[preset_index]->native[i]))
                     return (PAPI_ECNFLCT);
               }
            }
         }

         /* Try to add the preset. */

         remap =
             add_native_events(ESI, _papi_hwi_presets.data[preset_index]->native, count,
                               &ESI->EventInfoArray[thisindex]);
         if (remap < 0)
            return (PAPI_ECNFLCT);
         else {
            /* Fill in the EventCode (machine independent) information */

            ESI->EventInfoArray[thisindex].event_code = EventCode;
            ESI->EventInfoArray[thisindex].derived =
                _papi_hwi_presets.data[preset_index]->derived;
            ESI->EventInfoArray[thisindex].ops =
                _papi_hwi_presets.data[preset_index]->operation;
            if (remap)
               remap_event_position(ESI, thisindex);
         }
      } else if (EventCode & PAPI_NATIVE_MASK) {
         /* Check if native event exists */
         if (_papi_hwi_query_native_event(EventCode) != PAPI_OK)
            return (PAPI_ENOEVNT);

         /* check if the native events have been used as overflow
            events */
         if (ESI->state & PAPI_OVERFLOWING) {
            for (j = 0; j < ESI->overflow.event_counter; j++) {
               if (EventCode == ESI->overflow.EventCode[j])
                  return (PAPI_ECNFLCT);
            }
         }

         /* Try to add the native. */

         remap = add_native_events(ESI, &EventCode, 1, &ESI->EventInfoArray[thisindex]);
         if (remap < 0)
            return (PAPI_ECNFLCT);
         else {
            /* Fill in the EventCode (machine independent) information */

            ESI->EventInfoArray[thisindex].event_code = EventCode;
            if (remap)
               remap_event_position(ESI, thisindex);
         }
      } else {
         /* not Native and Preset events */

         return (PAPI_EBUG);
      }

   } else {
      /* Multiplexing is special. See multiplex.c */
     retval = mpx_add_event(&ESI->multiplex.mpx_evset, EventCode);
      if (retval < PAPI_OK)
         return (retval);
      ESI->EventInfoArray[thisindex].event_code = EventCode;    /* Relevant */
      ESI->EventInfoArray[thisindex].derived = NOT_DERIVED;

   }

   /* Bump the number of events */
   ESI->NumberOfEvents++;

   return (retval);
}


int _papi_hwi_add_pevent(EventSetInfo_t * ESI, int EventCode, void *inout)
{
   int thisindex, retval;

   /* Make sure the event is not present and get a free slot. */

   thisindex = get_free_EventCodeIndex(ESI, EventCode);
   if (thisindex < PAPI_OK)
      return (thisindex);

   /* Fill in machine depending info including the EventInfoArray. */

   retval =
       _papi_hwd_add_prog_event(&ESI->machdep, EventCode, inout,
                                &ESI->EventInfoArray[thisindex]);
   if (retval < PAPI_OK)
      return (retval);

   /* Initialize everything left over. */

   /* ESI->sw_stop[thisindex]     = 0; */
   /* ESI->hw_start[thisindex]   = 0; */

   ESI->NumberOfEvents++;
   return (retval);
}


int remove_native_events(EventSetInfo_t * ESI, int *nevt, int size)
{
   hwd_control_state_t *this_state = &ESI->machdep;
   NativeInfo_t *native = ESI->NativeInfoArray;
   int i, j, zero = 0, retval;

   /* Remove the references to this event from the native events:
      for all the metrics in this event,
      compare to each native event in this event set,
      and decrement owners if they match  */
   for (i = 0; i < size; i++) {
      for (j = 0; j < ESI->NativeCount; j++) {
         if (native[j].ni_event == nevt[i]) {
            native[j].ni_owners--;
            if (native[j].ni_owners == 0) {
               zero++;
            }
            break;
         }
      }
   }

   /* Remove any native events from the array if owners dropped to zero.
      The NativeInfoArray must be dense, with no empty slots, so if we
      remove an element, we must compact the list */
   for (i = 0; i < ESI->NativeCount; i++) {
      if (native[i].ni_event == 0)
         continue;

      if (native[i].ni_owners == 0) {
         int copy = 0;
         for (j = ESI->NativeCount - 1; j > i; j--) {
            if (native[j].ni_event == 0 || native[j].ni_owners == 0)
               continue;
            else {
               memcpy(native + i, native + j, sizeof(NativeInfo_t));
               memset(native + j, 0, sizeof(NativeInfo_t));
               native[j].ni_position = -1;
               copy++;
               break;
            }
         }
         if (copy == 0) {
            memset(native + i, 0, sizeof(NativeInfo_t));
            native[i].ni_position = -1;
         }
      }
   }

   /* to reset hwd_control_state values */
   ESI->NativeCount -= zero;

   /* If we removed any elements, 
      clear the now empty slots, reinitialize the index, and update the count.
      Then send the info down to the substrate to update the hwd control structure. */
   if (zero) {
      retval = _papi_hwd_update_control_state(this_state, native, ESI->NativeCount,
		&ESI->master->context);
      if (retval != PAPI_OK)
         return (retval);
   }

   return (PAPI_OK);
}

int _papi_hwi_remove_event(EventSetInfo_t * ESI, int EventCode)
{
   int j = 0, retval, thisindex;
   EventInfo_t *array;

   thisindex = _papi_hwi_lookup_EventCodeIndex(ESI, EventCode);
   if (thisindex < PAPI_OK)
      return (thisindex);

   /* If it is a MPX EventSet, remove it from the multiplex data structure and
      this threads multiplex list */

   if (_papi_hwi_is_sw_multiplex(ESI)) {
      retval = mpx_remove_event(&ESI->multiplex.mpx_evset, EventCode);
      if (retval < PAPI_OK)
         return (retval);
   } else
      /* Remove the events hardware dependent stuff from the EventSet */
   {
      if (EventCode & PAPI_PRESET_MASK) {
         int preset_index = EventCode & PAPI_PRESET_AND_MASK;

         /* Check if it's within the valid range */
         if ((preset_index < 0) || (preset_index >= PAPI_MAX_PRESET_EVENTS))
            return (PAPI_EINVAL);

         /* Check if event exists */
         if (!_papi_hwi_presets.count[preset_index])
            return (PAPI_ENOEVNT);

         /* Remove the preset event. */
         for (j = 0; _papi_hwi_presets.data[preset_index]->native[j] != 0; j++);
         retval =
             remove_native_events(ESI, _papi_hwi_presets.data[preset_index]->native, j);
         if (retval != PAPI_OK)
            return (retval);
      } else if (EventCode & PAPI_NATIVE_MASK) {
         /* Check if native event exists */
         if (_papi_hwi_query_native_event(EventCode) != PAPI_OK)
            return (PAPI_ENOEVNT);

         /* Remove the native event. */
         retval = remove_native_events(ESI, &EventCode, 1);
         if (retval != PAPI_OK)
            return (retval);
      } else
         return (PAPI_ENOEVNT);
   }
      array = ESI->EventInfoArray;

      /* Compact the Event Info Array list if it's not the last event */
      /* clear the newly empty slot in the array */
      for(;thisindex<ESI->NumberOfEvents-1;thisindex++)
         array[thisindex] = array[thisindex+1];

      array[thisindex].event_code = PAPI_NULL;
      for (j = 0; j < MAX_COUNTER_TERMS; j++)
         array[thisindex].pos[j] = -1;
      array[thisindex].ops = NULL;
      array[thisindex].derived = NOT_DERIVED;
   ESI->NumberOfEvents--;

   return (PAPI_OK);
}

int _papi_hwi_read(hwd_context_t * context, EventSetInfo_t * ESI, long_long * values)
{
   int retval;
   long_long *dp;
   int i, j = 0, index;

   retval = _papi_hwd_read(context, &ESI->machdep, &dp, ESI->state);
   if (retval != PAPI_OK)
     return (retval);


   /* This routine distributes hardware counters to software counters in the
      order that they were added. Note that the higher level
      EventInfoArray[i] entries may not be contiguous because the user
      has the right to remove an event.
      But if we do compaction after remove event, this function can be 
      changed.  
    */

   for (i = 0; i < _papi_hwi_system_info.sub_info.num_mpx_cntrs; i++) 
     {
       index = ESI->EventInfoArray[i].pos[0];
      if (index == -1)
         continue;

      INTDBG("Event index %d, position is 0x%x\n", j, index);

      /* If this is not a derived event */

      if (ESI->EventInfoArray[i].derived == NOT_DERIVED) 
	{
	  INTDBG("counter index is %d\n", index);
	  values[j] = dp[index];
	} 
      else /* If this is a derived event */ 
	{ 
	  values[j] = handle_derived(&ESI->EventInfoArray[i], dp);
#ifdef DEBUG
	  if (values[j] < (long_long)0) {
            INTDBG("Derived Event is negative!!: %lld\n", values[j]);
	  }
      INTDBG("read value is =%lld \n", values[j]);
#endif
	}

      /* Early exit! */
      if (++j == ESI->NumberOfEvents)
         break;
     }

   return (PAPI_OK);
}

int _papi_hwi_cleanup_eventset(EventSetInfo_t * ESI)
{
   int retval, i, tmp = _papi_hwi_system_info.sub_info.num_mpx_cntrs;
   /* Always clean the whole thing */

   for (i = (tmp - 1); i >= 0; i--) {
      if (ESI->EventInfoArray[i].event_code != PAPI_NULL) {
         retval = _papi_hwi_remove_event(ESI, ESI->EventInfoArray[i].event_code);
         if (retval != PAPI_OK)
            return (retval);
      }
   }

   return (PAPI_OK);
}

int _papi_hwi_convert_eventset_to_multiplex(_papi_int_multiplex_t *mpx)
{
  int retval, i, j = 0, *mpxlist = NULL;
  EventSetInfo_t * ESI = mpx->ESI;
  int flags = mpx->flags;

   /* If there are any events in the EventSet, 
      convert them to multiplex events */

   if (ESI->NumberOfEvents)
     {											  
       mpxlist = (int *) papi_malloc(sizeof(int) * ESI->NumberOfEvents);
       if (mpxlist == NULL) 
	   return (PAPI_ENOMEM);

       /* Build the args to MPX_add_events(). */

       /* Remember the EventInfoArray can be sparse
	  and the data can be non-contiguous */

       for (i = 0; i < EventInfoArrayLength(ESI); i++)
         if (ESI->EventInfoArray[i].event_code != PAPI_NULL)
	   mpxlist[j++] = ESI->EventInfoArray[i].event_code;

       /* Resize the EventInfo_t array */
       
       if ((_papi_hwi_system_info.sub_info.kernel_multiplex == 0) || 
	   ((_papi_hwi_system_info.sub_info.kernel_multiplex) && 
	    (flags & PAPI_MULTIPLEX_FORCE_SW))) 
	 {
	   retval = MPX_add_events(&ESI->multiplex.mpx_evset, mpxlist, j);
	   if (retval != PAPI_OK) 
	     {
	       papi_free(mpxlist);
	       return (retval);
	     }
	   papi_free(mpxlist);
	 }
     }

   /* Update the state before initialization! */

   ESI->state |= PAPI_MULTIPLEXING;
   if (_papi_hwi_system_info.sub_info.kernel_multiplex && (flags & PAPI_MULTIPLEX_FORCE_SW))
     ESI->multiplex.flags = PAPI_MULTIPLEX_FORCE_SW;
   ESI->multiplex.us = mpx->us;
 
   return (PAPI_OK);
}

#if 0
int _papi_hwi_query(int preset_index, int *flags, char **note)
{
   if (_papi_hwd_preset_map[preset_index].number == 0)
      return (0);
   INTDBG("preset_index: %d derived: %d\n", preset_index,
          _papi_hwd_preset_map[preset_index].derived);
   if (_papi_hwd_preset_map[preset_index].derived)
      *flags = PAPI_DERIVED;
   INTDBG("note: %s\n", _papi_hwd_preset_map[preset_index].note);
   if (_papi_hwd_preset_map[preset_index].note)
      *note = _papi_hwd_preset_map[preset_index].note;
   return (1);
}
#endif

/*
 * Routine that initializes the substrates
 * Currently, only one substrate is initialized, eventually
 * this will be many substrates
 */
int _papi_hwi_init_global(void)
{
   int retval;

#ifdef PAPI_NO_VECTOR
   retval = _papi_hwd_init_substrate(NULL);
#else
   retval = _papi_hwi_initialize_vector_table(&_papi_vector_table);
   if (retval != PAPI_OK ) return(retval);
   retval = _papi_hwd_init_substrate(&_papi_vector_table);
#endif
   return(retval);
}

/* Machine info struct initialization using defaults */
/* See _papi_mdi definition in papi_internal.h       */

int _papi_hwi_init_global_internal(void)
{
  int retval;
  extern const hwi_preset_info_t _papi_hwi_preset_info[PAPI_MAX_PRESET_EVENTS];

  memset(&_papi_hwi_presets,0x0,sizeof(_papi_hwi_presets));
  /* This member is static */
  _papi_hwi_presets.info = _papi_hwi_preset_info;

  memset(&_papi_hwi_system_info,0x0,sizeof(_papi_hwi_system_info));

   /* Global struct to maintain EventSet mapping */
   retval = allocate_eventset_map(&_papi_hwi_system_info.global_eventset_map);
   if (retval != PAPI_OK)
     return(retval);

   _papi_hwi_system_info.pid = 0;       /* Process identifier */

   /* The PAPI_substrate_info_t struct defined in papi.h */

   _papi_hwi_system_info.sub_info.name[0] = '\0';              /* Name of the substrate we're using, usually CVS RCS Id */
   _papi_hwi_system_info.sub_info.version[0] = '\0';           /* Version of this substrate, usually CVS Revision */
   _papi_hwi_system_info.sub_info.support_version[0] = '\0';   /* Version of the support library */
   _papi_hwi_system_info.sub_info.kernel_version[0] = '\0';    /* Version of the kernel PMC support driver */
   _papi_hwi_system_info.sub_info.num_cntrs = 0;               /* Number of counters the substrate supports */
   _papi_hwi_system_info.sub_info.num_mpx_cntrs = PAPI_MPX_DEF_DEG; /* Number of counters the substrate (or PAPI) can multiplex */
   _papi_hwi_system_info.sub_info.num_preset_events = 0;       
   _papi_hwi_system_info.sub_info.num_native_events = 0;       
   _papi_hwi_system_info.sub_info.default_domain = PAPI_DOM_USER;          /* The default domain when this substrate is used */
   _papi_hwi_system_info.sub_info.available_domains = _papi_hwi_system_info.sub_info.default_domain;       /* Available domains */ 
   _papi_hwi_system_info.sub_info.default_granularity = PAPI_GRN_THR;     /* The default granularity when this substrate is used */
   _papi_hwi_system_info.sub_info.available_granularities = _papi_hwi_system_info.sub_info.default_granularity; /* Available granularities */
   _papi_hwi_system_info.sub_info.opcode_match_width = 0;      /* Width of opcode matcher if exists, 0 if not */
   _papi_hwi_system_info.sub_info.multiplex_timer_sig = PAPI_SIGNAL;
   _papi_hwi_system_info.sub_info.multiplex_timer_num = PAPI_ITIMER;
   _papi_hwi_system_info.sub_info.multiplex_timer_us = PAPI_MPX_DEF_US;
   _papi_hwi_system_info.sub_info.hardware_intr_sig = PAPI_SIGNAL;
   _papi_hwi_system_info.sub_info.reserved_ints[0] = 0;
   _papi_hwi_system_info.sub_info.reserved_ints[1] = 0;
   _papi_hwi_system_info.sub_info.reserved_ints[2] = 0;
   _papi_hwi_system_info.sub_info.reserved_ints[3] = 0;
   _papi_hwi_system_info.sub_info.hardware_intr = 0;         /* Needs hw overflow intr to be emulated in software*/
   _papi_hwi_system_info.sub_info.precise_intr = 0;          /* Performance interrupts happen precisely */
   _papi_hwi_system_info.sub_info.posix1b_timers = 0;        
   _papi_hwi_system_info.sub_info.kernel_profile = 0;        /* Needs kernel profile support (buffered interrupts) to be emulated */
   _papi_hwi_system_info.sub_info.kernel_multiplex = 0;      /* In kernel multiplexing */
   _papi_hwi_system_info.sub_info.data_address_range = 0;    /* Supports data address range limiting */
   _papi_hwi_system_info.sub_info.instr_address_range = 0;   /* Supports instruction address range limiting */
   _papi_hwi_system_info.sub_info.fast_real_timer = 0;       /* Has a fast real timer */
   _papi_hwi_system_info.sub_info.fast_virtual_timer = 0;    /* Has a fast virtual timer */
   _papi_hwi_system_info.sub_info.attach = 0;    	     /* Can attach */
   _papi_hwi_system_info.sub_info.attach_must_ptrace = 0;    /* Attaching code must first ptrace and stop the child */
   _papi_hwi_system_info.sub_info.edge_detect = 0;           /* Supports edge detection on events */
   _papi_hwi_system_info.sub_info.invert = 0;                /* Supports invert detection on events */
   _papi_hwi_system_info.sub_info.profile_ear = 0;           /* Supports data/instr/tlb miss address sampling */
   _papi_hwi_system_info.sub_info.grouped_cntrs = 0;         
   _papi_hwi_system_info.sub_info.reserved_bits = 0;

   /* The PAPI_hw_info_t struct defined in papi.h */
   _papi_hwi_system_info.hw_info.ncpu = 0;     /* ncpu */
   _papi_hwi_system_info.hw_info.nnodes = 1;    /* nnodes */
   _papi_hwi_system_info.hw_info.totalcpus = 0;        /* totalcpus */
   _papi_hwi_system_info.hw_info.vendor = 0;   /* vendor */
   _papi_hwi_system_info.hw_info.vendor_string[0] = '\0';       /* vendor_string */
   _papi_hwi_system_info.hw_info.model = 0;    /* model */
   _papi_hwi_system_info.hw_info.model_string[0] = '\0';        /* model_string */
   _papi_hwi_system_info.hw_info.revision = 0.0;        /* revision */
   _papi_hwi_system_info.hw_info.mhz = 0.0;     /* mhz */
 
   return (PAPI_OK);
}

void _papi_hwi_shutdown_global_internal(void)
{
  _papi_hwi_cleanup_all_presets();
  free_eventset_map(&_papi_hwi_system_info.global_eventset_map);
  if (_papi_hwi_system_info.shlib_info.map){
     papi_free(_papi_hwi_system_info.shlib_info.map);
  }
  memset(&_papi_hwi_system_info,0x0,sizeof(_papi_hwi_system_info));
}

void _papi_hwi_dummy_handler(int EventSet, void *address, long_long  overflow_vector, void * context)
{
   /* This function is not used and shouldn't be called. */
   return;
}

static long_long handle_derived_add(int *position, long_long * from)
{
   int pos, i;
   long_long retval = 0;

   i = 0;
   while (i < MAX_COUNTER_TERMS) {
      pos = position[i++];
      if (pos == PAPI_NULL)
         break;
      INTDBG("Compound event, adding %lld to %lld\n", from[pos], retval);
      retval += from[pos];
   }
   return (retval);
}

static long_long handle_derived_subtract(int *position, long_long * from)
{
   int pos, i;
   long_long retval = from[position[0]];

   i = 1;
   while (i < MAX_COUNTER_TERMS) {
      pos = position[i++];
      if (pos == PAPI_NULL)
         break;
      INTDBG("Compound event, subtracting pos=%d  %lld from %lld\n", pos, from[pos],
             retval);
      retval -= from[pos];
   }
   return (retval);
}

static long_long units_per_second(long_long units, long_long cycles)
{
   return((units * (long_long)_papi_hwi_system_info.hw_info.mhz * (long_long)1000000)/cycles);
}

static long_long handle_derived_ps(int *position, long_long * from)
{
   return (units_per_second(from[position[1]], from[position[0]]));
}
static long_long handle_derived_add_ps(int *position, long_long * from)
{
   long_long tmp = handle_derived_add(position + 1, from);
   return (units_per_second(tmp, from[position[0]]));
}

/* this function implement postfix calculation, it reads in a string where I use:
      |      as delimiter
      N2     indicate No. 2 native event in the derived preset
      +, -, *, /, %  as operator
      #      as MHZ(million hz) got from  _papi_hwi_system_info.hw_info.mhz*1000000.0

  Haihang (you@cs.utk.edu)
*/ long_long _papi_hwi_postfix_calc(EventInfo_t * evi, long_long * hw_counter)
{
   char *point = evi->ops, operand[16];
   double stack[MAX_COUNTER_TERMS];
   int i, top = 0;

   while (*point != '\0') {
      if (*point == 'N') {      /* to get count for each native event */
         i = 0;
         point++;
         do {
            operand[i] = *point;
            point++;
            i++;
         } while (*point != '|');
         operand[i] = '\0';
         stack[top] = (double)hw_counter[evi->pos[atoi(operand)]];
         top++;
         point++;
      } else if (*point == '#') {       /* to get mhz, ignore the rest char's */
         stack[top] = _papi_hwi_system_info.hw_info.mhz * 1000000.0;
         top++;
         do {
            point++;
         } while (*point != '|');
         point++;
      } else if (isdigit(*point)) {     /* to get integer, I suppose only integer will be used, 
                                           no error check here, please only use integer */
         i = 0;
         do {
            operand[i] = *point;
            point++;
            i++;
         } while (*point != '|');
         operand[i] = '\0';
         stack[top] = atoi(operand);
         top++;
         point++;
      } else if (*point == '+') {       /* + calculation */
         stack[top - 2] += stack[top - 1];
         top--;
         do {
            point++;
         } while (*point != '|');
         point++;
      } else if (*point == '-') {       /* - calculation */
         stack[top - 2] -= stack[top - 1];
         top--;
         do {
            point++;
         } while (*point != '|');
         point++;
      } else if (*point == '*') {       /* * calculation */
         stack[top - 2] *= stack[top - 1];
         top--;
         do {
            point++;
         } while (*point != '|');
         point++;
      } else if (*point == '/') {       /* / calculation */
         stack[top - 2] /= stack[top - 1];
         top--;
         do {
            point++;
         } while (*point != '|');
         point++;
      } else {                  /* do nothing */
         do {
            point++;
         } while (*point != '|');
         point++;
      }
   }
   return (long_long) stack[0];
}

static long_long handle_derived(EventInfo_t * evi, long_long * from)
{
   switch (evi->derived) {
   case DERIVED_ADD:
      return (handle_derived_add(evi->pos, from));
   case DERIVED_ADD_PS:
      return (handle_derived_add_ps(evi->pos, from));
   case DERIVED_SUB:
      return (handle_derived_subtract(evi->pos, from));
   case DERIVED_PS:
      return (handle_derived_ps(evi->pos, from));
   case DERIVED_POSTFIX:
      return (_papi_hwi_postfix_calc(evi, from));
   case DERIVED_CMPD: /* This type has existed for a long time, but was never implemented.
                         Probably because its a no-op. However, if it's in a header, it
                         should be supported. As I found out when I implemented it in 
                         Pentium 4 for testing...dkt */
      return (from[evi->pos[0]]);
   default:
      PAPIERROR("BUG! Unknown derived command %d, returning 0",evi->derived);
      return((long_long)0);
   }
}

#if 0
void print_state(EventSetInfo_t * ESI)
{
   int i;

   APIDBG( "\n\n-----------------------------------------\n");
   APIDBG( "numEvent: %d    numNative: %d\n", ESI->NumberOfEvents,
           ESI->NativeCount);

   APIDBG( "\nnative_event_name       ");
   for (i = 0; i < MAX_COUNTERS; i++)
      APIDBG( "%15s",
              _papi_hwd_ntv_code_to_name(ESI->NativeInfoArray[i].ni_event));
   APIDBG( "\n");

   APIDBG( "native_event_position     ");
   for (i = 0; i < MAX_COUNTERS; i++)
      APIDBG( "%15d", ESI->NativeInfoArray[i].ni_position);
   APIDBG( "\n");

#if 0                           /* This code is specific to POWER */
   APIDBG( "native_event_selectors    ");
   for (i = 0; i < MAX_COUNTERS; i++)
      APIDBG( "%15d",
              native_table[ESI->NativeInfoArray[i].ni_event].resources.selector);
   APIDBG( "\n");

   APIDBG( "counter_cmd               ");
   for (i = 0; i < MAX_COUNTERS; i++)
      APIDBG( "%15d", (&(ESI->machdep))->counter_cmd.events[i]);
   APIDBG( "\n");
#endif

   APIDBG( "native links              ");
   for (i = 0; i < MAX_COUNTERS; i++)
      APIDBG( "%15d", ESI->NativeInfoArray[i].ni_owners);
   APIDBG( "\n");

}
#endif

/* this function recusively does Modified Bipartite Graph counter allocation 
    success  return 1
    fail     return 0
*/
int _papi_hwi_bipartite_alloc(hwd_reg_alloc_t * event_list, int count)
{
   int i, j;
   int idx_q[MAX_COUNTERS];     /* queue of indexes of lowest rank events */
   int map_q[MAX_COUNTERS];     /* queue of mapped events (TRUE if mapped) */
   int head, tail;

   /* build a queue of indexes to all events 
      that live on one counter only (rank == 1) */
   head = 0;                    /* points to top of queue */
   tail = 0;                    /* points to bottom of queue */
   for (i = 0; i < count; i++) {
      map_q[i] = 0;
      if (_papi_hwd_bpt_map_exclusive(&event_list[i]))
         idx_q[tail++] = i;
   }
   /* scan the single counter queue looking for events that share counters.
      If two events can live only on one counter, return failure.
      If the second event lives on more than one counter, remove shared counter
      from its selector and reduce its rank. 
      Mark first event as mapped to its counter. */ while (head < tail) {
      for (i = 0; i < count; i++) {
         if (i != idx_q[head]) {
            if (_papi_hwd_bpt_map_shared(&event_list[i], &event_list[idx_q[head]])) {
               /* both share a counter; if second is exclusive, mapping fails */
               if (_papi_hwd_bpt_map_exclusive(&event_list[i]))
                  return 0;
               else {
                  _papi_hwd_bpt_map_preempt(&event_list[i], &event_list[idx_q[head]]);
                  if (_papi_hwd_bpt_map_exclusive(&event_list[i]))
                     idx_q[tail++] = i;
               }
            }
         }
      }
      map_q[idx_q[head]] = 1;   /* mark this event as mapped */
      head++;
   }
   if (tail == count) {
      return 1;                 /* idx_q includes all events; everything is successfully mapped */
   } else {
      hwd_reg_alloc_t rest_event_list[MAX_COUNTERS];
      hwd_reg_alloc_t copy_rest_event_list[MAX_COUNTERS];
      int remainder;

      /* copy all unmapped events to a second list and make a backup */
      for (i = 0, j = 0; i < count; i++) {
         if (map_q[i] == 0) {
            memcpy(&copy_rest_event_list[j++], &event_list[i], sizeof(hwd_reg_alloc_t));
         }
      }
      remainder = j;

      memcpy(rest_event_list, copy_rest_event_list,
             sizeof(hwd_reg_alloc_t) * (remainder));

      /* try each possible mapping until you fail or find one that works */
      for (i = 0; i < MAX_COUNTERS; i++) {
         /* for the first unmapped event, try every possible counter */
         if (_papi_hwd_bpt_map_avail(rest_event_list, i)) {
            _papi_hwd_bpt_map_set(rest_event_list, i);
            /* remove selected counter from all other unmapped events */
            for (j = 1; j < remainder; j++) {
               if (_papi_hwd_bpt_map_shared(&rest_event_list[j], rest_event_list))
                  _papi_hwd_bpt_map_preempt(&rest_event_list[j], rest_event_list);
            }
            /* if recursive call to allocation works, break out of the loop */
            if (_papi_hwi_bipartite_alloc(rest_event_list, remainder))
               break;

            /* recursive mapping failed; copy the backup list and try the next combination */
            memcpy(rest_event_list, copy_rest_event_list,
                   sizeof(hwd_reg_alloc_t) * (remainder));
         }
      }
      if (i == MAX_COUNTERS) {
         return 0;              /* fail to find mapping */
      }
      for (i = 0, j = 0; i < count; i++) {
         if (map_q[i] == 0)
            _papi_hwd_bpt_map_update(&event_list[i], &rest_event_list[j++]);
      }
      return 1;
   }
}

/* _papi_hwi_get_event_info:
   Assumes EventCode contains a valid preset code.
   But defensive programming says check for NULL pointers.
   Returns a filled in PAPI_event_info_t structure containing
   descriptive strings and values for the specified preset event.
*/
int _papi_hwi_get_event_info(int EventCode, PAPI_event_info_t * info)
{
   int i = EventCode & PAPI_PRESET_AND_MASK;
   int j;

   if (_papi_hwi_presets.info[i].symbol) { /* if the event is in the preset table */
      info->event_code = EventCode;
      info->count = _papi_hwi_presets.count[i];
      strcpy(info->symbol, _papi_hwi_presets.info[i].symbol);
      if(_papi_hwi_presets.info[i].short_descr != NULL)
         strncpy(info->short_descr, _papi_hwi_presets.info[i].short_descr, sizeof(info->short_descr));
      if(_papi_hwi_presets.info[i].long_descr != NULL)
         strncpy(info->long_descr, _papi_hwi_presets.info[i].long_descr, sizeof(info->long_descr));
      info->derived[0] = '\0';
      info->postfix[0] = '\0';
      if (_papi_hwi_presets.data[i]) { /* if the event exists on this platform */
         strncpy(info->postfix, _papi_hwi_presets.data[i]->operation, sizeof(info->postfix));
         _papi_hwi_derived_string(_papi_hwi_presets.data[i]->derived, info->derived, sizeof(info->derived));
         for (j=0; j < (int)info->count; j++) {
            info->code[j] = _papi_hwi_presets.data[i]->native[j];
            _papi_hwi_native_code_to_name(info->code[j], info->name[j], sizeof(info->name[j]));
         }
      }
      if (_papi_hwi_presets.dev_note[i]) { /* if a developer's note exists for this event */
         strncpy(info->note, _papi_hwi_presets.dev_note[i], sizeof(info->note));
      } else info->note[0] = '\0';

      return(PAPI_OK);
   } else {
      return(PAPI_ENOEVNT);
   }
}

#ifdef PAPI_MOD_EVENTS /* defined if a modifiable event table is supported */
/* _papi_hwi_set_event_info:
   This is the internal version of the set_event_info code.
   Assumes that parameters are valid and that it is legal to
   replace events if requested. Also assumes preset events.
*/
int _papi_hwi_set_event_info(PAPI_event_info_t * info, int *EventCode)
{
   int i, j, retval;

   /* search the preset table for the first name match or first empty slot */
   for (i=0;i<PAPI_MAX_PRESET_EVENTS;i++) {
      if (_papi_hwi_presets.info[i].symbol == NULL) break;
/*      printf("old: %s  new: %s\n",_papi_hwi_presets.info[i].symbol,info->symbol); */
      if (!strcmp(_papi_hwi_presets.info[i].symbol, info->symbol)) break;
   }

   /* bail if the table's full */
   if (i >= PAPI_MAX_PRESET_EVENTS)
      return(PAPI_ENOTPRESET);

   /* At this point, we know the following:
      - i < PAPI_MAX_PRESET_EVENTS; AND
      - event[i] is  empty;  OR
      - event[i].symbol == info->symbol; 
   */

   *EventCode = i | PAPI_PRESET_MASK; /* set new EventCode (may not have changed) */
   _papi_hwi_presets.count[i] = info->count;

   /* There's currently a debate over the use of papi_xxx memory functions.
      One camp says they should always be used; the other says they're only
      for debug. Meanwhile, our code had better not rely on their function...
   */
#ifndef PAPI_NO_MEMORY_MANAGEMENT
  /* free the names and descriptions only if they were malloc'd by PAPI
   * Generally, this info is statically allocated at compile time.
   * This code overrides existing info, or appends new info to the table.
   * In these cases, papi_valid_free prevents pointers from being stranded.
   */
   if (_papi_hwi_presets.info[i].symbol) papi_valid_free(_papi_hwi_presets.info[i].symbol);
   if (_papi_hwi_presets.info[i].short_descr) papi_valid_free(_papi_hwi_presets.info[i].short_descr);
   if (_papi_hwi_presets.info[i].long_descr) papi_valid_free(_papi_hwi_presets.info[i].long_descr);
#endif
   _papi_hwi_presets.info[i].symbol = papi_strdup(info->symbol);
   _papi_hwi_presets.info[i].short_descr = papi_strdup(info->short_descr);
   _papi_hwi_presets.info[i].long_descr = papi_strdup(info->long_descr);

   if (_papi_hwi_presets.data[i] == NULL)
      _papi_hwi_presets.data[i] = papi_malloc(sizeof(hwi_preset_data_t));

   /* extract the derived type from the info->derived string */
   if (_papi_hwi_derived_type(info->derived,&_papi_hwi_presets.data[i]->derived) != PAPI_OK)
     return(PAPI_EINVAL);

   /* only copy the postfix string if it's a DERIVED_POSTFIX event */
   if (_papi_hwi_presets.data[i]->derived == DERIVED_POSTFIX)
      strncpy(_papi_hwi_presets.data[i]->operation, info->postfix, sizeof(info->postfix));

	/* copy the native event terms into the preset structure */
   /* names are passed in. check for validity and convert to codes */
   for (j=0; j < (int)info->count; j++) {
       retval = _papi_hwi_native_name_to_code(info->name[j],
          &_papi_hwi_presets.data[i]->native[j]);
       if(retval != PAPI_OK) {
          return(retval);
       }
   }

   if (info->note) { /* if a developer's note exists for this event */
      _papi_hwi_presets.dev_note[i] = papi_strdup(info->note);
   } else _papi_hwi_presets.dev_note[i] = NULL;
   return(PAPI_OK);
}
#endif /* PAPI_MOD_EVENTS */

