/**
 * @file
 * Read and state machine comments handling.
 *
 * This functions are called by the lexer and the parser, calls the reading 
 * functions and store when needed the comments readed.
 *
 * @todo : Check if the comment parser alocate speca each time its called 
 */

#include "TableUsage.h"
#include "Comment.h"
#include "ParseComment.h"
#include "ReadComments.h"

/**
 * Current comment for the states where the comment is not yet stored 
 * Temporary buffer for candidate states.
 */
static Comment *currentComment;

/**
 * Current comment state machine state
 */
static int currentState;

/** The first state regarding the document comment reading */
#define BEGIN_STATE 0

/** The state where the comment readed is a module candidate */
#define MODULE_CANDIDATE 1

/** The state where the comment readed is a module comment */
#define MODULE_COMMENT 2

/** The state where the comment readed is a function candidate */
#define FUNCTION_CANDIDATE 3

/** The state where the comment readed is a function comment */
#define FUNCTION_COMMENT 4

/**
 * Change the state to begin state
 */
static void changeToBegin(void)
{
  currentState = BEGIN_STATE;
}

/**
 * Change the state to Function candidate state
 */
static void changeToFunctionCandidate(void)
{
  currentState = FUNCTION_CANDIDATE;
}

/**
 * Change the state to module candidate
 */
static void changeToModuleCandidate(void)
{
  currentState = MODULE_CANDIDATE;
}

/**
 * Change the state to module comment
 */
static void changeToModuleComment(void)
{
  currentState = MODULE_COMMENT;
}

/**
 * Change the state to function comment
 */
static void changeToFunctionComment(void)
{
  currentState = FUNCTION_COMMENT;
}


/**
 * Event that ocurs when the lexer found the begining of a documentation
 * comment.
 *
 * Read the documentation comment from the stream and acording to the state
 * machine do the corresponding action
 */
void documentationComment(void)
{
	char *comment;
	Comment *commentParsed;

  comment = readDocComment();
  commentParsed = parseComment(comment);
	incrementNumFgldoc();

	/** Atenção pode haver aqui um eventual memory leak */
  switch ( currentState )
	{
			case BEGIN_STATE:
				currentComment = commentParsed;
				changeToModuleCandidate();
			  break;
			case MODULE_CANDIDATE:
				setModuleComment(currentComment);
				currentComment = commentParsed;
				changeToFunctionCandidate();
			  break;
			case MODULE_COMMENT:
				currentComment = commentParsed;
				changeToFunctionCandidate();
			  break;
			case FUNCTION_CANDIDATE: /** O ultimo comentário é que vale */
				currentComment = commentParsed;
			  break;
			case FUNCTION_COMMENT:
				currentComment = commentParsed;
				changeToFunctionCandidate();
			  break;
      otherwise:
				printf("ERROR: INVALID COMMENT STATE\n");
	}
}

/**
 * Event ocurred when the parser found the begining of function implementation
 */
void defineFunctionOcurred(void)
{
  switch ( currentState )
	{
			case BEGIN_STATE:
				changeToFunctionCandidate();
			  break;
			case MODULE_CANDIDATE:
				setFunctionComment(currentComment);
				changeToFunctionComment();
			  break;
			case MODULE_COMMENT:
			  break;
			case FUNCTION_CANDIDATE:
				setFunctionComment(currentComment);
				changeToFunctionComment();
			  break;
			case FUNCTION_COMMENT:
			  break;
	}
}

/**
 * Event ocurred when the parser found a define or globals outside functions
 */
void defineOrGlobalsOcurred(void)
{
  switch ( currentState )
	{
			case BEGIN_STATE:
				changeToBegin();
			  break;
			case MODULE_CANDIDATE:
				setModuleComment(currentComment);
				changeToModuleComment();
			  break;
			case MODULE_COMMENT:
			  break;
			case FUNCTION_CANDIDATE:
			  break;
			case FUNCTION_COMMENT:
			  break;
	}
}


/**
 * Initialize the documentation reading state machine.
 *
 * It should be called by initialization function of the parser since
 * it is used during one 4gl source parsing.
 */
void initCommentStateMachine(void)
{
  currentState = BEGIN_STATE;
	currentComment = (Comment *)0;
}
