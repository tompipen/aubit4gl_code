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
# $Id: Makefile,v 1.7 2003-08-26 05:27:04 afalout Exp $
#

ROOT    =../..
LIBROOT	=..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              Options
## ==================================================================

#> 1) Why -laubit4gl ?
#Its needed for the pop_.. and push_... stuff - on some platforms this is
#detected and linked properly, on some others - you need this to get the link
#to work...
#FIXME-in that case, it should be linked in conditionally:
ifeq "${TARGET_OS}" "cygwin"
	LIBAUBIT4GL=-L${LIBROOT} -laubit4gl
endif

PGLIBS=-L${ECPG_LIBDIR} ${ECPG_LFLAGS} -lecpg -lecpg_compat -lpgtypes

ALL=${LIBROOT}/libESQL_INFORMIX${SO_EXT} ${LIBROOT}/libESQL_POSTGRES${SO_EXT} \
    ${LIBROOT}/libESQL_SAP${SO_EXT} ${LIBROOT}/libESQL_QUERIX${SO_EXT}

ifneq "${COMSPEC}" ""
	QUERIX_IFLAGS=-I"${QUERIXDIR}/include"
	QUERIX_LFLAGS=-L"${QUERIXDIR}/lib"
else
	QUERIX_IFLAGS=-I${QUERIXDIR}/incl
	QUERIX_LFLAGS=-L${QUERIXDIR}/lib
    STATIC=-static
endif

## ==================================================================
##                              Targets
## ==================================================================

all: ${ALL}
	@echo "Done: ${ALL}"

libESQL_INFORMIX${SO_EXT}: ${LIBROOT}/libESQL_INFORMIX${SO_EXT}
${LIBROOT}/libESQL_INFORMIX${SO_EXT}: helper_funcs_informix.o
	${IFMX_ESQLC} ${STATIC} -g --shared $^ -o $@ ${LIBAUBIT4GL}

libESQL_POSTGRES${SO_EXT}: ${LIBROOT}/libESQL_POSTGRES${SO_EXT}
${LIBROOT}/libESQL_POSTGRES${SO_EXT}: helper_funcs_postgresql.o
	${CC} ${STATIC} -g --shared $^ -o $@ ${PGLIBS} ${LIBAUBIT4GL}
# -Bstatic
#gcc: file path prefix "static" never used

libESQL_SAP${SO_EXT}: ${LIBROOT}/libESQL_SAP${SO_EXT}
${LIBROOT}/libESQL_SAP${SO_EXT}: helper_funcs_sap.o
	${CC} ${STATIC} -g --shared $^ -o $@ ${LIBAUBIT4GL}

libESQL_QUERIX${SO_EXT}: ${LIBROOT}/libESQL_QUERIX${SO_EXT}
${LIBROOT}/libESQL_QUERIX${SO_EXT}: helper_funcs_querix.o
	${CC} ${STATIC} -g --shared $^ -o $@ ${LIBAUBIT4GL} ${QUERIX_LFLAGS} "${QUERIXDIR}/lib/libesql.lib" \
	"${QUERIXDIR}/lib/libesql.lib" "${QUERIXDIR}/lib/libfgl.lib"
#"${QUERIXDIR}/lib/libsqlc.lib"
#"${QUERIXDIR}/bin/libfgl.dll"
#-lesql

## ==================================================================
##                              Sub-targets
## ==================================================================


helper_funcs_informix.o: helper_funcs.ec
	${IFMX_ESQLC} -static -DDIALECT_INFORMIX -g -c -o $@ $^ -I${ROOT}/incl

helper_funcs_postgresql.o: helper_funcs.ec
	${PG_ESQLC} -C INFORMIX -t $^
	${CC} -DDIALECT_POSTGRES -g -c -o $@ helper_funcs.c -I$(ECPG_INCDIR) ${ECPG_IFLAGS} -I${ROOT}/incl

helper_funcs_sap.o: helper_funcs.ec
#cpc will allways add .cpc extension to any source files
	cp $^ $^.cpc
	${SAPDB_ESQLC} $^ -I${INFORMIXDIR}/incl/esql -I${ROOT}/incl -o $@ -DDIALECT_SAP
	rm $^.cpc

helper_funcs_querix.o: helper_funcs.ec
#must remove .c file or .ec will not get recompiled
	-rm helper_funcs.c
#need quotes because of the path on Windows
	"${Q_ESQLC}" $^
	${CC} -DDIALECT_QUERIX -g -c -o $@ helper_funcs.c -I${ROOT}/incl ${QUERIX_IFLAGS}
#-DNEWERA
	rm helper_funcs.c

## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} -f *.o *.c *${SO_EXT} *.cpc *.bak


# =============================== EOF ===============================
