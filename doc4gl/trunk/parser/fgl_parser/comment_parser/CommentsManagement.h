
#ifndef COMMENTS_MANAGEMENT_H
#define COMMENTS_MANAGEMENT_H

class CommentsManagement {
  private :
    /**
     * Current comment for the states where the comment is not yet stored 
     * Temporary buffer for candidate states.
     */
    Comment *currentComment;
	public:
    void documentationComment(void);
    void defineFunctionOcurred(void);
};
#endif
