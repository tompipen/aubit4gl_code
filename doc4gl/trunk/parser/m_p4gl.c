
/*
 *   p4gl : 4gl source file parser
 *
 *   Autor : Sergio Ferreira
 *   Main e funcoes de execucao de mais alto nivel.
 */

#include "y.tab.h"

extern int exit_stat;

main(argc,argv)
int argc;
char *argv[];
{
	InitP4gl(argc,argv);
	P4glVerbose("4gl Parsing\n");
	if( yyparse()==0)    /* Parse a source .4gl - Nao tem recup. de erros */
	{
	   OrderSymtab();       /* Orderna os arrays da tabela or nome */
	   DumpSymtab();
		 executeActions();
	}
	else
		printf("P4gl Parsing failed\n");
	CleanP4gl();
	exit(exit_stat);
}


/* 
 * Funcao executada quando nao identificou uma palavra como reservada
 */
CopyToken(YYText,TokenType)
char *YYText;
int TokenType;
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

