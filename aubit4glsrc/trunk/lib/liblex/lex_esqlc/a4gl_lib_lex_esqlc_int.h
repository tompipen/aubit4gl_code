


#include "a4gl_lib_lex_int.h"
//#define A4GL_append_expr A4GL_append_expr_obsol
//#define A4GL_new_expr A4GL_new_expr_obsol
//

struct binding_comp *ensure_bind(long *a_bindp,long need, struct expr_str *b) ;
//char find_variable_scope (char *s_in);
int print_bind_dir_definition(char i,struct expr_str *bind, int bindcnt) ;
int print_bind_dir_set_value (char i,struct expr_str *bind,int bindcnt);
int doing_esql(void);

int check_binding(struct expr_str_list *l, char *fromwhere,int yylineno);

enum e_dialect {
	E_DIALECT_NONE,
	E_DIALECT_INFORMIX,
	E_DIALECT_POSTGRES,
	E_DIALECT_SAPDB,
	E_DIALECT_INGRES,
	E_DIALECT_INFOFLEX
};

enum e_dialect esql_type(void);
struct variable *local_find_variable_from_usage(struct variable_usage *u);
char *generation_get_variable_usage_as_string(struct variable_usage *u );
char *make_sql_bind_g (expr_str_list *bind,char type);
int get_binding_dtype(expr_str *e);
void print_Constant(int type, char *vv);
char *generate_ispdf(void) ;
void remove_field_subscripts_from_field_list(struct fh_field_list *flist);

char * get_sql_variable_usage_internal (variable_usage * u, char dir) ;
char *lowlevel_chk_sql(char *sorig) ;
void set_global_curs(void);

void
print_pop_usage_prompt (expr_str * v);
struct command *get_last_cmd(void );
void dump_command_list(struct command **clist, int nvals);
int local_bad_identifiers(char *s);
int dump_class_definition(struct s_class_definition *class_def);
void set_object_function(int n);
