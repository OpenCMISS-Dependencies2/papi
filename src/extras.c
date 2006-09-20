/****************************/
/* THIS IS OPEN SOURCE CODE */
/****************************/

/* 
* File:    extras.c
* CVS:     $Id$
* Author:  Philip Mucci
*          mucci@cs.utk.edu
* Mods:    dan terpstra
*          terpstra@cs.utk.edu
* Mods:    Haihang You
*          you@cs.utk.edu
* Mods:    Kevin London
*          london@cs.utk.edu
* Mods:    Maynard Johnson
*          maynardj@us.ibm.com
*/

/* This file contains portable routines to do things that we wish the
vendors did in the kernel extensions or performance libraries. */

/* It also contains a new section at the end with Windows routines
 to emulate standard stuff found in Unix/Linux, but not Windows! */

#include "papi.h"
#include "papi_internal.h"
#include "papi_vector.h"
#include "papi_vector_redefine.h"

/*******************/
/* BEGIN EXTERNALS */
/*******************/

extern papi_mdi_t _papi_hwi_system_info;

#ifdef ANY_THREAD_GETS_SIGNAL
extern void _papi_hwi_lookup_thread_symbols(void);
extern int (*_papi_hwi_thread_kill_fn) (int, int);
#endif

/*****************/
/* END EXTERNALS */
/*****************/

/****************/
/* BEGIN LOCALS */
/****************/

static unsigned int _rnum = DEADBEEF;

/**************/
/* END LOCALS */
/**************/

extern unsigned long int (*_papi_hwi_thread_id_fn) (void);

inline_static unsigned short random_ushort(void)
{
   return (unsigned short) (_rnum = 1664525 * _rnum + 1013904223);
}


/* compute the amount by which to increment the bucket.
   value is the current value of the bucket
   this routine is used by all three profiling cases
   it is inlined for speed
*/
inline_static int profil_increment(long_long value,
                            int flags, long_long excess,
                            long_long threshold)
{
   int increment = 1;

   if (flags == PAPI_PROFIL_POSIX) {
      return(1);
   }

   if (flags & PAPI_PROFIL_RANDOM) {
      if (random_ushort() <= (USHRT_MAX / 4))
         return(0);
   }

   if (flags & PAPI_PROFIL_COMPRESS) {
      /* We're likely to ignore the sample if buf[address] gets big. */
      if (random_ushort() < value) {
         return(0);
      }
   }

   if (flags & PAPI_PROFIL_WEIGHTED) {  /* Increment is between 1 and 255 */
      if (excess <= (long_long) 1)
         increment = 1;
      else if (excess > threshold)
         increment = 255;
      else {
         threshold = threshold / (long_long) 255;
         increment = (int) (excess / threshold);
      }
   }
   return(increment);
}


static void posix_profil(caddr_t address, PAPI_sprofil_t * prof,
                         int flags, long_long excess, long_long threshold)
{
   unsigned short *buf16;
   unsigned int *buf32;
   u_long_long *buf64;
   unsigned long indx;
   u_long_long lloffset;

   /* SPECIAL CASE: if starting address is 0 and scale factor is 2
                    then all counts go into first bin.
   */
   if ((prof->pr_off == 0) && (prof->pr_scale == 0x2))
      indx = 0;
   else {
      /* compute the profile buffer offset by:
         - subtracting the profiling base address from the pc address
         - multiplying by the scaling factor
         - dividing by max scale (65536, or 2^^16) 
         - dividing by implicit 2 (2^^1 for a total of 2^^17), for even addresses
         NOTE: 131072 is a valid scale value. It produces byte resolution of addresses
      */
      lloffset = ((u_long_long)(address - prof->pr_off)) * prof->pr_scale;
      indx = (unsigned long)(lloffset >> 17);
   }

   /* confirm addresses within specified range */
   if (address >= prof->pr_off) {
      /* test first for 16-bit buckets; this should be the fast case */
      if (flags & PAPI_PROFIL_BUCKET_16) {
         if ((indx * sizeof(short)) < prof->pr_size) {
            buf16 = prof->pr_base;
            buf16[indx] += profil_increment(buf16[indx], flags, excess, threshold);
            PRFDBG("posix_profil_16() bucket %lu = %u\n", indx, buf16[indx]);
         }
      }
      /* next, look for the 32-bit case */
      else if (flags & PAPI_PROFIL_BUCKET_32) {
         if ((indx * sizeof(int)) < prof->pr_size) {
            buf32 = prof->pr_base;
            buf32[indx] += profil_increment(buf32[indx], flags, excess, threshold);
            PRFDBG("posix_profil_32() bucket %lu = %u\n", indx, buf32[indx]);
         }
      }
      /* finally, fall through to the 64-bit case */
      else {
         if ((indx * sizeof(long_long)) < prof->pr_size) {
            buf64 = prof->pr_base;
            buf64[indx] += profil_increment(buf64[indx], flags, excess, threshold);
            PRFDBG("posix_profil_64() bucket %lu = %lld\n", indx, buf64[indx]);
         }
      }
   }
}

