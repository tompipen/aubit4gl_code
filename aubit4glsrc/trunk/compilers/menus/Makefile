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
# $Id: Makefile,v 1.1 2005-03-25 12:48:31 afalout Exp $
#

ROOT        =../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

override NOINCL=0

## ==================================================================
##                              Options
## ==================================================================

ALL				=${ROOT}/bin/mcompile ${ROOT}/bin/mdecompile

#Should be obsolete - using xgen instead of rpcgen
#ifeq "${USE_RPCGEN}" "0"
#	RPCGEN      =${CP} ${ROOT}/tools/cygwin/menu_x_xdr.c ${ROOT}/tools/cygwin/menu_x.h .
#else
#	RPCGEN      =${RPCGEN} menu_x.x
#endif

C_LOCAL_IFLAGS  =-I. -I${ROOT}/lib/libincl -I../fcompile
#FIXME: this compiler should not depend on RPC:
#CFLAGS		   +=${C_LOCAL_IFLAGS} ${RPCLIB_INCLUDE}
CFLAGS		   +=${C_LOCAL_IFLAGS}
LCLINT_CFLAGS   =${C_IFLAGS} ${C_LOCAL_IFLAGS}

## ==================================================================
##                              Source files
## ==================================================================

SRC_COMMON      =mcompile.c
#menuwrite.c and menu_x_xdr.c are now part of libMENU_XDR
#MENU_X_XDR		=menu_x_xdr.c

SOURCES.yacc 	=menu.yacc
SOURCES.lex 	=menu.lex
TARGETS.c 		=y.tab.c
DECOMPILE		=decompile.c
OBJS_DECOMPILE	=$(DECOMPILE:%.c=%.o)
CMODS           =${SRC_COMMON} $(TARGETS.c)
OBJECTS 		=$(CMODS:%.c=%.o)


ifeq "${YACC}" "no"
	LEX_YY_C	=${ROOT}/tools/no_yacc/cygwin/compilers/menus/lex.yy.c
	Y_TAB_C_DEP	=${ROOT}/tools/no_yacc/cygwin/compilers/menus/y.tab.c
else
	LEX_YY_C	=lex.yy.c
	Y_TAB_C_DEP=$(SOURCES.yacc) ${LEX_YY_C}
endif


## ==================================================================
##                             Targets
## ==================================================================

all: $(ALL)
	@echo "Default targets ($(ALL)) successfully compiled"

${ROOT}/bin/mcompile: $(OBJECTS)
	${LD_EXE} -L${ROOT}/lib -o $@ $^ ${AUBIT_LIB}

${ROOT}/bin/mdecompile: ${OBJS_DECOMPILE}
	${LD_EXE} -L${ROOT}/lib -o $@ $^ ${AUBIT_LIB}

## ==================================================================
##                             Sub Targets
## ==================================================================

#menu_x_xdr.c:  menu_x.x
#	${RPCGEN}

#menu_x.h: menu_x.x
#	${RPCGEN}

y.tab.c: ${Y_TAB_C_DEP}
ifeq "${YACC}" "no"
	${CP} ${Y_TAB_C_DEP} .
else
	${YACC} -v  $(SOURCES.yacc)
endif

lex.yy.c: $(SOURCES.lex)
ifeq "${LEX}" "no"
	${CP} ${LEX_YY_C} .
else
	${LEX} $(SOURCES.lex)
endif

#rpc:
#	${RPCGEN}

XGENEXE    		=${ROOT}/bin/xgen
	
#use xgen rather than rpcgen then use "menu_x.xs.h" instead of menu_x.h
menu_x.xs.h menu_x.xi.c: menu_x.x ${XGENEXE}
	${XGENEXE} $<
	
${XGENEXE}:
	${MAKE} -C ${ROOT}/compilers/xgen
	
## ==================================================================
##                             Dependencies
## ==================================================================

y.tab.o: lex.yy.c
#rpc: ${MENU_X_XDR}
#rpc: menu_x_xdr.c

#FIXME: mcompile should not depend on rpcgen:
#menu_x.h=rpcgen menu_x.xs.h=xgen
#mcompile.o: menu_x.h menu_x.xs.h
mcompile.o: menu_x.xs.h

## ==================================================================
##                          Clean targets
## ==================================================================

clean: clean.xgen
	$(RM) mcompile mcompile-noodbc $(OBJECTS) $(TARGETS.c) *.BAK *.delta core *~ *.ln \
	*.output lex.yy.c *.err *.out decompiler menu_x_xdr.c menu_x.h \
	*.bak .*.bak *.exe mdecompile *.o *.dll *.a lclint.log

#Clean files created by xgen
clean.xgen:
	${RM} menu_x.x.h menu_x.xs.h menu_x.xi.c menu_x.xio.c menu_x.xo.c
	
## ==================================================================
##                           Other targets
## ==================================================================

splint: lclint
lclint: $(CMODS)
	${LCLINTERR}${LCLINTEXE} ${LCLINTFLAGS} $(LCLINT_CFLAGS) $(CMODS) > ${LCLINTLOG} ${LCLINTLOGCMD}
	${CAT} ${LCLINTLOG} >> ${ROOT}/${LCLINT_GLOBAL_LOG}
	@echo "see ${LCLINTLOG} for results"


#---------------------------- EOF -----------------------------------
