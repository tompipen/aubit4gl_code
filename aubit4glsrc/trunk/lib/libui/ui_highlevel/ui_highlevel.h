#include "a4gl_libaubit4gl.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>





void A4GL_switch_to_line_mode(void) ;
void A4GL_display_menu(ACL_Menu *m) ;
void *A4GL_LL_create_window(int h,int w,int y,int x,int border) ;
void A4GL_LL_remove_window(void *x) ;
void A4GL_wadd_char_xy_col( void *win,int x,int y,int ch) ;
void A4GL_screen_update(void) ;
void A4GL_LL_screen_refresh(void) ;
int A4GL_colour_code(int c) ;
void A4GL_initialize_screen_mode(void) ;
void A4GL_switch_to_scr_mode(void) ;
void A4GL_error_box(char *str,int attr) ;
void *A4GL_display_form(void *f,int attr) ;
void A4GL_h_disp_opt (ACL_Menu * menu, ACL_Menu_Opts * opt1, int offset, int y, int type) ;
void A4GL_clr_menu_disp (ACL_Menu * menu) ;
void A4GL_out_linemode(char *s) ;
void A4GL_LL_sleep(int n) ;
void A4GL_LL_make_window_top(void *w) ;
int A4GL_screen_width(void) ;
int A4GL_screen_height(void) ;
void A4GL_set_bkg(void *win, int attr) ;
int A4GL_decode_aubit_attr (int a, char s) ;
int A4GL_LL_menu_loop (void *menuv) ;
int A4GL_LL_start_prompt (void *vprompt, int ap, int c, int h, int af) ;
int A4GL_LL_prompt_loop (void *vprompt,int timeout) ;
void *A4GL_LL_make_field (void *fprop,int frow, int fcol, int rows, int cols) ;
void * A4GL_LL_make_label (int frow, int fcol, char *label) ;
int A4GL_LL_set_new_page(void *field,int n) ;
void A4GL_LL_set_field_userptr (void *field, void *ptr) ;
void *A4GL_LL_get_field_userptr (void *field) ;
void A4GL_LL_set_field_attr ( void *field) ;
void *A4GL_LL_new_form(void **fields) ;
void A4GL_LL_set_form_userptr(void *form,void *data) ;
void *A4GL_LL_get_form_userptr(void *form) ;
char *A4GL_LL_field_buffer(void *field,int n) ;
void A4GL_LL_set_field_buffer(void *field,int n,char *str) ;
int A4GL_LL_field_opts (void *field) ;
int A4GL_LL_set_field_opts (void *field, int oopt) ;
void A4GL_LL_set_field_fore(void *field,int attr) ;
void A4GL_LL_set_field_back(void *field,int attr) ;
void A4GL_LL_set_current_field(void *form,void *field) ;
void A4GL_LL_set_carat(void *form) ;
int A4GL_LL_getch_win() ;
int A4GL_LL_get_carat(void *form) ;
int A4GL_LL_int_form_driver (void *mform, int mode) ;
void *A4GL_LL_current_field (void *form) ;
void A4GL_LL_set_form_page(void *form,int page) ;
void *A4GL_LL_create_errorwindow(int h,int w,int y,int x,int attr,char *str) ;
void A4GL_LL_delete_errorwindow(void *curr_error_window) ;
int A4GL_LL_field_status(void *field) ;


