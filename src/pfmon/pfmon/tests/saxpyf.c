/*
 * Copyright (C) 2002 Hewlett-Packard Co
 * Contributed by Stephane Eranian <eranian@hpl.hp.com>
 *
 * This file is part of pfmon, a sample tool to measure performance 
 * of applications on Linux/ia64.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 * 02111-1307 USA
 */

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

#define VECTOR_SIZE	1000000

static void fatal_error(char *fmt,...) __attribute__((noreturn));

static void
fatal_error(char *fmt, ...) 
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);

	exit(1);
}


static void
saxpy(double *a, double *b, double *c, unsigned long size)
{
	unsigned long i;

	for(i=0; i < size; i++) {
		c[i] = 2*a[i] + b[i];
	}
}

int
main(int argc, char **argv)
{
	unsigned long size;
	double *a, *b, *c;

	size = argc > 1 ? strtoul(argv[1], NULL, 0) : VECTOR_SIZE;

	printf("%lu entries = %lu bytes/vector = %lu Mbytes total\n", 
		size, 
		size*sizeof(unsigned long),
		(3*size*sizeof(unsigned long))>>20
	);

	a = malloc(size*sizeof(double));
	b = malloc(size*sizeof(double));
	c = malloc(size*sizeof(double));

	if (a == NULL || b == NULL || c == NULL)
		fatal_error("Cannot allocate vectors\n");

	memset(a, 0, size*sizeof(double));
	memset(b, 0, size*sizeof(double));
	memset(c, 0, size*sizeof(double));


	saxpy(a, b, c, size);

	return 0;
}
