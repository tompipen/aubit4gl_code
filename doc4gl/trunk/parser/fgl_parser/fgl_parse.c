/**
 * @file
 *
 * The fgl_parser entry point.
 * The fgl parser is a new parsing tool of 4gl programs to be used 
 * inside doc4gl tool.
 * This parser is based on the aubit 4gl parser wich have a good
 * 4gl syntax support.
 *
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "string.h"
#include "a4gl_4glc_int.h"
#include "memfile.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/


/* -------- extern --------- */
extern int globals_only;	/* defined in map.c */
extern FILE *yyin;
extern long fpos;					/** current file position for direct fseek */
extern int yylineno;

/* -------- unknown --------- */
/* path to 4gl file we are currently compiling - used when compiling global files */
char currinfile_dirname[1024] = "";	
char errbuff[1024] = "";
char yytext[1024] = "";
int globals_only = 0;
int yyin_len;

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

void set_yytext (char *s);

/* Static variables that we then use to be class variables when it
 * pass to C++
 */
static const char *fglSource;

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
int openFglFile()
{
}

/**
 * Close the 4gl source file
 */
void closeFglFile()
{
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
 */
int parse_4gl (const char *fglFileName)
{
	int x;
	setFglSource(fglFileName);
  openFglFile();
	// @todo : The yyparse should return a FglModule abstract syntax.
  x = a4gl_yyparse ();
  closeFglFile();
}



int old_parse_4gl(const char *fileName) 
{
  int x, ret, flength=0;
  char buff[1028];
  char c[128];			//The 4gl file
  char *ptr;
  static FILE *filep = 0;

	/* --- To function that makes some threatment of the file name ---- */
  /* store the directory part of file name, if any, so we can use it for GLOBALS
     file compilation, if nececery */

  sprintf (c, "%s%s", fileName, ".4gl");
  strcpy (buff, c);
  if (strchr (buff, '/'))
  {
    ptr = strrchr (buff, '/');
    strcpy (ptr, "");		// this does NOT leave a slash at the end
    strcpy (currinfile_dirname, buff);
  }
  else
  {
    strcpy (currinfile_dirname, ".");
  }


#ifdef DEBUG
  A4GL_debug ("Set currinfile_dirname to: %s\n", currinfile_dirname);
  A4GL_debug ("Opening in memory: %s\n", c);
#endif
	/* --- To function ---- */

	/* ----- To function that open a file ----- */
  /*
   * File MUST be opened in binary mode on Windows, to be able to process
   * source file in DOS format - otherwise fpos/ftell gets completely 
	 * dissoriented.
   */
  yyin = A4GL_memfile_fopen (c, "rb");

  if (yyin == 0)
  {
    printf("Error opening file : %s\n", c);
    exit (1);
  }

  A4GL_memfile_fseek (yyin, 0, SEEK_END);
  yyin_len = A4GL_memfile_ftell (yyin);
  A4GL_memfile_rewind (yyin);

  if (yydebug)
  {
    printf ("Opened : %s\n", c);
  }
	/* ----- /To function that open a file ----- */

	/* This is the 4gl parsing. I just need to do this in doc4gl */
  x = a4gl_yyparse ();		/* we core A4GL_dump here on Darwin */
}

/**
 * Treatment of an error ocurred in the parsing.
 *
 * It makes the proper treatment of an syntax error ocurred during the parsing
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
  //printf ("Error compiling %s.4gl - check %s.err\n", outputfile, outputfile);
	*/
  exit (2);
}


/**
 *  Adds the parameters to the error buffer in the assigned with yyerror.
 *
 *  The purpose is to using sprintf with fixed number of parameters.
 *  I Think that this only exists until we start using varargs.
 *
 * @param s The first parameter
 * @param p The second parameter
 * @param q The tird parameter
 */
void
adderr (char *s, char *p, char *q)
{
  sprintf (errbuff, s, p, q);
}


/**
 * Inform if we are just parsing the globals
 *
 * @return
 *   - 1 : if we are just doing globals
 *   - 0 : otherwise
 */
int
only_doing_globals (void)
{
  if (globals_only)
    return 1;
  return 0;
}

/**
 *
 *
 * @param s
 */
void
set_yytext (char *s)
{
  strcpy (yytext, s);
}

/* ==================================== EOF =============================== */
