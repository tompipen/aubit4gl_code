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
# $Id: Makefile,v 1.9 2007-01-15 19:52:58 mikeaubury Exp $
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



ifeq "${LEX}" "no"
  LEX_YY_C	=lex_pregen.yy.c
  CFLAGS	+=-DUSE_PREGEN
else
  LEX_YY_C	=lex.yy.c
  EXTRA_ALL	+=refresh.nolex
endif

ifeq "${YACC}" "no"
  PARSE_OBJ   	=adbload2_parse_pregen.tab.o
  EXTRA_ALL=
else
  PARSE_OBJ     =adbload2_parse.tab.o
  EXTRA_ALL	+=refresh.noyacc
endif


## ==================================================================
##                    Targets
## ==================================================================

all: ${ALL} ${EXTRA_ALL}
	@echo "Default targets (${ALL}) succesfuly compiled"

adbload2: ${BINROOT}/adbload2
${BINROOT}/adbload2: ${PARSE_OBJ} parse.o adbload2.o process.o
	${FGLPC} -t EC -td INFORMIX -g -o $@ $^ -L${LIBROOT} 
#	-laubit4gl

## ==================================================================
##                    Sub-targets
## ==================================================================

refresh.noyacc: adbload2_parse.tab.c 
	cp adbload2_parse.tab.c adbload2_parse_pregen.tab.c

refresh.nolex: lex.yy.c
	cp lex.yy.c lex_pregen.yy.c

process.o: process.ec
	${FGLPC}  -t EC -td INFORMIX -g -o $@ $^ 

adbload2.o: adbload2.4gl
	${FGLPC}  -t EC -td INFORMIX -g -o $@ $^
	
lex.yy.c: adbload2_parse.l
	${LEX} $^

adbload2_parse.tab.c: adbload2_parse.y
	${BISON_EXE}  $^

adbload2_parse.tab.o: 		adbload2_parse.tab.c ${LEX_YY_C}
adbload2_parse_pregen.tab.o: 	adbload2_parse_pregen.tab.c ${LEX_YY_C}

## ==================================================================
##                    Test
## ==================================================================

test: adbload2
	${BINROOT}/asql_i.4ae mja1 q1.sql
	${BINROOT}/adbload2 -d mja1 -c bibble2 -l kjh
	${BINROOT}/asql_i.4ae mja1 q2.sql

show:
	@echo "PARSE_OBJ =${PARSE_OBJ}"
	@echo "LEX_YY_C=${LEX_YY_C}"
	@echo "CFLAGS=${CFLAGS}"
	@echo "EXTRA_ALL=${EXTRA_ALL}"
	@echo "LEX=${LEX} (flex -i ...)"
	@echo "YACC='${YACC}'"
	@echo "BISON=${BISON} (bison ...)"
	@echo "BISON_EXE=${BISON_EXE}"
	
## ==================================================================
##                    Clean
## ==================================================================

clean: 
	${RM} *.o lex.yy.c adbload2_parse.tab.c ${ALL} *.c_ \
	*.glb *~ *.bak y.tab.c adbload2.h adbload2.c process.c adbload2.ec

# ------------------------------ EOF ---------------------------------

