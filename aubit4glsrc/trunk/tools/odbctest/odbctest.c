/*
 *  odbctest.c
 *
 *  $Id: odbctest.c,v 1.5 2003-05-12 14:24:42 mikeaubury Exp $
 *
 *  Sample ODBC program
 *
 *  Distributed as part of the iODBC driver manager.
 *
 *  Copyright (C) 1999 by OpenLink Software <iodbc@openlinksw.com>
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the Free
 *  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#include <stdio.h>
#include <string.h>



#if (defined (__CYGWIN__) || defined (__MINGW32__))
#include <windows.h>
#include <sqlext.h>
#else

#ifdef UNIXODBC
#include <sql.h>
#include <sqlext.h>
#endif

#ifdef IODBC
#include "isql.h"
#include "isqlext.h"
#endif
#endif


#ifdef THIS_IS_FROM_AUBIT_
#if (defined (__CYGWIN__) || defined (__MINGW32__))
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


#ifdef SAPODBC
#include "WINDOWS.H"
				/*
				   incl/WINDOWS.H Header file for non-MS Windows platforms. On MS Windows 3.1 or
				   Windows NT, this file can be replaced by windows.h if an SDK has been installed.
				   Also defines thingsa like DWORD needed by followint headers.
				 */

#include <sql.h>		/* Header file for the ODBC driver (Core). */
#include <sqlext.h>		/* Header file for the ODBC driver (Level1 and Level2). */
#include <sqltypes.h>		/* Header file for the ODBC driver (Datatypes). */

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

#endif


#define MAXCOLS		32


SQLHENV henv;
SQLHDBC hdbc;
SQLHSTMT hstmt;
int connected;


/*
 *  Connect to the datasource
 *
 *  The connect string can have the following parts and they refer to
 *  the values in the odbc.ini file
 *
 *	DSN=<data source name>		[mandatory]
 *	HOST=<server host name>		[optional - value of Host]
 *	SVT=<database server type>	[optional - value of ServerType]
 *	DATABASE=<database path>	[optional - value of Database]
 *	OPTIONS=<db specific opts>	[optional - value of Options]
 *	UID=<user name>			[optional - value of LastUser]
 *	PWD=<password>			[optional]
 *	READONLY=<N|Y>			[optional - value of ReadOnly]
 *	FBS=<fetch buffer size>		[optional - value of FetchBufferSize]
 *
 *   Examples:
 *
 *	HOST=star;SVT=Informix 5;UID=demo;PWD=demo;DATABASE=stores5
 *
 *	DSN=stores5_informix;PWD=demo
 */
int
DB_Connect (char *connStr)
{
  short buflen;
  char buf[257];
  SQLCHAR dataSource[120];
  SQLCHAR dsn[33];
  SQLCHAR desc[255];
  SWORD len1, len2;
  int status;

#if (ODBCVER < 0x0300)
  if (SQLAllocEnv (&henv) != SQL_SUCCESS)
    return -1;

  if (SQLAllocConnect (henv, &hdbc) != SQL_SUCCESS)
    return -1;
#else
  if (SQLAllocHandle (SQL_HANDLE_ENV, NULL, &henv) != SQL_SUCCESS)
    return -1;

  SQLSetEnvAttr (henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER) SQL_OV_ODBC3,
		 SQL_IS_UINTEGER);

  if (SQLAllocHandle (SQL_HANDLE_DBC, henv, &hdbc) != SQL_SUCCESS)
    return -1;
#endif

  /*
   *  Either use the connect string provided on the command line or
   *  ask for one. If an empty string or a ? is given, show a nice
   *  list of options
   */
  if (connStr && *connStr)
    strcpy ((char *) dataSource, connStr);
  else
    while (1)
      {
	/*
	 *  Ask for the connect string
	 */
	printf ("\nEnter ODBC connect string (? shows list): ");
	if (fgets ((char *) dataSource, sizeof (dataSource), stdin) == NULL)
	  return 1;

	/*
	 *  Remove trailing '\n'
	 */
	dataSource[strlen ((char *) dataSource) - 1] = '\0';

	/*
	 *  If the user entered something other than a ?
	 *  break out of the while loop
	 */
	if (*dataSource && *dataSource != '?')
	  break;


	/*
	 *  Print headers
	 */
	fprintf (stderr, "\n%-30s | %-30s\n", "DSN", "Description");
	fprintf (stderr,
		 "---------------------------------------------------------------\n");

	/*
	 *  Goto the first record
	 */
	if (SQLDataSources (henv, SQL_FETCH_FIRST,
			    dsn, 33, &len1, desc, 255, &len2) != SQL_SUCCESS)
	  continue;

	/*
	 *  Show all records
	 */
	do
	  {
	    fprintf (stderr, "%-30s | %-30s\n", dsn, desc);
	  }
	while (SQLDataSources (henv, SQL_FETCH_NEXT,
			       dsn, 33, &len1, desc, 255,
			       &len2) == SQL_SUCCESS);
      }

  status = SQLDriverConnect (hdbc, 0, (UCHAR *) dataSource, SQL_NTS,
			     (UCHAR *) buf, sizeof (buf), &buflen,
			     SQL_DRIVER_COMPLETE);

  if (status != SQL_SUCCESS && status != SQL_SUCCESS_WITH_INFO)
    return -1;

  SQLSetConnectOption (hdbc, SQL_OPT_TRACEFILE, (UDWORD) "\\SQL.LOG");

  connected = 1;

