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
# $Id: a4gl_incl_4gldef.h,v 1.72 2004-09-08 10:05:21 afalout Exp $
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

#ifndef _NO_SYSINCL_

	#ifndef __NO_STDARG__
	//int stdargSTART______________________;
		#include <stdarg.h>
	//int stdargEND______________________;
	#endif
#endif // _NO_SYSINCL_

#ifdef __cplusplus

extern "C"
{
#endif

#ifndef _NO_SYSINCL_
	//int stdioSTART________________;
	#include <stdio.h>
	//int stdioEND________________;
#endif

#define AFT_FIELD_CHK(zzz,xxx) (_fld_dr==-98&&A4GL_field_name_str_match(fldname,zzz))
#define BEF_FIELD_CHK(zzz,xxx) (_fld_dr==-97&&A4GL_field_name_str_match(fldname,zzz))

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
    unsigned char dec_data[64];	       /**< The value stored in decimal variable */
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
    unsigned char dec_data[64];	       /**< The value stored in money variable */
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

struct s_constr_list {char *tabname;char *colname;};

	/** 4gl Datetime data type definition */
  typedef struct ival FglInterval;

  typedef struct ACL_Menu_Opts
  {
    char opt_title[80];
    char optkey[80];
    int optlength;
    int opt_no;
    int help_no;
    int optpos;
    int attributes;
    char shorthelp[80];
    struct ACL_Menu_Opts *next_option;
    struct ACL_Menu_Opts *prev_option;
    int page;
  }
  ACL_Menu_Opts;

  typedef struct
  {
    char menu_title[80];
    int menu_type;
    char parent_window_name[20];
    ACL_Menu_Opts *curr_option;
    int menu_offset;
    int mn_offset;
    int x;
    int y;
    int help_no;
    int num_opts;
    int abort_pressed;
    ACL_Menu_Opts *first;
    ACL_Menu_Opts *last;	/* used for wrapping round */
    //void *menu_win;
    int curr_page;
    int max_page;
    int w;
    int menu_line;
    int attrib;
    int gw_y;
    int gw_x;
    int gw_b;
  }
  ACL_Menu;

  struct aclfgl_event_list {
        int event_type;
        int block;
        int keycode;
        char *field;
  };


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

void A4GL_setnull (int type, void *buff, int size);
void A4GL_trim (char *p);
  int aclfgl_set_count (int nargs);
int a_isprint(int a);
  int aclfgl_arr_count (int nargs);
  int aclfgl_scr_line (int nargs);
  int aclfgl_arr_curr (int nargs);
  int aclfgl_length (int nargs);
  int acli_scroll (void *s, int n,int m);
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
  char *A4GL_char_pop (void);


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

  int A4GL_gen_field_chars (void ***field_list, void *formdets, ...);
  //int A4GL_set_fields (void *sio);
  void aclfgli_clr_err_flg (void);
  void A4GL_set_option_value (char type, int keyval);
  int aclfgli_get_err_flg (void);
  void A4GLSTK_setCurrentLine (const char *moduleName, int lineNumber);
  void A4GL_clr_fields (int to_defaults,  ...);
  int A4GL_field_name_str_match(char *f1,char *f2);
  int A4GL_chk_iskey (char *base,char *iot, char *keys);
  void A4GL_disp_fields (int n, int attr, ...);

  int A4GL_fgl_getfldbuf (void *inp,char itype, ...);
  void A4GL_set_init (struct BINDING *b, int n);
  int A4GL_req_field (void *s, char itype,char type,...);
  void aclfgli_pr_message (int attr, int wait,int nexpr);
  void A4GL_push_disp_bind (void *b, int n);
  void A4GL_fgl_start (int nargs, char *argv[]);
  void A4GLSTK_initFunctionCallStack (void);
  void A4GL_fgl_end (void);
  void A4GL_system_run (int a);
  void A4GL_push_time (void);
  int A4GL_esql_db_open(int a);
  //double A4GL_pop_double(void);
  /* ======================= API_ui.c ===================== */

//does not A4GL_match actual function definition:
  //int aclfgl_set_page (int nargs);
  //int aclfgl_get_page (int nargs);

  /* ======================= builtin.c  ================== */
  void aclfgli_current (int a, int b);
  void A4GL_push_current (int a, int b);	/* stack.c */
  char *aclfgli_str_to_id (char *name);
  int aclfgl_ascii (int n);
  void A4GL_push_ascii (void);	/* stack.c */
  void acli_interval (char *s, int n);
  int A4GL_ctodt (void *a, void *b, int size);
  int A4GL_ctoint (void *a, void *b, int size);


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
  void A4GL_upshift_stk (void);
  void A4GL_downshift_stk (void);

  /* ======================== datatypes.c ================ */

  int aclfgl_load_datatype (int nargs);


struct BINDING *A4GL_duplicate_binding (struct BINDING *b, int n);
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
    int lines_in_header;
    int lines_in_first_header;
    int lines_in_trailer;
    int print_section;
	char *header;
	int finishing;
	char *repName;
	char *modName;
	int convertable;
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
    int lines_in_header;
    int lines_in_first_header;
    int lines_in_trailer;
    int print_section;
	char *header;
	int finishing;
	char *repName;
	char *modName;
	int convertable;
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

  /*
     DLL building support on win32 hosts;  mostly to workaround their
     ridiculous implementation of data symbol exporting. See exaple in libltdl/
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

#ifdef __cplusplus
}
#endif

#endif				/* #ifndef FGLDEF_INCL */
