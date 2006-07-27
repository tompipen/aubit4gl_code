# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0   Makefile for convertsql    |
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
# $Id: Makefile,v 1.3 2006-07-27 16:04:24 mikeaubury Exp $
#

ROOT      	= ../..

## ==================================================================
##                    Includes
## ==================================================================

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                    Settings
## ==================================================================

PROGRAM   	=${ROOT}/bin/convertsql
CFLAGS		+=-I${ROOT}/incl

## ==================================================================
##                    Targets
## ==================================================================

all:	$(PROGRAM)

$(PROGRAM):	main.o convertsql.o
	${CC} -o $@ $^ -L${ROOT}/lib -l${AUBITLIBFULL}

## ==================================================================
##                    Clean
## ==================================================================

clean:
	${RM} *.o *.bak $(PROGRAM)

# =============================== EOF ===============================
