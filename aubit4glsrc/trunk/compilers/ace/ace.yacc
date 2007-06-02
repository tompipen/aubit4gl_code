%{
#define _BISON_SIMPLE_INCL_

/*
=====================================================================
		                    Includes
=====================================================================
*/
#define YYDEBUG 1
#define _NO_YYPARSE_PROTO_
/* #define _NO_YYLEX_PROTO_ */
#include "a4gl_ace_int.h"
#include <ctype.h>

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

extern struct report this_report;
#ifdef OLD_INCL
	extern int a4gl_status;
#endif
extern int lineno;
extern int colno;
extern int ignorekw;
static char temp_tab_name[256]="";
char *ordby[256];
int ordbycnt=0;
void *memdup(void *p,int l);

#define DUP(x) memdup(&x,sizeof(x))
#define COPY(x,y) memcpy(&x,&y,sizeof(x))

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void add_fmt (int cat, struct expr *col, struct commands commands);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

void *
memdup(void *p,int l)
{
	void *ptr;
	ptr=acl_malloc2(l);
	memcpy(ptr,p,l);
	return ptr;
}


void
set_expr_int(struct expr *e,int a)
{
	e->type=EXPRTYPE_INT;
	e->expr_u.i=a;
}


%}

%start ace_report

%name-prefix="a4gl_ace_yy"

%union	  {
	char   str[30000];
	struct command cmd;
	struct expr expr;
	struct expr *exprptr;
	struct commands commands;
	struct agg_val agg_val;
	struct var_usage *var_usage;
}

%token <str> NAME
%left COMMA
%right ASCII COLUMN SPACES USING
%left WHERE
%left KW_OR
%left KW_AND
%right CLIPPED
%left NOT
%left IS_NOT_NULL IS_NULL
%left GREATER_THAN GREATER_THAN_EQ LESS_THAN LESS_THAN_EQ EQUAL NOT_EQUAL COMPARISON
%right MATCHES NOT_MATCHES LIKE NOT_LIKE
%left PLUS MINUS
%left MULTIPLY DIVIDE
%left POW MOD

%token AFTER
%token AFTGROUP
%token ALL
%token ANY
%token ASC
%token ATSIGN
%token AVERAGE 
%token AVG
%token BEFORE
%token BETWEEN
%token BOTTOM
%token BY
%token KW_CALL
%token CH
%token CHAR
%token CHAR_VALUE
%token CLOSE_BRACKET
%token CLOSE_SQUARE
%token COLON
%token COMMANDS
%token COMPARISON
%token COUNT
%token DATABASE
%token DATE
%token TIME 
%token DATETIME
%token DAY
%token DECIMAL
%token DEFINE
%token DELIMITER
%token DESC
%token DISTINCT
%token DO
%token DOLLAR
%token DOT
%token ELSE
%token END
%token ESCAPE
%token EVERY
%token EXISTS
%token EXTERNAL
%token FIRST 
%token FLOAT
%token PIPE
%token FOR
%token FORMAT
%token FRACTION
%token FROM
%token FUNCTION
%token GROUP
%token GROUP_BY
%token HAVING
%token HEADER
%token HOUR
%token IF
%token IN
%token INPUT
%token INTEGER
%token INTERVAL
%token INTO
%token INTVAL
%token KW_FALSE
%token KW_TRUE
%token LAST
%token LEFT
%token LENGTH
%token LESS_THAN
%token LESS_THAN_EQ
%token LET
%token LINES
%token MARGIN
%token MINUTE
%token MONEY
%token MONTH
%token NAMED
%token NEED
%token NOT_EXISTS
%token NOT_IN
%token NUMBER_VALUE
%token NUMERIC
%token KW_OF 
%token ON
%token OPEN_BRACKET
%token OPEN_SQUARE
%token ORDER_BY
%token ORDER_EXTERNAL_BY
%token OUTER
%token OUTPUT
%token PAGE
%token PAGE_HEADER
%token PAGE_TRAILER
%token PARAM
%token PAUSE
%token PERCENT 
%token PRINT
%token PRINTER
%token PRINT_FILE
%token PROMPT
%token READ
%token REPORT
%token RIGHT
%token ROW
%token SECOND
%token SELECT
%token SEMICOLON
%token SKIP
%token SMALLFLOAT
%token SMALLINT
%token SOME
%token STEP
%token SUM
%token TEMP
%token THEN
%token TO
%token TOP
%token TOP_OF_PAGE
%token TOTAL
%token TRAILER
%token UNION
%token UNIQUE
%token UNITS_DAY 
%token UNITS_HOUR 
%token UNITS_MINUTE 
%token UNITS_MONTH 
%token UNITS_SECOND 
%token UNITS_YEAR 
%token UPDATE
%token USER
%token VARCHAR
%token VARIABLE
%token WHILE
%token WITH_NO_LOG
%token XBEGIN
%token XMAX
%token XMIN
%token YEAR
%%
ace_report :
	db_section 
	op_define_section 
	op_input_section 
	op_output_section 
	select_section 
	format_section;

db_section:
	DATABASE ASCII END {
		this_report.dbname=acl_strdup("!!ASCII!!");;
	}
	| DATABASE NAMED END {
		this_report.dbname=acl_strdup($<str>2);
		A4GLSQL_init_connection ($<str>2);
		if (a4gl_status!=0) {
			a4gl_ace_yyerror("Unable to connect to database");
		}
	}
;

op_define_section:
	|
	define_section
;


define_section:
	DEFINE define_element_list END
;

define_element_list :
	define_element | define_element_list define_element
;

define_element:
	ASCII def_ascii_list {
		printf("NIY\n");
		exit(0);
	}
	| VARIABLE variable datatype {
		ace_add_variable($<str>2,$<str>3,CAT_VARIABLE,0,-1,0);
	}
	| PARAM OPEN_SQUARE int_val CLOSE_SQUARE variable datatype {
		ace_add_variable($<str>5,$<str>6,CAT_PARAM,atoi($<str>3),-1,0);
	}
	| FUNCTION ufunc_name {
		add_function($<str>2);
	}
;

ufunc_name: NAMED
;

def_ascii_list : variable datatype | def_ascii_list COMMA variable datatype
;

variable: NAMED {
	char buff[256];
	int a;
	strcpy(buff,$<str>1);
	for (a=0;a<strlen(buff);a++) {
		buff[a]=toupper(buff[a]);
	}
	strcpy($<str>$,buff);
	}
;

datatype :
	FUNCTION 
	| INTEGER  {strcpy($<str>$,"INTEGER");}
	| CHAR  {strcpy($<str>$,"CHAR");}
	| CHAR OPEN_BRACKET int_val CLOSE_BRACKET  {sprintf($<str>$,"CHAR (%s)",$<str>3);}
	| VARCHAR {strcpy($<str>$,"VARCHAR");}
	| VARCHAR OPEN_BRACKET int_val CLOSE_BRACKET {sprintf($<str>$,"VARCHAR (%s)",$<str>3);}
	| DATE {strcpy($<str>$,"DATE");}
	| FLOAT {strcpy($<str>$,"FLOAT");}
	| SMALLFLOAT {strcpy($<str>$,"SMALLFLOAT");}
	| SMALLINT {strcpy($<str>$,"SMALLINT");}
	| DATETIME {strcpy($<str>$,"DATETIME");}
	| INTERVAL {strcpy($<str>$,"INTERVAL");}
	| MONEY {strcpy($<str>$,"MONEY");}
	| MONEY OPEN_BRACKET int_val CLOSE_BRACKET {sprintf($<str>$,"MONEY (%s,0)",$<str>3);}
	| MONEY OPEN_BRACKET int_val COMMA int_val CLOSE_BRACKET {sprintf($<str>$,"MONEY (%s,%s)",$<str>3,$<str>5);}
	| DECIMAL  {strcpy($<str>$,"DECIMAL");}
	| DECIMAL OPEN_BRACKET int_val CLOSE_BRACKET {sprintf($<str>$,"DECIMAL (%s,0)",$<str>3);}
	| DECIMAL OPEN_BRACKET int_val COMMA int_val CLOSE_BRACKET {sprintf($<str>$,"DECIMAL (%s,%s)",$<str>3,$<str>5);}
