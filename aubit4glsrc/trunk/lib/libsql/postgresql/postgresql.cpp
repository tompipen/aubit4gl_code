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
# $Id: postgresql.cpp,v 1.5 2003-01-15 11:43:33 afalout Exp $
#
*/

/**
 * @file
 *
 * Implementation of the direct connection of aubit 4gl to postgresql database
 * using the libpq postgresql access library.
 *
 *
 */

#define DEFINE_SQLCA

#ifdef WIN32
	#define _NO_FORM_H_
	#define _NO_CURSES_H_
	#define _NO_PANEL_H_
	#define _NO_CURSLIB_H_
	#define FORMXW //form_x.h
	#define _NO_DBFORM_H_
#endif



 /*
=====================================================================
		                    Includes
=====================================================================
*/


  #include <stdio.h>
  #include "a4gl_incl_4gldef.h"
  #include "a4gl_API_sql.h"

#if HAVE_POSTGRESQL_LIBPQ_FE_H
	#include <postgresql/libpq-fe.h>
#else
	#if HAVE_PGSQL_LIBPQ_FE_H
		#include <pgsql/libpq-fe.h>
	#else
		#define libpq(s)	assert("Don't have libpq-fe.h" == 0)
	#endif
#endif

  #include "PgConnection.h"
  #include "ConnectionException.h"
  #include "PgDriver.h"
  #include "PreparedStatement.h"


using namespace Aubit4glSql_postgresql;

/** The postgres driver object */
static PgDriver pgDriver;

extern "C" void exitwith(char *str);
extern "C" void set_errm (char *str);
extern "C" void debug (char *str);

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

#ifdef WIN32
	  int status;
#endif

#ifndef lint
  static const char rcs[] = "@(#)$Id: postgresql.cpp,v 1.5 2003-01-15 11:43:33 afalout Exp $";
#endif


typedef unsigned char UCHAR;
char lasterrorstr[1024] = "";

/** The global (not named) statement count, to generate unique names */
// @todo : This should be at the driver if necessary
static int statementCount = 0;

/** The counter of columns to get datatypes */
static int getColumnsOrder = 0;

/** The number of columns when getting datatypes */
static int getColumnsMax = 0;



/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 * Check if there was an sql error. Uses ESQL/C XOpen global variable SQLSTATE.
 *
 * @todo : Implement it.
 *
 * @return 
 *   - 1 : An sql error was ocurred.
 *   - 0 : No error 
 */
static int isSqlError()
{
  return 0;
}

/**
 * Check if the fetch was made to a not found row.
 *
 * Assign 100 to status.
 *
 * @return 
 *   - 1 : Row not found
 *   - 0 : Row found
 */
static int isNotFound()
{
  return 0;
}

/**
 * Get the status value.
 *
 * @todo Check if the status should be getted from the current connection 
 * object using the libpq function for this.
 *
 * @return The value to be assigned to status.
 */
extern "C" int A4GLSQL_get_status(void)
{
  return sqlca.sqlcode;
}

/**
 * Get the current SQL error message of the current default connection.
 *
 * @return The error message of the last error ocurred in the connection.
 */
extern "C" char *A4GLSQL_get_sqlerrm (void)
{
  return pgDriver.getCurrentConnection().getErrorMessage();
}

/**
 * Initialization of the sql library.
 *
 * @todo It is here that the PgDriver object should be initialized.
 */
extern "C" int A4GLSQL_initsqllib (void) 
{
}

/**
 * Init a new connection to the database and associate with an explicit 
 * session name.
 *
 * If the user identification was not set gets the values fromthe environment.
 *
 * @param sessname The name to be tied to the session. This is the name of 
 *   the connection
 * @param dsn The database name.
 * @param usr The user name to establish the connection.
 * @param pwd The password of the user to set the connection.
 */
extern "C" int A4GLSQL_init_session (char *sessname, char *dsn, 
char *usr, char *pwd)
{
  char *conninfo;
  
  if ( pgDriver.existConnection(sessname) == true )
  {
    // Error - Connection allready maded : setStatus
    // set the message with PQErrorMessage()
    // @todo : Set the message
    return 1;
  }

  try {
    PgConnection &pgConnection = pgDriver.connect(sessname,dsn,usr,pwd);
  }
  catch (ConnectionException& e) {
    // Error - Error connecting to the database : setStatus
    // @todo : Set the message
    return 1;
  }
  return 0;
}


