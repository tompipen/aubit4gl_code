#include <mysql.h>
#include <stdio.h>
#include "../a4gl_lib_sql_int.h"

dll_export sqlca_struct a4gl_sqlca;
dll_export int status;
#define CACHE_COLUMN '&'
int GetColNo = 0;
char GetColTab[2000];


#define PHASE_PRE_FETCH 0
#define PHASE_POST_FETCH 1
#define STMT_CANT_PREPARE -1
static MYSQL *conn = 0;
int isconnected = 0;
static char curr_dbname[256] = "";
char last_err[512] = "";
char curr_conn[512] = "default";




/*****************************************************************************/
// ***********   TRIVIAL IMPLEMENTATIONS   ************************************
/*****************************************************************************/

char *
A4GLSQLLIB_A4GLSQL_dbms_dialect (void)
{
  return "MYSQLDIRECT";
}


/*****************************************************************************/
char *
A4GLSQLLIB_A4GLSQL_dbms_name (void)
{
  return "MYSQL";
}

/*****************************************************************************/

char *
A4GLSQLLIB_A4GLSQL_syscolval_expr (char *tabname, char *colname, char *typ)
{
  // No syscolval or syscolatt atm
  return 0;
}

/*****************************************************************************/
t_expr_str_list *
A4GLSQLLIB_A4GLSQL_get_validation_expr (char *tabname, char *colname)
{
  // No syscolval or syscolatt atm
  return 0;
}

/*****************************************************************************/

int
A4GLSQLLIB_A4GLSQL_init_session_internal (char *sessname, char *dsn,
					  char *usr, char *pwd)
{
  // No sessions atm
  A4GL_exitwith ("Sessions not implemented");
  return 0;
}

/*****************************************************************************/
int
A4GLSQLLIB_A4GLSQL_set_conn_internal (char *sessname)
{
  // No sessions atm
  A4GL_exitwith ("Sessions not implemented");
  return 0;
}


/*****************************************************************************/
char *
A4GLSQLLIB_A4GLSQL_get_currdbname (void)
{
  return curr_dbname;
}

/*****************************************************************************/
char *
A4GLSQLLIB_A4GLSQL_get_curr_conn (void)
{
  return curr_conn;
}

/*****************************************************************************/
char *
A4GLSQLLIB_A4GLSQL_get_sqlerrm (void)
{
  return a4gl_sqlca.sqlerrm;
}

// *************************************************************************



/*****************************************************************************/

void
A4GL_AddColumn (char *local_GetColTab, int local_GetColNo, char *s, int d,
		int sz)
{
  char buff[256];
  char buff2[256];

  sprintf (buff, "%s_%d", local_GetColTab, local_GetColNo);

  if (A4GL_has_pointer (buff, CACHE_COLUMN))
    {
      /* Got the column cached ! */
      return;
    }
  sprintf (buff2, "%s %d %d", s, d, sz);
  A4GL_add_pointer (buff, CACHE_COLUMN, strdup (buff2));
}

/*****************************************************************************/
void
niy_dtype (int dtype)
{
  printf ("Datatype : %d has not been implemented yet...\n", dtype);
}

/*****************************************************************************/
void
conv_sqldtype (int dt, int len, int prec, int *fgldtype, int *fglprc)
{

  *fgldtype = 0;
  *fglprc = 0;


  switch (dt)
    {
    case MYSQL_TYPE_DECIMAL:
      niy_dtype (dt);
      break;
    case MYSQL_TYPE_TINY:
      *fgldtype = DTYPE_SMINT;
      *fglprc = 0;
      break;
    case MYSQL_TYPE_SHORT:
      *fgldtype = DTYPE_SMINT;
      *fglprc = 0;
      break;
    case MYSQL_TYPE_LONG:
      *fgldtype = DTYPE_SMINT;
      *fglprc = 0;
      break;
    case MYSQL_TYPE_FLOAT:
      *fgldtype = DTYPE_SMFLOAT;
      *fglprc = 0;
      break;
    case MYSQL_TYPE_DOUBLE:
      *fgldtype = DTYPE_FLOAT;
      *fglprc = 0;
      break;
    case MYSQL_TYPE_NULL:
      niy_dtype (dt);
      break;
    case MYSQL_TYPE_TIMESTAMP:
      *fgldtype = DTYPE_DTIME;
      *fglprc = 0;
      break;
    case MYSQL_TYPE_LONGLONG:
      niy_dtype (dt);
      break;
    case MYSQL_TYPE_INT24:
      niy_dtype (dt);
      break;
    case MYSQL_TYPE_DATE:
      *fgldtype = DTYPE_DATE;
      *fglprc = 0;
      break;
    case MYSQL_TYPE_TIME:
      *fgldtype = DTYPE_DTIME;
      *fglprc = 0x46;
      break;
    case MYSQL_TYPE_DATETIME:
      *fgldtype = DTYPE_DTIME;
      *fglprc = 0x46;
      break;
    case MYSQL_TYPE_YEAR:
      *fgldtype = DTYPE_SMINT;
      *fglprc = 0;
      break;
    case MYSQL_TYPE_NEWDATE:
      *fgldtype = DTYPE_DATE;
      *fglprc = 0;
      break;
    case MYSQL_TYPE_ENUM:
      *fgldtype = DTYPE_INT;
      *fglprc = 0;
      break;
    case MYSQL_TYPE_SET:
      niy_dtype (dt);
      break;
    case MYSQL_TYPE_TINY_BLOB:
      niy_dtype (dt);
      break;
    case MYSQL_TYPE_MEDIUM_BLOB:
      niy_dtype (dt);
      break;
    case MYSQL_TYPE_LONG_BLOB:
      niy_dtype (dt);
      break;
    case MYSQL_TYPE_BLOB:
      niy_dtype (dt);
      break;
    case MYSQL_TYPE_VAR_STRING:
      *fgldtype = DTYPE_VCHAR;
      *fglprc = 0;
      break;
    case MYSQL_TYPE_STRING:
      *fgldtype = DTYPE_CHAR;
      *fglprc = len;
      break;			// Odd - I get len=30 when length is actually 10....
    case MYSQL_TYPE_GEOMETRY:
      niy_dtype (dt);
      break;
    }
}



/*****************************************************************************/

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

