/*
#  ============================================================================ 
#
#  Copyright 1996 DESPODATA - Lisboa, PORTUGAL
#                                                        
#  Divisao de desenvolvimento e producao de software.
#  Rua da Prata 166 4.o Dto
#  1100 LISBOA
#                                                        
#  Autor: Sergio Alexandre Ferreira
#                                                        
#  Data de criacao: Sat May 04 10:26:13 LISBOA 1996
#
#	This Module contains Proprietary and Confidential
#	Information of Despodata - Consultores internacionais Lda.
#
#  Programa      : Métodos Utilitários diversos
#  ---------------------------------------------------------------------------
#  DESCRICAO: 
#
#  ---------------------------------------------------------------------------
#  FUNCOES: 
# 
#  ---------------------------------------------------------------------------
#  NOTAS:
#
#  ============================================================================ 
*/

#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <varargs.h>
#include "p4gl_symtab.h"


/****************************************************************************
 *  DESCRICAO : Escreve os erros num ficheiro de erros e no standard error.
 *              Consoante o primeiro argumento sai ou continua.
 *  Argumentos variaveis ( varargs )
 ****************************************************************************/
/*VARARGS0*/
P4glError(va_alist)
va_dcl
{
	int tipoErro;              /* Se a 0 e para fazer exit */
	va_list args;
	char *fmt;
	char  ErroTemporario[256];
	char *NmDir;

	va_start(args);

  NmDir = getcwd((char *)0,256);
	tipoErro = va_arg(args,int); /* 1.o argumento para fazer exit ou nao */

	fmt     = va_arg(args,char *);
	(void)vsprintf(ErroTemporario,fmt,args);
	va_end(args);

	if ( P4glCb.errorToDb == 1 )
    RegisterErrorInDb(ErroTemporario);
	fprintf(stdout,"p4gl: %s, %s",FicheiroInput,ErroTemporario);
	/* ??? Devia meter a data */
	fprintf(Log,"p4gl: Directoria: %s - Ficheiro: %s - %s",
			  NmDir,FicheiroInput,ErroTemporario);

	exit_stat = 1;
	if ( tipoErro == 0 )
	{
      CleanP4gl();
		exit(1);
	}
}


/*
 * Faz o tratamento de avisos quando necessario 
 */
/*VARARGS0*/
P4glWarning(va_alist)
va_dcl
{
	va_list args;
	char *fmt;
	char  ErroTemporario[512];
	int   Level;

	va_start(args);

	Level = va_arg(args,int);
	if ( Level > WarningLevel ) return;

	fmt     = va_arg(args,char *);
	(void)vsprintf(ErroTemporario,fmt,args);
	va_end(args);
	if ( P4glCb.errorToDb == 1 )
    RegisterWarningInDb(ErroTemporario);

	fprintf(stdout,"Warning: %s",ErroTemporario);
	fprintf(P4glCb.fl_erros_ptr,"Warning: %s",ErroTemporario);
}

/*
 * Envia mensagens de verbose quando seleccionado
 */
/*VARARGS0*/
P4glVerbose(va_alist)
va_dcl
{
	va_list args;
	char *fmt;
	char  ErroTemporario[128];

	if (!verbose)
		return;
	va_start(args);

	fmt     = va_arg(args,char *);
	(void)vsprintf(ErroTemporario,fmt,args);
	va_end(args);

	fprintf(stdout,"%s",ErroTemporario);
}

/*VARARGS0*/
/* 
 * Funcao que mostra mensagem de debug caso este estaja ligado.
 * Devia poder trabalhar por nivel de debug.
 */
P4glDebug(va_alist)
va_dcl
{
	va_list args;
	char *fmt;
	char  ErroTemporario[128];

   if (dbug == 0 )
		return;

	va_start(args);

	fmt     = va_arg(args,char *);
	(void)vsprintf(ErroTemporario,fmt,args);
	va_end(args);

	printf("DEBUG: %s",ErroTemporario);
	fflush(stdout);
}


/*
 * Remove espacos no fim da string
 */
RClipp(str)
char *str;
{
   register int i;
	int len;

	len = strlen(str);
	for (i=len-1 ; i >= 0 ;i--)
		if ( str[i] != ' ' )
			break;
	str[i+1]='\0';
}


Upshift(str)
char *str;
{
   register int i;

	for (i=0 ; str[i] != '\0' ; i++)
		str[i] = toupper(str[i]);
}

/**
 * Faz downshift de todos os caracteres da string enviada como parametro
 */
Downshift(str)
char *str;
{
  register int i;

	for (i=0 ; str[i] != '\0' ; i++)
		str[i] = tolower(str[i]);
}
   
   

copystr(StrDest,StrOrig)
char *StrDest, *StrOrig;
{
   if (StrOrig == (char*)0 )
		StrDest = (char *)0;
	else
		strcpy(StrDest,StrOrig);
}

/*
 * Tira as aspas que estao no principio e fim da string recebida
 * como argumento
 * <A NAME=tiraAspas>TiraAspas</A>
 */

tiraAspas(str)
char *str;
{
  str[0] = ' ';
  str[strlen(str)-1] = '\0';
}


/*VARARGS0*/
/*
 *  Aloca espaco para a string de destino e faz vsprintf para o destino
 *  Quem chama esta funcao tem de se preocupar com os free()(s)
 *  TODO - Testar se memória acabou
 */
char *CpStr(va_alist)
va_dcl
{
	va_list args;
	char *fmt;
	char *destinoTemporario;
	char *RetStr;
	int size = 2048;
	int n;


	destinoTemporario = (char *)malloc(size);
	while (1)
  {
	  va_start(args);
	  fmt = va_arg(args,char *);
	  n = vsnprintf(destinoTemporario,size,fmt,args);
	  va_end(args);

		if ( n > -1 && n < size )
      break;

		if ( n > -1 )
      size = n + 1;
		else
      size *= 2;
		destinoTemporario = (char *)realloc(destinoTemporario,size);
  }

	RetStr = (char *)strdup(destinoTemporario);
	return(RetStr);
}


/* 
 * Devolve o BaseName da variavel (primeiro nome antes de encontrar um ponto)
 */
BaseName(str)
char *str;
{
   register int i;

	for ( i = 0 ; str[i] != '\0' ;i++)
		if ( str[i] == '.' || str[i] == '[' )
			break;

   str[i] = '\0';
}

/**
 * Devolve o nome do ficheiro enviado como parametro sem a respectiva extensão
 */
char *fileWithoutExtension(str)
char *str;
{ 
  register int i;
	char *retStr;

	for ( i = strlen(str) ; i > 0 && str[i] != '.' ; i-- );
	retStr = (char *)malloc(i+1);
	strncpy(retStr,str,i);
	retStr[i] = '\0';
	return retStr;
}

/*
 * Returns the substring of str, starting in start a finishing in finish
 */
char *substr(str, start, finish)
char *str; short start; short finish;
{
   register sh;
	char *retstr;

	if ( start > finish)
		return (char *)0;
	retstr = (char *)malloc(finish-start+2);

	strncpy(retstr,str+start,finish-start+1);
	return retstr;
}


/*
 * Verifica se uma string esta vazia (se nao tem nada, espacos ou tab(s)
 */

IsEmpty(Str)
char *Str;
{
   register int i, len;

	len = strlen(Str);
	for ( i = 0 ; i <= len; i++)
	{
		if ( Str[i] != ' ' && Str[i] != '\t' )
			if ( Str[i] == '\0' )
				return(1);
			else
				return(0);
	}
	return(1);
}