/**
 * Connects to a database.
 *
 * @todo: programs that do not use DATABASE or CONNECT or SESSION,
 * should not call this function, but they DO!
 *
 * @param server The database name. If null the libpq try to see in the 
 * environment (PGDATABASE variable).
 * @param uid_p The user identification. If null libpq try to see PGUSER
 * environment variable.
 * @param pwd_p The password. If null libpq try to see PGPASWORD environment 
 * variable.
 * @return 
 *   - 1 : Connection estabilished.
 *   - 0 : there was an error connecting to database.
 */
extern "C" int A4GLSQL_make_connection (UCHAR *server,UCHAR *uid_p,UCHAR *pwd_p)
{
  return A4GLSQL_init_session (
    "default", 
    (char *)server, 
    (char *)uid_p, 
    (char *)pwd_p
  );
}

/**
 * Initialize the default connection to the database.
 *
 * @todo : Merge the functions in only one that connects calling from
 *         others.
 *
 * @param dbName The database name.
 * @return
 *  - 1 : An error ocurred.
 *  - 0 : Connection estabilished.
 */
extern "C" int A4GLSQL_init_connection (char *dbName)
{
  return A4GLSQL_make_connection ((UCHAR *)dbName,(UCHAR *)0,(UCHAR *)0);
}

/**
 * Close a named connection.
 *
 * @param sessname The session/connection name.
 * @return
 *  - 0 : Connection closed.
 *  - 1 : Connection does not exist or error ocurred.
 */
extern "C" int A4GLSQL_close_session (char *sessname)
{
  if ( !pgDriver.existConnection(sessname) )
  {
    // Error - Connection with that name does not exist
    // @todo : Set the status, sqlca and error code.
    return 1;
  }
  pgDriver.disconnect(sessname);
  return 0;
}


/**
 * Close the default connection.
 *
 * @param sessname The session/connection name.
 * @return
 *  - 0 : Connection closed.
 *  - 1 : Connection does not exist or error ocurred.
 */
extern "C" int A4GLSQL_close_connection(void)
{
  return A4GLSQL_close_session("default");
}

/**
 * Inicializa a informa��o sobre o estabelecimento da conex�o � base de dados.
 *
 * @todo : This function should pass to PgConnection class.
 *
 * @param dbname The database name.
 * @param userName The name of the user.
 * @param passwd The password
 */
static char *initConninfo(const char *dbname,const char *userName,
	                  const char *passwd)
{
  static char conninfo[512];
  if (dbname != NULL)
    sprintf(conninfo,"dbname=%s",dbname);

  if (userName != NULL)
  {
    strcat(conninfo,"user=");
    strcat(conninfo,userName);
  }

  if (passwd != NULL)
  {
    strcat(conninfo,"password=");
    strcat(conninfo,passwd);
  }
}

/**
 * Put a connection with a name as current connection.
 * 
 * @param sessname The session / connection name.
 * @return
 *   - 0 : Connection made default.
 *   - 1 : Connection with that name does not exist.
 */
extern "C" int A4GLSQL_set_conn (char *sessname)
{
  int retval = 0;
  try {
    pgDriver.setCurrentConnection(sessname);
  }
  catch (ConnectionException &e)
  {
    // Erro : Conex�o inexistente - Afectar status e error message
    // @todo Assign status and error message because the connection does not
    // exist.
    return 1;
  }
  return 0;
}

/**
 * Gets the name of the current connection.
 *
 * @todo : This method should belong only to connection manager
 *
 * @return The current connection name.
 */
extern "C" char *A4GLSQL_get_curr_conn(void)  
{
  char *name;

  /* @todo : Finish it
  try {
    PgConnection &currentConnection = pgDriver.getCurrentConnection();
  }
  catch (ConnectionException& e)
  {
    // @todo Assign status and error message
    return (char *)1;
  }
  name =  currentConnection.getConnectionName();
  */
  return name;
}

/**
 * Gets the database name of the current connection.
 *
 * @return The current database name.
 *    - NULL if no current connection.
 */
