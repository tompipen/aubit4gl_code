/* forms.h */
#ifndef HL_FORMS_H
#define HL_FORMS_H
#include "a4gl_libaubit4gl.h"

struct s_windows
{
  int x, y, w, h;
  void *win;
  char name[20];
  struct s_form_dets *form;
  struct s_form_attr winattr;
};



extern A4GL_LL_create_window(int h,int w,int y,int x,int border) ;
extern A4GL_LL_remove_window(void *x) ;
extern int A4GL_decode_aubit_attr (int a, char s) ;
extern int A4GL_screen_height(void) ;
extern int A4GL_screen_width(void) ;
extern void *A4GL_LL_get_field_userptr (void *field) ;
extern void *A4GL_display_form(void *f,int attr) ;
extern void A4GL_LL_make_window_top(void *w) ;
extern void A4GL_LL_set_field_back(void *field,int attr) ;
extern void A4GL_LL_set_field_buffer(void *field,int n,char *str) ;
extern void A4GL_LL_set_field_fore(void *field,int attr) ;
extern void A4GL_error_box(char *str,int attr) ;
extern void A4GL_screen_update(void) ;
extern void A4GL_set_bkg(void *win, int attr) ;
extern void A4GL_switch_to_line_mode(void) ;
extern void A4GL_switch_to_scr_mode(void) ;
char *A4GL_glob_window (int x, int y, int w, int h, int border);
char *UILIB_A4GL_get_currwin_name (void);
int A4GL_chkwin (void);
int A4GL_decode_line (int l);
int A4GL_decode_line_ib (int l);
int A4GL_decode_line_scr (int l);
int A4GL_find_win (void *w);
int A4GL_get_curr_border (void);
int A4GL_get_curr_left (void);
int A4GL_get_curr_print_top (void);
int A4GL_get_curr_top (void);
int A4GL_get_currwinno (void);
int A4GL_getcomment_line (void);
int A4GL_geterror_line (void);
int A4GL_getform_line (void);
int A4GL_getmenu_line (void);
int A4GL_getmessage_line (void);
int A4GL_getprompt_line (void);
int A4GL_init_windows (void);
int UILIB_A4GL_cr_window_form (char *namet,int iswindow,int form_line,int error_line,int prompt_line,int menu_line,int border, int comment_line, int message_line,int attrib);
int UILIB_A4GL_current_window (char *win_name);
int UILIB_A4GL_disp_form (char *name, int attr);
int UILIB_A4GL_get_curr_height (void);
int UILIB_A4GL_get_curr_width (void);
int UILIB_A4GL_iscurrborder (void);
int UILIB_A4GL_open_form (char *name);
int UILIB_aclfgl_fgl_drawbox (int n);
void *A4GL_create_blank_window (char *name, int x, int y, int w, int h, int border);
void *A4GL_create_window (char *name, int x, int y, int w, int h,int iswindow,int form_line,int error_line,int prompt_line,int menu_line,int border, int comment_line, int message_line,int attrib);
void *A4GL_display_form_new_win (char *name, struct s_form_dets *f, int x,int y, int attr);
void *A4GL_get_currwin (void);
void *A4GL_window_on_top (void);
void *A4GL_window_on_top_ign_menu (void);
void *UILIB_A4GL_get_curr_form (int warn_if_no_form);
void A4GL_dump_winstack (void);
void A4GL_inc_winname (char *b);
void A4GL_mja_endwin (void);
void A4GL_mja_set_field_buffer (void *field, int nbuff, char *buff);
void A4GL_scale_form (struct s_form_dets * f, int *y, int *x);
void A4GL_set_field_attr_with_attr (void *field, int attr, int cmd_type);
void A4GL_set_field_colour_attr (void *field, int do_reverse, int colour);
void A4GL_win_stack (struct s_windows *w, int op);
void UILIB_A4GL_close_form (char *formname);
void UILIB_A4GL_display_error (int a, int wait);
void UILIB_A4GL_remove_window (char *win_name);
#endif
