
/**
 * @file
 *
 * A class that defines a 4gl function
 */

#ifndef FGL_FUNCTION_H
#define FGL_FUNCTION_H

#include <string.h>
#include "FglAst.h"


class FglFunction 
{
private:
	FglIdentifier *name;    //< The name of the 4gl function.
	int startLine; //< The source line where the function is started.

public:
	void setName(FglIdentifier *name);
	FglFunction(FglIdentifier *_name) { name=_name; };
	FglFunction() {};
  //~FglFunction ();
  FglIdentifier *getName(void);
};

#endif
