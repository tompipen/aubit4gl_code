

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
// @todo : The old FglModule ast should be removed
#define YYPARSE_PARAM fglLexer , NodeState *astState

// @todo : See an alternative since this macro is deprecated
#define YYLEX_PARAM yystate,yyssa,yyssp, astState


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

/** A macro to access to the treecc ast easyly */
#define	AST_STATE	((NodeState *)astState)

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

/* This makes the parser reentrant (does not depend on any global variables). */
%pure-parser

/* Testing using parser parameters - This cores bison 1.875 */
//%parse-param "FglLexer *fglLexer", "fglLexer"


/* The start rule that the parser accepts */
/* If we want to make dynamic SQL parser generation this rule should be 
 * generated.
 */
%start module

/* The union where the values of rules are stored */
%union {
	FglNode *node;
}

/* <TOKEN_TYPE> */

/* More generic types for generic rules */
%type <node> variable

%type <node> NAMED_GEN	NAMED
%type <node> function_definition	abstract_function 
%type <node> identifier	abstract_open_form_rest open_form_name
%type <node> function_list op_function_list
%type <node> module
%type <node> open_form_cmd commands_all1 	

/* For initialize statement */
%type <node> init_cmd init_bind_var_list init_bind_var

/* <TOKEN_TYPE> */

//%token <str> NAME
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


