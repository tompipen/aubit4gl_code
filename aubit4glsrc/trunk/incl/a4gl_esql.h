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


#include "a4gl_incl_4glhdr.h"
#include "a4gl_libaubit4gl.h"
#define GETENV_OK 
#ifdef DIALECT_INFORMIX
#include "a4gl_esql_infx.h"
#endif

#ifdef DIALECT_POSTGRES
#include "a4gl_esql_postgres.h"
#endif
