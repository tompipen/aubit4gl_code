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
# $Id: a4gl_cint_4gldef.h,v 1.4 2004-09-28 09:49:10 afalout Exp $
*/

/**
 * @file
 *
 THIS FILE IS APPRENTLY A COPY OF incl/a4gl_incl_4gldef.h FILE,
 with a bunch of function prototypes added
 SHOULD WE FIND A WAY TO USE THAT FILE DIRECTLY AND REMOVE THIS FILE?

 We should probably generate the finction prototypes list from .spec
 files using dlmagic script.
 
 *
 */

#ifndef FGLDEF_INCL

#define FGLDEF_INCL

#ifndef __MINGW32__
	//On MinGW causes errors in va_list definition
	#include <stdarg.h>
#endif	

#ifdef __cplusplus

extern "C"
{
#endif
#include <stdio.h> //need for va_list


  typedef struct
  {
    void *ptr;             /**< A pointer to the variable bounded */
    int dtype;             /**< The data type of the variable bounded */
    long size;             /**< The size in bytes of the variable bounded */

    long start_char_subscript;
    long end_char_subscript;
  }
fgl_binding;


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
    long memsize;
		/**< Memory size */
    char filename[256];
    void *ptr;
  };

#define fglbyte struct fgl_int_loc
#define fgltext struct fgl_int_loc

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

#define struct_dtime struct A4GLSQL_dtime
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

#define struct_ival struct ival

	/** 4gl Datetime data type definition */
  typedef struct ival FglInterval;


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
    fgl_binding *group_data;
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
    fgl_binding *group_data;
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
	#define dll_import extern __declspec(dllimport)
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
	extern long quit_flag;					/** 4gl quit ocurred global flag */
#else
	/* only in libaubit4gl */
	dll_export sqlca_struct a4gl_sqlca;	    /** Sqlca variable -- DEFINED WHERE ??? --*/
	long a4gl_status;						/** 4gl global status variable */
	long int_flag;							/** 4gl interrupt ocurred global flag */
	long quit_flag;							/** 4gl quit ocurred global flag */
#endif

/*
On Windows, folowing line is causing:

$ make -C lib libA4GL_cint.dll
make: Entering directory `/usr/src/aubit/aubit4glsrc/lib'
cd ../cint; /usr/bin/bash make_cintlib
################################################################
# makecint : interpreter-compiler for cint (Windows Mingw version)
#
# Copyright(c) 1995~2004 Masaharu Goto (cint@pcroot.cern.ch)
#                        (cint mailing list 'cint@root.cern.ch')
################################################################
makefile is created. Makecint success.
Do 'make -f makefile' to compile the object
d:/cint
make[1]: Entering directory `/usr/src/aubit/aubit4glsrc/cint'
d:/cint/cint  -w1 -zlibA4GL_cint -nG__cpp_libA4GL_cint.C  -D__MAKECINT__ -DG__MA
KECINT -p -c-1 -A  -DG__SHAREDLIB -DG__FIX1 -DG__MINGW -D_WINDOWS -DG__NEWSTDHEA
DER -D_MAX_PATH=512  a4gl_cint_4gldef.h
Error: Too many '}' FILE:a4gl_cint_4gldef.h LINE:431
!!!Removing G__cpp_libA4GL_cint.C G__cpp_libA4GL_cint.h !!!
make[1]: *** [G__cpp_libA4GL_cint.C] Error 1
make[1]: Leaving directory `/usr/src/aubit/aubit4glsrc/cint'
ERROR: failed to create libA4GL_cint.so
make: *** [libA4GL_cint.dll] Error 3
make: Leaving directory `/usr/src/aubit/aubit4glsrc/lib'

*/

//  dll_export sqlca_struct a4gl_sqlca;	    /** Sqlca variable -- DEFINED WHERE ??? --*/

//****
  char *A4GL_char_pop (void);
  void *A4GL_cr_window (char *s, int iswindow, int form_line, int error_line,
			int prompt_line, int menu_line, int border,
			int comment_line, int message_line, int attrib);
  char *A4GL_disp_h_menu (void *menu);
