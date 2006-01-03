/**
 * @file
 * Test if the C function(s) popvchar and retvchar to put and retrieve 
 * varchar(s) in the stack work(s).
 */

#include <stdio.h>
#include "decimal.h"
#include "fglsys.h"

/**
 * Get a varchar value from the stack, and pop it to the stack again.
 * To be used in aubit 4gl tests.
 */
pop_ret_varchar(int n_params) {
  char varchar_value[65];

  popquote(varchar_value,64);
	retquote(varchar_value);
	return 1;
}
