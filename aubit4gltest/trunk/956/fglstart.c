/**
 * @file
 * Test if the fglstart function works ok.
 */


#include <stdio.h>
#include "decimal.h"
#include "fglsys.h"
#include "fglapi.h"

/**
 * Execute a 4gl function.
 * To be used in aubit 4gl tests.
 */
main() {
  int int_value;
  int ret_int_value;

	fgl_start("");
	pushint(int_value);
	popint(&ret_int_value);
	if ( int_value != ret_int_value )
	  exit(1);
	exit(0);
}
