/**
 * @file
 * Analisador sintatico e semântico de linguagem 4gl
 *
 * Diminutivos utilizados:
 *   - TOK : Token
 *   - op  : Optional
 */

%{

#include <stdio.h>
#include <alloca.h>
#include "p4gl_symtab.h"

char *CpStr();
char *GetListConcat();

extern int lineno;             /* 4GL Source current line */
%}


%union {                         /* Union for token information (number, etc) */
	char            y_sym[40];
	char            y_string[128];
	int             y_num;
	int             y_cursor_type;
	VAR_DECLARATION y_var;
	char            *y_text;             /* Para textos diversos - dinamico */
	NAME_LIST       *y_name_list;        /* Array de listas de variaveis */
	}

/* 
 *  Simbolos terminais
 */

%token <y_sym>    IDENTIFIER
%token <y_string> STRING
%token <y_num>    NUMBER

%token	ABORT ABSOLUTE ADD AFTER ALL ALLOCATE ALTER AND ANSI ANY APPEND
%token  ARRAY AS ASC ASCENDING ASCII AT ATTACH ATTRIBUTE ATTRIBUTES AUDIT
%token  AUTHORIZATION AUTONEXT 

%token	BEFORE BEGIN_TOK BETWEEN BLINK BOLD BORDER BOTH BOTTOM BREAK
%token  BUFFERED BY BYTE

/* To remove */
%token  BLUE 
%token	BLACK

%token	CALL CASCADE CASE CHAR CHECK CLEAR CLIPPED CLOSE CLUSTER COLUMN
%token  COLUMNS COMMAND COMMENT COMMIT COMMITTED COMPRESS 
%token  CONSTRAINED CONSTRAINT CONSTRAINTS CONSTRUCT CONTINUE
%token  CONTROL COUNT CREATE CURRENT CURSOR 

/* To remove */
%token   CYAN

%token	DATABASE DATE DATETIME DAY
%token  DEC DECLARE DEFAULT DEFAULTS DEFER DEFERRED DEFINE DELETE
%token  DELIMITER DELIMITERS DESC DESCENDING DETACH
%token  DIAGNOSTICS DIM DIRTY DISABLE DISABLED DISPLAY DISTINCT
%token  DOUBLE DOWN DROP

%token	ELSE ENABLE ENABLED END_TOK ERROR ESCAPE EVERY EXCLUSIVE
%token  EXECUTE EXISTS EXIT EXP EXPO EXPLAIN EXTEND EXTENT 
%token  EXTERNAL

%token	FALSE_TOK FETCH FIELD FILE_TOK FILLFACTOR FILTERING FINISH FIRST FLOAT 
%token  FLUSH FOR FOREACH FOREIGN FORM FORMAT FORMONLY FOUND FRACTION FRAGMENT
%token  FREE FROM FUNCTION_TOK

%token	GLOBAL GLOBALS_TOK GO GOTO GRANT GREATER_OR_EQUAL GROUP

/* To remove */
%token  GREEN 

%token	HAVING HEADER HELP HEX HIDE HIGH HOLD HOUR

%token	IF IMMEDIATE IN INC_GLOBALS INDEX INDEXES
%token  INITIALIZE INPUT INSERT INSTRUCTIONS INTEGER INTERRUPT
%token  INTERVAL INTO INVISIBLE IS ISOLATION 

%token	KEY

%token	LABEL LAST LEADING LEFT LENGTH    LESS_OR_EQUAL LET LIKE LINE LINES
%token  LOAD LOCATE LOCK LOG LONG LOW

/* To remove */
%token	MAGENTA 

%token  MAIN MARGIN MATCHES MEDIUM MEMORY MENU MESSAGE MINUTE
%token  MOD MODE MODIFY MONEY 

%token	MAX       /* Devia passar a ser funcao interna */

%token	NAME NCHAR NEED NEXT NO NONE NORMAL NOT NOT_EQUAL
%token  NULL_TOK NVARCHAR

%token	OF OFF ON OPEN OPTIMIZATION OPTION OPTIONS OR ORDER OTHERWISE
%token  OUTER OUTPUT

%token	PAGE PAGENO PAUSE PDQPRIORITY PICTURE PIPE PRECISION PREPARE PREVIOUS
%token  PRIMARY PRINT PRINTER PRIOR PRIVILEGES PROCEDURE
%token  PROGRAM PROMPT PUBLIC PUT

%token	QUIT

%token	RAISE READ REAL RECORD REFERENCES REFERENCING
%token  RELATIVE REMOVE RENAME REPEATABLE
%token  REPORT REQUIRED RESOURCE RESTRICT RETURN RETURNING
%token  REVERSE REVOKE RIGHT ROBIN ROLLBACK ROLLFORWARD ROUND ROW 
%token  ROWS RUN

/* To remove */
%token  RED 

%token	SCREEN SCROLL SECOND SELECT SERIAL 
%token  SET SHARE SHOW SKIP SLEEP SMALLFLOAT
%token  SMALLINT SOME SPACES SQL_TOK SQLERROR SQLWARNING
%token  STABILITY START STATISTICS STEP STOP 
%token  SYNONYM 

%token	TAB TABLE TABLES TEMP TEXT THEN THROUGH THRU TIME TO TOP TOTAL
%token  TRAILER TRANSACTION TRUE_TOK

%token	UNCOMMITTED UNCONSTRAINED UNDERLINE UNION UNIQUE UNITS UNLOAD UNLOCK
%token  UP UPDATE USER USING

%token	VALIDATE VALUES VARCHAR VARIABLES VERIFY VIEW

%token	WAIT WAITING WARNING WHEN WHENEVER WHERE WHILE WHITE WINDOW WITH
%token  WITHOUT WORDWRAP WORK WRAP 


/* To remove */
%token	YEAR YELLOW


%token '{'
%token '}'
%token '['
%token ']'
%token ','
%token '.'
%token '*'
%token ';'
%token '='
%token '<'
%token '>'
%token '@'


%token	UINTEGER   /* Unsigned e Signed integer */
%token	SINTEGER

%type       <y_sym>              number
%type       <y_sym>              literal
%type       <y_sym>              var_name
%type       <y_sym>              named_value
%type       <y_sym>              string_or_var
%type       <y_cursor_type>      cursor_type
%type       <y_sym>              cursor_name
%type       <y_name_list>        named_value_list
%type       <y_name_list>        table_reference_list
%type       <y_name_list>        op_argument_list       
%type       <y_name_list>        variable_list_declaration       
%type       <y_sym>              table_name
%type       <y_sym>              table_identifier
%type       <y_sym>              table_reference
%type       <y_sym>              fgl_basic_operand
%type       <y_sym>              fgl_operand
%type       <y_sym>              unload_target

%type       <y_text>             fgl_simple_data_type
%type       <y_text>             fgl_data_type
%type       <y_text>             array_data_type         
%type       <y_num>              cursor_specification
%type       <y_text>             record_data_type        decimal    money  
%type       <y_text>             datetime current        interval   varchar 
%type       <y_text>             op_char_length          char       dtqualifier
%type       <y_text>             maximum_and_reserve     float
%type       <y_text>             op_precision_and_scale  

%type       <y_text>             op_group_by_clause
%type       <y_text>             group_by_clause
%type       <y_text>             op_having_clause
%type       <y_text>             having_clause
%type       <y_text>             column_specification
%type       <y_text>             column_specification_list
%type       <y_text>             column_name
%type       <y_text>             column_identifier
%type       <y_text>             op_order_by_clause
%type       <y_text>             sort_specification_list
%type       <y_text>             sort_specification
%type       <y_text>             op_asc_desc
%type       <y_text>             select_list
%type       <y_text>             value_expression_list
%type       <y_text>             value_expression
%type       <y_text>             factor
%type       <y_text>             primary
%type       <y_text>             op_as_field
%type       <y_text>             set_function_specification
%type       <y_text>             distinct_set_function
%type       <y_text>             all_set_function
%type       <y_text>             all_set_function
%type       <y_text>             op_where_clause
%type       <y_text>             op_all
%type       <y_text>             where_clause
%type       <y_text>             search_condition
%type       <y_text>             boolean_term
%type       <y_text>             boolean_factor
%type       <y_text>             boolean_primary
%type       <y_text>             predicate
%type       <y_text>             comparison_predicate
%type       <y_text>             between_predicate
%type       <y_text>             in_predicate
%type       <y_text>             like_predicate
%type       <y_text>             matches_predicate
%type       <y_text>             null_predicate
%type       <y_text>             quantified_predicate
%type       <y_text>             exists_predicate
%type       <y_text>             comp_op
%type       <y_text>             op_not
%type       <y_text>             table_expression
%type       <y_text>             from_clause
%type       <y_text>             quantifier
%type       <y_sym>              value_specification
%type       <y_sym>              parameter_specification
%type       <y_sym>              variable_specification
%type       <y_sym>              sql_literal
%type       <y_sym>              pattern
%type       <y_sym>              escape_character
%type       <y_sym>              op_escape
%type       <y_sym>              target_specification
%type       <y_text>             op_call_parameters
%type       <y_text>             function_call
%type       <y_text>             function_name
%type       <y_text>             select_statement
%type       <y_text>             insert_statement
%type       <y_text>             update_statement_search
%type       <y_text>             update_statement_position
%type       <y_text>             set_clause_list
%type       <y_text>             set_clause_ansi_list
%type       <y_text>             set_clause_ansi
%type       <y_text>             set_clause_infx
%type       <y_text>             update_columns
%type       <y_text>             update_column_list
%type       <y_text>             op_insert_column_list
%type       <y_text>             insert_column_list
%type       <y_text>             insert_value_list
%type       <y_text>             insert_value
%type       <y_text>             query_term
%type       <y_text>             query_specification
%type       <y_text>             query_expression
%type       <y_text>             delete_statement_search
%type       <y_text>             delete_statement_position

%type       <y_text>             time_expression
%type       <y_text>             interval_value
%type       <y_text>             datetime_value
%type       <y_text>             date_value
%type       <y_text>             datetime_literal
%type       <y_text>             op_interval_sign
%type       <y_text>             op_datetime_qualifier
%type       <y_text>             numeric_time_interval
%type       <y_text>             op_num

/* Preparação para novas expressões  
character_expression
%type       <y_text>             op_subscript
%type       <y_text>             op_character_format_list
%type       <y_text>             character_format
%type       <y_text>             number_expression
%type       <y_text>             simple_number_expression
%type       <y_text>             number_operator
%type       <y_text>             mod_exp_operator
%type       <y_text>             literal_number
%type       <y_text>             op_decimals
%type       <y_text>             fgl_boolean_expression
%type       <y_text>             fgl_simple_boolean_expression
%type       <y_text>             op_not_list
%type       <y_text>             not_list
%type       <y_text>             op_not
%type       <y_text>             boolean_comparison
%type       <y_text>             set_membership_test
%type       <y_text>             fgl_expression_list
%type       <y_text>             string_comparison
%type       <y_text>             integer_expression
%type       <y_text>             pure_integers
%type       <y_text>             pure_integer
%type       <y_text>             literal_integer
%type       <y_text>             null_test
%type       <y_text>             relational_comparison
 */

%token		','
%token		COLON
%token		SEMICOLON
%right		NEG  
%left		'/' '*'
%left		'+' '-'
%left		'=' NOT_EQUAL '>' '<' GREATER_OR_EQUAL LESS_OR_EQUAL 


%start fgl_source

%%

/* ======================= HIGH LEVEL DEFINITIONS */

fgl_source
	: op_database op_variable_dec_list op_function_list

op_variable_dec_list
	:
	| op_variable_dec_list globals_list
	| op_variable_dec_list define_list
	| globals_list
	| define_list

globals_list
	: globals_list globals
	| globals

globals
	: op_define_globals
	| op_inc_globals

op_define_globals
   : GLOBALS_TOK                         { InGlobals = 1; InLimbo=0;   }
	  op_define_list END_TOK GLOBALS_TOK   
		  { InGlobals = 0; InLimbo=1; defineOrGlobalsOcurred();}
	;

                                /* Included global variable by pre-processing */
op_inc_globals
	: INC_GLOBALS STRING                { InInclude = 1;GlobalsInclude($2);
												 	  back_lineno = lineno-2;           }
	  op_database
	  op_define_globals
	  op_function_list
	  END_TOK INC_GLOBALS               
		  { InInclude = 0; lineno=back_lineno; defineOrGlobalsOcurred(); }
	;

/*
 * Tem de se afectar um estado e nao fazer nada se estas estiverem 
 * num include
 */
op_function_list
	:
	| function_list
	;

op_database
	: 
	| database
	;

/*  ====================== VARIABLE DEFINITION */
op_define_list
	:
	| op_define_list define_statement
	| define_statement
	;

define_list
	: define_list define_statement
	| define_statement
	;

define_statement
	: DEFINE 
	  variable_definition_list op_semicolon
	{ defineFound(); }
	;

variable_definition_list
	: variable_definition_list ',' variable_declaration
	| variable_declaration
	;

