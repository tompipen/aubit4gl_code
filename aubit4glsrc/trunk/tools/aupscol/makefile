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
# $Id: makefile,v 1.7 2006-10-02 07:52:40 afalout Exp $
#

# Currently Informix only
#
# Set A4GL_UPSCOL_VAL, A4GL_UPSCOL_ATT to point to different tablenames if 
# required (Tables will be created if they don't exist)

ROOT    =../..
LIBROOT	=${ROOT}/lib
BINROOT	=${ROOT}/bin

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

include ${ROOT}/incl/a4gl.mk

## ==================================================================
##                              Options
## ==================================================================

A4GL_LEXTYPE=EC
export A4GL_LEXTYPE
A4GL_LEXDIALECT=INFORMIX
export A4GL_LEXDIALECT
#INFORMIXC=gcc
#export INFORMIXC

#4GLC=${FGLPCEXEC} ${VERBOSE_FLAG}
#FGLPC_VERBOSE_FLAG=-V5
4GLC			=4glpc ${FGLPC_VERBOSE_FLAG}


ALL=${ROOT}/bin/aupscol

ifdef COMSPEC
	#Should be obsolete now:

	#FIXME!!!!! I'm using variable named TMP somewhere!!!!
	#TMP=/cygdrive/d/DOCUME~1/ADMINI~1/LOCALS~1/Temp
	#TMP=/tmp
    #PWD=
    #export TMP
    #export PWD
	
	#TMP=4glc CVS ace fcompile helpcompile menus pcode xgen
	#TEMP=/cygdrive/d/DOCUME~1/ADMINI~1/LOCALS~1/Temp
	#PWD=/usr/src/aubit/aubit4glsrc/tools/aupscol
	
	#Running:  4glc main.4gl -c -o main.ao
	#esqlc: Error -33041: Cannot open output file 'D:\cygwin\usr\src\aubit\aubit4glsr
	#c\tools\aupscol\4glc CVS ace fcompile helpcompile menus pcode xgen\eqaa3468'.
	
	#THIS IS PWD:	
	#'D:\cygwin\usr\src\aubit\aubit4glsrc\tools\aupscol\
	#THIS IS TMP:
	#4glc CVS ace fcompile helpcompile menus pcode xgen\eqaa3468'.	
	
endif


## ==================================================================
##                              Targets
## ==================================================================

all: ${ALL}
	@echo "Default target (${ALL}) succesfuly compiled."
	
${ROOT}/bin/aupscol: main.ao upscol.ao infx.ao ../asql/ifx_pick.ao val.ao att.ao
	${4GLC} ${VERBOSE_FLAG} $^ -o $@


## ==================================================================
##                              Sub-targets
## ==================================================================

../asql/ifx_pick.ao:
	${MAKE} -C ../asql

run:
	${ROOT}/bin/aupscol${EXE_EXT}
	
show:
	@echo "TMP=${TMP}"
	@echo "TEMP=${TEMP}"
	@echo "PWD=${PWD}"
#TMP=4glc CVS ace fcompile helpcompile menus pcode xgen
#PWD=/usr/src/aubit/aubit4glsrc
#esqlc: Error -33041: Cannot open output file 'd:\pdc25_vc_w32:\cygdrive\d\Progra
#~1\GnuWin32:\cygdrive\e\Program files\W2000\Informix\lib:\cygdrive\e\Program fil
#es\W2000\Informix\lib\esql:\eqaa3324'.

## ==================================================================
##                              Clean
## ==================================================================
	
clean:
	${RM} *.o *.ao *.bak *.h *.glb *.c *.ec *~ *.err aupscol *.warn *.c_ \
	${ALL} *~ 
	
	
