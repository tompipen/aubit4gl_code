/**
 * @file
 * Test if the pushdec function works ok.
 */


#include <stdio.h>
#include "decimal.h"
#include "fglsys.h"
#include "fglapi.h"

/**
 * Insert a decimal value in the stack and execute a 4gl function to see if the
 * value returns equal.
 * To be used in aubit 4gl tests.
 */
main() {
  dec_t decimal_value;
  dec_t ret_decimal_value;
	extern int fgl_push_decimal();
	char str[] = "23415.87777788888";

	fgl_start("");
	deccvasc(str,strlen(str),&decimal_value);
	pushdec(&decimal_value,DECLEN(16,11));
	fgl_call(fgl_push_decimal,1);
	popdec(&ret_decimal_value);
	if ( deccmp(&decimal_value,&ret_decimal_value) != 0 )
	  exit(1);
	exit(0);
}
