
#
# $Id: makefile,v 1.2 2004-11-26 03:57:52 afalout Exp $
#

ROOT		=../..
LIBROOT		=../../lib

#All stuff common to more then one Aubit compiler make file is there:
include ${ROOT}/incl/Makefile-common

## ==================================================================
##                   Settings
## ==================================================================

ALL					=sql_parse $(LIBROOT)/libSQLPARSE_INFORMIX.so
CFLAGS				=-g -fPIC -I$(ROOT)/incl
LDFLAGS				=-g
SQLPACK_IFX_PATH	=../4glc/rules/sqlpack/infx

## ==================================================================
##                   Targets
## ==================================================================

all: ${ALL}
	@echo "Run-time SQL parser compiled"

sql_parse: y.tab.o main.o   
	${CC} -I$(ROOT)/incl $^ -o $@ -L$(LIBROOT) -laubit4gl

$(LIBROOT)/libSQLPARSE_INFORMIX.so : y.tab.o    
	${CC} -shared -I$(ROOT)/incl $< -o $@ -L$(LIBROOT) -laubit4gl 

## ==================================================================
##                   Sub-targets
## ==================================================================
	
lex.yy.c: m2.lex
ifeq "${LEX}" "no"
	@echo "No lex (${LEX})"
	exit 4
else
	${NICE} ${LEX} -i $<
endif

main.o: main.c
	${CC} -c -DTEST $<

sql1.rule: ${SQLPACK_IFX_PATH}/sql1.rule
	cp $< .

schema.rule: ${SQLPACK_IFX_PATH}/schema.rule
	cp $< .

update.rule: ${SQLPACK_IFX_PATH}/update.rule
	cp $< .

m2.lex: gen_lex 2.reqd
	${SH} gen_lex > $@

2.reqd:	../4glc/rules/generated/kw.yh not_used
	cp $< ./$@.in
	fgrep -f not_used -v $@.in > $@

sql.yacc: 1.reqd 2.reqd 10.reqd 80.reqd 99.reqd
#no .rule files in curr dir???
	${CAT} $^ *.rule > $@


y.tab.c: sql.yacc
ifneq "${YACC}" "no"
	${YACC} -v -t -d $<
else
	@echo "No yacc (${YACC})"
	exit 4
endif	

y.tab.o: y.tab.c lex.yy.c util.c

## ==================================================================
##                   Clean
## ==================================================================

clean:
	${RM} *.o *.so *.dll ${ALL} 2.reqd *~ 2.reqd.in sql.yacc


	
