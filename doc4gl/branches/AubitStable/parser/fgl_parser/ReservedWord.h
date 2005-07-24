
/**
 * @file
 * A reserved word object.
 * @todo : Change the names and explain all.
 * @todo : Fix the 20 length limitation for each keyword.
 */

#ifndef RESERVEDWORD_H
#define RESERVEDWORD_H

class ReservedWord {
  private:
    int id;         //< Token numeric unique identification 
		int mode;       //< Allways 1 in the table file
		char *vals[20]; //< Array of reserved words and identifier marker(s)
};

#endif
