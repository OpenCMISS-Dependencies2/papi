#include <signal.h>
#include <asm/ucontext.h>    /* sys/ucontext.h  apparently broken */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <errno.h>
#include <sys/times.h>
#include <sys/time.h>
#include <sys/types.h>
#ifndef __x86_64__
#include <asm/system.h>
#include <asm/param.h>
#include <asm/bitops.h>
#endif
#include <linux/unistd.h>	

#ifdef PERFCTR25
#define PERFCTR20
#endif

#ifndef CONFIG_SMP
/* Assert that CONFIG_SMP is set before including asm/atomic.h to 
 * get bus-locking atomic_* operations when building on UP kernels
 */
#define CONFIG_SMP
#endif
#include "asm/atomic.h"

#include "libperfctr.h"
#include "papi.h"

typedef struct hwd_control_state {
  /* Which counters to use? Bits encode counters to use, may be duplicates */
  int selector;  
  /* Is this event derived? */
  int derived;   
  /* Buffer to pass to the kernel to control the counters */
#ifdef PERFCTR20
  struct vperfctr_control counter_cmd;
#else
  struct perfctr_control counter_cmd;
#endif
  /* Buffer to control the kernel state of the counters */
  struct vperfctr *self;
} hwd_control_state_t;

#include "papi_internal.h"

#define CNTR1 0x1
#define CNTR2 0x2
#define CNTR3 0x4
#define CNTR4 0x8

#define ALLCNTRS (CNTR1|CNTR2|CNTR3|CNTR4)

#define PERF_MAX_COUNTERS 4

#define PERF_CTR_MASK          0xFF000000
#define PERF_INV_CTR_MASK      0x00800000
#define PERF_ENABLE            0x00400000
#define PERF_INT_ENABLE        0x00100000
#define PERF_PIN_CONTROL       0x00080000
#define PERF_EDGE_DETECT       0x00040000
#define PERF_OS                0x00020000
#define PERF_USR               0x00010000
#define PERF_UNIT_MASK         0x0000FF00
#define PERF_EVNT_MASK         0x000000FF

#ifdef PERFCTR20
struct papi_perfctr_counter_cmd {
  unsigned int evntsel[PERF_MAX_COUNTERS];
} papi_perfctr_counter_cmd ;
#endif

typedef struct hwd_preset {
  /* Which counters to use? Bits encode counters to use, may be duplicates */
  unsigned char selector;  
  /* Is this event derived? */
  unsigned char derived;   
  /* If the derived event is not associative, this index is the lead operand */
  unsigned char operand_index;
  /* Buffer to pass to the kernel to control the counters */
#ifdef PERFCTR20
  struct papi_perfctr_counter_cmd counter_cmd;
#else
  struct perfctr_control counter_cmd;
#endif
  /* If it exists, then this is the description of this event */
  char note[PAPI_MAX_STR_LEN];
} hwd_preset_t;

extern char *basename(char *);
extern caddr_t _init, _fini, _etext, _edata;
extern int get_memory_info( PAPI_mem_info_t * mem_info, int cpu_type );
