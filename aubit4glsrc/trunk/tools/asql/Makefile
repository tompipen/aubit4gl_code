# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0   lib makefile				 |
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
# $Id: Makefile,v 1.8 2003-11-15 11:09:42 afalout Exp $
#

ROOT    =../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              Source files
## ==================================================================

#Objects that originate in 4GL code
OBJS_4GL= asql.ao connection_menu.ao pick.ao database.ao main_menu.ao query.ao \
	session.ao table.ao execute.ao paginate.ao

#Objects that originate in 4GL code, with ESQL compiler specific prefix, so that
#we don't mix them up when linking
OBJS_4GL_PG=$(addprefix pg_,${OBJS_4GL})
OBJS_4GL_IFX=$(addprefix ifx_,${OBJS_4GL})

#Objects that do not originate in 4GL code - version independent
OBJS_C=lex.yy.o simple_parse.o dir.o

#All objects for Postgres version
OBJS_PG=${OBJS_4GL_PG} ${OBJS_C} postgres.ao

#All objects for Informix version
OBJS_IFX=$(OBJS_4GL_IFX) ${OBJS_C} infx.ao

## ==================================================================
##                              Options
## ==================================================================

A4GL_LEXTYPE=EC
A4GL_USE_DATABASE_STMT=Y
export A4GL_LEXTYPE A4GL_USE_DATABASE_STMT POSTGRESDIR PGSQL_INCDIR

ALL=qryfrm.afr.dat

ifneq "${PG_ESQLC}" "no"
	ifeq "${HAVE_PGSQL_LIB}" "yes"
		ALL+=asql_p.4ae
    endif
endif

ifneq "${IFMX_ESQLC}" "no"
	ALL+=asql_i.4ae
endif

4GLPC=${SH} ${ROOT}/bin/4glpc
#-verbose

## ==================================================================
##                              Targets
## ==================================================================

all : ${ALL}
	@echo ""
	@echo "+--------------------------------------------------------------------+"
	@echo "| Default targets (${ALL}) compiled."
	@echo "+--------------------------------------------------------------------+"
	@echo ""

#why are we linking with UI_TUI ?
asql_i.4ae: A4GL_LEXDIALECT=INFORMIX
asql_i.4ae: ${OBJS_IFX}
	${4GLPC} -g  $^ -o $@  -lUI_TUI
	@echo ""
	@echo "+--------------------------------------------------------------------+"
	@echo "|           Successfuly compiled Informix version of asql            |"
	@echo "+--------------------------------------------------------------------+"
	@echo ""

asql_p.4ae: A4GL_LEXDIALECT=POSTGRES
asql_p.4ae: ${OBJS_PG}
	${4GLPC} -g  $^ -o $@  -lUI_TUI
	@echo ""
	@echo "+--------------------------------------------------------------------+"
	@echo "|          Successfuly compiled PostgreSQL version of asql           |"
	@echo "+--------------------------------------------------------------------+"
	@echo ""

qryfrm.afr.dat: qryfrm.per
	${ROOT}/bin/fcompile $^

## ==================================================================
##                              Sub-targets
## ==================================================================


lex.yy.c: parse.l
	${LEX} -i parse.l

#dir.o: dir.c
#	${CC} -g -c dir.c


#-G stops esql/c putting #lines in the output so its easier to debug
#%query.ao: query.4gl
#	${4GLPC} -g -G -c $^ -o $@
#
#%execute.ao: execute.4gl
#	${4GLPC} -g -G -c $^ -o $@

#Rule to make objects from 4GL file
%.ao:
	${4GLPC} -g -c $(subst pg_,,$(subst ifx_,,$*)).4gl -o $@


## ==================================================================
##                    Install/de-install
## ==================================================================

install:
	@echo "asql installed."

deinstall:
	@echo "asql de-installed."

## ==================================================================
##                     Run from current location
## ==================================================================

run.i:
	@LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:${ROOT}/lib";./asql_i.4ae

run.p:
	@LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:${ROOT}/lib";./asql_p.4ae

## ==================================================================
##                              clean
## ==================================================================

clean:
	${RM} ${OBJS_IFX} ${OBJS_PG} ${ALL} *.bak *.err *.warn lex.yy.c \
    ${OBJS_4GL:.ao=.h} ${OBJS_4GL:.ao=.glb} ${OBJS_4GL:.ao=.ec} \
	${OBJS_4GL:.ao=.cpc} ${OBJS_4GL:.ao=.c} \
	postgres.c postgres.cpc postgres.h postgres.glb \
	infx.c infx.ec infx.glb infx.h

# ============================= EOF ============================
