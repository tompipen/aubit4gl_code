
#ifndef FGL_TOKEN_H
#define FGL_TOKEN_H

#include "FglNode.h"

class FglToken : public FglNode {
  private:
		char *tokenText;
	public:
	  FglToken(int line,char *tokenText);
	  ~FglToken();
		char *getText();
};

#endif
