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
# $Id: Makefile,v 1.28 2006-07-17 11:16:09 mikeaubury Exp $
#

ROOT    	=../..
LIBROOT		=${ROOT}/lib

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

#Rules for compiling 4GL sources using Aubit compiler
include ${ROOT}/incl/a4gl.mk

## ==================================================================
##                              Settings
## ==================================================================

4GLC	=${ROOT}/bin/4glc
FCOMPILE=${ROOT}/bin/fcompile
CFLAGS+= -DPORTABLE

## ==================================================================
##                              Targets
## ==================================================================

${LIBROOT}/libHELP_std${SO_EXT}: helplib.o a4gl_xxhelp.afr.o
	${LD} ${SO_LDFLAGS} -g -DPORTABLE -o $@ $^ -I${ROOT}/incl -L${ROOT}/lib -laubit4gl
	@echo "Help library sucesfully compiled."


## ==================================================================
##                              Sub-targets
## ==================================================================

#helplib.o: helplib.${FGLC_OUTPUT_EXT}
#a4gl_xxhelp.afr.o: a4gl_xxhelp.afr.c

helplib.c: helplib.4gl
	export DEBUG=ALL; export A4GL_SQLTYPE=nosql; export A4GL_LEXTYPE=C; export A4GL_OBJ_EXT=.o; \
	${4GLC} -4 -DPORTABLE --namespace HELPLIB_aclfgl_ $^

#For debugging only
dbghelplib.${FGLC_OUTPUT_EXT}: helplib.4gl
	export DEBUG=ALL; export A4GL_SQLTYPE=nosql; export A4GL_LEXTYPE=C; \
	gdb --args ${4GLC} --namespace "HELPLIB_aclfgl_" $^
	
	
a4gl_xxhelp.afr.c: a4gl_xxhelp.per
	(export A4GL_PACKER=PACKED; export A4GL_FORMTYPE=GENERIC; \
	export A4GL_SQLTYPE=nosql; export DEBUG=ALL;\
	${FCOMPILE} -c $^)

## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} a4gl_xxhelp.afr.c ${LIBROOT}/libHELP_std${SO_EXT} \
	a4gl_xxhelp.afr.dat helplib.${FGLC_OUTPUT_EXT} helplib.c helplib.ec \
	helplib.glb helplib.h *.err *.bak debug.out *.o *.ao *~ *.warn

# =============================== EOF ================================


