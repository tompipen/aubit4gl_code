%{
/***************************************************************************
 *
 *   4gl language pre-processor
 *   
 *   It resolves includes for a 4gl source.
 *   Read the input file and include all the files referenced in "GLOBALS"
 *   It writes a file with the expanded code.
 *   The names of the files are passed as parameters
 *
 * Author : Sérgio Ferreira
 *
 ***************************************************************************/

extern int  Functions;          /* Number of Functions Found     */
extern FILE *param_out;
int    lineno=1;

/* Agora passa os comentários ao p4gl
"{"                            { ReadBlockComment(); }
"#"                            {  int ch;
	                               while ((ch=input()) != '\n' && ch != EOF);
				                         lineno++; 
		                            putc('\n',yyout);
								*/

%}

letra                           [a-zA-Z_]
digito                          [0-9]
letra_ou_digito                 [a-zA-Z_0-9]
separator                       [ \t\n]
double_quoted_string            \"([^"\n]|\\["\n])*\"
quoted_string                   \'([^'\n]|\\['\n])*\'
numero                          [0-9]+

%s GLOBALS

%%

"{**"                          { preprocessFglDoc(); }

"{"  { int ch;
		   putc('{',yyout);
	     while ((ch=input()) != '}' && ch != EOF)
			 {
		     putc(ch,yyout);
				 if ( ch == '\n' )
				   lineno++; 
			 }
		   putc('}',yyout);
		 }

"#"  { int ch;
	     while ((ch=input()) != '\n' && ch != EOF);
				 lineno++; 
		   putc('\n',yyout);
		 }

"--" { int ch;
	     while ((ch=input()) != '\n' && ch != EOF);
			  lineno++; 
		   putc('\n',yyout);
		 }
<GLOBALS>{double_quoted_string}    { IncluiFicheiro(yytext); BEGIN INITIAL; }
<GLOBALS>{quoted_string}           { IncluiFicheiro(yytext); BEGIN INITIAL; }
{double_quoted_string}             { ECHO;                                  }
{quoted_string}                    { ECHO;                                  }
"\n"                           { lineno++; ECHO;}



<INITIAL>{letra}{letra_ou_digito}*  { if (IsGlobals())
		     BEGIN GLOBALS;
			 else
			   ECHO;
			 IncrementFunction();
     }

<GLOBALS>{separator}+               { ECHO ;                            }
<GLOBALS>.                        { fprintf(yyout," GLOBALS ");
												  ECHO; BEGIN INITIAL;              }
"."                                 { ECHO; }

%%


/*
 * Verifica se a palavra encontrada eh GLOBALS
 */
IsGlobals()
{
	if (strcasecmp(yytext,"globals")==0)
		return 1;
	return 0;
}


/* 
 * Function counter increment.
 * If there are identifiers with this name, more memory will be allocated
 * and y cant divide by two because of start and finish report ???
 */
IncrementFunction()
{
	if (strcasecmp(yytext,"function") == 0 ||
	    strcasecmp(yytext,"main")     == 0 ||
	    strcasecmp(yytext,"report")   == 0 )
		Functions++;
}

/*
 * Inclui o ficheiro de globals
 * A proxima versao poderia tambem retirar os comentarios
 * TODO - As funções incluidas não são somadas e deveriam ser
 */ 
IncluiFicheiro(NomeFicheiro)
char *NomeFicheiro;
{
   FILE *FicheiroIncluido;
	char  NmFicheiro[64];
	char  str[256];
	char *s;
	int  ch;

	/* Retirar aspas */
	strcpy(NmFicheiro, NomeFicheiro+1);
	NmFicheiro[strlen(NmFicheiro)-1] = '\0';

	fprintf(yyout,"\nINC_GLOBALS \"%s\"\n",NmFicheiro);
   FicheiroIncluido = fopen(NmFicheiro,"r");
	if ( FicheiroIncluido == (FILE *)0)
	{
		printf("p4glpp: Ficheiro incluido nao existente ou sem permissoes (%s)\n",
				 NmFicheiro);
		exit(1);
	}
	while ( !feof(FicheiroIncluido) )
	{
		ch = getc(FicheiroIncluido);
	   if ( ! feof(FicheiroIncluido) )
		   putc(ch,yyout);
	}
	fprintf(yyout,"END INC_GLOBALS");
}

/**
 * Preprocessa os comentários {** que indicam que estes servem para 
 * documentar o módulo ou método seguinte.
 *
 * No caso do pré-processamento escreve-o directamente no ficheiro que depois
 * será tratado pelo parser em si
 */
preprocessFglDoc()
{
	int ch;
	int inComment = 0;

	putc('{',yyout);
	putc('*',yyout);
	putc('*',yyout);
  while ( inComment == 0 )
	{
		ch = input();
		switch ( ch ) 
		{
		  case EOF:
			  return;
		  case '}':
		    putc(ch,yyout);
			  inComment = 1;
				break;
      default:
		   putc(ch,yyout);
			 break;
		}
  }
}


/*
 * Read a block comment from yyin
 * It uses the syntax of 4gl { } and i have a block comment of my own 
 * thath does not coment the block to 4gl. It starts with {IGNORE } and
 * finishes with { IGNORE}
 */
ReadBlockComment()
{ 
	char str[80];
   int  j, ch;

		/* Temporariamente retirada a capacidade de IGNORE ate implementacao com
			input()
		 */

		/* O que esta entre comentarios funciona bem
      while ((ch=input()) != '}' && ch != EOF)
         if ( ch == '\n' )
            lineno++;
		return;
		*/

	// TODO É aqui que se vai deixar o código para fgldoc
	if ( lexgets(str,7) != 0 && strcmp("IGNORE",str) == 0 )
   {
      /* ignorar ate proximo IGNORE */
      while (lexgets (str, 80) != 0) 
      {
         lineno++;
         j = strlen(str);
         if (j > 8 && strstr(&str[j -8], "IGNORE}"))
            break;
         /* Leu IGNORE */
      }
   }
   else
   {
      /* Voltar atras n caracteres */
		/* Tem de ser com unput */
		lexunput(str,strlen(str));
      while (( ch = input() ) != '}' && ch != EOF)
			{
				 /* printf("%c",ch);*/
         if ( ch == '\n' )
            lineno++;
	   }
   }
}

/* 
 * It it suposed to have the some functionality of gets but using 
 * the macros input() and output()
 * ???? Por testar
 */
lexgets(str,NumberOfChr)
char *str;
int NumberOfChr;
{
   register int i,ch;

	for ( i = 0 ; i < NumberOfChr-1 ; i++ )
	{
		ch = input();
      if ( ch == EOF )
		{
	      str[i] = '\0';
			return(0);
		}
		if (ch == '\0' || ch == '\n')
			break;
		str[i] = ch;
	}
	str[i] = '\0';
	return(1);
}

/*
 * It unput(s) the number of characteres passed as parameter
 */
lexunput(str,Num)
char *str;
int   Num;
{
   register int i;

	for ( i = Num-1 ; i >= 0 ; i-- )
		unput(str[i]);
}


