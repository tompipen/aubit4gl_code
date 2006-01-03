/**
 * @file
 * Test if the C function dectoint works ok
 */

#include <stdio.h>
#include "decimal.h"
#include "fglsys.h"

/**
 * Get a long value from the stack, convert to decimal and pop it to 
 * the stack again.
 * To be used in aubit 4gl tests.
 */
long_to_decimal(int n_params) {
	dec_t decimal_value;
	long long_value;
	int ok_code;

  poplong(&long_value);
	ok_code = deccvlong(long_value,&decimal_value);
	retint(ok_code);
	retdec(&decimal_value);
	return 2;
}
