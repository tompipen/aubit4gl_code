/* generic_ui.h */

char *A4GL_string_width (char *s);
void A4GL_strip_nl (char *str);
int A4GL_mjalen (char *str);
void A4GL_set_option (ACL_Menu * menu, int opt);
int A4GL_new_do_keys (ACL_Menu * menu, int a);
int A4GL_find_char (ACL_Menu * menu, int key);
static void A4GL_move_bar (ACL_Menu * menu, int a);
int A4GL_seldir (char *filespec, char *filename);
void A4GL_stripbracket (char *str);
void A4GL_gsub (char *str);
////void UILIB_A4GL_next_option (void *vmenu, char *nextopt);
//int UILIB_A4GL_menu_hide_ap (void *menuv, va_list * ap);
//int UILIB_A4GL_menu_show_ap (void *menuv, va_list * ap);
static void A4GL_menu_attrib (ACL_Menu * menu, int attr, va_list * ap);
static int A4GL_find_shown (ACL_Menu * menu, int chk, int dir);
void A4GL_size_menu (ACL_Menu * menu);
//void *UILIB_A4GL_new_menu_create (char *title, int x, int y, int mn_type,int help_no);
//void UILIB_A4GL_add_menu_option (void *menuv, char *txt, char *keys, char *desc,int helpno, int attr);
//void UILIB_A4GL_finish_create_menu (void *menuv);
ACL_Menu *A4GL_new_menu (char *title,int x, int y, int mn_type, int help_no, int nopts,va_list * ap);
int A4GL_decode_colour_attr_aubit (int a);
//void UILIB_A4GLUI_ui_init (int argc, char *argv[]);
int A4GLUI_initlib ();
//void UILIB_A4GL_display_internal (int x, int y, char *s, int a, int clr_line);
//void UILIB_A4GL_gotolinemode ();
//int UILIB_A4GL_sleep_i (void);
//int UILIB_A4GL_start_prompt (void *vprompt, int ap, int c, int h, int af);
////int UILIB_A4GL_prompt_loop (void *vprompt, int timeout);
//int UILIB_A4GL_menu_loop (void *menuv);
void A4GL_wprintw (void *win, int attr, int x, int y, char *fmt, ...);
//int UILIB_A4GL_read_metrics (void *formdetsv);
//int UILIB_A4GL_read_fields (void *formdetsv);
//int UILIB_A4GL_disp_fields_ap (int n, int attr, va_list * ap);
void A4GL_set_field_pop_attr (void *field, int attr, int cmd_type);
int A4GL_gen_field_list (void ***field_list, struct s_form_dets *formdets,int a, va_list * ap);
int A4GL_get_field_width (void *field);
void A4GL_display_field_contents (void *field, int d1, int s1, char *ptr1);
void A4GL_error_nobox (char *str, int attr);
void A4GL_clr_error_nobox (char *dbg_fromwhere);
int A4GL_curr_metric_is_used_last_s_screenio (struct s_screenio *s, void *f);
int A4GL_form_field_chk (struct s_screenio *sio, int m);
int A4GL_form_field_constr (struct s_screenio *sio, int m);
int A4GL_get_metric_no (struct s_form_dets *form, void *f);
int A4GL_get_metric_for (struct s_form_dets *form, void *f);
char *A4GL_fld_data_ignore_format (struct struct_scr_field *fprop, char *fld_data);
int A4GL_check_and_copy_field_to_data_area (struct s_form_dets *form,struct struct_scr_field *fprop,char *fld_data, char *data_area);
void A4GL_clr_field (void *f);
void A4GL_do_after_field (void *f, struct s_screenio *sio);
int A4GL_find_field_no (void *f, struct s_screenio *sio);

extern void *A4GL_window_on_top_ign_menu (void);
//extern void *UILIB_A4GL_get_curr_form (int warn_if_no_form);
extern void A4GL_display_menu(ACL_Menu *m) ;
extern void A4GL_h_disp_opt (ACL_Menu * menu, ACL_Menu_Opts * opt1, int offset, int y, int type) ;
extern void A4GL_clr_menu_disp (ACL_Menu * menu) ;
extern int A4GL_colour_code(int c) ;
extern void A4GL_switch_to_line_mode(void) ;
extern void A4GL_out_linemode(char *s) ;
extern A4GL_wadd_char_xy_col( void *win,int x,int y,int ch) ;
extern void A4GL_screen_update(void) ;
extern void A4GL_LL_sleep(int n) ;
extern int A4GL_LL_start_prompt (void *vprompt, int ap, int c, int h, int af) ;
//extern int A4GL_LL_prompt_loop (void *vprompt,int timeout) ;
extern int A4GL_LL_menu_loop (void *menuv) ;
extern void * A4GL_LL_make_label (int frow, int fcol, char *label) ;
extern void *A4GL_LL_make_field (void *fprop,int frow, int fcol, int rows, int cols) ;
extern int A4GL_LL_set_new_page(void *field,int n) ;
extern void A4GL_LL_set_field_userptr (void *field, void *ptr) ;
extern void A4GL_LL_set_field_attr ( void *field) ;
//extern void *A4GL_LL_new_form(void **fields) ;
extern void A4GL_LL_set_form_userptr(void *form,void *data) ;

void A4GL_LL_enable_menu (void);

extern void *A4GL_LL_get_field_userptr (void *field) ;
/* extern int A4GL_LL_field_opts (void *field) ; */
extern char *A4GL_LL_field_buffer(void *field,int n) ;
extern int A4GL_LL_set_field_opts (void *field, int oopt) ;
extern int A4GL_screen_width(void) ;
extern void *A4GL_LL_create_errorwindow(int h,int w,int y,int x,int attr,char *str) ;
extern void A4GL_LL_delete_errorwindow(void *curr_error_window) ;
extern void *A4GL_LL_current_field (void *form) ;
extern void A4GL_LL_set_current_field(void *form,void *field) ;
extern int A4GL_LL_int_form_driver (void *mform, int mode) ;
extern int A4GL_LL_field_status(void *field) ;
extern void A4GL_LL_set_carat(void *form) ;

int A4GL_ll_set_field_opts (void *field, int oopt);
int A4GL_ll_field_opts (void *field);

int local_chk_field (struct s_form_dets *form, void *f);
//int ll_need_wordwrap_spaces(void);
