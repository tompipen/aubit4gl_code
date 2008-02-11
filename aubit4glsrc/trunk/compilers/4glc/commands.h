#ifndef COMMANDS_H
#define COMMANDS_H

#include "a4gl_libaubit4gl.h"
//#include "fgl.xs.h"

expr_str_list * make_expr_str_list( struct expr_str_list *list);
struct command *new_command (enum cmd_type ct);
void clr_attrib(struct attrib *attr ) ;

struct expr_str *new_variable_or_literal ( enum e_expr_type t, char *s); 
typedef struct command t_command;
//typedef struct expr_str_list t_expr_str_list;
struct single_option *new_option (char c, char *v,int isKey);
struct single_option *new_option_expr (char c, struct expr_str *v,int isKey);

struct command *new_cancel_cmd(enum cancel_type p_c);
struct command *new_close_cmd(enum e_close_type_nosql p_type, expr_str *p_ident);
struct command *new_close_sql_cmd(enum e_close_type_withsql p_type, expr_str *p_ident);
struct command *new_free_cmd(expr_str *connid, expr_str *p_cursorname);
struct command *new_continue_cmd(enum e_block_cmd p_what);
struct command *new_ext_cmd(enum e_block_cmd p_what);
struct command *new_defer_cmd(e_defer p_what);
struct command *new_code_cmd(char *p_contents);
struct command *new_disable_menu_cmd(str_list* p_list);
struct command *new_enable_menu_cmd(str_list* p_list);
struct command *new_check_menu_cmd(str_list* p_list);
struct command *new_uncheck_menu_cmd(str_list* p_list);
struct command *new_goto_cmd(char *p_label);
struct command *new_label_cmd(char *p_label);
struct command *new_sleep_cmd(expr_str* p_expr);
struct command *new_move_cmd(expr_str *p_windowname, expr_str* p_x, expr_str* p_y, e_boolean relative);
struct command *new_show_menu_cmd(char *p_menuname, char *p_menuhandler, expr_str* p_mn_file);
struct command *new_show_cmd(expr_str *p_windowname);
struct command *new_hide_cmd(expr_str *p_windowname);
struct command *new_run_cmd(expr_str* p_run_string, e_boolean p_wait, enum run_mode p_run_mode, struct expr_str *p_returning);
struct command *new_scroll_cmd(fh_field_list *p_srec, expr_str* p_val);
struct command *new_exit_prog_cmd(expr_str* p_exit_val);
struct command *new_prepare_cmd (expr_str *connid, struct expr_str *p_stmtid, expr_str * p_sql);
struct command *new_init_cmd(struct expr_str_list* p_varlist, str_list *p_tablist);
struct command *new_next_field_cmd(int p_rel,fh_field_entry* p_fieldname) ;

struct command *new_at_term_cmd(char *p_funcname);
struct command *new_next_option_cmd(expr_str *p_menuoption);
struct command *new_show_option_cmd(expr_str_list* p_menuoptions);
struct command *new_hide_option_cmd(expr_str_list* p_menuoptions);
struct command *new_display_form_cmd(struct expr_str *p_formname, attrib *p_attributes);
struct command *new_options_cmd(manyoptions* p_options) ;


struct command *new_finish_cmd(char *p_repname, struct convert* p_c);
struct command *new_start_cmd(char *p_repname, struct startrep* p_c);
struct command *new_open_window_cmd(struct expr_str *p_windowname, expr_str* p_x, expr_str* p_y, windowtype *p_wt, struct attrib *p_attrib);
struct command *new_open_form_cmd(struct expr_str *p_formname, expr_str* p_filename);
struct command *new_open_form_gui_cmd(struct expr_str *p_form, struct expr_str *p_y, struct expr_str *p_x, struct expr_str *p_like, int p_disable, char* formhandler);
struct command *new_unload_cmd(expr_str *connid, expr_str * p_sql, struct expr_str *p_filename, struct expr_str *p_delimiter);
struct command *new_load_cmd(expr_str *connid, struct expr_str *p_filename, struct expr_str *p_delimiter, struct expr_str *p_sqlvar, char *p_tabname, str_list* p_collist);
struct command *new_connect_cmd(struct expr_str *p_dbname, struct expr_str *p_conn_name, struct expr_str *p_username, struct expr_str *p_password);
struct command *new_open_cursor_cmd(expr_str *connid, struct expr_str *p_cursorname, struct expr_str_list *p_using_bind);
struct command *new_declare_cmd(expr_str *p_connid,expr_str *p_cursorname, struct s_cur_def *declare_dets, e_boolean p_with_hold,e_boolean p_scroll,e_boolean p_isstmt) ;

