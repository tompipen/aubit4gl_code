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
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: builtin.c,v 1.110 2007-04-20 07:12:34 mikeaubury Exp $
#
*/

/**
 * @file
 * Implementation of builtin, internal functions of informix 4gl standard,
 * as well as some of 4Js extensions
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_libaubit4gl_int.h"
#include <string.h>
#define ACLFGLI_STR_TO_ID         'S'
void A4GL_generateError (char *str, char *fileName, int lineno);
/*
=====================================================================
                    Variables definitions
=====================================================================
*/

int 	mv_arr_count = 0;
int 	mv_arr_curr = 0;
int 	mv_scr_line = 0;
FILE *	error_log_file = 0;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

/*
	Note : all functions with aclfgl_ prefix are callable from
	compiled 4gl code, since all references to functions get aclfgl_ prefix
	appended to them by 4gl compiler. Therefore, compiled 4gl code CANNOT
    call any function in Aubit libraries without aclfgl_ prefix.
*/


char *	A4GL_pull_off_data_for_display 	(int n,int display_type);
int 	aclfgl_ddepoke 					(char *progname, char *ddemessage, char *ddecommand, char *ddeparam);
char * 	aclfgl_ddefinish 				(char *progname, char *ddemessage);
int 	aclfgl_ddeexecute 				(char *progname, char *ddemessage, char *ddecommand);
char * 	aclfgl_ddegeterror 				(void);
int 	aclfgl_ddeconnect 				(char *progname, char *ddemessage);
void 	aclfgl_ddefinishall 			(void);
char * 	aclfgl_ddepeek 					(char *progname, char *ddemessage, char *ddecommand);
void 	aclfgl_fgl_winmessage 			(char *windowTitle, char *message, char *iconType);
void 	aclfgl_fgl_keysetlabel 			(char *keyName, char *labelText);
char * 	aclfgl_fgl_strtosend 			(char *str);
int 	aclfgl_winexecwait 				(char *exec_string);
int 	aclfgl_winexec 					(char *exec_string);
int 	aclfgli_show_help 				(int a);
int 	aclfgl_fgl_scr_size 			(int n);
int	aclfgl_fgl_setkeylabel(int n);
int	aclfgl_fgl_dialog_setkeylabel(int n);

void	A4GL_log_error(int lineno, char *fname, int mstatus);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 * Does nothing
 * fglwrap calls this to make sure this file is included in any
 * executable
 *
 */
void
A4GL_include_builtin_in_exe (void)
{
  /* Does nothing */
}

/**
 * Set count for INPUT / DISPLAY ARRAY statement.
 *
 * @param nargs Number of arguments passed by the parameter stack.
 */
int
aclfgl_set_count (int nargs)
{
  long a = 0;
  struct BINDING fbind[] = {
    {0, 2, 0,0,0,0}			
  };				/* end of binding */

	fbind[0].ptr=&a;
  if (nargs != 1)
    {
      /* A4GL_pop_args(nargs);set_status(-3001); */
      A4GL_pop_args (nargs);
      A4GLSQL_set_status (-3001, 0);
      return 0;
    }
  A4GLSQL_set_status (0, 0);
  A4GL_pop_params (fbind, 1);
  mv_arr_count = a;
/* a is now set to set_Count */
  return 0;
}

/**
 * Set the array counter.
 *
 * @param nargs Number of arguments passed by the parameter stack.
 */
int
aclfgl_arr_count (int nargs)
{
  if (nargs != 0)
    {
      A4GL_pop_args (nargs);
      A4GLSQL_set_status (-3001, 0);
      return 0;
    }
  A4GL_push_long (mv_arr_count);
/* a is now set to set_Count */
  return 1;
}

/**
 * Get the current scrren line (INPUT ARRAY 4gl statement).
 *
 * @param nargs Number of arguments passed by the parameter stack.
 */
int
aclfgl_scr_line (int nargs)
{
  if (nargs != 0)
    {
      A4GL_pop_args (nargs);
      A4GLSQL_set_status (-3001, 0);
      return 0;
    }
  A4GL_push_long (mv_scr_line);
  return 1;
}

/**
 * Get the current element in the program array (INPUT ARRAY 4gl statement).
 *
 * @param nargs Number of arguments passed by the parameter stack.
 */
int
aclfgl_arr_curr (int nargs)
{
  if (nargs != 0)
    {
      A4GL_pop_args (nargs);
      A4GLSQL_set_status (-3001, 0);
      return 0;
    }
  A4GL_push_long (mv_arr_curr);
  return 1;
}


/**
 * get resource (environment variable or from config file) when invoked 
 * in 4gl code with fgl_getenv(varname)
 *
 * @param nargs Number of arguments passed by the parameter stack.
 */
int
aclfgl_fgl_getenv (int nargs)
{
  char *g;
  char *p;

  if (nargs != 1)
    {
      A4GL_pop_args (nargs);
      A4GLSQL_set_status (-3001, 0);
      return 0;
    }
  g = A4GL_char_pop ();
  A4GL_trim (g);
  A4GL_debug ("Looking up %s", A4GL_null_as_null(g));
  p = acl_getenv_not_set_as_0(g);
  A4GL_debug("Got back %p");
  if (p) {
	  A4GL_debug(" %s = '%s'",A4GL_null_as_null(g),A4GL_null_as_null(p));
  }


  if (p == 0) {
	 if (A4GL_isyes(acl_getenv("ENV_NOT_SET_AS_STR"))) { // Historic Aubit4GL behaviour
    		A4GL_push_char ("");
	 } else {
		 A4GL_push_null (DTYPE_CHAR,0);
	 }
  } else {
	     if (strcmp(p,"")==0) {
                 A4GL_push_char (" ");
             } else {
                 A4GL_push_char (p);
             }
	  
  }
  acl_free (g);
  return 1;
}


