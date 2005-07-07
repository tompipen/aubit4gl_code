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
# $Id: makefile,v 1.2 2005-02-03 07:47:34 afalout Exp $
#

ROOT    		=../..

################
#All stuff common to more then one Aubit compiler make file is there:
include 		${ROOT}/incl/Makefile-common

#Include rules for compiling 4GL source code using variois 4GL compilers
include 		${ROOT}/incl/a4gl.mk
include 		${ROOT}/incl/i4gl.mk
#include 		${ROOT}/incl/d4gl.mk
#include 		${ROOT}/incl/q4gl.mk

## ==================================================================
##                            Settings
## ==================================================================

CFGLGO=cfglgo
MQ_DIR=/usr/mqm

ifeq "${HAVE_MQLIB}" "1"
	ALL		=libA4GL_MQ${SO_EXT} test_mq.4ae
	ifneq "${I4GL_PCOMPILER}" "no"
		ALL	+=ifx_runner_mq test_mq.4gi
	endif

else
	ALL=no_mqlib
endif


## ==================================================================
##                            Targets
## ==================================================================

all: ${ALL}
	@echo "Done: ${ALL}"

no_mqlib:
	@echo "IBM WebSphere MQ was not detected on your system."
	
libA4GL_MQ${SO_EXT}: ${LIBROOT}/libA4GL_MQ${SO_EXT}
${LIBROOT}/libA4GL_MQ${SO_EXT}: mqfunc.c
	${LD} ${SO_LDFLAGS} $^ -I${MQ_DIR}/inc -D__AUBIT__ -o $@ ${LINKLIBS} ${MQ_DIR}/lib/libmqm.a
ifeq "${SO_EXT}" ".dll"
#We will still need the dll.a untill we dlopen() it instead of linking 
	${MV} TMP${SOEXP_EXT} $@.a
endif
	
test_mq.4gi: test_mq.4gl

ifx_runner_mq: fgiusr.c mqfunc.c
	${CFGLGO} -I${MQ_DIR}/inc $^ ${MQ_DIR}/lib/libmqm.a -o $@


## ==================================================================
##                            Clean
## ==================================================================
	
clean:
	${RM} *.4gi *.o


