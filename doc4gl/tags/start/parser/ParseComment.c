
#include <stdio.h>
#include "Comment.h"
#include "StringBuffer.h"

/**
 *
 * Efectua o parsing dos coment�rios para retirar as tags iniciadas por @
 * De notar que o parsing � efectuado sobre uma string e n�o sobre um ficheiro
 *
 * Foi construido com um prfixo diferente por forma a que possa ser linkado 
 * com o parser do 4gl.
 *
 * $Author: afalout $
 * $Revision: 1.1.1.1 $
 * $Id: ParseComment.c,v 1.1.1.1 2001-12-26 07:31:31 afalout Exp $
 *
 */

char *currentChar;
int commentLineStarted = 0;

/* Defini��es para m�quina de estados */
#define IN_COMMENT   0 
#define TAG_COMMENT  1
#define TAG_CODE     2
int commentState = IN_COMMENT;

/* Defini��o da tag corrente */
#define NO_TAG         -1
#define TAG_PROCESS    0
#define TAG_PARAMETER  1
#define TAG_RETURN     2
#define TAG_TODO       3
#define TAG_AUTHOR     4
#define TAG_REVISION   5
int currentTag = NO_TAG;

Comment *currentComment;

/**
 * Inicializa a memoria para um coment�rio
 *
 * @param comm Pointer onde a mem�ria deve ser iniciada
 * @param bufferSize Tamanho pretendido para o buffer com o texto
 */
static void initComment(Comment *comm,int bufferSize)
{
  comm->processIdx = 0;
	comm->buffer = (char *)malloc(bufferSize * sizeof(char));
	*comm->buffer = '\0';
	comm->processIdx        = 0;
	comm->waitingForProcess = 0;
	comm->parameterList = (Parameters *)initParameters(10);
	comm->returnIdx         = -1;
	comm->todoIdx           = -1;
}


/**
 * Faz o parsing de um coment�rio fgldoc
 *
 * @param commentToParse Coment�rio a analisar
 */
Comment *parseComment(char *commentToParse)
{
  register int i;

	commentState = IN_COMMENT;

	commentLineStarted = 0;
  currentComment = (Comment *)malloc(sizeof(Comment));
	initComment(currentComment,strlen(commentToParse));
  currentChar = commentToParse;
  yyCommentlex();

	/* DEBUG */
	/*
	printf("==== COMENT�RIO ====\n");
	printf("TEXTO: %s\n",currentComment->buffer);
	printf("&&&&& PROCESSES:\n");
	for ( i = 0 ; i < currentComment->processIdx ; i++ )
	{
    printf("   * %s\n",currentComment->processCode[i]);
	}
	printf("=================\n\n");
	*/
	return currentComment;
}

/**
 * Marca o inicio de uma nova linha de coment�rio
 */
static void startCommentLine(void)
{
	commentLineStarted = 1;
}


/**
 * Devolve o pr�ximo caracter da string de coment�rio ou EOF se null
 * Executado pelo parser gerado pelo lex
 */
int getCommentChar(void)
{
  int retval;
  /*printf("getting char\n"); */
	if ( *currentChar == '\0' )
    retval = EOF;
  else 
		retval =  *currentChar;
  currentChar++;
  /*printf("Returning %c\n",retval); */
	return retval;
}

/**
 *  Afecta os coment�rios relativos a um return
 *
 *  @param comments Coment�rios a adicionar
 */
static void setReturnComments(char *comments)
{
  if ( currentComment->returnStarted == 1 )
  {
    currentComment->returnList[currentComment->returnIdx]= (char *)malloc(260);
    strcpy(currentComment->returnList[currentComment->returnIdx],comments);
  }
	else
    strcat(currentComment->returnList[currentComment->returnIdx],comments);
  currentComment->returnStarted = 0;
}

/**
 *  Afecta o n� de revis�o
 *
 *  @param revision N� de revis�o
 */
static void setRevision(char *revision)
{
  currentComment->revision = (char *)strdup(revision);
}

/**
 *  Afecta o autor
 *
 *  @param author Descri��o do autor
 */
static void setAuthor(char *author)
{
  currentComment->author = (char *)strdup(author);
}


/**
 *  Afecta os coment�rios relativos a um todo
 *
 *  @param comments Coment�rios a adicionar
 */
static void setTodoComments(char *comments)
{
  if ( currentComment->todoStarted == 1 )
  {
    currentComment->todoList[currentComment->todoIdx]= (char *)malloc(260) ;
    strcpy(currentComment->todoList[currentComment->todoIdx],comments);
  }
	else
    strcat(currentComment->todoList[currentComment->todoIdx],comments);
  currentComment->todoStarted = 0;
}


