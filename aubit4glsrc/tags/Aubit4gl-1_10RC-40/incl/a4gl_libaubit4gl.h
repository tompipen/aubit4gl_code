/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-2005 Aubit Development Team (See Credits file)    |
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
# | contact licensing@aubit.com                                           |
# +----------------------------------------------------------------------+
#
# $Id: a4gl_libaubit4gl.h,v 1.346 2008-11-11 17:36:36 mikeaubury Exp $
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



#ifdef HAVE_CONFIG_H
	/* header automatically created with AutoConf-configure */
	#ifdef ALT_CONFIG
	#include "a4gl_incl_config_alt.h"
	#else

	#include "a4gl_incl_config.h"

	#endif
#endif


#ifdef __cplusplus
	extern "C"
	{
#endif
  /*
     =====================================================================
     Constants definitions
     =====================================================================
   */


#include <limits.h> /* SHRT_MIN SHRT_MAX */

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

	#include <limits.h> /* SHRT_MIN SHRT_MAX */

#endif


  /* if WIN32 is still defined, that means that __CYGWIN__was not defined */
#if (defined(WIN32) && ! defined(__CYGWIN__) && ! defined(__MINGW32__))
	#define __NATIVE_WINDOWS__

	  int strncasecmp (char *a, char *b, int c);
#endif

#if defined(__MINGW32__)
	#undef WIN32

	/* #define assert("inside __MINGW32__" == 0) */

	#if defined(WIN32)
		/* #if (defined(WIN32) && ! defined(__CYGWIN__)) */
		#define assert("inside W32 defined" == 0)
	#endif

	/* missing from rpcgen generated form_x.h on CygWin: */
	#define bool_t int


  /*
     #define __WIN32__ 1
     #define __GNUC__ 3
     #define __VERSION__ "3.2 (mingw special 20020817-1)"
   */
   
	#include <limits.h> /* SHRT_MIN SHRT_MAX    */
   
#endif

#if (defined(__MACH__) && defined(__APPLE__))

	#define __DARWIN__

	#define bool_t int
	#define	enum_t	int

#endif

#ifdef __sun__
#include <limits.h>
#endif

#include "a4gl_memhandling.h"
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

#define AUBIT_ATTR_NORMAL     		0x0
#define AUBIT_ATTR_REVERSE    		0x01000
#define AUBIT_ATTR_UNDERLINE  		0x02000
#define AUBIT_ATTR_BOLD       		0x04000
#define AUBIT_ATTR_BLINK      		0x08000
#define AUBIT_ATTR_DIM        		0x10000
#define AUBIT_ATTR_INVISIBLE   		0x20000
#define AUBIT_ATTR_ALTCHARSET  		0x40000
#define AUBIT_ATTR_LEFT  		0x80000

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
/*
#define A4GLKEY_ENTER 		0xff01
*/
#define A4GLKEY_ENTER 		13
#define A4GLKEY_DOWN 		2001
#define A4GLKEY_UP 		2000
#define A4GLKEY_LEFT 		2002	
#define A4GLKEY_RIGHT 		2003
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

#define A4GLKEY_EVENT  		2017
#define A4GLKEY_SYNC  		2018

#define A4GLKEY_ACCEPT 		2016
#define A4GLKEY_DELETE		2015
#define A4GLKEY_INSERT		2014
#define A4GLKEY_HELP		2008
#define A4GLKEY_NEXT		0xff24
#define A4GLKEY_NEXTPAGE	2005
#define A4GLKEY_PREV		0xff26
#define A4GLKEY_PREVPAGE	2006
#define A4GLKEY_INTERRUPT	2011
#define A4GLKEY_START_OF_FIELD  2019
#define A4GLKEY_END_OF_FIELD    2020
#define A4GLKEY_FIELD_CLICKED 	2021


#define A4GLKEY_CANCEL 		0xfffe

#define A4GLKEY_F(x) 		(3000+x-1)

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
#define FNAMESIZE 		1024
#define MAXSCREENRECS 	32
#define MAXCONSTANTS 	1024

  /* ==== pointer "types" (to distinguish between dictionaries) ==== */
  /* Lines commented as //unused? contains defs that seems to
     be unused anywhere in "aubit4glsrc" */
#define RUNTIME_MAPPED_TNAME	'n'
  /* pointer type defs from a4gl_pointers.h */
#define PANCODE 		'1'
#define WINCODE 		'2'
#define CURCODE 		'3'
//#define PRECODE 		'4'
//#define PRECODE_R 		'5'
#define FORMCODE 		'7'
#define S_WINDOWSCODE 		'8'
#define S_FORMDETSCODE 		'9'
#define SESSCODE 		'A'
#define RPC_FUNC 		'B'
#define ATTRIBUTE 		'C'
#define DROPSHADOW 		'D'
#define COMPILED_FORM 		'E'
#define MESSAGEWIN 		'F'
//unused? #define PTR_ATTRIBUTE 		'G'
#define COMPILED_FORM_PACKER 	'H'
#define COMPILED_FORM_FORMTYPE 	'I'
#define DYNMEMALLOC 		'J'
#define STR_RESOURCE_VAL 	'K'
#define LOG_TEMP_TABLE		'O'
#define RECALL_LOG_ENTRIES	'W'
//unused? #define GOTO_USED		'Z'
#define FEATURE_USED		'X'
#define TAB_COL_IS_SERIAL	'g'
#define LAST_STRING_EXPR       'V'
#define LAST_STRING		'T'
#define LAST_STRING_START	'U'

#define CURSOR_USED             'c'
//unused? #define CURSOR_BIND_I           'i'
#define CURSOR_BIND_O           'o'
#define PREPARE_USED            'p'
#define PREPARE_PRINTED         'r'
//unused? #define TMP_USED                't'
#define FUNCTION_IGNORE         'f'
#define EMULATE_CURRENT_OF      'u'
//unused? #define ARRAYS_OF_RECORD        'a'
//unused? #define SCHEMA_FILE_INDEX       'x'
#define FUNC_POINTER            ';'
#define FIELDOPTS            	'{'
#define USERPTR            	':'
#define MEMEXTRA            	'y'
#define HASREQUIREMENT        	'%'
#define PREPAREPG        	'|'
#define HARU_IMAGE        	'h'

#define BLOCK_USED		'R'
#define ESQL_CURSOR_OPEN		'Y'
int A4GL_ESQL_cursor_is_open(char *s) ;
void A4GL_ESQL_set_cursor_is_open(char *s) ;
void A4GL_ESQL_set_cursor_is_closed(char *s) ;


/* 
 * these seem to be used only in lib/extra_libs/channel - 
 * but we need to ensure they are not used elsewhere
*/

#define CHANNEL_IN		'L'
#define CHANNEL_OUT		'M'
#define CHANNEL_DELIM		'N'
#define CHANNEL_PIPE		'P'




#define ACLFGLI_STR_TO_ID		'S'
  /* pointer type defs from sql.c and mysql.c */
#define CACHE_COLUMN '&'
  /* pointer type defs from sqlconvert.c */
#define SQL_CONVERSION '@'
//#define SQL_CONVERSION_CNT '&' // conflicts with CACHE_COLUMN,
	  			 // so I changed this one to #
#define SQL_CONVERSION_CNT '#'
  /* pointer type defs from a4gl_ui.h.*/
#define RES_PANEL 	1
#define RES_ACLWINDOW 	2
#define RES_CURSWINDOW 	3
#define RES_ACLFORM 	4


  /* ========================= from a4gl_ui.h ====================== */
#define DESCLENGTH 		10
#define nalloc(x) 		acl_malloc2(sizeof(x))
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

#define MENU_COMPARE_SHOWHIDE 1
#define MENU_COMPARE_NEXT_OPTION 2

  /* Datasave */
#define DATAVER 		1

#define NOTFOUND 		1
#define WRONGVER 		2
#define BADFILE 		3
#define NOWRITE 		4
#define BADWRITE 		5

#define STREQL(a,b) 	(strcmp(a,b)==0)
#define STRNEQ(a,b) 	(strcmp(a,b)!=0)
#define STRIEQ(a,b) 	(A4GL_aubit_strcasecmp(a,b)==0)
#define STRINEQ(a,b) 	(A4GL_aubit_strcasecmp(a,b)!=0)

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
#define DTYPE_NULL	9
#define DTYPE_DTIME     10
#define DTYPE_BYTE      11
#define DTYPE_TEXT      12
#define DTYPE_VCHAR     13
#define DTYPE_INTERVAL  14
#define DTYPE_NCHAR  15
#define DTYPE_INT8         17
#define DTYPE_SERIAL8      18

#define DTYPE_OBJECT    99
#define DTYPE_DYNAMIC_ARRAY      98
#define DTYPE_REFERENCE    97

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

#ifdef DOING_CM
#include <stdio.h>
#include "cm.h"
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

	#include <stdio.h>			/* needed for FILE symbol */

	#ifndef WIN32
		#include <string.h>
	#endif
	#include <stdlib.h>			/* free() */


	#if HAVE_SEARCH_H && ! defined(__MINGW32__)
		/* MinGW 3.1.0 introduced search.h, but it's not complete */
		#include <search.h>		/* VISIT-used in pointers.c */

	#else
	
		/* search internal node for windows and platforms without this 
		library function (like Darwin) */
	
		typedef struct entry
		{
		  char *key, *data;
		}
		ENTRY;
		
		typedef enum
		{ FIND, ENTER }
		ACTION;
		
		/*
		//why is this line commented out?
		//void A4GL_action (const void *nodep, const VISIT which, const int depth);
		*/
		
		/** A node tree information */
		typedef struct node_t
		{
		  char *key;
		  struct node_t *left, *right;
		}
		node;
	
		/* TSEARCH(3C) - The type of the visit made to an element of the tree */	
		node *tsearch (char *key, node ** rootp, int (*compar) (const void *l,const void *r));
		node *tdelete (char *key, node ** rootp, int (*compar) (const void*l,const void *r));
		void twalk (node * root, void *act);
		node *tfind (char *key, node ** rootp, int (*compar) (const void*l,const void *r));
		
		  /* For tsearch */
		  typedef enum
		  {
			preorder,
			postorder,
			endorder,
			leaf
		  }
		  VISIT;

#ifdef MAYBE_INVALID 
/*----------------- moved from pointers.c */
	#if defined(__MINGW32__)
		/* why was this line commented out? BECAUSE IT'S DEFINED IN 
		incl/a4gl_libaubit4gl.h
		F***! New version of MinGW needs this enabled, but old one
		needs it commented OUT. FIND OUT WHY!
		
		On new MinGW, if commented out, error is:
		pointers.c:142: parse error before "which"
		
		On old MinGW (gcc 3.2) , if not commented out, error is:
		pointers.c:122: conflicting types for `preorder'
		a4gl_libaubit4gl.h:483: previous declaration of `preorder'
		pointers.c:122: conflicting types for `postorder'
		a4gl_libaubit4gl.h:484: previous declaration of `postorder'
		pointers.c:122: conflicting types for `endorder'
		a4gl_libaubit4gl.h:485: previous declaration of `endorder'
		pointers.c:122: conflicting types for `leaf'
		a4gl_libaubit4gl.h:487: previous declaration of `leaf'
		pointers.c:122: redefinition of `VISIT'
		a4gl_libaubit4gl.h:488: `VISIT' previously declared here
		*/
		#if defined (__GNUC__) && defined (__GNUC_MINOR__)
			/*
			// Do a 'make gcc_symbols' in aubit source root to see what 
			//current compiler defines
			//&& defined (__VERSION__) && (__VERSION__ "3.2 (mingw special 20020817-1)")
			//#define __VERSION__ "3.2.3 (mingw special 20030504-1)"
			*/
			#if (__GNUC__ == 3)
				/*#if (__GNUC_MINOR__ >= 3) */
				#if (__GNUC_MINOR__ >= 2)
 					typedef enum { preorder, postorder, endorder, leaf } VISIT;
				#endif
			#endif
		#endif
	#endif
/*------------------------------------	  */
#endif	  
	  
	#endif

	#include <assert.h>		/* assert() */
	#include <time.h>
	#include <math.h>		/* pow() */
	#include <locale.h>		/* setlocale() */
	
	/*
	//on CygWin cause conflicts with glib-2.0/glib/gwin32.h
	// with g_win32_ftruncate
	*/

#ifndef MSVC
	#include <unistd.h>		/* sleep() close() write() usleep() */
#endif
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

#endif /* _NO_SYSINCL_ */


#ifdef USE_ZZIPLIB

	/*#define FILE ZZIP_FILE */
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

#ifndef DOING_CM
#ifndef GETENV_OK
#define getenv(s)	assert("Do not use getenv() - use acl_getenv() instead" == 0)
#endif

#ifndef WGETENV_OK
#define wgetenv(s)	assert("Do not use wgetenv() - use acl_getenv() instead" == 0)
#endif
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


struct s_module_error {
        int lineno;
        char *err_str;
};


struct s_pass_reference {
	void *bytes;
	int nbytes;
};


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
  int A4GL_edit (char *string, char type, int length, int x, int y);
  int A4GL_check_type (char c, char type, int flg, int len);
  int A4GL_ask_int (char *prompt);	/*  prompt for an integer from user  */
  double A4GL_ask_dbl (char *prompt);	/*  prompt for an integer from user  */
  double get_now_as_double(void);
	char *A4GL_get_username(void);
  int A4GL_ask_verify (char *prompt);	/*  prompt for verification  */
  unsigned int getcursor (void);	/* Returns the shape of the current cursor */
  void A4GL_strip_nl (char *str);
int A4GL_readkey(void);

/*
char *A4GLSQLCV_generate_current(char *from,char *to) ;
int A4GLSQLCV_check_requirement(char *s) ;
char *A4GLSQLCV_check_colname(char *tabname,char *colname) ;
char *A4GLSQLCV_matches_string(char *str,char *esc) ;
char *A4GLSQLCV_make_substr_s(char *colname,int n, char *l,char *r) ;
char *A4GLSQLCV_make_substr(char *colname,int nints,int i1,int i2) ;
*/



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
    int run_ui_mode;
    int pipe_ui_mode;
    char *inpattr_s;
    char *dispattr_s;
  };

