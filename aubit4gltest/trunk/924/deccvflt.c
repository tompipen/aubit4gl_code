/**
 * @file
 * Test if the C function deccvflt works ok
 */

#include <stdio.h>
#include "decimal.h"
#include "fglsys.h"

/**
 * Get a float value from the stack, convert to decimal and pop it to 
 * the stack again.
 * To be used in aubit 4gl tests.
 */
float_to_decimal(int n_params) {
	dec_t decimal_value;
	float float_value;
	int ok_code;

  popflo(&float_value);
	ok_code = deccvflt(float_value,&decimal_value);
	retint(ok_code);
	retdec(&decimal_value);
	return 2;
}
