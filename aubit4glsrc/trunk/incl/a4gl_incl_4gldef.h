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
# $Id: a4gl_incl_4gldef.h,v 1.10 2002-08-31 06:19:59 afalout Exp $
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

	/**
	 * Binding information structure definition.
	 * Used to bind values to and from SQL.
	 * Need to be here because a4gl_API_sql.h needs it
	 */
	struct BINDING {
		void *ptr; /**< A pointer to the variable bounded */
		int dtype; /**< The data type of the variable bounded */
		long size; /**< The size in bytes of the variable bounded */
	};


	/** SQLCA structure definition */
	typedef struct {
		int sqlcode;
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


	#define fglbyte struct fgl_int_loc

	/** 4gl Byte data type */
	typedef struct fgl_int_loc FglByte;

	#define fgltext struct fgl_int_loc

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

	/** Date time defined without typedef. To be deprecated */
	#define struct_dtime struct A4GLSQL_dtime

	/** 4gl Interval data type definition */
	typedef struct A4GLSQL_dtime FglDatetime;

	/**
	 * Interval variable data type.
	 */

	struct ival {
	    int stime;     /**< The start qualifier */
	    int ltime;     /**< The end qualifier */
	    char data[32]; /**< The value of the interval variable */
	};

	#define struct_ival struct ival

	/** 4gl Datetime data type definition */
	typedef struct ival FglInterval;

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
	int     aclfgl_err_get		(int statusnumber);
	int     aclfgl_err_print	(int statusnumber);
	int     aclfgl_err_quit		(int statusnumber);
	int     aclfgl_startlog 	(char *filename);
	int     aclfgl_errorlog 	(char *string);
	int     aclfgl_showhelp 	(int helpnumber);
	int 	aclfgl_fgl_getenv 	(int nargs);
	void    aclfgl_mdy			(void);

	/* ======================= From buildtin_d.c ====================*/

	void 	aclfgl_date		(void);
//	void 	aclfgl_fgl_drawbox(int n);
	int 	aclfgl_day		(void);
	int 	aclfgl_month	(void);
	int 	aclfgl_weekday	(void);
	int 	aclfgl_year		(void);

	void            aclfgl_hex         	(void);
	void            aclfgl_abs         	(void);
	void            aclfgl_root       	(void);
	void            aclfgl_sqrt        	(void);


	/* ============= from assist.4gl/.c ======================= */
	int aclfgl_run_gui (int nargs);

    /* ============== from curslib.c =========================== */
	void aclfgl_fgl_drawbox (int n);

    /* ======================= API_ui.c ===================== */

	int     aclfgl_set_page		(void);
	int     aclfgl_get_page		(void);

    /* =================== sql.c ============================ */

	int aclfgl_hstmt_get (int np);

    /* ====================== extfile.c ===================== */

    int 			aclfgl_fgl_show_help	(int a);

    /* ====================== fglwrap.c ====================== */

	int 			aclfgl_get_ui_mode	(void);
	int 			aclfgl_num_args		(int n);
	int 			aclfgl_arg_val		(int n);

    /* ======================= helper.c ======================= */

	int 		aclfgl_i_rowid_s	(int arg);
	int 		aclfgl_m_rowid_s	(int arg);
	int 		aclfgl_r_rowid_s	(int arg);
	int 		aclfgl_s_rowid_s	(int arg);
	int 		aclfgl_w_rowid_s	(int arg);
	int 		aclfgl_fgl_prtscr	(int n);
	int			aclfgl_get_info		(int np);

    /* ====================== others.c ======================= */

	int 		aclfgl_fgl_lastkey	(int _np);
	int 		aclfgl_fgl_keyval	(int _np);
	int 		aclfgl_upshift		(int _np);
	int 		aclfgl_downshift	(int _np);

    /* ======================== datatypes.c ================ */

	int aclfgl_load_datatype (int nargs);


#endif /* #ifndef FGLDEF_INCL */
