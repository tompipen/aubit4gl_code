
/**
 * @file
 * Declaration of the class that acts as the entry point to a 4gl parsing.
 *
 * @todo Put the licence and copywrights here.
 */

#ifndef FGL_PARSE_H
#define FGL_PARSE_H

#include "ParserError.h"
#include "MemFile.h"
#include "FglAst.h"
#include "FglLexer.h"

class FglParse {
	private:
		char *fglSourceFile;
    MemFile *memFile;
    FglLexer *fglLexer;
		int parsingResult;
		ParserError *parserError;
    FglLexer *openFglFile(void);
    void closeFglFile(void);
		void parseFgl(void);
    void keywordInit();

	public:
    FglParse(const char *_fglSourceFile);
    void printFunctionList(void);
		int getParsingResult();
		~FglParse();
};
#endif

