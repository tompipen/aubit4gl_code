
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
# $Id: gzhelper.c,v 1.1 2006-09-01 19:35:11 mikeaubury Exp $
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

