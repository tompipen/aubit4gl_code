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
# $Id: Makefile,v 1.34 2007-06-19 17:59:10 mikeaubury Exp $
#

ROOT    =../..
LIBROOT	=${ROOT}/lib
BINROOT	=${ROOT}/bin

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              Options
## ==================================================================

CFLAGS			=${WALL}  -g -I../../incl

ifeq "${LEX}" "no"
	LEX_YY_C=lex.pregen.c
	LEX_OBJ=lex.pregen.o
	REFRESHLEX=
else
	LEX_YY_C=lex.yy.c
	LEX_OBJ=lex.yy.o
	REFRESHLEX=refresh.lex
endif


ifneq "${COMSPEC}" ""
#We are non Windows
	ifeq "${GCC_MINGW}" "yes"
		#We are using MinGW compiler
		#for features.h included from search.h in Aubit tools/ directory
		#MinGW does not have features.h
		#This is dangerous - who knows what we might pick up from 
		#there this way
		LIST_CFLAGS	=${CFLAGS} -I"${WIN_CYGPATH}/usr/include"
	else
		#We are using CygWin compiler
		ifeq "${HAVE_RPCLIB}" "1"
			#In case we have rpclib, but not using rpcgen on CygWin
			#for rpc.h and in.h
			RPC_CFLAGS	=${CFLAGS} -I"${ROOT}\tools\no_rpc\cygwin" \
				-I"${WIN_CYGPATH}\usr\include"
		endif
	endif	
endif

#I think that npcode_xdr.o is used on compile lines where its not needed 
#(shouldn't be used on any executable ending in _fgl - should be used on the 
#ones that don't)
#OBJ_COMMON      	=npcode_xdr.o common_print.o common_eval.o
OBJ_COMMON      	=common_print.o common_eval.o
OBJ_COMMON_C		=npcode_xdr.o common_io_c.o
OBJ_COMMON_A4GL		=common_io_fgl.o
OBJ_RUNNER_COMMON	=runner_main.o runner_vars.o
OBJ_C2PCODE_COMMON	=y.tab.o ${LEX_OBJ} compiler_main.o \
					compiler_optimize.o set_var.o compiler_pcode.o \
					compiler_variables.o compiler_list.o compiler_param.o
OBJ_CHECKER_COMMON	=checker_read.o

OBJ_C2PCODE_C		=${OBJ_COMMON} ${OBJ_C2PCODE_COMMON} ${OBJ_COMMON_C}
OBJ_C2PCODE_A4GL	=${OBJ_COMMON} ${OBJ_C2PCODE_COMMON} ${OBJ_COMMON_A4GL}
OBJ_CHECKER_C		=${OBJ_COMMON} ${OBJ_COMMON_C} ${OBJ_CHECKER_COMMON} 
OBJ_CHECKER_A4GL	=${OBJ_COMMON} ${OBJ_COMMON_A4GL} ${OBJ_CHECKER_COMMON}
OBJ_RUNNER_C		=${OBJ_COMMON} ${OBJ_RUNNER_COMMON} ${OBJ_COMMON_C} \
					runner_calls_c.o runner_execute_c.o
OBJ_RUNNER_A4GL		=${OBJ_COMMON} ${OBJ_RUNNER_COMMON} ${OBJ_COMMON_A4GL} \
					runner_calls_fgl.o runner_execute_fgl.o

OBJ_LINKER	=  link.o common_io_fgl.o  compiler_optimize.o common_eval.o

#open.c write.c print.c missing from CVS:
OBJ_OPEN        	=npcode_xdr.o open.o write.o print.o

CMODS           =runner_calls.c checker_read.c common_eval.c \
				common_io.c common_print.c compiler_list.c compiler_main.c \
				compiler_param.c compiler_pcode.c compiler_variables.c \
				runner_execute.c runner_main.c runner_vars.c link.c

SRCS			=Makefile npcode.x npcode_defs.h calls.h \
				fgl_calls.h std_calls.h simple.lex simple.yacc ${CMODS}

#ifneq "${COMSPEC}" ""
	LINKLIBS	=-L${LIBROOT} -l${AUBITLIBFULL}
#endif

ifeq "${DBG}" "yes"
	LINKLIBS    +=-lefence
endif

#Targets we can compile in any case
ALL             =${BINROOT}/c2pcode_fgl ${BINROOT}/checker_fgl ${BINROOT}/runner_fgl \
				${BINROOT}/link_fgl ${REFRESHLEX}
				
#Targets we can compile only if we have RPC
ALL_RPC			=${BINROOT}/c2pcode ${BINROOT}/checker ${BINROOT}/runner

#We can't make this two at all - probably obsolete:
#${BINROOT}/open_pcode - open.c write.c print.c are missing from CVS
#${LIBROOT}/libDATA_pcode${SO_EXT} - xgen not set up

ifeq "${HAVE_RPCLIB}" "1"
	ALL			+=${ALL_RPC}
endif

