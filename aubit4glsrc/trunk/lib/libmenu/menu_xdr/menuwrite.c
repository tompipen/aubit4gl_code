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
# $Id: menuwrite.c,v 1.12 2003-05-15 07:10:42 mikeaubury Exp $
#*/

/**
 * @file
 *
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen A4GL_comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/


#include "a4gl_lib_menu_xdr_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

extern int as_c;
int scr = 0;
int cmaxcol = 0;
int cmaxline = 0;
int maxcol;
int maxline;
int newscreen = 0;
int fldno;
int fstart;
int openwith = 0;

char currftag[256];

struct struct_screen_record *curr_rec;
char buff_xdr[30000];

extern char *outputfilename;

struct menu_list the_menus;
struct struct_scr_field *fld;

char *chk_alias (char *s);
FILE *fxx;
FILE *fyy;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void A4GL_error_with (char *s, char *a, char *b);

#ifdef OLD_INCL
void A4GL_write_menu (void);
#endif

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * is this not the same as e-x-i-t-w-i-t-h-() ?
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
  exit (7);
}


/**
 * write the compiled menu data to file in Sun RPC XDR format
 *
 * @todo Describe function
 */
void
A4GL_write_menu (void)
{
  char fname[132];
  char fname2[132];
  int a;
  XDR xdrp;
  menu_list *ptr;
  ptr = &the_menus;
  strcpy (fname, outputfilename);
  strcat (fname, acl_getenv ("A4GL_MNU_EXT"));

  strcpy (fname2, outputfilename);
  strcat (fname2, ".c");


  fxx = fopen (fname, "wb");

  A4GL_debug ("has %d menus\n", the_menus.menus.menus_len);

  A4GL_debug ("writing in XDR format file %s\n", fname);

  if (fxx == 0)
    {
      A4GL_error_with ("Couldnt open file for write (%s)\n", fname, 0);
    }

  xdrstdio_create (&xdrp, fxx, XDR_ENCODE);
  a = xdr_menu_list (&xdrp, ptr);

  if (!a)
    {
      A4GL_debug ("*** Write FAILED ***\n");
      A4GL_error_with ("Unable to write data\n", 0, 0);
    }

  xdr_destroy (&xdrp);
  fclose (fxx);

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

}


/* =============================== EOF =============================== */