/*****************************************************************************/
int
A4GLSQLLIB_A4GLSQL_initlib (void)
{
  conn = mysql_init (NULL);
  isconnected = 0;
  return 1;
}


/*****************************************************************************/
int
A4GLSQLLIB_A4GLSQL_init_connection_internal (char *dbName)
{
  char dbname[2000];
  char *u;
  char *p;
  char uname_acl[256];
  char passwd_acl[256];
  char empty[10] = "None";

  isconnected = 0;
  strcpy (dbname, dbName);

  A4GL_trim (dbname);

  if (A4GL_sqlid_from_aclfile (dbname, uname_acl, passwd_acl))
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
      u = acl_getenv ("SQLUID");


#if ( ! defined(__MINGW32__))
      if (u == 0 || *u == '\0')
	u = getlogin ();
#else
#ifdef DEBUG
      A4GL_debug ("avoided getlogin() call");
#endif
#endif
      if (u == 0 || *u == '\0')
	u = acl_getenv ("LOGNAME");
      if (u == 0)
	u = empty;

      p = acl_getenv ("SQLPWD");
      if ((p == 0 || *p == '\0') && *u > '\0')
	{
	  // ----
	  // maybe prompt for it ? 
	}
      if (p == 0)
	p = empty;
    }

  A4GL_debug ("Connecting : u=%s p=%s dbname=%s", u, p, dbname);
  if (!mysql_real_connect
      (conn, acl_getenv ("MYSQL_SERVER"), u, p, dbname, 0, NULL, 0))
    {
      strcpy (last_err, (char *) mysql_error (conn));
      A4GL_set_errm (dbname);
      A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (-1);
      A4GL_exitwith ("Could not connect to database");
    }



  isconnected = 1;
  strcpy (curr_dbname, dbname);
  return 0;

}

/*****************************************************************************/
void
report_sql_error ()
{

  printf ("%d - %s\n", mysql_errno (conn), mysql_error (conn));
  A4GL_exitwith ("SQL Transaction Error");
}

/*****************************************************************************/
void
A4GLSQLLIB_A4GLSQL_commit_rollback (int mode)
{
  if (mode == -1)
    {
      if (mysql_query (conn, "BEGIN WORK") != 0)
	{
	  report_sql_error ();
	}
    }
  if (mode == 0)
    {
      if (mysql_query (conn, "ROLLBACK") != 0)
	{
	  report_sql_error ();
	}
    }
  if (mode == 1)
    {
      if (mysql_query (conn, "COMMIT") != 0)
	{
	  report_sql_error ();
	}
    }
}

/*****************************************************************************/

int
A4GLSQLLIB_A4GLSQL_close_session_internal (char *sessname)
{
  A4GL_assertion (1, "Close session not implemented");
  printf ("Close Session : %s\n", sessname);
}


/*****************************************************************************/
void
A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (int a)
{
  if (a > 0 && a != 100)
    a = 0 - a;
  a4gl_status = a;
  a4gl_sqlca.sqlcode = a;
  A4GLSQL_set_status (a, 1);
}



/*****************************************************************************/

char *
A4GLSQLLIB_A4GLSQL_get_errmsg (int a)
{
  if (a == -1)
    return last_err;
  if (mysql_errno (conn) == a)
    {
      return (char *) mysql_error (conn);
    }

  // probably about right anyway..
  return (char *) mysql_error (conn);

}


/**
 *   Describe a column for an existing statement
 *   
 *     @param hstmt The statement handler.
 *     @param colno
 *     @param type The type of the decribing information to return.
 *          - 0: The column type.
 *          - 1: The column name.
 *          - 2: The scale.
 *          - 3: The column length.
 *          - 4: Nullable or not
 *          - 5: No of columns in result
 *          - 6: Number of rows in result
 *     @return The description wanted  or zero if there was an error.
 */

int
A4GL_describecolumn (MYSQL_STMT * stmt, int colno, int type)
{
  MYSQL_RES *prepare_meta_result;
  MYSQL_ROW row;
  int column_count;
  int i;
  int dtype;
  int prc;
  MYSQL_FIELD *field;
  int rval;

  if (type == 6)
    return mysql_stmt_affected_rows (stmt);

  if (type == 5)
    return mysql_stmt_field_count (stmt);

  prepare_meta_result = mysql_stmt_result_metadata (stmt);

  if (!prepare_meta_result)
    {
      printf ("No meta result\n");
      return 0;
    }

  //mysql_store_result(prepare_meta_result);

  column_count = mysql_num_fields (prepare_meta_result);
  //printf ("Column count : %d\n", column_count);

  if (colno > column_count)
    {
      mysql_free_result (prepare_meta_result);
      A4GL_exitwith ("Column out of range");
      return 0;
    }


  field = mysql_fetch_field_direct (prepare_meta_result, colno);
  // Now - which part of 'field' do we want...
  //
  //
  conv_sqldtype (field->type, field->length, field->decimals, &dtype, &prc);
  switch (type)
    {
    case 0:
      rval = dtype;
      break;
    case 1:
      rval = (long) field->name;
      break;
    case 2:
      rval = field->decimals;
      break;
    case 3:
      rval = field->length;
      break;
    case 4:
      rval = 1;
      break;			// Nullable ? 
    }


  mysql_free_result (prepare_meta_result);
  return rval;
}


/*****************************************************************************/

long
A4GLSQLLIB_A4GLSQL_describe_stmt (char *stmt, int colno, int type)
{
  struct s_sid *sid;
  struct s_cid *cid;
  MYSQL_STMT *mstmt;
  int z;
  sid = A4GLSQL_find_prepare (stmt);
  if (sid == 0)
    {
      cid = A4GLSQL_find_cursor (stmt);
      if (cid == 0)
	{
	  A4GL_exitwith ("Could not find statement or cursor specified");
	  return 0;

	}
      mstmt = cid->hstmt;

    }
  else
    {
      mstmt = sid->hstmt;
    }

  if (sid == 0 && cid == 0)
    {
      A4GL_exitwith ("Statement could not be found");
    }
  z = A4GL_describecolumn (mstmt, colno, type);
  return z;
}


/*****************************************************************************/

