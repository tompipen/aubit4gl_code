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
# $Id: Makefile,v 1.6 2003-11-15 05:35:54 afalout Exp $
#

ROOT    =../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              Source files
## ==================================================================

OBJS_4GL= asql.ao connection_menu.ao pick.ao database.ao main_menu.ao query.ao \
	session.ao table.ao execute.ao paginate.ao

OBJS_C=lex.yy.o simple_parse.o dir.o

OBJS=${OBJS_4GL} ${OBJS_C}

OBJS_PG=${OBJS} postgres.ao
OBJS_IFX=${OBJS} infx.ao

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

## ==================================================================
##                              Targets
## ==================================================================

all : ${ALL}
	@echo "Default targets (${ALL}) compiled."

#obsolete:
#check:
#	./check_for_env

asql_i.4ae: ${OBJS_IFX}
	A4GL_LEXDIALECT=INFORMIX; 4glpc -g  $^ -o $@  -lUI_TUI

asql_p.4ae: ${OBJS_PG}
	A4GL_LEXDIALECT=POSTGRES; 4glpc -g  $^ -o $@  -lUI_TUI

qryfrm.afr.dat: qryfrm.per
	fcompile $^

## ==================================================================
##                              Sub-targets
## ==================================================================


lex.yy.c: parse.l
	flex -i parse.l

dir.o: dir.c
	gcc -g -c dir.c


query.ao: query.4gl
	4glpc -g -G -c $^ -o $@

execute.ao: execute.4gl
	4glpc -g -G -c $^ -o $@

infx.ao: infx.4gl
	A4GL_LEXDIALECT=INFORMIX; 4glpc -g -c $^ -o $@

postgres.ao: postgres.4gl
#	echo $@ $^ $*
#	echo $*  ${$@:.ao=.o} ${$^:.4gl=.o}
	A4GL_LEXDIALECT=POSTGRES; 4glpc -g -c $^ -o $@
#ecpg_wrap script produces .o not .ao - FIX IT
#	mv $*.o $@
#	mv ${$@:.ao=.o} $@
	mv postgres.o $@

%.ao: %.4gl
	4glpc -g -c $^ -o $@


## ==================================================================
##                              Install/de-install
## ==================================================================

install:
	@echo "asql installed."



deinstall:
	@echo "asql de-installed."

## ==================================================================
##                              clean
## ==================================================================

clean:
	${RM} ${OBJS} ${ALL} *.bak *.err *.warn lex.yy.c \
    ${OBJS_4GL:.ao=.h} ${OBJS_4GL:.ao=.glb} ${OBJS_4GL:.ao=.ec} \
	${OBJS_4GL:.ao=.cpc} ${OBJS_4GL:.ao=.c}


#	rm -f \
#	asql.4ae asql.4ae.err asql.c asql.ec asql.glb asql.h asql.o \
#	connection_menu.c connection_menu.ec connection_menu.glb connection_menu.h connection_menu.o \
#	database.c database.ec database.glb database.h database.o \
#	dir.o \
#	execute.c execute.ec execute.glb execute.h execute.o \
#	lex.yy.c lex.yy.o \
#	main_menu.c main_menu.ec main_menu.glb main_menu.h main_menu.o \
#	pick.c pick.ec pick.glb pick.h pick.o \
#	query.c query.ec query.glb query.h query.o \
#	session.c session.ec session.glb session.h session.o \
#	simple_parse.o \
#	table.c table.ec table.glb table.h table.o \
#	paginate.c paginate.ec paginate.glb paginate.h paginate.o \
#	infx.c infx.ec infx.glb infx.h infx.o

# ============================= EOF ============================
