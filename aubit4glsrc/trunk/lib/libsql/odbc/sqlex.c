/*
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
# $Id: sqlex.c,v 1.23 2005-03-09 15:15:13 mikeaubury Exp $
#
*/

/**
 * @file
 * SQL
 *
 * @todo Add Doxygen A4GL_comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen A4GL_comments to add to functions
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

#define chk_rc(rc,stmt,call) A4GL_chk_rc_full(rc,stmt,call,__LINE__,__FILE__)
#define WIDTH 		19
#define MEMSIZE 	1024
#define USES_RESOURCE int acl_rescnt;acl_rescnt=new_rescnt()
#define ALLOC(a) allocate_mem(a,(void*)acl_rescnt)
#define RELEASE() dealloc_mem((void *)acl_rescnt)
#define USERS_STRING 0
#define USERS_LONG 0
#define streq(a,b) (strcmp(a,b)==0)

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

struct xxsql_options		/* struct sql_options */
{
  char optname[30];
  char param[30];
  long opt_id;
  long param_id;
};

struct
{
  void *ptr;
  void *parent;
}
alloc_mem[MEMSIZE];

int line[80];
FILE *f = 0;
char invalid[] = "<Invalid>";


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

int A4GL_scan_options (struct xxsql_options options[], char *s, char *p, long *r1,
		  long *r2);
//int scan_stmt (char *s, char *p, HSTMT hstmt);
int A4GL_add_txt (char *s, int x, int hwnd);
int A4GL_clrline (int line[]);
int A4GL_rm_txt (int a, int line[], int ign);
int A4GL_remove_it (int a);
char *getres (char *s);
int add_userptr (void *ptr);
long A4GL_set_blob_data_int (FILE * blob, HSTMT hstmt, struct fgl_int_loc *b);
int A4GL_set_blob_data_repeat (HSTMT hstmt, struct fgl_int_loc *blob);
long A4GL_get_blob_data_int (FILE * blob, HSTMT hstmt, int colno, char **cptr);
int A4GL_alloc_find_ptr (void *ptr);

int A4GL_ctol (char s);
char *A4GL_generate_using_for_dmy (char *s, int size);
void *A4GL_allocate_mem (int size, void *parent);
void A4GL_init_mem (void);
int A4GL_alloc_find_parent (void *ptr, int start);
void A4GL_dealloc_mem (void *ptr);
int A4GL_new_rescnt (void);
int A4GL_get_blob_data (struct fgl_int_loc *blob, HSTMT hstmt, int colno);
int A4GL_set_blob_data (HSTMT hstmt);

/*
=====================================================================
                    Platform specific definitions
=====================================================================
*/

#ifdef __CYGWIN__
int need_logon (void);
//      int     set_regkey      (char *key, char *data);
//      int     get_regkey      (char *key, char *data, int n);
void createkey (void);
//      HKEY    newkey = 0;
//      void    get_anykey      (HKEY whence, char *key, char *key2, char *data, int n);
void MBox (char *s, char *fmt, ...);
void set_default_logon (void);
	/*
	   #endif


	   #define streq(a,b) (strcmp(a,b)==0)

	   #ifdef WIN32
	   struct sql_options conn_options[] =
	 */

	/** Connection options memory table - Windows version */
