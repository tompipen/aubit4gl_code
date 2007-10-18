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
# $Id: Makefile,v 1.46 2007-10-18 20:50:49 mikeaubury Exp $
#

ROOT    =../..

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
	LIBAUBIT4GL=-L${LIBROOT} -l${AUBITLIBFULL}
endif

ifeq "${TARGET_OS}" "solaris"
	LIBAUBIT4GL=-L${LIBROOT} -l${AUBITLIBFULL}
endif

SHARED=${SO_LDFLAGS}
PGEXTRA=


ifeq "${TARGET_OS}" "darwin"
SHARED=-bundle
PGEXTRA=-lpq `pg_config --libs` -L${LIBROOT} -laubit4gl
PGLIBS=-L${ECPG_LIBDIR} ${ECPG_LFLAGS} -lecpg -lecpg_compat -lpgtypes 
else
PGLIBS=-L${ECPG_LIBDIR} ${ECPG_LFLAGS} -lecpg -lecpg_compat -lpgtypes
endif



#Define default components to build
ifneq "$(ESQL)" "no"
	ALL	+=	${PLUGINDIR}/libESQL_INFORMIX${SO_EXT}
endif
ifneq "${Q_ESQLC}" "no"
	ALL	+=	${PLUGINDIR}/libESQL_QUERIX${SO_EXT}
endif
ifneq "$(II_SYSTEM)" ""
	ALL	+=	${PLUGINDIR}/libESQL_INGRES${SO_EXT}
endif
ifneq "${PG_ESQLC}" "no"
 	ALL	+=	${PLUGINDIR}/libESQL_POSTGRES${SO_EXT}
endif
ifneq "${SAPDB_ESQLC}" "no"
    ALL	+=	${PLUGINDIR}/libESQL_SAP${SO_EXT}
endif

ifneq "${COMSPEC}" ""
#Windows
	QUERIX_IFLAGS=-I"${QUERIXDIR}/include"
	QUERIX_LFLAGS=-L"${QUERIXDIR}/lib"
    QUERIX_LIBS="${QUERIXDIR}/lib/libesql.lib" "${QUERIXDIR}/lib/libesql.lib" \
				"${QUERIXDIR}/lib/libfgl.lib"
	#"${QUERIXDIR}/lib/libsqlc.lib"
	#"${QUERIXDIR}/bin/libfgl.dll"
else
#UNIX
	INGRES_IFLAGS=${shell cat "${INGRES_INST_PATH}/ingres/files/abflnk.opt"}
	INGRES_LFLAGS=
	INGRES_LIBS=
	QUERIX_IFLAGS=-I${QUERIXDIR}/incl
	QUERIX_LFLAGS=-L${QUERIXDIR}/lib


# Why do we need this ? 
    #STATIC=-static



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
libESQL_INFORMIX${SO_EXT}: ${PLUGINDIR}/libESQL_INFORMIX${SO_EXT}
${PLUGINDIR}/libESQL_INFORMIX${SO_EXT}: helper_funcs_informix.o
ifneq "${COMSPEC}" ""
#Windows
	$(CC) $(LDFLAGS) -g -mms-bitfields -shared -Wl,--export-all-symbols \
		$^ ${IFX_WIN_LIBS} ${LIBAUBIT4GL} -o $@
else
#Unix:
	 ${CC}  ${STATIC} -g ${SHARED} $^ -o $@ ${LIBAUBIT4GL}   -L${INFORMIXDIR}/lib -L${INFORMIXDIR}/lib/esql `esql -libs`
#Solaris:
#	libtool --mode=link gcc -shared helper_funcs.o -o libESQL_INFORMIX.so \ 
#		-L$INFORMIXDIR/lib -L$INFORMIXDIR/lib/esql  `esql -libs`
#	cp *.so .
endif

###################
libESQL_POSTGRES${SO_EXT}: ${PLUGINDIR}/libESQL_POSTGRES${SO_EXT}
${PLUGINDIR}/libESQL_POSTGRES${SO_EXT}: helper_funcs_postgresql.o
	${CC} ${STATIC} -g ${SHARED} $^ -o $@ ${PGLIBS} ${LIBAUBIT4GL} ${PGEXTRA}
# -Bstatic
#gcc: file path prefix "static" never used

###################
libESQL_SAP${SO_EXT}: ${PLUGINDIR}/libESQL_SAP${SO_EXT}
${PLUGINDIR}/libESQL_SAP${SO_EXT}: helper_funcs_sap.o
	${CC} ${STATIC} -g ${SHARED} $^ -o $@ ${LIBAUBIT4GL}

###################
libESQL_QUERIX${SO_EXT}: ${PLUGINDIR}/libESQL_QUERIX${SO_EXT}
${PLUGINDIR}/libESQL_QUERIX${SO_EXT}: helper_funcs_querix.o
	${CC} ${STATIC} -g ${SHARED} $^ -o $@ ${LIBAUBIT4GL} ${QUERIX_LFLAGS} ${QUERIX_LIBS}

###################
libESQL_INGRES${SO_EXT}: ${PLUGINDIR}/libESQL_INGRES${SO_EXT}
${PLUGINDIR}/libESQL_INGRES${SO_EXT}: helper_funcs_ingres.o
	${CC} ${STATIC} -g ${SHARED} $^ -o $@ ${LIBAUBIT4GL} ${INGRES_LFLAGS} ${INGRES_LIBS}

