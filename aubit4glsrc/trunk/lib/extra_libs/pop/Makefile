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
# $Id: Makefile,v 1.3 2003-08-31 13:33:55 mikeaubury Exp $
#

ROOT    =../../..
LIBROOT =${ROOT}/lib

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              Options
## ==================================================================

4GLPC_EXEC=export A4GL_LEXTYPE=C; ${SH} ${ROOT}/bin/4glpc

## ==================================================================
##                              Targets
## ==================================================================

#FIXME: use amake

all : ${LIBROOT}/liba4gl_pop${SO_EXT} test.4ae 
${LIBROOT}/liba4gl_pop${SO_EXT}: pop.4gl 
	${4GLPC_EXEC} -g -as-dll $^ -o $@ -lspopc
test.4ae: test.4gl test.per
	${4GLPC_EXEC} test.4gl -o test.4ae
	fcompile test.per

## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} *.out *.c *.${FGLC_OUTPUT_EXT} *.h *${SO_EXT} *.err *.bak *.glb *.h \
	*.4ae ${LIBROOT}/libA4GL_pop${SO_EXT}