;

op_input_section:
	| input_section
;

input_section: INPUT prompt_section END
;


prompt_section: prompt_element | prompt_section prompt_element
;

prompt_element: PROMPT FOR variable USING string {
	add_inputs((char *)A4GL_strip_quotes($<str>5),$<str>3);
}
;

op_output_section : | output_section
;

output_section: OUTPUT output_element_list END
;

output_element_list : output_element | output_element_list output_element
;

output_element:
	REPORT TO PRINTER string { this_report.output.report_to_where=2; this_report.output.report_to_filename=acl_strdup($<str>4);}
	| REPORT TO PRINTER  { this_report.output.report_to_where=1; }
	| REPORT TO string { this_report.output.report_to_where=3; this_report.output.report_to_filename=acl_strdup($<str>3); }
	| REPORT TO PIPE string { this_report.output.report_to_where=4; this_report.output.report_to_filename=acl_strdup($<str>4); }
	| LEFT MARGIN int_val {
		this_report.output.left_margin=atoi($<str>3);
	}
	| BOTTOM MARGIN int_val {
		this_report.output.bottom_margin=atoi($<str>3);
	}
	| TOP MARGIN int_val {
		this_report.output.top_margin=atoi($<str>3);
	}
	| PAGE LENGTH int_val {
		this_report.output.page_length=atoi($<str>3);
	}
	| RIGHT MARGIN int_val {
		this_report.output.right_margin=atoi($<str>3);
	}
	| TOP_OF_PAGE string {
		this_report.output.top_of_page=acl_strdup($<str>2);
	}
;


select_section:
	read_list END | sec_select_list END { execute_selects(); }
;

sec_select_list:
	select_statement 			 { add_select($<str>1,temp_tab_name); }
	| sec_select_list SEMICOLON select_statement { add_select($<str>3,temp_tab_name); }
;

read_list: 
	READ string op_delim op_order_by_clause_read
;

op_delim: | DELIMITER string
;

format_section: 
	  FORMAT EVERY ROW END {
		struct commands cmd;
		cmd.commands.commands_len=0;
		cmd.commands.commands_val=0;
		add_fmt(FORMAT_EVERY_ROW,NULL,cmd);
	  }
	| FORMAT format_actions  op_end
		
;

op_end: | END
;


format_actions : format_action | format_actions format_action 
;

format_action :
          FIRST PAGE HEADER 	commands  
	{
		add_fmt(FORMAT_FIRST_PAGE_HEADER,NULL,$<commands>4);
	}
        | PAGE TRAILER 		commands 
	{
		add_fmt(FORMAT_PAGE_TRAILER,NULL,$<commands>3);
	}
        | PAGE HEADER 		commands 
	{
		add_fmt(FORMAT_PAGE_HEADER,NULL,$<commands>3);
	}
        | ON EVERY ROW 		commands 
	{
		add_fmt(FORMAT_ON_EVERY_ROW,NULL,$<commands>4);
	}
        | ON LAST ROW 		commands {
		add_fmt(FORMAT_ON_LAST_ROW,NULL,$<commands>4);
	}
        | BEFORE GROUP KW_OF variable_sub_a commands {
		add_fmt(FORMAT_BEFORE_GROUP,DUP($<expr>4),$<commands>5);
	}
        | AFTER GROUP KW_OF variable_sub_a commands {
		add_fmt(FORMAT_AFTER_GROUP,DUP($<expr>4),$<commands>5);
	}
;


variable_sub: 
	NAMED  OPEN_SQUARE fmt_val_expression COMMA fmt_val_expression CLOSE_SQUARE {
		$<var_usage>$=malloc(sizeof(struct var_usage));
		$<var_usage>$->subscript1=DUP($<expr>3);
		$<var_usage>$->subscript2=DUP($<expr>5);
		$<var_usage>$->varname=strdup($<str>1);
		$<var_usage>$->varid=find_variable($<var_usage>$->varname);
		if ( $<var_usage>$->varid==-1) {
			printf("Warning : %s is not a defined variable\n",$<str>1);
		}
	}
	| NAMED  OPEN_SQUARE fmt_val_expression CLOSE_SQUARE {
		$<var_usage>$=malloc(sizeof(struct var_usage));
		$<var_usage>$->subscript1=DUP($<expr>3);
		$<var_usage>$->subscript2=NULL;
		$<var_usage>$->varname=strdup($<str>1);
		$<var_usage>$->varid=find_variable($<var_usage>$->varname);
		if ( $<var_usage>$->varid==-1) {
			printf("Warning : %s is not a defined variable\n",$<str>1);
		}
	}
	| NAMED  {
		
		$<var_usage>$=malloc(sizeof(struct var_usage));
		$<var_usage>$->subscript1=NULL;
		$<var_usage>$->subscript2=NULL;
		$<var_usage>$->varname=strdup($<str>1);
		$<var_usage>$->varid=find_variable($<var_usage>$->varname);
		if ( $<var_usage>$->varid==-1) {
			printf("Warning : %s is not a defined variable\n",$<str>1);
		}
	}

;

variable_sub_a:
	variable_sub  {
		$<expr>$.type=EXPRTYPE_VARIABLE_SUB;
		$<expr>$.expr_u.var_usage=$<var_usage>1;
	}
	| INTVAL {
		$<expr>$.type=EXPRTYPE_INT;
		$<expr>$.expr_u.i=atoi($<str>1);
	}
;



op_order_by_clause_read: {strcpy($<str>$,"");} | order_by_clause_read;

order_by_clause_read:
	ORDER_BY { ordbycnt=0; } sort_specification_list {
	printf("speclist : %s ",$<str>3);
	sprintf($<str>$,"ORDER BY %s",$<str>3);}
	| ORDER_EXTERNAL_BY sort_specification_list
	{sprintf($<str>$,"%s %s",$<str>1,$<str>2);}
	;


/*************************************************************************/
/*                            SQL SELECT STUFF                           */
/*************************************************************************/


literal: CHAR_VALUE {
		sprintf($<str>$,"\"%s\"",$<str>1);
	}
        | NUMERIC
        | real_number
        | INTVAL
       ;


order_by_clause:
	ORDER_BY { ordbycnt=0; } sort_specification_list { sprintf($<str>$,"ORDER BY %s",$<str>3); }
	;

sort_specification_list:
	sort_specification
	| sort_specification_list COMMA sort_specification {
sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);
}
	;

sort_specification: sort_spec op_asc_desc  {
		if (strlen($<str>2)) {
			sprintf($<str>$,"%s %s",$<str>1,$<str>2);
		}
	};

sort_spec: INTVAL  {
		char buff[256];
		sprintf(buff,"I%d",atoi($<str>1));
		ordby[ordbycnt++]=acl_strdup(buff);
	}
	| column_name  {
		char buff[256];
		sprintf(buff,"C%s",$<str>1);
		ordby[ordbycnt++]=acl_strdup(buff);
	}
	;

op_asc_desc: {strcpy($<str>$,"");}
	| ASC
	| DESC 
	;


having_clause:
	HAVING search_condition
{sprintf($<str>$," %s %s",$<str>1,$<str>2);}
	;


group_by_clause:
	GROUP_BY column_specification_list
{sprintf($<str>$," %s %s",$<str>1,$<str>2);}
;

column_specification_list:
	  column_specification
	| column_specification_list COMMA column_specification
{sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);}
	;


where_clause:
	WHERE search_condition {sprintf($<str>$,"WHERE \n0 (%s)\n0",$<str>2);}
	;


from_clause:
	FROM table_reference_list {sprintf($<str>$,"%s %s",$<str>1,$<str>2);}
	;

