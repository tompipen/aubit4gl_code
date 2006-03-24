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
# $Id: Makefile,v 1.30.2.1 2006-03-24 17:24:01 mikeaubury Exp $
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
ifneq "${COMSPEC}" ""
	LIBAUBIT4GL=-L${LIBROOT} -laubit4gl
endif

ifeq "${TARGET_OS}" "solaris"
	LIBAUBIT4GL=-L${LIBROOT} -laubit4gl
endif

PGLIBS=-L${ECPG_LIBDIR} ${ECPG_LFLAGS} -lecpg -lecpg_compat -lpgtypes

ALL=${LIBROOT}/libESQL_INFORMIX${SO_EXT} ${LIBROOT}/libESQL_POSTGRES${SO_EXT} \
    ${LIBROOT}/libESQL_SAP${SO_EXT} ${LIBROOT}/libESQL_QUERIX${SO_EXT} ${LIBROOT}/libESQL_INGRES${SO_EXT}

ifneq "${COMSPEC}" ""
	QUERIX_IFLAGS=-I"${QUERIXDIR}/include"
	QUERIX_LFLAGS=-L"${QUERIXDIR}/lib"
    QUERIX_LIBS="${QUERIXDIR}/lib/libesql.lib" "${QUERIXDIR}/lib/libesql.lib" \
				"${QUERIXDIR}/lib/libfgl.lib"
	#"${QUERIXDIR}/lib/libsqlc.lib"
	#"${QUERIXDIR}/bin/libfgl.dll"
else
	INGRES_IFLAGS=
	INGRES_LFLAGS=
	INGRES_LIBS=
	QUERIX_IFLAGS=-I${QUERIXDIR}/incl
	QUERIX_LFLAGS=-L${QUERIXDIR}/lib
    STATIC=-static
    QUERIX_LIBS=-lesql
endif
ifeq "${TARGET_OS}" "solaris"
	STATIC=
endif

ifdef COMSPEC
	#Should be OK now:
    #FIXME!!!!! I'm using variable named TMP somewhere!!!!
	#TMP			=/cygdrive/d/DOCUME~1/ADMINI~1/LOCALS~1/Temp
    #PWD			=
    #export TMP
    #export PWD

#from Mikes Makefile.cygwin:
	CFLAGS		:=-g -D_REENTRANT -DIFX_THREAD -I${ROOT}/incl ${CFLAGS} 
	ESQL		=esql -g
	ESQL_FLAGS	=-thread
	LDFLAGS		=
	#IFX_CSDK_DIR=/CSDK
	INFORMIXDIR_CSDK	=${INFORMIXDIR_UNQUOTED}${IFX_CSDK_DIR}
	IFX_WIN_LIBS="${INFORMIXDIR_CSDK}\bin\isqlt09a.dll"  "${INFORMIXDIR_CSDK}\bin\igl4n304.dll" \
		"${INFORMIXDIR_CSDK}\bin\iglxn304.dll"  "${INFORMIXDIR_CSDK}\bin\igo4n304.dll"
endif

ifneq "${COMSPEC}" ""
	PGLIBS				:=$(shell echo "${PGLIBS}" | tr '\\' '/')
	ECPG_INCDIR			:=$(shell echo "${ECPG_INCDIR}" | tr '\\' '/')
	ECPG_IFLAGS			:=$(shell echo "${ECPG_IFLAGS}" | tr '\\' '/')
	LIBPQ_FE_H_IFLAGS	:=$(shell echo "${LIBPQ_FE_H_IFLAGS}" | tr '\\' '/')
endif

## ==================================================================
##                              Targets
## ==================================================================

all: ${ALL}
	@echo "Done: ${ALL}"

###################
libESQL_INFORMIX${SO_EXT}: ${LIBROOT}/libESQL_INFORMIX${SO_EXT}
${LIBROOT}/libESQL_INFORMIX${SO_EXT}: helper_funcs_informix.o
ifneq "${COMSPEC}" ""
	$(CC) $(LDFLAGS) -g -mms-bitfields -shared -Wl,--export-all-symbols $^ ${IFX_WIN_LIBS} ${LIBAUBIT4GL} -o $@
else
	${IFMX_ESQLC}  ${STATIC} -g --shared $^ -o $@ ${LIBAUBIT4GL}  
#Solaris:
#	libtool --mode=link gcc -shared helper_funcs.o -o libESQL_INFORMIX.so \ 
#		-L$INFORMIXDIR/lib -L$INFORMIXDIR/lib/esql  `esql -libs`
#	cp *.so .
endif

###################
libESQL_POSTGRES${SO_EXT}: ${LIBROOT}/libESQL_POSTGRES${SO_EXT}
${LIBROOT}/libESQL_POSTGRES${SO_EXT}: helper_funcs_postgresql.o
	${CC} ${STATIC} -g --shared $^ -o $@ ${PGLIBS} ${LIBAUBIT4GL}
# -Bstatic
#gcc: file path prefix "static" never used