variable_declaration
	: variable_list_declaration fgl_data_type
	                                { StInsVarListDeclaration($1,$2);} 
	;

variable_list_declaration
	: variable_list_declaration ',' var_name
		                             { InsertNameList(&$$,$1,$3,lineno+1);    }
	| var_name
		                    { InsertNameList(&$$,(NAME_LIST *)0,$1,lineno+1); }
	;

fgl_data_type
	: fgl_simple_data_type                   { $$ = CpStr($1); }
	| LIKE table_identifier '.' column_name  { $$ = CpStr("LIKE %s.%s",$2,$4); } 
	| LIKE IDENTIFIER ':' table_identifier '.' column_name  { $$ = CpStr("LIKE %s.%s",$2,$4); } 
	| array_data_type                        { $$ = CpStr($1); }
	| record_data_type                       { $$ = CpStr($1); }
	| TEXT                                   { $$ = CpStr("TEXT"); }
	| BYTE                                   { $$ = CpStr("BYTE"); }
	;

array_data_type
	: ARRAY '[' array_dim ']' OF fgl_data_type { $$ = $6; }

/* ??? Aqui existem conflitos  */
/* ??? As afectacoes sao so para o bison funcionar */
array_dim
	: NUMBER                         { int x; x = $1; }
	| NUMBER ',' NUMBER              { int x; x = $1; x=$3; }
	| NUMBER ',' NUMBER ',' NUMBER   { int x; x = $1; x=$3; x=$5;}
	;

/* Tenho de limpar as variaveis entretanto descobertas pois sao sub-variaveis */
/* TODO - Esta regra está agranelada */
record_data_type
	:    RECORD                             { InRecord = 1; }
	        variable_definition_list 
	     END_TOK RECORD                     { InRecord = 0;  $$=CpStr("RECORD");}
	| RECORD LIKE table_identifier '.' '*'  {$$=CpStr("RECORD LIKE %s.*",$3); }
	| RECORD LIKE IDENTIFIER ':' table_identifier '.' '*'  {$$=CpStr("RECORD LIKE %s.*",$5); }
	| RECORD LIKE IDENTIFIER '@' IDENTIFIER ':' table_identifier '.' '*'  {$$=CpStr("RECORD LIKE %s.*",$7); }
	;

fgl_simple_data_type
	: INTEGER        { $$ = CpStr("INTEGER"); }
	| SMALLINT       { $$ = CpStr("SMALLINT"); }
	| decimal        { $$ = CpStr($1); }
  | money          { $$ = CpStr($1); }
	| float          { $$ = CpStr($1); }
	| SMALLFLOAT     { $$ = CpStr("SMALLFLOAT"); }
	| REAL           { $$ = CpStr(SMALLFLOAT); }
  | DATE           { $$ = CpStr("DATE"); }
	| char           { $$ = CpStr($1); }
	| datetime       { $$ = CpStr($1); }
	| current        { $$ = CpStr($1); }
	| interval       { $$ = CpStr($1); }
	| varchar        { $$ = CpStr($1); }
	;

datetime
	: DATETIME dtqualifier TO dtqualifier
							  { $$ = CpStr("DATETIME %s TO %s",$2,$4); }
	| DATETIME dtqualifier TO dtqualifier '(' NUMBER ')'
							  { $$ = CpStr("DATETIME %s TO %s (%d)",$2,$4,$6); }
	;

/* ??? Faltam ainda alguns casos */
interval
	: INTERVAL dtqualifier TO dtqualifier
							  { $$ = CpStr("INTERVAL %s TO %s",$2,$4); }
	| INTERVAL dtqualifier op_precision TO dtqualifier op_precision
							  { $$ = CpStr("INTERVAL %s TO %s (??)",$2,$5); }
	;

op_precision
	:
	| '(' NUMBER ')'
	;

current
	: CURRENT
					{ $$ = CpStr("CURRENT"); }
	| CURRENT current_qualifier TO current_qualifier
					{ $$ = CpStr("CURRENT"); }

current_qualifier
	: IDENTIFIER   { char *x;   x = $1; }
	| dtqualifier  { char *x;   x=CpStr($1); }
	
dtqualifier 
	: IDENTIFIER op_precision_and_scale { $$ = CpStr($1); } 
	| HOUR op_precision_and_scale       { $$ = CpStr("HOUR"); } 
	| MINUTE op_precision_and_scale     { $$ = CpStr("MINUTE"); }
	| SECOND op_precision_and_scale     { $$ = CpStr("SECOND");}
	| FRACTION op_precision_and_scale   { $$ = CpStr("FRACTION"); }
	| YEAR op_precision_and_scale       { $$ = CpStr("YEAR");}
	| DAY op_precision_and_scale        { $$ = CpStr("DAY"); }
	;

char 
	: CHAR op_char_length  { $$ = CpStr("CHAR %s",$2); }
	;

op_char_length
	:                      { $$ = CpStr(""); }
	| '(' NUMBER ')'       { $$ = CpStr("(%d)",$2); }
	;

varchar
	: VARCHAR maximum_and_reserve  { $$ = CpStr("VARCHAR %s",$2); }
	;

maximum_and_reserve
	: '(' NUMBER ')'               { $$ = CpStr("(%d)", $2); }
	| '(' NUMBER ',' NUMBER ')'    { $$ = CpStr("(%d,%d)", $2,$4); }
	;

decimal
   : DEC op_precision_and_scale   { $$ = CpStr("DECIMAL %s",$2); }
	;

money
   : MONEY op_precision_and_scale { $$ = CpStr("MONEY %s",$2); }
   ;

float
	: float_synonim '(' NUMBER ')' { $$ = CpStr("FLOAT (%d)",$3); }
	| float_synonim                { $$ = CpStr("FLOAT"); }
	;

float_synonim
	: FLOAT
	| DOUBLE PRECISION
	;

op_precision_and_scale
	:                              { $$ = CpStr(""); }
	| '(' NUMBER ')'               { $$ = CpStr("(%d)",$2); }
	| '(' NUMBER ',' NUMBER ')'    { $$ = CpStr("(%d,%d)",$2,$4); }
	;

array_indexes
	: fgl_expression
	| fgl_expression ',' fgl_expression
	| fgl_expression ',' fgl_expression ',' fgl_expression
	;

/* ======================== FUNCTIONS */

function_list
	: function_list        function_definition
	| function_definition
	/* ??? Se isto comecar a estourar pode ser daqui */
	|  /* Sem funcoes  - Isto da tres conflitos */
	;

function_definition
	: main
	| function
	| report
	;

main
	  : MAIN                    { StInsertLineFunction(lineno+1,FUNCTION_TYPE); InLimbo = 0;}
	  op_local_variables fgl_statement_list   {StInsertFunction(strdup("MAIN"),lineno+1,(NAME_LIST *)0);}
	  END_TOK MAIN                         { InLimbo = 1; }
	  ;

/* Ver como sao os posicionais com execucao parcial de funcoes */
function
	: FUNCTION_TOK { StInsertLineFunction(lineno+1,FUNCTION_TYPE); InLimbo = 0;}
	  function_def
	;

function_def
	: function_name '(' op_argument_list ')' 
	    op_local_variables 
		  fgl_statement_list
	  END_TOK FUNCTION_TOK      { StInsertFunction($1,lineno+1,$3);InLimbo=1; }
	| function_name '(' op_argument_list ')'   /* Funcoes vazias */
	     op_local_variables 
	  END_TOK FUNCTION_TOK      { StInsertFunction($1,lineno+1,$3);InLimbo=1; }
	;

function_name
  : IDENTIFIER  { $$ = $1; }
	| MENU { $$ = "menu"; }
  ;

op_argument_list
	:                          {$$ = (NAME_LIST *)0;}
	| op_argument_list ',' 
		  IDENTIFIER            {InsertNameList(&$$,$1,$3,lineno+1);}
  | IDENTIFIER              {InsertNameList(&$$,(NAME_LIST *)0,$1,lineno+1);}
	;

op_local_variables
	:
  | op_define_list
	;

/*  ====================== 4gl STATEMENTS               */
op_fgl_statement_list
	:
	| fgl_statement_list
	;

fgl_statement_list
  : fgl_statement_list fgl_statement op_semicolon { FunctionStatementCount++; }
	| fgl_statement op_semicolon                    { FunctionStatementCount++; }
	;

fgl_statement
	: flow_control
	| storage_manipulation
	| screen_interaction  
	| sql_statement
	| compiler_directives 
	| input_action      /* Como estamos a fazer um xref nao e preciso validar*/
	| construct_action  /* Como estamos a fazer um xref nao e preciso validar*/
	| display_action    /* Como estamos a fazer um xref nao e preciso validar*/
	| report_statement
	| PUT cursor_name FROM fgl_expression
		                       { StInsertCursorUsage($2,lineno+1,CURSOR_PUT);}
	| FLUSH cursor_name 
		                       { StInsertCursorUsage($2,lineno+1,CURSOR_FLUSH);}
	| unload
	| load
	;

unload
	: UNLOAD TO unload_target op_delimiter query_specification
	   {  if ( $3[0] != '\"' ) StInsertVariableUsage($3,lineno+1,READ_VAR);  }
	/*   Esta regra esta a dar erro
	| UNLOAD TO unload_target op_delimiter named_value
	   {  if ( $3[0] != "\"" ) StInsertVariableUsage($3,lineno+1,READ_VAR);
			StInsertVariableUsage($5,lineno+1,READ_VAR);                       }
			*/
	;

unload_target
	: named_value                                         { strcpy($$,$1);   }
	| STRING                                              { strcpy($$,$1);   }
	;

op_delimiter
	:
	| DELIMITER STRING
	;

load
	: LOAD FROM STRING op_delimiter 
		  INSERT INTO table_name op_insert_column_list
		                         { StInsertTable($7);
	                              StIncrementTable(); }
	| LOAD FROM named_value op_delimiter 
		  INSERT INTO table_name op_insert_column_list
	                            { StInsertVariableUsage($3,lineno+1,READ_VAR); 
		                           StInsertTable($7);
	                              StIncrementTable(); }
	;

/*  ============================ Control structures     */
flow_control
	: call
	| case
	| database
	| exit_program
	| FINISH REPORT IDENTIFIER
	                             { StInsertFunctionCall($3,lineno+1);
										    StUpdFCUsage("FINISH REPORT"); }
	| for
	| FOREACH cursor_name fgl_statement_list END_TOK FOREACH
		                    { StInsertCursorUsage($2,lineno+1,CURSOR_FETCH);}
	| FOREACH cursor_name END_TOK FOREACH               /* ???? Futuro Lixo */
		                    { StInsertCursorUsage($2,lineno+1,CURSOR_FETCH);}
	| FOREACH cursor_name op_st_using INTO named_value_list fgl_statement_list 
	  END_TOK FOREACH
		                    { StInsertVariableListUsage($5,ASSIGNMENT); 
		                      StInsertCursorUsage($2,lineno+1,CURSOR_FETCH);}
	                                                    /* ???? Futuro Lixo */
	| FOREACH cursor_name op_st_using INTO named_value_list END_TOK FOREACH 
		                    { StInsertVariableListUsage($5,ASSIGNMENT); 
		                      StInsertCursorUsage($2,lineno+1,CURSOR_FETCH);}
	| goto
	| if
	| LABEL IDENTIFIER ':'
	| OUTPUT TO REPORT IDENTIFIER '(' op_call_parameters ')'
	                             { StInsertFunctionCall($4,lineno+1);
										    StUpdFCUsage("OUTPUT TO REPORT"); }
	| RETURN fgl_return_list
	| run
	| start_report
	| while 
	| continues_and_exits
	| print_statement                           /* Isto nao eh flow control */
	| menu_action
	;

op_st_using
	:
	| USING named_value_list
	;

op_semicolon 
	: 
	| ';'

database
	: DATABASE database_name op_exclusive
	;

/* ??? Afectacoes so para o bison funcionar */
database_name
	: IDENTIFIER '@' IDENTIFIER   { char *x; x = $1;x=$3; }
	| IDENTIFIER                  { char *x; x = $1; }
	;

op_exclusive
	:
	| EXCLUSIVE
	;

exit_program
	: EXIT PROGRAM
	| EXIT PROGRAM fgl_expression
	| EXIT PROGRAM '(' fgl_expression ')'
	;

/* Como e para fazer um X ref nao e preciso ver se esta a fazer exit while
	fora de um while
	Se calhar podia-se fazer uma exit_list e continue_list
 */
continues_and_exits
	: EXIT WHILE
	| CONTINUE WHILE
	| EXIT FOR
	| EXIT CASE
	| CONTINUE FOR
	| EXIT FOREACH
	| CONTINUE FOREACH
	;

fgl_return_list   
	:
	| fgl_return_list ',' fgl_expression
	| fgl_expression
	;

call
	: CALL function_call RETURNING returning_list 
														{ StUpdFCUsage("CALL RETURNING"); }
	| CALL function_call                   { StUpdFCUsage("CALL"); }
	;

