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
# $Id: a4gl_libaubit4gl.h,v 1.41 2003-03-28 08:07:18 mikeaubury Exp $
#
*/

/**
 * @file
 *
 * Definition of structures and typedefs necessary for the libaubit4gl library
 * and commony used in most of Aubit code.
 *
 * This file is included from all API header files, all executables (compilers,
 * tools) - therefore from most if not all Aubit compiler code.
 * It is NOT included from Aubit compiler (4glc) generated c code.
 *
 * Definitipns EXTERNAL to library (needed outside of it) an used in
 * most of Aubit compielr code and compiler 4gl programs.
 * libaubit4gl.so/dll specific definitions are in a4gl_libaubit4gl_int.h
 * which will also include this file.
 *
 * See diagram of Aubit header includes in the documentation.
 *
 */

#ifndef _AUBIT_LIB_INCL_EXT_
#define _AUBIT_LIB_INCL_EXT_

 /*
=====================================================================
                    Constants definitions
=====================================================================
*/

	#if (defined(__CYGWIN__))
		/* we do not want code to behave as native Windows code if we are
        compiling under CygWin environment, since CygWin is essentially
        UNIX-like environment. When you see ifdef WIN32 in Aubit code, this
        applies ONLY to Windows native compilers, like MingWin, MSVC or
		Borland */
		#undef WIN32

		/* missing from rpcgen generated form_x.h on CygWin: */
		#define bool_t int
		#define u_int unsigned int

//remove        #define __NEED_DLL_IMPORT__

	#endif

    /* if WIN32 is still defined, that means that __CYGWIN__was not defined */
	#if (defined(WIN32) && ! defined(__CYGWIN__) && ! defined(__MINGW32__))
		#define __NATIVE_WINDOWS__

		int strncasecmp(char *a,char *b,int c);
    #endif

	#if defined(__MINGW32__)
   		#undef WIN32

   		//#define assert("inside __MINGW32__" == 0)

		#if defined(WIN32)
		//#if (defined(WIN32) && ! defined(__CYGWIN__))
	   		#define assert("inside W32 defined" == 0)
        #endif

		/* missing from rpcgen generated form_x.h on CygWin: */
		#define bool_t int

//remove        #define __NEED_DLL_IMPORT__

		/*
		#define __WIN32__ 1
		#define __GNUC__ 3
		#define __VERSION__ "3.2 (mingw special 20020817-1)"
        */
    #endif

	#if (defined(__MACH__) && defined(__APPLE__))

        #define __DARWIN__

		#define bool_t int
		///usr/include/rpc/auth.h:105: undefined type, found `XDR'
        //#include "rpc/xdr.h"
		#define	enum_t	int

    #endif

		/*
		DLL building support on win32 hosts;  mostly to workaround their
		ridiculous implementation of data symbol exporting. See exaple in libltdl/
		*/

