/**
 * @file 
 * Header file with function prototypes implemented in ReadComments.c
 */

#ifndef READ_COMMENTS_H
#define READ_COMMENTS_H

class ReadComments {
  public :
    char *readDocComment(void);
    char *readBlockComment(void);
    char *readLineComment(void);
};
#endif
