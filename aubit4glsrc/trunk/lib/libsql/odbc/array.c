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
# $Id: array.c,v 1.25 2007-07-04 17:13:48 mikeaubury Exp $
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
        Mode - not used
        Info - not used
        Arr1 = DBName
        Arr2 = Description ?

TABLES
        Mode = 1 Exclude system tables
                 otherwise include them

        arr1 = Table name
        arr2 = Schema/Owner of the Table

COLUMNS
        Mode= 0 - Fill arr2 with colsize
              1 - Fill arr2 with datatype name
                  Otherwise - fill it with the table name
        Info - Table name we're looking at
        arr1 = Column name


In all cases if the pointer the the array (arr1 or arr2) is 0 (or C-NULL) then
don't bother to fill it :-)

*/

int A4GL_fill_array_columns_mk2(int mx, char *arr1, int szarr1, char *arr2, int szarr2, int mode, char *info);


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
static SDWORD outlen[512];

#define chk_rc(rc,stmt,call) A4GL_chk_rc_full(rc,(void *)stmt,call,__LINE__,__FILE__)


/*
=====================================================================
                    Function prototypes
=====================================================================
*/

int A4GL_fill_array_databases(int mx, char *arr1, int szarr1, char *arr2,
                              int szarr2);
int A4GL_fill_array_tables   (int mx, char *arr1, int szarr1, char *arr2,
                              int szarr2, int mode);
