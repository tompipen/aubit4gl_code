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
# $Id: nosql.c,v 1.7 2002-01-24 06:37:18 afalout Exp $
#
*/

#ifdef __CYGWIN__
	#define DEFINE_SQLCA
	#define DEFINE_STATUS
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libincl/debug.h"
#include "libincl/database.h"
#include "libincl/stack.h"
#include "libincl/pointers.h"
#include "libincl/dtypes.h"

#include <stdarg.h>
#include "libincl/dtypes.h"

extern sqlca_struct sqlca;

//#ifndef __CYGWIN__
extern long status;
//#endif

char *find_str_resource (char *s);
typedef unsigned char UCHAR;

struct s_sid *find_prepare (char *pname, int mode);
void A4GLSQL_set_status (int a, int sql);
char lasterrorstr[1024] = "";

/*
void
A4GLSQL_initlib ()
{
  // Does nothing
}
*/
void
A4GLSQL_xset_status (int a)
{
  A4GLSQL_set_status (a, 0);
}

void
A4GLSQL_set_status (int a, int sql)
{

  status = a;
  if (sql)
    sqlca.sqlcode = a;
  debug ("Status set to %d", a);
}


int
A4GLSQL_init_connection (char *dbName)
{
  debug("Connection with database not available: A4GL_SQLTYPE=nosql");
  exitwith ("Could not init_connection - Connection with database not available: A4GL_SQLTYPE=nosql");
}


int
A4GLSQL_get_status ()
{
  return sqlca.sqlcode;
}


char *
A4GLSQL_get_sqlerrm ()
{
  return sqlca.sqlerrm;
}


int
A4GLSQL_read_columns (char *tabname, char *colname, int *dtype, int *size)
{
  exitwith ("Could not read_columns - noODBC build");

}



int
A4GLSQL_make_connection (UCHAR * server, UCHAR * uid_p, UCHAR * pwd_p)
{
  //exitwith ("Could not make ODBC connection - noODBC build");
  //FIXME: do we want to show some message here????

  //FIXME: programs that do not use DATBASE or CONNECT or SESSION,
  //should not call this function, but they DO!

  return 0;
}


int A4GLSQL_get_datatype (char *db, char *tab, char *col)
{

  exitwith ("Could not get_datatype - noODBC build");
}



/*
===================================================================
functions required to create executable from 4gl code that uses SQL
===================================================================
*/



int A4GLSQL_init_session (char *sessname, char *dsn, char *usr, char *pwd)
{
  exitwith ("Could not init_session - noODBC build");
}



int A4GLSQL_set_conn (char *sessname)
{
  exitwith ("Could not set_session - noODBC build");
}



struct s_sid *
A4GLSQL_prepare_glob_sql (char *s, int ni, struct BINDING *ibind)
{
  exitwith ("Could not prepare_global_sql - noODBC build");
}

int
A4GLSQL_execute_implicit_sql (struct s_sid *sid)
{
  exitwith ("Could not execute_implicit_sql - noODBC build");
}

int A4GLSQL_close_session (char *sessname)
{
  exitwith ("Could not close_session - noODBC build");
}


int
A4GLSQL_fill_array (int mx, char **arr1, int szarr1, char **arr2, int szarr2,
		    char *service, int mode, char *info)
{
  exitwith ("Could not fill_array - noODBC build");
}



struct s_sid *
A4GLSQL_prepare_sql (char *s)
{
  exitwith ("Could not prepare_sql - noODBC build");
}


int
A4GLSQL_add_prepare (char *pname, struct s_sid *sid)
{
  exitwith ("Could not add_prepare - noODBC build");
}


int A4GLSQL_execute_sql_from_ptr (char *pname, int ni, char **ibind)
{
  exitwith ("Could not execute_sql_from_ptr - noODBC build");
}


int
A4GLSQL_execute_implicit_select (struct s_sid *sid)
{
  exitwith ("Could not execute_implicit_select - noODBC build");
}


struct s_sid *
A4GLSQL_prepare_select (struct BINDING *ibind, int ni, struct BINDING *obind,
			int no, char *s)
{
  exitwith ("Could not prepare_select - noODBC build");
}


struct s_cid *
A4GLSQL_declare_cursor (int upd_hold, struct s_sid *sid, int scroll,
			char *cursname)
{
  exitwith ("Could not declare_cursor - noODBC build");
}


int A4GLSQL_set_sqlca_sqlcode (int a)
{
  status = a;
  sqlca.sqlcode = a;
}


int
A4GLSQL_open_cursor (int ni, char *s)
{
  exitwith ("Could not open_cursor - noODBC build");
}


int
A4GLSQL_fetch_cursor (char *cursor_name,
		      int fetch_mode, int fetch_when, int nibind,
		      struct BINDING *ibind)
{
  exitwith ("Could not fetch_cursor - noODBC build");
}


int A4GLSQL_put_insert (struct BINDING *ibind, int n)
{
  exitwith ("Could not put_insert - noODBC build");
}

int A4GLSQL_unload_data (char *fname, char *delims, char *sql1)
{
  exitwith ("Could not unload_data - noODBC build");
}


int A4GLSQL_commit_rollback (int mode)
{
  exitwith ("Could not commit_rollback - noODBC build");
}

struct s_sid *
A4GLSQL_find_prepare (char *pname, int mode)
{
  exitwith ("Could not find_prepare - noODBC build");
}

int A4GLSQL_flush_cursor (char *cursor)
{
  exitwith ("Could not flush_cursor - noODBC build");
}

int
A4GLSQL_execute_sql (char *pname, int ni, struct BINDING *ibind)
{
  exitwith ("Could not execute_sql - noODBC build");
}


int A4GLSQL_initsqllib()
{
// Does nothing - it doesn't need to..
return 1;
}
//---------------------------- EOF ------------------------------
