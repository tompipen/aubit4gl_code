*
* API specs for LEX library interface - used by dlmagic script
* to create API_lex.c (try "make API_lex.c")
*
* Note - there are no spaces for void* int* etc.
*
*
*
* Name of the API:
LIBRARY LEX
* Name of the variable which will have second part of library name to load:
VARIABLE A4GL_LEXTYPE
* Add prefix for created API punctions:
*API_PREFIX LEXAPI_
* Add prefix for existing library functions:
*LIB_PREFIX LEXLIB_
* Name of the header file to be referenced with #include
HEADER_FILE "API_lex_int.h"

#ifdef DEBUG
#undef DEBUG
#endif
* ======================================================================
* Function calls definitions:
* func-name param-type param-name ... -> returns
*

/* ------------ functions from compile_[c|perl].c -------------- */

/* void printc(char *fmt, ...) */
A4GL_internal_lex_printc char* fmt va_list* ap -> void 

/* printh (char *fmt, ...) */
A4GL_internal_lex_printh char* fmt   va_list* ap -> void 

/* void printcomment (char *fmt,...) */
A4GL_internal_lex_printcomment char* fmt va_list* ap -> void 

/* void print_sleep (void) */
print_sleep -> void

/* void print_include(char *s) */
print_include char* s -> void

/* void print_push_variable (char *s) */
print_push_variable char* s -> void

/* void print_clr_status () */
print_clr_status -> void

/* void incprint(void) */
A4GL_incprint -> void

/* void print_repctrl_block (void) */
print_repctrl_block -> void

/* void print_report_ctrl(void) */
print_report_ctrl -> void

/* void print_range_check (char *var, char *size) */
print_range_check char* var,char* size -> void

/* void print_start_block (int n) */
print_start_block int n -> void

/* void print_continue_block (int n, int brace) */
print_continue_block int n,int brace -> void

/* void print_end_block (int n) */
print_end_block int n -> void

/* void print_continue_loop (int n) */
print_continue_loop int n,char* s -> void

/* void print_exit_loop (int type, int n) */
print_exit_loop int type,int n -> void

/* void print_rep_ret (int report_cnt,int logit) */
print_rep_ret int report_cnt int dolog -> void

/* prchkerr (int l, char *f) */
A4GL_prchkerr int l,char* f -> void

/* void print_expr (struct expr_str *ptr) */
print_expr void* ptr -> void

print_arr_expr_fcall void* ptr -> char*

/* void print_bind_pop1 (char i) */
print_bind_pop1 char i -> void

/* int print_param (char i) */
print_param char i -> int

/* int print_bind (char i) */
print_bind char i -> int

print_bind_definition char i -> int

print_bind_set_value char i -> int

/* int print_bind_expr (void *ptr, char i) */
print_bind_expr void* ptr,char i -> int

/* void print_screen_mode (int n) */
print_screen_mode int n -> void

/* void print_start_server (char * port, char *funclist) */
print_start_server char* port,char* funclist -> void

/* void print_stop_external () */
print_stop_external -> void

/* void print_remote_func (char *identifier) */
print_remote_func char* identifier -> void

/* void print_exec_sql (char *s) */
print_exec_sql char* s -> void

/* void print_exec_sql_bound (char *s) */
print_exec_sql_bound char* s -> void

/* void print_pop_variable (char *s) */
print_pop_variable char* s -> void

/* void print_getfldbuf (char *fields) */
print_getfldbuf char* fields -> void

/* void print_returning () */
print_returning -> void


/* void print_form_is_compiled (char *s) */
print_form_is_compiled char* s char* packer char* formtype -> void

/* void print_field_func (char type, char *name, char *var ) */
print_field_func char type,char* name,char* var -> void

/* void print_func_call (char *identifier, struct expr_str *args, int args_cnt) */
print_func_call char* identifier,void* args,int args_cnt -> void

/* void print_class_func_call (char *var,char *identifier, struct expr_str *args, int args_cnt) */
print_class_func_call char* var,char* identifier,void* args,int args_cnt -> void

