#ifndef PAPI_INTERNAL_H
#define PAPI_INTERNAL_H

/* 
* File:    papi_internal.h
* CVS:     $Id$
* Author:  Philip Mucci
*          mucci@cs.utk.edu
* Mods:    dan terpstra
*          terpstra.utk.edu
* Mods:    <your name here>
*          <your email address>
*/  

#ifdef DEBUG
/* add Win32 to the debug list */
#if (defined(sgi) && defined(mips)) || defined(_CRAYT3E) || (defined(__digital__) \
	|| defined(__osf__)) || (defined(sun) && defined(sparc)) || defined(_WIN32)
#define DBG(a) { extern int _papi_hwi_debug; if (_papi_hwi_debug) { fprintf(stderr,"DEBUG:%s:%d: ",__FILE__,__LINE__); fprintf a; } }
#else /* SV2,SV1 ? */
#define DBG(a) { extern int _papi_hwi_debug; if (_papi_hwi_debug) { fprintf(stderr,"DEBUG:%s:%s:%d: ",__FILE__,__FUNCTION__,__LINE__); fprintf a; } }
#endif
#else
#define DBG(a)
#endif

#define DEADBEEF 0xdedbeef

/* some members of structs and/or function parameters may or may not be
   necessary, but at this point, we have included anything that might 
   possibly be useful later, and will remove them as we progress */

/* Signal used for overflow delivery */

#ifdef ITIMER_REALPROF
#define PAPI_ITIMER ITIMER_REALPROF
#else
#define PAPI_ITIMER ITIMER_PROF
#endif
#define PAPI_SIGNAL SIGPROF
#define PAPI_ITIMER_MS 1

/* Mask which indicates the event is a preset- the presets will have 
   the high bit set to one, as the vendors probably won't use the 
   higher numbers for the native events */

#define PRESET_MASK 0x80000000

/* Commands used to compute derived events */

#define NOT_DERIVED      0x0  /* Do nothing */
#define DERIVED_ADD      0x1  /* Add counters */
#define DERIVED_PS       0x2  /* Divide by the cycle counter and convert to seconds */
#define DERIVED_ADD_PS   0x4  /* Add 2 counters then divide by the cycle counter and xl8 to secs. */
#define DERIVED_CMPD     0x8  /* Event lives in operand index but takes 2 or more codes */
#define DERIVED_SUB      0x10 /* Sub all counters from counter with operand_index */

typedef struct _EventSetMultistartInfo {
  int num_runners;
  int *SharedDepth; } EventSetMultistartInfo_t;

typedef struct _EventSetDomainInfo {
  int domain; } EventSetDomainInfo_t;

typedef struct _EventSetGranularityInfo {
  int granularity; } EventSetGranularityInfo_t;

typedef struct _EventSetOverflowInfo {
  long_long deadline;
  int count;
  int threshold;
  int EventIndex;
  int EventCode;
  int flags;
  int timer_ms;
  PAPI_overflow_handler_t handler;
} EventSetOverflowInfo_t;

#if 0
typedef struct _EventSetInheritInfo {
  int inherit; } EventSetInheritInfo_t;
#endif

typedef struct _EventSetProfileInfo {
  PAPI_sprofil_t *prof;
  int count; /* Number of buffers */
  int flags;
} EventSetProfileInfo_t;

/* PAPI supports derived events that are made up of at most 2 counters. */

typedef struct _EventInfo {
  unsigned event_code;      /* Preset code or PAPI_NATIVE */
  unsigned hardware_index;  /* Index of counter to read in buffer returned by the hardware/kernel */
  hwd_register_map_t bits;  /* Bits that keep track of used resources by this event */
#if 0
  unsigned hardware_selector;  /* Counter select bits used in the lower level */
  unsigned command;       /* Counter derivation command used in the lower level */
  unsigned operand_index; /* Counter derivation data used in the lower level */
#endif
} EventInfo_t;

/* Multiplex definitions */

/* This contains only the information about an event that
 * would cause two events to be counted separately.  Options
 * that don't affect an event aren't included here.
 */

typedef struct _papi_info {
	int event_type;
	int domain;
	int granularity;
} PapiInfo;

typedef struct _masterevent {
        int uses;
        int active;
	int is_a_rate;
	int papi_event;
	PapiInfo pi;
        long_long count;
        long_long cycles;
	long_long handler_count;
	struct _threadlist * mythr;
        struct _masterevent * next;
} MasterEvent;

typedef struct _threadlist {
#ifdef PTHREADS
	pthread_t thr;
#else
        pid_t pid;
#endif
        /* Total cycles for this thread */
	long_long total_c;
        /* Pointer to event in use */
	MasterEvent * cur_event;
        /* List of multiplexing events for this thread */
	MasterEvent * head;
        /* Pointer to next thread */
	struct _threadlist * next;
} Threadlist;

/* Structure contained in the EventSet structure that
   holds information about multiplexing. */

typedef enum { MPX_STOPPED, MPX_RUNNING } MPX_status;

typedef struct _MPX_EventSet {
	MPX_status status;
        /* Pointer to this thread's structure */
	struct _threadlist * mythr;
        /* Pointers to this EventSet's MPX entries in the master list for this thread */
	struct _masterevent *(mev[PAPI_MPX_DEF_DEG]);
        /* Number of entries in above list */
	int	num_events;
        /* Not sure... */
	long_long start_c, stop_c;
	long_long start_values[PAPI_MPX_DEF_DEG];
	long_long start_cycles[PAPI_MPX_DEF_DEG];
	long_long stop_values[PAPI_MPX_DEF_DEG];
	long_long stop_cycles[PAPI_MPX_DEF_DEG];
	long_long start_hc[PAPI_MPX_DEF_DEG];
} MPX_EventSet;

