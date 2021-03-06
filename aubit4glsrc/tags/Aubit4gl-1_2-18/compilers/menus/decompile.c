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
# $Id: decompile.c,v 1.18 2008-07-06 11:34:27 mikeaubury Exp $
#*/

/**
 * @file
 * Menu files de-compiler
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

#include "a4gl_mcompile_int.h"

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void dump_options (menu * mm);
void dump_menu (menu_list * m);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 *
 * @todo Describe function
 */
int
main (int argc, char *argv[])
{
  struct menu_list the_menus;
/* FILE *f;
XDR xdrp; */
  int a = 0;

  if (argc != 2)
    {
      printf ("Usage %s filename\n", argv[0]);
      exit (0);
    }

  /*
     f=fopen(argv[1],"rb");

     if (f==0) {
     printf("Unable to open file %s\n",argv[1]);
     exit(2);
     }
   */

  memset (&the_menus, 0, sizeof (menu_list));
  A4GL_build_user_resources ();

  /*
     int      isolated_xdr_decompile                  (void* the_menus,void* xdrp,void* f);
     int      isolated_xdr_decompile                  (struct menu_list the_menus,XDR xdrp,FILE* f);
   */
  a = A4GL_read_data_from_file ("menu_list", &the_menus, argv[1]);

  if (!a)
    {
      printf ("Bad format\n");
    }
  else
    {
      dump_menu (&the_menus);
    }
  return 0;
}

/**
 *
 * @todo Describe function
 */
void
dump_menu (menu_list * m)
{
  int a;
  menu *mm;
  printf ("%d menus & submenus\n", m->menus.menus_len);
  for (a = 0; a < m->menus.menus_len; a++)
    {
      mm = &m->menus.menus_val[a];
      printf ("Menu : %s\n", mm->id);
      dump_options (mm);
    }
}

/**
 *
 * @todo Describe function
 */
void
dump_options (menu * mm)
{
  int a;
  menu_option_item *o;
  for (a = 0; a < mm->options.options_len; a++)
    {
      o = &mm->options.options_val[a];
      printf ("   %s (%s) ", o->id, o->caption);
      if (strlen (o->submenu_id) != 0)
	{
	  printf (" [Submenu ->%s] ", o->submenu_id);
	}
      printf (" Keys=%s Check=%d Attr=%x Color=%d\n", o->key_list,
	      o->checked, o->align, o->color);
      printf (" Image='%s'\n", o->image);
    }
}


/* ============================= EOF ================================== */