/* void print_pdf_call (char *a1, struct expr_str *args, char *a3) */
print_pdf_call char* a1,void* args,char* a3 -> void

/* void print_call_shared (char *libfile, char *funcname, int nargs) */
print_call_shared char* libfile,char* funcname,int nargs -> void


/* void print_call_shared_bound (char *libfile, char *funcname) */
print_call_shared_bound char* libfile char* funcname -> void

/* void print_end_call_shared () */
print_end_call_shared -> void

/* void print_call_external (char *host, char *func, char *port, int nargs) */
/* had to rename func because of collision with API function variable */
print_call_external char* host,char* funcname,char* port,int nargs -> void

/* void print_end_call_external () */
print_end_call_external -> void

/* void print_case (int has_expr) */
print_case int has_expr -> void

/* void print_after_when (int endofblock) */
print_after_when int endofblock -> void

/* void print_when (int has_expr) */
print_when int has_expr -> void

/* void print_close (char type, char *name) */
print_close char type,char* name -> void

/* void print_construct_1 () */
print_construct_1 -> void

/* void print_construct_2 (char *driver) */
print_construct_2 char* driver -> void

/* void print_construct_3 (int byname, char *constr_str, char *field_list, char *attr) */
print_construct_3 int byname,char* constr_str,char* field_list,char* attr,int cattr -> void

/* void print_befaft_field_1 (char *fieldexpr) */
print_befaft_field_1 char* fieldexpr -> void

/* void print_befaft_field_2 () */
print_befaft_field_2 -> void

/* void print_onkey_1 (char *key_list_str) */
print_onkey_1 char* key_list_str -> void

/* void print_onkey_2 () */
print_onkey_2 -> void

/* void print_onkey_2_prompt () */
print_onkey_2_prompt -> void

/* void print_defer (int quit) */
print_defer int quit -> void

/* void print_display_line () */
print_display_line -> void

/* void print_display_by_name (char *attr) */
print_display_by_name char* attr -> void

/* char * get_display_str (int type, char *s, char *f) */
A4GL_get_display_str int type,char* s,char* f -> char*

get_call_shared_bound_expr  char* lib char* name -> void*

/* void print_display (char *fmt, char *expr, char *attr) */
print_display char* fmt,char* expr,char* attr -> void

/* void print_display_form (char *s, char *a) */
print_display_form char* s,char* a -> void

/* void print_display_array_p1 (char *arrvar, char *srec, char *scroll,char *attr) */
print_display_array_p1 char* arrvar,char* srec,char* scroll,char* attr,void* iattr -> void

/* void print_display_array_p2 () */
print_display_array_p2 -> void

/* void print_error (char *s, int wait) */
print_error char* s,int wait -> void

/* void print_exit_program (int has_expr) */
print_exit_program int has_expr -> void

/* void print_for_start (char *var) */
print_for_start char* var -> void

/* void print_for_end () */
print_for_end -> void

/* void print_for_default_step () */
print_for_default_step -> void

/* void print_foreach_start () */
print_foreach_start -> void

/* void print_foreach_next (char *cursorname, int has_using, char *into) */
print_foreach_next char* cursorname,int has_using, char* into -> void

/* void print_foreach_end () */
print_foreach_end char* cname -> void

/* void print_foreach_end () */
print_foreach_close char* cname -> void

/* void print_pushchar (char *s) */
print_pushchar char* s -> void

/* void print_goto (char *label) */
print_goto char* label -> void

/* void print_gui_do_menuitems (char *list, int mode) */
print_gui_do_menuitems char* list,int mode -> void

/* void print_gui_do_fields (char *list, int mode) */
print_gui_do_fields char* list,int mode -> void

/* void print_gui_do_form (char *name, char *list, int mode) */
print_gui_do_form char* name,char* list,int mode -> void

/* void print_if_start () */
print_if_start -> void

/* void print_if_else () */
print_if_else -> void

/* void print_if_end () */
print_if_end -> void

/* void print_import (char *func, int nargs) */
/* have to rename func because of collision in API */
print_import char* funcname,int nargs -> void

/* void print_init () */
print_init -> void

