
	#include "a4gl_lib_ui_int.h"


    /* =========================== from a4gl_tui_tui.h ======================== */

	#define WANTCURSES

    #if HAVE_PDCURSES
		#define _SKIP_AAAA_ //don't include anything from form.h
		#include <curses.h>
		#include <panel.h>
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
				#include <panel.h>
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

	/* ======================= in colours.c  ======================= */
	int 		decode_aubit_attr	(int a,char t);
	void 		a4glattr_wattrset	(WINDOW *w,int a);
    int 		decode_colour_attr_aubit(int a);
	int 		colour_code 		(int a);


	/* ======================= in curslib.c  ======================= */
	void 		error_nobox			(char *str);
	void 		set_bkg				(WINDOW *win,int attr);
	void 		clear_prompt 		(struct s_prompt *prmt);


	/*  ======================= in ioform.c ======================= */
	void 		start_form 			(struct s_form_dets *s);
    void 		set_arr_fields 		(int n, int attr, ...);
    void 		disp_arr_fields 	(int n, int fonly, int attr, ...);
    int 		gen_field_list 		(FIELD *** field_list, struct s_form_dets *formdets, int a,va_list * ap);
    void 		int_form_driver 	(FORM * form, int a);
    int 		copy_field_data 	(struct s_form_dets * form);
    void 		iarr_arr_fields 	(int n, int fonly, int attr, ...);
    int 		get_curr_field_col 	(FORM * mform);
	void 		default_attributes 	(FIELD * f, int dtype);
    FIELD * 	make_field 			(int, int, int, int);
    FIELD * 	make_label 			(int frow, int fcol, char *label);


    /* =======================  in newpanels.c  ======================= */
    void 		mja_refresh 		(void);
    void 		mja_wrefresh 		(WINDOW * w);
	int 		getch_win 			(void);
	int 		xwattr_get 			(WINDOW * w);
    int 		iscurrborder 		(void);
    int 		getmessage_line 	(void);
    WINDOW * 	get_currwin 		(void);
    int 		subwin_print 		(WINDOW * win, char *fmt,...);
    int 		subwin_gotoxy 		(WINDOW * win, int x, int y);
    int 		refresh_menu_window (char *name,int top);
    int 		getmenu_line 		(void);
    int 		get_curr_print_top 	(void);
    int 		get_curr_left 		(void);
    void 		mja_endwin 			(void);
    LIBUSEONLY int init_windows 	(void);
    int 		init_colour_pairs 	(void);
    int 		geterror_line 		(void);
    void 		mja_setcolor 		(int typ);
    int 		screen_width 		(void);
    int 		get_curr_width 		(void);
    //void 		remove_window 		(char *win_name);
    int 		find_ptr_debug 		(void *ptr);
    int 		getprompt_line 		(void);
	void 		tui_print 			(char *fmt,...);
	
	//int aclfgl_aclfgl_dump_screen(int n);

    /* ======================= in array.c  ======================= */
    void set_array_mode(int type);


	/* =============== from a4gl_tui_attr_list.h ============== */


	#ifdef OBJECTMODULE
	attributes attributes_list[]=
	{
	        (int)0x0,"BLACK",COLOR_BLACK,0,
	        (int)0x1,"YELLOW",COLOR_YELLOW,A_BOLD,
	        (int)0x2,"MAGENTA",COLOR_MAGENTA,0,
	        (int)0x3,"RED",COLOR_RED,0,
	        (int)0x4,"CYAN",COLOR_CYAN,0,
	        (int)0x5,"GREEN",COLOR_GREEN,0,
	        (int)0x6,"BLUE",COLOR_BLUE,0,
	        (int)0x7,"WHITE",COLOR_WHITE,0,
	        (int)0x8,"UNDERLINE",0,A_UNDERLINE,
	        (int)0x10,"NORMAL",0,A_NORMAL,
	        (int)0x20,"BOLD",0,A_BOLD,
	        (int)0x40,"REVERSE",0,A_REVERSE,
	        (int)0x80,"BLINK",0,A_BLINK,
	        (int)0x100,"DIM",0,A_DIM,
	        (int)0x200,"INVISIBLE",0,A_INVIS,
	        (int)0,(char *)0
	};

	#endif

#ifdef __sun__
	#ifdef __sparc__
		/*
		 Error: can't open DLL /home/users/a/af/afalout/aubit4glsrc/lib/libUI_TUI.so - ld.so.1:
		 hello: fatal: relocation error: file /home/users/a/af/afalout/aubit4glsrc/lib/libUI_TUI.so:
		 symbol newscr: referenced symbol not found - STOP
		*/

		//from ncurses/curses.h:
		//extern WINDOW   *newscr;
        WINDOW   *newscr;
    #endif
#endif

/* ================================ EOF ================================== */

