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
# $Id: Makefile,v 1.10 2003-11-15 15:54:11 mikeaubury Exp $
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

#Objects that do not originate in 4GL code - version independent
OBJS_C=lex.yy.o simple_parse.o dir.o

#Version specific objects
OBJS_PG_ONLY=postgres.ao
OBJS_IFX_ONLY=infx.ao

CLEAN_OBJS=${OBJS_4GL} ${OBJS_PG_ONLY} ${OBJS_IFX_ONLY}

#All objects for Postgres version
OBJS_PG=$(addprefix pg_,${OBJS_4GL}) $(addprefix pg_,${OBJS_PG_ONLY}) ${OBJS_C}

#All objects for Informix version
OBJS_IFX=$(addprefix ifx_,${OBJS_4GL}) $(addprefix ifx_,${OBJS_IFX_ONLY}) ${OBJS_C}

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

#-G stops esql/c putting #lines in the output so its easier to debug
4GLPCFLAGS=-O2

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
#Because we call some of those curses routines directly ATM.
#Hopefully I can get rid of that eventually but the brief was to make the
#edititing key compatible with Informix's. To do this I'll need to access the
#curses routines directly..
#There may be an argument for putting this editing routine into a separate
#module (one key compatible TUI mode one, one that just uses the aubit UI
#routines) - but thats for later...
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

ifx_%.ao: %.4gl
	${4GLPC} ${4GLPCFLAGS} -c $^ -o $@

pg_%.ao: %.4gl
	${4GLPC} ${4GLPCFLAGS} -c $^ -o $@

#Rule to make objects from 4GL file
#%.ao:
#	${4GLPC} -g -c $(subst pg_,,$(subst ifx_,,$*)).4gl -o $@


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
	${RM} ${ALL} *.bak *.err *.warn lex.yy.c ${OBJS_PG} ${OBJS_IFX} \
    ${CLEAN_OBJS:.ao=.h} ${CLEAN_OBJS:.ao=.glb} ${CLEAN_OBJS:.ao=.cpc} \
	${CLEAN_OBJS:.ao=.ec} ${CLEAN_OBJS:.ao=.c}



#    ${OBJS_PG:.ao=.h} ${OBJS_PG:.ao=.glb} ${OBJS_PG} \
#	${OBJS_PG:.ao=.cpc} ${OBJS_PG:.ao=.c} \
#    ${OBJS_IFX:.ao=.h} ${OBJS_IFX:.ao=.glb} ${OBJS_IFX} \
#	${OBJS_IFX:.ao=.c}  ${OBJS_IFX:.ao=.ec}


#	postgres.c postgres.cpc postgres.h postgres.glb \
#	infx.c infx.ec infx.glb infx.h

# ============================= EOF ============================
