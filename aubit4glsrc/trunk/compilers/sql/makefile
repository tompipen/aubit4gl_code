#
# $Id: makefile,v 1.9 2005-02-09 02:20:12 afalout Exp $
#

ROOT		=../..
LIBROOT		=../../lib

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                   Settings
## ==================================================================

#LEX=no
#YACC=no

ifeq "${YACC}" "no"
	Y_TAB_C		=${ROOT}/tools/no_yacc/cygwin/compilers/sql/y.tab.c
	LEX_YY_C	=${ROOT}/tools/no_yacc/cygwin/compilers/sql/lex.yy.c
	CFLAGS      +=-I${ROOT}/tools/no_yacc/cygwin/compilers/sql
	KW_YH		=${ROOT}/tools/no_yacc/cygwin/compilers/4glc/rules/generated/kw.yh
else
	Y_TAB_C		=y.tab.c
	LEX_YY_C	=lex.yy.c
	KW_YH		=../4glc/rules/generated/kw.yh
endif

ALL					=${ROOT}/bin/sql_parse $(LIBROOT)/libSQLPARSE_INFORMIX${SO_EXT}
CFLAGS				+=-g -fPIC -I$(ROOT)/incl -I.
LDFLAGS				=-g
SQLPACK_IFX_PATH	=../4glc/rules/sqlpack/infx

## ==================================================================
##                   Targets
## ==================================================================

all: ${ALL}
	@echo "Run-time SQL parser/converter targets:"
	@echo "${ALL}"
	@echo "successfuly compiled."

#Executable that performs SQL parsing/conversion on a SQL in file
#NB: why not link with/dlopen libSQLPARSE_xxx.so instead of statically linking
#with y.tab.o ?
${ROOT}/bin/sql_parse: y.tab.o main.o
	${CC} -I$(ROOT)/incl $^ -o $@ -L$(LIBROOT) -laubit4gl

#Shared library that performs SQL parsing and conversion at run-time
#NB: why is it linked with libaubt4gl, when that lib is what loads it
#at run-time (except on Windows where it needs to be linked to resolve symbols)?
$(LIBROOT)/libSQLPARSE_INFORMIX${SO_EXT}: y.tab.o
	${CC} -g -shared -I$(ROOT)/incl $< -o $@ -L$(LIBROOT) -laubit4gl 

	
## ==================================================================
##                   Sub-targets
## ==================================================================
	
main.o: main.c
	${CC} ${CFLAGS} -c -DTEST $<

m2.lex: gen_lex 2.reqd
	${SH} gen_lex > $@

2.reqd:	${KW_YH}
	fgrep -f not_used -v $< > $@

../4glc/rules/generated/kw.yh:
ifneq "${YACC}" "no"
	${MAKE} -C ../4glc
endif
	
#WARNING: order is IMPORTANT!
sql.yacc: 1.reqd 2.reqd 10.reqd ${SQLPACK_IFX_PATH}/update.rule \
	${SQLPACK_IFX_PATH}/schema.rule ${SQLPACK_IFX_PATH}/sql1.rule \
	80.reqd 99.reqd
	${CAT} $^ > $@
	
${Y_TAB_C}: sql.yacc
ifneq "${YACC}" "no"
	${YACC} -v -t -d $<
else
	@echo "No yacc (${YACC}) Using ${Y_TAB_C}"
endif	

${LEX_YY_C}: m2.lex
ifneq "${LEX}" "no"
	${LEX} -i $<
else
	@echo "No lex (${LEX}) Using ${LEX_YY_C}"
endif

y.tab.o: ${Y_TAB_C} ${LEX_YY_C} util.c
	${CC} ${CFLAGS} -c $< -o $@
	
## ==================================================================
##                   Clean
## ==================================================================

clean:
	${RM} *.o *.so *.dll ${ALL} 2.reqd *~ sql.yacc \
	y.tab.h y.tab.c y.output m2.lex lex.yy.c



