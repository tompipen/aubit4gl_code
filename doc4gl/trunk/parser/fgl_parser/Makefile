# Makefile for experimental new 4gl parser for using with fgldoc
# based on the aubit4gl parser


FGL_PARSER_MOD= memfile.o fgl.o fgl_parse.o lexer.o generated/kw.o \
generated/mk_states.o generated/states.o 
fgl_parser:  $(FGL_PARSER_MOD)  m_fgl_parser.o
	$(CC) -o fgl_parser $(FGL_PARSER_MOD)

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

fgl_parser.a : $(FGL_PARSER_MOD) 
	ar rv fgl_parser.a $(FGL_PARSER_MOD)

# Test some parsings
.PHONY : test
test:
	./fgl_parser

clean:
	rm -f *.o generated/* y.output y.tab.h
