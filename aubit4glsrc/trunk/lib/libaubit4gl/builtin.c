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
# $Id: builtin.c,v 1.17 2003-02-08 17:40:52 mikeaubury Exp $
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
include_builtin_in_exe(void)
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
  struct BINDING fbind[] =
  {
    {&a, 2, 0} /* initializer element is not computable at load time (near initialization for `fbind[0].ptr') */
  };				/* end of binding */
  if (nargs != 1)
    {
	/* pop_args(nargs);set_status(-3001); */
      pop_args(nargs);A4GLSQL_set_status(-3001,0);

      return 0;
    }
  A4GLSQL_set_status(0,0);
  pop_params (fbind, 1);
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
      pop_args(nargs);A4GLSQL_set_status(-3001,0);
      return 0;
    }
  push_int (m_arr_count);
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
      pop_args(nargs);A4GLSQL_set_status(-3001,0);
      return 0;
    }
  push_int (m_scr_line);
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
      pop_args(nargs);A4GLSQL_set_status(-3001,0);
      return 0;
    }
  push_int (m_arr_curr);
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
      pop_args(nargs);A4GLSQL_set_status(-3001,0);
      return 0;
    }
  g = char_pop ();
  trim(g);
  debug("Looking up %s",g);
  p = acl_getenv (g);
  if (p == 0)
    push_char ("");
  else
    push_char (acl_getenv (g));
  acl_free (g);
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
      pop_args(nargs);A4GLSQL_set_status(-3001,0);
      return 0;
    }
  g = char_pop ();
  trim(g);
  p = strlen (g);
  push_int (p);
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
substr (char *ca, int dtype, int a, int b, ...)
{
  static char *np = 0;
  static char *np2 = 0;
  va_list ap;
  //printf ("a=%d b=%d\n", a, b);
  va_start (ap, b);
  va_end (ap);

#ifdef DEBUG
  {
    debug ("substr");
  }
#endif
  if (np != 0) acl_free (np);
  if (np2 != 0) acl_free (np2);
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
	debug ("NULL");
      }
#endif
      //printf("PAD\n");
      pad_string (np, DECODE_SIZE (dtype));
    }
  a--;
  b--;

#ifdef DEBUG
  {
    debug (">>>>Start with %s", np);
  }
  {
    debug (">>>>a=%d b=%d dtype=%d,\n ", a, b, dtype);
  }
#endif

  if (b == -1)
    b = a;
#ifdef DEBUG
  {
    debug (">>>>Allocated %d bytes", b - a + 2);
  }
#endif

  strncpy (np2, &np[a], b - a + 1);
  np2[b - a + 1] = 0;
#ifdef DEBUG
  {
    debug (">>>>Set to %s", np2);
  }
#endif
  //printf ("np2= '%s'\n", np2);
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
let_substr (char *ca, int dtype, int a, int b,...)
{
  char *np;
  int size;
#ifdef DEBUG
  {    debug ("let_substr");  }
#endif
  pad_string (ca, DECODE_SIZE (dtype));
#ifdef DEBUG
  {    debug ("Start with '%s'", ca);  }
  {    debug ("a=%d b=%d dtype=%d,\n ", a, b, dtype);  }
#endif
  if (b == 0)
    b = a;
  size = b - a + 1;
  np = (char *)acl_malloc (size + 1, "let_substr");
  pop_char (np, size);
#ifdef DEBUG
  {    debug ("   Stack contained %s\n", np);  }
  {    debug ("   Size=%d", size);  }
#endif
  strncpy (&ca[a - 1], np, size);
#ifdef DEBUG
  {    debug ("Set to %s", ca);  }
#endif
  return ca;
}

/**
 * The get count for INPUT ARRAY.
 */
int
get_count (void)
{
  return m_arr_count;
}

/**
 * Set the current position in input array
 *
 * @param a The position to be setted.
 */
void
set_arr_curr (int a)
{
  m_arr_curr = a;
  gui_scrollpos (a);
}

/**
 * Set the last array position.
 *
 * @param a The index of the last array position used.
 */
void
set_arr_count (int a)
{
  m_arr_count = a;
  gui_scroll (a);
}

/**
 * Set the screen line
 *
 * @param a The screen line to be setted.
 */
void
set_scr_line (int a)
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
strcasecmp (const char* s1, const char* s2)
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

