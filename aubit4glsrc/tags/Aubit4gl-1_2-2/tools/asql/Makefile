# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0
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
# $Id: Makefile,v 1.61 2009-07-10 11:55:55 mikeaubury Exp $
#

ROOT    		=../..

################
#All stuff common to more then one Aubit compiler make file is there:
include 		${ROOT}/incl/Makefile-common

#Include rules for compiling 4GL source code using Aubit compiler
include 		${ROOT}/incl/a4gl.mk
## ==================================================================
##                              Source files
## ==================================================================

################
#Objects that originate in 4GL code
OBJS_4GL		= \
	asql${A4GL_OBJ_EXT} connection_menu${A4GL_OBJ_EXT}  menus${A4GL_OBJ_EXT}\
	database${A4GL_OBJ_EXT} main_menu${A4GL_OBJ_EXT} \
	query${A4GL_OBJ_EXT} session${A4GL_OBJ_EXT} table${A4GL_OBJ_EXT} \
	execute${A4GL_OBJ_EXT} paginate${A4GL_OBJ_EXT} cedit${A4GL_OBJ_EXT} \
	filehand${A4GL_OBJ_EXT} load${A4GL_OBJ_EXT}  \
	form${A4GL_OBJ_EXT} \
	tools${A4GL_OBJ_EXT} user_menu${A4GL_OBJ_EXT} report${A4GL_OBJ_EXT} 

OBJS_FORM	= splash.afr${A4GL_OBJ_EXT}


# We *could* use the A4GL_pick library - but that adds some extra overhead on
# what should be a faily 'clean' program. We dont want to add any more dependancies
# than is really required
# so - we'll just pick up the object files we need instead...
PICKDIR		= ${ROOT}/lib/extra_libs/pick
OBJS_PICK	= ${PICKDIR}/pick10.afr${A4GL_OBJ_EXT}  ${PICKDIR}/pick20.afr${A4GL_OBJ_EXT} ${PICKDIR}/pick38.afr${A4GL_OBJ_EXT} ${PICKDIR}/pick78.afr${A4GL_OBJ_EXT}  ${PICKDIR}/pick${A4GL_OBJ_EXT}

ifeq "${LEX}" "no"
  LEX_YY_C      =lex_pregen.o
else
  LEX_YY_C      =lex.asql_yy.o
endif


ifeq "${YACC}" "no"
  CFLAGS        +=-DUSE_PREGEN
  EXTRA_ALL=
else
  EXTRA_ALL     +=refresh.noyacc
endif



################
#Objects that do not originate in 4GL code - version independent
OBJS_C			=${LEX_YY_C} simple_parse.o dir.o



################
#Version specific objects
OBJS_PG_ONLY	=postgres${A4GL_OBJ_EXT}
OBJS_IFX_ONLY	=infx${A4GL_OBJ_EXT}
OBJS_GEN_ONLY	=generic${A4GL_OBJ_EXT} generic_db${A4GL_OBJ_EXT}
OBJS_ING_ONLY	=ing${A4GL_OBJ_EXT}
OBJS_INFOFLEX_ONLY	=infoflex${A4GL_OBJ_EXT}

################
#All objects that will need celaning, without prefix
CLEAN_OBJS		=${OBJS_4GL} ${OBJS_PG_ONLY} ${OBJS_IFX_ONLY} ${OBJS_GEN_ONLY} ${OBJS_ING_ONLY} ${OBJS_INFOFLEX_ONLY}

################
#All objects for Postgres version
OBJS_PG			=$(addprefix pg_,${OBJS_4GL}) ${OBJS_C} \
				$(addprefix pg_,${OBJS_PG_ONLY}) ${OBJS_FORM} ${OBJS_PICK}

################
#All objects for Informix version
OBJS_IFX		=$(addprefix ifx_,${OBJS_4GL}) ${OBJS_C} \
				$(addprefix ifx_,${OBJS_IFX_ONLY}) ${OBJS_FORM} ${OBJS_PICK}


OBJS_GEN		=$(addprefix gen_,${OBJS_4GL}) ${OBJS_C} \
				$(addprefix gen_,${OBJS_GEN_ONLY}) ${OBJS_FORM} ${OBJS_PICK}

OBJS_ING		=$(addprefix ing_,${OBJS_4GL}) ${OBJS_C} \
				$(addprefix ing_,${OBJS_ING_ONLY}) ${OBJS_FORM} ${OBJS_PICK}

OBJS_INFOFLEX		=$(addprefix infoflex_,${OBJS_4GL}) ${OBJS_C} \
				$(addprefix infoflex_,${OBJS_INFOFLEX_ONLY}) ${OBJS_FORM} ${OBJS_PICK}
## ==================================================================
##                              Options
## ==================================================================

################
#Aubit compiler settings
A4GL_LEXTYPE	=EC
#A4GL_USE_DATABASE_STMT=Y

###############
#Export to environment
export A4GL_LEXTYPE A4GL_USE_DATABASE_STMT POSTGRESDIR PGSQL_INCDIR CFLAGS LD_LIBRARY_PATH

