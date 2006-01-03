/**
 * @file
 * Test if the pushflo function works ok.
 */


#include <stdio.h>
#include "fglsys.h"
#include "fglapi.h"

/**
 * Insert a float value in the stack and execute a 4gl function to see if the
 * value returns equal.
 * To be used in aubit 4gl tests.
 */
main() {
  float float_value;
  float ret_float_value;
	extern int fgl_push_float();

	float_value = 23415;
	fgl_start("");
	pushflo(&float_value);
	fgl_call(fgl_push_float,1);
	popflo(&ret_float_value);
	if ( float_value != ret_float_value )
	  exit(1);
	exit(0);
}