typedef MPX_EventSet * EventSetMultiplexInfo_t;

typedef struct _EventSetInfo {
  int EventSetIndex;       /* Index of the EventSet in the array  */

  int NumberOfEvents;    /* Number of counters added to EventSet */

  hwd_control_state_t machdep;      /* A pointer to memory of
			 sizeof(hwd_control_state_t) bytes. This 
                         will contain the encoding necessary for the 
                         hardware to set the counters to the appropriate
                         conditions*/

  long_long *hw_start;   /* Array of length _papi_system_info.num_cntrs that contains
			    unprocessed, out of order, long_long counter registers */

  long_long *sw_stop;    /* Array of length ESI->NumberOfCounters that contains
			    processed, in order, PAPI counter values when used or stopped */

  /* long_long *latest;   Array of the same length as above, containing 
				  the values of the counters when last read */ 

  int state;          /* The state of this entire EventSet; can be
			 PAPI_RUNNING or PAPI_STOPPED plus flags */

  EventInfo_t *EventInfoArray;   /* This array contains the mapping from 
                                  events added into the API into hardware 
                                  specific encoding as returned by the 
                                  kernel or the code that directly 
                                  accesses the counters. */

  EventSetMultistartInfo_t multistart;

  EventSetDomainInfo_t domain;

  EventSetGranularityInfo_t granularity;

  EventSetOverflowInfo_t overflow;
  
  EventSetMultiplexInfo_t multiplex;

  EventSetProfileInfo_t profile;
  
#if 0
  EventSetInheritInfo_t inherit;

#endif
  void *master;
} EventSetInfo_t;

typedef struct _dynamic_array{
	EventSetInfo_t   **dataSlotArray; /* array of ptrs to EventSets */
	int    totalSlots;      /* number of slots in dataSlotArrays      */
	int    availSlots;      /* number of open slots in dataSlotArrays */
	int    fullSlots;       /* number of full slots in dataSlotArray    */
	int    lowestEmptySlot; /* index of lowest empty dataSlotArray    */
} DynamicArray_t;

/* Substrate option types for _papi_hwd_ctl. */

typedef struct _papi_int_defdomain {
    int defdomain; } _papi_int_defdomain_t;

typedef struct _papi_int_domain {
    int domain;
    int eventset;
    EventSetInfo_t *ESI; } _papi_int_domain_t;

typedef struct _papi_int_granularity {
    int granularity;
    int eventset;
    EventSetInfo_t *ESI; } _papi_int_granularity_t;

typedef struct _papi_int_overflow {
  EventSetInfo_t *ESI;
  EventSetOverflowInfo_t overflow; } _papi_int_overflow_t;

typedef struct _papi_int_profile {
  EventSetInfo_t *ESI;
  EventSetProfileInfo_t profile; } _papi_int_profile_t;

#if 0
typedef struct _papi_int_inherit {
  EventSetInfo_t *master;
  int inherit; } _papi_int_inherit_t;
#endif

typedef union _papi_int_option_t {
  _papi_int_overflow_t overflow;
  _papi_int_profile_t profile;
  _papi_int_domain_t domain;
  _papi_int_defdomain_t defdomain;
#if 0
  _papi_int_inherit_t inherit;
#endif
  _papi_int_granularity_t granularity; 
} _papi_int_option_t;

/* Defined in papi.c */

extern unsigned long int (*_papi_hwi_thread_id_fn)(void);

typedef struct _papi_mdi {
  const char substrate[PAPI_MAX_STR_LEN]; /* Name of the substrate we're using */
  const float version;      /* Version of this substrate */
  pid_t pid;                /* Process identifier */
  PAPI_hw_info_t hw_info;   /* See definition in papi.h */
  PAPI_exe_info_t exe_info; /* See definition in papi.h */
  PAPI_shlib_info_t shlib_info; /* See definition in papi.h */

  /* The following variables define the length of the arrays in the 
     EventSetInfo_t structure. Each array is of length num_gp_cntrs + 
     num_sp_cntrs * sizeof(long_long) */

  int num_cntrs;   /* Number of counters returned by a substrate read/write */
                      
  int num_gp_cntrs;   /* Number of general purpose counters or counters
                         per group */
  int grouped_counters;   /* Number of counter groups, zero for no groups */
  int num_sp_cntrs;   /* Number of special purpose counters, like 
                         Time Stamp Counter on IBM or Pentium */

  int total_presets;  /* Number of preset events supported */

  int default_domain; /* The default domain when this substrate is used */

  int default_granularity; /* The default granularity when this substrate is used */

  /* Begin public feature flags */

  const int supports_program;        /* We can use programmable events */
  const int supports_write;          /* We can write the counters */
  int supports_hw_overflow;    /* Needs overflow to be emulated */
  int supports_hw_profile;     /* Needs profile to be emulated */
  const int supports_64bit_counters; /* Only limited precision is available from hardware */
  const int supports_inheritance;    /* We can pass on and inherit child counters/values */
  const int supports_attach;         /* We can attach PAPI to another process */
  const int supports_real_usec;      /* We can use the real_usec call */
  const int supports_real_cyc;       /* We can use the real_cyc call */
  const int supports_virt_usec;      /* We can use the virt_usec call */
  const int supports_virt_cyc;       /* We can use the virt_cyc call */

  /* End public feature flags */

  /* Begin private feature flags */

  const int supports_read_reset;     /* The read call from the kernel resets the counters */

  /* End private feature flags */

  DynamicArray_t global_eventset_map; /* Global structure to maintain int<->EventSet mapping */
} papi_mdi_t;

#endif /* PAPI_INTERNAL_H */