void _papi_hwi_dispatch_profile(EventSetInfo_t * ESI, void *context,
                      long_long over, int profile_index)
{
  _papi_hwi_context_t *ctx = (_papi_hwi_context_t *) context;

   EventSetProfileInfo_t *profile = &ESI->profile;
   caddr_t pc = (caddr_t) GET_OVERFLOW_ADDRESS(ctx);
   PAPI_sprofil_t *sprof;

  caddr_t offset = (caddr_t)0;
  caddr_t best_offset = (caddr_t)0;
  int count;
  int best_index = -1;
  int i;

  PRFDBG("handled at %p\n",pc);

  sprof = profile->prof[profile_index];
  count = profile->count[profile_index];
    
  for (i = 0; i < count; i++)
  {
      offset = (caddr_t)sprof[i].pr_off;
      if ((offset < pc) && (offset > best_offset))
      {
         best_index = i;
         best_offset = offset;
      }
   }

   if (best_index == -1)
      best_index = 0;

   posix_profil(pc, &sprof[best_index], profile->flags, over,
                profile->threshold[profile_index]);
}

/* if isHardware is true, then the processor is using hardware overflow,
   else it is using software overflow. Use this parameter instead of 
   _papi_hwi_system_info.supports_hw_overflow is in CRAY some processors
   may use hardware overflow, some may use software overflow.

   overflow_bit: if the substrate can get the overflow bit when overflow
                 occurs, then this should be passed by the substrate;

   If both genOverflowBit and isHardwareSupport are true, that means
     the substrate doesn't know how to get the overflow bit from the
     kernel directly, so we generate the overflow bit in this function 
    since this function can access the ESI->overflow struct;
   (The substrate can only set genOverflowBit parameter to true if the
     hardware doesn't support multiple hardware overflow. If the
     substrate supports multiple hardware overflow and you don't know how 
     to get the overflow bit, then I don't know how to deal with this 
     situation).
*/

