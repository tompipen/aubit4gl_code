
/**
 * @file
 * Execute the actions defined as parameters.
 *
 * All the phases of the compilation / parsing / documentation process entry
 * points are here.
 */

#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <varargs.h>
#include "p4gl_symtab.h"
#include "p4gl.h"

/**
 * Execute the actions defined as parameters.
 *
 * This function is executed after the parsing terminated and the abstract
 * tree reordering.
 *
 * Uses the parameters as stored in global variables InsertInDatabase and
 * repositoryFormat
 */
void executeActions(void)
{
  if ( InsertInDatabase )
  {
    if ( repositoryFormat == INSLIB ) {
	    InsertInslib();
    } else {
      insertP4glRep();
    }
  }

  //P4glDebug("after Done inserting\n");

  if ( generateFglDoc ){
	  //P4glDebug("Calling genFglDoc()\n");
	  genFglDoc();
  }
}

/**
 * Do the real parsing of the 4gl source file that loads the abstract tree.
 * Calls the yacc parser.
 *
 * @return 
 *   0 : The parsing have an error
 *   1 : Parsing ok
 */
int parseFgl(void)
{
	if ( usedParser == FGLDOC_PARSER )
	  return fgldocParser();
	else
	  return aubitParser();
}

/**
 * Parse the 4gl using the parser builded specificaly for this.
 * @todo : The preprocessing and file opening must be done here 
 * @return The result of the parsing process.
 */
int fgldocParser(void) 
{
  if ( fgldocParserPrepare() == 0)
	  return 1;
	openParamFile();
  if ( yyparse() == 0)
	  return 1;
  return 0;
}

/**
 * Parse the 4gl using a version of the aubit 4gl modified parser.
 * @return The result of the parsing process
 */
int aubitParser(void) 
{
#ifdef WITH_AUBIT_PARSER
	if ( parse_4gl("test/fgl/simple/hello.4gl") )
	  return 1;
#else
	printf("Not compiled with aubit4gl parser\n");
	return 1;
#endif
  return 0;
}


/* ======================================= EOF ===================================== */