struct s_std_attr
{
  int colour;

  int reverse;
  int underline;
  int bold;
  int dim;
  int blink;
  int invisible;

  int normal;
  int help_no;
};

#define MAX_RECALL_VALUES 100
  struct s_recall_entry {
	  	char *recall_value;
		struct s_recall_entry *next;
		struct s_recall_entry *prev;
  };

  struct s_recall_list {
	  struct s_recall_entry *first;
	  struct s_recall_entry *last;
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
    {"nchar", DTYPE_NCHAR, 0, 0},
    {"int8", DTYPE_INT8, 0, 0},
    {"serial8", DTYPE_SERIAL8, 0, 0},
    {0, 0, 0, 0}
  };
#else
  extern struct s_typenames def_dtypes[];
#endif


  /* ==================== from incl_4glhdr.h ========================= */

  /* not strictly voids - but saves getting into the details */
  void *prepare_glob_sql (char *s, int ni, void *b);
void A4GL_set_sql_lineno(int n);
char *
A4GLSQL_translate (char *sql1);



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
	FGL_CMD_DISPLAY_CMD,  /* DISPLAY / DISPLAY @ */
	FGL_CMD_DISPLAY_FIELD_CMD,  /* DISPLAY TO, DISPLAY BY NAME */
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
  void A4GL_set_lasterrorstr(char *s);


#ifndef ALREADY_DONE_POP_PUSH_ETC
  void A4GL_debug_full (char *fmt, ...);
  void A4GL_debug_full_extended (char *fmt, ...);
  void A4GL_debug_full_extended_ln (char *s, long l, const char *level, const char * func, char *fmt, ...);
  int A4GLSTK_isStackInfo (void);
  char *acl_getenv (char *);
  char * acl_getenv_not_set_as_0 (char *s);
  char *A4GLSTK_getStackTrace (void);
  void A4GLSTK_pushFunction (const char *functionName, char *params[], int n);
  char *A4GLSTK_topFunction(void);
  void A4GLSTK_popFunction (void);
  void A4GL_pushop (int a);
  void A4GL_chk_err (int lineno, char *fname);
  void A4GL_err_continue_log (int lineno, char *fname);

  void A4GL_push_bind_reverse (struct BINDING *b, int n, int no, int elemsize);
  void A4GL_push_bind (struct BINDING *b, int n, int no, int elemsize);
  void A4GL_push_null (int dtype,int size);
  char *a4gl_substr (char *s, int dtype, int a, int b, ...);
  int A4GL_set_line (char *s, long l);
  int A4GL_set_line_extended (char *s, long l, const char *level, const char * func);
  char *get_bind_varname(char i,int n);
  int A4GL_pop_bool (void);
  short A4GL_pop_int (void);

  int8 A4GL_pop_int8 (void);
  int A4GL_push_int8 (int8 a);

  long A4GL_pop_long (void);
  long A4GL_pop_date (void);
  float A4GL_pop_float (void);
  double A4GL_pop_double (void);
  double A4GL_pop_double_null_as_zero(void);
  void A4GL_pop_doubleinto (double *ptr);
  void A4GL_pop_into_double_null_as_zero(double *d );
  void A4GL_pop_into_double (double *d);
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
  void A4GL_fgl_end_4gl_1 (void); /* Used on interrupt */
