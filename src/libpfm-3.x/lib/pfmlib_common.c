/*
 * pfmlib_common.c: set of functions common to all PMU models
 *
 * Copyright (C) 2001-2003 Hewlett-Packard Co
 * Contributed by Stephane Eranian <eranian@hpl.hp.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * This file is part of libpfm, a performance monitoring support library for
 * applications on Linux/ia64.
*/

#include <sys/types.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

#include <perfmon/pfmlib.h>

#include "pfmlib_priv.h"

extern pfm_pmu_support_t itanium2_support;
extern pfm_pmu_support_t itanium_support;
extern pfm_pmu_support_t generic_ia64_support;

static pfm_pmu_support_t *supported_pmus[]=
{
#ifdef CONFIG_PFMLIB_ITANIUM2
	&itanium2_support,
#endif
#ifdef CONFIG_PFMLIB_ITANIUM
	&itanium_support,
#endif

#ifdef CONFIG_PFMLIB_GENERIC_IA64
	&generic_ia64_support,	/* must always be last (matches any IA-64 PMU) */
#endif
	NULL
};

/*
 * contains runtime configuration options for the library.
 * mostly for debug purposes.
 */
pfm_config_t pfm_config;

int
pfm_initialize(void)
{
	pfm_pmu_support_t **p = supported_pmus;
	while (*p) {
		if ((*p)->pmu_detect() == PFMLIB_SUCCESS) goto found;
		p++;
	}
	return PFMLIB_ERR_NOTSUPP;
found:
	pfm_current = *p;
	return PFMLIB_SUCCESS;
}

int
pfm_set_options(pfmlib_options_t *opt)
{
	if (opt == NULL) return PFMLIB_ERR_INVAL;

	pfm_config.options = *opt;

	return PFMLIB_SUCCESS;
}

/*
 * return the name corresponding to the pmu type. Only names
 * of PMU actually compiled in the library will be returned.
 */
int
pfm_get_pmu_name_bytype(int type, char *name, int maxlen)
{
	pfm_pmu_support_t **p = supported_pmus;

	if (name == NULL || maxlen < 1) return PFMLIB_ERR_INVAL;

	while (*p) {
		if ((*p)->pmu_type == type) goto found;
		p++;
	}
	return PFMLIB_ERR_INVAL;
found:
	strncpy(name, (*p)->pmu_name, maxlen-1);

	/* make sure the string is null terminated */
	name[maxlen-1] = '\0';

	return PFMLIB_SUCCESS;
}

int
pfm_list_supported_pmus(int (*pf)(const char *fmt,...))
{
	pfm_pmu_support_t **p;

	if (pf == NULL) return PFMLIB_ERR_INVAL;

	(*pf)("supported PMU models: ");

	for (p = supported_pmus; *p; p++) {
		(*pf)("[%s] ", (*p)->pmu_name);;
	}

	(*pf)("\ndetected host PMU: %s\n", pfm_current ? pfm_current->pmu_name : "not detected yet");

	return PFMLIB_SUCCESS;
}

int
pfm_get_pmu_name(char *name, int maxlen)
{
	if (PFMLIB_INITIALIZED() == 0) return PFMLIB_ERR_NOINIT;

	if (name == NULL || maxlen < 1) return PFMLIB_ERR_INVAL;

	strncpy(name, pfm_current->pmu_name, maxlen-1);

	name[maxlen-1] = '\0';

	return PFMLIB_SUCCESS;
}

int
pfm_get_pmu_type(int *type)
{
	if (PFMLIB_INITIALIZED() == 0) return PFMLIB_ERR_NOINIT;

	if (type == NULL) return PFMLIB_ERR_INVAL;

	*type = pfm_current->pmu_type;

	return PFMLIB_SUCCESS;
}

/*
 * boolean return value
 */
