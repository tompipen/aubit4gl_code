/**
 * @file
 * Test if the C function dectodbl works ok
 */

#include <stdio.h>
#include "decimal.h"
#include "fglsys.h"

/**
 * Get a decimal value from the stack, convert to string and pop it to 
 * the stack again.
 * To be used in aubit 4gl tests.
 */
decimal_to_ascii(int n_params) {
	dec_t decimal_value;
	char char_value[33];
	int ndigit
	int ok_code;

  popdec(&decimal_value);
  popint(&ndigit);
	ok_code = dececvt(&decimal_value,ndigit, ???
	retint(ok_code);
	retdub(&double_value);
	return 2;
}