void A4GL_set_last_cursor(int n);
  void A4GL_display_at (int n, int a);
  void A4GL_push_dtime (struct A4GLSQL_dtime *p);
  void A4GL_push_int (short p);
  void A4GL_push_long (long p);
  void A4GL_push_date (long p);
  void A4GL_push_float (float p);
  void A4GL_push_dec (char *p, int ismoney,int size);
  void A4GL_push_dec_dec (fgldecimal *p, int ismoney,int size);
  void A4GL_push_double (double p);
  void A4GL_push_chars (char *p, int dtype, int size);
  void A4GL_push_char (char *p);
  void A4GL_push_empty_char(void);
  void A4GL_push_variable (void *ptr, int dtype);
  void A4GL_push_interval (struct ival *p,int size);
  void A4GL_pop_args (int a);
#endif



  double A4GL_ret_var (void *p, int d);

  int A4GL_opboolean (void);
  void A4GL_debug_print_stack (void);
  void print_stack (void);
#ifndef LOCATE_VAR_DEFINED
#define LOCATE_VAR_DEFINED
  void A4GL_locate_var (struct fgl_int_loc *p, char where, char *filename);
#endif

  void A4GL_whats_in_a_string(char *s,int *d,int *sz);


int A4GL_isblank(int n) ;
int A4GL_GetNumberOfComments(void);
int aclfgl_fgl_compare(int n);
int aclfgl_fgl_setcurrline(int n);
int aclfgl_fgl_dialog_setcursor(int n) ;
int aclfgl_fgl_dialog_getcursor(int n) ;
int aclfgl_fgl_username(int n);
int aclfgl_aclfgl_get_stack_trace(int n);
int aclfgl_aclfgl_get_sql_requirement(int n);
int aclfgl_fgl_round(int nargs);
int aclfgl_aclfgl_flushinp (int n);
int aclfgl_aclfgl_embed_barcode (int _nargs);
int aclfgl_aclfgl_send_to_ui(int _nargs);
int aclfgl_aclfgl_client_set(int _nargs);
int aclfgl_aclfgl_client_execute(int _nargs);
int aclfgl_aclfgl_sendfile_to_ui(int _nargs);
int aclfgl_aclfgl_getclientfile(int _nargs);


void A4GL_convert_to_pdf_x (void);
void A4GL_convert_to_pdf_y (void);
size_t A4GL_base64_decode (const char *src, unsigned char **outptr);

int aclfgl_aclfgl_get_construct_element(int n) ; /* Gets a construct style string for a table/column for the specified value of the specified type/length, called in 4gl as : 
							call aclfgl_get_construct_element(tabname,colname,value,dtype,dtype_length) returning lv_str
						 */
		



	int A4GL_set_a4gl_sqlca_errd(int n,int v);
	int A4GL_set_a4gl_sqlca_sqlstate(char *s);
  int A4GL_pushint_fgl_infield (void *inp,char itype,...);
  void fgl_fatal(char *mod,long ln,long stat);


#define GETSETNEW 		-1
#define GETSETRM 		-2
#define GETSETGET 		1
#define GETSETSET 		2
#define GETSETGETPTR 	3

#define GETPTR(struct,ptr,element) A4GL_get_set(struct,ptr,GETSETGETPTR,element,0)
#define GET(struct,ptr,element) A4GL_get_set(struct,ptr,GETSETGET,element,0)
#define GET_AS_INT(struct,ptr,element) A4GL_get_set_as_int(struct,ptr,GETSETGET,element,0)

#define SET(struct,ptr,element,value) A4GL_get_set(struct,ptr,GETSETSET,element,(long)value)
#define NEW(struct) A4GL_get_set(struct,0,GETSETNEW,0,0)
#define RM(struct,ptr) A4GL_get_set(struct,ptr,GETSETRM,0,0)

#include "a4gl_rep_structure.h"
void A4GL_get_current_pdf_x(struct pdf_rep_structure *rep) ;
void A4GL_get_current_pdf_y(struct pdf_rep_structure *rep) ;


void A4GL_cleanup_undeleted_files(void);




#define REP_TYPE_NOTSET 			0
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
#define REPORT_CONVERT -16
#define REPORT_FREE    -17
#define REPORT_NOTHING    -20
#define REPORT_TERMINATE 			-9999


int A4GL_via_functionname(char *repname,void *vr,void *vfunction) ;
void* A4GL_get_curr_report(void) ;
void A4GL_set_curr_report(void *c) ;
char *A4GL_get_pdf_encoding(void) ;

#define ERR_BADNOARGS 			1000
#define ABORT 					1
#define WARN 					2



// Don't confuse the A4GL_debug prototype with the function thats normally used 
// for logging debug messages throughout the code
// here we're just defining a function to call that will
// complain that A4GL_debug_full hasn't been called...
//
// Because the #define that follows will map A4GL_debug to A4GL_debug_full
// we should *never* really be calling a function called 'A4GL_debug'....
void A4GL_debug(char *s); 

/*
#ifndef NODEBUG
#define A4GL_debug A4GL_set_line(__FILE__,__LINE__),A4GL_debug_full
#else
#define A4GL_debug null_func
#endif
*/

#ifndef NODEBUG

#if __STDC_VERSION__ < 199901L
# if __GNUC__ >= 2
#  define __func__ __FUNCTION__
# else
#  define __func__ "<unknown>"
# endif
#endif


#define A4GL_ftl(fmt,...) A4GL_debug_full_extended_ln(__FILE__,__LINE__,"FTL",__func__, fmt,## __VA_ARGS__)
#define A4GL_err(fmt,...) A4GL_debug_full_extended_ln(__FILE__,__LINE__,"ERR",__func__, fmt,## __VA_ARGS__)
#define A4GL_wrn(fmt,...) A4GL_debug_full_extended_ln(__FILE__,__LINE__,"WRN",__func__, fmt,## __VA_ARGS__)
#define A4GL_inf(fmt,...) A4GL_debug_full_extended_ln(__FILE__,__LINE__,"inf",__func__, fmt,## __VA_ARGS__)
#define A4GL_dbg(fmt,...) A4GL_debug_full_extended_ln(__FILE__,__LINE__,"dbg",__func__, fmt,## __VA_ARGS__)
#define A4GL_debug A4GL_dbg


#ifdef DEBUG
#define A4GL_trc(fmt,...)  A4GL_set_line_extended(__FILE__,__LINE__,"trc",__func__),A4GL_debug_full_extended
#else 
#define A4GL_trc(fmt,...)
#endif 

#else 
#define A4GL_ftl(fmt,...)
#define A4GL_err(fmt,...)
#define A4GL_wrn(fmt,...)
#define A4GL_inf(fmt,...)
#define A4GL_dbg(fmt,...)
#define A4GL_trc(fmt,...)

#endif 

  /* ====================== from data_if.c =================== */

  void *A4GL_get_set (char *str, void *ptr, int mode, char *name, long var);
  int A4GL_get_set_as_int (char *str, void *ptr, int mode, char *name, long var);


  /* ===================== from builtin.c =================== */

  int A4GL_fgl_fieldtouched (void *i,char itype, ...);
  void A4GL_close_database (void);

/* These two need a4gl in lower case... */
  char *a4gl_let_substr (char *ca, int dtype, int a, int b, ...);


  void A4GL_include_builtin_in_exe (void);
  void A4GL_set_scr_line (int a);
  void A4GL_set_arr_curr (int a);
  //int A4GL_get_count (void);
  void A4GL_set_arr_count (int a);
  int aclfgl_dbms_dialect (int n);
  void aclfgli_extend (void);


  /* ======================= From buildtin_d.c ==================== */


  int A4GL_func_clip (void);
  void A4GL_func_concat (void);
  void A4GL_func_using (void);
