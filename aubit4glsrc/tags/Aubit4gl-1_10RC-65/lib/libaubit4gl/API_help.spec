*
* API specs for HELP library interface - used by dlmagic script
* to create API_msg.c (try "make API_msg.c")
*
* Note - there are no spaces for void* int* etc.
*
*
*
* Name of the API:
LIBRARY HELP
* Name of the variable which will have second part of library name to load:
VARIABLE A4GL_HELPTYPE
* Name of the header file to be referenced with #include
*HEADER_FILE API_help.h
LIB_PREFIX HELPLIB_


*
* Function calls definitions:
* func-name param-type param-name ... -> returns"
*


*FIXME : why aclfgl_aclfgl_ (twice) ??

aclfgl_aclfgl_libhelp_showhelp int helpno -> int
aclfgl_aclfgl_openiem int nparams -> int
aclfgl_aclfgl_fetchiem int nparams -> int
aclfgl_aclfgl_closeiem int nparams -> int

/* ------------------------ EOF ------------------------ */

