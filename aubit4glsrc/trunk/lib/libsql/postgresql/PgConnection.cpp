
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
 * @param _dbName The name of the database as a char pointer.
 * @param _connName The name to assign to this connection.
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
 * @param _pgConn The pointer to the postgresql connection.
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
 * Get the error code of the last error ocurred in the connection.
 *
 * @todo : Implement it
 * @return The error code.
 */
int PgConnection::getError(void) 
{
}

/**
 * Get the message last error ocurred in the connection.
 * 
 * @todo Check if this method is not redundant with getErrorMessage
 * @return The error message.
 */
char *PgConnection::getLastError(void) 
{
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
 * Get the prepared statement from the list of statements prepared on this
 * connection.
 */
PreparedStatement &PgConnection::getPreparedStatement(char *statementName)
{
}

/**
 * Store the prepared statement on the statement list.
 *
 * @param name The name of the statement.
 * @param sid A pointer to the statement identification structure.
 */
void PgConnection::setPreparedStatement(const string& name,struct s_sid *sid) 
{
}

/**
 * Creates a PreparedStatement object for sending parameterized SQL statements 
 * to the database.
 * 
 * @todo : Implement it
 *
 * @param sqlTxt The sql command to be prepared.
 * @return The prepared statement.
 */
PreparedStatemement PgConnection::prepareStatement(char *sqlTxt) 
{
}

/**
 * Get the cursor from the list of opened cursors of the connection.
 *
 * @todo : Implement it
 * @param cursorName -the name of the cursor.
 * @return The Result set object that identify the cursor.
 */
ResultSet &PgConnection::getCursor(char *cursorName) 
{
}

/**
 * Delete a cursor from the list of opnend  cursors.
 *
 * @todo : Implement it
 * @param cursorName -the name of the cursor.
 */
void PgConnection::getCursor(char *cursorName) 
{
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
 * Obtain an object to access to the meta information about the database where 
 * the connection is estabilished.
 * It does stay with any reference stored in the connection. There are specific
 * methods that stay with the metadata insisde the connection.
 *
 * @todo : Implement it
 * @return A reference to the meta information about the database.
 */
DatabaseMetaData &PgConnection::getMetaData() {
    // instatiate the metadata object with new()
}

/**
 * Store a reference to the metadata and the opened result set.
 * 
 * @todo Implement it
 * @param md A reference to the netadata object.
 * @param rs A reference to the Rseult set object.
 */
void PgConnection::storeMetaData(DatabaseMetaData &md, ResultSet &rs)
{
}

/**
 * Get the result set of the currently stored metadata.
 *
 * @todo Implement it
 * @return A reference to the stored metadata.
 */
ResultSet &PgConnection::getStoredRsMetadata(void)
{
}

/**
 * Free the alocated resources used to the current metadat.
 * Delete all resources and close the result set if it exists.
 */
void PgConnection::freeStoredMetadata(void) 
{
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


extern "C" char *
A4GLSQL_dbms_dialect( void )
{
	return "POSTGRESQL";
}


// ================================ EOF =============================

