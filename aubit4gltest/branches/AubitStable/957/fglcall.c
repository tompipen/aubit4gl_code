/**
 * @file
 * Test if the fgl_call function works ok.
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
	extern int called_function();

	int_value = 23415;
	fgl_start("");
	pushint(int_value);
	fgl_call(called_function,1);
	popint(&ret_int_value);
	if ( int_value / 2 != ret_int_value )
	  exit(1);
	exit(0);
}
