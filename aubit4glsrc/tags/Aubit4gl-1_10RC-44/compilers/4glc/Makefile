# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0   lib/libgui makefile        |
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
# $Id: Makefile,v 1.42 2008-11-17 11:02:42 mikeaubury Exp $
#

ROOT		=../..
LIBROOT		=${ROOT}/lib

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                   Source files
## ==================================================================

WANTKW_C		= rules/generated/mk_states.c
Y_OUTPUT		= rules/generated/y.output

ifeq "${YACC}" "no"
	GENRULES    =${ROOT}/tools/no_yacc/cygwin/compilers/4glc/rules/generated
	Y_TAB_C		=${GENRULES}/y.tab.c
	Y_TAB_H		=${GENRULES}/y.tab.h
	CFLAGS		+=-I${ROOT}/tools/no_yacc/cygwin/compilers/4glc
	Y_OUTPUT	=
else
	GENRULES    =rules/generated
	Y_TAB_C		=${GENRULES}/y.tab.c
	Y_TAB_H		=${GENRULES}/y.tab.h
endif

ifeq "${GCC_MINGW}" "yes"
	CFLAGS		+=-I${ROOT}/tools/getopt
endif

#temp. workarounds for older versions of bizon y.output format:
HOSTNAME_SPEC   =xxaptiva

ifeq "${HOSTNAME}" "${HOSTNAME_SPEC}"
	#WANTKW_C	=/tmp/4glc/wantkw.c
	Y_OUTPUT	=/xxtmp/4glc/rules/generated/y.output
endif

CMODS_EXE       =4glc.c
#--- KEEP IN APLPABETIC ORDER ---
CMODS_LIB       =\
				API_lex.c API_parse_self.c  \
				compile.c class.c clobber.c \
				dim.c \
				field_handling.c \
				globals.c \
				import.c labels.c insert_curs.c fix_insert.c \
				linearise.c \
				rules/generated/kw.c \
				list.c lexer.c lex.c  expr_munging.c lint.c \
                                mod.c commands.c  map.c extendedmap.c parsehelp.c common.c \
                                ../../lib/generated/std_funcs.c  \
                                var_handling.c variables.c \
                		${Y_TAB_C} \
                		${WANTKW_C}

CMODS           =${CMODS_EXE} ${CMODS_LIB}

ifneq "${GETOPT_LONG}" "yes"
	ifeq "${GETOPT_LONG}" "iberty"
		AUBIT_LIB+=-L/opt/sfw/lib -liberty
    else
        CMODS   +=${ROOT}/tools/getopt/getopt.c ${ROOT}/tools/getopt/getopt1.c
    endif
endif

4GLCAOBJ		=${CMODS:.c=.o}
OBJS_LIB		=${CMODS_LIB:.c=.o}

