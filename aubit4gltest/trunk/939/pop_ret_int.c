/**
 * @file
 * Test if the C function(s) popint and retint to put and retrieve int(s)
 * in the stack work(s).
 */

#include <stdio.h>
#include "decimal.h"
#include "fglsys.h"

/**
 * Get an int value from the stack, and pop it to the stack again.
 * To be used in aubit 4gl tests.
 */
pop_ret_int(int n_params) {
	int int_value;

  popint(&int_value);
	retint(int_value);
	return 1;
}
