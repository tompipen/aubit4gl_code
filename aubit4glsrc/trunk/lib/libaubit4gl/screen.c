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
# $Id: screen.c,v 1.6 2002-11-19 18:18:56 mikeaubury Exp $
#*/

/**
 * @file
 *
 * Part of run time library.
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/


#ifdef OLD_INCL

	#include "a4gl_dbform.h" 	/* needed for struct s_form_dets in function find_attribute */
	#include "a4gl_aubit_lib.h" /* zrefresh() */
	#include "a4gl_debug.h" 	/* debug() */

#else

    #include "a4gl_libaubit4gl_int.h"

#endif

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

extern int ui_mode;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


char * find_attribute (struct s_form_dets *f, int field_no);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 *
 * @param a
 */
int
screen_mode(int a)
{
  static int smode=1;
  if (a==-1)
	  return smode;

  if (a==smode)
    return smode;
  if (a==0)
  {
    smode=0;
    return smode;
  }
  smode=1;
  zrefresh();
	return smode;
}


/**
 * moved here from lib/libform/form_xdr/readforms.c
 *
 * @param a
 */
char *
find_attribute (struct s_form_dets *f, int field_no)
{
  int a;

  for (a = 0; a < f->fileform->attributes.attributes_len; a++)
    {

      if (f->fileform->attributes.attributes_val[a].field_no == field_no)
	{
	  debug ("FIeld no %d is reference by attribute %d\n", field_no, a);
	  return (char *) &f->fileform->attributes.attributes_val[a];
	}
    }
  debug ("Couldnt find entry for field no %d\n", field_no);
  return 0;

}



int
chk_iskey (char *keys)
{
  char *k;
  char s[256];
  strcpy (s, keys);
  strcat (s, "|");
  debug ("Chk keys %s\n", s);

  if (strcmp (keys, "->ANY") == 0)
    return 1;

  k = strtok (s, "|");
  while (1)
    {
      debug ("Chk keys (%s - %d %d )\n", k, key_val (k), get_lastkey ());
      if (key_val (k) == get_lastkey ())
        {
          return 1;
        }
      k = strtok (0, "|");
      if (k == 0)
        return 0;
    }
  return 0;
}

/* ============================ EOF ============================ */
