#include "a4gl_libaubit4gl.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>





void A4GL_switch_to_line_mode(void) ;
void A4GL_display_menu(ACL_Menu *m) ;
void A4GL_wadd_char_xy_col( void *win,int x,int y,int ch) ;
void A4GL_screen_update(void) ;
int A4GL_colour_code(int c) ;
void A4GL_initialize_screen_mode(void) ;
void A4GL_switch_to_scr_mode(void) ;
void *A4GL_display_form(void *f,int attr) ;
void A4GL_h_disp_opt (ACL_Menu * menu, ACL_Menu_Opts * opt1, int offset, int y, int type) ;
void A4GL_clr_menu_disp (ACL_Menu * menu) ;
void A4GL_out_linemode(char *s) ;
int A4GL_screen_width(void) ;
int A4GL_screen_height(void) ;
void A4GL_set_bkg(void *win, int attr) ;
int A4GL_decode_aubit_attr (int a, char s) ;

ACL_Menu_Opts *A4GL_LL_show_menu_large(ACL_Menu *menu, int key);

