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

#include "a4gl_incl_4gldef.h"

#include "decimal.h"
#define COPY_DATA_IN_0(a4gl,pgres,size,x,y) A4GL_copy_char(pgres,a4gl,0,size,'i',x,y)
#define COPY_DATA_IN_1(a4gl,pgres,size) A4GL_copy_smint(pgres,a4gl,0,size,'i')
#define COPY_DATA_IN_2(a4gl,pgres,size) A4GL_copy_int(pgres,a4gl,0,size,'i')
#define COPY_DATA_IN_3(a4gl,pgres,size) A4GL_copy_double(pgres,a4gl,0,size,'i')
#define COPY_DATA_IN_4(a4gl,pgres,size) A4GL_copy_float(pgres,a4gl,0,size,'i')
#define COPY_DATA_IN_5(a4gl,pgres,size) A4GL_copy_decimal(pgres,a4gl,0,size,'i')
#define COPY_DATA_IN_6(a4gl,pgres,size) A4GL_copy_int(pgres,a4gl,0,size,'i')
#define COPY_DATA_IN_7(a4gl,pgres,size) A4GL_copy_int(pgres,a4gl,0,size,'i')
#define COPY_DATA_IN_8(a4gl,pgres,size) A4GL_copy_money(pgres,a4gl,0,size,'i')
#define COPY_DATA_IN_9(a4gl,pgres,size) A4GL_copy_int(pgres,a4gl,0,size,'i')
#define COPY_DATA_IN_10(a4gl,pgres,size) A4GL_copy_datetime(pgres,a4gl,0,size,'i')
#define COPY_DATA_IN_11(a4gl,pgres,size) A4GL_copy_blob_byte(pgres,a4gl,0,size,'i')
#define COPY_DATA_IN_12(a4gl,pgres,size) A4GL_copy_blob_text(pgres,a4gl,0,size,'i')
#define COPY_DATA_IN_13(a4gl,pgres,size) A4GL_copy_char(pgres,a4gl,0,size,'i')
#define COPY_DATA_IN_14(a4gl,pgres,size) A4GL_copy_interval(pgres,a4gl,0,size,'i')

#define COPY_DATA_OUT_0(a4gl,pgres,i,size,x,y) A4GL_copy_char(pgres,a4gl,i,size,'o',x,y)
#define COPY_DATA_OUT_1(a4gl,pgres,i,size) A4GL_copy_smint(pgres,a4gl,i,size,'o')
#define COPY_DATA_OUT_2(a4gl,pgres,i,size) A4GL_copy_int(pgres,a4gl,i,size,'o')
#define COPY_DATA_OUT_3(a4gl,pgres,i,size) A4GL_copy_double(pgres,a4gl,i,size,'o')
#define COPY_DATA_OUT_4(a4gl,pgres,i,size) A4GL_copy_float(pgres,a4gl,i,size,'o')
#define COPY_DATA_OUT_5(a4gl,pgres,i,size) A4GL_copy_decimal(pgres,a4gl,i,size,'o')
#define COPY_DATA_OUT_6(a4gl,pgres,i,size) A4GL_copy_int(pgres,a4gl,i,size,'o')
#define COPY_DATA_OUT_7(a4gl,pgres,i,size) A4GL_copy_int(pgres,a4gl,i,size,'o')
#define COPY_DATA_OUT_8(a4gl,pgres,i,size) A4GL_copy_money(pgres,a4gl,i,size,'o')
#define COPY_DATA_OUT_9(a4gl,pgres,i,size) A4GL_copy_int(pgres,a4gl,i,size,'o')
#define COPY_DATA_OUT_10(a4gl,pgres,i,size) A4GL_copy_datetime(pgres,a4gl,i,size,'o')
#define COPY_DATA_OUT_11(a4gl,pgres,i,size) A4GL_copy_blob_byte(pgres,a4gl,i,size,'o')
#define COPY_DATA_OUT_12(a4gl,pgres,i,size) A4GL_copy_blob_text(pgres,a4gl,i,size,'o')
#define COPY_DATA_OUT_13(a4gl,pgres,i,size) A4GL_copy_char(pgres,a4gl,i,size,'o')
#define COPY_DATA_OUT_14(a4gl,pgres,i,size) A4GL_copy_interval(pgres,a4gl,i,size,'o')






#define copy_sqlca

//#define dtime_t datetime


//#define popdec(x) {char *s;s=A4GL_char_pop();printf("%s\n",s);deccvasc(s,strlen(s),x); }
//#define retdec(x) {fgldecimal _s;A4GL_copy_decimal(x,&_s,0x1e10,'o');A4GL_push_variable(&_s,0x1e100005);}
