/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-1 Aubit Development Team (See Credits file)       |
# +----------------------------------------------------------------------+
# | This program is free software; you can redistribute it and/or modify |
# | it under the terms of one of the following licenses:                 |
# |                                                                      |
# |  A) the GNU General Public License as published by the Free Software |
# |     Foundation; either version 2 of the License, or (at your option) |
# |     any later version.                                               |
# |                                                                      |
# |  B) the Aubit License as published by the Aubit Development Team and |
# |     included in the distribution in the file: LICENSE                |
# |                                                                      |
# | This program is distributed in the hope that it will be useful,      |
# | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
# | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
# | GNU General Public License for more details.                         |
# |                                                                      |
# | You should have received a copy of both licenses referred to here.   |
# | If you did not, or have any questions about Aubit licensing, please  |
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: sql.c,v 1.92 2004-11-25 15:38:59 mikeaubury Exp $
#
*/

/**
 * @file
 * ODBC Sql execution implementation
 *
 * @todo Doxygen A4GL_comments to add to functions
 */


/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_lib_sql_odbc_int.h"
#if (ODBCVER >= 0x0300)
#define USE_TIMESTAMP
#else
#define DTIME_AS_CHAR
#endif

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

/*
#ifndef TRUE
	#define TRUE 1
#endif
#ifndef FALSE
	#define FALSE 0
#endif
*/


void * A4GLSQL_prepare_sql_internal (char *s);
void * A4GLSQL_find_prepare (char *pname);
int A4GLSQL_execute_sql (char *pname, int ni, void *vibind) ;
void * A4GLSQL_prepare_glob_sql_internal (char *s, int ni, void *vibind);
int A4GLSQL_make_connection (char * server, char * uid_p, char * pwd_p);
void * A4GL_bind_datetime (void *ptr_to_dtime_var);
void A4GL_decode_datetime (struct A4GLSQL_dtime *d, int *data);
#define FETCH_ABSOLUTE 		1
#define FETCH_RELATIVE 		2
#define DTYPE_DATE 			7
//#define A4GL_exitwith 			A4GL_exitwith_sql
#define MAXCURSORS 			100
#define MAXPREPARE 			100
#define MAXCOLS 			100
#define MAX_NUM_PRECISION 	15
#define MAX_NUM_STRING_SIZE (MAX_NUM_PRECISION + 5)


#define chk_rc(rc,stmt,call) A4GL_chk_rc_full(rc,(void *)stmt,call,__LINE__,__FILE__)


#ifndef __MINGW32__
	#define max(a,b) (a>b?a:b)
	/* windef.h:

	#ifndef NOMINMAX
	#ifndef max
	#define max(a,b) ((a)>(b)?(a):(b))
    */

#endif

/**
 * Define max length of char string representation of
 * number as: = max(precision) + leading sign + E +
 * exp sign + max exp length
 * =  15 + 1 + 1 + 1 + 2
 * =  15 + 5
 */

#define strlen(a) (strlen((char *)a))
#define fgl_size(a,b) (fgl_sizes[a]==-1?b+1:fgl_sizes[a])

#ifdef _WIN32
	#define ODBC_INI "ODBC.INI"
#else
	#define ODBC_INI ".odbc.ini"
#endif

#undef min
#define min(a, b) ((a) < (b) ? (a) : (b))
#undef max
#define max(a, b) ((a) < (b) ? (b) : (a))
#define SQLRETURN int


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


//truct expr_str *A4GLSQL_get_validation_expr(char *tabname,char *colname) ;
struct s_cid *A4GLSQL_find_cursor (char *cname);
struct s_cid *A4GLSQL_free_cursor (char *cname);
struct expr_str *A4GL_add_validation_elements_to_expr(struct expr_str *ptr,char *val) ;
void * A4GL_new_expr (char *value);
void * A4GL_append_expr (struct expr_str *orig_ptr, char *value);
char *A4GL_conv_date (char *s);
int A4GL_find_prepare2 (char *pname);
struct s_sid *find_prepare (char *pname);
int A4GL_find_cursor_for_decl (char *cname);
int A4GL_proc_bind (struct BINDING *b, int n, char t, HSTMT hstmt);
void A4GL_ibind_column_arr (int pos, char *s, HSTMT hstmt);
void *A4GL_bind_date (long *ptr_to_date_var);
void A4GL_ibind_column (int pos, struct BINDING *bind, HSTMT hstmt);
void A4GL_obind_column (int pos, struct BINDING *bind, HSTMT hstmt);
void A4GL_post_fetch_proc_bind (struct BINDING *use_binding, int use_nbind,
			   HSTMT hstmt);
void A4GL_add_cursor (struct s_cid *cid, char *cname);
int ODBC_exec_prepared_sql (SQLHSTMT hstmt);
int ODBC_exec_stmt (SQLHSTMT hstmt);
int ODBC_exec_select (SQLHSTMT hstmt);
int ODBC_exec_sql (UCHAR * sqlstr);
int ODBC_disconnect (void);
void ODBC_set_dbms_info (void);
int A4GL_sqlerrwith (int rc, HSTMT h);
int A4GL_chk_need_blob (int rc, HSTMT hstmt);
int A4GL_chk_getenv (char *s, int a);
static int conv_sqldtype (int sqldtype, int sdim);
char *A4GL_decode_rc (int a);
RETCODE SQL_API A4GL_newSQLSetParam (SQLHSTMT hstmt, UWORD ipar, SWORD fCType,
				SWORD fSqlType, UDWORD cbColDef,
				SWORD ibScale, PTR rgbValue,
				SDWORD FAR * pcbValue);
char *A4GL_ret_sql_err (void);
int print_err (HDBC hdbc, HSTMT hstmt);
long A4GL_describecolumn (SQLHSTMT hstmt, int colno, int type);
int set_stmt_options (char *cursname, char *opt, char *val);

#ifndef DONTINCLUDEDATASOURCES
#ifdef PGODBC
RETCODE SQL_API SQLDataSources (HENV henv, UWORD fDirection,
				UCHAR FAR * szDSN, SWORD cbDSNMax,
				SWORD FAR * pcbDSN, UCHAR FAR * szDescription,
				SWORD cbDescriptionMax,
				SWORD FAR * pcbDescription);
#endif
#endif

/* in sqlex.c */
extern int A4GL_set_blob_data (SQLHSTMT hstmt);
extern int A4GL_get_blob_data (struct fgl_int_loc *blob, HSTMT hstmt, int colno);

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

/* extern: */
extern char lasterrorstr[1024];

/* static: */
static char sess_name[32] = "default";
//must be long enough to hold full path for SQLlite database file
//static char OldDBname[64] = "";
static char OldDBname[2048] = "";
static char dbms_name[64] = "";
static char dbms_dialect[64] = "";
static HSTMT hstmtGetColumns = 0;	/** Statement used to iterate getting column information */
static char cn[256];					/** Column name */
static int dt;
static long prec;					/** Precision */
static int colsize;							/** Coulmn size */
static char szcolsize[20];

/* unknown: */
int rc;
int do_init_cursors = 1;
int do_init_prepare = 1;
char buffer[256];
HENV henv = 0;
HDBC hdbc = 0;					/** The database connection handle */
SDWORD outlen[512];

struct cursors
{
  struct s_cid *cid;
  char *cname;
}
 ;

struct stmts
{
  struct s_sid *sid;
  char *pname;
}
 ;

 /**
 * Definition of a date
 */
typedef struct tagACLDATE
{
  DATE_STRUCT date;
  long *ptr;
}
ACLDATE;

typedef struct tagACLDTIME
{
#ifdef DTIME_AS_CHAR
  char dtime[65];
#else
  TIMESTAMP_STRUCT dtime;
#endif
  struct A4GLSQL_dtime *ptr;
}
ACLDTIME;


/**
 * Conversion table between 4gl and C data types.
 */
int conv_4gl_to_c[] = {
  SQL_C_CHAR,
  SQL_C_SHORT,
  SQL_C_LONG,
  SQL_C_DOUBLE,
  SQL_C_FLOAT,
  SQL_C_DOUBLE,			/* decimal != double  need to change this */
  SQL_C_LONG,
  SQL_C_DATE,
  SQL_C_DOUBLE,			/* as for decimal,  money != double */
  9999,
#ifdef DTIME_AS_CHAR
  SQL_C_CHAR,
#else
#ifdef SQL_C_DATETIME
  SQL_C_DATETIME,     // Was timestamp
#else
  SQL_C_TIMESTAMP,     // Was timestamp
#endif
#endif
  SQL_C_BINARY,
  SQL_C_BINARY,
  SQL_C_CHAR,
  SQL_C_TIME
};

/**
 * Table of 4gl sizes.
 */
int fgl_sizes[] = {
  -1,
  sizeof (short),
  sizeof (long),
  sizeof (double),
  sizeof (float),
  sizeof (double),
  sizeof (long),
  sizeof (long),
  sizeof (double),
  0,
  0,
  0,
  0,
  -1,
  0
};

/**
 *
 */
int convpos_sql_to_4gl[15] = {
  9999,				/** 0 */
  0,				/** SQL_CHAR */
  3,				/** SQL_NUMERIC */
  5,				/** SQL_DECIMAL */
  2,				/** SQL_INTEGER */
  1,				/** SQL_SMINT */
  3,				/** SQL_FLOAT  */
  4,				/** SQL_REAL */
  3,				/** SQL_DOUBLE  8 */
  7,				/** SQL_DATE 9  */
  10,				/** SQL_TIME 10 */
  10,				/** SQL_TIMESTAMP 11 */
  0				/** SQL_VARCHAR  12 */
};


/**
 *
 */
int convneg_sql_to_4gl[15] = {
  9999,				/** 0 */
  12,				/** SQL_LONGVARCHAR */
  11,				/** SQL_BINARY */
  11,				/** SQL_VARBINARY */
  11,				/** SQL_LONGVARBINARY */
  2,				/** SQL_BIGINT */
  1,				/** SQL_TINYINT */
  1				/** SQL_BIT */
};

/*
=====================================================================
                    Platform specific definitions
=====================================================================
*/

#if (defined(WIN32) && ! defined(__CYWIN__))	/* && defined DLL_EXPORT */

dll_export sqlca_struct a4gl_sqlca;
dll_export int status;

#include <windows.h>
int WINAPI
libSQL_odbc32_init (HANDLE h, DWORD reason, void *foo)
{
  return 1;
}

char
libSQL_odbc32_is_dll (void)
{
  return 1;
}
#endif /* WIN32 && DLL_EXPORT */


dll_import sqlca_struct a4gl_sqlca;


/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Assign a value to the status global variable.
 *
 * @param a  The value to be set in status.
 * @param sql A Flag that indicate if sqlca.sqlcode will be assigned too:
 *   - 0 : sqlca.sqlcode will be not assigned.
 *   - Otherwise : sqlca.sqlcode will be assigned.
 */
void
A4GLSQL_set_status (int a, int sql)
{

  a4gl_status = a;
  if (sql)
    a4gl_sqlca.sqlcode = a;
  A4GL_debug ("Status set to %d", a);
}

char* A4GLSQL_get_errmsg(int a) { return 0; }

/**
 * Check if there was an error and set sqlca.
 *
 * @param rc The return call error.
 * @param hstmt The statement handle.
 * @param c  A string to identify who and wy called this
 * @param line Used just for debug
 * @param file Used just for debug
 */
void
A4GL_chk_rc_full (int rc, void *hstmt, char *c, int line, char *file)
{
  A4GL_debug ("Chk_rc_full : rc=%d (%s) stmt=%p c=%s line=%d file=%s", rc,
	 A4GL_decode_rc (rc), hstmt, c, line, file);

  if (rc == SQL_SUCCESS || rc==SQL_SUCCESS_WITH_INFO)
    {
      A4GLSQL_set_status (0, 1);
      return;
    }


  if (hstmt)
    {
      if (rc == SQL_NO_DATA_FOUND)
	{
	  A4GLSQL_set_sqlca_sqlcode (100);
/* A4GL_set_sqlca (hstmt, c, 0,0 ); *//* no error */
	  A4GLSQL_set_status (100, 1);
	  return;
	}
      A4GL_set_sqlca ((SQLHSTMT)hstmt, c, 0);
    }
}

/**
 * Sets the parameters of an SQL statement.
 *
 * This is where the ODBC call to SQLBindParameter() is made.
 *
 * @param hstmt Statement information handle.
 * @param ipar Position of the parameter.
 * @paramfCType Data type
 * @param fSqlType Data type
 * @param cbColDef
 * @param ibScale
 * @param rgbValue Pointer to the place wher the informationshould be used.
 * @param pcbValue
 */
RETCODE SQL_API
A4GL_newSQLSetParam (SQLHSTMT hstmt, UWORD ipar, SWORD fCType,
		SWORD fSqlType, UDWORD cbColDef, SWORD ibScale, PTR rgbValue,
		SDWORD FAR * pcbValue)
{
  int rc;
  static SDWORD cbval;

  A4GL_debug ("Setting parameter %d to type %d (%d) %d (%d)", ipar, fSqlType,
	 SQL_C_BINARY, fCType, SQL_PARAM_INPUT);

  if (fCType == SQL_C_BINARY)
    {
      A4GL_debug ("Setting blob data");
      cbval = 0;
      rc =
	SQLBindParameter (hstmt, ipar, SQL_PARAM_INPUT, SQL_C_BINARY,
			  SQL_LONGVARBINARY, 0, 0, rgbValue, 0, &cbval);
      cbval = SQL_LEN_DATA_AT_EXEC (64000);
      chk_rc (rc, hstmt, "SQLBindParameter");
      return rc;
    }

  rc = SQLBindParameter (hstmt, ipar, SQL_PARAM_INPUT,
			 fCType, fSqlType, cbColDef, ibScale, rgbValue,
			 3200, pcbValue);

  chk_rc (rc, hstmt, "SQLBindParameter");

  A4GL_debug ("cbval was set to %d after call", cbval);

  A4GL_debug ("All done returning rc=%d\n", rc);
  return rc;
}

/**
 * Count the number of ? parameter placeholders in a query string.
 *
 * @param s A string with the query.
 * @return The number of ? found in the query.
 */
static int
count_queries (char *s)
{
  char *ptr;
  int cnt = 0;
  char quote = 0;
  int slash = 0;
  /* count only the unquoted ?'s, ie. those that are not within
   * single/double quote strings or preceded by a backslash 
   */
  for (ptr = s; ptr && *ptr > 0; ptr++)
    {
      if (slash)
	{
	  slash = 0;
	  continue;
	}
      switch (*ptr)
	{
	case '\\':
	  slash = 1;
	  break;
	case '\"':
	case '\'':
	  if (quote == *ptr)
	    {
	      quote = 0;
	    }
	  else
	    {
	      if (quote == 0)
		{
		  quote = *ptr;
		}
	    }
	  break;
	case '?':
	  if (quote == 0)
	    cnt++;
	  break;
	}
    }
  A4GL_debug ("count_queries() found %d ?'s in string %s", cnt, s);
  return cnt;
}

/**
 * Process the binding of the variables to the statement.
 *
 * After this, the SQL statemen knows where to put or get values.
 *
 * @param b A pointer to the varaiable binding structure.
 * @param n The number of elements in the binding array.
 * @param t The bind type
 *   - i :  Input binding.
 *   - o :  Output binding.
 * @param hstmt Statement handle.
 * @return
 *   - 0 : An error ocurred.
 *   - 1 : Done.
 */
int
A4GL_proc_bind (struct BINDING *b, int n, char t, HSTMT hstmt)
{
  int a;
  SWORD nin=0;

  if (b == 0)
    return 0;


#ifdef DEBUG
  A4GL_debug ("In proc_bind...");
  A4GL_debug ("   Binding %p n=%d t=%c, stmt=%p", b, n, t, hstmt);
#endif


  if (t == 'i')
    {
      rc = SQLNumParams (hstmt, &nin);
      chk_rc (rc, hstmt, "SQLNumParams");

#ifdef DEBUG
      A4GL_debug ("Found %d parameters are required...", nin);
#endif

      if (n != nin)
	{


#ifdef DEBUG
	  A4GL_debug ("Number of host variables does not A4GL_match %d (given) !=%d (in sql)", n, nin);
#endif

	  return 0;
	}

#ifdef DEBUG
      A4GL_debug ("Looks like we have the right number..");
#endif

    }

  for (a = 1; a <= n; a++)
    {


#ifdef DEBUG
      A4GL_debug ("Binding parameter %d ", a);
#endif

      if (t == 'o')
	{
	  A4GL_obind_column (a, &b[a - 1], hstmt);
	}
      else
	{

	  A4GL_ibind_column (a, &b[a - 1], hstmt);
	}

#ifdef DEBUG
      A4GL_debug ("DOne...");
#endif
    }
  return 1;
}

