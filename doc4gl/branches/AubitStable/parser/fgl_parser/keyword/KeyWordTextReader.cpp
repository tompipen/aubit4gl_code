/**
 * @file
 * Reads the text file that contains the multi word keywords of 4gl and
 * load(s) it to memory, to be either used by parser or generate a C++ code
 * with a static table in it.
 */

#include <stdio.h>
#include <fstream.h>
#include <string>
#include "KeyWordTable.h"
#include "KeyWordTextReader.h"


using namespace std;

KeyWordTextReader::KeyWordTextReader(const char *_fileName) 
{
	fileName = _fileName;
}

/**
 * @todo : This shoul throw an exception and not exit
 */
void KeyWordTextReader::openFile() 
{ 
	ifstream infile (fileName); 
	if (! infile) { 
	  cerr << "Cannot open file:"; 
		cerr << "data.txt\n"; 
		exit (1);
  }
}

/**
 * Read and build the keyword table
 */
KeyWordTable *KeyWordTextReader::getKeywordTable() 
{
	 string s;
	 printf("Reading keyword table \n");
   while(getline(infile,s))
      cout << s << endl;  
	 printf("Readed\n");
}

void KeyWordTextReader::closeFile(void) 
{
	infile.close();
}

