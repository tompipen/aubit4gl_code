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
# $Id: Makefile,v 1.4 2004-08-08 01:42:18 afalout Exp $
#

ROOT		=../../../..
LIBROOT		=${ROOT}/lib

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              Options
## ==================================================================

CFLAGS=-g -I$(ROOT)/lib/libaubit4gl -I$(ROOT)/incl  ${PDFLIB_I_FLAGS}

ifeq "${PDFBUILD}" "yes"
	ALL=${LIBROOT}/libLOGREPPROC_PDF.so
endif	

LINKLIBS=-L$(ROOT)/lib -laubit4gl

## ==================================================================
##                              Targets
## ==================================================================

all: ${ALL}

${LIBROOT}/libLOGREPPROC_PDF.so : process_pdf.o pdf_handling.o ../common/common_pdf.c
#	gcc  -z -Wl,+s -Wl,-E -shared -g $^ -o $@ ${CFLAGS} -L$(ROOT)/lib -laubit4gl  -lpdf
#	${LD} @PDFLIB_L_FLAGS@ -lpdf $(SO_LDFLAGS) ${OBJECTS_PDF} -o $@ ${LINKLIBS}
	${LD} ${CFLAGS} ${PDFLIB_L_FLAGS} -lpdf $(SO_LDFLAGS) $^ -o $@ ${LINKLIBS}
	
process_pdf.o: ../../layout_engine/API_layout.h

../../layout_engine/API_layout.h:
	${MAKE} -C ../../layout_engine API_layout.h
	
show:
	@echo "PDFBUILD=${PDFBUILD}"
	
## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} ${LIBROOT}/libLOGREPPROC_PDF.so *.o
	
	
