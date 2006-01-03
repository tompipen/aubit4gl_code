/**
 * @file
 * Test if the C function(s) popquote and retquote to put and retrieve char(s)
 * in the stack work(s).
 */

#include <stdio.h>
#include "decimal.h"
#include "fglsys.h"

/**
 * Get a char value from the stack, and pop it to the stack again.
 * To be used in aubit 4gl tests.
 */
pop_ret_char(int n_params) {
  char char_value[65];

  popquote(char_value,64);
	retquote(char_value);
	return 1;
}
