#
# Copyright (c) 2002-2006 Hewlett-Packard Development Company, L.P.
# Contributed by Stephane Eranian <eranian@hpl.hp.com>
#
# Permission is hereby granted, free of charge, to any person obtaining a copy 
# of this software and associated documentation files (the "Software"), to deal 
# in the Software without restriction, including without limitation the rights 
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies 
# of the Software, and to permit persons to whom the Software is furnished to do so, 
# subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all 
# copies or substantial portions of the Software.  
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
# INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
# PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
# HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF 
# CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE 
# OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
# 
# This file is part of libpfm, a performance monitoring support library for
# applications on Linux.
#

#
# This file defines the global compilation settings.
# It is included by every Makefile
#
#
ARCH := $(shell uname -m)
ifeq (i686,$(findstring i686,$(ARCH)))
override ARCH=ia32
endif
ifeq (i586,$(findstring i586,$(ARCH)))
override ARCH=ia32
endif
ifeq (i486,$(findstring i486,$(ARCH)))
override ARCH=ia32
endif
ifeq (i386,$(findstring i386,$(ARCH)))
override ARCH=ia32
endif
#
# Where should things (lib, headers, man) go in the end.
#
install_prefix=/usr/local
PREFIX=$(install_prefix)
LIBDIR=$(PREFIX)/lib
INCDIR=$(PREFIX)/include
MANDIR=$(PREFIX)/share/man

#
# Configuration Paramaters for libpfm library
#
ifeq ($(ARCH),ia64)
CONFIG_PFMLIB_ARCH_IA64=y
CONFIG_PFMLIB_GEN_IA64=y
CONFIG_PFMLIB_ITANIUM=y
CONFIG_PFMLIB_ITANIUM2=y
CONFIG_PFMLIB_MONTECITO=y
endif

ifeq ($(ARCH),x86_64)
CONFIG_PFMLIB_ARCH_X86_64=y
CONFIG_PFMLIB_AMD64=y
CONFIG_PFMLIB_PENTIUM4=y
CONFIG_PFMLIB_GEN_IA32=y
CONFIG_PFMLIB_CORE=y
endif

ifeq ($(ARCH),ia32)
CONFIG_PFMLIB_ARCH_I386=y
CONFIG_PFMLIB_I386_P6=y
CONFIG_PFMLIB_GEN_IA32=y
CONFIG_PFMLIB_AMD64=y
CONFIG_PFMLIB_PENTIUM4=y
CONFIG_PFMLIB_CORE=y
endif

ifeq ($(ARCH),mips64)
CONFIG_PFMLIB_GEN_MIPS64=y
CONFIG_PFMLIB_ARCH_MIPS64=y
endif

#
# optimization level
#
OPTIM=-O2

#
# you shouldn't have to touch anything beyond this point
#

#
# The entire package can be compiled using 
# icc the Intel Itanium Compiler (7.x,8.x, 9.x)
# or GNU C
#CC=icc
CC=gcc
LIBS=
INSTALL=install
LN=ln -sf
PFMINCDIR=$(TOPDIR)/include
PFMLIBDIR=$(TOPDIR)/lib
DBG=-g -Wall -Werror
CFLAGS=$(OPTIM) $(DBG) -I$(PFMINCDIR)
LDFLAGS=-L$(PFMLIBDIR)
MKDEP=makedepend
PFMLIB=$(PFMLIBDIR)/libpfm.a