/**
 * Find a cursor in the pointer tree.
 *
 * @param cname The name of the cursor to be found.
 * @return A pointer to the cursor information.
 */
struct s_cid *
A4GLSQL_find_cursor (char *cname)
{
  struct s_cid *ptr;

  ptr = (struct s_cid *) A4GL_find_pointer_val (cname, CURCODE);
  if (ptr)
    return ptr;
  A4GL_exitwith ("Cursor not found");
  return 0;
}

/**
 * Check if a cursor exists in the pointer tree.
 *
 * @param cname The name of the cursor to be found.
 * @return If the cursor exists:
 *   - 0 : The cursor does not exist.
 *   - 1 : The cursor exist.
 */
int
A4GL_find_cursor_for_decl (char *cname)
{
  if (A4GL_find_pointer_val (cname, CURCODE))
    return 1;
  else
    return 0;
}


#ifdef IS_THIS_USED
/**
 * Prepare an sql statement.
 *
 * @param s A string with the sql statement to be prepared.
 * @return A pointer to the statement information structure.
 */
void * A4GLSQL_prepare_sql_internal (char *s)
{
  struct s_sid *sid;
  int rc;

#ifdef DEBUG
  A4GL_debug ("prepare_sql : %s", s);
#endif
  sid = malloc (sizeof (struct s_sid));
#ifdef DEBUG
  A4GL_debug ("Malloced sid=%p", sid);
#endif
  sid->select = strdup (s);
#ifdef DEBUG
  A4GL_debug ("Set select");
#endif
  sid->ibind = 0;
  sid->ni = count_queries (s);
  sid->obind = 0;
  sid->no = 0;

#ifdef DEBUG
  A4GL_debug ("Before alloc sid->hstmt=%p", sid->hstmt);
#endif

  if (A4GL_new_hstmt ((SQLHSTMT *)&sid->hstmt))	/* warning: passing arg 1 of `new_hstmt' from incompatible pointer type */
    {
#ifdef DEBUG
      A4GL_debug ("after alloc sid->hstmt=%p", sid->hstmt);
#endif
      rc = SQLPrepare ((SQLHSTMT )sid->hstmt, sid->select, SQL_NTS);
      chk_rc (rc, sid->hstmt, "SQLPrepare");

#ifdef DEBUG
      A4GL_debug ("Rc set to %d", rc);
#endif
      /* A4GL_set_sqlca (sid->hstmt, "Prepare_sql : after SQLPrepare", 0); */
      return sid;
    }
  else
    {
      /* A4GL_set_sqlca (sid->hstmt, "Prepare_sql : after SQLPrepare", 0); */
      A4GLSQL_set_status (0, 1);
      return 0;
    }
}
#endif


/**
 * Find a statement prepared in the pointer tree.
 *
 * @param pname The statement name.
 * @param mode Not used.
 * @return A pointer to the statement strucuture, 0 otherwise.
 */
void * A4GLSQL_find_prepare (char *pname)
{
  struct s_sid *ptr;

#ifdef DEBUG
  A4GL_debug ("chk %s was prepared", pname);
#endif
  A4GL_set_errm (pname);
  ptr = A4GL_find_pointer_val (pname, PRECODE);
  if (ptr)
    return ptr;
  return (struct s_sid *) 0;
}

/**
 * Execute an SQL statement.
 *
 * @param pname  The prepared statement name.
 * @param ni Number of elements in the input bind.
 * @param ibind The input binding array used.
 * @return
 */
int A4GLSQL_execute_sql (char *pname, int ni, void *vibind) 
{
  struct s_sid *sid;
struct BINDING *ibind;
ibind=vibind;

#ifdef DEBUG
  A4GL_debug ("execute_sql");
#endif
  sid = A4GLSQL_find_prepare (pname);	//,1
  A4GL_set_errm ("");

  if (sid == 0)
    {
      A4GL_exitwith ("Can't execute unprepared statement");
      return 0;
    }
#ifdef DEBUG
  A4GL_debug (" prepare statement - Sid=%p ", sid);
  A4GL_debug ("Binding any data... ni=%d hstmt=%p", ni, sid->hstmt);
#endif
  A4GL_proc_bind (ibind, ni, 'i', (SQLHSTMT)sid->hstmt);
#ifdef DEBUG
  A4GL_debug ("Bound any data... ni=%d", ni);
#endif
  return ODBC_exec_prepared_sql ((SQLHSTMT)sid->hstmt);
}

/**
 * Prepare a select statement.
 *
 * @todo : Check if the binds passes are arrays and if so put one more *
 *
 * @param ibind The input bind array (??).
 * @param ni The number of elements binded.
 * @param obind The output bind array (???).
 * @param no The number of output elements binded.
 * @param s The text of the select statement.
 */
void * A4GLSQL_prepare_select_internal (void *vibind, int ni, void *vobind, int no, char *s) /* mja */
{
  struct s_sid *sid;
  int rc;
  struct BINDING *ibind;
  struct BINDING *obind;
  ibind=vibind;
  obind=vobind;

  sid = malloc (sizeof (struct s_sid));
  sid->select = strdup (s);
  sid->ibind = ibind;
  A4GL_debug ("sid->ni=%d", ni);
  sid->ni = ni;
  sid->obind = obind;
  sid->no = no;


  A4GLSQL_set_status (0, 1);

  if (A4GL_new_hstmt ((SQLHSTMT *)&sid->hstmt))
    {
#ifdef DEBUG
      A4GL_debug ("after alloc sid->hstmt=%p", sid->hstmt);
      A4GL_debug ("statement = %s", sid->select);
#endif
      rc = SQLPrepare ((SQLHSTMT)sid->hstmt, sid->select, SQL_NTS);
      chk_rc (rc, sid->hstmt, "SQLPrepare");
      /* A4GL_set_sqlca (sid->hstmt, "Prepare_select : After Prepare", 0); */
#ifdef DEBUG
      A4GL_debug ("Prepared '%s'\n", s);
#endif
      if (a4gl_sqlca.sqlcode < 0)
	{
#ifdef DEBUG
	  A4GL_debug ("Returning 0");
#endif
	  sid->hstmt=0;
	  return 0;
	}
#ifdef DEBUG
      A4GL_debug ("Returning %p", sid);
#endif
      return sid;
    }
  else
    {
      /* not an sql error */
      if (a4gl_status == 0)
 A4GL_exitwith ("Memory Allocation Error");
#ifdef DEBUG
      A4GL_debug ("Some error generating hstmt");
#endif
      return 0;
    }

  return 0;
}

#ifdef IS_THIS_USED
/**
 * Prepare a global SQL statement
 *
 * @param s The SQL statement text.
 * @param ni The number of variables to bind.
 * @param ibind The input bind
 * @return A pointer to an SQL statement information strucutre.
 */
void * A4GLSQL_prepare_glob_sql_internal (char *s, int ni, void *vibind) /* mja */
{
  struct s_sid *sid;
  struct BINDING *ibind;
  ibind=vibind;
  A4GL_debug ("prepare_glob_sql '%s' %p %d", s, ibind, ni);
  sid = malloc (sizeof (struct s_sid));
  sid->select = strdup (s);
  sid->ibind = ibind;

#ifdef DEBUG
  A4GL_debug ("ni=%d ibind=%p", ni, ibind);
#endif
  sid->ni = ni;

  sid->obind = 0;
  sid->no = 0;

#ifdef DEBUG
  A4GL_debug ("Hdbc=%p ni=%d", hdbc, sid->ni);
#endif

  if (A4GL_new_hstmt ((SQLHSTMT *)&sid->hstmt))
    {
#ifdef DEBUG
      A4GL_debug ("after alloc sid->hstmt=%p", sid->hstmt);
      A4GL_debug ("Preparing %p %s\n", sid->hstmt, sid->select);
#endif
      rc = SQLPrepare ((SQLHSTMT)sid->hstmt, sid->select, SQL_NTS);
      chk_rc (rc, sid->hstmt, "SQLPrepare");
      /* A4GL_set_sqlca (sid->hstmt, "Prepare_glob_sql : After Prepare", 0); */
      if (a4gl_sqlca.sqlcode >= 0)
	{
#ifdef DEBUG
	  A4GL_debug ("Prepared %s as %p\n", s, sid->hstmt);
#endif
	  return sid;
	}
      else
	{
	  return 0;
	}
    }
  else
    {
      return 0;
    }
}
#endif

/**
 * Declare a cursor.
 *
 * @param upd_hold Indicate if the cursor is for update or with hold.
 * @param sid Select statement to use with the cursor.
 * @param scroll Indicate if is a scrolling cursor:
 *   - 0 :
 *   - 1 :
 * @param cursname The cursor name.
 * @return A pointer to the cursor informationstrucutre.
 */
void *
A4GLSQL_declare_cursor (int upd_hold, void *vsid, int scroll, char *cursname)
{
  struct s_sid *nsid;
  struct s_cid *cid;
  struct s_sid *sid;
  sid=vsid;

  if (sid == 0)
    {
      A4GL_exitwith ("Can't declare cursor for non-prepared statement");
      return 0;
    }
#ifdef DEBUG
  A4GL_debug ("Declaring cursor");
  A4GL_debug ("upd_hold=%d sid=%p scroll=%d cursname=%s", upd_hold, sid, scroll,
	 cursname);
#endif

  cid = malloc (sizeof (struct s_cid));

  nsid = malloc (sizeof (struct s_sid));
  A4GL_debug ("Malloced nsid & cid");
#ifdef DEBUG
  A4GL_debug ("sid=%p", sid);
#endif
  cid->statement = nsid;
  cid->hstmt = 0;
  cid->mode = upd_hold + scroll * 256;
  nsid->ibind = sid->ibind;
  nsid->hstmt = sid->hstmt;
  nsid->ni = sid->ni;
#ifdef DEBUG
  A4GL_debug ("nsid->ni=%d", nsid->ni);
#endif
  nsid->obind = sid->obind;
  nsid->no = sid->no;
  nsid->select = sid->select;
#ifdef DEBUG
  A4GL_debug ("Adding cursor %s", cursname);
#endif
  A4GL_add_cursor (cid, cursname);
#ifdef DEBUG
  A4GL_debug ("Added cursor");
  A4GL_debug ("cid->statement->ni=%d", cid->statement->ni);
  A4GL_debug ("cid->statement=%p", cid->statement);
  A4GL_debug ("cid->statement->ibind=%p", cid->statement->ibind);
#endif
  A4GL_new_hstmt ((SQLHSTMT *)&nsid->hstmt);
#ifdef DEBUG
  A4GL_debug ("Got statement");
#endif
  if (scroll)
    {
#ifdef DEBUG
      A4GL_debug ("Setting dynamic cursor");
#endif
      rc =
	SQLSetStmtOption ((SQLHSTMT )nsid->hstmt, SQL_CURSOR_TYPE, SQL_CURSOR_STATIC);
      if (rc==1) rc=0;
      chk_rc (rc, nsid->hstmt, "SQLSetScrollOption SCROLL_STATIC");
      A4GL_debug (" rc = %d\n", rc);
    }
#ifdef DEBUG
  A4GL_debug ("Returning %p", cid);
#endif
  SQLSetCursorName(nsid->hstmt,cursname,SQL_NTS);
  return cid;
}


/**
 * Execute an sql statement where its execution is implicit in 4gl.
 *
 * There are several places where this can occur such as a INPUT or
 * UPDATE, etc.
 *
 * @param sid The statement informnation handle.
 */
int
A4GLSQL_execute_implicit_sql (void *vsid)
{
struct s_sid *sid;
  
  int rc = 0;
sid=vsid;
  if (sid == 0)
    {
#ifdef DEBUG
      A4GL_debug ("A4GLSQL_execute_implicit_sql: internal error sid=0");
#endif
      return 0;
    }
#ifdef DEBUG
  A4GL_debug ("A4GLSQL_execute_implicit_sql: no=%d ni=%d sql=%s", sid->no, sid->ni, sid->select);
  A4GL_debug ("Calling proc_bind()");
#endif

  A4GL_proc_bind (sid->obind, sid->no, 'o', (SQLHSTMT)sid->hstmt);
  A4GL_proc_bind (sid->ibind, sid->ni, 'i', (SQLHSTMT)sid->hstmt);

#ifdef DEBUG
  A4GL_debug ("Calling ODBC_exec_stmt()");
#endif

  rc = ODBC_exec_stmt ((SQLHSTMT)sid->hstmt);
  A4GL_debug("Got rc as %d\n",rc);

#ifdef FREE
  if (rc) {
  	/* free up malloc'ed memory */
  	SQLFreeStmt ((SQLHSTMT)sid->hstmt, SQL_DROP);
  }
  sid->hstmt=0;

  free (sid->select);
  sid->select=0;
  free (sid);
#endif
  return (rc);
}





/**
 * Execute an implicit select instruction.
 *
 * Used when the SELECT is a direct SELECT INTO in 4gl code.
 *
 * @param sid The statement information.
 */
int
A4GLSQL_execute_implicit_select (void *vsid)
{
  int a;
struct s_sid *sid;
sid=vsid;

  if (sid == 0)
    {
#ifdef DEBUG
      A4GL_debug ("A4GLSQL_execute_implicit_select got sid == 0, returning -1");
#endif
      return -1;
    }
#ifdef DEBUG
  A4GL_debug ("Executing immediate : %s", sid->select);
#endif
  A4GL_proc_bind (sid->obind, sid->no, 'o', (SQLHSTMT)sid->hstmt);
  A4GL_proc_bind (sid->ibind, sid->ni, 'i', (SQLHSTMT)sid->hstmt);
#ifdef DEBUG
  A4GL_debug (" Bound data ... ni=%d no=%d", sid->ni, sid->no);
#endif
  a = ODBC_exec_select ((SQLHSTMT)sid->hstmt);


  if (a) {
	A4GL_post_fetch_proc_bind (sid->obind, sid->no, (SQLHSTMT )&sid->hstmt);
  	SQLFreeStmt ((SQLHSTMT)sid->hstmt, SQL_DROP);
	sid->hstmt=0;
  }
  free (sid->select);
  free (sid);

  return a;
}

/**
 * Open a cursor already declared.
 *
 * @param ni
 * @param s The cursor name.
 * @return
 */
