/**
 * @file
 * Read of special comments handling.
 *
 * This functions are called by the lexer and the parser, calls the reading 
 * functions and store when needed the comments readed.
 *
 * A module comment is marked with the @file tag.
 * All other comments are function comments.
 *
 * @todo : Check if the comment parser alocate speca each time its called 
 */

#include "TableUsage.h"
#include "Comment.h"
#include "ParseComment.h"
#include "ReadComments.h"
#include "CommentsManagement.h"

/**
 * Event that ocurs when the lexer found the begining of a documentation
 * comment.
 *
 * Read the documentation comment from the stream and acording to the state
 * machine do the corresponding action
 */
void CommentsManagement::documentationComment(void)
{
  char *comment;
  Comment *commentParsed;

  comment = readDocComment();
  commentParsed = parseComment(comment);
  incrementNumFgldoc();

  if ( commentParsed->file == 1 )
    setModuleComment(commentParsed);
  else
    currentComment = commentParsed;
}

/**
 * Event ocurred when the parser found the begining of function implementation
 */
void CommentsManagement::defineFunctionOcurred(void)
{
  setFunctionComment(currentComment);
}


