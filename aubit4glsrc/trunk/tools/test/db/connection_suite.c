/**
 * @file
 * Unit test to the informix connection functions.
 *
 * @todo : Finish all the test cases:
 *   -
 */

#include <check.h>
#include "informix_test.h"

/**
 * Test if the connection is established and if with wrong parameters
 * give an error.
 *
 * @todo : Break this test in severall 
 *
 * We need to create the database to be shure that we can work with.
 */
START_TEST(test_init_connection)
{
  fail_unless(A4GLSQL_init_connection("test")==0,"Connection to test failed");
  fail_unless(
    A4GLSQL_close_connection()==0,
    "Disconnect from test failed"
  );
}
END_TEST

/**
 *
 */
START_TEST(test_wrong_init_connection)
{
  fail_unless(A4GLSQL_init_connection("wrong_db") != 0,
    "Connection to not existant database does not return error"
  );
}
END_TEST

/**
 *
 */
START_TEST(test_make_connection)
{
  /* We need a user test_user created with test_password */
  fail_unless(A4GLSQL_make_connection ("test","test_user","test_password")==0,
    "Connection to test with user and password failed"
  );
  fail_unless(
    A4GLSQL_close_connection()==0,
    "Disconnect from test failed"
  );
}
END_TEST


/**
 *
 */
START_TEST(test_wrong_make_connection)
{
  /* Test with wrong password */
  fail_unless(A4GLSQL_make_connection ("test","test_user","wrong_passwd")!=0,
    "Connection with wrong password does not give error"
  );
  /* Test with wrong user */
  fail_unless(A4GLSQL_make_connection("test","wrong_user","test_password")!=0,
    "Connection with wrong user does not give error"
  );
  /* Test with wrong database */
  fail_unless(
    A4GLSQL_make_connection ("wrong_db","test_user","test_password")!=0,
    "Connection with wrong password does not give error"
  );
}
END_TEST

/**
 *
 */
START_TEST(test_init_session)
{
  /* Test a correct named connection */
  fail_unless(
    A4GLSQL_init_session ("session","test","test_user","test_password")==0,
    "Named connection"
  );
  fail_unless(
    A4GLSQL_close_session("session")==0,
    "Disconnect from named session in test failed"
  );
}
END_TEST

/**
 *
 */
START_TEST(test_wrong_init_session)
{
  /* Test a incorrect user name named connection */
  fail_unless(
    A4GLSQL_init_session ("session","test","wrong_user","test_password")!=0,
    "Named Connection with wrong user does not give error"
  );
}
END_TEST

  /* ... */

/**
 *
 */
START_TEST(test_set_conn)
{
  /* Try to set a connection current */
  /*
  fail_unless(A4GLSQL_set_conn ("session")==0,
    "Make a connection default"
  );
  */
  // Ha aqui qualquer coisa que deixa a conexao aberta
}
END_TEST

/**
 * Set up the test case.
 *
 * Load the informix library and try to estabilish the database connection.
 */
static void setup(void)
{
}

/**
 * Tear down the test case.
 *
 * Close the database connection.
 */
static void teardown(void)
{
}

/**
 * Create the informix aubit 4gl connection test suite.
 *
 * @return A pointer to the created informix test_suite.
 */
Suite *makeInformixConnectionSuite(void)
{
  Suite *s = suite_create("Informix native connection"); 
  TCase *tc_connection = tcase_create("Connection");
 
  suite_add_tcase (s, tc_connection);
 
  tcase_add_test (tc_connection,test_init_connection); 
  tcase_add_test (tc_connection,test_wrong_init_connection);
  tcase_add_test (tc_connection,test_make_connection);
  tcase_add_test (tc_connection,test_wrong_make_connection);
  tcase_add_test (tc_connection,test_init_session);
  tcase_add_test (tc_connection,test_wrong_init_session);
  tcase_add_test (tc_connection,test_set_conn);
  tcase_add_unchecked_fixture (tc_connection, setup, teardown);
  return s; 
}