/**
 * Foi descoberto um coment�rio de tag que deve ser escrito associado a tag 
 * corrente
 *
 * @param tagCode C�digo associado � tag corrente
 * @todo Colocar a inseer��o no buffer correspondente
 */
static void writeTagComment(char *tagComment)
{
  switch (currentTag)
	{
		case TAG_PROCESS:
		  break;
		case TAG_PARAMETER:
			setParameterComments(currentComment->parameterList,tagComment);
		  break;
		case TAG_RETURN:
			setReturnComments(tagComment);
		  break;
		case TAG_TODO:
			setTodoComments(tagComment);
		  break;
		case TAG_AUTHOR:
			setAuthor(tagComment);
		  break;
		case TAG_REVISION:
			setRevision(tagComment);
		  break;
	}
}

/**
 *  Afecta o c�digo do processo corrente
 *
 *  @param id C�digo identificador do processo
 */
static void setProcessCode(char *id)
{
  currentComment->processCode[currentComment->processIdx] = (char *)strdup(id);
	currentComment->processIdx++;
	currentComment->waitingForProcess = 0;
}


/**
 * Foi descoberto um c�digo de tag que deve ser escrito associado a tag corrente
 *
 * @param tagCode C�digo associado � tag corrente
 */
static void writeTagCode(char *tagCode)
{
  switch (currentTag)
	{
		case TAG_PROCESS:
			setProcessCode(tagCode);
		  break;
		case TAG_PARAMETER:
			setParameterName(currentComment->parameterList,tagCode);
		  break;
	}
	commentState = TAG_COMMENT;
}

/**
 *  Escreve no texto do coment�rio um identificador descoberto caso este 
 *  n�o esteja no contexto de ser a defini��o de um processo
 *
 *  @param id String que contem o referido identificador (palavra)
 */
void writeCommentIdentifier(char *id)
{
	commentLineStarted = 0;
  switch (commentState)
	{
		case IN_COMMENT:
      strcat(currentComment->buffer,id);
		  break;
		case TAG_COMMENT:
			writeTagComment(id);
		  break;
		case TAG_CODE:
			writeTagCode(id);
		  break;
	}
}

/**
 * Foi descoberta a tag @process. Muda para o estado correspondente
 */
void startProcess(void)
{
  currentComment->waitingForProcess = 1;
	commentState = TAG_CODE;
	currentTag   = TAG_PROCESS;
}

/**
 * Foi descoberta uma tag parameter
 */
void startParameter(void)
{
	commentState = TAG_CODE;
	currentTag   = TAG_PARAMETER;
}

void startReturn(void)
{
	commentState = TAG_COMMENT;
	currentTag   = TAG_RETURN;
  currentComment->returnStarted = 1;
	currentComment->returnIdx++;
}

void startTodo(void)
{
	commentState = TAG_COMMENT;
	currentTag   = TAG_TODO;
  currentComment->todoStarted = 1;
	currentComment->todoIdx++;
}

void startAuthor(void)
{
	commentState = TAG_COMMENT;
	currentTag   = TAG_AUTHOR;
}

void startRevision(void)
{
	commentState = TAG_COMMENT;
	currentTag   = TAG_REVISION;
}


/**
 * Nova linha iniciada. 
 * Marca na flag correspoondente e consoante o contexto chama a fun��o
 * para escrita no buffer
 */
void writeNewLine(void)
{
  commentLineStarted = 1;
}

/**
 *  Escreve no texto do coment�rio uma string que foi descoberta
 *
 *  @param comm : String com coment�rio
 */
void writeOtherComment(char *comm)
{
	if ( strcmp(comm,"*") == 0 && commentLineStarted == 1)
    return;
	commentLineStarted = 0;

  switch (commentState)
	{
		case IN_COMMENT:
      strcat(currentComment->buffer,comm);
		  break;
		case TAG_COMMENT:
			writeTagComment(comm);
		  break;
		case TAG_CODE:
		  break;
	}
}

/**
 * Foi descoberto um separador no coment�rio
 *
 * @param comm
 */
void writeSeparator(char *comm)
{
  switch (commentState)
	{
		case IN_COMMENT:
      strcat(currentComment->buffer,comm);
		  break;
		case TAG_COMMENT:
			writeTagComment(comm);
		  break;
		case TAG_CODE:
		  break;
	}
}



