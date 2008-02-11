*
* API specs for Parser library interface - used by dlmagic script
* to create API_Parser.c (try "make API_Parser.c")
*
* Note - there are no spaces for void* int* etc.
*
*
*
* Name of the API:
LIBRARY PARSER
* Name of the variable which will have second part of library name to load:
VARIABLE A4GL_PARSER
* Add prefix for existing library functions:
LIB_PREFIX FGLPARSE_
* Name of the header file to be referenced with #include
HEADER_FILE "API_parse_int.h"

#ifdef DEBUG
#undef DEBUG
#endif


doparse -> int 
A4GL_compiled_sqlpack -> char*
allow_token_state int yystate int yytoken -> int
A4GL_lexer_set_str void* p char* s -> void
A4GL_lexer_get_hashed_list int arr -> void*
A4GL_lexer_import_package char* s -> void
A4GL_lexer_find_type char* s  -> int
A4GL_lexer_parsed_fgl -> void
*do_print_declare_associate_1  char* var char* size char* n -> void
