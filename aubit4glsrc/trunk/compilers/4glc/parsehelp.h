
char *get_module_dbname(void);
char *rettype_integer(int n);
e_boolean get_module_isschema(void);
int A4GL_is_class_static(char *s);
int A4GL_open_class_dll(char *s);
int clr_ignore_indicators(void);
int print_agg_defines(char t, int a);
int push_blockcommand(char *cmd_type);
int set_ignore_indicators(void);
struct command * cmd_display_by_name (expr_str_list *l, attrib *attr);
struct command *print_linked_cmd(int type, struct expr_str *var);
struct command *set_whenever_from_store_cmd(void);
struct expr_str *add_report_agg(char t, struct expr_str *s1, struct expr_str *s2, int a, long *n);
struct on_events *append_event_list(struct on_events *evtlist, struct on_event *evt);
struct on_events *new_event_list(on_event *evt);
void *get_def_mn_file(void);
void A4GL_add_extra_warning(int yylineno, char *msg);
void A4GL_clr_extra_warnings(void);

#ifndef DEFINED_SET_CLOBBER
#define DEFINED_SET_CLOBBER
void A4GL_set_clobber (char *c);
#endif

void A4GL_set_extra_warnings(unsigned int *n, struct lint_warning **l);
/* These are defined in the API_lex */
//int FGLPARSE_A4GL_lexer_find_type(char *s);
//void FGLPARSE_A4GL_lexer_import_package(char *s);
//void FGLPARSE_A4GL_lexer_parsed_fgl(void);
void add_ex_dtype(char *sx);
void add_external_datatypes(char *s);
void add_globals_file_to_this_module(char *s);
void add_module_entry(module_entry *m);
void add_to_call_list_by_call(struct command *c);
void add_to_call_list_by_expr(expr_str *c);
void clr_call_list(void);
void continue_loop(char *cmd_type);
void debug_func(struct module_entry *e);
void do_print_menu_1(void);
void do_print_menu_block_end(int mn);
void dopop_commands(void);
void dopush_commands(void);
void pop_blockcommand(char *cmd_type);
void push_like(char *t);
void push_rectab(char *t);
void push_report_block(char *why, char whytype, char *var);
#ifndef DEFINED_SET_MODULE_DBNAME
#define DEFINED_SET_MODULE_DBNAME
void set_module_dbname(char *db,e_boolean isschema);
#endif

void set_variables(variable_list *v, char why);
void set_whenever(int c, char *p);
void set_whenever_from_store(void);
//struct str_list *new_str_list(char *str);
//struct str_list *add_str_list(struct str_list *n, char *str) ;
char *get_variable_bottom_level_name(struct variable_usage *vu );
int match_variable_usage(variable_usage *u1, variable_usage *u2);
struct s_select_list_item_list *make_select_list_item_list_from_variable_record(char *s) ;
char * get_id_from_variable_usage_expression(expr_str *ptr);
char *get_variable_as_string_from_variable_usage_expression(expr_str *ptr);
void A4GL_ensure_dtype_variables(expr_str_list *s);
void set_report_orderby(struct variable_list *v, struct expr_str_list*params, struct s_report_orderby_section *orderby);
int set_bind_var_dtype(char *type, char *errbuff,struct expr_str_list *bindlist);
struct expr_str *ensure_variable(char *errbuff, struct expr_str *ptr, int err_if_whole_array);
int check_parameters(char *errbuff,struct variable_list *var_list, expr_str_list *parameters);

#ifndef ENCODE_SIZE
#define ENCODE_SIZE(x) (x<<16)S
#endif


void make_cast (char *module,int lineno, struct expr_str *s, int target_dtype, int notnull, int force);
