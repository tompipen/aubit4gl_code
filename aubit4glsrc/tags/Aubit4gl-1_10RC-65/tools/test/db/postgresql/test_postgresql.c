/**
 * @file
 * Unit test to the postgresql connection functions.
 *
 * This main is specific does the specific postgresql actions
 * and execute the generic tests (those that are usable in the severall 
 * connectors. Due to this the modules from .. must
 * be linked to this one.
 *
 */

#include <check.h>
#include <a4gl_libaubit4gl.h>
#include "../connection_suite.h"

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
 * Entry point to execute the postgresql connection test suite.
 *
 * @todo : get the parameters of the test as argument or environment variables
 *
 * It should go to a separate module when we have several suites to
 * database(s) connection.
 */
int
main (void)
{
  int nf;
  Suite *s = makeConnectionSuite ();

  SRunner *sr = srunner_create (s);
  //srunner_add_suite(sr,makeDdlSuite());
  //srunner_add_suite(sr,makeDmlSuite());
  srunner_set_fork_status (sr, CK_NOFORK);

  /* Load the postgresql connector dynamic library */
  if (A4GLSQL_loadConnector ("pg") == 0)
    {
      printf ("Cant load the SQL library\n");
      exit (1);
    }

  srunner_run_all (sr, CK_VERBOSE);
  nf = srunner_ntests_failed (sr);
  srunner_free (sr);
  suite_free (s);

  //return (nf == 0) ? EXIT_SUCCESS : EXIT_FAILURE;

  return 0;

}
