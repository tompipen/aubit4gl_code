/**
 * @file
 *
 * A class that defines a 4gl function
 */

#include <stdlib.h>
#include <string.h>
#include "FglAst.h"


/**
 * A setter function to assign the name of the function.
 *
 * @param _name The name of the function
 */
void FglFunction::setName(FglIdentifier *_name)
{
  //name = strdup(_name);
}

/**
 * Getter for the name of the function.
 *
 * @return The name of the function
 */
FglIdentifier *FglFunction::getName(void) 
{
  return name;
}

/**
 * Destroy all information stored in an FglFunction object
 */
/**
FglFunction::~FglFunction () 
{
	//destroy name;
  //free(name);
}
*/