#Use this to create dependency for the parser:
RULES_SRC		=$(wildcard rules/*.reqd) $(wildcard rules/*.rule) $(wildcard rules/sqlpack/infx/*.rule)
#RULES_SRC			=$(addprefix rules/,$(RULES_SRC_tmp))

## ==================================================================
##                    Options
## ==================================================================

ifdef COMSPEC
	ALL			=${ROOT}/lib/lib4glc${SO_EXT}
    CMODS		=${CMODS_EXE}
	4GLCAOBJ	=${CMODS:.c=.o}
    4GL_LIB     =-l4glc
endif

ALL				+=${ROOT}/bin/4glc fgllint


core: ${ROOT}/bin/4glc 

C_LOCAL_IFLAGS  =-I${ROOT}/lib/liblex/lex_c -I.  -Irules -I${GENRULES}
#-I${ROOT}/lib -I${ROOT}/lib/libincl
CFLAGS			+=${C_LOCAL_IFLAGS} ${RPCLIB_INCLUDE} ${CURSES_INC_PATH}
LCLINT_CFLAGS   =${C_IFLAGS} ${C_LOCAL_IFLAGS}

ifneq "${COMSPEC}" ""
	LINKLIBS	=-L${LIBROOT} -l$(AUBITLIBFULL)
endif

ifeq "${GCC_MINGW}" "yes"
	LINKLIBS	+=-liberty
endif

ifeq "${TARGET_OS}" "linux" 
	LD_EXE_FLAGS=-rdynamic
endif

#ifeq "${TARGET_OS}" "solaris"
	#LINKLIBS	+=-ldl
	#AUBIT_LIB	+=-ldl
#endif
ifeq "${TARGET_OS}" "hpux"
	BISON_CC=cc
else
	BISON_CC=${CC}
endif

ifeq "something" "blah"
	LD_EXE_FLAGS=-export-dynamic
endif



## ==================================================================
##                              Targets
## ==================================================================

all: a4gl_4glc_int.h ${ALL} 
	@echo "Default targets (${ALL}) successfully compiled."

a4gl_4glc_int.h: API_lex.c API_parse.c

${ROOT}/bin/4glc: ${4GLCAOBJ} 
	${LD_EXE} ${LD_EXE_FLAGS} -L${ROOT}/lib -o $@ $^ ${AUBIT_LIB} ${4GL_LIB} ${EXTRASYSTEMLIBS}
ifeq "${STRIP_EXECUTABLES}" "yes"
	${CP}  $@${EXEEXT} $@-strip${EXEEXT}
	${STRIP} $@-strip${EXEEXT}
endif

## ==================================================================
##                            Windows Targets
## ==================================================================

lib4glc${SO_EXT}: ${ROOT}/lib/lib4glc${SO_EXT}
${ROOT}/lib/lib4glc${SO_EXT}: ${OBJS_LIB}
	${LD} ${SO_LDFLAGS} -o $@ $^ ${LINKLIBS}
ifeq "${SO_EXT}" ".dll"
	${MV} TMP${SOEXP_EXT} $@.a
endif


## ==================================================================
##                            Sub Targets
## ==================================================================

#rules.t :
#	${MAKE} -C rules $(MKNAME)

rules/generated/y.tab.o: ${Y_TAB_C} ${Y_TAB_H}
	${BISON_CC} ${CFLAGS} -c -o $@ ${Y_TAB_C} ${YYDEBUG} -I${ROOT}/lib/liblex/lex_c -I.

rules/generated/mk_states.o:  rules/generated/mk_states.c
	${CC} ${CFLAGS} -O2 -c -o $@ $< -I. -Irules/generated

${Y_TAB_C} rules/generated/y.output: ${RULES_SRC}
	${MAKE} -C rules

../fcompile/form_x.h:
	${MAKE} -C ../fcompile rpc

API_lex.c: API_lex.spec ../../incl/a4gl_API_lex.h    ../../incl/a4gl_API_lex_lib.h
	${SH} ../../lib/bin/dlmagic $< > $@
	${SH} ../../lib/bin/dlmagic $< -S > API_lex_self.c

	
../../incl/a4gl_API_lex.h: API_lex.spec	
	${SH} ../../lib/bin/dlmagic $< -h > $@

../../incl/a4gl_API_lex_lib.h: API_lex.spec	
	${SH} ../../lib/bin/dlmagic $< -H > $@


	
#../../incl/a4gl_API_lex.h: API_lex.spec	
#${SH} ../../lib/bin/dlmagic $< -h > $@

#../../incl/a4gl_API_lex_lib.h: API_lex.spec	
#${SH} ../../lib/bin/dlmagic $< -H > $@
#${ROOT}/tools/no_yacc/cygwin/compilers/4glc/rules/generated/y.tab.c

API_parse.c: API_parse.spec ../../incl/a4gl_API_parse.h    ../../incl/a4gl_API_parse_lib.h
	${SH} ../../lib/bin/dlmagic $< > $@

API_parse_self.c: API_parse.spec ../../incl/a4gl_API_parse.h    ../../incl/a4gl_API_parse_lib.h
	${SH} ../../lib/bin/dlmagic $< -S > API_parse_self.c

../../incl/a4gl_API_parse.h: API_parse.spec	
	${SH} ../../lib/bin/dlmagic $< -h > $@

../../incl/a4gl_API_parse_lib.h: API_parse.spec	
	${SH} ../../lib/bin/dlmagic $< -H > $@

rules/generated/mk_states.c: mk_states_c ${Y_OUTPUT}
ifeq "${HOSTNAME}" "${HOSTNAME_SPEC}"
	cp ${Y_OUTPUT} rules/generated/y.output
endif
	@echo "Y_OUTPUT=${Y_OUTPUT}"
ifneq "${YACC}" "no"
	${SH} $<
#the "t" file is some kind of temporary file created by wantkw_gen.pl
	${RM} t
else
	${CP} ${ROOT}/tools/no_yacc/cygwin/compilers/4glc/rules/generated/mk_states* rules/generated
endif

mk_states_c:
	cd ${ROOT}; config.status --file compilers/4glc/mk_states_c

## ==================================================================
##                            Dependencies
## ==================================================================

${GENRULES}/kw.c ${GENRULES}/single_words.rule  \
rules/generated/kw.h rules/generated/y.tab.h:
	${MAKE} -C rules $(MKNAME)

4glc.o: 				rules/generated/kw.h rules/generated/y.tab.h a4gl_4glc_int.h ../../incl/a4gl_API_lex.h ../../incl/a4gl_API_parse.h
dim.o: 					rules/generated/kw.h rules/generated/y.tab.h a4gl_4glc_int.h ../../incl/a4gl_API_lex.h ../../incl/a4gl_API_parse.h
compile.o: 				rules/generated/kw.h rules/generated/y.tab.h a4gl_4glc_int.h ../../incl/a4gl_API_lex.h ../../incl/a4gl_API_parse.h

mod.o: 					mod.c ${Y_TAB_C}
${GENRULES}/y.tab.o: 	../fcompile/form_x.h

lexer.o: ${GENRULES}/kw.h 
lexer.o: ${GENRULES}/y.tab.h

## ==================================================================
##                            Other Targets
## ==================================================================

splint: lclint
lclint: $(CMODS)
	${LCLINTERR}${LCLINTEXE} ${LCLINTFLAGS} $(LCLINT_CFLAGS) $(CMODS) > ${LCLINTLOG} ${LCLINTLOGCMD}
	${CAT} ${LCLINTLOG} >> ${ROOT}/${LCLINT_GLOBAL_LOG}
	@echo "see ${LCLINTLOG} for results"

show:
	@echo "YACC=${YACC}"
	@echo "GENRULES=${GENRULES}"
	@echo "Y_TAB_C=${Y_TAB_C}"
	@echo "CFLAGS=${CFLAGS}"
	@echo "Y_OUTPUT=${Y_OUTPUT}"

## ==================================================================
##                            Clean Targets
## ==================================================================

clean: clean.rules.generated clean.rules 
	${RM} *${SO_EXT} *.o *.err *.a *.exe *.bak .*.bak .\#* \
	*.log *.dll *.dll.a *.def wantkw.c wantkw.h rules/generated/mk_states_1.h rules/generated/mk_states.h \
	rules/generated/mk_states.c API_lex.c ../../incl/a4gl_API_lex.h ../../incl/a4gl_API_lex_lib.h \
	API_parse_self.c API_lex_self.c ../../incl/a4gl_API_parse_lib.h fgllint \
	../../incl/a4gl_API_parse.h API_parse.c

#WARNING! do NOT clean mk_states_c - this is an autoconf generated file
#and will get cleaned only in make.distclean target of root makefile
	
clean.rules.generated:
	(cd rules/generated; ${RM} *.yacc *.c *.h single_words *.o *.yh *.rule \
	*.output *.bak .*.bak)
	
clean.rules:
	${MAKE} -C rules clean


fgllint: ../../bin/fgllint


extra: ../../bin/reload ../../bin/fgllint ../../bin/fglcalltree 

../../bin/reload: reload.c API_lex.c common.c ../../lib/generated/std_funcs.c
	$(CC) -g -fPIC -I. -I$(AUBITDIR)  -I$(AUBITDIR)/incl $(LD_EXE_FLAGS) reload.c API_lex.c common.c ../../lib/generated/std_funcs.c -o $@ -L$(AUBITDIR)/lib -laubit4gl  



reload_static: reload.c API_lex_self.c common.c ../../lib/generated/std_funcs.c
	$(CC) -g -fPIC -I. -I$(AUBITDIR)  -I$(AUBITDIR)/incl $(LD_EXE_FLAGS) reload.c API_lex_self.c common.c ../../lib/generated/std_funcs.c  -o reload_static -L$(AUBITDIR)/lib -laubit4gl  -L`aubit-config DEFAULT_PLUGINDIR` -lLEX_C

../../bin/fgllint: lint_main.o API_lex.o  lint.o expr_munging.o linearise.o   common.o ../../lib/generated/std_funcs.c
	$(CC) -rdynamic  -g -o $@ $^ -L$(AUBITDIR)/lib -laubit4gl
	#cp fgllint $(AUBITDIR)/bin



fglcalltree:../../bin/fglcalltree
../../bin/fglcalltree: calltree.o API_lex.o  linearise.o calltree_expr.o module_def.o
	$(CC) -rdynamic  -g -o $@ $^ -L$(AUBITDIR)/lib -laubit4gl
	gcc -rdynamic  -g -o $@ $^ -L$(AUBITDIR)/lib -laubit4gl
	#cp fglcalltree $(AUBITDIR)/bin

#fglsplit: split.o API_lex.o  linearise.o
	#$(CC) -Wall -rdynamic  -g -o $@ $^ -L$(AUBITDIR)/lib -laubit4gl
	#cp $@ $(AUBITDIR)/bin

fgllink: write_4gl.o API_lex.o
	$(CC) -rdynamic  -g -o $@ $^ -L$(AUBITDIR)/lib -laubit4gl
	cp fgllink $(AUBITDIR)/bin


# --------------------------------- EOF -----------------------------

