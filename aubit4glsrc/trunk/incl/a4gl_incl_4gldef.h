/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-1 Aubit Development Team (See Credits file)       |
# +----------------------------------------------------------------------+
# | This program is free software; you can redistribute it and/or modify |
# | it under the terms of one of the following licenses:                 |
# |                                                                      |
# |  A) the GNU General Public License as published by the Free Software |
# |     Foundation; either version 2 of the License, or (at your option) |
# |     any later version.                                               |
# |                                                                      |
# |  B) the Aubit License as published by the Aubit Development Team and |
# |     included in the distribution in the file: LICENSE                |
# |                                                                      |
# | This program is distributed in the hope that it will be useful,      |
# | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
# | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
# | GNU General Public License for more details.                         |
# |                                                                      |
# | You should have received a copy of both licenses referred to here.   |
# | If you did not, or have any questions about Aubit licensing, please  |
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: a4gl_incl_4gldef.h,v 1.36 2003-04-24 08:30:18 mikeaubury Exp $
*/

/**
 * @file
 *
 * Definition of structures and typedefs necessary in both lib and generated
 * C code.
 *
 * Header file used to include in the generated c files with origin
 * in the 4gl source files.
 *
 * This file is included from:
 * a4gl_incl_4glhdr.h (included by 4glc compiled 4gl code)
 * and
 * a4gl_libaubit4gl.h (included from the most of Aubit compiler and libraries code)
 *
 */

#ifndef FGLDEF_INCL

#define FGLDEF_INCL
#include <stdarg.h>

#ifdef __cplusplus

