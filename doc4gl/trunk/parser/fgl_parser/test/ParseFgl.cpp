
#include "FglParse.h"
/**
 * Test utility that receive the name of the file as first parameter
 */
main(int argc, char *argv[]) 
{
  FglParse *fglParse = new FglParse(argv[1]);
	delete fglParse;
}
