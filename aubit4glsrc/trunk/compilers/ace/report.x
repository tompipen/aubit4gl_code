/* 
Data definitions for a report 
*/

const AACE_XDR_VERSION = 100;
const AACE_XDR_MAGIC = 0xa4ac1234;



enum cmdtypes {
	CMD_NULL,
	CMD_FOR,
	CMD_IF,
	CMD_WHILE,
	CMD_LET,
	CMD_NEED,
	CMD_SKIP,
	CMD_PAUSE,
	CMD_PRINT,
	CMD_PRINTFILE,
	CMD_BLOCK,
	CMD_CALL
};

enum varcats {
	CAT_NULL,
	CAT_INTERNAL, /* Counters for aggregates */
	CAT_PARAM,
	CAT_VARIABLE,
	CAT_SQL,
	CAT_FUNCTION,
	CAT_BUILTIN
};


enum aggtypes {
	AGG_COUNT,
	AGG_PERCENT,
	AGG_AVG,
	AGG_TOTAL,
	AGG_MIN,
	AGG_MAX
};



enum expr_operands {
	EXPR_AND,
	EXPR_OR,

	EXPR_ADD,
	EXPR_SUB,
	EXPR_MUL,
	EXPR_DIV,
	EXPR_POW,

	EXPR_CLIP,
	EXPR_USING,
	EXPR_COLUMN,
	EXPR_SPACES,
	EXPR_CONCAT,
	EXPR_ISNULL,
	EXPR_ISNOTNULL,
	EXPR_ASCII,
	EXPR_POSITION

};

enum exprtype {
	EXPRTYPE_NULL,
	EXPRTYPE_INT,
	EXPRTYPE_DOUBLE,
	EXPRTYPE_STRING,
	EXPRTYPE_VARIABLE,
	EXPRTYPE_BUILTIN,
	EXPRTYPE_COMPLEX,
	EXPRTYPE_SIMPLE,
	EXPRTYPE_LIST,
	EXPRTYPE_COMPARE,
	EXPRTYPE_FCALL,
	EXPRTYPE_AGG

};

/*
struct agg_val {
	enum aggtypes type;
	bool isgroup;
	struct expr *expr;
	struct expr *wexpr; 
};
*/

union expr switch (exprtype type) {
	case EXPRTYPE_NULL: 	int null;
	case EXPRTYPE_INT: 	int i;
	case EXPRTYPE_DOUBLE:    double d;
	case EXPRTYPE_STRING:    string s<>;
	case EXPRTYPE_VARIABLE:  int varid;
	case EXPRTYPE_BUILTIN:   string name<>; 
	case EXPRTYPE_COMPLEX:   struct complex_expr  *expr;
	case EXPRTYPE_COMPARE:   struct compare_expr  *cexpr;
	case EXPRTYPE_SIMPLE:    struct simple_expr  *sexpr;
	case EXPRTYPE_LIST:   	 struct expr_list  *lexpr;
	case EXPRTYPE_FCALL:   	 struct expr_call  *fcall;

	/* case EXPRTYPE_AGG:    	 struct agg_val  *aggval; */

	case EXPRTYPE_AGG:    	 int aggid;
};



	
struct expr_list {
	struct expr elem<>;
};

struct expr_call {
	string fname<>;
	struct expr_list *lexpr;
};


struct complex_expr {
	struct expr expr1;
	enum expr_operands operand;
	struct expr expr2;
};

struct compare_expr {
	string method<>;
	struct expr expr1;
	struct expr expr2;
};

struct simple_expr {
	struct expr expr;
	enum expr_operands operand;
};


struct variable {
	string name<>;
	string datatype_string<>;
	int category;
	int param_no;
	int datatype;
	int dim;
	int dataspace;
};

struct ascii {
	struct variable variables<>;
};
	
struct input_vals {
	string prompt<>;
	string variable_name<>;
	int varid;
};

struct output {
	int right_margin;
	int top_margin;
	int left_margin;
	int bottom_margin;
	int page_length;
	string top_of_page<>;
	int report_to_where;
	string report_to_filename<>;
};


struct select_stmts {
	string statement<>;
	int has_where;
	int wherepos1;
	int wherepos2;
	int varids<>;
	int varpos<>;
	string temp_tab_name<>;
	int orderby_list<>;
};


struct read_stmt {
	string filename<>;
	string delimiters<>;
	string orderby<>; /* FIXME */
};

union get_data switch(int select_or_read) {
	case 0:struct select_stmts selects<>;
	case 1:struct read_stmt read_data;
	
};


struct cmd_for {
	int varid;
	struct expr start;
	struct expr finish;
	struct expr step;
	struct command *command;
};

struct cmd_if {
	struct expr condition;
	struct command *command;
	struct command *elsecommand;

};

struct cmd_call {
	struct expr_call *fcall;
};

struct cmd_while {
	struct expr condition;
	struct command *command;
};

struct cmd_let {
	int varid;
	struct expr value;
	struct expr sub1;
	struct expr sub2;
};

struct cmd_need {
	int nlines;
};

struct cmd_pause {
	string message<>;
};

struct cmd_skip {
	int nlines; /* -1 = top of page */
};

struct cmd_print {
	struct expr print;
	int printnl;
};


struct cmd_printfile {
	string filename<>;
};


struct function {
	string name<>;
};

struct commands {
	struct command commands<>;
};

union command  switch (cmdtypes cmd_type) {
	case CMD_NULL   :       int null;
	case CMD_FOR	: 	struct cmd_for cmd_for;
	case CMD_IF	: 	struct cmd_if cmd_if;
	case CMD_WHILE	: 	struct cmd_while cmd_while;
	case CMD_LET	: 	struct cmd_let cmd_let;
	case CMD_NEED	:	struct cmd_need cmd_need;
	case CMD_PAUSE	:	struct cmd_pause cmd_pause;
	case CMD_SKIP	:	struct cmd_skip cmd_skip;
	case CMD_PRINT	:	struct cmd_print cmd_print;
	case CMD_PRINTFILE: 	struct cmd_printfile cmd_printfile;
	case CMD_BLOCK	: 	struct commands commands;
	case CMD_CALL	: 	struct cmd_call cmd_call;
};

enum formattype {
	FORMAT_PAGE_HEADER,
	FORMAT_FIRST_PAGE_HEADER,
	FORMAT_PAGE_TRAILER,
	FORMAT_EVERY_ROW,
	FORMAT_ON_EVERY_ROW,
	FORMAT_BEFORE_GROUP,
	FORMAT_AFTER_GROUP,
	FORMAT_ON_LAST_ROW
};
	

struct  format  {
	enum formattype category;
	string column<>;
	struct commands commands; 
};
	

struct agg_val {
	int format_id;       /* Format ID where aggregate is being used */
	enum aggtypes type;  /* Type - SUM/AVG etc */
	bool isgroup;        /* Is it a GROUP SUM/AVG etc */
	struct expr *expr;   /* Expression to aggregate */
	struct expr *wexpr;  /* Where clause to use (if applicable else 0)  */
};


struct report {
	string magic<>;
	string report_name<>;
	string dbname<>;
	struct ascii ascii;
	struct function functions<>;
	struct variable variables<>;
	struct input_vals inputs<>;
	struct output output;
	struct get_data getdata;
	struct format fmt<>;
	struct agg_val aggs<>;
};

