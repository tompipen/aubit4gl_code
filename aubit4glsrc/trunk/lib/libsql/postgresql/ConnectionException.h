
/**
 * @file
 *
 * Header file for the exception used in the connections from aubit4gl
 * to a postgresql database.
 */

#ifndef CONNECTIONEXCEPTION_INCL
#define CONNECTIONEXCEPTION_INCL

namespace Aubit4glSql_postgresql
{
  class ConnectionException
  {
  private:
    const char *message;

  public:
      ConnectionException (const char *errorText);
    const char *getMessage ();
  };
}

#endif
