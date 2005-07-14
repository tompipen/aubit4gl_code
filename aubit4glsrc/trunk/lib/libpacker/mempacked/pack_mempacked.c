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
# $Id: pack_mempacked.c,v 1.9 2005-07-14 11:32:55 mikeaubury Exp $
#*/

/**
 * @file
 *
 * @todo Doxygen comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_lib_packer_mempacked_int.h"

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

/*  Do we want the output indented ? */
#define INDENT


/*
-----------------------------------------------------------------------------
 PORTABLE
   Set if we are going to use network style integers
   Not set if we are going to use native integers
 (On some platforms these may be the same, on others they won't be)
-----------------------------------------------------------------------------
*/

#include <ctype.h>


/*
=====================================================================
                    Variables definitions
=====================================================================
*/


char *infile = 0;
//char mem_ibuff[20000];                                        /* Input line buffer */

//int mem_attrok = 0;
//int mem_contentok = 0;


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

char *A4GL_find_attr (char *s, char *n);	/* Extract a specified attribute from a string */
char *A4GL_find_contents (char *s);	/* Extract the tag contents from a string */

//int input_short (char *name, short *val, int ptr, int isarr);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/*
--------------------------------
--- API Functions
--------------------------------
*/

/*
-------------------------------------------------------------
 File IO routines
-------------------------------------------------------------
*/


/*
------------------------------------------------------------------------------
 Input Routines
------------------------------------------------------------------------------
*/


/**
 *
 * @todo Describe function
 */
int
input_start_array (char *s, int type, int *len)
{
  int a;
  a = input_int (s, len, 0, -1);
  A4GL_debug ("ARRAY %s - Length of array=%d", s, *len);
  return a;
}

/**
 *
 * @todo Describe function
 */
int
input_end_array (char *s, int type)
{
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
input_short (char *name, short *val, int ptr, int isarr)
{
  int a;
  A4GL_debug ("Input short %s", name);
  a = A4GL_memfile_fread ((char *)val, 1, sizeof (short), (void *)infile);
  *val = a4gl_ntohs (*val);
  return a;

}

int
input_char (char *name, char *val, int ptr, int isarr)
{
  int a;
  A4GL_debug ("Input short %s", name);
  a = A4GL_memfile_fread ((char *)val, 1, sizeof (char), (void *)infile);
  return a;

}


/**
 *
 * @todo Describe function
 */
int
input_int (char *name, int *val, int ptr, int isarr)
{
  if (sizeof (int) == sizeof (long))
    {
      return input_long (name, (long *) val, ptr, isarr);
    }
  else
    {
      return input_short (name, (short *) val, ptr, isarr);
    }
}

/**
 *
 * @todo Describe function
 */
int
input_long (char *name, long *val, int ptr, int isarr)
{
  /* long n; */
  int a;
  A4GL_debug ("Reading long %s", name);
  a = A4GL_memfile_fread ((char *)val, 1, sizeof (long), (void *)infile);
  A4GL_debug("Got a as %d val=%d (%x)\n",a,*val,*val);
  *val = a4gl_ntohl (*val);
  A4GL_debug ("->Got long %s  as %x\n", name, *val);
  return a;
}


/**
 *
 * @todo Describe function
 */
int
input_bool (char *name, int *val, int ptr, int isarr)
{
  return input_short (name, (short *) val, ptr, isarr);
}


/**
 *
 * @todo Describe function
 */
int
input_string (char *name, char **val, int ptr, int isarr)
{
  long l;
  int a;
  A4GL_debug ("Inputing string %s", name);
  if (!input_long ("", &l, 0, -1))
    return 0;
  A4GL_debug ("Got length as %d", l);
  *val = acl_malloc2 (l + 1);	/* Extra 1 for the \0 */
  memset (*val, 0, l + 1);
  a = A4GL_memfile_fread ((char *)*val, 1, l, (void *)infile);
  if (a == 0 && l == 0)
    return 1;
  return a;
}

/**
 *
 * @todo Describe function
 */
int
input_double (char *name, double *val, int ptr, int isarr)
{
  return A4GL_memfile_fread ((char *)val, 1, sizeof (*val), (void *)infile);
}

/**
 *
 * @todo Describe function
 */
int
input_start_struct (char *s, char *n, int ptr, int isarr)
{
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
input_end_struct (char *s, char *n)
{
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
input_start_union (char *s, char *n, int ptr, int isarr)
{
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
input_ptr_ok ()
{
  char n;
  A4GL_memfile_fread (&n, 1, sizeof (n),(void *) infile);
  if (n)
    return 1;
  else
    return 0;
}

/**
 *
 * @todo Describe function
 */
int
input_end_union (char *s, char *n)
{
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
input_enum (char *name, int *d)
{
  return input_int (name, d, 0, -1);
}



/*
--------------------------------
--- API Functions
--------------------------------
*/

/*
-------------------------------------------------------------
 File IO routines
-------------------------------------------------------------
*/

/**
 *
 * @todo Describe function
 */
int
A4GL_open_packer (char *basename, char dir)
{
  //char buff[256];
  char *ptr = 0;
  A4GL_debug ("MEMPACKER : basename=%s\n", basename);
  ptr = strchr (basename, '.');
  *ptr = 0;

  if (A4GL_has_pointer (basename, COMPILED_FORM))
    {
      ptr = A4GL_find_pointer_val (basename, COMPILED_FORM);
    }

  if (ptr == 0)
    {
      A4GL_exitwith ("Unable to open form in memory");
    }

  if (toupper (dir) == 'I')
    {
      //int n;
      infile = (void *)A4GL_memfile_fopen_buffer (ptr, -1);

      if (infile)
	{
	  return 1;
	}
      return 0;
    }

  return 0;

}

/**
 *
 * @todo Describe function
 */
void
A4GL_close_packer (char dir)
{
  if (toupper (dir) == 'I')
    {
      free (infile);
      infile = 0;
    }
}




int
A4GL_can_pack_all (char *name)
{
  return 0;
}