extern "C" char *A4GLSQL_get_currdbname()  
{
  char *currConnName;
  PgConnection connection;
  try {
    connection = pgDriver.getCurrentConnection();
  } 
  catch (ConnectionException& e)
  {
    // @todo Assign the status, sqlca and the error message
    return NULL;
  }

  // @todo : Possible memory leak here
  return strdup(connection.getDatabaseName());
}

/**
 * Create an sql statement structure.
 *
 * The structure s_sid is necesary because the compiler generate code that work
 * with it.
 *
 * @todo : Check and fix this function and pass it to a class.
 *
 * @param ibind The input bind array.
 * @param ni Number of elements in the input bind array.
 * @param obind The output bind array.
 * @param no The number of elements in the output bind array.
 * @param s A string containing the select statement.
 * @return A pointer to the statement identification structure.
 */
static struct s_sid *newStatement(
  struct BINDING *ibind, int ni, struct BINDING *obind, int no, char *s)
{
  typedef struct s_sid S_sid;
  S_sid *sid = (S_sid *)malloc(sizeof(S_sid));

  sid->select        = strdup(s);
  sid->ibind         = ibind;
  sid->ni            = ni;
  sid->obind         = obind;
  sid->no            = no;
  /*
  sid->statementName = strdup(getGlobalStatementName());

  statementName = sid->statementName;
  statementText = sid->select;
  */
  return sid;
}

/**
 * Prepare an sql statement acording to the bindings and statement.
 *
 * Note that if the statement have some syntax error it is only detected by
 * the backend when it is executed.
 *
 * @param ibind The input bind array.
 * @param ni Number of elements in the input bind array.
 * @param obind The output bind array.
 * @param no The number of elements in the output bind array.
 * @param s A string containing the select statement.
 * @return A pointer to the statement identification structure.
 */
static struct s_sid *prepareSqlStatement(
  struct BINDING *ibind, int ni, struct BINDING *obind, int no, char *s)
{
  struct s_sid *sid = newStatement(ibind,ni,obind,no,s);
	/** @todo : Implement this
  PgConnection & pgConnection = pgDriver.getCurrentConnection();
  PreparedStatement statement = pgConnection.prepareStatement(s);
  statement.prepare(s);
  */
  return sid;
}

/**
 * Prepare a global SQL statement (not named).
 *
 * @todo : Make all the assertions that i can.
 *
 * @param s A string with the SQL statement.
 * @param ni The number of input bind elements.
 * @param ibind A pointer to the input bind array.
 * @return A statement identification structure pointer.
 */
extern "C" struct s_sid *A4GLSQL_prepare_glob_sql (char *s, int ni, struct BINDING *ibind)
{
  return(prepareSqlStatement(ibind,ni,(struct BINDING *)0,0,s));
}

/** 
 * Convert the aubit data type of aubit 4gl to the informix specific.
 *
 * Note : This function is till in early stage. For now do not do nothing.
 *
 * @todo : Confirm that the datatypes reach here how informix need it 
 * 
 * @param dataType The aubit 4gl data type.
 * @return The informix data type.
 */
static int getIfmxDataType(int dataType)
{
  return dataType;
}

/**
 * Bind the value to input descriptor entry.
 *
 * @todo This mechanism should pass to one of the classes.
 *
 * @param descName The name for using as a global descriptor.
 * @param idx The position of the bound being setted 
 * @param bind A pointer to the bind array.
 * @return
 *  - 0 : Statement executed.
 *  - 1 : An error as ocurred.
 */
static int bindInputValue(char *descName,int idx,struct BINDING *bind)
{
  static const char function[] = "bindInputValue";
  return 0;
}

 
/**
 * Makes the bind of the input variables to pass to the statement to a 
 * global ESQL descriptor area.
 *
 * @todo : This function should go to one of the classes.
 *
 * @param descName The name for using as a global descriptor.
 * @param bCount The number of values to bind.
 * @param bind A pointer to the bind array.
 * @return
 *  - 0 : Statement executed.
 *  - 1 : An error as ocurred.
 */
