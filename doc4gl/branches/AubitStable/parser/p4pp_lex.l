%{
/**
 * @file

 *   4gl language pre-processor
 *   
 *   It resolves includes for a 4gl source.
 *   Read the input file and include all the files referenced in "GLOBALS"
 *   It writes a file with the expanded code.
 *   The names of the files are passed as parameters
 *
 * Author : Sérgio Ferreira
 *
 * @todo : Isto come a palavra GLOBALS depois do END GLOBALS
 *
 ***************************************************************************/

extern int  Functions;          /* Number of Functions Found     */
extern FILE *param_out;
int    lineno=1;
static int printed_globals = 0;
static int end = 0;

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



<INITIAL>{letra}{letra_ou_digito}*  { 
	  if (IsGlobals())
		{
		  printed_globals = 0;
		  BEGIN GLOBALS;
		}
		else
		  ECHO;
		IncrementFunction();
  }

<GLOBALS>{letra}{letra_ou_digito}*  {
		if (printed_globals == 0)
		{
	    fprintf(yyout," GLOBALS ");
		  printed_globals = 1;
		}
	  if (isEnd())
		{ 
		  end = 1;
		}
		else
		{
		  if (end == 1 ) 
			{
		      //BEGIN INITIAL;
	        //fprintf(yyout," GLOBALS ");
				//else
	      if ( IsGlobals())
				{
		      BEGIN INITIAL;
			    end = 0;
				}
		  }
		}
	  ECHO;
	}

<GLOBALS>{separator}+               { ECHO ;                            }
<GLOBALS>.                        { 
	  //fprintf(yyout," GLOBALS ");
		ECHO; /*BEGIN INITIAL;              */
	}
"."                                 { ECHO; }

%%


/**
 * Check if the word found is the keyword END.
 */
isEnd()
{
	if (strcasecmp(yytext,"end")==0)
		return 1;
	return 0;
}

/**
 * Check if the word found is the keyword GLOBALS.
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
    {
		Functions++;
    }
}

/*
 * Include GLOBALS file
 * A proxima versao poderia tambem retirar os comentarios
 * TODO - As funções incluidas não são somadas e deveriam ser
 */ 
IncluiFicheiro(NomeFicheiro)
char *NomeFicheiro;
{
FILE *FicheiroIncluido;
char  NmFicheiro[64];
char  str[256];
char  buff[10];
char *s;
int  i;
int buffcnt=0;
char ch; // it was int - why?


	/* Retirar aspas */
	strcpy(NmFicheiro, NomeFicheiro+1);
	NmFicheiro[strlen(NmFicheiro)-1] = '\0';

	fprintf(yyout,"\nINC_GLOBALS \"%s\"\n",NmFicheiro);
	FicheiroIncluido = fopen(NmFicheiro,"r");
	if ( FicheiroIncluido == (FILE *)0)
	{
		//printf("p4glpp: Ficheiro incluido nao existente ou sem permissoes (%s)\n",
        printf("p4glpp: File included via GLOBALS does not exist - check permisions (%s)\n",
				 NmFicheiro);
		exit(1);
	}

    strcpy(buff,"");

	while ( !feof(FicheiroIncluido) )
	{
		ch = getc(FicheiroIncluido);

        //accumulate last 10 characters in the buffer
		if (buffcnt == 10) {
			for ( i = 1 ; i < 11 ; i++ ) {
                buff[i-1]=buff[i];
            }
            buff[10]=ch;
		} else {
            buff[buffcnt]=ch;
            buffcnt++;
        }

		//printf("%d(%s)\n",buffcnt,buff);

		if ( ! feof(FicheiroIncluido) ) {
		   putc(ch,yyout);
        }

		if 	(
			(strcmp("GLOBALS \"",buff) == 0 ) || (strcmp("globals \"",buff) == 0 ) ||
			(strcmp("GLOBALS '",buff) == 0 ) || (strcmp("globals '",buff) == 0 )
			)
		{

            //not going to happen because buff = 10 chars, we compare only 9
            /*
			printf("Found 'GLOBALS filename' statement in included file %s\n",NomeFicheiro);
			printf("TODO: this file needs to be included too!\n");
            */
		}

        //TODO - make it case insensitive
		if ( (strcmp("END GLOBALS",buff) == 0 ) || (strcmp("end globals",buff) == 0 ) ) {
			/* 
			
			This is a very silly way to prevent from including MAIN, functions or report
            blocks via "GLOABALS filename" stmt.

            I tried to do this with if ( ! InInclude ) but failed - got parsing errors. This would be
            the only correct way to do this - EVERYTHING between INC_GLOBALS and END INC_GLOBALS
            must be ignored except GLOBALS ... END GLOBALS block(s) and "GLOBALS filename" statement(s)
            if present (which need to be expaned/included too)


            Problem is that in 4GL language is perfectly valid to use as GLOBALS file a module
            that countains functions; but since we just dump a whole GLOBALS file in temporary
            file to be parsed by p4gl, p4gl will "think" this functions are actual part of the
            module it's parsing - WHICH IS WRONG

            This is silly because:
                1) test for END GLOBALS is not case insensiitve and will fail to
                    detect, for example "End Globals"
                2) There can be more then one GLOBALS ... END GLOBALS block in included file

            4GL language rules state that GLOBALS ... END GLOABALS must be before any
            funtion (MAIN, FUNCTION, REPORT) blocks, so that is OK.

            We also want to ignore any MODULAR variables defined in included file, but this will not
            happen if they are defined before GLOBALS ... END GLOBALS block.

            On top of that, GLOBALS file can include other GLOBALS files itself, and we are not
            handling that at all...

            */

			//FIXME: p4gl (fgldoc actually) "thinks" ther was an error if p4pp prints ANYTHING to stdout...
			//printf("Reached END GLOBALS, exiting...\n");
			break; //exit while
        }

	}

	fprintf(yyout,"\nEND INC_GLOBALS\n");

	fclose (FicheiroIncluido);

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


