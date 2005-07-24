/**
 * @file
 * Functions for abstract tree management / access.
 */

#include <stdio.h>
#include "p4gl_symtab.h"
#include "p4gl.h"

/**
 * Gets the number of functions loaded at the abstract tree.
 * @return The number of functions loaded by the parser.
 */
int getFunctionIdx(void)
{
  return P4glCb.idx_funcoes;
}

/**
 * Gets the function information by is sequence in the array.
 *
 * @param The sequence / order of loading from the function.
 * @return The pointer to the function structure typedef.
 */
FUNCTION *getFunction(int sequence)
{
  if ( sequence > getFunctionIdx())
	  return (FUNCTION *)0;
	return &(P4glCb.functions[sequence]);
}

/**
 * Gets the table usage index.
 *
 * @param The function pointer to the structure / typedef used.
 * @return The table usage index.
 */
int
getFunctionTableUsageIdx(FUNCTION *function)
{
  return function->idxTableUsage;
}

/**
 * Sets the table usage index.
 *
 * @param The function pointer to the structure / typedef used.
 * @return The table usage index.
 */
void setFunctionTableUsageIdx(FUNCTION *function,int idxTableUsage)
{
  if ( getFunctionTableUsageIdx(function) >= MAXSQL )
		P4glError(ERROR_EXIT,
		  "setTableUsageIdx() : Table usage by function exceded\n");
  function->idxTableUsage = idxTableUsage;
}

/**
 * Gets the table usage information in a function.
 *
 * @param function The function where to find the table usage.
 * @param sequence The sequence of table usage inside the function.
 * @return The pointer to the table usage.
 */
TableUsage *getFunctionTableUsage(FUNCTION *function,int sequence)
{
  if ( sequence > getFunctionTableUsageIdx(function) )
	  return (TableUsage *)0;
  return function->tableUsage[sequence];
}

/**
 * Add a new table usage to the function.
 *
 * @param function A pointer to the function identification structure.
 * @param tableUsage A pointer to the table usage identification structure.
 */
void addFunctionTableUsage(FUNCTION *function, TableUsage *tableUsage)
{
	int tableUsageIdx = getFunctionTableUsageIdx(function);
  if ( tableUsageIdx >= MAXSQL )
		P4glError(ERROR_EXIT,"addTableUsage() : Table usage by function exceded\n");
  function->tableUsage[tableUsageIdx] = tableUsage;
  tableUsageIdx++;
	setFunctionTableUsageIdx(function,tableUsageIdx);
}

/**
 * Get the number of sql statements in a function
 * 
 * @param function Pointer to the function definition structure.
 * @return The number of SQL statements read.
 */
int getFunctionSqlIdx(FUNCTION *function)
{
  return function->idx_sql;
}

/**
 * Gets the information about a SQL in a function.
 *
 * @param function Pointer to the function information.
 * @param sequence Index in the array wanted.
 */
SQL *getFunctionSql(FUNCTION *function,int sequence)
{
	if ( sequence > function->idx_sql )
	  return (SQL *)0;
  return &(function->sql[sequence]);
}

/**
 * Gets the number of tables used in a SQL statement.
 *
 * @param sql A pointer to the SQL statement.
 * @return The number of table used.
 */
int getSqlTableIdx(SQL *sql)
{
  return sql->idx_tabelas;
}

/**
 * Gets the table name used at a specified position.
 *
 * @param sql A pointer to the SQL statement.
 * @param sequence The sequence of the table in the array
 * @return A Pointer to the table name.
 */
char *getSqlTable(SQL *sql,int sequence)
{
	if ( sequence > sql->idx_tabelas )
	  return NULL;
  return sql->tabelas[sequence];
}
