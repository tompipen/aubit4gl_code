/*
 *
 * A4GL_debug("Get columns...");
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-2005 Aubit Development Team (See Credits file)    |
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
# $Id: sql.c,v 1.167 2006-09-06 12:49:11 mikeaubury Exp $
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

void AddColumn (char *s, int d, int sz);
int GetColNo = 0;
char GetColTab[2000];
int GetColCached = 0;
int first_open = 1;
static int conv_sqlprec (int ndtype, int sdim, int scale);

#define CACHE_COLUMN '&'

#if (ODBCVER >= 0x0300)
#define USE_TIMESTAMP
#else
#define DTIME_AS_CHAR
#endif

#ifdef PGODBC
#define DTIME_AS_CHAR
#define DATE_AS_CHAR
#endif

#define DTIME_AS_CHAR

void ListDSN (void);
static int find_extras (void *id);
static void free_extra (void *id);
static void set_extra_data (void *id, int in_out, int position, int data,
			    void *val);
static int setup_extras (void *id);
void *A4GL_bind_decimal (void *ptr_to_decimal);
void initenv (void);

#ifdef DATE_AS_CHAR
int date_as_char = 1;
#else
int date_as_char = 0;
#endif


#ifdef DTIME_AS_CHAR
int dtime_as_char = 1;
#else
int dtime_as_char = 0;
#endif

static int do_fake_transactions (void);


#define SE_NULLPTR 1

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

int A4GLSQL_get_datatype (char *db, char *tab, char *col);
int A4GL_dttoc (void *a, void *b, int size);
void *A4GLSQL_prepare_sql_internal (char *s);
void *A4GLSQL_prepare_glob_sql_internal (char *s, int ni, void *vibind);
int A4GLSQL_make_connection (char *server, char *uid_p, char *pwd_p);
void *A4GL_bind_datetime (void *ptr_to_dtime_var);
void *A4GL_bind_interval (void *ptr_to_ival);
void A4GL_decode_datetime (struct A4GLSQL_dtime *d, int *data);
int A4GL_inttoc (void *a1, void *b, int size);
char scratch[255][255];

#define FETCH_ABSOLUTE 		1
#define FETCH_RELATIVE 		2
#define DTYPE_DATE 			7
#define MAXCURSORS 			100
#define MAXPREPARE 			100
#define MAXCOLS 			100
#define MAX_NUM_PRECISION 	15
#define MAX_NUM_STRING_SIZE (MAX_NUM_PRECISION + 5)

int in_transaction = 0;

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

//NOTE: ./compilers/4glc/insert_curs.c:static int find_cursor(char *s)
static struct s_cid *A4GLSQL_find_cursor (char *cname);

//int A4GLSQL_get_datatype (char *db, char *tab, char *col);
//static int do_fake_transactions(void) ;
//int A4GL_dttoc (void *a, void *b, int size);
//void *A4GLSQL_prepare_sql_internal (char *s);
//void *A4GLSQL_prepare_glob_sql_internal (char *s, int ni, void *vibind);
//int A4GLSQL_make_connection (char *server, char *uid_p, char *pwd_p);
//void *A4GL_bind_datetime (void *ptr_to_dtime_var);
//void A4GL_decode_datetime (struct A4GLSQL_dtime *d, int *data);

//truct expr_str *A4GLSQL_get_validation_expr(char *tabname,char *colname) ;
struct expr_str_list *A4GL_add_validation_elements_to_expr (struct
							    expr_str_list
							    *ptr, char *val);
//now in a4gl_libaubit4gl.h void *A4GL_new_expr (char *value);
//now in a4gl_libaubit4gl.h void *A4GL_append_expr (struct expr_str *orig_ptr, char *value);
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
int ODBC_exec_stmt (SQLHSTMT *hstmt);
int ODBC_exec_select (SQLHSTMT hstmt);
int ODBC_exec_sql (UCHAR * sqlstr);
int ODBC_disconnect (void);
void ODBC_set_dbms_info (void);
int A4GL_sqlerrwith (int rc, HSTMT *h,int freeitonfail);
int A4GL_chk_need_blob (int rc, HSTMT hstmt);
int A4GL_chk_getenv (char *s, int a);
static unsigned long conv_sqldtype (int sqldtype, int sdim);
char *A4GL_decode_rc (int a);
RETCODE SQL_API A4GL_newSQLSetParam (SQLHSTMT hstmt, UWORD ipar, SWORD fCType,
				     SWORD fSqlType, UDWORD cbColDef,
				     SWORD ibScale, PTR rgbValue,
				     SDWORD FAR * pcbValue);
char *A4GL_ret_sql_err (void);
int print_err (HDBC hdbc, HSTMT hstmt);
long A4GL_describecolumn (SQLHSTMT hstmt, int colno, int type);
int set_stmt_options (char *cursname, char *opt, char *val);

#ifdef INCLUDEDATASOURCES
RETCODE SQL_API SQLDataSources (HENV henv, UWORD fDirection,
				UCHAR FAR * szDSN, SWORD cbDSNMax,
				SWORD FAR * pcbDSN, UCHAR FAR * szDescription,
				SWORD cbDescriptionMax,
				SWORD FAR * pcbDescription);
#endif

/* in sqlex.c */
extern int A4GL_set_blob_data (SQLHSTMT hstmt);
extern int A4GL_get_blob_data (struct fgl_int_loc *blob, HSTMT hstmt,
			       int colno);



/*
=====================================================================
                    Variables definitions
=====================================================================
*/

/* extern: */


/* static: */
static char sess_name[32] = "default";
//must be long enough to hold full path for SQLlite database file
//static char OldDBname[64] = "";
static char OldDBname[2048] = "";
static char dbms_name[1065] = "";
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
static SDWORD outlen[512];

SQLINTEGER nullval = SQL_NULL_DATA;


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
  union
  {
    char date_c[44];
    DATE_STRUCT date_ds;
  } uDate;
  long *ptr;
}
ACLDATE;

typedef struct tagACLDTIME
{
  union
  {
    char dtime_c[65];
    TIMESTAMP_STRUCT dtime_t;
  } dtime_u;
  struct A4GLSQL_dtime *ptr;
}
ACLDTIME;

typedef struct tagACLIVAL
{
  union
  {
    char ival_c[65];
  } ival_u;
  struct ival *ptr;
}
ACLIVAL;


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
  -1,
  SQL_C_DOUBLE,			/* as for decimal,  money != double */
  9999,
  -1,
  SQL_C_BINARY,
  SQL_C_BINARY,
  SQL_C_CHAR,			/* Varchar */
  SQL_C_CHAR			/* Interval */
};


struct s_extra_data
{
  void *nullptr;
};

struct s_stmtextra
{
  void *orig_stmt;
  struct s_extra_data *idata;
  int ni;
  struct s_extra_data *odata;
  int no;
};


struct s_stmtextra *extras = 0;
int nextras = 0;



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
  0,
  sizeof (double),
  0,
  -1,
  0,
  0,
  -1,
  20
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

static char *lower(char *s) {
	static char *last=0;
	if (last) free(last);
	last=strdup(s);
	A4GL_convlower(last);
	return last;
}

static int A4GL_has_cache_column (char *buff) {
	int r;
	 r=A4GL_has_pointer (lower(buff), CACHE_COLUMN);

	 return r;
}


static char *A4GL_find_cache_column(char *buff) {
	//char *buffx;
	char *ptr;
	ptr=A4GL_find_pointer (lower(buff), CACHE_COLUMN);
	return  ptr;
}

static void A4GL_add_cache_column(char*buff,char*def) {
  	A4GL_add_pointer (lower(buff), CACHE_COLUMN, strdup (def));
}


static void
reformat_sql (char *sql, struct BINDING *ibind, int nibind, char *fromwhere)
{
  int c;
  FILE *f;
  int a;
  char buff[20000];
  char sbuff[20000];
  int b;
  static int log_sql = -1;

  c = 0;
  b = 0;

  if (log_sql == -1)
    {
      log_sql = A4GL_isyes (acl_getenv ("LOGODBCSQL"));
    }

  if (!log_sql)
    return;


  if (first_open)
    {
      first_open = 0;
      f = fopen ("/tmp/log.sql", "w");
    }
  else
    {
      f = fopen ("/tmp/log.sql", "a");
    }
  if (ibind == 0)
    {
      if (!strchr (sql, '?'))
	{
	  fprintf (f, "%s;\n", sql);
	}
      fclose (f);
      return;
    }


  for (a = 0; a < strlen (sql); a++)
    {
      if (sql[a] != '?')
	{
	  buff[b++] = sql[a];
	  continue;
	}

      sprintf (sbuff, "'?%d'", ibind[c].dtype);

      if (ibind[c].dtype == DTYPE_CHAR)
	{
	  static char *buff = 0;
	  char *ptr;
	  int a = 0;
	  int b = 0;
	  ptr = ibind[c].ptr;

	  if (strchr (ptr, '\''))
	    {
	      buff = realloc (buff, (strlen (ibind[c].ptr) * 2) + 1);
	      for (a = 0; a < strlen (ptr); a++)
		{
		  if (ptr[a] != '\'')
		    {
		      buff[b++] = ptr[a];
		    }
		  else
		    {
		      buff[b++] = '\'';
		      buff[b++] = '\'';
		    }
		}
	      buff[b] = 0;

	      sprintf (sbuff, "'%s'", buff);
	    }
	  else
	    {
	      sprintf (sbuff, "'%s'", ptr);
	    }
	}


      if (ibind[c].dtype == DTYPE_SMINT)
	{
	  sprintf (sbuff, "%d", *(short *) ibind[c].ptr);
	}

      if (ibind[c].dtype == DTYPE_INT)
	{
	  sprintf (sbuff, "%ld", *(long *) ibind[c].ptr);
	}


      if (ibind[c].dtype == DTYPE_FLOAT)
	{
	  sprintf (sbuff, "%lf", *(double *) ibind[c].ptr);
	}

      if (ibind[c].dtype == DTYPE_SMFLOAT)
	{
	  sprintf (sbuff, "%f", *(float *) ibind[c].ptr);
	}

      if (ibind[c].dtype == DTYPE_DECIMAL)
	{
	  char *ptr;
	  int dtype;
	  dtype = ibind[c].dtype + ENCODE_SIZE (ibind[c].size);
	  A4GL_push_variable (ibind[c].ptr, dtype);
	  ptr = A4GL_char_pop ();
	  sprintf (sbuff, "%s", ptr);
	  free (ptr);
	}

      if (ibind[c].dtype == DTYPE_DATE)
	{
	  char *ptr;
	  A4GL_push_date (*(long *) ibind[c].ptr);
	  ptr = A4GL_char_pop ();
	  sprintf (sbuff, "'%s'", ptr);
	  free (ptr);
	}
      buff[b] = 0;
      strcat (buff, sbuff);
      b = strlen (buff);
      c++;
    }
  buff[b] = 0;
  fprintf (f, "%s;\n", buff);
  fclose (f);
}


static void
ensure_as_char (void)
{
  static int ensured = 0;
  if (ensured)
    return;
  ensured++;

  if (A4GLSQLCV_check_requirement ("DATE_AS_CHAR"))
    {
      date_as_char = 1;
    }
  if (A4GLSQLCV_check_requirement ("DTIME_AS_CHAR"))
    {
      dtime_as_char = 1;
    }

  if (A4GL_isno (acl_getenv ("DATE_AS_CHAR")))
    {
      date_as_char = 0;
    }
  if (A4GL_isno (acl_getenv ("DTIME_AS_CHAR")))
    {
      dtime_as_char = 0;
    }
}


static void
set_conv_4gl_to_c (void)
{

  ensure_as_char ();
  if (date_as_char)
    {
      conv_4gl_to_c[7] = SQL_C_CHAR;
      fgl_sizes[7] = 20;
    }
  else
    {
      conv_4gl_to_c[7] = SQL_C_DATE;
      fgl_sizes[7] = sizeof (long);
    }

  if (dtime_as_char)
    {
      conv_4gl_to_c[10] = SQL_C_CHAR;
      fgl_sizes[10] = 30;
    }
  else
    {

#ifdef SQL_C_DATETIME
      conv_4gl_to_c[10] = SQL_C_DATETIME;	// Was timestamp
      fgl_sizes[10] = 20;
#else
      conv_4gl_to_c[10] = SQL_C_TIMESTAMP;	// Was timestamp
      fgl_sizes[10] = 20;
#endif
    }
}


#ifdef IN_LIBAUBIT4GL
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
#endif

char *
A4GLSQLLIB_A4GLSQL_get_errmsg (int a)
{
  return 0;
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
A4GL_chk_rc_full (int rc, void *hstmt, char *c, int line, char *file)
{
  A4GL_debug ("Chk_rc_full : rc=%d (%s) stmt=%p c=%s line=%d file=%s", rc,
	      A4GL_decode_rc (rc), hstmt, c, line, file);

  if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)
    {
      A4GLSQL_set_status (0, 1);
      return;
    }


  if (hstmt)
    {
      if (rc == SQL_NO_DATA_FOUND)
	{
	  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (100);
	  /* A4GL_set_sqlca (hstmt, c, 0,0 ); *//* no error */
	  A4GLSQL_set_status (100, 1);
	  return;
	}
      A4GL_set_sqlca ((SQLHSTMT) hstmt, c, 0);
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
A4GL_newSQLSetParam (SQLHSTMT hstmt, UWORD ipar, SWORD fCType, SWORD fSqlType,
		     UDWORD cbColDef, SWORD ibScale, PTR rgbValue,
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

  A4GL_debug ("SQLBindParam %p %d %d %d %d %d %d %d", hstmt, ipar, fCType,
	      fSqlType, cbColDef, ibScale, rgbValue, pcbValue);


  rc = SQLBindParameter (hstmt, ipar, SQL_PARAM_INPUT, fCType, fSqlType, cbColDef, ibScale, rgbValue, 256, pcbValue);	// 3200

  chk_rc (rc, hstmt, "SQLBindParameter");

  A4GL_debug ("cbval was set to %d after call", cbval);

  A4GL_debug ("All done returning rc=%d\n", rc);
  return rc;
}


#ifdef USE_COUNT_QUERIES
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
#endif

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

  SWORD nin = 0;
  SWORD nout = 0;

  if (b == 0)
    return 0;


#ifdef DEBUG
  A4GL_debug ("In proc_bind...");
  A4GL_debug ("   Binding %p n=%d t=%c, stmt=%p", b, n, t, hstmt);
  for (a = 0; a < n; a++)
    {
      A4GL_debug ("%d=   dtype=%d ptr=%p size=%d", a, b[a].dtype, b[a].ptr,
		  b[a].size);
    }
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
	  A4GL_debug
	    ("Number of host variables does not A4GL_match %d (given) !=%d (in sql)",
	     n, nin);
#endif

	  return 0;
	}

#ifdef DEBUG
      A4GL_debug ("Looks like we have the right number..");
#endif

    }

  nout = -1;

  if (!A4GL_isyes (acl_getenv ("NOSCRATCHOBIND")))
    {
      if (t == 'o')
	{
	  A4GL_debug ("Getting num result cols");
	  rc = SQLNumResultCols (hstmt, &nout);
	  if (rc < 0)
	    {
	      A4GL_debug ("Getting num result cols rc=%d", rc);
	      nout = -1;
	    }
	}
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

  if (t == 'o')
    {
      if (!A4GL_isyes (acl_getenv ("NOSCRATCHOBIND")))
	{
	  if (nout != -1 && n < nout)
	    {
	      int b = 0;
	      struct BINDING bind;
	      A4GL_debug ("Binding scratch !!");
	      bind.ptr = scratch[b];
	      bind.dtype = 0;
	      bind.size = 254;
	      // We've got too few!
	      for (a = n + 1; a <= nout; a++)
		{
		  A4GL_debug ("Binding scratch @ %d", a);
		  A4GL_obind_column (a, &bind, hstmt);
		}
	    }
	}
    }
  return 1;
}

