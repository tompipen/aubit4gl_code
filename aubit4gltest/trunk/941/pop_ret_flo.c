/**
 * @file
 * Test if the C function(s) popflo and retflo to put and retrieve floats(s)
 * in the stack work(s).
 */

#include <stdio.h>
#include "decimal.h"
#include "fglsys.h"

/**
 * Get an int value from the stack, and pop it to the stack again.
 * To be used in aubit 4gl tests.
 */
pop_ret_float(int n_params) {
	float float_value;

  popflo(&float_value);
	retflo(&float_value);
	return 1;
}
