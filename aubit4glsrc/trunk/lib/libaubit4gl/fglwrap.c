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
# $Id: fglwrap.c,v 1.41 2003-06-12 17:39:45 mikeaubury Exp $
#
*/

/**
 * @file
 * Wrapper functions to call fgl from c, system from fgl and environment
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen A4GL_comments to add to functions
 */

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

//#define DEFINE_INTFLAG
//#define DEFINE_QUITFLAG
#define _DEFINE_STATUSVARS_	/* one place we have to DEFINE them, for the
				   rest of source files, they get only DECLARED
				   as extern */

/* FIXME: we should not need to pre-load anything */
//#define _PRELOAD_SQL_		/* pre-load SQL module */
#define _PRELOAD_REPORT_	/* pre-load EXREPORT module */
#define _PRELOAD_UI_		/* pre-load UI module */

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

int p_numargs = 0;
int isdebug = 0;
int ui_mode = 0;
static int initsig_child(void );

/* extern int errno; */
#include <errno.h>

char *p_args[256];


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

extern int A4GL_start_gui (void);
void A4GL_nodef_init (void);
//void A4GL_fgl_end (void);
//void A4GL_fgl_start (int nargs, char *argv[]);
//void A4GL_system_run (int a);
void A4GL_generateError (char *str, char *fileName, int lineno);
void A4GL_null_func (void);
int A4GL_ass_hash (char **a, int s, int d, char *str, long size, int rw);
void A4GL_set_intr (void);
void A4GL_def_int (void);
void A4GL_def_quit (void);
char *A4GL_clob (char *s, char *p);



/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Function called when a 4gl program terminates is execution.
 *
 * If in curses mode exit curses.
 */
void
A4GL_fgl_end (void)
{
  if (A4GL_isscrmode ())
    {
#ifdef DEBUG
      A4GL_debug ("In screen mode - ending curses...");
#endif
      A4GL_gotolinemode ();
    }
  A4GL_close_database ();
  A4GL_close_errorlog_file ();
  A4GL_debug ("End of program - exit(0).");
  exit (0);
}

/**
 * function called on initialization of every Aubit compiled 4gl program:
 *
 * Command line arguments to compiled 4gl program can be:
 *
 * GUIPORT    	- FIXME: what is it?
 * NOCURSES     - FIXME: this is now A4GL_UI=CONSOLE
 *
 * @param nargs The number of arguments.
 * @param argv The arguments values.
 */
