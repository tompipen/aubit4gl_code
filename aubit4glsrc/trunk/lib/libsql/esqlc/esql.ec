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
# $Id: esql.ec,v 1.6 2002-03-14 22:29:43 saferreira Exp $
#
*/

/*
 * @file
 *
 * Implementation of the direct connection of aubit 4gl to Informix database
 * using esql/c.
 *
 * since on Windows only ESQL/C supported compiler is Visual C++,
 * we must be carefull not to include anything that will conflict with
 * MSVC here, since resulting .c need to be compiled and linked by MSVC
 */

#ifndef lint
static const char rcs[] = "@(#)$Id: esql.ec,v 1.6 2002-03-14 22:29:43 saferreira Exp $";
#endif

#define DEFINE_SQLCA

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

#include "../../libincl/constats.h"

EXEC SQL include sqlca.h;
//EXEC SQL include sqlda;

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

/* stack.h will eventually include stdlib.h, which uses getenv(), so 
 * we need to set GETENV_OK and only then include debug.h
 */
#include "libincl/stack.h"
#define GETENV_OK
#include "libincl/debug.h"

typedef unsigned char UCHAR;
char lasterrorstr[1024] = "";

/** The global (not named) statement count, to generate unique names */
static int statementCount = 0;

/** Indicate if an error as ocurred in order to return error codes */
static int errorOcurred;

/**
 * Handle the ocurrence of sql errors.
 */
static void esqlErrorHandler(void)
{
}

/**
 * Handle the ocurrence of sql warnings.
 */
static void esqlWarningHandler(void)
{
}

/**
 * Check if there was an sql error
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
 * Initialization of the sql library.
 *
 * Does nothing.
 * @todo : Call an warning and error hanlder.
 */
void
A4GLSQL_initlib (void)
{
  EXEC SQL whenever sqlerror call esqlErrorHandler;
  EXEC SQL whenever sqlwarning call esqlWarningHandler;
  /* Does nothing */
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

/**
 * Initialize the default connection to the database.
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
int A4GLSQL_close_connection()
{
  return A4GLSQL_close_session("default");
}


int
A4GLSQL_get_status ()
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


int
A4GLSQL_read_columns (char *tabname, char *colname, int *dtype, int *size)
{
  exitwith ("Could not read_columns - noODBC build");

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
int A4GLSQL_make_connection (
  const UCHAR *server,const UCHAR *uid_p,const UCHAR *pwd_p)
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
  free(dbName);
  free(userName);
  free(passwd);
  return retval;
}


int A4GLSQL_get_datatype (char *db, char *tab, char *col)
{
  exitwith ("Could not get_datatype - noODBC build");
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
  retUser = acl_getenv("SQLUID");
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
  retPasswd = acl_getenv("SQLPWD");
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
  return retval;
}

/**
 * create an sql statement structure.
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
  /* printf("SQL %s\n",statementText); */
  EXEC SQL PREPARE :statementName FROM :statementText;
  if ( isSqlError() )
  {
    free(sid);
    return (struct s_sid *)0;
  }
  return sid;
}


