/* menu.h */

void UILIB_A4GL_disp_h_menu (void *menuv);

extern char *UILIB_A4GL_get_currwin_name (void);
extern char *A4GL_glob_window (int x, int y, int w, int h, int border);
extern void A4GL_set_bkg(void *win, int attr) ;
extern int A4GL_decode_aubit_attr (int a, char s) ;
extern void A4GL_display_menu(ACL_Menu *m) ;

