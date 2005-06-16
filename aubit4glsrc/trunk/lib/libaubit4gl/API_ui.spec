* Name of the API:
LIBRARY UI
* Name of the variable which will have second part of library name to load:
VARIABLE A4GL_UI
* Add prefix for created API functions:
* API_PREFIX A4GLUI_
* Add prefix for existing library functions:
LIB_PREFIX UILIB_
* Name of the header file to be referenced with #include
*HEADER_FILE API_ui.h

*MAP A4GL_make_pixmap A4GL_make_pixmap_gw

* don't include a4gl_libaubit4gl.h - a4gl_libaubit4gl.h includes this header!
/* #include "a4gl_libaubit4gl.h" */
#include <stdarg.h>


/* void*  A4GL_cr_window (char* s, int iswindow, int form_line, int error_line, int prompt_line, int menu_line, int border, int comment_line, int message_line, int attrib) */
A4GL_cr_window char* s int iswindow int form_line int error_line int prompt_line int menu_line int border int comment_line int message_line int attrib -> void*
/* int A4GL_cr_window_form (char* name, int iswindow, int form_line, int error_line, int prompt_line, int menu_line, int border, int comment_line, int message_line, int attrib)*/
A4GL_cr_window_form char* name int iswindow int form_line int error_line int prompt_line int menu_line int border int comment_line int message_line int attrib -> int
/* int A4GL_disp_fields_ap (int n, int attr, va_list* ap)*/
A4GL_disp_fields_ap int n int attr va_list* ap -> int
/* int A4GL_disp_form_fields_ap (int n, int attr, char* formname, va_list* ap)*/
A4GL_disp_form_fields_ap int n int attr char* formname va_list* ap -> int
/* int A4GL_open_form (char* name)*/
A4GL_open_form char* name -> int
/* void A4GL_close_form (char* name)*/
A4GL_close_form char* name -> void
/* int A4GL_disp_form (char* name, int attr)*/
A4GL_disp_form char* name int attr -> int
/* int A4GL_current_window (char* win_name)*/
A4GL_current_window char* win_name -> int
/* int aclfgl_fgl_drawbox (int n)*/
aclfgl_fgl_drawbox int n -> int
/* void* A4GL_new_menu_create (char* title, int x, int y, int mn_type, int help_no)*/
A4GL_new_menu_create char* title int x int y int mn_type int help_no -> void*
/* void A4GL_add_menu_option (voi* menu, char* txt, char* keys, char* desc, int helpno, int attr)*/
A4GL_add_menu_option void* menu char* txt char* keys char* desc int helpno int attr -> void
/* void A4GL_finish_create_menu (void* menu)*/
A4GL_finish_create_menu void* menu -> void
/* void  A4GL_disp_h_menu (void* menu)*/
A4GL_disp_h_menu void* menu -> void
/* int A4GL_menu_loop (void* menu)*/
A4GL_menu_loop_v2 void* menu void* evt -> int
/* void A4GL_next_option (void* menu, char* nextopt)*/
A4GL_next_option void* menu char* nextopt -> void
/* int A4GL_free_menu (void* menu)*/
A4GL_free_menu void* menu -> int
/* int A4GL_req_field_input (void* s, char type, va_list* ap)*/
A4GL_req_field_input void* s char type va_list* ap -> int
/* int A4GL_req_field_input_array (void* s, char type, va_list* ap)*/
A4GL_req_field_input_array void* s char type va_list* ap -> int
/* int A4GL_menu_hide_ap (void* menu, va_list* ap)*/
A4GL_menu_hide_ap void* menu va_list* ap -> int
/* int A4GL_menu_show_ap (void* menu, va_list* ap)*/
A4GL_menu_show_ap void* menu va_list* ap -> int
/* void aclfgli_pr_message_internal (int attr, int wait,char* s)*/
aclfgli_pr_message_internal int attr int wait char* s -> void
/* void A4GL_display_error (int attr, int wait)*/
A4GL_display_error int attr int wait -> void
/* void* A4GL_get_curr_form (int warn_if_no_form)*/
A4GL_get_curr_form int warn_if_no_form -> void*

A4GL_set_option_value_for_current_window char type  int keyval  -> void
A4GL_get_option_value_for_current_window char type   -> int

/* int A4GL_widget_name_match (void* w, char* name)*/
A4GL_widget_name_match void* w char* name -> int
/* int A4GL_gen_field_chars_ap (void* field_list, void* formdets, va_list* ap)*/
A4GL_gen_field_chars_ap void* field_list void* formdets va_list* ap -> int
A4GL_gen_field_list_from_slist void* field_listv void* formdetsv void* listv -> int
/* int A4GL_form_loop (void* s,int init)*/
A4GL_form_loop_v2 void* s int init void* evt -> int
/* int A4GL_push_constr (void* s)*/
A4GL_push_constr void* s -> int
/* int A4GL_set_fields (void* sio)*/
A4GL_set_fields void* sio -> int
/* void A4GL_display_internal (int x, int y, char* s, int a, int clr_line)*/
A4GL_display_internal int x int y char* s int a int clr_line -> void
/* int A4GL_movewin (char* winname, int absol)*/
A4GL_movewin char* winname int absol -> int
/* void A4GL_hide_window (char* winname)*/
A4GL_hide_window char* winname -> void
/* void A4GL_show_window (char* winname)*/
A4GL_show_window char* winname -> void

