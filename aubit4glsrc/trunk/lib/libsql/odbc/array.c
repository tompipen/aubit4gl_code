/******************************************************************************
* (c) 1997-1998 Aubit Computing Ltd.
* 
* $Id: array.c,v 1.1 2003-02-14 12:49:31 mikeaubury Exp $
*
* Project : Part Of Aubit 4GL Library Functions
*
* Change History :
*	$Log: not supported by cvs2svn $
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include "a4gl_lib_sql_odbc_int.h"

extern HENV                    henv ;
extern HDBC                    hdbc;
SDWORD                  outlen[512];


int fill_array_databases (int mx, char *arr1, int szarr1, char *arr2, int szarr2)
{
  char buff1[80];
  char buff2[255];
  SWORD a;
  SWORD b;
  int rc;
  int fetch_mode;
  int cnt;
  a = 0;
  b = 0;
#ifdef DEBUG
/* {DEBUG} */
  {
    debug ("arr1=%p", arr1);
  }
#endif
  fetch_mode = SQL_FETCH_FIRST;
  cnt = 0;
#ifdef DEBUG
/* {DEBUG} */
  {
    debug ("Filling database array...");
  }
#endif
  while (cnt < mx)
    {
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("Fetch mode=%d", fetch_mode);
      }
#endif
      rc = SQLDataSources (henv, fetch_mode, buff1, 79, &a, buff2, 254, &b);
      chk_rc (rc, 0, "SQLDataSources");
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("  rc=%d", rc);
      }
#endif
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("  Buff1=%s Buff2=%s", buff1, buff2);
      }
#endif
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("  a=%d b=%d", a, b);
      }
#endif
      fetch_mode = SQL_FETCH_NEXT;
      if (rc == SQL_NO_DATA_FOUND)
	break;
      if (rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO)
	{
	  set_sqlca (0, "fill_array_database", 0);
#ifdef DEBUG
/* {DEBUG} */
	  {
	    debug ("Some error getting data....");
	  }
#endif
	  break;
	}

      if (arr1 != 0)
	strncpy (&arr1[cnt * (szarr1 + 1)], buff1, szarr1);
      if (arr2 != 0)
	strncpy (&arr2[cnt * (szarr2 + 1)], buff2, szarr2);
      cnt++;
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("fill array databases : Rc= %d", rc);
      }
#endif
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("    Buff1=%s", buff1);
      }
#endif
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("    Buff2=%s", buff2);
      }
#endif
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("    a=%d", a);
      }
#endif
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("    b=%d", b);
      }
#endif
    }
  return cnt;

}