struct xxsql_options conn_options[] = {
  {"ACCESS MODE", "READ ONLY", SQL_ACCESS_MODE, SQL_MODE_READ_ONLY},
  {"ACCESS MODE", "READ WRITE", SQL_ACCESS_MODE, SQL_MODE_READ_WRITE},
  {"AUTO COMMIT", "ON", SQL_AUTOCOMMIT, SQL_AUTOCOMMIT_ON},
  {"AUTO COMMIT", "OFF", SQL_AUTOCOMMIT, SQL_AUTOCOMMIT_OFF},
  {"CURRENT QUALIFIER", "STRING", SQL_CURRENT_QUALIFIER, USERS_STRING},
  {"LOGIN TIMEOUT", "LONG", SQL_LOGIN_TIMEOUT, USERS_LONG},
  {"ODBC CURSORS", "USE IF NEEDED", SQL_ODBC_CURSORS, SQL_CUR_USE_IF_NEEDED},
  {"ODBC CURSORS", "USE ODBC", SQL_ODBC_CURSORS, SQL_CUR_USE_ODBC},
  {"ODBC CURSORS", "USE DRIVER", SQL_ODBC_CURSORS, SQL_CUR_USE_DRIVER},
  {"TRACE", "OFF", SQL_OPT_TRACE, SQL_OPT_TRACE_OFF},
  {"TRACE", "ON", SQL_OPT_TRACE, SQL_OPT_TRACE_ON},
  {"TRACEFILE", "STRING", SQL_OPT_TRACEFILE, USERS_STRING},
  {"PACKET SIZE", "LONG", SQL_PACKET_SIZE, USERS_LONG},
  {"QUIET MODE", "LONG", SQL_QUIET_MODE, USERS_LONG},
  {"ISOLATION", "READ UNCOMMITTED", SQL_TXN_ISOLATION,
   SQL_TXN_READ_UNCOMMITTED},
  {"ISOLATION", "READ COMMITTED", SQL_TXN_ISOLATION, SQL_TXN_READ_COMMITTED},
  {"ISOLATION", "REPEATABLE READ", SQL_TXN_ISOLATION,
   SQL_TXN_REPEATABLE_READ},
  {"ISOLATION", "SERIALIZABLE", SQL_TXN_ISOLATION, SQL_TXN_SERIALIZABLE},
  /* {"ISOLATION","VERSIONING",      SQL_TXN_ISOLATION,SQL_TXN_VERSIONING}, */
  {"", 0, 0, 0}
};


	/* struct sql_options stmt_options[] = */
	/** Statement options memory table - Windows version */
struct xxsql_options stmt_options[] = {
  {"CONCURRENCY", "READ ONLY", SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY},
  {"CONCURRENCY", "LOCK", SQL_CONCURRENCY, SQL_CONCUR_LOCK},
  {"CONCURRENCY", "ROWVER", SQL_CONCURRENCY, SQL_CONCUR_ROWVER},
  {"CONCURRENCY", "VALUES", SQL_CONCURRENCY, SQL_CONCUR_VALUES},
  {"CURSOR TYPE", "FORWARD ONLY", SQL_CURSOR_TYPE, SQL_CURSOR_FORWARD_ONLY},
  {"CURSOR TYPE", "STATIC", SQL_CURSOR_TYPE, SQL_CURSOR_STATIC},
  {"CURSOR TYPE", "KEYSET DRIVEN", SQL_CURSOR_TYPE, SQL_CURSOR_KEYSET_DRIVEN},
  {"CURSOR TYPE", "DYNAMIC", SQL_CURSOR_TYPE, SQL_CURSOR_DYNAMIC},
  {"KEYSET SIZE", "LONG", SQL_KEYSET_SIZE, USERS_LONG},
  {"MAX LENGTH", "LONG", SQL_MAX_LENGTH, USERS_LONG},
  {"MAX ROWS", "LONG", SQL_MAX_ROWS, USERS_LONG},
  {"NOSCAN", "OFF", SQL_NOSCAN, SQL_NOSCAN_OFF},
  {"NOSCAN", "ON", SQL_NOSCAN, SQL_NOSCAN_ON},
  {"QUERY TIMEOUT", "LONG", SQL_QUERY_TIMEOUT, USERS_LONG},
  {"RETRIEVE DATA", "ON", SQL_RETRIEVE_DATA, SQL_RD_ON},
  {"RETRIEVE DATA", "OFF", SQL_RETRIEVE_DATA, SQL_RD_OFF},
  {"SIMULATE CURSOR", "NON UNIQUE", SQL_SIMULATE_CURSOR, SQL_SC_NON_UNIQUE},
  {"SIMULATE CURSOR", "TRY UNIQUE", SQL_SIMULATE_CURSOR, SQL_SC_TRY_UNIQUE},
  {"SIMULATE CURSOR", "UNIQUE", SQL_SIMULATE_CURSOR, SQL_SC_UNIQUE},
  {"USE BOOKMARKS", "ON", SQL_USE_BOOKMARKS, SQL_UB_ON},
  {"USE BOOKMARKS", "OFF", SQL_USE_BOOKMARKS, SQL_UB_OFF},
  {"", 0, 0, 0}
};

#else /* #ifdef __CYGWIN__ */

	/* struct sql_options conn_options[] = */
	/** Connection options memory table - unix version */
