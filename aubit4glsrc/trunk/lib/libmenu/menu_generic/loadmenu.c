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
# $Id: loadmenu.c,v 1.12 2005-03-09 15:14:47 mikeaubury Exp $
#*/

/**
 * @file
 * aubit 4gl compiled menus load in GTK mode, from PACKER fromated file.
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen A4GL_comments to add to functions
 */



//this is just a copy of XDR version - see lined marked with :
 //FIXME>>>>>>>>>
// to make it work, XDR definitions need to be replaced with libPACKER calls !!!


#include "a4gl_lib_menu_generic_int.h"

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

/*
=====================================================================
		                    Includes
=====================================================================
*/



/*
=====================================================================
                    Variables definitions
=====================================================================
*/


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
 * Load 4gl menus from a compiled file.
 * A redirector function to satisfy function prototype in API while using
 * void pointer in return
 *
 * @param fname
 * @param menuid The menu name.
 * @param mode
 * @param handler The menu handler name.
 * @return A pointer to the menu widget created.
 */
void *
A4GL_load_menu (char *fname, char *menu_id, int mode, void *handler)
{
  struct menu_list the_menus;
  int a = 0;
  void *w = 0;

  memset (&the_menus, 0, sizeof (menu_list));
  a = A4GL_read_data_from_file ("menu_list", &the_menus, fname);

  if (!a)
    {
      A4GL_debug ("Bad format\n");
    }
  else
    {
      w = A4GL_create_menu (&the_menus, menu_id, mode, handler);
      A4GL_debug("Created menu as %p\n",w);

    }
  A4GL_debug ("All done - menubar should be displayed\n");
  A4GL_gui_run_til_no_more ();
  return w;
}


/**
 * Implementation of the SHOW MENU 4gl statement in GTK GUI mode.
 *
 * @param menuid The menu name.
 * @param handler The menu handler name.
 */
void
A4GL_show_menu (char *menuid, void *handler)
{
  char *fname;
  void (*p) (char *);
  char buff[256];

  fname = A4GL_char_pop ();
  p = handler;

  sprintf (buff, "%s%s", fname, acl_getenv ("A4GL_MNU_BASE_EXT"));	// packer extension (xml/dat) is added later in libPACKER_

  fname = (char *) buff;
  A4GL_debug ("show_menu >%s<", fname);
  A4GL_load_menu (fname, menuid, 0, handler);
  p ("__BSM__");
}

/* =================================== EOF ============================= */
