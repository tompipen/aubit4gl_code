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
# $Id: a4gl_libaubit4gl.h,v 1.123 2004-05-12 08:15:51 mikeaubury Exp $
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

#ifdef __cplusplus
	extern "C"
	{
#endif
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

	  int strncasecmp (char *a, char *b, int c);
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
	#define	enum_t	int

#endif

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
//#define DATE_INVALID 				0
#define DATE_INVALID 				0x80000000

#define MAXDIG 						30

  /* ===================== from a4gl_dates.h ======================== */

#define	THURSDAY					4	/* for reformation */
#define	SATURDAY 					6	/* 1 Jan 1 was a Saturday */
#define	FIRST_MISSING_DAY 			639787	/* 3 Sep 1752 */
#define	NUMBER_MISSING_DAYS 		11	/* 11 day correction */
#define	MAXDAYS						42	/* max slots in a month array */
#define	SPACE						-1	/* used in day array */
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
#define AUBIT_ATTR_INVISIBLE   		0x20000
#define AUBIT_ATTR_ALTCHARSET  		0x40000

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

  /* =================== from a4gl_shockhelp.h ==================== */

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
#define A4GLKEY_ESCAPE          27
#define A4GLKEY_ENTER 		0xff01
#define A4GLKEY_DOWN 		0xff02
#define A4GLKEY_UP 		0xff03
#define A4GLKEY_LEFT 		0xff04
#define A4GLKEY_RIGHT 		0xff05
#define A4GLKEY_PGUP 		0xff06
#define A4GLKEY_PGDN 		0xff07
#define A4GLKEY_INS 		0xff08
#define A4GLKEY_DEL 		0xff09
#define A4GLKEY_HOME 		0xff0a
#define A4GLKEY_END 		0xff0b
#define A4GLKEY_DC 		0xff0c
#define A4GLKEY_DL 		0xff0d
#define A4GLKEY_BACKSPACE 	0xff0e
#define A4GLKEY_SHTAB 		0xff0f

#define A4GLKEY_ACCEPT 		0xff20
#define A4GLKEY_DELETE		0xff21
#define A4GLKEY_INSERT		0xff22
#define A4GLKEY_HELP		0xff23
#define A4GLKEY_NEXT		0xff24
#define A4GLKEY_NEXTPAGE	0xff25
#define A4GLKEY_PREV		0xff26
#define A4GLKEY_PREVPAGE	0xff27
#define A4GLKEY_INTERRUPT	0xff28


#define A4GLKEY_CANCEL 		0xfffe

#define A4GLKEY_F(x) 		(0xff10+x)

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
#define COMPILED_FORM_PACKER 	'H'
#define COMPILED_FORM_FORMTYPE 	'I'
#define DYNMEMALLOC 		'J'
#define STR_RESOURCE_VAL 		'K'

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

#define getptr_PANEL(b) 		(PANEL *)A4GL_find_pointer(b,RES_PANEL)
#define getptr_s_windows(b) 	(struct s_windows *)A4GL_find_pointer(b,RES_ACLWINDOW)
#define getptr_WINDOW(b) 		(WINDOW *)A4GL_find_pointer(b,RES_CURSWINDOW)
#define getptr_s_form_dets(b) 	(struct s_form_dets *)A4GL_find_pointer(b,RES_ACLFORM)

#define pushptr_PANEL(b,p)      	A4GL_add_pointer(b,RES_PANEL,p)
#define pushptr_s_windows(b,p)   	A4GL_add_pointer(b,RES_ACLWINDOW,p)
#define pushptr_WIN(b,p)         	A4GL_add_pointer(b,RES_CURSWINDOW,p)
#define pushptr_s_form_dets(b,p) 	A4GL_add_pointer(b,RES_ACLFORM,p)


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


  /* ==================== from incl_4glhdr.h ========================= */
#define A4GL_fglerror(a,b) 		A4GL_fgl_error(__LINE__,__FILE__,a,b)
/*
#define AFT_FIELD_CHK(zzz,xxx) 		(_fld_dr==-98&&strcmp(fldname,zzz)==0)
#define BEF_FIELD_CHK(zzz,xxx) 		(_fld_dr==-97&&strcmp(fldname,zzz)==0)
*/
#define DO_BEFORE_DELETE  		(_fld_dr==-12)
#define DO_AFTER_DELETE  		(_fld_dr==-13)
#define DO_BEFORE_INSERT  		(_fld_dr==-14)
#define DO_AFTER_INSERT  		(_fld_dr==-15)
#define BEF_ROW 			(_fld_dr==-10)
#define AFT_ROW  			(_fld_dr==-11)
#define BEFORE_INP  			(_fld_dr==-99)
#define AFTER_INP  			(_fld_dr==-95)
#define ON_KEY(zzz) 			(_fld_dr==-90&&A4GL_chk_iskey(_sio,_sio_kw,zzz))

#define set_status(a) 			A4GL_set_status(a,0)

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

#define DTYPE_OBJECT    99

#define DTYPE_MASK 		255	/* bit pattern for data type */
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
#ifdef CSCC
#define NO_UNIX_HEADERS
#undef HAVE_SEARCH_H
#undef HAVE_NETINET_IN_H
#endif
	#ifndef __NO_STDARG__
		#include <stdarg.h>		/* va_start(), va-list ... */
	#endif

#ifndef _NO_SYSINCL_

	#if defined(WIN32) || defined (__MINGW32__)
		#ifndef _NO_WINDOWS_H_
			#include <windows.h>
			#define __UCHAR_DEFINED__
		#endif
	#else						/* UNIX */
		#include <pwd.h>		/* getpwduid() */
		#ifndef NO_UNIX_HEADERS
		#include <sys/socket.h>
		#include <netinet/in.h>
		#include <netdb.h>
		#endif
	#endif

  	//#include <ctype.h>    	/* tolower() toupper() */
	#include <stdio.h>			/* needed for FILE symbol */

	#ifndef WIN32
		#include <string.h>
	#endif
	#include <stdlib.h>			/* free() */

	#if HAVE_SEARCH_H
		#include <search.h>		/* VISIT-used in pointers.c */
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

	#include <assert.h>		/* assert() */
	#include <time.h>
	#include <math.h>		/* pow() */
	#include <locale.h>		/* setlocale() */
	#include <unistd.h>		/* sleep() close() write() usleep() */
	#include <signal.h>		/* SIGINT */

  /*
     skipposixheaders flag:
     to force LCLint to process <sys/types.h>, since form_x.h will include
     rpc.h that needs fd_set. included via /usr/include/sys/types.h but
     defined in /usr/include/sys/select.h
   */

  /*@-skipposixheaders@ */
	#include <sys/types.h>
  /*@=skipposixheaders@ */

#endif //_NO_SYSINCL_


#ifdef USE_ZZIPLIB

	//#define FILE ZZIP_FILE
	#define fopen zzip_fopen
	#define fread zzip_fread
	#define fwrite zzip_fwrite
	#define fclose zzip_fclose
	#define frewind zzip_frewind
	#define fseek zzip_fseek
	#define ftell zzip_ftell
	#include "zzip.h"
#endif


  /*
     This will prevent ussage of getenv and wgetenv functions:
     You could also enforce the prohibition of other undesirable C
     functions, with gets() and strtok() springing to mind as the first
     candidates, but there are likely to be others too.

     This would cause compile-time error if getenv() is used:
     #define getenv(s)    assert("Do not use getenv()" == 0)
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


/*
=====================================================================
                    Variables definitions
=====================================================================
*/

  /* ========================= from a4gl_ui.h ====================== */

  struct input_array_attribs {
        char *maxcount;
        char *count;
        int allow_insert;
        int allow_delete;
        char *curr_row_display;
  };



  typedef struct s_int_list
  {
    int code;
    struct s_int_list *next_option;
  }
  int_list;

/* moved to a4GL_incl_4gldef.h becuse it's needed in A4GL_API_ui.h

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
    char window_name[20];
    ACL_Menu_Opts *curr_option;
    int menu_offset;
    int mn_offset;
    int x;
    int y;
    int help_no;
    int num_opts;
    int abort_pressed;
    ACL_Menu_Opts *first;
    ACL_Menu_Opts *last;	// used for wrapping round
    void *menu_win;
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

*/

  typedef struct s_field_geometry
  {
    int x, y;
    int length;
    struct s_field_geometry *field_up;
    struct s_field_geometry *field_down;
    struct s_field_geometry *field_left;
    struct s_field_geometry *field_right;
    struct s_field_geometry *field_next;
    struct s_field_geometry *field_previous;
    struct s_gen_field *master;
  }
  field_geometry;

  typedef struct
  {
    char colname[19];
    char tabname[19];
    int length;
    int x, y;
    int data_type;
    int attributes;		/*color etc. */
    int field_attributes;	/*autonext etc. */
    char tag[19];
    field_geometry *fields_list;
  }
  gen_field;

  typedef struct
  {
    int x, y, width, height;
    char form_name[19];
  }
  gen_form;


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

  void init_menu (void);	/*initialize menu structure */
  int disp_menu (char *str, int x, int y);	/* display a menu with title 'str' at position y */
  void banner (char str[], int a, int b, int c);
  void title_box (char str[], int a, int x, int l);
  void A4GL_error_box (char *str,int attr);	/*print error message */

  /* from curslib.c: */
  void A4GL_disp_opt (int row, int x, int y, int l, int type);
  int A4GL_do_key_menu (void);	/*internal function */
  void A4GL_do_pause (void);		/*waits for a key press */
  int A4GL_edit (char *string, char type, int length, int x, int y);
  int A4GL_check_type (char c, char type, int flg, int len);
  int A4GL_ask_int (char *prompt);	/*  prompt for an integer from user  */
  double A4GL_ask_dbl (char *prompt);	/*  prompt for an integer from user  */
  int A4GL_ask_verify (char *prompt);	/*  prompt for verification  */
  unsigned int getcursor (void);	/* Returns the shape of the current cursor */
  void A4GL_strip_nl (char *str);
int A4GL_readkey(void);

  ACL_Menu *A4GL_new_menu (char *title, int x, int y, int mn_type, int help_no,
		      int nopts, va_list * ap);

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

  typedef struct
  {
    int code;
    char *desc;
    int color_attrib;
    int attrib;
  }
  attributes;

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


  void *A4GL_create_blank_window (char *name, int x, int y, int w, int h,
			     int border);
  char *A4GL_glob_window (int x, int y, int w, int h, int border);
  void *A4GL_find_pointer (const char *pname, char t);


  struct s_form_attr
  {
    int mode;
    int colour;
    char border;
    int inpattr;
    int dispattr;
    int nextkey;
    int prevkey;
    int input_wrapmode;
    int comment_line;
    int form_line;
    int menu_line;
    int message_line;
    int prompt_line;
    int fcnt;
    int insmode;
    int error_line;
    int inskey;
    int delkey;
    int helpkey;
    int acckey;
    int fieldconstr;
    int sqlintr;
  };

  /* OBJECTMODULE is defined ONLY in keys.c */
#ifdef OBJECTMODULE
  char opts[100][80];		/*menu options */
  int abort_pressed;
  int relxedit = 0, relyedit = 0;
  int aborted;
  long time_offset = 0;
  int week_no = -1;
  struct s_form_attr std_dbscr;
#else
  extern char opts[10][80];	/*menu options */
  extern int abort_pressed;
  extern int relxedit, relyedit;
  extern int aborted;
  extern long time_offset;
  extern int week_no;
  dll_import struct s_form_attr std_dbscr;
#endif


  /* ======================== from debug.h ======================== */


  void A4GL_exitwith_sql (char *s);
  void A4GL_set_errm (char *s);

  /* in debug.c */
  void A4GL_setarg0 (const char *argv0);
  const char *A4GL_getarg0 (void);

  /* ========================== from a4gl_dtypes.h ==================== */

  struct s_typenames
  {
    char *name;
    int dtype;
    int noentry;
    int blank;
  };

#ifdef IO
  struct s_typenames def_dtypes[] = {
    {"char", DTYPE_CHAR, 0, 0},
    {"integer", DTYPE_INT, 0, 1},
    {"float", DTYPE_FLOAT, 0, 1},
    {"smallfloat", DTYPE_SMFLOAT, 0, 1},
    {"decimal", DTYPE_DECIMAL, 0, 1},
    {"serial", DTYPE_SERIAL, 0, 1},
    {"date", DTYPE_DATE, 0, 0},
    {"money", DTYPE_MONEY, 0, 1},
    {"datetime", DTYPE_DTIME, 0, 0},
    {"byte", DTYPE_BYTE, 2, 0},
    {"text", DTYPE_TEXT, 2, 0},
    {"varchar", DTYPE_VCHAR, 0, 0},
    {"interval", DTYPE_INTERVAL, 0, 0},
    {0, 0, 0, 0}
  };
#else
  extern struct s_typenames def_dtypes[];
#endif


  /* ==================== from incl_4glhdr.h ========================= */

  /* not strictly voids - but saves getting into the details */
  void *prepare_glob_sql (char *s, int ni, void *b);



enum cmd_types {
	FGL_CMD_PAUSE,
	FGL_CMD_START_RPC,
	FGL_CMD_STOP_RPC,
	FGL_CMD_CALL,
	FGL_CMD_CLOSE,
	FGL_CMD_CODE,
	FGL_CMD_COMMENT,
	FGL_CMD_CONSTRUCT,
	FGL_CMD_DEFER,
	FGL_CMD_DISPLAY_CMD,  // DISPLAY / DISPLAY @
	FGL_CMD_DISPLAY_FIELD_CMD,  // DISPLAY TO, DISPLAY BY NAME
	FGL_CMD_DISPLAY_FORM,
	FGL_CMD_ERROR,
	FGL_CMD_EXIT,
	FGL_CMD_CONTINUE,
	FGL_CMD_EXIT_PROGRAM,
	FGL_CMD_FOR,
	FGL_CMD_FOREACH,
	FGL_CMD_FREE,
	FGL_CMD_GOTO,
	FGL_CMD_CHECK_MENU,
	FGL_CMD_UNHECK_MENU,
	FGL_CMD_DISABLE,
	FGL_CMD_ENABLE,
	FGL_CMD_MSG_BOX,
	FGL_CMD_IF,
	FGL_CMD_INIT,
	FGL_CMD_NEXT_FIELD,
	FGL_CMD_NEXT_FORM,
	FGL_CMD_INPUT,
	FGL_CMD_SCROLL,
	FGL_CMD_LABEL,
	FGL_CMD_LET,
	FGL_CMD_LINKED,
	FGL_CMD_LINKED_DEL,
	FGL_CMD_LINKED_UPD,
	FGL_CMD_LOCATE,
	FGL_CMD_AT_TERM,
	FGL_CMD_RETURN,
	FGL_CMD_MENU,
	FGL_CMD_NEXT_OPTION,
	FGL_CMD_SHOW_OPTION,
	FGL_CMD_HIDE_OPTION,
	FGL_CMD_MESSAGE,
	FGL_CMD_OPEN_WINDOW,
	FGL_CMD_OPEN_STATUSBOX,
	FGL_CMD_OPEN_FORM,
	FGL_CMD_OPEN_SESSION,
	FGL_CMD_OPEN_CURSOR,
	FGL_CMD_CONNECT,
	FGL_CMD_OPTIONS,
	FGL_CMD_PREPARE,
	FGL_CMD_EXECUTE,
	FGL_CMD_PROMPT,
	FGL_CMD_GUI_PROMPT,
	FGL_CMD_PUT,
	FGL_CMD_START,
	FGL_CMD_OUTPUT,
	FGL_CMD_FINISH,
	FGL_CMD_TERM_REP,
	FGL_CMD_REPORT,
	FGL_CMD_RUN,
	FGL_CMD_DROPS,
	FGL_CMD_CREATE,
	FGL_CMD_UPD_STATS,
	FGL_CMD_ALTER,
	FGL_CMD_SET,
	FGL_CMD_SLEEP,
	FGL_CMD_SET_DATABASE,
	FGL_CMD_SQL,
	FGL_CMD_FLUSH,
	FGL_CMD_DECLARE,
	FGL_CMD_UNLOAD,
	FGL_CMD_LOAD,
	FGL_CMD_SQL_BLOCK,
	FGL_CMD_WHENEVER,
	FGL_CMD_CLEAR,
	FGL_CMD_CURRENT_WIN,
	FGL_CMD_SHOW,
	FGL_CMD_HIDE,
	FGL_CMD_MOVE
};
	
	


#define DEF_ASS(uass,d) char * uass[d]={(char *)-1}

#define OP_MASK 		(512|1024)
#define OP_MASK_BASE 	512

#define NUMERIC_OP_2  	(1*OP_MASK_BASE)
#define STRING_OP_S1 	(2*OP_MASK_BASE)
#define STRING_OP_S2 	(4*OP_MASK_BASE)
#define STRING_OP_N1 	(8*OP_MASK_BASE)
#define STRING_OP_N2 	(16*OP_MASK_BASE)
#define FUNCTION_OP 	(32*OP_MASK_BASE)
#define BOOLEAN_OP 		(64*OP_MASK_BASE)
#define OTHER_OP 		(128*OP_MASK_BASE)

  /* add no more than 15 items to any of the following groups */
#define OP_ADD 			(1|NUMERIC_OP_2)
#define OP_SUB 			(2|NUMERIC_OP_2)
#define OP_MULT 		(3|NUMERIC_OP_2)
#define OP_DIV 			(4|NUMERIC_OP_2)
#define OP_POWER 		(5|NUMERIC_OP_2)
#define OP_MOD 			(6|NUMERIC_OP_2)

#define OP_CLIP 		(1|STRING_OP_S1)
#define OP_CONCAT 		(1|STRING_OP_S2)
#define OP_COPY 		(2|STRING_OP_S2)
#define OP_USING 		(3|STRING_OP_S2)
#define OP_MATCHES 		(4|STRING_OP_S2)
#define OP_LIKE 		(5|STRING_OP_S2)

  /* This one is a special case and should **NOT** be
     used anywhere except for grouping others together in stack.c and
     when processing maths operations.
     Used for A4GL_add_op_function & find_op_function
   */

#define OP_MATH 		(12|BOOLEAN_OP)

#define OP_YEAR 		(1|STRING_OP_N1)
#define OP_MONTH 		(2|STRING_OP_N1)
#define OP_DAY 			(3|STRING_OP_N1)
#define OP_HOUR 		(4|STRING_OP_N1)
#define OP_MINUTE 		(5|STRING_OP_N1)
#define OP_SECOND 		(6|STRING_OP_N1)

#define OP_SUBSTR1 		(1|STRING_OP_N2
#define OP_SUBSTR2 		(1|STRING_OP_N3

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

  char *A4GL_new_string (int a);


#ifndef ALREADY_DONE_POP_PUSH_ETC
  void A4GL_debug_full (char *fmt, ...);
  int A4GLSTK_isStackInfo (void);
  char *acl_getenv (char *);
  char *A4GLSTK_getStackTrace (void);
  void A4GLSTK_pushFunction (const char *functionName, char *params[], int n);
  void A4GLSTK_popFunction (void);
  void A4GL_pushop (int a);
  void A4GL_chk_err (int lineno, char *fname);
  void A4GL_push_bind_reverse (struct BINDING *b, int n, int no, int elemsize);
  void A4GL_push_bind (struct BINDING *b, int n, int no, int elemsize);
  void A4GL_push_null (int dtype,int size);
  char *a4gl_substr (char *s, int dtype, int a, int b, ...);
  int A4GL_set_line (char *s, long l);
char *get_bind_varname(char i,int n);
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
  void A4GL_pop_params (struct BINDING *b, int n);
  void A4GL_push_param (void *p, int d);
  void A4GL_push_params (struct BINDING *b, int n);
  void A4GL_push_user (void);
  void A4GL_push_today (void);

void A4GL_fgl_end_4gl_0 (void);
void A4GL_fgl_end_4gl_1 (void); // Used on interrupt
void A4GL_display_at (int n, int a);
  void A4GL_push_dtime (struct A4GLSQL_dtime *p);
  void A4GL_push_int (short p);
  void A4GL_push_long (long p);
  void A4GL_push_date (long p);
  void A4GL_push_float (float p);
  void A4GL_push_dec (char *p, int ismoney,int size);
  void A4GL_push_double (double p);
  void A4GL_push_chars (char *p, int dtype, int size);
  void A4GL_push_char (char *p);
  void A4GL_push_variable (void *ptr, int dtype);
  void A4GL_push_interval (struct ival *p);
  void A4GL_pop_args (int a);
#endif



  double A4GL_ret_var (void *p, int d);

  int A4GL_opboolean (void);
  void A4GL_debug_print_stack (void);
  void print_stack (void);
  void A4GL_locate_var (struct fgl_int_loc *p, char where, char *filename);

#define acl_free(s) acl_free_full(s,__FILE__,__LINE__)
#define acl_malloc(a,b) acl_malloc_full(a,b,__FILE__,__LINE__)

#define GETSETNEW 		-1
#define GETSETRM 		-2
#define GETSETGET 		1
#define GETSETSET 		2
#define GETSETGETPTR 	3

#define GETPTR(struct,ptr,element) A4GL_get_set(struct,ptr,GETSETGETPTR,element,0)
#define GET(struct,ptr,element) A4GL_get_set(struct,ptr,GETSETGET,element,0)
#define SET(struct,ptr,element,value) A4GL_get_set(struct,ptr,GETSETSET,element,(long)value)
#define NEW(struct) A4GL_get_set(struct,0,GETSETNEW,0,0)
#define RM(struct,ptr) A4GL_get_set(struct,ptr,GETSETRM,0,0)

  /* report stuff */
#ifndef REP_STRUCTURE
#define REP_STRUCTURE
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
    /* was      int (*report)(); */
/* int (*report)(void); *//* report.c:180: too many arguments to function */
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
    /* was      int (*report)(); */
/* int (*report)(void); *//* report.c:180: too many arguments to function */
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







  //double A4GL_pdf_size (double f, char c, struct pdf_rep_structure *p);

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
#define REPORT_RESTART -15
#define REPORT_TERMINATE 			-9999
#define ERR_BADNOARGS 			1000
#define ABORT 					1
#define WARN 					2

#ifndef NODEBUG
#define A4GL_debug A4GL_set_line(__FILE__,__LINE__);A4GL_debug_full
#else
#define A4GL_debug null_func
#endif

  /* ====================== from data_if.c =================== */

  void *A4GL_get_set (char *str, void *ptr, int mode, char *name, long var);


  /* ===================== from builtin.c =================== */

  int A4GL_fgl_fieldtouched (void *i,char itype, ...);
  void A4GL_close_database (void);

/* These two need a4gl in lower case... */
  char *a4gl_let_substr (char *ca, int dtype, int a, int b, ...);


  void A4GL_include_builtin_in_exe (void);
  void A4GL_set_scr_line (int a);
  void A4GL_set_arr_curr (int a);
  int A4GL_get_count (void);
  void A4GL_set_arr_count (int a);
  int aclfgl_dbms_dialect (int n);
  void aclfgli_extend (void);


  /* ======================= From buildtin_d.c ==================== */


  int A4GL_func_clip (void);
  void A4GL_func_concat (void);
  void A4GL_func_using (void);
  int A4GL_find_function (char *a);
  double A4GL_power (double a, double b);

  /* ============================ resource.c ============================= */
  struct str_resource
  {
    char name[40];
    char value[1024];		//must be long enough to hold GTK include paths
  };

  char *A4GL_find_str_resource_int (char *search, int a);
  struct str_resource *A4GL_build_user_resources (void);
  int A4GL_env_option_set (char *s);


  /* ========================== gui_io.c ================================= */
  void A4GL_gui_scrollpos (int a);
  void A4GL_gui_scroll (int a);
  void A4GL_gui_error (char *txt, int errline);
  void A4GL_gui_endform (void);
  void A4GL_gui_currwin (long a);
  void A4GL_gui_wrefresh (void *d);
  void A4GL_gui_print (int a, char *fmt, ...);
  void A4GL_gui_dispform (char *s, int line);
  void A4GL_gui_setcolor (int a);
  void A4GL_gui_refresh (void);
  void A4GL_gui_move (int x, int y);
  void A4GL_gui_closewin (char *name);
  void A4GL_gui_win (char *name, int h, int w, int y, int x, int b, long d);
  void A4GL_gui_setposition (long ld);
  void A4GL_gui_setbuff (void *a, char *n);
  void A4GL_gui_mkfield (int h, int w, int y, int x, void *p);
  void A4GL_gui_setfocus (long ld);
  void A4GL_gui_setattr (long a, int f, int b);
  void A4GL_gui_mklabel (int h, int w, int y, int x, char *s);
  void A4GL_gui_startform (char *name);
  void A4GL_gui_endmenu (long ld);
  void A4GL_gui_menuopt (char *title, long id);
  void A4GL_gui_message (char *txt, int msgline);
  void A4GL_gui_rmmenu (long ld);
  void A4GL_gui_endprompt (long ld);
  void A4GL_gui_startprompt (long ld);

  /* ========================== funcs_d.c ================================ */
  //void A4GL_trim (char *p);
  void A4GL_bnamexxx (char *str, char *str1, char *str2);
  void A4GL_pad_string (char *ptr, int size);
  void *acl_malloc_full (int size, char *why, char *f, long line);
  void acl_free_full (void *ptr, char *f, long line);
  void a4gl_using (char *str, int s, char *fmt, double num);
  int A4GL_digittoc (int *a, char *z, char *fmt, int dtype, int size);


  /* ========================== attributes.c ============================= */
	
	void A4GL_get_strings_from_attr (int attr, char *col_str, char *attr_str);
	int A4GL_get_curr_window_attr (void);

  /* =========================== dates.c ================================= */
  long A4GL_gen_dateno (int day, int month, int year);
  int A4GL_get_date (int d, int *day, int *mn, int *yr);
  int A4GL_day_in_week (int, int, int);
  int A4GL_modify_year (int a);
  int A4GL_date_sep (int z);


/* == memfile.c == */
  FILE *A4GL_memfile_fopen (char *f, char *mode);
  int A4GL_memfile_fseek (FILE * f, long offset, int whence);
  int A4GL_memfile_getc (FILE * f);
  void A4GL_memfile_fclose (FILE * f);
  void A4GL_memfile_rewind (FILE * f);
  long A4GL_memfile_ftell (FILE * f);
  int A4GL_memfile_ungetc (int c, FILE * F);
  int A4GL_memfile_feof (FILE * f);
  int A4GL_memfile_fread (char *ptr, int s, int n, FILE * f);
	void *A4GL_memdup (void *ptr, int size);


  /* ============================ dmy.c ================================== */

  char *A4GL_using_date (int dn, char *us);
  char *A4GL_dbdate_to_using (char *dbdate);
  char *A4GL_get_dbdate (void);


  /* =========================== string.c ================================ */
  char *A4GL_new_string_set (int a, char *b);
  void A4GL_string_set (char *ptr, char *b, int size);
  int A4GL_mja_strncmp (char *str1, char *str2, int n);


  /* ============================ error.c ================================ */
  void A4GL_exitwith (char *s);
  void A4GL_set_error (char *fmt, ...);

  /* ============================ from a4gl_stack.h ================= */

#define OP_MASK 		(512|1024)
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



  char *A4GL_params_on_stack (char *_paramnames[], int n);
  int A4GL_isnull (int type, char *buff);
  //void A4GL_setnull (int type, void *buff, int size);
  char *A4GL_lrtrim (char *z);
  void A4GL_get_top_of_stack (int a, int *d, int *s, void **ptr);
  void A4GL_drop_param (void);
  void A4GL_init_blob (struct fgl_int_loc *p);
  int A4GL_read_param (void *p, int d, int size, int c);
  int A4GL_conv_to_interval (int a);
  int A4GL_chknull_boolean (int n, int n1, int n2,int d1,int d2);
  int A4GL_chknull (int n, int n1, int n2,int d1,int d2);

  /* ============================ calldll.c ============================== */
  void *A4GL_dl_openlibrary (char *type, char *name);
  void *A4GL_find_func_allow_missing (void *dllhandle, char *func);
  void *A4GL_find_func (void *dllhandle, char *func);


  /* ============================ conv.c ================================= */
  void A4GL_decode_interval (struct ival *ival, int *data);
  int A4GL_stod (void *zz, void *aa, int sz_ignore);
  int A4GL_conv (int dtype1, void *p1, int dtype2, void *p2, int size);
  void A4GL_set_convmatrix (int dtype1, int dtype2, void *ptr);
  void A4GL_assertion (int a, char *s);

  /* ============================ fglwrap.c ============================== */
  int A4GL_fgl_error (int a, char *s, int err, int stat);
  int A4GL_isyes (char *s);
  char *get_serno (void);
  void A4GL_set_abort (int a);
  void A4GL_check_and_show_id (char *program, char *arg1);

  /* ========================= errfile.c================================== */
  FILE *A4GL_mja_fopen (char *name, char *mode);
  FILE *A4GL_write_errfile (FILE * f, char *fname, long as, int lineno);


  /* ============================ extfile.c ============================== */

  char *A4GL_get_translated_id (char *no_c);
  char *A4GL_get_help_disp (int n);
  int A4GL_has_helpfile (void);
  char * A4GL_get_last_outfile (void);

  /* =========================== from a4gl_io.h ================ */

  FILE *A4GL_open_file_dbpath (char *fname);
  char *A4GL_fullpath_dbpath (char *fname);

  /* ========================== match.c ================================== */
  int A4GL_aubit_strcasecmp (char *a, char *b);
  int A4GL_matche (register char *p, register char *t,char m,char s,char b); /* m=multi s=single b=brace eg '*' '?' '[' */

  /* =========================== gui.c =================================== */
  int A4GL_isgui (void);
  void A4GL_proc_it (char *buff);
  int A4GL_get_gui_char (void);
  void A4GL_gui_actmenu (long ld);

  /* ============================ function_call_stack.c =================== */

  /* ============================ err.c =================================== */
  char *A4GL_err_print (int a, char *s);

  /* =========================== project.c =============================== */
  /* (created using mkproject script) */
  void A4GL_set_version (int a, char *m, char *id);
  char *A4GL_internal_version (void);
  int A4GL_internal_build (void);

  /* ============================ rexp2.c ================================= */
  void A4GL_stripnl (char *buff);
  int A4GL_mja_match (char *str1, char *str2, int likeormatch);
  char *A4GL_construct (char *tabname,char *colname, char *val, int inc_quotes);

  /* =========================== stack.c ================================ */


  struct bound_list
  {
    struct BINDING *ptr;
    int cnt;
    int popped;
  };

  void *dif_get_bind (struct bound_list *list);
  void *dif_start_bind (void);

  /* =================== from a4gl_shockhelp.h ==================== */

  struct in_addr *atoaddr (char *address);
  int make_connection (char *service, int type, char *netaddress);
  void ignore_pipe (void);


  int atoport (char *service, char *proto);
#ifndef __MINGW32__
  int A4GL_get_connection (int socket_type, unsigned short port, int *listener);
#endif
  int A4GL_sock_read (int sockfd, char *buf, size_t count);
  int A4GL_sock_write (int sockfd, char *buf, size_t count);
  int A4GL_sock_gets (int sockfd, char *str, size_t count);
  int A4GL_sock_puts (int sockfd, char *str);

  /* ============================ others.c ================================ */


  int A4GL_net_keyval (char *v);
  void A4GL_convupper (char *s);

#ifndef _NO_FORM_X_H_
#include "../common/dataio/form_x.x.h"	/* struct_form */
#endif

#ifndef _NO_FORM_X_H_		/* if we don't include form_x.h, this would generate errors : */
  int A4GL_find_srec (struct_form * fd, char *name);
  /* struct struct_scr_field defined in fcompile/form_x.h */
  int A4GL_has_str_attribute (struct struct_scr_field *f, int str);
  int A4GL_attr_name_match (struct struct_scr_field *field, char *s);
  char *A4GL_get_str_attribute (struct struct_scr_field *f, int str);
#endif
  void A4GL_set_last_key (int a);
  char *A4GL_strip_quotes (char *s);
  void A4GL_convlower (char *s);
  int A4GL_get_lastkey (void);

  /* ============================ io.c =================================== */
  void A4GL_bname (char *str, char *str1, char *str2);

  /* ============================ keys.c ================================= */
  int A4GL_key_val (char *str);
  int A4GL_is_special_key(int k, int type);
  int A4GL_check_keys (int val, char *str2);
  int A4GL_check_key (int val, char *a, int ln);


  /* ============================ pointers.c ============================= */
  int A4GL_has_pointer (char *pname, char t);
  void A4GL_add_pointer (char *orig_name, char type, void *ptr);
  void A4GL_del_pointer (char *pname, char t);
  int A4GL_find_pointer_ptr (char *name, char *type, void *ptr);
  void *A4GL_find_pointer_val (char *pname, char t);

  /* ============================ screen.c =============================== */
  int A4GL_screen_mode (int a);

  /* ============================ maths.c ================================ */
  void *A4GL_find_op_function (int dtype1, int dtype2, int op);
  void A4GL_add_op_function (int dtype1, int dtype2, int op, void (*function)(int ops));

  /* ============================ translate.c ============================ */

  void A4GL_dumpstring (char *s, long n, char *fname);


  void A4GL_set_a4gl_status (int a);
  int A4GL_get_a4gl_status (void);
  void A4GL_set_a4gl_sqlca_sqlcode (int a);
  int A4GL_get_a4gl_sqlca_sqlcode (void);

  /* ========================== from a4gl_screen.h ==================== */


  /* 4gl program controls */

#define FORMCONTROL_BEFORE_FIELD 		1
#define FORMCONTROL_AFTER_FIELD 		2
#define FORMCONTROL_BEFORE_INPUT 		3
#define FORMCONTROL_AFTER_INPUT 		4
#define FORMCONTROL_EXIT_INPUT_OK 		5
#define FORMCONTROL_EXIT_INPUT_ABORT 		6
#define FORMCONTROL_KEY_PRESS 			7
#define FORMCONTROL_BEFORE_INSERT 		8
#define FORMCONTROL_BEFORE_DELETE 		9
#define FORMCONTROL_AFTER_INSERT 		10
#define FORMCONTROL_AFTER_DELETE 		11
#define FORMCONTROL_BEFORE_ROW 			12
#define FORMCONTROL_AFTER_ROW 			13


  /* formloop controls ? Don't know if we need these yet... */
#define FORMCONTROL_REQUEST_FIELD
#define FORMCONTROL_ENABLE_FIELD
#define FORMCONTROL_DISABLE_FIELD
#define FORMCONTROL_HIDE_FIELD

  struct s_formcontrol
  {
    int op;
    char *parameter;
    char *field_name;
    int field_number;
    int state;
    int extent;
    void *field;
  };

  struct s_screenio
  {
    int mode;
    struct s_form_dets *currform;
    void *currentfield;
    int curr_attrib;
    struct s_metrics *currentmetrics;
    int novars;
    struct BINDING *vars;
    struct s_constr_list *constr;
    int nfields;
    void **field_list;
    int field_changed;
    int help_no;
    struct s_formcontrol *fcntrl;
    int fcntrl_cnt;
    int attrib;
    int processed_onkey;
  };

  typedef struct s_screenio  Tscreenio;

  struct s_disp_arr
  {
    int no_fields;
    int no_lines;
    int no_arr;
    int last_arr;
    struct struct_screen_record *srec;
    int arr_elemsize;
    int scr_line;
    int arr_line;
    int highlight;
    struct s_form_dets *currform;
    struct BINDING *binding;
    int nbind;
    int cntrl;
    int attribute;
    int processed_onkey;
  };

  struct s_inp_arr
  {
    int mode;
    int nbind;
    struct s_form_dets *currform;
    void *currentfield;
    struct s_metrics *currentmetrics;
    int novars;
    struct s_constr_list *constr;
    int nfields;
    void ***field_list;		/* this should probably be FIELD ***field_list; not void ? */
    int no_fields;
    int no_lines;
    int no_arr;
    int inp_flags;
    int arr_size;
    int last_arr;

    int last_arr_line;
    int last_scr_line;

    struct struct_screen_record *srec;
    int arr_elemsize;
    int scr_line;
    int arr_line;
    int highlight;
    struct BINDING *binding;
    int cntrl;
    int help_no;
    int curr_attrib;
    struct s_screenio *screen_io;
    struct s_formcontrol *fcntrl;
    int fcntrl_cnt;
    int allow_insert;
    int allow_delete;
    char *curr_display;
    int curr_display_i;
    int maxcount;
    int count;
    int display_attrib;
    int scr_dim;
    int curr_line_is_new;
    int processed_onkey;
  };


  /* ====================== from a4gl_prompt.h ================== */

  struct s_prompt
  {
    void *win;
    int mode;
    int charmode;
    char *promptstr;
    int lastkey;
    void *f;
    void *field;
    int h;
	int insmode;
    int processed_onkey;
  };

  //void *A4GL_get_curr_form (int warn_if_no_form);	/* in API_ui.c libtui/newpanels.c libgui/input.c */
  int load_data (char *fname, char *delims, char *tabname, ...);
  //int A4GL_inp_arr (void *disp, int ptr, char *srecname, int attrib, int init);
  int set_scrline_ia (int np);
  int set_arrline_ia (int np);
  struct struct_screen_record *A4GL_get_srec (char *name);

  /* From sql.c */
  char *get_currdbname (void);
  long describe_stmt (char *stmt, int colno, int type);

  /* From curslib.c (not completed) */
  ACL_Menu *A4GL_new_menu_tui (char *title,
			  int x, int y,
			  int mn_type, int help_no, int nopts, va_list * ap);
  ACL_Menu *A4GL_new_menu_create_tui (char *title, int x, int y, int mn_type,
				 int help_no);
  char *disp_h_menu_tui (ACL_Menu * menu);
  int endis_fields_tui (int en_dis, ...);
  void init_tui (void);

  /* From newpanels.c (Not completed) */
  struct s_form_dets *get_curr_form_tui (void);

  /* ====================== From formwrite2.c ====================== */
  char *A4GL_char_val (char *s);

  /* ============================ read_dty.c ============================= */
  int A4GL_get_dtype (char *tabname, char *colname, char *dbname, char *tablist[]);

  /* ========================= from a4gl_acl_string.h ============ */
  void A4GL_modify_size (char *z, int a);

  /* ==================== from a4gl_aclform.h =================== */


  struct form_attr
  {
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




  struct s_form_dets            /* taken from a4gl_dbform.h */
  {
    /* this was just
       struct_form *fileform;
       and it worked on Linux, but not on CygWin...??????
     */
    /* #ifndef _NO_FORM_X_H_ what was this about??? */
    struct struct_form *fileform;
    /* #endif */
    struct s_form_attr form_details;
    void *form;
    int fields_cnt;
    int currentmetrics;
    void *form_fields[1024];
    void *currentfield;
  };

  /* ============================ errfile.c =============================== */
  void A4GL_write_cont (FILE * f);

  /* =========================== dataio.c ============================= */
  int A4GL_read_data_from_file (char *datatype, void *ptr, char *filename);
  int A4GL_write_data_to_file (char *datatype, void *ptr, char *filename);


  /* prompt.c */

  void a4gl_usleep (int a);
  void A4GL_pause (char *s);





void A4GL_acli_scroll (int n, ...);
int
aclfgl_a4gl_get_ui_mode (int n);
int
aclfgl_a4gl_get_info (int np);

void
A4GL_set_last_field_name (char *s);
char *
A4GL_get_last_field_name (char *s);
void
A4GL_add_compiled_form (char *s, char *packer, char *formtype, char *frm);
void *
A4GL_read_form (char *s, char *p);
int
A4GLSQL_load_data_str (char *fname, char *delims, char *sqlstmt);
void
A4GL_in_in_ops (int op);
int
A4GL_get_escape_chr (void);
int A4GL_determine_attribute(int cmd_type, int attrib_curr_int, void *fprop,char *val_for_field);
//int A4GL_get_curr_width_gtk (void);
//int aclfgli_libhelp_showhelp(int helpno);
void
a4gl_basename (char **ppsz);
//void A4GL_display_internal (int x, int y, char *s, int a, int clr_line);
void
A4GL_error_nobox (char *str,int attr);
void
A4GL_clr_error_nobox (char *dbg_fromwhere);
//int A4GL_fgl_getfldbuf_ap (char *s, int n,...);
//int A4GL_fgl_fieldtouched_input_ap(Tscreenio *s,  va_list *ap);
void A4GL_core_dump(void);
void
A4GL_set_core_dump (void);
char *A4GL_null_as_null(char *s);
int A4GL_has_errorlog (void);
int A4GL_add_datatype_function_i (int a, char *funcname, void *func);
void A4GL_close_errorlog_file (void);
void A4GL_set_last_outfile (char *s);
void A4GL_ltrim(char *s) ;
void A4GL_fgl_die(int n);
fgldecimal *A4GL_init_dec (fgldecimal *s, int len, int d);









/* 
   used by display routines to convert a datatype 
   to a string suitable for display 
*/

#define DISPLAY_TYPE_DISPLAY 	1
#define DISPLAY_TYPE_DISPLAY_AT 2
#define DISPLAY_TYPE_DISPLAY_TO 3
#define DISPLAY_TYPE_PRINT 	4


#ifndef _DEFINE_STATUSVARS_     /* set from fglwrap.c --ONLY-- */
  /* for everything except libaubit4gl: */

	#ifndef _SQLCA_DEFINED_
		/*
	     _SQLCA_DEFINED_ is set in esql.ec to prevent conflict with Informix headers
	     that also define sqlca:
		*/
		#define _SQLCA_DEFINED_
	#endif

	#ifndef _NO_A4GL_STATUS_
		extern long a4gl_status;   /** 4gl global status variable */
    #endif

	#ifndef _NO_INT_QUIT_FLAG_
		extern long int_flag;      /** 4gl interrupt ocurred global flag */
		extern long quit_flag;     /** 4gl quit ocurred global flag */
    #endif
#else
  /* only in libaubit4gl */
  dll_export sqlca_struct a4gl_sqlca;       /** Sqlca variable -- DEFINED WHERE ??? --*/
  long a4gl_status;            /** 4gl global status variable */
  long int_flag;               /** 4gl interrupt ocurred global flag */
  long quit_flag;              /** 4gl quit ocurred global flag */
#endif

int A4GL_get_option_value (char type);

void A4GL_processed_onkey(void) ;
void A4GL_reset_processed_onkey(void);
int A4GL_has_processed_onkey(void);
char *A4GL_replace_sql_var (char *s);
char *A4GL_find_attribute (struct s_form_dets *f, int field_no);
int A4GL_key_map(int keycode);
void A4GL_chk_for_screen_print(int a);
void A4GL_logkey(long a);
void A4GL_trim_nl (char *p);

struct s_field_name {
	char *fname;
	int fpos;
};

struct s_field_name_list {
	int nfields;
	struct s_field_name *field_name_list;
};



int A4GL_menu_hide (ACL_Menu * menu, ...);
int A4GL_menu_show (ACL_Menu * menu, ...);
void A4GL_set_scrmode (char a);
int A4GL_isscrmode (void);
int A4GL_islinemode (void);
int A4GL_disp_form_fields (int n, int attr, char *formname, ...);
int A4GL_endis_fields (int en_dis, ...);
int A4GL_disp_arr (void *disp, void *ptr, char *srecname, int attrib,void *evt, ...);
int A4GL_open_gui_form (long *form_variable,char *name_orig, int absolute, int nat, char *like, int disable, void *handler_e, void (*handler_c (int a, int b)));
int A4GL_fgl_infield (void *inp,char itype,...);





  /* API prototypes */
#include "a4gl_API_form.h"	/* generated from .spec */
#include "a4gl_API_menu.h"	/* generated from .spec */
#include "a4gl_API_msg.h"	/* generated from .spec */
#include "a4gl_API_packer.h"	/* generated from .spec */
#include "a4gl_API_ui.h"	/* generated from .spec */
#include "a4gl_API_help.h"	/* generated from .spec */
#include "a4gl_sql.h"	/* generated from .spec */


#include "a4gl_API_exdata.h"	/* created manually */
#include "a4gl_API_exreport.h"	/* created manually */
#include "a4gl_API_sql.h"	/* created manually */
#include "a4gl_API_rpc.h"	/* created manually */


#ifndef ALLOW_BOTH_LIB_AND_CALL
#ifdef FGLINCLDEF_INCL
#error a4gl_4gl_callable.h and a4gl_libaubit4gl.h should not be included together
#endif
#endif

#ifdef __cplusplus
}
#endif


/*
-----------------------------------------------------------------------------
 PORTABLE
   Set if we are going to use network style integers
   Not set if we are going to use native integers
 (On some platforms these may be the same, on others they won't be)
-----------------------------------------------------------------------------
*/


#if HAVE_NETINET_IN_H
//fdef PORTABLE
	#include <netinet/in.h>
#else
	#ifndef htonl
		#define htonl(x) (x)
		#define htons(x) (x)
		#define ntohl(x) (x)
		#define ntohs(x) (x)
	#endif
#endif


#endif				/* #ifndef _AUBIT_LIB_INCL_EXT_ */


/* ========================== EOF ====================================== */
