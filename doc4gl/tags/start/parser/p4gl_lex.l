%{
/*  ==========================================================================
 *
 *   Author       : Sergio Ferreira
 *
 *   Lexical analyzer for the p4gl parser
 *
 *  ==========================================================================
 */

#include <string.h>
#include "p4gl_symtab.h"
#include "p4gl.h"

/* ??? Para retirar - O metodo de debug tem de mudar */
#include "m_p4gl.c"   /* O main fica aqui por causa dos defines para debug */

int lineno=1;         /* Source line number counter */

void readDocComment(void);

%}

alpha                           [a-zA-Z_]
alnum                           [a-zA-Z_0-9]
separator                       [ \t]+
double_quoted_string            \"([^"\n]|\\["\n])*\"
quoted_string                   \'([^'\n]|\\['\n])*\'

%%
"\n"                        { lineno++; }
"{**"                       { readDocComment(); }
"{"                         { readBlockComment(); }
"#"                         { readLineComment(); }
"--"                        { readLineComment(); }

"\""                        { readString();
															/* Falta copiar a string */
                              CopyToken(yytext,STRING); 
															return(STRING); }
{quoted_string}             { CopyToken(yytext,STRING); return(STRING); }

[0-9]+                      { CopyToken(yytext,NUMBER); return(NUMBER); }

"=="                        { return('='); }
"<>"                        { return(NOT_EQUAL); }
"!="                        { return(NOT_EQUAL); }
"<="                        { return(LESS_OR_EQUAL);}
">="                        { return(GREATER_OR_EQUAL);}
"**"                        { return(EXPO); }

{alpha}{alnum}*             { return(GetReserved(yytext));}
{separator}                 ;

.                           { return(yytext[0]); }

%%

/* 
 * Found End Of File
 */
yywrap()
{
  return(1);
}

/**
 * Concatena a uma string outra alocando espaço para tal
 *   @param strAppended String a ser aumentada
 *   @param strToAppend String a concatenar
 */
char *appendStr(char *strAppended,char *strToAppend)
{
  int originalLen;
	int toAppendLen;
	int neededLen;
	char *retStr;

	if ( strAppended == (char *)0 )
	  originalLen = 0;
  else
	  originalLen = strlen(strAppended);

	toAppendLen = strlen(strToAppend);
	/*printf("Original len %d ; to append %d\n",originalLen,toAppendLen);*/
	neededLen = originalLen + toAppendLen;
	if ( strAppended == (char *)0 )
	{
		/*printf("MALLOC\n");*/
	  retStr = malloc(neededLen);
	}
  else
	{
		/*printf("REALLOC %s\n",strAppended);*/
    retStr = realloc(strAppended,neededLen);
	}
	strcat(retStr,strToAppend);
	/*printf("Alocar %d bytes \n",neededLen);*/
	return retStr;
}



/**
 * Lê os comentários de linha guardando-as numa string no caso de se 
 * usar os comentários standard como comentários de documentação
 */
readLineComment()
{
  int ch;
	char lcStr[256];
	register int i=0;

    while ((ch=input()) != '\n' && ch != EOF);
      lineno++; 
		return;

	if ( standardComments == 0 || InLimbo == 0)
	{
    while ((ch=input()) != '\n' && ch != EOF);
      lineno++; 
  }
	else
	{
		int commentTerminated = 0;
		/*
	  lcStr = malloc(256);
		*/
		if ( i >= 255 )
		  fprintf(stderr,"ERRO COMENTÁRIO DE LINHA > 256");
    while (commentTerminated == 0)
		{
		  ch = input();
			switch ( ch )
			{
			  case '\n':
					commentTerminated = 1;
          lineno++; 
					break;
				case EOF:
					commentTerminated = 1;
					break;
			  default:
			    lcStr[i] = ch;
			    i++;
					break;
			}
		}
		/* TODO - Inserir num buffer de linhas */
		P4glCb.currFglDoc->buffer = appendStr(P4glCb.currFglDoc->buffer,lcStr);
		printf("&&&&&&&&&&&&&&&&&&&&&&&&& Estragar currFgldoc\n");
		/*free(lcStr);*/
	}
}

/** 
 * It it suposed to have the some functionality of gets but using 
 * the macros input() and output()
 *
 * This function should be at compiler library
 * The equal function in p4pp_lex.l is better than this one
 * @todo - resolver o retorno errado
 */
char *lexgets(str,NumberOfChr)
char *str;
int NumberOfChr;
{
   register int i,ch;

	for ( i = 0 ; i < NumberOfChr-1 ; i++ )
	{
		ch = input();
      if ( ch == EOF )
			  return NULL;
		if (ch == '\0' || ch == '\n')
			  return NULL;
		str[i] = ch;
	}
	str[i] = '\0';
	return "";
}

/**
 * Garante a existência de memória para o tamanho corrente
 * fazendo incrementos do tamanho definido (para não se estar sempre
 * a fazer realloc
 */
char *ensureCapacity(char *str,int incrementSize,int neededSize)
{
	char *retStr;
	int multFactor;

	multFactor = neededSize / incrementSize;
	if ( multFactor <= 0 )
	  multFactor = 1;
  if ( neededSize % incrementSize != 0 )
	  multFactor++;
	retStr = (char *)realloc(str,incrementSize*multFactor);
	return retStr;
}


/**
 * Lê os comentários {** que indicam que estes servem para 
 * documentar o módulo ou método seguinte.
 *
 */
void readDocComment(void)
{
	int ch;
	int inComment = 0;
	StringBuffer *docComment;

	/* ??? TOD Isto tem de ser mudado para usar realoc(s).
	 * O espaço alocado pode ser demais ou de menos. Deve ser optimizado
	 * @todo Se forem lidos dois comentários sem passar por função não há free
	 */
	docComment = (StringBuffer *) constructStringBuffer();
	initStringBuffer(docComment);
  while ( inComment == 0 )
	{
		ch = input();
		switch ( ch ) 
		{
		  case EOF:
			  inComment = 1;
		  case '}':
			  inComment = 1;
			  break;
			case '\n':
				appendCharStringBuffer(docComment,ch);
				lineno++;
			  break;
      default:
				appendCharStringBuffer(docComment,ch);
			  break;
		}
  }

	if ( P4glCb.idx_funcoes == 0 && P4glCb.numFglDoc > 0 )
	{
	  P4glCb.fglDoc        = (char *)strdup(P4glCb.currFglDoc->buffer);
	  P4glCb.currFglDoc    = docComment;
		P4glCb.parsedComment = parseComment(P4glCb.fglDoc);
	}
	else
	  P4glCb.currFglDoc = docComment;

	P4glCb.numFglDoc++;
	//printf("Curr Fgl doc  %s\n===\n", P4glCb.currFglDoc->buffer);
}

/*
 * Read a block comment from yyin
 * It uses the syntax of 4gl { } and i have a block comment of my own 
 * thath does not coment the block to 4gl. It starts with {IGNORE } and
 * finishes with { IGNORE}
 *
 * TODO - Leitura de comentário de bloco
 */
readBlockComment()
{ 
  char str[80];
  int  j, ch = 1;


	if ( lexgets(str,7) != NULL && strcmp("IGNORE",str) == 0 )
  {
    /* ignorar ate proximo IGNORE */
		/* printf("IGNORE : \n"); */
    while (lexgets (str, 80) != NULL) 
    {
      lineno++;
      j = strlen(str);
			/*printf(str); */
      if (j > 8 && strstr(&str[j -8], "IGNORE}"))
        break;
      /* Leu IGNORE */
    }
  }
  else
  {
    /* Voltar atras n caracteres */
		lexunput(str,strlen(str));

		/* Ignorar comentário */
	  if ( standardComments == 0 || InLimbo == 0)
		{
      while (ch != EOF)
			{
        ch = input();
				if ( ch == '}' || ch == EOF)
				  break;
        if ( ch == '\n' )
          lineno++;
	    }
		  return;
		}

		/* Ler comentário para documentação */
		{
	  /* TODO - Tornar isto mais dinâmico */
	  char *comment = (char *)malloc(512);
		char *oldComment;
    register int i=0;
		int commentTerminated = 0;
    while (commentTerminated == 0)
		{
			ch = input();
			oldComment = comment;
			comment = (char *)ensureCapacity(oldComment,512,i);
			switch ( ch )
			{
			  case '\n':
					comment[i] = ch;
					i++;
          lineno++;
					break;
			  case '}':
					commentTerminated = 1;
				  break;
			  case EOF:
					commentTerminated = 1;
				  break;
			  case 0:
					comment[i] = 32;
					i++;
					break;
			  default:
					comment[i] = ch;
					i++;
					break;
		  }
	  }
		  comment[i] = '\0';
		  P4glCb.currFglDoc->buffer = (char *)appendStr(
		    P4glCb.currFglDoc->buffer,comment
		  );
		}
  }
}

/*
 * Read a quoted string from yyin
 * TODO - Tamanho da string não pode ser limitado
 */
readString()
{ 
  char str[256];
  int j=0, ch, lookAheadCh;
	int stringFinished = 0;

	while ( stringFinished == 0)
	{
	  ch = input();
    if ( ch == EOF )
			break;
		str[j] = ch; j++;
	  switch ( ch )
		{
		  case '"':  /* Fazer lookahead para ver se é escape de aspas */
				lookAheadCh = input(); 
				if ( lookAheadCh != '"' )
				{
		      unput(lookAheadCh);
	        stringFinished = 1;
				}
				else
				{
		      str[j] = lookAheadCh; 
					j++;
				}
			  break;
			case '\\':
				lookAheadCh = input(); 
				if ( lookAheadCh != '"' )
		      unput(lookAheadCh);
				else
				{
		      str[j] = lookAheadCh; 
					j++;
				}
			  break;
			case '\n':
        lineno++; 
				break;
		}
  }
	str[j] = '\0';
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


