
/**
 * @file
 * Parser error handling in a class.
 * The idea is that in the future this will be an interface an each 
 * specific ErrorHandler could be plugged
 *
 */

#ifndef PARSERERROR_H
#define PARSERERROR_H

#include <vector>
#include "MemFile.h"
#include "FglParseError.h"

using std::vector;

class ParserError {
  private:
	   MemFile *memFile;
		 /** A vector of errors founded */
		 vector <FglParseError> errors;
	public:
		 void setMemFile(MemFile *_memFile);
		 void addError(const char *errorMsg);
		 void addError(const char *errorMsg,int line, int column);
		 void showErrors();
		 void genErrFile();
		 ~ParserError();
};

#endif
