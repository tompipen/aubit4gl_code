
/**
 *  @file 
 *  Definição do buffer que guarda um comentário fgldoc
 *  
 *  @todo Maior dinamismo nos arrays
 *
 */ 

#include "Parameters.h"

typedef struct {
  char       *buffer;
  char       *processCode[10];
	int        processIdx;
	int        waitingForProcess;
  Parameters *parameterList;
	int        waitingForParam;
  char       *returnList[10];
	int        returnIdx;
	int        returnStarted;
	char       *todoList[100];
	int        todoIdx;
	int        todoStarted;
	char       *author;
	char       *revision;
	int        deprecated;
	TableUsage  **tableList;
	int         tableIdx;
	int         tableStarted; // There should be only one variable to state mach
} Comment;

char *getCommentBuffer(Comment *comment);
int getCommentDeprecated(Comment *comment);
TableUsage *getCommentTableUsage(Comment *comment,int index);
int getCommentTableUsageIdx(Comment *comment);