returning_list
	: returning_list ',' named_value
	                           { StInsertVariableUsage($3,lineno+1,READ_VAR);} 
	| named_value
	                           { StInsertVariableUsage($1,lineno+1,READ_VAR);} 
	;

  /* ??? Esta regra pode dar conflitos por causa da concatenacao de strings */
op_call_parameters
	:                                         { $$=""; }
	| op_call_parameters ',' fgl_expression   { $$=CpStr("%s,%s",$1,""); }
	| op_call_parameters THRU fgl_expression  { $$=CpStr("%s THRU %s",$1,""); }
	| fgl_expression                          { $$=CpStr("%s",""); }
	;

case                                            /* Case single criterion */
	: CASE fgl_expression when_list op_otherwise END_TOK CASE
															  /* Case Multiple criteria */
	| CASE when_list op_otherwise END_TOK CASE
	;

/* Falta o tratamento do exit case */
when_list
	: when_list when
	| when
	;

when
	: WHEN fgl_expression fgl_statement_list
	     /* ??? Isto acaba quando a fgl_expression for opcional */
	| WHEN fgl_expression 
	;

op_otherwise
	:
	| OTHERWISE fgl_statement_list
	     /* ??? Isto acaba quando a fgl_expression for opcional */
	| OTHERWISE     
	;

/* This one have a shift reduce conflict */
if
	: IF fgl_expression THEN fgl_statement_list else END_TOK IF
	     /* ??? Isto acaba quando a fgl_expression for opcional */
	| IF fgl_expression THEN else END_TOK IF
	;

else
	: ELSE fgl_statement_list
	     /* ??? Isto acaba quando a fgl_expression for opcional */
	| ELSE 
	| /* Sem else */
	;

while
	: WHILE fgl_expression fgl_statement_list END_TOK WHILE
	| WHILE fgl_expression END_TOK WHILE
	;

/* Se calhar tambem devia ter expressoes no start */
for
	: FOR IDENTIFIER '=' fgl_expression 
	  TO fgl_expression 
	     op_step fgl_statement_list
	  END_TOK FOR
	     /* ??? Isto acaba quando a fgl_expression for opcional */
	| FOR IDENTIFIER '=' fgl_expression TO fgl_expression op_step END_TOK FOR
	;

/* ??? Tem de se aceitar expressoes no STEP */
op_step
	:
	| STEP NUMBER
	| STEP '-' NUMBER
	| STEP IDENTIFIER         { StInsertVariableUsage($2,lineno+1,READ_VAR); }
	;

goto
	: GO TO ':' IDENTIFIER
	| GO TO IDENTIFIER
	| GOTO ':' IDENTIFIER
	| GOTO IDENTIFIER
	;

start_report
	: START REPORT IDENTIFIER op_to_report
	                             { StInsertFunctionCall($3,lineno+1); 
										    StUpdFCUsage("START TO REPORT"); }
	;

op_to_report
	:
	| TO STRING
	| TO named_value          { StInsertVariableUsage($2,lineno+1,READ_VAR); }
	| TO PRINTER
	| TO PIPE STRING
	| TO PIPE named_value     { StInsertVariableUsage($3,lineno+1,READ_VAR); }
	;
 
/* O opcional clipped esta aqui um bocado estranho */
run 
	: RUN STRING                 op_returning_or_waiting
	| RUN '(' STRING ')'         op_returning_or_waiting
	| RUN '(' named_value ')'    op_returning_or_waiting
	                           { StInsertVariableUsage($3,lineno+1,READ_VAR); }
	| RUN named_value op_clipped op_returning_or_waiting
	                           { StInsertVariableUsage($2,lineno+1,READ_VAR); }
	;

op_returning_or_waiting
	:
	| RETURNING named_value    { StInsertVariableUsage($2,lineno+1,READ_VAR); }
	| WITHOUT WAITING
	;

/*  ============================ Storage Manipulation   */
storage_manipulation
	: let
	| initialize
	| FREE named_value 
	| locate
	;
	/* ??? Falta 
		| validate
   */

let 
	: LET named_value '=' fgl_expression 
	   { StInsertVariableUsage($2,lineno+1,ASSIGNMENT);} 
	| LET named_value '.' '*' '=' named_value '.' '*'
	   { StInsertVariableUsage($2,lineno+1,ASSIGNMENT);
	     StInsertVariableUsage($6,lineno+1,READ_VAR);
		} 
	;

initialize
	: INITIALIZE named_value_list TO NULL_TOK
		{ StInsertVariableListUsage($2,ASSIGNMENT); }
	;

	/* Falta o initialize like */

locate 
	: LOCATE named_value_list IN MEMORY {StInsertVariableListUsage($2,READ_VAR);}
	| LOCATE named_value_list IN FILE_TOK 
													{StInsertVariableListUsage($2,READ_VAR);}
	| LOCATE named_value_list IN FILE_TOK STRING
		                                {StInsertVariableListUsage($2,READ_VAR);}
	| LOCATE named_value_list IN FILE_TOK IDENTIFIER
		                                { StInsertVariableListUsage($2,READ_VAR);
		                                  StInsertVariableListUsage($5,READ_VAR);}
	;
	/* Depois se ve */
	/*| LOCATE named_value_list IN FILE named_value */

/*  ============================ Fgl expressions (Very simplified) */

/* Fgl expression nao e usada no SQL e como tal pode-se usar 
 * Para insercao de utilizacao de variaveis */
 /* ??? Afectacoes sao para o bison funcionar */
/* Restruturação de expressões 4gl
/* TODO - Notação cientifica com Enum em number */
/* 
fgl_expression
	: time_expression  
	  { char *x=$1; }
	| character_expression  
	  { char *x=$1; }
	| number_expression  
	  { char *x=$1; }
	| integer_expression  
	  { char *x=$1; }
	| fgl_boolean_expression  
	  { char *x=$1; }
	| NOT fgl_expression  
	|'(' fgl_expression ')'  
	;

character_expression
	: STRING        op_subscript op_character_format_list 
	  { $$=""; }
	| function_call op_subscript op_character_format_list 
	  { $$=""; }
	| named_value   op_subscript op_character_format_list 
	  { $$=""; }
	;

op_subscript
	:
	  { $$=""; }
	| '[' integer_expression ']'
	  { $$=""; }
	| '[' integer_expression ',' integer_expression ']'
	  { $$=""; }
	;

op_character_format_list
	:
	  { $$=""; }
	| op_character_format_list character_format
	  { $$=""; }
	;

character_format
	: clipped
	  { $$=""; }
	| using
	  { $$=""; }
  ;

number_expression
	: simple_number_expression
	  { $$=""; }
	| simple_number_expression mod_exp_operator
	  { $$=""; }
	| simple_number_expression number_operator number_expression
	  { $$=""; }
	;

simple_number_expression
	: op_signal literal_number
	  { $$=""; }
	| op_signal named_value
	  { $$=""; }
	| op_signal function_call
	  { $$=""; }
	| op_signal fgl_boolean_expression
	  { $$=""; }
	| op_signal fgl_boolean_expression
	  { $$=""; }
	;

number_operator
	: '+'
	  { $$=""; }
	| '-'
	  { $$=""; }
	| '*'
	  { $$=""; }
	| '/'
	  { $$=""; }
	;

mod_exp_operator
	: MOD
	  { $$=""; }
	| EXPO
	  { $$=""; }
	;

literal_number
	: op_signal NUMBER op_decimals 
	  { $$=""; }
	| op_signal '.' NUMBER
	  { $$=""; }
	;

op_decimals
	:
	  { $$=""; }
	| '.' NUMBER
	  { $$=""; }
	;


fgl_boolean_expression
	: fgl_simple_boolean_expression 
	  { $$=""; }
	| fgl_simple_boolean_expression AND fgl_boolean_expression 
	  { $$=""; }
	| fgl_simple_boolean_expression OR  fgl_boolean_expression 
	  { $$=""; }
	;

fgl_simple_boolean_expression
	: op_not_list fgl_expression
	  { $$=""; }
	| op_not_list boolean_comparison
	  { $$=""; }
	| op_not_list function_call
	  { $$=""; }
	| op_not_list TRUE_TOK
	  { $$=""; }
	| op_not_list FALSE_TOK
	  { $$=""; }
	;
	
op_not_list
	:
	  { $$=""; }
  | not_list
	  { $$=""; }
	;

not_list
	: NOT 
	  { $$=""; }
	| NOT not_list
	  { $$=""; }
	;

op_not
	:
	  { $$=""; }
	| NOT
	  { $$=""; }
	;

boolean_comparison
	: string_comparison
	  { $$=""; }
	| set_membership_test
	  { $$=""; }
	| null_test
	  { $$=""; }
	| relational_comparison
	  { $$=""; }
  ;

string_comparison
	: character_expression op_not MATCHES STRING op_escape
	  { $$=""; }
	;

set_membership_test
	: fgl_expression op_not IN '(' fgl_expression_list ')'
	  { $$=""; }
	;

fgl_expression_list
	: fgl_expression
	  { $$=""; }
	| fgl_expression ',' fgl_expression_list
	  { $$=""; }
	;

null_test
	: fgl_expression IS op_not NULL_TOK
	  { $$=""; }
  ;

relational_comparison
	: fgl_expression '=' fgl_expression
	  { $$=""; }
	| fgl_expression '<' fgl_expression
	  { $$=""; }
	| fgl_expression '>' fgl_expression
	  { $$=""; }
	| fgl_expression LESS_OR_EQUAL fgl_expression
	  { $$=""; }
	| fgl_expression GREATER_OR_EQUAL fgl_expression
	  { $$=""; }
	| fgl_expression NOT_EQUAL fgl_expression
	  { $$=""; }
	;

integer_expression
	: pure_integers
	  { $$=""; }
	| date_value '-' date_value
	  { $$=""; }
	;

pure_integers
	: pure_integer
	  { $$=""; }
	| pure_integer integer_operator pure_integers
	  { $$=""; }
	;

pure_integer
	: op_signal literal_integer 
	  { $$=""; }
	| op_signal function_call
	  { $$=""; }
	| op_signal named_value
	  { $$=""; }
	| op_signal fgl_boolean_expression
	  { $$=""; }
	;


literal_integer
	: op_signal NUMBER
	  { $$=""; }
	;

  */
/* FIQUEI AQUI */


/* Expressões antigas */
fgl_expression
	: fgl_expression op_spaces fgl_operator_list fgl_operand  { char *x; x=$4; }
	| fgl_expression op_spaces fgl_operator_list fgl_expression 
	| fgl_expression SPACES
	| fgl_operand  { char *x; x=$1; }
	| NOT fgl_expression
	| op_signal '(' fgl_expression ')' 
	| time_expression { char *x; x=$1; }
	;

op_spaces
	:
	| SPACES
	;

/* Quando meti esta lista deu mais alguns 100 conflitos reduce/reduce */
fgl_operator_list
	: fgl_operator_list fgl_operator
	| fgl_operator
	;

fgl_operator
	: '+'
	| '-'
	| '*'
	| '/'
	| MOD
	| EXPO                                                 /* ** Operator */
	| AND
	| OR 
	| '='
	| '<'
	| '>'
	| LESS_OR_EQUAL
	| GREATER_OR_EQUAL
  | NOT_EQUAL
	| IS 
	| IS NOT 
	| MATCHES
	| NOT MATCHES
	| ','
	;

/*
 * Tem tambem operandos dos reports
 * Devia devolver pelo $$: 
 *    - Tipo: String, Constante(literal), Funcao, NomeVariavel (tabela, etc)
 *    - Nome
 * ATENCAO : Apenas devolve o nome se este for named_value, caso contrario
 *           devolve NULL
 */
fgl_operand
	: fgl_basic_operand op_fgl_operand_format_list
		{  copystr($$,$1); }
	;

op_fgl_operand_format_list
	:
  | op_fgl_operand_format_list fgl_operand_format
  | fgl_operand_format
	;

fgl_operand_format
	: USING STRING 
	| CLIPPED 
	| wordwrap
	| units
	;

/*
 * ??? Como se vai detectar a diferenca entre nome de tabela e 
 *     estrutura ou coluna e variavel ???
 *  Para ja tem de passar a devolver qualquer coisa pelo $$
 * O problema eh que o named value pode ser um nome de tabela ou coluna
 */
