/**
 * @file
 * Test if the C function deccvint works ok
 */

#include <stdio.h>
#include "decimal.h"
#include "fglsys.h"

/**
 * Get a decimal value from the stack, convert to char and pop it to 
 * the stack again.
 * To be used in aubit 4gl tests.
 */
convert_to_decimal(int n_params) {
	dec_t decimal_value;
	int int_value;

  popint(&int_value);
	deccvint(int_value,&decimal_value);
	retdec(&decimal_value);
	return 1;
}
