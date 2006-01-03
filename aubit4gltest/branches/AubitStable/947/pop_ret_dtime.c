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
pop_ret_datetime(int n_params) {
  dtime_t datetime_value;

	// @todo : Falta o qualificador. Ver no manual de New Era
  popdtime(&datetime_value,TU_DTENCODE(TU_YEAR,TU_FRAC));
	retdtime(&datetime_value);
	return 1;
}

