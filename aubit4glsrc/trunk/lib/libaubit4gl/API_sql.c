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
# $Id: API_sql.c,v 1.19 2002-08-31 06:19:59 afalout Exp $
#
*/

/**
 * @file
 * Dynamic libraries usage of sql functions.
 *
 * The program is controled by the environment in order to load diferent
 * libraries to establish the database connection.
 *
 * This is the begining of the SQL driver manager.
 *
 * @todo Does this file belong in lib/ directory, or?
 *
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/


#include "a4gl_libaubit4gl_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

static void *libptr=0;
/* typedef unsigned char UCHAR; in a4gl_dlsql.h */

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

static int 	(*func)					();
/* void *		find_func				(void *p,char *s); in calldll.c */
/* int         A4GLSQL_initlib 		(void); */
/* void        A4GLSQL_xset_status(	int a); */
/* int         A4GLSQL_init_connection (char *dbName); */
/* int         A4GLSQL_get_status   	(void); */
/* int         A4GLSQL_get_curr_conn   (void); */
/* int         A4GLSQL_get_sqlerrm   	(void); */
/*int         A4GLSQL_get_columns 	(char *tabname, char *colname,
									int *dtype, int *size); */
/* int         A4GLSQL_next_column		(char **colname, int *dtype,int *size); */
/*int         A4GLSQL_end_get_columns	(void); */
/* int         A4GLSQL_read_columns   	(char *tabname,char *colname,
									int *dtype, int *size); */
/*int         A4GLSQL_make_connection (UCHAR * server, UCHAR * uid_p,
									UCHAR * pwd_p); */
/* int         A4GLSQL_get_datatype   	(char *db, char *tab, char *col); */
/* int         A4GLSQL_init_session   	(char *sessname, char *dsn, char *usr,
									char *pwd); */
/* int         A4GLSQL_set_conn   		(char *sessname); */
/* int         A4GLSQL_prepare_glob_sql(char *s, int ni, struct BINDING *ibind); */
/*int         A4GLSQL_execute_implicit_sql   (struct s_sid *sid); */
/* int         A4GLSQL_close_session   (char *sessname); */
/* int         A4GLSQL_fill_array     	(int mx, char **arr1, int szarr1,
									char **arr2, int szarr2, char *service,
									int mode, char *info  ); */
/* int         A4GLSQL_prepare_sql   	(char *s); */
/* int         A4GLSQL_add_prepare   	(char *pname, struct s_sid *sid); */
/* int         A4GLSQL_execute_sql_from_ptr (char *pname, int ni, char **ibind); */
/*int         A4GLSQL_execute_sql   	(char *pname, int ni,
									struct BINDING *ibind); */
/* int         A4GLSQL_execute_implicit_select (struct s_sid *sid); */
/*int         A4GLSQL_prepare_select  (struct BINDING *ibind, int ni,
									struct BINDING *obind, int no, char *s); */
/*int         A4GLSQL_declare_cursor  (int upd_hold, struct s_sid *sid,
									int scroll, char *cursname ); */
/* int         A4GLSQL_set_sqlca_sqlcode (int a); */
/*int         A4GLSQL_open_cursor   	(int ni, char *s); */
/*int         A4GLSQL_fetch_cursor   	(char *cursor_name, int fetch_mode,
									int fetch_when,
									int nibind, struct BINDING *ibind); */
/* int         A4GLSQL_put_insert   	(struct BINDING *ibind, int n); */
/* int         A4GLSQL_unload_data   	(char *fname, char *delims, char *sql1); */
/*int         A4GLSQL_commit_rollback (int mode); */
/* int         A4GLSQL_find_prepare   	(char *pname, int mode); */
/* int         A4GLSQL_flush_cursor   	(char *cursor); */
/*char *      A4GLSQL_get_currdbname  (char *cursor); */
/* long        A4GLSQL_describe_stmt 	(char *stmt, int colno, int type); */
/* long        A4GLSQL_initsqllib		(void); */
char *      global_A4GLSQL_get_sqlerrm (void);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/



/**
 * Loads SQL library from .so file.
 *
 * The opening of the library is made by dl_openlibrary() and based on
 * the environment variable A4GL_SQLTYPE.
 *
 * @return - 0 : Impossible to open the dynamic SQL library
 *         - 1 : Opened the library but not found the init function
 *         - otherwise : The pointer to A4GLSQL_initlib from library loaded
 */
int
A4GLSQL_initlib (void)
{
	libptr=(void *)dl_openlibrary("SQL",acl_getenv("A4GL_SQLTYPE"));
	debug("libptr=%p\n",libptr);
	if (libptr==0) {
		exitwith("Unable to open SQL library.");
		return 0;
	}
	func=find_func_allow_missing(libptr,"A4GLSQL_initlib");

	if (func)
		return func();
	else
		return 1;
}