void a4gl_using_from_string (char *str, int s, char *fmt, char *numeric,int isneg);
void A4GL_push_decimal_str(char *p);
  int A4GL_find_function (char *a);
  double A4GL_power (double a, double b);

  /* ============================ resource.c ============================= */
  struct str_resource
  {
    char name[80];
    char value[1024];		/*must be long enough to hold GTK include paths */
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
  /* void A4GL_trim (char *p); */
  void A4GL_bnamexxx (char *str, char *str1, char *str2);
  void A4GL_pad_string (char *ptr, int size);
  void acl_free_With_Context(void *ptr);
  void *acl_malloc2_With_Context(long size);
  char *acl_strdup_With_Context(void *a);
  void *acl_realloc_With_Context(void *a,long b);
  void *A4GL_current_malloc_context(void);
  void *A4GL_get_malloc_context(void);

  /*void acl_free_full (void *ptr, char *f, long line); */
  void a4gl_using (char *str, int s, char *fmt, double num);
  int A4GL_digittoc (int *a, char *z, char *fmt, int dtype, int size);
  void A4GL_strmaxcpy(char *dest,char *src,int max);
  void A4GL_logsql(int lineno,char *module, char *s);


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
  int A4GL_get_errcode_for_errstr (char *s);
  void A4GL_exitwith (char *s);
  void A4GL_exitwith_sql (char *s);
  void A4GL_set_errm (char *s);
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




  char *A4GL_params_on_stack (char *_paramnames[], int n);
  int A4GL_isnull (int type, char *buff);
  /* void A4GL_setnull (int type, void *buff, int size); */
  char *A4GL_lrtrim (char *z);
  void A4GL_get_top_of_stack (int a, int *d, int *s, void **ptr);
  void A4GL_drop_param (void);
  void A4GL_init_blob (struct fgl_int_loc *p);
  int A4GL_read_param (void *p, int d, int size, int c);
  int A4GL_conv_to_interval (int a);
  int A4GL_chknull_boolean (int n, int n1, int n2,int d1,int d2);
  int A4GL_chknull (int n, int n1, int n2,int d1,int d2);
  void A4GL_cast_top_of_stack_to_dtype(int dtype) ;


  /* ============================ calldll.c ============================== */
  void *A4GL_dl_openlibrary (char *type, char *name);
  void *A4GL_find_func_allow_missing (void *dllhandle, char *func);
  void *A4GL_find_func (void *dllhandle, char *func);


  /* ============================ conv.c ================================= */
  void A4GL_decode_interval (struct ival *ival, int *data,int *is_neg);
  int A4GL_stod (void *zz, void *aa, int sz_ignore);
  int A4GL_conv (int dtype1, void *p1, int dtype2, void *p2, int size);
  void A4GL_set_convmatrix (int dtype1, int dtype2, void *ptr);
  void A4GL_assertion (int a, char *s);

#define A4GL_assertion(a,b) A4GL_assertion_full(a,b,__FILE__,__LINE__)
void A4GL_assertion_full (int a, char *s, char *mod, int ln);
int A4GL_stodec (void *a, void *z, int size);
int A4GL_stol (void *aa, void *zi, int sz_ignore);
int A4GL_valid_int (char *s, int *data, int size);


  /* ============================ fglwrap.c ============================== */
  //int A4GL_fgl_error (int a, char *s, int err, int stat);
  int A4GL_isyes (char *s);
  int A4GL_isno (char *s);
  char *get_serno (void);
  void A4GL_set_abort (int a);
  void A4GL_check_and_show_id (char *program, char *arg1);
char *A4GL_get_running_program(void);
int A4GL_sock_write_int (char *buf, size_t count);

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
  FILE * A4GL_open_file_dbpath_plus_path (char *fname, char*pluspath,char *usedFilePath);
  char *A4GL_fullpath_dbpath_plus_path(char *fname, char *plus );

  char *A4GL_fullpath_dbpath (char *fname);

  /* ========================== match.c ================================== */
  int A4GL_aubit_strcasecmp (char *a, char *b);
  int A4GL_matche (register char *p, register char *t,char m,char s,char b); /* m=multi s=single b=brace eg '*' '?' '[' */

  /* =========================== gui.c =================================== */
  int A4GL_isgui (void);
  void A4GL_proc_it (char *buff);
  int A4GL_get_gui_char (void);
  void A4GL_gui_actmenu (long ld);



long a4gl_htonl(long x);
long a4gl_ntohl(long x);


short a4gl_htons(long x);
short a4gl_ntohs(long x);



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
  char *A4GL_construct (char *tabname,char *colname, char *val, int inc_quotes,int dtype,int dtype_size,void *callback_function);


  /* =========================== stack.c ================================ */


  struct bound_list
  {
    struct BINDING *ptr;
    int cnt;
    int popped;
  };

  void *dif_get_bind (struct bound_list *list);
  void *dif_start_bind (void);
int A4GL_conversion_ok(int a);

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

#ifndef NO_FGL_X /* Used to suppress reading these files when not required */
#ifndef SIMPLIFIED
 #include "../common/dataio/form_x.x.h"        /* struct_form */
 #include "../common/dataio/fgl.x.h"        /* struct_form */
#else
 #include "form_x.x.h"       /* struct_form */
 #include "fgl.x.h"
#endif
#endif

#endif






#ifndef _NO_FORM_X_H_		/* if we don't include form_x.h, this would generate errors : */
  int A4GL_find_srec (struct struct_form * fd, char *name);
  /* struct struct_scr_field defined in fcompile/form_x.h */
  int A4GL_has_str_attribute (struct struct_scr_field *f, int str);
  int A4GL_attr_name_match (struct struct_scr_field *field, char *s);
  char *A4GL_get_str_attribute (struct struct_scr_field *f, int str);
int A4GL_evaluate_field_colour(char *field_contents, struct struct_scr_field *fprop);
#endif
  void A4GL_set_last_key (int a);
  char *A4GL_strip_quotes (char *s);
  void A4GL_convlower (char *s);
  int A4GL_get_lastkey (void);
  FILE * A4GL_open_file_classpath (char *fname);

  /* ============================ io.c =================================== */
  void A4GL_bname (char *str, char *str1, char *str2);

  /* ============================ keys.c ================================= */
  int A4GL_key_val (char *str);
  int A4GL_is_special_key(int k, int type);
  int A4GL_check_keys (int val, char *str2);
  int A4GL_check_key (int val, char *a, int ln);


int A4GL_get_dbscr_commentline(void) ;
int A4GL_get_dbscr_formline(void);
int A4GL_get_dbscr_errorline(void);
int A4GL_get_dbscr_promptline(void);
int A4GL_get_dbscr_messageline(void);
int A4GL_get_dbscr_menuline(void);
int A4GL_get_dbscr_inputmode(void);
int A4GL_get_ccnt(void);
void A4GL_set_ccnt(int a);


  /* ============================ pointers.c ============================= */
  int A4GL_has_pointer (char *pname, char t);
  void A4GL_add_pointer (char *orig_name, char type, void *ptr);
  void A4GL_del_pointer (char *pname, char t);
  int A4GL_find_pointer_ptr (char *name, char *type, void *ptr);
  void *A4GL_find_pointer_val (char *pname, char t);

  /* ============================ screen.c =============================== */
  //int A4GL_screen_mode (int a);

  /* ============================ maths.c ================================ */
  void *A4GL_find_op_function (int dtype1, int dtype2, int op);

// Andrej commented out the ifdef, since proto is needed in all cases 
// "CSCC" = CSCC compiler (gnu portable .net)
//#ifdef CSCC
	void A4GL_add_op_function (int dtype1, int dtype2, int op, void (*function)(int ops));
	/* 
	compiling report.xi.c :
	In file included from report.xi.c:2:
	/opt/aubit/aubit4glsrc/incl/a4gl_libaubit4gl.h:1585: parse error before `function'
	
	problem here is that in (for example) common/dataio/report.x 
	contains struct called "function":
	
		struct function {
		char * name;
		};
		typedef struct function function;
	
	renamed it to a4gl_report_function
	
	
[root@aptiva aubit4glsrc]# find . -name "*.c" -exec grep -H "struct function" {} \;
./compilers/ace/data.c:      this_report.functions.functions_len * sizeof (struct function));

	*/
	
//#endif

  /* ============================ translate.c ============================ */

  void A4GL_dumpstring (char *s, long n, char *fname);


  void A4GL_set_a4gl_status (int a);
  int A4GL_get_a4gl_status (void);
  void A4GL_set_a4gl_sqlca_sqlcode (int a);
  int A4GL_get_a4gl_sqlca_sqlcode (void);

  /* ========================== from a4gl_screen.h ==================== */


  /* 4gl program controls */
enum e_formcontrol {
FORMCONTROL_BEFORE_FIELD=1,
FORMCONTROL_AFTER_FIELD =2,
FORMCONTROL_BEFORE_INPUT=3,
FORMCONTROL_AFTER_INPUT =4,
FORMCONTROL_EXIT_INPUT_OK=5,
FORMCONTROL_EXIT_INPUT_ABORT=6,
FORMCONTROL_KEY_PRESS=7,
FORMCONTROL_BEFORE_INSERT=8,
FORMCONTROL_BEFORE_DELETE=9,
FORMCONTROL_AFTER_INSERT =10,
FORMCONTROL_AFTER_DELETE =11,
FORMCONTROL_BEFORE_ROW =12,
FORMCONTROL_AFTER_ROW =	13,
  /* formloop controls ? Don't know if we need these yet... */
FORMCONTROL_REQUEST_FIELD,
FORMCONTROL_ENABLE_FIELD,
FORMCONTROL_DISABLE_FIELD,
FORMCONTROL_HIDE_FIELD
};

#define REQUIRED_TYPE_UNSET -1
#define REQUIRED_TYPE_FIELD 0
#define REQUIRED_TYPE_INPUT 1
int A4GL_input_required_handling(void) ;

  struct s_formcontrol
  {
    enum e_formcontrol op;
    char *parameter;
    char *field_name;
    int field_number;
    int state;
    int extent;
    void *field;
  };



#include "a4gl_screenio.h"
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
    char *curr_display;
    int start_slice;
    int end_slice;
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

	/* Slice handling */
    int start_slice;
    int end_slice;
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
	void *label;
  };

  int A4GLSQL_load_data (char *fname, char *delims, void*filterfunc, char *tabname, ...);
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
  void A4GL_make_downshift(char* s);

  /* ============================ read_dty.c ============================= */
  int A4GL_get_dtype (char *tabname, char *colname, char *dbname, char *tablist[]);
	char * A4GL_get_found_in_tab(void);

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
    int attrib_str;
  };