fgl_basic_operand
	: literal              { strcpy($$,$1); }
	| STRING               { strcpy($$,$1); }
	| function_call        { strcpy($$,$1);
									 StUpdFCUsage("EXPRESSION"); }
	| named_value          {  strcpy($$,$1);
			                    StInsertVariableUsage($1,lineno+1,READ_VAR); }
	| '-' named_value          {  strcpy($$,$2);
			                    StInsertVariableUsage($2,lineno+1,READ_VAR); }
	| '+' named_value          {  strcpy($$,$2);
			                    StInsertVariableUsage($2,lineno+1,READ_VAR); }
	| ASCII named_value    { $$[0]='\0'; }
	| ASCII '(' NUMBER ')' { $$[0]='\0'; }
	| ASCII '(' named_value ')' { $$[0]='\0'; }
	| ASCII NUMBER         { $$[0]='\0'; }
	| PAGENO               { $$[0]='\0'; }
	                                  /* Isto devia ser so para print */
	| GROUP function_call  { $$[0]='\0'; }
	| COLUMN fgl_expression   { $$[0]='\0';} /* 
	                         StInsertVariableUsage($2,lineno+1,READ_VAR); }*/
		/* ??? Faltam formatacoes de datetimes e intervals */
	| current              { $$[0]='\0'; }
	| TIME                 { $$[0]='\0'; }
	| TRUE_TOK             { $$[0]='\0'; }
	| FALSE_TOK            { $$[0]='\0'; }
	/* ??? O number tem de ser named_value ou NUMBER */
	/*
	| NUMBER SPACES        { $$[0]='\0'; }
	*/
	;

	

wordwrap
	: WORDWRAP RIGHT MARGIN NUMBER
	| WORDWRAP RIGHT MARGIN IDENTIFIER
	| WORDWRAP 
	;

op_signal
	:
	| '+'
	| '-'

literal
	: number op_format_qualifier { strcpy($$,$1); }
	| '+' number op_format_qualifier { strcpy($$,$2); }
	| '-' number op_format_qualifier { strcpy($$,$2); }
	/* ???  Nao funciona nao sei porque 
	: op_signal number op_format_qualifier { strcpy($$,$2); }
	*/

number
	: NUMBER              { sprintf($$,"%d",$1); }
	| NUMBER '.' NUMBER   { sprintf($$,"%d.%d",$1,$3); }
	| '.' NUMBER          { sprintf($$,"0.%d",$2); }
	;

/* Para os UNITS, using, etc */
op_format_qualifier
	:
	| units
	;

/*
 * Tem de se poder inserir uma lista no $$ que ira conter a lista de
 * variaveis para que estas sejam inseridas quando named_value_list
 * e utilizado.
 * Provavelmente este nome poderia passar para variable_list
 */
named_value_list
	: named_value_list ',' named_value 
		{ InsertNameList(&$$,$1,$3,lineno+1);    }
	| named_value THRU named_value     
		{ InsertNameList(&$$,(NAME_LIST *)0,$1,lineno+1); }
	| named_value THROUGH named_value  
		{ InsertNameList(&$$,(NAME_LIST *)0,$1,lineno+1); }
	| named_value                      
		{ InsertNameList(&$$,(NAME_LIST *)0,$1,lineno+1); }
	;

                         /* Variavel completa (ex:array de record de array) */
named_value
	: named_value '.' var_name
	  { sprintf($$,"%s.%s",$1,$3); }
	| IDENTIFIER ':' named_value '.' var_name
	  { sprintf($$,"%s.%s",$3,$5); }
	| var_name  /* Aqui tem de ser inserida a utilizacao de variavel */
	  { strcpy($$,$1); }
	| '@' var_name  /* Aqui tem de ser inserida a utilizacao de variavel */
	  { strcpy($$,$2); }
					/* O unico nome que nos interessa e o primeiro       */
	;


/* Devia-se arranjar um esquema de o lexxer poder tratar da aceitacao 
	dos nomes a partir do contexto 
 */
var_name 
	: IDENTIFIER complete_array_usage             { strcpy($$,$1); }
	/* Cada cena destas sao dois shift/reduce */
	                       /* Existem variaveis com este nome */
	/*| ACCEPT                                     { strcpy($$,"ACCEPT");}*/
	| AUDIT         { strcpy($$,"AUDIT");} 
	| CHAR          { strcpy($$,"CHARACTER");} 
	| CONTROL       { strcpy($$,"CONTROL");}
	| CONSTRUCT     { strcpy($$,"CONSTRUCT");}
	| COUNT                                      { strcpy($$,"COUNT");}
	| CURRENT       { strcpy($$,"CURRENT");}
	| DATE                                       { strcpy($$,"DATE");}
	| DEC           { strcpy($$,"DECIMAL");}
	| DESC  complete_array_usage        { strcpy($$,"DESC");}
	| DIM           { strcpy($$,"DIM");}
	| EXISTS        { strcpy($$,"EXISTS");}
	| FORM    complete_array_usage { strcpy($$,"FORM");}
	| FRACTION      { strcpy($$,"FRACTION");}
	| FIELD         { strcpy($$,"FIELD");}
	| FILE_TOK                                   { strcpy($$,"FILE");}
	| FINISH        { strcpy($$,"FINISH");}
	| FREE   complete_array_usage                { strcpy($$,"FREE");}
	| FROM          { strcpy($$,"FROM");}
	| GROUP                                      { strcpy($$,"GROUP");}
	| HOLD          { strcpy($$,"HOLD");}
	| LAST          { strcpy($$,"LAST");}
	| LENGTH        { strcpy($$,"LENGTH");}
	| LINE           complete_array_usage        { strcpy($$,"LINE");}
	| LINES         { strcpy($$,"LINES");}
	| MAX           { strcpy($$,"MAX");}
	| MESSAGE                                    { strcpy($$,"MESSAGE");}
	| MONEY                                      { strcpy($$,"MONEY");}
	| NAME    complete_array_usage               { strcpy($$,"NAME");}
	| NAME          { strcpy($$,"NAME");}
	| NOT           { strcpy($$,"NOT");}
	| NULL_TOK      { strcpy($$,"NULL");}
	| OPTION                                     { strcpy($$,"OPTION");}
	| ORDER                                      { strcpy($$,"ORDER");}
	| PAGE          { strcpy($$,"PAGE");}
	| PRINTER                                    { strcpy($$,"PRINTER");}
	| REMOVE        { strcpy($$,"REMOVE");}
	| ROW           { strcpy($$,"ROW");}
	/* Isto estraga os sub-query(s) e portanto optei por retirar */
	/*| SELECT                                     { strcpy($$,"SELECT");} */
	| SERIAL        { strcpy($$,"SERIAL");}
	| SHARE   complete_array_usage               { strcpy($$,"SHARE");}
	| TABLE         { strcpy($$,"TABLE");}
	| TRAILER       { strcpy($$,"TRAILER");}
	| TRANSACTION   { strcpy($$,"TRANSACTION");}
	| TEXT          { strcpy($$,"TEXT");}
	| TOTAL         { strcpy($$,"TOTAL");}
	| UNITS         { strcpy($$,"UNITS");}
	| USER          { strcpy($$,"USER");}
	| WAIT          { strcpy($$,"WAIT");}
	| WHENEVER      { strcpy($$,"WHENEVER");}
	| WORK          { strcpy($$,"WORK");}
	| '*'           { strcpy($$,"*");}
	/* | PRINT  Tem de se tirar por causa dos PRINT \n PRINT "jhjh" */
	;

complete_array_usage
	:
   | complete_array_usage '[' array_indexes ']'
   | '[' array_indexes ']'
	;

integer_operator
	: '+'
	| '-'
	| '*'
	| '/'
	| MOD
	| EXPO  /* ** */
	;

op_clipped
	:
	| CLIPPED
	;

/* ??? Isto esta repetido com regra using */
op_using 
	:
	| using
	;

/* Isto tem de mudar de nome */
using 
	: USING STRING
	| USING STRING CLIPPED
  ;

units 
  : UNITS unit_identifier
	;

unit_identifier
	: IDENTIFIER { char *x=$1;}
	| SECOND
	| DAY
	| MINUTE
	| HOUR
	;


time_expression
	: interval_value
	| datetime_value
	| date_value
	;

date_value
  : STRING op_using { char *x; x = $1; }
	| function_call op_using  { char *x; x= $1; }
	| named_value op_using { char *x; x = $1; }
	/* Só para resolver o today */
	| IDENTIFIER op_using { char *x; x = $1; }
	/* | TODAY op_using Ficou em função */
	
datetime_value
	: STRING { char *x; x = $1; }
	| datetime_literal 
	| function_call 
	| named_value { char *x; x = $1; }
	| current op_datetime_qualifier { char *x; x = $1; }
	| EXTEND '(' {printf("% % % % \n"); }fgl_expression  ',' dtqualifier TO dtqualifier ')' { $$=""; }
	| EXTEND '(' {printf("##%\n"); }fgl_expression ')' { $$=""; }
	/*
	| EXTEND '(' {printf("&&%\n"); }date_value ')' { $$=""; }
	*/
	;

datetime_literal
	: DATETIME '(' numeric_date_and_time ')' dtqualifier TO dtqualifier
	  { $$=""; }
	;

numeric_date_and_time
	: NUMBER { int x; x=$1; }
	| NUMBER '-' NUMBER { int x; x = $1; }
	| NUMBER '-' NUMBER '-' NUMBER 
	  {int x ; x = $1; }
	| NUMBER '-' NUMBER '-' NUMBER NUMBER
	  {int x ; x = $1; }
	| NUMBER '-' NUMBER '-' NUMBER NUMBER ':' NUMBER
	  {int x ; x = $1; }
	| NUMBER '-' NUMBER '-' NUMBER NUMBER ':' NUMBER ':' NUMBER
	  {int x ; x = $1; }
	| NUMBER '-' NUMBER '-' NUMBER NUMBER ':' NUMBER ':' NUMBER '.' NUMBER
	  {int x ; x = $1; }
	;

op_datetime_qualifier
	:  { $$=""; }
	| dtqualifier TO dtqualifier{ $$=""; }
	;

interval_value
	: op_interval_sign STRING 
	  {$$ = "";}
	| interval_literal 
	  {$$ = "";}
	| function_call
	  {$$ = "";}
	| named_value
	  {$$ = "";}
	/* Devia ser integer expression */
	| fgl_expression UNITS unit_identifier
	  {$$ = "";}
	;
	

op_interval_sign
	:{ $$=""; }
	| '+'{ $$=""; }
	| '-'{ $$=""; }
	;

interval_literal
	: INTERVAL '(' numeric_time_interval ')' dtqualifier TO dtqualifier
	;

/* ??? Esta regra est+a errada */
numeric_time_interval
	: op_interval_sign NUMBER { $$=""; }
	| op_interval_sign op_num NUMBER{ $$=""; }
	| op_interval_sign op_num op_num ':' NUMBER { $$=""; }
	| op_interval_sign op_num op_num ':' op_num ':' NUMBER{ $$=""; }
	| op_interval_sign op_num op_num ':' op_num ':' op_num '.' NUMBER{ $$=""; }
	| op_interval_sign NUMBER '-' NUMBER{ $$=""; }
	;

op_num
	: { $$=""; }
	| NUMBER { $$="" ; }
	;



function_call
	: IDENTIFIER '(' op_call_parameters ')'
	                             { StInsertFunctionCall($1,lineno+1); 
	                               $$=CpStr("%s(%s)",$1,$3);           }
	| MENU '(' op_call_parameters ')'
	                             { StInsertFunctionCall("menu",lineno+1); 
	                               $$=CpStr("%s(%s)","menu",$3);           }
	| LENGTH '(' fgl_operand ')' { $$=CpStr("LENGTH(%s)",$3); }
	| DATE '(' fgl_operand ')'   { $$=CpStr("DATE(%s)",$3); }
	/*| EXTEND '(' fgl_expression ',' dtqualifier TO dtqualifier ')'    */
	                             { $$=CpStr("EXTEND()"); }
	| set_function_specification
	;


/*  ============================ Reports                */
report
	: REPORT               { StInsertLineFunction(lineno+1,REPORT_TYPE); InLimbo = 0; }
	report_def    
	
report_def:
	IDENTIFIER '(' op_argument_list ')' 
		  op_local_variables
		  output_section
		  order_by_section
		  FORMAT format_section
	  END_TOK REPORT  {StInsertFunction($1,lineno+1,(NAME_LIST *)0);}
	  ;

output_section
	:  OUTPUT output_command_list
	| 
	;

output_command_list
	: output_command_list output_command
	| output_command
	;

output_command
	: REPORT TO STRING
	| REPORT TO PRINTER
	| REPORT TO PIPE STRING
	| REPORT TO PIPE IDENTIFIER
	| LEFT MARGIN NUMBER
	| TOP MARGIN NUMBER
	| BOTTOM MARGIN NUMBER
	| RIGHT MARGIN NUMBER
	| PAGE LENGTH NUMBER
	| TOP OF PAGE STRING
	;

order_by_section
	: ORDER EXTERNAL BY named_value_list    { CleanNameList($4); }
	| ORDER BY named_value_list             { CleanNameList($3); }
	|
	;

format_section
	: EVERY ROW
	| report_format_list
	;

/* Nao liga a repeticoes */
report_format_list
	: report_format_list report_format_block
	| report_format_block
	;

report_format_block
	: FIRST PAGE HEADER fgl_statement_list
	| PAGE HEADER fgl_statement_list
	| ON EVERY ROW fgl_statement_list
	| BEFORE GROUP OF named_value fgl_statement_list
	| AFTER GROUP OF named_value fgl_statement_list
	| PAGE TRAILER fgl_statement_list
	| ON LAST ROW fgl_statement_list
	;

