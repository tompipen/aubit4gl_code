# Makefile for experimental new 4gl parser for using with fgldoc
# based on the aubit4gl parser

CC=g++
CXX=g++
CXXFLAGS=-g -I ast
CFLAGS=-g -I ast

FGL_PARSER_MOD= MemFile.o FglLexer.o fgl.o fgl_parse.o generated/kw.o \
generated/mk_states.o generated/states.o 
fgl_parser.so : $(FGL_PARSER_MOD) 
	${LD} ${SO_LDFLAGS} $^ -o $@  ${LINKLIBS}

fgl_parser:  $(FGL_PARSER_MOD)  m_fgl_parser.o
	$(CXX) -o fgl_parser $(FGL_PARSER_MOD) m_fgl_parser.o -ldl ast/fgl_ast.so

# Generate some code necessary to compile the parser.
# The dependencies are not defined.
generate:
	# Gera generated/kw.c e generated/kw.h
	./convkw_hash kwords 
	# Gera generated/states.c
	./procstates defstates
	bison -y -r all -d -v fgl.y
	# Gera generated/mk_states.c
	./mk_states_c y.output

# Compile the .y with bison and compile(s) it to .o
fgl.o : fgl.y
	bison -d -k fgl.y
	mv -f fgl.tab.c fgl.c
	$(CC) $(CFLAGS) -c fgl.c
#bison -k -S glr.c fgl.y
#gcc $(CFLAGS) -c fgl.c

SO_LDFLAGS=-shared

all: generate fgl_parser.so fgl_parser


fgl_parser.a : $(FGL_PARSER_MOD) 
	ar rv fgl_parser.a $(FGL_PARSER_MOD)

# Test some parsings
.PHONY : test
test:
	make -C test

clean:
	rm -f *.o generated/* y.output y.tab.h fgl_parser.a *.so fgl_parser y.tab.c
	make -C ast clean
	make -C test clean
