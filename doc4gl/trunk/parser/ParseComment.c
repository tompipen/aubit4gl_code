/**
 * @file
 * Parse a comment to take the tags that begins with @.
 *
 * This parsing is made over a string and not a file because works with
 * the comnment getted by the 4gl lexer.
 *
 * To be linked with the 4gl parser (wich is also built in lex/flex) is
 * generated with a diferente prefix (done in the makefile).
 *
 * The parsing itself is made with a specific state machine.
 *
 * @todo : Make some syntax for table actions
 * @todo : Change the logic of the file level comments algorithm
 *
 * $Author: saferreira $
 * $Revision: 1.6 $
 * $Id: ParseComment.c,v 1.6 2003-05-14 09:51:40 saferreira Exp $
 *
 */

#include <stdio.h>
#include <string.h>
#include "TableUsage.h"
#include "Comment.h"
#include "StringBuffer.h"

static char *currentChar;
static int commentLineStarted = 0;

/* Definições para máquina de estados */
#define IN_COMMENT   0 
#define TAG_COMMENT  1
#define TAG_CODE     2

/** Current comment state */
static int commentState = IN_COMMENT;

/* Definição da tag corrente */
/** @todo : This should be an enumeradted */
#define NO_TAG         -1
#define TAG_PROCESS    0
#define TAG_PARAMETER  1
#define TAG_RETURN     2
#define TAG_TODO       3
#define TAG_AUTHOR     4
#define TAG_REVISION   5
#define TAG_TABLE      6
#define TAG_SEE        7
#define TAG_SINCE      8

/** Last tag readed by the parser */
static int currentTag = NO_TAG;

/** Current comment information */
static Comment *currentComment;

/**
 * Initialize the memory to a comment.
 *
 * The allocation of the buffer to the text is made here. 
 * If you want to use a Comment you should pass it throu this function.
 *
 * @todo : This function should go to Comment.c
 *
 * @param comm Pointer to a Comment structure to be initialized.
 * @param bufferSize The maximum size of the text buffer.
 */
static void initComment(Comment *comm,int bufferSize)
{
  comm->processIdx        = 0;
  comm->file              = 0;
	comm->buffer            = (char *)malloc(bufferSize * sizeof(char));
	*comm->buffer           = '\0';
	comm->processIdx        = 0;
	comm->waitingForProcess = 0;
	comm->parameterList     = (Parameters *)initParameters(10);
	comm->returnIdx         = -1;
	comm->todoIdx           = -1;
  comm->deprecated        = 0;
  comm->tableList         = (TableUsage **)calloc(10,sizeof(TableUsage *));
  comm->tableIdx          = -1;
  comm->tableStarted      = 0;
  comm->author = (char *)calloc(80,1);
  comm->revision = (char *)calloc(80,1);
  comm->since = (char *)calloc(80,1);
  comm->see = (char *)calloc(80,1);
}


/**
 * Make the parsing of a fgldoc comments loaded in a string.
 *
 * Alocates the space for a Comment structure that is filled with the
 * information.
 *
 * @param commentToParse Text with the comment to parse.
 * @return The comment information.
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
  return currentComment;
}

/**
 * Marca o inicio de uma nova linha de comentário
 */
static void startCommentLine(void)
{
  commentLineStarted = 1;
}


/**
 * Devolve o próximo caracter da string de comentário ou EOF se null
 * Executado pelo parser gerado pelo lex.
 *
 * @return The next character in the comment. EOF if it reaches the end
 */
int getCommentChar(void)
{
  int retval;
  if ( *currentChar == '\0' )
    retval = EOF;
  else 
    retval = *currentChar;
  currentChar++;
  return retval;
}

/**
 *  Afecta os comentários relativos a um return
 *
 *  @param comments Comentários a adicionar
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
 *  Afecta o nº de revisão
 *
 *  @param revision Nº de revisão
 */
static void setRevision(char *revision)
{
  strcat(currentComment->revision,revision);
}

/**
 *  Afecta o since
 *
 *  @param revision Nº de revisão
 */
static void setSince(char *since)
{
  strcat(currentComment->since,since);
}

/**
 *  Afecta o see
 *
 *  @param revision Nº de revisão
 */
static void setSee(char *see)
{
  strcat(currentComment->see,see);
}
/**
 *  Afecta o autor
 *
 *  @param author Descrição do autor
 */
static void setAuthor(char *author)
{
  strcat(currentComment->author,author);
}


/**
 *  Afecta os comentários relativos a um todo
 *
 *  @param comments Comentários a adicionar
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
 *  Assigns a table usage definition in comment with table tag.
 *
 *  @todo : Tipo de utilização da tabela.
 *  @todo : Separar a tabela retirando-lhe base de dados.
 *
 *  @param tableId Table name
 */
