

#ifndef AUBITCONNECTION_INCL
#define AUBITCONNECTION_INCL


	namespace Aubit4glSql {
	  /**
	   * Each instance should be an opened connection to a database
	   */
	  class Connection {
	    public:
	      char *initUser(const char *userName);
	      char *initPassword(const char *passwd);
	      char *getUser();
	      char *getPassword();
	      char *getDatabaseName();
	      Driver *getDriver();

	    private:
	      void *pointer;        /**< A pointer to the opened connection */

	      /** A reference to the database driver used by the connection */
	      Driver *driver;

	      /**
	       * The type of the connection:
	       *   - UNIX_ODBC
	       *   - ESQL (informix direct connection)
	       *   - LIBPQ (postgres)
	       */
	      int connectionType;

	      string name;              /**< The name of the connection */
	      string databaseName;      /**< The name of the database */
	      string userName;          /**< The login name */
	      string password;          /**< Password of the user */
	  };
	}

#endif /* #ifndef AUBITCONNECTION_INCL */