int A4GL_fill_array_columns  (int mx, char *arr1, int szarr1, char *arr2,
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
  char srv_name[100] = "";
  char srv_desc[255] = "";
  SWORD l_srv_name = 0;
  SWORD l_srv_desc = 0;
  int rc;
  int fetch_mode = SQL_FETCH_FIRST;
  int cnt = 0;

  A4GL_dbg ("Filling database arrayarr1=%p...", arr1);

  if (henv == 0)
  {
      A4GL_err("No environment configured");
      return 0;
  }

  while (cnt < mx)
  {
      rc = SQLDataSources (henv, fetch_mode,
              (SQLCHAR*)srv_name, sizeof(srv_name), &l_srv_name,
              (SQLCHAR*)srv_desc, sizeof(srv_desc), &l_srv_desc);
      if ( ! chk_rc (rc, 0, "SQLDataSources"))
          break;
      A4GL_trc ("SQLDataSources returned rc=%d, srv_name=%s srv_desc=%s", rc, srv_name, srv_desc);
      if (rc == SQL_NO_DATA_FOUND)
          break;
      fetch_mode = SQL_FETCH_NEXT;
      if (rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO)
      {
          A4GL_set_sqlca ("fill_array_database", "");
          break;
      }

      if (arr1)
          A4GL_strncpyz(&arr1[cnt * (szarr1 + 1)], srv_name, szarr1+1);
      if (arr2)
          A4GL_strncpyz(&arr2[cnt * (szarr2 + 1)], srv_desc, szarr2+1);
      cnt++;
  }
  A4GL_trc("Found %d datasources",cnt);
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
//  char tq[256]; // we do not use these columns, but someone may need them
                  // e.g. for debugging purposes
  char to[256];
  char tn[256];
  char tt[256];
//  char tr[256];
  int rc;
  int cnt = 0;

  if (hdbc == 0)
  {
      A4GL_exitwith ("Not connected to database");
      return 0;
  }
  A4GL_dbg ("Start get tables mode=%d arr1=%p arr2=%p", mode, arr1, arr2);
  A4GL_new_hstmt (&hstmt);

  rc = SQLTables(hstmt, NULL, 0, NULL, 0, NULL, 0, NULL, 0);
  chk_rc (rc, hstmt, "SQLTables");

//  rc = SQLBindCol (hstmt, 1, SQL_C_CHAR, tq, 255, &outlen[1]);
//  chk_rc (rc, hstmt, "SQLBindCol");
  rc = SQLBindCol (hstmt, 2, SQL_C_CHAR, to, 255, &outlen[2]);
  if (!chk_rc (rc, hstmt, "SQLBindCol"))
  {
      A4GL_free_hstmt(&hstmt);
      return 0;
  }
  rc = SQLBindCol (hstmt, 3, SQL_C_CHAR, tn, 255, &outlen[3]);
  if (!chk_rc (rc, hstmt, "SQLBindCol"))
  {
      A4GL_free_hstmt(&hstmt);
      return 0;
  }
  chk_rc (rc, hstmt, "SQLBindCol");
  rc = SQLBindCol (hstmt, 4, SQL_C_CHAR, tt, 255, &outlen[4]);
  chk_rc (rc, hstmt, "SQLBindCol");
//  rc = SQLBindCol (hstmt, 5, SQL_C_CHAR, tr, 255, &outlen[5]);
//  chk_rc (rc, hstmt, "SQLBindCol");

  while (cnt < mx)
  {
      memset(to, 0, sizeof(to));
      memset(tn, 0, sizeof(tn));
      rc = SQLFetch (hstmt);
      if (!chk_rc (rc, hstmt, "SQLFetch"))
          break;
      if (rc == SQL_NO_DATA_FOUND)
          break;

      if (!strncmp("DUMMY ROW", tn, szarr1) && strlen(to) == 0) // for some weird reason DB2/VM returns such junk
	  continue;

      if (rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO)
      {
          A4GL_inf("Some error getting data....");
          A4GL_free_hstmt(&hstmt);
          break;
      }

      A4GL_trc ("cnt=%d of max %d to=%s tn=%s", cnt, mx, to, tn);
      if (mode == 1 && strstr (tt, "SYSTEM"))
          continue;


      if (arr1)
      {
          tn[min(szarr1, sizeof(tn)-1)] = 0;
          A4GL_trim(tn);
          memset(&arr1[cnt * (szarr1 + 1)], 0, szarr1+1);
          A4GL_strncpyz(&arr1[cnt * (szarr1 + 1)], tn, szarr1+1);
      }
      if (arr2)
      {
          to[min(szarr2, sizeof(to)-1)] = 0;
          A4GL_trim(to);
          memset(&arr2[cnt * (szarr2 + 1)], 0, szarr2+1);
          A4GL_strncpyz(&arr2[cnt * (szarr2 + 1)], to, szarr2+1);
      }
      cnt++;
  }
  A4GL_free_hstmt(&hstmt);
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
  int i;
  int dtype;
  int size;
  int prec;

  if (hdbc == 0)
  {
      A4GL_exitwith ("Not connected to database");
      return 0;
  }
  if (! A4GLSQL_get_columns (info, "", &dtype, &size))
      return 0;

  A4GL_init_typeinfo();
  for (i = 0; i < mx; ++i)
  {
      char *colname;
      char scolsize[32];
      char *s;

      if ( ! A4GLSQL_next_column_detailed (&colname, NULL, &size, &prec, &dtype))
          break;
      if (size != prec && (size & 0xff) != 0) //two-part prec,size
	  SPRINTF2 (scolsize, "%d,%d", ((size >> 8) & 0xff) - (size & 0xff), size & 0xff);
      else
	  SPRINTF1 (scolsize, "%d", A4GL_display_size (dtype, prec, (SQLCHAR*)""));
      A4GL_trc("colname=%s dtype=%d(0x%x) size=%d(0x%x) prec=%d(0x%x) scolsize=%s", 
                colname,   dtype,  dtype, size,   size, prec,   prec, scolsize);
      if (arr1 != 0)
          A4GL_strncpyz (&arr1[i * (szarr1 + 1)], colname, szarr1);
      if (arr2 != 0)
      {
          s = &arr2[i * (szarr2 + 1)];
          switch (mode)
          {
            case 0:
              A4GL_strncpyz(&arr2[i * (szarr2+1)], scolsize, szarr2+1);
              break;
            case 1:
              A4GL_strncpyz(&arr2[i * (szarr2+1)],
                                   A4GL_type_id_to_name(dtype), szarr2+1);
              break;
            case 2:
              {
                  char scolsize_p[sizeof(scolsize)+3];
                  int sizelen;
                  int namelen;
                  int max_namelen;
                  A4GL_strncpyz (s, A4GL_type_id_to_name(dtype), szarr2+1);
                  sprintf(scolsize_p, "(%s)", scolsize);
                  sizelen = strlen(scolsize_p);
                  max_namelen = szarr2 - sizelen;
                  namelen = strlen(s);
                  if (namelen > max_namelen)
                  {
                      s[max_namelen-1] = '~';
                      A4GL_strncpyz(s + max_namelen, scolsize_p, sizelen+1);
                  }
                  else if (namelen > max_namelen)
                      A4GL_strncpyz(s + max_namelen, scolsize_p, sizelen+1);
                  else
                      strcat(s, scolsize_p);
              }
              break;
            default:
              A4GL_strncpyz (&arr2[i * (szarr2 + 1)], info, szarr2+1);
              break;
          }
      }
  }

  A4GLSQL_end_get_columns ();
  return i;
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
    A4GL_dbg("Fill array... service=%s mode=%d info=%s, arr1=%p szarr1=%i arr2=%p szarr2=%i",
            service, mode, info ? info : "<NULL>", arr1, szarr1, arr2, szarr2);
    if (strcmp (service, "DATABASES") == 0)
        return A4GL_fill_array_databases (mx, arr1, szarr1, arr2, szarr2);

    if (strcmp (service, "TABLES") == 0)
        return A4GL_fill_array_tables (mx, arr1, szarr1, arr2, szarr2, mode);

    if (strcmp (service, "COLUMNS") == 0)
        return A4GL_fill_array_columns (mx, arr1, szarr1, arr2, szarr2, mode, info);

    A4GL_err("****** ERROR unknown service :%s", service);
    return 0;
}


/* ================================== EOF ============================== */
