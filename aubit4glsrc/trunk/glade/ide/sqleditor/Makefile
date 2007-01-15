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
# $Id: Makefile,v 1.2 2007-01-15 19:52:58 mikeaubury Exp $
#

ROOT					=../../..
LIBROOT					=${ROOT}/lib

#All stuff common to more then one Aubit compiler make file is there:
include 				${ROOT}/incl/Makefile-common

#Include rules for compiling 4GL source code using Aubit compiler
include 				${ROOT}/incl/a4gl.mk

## ==================================================================
##                              Options
## ==================================================================

CFLAGS					+=-g -I${ROOT}/incl
#WARNING: currently, 4glpc is not hanling GCC on Windows, and will just pass everything
#to esql compiler - which will try to invoke MSVC "cl" which most probably
#will not exist on the system. OTOH, 4glc will handle ec compilation as 
#discreate steps of 4gl->.ec->.c->.dll/.exe
#If you are tempted to use 4glpc (instead 4glc
#directly) please make sure it will work for all platforms and ESQL dialects
#in this makefile. Andrej.
#4GLPC					=4glpc -g
#4GLPC				=${FGLPCEXEC}
#FGLPC_VERBOSE_FLAG=-V5
4GLPC			=4glpc ${FGLPC_VERBOSE_FLAG}

################
#Aubit compiler settings. infx.4gl contains Informix ESQL/C code
A4GL_LEXTYPE			=EC
A4GL_USE_DATABASE_STMT	=Y
A4GL_LEXDIALECT			=INFORMIX

#OBJ					= editor.ao infx.ao ../common/pick.ao ../common/about.ao \
						#execute.ao simple_parse.o lex.yy.o main.ao
BASE_4GL				= editor.4gl infx.4gl ../common/pick.4gl ../common/about.4gl \
						execute.4gl simple_parse.c ${LEX_YY_C} main.4gl

ifneq "${IFMX_ESQLC}" "no"
	ALL						=${ROOT}/bin/sqleditor.4ae
else
	ALL						=no_esql
endif

ifeq "${LEX}" "no"
  LEX_YY_C      =lex_pregen.o
  CFLAGS        +=-DUSE_PREGEN
  EXTRA_ALL=
else
  LEX_YY_C      =lex.yy.o
  EXTRA_ALL     +=refresh.nolex
endif




## ==================================================================
##                              Targets
## ==================================================================

all: ${ALL}
	@echo "+--------------------------------------------------------------------+"
	@echo "| Default target (${ALL}) succesfully compiled"
	@echo "+--------------------------------------------------------------------+"	

no_esql:
	@echo "+--------------------------------------------------------------------+"
	@echo "| Informix ESQL/C not detected - cannot compile Glade SQL editor     |"
	@echo "+--------------------------------------------------------------------+"

${ROOT}/bin/sqleditor.4ae: ${BASE_4GL}
	${4GLPC} -I../common -g $^ -o $@
	
## ==================================================================
##                              Sub-targets
## ==================================================================

#FIXME: not targets to compile ide.glade
#ide.glade also in ..

#Amake will do this automatically:

#../common/pick.ao: ../common/pick.4gl 
#	${4GLPC} $^ -c -o $@

#../common/about.ao: ../common/about.4gl
#	${4GLPC} $^ -c -o $@
	
#editor.ao: editor.4gl
#	${4GLPC} $^ -c -o $@ 

#infx.ao: infx.4gl
#	${4GLPC} $^ -c -o $@ 

#main.ao: main.4gl
#	${4GLPC} $^ -c -o $@ 

#edtprog.ao: edtprog.4gl
#	${4GLPC} $^ -c -o $@

#execute.ao: execute.4gl
#	${4GLPC} $^ -c -o $@

lex.yy.c: parse.l
	${LEX} -i $^


refresh.nolex: lex.yy.c
	cp lex.yy.c lex_pregen.c


## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} *.ec *.ao *.glb *.o lex.yy.c about.c about.h editor.c editor.h edtprog.c \
	edtprog.h execute.c execute.h ide1.c ide1.h infx.c infx.h lex.yy.c pick.c \
	pick.h ${ALL} *.warn *.err debug.out *.bak *~ ${OBJ} main.c main.h


