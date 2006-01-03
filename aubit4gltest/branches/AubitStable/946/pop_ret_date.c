/**
 * @file
 * Test if the C function(s) popdate and retdate to put and retrieve 
 * date(s) in the stack work(s).
 */

#include <stdio.h>
#include "fglsys.h"

/**
 * Get a date value from the stack, and pop it to the stack again.
 * To be used in aubit 4gl tests.
 */
pop_ret_date(int n_params) {
  long date_value;

  popdate(&date_value);
	retdate(date_value);
	return 1;
}
