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
# $Id: Makefile,v 1.12 2003-10-20 12:18:59 mikeaubury Exp $
#

ROOT    =../..
LIBROOT	=${ROOT}/lib
BINROOT	=${ROOT}/bin

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                              Options
## ==================================================================

CFLAGS			=-Wall -O2 -g

ifneq "${COMSPEC}" ""
	#for features.h
	LIST_CFLAGS	=${CFLAGS} -I"D:/cygwin/usr/include"
	#for rpc.h and in.h
	RPC_CFLAGS	=${CFLAGS} -I"D:\cygwin\usr\src\aubit\aubit4glsrc\tools\no_rpc\cygwin" -I"d:\cygwin\usr\include"
endif



OBJ_COMMON      =npcode_xdr.o  common_print.o common_eval.o

OBJ_RUNNER_COMMON=runner_main.o runner_execute.o runner_vars.o ${OBJ_COMMON}

OBJ_C2PCODE_C		=y.tab.o lex.yy.o compiler_main.o compiler_param.o \
				compiler_pcode.o compiler_variables.o compiler_list.o \
				${OBJ_COMMON} common_io_c.o

OBJ_C2PCODE_A4GL		=y.tab.o lex.yy.o compiler_main.o compiler_param.o \
				compiler_pcode.o compiler_variables.o compiler_list.o \
				${OBJ_COMMON} common_io_fgl.o

OBJ_CHECKER_C		=checker_read.o ${OBJ_COMMON} common_io_c.o
OBJ_CHECKER_A4GL		=checker_read.o ${OBJ_COMMON} common_io_fgl.o

OBJ_RUNNER_C	=runner_calls_c.o ${OBJ_RUNNER_COMMON} common_io_c.o

OBJ_RUNNER_A4GL	=runner_calls_fgl.o ${OBJ_RUNNER_COMMON} common_io_fgl.o

#open.c write.c print.c missing from CVS:
OBJ_OPEN        =npcode_xdr.o open.o write.o print.o

CMODS           =runner_calls.c checker_read.c common_eval.c \
				common_io.c common_print.c compiler_list.c compiler_main.c \
				compiler_param.c compiler_pcode.c compiler_variables.c \
				runner_execute.c runner_main.c runner_vars.c

SRCS			=Makefile npcode.x npcode_defs.h calls.h \
				fgl_calls.h std_calls.h simple.lex simple.yacc ${CMODS}

#ifeq "${TARGET_OS}" "cygwin"
	LINKLIBS	=-L${LIBROOT} -laubit4gl
#endif

ifeq "${DBG}" "yes"
	LINKLIBS    +=-lefence
endif

ALL             =${BINROOT}/c2pcode ${BINROOT}/c2pcode_fgl ${BINROOT}/checker  ${BINROOT}/checker_fgl ${BINROOT}/runner \
				${BINROOT}/runner_fgl
#open.c is missing from CVS:
#${BINROOT}/open_pcode

#xgen not set up:
#${LIBROOT}/libDATA_pcode${SO_EXT}

#we don't want -Wall in CFLAGS when compiling rpcgen generated code because it would
#give us bunch of warnings about unused varibles, that we cannot fix:
CFLAGS_RPCGEN	=$(CFLAGS:%-Wall=%)

#MOVE TO Makefile-common:
#RPCGEN=@RPCGEN@
RPCGEN=rpcgen

ifeq "${USE_RPCGEN}" "0"
	#use pre-compiled files
	RPCGEN_NPCODE	=${CP} ${ROOT}/tools/cygwin/npcode.h .
else
	RPCGEN_NPCODE	=${RPCGEN} npcode.x
endif

XGENEXE    		=${ROOT}/bin/xgen


ifneq "${COMSPEC}" ""
	RPCLINKLIBS=-L"D:/cygwin/lib" -lrpclib
	#-lcygwin
endif

## ==================================================================
##                              Targets
## ==================================================================

all: ${ALL}
	@echo "Default targets (${ALL}) compiled."

${BINROOT}/checker: $(OBJ_CHECKER_C) npcode.h
	$(CC) -g -o $@ $(OBJ_CHECKER_C) ${LINKLIBS} ${RPCLINKLIBS}


