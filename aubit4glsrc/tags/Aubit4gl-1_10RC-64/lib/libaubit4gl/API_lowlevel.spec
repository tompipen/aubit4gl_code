
* Name of the API:
LIBRARY HLUI
* Name of the variable which will have second part of library name to load:
VARIABLE A4GL_HLUI

!  struct list_of_fields { long a<>;};

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
A4GL_LL_display_form void* f int attrib int curr_width int curr_height int cb int currwinno int form_line void* currwin void* frm int maxline int maxcol char* name -> void* 

/* int A4GL_LL_dump_screen int n */
A4GL_LL_dump_screen int n char* fname int mode -> int

A4GL_LL_opening_form char* s char* f -> void

/* void A4GL_LL_error_box char* str int attr */
A4GL_LL_error_box char* str int attr  -> void 

/* char* A4GL_LL_field_buffer void* field int n */
A4GL_LL_field_buffer void* field int n -> char* 

/* int A4GL_LL_field_opts void* field */
A4GL_LL_field_opts void* field -> int

/* int A4GL_LL_field_status void* field */
A4GL_LL_field_status void* field -> int 

/* void A4GL_LL_form_page void* form */
A4GL_LL_form_page void* form -> int

/* Get the current X position in the field */
A4GL_LL_get_carat void* form -> int

/* Get the current y position in the field */
A4GL_LL_get_carat_y void* form -> int

A4GL_LL_init_color int c int r int g int b -> void


/* int A4GL_LL_get_field_width void* f */
A4GL_LL_get_field_width void* f -> int
A4GL_LL_get_field_height void* f -> int






/* A4GL_LL_get_field_userptr void* field -> void*  */
/* A4GL_LL_get_form_userptr void* form -> void*  */
/* A4GL_LL_set_form_userptr void* form void* data -> void */
/* A4GL_LL_set_field_userptr void* field void* ptr -> void */




/* int A4GL_LL_getch_swin void* window_ptr */
A4GL_LL_getch_swin void* window_ptr char* why void* evt -> int 

/* void A4GL_LL_gui_run_til_no_more */
A4GL_LL_gui_run_til_no_more -> void 

/* void A4GL_LL_hide_window void* w */
A4GL_LL_hide_window void* w -> void

/* void A4GL_LL_initialize_display */
A4GL_LL_initialize_display  -> void

/* int A4GL_LL_int_form_driver void* mform int mode */
A4GL_LL_int_form_driver void* mform int mode -> int

/* void* A4GL_LL_make_field int frow int fcol int rows int cols */
A4GL_LL_make_field int frow int fcol int rows int cols char* widget char* config char* incl void* fprop_id char* ref char* action -> void* 

/* void* A4GL_LL_make_label int frow int fcol char* label */
A4GL_LL_make_label int frow int fcol char* label -> void* 

/* void A4GL_LL_make_window_top void* w */
A4GL_LL_make_window_top void* w -> void

/* void A4GL_LL_move_window void* w int y int x */
A4GL_LL_move_window void* w int y int x -> void

/* void* A4GL_LL_new_form void* *fields */
A4GL_LL_new_form list_of_fields* formdets -> void*

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
A4GL_LL_screen_redraw  -> void

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

A4GL_LL_set_field_attr void* field int dtype int dynamic int autonext int invis int required int compress int has_picture int right -> long

/* void A4GL_LL_set_field_back void* field int attr */
A4GL_LL_set_field_back void* field int attr -> void

/* void A4GL_LL_set_field_buffer void* field int n char* str */
A4GL_LL_set_field_buffer void* field int n char* str char* origstr -> void


/* OLD ?A4GL_LL_clr_field_buffer void* field int n -> void */

/* void A4GL_LL_set_field_fore void* field int attr */
A4GL_LL_set_field_fore void* field int attr -> void

/* int A4GL_LL_set_field_opts void* field int oopt */
A4GL_LL_set_field_opts void* field int oopt ->  int

