# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0   Jabber makefile	   		 |
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
# $Id: makefile,v 1.8 2005-03-07 14:53:11 mikeaubury Exp $
#

ROOT        =../..
LIBROOT		=${ROOT}/lib

include 	${ROOT}/incl/Makefile-common

#We can't use Amake here - we cant't use 4glc (for linking) or 4glpc
#include 	${ROOT}/incl/a4gl.mk

## ==================================================================
##                              Settings
## ==================================================================

ALL 	=${ROOT}/bin/4glpc ${ROOT}/${HELP_DESTINATION}/4glpc.hlp

## ==================================================================
##                              Targets
## ==================================================================

all: ${ROOT}/bin/4glc ${ALL}
	@echo "Default targets (${ALL}) compiled."

${ROOT}/${HELP_DESTINATION}/4glpc.hlp: helpfile.msg ${ROOT}/bin/amkmessage
	${ROOT}/bin/amkmessage $< $@

${ROOT}/bin/4glpc: 4glpc.o times.o readsettings.o 
	${LD} $^ -o $@ -L${LIBROOT} -laubit4gl

## ==================================================================
##                              Rules
## ==================================================================
	
#%.ao: %.c
	#${CC} ${CFLAGS} -c $*.c -o $@
	
%.o: %.4gl
	export A4GL_OBJ_EXT=.o; A4GL_LEXTYPE=C; ${ROOT}/bin/4glc -c $<

## ==================================================================
##                              Dependencies
## ==================================================================
	
${ROOT}/bin/amkmessage:
	${MAKE} -C ${ROOT}/compilers/helpcompile
	
${ROOT}/bin/4glc:
	${MAKE} -C ${ROOT}/compilers/4glc
	
## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM}  *.o *.c *.h *.err *.glb ${ALL} *~ *.bak *.warn