#we don't want -Wall in CFLAGS when compiling rpcgen generated code because it would
#give us bunch of warnings about unused varibles, that we cannot fix:
CFLAGS_RPCGEN	=$(CFLAGS:%-Wall=%)

ifeq "${HAVE_RPCLIB}" "1"
	ifeq "${USE_RPCGEN}" "0"
		#use pre-compiled files
		RPCGEN_NPCODE	=${CP} ${ROOT}/tools/cygwin/npcode.h .
	else
		RPCGEN_NPCODE	=${RPCGEN} npcode.x
	endif
endif

XGENEXE    		=${ROOT}/bin/xgen

ifneq "${COMSPEC}" ""
	#set by configure: RPCLIB_NAME=-lrpclib
	#RPCLINKLIBS=-L"D:/cygwin/lib" -lrpclib
	RPCLINKLIBS=-L"D:/cygwin/lib" ${RPCLIB_NAME}
	#-lcygwin
endif

#ifeq "${TARGET_OS}" "solaris"
	#RPCLINKLIBS=-lnsl
#endif
ifeq "${TARGET_OS}" "solaris"
	CFLAGS+=-DSOLARIS
endif

ifneq "${TARGET_OS}" "hpux"
	ifneq "${TARGET_OS}" "cygwin"
		ifneq "${GCC_MINGW}" "yes"
            #all platforms except HP-UX, CygWin and MinGW:
			DL_LINK_LIBS           =-ldl
		endif
	endif
else
            #HP-UX only:
			DL_LINK_LIBS           =-lcl
endif

#rpclib dependency - Its already gone...
#Its used for c2pcode - but not for c2pcode_fgl (or any *_fgl).
#The idea being that I can get people not involved in 4GL to help with 
#development of c2pcode without needing the aubit4gl headers and libraries


## ==================================================================
##                              Targets
## ==================================================================

all: ${ALL} ${BINROOT}/runner_fgl_wrapper
	@echo "Default targets (${ALL}) compiled."

${BINROOT}/checker: $(OBJ_CHECKER_C) npcode.h
	$(CC) -g -o $@ $(OBJ_CHECKER_C) ${LINKLIBS} ${RPCLINKLIBS} ${EXTRASYSTEMLIBS}

#use "npcode.xs.h" instead of npcode.h
#${BINROOT}/checker_fgl: $(OBJ_CHECKER_A4GL) npcode.h
${BINROOT}/checker_fgl: $(OBJ_CHECKER_A4GL) npcode.xs.h
	$(CC) -g -DRPCGEN_HEADERS -o $@ $(OBJ_CHECKER_A4GL) ${LINKLIBS}
#${RPCLINKLIBS}

${BINROOT}/c2pcode:  $(OBJ_C2PCODE_C) npcode.h
	$(CC) -g -o $@ $(OBJ_C2PCODE_C) ${LINKLIBS} ${RPCLINKLIBS} ${EXTRASYSTEMLIBS}

#${BINROOT}/c2pcode_fgl:  $(OBJ_C2PCODE_A4GL) npcode.h
${BINROOT}/c2pcode_fgl:  $(OBJ_C2PCODE_A4GL) npcode.xs.h
	$(CC) -g -DRPCGEN_HEADERS -o $@ $(OBJ_C2PCODE_A4GL) ${LINKLIBS} 
#${RPCLINKLIBS}

${BINROOT}/link_fgl:  $(OBJ_LINKER) npcode.xs.h
	$(CC) -g -o $@ $(OBJ_LINKER) ${LINKLIBS} 

${BINROOT}/runner: $(OBJ_RUNNER_C)
	$(CC) --export-dynamic -o $@ $(OBJ_RUNNER_C) ${RPCLINKLIBS} ${DL_LINK_LIBS} ${EXTRASYSTEMLIBS}

#${BINROOT}/runner_fgl: $(OBJ_RUNNER_A4GL)
${BINROOT}/runner_fgl: $(OBJ_RUNNER_A4GL)  npcode.xs.h
	$(CC) --export-dynamic -DRPCGEN_HEADERS -o $@ $(OBJ_RUNNER_A4GL) ${LINKLIBS} ${DL_LINK_LIBS} ${EXTRASYSTEMLIBS}
#${RPCLINKLIBS}

${BINROOT}/runner_fgl_wrapper:
	${CP} ./runner_fgl_wrapper $@

#------------------- probably obsolete targets -------------------------

#What is this?
libDATA_pcode${SO_EXT}: ${LIBROOT}/libDATA_pcode${SO_EXT}
${LIBROOT}/libDATA_pcode${SO_EXT} : npcode.xi.o npcode.xio.o npcode.xo.o
	$(CC) -g ${SO_LDFLAGS} $^ -o $@

#/* SYSCALLS.c:781:NC */ extern ENTRY *hsearch (ENTRY, ACTION);
#/* SYSCALLS.c:773:NC */ extern int hcreate (size_t);

#	-lrapi
#	-L"D:\cygwin\lib\w32api" -lshlwapi
#@RPCLIB_LFLAGS@ @RPCLIB_NAME@

