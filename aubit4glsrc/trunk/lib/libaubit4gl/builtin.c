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
# $Id: builtin.c,v 1.57 2004-04-21 14:45:33 mikeaubury Exp $
#
*/

/**
 * @file
 * Implementation of builtin, internal functions of informix 4gl standard
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

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

int m_arr_count = 0;
int m_arr_curr = 0;
int m_scr_line = 0;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

/*
	Note : all functions with aclfgl_ prefix are callable from
	compiled 4gl code, since all references to functions get aclfgl_ prefix
	appended to them by 4gl compiler. Therefore, compiled 4gl code CANNOT
    call any function in Aubit libraries without aclfgl prefix.
*/

FILE *error_log_file = 0;
/*
=====================================================================
                    Functions definitions
=====================================================================
*/

int aclfgl_ddepoke (char *progname, char *ddemessage, char *ddecommand, char *ddeparam);

char * aclfgl_ddefinish (char *progname, char *ddemessage);
int aclfgl_fgl_getkey(int n) ;

int aclfgl_ddeexecute (char *progname, char *ddemessage, char *ddecommand);

char *A4GL_pull_off_data_for_display(int n,int display_type);
char * aclfgl_ddegeterror (void);

int aclfgl_ddeconnect (char *progname, char *ddemessage);

void aclfgl_ddefinishall (void);

char * aclfgl_ddepeek (char *progname, char *ddemessage, char *ddecommand);

void aclfgl_fgl_winmessage (char *windowTitle, char *message, char *iconType);

char * aclfgl_fgl_strtosend (char *str);

int aclfgl_winexecwait (char *exec_string);

int aclfgl_winexec (char *exec_string);
int aclfgli_show_help (int a);

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
    {&a, 2, 0}			/* initializer element is not computable at load time (near initialization for `fbind[0].ptr') */
  };				/* end of binding */
  if (nargs != 1)
    {
      /* A4GL_pop_args(nargs);set_status(-3001); */
      A4GL_pop_args (nargs);
      A4GLSQL_set_status (-3001, 0);

      return 0;
    }
  A4GLSQL_set_status (0, 0);
  A4GL_pop_params (fbind, 1);
  m_arr_count = a;
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
  A4GL_push_long (m_arr_count);
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
  A4GL_push_long (m_scr_line);
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
  A4GL_push_long (m_arr_curr);
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
  p = acl_getenv (g);
  A4GL_debug("Got back %p");
  if (p) A4GL_debug(" %s = '%s'",A4GL_null_as_null(g),A4GL_null_as_null(p));
  if (p == 0)
    A4GL_push_char ("");
  else
    A4GL_push_char (p);
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
  int p;
  if (nargs != 1)
    {
      A4GL_pop_args (nargs);
      A4GLSQL_set_status (-3001, 0);
      return 0;
    }
  g = A4GL_char_pop ();
  if (A4GL_isnull(0,g)) {
		A4GL_push_int(0);
		return 1;
	}
  A4GL_trim (g);
  p = strlen (g);
  A4GL_push_int (p);
  acl_free (g);
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
  va_list ap;
  //printf ("a=%d b=%d\n", a, b);
  va_start (ap, b);
  va_end (ap);
  A4GL_debug("Entering a4gl_substr");
  if (A4GL_isnull(0,ca)) return "";


#ifdef DEBUG
  {
    A4GL_debug ("substr");
  }
#endif
  if (np != 0)
    acl_free (np);
  if (np2 != 0)
    acl_free (np2);
  np = strdup (ca);
  np2 = strdup (ca);


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
      //printf("PAD\n");
      free (np);
      np = malloc (DECODE_SIZE (dtype) + 1);
      free (np2);
      np2 = malloc (DECODE_SIZE (dtype) + 1);
      A4GL_pad_string (np, DECODE_SIZE (dtype));
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

  strncpy (np2, &np[a], b - a + 1);
  np2[b - a + 1] = 0;
#ifdef DEBUG
  {
    A4GL_debug (">>>>Set to %s", A4GL_null_as_null(np2));
  }
#endif
  //printf ("np2= '%s'\n", np2);
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
  }
  {
    A4GL_debug ("   Size=%d", size);
  }
#endif
  strncpy (&ca[a - 1], np, size);
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
 A4GL_debug("m_arr_count=%d XYX",m_arr_count);
  return m_arr_count;
}

/**
 * Set the current position in input array
 *
 * @param a The position to be setted.
 */
void
A4GL_set_arr_curr (int a)
{
  m_arr_curr = a;
  A4GL_gui_scrollpos (a);
}

/**
 * Set the last array position.
 *
 * @param a The index of the last array position used.
 */
void
A4GL_set_arr_count (int a)
{
  m_arr_count = a;
  A4GL_gui_scroll (a);
}

/**
 * Set the screen line
 *
 * @param a The screen line to be setted.
 */
void
A4GL_set_scr_line (int a)
{
  m_scr_line = a;
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
  m_arr_curr = a;
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
  m_scr_line = a;
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

  for (b = 0; b < strlen (s); b++)
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

  for (b = strlen (s) - 1; b >= 0; b--)
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
  sprintf (buff, "Error : %d ", a);
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
  error_log_file = fopen (s, "w");

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
A4GL_errorlog (char *fname, int l, int n)
{
  char *s;
  char *date_str;
  char *time_str;
  //int d;

  //s = A4GL_char_pop ();
  s=A4GL_pull_off_data_for_display(n,DISPLAY_TYPE_DISPLAY_AT);
  A4GL_debug ("ERROR LOG - %s Line:%d %s\n", A4GL_null_as_null(fname), l, A4GL_null_as_null(s));

  if (error_log_file)
    {
      A4GL_push_current (1, 3);
      date_str = A4GL_char_pop ();

      A4GL_push_current (4, 6);
      time_str = A4GL_char_pop ();

      fprintf (error_log_file, "Date: %s    Time: %s\n", date_str, time_str);
      if (A4GL_isyes (acl_getenv ("EXTENDED_ERRORLOG")))
	{
	  fprintf (error_log_file, "MODULE : %s    Line: %d\n", fname, l);

	}
      fprintf (error_log_file, "%s\n", s);
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
  if (error_log_file)
    {
      fclose (error_log_file);
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
  if (A4GL_has_pointer ("default", SESSCODE))
    {
      A4GLSQL_close_session ("default");
      A4GL_del_pointer ("default", SESSCODE);
    }
  return;
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
  n = A4GL_pop_int ();
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
  //printf("--1>%s\n",s);
  A4GL_ctodt (s, &c, n);
  //printf("acli_dtime - pop'd c - n=%x\ndata=%s\n",n,c.data);
  A4GL_push_dtime (&c);
  A4GL_debug ("ADDED DATETIME TO STACK - %d %d", c.stime, c.ltime);

  A4GL_pop_char (buff, 40);
  //printf("DOUBLE CHECK GIVES : %s\n",buff);
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

  strcpy (buff, name);
  A4GL_trim (buff);
  return buff;
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
 * call fgl_winmessage("MS Word Start Up Error", "MS Word could not be started.\nMaybe wrong path?", "stop")
 *
**/
void
aclfgl_fgl_winmessage (char *windowTitle, char *message, char *iconType)
{
  A4GL_exitwith ("4Js winmessage function not implemented");
  //return 0;
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
	a=A4GL_get_key(-1);
	A4GL_push_long(a);
	return 1;
}


/* ================================== EOF ============================= */
