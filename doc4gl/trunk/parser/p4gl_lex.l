%{
/*  ==========================================================================
 *
 *   Author : Sergio Ferreira
 *   $Date: 2003-12-15 05:17:36 $
 *   $Id: p4gl_lex.l,v 1.7 2003-12-15 05:17:36 afalout Exp $
 *
 *   Lexical analyzer for the p4gl parser
 *
 *  ==========================================================================
 */

#include <string.h>
#include "p4gl_symtab.h"
#include "p4gl.h"
#include "y.tab.h"

//static char *rcsid = "$Id: p4gl_lex.l,v 1.7 2003-12-15 05:17:36 afalout Exp $";

int lineno=1;         /* Source line number counter */


%}

alpha                           [a-zA-Z_]
alnum                           [a-zA-Z_0-9]
separator                       [ \t]+
double_quoted_string            \"([^"\n]|\\["\n])*\"
quoted_string                   \'([^'\n]|\\['\n])*\'

%%
"\n"                        { lineno++; }
"{**"                       { documentationComment(); }
"{"                         { readBlockComment(); }
"#"                         { readLineComment(); }
"--"                        { readLineComment(); }

"\""                        { readString();
                              /* Falta copiar a string */
                              CopyToken(yytext,STRING);
                              return(STRING); }

{quoted_string}             { CopyToken(yytext,STRING); return(STRING);  }
{double_quoted_string}      { CopyToken(yytext,STRING); return(STRING);  }


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
 *
 *  @todo : This function should go to a specific module.
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
 * It it suposed to have the some functionality of gets but using 
 * the macros input() and output() using the encapsulater function 
 * p4glLexInput().
 *
 * This function should be at compiler library
 * The equal function in p4pp_lex.l is better than this one
 * @todo : This function should go to a specific module.
 * @todo - resolver o retorno errado
 *
 * @param str The place where to put the string.
 * @param NumberOfChar 
 */
char *lexgets(char *str,int NumberOfChr)
{
   register int i,ch;

  for ( i = 0 ; i < NumberOfChr-1 ; i++ )
  {
    ch = p4glLexInput();
    if ( ch == EOF )
      return NULL;
    if (ch == '\0' )
      return NULL;
    if (ch == '\n')
      break;
    str[i] = ch;
  }
  str[i] = '\0';
  return "";
}

/**
 * Garante a existência de memória para o tamanho corrente
 * fazendo incrementos do tamanho definido (para não se estar sempre
 * a fazer realloc
 * @todo : This function should change to other module.
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
 * Read one character from the input source file stream.
 *
 * @return The chacter readed.
 */
int p4glLexInput(void)
{
  return input();
}

/*
 * Read a quoted string from yyin
 * @todo : This function should change to other module.
 * @TODO - Tamanho da string não pode ser limitado a 256
 */
readString()
{ 
  char str[256];
  int j=0, ch, lookAheadCh;
  int stringFinished = 0;

  while ( stringFinished == 0)
  {
    ch = p4glLexInput();
    if ( ch == EOF )
      break;
    str[j] = ch; j++;
    switch ( ch )
    {
      case '"':  /* Fazer lookahead para ver se é escape de aspas */
        lookAheadCh = p4glLexInput(); 
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
      case '\\':  // Everything after \ is consumed, even "
        lookAheadCh = p4glLexInput(); 
        str[j] = lookAheadCh; 
                j++;
        break;
      case '\n':
        lineno++; 
        break;
    }
    fflush(stdout);
  }
  str[j] = '\0';
}

/*
 * It unput(s) the number of characteres passed as parameter
 *
 * @todo : This function should change to other module.
 *
 * @param str
 * @param Num
 */
lexunput(str,Num)
char *str;
int   Num;
{
   register int i;

  for ( i = Num-1 ; i >= 0 ; i-- )
    unput(str[i]);
}