int fill_array_tables (int mx, char *arr1, int szarr1, char *arr2, int szarr2, int mode)
{
  HSTMT hstmt;
  //char buff1[80];
  //char buff2[255];

  char tq[256];
  char to[256];
  char tn[256];
  char tt[256];
  char tr[256];

  int a, b;
  int rc;
  //int fetch_mode;
  int cnt;

  if (hdbc == 0)
    {
      exitwith ("Not connected to database");
      return 0;
    }
#ifdef DEBUG
/* {DEBUG} */
  {
    debug ("STart get tables ... Mode=%d", mode);
  }
#endif
  new_hstmt (&hstmt);

  rc = SQLTables (hstmt,
		  NULL, 0,
		  NULL, 0,
		  NULL, 0,
		  NULL, 0
    );
  chk_rc (rc, hstmt, "SQLTables");
  a = 79;
  b = 254;
#ifdef DEBUG
/* {DEBUG} */
  {
    debug ("arr1=%p", arr1);
  }
#endif
  cnt = 0;

  rc = SQLBindCol (hstmt, 1, SQL_C_CHAR, tq, 255, &outlen[1]);
  chk_rc (rc, hstmt, "SQLBindCol");
  rc = SQLBindCol (hstmt, 2, SQL_C_CHAR, to, 255, &outlen[2]);
  chk_rc (rc, hstmt, "SQLBindCol");
  rc = SQLBindCol (hstmt, 3, SQL_C_CHAR, tn, 255, &outlen[3]);
  chk_rc (rc, hstmt, "SQLBindCol");
  rc = SQLBindCol (hstmt, 4, SQL_C_CHAR, tt, 255, &outlen[4]);
  chk_rc (rc, hstmt, "SQLBindCol");
  rc = SQLBindCol (hstmt, 5, SQL_C_CHAR, tr, 255, &outlen[5]);
  chk_rc (rc, hstmt, "SQLBindCol");

  while (cnt < mx)
    {
      rc = SQLFetch (hstmt);
      chk_rc (rc, hstmt, "SQLFetch");

      if (rc == SQL_NO_DATA_FOUND)
	break;

      if (rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO)
	{
#ifdef DEBUG
/* {DEBUG} */
	  {
	    debug ("Some error getting data....");
	  }
#endif
	  SQLFreeStmt (hstmt, SQL_DROP);
	  chk_rc (rc, 0, "SQLFreeStmt");
	  break;
	}
#ifdef DEBUG
/* {DEBUG} */
      {
	debug (" tq= %s to= %s", tq, to);
      }
#endif
#ifdef DEBUG
/* {DEBUG} */
      {
	debug (" tn= %s tt= %s", tn, tt);
      }
#endif
#ifdef DEBUG
/* {DEBUG} */
      {
	debug (" tr= %s", tr);
      }
#endif

#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("Mode=%d", mode);
      }
#endif
      if (mode == 1)
	{

	  if (strstr (tt, "SYSTEM"))
	    {
#ifdef DEBUG
/* {DEBUG} */
	      {
		debug ("Is system table");
	      }
#endif
	      continue;
	    }
	}

      if (arr1 != 0)
	strncpy (&arr1[cnt * (szarr1 + 1)], tn, szarr1);
      if (arr2 != 0)
	strncpy (&arr2[cnt * (szarr2 + 1)], tr, szarr2);
      cnt++;
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("fill array tables : Rc= %d", rc);
      }
#endif
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("    a=%d", a);
      }
#endif
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("    b=%d", b);
      }
#endif
    }
  rc = SQLFreeStmt (hstmt, SQL_DROP);
  chk_rc (rc, hstmt, "SQLFreeStmt");
  return cnt;
}



int fill_array_columns (int mx, char *arr1, int szarr1, char *arr2, int szarr2, int mode, char *info)
{
  HSTMT hstmt;
  //char buff1[80];
  //char buff2[255];

  char tq[256];
  char to[256];
  char tn[256];
  char cn[256];
  int dt;
  char dtname[256];
  long prec;
  long len;
  long scale;
  long radix;
  long nullable;
  char remarks[256];
  int colsize;
  char szcolsize[20];
  int a, b;
  int rc;
  //int fetch_mode;
  int cnt;
  HSTMT ret;
#ifdef DEBUG
/* {DEBUG} */
  {
    debug ("Fill array columns for table %s", info);
  }
#endif

  if (hdbc == 0)
    {
      exitwith ("Not connected to database");
      return 0;
    }

  ret = new_hstmt (&hstmt);

  debug ("Getting columns for '%s'", info);
  rc = SQLColumns (hstmt,
		   NULL, 0,
		   NULL, 0,
		   info,
		   SQL_NTS,
		   NULL, 0
    );
  chk_rc (rc, hstmt, "SQLColumns");
  debug (" SQLColumns returned rc=%d", rc);
  a = 79;
  b = 254;
#ifdef DEBUG
/* {DEBUG} */
  {
    debug ("arr1=%p", arr1);
  }
#endif
  cnt = 0;

  SQLBindCol (hstmt, 1, SQL_C_CHAR, tq, 255, &outlen[1]);
  SQLBindCol (hstmt, 2, SQL_C_CHAR, to, 255, &outlen[2]);
  SQLBindCol (hstmt, 3, SQL_C_CHAR, tn, 255, &outlen[3]);
  SQLBindCol (hstmt, 4, SQL_C_CHAR, cn, 255, &outlen[4]);
  SQLBindCol (hstmt, 6, SQL_C_CHAR, dtname, 255, &outlen[6]);
  SQLBindCol (hstmt, 12, SQL_C_CHAR, remarks, 255, &outlen[12]);
  SQLBindCol (hstmt, 5, SQL_C_LONG, &dt, 4, &outlen[5]);
  SQLBindCol (hstmt, 7, SQL_C_LONG, &prec, 4, &outlen[7]);
  SQLBindCol (hstmt, 8, SQL_C_LONG, &len, 4, &outlen[8]);
  SQLBindCol (hstmt, 9, SQL_C_LONG, &scale, 4, &outlen[9]);
  SQLBindCol (hstmt, 10, SQL_C_LONG, &radix, 4, &outlen[10]);
  SQLBindCol (hstmt, 11, SQL_C_LONG, &nullable, 4, &outlen[11]);

  while (cnt < mx)
    {
      rc = SQLFetch (hstmt);
      if (rc == SQL_NO_DATA_FOUND || rc == SQL_ERROR)
	break;
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("column -> %s Dtype=%x len=%x rc=%d", cn, dt, len, rc);
      }
#endif
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("column %s %s %s %s", tq, to, tn, cn);
      }