struct xxsql_options conn_options[] = {
  {"ACCESS MODE", "READ ONLY", SQL_ACCESS_MODE, SQL_MODE_READ_ONLY},
  {"ACCESS MODE", "READ WRITE", SQL_ACCESS_MODE, SQL_MODE_READ_WRITE},
  {"AUTO COMMIT", "ON", SQL_AUTOCOMMIT, SQL_AUTOCOMMIT_ON},
  {"AUTO COMMIT", "OFF", SQL_AUTOCOMMIT, SQL_AUTOCOMMIT_OFF},
  {"CURRENT QUALIFIER", "STRING", SQL_CURRENT_QUALIFIER, USERS_STRING},
  {"LOGIN TIMEOUT", "LONG", SQL_LOGIN_TIMEOUT, USERS_LONG},
  {"ODBC CURSORS", "USE IF NEEDED", SQL_ODBC_CURSORS, SQL_CUR_USE_IF_NEEDED},
  {"ODBC CURSORS", "USE ODBC", SQL_ODBC_CURSORS, SQL_CUR_USE_ODBC},
  {"ODBC CURSORS", "USE DRIVER", SQL_ODBC_CURSORS, SQL_CUR_USE_DRIVER},
  {"TRACE", "OFF", SQL_OPT_TRACE, SQL_OPT_TRACE_OFF},
  {"TRACE", "ON", SQL_OPT_TRACE, SQL_OPT_TRACE_ON},
  {"TRACEFILE", "STRING", SQL_OPT_TRACEFILE, USERS_STRING},
  {"PACKET SIZE", "LONG", SQL_PACKET_SIZE, USERS_LONG},
  {"QUIET MODE", "LONG", SQL_QUIET_MODE, USERS_LONG},
  {"ISOLATION", "READ UNCOMMITTED", SQL_TXN_ISOLATION,
   SQL_TXN_READ_UNCOMMITTED},
  {"ISOLATION", "READ COMMITTED", SQL_TXN_ISOLATION, SQL_TXN_READ_COMMITTED},
  {"ISOLATION", "REPEATABLE READ", SQL_TXN_ISOLATION,
   SQL_TXN_REPEATABLE_READ},
  {"ISOLATION", "SERIALIZABLE", SQL_TXN_ISOLATION, SQL_TXN_SERIALIZABLE},
  /* {"ISOLATION","VERSIONING",      SQL_TXN_ISOLATION,SQL_TXN_VERSIONING}, */
  {"", "0", 0, 0}
};


	/* struct sql_options stmt_options[] = */
	/** Statement options memory table - unix version */
struct xxsql_options stmt_options[] = {
  {"CONCURRENCY", "READ ONLY", SQL_CONCURRENCY, SQL_CONCUR_READ_ONLY},
  {"CONCURRENCY", "LOCK", SQL_CONCURRENCY, SQL_CONCUR_LOCK},
  {"CONCURRENCY", "ROWVER", SQL_CONCURRENCY, SQL_CONCUR_ROWVER},
  {"CONCURRENCY", "VALUES", SQL_CONCURRENCY, SQL_CONCUR_VALUES},
  {"CURSOR TYPE", "FORWARD ONLY", SQL_CURSOR_TYPE, SQL_SCROLL_FORWARD_ONLY},
  {"CURSOR TYPE", "STATIC", SQL_CURSOR_TYPE, SQL_SCROLL_STATIC},
  {"CURSOR TYPE", "KEYSET DRIVEN", SQL_CURSOR_TYPE, SQL_SCROLL_KEYSET_DRIVEN},
  {"CURSOR TYPE", "DYNAMIC", SQL_CURSOR_TYPE, SQL_SCROLL_DYNAMIC},
  {"KEYSET SIZE", "LONG", SQL_KEYSET_SIZE, USERS_LONG},
  {"MAX LENGTH", "LONG", SQL_MAX_LENGTH, USERS_LONG},
  {"MAX ROWS", "LONG", SQL_MAX_ROWS, USERS_LONG},
  {"NOSCAN", "OFF", SQL_NOSCAN, 0},
  {"NOSCAN", "ON", SQL_NOSCAN, 1},
  /*{"BIND TYPE","ON",              SQL_BIND_TYPE,USERS_LONG}, */
  {"QUERY TIMEOUT", "LONG", SQL_QUERY_TIMEOUT, USERS_LONG},
  {"RETRIEVE DATA", "ON", SQL_RETRIEVE_DATA, 1},
  {"RETRIEVE DATA", "OFF", SQL_RETRIEVE_DATA, 0},
  {"SIMULATE CURSOR", "NON UNIQUE", SQL_SIMULATE_CURSOR, 0},
  {"SIMULATE CURSOR", "TRY UNIQUE", SQL_SIMULATE_CURSOR, 1},
  {"SIMULATE CURSOR", "UNIQUE", SQL_SIMULATE_CURSOR, 2},
  {"USE BOOKMARKS", "ON", SQL_USE_BOOKMARKS, 1},
  {"USE BOOKMARKS", "OFF", SQL_USE_BOOKMARKS, 0},
  {"", "0", 0, 0}
};