/**
 * enable A4GLSQL_dbms_dialect() to be callable from 4gl code
 * Returns the dialect of SQL spoken by the currently
 * connected DBMS. a char string, eg. "INFORMIX", "ORACLE", "SAPDB"
 *
 * @return allways 1
 */
int
aclfgl_dbms_dialect (int n) // n should always be 0
{
//char *g;
  char *p;

  p = A4GLSQL_dbms_dialect ();
  if (p == 0)
    A4GL_push_char ("");
  else
    A4GL_push_char (A4GLSQL_dbms_dialect ());
  //acl_free (g); // Is this here for a reason ?
  return 1;
}



/**
 * Make a string length to the string in the stack and return the length by
 * the stack.
 *
 * @param nargs Number of arguments passed by the parameter stack.
 * @return 
 *   - 0 : No arguments.
 *   - 1 : OK strlen made.
 */
int
aclfgl_length (int nargs)
{
  char *g;
  size_t p;
  if (nargs != 1)
    {
      A4GL_pop_args (nargs);
      A4GLSQL_set_status (-3001, 0);
      return 0;
    }
  g = A4GL_char_pop ();
  if (A4GL_isnull(DTYPE_CHAR,g)) {
		A4GL_push_int(0);
		return 1;
	}
  A4GL_trim_not_nl (g); // Trim just ' ' - not nl...
  p = strlen (g);
  A4GL_push_long ((long)p);
  acl_free (g);
  return 1;
}

int A4GL_push_substr (char *ca, int dtype, int a, int b, ...) {
char *p;  
	p=a4gl_substr(ca,dtype,a,b);
	A4GL_push_param(strdup(p),DTYPE_CHAR+(ENCODE_SIZE((b-a+1)))+DTYPE_MALLOCED);
	return 1;
}

/**
 * Make a substring acording to the data type.
 *
 * @param ca The String.
 * @param dtype The data type.
 * @param a The begining index wanted.
 * @param b The end index wanted.
 * @param ...
 */
char *
a4gl_substr (char *ca, int dtype, int a, int b, ...)
{
  static char *np = 0;
  static char *np2 = 0;
int sz;
  va_list ap;
  va_start (ap, b);
  va_end (ap);
  A4GL_debug("Entering a4gl_substr");
  if (A4GL_isnull(DTYPE_CHAR,ca)) return "";

  sz=DECODE_SIZE(dtype);
  if (b>sz && sz) {
	A4GL_exitwith("A character variable has referenced subscripts that are out of range");
	return "";
  }

#ifdef DEBUG
  {
    A4GL_debug ("substr");
  }
#endif
  if (np != 0)
    acl_free (np);
  if (np2 != 0)
    acl_free (np2);
  np = acl_strdup (ca);
  np2 = acl_strdup (ca);

  if (a>strlen(ca)) {
		a=strlen(ca);
		return "";
	}

  if (b>strlen(ca)) { // We're past the end of the string...
		b=strlen(ca);
  }
if (b) {
  if ((size_t)(b - a + 1) > strlen(ca)) {
		A4GL_debug("Need a little more..");
		free(np);
		free(np2);
	
		A4GL_debug("b=%d a=%d", b,a);
		A4GL_debug("Want %d bytes ",b - a + 2);
		np=acl_malloc2((size_t) (b - a + 2));
		np2=acl_malloc2((size_t) (b - a + 2));
		memset(np,0,(size_t)(b - a + 2));
		memset(np2,0,(size_t)(b - a + 2));
		strcpy(np,ca);
		strcpy(np2,ca);
  }
}

#ifdef DEBUG
  {
    A4GL_debug ("Start with %s", A4GL_null_as_null(np));
  }
#endif

  if (b == 0)
    {
      b = a;
    }

  if (np[0] == 0)
    {
#ifdef DEBUG
      {
 A4GL_debug ("NULL - dtype=%x", dtype);
      }
#endif
      free (np);
      np = acl_malloc2 ((size_t) DECODE_SIZE (dtype) + 1);
      free (np2);
      np2 = acl_malloc2 ((size_t) DECODE_SIZE (dtype) + 1);
		memset(np,0,(size_t) DECODE_SIZE (dtype) + 1);
		memset(np2,0,(size_t) DECODE_SIZE (dtype) + 1);
	
      A4GL_pad_string (np,  DECODE_SIZE (dtype));
    }
  a--;
  b--;

#ifdef DEBUG
  {
    A4GL_debug ("Start with %s", A4GL_null_as_null(np));
  }

  {
    A4GL_debug ("a=%d b=%d dtype=%d,\n ", a, b, dtype);
  }
#endif

  if (b == -1)
    b = a;
#ifdef DEBUG
  {
    A4GL_debug (">>>>Allocated %d bytes", b - a + 2);
  }
#endif

  A4GL_debug ("a=%d b-a+1=%d",a,b-a+1);

  strncpy (np2, &np[a], (size_t)(b - a + 1));
  np2[b - a + 1] = 0;
#ifdef DEBUG
  {
    A4GL_debug (">>>>Set to %s", A4GL_null_as_null(np2));
  }
#endif
A4GL_debug("Exiting a4gl_substr");
  return np2;
}

/**
 *
 * @param ca
 * @param dtype The data type
 * @param a The begining index.
 * @param b The end index.
 */
