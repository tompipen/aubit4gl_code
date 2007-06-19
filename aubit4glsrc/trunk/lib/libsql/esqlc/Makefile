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
# $Id: Makefile,v 1.17 2007-06-19 08:00:00 mikeaubury Exp $
#

ROOT		=../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              Options
## ==================================================================

SRC					=esql.ec
SRC_C				=${SRC:.ec=.c}
OBJS				=${SRC_C:.c=.o}

CFLAGS_INFX			+=${CFLAGS} -I.. -I${LIBROOT} -I${ROOT}/compilers/fcompile \
					-I${INFORMIXDIR} -I${INFORMIXDIR}/incl/esql \
					-I$(AUBITDIR)/incl -g ${FPIC}

CFLAGS_NOTINFX			+=${CFLAGS} -I.. -I${LIBROOT} -I${ROOT}/compilers/fcompile \
					-I$(AUBITDIR)/incl -g ${FPIC}

ESQL_INCLPATH		=-I.. -I${LIBROOT} -I${ROOT}/compilers/fcompile \
					-I$(AUBITDIR)/incl ${C_IFLAGS}

ifneq "${INFORMIXDIR}" ""
	ESQL_INCLPATH	+=-I${INFORMIXDIR}
endif

LD_LFLAGS_INFX           =-L$(INFORMIXDIR)/lib -L $(INFORMIXDIR)/lib/esql \
                    -L$(INFORMIXDIR)/lib/cli -g
LD_LFLAGS_NOTINFX        = -g

ifneq "$(findstring esql,${PLUGIN_STATIC})" ""
	
	#Remove any -shared flags and add the -static one:
	SO_LDFLAGS      :=-static $(filter-out -shared,${SO_LDFLAGS})

	#Must include libaubit4gl when linking statically, since statically linked
    #libs cannot have unresolved symbols at link-time. This one still has to be
    #linked in shared mode, since we don't make libaubit4gl.a (Thank God...)
	LD_POSTFLAGS    =-L${LIBROOT} -shared -l${AUBITLIBFULL}

	#Don't know why, but -static flag was not enough, I still got everything
	#linked shared - so we had to explicitly name objects to link statically:
    #(Probably because we use gcc not ldd directly to do linking, and gcc
    #found the -shared flag at the end where we need it for libaubit4gl)

    #Separate Informix from non-informix libraries:
	ONLY_IFX_LIBS   :=$(filter -lif%,${IFX_LIBS})
    NON_IFX_LIBS    :=$(filter-out -lif%,${IFX_LIBS})

    #Change -l notation into full object file name:
	ONLY_IFX_LIBS	:=$(subst -lif,libif,${ONLY_IFX_LIBS})
	ONLY_IFX_LIBS	:=$(addsuffix .a,${ONLY_IFX_LIBS})

    #Seaparate libs in lib/ from libs in lib/esql/
	IFXLIBS_LIB     :=$(filter libifasf.a,${ONLY_IFX_LIBS})
	IFXLIBS_LIB_ESQL:=$(filter-out libifasf.a,${ONLY_IFX_LIBS})

	#Add full path:
	IFXLIBS_LIB		:=$(addprefix $(INFORMIXDIR)/lib/,${IFXLIBS_LIB})
	IFXLIBS_LIB_ESQL:=$(addprefix $(INFORMIXDIR)/lib/esql/,${IFXLIBS_LIB_ESQL})

	#Final result:
	IFX_LIBS		:=${IFXLIBS_LIB} ${IFXLIBS_LIB_ESQL} ${NON_IFX_LIBS} -lifasf
endif


