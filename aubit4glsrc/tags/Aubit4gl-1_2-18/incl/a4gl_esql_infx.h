/*******************************************************************
* (c) 1997-2002 Aubit Computing Ltd.
*
* This header file should detect the current ESQL/C compiler as
* set the datatype conversion routines as required...
********************************************************************/


/*
#
# $Id: a4gl_esql_infx.h,v 1.32 2008-05-10 08:02:19 mikeaubury Exp $
#
*/

/**
 * @file
 *
 * Definition of structures and typedefs necessary for the ...
 */


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

#include <stdio.h>
#include <stdlib.h>
/*
 * WARNING: POSTGRESQL ECPG COMPILER AND AUBIT (in incl/compat) ALSO HAVE FILE decimal.h !!!
 [root@aptiva aubit4glsrc]# find /opt/informix/ -name decimal.h
	/opt/informix/incl/tools/decimal.h
	/opt/informix/incl/esql/decimal.h
	/opt/informix/incl/public/decimal.h
	/opt/informix/incl/dmi/decimal.h
 * MAKE SURE YOU REFER TO THIS FILE WITH FIXED PATH IN INCLUDE STATMENT, LIKE THIS:
 * #include "esql/decimal.h" 
*/
/*#include "decimal.h" */
#include "esql/decimal.h"
#include "datetime.h"
#include "sqltypes.h"
#include "a4gl_incl_4gldef.h"
#include "a4gl_incl_infx.h"
#include "ifxtypes.h"

#ifndef TARGETDIALECT
#define TARGETDIALECT "INFORMIX"
#endif