//no longer in API, apprently removed
//  void *A4GL_get_curr_win_gtk (void);
  void *A4GL_get_set (char *str, void *ptr, int mode, char *name, long var);
  void *A4GL_make_pixmap_gw (char *filename);
  void *A4GL_new_menu_create (char *title, int x, int y, int mn_type,
			      int help_no);
  char *aclfgli_str_to_id (char *name);
  void A4GLSQL_set_status (int a, int sql);
  void A4GLSTK_initFunctionCallStack (void);
  void A4GLSTK_pushFunction (const char *functionName, char *params[], int n);
  void A4GLSTK_setCurrentLine (const char *moduleName, int lineNumber);
  int  A4GL_acli_scroll (void *s, int n);
  void A4GL_add_menu_option (void *menu, char *txt, char *keys, char *desc,
			     int helpno, int attr);
  int  A4GL_chk_err (int l, char *module_name);
  int  A4GL_chk_iskey (char *keys);
  void A4GL_close_form (char *name);
  void A4GL_clr_fields (int to_defaults, char *flds, ...);
  void A4GL_clr_form (int to_defaults);
  void A4GL_clr_form_fields (int to_defaults, char *defs);
  void A4GL_clr_window (char *winname);
  int  A4GL_cr_window_form (char *name, int iswindow, int form_line,
			   int error_line, int prompt_line, int menu_line,
			   int border, int comment_line, int message_line,
			   int attrib);
  int  A4GL_ctodt (void *a, void *b, int size);
  int  A4GL_ctoint (void *a, void *b, int size);
  int  A4GL_current_window (char *win_name);
  void A4GL_debug_full (char *fmt, ...);
//Apparently renamed to _v2 
//  int  A4GL_disp_arr (void *disp, void *ptr, char *srecname, int attrib, ...);
  int  A4GL_disp_arr_v2 (void *disp, void *ptr, char *srecname, int attrib, ...);
  int  A4GL_disp_fields (int n, int attr, ...);
  int  A4GL_disp_form (char *name, int attr);
  int  A4GL_disp_form_fields (int n, int attr, char *formname, ...);
  void A4GL_display_at (int n, int a);
  void A4GL_display_error (int attr, int wait);
  void A4GL_downshift_stk (void);
  int  A4GL_endis_fields (int en_dis, ...);
  void A4GL_fgl_end (void);
  int  A4GL_fgl_fieldnametoid (char *f, char *s, int n);
  int  A4GL_fgl_getfldbuf (char *fields, int n, ...);
  int  A4GL_fgl_infield (char *s, int a);
  void A4GL_fgl_start (int nargs, char *argv[]);
  void A4GL_finish_create_menu (void *menu);
//renamed to _v2
//  int  A4GL_form_loop (void *s, int init);
  int  A4GL_form_loop_v2 (void *s, int init);
  int  A4GL_free_menu (void *menu);
  int  A4GL_gen_field_chars (void ***field_list, void *formdets, ...);
  void A4GL_hide_window (char *winname);
  int  A4GL_key_val (char *key);
  int  A4GL_menu_hide (void *menu, ...);
//  int  A4GL_menu_loop (void *menu);
  int  A4GL_menu_loop_v2 (void *menu);
  int  A4GL_menu_show (void *menu, ...);
  int  A4GL_movewin (char *winname, int absol);
  void A4GL_next_option (void *menu, char *nextopt);
  int  A4GL_open_form (char *name);
  int  A4GL_pop_bool (void);
  void A4GL_pop_params (fgl_binding *b, int n);
  int  A4GL_pop_var (void *p, int d);
  int  A4GL_pop_var2 (void *p, int d, int s);
//  int  A4GL_prompt_loop (void *prompt);
  int  A4GL_prompt_loop_v2 (void *prompt);
  void A4GL_push_ascii (void);	/* stack.c */
  void A4GL_push_char (char *p);
  int  A4GL_push_constr (void *s);
  void A4GL_push_current (int a, int b);	/* stack.c */
  void A4GL_push_disp_bind (void *b, int n);
  void A4GL_push_int (int a);
  void A4GL_push_long (long l);
  void A4GL_push_time (void);
  void A4GL_push_variable (void *ptr, int dtype);
  void A4GL_pushop (int a);
  void A4GL_remove_window (char *win_name);
  int  A4GL_req_field (void *s, int size, char *fieldname, int fno);
  int  A4GL_set_fields (void *sio);