extern "C"
{
#endif
#include <stdio.h>
#define fglbyte struct fgl_int_loc
#define fgltext struct fgl_int_loc

	/** Date time defined without typedef. To be deprecated */
#define struct_dtime struct A4GLSQL_dtime
#define struct_ival struct ival

	/**
	 * Binding information structure definition.
	 * Used to bind values to and from SQL.
	 * Need to be here because a4gl_API_sql.h needs it
	 */
  struct BINDING
  {
    void *ptr;		   /**< A pointer to the variable bounded */
    int dtype;		   /**< The data type of the variable bounded */
    long size;		   /**< The size in bytes of the variable bounded */

    long start_char_subscript;
    long end_char_subscript;
  };


	/** SQLCA structure definition */
  typedef struct
  {
    long sqlcode;
    char sqlerrm[73];
    char sqlerrp[9];
    int sqlerrd[6];
    char sqlawarn[9];
    char sqlstate[10];
  }
  sqlca_struct;

	/**
	 * Decimal 4gl data type variable definition
	 */
  typedef struct
  {
    char data[64];	       /**< The value stored in decimal variable */
  }
  fgldecimal;

	/** This type name is just to have some pattern in type names */
  typedef fgldecimal FglDecimal;

  typedef fgldecimal FglMoney;

	/**
	 * Money 4gl data type variable definition
	 */
  typedef struct
  {
    char data[64];	       /**< The value stored in money variable */
  }
  fglmoney;

  struct fgl_int_loc
  {
    char where;
    FILE *f;
    long memsize;	/**< Memory size */
    char filename[256];
    void *ptr;
  };


	/** 4gl Byte data type */
  typedef struct fgl_int_loc FglByte;

	/** 4gl Text data type */
  typedef struct fgl_int_loc FglText;

	/** Date data type */
  typedef long FglDate;

	/**
	 * Datetime value variable type.
	 *
	 * The name was chaged due to imcompatibility with esql/c
	 * 
	 * The values in qualifiers are :
	 *   - 1 : YEAR
	 *   - 2 : MONTH
	 *   - 3 : DAY
	 *   - 4 : HOUR
	 *   - 5 : MINUTE
	 *   - 6 : SECOND
	 *   - > 6 FRACTION + precision of fraction (2 by default)
	 */
  struct A4GLSQL_dtime
  {
    int stime;		   /**< The start qualifier */
    int ltime;		   /**< The end qualifier */
    char data[32];	   /**< The information in the var */
  };


	/** 4gl Interval data type definition */
  typedef struct A4GLSQL_dtime FglDatetime;

	/**
	 * Interval variable data type.
	 */

  struct ival
  {
    int stime;		   /**< The start qualifier */
    int ltime;		   /**< The end qualifier */
    char data[32];	   /**< The value of the interval variable */
    int i_years;
    int i_months;
    int i_days;
    int i_hours;
    int i_minutes;
    int i_seconds;
    long i_fractions;
  };


	/** 4gl Datetime data type definition */
  typedef struct ival FglInterval;

/* This prototypes should be created by 4glc, in assist.h, but they are not.
in any case , since the need to exist when compiling 4gl code, they need to be
here.

FIXME: declare this prototypes here:


assist.c:70: warning: no previous declaration for `aclfgl_set_window_title'
assist.c:92: warning: no previous declaration for `aclfgl_get_window_title'
assist.c:114: warning: no previous declaration for `aclfgl_set_window_icon'
assist.c:160: warning: no previous declaration for `aclfgl_set_frame_style'
assist.c:181: warning: no previous declaration for `aclfgl_yeild'
assist.c:199: warning: no previous declaration for `aclfgl_set_window_type'
assist.c:220: warning: no previous declaration for `aclfgl_set_prompt_style'
assist.c:247: warning: no previous declaration for `aclfgl_get_filename'
assist.c:321: warning: no previous declaration for `aclfgl_app_top_get'
assist.c:350: warning: no previous declaration for `aclfgl_app_hide'
assist.c:368: warning: no previous declaration for `aclfgl_app_show'
assist.c:386: warning: no previous declaration for `aclfgl_app_maximize'
assist.c:404: warning: no previous declaration for `aclfgl_app_minimize'
assist.c:422: warning: no previous declaration for `aclfgl_app_restore'
assist.c:440: warning: no previous declaration for `aclfgl_entry_max_chars_set'
assist.c:466: warning: no previous declaration for `aclfgl_entry_selected_cut'
assist.c:489: warning: no previous declaration for `aclfgl_entry_selected_copy'
assist.c:512: warning: no previous declaration for `aclfgl_entry_selected_paste'
assist.c:535: warning: no previous declaration for `aclfgl_entry_selection_set'
assist.c:568: warning: no previous declaration for `aclfgl_entry_text_get'
Assist.c:596: warning: no previous declaration for `aclfgl_field_hide'
assist.c:619: warning: no previous declaration for `aclfgl_field_show'
assist.c:640: warning: no previous declaration for `aclfgl_form_caption_get'
assist.c:658: warning: no previous declaration for `aclfgl_form_hide'
assist.c:676: warning: no previous declaration for `aclfgl_form_show'
assist.c:694: warning: no previous declaration for `aclfgl_form_is_open'
assist.c:724: warning: no previous declaration for `aclfgl_list_count_get'
assist.c:747: warning: no previous declaration for `aclfgl_list_current_get'
assist.c:774: warning: no previous declaration for `aclfgl_list_delete'
assist.c:801: warning: no previous declaration for `aclfgl_list_insert'
assist.c:834: warning: no previous declaration for `aclfgl_list_selected'
*/



  /* ===================== from builtin.c =================== */

  /*
     Note : all functions with aclfgl_ prefix are callable from
     compiled 4gl code, since all references to functions get aclfgl_ prefix
     appended to them by 4gl compiler. Therefore, compiled 4gl code CANNOT
     call any function in Aubit libraries without aclfgl prefix.
   */


  int aclfgl_set_count (int nargs);
  int aclfgl_arr_count (int nargs);
  int aclfgl_scr_line (int nargs);
  int aclfgl_arr_curr (int nargs);
  int aclfgl_length (int nargs);
  int acli_scroll (void *s, int n);
  void acli_datetime (char *s, int n);


  int aclfgl_err_get (int statusnumber);	// CHECK
  int aclfgl_err_print (int statusnumber);	// THESE SHOULD BE PASSED
  int aclfgl_err_quit (int statusnumber);	// A NUMBER OF PARAMETERS
  int aclfgl_startlog (char *filename);	// NOT THE PARAMETERS THEMSELVES

#define aclfgl_errorlog(n)  A4GL_errorlog(__FILE__,__LINE__,n);
#define aclfgl_startlog(n)  A4GL_startlog(__FILE__,__LINE__,n);

  //int     aclfgl_errorlog       (int n);
  int A4GL_errorlog (char *s, int l, int n);
  int A4GL_startlog (char *s, int l, int n);

  int aclfgl_showhelp (int helpnumber);
  int aclfgl_fgl_getenv (int nargs);
  int aclfgl_mdy (int nargs);
  char *char_pop (void);


  /* ======================= From buildtin_d.c ==================== */

  int aclfgl_date (int nargs);
  int aclfgl_day (int nargs);
  int aclfgl_month (int nargs);
  int aclfgl_year (int nargs);
  int aclfgl_weekday (int nargs);


  int aclfgl_hex (int nargs);
  int aclfgl_abs (int nargs);
  int aclfgl_root (int nargs);
  int aclfgl_sqrt (int nargs);

  int gen_field_chars (void ***field_list, void *formdets, ...);
  int set_fields (void *sio);
  void aclfgli_clr_err_flg (void);
  void set_option_value (char type, int keyval);
  int aclfgli_get_err_flg (void);
  void A4GLSTK_setCurrentLine (const char *moduleName, int lineNumber);
  void clr_fields (int to_defaults, char *flds,int fno,...);

  int chk_iskey (char *keys);
  int fgl_infield (char *s, int a);
  int disp_fields (int n, int attr, ...);
  void disp_fields_ap (int n, int attr, va_list * ap);

  int fgl_getfldbuf (char *fields,int n);
  void set_init (struct BINDING *b, int n);
  int start_prompt (void *prompt, int ap, int c, int h, int af);	// Not really a char *prompt - but in an app it is...
  void display_error (int attr, int wait);
  int req_field (void *s, int size, char *fieldname, int fno);
  void set_infield_from_stack (void);
  int form_loop (void *s);
  void aclfgli_pr_message (int attr, int wait);
  int push_constr (void *s);	// really a s_screenio - but not in an app
  int cr_window_form (char *name, int iswindow, int form_line,
		      int error_line, int prompt_line, int menu_line,
		      int border, int comment_line, int message_line,
		      int attrib);
  void remove_window (char *win_name);
  int prompt_loop (void *prompt);
  void push_disp_bind (void *b, int n);
  void fgl_start (int nargs, char *argv[]);
  void A4GLSTK_initFunctionCallStack (void);
  void fgl_end (void);
  int open_form (char *name);
  int disp_form (char *name, int attr);
  void close_form (char *name);
  void system_run (int a);
  void push_time (void);
  int movewin (char *winname, int absol);
  void hide_window (char *winname);
  void show_window (char *winname);
  void clr_window (char *winname);
  void sleep_i (void);
  int disp_arr (void *disp, void *ptr, char *srecname, int attrib, ...);
  void *cr_window (char *s, int iswindow, int form_line,
		   int error_line, int prompt_line, int menu_line,
		   int border, int comment_line, int message_line,
		   int attrib);


  int disp_form_fields (int n, int attr, char *formname, ...);

  int current_window (char *win_name);
  void next_option (void *menu, char *nextopt);
  int open_gui_form (char *name_orig, int absolute, int nat, char *like,
		     int disable, void *handler_e,
		     void (*handler_c (int a, int b)));
  void *make_pixmap (char *filename);
  int fgl_fieldnametoid (char *f, char *s, int n);
  void *get_curr_win_gtk (void);
  int aclfgl_aclfgl_dump_screen (int n);

  int set_fields_inp_arr (void *sio);
  int endis_fields (int en_dis, ...);
  void clr_form (int to_defaults);
  void clr_form_fields (int to_defaults, char *defs);

  /* ============= from assist.4gl/.c ======================= */
  int aclfgl_run_gui (int nargs);

  /* ============== from curslib.c =========================== */
  int aclfgl_fgl_drawbox (int n);
  //void  aclfgl_fgl_drawbox (int n);

  /* ======================= API_ui.c ===================== */

//does not match actual function definition:
  int aclfgl_set_page (int nargs);
  int aclfgl_get_page (int nargs);

  /* ======================= builtin.c  ================== */
  void aclfgli_current (int a, int b);
  void push_current (int a, int b);	/* stack.c */
  char *aclfgli_str_to_id (char *name);
  int aclfgl_ascii (int n);
  void push_ascii (void);	/* stack.c */
  void acli_interval (char *s, int n);
  int ctodt (void *a, void *b, int size);
  int ctoint (void *a, void *b, int size);


  //int     aclfgl_set_page               (void);
  //int     aclfgl_get_page               (void);


  /* =================== sql.c ============================ */

  int aclfgl_hstmt_get (int np);

  /* ====================== extfile.c ===================== */

  int aclfgl_fgl_show_help (int a);

  /* ====================== fglwrap.c ====================== */

  int aclfgl_get_ui_mode (int n);
  int aclfgl_num_args (int n);
  int aclfgl_arg_val (int n);

  /* ======================= helper.c ======================= */

  int aclfgl_i_rowid_s (int arg);
  int aclfgl_m_rowid_s (int arg);
  int aclfgl_r_rowid_s (int arg);
  int aclfgl_s_rowid_s (int arg);
  int aclfgl_w_rowid_s (int arg);
  int aclfgl_fgl_prtscr (int n);
  int aclfgl_get_info (int np);

  /* ====================== others.c ======================= */

  int aclfgl_fgl_lastkey (int _np);
  int aclfgl_fgl_keyval (int _np);
  int aclfgl_upshift (int _np);
  int aclfgl_downshift (int _np);
  void upshift_stk(void);
  void downshift_stk(void);

  /* ======================== datatypes.c ================ */

  int aclfgl_load_datatype (int nargs);


#ifndef REP_STRUCTURE
#define REP_STRUCTURE
  /* report stuff */
  struct rep_structure
  {
    int top_margin, bottom_margin, left_margin, right_margin;
    int page_length;
    int has_first_page;
    char *next_page;
    char *rep_table;		/* database table for aggregate values */
    struct BINDING *group_data;
    char output_mode;
    char output_loc[256];
    char top_of_page[256];
    FILE *output;
    int page_no;
    int printed_page_no;
    int line_no;
    int col_no;
    int (*report) (int a, int b);
  };

  struct pdf_rep_structure
  {
    double top_margin, bottom_margin, left_margin, right_margin;
    double page_length;
    double page_width;
    int has_first_page;
    char *next_page;
    char *rep_table;		/* database table for aggregate values */
    struct BINDING *group_data;
    char output_mode;
    char output_loc[256];
    FILE *output;
    int page_no;
    int printed_page_no;
    double line_no;
    double col_no;
    int (*report) (int a, int b);
    char font_name[256];
    double font_size;
    int paper_size;
    void *pdf_ptr;
    int font;
  };
#endif

/*
to fix the _nm_status error (if status is an int) change

extern int a4gl_status;

to
__attribute__((dllimport))extern int a4gl_status;

That's the ugly, short-hand way.  For some reason, auto-import
doesn't always work.  Search the mailing lists for more correct
ways of handling this (if you use the same include file to build
your library and in your applications - above should only
be used in applications which link to the library).
*/


#if ( defined(__CYGWIN__) || defined(__MINGW32__) )
#define __NEED_DLL_IMPORT__
#endif

#ifdef __NEED_DLL_IMPORT__
#define dll_export __declspec(dllexport)
#define dll_import extern __declspec(dllimport)	// for complex vars that can't be auto imported
#else
#define dll_export
#define dll_import extern
#endif

#ifndef _DEFINE_STATUSVARS_	/* set from fglwrap.c --ONLY-- */
  /* for everything except libaubit4gl: */

#ifndef _SQLCA_DEFINED_
  /*
     _SQLCA_DEFINED_ is set in esql.ec to prevent conflict with Informix headers
     that also define sqlca:
   */
#define _SQLCA_DEFINED_
#endif

  extern long a4gl_status;				/** 4gl global status variable */
  extern long int_flag;					/** 4gl interrupt ocurred global flag */
  extern long quit_flag;				/** 4gl quit ocurred global flag */
#else
  /* only in libaubit4gl */
  dll_export sqlca_struct a4gl_sqlca;	    /** Sqlca variable -- DEFINED WHERE ??? --*/
  long a4gl_status;							/** 4gl global status variable */
  long int_flag;						/** 4gl interrupt ocurred global flag */
  long quit_flag;						/** 4gl quit ocurred global flag */
#endif







#ifdef __cplusplus
}
#endif
#endif				/* #ifndef FGLDEF_INCL */
