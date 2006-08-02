/* This file checks to make sure the locking mechanisms work correctly on the platform.
 * Platforms where the locking mechanisms are not implemented or are incorrectly implemented
 * will fail.  -KSL
 */

#include <pthread.h>
#include "papi_test.h"

extern int TESTS_QUIET;         /* Declared in test_utils.c */


#define LOOPS  		100000
#define SLEEP_VALUE	20000

int count;
int rank;

void *Master(void *arg)
{
   int i;
   usleep(SLEEP_VALUE);
   PAPI_lock(PAPI_USR1_LOCK);
   /* Make sure Slaves are not sleeping */
   for (i = 0; i < LOOPS; i++) {
      count = 2 * count - i;
   }
   PAPI_unlock(PAPI_USR1_LOCK);
   pthread_exit(NULL);
}

void *Slave(void *arg)
{
   int i;

   PAPI_lock(PAPI_USR2_LOCK);
   PAPI_lock(PAPI_USR1_LOCK);
   for (i = 0; i < LOOPS; i++) {
      count += i;
   }
   PAPI_unlock(PAPI_USR1_LOCK);
   PAPI_unlock(PAPI_USR2_LOCK);
   pthread_exit(NULL);
}



int main(int argc, char **argv)
{
   pthread_t master;
   pthread_t slave1;
   int result_m, result_s, rc, i;
   int retval;

#if defined(__ALPHA) && defined(__osf__)
   test_skip(__FILE__, __LINE__, "thread support not available on this platform!", PAPI_ESBSTR);
#endif
   /* Setup a random number so compilers can't optimize it out */
   count = rand();
   result_m = count;
   rank = 0;

   tests_quiet(argc, argv);     /* Set TESTS_QUIET variable */

   for (i = 0; i < LOOPS; i++) {
      result_m = 2 * result_m - i;
   }
   result_s = result_m;

   for (i = 0; i < LOOPS; i++) {
      result_s += i;
   }

   if ((retval = PAPI_library_init(PAPI_VER_CURRENT)) != PAPI_VER_CURRENT)
      test_fail(__FILE__, __LINE__, "PAPI_library_init", retval);

   retval = PAPI_thread_init((unsigned long (*)(void)) (pthread_self));
   if (retval != PAPI_OK) {
      if (retval == PAPI_ESBSTR)
         test_skip(__FILE__, __LINE__, "PAPI_thread_init", retval);
      else
         test_fail(__FILE__, __LINE__, "PAPI_thread_init", retval);
   }

   PAPI_lock(PAPI_USR2_LOCK);
   rc = pthread_create(&master, NULL, Master, NULL);
   if (rc) {
      retval = PAPI_ESYS;
      test_fail(__FILE__, __LINE__, "pthread_create", retval);
   }
   rc = pthread_create(&slave1, NULL, Slave, NULL);
   if (rc) {
      retval = PAPI_ESYS;
      test_fail(__FILE__, __LINE__, "pthread_create", retval);
   }
   pthread_join(master, NULL);
   if (!TESTS_QUIET)
      printf("Master: Expected: %d  Received: %d\n", result_m, count);
   if (result_m != count)
      test_fail(__FILE__, __LINE__, "Thread Locks", 1);
   PAPI_unlock(PAPI_USR2_LOCK);
   pthread_join(slave1, NULL);
   if (!TESTS_QUIET)
      printf("Slave: Expected: %d  Received: %d\n", result_s, count);
   if (result_s != count)
      test_fail(__FILE__, __LINE__, "Thread Locks", 1);

   test_pass(__FILE__, NULL, 0);
   exit(1);
}