/**
 * Assign a value to the status internal 4gl variable.
 *
 * @param a The value to assign to status.
 * @param sql A flag that indicate if the sqlca.sqlcode should be assigned.
 *   - 0 : Not SQL
 *   - Otherwise : SQL
 */
void
A4GLSQL_set_status (int a, int sql)
{
  debug("A4GLSQL_set_status");

  status = a;
  if (sql)
    sqlca.sqlcode = a;
  debug ("Status set to %d", a);
}


/**
 *
 *
 * @param
 * @return
 */
void
A4GLSQL_xset_status(int a)
{
	debug("A4GLSQL_xset_status");
        A4GLSQL_set_status(a,0);
}

/**
 * Initialize a connection to the database.
 *
 * Called by the generated C code to implement the DATABASE 4gl statement.
 *
 * @param dbName The database name.
 * @return
 */
int
A4GLSQL_init_connection   (char *dbName)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_init_connection");
  return func(dbName);
}


/**
 * Get the value of the 4gl status variable.
 *
 * @return The status value.
 */
int
A4GLSQL_get_status   (void)
{
	debug("Status=%d sqlca.sqlcode=%d",status,sqlca.sqlcode);

	if (status==0&&sqlca.sqlcode<0) status=sqlca.sqlcode;

	return status ;
}

/**
 * Gets the current connection.
 *
 * Call the loaded function from the SQL dll.
 *
 * @return The current connection.
 */
/* int -- char * in sql.c */
char *
A4GLSQL_get_curr_conn   (void)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_get_curr_conn");
  return (char *)func();
}

/**
 * Get the error message returned by the database engine.
 *
 * Calls the loaded function from dl.
 *
 * @return
 */
/* int --- char * in sql.c */
char *
A4GLSQL_get_sqlerrm   (void)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_get_sqlerrm");
  return (char *)func();
}

/**
 * Start getting information about all columns from a table in the database 
 * engine.
 *
 * This is used to declare record like table.*
 *
 * @param tabname The table that we wish to get information about it.
 * @param colname The column name to get information about it.
 * @param dtype A pointer to the variable where to put the data type.
 * @param size A pointer to the variable where to put the size of the column
 *  returned by the database.
 * @return 
 *   - 1 : Information readed.
 *   - 0 : Error ocurred.
 */
int
A4GLSQL_get_columns (char *tabname, char *colname, int *dtype, int *size)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_get_columns");
  return func(tabname,colname,dtype,size);
}


/**
 * Iterate in getting information about all columns from a table from the 
 * database engine.
 *
 * A4GLSQL_get_columns(char *tabname) should be called before this one.
 *
 * This is used to declare record like table.*
 *
 * @param colname The place where to put the column name
 * @param dtype A pointer to the variable where to put the data type.
 * @param size A pointer to the variable where to put the size of the column
 *  returned by the database.
 * @return
 *   - 1 : Information readed.
 *   - 0 : Error ocurred.
 */
int
A4GLSQL_next_column(char **colname, int *dtype,int *size)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_next_column");
  return func(colname,dtype,size);
}

/**
 * Free all resources allocated in getting information about columns
 * 
 * @return 
 *   - 0 : Descriptor dealocated
 *   - 1 : Error ocurred.
 */
int
A4GLSQL_end_get_columns(void)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_end_get_columns");
  return func();
}


/**
 * Gets information about columns from a table in the database engine.
 *
 * @param tabname The table that we wish to get information about it.
 * @param colname The column name to get information about it.
 * @param dtype A pointer to the variable where to put the data type.
 * @param size A pointer to the variable where to put the size of the column
 *  returned by the database.
 * @return 
 *   - 1 : Information readed.
 *   - 0 : Error ocurred.
 */
int
A4GLSQL_read_columns   (char *tabname, char *colname, int *dtype, int *size)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_read_columns");
  return func(tabname,colname,dtype,size);
}

/**
 * Make a connection to the database engine.
 *
 * @param server The database server.
 * @param uid_p User identification (login in the database).
 * @param pwd_p Password to create the connection.
 * @return 
 */
int
A4GLSQL_make_connection   (UCHAR * server, UCHAR * uid_p, UCHAR * pwd_p)  {
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_make_connection");
  return func(server,uid_p,pwd_p);
}


/**
 * Gets the datatype of a column from a table in a database.
 *
 * @param db The database name.
 * @param tab The table name.
 * @param col The column name.
 * @return
 */
int
A4GLSQL_get_datatype   (char *db, char *tab, char *col)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_get_datatype");
  return func(db,tab,col);
}


