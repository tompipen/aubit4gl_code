#include "a4gl_incl_config.h"

struct define_variables
{
  int var_len;
  struct variable_element *var_val;
};


struct char_list
{
  int char_len;
  char **ptr;
};


struct s_assign
{
  long p;
  struct use_variable *v;
};


#ifdef USE_A4GL_DEBUG
int A4GL_set_line (char *s, long l);
void A4GL_debug_full (char *fmt, ...);
#define A4GL_debug A4GL_set_line(__FILE__,__LINE__);A4GL_debug_full
#else
#ifndef A4GL_debug
#define A4GL_debug nullfunc
#endif
#endif


#define DCHAR   0
#define DSTRING 1
#define DINT    2
#define DLONG   3
#define DPTR    4
#define DDEC    5
#define DMON    6
#define DVOID   7
#define DLONGPTR   8
#define DSHORTPTR   9

#define DBLOCK  126
#define DSTRUCT 127
#define DUNKNOWN -1


void append_param_list (long plist, long newparam);
long new_param_list_returns_long (long p);
long new_param_fcall_returns_long (char *fname, long plist);
long new_param_op_returns_long (long l, char *op, long r);
long new_param_returns_long (char s, void *ptr);
struct variable *get_block_vars (void);
void add_block_var (struct cmd_block *ptr, int pc);
long find_label (char *label);
void add_label (char *label);
long do_end_block (void);
void set_externs (void);
int process_xdr (char dir, void *s, char *filename);
void print_variable (int lvl, struct npvariable *n);
#define GET_ID(x) ((char *)this_module.id_table.id_table_val[x].s)
void allocate_variable (int module_level, int offset, struct npvariable *n);
int add_id (char *s);
long call_c_function (char *s, struct param *p, long *r);

int evaluate_param_into_integer (struct param *e, long *x);
int evaluate_param_i_into_integer (long e_i, long *x);

int evaluate_param_into_short (struct param *e, short *x);
int evaluate_param_i_into_short (long e_i, short *x);

int evaluate_param_into_double (struct param *e, double *x);
int evaluate_param_i_into_double (long e_i, double *x);

int evaluate_param_into_char (struct param *e, char*x); // NOT FOR STRINGS !
int evaluate_param_i_into_char (long e_i, char *x);     // NOT FOR STRINGS !

void *get_var_ptr (struct use_variable *use_var,int *size);
void optimize ();

long add_set_var (struct use_variable *var, long value_i, int once,int lvl);

int nset_param(struct param *p,int n);
void execute_start_block (long pc, struct cmd_block *c);
struct variable_element *param_variable (char *dtype, char *name, struct param *size);
struct variable_element *append_param_variable (struct variable_element *orig, struct variable_element *next);
struct define_variables *add_named_struct (char *s);
struct variable_element *new_variable_struct (struct define_variables *v);
struct variable_element *new_variable_element_string (char *s);
//void add_variable (int type, struct variable_element *e, char *id, struct param *set);
void add_variable (int type, struct variable_element *e, char *id, long set);
struct use_variable * mk_use_variable (long p_i, long arr_i1,long arr_i2, long arr_i3, char *id, char indirection);
int in_function (void);
struct variable_element *new_variable_struct (struct define_variables *v);
void print_params (long e);

void print_module_functions (void);

void resolve_gotos (void);
void set_pc_vstack_curr (void);
void set_pc_vstack (int pc);
long current_pc (void);
void print_module (void);
void add_default_named_structs (void);
void execute_end_block (void);
long call_function (long pc, struct npcmd_call *c);
void set_var (long pc, struct cmd_set_var *sv);
void set_var_once (long pc, struct cmd_set_var1 *sv);
void add_function (char *function_name, struct define_variables *v,
		   int is_static);
int run_module ();
long run_function (int func_no, struct param *p);

void add_variable_array (int type, struct variable_element *e, char *id, long *arrsize, long set);
void print_use_variable (struct use_variable *v);
long end_main (void);
void move_defines (void);
void end_define_module (void);





long add_block (void *ptr_c_vars);
long add_break (int a);
long add_call (char *funcname, long params_i);
long add_chk_err (int n);
long add_clr_err (void);
long add_continue (int a);
long add_ecall (char *s, int a, int b);
long add_errchk_40000 (void *n);
long add_errchk_40010 (void *n);
long add_errchk_40110 (void *n);
long add_errchk (void *n);
long add_goto (char *label);
long add_if (long e_i, char *true, char *false);
long add_pop_args (int n);
long add_pop_function() ;
long add_push_char (char *s);
long add_push_charv (long e_i);
long add_push_int (int n);
long add_push_long (int n) ;
long add_push_op (char *n);
long add_push_substr(long e);
int has_named_struct (char *s);
long add_return (long r_i);
long add_set_line (char *module,int line);
long end_function ();
void init_calls (int argc, char **argv);
void *resolve_externs (char *name);
void set_master_type (int type);
void end_define (void);
void set_master_set (long set);
long end_block (void);
void set_type (int a);
int special_cmd (struct cmd *c);
int open_and_run (char *lv_progname);
void nullfunc ();
int yylex (void);
long add_errchk (void *n);
int do_compiler_start (int argc, char *argv[]);
int yyerror (char *s);
void print_errchk (struct cmd_errchk *e);
long find_pcode_function (char *s);
int add_string (char *s);
#define PARAM_ID(x) this_module.params.params_val[x]
long add_push_op(char *n);
struct param *nget_param(int n);
long add_set_stat(int a);
long add_ecall(char *s,int a,int b);
int get_expr_n(int n);
void set_expr_n(int n,int v);
void make_new_param(int *n,struct param **p);
void set_indirection(int n,int up_down);
struct use_variable *get_use_variable(int n);
struct cmd_block *get_base(int block_pc);
long new_command (enum cmd_type cmd_type, void *ptr);

#ifdef NEED_CMD_TYPE_STR
static char *cmd_type_str[] = {
  "CMD_NULL",
  "CMD_BLOCK",
  "CMD_END_BLOCK",
  "CMD_CALL",
  "CMD_IF",
  "CMD_SET_VAR",
  "CMD_SET_VAR_ONCE",
  "CMD_GOTO_LABEL",
  "CMD_GOTO_PC",
  "CMD_RETURN",
  "CMD_NOP",
  "CMD_PUSH_LONG",
  "CMD_PUSH_INT",
  "CMD_PUSH_CHAR",
  "CMD_PUSH_CHARV",
  "CMD_CHK_ERR",
  "CMD_PUSH_VARIABLE",
  "CMD_END_4GL_0",
  "CMD_END_4GL_1",
  "CMD_DISPLAY_AT",
  "CMD_PUSH_OP",
  "CMD_CLR_ERR",
  "CMD_ERRCHK",
  "CMD_ECALL",
  "CMD_SET_STAT",
  "Not Set",
  "Not Set",
  "Not Set",
  "Not Set",
  "Not Set",
  "Not Set",
  "Not Set",
  "Not Set",
  "Not Set",
  "Not Set",
  "Not Set",
  "Not Set",
  "Not Set",
  "Not Set",
  "Not Set",
  "Not Set",
  "Not Set",
  "Not Set",
  "Not Set",
  "Not Set",
  "Not Set",
  "Not Set",
  "Not Set",
  "Not Set",
  ""
};



#endif
