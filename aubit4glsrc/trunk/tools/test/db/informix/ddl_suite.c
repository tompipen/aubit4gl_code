/**
 * @file
 * Unit test to the informix data definition language.
 *
 * @todo : Finish all the test cases:
 *   -
 */

#include <check.h>
//#include "a4gl_database.h"
#include "a4gl_libaubit4gl.h"
#include "informix_test.h"

/**
 * Test if it can create a table.
 *
 * @todo : Check with esql if the table was created.
 */
START_TEST(test_create_table)
{
  struct s_sid *sid;
  int result;
  char *strSql = "create table test_table (an_int integer,a_char char(10), a_decimal decimal(16,2))";
  sid = (struct s_sid *)A4GLSQL_prepare_glob_sql(
    strSql,0,(struct BINDING *)0
  );
  fail_unless(sid!=(struct s_sid *)0,"Prepare failed");
  //A4GLSQL_set_conn("test");
  result = A4GLSQL_execute_implicit_sql(sid);
  fail_unless(result==0,"Create table failed");
}
END_TEST

/**
 * Test if it can drop a table.
 *
 * @todo : Check with esql if the table was created.
 */
START_TEST(test_drop_table)
{
  struct s_sid *sid;
  int result;
  char *strSql = "drop table test_table";
  sid = (struct s_sid *)A4GLSQL_prepare_glob_sql(
    strSql,0,(struct BINDING *)0
  );
  fail_unless(sid!=(struct s_sid *)0,"Prepare failed");
  //A4GLSQL_set_conn("test");
  result = A4GLSQL_execute_implicit_sql(sid);
  fail_unless(result==0,"Drop table failed");
  fail_unless(tableExist("test_table") ==1,
    "Table that should be created does not exist"
  );
}
END_TEST

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
}

/**
 * Tear down the test case.
 *
 * Close the database connection.
 */
static void teardown(void)
{
  fail_unless(
    //A4GLSQL_close_connection("test")==0, "Disconnect from test failed"
	A4GLSQL_close_connection()==0, "Disconnect from test failed"
  );
}

/**
 * Create the informix aubit 4gl data definition language.
 *
 * @return A pointer to the created informix test_suite.
 */
Suite *makeDdlSuite(void)
{
  Suite *s = suite_create("Informix native data definition language"); 
  TCase *tc_dll = tcase_create("Data Definition Language");
 
  suite_add_tcase (s, tc_dll);
 
  tcase_add_unchecked_fixture (tc_dll, setup, teardown);
  tcase_add_test (tc_dll,test_create_table); 
  tcase_add_test (tc_dll,test_drop_table); 
  return s; 
}

