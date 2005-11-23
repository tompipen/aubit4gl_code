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
LIB_PREFIX LEXLIB_
* Name of the header file to be referenced with #include
HEADER_FILE "API_lex_int.h"

#ifdef DEBUG
#undef DEBUG
#endif
#include "variables.h"
#include "field_handling.h"
* ======================================================================
* Function calls definitions:
* func-name param-type param-name ... -> returns
*

/* ------------ functions from compile_[c|perl].c -------------- */

A4GL_internal_lex_printc char* fmt va_list* ap -> void 

A4GL_internal_lex_printh char* fmt   va_list* ap -> void 

A4GL_internal_lex_printcomment char* fmt va_list* ap -> void 

print_sleep t_expr_str* expr -> void

print_include char* s -> void

print_push_variable char* s -> void

print_clr_status -> void

A4GL_incprint -> void

print_repctrl_block -> void

print_report_ctrl -> void

print_range_check char* var,char* size -> void

print_start_block int n -> void

print_continue_block int n,int brace char* why -> void

print_end_block int n -> void

print_continue_loop int n,char* s -> void

print_exit_loop int type,int n -> void

print_rep_ret int report_cnt int dolog -> void

A4GL_prchkerr int l,char* f -> void

print_expr void* ptr -> void

print_arr_expr_fcall void* ptr -> char*



print_bind_pop1 char i -> void

print_bind_pop2 t_expr_str_list* exprlist char i -> void

print_param char i char* funcname -> int

print_bind char i -> int

print_bind_definition char i -> int

print_bind_set_value char i -> int

print_bind_expr void* ptr,char i -> int

print_screen_mode int n -> void

print_start_server char* port,char* funclist -> void

print_stop_external -> void

print_remote_func char* identifier -> void

print_exec_sql char* s -> void

print_exec_sql_bound char* s -> void

print_pop_variable char* s -> void

print_getfldbuf char* fields -> void



print_form_is_compiled char* s char* packer char* formtype -> void

print_field_func char type,char* name,char* var -> void

print_func_call t_expr_str* call -> void

print_class_func_call char* var,char* identifier,void* args,int args_cnt -> void

print_pdf_call char* a1,t_expr_str_list* args,char* a3 -> void


print_call_shared t_expr_str_list* expr char* libfile,char* funcname -> void


*   print_call_shared_bound char* libfile char* funcname -> void

*   print_end_call_shared -> void

*   print_call_external t_expr_str_list* expr char* host,char* funcname,char* port -> void

* print_end_call_external -> void

print_case t_expr_str* expr -> void

print_after_when int endofblock -> void

print_when int has_expr t_expr_str* expr -> void
print_otherwise -> void

print_close char type,char* name -> void

print_construct_1 -> void

print_construct_2 char* driver -> void

print_construct_fl int byname,char* constr_str,t_field_list* field_list,char* attr,int cattr -> void

print_befaft_field_1 char* fieldexpr -> void

print_befaft_field_2 -> void

print_onkey_1 char* key_list_str -> void

print_onaction_1 char* action -> void

print_onaction_2  -> void

print_ontimer_1 char* action -> void

print_ontimer_2  -> void

print_onkey_2 -> void

print_onkey_2_prompt -> void

print_defer int quit -> void


A4GL_get_display_str int type,char* s,char* f -> char*
rettype char* s -> char*

* get_call_shared_bound_expr  char* lib char* name -> void*

print_display_new t_expr_str_list* exprs t_dt_display* disp char* attr -> void

print_display_form char* s,char* a -> void

print_display_array_p1 char* arrvar,char* srec,char* scroll,char* attr,void* iattr -> void

print_display_array_p2 -> void

print_error t_expr_str_list* expr char* s,int wait -> void

print_exit_program t_expr_str* expr -> void

print_for_start char* var void* from void* to void* step -> void
print_for_step char* var void* from void* to void* step -> void
print_for_end char* var void* from void* to void* step -> void
print_case_end -> void


* get_for_default_step -> void*

print_foreach_start -> void

print_foreach_next char* cursorname,int has_using, char* into -> void

print_foreach_end char* cname -> void

print_foreach_close char* cname -> void

print_pushchar char* s -> void

print_goto char* label -> void

print_gui_do_menuitems char* list,int mode -> void

print_gui_do_fields char* list,int mode -> void

print_gui_do_form char* name,char* list,int mode -> void

print_if_start t_expr_str* ptr -> void

print_if_else -> void

print_if_end -> void

print_import char* funcname,int nargs -> void

print_init -> void

print_init_table char* s -> void

print_validate  -> void

A4GL_generate_or char* out,char* in1,char* in2 -> void

print_next_field char* s -> void

print_input_1 -> void

print_input_2 char* s -> void

print_input_fl int byname,char* defs,char* helpno,t_field_list* fldlist,int attr -> void

print_input_array char* arrvar,char* helpno,char* defs,char* srec,char* attr,void* inp_attr -> char*

A4GL_get_formloop_str int type -> char*

print_scroll char* flds,char* updown -> void

print_label char* s -> void

print_let_manyvars t_expr_str_list* expr_list  -> int

print_push_null -> void

print_linked_cmd int type,char* var -> int

print_locate char where,char* var,char* fname -> void

print_start_report char* where,t_expr_str* out,char* repname char* dimsetting -> void

print_output_to_report t_expr_str_list* expr char* repname -> void

print_finish_report char* repname -> void

print_terminate_report char* repname -> void

print_format_every_row -> void

print_need_lines t_expr_str* expr -> void

print_skip_lines double n -> void

print_skip_top -> void

print_skip_by double nval -> void

print_skip_to char* nval -> void

