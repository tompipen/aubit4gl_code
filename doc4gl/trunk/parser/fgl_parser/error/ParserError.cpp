/**
 * @file
 * Implementation of error handling class.
 * This is used to log or display the errors founded on a 4gl source to the
 * user.
 */

#include "MemFile.h"
#include "FglParseError.h"
#include "ParserError.h"

void ParserError::setMemFile(MemFile *_memFile)
{
  memFile = _memFile;
}

/**
 * Add a new error to the error vector
 *
 * @param errorMsg The message about the error that was ocurred.
 */
void ParserError::addError(const char *errorMsg)
{
  FglParseError error(errorMsg);
  errors.push_back(error);
}


/**
 * Add a new error to the vector with line and column where
 * was ocurred.
 *
 * @param errorMsg The message with the error that was ocurred.
 * @param line The source file line where it ocurred.
 * @param column The source file column where it ocurred.
 */
void ParserError::addError(const char *errorMsg,int line,int column)
{
  FglParseError error(errorMsg,line,column);
  errors.push_back(error);
}

/**
 * Show all errors to the standard output.
 */
void ParserError::showErrors(void)
{
  std::vector<FglParseError>::iterator it;
  for (it = errors.begin(); it != errors.end(); ++it)
  {
    FglParseError *error = it;
    cout << error->getMsg() << 
      " : [" << error->getLine() << "," << error->getColumn() << "]"
			<< endl;
  }
}

/**
 * Generate the error file with the syntax error assinalated in the 
 * corresponding position
 */
void ParserError::genErrFile(void)
{
}

/**
 * This should remove all information in the vector
 */
ParserError::~ParserError()
{
}
