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
# $Id: nosql.c,v 1.35 2005-03-09 15:15:12 mikeaubury Exp $
#*/

/**
 * @file
 *
 * Dummy module with empty implementations for sql functions without
 * specific SQL dinamic library built.
 */

 /*
    =====================================================================
    Includes
    =====================================================================
  */

#include "a4gl_lib_sql_int.h"
extern sqlca_struct a4gl_sqlca;
/*
=====================================================================
                    Variables definitions
=====================================================================
*/

char lasterrorstr[1024] = "";

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void A4GL_local_exitwith (char *s);
char *find_str_resource (char *s);
struct s_sid *find_prepare (char *pname);
extern char *A4GL_global_A4GLSQL_get_sqlerrm (void);	/* in API_sql.c */
int A4GLSQL_make_connection (char * server, char * uid_p,char * pwd_p);
int A4GLSQL_get_datatype (char *db, char *tab, char *col);
void * A4GLSQL_prepare_glob_sql_internal (char *s, int ni, void *ibind);
void * A4GLSQL_prepare_sql_internal (char *s);
int A4GLSQL_execute_sql_from_ptr_internal (char *pname, int ni, char *ibind);
int A4GLSQL_initsqllib (void);


/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 *
 * @todo Describe function
 */
void
A4GLSQL_xset_status (int a)
{
  A4GLSQL_set_status (a, 0);
}

/**
 *
 * @todo Describe function
 */
void
A4GLSQL_set_status (int a, int sql)
{
  a4gl_status = a;
  if (sql)
    a4gl_sqlca.sqlcode = a;
  A4GL_debug ("Status set to %d", a);
}

/**
 *
 * @todo Describe function
 */
