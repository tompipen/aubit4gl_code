/**
 * @file 
 * Header file for prototype declaration for functions in ParseComment.c
 */

Comment *parseComment(char *commentToParse);
int getCommentChar(void);
void writeCommentIdentifier(char *id);
void startProcess(void);
void startParameter(void);
void startReturn(void);
void startTodo(void);
void startAuthor(void);
void startRevision(void);
void writeNewLine(void);
void writeOtherComment(char *comm);
void writeSeparator(char *comm);
void markAsDeprecated(void);
