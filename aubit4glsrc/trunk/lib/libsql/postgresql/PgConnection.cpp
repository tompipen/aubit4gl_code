
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
 * Assign the pointer to the native connection.
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
const char *PgConnection::getConnectionName()
{
  return connectionName;
}

/**
 * Acessor to the name of the database of the connection
 *
 * @return The name of the database
 */
const char *PgConnection::getDatabaseName()
{
  return databaseName;
}

/**
 * Acessor to the message of the last error ocurred.
 *
 * @return The error message
 */
char *PgConnection::getErrorMessage()
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
 * Destructor that free the unecessary information
 */
PgConnection::~PgConnection()
{
  free(databaseName);
  free(connectionName);
}
