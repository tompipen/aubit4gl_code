#ifndef A4GL_EXPR_H
#define A4GL_EXPR_H
struct expr_str_list {
	  struct expr_str **list;
	  int nlist;
};

struct expr_push_variable {
	char *variable;
	long var_dtype;
};

struct expr_op {
	struct expr_str *left;
	struct expr_str *right;
	struct expr_str *escape;
};

struct expr_function_call {
	char *fname;
	struct expr_str_list *parameters;
	char *module;
	int line;
};

struct expr_shared_function_call {
	char *lib;
	char *fname;
	struct expr_str_list *parameters;
	char *module;
	int line;
};


struct expr_infield {
	        long sio_id;
	        struct fh_field_list *field_list;
	        char *module;
	        int line;
};


struct expr_get_fldbuf {
	long sio_id;
	struct fh_field_list *field_list;
	char *module;
	int line;
};


struct expr_field_touched {
	long sio_id;
	struct fh_field_list *field_list;
	char *module;
	int line;
};

struct expr_wordwrap {
	struct expr_str *expr;
	char *wrap_at;
};


struct expr_member_function_call {
	char *lib;
	char *fname;
	struct expr_str_list *parameters;
	char *module;
	int line;
};


struct expr_extend {
	struct expr_str *expr;
	int to;
};


struct expr_external_call {
	char *host;
	char *func;
	char *port;
	struct expr_str_list *parameters;
	int without_waiting;
	char *module;
	int line;
};



struct expr_substring {
	char *str;
	long len;
	char *substring_start;
	char *substring_end;
	int type;
};


struct expr_current {
	short from;
	short to;
};


struct expr_in {
	struct expr_str *expr;
	struct expr_str_list *elist;
};


struct expr_datetime {
	char *dtval;
	int extend;
};

struct expr_tmp {
	char *str;
	int dtype;
};

struct expr_interval {
	char *intval;
	int extend;
};

struct expr_exists_sq {
	char *subquery;
	int nibind;
	void *ibind;
};

struct expr_in_sq {
	struct expr_str *expr;
	char *subquery;
	int nibind;
	void *ibind;
};

struct expr_cast {
		struct expr_str *expr;
		int target_dtype;
		int src_dtype;
		int notnull;
		int force;
};

struct expr_bound_fcall {
	char *lib;
	char *fname;
	char *module;
	int line;
	int nibind;
	void *ibind;
	int nebind;
	void *ebind;
};

struct expr_agg {
	char agg_type;
	int expr_num;
	int in_group;
};

struct expr_dynarr_extent {
	char *var;
	int n;
};



enum e_expr_type {
		//ET_EXPR_CHAR,
		//ET_EXPR_EXPR,
		ET_EXPR_EXPR_LIST,
		//ET_EXPR_OP,
		//ET_EXPR_INT,
		//ET_EXPR_NUM,
		ET_EXPR_STRING,
		ET_EXPR_PUSH_VARIABLE,
		ET_EXPR_TODAY,
		ET_EXPR_TIME,
		ET_EXPR_LINENO,
		ET_EXPR_PAGENO,
		ET_EXPR_TIME_EXPR,
		ET_EXPR_DATE_EXPR,
		ET_EXPR_NULL,
		ET_EXPR_TRUE,
		ET_EXPR_FALSE,
		ET_EXPR_NOT,
		ET_EXPR_UPSHIFT,
		ET_EXPR_DOWNSHIFT,
		ET_EXPR_EXTEND,
		ET_EXPR_ASCII,
		ET_EXPR_MM,
		ET_EXPR_POINTS,
		ET_EXPR_INCHES,
		ET_EXPR_CURRENT,
		ET_EXPR_OP_MULT,
		ET_EXPR_OP_DIV,
		ET_EXPR_OP_POWER,
		ET_EXPR_OP_ADD,
		ET_EXPR_OP_SUB,
		ET_EXPR_OP_EQUAL,
		ET_EXPR_OP_NOT_EQUAL,
		ET_EXPR_OP_MOD,
		ET_EXPR_OP_USING,
		ET_EXPR_OP_LIKE,
		ET_EXPR_OP_NOT_LIKE,
		//ET_EXPR_OP_LENGTH,
		ET_EXPR_OP_IN,
		ET_EXPR_OP_NOT_IN,
		ET_EXPR_OP_CONCAT,
		ET_EXPR_OP_MATCHES,
		ET_EXPR_OP_NOT_MATCHES,
		ET_EXPR_OP_CLIP,
		ET_EXPR_OP_LESS_THAN,
		ET_EXPR_OP_LESS_THAN_EQ,
		ET_EXPR_OP_GREATER_THAN,
		ET_EXPR_OP_GREATER_THAN_EQ,
		ET_EXPR_OP_YEAR,
		ET_EXPR_OP_MONTH,
		ET_EXPR_OP_DAY,
		ET_EXPR_OP_HOUR,
		ET_EXPR_OP_MINUTE,
		ET_EXPR_OP_SECOND,
		ET_EXPR_OP_ISNULL,
		ET_EXPR_OP_ISNOTNULL,
		ET_EXPR_OP_SPACES,
		ET_EXPR_OP_AND,
		ET_EXPR_OP_OR,
		ET_EXPR_NEG,
		ET_EXPR_FCALL,
		ET_EXPR_SHARED_FCALL,
		ET_EXPR_MEMBER_FCALL,
		ET_EXPR_COLUMN,
		ET_EXPR_REPORT_EMAIL,
		ET_EXPR_REPORT_PRINTER,
		ET_EXPR_QUOTED_STRING,
		ET_EXPR_LITERAL_DOUBLE_STR,
		ET_EXPR_LITERAL_LONG,
		ET_EXPR_LITERAL_STRING, // original is already quoted....
		ET_EXPR_LITERAL_EMPTY_STRING, // original is already quoted....