print_report_print int type,char* semi,t_expr_str* expr -> void

print_report_print_file char* fname,char* semi -> void

print_report_print_img char* scaling,char* blob,char* type,char* semi -> void

A4GL_get_default_scaling -> char*

print_order_by_type int type int size -> void

print_report_1 char* name -> void

print_report_end -> void

print_report_2 int pdf,char* repordby -> void
print_report_2_1 -> void

print_pause char* msg -> void

print_op char* type -> void

print_niy char* type -> void

print_message t_expr_str_list* expr int type,char* attr,int wait -> void

print_system_run void* runstr int type,char* rvar -> void

print_set_conn char* conn -> void

print_set_options char* type,char* id,char* var,char* val -> void

print_while_1 -> void

print_while_2 t_expr_str* expr -> void

print_while_end -> void

print_put char* cname char* putvals -> void

print_prepare char* stmt,char* sqlvar -> void

print_undo_use char* s -> void

print_execute char* stmt,int exec_using -> void

print_execute_immediate char* stmt -> void

print_prompt_1 t_expr_str_list* expr char* a1,char* a2,char* a3,char* a4,int timeout -> void

print_prompt_forchar -> void

print_prompt_end char* s -> void

print_open_window char* name,t_ow_open_window* type t_expr_str* y t_expr_str* x -> void

print_open_form 	char* a1 t_expr_str* a2 -> void
print_open_form_gui 	char* fname char* at_gui,char* like_gui char* disable char* formhandler  -> void

print_open_session char* s,char* v,char* user -> void

print_open_cursor char* cname,int has_using -> void

print_clr_window char* s -> void

print_clr_form char* formname,char* clr,char* defs -> void

print_clr_fields_fl t_field_list* flds,char* defs -> void

print_current_window char* s -> void

print_show_window char* s -> void

print_hide_window char* s -> void

print_show_menu char* mname,char* mhand void* ptr -> void

get_def_mn_file -> void*

print_move_window char* n void* y_expr void* x_expr int rel -> void

print_menu_1 int n -> void
print_menu_1b int n -> void

print_end_menu_1 int n -> void

print_end_menu_2 int n -> void

print_menu_block int n int menu_no -> void

print_menu_block_end int m int n -> void

print_option_op int type,char* n,int mn -> void

print_at_termination char* f -> void

print_func_start_1 char* isstatic,char* fname,int type -> void
print_func_start_2 char* isstatic,char* fname,int type -> void
print_variable_new s_variable* v char scope int level

print_func_args int c -> void

print_func_defret0 -> void

print_func_end -> void

print_main_1 -> void

print_fgllib_start char* db -> void

print_main_end -> void

print_return t_expr_str_list* expr  -> void

print_options char n,char* s -> void

print_set_helpfile char* s -> void

print_set_langfile char* s -> void

print_sql_commit int t -> void

print_fetch_1 -> void

print_fetch_2 -> void

print_fetch_3 t_fetch* ftp char* into -> void

print_init_conn char* db -> void

print_do_select char* s -> void

print_flush_cursor char* s -> void

print_declare char* a1,char* a2,char* a3,int h1,int h2 -> void

print_curr_spec int type,char* s -> char*

print_select_all char* buff -> char*

print_unload char* file,char* delim,char* sql -> void

print_load char* file,char* delim,char* tab,char* list -> void
print_load_str char* file,char* delim,char* sql -> void

print_use_session char* sess -> void

A4GL_get_undo_use -> char*

print_next_form_field char* form,char* field -> void

print_declare_associate_1 char* variable,char* size,char* n -> void

print_declare_associate_2 char* variable,char* size,char* n -> void



A4GL_decode_array_string char* var char* s -> char*

printInitFunctionStack -> void

printDeclareFunctionStack char* functionName -> void

printPushFunction -> void

printPopFunction -> void


/* ----------- functions from compile_[c|perl]_gtk.c ------------------ */


print_formhandler char* name -> void

print_getwin -> void

print_end_formhandler -> void

print_event int type -> void

print_event_2 -> void


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
print_empty_bind char* name -> void

print_dealloc_arr char* s -> void
print_alloc_arr char* s char* dim -> void
print_realloc_arr char* s char* dim -> void

print_free_convertable char* report_name -> void
print_convert_report char* report_name char* fout char* type char* layoutfile char* file_or_pipe -> void
print_Constant int type char* v -> void
print_free_cursor char* s -> void

CLASS_print_reflector -> void
CLASS_set_class_name char* name -> void
CLASS_set_parent_name char* name -> void
CLASS_add_method char* name char* sig -> void
CLASS_print_class_variable_type char* buff -> void
CLASS_get_variable char* s -> char**
CLASS_get_members char* s -> char**
print_gtk_field int type,char* s -> void
print_gtk_field_2 -> void
print_gtk_menuhandler_1 char* name -> void
print_gtk_menuhandler_bsm -> void
print_gtk_menuhandler_bsm_end -> void
print_gtk_menuhandler_on char* s -> void
print_gtk_menuhandler_on_end -> void
print_gtk_menuhandler_end -> void
get_keyval_str char* s -> char*

* get_in_exists_sql char* s char t -> void*
* A4GL_expr_for_call char* ident long params int line char* file -> char*
/* print_display_line -> void */
* print_display_by_name char* attr -> void
* print_start_record int isstatic_extern char* varname char* arrsize int level -> void
* print_end_record char* vname char* arrsize int level -> void
* A4GL_get_push_literal char type,char* value -> char*
* print_define_char char* var,int size,int isstatic_extern -> void
* print_define char* varstring,int isstatic_extern -> void
* print_returning -> void
/*  ============================== EOF ================================= */





