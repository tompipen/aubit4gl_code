/**
 * @file
 * Test if the pushdub function works ok.
 */


#include <stdio.h>
#include "fglsys.h"
#include "fglapi.h"

/**
 * Insert a double value in the stack and execute a 4gl function to see if the
 * value returns equal.
 * To be used in aubit 4gl tests.
 */
main() {
  double double_value;
  double ret_double_value;
	extern int fgl_push_double();

	double_value = 23415.87777788888;
	fgl_start("");
	pushdub(&double_value);
	fgl_call(fgl_push_double,1);
	popdub(&ret_double_value);
	if ( double_value != ret_double_value )
	  exit(1);
	exit(0);
}
