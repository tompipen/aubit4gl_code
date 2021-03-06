#ifdef HAVE_CONFIG_H
	//../../../incl/
	#include "a4gl_incl_config.h"
#endif




#if (defined (__CYGWIN__) || defined (__MINGW32__))
	#include <windows.h>
	#include <sqlext.h>
#else
	#ifdef UNIXODBC
		#include <sql.h>
		#include <sqlext.h>
		#include <odbcinst.h>
		#define __UCHAR_DEFINED__
		#define __ODBC_DEFINED__
	#endif

	#ifdef IODBC
		#ifdef OLDIODBC
			#include <iodbc.h>
			#include <isql.h>
			#include <isqlext.h>
		#else
			#include <sql.h>
			#include <sqlext.h>
			#include <sqltypes.h>
		#endif

		#define __UCHAR_DEFINED__
		#define __ODBC_DEFINED__
	#endif

	#ifdef IFXODBC
		/* infromix headers require wchar_t to be already defined
		   so we have to include stdio.h here */
		#include <stdio.h>
		#include <wchar.h>

		#include <incl/cli/infxcli.h>
		#include <incl/cli/infxsql.h>
		#define __UCHAR_DEFINED__
		#define __ODBC_DEFINED__
		/* #include <incl/cli/sqlucode.h> */
	#endif
	
	#ifdef PGODBC
		#if HAVE_PGODBC_HEADERS
			//use headers supplied with PGODBC 
			
			//prevent inclusion of any more headers
			#define __INCLUDED_HEADERS__ 
			#include <pgsql/iodbc/iodbc.h>
			/* #include <pgsql/iodbc/isql.h> */
			#include <pgsql/iodbc/isqlext.h>
	
			/* NOTHING WE CAN DO:
			   /usr/include/pgsql/iodbc/isqlext.h:1344: warning: redundant redeclaration of `SQLNumResultCols' in same scope
			   /usr/include/pgsql/iodbc/isql.h:210: warning: previous declaration of `SQLNumResultCols'
			 */
	
			#define __UCHAR_DEFINED__
			#define __ODBC_DEFINED__
			/*
			  PostgreSQL headers don't define SQLHSTMT
			*/
			#ifndef FAR
				#define FAR
			#endif
			typedef void FAR *SQLHANDLE;
			typedef SQLHANDLE SQLHSTMT;
		#endif
		
		#if ((HAVE_UNIXODBC_HEADERS) && ! defined (__INCLUDED_HEADERS__))
			//use headers from unixODBC driver
			
			#define __INCLUDED_HEADERS__
		#endif
		
		#if ((HAVE_IODBC_HEADERS) && ! defined (__INCLUDED_HEADERS__))
			//use headers from iodbc driver
			#define __INCLUDED_HEADERS__
			#include <sql.h>
			#include <sqlext.h>
			#include <sqltypes.h>
	
			#define __UCHAR_DEFINED__
			#define __ODBC_DEFINED__
		#endif
		
		#if ((HAVE_SAPODBC_HEADERS) && ! defined (__INCLUDED_HEADERS__))
			#define __INCLUDED_HEADERS__
			//use headers from SAP ODBC driver
		#endif
		#define SQLRETURN int
	#endif


	#ifdef SAPODBC
		#if (HAVE_SAPODBC_HEADERS_7500)
			#include "programs/incl/WINDOWS.H"
			#include "programs/incl/sql.h"	/* Header file for the ODBC driver (Core). */
			#include "programs/incl/sqlext.h"	/* Header file for the ODBC driver (Level1 and Level2). */
			#include "programs/incl/sqltypes.h"	/* Header file for the ODBC driver (Datatypes). */
		#else
			#include "interfaces/odbc/incl/WINDOWS.H"
				/*
				   incl/WINDOWS.H Header file for non-MS Windows platforms. On MS Windows 3.1 or
				   Windows NT, this file can be replaced by windows.h if an SDK has been installed.
				   Also defines thingsa like DWORD needed by followint headers.
				 */
	
			#include "interfaces/odbc/incl/sql.h"	/* Header file for the ODBC driver (Core). */
			#include "interfaces/odbc/incl/sqlext.h"	/* Header file for the ODBC driver (Level1 and Level2). */
			#include "interfaces/odbc/incl/sqltypes.h"	/* Header file for the ODBC driver (Datatypes). */
		#endif
		#define __UCHAR_DEFINED__
		#define __ODBC_DEFINED__
	#endif

    #ifdef SQLITEODBC
        /* SQLite ODBC driver does not provide ODBC header files */
		#ifndef FAR
			#define FAR
		#endif
		#ifdef SIMPLIFIED
			//Looks like Mike's private thing?
			#include "odbc_headers/sql.h"
			#include "odbc_headers/sqlext.h"
		#else
			//use headers we have in Aubit CVS:
			#include "../../../tools/odbctest/incl/sql.h"
			#include "../../../tools/odbctest/incl/sqlext.h"
		#endif
		//#include <odbcinst.h>
		#define __UCHAR_DEFINED__
		#define __ODBC_DEFINED__
    #endif

	#ifndef __ODBC_DEFINED__
		/* default for tesing, when we don't use makefile we will not have -Dxxx
	   unixODBC headers: */
	   	#include <should-not-happen.h>
		#include <sql.h>
		#include <sqlext.h>
		#include <odbcinst.h>
		#define __UCHAR_DEFINED__
		#define __ODBC_DEFINED__
	#endif

#endif

#undef min
#define min(a, b) ((a) < (b) ? (a) : (b))
#undef max
#define max(a, b) ((a) < (b) ? (b) : (a))

#ifndef SQL_NO_DATA_FOUND
#define SQL_NO_DATA_FOUND SQL_NO_DATA
#endif


int A4GL_new_hstmt (HSTMT * hstmt);
int A4GL_free_hstmt (SQLHSTMT *phstmt);


int A4GL_chk_rc_full (SQLRETURN rc, void *hstmt, char *c, int line, char *file);
int A4GL_set_sqlca (SQLHSTMT hstmt, char *s);
SQLUINTEGER A4GL_display_size (SQLSMALLINT coltype, SQLUINTEGER collen, SQLCHAR* colname);
void A4GL_init_typeinfo(void);
char * A4GL_type_id_to_name(int type_id);

int get_fake_error(char *sqlstate);
#include "a4gl_lib_sql_int.h"
#include "a4gl_API_sql_lib.h"
#include "a4gl_expr.h"

    /*  -------------- in sql.c ------------------ */

