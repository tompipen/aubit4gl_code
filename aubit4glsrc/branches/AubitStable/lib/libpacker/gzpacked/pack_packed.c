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
# $Id: pack_packed.c,v 1.5 2005-11-21 18:29:41 mikeaubury Exp $
#*/

/**
 * @file
 * packed packer
 *
 * NOTE: it seems that on Windows calls originating in plug-in dll will go directly to
 * function called, if it's defined in same plug-in, and bypass the API.
 * On Linux, all calls would go via API regardless...
 *
 * @todo Doxygen comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_lib_packer_packed_int.h"
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


FILE *infile = 0;
FILE *outfile = 0;

char ibuff[20000];		/* Input line buffer */

int attrok = 0;
int contentok = 0;
int is_in_mem = 0;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

char *A4GL_find_attr (char *s, char *n);	/* Extract a specified attribute from a string */
char *A4GL_find_contents (char *s);	/* Extract the tag contents from a string */

//int A4GLPacker_input_short (char *name, short *val, int ptr, int isarr);
//int A4GLPacker_output_short (char *name, short val, int ptr, int isarr);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

#ifdef _TESTING_
/**
 * Internal helper function
 *
 * @todo Describe function
 */
static void chk (void *x);

static void
chk (void *x)
{
  if ((int) x < 10000)
    {
      printf ("Suspect pointer...\n");
      exit (0);
    }
}
#endif

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

FILE *
A4GL_gz_try_to_open (char *path, char *name, int keepopen)
{
char buff[2048];
FILE *f;
 A4GL_debug("path=%s name=%s",path,name);
  if (strlen (name) == 0)
    return 0;

  if (strlen (path))
    {
                //Forward slash should work on Windows just fine...
                //#ifndef WIN32 - we need __MINGW32__ or __CYGWIN__
              sprintf (buff, "%s/%s", path, name);
                //#else
                //  sprintf (buff, "%s\\%s", path, name);
                //#endif
    }
  else
    {
      sprintf (buff, name);
    }

        A4GL_debug ("Opening path '%s'", buff);


  /* Does it exist and can we read it ? */

        //FIXME: apparently does not wok with relative paths?
        f = fopen (buff, "r");
        if (f == 0) {
                A4GL_debug("Unable to open %s %s (%s)",path,name,buff);
                return (FILE *) 0;
        }
        if (!keepopen) {                                /* We just wanted to check.. */
          fclose (f);
                A4GL_debug("open %s %s (%s) was successful",path,name,buff);
          return (FILE *) 1;
        }
        A4GL_debug ("opened file %s in path %s", name, path);
        return f;                       /* We want it opened.. */
}


