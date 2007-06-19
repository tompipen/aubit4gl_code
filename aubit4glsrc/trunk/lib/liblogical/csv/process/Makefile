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
# $Id: Makefile,v 1.6 2007-06-19 07:37:28 mikeaubury Exp $
#

ROOT		=../../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              Options
## ==================================================================

CFLAGS+=-g ${WALL} -I$(ROOT)/incl -I../common -I../../common ${PIC}

OBJS=process_csv.o ../../common/a4gl_lle.o ../common/csv_io.o

## ==================================================================
##                              Targets
## ==================================================================


${PLUGINDIR}/libLOGREPPROC_CSV${SO_EXT}: ${OBJS}
	${CC}  ${SO_LDFLAGS}  ${OBJS} -o $@ -L${LIBROOT} -l${AUBITLIBFULL}
	
process_csv.o: ../../processor/API_process.h process_csv.c
	 ${CC} $(CFLAGS) -c -o process_csv.o process_csv.c

../../processor/API_process.h:
	${MAKE} -C ../../processor
	
## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} *.o ${PLUGINDIR}/libLOGREPPROC_CSV${SO_EXT}
	
