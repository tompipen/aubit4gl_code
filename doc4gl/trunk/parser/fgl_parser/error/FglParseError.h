
#ifndef FGLPARSERROR_H
#define FGLPARSERROR_H

class FglParseError {
  private:
		int line;
		int column;
		char *msg;
	public:
		FglParseError(const char *msg);
		FglParseError(const char *msg,int line,int column);
		int getLine();
		int getColumn();
		const char *getMsg();
		~FglParseError();
};

#endif