void
A4GL_fgl_start (int nargs, char *argv[])
{
  int a;
  int b = 0;
  void *ptr;
  char *p;

  /* 
     This does nothing - but we NEED IT!
     If builtin is not in the executable then we get link errors 
     todo: wind out why is this needed
   */
  A4GL_include_builtin_in_exe ();

  /* Initialise external datatypes module */
  A4GL_init_datatypes ();

  /* load settings from config file(s): */
  A4GL_build_user_resources ();


#ifdef _PRELOAD_SQL_
  if (!A4GLSQL_initlib ())
    {
      printf
	("4gllib: Error opening SQL Library - check A4GL_SQLTYPE is set correctly (A4GL_SQLTYPE=%s)\n",
	 acl_getenv ("A4GL_SQLTYPE"));
      exit (1);
    }

#ifdef DEBUG
  A4GL_debug ("Connecting to database...");
#endif
  A4GLSQL_initsqllib ();
#endif

  if (acl_getenv ("A4GL_UI"))
    {
      p = acl_getenv ("A4GL_UI");

      //where is CONSOLE?
      if (A4GL_aubit_strcasecmp (p, "TEXT") == 0)
	ui_mode = 0;
      if (A4GL_aubit_strcasecmp (p, "CURSES") == 0)
	ui_mode = 0;
      if (A4GL_aubit_strcasecmp (p, "GTK") == 0)
	ui_mode = 1;
      if (A4GL_aubit_strcasecmp (p, "GUI") == 0)
	ui_mode = 1;
    }

  p_numargs = nargs;
  setlocale (LC_ALL, "");
  setlocale (LC_CTYPE, "");
#ifdef DEBUG
  {
    A4GL_debug ("Starting 4gl program - %d arguments argv=%p", nargs, argv);
  }
#endif


  /* FIXME: we already printed something to stdout at this point... */
  /* printf("Check.."); */

  b = 0;
  for (a = 0; a < 256; a++)
    {
      if (a < nargs)
	{
	  if (argv[a])
	    {
	      /* FIXME: wha is this used for? */
	      if (strncmp (argv[a], "GUIPORT", 7) == 0)
		{
#ifdef DEBUG
		  A4GL_debug ("GUIMODE");
#endif
		  putenv (argv[a]);
		  continue;
		}

	      /* FIXME: this is now A4GL_UI=CONSOLE */
	      if (strncmp (argv[a], "NOCURSES", 8) == 0)
		{
#ifdef DEBUG
		  A4GL_debug ("NOCURSES");
#endif
		  putenv (argv[a]);
		  continue;
		}
	    }
	}

      if (a < nargs)
	{
	  p_args[b++] = strdup (argv[a]);
	}
      else
	{
	  p_args[b++] = 0;
	}
    }

#ifdef DEBUG
  A4GL_debug ("Copied Arguments\n");
#endif

  A4GL_start_gui ();

#ifdef _PRELOAD_REPORT_
  A4GLREPORT_initlib ();
#endif
  
#if (! defined(WIN32) && ! defined(__MINGW32__))
  //Mike, are you sure this is not going to work on MinGW, or where you just guessing,
  //since it's on Windows?
  A4GL_set_core_dump ();
  initsig_child();
#endif
  /* signal (SIGINT, fgl_end); */
  A4GL_nodef_init ();
#ifdef DEBUG
  A4GL_debug ("Init");
#endif


#ifdef _PRELOAD_UI_
  /* Initialize the UI library (ie load the dll) */
  if (!A4GLUI_initlib ())
    {
      printf ("4gllib: Error opening UI library (A4GL_UI=%s)\n",
	      acl_getenv ("A4GL_UI"));
      exit (1);
    }
  /* Do any startup required by the library */
  A4GLUI_ui_init (nargs, argv);
#endif

  /*
     FIXME: programs should make connection call only when they
     encounter DATABSE, CONNECT, etc
   */

#ifdef DEBUG
  A4GL_debug ("Allocating rack loads of space.... saves time later");
#endif

  ptr = malloc (1024 * 1024 * 10);
  free (ptr);

/*endwin(); *//* switch straight back to terminal mode */
#if (defined(WIN32) && ! defined(__CYGWIN__) && ! defined (__MINGW32__))
  rpc_nt_init ();
#endif

#ifdef DEBUG
  A4GL_debug ("fgl_start done");
#endif
}

/**
 * Execute a system calling another program.
 *
 * The system command is popped from the stack.
 *
 * @param a The mode :
 *   - 1 Receive and push the exit value of command executed to stack.
 *   - 2 In background mode.
 *
 */
void
A4GL_system_run (int a)
{
  char *s;
  int ret;

  A4GL_gotolinemode ();
  s = A4GL_char_pop ();
  if (a == 2)
    strcat (s, " &");
  ret = system (s);
  if (A4GL_env_option_set ("FIXSYSTEM"))
    ret = ret >> 8;
#ifdef DEBUG
  A4GL_debug (">>returns %x", ret);
#endif
  if (a == 1)
    {
      A4GL_push_int (ret);
    }
  acl_free (s);
  A4GL_zrefresh ();
}

/**
 * Checks if the string have some sort of yes (y,Y,1,true).
 *
 * @param s The string to be checked
 * @return - 1 : Is yes
 *         - 0 : Otherwise
 */
int
A4GL_isyes (char *s)
{
  if (s == 0)
    {
      //debug("isyes = false");
      return 0;
    }
  //debug("isyes called with %s\n",s);
  if (s[0] == 0)
    {
      //debug("isyes = false");
      return 0;
    }
  if (s[0] == 'y' || s[0] == 'Y' || s[0] == '1'
      || A4GL_aubit_strcasecmp (s, "true") == 0)
    {
      //debug("isyes = true");
      return 1;
    }
  //debug("isyes = false");
  return 0;
}

/**
 * Create an error in a string.
 *
 * @para str A pointer to the place where the error string will be generated.
 * @param fileName A string with the source name.
 * @param lineno The line in the source where the error ocurred.
 */
