/**
 * @file
 * Test if the function deccvasc works ok
 */

#include "decimal.h"
#include "fglsys.h"

/**
 * Get a decimal value from the stack, convert to char and pop it to 
 * the stack again.
 * To be used in aubit 4gl tests.
 */
convert_to_decimal(int n_params) {
	dec_t decimal_value;
	char char_value[8];

  popquote(char_value,8);
	deccvasc(char_value,7,&decimal_value);
	retdec(&decimal_value);
	return 1;
}