struct command *new_current_win_cmd(struct expr_str *p_windowname);
struct command *new_term_rep_cmd(char *p_reportname);
struct command *new_sql_cmd(expr_str *p_connid, char * p_sql) ;

int get_variable_dtype_from_variable_usage_expression(char *errbuff, expr_str *vu) ;

/*struct command *new_sql_bound_cmd(expr_str *p_connid,char *p_sql); */
struct command *new_select_cmd(expr_str *p_connid, struct s_select * p_sql,char *forupdate);
struct command *new_sql_transact_cmd(expr_str *p_connid, int p_trans);
struct command *new_set_database_cmd(expr_str* p_dbname,e_boolean p_exclusive);
struct command *new_whenever_cmd(int p_whencode, char *p_whento);
struct command *new_skip_cmd(int p_lines);
struct command *new_skip_by_cmd(double p_lines);
struct command *new_skip_to_cmd(double p_lines);
struct command *new_need_cmd(expr_str* p_expr);
struct command *new_print_file_cmd(struct expr_str *p_filename, e_boolean p_semi);
struct command *new_print_img_cmd(struct expr_str *p_var, expr_str* p_scale_x, expr_str* p_scale_y, char *p_img_type, e_boolean p_semi);
struct command *new_pause_cmd(struct expr_str *p_pause_msg);
struct command *new_set_cmd(char *p_niy);
struct command *new_open_session_cmd(expr_str * p_connid,struct expr_str* p_db,user_details* p_userdets);
struct command *new_enable_cmd (struct fh_field_list *srec);
struct command *new_enable_form_cmd ( struct expr_str* formname, struct fh_field_list *srec);
struct command *new_disable_cmd ( struct fh_field_list *srec );
struct command *new_disable_form_cmd ( struct expr_str* formname, struct fh_field_list *srec );
struct command *new_open_statusbox_cmd ( str name, expr_str *at_x, expr_str *at_y, expr_str *sz_width, expr_str *sz_height);
struct command *new_msg_box_cmd ( expr_str_list *msg, expr_str_list *caption, int icon, int buttons, int default_button, int disable, expr_str *returning);


struct command *new_resize_arr_cmd(expr_str *p_variable);

struct command *new_dealloc_arr_cmd(expr_str * p_variable);
struct command *new_alloc_arr_cmd(expr_str *p_variable);
struct command *new_next_form_cmd(char *form, char *field);
struct command *new_linked_cmd(expr_str *p_var);
struct command *new_linked_del_cmd(expr_str *p_var);
struct command *new_linked_upd_cmd(expr_str *p_var);
struct command *new_gui_prompt_cmd(char *p_niy);
struct command *new_free_rep_cmd(char *p_niy);
struct command *new_execute_immediate_cmd(expr_str *connid, struct expr_str *p_sql_stmt);
struct command *new_flush_cmd(expr_str *connid, expr_str *p_cursorname);
struct command *new_start_rpc_cmd(struct expr_str *p_valid_port, funcname_list p_remote_func_list);
struct command *new_for_cmd(expr_str*var, expr_str* p_start,expr_str* p_end,expr_str* p_step,commands *p_commands,int lineno);
struct command *new_print_cmd(expr_str_list *p_print_expr, e_boolean p_semi);
struct command *new_put_cmd(expr_str * p_connid,expr_str *p_cursorname,struct expr_str_list* p_list);
struct command *new_error_cmd(expr_str_list *p_expr_list,e_boolean p_wait_for_key,attrib *p_attributes);
struct command *new_call_cmd(expr_str* p_fcall,expr_str_list* p_returning);
struct command *new_output_cmd(char *p_reportname, expr_str_list *p_expressions);
struct command *new_while_cmd(expr_str* p_expr, commands *p_commands);
struct command *new_display_cmd(expr_str_list* p_exprs,dt_display* p_where,attrib *p_attributes,e_boolean byName);
struct command *new_locate_cmd(expr_str_list* p_variables, locate_pos *p_where);
struct command *new_message_cmd(expr_str_list *p_expr, attrib *p_attributes, e_boolean p_wait);
struct command *new_return_cmd(expr_str_list *p_retvals);
struct command *new_execute_cmd(expr_str *connid, expr_str_list* p_inbind, expr_str_list* p_outbind, expr_str *p_sql_stmtid);
struct command *new_sql_block_cmd( expr_str *connid, expr_str_list* p_list);
struct command *new_let_cmd(expr_str_list* p_vars, expr_str_list *p_vals);
struct command *new_case_cmd(expr_str* p_case_expr, struct whens *p_whens, commands *p_otherwise);
struct command *new_validate_cmd(expr_str_list* p_list, str_list* p_tablist);
struct command *new_display_b_n_cmd(expr_str_list* p_vars, attrib *p_attributes);
struct command *new_foreach_cmd(expr_str *connid, expr_str * p_cursorname, expr_str_list* p_inputvals, expr_str_list* p_outputvals, commands *p_cmds);
struct command *new_if_cmd(if_conds *p_truths,commands *p_whenfalse,int else_lineno, int last_lineno);
struct command *new_pdf_call_cmd(expr_str* p_fcall,expr_str_list* p_returning);