/* void print_init_table (char *s) */
print_init_table char* s -> void

/* void print_validate () */
print_validate  -> void

/* void generate_or (char *out, char *in1, char *in2) */
A4GL_generate_or char* out,char* in1,char* in2 -> void

/* void print_next_field (char *s) */
print_next_field char* s -> void

/* void print_input_1 () */
print_input_1 -> void

/* void print_input_2 (char *s) */
print_input_2 char* s -> void

/* void print_input (int byname, char *defs, char *helpno, char *fldlist) */
print_input int byname,char* defs,char* helpno,char* fldlist,int attr -> void

/* char * print_input_array (char *arrvar, char *helpno, char *defs, char *srec, char *attr) */
print_input_array char* arrvar,char* helpno,char* defs,char* srec,char* attr,void* inp_attr -> char*

/* char * get_formloop_str (int type) */
A4GL_get_formloop_str int type -> char*

/* void print_scroll (char *flds, char *updown) */
print_scroll char* flds,char* updown -> void

/* void print_label (char *s) */
print_label char* s -> void

/* int print_let_manyvars (char *nexprs) */
print_let_manyvars char* nexprs -> int

/* void print_push_null () */
print_push_null -> void

/* int print_linked_cmd (int type, char *var) */
print_linked_cmd int type,char* var -> int

/* void print_locate (char where, char *var, char *fname) */
print_locate char where,char* var,char* fname -> void

/* void print_start_report (char *where, char *out, char *repname) */
print_start_report char* where,char* out,char* repname char* dimsetting -> void

/* void print_output_to_report (char *repname, char *nvalues) */
print_output_to_report char* repname,char* nvalues -> void

/* void print_finish_report (char *repname) */
print_finish_report char* repname -> void

print_terminate_report char* repname -> void

/* void print_format_every_row () */
print_format_every_row -> void

/* void print_need_lines () */
print_need_lines -> void

/* void print_skip_lines () */
print_skip_lines double n -> void

/* void print_skip_top () */
print_skip_top -> void

/* void print_skip_by (char *nval) */
print_skip_by double nval -> void

/* void print_skip_to (char *nval)    */
print_skip_to char* nval -> void

/* void print_report_print (int type, char *semi, char *wordwrap) */
print_report_print int type,char* semi,char* wordwrap -> void

/* void print_report_print_file (char *fname, char *semi) */
print_report_print_file char* fname,char* semi -> void

/* void print_report_print_img (char *scaling, char *blob, char *type, char *semi) */
print_report_print_img char* scaling,char* blob,char* type,char* semi -> void

/* char * get_default_scaling () */
A4GL_get_default_scaling -> char*

/* void print_order_by_type (int type) */
print_order_by_type int type int size -> void

/* void print_report_1 (char *name) */
print_report_1 char* name -> void

/* void print_report_end () */
print_report_end -> void

/* void print_report_2 (int pdf, char *repordby) */
print_report_2 int pdf,char* repordby -> void

/* void print_pause (char *msg) */
print_pause char* msg -> void

/* void print_op (char *type) */
print_op char* type -> void

/* void print_niy (char *type) */
print_niy char* type -> void

/* void print_message (int type, char *attr, int wait,int exprs) */
print_message int type,char* attr,int wait,int exprs -> void

/* void print_system_run (int type, char *rvar) */
print_system_run int type,char* rvar -> void

/* void print_set_conn (char *conn) */
print_set_conn char* conn -> void

/* void print_set_options (char *type, char *id, char *var, char *val) */
print_set_options char* type,char* id,char* var,char* val -> void

/* void print_while_1 (void) */
print_while_1 -> void

/* void print_while_2 (void) */
print_while_2 -> void

/* void print_while_3 (void) */
print_while_3 -> void

/* void print_put (char* cname) */
print_put char* cname char* putvals -> void

/* void print_prepare (char *stmt, char *sqlvar) */
print_prepare char* stmt,char* sqlvar -> void

/* void print_undo_use (char *s) */
print_undo_use char* s -> void

