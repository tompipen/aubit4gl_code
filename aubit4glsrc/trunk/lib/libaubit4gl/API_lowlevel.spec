
* Name of the API:
LIBRARY HLUI
* Name of the variable which will have second part of library name to load:
VARIABLE A4GL_HLUI

A4GL_LL_beep -> void 
/* int A4GL_LL_colour_code int a */ 
A4GL_LL_colour_code int a -> int

/* void* A4GL_LL_create_errorwindow int h int w int y int x int attr char* str */
A4GL_LL_create_errorwindow int h int w int y int x int attr char* str -> void* 

/* void* A4GL_LL_create_window int h int w int y int x int border */
A4GL_LL_create_window int h int w int y int x int border -> void* 

/* void* A4GL_LL_current_field void* form */
A4GL_LL_current_field void* form -> void* 

/* int A4GL_LL_decode_aubit_attr int a char s */
A4GL_LL_decode_aubit_attr int a char s -> int

/* void A4GL_LL_delete_errorwindow void* curr_error_window */
A4GL_LL_delete_errorwindow void* curr_error_window -> void

/* void* A4GL_LL_display_form struct s_form_dets *f int attrib */
A4GL_LL_display_form void* f int attrib -> void* 

/* int A4GL_LL_dump_screen int n */
A4GL_LL_dump_screen int n -> int

/* void A4GL_LL_error_box char* str int attr */
A4GL_LL_error_box char* str int attr -> void 

/* char* A4GL_LL_field_buffer void* field int n */
A4GL_LL_field_buffer void* field int n -> char* 

/* int A4GL_LL_field_opts void* field */
A4GL_LL_field_opts void* field -> int

/* int A4GL_LL_field_status void* field */
A4GL_LL_field_status void* field -> int 

/* void A4GL_LL_form_page void* form */
A4GL_LL_form_page void* form -> void

/* int A4GL_LL_get_carat void* form */
A4GL_LL_get_carat void* form -> int

/* void* A4GL_LL_get_field_userptr void* field */
A4GL_LL_get_field_userptr void* field -> void* 

/* int A4GL_LL_get_field_width void* f */
A4GL_LL_get_field_width void* f -> int

/* void* A4GL_LL_get_form_userptr void* form */
A4GL_LL_get_form_userptr void* form -> void* 

/* int A4GL_LL_getch_swin void* window_ptr */
A4GL_LL_getch_swin void* window_ptr -> int 

/* void A4GL_LL_gui_run_til_no_more */
A4GL_LL_gui_run_til_no_more -> void 

/* void A4GL_LL_hide_window void* w */
A4GL_LL_hide_window void* w -> void

/* void A4GL_LL_initialize_display */
A4GL_LL_initialize_display  -> void

/* int A4GL_LL_int_form_driver void* mform int mode */
A4GL_LL_int_form_driver void* mform int mode -> int

/* void* A4GL_LL_make_field int frow int fcol int rows int cols */
A4GL_LL_make_field void* prop int frow int fcol int rows int cols -> void* 

/* void* A4GL_LL_make_label int frow int fcol char* label */
A4GL_LL_make_label int frow int fcol char* label -> void* 

/* void A4GL_LL_make_window_top void* w */
A4GL_LL_make_window_top void* w -> void

/* void A4GL_LL_move_window void* w int y int x */
A4GL_LL_move_window void* w int y int x -> void

/* void* A4GL_LL_new_form void* *fields */
A4GL_LL_new_form void* formdets -> void*

/* void A4GL_LL_out_linemode char* s */
A4GL_LL_out_linemode char* s -> void

/* void A4GL_LL_remove_window void* x */
A4GL_LL_remove_window void* x -> void

/* void A4GL_LL_scale_form void *f int* y int* x */
A4GL_LL_scale_form void* f int* y int* x -> void

/* int A4GL_LL_screen_height void */
A4GL_LL_screen_height -> int

/* void A4GL_LL_screen_mode */
A4GL_LL_screen_mode  -> void

/* void A4GL_LL_screen_refresh void */
A4GL_LL_screen_refresh  -> void

/* void A4GL_LL_screen_update void */
A4GL_LL_screen_update  -> void

/* int A4GL_LL_screen_width void */
A4GL_LL_screen_width  -> int

/* void A4GL_LL_set_bkg void* win int attr */
A4GL_LL_set_bkg void* win int attr -> void

/* void A4GL_LL_set_carat void* form */
A4GL_LL_set_carat void* form -> void

/* void A4GL_LL_set_current_field void* form void* field */
A4GL_LL_set_current_field void* form void* field -> void

/* void A4GL_LL_set_field_attr void* field */
A4GL_LL_set_field_attr void* field -> void

/* void A4GL_LL_set_field_back void* field int attr */
A4GL_LL_set_field_back void* field int attr -> void

/* void A4GL_LL_set_field_buffer void* field int n char* str */
A4GL_LL_set_field_buffer void* field int n char* str -> void

/* void A4GL_LL_set_field_fore void* field int attr */
A4GL_LL_set_field_fore void* field int attr -> void

/* int A4GL_LL_set_field_opts void* field int oopt */
A4GL_LL_set_field_opts void* field int oopt -> int

/* int A4GL_LL_set_field_status void* f int stat */
A4GL_LL_set_field_status void* f int stat -> int

/* void A4GL_LL_set_field_userptr void* field void* ptr */
A4GL_LL_set_field_userptr void* field void* ptr -> void

/* void A4GL_LL_set_form_page void* form int page */
A4GL_LL_set_form_page void* form int page -> void

/* void A4GL_LL_set_form_userptr void* form void* data */
A4GL_LL_set_form_userptr void* form void* data -> void

/* void A4GL_LL_set_max_field void* f int n */
A4GL_LL_set_max_field void* f int n -> void

/* int A4GL_LL_set_new_page void* field int n */
A4GL_LL_set_new_page void* field int n -> int

/* void A4GL_LL_show_window void* w */
A4GL_LL_show_window void* w -> void

/* void A4GL_LL_sleep int n */
A4GL_LL_sleep int n -> void

/* void A4GL_LL_switch_to_line_mode void */
A4GL_LL_switch_to_line_mode  -> void

/* void A4GL_LL_wadd_char_xy_col void* win int x int y int ch */
A4GL_LL_wadd_char_xy_col void* win int x int y int ch -> void

/* int UILIB_A4GL_prompt_loop void* vprompt int timeout void* evt_list*/
A4GL_LL_prompt_loop void* vprompt int timeout void* evt_list -> int

/* int UILIB_A4GL_start_prompt void* vprompt int ap int c int h int af */
A4GL_LL_start_prompt void* vprompt int ap int c int h int af -> int


A4GL_LL_set_chars_normal int* n -> int

A4GL_LL_endis_fields_ap int n void* ap -> int
