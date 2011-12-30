LIBRARY SQLPARSECMD
VARIABLE A4GL_PARSECMD
LIB_PREFIX A4GLPARSECMD_

#ifdef DEBUG_SPEC
#undef DEBUG_SPEC
#endif
/* This is used just by the 4gl compiler tools to  */
/* process SQL commands into the internal representation used by the 4gl compiler itself */
/* */
/*   This is primarily used to check PREPARE statements in the fglcalltree tool.. */

processSQL char* sqlCmd -> command* c
