struct define_variables {
        int var_len;
        struct variable_element *var_val;
};


struct char_list {
	int char_len;
	char **ptr;
};


struct s_assign {
        struct param *p;
        struct use_variable *v;
};

int A4GL_set_line (char *s, long l);
#define A4GL_debug A4GL_set_line(__FILE__,__LINE__);A4GL_debug_full


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


struct param *append_param_list   (struct param *plist,struct param *newparam) ;
struct param *new_param_list (struct param *p) ;
struct param *new_param_fcall    (char *fname,struct param *plist) ;
struct param *new_param_op        (struct param *l,char *op,struct param *r) ;
struct param *new_param(char s,void *ptr);
struct variable * get_block_vars (void);
void add_block_var (struct cmd_block *ptr, int pc);
long find_label(char *label);
void add_label(char *label);
long do_end_block (void);
void set_externs(void);
int process_xdr (char dir, void *s, char *filename);
void print_variable(int lvl,struct variable *n);
#define GET_ID(x) ((char *)this_module.id_table.id_table_val[x].s)
void allocate_variable (int module_level, int offset, struct variable *n);
int add_id(char *s);
long call_c_function(char *s,struct param *p,long *r);
int evaluate_param (struct param *e, int *x);
void *get_var_ptr(struct use_variable *use_var);
long add_set_var (struct use_variable *var, struct param *value,int once);
struct variable_element *param_variable (char *dtype,char *name,struct param *size);
struct variable_element *append_param_variable (struct variable_element *orig,struct variable_element *next);
struct define_variables *add_named_struct(char *s);
struct variable_element *new_variable_struct(struct define_variables *v);
struct variable_element *new_variable_element_string(char *s);
void add_variable (int type,struct variable_element *e,char *id,struct param *set);
struct use_variable * mk_use_variable (struct param *p, struct param *arr, char *id,char indirection);
int in_function(void );
struct variable_element *new_variable_struct(struct define_variables *v);
void print_params (struct param *e);

void print_module_functions(void);

void A4GL_debug_full (char *fmt, ...);
void resolve_gotos (void);
void set_pc_vstack_curr(void);
void set_pc_vstack (int pc);
long current_pc(void);
void print_module (void);
void add_default_named_structs(void);
void execute_start_block(long pc,struct cmd_block *c);
void execute_end_block(void);
long call_function (long pc, struct cmd_call *c);
void set_var(long pc, struct cmd_set_var *sv);
void set_var_once(long pc, struct cmd_set_var1 *sv);
void add_function (char *function_name, struct define_variables *v, int is_static);
int run_module ();
long run_function(int func_no,struct param *p);

void add_variable_array (int type, struct variable_element *e, char *id, long *arrsize, struct param *set);
void print_use_variable (struct use_variable *v);
long end_main (void);
void move_defines(void);
void end_define_module(void);
