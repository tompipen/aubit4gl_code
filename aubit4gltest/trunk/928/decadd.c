/**
 * @file
 * Test if the C function decadd works ok.
 */

#include <stdio.h>
#include "decimal.h"
#include "fglsys.h"

/**
 * Get two decimal values from the stack, sum them and pop the result to
 * the stack.
 * To be used in aubit 4gl tests.
 */
decimal_add(int n_params) {
	dec_t decimal_one;
	dec_t decimal_two;
	dec_t decimal_result;
	int ok_code;

  popdec(&decimal_one);
  popdec(&decimal_two);
	ok_code = decadd(&decimal_one,&decimal_two,&decimal_result);
	retint(ok_code);
	retdec(&decimal_result);
	return 2;
}
