/******************************************************************************
* (c) 1997-1998 Aubit Computing Ltd.
*
* $Id: sqlex.c,v 1.3 2002-01-04 12:48:16 afalout Exp $
*
* Project : Part Of Aubit 4GL Library Functions
*
* Change History :
*	$Log: not supported by cvs2svn $
*	Revision 1.2  2001/12/21 04:14:41  afalout
*	RMP work
*	
*	Revision 1.1  2001/12/03 15:44:37  mikeaubury
*	New dl sql stuff
*	
*	Revision 1.4  2001/09/20 08:55:16  afalout
*	Enabling makefiles to compile all builds from one environment
*	
*	Revision 1.3  2001/08/24 20:45:25  mikeaubury
*	Major fcompile updates.
*	Minor environment variable handling updates (to get it to work again :-)
*	
*	Revision 1.2  2001/08/21 19:31:22  mikeaubury
*	1. Changes for PUT
*	2. Changes for Core dump on startup of 4glc (if AUBITGUI isn't set)
*	
*	Revision 1.1.1.1  2001/08/20 02:36:39  afalout
*	Initial import to SF
*	
*	Revision 1.5  2001/08/13 01:07:43  afalout
*	CygWin merge
*	
*	Revision 1.4  2001/06/25 00:06:04  afalout
*	added IFDEF for unixODBC
*	
*	Revision 1.3  2001/06/12 03:37:33  afalout
*	make install, make clean
*	
*	Revision 1.2  2000/09/28 02:42:23  afalout
*	*** empty log message ***
*	
*	Revision 1.1.1.1  2000/01/29 03:11:52  cvs
*	Initial import of compiler sources using jCVS client
*	
*	Revision 1.8  1999/01/28 23:13:18  fglcomp
*	Latest Update 28/1/99
*
*	Revision 1.7  1998/12/24 08:05:53  fglcomp
*	.
*
*	Revision 1.6  1998/12/17 20:59:02  fglcomp
*	171298
*
*	Revision 1.5  1998/12/12 09:49:18  fglcomp
*	12/12/98
*
*	Revision 1.3  1998/10/15 21:54:22  fglcomp
*	Up till 15/10/98
*
*	Revision 1.2  1998/08/09 11:51:48  fglcomp
*	Added ID classifications
*
*
*******************************************************************************/
//#ifdef WIN32
#ifdef __CYGWIN__
	#define WIN32
	#include <windows.h>
	#include <sql.h>
	#include <sqlext.h>
#else
	#ifdef UNIXODBC
		#include <sql.h>
		#include <sqlext.h>
		#include <odbcinst.h>
	#else
		#include "iodbc.h"
		#include "isql.h"
		#include "isqlext.h"
	#endif
#endif

#include <stdio.h>
#include <stdarg.h>
#include "../libincl/debug.h"
#include "../libincl/dtypes.h"
#include "../libincl/stack.h"

int scan_conn (char *s, char *p, HDBC conn);
#define chk_rc(rc,stmt,call) chk_rc_full(rc,stmt,call,__LINE__,__FILE__)

struct xxsql_options //struct sql_options
  {
    char optname[30];
    char param[30];
    long opt_id;
    long param_id;
  };

struct str_resource
  {
    char name[20];
    char value[40];
  };
#define WIDTH 19

static char buff[30000];

#define MEMSIZE 1024
#define USES_RESOURCE int acl_rescnt;acl_rescnt=new_rescnt()
#define ALLOC(a) allocate_mem(a,(void*)acl_rescnt)
#define RELEASE() dealloc_mem((void *)acl_rescnt)

struct
  {
    void *ptr;
    void *parent;
  }
alloc_mem[MEMSIZE];

int line[80];
FILE *f = 0;
char invalid[] = "<Invalid>";
//char *find_str_resource (char *s);

#define USERS_STRING 0
#define USERS_LONG 0


//int scan_options (struct sql_options options[], char *s, char *p, long *r1, long *r2);
int scan_options (struct xxsql_options options[], char *s, char *p, long *r1, long *r2);
int scan_stmt (char *s, char *p, HSTMT hstmt);
int add_txt (char *s, int x, int hwnd);
int clrline (int line[]);
int rm_txt (int a, int line[], int ign);
int remove_it (int a);
char *getres (char *s);
//char *chk_str_resource (char *s, struct str_resource *res);
//char *find_str_resource (char *s);
//int replace_str_resource (char *s, char *neww);
int add_userptr (void *ptr);