table_reference_list:
	  table_reference
	| table_reference_list COMMA table_reference
{sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);}
	;

table_reference:
	  tname {sprintf($<str>$," %s ", $<str>1);}
	| OUTER tname {sprintf($<str>$," %s %s ",$<str>1,$<str>2);}
	| OUTER OPEN_BRACKET tname_list  CLOSE_BRACKET {sprintf($<str>$," %s (%s) ",$<str>1,$<str>3);}
	;

tname: table_name
	| table_name correlation_name {
		sprintf($<str>$,"%s %s",$<str>1,$<str>2);
		ace_add_table($<str>1,$<str>2);
		}
;



tname_list : table_reference | tname_list COMMA table_reference { sprintf($<str>$," %s,%s ",$<str>1,$<str>3);  }
;

table_expression:
	from_clause
	op_where_clause
	op_group_by_clause
	op_having_clause 
{
sprintf($<str>$,"%s %s %s %s",
$<str>1,$<str>2,
$<str>3,$<str>4);
}
	;

op_where_clause: /* empty */ {strcpy($<str>$,"\n0");}
	| where_clause
	;

op_group_by_clause: /*empty */ {strcpy($<str>$,"");}
	| group_by_clause
	;

op_having_clause: {strcpy($<str>$,"");}
	| having_clause
	;


search_condition:
	boolean_term
	| search_condition KW_OR boolean_term
{sprintf($<str>$,"%s %s %s",$<str>1,$<str>2,$<str>3);}
	;

boolean_term:
	boolean_factor
	| boolean_term KW_AND boolean_factor
{sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);}
	;

boolean_factor:
	  boolean_primary
	| NOT boolean_primary
{sprintf($<str>$," %s %s",$<str>1,$<str>2);}
	;

boolean_primary:
	  predicate
	| OPEN_BRACKET search_condition CLOSE_BRACKET
{sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);}
	;


exists_predicate:
	EXISTS subquery {sprintf($<str>$," %s %s",$<str>1,$<str>2);}
	| NOT_EXISTS subquery {sprintf($<str>$," %s %s",$<str>1,$<str>2);}
	;


quantified_predicate:
	sql_value_expression comp_op_sql quantifier subquery
{sprintf($<str>$," %s %s %s %s",$<str>1,$<str>2,$<str>3,$<str>4);}
	| subquery comp_op_sql sql_value_expression 
{sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);}
	;

quantifier:
	/*{strcpy($<str>$," ALL ");} 
	|*/
	 all
	| some
	;
all:
	ALL
	;

some:
	  SOME
	| ANY
	;





op_escape:
	ESCAPE escape_character
{sprintf($<str>$," %s %s",$<str>1,$<str>2);}
	;

pattern:
	  value_specification
	;

escape_character:
	  value_specification
	;


in_predicate:
	sql_value_expression IN OPEN_BRACKET in_value_list CLOSE_BRACKET
{sprintf($<str>$," %s %s %s %s %s",$<str>1,$<str>2,$<str>3,$<str>4,$<str>5);}
	| sql_value_expression IN subquery
{sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);}
	| sql_value_expression NOT_IN OPEN_BRACKET in_value_list CLOSE_BRACKET
{sprintf($<str>$," %s %s %s %s %s",$<str>1,$<str>2,$<str>3,$<str>4,$<str>5);}
	| sql_value_expression NOT_IN subquery
{sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);}

	;

in_value_list:
	  value_specification
	| in_value_list COMMA value_specification
{sprintf($<str>$," %s%s%s",$<str>1,$<str>2,$<str>3);}
	;

op_not: {strcpy($<str>$,"");}
	| NOT
	;


comparison_predicate:
	sql_value_expression op_not IS_NULL
		{sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);}
	| sql_value_expression op_not IS_NOT_NULL
		{sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);}
	| sql_value_expression comp_op_sql sql_value_expression
		{sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);}
	| sql_value_expression comp_op_sql subquery
		{sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);}
	| sql_value_expression op_not BETWEEN sql_value_expression KW_AND sql_value_expression
		{sprintf($<str>$," %s %s %s %s %s %s",$<str>1,$<str>2,$<str>3,$<str>4,$<str>5,$<str>6);}

	;

comp_op_sql:
	  EQUAL 
	| COMPARISON
	| NOT_EQUAL
	| LESS_THAN
	| GREATER_THAN 
        | NOT_MATCHES
        | NOT_LIKE
	| MATCHES
	| LIKE
	| LESS_THAN_EQ {sprintf($<str>$,"<=");}
	| GREATER_THAN_EQ {sprintf($<str>$,">=");}
	;


predicate:
	  comparison_predicate
	| in_predicate
	| quantified_predicate
	| exists_predicate
	;
op_all: {strcpy($<str>$,"");}
	| ALL
	| DISTINCT
	| UNIQUE
	;








table_name:
	CHAR_VALUE { sprintf($<str>$," %s",(char *)A4GL_strip_quotes($<str>1)); }
	| table_identifier {sprintf($<str>$,$<str>1); }
	| db_name COLON table_identifier { sprintf($<str>$," %s%s%s",$<str>1,$<str>2,$<str>3);  }
	| CHAR_VALUE DOT table_identifier { sprintf($<str>$,"\\\"%s\\\"%s%s",(char *)A4GL_strip_quotes($<str>1),$<str>2,$<str>3);  }
	

	;


db_name : identifier;


table_identifier:
	identifier {sprintf($<str>$,$<str>1);}
	;


col_arr : {strcpy($<str>$,"");} 
	| OPEN_SQUARE INTVAL CLOSE_SQUARE {sprintf($<str>$,"[%s]",$<str>2);}
	| OPEN_SQUARE INTVAL COMMA INTVAL CLOSE_SQUARE {sprintf($<str>$,"[%s,%s]",$<str>2,$<str>4);}
;

column_name: identifier col_arr { sprintf($<str>$,"%s%s",$<str>1,$<str>2); }
	| table_name  DOT identifier col_arr { sprintf($<str>$,"%s.%s%s",$<str>1,$<str>3,$<str>4); }
	| table_name  DOT MULTIPLY { sprintf($<str>$,"%s.%s",$<str>1,$<str>3); }


	;

correlation_name:
	identifier
	;


real_number :
	NUMBER_VALUE | DOT INTVAL {sprintf($<str>$,"0.%s",$<str>2);}
;

/*
s_curr_v: YEAR {strcpy($<str>$,"0");} | MONTH  {strcpy($<str>$,"5");}| DAY  {strcpy($<str>$,"8");}| HOUR  {strcpy($<str>$,"11");}| MINUTE  {strcpy($<str>$,"14");}| SECOND  {strcpy($<str>$,"17");}| FRACTION {strcpy($<str>$,"23");};
e_curr_v: YEAR {strcpy($<str>$,"4");} | MONTH  {strcpy($<str>$,"7");}| DAY  {strcpy($<str>$,"10");}| HOUR  {strcpy($<str>$,"13");}| MINUTE  {strcpy($<str>$,"16");}| SECOND  {strcpy($<str>$,"19");}| FRACTION {strcpy($<str>$,"25");};
*/
/*
s_curr: YEAR | MONTH | DAY | HOUR | MINUTE | SECOND | FRACTION;
e_curr: YEAR | MONTH | DAY | HOUR | MINUTE | SECOND | FRACTION;
*/



select_statement:
	SELECT {reset_sql_stuff();} op_ad sq_select_list 
	table_expression
        sel_p2 
	{sprintf($<str>$,"%s %s %s %s %s",$<str>1,$<str>3,$<str>4,$<str>5,$<str>6);
}
;

/*
in_select_statement:
	SELECT op_ad sq_select_list table_expression sel_p2 {
             char buff[30000];
             sprintf(buff,"%s %s %s %s %s", $<str>1, $<str>2, $<str>3, $<str>4, $<str>5);
             sprintf($<str>$,"push_char(\"%s\");",buff);
}
;
*/

select_statement2:
	select_statement2_1  ;