/**
 * Find a cursor in the pointer tree.
 *
 * @param cname The name of the cursor to be found.
 * @return A pointer to the cursor information.
 */
static struct s_cid *
A4GLSQL_find_cursor (char *cname)
{
  struct s_cid *ptr;

  ptr = (struct s_cid *) A4GL_find_pointer_val (cname, CURCODE);
  if (ptr)
    return ptr;
  A4GL_exitwith_sql ("Cursor not found");
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
void *
A4GLSQL_prepare_sql_internal (char *s)
{
  struct s_sid *sid;
  int rc;

#ifdef DEBUG
  A4GL_debug ("prepare_sql : %s", s);
#endif
  sid = acl_malloc2 (sizeof (struct s_sid));
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

  if (A4GL_new_hstmt ((SQLHSTMT *) & sid->hstmt))	/* warning: passing arg 1 of `new_hstmt' from incompatible pointer type */
    {
#ifdef DEBUG
      A4GL_debug ("after alloc sid->hstmt=%p", sid->hstmt);
#endif
      A4GL_assertion (sid->hstmt == 0, "No statement");
      rc = SQLPrepare ((SQLHSTMT) sid->hstmt, sid->select, SQL_NTS);
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


#ifdef NDEF
/**
 * Execute an SQL statement.
 *
 * @param pname  The prepared statement name.
 * @param ni Number of elements in the input bind.
 * @param ibind The input binding array used.
 * @return
 */
int
A4GLSQL_execute_sql (char *pname, int ni, void *vibind)
{
  struct s_sid *sid;
  struct BINDING *ibind;
  ibind = vibind;

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

  A4GL_proc_bind (ibind, ni, 'i', (SQLHSTMT) sid->hstmt);
  reformat_sql (sid->select, ibind, ni, "1");


#ifdef DEBUG
  A4GL_debug ("Bound any data... ni=%d", ni);
#endif
  return ODBC_exec_prepared_sql ((SQLHSTMT) sid->hstmt);
}
#endif

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
void *
A4GLSQLLIB_A4GLSQL_prepare_select_internal (void *vibind, int ni, void *vobind, int no, char *s,char *uniqid)	/* mja */
{
  struct s_sid *sid;
  int rc;
  struct BINDING *ibind;
  struct BINDING *obind;
  ibind = vibind;
  obind = vobind;

  sid = acl_malloc2 (sizeof (struct s_sid));
  sid->select = strdup (s);

  // I'm going to copy the bindings....

  sid->ibind = malloc (sizeof (struct BINDING) * ni);
  memcpy (sid->ibind, ibind, sizeof (struct BINDING) * ni);

  sid->obind = malloc (sizeof (struct BINDING) * no);
  memcpy (sid->obind, obind, sizeof (struct BINDING) * no);

  sid->ni = ni;
  sid->no = no;

  A4GLSQL_set_status (0, 1);

  if (A4GL_new_hstmt ((SQLHSTMT *) & sid->hstmt))
    {
#ifdef DEBUG
      A4GL_debug ("after alloc sid->hstmt=%p", sid->hstmt);
      A4GL_debug ("statement = %s", sid->select);
#endif
      A4GL_assertion (sid->hstmt == 0, "No statement");
      rc = SQLPrepare ((SQLHSTMT) sid->hstmt, sid->select, SQL_NTS);
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
	  sid->hstmt = 0;
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
void *
A4GLSQL_prepare_glob_sql_internal (char *s, int ni, void *vibind)	/* mja */
{
  struct s_sid *sid;
  struct BINDING *ibind;
  ibind = vibind;
  A4GL_debug ("prepare_glob_sql '%s' %p %d", s, ibind, ni);
  sid = acl_malloc2 (sizeof (struct s_sid));
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

  if (A4GL_new_hstmt ((SQLHSTMT *) & sid->hstmt))
    {
#ifdef DEBUG
      A4GL_debug ("after alloc sid->hstmt=%p", sid->hstmt);
      A4GL_debug ("Preparing %p %s\n", sid->hstmt, sid->select);
#endif
      A4GL_assertion (sid->hstmt == 0, "No statement");
      rc = SQLPrepare ((SQLHSTMT) sid->hstmt, sid->select, SQL_NTS);
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
A4GLSQLLIB_A4GLSQL_declare_cursor (int upd_hold, void *vsid, int scroll,
				   char *cursname)
{
#if (ODBCVER >= 0x0300)
  //static SQLUINTEGER is_scrollable=SQL_SCROLLABLE;
  //static SQLUINTEGER isnot_scrollable=SQL_NONSCROLLABLE;
#endif
  struct s_sid *nsid;
  struct s_cid *cid;
  struct s_sid *sid;
  sid = vsid;

  if (sid == 0)
    {
      A4GL_exitwith ("Can't declare cursor for non-prepared statement");
      return 0;
    }
#ifdef DEBUG
  A4GL_debug ("Declaring cursor");
  A4GL_debug ("upd_hold=%d sid=%p scroll=%d cursname=%s", upd_hold, sid,
	      scroll, cursname);
#endif

  cid = acl_malloc2 (sizeof (struct s_cid));

  nsid = acl_malloc2 (sizeof (struct s_sid));
  nsid->hstmt = 0;
  A4GL_debug ("Malloced nsid & cid");
#ifdef DEBUG
  A4GL_debug ("sid=%p", sid);
#endif
  cid->statement = nsid;
  cid->hstmt = 0;
  cid->mode = upd_hold + scroll * 256;
  nsid->ibind = sid->ibind;
  nsid->hstmt = sid->hstmt;
  A4GL_debug ("nsid->hstmt=%p", sid->hstmt);
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
  A4GL_new_hstmt ((SQLHSTMT *) & nsid->hstmt);
#ifdef DEBUG
  A4GL_debug ("Got statement");
#endif



  if (scroll)
    {
#ifdef DEBUG
      A4GL_debug ("Setting dynamic cursor");
#endif

#if (ODBCVER >= 0x0300) && !PGODBC
      if (!A4GL_isyes (acl_getenv ("NO_ATTR_CURSOR")))
	{
	  A4GL_debug ("Setting cursor type to scrollable");
	  rc =
	    SQLSetStmtAttr ((SQLHSTMT) nsid->hstmt, SQL_ATTR_CURSOR_TYPE,
			    (SQLPOINTER) SQL_CURSOR_STATIC, 0);
	  chk_rc (rc, nsid->hstmt, "SQLSetStmtAttr - CURSOR TYPE");
	  A4GL_debug ("set stmt attr rc=%d", rc);

	  rc =
	    SQLSetStmtAttr ((SQLHSTMT) nsid->hstmt,
			    SQL_ATTR_CURSOR_SCROLLABLE,
			    (SQLPOINTER) SQL_SCROLLABLE, 0);
	  chk_rc (rc, nsid->hstmt, "SQLSetStmtAttr - CURSOR SCROLLABLE");
	  A4GL_debug ("set stmt attr rc=%d", rc);

	  if (rc == -1)
	    {			// Well - we tried...
	      rc = 0;
	    }

	  if (rc == 1)
	    {
	      //SQLINTEGER bl;
	      SQLINTEGER sl;
	      SQLUINTEGER r = 99;
	      SQLUINTEGER r2 = 99;
	      SQLGetStmtAttr (nsid->hstmt, SQL_ATTR_CURSOR_SCROLLABLE, &r,
			      sizeof (r), &sl);
	      SQLGetStmtAttr (nsid->hstmt, SQL_ATTR_CURSOR_TYPE, &r2,
			      sizeof (r2), &sl);
	      // It didn't like that ?
	      A4GL_debug ("Asked for %x - got %x %x", SQL_SCROLLABLE, r, r2);
	    }
	}
      else
	{
	  rc =
	    SQLSetStmtOption ((SQLHSTMT) nsid->hstmt, SQL_CURSOR_TYPE,
			      SQL_CURSOR_STATIC);
	}
#else
      rc =
	SQLSetStmtOption ((SQLHSTMT) nsid->hstmt, SQL_CURSOR_TYPE,
			  SQL_CURSOR_STATIC);
#endif

      if (rc == 1)
	rc = 0;
      chk_rc (rc, nsid->hstmt, "SQLSetStmtOption SCROLL_STATIC");
      A4GL_debug (" rc = %d\n", rc);
    }
#ifdef DEBUG
  A4GL_debug ("Returning %p", cid);
#endif
  SQLSetCursorName (nsid->hstmt, cursname, SQL_NTS);
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
A4GLSQLLIB_A4GLSQL_execute_implicit_sql (void *vsid, int singleton)
{
  struct s_sid *sid;

  int rc = 0;
  sid = vsid;
  if (sid == 0)
    {
#ifdef DEBUG
      A4GL_debug ("A4GLSQL_execute_implicit_sql: internal error sid=0");
#endif
      return 0;
    }
#ifdef DEBUG
  A4GL_debug ("A4GLSQL_execute_implicit_sql: no=%d ni=%d sql=%s", sid->no,
	      sid->ni, sid->select);
  A4GL_debug ("Calling proc_bind()");
#endif

  A4GL_proc_bind (sid->obind, sid->no, 'o', (SQLHSTMT) sid->hstmt);
  A4GL_proc_bind (sid->ibind, sid->ni, 'i', (SQLHSTMT) sid->hstmt);

#ifdef DEBUG
  A4GL_debug ("Calling ODBC_exec_stmt()");
#endif



  reformat_sql (sid->select, sid->ibind, sid->ni, "2");

  rc = ODBC_exec_stmt (&sid->hstmt);
  A4GL_debug ("Got rc as %d\n", rc);

  if (rc && singleton)
    {
      /* free up malloc'ed memory */
      SQLFreeStmt ((SQLHSTMT) sid->hstmt, SQL_DROP);
      free_extra (sid->hstmt);
      sid->hstmt = 0;
      free (sid->select);
      sid->select = 0;

      // Should probably free the obind too..
      // leave that for later...
      if (sid->ibind)
	free (sid->ibind);


      free (sid);
    }


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
A4GLSQLLIB_A4GLSQL_execute_implicit_select (void *vsid, int singleton)
{
  int a;
  struct s_sid *sid;
  SWORD nresultcols;
  sid = vsid;

  if (sid == 0)
    {
#ifdef DEBUG
      A4GL_debug
	("A4GLSQL_execute_implicit_select got sid == 0, returning -1");
#endif
      return -1;
    }
#ifdef DEBUG
  A4GL_debug ("Executing immediate : %s", sid->select);
#endif
  A4GL_proc_bind (sid->obind, sid->no, 'o', (SQLHSTMT) sid->hstmt);
  A4GL_proc_bind (sid->ibind, sid->ni, 'i', (SQLHSTMT) sid->hstmt);
#ifdef DEBUG
  A4GL_debug (" Bound data ... ni=%d no=%d", sid->ni, sid->no);
#endif





  reformat_sql (sid->select, sid->ibind, sid->ni, "3");


  a = ODBC_exec_select ((SQLHSTMT) sid->hstmt);

  nresultcols = 0;
  SQLNumResultCols ((SQLHSTMT) sid->hstmt, &nresultcols);


  if (a && a4gl_status != 100)
    {
      A4GL_debug ("Calling post_fetch_proc_bind");
      A4GL_post_fetch_proc_bind (sid->obind, sid->no,
				 (SQLHSTMT) & sid->hstmt);
      if (nresultcols && nresultcols != sid->no)
	{
	  strcpy (a4gl_sqlca.sqlawarn, "       ");
	  a4gl_sqlca.sqlawarn[0] = 'W';
	  a4gl_sqlca.sqlawarn[3] = 'W';
	}
    }

  if (a)
    {
      SQLFreeStmt ((SQLHSTMT) sid->hstmt, SQL_DROP);
      free_extra (sid->hstmt);
      sid->hstmt = 0;
    }
  else
    {
      A4GL_debug ("a not set");
    }

  if (singleton)
    {
      free (sid->select);

      if (sid->obind)
	free (sid->obind);
      if (sid->ibind)
	free (sid->ibind);
      free (sid);
    }

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
A4GLSQLLIB_A4GLSQL_open_cursor (char *s, int ni, void *ibind)
{
  struct s_cid *cid;
  char *curs;
  SQLINTEGER rowcount;
  int save_ni = -1;
  int rc;
  struct s_sid *sid;
  struct BINDING *save_ibind = 0;
  int rc2;

  A4GL_debug ("XXX s=%s ni=%d ibind=%p", s, ni, ibind);


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

      A4GLSQLLIB_A4GLSQL_close_cursor (s);
    }

  sid = cid->statement;

  A4GL_debug ("Select ='%s'", sid->select);
  if (strncasecmp (sid->select, "INSERT", 6) == 0
      || strncasecmp (sid->select, " INSERT", 7) == 0)
    {
      A4GL_assertion (cid->statement->hstmt == 0, "No statement");
      rc =
	SQLPrepare ((SQLHSTMT) cid->statement->hstmt, cid->statement->select,
		    SQL_NTS);
      chk_rc (rc, cid->statement->hstmt, "SQLPrepare");
      return 0;
    }


  A4GL_debug ("XXX s=%s ni=%d ibind=%p", s, ni, ibind);
  if (ni)
    {
      // They've used a value on the OPEN
      save_ni = cid->statement->ni;
      save_ibind = cid->statement->ibind;
      cid->statement->ni = ni;
      cid->statement->ibind = (struct BINDING *) ibind;
    }


  A4GL_assertion (cid->statement->hstmt == 0, "No statement");
  rc =
    SQLPrepare ((SQLHSTMT) cid->statement->hstmt, cid->statement->select,
		SQL_NTS);
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
      A4GL_debug ("Too many or too few host variables ni=%d no expected=%d",
		  ni, cid->statement->ni);
#endif
      if (save_ni != -1)
	{
	  cid->statement->ni = save_ni;
	  cid->statement->ibind = save_ibind;
	}

      A4GL_exitwith ("Too many or too few host variables");
      return 0;
    }

#ifdef DEBUG
  A4GL_debug ("Host variables OK");
#endif

  curs = cid->statement->select;
  a4gl_status = 0;




  A4GL_debug ("XXX s=%s ni=%d ibind=%p", s, ni, ibind);


  if (ni == 0)
    {				/* No USING on the open.. */
      reformat_sql (cid->statement->select, cid->statement->ibind,
		    cid->statement->ni, "4");
      A4GL_proc_bind (cid->statement->ibind, cid->statement->ni, 'i',
		      (SQLHSTMT) cid->statement->hstmt);

    }
  else
    {
#ifdef ndef
      struct BINDING *b;
      int a;
#ifdef DEBUG
      A4GL_debug ("We dont have a binding - but I'll make one");
#endif
      b = acl_malloc2 (sizeof (struct BINDING) * ni);

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
#endif

      A4GL_proc_bind (ibind, ni, 'i', (SQLHSTMT) cid->statement->hstmt);
      reformat_sql (cid->statement->select, ibind, ni, "5");

    }


  if (a4gl_status != 0)
    {
      if (save_ni != -1)
	{
	  cid->statement->ni = save_ni;
	  cid->statement->ibind = save_ibind;
	}

      return 0;
    }

#ifdef DEBUG
  A4GL_debug ("Executing statement %s\n", curs);
  A4GL_debug ("cid=%p cid->hstmt=%p", cid, cid->hstmt);
#endif

  if (cid->hstmt != 0)
    {
      if (save_ni != -1)
	{
	  cid->statement->ni = save_ni;
	  cid->statement->ibind = save_ibind;
	}

      A4GL_exitwith ("Cursor already open");
      return 0;
    }
  else
    {
      cid->hstmt = cid->statement->hstmt;
      A4GL_debug ("cid->hstmt=%p", cid->hstmt);
    }
  /* Execute the SQL statement. */

#ifdef DEBUG
  A4GL_debug ("Setting cursor type");
  A4GL_debug ("Opening cursor %p", cid->statement->hstmt);
#endif

  rc = SQLExecute ((SQLHSTMT) cid->statement->hstmt);	//Reformatted
  chk_rc (rc, cid->statement->hstmt, "SQLExecute");
  rc2 = A4GL_chk_need_blob (rc, (SQLHSTMT) & cid->statement->hstmt);

#ifdef DEBUG
  A4GL_debug ("Executed...");
  A4GL_debug ("Open Cursor hstmt=%p", cid->statement->hstmt);
  A4GL_debug ("OBind...");
#endif
  A4GL_proc_bind (cid->statement->obind, cid->statement->no, 'o',
		  (SQLHSTMT) cid->statement->hstmt);
#ifdef DEBUG
  A4GL_debug ("IBind...");
  A4GL_debug ("After open cursor");
#endif

  /* A4GL_set_sqlca (cid->statement->hstmt, "Open Cursor", 1); */
  if (rc != SQL_SUCCESS)
    {
      int a;
      a = A4GL_sqlerrwith (rc,  & cid->statement->hstmt,1);
      cid->statement->hstmt = 0;
      if (save_ni != -1)
	{
	  cid->statement->ni = save_ni;
	  cid->statement->ibind = save_ibind;
	}

      return a;
    }
  A4GLSQL_set_status (0, 1);
  rc = SQLRowCount (cid->statement->hstmt, &rowcount);

  /* chk_rc (rc, cid->statement->hstmt, "SQLRowCount"); */
  a4gl_sqlca.sqlerrd[1] = rowcount;
  if (save_ni != -1)
    {
      cid->statement->ni = save_ni;
      cid->statement->ibind = save_ibind;
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
A4GLSQLLIB_A4GLSQL_fetch_cursor (char *cursor_name,
				 int fetch_mode, int fetch_when, int nibind,
				 void *vibind)
{
  struct s_cid *cid;
  int nfields;
  int rc;
  SDWORD nr;
  int use_nbind;
  struct BINDING *use_binding;
  int mode = 0;
  struct BINDING *ibind;
  int use_extended_fetch = -1;


  ibind = vibind;
  a4gl_sqlca.sqlerrd[2] = 0;

#ifdef DEBUG
  A4GL_debug ("In fetch_cursor (%s,%d,%d,%d,%p)", cursor_name, fetch_mode,
	      fetch_when, nibind, ibind);
  A4GL_debug ("before find cursor");
#endif

  cid = A4GLSQL_find_cursor (cursor_name);
  if (cid == 0)
    {
      A4GL_exitwith_sql ("Cursor not found");
      return 0;
    }
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
      A4GL_proc_bind (ibind, nibind, 'o', (SQLHSTMT) cid->statement->hstmt);
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


  if (use_extended_fetch == -1)
    {
      use_extended_fetch = 0;
      if (A4GL_chk_getenv ("EXTENDED_FETCH", TRUE))
	use_extended_fetch = 1;
      if (strcmp ("INGRES", A4GLSQL_dbms_dialect ()) == 0)
	use_extended_fetch = 0;
    }

  A4GL_debug ("use_Extended_fetch=%d\n", use_extended_fetch);

  if (use_extended_fetch == 1 && mode != SQL_FETCH_NEXT)
    {

#ifdef DEBUG
      A4GL_debug ("Calling SQLextended/SQLFetchScroll fetch with %p %d %d",
		  cid->statement->hstmt, mode, fetch_when);
#endif
      nr = 1;


#if (ODBCVER >= 0x0300) && !PGODBC

      A4GL_debug ("FetchScroll %d %d", mode, fetch_when);

      rc =
	SQLFetchScroll ((SQLHSTMT) cid->statement->hstmt, mode, fetch_when);
#else
      A4GL_debug ("ExtendedFetch");
      {
	UWORD nrs[1000];
	rc =
	  SQLExtendedFetch ((SQLHSTMT) cid->statement->hstmt, mode,
			    fetch_when, &nr, &nrs[0]);
      }
#endif





      chk_rc (rc, cid->statement->hstmt, "SQLExtendedFetch");
    }
  else
    {
      A4GL_debug ("Normal fetch");
      if (mode != SQL_FETCH_NEXT)
	{
	  printf ("WARNING: Fetching next and not supposed to..\n");
	}
      rc = SQLFetch ((SQLHSTMT) cid->statement->hstmt);
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
  a4gl_sqlca.sqlerrd[2] = 1;

  /*
     if (rc != SQL_SUCCESS && rc != SQL_NO_DATA_FOUND)
     {
     A4GL_set_sqlca (cid->statement->hstmt, "ODBC_exec_select : After SQLFetch", 0);
     }
   */

/*  res = PQexec (conn, cmd); exec */

  A4GL_debug ("use_binding...");
  A4GL_debug ("Calling post_fetch_proc_bind");
  A4GL_post_fetch_proc_bind (use_binding, use_nbind,
			     (SQLHSTMT) & cid->statement->hstmt);
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
A4GLSQLLIB_A4GLSQL_init_connection_internal (char *dbName_f)
{
  char empty[10] = "None";
  char dbName[2048];
  char *u, *p;
  HDBC *hh = 0;
  int rc = 0;
  char uname_acl[256];
  char passwd_acl[256];


  strcpy (dbName, dbName_f);
  A4GL_trim (dbName);

/* This section does not apply to "real" SQLite odbc driver since it will use odbc.ini
 settings to look for SQLite database file
#ifdef SQLITEODBC
*/
#ifdef SQLITE_DIRECT
  {
    char a[128], b[128], tmp[2048];
    char *FullPathDBname;
    char DATABASE[128];
    A4GL_debug ("SQLITE special...");

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
    if (a[0] == 0)
      {
	SPRINTF1 (tmp, "%s.db", dbName);
	A4GL_debug ("Added .db file name extension, dbName=%s", tmp);
      }
    else
      {
	strcpy (tmp, dbName);
      }
    //store DB file name as per DATABASE statement
    SPRINTF1 (DATABASE, "%s", tmp);
    //Find full path to the SQLite database file, use DBPATH
    FullPathDBname = A4GL_fullpath_dbpath ((char *) tmp);

    if (FullPathDBname)
      {
	strcpy (tmp, FullPathDBname);
	//strcpy (dbName,tmp);

	//add db file name as per DATABASE statement to discovered path
	SPRINTF1 (dbName, "%s", tmp);
	A4GL_debug ("Found SQLite db in '%s'", dbName);
      }
    else
      {
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
	A4GL_debug ("SQLite database file not found in DBPATH='%s'",
		    acl_getenv ("DBPATH"));
	A4GL_exitwith ("SQLite database file not found in DBPATH");
      }
  }
#endif

#ifdef DEBUG
  A4GL_debug ("A4GLSQL_init_connection(dbName='%s')", dbName);
#endif

  if (strcmp (dbName, OldDBname) == 0)
    {
#ifdef DEBUG
      A4GL_debug ("Already connected - ignored.");
#endif
      return 0;
    }

  /* free up the current default connection, if there is one */
  if (A4GL_has_pointer ("default", SESSCODE))
    {
      hh = A4GL_find_pointer_val ("default", SESSCODE);
      rc = SQLFreeConnect ((SQLHSTMT) * hh);
      chk_rc (rc, 0, "SQLFreeConnect");
    }


  if (A4GL_sqlid_from_aclfile (dbName, uname_acl, passwd_acl))
    {
      A4GL_debug ("Found in ACL File...");
      u = 0;
      p = 0;
      u = acl_getenv_only ("SQLUID");
      p = acl_getenv_only ("SQLPWD");
      if (u && strlen (u) == 0)
	u = 0;
      if (p && strlen (p) == 0)
	p = 0;
      if (!u || !p)
	{
	  u = uname_acl;
	  p = passwd_acl;
	}
    }
  else
    {

      A4GL_debug ("**not** found in ACL File...");
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
    }

#ifdef DEBUG
  A4GL_debug ("u=%s p=%s", u, p);
#endif



  if (A4GLSQL_make_connection (dbName, u, p))
    {
      /* do we have an existing pointer to default */
      hh = A4GL_find_pointer_val ("default", SESSCODE);
      if (hh == 0)
	{
	  hh = acl_malloc2 (sizeof (HDBC));
	}
      *hh = hdbc;
      A4GL_add_pointer ("default", SESSCODE, hh);




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
 * Get the current SQL error message.
 *
 * @return The contents of sqlca.sqlerrm.
 */
char *
A4GLSQLLIB_A4GLSQL_get_sqlerrm (void)
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
void
A4GLSQLLIB_A4GLSQL_free_cursor (char *cname)
{
  struct s_cid *ptr;

  ptr = A4GL_find_pointer_val (cname, CURCODE);
  if (ptr == 0)
    {
      A4GL_exitwith ("Can't free cursor thats not been defined");
      return;
    }
  if (ptr->hstmt)
    {
      SQLFreeStmt ((SQLHSTMT) ptr->hstmt, SQL_DROP);
      free_extra (ptr->hstmt);
      ptr->hstmt = 0;
      chk_rc (rc, 0, "SQLFreeStmt");
    }
  free (ptr->statement->select);
  free (ptr->statement);
  A4GL_del_pointer (cname, CURCODE);
  A4GLSQL_set_status (0, 1);
  return;
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
A4GLSQLLIB_A4GLSQL_close_cursor (char *cname)
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
      SQLFreeStmt ((SQLHSTMT) ptr->hstmt, SQL_CLOSE);
      free_extra (ptr->hstmt);
      ptr->hstmt = 0;
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
    case 0:
    case SQL_CHAR:
    case SQL_VARCHAR:
      A4GL_debug ("Character string");
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

    case 91:			/* date */
      return 10;
    case 92:			/* time */
      return 8;
    case 93:			/* datetime/timestamp */
      return collen;

    case 10:
      return 8;

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
A4GLSQL_make_connection (char *server, char *uid_p, char *pwd_p)
{
  RETCODE rc;
  char uid[256] = "";
  char pwd[256] = "";
  //RETCODE xrc;

#ifdef DEBUG
  A4GL_debug ("A4GLSQL_make_connection .. server=%s uid_p=%s pwd_p=%s",
	      server, uid_p, pwd_p);
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

  initenv ();
  rc = SQLAllocConnect (henv, &hdbc);
  chk_rc (rc, 0, "SQLAllocConnect");
#ifdef DEBUG
  A4GL_debug ("SQLAllocConnect returns %d %p", rc, hdbc);
  A4GL_debug ("Connecting to >%s< as >%s</>%s<", server, uid, pwd);
#endif



  // Do we actually need this ?
  if (A4GL_isyes (acl_getenv ("AUTOCOMMIT")))
    {
      rc = SQLSetConnectOption (hdbc, SQL_AUTOCOMMIT, 1);
    }
  if (A4GL_isno (acl_getenv ("AUTOCOMMIT")))
    {
      rc = SQLSetConnectOption (hdbc, SQL_AUTOCOMMIT, 0);
    }
  chk_rc (rc, 0, "SQLSetConnectOption");

  rc=0;
#if (ODBCVER >= 0x0300)
#ifdef SQL_CUR_USE_IF_NEEDED
  A4GL_debug ("Cursor use if needed");

  if (!A4GL_isno(acl_getenv("SETODBCCURSORS")))  {
  if (A4GL_isyes (acl_getenv ("ALWAYS_ODBC_CURSOR")))
    {
      		rc = SQLSetConnectAttr (hdbc, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER) SQL_CUR_USE_ODBC, (SQLINTEGER) 0);
    }
  else
    {
      		rc = SQLSetConnectAttr (hdbc, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER) SQL_CUR_USE_IF_NEEDED, (SQLINTEGER) 0);
    }
  }
#else
  if (!A4GL_isno(acl_getenv("NOSETODBCCURSORS")))  {
  A4GL_debug ("Cursor use odbc");
  //rc = SQLSetConnectOption(hdbc, SQL_ODBC_CURSORS,SQL_CUR_USE_ODBC );
  rc =
    SQLSetConnectAttr (hdbc, SQL_ATTR_ODBC_CURSORS,
		       (SQLPOINTER) SQL_CUR_USE_ODBC, (SQLINTEGER) 0);
  }
#endif
#else
  A4GL_debug ("ConnectOption - not ConnectAttr");
  rc = SQLSetConnectOption (hdbc, SQL_ODBC_CURSORS, SQL_CUR_USE_IF_NEEDED);
#endif


  chk_rc (rc, 0, "SQLSetConnectOption");




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

  A4GLSQLCV_load_convert ("INFORMIX", dbms_dialect);

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
A4GLSQLLIB_A4GLSQL_dbms_dialect (void)
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
A4GLSQLLIB_A4GLSQL_dbms_name (void)
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
  short len = 0;
  memset (dbms_name, 0, 64);
  rc = SQLGetInfo (hdbc, SQL_DBMS_NAME, dbms_name, (short) 64, &len);


  A4GL_debug ("DIALECT : %s\n", dbms_name);
  strcpy (dbms_dialect, "");

  if (strncasecmp (dbms_name, "informix", 8) == 0)
    {
      strcpy (dbms_dialect, "INFORMIX");
      return;
    }

  if (strncasecmp (dbms_name, "sapdb", 5) == 0)
    {
      strcpy (dbms_dialect, "SAPDB");
      return;
    }

  if (strncasecmp (dbms_name, "postgr", 6) == 0)
    {
      strcpy (dbms_dialect, "POSTGRESQL");
      return;
    }
  if (strncasecmp (dbms_name, "POSTGRESQL", 6) == 0)
    {
      strcpy (dbms_dialect, "POSTGRESQL");
      return;
    }

  if (strncasecmp (dbms_name, "oracl", 5) == 0)
    {
      strcpy (dbms_dialect, "ORACLE");
      return;
    }

  if (strncasecmp (dbms_name, "mysql", 5) == 0)
    {
      strcpy (dbms_dialect, "MYSQL");
      return;
    }

  if (strncasecmp (dbms_name, "SQLite", 6) == 0)
    {
      strcpy (dbms_dialect, "SQLITE");
      return;
    }
  if (strncasecmp (dbms_name, "INGRES", 6) == 0)
    {
      strcpy (dbms_dialect, "INGRES");
      return;
    }
  if (strncasecmp (dbms_name, "DB2", 3) == 0)
    {
      strcpy (dbms_dialect, "DB2");
      return;
    }
  if (strncasecmp (dbms_name, "SQLDS/VM", 8) == 0)
    {
      strcpy (dbms_dialect, "DB2VM");
      return;
    }
  if (strncasecmp (dbms_name, "Microsoft SQL Server",20) == 0)
    {
      strcpy (dbms_dialect, "SQLSERVER");
      return;
    }



  strcpy (dbms_dialect, dbms_name);
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

  if (A4GL_new_hstmt ((SQLHSTMT *) & hstmt))
    {

      reformat_sql (sqlstr, 0, 0, "6");

      rc = SQLExecDirect ((SQLHSTMT) hstmt, sqlstr, SQL_NTS);
      chk_rc (rc, 0, "SQLExecDirect");
#ifdef DEBUG
      A4GL_debug ("SQLExecDirect returns %d", rc);
#endif
      if (rc != SQL_SUCCESS)
	{
	  int a;
	  a = A4GL_sqlerrwith (rc, &hstmt,1);
	  
	  hstmt = 0;
	  return a;
	}

      rc = SQLFreeStmt ((SQLHSTMT) hstmt, SQL_DROP);
      free_extra (hstmt);
      hstmt = 0;
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
ODBC_exec_stmt (SQLHSTMT *ptr_hstmt)
{
  int rc1;
  int rc2;
  int fake_tr = 0;

  SQLINTEGER rowcount;


  if (ptr_hstmt == 0)
    {
      return 0;
    }


#ifdef DEBUG
  A4GL_debug ("In ODBC_exec_stmt %p", *ptr_hstmt);
#endif
  if (*ptr_hstmt == 0)
    {
      return 0;
    }


  if (do_fake_transactions ())
    {
      // if we're not already in a transaction - start one
      if (!in_transaction)
	{
	  fake_tr = 1;
	  A4GLSQL_commit_rollback (-1);
	}
    }


  rc1 = SQLExecute ((SQLHSTMT) *ptr_hstmt);	// Reformatted in caller
  chk_rc (rc1, *ptr_hstmt, "SQLExecute2");

#ifdef DEBUG
  A4GL_debug ("SQLExecute returns %d\n", rc);
#endif

// And finish it
  if (fake_tr)
    {
      if (rc1 == SQL_SUCCESS || rc1 == SQL_SUCCESS_WITH_INFO)
	A4GLSQL_commit_rollback (1);
      else
	A4GLSQL_commit_rollback (0);
    }



  if (rc1==SQL_SUCCESS) {
  rc2 = A4GL_chk_need_blob (rc1, *ptr_hstmt);

#ifdef DEBUG
  A4GL_debug ("chk_need_blob returns %d\n", rc);
#endif

  chk_rc (rc2, *ptr_hstmt, "SQLExecute2");
  }

#ifdef DEBUG
  A4GL_debug ("chk_rc: Result=%d (Success==%d)", rc, SQL_SUCCESS);
#endif

  if (rc1 != SQL_SUCCESS)
    {
      int a;
      a = A4GL_sqlerrwith (rc1, ptr_hstmt,0);
      *ptr_hstmt=0;
      return a;

    }
  if (SQLRowCount ((SQLHSTMT) *ptr_hstmt, &rowcount) == SQL_SUCCESS)
    {
      a4gl_sqlca.sqlerrd[2] = rowcount;
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
A4GL_sqlerrwith (int rc, HSTMT *h,int freeonfail)
{
  /* A4GL_set_sqlca (h, "From sqlerrwith", 0); */
  SQLFreeStmt ((SQLHSTMT) *h, SQL_DROP);
  free_extra (*h);
  *h = 0;
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

*************** Then use a different name...... - Dont just comment it out.....


make[2]: *** [sql.o] Error 1
*/
  SDWORD xerrno = 0;
  SWORD xerrno2 = 0;
  SDWORD rowcount = 0;
  RETCODE rc;
  memset (s1, 0, 80);
  memset (s2, 0, 255);
  A4GL_set_lasterrorstr ("");
  strcpy (s1, "00000");

  /* chk_rc (rc, hstmt, "SQLRowCount"); */
#ifdef DEBUG
  A4GL_debug ("set_sqlca...%p %p %p", henv, hdbc, hstmt);
  A4GL_debug ("set sqlca caused by %s", s);
#endif
  rc = -1;
  // Due to the above line the condition below is always true. Is that correct?
  if (rc != 0 && rc != 100)
    {
      A4GL_debug ("Calling SQLError %p %p %p rc=%d", henv, hdbc, hstmt, rc);
      rc = SQLError (henv, hdbc, (SQLHSTMT) hstmt, s1, &xerrno, s2, 500, &xerrno2);	//warning: passing arg 5 of `SQLError' from incompatible pointer type
      A4GL_debug ("rc=%d\n", rc);
      if (xerrno > 0 && xerrno != 100)
	xerrno = 0 - xerrno;
#ifdef DEBUG
      if (strcmp (s1, "S1010") == 0)
	{			// Function sequence error
		if (A4GL_isyes(acl_getenv("ASSERTONFUNCSEQERR"))) {
	  		A4GL_assertion (1, "Function sequence error ?");
	  	}
	}

      if (strcmp (s1, "01S02") == 0)
	{			// option changed 
	  A4GL_debug ("Option value changed");
	  strcpy (s1, "");
	}
      A4GL_debug ("After SQL Error %d %s %s\n%x", xerrno, s1, s2, xerrno2);
#endif
      if (rc == 100) // error occured but driver did not provide an info record
	  	     // (this part of code is needed when using somewhat broken (?) ODBC drivers)
      {
	  strcpy (s1, "HY000");
	  sprintf(s2, "Error occured, but SQLError ODBC function returned no error record xerrno=%i xerrno2=%i, assuming HY000", xerrno, xerrno2);
	  xerrno = -1;
	  xerrno2 = 0;
      }
      if (strlen (s1) == 0)
	strcpy (s1, "00000");

      strcpy (a4gl_sqlca.sqlstate, s1);

      if (strcmp (s1, "00000") == 0)
	{
	  xerrno = 0;
	  xerrno2 = 0;
	}

      if ((strcmp (s1, "00000") != 0 && xerrno == 0)
	  || (s1[0] == '0' && s1[1] == '1'))
	{
#ifdef DEBUG
	  A4GL_debug ("Got %s as state", s1);
#endif
	  if (xerrno == 0)
	    {
	      xerrno = -101;
	      xerrno2 = 0;
	    }
	}

#ifdef DEBUG
      A4GL_debug ("'%s' '%s' (%d %d)", s1, s2, xerrno, xerrno2);
#endif
      strncpy (a4gl_sqlca.sqlerrm, s2, 72);
      A4GLSQL_set_status (xerrno, 1);
#ifdef DEBUG
      A4GL_debug ("Setting lasterrorstr to '%s'", s2);
#endif
      A4GL_set_lasterrorstr (s2);
    }


  if (rc == 0 || rc == 100)
    {
      if (rc == 100)
	rowcount = 0;
      else
	{
#ifndef PGODBC
	  rc = SQLRowCount ((SQLHSTMT) hstmt, &rowcount);
#endif
	}
      a4gl_sqlca.sqlerrd[1] = rowcount;
    }
  else
    {
      a4gl_sqlca.sqlerrd[1] = 0;
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
  void *ptr_to_use;
#ifdef DEBUG
  A4GL_debug ("OBIND Binding %d=(%d %d %p)", pos, bind->dtype, bind->size,
	      bind->ptr);

  //if (bind->dtype==0) {
  //A4GL_debug("Binding : %s\n",bind->ptr);
  //}

  ptr_to_use = bind->ptr;


  A4GL_debug ("SQLBindCol");
#endif
  set_conv_4gl_to_c ();

  if (bind->dtype == DTYPE_DATE)
    {
      bind->libptr = A4GL_bind_date ((long *) bind->ptr);
      ptr_to_use = bind->libptr;
    }

  if (bind->dtype == DTYPE_DTIME)
    {
      bind->libptr = A4GL_bind_datetime ((void *) bind->ptr);
      ptr_to_use = bind->libptr;
    }

  if (bind->dtype == DTYPE_INTERVAL)
    {
      bind->libptr = A4GL_bind_interval ((void *) bind->ptr);
      ptr_to_use = bind->libptr;
    }


  if (bind->dtype == DTYPE_DECIMAL || bind->dtype == DTYPE_MONEY)
    {
      bind->libptr = A4GL_bind_decimal ((void *) bind->ptr);
      ptr_to_use = bind->libptr;
    }

  if (bind->dtype == DTYPE_BYTE || bind->dtype == DTYPE_TEXT)
    {
      return;
    }
  outlen[pos] = 0;


  A4GL_debug ("SQLBindCol (%p,%d,%d,%p,%d,%p)", (SQLHSTMT) hstmt, pos,
	      conv_4gl_to_c[bind->dtype], ptr_to_use, fgl_size (bind->dtype,
								bind->size),
	      &outlen[pos]);


  A4GL_assertion (conv_4gl_to_c[bind->dtype] < 0,
		  "Invalid 4GL<->ODBC conversion of datatype..");


  //printf (" SQLBindCol (%p,%d,%d,%p,%d,%p)\n", (SQLHSTMT) hstmt, pos, conv_4gl_to_c[bind->dtype], ptr_to_use, fgl_size (bind->dtype, bind->size), &outlen[pos]);



  rc =
    SQLBindCol ((SQLHSTMT) hstmt, pos, conv_4gl_to_c[bind->dtype], ptr_to_use,
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
  int size_c = 0;
  int size = 0;
  int isnull;
  /* DATE_STRUCT *tmp; */
  /*review */
  int k = 0;
  void *ptr_to_use = 0;

  isnull = A4GL_isnull (bind->dtype, bind->ptr);

  A4GL_debug ("ibind_column dtype=%d size=%d isnull=%d", bind->dtype,
	      bind->size, isnull);




  ptr_to_use = bind->ptr;

  if (bind->dtype == DTYPE_DATE && A4GL_isyes (acl_getenv ("BINDDATEASINT")))
    {
      rc =
	A4GL_newSQLSetParam ((SQLHSTMT) hstmt, pos, SQL_INTEGER, SQL_INTEGER,
			     0, 0, bind->ptr, isnull ? &nullval : NULL);
      return;
    }

  A4GL_debug ("ibind_column dtype=%d size=%d isnull=%d", bind->dtype,
	      bind->size, isnull);

  if (bind->dtype != DTYPE_CHAR && bind->dtype != DTYPE_VCHAR)
    {
      size_c = 0;
    }
  else
    {
      if (bind->start_char_subscript == 0)
	{
	  size_c = bind->size;
	}
      else
	{
	  if (bind->start_char_subscript > 100000)
	    {
	      size_c = 0;
	      A4GL_assertion (1,
			      "Dubious start substring character  - a test exists if its more that 100,000");
	    }
	  else
	    {
	      size_c =
		bind->end_char_subscript - bind->start_char_subscript + 1;
	    }
	}
    }

  A4GL_debug ("ibind_column dtype=%d size=%d isnull=%d", bind->dtype,
	      bind->size, isnull);
#ifdef DEBUG
  A4GL_debug ("Binding %d=(dtype=%d size=%d ptr=%p)", pos, bind->dtype,
	      bind->size, bind->ptr);
  if (bind->dtype == DTYPE_CHAR || bind->dtype == DTYPE_VCHAR)
    {
      A4GL_debug ("ibind_column dtype=%d size=%d isnull=%d", bind->dtype,
		  bind->size, isnull);
      A4GL_debug (" is a string : %s size=%d start=%d end=%d  size_c= %d",
		  bind->ptr, bind->size, bind->start_char_subscript,
		  bind->end_char_subscript, size_c);
    }
#endif


#ifdef DEBUG
  if (bind->dtype == DTYPE_CHAR)
    {
      A4GL_debug (" Binding : %s ", bind->ptr);
    }
  set_conv_4gl_to_c ();
  A4GL_debug ("Call SQLSetParam h=%p p=%d dt=%d dt=%d size=%d k=%d ptr=%p",
	      hstmt, pos, conv_4gl_to_c[bind->dtype],
	      conv_4gl_to_c[bind->dtype], size_c, k, bind->ptr);
#endif

  if (bind->dtype == DTYPE_DATE)
    {
      ACLDATE *p;		//@todo FIXME - THIS WILL CREATE A MEMORY LEAK - 
      // NEED TO CLEAN THIS AFTER ITS FINISHED BEING USED...
      void *ptr;
      int d, m, y;
      A4GL_debug ("Binding Date original pointer=%p", bind->ptr);
      ptr = bind->ptr;
      p = (ACLDATE *) A4GL_bind_date ((long *) ptr);
      A4GL_get_date (*(int *) ptr, &d, &m, &y);

      ensure_as_char ();

      if (date_as_char)
	{
	  A4GL_debug ("date_as_char");
	  if (A4GL_isyes (acl_getenv ("BINDDBDATE")))
	    {
	      char *x;
	      A4GL_push_date (*(long *) ptr);
	      x = A4GL_char_pop ();
	      SPRINTF1 (p->uDate.date_c, "%s", x);
	      free (x);
	    }
	  else
	    {
	      SPRINTF3 (p->uDate.date_c, "%04d-%02d-%02d", y, m, d);
	    }
	  size_c = strlen (p->uDate.date_c);
	  ptr_to_use = &p->uDate.date_c;
	  A4GL_debug ("Binding : %s\n", p->uDate.date_c);
	}
      else
	{
	  p->uDate.date_ds.year = y;
	  p->uDate.date_ds.month = m;
	  p->uDate.date_ds.day = d;
	  ptr_to_use = &p->uDate.date_ds;
	}


      bind->libptr = p;
    }


  if (bind->dtype == DTYPE_DTIME)
    {
      ACLDTIME *p;		//@todo FIXME - THIS WILL CREATE A MEMORY LEAK - NEED TO CLEAN THIS AFTER ITS FINISHED BEING USED...
      void *ptr;
      //int d,m,y;
      A4GL_debug ("Binding Datetime original pointer=%p", bind->ptr);

      ptr = bind->ptr;
      ensure_as_char ();

      p = (ACLDTIME *) A4GL_bind_datetime (ptr);
      if (dtime_as_char)
	{
	  char buff[50];
	  A4GL_dttoc (ptr, buff, bind->size);
	  A4GL_trim (buff);
	  strcpy (p->dtime_u.dtime_c, buff);
	  size_c = strlen (buff);
	  ptr_to_use = &p->dtime_u.dtime_c;
	}
      else
	{
	  int arr[10];
	  A4GL_decode_datetime ((struct A4GLSQL_dtime *) ptr, &arr[0]);
	  p->dtime_u.dtime_t.year = arr[0];
	  p->dtime_u.dtime_t.month = arr[1];
	  p->dtime_u.dtime_t.day = arr[2];
	  p->dtime_u.dtime_t.hour = arr[3];
	  p->dtime_u.dtime_t.minute = arr[4];
	  p->dtime_u.dtime_t.second = arr[5];
	  p->dtime_u.dtime_t.fraction = arr[6];
	  ptr_to_use = &p->dtime_u.dtime_t;

	}
      bind->libptr = p;
    }



  if (bind->dtype == DTYPE_INTERVAL)
    {
      ACLIVAL *p;		//@todo FIXME - THIS WILL CREATE A MEMORY LEAK - NEED TO CLEAN THIS AFTER ITS FINISHED BEING USED...
      char buff[50];
      void *ptr;
      //int d,m,y;
      A4GL_debug ("Binding Datetime original pointer=%p", bind->ptr);

      ptr = bind->ptr;
      p = (ACLIVAL *) A4GL_bind_interval (ptr);
      ensure_as_char ();
      A4GL_inttoc (ptr, buff, bind->size);
      A4GL_trim (buff);
      strcpy (p->ival_u.ival_c, buff);
      size_c = strlen (buff);
      bind->libptr = p;
      ptr_to_use = p;
    }



  if (bind->dtype == DTYPE_DECIMAL || bind->dtype == DTYPE_MONEY)
    {
      double *p;		//@todo FIXME - THIS WILL CREATE A MEMORY LEAK - NEED TO CLEAN THIS AFTER ITS FINISHED BEING USED...
      void *ptr;
      int dtype;
      double d;
      A4GL_debug ("Allocate for decimal");
      ptr = bind->ptr;
      p = acl_malloc2 (sizeof (double));
      dtype = bind->dtype + ENCODE_SIZE (bind->size);
      A4GL_push_variable (bind->ptr, dtype);
      d = A4GL_pop_double ();
      *p = d;
      bind->libptr = p;
      ptr_to_use = p;

#ifdef DEBUG
      A4GL_debug ("Bound decimal...\n");
#endif
    }




  set_conv_4gl_to_c ();

  A4GL_debug ("DTYPE %d DTYPE %d SIZE %d", conv_4gl_to_c[bind->dtype],
	      conv_4gl_to_c[bind->dtype], size_c);


  if (size_c)
    {
      size = size_c;
      if (isnull)
	{
	  A4GL_debug ("Calling setparam1");
	  rc =
	    A4GL_newSQLSetParam ((SQLHSTMT) hstmt, pos,
				 conv_4gl_to_c[bind->dtype],
				 conv_4gl_to_c[bind->dtype], size, k,
				 bind->ptr, &nullval);
	}
      else
	{
	  SQLINTEGER *sz;
	  sz = acl_malloc2 (sizeof (SQLINTEGER));
	  *sz = size_c;
	  A4GL_debug ("Calling setparam2");
	  set_extra_data (hstmt, 1, pos, SE_NULLPTR, (void *) sz);
	  rc =
	    A4GL_newSQLSetParam ((SQLHSTMT) hstmt, pos,
				 conv_4gl_to_c[bind->dtype],
				 conv_4gl_to_c[bind->dtype], size, k,
				 ptr_to_use, sz);
	}
    }
  else
    {
      A4GL_debug ("Calling setparam3");

      rc =
	A4GL_newSQLSetParam ((SQLHSTMT) hstmt, pos,
			     conv_4gl_to_c[bind->dtype],
			     conv_4gl_to_c[bind->dtype], size, k, ptr_to_use,
			     isnull ? &nullval : NULL);
    }




  A4GL_debug ("Called newSQLSetParam = %d", rc);
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

  a4gl_sqlca.sqlerrd[0] = 0;
#ifdef DEBUG
  A4GL_debug ("Before Execute hstmt=%p", hstmt);
#endif


  rc = SQLExecute (hstmt);	// Reformatted in caller
  chk_rc (rc, hstmt, "SQLExecute3");
  if (rc != 0)
    {
      A4GL_debug ("ODBC_exec_select returns 0 - no chk_need_block");
      return 0;
    }

  rc = A4GL_chk_need_blob (rc, hstmt);
  if (rc != 0)
    {
      A4GL_debug ("ODBC_exec_select returns 0 - no chk_need_block");
      return 0;
    }

  /* A4GL_set_sqlca (hstmt, "ODBC_exec_select : After SQLExecute", 0); */
  if (rc != 0)
    return 0;
  rc = SQLNumResultCols (hstmt, &nresultcols);
  chk_rc (rc, hstmt, "SQLNumResultCols");
#ifdef DEBUG
  A4GL_debug ("SQLNumResultCols returns %d", nresultcols);
#endif
  if (nresultcols == 0)
    {
      A4GL_debug ("ODBC_exec_select returns no rows - return 0");
      a4gl_sqlca.sqlerrd[0] = 0;
      return 0;
    }
  rc = SQLRowCount ((SQLHSTMT) hstmt, &rowcount);
  chk_rc (rc, hstmt, "SQLRowCount");


#ifdef DEBUG
  A4GL_debug ("SQLRowCount=%d", rowcount);
  A4GL_debug ("Before Fetch");
#endif

  if (rc == 100)
    {
      A4GL_debug ("NOT Found");
      A4GL_debug ("ODBC_exec_select returns NOT FOUND - return 0");
      a4gl_sqlca.sqlerrd[0] = 1;
      return 0;
    }

  rc = SQLFetch ((SQLHSTMT) hstmt);
  chk_rc (rc, hstmt, "SQLFetch");


  /* A4GL_set_sqlca (hstmt, "ODBC_exec_select : After SQLFetch", 0); */

#ifdef DEBUG
  A4GL_debug ("Result=%d", rc);
#endif

  if (rc == 100)
    {
      A4GL_debug ("NOT Found");
      a4gl_sqlca.sqlerrd[0] = 1;
      return 1;
    }

  /* Execute the SQL statement. */
  if (rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO)
    {
      int a;
#ifdef DEBUG
      A4GL_debug ("Oh dear.... %d", rc);
#endif
      A4GL_debug ("ODBC_exec_select returns ERROR - return something - rc=%d",
		  rc);
      a4gl_sqlca.sqlerrd[0] = 0;
      a = A4GL_sqlerrwith (rc, hstmt,1);
      hstmt=0;
      A4GL_debug ("ODBC_exec_select returns ERROR - return something - a=%d",
		  a);
      return a;

    }

  if (rc == SQL_SUCCESS_WITH_INFO)
    {
      A4GL_debug ("ODBC driver wants to tell be something");
#ifdef USE_DIAG_REC
      SQLCHAR SqlState[6], SQLStmt[100], Msg[SQL_MAX_MESSAGE_LENGTH];
      SQLINTEGER NativeError;
      SQLSMALLINT i, MsgLen;
      SQLRETURN rc1, rc2;
      i = 1;
      while ((rc2 =
	      SQLGetDiagRec (SQL_HANDLE_STMT, hstmt, i, SqlState,
			     &NativeError, Msg, sizeof (Msg),
			     &MsgLen)) != SQL_NO_DATA)
	{
	  i++;
	  if (strcmp (SqlState, "01004") == 0)
	    {
	      strcpy (a4gl_sqlca.sqlawarn, "       ");
	      a4gl_sqlca.sqlawarn[0] = 'W';
	      continue;
	    }
	  printf ("0.%s%s%d\n", SqlState, NativeError, Msg, MsgLen);

	}
#else
      {
	char s1[81];
	char s2[500];
	SDWORD xerrno = 0;
	SWORD xerrno2 = 0;

	memset (s1, 0, sizeof (s1));
	memset (s2, 0, sizeof (s1));
	xerrno = 0;
	xerrno2 = 0;
	rc = SQLError (henv, hdbc, (SQLHSTMT) hstmt, s1, &xerrno, s2, 500, &xerrno2);	//warning: passing arg 5 of `SQLError' from incompatible pointer type
	if (strcmp (s1, "01004") == 0)
	  {
	    strcpy (a4gl_sqlca.sqlawarn, "       ");
	    a4gl_sqlca.sqlawarn[0] = 'W';
	  }
	else
	  {
	    printf ("1.%s %s\n", s1, s2);
	  }
      }
#endif
    }

  rc = SQLNumResultCols (hstmt, &nresultcols);
  chk_rc (rc, hstmt, "SQLNumResultCols");

  a4gl_sqlca.sqlerrd[0] = 1;
#ifdef DEBUG
  A4GL_debug ("Yipee!");
#endif
  A4GL_debug ("ODBC_exec_select returns 1");
  return 1;
}




static void
free_extra (void *id)
{
  int nl;

  nl = find_extras (id);

  if (nl > 1000)
    {
      A4GL_assertion (1, "Bad nl ?\n");
    }
  if (nl != -1)
    {
      int a;
      extras[nl].orig_stmt = 0;
      for (a = 0; a < extras[nl].ni; a++)
	{
	  if (extras[nl].idata[a].nullptr)
	    {
	      free (extras[nl].idata[a].nullptr);
	    }
	}
    }
}

static void
set_extra_data (void *id, int in_out, int position, int data, void *val)
{
  int nl;

// Make sure we've got something
  nl = find_extras (id);
  if (nl == -1)
    nl = setup_extras (id);

  if (in_out == 1)
    {				// In
      if (position >= extras[nl].ni)
	{
	  int a;
	  extras[nl].idata =
	    realloc (extras[nl].idata,
		     sizeof (struct s_extra_data) * (position + 1));
	  for (a = extras[nl].ni; a < position; a++)
	    {
	      extras[nl].idata[a].nullptr = 0;
	    }
	}

      if (data == SE_NULLPTR)
	{
	  extras[nl].idata[position].nullptr = val;
	}
    }

  if (in_out == 0)
    {				// Out

    }

}


static int
find_extras (void *id)
{
  int a;
  int nl = -1;

  for (a = 0; a < nextras; a++)
    {
      if (extras[a].orig_stmt == id)
	{
	  nl = a;
	  return nl;
	}
    }
  return -1;
}

static int
setup_extras (void *id)
{
  int a;
  int nl = -1;

  for (a = 0; a < nextras; a++)
    {
      if (extras[a].orig_stmt == id)
	{
	  nl = a;
	  break;
	}
    }

/* wh: reuse empty entrys */
  for (a = 0; a < nextras; a++)
    {
      if (extras[a].orig_stmt == 0)
	{
	  nl = a;
	  break;
	}
    }

  if (nl == -1)
    {
      nextras++;
      extras = realloc (extras, sizeof (struct s_stmtextra) * nextras);
      nl = nextras - 1;
    }

  extras[nl].orig_stmt = id;
  extras[nl].idata = 0;
  extras[nl].odata = 0;
  extras[nl].ni = 0;
  extras[nl].no = 0;
  return nl;
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
  A4GL_debug ("Got hstmt : %p %p", hstmt, *hstmt);
  return (HSTMT *) * hstmt;
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
  //int nresultcols;

#ifdef DEBUG
  A4GL_debug ("In exec_prepared_sql");
#endif

  rc = SQLExecute (hstmt);	// reformatted in callers

  chk_rc (rc, hstmt, "SQLExecute");
  //rc = SQLNumResultCols (hstmt, &nresultcols);
  //chk_rc (rc, hstmt, "SQLNumResultCols");
  //A4GL_debug("SQLNumResultCols=%d",nresultcols);
  rc = A4GL_chk_need_blob (rc, hstmt);

  chk_rc (rc, hstmt, "SQLExecute");
//  A4GL_set_sqlca (hstmt, "ODBC_exec_prepared_sql : After SQLExecute", 0);

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
      return A4GL_sqlerrwith (rc, hstmt,1);
    }
#ifdef DEBUG
  A4GL_debug ("Yipee!");
#endif
  rc = SQLTransact (henv, hdbc, SQL_COMMIT);
  chk_rc (rc, 0, "SQLTransact (COMMIT)");
//  A4GL_set_sqlca (hstmt, "ODBC_exec_prepared_sql : After SQLTransact", 0);
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
  A4GL_new_hstmt ((SQLHSTMT *) & hstmt);
#ifdef DEBUG
  A4GL_debug ("Allocated .. %p %p %p", henv, hdbc, hstmt);
#endif
  SPRINTF2 (sql1, "select %s from %s where 1=0", col, tab);
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
  free_extra (hstmt);
  hstmt = 0;
  SQLFreeConnect (hdbc);
  return conv_sqldtype (coltype, collen[0]);
}


int conv_sqlprec (int ndtype, int sdim, int scale)
{
  if (ndtype == DTYPE_DECIMAL)
    {
      if (strcmp (dbms_dialect, "ORACLE") == 0)
	{
	  //size=((sdim+2)<<8)+2;
	  return ((sdim + scale) << 8) + scale;
	}
      if (strcmp (dbms_dialect, "INFORMIX") == 0)
	{
	  return (sdim << 8) + scale;
	}
      if (strcmp (dbms_dialect, "DB2") == 0 || strcmp(dbms_dialect, "DB2VM") == 0)
	{
	  A4GL_debug ("conv_sqlprec: ndtype=%i sdim=%i scale=%i ret=%i(0x%x)",
		      ndtype, sdim, scale, (sdim << 8) + scale,
		      (sdim << 8) + scale);
	  return (sdim << 8) + scale;
	}
    }
  return sdim;
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
static unsigned long
conv_sqldtype (int sqldtype, int sdim)
{
  int ndtype;

//#if (ODBCVER >= 0x0300)
#ifdef SQL_TYPE_DATE
  if (sqldtype == SQL_TYPE_DATE)
    return DTYPE_DATE;
#endif


  if (sqldtype == SQL_TIME)
    {
      return DTYPE_DTIME;
    }



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


  if (A4GL_isyes (acl_getenv ("NODATETIMES")))
    {
      if (ndtype == DTYPE_DTIME)
	{
	  ndtype = DTYPE_DATE;
	}
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
A4GLSQLLIB_A4GLSQL_get_currdbname (void)
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

  if (type == 6)
    {
      A4GL_pause_execution ();
    }
  if (hstmt == 0)
    {
      A4GL_exitwith ("Statement has not been prepared");
      return 0;
    }

  A4GL_debug ("hstmt=%p", hstmt);
  if (type == 5)
    {
      nresultcols = 0;
      A4GL_debug ("SQLNumResultCols");
      rc = SQLNumResultCols (hstmt, &nresultcols);
      if (rc != SQL_SUCCESS)
	{
	  A4GL_set_sqlca (hstmt, "numresultcols", 0);
	  return 0;
	}
      A4GL_debug ("Returning SQLNumResultCols\n", nresultcols);
      return nresultcols;
    }

  if (type == 6)
    {
      rowcount = 0;
      A4GL_debug ("SQLRowCount");
      rc = SQLRowCount (hstmt, &rowcount);
      if (rc != SQL_SUCCESS)
	{
	  A4GL_set_sqlca (hstmt, "rowcount", 0);
	  return 0;
	}
      A4GL_debug ("Returning SQLRowCount\n", rowcount);
      return rowcount;
    }


  A4GL_debug ("Describing...");
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
A4GLSQLLIB_A4GLSQL_describe_stmt (char *stmt, int colno, int type)
{
  struct s_sid *sid;
  HSTMT *hstmt = 0;
  struct s_cid *cid;
  long z;
  A4GL_debug ("A4GLSQLLIB_A4GLSQL_describe_stmt ('%s', %d, %d)", stmt, colno,
	      type);

  sid = A4GLSQL_find_prepare (stmt);

  A4GL_debug ("sid=%p\n", sid);
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
      hstmt = (SQLHSTMT *) sid->hstmt;
    }


  if (sid == 0 && cid == 0)
    {
      A4GL_exitwith ("Statement could not be found");
    }

  A4GL_debug ("describecolumn");
  z = A4GL_describecolumn ((SQLHSTMT) hstmt, colno, type);
  A4GL_debug ("Returning %d\n", z);
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
A4GLSQLLIB_A4GLSQL_get_columns (char *tabname, char *colname, int *dtype,
				int *size)
{
  static char tq[256];
  static char to[256];
  static char tn[256];
  static char dtname[256];
  char tabname2[256];
  static long len;
  static long scale;
  static long radix;
  static long nullable;
  static char remarks[256];
  static int a, b;
  static int rc;
  short nColumns;
  char buff[200];

  int dt2;
  int sz;



  GetColNo = 0;
  GetColCached = 0;



  A4GL_debug ("Get columns...");
  hstmtGetColumns = 0;
  if (hdbc == 0)
    {
      A4GL_exitwith ("Not connected to database");
      return 0;
    }
  A4GL_debug ("Here1");

  if (hstmtGetColumns == 0)
    {
#ifdef DEBUG
      A4GL_debug ("Creating new statement");
#endif
      A4GL_new_hstmt (&hstmtGetColumns);
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
      if (A4GL_isyes (acl_getenv ("UCASETNAME"))
	  || strcmp (dbms_dialect, "ORACLE") == 0
	  || strcmp (dbms_dialect, "DB2") == 0
	  || strcmp (dbms_dialect, "DB2VM") == 0)
	{
	  strcpy (tabname2, tabname);
	  A4GL_convupper (tabname2);
	  tabname = tabname2;
	}


      strcpy (GetColTab, tabname);
      sprintf (buff, "%s_1", tabname);

      if (A4GL_has_cache_column (buff))
	{
	  GetColCached = 1;
	  GetColNo = 0;
	  return 1;
	}

	
      rc = SQLColumns (hstmtGetColumns, NULL, 0, NULL, 0, tabname, SQL_NTS, NULL, 0);

      if (rc != SQL_SUCCESS)
	{
#ifdef DEBUG
	  A4GL_debug ("Some problem with SQLColumns for table %s rc=%d",tabname,rc);
	  //A4GL_set_sqlca (hstmtGetColumns, "SQLColumns",0)
#endif
	}


      if (rc == 100)
	{
#ifdef DEBUG
	  A4GL_debug ("SQLColumns failed for table '%s'\n", tabname);
#endif
	  A4GL_set_sqlca (hstmtGetColumns, "get_columns", 0);
	  A4GL_exitwith ("Table does not exist\n");
	  return 0;
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

      if (0)
	{

	  rc = SQLFetch (hstmtGetColumns);
	  //printf ("Add column '%s' %d %d\n", cn, dt, prec);

	  if (rc == SQL_NO_DATA_FOUND || rc == SQL_ERROR)
	    {
	      return 1;
	    }

	  colsize = A4GL_display_size (dt, prec, "");
	  SPRINTF1 (szcolsize, "%d", colsize);

	  if (rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO)
	    {
	      SQLFreeStmt (hstmtGetColumns, SQL_DROP);
	      free_extra (hstmtGetColumns);
	      hstmtGetColumns = 0;
	      return 0;
	    }
	  A4GL_convlower (cn);
	  dt2 = conv_sqldtype (dt, prec);
	  if (dt == SQL_TIME)
	    {
	      dt2 = DTYPE_DTIME;
	      prec = 0x46;
	    }

	  // We can't generate proper precision on a decimal..
	  // because we don't have the scale - assume 2..
	  sz = conv_sqlprec (dt2, prec, 2);
	  //printf ("Add column '%s' %d %d\n", cn, dt2, sz);
	  AddColumn (cn, dt2, sz);

	}



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
A4GLSQLLIB_A4GLSQL_next_column (char **colname, int *dtype, int *size)
{

  char buff[200];
  GetColNo++;

  if (GetColCached)
    {
      sprintf (buff, "%s_%d", GetColTab, GetColNo);
      if (A4GL_has_cache_column (buff))
	{
	  static char buffx[2000];
	  char *ptr;

	  ptr = A4GL_find_cache_column (buff);

	  if (ptr)
	    {
	      //printf("Scanning from %s\n",ptr);
	      sscanf (ptr, "%s %d %d", buffx, dtype, size);
	      *colname = buffx;
	      return 1;
	    }
	  else
	    {
	      A4GL_assertion (1, "Shouldn't happen");
	    }
	}
      return 0;
    }



  rc = SQLFetch (hstmtGetColumns);
#ifdef DEBUG
  A4GL_debug ("A4GLSQL_next_column fetch rc = %d, cn = %s\n", rc, cn);
#endif

  if (rc == SQL_NO_DATA_FOUND || rc == SQL_ERROR)
    {
      return 0;
    }

  colsize = A4GL_display_size (dt, prec, "");
  SPRINTF1 (szcolsize, "%d", colsize);

  if (rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO)
    {
      SQLFreeStmt (hstmtGetColumns, SQL_DROP);
      free_extra (hstmtGetColumns);
      hstmtGetColumns = 0;
      return 0;
    }
  A4GL_convlower (cn);
  *colname = cn;
  *dtype = conv_sqldtype (dt, prec);
  if (dt == SQL_TIME)
    {
      *dtype = DTYPE_DTIME;
      prec = 0x46;
    }

  // We can't generate proper precision on a decimal..
  // because we don't have the scale - assume 2..
  *size = conv_sqlprec (*dtype, prec, 2);

  if (A4GL_isyes (acl_getenv ("CACHESCHEMA")))
    {
      AddColumn (*colname, *dtype, *size);
    }
  return 1;
}


void
AddColumn (char *s, int d, int sz)
{
  char buff[256];
  char buff2[256];

  sprintf (buff, "%s_%d", GetColTab, GetColNo);
  if (A4GL_has_cache_column (buff))
    {
      // Got the column cached !
      return;
    }
  sprintf (buff2, "%s %d %d", s, d, sz);
  //printf("Adding %s to %s\n",buff,buff2);
  A4GL_add_cache_column (buff, buff2);
}




/**
 * Free all resources allocated in getting information about columns
 * 
 * @return 
 *   - 0 : Descriptor dealocated
 *   - 1 : Error ocurred.
 */
int
A4GLSQLLIB_A4GLSQL_end_get_columns (void)
{
  return 0;
}


#ifdef REMOVED
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
A4GLSQLLIB_A4GLSQL_read_columns (char *tabname, char *colname, int *dtype,
				 int *size)
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
  char tabname2[256];
  static int a, b;
  static int rc;
  short nColumns;
  char buff[200] = "";





  if (tabname && colname)
    {
      if (strlen (tabname) && strlen (colname))
	{
	  sprintf (buff, ":%s %s", tabname, colname);
	}
    }


  if (A4GL_isyes (acl_getenv ("CACHESCHEMA")))
    {
      if (A4GL_has_cache_column (buff))
	{
	  char *ptr;
	  ptr = A4GL_find_cache_column (buff);
	  sscanf (ptr, "%d %d", dtype, size);
	  return 1;
	}
    }


  if (hdbc == 0)
    {
      A4GL_exitwith ("Not connected to database");
      return 0;
    }
  if (A4GL_isyes (acl_getenv ("UCASETNAME"))
      || strcmp (dbms_dialect, "ORACLE") == 0
      || strcmp (dbms_dialect, "DB2") == 0
      || strcmp (dbms_dialect, "DB2VM") == 0)
    {
      strcpy (tabname2, tabname);
      A4GL_convupper (tabname2);
      tabname = tabname2;
    }
#ifdef DEBUG
  A4GL_debug ("In read column tabname='%s' colname='%s'", tabname, colname);
#endif

  if (hstmt == 0)
    {
#ifdef DEBUG
      A4GL_debug ("Creating new statement");
#endif
      A4GL_new_hstmt ((SQLHSTMT *) & hstmt);
    }

  if (tabname != 0)
    {
#ifdef DEBUG
      A4GL_debug ("New search");
#endif
      A4GL_new_hstmt ((SQLHSTMT *) & hstmt);
#ifdef DEBUG
      A4GL_debug ("Got Statement");
#endif

      rc = SQLColumns (hstmt, NULL, 0, NULL, 0, tabname, SQL_NTS, NULL, 0);

      if (rc != SQL_SUCCESS)
	{
#ifdef DEBUG
	  A4GL_debug ("Some problem with SQLColumns for table %s",tabname);
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
  A4GL_debug ("XXX       %x %s prec=%x %d\n %x %x %x '%s'", dt, dtname, prec,
	      len, scale, radix, nullable, remarks);
#endif
  colsize = A4GL_display_size (dt, prec, "");
  SPRINTF1 (szcolsize, "%d", colsize);

  if (rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO)
    {
#ifdef DEBUG
      A4GL_debug ("Some error getting data....");
#endif
      SQLFreeStmt (hstmt, SQL_DROP);
      free_extra (hstmt);
      hstmt = 0;
      return 0;
    }
  strcpy (colname, cn);
  A4GL_convlower (colname);

  *dtype = conv_sqldtype (dt, prec);
  if (dt == SQL_TIME)
    {
      *dtype = DTYPE_DTIME;
      prec = 0x46;
    }
  *size = conv_sqlprec (*dtype, prec, scale);

  if (A4GL_isyes (acl_getenv ("CACHESCHEMA")))
    {
      char buff2[2000];
      sprintf (buff2, "%d %d", *dtype, *size);
      if (!A4GL_has_cache_column (buff))
	{
	  A4GL_add_cache_column (buff, buff2);
	}
    }


#ifdef DEBUG
  A4GL_debug ("Set dtype to %d\n", *dtype);
#endif
  return 1;
}

#endif

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

  set_conv_4gl_to_c ();
  A4GL_newSQLSetParam (hstmt, pos, conv_4gl_to_c[0], conv_4gl_to_c[0], size,
		       0, s, NULL);
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
A4GLSQLLIB_A4GLSQL_init_session_internal (char *sessname, char *dsn,
					  char *usr, char *pwd)
{
  char empty[10] = "None";
  char *u, *p = 0;
  char uname_acl[256];
  char passwd_acl[256];
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

  if (A4GL_sqlid_from_aclfile (dsn, uname_acl, passwd_acl))
    {
      // If we've got a match - it must be explicitly overridden by the environment
      // so we'll use getenv rather than acl_getenv....
      u = acl_getenv_only ("SQLUID");
      p = acl_getenv_only ("SQLPWD");
      if (u && strlen (u) == 0)
	u = 0;
      if (p && strlen (p) == 0)
	p = 0;
      if (!u || !p)
	{
	  u = uname_acl;
	  p = passwd_acl;
	}
    }
  else
    {
      if (usr == 0)
	u = acl_getenv ("SQLUID");
      else
	u = usr;

      if (pwd == 0)
	p = acl_getenv ("SQLPWD");
      else
	p = pwd;
    }

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
      hh = acl_malloc2 (sizeof (HDBC));
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
A4GLSQLLIB_A4GLSQL_get_curr_conn (void)
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
      stmt = (SQLHSTMT) & ptr_sid->hstmt;
    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("Is cursor statement");
#endif
      ptr_cid = (struct s_cid *) A4GL_find_pointer (cursname, CURCODE);
      stmt = (SQLHSTMT) & ptr_cid->statement->hstmt;
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
A4GLSQLLIB_A4GLSQL_set_conn_internal (char *sessname)
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
A4GLSQLLIB_A4GLSQL_close_session_internal (char *sessname)
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
  A4GL_debug ("commiting all transactions on SQLite...");
  A4GLSQLLIB_A4GLSQL_commit_rollback (1);
#endif

  if (A4GL_isyes (acl_getenv ("FORCE_ROLLBACK_AT_EXIT")))
    {
      A4GLSQLLIB_A4GLSQL_commit_rollback (1);
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

  ptr = acl_malloc2 (sizeof (ACLDATE));
#ifdef DEBUG
  A4GL_debug ("Binding date for %p", ptr_to_date_var);
#endif
  ptr->ptr = ptr_to_date_var;
  ensure_as_char ();
  if (date_as_char)
    {
      strcpy (ptr->uDate.date_c, "0000-00-00");
    }
  else
    {
      ptr->uDate.date_ds.year = -1;
      ptr->uDate.date_ds.month = -1;
      ptr->uDate.date_ds.day = -1;
    }

  return (void *) ptr;
}

void *
A4GL_bind_datetime (void *ptr_to_dtime_var)
{
  ACLDTIME *ptr;

  ptr = acl_malloc2 (sizeof (ACLDTIME));

  ensure_as_char ();
  if (dtime_as_char)
    {
      strcpy (ptr->dtime_u.dtime_c, "");
    }
  else
    {
      ptr->dtime_u.dtime_t.year = -1;
      ptr->dtime_u.dtime_t.month = -1;
      ptr->dtime_u.dtime_t.day = -1;
      ptr->dtime_u.dtime_t.hour = -1;
      ptr->dtime_u.dtime_t.minute = -1;
      ptr->dtime_u.dtime_t.second = -1;
    }


  ptr->ptr = ptr_to_dtime_var;
  return (void *) ptr;
}

void *
A4GL_bind_interval (void *ptr_to_ival)
{
  ACLIVAL *ptr;

  ptr = acl_malloc2 (sizeof (ACLIVAL));
  strcpy (ptr->ival_u.ival_c, "");
  ptr->ptr = ptr_to_ival;
  return (void *) ptr;
}



void *
A4GL_bind_decimal (void *ptr_to_decimal)
{
  double *ptr;
  ptr = acl_malloc2 (sizeof (double));
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
A4GL_post_fetch_proc_bind (struct BINDING *use_binding, int use_nbind,
			   HSTMT hstmt)
{
  int bind_counter;
  int zz;
  // int ncols;
  ACLDATE *date1;
  ACLDTIME *dt1;
  ACLIVAL *iv1;
#ifdef DEBUG
  A4GL_debug ("In post_fetch_proc_bind...");
#endif

  for (bind_counter = 0; bind_counter < use_nbind; bind_counter++)
    {

#ifdef DEBUG
      A4GL_debug ("a=%d Binding type %d ptr=%p %d", bind_counter,
		  use_binding[bind_counter].dtype,
		  use_binding[bind_counter].ptr, outlen[bind_counter + 1]);
#endif


      if (use_binding[bind_counter].dtype == DTYPE_CHAR)
	{
	  A4GL_debug ("Found string @ %d = '%s'", bind_counter,
		      use_binding[bind_counter].ptr);
	  if (strlen (use_binding[bind_counter].ptr))
	    {			// Its not null 
	      A4GL_pad_string (use_binding[bind_counter].ptr,
			       use_binding[bind_counter].size);
	    }
	}



      if (outlen[bind_counter + 1] == -1)
	{
	  if (use_binding[bind_counter].dtype == DTYPE_DATE)
	    {
	      date1 = use_binding[bind_counter].ptr;
	      A4GL_setnull (DTYPE_DATE,
			    (char *) use_binding[bind_counter].ptr, 0);
	      continue;
	    }
	  A4GL_setnull (use_binding[bind_counter].dtype,
			(char *) use_binding[bind_counter].ptr,
			use_binding[bind_counter].size);
	  continue;
	}

      if (use_binding[bind_counter].dtype == DTYPE_BYTE
	  || use_binding[bind_counter].dtype == DTYPE_BYTE)
	{
	  A4GL_get_blob_data (use_binding[bind_counter].ptr, hstmt,
			      bind_counter);
	  continue;
	}

      if (use_binding[bind_counter].dtype == DTYPE_DATE)
	{
#ifdef DEBUG
	  A4GL_debug
	    ("Got a date datatype - better copy the date in properly");
#endif


	  date1 = use_binding[bind_counter].libptr;

	  ensure_as_char ();
	  if (date_as_char)
	    {
	      {
		int y, d, m;
		int nscanned;
		y = -1;
		d = -1;
		m = -1;
		A4GL_debug ("Date as char");
		A4GL_debug ("DATE=(%s,%d)\n", date1->uDate.date_c,
			    strlen (date1->uDate.date_c));

		if (strlen (date1->uDate.date_c))
		  {
		    nscanned =
		      sscanf (date1->uDate.date_c, "%d-%d-%d", &y, &m, &d);
		    if (nscanned == 3)
		      {
			A4GL_debug ("Calling gen_dateno");
			zz = A4GL_gen_dateno (d, m, y);
			*(long *) date1->ptr = zz;
			continue;
		      }
		    else
		      {
			A4GL_push_char (date1->uDate.date_c);
			zz = A4GL_pop_date ();


			*(long *) date1->ptr = zz;




			continue;
		      }
		  }
		else
		  {
		    A4GL_debug ("Looks null");
		    A4GL_setnull (DTYPE_DATE, date1->ptr, 0);
		    A4GL_debug ("Looks null");
		    continue;
		  }
	      }
	    }
	  else
	    {
	      A4GL_debug ("Date not as char");
	      A4GL_assertion (date1->uDate.date_ds.month < 1
			      || date1->uDate.date_ds.month > 12,
			      "Invalid month retrieved from db");
	      A4GL_assertion (date1->uDate.date_ds.day < 1
			      || date1->uDate.date_ds.day > 31,
			      "Invalid day retrieved from db");
#ifdef DEBUG
	      A4GL_debug ("Year=%d Month=%d Day=%d",
			  date1->uDate.date_ds.year,
			  date1->uDate.date_ds.month,
			  date1->uDate.date_ds.day);
#endif

	      A4GL_debug ("Calling gen_dateno");
	      zz =
		A4GL_gen_dateno (date1->uDate.date_ds.day,
				 date1->uDate.date_ds.month,
				 date1->uDate.date_ds.year);
	      *(long *) date1->ptr = zz;

	    }

	  //*(long *) use_binding[bind_counter].ptr = zz;
	  continue;

	}


      if (use_binding[bind_counter].dtype == DTYPE_INTERVAL)
	{

	  char buff[256];
	  iv1 = use_binding[bind_counter].libptr;
	  strcpy (buff, iv1->ival_u.ival_c);
	  A4GL_push_char (buff);
	  A4GL_setnull (DTYPE_INTERVAL, iv1->ptr,
			use_binding[bind_counter].size);
	  A4GL_pop_param (iv1->ptr, DTYPE_INTERVAL,
			  use_binding[bind_counter].size);
	  continue;
	}









      if (use_binding[bind_counter].dtype == DTYPE_DTIME)
	{

	  char buff[256];
	  dt1 = use_binding[bind_counter].libptr;
	  ensure_as_char ();
	  if (dtime_as_char)
	    {
	      strcpy (buff, dt1->dtime_u.dtime_c);
	    }
	  else
	    {
	      char buff2[256];
	      int s;
	      int e;
	      strcpy (buff, "");
	      s = use_binding[bind_counter].size >> 4;
	      e = use_binding[bind_counter].size & 0xf;

	      if (s > 1)
		dt1->dtime_u.dtime_t.year = 0;
	      if (s > 2)
		dt1->dtime_u.dtime_t.month = 0;
	      if (s > 3)
		dt1->dtime_u.dtime_t.day = 0;
	      if (s > 4)
		dt1->dtime_u.dtime_t.hour = 0;
	      if (s > 5)
		dt1->dtime_u.dtime_t.minute = 0;
	      if (s > 6)
		dt1->dtime_u.dtime_t.second = 0;

	      if (strlen (buff) || dt1->dtime_u.dtime_t.year)
		{
		  SPRINTF1 (buff2, "%04d", dt1->dtime_u.dtime_t.year);
		  strcat (buff, buff2);
		}

	      if (strlen (buff) || dt1->dtime_u.dtime_t.month)
		{
		  if (e >= 2)
		    {
		      SPRINTF1 (buff2, "%02d", dt1->dtime_u.dtime_t.month);
		      if (strlen (buff))
			strcat (buff, "-");
		      strcat (buff, buff2);
		    }
		}
	      if (strlen (buff) || dt1->dtime_u.dtime_t.day)
		{
		  if (e >= 3)
		    {
		      SPRINTF1 (buff2, "%02d", dt1->dtime_u.dtime_t.day);
		      if (strlen (buff))
			strcat (buff, "-");
		      strcat (buff, buff2);
		    }
		}
	      if (strlen (buff) || dt1->dtime_u.dtime_t.hour)
		{
		  if (e >= 4)
		    {
		      SPRINTF1 (buff2, "%02d", dt1->dtime_u.dtime_t.hour);
		      if (strlen (buff))
			strcat (buff, " ");
		      strcat (buff, buff2);
		    }
		}


	      if (strlen (buff) || dt1->dtime_u.dtime_t.minute)
		{
		  if (e >= 5)
		    {
		      SPRINTF1 (buff2, "%02d", dt1->dtime_u.dtime_t.minute);
		      if (strlen (buff))
			strcat (buff, ":");
		      strcat (buff, buff2);
		    }
		}
	      if (strlen (buff) || dt1->dtime_u.dtime_t.second)
		{
		  if (e >= 6)
		    {
		      SPRINTF1 (buff2, "%02d", dt1->dtime_u.dtime_t.second);
		      if (strlen (buff))
			strcat (buff, ":");
		      strcat (buff, buff2);
		    }
		}

	    }
	  A4GL_push_char (buff);
	  A4GL_setnull (DTYPE_DTIME, dt1->ptr,
			use_binding[bind_counter].size);
	  A4GL_pop_param (dt1->ptr, DTYPE_DTIME,
			  use_binding[bind_counter].size);
	  continue;
	}


      if (use_binding[bind_counter].dtype == DTYPE_DECIMAL
	  || use_binding[bind_counter].dtype == DTYPE_MONEY)
	{
	  // We've actually selected into a double...
	  double d;
	  A4GL_debug ("using decimal");
	  A4GL_assertion (use_binding[bind_counter].libptr == 0,
			  "No pointer to use for decimal/money");
	  d = *((double *) use_binding[bind_counter].libptr);
	  A4GL_debug ("DECIMAL from double on db d=%lf", d);
	  A4GL_push_double (d);
	  A4GL_pop_var2 (use_binding[bind_counter].ptr,
			 use_binding[bind_counter].dtype,
			 use_binding[bind_counter].size);
	  continue;
	}
      A4GL_debug ("Bound %d\n", bind_counter);

    }




#ifdef DEBUG
  if (0)
    {
      char buffstr[30000] = "Fetch returns :\n";
      char bf[2048];
      int a;
      for (a = 0; a < use_nbind; a++)
	{
	  char *cptr;
	  int dtype;


	  if (use_binding[a].dtype == DTYPE_CHAR
	      || use_binding[a].dtype == DTYPE_VCHAR
	      || use_binding[a].dtype == DTYPE_DECIMAL
	      || use_binding[a].dtype == DTYPE_MONEY
	      || use_binding[a].dtype == DTYPE_DTIME)
	    {
	      A4GL_debug ("Need to add size to dtype");
	      dtype =
		use_binding[a].dtype + ENCODE_SIZE (use_binding[a].size);
	    }
	  else
	    {
	      dtype = use_binding[a].dtype;
	    }



	  if (dtype == DTYPE_BYTE || dtype == DTYPE_TEXT)
	    {
	      A4GL_push_char ("<byte>");
	    }
	  else
	    {
	      if ((dtype & 15) == DTYPE_DTIME || (dtype & 15) == DTYPE_DATE)
		{
		  if ((dtype & 15) == DTYPE_DATE)
		    {
		      ACLDATE *date1;
		      ensure_as_char ();
		      date1 = use_binding[a].libptr;
		      if (date_as_char)
			{
			  A4GL_push_char (date1->uDate.date_c);
			}
		      else
			{
			  int xd;
			  int xm;
			  int xy;
			  char buff[40];
			  xy = date1->uDate.date_ds.year;
			  xm = date1->uDate.date_ds.month;
			  xd = date1->uDate.date_ds.day;
			  SPRINTF3 (buff, "%d-%d-%d", xy, xm, xd);
			  A4GL_push_char (buff);
			}
		    }
		  else
		    {

		      A4GL_push_char ("<datetime>");
		    }
		}
	      else
		{
		  A4GL_push_variable (use_binding[a].ptr, dtype);
		}
	    }
	  cptr = A4GL_char_pop ();
	  SPRINTF4 (bf, "%d) %d %d : %s", a, use_binding[a].dtype,
		    (int) use_binding[a].size, cptr);
	  if (a > 0)
	    strcat (buffstr, ",\n");
	  strcat (buffstr, bf);
	  free (cptr);
	}
      strcat (buffstr, "\n");
      A4GL_debug ("use_nbind=%d - %s", use_nbind, buffstr);
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
A4GLSQLLIB_A4GLSQL_commit_rollback (int mode)
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


  if (tmode == -1)
    return;


  if (tmode == 0)
    {
#ifdef DEBUG
      A4GL_debug ("ODBC Transaction Mode:%d ", mode);
#endif
      if (mode == 1)
	{
	  in_transaction = 0;
	  SQLTransact (henv, hdbc, SQL_COMMIT);
	}

      if (mode == 0)
	{
	  in_transaction = 0;
	  SQLTransact (henv, hdbc, SQL_ROLLBACK);
	}

      if (mode == -1)
	{
	  rc = SQLSetConnectOption (hdbc, SQL_AUTOCOMMIT, 0);
	  in_transaction = 1;
	}

      chk_rc (rc, hstmt, "Commit/Rollback1");
//      A4GL_set_sqlca (SQL_NULL_HSTMT, "Commit/Rollback", 0);
    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("Native Transaction Mode:%d", mode);
#endif
      A4GL_new_hstmt ((SQLHSTMT *) & hstmt);
      if (mode == -1)
	{
	  in_transaction = 1;
	  SQLExecDirect (hstmt, "BEGIN WORK", SQL_NTS);
	}

      if (mode == 0)
	{
	  in_transaction = 0;
	  SQLExecDirect (hstmt, "ROLLBACK WORK", SQL_NTS);
	}

      if (mode == 1)
	{
	  in_transaction = 0;
	  SQLExecDirect (hstmt, "COMMIT WORK", SQL_NTS);
	}

      chk_rc (rc, hstmt, "Commit/Rollback2");
//      A4GL_set_sqlca (hstmt, "Commit/Rollback", 0);


      SQLFreeStmt (hstmt, SQL_DROP);
      free_extra (hstmt);
      hstmt = 0;
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
A4GLSQLLIB_A4GLSQL_unload_data_internal (char *fname, char *delims,
					 char *sql1, int nbind, void *vibind)
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
  SQLUSMALLINT colcnt;
  SQLINTEGER ind;
  UDWORD collen;
  SWORD scale;
  SWORD nullable;
  FILE *fout;
  ibind = vibind;
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
  A4GL_new_hstmt ((SQLHSTMT *) & hstmt);

  sql2 = strdup (sql1);

  A4GL_assertion (hstmt == 0, "No statement");
  SQLPrepare ((SQLHSTMT) hstmt, sql2, SQL_NTS);
  A4GL_proc_bind (ibind, nbind, 'i', (SQLHSTMT) hstmt);

  reformat_sql (sql2, ibind, nbind, "7");

  rc = SQLExecute (hstmt);	// Reformatted
  chk_rc (rc, hstmt, "unload_data");
  if (a4gl_sqlca.sqlcode < 0)
    return;

#ifdef DEBUG
  A4GL_debug ("Executed %s %d", sql2, rc);
#endif

  rc = SQLNumResultCols (hstmt, &ncols);
  A4GL_debug ("Calling chk_Rc %d\n", rc);
  chk_rc (rc, hstmt, "unload_data");
  if (a4gl_sqlca.sqlcode < 0)
    return;
  A4GL_debug ("Done Calling chk_Rc %d status=%d \n", rc, a4gl_sqlca.sqlcode);


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
	    SQLGetData (hstmt, colcnt, SQL_CHAR, databuf,
			sizeof (databuf), &ind);
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

	  if (ind == -1)
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
		  if (coltype[colcnt] == SQL_DOUBLE)
		    {
		      if (strchr (databuf, '.') || strchr (databuf, ',')
			  || strchr (databuf, 'e'))
			{
			  fprintf (fout, "%s%c", databuf, delims[0]);
			}
		      else
			{
			  fprintf (fout, "%s.0%c", databuf, delims[0]);
			}
		    }
		  else
		    {
		      fprintf (fout, "%s%c", databuf, delims[0]);
		    }
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
  free_extra (hstmt);
  hstmt = 0;
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
	  SPRINTF1 (sbuff, "%04d", y);
	  strcat (buff, sbuff);
	}

      if (dbdate[cnt] == 'm' || dbdate[cnt] == 'M')
	{
	  SPRINTF1 (sbuff, "%02d", m);
	  strcat (buff, sbuff);
	}

      if (dbdate[cnt] == 'd' || dbdate[cnt] == 'D')
	{
	  SPRINTF1 (sbuff, "%02d", d);
	  strcat (buff, sbuff);
	}

      if (cnt != 2)
	{

	  if (dbdate[4] != 0)
	    SPRINTF1 (sbuff, "%c", dbdate[4]);
	  else
	    SPRINTF0 (sbuff, "/");

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



#ifdef INCLUDEDATASOURCES
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
A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (int a)
{
  a4gl_status = a;
  a4gl_sqlca.sqlcode = a;
}


static int
do_fake_transactions (void)
{
  static int d = -1;
  if (d == -1)
    {
      d = A4GL_isyes (acl_getenv ("FAKE_TRANSACTIONS"));
    }
  return d;
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
A4GLSQLLIB_A4GLSQL_put_insert (void *vibind, int n)
{
  struct BINDING *ibind;
  char *cursorName;
  struct s_cid *cid;
  struct s_sid *sid;
  int ni;
  ibind = vibind;


  cursorName = A4GL_char_pop ();
  cid = A4GLSQL_find_cursor (cursorName);
  free (cursorName);
  if (cid == 0)
    return;
  A4GL_debug ("Which Bind ? %p %d, %p %d", vibind, n, cid->statement->ibind,
	      cid->statement->ni);
  if (n)
    {
      ibind = vibind;
      ni = n;
    }
  else
    {
      ni = cid->statement->ni;
      ibind = cid->statement->ibind;
    }
  sid = cid->statement;
  A4GL_proc_bind (ibind, ni, 'i', (SQLHSTMT) sid->hstmt);
  reformat_sql (sid->select, ibind, ni, "8");
  ODBC_exec_prepared_sql ((SQLHSTMT) sid->hstmt);

}

/**
 * FLUSH CURSOR 4gl statement implementation.
 * Not implemented in ODBC.
 *
 * @param The cursor name.
 */
void
A4GLSQLLIB_A4GLSQL_flush_cursor (char *cursor)
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
A4GLSQLLIB_SQL_initlib (void)
{
  initenv ();
  A4GLSQL_make_connection (0, 0, 0);
  return 1;
}

char *
A4GLSQLLIB_A4GLSQL_syscolval_expr (char *tabname, char *colname, char *typ)
{
  return 0;
}

struct expr_str_list *
A4GL_add_validation_elements_to_expr (struct expr_str_list *ptr, char *val)
{
  char *ptr2;
  char *ptrn;
  //char buff[256];
  A4GL_trim (val);
  ptr2 = val;
  while (1)
    {
      ptrn = strtok (ptr2, ",");
      if (ptrn == 0)
	break;
      if (ptr2)
	{
	  ptr2 = 0;
	}


      //SPRINTF1 (buff, "A4GL_push_char(\"%s\");", ptrn);

      if (ptr == 0)
	{
	  ptr = A4GL_new_ptr_list (A4GL_new_literal_string (ptrn));
	  //ptr = A4GL_new_expr (buff);
	}
      else
	{
	  ptr =
	    A4GL_new_append_ptr_list (ptr, A4GL_new_literal_string (ptrn));
	}

    }
  return ptr;
}

/*
void *
A4GLSQLLIB_A4GLSQL_get_validation_expr (char *tabname, char *colname)
{
  char buff[300];
  SPRINTF3 (buff,
	   "select attrval from %s where attrname='INCLUDE' and tabname='%s' and colname='%s'",
	   acl_getenv ("A4GL_SYSCOL_VAL"), tabname, colname);

  printf ("Warning Validation feature not implemented in ODBC SQL Driver\n");
  return 0;
}
*/



t_expr_str_list *
A4GLSQLLIB_A4GLSQL_get_validation_expr (char *tabname, char *colname)
{
  char buff[300];
  char val[65];
  struct expr_str_list *ptr = 0;
  char *cptr = 0;
  struct BINDING obind[1] = { {0, 0, 64, 0, 0} };	/* end of binding */
  obind[0].ptr = &val;


  cptr = acl_getenv ("A4GL_SYSCOL_VAL");
  if (cptr == 0)
    return 0;
  if (strlen (cptr) == 0)
    return 0;
  if (strcmp (cptr, "NONE") == 0)
    return 0;
  SPRINTF3 (buff,
	    "select attrval from %s where attrname='INCLUDE' and tabname='%s' and colname='%s'",
	    cptr, tabname, colname);
  A4GLSQL_add_prepare ("p_get_val", (void *) A4GLSQL_prepare_select_internal (0, 0, 0, 0, buff,"__internal_sql_1"));
  if (a4gl_sqlca.sqlcode != 0)
    return (void *) -1;
  A4GLSQLLIB_A4GLSQL_declare_cursor (0 + 0,
				     A4GLSQL_find_prepare ("p_get_val"), 0,
				     "c_get_val");
  if (a4gl_sqlca.sqlcode != 0)
    return (void *) -1;
  A4GLSQLLIB_A4GLSQL_open_cursor ("c_get_val", 0, 0);
  if (a4gl_sqlca.sqlcode != 0)
    return (void *) -1;


  while (1)
    {
      A4GLSQL_fetch_cursor ("c_get_val", 2, 1, 1, obind);
      if (a4gl_sqlca.sqlcode != 0)
	break;
      ptr = A4GL_add_validation_elements_to_expr (ptr, val);
      /* Process it... */
    }
  return ptr;

}



void
initenv (void)
{
  if (henv == 0)
    {
      A4GL_debug ("Calling SQLAllocEnv()");
      //This call core dumps on SQLite/MinGW:
      rc = SQLAllocEnv (&henv);
      //rc = SQLAllocEnv (henv);
      chk_rc (rc, 0, "SQLAllocEnv");
#ifdef DEBUG
      A4GL_debug ("SQLAllocEnv returns %d %p", rc, henv);
#endif
      if (rc == SQL_SUCCESS)
	{
	  ListDSN ();
	}
    }




}

void
ListDSN (void)
{
  char l_dsn[100], l_desc[100];
  short int l_len1, l_len2, l_next;
  int rc;

  l_next = SQL_FETCH_FIRST;
  rc = SQL_SUCCESS;

  A4GL_debug ("Listing DSNs");

  while (rc == SQL_SUCCESS)
    {
      rc =
	SQLDataSources (henv, l_next, l_dsn, sizeof (l_dsn), &l_len1, l_desc,
			sizeof (l_desc), &l_len2);
      if (rc != SQL_SUCCESS)
	break;

      A4GL_debug ("Server=(%s) Description=(%s)\n", l_dsn, l_desc);
      l_next = SQL_FETCH_NEXT;
    }
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
A4GL_getdsnattr (char *dsn, char *attr, char *out, int outLen)
{
  char *str = dsn, *start;
  int len = strlen (attr);

  while (*str)
    {
      while (*str && *str == ';')
	{
	  ++str;
	}
      start = str;
      if ((str = strchr (str, '=')) == NULL)
	{
	  return 0;
	}
      if (str - start == len &&
#ifdef _WIN32
	  _strnicmp (start, attr, len) == 0
#else
	  strncasecmp (start, attr, len) == 0
#endif
	)
	{
	  start = ++str;
	  while (*str && *str != ';')
	    {
	      ++str;
	    }
	  len = min (outLen - 1, str - start);
	  strncpy (out, start, len);
	  out[len] = '\0';
	  return 1;
	}
      while (*str && *str != ';')
	{
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
GetAttributes (SETUPDLG * setupdlg)
{
  char *dsn = setupdlg->attr[KEY_DSN].attr;

  if (!setupdlg->attr[KEY_DESC].supplied)
    {
      SQLGetPrivateProfileString (dsn, "Description", "",
				  setupdlg->attr[KEY_DESC].attr,
				  sizeof (setupdlg->attr[KEY_DESC].attr),
				  ODBC_INI);
    }
  if (!setupdlg->attr[KEY_DBNAME].supplied)
    {
      SQLGetPrivateProfileString (dsn, "Database", "",
				  setupdlg->attr[KEY_DBNAME].attr,
				  sizeof (setupdlg->attr[KEY_DBNAME].attr),
				  ODBC_INI);
    }
  if (!setupdlg->attr[KEY_BUSY].supplied)
    {
      SQLGetPrivateProfileString (dsn, "Timeout", "1000",
				  setupdlg->attr[KEY_BUSY].attr,
				  sizeof (setupdlg->attr[KEY_BUSY].attr),
				  ODBC_INI);
    }
  if (!setupdlg->attr[KEY_NOWCHAR].supplied)
    {
      SQLGetPrivateProfileString (dsn, "NoWCHAR", "",
				  setupdlg->attr[KEY_NOWCHAR].attr,
				  sizeof (setupdlg->attr[KEY_NOWCHAR].attr),
				  ODBC_INI);
    }
#ifdef ASYNC
  if (!setupdlg->attr[KEY_THR].supplied)
    {
      SQLGetPrivateProfileString (dsn, "Threaded", "1",
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
example_drvconnect (SQLHDBC dbc, SQLCHAR * dsn, SQLSMALLINT dsnLen)
{
  DBC *d;
  int len;
  char buf[SQL_MAX_MESSAGE_LENGTH], dbname[SQL_MAX_MESSAGE_LENGTH / 4];
  char busy[SQL_MAX_MESSAGE_LENGTH / 4];
  char tflag[32], nwflag[32];


//Test parameters we got:
  if (dbc == SQL_NULL_HDBC)
    {
      return SQL_INVALID_HANDLE;
    }
  d = (DBC *) dbc;
  if (d->magic != DBC_MAGIC)
    {
      return SQL_INVALID_HANDLE;
    }
  if (d->sqlite != NULL)
    {
      setstatd (d, "connection already established", "08002");
      return SQL_ERROR;
    }
  buf[0] = '\0';
  if (dsnLen == SQL_NTS)
    {
      len = sizeof (buf) - 1;
    }
  else
    {
      len = min (sizeof (buf) - 1, dsnLen);
    }
  if (dsn != NULL)
    {
      strncpy (buf, dsn, len);
    }
  buf[len] = '\0';
  if (buf[0] == '\0')
    {
      setstatd (d, "invalid DSN", "S1090");
      return SQL_ERROR;
    }
  busy[0] = '\0';
  dbname[0] = '\0';
#ifdef WITHOUT_DRIVERMGR
//get info from odbc.ini using our own read function
  A4GL_getdsnattr (buf, "database", dbname, sizeof (dbname));
  if (dbname[0] == '\0')
    {
      strncpy (dbname, buf, sizeof (dbname));
      dbname[sizeof (dbname) - 1] = '\0';
    }
  A4GL_getdsnattr (buf, "timeout", busy, sizeof (busy));
  tflag[0] = '\0';
  nwflag[0] = '\0';
#ifdef ASYNC
  A4GL_getdsnattr (buf, "threaded", tflag, sizeof (tflag));
#endif
  A4GL_getdsnattr (buf, "nowchar", nwflag, sizeof (nwflag));
#else
//get info from odbc.ini using driver manager function calls:
  SQLGetPrivateProfileString (buf, "timeout", "1000",
			      busy, sizeof (busy), ODBC_INI);
  SQLGetPrivateProfileString (buf, "database", "",
			      dbname, sizeof (dbname), ODBC_INI);
#ifdef ASYNC
  SQLGetPrivateProfileString (buf, "threaded", "",
			      tflag, sizeof (tflag), ODBC_INI);
#endif
  SQLGetPrivateProfileString (buf, "nowchar", "",
			      nwflag, sizeof (nwflag), ODBC_INI);
#endif

  //Now we can connect:
  //d->nowchar = getbool(nwflag);
  //return dbopen(d, dbname, dsn, tflag, busy);
}


#endif //ifdef EXAMPLE

/* ================================ EOF ================================ */
