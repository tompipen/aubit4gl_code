/**
 * @file
 * Error composiong function.
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 */

#include "../libincl/debug.h"
extern char*get_errm(int a);

/**
 * Create a string with an 4gl error.
 * 
 * @param a The error code.
 * @param s Aditional string to compose the error.
 */
char *err_print(int a,char *s) 
{
  char *k;
  static char static_err[256];
  debug("In err print");
  sprintf(static_err,"Unknown error %d (%s)",a,s);
  k=static_err;
  if (a==-3001) {
    debug("Ignore wrong number of variables..");
    strcpy(static_err,"Wrong number of variables returned from function");	
    return k;
  }
  debug("Calling get_errm");
  k=get_errm(a*-1);
  debug("Got %s",k);
  sprintf(static_err,k,s);
  return static_err;
}



