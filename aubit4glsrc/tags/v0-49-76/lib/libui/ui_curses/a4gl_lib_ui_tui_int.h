
#include "a4gl_API_ui_lib.h"
#include "a4gl_lib_ui_int.h"

    /* =========================== from a4gl_tui_tui.h ======================== */

#define WANTCURSES

#if HAVE_PDCURSES
	#define _SKIP_AAAA_		//don't include anything from form.h
	#ifdef XCURSES
		#include <xcurses.h>
	#else
		#include <curses.h>
	#endif

	#ifdef XCURSES
		#include <xpanel.h>
	#else
		#include <panel.h>
	#endif

	#include <D:/cygwin/usr/include/ncurses/form.h>
#else
	#ifndef _NO_FORM_H_
		#include <form.h>
	#endif
	#if (defined(WIN32) && ! defined(__CYGWIN__) && ! defined(__MINGW32__))
		#ifndef PAN32
			#define PAN32
			#include <panel32.h>
		#endif
	#else
		#ifndef _NO_PANEL_H_
			#ifdef XCURSES
				#include <xpanel.h>
			#else
				#include <panel.h>
			#endif
		#endif
	#endif
#endif


typedef struct
{
  int x1, y1, x2, y2;
  char buf[12000];
  WINDOW *win_no;
}
textarea;


//void *A4GL_memdup (void *ptr, int size);
int A4GL_form_field_chk (struct s_screenio *sio, int m);
int A4GL_form_field_constr (struct s_screenio *sio, int m);
int A4GL_get_curr_metric (struct s_form_dets *form);
void A4GL_mja_set_current_field (FORM * form, FIELD * field);
struct s_form_dets *A4GL_getfromform (FORM * f);
int A4GL_curr_metric_is_used_last_s_screenio (struct s_screenio *s, FIELD * f);
//void A4GL_disp_form_fields_ap (int n, int attr, char *formname, va_list * ap);
//int A4GL_gen_field_chars_ap (FIELD *** field_list, struct s_form_dets *formdets, va_list * ap);
	/* ======================= in colours.c  ======================= */
int A4GL_decode_aubit_attr (int a, char t);
void a4glattr_wattrset (WINDOW * w, int a);
int A4GL_decode_colour_attr_aubit (int a);
int A4GL_colour_code (int a);


	/* ======================= in curslib.c  ======================= */
//void A4GL_error_nobox (char *str);
void A4GL_set_bkg (WINDOW * win, int attr);
void A4GL_clear_prompt (struct s_prompt *prmt);
void A4GL_set_init_value (FIELD * f, void *ptr, int dtype);


	/*  ======================= in ioform.c ======================= */
void A4GL_start_form (struct s_form_dets *s);
void A4GL_set_arr_fields (int n, int attr, ...);
void A4GL_disp_arr_fields (int n, int fonly, int attr, ...);
int A4GL_gen_field_list (FIELD *** field_list, struct s_form_dets *formdets, int a, va_list * ap);
void A4GL_int_form_driver (FORM * form, int a);
int A4GL_copy_field_data (struct s_form_dets *form);
void A4GL_iarr_arr_fields (struct s_inp_arr *arr,int attr,int arr_line,int scr_line,int blank);
int A4GL_get_curr_field_col (FORM * mform);
int A4GL_get_field_width (FIELD * f);
void A4GL_default_attributes (FIELD * f, int dtype);
FIELD *A4GL_make_field (int, int, int, int);
FIELD *A4GL_make_label (int frow, int fcol, char *label);
//int A4GL_req_field_input (struct s_screenio *s, char type, va_list *ap);
int A4GL_chkwin(void);
void aclfgli_show_help (int n);
int aclfgl_a4gl_show_help(int n);
//void A4GL_clr_fields_ap (int to_defaults, va_list *ap);
char *A4GL_string_width (char *s);
WINDOW *A4GL_display_form_win (WINDOW * w, char *name, struct s_form_dets *f);
void A4GL_combi_menu (char *dstn, char *str, int x, int y, int w, int h,
                 char *lst, int lstwidth, int nopts, char *nme, int border);
