/* 
* File:    multiplex.c
* CVS:     $Id$
* Author:  Philip Mucci
*          mucci@cs.utk.edu
* Mods:    <your name here>
*          <your email address>
*/

/* This file tests the multiplex functionality, originally developed by 
   John May of LLNL. */

#include "papi_test.h"

void init_papi(void)
{
   int retval;

   /* Initialize the library */

   retval = PAPI_library_init(PAPI_VER_CURRENT);
   if (retval != PAPI_VER_CURRENT)
      test_fail(__FILE__, __LINE__, "PAPI_library_init", retval);
}

/* Tests that we can really multiplex a lot. */

int case1(void)
{
   int retval, i, EventSet = PAPI_NULL, j = 0, allvalid = 1;
   long long *values;
   PAPI_event_info_t pset;
   
   init_papi();

   retval = PAPI_multiplex_init();
   if (retval != PAPI_OK)
      test_fail(__FILE__, __LINE__, "PAPI_multiplex_init", retval);

   retval = PAPI_create_eventset(&EventSet);
   if (retval != PAPI_OK)
      test_fail(__FILE__, __LINE__, "PAPI_create_eventset", retval);

   retval = PAPI_set_multiplex(EventSet);
   if (retval != PAPI_OK)
      test_fail(__FILE__, __LINE__, "PAPI_set_multiplex", retval);

    /* Fill up the event set with as many non-derived events as we can */

    i = PAPI_PRESET_MASK;
    do {
        if (PAPI_get_event_info(i, &pset) == PAPI_OK) 
	  {
	    if (pset.count && (strcmp(pset.derived,"NOT_DERIVED") == 0))
	      {
		retval = PAPI_add_event(EventSet, pset.event_code);
		if (retval != PAPI_OK)
		  test_fail(__FILE__, __LINE__, "PAPI_add_event", retval);
		else
		  {
		    printf("Added %s\n", pset.symbol);
		    j++;
		  }
	      }
	  }
    } while ((PAPI_enum_event(&i, PAPI_PRESET_ENUM_AVAIL) == PAPI_OK) && (j <= MAX_TO_ADD));

   values = (long long *) malloc(j * sizeof(long long));
   if (values == NULL)
      test_fail(__FILE__, __LINE__, "malloc", 0);

   if (PAPI_start(EventSet) != PAPI_OK)
      test_fail(__FILE__, __LINE__, "PAPI_start", retval);

   do_both(NUM_ITERS);
   do_misses(10, 1024*1024*4);

   retval = PAPI_stop(EventSet, values);
   if (retval != PAPI_OK)
      test_fail(__FILE__, __LINE__, "PAPI_stop", retval);

   test_print_event_header("multiplex2:\n", EventSet);
   for (i = 0; i < j; i++) {
     printf(ONENUM, values[i]);
     if (values[i] == 0)
       allvalid = 0;
   }
   printf("\n");
   if (!allvalid){
      if (!TESTS_QUIET ){
        printf("Warning:  one or more counter[s] registered no counts\n");
      /*test_fail(__FILE__, __LINE__, "one or more counter registered no counts",1);*/
      }
   }

   retval = PAPI_cleanup_eventset(EventSet);    /* JT */
   if (retval != PAPI_OK)
      test_fail(__FILE__, __LINE__, "PAPI_cleanup_eventset", retval);

   retval = PAPI_destroy_eventset(&EventSet);
   if (retval != PAPI_OK)
      test_fail(__FILE__, __LINE__, "PAPI_destroy_eventset", retval);

   return (SUCCESS);
}

int main(int argc, char **argv)
{

   tests_quiet(argc, argv);     /* Set TESTS_QUIET variable */

   printf("%s: Does PAPI_multiplex_init() handle lots of events?\n",argv[0]);
   printf("%s: Using %d iterations\n\n", argv[0], NUM_ITERS);

   case1();
   test_pass(__FILE__, NULL, 0);
   exit(1);
}