/**
 * Prepare a global SQL statement (not named).
 *
 * @todo : Make all the assertions that i can.
 *
 * I should create this function if want to have create table
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

    char *char_var;
    int smint_var, *smint_ptr;
    long int_var, *int_ptr;
    double float_var, *float_ptr;
    float smfloat_var, *smfloat_ptr;
    /*
    fgldecimal decimal_var;
    fgldate date_var;
    fglmoney money_var;
    struct_dtime  dtyme_var;
    fglbyte byte_var;
    fgltext text_var;
    struct_ival  interval_var;
    */
  EXEC SQL END DECLARE SECTION;

  dataType = getIfmxDataType(bind[idx].dtype);
  length   = bind[idx].size;
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
      break;
    case DTYPE_DATE:
      break;
    case DTYPE_MONEY:
      break;
    case DTYPE_DTIME:
      break;
    case DTYPE_BYTE:
      break;
    case DTYPE_TEXT:
      break;
    case DTYPE_INTERVAL:
      break;
    default:
      exitwith ("Invalid data type\n");
  }
  if ( isSqlError() )
    return 1;
  return 0;

  /*
  else if ( valueIsNull() )
  {
    debug("%s -- null\n", function);
    type = SQLCHAR;
    EXEC SQL SET DESCRIPTOR :nm_ibind VALUE :index
      TYPE = :type, LENGTH = 0, INDICATOR = -1;
  }
  else 
  {
    switch (type)
    {
      case ????:
	dbd_ix_debug(2, "%s -- integer\n", function);
	type = SQLINT;
	intvar = SvIV(val);
	EXEC SQL SET DESCRIPTOR :nm_ibind VALUE :index
	  TYPE = :type, DATA = :intvar;
	break;
      case ????:
	dbd_ix_debug(2, "%s -- numeric\n", function);
	type = SQLFLOAT;
	numeric = SvNV(val);
	EXEC SQL SET DESCRIPTOR :nm_ibind VALUE :index
	  TYPE = :type, DATA = :intvar;
        break;
      case ????:
      default:
	dbd_ix_debug(2, "%s -- string\n", function);
	type = SQLCHAR;
	string = SvPV(val, len);
	length = len + 1;
        if (length == 1)
    }
  }

{
*/
/**
** Even if you insert "" as a literal into a VARCHAR(), you get
** a blank returned.  If you manage to insert a zero length
** string via a variable into a VARCHAR, then you get a NULL
** output string.  This is arguably a bug, but oh well!
*/
/*
string = " ";
length = 2;
}
EXEC SQL SET DESCRIPTOR :nm_ibind VALUE :index
TYPE = :type, LENGTH = :length,
DATA = :string;
#endif
	}
	dbd_ix_sqlcode(imp_sth->dbh);
	if (sqlca.sqlcode < 0)
	{
		rc = 0;
	}
	dbd_ix_exit(function);
	return(rc);
	*/
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
  static const char function[] = "bindInputValue";
  EXEC SQL begin declare section;
    char   *descriptorName = descName;
    int    index = idx+1;
    int    length;
    int    dataType;
    loc_t  blob;

    char *char_var;
    int smint_var, *smint_ptr;
    long int_var, *int_ptr;
    double float_var, *float_ptr;
    float smfloat_var, *smfloat_ptr;
    /*
    fgldecimal decimal_var;
    fgldate date_var;
    fglmoney money_var;
    struct_dtime  dtyme_var;
    fglbyte byte_var;
    fgltext text_var;
    struct_ival  interval_var;
    */
  EXEC SQL END DECLARE SECTION;

  dataType = getIfmxDataType(bind[idx].dtype);
  length   = bind[idx].size;
  switch (dataType)
  {
    case DTYPE_CHAR:
    case DTYPE_VCHAR:
      EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
        :length = LENGTH;

      char_var = malloc(length + 1);
      EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
        :char_var = DATA;
      bind[idx].ptr = char_var;
      break;
    case DTYPE_SMINT:
      EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
        :dataType = TYPE,
        :smint_var = DATA;
      smint_ptr = malloc(sizeof(int));
      *smint_ptr = smint_var;
      bind[idx].ptr = smint_ptr;
      break;
    case DTYPE_INT:
      EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
        :dataType = TYPE,
        :int_var = DATA;
      int_ptr = malloc(sizeof(long));
      *int_ptr = int_var;
      bind[idx].ptr = int_ptr;
      break;
    case DTYPE_FLOAT:
      EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
        :dataType = TYPE,
        :float_var = DATA;
      float_ptr = malloc(sizeof(double));
      *float_ptr = float_var;
      bind[idx].ptr = float_ptr;
      break;
    case DTYPE_SMFLOAT:
      EXEC SQL GET DESCRIPTOR :descriptorName  VALUE :index
        :dataType = TYPE,
        :smfloat_var = DATA;
      smfloat_ptr = malloc(sizeof(float));
      *smfloat_ptr = smfloat_var;
      bind[idx].ptr = smfloat_ptr;
      break;
    case DTYPE_DECIMAL:
      break;
    case DTYPE_DATE:
      break;
    case DTYPE_MONEY:
      break;
    case DTYPE_DTIME:
      break;
    case DTYPE_BYTE:
      break;
    case DTYPE_TEXT:
      break;
    case DTYPE_INTERVAL:
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
static int processOutputBind(char *descName,int bCount,struct BINDING *bind)
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

  switch (getStatementBindType(sid))
  {
    /*
    case NO_BIND:
      break;
      */
    case INPUT_BIND:
      EXEC SQL DEALLOCATE DESCRIPTOR :inputDescriptorName;
      break;
    case OUTPUT_BIND:
      EXEC SQL DEALLOCATE DESCRIPTOR :outputDescriptorName;
      break;
    case INPUT_OUTPUT_BIND:
      EXEC SQL DEALLOCATE DESCRIPTOR :inputDescriptorName;
      EXEC SQL DEALLOCATE DESCRIPTOR :outputDescriptorName;
      break;
  }
  if ( isSqlError() )
    rc = 1;
  return rc;
}


