/**
 * @file
 * Test if the C function(s) popdtime and retdtime to put and retrieve 
 * date(s) in the stack work(s).
 */

#include <stdio.h>
#include "datetime.h"
#include "fglsys.h"

/**
 * Get a datetime value from the stack, and pop it to the stack again.
 * To be used in aubit 4gl tests.
 */
pop_ret_interval(int n_params) {
  intrvl_t interval_value;

  popinv(&interval_value,TU_DTENCODE(TU_HOUR,TU_SECOND));
	retinv(&interval_value);
	return 1;
}

