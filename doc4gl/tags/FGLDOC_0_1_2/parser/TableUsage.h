/**
 * @file
 * Header file for typedefs and prototypes of table usages.
 */
#define TABLE_SELECT 0
#define TABLE_INSERT 1
#define TABLE_UPDATE 2
#define TABLE_DELETE 3

#define TU_UNDEFINED -1
#define TU_SQL       0
#define TU_COMMENT   1

/**
 * Table usage information.
 */
typedef struct {
	int  foundAs;             /* How the table usage was found */
	int  operation;           /* Operation executed */
  char *tableName;   
	int  lineNumber;          /* The line where the usage was found in source */
}TableUsage;

TableUsage *newTableUsage(void);
void setTableUsageTableName(char *tableName,TableUsage *tableUsage);
char *getTableUsageTableName(TableUsage *tableUsage);
void setTableUsageFoundAs(int foundAs,TableUsage *tableUsage);
void setTableUsageOperation(int operation,TableUsage *tableUsage);
void setTableUsageLineNumber(int lineNumber,TableUsage *tableUsage);
