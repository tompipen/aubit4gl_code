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


/**
 * Generate a name to the current statement (if it is not allready named).
 * 
 * @todo Implement it
 */
void PreparedStatement::generateName(void) 
{
}


/**
 * Get the name of the prepared statement.
 * 
 * @todo Implement it
 */
void PreparedStatement::getName(void) 
{
}


/**
 * Execute the prepared statemement as a query.
 * 
 * @todo Implement it
 */
ResultSet PreparedStatement::executeQuery(void) 
{
}

/**
 * Execute the prepared statemement as a update, insert or delete.
 * 
 * @todo Implement it
 */
int PreparedStatement::executeUpdate(void) 
{
}


/** 
 * Store a pointer to the aubit 4gl statement identification.
 *
 * @todo Implement it
 * @param sid The pointer to the a4gl statement.
 */
void PreparedStatement::setA4glStatement(A4glStatement *sid)
{
}

/**
 * Get the 4gl statement stored here.
 *
 * @todo Implement it
 * @return The prepared statement
 */
A4glStatement *PreparedStatement::getA4glStatement(void) 
{
}