extern int	strcasecmp (const char*, const char*);

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
getuid(void)
{
    return 50;
}


#endif



/*
The STARTLOG( ) function opens an error log file.

filename is a quoted string to specify a filename (and optional path name
and file extension) of the error log file.

Variable is a variable of type CHAR or VARCHAR containing a filename
(and optional path name and file extension) of the error log file.

The following is a typical sequence to implement error logging:

Call STARTLOG( ) in the MAIN program block to open or create an error log file.

Use a LET statement with ERR_GET(status) to retrieve the error text and
to assign this value to a program variable.

Use ERRORLOG( ) to make an entry into the error log file.

The last two steps are not needed, if you are satisfied with the error
records that are automatically produced after STARTLOG( ) has been invoked.
After you call the STARTLOG( ) function, a record of every subsequent error
that occurs during the execution of your program is written to the error
log file, provided that the WHENEVER ERROR CONTINUE statement is not in
effect.

The error record consists of the date, time, source-module name and
line number, error number, and error message. You can also write your
own messages in the error log file by using the ERRORLOG( ).
*/



/**
 * fake function for err_get()
 *
 * @param statusnumber 
 */
int
aclfgl_err_get(int n) 
{
int a;
static char buff[200];
	a=pop_int();
	/* A4GLSQL_set_status(-3001,0); */
	sprintf(buff,"Error : %d ",a);
	push_char(buff);
      return 1;
}


/**
 * fake function for ERR_PRINT( )
 *
 *
 */
int
aclfgl_err_print(int statusnumber)
{

	/*  A4GLSQL_set_status(-3001,0); */
      return 0;
}


/**
 * fake function for ERR_QUIT( )
 */
int
aclfgl_err_quit(int statusnumber)
{

	/*  A4GLSQL_set_status(-3001,0); */
      return 0;
}


/**
 *
 *
 * @param
 */
int
aclfgl_startlog (char *filename)
/* start_log (filename, 4glmodule, 4gllinenumber) */
{

	/*  A4GLSQL_set_status(-3001,0); */
      return 0;
}


/**
 * The ERRORLOG( ) function copies its argument into the current error log file.
 */
int
aclfgl_errorlog (char *string)
/* error_log(string, 4glmode, 4gllinenumber) */

{

	/*  A4GLSQL_set_status(-3001,0); */
      return 0;
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

	/*  A4GLSQL_set_status(-3001,0); */
      return 0;
}


/*
P12.ao: In function `main':
P12.ao(.text+0x3c): undefined reference to `def_quit'
*/



/**
 * The FIELD_TOUCHED( ) operator tests whether the user has entered or
 * edited a value in a specified field or list of fields of the current 4GL 
 * form. (This operator can only appear within CONSTRUCT, INPUT, and INPUT
 * ARRAY statements.)
 * 
 * Usage:
 * input by name pr_globals.vouch_date, ...
 * ...
 * if not field_touched(year_num) then
 * 
 * 
 * 
 * Built-in functions that access field buffers and keystroke buffers:
 * 
 * Built-In Funtion 		Description
 * FIELD_TOUCHED(field)	Returns TRUE when the user has made a change to 
 *   screen field.
 * GET_FLDBUF(field-list) Returns the character values of the contents of 
 *   one or more fields.
 * FGL_LASTKEY( ) Returns an INTEGER value corresponding to the most recent 
 *   keystroke.
 * INFIELD(field) Returns TRUE if field is the name of the current screen field.
 * FGL_GETKEY
 * FGL_KEYVAL( )
 * 
 * 
 * See Informix 7.3 manual
 */
int
fgl_fieldtouched(char *fieldname)
{
    /* fieldname should be array */
      return 0;
}



/**
 * close database
 *
 */
void
close_database(void)
{
  if (has_pointer ("default", SESSCODE))
    {
           A4GLSQL_close_session("default");
           del_pointer("default",SESSCODE);
    }
    return;
    return;
}



void aclfgli_current(int a,int b) {
	push_current(a,b);
}

void aclfgli_extend() {
	// FIXME
}

char *aclfgli_str_to_id(char *name) 
{
static char buff[1024];
	
	strcpy(buff,name);
	trim(buff);
	return buff;
}

int aclfgl_ascii(int n) {
		int a;
		push_ascii();
		return 1;
}
/* ================================== EOF ============================= */

