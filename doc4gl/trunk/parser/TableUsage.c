/**
 * @file 
 * Table usage functions implementation.
 */

#include <stdio.h>
#include <string.h>
#include "TableUsage.h"

/**
 * Alocate and initialize information of a new table usage.
 *
 * @return A pointer to the alocatted structure.
 */
TableUsage *newTableUsage(void)
{
  TableUsage *ptr;

	ptr = (TableUsage *)malloc(sizeof(TableUsage));
	if ( ptr == (TableUsage *)0 )
	  return (TableUsage *)0;
	ptr->foundAs    = TU_UNDEFINED;
	ptr->operation  = TU_UNDEFINED;
	ptr->tableName  = NULL;
	ptr->lineNumber = 0;
	return ptr;
}

/**
 * Assigns the name to a table usage function.
 *
 * The table name setted is alocated as a new string.
 *
 * @param tableName The name of the table.
 * @param tableUsage A pointer to the table usage.
 */
void setTableUsageTableName(char *tableName,TableUsage *tableUsage)
{
  tableUsage->tableName = strdup(tableName);
}

/**
 * Gets the name to a table usage function.
 *
 * @param tableUsage A pointer to the table usage.
 */
char *getTableUsageTableName(TableUsage *tableUsage)
{
  return tableUsage->tableName;
}
/**
 * Assigns the place where the table usage declaration was found
 *
 * @param foundAs The way it was found.
 * @param tableUsage A pointer to the table usage.
 */
void setTableUsageFoundAs(int foundAs,TableUsage *tableUsage)
{
  tableUsage->foundAs = foundAs;
}

/**
 * Assigns the operation type done to the table
 *
 * @param operation The operation done to the table.
 * @param tableUsage A pointer to the table usage.
 */
void setTableUsageOperation(int operation,TableUsage *tableUsage)
{
  tableUsage->operation = operation;
}

/**
 * Assigns the line number where the operation was found.
 *
 * @param lineNumber The line number in the source code where found.
 * @param tableUsage A pointer to the table usage.
 */
void setTableUsageLineNumber(int lineNumber,TableUsage *tableUsage)
{
  tableUsage->lineNumber = lineNumber;
}
