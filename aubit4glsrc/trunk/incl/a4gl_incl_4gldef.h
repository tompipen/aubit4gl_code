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
# $Id: a4gl_incl_4gldef.h,v 1.28 2003-02-23 02:32:38 afalout Exp $
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
	struct BINDING {
		void *ptr; /**< A pointer to the variable bounded */
		int dtype; /**< The data type of the variable bounded */
		long size; /**< The size in bytes of the variable bounded */

		long start_char_subscript;
		long end_char_subscript;
	};


	/** SQLCA structure definition */
	typedef struct {
		long sqlcode;
		char sqlerrm[73];
		char sqlerrp[9];
		int sqlerrd[6];
		char sqlawarn[9];
		char sqlstate[10];
	} sqlca_struct;

	/**
	 * Decimal 4gl data type variable definition
	 */
	typedef struct  {
		char data[64]; /**< The value stored in decimal variable */
	} fgldecimal;

	/** This type name is just to have some pattern in type names */
	typedef fgldecimal FglDecimal;

	typedef fgldecimal FglMoney;

	/**
	 * Money 4gl data type variable definition
	 */
	typedef struct  {
		char data[64]; /**< The value stored in money variable */
	} fglmoney;

        struct fgl_int_loc {
          char where;
          FILE *f;
          long memsize; /**< Memory size */
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
	struct A4GLSQL_dtime {
	    int stime;     /**< The start qualifier */
	    int ltime;     /**< The end qualifier */
	    char data[32]; /**< The information in the var */
	};


	/** 4gl Interval data type definition */
	typedef struct A4GLSQL_dtime FglDatetime;

	/**
	 * Interval variable data type.
	 */

	struct ival {
	    int stime;     /**< The start qualifier */
	    int ltime;     /**< The end qualifier */
	    char data[32]; /**< The value of the interval variable */
		int i_years;
		int i_months;
		int i_days;
		int i_hours;
		int i_minutes;
		double i_seconds;
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
assist.c:596: warning: no previous declaration for `aclfgl_field_hide'
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


	int 	aclfgl_set_count 	(int nargs);
	int 	aclfgl_arr_count 	(int nargs);
	int 	aclfgl_scr_line 	(int nargs);
	int 	aclfgl_arr_curr 	(int nargs);
	int     aclfgl_length 		(int nargs);


	int     aclfgl_err_get		(int statusnumber); // CHECK
	int     aclfgl_err_print	(int statusnumber); // THESE SHOULD BE PASSED
	int     aclfgl_err_quit		(int statusnumber); // A NUMBER OF PARAMETERS
	int     aclfgl_startlog 	(char *filename);   // NOT THE PARAMETERS THEMSELVES

#define aclfgl_errorlog(n)  A4GL_errorlog(__FILE__,__LINE__,n);
#define aclfgl_startlog(n)  A4GL_startlog(__FILE__,__LINE__,n);

	//int     aclfgl_errorlog 	(int n);
	int     A4GL_errorlog 		(char *s,int l,int n);
	int     A4GL_startlog 		(char *s,int l,int n);

	int     aclfgl_showhelp 	(int helpnumber);
	int 	aclfgl_fgl_getenv 	(int nargs);
	int		aclfgl_mdy			(int nargs);
	char *	char_pop			(void );


	/* ======================= From buildtin_d.c ====================*/

	int 	aclfgl_date		(int nargs);
	int 	aclfgl_day		(int nargs);
	int 	aclfgl_month	(int nargs);
	int 	aclfgl_year		(int nargs);
	int 	aclfgl_weekday	(int nargs);


	int		aclfgl_hex		(int nargs);
	int		aclfgl_abs		(int nargs);
	int		aclfgl_root		(int nargs);
	int		aclfgl_sqrt		(int nargs);


	/* ============= from assist.4gl/.c ======================= */
	int 	aclfgl_run_gui 	(int nargs);

    /* ============== from curslib.c =========================== */
	int 	aclfgl_fgl_drawbox (int n);
	//void 	aclfgl_fgl_drawbox (int n);

    /* ======================= API_ui.c ===================== */

//does not match actual function definition:
	int     aclfgl_set_page		(int nargs);
	int     aclfgl_get_page		(int nargs);

    /* ======================= builtin.c  ================== */
	void 	aclfgli_current		(int a,int b);
	void 	push_current		(int a, int b); /* stack.c */
	char *	aclfgli_str_to_id	(char *name);
	int 	aclfgl_ascii		(int n);
	void 	push_ascii			(void); /* stack.c */

	//int     aclfgl_set_page		(void);
	//int     aclfgl_get_page		(void);


    /* =================== sql.c ============================ */

	int 	aclfgl_hstmt_get 	(int np);

    /* ====================== extfile.c ===================== */

    int 	aclfgl_fgl_show_help	(int a);

    /* ====================== fglwrap.c ====================== */

	int 	aclfgl_get_ui_mode	(int n);
	int 	aclfgl_num_args		(int n);
	int 	aclfgl_arg_val		(int n);

    /* ======================= helper.c ======================= */

	int 	aclfgl_i_rowid_s	(int arg);
	int 	aclfgl_m_rowid_s	(int arg);
	int 	aclfgl_r_rowid_s	(int arg);
	int 	aclfgl_s_rowid_s	(int arg);
	int 	aclfgl_w_rowid_s	(int arg);
	int 	aclfgl_fgl_prtscr	(int n);
	int		aclfgl_get_info		(int np);

    /* ====================== others.c ======================= */

	int 	aclfgl_fgl_lastkey	(int _np);
	int 	aclfgl_fgl_keyval	(int _np);
	int 	aclfgl_upshift		(int _np);
	int 	aclfgl_downshift	(int _np);

    /* ======================== datatypes.c ================ */

	int aclfgl_load_datatype (int nargs);


	#ifndef REP_STRUCTURE
	#define REP_STRUCTURE
        /* report stuff */
        struct rep_structure {
            int top_margin,bottom_margin,left_margin,right_margin;
            int page_length;
            int has_first_page;
            char *next_page;
            char *rep_table; 					/* database table for aggregate values */
            struct BINDING *group_data;
            char output_mode;
            char output_loc[256];
            char top_of_page[256];
            FILE *output;
            int page_no;
            int printed_page_no;
            int line_no;
            int col_no;
	        int (*report)(int a, int b);
        };

        struct pdf_rep_structure {
            double top_margin,bottom_margin,left_margin,right_margin;
            double page_length;
            double page_width;
            int has_first_page;
            char *next_page;
            char *rep_table; 					/* database table for aggregate values */
            struct BINDING *group_data;
            char output_mode;
            char output_loc[256];
            FILE *output;
            int page_no;
            int printed_page_no;
            double line_no;
            double col_no;
	        int (*report)(int a, int b);
			char font_name[256];
            double font_size;
            int paper_size;
            void *pdf_ptr;
			int font;
        };
	#endif

/*
to fix the _nm_status error (if status is an int) change

extern int status;

to
__attribute__((dllimport))extern int status;

That's the ugly, short-hand way.  For some reason, auto-import
doesn't always work.  Search the mailing lists for more correct
ways of handling this (if you use the same include file to build
your library and in your applications - above should only
be used in applications which link to the library).
*/


    #ifndef _DEFINE_STATUSVARS_  /* set from fglwrap.c --ONLY-- */
	    /* for everything except libaubit4gl: */

		#ifndef _SQLCA_DEFINED_
	        /*
			_SQLCA_DEFINED_ is set in esql.ec to prevent conflict with Informix headers
    	    that also define sqlca:
			*/
			#define _SQLCA_DEFINED_
	    #endif

        extern long status; 			/** 4gl global status variable */
        extern long int_flag;			/** 4gl interrupt ocurred global flag */
        extern long quit_flag; 			/** 4gl quit ocurred global flag */
    #else
		/* only in libaubit4gl */
        sqlca_struct sqlca; 			/** Sqlca variable */
		long status; 					/** 4gl global status variable */
        long int_flag; 					/** 4gl interrupt ocurred global flag */
        long quit_flag;					/** 4gl quit ocurred global flag */
	#endif

#endif /* #ifndef FGLDEF_INCL */
