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
# $Id: debug.c,v 1.34 2004-11-22 12:29:19 mikeaubury Exp $
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


#include "a4gl_libaubit4gl_int.h"
extern sqlca_struct a4gl_sqlca;
#ifdef strcpy
#undef strcpy
#endif
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
char g_fname[256];
int g_lineno;

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
	ptr=acl_getenv("DEBUGFILE");
	if (ptr) {
		if (strlen(ptr)) strcpy(debugfilename,ptr);
	}
}

  debugfile = A4GL_mja_fopen (debugfilename, "w");
  if (debugfile == 0)
    {
      printf ("Unable to open debug.out - check directory permissions...\n");
      exit (2);
    }
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
  va_list args;
  static char buff[40960];
  int a;
  int dbg_level;
  char buff_n[20];
  if (nodebug == DEBUG_NOTREQUIRED)
    return;

  if (nodebug == DEBUG_DONTKNOW)
    {
      if (strlen (acl_getenv ("DEBUG")))
	nodebug = DEBUG_REQUIRED;
      else
	{
	  nodebug = DEBUG_NOTREQUIRED;
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
  	dbg_level=atoi(acl_getenv("DEBUG_LEVEL"));
  	a=atoi(buff_n);
  	if (a && dbg_level && a > dbg_level) {
		return;
  	}
  }

  if (strncmp(g_fname,"API",3)==0) {
		char buff2[512];
		sprintf(buff2,"API %s\n",buff);
		A4GL_monitor_puts_int(buff2);
  }

  if (strcmp ("ALL", acl_getenv ("DEBUG")) == 0
      || strcmp (g_fname, acl_getenv ("DEBUG")) == 0)
    {
      va_start (args, fmt);
      vsprintf (buff, fmt, args);
      if (buff[strlen (buff) - 1] != ':')
	fprintf (debugfile, "%-20s %-6d (%6ld,%6ld,%1d)",
		 g_fname, g_lineno, a4gl_status, a4gl_sqlca.sqlcode,aclfgli_get_err_flg());
      else
	fprintf (debugfile, "%-20s                       "," ");

	if (a_strchr(buff,'\n')) 
      		fprintf (debugfile, " %s", buff);
	else
      		fprintf (debugfile, " %s\n", buff);

      /* fixme: A4GL_UI can also be gui, not only gtk
         Why are we printing this to stderr in any case, it is allready
         written to debug.out ?
       */



      /* This code is so we can A4GL_debug the GTK messages we get */
      if (strcmp (acl_getenv ("A4GL_UI"), "GTK") == 0)
	{
	  /* but not if we are running one of the compilers - this should
	     happen only when running Aubit compiled programs: */
	  if ((!strcmp (A4GL_getarg0 (), "4glc") == 0)
	      && (!strcmp (A4GL_getarg0 (), "fcompile") == 0)
	      && (!strcmp (A4GL_getarg0 (), "mcompile") == 0)
	      && (!strcmp (A4GL_getarg0 (), "mkmess") == 0))
	    {
	      fprintf (stderr, "%s\n", buff);
	      fflush (stderr);
	    }
	}

      //if (buff[strlen (buff) - 1] != ':') fprintf (debugfile, "LF\n");
      fflush (debugfile);
    }
}


/**
 * 
 * @todo Describe function
 */
int
A4GL_set_line (char *fname, long lineno)
{
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
