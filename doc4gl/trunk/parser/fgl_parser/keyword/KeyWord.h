/**
 * @file
 * A class that encapsulate the usage of the keywords table of the 4gl 
 * parser.
 *
 * The keywords was originaly generated to a C structure but i want
 * to have severall methods to do it.
 *
 * This class should be an interface to use it.
 *
 * The first aproach use the C structure and the functions that i found
 * at the lexer.
 */

#ifndef KEYWORD_H
#define KEYWORD_H
	  
class KeyWord {
  private:
		int id;
		int mode;
		char *vals;
	public:
		KeyWord(int _id, int _mode, char *_vals);
		// @todo : Making acessors with operator overloading
		int getId();
		int getMode();
		char *getVals();
		~KeyWord();
};

#endif
