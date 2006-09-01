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
# $Id: Makefile,v 1.12 2006-09-01 20:02:36 mikeaubury Exp $
#

ROOT		=../../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              Options
## ==================================================================

CFLAGS+=-g -I$(ROOT)/lib/libaubit4gl -I$(ROOT)/incl -fPIC 


## ==================================================================
##                              Targets
## ==================================================================

${PLUGINDIR}/libLOGREPPROC_TXT${SO_EXT} : process_txt.o
#	gcc  -shared -g $^ -o $@ ${CFLAGS} -L$(ROOT)/lib -l${AUBITLIBFULL} 
#	gcc -rdynamic -shared -g $^ -o $@ ${CFLAGS} -L$(ROOT)/lib -l${AUBITLIBFULL} 
	${LD} ${SO_LDFLAGS} -o $@ $^ -L$(LIBROOT) -l${AUBITLIBFULL}
	
process_txt.o: ../../layout_engine/API_layout.h ../../processor/API_process.h

../../layout_engine/API_layout.h:
	${MAKE} -C ../../layout_engine API_layout.h

../../processor/API_process.h: ../../processor/API_process.spec
	${LIBROOT}/bin/dlmagic $^ -h > $@

	
## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} ${PLUGINDIR}/libLOGREPPROC_TXT${SO_EXT} *.o
	
	