int
A4GLSQL_open_cursor (char *s,int ni,void *ibind)
{
  struct s_cid *cid;
  char *curs;
  unsigned long rowcount;
  int save_ni=-1;
  struct s_sid *sid;
  struct BINDING *save_ibind=0;
  int rc;


#ifdef DEBUG
  A4GL_debug ("Checking cursor %s exists before opening", s);
#endif

  cid = A4GLSQL_find_cursor (s);

  if (cid == 0)
    {
      return 0;
    }

  if (cid->hstmt != 0)
    {

      A4GLSQL_close_cursor (s);
    }

  sid = cid->statement;

  A4GL_debug("Select ='%s'",sid->select);
  if (strncasecmp(sid->select,"INSERT",6)==0 || strncasecmp(sid->select," INSERT",7)==0) {
  	rc = SQLPrepare ((SQLHSTMT )cid->statement->hstmt, cid->statement->select, SQL_NTS);
  	chk_rc (rc, cid->statement->hstmt, "SQLPrepare");
	return 0;
  }


  if (ni) {
        // They've used a value on the OPEN
        save_ni=cid->statement->ni;
        save_ibind=cid->statement->ibind;
        cid->statement->ni=ni;
        cid->statement->ibind=(struct BINDING *)ibind;
  }



  rc = SQLPrepare ((SQLHSTMT )cid->statement->hstmt, cid->statement->select, SQL_NTS);
  chk_rc (rc, cid->statement->hstmt, "SQLPrepare");
#ifdef DEBUG
  A4GL_debug ("cid=%p %s", cid, s);
  A4GL_debug ("cid->statement=%p", cid->statement);
  A4GL_debug ("cid->statement->ibind=%p", cid->statement->ibind);
  A4GL_debug ("cid->statement->ni=%d", cid->statement->ni);
#endif

  if (((cid->statement->ni) != ni) && ni > 0)
    {
#ifdef DEBUG
      A4GL_debug ("Too many or too few host variables ni=%d no expected=%d", ni,
	     cid->statement->ni);
#endif
        if (save_ni!=-1) {
                cid->statement->ni=save_ni;
                cid->statement->ibind=save_ibind;
        }

      A4GL_exitwith ("Too many or too few host variables");
      return 0;
    }

#ifdef DEBUG
  A4GL_debug ("Host variables OK");
#endif

  curs = cid->statement->select;
  a4gl_status = 0;
  if (ni == 0)
    {				/* No USING on the open.. */
      A4GL_proc_bind (cid->statement->ibind, cid->statement->ni, 'i', (SQLHSTMT)cid->statement->hstmt);

    }
  else
    {
      struct BINDING *b;
      int a;
#ifdef DEBUG
      A4GL_debug ("We dont have a binding - but I'll make one");
#endif
      b = malloc (sizeof (struct BINDING) * ni);

      for (a = ni - 1; a >= 0; a--)
	{
	  b[a].ptr = A4GL_char_pop ();
#ifdef DEBUG
	  A4GL_debug ("Got string as '%s' a=%d\n", b[a].ptr, a);
#endif
	  b[a].dtype = 0;
	  b[a].size = strlen (b[a].ptr);
#ifdef DEBUG
	  A4GL_debug ("Got size as '%d' a=%d\n", b[a].size, a);
#endif
	}

      for (a = 0; a < ni; a++)
	{
#ifdef DEBUG
	  A4GL_debug ("%d %d %s", b[a].dtype, b[a].size, b[a].ptr);
#endif
	}

      A4GL_proc_bind (b, ni, 'i', (SQLHSTMT)cid->statement->hstmt);

    }


  if (a4gl_status != 0)
    {
        if (save_ni!=-1) {
                cid->statement->ni=save_ni;
                cid->statement->ibind=save_ibind;
        }

      return 0;
    }

#ifdef DEBUG
  A4GL_debug ("Executing statement %s\n", curs);
  A4GL_debug ("cid=%p cid->hstmt=%p", cid, cid->hstmt);
#endif

  if (cid->hstmt != 0)
    {
        if (save_ni!=-1) {
                cid->statement->ni=save_ni;
                cid->statement->ibind=save_ibind;
        }

      A4GL_exitwith ("Cursor already open");
      return 0;
    }
  else
    {
      cid->hstmt = cid->statement->hstmt;
    }
  /* Execute the SQL statement. */

#ifdef DEBUG
  A4GL_debug ("Setting cursor type");
  A4GL_debug ("Opening cursor %p", cid->statement->hstmt);
#endif

  rc = SQLExecute ((SQLHSTMT )cid->statement->hstmt);
  rc = A4GL_chk_need_blob (rc, (SQLHSTMT)&cid->statement->hstmt);
  chk_rc (rc, cid->statement->hstmt, "SQLExecute");

#ifdef DEBUG
  A4GL_debug ("Executed...");
  A4GL_debug ("Open Cursor hstmt=%p", cid->statement->hstmt);
  A4GL_debug ("OBind...");
#endif
  A4GL_proc_bind (cid->statement->obind, cid->statement->no, 'o',
	     (SQLHSTMT)cid->statement->hstmt);
#ifdef DEBUG
  A4GL_debug ("IBind...");
  A4GL_debug ("After open cursor");
#endif

  /* A4GL_set_sqlca (cid->statement->hstmt, "Open Cursor", 1); */
  if (rc != SQL_SUCCESS)
    {
	int a;
	a=A4GL_sqlerrwith (rc, (SQLHSTMT)&cid->statement->hstmt);
		cid->statement->hstmt=0;
        if (save_ni!=-1) {
                cid->statement->ni=save_ni;
                cid->statement->ibind=save_ibind;
        }

      	return a;
    }
  A4GLSQL_set_status (0, 1);
  rc = SQLRowCount ((SQLHSTMT )cid->statement->hstmt, (SQLINTEGER *) & rowcount);

  /* chk_rc (rc, cid->statement->hstmt, "SQLRowCount"); */
  a4gl_sqlca.sqlerrd[1] = rowcount;
        if (save_ni!=-1) {
                cid->statement->ni=save_ni;
                cid->statement->ibind=save_ibind;
        }

  return 0;
}

/**
 * Fetch a cursor into variables.
 *
 * @param cursor_name The cursor name
 * @param fetch_mode The direction of the fetch:
 *  - FETCH_ABSOLUTE
 *  - FETCH_RELATIVE
 * @param fetch_when The number of elements to advance or go back.
 *   - 1
 *   - -1
 *   - Otherwise
 * @param nibind
 * @param ibind
 */
int
A4GLSQL_fetch_cursor (char *cursor_name,
		      int fetch_mode, int fetch_when, int nibind, void *vibind)
{
  struct s_cid *cid;
  int nfields;
  int rc;
  SDWORD nr;
  UWORD nrs[1000];
  int use_nbind;
  struct BINDING *use_binding;
  int mode = 0;
  struct BINDING *ibind;


  ibind=vibind;

#ifdef DEBUG
  A4GL_debug ("In fetch_cursor (%s,%d,%d,%d,%p)", cursor_name, fetch_mode,
	 fetch_when, nibind, ibind);
  A4GL_debug ("before find cursor");
#endif

  cid = A4GLSQL_find_cursor (cursor_name);
#ifdef DEBUG
  A4GL_debug ("fetch_cursor : cid=%p", cid);
#endif
  if (cid->hstmt == 0)
    {
      A4GL_exitwith ("Fetch attempted on unopened cursor");
      return 0;
    }
  if (nibind == 0)
    {
#ifdef DEBUG
      A4GL_debug ("   Use cursors bindings..");
#endif
      use_binding = cid->statement->obind;
      use_nbind = cid->statement->no;
    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("   Use fetches bindings..");
#endif
      use_binding = ibind;
      use_nbind = nibind;
      A4GL_proc_bind (ibind, nibind, 'o', (SQLHSTMT)cid->statement->hstmt);
    }

  switch (fetch_mode)
    {
    case FETCH_ABSOLUTE:
#ifdef DEBUG
      A4GL_debug ("Absolute : %d", fetch_when);
#endif
      mode = SQL_FETCH_ABSOLUTE;
      break;
    case FETCH_RELATIVE:
#ifdef DEBUG
      A4GL_debug ("relative : %d", fetch_when);
#endif
      mode = SQL_FETCH_RELATIVE;
      break;
    }

  if (mode == SQL_FETCH_RELATIVE)
    {
      if (fetch_when == 1)
	{
#ifdef DEBUG
	  A4GL_debug ("fetch next");
#endif
	  mode = SQL_FETCH_NEXT;
	}
      if (fetch_when == -1)
	{
#ifdef DEBUG
	  A4GL_debug ("fetch previous");
#endif
	  mode = SQL_FETCH_PRIOR;
	}
    }

  if (mode == SQL_FETCH_ABSOLUTE)
    {
      if (fetch_when == 1)
	{
#ifdef DEBUG
	  A4GL_debug ("fetch first");
#endif
	  mode = SQL_FETCH_FIRST;
	}
      if (fetch_when == -1)
	{
#ifdef DEBUG
	  A4GL_debug ("fetch last");
#endif
	  mode = SQL_FETCH_LAST;
	}
    }

#ifdef DEBUG
  A4GL_debug ("Before Extended fetch...");
#endif

  if (A4GL_chk_getenv ("EXTENDED_FETCH", TRUE))
    {

#ifdef DEBUG
      A4GL_debug ("Calling SQLextended fetch with %p %d %d", cid->statement->hstmt,
	     mode, fetch_when);
#endif
      nr = 1;
      rc =
	SQLExtendedFetch ((SQLHSTMT )cid->statement->hstmt, mode, fetch_when, &nr,
			  &nrs[0]);
      chk_rc (rc, cid->statement->hstmt, "SQLExtendedFetch");
    }
  else
    {
      rc = SQLFetch ((SQLHSTMT )cid->statement->hstmt);
      chk_rc (rc, cid->statement->hstmt, "SQLFetch");
    }
#ifdef DEBUG
  A4GL_debug ("After fetch");
  A4GL_debug ("Rc set to %d", rc);
#endif
  if (rc == SQL_NO_DATA_FOUND)
    {
      A4GLSQL_set_status (100, 1);
      return 0;
    }

  /*
     if (rc != SQL_SUCCESS && rc != SQL_NO_DATA_FOUND)
     {
     A4GL_set_sqlca (cid->statement->hstmt, "ODBC_exec_select : After SQLFetch", 0);
     }
   */

/*  res = PQexec (conn, cmd); exec */

  A4GL_debug("use_binding...");
  A4GL_post_fetch_proc_bind (use_binding, use_nbind, (SQLHSTMT)&cid->statement->hstmt);
  nfields = 1;			/* number of fields returned */
#ifdef DEBUG
  A4GL_debug ("nfields=%d\n", nfields);
  A4GL_debug ("nibind=%d\n", use_nbind);
#endif
  return 0;
}

/**
 * Initialize a connection, given an ODBC database/datasource name.
 *
 * If a connection was already opened free the resources used.
 *
 * Gets the username and password from the environment
 * and call A4GLSQL_make_connection().
 *
 * @todo : Substitute the deprecated function SQLFreeConnect.
 * @param	ODBC datasource name (DSN)
 * @return	0 if success (program terminates otherwise)
 */
int
A4GLSQL_init_connection_internal (char *dbName_f)
{
char empty[10] = "None";
char dbName[2048];
char *u, *p;
HDBC *hh = 0;
int rc;


strcpy(dbName,dbName_f);
A4GL_trim(dbName);

/* This section does not apply to "real" SQLite odbc driver since it will use odbc.ini
 settings to look for SQLite database file
#ifdef SQLITEODBC
*/
#ifdef SQLITE_DIRECT
{
char a[128], b[128], tmp[2048];
char *FullPathDBname;
char DATABASE[128];
	A4GL_debug("SQLITE special...");

    /* NOTE:

        When using SQLite, user can use the following DATABASE statement parameters:

        DATABASE example    - will use DBPATH to find SQLite db file, adding .db extension first
        DATABASE "example"  - same
        DATABASE "example.db" - will use DBPATH to find SQLite db file
        DATABASE "/full/path/to/dbfile/example" - will add .db extension, and check for file in specified path
        DATABASE "/full/path/to/dbfile/example.db" - will check for file in specified path
    */


	//See if user specified extension in his DATABASE statement:
	A4GL_bname (dbName, a, b);
    if (a[0] == 0) {
       	sprintf(tmp,"%s.db",dbName);
		A4GL_debug("Added .db file name extension, dbName=%s",tmp);
	} else {
        //sprintf(tmp,"%s",dbName);
		strcpy(tmp,dbName);
	}
	//store DB file name as per DATABASE statement
    sprintf(DATABASE,"%s",tmp);
	//Find full path to the SQLite database file, use DBPATH
	FullPathDBname=A4GL_fullpath_dbpath((char *)tmp);

	if (FullPathDBname) {
		strcpy (tmp,FullPathDBname);
		//strcpy (dbName,tmp);

		//add db file name as per DATABASE statement to discovered path
		sprintf(dbName,"%s",tmp);
		A4GL_debug("Found SQLite db in '%s'",dbName);
	} else {
		/*
            NOTE: SQLite by default will automatically create a new empty
            database file when an attempt to access non-existing database is
            made. This will in most casesI though result in complete confusion, since
            DATABASE statement will never fail, but then all SQL statements
			expecting tables and/or data will fail. But user will think he is
            successfully conncted to the database...

            So even if automatic creation of new database on first access
            sounds like a cool feature, I beleive we better exit here if we
            cannot find a specified SQLite database file in DBPATH.

        */
		A4GL_debug ("SQLite database file not found in DBPATH='%s'",acl_getenv("DBPATH"));
		A4GL_exitwith ("SQLite database file not found in DBPATH");
    }
}
#endif

#ifdef DEBUG
  A4GL_debug ("A4GLSQL_init_connection(dbName='%s')", dbName);
#endif

	if (strcmp (dbName, OldDBname) == 0) {
		#ifdef DEBUG
			A4GL_debug ("Already connected - ignored.");
		#endif
		return 0;
    }

  /* free up the current default connection, if there is one */
  if (A4GL_has_pointer ("default", SESSCODE)) {
      hh = A4GL_find_pointer_val ("default", SESSCODE);
      rc = SQLFreeConnect ((SQLHSTMT )*hh);
      chk_rc (rc, 0, "SQLFreeConnect");
    }

  /* get the user name and password from SQLUID, SQLPWD.
   *  if SQLUID not set, then try getlogin() or $LOGNAME
   *  if SQLPWD not set, then prompt user if we can
   */
  u = acl_getenv ("SQLUID");
#if ( ! defined(__MINGW32__))
  /*
     FIXME:
     can we find out if there is user name/password specified in odbc.ini
     before we just override it ?
   */

  if (u == 0 || *u == '\0')
    u = getlogin ();
  /*
     FIXME
     we have something simmilar somewhere in libaubit4gl for WIN32 - find it 
     and use it instead getlogin()
   */
#else
	#ifdef DEBUG
	  A4GL_debug ("avoided getlogin() call");
	#endif
#endif

  /* FIXME: what is LOGNAME ? */
  if (u == 0 || *u == '\0')
    u = acl_getenv ("LOGNAME");
  if (u == 0)
    u = empty;

  p = acl_getenv ("SQLPWD");
  if ((p == 0 || *p == '\0') && *u > '\0')
    {
      /*  prompt user for password - if not specified in odbc.ini -not yet implemented  */
    }
  if (p == 0)
    p = empty;

#ifdef DEBUG
  A4GL_debug ("u=%s p=%s", u, p);
#endif

  if (A4GLSQL_make_connection (dbName, u, p))
    {
      /* do we have an existing pointer to default */
      hh = A4GL_find_pointer_val ("default", SESSCODE);
      if (hh == 0)
	{
	  hh = malloc (sizeof (HDBC));
	}
      *hh = hdbc;
      A4GL_add_pointer ("default", SESSCODE, hh);
      rc = SQLSetConnectOption (hdbc, SQL_AUTOCOMMIT, 0);
      chk_rc (rc, 0, "SQLSetConnectOption");
#ifdef DEBUG
      A4GL_debug ("AUTOCOM rc=%d", rc);
#endif
    }
  else
    {
      A4GL_set_errm (dbName);
      A4GL_exitwith ("Could not connect to database");
    }
#ifdef DEBUG
  A4GL_debug ("hh=%p for %s", hh, dbName);
#endif
  strcpy (OldDBname, dbName);
  return 0;
}

/**
 * Assign the 4gl global variable status.
 *
 * @param a The value to be assigned to status.
 */
void
A4GLSQL_xset_status (int a)
{
  A4GLSQL_set_status (a, 0);
}

/**
 * Get the value of the status 4gl global variable.
 *
 * @return The value of sqlca.sqlcode
 */
int
A4GLSQL_get_status (void)
{
  return a4gl_sqlca.sqlcode;
}

/**
 * Get the current SQL error message.
 *
 * @return The contents of sqlca.sqlerrm.
 */
char *
A4GLSQL_get_sqlerrm (void)
{
  return a4gl_sqlca.sqlerrm;
}

/**
 * Free the resources allocated for a cursor.
 * FIXME: in free.rule, we still print just FIXME comment...
 * The cursor is found in the pointer tree.
 *
 * @param cname The cursor name.
 * @return Allways zero
 */
struct s_cid *
A4GLSQL_free_cursor (char *cname)
{
  struct s_cid *ptr;

  ptr = A4GL_find_pointer_val (cname, CURCODE);
  if (ptr == 0)
    {
      A4GL_exitwith ("Can't free cursor thats not been defined");
      return 0;
    }
  if (ptr->hstmt)
    {
      SQLFreeStmt ((SQLHSTMT )ptr->hstmt, SQL_DROP);
	ptr->hstmt=0;
      chk_rc (rc, 0, "SQLFreeStmt");
    }
  free (ptr->statement->select);
  free (ptr->statement);
  A4GL_del_pointer (cname, CURCODE);
  A4GLSQL_set_status (0, 1);
  return 0;
}

