# Makefile for experimental new 4gl parser for using with fgldoc
# based on the aubit4gl parser

CC=g++
CXX=g++
CXXFLAGS=-g -I ast -I syntax -I lexer -I error -I . -I keyword
CFLAGS=-g -I ast -I syntax -I lexer -I error -I . -I keyword 
SO_LDFLAGS=-shared

FGL_PARSER_MOD= syntax/fgl.o lexer/MemFile.o \
keyword/KeyWord.o keyword/KeyWordTextReader.o \
lexer/FglLexer.o error/FglParseError.o error/ParserError.o \
FglParse.o generated/kw.o generated/mk_states.o 
fgl_parser.so : $(FGL_PARSER_MOD) 
	${LD} ${SO_LDFLAGS} $^ -o $@  ${LINKLIBS}

# Generate some code necessary to compile the parser.
# The dependencies are not defined.
generate:
	# Gera generated/kw.c e generated/kw.h
	./convkw_hash kwords 
	# Gera generated/states.c
	#./procstates defstates
	bison -y -r all -d -v fgl.y
	# Gera generated/mk_states.c
	./mk_states_c y.output


all: fgl_parser.so
	make -C ast
	make -C test all

.PHONY : test
test:
	make -C test run

syntax/fgl.o :
	$(MAKE) -C syntax fgl.o

clean:
	rm -f *.o generated/* y.output y.tab.h fgl_parser.a *.so fgl_parser y.tab.c
	make -C ast clean
	make -C test clean
	make -C syntax clean
	make -C lexer clean
	make -C error clean
