
// @todo : Remove this after cleaning more
#include "KeyWord.h"
#include <ctype.h>


KeyWord::KeyWord(int _id, int _mode, char *vals)
{
  id = _id;
  mode = _mode;
	vals = strdup(vals);
}

int KeyWord::getId() 
{
  return id;
}

int KeyWord::getMode() 
{
  return Mode;
}

int KeyWord::getVals() 
{
  return vals;
}

KeyWord::~KeyWord()
{
	free(vals);
}