###################
libESQL_INFOFLEX${SO_EXT}: ${PLUGINDIR}/libESQL_INFOFLEX${SO_EXT}
INFOFLEX: ${PLUGINDIR}/libESQL_INFOFLEX${SO_EXT}
${PLUGINDIR}/libESQL_INFOFLEX${SO_EXT}: helper_funcs_infoflex.o
	${CC} ${STATIC} -g ${SHARED} $^ -o $@ ${LIBAUBIT4GL} ${INFOFLEX_LFLAGS} ${INFOFLEX_LIBS}

## ==================================================================
##                              Sub-targets
## ==================================================================

###################
#Infromix ESQL/C compiler
helper_funcs_informix.o: helper_funcs.ec
ifneq "${COMSPEC}" ""
#Windows:
#WARNING: Querix also has esqlc, and Informix esql invokes esqlc to compile .ec
#WARNING: esql will strip all quotes, and invoke esqlc with un-quoted paths
#that may contain spaces. If you get message "Input file name has invalid suffix ''"
#that is probably what happened. You must double-quote it ('"..."')
	export INFORMIXDIR=${INFORMIXDIR_UNQUOTED} ; \
		$(ESQL) -nln -dcmdl $(ESQL_FLAGS) -DDIALECT_INFORMIX -I'"${INFORMIXDIR_CSDK}/incl"' -e $<
	$(CC) $(CFLAGS) -DDIALECT_INFORMIX -I"${INFORMIXDIR_CSDK}/incl/esql" \
		-I"${INFORMIXDIR_CSDK}/incl" -c $(basename $<).c -o $@
	-@rm $(basename $<).c $(basename $<).c_*
else
#UNIX:
	export INFORMIXC=${INFORMIXC};  ${IFMX_ESQLC} ${PIC}  -nln -G -static -DDIALECT_INFORMIX -g -c -o $@ $^ -I${ROOT}/incl \
		-I"${INFORMIXDIR}/incl" 
#solaris:
#	esql -e helper_funcs.ec -I.. -I/home/aubit4gl/aubit4glsrc/incl
#	libtool --mode=compile gcc ${PIC} -I$INFORMIXDIR/incl/esql -I.. \ 
#		-I/home/aubit4gl/aubit4glsrc/incl  helper_funcs.c -c -o helper_funcs.o
endif

###################
#PostgreSQL ESQL/C compiler
helper_funcs_postgresql.o: helper_funcs.ec
	${PG_ESQLC} -C INFORMIX -t $^
	${CC} ${CFLAGS} -DPG_ESQLC_V3=$(PG_ESQLC_V3) -DDIALECT_POSTGRES -g -c -o $@ helper_funcs.c -I$(ECPG_INCDIR) ${ECPG_IFLAGS} ${LIBPQ_FE_H_IFLAGS} -I${ROOT}/incl `${ROOT}/bin/aubit-config PG_COPTS`

###################
#SAP ESQL/C compiler
helper_funcs_sap.o: helper_funcs.ec
#cpc will allways add .cpc extension to any source files specified, so we have to 
#make a copy and add .cpc extension
#As -H nocheck apparently does not work in 7.5 I had to manually rename declarations
#inside #ifdef-s so that cpc would not complain:
	cat $^ | sed -e 's/decimal \*infx\;/char dummy\[256\]\;/g' \
		-e 's/decimal \*x\;/char dummy\[256\]\;/g' > $^.cpc
#Had to disable syntax check of EXEC SQL statements, because SAP EC pre-compiler
#does not take in account #ifdef's, and then fail on syntax specific to
#another ESQL/C
#check nocheck   ::  -H nocheck              (default: -H check)
#      syntax    ::  -H syntax
#		-c = precompile only (translate to C - do not invoke C compiler)
	${SAPDB_ESQLC} -H nocheck $^ -I${ROOT}/incl -o $@ -DDIALECT_SAP ${SAPDB_INCDIR}
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
#helper_funcs_ingres.o: helper_funcs.ec
	. ${INGRES_INST_PATH}/.ingIIbash; $(INGRES_ESQLC) $^
	. ${INGRES_INST_PATH}/.ingIIbash; \
		${CC} ${CFLAGS} -DDIALECT_INGRES -g -c -o $@ $(basename $<).c -I${ROOT}/incl ${INGRES_IFLAGS}
	rm $(basename $<).c

####################
#Infoflex
helper_funcs_infoflex.o: helper_funcs_infoflex.ec
	esqlpp helper_funcs_infoflex.ec
	sqlcc ${CFLAGS} -DDIALECT_INFOFLEX -g -c -o $@ helper_funcs_infoflex.c -I${ROOT}/incl
	
show:
	@echo "INFORMIXDIR=${INFORMIXDIR}"
	@echo "INFORMIXDIR_UNQUOTED=${INFORMIXDIR_UNQUOTED}"

	
## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} -f *.o *.c ${ALL} *.cpc *.bak *.ec.w2 *.ec.w3 *.ec.pcl \
		helper_funcs.ec.cpc helper_ingres.c



# =============================== EOF ===============================
