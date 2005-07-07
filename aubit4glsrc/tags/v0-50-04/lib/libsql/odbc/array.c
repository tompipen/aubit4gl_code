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
# $Id: array.c,v 1.15 2005-05-21 16:18:50 mikeaubury Exp $
#
*/

/**
 * @file
 * ODBC Sql array functions for LOAD FROM ... INSERT INTO

The fill_array are supposed to populate an array with information on
databases, tables or columns.

The returns are into an char[szarr], so arr1 should really be something like
	char arr1[mx][szarr1] (if you see what I mean)...

The main interface is via fill_array where 'service' points to one of
the other functions (DATABASES, TABLES or COLUMNS)...

The 'mode' specifies what data to load into the arrays
the 'info' passes some extra details into the functions (like table names etc)

DATABASES
	Mode  - not used
	Info - not used
	Arr1 = DBName
	Arr2 = Description ?

TABLES
	Mode =1 Exclude system tables
		otherwise include them

	arr1 = Table name
	arr2 = Table description

COLUMNS
	Mode= 0 - Fill arr2 with colsize
		     1 - Fill arr2 with datatype name
		Otherwise - fill it with the table name
	Info - Table name we're looking at
	arr1 = Column name



In all cases if the pointer the the array (arr1 or arr2) is 0 (or C-NULL) then
don't bother to fill it :-)



 *
 */

int A4GL_fill_array_columns_mk2 (int mx, char *arr1, int szarr1, char *arr2, int szarr2, int mode, char *info);


/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_lib_sql_odbc_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/


extern HENV henv;
extern HDBC hdbc;
SDWORD outlen[512];

#define chk_rc(rc,stmt,call) A4GL_chk_rc_full(rc,(void *)stmt,call,__LINE__,__FILE__)


/*
=====================================================================
                    Function prototypes
=====================================================================
*/

int A4GL_fill_array_databases (int mx, char *arr1, int szarr1, char *arr2,
			  int szarr2);
int A4GL_fill_array_tables (int mx, char *arr1, int szarr1, char *arr2, int szarr2,
		       int mode);
int A4GL_fill_array_columns (int mx, char *arr1, int szarr1, char *arr2,
			int szarr2, int mode, char *info);


/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Fill database array
 *
 * @param mx        maximum number of rows to fill in in arr1/arr2
 * @param arr1      address of array 1
 * @param szarr1    size of each item in array 1 (eg ARRAY[20] of char(30) : mx=20, szarr1=30)
 * @param arr2      address of array 2
 * @param szarr2    size of each item in array 2
 *
 * @return Number of rows filled
 */
int
A4GL_fill_array_databases (int mx, char *arr1, int szarr1, char *arr2, int szarr2)
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
  A4GL_debug ("arr1=%p", arr1);
#endif
  fetch_mode = SQL_FETCH_FIRST;
  cnt = 0;
#ifdef DEBUG
  A4GL_debug ("Filling database array...");
#endif
  while (cnt < mx)
    {
#ifdef DEBUG
      A4GL_debug ("Fetch mode=%d", fetch_mode);
#endif
      rc = SQLDataSources (henv, fetch_mode, buff1, 79, &a, buff2, 254, &b);
      chk_rc (rc, 0, "SQLDataSources");
#ifdef DEBUG
      A4GL_debug ("  rc=%d", rc);
      A4GL_debug ("  Buff1=%s Buff2=%s", buff1, buff2);
      A4GL_debug ("  a=%d b=%d", a, b);
#endif
      fetch_mode = SQL_FETCH_NEXT;
      if (rc == SQL_NO_DATA_FOUND)
	break;
      if (rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO)
	{
	  A4GL_set_sqlca (0, "fill_array_database", 0);
#ifdef DEBUG
	  A4GL_debug ("Some error getting data....");
#endif
	  break;
	}

      if (arr1 != 0)
	strncpy (&arr1[cnt * (szarr1 + 1)], buff1, szarr1);
      if (arr2 != 0)
	strncpy (&arr2[cnt * (szarr2 + 1)], buff2, szarr2);
      cnt++;
#ifdef DEBUG
      A4GL_debug ("fill array databases : Rc= %d", rc);
      A4GL_debug ("    Buff1=%s", buff1);
      A4GL_debug ("    Buff2=%s", buff2);
      A4GL_debug ("    a=%d", a);
      A4GL_debug ("    b=%d", b);
#endif
    }

  return cnt;

}


