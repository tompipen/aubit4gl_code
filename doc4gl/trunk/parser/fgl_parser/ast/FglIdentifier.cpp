/**
 * @file
 *
 * A class that defines a 4gl function
 */

#include <stdlib.h>
#include <string.h>
#include "FglAst.h"


/**
 * Getter for the name of the function.
 *
 * @return The name of the function
 */
char *FglIdentifier::getName(void) 
{
  return name;
}

