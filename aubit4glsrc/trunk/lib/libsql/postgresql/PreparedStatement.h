
/**
 * @file
 *
 * Header file for the prepared statement of the aubit 4gl database connection.
 */

#ifndef PGDRIVER_INCL
#define PGDRIVER_INCL

namespace Aubit4glSql_postgresql
{

  class PreparedStatement
  {
  private:
      /** A list of the bind variables */
      /** The sql statement text with bind points (?) */
    string name;
      /** Generate a name for the statememtn whne it is not named */
    void generateName (void);
  public:
    void prepare (const char *sql);
    char *getName ();
    ResultSet executeQuery ();
    int executeUpdate ();
      /** 
       * Store a pointer to the aubit 4gl statement identification.
       *
       * @param sid The pointer to the a4gl statement.
       */
    void setA4glStatement (A4glStatement * sid);
    A4glStatement *getA4glStatement ();
  };
}

#endif
