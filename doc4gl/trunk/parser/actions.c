

#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <varargs.h>
#include "p4gl_symtab.h"

/**
 * De acordo com os parametros enviados executa a(s) acção(ões) 
 * correspondente(s)
 */

executeActions()
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

