int local_is_system_variable(struct variable *v);
//void set_suppress_lines(void);
//void clr_suppress_lines(void);
void printc(char *fmt, ...);
void printh(char *fmt, ...);
void A4GL_internal_lex_printh(char *fmt, va_list *ap);
void printcomment(char *fmt, ...);
void A4GL_internal_lex_printcomment(char *fmt, va_list *ap);
void A4GL_incprint(void);
void print_repctrl_block(int report_cnt, int report_stack_cnt, int curr_lineno);
void print_include(char *s);
//void print_report_ctrl(int report_cnt, char *curr_rep_name, int rep_type, int report_stack_cnt);
void print_range_check(char *var, char *size);
void print_start_block(int n);
void print_continue_block(int n, int brace, char *why);
void print_end_block(int n);
void print_continue_loop(int n, char *cmd_type);
void print_exit_loop(int type, int n, char *cmdtype);
void print_rep_ret(int report_cnt, int addit);
void print_report_2_1(void);
void print_clr_status(void);
void A4GL_prchkerr(int l, int isSql);
void print_expr(void *ptr);
char *print_arr_expr_fcall(void *optr);
struct expr_str_list *A4GL_rationalize_list_concat(struct expr_str_list *l);
void print_bind_pop2_g(t_expr_str_list *ptr, struct expr_str_list *b, char type);
int print_param_g(char i, char *fname, struct expr_str_list *bind);
void print_screen_mode(int n);
void print_start_server(char *port, char *funclist);
void print_stop_external(void);
void print_remote_func(char *identifier, int yylineno);
void print_form_is_compiled(char *s, char *packer, char *formtype);
void print_field_func(char type, char *name, char *var, int yylineno);
void print_func_call_g(t_expr_str *fcall, struct expr_str_list *return_values);
void print_class_func_call(char *var, char *identifier, void *args, int args_cnt, int yylineno);
void print_pdf_call_g(char *a1, struct expr_str_list *args, char *a3, struct expr_str_list *returning_values, int yylineno);
void print_call_shared_g(t_expr_str_list *expr, char *libfile, char *funcname, struct expr_str_list *returning_values, int yylineno);
void print_case(t_expr_str *expr);
void print_after_when(int endofblock);
void print_when(int has_expr, t_expr_str *expr);
void print_otherwise(void);
void print_construct_1(void);
void print_construct_2(char *driver);
void print_construct_fl_g(int byname, struct expr_str_list *bind, t_field_list *f_list, char *attr, int cattr, char *Style);
void print_befaft_field_1(char *fieldexpr);
void print_befaft_field_2(void);
void print_onkey_1(char *key_list_str);
void print_onkey_2(void);
void print_onkey_2_prompt(void);
void print_onaction_1(char *key_list_str);
void print_onaction_2(void);
void print_ontimer_1(char *key_list_str);
void print_ontimer_2(void);
void print_defer(int quit);
char *A4GL_get_display_str(int type, char *s, char *f);
void print_display_new(t_expr_str_list *expr, struct dt_display *disp, char *attr, char *Style);
void print_display_form(char *s, char *a, char *Style);
void print_display_array_p1(char *arrvar, char *srec, char *scroll, char *attr, void *v_input_attr, char *Style, struct expr_str_list *bind, char *slice, int start_slice, int end_slice);
void print_display_array_p2(void);
void print_error(t_expr_str_list *expr, char *s, int wait, char *Style);
void print_exit_program(t_expr_str *expr);
void print_for_start(char *var, void *vfrom, void *vto, void *vstep);
void print_for_step(char *var, void *vfrom, void *vto, void *vstep);
void print_for_end(char *var, void *vfrom, void *vto, void *vstep);
void print_foreach_start(void);
void print_pushchar(char *s);
void print_goto(char *label);
void print_gui_do_menuitems(char *list, int mode);
void print_gui_do_fields(char *list, int mode);
void print_gui_do_form(char *name, char *list, int mode);
void print_if_start(t_expr_str *ptr);
void print_if_else(void);
void print_if_end(void);
int split_arrsizes(char *s, int *arrsizes);
void print_init_var_from_expr(struct expr_str *v, char *prefix, int alvl, int explicit);
void print_init_var(struct variable  *v, char *prefix, int alvl, int explicit,int prefixIncludesName, int expand_array);
void print_init_g(struct expr_str_list *bind, int explicit);
void A4GL_generate_or(char *out, char *in1, char *in2);
void print_next_field(char *s);
void print_input_1(void);
void print_input_2(char *s);
void print_input_fl_g(int byname, char *defs, char *helpno, struct fh_field_list *fldlist_fh, char *sattr, char *Style, struct expr_str_list *bind);
char *print_input_array(char *arrvar, char *helpno, char *defs, char *srec, char *attr, void *v_input_attr, char *Style, struct expr_str_list *bind, char *slice, int inp_flags, int start_slice, int end_slice);
char *A4GL_get_formloop_str(int type);
void print_scroll(char *flds, char *updown);
void print_label(char *s);
int print_let_manyvars_g(t_expr_str_list *ptr, struct expr_str_list *bind);
void print_push_null(void);
void print_start_report(char *where, t_expr_str *out, char *repname, char *dim);
void print_output_to_report(t_expr_str_list *expr, char *repname);
void print_finish_report(char *repname);
void print_terminate_report(char *repname);
void print_need_lines(t_expr_str *expr);
void print_skip_lines(double d);
void print_skip_top(void);
void print_skip_by(double nval);
void print_skip_to(char *nval);
void print_report_print(int type, char *semi, t_expr_str *expr);
void print_report_print_file(char *fname, char *semi);
void print_report_print_img(char *scaling, char *blob, char *type, char *semi);
int print_order_by_type(int type, int size, struct expr_str_list *ordbind);
void print_report_1(char *name);
void print_report_end(void);
void print_report_2_g(int pdf, char *repordby, char *asc_desc, struct expr_str_list *bind, struct expr_str_list *orderbind, int report_cnt, char *curr_rep_name);
void print_pause(char *msg);
void print_sleep(t_expr_str *expr);
void print_op(char *type);
//void print_niy(char *type);
void print_push_variable(char *s);
void print_message(t_expr_str_list *expr, int type, char *attr, int wait, char *Style);
void print_system_run(void *expr, int type, char *rvar);
void print_set_options(char *type, char *id, char *var, char *val);
void print_while_1(void);
void print_while_2(t_expr_str *expr);
void print_while_end(void);
void print_case_end(void);
void print_case_free(void);
//void print_undo_use(char *s);
void print_prompt_1(t_expr_str_list *expr, char *a1, char *a2, char *a3, char *a4, int timeout, char *Style, char *promptvar);
void print_prompt_forchar(void);
void print_prompt_end(char *s);
void print_open_window(char *name, t_ow_open_window *type, t_expr_str *y, t_expr_str *x, char *Text, char *Style);
void print_open_form(char *a1, t_expr_str *a2);
void print_open_form_gui(char *name, char *at_gui, char *like_gui, char *disable, char *formhandler);
void print_clr_window(char *s);
void print_clr_form(char *formname, char *clr, char *defs);
void print_clr_fields_fl(t_field_list *fl, char *defs);
void print_current_window(char *s);
void print_show_window(char *s);
void print_hide_window(char *s);
void print_show_menu(char *mname, char *mhand, void *ptr);
void *get_def_mn_file(void);
void print_move_window(char *n, void *ptr1, void *ptr2, int rel);
void print_menu_1(int n);
void print_menu_1b(int n);
void print_option_op(int type, char *n, int mn);
void print_at_termination(char *f);
void printInitFunctionStack(void);
void printDeclareFunctionStack(char *_functionName);
void printPushFunction(int yylineno);
void printPopFunction(void);
void print_func_start_1(char *isstatic, char *fname, int type);
void print_func_start_2(char *isstatic, char *fname, int type);
void print_func_args(int c, int yylineno);
void print_func_defret0(void);
void print_func_end(void);
void print_main_1(void);
void print_fgllib_start (char *db, int is_schema,char *force_ui,char *debug_filename);
void print_main_end(void);
void print_return(t_expr_str_list *expr);
void print_options(char n, char *s);
void print_set_helpfile(char *s);
void print_set_langfile(char *s);
void print_fetch_2_g(struct expr_str_list *bind);
void print_next_form_field(char *form, char *field);
void print_declare_associate_1(char *variable, char *size, char *n);
void print_declare_associate_2(char *variable, char *size, char *n);
void print_define_char(char *var, int size, int isstatic_extern);
void print_define(char *varstring, int isstatic_extern);
void print_start_record(int isstatic_extern, char *varname, char *arrsize, int level);
char *A4GL_decode_array_string(char *var, char *s);
char *A4GL_get_into_part(expr_str_list *into);
char *A4GL_set_var_sql(int doing_declare, int n, char *current_upd_table);
//enum e_dialect esql_type(void);
void A4GL_lex_parsed_fgl(void);
void print_import_legacy(char *s);
void add_function_to_header(char *identifier, char *namespace, int params, int is_static);
void add_class_function_to_header(char *identifier, int params, char *is_static);
void print_foreach_close(char *cname);
int A4GL_doing_pcode(void);
int doing_cs(void);
void print_empty_bind(char *name);
void print_execute_immediate(char *stmt);
void print_alloc_arr(char *s, char *d);
void print_realloc_arr(char *s, char *d);
void print_dealloc_arr(char *s);
struct expr_str *A4GL_add_validation_elements_to_expr(struct expr_str *ptr, char *val);
void print_event_list(struct on_events* evtlist );
int *get_key_codes(char *keys);
char **get_field_codes(char *fields);
int print_bind_definition_g(struct expr_str_list *l, char i);
int print_bind_dir_definition_g(struct expr_str_list *lbind, int ignore_esql, char lbind_type);
int local_print_bind_set_value_g(struct expr_str_list *bind, int ignore_esqlc, int only_native, char type);
int print_bind_set_value_g(struct expr_str_list *bind, char type);
char *get_reset_state_after_call(int n);
void print_reset_state_after_call(int n);
void print_convert_report_via(char *repname, char *fname);
void print_convert_report(char *repname, char *fname, char *otype, char *layout, char *file_or_pipe);
void print_free_convertible(char *repname);
void print_import(char *func, int nargs, int yylineno);
char *pdtype(int n);
void print_Constant_1(char *name, struct constant_data *c);
void print_variable_new(struct variable *v, char scope, int level);
//char *rettype(char *s);
char *get_keyval_str(char *s);
int print_agg_defines(char t, int a);
//void A4GL_initlex(void);
void A4GL_whenchange(int n);
char *A4GL_field_name_as_char(char *fname, char *sub);
char *get_array_rebase(char *s);
char *change_arr_elem(char *s);
void print_loaded_globals_file(char *s);
void print_start_globals(void);
void print_end_globals(void);
void print_cancel(char *s);
int get_whenever_style(int code, char *whento);
//int check_binding(struct expr_str_list *l, char *fromwhere, int yylineno);
void merge_files(void);
//int LEXLIB_A4GL_write_generated_code(struct module_definition *m);
void print_copy_status_with_sql(int l);
void print_copy_status_not_sql(int l);
void real_print_func_call ( t_expr_str *fcall);
int is_in_report(void) ;
void print_returning_g (int from_where, struct expr_str_list *bind,int allow_one_or_zero);
 void print_form_attrib (struct form_attr *form_attrib);