void
A4GL_generateError (char *str, char *fileName, int lineno)
{
  if (A4GL_isgui ())
    {
      sprintf (str, "Error in '%s'@%d\rErr=%d.\r%s.",
	       fileName,
	       lineno,
	       (int) a4gl_status,
	       A4GL_err_print (a4gl_status, a4gl_sqlca.sqlerrm));
    }
  else
    {
      sprintf (str,
	       "Program stopped at '%s', line number %d.\nError status number %d.\n%s.\n",
	       fileName,
	       lineno,
	       (int) a4gl_status,
	       A4GL_err_print (a4gl_status, a4gl_sqlca.sqlerrm));
    }
  if (A4GLSTK_isStackInfo ())
    sprintf (str, "%s\n%s", str, A4GLSTK_getStackTrace ());
}

/**
 * Check if have ocurred some error.
 * This check is made with the value of global variable status.
 *
 * @param lineno The source line number where the error ocurred.
 * @param fname The source 4gl file number where the error ocurred.
 */
void
A4GL_chk_err (int lineno, char *fname)
{
  char s[2048];
#ifdef DEBUG
  {
    A4GL_debug ("Checking exit status");
  }
#endif

  if (a4gl_status >= 0)
    return;

  if (A4GL_isscrmode ())
    A4GL_gotolinemode ();

#ifdef DEBUG
  A4GL_debug ("Error...");
#endif
  A4GL_generateError (s, fname, lineno);
  if (A4GL_isgui ())
    {
#ifdef DEBUG
      A4GL_debug ("About to send to front end");
#endif
      sleep (1);
      A4GL_gui_error (s, 1);
      A4GL_gui_error ("Quitting...", 1);
    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("Write error to screen...");
#endif
      if (strcmp (fname, "Unknown") != 0 && A4GL_has_errorlog ())
	{
	  A4GL_push_char (s);
	  A4GL_errorlog (fname, lineno, 1);
	}
      A4GL_debug (s);
      printf ("Err:%s", s);
    }
  exit (1);
}

/**
 * Assigns the sqlca.sqlerrm error message.
 *
 * @param s The error message
 */
void
A4GL_set_errm (char *s)
{
  strcpy (a4gl_sqlca.sqlerrm, s);
}


/**
 * Push the 4gl number of executing arguments to the stack
 *
 * @param n Not used
 * @return allways 1
 */
int
aclfgl_num_args (int n)
{
  A4GL_push_int (p_numargs - 1);
  return 1;
}

/**
 *
 * @param n
 * @return allways 1
 */
int
aclfgl_arg_val (int n)
{
  int k;

  k = A4GL_pop_int ();
  if (k < p_numargs)
    A4GL_push_char (p_args[k]);
  else
    A4GL_push_char ("N/A");
  return 1;
}

/**
 * Dont do nothing
 */
void
A4GL_null_func (void)
{
}

/**
 * Clear the memory of an associative array.
 *
 * @param a The pointer to the pointer that points to the memory allocated.
 * @param sz The size to be allocated for the associative array.
 */
static void
ass_clrmem (char **a, int sz)
{
  memset (a, 0, sz);
}

/**
 * Associative array (hash) implementation.
 *
 * Executed in run-time by the generated C code.
 *
 * @param a key
 * @param s - size of string (+1 for null already added)
 * @param d - size of key array
 * @param str key
 * @param size The number of elements of the associative array.
 * @param rw
 *   - 0 : Reading from hash
 *   - Otherwise :
 */
