
/**
 * @file
 *
 * Header file for the prepared statement of the aubit 4gl database connection.
 */

#ifndef PGDRIVER_INCL
#define PGDRIVER_INCL

namespace Aubit4glSql_postgresql {

 class PreparedStatement {
   private:
	   /** A list of the bind variables */
		 /** The sql statement text with bind points (?) */
   public:
	   void prepare(const char *sql);
 };
}

#endif