###################
libESQL_SAP${SO_EXT}: ${LIBROOT}/libESQL_SAP${SO_EXT}
${LIBROOT}/libESQL_SAP${SO_EXT}: helper_funcs_sap.o
	${CC} ${STATIC} -g --shared $^ -o $@ ${LIBAUBIT4GL}

###################
libESQL_QUERIX${SO_EXT}: ${LIBROOT}/libESQL_QUERIX${SO_EXT}
${LIBROOT}/libESQL_QUERIX${SO_EXT}: helper_funcs_querix.o
	${CC} ${STATIC} -g --shared $^ -o $@ ${LIBAUBIT4GL} ${QUERIX_LFLAGS} ${QUERIX_LIBS}



libESQL_INGRES${SO_EXT}: ${LIBROOT}/libESQL_INGRES${SO_EXT}
${LIBROOT}/libESQL_INGRES${SO_EXT}: helper_funcs_ingres.o
	${CC} ${STATIC} -g --shared $^ -o $@ ${LIBAUBIT4GL} ${INGRES_LFLAGS} ${INGRES_LIBS}

## ==================================================================
##                              Sub-targets
## ==================================================================

###################
#Infromix ESQL/C compiler
helper_funcs_informix.o: helper_funcs.ec
ifneq "${COMSPEC}" ""
#WARNING: Querix also has esqlc, and Informix esql invokes esqlc to compile .ec
#WARNING: esql will strip all quotes, and invoke esqlc with un-quoted paths
#that may contain spaces. If you get message "Input file name has invalid suffix ''"
#that is probably what happened. You must double-quote it ('"..."')
	$(ESQL) -dcmdl $(ESQL_FLAGS) -DDIALECT_INFORMIX -I'"${INFORMIXDIR_CSDK}/incl"' -e $<
	$(CC) $(CFLAGS) -DDIALECT_INFORMIX -I"${INFORMIXDIR_CSDK}/incl/esql" \
		-I"${INFORMIXDIR_CSDK}/incl" -c $(basename $<).c -o $@
	-@rm $(basename $<).c $(basename $<).c_*
else
	${IFMX_ESQLC} -fPIC -static -DDIALECT_INFORMIX -g -c -o $@ $^ -I${ROOT}/incl \
		-I"${INFORMIXDIR}/incl" 
#solaris:
#	esql -e helper_funcs.ec -I.. -I/home/aubit4gl/aubit4glsrc/incl
#	libtool --mode=compile gcc -fPIC -I$INFORMIXDIR/incl/esql -I.. \ 
#		-I/home/aubit4gl/aubit4glsrc/incl  helper_funcs.c -c -o helper_funcs.o
endif

###################
#PostgreSQL ESQL/C compiler
helper_funcs_postgresql.o: helper_funcs.ec
	${PG_ESQLC} -C INFORMIX -t $^
	${CC} ${CFLAGS} -DPG_ESQLC_V3=$(PG_ESQLC_V3) -DDIALECT_POSTGRES -g -c -o $@ helper_funcs.c -I$(ECPG_INCDIR) ${ECPG_IFLAGS} ${LIBPQ_FE_H_IFLAGS} -I${ROOT}/incl `aubit-config PG_COPTS`

###################
#SAP ESQL/C compiler
helper_funcs_sap.o: helper_funcs.ec
#cpc will allways add .cpc extension to any source files
	cp $^ $^.cpc
#Had to disable syntax check of EXEC SQL statements, because SAP EC pre-compiler
#does not take in account #ifdef's, and then fail on syntax specific to
#another ESQL/C
#check nocheck   ::  -H nocheck              (default: -H check)
#      syntax    ::  -H syntax
	${SAPDB_ESQLC} -H nocheck $^ -I${ROOT}/incl -o $@ -DDIALECT_SAP -I/opt/sapdb/interfaces/precompiler/incl
	rm $^.cpc

###################
#Querix ESQL/C compiler
helper_funcs_querix.o: helper_funcs.ec
#must remove .c file or .ec will not get recompiled
 	#rm helper_funcs.c
#need quotes because of the path on Windows
	"${Q_ESQLC}" $^
	${CC} ${CFLAGS} -DDIALECT_QUERIX -g -c -o $@ helper_funcs.c -I${ROOT}/incl ${QUERIX_IFLAGS}
#-DNEWERA
	rm helper_funcs.c

###################
#INGRES ESQL/C compiler
helper_funcs_ingres.o: helper_ingres.ec
#must remove .c file or .ec will not get recompiled
	#rm helper_funcs.c
#need quotes because of the path on Windows
	$(II_SYSTEM)/ingres/bin/esqlc $^
	${CC} ${CFLAGS} -DDIALECT_INGRES -g -c -o $@ helper_ingres.c -I${ROOT}/incl ${INGRES_IFLAGS}
#-DNEWERA
	rm helper_ingres.c

	
show:
	@echo "INFORMIXDIR=${INFORMIXDIR}"
	@echo "INFORMIXDIR_UNQUOTED=${INFORMIXDIR_UNQUOTED}"

	
## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} -f *.o *.c *${SO_EXT} *.cpc *.bak *.ec.w2 *.ec.w3 *.ec.pcl



# =============================== EOF ===============================
