/**
 * @file
 * Lexical analisys suport
 *
 * @author : Sergio Ferreira
 * @version : $Revision: 1.1 $
 */


#include "stdio.h"
#include "p4gl_symtab.h"
#include "y.tab.h"


/**
 * Copy an non reserved word to the union used in yacc.
 *
 * Executed when the lexer does not recognizes a token as a reserved one.
 *
 * @param YYText A pointer to the buffer where the word is stored.
 * @param TokenType The token type:
 *    - IDENTIFIER
 *    - STRING
 *    - NUMBER
 *
 */
void CopyToken(char *YYText,int TokenType)
{

	/* printf("Vai copiar %s\n",YYText); */
  switch(TokenType)
	{
	   case IDENTIFIER:
			strcpy(yylval.y_sym,YYText);
			break;

		/*
	   case FGL_COLOR:
			strcpy(yylval.y_sym,YYText);
			break;
			*/

		case STRING:
			strcpy(yylval.y_string,YYText);
			break;

		case NUMBER:
			yylval.y_num = atoi(YYText);
			break;
	}
}

