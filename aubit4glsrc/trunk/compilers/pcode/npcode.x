const FGLC_XDR_VERSION = 100;
const FGLC_XDR_MAGIC = 0xa4fc2345;


struct vstring {
	string s<>;
	int rcnt;
	
};


enum cmd_type {
	CMD_NULL, /* NOT USED */
	CMD_BLOCK,
	CMD_END_BLOCK,
	CMD_CALL,
	CMD_IF,
	CMD_SET_VAR,
	CMD_SET_VAR_ONCE,
	CMD_GOTO_LABEL,
	CMD_GOTO_PC,
	CMD_RETURN,
	CMD_NOP

};

enum param_type {
	PARAM_TYPE_NULL,  /* NOT USED */
	PARAM_TYPE_LITERAL_INT,
	PARAM_TYPE_LITERAL_CHAR,
	PARAM_TYPE_LITERAL_STRING,
	PARAM_TYPE_LITERAL_DOUBLE,
	PARAM_TYPE_VAR,
	PARAM_TYPE_VAR_ID,
	PARAM_TYPE_CALL,
	PARAM_TYPE_LIST,
	PARAM_TYPE_OP,
	PARAM_TYPE_USE_VAR,
	PARAM_TYPE_EMPTY,
	PARAM_TYPE_CACHED,
/* 4GL Specific */
	PARAM_TYPE_SPECIAL,
	PARAM_TYPE_ONKEY 

};


enum var_category {
	CAT_NULL, /* NOT USED */
	CAT_NORMAL, 		/* Normal variable */
	CAT_STATIC,  		/* Static variable */
	CAT_EXTERN,		/* Extern variable */
	CAT_ALLOC,		/* Normal variable (allocated some space) */
	CAT_ALLOC_STATIC,	/* Static variable (allocated some space) */
	CAT_ALLOC_EXTERN,	/* Extern variable (pointed to real allocated space) */
	CAT_SUBSTRUCT,		/* its within a struct - so we don't care... */
	CAT_PARAMETER,
	CAT_PARAMETER_SET
};


struct variable_element {
	long name_id;
	long dtype;
	long i_arr_size[3]; /* Informix limits to 3 levels of array */
	long unit_size;
	long total_size;
	long offset; /* This is the offset for CAT_NORMAL/PARAMETER, or a pointer for STATIC or EXTERN */
	struct variable_element next<>;
};


struct variable {
	long variable_id;
        long def_block;
	enum var_category category;
	struct variable_element *var;

	/* long alloc_size; */
	/* long offset;     */
	/* struct param *set; */
};


struct param_list {
	struct param list<>;
};

enum enumop {
	EOP_EQUAL,
	EOP_GT,
	EOP_GTE,
	EOP_LT,
	EOP_LTE,
	EOP_PLUS,
	EOP_MINUS,
	EOP_MULTIPLY,
	EOP_DIVIDE,
	EOP_AND,
	EOP_OR,
	EOP_LOGAND,
	EOP_LOGOR,
	EOP_NE,
	EOP_NOT
};


struct param_op {
	struct param *left;
	enum enumop op_i;
	struct param *right;
};


struct cmd_block {
	struct variable c_vars<>;
	long mem_for_vars;
	long mem_to_alloc;
};

struct cmd_end_block {
	long pc_start_block;
};

/*
struct param_c_call {
	short func_id;
	struct param *params;
};
*/

union param switch (enum param_type param_type) {
	case PARAM_TYPE_LITERAL_INT: 		long 			n;
	case PARAM_TYPE_LITERAL_CHAR: 		char 			c;
	case PARAM_TYPE_LITERAL_STRING: 	long str_entry;
	case PARAM_TYPE_LITERAL_DOUBLE:		double 			*d;
	case PARAM_TYPE_VAR:			string 			v<>;
	case PARAM_TYPE_VAR_ID: 		int 			vid;
	case PARAM_TYPE_CALL: 			struct cmd_call 	*c_call; /* We'll use the same */
	case PARAM_TYPE_LIST: 			struct param_list 	*p_list;
	case PARAM_TYPE_OP: 			struct param_op 	*op;
	case PARAM_TYPE_USE_VAR: 		struct use_variable 	*uv;
	case PARAM_TYPE_EMPTY: 			void; 
	case PARAM_TYPE_CACHED: 		long param_cache_id; 
	case PARAM_TYPE_SPECIAL: 		string special<>;
	case PARAM_TYPE_ONKEY: 			string keys<>;
};

struct cmd_if {
	struct param *condition;
	long goto_true;
	long goto_false;
};

/*
struct cmd_while {
	struct param condition;
	long goto_true;
	long goto_false;
};
*/



struct cmd_call {
	long func_id;
	/* char is_c; */
	struct param *params;
};



struct use_variable_sub {
	struct param 			*subscript;
	long 				element;
};

struct use_variable {
	short variable_id;
	short defined_in_block_pc; 	/* -1 for MODULE LEVEL */
	char indirection;
	struct use_variable_sub sub<>;

	/* 
	struct param 		*subscript;
	struct use_variable 	*next;
	*/
};


struct cmd_set_var {
	struct use_variable variable;
	struct param value;
};

struct cmd_set_var1 {
	struct use_variable variable;
	struct param value;
	int set;
};

/* An individual command */
union cmd switch(enum cmd_type cmd_type) {
	case CMD_BLOCK: 	struct cmd_block 	*c_block;
	case CMD_END_BLOCK: 	struct cmd_end_block 	*c_endblock;
	case CMD_CALL: 		struct cmd_call 	*c_call;
	case CMD_IF: 		struct cmd_if  		*c_if;
	case CMD_SET_VAR: 	struct cmd_set_var 	*c_setvar;
	case CMD_SET_VAR_ONCE: 	struct cmd_set_var1 	*c_setvar1;
	case CMD_GOTO_LABEL: 	long 			c_goto_str;
	case CMD_GOTO_PC: 	long 			c_goto_pc;
	case CMD_RETURN: 	struct param 		*c_return;
	case CMD_NOP: 		void;
};

struct call_stack {
	struct cmd_block *block;
	int pc;
};

struct function {
	long 			func_name_id;
	struct use_variable 	param_vars<>;
	long 			function_class;
	struct cmd 		cmds<>;
};


struct module {
	long 			fglc_magic;
	long 			fglc_version;
	long 			file_size;
	string 			module_name<>;
	long 			compiled_time;


	struct vstring 		string_table<>;
	struct vstring 		id_table<>;
	long  			external_function_table<>;
	struct function 	functions<>;
	struct param		params<>;
};
