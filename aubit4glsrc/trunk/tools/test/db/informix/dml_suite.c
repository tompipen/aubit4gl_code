/**
 * @file
 * Unit test to the informix data manipulation language.
 *
 * @todo : Finish all the test cases:
 *   - Error in sql.
 *   - Insert with constraint failed.
 *   - Insert for select
 *   - Update
 *   - Update binded
 *   - Update with constraint failed.
 *   - Delete
 *   - Delete with binded values
 *   - Delete with failed constraint.
 *   - Singleton Select
 *   - Transacion:
 *      - Two begins
 *      - Commit
 *      - Commit without begin
 *      - rollback
 *      - rollback without begin
 *   - Normal cursor:
 *      - open
 *      - Two opens
 *      - close without open
 *      - fetch until the end
 *   - scroll cursor:
 *      - open
 *      - fetch first
 *      - fetch last
 *      - fetch next
 *      - fetch previous
 *      - fetch absolute
 *      - fetch relative
 *   - Cursor for update
 *   - update where current of
 *   - Cursor with hold
 *   - Cursor for insert:
 *     - open
 *     - close
 *     - put
 *     - flush
 *   - select into temp
 */

#include <check.h>
#include "a4gl_libaubit4gl.h"
#include "informix_test.h"

/**
 * Test the insert in a table.
 *
 * @todo : Check with esql if the data was inserted.
 */
START_TEST(test_insert)
{
  struct s_sid *sid;
  int result;
  char strSql[512];
  struct BINDING ibind[] = {
    {0,0,0}
  };

  cleanTestTable();
  /** @todo : Inserting more columns */
  strcpy(strSql,
    "insert into test_table (an_int,a_char,a_decimal) values (2,'TWO',1234.56)"
  );
  sid = (struct s_sid *)A4GLSQL_prepare_glob_sql(
    strSql,0,ibind
  );
  fail_unless(sid!=(struct s_sid *)0,"Prepare insert failed");
  if ( sid==(struct s_sid *)0 )
    return;
  result = A4GLSQL_execute_implicit_sql(sid);
  fail_unless(result==0,"Execute insert failed");
  fail_unless(countTestRows() == 1, "No rows inserted");
  fail_unless(validateTestRow(2,"TWO",1234.56) == 1, "No rows inserted");
}
END_TEST

/**
 * Test the insert in a table with variable binding.
 *
 * @todo : Check with esql if the data was inserted.
 */
START_TEST(test_bind_insert)
{
  struct s_sid *sid;
  int result;
  long int_var = 100;
  char char_var[15] = "Hello world";
  struct BINDING ibind[] = {
   {&int_var,2,0},
   {&char_var,0,15}
  };
  char *strSql = "insert into test_table (an_int,a_char) values (?,?)";

  cleanTestTable();
  sid = (struct s_sid *)A4GLSQL_prepare_glob_sql(
    strSql,2,ibind
  );
  fail_unless(sid!=(struct s_sid *)0,"Prepare insert failed");
  if ( sid==(struct s_sid *)0 )
    return;
  //A4GLSQL_set_conn("test");
  result = A4GLSQL_execute_implicit_sql(sid);
  fail_unless(result==0,"Binded insert failed");
  fail_unless(countTestRows() == 1, "No rows inserted");
}
END_TEST

/**
 * Test an update in a table.
 *
 * @todo : Make the test.
 * @todo : Check with esql if the data was inserted.
 */
/* not used
START_TEST(test_update)
{
  struct s_sid *sid = 0;
  struct BINDING ibind[] = {
    {0,0,0}
  };

  //struct BINDING obind[] = {
  //   {0,0,0}
  //};

  char *strSql = "update test_table set an_int=99 where an_int=1";
  int result;

  cleanTestTable();
  insertTestRows();
  A4GLSQL_prepare_glob_sql(strSql,0,ibind);
  fail_unless(sid!=(struct s_sid *)0,"Prepare update failed");
  if ( sid==(struct s_sid *)0 )
    return;
  result = A4GLSQL_execute_implicit_sql(sid);
  fail_unless(countTestRowsWithWhere("an_int=99") == 1, "No rows updated");
}
END_TEST
*/

/**
 * Test an update in a table with variable binding.
 *
 * @todo : Check with esql if the data was inserted.
 */
/* not used
START_TEST(test_bind_update)
{
  struct s_sid *sid;
  int result;
  long int_var = 1;
  //char char_var[15] = "Hello world";
  struct BINDING ibind[] = {
   {&int_var,2,0},
   {&int_var,2,0}
  };
  char *strSql = "update test_table set an_int=? where an_int=?";

  cleanTestTable();
  insertTestRows();
  sid = (struct s_sid *)A4GLSQL_prepare_glob_sql(
    strSql,2,ibind
  );
  fail_unless(sid!=(struct s_sid *)0,"Prepare insert failed");
  if ( sid==(struct s_sid *)0 )
    return;
  //A4GLSQL_set_conn("test");
  result = A4GLSQL_execute_implicit_sql(sid);
  fail_unless(result==0,"Binded insert failed");
}
END_TEST
*/

/**
 * Test a delete in a table.
 *
 * @todo : Make the test.
 * @todo : Check with esql if the data was inserted.
 */
/*
START_TEST(test_delete)
{
}
END_TEST
*/

/**
 * Test a binded delete in a table.
 *
 * @todo : Make the test.
 * @todo : Check with esql if the data was inserted.
 */
/*
START_TEST(test_bind_delete)
{
}
END_TEST
*/

/**
 * Set up the test case.
 *
 * Connect to the database.
 *
 * Load the informix library and try to estabilish the database connection.
 */
static void setup(void)
{
  int result;
  result = A4GLSQL_init_connection("test");
  fail_unless(result==0,"Connection to test failed");
  createTestTable();
}

/**
 * Tear down the test case.
 *
 * Close the database connection.
 */
static void teardown(void)
{
  dropTestTable();
  fail_unless(
    //A4GLSQL_close_connection("test")==0, "Disconnect from test failed"
	A4GLSQL_close_connection()==0, "Disconnect from test failed"
  );
}

/**
 * Create the informix aubit 4gl data manipulation language.
 *
 * @return A pointer to the created informix test_suite.
 */
Suite *makeDmlSuite(void)
{
  Suite *s = suite_create("Informix native data definition language"); 
  TCase *tc_dml = tcase_create("Data Manipulation Language");
 
  suite_add_tcase (s, tc_dml);
 
  tcase_add_unchecked_fixture (tc_dml, setup, teardown);
  tcase_add_test (tc_dml,test_insert); 
  tcase_add_test (tc_dml,test_bind_insert); 
  return s; 
}

