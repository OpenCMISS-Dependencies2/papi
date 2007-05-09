#include "papi_test.h"
#include <stdio.h>
#include <stdlib.h>

int EventSet=PAPI_NULL;
int retval;

void papi_init(int argc, char **argv)
{
   const PAPI_hw_info_t *hwinfo = NULL;
   
   tests_quiet(argc, argv);     /* Set TESTS_QUIET variable */
   /*for(i=0;i<argc;i++) */

   retval = PAPI_library_init(PAPI_VER_CURRENT);
   if (retval != PAPI_VER_CURRENT)
      test_fail(__FILE__, __LINE__, "PAPI_library_init", retval);

   if (!TESTS_QUIET) {
      retval = PAPI_set_debug(PAPI_VERB_ECONT);
      if (retval != PAPI_OK)
         test_fail(__FILE__, __LINE__, "PAPI_set_debug", retval);
   }

   if ((hwinfo = PAPI_get_hardware_info()) == NULL)
      test_fail(__FILE__, __LINE__, "PAPI_get_hardware_info", 2);

   if (!TESTS_QUIET) {
      printf
          ("Test case event_chooser: Available events which can be added with given events.\n");
      printf
          ("-------------------------------------------------------------------------\n");
      printf("Vendor string and code   : %s (%d)\n", hwinfo->vendor_string,
             hwinfo->vendor);
      printf("Model string and code    : %s (%d)\n", hwinfo->model_string, hwinfo->model);
      printf("CPU Revision             : %f\n", hwinfo->revision);
      printf("CPU Megahertz            : %f\n", hwinfo->mhz);
      printf("CPU Clock Megahertz      : %d\n", hwinfo->clock_mhz);
      printf("CPU's in this Node       : %d\n", hwinfo->ncpu);
      printf("Nodes in this System     : %d\n", hwinfo->nnodes);
      printf("Total CPU's              : %d\n", hwinfo->totalcpus);
      printf("Number Hardware Counters : %d\n", PAPI_get_opt(PAPI_MAX_HWCTRS, NULL));
      printf("Max Multiplex Counters   : %d\n", PAPI_get_opt(PAPI_MAX_MPX_CTRS, NULL));
      printf
          ("-------------------------------------------------------------------------\n");

   }

  retval=PAPI_create_eventset(&EventSet);
  if(retval != PAPI_OK){
    fprintf(stderr, "PAPI_create_eventset error\n");
    exit(1);
  }
	
}

int native()
{
   int i, j, k, evt;
   int retval;
   PAPI_event_info_t info;
#ifdef _POWER4
   int group = 0;
#endif
#ifdef PENTIUM4
   int l;
#endif

   i = 0 | PAPI_NATIVE_MASK;
   j = 0;
#ifdef __crayx1
   PAPI_enum_event(&i, 0);
#endif
   do {
    evt=i;
#ifdef _POWER4
      evt=i & 0xFF00FFFF;
#endif
    retval=PAPI_add_event(EventSet,evt);
    if(retval == PAPI_OK){
#ifdef _POWER4
      group = (i & 0x00FF0000) >> 16;
      if (group) {
         if (!TESTS_QUIET)
            printf("%10d", group - 1);
      } else {
         if (!TESTS_QUIET)
            printf("\n\n");
#endif
         j++;
         retval = PAPI_get_event_info(i, &info);

	 printf("%s\t0x%x\n |%s|\n",
		info.symbol,
		info.event_code,
		info.long_descr);

   for (k=0;k<(int)info.count;k++)
      printf(" |Register Value[%d]: 0x%-10x  %s|\n",k,info.code[k], info.name[k]);
   printf("\n");

#ifdef _POWER4
         if (!TESTS_QUIET)
            printf("Groups: ");
      }
#endif
#ifdef PENTIUM4
      k = i;
      if (PAPI_enum_event(&k, PAPI_PENT4_ENUM_BITS) == PAPI_OK) {
         l = strlen(info.long_descr);
         do {
            j++;
            retval = PAPI_get_event_info(k, &info);
            if (!TESTS_QUIET && retval == PAPI_OK) {
               printf("    %-26s 0x%-10x    %s\n",
                      info.symbol, info.event_code, info.long_descr + l);
            }
         } while (PAPI_enum_event(&k, PAPI_PENT4_ENUM_BITS) == PAPI_OK);
      }
      if (!TESTS_QUIET && retval == PAPI_OK)
         printf("\n");
   if((retval=PAPI_remove_event(EventSet,evt))!=PAPI_OK)
       printf("Error in PAPI_remove_event\n");
   }
   } while (PAPI_enum_event(&i, PAPI_PENT4_ENUM_GROUPS) == PAPI_OK);
#elif defined(_POWER4)
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
   if((retval=PAPI_remove_event(EventSet,evt))!=PAPI_OK)
       printf("Error in PAPI_remove_event\n");
   }
   } while (PAPI_enum_event(&i, PAPI_PWR4_ENUM_GROUPS) == PAPI_OK);
