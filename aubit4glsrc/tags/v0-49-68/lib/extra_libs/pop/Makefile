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
# $Id: Makefile,v 1.13 2005-03-07 14:53:04 mikeaubury Exp $
#

ROOT    =../../..
LIBROOT =${ROOT}/lib

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              Options
## ==================================================================

4GLPC_EXEC=export A4GL_LEXTYPE=C; ${FGLPCEXEC}

ALL=${LIBROOT}/libA4GL_pop${SO_EXT} 
#test.4ae

4GLC	=${ROOT}/bin/4glc

ifdef COMSPEC
	CFLAGS	+=-I$(shell cygpath -m /usr/include) -L$(shell cygpath -m /lib)
	LINKLIBS=-lwsock32
endif

## ==================================================================
##                              Targets
## ==================================================================

#FIXME: use amake

######### !!!!!!!!! PLEASE keep A4GL_ in UPPERCASE !!!!!!!!! ###############
all : ${ALL}

${LIBROOT}/libA4GL_pop${SO_EXT}: pop.o
#	${4GLPC_EXEC} -g ${AS_DLL} $^ -o $@ -lspopc
	${LD} ${SO_LDFLAGS} ${CFLAGS} -o $@ $^ -L${ROOT}/lib -laubit4gl -lspopc ${LINKLIBS}
	@echo "POP library sucesfully compiled."

pop.o: pop.4gl
	export A4GL_OBJ_EXT=.o; export A4GL_SQLTYPE=nosql; export A4GL_LEXTYPE=C; ${4GLC} -c ${VERBOSE_FLAG} $^

#Move this test in tools/test/build_test
test.4ae: test.4gl test.per
	${4GLPC_EXEC} $< -o $@
	${ROOT}/bin/fcompile test.per

pop_killer.4ae: pop_killer.4gl
	${4GLPC_EXEC} $^ -o $@

## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} *.out *.c *.${FGLC_OUTPUT_EXT} *.h *${SO_EXT} *.err *.bak *.glb *.h \
	*.4ae *.afr.dat *.afr.xml *.afr  ${ALL} *.stackdump