FILE *
A4GL_gz_open_file_dbpath (char *fname)
{
char str_path[2048];
int cnt;
char *ptr;
int str_len;
A4GL_debug("fname=%s",fname);
        memset (str_path, 0, 2048);

A4GL_debug("Try1");
        if (A4GL_gz_try_to_open ("", fname, 0)) {
                return A4GL_gz_try_to_open ("", fname, 1);
        }

A4GL_debug("Try2");
        if (A4GL_gz_try_to_open (".", fname, 0)) {
                return A4GL_gz_try_to_open (".", fname, 1);
        }

A4GL_debug("Try3");
        if (strlen (acl_getenv ("DBPATH"))) {
                strcpy (str_path, acl_getenv ("DBPATH"));
        }

        str_len = strlen (str_path);
        ptr = str_path;

        for (cnt = 0; cnt < str_len; cnt++) {
                #ifdef __MINGW32__
                if (str_path[cnt] == ';') {
                #else
                if (str_path[cnt] == ':') {
                #endif
            //if next char is a separator, skip that one too...
                        #ifdef __MINGW32__
                        if (str_path[cnt+1] == ';') {
            #else
            if (str_path[cnt+1] == ':') {
            #endif
                                cnt++;
                                ptr = &str_path[cnt];
            }

                        if ( cnt !=0 ) {
                                str_path[cnt] = 0;
                                if (strlen (ptr)) {
                                        if (A4GL_gz_try_to_open (ptr, fname, 0)) {
                                                return A4GL_gz_try_to_open (ptr, fname, 1);
                        } else {
                                                cnt++;
                                                ptr = &str_path[cnt];
                        }
                                }
                        } else {
                                //skip over separator if found as first character:
                                cnt++;
                                ptr = &str_path[cnt];
                        }
        }
        }

        if (strlen (ptr)) {
A4GL_debug("Try4 : %s",ptr);
                if (A4GL_gz_try_to_open (ptr, fname, 0)) {
                        return A4GL_gz_try_to_open (ptr, fname, 1);
        }
        }

        return (FILE *) 0;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_A4GL_open_packer (char *basename, char dir)
{
  char buff[256];
  is_in_mem = 0;

  if (toupper (dir) == 'O')  {
      sprintf (buff, "%s%s", basename,acl_getenv("A4GL_PACKED_EXT"));
      outfile = fopen (buff, "w");

    if (outfile) {
		  A4GL_set_last_outfile (buff);
		  return 1;
	}
    return 0;
  }

  if (toupper (dir) == 'I')
    {
      sprintf (buff, "%s%s", basename, acl_getenv("A4GL_PACKED_EXT"));
      infile = A4GL_gz_open_file_dbpath (buff);
      if (infile)
	return 1;
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
  if (toupper (dir) == 'O')
    fclose (outfile);

  if (toupper (dir) == 'I')
    fclose (infile);
}

/*
----------------------------------------------------------------------------
 Output routines
----------------------------------------------------------------------------
*/

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_output_start_array (char *s, int type, int len)
{

  return A4GLPacker_output_long (s, len, 0, -1);
  /* return fwrite(&len,1,sizeof(len),outfile); */
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_output_end_array (char *s, int type)
{
  return 1;
}


/**
 *
 * @todo Describe function
 */
int
A4GLPacker_output_short (char *name, short val, int ptr, int isarr)
{
  A4GL_debug ("Outputing SHORT %s : 0x%x", name, val);
  val = a4gl_htons (val);
  return fwrite (&val, 1, sizeof (val), outfile);
}

int
A4GLPacker_output_char (char *name, char val, int ptr, int isarr)
{
  A4GL_debug ("Outputing CHAR %s : 0x%x", name, val);
  return fwrite (&val, 1, sizeof (char), outfile);
}


/**
 *
 * @todo Describe function
 */
int
A4GLPacker_output_int (char *name, int val, int ptr, int isarr)
{
  if (sizeof (int) == sizeof (long))
    {
      return A4GLPacker_output_long (name, val, ptr, isarr);
    }
  else
    {
      return A4GLPacker_output_short (name, val, ptr, isarr);
    }
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_output_long (char *name, long val, int ptr, int isarr)
{
  int a;
  A4GL_debug ("Outputing LONG %s - 0x%x\n", name, val);
  val = a4gl_htonl (val);
  a = fwrite (&val, 1, sizeof (val), outfile);
  A4GL_debug ("a=%d\n", a);
  return a;
}


/**
 *
 * @todo Describe function
 */
int
//A4GLPacker_output_bool (char *name, short val, int ptr, int isarr)
A4GLPacker_output_bool (char *name, int val, int ptr, int isarr)
{
  return A4GLPacker_output_short (name, val, ptr, isarr);
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_output_string (char *name, char *val, int ptr, int isarr)
{
  int a;
  A4GL_debug ("Output string - length first (%d) pos=%d", strlen (val),
	 ftell (outfile));
  A4GLPacker_output_long (name, strlen (val), ptr, isarr);
  A4GL_debug ("outputing string itself (%s)", val);
  a = fwrite (val, 1, strlen (val), outfile);

  if (strlen (val) == 0)
    a = 1;
  A4GL_debug ("pos now = %d", ftell (outfile));
  return a;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_output_double (char *name, double val, int ptr, int isarr)
{
/*  FIX PORTABILITY.... */
  return fwrite (&val, 1, sizeof (val), outfile);
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_output_start_struct (char *s, char *n, int ptr, int isarr)
{
  A4GL_debug ("Starting struct %s\n", s);
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_output_end_struct (char *s, char *n)
{
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_output_start_union (char *s, char *n, int ptr, int isarr)
{
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_output_nullptr (char *s)
{
  char n = 0;
  return fwrite (&n, 1, sizeof (n), outfile);
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_output_okptr (char *s)
{
  char n = 1;
  return fwrite (&n, 1, sizeof (n), outfile);
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_output_end_union (char *s, char *n)
{
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_output_enum (char *name, char *s, int d)
{
  return A4GLPacker_output_int (name, d, 0, -1);
}


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
  A4GL_debug ("ARRAY %s - Length of array=%d", s, *len);
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
  a = fread (val, 1, sizeof (short), infile);
  *val = a4gl_ntohs (*val);
  return a;

}



/**
 *
 * @todo Describe function
 */
int
A4GLPacker_input_int (char *name, int *val, int ptr, int isarr)
{
  if (sizeof (int) == sizeof (long))
    {
      return A4GLPacker_input_long (name, (long *) val, ptr, isarr);
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
  int a;
  /* long n; */
  a = fread (val, 1, sizeof (long), infile);

  *val = a4gl_ntohl (*val);
  return a>0;
}


int
A4GLPacker_input_char (char *name, char *val, int ptr, int isarr)
{
  int a;
  /* long n; */
  a = fread (val, 1, sizeof (char), infile);
  return a>0;
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

  A4GL_debug ("Inputing string '%s'", name);
//  A4GL_debug ("xxxxxxxxxxxx calling A4GLPacker_input_long()");

  if (!A4GLPacker_input_long ("", &l, 0, -1)) {
//	  A4GL_debug ("wwwwwwwwwwwwwww ZERO!");
	return 0;
  }
  A4GL_debug ("Got length as %d", l);
  *val = malloc (l+1);	/* Extra 1 for the \0 */
  memset(*val,0,l+1);
  a = fread (*val, 1, l, infile);
  if (a == 0 && l == 0)
    return 1;
  return a>0;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_input_double (char *name, double *val, int ptr, int isarr)
{
  int r;
r=fread ((char *)val, 1, sizeof (*val), infile);
if (r<=0) return 0;
else return 1;
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
A4GLPacker_input_start_union (char *s, char *n, int ptr, int isarr)
{
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_input_ptr_ok ()
{
  char n;
  fread (&n, 1, sizeof (n), infile);
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
A4GLPacker_input_end_union (char *s, char *n)
{
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_input_enum (char *name, int *d)
{
  return A4GLPacker_input_int (name, d, 0, -1);
}

/**
 *
 * @todo Describe function
 */
int
//can_pack_all(void)
A4GLPacker_A4GL_can_pack_all (char *name)
{
  return 0;
}


/* ====================================== EOF ============================ */

