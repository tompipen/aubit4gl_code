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
# $Id: esql.ec,v 1.22 2002-07-26 14:37:03 mikeaubury Exp $
#
*/

/*
 * @file
 *
 * Implementation of the direct connection of aubit 4gl to Informix database
 * using esql/c.
 *
 * since on Windows only ESQL/C supported compiler is Visual C++, or Bordland
 * we must be carefull not to include anything that will conflict with
 * MSVC here, since resulting .c need to be compiled and linked by MSVC
 *
 * The functions that are not static are the ones that are defined by the 
 * Aubit4gl Database Driver Interface.
 *
 * This interface is the way to have aubit working with severall diferent
 * ways of access to relational databases.
 *
 * In this module it is our goal to have the implementation the most like as 
 * possible to Xopen embeded sql definition.
 *
 * When compiled its assembled in a dynamic library called libSQL_esql.so (or
 * .ddl in windows).
 *
 * Its loaded acording to an environment variable called A4SQL_SQLTYPE that
 * should be filled with "esql".
 *
 * @todo : Assertions
 * @todo : Assign status with set_status
 */


/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#define DEFINE_SQLCA

/** Informix ESQL/C database connector type */
#define ESQL_CONNECTOR   0

#define _SQLCA_DEFINED_

#ifdef WIN32
	#define _NO_FORM_H_
	#define _NO_CURSES_H_
	#define _NO_PANEL_H_
	#define _NO_CURSLIB_H_
	#define FORMXW 					/* form_x.h */
	#define _NO_DBFORM_H_
#endif

#define INPUT_OUTPUT_BIND 0
#define INPUT_BIND        1
#define OUTPUT_BIND       2
#define NO_BIND           3


#define SIMPLE                0
#define SIMPLE_SCROLL         1
#define FOR_UPDATE            2
#define FOR_UPDATE_WITH_HOLD  3
#define WITH_HOLD             4

#define FETCH_FIRST     0
#define FETCH_LAST      1
#define FETCH_NEXT      2
#define FETCH_PREVIOUS  3
#define FETCH_CURRENT   4
#define FETCH__RELATIVE 5
#define FETCH__ABSOLUTE 6


/*
=====================================================================
		                    Includes
=====================================================================
*/

#ifdef OLD_INCL

	#include <stdio.h>
	#include "a4gl_incl_4gldef.h"
	#include "a4gl_database.h"

	#ifndef WIN32
		#include <string.h>
		#include "a4gl_pointers.h"
		#include "a4gl_dtypes.h"
		#include <stdlib.h>
	#else
		#include <windows.h>
		#include "a4gl_pointers.h"
		#include "a4gl_dtypes.h"
	#endif

	#include "a4gl_constats.h"
	#include "a4gl_incl_4glhdr.h"

	#ifndef WIN32
		#include <stdarg.h>
	#endif

	/* stack.h will eventually include stdlib.h, which uses getenv(), so
	 * we need to set GETENV_OK and only then include debug.h
	 */
	#include "a4gl_stack.h"
	#define GETENV_OK
	#include "a4gl_debug.h"

#else

    #include "a4gl_lib_sql_esqlc_int.h"

#endif


EXEC SQL include sqlca;


/*
=====================================================================
                    Variables definitions
=====================================================================
*/

#ifndef lint
	static const char rcs[] = "@(#)$Id: esql.ec,v 1.22 2002-07-26 14:37:03 mikeaubury Exp $";
#endif

#ifdef WIN32
	int status;
#endif

#ifdef OLD_INCL
	typedef unsigned char UCHAR;
#endif

char lasterrorstr[1024] = "";

/** The global (not named) statement count, to generate unique names */
static int statementCount = 0;

/** Indicate if an error as ocurred in order to return error codes */
static int errorOcurred;

/**
 * Information about a connection to a database.
 *
 * This type should be expanded to use a global connection manager in aubit
 *
 * @todo : Put this in a connection manager
 */
typedef struct {
  char *connectionName; /**< The name of the connection - This is unique */
  char *databaseName;   /**< The name of the database */
  char connector;       /**< The aubit connector used */
  char *userName;       /**< User name used for estabilishing the connection */
  char *password;       /**< The password used to connect */
  void *connectionInfo; /**< A pointer to a connector specific information */
}DbConnection;

/** The current connection name */
char *currentConnection;

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
 * Handle the ocurrence of sql errors.
 */
static void esqlErrorHandler(void)
{
  A4GLSQL_set_status(sqlca.sqlcode,1);
}

/**
 * Handle the ocurrence of sql warnings.
 */
static void esqlWarningHandler(void)
{
}

/**
 * Check if there was an sql error. Uses ESQL/C XOpen global variable SQLSTATE.
 *
 * @return 
 *   - 1 : An sql error was ocurred.
 *   - 0 : No error 
 */
static int isSqlError()
{
  if ( SQLSTATE[0] != '0' || (SQLSTATE[1] != '0' &&
       SQLSTATE[1] != '1' && SQLSTATE[1] != '2' ) )
    return 1;
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
  if ( strcmp(SQLSTATE,"02000") == 0 )
  {
    A4GLSQL_set_status(100,1);
    return 1;
  }
  return 0;
}

/**
 * Get the status value.
 *
 * @return The value to be assigned to status.
 */
int A4GLSQL_get_status(void)
{
  return sqlca.sqlcode;
}

/**
 * Get the current SQL error message.
 *
 * @return The contents of sqlca.sqlerrm.
 */
char *A4GLSQL_get_sqlerrm (void)
{
  EXEC SQL BEGIN DECLARE SECTION;
    char *msg = (char *)malloc(8191);
  EXEC SQL END DECLARE SECTION;
  
  EXEC SQL get diagnostics exception 1 :msg = MESSAGE_TEXT;
  return msg;
}

/**
 * Initialization of the sql library.
 *
 * Just initialize the error handling.
 */
/* void */	/* int A4GLSQL_initsqllib(void); */			/* << from sql.c */
int
A4GLSQL_initsqllib (void)
{
  EXEC SQL whenever sqlerror call esqlErrorHandler;
  EXEC SQL whenever sqlwarning call esqlWarningHandler;
  currentConnection = NULL;
  return 1;
}

/**
 * Get a unique name for a global (not named) statement.
 * To obtain it increment the static statementCount.
 *
 * @return The global statement count @return The global statement count.
 */
static char *getGlobalStatementName(void)
{
  static char statementName[10];

  statementCount++;
  sprintf(statementName,"st_%d",statementCount);
  return statementName;
}

/*  =================== Connection manager =================== */

/**
 * Create a new DbConnection object.
 *
 * @return A pointer to the connecion allocated.
 */
static DbConnection *NewDbConnection()
{
  DbConnection *connection;

  connection = (DbConnection *)malloc(sizeof(DbConnection));
  return connection;
}

/**
 * Gets the current connection information.
 *
 * @return The current connection.
 */
static DbConnection *getCurrentESQLConnection(void)
{
  DbConnection *currConnection;

  if ( currentConnection == NULL )
    return (DbConnection *)0;
  currConnection = (DbConnection *)find_pointer_val (
    currentConnection, 
    SESSCODE
  );
  
  return currConnection;
}

/**
 * Gets the name of the current connection.
 *
 * @return The name of the current connection.
 */
