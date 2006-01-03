/**
 * @file
 * Test if the C function dectoint works ok
 */

#include <stdio.h>
#include "decimal.h"
#include "fglsys.h"

/**
 * Get a decimal value from the stack, convert to int and pop it to 
 * the stack again.
 * To be used in aubit 4gl tests.
 */
convert_to_int(int n_params) {
	dec_t decimal_value;
	int int_value;
	int ok_code;

  popdec(&decimal_value);
	ok_code = dectoint(&decimal_value,&int_value);
	retint(ok_code);
	retint(int_value);
	return 2;
}
