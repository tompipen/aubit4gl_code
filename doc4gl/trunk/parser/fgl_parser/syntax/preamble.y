

/**
 * @file
 *
 * Informix 4gl grammar in bison format.
 * This grammar is based in the Aubit 4gl grammar that works ok 
 * with a lot of 4gl code.
 *
 * The first goal with this grammar is put it working without C code
 * in order to implement the loading of a 4gl object model.
 *
 */


%{

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

// This is necessary to receive a pointer to the lexer object. This macro is
// deprecated
#define YYPARSE_PARAM fglLexer , FglModule **ast

// @todo : See an alternative since this macro is deprecated
#define YYLEX_PARAM yystate,yyssa,yyssp


// Hehe - This one is pretty cool if you have a fairly recent version of bison
#define YYERROR_VERBOSE

#define YYDEBUG 1


/* prevent warning for redundant declaration of yyparse: */
#define _BISON_SIMPLE_INCL_

#define _NO_Y_TAB_H_
#define _NO_WINDOWS_H_

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "FglAst.h"
#include "a4gl_4glc_int.h"
#include "FglLexer.h"

/** 
 * A macro that define the call to the error function.
 * The error function is in the error handler registered in the lexer.
 */
#define a4gl_yyerror(e) ((FglLexer *)fglLexer)->getParserError()->addError(e, \
((FglLexer *)fglLexer)->getLine(),0)

/*
=====================================================================
		                    Variables definitions
=====================================================================
*/

// It still depends on a global function of the parser and should receive as
// a parameter
//int a4gl_yylex (void *pyylval, int yystate, void *yys1, void *yys2);
#define a4gl_yylex(x,y) ((FglLexer *)fglLexer)->yyLex((void *)x,y)


%}
/** The prefix used when generating the C code. */
%name-prefix="a4gl_yy"

/* This makes the parser reentrant (does not depend on anything global). */
%pure-parser

/* Testing parser parameters - This cores bison 1.875 */
//%parse-param "FglLexer *fglLexer", "fglLexer"





/* The start rule that the parser accepts */
%start module

/* The union where the values of rules are stored */
%union	  {
	FglIdentifier *fgl_identifier;
	FunctionList *fgl_function_list;
	FglFunction *function;
	FglToken *token;
	FglModule *fgl_module;
	// @todo : Remove this way of talking to the parser
	char	str[1024];  /* This would core dump in CygWin on call to */
	}

/* <TOKEN_TYPE> */

%type <token> NAMED_GEN	NAMED
%type <function> func_def	func_or_main 
%type <fgl_identifier> identifier	
%type <fgl_function_list> function_list func_main_def
%type <fgl_module> module
/* <TOKEN_TYPE> */

%token <str> NAME
%left UMINUS
%left COMMA
%left KW_OR         
%left KW_AND        
%left KW_USING 
%left NOT
%left MATCHES     
%left POWER
%left LESS_THAN 
%left GREATER_THAN 
%left EQUAL 
%left GREATER_THAN_EQ 
%left LESS_THAN_EQ 
%left NOT_EQUAL
%left MINUS PLUS
%left DIVIDE MULTIPLY
%left MOD
%right COMMAND

%token NUMBER_VALUE
%token CHAR_VALUE
%token INT_VALUE
%token NAMED_GEN
/* %token COMMENT */
%token CLINE
%token SQLLINE
%token KW_CSTART
%token KW_CEND
%token USER_DTYPE
%token SQL_TEXT