/**
 * Fill table array
 *
 * @param mx        maximum number of rows to fill in in arr1/arr2
 * @param arr1      address of array 1
 * @param szarr1    size of each item in array 1 (eg ARRAY[20] of char(30) : mx=20, szarr1=30)
 * @param arr2      address of array 2
 * @param szarr2    size of each item in array 2
 * @param mode      specific to service , when used by TABLES = exclude system tables
 *
 * @return Number of rows filled
 */
int
A4GL_fill_array_tables (int mx, char *arr1, int szarr1, char *arr2, int szarr2,
		   int mode)
{
  HSTMT hstmt;
  char tq[256];
  char to[256];
  char tn[256];
  char tt[256];
  char tr[256];
  int a, b;
  int rc;
  int cnt;

  if (hdbc == 0)
    {
      A4GL_exitwith ("Not connected to database");
      return 0;
    }
#ifdef DEBUG
  A4GL_debug ("STart get tables ... Mode=%d", mode);
#endif
  A4GL_new_hstmt (&hstmt);

  rc = SQLTables (hstmt, NULL, 0, NULL, 0, NULL, 0, NULL, 0);

  chk_rc (rc, hstmt, "SQLTables");
  a = 79;
  b = 254;
#ifdef DEBUG
  A4GL_debug ("arr1=%p", arr1);
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
	  A4GL_debug ("Some error getting data....");
#endif
	  SQLFreeStmt (hstmt, SQL_DROP);
	  chk_rc (rc, 0, "SQLFreeStmt");
	  break;
	}

#ifdef DEBUG
      A4GL_debug (" tq= %s to= %s", tq, to);
      A4GL_debug (" tn= %s tt= %s", tn, tt);
      A4GL_debug (" tr= %s", tr);
      A4GL_debug ("Mode=%d", mode);
#endif
      if (mode == 1)
	{
	  if (strstr (tt, "SYSTEM"))
	    {
#ifdef DEBUG
	      A4GL_debug ("Is system table");
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
      A4GL_debug ("fill array tables : Rc= %d", rc);
      A4GL_debug ("    a=%d", a);
      A4GL_debug ("    b=%d", b);
#endif
    }

  rc = SQLFreeStmt (hstmt, SQL_DROP);
  chk_rc (rc, hstmt, "SQLFreeStmt");
  return cnt;
}



/**
 * Fill column array
 *
 * @param mx        maximum number of rows to fill in in arr1/arr2
 * @param arr1      address of array 1
 * @param szarr1    size of each item in array 1 (eg ARRAY[20] of char(30) : mx=20, szarr1=30)
 * @param arr2      address of array 2
 * @param szarr2    size of each item in array 2
 * @param mode      specific to service , when used by TABLES = exclude system tables
 * @param info      specific to service , when used by COLUMNS specifies the table name
 *
 * @return Number of rows filled
 */
