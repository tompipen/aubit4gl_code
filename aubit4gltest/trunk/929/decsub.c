/**
 * @file
 * Test if the C function decsub works ok.
 */

#include <stdio.h>
#include "decimal.h"
#include "fglsys.h"

/**
 * Get two decimal values from the stack, subtract them and pop the result to
 * the stack.
 * To be used in aubit 4gl tests.
 */
decimal_sub(int n_params) {
	dec_t decimal_one;
	dec_t decimal_two;
	dec_t decimal_result;
	int ok_code;

  popdec(&decimal_two);
  popdec(&decimal_one);
	ok_code = decsub(&decimal_one,&decimal_two,&decimal_result);
	retint(ok_code);
	retdec(&decimal_result);
	return 2;
}
