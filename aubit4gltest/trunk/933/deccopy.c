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
decimal_copy(int n_params) {
	dec_t dec_original;
	dec_t dec_copy;
	int ok_code;

  popdec(&dec_original);
	deccopy(&dec_original,&dec_copy);
	retint(ok_code);
	retdec(&dec_copy);
	return 1;
}