char *
a4gl_let_substr (char *ca, int dtype, int a, int b, ...)
{
  char *np;
  int size;
#ifdef DEBUG
  {
    A4GL_debug ("let_substr");
  }
#endif
  A4GL_pad_string (ca, DECODE_SIZE (dtype));
#ifdef DEBUG
  {
    A4GL_debug ("Start with '%s'", A4GL_null_as_null(ca));
  }
  {
    A4GL_debug ("a=%d b=%d dtype=%d,\n ", a, b, dtype);
  }
#endif
  if (b == 0)
    b = a;
  size = b - a + 1;
  np = (char *) acl_malloc (size + 1, "let_substr");
  A4GL_pop_char (np, size);
#ifdef DEBUG
  {
    A4GL_debug ("   Stack contained %s\n", A4GL_null_as_null(np));
    A4GL_debug ("   Size=%d", size);
  }
#endif

  if (strlen(np)!=(size_t)size) {
		A4GL_pad_string(np,size);
  }

  strncpy (&ca[a - 1], np, (size_t)size);
#ifdef DEBUG
  {
    A4GL_debug ("Set to %s", A4GL_null_as_null(ca));
  }
#endif
  return ca;
}

/**
 * The get count for INPUT ARRAY.
 */
int
A4GL_get_count (void)
{
 A4GL_debug("mv_arr_count=%d XYX",mv_arr_count);
  return mv_arr_count;
}

/**
 * Set the current position in input array
 *
 * @param a The position to be setted.
 */
void
A4GL_set_arr_curr (int a)
{
  mv_arr_curr = a;
}

/**
 * Set the last array position.
 *
 * @param a The index of the last array position used.
 */
void
A4GL_set_arr_count (int a)
{
  mv_arr_count = a;
}

/**
 * Set the screen line
 *
 * @param a The screen line to be setted.
 */
void
A4GL_set_scr_line (int a)
{
  mv_scr_line = a;
}

/**
 * Sets the current array.
 *
 * @deprecated : Removal candidate.
 * @todo : Remove if not used.
 * @param a The current array to be setted.
 */
/*
void
get_arr_curr (int a)
{
  mv_arr_curr = a;
}
*/

/**
 * Sets the current array.
 *
 * @deprecated : Removal candidate.
 * @todo : Remove if not used.
 * @param a The current array to be setted.
 */
/*
void
get_scr_line (int a)
{
  mv_scr_line = a;
}
*/

#if (defined (_WINDOWS) || defined (__MINGW32__))

/**
 *
 *
 * @param
 */
char *
index (char *s, int a)
{

  int b;
int l;
l=strlen (s);
  for (b = 0; b < l; b++)
    {

      if (s[b] == a)
	return &s[b];

    }

  return 0;

}


/**
 *
 *
 * @param
 */
char *
rindex (char *s, int a)
{

  int b;
int l;
  l=strlen (s);

  for (b = l - 1; b >= 0; b--)
    {

      if (s[b] == a)
	return &s[b];

    }

  return 0;

}

#ifndef __MINGW32__
/**
 *
 * builtin.c:446: conflicting types for `strcasecmp'
 * d:/MinGW/include/string.h:163: previous declaration of `strcasecmp'
 *
 *
 * @param
 */
int
//strcasecmp (char *s1, char *s2)
strcasecmp (const char *s1, const char *s2)
{
/*
d:/MinGW/bin/../lib/gcc-lib/mingw32/3.2/../../../libmoldname.a(string_old.o)(.text+0x0):string_old.c: multiple definition of `strcasecmp'
builtin.o:D:/cygwin/usr/src/aubit/aubit4glsrc/lib/libaubit4gl/builtin.c:449: first defined here
*/



  return stricmp (s1, s2);

}

/**
 * builtin.c:493: conflicting types for `popen'
 * d:/MinGW/include/stdio.h:314: previous declaration of `popen'
 *
 * A dummy windows popen.
 * Just return 0
 */
int
popen (void)
{

  return 0;

}

#else

extern int strcasecmp (const char *, const char *);

#endif //ndef __MINGW32__



/**
 * Windows implementation of unix sleep. On UNIX defined in <unistd.h>
 *
 * @param a The number of seconds to sleep.
 */
void
sleep (int a)
{
  Sleep (a * 1000);
}


/**
 *
 *
 * @param
 */
int
getpwuid (void)
{
  return 0;
}

/**
 * The windows dummy implementation of unix getuid().
 *
 * @return Allways 50.
 */
int
getuid (void)
{
  return 50;
}


#endif


/**
 * fake function for err_get()
 *
 * @param statusnumber 
 */
int
aclfgl_err_get (int n)
{
  int a;
  static char buff[200];
  a = A4GL_pop_int ();
  /* A4GLSQL_set_status(-3001,0); */
  SNPRINTF (buff,200, "Error : %d ", a);
  A4GL_push_char (buff);
  return 1;
}


/**
 * fake function for ERR_PRINT( )
 *
 *
 */
int
aclfgl_err_print (int statusnumber)
{

  /*  A4GLSQL_set_status(-3001,0); */
  return 0;
}


/**
 * fake function for ERR_QUIT( )
 *
 * @param statusnumber
 */
int
aclfgl_err_quit (int statusnumber)
{

  /*  A4GLSQL_set_status(-3001,0); */
  return 0;
}


/**
 *
 * The STARTLOG( ) function opens an error log file.
 *
 * filename is a quoted string to specify a filename (and optional path name
 * and file extension) of the error log file.
 *
 * Variable is a variable of type CHAR or VARCHAR containing a filename
 * (and optional path name and file extension) of the error log file.
 *
 * The following is a typical sequence to implement error logging:
 *
 * Call STARTLOG( ) in the MAIN program block to open or create an error log file.
 *
 * Use a LET statement with ERR_GET(status) to retrieve the error text and
 * to assign this value to a program variable.
 *
 * Use ERRORLOG( ) to make an entry into the error log file.
 *
 * The last two steps are not needed, if you are satisfied with the error
 * records that are automatically produced after STARTLOG( ) has been invoked.
 * After you call the STARTLOG( ) function, a record of every subsequent error
 * that occurs during the execution of your program is written to the error
 * log file, provided that the WHENEVER ERROR CONTINUE statement is not in
 * effect.
 *
 * The error record consists of the date, time, source-module name and
 * line number, error number, and error message. You can also write your
 * own messages in the error log file by using the ERRORLOG( ).
 *
 *
 *
 * @param fname
 * @param l
 * @param n
 */
