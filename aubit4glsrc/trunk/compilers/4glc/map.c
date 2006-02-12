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
# $Id: map.c,v 1.39 2006-02-12 09:56:16 mikeaubury Exp $
#*/

/**
 * @file
 * Generation of map file.
 *
 * The map file is used to put in a file some mapping between the elements
 * in the 4gl source code and the line number module, etc.
 *
 * It is a file with pipe separated columns and \n separated records
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_4glc_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

static FILE *mapfile = 0;	/* The map file pointer opened file */

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Open the map file.
 *
 * If the environment variable MAP4GL is assigned with Y open the file
 * Downt do nothing otherwise
 *
 * @param s The map file name
 */
void
openmap (char *s)
{
  char buff[256];
#ifdef DEBUG
  A4GL_debug ("openmap");
#endif

  if (strcmp (acl_getenv ("MAP4GL"), "Y") == 0 && mapfile == 0)
    {
#ifdef DEBUG
      A4GL_debug ("Opening map file..%s \n", acl_getenv ("MAP4GL"));
#endif
      if (A4GL_isyes(acl_getenv("LOCALOUTPUT"))) {
		char *str;
		str=rindex(s,'/');
		if (str) s=str+1;
      }
      SPRINTF1 (buff, "%s.map", s);
      mapfile = fopen (buff, "w");

      if (mapfile == 0)
	{
#ifdef DEBUG
	  A4GL_debug ("Unable to open map file");
#endif
	  FPRINTF (stderr,"Unable to open map file\n");
	  exit (1);
	}
#ifdef DEBUG
      A4GL_debug ("Mapfile=%p", mapfile);
#endif
    }
}

/**
 * Add a new map to the opened file.
 *
 * Just adds if the mapfile was opened (controled by environment variable
 * MAP4GL)
 *
 * @param t The x4gl element type
 * @param s The name of the element
 * @param w The scope where the element was declared
 *    - MAIN
 *    - MODULE
 *    - Function name
 * @param l The line number in the source code where the implementation was
 *          started.
 * @param m The x4gl module name
 */
void
addmap (char *t, char *s, char *w, int l, char *m)
{
#ifdef DEBUG
  A4GL_debug ("Adding to map: %p", mapfile);
#endif
  if (mapfile)
    FPRINTF (mapfile, "%s|%s|%s|%d|%s|\n", t, s, w, l, m);
}

/**
 * Close the map file
 */
void
closemap (void)
{
  if (mapfile)
    fclose (mapfile);
}

/**
 * Remove the quotes from a quoted string.
 * @todo move in common library
 * @param s The string to be unquoted
 */
void
rm_quotes (char *s)
{
    char *d;
    if(*s == 0) return;
    for(d = s; *s; *s++)
	if(*s != '"')
	    *d++ = *s;
    *d = 0;
}

/**
 * Remove the quotes in the beginning and at the from a quoted string
 * @todo move in common library
 * @param s The string to be unquoted
 */
void
rm_quote (char *s)
{
  char *buff;
  int a;
  int b = 0;

  if(*s == 0) return;

  buff = calloc(strlen(s) + 1, 1);

  for (a = 0; a <= strlen(s); a++)
    {
      if (s[a] != '"')
	{
	  buff[b++] = s[a];
	}
    }
  for (a = strlen (buff) - 1; a >= 0; a--)
    {
      if (buff[a]=='/') break; // Maybe its a . or .. directory...
      if (buff[a] == '.')
	{
	  buff[a] = 0;
	  break;
	}
    }
  strcpy (s, buff);

  free(buff);
}


/* ================================ EOF ============================== */