int
A4GL_ass_hash (char **a, int s, int d, char *str, long size, int rw)
{
  char buff[256];
  int p;
  int t;
  int start;

  s--;


#ifdef DEBUG
  {
    A4GL_debug ("In A4GL_ass_hash a= %p", a);
  }
#endif

  t = 0;
#ifdef DEBUG
  A4GL_debug ("Look for '%s'\n", str);
#endif

  if (strlen (str) == 0)
    {
#ifdef DEBUG
      {
 A4GL_debug ("Empty string\n");
      }
#endif
      return 0;
    }

#ifdef DEBUG
  {
    A4GL_debug ("Chk for need clean");
  }
#endif

  if (a[0] == (char *) -1)
    {
#ifdef DEBUG
      {
 A4GL_debug ("clean it");
      }
#endif

      ass_clrmem (a, size);
      for (t = 0; t < d; t++)
	{
	  a[t] = 0;
	}
      t = 0;

    }

#ifdef DEBUG
  {
    A4GL_debug ("clear buff");
  }
#endif

  memset (buff, 0, 255);

#ifdef DEBUG
  {
    A4GL_debug ("set buff");
  }
#endif

  strcpy (buff, str);
#ifdef DEBUG
  {
    A4GL_debug ("copied - marking end at %d", s);
  }
#endif

  buff[s] = 0;
  A4GL_trim (buff);

#ifdef DEBUG
  {
    A4GL_debug ("copied : %s", buff);
  }
#endif

  for (p = 0; p < s; p++)
    {
      t = t + buff[p] * (p + 1);
    }

#ifdef DEBUG
  {
    A4GL_debug ("hash code = %d", t);
  }
#endif
  t = t % d;
  if (t == 0)
    t++;
  start = t;

#ifdef DEBUG
  A4GL_debug ("Test");
  {
    A4GL_debug ("B hash code = %d", t);
  }
  {
    A4GL_debug ("addr1= %p", a);
  }
  {
    A4GL_debug ("addr2= %p", a[t]);
  }
#endif

  while ((a[t] != 0))
    {
#ifdef DEBUG
      {
 A4GL_debug (" checking = %d a[t]=%p", t, a[t]);
      }
#endif
      if (strcmp ((char *) a[t], buff) == 0)
	{
#ifdef DEBUG
	  {
	    A4GL_debug ("Found it -> t=%d\n", t);
	  }
#endif
	  return t;
	}

      t++;
      t = t % d;

#ifdef DEBUG
      {
 A4GL_debug (" C hash code = %d a[t]=%s", t, a[t]);
      }
#endif

      if (t == 0)
	t++;

      if (t == start)
	{
#ifdef DEBUG
	  A4GL_debug ("Out of hash spaces\n");
#endif
	  exit (0);
	}
    }

#ifdef DEBUG
  A4GL_debug ("t=%d\n", t);
#endif
  if (rw == 0)
    {
      a[t] = realloc (a[t], strlen (buff) + 1);
      strcpy ((char *) a[t], buff);
#ifdef DEBUG
      {
 A4GL_debug (" returning %d", t);
      }
#endif
      return t;
    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("Not found on a read from hash table");
#endif
      return 0;
    }
}


/**
 *
 * @todo Describe function
 */
void
A4GL_set_intr (void)
{
#ifdef DEBUG
  A4GL_debug ("-------------INTERRUPT----------------");
#endif
  int_flag = TRUE;
  errno = -1;

  /* CHECKME
     ungetch(A4GLKEY_CANCEL);
   */

  A4GL_set_abort (1);
  /* Reset signal */
  A4GL_def_int ();
}

#if (defined(WIN32) && ! defined(__CYGWIN__))
/**
 * Initilaizes the signals in windows systems.
 *
 * @param type
 * @return
 */
BOOL __stdcall
set_intr_win32 (DWORD type)
{
  if (type == CTRL_C_EVENT || type == CTRL_BREAK_EVENT)
    {
#ifdef DEBUG
      A4GL_debug ("-------------INTERRUPT----------------");
#endif
      int_flag = TRUE;
      errno = -1;
      ungetch (A4GLKEY_CANCEL);
      A4GL_set_abort (1);
    }
  return TRUE;
}
#endif

// ######################################################################
#if (defined(WIN32) && ! defined(__CYGWIN__))
// ######################################################################
//This conditional will happen ONLy when compiling with native Windows compilers, like MinGW


// implicit declaration of function `rpc_nt_init'
// implicit declaration of function `sleep' -- should be in <unistd.h>
// implicit declaration of function `ungetch' -- <curses.h>

#if ! defined (__MINGW32__)
typedef unsigned long sigset_t;
#endif

/**
 * Struct for signal handling in windows systems
 */
struct sigaction
{
  void (*sa_handler) (int);
  sigset_t sa_mask;
  int sa_flags;
};

/**
 * Stop the defer interrupt in windows systems
 */
void
A4GL_nodef_init (void)
{
#ifdef DEBUG
  A4GL_debug ("No defer interrupt");
#endif
  SetConsoleCtrlHandler (set_intr_win32, 0);
}


/**
 * Start the DEFER INTERRUPT in windows systems
 */
void
A4GL_def_int (void)
{
#ifdef DEBUG
  A4GL_debug ("Setting interrupt mode");
#endif
  SetConsoleCtrlHandler (set_intr_win32, 1);
}


// ######################################################################
#else //#if (defined(WIN32) && ! defined(__CYGWIN__))
// ######################################################################
//This conditional will happen ONLY when NOT compiling on Windows, or when compiling on Windows
// with CygWin compiler

