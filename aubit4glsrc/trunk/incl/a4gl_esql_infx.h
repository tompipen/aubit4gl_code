/*******************************************************************
* (c) 1997-2002 Aubit Computing Ltd.
*
* This header file should detect the current ESQL/C compiler as
* set the datatype conversion routines as required...
********************************************************************/

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "decimal.h"
#include "datetime.h"
#include "a4gl_incl_4gldef.h"
#include "a4gl_incl_infx.h"

#ifdef __cplusplus
extern "C"
{
#endif
  void copy_money (dec_t * infx, fglmoney * a4gl, int size, char dir);
  void copy_decimal (dec_t * infx, fgldecimal * a4gl, int size, char dir);
  void copy_datetime (dtime_t * infx, struct A4GLSQL_dtime *a4gl, int size,
		      int mode);


// Conversion functions between informix types and A4GL datatypes
  void copy_decimal (struct decimal *infx, fgldecimal * a4gl, int size,
		     char dir);
#define COPY_DATA_IN_0(a4gl,infx,size) strcpy(*(infx),*(a4gl))
#define COPY_DATA_IN_1(a4gl,infx,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_2(a4gl,infx,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_3(a4gl,infx,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_4(a4gl,infx,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_5(a4gl,infx,size) copy_decimal(infx,a4gl,size,'i')
#define COPY_DATA_IN_6(a4gl,infx,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_7(a4gl,infx,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_8(a4gl,infx,size) copy_money(infx,a4gl,size,'i')
#define COPY_DATA_IN_9(a4gl,infx,size) *(infx)=*(a4gl)
#define COPY_DATA_IN_10(a4gl,infx,size) copy_datetime(infx,a4gl,size,'i')
#define COPY_DATA_IN_11(a4gl,infx,size) copy_blob_byte(infx,a4gl,size,'i')
#define COPY_DATA_IN_12(a4gl,infx,size) copy_blob_text(infx,a4gl,size,'i')
#define COPY_DATA_IN_13(a4gl,infx,size) strcpy(*(infx),*(a4gl))
#define COPY_DATA_IN_14(a4gl,infx,size) copy_interval(infx,a4gl,size,'i')
#define COPY_DATA_OUT_0(a4gl,infx,size) strcpy(*(a4gl),*(infx))
#define COPY_DATA_OUT_1(a4gl,infx,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_2(a4gl,infx,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_3(a4gl,infx,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_4(a4gl,infx,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_5(a4gl,infx,size) copy_decimal(infx,a4gl,size,'o')
#define COPY_DATA_OUT_6(a4gl,infx,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_7(a4gl,infx,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_8(a4gl,infx,size) copy_money(infx,a4gl,size,'o')
#define COPY_DATA_OUT_9(a4gl,infx,size) *(a4gl)=*(infx)
#define COPY_DATA_OUT_10(a4gl,infx,size) copy_datetime(infx,a4gl,size,'o')
#define COPY_DATA_OUT_11(a4gl,infx,size) copy_blob_byte(infx,a4gl,size,'o')
#define COPY_DATA_OUT_12(a4gl,infx,size) copy_blob_text(infx,a4gl,size,'o')
#define COPY_DATA_OUT_13(a4gl,infx,size) *strcpy(*(a4gl),*(infx))
#define COPY_DATA_OUT_14(a4gl,infx,size) copy_interval(infx,a4gl,size,'o')


#define COPY_SQLCA
#define popdec(x) {fgldecimal _s;pop_var(&_s,0x1e100005);copy_decimal(x,&_s,0x1e10,'i');}
#define retdec(x) {fgldecimal _s;copy_decimal(x,&_s,0x1e10,'o');push_variable(&_s,0x1e100005);}


#define popdtime(x) {char *_s;_s=char_pop();dtcvasc(_s,&x);free(_s);}

#define retdtime(x) {char _s[123];dttoasc(&x,_s);push_char(_s);}
#ifdef __cplusplus
}
#endif
