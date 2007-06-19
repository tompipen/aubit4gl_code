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
# $Id: debug.c,v 1.57 2007-06-19 19:40:34 mikeaubury Exp $
#
*/

/**
 * @file
 *
 * The A4GL_debug utility functions.
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/


#define NOSTRCPYMAP
#include "a4gl_libaubit4gl_int.h"
#include <ctype.h>
extern sqlca_struct a4gl_sqlca;

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#define DEBUG_NOTREQUIRED 	2
#define DEBUG_REQUIRED 		1
#define DEBUG_DONTKNOW 		0


/*
=====================================================================
                    Variables definitions
=====================================================================
*/

FILE *debugfile = 0;
int nodebug = DEBUG_DONTKNOW;
static char g_fname[1024];
static char g_function[128];
static char g_level[64];
static int g_lineno;
static int opened_debug_output=0;

static char arg0[15] = "**undefined**";


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

static void open_debugfile (void);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/



/**
 * Open the A4GL_debug file.
 *
 * @todo Describe function
 */
static void
open_debugfile (void)
{
static char debugfilename[256]="";
if (strlen(debugfilename)==0) {
	char *ptr;
	strcpy(debugfilename,"debug.out");
	ptr=acl_getenv("A4GL_DEBUGFILE");
	if (ptr) {
		if (strlen(ptr)) strcpy(debugfilename,ptr);
	}
}

  if (!opened_debug_output ) {
    	opened_debug_output++;
    	debugfile = fopen (debugfilename, "w");
   } else {
    	debugfile = fopen (debugfilename, "a");
   }
  if (debugfile == 0)
    {
      PRINTF ("Unable to open debug.out - check directory permissions...\n");
	A4GL_fgl_die(2);
    }
}




/**
 * The A4GL_debug function.
 * The function is used because it exist a define that calls
 * it, if A4GL_debug is set.
 *
 */
void
A4GL_debug_full_extended (char *fmt, ...)
{
  static va_list args;
#define MAX_DEBUG 90000
  static char buff[MAX_DEBUG+1];
  static int a;
  static int dbg_level=-1;
  static char buff_n[20];
  static int indebug=0;


  if (nodebug == DEBUG_NOTREQUIRED) { return; }

  if (indebug) return;
  indebug++;


  if (strlen(fmt)==0) {
		A4GL_assertion(1,"No format for debug");
		A4GL_pause_execution();
  }

  if (nodebug == DEBUG_DONTKNOW)
    {
      if (strlen (acl_getenv ("DEBUG")))
	nodebug = DEBUG_REQUIRED;
      else
	{
	  nodebug = DEBUG_NOTREQUIRED;
	  indebug=0;
	  return;
	}
    }


  if (isdigit(fmt[0])) {
	if (!isdigit(fmt[1])) {
		buff_n[0]=fmt[0];
		buff_n[1]=0;
	} else {
		buff_n[0]=fmt[0];
		buff_n[1]=fmt[1];
		buff_n[2]=0;
	}
	if (dbg_level==-1)  {
  		dbg_level=atoi(acl_getenv("DEBUG_LEVEL"));
	}
  	a=atoi(buff_n);
  	if (a && dbg_level && a > dbg_level) {
		indebug=0;
		return;
  	}
  }

  if (strncmp(g_fname,"API",3)==0) {
		char buff2[MAX_DEBUG+100];
		SPRINTF1(buff2,"API %s\n",buff);
#ifdef USE_MONITOR
		A4GL_monitor_puts_int(buff2);
#endif
  }

  if (strcmp ("ALL", acl_getenv ("DEBUG")) == 0
      || strcmp (g_fname, acl_getenv ("DEBUG")) == 0)
    {
        va_start (args, fmt);
	memset(buff,0,sizeof(buff));

#ifdef  HAVE_VSNPRINTF
	VSNPRINTF (buff, MAX_DEBUG,fmt, args);
#else
      	VSPRINTF (buff, fmt, args);
#endif

	buff[MAX_DEBUG]=0;

  	open_debugfile ();

  	if (!debugfile) return;
      if (buff[strlen (buff) - 1] != ':')
	FPRINTF (debugfile, "%-20s %-6d %-3s (%6ld,%6ld,%1d) %s%s",
		 g_fname, g_lineno, g_level, a4gl_status, a4gl_sqlca.sqlcode,aclfgli_get_err_flg(),
		 g_function, g_function[0] == 0 ? "": "() ");
      else
	FPRINTF (debugfile, "%-20s                       "," ");

	if (a_strchr(buff,'\n')) 
      		FPRINTF (debugfile, " %s", buff);
	else
      		FPRINTF (debugfile, " %s\n", buff);

	fclose(debugfile);

    }
  indebug=0;
}

/**
 * The A4GL_debug function.
 * The function is used because it exist a define that calls
 * it, if A4GL_debug is set.
 *
 */
