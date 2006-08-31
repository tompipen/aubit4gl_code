CFLAGS=-g

adbload2: adbload2_parse.tab.o parse.o adbload2.o process.o
	4glpc -t EC -g -o adbload2 adbload2_parse.tab.o adbload2.o parse.o process.o -laubit4gl

process.o: process.ec
	4glpc -t EC -g -o process.o process.ec 

adbload2.o: adbload2.4gl
	4glpc -t EC -g -o adbload2.o adbload2.4gl

lex.yy.c: adbload2_parse.l
	flex -i adbload2_parse.l

adbload2_parse.tab.c: adbload2_parse.y
	bison adbload2_parse.y

adbload2_parse.tab.o: adbload2_parse.tab.c lex.yy.c


test: adbload2
	asql_i.4ae mja1 q1.sql
	./adbload2   -d mja1 -c bibble2 -l kjh
	asql_i.4ae mja1 q2.sql

clean: 
	rm *.o lex.yy.c adbload2_parse.tab.c
