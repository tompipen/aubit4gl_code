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



#ifdef DIALECT_INFORMIX
#include "a4gl_esql_infx.h"
#endif

#ifdef DIALECT_POSTGRES
#include "a4gl_esql_postgres.h"
#endif