#TODO: remove all this - its obsolete:
ifdef xxxxCOMSPECxxxx
    #since we are using ESQL/C compiler, and then MSVC, this define is not automatic:
	#ESQL_FLAGS		=-D__CYGWIN__ -e
	ESQL_FLAGS		=-e
	# -e, -p          Preprocess only (no compilation or linking).

    #strange things happen to paths when invoking native Windows programs from CygWin make,
    #so we need to use explicit backslash, even though slash is understood by most
    #Windows programs:
	ESQL_INCLPATH	+=-I${LIBROOT} 
	#-I${ROOT}\compilers\fcompile

    #FIXME!!!!! I'm using variable named TMP somewhere!!!!
	#Should be OK now
	#TMP=/cygdrive/d/DOCUME~1/ADMINI~1/LOCALS~1/Temp
    #PWD=
    #export TMP
    #export PWD

	#IFX_CSDK_DIR=/CSDK
	INFORMIXDIR_CSDK	=${INFORMIXDIR_UNQUOTED}${IFX_CSDK_DIR}
	IFX_LIBS="${INFORMIXDIR_CSDK}\bin\isqlt09a.dll"  "${INFORMIXDIR_CSDK}\bin\igl4n304.dll" \
		"${INFORMIXDIR_CSDK}\bin\iglxn304.dll"  "${INFORMIXDIR_CSDK}\bin\igo4n304.dll"

else
#    ESQL_INCLPATH	=-I${LIBROOT} -I${ROOT}/compilers/fcompile
	
endif

ALL				=${PLUGINDIR}/libSQL_esql${SO_EXT}

#C pre-processor flags:
CPP_FLAGS=-I${ROOT}/incl -I.. -P
#-P - line numbers - cpc don't like them
#-C - keep comments

#SAP DB esql pre-compiler flags:
CPC_FLAGS=-H nocheck -c
#-u dba,dba -d TST

#SAP DB esql linker:
CPCLNK=${SAPDBROOT}/interfaces/precompiler/bin/cpclnk

ifneq "${COMSPEC}" ""
	LIBAUBIT4GL=-L${LIBROOT} -l${AUBITLIBFULL}
endif

PGLIBS=-L${ECPG_LIBDIR} ${ECPG_LFLAGS} -lecpg -lecpg_compat -lpgtypes

ifneq "${COMSPEC}" ""
	QUERIX_IFLAGS=-I"${QUERIXDIR}/include"
    #-I"E:/Program files/W2000/QueriX/include"
	QUERIX_LFLAGS=-L"${QUERIXDIR}/lib"
    QUERIX_LIBS="${QUERIXDIR}/lib/libesql.lib" "${QUERIXDIR}/lib/libesql.lib" \
				"${QUERIXDIR}/lib/libfgl.lib"
	#"${QUERIXDIR}/lib/libsqlc.lib"
	#"${QUERIXDIR}/bin/libfgl.dll"
else
	QUERIX_IFLAGS=-I${QUERIXDIR}/incl
	QUERIX_LFLAGS=-L${QUERIXDIR}/lib
    STATIC=-static
    QUERIX_LIBS=-lesql
endif

ifeq "${TARGET_OS}" "solaris"
	ESQL_FLAGS+=${PIC}
endif

ifeq "${TARGET_OS}" "linux"
	ESQL_FLAGS+=${PIC}
endif

ifdef COMSPEC
	#CFLAGS=-g -O2 -Wall -D_REENTRANT -DIFX_THREAD -I../../../incl -I..
	#ESQL_SOMETHING=esql
	ESQL_FLAGS=-thread
	LDFLAGS=
	#IFX_CSDK_DIR=/CSDK
	INFORMIXDIR_CSDK	=${INFORMIXDIR_UNQUOTED}${IFX_CSDK_DIR}
	IFX_LIBS="${INFORMIXDIR_CSDK}\bin\isqlt09a.dll"  "${INFORMIXDIR_CSDK}\bin\igl4n304.dll" \
		"${INFORMIXDIR_CSDK}\bin\iglxn304.dll"  "${INFORMIXDIR_CSDK}\bin\igo4n304.dll"
	LINKLIBS=-L../../ -l${AUBITLIBFULL}
	CFLAGS+=-D_REENTRANT -DIFX_THREAD -I"${INFORMIXDIR_CSDK}\incl\esql"	
endif

