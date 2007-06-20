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
# $Id: Makefile,v 1.3 2007-06-20 07:04:58 mikeaubury Exp $
#

ROOT        =../..
LIBROOT     =${ROOT}/lib

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                    		Settings
## ==================================================================

ifeq "${LEX}" "no"
	LEX_YY_C	=${ROOT}/tools/no_yacc/cygwin/compilers/xgen/lex.yy.c
else
	LEX_YY_C	=lex.yy.c
endif

ifeq "${YACC}" "no"
	Y_TAB_C_DEP	=${ROOT}/tools/no_yacc/cygwin/compilers/xgen/y.tab.c
else
	Y_TAB_C_DEP	=${LEX_YY_C}
endif

CMODS		=y.tab.c main.c
OBJS		=${CMODS:.c=.o}

API_HEADERS =${ROOT}/incl/a4gl_API_lex.h ${ROOT}/incl/a4gl_API_form.h \
			${ROOT}/incl/a4gl_API_menu.h ${ROOT}/incl/a4gl_API_msg.h \
			${ROOT}/incl/a4gl_API_packer.h ${ROOT}/incl/a4gl_API_ui.h

ALL			=${ROOT}/bin/xgen
#use_xgen

## ==================================================================
##                          Targets
## ==================================================================

all: ${ALL}
	@echo "Default targets (${ALL}) built successfully."

${ROOT}/bin/xgen: ${OBJS}
	${CC} ${EXE_CFLAGS} $^ -o $@
#	${CP} $@ ${ROOT}/bin

y.tab.c: x.yacc lex.yy.c
#${ROOT}/common/dataio/form_x.x.h
#	@echo "YACC=>>${YACC}<<"
ifeq "${YACC}" "no"
	${CP} ${Y_TAB_C_DEP} .
else
	${YACC} x.yacc
endif


lex.yy.c: x.lex
ifeq "${LEX}" "no"
	${CP} ${LEX_YY_C} .
else
	${LEX} $^
endif


#use_xgen:
#	(cd ../../common/dataio; make)

#${ROOT}/common/dataio/form_x.x.h:
#	${MAKE} -C ${ROOT}/common/dataio form_x.xo.c


${API_HEADERS}:
	${MAKE} -C ../../lib/libaubit4gl api.headers

y.tab.o: ${API_HEADERS}

show:
	@echo "YACC=${YACC}"
	@echo "Y_TAB_C_DEP=${Y_TAB_C_DEP}"
	@echo "LEX=${LEX}"
	@echo "LEX_YY_C=${LEX_YY_C}"
	@echo "CFLAGS=${CFLAGS}"


## ==================================================================
##                          Clean
## ==================================================================

clean:
	${RM} lex.yy.c *.o xgen y.tab.c *.bak .*.bak

## ==================================================================
##                         Other Targets
## ==================================================================

splint: lclint
lclint: $(CMODS)
	${LCLINTERR}${LCLINTEXE} ${LCLINTFLAGS} $(LCLINT_CFLAGS) $(CMODS) > ${LCLINTLOG} ${LCLINTLOGCMD}
	${CAT} ${LCLINTLOG} >> ${ROOT}/${LCLINT_GLOBAL_LOG}
	@echo "see ${LCLINTLOG} for results"


# ============================= EOF ==================================