static int processInputBind(char *descName,int bCount,struct BINDING *bind)
{
	/* @todo :Implement this
  for ( int i = 0 ; i < bindCount ; i++ )
    if ( bindInputValue(descriptorName,i,bind) == 1 )
      return 1;
      */
  return 0;
}

/**
 * Bind the value to output descriptor entry.
 *
 * Part of this code is copied from DBD::Informix.
 *
 * @todo : This mechanism should go to one of the classes.
 *
 * @param descName The name for using as a global descriptor.
 * @param idx The position of the bound being setted 
 * @param bind A pointer to the bind array.
 * @return
 *  - 0 : Statement executed.
 *  - 1 : An error as ocurred.
 */
static int bindOutputValue(char *descName,int idx,struct BINDING *bind)
{
  static const char function[] = "bindOutputValue";
  return 0;
}

/**
 * Allocate the output descriptors because they must exist before the 
 * execution of the statement.
 *
 * @todo : I think that this is not necessary here
 *
 * @param descName The name for using as a global descriptor.
 * @param bCount The number of values to bind.
 * @param bind A pointer to the bind array.
 * @return
 *  - 0 : Statement executed.
 *  - 1 : An error as ocurred.
 */
static int allocateOutputDescriptor(char *descName,
  int bCount,struct BINDING *bind)
{
  return 0;
}
 
/**
 * Makes the bind of the input variables to pass to the statement to a 
 * global ESQL descriptor area.
 *
 * @todo : I think that this is not necessary here
 *
 * @param descName The name for using as a global descriptor.
 * @param bCount The number of values to bind.
 * @param bind A pointer to the bind array.
 * @return
 *  - 0 : Statement executed.
 *  - 1 : An error as ocurred.
 */
static int processOutputBind(char *descName,int bCount,struct BINDING *bind)
{
  return 0;
}

/**
 * Generate the descriptor name.
 *
 * @todo : I think that this is not necessary here
 *
 * @param statementName The name of the statement to build descriptor name.
 * @param type The descriptor type:
 *   - I : Descriptor for input bind.
 *   - O : Descriptor for output bind.
 * @return The descriptor name.
 */
char *getDescriptorName(char *statementName,char bindType)
{
  char *descriptorName = (char *)malloc(sizeof(statementName+6));
  sprintf(descriptorName,"%s_%cbind",statementName,bindType);
  return descriptorName;
}

#define INPUT_OUTPUT_BIND 0
#define INPUT_BIND        1
#define OUTPUT_BIND       2
#define NO_BIND           3

/**
 * Define the type of statement to be executed.
 * 
 * @param sid A pointer to the statement structure.
 * @return The statement type
 */
static int getStatementBindType(struct s_sid *sid)
{
  if ( sid->obind != (struct BINDING *)0 && sid->no > 0 &&
       sid->ibind != (struct BINDING *)0 && sid->ni > 0 )
    return INPUT_OUTPUT_BIND;
  if ( sid->ibind != (struct BINDING *)0 && sid->ni > 0 )
    return INPUT_BIND;
  if ( sid->obind != (struct BINDING *)0 && sid->no > 0 )
    return OUTPUT_BIND;
  return NO_BIND;
}

/**
 * Execute the SQL statement.
 *
 * The type of the statement is choosed acording the bind available.
 *
 * @todo : This should go to one of the classes. 
 *
 * @param sid The statement information.
 * @return
 *  - 0 : Connection closed.
 *  - 1 : Connection does not exist or error ocurred.
 */
static int executeStatement(struct s_sid *sid)
{
  int rc = 0;
  return rc;
}

/**
 * Prepare an sql statement.
 *
 * @todo : Finish and test this function.
 *
 * @param s A string with the sql statement to be prepared.
 * @return A pointer to the statement information structure.
 */
extern "C" struct s_sid *A4GLSQL_prepare_sql (char *s)
{
  return(prepareSqlStatement((struct BINDING *)0,0,(struct BINDING *)0,0,s));
}

/**
 * Store the information of a prepared statement in a global data structure.
 *
 * @todo The prepared statement should be stored in the connection object.
 *
 * @param pname The prepared statement name.
 * @param sid A pointer to the statement information.
 * @return Allways 0
 */