int
A4GL_startlog (char *fname, int l, int n)
{
  char *s;
  s = A4GL_char_pop ();

  A4GL_trim (fname);
  A4GL_trim (s);
  A4GL_debug ("START LOG (%s Line:%d) to file '%s'\n", A4GL_null_as_null(fname), l, A4GL_null_as_null(s));


  if (A4GL_isyes(acl_getenv("RESTARTLOG"))) {
  	error_log_file = fopen (s, "w");
  } else {
  	error_log_file = fopen (s, "a");
  }

  if (error_log_file == 0)
    {
      A4GL_exitwith ("Unable to open Error Log file");
    }

  free (s);

  return 0;
}

/**
 *
 */
int
A4GL_has_errorlog (void)
{
  if (error_log_file)
    return 1;
  return 0;
}


/**
 * The ERRORLOG( ) function copies its argument into the current error log file.
 * See documentation for function A4GL_startlog.
 *
 * @param fname
 * @param l
 * @param n
 */
int
A4GL_errorlog (char *fname, int l, int nargs)
{
  char *s;
  char *date_str;
  char *time_str;
  //int d;

  //s = A4GL_char_pop ();
  s=A4GL_pull_off_data_for_display(nargs,DISPLAY_TYPE_DISPLAY_AT);
  A4GL_debug ("ERROR LOG - %s Line:%d %s\n", A4GL_null_as_null(fname), l, A4GL_null_as_null(s));

  A4GL_trim(s);
  if (error_log_file)
    {
      A4GL_push_current (1, 3);
      date_str = A4GL_char_pop ();

      A4GL_push_current (4, 6);
      time_str = A4GL_char_pop ();

      FPRINTF (error_log_file, "Date: %s    Time: %s\n", date_str, time_str);
      if (A4GL_isyes (acl_getenv ("EXTENDED_ERRORLOG")))
	{
	  FPRINTF (error_log_file, "MODULE : %s    Line: %d\n", fname, l);

	}
      FPRINTF (error_log_file, "%s\n", s);
      fflush (error_log_file);

    }
  else
    {
      A4GL_exitwith ("Error Log file is not open");
    }

  free (s);

  return 0;
}



void
A4GL_close_errorlog_file (void)
{
A4GL_debug("Close_errlog_file");
  if (error_log_file)
    {
      A4GL_debug("error log was open");
      fclose (error_log_file);
      A4GL_debug("not any more...");
      error_log_file=0;
    }
}

/**
 * The SHOWHELP( ) function displays a Help message, corresponding to its
 * specified SMALLINT argument, from the current Help file.
 * 
 * 
 * 
 * The argument of SHOWHELP( ) identifies the number (between 1 and 32,767)
 * of a message in the Help file that was specified in the OPTIONS statement.
 * 
 * When it is called, SHOWHELP( ) opens the Help window, and displays the
 * first (or only) page of the Help message text below a ring menu of Help 
 * options. This menu is called the Help menu.
 * 
 * If the Help message is too long to fit on one page, the Screen or Next
 * option of the Help menu can display the next page of the message. The 
 * Previous option re displays the previous page. The Resume option closes 
 * the Help window, and returns focus to the Application window.
 * 
 * In interactive statements like CONSTRUCT, INPUT, INPUT ARRAY, PROMPT,
 * or the COMMAND clause of a MENU statement, the effect of SHOWHELP( ) 
 * resembles that of the Help key. The Help key, however, displays only
 * the message specified in the current HELP clause.
 *
 * @param helpnumber
 */
int
aclfgl_showhelp (int helpnumber)
/* show_help(string, 4glmode, 4gllinenumber) */
{
  A4GL_push_long (helpnumber);
  aclfgli_show_help (1);

  return 0;
}


/*
P12.ao: In function `main':
P12.ao(.text+0x3c): undefined reference to `def_quit'
*/



/**
 * close database
 *
 */
void
A4GL_close_database (void)
{
  if (!A4GL_isno(acl_getenv("FORCE_CLOSE")) ) {
  if (A4GL_has_pointer ("default", SESSCODE))
    {
      A4GLSQL_close_session ("default");
      A4GL_del_pointer ("default", SESSCODE);
    }
  return;
  }
  return;
}



/**
 * @todo Describe function
 *
 * @param a
 * @param b
 */
void
aclfgli_current (int a, int b)
{
  A4GL_push_current (a, b);
}

/**
 * @todo Describe function
 *
 */
