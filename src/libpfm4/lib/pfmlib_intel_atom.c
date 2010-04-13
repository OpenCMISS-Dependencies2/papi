/*
 * pfmlib_intel_atom.c : Intel Atom PMU
 *
 * Copyright (c) 2008 Google, Inc
 * Contributed by Stephane Eranian <eranian@gmail.com>
 *
 * Based on work:
 * Copyright (c) 2006 Hewlett-Packard Development Company, L.P.
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
 *
 * This file implements support for Intel Core PMU as specified in the following document:
 * 	"IA-32 Intel Architecture Software Developer's Manual - Volume 3B: System
 * 	Programming Guide"
 *
 * Intel Atom = architectural v3 + PEBS
 */
/* private headers */
#include "pfmlib_priv.h"
#include "pfmlib_intel_x86_priv.h"
#include "events/intel_atom_events.h"

static int
pfm_intel_atom_detect(void *this)
{
	int ret, family, model;

	ret = pfm_intel_x86_detect(&family, &model);
	if (ret != PFM_SUCCESS)
		return ret;
	/*
	 * Atom : family 6 model 28
	 */
	return family == 6 && model == 28 ? PFM_SUCCESS : PFM_ERR_NOTSUPP;
}

static int
pfm_intel_atom_init(void *this)
{
	pfm_intel_x86_cfg.arch_version = 3;
	return PFM_SUCCESS;
}

pfmlib_pmu_t intel_atom_support={
	.desc			= "Intel Atom",
	.name			= "atom",
	.pmu			= PFM_PMU_INTEL_ATOM,
	.pme_count		= PME_INTEL_ATOM_EVENT_COUNT,
	.max_encoding		= 1,
	.pe			= intel_atom_pe,

	.pmu_detect		= pfm_intel_atom_detect,
	.pmu_init		= pfm_intel_atom_init,

	.get_event_encoding	= pfm_intel_x86_get_encoding,
	.get_event_first	= pfm_intel_x86_get_event_first,
	.get_event_next		= pfm_intel_x86_get_event_next,
	.event_is_valid		= pfm_intel_x86_event_is_valid,
	.get_event_perf_type	= pfm_intel_x86_get_event_perf_type,
	.validate_table		= pfm_intel_x86_validate_table,
	.get_event_info		= pfm_intel_x86_get_event_info,
	.get_event_attr_info	= pfm_intel_x86_get_event_attr_info,
};