//#ifdef WIN32
#define streq(a,b) (strcmp(a,b)==0)

#ifdef __CYGWIN__
int need_logon ();
int set_regkey (char *key, char *data);
int get_regkey (char *key, char *data, int n);
void createkey ();
HKEY newkey = 0;
//void get_anykey (int whence, char *key, char *key2, char *data, int n);
void get_anykey (HKEY whence, char *key, char *key2, char *data, int n);
void MBox (char *s, char *fmt,...);
void set_default_logon ();
/*
#endif


#define streq(a,b) (strcmp(a,b)==0)

#ifdef WIN32
struct sql_options conn_options[] =
*/
struct xxsql_options conn_options[] =
{
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
  {"ISOLATION", "READ UNCOMMITTED", SQL_TXN_ISOLATION, SQL_TXN_READ_UNCOMMITTED},
  {"ISOLATION", "READ COMMITTED", SQL_TXN_ISOLATION, SQL_TXN_READ_COMMITTED},
{"ISOLATION", "REPEATABLE READ", SQL_TXN_ISOLATION, SQL_TXN_REPEATABLE_READ},
  {"ISOLATION", "SERIALIZABLE", SQL_TXN_ISOLATION, SQL_TXN_SERIALIZABLE},
//{"ISOLATION","VERSIONING",      SQL_TXN_ISOLATION,SQL_TXN_VERSIONING},
  {"", 0, 0, 0}
};


//struct sql_options stmt_options[] =
struct xxsql_options stmt_options[] =
{
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

#else

//struct sql_options conn_options[] =
struct xxsql_options conn_options[] =
{
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
  {"ISOLATION", "READ UNCOMMITTED", SQL_TXN_ISOLATION, SQL_TXN_READ_UNCOMMITTED},
  {"ISOLATION", "READ COMMITTED", SQL_TXN_ISOLATION, SQL_TXN_READ_COMMITTED},
{"ISOLATION", "REPEATABLE READ", SQL_TXN_ISOLATION, SQL_TXN_REPEATABLE_READ},
  {"ISOLATION", "SERIALIZABLE", SQL_TXN_ISOLATION, SQL_TXN_SERIALIZABLE},
//{"ISOLATION","VERSIONING",      SQL_TXN_ISOLATION,SQL_TXN_VERSIONING},
  {"", 0, 0, 0}
};


//struct sql_options stmt_options[] =
struct xxsql_options stmt_options[] =
{
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
  {"", 0, 0, 0}
};


#endif



//scan_options (struct sql_options options[], char *s, char *p, long *r1, long *r2)
scan_options (struct xxsql_options options[], char *s, char *p, long *r1, long *r2)
{
  int a;
  long val;
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

int
scan_conn (char *s, char *p, HDBC conn)
{
  long a, b;
  int rc;
  int z;
  debug ("Checking %s %s %p", s, p, conn);
  z = scan_options (conn_options, s, p, &a, &b);

  debug ("z=%d\n", z);
  if (z == -2)
    {
      z = scan_options (stmt_options, s, p, &a, &b);
    }

  if (z == -1)
    {
      exitwith ("Parameter is not applicable to option");
      return 0;
    }

  if (z == -2)
    {
      exitwith ("Option was not found");
    }
  if (b < 1000)
    {
      debug ("Got %ld %ld on statement %p\n", a, b, conn);
    }
  else
    {
      debug ("Got %ld %s on statement %p\n", a, b, conn);
    }
  debug ("Calling setconnectoption with %ld %ld %ld", conn, a, b);
  rc = SQLSetConnectOption ((HDBC) conn, (UWORD) a, (UDWORD) b);

  set_sqlca (SQL_NULL_HSTMT, "SetConnect", 0);
  debug ("Set Option...rc=%d", rc);
  return 1;
}

int
scan_stmt (char *s, char *p, HSTMT hstmt)
{
  UWORD a;
  UDWORD b;
  int z;
  int rc;
  debug ("Checking %s %s %ld", s, p, hstmt);
  z = scan_options (stmt_options, s, p, (long *)&a, (long *)&b);

  if (z == -1)
    {
      exitwith ("Parameter is not applicable to option");
      return 0;
    }

  if (z == -2)
    {
      exitwith ("Option was not found");
      return 0;
    }

  debug ("Got %ld %ld stmt=%p\n", a, b, hstmt);
  rc = SQLSetStmtOption (hstmt, a, b);
  debug ("rc=%d", rc);
  set_sqlca (hstmt, "SetStmtOption", 0);
  return 1;
}




int
add_txt (char *s, int x, int hwnd)
{
  int b;
  int z;
  for (b = x - 1; b < x - 1 + (int) strlen (s); b++)
    {
      if (line[b])
	rm_txt (z, line, b);
      line[b] = hwnd;
    }
  return 0;
}

int
clrline (int line[])
{
  int a;
  for (a = 0; a < 80; a++)
    {
      line[a] = 0;
    }
  return 0;
}

int
rm_txt (int a, int line[], int ign)
{
  int b;
  for (b = 0; b < 80; b++)
    if (line[b] == a && b != ign)
      return 0;

  remove_it (a);
  return 0;
}

int
remove_it (int a)
{
  debug ("Clr %d\n", a);
  return 0;
}



char *
getres (char *s)
{
  char buff[256];
  static char buff2[256];
  int len;
  strcpy (buff, s);
  strcat (buff, "=");
  len = strlen (s);

  if (f == 0)
    f = mja_fopen ("res", "r");

  if (f == 0)
    return invalid;

  rewind (f);
  while (fgets (buff2, 255, f))
    {
      stripnl (buff2);
      if (strncasecmp (buff2, buff, len + 1) == 0)
	{
	  return &buff2[len + 1];
	}
    }
  return invalid;
}



ctol (char s)
{
  char buff[2];
  buff[0] = s;
  buff[1] = 0;
  return atoi (buff);
}


char *
generate_using_for_dmy (char *s, int size)
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
      yr = ctol (s[3]);
    }

