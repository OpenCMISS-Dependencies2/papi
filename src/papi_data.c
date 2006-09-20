/****************************/
/* THIS IS OPEN SOURCE CODE */
/****************************/

/* 
* File:    papi_data.c
* CVS:     $Id$
* Author:  Philip Mucci
*          mucci@cs.utk.edu
* Mods:    dan terpstra
*          terpstra@cs.utk.edu
* Mods:    Haihang You
*	       you@cs.utk.edu
* Mods:    Min Zhou
*          min@cs.utk.edu
* Mods:    Kevin London
*	   london@cs.utk.edu
* Mods:    Per Ekman
*          pek@pdc.kth.se
* Mods:    <your name here>
*          <your email address>
*/

#include "papi.h"
#include "papi_internal.h"

/********************/
/*  BEGIN GLOBALS   */
/********************/

#include "papi_data.h"

EventSetInfo_t *default_master_eventset = NULL;
int init_retval = DEADBEEF;
int init_level = PAPI_NOT_INITED;
#ifdef DEBUG
int _papi_hwi_debug = 0;
#endif

/* Machine dependent info structure */
papi_mdi_t _papi_hwi_system_info;

unsigned int _papi_hwi_preset_count[PAPI_MAX_PRESET_EVENTS] = {0};
hwi_preset_data_t *_papi_hwi_preset_data[PAPI_MAX_PRESET_EVENTS] = {NULL};
char *_papi_hwi_dev_notes[PAPI_MAX_PRESET_EVENTS] = {0};
hwi_presets_t _papi_hwi_presets = {
   _papi_hwi_preset_count,
   _papi_hwi_preset_info,
   _papi_hwi_preset_data,
   _papi_hwi_dev_notes
};


/* table matching derived types to derived strings.
   used by get_info, encode_event, xml translator
*/
const hwi_describe_t _papi_hwi_derived[] = {
   {NOT_DERIVED,     "NOT_DERIVED",    "Do nothing"},
   {DERIVED_ADD,     "DERIVED_ADD",    "Add counters"},
   {DERIVED_PS,      "DERIVED_PS",     "Divide by the cycle counter and convert to seconds"},
   {DERIVED_ADD_PS,  "DERIVED_ADD_PS", "Add 2 counters then divide by the cycle counter and xl8 to secs."},
   {DERIVED_CMPD,    "DERIVED_CMPD",   "Event lives in first counter but takes 2 or more codes"},
   {DERIVED_SUB,     "DERIVED_SUB",    "Sub all counters from first counter"},
   {DERIVED_POSTFIX, "DERIVED_POSTFIX", "Process counters based on specified postfix string"},
   {-1, NULL, NULL}
};

/* _papi_hwi_derived_type:
   Helper routine to extract a derived type from a derived string
   returns type value if found, otherwise returns -1
*/
int _papi_hwi_derived_type(char *tmp, int *code) 
{
  int i = 0;
  while (_papi_hwi_derived[i].name != NULL)
    {
      if (strcasecmp(tmp,_papi_hwi_derived[i].name) == 0)
	{
	  *code = _papi_hwi_derived[i].value;
	  return(PAPI_OK);
	}
      i++;
    }
  INTDBG("Invalid derived string %s\n",tmp);
  return(PAPI_EINVAL);
}

/* _papi_hwi_derived_string:
   Helper routine to extract a derived string from a derived type
   copies derived type string into derived if found,
   otherwise returns PAPI_EINVAL
*/
int _papi_hwi_derived_string(int type, char *derived, int len) {
   int j;

   for(j = 0; _papi_hwi_derived[j].value != -1; j++) {
      if (_papi_hwi_derived[j].value == type) {
         strncpy(derived, _papi_hwi_derived[j].name, len);
         return(PAPI_OK);
      }
   }
   INTDBG("Invalid derived type %d\n",type);
   return(PAPI_EINVAL);
}

/********************/
/*    END GLOBALS   */
/********************/
