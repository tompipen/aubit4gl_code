/**
 * @file 
 *
 * The Aubit4gl to postgressql driver class.
 *
 * The object of this class represent a loaded driver.
 *
 * Duvidas:
 *  - Variavel de instancia nula ?
 *  - O que acontece se num map a chave nao existir ?
 *  - Como perceber que não existe ?
 */

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
#include "PgDriver.h"
#include "ConnectionException.h"

using namespace Aubit4glSql_postgresql;

/**
 * Default constructor
 */
PgDriver::PgDriver()
{
  currentConnection = (PgConnection *)0;
}

/**
 * Connect to the database using specific parameters
 *
 * @param connectionName The inernal name of the connection.
 * @param hostName Name of host to connect to. If it begins with a slash,
 *   it specifies Unix-domain communication rather than TCP/IP 
 *   communication; the value is the name of the directory in wich the 
 *   socket file is stored. the default is to connect to a Unix-domain 
 *   socket in /tmp.
 * @param tcpPort   Port number to connect to at server host or socket 
 *   file name extension for Unix-domain connections
 * @param hostaddr IP adress of host to connect to
 * @param dbName The database name.
 * @param userName The name of the user to connect as.
 * @param password the password to be used if the server demands password 
 *   authentication.
 * @param options Trace/Debug options to be send to the server.
 * @param tty A file or tty for optional debug output from the backend.
 * @param requireSsl Set to true to require SSL connection to the backend.
 *   Libpq then refuse to connect if the server does not suport SSL.
 */
PgConnection *PgDriver::connect(
                          const char *connectionName,
                          const char *hostName,
                          const char *hostAddr,
                          const char *tcpPort,
                          const char *dbName,
                          const char *userName,
                          const char *password,
                          const char *options,
                          const char *tty,
                          bool requireSsl)
{
  char conninfo[128];
  PGconn *libpqConnection;

  conninfo[0] = 0;

  setConnParam(conninfo,"host",hostName);
  setConnParam(conninfo,"hostaddr",hostAddr);
  setConnParam(conninfo,"port",tcpPort);
  setConnParam(conninfo,"dbname",dbName);
  setConnParam(conninfo,"user",userName);
  setConnParam(conninfo,"password",password);
  setConnParam(conninfo,"options",options);
  setConnParam(conninfo,"tty",tty);
  if ( requireSsl )
    setConnParam(conninfo,"requiressl","1");
  else
    setConnParam(conninfo,"requiressl","0");
  libpqConnection = PQconnectdb(conninfo);
  if (PQstatus(libpqConnection) != CONNECTION_OK )
  {
    PQfinish(libpqConnection);
    throw ConnectionException("Cant establish the connection");
  }

  PgConnection *pgConnection;
  pgConnection = new PgConnection;
  pgConnection->setPgConn(libpqConnection);
  registerConnection(connectionName,*pgConnection);
  return pgConnection;
}


/**
 * Connect to the database with the URL.
 *
 * @todo Implement it.
 * @param url The database url in a string.
 */
PgConnection& PgDriver::connect(const char *url)
{
	return *(new PgConnection());
}

/**
 * Utility method to make the connection to the database.
 *
 * @param connectionName The name of the connection.
 * @param databaseName The name of the database to connect to.
 * @param userName The name of the user.
 * @param password The password used to connect.
 */
PgConnection& PgDriver::connect(const char *connectionName,
		                const char *databaseName,
				const char *userName,
				const char *password)
{
	// @todo : Implement it
}

/**
 * Append a new parameter with a value to the conninfo string.
 * 
 * @param conninfo The string to be appended.
 * @param paramName The name of the parameter.
 * @param paramValue The value to be generated for the parameter.
 */
void PgDriver::setConnParam(char *conninfo,
                            const char *paramName,
                            const char *paramValue)
{
  static const char *separator = ";";

  if ( paramValue != NULL )
  {
    strcat(conninfo,paramName);
    strcat(conninfo,"='");
    strcat(conninfo,paramValue);
    strcat(conninfo,"'");
    strcat(conninfo,separator);
  }
}

/**
 * Register an established connection.
 *
 * @param connectionName The name of the connection.
 * @param pgConnection A pointer to the postgresql connection information.
 */
void PgDriver::registerConnection(const string connectionName,
		                  PgConnection &pgConnection)
{
  connectionList[connectionName] = pgConnection;
}

/**
 * Get the current connection.
 * If there is no current connection throw an exception.
 *
 * @return 
 *   - The current connection. 
 *   - Null if its not setted.
 */
PgConnection& PgDriver::getCurrentConnection()
{
  return *currentConnection;
}

/**
 * Set an open connection as the current one.
 *
 * @param connectionName The name of the existing connection to be 
 *   the current.
 */
void PgDriver::setCurrentConnection(const string& connectionName)
{
  if ( existConnection(connectionName) )
    currentConnection = &connectionList[connectionName];
  else
    throw new ConnectionException("Connection does not exist");
}

/**
 * Check if an existing connection exist in the driver list of active 
 * connections.
 *
 * @param connectionName The name of the connection.
 * @return The existance of the connection:
 *   - true : Exist.
 *   - false : Does not exist.
 */
bool PgDriver::existConnection(const string connectionName)
{
  if ( connectionList.find(connectionName) == connectionList.end() )
    return false;
  return true;
}

/**
 * Disconnect a connection by is name.
 *
 * @param connectionName The name of the connection wanted
 */
void PgDriver::disconnect(const char *connectionName)
{
  string connName(connectionName);
  PgConnection &connection = connectionList[connName];

  // @todo : Disconnect from postgresql
}

/**
 * Return the first connection to a database found.
 *
 * @param dbName The name of the database.
 */
PgConnection PgDriver::getConnectionToDatabase(const char *dbName)
{
	// @todo Implement it
}

/**
 * Get the connection name for a database name.
 *
 * @param dbName The name of the database.
 * @return
 *   - The name of the connection.
 *   - NULL : No such connection.
 */
const char *PgDriver::getConnectionNameToDatabase(const char *dbName)
{
	// @todo Implement it
  return "XX";
}
