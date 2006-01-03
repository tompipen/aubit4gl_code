/**
 * @file
 * Test if the C function dectoflt works ok
 */

#include <stdio.h>
#include "decimal.h"
#ifdef INFORMIX
	#include "fglsys.h"
#endif

/**
 * Get a decimal value from the stack, convert to float and pop it to 
 * the stack again.
 * To be used in aubit 4gl tests.
 */
#ifdef INFORMIX
decimal_to_float(int n_params) {
#else
aclfgl_decimal_to_float(int n_params) {
#endif
	dec_t decimal_value;
	float float_value;
	int ok_code;
	#ifdef INFORMIX
		popdec(&decimal_value);
	#else
		popdec_native(&decimal_value);
		//popdec(&decimal_value);
	#endif
	ok_code = dectoflt(&decimal_value,&float_value);
	retint(ok_code);
	retflo(&float_value);
	return 2;
}