#endif /* #ifdef __CYGWIN__ */


/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * @deprecated This a deprecation candidate.
 *
 * @param options Options array to be scanned.
 * @param s
 * @param p
 * @param r1
 * @param r2
 */
int
A4GL_scan_options (struct xxsql_options options[], char *s, char *p, long *r1,
	      long *r2)
{
  int a;
  long val = 0;
  int type;
  int foundit = 0;

  for (a = 0; options[a].optname[0] != 0; a++)
    {
      if (strcmp (s, options[a].optname) == 0)
	{
	  foundit = 1;
	  type = 0;

	  if (strcmp (options[a].param, "STRING") == 0)
	    {
	      val = (long) p;
	      type = 1;
	    }
	  if (strcmp (options[a].param, "LONG") == 0)
	    {
	      val = atol (p);
	      type = 2;
	    }

	  if (type == 0 && strcmp (p, options[a].param) == 0)
	    {
	      val = options[a].param_id;
	      type = 2;
	    }

	  if (type == 0)
	    continue;
	  *r1 = options[a].opt_id;
	  *r2 = val;
	  return 1;
	}

    }
  if (foundit)
    return -1;
  else
    return -2;
}

/**
 * @deprecated This a deprecation candidate.
 *
 * @param s
 * @param p
 * @param conn
 */
/*
int
scan_conn (char *s, char *p, HDBC conn)
{
  long a, b;
  int rc;
  int z;
  A4GL_debug ("Checking %s %s %p", s, p, conn);
  z = A4GL_scan_options (conn_options, s, p, &a, &b);

  A4GL_debug ("z=%d\n", z);
  if (z == -2)
    {
      z = A4GL_scan_options (stmt_options, s, p, &a, &b);
    }

  if (z == -1)
    {
      A4GL_exitwith ("Parameter is not applicable to option");
      return 0;
    }

  if (z == -2)
    {
      A4GL_exitwith ("Option was not found");
    }
  if (b < 1000)
    {
      A4GL_debug ("Got %ld %ld on statement %p\n", a, b, conn);
    }
  else
    {
      A4GL_debug ("Got %ld %s on statement %p\n", a, b, conn);
    }
  A4GL_debug ("Calling setconnectoption with %ld %ld %ld", conn, a, b);
  rc = SQLSetConnectOption ((HDBC) conn, (UWORD) a, (UDWORD) b);

  A4GL_set_sqlca (SQL_NULL_HSTMT, "SetConnect", 0);
  A4GL_debug ("Set Option...rc=%d", rc);
  return 1;
}
*/

/**
 * @deprecated This a deprecation candidate.
 *
 * @param s
 * @param p
 * @paramhstmt The statement handle.
 */
/*
int
scan_stmt (char *s, char *p, HSTMT hstmt)
{
  UWORD a;
  UDWORD b;
  int z;
  int rc;
  A4GL_debug ("Checking %s %s %ld", s, p, hstmt);
  z = A4GL_scan_options (stmt_options, s, p, (long *)&a, (long *)&b);

  if (z == -1)
    {
      A4GL_exitwith ("Parameter is not applicable to option");
      return 0;
    }

  if (z == -2)
    {
      A4GL_exitwith ("Option was not found");
      return 0;
    }

  A4GL_debug ("Got %ld %ld stmt=%p\n", a, b, hstmt);
  rc = SQLSetStmtOption (hstmt, a, b);
  A4GL_debug ("rc=%d", rc);
  A4GL_set_sqlca (hstmt, "SetStmtOption", 0);
  return 1;
}
*/

/**
 * @deprecated This a candidate for cleaning.
 */