int
A4GLSQL_init_connection_internal (char *dbName)
{
  A4GL_debug ("Connection with database not available: A4GL_SQLTYPE=nosql");
  A4GL_local_exitwith
    ("Could not init_connection - Connection with database not available: A4GL_SQLTYPE=nosql");
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
A4GLSQL_get_status (void)
{
  return a4gl_sqlca.sqlcode;
}

/**
 *
 * @todo Describe function
 */
char *
A4GLSQL_get_sqlerrm (void)
{
  return A4GL_global_A4GLSQL_get_sqlerrm ();
}

/**
 *
 * @todo Describe function
 */
int
A4GLSQL_read_columns (char *tabname, char *colname, int *dtype, int *size)
{
  A4GL_local_exitwith ("Could not read_columns - noODBC build");
  return 0;

}

/**
 *
 * @todo Describe function
 */
int A4GLSQL_make_connection (char * server, char * uid_p,char * pwd_p)
{
  /*
     A4GL_local_exitwith ("Could not make ODBC connection - noODBC build");
     FIXME: do we want to show some message here????

     FIXME: programs that do not use DATBASE or CONNECT or SESSION,
     should not call this function, but they DO!
   */

  return 0;
}

/**
 *
 * @todo Describe function
 */
int A4GLSQL_get_datatype (char *db, char *tab, char *col)
{
  A4GL_local_exitwith ("Could not get_datatype - noODBC build");
  return 0;
}

/*
===================================================================
functions required to create executable from 4gl code that uses SQL
===================================================================
*/

/**
 *
 * @todo Describe function
 */
int
A4GLSQL_init_session_internal (char *sessname, char *dsn, char *usr, char *pwd)
{
  A4GL_local_exitwith ("Could not init_session - noODBC build");
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
A4GLSQL_set_conn_internal (char *sessname)
{
  A4GL_local_exitwith ("Could not set_session - noODBC build");
  return 0;
}

/**
 *
 * @todo Describe function
 */
void * A4GLSQL_prepare_glob_sql_internal (char *s, int ni, void *ibind)
{
  A4GL_local_exitwith ("Could not prepare_global_sql - noODBC build");
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
A4GLSQL_execute_implicit_sql (void *sid,int singleton)
{
  A4GL_local_exitwith ("Could not execute_implicit_sql - noODBC build");
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
A4GLSQL_close_session_internal (char *sessname)
{
  A4GL_local_exitwith ("Could not close_session - noODBC build");
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
A4GLSQL_fill_array (int mx, char *arr1, int szarr1, char *arr2, int szarr2,
		    char *service, int mode, char *info)
{
  A4GL_local_exitwith ("Could not fill_array - noODBC build");
  return 0;
}

/**
 *
 * @todo Describe function
 */
void * A4GLSQL_prepare_sql_internal (char *s)
{
  A4GL_local_exitwith ("Could not prepare_sql - noODBC build");
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
A4GLSQL_add_prepare (char *pname, void *sid)
{
  A4GL_local_exitwith ("Could not add_prepare - noODBC build");
  return 0;
}

/**
 *
 * @todo Describe function
 */
int A4GLSQL_execute_sql_from_ptr_internal (char *pname, int ni, char *ibind)
{
  A4GL_local_exitwith ("Could not execute_sql_from_ptr - noODBC build");
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
A4GLSQL_execute_implicit_select (void *sid,int singleton)
{
  A4GL_local_exitwith ("Could not execute_implicit_select - noODBC build");
  return 0;
}

/**
 *
 * @todo Describe function
 */
void *
A4GLSQL_prepare_select_internal (void *ibind, int ni, void *obind,
			int no, char *s)
{
  A4GL_local_exitwith ("Could not prepare_select - noODBC build");
  return 0;
}

/**
 *
 * @todo Describe function
 */
void *
A4GLSQL_declare_cursor (int upd_hold, void *sid, int scroll,
			char *cursname)
{
  A4GL_local_exitwith ("Could not declare_cursor - noODBC build");
  return 0;
}

/**
 *
 * @todo Describe function
 */
void
A4GLSQL_set_sqlca_sqlcode (int a)
{
  a4gl_status = a;
  a4gl_sqlca.sqlcode = a;
}

/**
 *
 * @todo Describe function
 */
int
A4GLSQL_open_cursor (char *s,int ni,void *ibind)
{
  A4GL_local_exitwith ("Could not open_cursor - noODBC build");
  return 0;
}

/**
 *
 * @todo Describe function
 */
int
A4GLSQL_fetch_cursor (char *cursor_name,
		      int fetch_mode, int fetch_when, int nibind,
		      void *ibind)
{
  A4GL_local_exitwith ("Could not fetch_cursor - noODBC build");
  return 0;
}

/**
 *
 * @todo Describe function
 */
void
A4GLSQL_put_insert (void *ibind, int n)
{
  A4GL_local_exitwith ("Could not put_insert - noODBC build");
}

/**
 *
 * @todo Describe function
 */
void
A4GLSQL_unload_data_internal (char *fname, char *delims, char *sql1,int nbind,void *ibind)
{
  A4GL_local_exitwith ("Could not unload_data - noODBC build");
}

/**
 *
 * @todo Describe function
 */
void
A4GLSQL_commit_rollback (int mode)
{
  A4GL_local_exitwith ("Could not commit_rollback - noODBC build");
}

/**
 *
 * @todo Describe function
 */
void *
A4GLSQL_find_prepare (char *pname)
{
  A4GL_local_exitwith ("Could not find_prepare - noODBC build");
  return 0;
}

/**
 *
 * @todo Describe function
 */
void
A4GLSQL_flush_cursor (char *cursor)
{
  A4GL_local_exitwith ("Could not flush_cursor - noODBC build");
}

/**
 *
 * @todo Describe function
 */
int
A4GLSQL_execute_sql (char *pname, int ni, void *ibind)
{
  A4GL_local_exitwith ("Could not execute_sql - noODBC build");
  return 0;
}

/**
 *
 * @todo Describe function
 */
int A4GLSQL_initsqllib (void)
{
  return 1;
}

/**
 *
 * @todo Describe function
 */
void
A4GL_local_exitwith (char *s)
{
#ifdef DEBUG
  {
    A4GL_debug ("ending because : %s", s);
  }
#endif
  printf ("\n\n\n");
  exit (1);

}

void *A4GLSQL_get_validation_expr(char *tabname,char *colname) {
return 0;
}

char *A4GLSQL_syscolval_expr(char *tabname,char *colname,char *typ) {
return 0;
}


/* =============================== EOF ============================== */