select_statement2_1:
	SELECT op_ad sq_select_list 
	table_expression 
        sel_p2
{sprintf($<str>$,"%s %s %s %s %s", $<str>1, $<str>2, $<str>3, $<str>4, $<str>5 );}
;


sel_p2 : {strcpy($<str>$,"");}
| UNION op_all select_statement2 {
       sprintf($<str>$,"%s %s %s",$<str>1,$<str>2,$<str>3);
       }
| order_by_clause 
| INTO TEMP tmp_tabname op_no_log {
       sprintf($<str>$,"INTO TEMP %s%s ",$<str>3,$<str>4);
	strcpy(temp_tab_name,$<str>3);
}
| order_by_clause INTO TEMP tmp_tabname op_no_log {
       sprintf($<str>$,"%s INTO TEMP %s%s ",$<str>1, $<str>4,$<str>5);
	strcpy(temp_tab_name,$<str>3);
}

;


op_no_log: {strcpy($<str>$,"");} | WITH_NO_LOG {strcpy($<str>$," WITH NO LOG");}
;


tmp_tabname: identifier
;
/*
op_into_temp :
{
strcpy($<str>$,"");} | INTO TEMP tmp_tabname op_no_log
{
sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);
strcpy(temp_tab_name,$<str>3);
}
;

*/



subquery:
	OPEN_BRACKET SELECT op_ad sq_select_list table_expression CLOSE_BRACKET
{sprintf($<str>$," %s %s %s %s %s %s",$<str>1,$<str>2,$<str>3,$<str>4,$<str>5,$<str>6);}
	;

op_ad: {strcpy($<str>$,"");}
	| ALL {sprintf($<str>$,"ALL");}
	| DISTINCT {sprintf($<str>$,"DISTINCT");}
	| UNIQUE {sprintf($<str>$,"DISTINCT");}
	;

sq_select_list: 
	value_expression_pls 
	| sq_select_list COMMA value_expression_pls { sprintf($<str>$," %s,%s",$<str>1,$<str>3);}
	;

value_expression_pls : 
		sql_value_expression {
			add_select_column($<str>1,$<str>1);
		}
	| 	sql_value_expression  NAMED {
			sprintf($<str>$," %s %s",$<str>1,$<str>2);
			add_select_column($<str>1,$<str>2);
		}
;


column_specification : sql_value_expression
;

units_qual:
        UNITS_YEAR {sprintf($<str>$,"UNITS YEAR");}
        | UNITS_MONTH {sprintf($<str>$,"UNITS MONTH"); }
        | UNITS_DAY {sprintf($<str>$,"UNITS DAY);"); }
        | UNITS_HOUR {sprintf($<str>$,"UNITS HOUR);"); }
        | UNITS_MINUTE {sprintf($<str>$,"UNITS MINUTE);"); }
        | UNITS_SECOND {sprintf($<str>$,"UNITS SECOND);"); }
;

sql_value_expression:
	sql_value_expression sql_val_expr_next  { sprintf($<str>$,"%s%s", $<str>1,$<str>2); }
	| literal
	| identifier
	| identifier OPEN_SQUARE int_val CLOSE_SQUARE                			{sprintf($<str>$," %s[%s]",$<str>1,$<str>3);}
	| identifier OPEN_SQUARE int_val COMMA int_val CLOSE_SQUARE  			{sprintf($<str>$," %s[%s,%s]",$<str>1,$<str>3,$<str>5);}
	| identifier DOT identifier OPEN_SQUARE int_val CLOSE_SQUARE                	{sprintf($<str>$," %s.%s[%s]",$<str>1,$<str>3,$<str>5);}
	| identifier DOT identifier OPEN_SQUARE int_val COMMA int_val CLOSE_SQUARE  	{sprintf($<str>$," %s.%s[%s,%s]",$<str>1,$<str>3,$<str>5,$<str>7);}
	| DOLLAR identifier {
			if (find_variable($<str>2)==-1) { a4gl_ace_yyerror("Error - undefined variable\n"); }
			sprintf($<str>$,"\n2(%d)",find_variable($<str>2));
			}
	| identifier DOT identifier
			{sprintf($<str>$," %s%s%s",$<str>1,$<str>2,$<str>3);}
	| identifier DOT MULTIPLY
			{sprintf($<str>$," %s%s%s",$<str>1,$<str>2,$<str>3);}
	| KW_TRUE
	| KW_FALSE
	| USER
	| MULTIPLY {sprintf($<str>$," %s ",$<str>1);}
	| OPEN_BRACKET sql_value_expression CLOSE_BRACKET {sprintf($<str>$," %s %s %s",$<str>1,$<str>2,$<str>3);}
	| DATE  OPEN_BRACKET  sql_value_expr_list CLOSE_BRACKET {sprintf($<str>$," %s(%s)",$<str>1,$<str>3);}
	| DAY  OPEN_BRACKET  sql_value_expr_list CLOSE_BRACKET {sprintf($<str>$," %s(%s)",$<str>1,$<str>3);}
	| MONTH  OPEN_BRACKET  sql_value_expr_list CLOSE_BRACKET {sprintf($<str>$," %s(%s)",$<str>1,$<str>3);}
	| YEAR  OPEN_BRACKET  sql_value_expr_list CLOSE_BRACKET {sprintf($<str>$," %s(%s)",$<str>1,$<str>3);}
	| identifier OPEN_BRACKET sql_value_expr_list CLOSE_BRACKET {sprintf($<str>$,"%s(%s)",$<str>1,$<str>3);}
 	/* | COUNT OPEN_BRACKET MULTIPLY CLOSE_BRACKET {sprintf($<str>$," %s %s %s %s",$<str>1,$<str>2,$<str>3,$<str>4);}  */
 	| AVG OPEN_BRACKET op_all sql_value_expression CLOSE_BRACKET
			{sprintf($<str>$," %s %s %s %s %s",$<str>1,$<str>2,$<str>3,$<str>4,$<str>5);}
	| XMAX OPEN_BRACKET op_all sql_value_expression CLOSE_BRACKET
			{sprintf($<str>$," %s %s %s %s %s",$<str>1,$<str>2,$<str>3,$<str>4,$<str>5);}
	| XMIN OPEN_BRACKET op_all sql_value_expression CLOSE_BRACKET
			{sprintf($<str>$," %s %s %s %s %s",$<str>1,$<str>2,$<str>3,$<str>4,$<str>5);}
	| SUM OPEN_BRACKET op_all sql_value_expression CLOSE_BRACKET
			{sprintf($<str>$," %s %s %s %s %s",$<str>1,$<str>2,$<str>3,$<str>4,$<str>5);}
	| COUNT OPEN_BRACKET op_all sql_value_expression CLOSE_BRACKET
			{sprintf($<str>$," %s %s %s %s %s",$<str>1,$<str>2,$<str>3,$<str>4,$<str>5);}
;

sql_val_expr_next: 
	DIVIDE sql_value_expression_s 	{sprintf($<str>$,"/%s",$<str>2);}
	| MOD sql_value_expression_s 	{sprintf($<str>$," MOD %s",$<str>2);}
	| POW sql_value_expression_s 	{sprintf($<str>$," POW %s",$<str>2);}
	| units_qual  			{sprintf($<str>$,"%s",$<str>1);}
	| MULTIPLY sql_value_expression_s 	{sprintf($<str>$,"*%s",$<str>2);}
	| PLUS sql_value_expression_s     	{sprintf($<str>$,"+%s",$<str>2);}
	| MINUS sql_value_expression_s   	{sprintf($<str>$,"-%s",$<str>2);}
;

sql_value_expression_s: op_prefix sql_value_expression { sprintf($<str>$,"%s%s",$<str>1,$<str>2);}
;

op_prefix: {strcpy($<str>$,"");}
	| PLUS  {strcpy($<str>$,"+");}
	| MINUS  {strcpy($<str>$,"-");}
;

