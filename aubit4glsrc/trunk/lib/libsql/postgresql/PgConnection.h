
/**
 * @file
 *
 * Header file for the connection class to connect Aubit4gl to Postgresql.
 */

#ifndef PGCONNECTION_INCL
#define PGCONNECTION_INCL

namespace Aubit4glSql_postgresql {

 class PgConnection {
   private:
     char *connectionName;  /**< The name of the connection */
     char *databaseName;    /**< The database name where is connected to */
     char *userName;        /**< User name used to connect */
     char *password;        /**< The password used to connect */
     PGconn *pgConn;        /**< A pointer to the libpq connection */
     int statementCount;    /**< The number of statements used */
     char *errorMessage;    /**< Message of last error ocurred */
   public:
     PgConnection();
     PgConnection(const char *_dbName, const char *_connName);
     ~PgConnection();
     void setPgConn(PGconn *PGconn);
     const char *getConnectionName();
     const char *getDatabaseName();
     char *getErrorMessage();
     int getError();
     char *getGlobalStatementName(void);
  };
}

#endif
