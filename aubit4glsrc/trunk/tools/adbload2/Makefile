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
# $Id: Makefile,v 1.6 2006-12-08 20:11:20 mikeaubury Exp $
#

ROOT    =../..
BINROOT	=${ROOT}/bin
LIBROOT	=${ROOT}/lib

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

#
# only works with Informix EC atm...
#

## ==================================================================
##                    Settings
## ==================================================================

CFLAGS			=-g

ALL				=${BINROOT}/adbload2
#FGLPC_VERBOSE	=-V5
FGLPC			=${BINROOT}/4glpc ${FGLPC_VERBOSE}

## ==================================================================
##                    Targets
## ==================================================================

all: ${ALL}
	@echo "Default targets (${ALL}) succesfuly compiled"

adbload2: ${BINROOT}/adbload2
${BINROOT}/adbload2: adbload2_parse.tab.o parse.o adbload2.o process.o
	${FGLPC} -V5  -t EC -g -o $@ $^ -L${LIBROOT} 
#	-laubit4gl

## ==================================================================
##                    Sub-targets
## ==================================================================

process.o: process.ec
	${FGLPC}  -t EC -g -o $@ $^ 

adbload2.o: adbload2.4gl
	${FGLPC}  -V5  -t EC -g -o $@ $^
	
lex.yy.c: adbload2_parse.l
	${LEX} $^

adbload2_parse.tab.c: adbload2_parse.y
	${BISON_EXE} $^

adbload2_parse.tab.o: adbload2_parse.tab.c lex.yy.c

## ==================================================================
##                    Test
## ==================================================================

test: adbload2
	${BINROOT}/asql_i.4ae mja1 q1.sql
	${BINROOT}/adbload2 -d mja1 -c bibble2 -l kjh
	${BINROOT}/asql_i.4ae mja1 q2.sql

show:
	@echo "LEX=${LEX} (flex -i ...)"
	@echo "BISON=${BISON} (bison ...)"
	@echo "BISON_EXE=${BISON_EXE}"
	
## ==================================================================
##                    Clean
## ==================================================================

clean: 
	${RM} *.o lex.yy.c adbload2_parse.tab.c ${ALL} *.c_ \
	*.glb *~ *.bak y.tab.c adbload2.h adbload2.c process.c adbload2.ec

# ------------------------------ EOF ---------------------------------

