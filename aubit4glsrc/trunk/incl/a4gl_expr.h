#ifndef A4GL_EXPR_H
#define A4GL_EXPR_H

#define Blah
#include "dataio/fgl.xs.h"

struct expr_str *A4GL_new_op_expr(struct expr_str *left, struct expr_str *right, enum e_expr_type type, struct expr_str *escape) ;
struct expr_str *A4GL_new_expr_call_external(char *host,char *func,expr_str *port,struct expr_str_list *params,int nowait,char *mod,int line,char *namespace);
struct expr_str *A4GL_new_datetime_expr(char *str, int extent);
struct expr_str *A4GL_new_interval_expr(char *str, int extent);
struct expr_str *A4GL_new_expr_agg (char type,int nagg, expr_str *s1, expr_str *s2, int in_group, int blockid_grp, int blockid_always,int lineno);
struct expr_str *A4GL_new_literal_double_str (char *value);
struct expr_str *A4GL_new_expr_field_touched(int sid, struct fh_field_list *fl,char *mod,int line);
struct expr_str *A4GL_new_expr_not_field_touched(int sid, struct fh_field_list *fl,char *mod,int line);
struct expr_str *A4GL_new_expr_email_report (char *repname, struct expr_str *email_addr);
struct expr_str *A4GL_new_expr_extend(struct expr_str *ptr,int to);
struct expr_str *A4GL_new_literal_long_str (char *value);
struct expr_str_list *expand_variables_in_expr_str_list(expr_str_list *parameters,int err_if_not_var,int err_if_whole_array) ;
struct expr_str *A4GL_new_expr_form_is_compiled(char *formname, expr_str_list *params,char *mod,int line);
struct expr_str * A4GL_new_translated_string (char *value);
struct expr_str *A4GL_new_expr_funcdef(char *funcname, char *namespace);
struct expr_str * A4GL_new_expr_binding (expr_str_list * list);
struct expr_str * A4GL_new_expr_named_param (char *name, expr_str *value);
struct expr_str * A4GL_new_spl_for_item_expr (expr_str *start,expr_str *end, expr_str *step);
struct expr_str * A4GL_expr_select ( struct s_select *s);
struct expr_str * A4GL_new_expr_syncfields (int sid, char *mode, char *mod, int line);


struct expr_str *report_position_expr_x(struct expr_str *expr) ;
struct expr_str *report_position_expr_y(struct expr_str *expr) ;
struct expr_str *report_position_current_y(void ) ;
struct expr_str *report_position_current_x(void ) ;


struct expr_str *A4GL_new_literal_long_long (long value);
struct expr_str *A4GL_new_literal_string (char *value);
struct expr_str *A4GL_new_expr_temp(char *s,int dtype);
struct expr_str *A4GL_new_literal_empty_str(void);
struct expr_str *A4GL_new_concat_list(struct expr_str_list *params);
struct expr_str *A4GL_new_substring_expr (char *str,long str_len,char *ptr_s, char *ptr_e,int type);
struct expr_str *A4GL_expr_exists_sq(int invert,struct s_select  *s);
struct expr_str *A4GL_expr_in_sq(struct expr_str *expr, int invert,struct s_select *s);
struct expr_str *A4GL_expr_in(struct expr_str *expr, int invert,struct expr_str_list *elist);
char *expr_name(enum e_expr_type e);

struct expr_str *A4GL_new_expr_simple_string(char *str,enum e_expr_type type) ;
struct expr_str *A4GL_new_expr_assoc(char *s, expr_str *subscript);

struct expr_str *A4GL_new_expr_simple_expr(struct expr_str *ptr,enum e_expr_type type);
struct expr_str *A4GL_new_expr_shared_fcall(char *lib,char *function,struct expr_str_list *params,char *mod,int line, char *p_namespace,char *errbuf);
struct expr_str *A4GL_new_expr_bound_fcall(char *lib,char *function,char *mod,int line, expr_str_list *params, char *p_namespace);
struct expr_str *A4GL_new_expr_member_fcall(struct expr_str *var_usage,struct expr_str_list *params,char *mod,int line, char *p_namespace);
struct expr_str_list *A4GL_rationalize_list(struct expr_str_list *l);
struct expr_str *A4GL_new_expr_fcall(char *function,struct expr_str_list *params,char *mod,int line,char *p_namespace);
void * A4GL_append_expr (struct expr_str *orig_ptr, char *value);
struct expr_str *A4GL_new_expr_simple (enum e_expr_type type);
struct expr_str *A4GL_new_expr_neg(struct expr_str *ptr);
struct expr_str *A4GL_new_expr_push_variable(struct variable_usage *v,int isinreport) ;
struct expr_str *A4GL_new_expr_reference(struct expr_str *expr) ;
struct expr_str *A4GL_new_expr_param(char *name, int isReference);
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
struct expr_str *A4GL_new_expr_wordwrap(struct expr_str *ptr,struct expr_str *wrap_at);
struct expr_str *A4GL_new_expr_pdf_fcall(char *function,struct expr_str_list *params,char *mod,int line,char *p_namespace);
int A4GL_is_just_int_literal (expr_str * e, long val);
struct expr_str *A4GL_new_variable_usage_with_asc_desc(struct expr_str *var_usage,char *Asc_Desc);

struct str_list *new_str_list(char *str);
struct str_list *add_str_list(struct str_list *n, char *str);
char *expr_as_string(expr_str *s);
struct expr_str *A4GL_new_expr_list_with_list (expr_str_list *list);
char *A4GL_expr_is_single_string(struct expr_str_list *ptr);
char *A4GL_expr_starts_with_single_string(struct expr_str_list *ptr);
int A4GL_is_just_expr_clipped(char *v,struct expr_str_list *ptr);
int get_variable_dtype_from_variable_expression(expr_str *ptr);
struct expr_str *A4GL_new_quoted_string (char *value);
struct expr_str *A4GL_new_expr_aligned(enum e_expr_type etype, struct expr_str *text, struct expr_str *to);
struct expr_str *A4GL_new_expr_tag(struct expr_str *text, struct expr_str *tag) ;
struct expr_str *A4GL_new_select_list_item_expr(struct s_select_list_item *s) ;
struct expr_str * A4GL_new_expr_member_fcall_n (struct expr_str *var_usage_ptr, char *funcname, char *objtype, int datatype, struct expr_str_list *params, char *mod, int line, char *p_namespace) ;

//struct expr_str *new_select_list_query(struct s_select *s1);
#ifdef MOVED
int input_funcname(char *rn, char **r, int isptr, int arr);

int input_sql_ident(char *rn, char **r, int isptr, int arr);
int input_str(char *rn, char **r, int isptr, int arr);
int output_funcname(char *n, char *r, int isptr, int arr);
int output_sql_ident(char *n, char *r, int isptr, int arr);
int output_str(char *n, char * r, int isptr, int arr);
#endif


#endif
