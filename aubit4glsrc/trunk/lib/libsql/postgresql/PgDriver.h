/**
 * @file
 *
 * Header file for the driver class to connect Aubit4gl to Postgresql.
 */

#ifndef PGDRIVER_INCL
#define PGDRIVER_INCL

#include <string>
#include <map>

using namespace std;

namespace Aubit4glSql_postgresql {

 class PgDriver {
   private:
     typedef map<const string,PgConnection> Connections;

     /** A list of the active connections */
     Connections connectionList;

     /** The current connection */
     PgConnection *currentConnection;

     PgConnection *connect(const char *connectionName,
                          const char *hostName,
                          const char *hostAddr,
                          const char *tcpPort,
                          const char *dbName,
                          const char *userName,
                          const char *password,
                          const char *options,
                          const char *tty,
                          bool requireSsl);

     void setConnParam(char *conninfo,
                       const char *paramName,
                       const char *paramValue);
     void registerConnection(const string connectionName,
                             PgConnection &pgConnection);
   public:
     PgDriver();
     PgConnection& connect(const char *url);
     PgConnection& connect(const char *connectionName,
                           const char *databaseName,
                           const char *userName,
                           const char *password);
     bool existConnection(char *connectionName);
     bool existConnection(const string& connectionName);
     void disconnect(const char *connectionName);
     bool setCurrentConnection(const string& connectionName);
     PgConnection& getCurrentConnection();
     PgConnection getConnectionToDatabase(const char *dbName);
     const char *getConnectionNameToDatabase(const char *dbName);
 };
}
#endif
