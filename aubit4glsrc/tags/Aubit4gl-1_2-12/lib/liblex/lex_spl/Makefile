# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0   lib/liblex/lex_c makefile	 |
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
# $Id: Makefile,v 1.1 2009-02-03 14:28:38 mikeaubury Exp $
#

ROOT        =../../..

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                   Source files
## ==================================================================

#FIXME: does compile_c_gtk.o belong here, or in 4GLCAOBJ ?

#Since compile_c.c includes calls to make_sql_bind, which is defined in binding.c, binding.c, must
#be linked in C as well, because there cannot be any unsresolved symbols at link time on Windows:
COMMON_OBJ      =compile_spl.o 


#binding.c:268: undefined reference to `A4GL_dtype_sz'

4GLCOBJ_SPL		=  ${COMMON_OBJ}


## ==================================================================
##                    Options
## ==================================================================

ifeq "${YACC}" "no"
	CFLAGS		+=-I${ROOT}/tools/no_yacc/cygwin/compilers/4glc
	KW_H		=${ROOT}/tools/no_yacc/cygwin/compilers/4glc/rules/generated/kw.h
	Y_TAB_H		=${ROOT}/tools/no_yacc/cygwin/compilers/4glc/rules/generated/y.tab.h
else
	KW_H		=${ROOT}/compilers/4glc/rules/generated/kw.h
	Y_TAB_H		=${ROOT}/compilers/4glc/rules/generated/y.tab.h
endif

ifeq "${GCC_MINGW}" "yes"
	CFLAGS		+=-I${ROOT}/tools/getopt
endif

CFLAGS			+=-I.. -I. -I${LIBROOT}/libincl -I${ROOT}/compilers/fcompile -I${ROOT}/compilers/4glc/rules -I${ROOT}/compilers/4glc
ifneq "${COMSPEC}" ""
	LINKDEPS    =${LIBROOT}/lib4glc${SO_EXT}
	LINKLIBS	+=-L${LIBROOT} -l${AUBITLIBFULL} -l4glc
endif

ALL         	+=${PLUGINDIR}/libLEX_SPL${SO_EXT}

## ==================================================================
##                              Targets
## ==================================================================

ALL: ${ALL}
	@echo "All targets (${ALL}) successfully compiled"

#Pure C output for C compiler
# PCODE C output
${PLUGINDIR}/libLEX_SPL${SO_EXT} : ${4GLCOBJ_SPL} ${LINKDEPS}
	${LD} ${SO_LDFLAGS} -o $@ ${4GLCOBJ_SPL} ${LINKLIBS}


## ==================================================================
##                            Sub Targets
## ==================================================================

#bad_idents.o: a4gl_lib_lex_esqlc_int.h
binding.o: a4gl_lib_lex_esqlc_int.h
class.o: a4gl_lib_lex_esqlc_int.h
compile_c.o: a4gl_lib_lex_esqlc_int.h
compile_c_esql.o: a4gl_lib_lex_esqlc_int.h
compile_c_gtk.o: a4gl_lib_lex_esqlc_int.h
compile_c_sql.o: a4gl_lib_lex_esqlc_int.h
init.o: a4gl_lib_lex_esqlc_int.h

a4gl_lib_lex_esqlc_int.h: ../a4gl_lib_lex_int.h


../../incl/a4gl_API_lex_lib.h ../../incl/a4gl_API_lex.h: ${ROOT}/compilers/4glc/API_lex.spec
	${MAKE} -C ${ROOT}/compilers/4glc ../../incl/a4gl_API_lex_lib.h
	${MAKE} -C ${ROOT}/compilers/4glc ../../incl/a4gl_API_lex.h

../a4gl_lib_lex_int.h: ../../incl/a4gl_API_lex.h  ../../incl/a4gl_API_parse.h

../../incl/a4gl_API_parse_lib.h ../../incl/a4gl_API_parse.h: ${ROOT}/compilers/4glc/API_parse.spec
	${MAKE} -C ${ROOT}/compilers/4glc ../../incl/a4gl_API_parse_lib.h
	${MAKE} -C ${ROOT}/compilers/4glc ../../incl/a4gl_API_parse.h


${LIBROOT}/lib4glc${SO_EXT}:
	${MAKE} -C ${ROOT}/compilers/4glc lib4glc${SO_EXT}

## ==================================================================
##                            Dependencies
## ==================================================================

compile_c.o compile_c_sql.o: ${KW_H} ${Y_TAB_H} compile_c.h

${KW_H} ${Y_TAB_H}:
	${MAKE} -C ${ROOT}/compilers/4glc rules/generated/y.tab.c

## ==================================================================
##                            Clean Targets
## ==================================================================

clean:
	${RM}  *.o *.err 4glc 4glc-noodbc *.a *.exe *.bak \
	.\#* 4glp *.log *.dll *.dll.a \
		${PLUGINDIR}/libLEX_SPL${SO_EXT} 

tgz:
	tar cvzf /tmp/spl.tgz Makefile compile_spl.c compile_spl.h

#--------------------------------- EOF -----------------------------