/**
 * Stop the DEFER INTERRUPT in unix systems.
 */
void
A4GL_nodef_init ()
{
  struct sigaction sa;
  int ret;

#ifdef OTHER_UNIX
  sa.sa_sigaction = (void *) A4GL_fgl_end;
#else
  sa.sa_handler = (void *) A4GL_fgl_end;
#endif
  sigemptyset (&sa.sa_mask);
  sa.sa_flags = 0;
  ret = sigaction (SIGINT, &sa, 0);
  if (ret)
    {
      A4GL_exitwith ("Could not defer interrupt");
    }
}


void A4GL_core_dump(void) {
  if (A4GL_isscrmode ())
    {
#ifdef DEBUG
      A4GL_debug ("In screen mode - ending curses...");
#endif
      A4GL_gotolinemode ();
    }
   printf("Internal Error - segmentation fault\n");
   printf("Please note all circumstances and log with the Aubit4GL team\n");
   printf("If possible - reproduce the error with the environment variable DEBUG\n");
   printf("set to ALL :\n\n");
   printf("$ export DEBUG=ALL\n\n");
   printf("And enclose the last 100 lines from the resultant debug.out file\n");
   printf("with your bug log.\n");
   printf("\n");
   printf("%s\n",A4GLSTK_getStackTrace ());
   if (A4GL_isscrmode ())
    {
#ifdef DEBUG
      A4GL_debug ("In screen mode - ending curses...");
#endif
      A4GL_gotolinemode ();
    }
  A4GL_close_database ();
  A4GL_close_errorlog_file ();
  exit(99);

}

void
A4GL_set_core_dump (void)
{
  struct sigaction sa;
  int ret;

// A4GL_DUMP_CORE = YES 
//          Dumps core rather than attach a signal handler to the segmentation
//          fault...
if (A4GL_isyes(acl_getenv("DUMP_CORE"))) {
	return;
}

#ifdef OTHER_UNIX
  sa.sa_sigaction = (void *) A4GL_core_dump;
#else
  sa.sa_handler = (void *) A4GL_core_dump;
#endif
  sigemptyset (&sa.sa_mask);
  sa.sa_flags = 0;
  ret = sigaction (SIGSEGV, &sa, 0);
  if (ret)
    {
      A4GL_exitwith ("Could not attach SegFault Handler");
    }
}



/**
 * Start the defer interrupt in unix systems.
 */
void
A4GL_def_int (void)
{
  struct sigaction sa;
  int ret;

#ifdef OTHER_UNIX
  sa.sa_sigaction = (void *) A4GL_set_intr;
#else
  sa.sa_handler = (void *) A4GL_set_intr;
#endif
  sigemptyset (&sa.sa_mask);
  sa.sa_flags = 0;
  ret = sigaction (SIGINT, &sa, 0);
  if (ret)
    {
      A4GL_exitwith ("Could not defer interrupt");
    }
}


// ######################################################################
#endif  //#if (defined(WIN32) && ! defined(__CYGWIN__))
// ######################################################################


/**
 * Trim the blank spaces in a string
 *
 * @param s The string to be trimmed
 * @return A new static string to be trimmed
 */
static char *
ftrim (char *s)
{
  static char f[256];
  int a;
  strcpy (f, s);
  for (a = strlen (s) - 1; a >= 0; a--)
    {
      if (f[a] == ' ')
	f[a] = 0;
      else
	break;
    }
  return f;
}

/**
 * @param s
 * @param p
 * @return 
 */
char *
A4GL_clob (char *s, char *p)
{
  static char clobber[256];
  sprintf (clobber, "%s:%s", s, ftrim (p));
  return clobber;
}

/**
 * Generate the serial number of the aubit 4gl compiler.
 * 
 * @return A string pointer with the serial number.
 */
/*
char *
get_serno(void)
{
	return "XXXXXXXXXX";
}
*/

/**
 * Check and show the aubit compiler ID
 *
 * @param program A string identifiing the program name
 * @param arg1 The first argument of the program argv[1]
 */
