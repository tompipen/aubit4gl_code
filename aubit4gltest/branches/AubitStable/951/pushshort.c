/**
 * @file
 * Test if the pushshort function works ok.
 */


#include <stdio.h>
#include "fglsys.h"
#include "fglapi.h"

/**
 * Insert a short value in the stack and execute a 4gl funcrion
 * To be used in aubit 4gl tests.
 */
main() {
  short short_value;
  short ret_short_value;
	extern int fgl_push_short();

	short_value = 23415;
	fgl_start("");
	pushint(short_value);
	fgl_call(fgl_push_short,1);
	popint(&ret_short_value);
	if ( short_value != ret_short_value )
	  exit(1);
	exit(0);
}