#define MAX_FORM_FIELDS 4096


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
    void *form_fields[MAX_FORM_FIELDS];
    void *currentfield;
  };

  /* ============================ errfile.c =============================== */
  void A4GL_write_cont (FILE * f);

  /* =========================== dataio.c ============================= */
  int A4GL_read_data_from_file (char *datatype, void *ptr, char *filename);
  int A4GL_write_data_to_file (char *datatype, void *ptr, char *filename);
int A4GL_read_data_from_file_generic (char *package, char *datatype, void *ptr, char *filename);
int A4GL_write_data_to_file_generic (char *package, char *datatype, void *ptr, char *filename);



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
A4GLSQL_load_data_str (char *fname, char *delims, void *filterfunc, char *sqlstmt);
void
A4GL_in_in_ops (int op);
int
A4GL_get_escape_chr (void);
int A4GL_determine_attribute(int cmd_type, int attrib_curr_int, void *fprop,char *val_for_field);
void
a4gl_basename (char **ppsz);
void
A4GL_error_nobox (char *str,int attr);
void
A4GL_clr_error_nobox (char *dbg_fromwhere);
void A4GL_core_dump(void);
void
A4GL_set_core_dump (void);
char *A4GL_null_as_null(char *s);
int A4GL_has_errorlog (void);
#ifdef CSCC
	/*int A4GL_add_datatype_function_i (int a, char *funcname, void (*function)(int)); */
#else
	int A4GL_add_datatype_function_i (int a, char *funcname, void *func);
#endif
void A4GL_close_errorlog_file (void);
void A4GL_set_last_outfile (char *s);
void A4GL_ltrim(char *s) ;
void A4GL_fgl_die(int n);
fgldecimal *A4GL_init_dec (fgldecimal *s, int len, int d);
//char *A4GL_str_to_dec (char *s, fgldecimal *w);
char *A4GL_dec_to_str (fgldecimal *dec, int size) ;

fgldecimal *A4GL_str_to_dec (char *str_orig, fgldecimal *dec);

//int A4GL_call_4gl_dll (char *filename, char *function, int args);
void A4GL_process_stack_op_other (int d);
void *A4GL_pop_binding (int *n);
int A4GL_push_binding (void *ptr, int num);
int A4GL_stof (void *aa, void *zz, int sz_ignore);
int A4GL_nullfunc (void);
int A4GL_chk_params (struct BINDING *b, int nb, struct BINDING *o, int no);
char *A4GLSQLCV_generate_ins_string(char *current_ins_table,char *s,  int is_select_into);
void A4GLSQLCV_load_convert (char *source_dialect, char *target_dialect) ;
char *A4GLSQLCV_get_forupdate (char *collist);
char *A4GLSQLCV_check_sql(char *s ,int *converted) ;
char *A4GLSQLCV_dtype_alias(char *s ) ;
char *A4GLSQLCV_check_expr(char *s ) ;
char *A4GLSQLCV_sql_func(char *f,char *param);
char *A4GLSQLCV_select_into_temp(char *sel,char *lp,char *tabname);
char *A4GLSQLCV_create_temp_table(char *tabname,char *elements,char *extra,char *oplog);
char *A4GLSQLCV_check_tablename(char *t) ;
char *A4GLSQLCV_make_tablename(char *t,char *c) ;
char *A4GLSQLCV_ownerize_tablename(char *owner, char *table);
char *A4GLSQLCV_db_tablename(char *dbname, char*instance, char*ownerized_tablename );


void A4GL_add_feature(char *s);
char *A4GLSQLCV_get_sqlconst(char *cval);
char *A4GLSQLCV_generate_current(char *from,char *to) ;
int A4GLSQLCV_check_requirement(char *s) ;
char *A4GLSQLCV_check_colname(char *tabname,char *colname) ;
char *A4GLSQLCV_matches_string(char *not,char *str,char *esc) ;
//char *A4GLSQLCV_make_substr_s(char *colname,int n, char *l,char *r) ;
//char *A4GLSQLCV_make_substr_s(char *colname,int n, struct expr_str *l,struct expr_str *r) ;
char *A4GLSQLCV_make_substr(char *colname,int i0,int i1,int i2) ;
char *A4GLSQLCV_make_ival_extend(char *ival,char *from,char *from_len,char *to,int extend) ;
char *A4GLSQLCV_make_dtime_extend(char *dval,char *from,char *to,int extend) ;
char *A4GLSQLCV_datetime_value(char *s) ;
char *A4GLSQLCV_interval_value(char *s) ;
void A4GLSQLCV_check_fullpath(char *s)  ;
char *A4GLSQLCV_rencol(char *tabname,char *colname,char *ncolname) ;
char *A4GLSQLCV_rentab(char *tabname,char *ntabname) ;






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
void A4GL_gen_field_slist( struct s_field_name_list *list, va_list *ap);

int A4GL_menu_opts_compare(char *a,char *b,int why);
int A4GL_menu_hide (ACL_Menu * menu, ...);
int A4GL_menu_show (ACL_Menu * menu, ...);
int A4GL_is_unique_menu_key (ACL_Menu * menu, int key);
char *A4GL_show_menu_large_get_matches(ACL_Menu *menu, char *typed_portion, int width, int *pcnt, ACL_Menu_Opts **uniq) ;
void A4GL_set_scrmode (char a);
int A4GL_isscrmode (void);
int A4GL_islinemode (void);
int A4GL_disp_form_fields (int n, int attr, char *formname, ...);
int A4GL_endis_fields (int en_dis, ...);
int A4GL_disp_arr (void *disp, void *ptr, char *srecname, int attrib,void *evt, ...);
int A4GL_open_gui_form (long *form_variable,char *name_orig, int absolute, int nat, char *like, int disable, void *handler_e, void (*handler_c (int a, int b)));
int A4GL_fgl_infield (void *inp,char itype,...);
int a4gl_toupper(int n);
int a4gl_tolower(int n);


#ifndef NOSTRCPYMAP
#ifndef strcpy
#ifndef strcat
#define strcpy(d,s) A4GL_strcpy(d,s,__FILE__,__LINE__,(long)sizeof(d))
#define strcat(d,s) A4GL_strcat(d,s,__FILE__,__LINE__,(long)sizeof(d))
#endif
#endif
#endif

char *A4GL_strcat  (char *d,char *s,char *fname,int l,int sdest);
char *A4GL_strcpy  (char *d,char *s,char *fname,int l,int sdest);
int A4GL_sprintf (char *f,int l, char *dest,size_t sdest,char *fmt, ...) ;
// When we 'grep' for a printf (often used for debugging) - we'll ignore anything
// using PRINTF (as these are known to not be used for debugging)


#define FPRINTF fprintf
#define VFPRINTF vfprintf

#define SNPRINTF snprintf
#define VSPRINTF vsprintf
#define VSNPRINTF vsnprintf

#ifdef _WIN32
#undef VSNPRINTF 
#undef SNPRINTF

#define HAVE_SNPRINTF 1
#define HAVE_VSNPRINTF 1
#define VSNPRINTF   _vsnprintf
#define SNPRINTF    _snprintf
#endif

