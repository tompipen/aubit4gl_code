#include "a4gl_libaubit4gl.h"
#include <sys/types.h>
#include "../a4gl_lib_lex_int.h"



/* PROTOTYPES */

void ensure_char (struct expr_str *p, int f);
static char *make_arr_str (char *s, struct variable *v);
char *rettype_integer_internal (int n);
int is_param (char *s);
void clr_suppress_newlines (void);
void set_suppress_newlines (void);
char *is_single_string (struct expr_str_list *ptr);
char *use_scope (char *s);
static void print_define_char (char *vbuff, char *tbuff, char *abuff,
			       int size, int isstatic_extern, int lvl);
static void print_define (char *vbuff, char *tbuff, char *abuff,
			  int isstatic_extern, int lvl);
void ensure_dtype (struct expr_str *e, int dtype, int notnull);
char *anon_prepare (char *s);
static int is_just_expr_clipped (char *v, struct expr_str_list *ptr);
int is_ignore_var (char *var);

void print_function_variable_init (void);

void print_structures_in (struct record_variable *v, int lvl, int scope);
char *fixup_squares (char *s);



void printc (char *fmt, ...);

void
printh (char *fmt, ...);
struct expr_str_list *
A4GL_rationalize_list_concat (struct expr_str_list *l);


char *
check_for_reserved_words (char *s);
char * valid_func_name (char *s);
int
print_bind_set_value_param_2 (char *cname, char i);
struct binding_comp *ensure_bind (long *a_bindp, long need,
		                                  struct binding_comp *b);
char *rettype_integer (int a);
