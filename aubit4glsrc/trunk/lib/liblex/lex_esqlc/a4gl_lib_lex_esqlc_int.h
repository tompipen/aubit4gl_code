


#include "a4gl_lib_lex_int.h"
//#define A4GL_append_expr A4GL_append_expr_obsol
//#define A4GL_new_expr A4GL_new_expr_obsol
//
void print_exists_subquery(int i,struct expr_exists_sq *e_expr) ;

void print_in_subquery(int i,struct expr_in_sq *in_expr) ;
struct binding_comp *ensure_bind(long *a_bindp,long need, struct binding_comp *b) ;
char find_variable_scope (char *s_in);
int print_bind_dir_definition(char i,struct binding_comp *bind, int bindcnt) ;
int print_bind_dir_set_value (char i,struct binding_comp *bind,int bindcnt);
int doing_esql(void);



enum e_dialect {
	E_DIALECT_NONE,
	E_DIALECT_INFORMIX,
	E_DIALECT_POSTGRES,
	E_DIALECT_SAPDB,
	E_DIALECT_INGRES,
	E_DIALECT_INFOFLEX
};

enum e_dialect esql_type(void);
