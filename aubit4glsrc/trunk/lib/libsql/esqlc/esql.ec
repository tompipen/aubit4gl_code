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
# $Id: esql.ec,v 1.4 2002-02-19 09:18:34 afalout Exp $
#
*/

/*
since on Windows only ESQL/C supported compiler is Visual C++,
we must be carefull not to include anything that will conflict with
MSVC here, since resulting .c need to be compiled and linked by MSVC
*/

#ifdef xxxblah_WIN32

	//in sqltypes.h:
	//typedef PVOID HSTMT;


	#ifndef FAR
	#define FAR
	#endif


	//only Informix .h fire to mention HSTMT at all is sqlucode.h
	//this definitions are taken from sqltypes.h from iODBC
	typedef void FAR *		HSTMT;
	typedef signed short 		SWORD;

	//from sql.c:
	int rc;

#endif

#define DEFINE_SQLCA


//#ifndef WIN32
//#include "incl/esql/sqlca.h"
//#else
//#include "headers/sql.h"
//ext, types, ucode
//#endif


#ifndef WIN32
	#include <stdio.h>
	#include <string.h>
	//#include "libincl/debug.h"
	#include "libincl/database.h"
	//#include "libincl/stack.h"
	#include "libincl/pointers.h"
	#include "libincl/dtypes.h"
	#include <stdlib.h>
#else
//	#include </progra~1/DevStudio/VC/include/stdio.h>
	#include <stdio.h>
	#include <windows.h>
    int status;
	#include "libincl/pointers.h"
	#include "libincl/dtypes.h"
	#include "libincl/database.h"
/*
		#ifndef PAN32
			#define PAN32
			#include <panel32.h>
		#endif
*/

#endif



//EXEC SQL include ..\..\libincl\sqlca.h;
EXEC SQL include sqlca.h;
//sqlda.h from Plexus?? there is no sqlds.h on Windows esql/c
//also no sqliapi.h on Windows
EXEC SQL include sqlda;


long pcnt=0;

#ifndef WIN32
	#include <stdarg.h>
#else
    #define _NO_FORM_H_
    #define _NO_CURSES_H_
	#define _NO_PANEL_H_
	#define _NO_CURSLIB_H_
	#define FORMXW //form_x.h
    #define _NO_DBFORM_H_
#endif
	// stack.h will eventually include stdlib.h, which uses getenv(), so
	// we need to set GETENV_OK and only then include debug.h
	#include "libincl/stack.h"
	#define GETENV_OK
	#include "libincl/debug.h"
//#endif



//extern sqlca_struct sqlca;
//extern long status;

char *find_str_resource (char *s);
typedef unsigned char UCHAR;

struct s_sid *find_prepare (char *pname, int mode);
char *acl_getenv (char *s);
void A4GLSQL_set_status (int a, int sql);
char lasterrorstr[1024] = "";


void
A4GLSQL_initlib ()
{
  /* Does nothing */
}


/*
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
*/

int
A4GLSQL_init_connection (char *dbName)
{
$char b[256];
strcpy(b,dbName);
$database $b;
 
}

/*
int
A4GLSQL_get_status ()
{
  return sqlca.sqlcode;
}

*/
char *
A4GLSQL_get_sqlerrm ()
{
	return global_A4GLSQL_get_sqlerrm ();
	//return sqlca.sqlerrm;
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
//$char stmt[64];
$char stmt[256];
struct sqlda *udesc;
struct sqlvar_struct *col;
int tmp;

  if (sid == 0)
    {
#ifdef DEBUG
/* {DEBUG} */
      {
        debug ("Warning .... Can't execute non-prepared statement");
      }
#endif
      return 0;
    }

    /*
	incllib/database.h :
		struct s_sid {
			struct BINDING *ibind;
			struct BINDING *obind;
			int ni;
			int no;
			char *select;
			void *hstmt;  <<<<<<<<<<<<<<<<<<
		};
    */


    #ifndef WIN32
		//esql.ec(389) : error C2371: 'get_uniqname_xx1' : redefinition; different basic types
		strcpy(stmt,get_uniqname_xx1(sid->hstmt));
		/*
		tmp=sid->hstmt;
		strcpy(stmt,get_uniqname_xx1(tmp));
	    */
    #else
		exitwith ("Could not get_uniqname - see bug in esql.ec");
	#endif

  EXEC SQL describe  $stmt into udesc;

	#ifndef WIN32
		//in sql.c: int proc_bind (struct BINDING *b, int n, char t, HSTMT hstmt)
        //so how the hell do I call it from here? this function(s) need to be
        //moved of dlsql.c if they are to used form somewhere else then ODBC
        //dll
		proc_bind (sid->obind, sid->no, 'o', sid->hstmt);
		proc_bind (sid->ibind, sid->ni, 'i', sid->hstmt);
    #else
		exitwith ("Could not proc_bind - function is in wrong object - see in esql.ec");
	#endif

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
A4GLSQL_prepare_select (struct BINDING *ibind, int ni, struct BINDING *obind, int no, char *s)
{
$char b[64];
$char *sql;
  struct s_sid *sid;  
  sid = malloc (sizeof (struct s_sid));
  sql=strdup(s);
  sid->select =sql;
  sid->ibind = ibind;
  debug ("sid->ni=%d", ni);
  sid->ni = ni;
  sid->obind = obind;
  sid->no = no;
  A4GLSQL_set_status (0, 1);
  
    #ifndef WIN32
		strcpy(b,get_uname());
    #else
		exitwith ("Could not get_uname - where is this defined? See esql.ec");
    #endif

  sid->hstmt=pcnt;
  EXEC SQL prepare $b from :sql;
}


struct s_cid *
A4GLSQL_declare_cursor (int upd_hold, struct s_sid *sid, int scroll,
			char *cursname)
{
  exitwith ("Could not declare_cursor - noODBC build");
}

/*
int A4GLSQL_set_sqlca_sqlcode (int a)
{
  status = a;
  sqlca.sqlcode = a;
}
*/

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

//---------------------------- EOF ------------------------------


char *get_uniqname() {
	pcnt++;

    #ifndef WIN32
		return  get_uniqname_xx1(pcnt);
    #else
		exitwith ("Could not get_uniqname - see bug in esql.ec");
    #endif

}


char *get_uniqname_xx1(int a) {
	static char buff[256];
	sprintf(buff,"a4glx_%d",a);
	return buff;
    return "";
}
