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
# $Id: sql.c,v 1.51 2003-02-16 04:25:42 afalout Exp $
#
*/

/**
 * @file
 * ODBC Sql execution implementation
 *
 * @todo Doxygen comments to add to functions
 */


/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_lib_sql_odbc_int.h"

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#ifndef TRUE
	#define TRUE 1
#endif
#ifndef FALSE
	#define FALSE 0
#endif

#define FETCH_ABSOLUTE 	1
#define FETCH_RELATIVE 	2
#define DTYPE_DATE 		7
#define chk_rc(rc,stmt,call) chk_rc_full(rc,(void *)stmt,call,__LINE__,__FILE__)
#define exitwith 		exitwith_sql
#define MAXCURSORS 		100
#define MAXPREPARE 		100
#define MAXCOLS 		100
#define max(a,b) (a>b?a:b)
#define MAX_NUM_PRECISION 15

/**
 * Define max length of char string representation of
 * number as: = max(precision) + leading sign + E +
 * exp sign + max exp length
 * =  15 + 1 + 1 + 1 + 2
 * =  15 + 5
 */
#define MAX_NUM_STRING_SIZE (MAX_NUM_PRECISION + 5)
#define strlen(a) (strlen((char *)a))
#define fgl_size(a,b) (fgl_sizes[a]==-1?b+1:fgl_sizes[a])
/* #define fgl_size(a,b) (fgl_sizes[a]==-1?b:fgl_sizes[a]) */

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

/*
getlogin not available in mingw see syscalls.c.x

#ifdef __MINGW32__
	extern char *getlogin (void);
#endif
*/

struct s_cid *	A4GLSQL_find_cursor (char *cname);
struct s_cid * 	A4GLSQL_free_cursor (char *cname);

char *			conv_date		(char *s);
int 			find_prepare2 	(char *pname);
struct s_sid *	find_prepare 	(char *pname);
int 			find_cursor_for_decl (char *cname);
int 			proc_bind 		(struct BINDING *b, int n, char t, HSTMT hstmt);
void 			ibind_column_arr (int pos, char *s, HSTMT hstmt);
void *			bind_date 		(long *ptr_to_date_var);
void 			ibind_column 	(int pos, struct BINDING *bind, HSTMT hstmt);
void 			obind_column 	(int pos, struct BINDING *bind, HSTMT hstmt);
void 			post_fetch_proc_bind (struct BINDING *use_binding, int use_nbind,HSTMT hstmt);
void 			add_cursor 		(struct s_cid *cid, char *cname);
int 			ODBC_exec_prepared_sql	(HSTMT hstmt);
int 			ODBC_exec_stmt		(HSTMT hstmt);
int 			ODBC_exec_select	(HSTMT hstmt);
int 			ODBC_exec_sql		(UCHAR * sqlstr);
int 			ODBC_disconnect		(void);
void			ODBC_set_dbms_info	(void);
int 			sqlerrwith 		(int rc, HSTMT h);
int 			chk_need_blob	(int rc,HSTMT hstmt)  ;
int 			chk_getenv		(char *s,int a) ;
static int 		conv_sqldtype 	(int sqldtype, int sdim);
char *			decode_rc		(int a);
RETCODE SQL_API newSQLSetParam 	(HSTMT hstmt, UWORD ipar, SWORD fCType,
     							SWORD fSqlType, UDWORD cbColDef, SWORD ibScale, PTR rgbValue,
      				 			SDWORD FAR * pcbValue);
char* 			ret_sql_err 	(void);
int 			print_err 		(HDBC hdbc, HSTMT hstmt);
long 			describecolumn (HSTMT hstmt, int colno, int type);
int 			set_stmt_options (char *cursname, char *opt, char *val);

#ifndef DONTINCLUDEDATASOURCES
	#ifdef PGODBC
		RETCODE SQL_API SQLDataSources (HENV henv, UWORD fDirection,
		    UCHAR FAR * szDSN, SWORD cbDSNMax, SWORD FAR * pcbDSN,
		    UCHAR FAR * szDescription, SWORD cbDescriptionMax,
		    SWORD FAR * pcbDescription);
    #endif
#endif

/* in sqlex.c */
extern int 		set_blob_data	(HSTMT hstmt);
extern int 		get_blob_data 	(struct fgl_int_loc *blob, HSTMT hstmt, int colno);

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

/* extern: */
extern char 	lasterrorstr[1024];

/* static: */
static char 	sess_name[32] = "default";
static char 	OldDBname[64] = "";
static char	dbms_name[64] = "";
static char	dbms_dialect[64] = "";
static HSTMT 	hstmtGetColumns = 0; 	/** Statement used to iterate getting column information */
static char 	cn[256]; 				/** Column name */
static int 		dt;
static long 	prec; 					/** Precision */
static int 		colsize;					/** Coulmn size */
static char 	szcolsize[20];

/* unknown: */
int 			rc;
int 			do_init_cursors = 1;
int 			do_init_prepare = 1;
char 			buffer[256];
HENV 			henv = 0;
HDBC 			hdbc = 0;		/** The database connection handle */
SDWORD 			outlen[512];

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


/**
 * Conversion table between 4gl and C data types.
 */
int conv_4gl_to_c[] =
{
  SQL_C_CHAR,
  SQL_C_SHORT,
  SQL_C_LONG,
  SQL_C_DOUBLE,
  SQL_C_FLOAT,
  SQL_C_DOUBLE,			/* decimal != double  need to change this */
  SQL_C_LONG,
  SQL_C_DATE,
  SQL_C_DOUBLE,			/* as for decimal money != double */
  9999,
  SQL_C_TIMESTAMP,
  SQL_C_BINARY,
  SQL_C_BINARY,
  SQL_C_CHAR,
  SQL_C_TIME
};

/**
 * Table of 4gl sizes.
 */