//remove
/*
    #ifdef __NEED_DLL_IMPORT__
		#define dll_export __declspec(dllexport)
		#define dll_import extern __declspec(dllimport) // for complex vars that can't be auto imported
	#else
		#define dll_export
		#define dll_import extern
	#endif
*/


    /* ======================= from a4gl_constats.h ================== */

	#define ATTRIB_AUTONEXT 			1
	#define ATTRIB_INVISIBLE 			2
	#define ATTRIB_NOENTRY 				4
	#define ATTRIB_REQUIRED 			8
	#define ATTRIB_REVERSE 				16
	#define ATTRIB_UPSHIFT 				32
	#define ATTRIB_DOWNSHIFT 			64
	#define ATTRIB_VERIFY 				128
	#define ATTRIB_WORDWRAP 			256
	#define ATTRIB_COLOUR 				512

	#define MODE_INPUT 					1
	#define MODE_INPUT_WITHOUT_DEFAULTS 2
	#define MODE_CONSTRUCT 				3
	#define MODE_DISPLAY_ARRAY 			4
	#define MODE_PROMPT 				5
	#define MODE_INPUT_ARRAY 			6

	#define FETCH_ABSOLUTE 				1
	#define FETCH_RELATIVE 				2

	#define NO 							(void *)0
	#define FGL_OK 						(void *)1
	#define DIGIT_ALIGN_RIGHT 			1
	#define NUM_PARAM 					30
	#define DATE_INVALID 				0
	#define MAXDIG 						30

    /* ===================== from a4gl_dates.h ======================== */

	#define	THURSDAY					4		/* for reformation */
	#define	SATURDAY 					6		/* 1 Jan 1 was a Saturday */
	#define	FIRST_MISSING_DAY 			639787	/* 3 Sep 1752 */
	#define	NUMBER_MISSING_DAYS 		11		/* 11 day correction */
	#define	MAXDAYS						42		/* max slots in a month array */
	#define	SPACE						-1		/* used in day array */
	#define EPOCH 						693608

	/* ======================== from a4gl_aubitcolours.h ========== */
	#define AUBIT_COLOR_BLACK     		0x00000
	#define AUBIT_COLOR_RED       		0x00100
	#define AUBIT_COLOR_GREEN     		0x00200
	#define AUBIT_COLOR_YELLOW    		0x00300
	#define AUBIT_COLOR_BLUE      		0x00400
	#define AUBIT_COLOR_MAGENTA   		0x00500
	#define AUBIT_COLOR_CYAN      		0x00600
	#define AUBIT_COLOR_WHITE     		0x00700

	#define AUBIT_ATTR_NORMAL     		0x00800
	#define AUBIT_ATTR_REVERSE    		0x01000
	#define AUBIT_ATTR_UNDERLINE  		0x02000
	#define AUBIT_ATTR_BOLD       		0x04000
	#define AUBIT_ATTR_BLINK      		0x08000
	#define AUBIT_ATTR_DIM        		0x10000

    /* ====================== from a4gl_errors.h ================== */
	#define ERR_BADNOARGS 		1000
	#define ABORT 				1
	#define WARN 				2

	#define WHEN_CONTINUE 		0
	#define WHEN_STOP 			1
	#define WHEN_CALL 			2
	#define WHEN_GOTO 			3
	#define WHEN_NOTSET 		4
	#define WHEN_ERROR 			16
	#define WHEN_ANYERROR 		32
	#define WHEN_SQLERROR 		64
	#define WHEN_WARNING 		128
	#define WHEN_SQLWARNING		256
	#define WHEN_NOTFOUND 		512
	#define WHEN_SUCCESS 		1024
	#define WHEN_SQLSUCCESS 	2048

	#define A_WHEN_ERROR 		0
	#define A_WHEN_ANYERROR 	1
	#define A_WHEN_SQLERROR 	2
	#define A_WHEN_WARNING 		3
	#define A_WHEN_SQLWARNING	4
	#define A_WHEN_NOTFOUND 	5
	#define A_WHEN_SUCCESS	 	6
	#define A_WHEN_SQLSUCCESS   7

    /* =================== from a4gl_shockhelp.h ====================*/

	/* On some crazy systems, these aren't defined. */
	#ifndef EXIT_FAILURE
		#define EXIT_FAILURE 1
	#endif

	#ifndef EXIT_SUCCESS
		#define EXIT_SUCCESS 0
	#endif

    /* ======================== from a4gl_match.h ================= */

	#define CONSTR_SEP '\t'
	#define like(s1,s2) mja_match(s1,s2,'L');
	#define matches(s1,s2) mja_match(s1,s2,'M');

    /* ========================= from a4gl_keys.h ================== */
	#define A4GLKEY_ENTER 	0xff01
	#define A4GLKEY_DOWN 	0xff02
	#define A4GLKEY_UP 		0xff03
	#define A4GLKEY_LEFT 	0xff04
	#define A4GLKEY_RIGHT 	0xff05
	#define A4GLKEY_PGUP 	0xff06
	#define A4GLKEY_PGDN 	0xff07
	#define A4GLKEY_INS 	0xff08
	#define A4GLKEY_DEL 	0xff09
	#define A4GLKEY_HOME 	0xff0a
	#define A4GLKEY_END 	0xff0b
	#define A4GLKEY_CANCEL 	0xfffe
	#define A4GLKEY_F(x) 	(0xff10+x)

    /* ========================= from a4gl_tunable.h ================ */

	#define MAXLEN 			80
	#define MAXWIDTH 		256
	#define MAXTAGS 		256
	#define TAGSIZE 		100
	#define MAXSCREENS 		10
	#define MAXFIELDS 		256
	#define NUMTABS 		100
	#define BIGBUFF 		1024
	#define TABLESIZE 		32
	#define COLUMNSIZE 		32
	#define NUMALIAS 		32
	#define DBSIZE 			32
	#define SMALLSTRING 	32
	#define BIGSTRING 		256
	#define FNAMESIZE 		64
	#define MAXSCREENRECS 	32
	#define MAXCONSTANTS 	1024

    /* ========================== from a4gl_pointers.h =============== */
	#define PANCODE 		'1'
	#define WINCODE 		'2'
	#define CURCODE 		'3'
	#define PRECODE 		'4'
	#define MNWINCODE 		'5'
	#define MNPARCODE 		'6'
	#define FORMCODE 		'7'
	#define S_WINDOWSCODE 	'8'
	#define S_FORMDETSCODE 	'9'
	#define SESSCODE 		'A'
	#define RPC_FUNC 		'B'
	#define ATTRIBUTE 		'C'
	#define DROPSHADOW 		'D'
	#define COMPILED_FORM 	'E'
	#define MESSAGEWIN 		'F'
	#define PTR_ATTRIBUTE 		'G'

	/* ========================= from a4gl_ui.h ====================== */
	#define DESCLENGTH 		10
	#define nalloc(x) 		malloc(sizeof(x))
	#define INVERT 			1
	#define NORM 			0
	#define BS 				KEY_BACKSPACE
	#define FORMFEED 		12
	#define gotoxy(x,y) 	mja_gotoxy(x,y)
	#define CR 				13
	#define ESC 			27
	#define HOMEKEY 		KEY_HOME
	#define ENDKEY 			KEY_END
	#define UPKEY 			KEY_UP
	#define DOWNKEY 		KEY_DOWN
	#define PGUPKEY 		KEY_PPAGE
	#define PGDNKEY 		KEY_NPAGE
	#define LEFTKEY 		KEY_LEFT
	#define INSKEY 			KEY_IC
	#define RIGHTKEY 		KEY_RIGHT
	#define DELKEY 			KEY_BACKSPACE
	#define F1 				KEY_F(1)
	#define F2 				KEY_F(2)
	#define F3 				KEY_F(3)
	#define F4 				KEY_F(4)
	#define F5 				KEY_F(5)
	#define F6 				KEY_F(6)
	#define F7 				KEY_F(7)
	#define F8 				KEY_F(8)
	#define F9 				KEY_F(9)
	#define F10 			KEY_F(10)
	#define F11 			KEY_F(11)
	#define F12 			KEY_F(12)
	#define MENU_ALL 		"_AlL_"
	/* Datasave */
	#define DATAVER 		1

	#define NOTFOUND 		1
	#define WRONGVER 		2
	#define BADFILE 		3
	#define NOWRITE 		4
	#define BADWRITE 		5

	#define STREQL(a,b) 	(strcmp(a,b)==0)
	#define STRNEQ(a,b) 	(strcmp(a,b)!=0)
	#define STRIEQ(a,b) 	(strcasecmp(a,b)==0)
	#define STRINEQ(a,b) 	(strcasecmp(a,b)!=0)

	#define RES_PANEL 		1
	#define RES_ACLWINDOW 	2
	#define RES_CURSWINDOW 	3
	#define RES_ACLFORM 	4

	#define getptr_PANEL(b) 		(PANEL *)find_pointer(b,RES_PANEL)
	#define getptr_s_windows(b) 	(struct s_windows *)find_pointer(b,RES_ACLWINDOW)
	#define getptr_WINDOW(b) 		(WINDOW *)find_pointer(b,RES_CURSWINDOW)
	#define getptr_s_form_dets(b) 	(struct s_form_dets *)find_pointer(b,RES_ACLFORM)

	#define pushptr_PANEL(b,p)      	add_pointer(b,RES_PANEL,p)
	#define pushptr_s_windows(b,p)   	add_pointer(b,RES_ACLWINDOW,p)
	#define pushptr_WIN(b,p)         	add_pointer(b,RES_CURSWINDOW,p)
	#define pushptr_s_form_dets(b,p) 	add_pointer(b,RES_ACLFORM,p)


	/* available only to this library */
	#define LIBPRIVATE 		static

	/* available to other files in the library */
	#define LIBUSEONLY
	#define LIBEXPORT

	/* available to 4gl */
	#define LIBINTERFACE
	#define PANCODE 		'1'
	#define WINCODE 		'2'


	/* ========================= from a4gl_ui.h ====================== */
	#define IDENTLEN 		18;
	#define ACL_MN_SHOW 	0x0000
	#define ACL_MN_HIDE 	0x0001
	#define A_BORDER 		0x400
	#define wchk() if (a4gl_sqlca.sqlcode<0) werror_hand(__FILE__,__LINE__)


    /* ==================== from incl_4glhdr.h =========================*/
	#define fglerror(a,b) 			fgl_error(__LINE__,__FILE__,a,b)
	#define AFT_FIELD_CHK(zzz,xxx) 	(_fld_dr==-98&&strcmp(fldname,zzz)==0)
	#define BEF_FIELD_CHK(zzz,xxx) 	(_fld_dr==-97&&strcmp(fldname,zzz)==0)
	#define BEF_DELETE  			(_fld_dr==-12)
	#define AFT_DELETE  			(_fld_dr==-13)
	#define BEF_INSERT  			(_fld_dr==-14)
	#define AFT_INSERT  			(_fld_dr==-15)
	#define BEF_ROW 				(_fld_dr==-10)
	#define AFT_ROW  				(_fld_dr==-11)
	#define BEFORE_INP  			(_fld_dr==-99)
	#define AFTER_INP  				(_fld_dr==-95)
	#define ON_KEY(zzz) 			if (_fld_dr==-90&&chk_iskey(zzz))
	#define set_status(a) 			set_status(a,0)

	/* ========================== from a4gl_dtypes.h ==================== */
	#define DTYPE_CHAR      0
	#define DTYPE_SMINT     1
	#define DTYPE_INT       2
	#define DTYPE_FLOAT     3
	#define DTYPE_SMFLOAT   4
	#define DTYPE_DECIMAL   5
	#define DTYPE_SERIAL    6
	#define DTYPE_DATE      7
	#define DTYPE_MONEY     8
	#define DTYPE_DTIME     10
	#define DTYPE_BYTE      11
	#define DTYPE_TEXT      12
	#define DTYPE_VCHAR     13
	#define DTYPE_INTERVAL  14
	#define DTYPE_MASK 		255 /* bit pattern for data type */
	#define DTYPE_MALLOCED 	256

	#define MAX_DTYPE  		255
	#define MAXDIG 			30
	#define MAXPNT 			30