report_statement
	: NEED NUMBER LINES
	| NEED NUMBER LINE
	| NEED named_value LINES  /* Isto pode dar um grande granel */
	     { StInsertVariableUsage($2,lineno+1,READ_VAR); }
	| PAUSE STRING
	/*| print_statement */
	| SKIP TO TOP OF PAGE
	| SKIP NUMBER LINE    /* Passar para lexxer o reconhecimento de LINE */
	| SKIP NUMBER LINES
	;

/* ??? Faltam alguns casos : agregados, FILE, etc*/
print_statement
	: PRINT fgl_expression
	| PRINT fgl_expression ';'
	| PRINT 
	| PRINT ';'
	| PRINT FILE_TOK var_name



/*  ============================ Screen Interaction     */
screen_interaction  
	: clear
	| CLOSE FORM IDENTIFIER
	| CLOSE WINDOW IDENTIFIER
	| construct
	| CURRENT WINDOW IS IDENTIFIER
	| CURRENT WINDOW IS SCREEN
	| display
	| display_array
	| DISPLAY FORM IDENTIFIER attribute_clause
	| ERROR string_exp  attribute_clause
	| input
	| input_array 
	| menu
	| MESSAGE string_exp  attribute_clause
	| OPEN FORM IDENTIFIER FROM form_origin
	| open_window
	| options
	| prompt
   /* O Scroll nao funciona */
   | SCROLL field_clause_list scroll_dir 
   | SCROLL field_clause_list scroll_dir BY NUMBER
	| SLEEP fgl_expression
	/* VARIABLE USAGE */

form_origin
	: STRING { char *x; x=$1; }
	| var_name { char *x; x=$1; }
	;

clear
	: CLEAR FORM
	| CLEAR WINDOW IDENTIFIER
	| CLEAR WINDOW SCREEN
	| CLEAR SCREEN
	| CLEAR field_clause_list

construct
	: CONSTRUCT 
		construct_variable_clause 
		attribute_clause 
		help_clause
		construct_management

construct_variable_clause
	/* : IDENTIFIER ON column_list FROM  field_clause_list  */
	: IDENTIFIER ON named_value_list FROM  field_clause_list 
		  { CleanNameList($3);
	       StInsertVariableUsage($1,lineno+1,ASSIGNMENT);}
	| BY NAME IDENTIFIER ON column_list 
	     {StInsertVariableUsage($3,lineno+1,ASSIGNMENT);}


help_clause
	:
	| HELP NUMBER

attribute_clause
	:
	| ATTRIBUTE '(' attribute_list ')'

attribute_list
	: attribute_list ',' attribute
	| attribute

	/* As cores nao se podem repetir */
	/* Os atributos poderiam ser guardados como identificadores */
	/* Devia haver um token especial para attributos atomicos */

attribute
	: BLACK
	| BLUE
	| CYAN
	| GREEN
	| MAGENTA
	| RED
	| WHITE
	| YELLOW
	| BOLD
	| DIM
	| INVISIBLE
	| NORMAL
	/* A Partir daqui ja se pode repetir */
	| REVERSE
	| BLINK
	| UNDERLINE
	| COMMENT LINE reserved_line_position
	| BORDER
	| FORM LINE    reserved_line_position
	| MENU LINE    reserved_line_position
	| MESSAGE LINE reserved_line_position
	| PROMPT LINE  reserved_line_position

/* ??? Afectacoes sao para o bison funcionar */
reserved_line_position
	: FIRST
	| FIRST '+' NUMBER { int x=$3; }
	| NUMBER { int x=$1;}
	| LAST
	| LAST '-' NUMBER { int x=$3;}

construct_management
	: construct_management_block_list END_TOK CONSTRUCT
	|  /*Sem after(s) */

construct_management_block_list
	: construct_management_block_list construct_management_block
	| construct_management_block

/* Isto da conflitos - Tem 4 shift reduce que podem ter a ver com field clause*/
/* Para poupar regras juntou-se o construct com input array */
construct_management_block
	: BEFORE FIELD     field_clause_list fgl_statement_list 
	| BEFORE CONSTRUCT fgl_statement_list
	| AFTER FIELD      field_clause_list fgl_statement_list 
	| AFTER CONSTRUCT  fgl_statement_list 
	| on_key_input     fgl_statement_list 

construct_action
	: EXIT     CONSTRUCT
	| CONTINUE CONSTRUCT

/* First try of using state machine for identifiers */
/*
exp_field_clause_list
	: field_clause_list ',' field_clause
	| field_clause
*/

field_clause_list
	: field_clause_list ',' field_clause
	| field_clause

/* Esta parte tem de ser melhorada - Esta pouco legivel */
field_clause
	: left_field
	| left_field '.' right_field

/* Isto devia guardar as variaveis globais como utilizadas no indice de array */
left_field
	: field_name
	| field_name '[' fgl_expression ']'
	| FORMONLY

right_field
	: field_name
	| '*'
	| field_name THROUGH var_name '.' field_name
	| field_name THRU    var_name '.' field_name

/* Se calhar este problema resolve-se com uma maquina de estado no lexxer */
/* ??? Afectacoes so para o bison trabalhar */
field_name
	: IDENTIFIER { char *x=$1; }
	| CONSTRUCT    /* Palavras reservadas como nomes de campos */
	| CONTROL      /* Palavras reservadas como nomes de campos */
	| DATE        
	| DEC
	| DESC
	| END_TOK
	| FILE_TOK
	| FROM
	| GROUP
	| HOLD
	| LAST
	| LENGTH
	| LINES
	| MESSAGE
	| NAME
	| NOT     /* Ainda nao vi se da problemas */
	| OPTION
	| ORDER
	| PRINTER     
	| SERIAL
	| SHARE
	| TABLE
	| TEXT
	| TOTAL
	| UNITS
 	| SELECT    
 	| FINISH
	;

display
	: DISPLAY fgl_expression display_where_to attribute_clause
	| DISPLAY BY NAME named_value_list attribute_clause
		{ StInsertVariableListUsage($4,READ_VAR); }
	;

display_where_to
	:
	/*| AT coord ',' coord */
	| AT fgl_expression ',' fgl_expression 
	| TO field_clause_list 
	;


display_array
	: DISPLAY ARRAY named_value TO IDENTIFIER '.' '*' 
			attribute_clause on_key_list
	  END_TOK DISPLAY
	                         { StInsertVariableUsage($3,lineno+1,READ_VAR); }
	| DISPLAY ARRAY named_value TO IDENTIFIER '.' '*' 
			attribute_clause 
	                         { StInsertVariableUsage($3,lineno+1,READ_VAR); }
   ;

/* ??? Faltam os atributos especificos do input */
/* Se calhar deveria ter uma maquina de estados associada ao evento 
	(para atributos)
 */
input
	: INPUT 
		input_binding_clause 
		attribute_clause
		help_clause
		input_management

input_binding_clause
	:         named_value_list                  FROM field_clause_list
		                              { StInsertVariableListUsage($1,READ_VAR); }
	|         named_value_list WITHOUT DEFAULTS FROM field_clause_list
		                              { StInsertVariableListUsage($1,READ_VAR); }
	| BY NAME named_value_list       { StInsertVariableListUsage($3,READ_VAR); }
	| BY NAME named_value_list WITHOUT DEFAULTS 
		                              { StInsertVariableListUsage($3,READ_VAR); }

input_management
	: input_management_block_list END_TOK INPUT
	|  /*Sem after(s) */

input_management_block_list
	: input_management_block_list input_management_block
	| input_management_block

/* Isto da conflitos - Tem 4 shift reduce que podem ter a ver com field clause*/
/* Para poupar regras juntou-se o input com input array */
input_management_block
	: BEFORE FIELD field_clause_list fgl_statement_list 
	| BEFORE INPUT                   fgl_statement_list
	          /* Just for trying to use state machine */
	| AFTER FIELD  field_clause_list fgl_statement_list 
	| AFTER INPUT  fgl_statement_list 
	| on_key_input fgl_statement_list 
	/* So do input array */
	| BEFORE DELETE fgl_statement_list 
	| BEFORE INSERT fgl_statement_list 
	| AFTER ROW fgl_statement_list 
	| BEFORE ROW fgl_statement_list 

on_key_input
	: ON KEY '(' key_list ')' 

input_action
	: NEXT FIELD field_clause
	| NEXT FIELD NEXT
	| NEXT FIELD PREVIOUS
	| EXIT INPUT
	| CONTINUE INPUT
	;

/* Esta origina mais conflitos por causa das sub-clausulas */
input_array
	: INPUT ARRAY
		input_array_binding_clause 
		attribute_clause
		help_clause
		input_management
	;

input_array_binding_clause
	: IDENTIFIER FROM IDENTIFIER '.' '*'
	                           { StInsertVariableUsage($3,lineno+1,READ_VAR); }
	| IDENTIFIER WITHOUT DEFAULTS FROM IDENTIFIER '.' '*'
	                           { StInsertVariableUsage($5,lineno+1,READ_VAR); }
	;

menu
	: MENU string_or_var menu_control_list END_TOK MENU
	;

menu_control_list
   : menu_control_list menu_control
	| menu_control
	;

menu_control
	: BEFORE MENU fgl_statement_list
	| command_block op_fgl_statement_list
	;

/* Menu command block */
command_block
	: COMMAND menu_option_def help_clause
	;

/* Definição da opção / comando do menu */
menu_option_def
	: menu_key
	| menu_key menu_option_value
	| menu_key menu_option_value menu_option_value
	| menu_option_value
	| menu_option_value menu_option_value
	;

/* ??? Afectacoes sao para o bison funcionar */
menu_option_value
	: named_value  { char *x=$1; }
	   /* VARIABLE USAGE */
	| STRING { char *x=$1; }
	;

menu_key
	: KEY '(' key_list ')'
	/*| KEY '(' STRING ')' */
	;

menu_action
	: NEXT OPTION STRING
	| SHOW OPTION named_value
	   /* VARIABLE USAGE */
	| SHOW OPTION menu_option_list
	| HIDE OPTION menu_option_list
	   /* VARIABLE USAGE */
	| HIDE OPTION STRING
	| SHOW OPTION ALL
	| CONTINUE MENU
	| EXIT MENU
	;

menu_option_list
	: menu_option_list ',' menu_option
	| menu_option

/* As afectações são só para o byson funcionar */
menu_option
	: STRING            { char *x; x = $1; }
	| ALL
	| named_value       { char *x; x = $1; }
 
/* Nesta versao usa o mesmo para display array, display, Input, etc) */
op_on_key_list
	:
	| on_key_list
	;

on_key_list
	: on_key_list on_key
	| on_key
	;

on_key
	: ON KEY '(' key_list ')' fgl_statement_list
	;

display_action
	: EXIT DISPLAY
	;

open_window
	: OPEN WINDOW IDENTIFIER AT coord ',' coord 
			 WITH fgl_expression ROWS ',' fgl_expression COLUMNS attribute_clause
	| OPEN WINDOW IDENTIFIER AT coord ',' coord 
			 WITH FORM string_or_var attribute_clause
	   { StInsertVariableUsage($10,lineno+1,READ_VAR);} 
	;

/* ??? Afectacao so para desenrascar o funcionamento em bison */
coord
	: IDENTIFIER   
	   { StInsertVariableUsage($1,lineno+1,READ_VAR);} 
	| NUMBER     { int x=$1; }
	;

options
	: OPTIONS option_list
	;

option_list
	: option_list ',' option
	| option
	;

option
	: COMMENT LINE reserved_line_position
	| ERROR LINE reserved_line_position
	| FORM LINE reserved_line_position
	| MENU LINE reserved_line_position
	| MESSAGE LINE reserved_line_position
	| PROMPT LINE reserved_line_position
	/* Isto eh da accept key. Para descomentar */
	| key KEY key
	/*
	| ACCEPT LINE key
	*/
	| DELETE KEY key
	| INSERT KEY key
	| NEXT KEY key
	| PREVIOUS KEY key
	| HELP KEY key
	| HELP FILE_TOK STRING
	| HELP FILE_TOK IDENTIFIER   /* Devia ser variavel */
	| DISPLAY ATTRIBUTE '(' attribute_list ')'  /* Os options deviam ter uma */
	| INPUT ATTRIBUTE '(' attribute_list ')' 
	| INPUT WRAP
	| INPUT NO WRAP
	| FIELD ORDER UNCONSTRAINED
	| FIELD ORDER CONSTRAINED
	| SQL_TOK INTERRUPT ON
	| SQL_TOK INTERRUPT OFF
	;

prompt
	: PROMPT fgl_expression attribute_clause FOR IDENTIFIER help_clause
	  attribute_clause prompt_on_key_list
	   /* VARIABLE ASSIGNMENT */
	| PROMPT fgl_expression attribute_clause FOR CHAR IDENTIFIER help_clause
	  attribute_clause prompt_on_key_list
	   /* VARIABLE ASSIGNMENT */
	;