${BINROOT}/checker_fgl: $(OBJ_CHECKER_A4GL) npcode.h
	$(CC) -g -o $@ $(OBJ_CHECKER_A4GL) ${LINKLIBS} -laubit4gl


${BINROOT}/c2pcode:  $(OBJ_C2PCODE_C) npcode.h
	$(CC) -o $@ $(OBJ_C2PCODE_C) ${LINKLIBS} ${RPCLINKLIBS}

${BINROOT}/c2pcode_fgl:  $(OBJ_C2PCODE_A4GL) npcode.h
	$(CC) -o $@ $(OBJ_C2PCODE_A4GL) ${LINKLIBS} -laubit4gl

#/* SYSCALLS.c:781:NC */ extern ENTRY *hsearch (ENTRY, ACTION);
#/* SYSCALLS.c:773:NC */ extern int hcreate (size_t);

#	-lrapi
#	-L"D:\cygwin\lib\w32api" -lshlwapi
#@RPCLIB_LFLAGS@ @RPCLIB_NAME@

#open.c is missing from CVS:
${BINROOT}/open_pcode:  ${OBJ_OPEN}
	$(CC) $^ -o $@ ${LINKLIBS}

${LIBROOT}/libDATA_pcode${SO_EXT} : npcode.xi.o npcode.xio.o npcode.xo.o
	$(CC) -g -shared $^ -o $@

${BINROOT}/runner: $(OBJ_RUNNER_C)
	$(CC) -O2 -o $@ $(OBJ_RUNNER_C) ${RPCLINKLIBS} -ldl

${BINROOT}/runner_fgl: $(OBJ_RUNNER_A4GL)
	$(CC) -O2 -o $@ $(OBJ_RUNNER_A4GL) ${LINKLIBS} ${RPCLINKLIBS} -ldl


## ==================================================================
##                              Sub-targets
## ==================================================================


npcode.xi.o npcode.xio.o npcode.xo.o: npcode.x ${XGENEXE}
	${XGENEXE} $< something

runner_calls_c.o : runner_calls.c calls.h std_calls.h 
	$(CC) ${CFLAGS} -g -c runner_calls.c -DSTDCALLS -o $@

runner_calls_fgl.o : runner_calls.c calls.h fgl_calls.h
	$(CC) ${CFLAGS} -g -c runner_calls.c -DFGLCALLS -I$(ROOT)/incl -o $@

npcode_xdr.o: npcode_xdr.c
	$(CC) ${RPC_CFLAGS} -c -o $@ $^

common_io_c.o: common_io.c
	$(CC) -DNO_AUBITLIB ${RPC_CFLAGS} -c -o $@ $^

common_io_fgl.o: common_io.c
	$(CC) -DHAS_AUBITLIB ${RPC_CFLAGS} -c -o $@ $^

compiler_list.o: compiler_list.c
	$(CC) ${LIST_CFLAGS} -c -o $@ $^

npcode.h : npcode.x
	${RPCGEN_NPCODE}

y.tab.o : simple.yacc npcode.h
#bison -y -r all -d -v $^
# add -t for yacc debugging...
	bison  -y -t -d -v $<
	$(CC) ${CFLAGS} -g -c y.tab.c

lex.yy.c: simple.lex
	flex -i $^

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

make_pcode.o y.tab.o main.o variable.o param.o runner_main.o: npcode.h

## ==================================================================
##                         Other Targets
## ==================================================================

splint: lclint
lclint: $(CMODS)
	${LCLINTERR}${LCLINTEXE} ${LCLINTFLAGS} $(LCLINT_CFLAGS) $(CMODS) > ${LCLINTLOG} ${LCLINTLOGCMD}
	${CAT} ${LCLINTLOG} >> ${ROOT}/${LCLINT_GLOBAL_LOG}
	@echo "see ${LCLINTLOG} for results"

## ==================================================================
##                              Clean
## ==================================================================

clean:
	${RM} *.o y.tab.c lex.yy.c ${ALL} y.output y.tab.h *.bak \
	npcode.h npcode_xdr.c *.x.h *.xi.c *.xio.c *.xo.c *.xs.h

# =============================== EOF ===============================
