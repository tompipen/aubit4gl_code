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
# $Id: pack_mempacked.c,v 1.17 2010-02-16 13:16:58 mikeaubury Exp $
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

//int A4GLPacker_A4GLPacker_input_short (char *name, short *val, int ptr, int isarr);

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
A4GLPacker_input_start_array (char *s, int type, int *len)
{
  int a;
  a = A4GLPacker_input_int (s, len, 0, -1);
#ifdef DEBUG
  A4GL_debug ("ARRAY %s - Length of array=%d", s, *len);
#endif
  return a;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_input_end_array (char *s, int type)
{
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_input_short (char *name, short *val, int ptr, int isarr)
{
  int a;
#ifdef DEBUG
  A4GL_debug ("Input short %s", name);
#endif
  a = A4GL_memfile_fread ((char *)val, 1, sizeof (short), (void *)infile);
  *val = a4gl_ntohs (*val);
  return a;

}

int
A4GLPacker_input_char (char *name, char *val, int ptr, int isarr)
{
  int a;
#ifdef DEBUG
  A4GL_debug ("Input short %s", name);
#endif
  a = A4GL_memfile_fread ((char *)val, 1, sizeof (char), (void *)infile);
  return a;

}


/**
 *
 * @todo Describe function
 */
int
A4GLPacker_input_int (char *name, int *val, int ptr, int isarr)
{
int a;
  if (sizeof (int) != sizeof (short)) // 32 or 64 Bit ?
    {
      long z;
	a=A4GLPacker_input_long (name, &z, ptr, isarr);
	*val=z;
	return a;
    }
  else
    {
      return A4GLPacker_input_short (name, (short *) val, ptr, isarr);
    }
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_input_long (char *name, long *val, int ptr, int isarr)
{
  /* long n; */
  int a;
#ifdef DEBUG
  A4GL_debug ("Reading long %s", name);
#endif
  a = A4GL_memfile_fread ((char *)val, 1, sizeof (long), (void *)infile);
#ifdef DEBUG
  A4GL_debug("Got a as %d val=%d (%x)\n",a,*val,*val);
#endif
  *val = a4gl_ntohl (*val);
#ifdef DEBUG
  A4GL_debug ("->Got long %s  as %x\n", name, *val);
#endif
  return a;
}


/**
 *
 * @todo Describe function
 */
int
A4GLPacker_input_bool (char *name, int *val, int ptr, int isarr)
{
  return A4GLPacker_input_short (name, (short *) val, ptr, isarr);
}


/**
 *
 * @todo Describe function
 */
int
A4GLPacker_input_string (char *name, char **val, int ptr, int isarr)
{
  long l;
  int a;
#ifdef DEBUG
  A4GL_debug ("Inputing string %s", name);
#endif
  if (!A4GLPacker_input_long ("", &l, 0, -1))
    return 0;
#ifdef DEBUG
  A4GL_debug ("Got length as %d", l);
#endif
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
A4GLPacker_input_double (char *name, double *val, int ptr, int isarr)
{
  return A4GL_memfile_fread ((char *)val, 1, sizeof (*val), (void *)infile);
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_input_start_struct (char *s, char *n, int ptr, int isarr)
{
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_input_end_struct (char *s, char *n)
{
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_input_start_union (char *s, char *en, int *e,char *n, int ptr, int isarr)
{
int a;
  a=A4GLPacker_input_int (en, e, 0, -1);
  if (!a) { 
#ifdef DEBUG
A4GL_debug("Failed to read %s %s %s",s,en,n); 
#endif
}
  return a;

}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_input_ptr_ok ()
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
A4GLPacker_input_end_union (char *s,char *en, int e, char *n)
{
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_input_enum (char *name, char *en,  int *d)
{
  return A4GLPacker_input_int (name, d, 0, -1);
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
A4GLPacker_A4GL_open_packer (char *basename, char dir,char *packname,char *version)
{
  //char buff[256];
  char *ptr = 0;
#ifdef DEBUG
  A4GL_debug ("MEMPACKER : basename=%s\n", basename);
#endif
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
A4GLPacker_A4GL_close_packer (char dir)
{
  if (toupper (dir) == 'I')
    {
      free (infile);
      infile = 0;
    }
}




int
A4GLPacker_A4GL_can_pack_all (char *name)
{
  return 0;
}

char *A4GLPacker_A4GL_get_packer_ext(void) {
        return ".c"; 
}




void A4GLPacker_A4GL_output_common_header(char* module,char* version) {
	// mempacker can only read pregenerated output - this should never happen
	A4GL_assertion(1,"MEMPACKER is readonly..");
}

int A4GLPacker_A4GL_valid_common_header(char* module,char* version) {
        char buff[200];
        char buff_r[200];

	// THIS MUST MATCH THE DEFINITION IN 
	// lib/libpacker/packed/pack_packed.c
        sprintf(buff,"A4GL FILE : %s %s\n",module,version);
	// otherwise - we'll be checking against the wrong header!!


        A4GL_memfile_fread (buff_r, 1, strlen(buff), (void *) infile);
        if (memcmp(buff,buff_r,strlen(buff))==0) { // Everything is ok...
                return 1;
        }
        return 0;
}

