# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0   lib/libgui makefile		 |
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
# $Id: Makefile,v 1.1 2004-05-21 11:53:40 mikeaubury Exp $
#

LIBROOT		=../../..
ROOT		=../../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              Options
## ==================================================================

CFLAGS=-I$(ROOT)/lib/libaubit4gl -I$(ROOT)/incl
LFLAGS=-L$(ROOT)/lib -laubit4gl `pkg-config --libs --cflags gtk+-2.0`

## ==================================================================
##                              Targets
## ==================================================================

${LIBROOT}/libLOGREP_PDF.so : layout_pdf.c
	cc -rdynamic -shared -g $^ -o $@ ${CFLAGS} ${LFLAGS}

## ==================================================================
##                              Options
## ==================================================================

clean:
	${RM} ${LIBROOT}/libLOGREP_PDF.so *.o
	
	