#if ((!(HAVE_SNPRINTF)) && (!(HAVE_VSNPRINTF)))
#include "missing/snprintf.h"
#endif


#define PRINTF printf
#define SPRINTF0(s,f)                        	A4GL_sprintf(__FILE__,__LINE__,s,sizeof(s),f)
#define SPRINTF1(s,f,p1)                        A4GL_sprintf(__FILE__,__LINE__,s,sizeof(s),f,p1)
#define SPRINTF2(s,f,p1,p2)                     A4GL_sprintf(__FILE__,__LINE__,s,sizeof(s),f,p1,p2)
#define SPRINTF3(s,f,p1,p2,p3)                  A4GL_sprintf(__FILE__,__LINE__,s,sizeof(s),f,p1,p2,p3)
#define SPRINTF4(s,f,p1,p2,p3,p4)               A4GL_sprintf(__FILE__,__LINE__,s,sizeof(s),f,p1,p2,p3,p4)
#define SPRINTF5(s,f,p1,p2,p3,p4,p5)            A4GL_sprintf(__FILE__,__LINE__,s,sizeof(s),f,p1,p2,p3,p4,p5)
#define SPRINTF6(s,f,p1,p2,p3,p4,p5,p6)         A4GL_sprintf(__FILE__,__LINE__,s,sizeof(s),f,p1,p2,p3,p4,p5,p6)
#define SPRINTF7(s,f,p1,p2,p3,p4,p5,p6,p7)      A4GL_sprintf(__FILE__,__LINE__,s,sizeof(s),f,p1,p2,p3,p4,p5,p6,p7)
#define SPRINTF8(s,f,p1,p2,p3,p4,p5,p6,p7,p8)      	A4GL_sprintf(__FILE__,__LINE__,s,sizeof(s),f,p1,p2,p3,p4,p5,p6,p7,p8)
#define SPRINTF9(s,f,p1,p2,p3,p4,p5,p6,p7,p8,p9)      	A4GL_sprintf(__FILE__,__LINE__,s,sizeof(s),f,p1,p2,p3,p4,p5,p6,p7,p8,p9)
#define SPRINTF10(s,f,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10)	A4GL_sprintf(__FILE__,__LINE__,s,sizeof(s),f,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10)
#define SPRINTF24(s,f, p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,p21,p22,p23,p24)	A4GL_sprintf(__FILE__,__LINE__,s,sizeof(s),f, p1,p2,p3,p4,p5,p6,p7,p8,p9,p10, p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,p21,p22,p23,p24)


#define A4GL_EVENT_BEF_ROW 		-10
#define A4GL_EVENT_AFT_ROW  		-11
#define A4GL_EVENT_BEFORE_DELETE  	-12
#define A4GL_EVENT_AFTER_DELETE  	-13
#define A4GL_EVENT_BEFORE_INSERT  	-14
#define A4GL_EVENT_AFTER_INSERT  	-15
#define A4GL_EVENT_BEF_INSERT_DELETE  	-17
#define A4GL_EVENT_AFT_INSERT_DELETE  	-18


#define A4GL_EVENT_ON_IDLE  		-50
#define A4GL_EVENT_ON_INTERVAL 		-51
#define A4GL_EVENT_ON_TIME 		-52


#define A4GL_EVENT_KEY_PRESS  		-90
#define A4GL_EVENT_ON_ACTION  		-91
#define A4GL_EVENT_AFTER_INP_CLEAN 	-94
#define A4GL_EVENT_AFTER_INP  		-95
#define A4GL_EVENT_BEFORE_FIELD 	-97
#define A4GL_EVENT_AFTER_FIELD 		-98
#define A4GL_EVENT_BEFORE_INP  		-99
#define A4GL_EVENT_BEFORE_FIELD_1 	-197
#define A4GL_EVENT_AFTER_FIELD_1 	-198


void A4GL_free_associated_mem(void *orig);
void *A4GL_alloc_associated_mem(void *orig,int nbytes);

int aclfgl_fgl_dialog_setcurrline(int n);
int aclfgl_fgl_dialog_getfieldname(int n);
int aclfgl_fgl_dialog_getbuffer(int n);
int aclfgl_fgl_dialog_setbuffer(int n);
int aclfgl_fgl_buffertouched(int n);

int aclfgl_fgl_settitle(int n);
int aclfgl_fgl_getpid(int n);
int aclfgl_fgl_getppid(int n);
int aclfgl_fgl_winquestion(int n);
int aclfgl_fgl_winbutton(int n);

int aclfgl_aclfgl_get_user(int n);
int aclfgl_aclfgl_expand_env_vars_in_cmdline(int n);
int aclfgl_aclfgl_read_pipe(int nargs);
void A4GL_pause_execution(void);
void A4GL_pause_execution_msg(char *s);
void A4GL_start_monitor (void);
void A4GL_monitor_close (void);
int A4GL_has_monitor(void);
int a4gl_isalpha(int a);
void A4GL_assertion_failed(char *s);
int A4GL_was_last_empty(void);
void A4GL_clr_last_was_empty(void);
void A4GL_push_date_expr(void);
void A4GL_push_time_expr(void);
void A4GL_make_field_slist_from_ap( struct s_field_name_list *list, va_list *ap,int replace_0);
int aclfgl_aclfgl_setenv(int n);
int A4GL_setenv(char *name, char *value, int overwrite);
char * acl_getenv_only (char *s);
void A4GL_log_changed_envvar(char *name,char *value);
int A4GL_strstartswith(char *s,char *w);
int A4GL_isnullfunc(void *ptr);
char * A4GL_make_using_tostring (char *ptr, int d, int n);
int fgl_callback (int nargs, char *argv[]);
char *A4GL_get_esql_ext(void);
int a4gl_isupper(int n);
void A4GL_log_sql_prepared_map(char *s);





//int A4GL_is_class_static(char *s);
//void A4GL_set_clobber (char *c);
int a4gl_islower(int n);
void A4GL_log_sql_prepared(char *s);
char *A4GLSQLCV_convert_sql (  char* target_dialect ,char* sql );
int A4GL_strattr_to_num (char *s);
void A4GL_stop_ui(int exitcode);
int aclfgl_aclfgl_set_color (int _nargs);
FILE *A4GL_get_stderr(void) ;

char *A4GL_not_set_empty_string(void);
char *A4GL_tea_string_decipher(char *s);
char *A4GL_tea_string_encipher(char *s);
int A4GLSQL_read_columns (char *tabname, char *xcolname, int *dtype, int *size);

int A4GL_monitor_puts_int (char *str);
//A4GL_convert_report (struct rep_structure *rep, char *ofile, char *otype, char *layout, int to_pipe);

char *A4GL_find_report_dim_string(char *type,int value);

//void A4GL_free_report(struct rep_structure *rep);
char *A4GL_get_tmp_rep(char *mod,char *f);
void a4gl_upshift(char *s);
void A4GL_copy_sqlca_sqlawarn_8chars( char c0, char c1, char c2, char c3, char c4, char c5, char c6, char c7);
void A4GL_copy_sqlca_sqlawarn_string8( char *c);
int
A4GL_call_4gl_dll_bound (char *filename, char *function, int ni,struct BINDING *ibind,int no,struct BINDING *obind);
int A4GLSQL_execute_sql (char *pname, int ni, void *vibind);
int A4GLSQL_add_prepare (char *pname, void *vsid);

void A4GL_write_errfile_many_errors(char *errfile,FILE *fin,struct s_module_error *e,int cnt);
char *A4GL_compiling_module(void);
char *A4GL_compiling_module_basename(void);
void A4GL_set_sql_conv(int n);
void load_temp_table(void);
//void save_temp_table(char *tabname,int select_into);
void save_temp_table(char *tabname,long select_into);



void A4GL_free_directory(void);
char **A4GL_read_directory(char *dir,char *spec);
void A4GL_free_list(char **list);
char ** A4GL_gen_list_dbpath (char *spec, char *path);
int A4GL_has_initialized(void);


#include "a4gl_gen_stack.h"
///

int A4GL_has_evt_timeout(struct aclfgl_event_list *evt) ;
void A4GL_clr_evt_timeouts(struct aclfgl_event_list *evt) ;
void A4GL_evt_not_idle(struct aclfgl_event_list *evt) ;
int A4GL_has_event_for_field(int cat,char *a,struct aclfgl_event_list *evt) ;
int A4GL_has_event_for_action(char *a,struct aclfgl_event_list *evt);
int A4GL_has_event_for_keypress(int a,struct aclfgl_event_list *evt);
int A4GL_has_event(int a,struct aclfgl_event_list *evt);
///