static void setTable(char *tableId)
{
  TableUsage *tableUsage;

  if ( currentComment->tableStarted == 1 )
  {
    tableUsage = newTableUsage();
    currentComment->tableList[currentComment->tableIdx] = tableUsage;
    setTableUsageTableName(tableId,tableUsage);
    setTableUsageFoundAs(TU_COMMENT,tableUsage);
    setTableUsageOperation(TU_UNDEFINED,tableUsage);
    setTableUsageLineNumber(TU_UNDEFINED,tableUsage);
  }
  else
  {
    char *oldStr, newStr[64];
    tableUsage = currentComment->tableList[currentComment->tableIdx];
    oldStr = getTableUsageTableName(tableUsage);
    sprintf(newStr, "%s%s",oldStr,tableId);
    setTableUsageTableName(newStr,tableUsage);
    free(oldStr);
  }
  currentComment->tableStarted = 0;
}



/**
 * Foi descoberto um comentário de tag que deve ser escrito associado a tag 
 * corrente
 *
 * @param tagCode Código associado à tag corrente
 * @todo Colocar a inserção no buffer correspondente
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
    case TAG_SEE:
      setSee(tagComment);
      break;
    case TAG_SINCE:
      setSince(tagComment);
      break;
    case TAG_TABLE:
      setTable(tagComment);
      break;
  }
}

/**
 *  Afecta o código do processo corrente
 *
 *  @param id Código identificador do processo
 */
static void setProcessCode(char *id)
{
  currentComment->processCode[currentComment->processIdx] = (char *)strdup(id);
  currentComment->processIdx++;
  currentComment->waitingForProcess = 0;
}


/**
 * Foi descoberto um código de tag que deve ser escrito associado a tag corrente
 *
 * @param tagCode Código associado à tag corrente
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
 *  Escreve no texto do comentário um identificador descoberto caso este 
 *  não esteja no contexto de ser a definição de um processo
 *
 *  Executed by the comment parser.
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
 * Set the current comment as the module documentation comment.
 */
void setModuleDocument(void)
{
  currentComment->file = 1;
}

/**
 * It was found the @process process tag. changes to the corresponding state.
 */
void startProcess(void)
{
  currentComment->waitingForProcess = 1;
  commentState = TAG_CODE;
  currentTag   = TAG_PROCESS;
}

/**
 * It was found a parameter tag.
 */
void startParameter(void)
{
  commentState = TAG_CODE;
  currentTag   = TAG_PARAMETER;
}

/**
 * Foi descoberto o inicio de uma tag de return.
 * Marca na máquina de estados este facto para receber o texto para o
 * sitio certo.
 */
void startReturn(void)
{
  commentState = TAG_COMMENT;
  currentTag   = TAG_RETURN;
  currentComment->returnStarted = 1;
  currentComment->returnIdx++;
}

/**
 * Found a todo tag.
 * Mark the fact in the state machine in order to be read the todo text.
 */
void startTodo(void)
{
  commentState = TAG_COMMENT;
  currentTag   = TAG_TODO;
  currentComment->todoStarted = 1;
  currentComment->todoIdx++;
}

/**
 * Found a table tag.
 * Mark the fact in the state machine in order to be read the table text.
 *
 * Finishes the table state after reading a new tag.
 */
void startTable(void)
{
  commentState = TAG_COMMENT;
  currentTag   = TAG_TABLE;
  currentComment->tableStarted = 1;
  currentComment->tableIdx++;
}

/**
 * Started a Author tag.
 * Mark the fact in the state machine in order to read the author name
 */
void startAuthor(void)
{
  commentState = TAG_COMMENT;
  currentTag   = TAG_AUTHOR;
}

/**
 * Started a revision tag.
 * Mark the fact in the state machine in order to read the source code revision
 */
void startRevision(void)
{
  commentState = TAG_COMMENT;
  currentTag   = TAG_REVISION;
}

/**
 * Started a since tag.
 * Mark the fact in the state machine in order to read the source code revision
 */
void startSince(void)
{
  commentState = TAG_COMMENT;
  currentTag   = TAG_SINCE;
}

/**
 * Started a SEE tag.
 * Mark the fact in the state machine in order to read the source code revision
 */
void startSee(void)
{
  commentState = TAG_COMMENT;
  currentTag   = TAG_SEE;
}

/**
 * Nova linha iniciada. 
 * Marca na flag correspoondente e consoante o contexto chama a função
 * para escrita no buffer
 */
void writeNewLine(void)
{
  commentLineStarted = 1;
}

/**
 *  Write in the comment text a string that was found.
 *  Executed by the lexer when he found a string that its not a a tag.
 *  The string found belong to the current tag and is apended to it.
 *
 *  @param comm : The string with the text to be appended to the proper tag.
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
      if ( currentTag != TAG_TABLE )
        writeTagComment(comm);
      break;
    case TAG_CODE:
      break;
  }
}

/**
 * Was found a separator in the comment. 
 * Normaly the separator is appended to the tag comment or to comment buffer.
 * When the state is in some specific TAG_COMMENT (TABLE) the 
 *
 * @param comm The separator found.
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

/**
 * Found the deprecated tag.
 * Marks the fact in the current comment.
 */
void markAsDeprecated(void)
{
  currentComment->deprecated = 1;
}


