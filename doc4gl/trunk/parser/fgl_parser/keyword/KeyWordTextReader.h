
/**
 * @file 
 * A keyword text file reader and insertion in a Reserved word table.
 * The idea is to have a C++ code that can read the reserved word format 
 * to memory in order to use it directly from memory or generate a C++
 * initialization to be linked with the parser.
 */

#include <fstream.h>
#include "KeyWordTable.h"

#ifndef KEYWORDTEXTREADER_H
#define KEYWORDTEXTREADER_H

class KeyWordTextReader {
  private:
		const char *fileName;
		ifstream infile;
	public:
		void openFile();
		void closeFile();
		KeyWordTextReader(const char *fileName);
		KeyWordTable *getKeywordTable(void);
};

#endif