char *A4GLSQLCV_insert_alias_column(char *t,char *c,char *v,int dtype);
char *A4GLSQLCV_insert_alias_value(char *t,char *c,char *v,int dtype);
void A4GLSQLCV_add_temp_table(char *tabname);

  /* API prototypes - now all generated from .spec files by dlmagic */
#include "a4gl_API_form.h"	
#include "a4gl_API_menu.h"	
//#include "a4gl_API_msg.h"	
#include "a4gl_API_packer.h"
#include "a4gl_API_ui.h"	
#include "a4gl_API_help.h"	
#include "a4gl_sql.h"	
#include "a4gl_exdata.h"	
#include "a4gl_API_exreport.h"
#include "a4gl_API_sqlparse.h"
#include "a4gl_API_rpc.h"	
#include "a4gl_API_esql.h"

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


#ifdef MSVC
#undef HAVE_NETINET_IN_H
#endif


#if HAVE_NETINET_IN_H
	#include <netinet/in.h>
#else
	#ifndef htonl
	#ifdef __WIN32__
		/* short win_ntohs(short x);
		short win_htons(short x);
		long  win_ntohl(long x);
		long  win_htonl(long x);
		#define htonl(x) win_htonl(x) 
		#define htons(x) win_htons(x) 
		#define ntohl(x) win_ntohl(x) 
		#define ntohs(x) win_ntohs(x) 
		*/
	#else
		#define htonl(x) (x)
		#define htons(x) (x)
		#define ntohl(x) (x)
		#define ntohs(x) (x)
	#endif
	#endif
#endif




#ifndef gzfopen
#if HAVE_ZLIB

#include <zlib.h>
#define gzfopen gzopen
#define gzfwrite(a,b,c,d) gzwrite(d,a,b*c)
#define gzfprintf gzprintf
#define gzfread(a,b,c,d) gzread(d,a,b*c)
#define gzfeof(f) gzeof(f)
#define gzfgets( buf,len,f) gzgets(f, buf,len)
#define gzfclose(a) gzclose(a)
#define gzfgetc(a) gzgetc(a)
#define gzfputc(a,b) gzputc(b,a)
#else
#define gzfopen fopen
#define gzfwrite(a,b,c,d) fwrite(a,b,c,d)
#define gzfread(a,b,c,d) fread(a,b,c,d)
#define gzfprintf fprintf
#define gzftell(a) tell(a)
#define gzfseek(a,b,c) seek(a,b,c)
#define gzrewind(a) rewind(a)
#define gzfclose(a) fclose(a)
#define gzfgets(buf,len,f) fgets(buf,len,f)
#define gzfeof(f) feof(f)
#define gzfgetc(a) fgetc(a)
#define gzfputc(a,b) fputc(a,b)
#endif
#endif

void A4GL_internal_open_report_file(struct rep_structure *rep,int no_param);

FILE * A4GL_memfile_fopen_buffer (char *ptr, int len);
char *A4GL_fullpath_classpath (char *fname) ;
/* Prototypes from fglwrap.c */
void A4GL_fgl_die_with_msg(int n,char *s);
void * A4GL_new_expr (char *value);
void A4GL_add_recall_value(char *field_name,char *value);
void A4GL_debug_dump_recall(char *field_name);
char *A4GL_recall_field(char *t,char *c,int x,int y,int show);
int A4GL_sqlid_from_aclfile(char *dbname,char *uname,char *passwd);

void A4GL_set_connection_username(char *u) ;
char * A4GL_get_connection_username(void) ;



char *A4GL_confirm_colname(char *t,char *c);

//int input_funcname(char *rn, char **r, int isptr, int arr);
//int input_sql_ident(char *rn, char **r, int isptr, int arr);
//int input_str(char *rn, char **r, int isptr, int arr);
//int output_funcname(char *n, char *r, int isptr, int arr);
//int output_sql_ident(char *n, char *r, int isptr, int arr);
//int output_str(char *n, char * r, int isptr, int arr);

#ifndef _NO_FORM_X_H_
#include "dataio/fgl.xs.h"

typedef struct expr_str t_expr_str;
#define T_EXPR_LIST_DEFINED
typedef struct expr_str_list t_expr_str_list;


enum ow_open_window_type {
	OW_AT,
	OW_FORM
};


struct ow_open_window {
	enum ow_open_window_type type;
	union {
		struct expr_str *formname;
		struct {
			struct expr_str *x;
			struct expr_str *y;
		} x_y;
	} u_data;
};


typedef struct ow_open_window t_ow_open_window;



#ifndef BIND_RECOPY
#define BIND_RECOPY
struct BINDING * bind_recopy (struct BINDING *b, int n, struct BINDING *c);
#endif



char *A4GLSQLCV_make_case(struct s_select *select,struct s_sli_case *i);
void A4GL_free_select_stmt(struct s_select *s);
int A4GL_new_escape_quote_owner (void);
struct s_select_list_item_list *new_select_list_item_list(struct s_select_list_item *i) ;
struct s_select_list_item * new_select_list_item_variable_usage_list (struct s_select_list_item_list *vs);
struct s_select_list_item *new_select_list_item_char (char *s) ;
struct s_select_list_item *new_select_list_item_literal (char *s) ;
struct s_select_list_item *new_select_list_item_datetime (char *s) ;
struct s_select_list_item * new_select_list_query (struct s_select *s);
struct s_select_list_item *new_select_list_item_extend (struct s_select_list_item *dt_expr, char *from,char *to) ;
struct s_select_list_item *new_select_list_item_interval (char *s) ;
struct s_select_list_item *new_select_list_item_col (char *t,char *c,struct ilist *subscripts);
struct s_select_list_item *new_select_list_item_sq (enum sq_expression_type type, struct s_select_list_item *s) ;
struct s_select_list_item *new_select_list_item_builtin_const (enum e_sli type) ;
struct s_select_list_item *new_select_list_item_agg1 (enum e_sli type,char *aud, struct s_select_list_item *i) ;
struct s_select_list_item *new_select_list_item_op_sli (struct s_select_list_item *left, struct s_select_list_item *right, enum e_sli op) ;
struct s_select_list_item *new_select_list_item_op_expr (struct s_select_list_item *left, struct s_select_list_item *right, char* op) ;
struct s_select_list_item *new_select_list_item_op_between (char *not,struct s_select_list_item *v, struct s_select_list_item *from, struct s_select_list_item *to,int not_between) ;
struct s_select_list_item *new_select_list_item_builtin_fcall (enum e_sli type, struct s_select_list_item_list *params) ;
struct s_select_list_item *new_select_list_item_simple_expr (enum e_sli type, struct s_select_list_item *expr) ;
struct s_select_list_item *new_select_list_item_regex (enum e_sli type, struct s_select_list_item *val,struct s_select_list_item *regex,char *escape);
struct s_select_list_item_list *add_select_list_item_list(struct s_select_list_item_list *p,struct s_select_list_item *i);
struct s_select_list_item *new_select_list_subquery(struct s_select *s);
struct s_select_list_item *new_select_list_item_fcall (char *fname, struct s_select_list_item_list *params);
struct s_table *A4GLSQLPARSE_append_tablename(struct s_table *t1,struct s_table *t2, e_outer_type is_outer, s_select_list_item *join_condition);
struct s_table *A4GLSQLPARSE_new_tablename(char *tname,char *alias);
struct s_select *new_empty_select (void);
struct s_select_list_item *new_select_list_item_variable (char *s);
struct s_select_list_item *new_select_list_item_column_from_transform(char *s);
struct s_select_list_item *new_select_list_item_ibind (char *s);
struct s_select_list_item *new_select_list_item_op_slil (struct s_select_list_item *left, struct s_select_list_item_list *right, enum e_sli op);
struct s_select_list_item * new_select_list_item_variable_usage (struct variable_usage *v);
struct s_select_list_item *new_select_list_item_cast(struct s_select_list_item *expr, char *cast);
char *make_select_stmt_v2(char *upd_or_del_table, struct s_select *select, char *into_portion);
#define make_select_stmt ERROR ERROR ERROR
void preprocess_sql_statement (struct s_select *select);



void
map_select_stmt (char *main_statement_type, struct s_select *select);
void
map_delete_update (char *main_statement_type, char *table, struct s_select_list_item *i);
void map_create_temp(char *tab, char *src);
void fail_on_select_ibind(void);