int
A4GL_fill_array_columns (int mx, char *arr1, int szarr1, char *arr2, int szarr2,
		    int mode, char *info)
{
  SQLHSTMT hstmt;
struct  {
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
} data;
  int colsize;
  char szcolsize[20];
  int a, b;
  int rc;
  int cnt;
  SQLHSTMT ret;



#ifdef DEBUG
  A4GL_debug ("Fill array columns for table %s", info);
#endif

  if (hdbc == 0)
    {
      A4GL_exitwith ("Not connected to database");
      return 0;
    }

  ret = (SQLHSTMT)A4GL_new_hstmt ((SQLHSTMT *)&hstmt);

#ifdef DEBUG
  A4GL_debug ("Getting columns for '%s'", info);
#endif

  rc = SQLColumns (hstmt, NULL, 0, NULL, 0, info, SQL_NTS, NULL, 0);

  chk_rc (rc, hstmt, "SQLColumns");

#ifdef DEBUG
  A4GL_debug (" SQLColumns returned rc=%d", rc);
#endif
  a = 79;
  b = 254;
#ifdef DEBUG
  A4GL_debug ("arr1=%p", arr1);
#endif

  cnt = 0;

  SQLBindCol (hstmt, 1, SQL_C_CHAR, data.tq, 255, &outlen[1]);
  SQLBindCol (hstmt, 2, SQL_C_CHAR, data.to, 255, &outlen[2]);
  SQLBindCol (hstmt, 3, SQL_C_CHAR, data.tn, 255, &outlen[3]);
  SQLBindCol (hstmt, 4, SQL_C_CHAR, data.cn, 255, &outlen[4]);
  SQLBindCol (hstmt, 6, SQL_C_CHAR, data.dtname, 255, &outlen[6]);
  SQLBindCol (hstmt, 12, SQL_C_CHAR, data.remarks, 255, &outlen[12]);
  SQLBindCol (hstmt, 5, SQL_C_LONG, &data.dt, 4, &outlen[5]);
  SQLBindCol (hstmt, 7, SQL_C_LONG, &data.prec, 4, &outlen[7]);
  SQLBindCol (hstmt, 8, SQL_C_LONG, &data.len, 4, &outlen[8]);
  SQLBindCol (hstmt, 9, SQL_C_LONG, &data.scale, 4, &outlen[9]);
  SQLBindCol (hstmt, 10, SQL_C_LONG, &data.radix, 4, &outlen[10]);
  SQLBindCol (hstmt, 11, SQL_C_LONG, &data.nullable, 4, &outlen[11]);

  	while (cnt < mx) {
		memset(&data,0,sizeof(data));
		rc = SQLFetch (hstmt);
		if (rc == SQL_NO_DATA_FOUND || rc == SQL_ERROR){
			#ifdef DEBUG
				A4GL_debug ("Done fetch - got %d", rc);
			#endif
			break;
		}
		#ifdef DEBUG
		A4GL_debug ("column -> %s Dtype=%x len=%x rc=%d", data.cn, data.dt, data.len, rc);
		A4GL_debug ("column %s %s %s %s", data.tq, data.to, data.tn, data.cn);
		A4GL_debug ("XXX       %x %s prec=%x %d\n %x %x %x '%s'", data.dt, data.dtname, data.prec,
	     	data.len, data.scale, data.radix, data.nullable, data.remarks);
		#endif
		colsize = A4GL_display_size (data.dt, data.prec, "");
		sprintf (szcolsize, "%d", colsize);

		if (rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO) {
			#ifdef DEBUG
				A4GL_debug ("Some error getting data....");
			#endif
			SQLFreeStmt (hstmt, SQL_DROP);
			break;
		}

		if (arr1 != 0) {
			strncpy (&arr1[cnt * (szarr1 + 1)], data.cn, szarr1);
		}
		if (arr2 != 0) {
			switch (mode) {
				case 0:
					strncpy (&arr2[cnt * (szarr2 + 1)], szcolsize, szarr2);
					break;
				case 1:
					strncpy (&arr2[cnt * (szarr2 + 1)], data.dtname, szarr2);
					break;
				default:
					strncpy (&arr2[cnt * (szarr2 + 1)], data.tn, szarr2);
					break;
			}
		}
		cnt++;
		#ifdef DEBUG
			A4GL_debug ("fill array columns : Rc= %d", rc);
			A4GL_debug ("    cb=%s dtname=%s", data.cn, data.dtname);
		#endif
    }
	SQLFreeStmt (hstmt, SQL_DROP);
	return cnt;
}