/**
 * Init a new connection to the database and associate with an explicit 
 * session name.
 *
 * @param sessname The name to be tied to the session.
 * @param dsn The data source name.
 * @param usr The user name to establish the connection.
 * @param pwd The password of the user to set the connection.
 */
int
A4GLSQL_init_session   (char *sessname, char *dsn, char *usr, char *pwd)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_init_session");
  return func(sessname,dsn,usr,pwd);
}

/**
 * Sets the connection to use in the execution of the next SQL statement.
 *
 * @param sessname The session name.
 */
int
A4GLSQL_set_conn   (char *sessname)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_set_conn");
  return func(sessname);
}


/**
 * Prepare a global SQL statement (not named).
 *
 * @param s A string with the SQL statement.
 * @param ni The number of input bind elements.
 * @param ibind A pointer to the input bind array.
 * @return A statement identification structure pointer.
 */
/* int -- struct s_sid * in sql.c */
struct s_sid *
A4GLSQL_prepare_glob_sql   (char *s, int ni, struct BINDING *ibind)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_prepare_glob_sql");
  return (struct s_sid *)func(s,ni,ibind);
}


/**
 * Execute an sql statement where the its execution is implicit in 4gl.
 *
 * @param sid The statement identification.
 * @return
 *  - 0 : Statement executed.
 *  - 1 : An error as ocurred.
 */
int
A4GLSQL_execute_implicit_sql   (struct s_sid *sid)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_execute_implicit_sql");
  return func(sid);
}


/**
 * Close a named connection.
 *
 * @param sessname The session/connection name.
 * @return
 *  - 0 : Connection closed.
 *  - 1 : Connection does not exist or error ocurred.
 */
int
A4GLSQL_close_session   (char *sessname)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_close_session");
  return func(sessname);
}

/**
 * Close a cursor opened.
 *
 * @param currname The name of the cursor.
 * @return
 */
int
A4GLSQL_close_cursor   (char *currname)  
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_close_cursor");
  return func(currname);
}


/**
 *
 *
 * @param
 * @return
 */
int
A4GLSQL_fill_array     (int mx, char **arr1, int szarr1, char **arr2,
						int szarr2, char *service, int mode, char *info)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_fill_array");
  return func(mx,arr1,szarr1,arr2,szarr2,service,mode,info);
}


/**
 * Prepare an sql statement.
 *
 * @param s a string with the statement to be prepared.
 * @return
 */
/* int --- struct s_sid * in sql.c */
struct s_sid *
A4GLSQL_prepare_sql   (char *s)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_prepare_sql");
  return (struct s_sid *)func(s);
}


/**
 * Store the information of a prepared statement in a global data structure.
 *
 * @param pname The prepare statement name.
 * @param sid A pointer to the statement information.
 * @return Allways 0
 */
int
A4GLSQL_add_prepare   (char *pname, struct s_sid *sid)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_add_prepare");
  return func(pname,sid);
}


/**
 * Used from load.c
 *
 * @param prepared statement name.
 * @param ni Number of binded input parameters.
 * @param The input bind array.
 * @return Allways 0
 */
int
A4GLSQL_execute_sql_from_ptr   (char *pname, int ni, char **ibind)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_execute_sql_from_ptr");
  return func(pname,ni,*ibind);
}


/**
 * Execute an implicit select instruction.
 *
 * Used when the SELECT is a direct SELECT INTO in 4gl code.
 *
 * @param sid The statement information.
 * @return
 *  - 0 : Connection closed.
 *  - 1 : Connection does not exist or error ocurred.
 *  - -1 : The pointer to the statement is null.
 */
int
A4GLSQL_execute_implicit_select   (struct s_sid *sid)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_execute_implicit_select");
  return func(sid);
}


/**
 * Prepare a select statement.
 *
 * @param ibind The input bind array.
 * @param ni Number of elements in the input bind array.
 * @param obind The output bind array.
 * @param no The number of elements in the output bind array.
 * @param s A string containing the select statement.
 * @return A pointer to the statement identification structure.
 */
/* int -- struct s_sid * in sql.c */
struct s_sid *
A4GLSQL_prepare_select       (struct BINDING *ibind, int ni, struct BINDING *obind, int no, char *s    )
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_prepare_select");
  return (struct s_sid *)func(ibind,ni,obind,no,s);
}

/**
 * Declare a cursor.
 *
 * @param upd_hold Indicate if the cursor is for update or with hold.
 * @param sid Select statement to use with the cursor.
 * @param scroll Indicate if is a scrolling cursor:
 *   - 0 : Do not have scroll
 *   - 1 : The cursor have scroll
 * @param cursname The cursor name.
 */
