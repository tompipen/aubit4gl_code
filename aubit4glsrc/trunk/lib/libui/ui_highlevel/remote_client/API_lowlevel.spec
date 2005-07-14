
* Name of the API:
LIBRARY HLUI
* Name of the variable which will have second part of library name to load:
VARIABLE A4GL_HLUI


!  struct list_of_fields { long a<>;};


A4GL_LL_beep -> void 
A4GL_LL_clear_prompt void* f void* p -> void
A4GL_LL_clr_form_fields int to_defaults char* defs  -> void
A4GL_LL_clr_menu_disp void* menu int curr_width int curr_height int iscurrborder int currwinno void* cw int menu_offset int gw_y -> void 
A4GL_LL_colour_code int a -> int
A4GL_LL_construct_large char* orig void* evt int initkey int initpos char* left char* right int curr_width int curr_height int comment_line void* currwin  int currisborder -> int
A4GL_LL_create_errorwindow int h int w int y int x int attr char* str -> void* 
A4GL_LL_create_window int h int w int y int x int border -> void* 
A4GL_LL_current_field void* form -> void* 
A4GL_LL_decode_aubit_attr int a char s -> int
A4GL_LL_delete_errorwindow void* curr_error_window -> void
A4GL_LL_disp_h_menu int num_opts -> int
A4GL_LL_disp_h_menu_opt int opt_num int num_opts char* title int attrib -> int
A4GL_LL_display_form void* f int attrib int curr_width int curr_height int cb int currwinno int form_line void* currwin void* frm int maxline int maxcol -> void* 
A4GL_LL_dump_screen int n char* fname int mode -> int
A4GL_LL_endis_fields_ap int n void* ap -> int
A4GL_LL_error_box char* str int attr  -> void 
A4GL_LL_field_buffer void* field int n -> char* 
A4GL_LL_field_opts void* field -> int
A4GL_LL_field_status void* field -> int 
A4GL_LL_form_page void* form -> int
A4GL_LL_get_carat void* form -> int
A4GL_LL_get_field_userptr void* field -> void* 
A4GL_LL_get_form_userptr void* form -> void* 
A4GL_LL_get_value char* s -> void*
A4GL_LL_getch_swin void* window_ptr -> int 
A4GL_LL_gui_run_til_no_more -> void 
A4GL_LL_h_disp_title void* menu char* str int curr_width int curr_height int iscurrborder int currwinno void* cw int gw_y -> void
A4GL_LL_hide_h_menu -> int
A4GL_LL_hide_window void* w -> void
A4GL_LL_initialize_display -> void
A4GL_LL_int_form_driver void* mform int mode -> int
A4GL_LL_make_field int frow int fcol int rows int cols char* widget char* config void* id -> void* 
A4GL_LL_make_label int frow int fcol char* label -> void* 
A4GL_LL_make_window_top void* w -> void
A4GL_LL_menu_type -> int
A4GL_LL_move_window void* w int y int x -> void
A4GL_LL_new_form list_of_fields* fields -> void*
A4GL_LL_open_gui_form char* name_orig  int absolute  int nat  char* like  int disable  void* handler_e void* phandler_c -> int
A4GL_LL_out_linemode char* s -> void
A4GL_LL_remove_window void* x -> void
A4GL_LL_scale_form void* f int* y int* x -> void
A4GL_LL_screen_height -> int
A4GL_LL_screen_mode  -> void
A4GL_LL_screen_redraw  -> void
A4GL_LL_screen_update  -> void
A4GL_LL_screen_width  -> int
A4GL_LL_set_acc_intr_keys int n -> void
A4GL_LL_set_bkg void* win int attr -> void
A4GL_LL_set_carat void* form -> void
A4GL_LL_set_chars_normal int* n -> int
A4GL_LL_set_current_field void* form void* field -> void
A4GL_LL_set_field_attr void* field int dtype int dynamic int autonext int invis int required int compress int has_picture -> void
A4GL_LL_set_field_back void* field int attr -> void
A4GL_LL_set_field_buffer void* field int n char* str -> void
A4GL_LL_set_field_fore void* field int attr -> void
A4GL_LL_set_field_opts void* field int oopt -> int
A4GL_LL_set_field_status void* f int stat -> int
A4GL_LL_set_field_userptr void* field void* ptr -> void
A4GL_LL_set_form_page void* form int page -> void
A4GL_LL_set_form_userptr void* form void* data -> void
A4GL_LL_set_max_field void* f int n -> void
A4GL_LL_set_new_page void* field int n -> int
A4GL_LL_set_window_title void* win int nargs -> int
A4GL_LL_show_window void* w -> void
A4GL_LL_sleep int n -> void
A4GL_LL_start_prompt void* vprompt char* promptstr int ap int c int h int af int curr_width int cb int prompt_line void* cw int prompt_mode -> int
A4GL_LL_switch_to_line_mode  -> void
A4GL_LL_wadd_char_xy_col void* win int x int y int ch int curr_width int curr_height int cb int cwno -> void
A4GL_LL_wadd_char_xy_col_w void* win int x int y int ch int curr_width int curr_height int cb int cwno -> void
A4GL_LL_widget_name_match void* w char* name -> int
A4GL_LL_pause_mode int pm -> int
A4GL_LL_get_field_width_dynamic void* f -> int
