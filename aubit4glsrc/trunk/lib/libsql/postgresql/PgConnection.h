
/**
 * @file
 *
 * Header file for the connection class to connect Aubit4gl to Postgresql.
 */

#ifndef PGCONNECTION_INCL
#define PGCONNECTION_INCL

using namespace std;

namespace Aubit4glSql_postgresql {

 class PgConnection {
   private:
     /** The map of prepared statememnts, indexed by the statement name */
     typedef map<const string,PreparedStatement> Statements;

     /** The list of statements */
     Statements statements;

     char *connectionName;  /**< The name of the connection */
     char *databaseName;    /**< The database name where is connected to */
     char *userName;        /**< User name used to connect */
     char *password;        /**< The password used to connect */
     PGconn *pgConn;        /**< A pointer to the libpq connection */
     int statementCount;    /**< The number of statements used */
     char *errorMessage;    /**< Message of last error ocurred */
   public:
     PgConnection(void);
     PgConnection(const char *_dbName, const char *_connName);
     ~PgConnection(void);
     void setPgConn(PGconn *PGconn);
     const char *getConnectionName(void);
     const char *getDatabaseName(void);
     void disconnect(void);
     char *getErrorMessage(void);
     int getError(void);
     char *getLastError(void);
     char *getGlobalStatementName(void);
     PreparedStatement getPreparedStatement(char *name);
     void setPreparedStatement(const string& name,struct s_sid *sid);
     PreparedStatemement prepareStatement(char *s);
     ResultSet &getCursor(char *cursorName);
     void deleteCursor(char *cursorName);
     void begin(void);
     void commit(void);
     void rollback(void);
     DatabaseMetadata &getMetaData(void);
     void storeMetaData(DatabaseMetaData &md, ResultSet &rs);
     ResultSet &getStoredRsMetadata(void);
     void freeStoredMetadata(void);
  };
}

#endif
