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
# $Id: debug.c,v 1.13 2002-12-24 08:57:36 mikeaubury Exp $
#
*/

/**
 * @file
 *
 * @todo Add Doxygen comments to file
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/


#include "a4gl_libaubit4gl_int.h"


/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#define DEBUG_NOTREQUIRED 2
#define DEBUG_REQUIRED 1
#define DEBUG_DONTKNOW 0

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

FILE *debugfile = 0;
int nodebug = DEBUG_DONTKNOW;
char g_fname[256];
int g_lineno;

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
 *
 * @todo Describe function
 */
static void
open_debugfile (void)
{
  debugfile = mja_fopen ("debug.out", "w");
  if (debugfile==0) {
                printf("Unable to open debug.out - check directory permissions...\n");
        exit(2);
  }
}

/**
 *
 * @todo Describe function
 */
void
debug_full (char *fmt,...)
{
  va_list args;
  static char buff[40960];
  if (nodebug == DEBUG_NOTREQUIRED)
    return;

  if (nodebug == DEBUG_DONTKNOW)
    {
      if (strlen(acl_getenv ("DEBUG")))
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
  if (strcmp ("ALL", acl_getenv ("DEBUG")) == 0 || strcmp (g_fname, acl_getenv ("DEBUG")) == 0)
    {
      va_start (args, fmt);
      vsprintf (buff, fmt, args);
      if (buff[strlen (buff) - 1] != ':')
        fprintf (debugfile, "%-20s %-6d status=%6d sqlca.sqlcode=%6d\n ", g_fname, g_lineno, (int)status, sqlca.sqlcode);

      fprintf (debugfile, "%s\n", buff);

        /* fixme: A4GL_UI can also be gui, not only gtk
        Why are we printing this to stderr in any case, it is allready
        written to debug.out ?
        */
        


		/* This code is so we can debug the GTK messages we get */
		if (strcmp(acl_getenv("A4GL_UI"),"GTK")==0) {
                	fprintf(stderr,"%s\n",buff);
			fflush(stderr);
        	}
        
      if (buff[strlen (buff) - 1] != ':')
        fprintf (debugfile, "\n");
      fflush (debugfile);
    }
}


/**
 *
 * @todo Describe function
 */
int
set_line (char *fname, long lineno)
{
  if (nodebug == 1)
    {
      strcpy (g_fname, fname);

      g_lineno = lineno;
    }
  return 0;
}

/* =============================== EOF ============================= */
