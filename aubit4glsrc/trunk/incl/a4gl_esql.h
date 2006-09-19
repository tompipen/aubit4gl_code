/*******************************************************************
* (c) 1997-2002 Aubit Computing Ltd.
*
* This header file should detect the current ESQL/C compiler as
* set the datatype conversion routines as required...
********************************************************************/


/*
#
# $Id: a4gl_esql.h,v 1.22 2006-09-19 13:22:44 mikeaubury Exp $
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

#ifndef A4GL_ESQL_H
#define A4GL_ESQL_H

#ifdef __cplusplus
extern "C"
{
#endif
/*#include "a4gl_incl_4glhdr.h" */
#define GETENV_OK
#include "a4gl_API_esql.h"

/*
//Including a4gl_libaubit4gl.h here will force practicvally every header file
//in Aubit compiler to become a dependency when installing Aubit compiler.
//I compiled a lot of code, and did not find that there is a need for it.
//#include "a4gl_libaubit4gl.h"
*/

#ifdef DIALECT_INFORMIX
	#include "a4gl_esql_infx.h"
	#define VALID_DIALECT_FOUND
#endif

#ifdef DIALECT_INGRES
	#include "a4gl_esql_ingres.h"
	#define VALID_DIALECT_FOUND
#endif

#ifdef DIALECT_POSTGRES
	#include "a4gl_esql_postgres.h"
	#define VALID_DIALECT_FOUND
#endif

#ifdef DIALECT_QUERIX
	#include "a4gl_esql_querix.h"
	#define VALID_DIALECT_FOUND
#endif

#ifdef DIALECT_SAP
	#include "a4gl_esql_sap.h"
	#define VALID_DIALECT_FOUND
#endif

#ifdef DIALECT_INGRES
	#include "a4gl_esql_ingres.h"
	#define VALID_DIALECT_FOUND
#endif

#ifdef DIALECT_INFOFLEX
	#include "a4gl_esql_infoflex.h"
	#define VALID_DIALECT_FOUND
#endif

#ifndef VALID_DIALECT_FOUND
	/* default: */
	#include "a4gl_esql_infx.h"
#endif


void ESQLAPI_A4GLESQL_initlib(void);

//void ESQLAPI_A4GL_copy_char(char *infx,char *a4gl,short *p_indicat,int size,int mode,int x,int y);
//void ESQLAPI_A4GL_copy_date(long *infx,long *a4gl,short *p_indicat,int size,int mode);
//void ESQLAPI_A4GL_copy_datetime(void *infxv, void *a4glv,short *p_indicat,int size,int mode);
//void ESQLAPI_A4GL_copy_decimal(void *infxv,void *a4glv,short *p_indicat,int size,char mode);
//void ESQLAPI_A4GL_copy_double(double *infx,double *a4gl,short *p_indicat,int size,int mode);
//void ESQLAPI_A4GL_copy_float(float *infx,float *a4gl,short *p_indicat,int size,int mode);
//void ESQLAPI_A4GL_copy_int(long *infx,long *a4gl,short *p_indicat,int size,int mode);
//void ESQLAPI_A4GL_copy_interval(void *infxv, void *a4glv,short *p_indicat,int size,int mode)  ;
//void ESQLAPI_A4GL_copy_money(void *infxv,void *a4glv,short *p_indicat,int size,char mode);
//void ESQLAPI_A4GL_copy_smint(short *infx,short *a4gl,short *p_indicat,int size,int mode);


#ifdef __cplusplus
}
#endif





#endif