int _papi_hwi_dispatch_overflow_signal(void *papiContext, int *isHardware, long_long overflow_bit, int genOverflowBit, ThreadInfo_t **t)
{
   int retval, event_counter, i, overflow_flag, pos;
   int papi_index, j;
   int profile_index = 0;
   long_long overflow_vector;

   long_long temp[MAX_COUNTERS], over;
   long_long latest = 0;
   ThreadInfo_t *thread;
   EventSetInfo_t *ESI;
   _papi_hwi_context_t *ctx = (_papi_hwi_context_t *) papiContext;

   OVFDBG("enter\n");

   if (*t) 
     thread = *t;
   else
     *t = thread = _papi_hwi_lookup_thread();
   
   if (thread != NULL) 
     {
       ESI = thread->running_eventset;

       if ((ESI == NULL) || ((ESI->state & PAPI_OVERFLOWING) == 0))
	 {
	   OVFDBG("Either no eventset or eventset not set to overflow.\n");
#ifdef ANY_THREAD_GETS_SIGNAL
	   _papi_hwi_broadcast_signal(thread->tid);
#endif
	   return(PAPI_OK);
	 }

       if (ESI->master != thread)
	 {
	   PAPIERROR("eventset->thread 0x%lx vs. current thread 0x%lx mismatch",ESI->master,thread);
	   return(PAPI_EBUG);
	 }

      if ( isHardware ) {
         if ( ESI->overflow.flags & PAPI_OVERFLOW_HARDWARE ){
             ESI->state |= PAPI_PAUSED;
             *isHardware = 1;
         }
         else
             *isHardware = 0;
      }
      /* Get the latest counter value */
      event_counter = ESI->overflow.event_counter;

      overflow_flag = 0;
      overflow_vector = 0;

      if (!(ESI->overflow.flags&PAPI_OVERFLOW_HARDWARE)) {
         retval = _papi_hwi_read(&thread->context, ESI, ESI->sw_stop);
         if (retval < PAPI_OK)
	   return(retval);
         for (i = 0; i < event_counter; i++) {
            papi_index = ESI->overflow.EventIndex[i];
            latest = ESI->sw_stop[papi_index];
            temp[i] = -1;

            if (latest >= (long_long)ESI->overflow.deadline[i]) {
               OVFDBG("dispatch_overflow() latest %lld, deadline %lld, threshold %d\n",
                    latest, ESI->overflow.deadline[i], ESI->overflow.threshold[i]);
               pos = ESI->EventInfoArray[papi_index].pos[0];
               overflow_vector ^= (long_long )1 << pos;
               temp[i] = latest - ESI->overflow.deadline[i];
               overflow_flag = 1;
               /* adjust the deadline */
               ESI->overflow.deadline[i] = latest + ESI->overflow.threshold[i];
            }
         }
      }
      else if ( genOverflowBit) {
         /* we had assumed the overflow event can't be derived event */
         papi_index = ESI->overflow.EventIndex[0];

         /* suppose the pos is the same as the counter number
          * (this is not true in Itanium, but itanium doesn't 
          * need us to generate the overflow bit
          */
         pos = ESI->EventInfoArray[papi_index].pos[0];
         overflow_vector = (long_long )1 << pos;
      } else 
         overflow_vector = overflow_bit;

      if ((ESI->overflow.flags&PAPI_OVERFLOW_HARDWARE) || overflow_flag) {
         ESI->overflow.count++;
         if (ESI->state & PAPI_PROFILING) {
            int k = 0;
            while (overflow_vector) {
               i = ffsll(overflow_vector) - 1;
               for (j = 0; j < event_counter; j++) {
                  papi_index = ESI->overflow.EventIndex[j];
                 /* This loop is here ONLY because Pentium 4 can have tagged *
                  * events that contain more than one counter without being  *
                  * derived. You've gotta scan all terms to make sure you    *
                  * find the one to profile. */
                  for(k = 0, pos = 0; k < MAX_COUNTER_TERMS && pos >= 0; k++) {
                     pos = ESI->EventInfoArray[papi_index].pos[k];
                     if (i == pos) {
                        profile_index = j;
                        goto foundit;
                     }
                  }
               }
               if (j == event_counter)
		 {
		   PAPIERROR("BUG! overflow_vector is 0, dropping interrupt");
		   return(PAPI_EBUG);
		 }

foundit:
               if ((ESI->overflow.flags&PAPI_OVERFLOW_HARDWARE))
                  over = 0;
               else
                  over = temp[profile_index];
               _papi_hwi_dispatch_profile(ESI, (caddr_t) papiContext, over, profile_index);
               overflow_vector ^= (long_long )1 << i;
            }
            /* do not use overflow_vector after this place */
         } else {
            ESI->overflow.handler(ESI->EventSetIndex,
                  GET_OVERFLOW_ADDRESS(ctx), overflow_vector,ctx->ucontext);
         }
      }
       ESI->state &= ~(PAPI_PAUSED);
   }
#ifdef ANY_THREAD_GETS_SIGNAL
   else {
      OVFDBG("I haven't been noticed by PAPI before\n");
      _papi_hwi_broadcast_signal((*_papi_hwi_thread_id_fn) ());
   }
#endif
   return(PAPI_OK);
}

volatile int _papi_hwi_using_signal = 0;

#ifdef _WIN32

static MMRESULT wTimerID;       // unique ID for referencing this timer
static UINT wTimerRes;          // resolution for this timer