#else
   if((retval=PAPI_remove_event(EventSet,evt))!=PAPI_OK)
       printf("Error in PAPI_remove_event\n");
   }
   } while (PAPI_enum_event(&i, PAPI_ENUM_ALL) == PAPI_OK);
#endif

   if (!TESTS_QUIET) {
      printf
          ("-------------------------------------------------------------------------\n");
      printf("Total events reported: %d\n", j);
   }
   test_pass(__FILE__, NULL, 0);
   exit(1);
}

int preset()
{
   int i,j=0;
   int retval;
   int print_avail_only = 1;
   int print_tabular = 1;
   PAPI_event_info_t info;


         i = PAPI_PRESET_MASK;
         if (print_tabular) {
            if (print_avail_only) {
               printf("Name\t\tDerived\tDescription (Mgr. Note)\n");
            } else {
               printf("Name\t\tCode\t\tAvail\tDeriv\tDescription (Note)\n");
            }
         }
         else {
            printf("The following correspond to fields in the PAPI_event_info_t structure.\n");
            printf("Symbol\tEvent Code\tCount\n |Short Description|\n |Long Description|\n |Developer's Notes|\n Derived|\n |PostFix|\n");
         }
         do {
           retval=PAPI_add_event(EventSet,i);
           if(retval == PAPI_OK){
             if (PAPI_get_event_info(i, &info) == PAPI_OK) {
               if (print_tabular) {
                  if (print_avail_only) {
		               printf("%s\t%s\t%s (%s)\n",
			               info.symbol,
			               (info.count > 1 ? "Yes" : "No"),
			               info.long_descr, (info.note ? info.note : ""));
                  } else {
		               printf("%s\t0x%x\t%s\t%s\t%s (%s)\n",
		                     info.symbol,
		                     info.event_code,
		                     (info.count ? "Yes" : "No"),
		                     (info.count > 1 ? "Yes" : "No"),
		                     info.long_descr, (info.note ? info.note : ""));
                  }
               } else {
	               printf("%s\t0x%x\t%d\n |%s|\n |%s|\n |%s|\n |%s|\n |%s|\n",
		               info.symbol,
		               info.event_code,
		               info.count,
		               info.short_descr,
		               info.long_descr,
		               info.note,
                     info.derived,
                     info.postfix);
                  for (j=0;j<(int)info.count;j++) printf(" |Native Code[%d]: 0x%x  %s|\n",j,info.code[j], info.name[j]);
               }
	        }   
	        if((retval=PAPI_remove_event(EventSet,i))!=PAPI_OK)
              printf("Error in PAPI_remove_event\n");
            j++;
          }

         } while (PAPI_enum_event(&i, print_avail_only) == PAPI_OK);
      
   if (!TESTS_QUIET) {
      printf
          ("-------------------------------------------------------------------------\n");
      printf("Total events reported: %d\n", j);
   }
   test_pass(__FILE__, NULL, 0);
   exit(1);
}

int main(int argc, char **argv)
{
  int i;
  int pevent;

  if(argc<3){
    fprintf(stderr, "Usage: eventChooser NATIVE|PRESET evt1 evet2 ... \n");
    exit(1);
  }
  papi_init(argc, argv);

  for(i=2; i<argc; i++){
    PAPI_event_name_to_code(argv[i], &pevent);
    retval=PAPI_add_event(EventSet,pevent);
    if(retval != PAPI_OK){
      fprintf(stderr, "Event %s can't be counted with others\n", argv[i]);
      exit(1);
    }
  }

  if(!strcmp("NATIVE", argv[1]))
    native();
  else if(!strcmp("PRESET", argv[1]))
    preset();
  else{
    fprintf(stderr, "Usage: eventChooser NATIVE|PRESET evt1 evet2 ... \n");
    exit(1);
  }
  exit(0);
}