/*
=====================================================================
		               System Includes
=====================================================================
*/

	#ifdef HAVE_CONFIG_H
		/* header automatically created with AutoConf-configure */
		#include "a4gl_incl_config.h"
	#endif

	#if defined(WIN32) || defined (__MINGW32__)
		#ifndef _NO_WINDOWS_H_
			#include <windows.h>
			#define __UCHAR_DEFINED__
		#endif
	#else /* UNIX */
		#include <pwd.h>    		/* getpwduid() */
		#include <sys/socket.h>
		#include <netinet/in.h>
		#include <netdb.h>
	#endif

	#include <stdarg.h>  			/* va_start() */
   	#include <ctype.h> 				/* tolower() toupper() */
	#include <stdio.h> 				/* needed for FILE symbol */
	#ifndef WIN32
		#include <string.h>
    #endif
	#include <stdlib.h> 			/* free() */

	#if HAVE_SEARCH_H
		#include <search.h> 		/* VISIT-used in pointers.c */
    #else
		/* For tsearch */
		typedef enum
		{
		  preorder,
		  postorder,
		  endorder,
		  leaf
		}
		VISIT;
    #endif

	#include <assert.h>             /* assert() */
	#include <time.h>
	#include <math.h> 				/* pow() */
	#include <locale.h>             /* setlocale() */
	#include <unistd.h> 			/* sleep() close() write() usleep() */
	#include <signal.h>             /* SIGINT */

	
	/*
    skipposixheaders flag:
	to force LCLint to process <sys/types.h>, since form_x.h will include
    rpc.h that needs fd_set. included via /usr/include/sys/types.h but
	defined in /usr/include/sys/select.h
	 */

	/*@-skipposixheaders@*/
	#include <sys/types.h>
	/*@=skipposixheaders@*/

	/*
	   This will prevent ussage of getenv and wgetenv functions:
	   You could also enforce the prohibition of other undesirable C
	   functions, with gets() and strtok() springing to mind as the first
	   candidates, but there are likely to be others too.

		This would cause compile-time error if getenv() is used:
		#define getenv(s)	assert("Do not use getenv()" == 0)
		like this:
		/usr/include/stdlib.h:587: parse error before string constant

		 This will also cause compile time error (prefered)
        #define getenv(s) do not use getenv() - use acl_getenv() instead
            ...but it will not work for Splint so we must use assert one

        Must be after system includes, because stdlib.h sefines getenv()
	*/

	#ifndef GETENV_OK
		#define getenv(s)	assert("Do not use getenv() - use acl_getenv() instead" == 0)
	#endif

	#ifndef WGETENV_OK
		#define wgetenv(s)	assert("Do not use wgetenv() - use acl_getenv() instead" == 0)
	#endif


	/* if not defined in system provided includes: */
	#ifndef BOOLEAN
		#define BOOLEAN 	int
    #endif
	#ifndef TRUE
		#define TRUE 		1
    #endif
	#ifndef FALSE
		#define FALSE 		0
	#endif


/*
=====================================================================
		               Aubit Includes
=====================================================================
*/

	/* definitions used both in Aubit compiler code and at run-time */
	#include "a4gl_incl_4gldef.h"

	/* API prototypes */
	#include "a4gl_API_lex.h"          	/* generated from .spec */
	#include "a4gl_API_form.h"          /* generated from .spec */
	#include "a4gl_API_menu.h"          /* generated from .spec */
	#include "a4gl_API_msg.h"           /* generated from .spec */
	#include "a4gl_API_packer.h"        /* generated from .spec */
    #include "a4gl_API_exdata.h"        /* created manually */
	#include "a4gl_API_ui.h"            /* created manually */
	#include "a4gl_API_exreport.h"    	/* created manually */
	#include "a4gl_API_sql.h"           /* created manually */
	#include "a4gl_API_rpc.h"         	/* created manually */

	#ifndef _NO_FORM_X_H_
		#include "../common/dataio/form_x.x.h"   /* struct_form */
    #endif