//removed from API, but still present in UI plug-ins
//  int  A4GL_set_fields_inp_arr (void *sio);
  void A4GL_set_help_file (char *s);
  void A4GL_set_infield_from_stack (void);
  void A4GL_set_init (fgl_binding * b, int n);
  void A4GL_set_line (char *fname, long lineno);
  void A4GL_set_option_value (char type, int keyval);
  void A4GL_show_window (char *winname);
  void A4GL_sleep_i (void);
  int  A4GL_start_prompt (void *prompt, int ap, int c, int h, int af);
  void A4GL_system_run (int a);
  void A4GL_upshift_stk (void);
  int  aclfgl_a4gl_get_page (int nargs);
  int  aclfgl_a4gl_run_gui (int nargs);
  int  aclfgl_abs (int nargs);
  int  aclfgl_aclfgl_dump_screen (int n);
  int  aclfgl_arg_val (int n);
  int  aclfgl_arr_count (int nargs);
  int  aclfgl_arr_curr (int nargs);
  int  aclfgl_ascii (int n);
  int  aclfgl_date (int nargs);
  int  aclfgl_day (int nargs);
  int  aclfgl_downshift (int _np);
  int  aclfgl_err_get (int statusnumber);
  int  aclfgl_err_print (int statusnumber);
  int  aclfgl_err_quit (int statusnumber);
  int  aclfgl_fgl_drawbox (int n);
  int  aclfgl_fgl_getenv (int nargs);
  int  aclfgl_fgl_keyval (int _np);
  int  aclfgl_fgl_lastkey (int _np);
  int  aclfgl_fgl_prtscr (int n);
  int  aclfgl_hex (int nargs);
  //this function is inside ifdef INCLUDE_USR_FUNCS
  //and not invoked from anywhere: (most other the same)
//  int  aclfgl_i_rowid_s (int arg);
//  int  aclfgl_m_rowid_s (int arg);
//  int  aclfgl_r_rowid_s (int arg);
//  int  aclfgl_s_rowid_s (int arg);
//  int  aclfgl_w_rowid_s (int arg);  
//*****

  int  aclfgl_num_args (int n);
  int  aclfgl_root (int nargs);
  int  aclfgl_mdy (int nargs);
  int  aclfgl_month (int nargs);
  int  aclfgl_length (int nargs);
  int  aclfgl_load_datatype (int nargs);

  int  aclfgl_scr_line (int nargs);
  int  aclfgl_set_count (int nargs);
  int  aclfgl_set_page (int nargs);
  int  aclfgl_showhelp (int helpnumber);
  int  aclfgl_sqrt (int nargs);
  int  aclfgl_upshift (int _np);
  int  aclfgl_weekday (int nargs);
  int  aclfgl_year (int nargs);
  void aclfgli_clr_err_flg (void);
  void aclfgli_current (int a, int b);
  int  aclfgli_get_err_flg (void);
  void aclfgli_pr_message (int attr, int wait);
  void acli_datetime (char *s, int n);
  void acli_interval (char *s, int n);
  char *a4gl_let_substr (char *ca, int dtype, int a, int b, ...);
  char *a4gl_substr (char *s, int dtype, int a, int b, ...);
  void A4GLSTK_popFunction (void);
  short A4GL_pop_int (void);
int A4GL_pop_bool (void);
  short A4GL_pop_int (void);
long A4GL_pop_long (void);
long A4GL_pop_date (void);
float A4GL_pop_float (void);
double A4GL_pop_double (void);
int A4GL_pop_var (void *p, int d);
int A4GL_pop_var2 (void *p, int d, int s);
int A4GL_pop_char (char *z, int size);
int A4GL_pop_param (void *p, int d, int size);
void A4GL_pop_args (int a);
void A4GLSTK_popFunction (void);


#ifdef __cplusplus
}
#endif
#endif				/* #ifndef FGLDEF_INCL */