/**
 * Execute an sql statement where the its execution is implicit in 4gl.
 *
 * I should make this to have create table
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

  statementName  = sid->statementName;

  if ( sid->ibind != (struct BINDING *)0 && sid->ni > 0 )
  {
    descriptorName = getDescriptorName(statementName,'I');
    inputBindCount = sid->ni;

    if ( processInputBind(descriptorName,inputBindCount,sid->ibind) == 1)
      rc = 1;
    else
    {
      EXEC SQL EXECUTE :statementName USING SQL DESCRIPTOR :descriptorName;
    }
  }
  else
  {
    debug("Query %s \n",sid->select);
    debug("Statement name %s \n",statementName);
    EXEC SQL EXECUTE :statementName;
  }

  if ( isSqlError() )
    rc = 1;
  EXEC SQL DEALLOCATE DESCRIPTOR :descriptorName;
  return rc;
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
  if ( isSqlError() )
    return 1;
  return 0;
}


int
A4GLSQL_fill_array (int mx, char **arr1, int szarr1, char **arr2, int szarr2,
		    char *service, int mode, char *info)
{
  exitwith ("Could not fill_array - noODBC build");
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
int A4GLSQL_execute_sql_from_ptr (char *pname, int ni, char **ibind)
{
  return 0;
}

/**
 * Process the binds of a statement.
 *
 * the structure s_sid is expanded to have the descriptor names.
 * 
 * @param sid A pointer to the statement identification structure.
 * @return
 *  - 0 : Binds made.
 *  - 1 : Error making binds
 */