int
pfm_is_pmu_supported(int type)
{
	pfm_pmu_support_t **p = supported_pmus;

	if (PFMLIB_INITIALIZED() == 0) return PFMLIB_ERR_NOINIT;

	while (*p) {
		if ((*p)->pmu_type == type) return PFMLIB_SUCCESS;
		p++;
	}
	return PFMLIB_ERR_NOTSUPP;
}

int
pfm_force_pmu(int type)
{
	pfm_pmu_support_t **p = supported_pmus;

	while (*p) {
		if ((*p)->pmu_type == type) goto found;
		p++;
	}
	return PFMLIB_ERR_NOTSUPP;
found:
	/* verify that this is valid */
	if ((*p)->pmu_detect() != PFMLIB_SUCCESS) return PFMLIB_ERR_NOTSUPP;

	pfm_current = *p;

	return PFMLIB_SUCCESS;
}

static int
pfm_gen_event_code(const char *str, unsigned long *code)
{
	long ret;
	char *endptr = NULL;

	if (str == NULL || code == NULL) return PFMLIB_ERR_INVAL;

	ret = strtoul(str,&endptr, 0);

	/* check for errors */
	if (*endptr!='\0') return PFMLIB_ERR_INVAL;

	*code = ret;

	return PFMLIB_SUCCESS;
}

int
pfm_find_event_byname(const char *n, unsigned int *idx)
{
	 unsigned int i;

	if (PFMLIB_INITIALIZED() == 0) return PFMLIB_ERR_NOINIT;

	if (n == NULL || idx == NULL) return PFMLIB_ERR_INVAL;

	/* we do case insensitive comparisons */
	for(i=0; i < pfm_current->pme_count; i++) {
		if (!strcasecmp(pfm_current->get_event_name(i), n)) goto found;
	}
	return PFMLIB_ERR_NOTFOUND;
found:
	*idx = i;
	return PFMLIB_SUCCESS;
}

static int
pfm_find_event_byvcode(unsigned long vcode, unsigned int *idx)
{
	unsigned int i;

	if (PFMLIB_INITIALIZED() == 0) return PFMLIB_ERR_NOINIT;

	if (idx == NULL) return PFMLIB_ERR_INVAL;

	for(i=0; i < pfm_current->pme_count; i++) {
		if (pfm_current->get_event_vcode(i) == vcode) goto found;
	}
	return PFMLIB_ERR_NOTFOUND;
found:
	*idx = i;
	return PFMLIB_SUCCESS;
}

int
pfm_find_event_bycode(int code, unsigned int *idx)
{
	unsigned int i;

	if (PFMLIB_INITIALIZED() == 0) return PFMLIB_ERR_NOINIT;

	if (idx == NULL) return PFMLIB_ERR_INVAL;

	for(i=0; i < pfm_current->pme_count; i++) {
		if (pfm_current->get_event_code(i) == code) goto found;
	}
	return PFMLIB_ERR_NOTFOUND;
found:
	*idx = i;
	return PFMLIB_SUCCESS;
}

int
pfm_find_event(const char *v, unsigned int *ev)
{
	unsigned long number;
	int ret;

	if (PFMLIB_INITIALIZED() == 0) return PFMLIB_ERR_NOINIT;

	if (v == NULL || ev == NULL) return PFMLIB_ERR_INVAL;

	if (isdigit((int)*v)) {
		ret = pfm_gen_event_code(v, &number);
		if (ret != PFMLIB_SUCCESS) return ret;

		if (number <= INT_MAX) {
			int the_int_number = (int)number;

			ret = pfm_find_event_bycode(the_int_number, ev);
			if (ret == PFMLIB_SUCCESS) return ret;
		}
		/* try the vcode now */
		ret  = pfm_find_event_byvcode(number, ev);
	} else {
		ret = pfm_find_event_byname(v, ev);
	}
	return ret;
}

int
pfm_find_event_bycode_next(int code, unsigned int i, unsigned int *next)
{
	if (PFMLIB_INITIALIZED() == 0) return PFMLIB_ERR_NOINIT;

	if (next == NULL) return PFMLIB_ERR_INVAL;

	for(++i; i < pfm_current->pme_count; i++) {
		if (pfm_current->get_event_code(i) == code) goto found;
	}
	return PFMLIB_ERR_NOTFOUND;
found:
	*next = i;
	return PFMLIB_SUCCESS;
}

