#
# $Id: Makefile,v 1.2 2006-07-27 16:01:11 mikeaubury Exp $
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
	LEX_YY_C	=lex.sqlparse_yy.c
	KW_YH		=../4glc/rules/generated/kw.yh
endif

ALL					=${ROOT}/bin/sql_parse $(PLUGINDIR)/libSQLPARSE_INFORMIX${SO_EXT}
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
	${CC} -I$(ROOT)/incl $^ -o $@ -L$(LIBROOT) -l${AUBITLIBFULL}

#Shared library that performs SQL parsing and conversion at run-time
#NB: why is it linked with libaubt4gl, when that lib is what loads it
#at run-time (except on Windows where it needs to be linked to resolve symbols)?
$(PLUGINDIR)/libSQLPARSE_INFORMIX${SO_EXT}: y.tab.o
	${CC} -g -shared -I$(ROOT)/incl $< -o $@ -L$(LIBROOT) -l${AUBITLIBFULL} 

	
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
	 ${SQLPACK_IFX_PATH}/select.rule \
	 ${SQLPACK_IFX_PATH}/simple.rule \
	80.reqd 99.reqd
	${CAT} $^ > $@
	
${Y_TAB_C}: sql.yacc
ifneq "${YACC}" "no"
	${YACC} -p sqlparse -v -t -d $<
else
	@echo "No yacc (${YACC}) Using ${Y_TAB_C}"
endif	

${LEX_YY_C}: m2.lex
ifneq "${LEX}" "no"
	${LEX} -Psqlparse_yy -i $<
else
	@echo "No lex (${LEX}) Using ${LEX_YY_C}"
endif

y.tab.o: ${Y_TAB_C} ${LEX_YY_C} util.c ilist.h ../4glc/fix_insert.c
	${CC} ${CFLAGS} -c $< -o $@
	
## ==================================================================
##                   Clean
## ==================================================================

clean:
	${RM} *.o *.so *.dll ${ALL} 2.reqd *~ sql.yacc \
	y.tab.h y.tab.c y.output m2.lex lex.yy.c lex.sqlparse_yy.c



