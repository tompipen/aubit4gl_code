/**
 * @file
 *
 * Functions to manage a Comment structure (a kind of object point of view)
 *
 * @todo : Functions to handle the rest of the fields of Comment
 */

#include <stdio.h>
#include "TableUsage.h"
#include "Comment.h"

/**
 * Gets the text buffer of a comment.
 *
 * If receive a NULL return a null
 *
 * @param comment A pointer to the comment structure.
 */
char *getCommentBuffer(Comment *comment)
{
  if ( comment == (Comment *)0)
	  return NULL;
	return comment->buffer;
}

/**
 * Gets the deprecated field of a comment
 *
 * If receive a NULL return 0
 *
 * @param comment The deprecated flag.
 */
int getCommentDeprecated(Comment *comment)
{
  if ( comment == (Comment *)0)
	  return -1;
	return comment->deprecated;
}

/**
 * Get(s) a table usage from the comment
 *
 * @param comment A pointer to the comment where to get the table usage.
 * @param index The index of the table usage in the list
 * @return The pointer to the table usage structure.
 */
TableUsage *getCommentTableUsage(Comment *comment,int index)
{
  if ( comment == (Comment *)0)
	  return (TableUsage *)0;
  if ( index > comment->tableIdx || index < 0 )
	  return (TableUsage *)0;
	return comment->tableList[index];
}

/**
 * Get(s) the number of table usages in the comment.
 *
 * @param comment A pointer to the comment where to get the table usage.
 * @return The number of table usages.
 */
int getCommentTableUsageIdx(Comment *comment)
{
  if ( comment == (Comment *)0)
	  return -1;
	return comment->tableIdx;
}