static int processStatementBinds(struct s_sid *sid)
{
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

    if ( processOutputBind(sid->outputDescriptorName,sid->no,sid->obind) == 1)
      return 1;
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

  if ( sid->obind != (struct BINDING *)0 && sid->no > 0 )
  {
    descriptorName = sid->inputDescriptorName;
    EXEC SQL DEALLOCATE DESCRIPTOR :descriptorName;
    free(descriptorName);
  }
  if ( isSqlError() )
    rc = 1;

  if ( sid->ibind != (struct BINDING *)0 && sid->ni > 0 )
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
int A4GLSQL_execute_implicit_select (struct s_sid *sid)
{
  EXEC SQL begin declare section;
    char *statementName;
    char *statementText;
  EXEC SQL end declare section;

  debug("execute_implicit_select");
  if (sid == 0)
    return -1;

  /** Todo : We must free the statementName somehow */
  sid->statementName = strdup(getGlobalStatementName());
  if ( processStatementBinds(sid) == 1 )
    return 1;
  if ( executeStatement(sid) == 1 )
    return 1;
  if ( deallocateDescriptors(sid) == 1 )
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
struct s_sid *
A4GLSQL_prepare_select (struct BINDING *ibind, int ni, struct BINDING *obind, int no, char *s)
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
 *
 * @param upd_hold
 * @param scroll Flag that indicate that the cursor have scroll:
 *   - 0 : Does not have scroll.
 *   - 1 : Have scroll.
 * @return The cursor type
 */
static int getCursorType(int upd_hold,int scroll)
{
  if ( scroll == 0 )
    return SIMPLE;
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

  cursorIdentification = malloc(sizeof(struct s_cid));
  cursorIdentification->statement = sid;
  switch (getCursorType(upd_hold,scroll))
  {
    case SIMPLE:
      EXEC SQL DECLARE :cursorName CURSOR FOR :statementName;
      break;
    case SIMPLE_SCROLL:
      EXEC SQL DECLARE :cursorName SCROLL CURSOR FOR :statementName;
      break;
    case FOR_UPDATE:
      /*
      EXEC SQL DECLARE :cursorName CURSOR FOR :statementName
        FOR UPDATE;
	*/
      break;
    case FOR_UPDATE_WITH_HOLD:
      /*
      EXEC SQL DECLARE :cursorName SCROLL CURSOR FOR :statementName
	WITH HOLD FOR UPDATE;
	*/
      break;
    case WITH_HOLD:
      /*
      EXEC SQL DECLARE :cursorName SCROLL CURSOR FOR :statementName
	WITH HOLD;
	*/
      break;
  }
  if ( isSqlError() )
    return (struct s_cid *)0;
  return cursorIdentification;
}

/*
int A4GLSQL_set_sqlca_sqlcode (int a)
{
  status = a;
  sqlca.sqlcode = a;
}
*/

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
    char *statementName;
  EXEC SQL END DECLARE SECTION;

  EXEC SQL OPEN :cursorName;
  if ( isSqlError() )
    return 1;
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
 * @param nibind Count of elements in the bind array.
 * @param ibind A pointer to the input bind array.
 * @return
 *   - 1 : Cursor fetched.
 *   - 0 : An error as ocurred.
 */
int
A4GLSQL_fetch_cursor (char *cursor_name,
		      int fetch_mode, int fetch_when, int nibind,
		      struct BINDING *ibind)
{
  EXEC SQL BEGIN DECLARE SECTION;
    char *cursorName = cursor_name;
    char *descriptorName;
    int position = fetch_when;
  EXEC SQL END DECLARE SECTION;

  if ( ibind != (struct BINDING *)0 && nibind > 0 )
  {
    descriptorName = getDescriptorName(cursor_name,'I');

    if ( processInputBind(descriptorName,nibind,ibind) == 1)
      exitwith ("Error binding");
  }

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
  return 0;
}

/**
 * Put the information in an insert cursor.
 * 
 * @todo : Fix the parameters. We need the cursor name.
 *
 * @param ibind The bind array
 * @param n The number of elements in the bind array.
 * @return
 *   - 1 : Data inserted in the cursor.
 *   - 0 : An error as ocurred.
 */
int A4GLSQL_put_insert (struct BINDING *ibind, int n)
{
  /*
  if ( ibind != (struct BINDING *)0 && nibind > 0 )
  {
    descriptorName = getDescriptorName(statementName,'I');

    if ( processInputBind(descriptorName,nibind,ibind) == 1)
      exitwith ("Error binding");
  }
  */
  //EXEC SQL PUT :cursorName FROM :state
}

/**
 * @todo : UImplement the unload
 */
int A4GLSQL_unload_data (char *fname, char *delims, char *sql1)
{
  exitwith ("Could not unload_data - noODBC build");
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
int A4GLSQL_commit_rollback (int mode)
{
  debug ("In commit_rollback");

  /*
  ptr = acl_getenv ("TRANSMODE");
  if (strlen(ptr))
    tmode = atoi(ptr);
  else
    tmode = 0;
    */

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
  if ( isSqlError() )
    return 1;
  return 0;
}

/**
 * Find a prepared statement.
 *
 * There should be a global strucutre or array where to store all the
 * prepared statements.
 *
 * @param pname The statement name.
 * @param mode
 * @return 
 *   - A pointer to the structure found in the tree.
 *   - 0 : The structure was not found
 */
struct s_sid *A4GLSQL_find_prepare (char *pname, int mode)
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
int A4GLSQL_flush_cursor (char *cursor)
{
  EXEC SQL BEGIN DECLARE SECTION;
    char *cursorName = cursor;
  EXEC SQL END DECLARE SECTION;

  EXEC SQL FLUSH :cursorName;
  if ( isSqlError() )
    return 1;
  return 0;
}

/**
 * Execute an SQL statement.
 *
 * @param pname  The prepared statement name.
 * @param ni Number of elements in the input bind.
 * @param ibind The input binding array used.
 * @return
 */
int A4GLSQL_execute_sql (char *pname, int ni, struct BINDING *ibind)
{
  struct s_sid *sid;

  exitwith ("Could not execute_sql - noODBC build");
  sid = newStatement(ibind,ni,(struct BINDING *)0,0,NULL);
  sid->statementName = pname;
  if ( processStatementBinds(sid) == 1 )
    return 1;
  if ( executeStatement(sid) == 1 )
    return 1;
  if ( deallocateDescriptors(sid) == 1 )
    return 1;
  return 0;
}