int 
A4GL_fill_array_columns_mk2 (int mx, char *arr1, int szarr1, char *arr2, int szarr2, int mode, char *info) {
SQLHSTMT hstmt;
int rc;
SQLHSTMT ret;
char buff[256];
SQLSMALLINT scale;
SQLSMALLINT nullable;
int allow_no_rows=1;
SQLSMALLINT ncols;
char colname[64];
SWORD colnamelen;
SQLSMALLINT coltype;
int colcnt;
UDWORD collen;

  	#ifdef DEBUG
  		A4GL_debug ("Fill array columns for table %s", info);
	#endif

  	if (hdbc == 0){
		A4GL_exitwith ("Not connected to database");
		return 0;
    }
	ret = (SQLHSTMT)A4GL_new_hstmt ((SQLHSTMT *)&hstmt);
  	if (allow_no_rows) {
		sprintf(buff,"select * from %s where 1=0",info);
	} else {
		sprintf(buff,"select * from %s ",info);
	}

	SQLPrepare ((SQLHSTMT)hstmt, buff, SQL_NTS);
	rc = SQLExecute(hstmt);
	chk_rc (rc, hstmt, "unload_data");
	if (rc<0) {
		return 0;
	}
	rc = SQLNumResultCols (hstmt, &ncols);
	chk_rc (rc, hstmt, "unload_data");
	if (rc<0) {
		return 0;
	}


  	for (colcnt = 1; colcnt <= ncols; colcnt++) {
		rc = SQLDescribeCol (hstmt, colcnt, colname, (SWORD) sizeof (colname), 
			&colnamelen, &coltype, &collen, &scale, &nullable);
		chk_rc (rc, hstmt, "SQLDescribeCol");
		if (arr1 != 0) {
			strncpy (&arr1[(colcnt-1) * (szarr1 + 1)], colname, szarr1);
		}
		if (arr2 != 0) {
			switch (mode) {
				case 0:
					{ char buff[256];
						#ifdef SQLITE
							sprintf(buff,"%d",collen);
						#else
							//sprintf(buff,"%ld",collen);
							sprintf(buff,"%d",(int)collen);
							/*warning: long int format, int arg (arg 3)
							UDWORD collen;
							*/
						#endif
						strncpy (&arr2[(colcnt-1) * (szarr2 + 1)], buff, szarr2);
					}
					break;
				case 1:
              		strncpy (&arr2[(colcnt-1) * (szarr2 + 1)], "CHAR(-1)", szarr2);
					break;
				default:
					strncpy (&arr2[(colcnt-1) * (szarr2 + 1)], info, szarr2);
					break;
            }
        }
	}

	SQLFreeStmt (hstmt, SQL_DROP);
	return colcnt-1;
}


/**
 * Fill array - depending on service specified, invokes appropriate function
 * that does the work
 *
 * @param mx        maximum number of rows to fill in in arr1/arr2
 * @param arr1      address of array 1
 * @param szarr1    size of each item in array 1 (eg ARRAY[20] of char(30) : mx=20, szarr1=30)
 * @param arr2      address of array 2
 * @param szarr2    size of each item in array 2
 * @param service   what to fill in : DATABASES, TABLES, COLUMNS
 * @param mode      specific to service , when used by TABLES = exclude system tables
 * @param info      specific to service , when used by COLUMNS specifies the table name
 *
 * @return Number of rows filled
 */
int
A4GLSQLLIB_A4GLSQL_fill_array (int mx, char *arr1, int szarr1, char *arr2, int szarr2,
		    char *service, int mode, char *info)
{
#ifdef DEBUG
  A4GL_debug ("Fill array.... mode = %d", mode);
#endif

/*

array.c:435: warning: passing arg 2 of `fill_array_databases' from incompatible pointer type
array.c:435: warning: passing arg 4 of `fill_array_databases' from incompatible pointer type
array.c:443: warning: passing arg 2 of `fill_array_tables' from incompatible pointer type
array.c:443: warning: passing arg 4 of `fill_array_tables' from incompatible pointer type
array.c:451: warning: passing arg 2 of `fill_array_columns' from incompatible pointer type
array.c:451: warning: passing arg 4 of `fill_array_columns' from incompatible pointer type

*/



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
	rval=A4GL_fill_array_columns (mx, arr1, szarr1, arr2, szarr2, mode, info);
	if (rval<=0) {
		// Try again a different way...
		rval=A4GL_fill_array_columns_mk2 (mx, arr1, szarr1, arr2, szarr2, mode, info);
	}
	A4GL_debug("Got %d\n",rval);
      return rval;
    }
#ifdef DEBUG
  A4GL_debug ("****** ERROR unknown service :%s", service);
#endif
  return (0);
}


/* ================================== EOF ============================== */
