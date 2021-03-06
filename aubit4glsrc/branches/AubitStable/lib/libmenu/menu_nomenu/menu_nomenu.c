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
# $Id: menu_nomenu.c,v 1.10 2005-11-21 18:29:41 mikeaubury Exp $
#*/

/**
 * @file
 * aubit 4gl menus extension used when no other menu extensions are available or needed.
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


#include "a4gl_lib_menu_int.h"

#include "menu_x.x.h"
#include "a4gl_API_menu_lib.h"

//struct menu_list the_menus;

extern char *outputfilename;

FILE *fxx = 0;
FILE *fyy = 0;
extern int as_c;


void A4GL_error_with (char *s, char *a, char *b);

/* what do we need here? */


/**
 * write the compiled menu data to file in libPACKER format
 *
 * @todo Describe function
 */
void
A4GLMENU_A4GL_write_menu (void*ml)
{
  char fname[132];
  char fname2[132];
  int a;
  menu_list *ptr;

  ptr = ml;
  strcpy (fname, outputfilename);
  strcat (fname, acl_getenv ("A4GL_MNU_BASE_EXT"));

  strcpy (fname2, outputfilename);
  strcat (fname2, ".c");



  A4GL_debug ("has %d menus\n", ptr->menus.menus_len);

  A4GL_debug ("calling write_data_to_file\n", ptr->menus.menus_len);

  a = A4GL_write_data_to_file ("menu_list", ptr, fname);

  A4GL_debug ("returned from write_data_to_file()");

  if (!a)
    {
      A4GL_debug ("*** Write FAILED ***\n");
      A4GL_error_with ("Unable to write data\n", 0, 0);
    }


//      xdr_destroy(&xdrp);
  if (fxx)
    {
      //what is this closing anyway?
      fclose (fxx);
    }

  if (as_c)
    {
      int cnt = 0;
      int a;
      A4GL_debug ("Asc\n");
      fxx = fopen (fname, "r");
      fyy = fopen (fname2, "w");
      fprintf (fyy, "char compiled_menu_%s[]={\n", outputfilename);

      while (!feof (fxx))
	{
	  a = fgetc (fxx);
	  if (feof (fxx))
	    break;
	  if (cnt > 0)
	    fprintf (fyy, ",");
	  if (cnt % 16 == 0 && cnt)
	    {
	      fprintf (fyy, "\n");
	    }
	  if (a == -1)
	    {
	      break;
	    }
	  fprintf (fyy, "0x%02x", a);
	  cnt++;
	}
      fprintf (fyy, "};\n");
      fclose (fxx);
      fclose (fyy);
      /* unlink(fname); */
    }

  A4GL_debug ("Exiting write_menu()");

}

/**
 * is this not the same as exitwith() ?
 *
 * @todo Describe function
 */
void
A4GL_error_with (char *s, char *a, char *b)
{
  static char z[2];
  z[0] = 0;
  if (a == 0)
    a = z;
  if (b == 0)
    b = z;
  printf (s, a, b);

  A4GL_debug ("\n");
  exit (8);
}
