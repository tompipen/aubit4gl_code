
int print_alloc_arr_cmd(struct_alloc_arr_cmd *cmd_data);
int print_at_term_cmd(struct_at_term_cmd *cmd_data);
int print_call_cmd(struct_call_cmd *cmd_data);
int print_cancel_cmd(struct_cancel_cmd *cmd_data);
int print_case_cmd(struct_case_cmd *cmd_data);
int print_check_menu_cmd(struct_check_menu_cmd *cmd_data);
int print_clear_cmd(struct_clear_cmd *cmd_data);
int print_close_cmd(struct_close_cmd *cmd_data);
int print_code_cmd(struct_code_cmd *cmd_data);
int print_connect_cmd(struct_connect_cmd *cmd_data);
int print_construct_cmd(struct_construct_cmd *cmd_data);
int print_continue_cmd(struct_continue_cmd *cmd_data);
int print_convert_cmd(struct_convert_cmd *cmd_data);
int print_current_win_cmd(struct_current_win_cmd *cmd_data);
int print_dealloc_arr_cmd(struct_dealloc_arr_cmd *cmd_data);
int print_declare_cmd(struct_declare_cmd *cmd_data);
int print_defer_cmd(struct_defer_cmd *cmd_data);
int print_delete_cmd(struct_delete_cmd *cmd_data);
int print_disable_cmd(struct_disable_cmd *cmd_data);
int print_disable_form_cmd(struct_disable_form_cmd *cmd_data);
int print_disable_menu_cmd(struct_disable_menu_cmd *cmd_data);
int print_display_array_cmd(struct_display_array_cmd *cmd_data);
int print_display_b_n_cmd(struct_display_b_n_cmd *cmd_data);
int print_display_cmd(struct_display_cmd *cmd_data);
int print_display_form_cmd(struct_display_form_cmd *cmd_data);
int print_enable_cmd(struct_enable_cmd *cmd_data);
int print_enable_form_cmd(struct_enable_form_cmd *cmd_data);
int print_enable_menu_cmd(struct_enable_menu_cmd *cmd_data);
int print_error_cmd(struct_error_cmd *cmd_data);
int print_execute_cmd(struct_execute_cmd *cmd_data,int already_doing_command);
int print_execute_immediate_cmd(struct_execute_immediate_cmd *cmd_data);
int print_exit_prog_cmd(struct_exit_prog_cmd *cmd_data);
int print_ext_cmd(struct_ext_cmd *cmd_data);
int print_fetch_cmd(struct_fetch_cmd *cmd_data,int using_obind_dup_not_obind);
int print_finish_cmd(struct_finish_cmd *cmd_data);
int print_flush_cmd(struct_flush_cmd *cmd_data);
int print_for_cmd(struct_for_cmd *cmd_data);
int print_foreach_cmd(struct_foreach_cmd *cmd_data);
int print_free_cmd(struct_free_cmd *cmd_data);
int print_free_rep_cmd(struct_free_rep_cmd *cmd_data);
int print_goto_cmd(struct_goto_cmd *cmd_data);
int print_hide_cmd(struct_hide_cmd *cmd_data);
int print_hide_option_cmd(struct_hide_option_cmd *cmd_data);
int print_if_cmd(struct_if_cmd *cmd_data);
int print_init_cmd(struct_init_cmd *cmd_data);
int print_input_array_cmd(struct_input_array_cmd *cmd_data);
int print_input_cmd(struct_input_cmd *cmd_data);
int print_insert_cmd(struct_insert_cmd *cmd_data);
int print_label_cmd(struct_label_cmd *cmd_data);
int print_let_cmd(struct_let_cmd *cmd_data);
int print_load_cmd(struct_load_cmd *cmd_data);
int print_locate_cmd(struct_locate_cmd *cmd_data);
int print_menu_cmd(struct_menu_cmd *cmd_data);
int print_message_cmd(struct_message_cmd *cmd_data);
int print_move_cmd(struct_move_cmd *cmd_data);
int print_msg_box_cmd(struct_msg_box_cmd *cmd_data);
int print_need_cmd(struct_need_cmd *cmd_data);
int print_next_field_cmd(struct_next_field_cmd *cmd_data);
int print_next_form_cmd(struct_next_form_cmd *cmd_data);
int print_next_option_cmd(struct_next_option_cmd *cmd_data);
int print_open_cursor_cmd(struct_open_cursor_cmd *cmd_data);
int print_open_form_cmd(struct_open_form_cmd *cmd_data);
int print_open_form_gui_cmd(struct_open_form_gui_cmd *cmd_data);
int print_open_statusbox_cmd(struct_open_statusbox_cmd *cmd_data);
int print_open_window_cmd(struct_open_window_cmd *cmd_data);
int print_options_cmd(struct_options_cmd *cmd_data);
int print_output_cmd(struct_output_cmd *cmd_data);
int print_pause_cmd(struct_pause_cmd *cmd_data);
int print_pause_screen_off_cmd(void);
int print_pause_screen_on_cmd(void);
int print_pdf_call_cmd(struct_pdf_call_cmd *cmd_data);
int print_prepare_cmd(struct_prepare_cmd *cmd_data,int already_doing_command);
int print_print_cmd(struct_print_cmd *cmd_data);
int print_print_file_cmd(struct_print_file_cmd *cmd_data);
int print_print_img_cmd(struct_print_img_cmd *cmd_data);
int print_prompt_cmd(struct_prompt_cmd *cmd_data);
int print_put_cmd(struct_put_cmd *cmd_data);
int print_resize_arr_cmd(struct_resize_arr_cmd *cmd_data);
int print_return_cmd(struct_return_cmd *cmd_data);
int print_run_cmd(struct_run_cmd *cmd_data);
int print_scroll_cmd(struct_scroll_cmd *cmd_data);
int print_select_cmd(struct_select_cmd *cmd_data);
int print_set_database_cmd(struct_set_database_cmd *cmd_data);
int print_set_session_cmd(struct_set_session_cmd *cmd_data);
int print_show_cmd(struct_show_cmd *cmd_data);
int print_show_menu_cmd(struct_show_menu_cmd *cmd_data);
int print_show_option_cmd(struct_show_option_cmd *cmd_data);
int print_skip_by_cmd(struct_skip_by_cmd *cmd_data);
int print_skip_cmd(struct_skip_cmd *cmd_data);
int print_skip_to_cmd(struct_skip_to_cmd *cmd_data);
int print_skip_to_top_cmd(void);
int print_sleep_cmd(struct_sleep_cmd *cmd_data);
int print_sql_block_cmd(struct_sql_block_cmd *cmd_data);
int print_sql_cmd(struct_sql_cmd *cmd_data);
int print_sql_transact_cmd(struct_sql_transact_cmd *cmd_data);
int print_start_cmd(struct_start_cmd *cmd_data);
int print_start_rpc_cmd(struct_start_rpc_cmd *cmd_data);
int print_stop_rpc_cmd(void);
int print_term_rep_cmd(struct_term_rep_cmd *cmd_data);
int print_uncheck_menu_cmd(struct_uncheck_menu_cmd *cmd_data);
int print_unload_cmd(struct_unload_cmd *cmd_data);
int print_update_cmd(struct_update_cmd *cmd_data);
int print_validate_cmd(struct_validate_cmd *cmd_data);
int print_whenever_cmd(struct_whenever_cmd *cmd_data);
int print_while_cmd(struct_while_cmd *cmd_data);
void print_cmd_start(void);
