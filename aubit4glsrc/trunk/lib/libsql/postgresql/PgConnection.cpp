
/**
 * @file Implementation of methods for the postgres connection definition
 * class.
 *
 * @todo Store all the postgres driver specific information.
 */

#include <stdlib.h>
#include <string.h>

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

using namespace Aubit4glSql_postgresql;

/**
 *  The default constructor.
 */
PgConnection::PgConnection()
{
  statementCount = 0;
}

/**
 * One convenient constructor.
 *
 * @param _dbName
 * @param _connName
 */
PgConnection::PgConnection(const char *_dbName, const char *_connName)
{
  PgConnection();
  databaseName = strdup(_dbName);
  connectionName = strdup(_connName);
}

/**
 * Assign the pointer to the native postgresql connection.
 *
 * @param _pgConn The pointer to the connection
 */
void PgConnection::setPgConn(PGconn *_pgConn)
{
  pgConn = _pgConn;
}


/**
 * Acessor to the name of the connection.
 *
 * @return The name of the connection.
 */
const char *PgConnection::getConnectionName(void)
{
  return connectionName;
}

/**
 * Acessor to the name of the database of the connection
 *
 * @return The name of the database
 */
const char *PgConnection::getDatabaseName(void)
{
  return databaseName;
}

/**
 * Disconnect from the database.
 */
void PgConnection::disconnect(void) 
{
  PQfinish(pgConn);
}

/**
 * Acessor to the message of the last error ocurred.
 *
 * @return The error message
 */
char *PgConnection::getErrorMessage(void)
{
  return errorMessage;
}

/**
 * Get a unique name for a global (not named) statement.
 * To obtain it increment the static statementCount.
 *
 * @return The global statement count @return The global statement count.
 */
char *PgConnection::getGlobalStatementName(void)
{
  static char statementName[10];

  sprintf(statementName,"st_%d",statementCount);
  return statementName;
}

/**
 * Start a new transaction over the database.
 */
void PgConnection::begin() 
{
  PGResult res;
  res = PQexec(pgConn,"BEGIN");
  if ( !res || PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    PQclear(res);
    throw SQLException("Error starting a transaction");
  }
}

/**
 * Makes all changes since the previous begin work permanent and releases
 * any database locks currently held by this connection object.
 */
void PGConnection::commit() 
{
  PGResult res;
  res = PQexec(pgConn,"COMMIT");
  if ( !res || PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    PQclear(res);
    throw SQLException("Error starting a transaction");
  }
}


/**
 * Undoes all changes made in the current transaction and releases any 
 * database locks currently held by this Connection object. 
 */
void PgConnection::rollback()
{
  PGResult res;
  res = PQexec(pgConn,"ROLLBACK");
  if ( !res || PQresultStatus(res) != PGRES_COMMAND_OK)
  {
    PQclear(res);
    throw SQLException("Error starting a transaction");
  }
}

/**
 * Destructor that free the unecessary information
 */
PgConnection::~PgConnection()
{
  disconnect();
  free(databaseName);
  free(connectionName);
}

/*
 conversion can be automated for the native Postgres interface
 if you just include the following function :

*/


char *
A4GLSQL_dbms_dialect( void )
{
	return "POSTGRESQL";
}


// ================================ EOF =============================

