
/**
 * @file 
 * The aubit 4gl connection manager
 */

#include <string>
#include <map>
#include "AubitDatabaseDriver.h"
#include "AubitConnection.h"

namespace Aubit4glSql {

  typedef std::map<string,Driver> Drivers;
  typedef std::map<string,Connection> Connections;
  
  class ConnectionManager {
	  private:
      char *curentConnection;
		  Drivers drivers;
		  Connections connections;
      void testDriverInterface(void);
    public:
      void setCurrentConnection(const char *connectionName);
      char *getCurrentConnection(void);
      void setConnection(Connection connection);
      Connection *getConnection(const char *connectionName);
      bool isConnection(const char *connectionName);
      void loadDriver(const char *driverName);
      void unloadDriver(const char *driverName);
  };
}
  

