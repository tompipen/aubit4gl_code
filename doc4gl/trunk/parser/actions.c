
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
    if ( repositoryFormat == INSLIB )
	    InsertInslib();
	  else
      insertP4glRep();
  }

	/** Aqui tem de se inserir a chamada ao novo repositório */

  if ( generateFglDoc )
	  genFglDoc();
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
  if ( yyparse() == 0)
	  return 1;
  return 0;
}