void
A4GL_check_and_show_id (char *program, char *arg1)
{
  char mod[32];
  char id[132];
  int a;

  if (strcmp (arg1, "-v") == 0)
    {
      printf ("(c) 1997-2002 Aubit project\n%s\n\n", program);
      /*
         printf("Serial Number %s\n\nVersion       %s\nBuild Level   %d\n",
         get_serno(),internal_version(),internal_build()
         );
       */
      printf ("Version       %s\nBuild Level   %d\n",
	      A4GL_internal_version (), A4GL_internal_build ());

      exit (0);
    }

  if (strcmp (arg1, "-vfull") == 0)
    {
      printf ("(c) 1997-2002 Aubit project\n%s\n\n", program);
      printf ("Version       %s\nBuild Level   %d\n",
	      A4GL_internal_version (), A4GL_internal_build ());
      for (a = 0;; a++)
	{
	  A4GL_set_version (a, mod, id);
	  if (strlen (mod) == 0)
	    break;
	  printf ("%s:\n  %s\n", mod, id);
	}
      exit (0);
    }
}

/**
 * Yes it is... used (?)
 */
int
aclfgl_a4gl_get_ui_mode (int n)
{
  A4GL_push_int (ui_mode);
  return 1;
}


/*
The DEFER statement prevents 4GL from terminating program execution when
the user presses the Interrupt key or the Quit key.

DEFER is a method of intercepting asynchronous signals from outside the program.

Unless it includes the DEFER statement, the 4GL application terminates
whenever the user presses the Interrupt key or the Quit key. The Interrupt 
key is CONTROL-C, and the Quit key is CONTROL-\. (Here the Quit key 
emulates the effect of the Quit key on UNIX systems.)

The DEFER statement tells 4GL to set a built-in global variable to a 
non-zero value, rather than terminate, when the user presses one of these keys:

If the user presses the Interrupt key when DEFER INTERRUPT has been 
specified, 4GL sets the built-in global variable int_flag to TRUE.

If the user presses the Quit key when DEFER QUIT has been specified, 
4GL sets the built-in global variable quit_flag to TRUE.

The DEFER INTERRUPT and DEFER QUIT statements can appear only in the 
MAIN program block, and only once there in any program. Once executed, 
the DEFER statement remains in effect for the duration of the program; 
you cannot restore the original function of the Interrupt key or the Quit key.

4GL programs can include code to check whether int_flag or quit_flag
is TRUE, and if so, to take appropriate action. Be sure also to reset
int_flag or quit_flag to FALSE (that is, to zero) so that subsequent 
tests are valid.

*/



/**
 * Dummy function for DEFER QUIT
 */
void
A4GL_def_quit (void)
{
#ifdef DEBUG
  A4GL_debug ("FIXME: DEFER QUIT NOT IMPLEMENTED - Setting quit mode");
#endif
}


/**
 *
 * @todo Describe function
 */
void
A4GL_set_abort (int a)
{
#ifdef DEBUG
  A4GL_debug ("set_abort called with %d", a);
#endif
  abort_pressed = a;
}


/*Param (char *str)    : String to A4GL_strip                         */
/*Description          : Strips trailing \n from a string        */
/**
 *
 * @todo Describe function
 */
void
A4GL_stripnl (char *str)
{
  int a;
  for (a = 0; a < strlen (str); a++)
    {
      if (str[a] == '\n' || str[a] == '\r')
	{
	  str[a] = 0;
	  break;
	}
    }
}

/* same thing?

void
stripnl(char *buff)
{
        int a;
        for (a=strlen(buff)-1;a--;a>=0)
        {
                if (buff[a]=='\n') {
                        buff[a]=0;
                        break;
                }
        }
}

*/




/**
 *
 * @todo Describe function
 */
int
A4GL_fgl_error (int a, char *s, int err, int stat)
{
  A4GL_gotolinemode ();
#ifdef DEBUG
  A4GL_debug ("\n\n\nError at line %d in file %s\n", a, s);
  A4GL_debug ("Error number %d - Error level %d\n\n", err, stat);
#endif
  printf ("\n\n\nError at line %d in file %s\n", a, s);
  printf ("Error number %d - Error level %d\n\n", err, stat);
  exit (0);
  return 0;
}




static int initsig_child()
{
struct sigaction ServerSig; 
A4GL_debug("Adding SIGCLD handler to stop defunct processes with informix..");
ServerSig.sa_handler = SIG_IGN;
ServerSig.sa_flags = SA_NOCLDWAIT; 

if (sigaction(SIGCLD, &ServerSig, NULL))
{
	A4GL_exitwith("Unable to attach SIGCLD handler");
	return 0;
} 

return 1;
}


/* ================================= EOF ============================= */
