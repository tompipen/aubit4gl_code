/*
void check_module(struct module_definition *d);
int check_program(module_definition *mods, int nmodules);
char *dtype_as_string(int dtype);
void A4GL_lint (char *module, int line, char *code, char *type, char *extra);
*/

int add_global_variable_assignement(char *s, char *currfunc, char *module, int line);
expr_str *get_expr_datatype(int n);
char *dtype_as_string(int dtype);
void lint_warnings(int n, struct lint_warning *v);
int local_is_valid_vname(struct variable *v, char scope);
//void check_variable_name(char *modname, char *scope, struct variable *v);
int has_variable(struct variable_list *v, char *name);
void check_module(struct module_definition *d);
int find_function_single_rtype(char *funcname);
int check_program(module_definition *mods, int nmodules);
//void set_lint_module(char *s);
void A4GL_lint(char *module_in, int lintline, char *code, char *type, char *extra);
void open_lintfile(char *s);
void close_lintfile(void);
int get_lint_style(void);
void dump_prototypes(void);
//int is_bolton_function(char *s);
void gen_function_prototypes(int e, struct s_function_definition *function_definition);
void create_protos_from_module(module_definition *this_module);
void log_proto(struct expr_str *fcall, struct expr_str_list *ret);

