/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0   root makefile              |
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
# $Id: aubit-config.c,v 1.9 2003-05-12 14:24:31 mikeaubury Exp $
#
*/

/**
 * @file
 *
 * aubit-config.c gets compiled up with
 * resource.c to form the "aubit-config" program
 *
 *
 * This should be the first thing made and can then be used for the makefiles
 * where required.
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include <stdarg.h>
#include <stdio.h>
#include <string.h>		/* strcmp() */
#include <stdlib.h>		/* exit() */


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

extern void build_user_resources (void);
extern void exitwith (void);
extern void dump_all_resource_vars (int export);
extern char *acl_getenv (char *s);

void trim_nl (char *p);
void debug_full (char *fmt, ...);
void set_line (void);

//char * DEBUG_CFG;

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

int
main (int argc, char *argv[])
{


  if (argc != 2)
    {
      printf ("\n");
      printf ("Usage:\n");
      printf ("     aubit-config [VARIABLE_NAME | -a]\n");
      printf ("        -a: show all set variables\n");
      printf ("        -ae: show all set variables as 'export VARIABLE=\n");
      printf ("\n");
      exit (1);
    }

//      DEBUG_CFG = acl_getenv ("DEBUG_CFG");

  /* load settings from config file(s): */
  build_user_resources ();

  if (strcmp (argv[1], "-a") == 0)
    {
      dump_all_resource_vars (0);
      exit (0);
    }
  if (strcmp (argv[1], "-ae") == 0)
    {
      dump_all_resource_vars (1);
      exit (0);
    }

  printf ("%s\n", acl_getenv (argv[1]));

  exit (0);
}

/**
 *  Take of the last new line in a string.
 *
 *  @param p The string to be trimmed.
 */
void
trim_nl (char *p)
{
  int a;
  for (a = strlen (p) - 1; a >= 0; a--)
    {
      if (p[a] != ' ' && p[a] != '\n' && p[a] != '\r')
	break;
      p[a] = 0;
    }
}

/**
 * Simplified version of same function from libaubit4gl, to avoid linking
 * with libaubit4gl
 */
void
debug_full (char *fmt, ...)
{
  va_list args;
  static char buff[4096];

  /* Problem here is that when DEBUG is set, this will dump ALL settings
     to stdout. But when we are debugging, for instance, 4glc, and set DEBUG,
     we need aubit-config to return us things like AUBITDIR.

     As temporary sollution, I renamed DEBUG here to DEBUG_CFG.

   */


  if (strcmp ("ALL", acl_getenv ("DEBUG_CFG")) == 0)
//      if (strcmp ("ALL", DEBUG_CFG) == 0 )
    {
      va_start (args, fmt);
      vsprintf (buff, fmt, args);
      printf ("%s\n", buff);
    }
}

/**
 * Dummy function
 */
void
exitwith (void)
{
}

/**
 * Dummy function
 */
void
set_line (void)
{
}


/* -------------------------- EOF ------------------------ */