void print_event_actions (char *loopvar, struct on_events*events) ;


void dump_commands(commands *c) ;
char *local_expr_as_string(expr_str *s);
char *local_ident_as_string(expr_str *s,int quote);
void print_field_list(struct fh_field_list *flist);
void print_pop_usage(expr_str *v);
void print_form_attrib_v2 (int iswindow, struct attrib *form_attrib);
void dump_comments (int n);
void print_close (char type, char *name);
void A4GL_print_expr_list_concat (struct expr_str_list *l);
void print_push_variable_usage (expr_str *ptr);
void set_whenever (int c, char *p);
//int attributes_as_int (struct attrib *a);
void set_nonewlines_full (long l);
void print_str_list(str_list *list);
int get_last_menuid(void);
void real_print_expr_list (struct expr_str_list *l);
void clr_nonewlines (void);
void print_field(struct fh_field_entry*field );
void print_ident (struct expr_str *ptr);
char *local_field_name_list_as_char(struct fh_field_list *fl) ;
char *get_sql_into_buff(struct expr_str_list *into);
char * get_insert_cmd (struct struct_insert_cmd *insertCmd,int *converted);

char * get_ident_as_string (struct expr_str *ptr);
void print_variable_usage(expr_str *v);
char * get_delete_cmd (struct struct_delete_cmd *deleteCmd, int *converted);
char * get_select (struct s_select *s, char *forUpdate);
void search_sql_variables (struct s_select_list_item_list *l,char dir);