void
aclfgli_extend (void)
{
  struct A4GLSQL_dtime c;
  int n;
  char *ptr;
	char buff[256]="";
  int  d2;
  int  s2;
  struct A4GLSQL_dtime dt2;
  struct A4GLSQL_dtime *pi;
  int dtime_data2[10];

  n = A4GL_pop_int ();

  A4GL_get_top_of_stack (1, &d2, &s2, (void *) &pi);
	if (A4GL_isnull((d2&DTYPE_MASK),(void *)pi)) {
		pi=0;

	}


  if ((d2&DTYPE_MASK)!=DTYPE_DTIME) {
		if ((d2&DTYPE_MASK)==DTYPE_DATE) {
			// Can't extend a non-datetime!
			pi=0;
			A4GL_pop_var2 (&c, DTYPE_DTIME, n);
			A4GL_push_dtime (&c);
			return;
		}
  }

  if (pi==0) {  
		A4GL_drop_param();
		A4GL_push_null(DTYPE_DTIME, s2);
		return;
		
  }

  dt2.stime = pi->stime;
  dt2.ltime = pi->ltime;

  A4GL_pop_param (&dt2, DTYPE_DTIME, dt2.stime * 16 + dt2.ltime);
  A4GL_decode_datetime (&dt2, &dtime_data2[0]);

  if (dtime_data2[1]==0) dtime_data2[1]=1; // cant have a 0 month...
  if (dtime_data2[2]==0) dtime_data2[1]=1; // cant have a 0 day...
  
  switch (n) {
	case 0x11: // Year to year
  		SPRINTF1 (buff, "%04d", dtime_data2[0]);
		break;

	case 0x12: // Year to month
  		SPRINTF2 (buff, "%04d-%02d", dtime_data2[0], dtime_data2[1]);
		break;

	case 0x13: // Year to day
  		SPRINTF3 (buff, "%04d-%02d-%02d", dtime_data2[0], dtime_data2[1], dtime_data2[2]);
		break;

	case 0x14: // Year to hour
  		SPRINTF4 (buff, "%04d-%02d-%02d %02d",
               		dtime_data2[0], dtime_data2[1], dtime_data2[2], dtime_data2[3]);
		break;

	case 0x15: // Year to minute
  		SPRINTF5 (buff, "%04d-%02d-%02d %02d:%02d", dtime_data2[0], dtime_data2[1], dtime_data2[2], dtime_data2[3], dtime_data2[4]);
		break;

	case 0x16: // Year to second
  		SPRINTF6 (buff, "%04d-%02d-%02d %02d:%02d:%02d", dtime_data2[0], dtime_data2[1], dtime_data2[2], dtime_data2[3], dtime_data2[4], dtime_data2[5]);
		break;

	case 0x17: // Year to fraction(1)
	case 0x18: // Year to fraction(2)
	case 0x19: // Year to fraction(3)
	case 0x1a: // Year to fraction(4)
	case 0x1b: // Year to fraction(5)
  		SPRINTF7 (buff, "%04d-%02d-%02d %02d:%02d:%02d.%05d", dtime_data2[0], dtime_data2[1], dtime_data2[2], dtime_data2[3], dtime_data2[4], dtime_data2[5], dtime_data2[6]);
		break;


// **************************
	case 0x22: // Month to month
  		SPRINTF1 (buff, "0000-%02d-00",  dtime_data2[1]);
		break;

	case 0x23: // Month to day
  		SPRINTF2 (buff, "0000-%02d-%02d", dtime_data2[1], dtime_data2[2]);
		break;

	case 0x24: // Month to hour
  		SPRINTF3 (buff, "0000-%02d-%02d %02d",
               		dtime_data2[1], dtime_data2[2], dtime_data2[3]);
		break;

	case 0x25: // Month to minute
  		SPRINTF4 (buff, "0000-%02d-%02d %02d:%02d",  dtime_data2[1], dtime_data2[2], dtime_data2[3], dtime_data2[4]);
		break;

	case 0x26: // Month to second
  		SPRINTF5 (buff, "0000-%02d-%02d %02d:%02d:%02d", dtime_data2[1], dtime_data2[2], dtime_data2[3], dtime_data2[4], dtime_data2[5]);
		break;

	case 0x27: // Month to fraction(1)
	case 0x28: // Month to fraction(2)
	case 0x29: // Month to fraction(3)
	case 0x2a: // Month to fraction(4)
	case 0x2b: // Month to fraction(5)
  		SPRINTF6 (buff, "0000-%02d-%02d %02d:%02d:%02d.%05d",  dtime_data2[1], dtime_data2[2], dtime_data2[3], dtime_data2[4], dtime_data2[5], dtime_data2[6]);
		break;



// **************************
	case 0x33: // day to day
  		SPRINTF1 (buff, "0000-00-%02d",  dtime_data2[2]);
		break;

	case 0x34: // day to hour
  		SPRINTF2 (buff, "0000-00-%02d %02d", dtime_data2[2], dtime_data2[3]);
		break;

	case 0x35: // day to minute
  		SPRINTF3 (buff, "0000-00-%02d %02d:%02d",   dtime_data2[2], dtime_data2[3], dtime_data2[4]);
		break;

	case 0x36: // day to second
  		SPRINTF4 (buff, "0000-00-%02d %02d:%02d:%02d",  dtime_data2[2], dtime_data2[3], dtime_data2[4], dtime_data2[5]);
		break;

	case 0x37: // day to fraction(1)
	case 0x38: // day to fraction(2)
	case 0x39: // day to fraction(3)
	case 0x3a: // day to fraction(4)
	case 0x3b: // day to fraction(5)
  		SPRINTF5 (buff, "0000-00-%02d %02d:%02d:%02d.%05d",   dtime_data2[2], dtime_data2[3], dtime_data2[4], dtime_data2[5], dtime_data2[6]);
		break;


// **************************

	case 0x44: // hour to hour
  		SPRINTF1 (buff, "0000-00-00 %02d",  dtime_data2[3]);
		break;

	case 0x45: // hour to minute
  		SPRINTF2 (buff, "0000-00-00 %02d:%02d",   dtime_data2[3], dtime_data2[4]);
		break;

	case 0x46: // hour to second
  		SPRINTF3 (buff, "0000-00-00 %02d:%02d:%02d",  dtime_data2[3], dtime_data2[4], dtime_data2[5]);
		break;

	case 0x47: // hour to fraction(1)
	case 0x48: // hour to fraction(2)
	case 0x49: // hour to fraction(3)
	case 0x4a: // hour to fraction(4)
	case 0x4b: // hour to fraction(5)
  		SPRINTF4 (buff, "0000-00-00 %02d:%02d:%02d.%05d",    dtime_data2[3], dtime_data2[4], dtime_data2[5], dtime_data2[6]);
		break;

// **************************


	case 0x55: // minute to minute
  		SPRINTF1 (buff, "0000-00-00 00:%02d",    dtime_data2[4]);
		break;

	case 0x56: // hour to second
  		SPRINTF2 (buff, "0000-00-00 00:%02d:%02d",   dtime_data2[4], dtime_data2[5]);
		break;

	case 0x57: // hour to fraction(1)
	case 0x58: // hour to fraction(2)
	case 0x59: // hour to fraction(3)
	case 0x5a: // hour to fraction(4)
	case 0x5b: // hour to fraction(5)
  		SPRINTF3 (buff, "0000-00-00 00:%02d:%02d.%05d",     dtime_data2[4], dtime_data2[5], dtime_data2[6]);
		break;

// **************************


	case 0x66: // second to second
  		SPRINTF1 (buff, "0000-00-00 00:00:%02d",    dtime_data2[5]);
		break;

	case 0x67: // hour to fraction(1)
	case 0x68: // hour to fraction(2)
	case 0x69: // hour to fraction(3)
	case 0x6a: // hour to fraction(4)
	case 0x6b: // hour to fraction(5)
  		SPRINTF2 (buff, "0000-00-00 00:00:%02d.%05d",      dtime_data2[5], dtime_data2[6]);
		break;


	default: A4GL_assertion(1,"Unhandled EXTEND"); break;
	}

  A4GL_push_char(buff);
  A4GL_pop_var2 (&c, DTYPE_DTIME, n);

  A4GL_push_dtime (&c);
}

