/**
 *  @file 
 *  Definition of the buffer where a fgldoc comment is stored.
 *  
 *  @todo The arrays should be much more dynamic.
 *  @todo Add more tags
 *  @todo See tag
 *
 */ 

#include "Parameters.h"

typedef struct {
  char       *buffer;           /**< The buffer containing the text of the comment */
  char       file;              /**< A boolean flag to indicate that is file comment */
  char       *processCode[10];  /**< Process tables refered in this comment */
  int        processIdx;        /**< Number of elements filled in process table */
  int        waitingForProcess; /**< Internal state */
  Parameters *parameterList;    /**< Pointer to a function parameter list */
  int        waitingForParam;   /**< Internal state */
  char       *returnList[10];   /**< Return list defined in the comment */
  int        returnIdx;         /**< Number of elements filled in the return list */
  int        returnStarted;     /**< Internal state */
  char       *todoList[100];    /**< List of tasks todo in the comment */
  int        todoIdx;           /**< Number of elements in the todo list */
  int        todoStarted;       /**< Internal state */
  char       *author;           /**< Author refered with the @author tag */
  char       *revision;         /**< Source revision refered with the @revision tag */
  int        deprecated;        /**< Deprecation marker found */
  char        *since;           /**< A since tag */
  char        *see;             /**< A see tag */
  TableUsage  **tableList;      /**< Table usage list */
  int         tableIdx;         /**< Number of elements filled in the table list */
  char       *formList[100];    /**< List of forms defined in the comment or found */
  int        formIdx;           /**< Number of elements in the form list */
  int         tableStarted;     /**< Internal state */
} Comment;

char *getCommentBuffer(Comment *comment);
int getCommentDeprecated(Comment *comment);
TableUsage *getCommentTableUsage(Comment *comment,int index);
int getCommentTableUsageIdx(Comment *comment);