void A4GL_size_menu (ACL_Menu * menu);
void A4GL_clearbox (textarea * area);
void acllib_pause (char *s);
void A4GL_ask_char (char *prompt, char *s, int a);
void A4GL_ask_cmdline (char *prompt, char *s, int a);
int A4GL_mjalen (char *str);
void A4GL_setreledit (int x, int y);
void A4GL_gsub (char *str);
void A4GL_startit (void);
void A4GL_endit (void);
int A4GL_disp_horiz_menu (char *title, int y, int mn_type);
void *A4GL_decode_clicked (void);
void A4GL_display_menu (ACL_Menu * menu);
void A4GL_h_disp_opt (ACL_Menu * menu, ACL_Menu_Opts * opt1, int offset, int y, int type);
void A4GL_clr_menu_disp (ACL_Menu * menu);
//void aclfgli_pr_message_internal (int attr, int wait,char *s);
//int A4GL_endis_fields_ap (int en_dis, va_list * ap);
int A4GL_curses_to_aubit (int a);

void A4GL_set_option (ACL_Menu * menu, int opt);
//void A4GL_free_menu (ACL_Menu * menu);
//void A4GL_disp_h_menu (ACL_Menu * menu);
//int A4GL_menu_loop (ACL_Menu * menu);
int A4GL_seldir (char *filespec, char *filename);
//void curs_err (char *str);
int A4GL_load_form (char *fname2, int fno1, int fno);
void A4GL_stripbracket (char *str);
void A4GL_clrscr (void);
void A4GL_set_message (char *str, int x, int y);
void A4GL_clr_message (void);
void A4GL_chklistbox (char **arr, int elem, int mult, int x, int y, int w, int h);
int A4GL_isselected (int a);
//void A4GL_next_option (ACL_Menu * menu, char *nextopt);
//void A4GL_menu_hide_ap (ACL_Menu * menu, va_list * ap);
//void A4GL_menu_show (ACL_Menu * menu, ...);
//void aclfgli_pr_message (int attr, int wait);
//void A4GL_set_option_value (char type, int keyval);
//int A4GL_show_menu (void);
//int A4GL_endis_fields (int en_dis, ...);
ACL_Menu *A4GL_new_menu_tui_oldway (char *title, int x, int y, int mn_type, int help_no, int nopts, va_list * ap);
//ACL_Menu *A4GL_new_menu_create (char *title, int x, int y, int mn_type, int help_no);
//void A4GL_add_menu_option (ACL_Menu * menu, char *txt, char *keys, char *desc, int helpno, int attr);
//void A4GL_finish_create_menu (ACL_Menu * menu);
void A4GL_refresh_after_system (void);
WINDOW *A4GL_window_on_top (void);
//void A4GL_menu_show_ap (ACL_Menu * menu, va_list * ap);
int
A4GL_real_getch_swin (WINDOW * window_ptr);
int A4GL_mja_vwprintw (WINDOW * win, char *fmt, va_list * args);
//int   A4GL_current_window          (char *win_name);
void print_panel_stack (void);
void A4GL_init_stddbscr (void);
void A4GL_do_update_panels (void);
void A4GL_change_currwinno (int a, char *s);
void A4GL_change_currwin (WINDOW * a, char *s);
void A4GL_inc_winname (char *b);
int A4GL_getch_swin (WINDOW * window_ptr);
int A4GL_getform_line (void);
int A4GL_find_win (PANEL * p);
int A4GL_screen_height (void);
int A4GL_top_win (PANEL * p);
char *A4GL_pointer_code (int c);
int A4GL_new_do_keys (ACL_Menu * menu, int a);
//void  A4GL_clr_window                      (char *win_name);
int A4GL_int_current_window (char *win_name);
int A4GL_get_curr_win (void);
//int A4GL_get_curr_height (void);
int A4GL_get_curr_top (void);
//char *A4GL_get_currwin_name (void);
//int A4GL_get_curr_border (void);
void display_at2 (char *z, int x, int y, int a);
int A4GL_decode_line (int l);
int A4GL_decode_line_ib (int l);
//void  A4GL_display_error           (int a,int wait);
//void A4GL_add_compiled_form (char *s, char *frm);
//int   A4GL_open_form                       (char *name);
//void  A4GL_close_form                      (char *formname);
//int   A4GL_disp_form                       (char *name, int attr);
int A4GL_set_window (int a);
int A4GL_subwin_printxy (WINDOW * win, int x, int y, char *fmt, ...);
int A4GL_subwin_setcolor (WINDOW * win, int typ);
int A4GL_getcomment_line (void);
void A4GL_set_attr_win (char s, int wattr);
char *A4GL_windowname_on_top (void);
int A4GL_invert_color (int a);
void A4GL_move_bar (ACL_Menu * menu, int a);
int A4GL_find_char (ACL_Menu * menu, int key);
int A4GL_gui_startmenu (char *s, long a);
void make_error_panel_top(void);
PANEL *get_below_panel(PANEL *p);
void A4GL_tui_printr (int refreshwin, char *fmt, ...);
int A4GL_has_timeout(int a);
void A4GL_refresh_error_window(void);
//void  A4GL_sleep_i                         (void);


    /* =======================  in newpanels.c  ======================= */
