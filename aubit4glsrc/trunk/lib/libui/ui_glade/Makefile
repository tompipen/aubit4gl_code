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
# $Id: Makefile,v 1.4 2006-07-27 16:04:07 mikeaubury Exp $
#

ROOT			=../../..

#All stuff common to more then one Aubit compiler make file is there:
include 		${ROOT}/incl/Makefile-common

## ==================================================================
##                              Options
## ==================================================================

CFLAGS			+=$(shell pkg-config libglade-2.0 --cflags)
LINKLIBS		=$(shell pkg-config libglade-2.0 --libs)
ALL				=${PLUGINDIR}/libUI_GLADE${SO_EXT}

OBJS			=glade.o dialog.o obj.o list.o

## ==================================================================
##                              Targets
## ==================================================================

all: ${ALL}
	@echo "+--------------------------------------------------------------------+"
	@echo "| Default targets (${ALL}) successfuly compiled"
	@echo "+--------------------------------------------------------------------+"	

${PLUGINDIR}/libUI_GLADE${SO_EXT}: ${OBJS}
#	${CC} -g -shared $^ -o $@ ${LFLAGS}
	${LD} ${SO_LDFLAGS} -o $@ $^ ${LINKLIBS} -L$(ROOT)/lib -l${AUBITLIBFULL}

## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} *.o debug.out *~ *.bak ${ALL}
	${MAKE} -C glade_lib clean