char *get_update_cmd(struct struct_update_cmd *updateCmd, int *converted);
void print_report_table (char *repname, char type, int c,char*asc_desc,struct expr_str_list *funcbind, struct expr_str_list *orderbind);
char *get_sql_variable_usage (variable_usage *u ,char dir);
char *get_last_print_bind_dir_definition_g_rval(char dir);
char *escape_quotes_and_remove_nl(char *s) ;

void print_conversions_g (expr_str_list *bind,char dir);
char *get_str_list_as_string(str_list *list,char *sep);
char * c_generation_trans_quote (char *s);

char * A4GL_dtype_sz (int d, int s);
void print_in_subquery(int i, struct s_expr_in_sq *e);
int has_conversions_g (expr_str_list *bind,char dir);
void print_exists_subquery(int i, struct s_expr_exists_sq *e) ;
char *get_current_module_name(void);
char *get_current_module_name_clean(void);
int dump_report (struct s_report_definition *report_definition);
int A4GL_module_has_function(struct module_definition *module, char *s,char *file,struct flist *ptr);
int local_print_agg_defines(char t,int a);
int dump_pdf_report (struct s_pdf_report_definition *report_definition);
int dump_command(struct command_data *cd);
int clr_rep_print_entry(void);
void print_generation_copy_status (void);
int chk_ibind_select(struct s_select *s);
