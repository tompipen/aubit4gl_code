/**
 * @file 
 * Header file for prototype declaration for functions in ParseComment.c
 */

#ifndef PARSE_COMMENT_H
#define PARSE_COMMENT_H
class ParseComment {
	private:
    void yyCommentlex(void); //defined in CommentLexer.c/.l
    static char *currentChar;
    static int commentLineStarted = 0;
    void setReturnComments(char *comments);
    void setRevision(char *revision);
    void setSince(char *since);
    void setSee(char *see);
    void setAuthor(char *author);
    void setTodoComments(char *comments);
    void setTable(char *tableId);
    void writeTagComment(char *tagComment)
    void setProcessCode(char *id);
    void writeTagCode(char *tagCode);
    void writeCommentIdentifier(char *id);
    void startProcess(void);
  public:
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
    void setModuleDocument(void);
};
#endif