/*
=====================================================================
                    Variables definitions
=====================================================================
*/

	/* ========================= from a4gl_ui.h ====================== */

	typedef struct	{
	  int 		code;
	  struct 	int_list *next_option;
	}
	int_list;

	typedef struct ACL_Menu_Opts {
	    char 	opt_title[80];
	    char 	optkey[80];
	    int 	optlength;
	    int 	opt_no;
	    int 	help_no;
	    int 	optpos;
	    int 	attributes;
	    char 	shorthelp[80];
	    struct 	ACL_Menu_Opts *next_option;
	    struct 	ACL_Menu_Opts *prev_option;
	    int 	page;
	}
	ACL_Menu_Opts;

	typedef struct {
	    char 			menu_title[80];
	    int 			menu_type;
	    char 			window_name[20];
	    ACL_Menu_Opts *	curr_option;
	    int 			menu_offset;
	    int 			mn_offset;
	    int 			x;
	    int 			y;
	    int 			help_no;
	    int 			num_opts;
	    int 			abort_pressed;
	    ACL_Menu_Opts *	first;
	    ACL_Menu_Opts *	last;	/* used for wrapping round */
	    void *			menu_win;
	    int 			curr_page;
	    int 			max_page;
	    int 			w;
	    int 			menu_line;
	    int 			attrib;
	}
	ACL_Menu;

	typedef struct  {
		int 	x,y;
		int 	length;
		struct 	field_geometry *field_up;
		struct 	field_geometry *field_down;
		struct 	field_geometry *field_left;
		struct 	field_geometry *field_right;
		struct 	field_geometry *field_next;
		struct 	field_geometry *field_previous;
		struct 	gen_field *master;
	}
	field_geometry;

	typedef struct {
		char 				colname[19];
		char 				tabname[19];
		int 				length;
		int 				x,y;
		int 				data_type;
		int 				attributes; 		/*color etc.*/
		int 				field_attributes; 	/*autonext etc.*/
		char 				tag[19];
		field_geometry *	fields_list;
	} 
	gen_field;

	typedef struct {
		int 	x,y,width,height;
		char 	form_name[19];
	} 
	gen_form;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

	void 	init_menu 		(void);			/*initialize menu structure */
	int 	disp_menu 		(char *str, int x,int y);	/* display a menu with title 'str' at position y */
	void 	banner 			(char str[], int a, int b, int c);
	void 	title_box 		(char str[], int a, int x, int l);
	void 	error_box		(char *str);	/*print error message */

	/* from curslib.c: */
	void 	disp_opt 		(int row, int x, int y, int l, int type);
	int 	do_key_menu 	(void);			/*internal function */
	void 	do_pause 		(void);			/*waits for a key press */
	int 	edit 			(char *string, char type, int length, int x, int y);
	int 	check_type 		(char c, char type, int flg, int len);
	int 	ask_int 		(char *prompt);	/*  prompt for an integer from user  */
	double 	ask_dbl 		(char *prompt);	/*  prompt for an integer from user  */
	int 	ask_verify 		(char *prompt);	/*  prompt for verification  */
	unsigned int getcursor 	(void);			/* Returns the shape of the current cursor */
	void    strip_nl 		(char *str);

	ACL_Menu * new_menu 	(char *title,int x, int y,int mn_type, int help_no, int nopts,va_list *ap);

	struct text_info
	  {
	    unsigned char winleft;
	    unsigned char wintop;
	    unsigned char winright;
	    unsigned char winbottom;
	    unsigned char attribute;
	    unsigned char normattr;
	    unsigned char currmode;
	    unsigned char screenheight;
	    unsigned char screenwidth;
	    unsigned char curx;
	    unsigned char cury;
	  };

	typedef struct {
		int code;
		char *desc;
		int color_attrib;
		int attrib;
	} attributes;

	enum box_styles
	  {
	    NORMAL_BOX,
	    BORDER_BOX
	  };

	enum color_codes
	  {
	    NORMAL_TEXT,
	    ERROR_COL,
	    MESSAGE,
	    NORMAL_MENU,
	    INVERT_MENU,
	    TITLE_COL,
	    EDIT_FIELD
	  };

	enum menu_types
	  {
	    ACL_MN_VERTICAL,
	    ACL_MN_HORIZ_BOXED,
	    ACL_MN_HORIZ_NOTBOXED
	  };


	void *	create_blank_window (char *name, int x, int y, int w, int h, int border);
	char * 	glob_window 		(int x, int y, int w, int h, int border);
	void * 	find_pointer 		(const char *pname, char t);

	/* OBJECTMODULE is defined ONLY in keys.c */
	#ifdef OBJECTMODULE
		char 				opts[100][80];			/*menu options */
		int 				abort_pressed;
		int 				relxedit = 0, relyedit = 0;
		int 				aborted;
		long 				time_offset = 0;
		int 				week_no = -1;
		struct 				s_form_attr std_dbscr;
	#else
		extern char 		opts[10][80];	/*menu options */
		extern int 			abort_pressed;
		extern int 			relxedit, relyedit;
		extern int 			aborted;
		extern long 		time_offset;
		extern int 			week_no;
		dll_import struct 	s_form_attr std_dbscr;
	#endif


    /* ======================== from debug.h ========================*/


	void 	debug_full 		(char *fmt,...);
	void 	exitwith_sql	(char *s) ;
	void 	set_errm		(char *s);

    /* in debug.c */
	void 			setarg0	(const char *argv0);
	const char * 	getarg0	(void);

    /* ========================== from a4gl_dtypes.h ==================== */

		struct s_typenames {
			char *name;
			int dtype;
			int noentry;
			int blank;
		};

		#ifdef IO
			struct s_typenames def_dtypes[]= {
			{"char",DTYPE_CHAR,0,0},
			{"integer",DTYPE_INT,0,1},
			{"float",DTYPE_FLOAT,0,1},
			{"smallfloat",DTYPE_SMFLOAT,0,1},
			{"decimal",DTYPE_DECIMAL,0,1},
			{"serial",DTYPE_SERIAL,0,1},
			{"date",DTYPE_DATE,0,0},
			{"money",DTYPE_MONEY,0,1},
			{"datetime",DTYPE_DTIME,0,0},
			{"byte",DTYPE_BYTE,2,0},
			{"text",DTYPE_TEXT,2,0},
			{"varchar",DTYPE_VCHAR,0,0},
			{"interval",DTYPE_INTERVAL,0,0},
			{0,0,0,0}
			};
		#else
			extern struct s_typenames def_dtypes[];
		#endif


    /* ==================== from incl_4glhdr.h =========================*/

	/* not strictly voids - but saves getting into the details */
	void *	prepare_glob_sql 	(char *s,int ni,void *b);

	#define DEF_ASS(uass,d) char * uass[d]={(char *)-1}

	#define OP_MASK 		512|1024
	#define OP_MASK_BASE 	512

	#define NUMERIC_OP_2  	1*OP_MASK_BASE
	#define STRING_OP_S1 	2*OP_MASK_BASE
	#define STRING_OP_S2 	4*OP_MASK_BASE
	#define STRING_OP_N1 	8*OP_MASK_BASE
	#define STRING_OP_N2 	16*OP_MASK_BASE
	#define FUNCTION_OP 	32*OP_MASK_BASE
	#define BOOLEAN_OP 		64*OP_MASK_BASE
	#define OTHER_OP 		128*OP_MASK_BASE

	/* add no more than 15 items to any of the following groups */
	#define OP_ADD 			1|NUMERIC_OP_2
	#define OP_SUB 			2|NUMERIC_OP_2
	#define OP_MULT 		3|NUMERIC_OP_2
	#define OP_DIV 			4|NUMERIC_OP_2
	#define OP_POWER 		5|NUMERIC_OP_2
	#define OP_MOD 			6|NUMERIC_OP_2

	#define OP_CLIP 		1|STRING_OP_S1
	#define OP_CONCAT 		1|STRING_OP_S2
	#define OP_COPY 		2|STRING_OP_S2
	#define OP_USING 		3|STRING_OP_S2
	#define OP_MATCHES 		4|STRING_OP_S2
	#define OP_LIKE 		5|STRING_OP_S2

	/* This one is a special case and should **NOT** be
	   used anywhere except for grouping others together in stack.c and
	   when processing maths operations.
       Used for add_op_function & find_op_function
	*/

	#define OP_MATH 		12|BOOLEAN_OP

	#define OP_YEAR 		1|STRING_OP_N1
	#define OP_MONTH 		2|STRING_OP_N1
	#define OP_DAY 			3|STRING_OP_N1
	#define OP_HOUR 		4|STRING_OP_N1
	#define OP_MINUTE 		5|STRING_OP_N1
	#define OP_SECOND 		6|STRING_OP_N1

	#define OP_SUBSTR1 		1|STRING_OP_N2
	#define OP_SUBSTR2 		1|STRING_OP_N3

	#define OP_EQUAL 		(1|BOOLEAN_OP)
	#define OP_LESS_THAN 	(2|BOOLEAN_OP)
	#define OP_GREATER_THAN (3|BOOLEAN_OP)
	#define OP_NOT_EQUAL 	(4|BOOLEAN_OP)
	#define OP_LESS_THAN_EQ (5|BOOLEAN_OP)
	#define OP_GREATER_THAN_EQ (6|BOOLEAN_OP)
	#define OP_AND 			(7|BOOLEAN_OP)
	#define OP_OR 			(8|BOOLEAN_OP)
	#define OP_NOT 			(9|BOOLEAN_OP)
	#define OP_ISNULL 		(10|BOOLEAN_OP)
	#define OP_ISNOTNULL 	(11|BOOLEAN_OP)

	#define OP_IN 			(1|OTHER_OP)
	#define OP_NOTIN 		(2|OTHER_OP)
	#define OP_IN_SELECT 	(3|OTHER_OP)
	#define OP_NOTIN_SELECT (4|OTHER_OP)
	#define OP_EXISTS 		(5|OTHER_OP)
	#define OP_NOTEXISTS 	(6|OTHER_OP)

	#define ENCODE_SIZE(x) 	(x<<16)
	#define DECODE_SIZE(x) 	(x>>16)

	char *	new_string		(int a);
	int 	pop_bool		(void);
	short 	pop_int			(void);
	long 	pop_long		(void);
	long 	pop_date		(void);
	float 	pop_float		(void);
	double 	pop_double		(void);
	int 	pop_var			(void *p,int d) ;
	int 	pop_var2		(void *p,int d,int s) ;
	double 	ret_var			(void *p,int d) ;
	int 	pop_char		(char *z,int size);
	//char *	char_pop		(void);
	int 	pop_param		(void *p,int d,int size);
	void 	pop_params		(struct BINDING *b,int n);
	void 	push_param		(void *p,int d);
	void 	push_params 	(struct BINDING *b, int n);
	void 	push_user		(void);
	void 	push_today		(void);
	int 	opboolean		(void);
	void 	pop_args		(int a);
	void 	debug_print_stack(void);
	void 	print_stack		(void);
	void 	locate_var		(struct fgl_int_loc *p,char where,char *filename);

	#define acl_free(s) acl_free_full(s,__FILE__,__LINE__)
	#define acl_malloc(a,b) acl_malloc_full(a,b,__FILE__,__LINE__)

	#define GETSETNEW 		-1
	#define GETSETRM 		-2
	#define GETSETGET 		1
	#define GETSETSET 		2
	#define GETSETGETPTR 	3

	#define GETPTR(struct,ptr,element) get_set(struct,ptr,GETSETGETPTR,element,0)
	#define GET(struct,ptr,element) get_set(struct,ptr,GETSETGET,element,0)
	#define SET(struct,ptr,element,value) get_set(struct,ptr,GETSETSET,element,(long)value)
	#define NEW(struct) get_set(struct,0,GETSETNEW,0,0)
	#define RM(struct,ptr) get_set(struct,ptr,GETSETRM,0,0)

	/* report stuff */