  if (strlen (s) == 5)
    {
      v = 3;
      yr = ctol (s[3]);
      sep = s[4];
    }

  if (yr != 2 && yr != 4)
    {
      debug ("DMY setting - only 2 or 4 digits for year!");
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






void *
allocate_mem (int size, void *parent)
{
  void *ptr;
  int a;
  a = alloc_find_ptr (0);

  if (a == -1)
    {
      debug ("No free space...");
      exit (0);
    }

  alloc_mem[a].ptr = malloc (size);

  if (alloc_mem[a].ptr == 0)
    {
      debug ("No free memory...");
      exit (0);
    }

  alloc_mem[a].parent = parent;
  debug (">%p\n", alloc_mem[a].ptr);
  return alloc_mem[a].ptr;
}

init_mem ()
{
  int a;
  for (a = 0; a < MEMSIZE; a++)
    {
      alloc_mem[a].ptr = 0;
      alloc_mem[a].parent = 0;
    }
}

alloc_find_ptr (void *ptr)
{
  int a;
  for (a = 0; a < MEMSIZE; a++)
    {
      if (alloc_mem[a].ptr == ptr)
	return a;
    }
  return -1;
}

alloc_find_parent (void *ptr, int start)
{
  int a;
  for (a = start; a < MEMSIZE; a++)
    {
      if (alloc_mem[a].parent == ptr)
	return a;
    }
  return -1;
}


dealloc_mem (void *ptr)
{
  int a = -1;
  while (1)
    {
      a = alloc_find_parent (ptr, a + 1);
      if (a == -1)
	break;
/* delete anything with this as as a parent */
      dealloc_mem (alloc_mem[a].ptr);
    }
  a = alloc_find_ptr (ptr);
  if (a != -1)
    {
      alloc_mem[a].ptr = 0;
      alloc_mem[a].parent = 0;
      free (ptr);
      debug ("-%p\n", ptr);
    }
}

int
new_rescnt ()
{
  static int rescnt = 1;
  return rescnt++;
}


readfile_for_preload (char *f)
{
  FILE *fi;
  int a, b, c;
  char bu[256];
  sprintf (bu, "%s.frm", f);
  fi = mja_fopen (bu, "rb");
  if (fi == 0)
    {
      debug ("Couldnt open %s\n", bu);
      exit (0);
    }
  a = fread (buff, 1, 30000, fi);
  close (fi);
  debug ("struct s_preloaded_form pre_load_%s ={\"%s\",%d,{", f, f, a);
  for (b = 0; b < a; b += WIDTH)
    {
      debug ("\n");
//if (b>0) debug(",");
      //debug("{");

      for (c = 0; c < WIDTH; c++)
	{
	  if (c + b >= a)
	    break;
	  debug ("%3d", buff[c + b]);
	  if (c + b + 1 < a)
	    debug (",");
	}

    }
  debug ("}\n};\n");
}

/******************************************************************

			        BLOB relatad functions

******************************************************************/

get_blob_data (struct fgl_int_loc *blob, HSTMT hstmt, int colno)
{
  FILE *f;
  int cnt;


  debug("blob=%p",blob);
  debug("blob->where=%c",blob->where);
  debug("blob->filename=%s",blob->filename);

  if (blob->where != 'F' && blob->where != 'M')
    {
      exitwith ("Blob not located");
      return 0;
    }

  if (blob->where == 'F')
    {
      debug ("Writing blob to %s", blob->filename);

      if (blob->f == 0)
	{
	  blob->f = fopen (blob->filename, "w");

	  if (blob->f == 0)
	    {
	      exitwith ("Unable to open blob");
	      return 0;
	    }
	}

      cnt = get_blob_data_int (blob->f, hstmt, colno, 0);

      fclose (blob->f);
      blob->f=0;
    }
  else
    {
      debug ("Writing blob to memory");
      if (blob->ptr)
	{
	  free (blob->ptr);
	}
      cnt = get_blob_data_int (0, hstmt, colno, &blob->ptr);

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



get_blob_data_int (FILE * blob, HSTMT hstmt, int colno, char **cptr)
{
  char buff[64000];
  char *ptr = 0;
  long cnt = 0;
  int rc;
  SDWORD i;

  debug("In get_blob_data_int");

  if (blob)
    rewind (blob);

  while (1)
    {
	debug("In loop");

      if (blob == 0)
	{
	  debug("Memory...");
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


set_blob_data(HSTMT hstmt) {
  int rc;
  struct fgl_int_loc *blob;
  rc=SQL_NEED_DATA;
  while (rc==SQL_NEED_DATA) {
  	rc=SQLParamData(hstmt,(PTR)&blob);
	set_blob_data_repeat(hstmt,blob);
  }
  return rc;
}

set_blob_data_repeat (HSTMT hstmt,struct fgl_int_loc *blob)
{
  FILE *f;
  int cnt;


  debug("blob=%p",blob);
  debug("blob->where=%c",blob->where);
  debug("blob->filename=%s",blob->filename);

  if (blob->where != 'F' && blob->where != 'M')
    {
      exitwith ("Blob not located");
      return 0;
    }

  if (blob->where == 'F')
    {
      debug ("Reading blob from %s", blob->filename);

      if (blob->f == 0)
	{
	  blob->f = fopen (blob->filename, "r");

	  if (blob->f == 0)
	    {
	      exitwith ("Unable to open blob");
	      return 0;
	    }
	}

      cnt = set_blob_data_int (blob->f, hstmt, blob);

      fclose (blob->f);
      blob->f=0;
    }
  else
    {
      debug ("reading blob from memory");
      if (blob->ptr)
	{
	  free (blob->ptr);
	}
      cnt = set_blob_data_int (0, hstmt,  blob);

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



set_blob_data_int (FILE * blob, HSTMT hstmt, struct fgl_int_loc *b)
{
  char buff[64000];
  char *ptr = 0;
  long cnt = 0;
  int rc;
  int i;
  int write_bytes;

  debug("In set_blob_data_int");

  if (blob) rewind (blob);

  if (blob==0) {
  	for (i=0;i<=b->memsize;i+=sizeof(buff)) {
		if (i+sizeof(buff)<b->memsize) write_bytes=sizeof(buff);
		else write_bytes=b->memsize-i;

          rc = SQLPutData (hstmt, ptr+i, write_bytes);
	  }
	  return b->memsize;
  }
  else 
	{
		while (1) {
			write_bytes=fread(buff,1,sizeof(buff),blob);
			if (write_bytes<=0) break;
			cnt+=write_bytes;
          		rc = SQLPutData (hstmt, buff, write_bytes);
		}
			b->memsize=cnt;
			return cnt;
	}
}


//--------------------------- EOF --------------------------