#What is this?
#open.c is missing from CVS:
${BINROOT}/open_pcode:  ${OBJ_OPEN}
	$(CC) $^ -o $@ ${LINKLIBS}

## ==================================================================
##                              Sub-targets
## ==================================================================

runner_calls_c.o : runner_calls.c calls.h std_calls.h 
	$(CC) ${CFLAGS} -g -c $< -DSTDCALLS -o $@

runner_calls_fgl.o : runner_calls.c calls.h fgl_calls.h
	$(CC) ${CFLAGS} -DUSE_A4GL_DEBUG=1 -g -c $< -DFGLCALLS -I$(ROOT)/incl -o $@

runner_execute_c.o : runner_execute.c 
	$(CC) ${CFLAGS} -g -c $< -DSTDCALLS -o $@

runner_execute_fgl.o : runner_execute.c 
	$(CC) -DUSE_A4GL_DEBUG=1 ${CFLAGS} -g -c $< -DFGLCALLS -I$(ROOT)/incl -o $@

npcode_xdr.o: npcode_xdr.c
	$(CC) ${RPC_CFLAGS} -c -o $@ $<

common_io_c.o: common_io.c
	$(CC) -g -DRPCGEN_HEADERS -DNO_AUBITLIB ${RPC_CFLAGS} -c -o $@ $<

common_io_fgl.o: common_io.c
	$(CC) -g -DHAS_AUBITLIB ${RPC_CFLAGS} -c -o $@ $<

compiler_list.o: compiler_list.c
	$(CC) ${CFLAGS} ${LIST_CFLAGS} -c -o $@ $<

ifeq "${HAVE_RPCLIB}" "1"
npcode_xdr.c npcode.h : npcode.x
	${RPCGEN_NPCODE}
endif	

#use xgen rather than rpcgen then use "npcode.xs.h" instead of npcode.h
npcode.xs.h npcode.xi.c: npcode.x ${XGENEXE}
	${XGENEXE} $<

#for libDATA_pcode - PROBABLY OBSOLETE
#npcode.xi.o npcode.xio.o npcode.xo.o: npcode.x ${XGENEXE}
#	${XGENEXE} $< something

ifeq "${HAVE_RPCLIB}" "1"
y.tab.o : simple.yacc npcode.h
else
y.tab.o : simple.yacc npcode.xs.h
endif
#bison -y -r all -d -v $^
# add -t for yacc debugging...
ifneq "${BISON}" "no"
	${BISON} -y -t -d -v $<
else
	@echo "AutoConf did not detect valid version of Bison on your system"
	@exit 1
endif
	$(CC) ${CFLAGS} -g -c y.tab.c

lex.yy.c: simple.lex
#	flex -i $^
	${LEX} -i $<

${XGENEXE}:
	${MAKE} -C ${ROOT}/compilers/xgen

## ==================================================================
##                              Testing
## ==================================================================

#runit.c: runit.4gl
#	A4GL_FAKELEXTYPE=C 4glc runit.4gl

mine.4pe: hello.c simple
	simple $<

## ==================================================================
##                              Archives packaging
## ==================================================================

src.tgz: $(SRCS)
	tar cvzf $@ $(SRCS)

bin: make_pcode.c main.c simple.yacc simple.lex pcode.h variable.c
	tar cvf pcode.tar $^
	gzip -9 pcode.tar

## ==================================================================
##                              Dependencies
## ==================================================================

#make_pcode.o y.tab.o main.o variable.o param.o runner_main.o: npcode.h

ifeq "${HAVE_RPCLIB}" "1"
${OBJ_C2PCODE_C} ${OBJ_CHECKER_C} ${OBJ_RUNNER_C}: npcode.h
endif
${OBJ_C2PCODE_A4GL} ${OBJ_CHECKER_A4GL} ${OBJ_RUNNER_A4GL}: npcode.xs.h

## ==================================================================
##                         Other Targets
## ==================================================================

splint: lclint
lclint: $(CMODS)
	${LCLINTERR}${LCLINTEXE} ${LCLINTFLAGS} $(LCLINT_CFLAGS) $(CMODS) > ${LCLINTLOG} ${LCLINTLOGCMD}
	${CAT} ${LCLINTLOG} >> ${ROOT}/${LCLINT_GLOBAL_LOG}
	@echo "see ${LCLINTLOG} for results"

show:
	@echo "HAVE_RPCLIB=${HAVE_RPCLIB}"
	@echo "USE_RPCGEN=${USE_RPCGEN}"


refresh.lex: lex.yy.c
	cp lex.yy.c lex.pregen.c
	

## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} *.o y.tab.c lex.yy.c ${ALL} ${ALL_RPC} y.output y.tab.h *.bak \
	npcode.h npcode.xs.h npcode_xdr.c *.x.h *.xi.c *.xio.c *.xo.c *.xs.h *~ 
	
#set_var.c 

# =============================== EOF ===============================