int
A4GL_add_txt (char *s, int x, int hwnd)
{
  int b;
  int z = 0;
  for (b = x - 1; b < x - 1 + (int) strlen (s); b++)
    {
      if (line[b])
 A4GL_rm_txt (z, line, b);
      line[b] = hwnd;
    }
  return 0;
}

/**
 * @deprecated This a candidate for cleaning.
 */
int
A4GL_clrline (int line[])
{
  int a;
  for (a = 0; a < 80; a++)
    {
      line[a] = 0;
    }
  return 0;
}

/**
 * @deprecated This a candidate for cleaning.
 */
int
A4GL_rm_txt (int a, int line[], int ign)
{
  int b;
  for (b = 0; b < 80; b++)
    if (line[b] == a && b != ign)
      return 0;

  A4GL_remove_it (a);
  return 0;
}

/**
 * @deprecated This a candidate for cleaning.
 */
int
A4GL_remove_it (int a)
{
  A4GL_debug ("Clr %d\n", a);
  return 0;
}

/**
 * @deprecated This a candidate for cleaning.
 */
int
A4GL_ctol (char s)
{
  char buff[2];
  buff[0] = s;
  buff[1] = 0;
  return atoi (buff);
}

/**
 * @deprecated This a candidate for cleaning.
 */
char *
A4GL_generate_using_for_dmy (char *s, int size)
{
  static char using_str[20] = "";
  int v = 0;
  char sep = '/';
  int yr = 2;
  char years[5];

  strcpy (using_str, "");

  if (strlen (s) == 3)
    {
      v = 1;
    }

  if (strlen (s) == 4)
    {
      v = 2;
      yr = A4GL_ctol (s[3]);
    }

  if (strlen (s) == 5)
    {
      v = 3;
      yr = A4GL_ctol (s[3]);
      sep = s[4];
    }

  if (yr != 2 && yr != 4)
    {
      A4GL_debug ("DMY setting - only 2 or 4 digits for year!");
      return using_str;
    }

  if (size < 10)
    yr = 2;

  if (yr == 2)
    strcpy (years, "yy");

  if (yr == 4)
    strcpy (years, "yyyy");
  if (size >= 8)
    {
      if (s[0] == 'D' && s[1] == 'M' && s[2] == 'Y')
	sprintf (using_str, "dd%cmm%c%s", sep, sep, years);
      if (s[0] == 'D' && s[1] == 'Y' && s[2] == 'M')
	sprintf (using_str, "dd%c%s%cmm", sep, years, sep);
      if (s[0] == 'M' && s[1] == 'D' && s[2] == 'Y')
	sprintf (using_str, "mm%cdd%c%s", sep, sep, years);
      if (s[0] == 'M' && s[1] == 'Y' && s[2] == 'D')
	sprintf (using_str, "mm%c%s%cdd", sep, years, sep);
      if (s[0] == 'Y' && s[1] == 'D' && s[2] == 'M')
	sprintf (using_str, "%s%cdd%cmm", years, sep, sep);
      if (s[0] == 'Y' && s[1] == 'M' && s[2] == 'D')
	sprintf (using_str, "%s%cmm%cdd", years, sep, sep);
    }
  else
    {
      if (s[0] == 'D' && s[1] == 'M' && s[2] == 'Y')
	sprintf (using_str, "ddmm%s", years);
      if (s[0] == 'D' && s[1] == 'Y' && s[2] == 'M')
	sprintf (using_str, "dd%smm", years);
      if (s[0] == 'M' && s[1] == 'D' && s[2] == 'Y')
	sprintf (using_str, "mmdd%s", years);
      if (s[0] == 'M' && s[1] == 'Y' && s[2] == 'D')
	sprintf (using_str, "mm%sdd", years);
      if (s[0] == 'Y' && s[1] == 'D' && s[2] == 'M')
	sprintf (using_str, "%sddmm", years);
      if (s[0] == 'Y' && s[1] == 'M' && s[2] == 'D')
	sprintf (using_str, "%smmdd", years);
    }


  return using_str;
}

/**
 * @deprecated This a candidate for cleaning.
 */
void *
A4GL_allocate_mem (int size, void *parent)
{
  int a;

  a = A4GL_alloc_find_ptr (0);

  if (a == -1)
    {
      A4GL_debug ("No free space...");
      exit (0);
    }

  alloc_mem[a].ptr = malloc (size);

  if (alloc_mem[a].ptr == 0)
    {
      A4GL_debug ("No free memory...");
      exit (0);
    }

  alloc_mem[a].parent = parent;
  A4GL_debug (">%p\n", alloc_mem[a].ptr);
  return alloc_mem[a].ptr;
}

