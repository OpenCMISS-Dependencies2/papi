/* 
* File:    zero_omp.c
* CVS:     $Id$
* Author:  Philip Mucci
*          mucci@cs.utk.edu
* Mods:    Nils Smeds
*          smeds@pdc.kth.se
*          Anders Nilsson
*          anni@pdc.kth.se
*/  

/* This file performs the following test: start, stop and timer
functionality for 2 slave OMP threads

   - It attempts to use the following two counters. It may use less
depending on hardware counter resource limitations. These are counted
in the default counting domain and default granularity, depending on
the platform. Usually this is the user domain (PAPI_DOM_USER) and
thread context (PAPI_GRN_THR).

     + PAPI_FP_INS
     + PAPI_TOT_CYC

Each thread inside the Thread routine:
   - Get cyc.
   - Get us.
   - Start counters
   - Do flops
   - Stop and read counters
   - Get us.
   - Get cyc.

Master serial thread:
   - Get us.
   - Get cyc.
   - Run parallel for loop
   - Get us.
   - Get cyc.
*/

#include "papi_test.h"

#ifdef _OPENMP
#include <omp.h>
#else
#error "This compiler does not understand OPENMP"
#endif

extern int TESTS_QUIET; /* Declared in test_utils.c */

void Thread(int n)
{
  int retval, num_tests = 1;
  int EventSet1;
  int PAPI_event, mask1;
  int num_events1;
  long_long **values;
  long_long elapsed_us, elapsed_cyc;
  char event_name[PAPI_MAX_STR_LEN];

  if ( !TESTS_QUIET )
     printf("Thread 0x%x\n",omp_get_thread_num());
  else
     num_events1 = (int) omp_get_thread_num();

  /* query and set up the right instruction to monitor */
  if (PAPI_query_event(PAPI_FP_INS) == PAPI_OK) {
	  PAPI_event = PAPI_FP_INS;
	  mask1 = MASK_FP_INS | MASK_TOT_CYC;
  }
  else {
	  PAPI_event = PAPI_TOT_INS;
	  mask1 = MASK_TOT_INS | MASK_TOT_CYC;
  }

  retval = PAPI_event_code_to_name(PAPI_event, event_name);
  if (retval != PAPI_OK) test_fail(__FILE__, __LINE__, "PAPI_event_code_to_name", retval);

  EventSet1 = add_test_events(&num_events1,&mask1);

  /* num_events1 is greater than num_events2 so don't worry. */

  values = allocate_test_space(num_tests, num_events1);

  elapsed_us = PAPI_get_real_usec();

  elapsed_cyc = PAPI_get_real_cyc();

  retval = PAPI_start(EventSet1);
  if (retval != PAPI_OK) test_fail(__FILE__, __LINE__, "PAPI_start", retval);

  do_flops(n);
  
  retval = PAPI_stop(EventSet1, values[0]);
  if (retval != PAPI_OK) test_fail(__FILE__, __LINE__, "PAPI_stop", retval);

  elapsed_us = PAPI_get_real_usec() - elapsed_us;

  elapsed_cyc = PAPI_get_real_cyc() - elapsed_cyc;

  remove_test_events(&EventSet1, mask1);

  if ( !TESTS_QUIET ) {
    printf("Thread 0x%x %-12s : \t%lld\n", omp_get_thread_num(), event_name,
	 (values[0])[0]);
    printf("Thread 0x%x PAPI_TOT_CYC: \t%lld\n",omp_get_thread_num(),
	 (values[0])[1]);
    printf("Thread 0x%x Real usec   : \t%lld\n",omp_get_thread_num(),
	 elapsed_us);
    printf("Thread 0x%x Real cycles : \t%lld\n",omp_get_thread_num(),
	 elapsed_cyc);
  }

  /* It is illegal for the threads to exit in OpenMP */
  /* test_pass(__FILE__,0,0); */
  free_test_space(values, num_tests);
}

int main(int argc, char **argv) 
{
  int maxthr, retval;
  long_long elapsed_us, elapsed_cyc;

  tests_quiet(argc, argv); /* Set TESTS_QUIET variable */

  retval = PAPI_library_init(PAPI_VER_CURRENT);
  if ( retval != PAPI_VER_CURRENT)  test_fail(__FILE__, __LINE__, "PAPI_library_init", retval);

  if ( !TESTS_QUIET ) {
	retval = PAPI_set_debug(PAPI_VERB_ECONT);
	if (retval != PAPI_OK) test_fail(__FILE__, __LINE__, "PAPI_set_debug", retval);
  }


  elapsed_us = PAPI_get_real_usec();

  elapsed_cyc = PAPI_get_real_cyc();


  retval = PAPI_thread_init((unsigned long (*)(void))(omp_get_thread_num),0);
  if (retval != PAPI_OK) 
     if (retval == PAPI_ESBSTR)
	test_skip(__FILE__, __LINE__, "PAPI_thread_init", retval);
     else
	test_fail(__FILE__, __LINE__, "PAPI_thread_init", retval);

#pragma omp parallel private(maxthr,retval)
{
  maxthr = omp_get_num_threads();
  Thread(1000000*(omp_get_thread_num()+1));
}

  elapsed_cyc = PAPI_get_real_cyc() - elapsed_cyc;

  elapsed_us = PAPI_get_real_usec() - elapsed_us;

  if ( !TESTS_QUIET ) { 
    printf("Master real usec   : \t%lld\n",
	 elapsed_us);
    printf("Master real cycles : \t%lld\n",
	 elapsed_cyc);
  }

  test_pass(__FILE__,NULL,0);
  exit(0);
}
