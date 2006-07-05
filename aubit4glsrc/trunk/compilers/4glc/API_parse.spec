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

#ifdef DEBUG
#undef DEBUG
#endif


doparse -> int 