ifneq "${COMSPEC}" ""
#PLEASE DO NOT USE HARD-CODED PATHS UNDER --ANY-- CIRCUMSTANCES! IT'S POINTLESS!
#	ECPG_INCDIR			:=c:/progra~1/postgr~1/8.1/include
	ECPG_INCDIR			:=$(shell echo "${ECPG_INCDIR}" | tr '\\' '/')
#$(shell echo "${ECPG_INCDIR}" | tr '\\' '/')
	LIBPQ_FE_H_IFLAGS	:=$(shell echo "${LIBPQ_FE_H_IFLAGS}" | tr '\\' '/')
	ECPG_IFLAGS			:=$(shell echo "${ECPG_IFLAGS}" | tr '\\' '/')
	PGLIBS				:=$(shell echo "${PGLIBS}" | tr '\\' '/')
endif	


.SUFFIXES: .ec .o .c

## ==================================================================
##                              Targets
## ==================================================================

ALL: ${ALL}

#remove this once esql_compatible.ec is finished:

##################
#ESQL/C database plug-in compiled with Informix ESQL/C compiler:
libSQL_esql${SO_EXT}: ${PLUGINDIR}/libSQL_esql${SO_EXT}
${PLUGINDIR}/libSQL_esql${SO_EXT}: ${SRC}
#	cpp ${CPP_FLAGS} $^ -D__IFX__  > ifx_$^
ifneq "${COMSPEC}" ""
#Windows
#	$(ESQL_SOMETHING) $(ESQL_FLAGS) -e $<
	export INFORMIXDIR=${INFORMIXDIR_UNQUOTED} ; \
		${IFMX_ESQLC} $(ESQL_FLAGS) -e $<
	$(CC) $(CFLAGS_INFX) -c $(basename $<).c -o $(basename $<).o
	-@rm $(basename $<).c $(basename $<).c_*
	$(CC) $(LFLAGS_INFX) -mms-bitfields -shared -Wl,--export-all-symbols $(basename $<).o ${IFX_LIBS} ${LINKLIBS} -o $@
else
#UNIX
	export INFORMIXC=${INFORMIXC}; \
		${IFMX_ESQLC} -g -c $^ ${ESQL_FLAGS} ${WALL} ${ESQL_INCLPATH} ${C_DFLAGS}
	${LD} ${LD_LFLAGS_INFX} $(SO_LDFLAGS) -g  esql.o ${IFX_LIBS} -o $@ ${LD_POSTFLAGS}
endif


INFOFLEX: ${PLUGINDIR}/libSQL_infoflex${SO_EXT}
${PLUGINDIR}/libSQL_infoflex${SO_EXT}:
	esqlpp esql_infoflex.ec
	sqlcc -c -o esql_infoflex.o esql_infoflex.c
	sqlcc ${LD_LFLAGS_NOTINFX} $(SO_LDFLAGS) -g  esql_infoflex.o -o $@ ${LD_POSTFLAGS}


#------------------------ esql_compatible.ec ----------------------------

##################
#ESQL/C database plug-in compiled with Informix ESQL/C compiler:
#${PLUGINDIR}/libSQL_esqlI${SO_EXT}: ${PLUGINDIR}/libSQL_esqlI${SO_EXT}
${PLUGINDIR}/libSQL_esqlI${SO_EXT}: esql_compatible.ec
	cpp ${CPP_FLAGS} $^ -D__IFX__  > ifx_$^
	export INFORMIXC=${INFORMIXC}; ${IFMX_ESQLC} -c ifx_$^ ${ESQL_FLAGS} \
		${ESQL_INCLPATH} ${C_DFLAGS}
	${LD} ${LD_LFLAGS_INFX} $(SO_LDFLAGS) ifx_esql.o ${IFX_LIBS} -o $@ ${LD_POSTFLAGS}

