
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
     char *connectionName;
     char *databaseName;
     /** Message of last error ocurred */
     char *errorMessage;
     PGconn *pgConn;
   public:
     PgConnection();
     PgConnection(const char *_dbName, const char *_connName);
     ~PgConnection();
     void setPgConn(PGconn *PGconn);
     const char *getConnectionName();
     const char *getDatabaseName();
     char *getErrorMessage();
  };
}

#endif
