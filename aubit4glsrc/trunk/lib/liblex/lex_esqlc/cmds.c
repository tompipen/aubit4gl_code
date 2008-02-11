#include "a4gl_lib_lex_esqlc_int.h"
#define ONE_NOT_ZERO(x) (x?x:1)
#include "field_handling.h"
#include "compile_c.h"


#include "cmd_funcs.h"
int ok;

int dump_command(struct command_data *cd) {
switch(cd->type) {
   case E_CMD_STOP_RPC_CMD         : ok=print_stop_rpc_cmd(); break;
   case E_CMD_PAUSE_SCREEN_ON_CMD  : ok=print_pause_screen_on_cmd(); break;
   case E_CMD_PAUSE_SCREEN_OFF_CMD : ok=print_pause_screen_off_cmd(); break;
   case E_CMD_SKIP_TO_TOP_CMD      : ok=print_skip_to_top_cmd(); break;
   case E_CMD_START_RPC_CMD        : ok=print_start_rpc_cmd(&cd->command_data_u.start_rpc_cmd); break;
   case E_CMD_CALL_CMD             : ok=print_call_cmd(&cd->command_data_u.call_cmd); break;
   case E_CMD_CANCEL_CMD           : ok=print_cancel_cmd(&cd->command_data_u.cancel_cmd); break;
   case E_CMD_CASE_CMD             : ok=print_case_cmd(&cd->command_data_u.case_cmd); break;
   case E_CMD_CLOSE_CMD            : ok=print_close_cmd(&cd->command_data_u.close_cmd); break;
   case E_CMD_CLOSE_SQL_CMD        : ok=print_close_sql_cmd(&cd->command_data_u.close_sql_cmd,0); break;
   case E_CMD_CODE_CMD             : ok=print_code_cmd(&cd->command_data_u.code_cmd); break;
   case E_CMD_CONSTRUCT_CMD        : ok=print_construct_cmd(&cd->command_data_u.construct_cmd); break;
   case E_CMD_DEFER_CMD            : ok=print_defer_cmd(&cd->command_data_u.defer_cmd); break;
   case E_CMD_DISPLAY_B_N_CMD      : ok=print_display_b_n_cmd(&cd->command_data_u.display_b_n_cmd); break;
   case E_CMD_DISPLAY_CMD          : ok=print_display_cmd(&cd->command_data_u.display_cmd); break;
   case E_CMD_DISPLAY_FORM_CMD     : ok=print_display_form_cmd(&cd->command_data_u.display_form_cmd); break;
   case E_CMD_DISPLAY_ARRAY_CMD    : ok=print_display_array_cmd(&cd->command_data_u.display_array_cmd); break;
   case E_CMD_ALLOC_ARR_CMD        : ok=print_alloc_arr_cmd(&cd->command_data_u.alloc_arr_cmd); break;
   case E_CMD_DEALLOC_ARR_CMD      : ok=print_dealloc_arr_cmd(&cd->command_data_u.dealloc_arr_cmd); break;
   case E_CMD_RESIZE_ARR_CMD       : ok=print_resize_arr_cmd(&cd->command_data_u.resize_arr_cmd); break;
   case E_CMD_ERROR_CMD            : ok=print_error_cmd(&cd->command_data_u.error_cmd); break;
   case E_CMD_EXT_CMD              : ok=print_ext_cmd(&cd->command_data_u.ext_cmd); break;
   case E_CMD_CONTINUE_CMD         : ok=print_continue_cmd(&cd->command_data_u.continue_cmd); break;
   case E_CMD_EXIT_PROG_CMD        : ok=print_exit_prog_cmd(&cd->command_data_u.exit_prog_cmd); break;
   case E_CMD_FOR_CMD              : ok=print_for_cmd(&cd->command_data_u.for_cmd); break;
   case E_CMD_FOREACH_CMD          : ok=print_foreach_cmd(&cd->command_data_u.foreach_cmd); break;
   case E_CMD_FREE_CMD             : ok=print_free_cmd(&cd->command_data_u.free_cmd); break;
   case E_CMD_GOTO_CMD             : ok=print_goto_cmd(&cd->command_data_u.goto_cmd); break;
   case E_CMD_CHECK_MENU_CMD       : ok=print_check_menu_cmd(&cd->command_data_u.check_menu_cmd); break;
   case E_CMD_UNCHECK_MENU_CMD     : ok=print_uncheck_menu_cmd(&cd->command_data_u.uncheck_menu_cmd); break;
   case E_CMD_DISABLE_MENU_CMD     : ok=print_disable_menu_cmd(&cd->command_data_u.disable_menu_cmd); break;
   case E_CMD_ENABLE_MENU_CMD      : ok=print_enable_menu_cmd(&cd->command_data_u.enable_menu_cmd); break;
   case E_CMD_MSG_BOX_CMD          : ok=print_msg_box_cmd(&cd->command_data_u.msg_box_cmd); break;
   case E_CMD_IF_CMD               : ok=print_if_cmd(&cd->command_data_u.if_cmd); break;
   case E_CMD_INIT_CMD             : ok=print_init_cmd(&cd->command_data_u.init_cmd); break;
   case E_CMD_NEXT_FIELD_CMD       : ok=print_next_field_cmd(&cd->command_data_u.next_field_cmd); break;
   case E_CMD_NEXT_FORM_CMD        : ok=print_next_form_cmd(&cd->command_data_u.next_form_cmd); break;
   case E_CMD_INPUT_CMD            : ok=print_input_cmd(&cd->command_data_u.input_cmd); break;
   case E_CMD_INPUT_ARRAY_CMD      : ok=print_input_array_cmd(&cd->command_data_u.input_array_cmd); break;
   case E_CMD_SCROLL_CMD           : ok=print_scroll_cmd(&cd->command_data_u.scroll_cmd); break;
   case E_CMD_LABEL_CMD            : ok=print_label_cmd(&cd->command_data_u.label_cmd); break;
   case E_CMD_LET_CMD              : ok=print_let_cmd(&cd->command_data_u.let_cmd); break;
   case E_CMD_LOCATE_CMD           : ok=print_locate_cmd(&cd->command_data_u.locate_cmd); break;
   case E_CMD_AT_TERM_CMD          : ok=print_at_term_cmd(&cd->command_data_u.at_term_cmd); break;
   case E_CMD_RETURN_CMD           : ok=print_return_cmd(&cd->command_data_u.return_cmd); break;
   case E_CMD_MENU_CMD             : ok=print_menu_cmd(&cd->command_data_u.menu_cmd); break;
   case E_CMD_NEXT_OPTION_CMD      : ok=print_next_option_cmd(&cd->command_data_u.next_option_cmd); break;
   case E_CMD_SHOW_OPTION_CMD      : ok=print_show_option_cmd(&cd->command_data_u.show_option_cmd); break;
   case E_CMD_HIDE_OPTION_CMD      : ok=print_hide_option_cmd(&cd->command_data_u.hide_option_cmd); break;
   case E_CMD_MESSAGE_CMD          : ok=print_message_cmd(&cd->command_data_u.message_cmd); break;
   case E_CMD_OPEN_WINDOW_CMD      : ok=print_open_window_cmd(&cd->command_data_u.open_window_cmd); break;
   case E_CMD_OPEN_STATUSBOX_CMD   : ok=print_open_statusbox_cmd(&cd->command_data_u.open_statusbox_cmd); break;
   case E_CMD_OPEN_FORM_CMD        : ok=print_open_form_cmd(&cd->command_data_u.open_form_cmd); break;
   case E_CMD_OPEN_FORM_GUI_CMD    : ok=print_open_form_gui_cmd(&cd->command_data_u.open_form_gui_cmd); break;
   case E_CMD_OPEN_CURSOR_CMD      : ok=print_open_cursor_cmd(&cd->command_data_u.open_cursor_cmd); break;
   case E_CMD_CONNECT_CMD          : ok=print_connect_cmd(&cd->command_data_u.connect_cmd); break;
   case E_CMD_OPTIONS_CMD          : ok=print_options_cmd(&cd->command_data_u.options_cmd); break;
   case E_CMD_PREPARE_CMD          : ok=print_prepare_cmd(&cd->command_data_u.prepare_cmd,0); break;
   case E_CMD_EXECUTE_CMD          : ok=print_execute_cmd(&cd->command_data_u.execute_cmd,0); break;
   case E_CMD_EXECUTE_IMMEDIATE_CMD: ok=print_execute_immediate_cmd(&cd->command_data_u.execute_immediate_cmd); break;
   case E_CMD_PROMPT_CMD           : ok=print_prompt_cmd(&cd->command_data_u.prompt_cmd); break;
   case E_CMD_START_CMD            : ok=print_start_cmd(&cd->command_data_u.start_cmd); break;
   case E_CMD_CONVERT_CMD          : ok=print_convert_cmd(&cd->command_data_u.convert_cmd); break;
   case E_CMD_FREE_REP_CMD         : ok=print_free_rep_cmd(&cd->command_data_u.free_rep_cmd); break;
   case E_CMD_OUTPUT_CMD           : ok=print_output_cmd(&cd->command_data_u.output_cmd); break;
   case E_CMD_FINISH_CMD           : ok=print_finish_cmd(&cd->command_data_u.finish_cmd); break;
   case E_CMD_TERM_REP_CMD         : ok=print_term_rep_cmd(&cd->command_data_u.term_rep_cmd); break;
   case E_CMD_NEED_CMD             : ok=print_need_cmd(&cd->command_data_u.need_cmd); break;
   case E_CMD_SKIP_CMD             : ok=print_skip_cmd(&cd->command_data_u.skip_cmd); break;
   case E_CMD_SKIP_BY_CMD          : ok=print_skip_by_cmd(&cd->command_data_u.skip_by_cmd); break;
   case E_CMD_SKIP_TO_CMD          : ok=print_skip_to_cmd(&cd->command_data_u.skip_to_cmd); break;
   case E_CMD_PRINT_CMD            : ok=print_print_cmd(&cd->command_data_u.print_cmd); break;
   case E_CMD_PRINT_FILE_CMD       : ok=print_print_file_cmd(&cd->command_data_u.print_file_cmd); break;
   case E_CMD_PRINT_IMG_CMD        : ok=print_print_img_cmd(&cd->command_data_u.print_img_cmd); break;
   case E_CMD_PAUSE_CMD            : ok=print_pause_cmd(&cd->command_data_u.pause_cmd); break;
   case E_CMD_RUN_CMD              : ok=print_run_cmd(&cd->command_data_u.run_cmd); break;
   case E_CMD_SLEEP_CMD            : ok=print_sleep_cmd(&cd->command_data_u.sleep_cmd); break;
   case E_CMD_SQL_BLOCK_CMD        : ok=print_sql_block_cmd(&cd->command_data_u.sql_block_cmd); break;
   case E_CMD_VALIDATE_CMD         : ok=print_validate_cmd(&cd->command_data_u.validate_cmd); break;
   case E_CMD_WHENEVER_CMD         : ok=print_whenever_cmd(&cd->command_data_u.whenever_cmd); break;
   case E_CMD_WHILE_CMD            : ok=print_while_cmd(&cd->command_data_u.while_cmd); break;
   case E_CMD_CLEAR_CMD            : ok=print_clear_cmd(&cd->command_data_u.clear_cmd); break;
   case E_CMD_CURRENT_WIN_CMD      : ok=print_current_win_cmd(&cd->command_data_u.current_win_cmd); break;
   case E_CMD_SHOW_CMD             : ok=print_show_cmd(&cd->command_data_u.show_cmd); break;
   case E_CMD_HIDE_CMD             : ok=print_hide_cmd(&cd->command_data_u.hide_cmd); break;
   case E_CMD_MOVE_CMD             : ok=print_move_cmd(&cd->command_data_u.move_cmd); break;
   case E_CMD_PUT_CMD              : ok=print_put_cmd(&cd->command_data_u.put_cmd); break;
   case E_CMD_UNLOAD_CMD           : ok=print_unload_cmd(&cd->command_data_u.unload_cmd); break;
   case E_CMD_LOAD_CMD             : ok=print_load_cmd(&cd->command_data_u.load_cmd); break;
   case E_CMD_SQL_CMD              : ok=print_sql_cmd(&cd->command_data_u.sql_cmd); break;
   case E_CMD_SQL_TRANSACT_CMD     : ok=print_sql_transact_cmd(&cd->command_data_u.sql_transact_cmd); break;
   case E_CMD_SELECT_CMD           : ok=print_select_cmd(&cd->command_data_u.select_cmd); break;
   case E_CMD_FLUSH_CMD            : ok=print_flush_cmd(&cd->command_data_u.flush_cmd); break;
   case E_CMD_DECLARE_CMD          : ok=print_declare_cmd(&cd->command_data_u.declare_cmd); break;
   case E_CMD_SET_DATABASE_CMD     : ok=print_set_database_cmd(&cd->command_data_u.set_database_cmd); break;
   case E_CMD_FETCH_CMD            : ok=print_fetch_cmd(&cd->command_data_u.fetch_cmd,0); break;
   case E_CMD_SHOW_MENU_CMD        : ok=print_show_menu_cmd(&cd->command_data_u.show_menu_cmd); break;
   case E_CMD_ENABLE_CMD           : ok=print_enable_cmd(&cd->command_data_u.enable_cmd); break;
   case E_CMD_UPDATE_CMD           : ok=print_update_cmd(&cd->command_data_u.update_cmd); break;
   case E_CMD_INSERT_CMD           : ok=print_insert_cmd(&cd->command_data_u.insert_cmd); break;
   case E_CMD_DELETE_CMD           : ok=print_delete_cmd(&cd->command_data_u.delete_cmd); break;
   case E_CMD_ENABLE_FORM_CMD      : ok=print_enable_form_cmd(&cd->command_data_u.enable_form_cmd); break;
   case E_CMD_DISABLE_CMD          : ok=print_disable_cmd(&cd->command_data_u.disable_cmd); break;
   case E_CMD_DISABLE_FORM_CMD     : ok=print_disable_form_cmd(&cd->command_data_u.disable_form_cmd); break;
   case E_CMD_PDF_CALL_CMD         : ok=print_pdf_call_cmd(&cd->command_data_u.pdf_call_cmd); break;
   case E_CMD_SET_SESSION_CMD      : ok=print_set_session_cmd(&cd->command_data_u.set_session_cmd); break;
} /* end of switch */
return ok;
}
