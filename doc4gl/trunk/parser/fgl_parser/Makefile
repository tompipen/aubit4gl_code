# Makefile for experimental new 4gl parser for using with fgldoc
# based on the aubit4gl parser


FGL_PARSER_MOD= memfile.o fgl.o fgl_parse.o lexer.o generated/kw.o \
generated/mk_states.o generated/states.o m_fgl_parser.o
fgl_parser:  $(FGL_PARSER_MOD)
	$(CC) -o fgl_parser $(FGL_PARSER_MOD)