/**
 * @todo Describe function
 *
 * @param s
 * @param n
 */
void
acli_interval (char *s, int n)
{
  struct_ival c;
  //char *ptr;
  A4GL_debug ("acli_interval s=%s n=%d\n", A4GL_null_as_null(s), n);
  memset(&c,0,sizeof(c));
  c.ltime = n & 16;
  c.stime = n / 16;
  A4GL_ctoint (s, &c, n);
  A4GL_debug ("acli_interval - pop'd c - n=%x", n);
  A4GL_push_interval (&c);

}

/**
 * @todo Describe function
 *
 * @param s
 * @param n
 */
void
acli_datetime (char *s, int n)
{
  struct_dtime c;
  //char *ptr;
  char buff[255];

  A4GL_debug ("acli_datetime s=%s n=%d\n", A4GL_null_as_null(s), n);
  c.ltime = n & 16;
  c.stime = n / 16;
  A4GL_ctodt (s, &c, n);
  A4GL_push_dtime (&c);
  A4GL_debug ("ADDED DATETIME TO STACK - %d %d", c.stime, c.ltime);

  A4GL_pop_char (buff, 40);
  A4GL_push_dtime (&c);

}



/**
 * @todo Describe function
 *
 * @param name
 */
char *
aclfgli_str_to_id (char *name)
{
  static char buff[1024];
  char *ptr;

  if (A4GL_has_pointer(name,ACLFGLI_STR_TO_ID)) {
	return A4GL_find_pointer(name,ACLFGLI_STR_TO_ID);
  }

  strcpy (buff, name);
  A4GL_trim (buff);
  A4GL_make_downshift(buff);
  ptr=acl_strdup(buff);

  A4GL_add_pointer(name,ACLFGLI_STR_TO_ID,ptr);

  return ptr;
}

/**
 * @todo Describe function
 *
 * @param n
 */
int
aclfgl_ascii (int n)
{
  A4GL_push_ascii ();
  return 1;
}


/**
 * @todo - implement acli_scroll
 *
 * @param s
 * @param n
 *
**/

void A4GL_acli_scroll (int n,...) 
{
va_list ap;
va_start(ap,n);
  A4GL_acli_scroll_ap(n,&ap);
}


/* 
========================================================================
                         4Js built-in functions emulation
========================================================================
*/


/**
 * 4Js specific - Dynamic Data Exchange - MS Windows only
 * let success = DDEPoke("IEXPLORE","system","www_OpenURL","http://www.fgss.com")
 * @todo - implement it
 *
 * @param s
 * @param n
 *
**/
int
aclfgl_ddepoke (char *progname, char *ddemessage, char *ddecommand,
		char *ddeparam)
{
  A4GL_exitwith ("4Js DDE functions not implemented");
  return 0;
}



//      LET var = DDEFinish( progname, "System" )
char *
aclfgl_ddefinish (char *progname, char *ddemessage)
{
  A4GL_exitwith ("4Js DDE functions not implemented");
  return 0;
}


/**
 * 4Js specific
 * if not DDEexecute("WINWORD", "System", str) then
 * @todo - implement it
 *
 * @param progname name of the running program to establist a DDE link to
 * @param ddemessage message to pass to the program via DDE link
 *
 * @return 1 on success, otherwise 0
 *
**/
int
aclfgl_ddeexecute (char *progname, char *ddemessage, char *ddecommand)
{
  A4GL_exitwith ("4Js DDE functions not implemented");
  return 0;
}

//      LET p_text = DDEGeterror()
char *
aclfgl_ddegeterror (void)
{
  A4GL_exitwith ("4Js DDE functions not implemented");
  return 0;
}