struct on_event *new_event(e_event event_type, void *data, commands *cmds,int lineno);
struct menuoption *new_menu_option(str_list  *keys, struct expr_str *mnoption, struct expr_str *mndescription, int helpno);
struct command *new_prompt_cmd(expr_str_list* p_prompt_str ,struct attrib* p_prompt_str_attrib,struct attrib* p_prompt_fld_attrib,e_boolean p_for_char,expr_str* p_promptvar,int p_helpno,struct on_events* p_events,int p_sio,int p_blk);
struct command *new_menu_cmd(struct expr_str* p_menu_title,struct attrib *p_menu_attrib,struct on_events* p_events,int p_sio ,struct expr_str * menu_attrib_comment,struct expr_str *menu_attrib_style, struct expr_str *menu_attrib_image);
struct command *new_clear_cmd(e_clear e, void *data ,e_boolean todefaults) ;
struct command *new_convert_cmd(char * p_repname,struct convert* p_c) ;
struct report_format_section_entry* new_report_format_section_entry(report_blocks rb, void *variable, commands* cmds,int orderby_var_no,int lineno);
struct report_orderby_section *new_report_orderby_section(e_report_orderby p_type,expr_str_list* p_variables);
struct command *new_input_cmd(expr_str_list* p_variables,fh_field_list* p_field_list,struct on_events* p_events,struct attrib *p_attrib,e_boolean p_without_defaults,int p_helpno,int p_sio);
struct command *new_construct_cmd(e_boolean byname, expr_str* p_constr_var,cons_list* p_columns,fh_field_list* p_list,struct on_events* p_events,struct attrib *p_attrib,e_boolean p_without_defaults,int p_helpno,int p_sio);
struct command *new_input_array_cmd(struct expr_str* p_srec,struct expr_str * p_arrayname,struct attrib *p_attrib,struct on_events* p_events,e_boolean p_without_defaults,int p_helpno,int p_sio,int p_blk,char *slice) ;

struct command *new_display_array_cmd(struct expr_str * p_srec,struct expr_str *p_arrayname,struct attrib *p_attrib,struct on_events* p_events,fh_field_entry* p_scroll_using,int p_sio, char *slice) ;
struct command *new_set_session_cmd(char * p_type,expr_str* p_s1,expr_str * p_s2,expr_str * p_s3);

struct module_entry *new_import_legacy_definition(char * p_funcname,int lineno);
struct module_entry *new_import_function_definition(char * p_funcname,int p_nparam,int lineno);
struct module_entry *new_module_entry(enum module_entry_type met_type);
struct module_entry *new_function_definition(char * p_funcname,e_boolean p_isstatic,expr_str_list* p_parameters,commands* p_commands,int lineno);
struct module_entry *new_main_definition(commands* p_commands,int lineno);
struct module_entry *new_module_code_cmd(struct command *cmd);
struct module_entry *new_formhandler_definition(char *name, struct str_list *fld_list, on_events *fld_events, on_events *before_events, on_events *after_events );

struct command *new_fetch_cmd(expr_str * p_connid, struct s_fetch* p_fetch,expr_str_list* p_outbind);
struct module_entry *new_pdf_report_definition(char * p_funcname,e_boolean p_isstatic,expr_str_list* p_parameters,pdf_startrep* p_report_output_section,report_orderby_section *p_report_orderby_section,report_format_section *p_report_format_section,int lineno );
struct module_entry *new_report_definition(char * p_funcname,e_boolean p_isstatic,expr_str_list* p_parameters,startrep* p_report_output_section,report_orderby_section *p_report_orderby_section,report_format_section *p_report_format_section,int lineno );
int set_cmdlineno(int n) ;
void add_class_module_entry(void) ;
void new_class(char *cname, char *pname);
void add_class_entry(struct module_entry *e);
void dump_list(expr_str_list *l);
char *expr_as_string_when_possible(expr_str *e);
int check_input_or_display_array_variable(expr_str *e);
struct s_select_list_item *convert_fgl_expr_to_sql_expr(expr_str *e) ;
//expr_str *A4GL_new_select_list_item_expr(struct s_select_list_item *e) ;
int is_valid_identifier(expr_str *l);
int get_validate_list_cnt (void);

#endif

