#ifndef _PAPI_AIX_H               /* _PAPI_AIX */
#define _PAPI_AIX_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <libgen.h>
#include <time.h>
#if defined( _AIX51) || defined(_AIX52)
#include <sys/procfs.h>
#include <sys/cred.h>
#endif
#include <procinfo.h>
#include <dlfcn.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/systemcfg.h>
#include <sys/processor.h>
#include <sys/atomic_op.h>
#include <sys/utsname.h>


#include "pmapi.h"

#define inline_static __inline

#define ANY_THREAD_GETS_SIGNAL
#define POWER_MAX_COUNTERS MAX_COUNTERS
#define MAX_COUNTER_TERMS MAX_COUNTERS
#define INVALID_EVENT -2
#define POWER_MAX_COUNTERS_MAPPING 8

extern _text;
extern _etext;
extern _edata;
extern _end;
extern _data;

/* globals */
pm_info_t pminfo;

/* Locks */
extern atomic_p lock[];

#define _papi_hwd_lock(lck)                     \
while(_check_lock(lock[lck],0,1) == TRUE)       \
{                                               \
   usleep(1000);                                \
}

#define _papi_hwd_unlock(lck)                   \
{                                               \
  _clear_lock(lock[lck], 0);                   \
}

/* overflow */
typedef siginfo_t hwd_siginfo_t;
typedef struct sigcontext hwd_ucontext_t;

#define GET_OVERFLOW_ADDRESS(ctx)  (void *)(((hwd_ucontext_t *)(ctx->ucontext))->sc_jmpbuf.jmp_context.iar)

/* prototypes */

#endif                          /* _PAPI_AIX */
