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
	CMD_NOP,
/* 4gl specific */
	CMD_PUSH_LONG	,
	CMD_PUSH_INT	,
	CMD_PUSH_CHAR	,
	CMD_PUSH_CHARV	,
	CMD_CHK_ERR	,
	CMD_PUSH_VARIABLE,
	CMD_END_4GL_0	,
	CMD_END_4GL_1,
	CMD_DISPLAY_AT	,
	CMD_PUSH_OP,
	CMD_CLR_ERR,
	CMD_ERRCHK,
	CMD_ECALL,
	CMD_SET_STAT


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
	short name_id;
	long dtype;
	long i_arr_size[3]; /* Informix limits to 3 levels of array */
	short unit_size;
	/*long as; */
	long total_size;
	long offset; /* This is the offset for CAT_NORMAL/PARAMETER, or a pointer for STATIC or EXTERN */
	struct variable_element next<>;
};


struct npvariable {
	long variable_id;
        long def_block;
	enum var_category category;
	struct variable_element *var;

};


struct param_list {
	long  list_param_id<>;
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
	long left_param_id;
	enum enumop op_i;
	long right_param_id;
};


struct cmd_block {
	struct npvariable c_vars<>;
	long mem_for_vars;
	long mem_to_alloc;
};

struct cmd_end_block {
	long pc_start_block;
};


union param switch (int param_type) {
	case PARAM_TYPE_LITERAL_INT: 		long 			n;
	case PARAM_TYPE_LITERAL_CHAR: 		char 			c;
	case PARAM_TYPE_LITERAL_STRING: 	long 			str_entry;
	case PARAM_TYPE_LITERAL_DOUBLE:		double 			*d;
	case PARAM_TYPE_VAR:			string 			v<>;
	case PARAM_TYPE_VAR_ID: 		int 			vid;
	case PARAM_TYPE_CALL: 			struct npcmd_call 	*c_call; /* We'll use the same */
	case PARAM_TYPE_LIST: 			struct param_list 	*p_list;
	case PARAM_TYPE_OP: 			struct param_op 	*op;
	case PARAM_TYPE_USE_VAR: 		struct use_variable 	*uv;
	case PARAM_TYPE_CACHED: 		long 			param_cache_id; 
	case PARAM_TYPE_SPECIAL: 		string 			special<>;
	case PARAM_TYPE_ONKEY: 			string 			keys<>;
	case PARAM_TYPE_NULL: 			void; 
	case PARAM_TYPE_EMPTY: 			void; 
};

struct npcmd_if {
	long condition_param_id;
	long goto_true;
	long goto_false;
};


struct npcmd_call {
	long func_id;
	long func_params_param_id;
};



struct use_variable_sub {
	long x1subscript_param_id[3];
	long x1element;
	long subscript_all;
};

struct use_variable {
	short  variable_id;
	short  defined_in_block_pc; 	/* -1 for MODULE LEVEL */
	char   indirection;
	struct use_variable_sub sub<>;
};


struct cmd_set_var {
	struct use_variable variable;
	long value_param_id;
};

struct cmd_set_var1 {
	struct use_variable variable;
	long value_param_id;
	int set;
};

struct cmd_display_at {
	short x;
	short y;
};

struct cmd_errchk {
	long line;
	long module_name;
	long modes[5];
	long actions[5];
};


struct ecall {
	int func_id;
	int ln;
	int nparam;
};

/* An individual command */
union cmd switch(int  cmd_type) {
	case CMD_BLOCK: 	struct cmd_block *	c_block;
	case CMD_END_BLOCK: 	struct cmd_end_block *	c_endblock;
	case CMD_CALL: 		struct npcmd_call *	c_call;
	case CMD_IF: 		struct npcmd_if *	c_if;
	case CMD_SET_VAR: 	struct cmd_set_var *	c_setvar;
	case CMD_SET_VAR_ONCE: 	struct cmd_set_var1 *	c_setvar1;
	case CMD_GOTO_LABEL: 	long 			c_goto_str;
	case CMD_GOTO_PC: 	long 			c_goto_pc;
	case CMD_RETURN: 	long  			c_return_param_id;
	case CMD_CLR_ERR:       void;
	case CMD_END_4GL_0:     void;
	case CMD_END_4GL_1:     void;
	case CMD_NOP: 		void;
	case CMD_PUSH_LONG:     long			c_push_long;
	case CMD_PUSH_INT:	short 			c_push_int;
	case CMD_CHK_ERR: 	long 			c_chk_err_lineno;
	case CMD_ERRCHK:	struct cmd_errchk *	c_errchk;
	case CMD_PUSH_CHAR:	long 			c_push_char;
	case CMD_PUSH_CHARV: 	long 			c_var_param_id;

	case CMD_DISPLAY_AT:	struct cmd_display_at 	c_disp_at;
	case CMD_PUSH_OP:	long   			c_push_op;
	case CMD_ECALL:		struct ecall *		c_ecall;
	case CMD_SET_STAT: 	long 			c_setval;
};


struct call_stack {
	struct cmd_block *block;
	int pc;
};

struct npfunction {
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
	struct npfunction 	functions<>;
	struct param		params<>;
};