char *make_table_expression(struct s_select *select);
char *get_select_list_item_list(struct s_select *select, struct s_select_list_item_list *i) ;
char *get_select_list_item(struct s_select *select, struct s_select_list_item *p) ;
struct s_select_list_item *new_select_list_item_case(struct s_select_list_item  *i);
struct s_select_list_item * append_select_list_item_case (struct s_select_list_item *l, struct s_select_list_item *w) ;
struct s_select_list_item * new_select_list_item_case_element ( struct s_select_list_item *w,  struct s_select_list_item *e)  ;
struct s_select_list_item * new_select_list_item_replace_var (char *s);
struct s_select_list_item_list * rationalize_select_list_item_list ( s_select_list_item_list *old );
int is_fake_rowid_column(char*s);
int A4GL_last_was_ascii_null(void);
char *A4GLSQLCV_check_colname_alias(char *alias,char *tabname, char *colname);
 
struct s_table_list *A4GLSQLPARSE_add_table_to_table_list(struct s_table_list *tl,char *t,char *a);

int A4GLSQLPARSE_from_clause_collect_tables(struct s_select *select, struct s_table *t,struct s_table_list *tl);

char * fix_delete_update_columns (char *table, struct s_select_list_item *i) ;
char * get_select_list_item_list_ob (struct s_select *select, struct s_select_list_item_list *i);
char * find_table (struct s_select *select, struct s_select_list_item *i);
int A4GLSQLPARSE_from_outer_clause (struct s_select *select, char *left, struct s_table *t, char *fill, struct s_table_list *tl);
int A4GLSQLPARSE_from_clause(struct s_select *select, struct s_table *t,char *fill,struct s_table_list *tl) ;
int A4GLSQLPARSE_from_clause_join (struct s_select *select, struct s_table *t, char *fill, struct s_table_list *tl);
#include "a4gl_API_sql.h"
#endif



int A4GL_fgl_keyval (int _np);
int A4GL_aubit_strcasestr(char *h,char *n);
int aclfgl_aclfgl_random(int n) ;
int aclfgl_aclfgl_get_connection_username(int a) ;
int A4GL_valid_dt (char *s, int *data,int size);

int A4GL_include_range_check (char *ss, char *ptr, int dtype);

int A4GLSQLCV_check_runtime_requirement (char *s);
int A4GL_compile_time_convert(void);
void A4GL_set_compile_time_convert(int a);

void A4GL_set_fcompile_err(char *s) ;
char *A4GL_get_fcompile_err(void) ;


void A4GL_set_malloc_context(void *a) ;

void A4GL_free_malloc_context(void *s) ;
void A4GL_clr_malloc_context(void ) ;

void A4GL_dec_dec_ops(int op);


int A4GL_get_sql_conv (void);
char *A4GL_get_esql_connection(void);
void A4GL_set_esql_connection(char *s);
int A4GL_copy_file(char *from,char *to);
int A4GL_file_exists(char *fname);
int A4GL_move_file(char *from,char *to);
int A4GL_file_length(char *fname);
int A4GL_delete_file(char *fname);
void A4GL_status_ok(int sql_too);
//void A4GL_set_sql_lineno(int n);
void A4GL_decode_datetime (struct A4GLSQL_dtime *d, int *data);
int aclfgl_aclfgl_getcwd (int a);
int aclfgl_aclfgl_replace_start(int nargs);
int aclfgl_aclfgl_call_in_shared(int a) ;
int aclfgl_aclfgl_set_pdf_encoding(int n);
int aclfgl_aclfgl_get_pdf_encoding(int n);
void add_int8_support(void);
void add_reference_support(void);
int A4GL_dttoc (void *a, void *b, int size);
int A4GL_wcswidth(char *mbs);
void A4GL_remove_trailing_zeros_and_leading_spaces(char *s) ;



void A4GL_set_intr (void);



#ifdef WORK_IN_PROGRESS
/* SQL WHERE CLAUSE HANDLING */



struct predicate {
	union {
		comparison;
		in_predicate
		exists_predicate
	}
	;
};

struct boolean_primary {
	union {
		struct predicate *p;
		struct search_condition *s;
	}
};

struct boolean_term {
		struct boolean_factor factor;
		struct boolean_term *and;
}

struct boolean_factor_ss {
		struct boolean_primary *p;
		short not;
};


struct search_condition {
	struct boolean_term_ss *b;
	struct search_condition *or;
};
#endif


void *A4GL_esql_dbopen_connection(void) ;
//char *A4GL_var_for_inp_array(char *s);

typedef struct
{
    char decsep;
    char thsep;
} s_decfmt;

typedef struct
{
    s_decfmt posix_decfmt;
    s_decfmt ui_decfmt;
    s_decfmt db_decfmt;
    s_decfmt printf_decfmt;
    s_decfmt scanf_decfmt;
    s_decfmt using_decfmt;
} s_convfmts;

#ifdef __WIN32__
  #ifndef DEFINES_CONVFMTS
    #ifdef EXTERN_CONVFMTS
      extern s_convfmts a4gl_convfmts;
    #else
      dll_import s_convfmts a4gl_convfmts;
    #endif
  #endif
#else
extern s_convfmts a4gl_convfmts;
#endif

s_convfmts * A4GL_get_convfmts(void);

void A4GL_init_default_formats(void);
char *A4GL_decstr_convert(char *buf, s_decfmt from, s_decfmt to, int newbuf, int trim, int maxlen);
int A4GL_is_numeric_datatype(int dtype);
char *A4GL_has_comment(int n,int c);
int A4GL_GetComment(int a, char **s, int *l, int *c, char *type);
int A4GL_is_meaningful_in_decfmt(s_decfmt fmt, char c);
int A4GL_get_attr_from_string (char *s);
int A4GL_bad_identifiers(char *S);
void A4GL_get_blob_data(fglbyte *b,char **buffer, long *buffer_len);
char *
A4GLSQLCV_make_substr_s (char *colname, int n, char *l, char *r);
char *A4GL_get_syscolatt(char *tabname,char *colname,int seq, char *attr);
int A4GL_get_single_int_returned_from_call(int n);
int A4GL_islocated(struct fgl_int_loc *p);
int A4GL_wordwrap_text(char *in, char *out,int width, int maxsize);
char *A4GL_get_errmsg_from_helpfiles(int n);

void A4GL_change_trailing_zeros_for_leading_spaces(char *s);
int A4GL_never_dlmagic_cache(char *s);
void A4GL_removePreparedStatementBySid(void *sid);
void *A4GL_set_associated_mem(void *orig,void *newbytes);
//int A4GL_findPreparedStatementbySid (void *sid) ;
void A4GL_addPreparedStatement (char *name, char *anonname, void *sid, void *extra_data);
//int A4GL_findPreparedStatement (char *name);
//int A4GL_findPreparedStatementByUniq (char *name);
void * A4GL_getSIDByUniq (char *name);
void A4GL_removePreparedStatement(char *name);
int
A4GL_apisql_has_sess (char *sessname);
char *A4GL_get_clobbered_from(char *s) ;
int A4GL_file_is_newer(char*lv_f1, char *lv_f2);
size_t A4GL_base64_encode(const char *inp, size_t insize, char **outptr);
void A4GL_set_stderr(FILE *errfile);
int aclfgl_aclfgl_parse_csv(int nparam);
int aclfgl_aclfgl_split_on_delimiter (int n);
int A4GL_has_associated_mem (void *orig,void *assoc);
void A4GL_cvsql_replace_str (char *buff, char *from, char *to);
long A4GL_bounds_check(long a,long maxbound); /* Check array bounds in a 4gl call */

long A4GL_get_length (char *s);
void A4GL_ensure_numeric_prompt_var(int dtype);
void A4GL_convert_ui_char_on_stack_decimal_sep(void );
int A4GL_remap_nativeerror(int n, char *sqlstate);
void A4GL_size_decimal_string(char *s,int *dig, int *dec);
void A4GL_pop_sized_decimal(fgldecimal *b);
void A4GL_remove_printfthsep_in_decimal(char *s);
void A4GL_strip_bracket (char *s);

int A4GL_is_event_close (void *event);
void A4GL_push_reference (void *x, int l);
int aclfgl_aclfgl_walk_pointers (int n);
int aclfgl_aclfgl_trim_nl(int n);
struct struct_form *A4GL_get_the_form_ptr(void) ;
void A4GL_set_fld(void *f) ;
struct struct_scr_field *A4GL_get_fld(void) ;
void A4GL_set_as_c(int n) ;
int A4GL_get_as_c(void) ;
void A4GL_init_dec_size(fgldecimal *dec, int size);




void
A4GL_str_dot_to_dec (char *s, fgldecimal * d);
#endif				/* #ifndef _AUBIT_LIB_INCL_EXT_ */


/* ========================== EOF ====================================== */
