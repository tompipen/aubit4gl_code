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
# $Id: esql.ec,v 1.76 2004-03-09 08:36:59 mikeaubury Exp $
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
 * .dll in windows).
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

//Not referenced anywhere:
//#define DEFINE_SQLCA

/** Informix ESQL/C database connector type */
#define ESQL_CONNECTOR   0

//Prevent Aubit headers from definig sqlc record; we will use the one
//provided in Informix headers instead.
//WARNING: Since sqlca is used in many places in Aubit code, is this safe?
#define _SQLCA_DEFINED_


//#ifndef __QUERIX__
$include sqlca;
//#else
//not sure about this:
//$include qxdefs.h;
//#endif

#include "a4gl_incl_4gldef.h"

extern sqlca_struct a4gl_sqlca;

#if defined (WIN32) || defined (__CYGWIN__)
#define _NO_FORM_H_
#define _NO_CURSES_H_
#define _NO_PANEL_H_
#define _NO_CURSLIB_H_
#define FORMXW			/* form_x.h */
#define _NO_DBFORM_H_
#endif

#define INPUT_OUTPUT_BIND 		0
#define INPUT_BIND        		1
#define OUTPUT_BIND       		2
#define NO_BIND           		3


#define SIMPLE                	0
#define SIMPLE_SCROLL         	1
#define FOR_UPDATE            	2
#define FOR_UPDATE_WITH_HOLD  	3
#define WITH_HOLD             	4

#define FETCH_FIRST    			0
#define FETCH_LAST      		1
#define FETCH_NEXT      		2
#define FETCH_PREVIOUS  		3
#define FETCH_CURRENT   		4
#define FETCH__RELATIVE 		5
#define FETCH__ABSOLUTE 		6


/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_lib_sql_esqlc_int.h"

static error_just_in_case ();
static int processPreStatementBinds (struct s_sid *sid);


EXEC SQL include sqlca;


/*
=====================================================================
                    Variables definitions
=====================================================================
*/

#ifndef lint
static const char rcs[] =
  "@(#)$Id: esql.ec,v 1.76 2004-03-09 08:36:59 mikeaubury Exp $";
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
typedef struct
{
  char *connectionName;	/**< The name of the connection - This is unique */
  char *databaseName;	/**< The name of the database */
  char connector;	/**< The aubit connector used */
  char *userName;	/**< User name used for estabilishing the connection */
  char *password;	/**< The password used to connect */
  void *connectionInfo;	/**< A pointer to a connector specific information */
}
DbConnection;

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
static void
esqlErrorHandler (void)
{
  A4GL_debug ("In esqlErrorHandler..");
  A4GLSQL_set_status (sqlca.sqlcode, 1);
}

/**
 * Handle the ocurrence of sql warnings.
 */
static void
esqlWarningHandler (void)
{
}

/**
 * Check if there was an sql error. Uses ESQL/C XOpen global variable SQLSTATE.
 *
 * @return 
 *   - 1 : An sql error was ocurred.
 *   - 0 : No error
 */