/**
 * Close a cursor.
 *
 * The cursor is found in the pointer tree.
 *
 * @param The cursor name.
 * @return
 *   - -1 A cursor with that name was not found
 *   - 1 Cursor closed
 */
int
A4GLSQL_close_cursor (char *cname)
{
  struct s_cid *ptr;

#ifdef DEBUG
  A4GL_debug ("In close cursor");
#endif
  ptr = A4GL_find_pointer_val (cname, CURCODE);
  if (ptr == 0)
    {
      A4GL_exitwith ("Can't close cursor that hasn't been defined");
      return -1;
    }

#ifdef DEBUG
  A4GL_debug ("Clr hstmt ptr=%p", ptr);
#endif

  if (ptr->hstmt)
    {
      SQLFreeStmt ((SQLHSTMT )ptr->hstmt, SQL_CLOSE);
	ptr->hstmt=0;
      chk_rc (rc, ptr->hstmt, "SQLFreeStmt");
    }

  ptr->hstmt = 0;
#ifdef DEBUG
  A4GL_debug ("Clr hstmt ptr=%p hstmt=%p", ptr, ptr->hstmt);
#endif
  return 1;
}

/**
 * Add a cursor to the pointer tree.
 *
 * @param cid A pointer to the identifing cursor structure.
 * @param cname The cursor name.
 */
void
A4GL_add_cursor (struct s_cid *cid, char *cname)
{
  A4GL_add_pointer (cname, CURCODE, cid);
}

/**
 * Gets the sql error.
 *
 * @todo : Fix this recursive return.
 */
char *
A4GL_ret_sql_err (void)
{
  return A4GL_ret_sql_err ();
}

/**
 * Check if a prepared statement exist in thepointer tree.
 *
 * @param pname The prepared statement name.
 * @return
 *   - 1 : The statement exist.
 *   - 0 : The statement does not exist.
 */
int
A4GL_find_prepare2 (char *pname)
{
  struct s_sid *ptr;
  ptr = (struct s_sid *) A4GL_find_pointer_val (pname, PRECODE);
  if (ptr)
    return 1;
  return 0;
}


#ifdef MOVED_TO_LIBAUBIT4GL
/**
 * Add a prepare statement to the pointer tree.
 *
 * @param pname The prepared statement name.
 * @param sid A pointer to the statement information.
 */
int
A4GLSQL_add_prepare (char *pname, void *vsid) 
{
struct s_sid *sid;
sid=vsid;
  if (sid)
    {
      A4GL_add_pointer (pname, PRECODE, sid);
      return 1;
    }
  else
    {
      return 0;
    }

}
#endif

/**
 * If A4GL_debug was set print Error.
 *
 * @return Allways 1
 */
int
print_err (HDBC hdbc, HSTMT hstmt)
{
#ifdef DEBUG
  A4GL_debug ("Error.....\n");
#endif
  return 1;
}

/**
 * Gets the size of the datatype of a table column.
 *
 * @param coltype The data type.
 * @param collen The length of the column.
 * @param colname The name of the column.
 * @return The size calculated.
 */
UDWORD
A4GL_display_size (SWORD coltype, UDWORD collen, UCHAR * colname)
{
#ifdef DEBUG
  A4GL_debug ("display_size Coltype=%d %d %s\n", coltype, collen, colname);
#endif
  switch (coltype)
    {
    case SQL_CHAR:
    case SQL_VARCHAR:
      return (max (collen, strlen (colname)));
    case SQL_SMALLINT:
      return (max (6, strlen (colname)));
    case SQL_INTEGER:
      return (max (11, strlen (colname)));
    case SQL_DECIMAL:
    case SQL_NUMERIC:
    case SQL_REAL:
    case SQL_FLOAT:
    case SQL_DOUBLE:
      return (max (MAX_NUM_STRING_SIZE, strlen (colname)));

      /* Note that this function only supports the core data types. */
    case SQL_LONGVARBINARY:
    case SQL_LONGVARCHAR:
    case SQL_VARBINARY:
      return 6;
    case 9:			/* date */

      return 12;
    case 11:			/* datetime */

      return 26;		/* yyyy-mm-dd hh:mm:ss.ffffff */

    case 91:
	return 12; /* date */
    default:
      printf ("Unknown datatype, %d\n", coltype);
      return (0);
    }
}

/**
 * Connects to a database.
 *
 * @param server The database server name. 
 * @param uid_p The user identification.
 * @param pwd_p The password.
 * @return 
 *   - 1 : Connection estabilished.
 *   - 0 : there was an error connecting to database.
 */
int A4GLSQL_make_connection (char * server, char * uid_p, char * pwd_p)
{
RETCODE rc;
char uid[256] = "";
char pwd[256] = "";

#ifdef DEBUG
  A4GL_debug ("A4GLSQL_make_connection .. server=%s uid_p=%s pwd_p=%s", server, uid_p, pwd_p);
#endif

  /* do nothing if no server, which can happen if fgl_start
   * has no default compile-time database  */
  if ((server == 0) || (strlen (server) == 0))
    {
	#ifdef DEBUG
      A4GL_debug (" no server - no connection.");
	#endif
      return 1;
    }

  /* copy user name and password, and remove trailing spaces
   */

  A4GL_trim (uid_p);
  A4GL_trim (pwd_p);
  if (uid_p)
    strcpy (uid, uid_p);
  if (pwd_p)
    strcpy (pwd, pwd_p);
  A4GL_trim (uid);
  A4GL_trim (pwd);
  A4GL_trim (server);
  /*
     FIXME: we really need more then trim() here - I once had a TAB after
     uid by mistake...
   */

  if (henv == 0) {
	  A4GL_debug ("Calling SQLAllocEnv()");
      //This call core dumps on SQLite/MinGW:
	  rc = SQLAllocEnv (&henv);
      //rc = SQLAllocEnv (henv);
	  chk_rc (rc, 0, "SQLAllocEnv");
	  #ifdef DEBUG
      	A4GL_debug ("SQLAllocEnv returns %d %p", rc, henv);
	  #endif
    }
  rc = SQLAllocConnect (henv, &hdbc);
  chk_rc (rc, 0, "SQLAllocConnect");
#ifdef DEBUG
  A4GL_debug ("SQLAllocConnect returns %d %p", rc, hdbc);
  A4GL_debug ("Connecting to >%s< as >%s</>%s<", server, uid, pwd);
#endif

  rc = SQLConnect (hdbc, server, SQL_NTS, uid, SQL_NTS, pwd, SQL_NTS);

  chk_rc (rc, 0, "SQLConnect");

#ifdef DEBUG
  A4GL_debug ("SQLConnect status = %d", rc);
#endif

  if (rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO)
    {
      A4GL_set_sqlca (0, "Connect Failed", 0);
      return 0;
    }

  A4GLSQL_set_status (0, 1);
  ODBC_set_dbms_info ();

  rc = SQLSetConnectOption (hdbc, SQL_ASYNC_ENABLE, 0);
  A4GLSQL_set_status (0, 1);

  return 1;
}

/**
 * Returns the name of the SQL dialect used
 * by the current connected database
 * eg. "INFORMIX", "SAPDB", "POSTGRESQL"
 *
 * @return  dialect as char string
 */
char *
A4GLSQL_dbms_dialect (void)
{
  /* this is set in make_connection */
  return dbms_dialect;
}

/**
 * Returns the name of the currently connected DBMS.
 * eg. "Informix", "SAP DB", "PostgreSQL"
 *
 * @return  pointer to name
 */
char *
A4GLSQL_dbms_name (void)
{
  /* this is set in make_connection */
  return dbms_name;
}

/**
 * Sets the dbms_name / dbms_dialect variables, for current session.
 * Should always be called by make_connection() and set_conn().
 *
 * @return Always 0.
 */
void
ODBC_set_dbms_info (void)
{
  int rc;
  short len;

  rc = SQLGetInfo (hdbc, SQL_DBMS_NAME, dbms_name, (short) 64, &len);
  A4GL_debug("DIALECT : %s\n",dbms_name);
  strcpy (dbms_dialect, "");

  if (strncasecmp (dbms_name, "informix", 8) == 0)
    {
      strcpy (dbms_dialect, "INFORMIX");
    }

  if (strncasecmp (dbms_name, "sapdb", 5) == 0)
    {
      strcpy (dbms_dialect, "SAPDB");
    }

  if (strncasecmp (dbms_name, "postgr", 6) == 0)
    {
      strcpy (dbms_dialect, "POSTGRESQL");
    }

  if (strncasecmp (dbms_name, "oracl", 5) == 0)
    {
      strcpy (dbms_dialect, "ORACLE");
    }

  if (strncasecmp (dbms_name, "mysql", 5) == 0)
    {
      strcpy (dbms_dialect, "MYSQL");
    }

  if (strncasecmp (dbms_name, "SQLite", 6) == 0)
    {
      strcpy (dbms_dialect, "SQLITE");
    }

  /* ( later, this will be set from user-editable config files ) */
}

/**
 * Disconnect the current connection from a datasource.
 *
 * @return Always 0.
 */
int
ODBC_disconnect (void)
{
#ifdef DEBUG
  A4GL_debug ("ODBC_disconnect: hdbc=%p", hdbc);
#endif
  if (hdbc)
    {
      SQLDisconnect (hdbc);
      chk_rc (rc, 0, "SQLDisconnect");
    }
  /* Free the connection handle.      */
  if (hdbc)
    {
      SQLFreeConnect ((HDBC) hdbc);
      chk_rc (rc, 0, "SQLFreeConnect");
    }
  /* Free the environment handle.     */
  if (henv)
    {
      SQLFreeEnv (henv);
      chk_rc (rc, 0, "SQLFreeEnv");
    }
  return 0;
}

/**
 * Execute an SQL statement trough ODBC.
 *
 * @param sqlstr The sql text to be executed.
 * @return
 *   - 1 : The statement was correctly executed.
 *   - 0 : There was an error.
 */
int
ODBC_exec_sql (UCHAR * sqlstr)
{
  HSTMT hstmt;
  int rc;

#ifdef DEBUG
  A4GL_debug ("ODBC_exec_sql: %s", sqlstr);
#endif

  if (A4GL_new_hstmt ((SQLHSTMT *)&hstmt))
    {
      rc = SQLExecDirect ((SQLHSTMT )hstmt, sqlstr, SQL_NTS);
      chk_rc (rc, 0, "SQLExecDirect");
#ifdef DEBUG
      A4GL_debug ("SQLExecDirect returns %d", rc);
#endif
      if (rc != SQL_SUCCESS)
	{
	int a;
		a=A4GL_sqlerrwith (rc, hstmt);
		hstmt=0;
	  	return a;
	}

      rc = SQLFreeStmt ((SQLHSTMT )hstmt, SQL_DROP);
		hstmt=0;
      chk_rc (rc, 0, "SQLFreeStmt");
      return 1;
    }

#ifdef DEBUG
  A4GL_debug ("Failed to allocate new hstmt!");
#endif

  return 0;
}

/**
 * Execute a prepared sql statement through ODBC.
 * Called from A4GLSQL_execute_implicit_sql()
 *
 * @param hstmt The statement handle.
 * @return
 *   - 1 : The statement was correctly executed.
 *   - 0 : There was an error.
 */
int
ODBC_exec_stmt (SQLHSTMT hstmt)
{
  int rc;
  long rowcount;
#ifdef DEBUG
  A4GL_debug ("In ODBC_exec_stmt %p",hstmt);
#endif
  if (hstmt==0) {
	return 0;
  }
  rc = SQLExecute ((SQLHSTMT )hstmt);


#ifdef DEBUG
  A4GL_debug ("SQLExecute returns %d\n", rc);
#endif

  rc = A4GL_chk_need_blob (rc, hstmt);

#ifdef DEBUG
  A4GL_debug ("chk_need_blob returns %d\n", rc);
#endif

  chk_rc (rc, hstmt, "SQLExecute2");

#ifdef DEBUG
  A4GL_debug ("chk_rc: Result=%d (Success==%d)", rc, SQL_SUCCESS);
#endif

  if (rc != SQL_SUCCESS)
    {
	int a;
	a=A4GL_sqlerrwith (rc, hstmt);
      	return a;

    }
 if (SQLRowCount ((SQLHSTMT )hstmt, &rowcount)==SQL_SUCCESS) { a4gl_sqlca.sqlerrd[2]=rowcount; }

  A4GLSQL_set_status (0, 1);
  return 1;
}

/**
 * Ask odbc to free the resources allocated to the statement.
 *
 * @param rc Not used.
 * @param h The statement handle.
 * @return Allways 0.
 */
int
A4GL_sqlerrwith (int rc, HSTMT h)
{
  /* A4GL_set_sqlca (h, "From sqlerrwith", 0); */
  	SQLFreeStmt ((SQLHSTMT)h, SQL_DROP);
	h=0;
  return 0;
}

/**
 * Assign the values of sqlca acording to the status of the statement.
 *
 * @param hstmt The statement handler.
 * @param s A string to identify who and wy called this.
 * @param reset Not used.
 */
void
A4GL_set_sqlca (SQLHSTMT hstmt, char *s, int reset)
{
  char s1[81];
  char s2[500];
  
/*
sql.c: In function `set_sqlca':
sql.c:1788: conflicting types for `_errno'
d:/MinGW/include/stdlib.h:153: previous declaration of `_errno'
sql.c:1788: warning: extern declaration of `_errno' doesn't A4GL_match global one
make[2]: *** [sql.o] Error 1
*/
#ifndef __MINGW32__
  SDWORD errno=0;
#endif
  SWORD errno2=0;
  SDWORD rowcount;
  RETCODE rc;
  memset(s1,0,80);
  memset(s2,0,255);
  strcpy (lasterrorstr, "");
  strcpy (s1, "00000");

  /* chk_rc (rc, hstmt, "SQLRowCount"); */
#ifdef DEBUG
  A4GL_debug ("set_sqlca...%p %p %p", henv, hdbc, hstmt);
  A4GL_debug ("set sqlca caused by %s", s);
#endif
  rc = -1;

  if (rc != 0 && rc != 100)
    {
      A4GL_debug ("Calling SQLError %p %p %p rc=%d", henv, hdbc, hstmt, rc);
      rc = SQLError (henv, hdbc, (SQLHSTMT)hstmt, s1, &errno, s2, 500, &errno2); //warning: passing arg 5 of `SQLError' from incompatible pointer type
      A4GL_debug ("rc=%d\n", rc);
      if (errno > 0 && errno != 100)
	errno = 0 - errno;
#ifdef DEBUG
      A4GL_debug ("After SQL Error %d %s %s\n%x", errno, s1, s2, errno2);
#endif
      if (strlen (s1) == 0)
	strcpy (s1, "00000");

      strcpy (a4gl_sqlca.sqlstate, s1);

      if (strcmp (s1, "00000") == 0)
	{
	  errno = 0;
	  errno2 = 0;
	}

      if ((strcmp (s1, "00000") != 0 && errno == 0)
	  || (s1[0] == '0' && s1[1] == '1'))
	{
#ifdef DEBUG
	  A4GL_debug ("Got %s as state", s1);
#endif
	  if (errno == 0)
	    {
	      errno = -101;
	      errno2 = 0;
	    }
	}

#ifdef DEBUG
      A4GL_debug ("'%s' '%s' (%d %d)", s1, s2, errno, errno2);
#endif
      strncpy (a4gl_sqlca.sqlerrm, s2, 72);
      A4GLSQL_set_status (errno, 1);
#ifdef DEBUG
      A4GL_debug ("Setting lasterrorstr to '%s'", s2);
#endif
      strcpy (lasterrorstr, s2);
    }
  if (rc==0 || rc==100 ) {
	if (rc==100) rowcount=0;
	else {
  		rc = SQLRowCount ((SQLHSTMT )hstmt, &rowcount);
	}
  a4gl_sqlca.sqlerrd[1] = rowcount;
  } else {
  	a4gl_sqlca.sqlerrd[1] =0;
  }
}

/**
 * Do a output bind of variable to the statement.
 *
 * @param pos Position / sequence in the bind array.
 * @param bind Pointer to the bind array.
 * @param hstmt Statement handle.
 */
