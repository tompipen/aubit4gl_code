/**
 * @file
 * Test if the pushshort function works ok.
 */


#include <stdio.h>
#include "fglsys.h"
#include "fglapi.h"

/**
 * Insert a short value in the stack and execute a 4gl funcrion
 * To be used in aubit 4gl tests.
 */
main() {
  long long_value;
  long ret_long_value;
	extern int fgl_push_long();

	long_value = 23415;
	fgl_start("");
	pushint(long_value);
	fgl_call(fgl_push_long,1);
	popint(&ret_long_value);
	if ( long_value != ret_long_value )
	  exit(1);
	exit(0);
}
