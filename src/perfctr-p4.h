#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <signal.h>
#include <unistd.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <errno.h>
#include <sys/times.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/ucontext.h>

#include <linux/unistd.h>	
#include <asm/system.h>
#include <asm/bitops.h>

#include "libperfctr.h"

#include "p4_events.h"

#ifndef PAPI3
#include "papi.h"
typedef struct _papi_address_map {
  char mapname[PAPI_MAX_STR_LEN];
  caddr_t text_start;   /* Start address of program text segment */
  caddr_t text_end;     /* End address of program text segment */
  caddr_t data_start;   /* Start address of program data segment */
  caddr_t data_end;     /* End address of program data segment */
  caddr_t bss_start;    /* Start address of program bss segment */
  caddr_t bss_end;      /* End address of program bss segment */
} PAPI_address_map_t;
#endif

/* Per event data structure for each event */

typedef struct P4_perfctr_event {
  unsigned pmc_map;
  unsigned evntsel;
  unsigned evntsel_aux;
  unsigned pebs_enable;
  unsigned pebs_matrix_vert;
  unsigned ireset;
} P4_perfctr_event_t;

#define P4_MAX_REGS_PER_EVENT 4

typedef struct P4_perfctr_codes {
  P4_perfctr_event_t data[P4_MAX_REGS_PER_EVENT];
} P4_perfctr_preset_t;

typedef struct P4_perfctr_avail {
  unsigned selector;               /* Mask for which counters in use */
  unsigned pebs_enable;            /* PEBS */
  unsigned pebs_matrix_vert;       /* PEBS_MATRIX_VERT */
} P4_register_t;

typedef struct P4_regmap {
  unsigned num_hardware_events;
  P4_register_t hardware_event[P4_MAX_REGS_PER_EVENT];
} P4_regmap_t;

/* Per eventset data structure for thread level counters */

typedef struct P4_perfctr_control {
  P4_register_t allocated_registers;
  struct vperfctr_control control; 
  struct perfctr_sum_ctrs state;
} P4_perfctr_control_t;

/* Per thread data structure for thread level counters */

typedef struct P4_perfctr_context {
  struct vperfctr *perfctr;
/*  P4_perfctr_control_t start; */
} P4_perfctr_context_t;

#ifndef PAPI3
typedef struct {
  P4_perfctr_control_t control;
  P4_perfctr_context_t context; 
}  hwd_control_state_t;
#else
typedef P4_perfctr_control_t hwd_control_state_t;
#endif

#ifndef PAPI3
#include "papi_internal.h"
extern caddr_t _init, _fini, _etext, _edata;
typedef EventSetInfo EventSetInfo_t;
typedef papi_mdi papi_mdi_t;
#endif

typedef P4_regmap_t hwd_register_map_t;

typedef P4_register_t hwd_register_t;

typedef P4_perfctr_context_t hwd_context_t;

typedef P4_perfctr_event_t hwd_event_t;

typedef struct _ThreadInfo {
  unsigned pid;
  unsigned tid;
  hwd_context_t context;
  void *event_set_overflowing;
  int domain;
} ThreadInfo_t;

extern ThreadInfo_t *default_master_thread;

#ifdef PAPI3
typedef struct _thread_list {
  ThreadInfo_t *master;
  struct _thread_list *next; 
} ThreadInfoList_t;
#endif

#if 0
#include "papi_internal.h"

/* Per thread data structure for global level counters */

typedef struct P4_perfctr_context {
  struct gperfctr *perfctr;
} P4_perfctr_global_context_t;

typedef struct P4_global_control {
  struct gperfctr_control *control; 
  struct gperfctr_state *state;
} P4_perfctr_global_control_t;
#include "papi_protos.h"
#endif


/* Per preset data structure statically defined in dense array in substrate */

typedef struct P4_search {
  unsigned preset;
  char *note;
  unsigned number;
  P4_perfctr_preset_t info;
} P4_search_t;

/* Per preset data structure dynamically defined in sparse array by substrate
   from array of P4_search_t's. */

typedef struct P4_preset {
  /* Is this event derived? */
  unsigned derived;   
  /* Number of counters in the following */
  unsigned number;
  /* Where can this register live */
  P4_regmap_t possible_registers;
  /* Information on how to construct the event */
  P4_perfctr_preset_t *info;
  /* If it exists, then this is the description of this event */
  char note[PAPI_MAX_STR_LEN];
} P4_preset_t;

typedef P4_preset_t hwd_preset_t;

#define AI_ERROR "No support for a-mode counters after adding an i-mode counter"
#define VOPEN_ERROR "vperfctr_open() returned NULL"
#define GOPEN_ERROR "gperfctr_open() returned NULL"
#define VINFO_ERROR "vperfctr_info() returned < 0"
#define VCNTRL_ERROR "vperfctr_control() returned < 0"
#define GCNTRL_ERROR "gperfctr_control() returned < 0"
#define FOPEN_ERROR "fopen(%s) returned NULL"
#define STATE_MAL_ERROR "Error allocating perfctr structures"
#define MODEL_ERROR "This is not a Pentium 4"
 
#define error_return(retval, format, args...) { fprintf(stderr,"Error in %s, function %s, line %d: ",__FILE__,__FUNCTION__,__LINE__); fprintf(stderr, format , ## args) ; fprintf(stderr, "\n"); return(retval); }
#ifdef DEBUG
#define DEBUGLABEL(a) fprintf(stderr,"%s:%s:%s:%d: ",a,__FILE__,__FUNCTION__,__LINE__)
#define SUBDBG(format, args...) { extern int _papi_hwi_debug; if (_papi_hwi_debug) { DEBUGLABEL("SUBSTRATE"); fprintf (stderr, format , ## args); } }
#else
#define SUBDBG(format, args...) { ; }
#endif

#ifndef PAPI3
#define _papi_hwi_debug papi_debug
#endif

#define PAPI_VENDOR_UNKNOWN -1
#define PAPI_VENDOR_INTEL   1
#define PAPI_VENDOR_AMD     2
#define PAPI_VENDOR_CYRIX   3

/* Stupid linux basename prototype! */

extern char *basename(char *);
extern int sighold(int);
extern int sigrelse(int);

/* Undefined identifiers in executable */

extern caddr_t _start, _fini, _end, _edata, __data_start, __bss_start;
extern int get_memory_info( PAPI_mem_info_t * mem_info, int cpu_type );
extern int _papi_hwd_get_system_info(void);