int _papi_hwi_start_timer(int milliseconds)
{
   int retval = PAPI_OK;

   TIMECAPS tc;
   DWORD threadID;

   // get the timer resolution capability on this system
   if (timeGetDevCaps(&tc, sizeof(TIMECAPS)) != TIMERR_NOERROR)
      return (PAPI_ESYS);

   // get the ID of the current thread to read the context later
   // NOTE: Use of this code is restricted to W2000 and later...
   threadID = GetCurrentThreadId();

   // set the minimum usable resolution of the timer
   wTimerRes = min(max(tc.wPeriodMin, 1), tc.wPeriodMax);
   timeBeginPeriod(wTimerRes);

   // initialize a periodic timer
   //    triggering every (milliseconds) 
   //    and calling (_papi_hwd_timer_callback())
   //    with no data
   wTimerID = timeSetEvent(milliseconds, wTimerRes,
                          (LPTIMECALLBACK) _papi_hwd_timer_callback, threadID, TIME_PERIODIC);
   if (!wTimerID)
      return PAPI_ESYS;

   return (retval);
}

int _papi_hwi_start_signal(int signal, int need_context)
{
  return(PAPI_OK);
}

int _papi_hwi_stop_signal(int signal)
{
  return(PAPI_OK);
}

int _papi_hwi_stop_timer(void)
{
   int retval = PAPI_OK;

   if (timeKillEvent(wTimerID) != TIMERR_NOERROR)
      retval = PAPI_ESYS;
   timeEndPeriod(wTimerRes);
   return (retval);
}

#else

static struct sigaction oaction;
static struct itimerval ovalue;

int _papi_hwi_start_timer(int milliseconds)
{
   struct itimerval value;

#ifdef ANY_THREAD_GETS_SIGNAL
   _papi_hwi_lock(INTERNAL_LOCK);
   if ((_papi_hwi_using_signal-1))
     {
       INTDBG("itimer already installed\n");
       _papi_hwi_unlock(INTERNAL_LOCK);
       return(PAPI_OK);
     }
   _papi_hwi_unlock(INTERNAL_LOCK);
#endif

   value.it_interval.tv_sec = 0;
   value.it_interval.tv_usec = milliseconds * 1000;
   value.it_value.tv_sec = 0;
   value.it_value.tv_usec = milliseconds * 1000;

   INTDBG("installing itimer %d ms\n",milliseconds);
   if (setitimer(PAPI_ITIMER, &value, &ovalue) < 0)
     {
       PAPIERROR("setitimer errno %d",errno);
       return (PAPI_ESYS);
     }

   return (PAPI_OK);
}

int _papi_hwi_start_signal(int signal, int need_context)
{
   struct sigaction action;

   _papi_hwi_lock(INTERNAL_LOCK);
   _papi_hwi_using_signal++;
   if (_papi_hwi_using_signal - 1)
     {
       INTDBG("_papi_hwi_using_signal is now %d\n",_papi_hwi_using_signal);
       _papi_hwi_unlock(INTERNAL_LOCK);
       return(PAPI_OK);
     }

   memset(&action, 0x00, sizeof(struct sigaction));
   action.sa_flags = SA_RESTART;
#if defined(__ALPHA) && defined(__osf__)
   action.sa_handler = (void (*)(int)) _papi_hwd_dispatch_timer;
#elif defined(_BGL)
   action.sa_sigaction = (void (*)(int, siginfo_t *, void *)) _papi_hwd_dispatch_timer;
   if (need_context)
     action.sa_flags |= SIGPWR;
#else
   action.sa_sigaction = (void (*)(int, siginfo_t *, void *)) _papi_hwd_dispatch_timer;
   if (need_context)
     action.sa_flags |= SA_SIGINFO;
#endif

   INTDBG("installing signal handler\n");
   if (sigaction(signal, &action, &oaction) < 0)
     {
       PAPIERROR("sigaction errno %d",errno);
       _papi_hwi_unlock(INTERNAL_LOCK);
       return (PAPI_ESYS);
     }

   INTDBG("_papi_hwi_using_signal is now %d.\n",_papi_hwi_using_signal);
   _papi_hwi_unlock(INTERNAL_LOCK);

   return (PAPI_OK);
}

