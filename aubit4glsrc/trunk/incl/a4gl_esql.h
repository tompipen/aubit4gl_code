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

#ifndef A4GL_ESQL_H
#define A4GL_ESQL_H

#ifdef __cplusplus
extern "C"
{
#endif
//#include "a4gl_incl_4glhdr.h"
#define GETENV_OK
#include "a4gl_API_esql.h"

//Including a4gl_libaubit4gl.h here will force practicvally every header file
//in Aubit compiler to become a dependency when installing Aubit compiler.
//I compiled a lot of code, and did not find that there is a need for it.
//#include "a4gl_libaubit4gl.h"

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

#ifndef VALID_DIALECT_FOUND
	//default:
	#include "a4gl_esql_infx.h"
#endif

#ifdef __cplusplus
}
#endif
#endif
