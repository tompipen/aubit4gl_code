


#include "a4gl_lib_lex_int.h"
//#define A4GL_append_expr A4GL_append_expr_obsol
//#define A4GL_new_expr A4GL_new_expr_obsol
//
void print_exists_subquery(int i,struct s_expr_exists_sq *e_expr) ;

void print_in_subquery(int i,struct s_expr_in_sq *in_expr) ;
struct binding_comp *ensure_bind(long *a_bindp,long need, struct binding_comp *b) ;
//char find_variable_scope (char *s_in);
int print_bind_dir_definition(char i,struct binding_comp *bind, int bindcnt) ;
int print_bind_dir_set_value (char i,struct binding_comp *bind,int bindcnt);
//void printc_safe_to_split_at_comma(char *fmt, ...);
//
//

//void load_protos(void) ;
//int get_bolton_rtype(int a,int rval);
char * get_ident (struct expr_str *ptr,int prefixWithModuleName);


//void printc_safe_to_split_at_comma (char *fmt, ...);

//char * decode_varbind (struct expr_str *t, char read_or_write, int pos);
int compile_time_convert(void);
void print_in_binding (struct expr_str_list *list);
char *generation_get_variable_usage_as_string (struct variable_usage *u);
int match_variable_usage(variable_usage *u1, variable_usage *u2);
void print_prepare_cmd (struct_prepare_cmd * p);
void print_copy_fromRSet (struct expr_str_list *list);
int get_binding_dtype (expr_str * e);
char * A4GL_dtype_sz (int d, int s);
int dump_report (struct s_report_definition *report_definition);
int dump_pdf_report (struct s_pdf_report_definition *report_definition);
void print_report_table (char *repname, char type, int c,char*asc_desc,struct expr_str_list *funcbind, struct expr_str_list *orderbind);