void
A4GL_obind_column (int pos, struct BINDING *bind, HSTMT hstmt)
{
  static int rc;

#ifdef DEBUG
  A4GL_debug ("OBIND Binding %d=(%d %d %p)", pos, bind->dtype, bind->size,
	 bind->ptr);

  //if (bind->dtype==0) {
		//A4GL_debug("Binding : %s\n",bind->ptr);
  //}

  A4GL_debug
    ("SQLBindCol(hstmt=%p, pos=%d,\n     bind->dtype=%d conv_4gl_to_c[bind->dtype]=%d, bind->ptr=%p,\n     fgl_size(bind->dtype,bind->size)=%d, SQL_NULL_DATA);",
     hstmt, pos, bind->dtype,conv_4gl_to_c[bind->dtype], bind->ptr, fgl_size (bind->dtype,
								  bind->size),
     SQL_NULL_DATA);
  A4GL_debug ("SQLBindCol");
#endif

  if (bind->dtype == DTYPE_DATE)  { bind->ptr = A4GL_bind_date ((long *) bind->ptr); }
  if (bind->dtype == DTYPE_DTIME) { bind->ptr = A4GL_bind_datetime ((void *) bind->ptr); }



  if (bind->dtype == DTYPE_BYTE || bind->dtype == DTYPE_TEXT)
    {
      return;
    }

  rc =
    SQLBindCol ((SQLHSTMT )hstmt, pos, conv_4gl_to_c[bind->dtype], bind->ptr,
		fgl_size (bind->dtype, bind->size), &outlen[pos]);

  chk_rc (rc, hstmt, "SQLBindCol");
#ifdef DEBUG
  A4GL_debug ("SQLBindCol returned %d", rc);
#endif
  /* A4GL_set_sqlca (hstmt, "obind_column : After SQLBindCol", 0); */

}

/**
 * Do a input bind of variable to the statement.
 *
 * @param pos Position/sequence of the parameter.
 * @param bin  Pointer to the element in the bin array that decribes the
 * bin to be done.
 * @param hstmt A pointer to the statement information.
 */
void
A4GL_ibind_column (int pos, struct BINDING *bind, HSTMT hstmt)
{
  int size;
  /* DATE_STRUCT *tmp; */
  /*review */

  int k = 0;
A4GL_debug("ibind_column %d",bind->dtype,DTYPE_DECIMAL);
  if (bind->dtype == DTYPE_DATE && A4GL_isyes(acl_getenv("BINDDATEASINT")))
    {
      	rc = A4GL_newSQLSetParam ((SQLHSTMT )hstmt, pos, SQL_INTEGER, SQL_INTEGER, 0, 0, bind->ptr, NULL);
	return;
    }

#ifdef DEBUG
  A4GL_debug ("Binding %d=(%d %d %p)", pos, bind->dtype, bind->size, bind->ptr);
  if (bind->dtype==0) {
	A4GL_debug(" is a string : %s",bind->ptr);
  }
#endif

  if (bind->dtype != 0)
    size = 0;
  else
    size = bind->size;

#ifdef DEBUG
  if (bind->dtype==0) {
  A4GL_debug(" Binding : %s ",bind->ptr);
  }
  A4GL_debug ("Call SQLSetParam h=%p p=%d dt=%d dt=%d size=%d k=%d ptr=%p", hstmt, pos, conv_4gl_to_c[bind->dtype], conv_4gl_to_c[bind->dtype], size, k, bind->ptr);
#endif

  if (bind->dtype == DTYPE_DATE)
    {
	ACLDATE *p; //@todo FIXME - THIS WILL CREATE A MEMORY LEAK - NEED TO CLEAN THIS AFTER ITS FINISHED BEING USED...
	void *ptr;
	int d,m,y;
	A4GL_debug("Binding Date original pointer=%p",bind->ptr);
	ptr=bind->ptr;
	p= (ACLDATE *)A4GL_bind_date ((long *) ptr);
	A4GL_get_date(*(int *)ptr,&d,&m,&y);
	p->date.year=y;
	p->date.month=m;
	p->date.day=d;
        bind->ptr = p;
    }


  if (bind->dtype == DTYPE_DTIME)
    {
	ACLDTIME *p; //@todo FIXME - THIS WILL CREATE A MEMORY LEAK - NEED TO CLEAN THIS AFTER ITS FINISHED BEING USED...
	int arr[10];
	//char buff[50];
	void *ptr;
	//int d,m,y;
	A4GL_debug("Binding Date original pointer=%p",bind->ptr);
	ptr=bind->ptr;
	p= (ACLDTIME *)A4GL_bind_datetime (ptr);
#ifdef DTIME_AS_CHAR
	A4GL_dttoc(ptr,buff,bind->size);
	A4GL_trim(buff);
	strcpy(p->dtime,buff);
#else
	A4GL_decode_datetime((struct A4GLSQL_dtime*)ptr,&arr[0]);
	p->dtime.year=arr[0];
	p->dtime.month=arr[1];
	p->dtime.day=arr[2];
	p->dtime.hour=arr[3];
	p->dtime.minute=arr[4];
	p->dtime.second=arr[5];
	p->dtime.fraction=arr[6];

#endif
        bind->ptr = p;
    }


  if (bind->dtype == DTYPE_DECIMAL)
    {
	double *p; //@todo FIXME - THIS WILL CREATE A MEMORY LEAK - NEED TO CLEAN THIS AFTER ITS FINISHED BEING USED...
	void *ptr;
	int dtype;
	double d;
	ptr=bind->ptr;
	p= malloc(sizeof(double));
	dtype = bind->dtype + ENCODE_SIZE (bind->size);
	A4GL_push_variable(bind->ptr, dtype);
	d=A4GL_pop_double();
	*p=d;
        bind->ptr = p;

#ifdef DEBUG
      A4GL_debug ("Bound date...\n");
#endif
    }





  rc = A4GL_newSQLSetParam ((SQLHSTMT )hstmt, pos, conv_4gl_to_c[bind->dtype], conv_4gl_to_c[bind->dtype], size, k, bind->ptr, NULL);

  A4GL_debug("Called newSQLSetParam = %d",rc);
  /* chk_rc (rc, hstmt, "SQLSetParam"); */

}

/**
 * Ask odbc to execute a select statement allready prepared.
 *
 * @param hstmt The statement handle.
 * @return
 *   - 1 : Statement executed.
 *   - 0 : An error ocurred.
 */
int
ODBC_exec_select (SQLHSTMT hstmt)
{
  int rc;
  SWORD nresultcols;
  SDWORD rowcount;

a4gl_sqlca.sqlerrd[0]=0;
#ifdef DEBUG
  A4GL_debug ("Before Execute hstmt=%p", hstmt);
#endif
  rc = SQLExecute (hstmt);
  rc = A4GL_chk_need_blob (rc, hstmt);
  chk_rc (rc, hstmt, "SQLExecute3");
  if (rc != 0)
    return 0;

  /* A4GL_set_sqlca (hstmt, "ODBC_exec_select : After SQLExecute", 0); */
  if (rc != 0)
    return 0;
  rc = SQLNumResultCols (hstmt, &nresultcols);
  chk_rc (rc, hstmt, "SQLNumResultCols");
#ifdef DEBUG
  A4GL_debug ("SQLNumResultCols returns %d", nresultcols);
#endif
   if (nresultcols==0) {
		a4gl_sqlca.sqlerrd[0]=0;
		return 0;
	}
  rc = SQLRowCount ((SQLHSTMT )hstmt, &rowcount);
  chk_rc (rc, hstmt, "SQLRowCount");
  

#ifdef DEBUG
  A4GL_debug ("SQLRowCount=%d", rowcount);
  A4GL_debug ("Before Fetch");
#endif

  if (rc == 100)  {
	A4GL_debug("NOT Found");
    a4gl_sqlca.sqlerrd[0]=1;
    return 0;
  }

  rc = SQLFetch ((SQLHSTMT )hstmt);
  chk_rc (rc, hstmt, "SQLFetch");

  /* A4GL_set_sqlca (hstmt, "ODBC_exec_select : After SQLFetch", 0); */

#ifdef DEBUG
  A4GL_debug ("Result=%d", rc);
#endif

  if (rc == 100)  {
	A4GL_debug("NOT Found");
    a4gl_sqlca.sqlerrd[0]=1;
	return 1;
  }

  /* Execute the SQL statement. */
  if (rc != SQL_SUCCESS)
    {
	int a;
#ifdef DEBUG
      A4GL_debug ("Oh dear.... %d", rc);
#endif
	a4gl_sqlca.sqlerrd[0]=0;
	a=A4GL_sqlerrwith (rc, hstmt);
      return  a;

    }

a4gl_sqlca.sqlerrd[0]=1;
#ifdef DEBUG
  A4GL_debug ("Yipee!");
#endif
  return 1;
}

/**
 * Create a statement handle.
 *
 * Ask to odbc to give a statement handler.
 *
 * @param A pointer to the statement handle structure to be created.
 * @retutn The statement handler.
 */
HSTMT *
A4GL_new_hstmt (SQLHSTMT * hstmt)
{
  int rc;
#ifdef DEBUG
  A4GL_debug ("Database : %s", OldDBname);
#endif
  if (hdbc == 0)
    {
#ifdef DEBUG
      A4GL_debug ("*** No current connection ....");
#endif
      A4GL_exitwith ("Not connected to database");
      return 0;
    }
  rc = SQLAllocStmt (hdbc, hstmt);
  chk_rc (rc, 0, "SQLAllocStmt");
#ifdef DEBUG
  A4GL_debug ("allocate statement returns rc=%d", rc);
#endif
  return (HSTMT *)*hstmt;
}

/**
 * Ask odbc to execute a prepared SQL statement.
 *
 * @param hstmt A statement handle.
 * @return
 *   - 1 : Statement executed.
 *   - 0 : An error ocurred.
 */
int
ODBC_exec_prepared_sql (SQLHSTMT hstmt)
{
  int rc;

#ifdef DEBUG
  A4GL_debug ("In exec_prepared_sql");
#endif

  rc = SQLExecute (hstmt);

  rc = A4GL_chk_need_blob (rc, hstmt);

  chk_rc (rc, hstmt, "SQLExecute");
  A4GL_set_sqlca (hstmt, "ODBC_exec_prepared_sql : After SQLExecute", 0);

#ifdef DEBUG
  A4GL_debug ("Result=%d", rc);
#endif

  /* Execute the SQL statement. */
  if (rc != SQL_SUCCESS)
    {
	//int a;
#ifdef DEBUG
      A4GL_debug ("Oh dear.... %d", rc);
#endif
      return A4GL_sqlerrwith (rc, hstmt);
    }
#ifdef DEBUG
  A4GL_debug ("Yipee!");
#endif
  rc = SQLTransact (henv, hdbc, SQL_COMMIT);
  chk_rc (rc, 0, "SQLTransact (COMMIT)");
  A4GL_set_sqlca (hstmt, "ODBC_exec_prepared_sql : After SQLTransact", 0);
  return 1;
}


/* FIXME: what is this doing? */
#define IGNOREEXITWITH
IGNOREEXITWITH
/**
 * Ask the database about the datatype of a column.
 *
 *
 * @param db The database name.
 * @param tab The table name.
 * @param col The column name.
 * @return 
 *   - -1 : An error ocurred.
 *   - Otherwise : The datatype code.
 */
  int
A4GLSQL_get_datatype (char *db, char *tab, char *col)
{
  HSTMT hstmt;
  char sql1[256];
  UCHAR colname[32];
  SWORD coltype;
  SWORD colnamelen;
  SWORD nullable;
  UDWORD collen[1];
  SWORD scale;

  A4GLSQL_init_connection (db);
#ifdef DEBUG
  A4GL_debug ("Getting datatype for %s %s %s", db, tab, col);
#endif
  A4GL_new_hstmt ((SQLHSTMT *)&hstmt);
#ifdef DEBUG
  A4GL_debug ("Allocated .. %p %p %p", henv, hdbc, hstmt);
#endif
  sprintf (sql1, "select %s from %s where 1=0", col, tab);
#ifdef DEBUG
  A4GL_debug ("Executing... %s", sql1);
#endif
  /* Execute the SQL statement. */
  if (SQLExecDirect (hstmt, sql1, SQL_NTS) != SQL_SUCCESS)
    {
#ifdef DEBUG
      A4GL_debug ("Error executing\n");
#endif
      return -1;
    }

#ifdef DEBUG
  A4GL_debug ("Executed OK");
#endif

  SQLDescribeCol (hstmt, 1, colname,
		  (SWORD) sizeof (colname),
		  &colnamelen, &coltype, &collen[0], &scale, &nullable);
#ifdef DEBUG
  A4GL_debug ("SQL DATATYPE : Got %s %d %d", colname, coltype, collen[0]);
#endif
  SQLFreeStmt (hstmt, SQL_DROP);
	hstmt=0;
  SQLFreeConnect (hdbc);
  return conv_sqldtype (coltype, collen[0]);
}

/**
 * Convert the SQL data type to the 4gl data type.
 *
 * Use the table convneg_sql_to_4gl.
 *
 * @param sqldtype The sql datatype returned by ODBC.
 * @param sdim
 * @return The 4gl data type.
 */
static int
conv_sqldtype (int sqldtype, int sdim)
{
int ndtype;

//#if (ODBCVER >= 0x0300)
	#ifdef SQL_TYPE_DATE
	if (sqldtype==SQL_TYPE_DATE) return DTYPE_DATE;
	#endif


	if (sqldtype >= 0)
    	ndtype = convpos_sql_to_4gl[sqldtype];
	else
	    ndtype = convneg_sql_to_4gl[sqldtype * -1];

	if (ndtype == 0)
    {
	#ifdef DEBUG
      A4GL_debug ("Encoding string size : %d", sdim);
	#endif
      ndtype = ENCODE_SIZE (sdim);
    }

	#ifdef DEBUG
	A4GL_debug ("Datatype (%d,%d) is 0x%x ", sqldtype, sdim, ndtype);
	#endif
	return ndtype;
}

/**
 * Gets the current database name.
 *
 * @return The current database name.
 */
char *
A4GLSQL_get_currdbname (void)
{
  return OldDBname;
}

/**
 * Describe a column for an existing statement 
 *
 * @param hstmt The statement handler.
 * @param colno
 * @param type The type of the decribing information to return.
 *   - 0: The column type.
 *   - 1: The column name.
 *   - 2: The scale.
 *   - 3: The column length.
 *   - 4: Nullable or not
 *  @return The description wanted  or zero if there was an error.
 */
long
A4GL_describecolumn (SQLHSTMT hstmt, int colno, int type)
{
  static char colname[256];
  SWORD coltype;
  SWORD colnamelen;
  SWORD nullable;
  UDWORD collen;
  SWORD scale;
  SWORD nresultcols;
  SDWORD rowcount;
  int rc;

  if (hstmt == 0)
    {
      A4GL_exitwith ("Statement has not been prepared");
      return 0;
    }

  if (type == 5)
    {
      SQLNumResultCols (hstmt, &nresultcols);
      return nresultcols;
    }

  if (type == 6)
    {
      SQLRowCount (hstmt, &rowcount);
      return rowcount;
    }

  rc = SQLDescribeCol (hstmt, colno, colname,
		       (SWORD) sizeof (colname),
		       &colnamelen, &coltype, &collen, &scale, &nullable);
  if (rc != SQL_SUCCESS)
    {
      A4GL_set_sqlca (hstmt, "Describe column", 0);
      return 0;
    }

#ifdef DEBUG
  A4GL_debug ("SQL DATATYPE : Got %s %d %d", colname, coltype, collen);
  A4GL_debug ("Returning type code : %d", type);
  A4GL_debug ("Col type = %d %d", coltype, collen);
#endif

  coltype = conv_sqldtype (coltype, collen);
#ifdef DEBUG
  A4GL_debug ("Converted type");
#endif
  switch (type)
    {
    case 0:
      return coltype;
    case 1:
      return (long) colname;
    case 2:
      return scale;
    case 3:
      return collen;
    case 4:
      return nullable;
    }

  A4GL_exitwith ("Internal Error (describecolumn)");
  return 0;
}

