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
# $Id: fglwrap.c,v 1.4 2002-05-07 22:52:24 saferreira Exp $
#
*/

/**
 * @file
 * Wrapper functions to call fgl from c, system from fgl and environment
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

#define DEFINE_INTFLAG
#define DEFINE_QUITFLAG
#include <signal.h>
#include <locale.h>
//#include <unistd.h>
#include <string.h>
#ifdef __CYGWIN__
#include <windows.h>
#include <errno.h>
#endif
/*#include "../../incl/sqlca.h"*/

//authunix_parms redefined: start here:
#include "a4gl_dbform.h"
#include "a4gl_stack.h"
#include "a4gl_debug.h"
#include "a4gl_keys.h"

//FIXME: is this OK? see lib/libincl/dbform.h
#ifdef __CYGWIN__
extern int int_flag;
extern int status;
#else
extern long status;
#endif

extern sqlca_struct sqlca;
int p_numargs=0;
int isdebug=0;
char *p_args[256];

extern int start_gui();
void nodef_init();
int ui_mode=0;
int int_flag;

int quit_flag;
int abort_pressed;

extern int errno;

/**
 * Function called when a 4gl program terminates is execution.
 *
 * If in curses mode exit curses.
 */
void fgl_end(void) 
{
  if (isscrmode ()) {
	  debug("In screen mode - ending curses...");
	  gotolinemode();
  }
  exit (0);
}

/**
 * function called on initialization of every Aubit compiled 4gl program:
 * 
 * Command line arguments to compiled 4gl program can be:
 * 
 * GUIPORT    	- FIXME: what is it?
 * NOCURSES     - FIXME: this is now AUBITGUI=CONSOLE
 *
 * @param nargs The number of arguments.
 * @param argv The arguments values.
 */
