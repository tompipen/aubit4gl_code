/**
 * @file
 *
 * The fgl_parser entry point.
 * The fgl parser is a new parsing tool of 4gl programs to be used 
 * inside doc4gl tool.
 * This parser is based on the aubit 4gl parser wich have a good
 * 4gl syntax support.
 * 
 * The parsing is made over a 4gl file and create an Abstract Syntax
 * Tree.
 *
 * It is not goal of this class make any semantic parsing, code 
 * generation or documentation composing.
 *
 * This should be kept as an abstraction to such actions.
 *
 * @todo : Plug of error and log objects.
 * @todo : Put the licence and copywrith here.
 *
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "string.h"
#include "MemFile.h"
#include "KeyWordTextReader.h"
#include "KeyWord.h"
#include "FglParse.h"

/**
 * Constructor with the file name as parameter.
 *
 * @param _fglSourceFile The name of the 4gl file to be parsed.
 */
FglParse::FglParse(const char *_fglSourceFile)
{
  fglSourceFile = strdup(_fglSourceFile);
	parseFgl();
}

/**
 * Open the file name.
 * The FILE structure is assigned to yyin global pointer that then
 * yylex use.
 *
 * @return A pointer to a Lexer object.
 */
FglLexer *FglParse::openFglFile(void)
{
	memFile = new MemFile();
  if ( memFile->fopen(fglSourceFile) == 0 ) {
		printf("Cant open %s\n",fglSourceFile);
	  perror("Opening source");
		return 0;
	}
	fglLexer = new FglLexer();
	// Tell the lexer wich memfile to use
	fglLexer->setMemFile(memFile);
}

/**
 * Function just to test if i receive the function list from the parser
 * 
 * @todo : Remove this from here because it is just for debuging purposes.
 */
void FglParse::printFunctionList()
{
   //FunctionList *functionList = ast->getFunctionList();
	 //functionList->printFunctionList();
}

/**
 * Parse one 4gl file.
 *
 * This is the entry point to the new parser of doc4gl.
 *
 * The result of this parsing is an 4gl object model in a C++ 
 * object that containts a Abstract Syntax.
 *
 * The Abract Syntax Tree is build and generated using treecc.
 *
 * @todo : The old AT should be removed to use just the treecc ast
 *
 */
void FglParse::parseFgl(void)
{
	// @todo : Fix this
  int a4gl_yyparse(void * lexer,NodeState *astState);

	// keywordInit();

	/* Create the node factory and state object */
	NodeState *astState = new NodeState("hello", "another hello");

	/** @todo The error object should be pluged and not instantiated here */
	parserError = new ParserError();

	/** Open the 4gl file and load it to a memory buffer */
  FglLexer *fglLexer = openFglFile();

	/** Plug the error object to the lexer */
	fglLexer->setParserError(parserError);

	/** Calls the bison parser */
  parsingResult = a4gl_yyparse((void *)fglLexer,astState);

	// Show the eventualy ocurred errors.
	parserError->showErrors();
	// @todo this should go to destructor
	delete astState;
}

/**
 * @todo : Just to test dynamic keywords so remove it after being working
 */
void FglParse::keywordInit() 
{
	KeyWordTextReader *kwordReader = new KeyWordTextReader("kwords");
	kwordReader->openFile();
	kwordReader->getKeywordTable();
	kwordReader->closeFile();
}

/**
 * Getter for the result of the 4gl parsing.
 *
 * @todo : The parsing result should be an enumerated.
 *
 * @rerurn The parsing result.
 */
int FglParse::getParsingResult(void) 
{
   return parsingResult;
}

/**
 * Destructor.
 */
FglParse::~FglParse(void) 
{
	delete parserError;
  delete memFile;
  delete fglLexer;
}

/* ==================================== EOF =============================== */