static int
pfm_find_event_byvcode_next(unsigned long vcode, unsigned int i, unsigned int *next)
{
	if (PFMLIB_INITIALIZED() == 0) return PFMLIB_ERR_NOINIT;

	if (next == NULL) return PFMLIB_ERR_INVAL;

	

	for(++i; i < pfm_current->pme_count; i++) {
		if (pfm_current->get_event_vcode(i) == vcode) goto found;
	}
	return PFMLIB_ERR_NOTFOUND;
found:
	*next = i;
	return PFMLIB_SUCCESS;
}

int
pfm_get_event_name(unsigned int i, char *name, int maxlen)
{
	if (PFMLIB_INITIALIZED() == 0) return PFMLIB_ERR_NOINIT;

	if (i >= pfm_current->pme_count || name == NULL || maxlen < 1) return PFMLIB_ERR_INVAL;

	strncpy(name, pfm_current->get_event_name(i), maxlen-1);

	name[maxlen-1] = '\0';

	return PFMLIB_SUCCESS;
}

int
pfm_get_event_code(unsigned int i, int *code)
{
	if (PFMLIB_INITIALIZED() == 0) return PFMLIB_ERR_NOINIT;

	if (i >= pfm_current->pme_count || code == NULL) return PFMLIB_ERR_INVAL;

	*code = pfm_current->get_event_code(i);

	return PFMLIB_SUCCESS;
}

int
pfm_get_event_counters(unsigned int i, pfmlib_regmask_t *counters)
{
	if (PFMLIB_INITIALIZED() == 0) return PFMLIB_ERR_NOINIT;

	if (i >= pfm_current->pme_count) return PFMLIB_ERR_INVAL;

	pfm_current->get_event_counters(i, counters);

	return PFMLIB_SUCCESS;
}


int
pfm_get_num_events(unsigned int *count)
{
	if (PFMLIB_INITIALIZED() == 0) return PFMLIB_ERR_NOINIT;

	if (count == NULL) return PFMLIB_ERR_INVAL;

	*count = pfm_current->pme_count;

	return PFMLIB_SUCCESS;
}


/*
 * Function used to print information about a specific events. More than
 * one event can be printed in case an event code is given rather than
 * a specific name. A callback function is used for printing.
 */
int
pfm_print_event_info(const char *name, int (*pf)(const char *fmt,...))
{
	unsigned long number, vcode;
	pfmlib_regmask_t cmask, impl_counters;
        int code, ret;
	int code_is_used = 1, event_is_digit = 0;
	unsigned int idx, next_idx, n, num_counters, i;

	if (PFMLIB_INITIALIZED() == 0) return PFMLIB_ERR_NOINIT;

	if (name == NULL || pf == NULL) return PFMLIB_ERR_INVAL;

	pfm_current->get_num_counters(&n);

	/* we can't quite use pfm_findevent() because we need to try
	 * both ways systematically.
	 */
	if (isdigit((int)*name)) {

		event_is_digit = 1;

		ret = pfm_gen_event_code(name, &number);
		if (ret != PFMLIB_SUCCESS) return ret;

		if (number <= INT_MAX) {
			int the_int_number = (int)number;

			ret = pfm_find_event_bycode(the_int_number, &idx);
			if (ret == PFMLIB_SUCCESS) goto start_loop;
		}
		code_is_used = 0;

		/* try the vcode now */
		ret  = pfm_find_event_byvcode(number, &idx);
	} else {
		ret  = pfm_find_event_byname(name, &idx);
	}

	if (ret != PFMLIB_SUCCESS) return PFMLIB_ERR_NOTFOUND;

	pfm_current->get_num_counters(&num_counters);
start_loop:
	do {
		code  = pfm_current->get_event_code(idx);
		vcode = pfm_current->get_event_vcode(idx);

		(*pf)(	"Name   : %s\n"
			"VCode  : 0x%lx\n"
			"Code   : 0x%x\n",
			pfm_current->get_event_name(idx),
			vcode,
			code);
		
		(*pf)(	"PMD/PMC: [ ");

		pfm_current->get_event_counters(idx, &cmask);
		n = num_counters;
		for (i=0; n; i++) {
			if (PFMLIB_REGMASK_ISSET(&impl_counters, i)) n--;
			if (PFMLIB_REGMASK_ISSET(&cmask, i)) (*pf)("%d ", i);
		}
		(*pf)(	"]\n");

		/* print PMU specific information */
		if (pfm_current->print_info) {
			pfm_current->print_info(idx, pf);
		}
		ret = code_is_used ?
			pfm_find_event_bycode_next(code, idx, &next_idx) :
			pfm_find_event_byvcode_next(vcode, idx, &next_idx);

		idx = next_idx;

	} while (event_is_digit && ret == PFMLIB_SUCCESS);

	return PFMLIB_SUCCESS;
}

