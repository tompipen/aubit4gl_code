/**
 * @file
 * Test if a poplocator works ok.
 */


#include <stdio.h>
#include "locator.h"
#include "fglsys.h"

/**
 * Get a locator value from the stack, and pop the file name where it is
 * to the stack again.
 * To be used in aubit 4gl tests.
 */
pop_locator(int n_params) {
  loc_t *lob_value;

  poplocator(&lob_value);
	retquote(lob_value->loc_fname);
	return 1;
}