#if (ODBCVER < 0x0300)
  if (SQLAllocStmt (hdbc, &hstmt) != SQL_SUCCESS)
    return -1;
#else
  if (SQLAllocHandle (SQL_HANDLE_STMT, hdbc, &hstmt) != SQL_SUCCESS)
    return -1;
#endif

  return 0;
}


/*
 *  Disconnect from the database
 */
int
DB_Disconnect (void)
{
#if (ODBCVER < 0x0300)
  if (hstmt)
    SQLFreeStmt (hstmt, SQL_DROP);

  if (connected)
    SQLDisconnect (hdbc);

  if (hdbc)
    QLFreeConnect (hdbc);

  if (henv)
    SQLFreeEnv (henv);
#else
  if (hstmt)
    SQLFreeHandle (SQL_HANDLE_STMT, hstmt);

  if (connected)
    SQLDisconnect (hdbc);

  if (hdbc)
    SQLFreeHandle (SQL_HANDLE_DBC, hdbc);

  if (henv)
    SQLFreeHandle (SQL_HANDLE_ENV, henv);
#endif

  return 0;
}


/*
 *  This is the message handler for the communications layer.
 *
 *  The messages received here are not passed through SQLError,
 *  because they might occur when no connection is established.
 *
 *  Typically, Rejections from oplrqb are trapped here, and
 *  also RPC errors.
 *
 *  When no message handler is installed, the messages are output to stderr
 */
void
DB_MesgHandler (char *reason)
{
  fprintf (stderr, "DB_MesgHandler: %s\n", reason);
}


/*
 *  Show all the error information that is available
 */
int
DB_Errors (char *where)
{
  unsigned char buf[250];
  unsigned char sqlstate[15];

  /*
   *  Get statement errors
   */
  while (SQLError (henv, hdbc, hstmt, sqlstate, NULL,
		   buf, sizeof (buf), NULL) == SQL_SUCCESS)
    {
      fprintf (stderr, "%s, SQLSTATE=%s\n", buf, sqlstate);
    }

  /*
   *  Get connection errors
   */
  while (SQLError (henv, hdbc, SQL_NULL_HSTMT, sqlstate, NULL,
		   buf, sizeof (buf), NULL) == SQL_SUCCESS)
    {
      fprintf (stderr, "%s, SQLSTATE=%s\n", buf, sqlstate);
    }

  /*
   *  Get environmental errors
   */
  while (SQLError (henv, SQL_NULL_HDBC, SQL_NULL_HSTMT, sqlstate, NULL,
		   buf, sizeof (buf), NULL) == SQL_SUCCESS)
    {
      fprintf (stderr, "%s, SQLSTATE=%s\n", buf, sqlstate);
    }

  return -1;
}


/*
 *  Test program to run on the connected database
 */