extern "C" int A4GLSQL_add_prepare (char *pname, struct s_sid *sid)
{
	/*
  if (sid)
  {
    add_pointer (pname, PRECODE, sid);
    return 1;
  }
  else
  {
    return 0;
  }
  */
}

/**
 * Not used.
 *
 * @param prepared statement name.
 * @param ni Number of binded input parameters.
 * @param The input bind array.
 * @return Allways 0
 */
extern "C" int A4GLSQL_execute_sql_from_ptr(char *pname, int ni, char **ibind)
{
  return 0;
}

/**
 * Process the binds of a statement before the execution.
 *
 * the structure s_sid is expanded to have the descriptor names.
 *
 * @todo This is not necessary here.
 * 
 * @param sid A pointer to the statement identification structure.
 * @return
 *  - 0 : Binds made.
 *  - 1 : Error making binds
 */
static int processPreStatementBinds(struct s_sid *sid)
{
  return 0;
}

/**
 * Dealocate the descriptors used in a statement.
 *
 * @todo : This should be made in the prepared statement desctruction.
 *
 * @param sid The statement information.
 * @return
 *  - 0 : Connection closed.
 *  - 1 : Connection does not exist or error ocurred.
 */
static int deallocateDescriptors(struct s_sid *sid)
{
  int rc = 0;
  return rc;
}

/**
 * Process the binds of a statement after the execution.
 *
 * @todo : Even if it is necessary should be made in the statement class
 *
 * the structure s_sid is expanded to have the descriptor names.
 * 
 * @param sid A pointer to the statement identification structure.
 * @return
 *  - 0 : Binds made.
 *  - 1 : Error making binds
 */
static int processPosStatementBinds(struct s_sid *sid)
{
  if ( sid->obind != (struct BINDING *)0 && sid->no > 0 )
  {
    if ( processOutputBind(sid->outputDescriptorName,sid->no,sid->obind) == 1)
      return 1;
  }
  if ( deallocateDescriptors(sid) == 1 )
    return 1;
  return 0;
}


/**
 * Execute an implicit select instruction.
 *
 * Used when the SELECT is a direct SELECT INTO in 4gl code.
 *
 * @todo : This should be made in one of the classes.
 *
 * @param sid The statement information that should be prepared.
 * @return
 *  - 0 : Connection closed.
 *  - 1 : Connection does not exist or error ocurred.
 *  - -1 : The pointer to the statement is null.
 */
int A4GLSQL_execute_implicit_select (struct s_sid *sid)
{
  //debug("PG : execute_implicit_select");
  if (sid == 0)
    return -1;

  if ( processPreStatementBinds(sid) == 1 )
    return 1;
  if ( executeStatement(sid) == 1 )
    return 1;
  if ( processPosStatementBinds(sid) == 1 )
    return 1;
  return 0;
}

/**
 * Execute an sql statement where the its execution is implicit in 4gl.
 *
 * @todo : Finish the statement execution.
 * @todo : See the bind array that is passed as simple pointer.
 * @todo : We could use same way that execute implicit select.
 * @todo : use executeStatement().
 *
 * @param sid The statement identification.
 * @return
 *  - 0 : Statement executed.
 *  - 1 : An error as ocurred.
 */