#ifdef __cplusplus
extern "C"
{
#endif
  /*
  //void A4GL_copy_money (dec_t * infx, fglmoney * a4gl, int indicat,int size, char dir); 
  //void A4GL_copy_decimal (dec_t * infx, fgldecimal * a4gl, int indicat,int size, char dir);
  //void A4GL_copy_datetime (dtime_t * infx, struct A4GLSQL_dtime *a4gl, int indicat,int size, int mode);
  */

/*
// Conversion functions between informix types and A4GL datatypes
//void A4GL_copy_decimal (struct decimal *infx, fgldecimal * a4gl, int indicat,int size, char dir);
*/

#define COPY_DATA_IN_0(a4gl,infx,xi,size,x,y) A4GL_copy_char(infx,a4gl,xi,size,'i',x,y)
#define COPY_DATA_IN_1(a4gl,infx,xi,size) A4GL_copy_smint(infx,a4gl,xi,size,'i')
#define COPY_DATA_IN_2(a4gl,infx,xi,size) A4GL_copy_int(infx,a4gl,xi,size,'i')
#define COPY_DATA_IN_3(a4gl,infx,xi,size) A4GL_copy_double(infx,a4gl,xi,size,'i')
#define COPY_DATA_IN_4(a4gl,infx,xi,size) A4GL_copy_float(infx,a4gl,xi,size,'i')
#define COPY_DATA_IN_5(a4gl,infx,xi,size) A4GL_copy_decimal(infx,a4gl,xi,size,'i')
#define COPY_DATA_IN_6(a4gl,infx,xi,size) A4GL_copy_int(infx,a4gl,xi,size,'i')
#define COPY_DATA_IN_7(a4gl,infx,xi,size) A4GL_copy_date(infx,a4gl,xi,size,'i')
#define COPY_DATA_IN_8(a4gl,infx,xi,size) A4GL_copy_money(infx,a4gl,xi,size,'i')
#define COPY_DATA_IN_9(a4gl,infx,xi,size) A4GL_copy_int(infx,a4gl,xi,size,'i')
#define COPY_DATA_IN_10(a4gl,infx,xi,size) A4GL_copy_datetime(infx,a4gl,xi,size,'i')
#define COPY_DATA_IN_11(a4gl,infx,xi,size) A4GL_copy_blob_byte(infx,a4gl,xi,size,'i')
#define COPY_DATA_IN_12(a4gl,infx,xi,size) A4GL_copy_blob_text(infx,a4gl,xi,size,'i')
#define COPY_DATA_IN_13(a4gl,infx,xi,size,x,y) A4GL_copy_char(infx,a4gl,xi,size,'i',x,y)
#define COPY_DATA_IN_14(a4gl,infx,xi,size) A4GL_copy_interval(infx,a4gl,xi,size,'i')

#define COPY_DATA_OUT_0(a4gl,infx,xi,size,x,y) A4GL_copy_char(infx,a4gl,xi,size,'o',x,y)
#define COPY_DATA_OUT_1(a4gl,infx,xi,size) A4GL_copy_smint(infx,a4gl,xi,size,'o')
#define COPY_DATA_OUT_2(a4gl,infx,xi,size) A4GL_copy_int(infx,a4gl,xi,size,'o')
#define COPY_DATA_OUT_3(a4gl,infx,xi,size) A4GL_copy_double(infx,a4gl,xi,size,'o')
#define COPY_DATA_OUT_4(a4gl,infx,xi,size) A4GL_copy_float(infx,a4gl,xi,size,'o')
#define COPY_DATA_OUT_5(a4gl,infx,xi,size) A4GL_copy_decimal(infx,a4gl,xi,size,'o')
#define COPY_DATA_OUT_6(a4gl,infx,xi,size) A4GL_copy_int(infx,a4gl,xi,size,'o')
#define COPY_DATA_OUT_7(a4gl,infx,xi,size) A4GL_copy_date(infx,a4gl,xi,size,'o')
#define COPY_DATA_OUT_8(a4gl,infx,xi,size) A4GL_copy_money(infx,a4gl,xi,size,'o')
#define COPY_DATA_OUT_9(a4gl,infx,xi,size) A4GL_copy_int(infx,a4gl,xi,size,'o')
#define COPY_DATA_OUT_10(a4gl,infx,xi,size) A4GL_copy_datetime(infx,a4gl,xi,size,'o')
#define COPY_DATA_OUT_11(a4gl,infx,xi,size) A4GL_copy_blob_byte(infx,a4gl,xi,size,'o')
#define COPY_DATA_OUT_12(a4gl,infx,xi,size) A4GL_copy_blob_text(infx,a4gl,xi,size,'o')
#define COPY_DATA_OUT_13(a4gl,infx,i,size,x,y) A4GL_copy_char(infx,a4gl,xi,size,'o',x,y)
#define COPY_DATA_OUT_14(a4gl,infx,xi,size) A4GL_copy_interval(infx,a4gl,xi,size,'o')
#ifdef _FGL_
#define A4GLSQL_SET_SQLCA_SQLWARN A4GL_copy_sqlca_sqlawarn_string8(sqlca.sqlawarn)
#else
#define A4GLSQL_SET_SQLCA_SQLWARN A4GL_copy_sqlca_sqlawarn_8chars(sqlca.sqlwarn.sqlwarn0,sqlca.sqlwarn.sqlwarn1,sqlca.sqlwarn.sqlwarn2,sqlca.sqlwarn.sqlwarn3,sqlca.sqlwarn.sqlwarn4, sqlca.sqlwarn.sqlwarn5, sqlca.sqlwarn.sqlwarn6, sqlca.sqlwarn.sqlwarn7)

#endif

#undef ALWAYS_CONVERT_PREPARED


#ifdef ALWAYS_CONVERT_PREPARED
#define CONVERTSQL(s) A4GLSQLCV_convert_sql_ml(A4GL_get_target_dialect("INFORMIX",TARGETDIALECT),s,_module_name,__LINE__)
#define CONVERTSQL_LN(s,l) A4GLSQLCV_convert_sql_ml(A4GL_get_target_dialect("INFORMIX",TARGETDIALECT),s,_module_name,l)
#else
#define CONVERTSQL(s) s
#define CONVERTSQL_LN(s,l) s
#endif



#define LEXDIALECT_TYPE "INFORMIX"


#define COPY_SQLCA

/*
//#define popdec(x) {fgldecimal _s;A4GL_pop_var(&_s,0x1e100005);A4GL_copy_decimal(x,&_s,0x1e10,'i');}
//#define retdec(x) {fgldecimal _s;A4GL_copy_decimal(x,&_s,0x1e10,'o');A4GL_push_variable(&_s,0x1e100005);}
//#define popdtime(x) {char *_s;_s=A4GL_char_pop();dtcvasc(_s,&x);free(_s);}
//#define retdtime(x) {char _s[123];dttoasc(&x,_s);push_char(_s);}
*/

#ifdef __cplusplus
}
#endif
