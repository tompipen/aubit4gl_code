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
# $Id: makefile,v 1.4 2004-09-28 09:49:27 afalout Exp $
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

## ==================================================================
##                              Options
## ==================================================================

A4GL_LEXTYPE=EC
export A4GL_LEXTYPE
A4GL_LEXDIALECT=INFORMIX
export A4GL_LEXDIALECT
#INFORMIXC=gcc
#export INFORMIXC

4GLC=${FGLPCEXEC} -verbose

## ==================================================================
##                              Targets
## ==================================================================

${ROOT}/bin/aupscol: main.o upscol.o infx.o ../asql/ifx_pick.ao val.o att.o
	${4GLC} $^ -o $@

## ==================================================================
##                              Sub-targets
## ==================================================================

#FIXME: use amake to do this

att.o: att.4gl
	${4GLC} -g -c $^ -o $@

main.o: main.4gl
	${4GLC} -g -c $^ -o $@

val.o: val.4gl
	${4GLC}  -g -c $^ -o $@

infx.o: infx.4gl
	${4GLC} -g -c $^ -o $@

upscol.o: upscol.4gl
	${4GLC} -g -c $^ -o $@

../asql/ifx_pick.ao:
	${MAKE} -C ../asql

## ==================================================================
##                              Clean
## ==================================================================
	
clean:
	${RM} *.o *.ao *.bak *.h *.glb *.c *.ec *~ *.err aupscol \
	${ROOT}/bin/aupscol *~
	
	
