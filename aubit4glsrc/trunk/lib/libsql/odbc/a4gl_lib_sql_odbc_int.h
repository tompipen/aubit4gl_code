

#ifdef __CYGWIN__
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

		#include <incl/cli/infxcli.h>
		#include <incl/cli/infxsql.h>
		#define __UCHAR_DEFINED__
	    #define __ODBC_DEFINED__
		/* #include <incl/cli/sqlucode.h> */
	#endif

	#ifdef PGODBC
			#include <pgsql/iodbc/iodbc.h>
			/* #include <pgsql/iodbc/isql.h> */
			#include <pgsql/iodbc/isqlext.h>

            /* NOTHING WE CAN DO:
            /usr/include/pgsql/iodbc/isqlext.h:1344: warning: redundant redeclaration of `SQLNumResultCols' in same scope
			/usr/include/pgsql/iodbc/isql.h:210: warning: previous declaration of `SQLNumResultCols'
            */

			#define __UCHAR_DEFINED__
		    #define __ODBC_DEFINED__
	#endif

    #ifndef __ODBC_DEFINED__
        /* default for tesing, when we don't use makefile we will not have -Dxxx
		 unixODBC headers: */
		#include <sql.h>
		#include <sqlext.h>
		#include <odbcinst.h>
		#define __UCHAR_DEFINED__
	    #define __ODBC_DEFINED__
	#endif

#endif


    #include "a4gl_lib_sql_int.h"