##################
#Querix ESQL/C compiler:
#HEAD= > /tmp/scr.scr 2>&1; head /tmp/scr.scr
HEAD_NOWARN= 2>&1 | grep -v "warning:" | grep -v "In function" > /tmp/scr.scr ; head /tmp/scr.scr
BREAK=@exit 1
#${PLUGINDIR}/libSQL_esqlQ${SO_EXT}: ${PLUGINDIR}/libSQL_esqlQ${SO_EXT}
${PLUGINDIR}/libSQL_esqlQ${SO_EXT}: esql_compatible.ec
##must remove .c file or .ec will not get recompiled
	rm -f q_$(basename $<).c
	cpp ${CPP_FLAGS} $^ -D__QUERIX__ -D__QUERIX_FIX__ > q_$^
##-DNEWERA
#need quotes because of the path on Windows
	"${Q_ESQLC}" q_$^ ${HEAD}
#	${BREAK}
	${CC} -g -c q_$(basename $<).c -o q_$(basename $<).o -I${ROOT}/incl ${QUERIX_IFLAGS} ${HEAD_NOWARN}
#	${BREAK}
	${CC} -shared -g q_$(basename $<).o -o $@ ${QUERIX_LFLAGS} ${QUERIX_LIBS}
#	rm -f q_$(basename $<).c

##################
#SAP DB ESQL/C compiler:
PRECIOUS : sap_esql_compatible.ec.o
#${PLUGINDIR}/libSQL_esqlSAP${SO_EXT}: ${PLUGINDIR}/libSQL_esqlSAP${SO_EXT}
${PLUGINDIR}/libSQL_esqlSAP${SO_EXT}: esql_compatible.ec
#cpc will allways add .cpc extension to any source files
	cpp ${CPP_FLAGS} $^ -D__SAP__  -I${SAPDBROOT}/interfaces/precompiler/incl > sap_$^.cpc
	${SAPDB_ESQLC} ${CPC_FLAGS} sap_$^ -I${ROOT}/incl 2>&1
	${CC} -c ${SAPDB_INCDIR} -I${ROOT}/incl -o sap_$^.o sap_$^.c
#-I${SAPDBROOT}/interfaces/precompiler/incl
#	rm sap_$^.cpc
#	${CPCLNK} -shared sap_esql_compatible.ec.o
	${CC} -shared sap_$^.o -o $@ ${SAPDB_LIBDIR} -lpcrl -lsqlca -ldl
#-L${SAPDBROOT}/interfaces/precompiler/lib

##################
#PostgreSQL ESQL/C compiler:
#${PLUGINDIR}/libSQL_esqlPG${SO_EXT}: ${PLUGINDIR}/libSQL_esqlPG${SO_EXT}
${PLUGINDIR}/libSQL_esqlPG${SO_EXT}: esql_compatible.ec

#	cpp ${CPP_FLAGS} $^ -D__PG__ -D__PG_FIX__ -I/opt/ecpg-cvs/include > pg_$^
	cpp ${CPP_FLAGS} $^ -D__PG__ -D__PG_FIX__ ${PGSQL_INCLUDE} > pg_$^
#	${PG_ESQLC} -I/opt/ecpg-cvs/include -C INFORMIX -t pg_$^
	${PG_ESQLC} ${PGSQL_INCLUDE} -C INFORMIX -t pg_$^
#	${CC} ${STATIC} -g --shared $^ -o $@ ${PGLIBS} ${LIBAUBIT4GL}

##################
#Plexus also has esql/c compiler (c:\xdp32\esqlc.exe)


###################
#Simple Informix ESQL/C plug-in, based on 'simple' template
#FIXME: does not compile
#FIXME: Not sure what is this good for, when we already have working one?
#${PLUGINDIR}/libSQL_c_esql${SO_EXT}: ${PLUGINDIR}/libSQL_c_esql${SO_EXT}
${PLUGINDIR}/libSQL_c_esql${SO_EXT}: esql_simple_infx.ec
	export INFORMIXC=${INFORMIXC}; ${IFMX_ESQLC} -c $^ ${ESQL_FLAGS} ${ESQL_INCLPATH} ${C_DFLAGS}
	${LD} ${LD_LFLAGS_NOTINFX} $(SO_LDFLAGS) $(basename $<).o ${IFX_LIBS} -o $@ ${LD_POSTFLAGS}


