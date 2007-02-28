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


/* We don't want to enable debugging in here */
/*  because A4GL_copy_char can be passed invalid strings as a location */
/* to copy INTO  (ie - it will be set After the copy) */
#ifdef DEBUG_SPEC
#undef DEBUG_SPEC
#endif
#define structBINDING struct BINDING

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
A4GL_copy_double double* infx,double* a4gl,short*  indicat,int size,char mode -> void
A4GL_copy_int long* infx,long* a4gl,short*  indicat,int size,char mode -> void
A4GL_copy_money void* infx,void* a4gl,short*  indicat,int size,char dir -> void
A4GL_copy_smint short* infx,short* a4gl,short*  indicat,int size,char mode -> void
A4GL_connect_db char* dbname -> void
A4GL_db_connected char* dbname -> void*
A4GL_copy_native_bind char dir structBINDING* a4glbind structBINDING* nativebind structBINDING* indbind int n -> void
A4GL_init_out_text void* a4gl void* infx -> void
A4GL_init_out_byte void* a4gl void* infx -> void

popdec_native void* vx -> void
retdec_native void* vx -> void
popdtime_native void* vx -> void
retdtime_native void* vx -> void