sql_value_expr_list : 
	sql_value_expression | sql_value_expr_list COMMA sql_value_expression
{
	sprintf($<str>$,"%s,%s",$<str>1,$<str>3);
}
;

value_specification:
	 literal
	;




/*************************************************************************/
/*                            ACE COMMANDS                               */
/*************************************************************************/


commands:
	command {
		$<commands>$.commands.commands_len=1;
		$<commands>$.commands.commands_val=acl_malloc2(sizeof(struct command));
		COPY($<commands>$.commands.commands_val[0],$<cmd>1);
		} 
	| commands command  {
		COPY($<commands>$,$<commands>1);
		$<commands>$.commands.commands_len++;
		$<commands>$.commands.commands_val=realloc(
		$<commands>$.commands.commands_val,
		$<commands>$.commands.commands_len*sizeof(struct command));
		COPY($<commands>$.commands.commands_val[ $<commands>$.commands.commands_len-1 ],$<cmd>2);
	}
;


command: 
	for_command
	| if_command
	| while_command
	| let_command
	| need_command
	| pause_command
	| skip_command
	| print_command
	| print_file_command
	| call_command
	| XBEGIN commands END {
		$<cmd>$.cmd_type=CMD_BLOCK;
		$<cmd>$.command_u.commands.commands.commands_val=$<commands>2.commands.commands_val;
		$<cmd>$.command_u.commands.commands.commands_len=$<commands>2.commands.commands_len;
	}
;

/*
block_commands: command {
	$<cmd>$.cmd_type=CMD_BLOCK;

	$<cmd>$.command_u.commands.commands.commands_len=1;
	printf("L1= %d\n",$<cmd>$.command_u.commands.commands.commands_len);
	$<cmd>$.command_u.commands.commands.commands_val=acl_malloc2(sizeof(struct command));

	COPY($<cmd>$.command_u.commands.commands.commands_val[0],$<cmd>1);

	}
	| block_commands command {
	COPY($<cmd>$,$<cmd>1);
	$<cmd>$.command_u.commands.commands.commands_len++;
	printf("L2= %d\n",$<cmd>$.command_u.commands.commands.commands_len);

	$<cmd>$.command_u.commands.commands.commands_val=realloc(
		$<cmd>$.command_u.commands.commands.commands_val,
		sizeof(struct command)* 
		$<cmd>$.command_u.commands.commands.commands_len
	);

	COPY($<cmd>$.command_u.commands.commands.commands_val[
		$<cmd>$.command_u.commands.commands.commands_len-1],$<cmd>2);

}
;
*/


call_command :  KW_CALL func_identifier OPEN_BRACKET op_fmt_val_expr_list CLOSE_BRACKET {
		$<cmd>$.cmd_type=CMD_CALL;
		$<cmd>$.command_u.cmd_call.fcall=acl_malloc2(sizeof(struct expr_call));
                $<cmd>$.command_u.cmd_call.fcall->fname=acl_strdup($<str>2);
	
                $<cmd>$.command_u.cmd_call.fcall->lexpr=$<expr>4.expr_u.lexpr;
		print_lexpr( $<cmd>$.command_u.cmd_call.fcall->lexpr);
}
;


func_identifier: DATE 
	| MONTH	
	| YEAR
	| DAY
	| identifier
;
for_command:
	FOR variable EQUAL fmt_val_expression TO fmt_val_expression op_step DO command {
		$<cmd>$.cmd_type=CMD_FOR;
		$<cmd>$.command_u.cmd_for.varid=find_variable($<str>2);
		COPY($<cmd>$.command_u.cmd_for.start,$<expr>4);
		COPY($<cmd>$.command_u.cmd_for.finish,$<expr>6);
		COPY($<cmd>$.command_u.cmd_for.step,$<expr>7);
	}
;

op_step : { $<expr>$.type=EXPRTYPE_INT; $<expr>$.expr_u.i=1; }
	| STEP fmt_val_expression { COPY($<expr>$,$<expr>1);}
;


if_command: IF fmt_val_expression THEN command op_else {
	$<cmd>$.cmd_type=CMD_IF;
	COPY($<cmd>$.command_u.cmd_if.condition,$<expr>2);
	$<cmd>$.command_u.cmd_if.command=(struct command *)DUP($<cmd>4);
	$<cmd>$.command_u.cmd_if.elsecommand=(struct command *)DUP($<cmd>5);
}
;

op_else : {
		$<cmd>$.cmd_type=CMD_NULL;
		$<cmd>$.command_u.null=1;
	} | ELSE command { COPY($<cmd>$,$<cmd>2); }
;


let_command: 
LET NAMED EQUAL expr_concat {
		int v;
		$<cmd>$.cmd_type=CMD_LET;
		v=find_variable($<str>2);
		$<cmd>$.command_u.cmd_let.varid=v;
		$<cmd>$.command_u.cmd_let.value=DUP($<expr>4);
		$<cmd>$.command_u.cmd_let.sub1=0;
		$<cmd>$.command_u.cmd_let.sub2=0; 
	}

|
LET NAMED OPEN_SQUARE fmt_val_expression CLOSE_SQUARE EQUAL expr_concat {
		int v;
		$<cmd>$.cmd_type=CMD_LET;
		v=find_variable($<str>2);
		$<cmd>$.command_u.cmd_let.varid=v;
		$<cmd>$.command_u.cmd_let.value=DUP($<expr>7);
		$<cmd>$.command_u.cmd_let.sub1=DUP($<expr>4); 
		$<cmd>$.command_u.cmd_let.sub2=0;
	}

|
LET NAMED OPEN_SQUARE fmt_val_expression COMMA fmt_val_expression CLOSE_SQUARE EQUAL expr_concat {
		int v;
		$<cmd>$.cmd_type=CMD_LET;
		v=find_variable($<str>2);
		$<cmd>$.command_u.cmd_let.varid=v;
		$<cmd>$.command_u.cmd_let.value=DUP($<expr>9);
		$<cmd>$.command_u.cmd_let.sub1=DUP($<expr>4); 
		$<cmd>$.command_u.cmd_let.sub2=DUP($<expr>6); 
	}


;

op_expr_concat : {
		$<expr>$.type=EXPRTYPE_STRING;
		$<expr>$.expr_u.s=acl_strdup("");
		}
	| expr_concat 
;

expr_concat: fmt_val_expression | expr_concat COMMA fmt_val_expression {

	$<expr>$.type=EXPRTYPE_COMPLEX;
	$<expr>$.expr_u.expr=acl_malloc2(sizeof(struct complex_expr));
	COPY($<expr>$.expr_u.expr->expr1,$<expr>1);
	COPY($<expr>$.expr_u.expr->expr2,$<expr>3);
	$<expr>$.expr_u.expr->operand=EXPR_CONCAT;

	}
	
;

need_command: NEED int_val LINES {
	$<cmd>$.cmd_type=CMD_NEED;
	$<cmd>$.command_u.cmd_need.nlines=atoi($<str>2);
}
;

pause_command: PAUSE string {
	$<cmd>$.cmd_type=CMD_PAUSE;
	$<cmd>$.command_u.cmd_pause.message=acl_strdup($<str>2);
}
;


print_command: PRINT op_expr_concat op_semi  {
	$<cmd>$.cmd_type=CMD_PRINT;
	$<cmd>$.command_u.cmd_print.printnl=atoi($<str>3);
	$<cmd>$.command_u.cmd_print.print=$<expr>2;
}

;

op_semi: {strcpy($<str>$,"1");} | SEMICOLON {strcpy($<str>$,"0");}
;

print_file_command: PRINT_FILE string {
	$<cmd>$.cmd_type=CMD_PRINTFILE;
	$<cmd>$.command_u.cmd_printfile.filename=acl_strdup($<str>2);
}
;

skip_command : SKIP int_val LINES {
		$<cmd>$.cmd_type=CMD_SKIP;
		$<cmd>$.command_u.cmd_skip.nlines=atoi($<str>2);

	}
	| SKIP TO TOP_OF_PAGE {
		$<cmd>$.cmd_type=CMD_SKIP;
		$<cmd>$.command_u.cmd_skip.nlines=-1;
	}
