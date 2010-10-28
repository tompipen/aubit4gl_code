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
# | contact licensing@aubit.com                                           |
# +----------------------------------------------------------------------+
#
# $Id: map.c,v 1.52 2010-10-28 20:34:44 mikeaubury Exp $
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
//static void map_select_list_item (char *stmttype,struct s_select *select, struct s_select_list_item *p);
//static void map_select_list_item_list (char *stmttype, char*listtype,struct s_select *select, struct s_select_list_item_list *i);

int A4GL_has_column (char *t, char *c);

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

static FILE *mapfile = 0;	/* The map file pointer opened file */
FILE *crudfile = 0;	/* The map file pointer opened file */
extern char curr_func[];
extern int yylineno;
extern char infilename[];
//static char *module_name_without_dirstart(char *s) ;

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

  if (strcmp (acl_getenv ("A4GL_MAP4GL"), "Y") == 0 && mapfile == 0)
    {
#ifdef DEBUG
      A4GL_debug ("Opening map file..%s \n", acl_getenv ("A4GL_MAP4GL"));
#endif
      if (A4GL_isyes (acl_getenv ("A4GL_LOCALOUTPUT")))
	{
	  char *str;
	  str = rindex (s, '/');
	  if (str)
	    s = str + 1;
	}
      SPRINTF1 (buff, "%s.map", s);
      mapfile = fopen (buff, "w");

      if (mapfile == 0)
	{
#ifdef DEBUG
	  A4GL_debug ("Unable to open map file");
#endif
	  FPRINTF (stderr, "Unable to open map file\n");
	  exit (1);
	}
#ifdef DEBUG
      A4GL_debug ("Mapfile=%p", mapfile);
#endif
    }

  if (strcmp (acl_getenv ("MAPCRUD"), "Y") == 0 && crudfile == 0)
    {
      if (A4GL_isyes (acl_getenv ("A4GL_LOCALOUTPUT")))
	{
	  char *str;
	  str = rindex (s, '/');
	  if (str)
	    s = str + 1;
	}
      SPRINTF1 (buff, "%s.map.xml", s);

      crudfile = fopen (buff, "w");

      if (crudfile == 0)
	{
#ifdef DEBUG
	  A4GL_debug ("Unable to open map file");
#endif
	  FPRINTF (stderr, "Unable to open CRUD map file\n");
	  exit (1);
	}
      //FPRINTF(crudfile,"<MODULE NAME=\"%s\">\n",module_name_without_dirstart(infilename));
      FPRINTF(crudfile,"   <FUNCTIONS>\n");


    }


}

/**
 * Add a new map to the opened file.
 *
 * Just adds if the mapfile was opened (controled by environment variable
 * A4GL_MAP4GL)
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
  static char *last_w = 0;
  static int last_l = 0;
  static char *last_m = 0;

  if (m == 0)
    m = last_m;
  if (l == 0)
    l = last_l;
  if (w == 0)
    w = last_w;

  if (w == 0)
    w = "";
  if (m == 0)
    m = "";
  last_w = w;
  last_l = l;
  last_m = m;

#ifdef DEBUG
  A4GL_debug ("Adding to map: %p", mapfile);
#endif
  if (mapfile)
    FPRINTF (mapfile, "%s|%s|%s|%d|%s|\n", t, s, w, l, m);
}

void
addmap_p (char *t, struct expr_str *s, char *w, int l, char *m) {
//@ FIXME
}
/**
 * Close the map file
 */
void
closemap (void)
{
  if (mapfile)
    fclose (mapfile);
  if (crudfile)  {
         FPRINTF(crudfile,"   </FUNCTIONS>\n");
	  //FPRINTF(crudfile,"</MODULE>\n");
	  fclose(crudfile);
  }
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

  if (*s == 0)
    return;

  for (d = s; *s; s++)
    {
      if (*s != '"')
	*d++ = *s;
    }
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

  if (*s == 0)
    return;

  buff = calloc (strlen (s) + 1, 1);

  for (a = 0; a <= strlen (s); a++)
    {
      if (s[a] != '"')
	{
	  buff[b++] = s[a];
	}
    }
  for (a = strlen (buff) - 1; a >= 0; a--)
    {
      if (buff[a] == '/')
	break;			// Maybe its a . or .. directory...
      if (buff[a] == '.')
	{
	  buff[a] = 0;
	  break;
	}
    }
  strcpy (s, buff);

  free (buff);
}



void add_used_cmd(char *s) {
FILE *f;
if (A4GL_isyes(acl_getenv("LOGCMDS"))) {
	f=fopen("/tmp/used_cmds.log","w");
	fprintf(f,"%s\n",s);
	fclose(f);
}
}



/* ================================ EOF ============================== */
