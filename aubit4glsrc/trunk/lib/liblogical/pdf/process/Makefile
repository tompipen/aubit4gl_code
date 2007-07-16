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
# $Id: Makefile,v 1.9 2007-07-16 06:15:37 mikeaubury Exp $
#

ROOT		=../../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              Options
## ==================================================================

CFLAGS+=-g -I$(ROOT)/lib/libaubit4gl -I$(ROOT)/incl  ${PDFLIB_I_FLAGS}

ifeq "${PDFBUILD}" "yes"
	ALL=${PLUGINDIR}/libLOGREPPROC_PDF${SO_EXT}
endif	

LINKLIBS=-L$(ROOT)/lib -l${AUBITLIBFULL}

## ==================================================================
##                              Targets
## ==================================================================

all: ${ALL}

${PLUGINDIR}/libLOGREPPROC_PDF${SO_EXT} : process_pdf.o pdf_handling.o ../common/common_pdf.c pdf_barcode.o
	${LD} ${CFLAGS} ${PDFLIB_L_FLAGS} $(SO_LDFLAGS) $^ -o $@ ${LINKLIBS} -lpdf
	
process_pdf.o: ../../layout_engine/API_layout.h ../../processor/API_process.h process_pdf.c
	${CC} $(CFLAGS) -c -o process_pdf.o process_pdf.c

../../layout_engine/API_layout.h:
	${MAKE} -C ../../layout_engine API_layout.h
../../processor/API_process.h:
	${MAKE} -C ../../processor API_process.h
	

show:
	@echo "PDFBUILD=${PDFBUILD}"
	
## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} ${PLUGINDIR}/libLOGREPPROC_PDF${SO_EXT} *.o
	
	
