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
# $Id: params.c,v 1.2 2002-10-13 11:44:40 afalout Exp $
#*/

/**
 * @file
 * The param mechanism for the GTK lib store parameters.
 *
 * Its a kind of hash where we store vales by key
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/


#include "a4gl_lib_ui_gtk_int.h"

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#define TYPE_CHAR 1
#define TYPE_INT 2

/*
=====================================================================
                    Variables definitions
=====================================================================
*/


/** The arguments count */
static int args_cnt;

/** Array of arguments stored. */
static char *args[256];

/** The values of the parameters */
static char *args_val[256];

/** The types of the parameters */
static int args_type[256];

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

#ifdef OLD_INCL
	void split_config (char *str);
	void * find_param (char *name);
#endif


/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Get parameters from a string.
 *
 * The parameter separator is ;
 *
 * @param str The string with the parameters.
 */
void
split_config (char *str)
{
  char *ptr;
  char *s;
  int a;
  ptr = str;
  args_cnt = 0;
  while (1)
    {

      s = strtok (ptr, ";");

      if (s)
	{
	  args[args_cnt++] = s;
	}
      else
	{
	  break;
	}

      ptr = 0;
    }

  for (a = 0; a < args_cnt; a++)
    {
      args_val[a] = 0;
      ptr = strchr (args[a], '=');
      if (ptr)
	{
	  *ptr = 0;
	  args_val[a] = ptr + 1;
	}
      if (args_val[a][0] == '\'')
	{
	  args_type[a] = TYPE_CHAR;
	  args_val[a][strlen (args_val[a]) - 1] = 0;
	  args_val[a]++;
	}
      else
	{
	  args_type[a] = TYPE_INT;
	}

      debug ("'%s' = --%s-- type=%d\n", args[a], args_val[a], args_type[a]);
    }
}

/**
 * Find a values of a parameter by name.
 *
 * @param name The name of the parameter to be finded.
 * @return A pointer to the bytes that have the values stored.
 */
void *
find_param (char *name)
{
  int a;
  int reqd = 1;
  if (name[0] == '*')
    {
      reqd = 0;
      name++;
    }
  for (a = 0; a < args_cnt; a++)
    {
      if (strcasecmp (args[a], name) == 0)
	{
	  if (args_type[a] == TYPE_CHAR)
	    return args_val[a];
	  else
	    return (void *) atoi (args_val[a]);
	}
    }

  if (reqd)
    {
      debug ("Required Parameter not found %s\n", name);
      return 0;
    }
  else
    {
      return 0;
    }

}


/* ============================== EOF =============================== */