prompt_on_key_list
	:
	/*| ON KEY '(' key_list ')' fgl_statement_list END_TOK PROMPT*/
	| on_key_list END_TOK PROMPT
	;


key_list
	: key_list ',' key
	| key
	;

key
	/* Nova versao com tabela de teclas (para libertar um bocadinho o parser) */
	: IDENTIFIER              { if (!IsFglKey($1)) 
													{
													printf("Key %s\n",$1);
								          yyerror("Syntax error. Fgl Key expected"); }
													}
	| STRING  { char *x;   x = $1; }
	/*| ACCEPT  *//* O Accept ate podia ser retirado */
	| CONTROL '-' IDENTIFIER  { char strkey[10]; 
										 sprintf(strkey,"CONTROL-%s", $3);
										 if (!IsFglKey(strkey)) 
								          yyerror("Syntax error. Fgl Key expected"); }
	| DELETE
	| DOWN 
	| ESCAPE
	| HELP
	| INSERT
	| INTERRUPT
	| LEFT
	| NEXT
	| PREVIOUS
	| RETURN
	| RIGHT
	| TAB
	| UP
	;


/* ??? Afectacoes so para o bison funcionar */
string_exp
	: string_exp ',' string_or_var { char *x=$3; }
	| string_exp ',' COLUMN NUMBER { int x=$4; }
	| COLUMN NUMBER { int x=$2; }
	| string_or_var { char *x=$1; }
	;

string_or_var
	: STRING op_clipped        { strcpy($$,$1); }
	| fgl_operand { strcpy($$,$1);
	/* | fgl_operand op_clipped   { strcpy($$,$1); */

	/*| named_value op_clipped   { strcpy($$,$1); */
	;
	                             StInsertVariableUsage($1,lineno+1,READ_VAR); }

scroll_dir
	: DOWN
	| UP
	;

/*  ============================ SQL Statements         */

column_list
	: column_list ',' column
	| column
	;

/* ??? Afectacao so para desenrascar */
column
	: IDENTIFIER '.' IDENTIFIER { char *x=$1; }
	| IDENTIFIER { char *x=$1; }
	;

/*  ============================ SQL Statements FROM IIUG       */

/*****************************************************************************/



/*----------------------- <Update Statement: Searched> ----------------------*/

update_statement_search
	: UPDATE table_name
	  SET set_clause_list
	  op_where_clause                      { 
		StInsertTable($2); 
	   $$=CpStr("UPDATE %s SET %s %s\n",$2,$4,$5); }
	;


/*---------------------- <Update Statement: Positioned> ---------------------*/

update_statement_position:
	UPDATE table_name
	SET set_clause_list
	WHERE CURRENT OF cursor_name
		{ StInsertTable($2);   
		  StInsertCursorUsage($8,lineno+1,CURSOR_UPDATE);
	     $$=CpStr("UPDATE %s SET %s WHERE CURRENT OF %s\n",$2,$4,$8); }
	;

set_clause_list
	: set_clause_ansi_list                      { $$=CpStr($1);     }
	| set_clause_infx                           { $$=CpStr($1);     }

set_clause_ansi_list
	: set_clause_ansi                           { $$=CpStr($1);            }
	| set_clause_ansi_list ',' set_clause_ansi  { $$=CpStr("%s,%s",$1,$3); }
	;

set_clause_ansi
	: column_specification '=' value_expression { $$=CpStr("%s=%s",$1,$3); }
	/* | column_specification '=' NULL_TOK A value expression ja tem */
	;

set_clause_infx
	: update_columns '=' value_expression              
									 {$$=CpStr("%s=%s",$1,$3);}
	| update_columns '=' '(' value_expression_list ')' 
									 {$$=CpStr("%s=(%s)",$1,$4);}

update_columns
	: '(' update_column_list ')'                   {$$=CpStr("(%s)",$2);}
	| '*'                                          {$$=CpStr("*");}
	| table_identifier '.' '*'                     {$$=CpStr("%s.*",$1); }
	;

update_column_list
	: column_specification                         {$$=CpStr($1);}
	| update_column_list ',' column_specification  {$$=CpStr("%s,%s",$1,$3);}
	;

/*---------------------------- <Select Statement> ---------------------------*/

/* Isto e um select como instrucao isolada */
/* O select list nao pode ter utilizacao de variaveis */
/* O table expression tem de retornar uma lista de named_values dos
	quais serao retirados os que tem o nome de uma tabela */
select_statement:
	SELECT  op_ad select_list
	op_into table_expression        { $$=CpStr("SELECT %s %s %s\n","",$3,$5); }
	;

op_into
	:
	| INTO named_value_list         { StInsertVariableListUsage($2,ASSIGNMENT); }

/*---------------------- 8.9 <Rollback Statement> ---------------------------*/

rollback_statement:
	ROLLBACK WORK
	;

/*---------------------------- <Open Statement> -----------------------------*/

open_statement
	: OPEN cursor_name
		{ StInsertCursorUsage($2,lineno+1,CURSOR_OPEN);}
	| OPEN cursor_name USING named_value_list
		{ StInsertVariableListUsage($4,READ_VAR); 
		  StInsertCursorUsage($2,lineno+1,CURSOR_OPEN);}
	;

/*---------------------------- <Insert Statement> ---------------------------*/

insert_statement
	: INSERT INTO table_name op_insert_column_list
	  VALUES '(' insert_value_list ')'
		  { StInsertTable($3); 
		    $$=CpStr("INSERT INTO %s %s VALUES (%s)\n",$3,$4,$7); }
		    /*printf("INSERT INTO %s %s VALUES (%s)\n",$3,$4,$7); }*/
	| INSERT INTO table_name op_insert_column_list
	  query_specification
		  { StInsertTable($3); 
		    /*printf("INSERT INTO %s %s QUERY \n",$3,$4);*/
		    $$=CpStr("INSERT INTO %s %s QUERY \n",$3,$4); }
	;

op_insert_column_list
	:                                           { $$=CpStr("");            }
	| '(' insert_column_list ')'                { $$=CpStr("(%s)",$2);     }
	;

insert_column_list
	: column_identifier                             { $$=CpStr($1);            }
	| insert_column_list ',' column_identifier      { $$=CpStr("%s,%s",$1,$3); }
	/*
	: column_name                               { $$=CpStr($1);            }
	| insert_column_list ',' column_name        { $$=CpStr("%s,%s",$1,$3); }
	Alterado em 25/9/98 */
	;

insert_value_list
	: insert_value                              { $$=CpStr($1);            }
	| insert_value_list ',' insert_value        { $$=CpStr("%s,%s",$1,$3); }
	;

insert_value
	/* value_specification */
	: fgl_operand                               { $$=CpStr($1);           }
	| NULL_TOK                                  { $$=CpStr("NULL");       }
	;


/*---------------------------- <Fetch Statement> ----------------------------*/

fetch_statement
	: FETCH fetch_action cursor_name INTO fetch_target_list
		{ StInsertCursorUsage($3,lineno+1,CURSOR_FETCH);}
	| FETCH fetch_action cursor_name 
		{ StInsertCursorUsage($3,lineno+1,CURSOR_FETCH);}
	;

fetch_action
	: 
	| NEXT
	| PREVIOUS
	| PRIOR
	| FIRST
	| LAST
	| CURRENT
	| RELATIVE fgl_expression /* Granel */   /* Depois acaba-se (quando aparacer) */
	/* | RELATIVE NUMBER    Depois acaba-se (quando aparacer) */
	| ABSOLUTE named_value   /* Depois acaba-se (quando aparacer) */
	   /* VARIABLE USAGE */
	| ABSOLUTE NUMBER   /* Depois acaba-se (quando aparacer) */

/* ??? Afectacoes so para desenrascar */
fetch_target_list:
	named_value {char *x=$1; }
	   /* VARIABLE ASSIGNMENT */
	| fetch_target_list ',' named_value { char *x=$3;}
	   /* VARIABLE ASSIGNMENT */
	;

/*----------------------- <Delete Statement: Searched> ----------------------*/

delete_statement_search:
	DELETE FROM table_name
	op_where_clause 
				{ StInsertTable($3);   /* To remove */
	           $$=CpStr("DELETE FROM %s %s",$3,$4); 
	           StIncrementTable(); }
	;

/*---------------------- <Delete Statement: Positioned> ---------------------*/

delete_statement_position:
	DELETE FROM table_name
	WHERE CURRENT OF cursor_name
				{ StInsertTable($3);   /* To remove */
	           $$=CpStr("DELETE FROM %s WHERE CURRENT OF %s",$3,$7); 
	           StIncrementTable(); }
	;

/*------------------------ <Execute statement> -----------------------------*/

execute_statement
	: EXECUTE IDENTIFIER 
	| EXECUTE IDENTIFIER  USING named_value_list
		{ StInsertVariableListUsage($4,READ_VAR); }

/*------------------------- <Declare Cursor> -----------------------------*/

/* Isto esta rebuscado mas e por causa de um conflito derivado de 
	limited lookahead 
	Eventualmente tem de se ter cuidado com o carregamento da tabela de simbolos
	*/
declare_cursor:
	DECLARE cursor_name cursor_type 
	   FOR cursor_specification  
	      /* Declare for update */
			{ StInsertCursorDeclaration($2,$3,$5); }
	| DECLARE cursor_name cursor_type 
	   FOR cursor_specification  FOR UPDATE op_for_update_list
	      /* Declare seguido de for */
			{ StInsertCursorDeclaration($2,$3,$5); }
	| DECLARE cursor_name cursor_type 
	   FOR cursor_specification  
	   FOR IDENTIFIER '=' fgl_expression TO fgl_expression op_step 
			fgl_statement_list
	   END_TOK FOR
			{ StInsertCursorDeclaration($2,$3,$5); }
	;

op_for_update_list
	:
	| OF update_column_list { char *x; x=$2; }

cursor_type
	: SCROLL CURSOR                                  { $$ = CURS_SCROLL; }
	| CURSOR                                         { $$ = CURS_NORMAL; }
	| CURSOR WITH HOLD                               { $$ = WITH_HOLD; }
	| SCROLL CURSOR WITH HOLD                        { $$ = SCROLL_WITH_HOLD; }

cursor_specification
	: query_expression                  { StInsertSQLTxt($1);
	                                      StInsertSQL(SQL_SELECT,lineno+1); 
													  $$ = NOT_PREPARED; }
	/* Cursor of prepared statement */
	| IDENTIFIER                        { $$ = PREPARED; }
	;

query_expression
	: query_term                                { $$=CpStr($1); }
	| query_expression UNION op_all query_term  { $$=CpStr($1); }
	;

query_term
	: query_specification                    { $$=CpStr($1); }
	| '(' query_expression ')'               { $$=CpStr($2); }
	;

op_order_by_clause
	:                                        { $$=CpStr(""); }
	| ORDER BY sort_specification_list       { $$=CpStr("ORDER BY %s",$3); }
	;

sort_specification_list
	: sort_specification                     { $$=CpStr($1);                } 
	| sort_specification_list ',' 
	  sort_specification                     { $$=CpStr("%s,%s",$1,$3);    }
	;

sort_specification
	: NUMBER op_asc_desc                     { $$=CpStr("%d %s",$1,$2);    }
	| column_specification op_asc_desc       { $$=CpStr("%s %s",$1,$2);    }
	;

op_asc_desc 
	:                                        { $$="";                 }
	| ASC                                    { $$=CpStr("ASC");             }
	| DESC                                   { $$=CpStr("DESC");            }
	;

/*---------------------------- <Begin and Commit Statement> -----------------*/

commit_statement:
	COMMIT WORK
	;

begin_statement:
	BEGIN_TOK WORK
	;

/*---------------------------- <Close Statement> ----------------------------*/

close_statement:
	CLOSE cursor_name
		{ StInsertCursorUsage($2,lineno+1,CURSOR_CLOSE);}
	;

/*---------------------------- <SQL Statements> ----------------------------*/
sql_statement:
	  close_statement
	| CLOSE DATABASE
	| begin_statement
	| commit_statement
	| delete_statement_position                /* Delete where current of */
	                     { StInsertSQLTxt($1);
								  StInsertSQL(SQL_DELETE,lineno+1); }
	| delete_statement_search
	                     { StInsertSQLTxt($1);
	                       StInsertSQL(SQL_DELETE,lineno+1); }
	| execute_statement
	| fetch_statement
	| insert_statement   { StIncrementTable();
	                       StInsertSQLTxt($1);
	                       StInsertSQL(SQL_INSERT,lineno+1); }
	| open_statement
	| rollback_statement
	| select_statement   { StInsertSQLTxt($1);
	                       StInsertSQL(SQL_SELECT,lineno+1); }
	                                /* Isto esta dentro de declare_cursor */
	/* | cursor_specification */
	| update_statement_position                /* Update where current of */
	                     { StIncrementTable();
	                       StInsertSQLTxt($1);  
	                       StInsertSQL(SQL_UPDATE,lineno+1); }
	| update_statement_search
	                     { StIncrementTable();
	                       StInsertSQLTxt($1);  
	                       StInsertSQL(SQL_UPDATE,lineno+1); }
	| declare_cursor
	| prepare
	| SET EXPLAIN ON
	| SET EXPLAIN OFF
	| set_lock_mode
	| set_isolation
	| table_definition   /* Esta no schema definition que esta comentado */
	| index_definition
	| revoke
	| DROP TABLE table_name 
	| lock
	| unlock
	| update_statistics
	;

