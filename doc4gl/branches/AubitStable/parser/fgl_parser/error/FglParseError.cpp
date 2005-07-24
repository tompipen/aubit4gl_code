
#include <stdlib.h>
#include <string.h>
#include "FglParseError.h"

FglParseError::FglParseError(const char *_msg)
{
  msg = strdup(_msg);
	line = 0;
	column = 0;
}

FglParseError::FglParseError(const char *_msg,int _line,int _column)
{
  msg = strdup(_msg);
	line = _line;
	column = _column;
}

int FglParseError::getLine()
{
	return line;
}

int FglParseError::getColumn()
{
	return column;
}

const char *FglParseError::getMsg()
{
	return msg;
}

FglParseError::~FglParseError()
{
	// @todo : Possible memory leak.
	//free(msg);
}
