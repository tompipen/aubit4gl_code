CFLAGS=-Wall -I$(AUBITDIR)/incl -O2

all: c2pcode checker runner

OBJ_C2PCODE=y.tab.o lex.yy.o compiler_main.o common_io.o npcode_xdr.o compiler_param.o compiler_pcode.o compiler_variables.o common_print.o compiler_list.o common_eval.o
OBJ_CHECKER=npcode_xdr.o checker_read.o common_io.o common_print.o common_eval.o
OBJ_RUNNER=runit.o npcode_xdr.o  common_io.o runner_main.o runner_execute.o runner_vars.o common_print.o common_eval.o


SRCS=Makefile npcode.x npcode_defs.h runit.4gl checker_read.c common_eval.c common_io.c common_print.c compiler_list.c compiler_main.c compiler_param.c compiler_pcode.c compiler_variables.c runner_execute.c runner_main.c runner_vars.c simple.lex simple.yacc


checker: $(OBJ_CHECKER) npcode.h 
	cc -g -o $@ $(OBJ_CHECKER) -laubit4gl  -g -pg
#-lefence

c2pcode:  $(OBJ_C2PCODE) npcode.h
#make_pcode.o y.tab.o lex.yy.o compiler_main.o param.o variable.o npcode.h write.o npcode_xdr.o common_print.o 
#cc -g make_pcode.o y.tab.o lex.yy.o main.o param.o variable.o write.o npcode_xdr.o -o simple -laubit4gl
#-lefence
	cc -o $@ $(OBJ_C2PCODE) -laubit4gl  
#-lefence
	

npcode_xdr.o: npcode_xdr.c
	gcc -c -g -o npcode_xdr.o npcode_xdr.c

npcode.h : npcode.x
	rpcgen npcode.x

open_pcode:  open.o write.o npcode_xdr.o print.o
	cc open.o write.o npcode_xdr.o print.o -o open_pcode -laubit4gl

make_pcode.o : npcode.h
y.tab.o : npcode.h
main.o : npcode.h
variable.o : npcode.h
param.o : npcode.h
runner_main.o: npcode.h

y.tab.o : simple.yacc
	#bison -y -r all -d -v  simple.yacc
	# add -t for yacc debugging...
	yacc  -t -d -v simple.yacc
	gcc -g -c y.tab.c

lex.yy.c: simple.lex
	flex -i simple.lex

bin:
	tar cvf pcode.tar make_pcode.c main.c simple.yacc simple.lex pcode.h variable.c
	gzip -9  pcode.tar

clean: 
	rm *.o y.tab.c lex.yy.c c2pcode checker

libDATA_pcode.so : npcode.xi.o npcode.xio.o npcode.xo.o
	gcc -g -I../incl -shared npcode.xi.o npcode.xio.o npcode.xo.o -o libDATA_pcode.so


runit.c: runit.4gl
	A4GL_FAKELEXTYPE=C 4glc runit.4gl

runner: $(OBJ_RUNNER)
	4glpc -O2 -o $@ $(OBJ_RUNNER) -laubit4gl

mine.4pe: simple
	simple hello.c

src.tgz: $(SRCS)
	tar cvzf src.tgz $(SRCS)