A4GL_fgl_infield_ap void* inp,va_list* ap -> int
A4GL_fgl_infield_ia_ap void* inp,va_list* ap -> int

/* void A4GL_clr_window (char* winname)*/
A4GL_clr_window char* winname -> void
/* void A4GL_sleep_i (void)*/
A4GL_sleep_i -> void
/* void A4GL_remove_window (char* win_name)*/
A4GL_remove_window char* win_name -> void
/* int A4GL_disp_arr_ap (void* disp, void* ptr, char* srecname, int attrib, va_list* ap)*/
A4GL_disp_arr_v2 void* disp void* ptr char* srecname int attrib int scrollf int scrollw void* evt  -> int
/* int A4GL_inp_arr (void* disp, int defs, char* srecname, int attrib, int init)*/
A4GL_inp_arr_v2 void* disp int defs char* srecname int attrib int init void* evt -> int
/* int A4GL_prompt_loop (void* prompt,int timeout)*/
A4GL_prompt_loop_v2 void* prompt,int timeout void* evt_list -> int
/* int A4GL_start_prompt (void* prompt, int ap, int c, int h, int af)*/
A4GL_start_prompt void* prompt int ap int c int h int af -> int
/* int A4GL_endis_fields_ap (int en_dis, va_list* ap)*/
A4GL_endis_fields_ap int en_dis va_list* ap -> int
/* void A4GL_clr_form (int to_defaults)*/
A4GL_clr_form int to_defaults -> void
/* void A4GL_clr_form_fields (int to_defaults, char* defs)*/
A4GL_clr_form_fields int to_defaults char* defs -> void
/* void A4GL_clr_fields_ap (int to_defaults, va_list* ap)*/
A4GL_clr_fields_ap int to_defaults va_list* ap -> void
/* int A4GL_fgl_getfldbuf_ap (va_list* ap)*/
A4GL_fgl_getfldbuf_ap void* inp va_list* ap -> int
/* int A4GL_fgl_getfldbuf_ia_ap (va_list* ap)*/
A4GL_fgl_getfldbuf_ia_ap void* inp va_list* ap -> int
/* void A4GL_zrefresh (void)*/
A4GL_zrefresh -> void
/* void A4GL_gotolinemode (void)*/
A4GL_gotolinemode -> void
/* char*  A4GL_get_currwin_name (void)*/
A4GL_get_currwin_name -> char*
/* void A4GL_gui_run_til_no_more (void)*/
A4GL_gui_run_til_no_more -> void
/* int A4GL_read_fields (void* formdets)*/
A4GL_read_fields void* formdets -> int
/* int A4GL_read_metrics (void* formdets)*/
A4GL_read_metrics void* formdets -> int
/* int aclfgl_set_page (int n)*/
aclfgl_a4gl_set_page int n -> int
/* int aclfgl_a4gl_get_page (int n)*/
aclfgl_a4gl_get_page int n -> int
/* int aclfgl_a4gl_run_gui (int nargs)*/
aclfgl_a4gl_run_gui int nargs -> int
/* void A4GL_set_infield_from_stack (void)*/
A4GL_set_infield_from_stack -> void
/* int A4GL_open_gui_form_internal (long* form_variable char* name_orig, int absolute, int nat, char* like, int disable, void* handler_e)*/
A4GL_open_gui_form_internal long* form_variable char* name_orig int absolute int nat char* like int disable void* handler_e void* handler_c -> int

/* int A4GL_fgl_fieldnametoid (char* f, char* s, int n)*/
A4GL_fgl_fieldnametoid char* f char* s int n -> int
/* int aclfgl_set_window_title (int nargs)*/
aclfgl_set_window_title int nargs -> int

A4GL_finish_screenio void* sio char* siotype -> void

/* void*  A4GL_make_pixmap_gw (char* filename)*/
A4GL_make_pixmap_gw char* filename -> void*
/* int aclfgl_aclfgl_dump_screen (int n)*/
aclfgl_aclfgl_dump_screen int n -> int
/* int A4GL_set_fields_inp_arr (void* sio)*/
/* A4GL_set_fields_inp_arr void* sio -> int */
/* int A4GL_get_curr_width ()*/
A4GL_get_curr_width -> int
A4GL_get_curr_height -> int
/* int A4GL_iscurrborder ()*/
A4GL_iscurrborder -> int
/* void A4GL_init_color(int n,int r,int g,int b) */
A4GL_init_color int n int r int g int b -> void
/* int A4GL_fgl_fieldtouched_input_ap (void* input, va_list* ap)*/
A4GL_fgl_fieldtouched_input_ap void* input va_list* ap -> int
/* int A4GL_fgl_fieldtouched_input_array_ap (void* input, va_list* ap)*/
A4GL_fgl_fieldtouched_input_array_ap void* input va_list* ap -> int
A4GLUI_ui_init int argc,char** argv -> void
A4GL_acli_scroll_ap int n va_list* ap -> void
A4GL_get_key int timeout -> int
A4GL_create_menu void* m char* id int mode void* handler -> void*
A4GL_reset_state_for void* sio char* siotype -> void
aclfgl_fgl_set_arrline int nparam -> int
aclfgl_fgl_set_scrline int nparam -> int
A4GL_reset_delims void* vformdets void* field char* delims -> void
A4GLUI_set_intr -> void
A4GL_screen_mode int sm -> int
