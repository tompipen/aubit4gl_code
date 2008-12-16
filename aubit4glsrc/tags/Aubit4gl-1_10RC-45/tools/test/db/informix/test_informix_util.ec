#include <string.h>

/**
 * @file
 * Informix native connection testing utilities.
 *
 * Here are implented functions that do the tests directly to the database.
 */

/**
 * @todo : Take off the malloc that is a memory leak.
 * Connect to informix test instance
 * @return 
 *   - 0 : Connection established.
 *   - 1 : An error as ocurred.
 */
int connectToTestInstance(void)
{
  EXEC SQL BEGIN DECLARE SECTION;
    char *msg = (char *)malloc(8191);
  EXEC SQL END DECLARE SECTION;

  EXEC SQL CONNECT TO DEFAULT;
  if ( SQLSTATE[0] = '0' && SQLSTATE[1] > '2' )
  {
    EXEC SQL get diagnostics exception 1 :msg = MESSAGE_TEXT;
    //setErrorMessage(strdup(msg));
    return 0;
  }
  return 1;
}

/**
 * @todo : Take off the malloc that is a memory leak.
 * Disconnect from informix test instance
 * @return 
 *   - 0 : Connection disconnected.
 *   - 1 : An error as ocurred.
 */
int disconnectFromTestInstance(void)
{
  EXEC SQL BEGIN DECLARE SECTION;
    char *msg = (char *)malloc(8191);
  EXEC SQL END DECLARE SECTION;

  EXEC SQL disconnect default;
  if ( SQLSTATE[0] = '0' && SQLSTATE[1] > '2' )
  {
    EXEC SQL get diagnostics exception 1 :msg = MESSAGE_TEXT;
    //setErrorMessage(strdup(msg));
    return 0;
  }
  return 1;
}

/**
 * drop the database in the database server.
 *
 * @param dbName The database name.
 * @return
 *   - 0 : Database removed
 *   - 1 : An error as ocurred.
 */
int dropDatabase(char *dbName)
{
  EXEC SQL BEGIN DECLARE SECTION;
    char *msg = (char *)malloc(8191);
    char *databaseName;
  EXEC SQL END DECLARE SECTION;
  int retval = 1;

  databaseName = strdup(dbName);
  //EXEC SQL CLOSE DATABASE;
  EXEC SQL DROP DATABASE :databaseName;
  if ( SQLSTATE[0] = '0' && SQLSTATE[1] > '2' )
  {
    EXEC SQL get diagnostics exception 1 :msg = MESSAGE_TEXT;
    printf("ERRO %s\n",msg);
    //setErrorMessage(strdup(msg));
    retval = 0;
  }
  free(databaseName);
  return retval;
}

/**
 * Create a datbase in the database server.
 *
 * @param dbName The database name.
 * @return
 *   - 0 : Database created.
 *   - 1 : An error as ocurred.
 */
int createDatabase(char *dbName)
{
  EXEC SQL BEGIN DECLARE SECTION;
    char *msg = (char *)malloc(8191);
    char *databaseName;
  EXEC SQL END DECLARE SECTION;
  int retval = 1;

  databaseName = strdup(dbName);
  EXEC SQL CREATE DATABASE :databaseName;
  if ( SQLSTATE[0] = '0' && SQLSTATE[1] > '2' )
  {
    EXEC SQL get diagnostics exception 1 :msg = MESSAGE_TEXT;
    printf("ERRO %s\n",msg);
    //setErrorMessage(strdup(msg));
    retval = 0;
  }
  EXEC SQL GRANT CONNECT TO "test_user";
  free(databaseName);
  return retval;
}

/**
 * Create the table that should be used as test table.
 */
int createTestTable(void)
{
  EXEC SQL create table test_table (
    an_int integer,
    a_char char(10)
  );
  /** @todo : Create the new data types
  a_smallint smallint,
  a_float float,
  a_smallfloat smallfloat,
  a_date date,
  a_decimal decimal(16,2),
  a_varchar varchar(255,10),
  a_interval interval year to minute,
  a_datetime datetime year to minute
  */
  /** @todo : Test diferent precisions of datatypes */
  /** @todo : Test not nulls */
  /** @todo : Use constraints:
    primary key (an_int)
   */
}

/**
 * Drop the test table
 */
int dropTestTable(void)
{
  EXEC SQL drop table test_table;
}

/**
 * Clean the data in the test table.
 */
int cleanTestTable()
{
  EXEC SQL delete from test_table;
}

/**
 * Count the number of rows in the test table.
 *
 * @return The number of rows in the test_table
 */
int countTestRows()
{
 EXEC SQL BEGIN DECLARE SECTION;
   int numRows;
 EXEC SQL END DECLARE SECTION;

 EXEC SQL select count(*) into :numRows from test_table;
 return numRows;
}

/**
 * Insert rows to tes update and delete.
 * @todo : Return errors if ocurred.
 */
int insertTestRows(void)
{
  EXEC SQL insert into test_table (an_int,a_char) values (1,"One");
}

/**
 * Validate if the test row is correctly at the database.
 * 
 * @param an_int_var
 * @param a_char_var
 * @param a_decimal_var
 * @return 
 *   - 1 : The row is invalid.
 *   - 0 : The row is valid.
 */
int
validateTestRow(int an_int_var,char *a_char_var,float a_decimal_var)
{
    return 0;
}

/**
 * Count the number of rows acording to the where clause.
 *
 * @param whereStr A string with the where clause
 * @return The count of rows acording to the where.
 *    - -1 : An error as ocurred.
 */
int countTestRowsWithWhere(char *str)
{
 EXEC SQL BEGIN DECLARE SECTION;
   int numRows;
   char *whereStr = str;
   char strSql[256];
 EXEC SQL END DECLARE SECTION;

 sprintf(strSql,"select count(*) from %s where %s","test_table",whereStr);
 EXEC SQL prepare statCount from :strSql;
 EXEC SQL select count(*) into :numRows from test_table;
 return numRows;
}

/**
 * Check if a table exist in the database.
 *
 * @todo : Implement it.
 *
 * @param tableName A string with the table name.
 */
int tableExist(char *tableName)
{
  return 1;
}