/* int -- struct s_cid * in sql.c */
struct s_cid *
A4GLSQL_declare_cursor    (int upd_hold, struct s_sid *sid, int scroll, char *cursname )
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_declare_cursor");
  return (struct s_cid *)func(upd_hold,sid,scroll,cursname);
}

/**
 * Assign a value to sqlca.sqlcode.
 *
 * @param a The value to be assigned.
 */
/* int -- void in sql.c */
void
A4GLSQL_set_sqlca_sqlcode   (int a)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_set_sqlca_sqlcode");
  func(a);
}

/**
 * Open a cursor.
 *
 * @todo : Check the type diference between the generated code and the function
 * declaration.
 *
 * @param ni
 * @param s The cursor name.
 */
int
A4GLSQL_open_cursor   (int ni, char *s)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_open_cursor");
  return func(ni,s);
}

/**
 * Fetch a cursor to variables.
 *
 * @param cursor_name The name of the cursor in 4gl.
 * @param fetchmode
 *   : FETCH_RELATIVE
 * @param fetch_when The amount of rows to advance acordingto the fetch type.
 * @param nibind
 * @param ibind
 * @return
 */
int
A4GLSQL_fetch_cursor   (char *cursor_name, int fetch_mode, int fetch_when,
  int nibind, struct BINDING *ibind)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_fetch_cursor");
  return func(cursor_name,fetch_mode,fetch_when,nibind,ibind);
}


/**
 * Put the information in an insert cursor.
 *
 *
 * @param ibind The bind array
 * @param n The number of elements in the bind array.
 * @return
 *   - 1 : Data inserted in the cursor.
 *   - 0 : An error as ocurred.
 */
/* int -- void in sql.c !!! */
void
A4GLSQL_put_insert   (struct BINDING *ibind, int n)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_put_insert");
  func(ibind,n);
}


/**
 *
 *
 * @param
 * @return
 */
/* int -- void in sql;.c */
void
A4GLSQL_unload_data   (char *fname, char *delims, char *sql1)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_unload_data");
  func(fname,delims,sql1);
}


/**
 * Execute a transaction instruction (begin, commit, rollback).
 *
 * @param mode The transaction statement to be called:
 *  - -1 : Begin work.
 *  - 0 : Rollback work.
 *  - 1 : Commit work.
 * @return
 */
/* int -- void in sql.c !! */
void
A4GLSQL_commit_rollback   (int mode)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_commit_rollback");
  func(mode);
}

/**
 * Prepare a select statement.
 *
 * @todo : Fix the call to this functionin generated code with less parameters.
 *
 * @param pname
 * @param mode
 */
/* int --- struct s_sid * in sql.c */
struct s_sid *
A4GLSQL_find_prepare   (char *pname)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_find_prepare");
  return (struct s_sid *)func(pname);
}

/**
 * FLUSH CURSOR 4gl statement implementation.
 *
 * Flush the rows in an insert cursor into the database.
 *
 * @param The cursor name.
 * @return 
 *  - 0 : Instruction executed.
 *  - 1 : An error as ocurred.
 */
/* int---void in sql.c !!! */
void
A4GLSQL_flush_cursor   (char *cursor)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_flush_cursor");
  func(cursor);
}

/**
 *
 *
 * @param
 * @return
 */
char *
/* A4GLSQL_get_currdbname   (char *cursor) -- void in sql.c !!! */
A4GLSQL_get_currdbname   (void)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_get_currdbname");
  /* return (char *)func(cursor); */
  return (char *)func();
}


/**
 * Execute an SQL statement.
 *
 * @param pname  The prepared statement name.
 * @param ni Number of elements in the input bind.
 * @param ibind The input binding array used.
 * @return
 */
int
A4GLSQL_execute_sql   (char *pname, int ni, struct BINDING *ibind)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_execute_sql");
  return func(pname,ni,ibind);
}


/**
 *
 *
 * @param
 * @return
 */
long
A4GLSQL_describe_stmt (char *stmt, int colno, int type)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_describe_stmt");
  return func(stmt,colno,type);

}


/**
 * Called by the 4gl starting function, analyse the resources in order
 * to decide wich dynamic library it uses to establish the connection to the 
 * database.
 *
 * @return The pointer to the function loaded.
 */
/* long --- int in sql.c ! */
int
A4GLSQL_initsqllib(void)
{
  if (libptr==0) A4GLSQL_initlib();
  func=find_func(libptr,"A4GLSQL_initsqllib");
  if (func) return func();
  else return 1;
}


/* moved here from nosql.c/sql.c to work around prblem with automatic exporting
of globals when making windows .dll
*/
/**
 *
 *
 * @param
 * @return
 */
char *
global_A4GLSQL_get_sqlerrm (void)
{
	return sqlca.sqlerrm;
}


/* =============================== EOF ============================== */