#endif
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("XXX       %x %s prec=%x %d\n %x %x %x '%s'", dt, dtname, prec, len, scale, radix, nullable, remarks);
      }
#endif
      colsize = display_size (dt, prec, "");
      sprintf (szcolsize, "%d", colsize);

      if (rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO)
	{
#ifdef DEBUG
/* {DEBUG} */
	  {
	    debug ("Some error getting data....");
	  }
#endif
	  SQLFreeStmt (hstmt, SQL_DROP);
	  break;
	}

      if (arr1 != 0)
	strncpy (&arr1[cnt * (szarr1 + 1)], cn, szarr1);
      if (arr2 != 0)
	{
	  switch (mode)
	    {
	    case 0:
	      strncpy (&arr2[cnt * (szarr2 + 1)], szcolsize, szarr2);
	      break;
	    case 1:
	      strncpy (&arr2[cnt * (szarr2 + 1)], dtname, szarr2);
	      break;
	    default:
	      strncpy (&arr2[cnt * (szarr2 + 1)], tn, szarr2);
	      break;
	    }
	}
      cnt++;
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("fill array columns : Rc= %d", rc);
      }
#endif
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("    cb=%s dtname=%s", cn, dtname);
      }
#endif
    }
  SQLFreeStmt (hstmt, SQL_DROP);
  return cnt;
}

/*************************************/
/* fill array ...
   mx = maximum number of rows to fill in in arr1/arr2
   arr1 = address of array 1
   szarr1 = size of each item in array 1 
   (eg ARRAY[20] of char(30) : mx=20, szarr1=30
   arr2 = address of array 2
   szarr2 = size of each item in array 2
   service = what to fill in : DATABASES, TABLES, COLUMNS
   mode = specific to service , when used by TABLES = exclude system tables
   info = specific to service , when used by COLUMNS specifies the table name
   ************************************ */
int A4GLSQL_fill_array (int mx, char **arr1, int szarr1, char **arr2, int szarr2,
	    char *service, int mode, char *info)
{
  debug ("Fill array.... mode = %d", mode);
  if (strcmp (service, "DATABASES") == 0)
    {
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("Get Databases");
      }
#endif
      return fill_array_databases (mx, arr1, szarr1, arr2, szarr2);
    }

  if (strcmp (service, "TABLES") == 0)
    {
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("Get Tables");
      }
#endif
      return fill_array_tables (mx, arr1, szarr1, arr2, szarr2, mode);
    }

  if (strcmp (service, "COLUMNS") == 0)
    {
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("Get columns");
      }
#endif
      return fill_array_columns (mx, arr1, szarr1, arr2, szarr2, mode, info);
    }
#ifdef DEBUG
/* {DEBUG} */
  {
    debug ("****** ERROR unknown service :%s", service);
  }
#endif
}


