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
# $Id: Makefile,v 1.5 2003-07-20 06:53:25 afalout Exp $
#

ROOT    =../../..
LIBROOT	=../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              Options
## ==================================================================


## ==================================================================
##                              Targets
## ==================================================================


all: ${LIBROOT}/libesqlhelper_funcs.so

${LIBROOT}/libesqlhelper_funcs.so: helper_funcs.o
	esql -Bstatic -g --shared $^ -o $@ -L${LIBROOT} -laubit4gl

${LIBROOT}/libesqlhelper_funcs_p.so: helper_funcs_p.o
	gcc -Bstatic -g --shared $^ -o $@ -L${LIBROOT} -laubit4gl

## ==================================================================
##                              Sub-targets
## ==================================================================


helper_funcs.o: helper_funcs.ec
	esql -DDIALECT_INFORMIX -g -c -o $@ $^ -I${ROOT}/incl

helper_funcs_p.o: helper_funcs.ec
	ecpg helper_funcs.ec
	gcc -DDIALECT_POSTGRES -g -c -o helper_funcs_p.o helper_funcs.c -I$(POSTGRESDIR)/include -I${ROOT}/incl

## ==================================================================
##                              Clean
## ==================================================================


clean:
	${RM} -f *.o *.c *.so

