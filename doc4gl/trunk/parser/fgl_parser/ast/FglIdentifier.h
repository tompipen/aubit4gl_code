
/**
 * @file
 *
 * A class that defines a 4gl function
 */

#ifndef FGL_IDENTIFIER_H
#define FGL_IDENTIFIER_H

#include <string.h>


class FglIdentifier 
{
private:
	char *name;    //< The denomination of the identifier

public:
	FglIdentifier(const char *_name) { name=strdup(_name); };
  char *getName(void);
};

#endif