;


while_command: WHILE fmt_val_expression DO command {
		$<cmd>$.cmd_type=CMD_WHILE;
		COPY($<cmd>$.command_u.cmd_while.condition,$<expr>2);
		$<cmd>$.command_u.cmd_while.command=(struct command *)DUP($<cmd>4);
}
;

/*****************************************************************************/

int_val: INTVAL
;

string: CHAR_VALUE
;


identifier: NAMED
| reserved_word
;


reserved_word:
 AFTER 

| ASC
| AFTGROUP

| BEFORE
| BETWEEN
| BOTTOM
| BY
| KW_CALL
| CH
| CHAR
| CLIPPED
| COLUMN
| COMMANDS
| COMPARISON
| DATABASE
| DATETIME
| DECIMAL
| DEFINE
| DELIMITER
| DESC
| DO
| ELSE
| ESCAPE
| EVERY
| EXTERNAL
| FIRST 
| FLOAT
| FOR
| FORMAT
| FRACTION
| FROM
| FUNCTION
| GROUP
| HEADER
| HOUR
| IF
| IN
| INPUT
| LAST
| LEFT
| LENGTH
| LET
| LIKE
| LINES
| MARGIN
| MINUTE
| MONEY
| NEED
| KW_OF 
| ON
| OUTPUT
| PAGE
| PARAM
| PAUSE
| POW
| PRINTER
| PROMPT
| READ
| REPORT
| RIGHT
| ROW
| SECOND
| SKIP
| SMALLFLOAT
| SMALLINT
| SPACES
| STEP
| TEMP
| THEN
| TO
| TOP
| TOTAL
| TRAILER
| UPDATE
| VARCHAR
| VARIABLE
| WHILE
| XBEGIN


;



op_where_agg:  	{
			$<exprptr>$=0;
		}
	| WHERE fmt_val_expression 
		{ 
			$<exprptr>$=DUP($<expr>2); 
		}
;


aggregate: aggregate_elem  op_where_agg 	
		{
		COPY($<agg_val>$,$<agg_val>1);
		$<agg_val>$.wexpr=$<exprptr>2; 
		}
;


of_expr: 
		KW_OF fmt_val_expression {
			$<exprptr>$=DUP($<expr>2);
	}
;

aggregate_elem:
	COUNT  {
		$<agg_val>$.type=AGG_COUNT;
		$<agg_val>$.wexpr=0;
		$<agg_val>$.expr=0;
		$<agg_val>$.isgroup=0;
	}
	| PERCENT {
		$<agg_val>$.type=AGG_PERCENT;
		$<agg_val>$.wexpr=0;
		$<agg_val>$.expr=0;
		$<agg_val>$.isgroup=0;
	}
 	| AVERAGE of_expr {
		$<agg_val>$.type=AGG_AVG;
		$<agg_val>$.wexpr=0;
		$<agg_val>$.expr=$<exprptr>2;
		$<agg_val>$.isgroup=0;
	}
	| TOTAL of_expr {
		$<agg_val>$.type=AGG_TOTAL;
		$<agg_val>$.wexpr=0;
		$<agg_val>$.expr=$<exprptr>2;
		$<agg_val>$.isgroup=0;
	}
	| AVG of_expr {
		$<agg_val>$.type=AGG_AVG;
		$<agg_val>$.wexpr=0;
		$<agg_val>$.expr=$<exprptr>2;
		$<agg_val>$.isgroup=0;
	}
	| XMIN of_expr {
		$<agg_val>$.type=AGG_MIN;
		$<agg_val>$.wexpr=0;
		$<agg_val>$.expr=$<exprptr>2;
		$<agg_val>$.isgroup=0;
	}
	| XMAX of_expr {
		$<agg_val>$.type=AGG_MAX;
		$<agg_val>$.wexpr=0;
		$<agg_val>$.expr=$<exprptr>2;
		$<agg_val>$.isgroup=0;
	}

	| GROUP COUNT  {
		$<agg_val>$.type=AGG_COUNT;
		$<agg_val>$.isgroup=1;
		$<agg_val>$.wexpr=0;
		$<agg_val>$.expr=0;
	}
	| GROUP PERCENT {
		$<agg_val>$.type=AGG_PERCENT;
		$<agg_val>$.isgroup=1;
		$<agg_val>$.wexpr=0;
		$<agg_val>$.expr=0;
	}
 	| GROUP AVERAGE of_expr {
		$<agg_val>$.type=AGG_AVG;
		$<agg_val>$.isgroup=1;
		$<agg_val>$.wexpr=0;
		$<agg_val>$.expr=$<exprptr>3;
	}
	| GROUP TOTAL of_expr {
		$<agg_val>$.type=AGG_TOTAL;
		$<agg_val>$.wexpr=0;
		$<agg_val>$.isgroup=1;
		$<agg_val>$.expr=$<exprptr>3;
	}
	| GROUP AVG of_expr {
		$<agg_val>$.type=AGG_AVG;
		$<agg_val>$.wexpr=0;
		$<agg_val>$.isgroup=1;
		$<agg_val>$.expr=$<exprptr>3;
	}
	| GROUP XMIN of_expr {
		$<agg_val>$.type=AGG_MIN;
		$<agg_val>$.wexpr=0;
		$<agg_val>$.isgroup=1;
		$<agg_val>$.expr=$<exprptr>3;
	}
	| GROUP XMAX of_expr {
		$<agg_val>$.type=AGG_MAX;
		$<agg_val>$.wexpr=0;
		$<agg_val>$.isgroup=1;
		$<agg_val>$.expr=$<exprptr>3;
	}
;

