/**
 * @file
 * Test if the function deccvasc works ok
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
	char char_value[9];

  popquote(char_value,9);
	dectoasc(&decimal_value,char_value,9,6);
	retdec(&decimal_value);
	return 1;
}
