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
# $Id: Makefile,v 1.2 2006-10-13 11:28:55 afalout Exp $
#

ROOT			=../..
LIBROOT			=${ROOT}/lib

#All stuff common to more then one Aubit compiler make file is there:
include 		${ROOT}/incl/Makefile-common

#Include rules for compiling 4GL source code using Aubit compiler
include 		${ROOT}/incl/a4gl.mk

## ==================================================================
##                              Options
## ==================================================================

CFLAGS			+=-I${ROOT}/incl
#WARNING: currently, 4glpc is not hanling GCC on Windows, and will just pass everything
#to esql compiler - which will try to invoke MSVC "cl" which most probably
#will not exist on the system. OTOH, 4glc will handle ec compilation as 
#discreate steps of 4gl->.ec->.c->.dll/.exe
#If you are tempted to use 4glpc (instead 4glc
#directly) please make sure it will work for all platforms and ESQL dialects
#in this makefile. Andrej.
#4GLPC			=${FGLPCEXEC}
#FGLPC_VERBOSE_FLAG=-V5
4GLPC			=4glpc ${FGLPC_VERBOSE_FLAG}

ALL				=${ROOT}/bin/ide1.4ae ${ROOT}/bin/sqleditor.4ae

## ==================================================================
##                              Targets
## ==================================================================

all: ${ALL}
	@echo "+--------------------------------------------------------------------+"
	@echo "| Default targets (${ALL}) successfuly compiled"
	@echo "+--------------------------------------------------------------------+"	

${ROOT}/bin/ide1.4ae: ide1.ao common/pick.ao common/about.ao edtprog.ao options.ao
	${4GLPC} $^ -o $@

${ROOT}/bin/sqleditor.4ae:
	${MAKE} -C sqleditor
	
#FIXME: no target to compile ide.glade
	
## ==================================================================
##                              Sub-targets
## ==================================================================

#Amake will do this automatically:

#common/pick.ao: common/pick.4gl
#	${4GLPC} $^ -c -o $@

#common/about.ao: common/about.4gl
#	${4GLPC} $^ -c -o $@
	
#options.ao: options.4gl
#	${4GLPC} $^ -c -o $@ 

#ide1.ao: ide1.4gl
#	${4GLPC} $^ -c -o $@ 

#edtprog.ao: edtprog.4gl
#	${4GLPC} $^ -c -o $@

## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} *.ao *.ec *.glb *.o *.c *.h *.err *.warn debug.out *~ *.bak ${ALL}
	${MAKE} -C sqleditor clean
	cd common; ${RM} *.ao *.c *.glb *.h *.err *.warn debug.out *~ *.bak *.ec
	

