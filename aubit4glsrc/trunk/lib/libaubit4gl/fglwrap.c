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
# $Id: fglwrap.c,v 1.31 2003-03-29 16:33:26 mikeaubury Exp $
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

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

//#define DEFINE_INTFLAG
//#define DEFINE_QUITFLAG
#define _DEFINE_STATUSVARS_ /* one place we have to DEFINE them, for the
	                            rest of source files, they get only DECLARED
	                            as extern */

/* FIXME: we should not need to pre-load anything */
#define _PRELOAD_SQL_ 		/* pre-load SQL module */
#define _PRELOAD_REPORT_  	/* pre-load EXREPORT module */
#define _PRELOAD_UI_ 		/* pre-load UI module */

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

int 	p_numargs	=0;
int 	isdebug		=0;
int 	ui_mode		=0;

/* extern int errno; */
#include <errno.h>

char *	p_args[256];


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

extern int 		start_gui			(void);
void 			nodef_init			(void);
void 			fgl_end				(void);
void 			fgl_start			(int nargs,char *argv[]);
void 			system_run			(int a);
void 			generateError		(char *str,char *fileName,int lineno);
void 			null_func			(void);
int 			ass_hash 			(char **a, int s, int d, char *str, long size,int rw);
void 			set_intr			(void);
void 			def_int				(void);
void 			def_quit			(void);
char * 			clob				(char *s,char *p);



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
fgl_end(void)
{
  if (isscrmode ())
  {
	#ifdef DEBUG
	  debug("In screen mode - ending curses...");
    #endif
	  gotolinemode();
  }
  close_database();
  A4GL_close_errorlog_file();
  debug("End of program - exit(0).");
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
fgl_start(int nargs,char *argv[])
{
int a;
int b=0;
void *ptr;
char *p;

	/* 
	This does nothing - but we NEED IT!
	If builtin is not in the executable then we get link errors 
	todo: wind out why is this needed
	*/
	include_builtin_in_exe();
        
	/* Initialise external datatypes module */
	init_datatypes();
	
	/* load settings from config file(s): */
	build_user_resources();


	#ifdef _PRELOAD_SQL_
		if (!A4GLSQL_initlib())
		{
			printf("4gllib: Error opening SQL Library - check A4GL_SQLTYPE is set correctly (A4GL_SQLTYPE=%s)\n",
			  acl_getenv("A4GL_SQLTYPE")
			);
			exit(1);
		}

		#ifdef DEBUG
			debug("Connecting to database...");
        #endif
		A4GLSQL_initsqllib();
    #endif

	if (acl_getenv("A4GL_UI")) {
		p=acl_getenv("A4GL_UI");

		//where is CONSOLE?
		if (aubit_strcasecmp(p,"TEXT")==0  )	ui_mode=0;
		if (aubit_strcasecmp(p,"CURSES")==0) 	ui_mode=0;
		if (aubit_strcasecmp(p,"GTK")==0) 	ui_mode=1;
		if (aubit_strcasecmp(p,"GUI")==0) 	ui_mode=1;
	}

	p_numargs = nargs;
	setlocale(LC_ALL,"");
	setlocale(LC_CTYPE,"");
	#ifdef DEBUG
		{debug("Starting 4gl program - %d arguments argv=%p",nargs,argv);}
	#endif


	/* FIXME: we already printed something to stdout at this point... */
	/* printf("Check.."); */

	b=0;
	for (a=0;a<256;a++)
	{
		if (a<nargs)
        {
			if (argv[a])
			{
			    /* FIXME: wha is this used for? */
				if (strncmp(argv[a],"GUIPORT",7)==0) {
			       	#ifdef DEBUG
					   debug("GUIMODE");
                    #endif
			       putenv(argv[a]);
			       continue;
			    }

				/* FIXME: this is now A4GL_UI=CONSOLE */
				if (strncmp(argv[a],"NOCURSES",8)==0) {
			       	#ifdef DEBUG
					   debug("NOCURSES");
                    #endif
			       putenv(argv[a]);
			       continue;
			    }
			}
        }

	    if (a<nargs) 
		{
			p_args[b++]=strdup(argv[a]);
        }
    	else
		{
			p_args[b++]=0;
        }
	}

	#ifdef DEBUG
		debug("Copied Arguments\n");
    #endif

	start_gui();
	
   	#ifdef _PRELOAD_REPORT_
		A4GLREPORT_initlib();
    #endif

	/* signal (SIGINT, fgl_end); */
	nodef_init();
	#ifdef DEBUG
		debug("Init");
    #endif


	#ifdef _PRELOAD_UI_
		/* Initialize the UI library (ie load the dll) */
		if (!A4GLUI_initlib()) {
			printf("4gllib: Error opening UI library (A4GL_UI=%s)\n",acl_getenv("A4GL_UI"));
			exit(1);
		}
		/* Do any startup required by the library */
		A4GLUI_ui_init(nargs,argv);
    #endif

	/*
    FIXME: programs should make connection call only when they
    encounter DATABSE, CONNECT, etc
	*/

	#ifdef DEBUG
		debug("Allocating rack loads of space.... saves time later");
    #endif

	ptr=malloc(1024*1024*10);
	free(ptr);

	/*endwin();*/ /* switch straight back to terminal mode */
	#if (defined(WIN32) && ! defined(__CYGWIN__) && ! defined (__MINGW32__))
	  rpc_nt_init();
	#endif

	#ifdef DEBUG
		debug("fgl_start done");
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
system_run(int a)
{
  char *s;
  int ret;

	gotolinemode();
	s=char_pop();
	if (a==2) strcat(s," &");
	ret=system(s);
	if (env_option_set("FIXSYSTEM") ) ret=ret>>8;
	#ifdef DEBUG
		debug(">>returns %x",ret);
    #endif
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
int 
isyes(char *s)
{
	if (s==0) {
		//debug("isyes = false");
		return 0;
	}
	//debug("isyes called with %s\n",s);
	if (s[0]==0) {
		//debug("isyes = false");
		return 0;
	}
	if (s[0]=='y'||s[0]=='Y'||s[0]=='1'||aubit_strcasecmp(s,"true")==0) {
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
generateError(char *str,char *fileName,int lineno)
{
  if (isgui()) 
  {
    sprintf(str,"Error in '%s'@%d\rErr=%d.\r%s.",
      fileName,
      lineno,
      (int)a4gl_status,
      err_print(a4gl_status,a4gl_sqlca.sqlerrm)
    );
  }
  else
  {
    sprintf(str,
     "Program stopped at '%s', line number %d.\nError status number %d.\n%s.\n",
      fileName,
      lineno,
      (int)a4gl_status,
      err_print(a4gl_status,a4gl_sqlca.sqlerrm)
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
void
chk_err(int lineno,char *fname)
{
  char s[2048];
  #ifdef DEBUG
  	{debug("Checking exit status");}
  #endif

  if (a4gl_status >= 0) 
    return;

  if (isscrmode())
    gotolinemode();

  #ifdef DEBUG
	  debug("Error...");
  #endif
  generateError(s,fname,lineno);
  if (isgui()) 
  {
    #ifdef DEBUG
		debug("About to send to front end");
    #endif
    sleep(1);
    gui_error(s,1);
    gui_error("Quitting...",1);
  }
  else 
  {
    #ifdef DEBUG
		debug("Write error to screen...");
    #endif 
    push_char(s);
    A4GL_errorlog(fname,lineno,1);
    printf("Err:%s",s);
  }
  exit(1);
}

/**
 * Assigns the sqlca.sqlerrm error message.
 *
 * @param s The error message
 */
void 
set_errm(char *s)
{
	strcpy(a4gl_sqlca.sqlerrm,s);
}


/**
 * Push the 4gl number of executing arguments to the stack
 *
 * @param n Not used
 * @return allways 1
 */
int
aclfgl_num_args(int n)
{
	push_int(p_numargs-1);
	return 1;
}

/**
 *
 * @param n
 * @return allways 1
 */
int
aclfgl_arg_val(int n)
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
void
null_func(void)
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
ass_hash (char **a, int s, int d, char *str, long size,int rw)
{
char buff[256];
int p;
int t;
int start;

  s--;


	#ifdef DEBUG
		{debug("In ass_hash a= %p",a); }
	#endif

	t = 0;
	#ifdef DEBUG
		debug ("Look for '%s'\n", str);
    #endif

	if (strlen (str) == 0) {
		#ifdef DEBUG
			{debug("Empty string\n");}
		#endif
		return 0;
    }

	#ifdef DEBUG
		{debug("Chk for need clean");	}
	#endif

	if (a[0] == (char *) -1)
	{
		#ifdef DEBUG
			{debug("clean it");}
		#endif
		
	  ass_clrmem (a, size);
	  for (t=0;t<d;t++) {
			a[t]=0;
	  }
	  t=0;

	}

	#ifdef DEBUG
		{debug("clear buff"); }
	#endif

	memset (buff, 0, 255);

	#ifdef DEBUG
		{debug("set buff");	}
	#endif

	strcpy (buff, str);
	#ifdef DEBUG
		{debug("copied - marking end at %d",s);	}
	#endif

	buff[s] = 0;
	trim(buff);

	#ifdef DEBUG
		{debug("copied : %s",buff);	}
	#endif

	  for (p = 0; p < s; p++)
	    {
	      t = t + buff[p]*(p+1);
	    }

	#ifdef DEBUG
		{debug("hash code = %d",t); }
	#endif
	  t = t % d;
	  if (t == 0) t++;
	  start = t;

	#ifdef DEBUG
		debug("Test");
		{debug("B hash code = %d",t);}
		{debug("addr1= %p",a);}
		{debug("addr2= %p",a[t]);}
    #endif
	
	  while ((a[t] != 0))
	    {
			#ifdef DEBUG
				{debug(" checking = %d a[t]=%p",t,a[t]);	}
			#endif
	      	if (strcmp ((char *)a[t], buff) == 0) {
				#ifdef DEBUG
					{debug("Found it -> t=%d\n", t); }
				#endif
				return t;
			}

			t++;
			t = t % d;

			#ifdef DEBUG
				{debug(" C hash code = %d a[t]=%s",t,a[t]);	}
			#endif

			if (t == 0) t++;

	      	if (t == start)	{ 
				#ifdef DEBUG
					debug ("Out of hash spaces\n");
                #endif
				exit (0);
			}
		}

	#ifdef DEBUG
		debug ("t=%d\n", t);
    #endif
	if (rw==0) {
		a[t]=realloc(a[t],strlen(buff)+1);
		strcpy ((char *)a[t], buff);
		#ifdef DEBUG
			{debug(" returning %d",t);}
		#endif
		return t;
	} else  {
	  	#ifdef DEBUG
			debug ("Not found on a read from hash table");
        #endif
	  	return 0;
	}
}


/**
 *
 * @todo Describe function
 */
void
set_intr(void)
{
    #ifdef DEBUG
		debug("-------------INTERRUPT----------------");
    #endif
	int_flag=TRUE;
	errno=-1;

	/* CHECKME
	ungetch(A4GLKEY_CANCEL);
    */

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
		#ifdef DEBUG
			debug("-------------INTERRUPT----------------");
        #endif
		int_flag=TRUE;
		errno=-1;
		ungetch(A4GLKEY_CANCEL);
		set_abort(1);
		}
	return TRUE;
}
#endif


#if (defined(WIN32) && ! defined(__CYGWIN__))

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
	void (*sa_handler)(int);
	sigset_t sa_mask;
	int sa_flags;
};

/**
 * Stop the defer interrupt in windows systems
 */
void 
nodef_init(void)
{
	#ifdef DEBUG
		debug("No defer interrupt");
    #endif
	SetConsoleCtrlHandler(set_intr_win32, 0); 
} 
 

/**
 * Start the DEFER INTERRUPT in windows systems
 */
void
def_int(void)
{
	#ifdef DEBUG
		debug("Setting interrupt mode");
    #endif
	SetConsoleCtrlHandler(set_intr_win32, 1);
}

#else


/**
 * Stop the DEFER INTERRUPT in unix systems.
 */
void 
nodef_init()
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
void 
def_int(void)
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
static char *
ftrim(char *s)
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
char *
clob(char *s,char *p)
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
check_and_show_id(char *program, char *arg1)
{
char mod[32];
char id[132];
int a;

	if (strcmp(arg1,"-v")==0)
	{
	    printf("(c) 1997-2002 Aubit project\n%s\n\n",program);
	    /*
		printf("Serial Number %s\n\nVersion       %s\nBuild Level   %d\n",
			  get_serno(),internal_version(),internal_build()
			);
        */
		printf("Version       %s\nBuild Level   %d\n",
			  internal_version(),internal_build()
			);

	    exit(0);
	}

	if (strcmp(arg1,"-vfull")==0)
	{
		printf("(c) 1997-2002 Aubit project\n%s\n\n",program);
		printf("Version       %s\nBuild Level   %d\n",
			  internal_version(),internal_build()
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

/**
 * Yes it is... used (?)
 */
int
aclfgl_get_ui_mode(int n)
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
void
def_quit(void)
{
	#ifdef DEBUG
		debug("FIXME: DEFER QUIT NOT IMPLEMENTED - Setting quit mode");
    #endif
}


/**
 *
 * @todo Describe function
 */
void
set_abort (int a)
{
  #ifdef DEBUG
	  debug("set_abort called with %d",a);
  #endif
  abort_pressed = a;
}


/*Param (char *str)    : String to strip                         */
/*Description          : Strips trailing \n from a string        */
/**
 *
 * @todo Describe function
 */
void
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
fgl_error (int a, char *s, int err, int stat)
{
  gotolinemode ();
  #ifdef DEBUG
	  debug ("\n\n\nError at line %d in file %s\n", a, s);
	  debug ("Error number %d - Error level %d\n\n", err, stat);
  #endif
  printf ("\n\n\nError at line %d in file %s\n", a, s);
  printf ("Error number %d - Error level %d\n\n", err, stat);
  exit (0);
  return 0;
}

/* ================================= EOF ============================= */