/**
 * 4Js specific
 * let success = DDEConnect("IEXPLORE","system")
 * @todo - implement it
 *
 * @param progname name of the running program to establist a DDE link to
 * @param ddemessage message to pass to the program via DDE link
 *
 * @return 1 on success, otherwise 0
 *
**/
int
aclfgl_ddeconnect (char *progname, char *ddemessage)
{
  A4GL_exitwith ("4Js DDE functions not implemented");
  return 0;
}


//   CALL DDEFinishAll()
void
aclfgl_ddefinishall (void)
{
  A4GL_exitwith ("4Js DDE functions not implemented");
}


/**
 * Strings containing characters such as \ need to be passed through
 * fgl_strtosend() as this re-formats them so that MS Word will see the
 * correct sring.
**/
char *
aclfgl_fgl_strtosend (char *str)
{
  A4GL_exitwith ("4Js DDE functions not implemented");
  return 0;
}


/**
 * 4Js specific
 * let response = DDEPeek("IEXPLORE","system","www_GetWindowInfo")
 * @todo - implement it
 *
 * @param progname name of the running program to establist a DDE link to
 * @param ddemessage message to pass to the program via DDE link
 *
 * @return 1 on success, otherwise 0
 *
**/
char *
aclfgl_ddepeek (char *progname, char *ddemessage, char *ddecommand)
{
  A4GL_exitwith ("4Js DDE functions not implemented");
  return 0;
}


/**
 * CALL FGL_KEYSETLABEL ("return", "Next")
 * 4Js compatibility - 
 * inside dialog use dialog.keysetlabel("key", "label") instead
 * 
 * (deprecated, use fgl_setkeylabel() or fgl_dialog_setkeylabel() instead)
**/
void
aclfgl_fgl_keysetlabel (char *keyName, char *labelText)
{
  A4GL_exitwith ("4Js keysetlabel function not implemented");
}

/**
 * call fgl_winmessage("MS Word Start Up Error", "MS Word could not be started", "stop")
 * 4Js compatibility - opens message window
 *
**/
void
aclfgl_fgl_winmessage (char *windowTitle, char *message, char *iconType)
{
  A4GL_exitwith ("4Js winmessage function not implemented");
}


//LET success = WinExecWait(exec_string)
int
aclfgl_winexecwait (char *exec_string)
{
  A4GL_exitwith ("4Js winexecwait function not implemented");
  return 0;
}

//LET success = WinExec(exec_string)
int
aclfgl_winexec (char *exec_string)
{
  A4GL_exitwith ("4Js winexec function not implemented");
  return 0;
}



int aclfgl_fgl_getkey(int n) {
	int a;
	A4GL_debug("FGL1");
	A4GLSQL_set_status (0, 0);
	a=0;
	while (a==0) {
		a=A4GL_get_key(-1);
		
	}
	A4GL_push_long(a);
	return 1;
}

int aclfgl_fgl_getkey_wait(int n) {
	int a;
	int wait;
	long s;
	long t;
	s=(long) time(0);
	A4GL_debug("FGL1");
	wait=A4GL_pop_long();
	
	A4GLSQL_set_status (0, 0);
	while (1) {
		a=A4GL_get_key(wait);
		t=(long)time(0);
		if (t-s>n || a) break;
	}
	A4GL_push_long(a);
	return 1;
}


void A4GL_log_error(int lineno,char *fname,int mstatus) {
char s[2048];
A4GL_generateError (s, fname, lineno);
      if (strcmp (fname, "Unknown") != 0 && A4GL_has_errorlog ())
        {
          A4GL_push_char (s);
          A4GL_errorlog (fname, lineno, 1);
        }

}





/* ================================== EOF ============================= */

























/* 4Js functions */

int aclfgl_fgl_scr_size(int n)  {
// fgl_scr_size(char *srecname)
	struct struct_screen_record *srec;
	char *s;

	s=A4GL_char_pop();
	A4GL_trim(s);
	srec=A4GL_get_srec(s);
	if(!srec) {
		A4GL_debug("screen record '%s' not found in current form", s);
		A4GL_push_long(-1);
	} else {
		A4GL_push_long(srec->dim);
	}
	acl_free(s);
	return 1;
}

int aclfgl_fgl_dialog_setcurrline(int n) {
// fgl_dialog_setcurrline ( screen_line, array_row )
	int screen_line, array_row;
	array_row = A4GL_pop_int();
	screen_line = A4GL_pop_int();
	A4GL_push_int(array_row);
	aclfgl_fgl_set_arrline(1);
	A4GL_push_int(screen_line);
	aclfgl_fgl_set_scrline(1);
	return 0;
}

int aclfgl_fgl_dialog_getfieldname(int n)  {
//function returns the name of the current field.
	A4GL_debug ("WARNING: fgl_dialog_getfieldname() not yet implemented!");
	A4GL_push_char("");
	return 1;
}


int aclfgl_fgl_dialog_getbuffer(int n)  {
// returns the value of the current field:
	A4GL_debug ("WARNING: fgl_dialog_getbuffer() not yet implemented!");
	A4GL_push_char("");
	return 1;
}

int aclfgl_fgl_dialog_setbuffer(int n) {
// function sets the value of the current field:
	char *p1 = A4GL_char_pop();
	A4GL_debug ("WARNING: fgl_dialog_setbuffer() not yet implemented!");
	free(p1);
	return 0;
}

int aclfgl_fgl_buffertouched(int n)  {
// Returns  INTEGER  TRUE if the last field has been modified.
	A4GL_debug ("WARNING: fgl_buffertouched() not yet implemented!");
	A4GL_push_int(1);
	return 1;
}


int aclfgl_fgl_setkeylabel(int n)  {
	char *p1;
	char *p2;
	A4GL_debug ("WARNING: fgl_setkeylabel() not yet implemented!");
	p1=A4GL_char_pop();
	p2=A4GL_char_pop();
	free(p1);
	free(p2);
	return 0;
}

