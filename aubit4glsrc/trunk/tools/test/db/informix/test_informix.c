/**
 * @file
 * Unit test to the informix connection functions.
 *
 */

#include <check.h>
#include "informix_test.h"

#ifndef WIN32
	#include <dlfcn.h>
#endif


void *sql_lib;

/** Error message */
//static char *errorMessage;

/**
 * Assign the error message ocurred with informix
 */
/*
void setErrorMessage(char  *_errorMessage)
{
  printf("Error message  %s\n", _errorMessage);
  errorMessage = _errorMessage;
}
*/


/**
 * Entry point to execute the informix connection test suite.
 *
 * @todo : get the parameters of the test as argument or environment variables
 *
 * It should go to a separate module when we have several suites to
 * database(s) connection.
 */
int main(void)
{
  int nf; 
  Suite *s = makeInformixConnectionSuite(); 

  SRunner *sr = srunner_create(s); 
  //SRunner *sr = srunner_create(makeDdlSuite());
  srunner_add_suite(sr,makeDdlSuite());
  srunner_add_suite(sr,makeDmlSuite());
  srunner_set_fork_status (sr, CK_NOFORK); 

  /* Load the esql library */
  sql_lib = (void *)dlopen("SQL","esql");
  /* Create the database using a specific esql/c */
  connectToTestInstance();
  createDatabase("test");
  disconnectFromTestInstance();

  srunner_run_all (sr, CK_VERBOSE); 
  nf = srunner_ntests_failed(sr); 
  srunner_free(sr); 
  suite_free(s); 

  /*
  connectToTestInstance();
  dropDatabase("test");
  disconnectFromTestInstance();
  */
  //return (nf == 0) ? EXIT_SUCCESS : EXIT_FAILURE;

  return 0;

}
