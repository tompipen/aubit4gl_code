/**
 * @file
 * Test if the C function(s) popshort and retshort to put and retrieve int(s)
 * in the stack work(s).
 */

#include <stdio.h>
#include "decimal.h"
#include "fglsys.h"

/**
 * Get an int value from the stack, and pop it to the stack again.
 * To be used in aubit 4gl tests.
 */
pop_ret_short(int n_params) {
	short short_value;

  popshort(&short_value);
	retshort(short_value);
	return 1;
}
