# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-1 Aubit Development Team (See Credits file)       |
# +----------------------------------------------------------------------+
# | This program is free software; you can redistribute it and/or modify |
# | it under the terms of one of the following licenses:                 |
# |                                                                      |
# |  A) the GNU General Public License as published by the Free Software |
# |     Foundation; either version 2 of the License, or (at your option) |
# |     any later version.                                               |
# |                                                                      |
# |  B) the Aubit License as published by the Aubit Development Team and |
# |     included in the distribution in the file: LICENSE                |
# |                                                                      |
# | This program is distributed in the hope that it will be useful,      |
# | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
# | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
# | GNU General Public License for more details.                         |
# |                                                                      |
# | You should have received a copy of both licenses referred to here.   |
# | If you did not, or have any questions about Aubit licensing, please  |
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+

#
# $Id: Makefile,v 1.8 2004-07-11 02:58:03 afalout Exp $
#
ROOT		=../../..
LIBROOT		=${ROOT}/lib


#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              Options
## ==================================================================

CFLAGS+=-Wall -g -I$(ROOT)/lib/libaubit4gl -I$(ROOT)/incl -fPIC

OBJS=process_report.o ../common/a4gl_lle.o API_process.o

LD_EXE_FLAGS=-rdynamic

ifeq "${TARGET_OS}" "hpux"
	LD_EXE_FLAGS=-a1 -z -Wl,+s -Wl,-E -lnsl
endif

## ==================================================================
##                              Targets
## ==================================================================

${ROOT}/bin/process_report: API_process.h ${OBJS} 
	${CC} -g ${OBJS} -o $@  -L$(LIBROOT) -laubit4gl ${LD_EXE_FLAGS}

API_process.c: API_process.spec
	../../bin/dlmagic $^ > $@

API_process.h: API_process.spec
	../../bin/dlmagic $^ -h > $@

## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} *.o process_report ${ROOT}/bin/process_report API_process.h \
	API_process.c *~