int
pfm_print_event_info_byindex(unsigned int v, int (*pf)(const char *fmt,...))
{
	pfmlib_regmask_t cmask, impl_counters;
	unsigned int i, n;

	if (PFMLIB_INITIALIZED() == 0) return PFMLIB_ERR_NOINIT;

	if (v >= pfm_current->pme_count || pf == NULL) return PFMLIB_ERR_INVAL;

	(*pf)(	"Name   : %s\n"
		"VCode  : 0x%lx\n"
		"Code   : 0x%x\n",
		pfm_current->get_event_name(v),
		pfm_current->get_event_vcode(v),
		pfm_current->get_event_code(v));
	
	(*pf)(	"PMD/PMC: [ ");

	pfm_current->get_num_counters(&n);
	pfm_current->get_event_counters(v, &cmask);
	pfm_current->get_impl_counters(&impl_counters);

	for (i=0; n; i++) {
		if (PFMLIB_REGMASK_ISSET(&impl_counters, i)) n--;
		if (PFMLIB_REGMASK_ISSET(&cmask, i)) (*pf)("%d ", i);
	}
	(*pf)(	"]\n");

	/* print PMU specific information */
	if (pfm_current->print_info) {
		pfm_current->print_info(v, pf);
	}
	return PFMLIB_SUCCESS;
}

int
pfm_dispatch_events(pfmlib_input_param_t *inp, void *model_in, pfmlib_output_param_t *outp, void *model_out)
{
	unsigned int max_count, count;
	unsigned int i;

	if (PFMLIB_INITIALIZED() == 0) return PFMLIB_ERR_NOINIT;

	if (inp == NULL || outp == NULL) return PFMLIB_ERR_INVAL;

	/*
	 * the default priv level must be set to something
	 */
	if (inp->pfp_dfl_plm == 0) return PFMLIB_ERR_INVAL;

	if (inp->pfp_event_count >= PFMLIB_MAX_PMCS) return PFMLIB_ERR_INVAL;

	max_count = pfm_current->pme_count;
	count     = inp->pfp_event_count;

	/*
	 * check that event descriptors are correct
	 *
	 * invalid plm bits are simply ignored
	 */
	for (i=0; i < count; i++) {
		if (inp->pfp_events[i].event >= max_count) return PFMLIB_ERR_INVAL;
	}

	/* reset pc counter */
	outp->pfp_pmc_count = 0;

	return pfm_current->dispatch_events(inp, model_in, outp, model_out);
}

/*
 * more or less obosleted by pfm_get_impl_counters()
 */
int
pfm_get_num_counters(unsigned int *num)
{
	if (PFMLIB_INITIALIZED() == 0) return PFMLIB_ERR_NOINIT;

	if (num == NULL) return PFMLIB_ERR_INVAL;
	
	pfm_current->get_num_counters(num);

	return PFMLIB_SUCCESS;
}

