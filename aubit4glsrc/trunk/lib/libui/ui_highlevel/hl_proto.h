char *A4GL_fld_data_ignore_format(struct struct_scr_field *fprop, char *fld_data);
char *A4GL_string_width(char *s);
int A4GL_check_and_copy_field_to_data_area(struct s_form_dets *form, struct struct_scr_field *fprop, char *fld_data, char *data_area);
int A4GL_chkwin(void);
int A4GL_copy_field_data(struct s_form_dets *form);
int A4GL_curr_metric_is_used_last_s_screenio(struct s_screenio *s, void *f);
int A4GL_decode_colour_attr_aubit(int a);
int A4GL_decode_line(int l);
int A4GL_decode_line_ib(int l);
int A4GL_decode_line_scr(int l);
int A4GL_do_after_field(void *f, struct s_screenio *sio);
int A4GL_field_name_match(void *f, char *s);
int A4GL_field_opts_off(void *v, int n);
int A4GL_field_opts_on(void *v, int n);
int A4GL_find_char (ACL_Menu * menu, int key);
int A4GL_find_field_no(void *f, struct s_screenio *sio);
int A4GL_find_win(void *w);
int A4GL_form_field_chk(struct s_screenio *sio, int m);
int A4GL_form_field_chk_iarr(struct s_inp_arr *sio, int m);
int A4GL_form_field_constr(struct s_screenio *sio, int m);
int A4GL_gen_field_list (void ***field_list, struct s_form_dets *formdets,int a, va_list * ap);
int A4GL_get_curr_border(void);
int A4GL_get_curr_infield(void);
int A4GL_get_curr_left(void);
int A4GL_get_curr_metric(struct s_form_dets *form);
int A4GL_get_curr_print_top(void);
int A4GL_get_curr_top(void);
int A4GL_get_currwinno(void);
int A4GL_get_field_width(void *field);
int A4GL_get_metric_for(struct s_form_dets *form, void *f);
int A4GL_get_metric_no(struct s_form_dets *form, void *f);
int A4GL_getch_win(int allow_acc_intr,char* why);
int A4GL_getcomment_line(void);
int A4GL_geterror_line(void);
int A4GL_getform_line(void);
int A4GL_getmenu_line(void);
int A4GL_getmessage_line(void);
int A4GL_getprompt_line(void);
int A4GL_highlevel_menu_loop(void *menuv);
int A4GL_init_windows(void);
int A4GL_mjalen(char *str);
int A4GL_new_do_keys (ACL_Menu * menu, int a);
int A4GL_proc_key_input(int a, void *mform, struct s_screenio *s);
int A4GL_proc_key_prompt(int a, void *mform, struct s_prompt *prompt);
int A4GL_seldir(char *filespec, char *filename);
int A4GL_set_fields_inp_arr(void *vsio, int n);
int A4GL_turn_field_off(void *f);
int A4GL_win_stack_cnt(void);
void *A4GL_create_window(char *name, int x, int y, int w, int h, int iswindow, int form_line, int error_line, int prompt_line, int menu_line, int border, int comment_line, int message_line, int attrib);
void *A4GL_decode_clicked (void);
void *A4GL_find_form_for_win(void *w);
void *A4GL_window_on_stack(int cnt);
void *A4GL_window_on_top(void);
void *A4GL_window_on_top_ign_menu(void);
void A4GL_clr_field(void *f);
void A4GL_clr_menu_disp (ACL_Menu * menu) ;

void A4GL_comments(struct struct_scr_field *fprop);

void A4GL_default_attributes(void *f, int dtype,int has_picture);
void A4GL_display_field_contents(void *field, int d1, int s1, char *ptr1);
void A4GL_display_menu(ACL_Menu *m) ;
void A4GL_dump_winstack(void);
void A4GL_gsub(char *str);
void A4GL_gui_startmenu (char *mnname, long mn);
void A4GL_h_disp_opt (ACL_Menu * menu, ACL_Menu_Opts * opt1, int offset, int y, int type) ;
void A4GL_iarr_arr_fields(struct s_inp_arr *arr, int dattr, int arr_line, int scr_line, int blank);
void A4GL_inc_winname(char *b);
void A4GL_init_stddbscr (void);
void A4GL_initialize_screen_mode(void);
void A4GL_make_window_with_this_form_current(void *form);
void A4GL_mja_endwin(void);
void A4GL_mja_set_current_field(void *form, void *field);
void A4GL_mja_set_field_buffer(void *field, int nbuff, char *buff);
void A4GL_mja_set_field_buffer_contrl(void *field, int nbuff, int ch);
void A4GL_set_arr_fields(int n, int attr, ...);
void A4GL_set_array_mode(int type);
void A4GL_set_curr_infield(long a);
void A4GL_set_field_attr_with_attr(void *field, int attr, int cmd_type);
void A4GL_set_field_attr_with_attr_already_determined(void *field, int attr, int cmd_type);
void A4GL_set_field_colour_attr(void *field, int do_reverse, int colour);
void A4GL_set_field_pop_attr(void *field, int attr, int cmd_type);
void A4GL_set_infield_from_parameter(int a);
void A4GL_set_init_value(void *f, void *ptr, int dtype);
void A4GL_set_option (ACL_Menu * menu, int opt);
void A4GL_start_form(void *s);
void A4GL_stripbracket(char *str);
void A4GL_switch_to_scr_mode(void);
void A4GL_set_field_attr_for_ll (void *field);
void A4GL_turn_field_on2(void *f, int a);
void A4GL_wprintw(void *win, int attr, int x, int y,int curr_width,int curr_height,int iscurrborder, int currwinno, char *fmt, ...);
void chk_for_picture(void *f, char *buff);
void debug_print_flags(void *sv, char *txt);
void* A4GL_add_window(int x, int y, int w, int h, char *name, void *fd, void *win);
void A4GL_wprintw_window (void *win, int attr, int x, int y, int curr_width,int curr_height,int iscurrborder,int currwinno, char *fmt, ...);
int A4GL_getch_internal(void *win,char *why);



struct list_of_fields {
        struct {
                unsigned int a_len;
                long *a_val;
        } a;
};
typedef struct list_of_fields list_of_fields;




void *A4GL_ll_get_field_userptr(void *f) ;
void A4GL_ll_set_field_userptr(void *f, void *r) ;
void *A4GL_ll_get_form_userptr(void *f) ;
void A4GL_ll_set_form_userptr(void *f, void *r) ;

int A4GL_get_dbscr_promptline(void);
int A4GL_get_dbscr_messageline(void);
int A4GL_get_dbscr_commentline(void);
int A4GL_get_dbscr_errorline(void);
int A4GL_get_dbscr_formline(void);
int A4GL_get_dbscr_menuline(void);
int A4GL_get_dbscr_inputmode(void);
int A4GL_ll_field_opts (void *f);
void A4GL_ll_set_field_opts (void *f,int l);
void A4GL_submit_events(void *s, struct aclfgl_event_list *evt );