		ET_EXPR_REDUCED,
		ET_EXPR_EXTERNAL,
		ET_EXPR_GET_FLDBUF,
		ET_EXPR_WORDWRAP,
		ET_EXPR_SUBSTRING,
		ET_EXPR_NOT_EXISTS_SUBQUERY,
		ET_EXPR_EXISTS_SUBQUERY,
		ET_EXPR_OP_IN_SUBQUERY,
		ET_EXPR_OP_NOTIN_SUBQUERY,

		ET_EXPR_CAST,
		ET_EXPR_CONCAT_LIST,
		ET_EXPR_YEAR_FUNC,
		ET_EXPR_MONTH_FUNC,
		ET_EXPR_DAY_FUNC,
		ET_EXPR_DATE_FUNC,
		ET_EXPR_TIME_FUNC,
		ET_EXPR_DTVAL,
		ET_EXPR_INFIELD,
		ET_EXPR_FIELD_TOUCHED,
		ET_EXPR_NOT_FIELD_TOUCHED,
		ET_EXPR_IVAL_VAL,
		ET_EXPR_FCALL_SINGLE,
		ET_EXPR_TEMP,
		ET_EXPR_BOUND_FCALL,
		ET_EXPR_AGGREGATE,
		ET_EXPR_FGL_SIZEOF,
		ET_EXPR_FGL_ADDRESSOF,
		ET_EXPR_FGL_ISDYNARR_ALLOCATED,
		ET_EXPR_FGL_DYNARR_EXTENTSIZE,
		ET_EXPR_FIELDTOWIDGET,
		ET_EXPR_ID_TO_INT,

		ET_EXPR_LAST // NOT USED - just there so the above can all have a trailing ',' !!! (and possibly checking later...)
};




struct expr_str {
	  enum e_expr_type expr_type;
	  union {
	  	char 					*expr_char; // We'd like to obsolete the use of this one....

	  	char 					*expr_string; 
		long   					expr_long;
		struct fh_field_entry			*expr_field_entry;
		struct expr_extend			*expr_extend;
		struct expr_str 			*expr_expr;
		struct expr_str_list 			*expr_list;
		struct expr_push_variable 		*expr_push_variable;
		struct expr_function_call		*expr_function_call;
		struct expr_shared_function_call	*expr_shared_function_call;
		struct expr_member_function_call	*expr_member_function_call;
		struct expr_external_call		*expr_external_call;
		struct expr_op				*expr_op;
		struct expr_current 			*expr_current;
		struct expr_get_fldbuf 			*expr_get_fldbuf;
		struct expr_infield 			*expr_infield;
		struct expr_wordwrap 			*expr_wordwrap;
		struct expr_substring			*expr_substring;
		struct expr_in				*expr_in;
		struct expr_exists_sq			*expr_exists_sq;
		struct expr_in_sq			*expr_in_sq;
		struct expr_cast			*expr_cast;
		struct expr_datetime			*expr_datetime;
		struct expr_interval			*expr_interval;
		struct expr_field_touched		*expr_field_touched;
		struct expr_tmp				*expr_tmp;
		struct expr_bound_fcall			*expr_bound_fcall;
		struct expr_agg				*expr_agg;
		struct expr_dynarr_extent	        *expr_dynarr_extent;
	
	  } u_data;
	  struct expr_str *next;
};

