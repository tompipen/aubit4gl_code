/**
 * @file
 * Test if the C function(s) popdub and retdub to put and retrieve floats(s)
 * in the stack work(s).
 */

#include <stdio.h>
#include "decimal.h"
#include "fglsys.h"

/**
 * Get an double value from the stack, and pop it to the stack again.
 * To be used in aubit 4gl tests.
 */
pop_ret_double(int n_params) {
	float double_value;

  popdub(&double_value);
	retdub(&double_value);
	return 1;
}