/**
 * @deprecated This a candidate for cleaning.
 */
void
A4GL_init_mem (void)
{
  int a;
  for (a = 0; a < MEMSIZE; a++)
    {
      alloc_mem[a].ptr = 0;
      alloc_mem[a].parent = 0;
    }
}

/**
 * @deprecated This a candidate for cleaning.
 */
int
A4GL_alloc_find_ptr (void *ptr)
{
  int a;
  for (a = 0; a < MEMSIZE; a++)
    {
      if (alloc_mem[a].ptr == ptr)
	return a;
    }
  return -1;
}

/**
 * @deprecated This a candidate for cleaning.
 */
int
A4GL_alloc_find_parent (void *ptr, int start)
{
  int a;
  for (a = start; a < MEMSIZE; a++)
    {
      if (alloc_mem[a].parent == ptr)
	return a;
    }
  return -1;
}

/**
 * @deprecated This a candidate for cleaning.
 */
void
A4GL_dealloc_mem (void *ptr)
{
  int a = -1;
  while (1)
    {
      a = A4GL_alloc_find_parent (ptr, a + 1);
      if (a == -1)
	break;
/* delete anything with this as as a parent */
      A4GL_dealloc_mem (alloc_mem[a].ptr);
    }
  a = A4GL_alloc_find_ptr (ptr);
  if (a != -1)
    {
      alloc_mem[a].ptr = 0;
      alloc_mem[a].parent = 0;
      free (ptr);
      A4GL_debug ("-%p\n", ptr);
    }
}

/**
 *
 * @todo Describe function
 */
int
A4GL_new_rescnt (void)
{
  static int rescnt = 1;
  return rescnt++;
}


/* *****************************************************************

			        BLOB relatad functions

******************************************************************/

/**
 * Get the blob data into the specified location (memory or file).
 *
 * @param blob Pointer to the blob location.
 * @param hstmt The statement handle.
 * @param colno the column number.
 */
int
A4GL_get_blob_data (struct fgl_int_loc *blob, HSTMT hstmt, int colno)
{
  int cnt;

  A4GL_debug ("blob=%p", blob);
  A4GL_debug ("blob->where=%c", blob->where);
  A4GL_debug ("blob->filename=%s", blob->filename);

  if (blob->where != 'F' && blob->where != 'M')
    {
      A4GL_exitwith ("Blob not located");
      return 0;
    }

  if (blob->where == 'F')
    {
      A4GL_debug ("Writing blob to %s", blob->filename);

      if (blob->f == 0)
	{
	  blob->f = fopen (blob->filename, "w");

	  if (blob->f == 0)
	    {
	      A4GL_exitwith ("Unable to open blob");
	      return 0;
	    }
	}

      cnt = A4GL_get_blob_data_int (blob->f, hstmt, colno, 0);

      fclose (blob->f);
      blob->f = 0;
    }
  else
    {
      A4GL_debug ("Writing blob to memory");
      if (blob->ptr)
	{
	  free (blob->ptr);
	}
      cnt = A4GL_get_blob_data_int (0, hstmt, colno, (char **) &blob->ptr);

    }
  if (cnt < 0)
    {
      blob->where = 'N';
      return 0;
    }
  blob->memsize = cnt;
/* everything is ok */
  return 1;
}

/**
 * Get the blob information from the statement handle into the specified 
 * location.
 *
 * @param blob The file where the blob is located.
 * @param hstmt The statement handle.
 * @param colno The column number.
 * @param cptr 
 */
