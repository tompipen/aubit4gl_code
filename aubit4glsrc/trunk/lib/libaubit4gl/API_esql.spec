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
* LIB_PREFIX ESQLAPI_
* Name of the header file to be referenced with #include
* HEADER_FILE API_esql.h

* ======================================================================
* Function calls definitions:
* func-name param-type param-name ... -> returns
*

#include "a4gl_API_esql.h"
/* ------------ functions from compile_[c|perl].c -------------- */

/* void printc(char *fmt, ...) */

/*
void A4GL_copy_char(char *infx,char *a4gl,int indicat,int size,int mode,int x,int y);
void A4GL_copy_date(long *infx,long *a4gl,int indicat,int size,int mode);
void A4GL_copy_datetime(dtime_t *infx, struct A4GLSQL_dtime *a4gl,int indicat,int size,int mode);
void A4GL_copy_decimal(dec_t *infx,fgldecimal *a4gl,int indicat,int size,char dir);
void A4GL_copy_float(float *infx,float *a4gl,int indicat,int size,int mode);
void A4GL_copy_int(long *infx,long *a4gl,int indicat,int size,int mode);
void A4GL_copy_money(dec_t *infx,fglmoney *a4gl,int indicat,int size,char dir);
void A4GL_copy_smint(short *infx,short *a4gl,int indicat,int size,int mode);
void popdec(void *vx);
void retdec(void *vx);
void popdtime(void *vx);
void retdtime(void *vx);
*/


A4GL_copy_char char* infx,char* a4gl,int indicat,int size,int mode,int x,int y -> void
A4GL_copy_date long* infx,long* a4gl,int indicat,int size,int mode -> void
A4GL_copy_datetime void* infx, void* a4gl,int indicat,int size,int mode -> void
A4GL_copy_decimal void* infx,void* a4gl,int indicat,int size,char dir -> void
A4GL_copy_float float* infx,float* a4gl,int indicat,int size,int mode -> void
A4GL_copy_int long* infx,long* a4gl,int indicat,int size,int mode -> void
A4GL_copy_money void* infx,void* a4gl,int indicat,int size,char dir -> void
A4GL_copy_smint short* infx,short* a4gl,int indicat,int size,int mode -> void
popdec void* vx -> void
retdec void* vx -> void
popdtime void* vx -> void
retdtime void* vx -> void


