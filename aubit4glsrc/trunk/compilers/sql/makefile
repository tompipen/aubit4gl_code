
#
# $Id: makefile,v 1.3 2004-11-26 08:11:24 afalout Exp $
#

ROOT		=../..
LIBROOT		=../../lib

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                   Settings
## ==================================================================

ALL					=${ROOT}/bin/sql_parse $(LIBROOT)/libSQLPARSE_INFORMIX${SO_EXT}
CFLAGS				=-g -fPIC -I$(ROOT)/incl
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
	${CC} -shared -I$(ROOT)/incl $< -o $@ -L$(LIBROOT) -laubit4gl 

## ==================================================================
##                   Sub-targets
## ==================================================================
	
main.o: main.c
	${CC} -c -DTEST $<

m2.lex: gen_lex 2.reqd
	${SH} gen_lex > $@

2.reqd:	../4glc/rules/generated/kw.yh
	fgrep -f not_used -v $< > $@

#WARNING: order is IMPORTANT!
sql.yacc: 1.reqd 2.reqd 10.reqd ${SQLPACK_IFX_PATH}/update.rule \
	${SQLPACK_IFX_PATH}/schema.rule ${SQLPACK_IFX_PATH}/sql1.rule \
	80.reqd 99.reqd
	${CAT} $^ > $@
	
y.tab.c: sql.yacc
ifneq "${YACC}" "no"
	${YACC} -v -t -d $<
else
	@echo "No yacc (${YACC})"
	exit 4
endif	

lex.yy.c: m2.lex
ifneq "${LEX}" "no"
	${NICE} ${LEX} -i $<
else
	@echo "No lex (${LEX})"
	exit 4
endif

y.tab.o: y.tab.c lex.yy.c util.c

## ==================================================================
##                   Clean
## ==================================================================

clean:
	${RM} *.o *.so *.dll ${ALL} 2.reqd *~ sql.yacc


	