/* int A4GL_LL_set_field_status void* f int stat */
A4GL_LL_set_field_status void* f int stat -> void


/* void A4GL_LL_set_form_page void* form int page */
A4GL_LL_set_form_page void* form int page -> void


/* void A4GL_LL_set_max_field void* f int n */
A4GL_LL_set_max_field void* f int n void* frm -> void

/* int A4GL_LL_set_new_page void* field int n */
A4GL_LL_set_new_page void* field int n -> int

/* void A4GL_LL_show_window void* w */
A4GL_LL_show_window void* w -> void

/* void A4GL_LL_sleep int n */
A4GL_LL_sleep int n -> void

/* void A4GL_LL_switch_to_line_mode void */
A4GL_LL_switch_to_line_mode  -> void

/* void A4GL_LL_wadd_char_xy_col void* win int x int y int ch  */
A4GL_LL_wadd_char_xy_col void* win int x int y int ch int curr_width int curr_height int cb int cwno -> void
A4GL_LL_wadd_char_xy_col_w void* win int x int y int ch int curr_width int curr_height int cb int cwno -> void

/* int UILIB_A4GL_prompt_loop void* vprompt int timeout void* evt_list*/
/* A4GL_LL_prompt_loop void* vprompt int timeout void* evt_list -> int */

/* int UILIB_A4GL_start_prompt void* vprompt int ap int c int h int af */
A4GL_LL_start_prompt void* vprompt char* promptstr int ap int c int h int af int curr_width int cb int prompt_line void* cw int prompt_mode -> int


A4GL_LL_set_chars_normal int* n -> int

A4GL_LL_endis_fields_ap int n void* ap -> int

A4GL_LL_disp_form_fields_ap int n int attr char* formname va_list* ap -> int
A4GL_LL_open_gui_form char* name_orig  int absolute  int nat  char* like  int disable  void* handler_e void* phandler_c -> int

A4GL_LL_set_window_title void* currwin char* s -> int
A4GL_LL_widget_name_match void* w char* name -> int
A4GL_LL_clr_form_fields int to_defaults char* defs  -> void
A4GL_LL_clr_menu_disp void* menu int curr_width int curr_height int iscurrborder int currwinno void* cw int menu_offset int gw_y -> void 
A4GL_LL_h_disp_title_with_attr void* menu char* str int curr_width int curr_height int iscurrborder int currwinno void* cw int gw_y char* mnstyle char* mncomment char* mnimage -> void
A4GL_LL_set_acc_intr_keys int n -> void
A4GL_LL_menu_loop void* menu -> int

A4GL_LL_get_value char* s -> void*
A4GL_LL_clear_prompt void* f void* p -> void

A4GL_LL_disp_h_menu int num_opts  char* title char* mnstyle char* mncomment char* mnimage -> int
A4GL_LL_disp_h_menu_opt int opt_num int num_opts char* title char* shorthelp int attrib -> void
A4GL_LL_menu_type -> int
A4GL_LL_hide_h_menu -> int
A4GL_LL_construct_large char* orig void* evt int initkey int initpos char* left char* right int curr_width int curr_height int comment_line void* currwin int currisborder int construct_not_added,int dtype -> void*
A4GL_LL_construct_large_finished void* f -> char*
A4GL_LL_pause_mode int pm -> int
A4GL_LL_get_field_width_dynamic void* f -> int
A4GL_LL_get_field_height_dynamic void* f -> int
A4GL_LL_submit_event int a void* s int event_type int block int keycode char* field -> void
A4GL_LL_activate_events void* s -> void
A4GL_LL_finished_with_events void* s -> void
A4GL_LL_get_triggered_event -> int
A4GL_LL_can_show_comments char* str -> int
A4GL_LL_can_show_message int msgline char* str int wait -> int
A4GL_LL_direct_to_ui char* t char* s -> void