/**
 * Describe an sql statement.
 *
 * @param stmt The text with the statement to be described.
 * @param colno
 * @param type The type of the information wanted.
 * @return
 */
long
A4GLSQL_describe_stmt (char *stmt, int colno, int type)
{
  struct s_sid *sid;
  HSTMT *hstmt;
  struct s_cid *cid;
  long z;

  sid = A4GLSQL_find_prepare (stmt);
  cid = 0;

  if (sid == 0)
    {
#ifdef DEBUG
      A4GL_debug ("Sid=0 - try as a cursor");
#endif
      cid = A4GLSQL_find_cursor (stmt);
#ifdef DEBUG
      A4GL_debug ("cid=%p", cid);
#endif
      if (cid == 0)
	{
	  A4GL_exitwith ("Could not find statement or cursor specified");
	  return 0;

	}
      hstmt = cid->hstmt;
    }
  else
    {
      hstmt = (SQLHSTMT *)&sid->hstmt;
    }


  if (sid == 0 && cid == 0)
    {
      A4GL_exitwith ("Statement could not be found");
    }

  z = A4GL_describecolumn ((SQLHSTMT)hstmt, colno, type);
  return z;
}

/**
 * Gets information about columns from a table in the database engine.
 *
 * @param tabname The table that we wish to get information about it.
 * @param colname The column name to get information about it.
 * @param dtype A pointer to the variable where to put the data type.
 * @param size A pointer to the variable where to put the size of the column
 *  returned by the database.
 * @return
 *   - 1 : Information readed.
 *   - 0 : Error ocurred.
 */
int
A4GLSQL_get_columns (char *tabname, char *colname, int *dtype, int *size)
{
  static char tq[256];
  static char to[256];
  static char tn[256];
  static char dtname[256];
  static long len;
  static long scale;
  static long radix;
  static long nullable;
  static char remarks[256];
  static int a, b;
  static int rc;
  short nColumns;

  hstmtGetColumns = 0;
  if (hdbc == 0)
    {
      A4GL_exitwith ("Not connected to database");
      return 0;
    }

  if (hstmtGetColumns == 0)
    {
#ifdef DEBUG
      A4GL_debug ("Creating new statement");
#endif
      A4GL_new_hstmt ((SQLHSTMT *)&hstmtGetColumns);
    }

  if (tabname != 0)
    {
#ifdef DEBUG
      A4GL_debug ("New search");
#endif
      //new_hstmt (&hstmtGetColumns);
#ifdef DEBUG
      A4GL_debug ("Got Statement");
#endif

/*
SQLColumns (hstmt, "DatabaseName", SQL_NTS,  // qualifier
NULL, 0,                                     // owner
"TcpConnectionTable", SQL_NTS,               // table
"%",SQL_NTS);                                // all columns
*/
      rc = SQLColumns (hstmtGetColumns,
		       NULL, 0, NULL, 0, tabname, SQL_NTS, NULL, 0);

      if (rc != SQL_SUCCESS)
	{
#ifdef DEBUG
	  A4GL_debug ("Some problem with SQLColumns");
#endif
	}

      if (rc == SQL_ERROR)
	{
#ifdef DEBUG
	  A4GL_debug ("SQLColumns failed for table '%s'\n", tabname);
#endif
	  A4GL_set_sqlca (hstmtGetColumns, "getting column info", 0);
	  A4GL_exitwith ("Error getting column info\n");
	  return 0;
	}
#ifdef DEBUG
      A4GL_debug ("rc=%d\n", rc);
#endif

      if (SQLNumResultCols (hstmtGetColumns, &nColumns) != SQL_SUCCESS)
	{
#ifdef DEBUG
	  A4GL_debug ("No NumResultCols");
#endif
	  nColumns = -1;
	}

#ifdef DEBUG
      A4GL_debug ("nColumns=%d", nColumns);
#endif

      a = 79;
      b = 254;
      rc = SQLBindCol (hstmtGetColumns, 1, SQL_C_CHAR, tq, 255, &outlen[1]);
#ifdef DEBUG
      A4GL_debug ("Rc=%d", rc);
#endif
      rc = SQLBindCol (hstmtGetColumns, 2, SQL_C_CHAR, to, 255, &outlen[2]);
#ifdef DEBUG
      A4GL_debug ("Rc=%d", rc);
#endif
      rc = SQLBindCol (hstmtGetColumns, 3, SQL_C_CHAR, tn, 255, &outlen[3]);
#ifdef DEBUG
      A4GL_debug ("Rc=%d", rc);
#endif
      rc = SQLBindCol (hstmtGetColumns, 4, SQL_C_CHAR, cn, 255, &outlen[4]);
#ifdef DEBUG
      A4GL_debug ("Rc=%d", rc);
#endif
      rc =
	SQLBindCol (hstmtGetColumns, 6, SQL_C_CHAR, dtname, 255, &outlen[6]);
#ifdef DEBUG
      A4GL_debug ("Rc=%d", rc);
#endif
      rc = SQLBindCol (hstmtGetColumns, 5, SQL_C_LONG, &dt, 4, &outlen[5]);
#ifdef DEBUG
      A4GL_debug ("Rc=%d", rc);
#endif
      rc = SQLBindCol (hstmtGetColumns, 7, SQL_C_LONG, &prec, 4, &outlen[7]);
#ifdef DEBUG
      A4GL_debug ("Rc=%d", rc);
#endif
      rc = SQLBindCol (hstmtGetColumns, 8, SQL_C_LONG, &len, 4, &outlen[8]);
#ifdef DEBUG
      A4GL_debug ("Rc=%d", rc);
#endif
      rc = SQLBindCol (hstmtGetColumns, 9, SQL_C_LONG, &scale, 4, &outlen[9]);
#ifdef DEBUG
      A4GL_debug ("Rc=%d", rc);
#endif
      rc =
	SQLBindCol (hstmtGetColumns, 10, SQL_C_LONG, &radix, 4, &outlen[10]);
#ifdef DEBUG
      A4GL_debug ("Rc=%d", rc);
#endif
      rc =
	SQLBindCol (hstmtGetColumns, 11, SQL_C_LONG, &nullable, 4,
		    &outlen[11]);
#ifdef DEBUG
      A4GL_debug ("Rc=%d", rc);
#endif
      rc =
	SQLBindCol (hstmtGetColumns, 12, SQL_C_CHAR, remarks, 255,
		    &outlen[12]);
#ifdef DEBUG
      A4GL_debug ("Rc=%d", rc);
      A4GL_debug ("Bound columns\n");
#endif

    }
  return 1;
}


/**
 * Iterate in getting information about all columns from a table from the 
 * database engine.
 *
 * A4GLSQL_get_columns(char *tabname) should be called before this one.
 *
 * This is used to declare record like table.*
 *
 * @param colname The place where to put the column name
 * @param dtype A pointer to the variable where to put the data type.
 * @param size A pointer to the variable where to put the size of the column
 *  returned by the database.
 * @return 
 *   - 1 : Information readed.
 *   - 0 : Error ocurred.
 */
int
A4GLSQL_next_column (char **colname, int *dtype, int *size)
{
  rc = SQLFetch (hstmtGetColumns);
#ifdef DEBUG
  A4GL_debug ("A4GLSQL_next_column fetch rc = %d, cn = %s\n", rc, cn);
#endif

  if (rc == SQL_NO_DATA_FOUND || rc == SQL_ERROR)
    {
      return 0;
    }

  colsize = A4GL_display_size (dt, prec, "");
  sprintf (szcolsize, "%d", colsize);

  if (rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO)
    {
      SQLFreeStmt (hstmtGetColumns, SQL_DROP);
	hstmtGetColumns=0;
      return 0;
    }
  *colname = cn;
  *size = prec;
  *dtype = conv_sqldtype (dt, prec);
  return 1;
}

/**
 * Free all resources allocated in getting information about columns
 * 
 * @return 
 *   - 0 : Descriptor dealocated
 *   - 1 : Error ocurred.
 */
int
A4GLSQL_end_get_columns (void)
{
  return 0;
}


/**
 * Gets information about columns from a table in the database engine.
 *
 * @param tabname The table that we wish to get information about it.
 * @param colname The column name to get information about it.
 * @param dtype A pointer to the variable where to put the data type.
 * @param size A pointer to the variable where to put the size of the column
 *  returned by the database.
 * @return
 *   - 1 : Information readed.
 *   - 0 : Error ocurred.
 */
int
A4GLSQL_read_columns (char *tabname, char *colname, int *dtype, int *size)
{
  static HSTMT hstmt = 0;
  static char tq[256];
  static char to[256];
  static char tn[256];
  static char cn[256];
  static int dt;
  static char dtname[256];
  static long prec;
  static long len;
  static long scale;
  static long radix;
  static long nullable;
  static char remarks[256];
  static int colsize;
  static char szcolsize[20];
  static int a, b;
  static int rc;
  short nColumns;

  if (hdbc == 0)
    {
      A4GL_exitwith ("Not connected to database");
      return 0;
    }
#ifdef DEBUG
  A4GL_debug ("In read column tabname='%s' colname='%s'", tabname, colname);
#endif

  if (hstmt == 0)
    {
#ifdef DEBUG
      A4GL_debug ("Creating new statement");
#endif
      A4GL_new_hstmt ((SQLHSTMT *)&hstmt);
    }

  if (tabname != 0)
    {
#ifdef DEBUG
      A4GL_debug ("New search");
#endif
      A4GL_new_hstmt ((SQLHSTMT *)&hstmt);
#ifdef DEBUG
      A4GL_debug ("Got Statement");
#endif

      rc = SQLColumns (hstmt, NULL, 0, NULL, 0, tabname, SQL_NTS, NULL, 0);

      if (rc != SQL_SUCCESS)
	{
#ifdef DEBUG
	  A4GL_debug ("Some problem with SQLColumns");
#endif
	}

      if (rc == SQL_ERROR)
	{
#ifdef DEBUG
	  A4GL_debug ("SQLColumns failed for table '%s'\n", tabname);
#endif
	  A4GL_set_sqlca (hstmt, "getting column info", 0);
	  A4GL_exitwith ("Error getting column info\n");
	  //exitwith will not exit when running 4glc - must use a4gl_yyerror()
	  //a4gl_yyerror("Error getting column info\n");
	  //but can't do that unless I link libSQL_xxx.dll with lib4glc.dll - On Windows
	  //there can't be any unresolved sybols at linking!

	  return 0;
	}

#ifdef DEBUG
      A4GL_debug ("rc=%d\n", rc);
#endif

      if (SQLNumResultCols (hstmt, &nColumns) != SQL_SUCCESS)
	{
#ifdef DEBUG
	  A4GL_debug ("No NumResultCols");
#endif
	  nColumns = -1;
	}

#ifdef DEBUG
      A4GL_debug ("nColumns=%d", nColumns);
#endif

      a = 79;
      b = 254;
      rc = SQLBindCol (hstmt, 1, SQL_C_CHAR, tq, 255, &outlen[1]);
#ifdef DEBUG
      A4GL_debug ("Rc=%d", rc);
#endif
      rc = SQLBindCol (hstmt, 2, SQL_C_CHAR, to, 255, &outlen[2]);
#ifdef DEBUG
      A4GL_debug ("Rc=%d", rc);
#endif
      rc = SQLBindCol (hstmt, 3, SQL_C_CHAR, tn, 255, &outlen[3]);
#ifdef DEBUG
      A4GL_debug ("Rc=%d", rc);
#endif
      rc = SQLBindCol (hstmt, 4, SQL_C_CHAR, cn, 255, &outlen[4]);
#ifdef DEBUG
      A4GL_debug ("Rc=%d", rc);
#endif
      rc = SQLBindCol (hstmt, 6, SQL_C_CHAR, dtname, 255, &outlen[6]);
#ifdef DEBUG
      A4GL_debug ("Rc=%d", rc);
#endif
      rc = SQLBindCol (hstmt, 5, SQL_C_LONG, &dt, 4, &outlen[5]);
#ifdef DEBUG
      A4GL_debug ("Rc=%d", rc);
#endif
      rc = SQLBindCol (hstmt, 7, SQL_C_LONG, &prec, 4, &outlen[7]);
#ifdef DEBUG
      A4GL_debug ("Rc=%d", rc);
#endif
      rc = SQLBindCol (hstmt, 8, SQL_C_LONG, &len, 4, &outlen[8]);
#ifdef DEBUG
      A4GL_debug ("Rc=%d", rc);
#endif
      rc = SQLBindCol (hstmt, 9, SQL_C_LONG, &scale, 4, &outlen[9]);
#ifdef DEBUG
      A4GL_debug ("Rc=%d", rc);
#endif
      rc = SQLBindCol (hstmt, 10, SQL_C_LONG, &radix, 4, &outlen[10]);
#ifdef DEBUG
      A4GL_debug ("Rc=%d", rc);
#endif
      rc = SQLBindCol (hstmt, 11, SQL_C_LONG, &nullable, 4, &outlen[11]);
#ifdef DEBUG
      A4GL_debug ("Rc=%d", rc);
#endif
      rc = SQLBindCol (hstmt, 12, SQL_C_CHAR, remarks, 255, &outlen[12]);
#ifdef DEBUG
      A4GL_debug ("Rc=%d", rc);
      A4GL_debug ("Bound columns\n");
#endif

    }

  rc = SQLFetch (hstmt);

#ifdef DEBUG
  A4GL_debug ("Rc = %d", rc);
#endif
  if (colname[0] != 0)
    {
      /* if were looking for a specific column ... */
      A4GL_trim (cn);
      while (strcasecmp (cn, colname) != 0)
	{

#ifdef DEBUG
	  A4GL_debug ("Calling Fetch... %s %s\n", cn, colname);
#endif

	  rc = SQLFetch (hstmt);
	  A4GL_trim (cn);
#ifdef DEBUG
	  A4GL_debug ("Fetch called - %d\n", rc);
#endif
	  if (rc == SQL_NO_DATA_FOUND || rc == SQL_ERROR)
	    {
	      return 0;
	    }
	}
    }

  if (rc == SQL_NO_DATA_FOUND || rc == SQL_ERROR)
    {
      return 0;
    }

#ifdef DEBUG
  A4GL_debug ("column -> %s Dtype=%x len=%x rc=%d", cn, dt, len, rc);
  A4GL_debug ("column tq=%s to=%s tn=%s cn=%s", tq, to, tn, cn);
  A4GL_debug ("XXX       %x %s prec=%x %d\n %x %x %x '%s'", dt, dtname, prec, len,
	 scale, radix, nullable, remarks);
#endif
  colsize = A4GL_display_size (dt, prec, "");
  sprintf (szcolsize, "%d", colsize);

  if (rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO)
    {
#ifdef DEBUG
      A4GL_debug ("Some error getting data....");
#endif
      SQLFreeStmt (hstmt, SQL_DROP);
	hstmt=0;
      return 0;
    }
  strcpy (colname, cn);
  *size = prec;
  *dtype = conv_sqldtype (dt, prec);
#ifdef DEBUG
  A4GL_debug ("Set dtype to %d\n", *dtype);
#endif
  return 1;
}

/**
 *
 *
 * @param
 */
void
A4GL_ibind_column_arr (int pos, char *s, HSTMT hstmt)
{
  int size;
/* DATE_STRUCT *tmp; */
/*review */

  size = strlen (s);

  A4GL_newSQLSetParam (hstmt, pos,
		  conv_4gl_to_c[0], conv_4gl_to_c[0], size, 0, s, NULL);
}

/**
 * Init a new connection to the database and associate with an explicit
 * session name.
 *
 * If the user identification was not set gets the values fromthe environment.
 *
 * @param sessname The name to be tied to the session.
 * @param dsn The data source name.
 * @param usr The user name to establish the connection.
 * @param pwd The password of the user to set the connection.
 */
