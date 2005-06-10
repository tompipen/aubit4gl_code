
/**
 * @file
 *
 * Implementation of exception used in the connections from aubit4gl
 * to a postgresql database.
 */

#include <stdlib.h>
#include <string.h>
#include "ConnectionException.h"

using namespace Aubit4glSql_postgresql;

/**
 * Constructor for a connection exception.
 *
 * @param errorText The text describing the exception ocurred.
 */
ConnectionException::ConnectionException(const char *_errorText)
{
  message = _errorText;
}


/**
 * Get the error message.
 */
const char *ConnectionException::getMessage() {
  return message;
}

