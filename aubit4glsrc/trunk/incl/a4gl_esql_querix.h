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
//#include "decimal.h"
//#include "datetime.h"
//#include "sqltypes.h"
#include "a4gl_incl_4gldef.h"
#include "a4gl_incl_infx.h"

#ifdef __cplusplus
extern "C"
{
#endif
/*
helper_funcs.c:30: `CDECIMALTYPE' undeclared (first use in this function)
helper_funcs.c:67: `CMONEYTYPE' undeclared (first use in this function)
helper_funcs.c:177: `CCHARTYPE' undeclared (first use in this function)
helper_funcs.c:199: `CDATETYPE' undeclared (first use in this function)
helper_funcs.c:240: `CLONGTYPE' undeclared (first use in this function)
*/

 /* C language types */
/* this list was taken from Informix sqltypes.h since this definitions do not 
exist in Querix or Aubit headers */
#define CCHARTYPE	100
#define CSHORTTYPE	101
#define CINTTYPE	102
#define CLONGTYPE	103
#define CFLOATTYPE	104
#define CDOUBLETYPE	105
#define CDECIMALTYPE	107
#define CFIXCHARTYPE	108
#define CSTRINGTYPE	109
#define CDATETYPE	110
#define CMONEYTYPE	111
#define CDTIMETYPE	112
#define CLOCATORTYPE    113
#define CVCHARTYPE	114
#define CINVTYPE	115
#define CFILETYPE	116
#define CINT8TYPE	117
#define CCOLLTYPE       118
#define CLVCHARTYPE     119
#define CFIXBINTYPE     120
#define CVARBINTYPE     121
#define CBOOLTYPE       122
#define CROWTYPE        123
#define CLVCHARPTRTYPE  124
#define CTYPEMAX	25




  //void A4GL_copy_money (dec_t * infx, fglmoney * a4gl, int indicat,int size, char dir);
  //void A4GL_copy_decimal (dec_t * infx, fgldecimal * a4gl, int indicat,int size, char dir);
  //void A4GL_copy_datetime (dtime_t * infx, struct A4GLSQL_dtime *a4gl, int indicat,int size, int mode);


// Conversion functions between informix types and A4GL datatypes
//void A4GL_copy_decimal (struct decimal *infx, fgldecimal * a4gl, int indicat,int size, char dir);

#define COPY_DATA_IN_0(a4gl,infx,size,x,y) A4GL_copy_char(infx,a4gl,0,size,'i',x,y)
#define COPY_DATA_IN_1(a4gl,infx,size) A4GL_copy_smint(infx,a4gl,0,size,'i')
#define COPY_DATA_IN_2(a4gl,infx,size) A4GL_copy_int(infx,a4gl,0,size,'i')
#define COPY_DATA_IN_3(a4gl,infx,size) A4GL_copy_double(infx,a4gl,0,size,'i')
#define COPY_DATA_IN_4(a4gl,infx,size) A4GL_copy_float(infx,a4gl,0,size,'i')
#define COPY_DATA_IN_5(a4gl,infx,size) A4GL_copy_decimal(infx,a4gl,0,size,'i')
#define COPY_DATA_IN_6(a4gl,infx,size) A4GL_copy_int(infx,a4gl,0,size,'i')
#define COPY_DATA_IN_7(a4gl,infx,size) A4GL_copy_date(infx,a4gl,0,size,'i')
#define COPY_DATA_IN_8(a4gl,infx,size) A4GL_copy_money(infx,a4gl,0,size,'i')
#define COPY_DATA_IN_9(a4gl,infx,size) A4GL_copy_int(infx,a4gl,0,size,'i')
#define COPY_DATA_IN_10(a4gl,infx,size) A4GL_copy_datetime(infx,a4gl,0,size,'i')
#define COPY_DATA_IN_11(a4gl,infx,size) A4GL_copy_blob_byte(infx,a4gl,0,size,'i')
#define COPY_DATA_IN_12(a4gl,infx,size) A4GL_copy_blob_text(infx,a4gl,0,size,'i')
#define COPY_DATA_IN_13(a4gl,infx,size) A4GL_copy_char(infx,a4gl,0,size,'i')
#define COPY_DATA_IN_14(a4gl,infx,size) A4GL_copy_interval(infx,a4gl,0,size,'i')

#define COPY_DATA_OUT_0(a4gl,infx,i,size,x,y) A4GL_copy_char(infx,a4gl,i,size,'o',x,y)
#define COPY_DATA_OUT_1(a4gl,infx,i,size) A4GL_copy_smint(infx,a4gl,i,size,'o')
#define COPY_DATA_OUT_2(a4gl,infx,i,size) A4GL_copy_int(infx,a4gl,i,size,'o')
#define COPY_DATA_OUT_3(a4gl,infx,i,size) A4GL_copy_double(infx,a4gl,i,size,'o')
#define COPY_DATA_OUT_4(a4gl,infx,i,size) A4GL_copy_float(infx,a4gl,i,size,'o')
#define COPY_DATA_OUT_5(a4gl,infx,i,size) A4GL_copy_decimal(infx,a4gl,i,size,'o')
#define COPY_DATA_OUT_6(a4gl,infx,i,size) A4GL_copy_int(infx,a4gl,i,size,'o')
#define COPY_DATA_OUT_7(a4gl,infx,i,size) A4GL_copy_date(infx,a4gl,i,size,'o')
#define COPY_DATA_OUT_8(a4gl,infx,i,size) A4GL_copy_money(infx,a4gl,i,size,'o')
#define COPY_DATA_OUT_9(a4gl,infx,i,size) A4GL_copy_int(infx,a4gl,i,size,'o')
#define COPY_DATA_OUT_10(a4gl,infx,i,size) A4GL_copy_datetime(infx,a4gl,i,size,'o')
#define COPY_DATA_OUT_11(a4gl,infx,i,size) A4GL_copy_blob_byte(infx,a4gl,i,size,'o')
#define COPY_DATA_OUT_12(a4gl,infx,i,size) A4GL_copy_blob_text(infx,a4gl,i,size,'o')
#define COPY_DATA_OUT_13(a4gl,infx,i,size) A4GL_copy_char(infx,a4gl,i,size,'o')
#define COPY_DATA_OUT_14(a4gl,infx,i,size) A4GL_copy_interval(infx,a4gl,i,size,'o')




#define COPY_SQLCA
//#define popdec(x) {fgldecimal _s;A4GL_pop_var(&_s,0x1e100005);A4GL_copy_decimal(x,&_s,0x1e10,'i');}
//#define retdec(x) {fgldecimal _s;A4GL_copy_decimal(x,&_s,0x1e10,'o');A4GL_push_variable(&_s,0x1e100005);}


//#define popdtime(x) {char *_s;_s=A4GL_char_pop();dtcvasc(_s,&x);free(_s);}
//#define retdtime(x) {char _s[123];dttoasc(&x,_s);push_char(_s);}

#ifdef __cplusplus
}
#endif