void fgl_start(int nargs,char *argv[]) 
{
  int a;
  int b=0;
  void *ptr;
  void *ptr_win;
  int mcode;
  char *p;

	include_builtin_in_exe(); // This does nothing - but we NEED IT!
			// If builtin is not in the executable then we get link errors

	//load settings from config file(s):
	build_user_resources();

	if (!A4GLSQL_initlib())
	{
		printf("4gllib: Error opening SQL Library - check A4GL_SQLTYPE is set correctly (A4GL_SQLTYPE=%s)\n", 
		  acl_getenv("A4GL_SQLTYPE")
		);
		exit(1);
	}

	if (acl_getenv("AUBITGUI")) {
		p=acl_getenv("AUBITGUI");

		if (strcasecmp(p,"TEXT")==0  ) 	ui_mode=0;
		if (strcasecmp(p,"CURSES")==0) 	ui_mode=0;
		if (strcasecmp(p,"GTK")==0) 	  ui_mode=1;
		if (strcasecmp(p,"GUI")==0) 	  ui_mode=1;
	}

	p_numargs = nargs;
	setlocale(LC_ALL,"");
	setlocale(LC_CTYPE,"");
	#ifdef DEBUG
	/*{DEBUG}*/ {debug("Starting program - %d arguments argv=%p",nargs,argv);}
	#endif

	b=0;
	for (a=0;a<256;a++) 
	{
		//debug("a=%d\n",a);
		if (a<nargs)
		if (argv[a]) 
		{

		  //FIXME: we already printed something to stdout at this point...
		  //printf("Check..");
  
	    if (strncmp(argv[a],"GUIPORT",7)==0) {
	       debug("GUIMODE");
	       putenv(argv[a]);
	       continue;
	    }
  
	    if (strncmp(argv[a],"NOCURSES",8)==0) {     //FIXME: this is now AUBITGUI=CONSOLE
	       debug("NOCURSES");
	       putenv(argv[a]);
	       continue;
	    }

	  }
    //debug("Copy");

    if (a<nargs) p_args[b++]=strdup(argv[a]);
    else p_args[b++]=0;
	}
	debug("Copied Arguments\n");

	start_gui();
	A4GLREPORT_initlib();

	//signal (SIGINT, fgl_end);
	nodef_init();
	debug("Init");


// Initialize the UI library (ie load the dll)
	if (!A4GLUI_initlib()) {
		printf("4gllib: Error opening UI library (AUBITGUI=%s)\n",acl_getenv("AUBITGUI"));
		exit(1);
	}

// Do any startup required by the library
	A4GLUI_ui_init(nargs,argv);

/*
    FIXME: programs should do make connection call only when they
    encounter DATABSE, CONNECT, etc - since we now have no-ODBC build
*/

	debug("Connecting...");
	A4GLSQL_initsqllib();

#ifdef MOVED_TO_INIT_TUI_FUNCTION
	if (ui_mode==0) {
	#ifdef NCURSES_MOUSE_VERSION
	  debug("Turning Mouse on");
	#ifdef WIN32
	#ifndef __CYGWIN__
	  debug("Turning WIN32 mouse on\n");
	  if (env_option_set("ACL_MOUSE") mouse_on(ALL_MOUSE_EVENTS);
	#endif
	#else
	  if (env_option_set("ACL_MOUSE") ) {
	           debug("Turning UNIX mouse on\n");
	           mcode=mousemask(ALL_MOUSE_EVENTS,0);
	           debug("Turned on %d (%d)",mcode,ALL_MOUSE_EVENTS);
	  }
	#endif
	#endif
	}
#endif
	
	debug("Allocating rack loads of space.... saves time later");

	ptr=malloc(1024*1024*10);
	free(ptr);


	/*endwin();*/ /* switch straight back to terminal mode */
	#ifdef WIN32
	#ifndef __CYGWIN__
	  rpc_nt_init();
	#endif
	#endif

	debug("All done");
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
void system_run(int a)
{
  char *s;
  int ret;

	gotolinemode();
	s=char_pop();
	if (a==2) strcat(s," &");
	ret=system(s);
	if (env_option_set("FIXSYSTEM") ) ret=ret>>8;
	debug(">>returns %x",ret);
	if (a==1) {push_int(ret);}
	acl_free(s);
	zrefresh();
}

/**
 * Checks if the string have some sort of yes (y,Y,1,true).
 *
 * @param s The string to be checked
 * @return - 1 : Is yes
 *         - 0 : Otherwise
 */
int isyes(char *s) 
{
	if (s==0) return 0;
	if (s[0]==0) return 0;
	if (s[0]=='y'||s[0]=='Y'||s[0]=='1'||aubit_strcasecmp(s,"true")==0) return 1;
	return 0;
}
/**
 * Create an error in a string.
 *
 * @para str A pointer to the place where the error string will be generated.
 * @param fileName A string with the source name.
 * @param lineno The line in the source where the error ocurred.
 */
void generateError(char *str,char *fileName,int lineno)
{
  if (isgui()) 
  {
    sprintf(str,"Error in '%s'@%d\rErr=%d.\r%s.",
      fileName,
      lineno,
      status,
      err_print(status,sqlca.sqlerrm)
    );
  }
  else
  {
    sprintf(str,
     "Program stopped at '%s', line number %d.\nError status number %d.\n%s.\n",
      fileName,
      lineno,
      status,
      err_print(status,sqlca.sqlerrm)
    );
  }
  if ( A4GLSTK_isStackInfo() )
    sprintf(str,"%s\n%s",str,A4GLSTK_getStackTrace());
}

/**
 * Check if have ocurred some error.
 * This check is made with the value of global variable status.
 *
 * @param lineno The source line number where the error ocurred.
 * @param fname The source 4gl file number where the error ocurred.
 */
void chk_err(int lineno,char *fname) 
{
  char s[2048];
  #ifdef DEBUG
  /* {DEBUG} */ {debug("Checking exit status");}
  #endif

  if (status >= 0) 
    return;

  if (isscrmode()) 
    gotolinemode();

  debug("Error...");
  generateError(s,fname,lineno);
  if (isgui()) 
  {
    debug("About to send to front end");
    sleep(1);
    gui_error(s,1);
    gui_error("Quitting...",1);
  }
  else 
  {
    debug("Write error to screen...");
    printf("%s",s);
  }
  exit(1);
}

/**
 * Assigns the sqlca.sqlerrm error message.
 *
 * @param s The error message
 */
void set_errm(char *s)
{
	strcpy(sqlca.sqlerrm,s);
}


/**
 * Push the 4gl number of executing arguments to the stack
 *
 * @param n Not used
 * @return allways 1
 */
int aclfgl_num_args(int n)
{
	push_int(p_numargs-1);
	return 1;
}

/**
 *
 * @param n
 * @return allways 1
 */
int aclfgl_arg_val(int n)
{
  int k;

	k=pop_int();
	if (k<p_numargs) push_char(p_args[k]);
	else push_char("N/A");
	return 1;
}

/**
 * Dont do nothing
 */
void null_func(void)
{
}

/**
 * Clear the memory of an associative array.
 *
 * @param a The pointer to the pointer that points to the memory allocated.
 * @param sz The size to be allocated for the associative array.
 */
static void ass_clrmem (char **a, int sz)
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
int ass_hash (char **a, int s, int d, char *str, long size,int rw)
{

  char buff[256];
  int p;
  int t;
  int start;

  s--;


	#ifdef DEBUG
		/* {DEBUG} */ {  debug("In ass_hash a= %p",a); }
	#endif
	
	t = 0;
	debug ("Look for '%s'\n", str);

	if (strlen (str) == 0) {
		#ifdef DEBUG
		/* {DEBUG} */ {    debug("Empty string\n");	}
		#endif
		return 0;
    }

	#ifdef DEBUG
		/* {DEBUG} */ {debug("Chk for need clean");	}
	#endif

	if (a[0] == (char *) -1) 
	{
		#ifdef DEBUG
		/* {DEBUG} */ {      debug("clean it");}
		#endif
		
	  ass_clrmem (a, size);
	  for (t=0;t<d;t++) {
			a[t]=0;
	  }
	  t=0;

	}

	#ifdef DEBUG
		/* {DEBUG} */ {  debug("clear buff"); }
	#endif
	  
	memset (buff, 0, 255);
	
	#ifdef DEBUG
		/* {DEBUG} */ {  debug("set buff");	}
	#endif
	  
	strcpy (buff, str);
	#ifdef DEBUG
		/* {DEBUG} */ {  debug("copied - marking end at %d",s);	}
	#endif
	  
	buff[s] = 0;
	trim(buff);
	
	#ifdef DEBUG
		/* {DEBUG} */ {  debug("copied : %s",buff);	}
	#endif

	  for (p = 0; p < s; p++)
	    {
	      t = t + buff[p]*(p+1);
	    }

	#ifdef DEBUG
		/* {DEBUG} */ {  debug("hash code = %d",t); }
	#endif
	  t = t % d;
	  if (t == 0) t++;
	  start = t;

	debug("Test");
		/* {DEBUG} */ {  debug("B hash code = %d",t); 	}
		/* {DEBUG} */ {  debug("addr1= %p",a); 	}
		/* {DEBUG} */ {  debug("addr2= %p",a[t]); 	}
	
	  while ((a[t] != 0))
	    {
			#ifdef DEBUG
				/* {DEBUG} */ {      debug(" checking = %d a[t]=%p",t,a[t]);	}
			#endif
	      	if (strcmp ((char *)a[t], buff) == 0) {
				#ifdef DEBUG
					/* {DEBUG} */ {	  debug("Found it -> t=%d\n", t); }
				#endif
				return t;
			}

			t++;
			t = t % d;

			#ifdef DEBUG
				/* {DEBUG} */ {      debug(" C hash code = %d a[t]=%s",t,a[t]);	}
			#endif

			if (t == 0) t++;

	      	if (t == start)	{ 
				debug ("Out of hash spaces\n");  
				exit (0);
			}
		}

	debug ("t=%d\n", t);
	if (rw==0) {
		a[t]=realloc(a[t],strlen(buff)+1);
		strcpy ((char *)a[t], buff);
		#ifdef DEBUG
			/* {DEBUG} */ {  debug(" returning %d",t);}
		#endif
		return t;
	} else  {
	  	debug ("Not found on a read from hash table");
	  	return 0;
	}
}


void set_intr(void)
{
  	void def_int(void);

	debug("-------------INTERRUPT----------------");
	int_flag=TRUE;
	errno=-1;

// CHECKME
	//ungetch(A4GLKEY_CANCEL);

	set_abort(1);
	/* Reset signal */
	def_int();
}

#if (defined(WIN32) && ! defined(__CYGWIN__))
/**
 * Initilaizes the signals in windows systems.
 *
 * @param type
 * @return
 */
BOOL __stdcall set_intr_win32(DWORD type)
{
	if (type==CTRL_C_EVENT||type==CTRL_BREAK_EVENT) {
		debug("-------------INTERRUPT----------------");
		int_flag=TRUE;
		errno=-1;
		ungetch(KEY_CANCEL);
		set_abort(1);
		}
	return TRUE;
}
#endif


#if (defined(WIN32) && ! defined(__CYGWIN__))
typedef unsigned long sigset_t;

/**
 * Struct for signal handling in windows systems
 */
struct sigaction 
{
	void (*sa_handler)(int);
	sigset_t sa_mask;
	int sa_flags;
};

/**
 * Stop the defer interrupt in windows systems
 */
void nodef_init(void) 
{
	debug("No defer interrupt");
	SetConsoleCtrlHandler(set_intr_win32, 0); 
} 
 

/**
 * Start the DEFER INTERRUPT in windows systems
 */
void def_int(void) 
{
	debug("Setting interrupt mode");
	SetConsoleCtrlHandler(set_intr_win32, 1);
}

#else


/**
 * Stop the DEFER INTERRUPT in unix systems.
 */
void nodef_init() 
{
  struct sigaction sa;
  int ret;

	#ifdef OTHER_UNIX
	sa.sa_sigaction=(void *)fgl_end;
	#else
	sa.sa_handler = (void *)fgl_end;
	#endif
	sigemptyset(&sa.sa_mask);
	sa.sa_flags=0;
	ret=sigaction(SIGINT,&sa,0);
	if (ret) {
		exitwith("Could not defer interrupt");
	}
}


/**
 * Start the defer interrupt in unix systems.
 */
void def_int(void) 
{
  struct sigaction sa;
  int ret;

	#ifdef OTHER_UNIX
	sa.sa_sigaction = (void *)set_intr;
	#else
	sa.sa_handler = (void *)set_intr;
	#endif
	sigemptyset(&sa.sa_mask);
	sa.sa_flags=0;
	ret=sigaction(SIGINT,&sa,0);
	if (ret) {
		exitwith("Could not defer interrupt");
	}
}
#endif


/**
 * Trim the blank spaces in a string
 *
 * @param s The string to be trimmed
 * @return A new static string to be trimmed
 */
static char *ftrim(char *s) 
{
  static char f[256];
  int a;
	strcpy(f,s);
	for (a=strlen(s)-1;a>=0;a--) 
	{
		if (f[a]==' ') f[a]=0;
		else break;
	}
	return f;
}

/**
 * @param s
 * @param p
 * @return 
 */
char *clob(char *s,char *p) 
{
  static char clobber[256];
	sprintf(clobber,"%s:%s",s,ftrim(p));
	return clobber;
}

/**
 * Generate the serial number of the aubit 4gl compiler.
 * 
 * @return A string pointer with the serial number.
 */
char *get_serno(void) 
{
	return "XXXXXXXXXX";
}

/**
 * Check and show the aubit compiler ID
 *
 * @param program A string identifiing the program name
 * @param arg1 The first argument of the program argv[1]
 */
void check_and_show_id(char *program, char *arg1) 
{
  char mod[32];
  char id[132];
  int a;

	if (strcmp(arg1,"-v")==0) 
	{
	    printf("(c) 1997-2002 Aubit Computing Ltd\n%s\n\n",program);
	    printf("Serial Number %s\n\nVersion       %s\nBuild Level   %d\n",
			  get_serno(),internal_version(),internal_build()
			);
	    exit(0);
	}

	if (strcmp(arg1,"-vfull")==0) 
	{
    printf("(c) 1997-2002 Aubit Computing Ltd\n%s\n\n",program);
	  printf("Serial Number %s\n\nVersion       %s\nBuild Level   %d\n",
			get_serno(),internal_version(),internal_build()
		);
	  for (a=0;;a++) 
		{
	    set_version(a,mod,id);
	    if (strlen(mod)==0) break;
		  printf("%s:\n  %s\n",mod,id);
	  }
	  exit(0);
	}
}

#ifdef THESE_ARE_IN_4GLC
exitwith("Wrong number of parameters");
#endif


/**
 * Yes it is... used (?)
 */
int aclfgl_get_ui_mode(void) 
{
	push_int(ui_mode);
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
void def_quit(void) 
{
	debug("FIXME: DEFER QUIT NOT IMPLEMENTED - Setting quit mode");
}


set_abort (int a)
{
  debug("set_abort called with %d",a);
  abort_pressed = a;
}


/*****************************************************************/
/*Function             : stripnl                                 */
/*Param (char *str)    : String to strip                         */
/*Returns              :                                         */
/*Description          : Strips trailing \n from a string        */
/*                                                               */
/*Created              : Wed May 14 14:55:15 BST 1997            */
/*Author               : informix                                */
/*Modifications        : None.                                   */
/*****************************************************************/
stripnl (char *str)
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



int
fgl_error (int a, char *s, int err, int stat)
{
  gotolinemode ();
  debug ("\n\n\nError at line %d in file %s\n", a, s);
  debug ("Error number %d - Error level %d\n\n", err, stat);
  printf ("\n\n\nError at line %d in file %s\n", a, s);
  printf ("Error number %d - Error level %d\n\n", err, stat);
  exit (0);
  return 0;
}
