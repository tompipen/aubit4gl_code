/**
 * @file Implementation of methods for prepared statments
 */

#include "PreparedStatement.h"

using namespace Aubit4glSql_postgresql;

/**
 * Prepare an sql statement.
 *
 * In this (postgresql) specific case the statement is just parsed to find
 * the bind places (with ?) because postgesql does not have preparation of 
 * statements.
 *
 * @todo Implement this
 *
 * @param sql The sql statement text.
 */
void PreparedStatement::prepare(const char *sql)
{
}