int
DB_Test ()
{
  char request[512];
  char fetchBuffer[1000];
  short displayWidths[MAXCOLS];
  short displayWidth;
  short numCols;
  short colNum;
  char colName[50];
  short colType;
  UDWORD colPrecision;
  SDWORD colIndicator;
  short colScale;
  short colNullable;
  UDWORD totalRows;
  int i;

  while (1)
    {
      /*
       *  Ask the user for a dynamic SQL statement
       */
      printf ("\nSQL>");
      if (fgets (request, sizeof (request), stdin) == NULL)
	break;

      request[strlen (request) - 1] = '\0';
      if (request[0] == '\0')
	continue;

      /*
       *  If the user just types tables, give him a list
       */
      if (!strcmp (request, "tables"))
	{
	  if (SQLTables (hstmt, NULL, SQL_NTS, NULL, SQL_NTS, NULL, SQL_NTS,
			 NULL, SQL_NTS) != SQL_SUCCESS)
	    {
	      DB_Errors ("SQLTables");
	      continue;
	    }
	}
      else if (!strcmp (request, "quit") || !strcmp (request, "exit"))
	break;			/* If you want to quit, just say so */
      else
	{
	  /*
	   *  Prepare & Execute the statement
	   */
	  if (SQLPrepare (hstmt, (UCHAR *) request, SQL_NTS) != SQL_SUCCESS)
	    {
	      DB_Errors ("SQLPrepare");
	      continue;
	    }
	  if (SQLExecute (hstmt) != SQL_SUCCESS)
	    {
	      DB_Errors ("SQLExec");
	      continue;
	    }
	}

      /*
       *  Get the number of result columns for this cursor.
       *  If it is 0, then the statement was probably a select
       */
      if (SQLNumResultCols (hstmt, &numCols) != SQL_SUCCESS)
	{
	  DB_Errors ("SQLNumResultCols");
	  goto endCursor;
	}
      if (numCols == 0)
	{
	  printf ("Statement executed.\n");
	  goto endCursor;
	}

      if (numCols > MAXCOLS)
	numCols = MAXCOLS;

      /*
       *  Get the names for the columns
       */
      for (colNum = 1; colNum <= numCols; colNum++)
	{
	  /*
	   *  Get the name and other type information
	   */
	  if (SQLDescribeCol (hstmt, colNum, (UCHAR *) colName,
			      sizeof (colName), NULL, &colType, &colPrecision,
			      &colScale, &colNullable) != SQL_SUCCESS)
	    {
	      DB_Errors ("SQLDescribeCol");
	      goto endCursor;
	    }

	  /*
	   *  Calculate the display width for the column
	   */
	  switch (colType)
	    {
	    case SQL_VARCHAR:
	    case SQL_CHAR:
	      displayWidth = (short) colPrecision;
	      break;
	    case SQL_BIT:
	      displayWidth = 1;
	      break;
	    case SQL_TINYINT:
	    case SQL_SMALLINT:
	    case SQL_INTEGER:
	      displayWidth = colPrecision + 1;	/* sign */
	      break;
	    case SQL_DOUBLE:
	    case SQL_DECIMAL:
	    case SQL_NUMERIC:
	    case SQL_FLOAT:
	      displayWidth = colPrecision + 2;	/* sign, comma */
	      break;
	    case SQL_DATE:
	    case SQL_TIME:
	    case SQL_TIMESTAMP:
	      displayWidth = colPrecision;
	      break;
	    default:
	      displayWidths[colNum - 1] = 0;	/* skip other data types */
	      continue;
	    }

	  if (displayWidth < strlen (colName))
	    displayWidth = strlen (colName);
	  if (displayWidth > sizeof (fetchBuffer) - 1)
	    displayWidth = sizeof (fetchBuffer) - 1;

	  displayWidths[colNum - 1] = displayWidth;

	  /*
	   *  Print header field
	   */
	  printf ("%-*.*s", displayWidth, displayWidth, colName);
	  if (colNum < numCols)
	    putchar ('|');
	}
      putchar ('\n');

      /*
       *  Print second line
       */
      for (colNum = 1; colNum <= numCols; colNum++)
	{
	  for (i = 0; i < displayWidths[colNum - 1]; i++)
	    putchar ('-');
	  if (colNum < numCols)
	    putchar ('+');
	}
      putchar ('\n');

      /*
       *  Print all the fields
       */
      totalRows = 0;
      while (1)
	{
	  int sts = SQLFetch (hstmt);

	  if (sts == SQL_NO_DATA_FOUND)
	    break;

	  if (sts != SQL_SUCCESS)
	    {
	      DB_Errors ("Fetch");
	      break;
	    }
	  for (colNum = 1; colNum <= numCols; colNum++)
	    {
	      /*
	       *  Fetch this column as character
	       */
	      if (SQLGetData (hstmt, colNum, SQL_CHAR, fetchBuffer,
			      sizeof (fetchBuffer),
			      &colIndicator) != SQL_SUCCESS)
		{
		  DB_Errors ("SQLGetData");
		  goto endCursor;
		}

	      /*
	       *  Show NULL fields as ****
	       */
	      if (colIndicator == SQL_NULL_DATA)
		{
		  for (i = 0; i < displayWidths[colNum - 1]; i++)
		    fetchBuffer[i] = '*';
		  fetchBuffer[i] = '\0';
		}

	      printf ("%-*.*s", displayWidths[colNum - 1],
		      displayWidths[colNum - 1], fetchBuffer);
	      if (colNum < numCols)
		putchar ('|');
	    }
	  putchar ('\n');
	  totalRows++;
	}

      printf (" %lu row(s) fetched.\n", totalRows);

    endCursor:
      SQLFreeStmt (hstmt, SQL_CLOSE);
    }

  return 0;
}


int
main (int argc, char **argv)
{
  puts ("OpenLink ODBC Demonstration program");
  puts ("This program shows an interactive SQL processor\n");


  /*
   *  If we can connect to this datasource, run the test program
   */
  if (DB_Connect (argv[1]) != 0)
    {
      DB_Errors ("DB_Connect");
    }

  else if (DB_Test () != 0)
    {
      DB_Errors ("DB_Test");
    }

  /*
   *  End the connection
   */
  DB_Disconnect ();

  puts ("\nHave a nice day.");

  return 0;
}