void A4GL_mja_refresh (void);
void A4GL_mja_wrefresh (WINDOW * w);
int A4GL_getch_win (void);
int A4GL_xwattr_get (WINDOW * w);
    //int               A4GL_iscurrborder            (void);
int A4GL_getmessage_line (void);
WINDOW *A4GL_get_currwin (void);
int A4GL_subwin_print (WINDOW * win, char *fmt, ...);
int A4GL_subwin_gotoxy (WINDOW * win, int x, int y,int has_border);
int A4GL_refresh_menu_window (char *name, int top);
int A4GL_getmenu_line (void);
int A4GL_get_curr_print_top (void);
int A4GL_get_curr_left (void);
void A4GL_mja_endwin (void);
LIBUSEONLY int A4GL_init_windows (void);
int A4GL_init_colour_pairs (void);
int A4GL_geterror_line (void);
void A4GL_mja_setcolor (int typ);
int A4GL_screen_width (void);
    //int               A4GL_get_curr_width          (void);
    //void              A4GL_remove_window           (char *win_name);
int A4GL_find_ptr_debug (void *ptr);
int A4GL_getprompt_line (void);
void A4GL_tui_print (char *fmt, ...);
void A4GL_mja_gotoxy (int x, int y);
void
A4GL_init_curses_stuff (void);
void A4GL_comments (struct struct_scr_field *fprop);
//int A4GL_disp_arr_ap (struct s_disp_arr *disp, void *ptr, char *srecname, int attrib, va_list * ap);
void A4GL_set_field_attr_with_attr (FIELD * field, int attr, int cmd_type);
void A4GL_display_field_contents (FIELD * field, int d1, int s1, char *ptr1);

int A4GL_get_curr_border (void);
//int A4GL_fgl_fieldtouched_input_array_ap (struct s_inp_arr *s, va_list * ap);

void A4GL_mja_pos_form_cursor (FORM * form);
int A4GL_turn_field_off (FIELD * f);
void A4GL_turn_field_on (FIELD * f);
void A4GL_turn_field_on2 (FIELD * f, int a);
void A4GL_debug_print_field_opts (FIELD * a);
int A4GL_form_field_chk_iarr (struct s_inp_arr *sio, int m);

	//int aclfgl_aclfgl_dump_screen(int n);

    /* ======================= in array.c  ======================= */
void A4GL_set_array_mode (int type);


	/* =============== from a4gl_tui_attr_list.h ============== */


#ifdef OBJECTMODULE
attributes attributes_list[] = {
  (int) 0x0, "BLACK", COLOR_BLACK, 0,
  (int) 0x1, "YELLOW", COLOR_YELLOW, A_BOLD,
  (int) 0x2, "MAGENTA", COLOR_MAGENTA, 0,
  (int) 0x3, "RED", COLOR_RED, 0,
  (int) 0x4, "CYAN", COLOR_CYAN, 0,
  (int) 0x5, "GREEN", COLOR_GREEN, 0,
  (int) 0x6, "BLUE", COLOR_BLUE, 0,
  (int) 0x7, "WHITE", COLOR_WHITE, 0,
  (int) 0x8, "UNDERLINE", 0, A_UNDERLINE,
  (int) 0x10, "NORMAL", 0, A_NORMAL,
  (int) 0x20, "BOLD", 0, A_BOLD,
  (int) 0x40, "REVERSE", 0, A_REVERSE,
  (int) 0x80, "BLINK", 0, A_BLINK,
  (int) 0x100, "DIM", 0, A_DIM,
  (int) 0x200, "INVISIBLE", 0, A_INVIS,
  (int) 0, (char *) 0
};

#endif

#ifdef __sun__
#ifdef __sparc__
		/*
		   Error: can't open DLL /home/users/a/af/afalout/aubit4glsrc/lib/libUI_TUI.so - ld.so.1:
		   hello: fatal: relocation error: file /home/users/a/af/afalout/aubit4glsrc/lib/libUI_TUI.so:
		   symbol newscr: referenced symbol not found - STOP
		 */

		//from curses.h:
		//extern WINDOW   *newscr;
WINDOW *newscr;
#endif
#endif

/* ================================ EOF ================================== */