int _papi_hwi_stop_signal(int signal)
{
  _papi_hwi_lock(INTERNAL_LOCK);
  if (--_papi_hwi_using_signal == 0) 
    {
      INTDBG("removing signal handler\n");
      if (sigaction(signal, &oaction, NULL) == -1)
	{
	  PAPIERROR("sigaction errno %d",errno);
	  _papi_hwi_unlock(INTERNAL_LOCK);
	  return(PAPI_ESYS);
	}
    }
  
  INTDBG("_papi_hwi_using_signal is now %d\n", _papi_hwi_using_signal);
  _papi_hwi_unlock(INTERNAL_LOCK);

  return(PAPI_OK);
}

int _papi_hwi_stop_timer(void)
{
#ifdef ANY_THREAD_GETS_SIGNAL
   _papi_hwi_lock(INTERNAL_LOCK);
   if (_papi_hwi_using_signal > 1)
     {
       INTDBG("itimer in use by another thread\n");
       _papi_hwi_unlock(INTERNAL_LOCK);
       return(PAPI_OK);
     }
   _papi_hwi_unlock(INTERNAL_LOCK);
#endif

   INTDBG("turning off timer\n");
   if (setitimer(PAPI_ITIMER, &ovalue, NULL) == -1)
     {
       PAPIERROR("setitimer errno %d",errno);
       return(PAPI_ESYS);
     }

   return (PAPI_OK);
}

#endif /* _WIN32 */

/*
  Hardware independent routines to support an opaque native event table.
  These routines assume the existence of two hardware dependent routines:
    _papi_hwd_native_code_to_name()
    _papi_hwd_native_code_to_descr()
  A third routine is required to extract hardware dependent mapping info from the structure:
    _papi_hwd_native_code_to_bits()
  In addition, two more optional hardware dependent routines provide for the creation
  of new native events that may not be included in the distribution:
    _papi_hwd_encode_native()
    _papi_hwd_decode_native()
  These five routines provide the mapping from the opaque hardware dependent
  native event structure array to the higher level hardware independent interface.
*/

/* Returns PAPI_OK if native EventCode found, or PAPI_ENOEVNT if not;
   NOTE: This function uses the NON-THREAD-SAFE _papi_hwd_ntv_code_to_name call
         because it doesn't actually use the returned string pointer.
   Used to enumerate the entire array, e.g. for native_avail.c */
int _papi_hwi_query_native_event(unsigned int EventCode)
{
   char *name;

   if (EventCode & PAPI_NATIVE_MASK) {
      name = _papi_hwd_ntv_code_to_name(EventCode);
      if (name)
         return (PAPI_OK);
   }
   return (PAPI_ENOEVNT);
}

/* Converts an ASCII name into a native event code usable by other routines
   Returns code = 0 and PAPI_OK if name not found.
   This allows for sparse native event arrays */
int _papi_hwi_native_name_to_code(char *in, int *out)
{
   char *name;
   unsigned int i = 0 | PAPI_NATIVE_MASK;
   int retval = PAPI_ENOEVNT;
/* Cray X1 doesn't loop on 0, so a code_to_name on this will fail, the
 * first call to enum_events with a 0 will give a valid code
 */
#if defined(__crayx1)
 _papi_hwd_ntv_enum_events(&i, 0);
#endif
    _papi_hwi_lock(INTERNAL_LOCK);
   do {
      name = _papi_hwd_ntv_code_to_name(i);
/*      printf("name =|%s|\ninput=|%s|\n", name, in); */
      if (name != NULL) {
         if (strcasecmp(name, in) == 0) {
            *out = i;
            retval = PAPI_OK;
         }
     } else {
         *out = 0;
         retval = PAPI_OK;
      }
   } while ((_papi_hwd_ntv_enum_events(&i, 0) == PAPI_OK) && (retval == PAPI_ENOEVNT)) ;
   _papi_hwi_unlock(INTERNAL_LOCK);
   return (retval);
}


/* Returns event name based on native event code. 
   Returns NULL if name not found */
int _papi_hwi_native_code_to_name(unsigned int EventCode, char *hwi_name, int len)
{
   char *name;
   int retval = PAPI_ENOEVNT;
   if (EventCode & PAPI_NATIVE_MASK) {
      _papi_hwi_lock(INTERNAL_LOCK);
      name = _papi_hwd_ntv_code_to_name(EventCode);
      if (name) {
         strncpy(hwi_name, name, len);
         retval = PAPI_OK;
      } else *hwi_name = 0;
      _papi_hwi_unlock(INTERNAL_LOCK);
   }
   return (retval);
}