int
A4GLSQL_init_session_internal (char *sessname, char *dsn, char *usr, char *pwd)
{
  char empty[10] = "None";
  char *u, *p = 0;
  HDBC *hh;

  if (sessname == 0 || strlen (sessname) == 0)
    {
      return 0;
    }

  hh = A4GL_find_pointer_val (sessname, SESSCODE);

  if (hh)
    {
      A4GL_exitwith ("Session already opened");
      return 0;
    }

  if (strcmp (sessname, sess_name) == 0)
    return 0;

  A4GL_set_errm (dsn);

  if (usr == 0)
    u = acl_getenv ("SQLUID");
  else
    u = usr;

  if (pwd == 0)
    p = acl_getenv ("SQLPWD");
  else
    p = pwd;

#ifdef DEBUG
  A4GL_debug ("Got environment variables");
#endif

  if (u == 0)
    u = empty;
  if (p == 0)
    p = empty;

#ifdef DEBUG
  A4GL_debug ("u=%s p=%s", u, p);
  A4GL_debug ("Try to make connection then ..%s ", dsn);
#endif

  if (A4GLSQL_make_connection (dsn, u, p))
    {
      /* do we have an existing pointer to default */
      hh = malloc (sizeof (HDBC));
      A4GL_add_pointer (sessname, SESSCODE, hh);
      *hh = hdbc;

#ifdef DEBUG
      A4GL_debug ("Made connection executing SQL");
#endif
    }
  else
    {
      A4GL_exitwith ("Could not connect to database");
    }
  strcpy (sess_name, sessname);
  return 0;
}

/**
 * Get the current session name.
 *
 * @return The current connection name.
 */
char *
A4GLSQL_get_curr_conn (void)
{
  return sess_name;
}

/**
 * @todo : Check if not used and clear it
 * @deprecated
 *
 * @param cursname The cursor name.
 * @param opt
 * @param val
 */
/*
int
set_stmt_options (char *cursname, char *opt, char *val)
{
  int code;
  struct s_sid *ptr_sid;
  struct s_cid *ptr_cid;
  HSTMT stmt;
  code = CURCODE;

  if (!(A4GL_find_pointer_val (cursname, code)))
    {
      code = PRECODE;
      if (!(A4GL_find_pointer_val (cursname, code)))
	{
	  A4GL_set_errm (cursname);
	  A4GL_exitwith ("%s is not a statement or cursor name");
	  return 0;
	}
    }

  if (code == PRECODE)
    {
      A4GL_debug ("Is prepare statement");
      ptr_sid = (struct s_sid *) A4GL_find_pointer (cursname, PRECODE);
      stmt = &ptr_sid->hstmt;
    }
  else
    {
      A4GL_debug ("Is cursor statement");
      ptr_cid = (struct s_cid *) A4GL_find_pointer (cursname, CURCODE);
      stmt = &ptr_cid->statement->hstmt;
    }


  scan_stmt (opt, val, stmt);
return 1;
}
*/


/**
 * @todo : Confirm that this function is not used and remove it.
 * @deprecated
 */
int
aclfgl_hstmt_get (int np)
{
  int code;
  struct s_sid *ptr_sid;
  struct s_cid *ptr_cid;
  char aa[21];
  char cursname[64];
  SQLHSTMT stmt;
  code = CURCODE;

  if (np != 1)
    {
      for (code = 0; code < np; code++)
	{
	  A4GL_pop_char (aa, 20);
	  return 0;
	}
    }
  A4GL_pop_char (cursname, 64);
  A4GL_trim (cursname);

  if (!(A4GL_find_pointer_val (cursname, code)))
    {
      code = PRECODE;
      if (!(A4GL_find_pointer_val (cursname, code)))
	{
	  A4GL_set_errm (cursname);
	  A4GL_exitwith ("%s is not a statement or cursor name");
	  return 0;
	}
    }

  if (code == PRECODE)
    {
#ifdef DEBUG
      A4GL_debug ("Is prepare statement");
#endif
      ptr_sid = (struct s_sid *) A4GL_find_pointer (cursname, PRECODE);
      stmt = (SQLHSTMT )&ptr_sid->hstmt;
    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("Is cursor statement");
#endif
      ptr_cid = (struct s_cid *) A4GL_find_pointer (cursname, CURCODE);
      stmt = (SQLHSTMT )&ptr_cid->statement->hstmt;
    }

  A4GL_push_long ((int) stmt);
  return 1;
}

/**
 * Sets the connection to use in the execution of the next SQL statement.
 *
 * ODBC dynamic library.
 *
 * @param sessname The session name.
 */
int
A4GLSQL_set_conn_internal (char *sessname)
{
  HDBC *hdbc_new;

  if (A4GL_find_pointer_val (sessname, SESSCODE))
    {
      strcpy (sess_name, sessname);
      hdbc_new = (HDBC *) A4GL_find_pointer_val (sessname, SESSCODE);
      hdbc = *hdbc_new;
    }
  else
    {
      if (strcmp (sessname, "default") != 0)
	{
	  A4GL_set_errm (sessname);
	  A4GL_exitwith
	    ("Could not make session (%s) current as it does not exist");
	  return 0;
	}
      else
	{
	  strcpy (sess_name, "default");
	}
    }

  ODBC_set_dbms_info ();
  return 1;
}

/**
 * Find the session and if exist close it.
 *
 * @param sessname The session name.
 * @return 
 *  - 0 : The session does not exist or could not disconnect from DB.
 *  - 1 : Session closed.
 */
int
A4GLSQL_close_session_internal (char *sessname)
{
  HDBC *ptr;
  int rc;

  ptr = (HDBC *) A4GL_find_pointer_val (sessname, SESSCODE);

#ifdef DEBUG
  A4GL_debug ("Trying to close session %s, pr=%p", sessname, ptr);
#endif

#if ( defined (SQLITEODBC) || defined (SQLITE_DIRECT) )
	//SQLite needs all transactions closed before connection can be ended
    //FIXME: is there a bettr way? SQL_AUTOCOMMIT ? What should we really
    //do if program wants to exit after an error or by reaching EXIT PROGARAM?
	A4GL_debug("commiting all transactions on SQLite...");
	A4GLSQL_commit_rollback (1);
#endif

if (A4GL_isyes(acl_getenv("FORCE_ROLLBACK_AT_EXIT"))) {
	A4GLSQL_commit_rollback (1);
}



  if (ptr == 0)
    {
      A4GL_set_errm (sessname);
      A4GL_exitwith ("Session Id (%s) does not exist");
      return 0;
    }

  rc = SQLDisconnect (*ptr);

  if (rc == 0)
    {
      A4GLSQL_set_status (0, 1);
      free (ptr);
      if (strcmp (sessname, "default") != 0)
	A4GLSQL_set_conn ("default");
    }
  else
    {
      A4GL_exitwith ("Could not disconnect from database");
      return 0;
    }
  return 1;
}


/**
 *
 *
 * @param
 */
void *
A4GL_bind_date (long *ptr_to_date_var)
{
  ACLDATE *ptr;

  ptr = malloc (sizeof (ACLDATE));
#ifdef DEBUG
  A4GL_debug ("Binding date for %p", ptr_to_date_var);
#endif
  ptr->ptr = ptr_to_date_var;
  return (void *) ptr;
}

void * A4GL_bind_datetime (void *ptr_to_dtime_var)
{
  ACLDTIME *ptr;

  ptr = malloc (sizeof (ACLDTIME));
  
#ifdef DTIME_AS_CHAR
	strcpy(ptr->dtime,"");
#else
	ptr->dtime.year=-1;
	ptr->dtime.month=-1;
	ptr->dtime.day=-1;
	ptr->dtime.hour=-1;
	ptr->dtime.minute=-1;
	ptr->dtime.second=-1;
#endif


  ptr->ptr = ptr_to_dtime_var;
  return (void *) ptr;
}

/**
 * Binding processing after fetch.
 *
 * @param use_binding A pointer to the binding structure.
 * @param use_nbind A counter of the number of elements in the binding array.
 * @param hstmt The statement handle.
 */
void
A4GL_post_fetch_proc_bind (struct BINDING *use_binding, int use_nbind, HSTMT hstmt)
{
  int a;
  int zz;
  ACLDATE *date1;
  ACLDTIME *dt1;

#ifdef DEBUG
  A4GL_debug ("In post_fetch_proc_bind...");
#endif

  for (a = 0; a < use_nbind; a++)
    {

#ifdef DEBUG
      A4GL_debug ("Binding type %d ptr=%p %d", use_binding[a].dtype,
	     use_binding[a].ptr, outlen[a + 1]);
#endif


      if (use_binding[a].dtype == DTYPE_CHAR) {
		A4GL_debug("Found string @ %d = '%s'",a,use_binding[a].ptr);
		A4GL_pad_string(use_binding[a].ptr, use_binding[a].size);
      }



      if (outlen[a + 1] == -1)
	{
	  if (use_binding[a].dtype == DTYPE_DATE)
	    {
	      date1 = use_binding[a].ptr;
	      A4GL_setnull (DTYPE_DATE, (char *) date1->ptr, 0);
	      continue;
	    }
	  A4GL_setnull (use_binding[a].dtype, (char *) use_binding[a].ptr,
		   use_binding[a].size);
	  continue;
	}

      if (use_binding[a].dtype == DTYPE_BYTE
	  || use_binding[a].dtype == DTYPE_BYTE)
	{
	  A4GL_get_blob_data (use_binding[a].ptr, hstmt, a);
	  continue;
	}

      if (use_binding[a].dtype == DTYPE_DATE)
	{
#ifdef DEBUG
	  A4GL_debug ("Got a date datatype - better copy the date in properly");
#endif
	  date1 = use_binding[a].ptr;
#ifdef DEBUG
	  A4GL_debug ("Year=%d Month=%d Day=%d", date1->date.year, date1->date.month, date1->date.day);
#endif
	  zz = A4GL_gen_dateno (date1->date.day, date1->date.month, date1->date.year);
	  *((long *) date1->ptr) = zz;
	}
      if (use_binding[a].dtype == DTYPE_DTIME)
	{
		
	char buff[256];
	char buff2[256];
	int s;int e;
	  	dt1 = use_binding[a].ptr;
#ifdef DTIME_AS_CHAR
		strcpy(buff,dt1->dtime);
#else
	strcpy(buff,"");
	s=use_binding[a].size>>4;
	e=use_binding[a].size&0xf;

	if (s>1) dt1->dtime.year=0;
	if (s>2) dt1->dtime.month=0;
	if (s>3) dt1->dtime.day=0;
	if (s>4) dt1->dtime.hour=0;
	if (s>5) dt1->dtime.minute=0;
	if (s>6) dt1->dtime.second=0;

	
	if (strlen(buff)||dt1->dtime.year) { sprintf(buff2,"%04d",dt1->dtime.year); strcat(buff,buff2); }

	if (strlen(buff)||dt1->dtime.month) { 
		if (e>=2) {
			sprintf(buff2,"%02d",dt1->dtime.month); 
			if (strlen(buff)) strcat(buff,"-");
			strcat(buff,buff2); 
		}
	}
	if (strlen(buff)||dt1->dtime.day) { 
		if (e>=3) {
			sprintf(buff2,"%02d",dt1->dtime.day); 
			if (strlen(buff)) strcat(buff,"-");
			strcat(buff,buff2); 
		}
	}
	if (strlen(buff)||dt1->dtime.hour) { 
		if (e>=4) {
			sprintf(buff2,"%02d",dt1->dtime.hour); 
			if (strlen(buff)) strcat(buff," ");
			strcat(buff,buff2); 
		}
	}


	if (strlen(buff)||dt1->dtime.minute) { 
		if (e>=5) {
			sprintf(buff2,"%02d",dt1->dtime.minute); 
			if (strlen(buff)) strcat(buff,":");
			strcat(buff,buff2); 
		}
	}
	if (strlen(buff)||dt1->dtime.second) { 
		if (e>=6) {
			sprintf(buff2,"%02d",dt1->dtime.second); 
			if (strlen(buff)) strcat(buff,":");
			strcat(buff,buff2); 
		}
	}

#endif
		A4GL_push_char(buff);
		A4GL_setnull(DTYPE_DTIME,dt1->ptr,use_binding[a].size);
		A4GL_pop_param(dt1->ptr,DTYPE_DTIME,use_binding[a].size);
	}

	
	if (use_binding[a].dtype == DTYPE_DECIMAL) {
		// We've actually selected into a double...
		double d;
		d=*((double *)use_binding[a].ptr);
		A4GL_debug("DECIMAL from double on db d=%lf",d);
		A4GL_push_double(d);
		A4GL_pop_var2(use_binding[a].ptr,use_binding[a].dtype,use_binding[a].size);
	}



    }

#ifdef DEBUG
  {
    char buffstr[30000] = "Fetch returns :\n";
    char bf[2048];
    for (a = 0; a < use_nbind; a++)
      {
	char *cptr;
	int dtype;


	if (use_binding[a].dtype==DTYPE_CHAR || use_binding[a].dtype==DTYPE_VCHAR || use_binding[a].dtype==DTYPE_DECIMAL ||  use_binding[a].dtype==DTYPE_DTIME ) {
		A4GL_debug("Need to add size to dtype");
	  dtype = use_binding[a].dtype + ENCODE_SIZE (use_binding[a].size);
	} else {
	  dtype = use_binding[a].dtype;
	}



	if (dtype == DTYPE_BYTE || dtype == DTYPE_TEXT)
	  {
	    A4GL_push_char ("<byte>");
	  }
	else
	  {
		if ((dtype&15)==DTYPE_DTIME) {
			A4GL_push_char("<datetime>");
		} else {
	    		A4GL_push_variable (use_binding[a].ptr, dtype);
		}
	  }
	cptr = A4GL_char_pop ();
	sprintf (bf, "%d) %d %d : %s", a, use_binding[a].dtype,
		 (int) use_binding[a].size, cptr);
	if (a > 0)
	  strcat (buffstr, ",\n");
	strcat (buffstr, bf);
	free (cptr);
      }
    strcat (buffstr, "\n");
    A4GL_debug ("use_nbind=%d - %s", use_nbind,buffstr);
  }
#endif
}

/**
 * Implementationin ODBC of the transaction statements (BEGIN WORK,
 * COMMIT WORK, ROLLBACK WORK).
 *
 * @param mode The transaction statement to execute:
 *   - -1 : Begin work
 *   - 0 : Rollback work
 *   - 1 : Commit work
 */
void
A4GLSQL_commit_rollback (int mode)
{
  HSTMT hstmt = 0;
  char *ptr;
  int tmode;

#ifdef DEBUG
  A4GL_debug ("In commit_rollback");
#endif
  ptr = acl_getenv ("TRANSMODE");
  if (strlen (ptr))
    {
      tmode = atoi (ptr);
    }
  else
    {
      tmode = 0;
    }


  if (tmode == 0)
    {
#ifdef DEBUG
      A4GL_debug ("ODBC Transaction Mode:%d ", mode);
#endif
      if (mode == 1)
	SQLTransact (henv, hdbc, SQL_COMMIT);

      if (mode == 0)
	SQLTransact (henv, hdbc, SQL_ROLLBACK);

      A4GL_set_sqlca (SQL_NULL_HSTMT, "Commit/Rollback", 0);
    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("Native Transaction Mode:%d", mode);
#endif
      A4GL_new_hstmt ((SQLHSTMT *)&hstmt);
      if (mode == -1)
	SQLExecDirect (hstmt, "BEGIN WORK", SQL_NTS);

      if (mode == 0)
	SQLExecDirect (hstmt, "ROLLBACK WORK", SQL_NTS);

      if (mode == 1)
	SQLExecDirect (hstmt, "COMMIT WORK", SQL_NTS);

      A4GL_set_sqlca (hstmt, "Commit/Rollback", 0);


      SQLFreeStmt (hstmt, SQL_DROP);
	hstmt=0;
    }

}

/**
 * ODBC implementation of the UNLOAD 4gl statement.
 *
 * @param fname File name where to unload the data.
 * @param delims column separator to use.
 * @param sql1 Sql select text to generate the unload data.
 */
