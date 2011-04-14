
/**
 * @file 
 * The aubit 4gl connection manager implementation.
 */


#include "ConnectionManager.h"

using namespace Aubit4glSql;

// This is to go away
char *acl_getenv(char *);
// Until here

void 
ConnectionManager::setCurrentConnection(const char *connectionName) 
{
}

char *
ConnectionManager::getCurrentConnection()
{
}

void 
ConnectionManager::setConnection(Connection connection)
{
}

Connection *
ConnectionManager::getConnection(const char *connectionName)
{
}

/**
 * Check if there is a connection
 *
 * @param connectionName the name of the connection wanted
 */
bool ConnectionManager::isConnection(const char *connectionName)
{
}

void ConnectionManager::loadDriver(const char *driverName)
{
}

void ConnectionManager::unloadDriver(const char *driverName)
{
}

void ConnectionManager::testDriverInterface(void)
{
}

/**
 * Acessor for the user name used in the connection
 *
 * @return The user name
 */
char *Connection::getUser()
{
}

/**
 * Acess to the password used to connect
 *
 * @return The passorwd
 */
char *Connection::getPassword()
{
  return password.c_str();
}

/**
 * Access the name of the opened database of the connection
 *
 * @return The name of the database
 */
char *Connection::getDatabaseName(void)
{
  return databaseName.c_str();
}

/**
 * Access the driver used to estabilish the connection to the database.
 *
 * @return  A pointer to the connection
 */
Driver *Connection::getDriver(void)
{
}

/**
 *  Increment the statement count
 */
void Driver::incrementStatement()
{
  statementCount++;
}

/**
 * Create a unique name for a statement in a driver
 *
 * @return A string with the statement name
 */
char *Driver::getStatementName()
{
  static char statementName[32];

	sprintf(statementName,"st_%d",statementCount);
	return statementName;
}


/**
 * Initialize the user name used to access the password.
 * The username returned is allocated here, so need to be freed when 
 * no longer needed.
 *
 * @param userName The user name passed (could be null)
 * @return The user name to use.
 */
char *Connection::initUser(const char *userName)
{
  static char *retUser;
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
char *Connection::initPassword(const char *passwd)
{
  static char *retPasswd;
  if ( passwd != NULL )
    return strdup(passwd);
  /** @todo : Confirm if this should be the env var name to be used */
  retPasswd = acl_getenv("SQLPWD");
  if ( retPasswd != NULL )
    return strdup(retPasswd);
  return retPasswd;
}