/* Returns event description based on native event code.
   Returns NULL if description not found */
int _papi_hwi_native_code_to_descr(unsigned int EventCode, char *hwi_descr, int len)
{
   char *descr;
   int retval = PAPI_ENOEVNT;
   if (EventCode & PAPI_NATIVE_MASK) {
      _papi_hwi_lock(INTERNAL_LOCK);
      descr = _papi_hwd_ntv_code_to_descr(EventCode);
      if (descr) {
         strncpy(hwi_descr, descr, len);
         retval = PAPI_OK;
      } else *hwi_descr = 0;
      _papi_hwi_unlock(INTERNAL_LOCK);
   }
   return (retval);
}


/* The native event equivalent of PAPI_get_event_info */
int _papi_hwi_get_native_event_info(unsigned int EventCode, PAPI_event_info_t * info)
{
   hwd_register_t bits;
   int retval;

   if (EventCode & PAPI_NATIVE_MASK) {
      _papi_hwi_lock(INTERNAL_LOCK);
      strncpy(info->symbol, _papi_hwd_ntv_code_to_name(EventCode), PAPI_MAX_STR_LEN);
      _papi_hwi_unlock(INTERNAL_LOCK);
      if (strlen(info->symbol)) {
         /* Fill in the info structure */
         info->event_code = EventCode;
         _papi_hwi_lock(INTERNAL_LOCK);
         strncpy(info->long_descr, _papi_hwd_ntv_code_to_descr(EventCode),
                 PAPI_HUGE_STR_LEN);
         _papi_hwi_unlock(INTERNAL_LOCK);
         info->short_descr[0] = '\0';
         info->derived[0] = '\0';
         info->postfix[0] = '\0';

         /* Convert the register bits structure for this EventCode into
            arrays of names and values (substrate dependent).
         */
         retval = _papi_hwd_ntv_code_to_bits(EventCode, &bits);
         if (retval == PAPI_OK)
	   retval = _papi_hwd_ntv_bits_to_info(&bits, (char *)info->name, info->code, PAPI_MAX_STR_LEN, PAPI_MAX_INFO_TERMS);
         if (retval < 0) 
	   info->count = 0;
         else 
	   info->count = retval;
         return (PAPI_OK);
      }
   }
   return (PAPI_ENOEVNT);
}

#if !defined(HAVE_FFSLL)
/* find the first set bit in long_long */

int ffsll(long_long lli)
{
   int i, num, t, tmpint, len;

   num = sizeof(long_long)/sizeof(int);
   if(num == 1) return(ffs((int)lli));
   len = sizeof(int)*CHAR_BIT;

   for(i=0; i< num; i++ ) {
      tmpint = (int)( ( (lli>>len)<<len) ^ lli );

      t=ffs(tmpint);
      if ( t ) {
         return(t+i*len);
      }
      lli = lli>>len;
   }
   return PAPI_OK;
}
#endif


/**********************************************************************
	Windows Compatability stuff
	Delimited by the _WIN32 define
**********************************************************************/
#ifdef _WIN32

/*
 This routine normally lives in <strings> on Unix.
 Microsoft Visual C++ doesn't have this file.
*/
extern int ffs(int i)
{
   int c = 1;

   do {
      if (i & 1)
         return (c);
      i = i >> 1;
      c++;
   } while (i);
   return (0);
}

/*
 More Unix routines that I can't find in Windows
 This one returns a pseudo-random integer
 given an unsigned int seed.
*/
extern int rand_r(unsigned int *Seed)
{
   srand(*Seed);
   return (rand());
}

/*
  Another Unix routine that doesn't exist in Windows.
  Kevin uses it in the memory stuff, specifically in PAPI_get_dmem_info().
*/
extern int getpagesize(void)
{
   SYSTEM_INFO SystemInfo;      // system information structure  

   GetSystemInfo(&SystemInfo);
   return ((int) SystemInfo.dwPageSize);
}

#endif                          /* _WIN32 */