fmt_val_expression:
	 MINUS fmt_val_expression  {
		switch ( $<expr>2.type) {
			case EXPRTYPE_DOUBLE:
					COPY($<expr>$,$<expr>2); 
					$<expr>$.expr_u.d=0.0-$<expr>$.expr_u.d;
					break;
			case EXPRTYPE_INT:
					COPY($<expr>$,$<expr>2); 
					$<expr>$.expr_u.i=0-$<expr>$.expr_u.i;
					break;
			default : 
					$<expr>$.type=EXPRTYPE_COMPLEX;
					$<expr>$.expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
					set_expr_int(&$<expr>$.expr_u.expr->expr1, 0);
					COPY($<expr>$.expr_u.expr->expr2,$<expr>2); 
					$<expr>$.expr_u.expr->operand=EXPR_SUB; 
		}
	}
	| literal_expr { COPY($<expr>$,$<expr>1); }

	| KW_TRUE {
		$<expr>$.type=EXPRTYPE_INT;
		$<expr>$.expr_u.i=1;
		}
	| KW_FALSE {
		$<expr>$.type=EXPRTYPE_INT;
		$<expr>$.expr_u.i=0;
		}
	| USER {
		$<expr>$.type=EXPRTYPE_BUILTIN;
		$<expr>$.expr_u.name=acl_strdup($<str>1);
	}
	| DATE {
		int v;
		v=find_variable("date");
		$<expr>$.type=EXPRTYPE_VARIABLE;
		if (v==-1) {
			printf("Warning : %s is not a defined variable\n",$<str>1);
		} 
		$<expr>$.expr_u.varid=v;
	}
	| TIME {
		int v;
		v=find_variable("time");
		$<expr>$.type=EXPRTYPE_VARIABLE;
		if (v==-1) {
			printf("Warning : %s is not a defined variable\n",$<str>1);
		} 
		$<expr>$.expr_u.varid=v;
	}

	| DATE  OPEN_BRACKET  fmt_val_expr_list CLOSE_BRACKET {
		$<expr>$.type=EXPRTYPE_FCALL; 
		$<expr>$.expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		$<expr>$.expr_u.fcall->fname=acl_strdup("DATE");
                $<cmd>$.command_u.cmd_call.fcall->lexpr=$<expr>3.expr_u.lexpr;
	}

	| MONTH  OPEN_BRACKET  fmt_val_expr_list CLOSE_BRACKET {
		$<expr>$.type=EXPRTYPE_FCALL; 
		$<expr>$.expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		$<expr>$.expr_u.fcall->fname=acl_strdup("MONTH");
                $<cmd>$.command_u.cmd_call.fcall->lexpr=$<expr>3.expr_u.lexpr;
	}
	| YEAR  OPEN_BRACKET  fmt_val_expr_list CLOSE_BRACKET {
		$<expr>$.type=EXPRTYPE_FCALL; 
		$<expr>$.expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		$<expr>$.expr_u.fcall->fname=acl_strdup("YEAR");
                $<cmd>$.command_u.cmd_call.fcall->lexpr=$<expr>3.expr_u.lexpr;
	}
	| DAY  OPEN_BRACKET  fmt_val_expr_list CLOSE_BRACKET {
		$<expr>$.type=EXPRTYPE_FCALL; 
		$<expr>$.expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		$<expr>$.expr_u.fcall->fname=acl_strdup("DAY");
                $<cmd>$.command_u.cmd_call.fcall->lexpr=$<expr>3.expr_u.lexpr;
	}

	| NAMED OPEN_BRACKET fmt_val_expr_list CLOSE_BRACKET {
		$<expr>$.type=EXPRTYPE_FCALL; 
		$<expr>$.expr_u.fcall=acl_malloc2(sizeof(struct expr_call));
		$<expr>$.expr_u.fcall->fname=acl_strdup($<str>1);
                $<cmd>$.command_u.cmd_call.fcall->lexpr=$<expr>3.expr_u.lexpr;
	}
	| OPEN_BRACKET fmt_val_expression CLOSE_BRACKET { COPY($<expr>$,$<expr>2); }
	| COLUMN fmt_val_expression {
		$<expr>$.type=EXPRTYPE_SIMPLE; 
		$<expr>$.expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY($<expr>$.expr_u.sexpr->expr,$<expr>2); 
		$<expr>$.expr_u.sexpr->operand=EXPR_COLUMN; 
	}
	| ASCII fmt_val_expression {
		$<expr>$.type=EXPRTYPE_SIMPLE; 
		$<expr>$.expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		COPY($<expr>$.expr_u.sexpr->expr,$<expr>2); 
		$<expr>$.expr_u.sexpr->operand=EXPR_ASCII; 
	}
	| variable_sub {
		$<expr>$.type=EXPRTYPE_VARIABLE_SUB;
		$<expr>$.expr_u.var_usage=$<var_usage>1;
	}

	| aggregate {
		$<expr>$.type=EXPRTYPE_AGG; 
		$<expr>$.expr_u.aggid=add_agg($<agg_val>1);
	}

 	| fmt_val_expression val_next {
		struct expr *e1;
		COPY($<expr>$,$<expr>2);
		if ( $<expr>$.type==EXPRTYPE_SIMPLE)  {
		  	COPY($<expr>$.expr_u.sexpr->expr,$<expr>1); 
		} else {
			if ( $<expr>$.type==EXPRTYPE_COMPLEX ) {
				COPY($<expr>$.expr_u.expr->expr1,$<expr>1); 
			} else {
				if ($<expr>$.type==EXPRTYPE_COMPARE)  {
				COPY($<expr>$.expr_u.cexpr->expr1,$<expr>1); 

				} else {
					printf("BAD -> %d\n", $<expr>$.type);
				}
			}
		}
		e1=&$<expr>$;
	}
;


val_next : 
	KW_AND fmt_val_expression { 
		$<expr>$.type=EXPRTYPE_COMPLEX; 
		$<expr>$.expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY($<expr>$.expr_u.expr->expr2,$<expr>2); 
		$<expr>$.expr_u.expr->operand=EXPR_AND; 
	}

	| KW_OR fmt_val_expression { 
		$<expr>$.type=EXPRTYPE_COMPLEX; 
		$<expr>$.expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1); */
		COPY($<expr>$.expr_u.expr->expr2,$<expr>2); 
		$<expr>$.expr_u.expr->operand=EXPR_OR; 
	}
	| DIVIDE fmt_val_expression 
		{ 
		$<expr>$.type=EXPRTYPE_COMPLEX; $<expr>$.expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY($<expr>$.expr_u.expr->expr2,$<expr>2); 
		$<expr>$.expr_u.expr->operand=EXPR_DIV; 
		}

	 | POW fmt_val_expression 
		{ 
		$<expr>$.type=EXPRTYPE_COMPLEX; $<expr>$.expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY($<expr>$.expr_u.expr->expr2,$<expr>2); 
		$<expr>$.expr_u.expr->operand=EXPR_POW; 
		}
	 | MOD fmt_val_expression 
		{ 
		$<expr>$.type=EXPRTYPE_COMPLEX; $<expr>$.expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY($<expr>$.expr_u.expr->expr2,$<expr>2); 
		$<expr>$.expr_u.expr->operand=EXPR_MOD; 
		}


	| MULTIPLY fmt_val_expression
		{ 
		$<expr>$.type=EXPRTYPE_COMPLEX; $<expr>$.expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY($<expr>$.expr_u.expr->expr2,$<expr>2); 
		$<expr>$.expr_u.expr->operand=EXPR_MUL; 
		}
	| PLUS fmt_val_expression { 
		$<expr>$.type=EXPRTYPE_COMPLEX; 
		$<expr>$.expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/* COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY($<expr>$.expr_u.expr->expr2,$<expr>2); 
		$<expr>$.expr_u.expr->operand=EXPR_ADD; 
	}


	| MINUS fmt_val_expression { 
		$<expr>$.type=EXPRTYPE_COMPLEX;
		$<expr>$.expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1);  */
		COPY($<expr>$.expr_u.expr->expr2,$<expr>2); 
		$<expr>$.expr_u.expr->operand=EXPR_SUB; 
	}
	|  USING fmt_val_expression { 
		$<expr>$.type=EXPRTYPE_COMPLEX;
		$<expr>$.expr_u.expr=acl_malloc2(sizeof(struct complex_expr)); 
		/*COPY($<expr>$.expr_u.expr->expr1,$<expr>1); */
		COPY($<expr>$.expr_u.expr->expr2,$<expr>2); 
		$<expr>$.expr_u.expr->operand=EXPR_USING; 
	}

	| EQUAL  fmt_val_expression {
		$<expr>$.type=EXPRTYPE_COMPARE;
		$<expr>$.expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY($<expr>$.expr_u.cexpr->expr2,$<expr>2); 
		$<expr>$.expr_u.cexpr->method=acl_strdup($<str>1); 
		}
	| COMPARISON fmt_val_expression {
		$<expr>$.type=EXPRTYPE_COMPARE;
		$<expr>$.expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY($<expr>$.expr_u.cexpr->expr2,$<expr>2); 
		$<expr>$.expr_u.cexpr->method=acl_strdup($<str>1); 
		}
	| NOT_EQUAL fmt_val_expression {
		$<expr>$.type=EXPRTYPE_COMPARE;
		$<expr>$.expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY($<expr>$.expr_u.cexpr->expr2,$<expr>2); 
		$<expr>$.expr_u.cexpr->method=acl_strdup($<str>1); 
		}
	| LESS_THAN fmt_val_expression {
		$<expr>$.type=EXPRTYPE_COMPARE;
		$<expr>$.expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY($<expr>$.expr_u.cexpr->expr2,$<expr>2); 
		$<expr>$.expr_u.cexpr->method=acl_strdup($<str>1); 
		}
	| GREATER_THAN fmt_val_expression {
		$<expr>$.type=EXPRTYPE_COMPARE;
		$<expr>$.expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY($<expr>$.expr_u.cexpr->expr2,$<expr>2); 
		$<expr>$.expr_u.cexpr->method=acl_strdup($<str>1); 
		}
        | NOT_MATCHES fmt_val_expression {
		$<expr>$.type=EXPRTYPE_COMPARE;
		$<expr>$.expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY($<expr>$.expr_u.cexpr->expr2,$<expr>2); 
		$<expr>$.expr_u.cexpr->method=acl_strdup($<str>1); 
		}
        | NOT_LIKE fmt_val_expression {
		$<expr>$.type=EXPRTYPE_COMPARE;
		$<expr>$.expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY($<expr>$.expr_u.cexpr->expr2,$<expr>2); 
		$<expr>$.expr_u.cexpr->method=acl_strdup($<str>1); 
		}
	| MATCHES fmt_val_expression {
		$<expr>$.type=EXPRTYPE_COMPARE;
		$<expr>$.expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY($<expr>$.expr_u.cexpr->expr2,$<expr>2); 
		$<expr>$.expr_u.cexpr->method=acl_strdup($<str>1); 
		}
	| LIKE fmt_val_expression {
		$<expr>$.type=EXPRTYPE_COMPARE;
		$<expr>$.expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY($<expr>$.expr_u.cexpr->expr2,$<expr>2); 
		$<expr>$.expr_u.cexpr->method=acl_strdup($<str>1); 
		}
	| LESS_THAN_EQ fmt_val_expression {
		$<expr>$.type=EXPRTYPE_COMPARE;
		$<expr>$.expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY($<expr>$.expr_u.cexpr->expr2,$<expr>2); 
		$<expr>$.expr_u.cexpr->method=acl_strdup($<str>1); 
		}
	| GREATER_THAN_EQ fmt_val_expression {
		$<expr>$.type=EXPRTYPE_COMPARE;
		$<expr>$.expr_u.cexpr=acl_malloc2(sizeof(struct complex_expr)); 
		COPY($<expr>$.expr_u.cexpr->expr2,$<expr>2); 
		$<expr>$.expr_u.cexpr->method=acl_strdup($<str>1); 
		}
	

	| SPACES  {
		$<expr>$.type=EXPRTYPE_SIMPLE; 
		$<expr>$.expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/*COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		$<expr>$.expr_u.sexpr->operand=EXPR_SPACES; 
	}

	| IS_NULL  {
		$<expr>$.type=EXPRTYPE_SIMPLE; 
		$<expr>$.expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr)); 
		/*COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		$<expr>$.expr_u.sexpr->operand=EXPR_ISNULL; 
	}
	| IS_NOT_NULL  {
		$<expr>$.type=EXPRTYPE_SIMPLE; 
		$<expr>$.expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/* COPY($<expr>$.expr_u.sexpr->expr,$<expr>1); */
		$<expr>$.expr_u.sexpr->operand=EXPR_ISNOTNULL; 
	}


	| CLIPPED  {
		$<expr>$.type=EXPRTYPE_SIMPLE; 
		$<expr>$.expr_u.sexpr=acl_malloc2(sizeof(struct simple_expr));  
		/* COPY($<expr>$.expr_u.sexpr->expr,$<expr>1);  */
		$<expr>$.expr_u.sexpr->operand=EXPR_CLIP; 
	}
