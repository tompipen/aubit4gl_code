/**
 * @file
 * Test if the C function dectolong works ok
 */

#include <stdio.h>
#include "decimal.h"
#include "fglsys.h"

/**
 * Get a decimal value from the stack, convert to long and pop it to 
 * the stack again.
 * To be used in aubit 4gl tests.
 */
decimal_to_long(int n_params) {
	dec_t decimal_value;
	long long_value;
	int ok_code;

  popdec(&decimal_value);
	ok_code = dectolong(&decimal_value,&long_value);
	retint(ok_code);
	retlong(long_value);
	return 2;
}