typedef struct expr_str t_expr_str;

#define T_EXPR_LIST_DEFINED
typedef struct expr_str_list t_expr_str_list;

struct expr_str *A4GL_new_op_expr(struct expr_str *left, struct expr_str *right, enum e_expr_type type, struct expr_str *escape) ;
struct expr_str *A4GL_new_expr_call_external(char *host,char *func,char *port,struct expr_str_list *params,int nowait,char *mod,int line);
struct expr_str *A4GL_new_datetime_expr(char *str, int extent);
struct expr_str *A4GL_new_interval_expr(char *str, int extent);
struct expr_str *A4GL_new_expr_agg(char type, int nagg);
struct expr_str *A4GL_new_literal_double_str (char *value);
struct expr_str *A4GL_new_expr_field_touched(int sid, struct fh_field_list *fl,char *mod,int line);
struct expr_str *A4GL_new_expr_not_field_touched(int sid, struct fh_field_list *fl,char *mod,int line);
struct expr_str *A4GL_new_expr_extend(struct expr_str *ptr,int to);
struct expr_str *A4GL_new_literal_long_str (char *value);
struct expr_str *A4GL_new_literal_long_long (long value);
struct expr_str *A4GL_new_literal_string (char *value);
struct expr_str *A4GL_new_expr_temp(char *s,int dtype);
struct expr_str *A4GL_new_literal_empty_str(void);
struct expr_str *A4GL_new_concat_list(struct expr_str_list *params);
struct expr_str *A4GL_new_substring_expr (char *str,long str_len,char *ptr_s, char *ptr_e,int type);
struct expr_str *A4GL_expr_exists_sq(int invert,char *s,void *bind, int nbind);
struct expr_str *A4GL_expr_in_sq(struct expr_str *expr, int invert,char *subquery,void *bind, int nbind);
struct expr_str *A4GL_expr_in(struct expr_str *expr, int invert,struct expr_str_list *elist);
char *expr_name(enum e_expr_type e);

struct expr_str *A4GL_new_expr_simple_string(char *str,enum e_expr_type type) ;

struct expr_str *A4GL_new_expr_simple_expr(struct expr_str *ptr,enum e_expr_type type);
struct expr_str *A4GL_new_expr_shared_fcall(char *lib,char *function,struct expr_str_list *params,char *mod,int line);
struct expr_str *A4GL_new_expr_bound_fcall(char *lib,char *function,char *mod,int line,int nibind,void *ibind, int nibytes,int nebind,void *ebind,int nebytes);
struct expr_str *A4GL_new_expr_member_fcall(char *lib,char *function,struct expr_str_list *params,char *mod,int line);
struct expr_str_list *A4GL_rationalize_list(struct expr_str_list *l);
struct expr_str *A4GL_new_expr_fcall(char *function,struct expr_str_list *params,char *mod,int line);
void * A4GL_append_expr (struct expr_str *orig_ptr, char *value);
struct expr_str *A4GL_new_expr_simple (enum e_expr_type type);
struct expr_str *A4GL_new_expr_neg(struct expr_str *ptr);
struct expr_str *A4GL_new_expr_push_variable(char *v,long dtype);
void * A4GL_append_expr_expr (struct expr_str *orig_ptr, struct expr_str *second_ptr);
int A4GL_length_expr (struct expr_str *ptr);
struct expr_str_list *A4GL_new_ptr_list(struct expr_str *ptr);
struct expr_str_list *A4GL_new_append_ptr_list(struct expr_str_list *l,struct expr_str *ptr);
int A4GL_new_list_get_count(struct expr_str_list *l);
void A4GL_print_expr_ret_list(struct expr_str_list *l);
struct expr_str *A4GL_new_expr_list (void);
struct expr_str_list *A4GL_new_prepend_ptr_list(struct expr_str_list *l,struct expr_str *p);
struct expr_str *A4GL_new_expr_get_fldbuf(int sid, struct fh_field_list *fl,char *mod,int line);
struct expr_str *A4GL_new_expr_infield(int sid, struct fh_field_list *fl,char *mod,int line);
struct expr_str *A4GL_new_expr_current(int from, int to);
struct expr_str *A4GL_new_expr_wordwrap(struct expr_str *ptr,char *wrap_at);

#endif