extern "C" int A4GLSQL_execute_implicit_sql (struct s_sid *sid)
{
  int rc = 0;

  if ( sid == (struct s_sid *)0 )
  {
    /** @todo : I should store the error message and number somwehere */
    return 1;
  }

  if ( processPreStatementBinds(sid) == 1 )
    return 1;
  if ( executeStatement(sid) == 1 )
    return 1;
  if ( processPosStatementBinds(sid) == 1 )
    return 1;
  return 0;
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
extern "C" struct s_sid *A4GLSQL_prepare_select (
  struct BINDING *ibind, int ni, struct BINDING *obind, int no, char *s)
{
  return(prepareSqlStatement(ibind,ni,obind,no,s));
}


#define SIMPLE                0
#define SIMPLE_SCROLL         1
#define FOR_UPDATE            2
#define FOR_UPDATE_WITH_HOLD  3
#define WITH_HOLD             4

/**
 * Get the cursor type to be declared acording to the flags.
 *
 * @todo : Fix other cursor types.
 * @todo : Insert an assertion.
 * @todo : Understand what cursors do i have in postgresql.
 * @todo : This should be made in some separate class.
 *
 * @param upd_hold Indicate if the cursor is for update and(or) with hold
 *   - 0 : Not for update and without hold.
 *   - 1 : For update without hold.
 *   - 2 : With hold NOT for  update.
 * @param scroll Flag that indicate that the cursor have scroll:
 *   - 0 : Does not have scroll.
 *   - 1 : Have scroll.
 * @return The cursor type
 */
static int getCursorType(int upd_hold,int scroll)
{
  if ( scroll == 0 )
  {
    switch (upd_hold)
    {
      case 0:
        return SIMPLE;
      case 1: 
        return FOR_UPDATE;
      case 2: 
        return WITH_HOLD;
    }
  }
  else if ( scroll == 1 )
    return SIMPLE_SCROLL;
  else
    return -1;
}


/**
 * Declare a cursor.
 *
 * @todo : This shoud be made in a specific class.
 *
 * @todo : Include assertions.
 *
 * @param upd_hold Indicate if the cursor is for update or with hold.
 *   - 0 : Not for update and without hold
 *   - 1 : Cursor for update and without hold
 *   - 2 : Cursor with hold and not for update
 * @param sid Select statement to use with the cursor.
 * @param scroll Indicate if is a scrolling cursor:
 *   - 0 : The cursor does not have scrolling
 *   - 1 : The cursor does have scrolling
 * @param cursname The cursor name.
 * @return A pointer to the cursor informationstrucutre.
 */
extern "C" struct s_cid *A4GLSQL_declare_cursor(
  int upd_hold,struct s_sid *sid,int scroll,char *cursname)
{
  int retval = 0;
  struct s_cid *cursorIdentification;

  return cursorIdentification;
}


/**
 * Open a cursor already declared.
 *
 * @todo : This should be made in the PgConnection object.
 *
 * @todo : Terminate the function implementation.
 * @todo : Using its not OK
 *
 * @param ni Number of input binds to be compared with the binds in prepare
 * @param s The cursor name.
 * @return
 *   - 1 : Cursor declared.
 *   - 0 : An error as ocurred.
 */
extern "C" int A4GLSQL_open_cursor (int ni, char *s)
{
  return 0;
}

#define FETCH_FIRST     0
#define FETCH_LAST      1
#define FETCH_NEXT      2
#define FETCH_PREVIOUS  3
#define FETCH_CURRENT   4
#define FETCH__RELATIVE 5
#define FETCH__ABSOLUTE 6

/**
 * Define the fetch type.
 *
 * @param fetch_mode
 *   - FETCH_RELATIVE 
 *   - FETCH_ABSOLUTE
 * @param fetch_when
 *   - 0 : CURRENT
 *   - 1 : FIRST or NEXT
 *   - -1 : LAST or PREVIOUS
 *   - Otherwise : The number of elements (relative or absolute)
 * @return
 */
static int getFetchType(int fetch_mode,int fetch_when)
{
  if ( fetch_when == 0 )
    return FETCH_CURRENT;

  if ( fetch_when == 1 )
  {
    if ( fetch_mode == FETCH__ABSOLUTE )
      return FETCH_FIRST;
    else if ( fetch_mode == FETCH__RELATIVE )
      return FETCH_NEXT;
    else
      exitwith ("Invalid cursor type");
  }

  if ( fetch_when == -1 )
  {
    if ( fetch_mode == FETCH__ABSOLUTE )
      return FETCH_LAST;
    else if ( fetch_mode == FETCH__RELATIVE )
      return FETCH_PREVIOUS;
    else
      exitwith ("Invalid cursor type");
  }

  if ( fetch_mode == FETCH__ABSOLUTE )
    return FETCH__ABSOLUTE;

  if ( fetch_mode == FETCH__RELATIVE )
    return FETCH__RELATIVE;
  exitwith ("Invalid cursor type");
  return -1;
}

/**
 * Fetch a cursor into the binding variables.
 *
 * @todo : Most of this should be made by ResultSet class
 *
 * @param cursor_name A string containing the 4gl cursor name.
 * @param fetch_mode The type of the fetch to be made:
 *   - FETCH_RELATIVE 
 *   - FETCH_ABSOLUTE
 * @param fetch_when
 *   - 0 : CURRENT
 *   - 1 : FIRST or NEXT
 *   - -1 : LAST or PREVIOUS
 *   - Otherwise : The number of elements (relative or absolute)
 * @param nobind Count of elements in the output bind array.
 * @param obind A pointer to the input bind array.
 * @return
 *   - 1 : Cursor fetched.
 *   - 0 : An error as ocurred.
 */
extern "C" int A4GLSQL_fetch_cursor (char *cursor_name,
		      int fetch_mode, int fetch_when, int nobind,
		      struct BINDING *obind)
{
  return 0;
}

/**
 * Put the information in an insert cursor.
 *
 * The compiler does not suport insert cursors for now.
 * 
 * @todo : Fix the parameters. We need the cursor name.
 *
 * @param ibind The bind array
 * @param n The number of elements in the bind array.
 * @return
 *   - 1 : Data inserted in the cursor.
 *   - 0 : An error as ocurred.
 */
extern "C" void A4GLSQL_put_insert (struct BINDING *ibind, int n)
{
}

/**
 * Print the information to the file acording to the data type
 *
 * @this should be implemented in an unload class
 * 
 * @param unloadFile A pointer to the opened unload file
 * @param idx The index of the column to be printed
 * @return 
 *   - 1 : An error as ocurred.
 *   - 0 : Field printed.
 */
static int printField(FILE *unloadFile,int idx,char *descName)
{
  FglDecimal  *fgl_decimal;
  FglMoney    *fgl_money;
  FglDatetime *fgl_dtime;
  FglInterval *fgl_interval;
  int rc = 0;

  return 0;
}

/**
 * Unload the data to a file acording to SQL statemement with
 * columns separated by a delimiter.
 *
 * @todo : Implement this in a specific class.
 * @todo : Implement the unload
 * @todo : Merge the code to a connector library in order to have just
 *         one function to do it.
 *
 * @param fname The name where the data is to be inserted.
 * @param delims The row delimiter.
 * @param sql1 The SQL to generate the data.
 *
 * @return
 *   - 1 : There was an error unloading the data.
 *   - 0 : Data unloaded to file.
 */
extern "C" void A4GLSQL_unload_data (char *fname, char *delims, char *sqlStr)
{
}

/**
 * Implementationin ODBC of the transaction statements (BEGIN WORK, 
 * COMMIT WORK, ROLLBACK WORK).
 *
 * @todo : Implement this in the connection object.
 * @todo : Change the variable.
 * @todo : See wath is TRANSMODE.
 * @param mode The transaction statement to execute:
 *   - -1 : Begin work
 *   - 0 : Rollback work
 *   - 1 : Commit work
 * @return 
 *  - 0 : Instruction executed.
 *  - 1 : An error as ocurred.
 */
extern "C" void A4GLSQL_commit_rollback (int mode)
{
}

/**
 * Find a prepared statement.
 *
 * There should be a global strucutre or array where to store all the
 * prepared statements.
 *
 * @todo : This is implemented inside connection class.
 * @todo : The mode should be used for something.
 *
 * @param pname The statement name.
 * @return 
 *   - A pointer to the structure found in the tree.
 *   - 0 : The structure was not found
 */
extern "C" struct s_sid *A4GLSQL_find_prepare (char *pname)
{
  return (struct s_sid *)0;
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
extern "C" void A4GLSQL_flush_cursor (char *cursor)
{
}

/**
 * Execute an allready prepared SQL statement.
 *
 * @todo Implement this in the PreparedStatement class
 *
 * @param pname  The prepared statement name.
 * @param ni Number of elements in the input bind.
 * @param ibind The input binding array used.
 * @return
 *   - 0 : SQL statement executed.
 *   - 1 : There was an error.
 */
extern "C" int A4GLSQL_execute_sql (char *pname, int ni, struct BINDING *ibind)
{
  struct s_sid *sid;

  debug("ESQL : A4GLSQL_execute_sql");
  /** @todo : Fix the mode that is not used now */
  sid = A4GLSQL_find_prepare (pname);
  sid->ibind = ibind;
  sid->ni    = ni;
  if ( processPreStatementBinds(sid) == 1 )
    return 1;
  if ( executeStatement(sid) == 1 )
    return 1;
  if ( processPosStatementBinds(sid) == 1 )
    return 1;
  return 0;
}

/**
 * Start getting information about all columns from a table in the database 
 * engine.
 *
 * @todo : Implement this with getMetaData of Connection class.
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
extern "C" int A4GLSQL_get_columns(char *tabname, char *colname, 
		                   int *dtype, int *size)
{
  return 1;
}


/**
 * Iterate in getting information about all columns from a table from the 
 * database engine.
 *
 * A4GLSQL_get_columns(char *tabname) should be called before this one.
 *
 * @todo Use DatabaseMetadata to do it.
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
extern "C" int A4GLSQL_next_column(char **colname, int *dtype,int *size)
{
  return 1;
}

/**
 * Free all resources allocated in getting information about columns
 *
 * @todo Free(s) a DatabaseMetaData object.
 * 
 * @return 
 *   - 0 : Descriptor dealocated
 *   - 1 : Error ocurred.
 */
extern "C" int A4GLSQL_end_get_columns(void)
{
  return 1;
}


/**
 * Gets information about columns from a table in the database engine.
 *
 * @todo : Use DatabaseMetaData
 * @todo : Put this working with .*
 * @todo : Remove if not used.
 *
 * @param tabname The table that we wish to get information about it.
 * @param colname The column name to get information about it.
 * @param dtype A pointer to the variable where to put the data type.
 * @param size A pointer to the variable where to put the size of the column
 *  returned by the database.
 * @return 
 *   - 0 : Information readed.
 *   - 1 : Error ocurred.
 */
static int getDataType(char *connName, char *tabname,char *colname,
  int *dtype,int *size)
{
  return 0;
}

/**
 * Gets information about columns from a table in the database engine.
 *
 * Aparently the compiler is waiting for an iteration in the columns of a
 * table.
 *
 * @todo : Use database metadata.
 * @todo : Put this working with .*
 * @todo : Use the getDataType()
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
extern "C" int A4GLSQL_read_columns(char *tabname,char *colname,int *dtype,int *size)
{
  return 1;
}

/**
 * Get the datatype of a column in the database engine.
 *
 * @todo : Use database metadata.
 *
 * @todo : Understand if this function is used somewhere.
 *
 * @param db The database name.
 * @param tab The table name.
 * @param col The column name.
 * @return 
 *   - -1 : An error ocurred.
 *   - Otherwise : The datatype code.
 */
extern "C" int A4GLSQL_get_datatype (char *db, char *tab, char *col)
{
  int dataType;
  int length;
  char *connectionName;

  //connectionName = pgDriver.getConnectionNameForDatabase(db);
  if ( connectionName == NULL )
    return -1;

  if ( getDataType(connectionName,tab,col,&dataType,&length) == 1 )
    return -1;
  return dataType;
}

/**
 * Close a cursor opened.
 *
 * @todo : Use the connection class
 *
 * @param currname The name of the cursor.
 * @return
 */
extern "C" int A4GLSQL_close_cursor(char *currname)  
{
  return 1;
}

/**
 * @todo : Understand if this function is used.
 */
extern "C" int A4GLSQL_fill_array (int mx, char **arr1, int szarr1, 
		    char **arr2, int szarr2,
		    char *service, int mode, char *info)
{
  exitwith ("Could not fill_array - noODBC build");
  return 1;
}

/**
 * Assign the sqlca.sqlcode with a value.
 *
 * @todo : this function MUST call a function outside ESQL in order to use the
 * other sqlca that is not the informix one.
 *
 * @param a The value to be assigned to sqlca.sqlcode
 * @return Allways 0
 */
extern "C" void A4GLSQL_set_sqlca_sqlcode (int a)
{
  status = a;
  sqlca.sqlcode = a;
}

/**
 * Describe an sql statement.
 *
 * @todo : Implement it with the preparedStatement.getMetaData()
 * @todo : Understand where this is used.
 *
 * @param stmt The text with the statement to be described.
 * @param colno
 * @param type The type of the information wanted.
 * @return
 */
extern "C" long A4GLSQL_describe_stmt (char *stmt, int colno, int type) 
{
  printf("Describe smtm\n");
}