/*
        | UNITS_YEAR {
		sprintf($<str>$,"UNITS YEAR");
		A4GL_assertion(1,"NIY"); }
        | UNITS_MONTH {sprintf($<str>$,"UNITS MONTH"); 
		A4GL_assertion(1,"NIY"); }
        | UNITS_DAY {sprintf($<str>$,"UNITS DAY);"); 
		A4GL_assertion(1,"NIY"); }
        | UNITS_HOUR {sprintf($<str>$,"UNITS HOUR);"); 
		A4GL_assertion(1,"NIY"); }
        | UNITS_MINUTE {sprintf($<str>$,"UNITS MINUTE);");
		A4GL_assertion(1,"NIY"); }
        | UNITS_SECOND {sprintf($<str>$,"UNITS SECOND);"); 
		A4GL_assertion(1,"NIY"); }
*/
;


/*
	| units_qual {
		printf("NIY\n");
		A4GL_assertion(1,"NIY");
		//sprintf($<str>$," %s %s",$<str>1,$<str>2);
		}
;
*/

op_fmt_val_expr_list : null_expr {
		$<expr>$.type=EXPRTYPE_LIST;
		$<expr>$.expr_u.lexpr=acl_malloc2(sizeof(struct expr_list));
		$<expr>$.expr_u.lexpr->elem.elem_len=1;
		$<expr>$.expr_u.lexpr->elem.elem_val=0;
		$<expr>$.expr_u.lexpr->elem.elem_val=realloc(
			$<expr>$.expr_u.lexpr->elem.elem_val,
			sizeof(struct expr)*$<expr>$.expr_u.lexpr->elem.elem_len);
		COPY($<expr>$.expr_u.lexpr->elem.elem_val[0],$<expr>1);
		print_lexpr($<expr>$.expr_u.lexpr);
	} 
	| fmt_val_expr_list {
		COPY($<expr>$,$<expr>1);
	}
;


fmt_val_expr_list : 
	fmt_val_expression {
		$<expr>$.type=EXPRTYPE_LIST;
		$<expr>$.expr_u.lexpr=acl_malloc2(sizeof(struct expr_list));
		$<expr>$.expr_u.lexpr->elem.elem_len=1;
		$<expr>$.expr_u.lexpr->elem.elem_val=0;
		$<expr>$.expr_u.lexpr->elem.elem_val=realloc( $<expr>$.expr_u.lexpr->elem.elem_val,sizeof(struct expr)* $<expr>$.expr_u.lexpr->elem.elem_len);
		COPY($<expr>$.expr_u.lexpr->elem.elem_val[0],$<expr>1);
	} | fmt_val_expr_list COMMA fmt_val_expression {
		COPY($<expr>$,$<expr>1);
		$<expr>$.expr_u.lexpr->elem.elem_len++;
		$<expr>$.expr_u.lexpr->elem.elem_val=realloc( $<expr>$.expr_u.lexpr->elem.elem_val,sizeof(struct expr)* $<expr>$.expr_u.lexpr->elem.elem_len);
		COPY($<expr>$.expr_u.lexpr->elem.elem_val[ $<expr>$.expr_u.lexpr->elem.elem_len-1 ],$<expr>3);

	}

;
null_expr : {
		$<expr>$.type=EXPRTYPE_NULL;
	}
;


literal_expr: CHAR_VALUE {
		$<expr>$.type=EXPRTYPE_STRING;
		$<expr>$.expr_u.s=acl_strdup($<str>1);
	}
	| NUMERIC {
		$<expr>$.type=EXPRTYPE_DOUBLE;
		$<expr>$.expr_u.d=atof($<str>1);
	}
	| real_number {
		$<expr>$.type=EXPRTYPE_DOUBLE;
		$<expr>$.expr_u.d=atof($<str>1);
	}
	| INTVAL {
		$<expr>$.type=EXPRTYPE_INT;
		$<expr>$.expr_u.i=atoi($<str>1);
	}
/*
	| PLUS real_number {
		$<expr>$.type=EXPRTYPE_DOUBLE;
		$<expr>$.expr_u.d=atof($<str>2);
	}
	| PLUS INTVAL {
		$<expr>$.type=EXPRTYPE_INT;
		$<expr>$.expr_u.i=atoi($<str>2);
	}
	| MINUS real_number {
		$<expr>$.type=EXPRTYPE_DOUBLE;
		$<expr>$.expr_u.d=0-atof($<str>2);
	}
	| MINUS INTVAL {
		$<expr>$.type=EXPRTYPE_INT;
		$<expr>$.expr_u.i=0-atoi($<str>2);
	}
*/

;


%%

#ifdef PREGEN
#include "ace/lex.yy.c"
#else
#include "lex.yy.c"
#endif
