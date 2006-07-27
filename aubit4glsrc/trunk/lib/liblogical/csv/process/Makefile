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
# $Id: Makefile,v 1.2 2006-07-27 16:02:57 mikeaubury Exp $
#

ROOT		=../../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              Options
## ==================================================================

CFLAGS=-g -Wall -I$(ROOT)/incl -I../common -I../../common -fPIC

OBJS=process_csv.o ../../common/a4gl_lle.o ../common/csv_io.o

## ==================================================================
##                              Targets
## ==================================================================


${PLUGINDIR}/libLOGREPPROC_CSV${SO_EXT}: ${OBJS}
	${CC} -fPIC -shared ${OBJS} -o $@ -L${LIBROOT} -l${AUBITLIBFULL}
	
process_csv.o: ../../processor/API_process.h

../../processor/API_process.h:
	${MAKE} -C ../../processor
	
## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} *.o ${PLUGINDIR}/libLOGREPPROC_CSV${SO_EXT}
	