lock
	: LOCK TABLE table_name IN lock_mode MODE
	;

lock_mode
	: SHARE
	| EXCLUSIVE
	;

unlock
	: UNLOCK TABLE table_name
	;

set_lock_mode
	: SET LOCK MODE TO WAIT NUMBER
	| SET LOCK MODE TO WAIT 
	| SET LOCK MODE TO NOT WAIT 
	;

set_isolation
	: SET ISOLATION TO DIRTY READ
	| SET ISOLATION TO COMMITTED READ
	| SET ISOLATION TO CURSOR STABILITY
	| SET ISOLATION TO REPEATABLE READ
	;
 /* ??? Ainda faltam ??? */

/*-------------------------  <update statistics> --------------------------*/

/* TODO - Este statement não está completo */
update_statistics
	: UPDATE STATISTICS FOR TABLE table_name

/*---------------------- 6.10 <privilege definition> ------------------------*/

privilege_definition:
	GRANT privileges ON table_name
	TO grantee_list
	op_with_grant_option
	;

op_with_grant_option:
	| WITH GRANT OPTION
	;

privileges:
	ALL PRIVILEGES
	| ALL
	| action_list
	;

action_list:
	action
	| action_list ',' action
	;

action:
	SELECT
	| INSERT
	| DELETE
	| UPDATE op_grant_column_list
	;

op_grant_column_list:
	| '(' grant_column_list ')'
	;

/* ??? Afectacoes so para o bison trabalhar */
grant_column_list
	: column_name { char *x=$1;}
	| grant_column_list ',' column_name
	;

grantee_list
	: grantee
	| grantee_list ',' grantee
	;

grantee:
	PUBLIC
	| authorization_identifier
	;

revoke : 
	REVOKE privileges ON table_name
	FROM grantee_list 
	;

/*----------------------------- <view definition> ---------------------------*/

view_definition:
	CREATE VIEW table_name op_view_column_list
	AS query_specification
	op_with_check_option
	;

op_view_column_list:
	| '(' view_column_list ')'
	;

/* ??? Afectacoes so para o bison funcionar */
view_column_list 
	: column_name { char *x=$1; }
	| view_column_list ',' column_name { char *x=$3; }
	;

op_with_check_option:
	| WITH CHECK OPTION
	;

/*--------------------- <Check Constraint Definition> -----------------*/

check_constraint_definition:
	CHECK '(' search_condition ')'
	;

/*--------------------- <Referential Constraint Definition> -----------------*/

referential_constraint_definition:
	FOREIGN KEY '(' references_columns ')'
	references_specification
	;

references_specification:
	REFERENCES referenced_table_and_columns
	;

references_columns:
	references_column_list
	;

/* ??? Afectacao para bison trabalhar */
referenced_table_and_columns
	: table_name { char *x=$1; }
	| table_name '(' references_column_list ')' { char *x=$1; }
	;

/* ??? Afectacao so para o bison funcionar */
references_column_list
	: column_name { char *x=$1; }
	| references_column_list ',' column_name { char *x=$3; }
	;

/*----------------------- <Unique Constraint Definition> --------------------*/

unique_constraint_definition:
	  UNIQUE '(' unique_column_list ')'
	| PRIMARY KEY '(' unique_column_list ')'
	;

/* ??? Afectacoes so para o bison funcionar */
unique_column_list
	: column_name { char *x=$1; }
	| unique_column_list ',' column_name { char *x=$3; }
	;
	
/*----------------------- <Table Constraint Definition> --------------------*/

table_constraint_definition:
	unique_constraint_definition
	| referential_constraint_definition
	| check_constraint_definition
	;

/*------------------------------ <Default Clause> ---------------------------*/

default_clause:
	  DEFAULT sql_literal
	| DEFAULT NULL_TOK
	| DEFAULT USER
	;

/*---------------------------- <Column Definition> --------------------------*/

/* ??? Afactacoes para o bison funcionar */
/* column_name data_type */
column_definiton:
	column_name fgl_data_type
	op_default_clause
	op_column_constraint_list { char *x=$1; }
	;

op_default_clause:
	|default_clause
	;

op_column_constraint_list:
	| column_constraint op_column_constraint_list
	;

column_constraint:
	  NOT NULL_TOK
	| NOT NULL_TOK UNIQUE
	| references_specification
	| CHECK '(' search_condition ')'
	;

/*------------------------ 6.2 <table definition> ---------------------------*/

table_definition:
	CREATE op_temp TABLE table_name
	'('  table_element_list ')' op_with_no_log
	;

op_temp
	:
	| TEMP
	;

table_element_list:
	  table_element
	| table_element_list ',' table_element
	;
	
table_element:
	  column_definiton
	| table_constraint_definition
	;

op_with_no_log
	: 
	| WITH NO LOG
	;

/*--------------------------------- <index> --------------------------------*/

index_definition
	: create_index
	| drop_index
	;

create_index
	: CREATE op_unique INDEX index_name ON table_name '(' column_list ')' 
	;

op_unique
	:
	| UNIQUE

index_name
	: IDENTIFIER   { char *x; x=$1; }
	| STRING '.' IDENTIFIER  { char *x; x = $1; }

drop_index
	: DROP INDEX IDENTIFIER 
	;
	
/*--------------------------------- <schema> --------------------------------*/

/* Isto esta temporariamente em comentario
schema:
	CREATE SCHEMA schema_authorization_clause
	schema_element_list
	;

schema_authorization_clause:
	AUTHORIZATION schema_authorization_identifier
	;

schema_authorization_identifier:
	authorization_identifier
	;

schema_element_list:
	  schema_element
	| schema_element_list schema_element
	;

schema_element:
	  table_definition
	| index_definition
	| view_definition
	| privilege_definition
	;
	*/

/*****************************************************************************/
/*--------------------------- <query specification> -------------------------*/

/* 
 * Como o query_specification pode ser de outra regra o $$ devera devolver 
 * informacao que o descreva, nomeadamente:
 *   - Lista de colunas
 *   - Funcoes utilizadas
 *   - Lista de variaveis (das quais serao filtradas as tabelas, 
 * locais e modulares)
 *   - Lista de tabelas
 */
query_specification:
	SELECT op_ad select_list 
	into_target_specification
	table_expression                { $$=CpStr("SELECT %s %s %s\n","",$3,$5); }
	;

into_target_specification
	:
	| INTO named_value_list       { StInsertVariableListUsage($2,ASSIGNMENT); }

select_list
	: value_expression_list                      { $$=CpStr($1);             }
	/*| '*'       */
	;

value_expression_list
	: value_expression                           { $$=CpStr($1);             }
	| value_expression_list ',' value_expression { $$=CpStr("%s,%s",$1,$3); }
	;

/*--------------------------------- <subquery> ------------------------------*/

subquery:
	'(' SELECT op_ad result_specification table_expression ')'
		 /* Query part - Text insertion */
	;

/* 
 * Isto tem de devolver uma string com a operacao
 */
op_ad:
	| ALL
	| DISTINCT
	| UNIQUE
	;

/* Afectacao para o bison trabalhar */
result_specification
	: value_expression { char *x=$1; }
	| '*'
	;

/*------------------------------ <having clause> ----------------------------*/

having_clause:
	HAVING search_condition { $$=CpStr("HAVING %s",$2); }
		 /* Query part - Text insertion */
	;

/*----------------------------- <group by clause> ---------------------------*/

group_by_clause
	: GROUP BY column_specification_list       { $$=CpStr("GROUP BY %s",$3); }
	; 

column_specification_list
	: column_specification                   { $$=CpStr($1);              }
	| NUMBER                                 { $$=CpStr("%d",$1);        }
	| column_specification_list ',' column_specification
		                                      { $$=CpStr("%s,%s",$1,$3);  }
	| column_specification_list ',' NUMBER   { $$=CpStr("%s,%d",$1,$3);  }
	;

/*------------------------------- <where clause> ----------------------------*/

where_clause
	: WHERE search_condition                 { $$=CpStr("WHERE %s",$2);    }
	;

/*------------------------------- <from clause> -----------------------------*/

/* Eu queria que isto devolvesse um array de estruturas com as tabelas usadas */
from_clause
	: FROM table_reference_list 
		{  $$=CpStr("FROM %s",GetListConcat($2,",")); CleanNameList($2); }
	;

/* Isto tem de passar a trabalhar com stacks devolvidos pelo $$ */
table_reference_list
	: table_reference
	  { StInsertTable($1);   /* To remove */
	    StIncrementTable(); 
		 /* First try */
		 InsertNameList(&$$,(NAME_LIST *)0,$1,lineno+1); }

	| table_reference_list ',' table_reference
	  { StInsertTable($3);   /* To remove */
	    StIncrementTable(); 
		 /* First try */
		 InsertNameList(&$$,$1,$3,lineno+1); }

	/* Faltam os () */
	| table_reference_list ',' OUTER table_reference
	  { StInsertTable($4);   /* To remove */
	    StIncrementTable(); 
		 /* First try */
		 InsertNameList(&$$,$1,$4,lineno+1); }
	;

/* == It returns only the Name of the table */
table_reference
	: table_name                    { strcpy($$,$1); }
	| table_name correlation_name   { strcpy($$,$1); }
	;

/*---------------------------- <search condiction> --------------------------*/

/* TODO - Confirmar into temp na syntaxe do 4gl */
table_expression:
	from_clause
	op_where_clause
	op_group_by_clause
	op_having_clause
	op_order_by_clause
	op_into_temp
		{ $$=CpStr( "%s %s %s %s", $1, $2, $3, $4); }
	;

op_where_clause
	:                                   { $$=CpStr("");                     }
	| where_clause                      { $$=CpStr($1);                     }
	;

op_group_by_clause
	:                                   { $$=CpStr(""); }
	| group_by_clause                   { $$=CpStr($1); }
	;

op_having_clause
	:                                   { $$=CpStr(""); }
	| having_clause                     { $$=CpStr($1); }
	;

op_into_temp
	:
	| INTO TEMP IDENTIFIER op_with_no_log

op_with_no_log
	:
	| WITH NO LOG ';'

/*---------------------------- <search condiction> --------------------------*/

search_condition
	: boolean_term                             { $$=CpStr($1);              }
	| search_condition OR boolean_term         { $$=CpStr("%s OR %s",$1,$3);}
	;

boolean_term
	: boolean_factor                           { $$=CpStr($1);               }
	| boolean_term AND boolean_factor          { $$=CpStr("%s AND %s",$1,$3);}
	;

boolean_factor
	: boolean_primary                          { $$=CpStr($1);               }
	| NOT boolean_primary                      { $$=CpStr("NOT %s",$2);     }
	;

boolean_primary
	: predicate                                { $$=CpStr($1);               }
	| '(' search_condition ')'                 { $$=CpStr("(%s)",$2);       }
	;

/*----------------------------- <exists_predicate> --------------------------*/

exists_predicate:
	EXISTS subquery    { $$=CpStr("EXISTS %s","Subquery"); }
	;

/*--------------------------- <quantified_predicate> ------------------------*/

quantified_predicate:
	value_expression comp_op quantifier subquery
		  { $$=CpStr("%s %s %s %s",$1,$2,$3,"Subquery"); }
	;

quantifier 
	: all       { $$=CpStr("ALL");  }
	| some      { $$=CpStr("SOME"); }
	;

all:
	ALL
	;

some:
	  SOME
	| ANY
	;

/*------------------------------ <null_predicate> ---------------------------*/

null_predicate:
	/* Mais granel */
	/* column_specification IS op_not NULL_TOK */
	named_value IS op_not NULL_TOK
		  { $$=CpStr("%s IS %s NULL",$1,$3); }
	   /* VARIABLE USAGE */
	;

/*------------------------------ <like_predicate> ---------------------------*/

like_predicate:
	/* Mais granel */
	  /* column_specification op_not LIKE pattern op_escape*/
	  named_value op_not LIKE pattern op_escape
		  { $$=CpStr("%s %s LIKE %s %s",$1,$2,$4,$5); }
	   /* VARIABLE USAGE */
	;

op_escape
	: { strcpy($$,""); }
	| ESCAPE escape_character { sprintf($$,"ESCAPE %s",$2); }
	;

pattern
	: value_specification { strcpy($$,$1); }
	;

escape_character:
	  value_specification { strcpy($$,$1); }
	;

/*------------------------- <matches_predicate> ---------------------------*/

matches_predicate:
	  /* Mais granel */
	  /* column_specification op_not MATCHES pattern op_escape */
	  named_value op_not MATCHES pattern op_escape
		  { $$=CpStr("%s %s MATCHES %s %s",$1,$2,$4,$5); }
	   /* VARIABLE USAGE */
	;

