/**
 * @file
 * Test if the C function dectoflt works ok
 */

#include <stdio.h>
#include "decimal.h"
#include "fglsys.h"

/**
 * Get a decimal value from the stack, convert to float and pop it to 
 * the stack again.
 * To be used in aubit 4gl tests.
 */
decimal_to_float(int n_params) {
	dec_t decimal_value;
	float float_value;
	int ok_code;

  popdec(&decimal_value);
	ok_code = dectoflt(&decimal_value,&float_value);
	retint(ok_code);
	retflo(&float_value);
	return 2;
}