###################
#Simple PG - ecpg NOT in Informix compatible mode!!! Based on 'simple' template
#INTENDED TO be used for 4glc to resolve variables define as LIKE when compiling to 
#EC with POSTGRES dialect - DOES NOT HAVE IMPLEMENTED FULL FUNCTIONALITY OF
#DRIVER NEEDED TO RUN PROGRAMS.
#Seems abandoned - see postgresql/simple.c
#${PLUGINDIR}/libSQL_c_ecpg${SO_EXT}: ${PLUGINDIR}/libSQL_c_ecpg${SO_EXT}
libSQL_c_ecpg: ${PLUGINDIR}/libSQL_c_ecpg${SO_EXT}
${PLUGINDIR}/libSQL_c_ecpg${SO_EXT}: esql_simple_ecpg.ec
#	LD_RUN_PATH=${LD_RUN_PATH}:${POSTGRESDIR}/lib; export LD_RUN_PATH
	${PG_ESQLC} -ct $^
	${CC} -I$(ECPG_INCDIR) ${CFLAGS_NOTINFX} -c -I. -I.. -I${ROOT}/incl  ${LIBPQ_FE_H_IFLAGS} \
		${ECPG_IFLAGS} $(basename $<).c -o $(basename $<).o
	${CC} ${CFLAGS_NOTINFX} -shared -o $@ $(basename $<).o -L${LIBROOT} ${PGLIBS} ${LIBAUBIT4GL}

test_ecpg_config:
	echo pg_esqlc=${PG_ESQLC} 
	echo ECPG_INCDIR=${ECPG_INCDIR} 
	echo CFLAGS=${CFLAGS} 
	echo ECPG_IFLAGS=${ECPG_IFLAGS} 

## ==================================================================
##                              Sub-Targets
## ==================================================================

#Debugging: show current settings od make variables
show:
ifdef COMSPEC
	@echo "---------------------- Output of 'set' ----------------------------"
	set
	@echo "---------------------- Above: output of 'set' ----------------------------"
endif
	@echo "ONLY_IFX_LIBS=${ONLY_IFX_LIBS}"
	@echo "IFXLIBS_LIB=${IFXLIBS_LIB}"
	@echo "IFXLIBS_LIB_ESQL=${IFXLIBS_LIB_ESQL}"
	@echo "NON_IFX_LIBS=${NON_IFX_LIBS}"
	@echo "INFORMIXDIR=${INFORMIXDIR}"
ifdef COMSPEC
	@echo "INFORMIXDIR from set=`set | grep INFORMIXDIR`"
endif
	@echo "INFORMIXDIR_CSDK=${INFORMIXDIR_CSDK}"
	@echo "INFORMIXDIR_UNQUOTED=${INFORMIXDIR_UNQUOTED}"
	@echo "IFX_CSDK_DIR=${IFX_CSDK_DIR}"
	@echo "IFX_LIBS=${IFX_LIBS}"

## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} *.o  *.bak *.c *.obj *.c_ *.a *.dll *.lnk *.map *.exp \
	*.lib .\#* ifx_* pg_* sap_* q_* ${PLUGINDIR}/libSQL_esql${SO_EXT} \
    	${PLUGINDIR}/libSQL_esqlPG${SO_EXT} ${PLUGINDIR}/libSQL_esqlSAP${SO_EXT} \
	${PLUGINDIR}/libSQL_esqlI${SO_EXT} \
	${PLUGINDIR}/libSQL_esqlQ${SO_EXT} \
	${PLUGINDIR}/libSQL_c_esql${SO_EXT}  \
	${PLUGINDIR}/libSQL_c_ecpg${SO_EXT} \
	*.pcl *.lst *~ ${ALL}

#------------------------------- EOF -------------------------------