#ifndef REP_STRUCTURE
#define REP_STRUCTURE
	struct rep_structure {
	    int top_margin,bottom_margin,left_margin,right_margin;
	    int page_length;
	    int has_first_page;
	    char *next_page;
	    char *rep_table; /* database table for aggregate values */
	    struct BINDING *group_data;
	    char output_mode;
	    char output_loc[256];
	    char top_of_page[256];
	    FILE *output;
	    int page_no;
	    int printed_page_no;
	    int line_no;
	    int col_no;
		/* was 	    int (*report)(); */
		/* int (*report)(void); */ /* report.c:180: too many arguments to function */
        int (*report)(int a, int b);
	};
	struct pdf_rep_structure {
	    double top_margin,bottom_margin,left_margin,right_margin;
	    double page_length;
	    double page_width;
	    int has_first_page;
	    char *next_page;
	    char *rep_table; /* database table for aggregate values */
	    struct BINDING *group_data;
	    char output_mode;
	    char output_loc[256];
	    FILE *output;
	    int page_no;
	    int printed_page_no;
	    double line_no;
	    double col_no;
		/* was 	    int (*report)(); */
		/* int (*report)(void); */ /* report.c:180: too many arguments to function */
        int (*report)(int a, int b);
		char font_name[256];
	    double font_size;
	    int paper_size;
	    void *pdf_ptr;
	   int font;
	};

