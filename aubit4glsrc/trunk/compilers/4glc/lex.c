/*******************************************************************
* (c) 1997-2003 Aubit Computing Ltd.
*
*
********************************************************************/


//#include "a4gl_libaubit4gl.h" is included in a4gl_4glc_int.h
#include "a4gl_4glc_int.h"
/*
This module is intended to remove any problems with generating liblex from
the .spec file.

In theory - all API_... calls should call the function that they are called.
If this is NOT done then we will have problems later on if we want to statically
link the library rather than using some environment variable to choose one at run
time....
*/


/* ------------ functions from compile_[c|perl].c -------------- */


#ifdef NDEF
void A4GL_lex_printc(char* fmt,... ) {
va_list ap;
   va_start(ap,fmt);
   A4GL_internal_lex_printc(fmt,&ap);
   va_end(ap);
}

void A4GL_lex_printh(char* fmt,... ) {
    va_list ap;
   va_start(ap,fmt);
   A4GL_internal_lex_printh(fmt,&ap);
   va_end(ap);
}
#endif


void A4GL_lex_printcomment(char* fmt,... ) {
va_list ap;
return;
}