ALL_FORMS		=

################
#Decide what to compile by default
ifneq "${PG_ESQLC}" "no"
	ifeq "${HAVE_PGSQL_LIB}" "yes"
		ALL_PROGS		+=asql_p${A4GL_EXE_EXT}
    endif
endif

ifneq "${IFMX_ESQLC}" "no"
	ALL_PROGS			+=asql_i${A4GL_EXE_EXT} runforms${A4GL_EXE_EXT}
endif

ALL_PROGS				+=asql_g${A4GL_EXE_EXT}

################
#4gl compiler command line to use
#WARNING: currently, 4glpc is not hanling GCC on Windows, and will just pass everything
#to esql compiler - which will try to invoke MSVC "cl" which most probably
#will not exist on the system. OTOH, 4glc will handle ec compilation as 
#discreate steps of 4gl->.ec->.c->.dll/.exe
#If you are tempted to use 4glpc (instead 4glc
#directly) please make sure it will work for all platforms and ESQL dialects
#in this makefile. Andrej.
#PS. trying to use 4glpc configuration files - ignore above if it works:
VERBOSE_FLAG	=--verbose
#4GLPC			=${FGLPCEXEC} ${VERBOSE_FLAG}
#FGLPC_VERBOSE_FLAG=-V5
4GLPC			=4glpc -V5 -fbounds-checking ${FGLPC_VERBOSE_FLAG}  
IFX4GLPC			=NEVER_CONVERT=Y 4glpc ${FGLPC_VERBOSE_FLAG} 

################
#4gl compiler flags
#-G stops esql/c putting #lines in the output so its easier to debug
4GLPCFLAGS		= -g   -versioned

ifeq "${VERBOSE}" "1"
	4GLPCFLAGS	+=${VERBOSE_FLAG}
endif
################
#Full make line to use when compiling 4gl objects
COMP4GL			=${4GLPC} -o $@ ${4GLPCFLAGS} -c $< 
#COMP4GL=${4GLPC} -g -c $(subst pg_,,$(subst ifx_,,$*)).4gl -o $@


################
#Additional libraries to link with created programs
#
#why are we linking with UI_TUI ?
#Because we call some of those curses routines directly ATM.
#Hopefully I can get rid of that eventually but the brief was to make the
#edititing key compatible with Informix's. To do this I'll need to access the
#curses routines directly..
#There may be an argument for putting this editing routine into a separate
#module (one key compatible TUI mode one, one that just uses the aubit UI
#routines) - but thats for later...

LINKLIBS		=
#-lUI_TUI


ALL				= ${ALL_PROGS}

.phony: install all clean

## ==================================================================
##                              Targets
## ==================================================================

ifeq "${TARGET_OS}" "hpux"
	4GLPCFLAGS+=-a1 -z -Wl,+s -Wl,-E
endif

%.afr${A4GL_OBJ_EXT}:%.per
	fcompile -c $<	
	4glpc -t C -c -o $@ ${subst .per,.afr.c,$<}

%.afr.dat:%.per
	fcompile  $<


################
#Default target
all : ${ALL} install
	@echo ""
	@echo "+--------------------------------------------------------------------+"
	@echo "| Default targets (${ALL}) compiled."
	@echo "+--------------------------------------------------------------------+"
	@echo ""

################
#Target to make asql Informix version
asql_i${A4GL_EXE_EXT}: ${OBJS_IFX}
	${IFX4GLPC} -V2 -t EC -td INFORMIX ${4GLPCFLAGS} $^ -o $@ ${LINKLIBS} 
	@echo ""
	@echo "+--------------------------------------------------------------------+"
	@echo "|           Successfuly compiled Informix version of asql            |"
	@echo "+--------------------------------------------------------------------+"
	@echo ""

runforms${A4GL_EXE_EXT}: 
	cd runforms; make; 
	

asql_g${A4GL_EXE_EXT}: ${OBJS_GEN}
	${4GLPC} -t C ${4GLPCFLAGS} $^ -o $@ ${LINKLIBS} 
	@echo ""
	@echo "+--------------------------------------------------------------------+"
	@echo "|           Successfuly compiled Generic version of asql             |"
	@echo "+--------------------------------------------------------------------+"
	@echo ""

asql_I${A4GL_EXE_EXT}: ${OBJS_ING}
	${4GLPC} -t EC -td INGRES ${4GLPCFLAGS} $^ -o $@ ${LINKLIBS} 
	@echo ""
	@echo "+--------------------------------------------------------------------+"
	@echo "|           Successfuly compiled Ingres  version of asql             |"
	@echo "+--------------------------------------------------------------------+"
	@echo ""

################
#Target to make asql PostgreSQL version
asql_p${A4GL_EXE_EXT}: ${OBJS_PG}
	${4GLPC} -t EC -td POSTGRES ${4GLPCFLAGS} $^ -o $@ ${LINKLIBS}
	@echo ""
	@echo "+--------------------------------------------------------------------+"
	@echo "|          Successfuly compiled PostgreSQL version of asql           |"
	@echo "+--------------------------------------------------------------------+"
	@echo ""


