all : sql_parse libSQLPARSE_INFORMIX.so
CFLAGS=-g -fPIC -I$(AUBITDIR)/incl
LDFLAGS=-g

sql_parse: y.tab.o main.o   
	gcc -I$(AUBITDIR)/incl y.tab.o main.o     -o sql_parse -L$(AUBITDIR)/lib -laubit4gl

libSQLPARSE_INFORMIX.so : y.tab.o    
	gcc -shared -I$(AUBITDIR)/incl y.tab.o  -o libSQLPARSE_INFORMIX.so -L$(AUBITDIR)/lib -laubit4gl 
	cp libSQLPARSE_INFORMIX.so $(AUBITDIR)/lib

lex.yy.c: m2.lex
	flex -i m2.lex

main.o: main.c
	gcc -c -DTEST main.c

sql1.rule: ../4glc/rules/sqlpack/infx/sql1.rule
	cp ../4glc/rules/sqlpack/infx/sql1.rule .

schema.rule: ../4glc/rules/sqlpack/infx/schema.rule
	cp ../4glc/rules/sqlpack/infx/schema.rule .

update.rule: ../4glc/rules/sqlpack/infx/update.rule
	cp ../4glc/rules/sqlpack/infx/update.rule .

m2.lex: gen_lex 2.reqd
	sh gen_lex > m2.lex

2.reqd:	../4glc/rules/generated/kw.yh not_used
	cp ../4glc/rules/generated/kw.yh ./2.reqd.in
	fgrep -f not_used -v 2.reqd.in > 2.reqd

sql.yacc: 1.reqd 2.reqd 10.reqd *.rule 80.reqd 99.reqd 
	cat 1.reqd 2.reqd 10.reqd *.rule 80.reqd 99.reqd > sql.yacc

y.tab.c: sql.yacc 
	yacc -v -t -d sql.yacc

y.tab.o: y.tab.c lex.yy.c util.c



