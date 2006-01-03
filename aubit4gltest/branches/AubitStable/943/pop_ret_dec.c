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
pop_ret_decimal(int n_params) {
  dec_t decimal_value;

  popdub(&decimal_value);
	retdub(&decimal_value);
	return 1;
}