void *
A4GLSQLLIB_A4GLSQL_prepare_select_internal (void *ibind, int ni, void *obind,
					    int no, char *s)
{
  MYSQL_STMT *stmt;
  struct s_sid *sid;
  sid = acl_malloc2 (sizeof (struct s_sid));

  sid->select = strdup (s);

  sid->ibind = malloc (sizeof (struct BINDING) * ni);
  memcpy (sid->ibind, ibind, sizeof (struct BINDING) * ni);

  sid->obind = malloc (sizeof (struct BINDING) * no);
  memcpy (sid->obind, obind, sizeof (struct BINDING) * no);

  sid->ni = ni;
  sid->no = no;

  stmt = mysql_stmt_init (conn);

  if (strlen (curr_dbname) == 0)
    {
      A4GL_exitwith ("No database connection");
      return 0;
    }

  if (strlen (s) == 0)
    {
      sid->hstmt = (void *) STMT_CANT_PREPARE;
      return sid;
    }
  if (mysql_stmt_prepare (stmt, s, strlen (s)) != 0)
    {
      // Some error...
      A4GL_debug ("Err : %s (%p)\n", mysql_stmt_error (stmt), stmt);
      A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (mysql_errno (conn));
      if (mysql_errno (conn) == 1295)
	{			// Can't prepare it...
	  sid->hstmt = (void *) STMT_CANT_PREPARE;
	  return sid;
	}
      sid->hstmt = 0;
      return sid;
    }
  sid->hstmt = stmt;
  return sid;
}



/*****************************************************************************/
int
A4GLSQLLIB_A4GLSQL_get_columns (char *tabname, char *colname, int *dtype,
				int *size)
{
  MYSQL_RES *result;
  MYSQL_FIELD *field;
  int cnt;
  char buff[256];
  if (strlen (curr_dbname) == 0)
    {
      return 0;
    }

  strcpy (GetColTab, tabname);
  sprintf (buff, "%s_1", tabname);

  if (A4GL_has_pointer (buff, CACHE_COLUMN))
    {
      GetColNo = 0;
      return 1;
    }


  result = mysql_list_fields (conn, tabname, NULL);

  if (!result)
    {
      //printf ("No result for %s on %p\n", buff, conn);
      return 0;
    }

  cnt = 0;
  while ((field = mysql_fetch_field (result)))
    {
      int r;
      int dtype;
      int prc;
      char cn[256];
      strcpy (cn, field->name);
      A4GL_convlower (cn);
      cnt++;
      conv_sqldtype (field->type, field->length, field->decimals, &dtype,
		     &prc);
      A4GL_AddColumn (GetColTab, cnt, cn, dtype, prc);

      //printf ("\n");
    }

  GetColNo = 0;

  mysql_free_result (result);
  return 1;
}



/*****************************************************************************/

