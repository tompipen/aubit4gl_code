/**
 * @file
 * Test if the C function dectodbl works ok
 */

#include <stdio.h>
#include "decimal.h"
#include "fglsys.h"

/**
 * Get a decimal value from the stack, convert to double and pop it to 
 * the stack again.
 * To be used in aubit 4gl tests.
 */
decimal_to_double(int n_params) {
	dec_t decimal_value;
	double double_value;
	int ok_code;

  popdec(&decimal_value);
	ok_code = dectodbl(&decimal_value,&double_value);
	retint(ok_code);
	retdub(&double_value);
	return 2;
}
