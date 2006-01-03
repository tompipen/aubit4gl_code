/**
 * @file
 * Test if the fgl_exitfm function works ok.
 * @todo : Understand what to test with this
 */


#include <stdio.h>
#include "fglsys.h"
#include "fglapi.h"

/**
 * Insert a value to stack execute a 4gl function and see if 
 * it was executed.
 * To be used in aubit 4gl tests.
 */
main() {
  int int_value;
  int ret_int_value;
	extern int menu_function();

	fgl_start("");
	fgl_call(menu_function,0);
	fgl_exitfm();
	exit(0);
}