static char *getCurrentESQLConnectionName(void)
{
  return currentConnection;
}

/**
 * Mark a connection as current.
 *
 * @param connectionName The name of the connection to be current.
 */
static int setCurrentESQLConnection(char *connectionName)
{
  currentConnection = connectionName;
}

/**
 * Remove a connection from the manager array.Normaly this is due to be
 * closed.
 *
 * @param connectionName The name of the connection
 * @return 
 *   - 1 : There is no connection with that name
 *   - 0 : Connection removed
 */
static int removeESQLConnection(char *connectionName)
{
  if ( !has_pointer (connectionName, SESSCODE))
    return 1;

  del_pointer (connectionName, CURCODE);
  return 0;
}

/**
 * Add a new connection to the manager
 *
 * @param connectionName The name of the connection.
 * @param databaseName The name of the database.
 * @param userName The name of the user used to connect.
 * @param passwd The password used to connect.
 *
 * @return
 *   - 1 : An error as ocurred, because a connection with that name allready
 *         exist.
 *   - 0 : Connection added
 */
static int addESQLConnection(char *connectionName,char *dbName,
  char *userName,char *passwd)
{
  DbConnection *connection;
  if ( has_pointer (connectionName, SESSCODE))
    return 1;
  connection = NewDbConnection();
  connection->connectionName = strdup(connectionName);
  connection->databaseName   = strdup(dbName);
  connection->connector      = ESQL_CONNECTOR;
  connection->userName       = userName;
  connection->password       = passwd;
  connection->connectionInfo = 0;
  add_pointer (connectionName, SESSCODE,connection);
  return 0;
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
int A4GLSQL_init_connection (char *dbName)
{
  EXEC SQL BEGIN DECLARE SECTION;
    char *db = dbName;
  EXEC SQL END DECLARE SECTION;

  EXEC SQL connect to :db as 'default';
  if ( isSqlError() )
    return 1;
  addESQLConnection("default",dbName,NULL,NULL);
  return 0;
}

/**
 * Close a named connection.
 *
 * @param sessname The session/connection name.
 * @return
 *  - 0 : Connection closed.
 *  - 1 : Connection does not exist or error ocurred.
 */
int A4GLSQL_close_session (char *sessname)
{
  EXEC SQL begin declare section;
    char *connectionName = sessname;
  EXEC SQL end declare section;

  if ( connectionName == NULL )
    EXEC SQL DISCONNECT DEFAULT;
  else
    EXEC SQL DISCONNECT :connectionName;
  removeESQLConnection(connectionName);
  if ( isSqlError() )
    return 1;
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
int A4GLSQL_close_connection(void)
{
  return A4GLSQL_close_session("default");
}

/**
 * Connects to a database.
 *
 * @todo: programs that do not use DATBASE or CONNECT or SESSION,
 * should not call this function, but they DO!
 *
 * @param server The database name. In odbc this could be the datasource.
 *  In informix its always the database name.
 * @param uid_p The user identification.
 * @param pwd_p The password.
 * @return 
 *   - 1 : Connection estabilished.
 *   - 0 : there was an error connecting to database.
 */
/*	int A4GLSQL_make_connection(UCHAR * server, UCHAR * uid_p, UCHAR * pwd_p); */
int A4GLSQL_make_connection
/*  const UCHAR *server,const UCHAR *uid_p,const UCHAR *pwd_p) */
(UCHAR * server, UCHAR * uid_p, UCHAR * pwd_p)
{
  EXEC SQL begin declare section;
    char *dbName;
    char *userName;
    char *passwd;
  EXEC SQL end declare section;
  int retval = 0;

  dbName   = strdup(server);
  userName = strdup(uid_p);
  passwd   = strdup(pwd_p);
  EXEC SQL connect to :dbName as 'default' 
    user :userName using :passwd;
  if ( isSqlError() )
    retval = 1;
  else
    addESQLConnection("default",dbName,userName,passwd);
  free(dbName);
  free(userName);
  free(passwd);
  return retval;
}

/**
 * Initialize the user name used to access the password.
 * The username returned is allocated here, so need to be freed when 
 * no longer needed.
 *
 * This function is a candidate to be in an sql suport library.
 * 
 * @param userName The user name passed (could be null)
 * @return The user name to use.
 */
static char *initUser(const char *userName)
{
  char *retUser;
  if ( userName != NULL )
    return strdup(userName);
  /** @todo : Confirm if this should be the env var name to be used */
  retUser = (char *)acl_getenv("SQLUID");
  if ( retUser != NULL )
    return strdup(retUser);
  return retUser;
}

/**
 * Decide wich password to use acording to the define value and environment.
 *
 * @param passwd The password to check.
 * @return The password choosed.
 */
static char *initPassword(const char *passwd)
{
  char *retPasswd;
  if ( passwd != NULL )
    return strdup(passwd);
  /** @todo : Confirm if this should be the env var name to be used */
  retPasswd = (char *)acl_getenv("SQLPWD");
  if ( retPasswd != NULL )
    return strdup(retPasswd);
  return retPasswd;
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
int A4GLSQL_init_session (char *sessname, char *dsn, char *usr, char *pwd)
{
  EXEC SQL begin declare section;
    char *dbName = dsn;
    char *userName;
    char *password;
    char *connectionName = sessname;
  EXEC SQL end declare section;
  int retval = 0;

  if ( dsn == NULL )
  {
    exitwith ("Database name not seted");
    return 1;
  }


  /** @todo : Even if the connection exist it should not be the default one */
  /* See if its allready opened. */
  EXEC SQL set connection :connectionName;
  if ( SQLSTATE[0] == '0' && (SQLSTATE[1] == '0' ||
       SQLSTATE[1] == '1' || SQLSTATE[1] == '2' ))
  {
    exitwith ("Session already opened");
    return 1;
  }

  /* Treat the user and password precedence. */
  userName = initUser(usr);
  password = initPassword(pwd);

  if (connectionName == NULL )
  {
    EXEC SQL CONNECT TO DEFAULT;
  }
  else
  {
    if (userName == NULL || password == NULL )
      EXEC SQL connect to :dbName as :connectionName;
    else
    {
      EXEC SQL connect to :dbName as :connectionName
        user :userName using :password;
      free(userName);
      free(password);
    }
  }

  if ( isSqlError() )
    retval = 1;
  else
    addESQLConnection("default",dbName,userName,password);
  return retval;
}


/**
 * Put a connection with a name as current connection.
 * 
 * @param sessname The session / connection name.
 * @return
 *   - 0 : Connection made default.
 *   - 1 : Connection with that name does not exist.
 */
int A4GLSQL_set_conn (char *sessname)
{
  EXEC SQL begin declare section;
    char *connectionName = sessname;
  EXEC SQL end declare section;
  int retval = 0;

  if ( connectionName == NULL )
    EXEC SQL SET CONNECTION DEFAULT;
  else
    EXEC SQL SET CONNECTION :connectionName;
  if ( isSqlError() )
    retval = 1;
  else
    setCurrentESQLConnection(connectionName);
  return retval;
}

/**
 * Gets the name of the current connection.
 *
 * @todo : Implement the mechanism.
 *
 * @return The current connection name.
 */
char *A4GLSQL_get_curr_conn(void)  
{
  return getCurrentESQLConnectionName();
}

/**
 * Gets the database name of the current connection.
 *
 * @todo : Implement the mechanism.
 *
 * We need to store the current connection somewhere.
 *
 * @return The current database name.
 *    - NULL if no current connection.
 */
/* 	char *A4GLSQL_get_currdbname(void); */
/* char *A4GLSQL_get_currdbname(char *cursor) */
char *A4GLSQL_get_currdbname(void)
{
  DbConnection *currConnection;

  currConnection = getCurrentESQLConnection();
  if ( currConnection == (DbConnection *)0 )
    return NULL;
  return currConnection->connectionName; 
}

/**
 * Get the connection name for a database.
 * 
 * The connections are stored in the connection manager.
 *
 * This connection manager is for now local to ESQL but should be expanded
 * for all connectors at some time.
 *
 * @todo : Implement the connection mechanism.
 *
 * @param databaseName The name of the database.
 * @return 
 *   - The connection name
 *   - NULL : If no connection for that specific database opened
 */
static char *getConnectionForDatabase(char *databaseName)
{
  register int i;

  /*
   This is not working.
   For doing this i need an iterator trough the tree.
  hh = find_pointer_val ("default", SESSCODE);
  for (i = 0 ; i < connectionIdx ; i++)
  {
    if (strcmp(databaseName,connections[i].databaseName) == 0 )
      return connections[i].connectionName;
  }
  return NULL;
  */
}


/**
 * Create an sql statement structure.
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
  EXEC SQL begin declare section;
    char *statementName;
    char *statementText;
  EXEC SQL end declare section;

  struct s_sid *sid = malloc(sizeof(struct s_sid));

  sid->select        = strdup(s);
  sid->ibind         = ibind;
  sid->ni            = ni;
  sid->obind         = obind;
  sid->no            = no;
  sid->statementName = strdup(getGlobalStatementName());

  statementName = sid->statementName;
  statementText = sid->select;
  return sid;
}

/**
 * Prepare an sql statement acording to the bindings and statement
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
  EXEC SQL begin declare section;
    char *statementName;
    char *statementText;
  EXEC SQL end declare section;

  struct s_sid *sid = newStatement(ibind,ni,obind,no,s);

  statementName = sid->statementName;
  statementText = sid->select;
  EXEC SQL PREPARE :statementName FROM :statementText;
  if ( isSqlError() )
  {
    free(sid);
    A4GLSQL_set_status(sqlca.sqlcode,1);
    return (struct s_sid *)0;
  }
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
struct s_sid *A4GLSQL_prepare_glob_sql (char *s, int ni, struct BINDING *ibind)
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
static getIfmxDataType(int dataType)
{
  return dataType;
}

/**
 * Bind the value to input descriptor entry.
 *
 * Part of this code is copied from DBD::Informix.
 *
 * @todo : Put the specifics of each ESQLC version just as LF done
 * in DBD.
 * @todo : Put the nulls working.
 * @todo : Implement the blob stuff
 * @todo : Terminate the data types.
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
  EXEC SQL begin declare section;
    char   *descriptorName = descName;
    int    index = idx+1;
    int    length;
    int    dataType;
    loc_t  blob;

    char     *char_var;
    int      smint_var, *smint_ptr;
    long     int_var, *int_ptr;
    double   float_var, *float_ptr;
    float    smfloat_var, *smfloat_ptr;
    dec_t    decimal_var;
    long     date_var;
    dec_t    money_var;
    dtime_t  dtime_var;
    intrvl_t interval_var;
    /*
    fglbyte byte_var;
    fgltext text_var;
    */
  EXEC SQL END DECLARE SECTION;
  fgldecimal  *fgl_decimal;
  FglDate     *fgl_date;
  fglmoney    *fgl_money;
  FglDatetime *fgl_dtime;
  FglInterval *fgl_interval;

  dataType = getIfmxDataType(bind[idx].dtype);
  length   = bind[idx].size;

  if ( isnull(dataType,bind[idx].ptr) )
  {
    EXEC SQL SET DESCRIPTOR :descriptorName  VALUE :index
      TYPE = :dataType,
      LENGTH = :length,
      INDICATOR = -1;
    if ( isSqlError() )
      return 1;
    return 0;
  }

  switch (dataType)
  {
    case DTYPE_CHAR:
    case DTYPE_VCHAR:
      char_var = bind[idx].ptr;
      EXEC SQL SET DESCRIPTOR :descriptorName  VALUE :index
        TYPE = :dataType,
        LENGTH = :length,
        DATA = :char_var;
      break;
    case DTYPE_SMINT:
      smint_ptr = (int *)bind[idx].ptr;
      smint_var = (int)*smint_ptr;
      EXEC SQL SET DESCRIPTOR :descriptorName  VALUE :index
        TYPE = :dataType,
        DATA = :smint_var;
      break;
    case DTYPE_INT:
      int_ptr = (long *)bind[idx].ptr;
      int_var = (long) *int_ptr;
      EXEC SQL SET DESCRIPTOR :descriptorName  VALUE :index
        TYPE = :dataType,
        DATA = :int_var;
      break;
    case DTYPE_FLOAT:
      float_ptr = (double *)bind[idx].ptr;
      float_var = (double)*float_ptr;
      EXEC SQL SET DESCRIPTOR :descriptorName  VALUE :index
        TYPE = :dataType,
        DATA = :float_var;
      break;
    case DTYPE_SMFLOAT:
      smfloat_ptr = (float *)bind[idx].ptr;
      smfloat_var = (float) *smfloat_ptr;
      EXEC SQL SET DESCRIPTOR :descriptorName  VALUE :index
        TYPE = :dataType,
        DATA = :smfloat_var;
      break;
    case DTYPE_DECIMAL:
      fgl_decimal = (fgldecimal *)bind[idx].ptr;
      if ( deccvasc(fgl_decimal->data,strlen(fgl_decimal->data),&decimal_var) )
      {
	/** @todo : We need to store this error */
        return 1;
      }
      EXEC SQL SET DESCRIPTOR :descriptorName  VALUE :index
        TYPE = :dataType,
        DATA = :decimal_var;
      break;
    case DTYPE_DATE:
      fgl_date = (long *)bind[idx].ptr;
      date_var = (long) *fgl_date;
      EXEC SQL SET DESCRIPTOR :descriptorName  VALUE :index
        TYPE = :dataType,
        DATA = :date_var;
      break;
    case DTYPE_MONEY:
      fgl_money = (fglmoney *)bind[idx].ptr;
      if ( deccvasc(fgl_money->data,strlen(fgl_money->data),&money_var) )
      {
	/** @todo : We need to store this error */
        return 1;
      }
      EXEC SQL SET DESCRIPTOR :descriptorName  VALUE :index
        TYPE = :dataType,
        DATA = :money_var;
      break;
    case DTYPE_DTIME:
      fgl_dtime = (FglDatetime *)bind[idx].ptr;
      if ( dtcvasc(fgl_dtime->data,&dtime_var) )
      {
	/** @todo : We need to store this error */
        return 1;
      }
      EXEC SQL SET DESCRIPTOR :descriptorName  VALUE :index
        TYPE = :dataType,
        DATA = :dtime_var;
      break;
    case DTYPE_INTERVAL:
      fgl_interval = (FglInterval *)bind[idx].ptr;
      if ( incvasc(fgl_interval->data,&interval_var) )
      {
	/** @todo : We need to store this error */
        return 1;
      }
      EXEC SQL SET DESCRIPTOR :descriptorName  VALUE :index
        TYPE = :dataType,
        DATA = :interval_var;
      break;
    case DTYPE_TEXT:
      break;
    case DTYPE_BYTE:
      break;
    default:
      exitwith ("Invalid data type\n");
  }
  if ( isSqlError() )
    return 1;
  return 0;
}

 
/**
 * Makes the bind of the input variables to pass to the statement to a 
 * global ESQL descriptor area.
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
  EXEC SQL begin declare section;
    char *descriptorName = descName;
    int  bindCount = bCount;
  EXEC SQL end declare section;
  register int i;

  EXEC SQL ALLOCATE DESCRIPTOR :descriptorName WITH MAX :bindCount;
  if ( isSqlError() )
  {
    return 1;
  }

  for ( i = 0 ; i < bindCount ; i++ )
    if ( bindInputValue(descriptorName,i,bind) == 1 )
      return 1;
  return 0;
}

/**
 * Bind the value to output descriptor entry.
 *
 * Part of this code is copied from DBD::Informix.
 *
 * @todo : Put the specifics of each ESQLC version just as LF done
 * in DBD.
 * @todo : Put the nulls working.
 * @todo : Implement the blob stuff
 * @todo : Terminate the data types.
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
  EXEC SQL begin declare section;
    char   *descriptorName = descName;
    int    index = idx+1;
    int    length;
    int    dataType;
    short  indicator;
    loc_t  blob;

    char     *char_var;
    int      smint_var;
    long     int_var;
    double   float_var;
    float    smfloat_var;
    dec_t    decimal_var;
    long     date_var;
    dec_t    money_var;
    dtime_t  dtime_var;
    intrvl_t interval_var;
    /*
    fglbyte byte_var;
    fgltext text_var;
    */
  EXEC SQL END DECLARE SECTION;
  FglDecimal  *fgl_decimal;
  FglMoney    *fgl_money;
  FglDatetime *fgl_dtime;
  FglInterval *fgl_interval;

  dataType = getIfmxDataType(bind[idx].dtype);
  length   = bind[idx].size;

  EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
    :indicator = INDICATOR, :length = LENGTH;
  if ( isSqlError() )
    return 1;
  if ( indicator == -1 )
  {
    setnull(dataType,bind[idx].ptr,length);
    return;
  }

  switch (dataType)
  {
    case DTYPE_CHAR:
    case DTYPE_VCHAR:
      EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
        :length = LENGTH;
      if ( isSqlError() )
        return 1;
      char_var = malloc(length + 1);
      EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
        :char_var = DATA;
      strcpy(bind[idx].ptr,char_var);
      free(char_var);
      break;
    case DTYPE_SMINT:
      EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
        :dataType = TYPE,
        :smint_var = DATA;
      if ( isSqlError() )
        return 1;
      *(int *)bind[idx].ptr = smint_var;
      break;
    case DTYPE_INT:
      EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
        :dataType = TYPE,
        :int_var = DATA;
      if ( isSqlError() )
        return 1;
      *(long *)bind[idx].ptr = int_var;
      break;
    case DTYPE_FLOAT:
      EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
        :dataType = TYPE,
        :float_var = DATA;
      if ( isSqlError() )
        return 1;
      *(double *)bind[idx].ptr = float_var;
      break;
    case DTYPE_SMFLOAT:
      EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
        :dataType = TYPE,
        :smfloat_var = DATA;
      if ( isSqlError() )
        return 1;
      *(float *)bind[idx].ptr = smfloat_var;
      break;
    case DTYPE_DECIMAL:
      EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
        :dataType = TYPE,
        :decimal_var = DATA;
      if ( isSqlError() )
        return 1;
      fgl_decimal = malloc(sizeof(fgldecimal));
      if ( dectoasc(&decimal_var,fgl_decimal->data,64,-1) )
      {
	/** @todo : Store the error somewhere */
        return 1;
      }
      (FglDecimal *)bind[idx].ptr = fgl_decimal;
      break;
    case DTYPE_DATE:
      EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
        :dataType = TYPE,
        :date_var = DATA;
      if ( isSqlError() )
        return 1;
      *(long *)bind[idx].ptr = date_var;
      break;
    case DTYPE_MONEY:
      EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
        :dataType = TYPE,
        :money_var = DATA;
      if ( isSqlError() )
        return 1;
      fgl_money = malloc(sizeof(fglmoney));
      if ( dectoasc(&money_var,fgl_money->data,64,-1) )
      {
	/** @todo : Store the error somewhere */
        return 1;
      }
      (fgldecimal *)bind[idx].ptr = fgl_decimal;
      break;
    case DTYPE_DTIME:
      EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
        :dataType = TYPE,
        :dtime_var = DATA;
      if ( isSqlError() )
        return 1;
      fgl_dtime = malloc(sizeof(FglDatetime));
      if ( dttoasc(&dtime_var,fgl_dtime->data) )
      {
	/** @todo : Store the error somewhere */
        return 1;
      }
      (FglDatetime *)bind[idx].ptr = fgl_dtime;
      break;
    case DTYPE_INTERVAL:
      EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
        :dataType = TYPE,
        :interval_var = DATA;
      if ( isSqlError() )
        return 1;
      fgl_interval = malloc(sizeof(FglInterval));
      if ( intoasc(&interval_var,fgl_interval->data) )
      {
	/** @todo : Store the error somewhere */
        return 1;
      }
      (FglInterval *)bind[idx].ptr = fgl_interval;
      break;
    case DTYPE_BYTE:
      break;
    case DTYPE_TEXT:
      break;
    default:
      exitwith ("Invalid data type\n");
  }
  if ( isSqlError() )
    return 1;
  return 0;
}

/**
 * Allocate the output descriptors because they must exist before the 
 * execution of the statement.
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
  EXEC SQL begin declare section;
    char *descriptorName = descName;
    int  bindCount = bCount;
  EXEC SQL end declare section;
  register int i;

  EXEC SQL ALLOCATE DESCRIPTOR :descriptorName WITH MAX :bindCount;
  if ( isSqlError() )
  {
    return 1;
  }
  return 0;
}
 
/**
 * Makes the bind of the input variables to pass to the statement to a 
 * global ESQL descriptor area.
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
  EXEC SQL begin declare section;
    char *descriptorName = descName;
    int  bindCount = bCount;
  EXEC SQL end declare section;
  register int i;

  for ( i = 0 ; i < bindCount ; i++ )
    if ( bindOutputValue(descriptorName,i,bind) == 1 )
      return 1;
  return 0;
}

/**
 * Generate the descriptor name.
 *
 * @param statementName The name of the statement to build descriptor name.
 * @param type The descriptor type:
 *   - I : Descriptor for input bind.
 *   - O : Descriptor for output bind.
 * @return The descriptor name.
 */
char *getDescriptorName(char *statementName,char bindType)
{
  char *descriptorName = malloc(sizeof(statementName+6));
  sprintf(descriptorName,"%s_%cbind",statementName,bindType);
  return descriptorName;
}

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
 * @todo : Assertions
 *
 * @param sid The statement information.
 * @return
 *  - 0 : Connection closed.
 *  - 1 : Connection does not exist or error ocurred.
 */
static int executeStatement(struct s_sid *sid)
{
  EXEC SQL begin declare section;
    char *statementName;
    char *inputDescriptorName;
    char *outputDescriptorName;
  EXEC SQL end declare section;
  int rc = 0;

  statementName        = sid->statementName;
  inputDescriptorName  = sid->inputDescriptorName;
  outputDescriptorName = sid->outputDescriptorName;
  switch (getStatementBindType(sid))
  {
    case NO_BIND:
      EXEC SQL EXECUTE :statementName;
      break;
    case INPUT_BIND:
      EXEC SQL EXECUTE :statementName 
        USING SQL DESCRIPTOR :inputDescriptorName;
      break;
    case OUTPUT_BIND:
      EXEC SQL EXECUTE :statementName 
        INTO SQL DESCRIPTOR :outputDescriptorName;
      break;
    case INPUT_OUTPUT_BIND:
      EXEC SQL EXECUTE :statementName 
        INTO SQL DESCRIPTOR :outputDescriptorName
        USING SQL DESCRIPTOR :inputDescriptorName;
      break;
    otherwise:
      exitwith ("Invalid bind\n");
  }

  if ( isSqlError() )
    rc = 1;

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
struct s_sid *A4GLSQL_prepare_sql (char *s)
{
  return(prepareSqlStatement((struct BINDING *)0,0,(struct BINDING *)0,0,s));
}

/**
 * Store the information of a prepared statement in a global data structure.
 *
 * @param pname The prepare statement name.
 * @param sid A pointer to the statement information.
 * @return Allways 0
 */
int A4GLSQL_add_prepare (char *pname, struct s_sid *sid)
{
  if (sid)
  {
    add_pointer (pname, PRECODE, sid);
    return 1;
  }
  else
  {
    return 0;
  }
}

/**
 * Not used.
 *
 * @param prepared statement name.
 * @param ni Number of binded input parameters.
 * @param The input bind array.
 * @return Allways 0
 */
int A4GLSQL_execute_sql_from_ptr(char *pname, int ni, char **ibind)
{
  return 0;
}

/**
 * Process the binds of a statement before the execution.
 *
 * the structure s_sid is expanded to have the descriptor names.
 * 
 * @param sid A pointer to the statement identification structure.
 * @return
 *  - 0 : Binds made.
 *  - 1 : Error making binds
 */
static int processPreStatementBinds(struct s_sid *sid)
{
  EXEC SQL BEGIN DECLARE SECTION;
    char *statementName;
    char *descriptorName;
  EXEC SQL END DECLARE SECTION;
  int rv = 0;
  if ( sid->ibind != (struct BINDING *)0 && sid->ni > 0 )
  {
    sid->inputDescriptorName = getDescriptorName(sid->statementName,'I');

    if ( processInputBind(sid->inputDescriptorName,sid->ni,sid->ibind) == 1)
      return 1;
  }

  if ( sid->obind != (struct BINDING *)0 && sid->no > 0 )
  {
    sid->outputDescriptorName = getDescriptorName(
      sid->statementName,
      'O'
    );

    rv = allocateOutputDescriptor(
      sid->outputDescriptorName,
      sid->no,
      sid->obind
    );
    if ( rv == 1)
      return 1;
    descriptorName = sid->outputDescriptorName;
    statementName  = sid->statementName;
    EXEC SQL DESCRIBE :statementName USING SQL DESCRIPTOR :descriptorName;
  }
  return 0;
}

/**
 * Dealocate the descriptors used in a statement.
 *
 * @param sid The statement information.
 * @return
 *  - 0 : Connection closed.
 *  - 1 : Connection does not exist or error ocurred.
 */
static int deallocateDescriptors(struct s_sid *sid)
{
  EXEC SQL begin declare section;
    char *descriptorName;
  EXEC SQL end declare section;
  int rc = 0;

  if ( sid->ibind != (struct BINDING *)0 && sid->ni > 0 )
  {
    descriptorName = sid->inputDescriptorName;
    EXEC SQL DEALLOCATE DESCRIPTOR :descriptorName;
    free(descriptorName);
  }
  if ( isSqlError() )
    rc = 1;

  if ( sid->obind != (struct BINDING *)0 && sid->no > 0 )
  {
    descriptorName = sid->outputDescriptorName;
    EXEC SQL DEALLOCATE DESCRIPTOR :descriptorName;
    free(descriptorName);
  }
  if ( isSqlError() )
    rc = 1;
  return rc;
}

/**
 * Process the binds of a statement after the execution.
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
 * @param sid The statement information that should be prepared.
 * @return
 *  - 0 : Connection closed.
 *  - 1 : Connection does not exist or error ocurred.
 *  - -1 : The pointer to the statement is null.
 */
int A4GLSQL_execute_implicit_select (struct s_sid *sid)
{
  EXEC SQL begin declare section;
    char *statementName;
    char *statementText;
  EXEC SQL end declare section;

  debug("ESQL : execute_implicit_select");
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
int A4GLSQL_execute_implicit_sql (struct s_sid *sid)
{
  EXEC SQL begin declare section;
    char *statementName;
    char *descriptorName;
    int  inputBindCount;
  EXEC SQL end declare section;
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
struct s_sid *A4GLSQL_prepare_select (
  struct BINDING *ibind, int ni, struct BINDING *obind, int no, char *s)
{
  return(prepareSqlStatement(ibind,ni,obind,no,s));
}


/**
 * Get the cursor type to be declared acording to the flags.
 *
 * @todo : Fix other cursor types.
 * @todo : Insert an assertion.
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
struct s_cid *A4GLSQL_declare_cursor(
  int upd_hold,struct s_sid *sid,int scroll,char *cursname)
{
  EXEC SQL BEGIN DECLARE SECTION;
    char *cursorName = cursname;
    char *statementName;
  EXEC SQL END DECLARE SECTION;
  int retval = 0;
  struct s_cid *cursorIdentification;

  if ( sid == (struct s_sid *)0 )
    return (struct s_cid *)0;

  cursorIdentification = malloc(sizeof(struct s_cid));
  cursorIdentification->statement = sid;
  statementName = sid->statementName;
  switch (getCursorType(upd_hold,scroll))
  {
    case SIMPLE:
      EXEC SQL DECLARE :cursorName CURSOR FOR :statementName;
      break;
    case SIMPLE_SCROLL:
      EXEC SQL DECLARE :cursorName SCROLL CURSOR FOR :statementName;
      break;
    case FOR_UPDATE:
      /** @todo : Fix the for update that hould be in prepared select */
      /*
      EXEC SQL DECLARE :cursorName CURSOR FOR :statementName FOR UPDATE;
      */
      break;
    case FOR_UPDATE_WITH_HOLD:
      /*
      EXEC SQL DECLARE :cursorName SCROLL CURSOR FOR :statementName
	WITH HOLD FOR UPDATE;
	*/
      break;
    case WITH_HOLD:
      EXEC SQL DECLARE :cursorName CURSOR WITH HOLD FOR :statementName;
      break;
    otherwise:
      /** @todo : Assign an error code  */
      return (struct s_cid *)0;
  }
  if ( isSqlError() )
    return (struct s_cid *)0;
  add_pointer (cursname, PRECODE, cursorIdentification);
  return cursorIdentification;
}


/**
 * Open a cursor already declared.
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
int A4GLSQL_open_cursor (int ni, char *s)
{
  EXEC SQL BEGIN DECLARE SECTION;
    char *cursorName = s;
  EXEC SQL END DECLARE SECTION;

  EXEC SQL OPEN :cursorName;
  if ( isSqlError() )
    return 1;
  return 0;
}


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
    if ( fetch_mode == FETCH_ABSOLUTE )
      return FETCH_FIRST;
    else if ( fetch_mode == FETCH_RELATIVE )
      return FETCH_NEXT;
    else
      exitwith ("Invalid cursor type");
  }

  if ( fetch_when == -1 )
  {
    if ( fetch_mode == FETCH_ABSOLUTE )
      return FETCH_LAST;
    else if ( fetch_mode == FETCH_RELATIVE )
      return FETCH_PREVIOUS;
    else
      exitwith ("Invalid cursor type");
  }

  if ( fetch_mode == FETCH_ABSOLUTE )
    return FETCH__ABSOLUTE;

  if ( fetch_mode == FETCH_RELATIVE )
    return FETCH__RELATIVE;
  exitwith ("Invalid cursor type");
  return -1;
}

/**
 * Fetch a cursor into the binding variables.
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
int A4GLSQL_fetch_cursor (char *cursor_name,
		      int fetch_mode, int fetch_when, int nobind,
		      struct BINDING *obind)
{
  EXEC SQL BEGIN DECLARE SECTION;
    char *cursorName = cursor_name;
    char *descriptorName;
    int position = fetch_when;
  EXEC SQL END DECLARE SECTION;
  struct s_sid *sid;
  struct s_cid *cid;

  cid = (struct s_cid *)find_pointer_val (cursorName, PRECODE);
  sid = (struct s_sid *) cid->statement;
  if ( sid == (struct s_sid *)0 )
  {
    /** @todo : Proper error handling */
    return 1;
  }

  sid->obind = obind;
  sid->no = nobind;
  /** @todo : Maybe input bind should be cleaned (if exist) */
  if ( processPreStatementBinds(sid) == 1 )
    return 1;
  descriptorName = sid->outputDescriptorName;

  switch (getFetchType(fetch_mode,fetch_when))
  {
    case FETCH_FIRST:
      EXEC SQL FETCH FIRST :cursorName USING SQL DESCRIPTOR :descriptorName;
      break;
    case FETCH_LAST:
      EXEC SQL FETCH LAST :cursorName USING SQL DESCRIPTOR :descriptorName;
      break;
    case FETCH_NEXT:
      EXEC SQL FETCH NEXT :cursorName USING SQL DESCRIPTOR :descriptorName;
      break;
    case FETCH_PREVIOUS:
      EXEC SQL FETCH PREVIOUS :cursorName USING SQL DESCRIPTOR :descriptorName;
      break;
    case FETCH_CURRENT:
      EXEC SQL FETCH CURRENT :cursorName USING SQL DESCRIPTOR :descriptorName;
      break;
    case FETCH__RELATIVE:
      EXEC SQL FETCH RELATIVE :position :cursorName 
        USING SQL DESCRIPTOR :descriptorName;
      break;
    case FETCH__ABSOLUTE:
      EXEC SQL FETCH ABSOLUTE :position :cursorName 
        USING SQL DESCRIPTOR :descriptorName;
      break;
    otherwise:
      exitwith ("Invalid fetch");
  }
  if ( isSqlError() )
    return 1;
  if ( isNotFound() )
    return 0;
  if ( processPosStatementBinds(sid) == 1 )
    return 1;
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
/* 	void A4GLSQL_put_insert(struct BINDING *ibind,int n); */
/* int */
void
A4GLSQL_put_insert (struct BINDING *ibind, int n)
{
  /*
  if ( ibind != (struct BINDING *)0 && nibind > 0 )
  {
    descriptorName = getDescriptorName(statementName,'I');

    if ( processInputBind(descriptorName,nibind,ibind) == 1)
      exitwith ("Error binding");
  }
  */
  /* EXEC SQL PUT :cursorName FROM :state */
}

/**
 * Print the information to the file acording to the data type
 * 
 * @param unloadFile A pointer to the opened unload file
 * @param idx The index of the column to be printed
 * @return 
 *   - 1 : An error as ocurred.
 *   - 0 : Field printed.
 */
static int printField(FILE *unloadFile,int idx,char *descName)
{
  EXEC SQL BEGIN DECLARE SECTION;
    int dataType;
    int index = idx;
    short indicator;

    char   *descriptorName = descName;
    int    length;
    loc_t  blob;

    char     *char_var;
    int      smint_var;
    long     int_var;
    double   float_var;
    float    smfloat_var;
    dec_t    decimal_var;
    long     date_var;
    dec_t    money_var;
    dtime_t  dtime_var;
    intrvl_t interval_var;
    /*
    fglbyte byte_var;
    fgltext text_var;
    */
  EXEC SQL END DECLARE SECTION;
  FglDecimal  *fgl_decimal;
  FglMoney    *fgl_money;
  FglDatetime *fgl_dtime;
  FglInterval *fgl_interval;
  int rc = 0;

  EXEC SQL GET DESCRIPTOR 'descUnload'  VALUE :index
    :indicator = INDICATOR, :dataType = TYPE;
        
  if (indicator == -1) 
  {
    return 0;
  } 

  switch (dataType)
  {
    case DTYPE_CHAR:
    case DTYPE_VCHAR:
      EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
        :length = LENGTH;
      if ( isSqlError() )
      {
        rc = 1;
	break;
      }
      char_var = malloc(length + 1);
      EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
        :char_var = DATA;
      trim(char_var);
      fprintf(unloadFile,"%s",char_var);
      free(char_var);
      break;
    case DTYPE_SMINT:
      EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
        :dataType = TYPE,
        :smint_var = DATA;
      if ( isSqlError() )
      {
        rc = 1;
	break;
      }
      fprintf(unloadFile,"%d",smint_var);
      break;
    case DTYPE_INT:
      EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
        :dataType = TYPE,
        :int_var = DATA;
      if ( isSqlError() )
      {
        rc = 1;
	break;
      }
      fprintf(unloadFile,"%ld",int_var);
      break;
    case DTYPE_FLOAT:
      EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
        :dataType = TYPE,
        :float_var = DATA;
      if ( isSqlError() )
      {
        rc = 1;
	break;
      }
      fprintf(unloadFile,"%lf",float_var);
      break;
    case DTYPE_SMFLOAT:
      EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
        :dataType = TYPE,
        :smfloat_var = DATA;
      if ( isSqlError() )
      {
        rc = 1;
	break;
      }
      fprintf(unloadFile,"%f",smfloat_var);
      break;
    case DTYPE_DECIMAL:
      EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
        :dataType = TYPE,
        :decimal_var = DATA;
      if ( isSqlError() )
      {
        rc = 1;
	break;
      }
      fgl_decimal = malloc(sizeof(fgldecimal));
      if ( dectoasc(&decimal_var,fgl_decimal->data,64,-1) )
      {
	/** @todo : Store the error somewhere */
        return 1;
      }
      fprintf(unloadFile,"%s",fgl_decimal->data);
      free(fgl_decimal);
      break;
    case DTYPE_DATE:
      EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
        :dataType = TYPE,
        :date_var = DATA;
      if ( isSqlError() )
      {
        rc = 1;
	break;
      }
      /** @todo : Print as date field */
      char_var = malloc(sizeof(char)*10);
      dtos(&date_var,char_var,10);
      fprintf(unloadFile,"%s",char_var);
      free(char_var);
      break;
    case DTYPE_MONEY:
      EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
        :dataType = TYPE,
        :money_var = DATA;
      if ( isSqlError() )
      {
        rc = 1;
	break;
      }
      fgl_money = malloc(sizeof(fglmoney));
      if ( dectoasc(&money_var,fgl_money->data,64,-1) )
      {
	/** @todo : Store the error somewhere */
        return 1;
      }
      fprintf(unloadFile,"%s",fgl_money->data);
      free(fgl_money);
      break;
    case DTYPE_DTIME:
      EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
        :dataType = TYPE,
        :dtime_var = DATA;
      if ( isSqlError() )
      {
        rc = 1;
	break;
      }
      fgl_dtime = malloc(sizeof(FglDatetime));
      if ( dttoasc(&dtime_var,fgl_dtime->data) )
      {
	/** @todo : Store the error somewhere */
        return 1;
      }
      fprintf(unloadFile,"%s",fgl_dtime->data);
      free(fgl_dtime);
      break;
    case DTYPE_INTERVAL:
      EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
        :dataType = TYPE,
        :interval_var = DATA;
      if ( isSqlError() )
      {
        rc = 1;
	break;
      }
      fgl_interval = malloc(sizeof(FglInterval));
      if ( intoasc(&interval_var,fgl_interval->data) )
      {
	/** @todo : Store the error somewhere */
        return 1;
      }
      fprintf(unloadFile,"%s",fgl_interval->data);
      free(fgl_interval);
      break;
    case DTYPE_BYTE:
      break;
    case DTYPE_TEXT:
      break;
    default:
      exitwith ("Invalid data type\n");
  }
  return 0;
}

/**
 * Unload the data to a file acording to SQL statemement with
 * columns separated by a delimiter.
 *
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
/* 	void A4GLSQL_unload_data(char *fname,char *delims, char *sql1); */
/* int */
void
A4GLSQL_unload_data (char *fname, char *delims, char *sqlStr)
{
  int cnt=0;
  static char databuf[64000];
  FILE *unloadFile;
  int rc = 0;

  EXEC SQL BEGIN DECLARE SECTION;
    char *strSql = sqlStr;
    short numberOfColumns;
    int colcnt;
    int coltype;
  EXEC SQL END DECLARE SECTION;

  unloadFile = (FILE *)mja_fopen(fname,"wt");
  if ( unloadFile == (FILE *)0 )
  {
    /** @todo : Generate some error code compatible with informix 4gl */
    return; /* return 1; */
  }

  EXEC SQL PREPARE stUnload FROM :strSql;
  if ( isSqlError() )
    return; /* return 1; */

  EXEC SQL ALLOCATE DESCRIPTOR 'descUnload';
  if ( isSqlError() )
    return; /* return 1; */

  EXEC SQL DESCRIBE stUnload USING SQL DESCRIPTOR 'descUnload';
  if ( isSqlError() )
  {
    EXEC SQL DEALLOCATE DESCRIPTOR 'descUnload';
    return; /* return 1; */
  }

  EXEC SQL GET DESCRIPTOR 'descUnload' :numberOfColumns = COUNT;
  if ( isSqlError() )
  {
    EXEC SQL DEALLOCATE DESCRIPTOR 'descUnload';
    return; /* return 1; */
  }

  EXEC SQL DECLARE crUnload CURSOR FOR stUnload;
  if ( isSqlError() )
  {
    EXEC SQL DEALLOCATE DESCRIPTOR 'descUnload';
    return; /* return 1; */
  }

  EXEC SQL OPEN crUnload;
  if ( isSqlError() )
  {
    EXEC SQL DEALLOCATE DESCRIPTOR 'descUnload';
    return; /* return 1; */
  }

  // Get the data
  while (1)
  {
    EXEC SQL FETCH crUnload USING SQL DESCRIPTOR 'descUnload';
    if ( isSqlError() )
    {
      EXEC SQL DEALLOCATE DESCRIPTOR 'descUnload';
      return; /* return 1; */
    }
    if ( strcmp(SQLSTATE,"02000") == 0 )
      break;

    cnt++;
    for ( colcnt = 1; colcnt <= numberOfColumns; colcnt++) 
    {
      if ( printField(unloadFile,colcnt,"descUnload") == 1 )
      {
        rc = 1;
	break;
      }
      fprintf(unloadFile,"%c",delims[0]);
    }
    fprintf(unloadFile,"\n");
  }
  fclose(unloadFile);
  sqlca.sqlerrd[1]=cnt;
  EXEC SQL FREE stUnload;
  EXEC SQL FREE crUnload;
  EXEC SQL DEALLOCATE DESCRIPTOR 'descUnload';
  if ( isSqlError() )
    rc = 1;
  return; /* return 0; */
}

/**
 * Implementationin ODBC of the transaction statements (BEGIN WORK, 
 * COMMIT WORK, ROLLBACK WORK).
 *
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
/* 	void A4GLSQL_commit_rollback (int mode);*/
/* int */
void
A4GLSQL_commit_rollback (int mode)
{
  debug ("In commit_rollback");

  switch (mode)
  {
    case -1:
      EXEC SQL BEGIN WORK;
      break;
    case 0:
      EXEC SQL ROLLBACK WORK;
      break;
    case 1:
      EXEC SQL COMMIT WORK;
      break;
  }
/*
  if ( isSqlError() )
    return 1;
  return 0;
*/
}

/**
 * Find a prepared statement.
 *
 * There should be a global strucutre or array where to store all the
 * prepared statements.
 *
 * @todo : The mode should be used for something.
 *
 * @param pname The statement name.
 * @param mode
 * @return 
 *   - A pointer to the structure found in the tree.
 *   - 0 : The structure was not found
 */
struct s_sid *A4GLSQL_find_prepare (char *pname)
{
  struct s_sid *ptr;

  set_errm (pname);
  ptr = (struct s_sid *)find_pointer_val (pname, PRECODE);
  if (ptr)
    return ptr;
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
/* 	void A4GLSQL_flush_cursor(char *cursor); */
/* int */
void
A4GLSQL_flush_cursor (char *cursor)
{
  EXEC SQL BEGIN DECLARE SECTION;
    char *cursorName = cursor;
  EXEC SQL END DECLARE SECTION;

  EXEC SQL FLUSH :cursorName;
/*
  if ( isSqlError() )
    return 1;
  return 0;
*/
}

/**
 * Execute an allready preparted SQL statement.
 *
 * @param pname  The prepared statement name.
 * @param ni Number of elements in the input bind.
 * @param ibind The input binding array used.
 * @return
 *   - 0 : SQL statement executed.
 *   - 1 : There was an error.
 */
int A4GLSQL_execute_sql (char *pname, int ni, struct BINDING *ibind)
{
  struct s_sid *sid;

  debug("ESQL : A4GLSQL_execute_sql");
  /** @todo : Fix the mode that is not used now  - done remove comment */
  sid = A4GLSQL_find_prepare (pname); // ,0
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
/*
B
B
B
*/
/* Bad Blue Boys ? - No wrong termtype...(oops) */

/* int A4GLSQL_get_columns (char *tabname, char *colname, int *dtype, int *size); */
/* int A4GLSQL_get_columns(char *tabname) */
int
A4GLSQL_get_columns (char *tabname, char *colname, int *dtype, int *size)
{
  EXEC SQL BEGIN DECLARE SECTION;
    char strSelect[640];
    int numberOfColumns;
  EXEC SQL END DECLARE SECTION;

  sprintf(strSelect,"select * from %s\n",tabname);
  EXEC SQL PREPARE stReadAllColumns FROM :strSelect;
  if ( isSqlError() )
  {
    return 0;
  }

  EXEC SQL ALLOCATE DESCRIPTOR 'descReadAllColumns';
  if ( isSqlError() )
  {
    return 0;
  }

  EXEC SQL DESCRIBE stReadAllColumns USING SQL DESCRIPTOR 'descReadAllColumns';
  if ( isSqlError() )
  {
    return 0;
  }

  EXEC SQL GET DESCRIPTOR 'descReadAllColumns' :numberOfColumns = COUNT;
  if ( isSqlError() )
  {
    return 0;
  }

  getColumnsMax = numberOfColumns;
  getColumnsOrder = 1;
  return 1;
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
/* int A4GLSQL_next_column(char **colname, int *dtype,int *size); */
/* int A4GLSQL_next_column(char *colname, int *dtype,int *size) */
int 
A4GLSQL_next_column(char **colname, int *dtype,int *size)
{
  EXEC SQL BEGIN DECLARE SECTION;
    int idx = getColumnsOrder;
    int dataType;
    int length;
    char columnName[64];
  EXEC SQL END DECLARE SECTION;

  if ( idx > getColumnsMax )
    return 0;

  EXEC SQL GET DESCRIPTOR 'descReadAllColumns' VALUE :idx
    :columnName = NAME, :dataType = TYPE, :length = LENGTH;
  if ( isSqlError() )
    return 0;
  *dtype = dataType;
  *size = length;
  strcpy((char *)colname,columnName);
  getColumnsOrder++;
  return 1;
}

/**
 * Free all resources allocated in getting information about columns
 * 
 * @return 
 *   - 0 : Descriptor dealocated
 *   - 1 : Error ocurred.
 */
int A4GLSQL_end_get_columns(void)
{
  EXEC SQL DEALLOCATE DESCRIPTOR 'descReadAllColumns';
  if ( isSqlError() )
  {
    return 0;
  }
  return 1;
}


/**
 * Gets information about columns from a table in the database engine.
 *
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
static int getSQLDataType(char *connName, char *tabname,char *colname,
  int *dtype,int *size)
{
  EXEC SQL BEGIN DECLARE SECTION;
    char strSelect[640];
    int dataType;
    int length;
  EXEC SQL END DECLARE SECTION;

  sprintf(strSelect,"select %s from %s",colname,tabname);
  EXEC SQL PREPARE stReadColumns FROM :strSelect;
  if ( isSqlError() )
  {
    return 1;
  }

  EXEC SQL ALLOCATE DESCRIPTOR 'descReadColumns';
  if ( isSqlError() )
  {
    return 1;
  }

  EXEC SQL DESCRIBE stReadColumns USING SQL DESCRIPTOR 'descReadColumns';
  if ( isSqlError() )
  {
    EXEC SQL DEALLOCATE DESCRIPTOR 'descReadColumns';
    return 1;
  }

  EXEC SQL GET DESCRIPTOR 'descReadColumns' VALUE 0
    :dataType = TYPE, :length = LENGTH;
  if ( isSqlError() )
  {
    EXEC SQL DEALLOCATE DESCRIPTOR 'descReadColumns';
    return 1;
  }
  EXEC SQL DEALLOCATE DESCRIPTOR 'descReadColumns';
  if ( isSqlError() )
  {
    return 1;
  }
  *dtype = dataType;
  *size = length;
  return 0;
}

/**
 * Gets information about columns from a table in the database engine.
 *
 * Aparently the compiler is waiting for an iteration in the columns of a
 * table.
 *
 * @todo : Put this working with .*
 * @todo : Use the getSQLDataType()
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
int A4GLSQL_read_columns(char *tabname,char *colname,int *dtype,int *size)
{
  EXEC SQL BEGIN DECLARE SECTION;
    char strSelect[640];
    int dataType;
    int length;
  EXEC SQL END DECLARE SECTION;

  sprintf(strSelect,"select %s from %s",colname,tabname);
  EXEC SQL PREPARE stXReadColumns FROM :strSelect;
  if ( isSqlError() )
  {
    return 0;
  }

  EXEC SQL ALLOCATE DESCRIPTOR 'descReadColumns';
  if ( isSqlError() )
  {
    return 0;
  }

  EXEC SQL DESCRIBE stXReadColumns USING SQL DESCRIPTOR 'descReadColumns';
  if ( isSqlError() )
  {
    EXEC SQL DEALLOCATE DESCRIPTOR 'descReadColumns';
    return 0;
  }

  EXEC SQL GET DESCRIPTOR 'descReadColumns' VALUE 1
    :dataType = TYPE, :length = LENGTH;
  if ( isSqlError() )
  {
    EXEC SQL DEALLOCATE DESCRIPTOR 'descReadColumns';
    return 0;
  }
  EXEC SQL DEALLOCATE DESCRIPTOR 'descReadColumns';
  if ( isSqlError() )
  {
    return 0;
  }
  *dtype = dataType;
  *size = length;
  return 1;
}

/**
 * Get the datatype of a column in the database engine.
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
int A4GLSQL_get_datatype (char *db, char *tab, char *col)
{
  int dataType;
  int length;
  char *connectionName;

  connectionName = getConnectionForDatabase(db);
  if ( connectionName == NULL )
    return -1;

  if ( getSQLDataType(connectionName,tab,col,&dataType,&length) == 1 )
    return -1;
  return dataType;
}

/**
 * Close a cursor opened.
 *
 * @param currname The name of the cursor.
 * @return
 */
int A4GLSQL_close_cursor(char *currname)  
{
  EXEC SQL BEGIN DECLARE SECTION;
    char *cursorName = currname;
  EXEC SQL END DECLARE SECTION;

  EXEC SQL CLOSE :cursorName;
  if ( isSqlError() )
    return 1;
  return 0;
}

/**
 * @todo : Understand if this function is used.
 */
int
A4GLSQL_fill_array (int mx, char **arr1, int szarr1, char **arr2, int szarr2,
		    char *service, int mode, char *info)
{
  exitwith ("Could not fill_array - noODBC build");
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
/* 	void A4GLSQL_set_sqlca_sqlcode(int a); */
/* int */
void
A4GLSQL_set_sqlca_sqlcode (int a)
{
  status = a;
  sqlca.sqlcode = a;
  /* return 0; */
}

/**
 * Describe an sql statement.
 *
 * @todo : Understand where this is used.
 *
 * @param stmt The text with the statement to be described.
 * @param colno
 * @param type The type of the information wanted.
 * @return
 */
long A4GLSQL_describe_stmt (char *stmt, int colno, int type)
{
  printf("Describe smtm\n");
}


/* ================================= EOF ============================== */