int aclfgl_fgl_dialog_setkeylabel(int n)  {
	char *p1;
	char *p2;
	A4GL_debug ("WARNING: fgl_dialog_setkeylabel() not yet implemented!");
	p1=A4GL_char_pop();
	p2=A4GL_char_pop();
	free(p1);
	free(p2);
	return 0;
}


int aclfgl_fgl_compare(int n) {
	int a;
	int ok;
	int half;
	char **compares;


	if (n%2!=0) {
			A4GL_pop_args(n);
		        A4GL_push_int(0);
		        return 1;
	}

	half=n/2;
	compares=malloc(sizeof(char*)*n);

	for (a=n-1;a>=0;a--) {
		        compares[a]=A4GL_char_pop();
	}
	ok=1;
	for (a=0;a<half;a++) {
		        A4GL_push_char(compares[a]);
			        A4GL_push_char(compares[a+half]);
				        A4GL_pushop(OP_EQUAL);
					        if (!A4GL_pop_bool()) {
							                ok=0; break;
									        }
	}
	for (a=0;a<n;a++) {
		free(compares[a]);
	}
	free(compares);
	A4GL_push_int(ok);
	return 1;
}



int A4GL_strstartswith(char *s,char *w) {
	return (strncmp(s,w,strlen(w))==0);
}

int aclfgl_fgl_round(int nargs) {
	double d;
	char buff[256];
	char smbuff[200];
	int places;
  if (nargs != 2)
    {
      /* A4GL_pop_args(nargs);set_status(-3001); */
      A4GL_pop_args (nargs);
      A4GLSQL_set_status (-3001, 0);
      return 0;
    }
	places=A4GL_pop_int();
	d=A4GL_pop_double();
	SPRINTF1(buff,"%%.%dlf",places);
	SPRINTF1(smbuff,buff,d);
	A4GL_push_char(smbuff);
	return 1;
}


int aclfgl_fgl_settitle(int n) {
	return aclfgl_set_window_title(n);
}

int aclfgl_fgl_getpid(int n) {
	A4GL_push_int(getpid());
	return 1;
}



/*
 fgl_winquestion(title, text, default_value, possible_values, icon, danger)
  
  - title Title of the dialog box.
  - text Text of the question (\n stands for new line).
  - default_value Answer on which the focus has to be positioned.
  - possible_values List of values separated by the pipe character (|).
  - icon Name of the icon to be used in the dialog box.
  - danger Number of the warning item: a skull with crossbones
           appears each time the pointer enters the corresponding
	    button (on X11 only).
*/
int aclfgl_fgl_winquestion(int nargs) {
	char *title;
	char *text;
	char *def;
	char *pos;
	char *icon;
	int danger;
	if (nargs!=6) {
      		A4GL_pop_args (nargs);
      		A4GLSQL_set_status (-3001, 0);
      		return 0;
	}

	danger=A4GL_pop_int();
	icon=A4GL_char_pop();
	pos=A4GL_char_pop();
	def=A4GL_char_pop();
	text=A4GL_char_pop();
	title=A4GL_char_pop();
	A4GL_push_char(A4GL_ui_fgl_winquestion(title,text,def,pos,icon,danger,0));
	return 0;
}

/*
 fgl_winbutton(title, text, default_value, possible_values, icon, danger)
  
  - title Title of the dialog box.
  - text Text of the question (\n stands for new line).
  - default_value Answer on which the focus has to be positioned.
  - possible_values List of values separated by the pipe character (|).
  - icon Name of the icon to be used in the dialog box.
  - danger Number of the warning item: a skull with crossbones
           appears each time the pointer enters the corresponding
	    button (on X11 only).
*/
int aclfgl_fgl_winbutton(int nargs) {
	char *title;
	char *text;
	char *def;
	char *pos;
	char *icon;
	int danger;
	if (nargs!=6) {
      		A4GL_pop_args (nargs);
      		A4GLSQL_set_status (-3001, 0);
      		return 0;
	}

	danger=A4GL_pop_int();
	icon=A4GL_char_pop();
	pos=A4GL_char_pop();
	def=A4GL_char_pop();
	text=A4GL_char_pop();
	title=A4GL_char_pop();
	A4GL_push_char(A4GL_ui_fgl_winquestion(title,text,def,pos,icon,danger,1));
	return 0;
}


int
aclfgl_aclfgl_getcwd (int a)
{
  char buff[512];
  char buff2[512];


#ifdef MSVC
	  _getcwd (buff, 512);
#else
	  getcwd (buff, 512);
#endif

   A4GL_push_char(buff);
   return 1;
}



int aclfgl_aclfgl_replace_start(int nargs) {
char buff[256];
char *rpl_with;
char *rpl_start;
char *str;
	if (nargs!=3) {
      		A4GL_pop_args (nargs);
      		A4GLSQL_set_status (-3001, 0);
      		return 0;
	}
	rpl_with=A4GL_char_pop();
	rpl_start=A4GL_char_pop();
	str=A4GL_char_pop();

	if (strncmp(str,rpl_start,strlen(rpl_start))==0) {
		SPRINTF2(buff,"%s%s",rpl_with,&str[strlen(rpl_start)]);
		A4GL_push_char(buff);
	} else {
		A4GL_push_char(str);
	}
	free(rpl_with); free(rpl_start); free(str);
	return 1;
}



int aclfgl_aclfgl_call_in_shared(int a) {
char *ptr1;
char *ptr2;
char *ptr3;

	ptr1=A4GL_char_pop();
	ptr2=A4GL_char_pop();
	A4GL_convlower(ptr1);

 	return A4GL_call_4gl_dll (ptr2,ptr1, a-2);

return 0;
}
