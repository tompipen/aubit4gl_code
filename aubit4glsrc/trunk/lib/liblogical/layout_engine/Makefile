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
# $Id: Makefile,v 1.2 2004-03-19 02:44:47 afalout Exp $
#

LIBROOT		=../..
ROOT		=../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              Options
## ==================================================================


CFLAGS+=-g $(shell pkg-config --cflags gtk+-2.0) \
	-I$(AUBITDIR)/lib/libaubit4gl -I$(AUBITDIR)/incl

LFLAGS:=$(shell pkg-config --libs gtk+-2.0) -laubit4gl

OBJS=layout_engine.o ../common/a4gl_lle.o ../report_viewer/report_viewer.o \
	API_layout.o file_hand.o

## ==================================================================
##                              Targets
## ==================================================================

layout_engine: API_layout.h ${OBJS}
	cc -rdynamic -g ${OBJS} -o $@ ${LFLAGS}  

API_layout.c: API_layout.spec
	../../bin/dlmagic $^ > $@

API_layout.h: API_layout.spec
	../../bin/dlmagic $^ -h > $@

## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} *.o layout_engine
	
