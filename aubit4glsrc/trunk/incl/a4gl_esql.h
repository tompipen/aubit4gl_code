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


//#include "a4gl_incl_4glhdr.h"
#define GETENV_OK


//Including a4gl_libaubit4gl.h here will force practicvally every header file
//in Aubit compiler to become a dependency when installing Aubit compiler.
//I compiled a lot of code, and did not find that there is a need for it.
//#include "a4gl_libaubit4gl.h"

#ifdef DIALECT_INFORMIX
	#include "a4gl_esql_infx.h"
	#define VALID_DIALECT_FOUND
#endif


#ifdef DIALECT_POSTGRES
	#include "a4gl_esql_postgres.h"
	#define VALID_DIALECT_FOUND
#endif

#ifndef VALID_DIALECT_FOUND
	#include "a4gl_esql_infx.h"
#endif
