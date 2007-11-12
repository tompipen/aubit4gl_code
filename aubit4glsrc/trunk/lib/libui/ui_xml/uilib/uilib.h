/* uilib.c */
char *uilib_xml_escape(char *s);
int uilib_start(int nargs);
int uilib_program_exit(int nargs);
int uilib_clear_screen(int nargs);
int uilib_clear_window(int nargs);
int uilib_set_field_list(int nargs);
int uilib_display_values(int nargs);
int uilib_clear_fields(int nargs);
int uilib_clear_form(int nargs);
int uilib_close_form(int nargs);
int uilib_close_window(int nargs);
int uilib_error(int nargs);
int uilib_message(int nargs);
int uilib_displayat(int nargs);
int uilib_current_window(int nargs);
int uilib_display(int nargs);
int uilib_options(int nargs);
int uilib_open_form(int nargs);
int uilib_display_form(int nargs);
int uilib_sleep(int nargs);
int uilib_open_window_with_form(int n);
int uilib_open_window(int n);
int uilib_prompt_start(int n);
int uilib_prompt_initialised(int n);
int uilib_prompt_loop(int n);
int uilib_get_prompt_result(int nargs);
int uilib_free_prompt(int nargs);
int uilib_event(int nargs);
int uilib_start_events(int nargs);
int uilib_end_events(int nargs);
int uilib_hide_option(int nargs);
int uilib_show_option(int n);
int uilib_next_option(int n);
int uilib_menu_add(int nargs);
int uilib_free_menu(int nargs);
int uilib_menu_loop(int nargs);
int uilib_menu_start(int nargs);
int uilib_menu_initialised(int nargs);
int uilib_free_input(int nargs);
int uilib_input_get_values(int nargs);
int uilib_input_loop(int nargs);
int uilib_input_start(int nargs);
int uilib_input_initialised(int nargs);
int uilib_next_field(int nargs);
int uilib_construct_start(int nargs);
int uilib_construct_loop(int nargs);
int uilib_construct_query(int nargs);
int uilib_free_construct(int nargs);
int uilib_construct_initialised(int nargs);

int uilib_get_context(int nargs);
int uilib_clear_to_defaults(int nargs);
int uilib_clear(int nargs);



int uilib_set_count(int nargs) ;
int uilib_arr_count(int nargs) ;
int uilib_scr_line(int nargs) ;
int uilib_arr_curr(int nargs) ;

int uilib_display_array_line(int nargs);
int uilib_display_array_initialised(int nargs);
int uilib_array_lines_end(int nargs);
int uilib_array_lines_start(int nargs);
int uilib_display_array_loop(int nargs);
int uilib_display_array_start(int nargs);



int uilib_input_array_start(int nargs);
int uilib_input_array_sync(int nargs);
int uilib_input_array_loop(int nargs);
int uilib_has_array_values(int nargs);
int uilib_input_get_array_values(int nargs);
int uilib_input_array_initialised(int nargs);

int uilib_free_input_array(int nargs);

int uilib_getfldbuf(int nargs) ;
int uilib_fgl_drawbox(int nargs);
int uilib_set_field_list_directly (char *s);
int uilib_menu_set (int nargs);
int uilib_infield(int n);
int uilib_lastkey(int n);
int uilib_save_file(char *id, char *s);
void set_construct_clause(int context, char *ptr);