/* void print_execute (char *stmt, int exec_using) */
print_execute char* stmt,int exec_using -> void

print_execute_immediate char* stmt -> void

/* void print_prompt_1 (char *a1, char *a2, char *a3, char *a4, int timeout) */
print_prompt_1 char* a1,char* a2,char* a3,char* a4,int timeout -> void

/* void print_prompt_forchar () */
print_prompt_forchar -> void

/* void print_prompt_end (char *s) */
print_prompt_end char* s -> void

/* void print_open_window (char *name, char *type) */
print_open_window char* name,char* type -> void

/* void print_open_form (char *fmt, char *a1, char *a2) */
print_open_form char* fmt,char* a1,char* a2 -> void

/* void print_open_session (char *s, char *v, char *user) */
print_open_session char* s,char* v,char* user -> void

/* void print_open_cursor (char *cname, int has_using) */
print_open_cursor char* cname,int has_using -> void

/* void print_clr_window (char *s) */
print_clr_window char* s -> void

/* void print_clr_form (char *formname, char *clr, char *defs) */
print_clr_form char* formname,char* clr,char* defs -> void

/* void print_clr_fields (char *flds, char *defs) */
print_clr_fields char* flds,char* defs -> void

/* void print_current_window (char *s) */
print_current_window char* s -> void

/* void print_show_window (char *s) */
print_show_window char* s -> void

/* void print_hide_window (char *s) */
print_hide_window char* s -> void

/* void print_show_menu (char *mname, char *mhand) */
print_show_menu char* mname,char* mhand -> void

/* void print_def_mn_file ()  */
print_def_mn_file -> void

/* void print_move_window (char *n, int rel) */
print_move_window char* n,int rel -> void

/* void print_menu_1 (void) */
print_menu_1 int n -> void
print_menu_1b int n -> void

/* void print_end_menu_1 (void) */
print_end_menu_1 int n -> void

/* void print_end_menu_2(void) */
print_end_menu_2 int n -> void

/* void print_menu_block (int n) */
print_menu_block int n int menu_no -> void

/* void print_menu_block_end () */
print_menu_block_end int n -> void

/* void print_option_op (int type, char *n) */
print_option_op int type,char* n,int mn -> void

/* void print_at_termination (char *f) */
print_at_termination char* f -> void

/* void print_func_start (char *isstatic, char *fname, int type) */
print_func_start char* isstatic,char* fname,int type -> void

/* void print_func_args (int c) */
print_func_args int c -> void

/* void print_func_defret0 () */
print_func_defret0 -> void

/* void print_func_end () */
print_func_end -> void

/* void print_main_1 () */
print_main_1 -> void

/* void print_fgllib_start (char *db) */
print_fgllib_start char* db -> void

/* void print_main_end () */
print_main_end -> void

/* void print_return (int n) */
print_return int n -> void

/* void print_options (char n, char *s) */
print_options char n,char* s -> void

/* void print_set_helpfile (char *s) */
print_set_helpfile char* s -> void

/* void print_set_langfile (char *s) */
print_set_langfile char* s -> void

/* void print_sql_commit (int t) */
print_sql_commit int t -> void

/* void print_fetch_1 () */
print_fetch_1 -> void

/* void print_fetch_2 () */
print_fetch_2 -> void

/* void print_fetch_3 (char *ftp, char *into) */
print_fetch_3 char* ftp,char* into -> void

/* void print_init_conn (char *db) */
print_init_conn char* db -> void

/* void print_do_select (char *s) */
print_do_select char* s -> void

/* void print_flush_cursor (char *s) */
print_flush_cursor char* s -> void

/* void print_declare (char *a1, char *a2, char *a3, int h1, int h2) */
print_declare char* a1,char* a2,char* a3,int h1,int h2 -> void

/* char * print_curr_spec (int type, char *s) */
print_curr_spec int type,char* s -> char*

/* char * print_select_all (char *buff) */
print_select_all char* buff -> char*

/* void print_unload (char *file, char *delim, char *sql) */
print_unload char* file,char* delim,char* sql -> void

