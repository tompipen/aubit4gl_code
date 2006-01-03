/**
 * @file
 * Test if the C function deccmp works ok.
 */

#include <stdio.h>
#include "decimal.h"
#include "fglsys.h"

/**
 * Get two decimal values from the stack, compare them and pop the result to
 * the stack.
 * To be used in aubit 4gl tests.
 */
decimal_cmp(int n_params) {
	dec_t decimal_one;
	dec_t decimal_two;
	int ok_code;

  popdec(&decimal_two);
  popdec(&decimal_one);
	ok_code = deccmp(&decimal_one,&decimal_two);
	retint(ok_code);
	return 1;
}