#endif
	double 	pdf_size		(double f, char c,struct pdf_rep_structure *p);

	#define REP_TYPE_PDF 			1
	#define REP_TYPE_NORMAL 		2
	#define REPORT_START 			-1
	#define REPORT_FINISH 			-2
	#define REPORT_DATA 			-3
	#define REPORT_OPS_COMPLETE 	-4
	#define REPORT_AFTERDATA 		-5
	#define REPORT_SENDDATA 		-6
	#define REPORT_BEFOREDATA 		-7
	#define REPORT_BEFOREGROUP 		-8
	#define REPORT_AFTERGROUP 		-9
	#define REPORT_LASTROW 			-10
	#define REPORT_PAGEHEADER 		-11
	#define REPORT_FIRSTPAGEHEADER 	-12
	#define REPORT_LASTDATA 		-13
	#define REPORT_PAGETRAILER 		-14
	#define ERR_BADNOARGS 			1000
	#define ABORT 					1
	#define WARN 					2

	#ifndef NODEBUG
		int set_line(char *s,long l);
		#define debug set_line(__FILE__,__LINE__);debug_full
	#else
		#define debug null_func
	#endif

    /* ====================== from data_if.c =================== */

   	void * get_set(char *str,void *ptr,int mode,char *name,long var);


    /* ===================== from builtin.c =================== */

	int     fgl_fieldtouched	(char *fieldname);
	void    close_database		(void);
	char * 	let_substr 			(char *ca, int dtype, int a, int b,...);
	char *	substr				(char *s,int dtype,int a,int b,...);
	void	include_builtin_in_exe(void);
	void 	set_scr_line 		(int a);
	void 	set_arr_curr 		(int a);
	int 	get_count 			(void);
	void    set_arr_count 		(int a);
	int aclfgl_dbms_dialect(void);
	void aclfgli_extend(void) ;


	/* ======================= From buildtin_d.c ====================*/

	void 	push_dtime		(struct A4GLSQL_dtime *p);
	void 	push_int		(int p);
	void 	push_long		(long p);
	void 	push_date		(long p);
	void 	push_float		(float p);
	void 	push_dec		(char *p,int ismoney);
	void 	push_double		(double p);
	void 	push_chars		(char * p,int dtype,int size);
	void 	push_char		(char * p);
	void 	push_variable	(void *ptr,int dtype);
	void 	push_interval	(struct ival *p);

	int 	func_clip		(void);
	void 	func_concat		(void);
	void 	func_using		(void);
	int 	find_function	(char *a);
	double 	power			(double a,double b);

	/* ============================ resource.c ============================= */
	struct str_resource
	  {
	    char name[20];
	    char value[1024]; //must be long enough to hold GTK include paths
	  };

	char * 	find_str_resource_int	(char *search, int a);
	struct 	str_resource * build_user_resources(void);
	int 	env_option_set			(char *s);
	char*	acl_getenv 				(char *);


	/* ========================== gui_io.c ================================= */
	void 	gui_scrollpos		(int a);
	void 	gui_scroll			(int a);
	void 	gui_error			(char *txt,int errline);
	void 	gui_endform			(void);
	void    gui_currwin			(long a);
	void    gui_wrefresh		(void *d);
	void    gui_print 			(int a,char *fmt,...);
	void    gui_dispform		(char *s,int line);
	void 	gui_setcolor		(int a);
	void    gui_refresh			(void);
	void    gui_move			(int x,int y);
	void    gui_closewin		(char *name);
	void    gui_win				(char *name,int h,int w,int y,int x,int b,long d);
	void    gui_setposition		(long ld);
	void    gui_setbuff			(void *a,char *n);
	void    gui_mkfield			(int h,int w,int y,int x,void *p);
	void    gui_setfocus		(long ld);
	void    gui_setattr			(long a,int f,int b);
	void    gui_mklabel			(int h,int w,int y,int x,char *s);
	void    gui_startform		(char *name);
	void    gui_endmenu			(long ld);
	void    gui_menuopt			(char *title,long id);
	void    gui_message			(char *txt,int msgline);
	void    gui_rmmenu			(long ld);
	void    gui_endprompt		(long ld);
	void    gui_startprompt		(long ld);

	/* ========================== funcs_d.c ================================ */
	void 	trim				(char *p);
	void 	bnamexxx			(char *str,char *str1,char *str2);
	void 	pad_string			(char *ptr,int size);
	void * 	acl_malloc_full		(int size,char *why,char *f,long line);
	void 	acl_free_full		(void *ptr,char *f,long line);
	void	using				(char *str,int s,char *fmt,double num);
	int     digittoc			(int *a,char *z,char *fmt,int dtype,int size);


	/* =========================== dates.c ================================= */
	long 	gen_dateno			(int day,int month,int year);
	int 	get_date			(int d,int *day,int *mn,int *yr);
	int		day_in_week 		(int, int, int);
	int     modify_year			(int a);
	int 	date_sep			(int z);

 	/* ============================ dmy.c ================================== */
 
 	char *		using_date		(int dn,char *us);
 	char *		dbdate_to_using	(char *dbdate);
 	char *		get_dbdate		(void);
 

	/* =========================== string.c ================================ */
	char *	new_string_set		(int a,char *b);
	void 	string_set			(char *ptr,char *b,int size);
	int 	mja_strncmp 		(char *str1, char *str2, int n);


	/* ============================ error.c ================================ */
	void 	exitwith			(char *s);
	void 	set_error 			(char *fmt,...);

    /* ============================ from a4gl_stack.h =================*/

	#define OP_MASK 		512|1024
	#define OP_MASK_BASE 	512

	/* add no more than 15 items to any of the following groups */

	#define OP_IN 			(1|OTHER_OP)
	#define OP_NOTIN 		(2|OTHER_OP)
	#define OP_IN_SELECT 	(3|OTHER_OP)
	#define OP_NOTIN_SELECT (4|OTHER_OP)
	#define OP_EXISTS 		(5|OTHER_OP)
	#define OP_NOTEXISTS 	(6|OTHER_OP)


	#define ENCODE_SIZE(x) (x<<16)
	#define DECODE_SIZE(x) (x>>16)

	#define fglbyte struct fgl_int_loc
	#define fgltext struct fgl_int_loc
	
	#define acl_free(s) acl_free_full(s,__FILE__,__LINE__)
	#define acl_malloc(a,b) acl_malloc_full(a,b,__FILE__,__LINE__)



	void 	pushop 				(int a);
	char *	params_on_stack 	(char *_paramnames[],int n);
	int 	isnull 				(int type, char *buff);
	void 	setnull 			(int type, char *buff, int size);
	char *	lrtrim				(char *z) ;
	void 	get_top_of_stack 	(int a, int *d, int *s, void **ptr);
	void 	drop_param 			(void);
	void 	push_null 			(void);
	void 	init_blob 			(struct fgl_int_loc *p);
	int 	read_param 			(void *p, int d, int size, int c);
	int 	conv_to_interval 	(int a);
	int 	chknull_boolean 	(int n, int n1, int n2);
	int 	chknull 			(int n, int n1, int n2);
	void 	push_bind 			(struct BINDING *b, int n, int no, int elemsize);
	void 	push_bind_reverse 		(struct BINDING *b, int n, int no, int elemsize);

	/* ============================ calldll.c ============================== */
	void * 	dl_openlibrary 		(char *type, char *name);
	void *  find_func_allow_missing (void *dllhandle, char *func);
	void * 	find_func 			(void *dllhandle, char *func);


	/* ============================ conv.c ================================= */
	void 	decode_interval 	(struct ival *ival, int *data);
	int 	stod 				(void *zz, void *aa, int sz_ignore);
	int 	conv 				(int dtype1, void *p1, int dtype2, void *p2, int size);
	void    set_convmatrix		(int dtype1,int dtype2,void *ptr);
	void assertion                  (int a, char *s);

	/* ============================ fglwrap.c ============================== */
	void 	chk_err				(int lineno,char *fname);
	int     fgl_error 			(int a, char *s, int err, int stat);
	int 	isyes				(char *s);
	char * 	get_serno			(void);
	void 	set_abort 			(int a);
	void    check_and_show_id	(char *program, char *arg1);

	/* ========================= errfile.c================================== */
	FILE *	mja_fopen			(char *name,char *mode);
	FILE *	write_errfile		(FILE *f,char *fname,long as,int lineno);


	/* ============================ extfile.c ============================== */

	char * 	get_translated_id 	(char * no_c);
	char * 	get_help_disp		(int n);
	int     has_helpfile		(void);

    /* =========================== from a4gl_io.h ================ */

	FILE *	open_file_dbpath	(char *fname);

	/* ========================== match.c ================================== */
	int 	aubit_strcasecmp 	(char *a, char *b);
	int		matche 				(register char *p, register char *t);

	/* =========================== gui.c =================================== */
	int 	isgui 				(void);
	void 	proc_it 			(char *buff);
	int 	get_gui_char 		(void);
	void    gui_actmenu			(long ld);

	/* ============================ function_call_stack.c =================== */
	int 	A4GLSTK_isStackInfo	(void);
	char *	A4GLSTK_getStackTrace(void);
	void 	A4GLSTK_pushFunction(const char *functionName,char *params[],int n);
	void 	A4GLSTK_popFunction	(void);

	/* ============================ err.c =================================== */
	char * 	err_print			(int a,char *s);

	/* =========================== project.c =============================== */
	/* (created using mkproject script) */
	void 	set_version			(int a,char *m,char *id);
	char*	internal_version	(void);
	int 	internal_build		(void);

	/* ============================ rexp2.c ================================= */
	void 	stripnl				(char *buff);
	int 	mja_match			(char *str1, char*str2, int likeormatch);
	char *	construct			(char *colname, char *val, int inc_quotes);

    /* =========================== stack.c ================================ */


	struct bound_list
	{
	  struct BINDING *ptr;
	  int cnt;
	  int popped;
	};

	void *      dif_get_bind 	(struct bound_list *list);
	void *      dif_start_bind 	(void);

    /* =================== from a4gl_shockhelp.h ====================*/

	struct 	in_addr *atoaddr	(char *address );
	int 	make_connection		(char *service, int type, char *netaddress );
	void 	ignore_pipe			(void);


	int 	atoport 			(char *service,char *proto);
	#ifndef __MINGW32__
		int 	get_connection 		(int socket_type,u_short port,int *listener);
	#endif
	int 	sock_read 			(int sockfd, char *buf, size_t count);
	int 	sock_write 			(int sockfd, char *buf, size_t count);
	int 	sock_gets 			(int sockfd, char *str, size_t count);
	int 	sock_puts 			(int sockfd,char *str);

	/* ============================ others.c ================================ */


	int 	net_keyval			(char *v);
	void 	convupper			(char *s);
    #ifndef _NO_FORM_X_H_ /* if we don't include form_x.h, this would generate errors : */
		int 	find_srec 			(struct_form * fd, char *name);
        /* struct struct_scr_field defined in fcompile/form_x.h */
		int 	has_str_attribute 	(struct struct_scr_field * f, int str);
		int 	attr_name_match 	(struct struct_scr_field *field, char *s);
		char *	get_str_attribute 	(struct struct_scr_field *f, int str);
	#endif
	void 	set_last_key 		(int a);
	char *	strip_quotes 		(char *s);
	void 	convlower			(char *s);
	int 	get_lastkey 		(void);

	/* ============================ io.c =================================== */
	void 	bname 				(char *str, char *str1, char *str2);

	/* ============================ keys.c ================================= */
	int 	key_val				(char *str);
	int 	check_keys 			(int val, char *str2);
	int 	check_key 			(int val, char *a, int ln);


	/* ============================ pointers.c ============================= */
	int 	has_pointer 		(char *pname, char t);
	void 	add_pointer 		(char *orig_name, char type, void *ptr);
	void 	del_pointer 		(char *pname, char t);
	int 	find_pointer_ptr 	(char *name,char *type,void *ptr);
	void * 	find_pointer_val 	(char *pname, char t);

	/* ============================ screen.c =============================== */
	int 	screen_mode			(int a);

	/* ============================ maths.c ================================ */
	void * 	find_op_function	(int dtype1,int dtype2,int op);
	void 	add_op_function		(int dtype1,int dtype2,int op,void *function);

	/* ============================ translate.c ============================ */

	void 	dumpstring			(char *s,long n,char *fname);


	void set_a4gl_status(int a) ;
	int get_a4gl_status(void) ;
	void set_a4gl_sqlca_sqlcode(int a) ;
	int get_a4gl_sqlca_sqlcode(void ) ;

    /* ========================== from a4gl_screen.h ==================== */


	/* 4gl program controls */
	#define FORMCONTROL_BEFORE_FIELD 		1
	#define FORMCONTROL_AFTER_FIELD 		2
	#define FORMCONTROL_BEFORE_INPUT 		3
	#define FORMCONTROL_AFTER_INPUT 		4
	#define FORMCONTROL_EXIT_INPUT_OK 		5
	#define FORMCONTROL_EXIT_INPUT_ABORT 	6
	#define FORMCONTROL_KEY_PRESS 			7

	/* formloop controls */
	#define FORMCONTROL_REQUEST_FIELD
	#define FORMCONTROL_ENABLE_FIELD
	#define FORMCONTROL_DISABLE_FIELD
	#define FORMCONTROL_HIDE_FIELD

	struct s_formcontrol {
		int 	op;
		char *	parameter;
		int 	field_number;
	};

	struct s_screenio {
		int 	mode;
		struct 	s_form_dets *currform;
		void *	currentfield;
		struct 	s_metrics *currentmetrics;
		int 	novars;
		struct 	BINDING *vars;
		struct 	s_constr_list *constr;
		int 	nfields;
		void **	field_list;
		int 	field_changed;
		int 	help_no;
		//struct 	s_formcontrol msgs[10];
		//int 	msg_cnt;

	};

	struct s_disp_arr {
		int 	no_fields;
		int 	no_lines;
		int 	no_arr;
		int 	last_arr;
		struct 	struct_screen_record *srec;
		int 	arr_elemsize;
		int 	scr_line;
		int 	arr_line;
		int 	highlight;
		struct 	s_form_dets *currform;
		struct 	BINDING *binding;
		int 	nbind;
		int 	cntrl;
	};

	struct s_inp_arr {
		int 	mode;
		int 	nbind;
		struct 	s_form_dets *currform;
		void *	currentfield;
		struct 	s_metrics *currentmetrics;
		int 	novars;
		struct 	s_constr_list *constr;
		int 	nfields;
		void ***field_list;   /* this should probably be FIELD ***field_list; not void ? */
		int 	no_fields;
		int 	no_lines;
		int 	no_arr;
		int 	inp_flags;
		int 	arr_size;

		int 	last_arr_line;
		int 	last_scr_line;

		struct 	struct_screen_record *srec;
		int 	arr_elemsize;
		int 	scr_line;
		int 	arr_line;
		int 	highlight;
		struct 	BINDING *binding;
		int 	cntrl;
		int 	help_no;
		int 	curr_attrib;
		struct s_screenio *screen_io;
	};


    /* ====================== from a4gl_prompt.h ================== */

	struct s_prompt {
		void *	win;
		int 	mode;
		int 	charmode;
		char *	promptstr;
		int 	lastkey;
		void *	f;
		void *	field;
		int 	h;
	};

	void * 	get_curr_form 	(void); /* in API_ui.c libtui/newpanels.c libgui/input.c */
	int 	load_data		(char *fname,char *delims,char *tabname,...);
	int 	inp_arr 		(struct s_inp_arr *disp, void *ptr, char *srecname, int attrib,int init);
	int 	set_scrline_ia 	(int np);
	int 	set_arrline_ia 	(int np);
	struct 	struct_screen_record *get_srec (char *name);

	/* From sql.c */
	char *	get_currdbname	(void);
	long 	describe_stmt 	(char *stmt, int colno, int type);

	/* From curslib.c (not completed) */
	ACL_Menu *new_menu_tui (char *title,
		  int x, int y,
		  int mn_type, int help_no, int nopts,va_list *ap
	);
	ACL_Menu *new_menu_create_tui(
			char *title, int x, int y, int mn_type, int help_no
	);
	char *	disp_h_menu_tui 	(ACL_Menu * menu);
	int 	endis_fields_tui	(int en_dis,...) ;
	void 	init_tui			(void);

	/* From newpanels.c (Not completed) */
	struct 	s_form_dets * get_curr_form_tui(void);

	/* ====================== From formwrite2.c ====================== */
	char *	char_val 		(char *s);

	/* ============================ read_dty.c ============================= */
	int 	get_dtype		(char *tabname, char *colname,char *dbname,char *tablist[]);

    /* ========================= from a4gl_acl_string.h ============ */
	void 	modify_size		(char *z,int a);

    /* ==================== from a4gl_aclform.h =================== */


   	struct form_attr {
	    int iswindow;
	    int form_line;
	    int error_line;
	    int prompt_line;
		int comment_line;
		int message_line;
	    int menu_line;
	    int border;
	    int attrib;
	};


	/* ============================ errfile.c =============================== */
	void    write_cont			(FILE *f);

    /* =========================== dataio.c =============================*/
	int 	read_data_from_file	(char *datatype, void *ptr, char *filename) ;
	int 	write_data_to_file	(char *datatype, void *ptr, char *filename) ;


    /* prompt.c */

	void a4gl_usleep(int a);
	void A4GL_pause(char *s);



#endif /* #ifndef _AUBIT_LIB_INCL_EXT_ */


/* ========================== EOF ====================================== */