void
A4GL_debug_full (char *fmt, ...)
{
  static va_list args;
#define MAX_DEBUG 10000
  static char buff[MAX_DEBUG+1];
  static int a;
  static int dbg_level=-1;
  static char buff_n[20];
  static int indebug=0;


  if (nodebug == DEBUG_NOTREQUIRED) { return; }

  if (indebug) return;
  indebug++;


  if (strlen(fmt)==0) {
		A4GL_assertion(1,"No format for debug");
		A4GL_pause_execution();
  }

  if (nodebug == DEBUG_DONTKNOW)
    {
      if (strlen (acl_getenv ("DEBUG")))
	nodebug = DEBUG_REQUIRED;
      else
	{
	  nodebug = DEBUG_NOTREQUIRED;
	  indebug=0;
	  return;
	}
    }

  if (debugfile == 0)
    {
      open_debugfile ();
    }

  if (isdigit(fmt[0])) {
	if (!isdigit(fmt[1])) {
		buff_n[0]=fmt[0];
		buff_n[1]=0;
	} else {
		buff_n[0]=fmt[0];
		buff_n[1]=fmt[1];
		buff_n[2]=0;
	}
	if (dbg_level==-1)  {
  		dbg_level=atoi(acl_getenv("DEBUG_LEVEL"));
	}
  	a=atoi(buff_n);
  	if (a && dbg_level && a > dbg_level) {
		indebug=0;
		return;
  	}
  }

  if (strncmp(g_fname,"API",3)==0) {
		char buff2[MAX_DEBUG+100];
		SPRINTF1(buff2,"API %s\n",buff);
#ifdef USE_MONITOR
		A4GL_monitor_puts_int(buff2);
#endif
  }

  if (strcmp ("ALL", acl_getenv ("DEBUG")) == 0
      || strcmp (g_fname, acl_getenv ("DEBUG")) == 0)
    {
      va_start (args, fmt);
	memset(buff,0,sizeof(buff));

#ifdef  HAVE_VSNPRINTF
	VSNPRINTF (buff, MAX_DEBUG,fmt, args);
#else
      	VSPRINTF (buff, fmt, args);
#endif

	buff[MAX_DEBUG]=0;
      if (buff[strlen (buff) - 1] != ':')
	FPRINTF (debugfile, "%-20s %-6d (%6ld,%6ld,%1d)",
		 g_fname, g_lineno, a4gl_status, a4gl_sqlca.sqlcode,aclfgli_get_err_flg());
      else
	FPRINTF (debugfile, "%-20s                       "," ");

	if (a_strchr(buff,'\n')) 
      		FPRINTF (debugfile, " %s", buff);
	else
      		FPRINTF (debugfile, " %s\n", buff);

      fflush (debugfile);
    }
  indebug=0;
}


/**
 * 
 * @todo Describe function
 */
int
A4GL_set_line_extended (char *fname, long lineno, const char *level, const char *func)
{
  if (nodebug == DEBUG_NOTREQUIRED) { return 0; }
  if (nodebug == 1)
    {
      strcpy (g_fname, fname);
      strcpy (g_level, level);
      strcpy (g_function, func);
      g_lineno = lineno;
    }
  return 0;
}

/**
 * 
 * @todo Describe function
 */
int
A4GL_set_line (char *fname, long lineno)
{
  if (nodebug == DEBUG_NOTREQUIRED) { return 0; }
  if (nodebug == 1)
    {
      strcpy (g_fname, fname);

      g_lineno = lineno;
    }
  return 0;
}


/**
 * Store basename of command, excluding trailing slashes
 * Doesn't handle two pathological cases -- "/" and ""
 *
 */
void
A4GL_setarg0 (const char *argv0)
{
  const char *cp;
#if ( defined (__MINGW32__) )
  char a[128];
  char b[128];
  char c[128];
#endif

  size_t nbytes = sizeof (arg0) - 1;


#if ( defined (__MINGW32__) )

  if (((cp = strrchr (argv0, '/')) != (char *) 0 && *(cp + 1) == '\0')
      || ((cp = strrchr (argv0, '\\')) != (char *) 0 && *(cp + 1) == '\0'))
    {
      /* Skip backwards over trailing slashes */
      const char *ep = cp;
      while (ep > argv0 && ((*ep == '/') || (*ep == '\\')))
	ep--;
      /* Skip backwards over non-slashes */
      cp = ep;
      while (cp > argv0 && ((*cp != '/') && (*cp != '\\')))

#else
  if ((cp = strrchr (argv0, '/')) != (char *) 0 && *(cp + 1) == '\0')
    {
      /* Skip backwards over trailing slashes */
      const char *ep = cp;
      while (ep > argv0 && *ep == '/')
	ep--;
      /* Skip backwards over non-slashes */
      cp = ep;
      while (cp > argv0 && *cp != '/')
#endif

	cp--;
      cp++;
      nbytes = ep - cp + 1;
      if (nbytes > sizeof (arg0) - 1)
	nbytes = sizeof (arg0) - 1;
    }
  else if (cp != (char *) 0)
    {
      /* Regular pathname containing slashes */
      cp++;
    }
  else
    {
      /* Basename of file only */
      cp = argv0;
    }
  strncpy (arg0, cp, nbytes);
  arg0[nbytes] = '\0';

#if ( defined (__MINGW32__) )
  /* A4GL_strip .exe extension */


  strcpy (c, arg0);
  A4GL_bname (c, a, b);
  strcpy (arg0, a);

#endif


}

/**
 * Returns the basename of the command used to start this application
 *
 */

const char *
A4GL_getarg0 (void)
{
  return (arg0);
}


/*
Return file name without the path
Yes, it is a mess, but this works
*/
void
a4gl_basename (char **ppsz)
{
  char *pszslash;

  for (pszslash = *ppsz; *pszslash; pszslash++)
    if ((*pszslash == '\\') || (*pszslash == '/'))
      {
	*ppsz = pszslash + 1;
      }
}


/* =============================== EOF ============================= */