int
pfm_get_num_pmcs(unsigned int *num)
{
	if (PFMLIB_INITIALIZED() == 0) return PFMLIB_ERR_NOINIT;

	if (num == NULL) return PFMLIB_ERR_INVAL;
	
	pfm_current->get_num_pmcs(num);

	return PFMLIB_SUCCESS;
}

int
pfm_get_num_pmds(unsigned int *num)
{
	if (PFMLIB_INITIALIZED() == 0) return PFMLIB_ERR_NOINIT;

	if (num == NULL) return PFMLIB_ERR_INVAL;
	
	pfm_current->get_num_pmds(num);

	return PFMLIB_SUCCESS;
}

int
pfm_get_impl_pmcs(pfmlib_regmask_t *impl_pmcs)
{
	if (PFMLIB_INITIALIZED() == 0) return PFMLIB_ERR_NOINIT;
	if (impl_pmcs == NULL) return PFMLIB_ERR_INVAL;

	pfm_current->get_impl_pmcs(impl_pmcs);

	return PFMLIB_SUCCESS;
}

int
pfm_get_impl_pmds(pfmlib_regmask_t *impl_pmds)
{
	if (PFMLIB_INITIALIZED() == 0) return PFMLIB_ERR_NOINIT;
	if (impl_pmds == NULL) return PFMLIB_ERR_INVAL;

	pfm_current->get_impl_pmds(impl_pmds);

	return PFMLIB_SUCCESS;
}

int
pfm_get_impl_counters(pfmlib_regmask_t *impl_counters)
{
	if (PFMLIB_INITIALIZED() == 0) return PFMLIB_ERR_NOINIT;
	if (impl_counters == NULL) return PFMLIB_ERR_INVAL;

	pfm_current->get_impl_counters(impl_counters);

	return PFMLIB_SUCCESS;
}

int
pfm_get_hw_counter_width(unsigned int *width)
{
	if (PFMLIB_INITIALIZED() == 0) return PFMLIB_ERR_NOINIT;
	if (width == NULL) return PFMLIB_ERR_INVAL;

	pfm_current->get_hw_counter_width(width);

	return PFMLIB_SUCCESS;
}


/* sorry, only English supported at this point! */
static char *pfmlib_err_list[]=
{
	"success",
	"not supported",
	"invalid parameters",
	"pfmlib not initialized",
	"object not found",
	"cannot assign events to counters",
	"buffer is full",
	"event used more than once",
	"invalid model specific magic number",
	"invalid combination of model specific features",
	"incompatible event sets",
	"incompatible events combination",
	"too many events",
	"code range too big",
	"empty code range",
	"invalid code range",
	"too many code ranges",
	"invalid data range",
	"too many data ranges",
	"not supported by host cpu",
	"code range is not bundle-aligned"
};
static int pfmlib_err_count = sizeof(pfmlib_err_list)/sizeof(char *);

char *
pfm_strerror(int code)
{
	code = -code;
	if (code <0 || code >= pfmlib_err_count) return "unknown error code";
	return pfmlib_err_list[code];
}

void
__pfm_vbprintf(const char *fmt, ...)
{
	va_list ap;

	if (pfm_config.options.pfm_verbose == 0) return;

	va_start(ap, fmt);
	vprintf(fmt, ap);
	va_end(ap);
}

int
pfm_get_version(unsigned int *version)
{
	if (version == NULL) return PFMLIB_ERR_INVAL;
	*version = PFMLIB_VERSION;
	return 0;
}

int
pfm_get_max_event_name_len(unsigned int *len)
{
	unsigned int i;
	unsigned int max = 0, l;

	if (PFMLIB_INITIALIZED() == 0) return PFMLIB_ERR_NOINIT;
	if (len == NULL) return PFMLIB_ERR_INVAL;

	for(i=0; i < pfm_current->pme_count; i++) {
		l = strlen(pfm_current->get_event_name(i));
		if (l > max) max = l;
	}
	*len = max;

	return PFMLIB_SUCCESS;
}

