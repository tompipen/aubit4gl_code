/**
 * @file
 * Test if the pushint function works ok.
 */


#include <stdio.h>
#include "fglsys.h"
#include "fglapi.h"

/**
 * Get a locator value from the stack, and pop the file name where it is
 * to the stack again.
 * To be used in aubit 4gl tests.
 */
main() {
  int int_value;
  int ret_int_value;
	extern int fgl_push_int();

	int_value = 23415;
	fgl_start("");
	pushint(int_value);
	fgl_call(fgl_push_int,1);
	popint(&ret_int_value);
	if ( int_value != ret_int_value )
	  exit(1);
	exit(0);
}
