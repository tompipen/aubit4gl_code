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
# $Id: Makefile,v 1.4 2003-08-04 00:49:45 afalout Exp $
#

ROOT    =../..
LIBROOT	=..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              Options
## ==================================================================

#> 1) Why -laubit4gl ?
#Its needed for the pop_.. and push_... stuff - on some platforms this is
#detected and linked properly, on some others - you need this to get the link
#to work...
#FIXME-in that case, it should be linked in conditionally:
#ifeq "${TARGET_OS}" "theOneThatNeedIt"
	LIBAUBIT4GL=-L${LIBROOT} -laubit4gl
#endif

PGLIBS=-L${PGSQL_LIBDIR} -lecpg -lecpg_compat -lpgtypes

## ==================================================================
##                              Targets
## ==================================================================

all: ${LIBROOT}/libESQL_INFORMIX.so ${LIBROOT}/libESQL_POSTGRES.so

libESQL_INFORMIX.so: ${LIBROOT}/libESQL_INFORMIX.so
${LIBROOT}/libESQL_INFORMIX.so: helper_funcs_i.o
	esql -static -Bstatic -g --shared $^ -o $@ ${LIBAUBIT4GL}

libESQL_POSTGRES.so: ${LIBROOT}/libESQL_POSTGRES.so
${LIBROOT}/libESQL_POSTGRES.so: helper_funcs_p.o
	${CC} -static -Bstatic -g --shared $^ -o $@ ${PGLIBS} ${LIBAUBIT4GL}

## ==================================================================
##                              Sub-targets
## ==================================================================


helper_funcs_i.o: helper_funcs.ec
	esql -static -DDIALECT_INFORMIX -g -c -o $@ $^ -I${ROOT}/incl

helper_funcs_p.o: helper_funcs.ec
	ecpg -C INFORMIX -t helper_funcs.ec
	gcc -DDIALECT_POSTGRES -g -c -o $@ helper_funcs.c -I$(PGSQL_INCDIR) -I${ROOT}/incl

## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} -f *.o *.c *.so


# =============================== EOF ===============================