int fgl_sizes[] =
{
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
int convpos_sql_to_4gl[15] =
{
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
int convneg_sql_to_4gl[15] =
{
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

#if (defined(WIN32) && ! defined(__CYWIN__)) /* && defined DLL_EXPORT */

	dll_export sqlca_struct sqlca;
	dll_export int status;

	#include <windows.h>
	int WINAPI

	libSQL_odbc32_init(HANDLE h, DWORD reason, void *foo)
	{
	  return 1;
	}

	char
	libSQL_odbc32_is_dll (void)
	{
	  return 1;
	}
#endif /* WIN32 && DLL_EXPORT */


dll_import sqlca_struct sqlca;


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

  status = a;
  if (sql)
    sqlca.sqlcode = a;
  debug ("Status set to %d", a);
}


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
chk_rc_full (int rc, void *hstmt, char *c, int line, char *file)
{
  debug ("Chk_rc_full : rc=%d (%s) stmt=%p c=%s line=%d file=%s", rc,
            decode_rc(rc), hstmt, c, line, file);

  if (rc==SQL_SUCCESS) {
     A4GLSQL_set_status(0,1);
     return;
  }


	if (hstmt)
	{
	  if (rc == SQL_NO_DATA_FOUND)
    	{
	      A4GLSQL_set_sqlca_sqlcode(100);
    	  /* set_sqlca (hstmt, c, 0,0 ); */ /* no error */
	      A4GLSQL_set_status (100, 1);
    	  return;
	    }
	  set_sqlca (hstmt, c, 0);
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
newSQLSetParam (HSTMT hstmt, UWORD ipar, SWORD fCType,
      SWORD fSqlType, UDWORD cbColDef, SWORD ibScale, PTR rgbValue,
      SDWORD FAR * pcbValue)
{
int rc;
static SDWORD cbval;

	debug("Setting parameter %d to type %d (%d) %d (%d)",ipar,fSqlType,SQL_C_BINARY,fCType,SQL_PARAM_INPUT);

	if (fCType==SQL_C_BINARY)
	{
		debug("Setting blob data");
		cbval=0;
		rc=SQLBindParameter(hstmt, ipar, SQL_PARAM_INPUT, SQL_C_BINARY, SQL_LONGVARBINARY, 0, 0, rgbValue, 0, &cbval);
		cbval=SQL_LEN_DATA_AT_EXEC(64000);
	   	chk_rc(rc,hstmt,"SQLBindParameter");
		return rc;
	}

	rc= SQLBindParameter (hstmt,ipar, SQL_PARAM_INPUT,
	    fCType, fSqlType, cbColDef, ibScale, rgbValue,
	    3200 ,pcbValue);

   chk_rc(rc,hstmt,"SQLBindParameter");

	debug("cbval was set to %d after call",cbval);

	debug("All done returning rc=%d\n",rc);
	return rc;
}

/**
 * Count the number of ? parameter placeholders in a query string.
 *
 * @param s A string with the query.
 * @return The number of ? found in the query.
 */
static int 
count_queries(char *s)
{
  char *ptr;
  int cnt=0;
  char quote=0;
  int slash=0;
  /* count only the unquoted ?'s, ie. those that are not within
   * single/double quote strings or preceded by a backslash 
   */
  for (ptr=s; ptr && *ptr > 0; ptr++) {
    if (slash) {
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
        if (quote == *ptr) {
            quote = 0;
	}
	else {
           if (quote == 0) {
               quote = *ptr;
	   }
	}
      break;
    case '?':
      if (quote == 0) cnt++;
      break;
    }
  }
  debug("count_queries() found %d ?'s in string %s",cnt,s);
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
proc_bind (struct BINDING *b, int n, char t, HSTMT hstmt)
{
  int a;
  SWORD nin;
  if (b == 0)
    return 0;
#ifdef DEBUG 
	/* {DEBUG} */ {debug ("In proc_bind...");}
	/* {DEBUG} */ { debug ("   Binding %p n=%d t=%c, stmt=%p", b, n, t, hstmt); }
#endif
  if (t == 'i')
    {
      rc = SQLNumParams (hstmt, &nin);
      chk_rc (rc, hstmt, "SQLNumParams");

      /* set_sqlca (hstmt, "proc_bind, after NumParams",0); */
#ifdef DEBUG
	/* {DEBUG} */ { debug ("Found %d parameters are required...", nin); }
#endif

      if (n != nin)
	{
#ifdef DEBUG
	/* {DEBUG} */ { debug ("Number of host variables does not match %d (given) !=%d (in sql)", n, nin); }
#endif
	  return 0;
	}

#ifdef DEBUG
	/* {DEBUG} */ { debug ("Looks like we have the right number.."); }
#endif
    }
  for (a = 1; a <= n; a++)
    {
#ifdef DEBUG
	/* {DEBUG} */ { debug ("Binding parameter %d ", a); }
#endif

      if (t == 'o')
	{
	  obind_column (a, &b[a - 1], hstmt);
	}
      else
	{

	  ibind_column (a, &b[a - 1], hstmt);
	}

#ifdef DEBUG
	/* {DEBUG} */ {debug ("DOne...");}
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
  ptr = (struct s_cid *) find_pointer_val (cname, CURCODE);
  if (ptr)
    return ptr;
  exitwith ("Cursor not found");
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
find_cursor_for_decl (char *cname)
{
  if (find_pointer_val (cname, CURCODE))
    return 1;
  else
    return 0;
}

/**
 * Prepare an sql statement.
 *
 * @param s A string with the sql statement to be prepared.
 * @return A pointer to the statement information structure.
 */
struct s_sid *
A4GLSQL_prepare_sql (char *s)
{
 struct s_sid *sid;
 int rc;

  debug ("prepare_sql : %s", s);
  sid = malloc (sizeof (struct s_sid));
  debug ("Malloced sid=%p", sid);
  sid->select = strdup (s);
  debug ("Set select");
  sid->ibind = 0;
  sid->ni =  count_queries(s);
  sid->obind = 0;
  sid->no = 0;

	#ifdef DEBUG
	{ debug ("Before alloc sid->hstmt=%p", sid->hstmt); }
	#endif

	if (new_hstmt (&sid->hstmt)) /* warning: passing arg 1 of `new_hstmt' from incompatible pointer type */
	{
		#ifdef DEBUG
		{debug ("after alloc sid->hstmt=%p", sid->hstmt);}
		#endif
		rc = SQLPrepare ( sid->hstmt, sid->select, SQL_NTS);
		chk_rc (rc, sid->hstmt, "SQLPrepare");

		#ifdef DEBUG
		{debug ("Rc set to %d", rc);}
		#endif
		/* set_sqlca (sid->hstmt, "Prepare_sql : after SQLPrepare", 0); */
		return sid;
    }
	else
    {
		/* set_sqlca (sid->hstmt, "Prepare_sql : after SQLPrepare", 0); */
		A4GLSQL_set_status(0,1);
		return 0;
    }
}


/**
 * Find a statement prepared in the pointer tree.
 *
 * @param pname The statement name.
 * @param mode Not used.
 * @return A pointer to the statement strucuture, 0 otherwise.
 */
struct s_sid *
A4GLSQL_find_prepare (char *pname)
{
  struct s_sid *ptr;
  debug ("chk %s was prepared", pname);
  set_errm (pname);
  ptr = find_pointer_val (pname, PRECODE);
  if (ptr)
    return ptr;
  return (struct s_sid *)0;
}

/**
 * Execute an SQL statement.
 *
 * @param pname  The prepared statement name.
 * @param ni Number of elements in the input bind.
 * @param ibind The input binding array used.
 * @return
 */
int 
A4GLSQL_execute_sql (char *pname, int ni, struct BINDING * ibind)
{
struct s_sid *sid;
  
  debug ("execute_sql");
  sid = A4GLSQL_find_prepare (pname); //,1
  set_errm ("");

  if (sid==0) {
	exitwith("Can't execute unprepared statement");
	return 0;
  }
#ifdef DEBUG
	{ debug (" prepare statement - Sid=%p ", sid); }
#endif
#ifdef DEBUG
	{ debug ("Binding any data... ni=%d hstmt=%p", ni, sid->hstmt); }
#endif
  proc_bind (ibind, ni, 'i',  sid->hstmt);
#ifdef DEBUG
	{ debug ("Bound any data... ni=%d", ni); }
#endif
  return ODBC_exec_prepared_sql (sid->hstmt);
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
struct s_sid *
A4GLSQL_prepare_select (
      struct BINDING *ibind, int ni, struct BINDING *obind, int no, char *s)
{
  struct s_sid *sid;
  int rc;
  sid = malloc (sizeof (struct s_sid));
  sid->select = strdup (s);
  sid->ibind = ibind;
  debug ("sid->ni=%d", ni);
  sid->ni = ni;
  sid->obind = obind;
  sid->no = no;

#ifdef DEBUG
	/* {DEBUG} */ {debug ("Before alloc sid->hstmt=%p", sid->hstmt);}
#endif

  A4GLSQL_set_status (0, 1);

  if (new_hstmt (&sid->hstmt))
    {
#ifdef DEBUG
	/* {DEBUG} */{debug ("after alloc sid->hstmt=%p", sid->hstmt);}
#endif
	debug("statement = %s",sid->select);
      rc = SQLPrepare ( sid->hstmt, sid->select, SQL_NTS);
      chk_rc (rc, sid->hstmt, "SQLPrepare");
      /* set_sqlca (sid->hstmt, "Prepare_select : After Prepare", 0); */
      debug ("Prepared '%s'\n", s);
      if (sqlca.sqlcode < 0) {
        debug("Returning 0");
	return 0;
      }
      debug("Returning %p",sid);
      return sid;
    }
  else
    {
      /* not an sql error */
      if (status == 0)
	exitwith ("Memory Allocation Error");
      debug ("Some error generating hstmt");
      return 0;
    }

  return 0;
}

/**
 * Prepare a global SQL statement
 *
 * @param s The SQL statement text.
 * @param ni The number of variables to bind.
 * @param ibind The input bind
 * @return A pointer to an SQL statement information strucutre.
 */
struct s_sid *
A4GLSQL_prepare_glob_sql (char *s, int ni, struct BINDING *ibind)
{
  struct s_sid *sid;
  debug ("prepare_glob_sql '%s' %p %d", s, ibind, ni);
  sid = malloc (sizeof (struct s_sid));
  sid->select = strdup (s);
  sid->ibind = ibind;

#ifdef DEBUG
	/* {DEBUG} */ { debug ("ni=%d ibind=%p", ni, ibind); }
#endif
  sid->ni = ni;

  sid->obind = 0;
  sid->no = 0;

#ifdef DEBUG
	/* {DEBUG} */ { debug ("Hdbc=%p ni=%d", hdbc, sid->ni); }
#endif

  if (new_hstmt (&sid->hstmt))
    {
#ifdef DEBUG
	/* {DEBUG} */ { debug ("after alloc sid->hstmt=%p", sid->hstmt); }
#endif
	debug("Preparing %p %s\n",sid->hstmt,sid->select);
      rc = SQLPrepare ( sid->hstmt, sid->select, SQL_NTS);
	  chk_rc (rc, sid->hstmt, "SQLPrepare");
      /* set_sqlca (sid->hstmt, "Prepare_glob_sql : After Prepare", 0); */
      if (sqlca.sqlcode>=0) {
      debug ("Prepared %s as %p\n", s, sid->hstmt);
      return sid;
	} else {return 0;}
    }
  else
    {
      return 0;
    }
}

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
struct s_cid *
A4GLSQL_declare_cursor(int upd_hold,struct s_sid *sid,int scroll,char *cursname)
{
struct s_sid *nsid;
struct s_cid *cid;

  if (sid == 0)
    {
      exitwith ("Can't declare cursor for non-prepared statement");
      return 0;
    }
  debug ("Declaring cursor");
#ifdef DEBUG
	/* {DEBUG} */ { debug ("upd_hold=%d sid=%p scroll=%d cursname=%s", upd_hold, sid, scroll, cursname); }
#endif

  cid = malloc (sizeof (struct s_cid));

  nsid = malloc (sizeof (struct s_sid));
  debug ("Malloced nsid & cid");
#ifdef DEBUG
	/* {DEBUG} */ {debug ("sid=%p", sid); }
#endif
  cid->statement = nsid;
  cid->hstmt = 0;
  cid->mode = upd_hold + scroll * 256;
  nsid->ibind = sid->ibind;
  nsid->hstmt = sid->hstmt;
  nsid->ni = sid->ni;
  debug ("nsid->ni=%d", nsid->ni);
  nsid->obind = sid->obind;
  nsid->no = sid->no;
  nsid->select = sid->select;
  debug ("Adding cursor %s", cursname);
  add_cursor (cid, cursname);
  debug ("Added cursor");
  debug ("cid->statement->ni=%d", cid->statement->ni);
  debug ("cid->statement=%p", cid->statement);
  debug ("cid->statement->ibind=%p", cid->statement->ibind);
  new_hstmt (&nsid->hstmt);
  debug("Got statement");
  if (scroll) {
	debug("Setting dynamic cursor");
	rc=SQLSetStmtOption(&nsid->hstmt,SQL_CURSOR_TYPE,SQL_CURSOR_STATIC);
        chk_rc (rc, nsid->hstmt, "SQLSetScrollOption SCROLL_STATIC");
printf(" rc = %d\n", rc);
  }
  debug("Returning %p",cid);
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
A4GLSQL_execute_implicit_sql (struct s_sid *sid)
{
 int rc=0;

  if (sid == 0)
    {
#ifdef DEBUG
    /* {DEBUG} */ {debug("A4GLSQL_execute_implicit_sql: internal error sid=0");}
#endif
      return 0;
    }
#ifdef DEBUG
    /* {DEBUG} */ {debug("A4GLSQL_execute_implicit_sql: no=%d ni=%d sql=%s",
                          sid->no, sid->ni, sid->select);}
    /* {DEBUG} */ {debug("Calling proc_bind()");}
#endif

  proc_bind (sid->obind, sid->no, 'o',  sid->hstmt);
  proc_bind (sid->ibind, sid->ni, 'i',  sid->hstmt);

#ifdef DEBUG
    /* {DEBUG} */ {debug("Calling ODBC_exec_stmt()");}
#endif

  rc = ODBC_exec_stmt (sid->hstmt);

  /* free up malloc'ed memory */
  SQLFreeStmt (sid->hstmt, SQL_DROP);
  free (sid->select);
  free (sid);

  return(rc);
}

/**
 * Execute an implicit select instruction.
 *
 * Used when the SELECT is a direct SELECT INTO in 4gl code.
 *
 * @param sid The statement information.
 */
int
A4GLSQL_execute_implicit_select (struct s_sid *sid)
{
  int a;

  if (sid == 0)
    {
      debug("A4GLSQL_execute_implicit_select got sid == 0, returning -1");
      return -1;
    }
  debug ("Executing immediate : %s", sid->select);
  proc_bind (sid->obind, sid->no, 'o',  sid->hstmt);
  proc_bind (sid->ibind, sid->ni, 'i',  sid->hstmt);
#ifdef DEBUG
    /* {DEBUG} */ { debug (" Bound data ... ni=%d no=%d", sid->ni, sid->no);}
#endif
  a = ODBC_exec_select ( sid->hstmt);
  if (a) post_fetch_proc_bind (sid->obind, sid->no,&sid->hstmt);

  /* free up malloc'ed memory */
  SQLFreeStmt (sid->hstmt, SQL_DROP);
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
A4GLSQL_open_cursor (int ni, char *s)
{

  struct s_cid *cid;
  char *curs;
  unsigned long rowcount;
  int rc;

  debug ("Checking cursor %s exists before opening", s);

  cid = A4GLSQL_find_cursor (s);

  if (cid == 0)
    {
      return 0;
    }

  if (cid->hstmt != 0) {

	A4GLSQL_close_cursor(s);

        /*
        exitwith ("Cursor already open");
        return;
        */
    }

  rc = SQLPrepare ( cid->statement->hstmt, cid->statement->select, SQL_NTS);
  chk_rc (rc, cid->statement->hstmt, "SQLPrepare");
  debug ("cid=%p %s", cid, s);
  debug ("cid->statement=%p", cid->statement);
  debug ("cid->statement->ibind=%p", cid->statement->ibind);
  debug ("cid->statement->ni=%d", cid->statement->ni);

  if (((cid->statement->ni) != ni) && ni > 0)
    {
      debug ("Too many or too few host variables ni=%d no expected=%d", ni, cid->statement->ni);
      exitwith ("Too many or too few host variables");
      return 0;
    }
  debug ("Host variables OK");

  curs = cid->statement->select;
  status=0;
  if (ni==0) { /* No USING on the open.. */
  	proc_bind (cid->statement->ibind, cid->statement->ni, 'i',  cid->statement->hstmt);

  } else {
	struct BINDING *b;
	int a;
	debug("We dont have a binding - but I'll make one");
	b=malloc(sizeof(struct BINDING)*ni);

	for  (a=ni-1;a>=0;a--) {
		b[a].ptr=char_pop();
		debug("Got string as '%s' a=%d\n",b[a].ptr,a);
		b[a].dtype=0;
		b[a].size=strlen(b[a].ptr);
		debug("Got size as '%d' a=%d\n",b[a].size,a);
	}

	for  (a=0;a<ni;a++) {
		debug ("%d %d %s",b[a].dtype,b[a].size,b[a].ptr);
	}

  	proc_bind (b, ni, 'i',  cid->statement->hstmt);

  }


  if (status!=0)  {
	return 0;
  }

  debug ("Executing statement %s\n", curs);
  debug ("cid=%p cid->hstmt=%p", cid, cid->hstmt);

  if (cid->hstmt != 0)
    {
      exitwith ("Cursor already open");
      return 0;
    }
  else
    {
      cid->hstmt =  cid->statement->hstmt;
    }
  /* Execute the SQL statement. */
   debug("Setting cursor type");


  debug ("Opening cursor %p", cid->statement->hstmt);


  rc = SQLExecute ( cid->statement->hstmt);
  rc=chk_need_blob(rc,&cid->statement->hstmt);
  chk_rc (rc, cid->statement->hstmt, "SQLExecute");

  debug ("Executed...");
#ifdef DEBUG
	/* {DEBUG} */ {debug ("Open Cursor hstmt=%p", cid->statement->hstmt);}
#endif

#ifdef DEBUG
	/* {DEBUG} */ {debug ("OBind..."); }
#endif
  proc_bind (cid->statement->obind, cid->statement->no, 'o',
		  cid->statement->hstmt);
#ifdef DEBUG
	/* {DEBUG} */ {debug ("IBind...");}
#endif
  debug ("After open cursor");

  /* set_sqlca (cid->statement->hstmt, "Open Cursor", 1); */
  if (rc != SQL_SUCCESS)
    {
      return sqlerrwith (rc, &cid->statement->hstmt);
    }
  A4GLSQL_set_status (0, 1);
  rc = SQLRowCount ( cid->statement->hstmt,(SQLINTEGER*) &rowcount);

  /* chk_rc (rc, cid->statement->hstmt, "SQLRowCount"); */
  sqlca.sqlerrd[1] = rowcount;
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
	  int fetch_mode, int fetch_when, int nibind, struct BINDING * ibind)
{

  struct s_cid *cid;
  int nfields;
  int rc;
  SDWORD nr;
  UWORD nrs[1000];
  int use_nbind;
  struct BINDING *use_binding;
  int mode=0;

  debug ("In fetch_cursor (%s,%d,%d,%d,%p)", cursor_name, fetch_mode, fetch_when, nibind, ibind);
  debug ("before find cursor");
  cid = A4GLSQL_find_cursor (cursor_name);
#ifdef DEBUG
	/* {DEBUG} */ {debug ("fetch_cursor : cid=%p", cid);}
#endif
  if (cid->hstmt == 0)
    {
      exitwith ("Fetch attempted on unopened cursor");
      return 0;
    }
  if (ibind == 0)
    {
#ifdef DEBUG
	/* {DEBUG} */ {debug ("   Use cursors bindings..");}
#endif
      use_binding = cid->statement->obind;
      use_nbind = cid->statement->no;
    }
  else
    {
#ifdef DEBUG
	/* {DEBUG} */ {debug ("   Use fetches bindings..");}
#endif
      use_binding = ibind;
      use_nbind = nibind;
      proc_bind (ibind, nibind, 'o',  cid->statement->hstmt); 
    }

  switch (fetch_mode)
    {
    case FETCH_ABSOLUTE:
      debug("Absolute : %d",fetch_when);
      mode = SQL_FETCH_ABSOLUTE;
      break;
    case FETCH_RELATIVE:
      debug("relative : %d",fetch_when);
      mode = SQL_FETCH_RELATIVE;
      break;
    }

  if (mode == SQL_FETCH_RELATIVE)
    {
      if (fetch_when == 1) {
      debug("fetch next");
	mode = SQL_FETCH_NEXT;
      }
      if (fetch_when == -1) {
      debug("fetch previous");
	mode = SQL_FETCH_PRIOR;
      }
    }

  if (mode == SQL_FETCH_ABSOLUTE)
    {
      if (fetch_when == 1) {
      debug("fetch first");
	mode = SQL_FETCH_FIRST;
      }
      if (fetch_when == -1) {
      debug("fetch last");
	mode = SQL_FETCH_LAST;
}
    }

  debug ("Before Extended fetch...");

  if (chk_getenv ("EXTENDED_FETCH",TRUE))
    {

      debug ("Calling SQLextended fetch with %p %d %d", cid->statement->hstmt, mode, fetch_when);
      nr = 1;
      rc = SQLExtendedFetch ( cid->statement->hstmt, mode, fetch_when, &nr, &nrs[0]);
      chk_rc (rc, cid->statement->hstmt, "SQLExtendedFetch");
    }
  else
    {
      rc = SQLFetch ( cid->statement->hstmt );
      chk_rc (rc, cid->statement->hstmt, "SQLFetch");
    }
  debug ("After fetch");
#ifdef DEBUG
	/* {DEBUG} */ { debug ("Rc set to %d", rc); }
#endif
  if (rc == SQL_NO_DATA_FOUND)
    {
      A4GLSQL_set_status (100, 1);
      return 0;
    }

  /*
  if (rc != SQL_SUCCESS && rc != SQL_NO_DATA_FOUND)
    {
      set_sqlca (cid->statement->hstmt, "ODBC_exec_select : After SQLFetch", 0);
    }
    */

/*  res = PQexec (conn, cmd); exec */
  post_fetch_proc_bind (use_binding, use_nbind,&cid->statement->hstmt);
  nfields = 1;			/* number of fields returned */
  debug ("nfields=%d\n", nfields);
  debug ("nibind=%d\n", use_nbind);
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
A4GLSQL_init_connection (char *dbName)
{
  char empty[10] = "None";
  char  *u, *p;
  HDBC *hh=0;
  int rc;

  #ifdef DEBUG
	  debug("A4GLSQL_init_connection(dbName='%s')", dbName);
  #endif

  if (strcmp (dbName, OldDBname) == 0) {
	#ifdef DEBUG
		debug ("Already connected - ignored.");
    #endif
    return 0;
  }

  /* free up the current default connection, if there is one */
  if (has_pointer ("default", SESSCODE))
    {
      hh = find_pointer_val ("default", SESSCODE);
      rc = SQLFreeConnect (*hh);
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

  if (u==0 || *u=='\0')  u = getlogin();
	/*
    FIXME
	we have something simmilar somewhere in libaubit4gl for WIN32 - find it 
	and use it instead getlogin()
    */
#else
  #ifdef DEBUG
    debug("avoided getlogin() call");
  #endif

#endif
  
  /* FIXME: what is LOGNAME ? */
  if (u==0 || *u=='\0')  u = acl_getenv("LOGNAME");
  if (u==0)  u = empty;

  p = acl_getenv ("SQLPWD");
  if ( (p==0 || *p =='\0') && *u >'\0' ) {
     /*  prompt user for password - if not specified in odbc.ini -not yet implemented  */
  }
  if (p==0)  p = empty;

#ifdef DEBUG 
  { debug ("u=%s p=%s", u, p); }
#endif

  if (A4GLSQL_make_connection (dbName, u, p))
    {
      /* do we have an existing pointer to default */
      hh = find_pointer_val ("default", SESSCODE);
      if (hh == 0)
	{
	  hh = malloc (sizeof (HDBC));
	}
      *hh = hdbc;
      add_pointer ("default", SESSCODE, hh);
      rc = SQLSetConnectOption (hdbc, SQL_AUTOCOMMIT, 0);
      chk_rc (rc, 0, "SQLSetConnectOption");
	  #ifdef DEBUG
		  debug ("AUTOCOM rc=%d", rc);
      #endif
    }
  else
    {
      set_errm (dbName);
      exitwith ("Could not connect to database");
    }
  #ifdef DEBUG
	  debug ("hh=%p for %s", hh, dbName);
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
A4GLSQL_xset_status(int a) 
{
	A4GLSQL_set_status(a,0);
}

/**
 * Get the value of the status 4gl global variable.
 *
 * @return The value of sqlca.sqlcode
 */
int 
A4GLSQL_get_status (void)
{
  return sqlca.sqlcode;
}

/**
 * Get the current SQL error message.
 *
 * @return The contents of sqlca.sqlerrm.
 */
char *
A4GLSQL_get_sqlerrm (void)
{
  return sqlca.sqlerrm;
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
  ptr = find_pointer_val (cname, CURCODE);
  if (ptr == 0)
    {
      exitwith ("Can't free cursor thats not been defined");
      return 0;
    }
  if (ptr->hstmt)
    {
      SQLFreeStmt (ptr->hstmt, SQL_DROP);
      chk_rc (rc, 0, "SQLFreeStmt");
    }
  free (ptr->statement->select);
  free (ptr->statement);
  del_pointer (cname, CURCODE);
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

  debug ("In close cursor");
  ptr = find_pointer_val (cname, CURCODE);
  if (ptr == 0)
    {
      exitwith ("Can't close cursor that hasn't been defined");
      return -1;
    }

  debug ("Clr hstmt ptr=%p", ptr);

  if (ptr->hstmt)
    {
      SQLFreeStmt (ptr->hstmt, SQL_CLOSE);
      chk_rc (rc, ptr->hstmt, "SQLFreeStmt");
    }

  ptr->hstmt = 0;
  debug ("Clr hstmt ptr=%p hstmt=%p", ptr, ptr->hstmt);
  return 1;
}

/**
 * Add a cursor to the pointer tree.
 *
 * @param cid A pointer to the identifing cursor structure.
 * @param cname The cursor name.
 */
void 
add_cursor (struct s_cid *cid, char *cname)
{
  add_pointer (cname, CURCODE, cid);
}

/**
 * Gets the sql error.
 *
 * @todo : Fix this recursive return.
 */
char*
ret_sql_err (void)
{
  return ret_sql_err ();
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
find_prepare2 (char *pname)
{
  struct s_sid *ptr;
  ptr = (struct s_sid *) find_pointer_val (pname, PRECODE);
  if (ptr)
    return 1;
  return 0;
}

/**
 * Add a prepare statement to the pointer tree.
 *
 * @param pname The prepared statement name.
 * @param sid A pointer to the statement information.
 */
int 
A4GLSQL_add_prepare (char *pname, struct s_sid * sid)
{
  if (sid)
    {
      add_pointer (pname, PRECODE, sid);
      return 1;
    }
  else
    {
      return 0;
    }

}

/**
 * If debug was set print Error.
 *
 * @return Allways 1
 */
int
print_err (HDBC hdbc, HSTMT hstmt)
{
#ifdef DEBUG
	/* {DEBUG} */ { debug ("Error.....\n"); }
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
display_size (SWORD coltype, UDWORD collen, UCHAR * colname)
{
  debug ("display_size Coltype=%d %d %s\n", coltype, collen, colname);
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

	/* Note that this function only supports the */
	/* core data types. */
	case SQL_LONGVARBINARY:
	case SQL_LONGVARCHAR:
	case SQL_VARBINARY: return 6;
    case 9:			/* date */

      return 12;
    case 11:			/* datetime */

      return 26;		/* yyyy-mm-dd hh:mm:ss.ffffff */

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
int 
A4GLSQL_make_connection (UCHAR * server, UCHAR * uid_p, UCHAR * pwd_p)
{
  RETCODE rc;
  char uid[256]="";
  char pwd[256]="";

  debug ("A4GLSQL_make_connection .. server=%s uid_p=%s pwd_p=%s",
        server, uid_p, pwd_p );

  /* do nothing if no server, which can happen if fgl_start
   * has no default compile-time database  */
  if ( (server == 0) || (strlen(server) == 0) ) {
        debug (" no server - no connection.");
        return 1;
  }

  /* copy user name and password, and remove trailing spaces
   */

  trim(uid_p);
  trim(pwd_p);
  if (uid_p) strcpy(uid,uid_p);
  if (pwd_p) strcpy(pwd,pwd_p);
  trim(uid);
  trim(pwd);
  trim(server);

  /*
    FIXME: we really need more then trim() here - I once had a TAB after
    uid by mistake...
  */

  if (henv == 0)
    {
      rc = SQLAllocEnv (&henv);
      chk_rc (rc, 0, "SQLAllocEnv");
#ifdef DEBUG
	{debug ("SQLAllocEnv returns %d %p", rc, henv);}
#endif
    }

  rc = SQLAllocConnect (henv, &hdbc);
  chk_rc (rc, 0, "SQLAllocConnect");
#ifdef DEBUG
	{debug ("SQLAllocConnect returns %d %p", rc, hdbc);}
#endif

#ifdef DEBUG
	debug("Connecting to >%s< as >%s</>%s<",server,uid,pwd);
#endif

rc = SQLConnect (hdbc, server, SQL_NTS, uid, SQL_NTS, pwd, SQL_NTS);

chk_rc (rc, 0, "SQLConnect");

#ifdef DEBUG
	{debug ("SQLConnect status = %d", rc);}
#endif

  if (rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO)
    {
      set_sqlca (0, "Connect Failed", 0);
      return 0;
    }

  A4GLSQL_set_status(0,1);
  ODBC_set_dbms_info();

  rc = SQLSetConnectOption (hdbc, SQL_ASYNC_ENABLE, 0);
  A4GLSQL_set_status(0,1);

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
A4GLSQL_dbms_dialect( void )
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
A4GLSQL_dbms_name( void )
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
ODBC_set_dbms_info(void)
{
  int rc;
  short len;

  rc = SQLGetInfo(hdbc, SQL_DBMS_NAME, dbms_name, (short) 64, &len);

  strcpy(dbms_dialect,"");
  if ( strncasecmp(dbms_name,"informix",8)==0) {strcpy(dbms_dialect,"INFORMIX"); }
  if ( strncasecmp(dbms_name,"sapdb",5)==0)  {strcpy(dbms_dialect,"SAPDB"); }
  if ( strncasecmp(dbms_name,"postgr",6)==0) {strcpy(dbms_dialect,"POSTGRESQL"); }
  if ( strncasecmp(dbms_name,"oracl",5)==0)  {strcpy(dbms_dialect,"ORACLE"); }
  if ( strncasecmp(dbms_name,"mysql",5)==0)  {strcpy(dbms_dialect, "MYSQL"); }
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
	/* {DEBUG} */ {debug ("ODBC_disconnect: hdbc=%p", hdbc); }
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
    /* {DEBUG} */ {debug ("ODBC_exec_sql: %s",sqlstr);}
#endif

  if (new_hstmt (&hstmt))
    {
      rc = SQLExecDirect (hstmt, sqlstr, SQL_NTS);
      chk_rc (rc, 0, "SQLExecDirect");
#ifdef DEBUG
    /* {DEBUG} */{debug ("SQLExecDirect returns %d", rc);}
#endif
      if (rc != SQL_SUCCESS)
      {
        return sqlerrwith (rc, hstmt);
      }
      rc = SQLFreeStmt (hstmt, SQL_DROP);
      chk_rc (rc, 0, "SQLFreeStmt");
      return 1;
    }

#ifdef DEBUG
    /* {DEBUG} */{debug ("Failed to allocate new hstmt!");}
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
ODBC_exec_stmt (HSTMT hstmt)
{
  int rc;

#ifdef DEBUG
    /* {DEBUG} */{debug ("In ODBC_exec_stmt ....");}
#endif

  rc = SQLExecute (hstmt);

#ifdef DEBUG
    /* {DEBUG} */ {debug("SQLExecute returns %d\n",rc);}
#endif

  rc=chk_need_blob(rc,hstmt);

#ifdef DEBUG
    /* {DEBUG} */ {debug("chk_need_blob returns %d\n",rc);}
#endif

  chk_rc (rc, hstmt, "SQLExecute2");

#ifdef DEBUG
    /* {DEBUG} */ {debug("chk_rc: Result=%d (Success==%d)",rc,SQL_SUCCESS);}
#endif

  if (rc != SQL_SUCCESS)
    {
      return sqlerrwith (rc, hstmt);
    }

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
sqlerrwith (int rc, HSTMT h)
{
  /* set_sqlca (h, "From sqlerrwith", 0); */
  SQLFreeStmt (h, SQL_DROP);
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
set_sqlca (HSTMT hstmt, char *s, int reset)
{
  char s1[81];
  char s2[500];
/*
sql.c: In function `set_sqlca':
sql.c:1788: conflicting types for `_errno'
d:/MinGW/include/stdlib.h:153: previous declaration of `_errno'
sql.c:1788: warning: extern declaration of `_errno' doesn't match global one
make[2]: *** [sql.o] Error 1
*/
#ifndef __MINGW32__
  SDWORD errno;
#endif
  SWORD errno2;
  SDWORD rowcount;
  RETCODE rc;

  strcpy (lasterrorstr, "");

  /* chk_rc (rc, hstmt, "SQLRowCount"); */
#ifdef DEBUG
	/* {DEBUG} */ {debug ("set_sqlca...%p %p %p", henv, hdbc, hstmt);}
	/* {DEBUG} */ {debug ("set sqlca caused by %s", s);}
#endif
  rc = -1;
  //while (rc != 0 && rc != 100)
  if (rc != 0 && rc != 100)
    {
      debug("Calling SQLError %p %p %p rc=%d",henv,hdbc,hstmt,rc);
      rc = SQLError (henv, hdbc, hstmt, s1, &errno, s2, 500, &errno2);
      debug("rc=%d\n",rc);
	if (errno>0 && errno!=100) errno=0-errno;
#ifdef DEBUG
	/* {DEBUG} */{debug ("After SQL Error %d %s %s\n%x",errno,s1,s2,errno2); }
#endif
      if (strlen(s1)==0) strcpy(s1,"00000");

      strcpy (sqlca.sqlstate, s1);

      if (strcmp (s1, "00000") == 0)
	{
	  errno = 0;
	  errno2 = 0;
	}

      if ((strcmp (s1, "00000") != 0 && errno == 0)||(s1[0]=='0'&&s1[1]=='1'))
	{
	  debug("Got %s as state",s1);
	if (errno==0) {
	  errno = -101;
	  errno2 = 0;
	}
	}

#ifdef DEBUG
	/* {DEBUG} */{debug ("'%s' '%s' (%d %d)", s1, s2, errno, errno2);}
#endif
      strncpy (sqlca.sqlerrm, s2, 72);
      A4GLSQL_set_status (errno, 1);
      debug ("Setting lasterrorstr to '%s'", s2);
      strcpy (lasterrorstr, s2);
    }
  debug("Done that - getting rowcount");
  rc = SQLRowCount (hstmt, &rowcount);
  sqlca.sqlerrd[1] = rowcount;
}

/**
 * Do a output bind of variable to the statement.
 *
 * @param pos Position / sequence in the bind array.
 * @param bind Pointer to the bind array.
 * @param hstmt Statement handle.
 */
void
obind_column (int pos, struct BINDING *bind, HSTMT hstmt)
{
  static int rc;

#ifdef DEBUG
	/* {DEBUG} */ {debug ("OBIND Binding %d=(%d %d %p)", pos, bind->dtype, bind->size, bind->ptr);}
	/* {DEBUG} */ {debug ("SQLBindCol(hstmt=%p, pos=%d,\n     conv_4gl_to_c[bind->dtype]=%d, bind->ptr=%p,\n     fgl_size(bind->dtype,bind->size)=%d, SQL_NULL_DATA);", hstmt, pos, conv_4gl_to_c[bind->dtype], bind->ptr, fgl_size (bind->dtype, bind->size), SQL_NULL_DATA);  }
	/* {DEBUG} */ {debug ("SQLBindCol");}
#endif

  if (bind->dtype == DTYPE_DATE)
    {
      bind->ptr = bind_date ((long *) bind->ptr);
      debug ("Bound date...\n");
    }

  if (bind->dtype==DTYPE_BYTE||bind->dtype==DTYPE_TEXT) 	{
		return;
  }
	
  rc = SQLBindCol (hstmt, pos, conv_4gl_to_c[bind->dtype], bind->ptr, fgl_size (bind->dtype, bind->size), &outlen[pos]);

  chk_rc (rc, hstmt, "SQLBindCol");
#ifdef DEBUG
	/* {DEBUG} */ {debug ("SQLBindCol returned %d", rc);}
#endif
  /* set_sqlca (hstmt, "obind_column : After SQLBindCol", 0); */

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
ibind_column (int pos, struct BINDING *bind, HSTMT hstmt)
{
  int size;
	/* DATE_STRUCT *tmp; */
	/*review */

  int k=0;

  if (bind->dtype == 7)
    {
      rc = newSQLSetParam (hstmt,
			pos,
			SQL_INTEGER,
			SQL_INTEGER, 0, 0, bind->ptr, NULL);
      /* chk_rc (rc, hstmt, "SQLSetParam"); */
    }

#ifdef DEBUG
	/* {DEBUG} */ {debug ("Binding %d=(%d %d %p)", pos, bind->dtype, bind->size, bind->ptr);}
#endif
  if (bind->dtype != 0)
    size = 0;
  else
    size = bind->size;


  debug("Call SQLSetParam h=%p p=%d dt=%d dt=%d size=%d k=%d ptr=%p",hstmt,pos,
		    conv_4gl_to_c[bind->dtype],
		    conv_4gl_to_c[bind->dtype],
		    size, k,bind->ptr);
  	rc = newSQLSetParam (hstmt, pos,
		    conv_4gl_to_c[bind->dtype],
		    conv_4gl_to_c[bind->dtype],
		    size, k, bind->ptr,
		    NULL);


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
ODBC_exec_select (HSTMT hstmt)
{
  int rc;

  SWORD nresultcols;
  SDWORD rowcount;

#ifdef DEBUG
	/* {DEBUG} */ {debug ("Before Execute");}
#endif
  rc = SQLExecute (hstmt);
  rc=chk_need_blob(rc,hstmt);
  chk_rc (rc, hstmt, "SQLExecute3");
  if (rc!=0)  return 0;

  /* set_sqlca (hstmt, "ODBC_exec_select : After SQLExecute", 0); */
  if (rc!=0)  return 0;
  rc = SQLNumResultCols (hstmt, &nresultcols);
  chk_rc (rc, hstmt, "SQLNumResultCols");
#ifdef DEBUG
	/* {DEBUG} */{debug ("SQLNumResultCols returns %d", nresultcols);}
#endif
  rc = SQLRowCount (hstmt, &rowcount);
  chk_rc (rc, hstmt, "SQLRowCount");

#ifdef DEBUG
	/* {DEBUG} */{debug ("SQLRowCount=%d", rowcount);}
#endif

#ifdef DEBUG
	/* {DEBUG} */{debug ("Before Fetch");}
#endif

  if (rc==100) return 0;

  rc = SQLFetch (hstmt);
  chk_rc (rc, hstmt, "SQLFetch");

  /* set_sqlca (hstmt, "ODBC_exec_select : After SQLFetch", 0); */

#ifdef DEBUG
	/* {DEBUG} */ {debug ("Result=%d", rc);}
#endif

	/* Execute the SQL statement. */
  if (rc != SQL_SUCCESS)
    {
#ifdef DEBUG
	/* {DEBUG} */{debug ("Oh dear.... %d", rc);}
#endif
      return sqlerrwith (rc, hstmt);
    }
#ifdef DEBUG
	/* {DEBUG} */{debug ("Yipee!");}
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
new_hstmt (HSTMT * hstmt)
{
  int rc;
  debug ("Database : %s", OldDBname);
  if (hdbc == 0 )
    {
      debug ("*** No current connection ....");
      exitwith ("Not connected to database");
      return 0;
    }
  rc = SQLAllocStmt (hdbc, hstmt);
  chk_rc (rc, 0, "SQLAllocStmt");
  debug ("allocate statement returns rc=%d", rc);
  return *hstmt;
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
ODBC_exec_prepared_sql (HSTMT hstmt)
{
int rc;

debug("In exec_prepared_sql");

  rc = SQLExecute (hstmt);

  rc=chk_need_blob(rc,hstmt);

  chk_rc (rc, hstmt, "SQLExecute");
   set_sqlca (hstmt, "ODBC_exec_prepared_sql : After SQLExecute", 0); 

#ifdef DEBUG
	/* {DEBUG} */{debug ("Result=%d", rc);}
#endif

	/* Execute the SQL statement. */
  if (rc != SQL_SUCCESS)
    {
#ifdef DEBUG
	/* {DEBUG} */{debug ("Oh dear.... %d", rc);}
#endif
      return sqlerrwith (rc, hstmt);
    }
#ifdef DEBUG
	/* {DEBUG} */ {debug ("Yipee!");}
#endif
  rc = SQLTransact (henv, hdbc, SQL_COMMIT);
  chk_rc (rc, 0, "SQLTransact (COMMIT)");
  set_sqlca (hstmt, "ODBC_exec_prepared_sql : After SQLTransact", 0);
  return 1;
}

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
  {    debug ("Getting datatype for %s %s %s", db, tab, col);  }
#endif
  new_hstmt (&hstmt);
#ifdef DEBUG
  {    debug ("Allocated .. %p %p %p", henv, hdbc, hstmt);  }
#endif
  sprintf (sql1, "select %s from %s where 1=0", col, tab);
#ifdef DEBUG
  {    debug ("Executing... %s", sql1);  }
#endif
/* Execute the SQL statement. */
  if (SQLExecDirect (hstmt, sql1, SQL_NTS) != SQL_SUCCESS) {
    debug("Error executing\n");
    return -1;
}

#ifdef DEBUG
  {    debug ("Executed OK");  }
#endif

  SQLDescribeCol (hstmt, 1, colname,
		  (SWORD) sizeof (colname),
		  &colnamelen, &coltype,
		  &collen[0], &scale, &nullable);
#ifdef DEBUG
  {    debug ("SQL DATATYPE : Got %s %d %d", colname, coltype, collen[0]);  }
#endif
  SQLFreeStmt (hstmt, SQL_DROP);
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

  if (sqldtype >= 0)
    ndtype = convpos_sql_to_4gl[sqldtype];
  else
    ndtype = convneg_sql_to_4gl[sqldtype * -1];
  if (ndtype == 0)
    {
      debug ("Encoding string size : %d", sdim);
      ndtype = ENCODE_SIZE (sdim);
    }
#ifdef DEBUG
  {    debug ("Datatype (%d,%d) is 0x%x ", sqldtype,sdim,ndtype);  }
#endif
  return ndtype;
}

/**
 * Gets the current database name.
 *
 * @return The current database name.
 */
char *
A4GLSQL_get_currdbname(void)
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
describecolumn (HSTMT hstmt, int colno, int type)
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
      exitwith ("Statement has not been prepared");
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
		       &colnamelen, &coltype,
		       &collen, &scale, &nullable);
  if (rc != SQL_SUCCESS)
    {
      set_sqlca (hstmt, "Describe column", 0);
      return 0;
    }

#ifdef DEBUG
  {    debug ("SQL DATATYPE : Got %s %d %d", colname, coltype, collen);  }
  {    debug ("Returning type code : %d", type);  }
  {    debug ("Col type = %d %d", coltype, collen);  }
#endif

  coltype = conv_sqldtype (coltype, collen);
#ifdef DEBUG
  {    debug ("Converted type");  }
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

  exitwith ("Internal Error (describecolumn)");
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

  sid = A4GLSQL_find_prepare(stmt);
  cid=0;

  if (sid == 0)
    {
#ifdef DEBUG
      {	debug ("Sid=0 - try as a cursor");      }
#endif
      cid = A4GLSQL_find_cursor (stmt);
#ifdef DEBUG
      {	debug ("cid=%p", cid);      }
#endif
      if (cid == 0)
	{
	  exitwith ("Could not find statement or cursor specified");
	  return 0;

	}
      hstmt = cid->hstmt;
    }
  else
    {
      hstmt = &sid->hstmt;
    }


  if (sid == 0 && cid == 0)
    {
      exitwith ("Statement could not be found");
    }

  z = describecolumn (hstmt, colno, type);
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
    exitwith ("Not connected to database");
    return 0;
  }

  if (hstmtGetColumns == 0)
  {
    debug ("Creating new statement");
    new_hstmt (&hstmtGetColumns);
  }

  if (tabname != 0)
    {
      debug ("New search");
      new_hstmt (&hstmtGetColumns);
      debug ("Got Statement");

      rc = SQLColumns (hstmtGetColumns,
		       NULL, 0,
		       NULL, 0,
		       tabname,
		       SQL_NTS,
		       NULL, 0
	);

      if (rc!=SQL_SUCCESS) {
		debug("Some problem with SQLColumns");
      }

      if (rc == SQL_ERROR)
	{
	  debug ("SQLColumns failed for table '%s'\n",tabname);
          set_sqlca (hstmtGetColumns, "getting column info", 0);
	  exitwith ("Error getting column info\n");
	  return 0;
	}

      debug ("rc=%d\n", rc);

       if (SQLNumResultCols( hstmtGetColumns, &nColumns)!=SQL_SUCCESS) {
		debug("No NumResultCols");
		nColumns=-1;
       }

     debug("nColumns=%d",nColumns);

      a = 79;
      b = 254;
      rc=SQLBindCol (hstmtGetColumns, 1, SQL_C_CHAR, tq, 255, &outlen[1]);
	debug("Rc=%d",rc);
      rc=SQLBindCol (hstmtGetColumns, 2, SQL_C_CHAR, to, 255, &outlen[2]);
	debug("Rc=%d",rc);
      rc=SQLBindCol (hstmtGetColumns, 3, SQL_C_CHAR, tn, 255, &outlen[3]);
	debug("Rc=%d",rc);
      rc=SQLBindCol (hstmtGetColumns, 4, SQL_C_CHAR, cn, 255, &outlen[4]);
	debug("Rc=%d",rc);
      rc=SQLBindCol (hstmtGetColumns, 6, SQL_C_CHAR, dtname, 255, &outlen[6]);
	debug("Rc=%d",rc);
      rc=SQLBindCol (hstmtGetColumns, 5, SQL_C_LONG, &dt, 4, &outlen[5]);
	debug("Rc=%d",rc);
      rc=SQLBindCol (hstmtGetColumns, 7, SQL_C_LONG, &prec, 4, &outlen[7]);
	debug("Rc=%d",rc);
      rc=SQLBindCol (hstmtGetColumns, 8, SQL_C_LONG, &len, 4, &outlen[8]);
	debug("Rc=%d",rc);
      rc=SQLBindCol (hstmtGetColumns, 9, SQL_C_LONG, &scale, 4, &outlen[9]);
	debug("Rc=%d",rc);
      rc=SQLBindCol (hstmtGetColumns, 10, SQL_C_LONG, &radix, 4, &outlen[10]);
	debug("Rc=%d",rc);
      rc=SQLBindCol (hstmtGetColumns, 11, SQL_C_LONG, &nullable, 4, &outlen[11]);
	debug("Rc=%d",rc);
      rc=SQLBindCol (hstmtGetColumns, 12, SQL_C_CHAR, remarks, 255, &outlen[12]);
	debug("Rc=%d",rc);
      debug ("Bound columns\n");
    
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
A4GLSQL_next_column(char **colname, int *dtype,int *size)
{
  rc = SQLFetch (hstmtGetColumns);
  debug("A4GLSQL_next_column fetch rc = %d, cn = %s\n", rc, cn);

  if (rc == SQL_NO_DATA_FOUND || rc == SQL_ERROR)
  {
    return 0;
  }

  colsize = display_size (dt, prec, "");
  sprintf (szcolsize, "%d", colsize);

  if (rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO)
  {
    SQLFreeStmt (hstmtGetColumns, SQL_DROP);
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
A4GLSQL_end_get_columns(void)
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
      exitwith ("Not connected to database");
      return 0;
    }
#ifdef DEBUG
  {    debug ("In read column tabname='%s' colname='%s'", tabname, colname);  }
#endif

  if (hstmt == 0)
    {
      debug ("Creating new statement");
      new_hstmt (&hstmt);
    }

  if (tabname != 0)
    {
      debug ("New search");
      new_hstmt (&hstmt);
      debug ("Got Statement");

      rc = SQLColumns (hstmt,
		       NULL, 0,
		       NULL, 0,
		       tabname,
		       SQL_NTS,
		       NULL, 0
	);

      if (rc!=SQL_SUCCESS) {
		debug("Some problem with SQLColumns");
      }

      if (rc == SQL_ERROR)
	{
	  debug ("SQLColumns failed for table '%s'\n",tabname);
          set_sqlca (hstmt, "getting column info", 0);
	  exitwith ("Error getting column info\n");
	  return 0;
	}

      debug ("rc=%d\n", rc);

       if (SQLNumResultCols( hstmt, &nColumns)!=SQL_SUCCESS) {
		debug("No NumResultCols");
		nColumns=-1;
       }

     debug("nColumns=%d",nColumns);

      a = 79;
      b = 254;
      rc=SQLBindCol (hstmt, 1, SQL_C_CHAR, tq, 255, &outlen[1]);
	debug("Rc=%d",rc);
      rc=SQLBindCol (hstmt, 2, SQL_C_CHAR, to, 255, &outlen[2]);
	debug("Rc=%d",rc);
      rc=SQLBindCol (hstmt, 3, SQL_C_CHAR, tn, 255, &outlen[3]);
	debug("Rc=%d",rc);
      rc=SQLBindCol (hstmt, 4, SQL_C_CHAR, cn, 255, &outlen[4]);
	debug("Rc=%d",rc);
      rc=SQLBindCol (hstmt, 6, SQL_C_CHAR, dtname, 255, &outlen[6]);
	debug("Rc=%d",rc);
      rc=SQLBindCol (hstmt, 5, SQL_C_LONG, &dt, 4, &outlen[5]);
	debug("Rc=%d",rc);
      rc=SQLBindCol (hstmt, 7, SQL_C_LONG, &prec, 4, &outlen[7]);
	debug("Rc=%d",rc);
      rc=SQLBindCol (hstmt, 8, SQL_C_LONG, &len, 4, &outlen[8]);
	debug("Rc=%d",rc);
      rc=SQLBindCol (hstmt, 9, SQL_C_LONG, &scale, 4, &outlen[9]);
	debug("Rc=%d",rc);
      rc=SQLBindCol (hstmt, 10, SQL_C_LONG, &radix, 4, &outlen[10]);
	debug("Rc=%d",rc);
      rc=SQLBindCol (hstmt, 11, SQL_C_LONG, &nullable, 4, &outlen[11]);
	debug("Rc=%d",rc);
      rc=SQLBindCol (hstmt, 12, SQL_C_CHAR, remarks, 255, &outlen[12]);
	debug("Rc=%d",rc);
      debug ("Bound columns\n");
    
  }

  rc = SQLFetch (hstmt);

#ifdef DEBUG
  {    debug ("Rc = %d", rc);  }
#endif
  if (colname[0] != 0)
    {
      /* if were looking for a specific column ... */
      trim (cn);
      while (strcasecmp (cn, colname) != 0)
	{

	  debug ("Calling Fetch... %s %s\n", cn, colname);

	  rc = SQLFetch (hstmt);
	  trim (cn);
	  debug ("Fetch called - %d\n", rc);
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
  {    debug ("column -> %s Dtype=%x len=%x rc=%d", cn, dt, len, rc);  }
  {    debug ("column tq=%s to=%s tn=%s cn=%s", tq, to, tn, cn);  }
  {    debug ("XXX       %x %s prec=%x %d\n %x %x %x '%s'", dt, dtname, prec, len, scale, radix, nullable, remarks);  }
#endif
  colsize = display_size (dt, prec, "");
  sprintf (szcolsize, "%d", colsize);

  if (rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO)
    {
#ifdef DEBUG
      {	debug ("Some error getting data....");      }
#endif
      SQLFreeStmt (hstmt, SQL_DROP);
      return 0;
    }
  strcpy (colname, cn);
  *size = prec;
  *dtype = conv_sqldtype (dt, prec);
  debug("Set dtype to %d\n",*dtype);
  return 1;
}

/**
 *
 *
 * @param
 */
void
ibind_column_arr (int pos, char *s, HSTMT hstmt)
{
  int size;
/* DATE_STRUCT *tmp; */
/*review */

  size = strlen (s);

  newSQLSetParam (hstmt, pos,
	       conv_4gl_to_c[0],
	       conv_4gl_to_c[0],
	       size, 0, s,
	       NULL);
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
A4GLSQL_init_session (char *sessname, char *dsn, char *usr, char *pwd)
{
char empty[10] = "None";
char *u, *p = 0;
HDBC *hh;

  if ( sessname == 0 || strlen(sessname) == 0 ) {
       return 0;
  }

  hh = find_pointer_val (sessname, SESSCODE);

  if (hh)
    {
      exitwith ("Session already opened");
      return 0;
    }

  if (strcmp (sessname, sess_name) == 0)
    return 0;

  set_errm (dsn);

  if (usr == 0)
    u = acl_getenv ("SQLUID");
  else
    u = usr;

  if (pwd == 0)
    p = acl_getenv ("SQLPWD");
  else
    p = pwd;

#ifdef DEBUG
  {    debug ("Got environment variables");  }
#endif

  if (u == 0)
    u = empty;
  if (p == 0)
    p = empty;

#ifdef DEBUG
	{ debug ("u=%s p=%s", u, p); }
	{ debug ("Try to make connection then ..%s ", dsn); }
#endif

  if (A4GLSQL_make_connection (dsn, u, p))
    {
	/* do we have an existing pointer to default */
      hh = malloc (sizeof (HDBC));
      add_pointer (sessname, SESSCODE, hh);
      *hh = hdbc;

#ifdef DEBUG
	/* {DEBUG} */ { debug ("Made connection executing SQL"); }
#endif
    }
  else
    {
      exitwith ("Could not connect to database");
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

  if (!(find_pointer_val (cursname, code)))
    {
      code = PRECODE;
      if (!(find_pointer_val (cursname, code)))
	{
	  set_errm (cursname);
	  exitwith ("%s is not a statement or cursor name");
	  return 0;
	}
    }

  if (code == PRECODE)
    {
      debug ("Is prepare statement");
      ptr_sid = (struct s_sid *) find_pointer (cursname, PRECODE);
      stmt = &ptr_sid->hstmt;
    }
  else
    {
      debug ("Is cursor statement");
      ptr_cid = (struct s_cid *) find_pointer (cursname, CURCODE);
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
  HSTMT stmt;
  code = CURCODE;
  if (np != 1)
    {
      for (code = 0; code < np; code++)
	{
	  pop_char (aa, 20);
	  return 0;
	}
    }
  pop_char (cursname, 64);
  trim (cursname);

  if (!(find_pointer_val (cursname, code)))
    {
      code = PRECODE;
      if (!(find_pointer_val (cursname, code)))
	{
	  set_errm (cursname);
	  exitwith ("%s is not a statement or cursor name");
	  return 0;
	}
    }

  if (code == PRECODE)
    {
      debug ("Is prepare statement");
      ptr_sid = (struct s_sid *) find_pointer (cursname, PRECODE);
      stmt = &ptr_sid->hstmt;
    }
  else
    {
      debug ("Is cursor statement");
      ptr_cid = (struct s_cid *) find_pointer (cursname, CURCODE);
      stmt = &ptr_cid->statement->hstmt;
    }

  push_long ((int)stmt);
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
A4GLSQL_set_conn (char *sessname)
{
  HDBC *hdbc_new;
  if (find_pointer_val (sessname, SESSCODE))
    {
      strcpy (sess_name, sessname);
      hdbc_new = (HDBC *) find_pointer_val (sessname, SESSCODE);
      hdbc = *hdbc_new;
    }
  else
    {
      if (strcmp (sessname, "default") != 0)
	{
	  set_errm (sessname);
	  exitwith ("Could not make session (%s) current as it does not exist");
	  return 0;
	}
      else
	{
	  strcpy (sess_name, "default");
	}
    }
ODBC_set_dbms_info();
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
A4GLSQL_close_session (char *sessname)
{
  HDBC *ptr;
  int rc;
  ptr = (HDBC *) find_pointer_val (sessname, SESSCODE);

  debug("Trying to close session %s, pr=%p", sessname, ptr);

  if (ptr == 0)
    {
      set_errm (sessname);
      exitwith ("Session Id (%s) does not exist");
      return 0;
    }

  rc = SQLDisconnect (*ptr);

  if (rc == 0)
    {
      A4GLSQL_set_status (0, 1);
      free (ptr);
      if ( strcmp(sessname,"default") != 0 )
           A4GLSQL_set_conn ("default");
    }
  else
    {
      exitwith ("Could not disconnect from database");
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
bind_date (long *ptr_to_date_var)
{
  ACLDATE *ptr;
  ptr = malloc (sizeof (ACLDATE));
  debug("Binding date for %p",ptr_to_date_var);
  ptr->ptr = ptr_to_date_var;
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
post_fetch_proc_bind(struct BINDING *use_binding,int use_nbind,HSTMT hstmt)
{
  int a;
  int zz;
  ACLDATE *date1;
  debug ("In post_fetch_proc_bind...");

  for (a = 0; a < use_nbind; a++)
    {
	
      debug ("Binding type %d ptr=%p %d", use_binding[a].dtype, use_binding[a].ptr,outlen[a+1]);

      if (outlen[a+1]==-1) {
      		if (use_binding[a].dtype == DTYPE_DATE) {
	  		date1 = use_binding[a].ptr;
			setnull(DTYPE_DATE,(char *)date1->ptr,0);
			continue;
		}
		setnull(use_binding[a].dtype,(char *)use_binding[a].ptr ,use_binding[a].size);
		continue;
      }

      if (use_binding[a].dtype==DTYPE_BYTE||use_binding[a].dtype==DTYPE_BYTE) {
		get_blob_data(use_binding[a].ptr,hstmt,a);
		continue;
      }

      if (use_binding[a].dtype == DTYPE_DATE)
	{
	  debug ("Got a date datatype - better copy the date in properly");
	  date1 = use_binding[a].ptr;
	  debug ("Year=%d Month=%d Day=%d", date1->date.year, date1->date.month, date1->date.day);
	  zz = gen_dateno (
			    date1->date.day,
			    date1->date.month,
			    date1->date.year
	    );
	  *((long *)date1->ptr) = zz;
	}
    }

#ifdef DEBUG
	{
	char buffstr[30000]="Fetch returns :\n";
	char bf[2048];
	for (a=0;a<use_nbind;a++) {
	char *cptr;
	int dtype;
	if (use_binding[a].dtype)  dtype=use_binding[a].dtype;
	else dtype=use_binding[a].dtype+ENCODE_SIZE(use_binding[a].size);
	if (dtype==DTYPE_BYTE||dtype==DTYPE_TEXT) {
		push_char("<byte>");
	} else {
		push_variable(use_binding[a].ptr,dtype);
	}
	cptr=char_pop();
	sprintf(bf,"%d) %d %d : %s",a,use_binding[a].dtype,(int)use_binding[a].size,cptr);
	if (a>0) strcat(buffstr,",\n");
	strcat(buffstr,bf);
	free(cptr);
	}
	strcat(buffstr,"\n");
	debug("%s",buffstr);
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

  debug ("In commit_rollback");
  ptr = acl_getenv ("TRANSMODE");
  if (strlen(ptr))
    {
      tmode = atoi (ptr);
    }
  else
    {
      tmode = 0;
    }


  if (tmode == 0)
    {
      debug ("ODBC Transaction Mode:%d ", mode);
      if (mode == 1)
	SQLTransact (henv, hdbc, SQL_COMMIT);

      if (mode == 0)
	SQLTransact (henv, hdbc, SQL_ROLLBACK);

      set_sqlca (SQL_NULL_HSTMT, "Commit/Rollback", 0);
    }
  else
    {
      debug ("Native Transaction Mode:%d", mode);
      new_hstmt (&hstmt);
      if (mode == -1)
	SQLExecDirect (hstmt, "BEGIN WORK", SQL_NTS);

      if (mode == 0)
	SQLExecDirect (hstmt, "ROLLBACK WORK", SQL_NTS);

      if (mode == 1)
	SQLExecDirect (hstmt, "COMMIT WORK", SQL_NTS);
      set_sqlca (hstmt, "Commit/Rollback", 0);


      SQLFreeStmt (hstmt, SQL_DROP);
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
A4GLSQL_unload_data(char *fname,char *delims, char *sql1) 
{
HSTMT hstmt;
char *sql2;
int cnt=0;
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

  fout=mja_fopen(fname,"wt");

  if (fout==0) {
        exitwith("Error opening file for unload");
        return;
  }

  if (hdbc == 0)
    {
      exitwith ("Not connected to database");
      return;
    }
  new_hstmt (&hstmt);

  sql2 = strdup(sql1);

  rc=SQLExecDirect (hstmt, sql2, SQL_NTS);
  chk_rc (rc, hstmt, "unload_data");
  debug("Executed %s %d",sql2,rc);

  rc=SQLNumResultCols(hstmt,&ncols);
  chk_rc (rc, hstmt, "unload_data");
  for (colcnt=1;colcnt<=ncols;colcnt++) {

         rc=SQLDescribeCol (hstmt, colcnt, colname,
		  (SWORD) sizeof (colname),
		  &colnamelen, &coltype[colcnt],
		  &collen, &scale, &nullable);
         chk_rc (rc, hstmt, "SQLDescribeCol");
   }
  while (1)
    {
      rc = SQLFetch (hstmt);
      chk_rc (rc, hstmt, "SQLFetch");
      if (rc == SQL_NO_DATA_FOUND) break;
      cnt++;
	  debug("Fetched row");
      for (colcnt=1;colcnt<=ncols;colcnt++) {

         rc=SQLGetData(hstmt,(short)colcnt,SQL_CHAR,databuf,sizeof(databuf),(SQLINTEGER*)&ind);
				/*
				warning: passing arg 6 of `SQLGetData' from incompatible pointer type
                unsigned long ind;

					SQLRETURN   SQLGetData(SQLHSTMT StatementHandle,
					           SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType,
					           SQLPOINTER TargetValue, SQLINTEGER BufferLength,
					           SQLINTEGER *StrLen_or_Ind);
                */

         chk_rc (rc, hstmt, "SQLGetData");


         debug("Cycling through data %d (%d) ind=%d",colcnt,rc,ind);
         
         if (ind==0) {
	      debug("Null...");
              fprintf(fout,"%c",delims[0]);
         } else {
	      trim(databuf);
              debug("Not null %s    datatype : %d",databuf,coltype[colcnt]);

              if (strlen(databuf)==0) strcpy(databuf," ");

	      if (coltype[colcnt]==SQL_DATE) {
                   fprintf(fout,"%s%c",conv_date(databuf),delims[0]);
              } else {
                   fprintf(fout,"%s%c",databuf,delims[0]);
              }
         }
      }
      fprintf(fout,"\n");
   }

  debug("All done...");
  free(sql2);
  rc = SQLFreeStmt (hstmt, SQL_DROP);
  fclose(fout);
  chk_rc (rc, hstmt, "SQLFreeStmt");
  sqlca.sqlerrd[1]=cnt;
}

/**
 * Convert a date to the format setted in DBDATE.
 *
 * @param s The string with the date coming from the database.
 */
char*
conv_date(char *s) 
{
static char buff[20];
static char sbuff[20];
static char dbdate[20];
int y,m,d;
int cnt;
buff[0]=0;

	sscanf(s,"%d-%d-%d",&y,&m,&d);
	strcpy( dbdate, get_dbdate() );

	debug("Scanning... dbdate=%s",dbdate);

	for (cnt=0;cnt<=2;cnt++) {

	   if ( dbdate[cnt]=='y'|| dbdate[cnt]=='Y') {
	      sprintf(sbuff,"%04d",y);
	      strcat(buff,sbuff);
	   }

	   if ( dbdate[cnt]=='m'|| dbdate[cnt]=='M') {
	      sprintf(sbuff,"%02d",m);
	      strcat(buff,sbuff);
	   }

	   if ( dbdate[cnt]=='d'|| dbdate[cnt]=='D') {
	      sprintf(sbuff,"%02d",d);
	      strcat(buff,sbuff);
	   }

	   if (cnt!=2) {

	      if (dbdate[4]!=0)
		   sprintf(sbuff,"%c",dbdate[4]);
	      else
		   sprintf(sbuff,"/");

	      strcat(buff,sbuff);
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
char*
decode_rc(int a)
{
	switch(a) {
		case SQL_SUCCESS: return "SQL_SUCCESS";
		case SQL_ERROR: return "SQL_ERROR";
		case SQL_INVALID_HANDLE: return "SQL_INVALID_HANDLE";
		case SQL_SUCCESS_WITH_INFO: return "SQL_SUCCESS_WITH_INFO";
		case SQL_NO_DATA_FOUND: return "SQL_NO_DATA_FOUND";
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
chk_need_blob(int rc,HSTMT hstmt)  
{
    debug("In chk_need_blob rc=%d",rc);
    if (rc!=SQL_NEED_DATA) return rc;
    debug("Need data for %p",hstmt);
    return set_blob_data(hstmt);
}

/**
 * Assign the sqlca.sqlcode with a value
 *
 * @param a The value to be assigned.
 */
void
A4GLSQL_set_sqlca_sqlcode(int a)
{
    status=a;
    sqlca.sqlcode=a;
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
chk_getenv(char *s,int a)
{
char *p;
    p=acl_getenv(s);
    if (p==0&&a==0) return TRUE;
    if (p==0&&a!=0) return FALSE;
    debug("Checking %s (%s) for %d",s,p,a);

    if (p[0]=='Y'||p[0]=='y'||p[0]=='T'||p[0]=='t') {
        if (a==TRUE) return TRUE;
    }
    if (p[0]=='N'||p[0]=='n'||p[0]=='F'||p[0]=='f') {
        if (a==TRUE) return FALSE ;
        else return TRUE;
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
A4GLSQL_put_insert(struct BINDING *ibind,int n)
{
    debug("Not implemented");
    exitwith("Not implemented");
}

/**
 * FLUSH CURSOR 4gl statement implementation.
 * Not implemented in ODBC.
 *
 * @param The cursor name.
 */
void
A4GLSQL_flush_cursor(char *cursor)
{
    debug("Not implemented");
    exitwith("Not implemented");
}

/**
 * Initialization of the sql dynamic library.
 *
 * Used to initialise SQL library, ater loading it with dlopen,
 * called from fglwrap.c
 */
int
A4GLSQL_initsqllib(void)
{
    A4GLSQL_make_connection(0,0,0);
    return 1;
}

/* ================================ EOF ================================ */