/* void print_load (char *file, char *delim, char *tab, char *list) */
print_load char* file,char* delim,char* tab,char* list -> void
print_load_str char* file,char* delim,char* sql -> void

/* void print_use_session (char *sess) */
print_use_session char *sess -> void

/* char * get_undo_use (void) */
A4GL_get_undo_use -> char*

/* void print_next_form_field (char *form, char *field) */
print_next_form_field char* form,char* field -> void

/* void print_declare_associate_1 (char *variable, char *size, char *n) */
print_declare_associate_1 char* variable,char* size,char* n -> void

/* void print_declare_associate_2 (char *variable, char *size, char *n) */
print_declare_associate_2 char* variable,char* size,char* n -> void

/* void print_define_char (char *var, int size, int isstatic_extern) */
print_define_char char* var,int size,int isstatic_extern -> void

/* void print_define (char *varstring, int isstatic_extern) */
print_define char* varstring,int isstatic_extern -> void

/* void print_start_record (int isstatic_extern, char *varname,char *arrsize,int level) */
print_start_record int isstatic_extern,char* varname,char *arrsize,int level -> void

/* void print_end_record (char *vname, char *arrsize) */
print_end_record char* vname,char* arrsize,int level -> void

/* char * get_push_literal (char type, char *value) */
A4GL_get_push_literal char type,char* value -> char*

/* char *decode_array_string(char *s) */
A4GL_decode_array_string char* s -> char*

/* void printInitFunctionStack(void) */
printInitFunctionStack -> void

/* void printDeclareFunctionStack(char *functionName) */
printDeclareFunctionStack char* functionName -> void

/* void printPushFunction(void) */
printPushFunction -> void

/* void printPopFunction(void) */
printPopFunction -> void


/* ----------- functions from compile_[c|perl]_gtk.c ------------------ */


/* print_formhandler (char *name) */
print_formhandler char* name -> void

/* print_getwin()  */
print_getwin -> void

/* print_end_formhandler () */
print_end_formhandler -> void

/* print_event (int type) */
print_event int type -> void

/* print_event_2 () */
print_event_2 -> void

/* print_gtk_field (int type, char *s) */
print_gtk_field int type,char* s -> void

/* print_gtk_field_2 () */
print_gtk_field_2 -> void

/* print_gtk_menuhandler_1 (char *name) */
print_gtk_menuhandler_1 char* name -> void

/* print_gtk_menuhandler_bsm () */
print_gtk_menuhandler_bsm -> void

/* print_gtk_menuhandler_bsm_end () */
print_gtk_menuhandler_bsm_end -> void

/* print_gtk_menuhandler_on (char *s) */
print_gtk_menuhandler_on char* s -> void

/* print_gtk_menuhandler_on_end () */
print_gtk_menuhandler_on_end -> void

/* print_gtk_menuhandler_end() */
print_gtk_menuhandler_end -> void

get_column_transform char* s -> char*

print_module_variable_init -> void

print_cmd_start -> void

print_import_legacy char* s -> void


print_cmd_end -> void

A4GL_get_into_part int d int n -> char*
A4GL_add_put_string char* buff -> void

A4GL_set_var_sql int d int n -> char*

A4GL_lex_parsed_fgl -> void
A4GL_bad_identifiers char* ident -> int
print_sql_block_cmd char* sql -> void
A4GL_expr_for_call char* ident char* params int line char* file -> char*
print_empty_bind char* name -> void

print_dealloc_arr char* s -> void
print_alloc_arr char* s char* dim -> void
print_realloc_arr char* s char* dim -> void
get_in_exists_sql char* s char t -> void*

print_free_convertable char* report_name -> void
print_convert_report char* report_name char* fout char* type char* layoutfile char* file_or_pipe -> void
print_Constant int type char* v -> void

CLASS_print_reflector -> void
CLASS_set_class_name char* name -> void
CLASS_set_parent_name char* name -> void
CLASS_add_method char* name char* sig -> void
CLASS_print_class_variable_type char* buff -> void
CLASS_get_variable char* s -> char**
CLASS_get_members char* s -> char**

/*  ============================== EOF ================================= */





