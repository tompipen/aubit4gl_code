/**
 * @file
 * Unit test to the aubit 4gl connection functions.
 *
 * This test case can be used in development stage to test if we can
 * connect to the database.
 *
 * It should be linked with apropriate main that loads the proper 
 * connector shared library.
 *
 * To run this tests agains a database we need:
 *   - Create a database called "test"
 *   - Create a user called "test_user" with password "test_password"
 *   - Grant connect permissions of that user to the database.
 *   - Set the aubit4gl environment variables in order that can 
 *     access to the database:
 *       - user ???
 *       - password ???
 *   - Remove any database called "wrong_db" if it exist.
 *   - Revoke  permissions from a user called "wrong_user" in "test" 
 *     database if it exist.
 *
 * @todo : Finish all the test cases:
 *   -
 */

#include <check.h>
#include "connection_suite.h"
#include "a4gl_API_sql.h"


/**
 * Test if the connection is established and if with wrong parameters
 * give an error.
 *
 * We need to create the database "test" to be shure that we can work with.
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
 * Test if the connect function tells us that the connection
 * to a database that does not exist was that connection
 * was OK.
 */
START_TEST(test_wrong_init_connection)
{
  fail_unless(A4GLSQL_init_connection("wrong_db") != 0,
    "Connection to not existant database does not return error"
  );
}
END_TEST

/**
 * Test if we can connect to the database using the make_connection
 * function.
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
 * Test if the function to make the connections tells us 
 * that it was connected even if it was impossible 
 * because the user does not exist.
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
 * Test the init_session function, that initializes a connection 
 * to a database called test with a user with name test_user and
 * a password test_password.
 */
START_TEST(test_init_session)
{
  /* Test a correct named connection */
  if ( A4GLSQL_init_session ("session","test","test_user","test_password")==1 )
    fail("Named connection (init_session) failed");
  printf("Init passed\n");
  fail_unless(
    A4GLSQL_close_session("session")==0,
    "Disconnect from named session in test failed"
  );
}
END_TEST

/**
 * test if connecting to the database with wrong 
 * parameters (user) does not give error that should 
 * give.
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
 * Test if the set_conn does work to establish a connection.
 *
 * @todo uncomment the commented code.
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
 */
static void setup(void)
{
}

/**
 * Tear down the test case.
 */
static void teardown(void)
{
}

/**
 * Create the aubit 4gl connection test suite.
 *
 * @return A pointer to the created connection test_suite.
 */
Suite *makeConnectionSuite(void)
{
  Suite *s = suite_create("Database connection"); 
  TCase *tc_connection = tcase_create("Connection");
 
  suite_add_tcase (s, tc_connection);
 
  tcase_add_test (tc_connection,test_init_session);
  tcase_add_test (tc_connection,test_wrong_init_session);
  tcase_add_test (tc_connection,test_make_connection);
  tcase_add_test (tc_connection,test_wrong_make_connection);
  tcase_add_test (tc_connection,test_init_connection); 
  tcase_add_test (tc_connection,test_wrong_init_connection);
  tcase_add_test (tc_connection,test_set_conn);
  tcase_add_unchecked_fixture (tc_connection, setup, teardown);
  return s; 
}

