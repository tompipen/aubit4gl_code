CFLAGS=-Wall  -O2
CC=gcc


all: c2pcode checker runner runner_fgl

OBJ_C2PCODE=y.tab.o lex.yy.o compiler_main.o common_io.o npcode_xdr.o compiler_param.o compiler_pcode.o compiler_variables.o common_print.o compiler_list.o common_eval.o

OBJ_CHECKER=npcode_xdr.o checker_read.o common_io.o common_print.o common_eval.o

OBJ_RUNNER_C=runner_calls_c.o npcode_xdr.o  common_io.o runner_main.o runner_execute.o runner_vars.o common_print.o common_eval.o
OBJ_RUNNER_A4GL=runner_calls_fgl.o npcode_xdr.o  common_io.o runner_main.o runner_execute.o runner_vars.o common_print.o common_eval.o


SRCS=Makefile npcode.x npcode_defs.h runner_calls.c calls.h fgl_calls.h std_calls.h checker_read.c common_eval.c common_io.c common_print.c compiler_list.c compiler_main.c compiler_param.c compiler_pcode.c compiler_variables.c runner_execute.c runner_main.c runner_vars.c simple.lex simple.yacc


runner_calls_c.o : runner_calls.c
	$(CC) -g -c runner_calls.c -DSTDCALLS -o runner_calls_c.o

runner_calls_fgl.o : runner_calls.c
	$(CC) -g -c runner_calls.c -DFGLCALLS -I$(AUBITDIR)/incl -o runner_calls_fgl.o


checker: $(OBJ_CHECKER) npcode.h 
	$(CC) -g -o $@ $(OBJ_CHECKER) -laubit4gl  -g 
#-lefence

c2pcode:  $(OBJ_C2PCODE) npcode.h
#make_pcode.o y.tab.o lex.yy.o compiler_main.o param.o variable.o npcode.h write.o npcode_xdr.o common_print.o 
#cc -g make_pcode.o y.tab.o lex.yy.o main.o param.o variable.o write.o npcode_xdr.o -o simple -laubit4gl
#-lefence
	$(CC) -o $@ $(OBJ_C2PCODE) -laubit4gl  
#-lefence
	

npcode_xdr.o: npcode_xdr.c
	$(CC) -c -g -o npcode_xdr.o npcode_xdr.c

npcode.h : npcode.x
	rpcgen npcode.x

open_pcode:  open.o write.o npcode_xdr.o print.o
	$(CC) open.o write.o npcode_xdr.o print.o -o open_pcode -laubit4gl

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
	$(CC) -g -c y.tab.c

lex.yy.c: simple.lex
	flex -i simple.lex

bin:
	tar cvf pcode.tar make_pcode.c main.c simple.yacc simple.lex pcode.h variable.c
	gzip -9  pcode.tar

clean: 
	rm *.o y.tab.c lex.yy.c c2pcode checker y.output y.tab.h runner

libDATA_pcode.so : npcode.xi.o npcode.xio.o npcode.xo.o
	$(CC) -g -I../incl -shared npcode.xi.o npcode.xio.o npcode.xo.o -o libDATA_pcode.so


#runit.c: runit.4gl
	#A4GL_FAKELEXTYPE=C 4glc runit.4gl

runner: $(OBJ_RUNNER_C)
	$(CC) -O2 -o $@ $(OBJ_RUNNER_C) 

runner_fgl: $(OBJ_RUNNER_A4GL)
	$(CC) -O2 -o $@ $(OBJ_RUNNER_A4GL) -laubit4gl

mine.4pe: simple
	simple hello.c

src.tgz: $(SRCS)
	tar cvzf src.tgz $(SRCS)
