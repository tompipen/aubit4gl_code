/**
 * @file
 *
 * The fgl_parser entry point.
 * The fgl parser is a new parsing tool of 4gl programs to be used 
 * inside doc4gl tool.
 * This parser is based on the aubit 4gl parser wich have a good
 * 4gl syntax support.
 *
 * @todo : This code needs to be changed and passed to C++ class.
 *
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "string.h"
#include "a4gl_4glc_int.h"
#include "MemFile.h"
#include "KeyWordTextReader.h"
#include "KeyWord.h"
#include "FglLexer.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/


/* -------- unknown --------- */
/* path to 4gl file we are currently compiling - used when compiling global files */
char errbuff[1024] = "";
char yytext[1024] = "";

#ifdef YYDEBUG
extern int yydebug;		/* defined in y.tab.c _IF_ -DYYDEBUG is set */
#else
int yydebug;			/* if !-DYYDEBUG, we need to define it here */
#endif

#undef DEBUG

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

/* Static variables that we then use to be class variables when it
 * pass to C++
 */
static const char *fglSource;

MemFile *memFile;
FglLexer *fglLexer;

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Open the file name.
 * The FILE structure is assigned to yyin global pointer that then
 * yylex use.
 *
 */
FglLexer *openFglFile()
{
	memFile = new MemFile();
  if ( memFile->fopen(fglSource) == 0 ) {
		printf("Cant open %s\n",fglSource);
	  perror("Opening source");
		return 0;
	}
	fglLexer = new FglLexer();
	// Tell the lexer wich memfile to use
	fglLexer->setMemFile(memFile);
}

/**
 * Close the 4gl source file
 */
void closeFglFile()
{
  //memFile->fclose();
	delete memFile;
	// @todo : Destroy the object
}

/**
 * This is to an acessor when this is C++ object
 *
 * @param _fglSource The name of the file to be opened.
 */
void setFglSource(const char *_fglSource) 
{
  fglSource = _fglSource;
}

/**
 * Parse one 4gl file.
 *
 * This is the entry point to the new parser of doc4gl.
 *
 * The result of this parsing is an 4gl object model in a C++ 
 * object that containts a Abstract Syntax.
 *
 * @param fileName input source file, with path but no extension
 * @return 
 *   0 - The syntax of the 4gl file is correct.
 *   1 - The syntax is incorrect
 */
int parse_4gl (const char *fglFileName)
{
	int x;
	setFglSource(fglFileName);
	// @Just to test 
	/*
	KeyWordTextReader *kwordReader = new KeyWordTextReader("kwords");
	kwordReader->openFile();
	kwordReader->getKeywordTable();
	kwordReader->closeFile();
	*/

  FglLexer *fglLexer = openFglFile();
	// @todo : Implement this function
	//yylex_init();
	// I need to change something to pass the lexer object to the parser.
	// @todo : The yyparse should return a FglModule abstract syntax.
  x = a4gl_yyparse((void *)fglLexer);
	// @todo : Implement this function
	//yylex_destroy();
  closeFglFile();
	return x;
}

/**
 * Treatment of an error ocurred in the parsing.
 *
 * It makes the proper treatment of an syntax error ocurred during the parsing
 * I need a way to return the control to who have called the parser not exiting.
 *
 * @todo : Create a way to register dynamicaly functions to handle the error(s).
 *
 * @param s The string that contains the error
 */
void
a4gl_yyerror (char *s)
{
  char errfile[256];
  FILE *f;
  long ld;
  char a;

	/* @todo : Uncomment because this is needed
  ld = A4GL_memfile_ftell (yyin);
  //sprintf (errfile, "%s.err", outputfile);
  a = 0;


  // Need a real fseek here 
  fseek (yyin, fpos, SEEK_SET);
  f = A4GL_write_errfile (yyin, errfile, ld, yylineno);
  fprintf (f, "| %s%s (%s)", s, errbuff, yytext);
  A4GL_write_cont (yyin);
  printf ("Error compiling %s.4gl - check %s.err\n", outputfile, outputfile);
	*/
  printf ("%s%s (%s)\n", s, errbuff, yytext);
  //return (2);
}

/* ==================================== EOF =============================== */
