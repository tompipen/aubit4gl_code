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
# $Id: io.c,v 1.18 2004-02-22 02:29:00 afalout Exp $
#
*/

/**
 * @file
 * File IO functions, for reading forms, etc
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_libaubit4gl_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

FILE *oufile = 0;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

int A4GL_read_int (FILE * ofile);
void A4GL_write_int (FILE * ofile, int la);
FILE *A4GL_try_to_open (char *path, char *name, int keepopen);


/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 * Read an int from a file.
 *
 * @param ofile Pointer to the file to be readed. If 0 use global oufile.
 * @return The int readed.
 */
int
A4GL_read_int (FILE * ofile)
{
  int a;

  if (ofile == 0)
    ofile = oufile;
  fread (&a, 1, sizeof (int), ofile);
  /* a=(int)sa; */
  A4GL_debug ("read_int returns %d", a);
  return a;

}

/**
 * Write an int to a file.
 *
 * @param ofile A pointer to the opened file. If 0 use oufile.
 * @param la The integer to be writed in the file.
 */
void
A4GL_write_int (FILE * ofile, int la)
{
  static int locala;
  int sizeo;

  if (ofile == 0)
    ofile = oufile;
  A4GL_debug ("File=%p", ofile);
  A4GL_debug ("&locala=%p", &locala);
  sizeo = sizeof (locala);
  locala = la;

  fwrite (&locala, sizeo, 1, ofile);
}


/**
 * Breaks the file name to take the file name without extension and dir name
 *
 * Its used to separate column names from tablename too.
 *
 * This function is repeated in severall places.
 * @todo : Merge all this functions to the lib.
 *
 * @param str The file name 
 * @param str1 A pointer to the place where to return the left part.
 * @param str2 A pointer to the place where to return the right part.
 */
void
A4GL_bname (char *str, char *str1, char *str2)
{
static char fn[FNAMESIZE];
int a;
char *ptr;

  strcpy (fn, str);

  for (a = strlen (fn); a >= 0; a--) {
      if (fn[a] == '.'){
		fn[a] = 0;
		break;
	  }
  }

  ptr = &fn[a];
  strcpy (str1, fn);

  if (a > 0){
      strcpy (str2, ptr + 1);
  } else {
      strcpy (str2, fn);
      strcpy (str1, "");
  }
}


/**
 * Try to open a file.
 *
 * @param path The directory name.
 * @param name The file name
 * @param keepopen Flag that indicate if we just want to see if can be opened:
 *   - 0 : Close the file
 *   - Otherwise : Keep the file opened and return the File pointer.
 * @return The pointer of the file opened.
 */
FILE *
A4GL_try_to_open (char *path, char *name, int keepopen)
{
char buff[2048];
FILE *f;

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
		return (FILE *) 0;
	}
	if (!keepopen) {				/* We just wanted to check.. */
	  fclose (f);
	  return (FILE *) 1;
	}
	A4GL_debug ("opened file %s in path %s", name, path);
	return f;			/* We want it opened.. */
}

/**
 * Open a file from the DBPATH (always for reading...)
 *
 * @param fname The pointer to the filename to be opened.
 * @return The pointer to the file opened. 0 otherwise.
 */
FILE *
A4GL_open_file_dbpath (char *fname)
{
char str_path[2048];
int cnt;
char *ptr;
int str_len;

	memset (str_path, 0, 2048);

	if (A4GL_try_to_open ("", fname, 0)) {
		return A4GL_try_to_open ("", fname, 1);
    }

	if (A4GL_try_to_open (".", fname, 0)) {
		return A4GL_try_to_open (".", fname, 1);
	}

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
					if (A4GL_try_to_open (ptr, fname, 0)) {
						return A4GL_try_to_open (ptr, fname, 1);
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
		if (A4GL_try_to_open (ptr, fname, 0)) {
			return A4GL_try_to_open (ptr, fname, 1);
        }
	}

	return (FILE *) 0;
}

/**
 * Find a full path to file in DBPATH, or current directory
 *
 * @param fname The pointer to the name of the file to searched for.
 * @return The pointer to the full path including the file name and extension
 *         to file found in DBPATH. 0 otherwise.
 */
char *
A4GL_fullpath_dbpath (char *fname)
{
char str_path[2048],str_path2[2048];
int cnt, cnt2;
char *ptr=0;
char *ptr2=0;
int str_len; //, curr_str_len;
char *dbpath;

	memset (str_path, 0, 2048);
	memset (str_path2, 0, 2048);

	if (A4GL_try_to_open ("", fname, 0) ) {
		return fname;
    }

	if (A4GL_try_to_open (".", fname, 0)) {
		strcpy(ptr2,"./");
		strcat(ptr2,fname);
		return ptr2;
    }

	dbpath=acl_getenv ("DBPATH");

	if (dbpath!=0) {
		if (strlen (dbpath)) 
		{
			strcpy (str_path, dbpath);
		} else {
			strcpy(str_path,"");
		}
	}

	str_len = strlen (str_path);
	ptr = str_path;

	A4GL_debug ("ptr DBPATH='%s'",ptr);

	for (cnt = 0; cnt < str_len; cnt++) {

		#ifdef __MINGW32__
	    if (str_path[cnt] == ';') {
		#else
	    if (str_path[cnt] == ':') {
		#endif
			A4GL_debug ("Found separator at %d",cnt);
            str_path[cnt] = 0;
            if (strlen (ptr)) {
                //A4GL_debug ("strlen (ptr) > 0, ptr=%s",ptr);
				strcpy (str_path2, ptr);
                //A4GL_debug ("str_path2=%s",str_path2);
				// Let's assume no-one will stuff DBPATH with more then 5
				// consecutive separators... :-)
				for (cnt2 = 0; cnt2 < 5; cnt2++) {
					#ifdef __MINGW32__
					if (str_path2[cnt2] == ';') {
		            #else
		            if (str_path2[cnt2] == ':') {
		            #endif
						A4GL_debug ("Skipping one more separator");
						ptr = &str_path2[cnt2+1];
					} else {
						break;
		            }
		        }

                //A4GL_debug ("strlen (ptr) > 0, ptr=%s",ptr);

				if (A4GL_try_to_open (ptr, fname, 0)) {
                    ptr2=malloc(strlen(ptr)+2+strlen(fname));
					strcpy(ptr2,ptr);
                    strcat(ptr2,"/");
                    strcat(ptr2,fname);
                    return ptr2;
                } else {
                    cnt++;
                    ptr = &str_path[cnt];
                }
            } else {
                //A4GL_debug ("strlen (ptr) = 0");
				cnt++;
				ptr = &str_path[cnt];
            }
		}
	}

	//catch cases when DBPATH contained only one path and no separator:
	if (strlen (ptr)) {
		A4GL_debug ("One last time...");
		if (A4GL_try_to_open (ptr, fname, 0)) {
			ptr2=strdup(ptr);
			//#ifdef __MINGW32__
		  	//	strcat(ptr2,"\\");
			//#else
				strcat(ptr2,"/");
			//#endif
			strcat(ptr2,fname);
			return ptr2;
		}
    }

	return (char *) 0;
}


/* ============================= EOF =============================== */
