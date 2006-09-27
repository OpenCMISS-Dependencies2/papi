/*
 * Contributed by Philip Mucci <mucci@cs.utk.edu> based on code from
 * Copyright (c) 2004-2006 Hewlett-Packard Development Company, L.P.
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
#ifndef __PFMLIB_GEN_MIPS64_PRIV_H__
#define __PFMLIB_GEN_MIPS64_PRIV_H__

/*
 * mips64 encoding structure
 * (code must be first 4 bits)
 */
typedef struct {
	unsigned long pme_emask:32; /* event mask, holds room for four events, low 8 bits cntr0, ... high 8 bits cntr3 */
} pme_gen_mips64_entry_code_t;		

typedef union {
	pme_gen_mips64_entry_code_t pme_code;
	unsigned long 		pme_vcode;
} pme_gen_mips64_codes_t;

typedef struct {
	char			*pme_name;
	pme_gen_mips64_codes_t	pme_entry_code;
	uint32_t		pme_counters; 
	char			*pme_desc;		/* text description of the event */
} pme_gen_mips64_entry_t;

#endif /* __PFMLIB_GEN_MIPS64_PRIV_H__ */