int
A4GLSQLLIB_A4GLSQL_next_column (char **colname, int *dtype, int *size)
{
  char buff[200];
  GetColNo++;

  sprintf (buff, "%s_%d", GetColTab, GetColNo);
  if (A4GL_has_pointer (buff, CACHE_COLUMN))
    {
      static char buffx[2000];
      char *ptr;

      ptr = A4GL_find_pointer (buff, CACHE_COLUMN);

      if (ptr)
	{
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

/*****************************************************************************/
int
A4GLSQLLIB_A4GLSQL_end_get_columns (void)
{
  // Nothing to do..
}










/*****************************************************************************/

int
A4GL_fill_array_databases (int mx, char *arr1, int szarr1, char *arr2,
			   int szarr2)
{
  MYSQL_RES *res;
  MYSQL_ROW row;
  int column_count;
  int n;
  int cnt;

  if (isconnected == 0)
    return 0;

  res = mysql_list_dbs (conn, NULL);

  printf ("Fill..");
  if (res == 0)
    return 0;



  printf ("Nrows..\n");
  n = mysql_num_rows (res);
  printf ("Nrows %d\n", n);
  if (n > mx)
    n = mx;


  column_count = mysql_num_fields (res);
  printf ("column_count : %d\n", column_count);
  while ((row = mysql_fetch_row (res)) != NULL)
    {
      int a;
      if (arr1 != 0)
	{
	  strncpy (&arr1[cnt * (szarr1 + 1)], row[0], szarr1);
	}
      cnt++;
      if (cnt >= n)
	break;
    }
  return cnt;

}

/*****************************************************************************/
int
A4GL_fill_array_tables (int mx, char *arr1, int szarr1, char *arr2,
			int szarr2, int mode)
{

  A4GL_assertion (1, "Not implemented yet (fill_array_tables)");
}

/*****************************************************************************/
int
A4GL_fill_array_columns (int mx, char *arr1, int szarr1, char *arr2,
			 int szarr2, int mode, char *info)
{
  int cnt = 0;
  MYSQL_RES *result;
  MYSQL_FIELD *field;
  result = mysql_list_fields (conn, info, NULL);

  while ((field = mysql_fetch_field (result)))
    {
      int r;
      int dtype;
      int prc;
      char cn[256];
      //printf ("field name %s\n", field->name);
      //printf ("field type %d\n", field->type);
      //printf ("field length %d\n", field->length);
      //printf ("field decimals %d\n", field->decimals);
      strcpy (cn, field->name);
      A4GL_convlower (cn);
      conv_sqldtype (field->type, field->length, field->decimals, &dtype,
		     &prc);
      if (arr1 != 0)
	{
	  strncpy (&arr1[cnt * (szarr1 + 1)], cn, szarr1);
	}
      if (arr2 != 0)
	{
	  switch (mode)
	    {
	    case 0:
	      sprintf (&arr2[cnt * (szarr2 + 1)], "%d", field->length);
	      break;
	    case 1:
	      sprintf (&arr2[cnt * (szarr2 + 1)], "%d", dtype);
	      break;

	    case 2:
	      sprintf (&arr2[cnt * (szarr2 + 1)], "%d(%d)", dtype, prc);
	      break;

	    default:
	      strncpy (&arr2[cnt * (szarr2 + 1)], cn, szarr2);
	      break;
	    }
	}

      cnt++;
    }
  return cnt;
}

/*****************************************************************************/
int
A4GLSQLLIB_A4GLSQL_fill_array (int mx, char *arr1, int szarr1, char *arr2,
			       int szarr2, char *service, int mode,
			       char *info)
{
#ifdef DEBUG
  A4GL_debug ("Fill array.... mode = %d", mode);
#endif

  if (strcmp (service, "DATABASES") == 0)
    {
#ifdef DEBUG
      A4GL_debug ("Get Databases");
#endif
      return A4GL_fill_array_databases (mx, arr1, szarr1, arr2, szarr2);
    }

  if (strcmp (service, "TABLES") == 0)
    {
#ifdef DEBUG
      A4GL_debug ("Get Tables");
#endif
      return A4GL_fill_array_tables (mx, arr1, szarr1, arr2, szarr2, mode);
    }

  if (strcmp (service, "COLUMNS") == 0)
    {
      int rval;
#ifdef DEBUG
      A4GL_debug ("Get columns");
#endif
      rval =
	A4GL_fill_array_columns (mx, arr1, szarr1, arr2, szarr2, mode, info);
      if (rval <= 0)
	{
	  // Try again a different way...
	  rval =
	    A4GL_fill_array_columns_mk2 (mx, arr1, szarr1, arr2, szarr2, mode,
					 info);
	}
      A4GL_debug ("Got %d\n", rval);
      return rval;
    }
#ifdef DEBUG
  A4GL_debug ("****** ERROR unknown service :%s", service);
#endif
  return (0);
}


/*****************************************************************************/


static void
copy_in_single_mysql_bind (MYSQL_STMT * stmt, void *associated_to,
			   struct BINDING *ibind, MYSQL_BIND * mibind,
			   my_bool * ind)
{
  MYSQL_TIME *mytime;
  char *mystr;
  double d;
  double *dptr;
  long *len;
  int dtype;

  if (A4GL_isnull (ibind->dtype, ibind->ptr))
    {
      *ind = 1;
    }
  else
    {
      *ind = 0;
    }

  switch (ibind->dtype & DTYPE_MASK)
    {
    case DTYPE_VCHAR:
    case DTYPE_CHAR:
      mibind->buffer_type = MYSQL_TYPE_STRING;
      mibind->buffer = ibind->ptr;
      mibind->is_null = ind;
      len = A4GL_alloc_associated_mem (associated_to, sizeof (long));
      *len = strlen (ibind->ptr);
      mibind->length = len;
      break;

    case DTYPE_SMINT:
      mibind->buffer_type = MYSQL_TYPE_SHORT;
      mibind->buffer = ibind->ptr;
      mibind->is_null = ind;
      mibind->length = 0;
      break;

    case DTYPE_INT:
      mibind->buffer_type = MYSQL_TYPE_LONG;
      mibind->buffer = ibind->ptr;
      mibind->is_null = ind;
      mibind->length = 0;
      break;

    case DTYPE_FLOAT:
      mibind->buffer_type = MYSQL_TYPE_DOUBLE;
      mibind->buffer = ibind->ptr;
      mibind->is_null = ind;
      mibind->length = 0;
      break;

    case DTYPE_SMFLOAT:
      mibind->buffer_type = MYSQL_TYPE_FLOAT;
      mibind->buffer = ibind->ptr;
      mibind->is_null = ind;
      mibind->length = 0;
      break;


    case DTYPE_SERIAL:
      mibind->buffer_type = MYSQL_TYPE_LONG;
      mibind->buffer = ibind->ptr;
      mibind->is_null = ind;
      mibind->length = 0;
      break;



    case DTYPE_DATE:
      {
	int d, m, y;
	mytime =
	  A4GL_alloc_associated_mem (associated_to, sizeof (MYSQL_TIME));
	A4GL_get_date (*(long *) ibind->ptr, &d, &m, &y);

	mytime->year = y;
	mytime->month = m;
	mytime->day = d;

	mibind->buffer_type = MYSQL_TYPE_DATE;
	mibind->buffer = mytime;
	mibind->is_null = ind;
	mibind->length = 0;
      }
      break;


    case DTYPE_DECIMAL:
      // We'll just treat it as a double for now...
      dtype = ibind->dtype + ENCODE_SIZE (ibind->size);
      A4GL_push_variable (ibind->ptr, dtype);
      d = A4GL_pop_double ();
      dptr = A4GL_alloc_associated_mem (associated_to, sizeof (double));
      *dptr = d;
      mibind->buffer_type = MYSQL_TYPE_DOUBLE;
      mibind->buffer = &d;
      mibind->is_null = ind;
      mibind->length = 0;
      break;

    case DTYPE_MONEY:
      // We'll just treat it as a double for now...
      dtype = ibind->dtype + ENCODE_SIZE (ibind->size);
      A4GL_push_variable (ibind->ptr, dtype);
      d = A4GL_pop_double ();
      dptr = A4GL_alloc_associated_mem (associated_to, sizeof (double));
      *dptr = d;
      mibind->buffer_type = MYSQL_TYPE_DOUBLE;
      mibind->buffer = &d;
      mibind->is_null = ind;
      mibind->length = 0;
      break;






    case DTYPE_DTIME:
      {
	char *ptr;
	int data[10];
	MYSQL_TIME *mytime;
	mytime =
	  A4GL_alloc_associated_mem (associated_to, sizeof (MYSQL_TIME));
	A4GL_decode_datetime (ibind->ptr, &data);
	mibind->buffer_type = MYSQL_TYPE_DATETIME;
	mytime->year = data[0];
	mytime->month = data[1];
	mytime->day = data[2];
	mytime->hour = data[3];
	mytime->minute = data[4];
	mytime->second = data[5];
	mytime->neg = 0;
	mytime->second_part = 0;
	mibind->buffer = mytime;
	mibind->is_null = ind;
	mibind->length = 0;
      }
      break;


    case DTYPE_INTERVAL:
      {
	char *ptr;
	mibind->buffer_type = MYSQL_TYPE_STRING;
	mibind->buffer = ibind->ptr;
	mibind->is_null = ind;
	ptr = A4GL_alloc_associated_mem (associated_to, 30);
	len = A4GL_alloc_associated_mem (associated_to, sizeof (long));
	A4GL_inttoc (ibind->ptr, ptr, 30);
	*len = strlen (ptr);
	mibind->length = len;
      }
      break;


    case DTYPE_BYTE:
      A4GL_assertion (1, "Not implemented yet (byte)");
      mibind->buffer_type = MYSQL_TYPE_LONG;
      mibind->buffer = ibind->ptr;
      mibind->is_null = ind;
      mibind->length = 0;
      break;

    case DTYPE_TEXT:
      A4GL_assertion (1, "Not implemented yet (text)");
      mibind->buffer_type = MYSQL_TYPE_LONG;
      mibind->buffer = ibind->ptr;
      mibind->is_null = ind;
      mibind->length = 0;
      break;

    }
}

/*****************************************************************************/
static MYSQL_BIND *
copy_from_aubit_to_mysql (MYSQL_STMT * stmt, void *associated_to,
			  struct BINDING *ibind, int ni)
{
  MYSQL_BIND *mysql_ibind;
  int a;
  my_bool *indicators;


  mysql_ibind =
    A4GL_alloc_associated_mem (associated_to, sizeof (MYSQL_BIND) * ni);
  indicators =
    A4GL_alloc_associated_mem (associated_to, sizeof (my_bool) * ni);

  for (a = 0; a < ni; a++)
    {
      copy_in_single_mysql_bind (stmt, associated_to, &ibind[a],
				 &mysql_ibind[a], &indicators[a]);
    }
  return mysql_ibind;
}


/*****************************************************************************/

static void
copy_out_single_mysql_bind (MYSQL_STMT * stmt, void *associated_to,
			    struct BINDING *obind, MYSQL_BIND * mobind,
			    my_bool * ind, int phase)
{
  MYSQL_TIME *mytime;
  char *mystr;
  double d;
  double *dptr;
  long *len;
  int dtype;

  if (ind && phase == PHASE_POST_FETCH)
    {
      if (*ind)
	{
	  A4GL_setnull (obind->dtype, (char *) obind->ptr, obind->size);
	  return;
	}
    }

  switch (obind->dtype & DTYPE_MASK)
    {
    case DTYPE_VCHAR:
    case DTYPE_CHAR:
      if (phase == PHASE_PRE_FETCH)
	{
	  mobind->buffer_type = MYSQL_TYPE_STRING;
	  mobind->buffer = obind->ptr;
	  mobind->is_null = ind;
	  len = A4GL_alloc_associated_mem (associated_to, sizeof (long));
	  mobind->buffer_length = obind->size;
	  mobind->length = len;
	}
      break;

    case DTYPE_SMINT:
      if (phase == PHASE_PRE_FETCH)
	{
	  mobind->buffer_type = MYSQL_TYPE_SHORT;
	  mobind->buffer = obind->ptr;
	  mobind->is_null = ind;
	  mobind->length = 0;
	}
      break;

    case DTYPE_INT:
      if (phase == PHASE_PRE_FETCH)
	{
	  mobind->buffer_type = MYSQL_TYPE_LONG;
	  mobind->buffer = obind->ptr;
	  mobind->is_null = ind;
	  mobind->length = 0;
	}
      break;

    case DTYPE_FLOAT:
      if (phase == PHASE_PRE_FETCH)
	{
	  mobind->buffer_type = MYSQL_TYPE_DOUBLE;
	  mobind->buffer = obind->ptr;
	  mobind->is_null = ind;
	  mobind->length = 0;
	}
      break;

    case DTYPE_SMFLOAT:
      if (phase == PHASE_PRE_FETCH)
	{
	  mobind->buffer_type = MYSQL_TYPE_FLOAT;
	  mobind->buffer = obind->ptr;
	  mobind->is_null = ind;
	  mobind->length = 0;
	}
      break;


    case DTYPE_SERIAL:
      if (phase == PHASE_PRE_FETCH)
	{
	  mobind->buffer_type = MYSQL_TYPE_LONG;
	  mobind->buffer = obind->ptr;
	  mobind->is_null = ind;
	  mobind->length = 0;
	}
      break;



    case DTYPE_DATE:
      if (phase == PHASE_PRE_FETCH)
	{
	  mytime =
	    A4GL_alloc_associated_mem (associated_to, sizeof (MYSQL_TIME));
	  mobind->buffer_type = MYSQL_TYPE_DATE;
	  mobind->buffer = mytime;
	  mobind->is_null = ind;
	  mobind->length = 0;
	}

      if (phase == PHASE_POST_FETCH)
	{
	  int i_date;
	  mytime = mobind->buffer;
	  //i_date=0;
	  i_date = A4GL_gen_dateno (mytime->day, mytime->month, mytime->year);
	  *(long *) obind->ptr = i_date;
	}
      break;


    case DTYPE_DECIMAL:
      if (phase == PHASE_PRE_FETCH)
	{
	  dptr = A4GL_alloc_associated_mem (associated_to, sizeof (double));
	  mobind->buffer_type = MYSQL_TYPE_DOUBLE;
	  mobind->buffer = dptr;
	  mobind->is_null = ind;
	  mobind->length = 0;
	}

      if (phase == PHASE_POST_FETCH)
	{
	  // We'll just treat it as a double for now...
	  dtype = obind->dtype + ENCODE_SIZE (obind->size);
	  d = *(double *) mobind->buffer;
	  A4GL_push_double (d);
	  A4GL_pop_var2 (obind->ptr, dtype,obind->size);
	}
      break;

    case DTYPE_MONEY:
      if (phase == PHASE_PRE_FETCH)
	{
	  dptr = A4GL_alloc_associated_mem (associated_to, sizeof (double));
	  mobind->buffer_type = MYSQL_TYPE_DOUBLE;
	  mobind->buffer = dptr;
	  mobind->is_null = ind;
	  mobind->length = 0;
	}

      if (phase == PHASE_POST_FETCH)
	{
	  // We'll just treat it as a double for now...
	  dtype = obind->dtype + ENCODE_SIZE (obind->size);
	  d = *(double *) mobind->buffer;
	  A4GL_push_double (d);
	  A4GL_pop_var2 (obind->ptr, dtype,obind->size);
	}
      break;



    case DTYPE_DTIME:
      if (phase == PHASE_PRE_FETCH)
	{
	  mytime =
	    A4GL_alloc_associated_mem (associated_to, sizeof (MYSQL_TIME));
	  mobind->buffer_type = MYSQL_TYPE_DATETIME;
	  mobind->buffer = mytime;
	  mobind->is_null = ind;
	  mobind->length = 0;
	}

      if (phase == PHASE_POST_FETCH)
	{
	  int i_date;
	  char buff[256];
	  mytime = mobind->buffer;
	  sprintf (buff, "%04d-%02d-%02d %02d:%02d:%02d", mytime->year,
		   mytime->month, mytime->day, mytime->hour, mytime->minute,
		   mytime->second);
	  A4GL_ctodt (buff, obind->ptr, obind->size);
	}
      break;

    case DTYPE_BYTE:
      A4GL_assertion (1, "Not implemented yet (byte2)");
      break;

    case DTYPE_TEXT:
      A4GL_assertion (1, "Not implemented yet (text2)");
      break;

    case DTYPE_INTERVAL:
      A4GL_assertion (1, "Not implemented yet (interval2)");
      break;

    }
}

/*****************************************************************************/

static int
fetch_from_mysql_to_aubit (MYSQL_STMT * stmt, void *associated_to,
			   struct BINDING *obind, int no)
{
  MYSQL_BIND *mysql_obind;
  int a;
  int x;
  my_bool *indicators;

  mysql_obind =
    A4GL_alloc_associated_mem (associated_to, sizeof (MYSQL_BIND) * no);
  indicators =
    A4GL_alloc_associated_mem (associated_to, sizeof (my_bool) * no);

  for (a = 0; a < no; a++)
    {
      /* Bind... */
      copy_out_single_mysql_bind (stmt, associated_to, &obind[a],
				  &mysql_obind[a], &indicators[a],
				  PHASE_PRE_FETCH);
      indicators[a] = 0;
    }

  mysql_stmt_bind_result (stmt, mysql_obind);
  x = mysql_stmt_fetch (stmt);

  if (x == MYSQL_NO_DATA)
    {
      A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (100);
      return 0;
    }

  if (x == 1)
    {
      A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (mysql_errno (conn));
      return 0;
    }

  for (a = 0; a < no; a++)
    {
      /* Use Bind... */
      copy_out_single_mysql_bind (stmt, associated_to, &obind[a],
				  &mysql_obind[a], &indicators[a],
				  PHASE_POST_FETCH);
    }

  return 1;

}

/*****************************************************************************/

int static
execute_sql (MYSQL_STMT * stmt, char *sql, struct BINDING *ibind, int ni,
	     struct BINDING *obind, int no)
{
  MYSQL_BIND *mysql_ibind;
  int param_count;
  int id;

  if (strlen (sql) == 0)
    {
      A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (0);	// Nothing to do...
      return 1;
    }

  if ((void *) stmt == (void *) STMT_CANT_PREPARE)
    {
      if (mysql_query (conn, sql) == 0)
	{
	  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (0);
	  return 1;		// OK
	}
      else
	{
	  A4GL_debug ("Error : %s\n", mysql_error (conn));
	  A4GL_set_errm ((char *)mysql_error (conn));
	  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (mysql_errno (conn));
	  return 0;		// Failed
	}
    }


  param_count = mysql_stmt_param_count (stmt);	// Number of paramters...
  if (ni != param_count)
    {
      A4GL_debug ("Got %d params - expecting %d\n", ni, param_count);
      A4GL_exitwith ("Too many or too few host variables");
      return 0;
    }
  if (ni)
    {
      mysql_ibind = copy_from_aubit_to_mysql (stmt, (void *) stmt, ibind, ni);
    }
  else
    {
      mysql_ibind = 0;
    }

  if (mysql_ibind)
    {
      mysql_stmt_bind_param (stmt, mysql_ibind);
    }


  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (0);
  //a4gl_status=0;
  //a4gl_sqlca.sqlcode=0;

  if (mysql_stmt_execute (stmt))
    {
      // Some error ? 
      A4GL_debug ("Error : %s (%p)\n", mysql_stmt_error (stmt), stmt);
      A4GL_set_errm ((char *)mysql_stmt_error (stmt));
      A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (mysql_errno (conn));
      return 0;
    }

  id = mysql_stmt_insert_id (stmt);
  if (id == 0)
    {
      a4gl_sqlca.sqlerrd[1] = mysql_stmt_affected_rows (stmt);
    }
  else
    {
      a4gl_sqlca.sqlerrd[1] = id;
    }

  strcpy (a4gl_sqlca.sqlstate, (char *)mysql_stmt_sqlstate (stmt));
  return 1;
}

/*****************************************************************************/

int
A4GLSQLLIB_A4GLSQL_execute_implicit_select (void *vsid, int singleton)
{
  struct s_sid *sid;
  int nibind = 0;
  struct BINDING *ibind = 0;

  int rc = 0;
  sid = vsid;

  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (0);
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


  nibind = sid->ni;
  ibind = sid->ibind;

  A4GL_debug ("Execute : %s\n", sid->select);

  strcpy (a4gl_sqlca.sqlawarn, "       ");


  if (execute_sql (sid->hstmt, sid->select, ibind, nibind, 0, 0))
    {
      int nresultcols;
      int copy_out_n;
      int nrows;

      // Get all the details in one go - lets us get our rowcount ;-)
      mysql_stmt_store_result (sid->hstmt);
      nrows = mysql_stmt_num_rows (sid->hstmt);
      nresultcols = mysql_stmt_field_count (sid->hstmt);

      //mysql_store_result (sid->hstmt);

      if (nrows == 0)
	{
	  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (100);
	}
      else
	{
	  if (nrows > 1)
	    {
	      A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (-284);
	    }
	}

      if (nresultcols && nresultcols != sid->no)
	{
	  strcpy (a4gl_sqlca.sqlawarn, "       ");
	  a4gl_sqlca.sqlawarn[0] = 'W';
	  a4gl_sqlca.sqlawarn[3] = 'W';
	}


      if (nrows == 1)
	{
	  int a;
	  // we don't want to be copying out more than we got in...
	  copy_out_n = nresultcols;
	  if (copy_out_n > sid->no)
	    {
	      copy_out_n = sid->no;
	    }
	  fetch_from_mysql_to_aubit (sid->hstmt, sid->hstmt, sid->obind,
				     copy_out_n);
	}

      A4GL_free_associated_mem (sid->hstmt);


      if (singleton)
	{
	  mysql_stmt_close (sid->hstmt);
	}
      A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (0);
    }
}

/*****************************************************************************/

int
A4GLSQLLIB_A4GLSQL_execute_implicit_sql (void *vsid, int singleton)
{
  struct s_sid *sid;
  int nibind = 0;
  struct BINDING *ibind = 0;

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


  nibind = sid->ni;
  ibind = sid->ibind;

  A4GL_debug ("Execute : %s\n", sid->select);

  if (sid->hstmt == 0)
    {
      return 0;
    }

  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (0);

  if (execute_sql (sid->hstmt, sid->select, ibind, nibind, 0, 0))
    {

      if (singleton)
	{
	  A4GL_free_associated_mem (sid->hstmt);
	  if (sid->hstmt != (void *) STMT_CANT_PREPARE)
	    {
	      mysql_stmt_close (sid->hstmt);
	    }
	}
    }
  return 1;
}

/*****************************************************************************/
void *
A4GLSQLLIB_A4GLSQL_declare_cursor (int upd_hold, void *vsid, int scroll,
				   char *cursname)
{
  struct s_sid *nsid;
  struct s_cid *cid;
  struct s_sid *sid;
  sid = vsid;

  if (sid == 0)
    {
      A4GL_exitwith ("Can't declare cursor for non-prepared statement");
      return 0;
    }

  cid = acl_malloc2 (sizeof (struct s_cid));

  cid->statement = sid;
  cid->hstmt = 0;
  cid->mode = upd_hold + (scroll * 256);
  cid->o_ibind = 0;
  cid->o_obind = 0;
  cid->o_ni = 0;
  cid->o_no = 0;
  A4GL_add_pointer (cursname, CURCODE, cid);


  return cid;
}

/*****************************************************************************/
int
A4GLSQLLIB_A4GLSQL_open_cursor (char *s, int ni, void *vibind)
{
  struct s_cid *cid;
  struct BINDING *ibind;
  int nresultcols;
  int copy_out_n;
  int nrows;

  // Here - we'll bind the inputs
  // and then execute the statement...
  ibind = vibind;
  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (0);
  cid = A4GLSQL_find_cursor (s);

  if (cid == 0)
    {
      A4GL_exitwith ("Can't open cursor that hasn't been defined");
      return -1;
    }

  if (cid->hstmt)
    {
      A4GLSQLLIB_A4GLSQL_close_cursor (s);	// close it first...
    }

  cid->currpos = 0;

  if (ni != 0)
    {
      cid->o_ibind = ibind;
      cid->o_ni = ni;
    }
  else
    {
      ibind = cid->statement->ibind;
      ni = cid->statement->ni;
    }

  strcpy (a4gl_sqlca.sqlawarn, "       ");

  if (!execute_sql
      (cid->statement->hstmt, cid->statement->select, ibind, ni, 0, 0))
    {

      return 0;
    }
  if (cid->mode & 256)
    {				// Scroll cursor...
      mysql_stmt_store_result (cid->statement->hstmt);
      cid->nrows = mysql_stmt_num_rows (cid->statement->hstmt);
    }
  else
    {
      // This effectively makes all cursors scroll cursors
      // but if we don't do it - we get "Commands out of sequence" errors....
      mysql_stmt_store_result (cid->statement->hstmt);
      cid->nrows = -1;
    }

  nresultcols = mysql_stmt_field_count (cid->statement->hstmt);

  cid->sql_no = nresultcols;
  /*
     if (nresultcols && nresultcols !=no)
     {
     strcpy (a4gl_sqlca.sqlawarn, "       ");
     a4gl_sqlca.sqlawarn[0] = 'W';
     a4gl_sqlca.sqlawarn[3] = 'W';
     }
   */

}

/*****************************************************************************/
int
A4GLSQLLIB_A4GLSQL_fetch_cursor (char *cursor_name, int fetch_mode,
				 int fetch_when, int nobind, void *vobind)
{
  struct BINDING *obind;
  struct s_cid *cid;
  int v_for_ptr;
  int nresultcols;
  int copy_out_n;

  obind = vobind;

  cid = A4GLSQL_find_cursor (cursor_name);
  if (cid == 0)
    {
      A4GL_exitwith_sql ("Cursor not found");
      return 0;
    }
  nresultcols = mysql_stmt_field_count (cid->statement->hstmt);
  copy_out_n = nresultcols;

  if (nobind == 0)
    {
      if (cid->o_obind)
	{
	  obind = cid->o_obind;
	  nobind = cid->o_no;
	}
      else
	{
	  obind = cid->statement->obind;
	  nobind = cid->statement->no;
	}
    }

  if (copy_out_n > nobind)
    {
      copy_out_n = nobind;
    }

  if (cid->nrows == -1
      && (fetch_mode == FETCH_ABSOLUTE
	  || (fetch_mode == FETCH_RELATIVE && fetch_when != 1)))
    {
      // declared as a normal cursor - but they want to scroll ? 
      A4GL_exitwith ("Fetch Relative or Absolute on a non-scroll cursor");
      return 0;
    }


  switch (fetch_mode)
    {
    case FETCH_ABSOLUTE:
      if (fetch_when == -1)
	{
	  int last;
	  cid->currpos = cid->nrows;
	  mysql_stmt_data_seek (cid->statement->hstmt, cid->currpos - 1);
	}
      else
	{
	  cid->currpos = fetch_when;
	  mysql_stmt_data_seek (cid->statement->hstmt, cid->currpos - 1);
	}
      break;

    case FETCH_RELATIVE:
      if (fetch_when != 1)
	{
	  cid->currpos += fetch_when;
	  mysql_stmt_data_seek (cid->statement->hstmt, cid->currpos - 1);
	  if (cid->currpos > cid->nrows || cid->currpos < 0)
	    {
	      A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (100);
	      return 0;
	    }
	}
      else
	{
	  cid->currpos++;
	}
      break;
    }

  fetch_from_mysql_to_aubit (cid->statement->hstmt, &v_for_ptr, obind,
			     copy_out_n);
  A4GL_free_associated_mem (&v_for_ptr);


  return 1;
}

/*****************************************************************************/

int
A4GLSQLLIB_A4GLSQL_close_cursor (char *currname)
{
  struct s_cid *ptr;
  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (0);
  ptr = A4GL_find_pointer_val (currname, CURCODE);

  if (ptr == 0)
    {
      A4GL_exitwith ("Can't close cursor that hasn't been defined");
      return -1;
    }

  if (ptr->hstmt)
    {
      mysql_stmt_close (ptr->hstmt);
      A4GL_free_associated_mem (ptr->hstmt);
    }


  ptr->hstmt = 0;
  return 1;
}

/*****************************************************************************/
void
A4GLSQLLIB_A4GLSQL_free_cursor (char *currname)
{
  struct s_cid *ptr;
  A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (0);
  ptr = A4GL_find_pointer_val (currname, CURCODE);

  if (ptr == 0)
    {
      A4GL_exitwith ("Can't free cursor that hasn't been defined");
      return;
    }

  if (ptr->hstmt)
    {
      mysql_stmt_close (ptr->hstmt);
      A4GL_free_associated_mem (ptr->hstmt);
    }


  ptr->hstmt = 0;
  A4GL_free_associated_mem (ptr);
  free (ptr);


}


/*****************************************************************************/

void
A4GLSQLLIB_A4GLSQL_put_insert (void *vibind, int n)
{
  char *cursorName;
  struct BINDING *ibind;
  struct s_cid *cid;
  int ni;
  struct s_sid *sid;
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
  execute_sql (sid->hstmt, sid->select, ibind, ni, 0, 0);
}


void
A4GLSQLLIB_A4GLSQL_flush_cursor (char *cursor)
{
  // Does nothing...
}

void
A4GLSQLLIB_A4GLSQL_unload_data_internal (char *fname, char *delims,
					 char *sql1, int nbind, void *ibind)
{

  FILE *f;
  MYSQL_STMT *stmt;
  stmt = mysql_stmt_init (conn);

  f = fopen (fname, "w");

  if (f == 0)
    {
      A4GL_exitwith ("Can't open file for unload");
      return;
    }


  if (mysql_stmt_prepare (stmt, sql1, strlen (sql1)))
    {
      A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (mysql_errno (conn));
      return;
    }

  if (execute_sql (stmt, sql1, ibind, nbind, 0, 0))
    {
      int nresultcols;
      int copy_out_n;
      int nrows;
      MYSQL_BIND *b;
      void **buffs;


      // Get all the details in one go - lets us get our rowcount ;-)
      mysql_stmt_store_result (stmt);
      nrows = mysql_stmt_num_rows (stmt);
      nresultcols = mysql_stmt_field_count (stmt);

      if (nrows == 0)
	{
	  return;		// nothing to do...
	}

      A4GL_describecolumn (stmt, 0, 0);

      if (nresultcols && nrows)
	{
	  int a;
	  MYSQL_RES *prepare_meta_result;
	  MYSQL_ROW row;
	  int dtype;
	  int prc;
	  int sz;
	  my_bool *ind;
	  long *longs;
	  int *dtypes;
	  int *sizes;

	  // Lets set up some space to store everything....
	  //
	  prepare_meta_result = mysql_stmt_result_metadata (stmt);
	  b = malloc (sizeof (MYSQL_BIND) * nresultcols);
	  buffs = malloc (sizeof (void *) * nresultcols);
	  ind = malloc (sizeof (my_bool) * nresultcols);
	  longs = malloc (sizeof (long) * nresultcols);
	  sizes = malloc (sizeof (int) * nresultcols);
	  dtypes = malloc (sizeof (int) * nresultcols);

	  memset (b, 0, sizeof (MYSQL_BIND) * nresultcols);
	  for (a = 0; a < nresultcols; a++)
	    {
	      int isset = 0;
	      MYSQL_FIELD *field;
	      field = mysql_fetch_field_direct (prepare_meta_result, a);
	      conv_sqldtype (field->type, field->length, field->decimals,
			     &dtype, &prc);


	      dtypes[a] = dtype;
	      sizes[a] = prc;

	      buffs[a] = 0;

	      switch (dtype & DTYPE_MASK)
		{
		case DTYPE_CHAR:
		  sz = field->length + 1;
		  buffs[a] = malloc (field->length + 1);
		  dtypes[a] = 0;
		  break;
		case DTYPE_VCHAR:
		  sz = field->length + 1;
		  buffs[a] = malloc (field->length + 1);
		  dtypes[a] = 0;
		  break;
		case DTYPE_SMINT:
		  sz = 10;
		  buffs[a] = malloc (10);
		  dtypes[a] = 0;
		  break;

		case DTYPE_SERIAL:
		case DTYPE_INT:
		  sz = 20;
		  buffs[a] = malloc (20);
		  dtypes[a] = 0;
		  break;
		case DTYPE_FLOAT:
		  sz = 20;
		  buffs[a] = malloc (20);
		  dtypes[a] = 0;
		  break;
		case DTYPE_SMFLOAT:
		  sz = 20;
		  buffs[a] = malloc (20);
		  dtypes[a] = 0;
		  break;
		case DTYPE_DECIMAL:
		  sz = 20;
		  buffs[a] = malloc (20);
		  dtypes[a] = 0;
		  break;
		case DTYPE_DATE:
		  sz = 20;
		  buffs[a] = malloc (20);
		  dtypes[a] = 0;
		  break;
		case DTYPE_MONEY:
		  sz = 20;
		  buffs[a] = malloc (20);
		  dtypes[a] = 0;
		  break;
		case DTYPE_DTIME:
		  sz = 20;
		  buffs[a] = malloc (20);
		  dtypes[a] = 0;
		  break;
		case DTYPE_BYTE:
		  A4GL_assertion (1, "Not implemented (byte3)");
		  break;
		case DTYPE_TEXT:
		  A4GL_assertion (1, "Not implemented (byte3)");
		  break;
		case DTYPE_INTERVAL:
		  sz = 20;
		  buffs[a] = malloc (20);
		  dtypes[a] = 0;
		  break;
		}

	      if (!isset)
		{
		  b[a].buffer_type = MYSQL_TYPE_STRING;
		  b[a].buffer = buffs[a];
		  b[a].is_null = &ind[a];
		  b[a].buffer_length = sz * 3;
		  b[a].length = &longs[a];
		}

	    }
	  // 'b' should point to our bindings...

	  mysql_stmt_bind_result (stmt, b);

	  while (1)
	    {
	      int x;
	      if (mysql_stmt_fetch (stmt))
		break;

	      for (a = 0; a < nresultcols; a++)
		{
		  if (dtypes[a] == 0)
		    {
		      if (!ind[a])
			{
			  fprintf (f, "%s", buffs[a]);
			}
		    }
		  fprintf (f, "%s", delims);
		}
	      fprintf (f, "\n");
	    }

	}
    }
  fclose (f);
}