################
#Target to make asql InfoflexSQL version

INFOFLEX: asql_infoflex${A4GL_EXE_EXT}
asql_infoflex${A4GL_EXE_EXT}: ${OBJS_INFOFLEX}
	${4GLPC} -t EC -td INFOFLEX  ${4GLPCFLAGS} $^ -o $@ ${LINKLIBS}
	@echo ""
	@echo "+--------------------------------------------------------------------+"
	@echo "|          Successfuly compiled InfoFlex version of asql             |"
	@echo "+--------------------------------------------------------------------+"
	@echo ""

## ==================================================================
##                              Sub-targets
## ==================================================================

################
#Target to make parser
lex.asql_yy.c: parse.l
	${LEX} -Pasql_yy -i $^

################
#Rule to make objects from 4GL file - Informix version
ifx_%${A4GL_OBJ_EXT}: %.4gl simple.h
	${COMP4GL} --neverconvert -t EC -td INFORMIX -DSTATIC_LIBAUBIT4GL 


${PICKDIR}/pick${A4GL_OBJ_EXT}: ${PICKDIR}/pick.4gl
	${4GLPC} -t C -o $@ ${4GLPCFLAGS} -c $<

gen_%${A4GL_OBJ_EXT}: %.4gl simple.h
	${4GLPC} -t C -o $@ ${4GLPCFLAGS} -c $< 

ing_%${A4GL_OBJ_EXT}: %.4gl simple.h
	${4GLPC} -t EC -td INGRES -o $@ ${4GLPCFLAGS} -c $< 

infoflex_%${A4GL_OBJ_EXT}: %.4gl simple.h
	${4GLPC} -t EC -td INFOFLEX -o $@ ${4GLPCFLAGS} -c $< 

################
#Rule to make objects from 4GL file - Postgres version
pg_%.ao: %.4gl simple.h
	${4GLPC} -t EC -td POSTGRES -o $@ ${4GLPCFLAGS} -c $< 

## ==================================================================
##                    Install/de-install
## ==================================================================

install:
	${CP} ${ALL_PROGS} ${ROOT}/bin
#	${CP} ${ALL_FORMS} ${ROOT}/${FORMS_DESTINATION}
#	ln -s ${ROOT}/bin/asql_p.4ae ${ROOT}/bin/asql
	${RM} ${AUBITDIR}/bin/asql	
	ln -s ${AUBITDIR}/bin/asql_g${A4GL_EXE_EXT} ${AUBITDIR}/bin/asql
	@echo "asql installed."

#deinstall:
#	cd ${ROOT}/bin; ${RM} ${ALL} asql
#	@echo "asql de-installed."

## ==================================================================
##                     Run from current location
## ==================================================================

run.i:
	@LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:${ROOT}/lib";A4GL_FORMTYPE=GENERIC; \
	A4GL_PACKER=PACKED;./asql_i${A4GL_EXE_EXT}

run.I:
	@LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:${ROOT}/lib";A4GL_FORMTYPE=GENERIC; \
	A4GL_PACKER=PACKED;./asql_I${A4GL_EXE_EXT}
run.p:
	@LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:${ROOT}/lib";A4GL_FORMTYPE=GENERIC; \
	A4GL_PACKER=PACKED;./asql_p${A4GL_EXE_EXT}

	
menus.4gl: menus.txt generate
	sh generate  > menus.4gl

show:
	aubit-config POSTGRESDIR


refresh.noyacc: lex.yy.c
	cp lex.asql_yy.c lex_pregen.c

asql_i_static.4ae:
	$(INFORMIXDIR)/bin/esql -static -g  ifx_asql.ao ifx_connection_menu.ao ifx_menus.ao ifx_pick.ao ifx_database.ao ifx_main_menu.ao ifx_query.ao ifx_session.ao ifx_table.ao ifx_execute.ao ifx_paginate.ao ifx_cedit.ao ifx_filehand.ao ifx_load.ao ifx_form.ao ifx_tools.ao ifx_user_menu.ao ifx_report.ao lex.asql_yy.o simple_parse.o dir.o ifx_infx.ao -o asql_i_static.4ae -L/home/aubit4gl/aubit4glsrc/lib -laubit4gl_static -L/home/aubit4gl/aubit4glsrc/lib/libaubit4gl  -lm -lncurses -L$(INFORMIXDIR)/lib -L$(INFORMIXDIR)/lib/esql  -lncurses -lform -lpanel -lz


## ==================================================================
##                              clean
## ==================================================================

clean:
	${RM} ${ALL} ${OBJS_PG} ${OBJS_IFX} ${OBJS_GEN} ${CLEAN_OBJS:.ao=.warn} \
    ${CLEAN_OBJS:.ao=.h} ${CLEAN_OBJS:.ao=.glb} ${CLEAN_OBJS:.ao=.cpc} \
	${CLEAN_OBJS:.ao=.ec} ${CLEAN_OBJS:.ao=.c} \
    *.bak *.err *.warn lex.asql_yy.c lex.asql_yy.c *.c_ *~ debug.out


# ============================= EOF =================================
