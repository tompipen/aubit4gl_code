int UILIB_aclfgl_a4gl_get_page (int n);
int UILIB_aclfgl_set_page (int n);
int UILIB_aclfgl_aclfgl_dump_screen(int n) ;
void UILIB_A4GL_gui_run_til_no_more() ;
void UILIB_A4GL_clr_form (int to_default);
void UILIB_A4GL_clr_fields_ap (int to_defaults, va_list * ap);
int UILIB_A4GL_fgl_fieldtouched_input_ap (void *sv, va_list * ap);
int UILIB_A4GL_fgl_fieldtouched_input_array_ap (void *sv, va_list * ap);
int UILIB_A4GL_fgl_getfldbuf_ap (void *inp, va_list * ap);
int UILIB_A4GL_fgl_getfldbuf_ia_ap (void *inp, va_list * ap);
int UILIB_A4GL_fgl_infield_ap (void *inp, va_list * ap);
int UILIB_A4GL_fgl_infield_ia_ap (void *inp, va_list * ap);
int UILIB_A4GL_gen_field_chars_ap (void *field_listv, void *formdetsv, va_list * ap);
void UILIB_A4GL_hide_window (char *winname);
int UILIB_A4GL_movewin (char *winname, int absol);
int UILIB_A4GL_push_constr (void *vs);
int UILIB_A4GL_set_fields (void *vsio);
void UILIB_A4GL_show_window (char *winname);
void UILIB_A4GL_zrefresh() ;
void UILIB_aclfgli_pr_message_internal (int attr, int wait, char *s);