long
A4GL_get_blob_data_int (FILE * blob, HSTMT hstmt, int colno, char **cptr)
{
  char buff[64000];
  char *ptr = 0;
  long cnt = 0;
  int rc;
  SDWORD i;

  A4GL_debug ("In get_blob_data_int");

  if (blob)
    rewind (blob);

  while (1)
    {
      A4GL_debug ("In loop");

      if (blob == 0)
	{
	  A4GL_debug ("Memory...");
	  ptr = realloc (ptr, cnt + sizeof (buff));
	  if (ptr == 0)
	    {
	      return -1;
	    }
	  memset (ptr + cnt, 0, sizeof (buff));
	}
      rc = SQLGetData (hstmt, 1, SQL_C_DEFAULT, buff, sizeof (buff), &i);
      if (rc < 0)
	break;

      if (i < 0)
	return -1;

      if (blob)
	{
	  if (i < sizeof (buff))
	    {
	      cnt += i;
	      fwrite (buff, i, 1, blob);
	      break;
	    }
	  else
	    {
	      fwrite (buff, sizeof (buff), 1, blob);
	    }
	}
      else
	{
	  if (i < sizeof (buff))
	    memcpy (ptr + cnt, buff, i);
	  else
	    memcpy (ptr + cnt, buff, sizeof (buff));
	}

      if (i < sizeof (buff))
	cnt += i;
      else
	cnt += sizeof (buff);
      if (rc == 0)
	break;
    }
  if (blob == 0 && cptr)
    {
      /* resize it down */
      ptr = realloc (ptr, cnt);
      *cptr = ptr;
    }
  return cnt;
}

/**
 * Set the blob information to the statement.
 *
 * @param hstmt The statement handle.
 */
int
A4GL_set_blob_data (HSTMT hstmt)
{
  int rc;
  struct fgl_int_loc *blob;
  rc = SQL_NEED_DATA;
  while (rc == SQL_NEED_DATA)
    {
      rc = SQLParamData (hstmt, (PTR) & blob);
      A4GL_set_blob_data_repeat (hstmt, blob);
    }
  return rc;
}

/**
 * Read a blob into the statement hande.
 *
 * Check the location of the blob anf if in a file open it.
 * A the end frees the memory.
 *
 * @param hstmt The statement handle.
 * @param blob Pointer to the the blob  location.
 */
int
A4GL_set_blob_data_repeat (HSTMT hstmt, struct fgl_int_loc *blob)
{
  int cnt;


  A4GL_debug ("blob=%p", blob);
  A4GL_debug ("blob->where=%c", blob->where);
  A4GL_debug ("blob->filename=%s", blob->filename);

  if (blob->where != 'F' && blob->where != 'M')
    {
      A4GL_exitwith ("Blob not located");
      return 0;
    }

  if (blob->where == 'F')
    {
      A4GL_debug ("Reading blob from %s", blob->filename);

      if (blob->f == 0)
	{
	  blob->f = fopen (blob->filename, "r");

	  if (blob->f == 0)
	    {
	      A4GL_exitwith ("Unable to open blob");
	      return 0;
	    }
	}

      cnt = A4GL_set_blob_data_int (blob->f, hstmt, blob);

      fclose (blob->f);
      blob->f = 0;
    }
  else
    {
      A4GL_debug ("reading blob from memory");
      if (blob->ptr)
	{
	  free (blob->ptr);
	}
      cnt = A4GL_set_blob_data_int (0, hstmt, blob);

    }

  if (cnt < 0)
    {
      blob->where = 'N';
      return 0;
    }

  blob->memsize = cnt;
  /* everything is ok */
  return 1;
}

/**
 * Read a blob information from a FILE and set it to the statement information.
 *
 * @param blob The file where the blob is located.
 * @param hstmt The statement handle.
 * @param b Pointer to the blob location.
 */
long
A4GL_set_blob_data_int (FILE * blob, HSTMT hstmt, struct fgl_int_loc *b)
{
  char buff[64000];
  char *ptr = 0;
  long cnt = 0;
  int rc;
  int i;
  int write_bytes;

  A4GL_debug ("In set_blob_data_int");

  if (blob)
    rewind (blob);

  if (blob == 0)
    {
      for (i = 0; i <= b->memsize; i += sizeof (buff))
	{
	  if (i + sizeof (buff) < b->memsize)
	    write_bytes = sizeof (buff);
	  else
	    write_bytes = b->memsize - i;

	  rc = SQLPutData (hstmt, ptr + i, write_bytes);
	}
      return b->memsize;
    }
  else
    {
      while (1)
	{
	  write_bytes = fread (buff, 1, sizeof (buff), blob);
	  if (write_bytes <= 0)
	    break;
	  cnt += write_bytes;
	  rc = SQLPutData (hstmt, buff, write_bytes);
	}
      b->memsize = cnt;
      return cnt;
    }
  return 0;
}


/* =============================== EOF =============================== */
