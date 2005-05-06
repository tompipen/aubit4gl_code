*
* API specs for ESQL Helper library interface - used by dlmagic script
* to create API_esql.c (try "make API_esql.c")
*
* Note - there are no spaces for void* int* etc.
*
*
*
* Name of the API:
LIBRARY ESQL
* Name of the variable which will have second part of library name to load:
VARIABLE A4GL_LEXDIALECT
* Add prefix for created API punctions:
* API_PREFIX ESQLAPI_
* Add prefix for existing library functions:
LIB_PREFIX ESQLAPI_
* Name of the header file to be referenced with #include
* HEADER_FILE API_esql.h

// This is needed to get the prototypes for the functions
// FIXME: should this not be printed by dlmagic ??
// - NO - dlmagic includes a4gl_libaubit4gl_int.h which includes all API headers
//#include "a4gl_API_esql.h"
//#ifdef DEBUG_SPEC
//#undef DEBUG_SPEC
//#endif

* ======================================================================
* Function calls definitions:
* func-name param-type param-name ... -> returns
*

A4GL_copy_char char* infx,char* a4gl,short*  indicat,int size,char mode,int x,int y -> void
A4GL_copy_date long* infx,long* a4gl,short*  indicat,int size,char mode -> void
A4GL_copy_datetime void* infx, void* a4gl,short*  indicat,int size,char mode -> void
A4GL_copy_interval void* infx, void* a4gl,short*  indicat,int size,char mode -> void
A4GL_copy_decimal void* infx,void* a4gl,short*  indicat,int size,char dir -> void
A4GL_copy_float float* infx,float* a4gl,short*  indicat,int size,char mode -> void
A4GL_copy_double double* infx,double* a4gl,short*  indicat,int size,int mode -> void
A4GL_copy_int long* infx,long* a4gl,short*  indicat,int size,char mode -> void
A4GL_copy_money void* infx,void* a4gl,short*  indicat,int size,char dir -> void
A4GL_copy_smint short* infx,short* a4gl,short*  indicat,int size,char mode -> void
A4GL_connect_db char* dbname -> void
A4GL_db_connected char* dbname -> void*

popdec_native void* vx -> void
retdec_native void* vx -> void
popdtime_native void* vx -> void
retdtime_native void* vx -> void