/*------------------------------- <in_predicate> ----------------------------*/

in_predicate
	: named_value op_not IN subquery  
		{ $$=CpStr("%s %s IN %s",$1,$2,"SUBQUERY"); }
	   /* VARIABLE USAGE */
	| named_value op_not IN '(' in_value_list ')'
		{ $$=CpStr("%s %s IN (%s)",$1,$2,"IN VALUE"); }
	   /* VARIABLE USAGE */
	;

in_value_list:
	  in_value_specification
	| in_value_list ',' in_value_specification
	;

/* So para desenrascar */
in_value_specification
	: STRING { char *x=$1; }
	| NUMBER { int x=$1; }
	| IDENTIFIER { char *x=$1; }
	;

/* ??? Afectacao so para desenrascar */
in_primary
	/* : value_specification */
	/* : column_specification */
	/* | set_function_specification */
	/* | '(' value_expression ')' */
	/*| TODAY                       E ainda faltam aqui mais umas reservadas */
	/* | function_call                */
	: IDENTIFIER { char *x=$1; }
	| IDENTIFIER '.' IDENTIFIER { char *x=$1; }
	| IDENTIFIER '[' array_indexes ']' '.' var_name { char *x=$1; }
	| IDENTIFIER '[' array_indexes ']' { char *x=$1; }
	;


/*----------------------------- <between_predicate> -------------------------*/

between_predicate:
	value_expression op_not
		BETWEEN value_expression AND value_expression
			 { $$=CpStr("%s %s BETWEEN %s AND %s",$1,$2,$4,$6);  }
	;

op_not
	:          { $$=CpStr("");     }
	| NOT      { $$=CpStr("NOT");  }
	;

/*---------------------- 5.11 <comparison_predicate> ------------------------*/

comparison_predicate
	: value_expression comp_op value_expression
			{ $$=CpStr("%s %s %s",$1,$2,$3);   }
	| value_expression comp_op subquery
			{ $$=CpStr("%s %s %s",$1,$2,"subquery");   }
	;

comp_op 
	: '='                                      { $$=CpStr("=");            }
	| NOT_EQUAL                                { $$=CpStr("!=");           }
	| '<'                                      { $$=CpStr("<");            }
	| '>'                                      { $$=CpStr(">");            }
	| LESS_OR_EQUAL                            { $$=CpStr("<=");           }
	| GREATER_OR_EQUAL                         { $$=CpStr(">=");           }
	;

/*-------------------------------- <predicate> ------------------------------*/

predicate
	: comparison_predicate                    { $$=CpStr($1);            }
	| between_predicate                       { $$=CpStr($1);            }
	| in_predicate                            { $$=CpStr($1);            }
	| like_predicate                          { $$=CpStr($1);            }
	| matches_predicate                       { $$=CpStr($1);            }
	| null_predicate                          { $$=CpStr($1);            }
	| quantified_predicate                    { $$=CpStr($1);            }
	| exists_predicate                        { $$=CpStr($1);            }
	;

/*---------------------------- <value expression> ---------------------------*/

value_expression
	: value_expression '*' value_expression   { $$=CpStr("%s * %s",$1,$3);  }
	| value_expression '/' value_expression   { $$=CpStr("%s / %s",$1,$3);  }
	| value_expression '+' value_expression   { $$=CpStr("%s + %s",$1,$3);  }
	| value_expression '-' value_expression   { $$=CpStr("%s - %s",$1,$3);  }
	| primary                                 { $$=CpStr($1);                }
	| factor                                  { $$=CpStr($1);                }
	;

factor
	: '+' primary                             { $$=CpStr("+%s",$2);          }
	| '-' primary                             { $$=CpStr("-%s",$2);          }
	;

/* Esta regra esta um bocado agranelada */
/* ATENCAO : Apenas devolve uma string no caso dos named values,
				 Caso contrario devolve NULL
 */
primary
  : fgl_operand op_as_field                { $$=CpStr("%s %s",$1,$2);     }
	| set_function_specification op_as_field { $$=CpStr("%s %s",$1,$2);     }
	| '(' value_expression ')' op_as_field   { $$=CpStr("(%s) %s",$2,$4);   }
	/* Isto estraga tudo
  | fgl_expression                         { $$=CpStr("%s","");     }
	*/
	;

op_as_field
	:                                        { $$=CpStr("");                }
	| IDENTIFIER                             { $$=CpStr(" %s",$1);          }
	| AS IDENTIFIER                          { $$=CpStr(" AS %s",$2);       }
	;

/*----------------------- <set function specification> ----------------------*/

/* ??? O count tem de deixar de ser palavra reservada */

set_function_specification
	: COUNT '(' '*' ')'                      { $$=CpStr("COUNT(*)");         }
	                                         /* ??? So para desenrascar */
	| COUNT '(' '*' ')' IDENTIFIER           { $$=CpStr("COUNT(*) %s",$5);   }
	| distinct_set_function                  { $$=CpStr($1);                 }
	| all_set_function                       { $$=CpStr($1);                 }
	;

distinct_set_function
	: MAX '(' DISTINCT column_specification ')'
		                                 { $$=CpStr("MAX(DISTINCT %s)",$4);   }
	/* Se funcionar podem-se tirar as funcoes */
	| IDENTIFIER '(' DISTINCT column_specification ')'
		                                 { $$=CpStr("%s(DISTINCT %s)",$1,$4); }
	| COUNT '(' DISTINCT column_specification ')'
		                                 { $$=CpStr("COUNT(DISTINCT %s)",$4); }
	;

all_set_function
	/* Estas funcoes passam para o array de funcoes internas */
	: MAX '(' op_all value_expression ')'
		                                 { $$=CpStr("MAX(%s %s)",$3,$4); }
	| IDENTIFIER '(' op_all value_expression ')'
		                                 { $$=CpStr("%s(%s %s)",$1,$3,$4); }
	| COUNT '(' op_all value_expression ')'
		                                 { $$=CpStr("COUNT(%s %s)",$3,$4); }
	;

op_all
	:                                    { $$=CpStr("");                   }
	| ALL                                { $$=CpStr("ALL");                }

	;


/*------------------------- <column specification> --------------------------*/
/* Apenas colunas simples */
column_specification
	: column_name                         { $$=CpStr($1);                   }
	                                      /* ??? Isto nao esta la muito bem */
	| table_identifier '.' column_name    { $$=CpStr("%s.%s",$1,$3);        }
	;

/*-------------- <value specification> and <target specification> -----------*/


value_specification
	: parameter_specification { strcpy($$,$1); }
	| variable_specification { strcpy($$,$1); }
	| sql_literal { strcpy($$,$1); }
	| USER { strcpy($$,"USER"); }
	;

target_specification
	: parameter_specification  { strcpy($$,$1); }
	| variable_specification  { strcpy($$,$1); }
	;

parameter_specification:
	/*IDENTIFIER   { strcpy($$,$1); } */
	named_value { strcpy($$,$1); } 
	;

variable_specification:
	',' IDENTIFIER { sprintf($$,",%s",$2); }
	/*| ',' named_value*/
	;

/*--------------------------- 5.5 <data type> -------------------------------*/
/* ??? Podia ser usado o que ja esta definido */
/* Tem de ser merged com os do 4gl */
/* ??? Usar  fgl_datatype */

data_type:
	  char_string_type
	| DATE
	| exact_numeric_type
	| approx_numeric_type
	;

char_string_type
	: CHAR
	| CHAR '(' length ')'
	;

exact_numeric_type
	: DEC '(' NUMBER op_scale ')'
	| DEC
	| INTEGER
	| SMALLINT
	;

op_scale:
	| ',' scale
	;

approx_numeric_type:
	FLOAT '(' NUMBER ')'
	| REAL
	| DOUBLE PRECISION
	;

/* ??? Afectacao para o bison funcionar */
length
	/* : UINTEGER Defiincao do parser de sql */
	: NUMBER { int x=$1; }
	;

scale
	/* : UINTEGER Definicao da gramatica SQL */
	: NUMBER { int x=$1; }
	;

/*----------------------------- 5.4 Names -----------------------------------*/
table_name
	: table_identifier op_as                               { strcpy($$,$1); }
	| authorization_identifier '.' table_identifier op_as  { strcpy($$,$3); }
	| authorization_identifier ':' table_identifier op_as  { strcpy($$,$3); }
	| authorization_identifier ':' table_identifier op_as  { strcpy($$,$3); }
	;

/* Optional table alias */
op_as
	:
	| AS IDENTIFIER { char *x; x=$2; }
	;

/* ??? Afectacao para o bison funcionar */
/* TODO - Isto não está lá muito bem */
authorization_identifier
	: IDENTIFIER { char *x=$1; }
	| IDENTIFIER '@' IDENTIFIER { char *x=$1; }
	| STRING { char *x=$1; }
	;

/* 
 * Isto tem de passar a trabalhar com o $$
 * Nao suporta owner.tabela.coluna 
 */
table_identifier
	: IDENTIFIER
	   { strcpy($$,$1); }
	| MESSAGE     /* ??? Isto devia dar um errozito */
	   { strcpy($$,"MESSAGE"); }
	| TABLE       /* ??? Isto devia dar um errozito */
	   { strcpy($$,"TABLE"); }
	| USER        /* ??? Isto devia dar um errozito */
	   { strcpy($$,"USER"); }
	;

column_identifier
	: table_identifier '.' column_name    { $$=CpStr($3);      }
	| column_name                         { $$=CpStr($1);      }

column_name
	: IDENTIFIER                          { $$=CpStr($1);                  }
	| CONSTRUCT                           { $$=CpStr("CONSTRUCT");             }
	| COUNT                               { $$=CpStr("COUNT");             }
  | DATE                                { $$=CpStr("DATE");             }
  | DEC                                 { $$=CpStr("SHARE");             }
	| FIELD                               { $$=CpStr("FIELD");             }
  | FORM                                { $$=CpStr("FORM");             }
  | FREE                                { $$=CpStr("FREE");               }
	| FROM                                { $$=CpStr("FROM");               }
	| GROUP                               { $$=CpStr("GROUP");              }
	| HOLD                                { $$=CpStr("HOLD");               }
	| LAST                                { $$=CpStr("LAST");               }
	| LENGTH                              { $$=CpStr("LENGTH");             }
	| LINE                                { $$=CpStr("LINE");               }
	| LINES                               { $$=CpStr("LINES");              }
	| MAX                                 { $$=CpStr("MAX");                }
	| NAME                                { $$=CpStr("NAME");               }
  | OPTION                              { $$=CpStr("OPTION");             }
  | ORDER                               { $$=CpStr("ORDER");              }
	| PRINT                               { $$=CpStr("PRINT");              }
	| PRINTER                             { $$=CpStr("PRINTER");            }
	| SERIAL                              { $$=CpStr("SERIAL");             }
	| SHARE                               { $$=CpStr("SHARE");              }
	| TABLE                               { $$=CpStr("TABLE");              }
	| TEXT                                { $$=CpStr("TEXT");               }
	| TOTAL                               { $$=CpStr("TOTAL");              }
	| UNITS                               { $$=CpStr("UNITS");              }
	| USER                                { $$=CpStr("USER");              }
	;

/* ??? Afectacao para o bison funcionar */
correlation_name:
	IDENTIFIER { char *x=$1; }
   ; 

cursor_name:
	IDENTIFIER
		{ strcpy($$,$1); }
	;

/*--------------------------------- <literal> --------------------------------*/

sql_literal
	: STRING   { strcpy($$,$1); }
	| NUMBER  { sprintf($$,"%d",$1); }
	/*
	| UINTEGER  { strcpy($$,$1); }
	| SINTEGER  { strcpy($$,$1); }
	*/
	;

/*  ----------------------------- <Others> ---------------------------------*/
prepare
	: PREPARE IDENTIFIER FROM STRING
		/* Insert SQL - Prepared */
	| PREPARE IDENTIFIER FROM named_value
	   { StInsertVariableUsage($4,lineno+1,READ_VAR);} 
		/* Insert SQL - Prepared */
	;

	/* Para remover quando se souber que esta OK
	| PREPARE IDENTIFIER FROM IDENTIFIER
	*/

/*  ============================== COMPILER DIRECTIVES    */
compiler_directives
	: DEFER INTERRUPT
	| DEFER QUIT
	| WHENEVER whenever_event whenever_action

whenever_event
	: NOT FOUND
	| ERROR
	| SQLERROR
	| ANY SQLERROR
	| ANY ERROR
	| SQLWARNING
	| WARNING

whenever_action
	: CONTINUE
	| goto
	| STOP
	| CALL IDENTIFIER        { StInsertFunctionCall($2,lineno+1); 
									   StUpdFCUsage("WHENEVER"); }


op_semicolon
	:
	| ';'

%%



/*
 * Falta estudar e usar recuperacao de erros que aqui eh fundamental
 */
yyerror(s)
char *s;
{
	P4glError(1,"Line %d: %s\n",lineno+1,s);
}