static int
isSqlError ()
{
  A4GL_set_a4gl_sqlca_sqlcode (sqlca.sqlcode);
  if (SQLSTATE[0] != '0' || (SQLSTATE[1] != '0' &&
			     SQLSTATE[1] != '1' && SQLSTATE[1] != '2'))
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
static int
isNotFound ()
{
  if (strcmp (SQLSTATE, "02000") == 0)
    {
      A4GLSQL_set_status (100, 1);
      return 1;
    }
  return 0;
}

/**
 * Get the status value.
 *
 * @return The value to be assigned to status.
 */
int
A4GLSQL_get_status (void)
{
  return sqlca.sqlcode;
}

/**
 * Get the current SQL error message.
 *
 * @return The contents of sqlca.sqlerrm.
 */
char *
A4GLSQL_get_sqlerrm (void)
{
  EXEC SQL BEGIN DECLARE SECTION;
  char *msg = (char *) malloc (8191);
  EXEC SQL END DECLARE SECTION;

  EXEC SQL get diagnostics exception 1:msg = MESSAGE_TEXT;
  return msg;
}

/**
 * Initialization of the sql library.
 *
 * Just initialize the error handling.
 */
/* void *//* int A4GLSQL_initsqllib(void); *//* << from sql.c */
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
static char *
getGlobalStatementName (void)
{
  static char statementName[10];

  statementCount++;
  sprintf (statementName, "st_%d", statementCount);
  return statementName;
}

/*  =================== Connection manager =================== */

/**
 * Create a new DbConnection object.
 *
 * @return A pointer to the connecion allocated.
 */
static DbConnection *
NewDbConnection ()
{
  DbConnection *connection;

  connection = (DbConnection *) malloc (sizeof (DbConnection));
  return connection;
}

/**
 * Gets the current connection information.
 *
 * @return The current connection.
 */
static DbConnection *
getCurrentESQLConnection (void)
{
  DbConnection *currConnection;

  if (currentConnection == NULL)
    return (DbConnection *) 0;
  currConnection = (DbConnection *) A4GL_find_pointer_val (currentConnection,
							   SESSCODE);

  return currConnection;
}

/**
 * Gets the name of the current connection.
 *
 * @return The name of the current connection.
 */
static char *
getCurrentESQLConnectionName (void)
{
  return currentConnection;
}

/**
 * Mark a connection as current.
 *
 * @param connectionName The name of the connection to be current.
 */
static int
setCurrentESQLConnection (char *connectionName)
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
static int
removeESQLConnection (char *connectionName)
{
  if (!A4GL_has_pointer (connectionName, SESSCODE))
    return 1;

  A4GL_del_pointer (connectionName, CURCODE);
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
static int
addESQLConnection (char *connectionName, char *dbName,
		   char *userName, char *passwd)
{
  DbConnection *connection;
  if (A4GL_has_pointer (connectionName, SESSCODE))
    return 1;
  connection = NewDbConnection ();
  connection->connectionName = strdup (connectionName);
  connection->databaseName = strdup (dbName);
  connection->connector = ESQL_CONNECTOR;
  connection->userName = userName;
  connection->password = passwd;
  connection->connectionInfo = 0;
  A4GL_add_pointer (connectionName, SESSCODE, connection);
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
int
A4GLSQL_init_connection_internal (char *dbName)
{
  static int have_connected = 0;
  char buff[256];

  EXEC SQL BEGIN DECLARE SECTION;
  char *db;
  EXEC SQL END DECLARE SECTION;

  strcpy (buff, dbName);
  A4GL_trim (buff);
  db = buff;
  A4GL_debug ("-->%s<--\n", buff);

// Have we got an active db session ?
  if (have_connected)
    {
      EXEC SQL DISCONNECT 'default';
      removeESQLConnection ("default");
      // Not any more we haven't...
    }

  EXEC SQL connect to:db as "default";

  A4GL_debug ("Sqlca=%d", sqlca.sqlcode);

  if (isSqlError ())
    return 1;

  addESQLConnection ("default", dbName, NULL, NULL);
  have_connected = 1;

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
int
A4GLSQL_close_session_internal (char *sessname)
{
  EXEC SQL begin declare section;
  char *connectionName = sessname;
  EXEC SQL end declare section;

  if (connectionName == NULL)
    {
      EXEC SQL DISCONNECT DEFAULT;
    }
  else
    {
      EXEC SQL DISCONNECT:connectionName;
      removeESQLConnection (connectionName);
    }
  if (isSqlError ())
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
int
A4GLSQL_close_connection (void)
{
  return A4GLSQL_close_session ("default");
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
  (char * server, char * uid_p, char * pwd_p)
{
  EXEC SQL begin declare section;
  char *dbName;
  char *userName;
  char *passwd;
  EXEC SQL end declare section;
  int retval = 0;

  dbName = strdup (server);
  userName = strdup (uid_p);
  passwd = strdup (pwd_p);	//Querix esql/c compiler chokes here....
  EXEC SQL connect to:dbName as 'default' user:userName using:passwd;
  if (isSqlError ())
    retval = 1;
  else
    addESQLConnection ("default", dbName, userName, passwd);
  free (dbName);
  free (userName);
  free (passwd);
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
static char *
initUser (const char *userName)
{
  char *retUser;
  if (userName != NULL)
    return strdup (userName);
  /** @todo : Confirm if this should be the env var name to be used */
  retUser = (char *) acl_getenv ("SQLUID");
  if (retUser != NULL)
    return strdup (retUser);
  return retUser;
}

/**
 * Decide wich password to use acording to the define value and environment.
 *
 * @param passwd The password to check.
 * @return The password choosed.
 */
static char *
initPassword (const char *passwd)
{
  char *retPasswd;
  if (passwd != NULL)
    return strdup (passwd);
  /** @todo : Confirm if this should be the env var name to be used */
  retPasswd = (char *) acl_getenv ("SQLPWD");
  if (retPasswd != NULL)
    return strdup (retPasswd);
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
int
A4GLSQL_init_session_internal (char *sessname, char *dsn, char *usr, char *pwd)
{
  EXEC SQL begin declare section;
  char *dbName = dsn;
  char *userName;
  char *password;
  char *connectionName = sessname;
  EXEC SQL end declare section;
  int retval = 0;

  if (dsn == NULL)
    {
      A4GL_exitwith ("Database name not seted");
      return 1;
    }


  /** @todo : Even if the connection exist it should not be the default one */
  /* See if its allready opened. */
  EXEC SQL set connection:connectionName;
  if (SQLSTATE[0] == '0' && (SQLSTATE[1] == '0' ||
			     SQLSTATE[1] == '1' || SQLSTATE[1] == '2'))
    {
      A4GL_exitwith ("Session already opened");
      return 1;
    }

  /* Treat the user and password precedence. */
  userName = initUser (usr);
  password = initPassword (pwd);

  if (connectionName == NULL)
    {
      EXEC SQL CONNECT TO DEFAULT;
    }
  else
    {
      if (userName == NULL || password == NULL)
	EXEC SQL connect to:dbName as:connectionName;
      else
	{
	  EXEC SQL connect to:dbName as:connectionName
	    user:userName using:password;
	  free (userName);
	  free (password);
	}
    }

  if (isSqlError ())
    retval = 1;
  else
    addESQLConnection ("default", dbName, userName, password);
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
int
A4GLSQL_set_conn_internal (char *sessname)
{
  EXEC SQL begin declare section;
  char *connectionName = sessname;
  EXEC SQL end declare section;
  int retval = 0;

  if (connectionName == NULL)
    EXEC SQL SET CONNECTION DEFAULT;
  else
  EXEC SQL SET CONNECTION:connectionName;
  if (isSqlError ())
    retval = 1;
  else
    setCurrentESQLConnection (connectionName);
  return retval;
}

/**
 * Gets the name of the current connection.
 *
 * @todo : Implement the mechanism.
 *
 * @return The current connection name.
 */
char *
A4GLSQL_get_curr_conn (void)
{
  return getCurrentESQLConnectionName ();
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
char *
A4GLSQL_get_currdbname (void)
{
  DbConnection *currConnection;

  currConnection = getCurrentESQLConnection ();
  if (currConnection == (DbConnection *) 0)
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
static char *
getConnectionForDatabase (char *databaseName)
{
  register int i;

  /*
     This is not working.
     For doing this i need an iterator trough the tree.
     hh = A4GL_find_pointer_val ("default", SESSCODE);
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
static struct s_sid *
newStatement (struct BINDING *ibind, int ni, struct BINDING *obind, int no,
	      char *s)
{
  EXEC SQL begin declare section;
  char *statementName;
  char *statementText;
  EXEC SQL end declare section;

  struct s_sid *sid = malloc (sizeof (struct s_sid));

  sid->select = strdup (s);
  sid->ibind = ibind;
  sid->ni = ni;
  sid->obind = obind;
  sid->no = no;
  sid->statementName = strdup (getGlobalStatementName ());
  sid->inputDescriptorName = 0;
  sid->outputDescriptorName = 0;

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
static struct s_sid *
prepareSqlStatement (struct BINDING *ibind, int ni, struct BINDING *obind,
		     int no, char *s)
{
  EXEC SQL begin declare section;
  char *statementName;
  char *statementText;
  EXEC SQL end declare section;
  char *s_internal;
  struct s_sid *sid = newStatement (ibind, ni, obind, no, s);
  s_internal = strdup (s);
  A4GL_trim (s_internal);
  A4GL_debug ("PrepareSQL : %s", s_internal);
  free (s_internal);

  statementName = sid->statementName;
  statementText = sid->select;
  EXEC SQL PREPARE:statementName FROM:statementText;
  if (isSqlError ())
    {
      free (sid);
      A4GLSQL_set_status (sqlca.sqlcode, 1);
      return (struct s_sid *) 0;
    }

  //if ( processPreStatementBinds(sid) == 1 ) {
  //debug("processPreStatementBinds failed ?");
  //error_just_in_case();
  //return 0;
  //}
  A4GL_debug ("Prepared OK\n");
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
void *
A4GLSQL_prepare_glob_sql_internal (char *s, int ni, void *vibind) 
{
  struct s_sid *ptr;
  struct BINDING *ibind;
  ibind=vibind;
  A4GL_debug ("S=%s\n", s);
  ptr = prepareSqlStatement (ibind, ni, (struct BINDING *) 0, 0, s);
  A4GL_debug ("Got ptr as %p", ptr);
  return ptr;
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
static
getIfmxDataType (int dataType)
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
static int
bindInputValue (char *descName, int idx, struct BINDING *bind)
{
  static const char function[] = "bindInputValue";
  EXEC SQL begin declare section;
  char *descriptorName = descName;
  int index = idx + 1;
  int length;
  int dataType;
  loc_t blob;

  char *char_var;
  short smint_var, *smint_ptr;
  long int_var, *int_ptr;
  double float_var, *float_ptr;
  float smfloat_var, *smfloat_ptr;
  dec_t decimal_var;
  long date_var;
  dec_t money_var;
  dtime_t dtime_var;
  //datetime year to second dtime_var;
  intrvl_t interval_var;
  /*
     fglbyte byte_var;
     fgltext text_var;
   */

  EXEC SQL END DECLARE SECTION;
  fgldecimal *fgl_decimal;
  FglDate *fgl_date;
  fglmoney *fgl_money;
  FglDatetime *fgl_dtime;
  FglInterval *fgl_interval;
  char genData[256];

  dataType = getIfmxDataType (bind[idx].dtype);
  length = bind[idx].size;	// unfix_length...
  A4GL_debug ("In binding - %d %d ptr=%p", dataType, length, bind[idx].ptr);

  if (A4GL_isnull (dataType, bind[idx].ptr))
    {
      EXEC SQL SET DESCRIPTOR:descriptorName VALUE:index
	TYPE =:dataType, LENGTH =:length, INDICATOR = -1;
      if (isSqlError ())
	return 1;
      return 0;
    }

  A4GL_debug ("Not null");

  switch (dataType)
    {
    case DTYPE_CHAR:
    case DTYPE_VCHAR:
      char_var = bind[idx].ptr;

      length++;			// Add space for the \0

      EXEC SQL SET DESCRIPTOR:descriptorName VALUE:index
	TYPE =:dataType, LENGTH =:length, DATA =:char_var;
      break;

    case DTYPE_SMINT:
      smint_ptr = (short *) bind[idx].ptr;
      smint_var = (short) *smint_ptr;
      EXEC SQL SET DESCRIPTOR:descriptorName VALUE:index
	TYPE =:dataType, DATA =:smint_var;
      break;
    case DTYPE_INT:
      int_ptr = (long *) bind[idx].ptr;
      int_var = (long) *int_ptr;
      EXEC SQL SET DESCRIPTOR:descriptorName VALUE:index
	TYPE =:dataType, DATA =:int_var;
      break;
    case DTYPE_FLOAT:
      float_ptr = (double *) bind[idx].ptr;
      float_var = (double) *float_ptr;
      EXEC SQL SET DESCRIPTOR:descriptorName VALUE:index
	TYPE =:dataType, DATA =:float_var;
      break;
    case DTYPE_SMFLOAT:
      smfloat_ptr = (float *) bind[idx].ptr;
      smfloat_var = (float) *smfloat_ptr;
      EXEC SQL SET DESCRIPTOR:descriptorName VALUE:index
	TYPE =:dataType, DATA =:smfloat_var;
      break;
    case DTYPE_DECIMAL:
      fgl_decimal = (fgldecimal *) bind[idx].ptr;
      if (deccvasc
	  (&fgl_decimal->dec_data[2], strlen (&fgl_decimal->dec_data[2]),
	   &decimal_var))
	{
	/** @todo : We need to store this error */
	  return 1;
	}
      EXEC SQL SET DESCRIPTOR:descriptorName VALUE:index
	TYPE =:dataType, DATA =:decimal_var;
      break;
    case DTYPE_DATE:
      fgl_date = (long *) bind[idx].ptr;
      date_var = (long) *fgl_date;
      EXEC SQL SET DESCRIPTOR:descriptorName VALUE:index
	TYPE =:dataType, DATA =:date_var;
      break;
    case DTYPE_MONEY:
      fgl_money = (fglmoney *) bind[idx].ptr;
      if (deccvasc
	  (&fgl_money->dec_data[2], strlen (&fgl_money->dec_data[2]),
	   &money_var))
	{
	/** @todo : We need to store this error */
	  return 1;
	}
      EXEC SQL SET DESCRIPTOR:descriptorName VALUE:index
	TYPE =:dataType, DATA =:money_var;
      break;
    case DTYPE_DTIME:

      fgl_dtime = (FglDatetime *) bind[idx].ptr;

      A4GL_dttoc (fgl_dtime, &genData, 30);
      A4GL_debug ("DT = '%s'\n", genData);
      dtime_var.dt_qual = 3594;
      if (dtcvasc (genData, &dtime_var))
	{
      		dtime_var.dt_qual = 1642;
      		if (dtcvasc (genData, &dtime_var)) {
	  		A4GL_debug ("Invalid datetime!!");
			/** @todo : We need to store this error */
	  		return 1;
		}
	}
      char_var = genData;
      dataType = 0;
      length = 255;
      EXEC SQL SET DESCRIPTOR:descriptorName VALUE:index
	TYPE =:dataType, DATA =:char_var, LENGTH =:length;
      if (sqlca.sqlcode != 0)
	{
	  A4GL_debug ("Bugger - bombed");
	}
      else
	{
	  A4GL_debug ("Bound ok");
	}
      break;

    case DTYPE_INTERVAL:
      fgl_interval = (FglInterval *) bind[idx].ptr;
      if (incvasc (fgl_interval->data, &interval_var))
	{
	/** @todo : We need to store this error */
	  return 1;
	}
      EXEC SQL SET DESCRIPTOR:descriptorName VALUE:index
	TYPE =:dataType, DATA =:interval_var;
      break;
    case DTYPE_TEXT:
      break;
    case DTYPE_BYTE:
      break;
    default:
      A4GL_exitwith ("Invalid data type\n");
    }
  if (isSqlError ())
    {
      A4GL_debug ("Problem");
      return 1;
    }
  A4GL_debug ("OK");
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
static int
processInputBind (char *descName, int bCount, struct BINDING *bind)
{
  EXEC SQL begin declare section;
  char *descriptorName = descName;
  int bindCount = bCount;
  EXEC SQL end declare section;
  register int i;

  EXEC SQL ALLOCATE DESCRIPTOR:descriptorName WITH MAX:bindCount;
  if (sqlca.sqlcode == -480)
    {
      EXEC SQL DEALLOCATE DESCRIPTOR:descriptorName;
      EXEC SQL ALLOCATE DESCRIPTOR:descriptorName WITH MAX:bindCount;
    }

  if (isSqlError ())
    {
      return 1;
    }

  for (i = 0; i < bindCount; i++)
    if (bindInputValue (descriptorName, i, bind) == 1)
      {
	A4GL_debug ("Failed binding %d\n", i);
	return 1;
      }
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
static int
bindOutputValue (char *descName, int idx, struct BINDING *bind)
{
  static const char function[] = "bindOutputValue";
  EXEC SQL begin declare section;
  char *descriptorName = descName;
  int index = idx + 1;
  int length;
  int dataType;
  short indicator;
  loc_t blob;

  char *char_var;
  short smint_var;
  long int_var;
  double float_var;
  float smfloat_var;
  dec_t decimal_var;
  long date_var;
  dec_t money_var;
  dtime_t dtime_var;
  intrvl_t interval_var;
  /*
     fglbyte byte_var;
     fgltext text_var;
   */
  EXEC SQL END DECLARE SECTION;
  FglDecimal *fgl_decimal;
  FglMoney *fgl_money;
  FglDatetime *fgl_dtime;
  FglInterval *fgl_interval;

  char tmpbuff[256];

  dataType = getIfmxDataType (bind[idx].dtype);
  length = bind[idx].size;	// unfix datatype ?

  EXEC SQL GET DESCRIPTOR:descriptorName VALUE:index:indicator =
    INDICATOR,:length = LENGTH;
  if (isSqlError ())
    {
      A4GL_debug ("Err1");
      return 1;
    }

  if (indicator == -1)
    {
      A4GL_debug ("Calling A4GL_setnull %d %p %d\n", dataType, bind[idx].ptr,
		  length);
      A4GL_setnull (dataType, bind[idx].ptr, length);	/* Something wrong with this */
      //if (dataType==0) { debug("ptr=%s\n",bind[idx].ptr); }
      return 0;
    }

  A4GL_debug ("MJAMJA datatype : %d", dataType);
  fflush (stdout);
  switch (dataType)
    {
    case DTYPE_CHAR:
    case DTYPE_VCHAR:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index:length =
	LENGTH;
      if (isSqlError ())
	return 1;
      char_var = malloc (length + 1);
      EXEC SQL GET DESCRIPTOR:descriptorName VALUE:index:char_var = DATA;
      strcpy (bind[idx].ptr, char_var);
      free (char_var);
      break;
    case DTYPE_SMINT:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:smint_var =
	DATA;
      if (isSqlError ())
	return 1;
      *(short *) bind[idx].ptr = smint_var;
      break;
    case DTYPE_INT:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:int_var =
	DATA;
      if (isSqlError ())
	return 1;
      *(long *) bind[idx].ptr = int_var;
      break;
    case DTYPE_FLOAT:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:float_var =
	DATA;
      if (isSqlError ())
	return 1;
      *(double *) bind[idx].ptr = float_var;
      break;
    case DTYPE_SMFLOAT:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:smfloat_var =
	DATA;
      if (isSqlError ())
	return 1;
      *(float *) bind[idx].ptr = smfloat_var;
      break;



    case DTYPE_DECIMAL:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:decimal_var =
	DATA;
      A4GL_debug ("DECIMAL...");
      if (isSqlError ())
	{
	  A4GL_debug ("isSqlError...");
	  return 1;
	}

      memset (tmpbuff, 0, 255);
      if (dectoasc (&decimal_var, tmpbuff, 64, -1))
	{
	  return 1;
	}
      A4GL_debug ("tmpbuff=%s\n", tmpbuff);
      A4GL_stodec (tmpbuff, bind[idx].ptr, bind[idx].size);
      break;


    case DTYPE_DATE:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:date_var =
	DATA;
      if (isSqlError ())
	return 1;
      *(long *) bind[idx].ptr = date_var;
      break;
    case DTYPE_MONEY:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:money_var =
	DATA;
      if (isSqlError ())
	return 1;
      fgl_money = malloc (sizeof (fglmoney));
      if (dectoasc (&money_var, &fgl_money->dec_data[2], 64, -1))
	{
	/** @todo : Store the error somewhere */
	  return 1;
	}
      (fgldecimal *) bind[idx].ptr = fgl_decimal;
      break;



    case DTYPE_DTIME:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:dtime_var =
	DATA;
      if (isSqlError ())
	return 1;
      if (dttoasc (&dtime_var, tmpbuff))
	{
	  return 1;
	}
      A4GL_ctodt (tmpbuff, (FglDatetime *) bind[idx].ptr, bind[idx].size);
      break;



    case DTYPE_INTERVAL:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:interval_var =
	DATA;
      if (isSqlError ())
	return 1;
      fgl_interval = malloc (sizeof (FglInterval));
      if (intoasc (&interval_var, fgl_interval->data))
	{
	/** @todo : Store the error somewhere */
	  return 1;
	}
      (FglInterval *) bind[idx].ptr = fgl_interval;
      break;
    case DTYPE_BYTE:
      break;
    case DTYPE_TEXT:
      break;
    default:
      A4GL_exitwith ("Invalid data type\n");
    }
  A4GL_debug ("Got to here");
  if (isSqlError ())
    {
      A4GL_debug ("Some isSqlError..");
      return 1;
    }
  A4GL_debug ("Ok");
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
static int
allocateOutputDescriptor (char *descName, int bCount, struct BINDING *bind)
{
  EXEC SQL begin declare section;
  char *descriptorName = descName;
  int bindCount = bCount;
  EXEC SQL end declare section;
  register int i;
  A4GL_debug ("allocOutout - %s cnt=%d", descriptorName, bindCount);
  bindCount += 256;
  EXEC SQL ALLOCATE DESCRIPTOR:descriptorName WITH MAX:bindCount;
  A4GL_debug ("Status=%d", sqlca.sqlcode);
  if (sqlca.sqlcode == -480)
    {
      sqlca.sqlcode = 0;
      A4GL_set_a4gl_sqlca_sqlcode (0);
      A4GL_debug ("Try dealloc and alloc");
      EXEC SQL DEALLOCATE DESCRIPTOR:descriptorName;
      EXEC SQL ALLOCATE DESCRIPTOR:descriptorName WITH MAX:bindCount;
    }
  A4GL_debug ("Done");
  if (isSqlError ())
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
static int
processOutputBind (char *descName, int bCount, struct BINDING *bind)
{
  EXEC SQL begin declare section;
  char *descriptorName = descName;
  int bindCount = bCount;
  EXEC SQL end declare section;
  register int i;

  for (i = 0; i < bindCount; i++)
    if (bindOutputValue (descriptorName, i, bind) == 1)
      {
	A4GL_debug ("Failed bind @ %d\n", i);
	return 1;
      }
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
char *
getDescriptorName (char *statementName, char bindType)
{
  char *descriptorName;
  descriptorName = malloc (strlen (statementName) + 20);
  sprintf (descriptorName, "%s_%cbind", statementName, bindType);
  return descriptorName;
}

/**
 * Define the type of statement to be executed.
 * 
 * @param sid A pointer to the statement structure.
 * @return The statement type
 */
static int
getStatementBindType (struct s_sid *sid)
{
A4GL_debug("getStatementBindType : %p %p %d %d",sid->obind,sid->ibind,sid->no,sid->ni);
  if (sid->obind != (struct BINDING *) 0 && sid->no > 0 &&
      sid->ibind != (struct BINDING *) 0 && sid->ni > 0)
    return INPUT_OUTPUT_BIND;
  if (sid->ibind != (struct BINDING *) 0 && sid->ni > 0)
    return INPUT_BIND;
  if (sid->obind != (struct BINDING *) 0 && sid->no > 0)
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
static int
executeStatement (struct s_sid *sid)
{
  EXEC SQL begin declare section;
  char *statementName;
  char *inputDescriptorName;
  char *outputDescriptorName;
  EXEC SQL end declare section;
  int rc = 0;

  statementName = sid->statementName;
  inputDescriptorName = sid->inputDescriptorName;
  outputDescriptorName = sid->outputDescriptorName;
  A4GL_debug ("ExecuteStatement %d - %d %d %d %d",getStatementBindType (sid),NO_BIND,INPUT_BIND,OUTPUT_BIND,INPUT_OUTPUT_BIND);
  switch (getStatementBindType (sid))
    {
    case NO_BIND:
    EXEC SQL EXECUTE:statementName;
      break;
    case INPUT_BIND:
    EXEC SQL EXECUTE: statementName USING SQL DESCRIPTOR:inputDescriptorName;
      break;
    case OUTPUT_BIND:
    EXEC SQL EXECUTE: statementName INTO SQL DESCRIPTOR:outputDescriptorName;
      break;
    case INPUT_OUTPUT_BIND:
    EXEC SQL EXECUTE: statementName INTO SQL DESCRIPTOR: outputDescriptorName USING SQL DESCRIPTOR:inputDescriptorName;
      break;
    otherwise:
      A4GL_exitwith ("Invalid bind\n");
    }

  if (isSqlError ())
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
void *
A4GLSQL_prepare_sql_internal (char *s)
{
  struct s_sid *sid;
  sid =
    prepareSqlStatement ((struct BINDING *) 0, 0, (struct BINDING *) 0, 0, s);
  A4GLSQL_set_status (sqlca.sqlcode, 1);
  return sid;
}

/**
 * Store the information of a prepared statement in a global data structure.
 *
 * @param pname The prepare statement name.
 * @param sid A pointer to the statement information.
 * @return Allways 0
 */
int
A4GLSQL_add_prepare (char *pname, void *vsid)
{
struct s_sid *sid;
sid=vsid;
  if (sid)
    {
      A4GL_add_pointer (pname, PRECODE, sid);
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
int
A4GLSQL_execute_sql_from_ptr_internal (char *pname, int ni, char *ibind)
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
static int
processPreStatementBinds (struct s_sid *sid)
{
  EXEC SQL BEGIN DECLARE SECTION;
  char *statementName;
  char *descriptorName;
  EXEC SQL END DECLARE SECTION;
  int rv = 0;
  A4GL_debug ("a1");
  if (sid->ibind != (struct BINDING *) 0 && sid->ni > 0)
    {
      A4GL_debug ("a2");
      if (sid->inputDescriptorName == 0)
	sid->inputDescriptorName =
	  getDescriptorName (sid->statementName, 'I');

      if (processInputBind (sid->inputDescriptorName, sid->ni, sid->ibind) ==
	  1)
	{
	  A4GL_debug ("Fail1 ");
	  return 1;
	}
    }
  A4GL_debug ("a3");

  if (sid->obind != (struct BINDING *) 0 && sid->no > 0)
    {


      sid->outputDescriptorName = getDescriptorName (sid->statementName, 'O');

      A4GL_debug ("a3.1 no=%d ", sid->no);

      A4GL_debug ("allocateOutputDescriptorName - %s\n",
		  sid->outputDescriptorName);
      rv =
	allocateOutputDescriptor (sid->outputDescriptorName, sid->no,
				  sid->obind);
      if (rv == 1)
	{
	  A4GL_debug ("Fail2");
	  return 1;
	}
      A4GL_debug ("a4");
      descriptorName = sid->outputDescriptorName;
      statementName = sid->statementName;
      EXEC SQL DESCRIBE:statementName USING SQL DESCRIPTOR:descriptorName;
      A4GL_debug ("a4.1");
    }
  A4GL_debug ("OK3");
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
static int
deallocateDescriptors (struct s_sid *sid)
{
  EXEC SQL begin declare section;
  char *descriptorName;
  EXEC SQL end declare section;
  int rc = 0;

  if (sid->ibind != (struct BINDING *) 0 && sid->ni > 0)
    {
      descriptorName = sid->inputDescriptorName;
      EXEC SQL DEALLOCATE DESCRIPTOR:descriptorName;
      free (descriptorName);
      sid->inputDescriptorName = 0;
    }
  if (isSqlError ())
    rc = 1;

  if (sid->obind != (struct BINDING *) 0 && sid->no > 0)
    {
      descriptorName = sid->outputDescriptorName;
      EXEC SQL DEALLOCATE DESCRIPTOR:descriptorName;
      free (descriptorName);
      sid->outputDescriptorName = 0;
    }
  if (isSqlError ())
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
static int
processPosStatementBinds (struct s_sid *sid)
{
  if (sid->obind != (struct BINDING *) 0 && sid->no > 0)
    {
      A4GL_debug ("calling processOutputBind");
      if (processOutputBind (sid->outputDescriptorName, sid->no, sid->obind)
	  == 1)
	{
	  A4GL_debug ("Failed..");
	  return 1;
	}
    }

  if (deallocateDescriptors (sid) == 1)
    {
      A4GL_debug ("Deallocating failed..");
      return 1;
    }

  A4GL_debug ("All Ok in posStatementBinds");
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
int
A4GLSQL_execute_implicit_select (void *vsid)
{
struct s_sid *sid;
  EXEC SQL begin declare section;
  char *statementName;
  char *statementText;
  EXEC SQL end declare section;
sid=vsid;

  A4GL_debug ("ESQL : execute_implicit_select");
  if (sid == 0)
    {
      A4GL_debug ("SID=0");
      return -1;
    }

  A4GL_debug ("ESQL : pre");
  if (processPreStatementBinds (sid) == 1)
    {
      A4GL_debug ("processPreStatementBinds failed ?");
      error_just_in_case ();
      return 1;
    }

  A4GL_debug ("ESQL : exec");
  if (executeStatement (sid) == 1)
    {
      A4GL_debug ("executeStatement failed ?");
      error_just_in_case ();
      return 1;
    }
  if (sqlca.sqlcode == 0)
    {
      A4GL_debug ("ESQL : post");

      if (processPosStatementBinds (sid) == 1)
	{
	  A4GL_debug ("processPosStatementBinds failed ?");
	  error_just_in_case ();
	  return 1;
	}
    }
  A4GL_debug ("All ok ?");
  A4GLSQL_set_status (sqlca.sqlcode, 1);
  return 0;
}

static
error_just_in_case ()
{

  if (sqlca.sqlcode == 0)
    {
      // We have an error - but its not in Informix...
      // We'll fake one - how about -410
      sqlca.sqlcode = -410;
      esqlErrorHandler ();
    }
  else
    {
      A4GLSQL_set_status (sqlca.sqlcode, 1);
    }
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
int
A4GLSQL_execute_implicit_sql (void *vsid)
{
struct s_sid *sid;
  EXEC SQL begin declare section;
  char *statementName;
  char *descriptorName;
  int inputBindCount;
  EXEC SQL end declare section;
  int rc = 0;
  vsid=sid;
  A4GL_debug ("In execute_implicit_sql");
  if (sid == (struct s_sid *) 0)
    {
      A4GL_debug ("Bugger - failed");
    /** @todo : I should store the error message and number somwehere */
      return 1;
    }

  if (processPreStatementBinds (sid) == 1)
    {
      A4GL_debug ("Pre failed");
      error_just_in_case ();
      return 1;
    }
  if (executeStatement (sid) == 1)
    {
      A4GL_debug ("Execute failed");
      error_just_in_case ();
      return 1;
    }
    a4gl_sqlca.sqlerrd[0]=sqlca.sqlerrd[0];
    a4gl_sqlca.sqlerrd[1]=sqlca.sqlerrd[1];
    a4gl_sqlca.sqlerrd[2]=sqlca.sqlerrd[2];
    a4gl_sqlca.sqlerrd[3]=sqlca.sqlerrd[3];
    a4gl_sqlca.sqlerrd[4]=sqlca.sqlerrd[4];

if (A4GL_isyes(acl_getenv("SWAP_SQLCA62"))) {
    a4gl_sqlca.sqlerrd[5]=sqlca.sqlerrd[1];
} else {
    a4gl_sqlca.sqlerrd[5]=sqlca.sqlerrd[5];
}
	strcpy(a4gl_sqlca.sqlerrm,sqlca.sqlerrm);
    //strncpy(a4gl_sqlca.sqlawarn,sqlca.sqlawarn,9);
	//strcpy(a4gl_sqlca.sqlstate,sqlca.sqlstate);



  if (processPosStatementBinds (sid) == 1)
    {
      A4GL_debug ("Pos failed");
      error_just_in_case ();
      return 1;
    }
  A4GL_debug ("OK");
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
void *
A4GLSQL_prepare_select_internal (void *ibind, int ni, void *obind,
			int no, char *s)
{
//printf("prepare_select : %d %d (%s)\n",ni,no,s);
  return (prepareSqlStatement (ibind, ni, obind, no, s));
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
static int
getCursorType (int upd_hold, int scroll)
{
  if (scroll == 0)
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
  else if (scroll == 1)
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
void *
A4GLSQL_declare_cursor (int upd_hold, void *vsid, int scroll,
			char *cursname)
{
  EXEC SQL BEGIN DECLARE SECTION;
  char *cursorName = cursname;
  char *statementName;
  char *outputDescriptorName;
  EXEC SQL END DECLARE SECTION;
  int retval = 0;
  struct s_cid *cursorIdentification;
  struct s_sid *sid;
	sid=vsid;

  if (sid == (struct s_sid *) 0)
    return (struct s_cid *) 0;


  cursorIdentification = malloc (sizeof (struct s_cid));
  cursorIdentification->statement = sid;
  statementName = sid->statementName;
  A4GL_debug ("obind count=%d", sid->no);

      switch (getCursorType (upd_hold, scroll))
	{
	case SIMPLE:
	EXEC SQL DECLARE: cursorName CURSOR FOR:statementName;
	  break;
	case SIMPLE_SCROLL:
	EXEC SQL DECLARE: cursorName SCROLL CURSOR FOR:statementName;
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
	EXEC SQL DECLARE: cursorName CURSOR WITH HOLD FOR:statementName;
	  break;
	default:
      /** @todo : Assign an error code  */
	  return (struct s_cid *) 0;
	}

  if (isSqlError ())
    {
      A4GL_debug ("Declare failed");
      return (struct s_cid *) 0;
    }
  A4GL_debug ("Declared OK");
  A4GL_add_pointer (cursname, PRECODE, cursorIdentification);


  if (processPreStatementBinds (sid) == 1)
    return (struct s_cid *) 0;

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
 *
 * 	@ FIXME - doesn't use the USING section...
 *
 */
int
A4GLSQL_open_cursor (int ni, char *s)
{
  EXEC SQL BEGIN DECLARE SECTION;
  char *cursorName = s;
  struct s_cid *cursorIdentification;
  struct s_sid *sid;
  char *inputDescriptorName;
  char *outputDescriptorName;

  EXEC SQL END DECLARE SECTION;

  A4GL_debug ("Open Cursor");

  cursorIdentification = A4GL_find_pointer (s, PRECODE);


  A4GL_debug ("Got cursorIdentification as : %p", cursorIdentification);
  sid = cursorIdentification->statement;
  A4GL_debug("%s",sid->select);


  if (strncasecmp(sid->select,"INSERT",6)==0) {
    EXEC SQL OPEN:cursorName;
  if (isSqlError ())
    return 1;
  return 0;
  }


  inputDescriptorName = sid->inputDescriptorName;
  outputDescriptorName = sid->outputDescriptorName;
  A4GL_debug ("Descritors : %s %s", inputDescriptorName,
	      outputDescriptorName);

  processPreStatementBinds (sid);	// MJA 150503

  switch (getStatementBindType (sid))
    {
    case NO_BIND:
    EXEC SQL OPEN:cursorName;
      break;

    case INPUT_BIND:
    EXEC SQL OPEN: cursorName USING SQL DESCRIPTOR:inputDescriptorName;
      break;

    case OUTPUT_BIND:
      A4GL_debug ("Into on an open ?");
      EXEC SQL OPEN:cursorName
	//INTO SQL DESCRIPTOR :outputDescriptorName
       ;
      break;
    case INPUT_OUTPUT_BIND:
      A4GL_debug ("Into on an open ?");
      EXEC SQL OPEN:cursorName
	//INTO SQL DESCRIPTOR :outputDescriptorName
        USING SQL DESCRIPTOR:inputDescriptorName;
      break;
    }


  if (isSqlError ())
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
static int
getFetchType (int fetch_mode, int fetch_when)
{
  if (fetch_when == 0)
    return FETCH_CURRENT;

  if (fetch_when == 1)
    {
      if (fetch_mode == FETCH_ABSOLUTE)
	return FETCH_FIRST;
      else if (fetch_mode == FETCH_RELATIVE)
	return FETCH_NEXT;
      else
	A4GL_exitwith ("Invalid cursor type");
    }

  if (fetch_when == -1)
    {
      if (fetch_mode == FETCH_ABSOLUTE)
	return FETCH_LAST;
      else if (fetch_mode == FETCH_RELATIVE)
	return FETCH_PREVIOUS;
      else
	A4GL_exitwith ("Invalid cursor type");
    }

  if (fetch_mode == FETCH_ABSOLUTE)
    return FETCH__ABSOLUTE;

  if (fetch_mode == FETCH_RELATIVE)
    return FETCH__RELATIVE;
  A4GL_exitwith ("Invalid cursor type");
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
int
A4GLSQL_fetch_cursor (char *cursor_name,
		      int fetch_mode, int fetch_when, int nobind,
			void *vobind
)
{
  EXEC SQL BEGIN DECLARE SECTION;
  char *cursorName = cursor_name;
  char *descriptorName;
  int position = fetch_when;
  EXEC SQL END DECLARE SECTION;
  struct s_sid *sid;
  struct s_cid *cid;
	      struct BINDING *obind;
	obind=vobind;

  cid = (struct s_cid *) A4GL_find_pointer_val (cursorName, PRECODE);
  sid = (struct s_sid *) cid->statement;
  if (sid == (struct s_sid *) 0)
    {
    /** @todo : Proper error handling */
      return 1;
    }

  if (sid->no!=0) {
	if (nobind==0) {
		nobind=sid->no;
		obind=sid->obind;	
	}
  }

sid->obind = obind;
sid->no = nobind;


  /** @todo : Maybe input bind should be cleaned (if exist) */
  if (processPreStatementBinds (sid) == 1)
    return 1;
  descriptorName = sid->outputDescriptorName;

  switch (getFetchType (fetch_mode, fetch_when))
    {
    case FETCH_FIRST:
    EXEC SQL FETCH FIRST: cursorName USING SQL DESCRIPTOR :descriptorName;
      break;
    case FETCH_LAST:
    EXEC SQL FETCH LAST: cursorName USING SQL DESCRIPTOR :descriptorName;
      break;
    case FETCH_NEXT:
    EXEC SQL FETCH NEXT: cursorName USING SQL DESCRIPTOR :descriptorName;
      break;
    case FETCH_PREVIOUS:
    EXEC SQL FETCH PREVIOUS: cursorName USING SQL DESCRIPTOR:descriptorName;
      break;
    case FETCH_CURRENT:
    EXEC SQL FETCH CURRENT: cursorName USING SQL DESCRIPTOR:descriptorName;
      break;
    case FETCH__RELATIVE:
    EXEC SQL FETCH RELATIVE: position: cursorName USING SQL DESCRIPTOR:descriptorName;
      break;
    case FETCH__ABSOLUTE:
    EXEC SQL FETCH ABSOLUTE: position: cursorName USING SQL DESCRIPTOR:descriptorName;
      break;
    otherwise:
      A4GL_exitwith ("Invalid fetch");
    }
  if (isSqlError ())
    return 1;
  if (isNotFound ())
    return 0;
  if (processPosStatementBinds (sid) == 1)
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
A4GLSQL_put_insert (void *vibind, int n)
{
  exec sql begin declare section;
  char *cursorName;
  char *descriptorName;
  struct s_sid *sid;
  struct s_cid *cid;
  exec sql end declare section;
  struct BINDING *ibind;
  ibind=vibind;

  cursorName = A4GL_char_pop ();

  cid = (struct s_cid *) A4GL_find_pointer_val (cursorName, PRECODE);
  sid = (struct s_sid *) cid->statement;

	//printf("CID : %d %d\n",cid->ni,cid->no);
	//printf("SID : %d %d\n",sid->ni,sid->no);
if (sid) {
	//printf("Maybe %d %d\n",sid->ni,sid->no);

  if (sid->ni!=0) {
        if (n==0) {
	//printf("FORCE IT..\n");
                n=sid->ni;
                ibind=sid->ibind;
        }
  }
} else {
	//printf("No sid\n");
}





  if (ibind != (struct BINDING *) 0 && n > 0)
    {
      descriptorName = getDescriptorName (cursorName, 'I');

      if (processInputBind (descriptorName, n, ibind) == 1)
	A4GL_exitwith ("Error binding");
    }

  EXEC SQL PUT:cursorName USING SQL DESCRIPTOR $descriptorName;

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
static int
printField (FILE * unloadFile, int idx, char *descName)
{
  EXEC SQL BEGIN DECLARE SECTION;
  int dataType;
  int index = idx;
  short indicator;

  char *descriptorName = descName;
  int length;
  loc_t blob;

  char *char_var;
  short smint_var;
  long int_var;
  double float_var;
  float smfloat_var;
  dec_t decimal_var;
  long date_var;
  dec_t money_var;
  dtime_t dtime_var;
  intrvl_t interval_var;
  /*
     fglbyte byte_var;
     fgltext text_var;
   */
  EXEC SQL END DECLARE SECTION;
  FglDecimal *fgl_decimal;
  FglMoney *fgl_money;
  FglDatetime *fgl_dtime;
  FglInterval *fgl_interval;
  int rc = 0;

  EXEC SQL GET DESCRIPTOR 'descUnload' VALUE:index:indicator =
    INDICATOR,:dataType = TYPE;

  if (indicator == -1)
    {
      return 0;
    }

  switch (dataType)
    {
    case DTYPE_CHAR:
    case DTYPE_VCHAR:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index:length =
	LENGTH;
      if (isSqlError ())
	{
	  rc = 1;
	  break;
	}
      char_var = malloc (length + 1);
      EXEC SQL GET DESCRIPTOR:descriptorName VALUE:index:char_var = DATA;
      A4GL_trim (char_var);
      fprintf (unloadFile, "%s", char_var);
      free (char_var);
      break;
    case DTYPE_SMINT:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:smint_var =
	DATA;
      if (isSqlError ())
	{
	  rc = 1;
	  break;
	}
      fprintf (unloadFile, "%d", smint_var);
      break;
    case DTYPE_INT:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:int_var =
	DATA;
      if (isSqlError ())
	{
	  rc = 1;
	  break;
	}
      fprintf (unloadFile, "%ld", int_var);
      break;
    case DTYPE_FLOAT:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:float_var =
	DATA;
      if (isSqlError ())
	{
	  rc = 1;
	  break;
	}
      fprintf (unloadFile, "%lf", float_var);
      break;
    case DTYPE_SMFLOAT:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:smfloat_var =
	DATA;
      if (isSqlError ())
	{
	  rc = 1;
	  break;
	}
      fprintf (unloadFile, "%f", smfloat_var);
      break;
    case DTYPE_DECIMAL:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:decimal_var =
	DATA;
      if (isSqlError ())
	{
	  rc = 1;
	  break;
	}
      fgl_decimal = malloc (sizeof (fgldecimal));
      if (dectoasc (&decimal_var, &fgl_decimal->dec_data[2], 64, -1))
	{
	/** @todo : Store the error somewhere */
	  return 1;
	}
      fprintf (unloadFile, "%s", &fgl_decimal->dec_data[2]);
      free (fgl_decimal);
      break;
    case DTYPE_DATE:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:date_var =
	DATA;
      if (isSqlError ())
	{
	  rc = 1;
	  break;
	}
      /** @todo : Print as date field */
      char_var = malloc (sizeof (char) * 10);
      A4GL_dtos (&date_var, char_var, 10);
      fprintf (unloadFile, "%s", char_var);
      free (char_var);
      break;
    case DTYPE_MONEY:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:money_var =
	DATA;
      if (isSqlError ())
	{
	  rc = 1;
	  break;
	}
      fgl_money = malloc (sizeof (fglmoney));
      if (dectoasc (&money_var, &fgl_money->dec_data[2], 64, -1))
	{
	/** @todo : Store the error somewhere */
	  return 1;
	}
      fprintf (unloadFile, "%s", &fgl_money->dec_data[2]);
      free (fgl_money);
      break;
    case DTYPE_DTIME:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:dtime_var =
	DATA;
      if (isSqlError ())
	{
	  rc = 1;
	  break;
	}
      fgl_dtime = malloc (sizeof (FglDatetime));
      if (dttoasc (&dtime_var, fgl_dtime->data))
	{
	/** @todo : Store the error somewhere */
	  return 1;
	}
      fprintf (unloadFile, "%s", fgl_dtime->data);
      free (fgl_dtime);
      break;
    case DTYPE_INTERVAL:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:interval_var =
	DATA;
      if (isSqlError ())
	{
	  rc = 1;
	  break;
	}
      fgl_interval = malloc (sizeof (FglInterval));
      if (intoasc (&interval_var, fgl_interval->data))
	{
	/** @todo : Store the error somewhere */
	  return 1;
	}
      fprintf (unloadFile, "%s", fgl_interval->data);
      free (fgl_interval);
      break;
    case DTYPE_BYTE:
      break;
    case DTYPE_TEXT:
      break;
    default:
      A4GL_exitwith ("Invalid data type\n");
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
A4GLSQL_unload_data_internal (char *fname_o, char *delims, char *sqlStr, int nbind, void *vibind)
{
  int cnt = 0;
  static char databuf[64000];
  FILE *unloadFile;
  int rc = 0;
  struct BINDING *ibind;

  EXEC SQL BEGIN DECLARE SECTION;
  char *strSql = sqlStr;
  short numberOfColumns;
  int colcnt;
  int coltype;
  EXEC SQL END DECLARE SECTION;
  char *fname;
  ibind=vibind;
  A4GL_debug ("Unload data..");
  fname=strdup(fname_o); A4GL_trim(fname);
  unloadFile = (FILE *) A4GL_mja_fopen (fname, "wt");
  if (unloadFile == (FILE *) 0)
    {
    /** @todo : Generate some error code compatible with informix 4gl */
	free(fname);
      return;			/* return 1; */
    }


  A4GL_debug("prepare : %s",strSql);
  EXEC SQL PREPARE stUnload FROM:strSql;
  A4GL_debug("Prepared..");
  if (isSqlError ()) {
	free(fname);
    	return;			/* return 1; */
  }

  EXEC SQL ALLOCATE DESCRIPTOR 'descUnload' WITH MAX 1024;


  EXEC SQL DESCRIBE stUnload USING SQL DESCRIPTOR 'descUnload';
  if (isSqlError ())
    {
      EXEC SQL DEALLOCATE DESCRIPTOR 'descUnload';
	free(fname);
      return;			/* return 1; */
    }


  A4GL_debug("Described");

  EXEC SQL GET DESCRIPTOR 'descUnload':numberOfColumns = COUNT;

  if (isSqlError ())
    {
      EXEC SQL DEALLOCATE DESCRIPTOR 'descUnload';
	free(fname);
      return;			/* return 1; */
    }


  A4GL_debug("Declare.");
  EXEC SQL DECLARE crUnload CURSOR FOR stUnload;
  A4GL_debug("Declared");
  if (isSqlError ())
    {
      EXEC SQL DEALLOCATE DESCRIPTOR 'descUnload';
	free(fname);
      return;			/* return 1; */
    }
  processInputBind ("escInpUnload", nbind, ibind);
  if (!nbind)
    {
      EXEC SQL OPEN crUnload;
    }
  else
    {
      EXEC SQL OPEN crUnload USING SQL DESCRIPTOR 'descInpUnload';
    }

  A4GL_debug ("Here4");

  if (isSqlError ())
    {
      EXEC SQL DEALLOCATE DESCRIPTOR 'descUnload';
	free(fname);
      return;			/* return 1; */
    }

  A4GL_debug ("Here5");
  // Get the data
  while (1)
    {
      A4GL_debug ("Here6");
      EXEC SQL FETCH crUnload USING SQL DESCRIPTOR 'descUnload';
      if (isSqlError ())
	{
	  EXEC SQL DEALLOCATE DESCRIPTOR 'descUnload';
	free(fname);
	  return;		/* return 1; */
	}
      if (strcmp (SQLSTATE, "02000") == 0)
	break;

      A4GL_debug ("Here7");
      cnt++;
      for (colcnt = 1; colcnt <= numberOfColumns; colcnt++)
	{
	  if (printField (unloadFile, colcnt, "descUnload") == 1)
	    {
	      rc = 1;
	      break;
	    }
	  fprintf (unloadFile, "%c", delims[0]);
	}
      fprintf (unloadFile, "\n");
    }
  A4GL_debug ("Here8");
  fclose (unloadFile);
  sqlca.sqlerrd[1] = cnt;
  EXEC SQL FREE stUnload;
  EXEC SQL FREE crUnload;
  A4GL_debug ("Here9");
  EXEC SQL DEALLOCATE DESCRIPTOR 'descUnload';
  if (isSqlError ())
    rc = 1;
	free(fname);
  return;			/* return 0; */
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
  A4GL_debug ("In commit_rollback");
#ifndef NO_TRANSACTIONS
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
#endif
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
void *
A4GLSQL_find_prepare (char *pname)
{
  struct s_sid *ptr;

  A4GL_set_errm (pname);
  ptr = (struct s_sid *) A4GL_find_pointer_val (pname, PRECODE);
  if (ptr)
    return ptr;
  return (struct s_sid *) 0;
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

  EXEC SQL FLUSH:cursorName;
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
int
A4GLSQL_execute_sql (char *pname, int ni, void *vibind) 
{
  struct s_sid *sid;
struct BINDING *ibind;
ibind=vibind;

  A4GL_debug ("ESQL : A4GLSQL_execute_sql");
  /** @todo : Fix the mode that is not used now  - done remove comment */
  sid = A4GLSQL_find_prepare (pname);	// ,0
  sid->ibind = ibind;
  sid->ni = ni;
  if (processPreStatementBinds (sid) == 1)
    return 1;
  if (executeStatement (sid) == 1)
    return 1;
  if (processPosStatementBinds (sid) == 1)
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
 *                It is not used, now.
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
  EXEC SQL BEGIN DECLARE SECTION;
  char strSelect[640];
  int numberOfColumns;
  int MaxColumns = 1024;		//we will be able to process tables with maximum 1024 columns
  EXEC SQL END DECLARE SECTION;

  sprintf (strSelect, "select * from %s\n", tabname);
  A4GL_debug ("strSelect : %s\n", strSelect);
  EXEC SQL PREPARE stReadAllColumns FROM:strSelect;
  if (isSqlError ())
    {
#ifdef DEBUG
      A4GL_debug ("Error in EXEC SQL PREPARE");
#endif
      return 0;
    }

  EXEC SQL ALLOCATE DESCRIPTOR 'descReadAllColumns' WITH MAX:MaxColumns;
  if (sqlca.sqlcode == -480)
    {
      EXEC SQL DEALLOCATE DESCRIPTOR 'descReadAllColumns';
      EXEC SQL ALLOCATE DESCRIPTOR 'descReadAllColumns';
    }
  if (isSqlError ())
    {
#ifdef DEBUG
      A4GL_debug ("Error in EXEC SQL ALLOCATE DESCRIPTOR");
#endif
      return 0;
    }

  EXEC SQL DESCRIBE stReadAllColumns USING SQL DESCRIPTOR
    'descReadAllColumns';
  if (isSqlError ())
    {
#ifdef DEBUG
      A4GL_debug ("Error in EXEC SQL DESCRIBE");
#endif
      return 0;
    }

  EXEC SQL GET DESCRIPTOR 'descReadAllColumns':numberOfColumns = COUNT;
  if (isSqlError ())
    {
#ifdef DEBUG
      A4GL_debug ("Error in EXEC SQL GET DESCRIPTOR, numberOfColumns = %s",
		  numberOfColumns);
      //FIXME: can we read error returned by ESQL/C lib here, and sent it to debug() ?
      A4GL_debug ("ESQL/C Error message:%s", A4GLSQL_get_sqlerrm ());
#endif
      return 0;
    }

  getColumnsMax = numberOfColumns;
  getColumnsOrder = 1;
  A4GL_debug ("COlumns max=%d", numberOfColumns);
  return numberOfColumns;
}

/**
 * Convert the length qualifiers for a datetime from the
 *  informix notation to the A4GL notation
 */
int
Infx_dt_to_A4gl_dt (int n)
{
  switch (n)
    {
    case TU_YEAR:
      return 1;
    case TU_MONTH:
      return 2;
    case TU_DAY:
      return 3;
    case TU_HOUR:
      return 4;
    case TU_MINUTE:
      return 5;
    case TU_SECOND:
      return 6;
    case TU_F1:
      return 7;
    case TU_F2:
      return 8;
    case TU_F3:
      return 9;
    case TU_F4:
      return 10;
    case TU_F5:
      return 11;
    }
  // Shouldn't get to here
  return 3;
}

/**
 *
 * @param length The length of the datatype.
 * @param dtype The data type.
 * @return The lnegth calculated.
 */
static long
fixlength (int dtype, int length)
{
  int n1, n2;
  if (dtype > 255)
    dtype -= 256;
  A4GL_debug ("Got datatype : %d length %d\n", dtype, length);
  if (dtype==5||dtype==8) {
	int a1,a2;
	a1=length&0xff;
	a2=length>>8;
	if (a1==0xff) {
		a1=2; a2+=5; length=(a2<<8)+a1; 
		return length;
	}

  }


  if (dtype == 10)
    {
      n1 = Infx_dt_to_A4gl_dt (TU_START (length));
      n2 = Infx_dt_to_A4gl_dt (TU_END (length));
      return (n1 * 16) + n2;
    }

  return length;
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
A4GLSQL_next_column (char **colname, int *dtype, int *size)
{
  EXEC SQL BEGIN DECLARE SECTION;
  int idx = getColumnsOrder;
  int dataType;
  int length;
  static char columnName[64];
  EXEC SQL END DECLARE SECTION;

  if (idx > getColumnsMax)
    return 0;

  EXEC SQL GET DESCRIPTOR 'descReadAllColumns' VALUE:idx:columnName =
    NAME,:dataType = TYPE,:length = LENGTH;
  if (isSqlError ())
    return 0;

  *dtype = dataType;
  *colname = columnName;
  *size = fixlength (dataType, length);
  A4GL_debug ("dtype=%d size=%d colname=%s\n", *dtype, *size, *colname);
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
int
A4GLSQL_end_get_columns (void)
{
  EXEC SQL DEALLOCATE DESCRIPTOR 'descReadAllColumns';
  if (isSqlError ())
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
static int
getSQLDataType (char *connName, char *tabname, char *colname,
		int *dtype, int *size)
{
  EXEC SQL BEGIN DECLARE SECTION;
  char strSelect[640];
  int dataType;
  int length;
  EXEC SQL END DECLARE SECTION;

  sprintf (strSelect, "select %s from %s", colname, tabname);
  A4GL_debug ("SQL = %s", strSelect);
  EXEC SQL PREPARE stReadColumns FROM:strSelect;
  if (isSqlError ())
    {
      return 1;
    }

  EXEC SQL ALLOCATE DESCRIPTOR 'descReadColumns';
  if (isSqlError ())
    {
      return 1;
    }

  EXEC SQL DESCRIBE stReadColumns USING SQL DESCRIPTOR 'descReadColumns';
  if (isSqlError ())
    {
      EXEC SQL DEALLOCATE DESCRIPTOR 'descReadColumns';
      return 1;
    }

  EXEC SQL GET DESCRIPTOR 'descReadColumns' VALUE 0:dataType = TYPE,:length =
    LENGTH;
  if (isSqlError ())
    {
      EXEC SQL DEALLOCATE DESCRIPTOR 'descReadColumns';
      return 1;
    }
  EXEC SQL DEALLOCATE DESCRIPTOR 'descReadColumns';
  if (isSqlError ())
    {
      return 1;
    }
  *dtype = dataType;
  *size = fixlength (dataType, length);
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
int
A4GLSQL_read_columns (char *tabname, char *colname, int *dtype, int *size)
{
  EXEC SQL BEGIN DECLARE SECTION;
  char strSelect[640];
  int dataType;
  int length;
  EXEC SQL END DECLARE SECTION;

  sprintf (strSelect, "select %s.%s from %s", tabname, colname, tabname);
  EXEC SQL PREPARE stXReadColumns FROM:strSelect;
  if (isSqlError ())
    {
      return 0;
    }

  EXEC SQL ALLOCATE DESCRIPTOR 'descReadColumns';
  if (isSqlError ())
    {
      return 0;
    }

  EXEC SQL DESCRIBE stXReadColumns USING SQL DESCRIPTOR 'descReadColumns';
  if (isSqlError ())
    {
      EXEC SQL DEALLOCATE DESCRIPTOR 'descReadColumns';
      return 0;
    }

  EXEC SQL GET DESCRIPTOR 'descReadColumns' VALUE 1:dataType = TYPE,:length =
    LENGTH;
  if (isSqlError ())
    {
      EXEC SQL DEALLOCATE DESCRIPTOR 'descReadColumns';
      return 0;
    }
  EXEC SQL DEALLOCATE DESCRIPTOR 'descReadColumns';
  if (isSqlError ())
    {
      return 0;
    }
  *dtype = dataType;
  *size = fixlength (dataType, length);
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
int
A4GLSQL_get_datatype (char *db, char *tab, char *col)
{
  int dataType;
  int length;
  char *connectionName;

  connectionName = getConnectionForDatabase (db);
  if (connectionName == NULL)
    return -1;

  if (getSQLDataType (connectionName, tab, col, &dataType, &length) == 1)
    return -1;
  return dataType;
}

/**
 * Close a cursor opened.
 *
 * @param currname The name of the cursor.
 * @return
 */
int
A4GLSQL_close_cursor (char *currname)
{
  EXEC SQL BEGIN DECLARE SECTION;
  char *cursorName = currname;
  EXEC SQL END DECLARE SECTION;

  EXEC SQL CLOSE:cursorName;
  if (isSqlError ())
    return 1;
  return 0;
}

#define COLUMN_SIZE 0
#define DATA_TYPE   1

/**
 * Fill the array for columns.
 * 
 * @param tableName The name of the table to be checked.
 * @param max The max of columns that can be readed.
 */
static int
fillColumnsArray (char *tableName, int max, char *colArray,
		  int sizeColArray, char *array2, int sizeArray2, int mode)
{
  static char colname[64];
  int dtype;
  int size;
  int rv;
  int i = 0;
  char *ccol;

  strcpy (colname, "");
  A4GL_debug ("fillColumnsArray\n");


  rv = A4GLSQL_get_columns (tableName, colname, &dtype, &size);
  A4GL_debug ("Got rv as %d\n", rv);
  while (rv)
    {
      rv = A4GLSQL_next_column (&ccol, &dtype, &size);
      if (!rv)
	break;

      strcpy (colname, ccol);
      A4GL_trim (colname);
      strncpy (&colArray[i * (sizeColArray + 1)], colname, sizeColArray);


      if (array2 != (char *) 0)
	{


	  switch (mode)
	    {

	    case COLUMN_SIZE:
	      sprintf (&array2[i * (sizeArray2 + 1)], "%d", size);
	      break;
	    case DATA_TYPE:
	      sprintf (&array2[i * (sizeArray2 + 1)], "%d", dtype);
	      break;

	    default:
	      A4GL_exitwith ("Could not fill_array - Wrong mode asked!");
	    }
	}
      i++;
      if (i >= max)
	break;
    }
  rv = A4GLSQL_end_get_columns ();
  A4GL_debug ("returning %d columns rv=%d", i, rv);
  return i;
}

/**
 *
 * The fill_array are supposed to populate an array with information on
 * databases, tables or columns.
 * 
 * The returns are into an char[szarr], so arr1 should really be something like
 * char arr1[mx][szarr1] (if you see what I mean)...
 * 
 * The main interface is via fill_array where 'service' points to one of
 * the other functions (DATABASES, TABLES or COLUMNS)...
 * 
 * With service = DATABASES
 *   Mode  - not used
 *   Info - not used
 *   Arr1 = DBName
 *   Arr2 = Description ?
 * 
 * With service = TABLES
 *   Mode =1 Exclude system tables
 *   otherwise include them
 * 
 *   arr1 = Table name
 *   arr2 = Table description
 * 
 * With servce = COLUMNS
 *   Mode= 0 - Fill arr2 with colsize
 *         1 - Fill arr2 with datatype name
 *   Otherwise - fill it with the table name
 *   Info - Table name we're looking at
 *   arr1 = Column name
 * 
 * In all cases if the pointer the the array(arr1 or arr2) is 0 (or C-NULL) then
 * don't bother to fill it :-)
 *
 *
 * @param mx Maximum rows to fill in arr1/arr2.
 *
 * @param arr1 The adress where to return the information asked:
 *    DBName if service = DATABASES.
 *    Table name if service = TABLES.
 *    Column name if service = COLUMNS
 *
 * @param szarr1 Size of each item in array 1.
 *
 * @param arr2 adress of second array used to return information:
 *    - Description if service = DATABASES
 *    - Table description if service = TABLES
 *
 * @param szarr2 Size of each item in array 2.
 * @param service A string that defines the service wanted:
 *                  - DATABASES
 *                  - TABLES
 *                  - COLUMNS
 * @param mode specifies what data to load into the arrays.
 *   With service = TABLES
 *     - 1 Exclude system tables.
 *   With service = COLUMNS
 *     - 0 - Fill arr2 with colsize.
 *     - 1 - Fill arr2 with datatype name.
 * @param info passes some extra details into the functions (like table names 
 *             etc).
 *    With service = COLUMNS
 *      - Table name we're looking at
 *
 * @return The number of rows filled.
 * 
 */
int
A4GLSQL_fill_array (int mx, char *arr1, int szarr1, char *arr2, int szarr2,
		    char *service, int mode, char *info)
{
  A4GL_debug ("fill_array");
  if (strcmp (service, "DATABASES") == 0)
    A4GL_exitwith
      ("Could not fill_array - DATABASES service not implemented !");
  else if (strcmp (service, "TABLES") == 0)
    A4GL_exitwith ("Could not fill_array - TABLES service not implemented !");
  // This is the important to implement
  else if (strcmp (service, "COLUMNS") == 0)
    return fillColumnsArray (info, mx, arr1, szarr1, arr2, szarr2, mode);
  else
    A4GL_exitwith ("Could not fill_array - Invalid service asked !");
  return 0;
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
  A4GL_set_a4gl_status (a);
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
long
A4GLSQL_describe_stmt (char *stmt, int colno, int type)
{
  printf ("Describe smtm\n");
}


/**
 * Returns the dialect of SQL spoken by the currently
 * connected DBMS.
 *
 * @return  a char string "INFORMIX"
 */
char *
A4GLSQL_dbms_dialect (void)
{
  return "INFORMIX";
}

int
A4GLSQL_initlib ()
{
// Does nothing
}


struct expr_str *A4GL_add_validation_elements_to_expr(struct expr_str *ptr,char *val) {
char *ptr2;
char *ptrn;
char buff[256];
A4GL_trim(val);
ptr2=val;
while (1) {
        ptrn=strtok(ptr2,",");
        if (ptrn==0) break;
        if (ptr2) {ptr2=0;}

        sprintf(buff,"A4GL_push_char(\"%s\");",ptrn);

        if (ptr==0) {
                ptr=(struct expr_str *)A4GL_new_expr(buff);
        } else {
                A4GL_append_expr(ptr,buff);
        }

}
return ptr;
}


void *A4GLSQL_get_validation_expr(char *tabname,char *colname) {
EXEC SQL BEGIN DECLARE SECTION;
char buff[300];
char val[65];
struct expr_str *ptr=0;
EXEC SQL END DECLARE SECTION;
int cnt;
sprintf(buff,"select attrval from %s where attrname='INCLUDE' and tabname='%s' and colname='%s'",acl_getenv("A4GL_UPSCOL_VAL"),tabname,colname);
EXEC SQL PREPARE p_get_val FROM :buff;
if (sqlca.sqlcode!=0) return 0;
EXEC SQL DECLARE c_get_val CURSOR FOR p_get_val;
if (sqlca.sqlcode!=0) return 0;
EXEC SQL OPEN c_get_val ;
if (sqlca.sqlcode!=0) return 0;


while (1) {
	EXEC SQL FETCH c_get_val INTO  $val;
	if (sqlca.sqlcode!=0) break;
	//printf("---> %s\n",val);
	ptr=A4GL_add_validation_elements_to_expr(ptr,val);
	// Process it...
}
return ptr;

}


/* ================================= EOF ============================== */