void
A4GLSQL_unload_data_internal (char *fname, char *delims, char *sql1,int nbind, void *vibind)
{
  HSTMT hstmt;
  char *sql2;
  struct BINDING *ibind;
  int cnt = 0;
  static char databuf[64000];
  short ncols;
  char colname[64];
  SWORD colnamelen;
  SWORD coltype[5000];
  int colcnt;
  unsigned long ind;
  UDWORD collen;
  SWORD scale;
  SWORD nullable;
  FILE *fout;
  ibind=vibind;
  fout = A4GL_mja_fopen (fname, "wt");

  if (fout == 0)
    {
      A4GL_exitwith ("Error opening file for unload");
      return;
    }

  if (hdbc == 0)
    {
      A4GL_exitwith ("Not connected to database");
      return;
    }
  A4GL_new_hstmt ((SQLHSTMT *)&hstmt);

  sql2 = strdup (sql1);

  rc = SQLExecDirect (hstmt, sql2, SQL_NTS);
  chk_rc (rc, hstmt, "unload_data");
#ifdef DEBUG
  A4GL_debug ("Executed %s %d", sql2, rc);
#endif

  rc = SQLNumResultCols (hstmt, &ncols);
  chk_rc (rc, hstmt, "unload_data");
  for (colcnt = 1; colcnt <= ncols; colcnt++)
    {

      rc = SQLDescribeCol (hstmt, colcnt, colname,
			   (SWORD) sizeof (colname),
			   &colnamelen, &coltype[colcnt],
			   &collen, &scale, &nullable);
      chk_rc (rc, hstmt, "SQLDescribeCol");
    }
  while (1)
    {
      rc = SQLFetch (hstmt);
      chk_rc (rc, hstmt, "SQLFetch");
      if (rc == SQL_NO_DATA_FOUND)
	break;
      cnt++;
#ifdef DEBUG
      A4GL_debug ("Fetched row");
#endif
      for (colcnt = 1; colcnt <= ncols; colcnt++)
	{

	  rc =
	    SQLGetData (hstmt, (short) colcnt, SQL_CHAR, databuf,
			sizeof (databuf), (SQLINTEGER *) & ind);
	  /*
	     warning: passing arg 6 of `SQLGetData' from incompatible pointer type
	     unsigned long ind;

	     SQLRETURN   SQLGetData(SQLHSTMT StatementHandle,
	     SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType,
	     SQLPOINTER TargetValue, SQLINTEGER BufferLength,
	     SQLINTEGER *StrLen_or_Ind);
	   */

	  chk_rc (rc, hstmt, "SQLGetData");

#ifdef DEBUG
	  A4GL_debug ("Cycling through data %d (%d) ind=%d", colcnt, rc, ind);
#endif

	  if (ind == 0)
	    {
#ifdef DEBUG
	      A4GL_debug ("Null...");
#endif
	      fprintf (fout, "%c", delims[0]);
	    }
	  else
	    {
	      A4GL_trim (databuf);
#ifdef DEBUG
	      A4GL_debug ("Not null %s    datatype : %d", databuf,
		     coltype[colcnt]);
#endif

	      if (strlen (databuf) == 0)
		strcpy (databuf, " ");

	      if (coltype[colcnt] == SQL_DATE)
		{
		  fprintf (fout, "%s%c", A4GL_conv_date (databuf), delims[0]);
		}
	      else
		{
		  fprintf (fout, "%s%c", databuf, delims[0]);
		}
	    }
	}
      fprintf (fout, "\n");
    }

#ifdef DEBUG
  A4GL_debug ("All done...");
#endif
  free (sql2);
  rc = SQLFreeStmt (hstmt, SQL_DROP);
	hstmt=0;
  fclose (fout);
  chk_rc (rc, hstmt, "SQLFreeStmt");
  a4gl_sqlca.sqlerrd[1] = cnt;
}

/**
 * Convert a date to the format setted in DBDATE.
 *
 * @param s The string with the date coming from the database.
 */
char *
A4GL_conv_date (char *s)
{
  static char buff[20];
  static char sbuff[20];
  static char dbdate[20];
  int y, m, d;
  int cnt;
  buff[0] = 0;

  sscanf (s, "%d-%d-%d", &y, &m, &d);
  strcpy (dbdate, A4GL_get_dbdate ());

#ifdef DEBUG
  A4GL_debug ("Scanning... dbdate=%s", dbdate);
#endif

  for (cnt = 0; cnt <= 2; cnt++)
    {

      if (dbdate[cnt] == 'y' || dbdate[cnt] == 'Y')
	{
	  sprintf (sbuff, "%04d", y);
	  strcat (buff, sbuff);
	}

      if (dbdate[cnt] == 'm' || dbdate[cnt] == 'M')
	{
	  sprintf (sbuff, "%02d", m);
	  strcat (buff, sbuff);
	}

      if (dbdate[cnt] == 'd' || dbdate[cnt] == 'D')
	{
	  sprintf (sbuff, "%02d", d);
	  strcat (buff, sbuff);
	}

      if (cnt != 2)
	{

	  if (dbdate[4] != 0)
	    sprintf (sbuff, "%c", dbdate[4]);
	  else
	    sprintf (sbuff, "/");

	  strcat (buff, sbuff);
	}

    }
  return buff;
}

/**
 * Decode a return call from the integer defined value to a string.
 *
 * @param a The integer value to be decoded.
 * @return The value converted to string
 */
char *
A4GL_decode_rc (int a)
{
  switch (a)
    {
    case SQL_SUCCESS:
      return "SQL_SUCCESS";
    case SQL_ERROR:
      return "SQL_ERROR";
    case SQL_INVALID_HANDLE:
      return "SQL_INVALID_HANDLE";
    case SQL_SUCCESS_WITH_INFO:
      return "SQL_SUCCESS_WITH_INFO";
    case SQL_NO_DATA_FOUND:
      return "SQL_NO_DATA_FOUND";
    }
  return "Unknown";
}

#ifndef DONTINCLUDEDATASOURCES
RETCODE SQL_API
SQLDataSources (HENV henv, UWORD fDirection,
		UCHAR FAR * szDSN, SWORD cbDSNMax, SWORD FAR * pcbDSN,
		UCHAR FAR * szDescription, SWORD cbDescriptionMax,
		SWORD FAR * pcbDescription)
{
  return -1;
}
#endif

/**
 *
 * @param rc 
 * @param hstmt The statement handle.
 * @return
 */
int
A4GL_chk_need_blob (int rc, HSTMT hstmt)
{
#ifdef DEBUG
  A4GL_debug ("In A4GL_chk_need_blob rc=%d", rc);
#endif
  if (rc != SQL_NEED_DATA)
    return rc;
#ifdef DEBUG
  A4GL_debug ("Need data for %p", hstmt);
#endif
  return A4GL_set_blob_data (hstmt);
}

/**
 * Assign the sqlca.sqlcode with a value
 *
 * @param a The value to be assigned.
 */
void
A4GLSQL_set_sqlca_sqlcode (int a)
{
  a4gl_status = a;
  a4gl_sqlca.sqlcode = a;
}

/**
 * Check if a environment variable is set (true/false).
 *
 * @param A string containing the environment variable.
 * @param a
 * @return
 *   - TRUE : The variable is set and have YyTt
 *   - FALSE  Otherwise.
 */
int
A4GL_chk_getenv (char *s, int a)
{
  char *p;
  p = acl_getenv (s);
  if (p == 0 && a == 0)
    return TRUE;
  if (p == 0 && a != 0)
    return FALSE;

#ifdef DEBUG
  A4GL_debug ("Checking %s (%s) for %d", s, p, a);
#endif

  if (p[0] == 'Y' || p[0] == 'y' || p[0] == 'T' || p[0] == 't')
    {
      if (a == TRUE)
	return TRUE;
    }
  if (p[0] == 'N' || p[0] == 'n' || p[0] == 'F' || p[0] == 'f')
    {
      if (a == TRUE)
	return FALSE;
      else
	return TRUE;
    }
  return FALSE;
}

/**
 * PUT statement for cursors for insert.
 * Not implemented.
 *
 * @param ibind The input bin array.
 * @param n 
 */
void
A4GLSQL_put_insert ( void *vibind, int n)
{
struct BINDING *ibind;
char *cursorName;
  struct s_cid *cid;
  struct s_sid *sid;
int ni;
ibind=vibind;


  cursorName = A4GL_char_pop ();
  cid = A4GLSQL_find_cursor (cursorName);
	free(cursorName);
  if (cid==0) return;
	A4GL_debug("Which Bind ? %p %d, %p %d",vibind,n,cid->statement->ibind,cid->statement->ni);
  if (n) {
	ibind=vibind;
	ni=n;
  } else {
        ni=cid->statement->ni;
        ibind=cid->statement->ibind;
  }
  sid=cid->statement;
  A4GL_proc_bind (ibind, ni, 'i', (SQLHSTMT)sid->hstmt);
  return ODBC_exec_prepared_sql ((SQLHSTMT)sid->hstmt);

}

/**
 * FLUSH CURSOR 4gl statement implementation.
 * Not implemented in ODBC.
 *
 * @param The cursor name.
 */
void
A4GLSQL_flush_cursor (char *cursor)
{
#ifdef DEBUG
  A4GL_debug ("Not implemented A4GLSQL_flush_cursor");
#endif
  A4GL_exitwith ("Not implemented A4GLSQL_flush_cursor");
}

/**
 * Initialization of the sql dynamic library.
 *
 * Used to initialise SQL library, ater loading it with dlopen,
 * called from fglwrap.c
 */
int
A4GLSQL_initsqllib (void)
{
  A4GLSQL_make_connection (0, 0, 0);
  return 1;
}

char *A4GLSQL_syscolval_expr(char *tabname,char *colname,char *typ) {
	return 0;
}

struct expr_str *A4GL_add_validation_elements_to_expr(struct expr_str *ptr,char *val) {
char *ptr2;
char *ptrn;
char buff[256];
A4GL_trim(val);
ptr2=val;
while (1) {
        ptrn=strtok(ptr2,",");
        if (ptrn==0) break;
        if (ptr2) {ptr2=0;}

        sprintf(buff,"A4GL_push_char(\"%s\");",ptrn);

        if (ptr==0) {
                ptr=A4GL_new_expr(buff);
        } else {
                A4GL_append_expr(ptr,buff);
        }

}
return ptr;
}


void *A4GLSQL_get_validation_expr(char *tabname,char *colname) {
char buff[300];
sprintf(buff, "select attrval from %s where attrname='INCLUDE' and tabname='%s' and colname='%s'", acl_getenv("A4GL_SYSCOL_VAL"),tabname,colname);

printf("Warning Validation feature not implemented in ODBC SQL Driver\n");
return 0;
}





/* =================================================== */
/* Folowing code examples taken from sqliteodbc.c file */
/* =================================================== */

#ifdef EXAMPLE

//FIXME: we need to be able to read odbc.ini directly to get at least
// username and password

#if defined(WITHOUT_DRIVERMGR) || !defined(_WIN32)

/**
 * Handling of SQLConnect() connection attributes
 * for standalone operation without driver manager.
 * Extracts requested parameter value from connect string.
 * @param dsn DSN/driver connection string
 * @param attr attribute string to be retrieved
 * @param out output buffer
 * @param outLen length of output buffer
 * @result true or false
 */

static int
A4GL_getdsnattr(char *dsn, char *attr, char *out, int outLen)
{
char *str = dsn, *start;
int len = strlen(attr);

    while (*str) {
		while (*str && *str == ';') {
		    ++str;
		}
		start = str;
		if ((str = strchr(str, '=')) == NULL) {
		    return 0;
		}
		if (str - start == len &&
			#ifdef _WIN32
		    _strnicmp(start, attr, len) == 0
			#else
		    strncasecmp(start, attr, len) == 0
			#endif
		   ) {
		    start = ++str;
		    while (*str && *str != ';') {
				++str;
		    }
		    len = min(outLen - 1, str - start);
		    strncpy(out, start, len);
		    out[len] = '\0';
		    return 1;
		}
		while (*str && *str != ';') {
		    ++str;
		}
    }
    return 0;
}
#endif

#if defined(WITHOUT_DRIVERMGR) || defined(_WIN32)

/**
 * Get datasource attributes from registry.
 * @param setupdlg pointer to dialog data
 */

static void
GetAttributes(SETUPDLG *setupdlg)
{
    char *dsn = setupdlg->attr[KEY_DSN].attr;

    if (!setupdlg->attr[KEY_DESC].supplied) {
	SQLGetPrivateProfileString(dsn, "Description", "",
				   setupdlg->attr[KEY_DESC].attr,
				   sizeof (setupdlg->attr[KEY_DESC].attr),
				   ODBC_INI);
    }
    if (!setupdlg->attr[KEY_DBNAME].supplied) {
	SQLGetPrivateProfileString(dsn, "Database", "",
				   setupdlg->attr[KEY_DBNAME].attr,
				   sizeof (setupdlg->attr[KEY_DBNAME].attr),
				   ODBC_INI);
    }
    if (!setupdlg->attr[KEY_BUSY].supplied) {
	SQLGetPrivateProfileString(dsn, "Timeout", "1000",
				   setupdlg->attr[KEY_BUSY].attr,
				   sizeof (setupdlg->attr[KEY_BUSY].attr),
				   ODBC_INI);
    }
    if (!setupdlg->attr[KEY_NOWCHAR].supplied) {
	SQLGetPrivateProfileString(dsn, "NoWCHAR", "",
				   setupdlg->attr[KEY_NOWCHAR].attr,
				   sizeof (setupdlg->attr[KEY_NOWCHAR].attr),
				   ODBC_INI);
    }
#ifdef ASYNC
    if (!setupdlg->attr[KEY_THR].supplied) {
	SQLGetPrivateProfileString(dsn, "Threaded", "1",
				   setupdlg->attr[KEY_THR].attr,
				   sizeof (setupdlg->attr[KEY_THR].attr),
				   ODBC_INI);
    }
#endif
}

#endif

/**
 * Internal connect to database.
 * @param dbc database connection handle
 * @param dsn DSN string
 * @param dsnLen length of DSN string or SQL_NTS
 * @result ODBC error code
 */

static SQLRETURN
example_drvconnect(SQLHDBC dbc, SQLCHAR *dsn, SQLSMALLINT dsnLen)
{
DBC *d;
int len;
char buf[SQL_MAX_MESSAGE_LENGTH], dbname[SQL_MAX_MESSAGE_LENGTH / 4];
char busy[SQL_MAX_MESSAGE_LENGTH / 4];
char tflag[32], nwflag[32];


//Test parameters we got:
	if (dbc == SQL_NULL_HDBC) {
		return SQL_INVALID_HANDLE;
    }
    d = (DBC *) dbc;
    if (d->magic != DBC_MAGIC) {
		return SQL_INVALID_HANDLE;
    }
    if (d->sqlite != NULL) {
		setstatd(d, "connection already established", "08002");
		return SQL_ERROR;
    }
    buf[0] = '\0';
    if (dsnLen == SQL_NTS) {
		len = sizeof (buf) - 1;
    } else {
		len = min(sizeof (buf) - 1, dsnLen);
    }
    if (dsn != NULL) {
		strncpy(buf, dsn, len);
    }
    buf[len] = '\0';
    if (buf[0] == '\0') {
		setstatd(d, "invalid DSN", "S1090");
		return SQL_ERROR;
    }
    busy[0] = '\0';
    dbname[0] = '\0';
#ifdef WITHOUT_DRIVERMGR
//get info from odbc.ini using our own read function
	A4GL_getdsnattr(buf, "database", dbname, sizeof (dbname));
    if (dbname[0] == '\0') {
		strncpy(dbname, buf, sizeof (dbname));
		dbname[sizeof (dbname) - 1] = '\0';
    }
    A4GL_getdsnattr(buf, "timeout", busy, sizeof (busy));
    tflag[0] = '\0';
    nwflag[0] = '\0';
	#ifdef ASYNC
	    A4GL_getdsnattr(buf, "threaded", tflag, sizeof (tflag));
	#endif
    A4GL_getdsnattr(buf, "nowchar", nwflag, sizeof (nwflag));
#else
//get info from odbc.ini using driver manager function calls:
	SQLGetPrivateProfileString(buf, "timeout", "1000",
			       busy, sizeof (busy), ODBC_INI);
    SQLGetPrivateProfileString(buf, "database", "",
			       dbname, sizeof (dbname), ODBC_INI);
	#ifdef ASYNC
	    SQLGetPrivateProfileString(buf, "threaded", "",
				       tflag, sizeof (tflag), ODBC_INI);
	#endif
    SQLGetPrivateProfileString(buf, "nowchar", "",
			       nwflag, sizeof (nwflag), ODBC_INI);
#endif

	//Now we can connect:
	//d->nowchar = getbool(nwflag);
    //return dbopen(d, dbname, dsn, tflag, busy);
}


#endif //ifdef EXAMPLE

/* ================================ EOF ================================ */
