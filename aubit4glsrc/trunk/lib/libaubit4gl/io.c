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
# $Id: io.c,v 1.29 2005-03-09 15:14:39 mikeaubury Exp $
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
char *A4GL_fullpath_classpath (char *fname) ;
static char * A4GL_fullpath_xpath (char *fname,char *path);
//FILE * A4GL_open_file_classpath (char *fname);


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

strcpy(str1,"");
strcpy(str2,"");
  strcpy (fn, str);

  for (a = strlen (fn); a >= 0; a--) {
      if (fn[a] == '.'){
		fn[a] = 0;
		break;
	  }
      if (fn[a]=='/') {a=0;break;}
	
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
	//A4GL_debug("A4GL_try_to_open() path=%s name=%s",path,name);
	if (strlen (name) == 0)
		return 0;

	if (strlen (path)) {
		//Forward slash should work on Windows just fine...
		//#ifndef WIN32 - we need __MINGW32__ or __CYGWIN__
	      sprintf (buff, "%s/%s", path, name);
		//#else
		//  sprintf (buff, "%s\\%s", path, name);
		//#endif
    } else {
		sprintf (buff, name);
    }

	//A4GL_debug ("Opening path '%s'", buff);
	
	//FIXME: apparently does not wok with relative paths?
	
	/*
    Shuld we open files in binary mode instead?
		f = fopen (buff, "rb");
	I was trying this because PACKED packer does not work on Windows, 
	but XML packer does - did not help (try test #242)
	*/

	/* Does it exist and can we read it ? */
	f = fopen (buff, "rb");
	if (f == 0) {
		A4GL_debug("Cant open '%s'",buff);
		return (FILE *) 0;
	}
	A4GL_debug("Opened '%s'",buff);	
	if (!keepopen) {				/* We just wanted to check.. */
		fclose (f);
		A4GL_debug("...and closed it");
		return (FILE *) 1;
	}
	return f;			/* We want it opened.. */
}

/**
 * Open a file from the DBPATH (always for reading)
 *
 * @param fname The pointer to the filename to be opened.
 * @return The pointer to the file opened. 0 otherwise.
 */
FILE *
A4GL_open_file_dbpath (char *fname)
{
char *ptr;
	ptr=A4GL_fullpath_dbpath(fname);
	if (ptr==0) return 0;
	return A4GL_try_to_open("",ptr,1);
}

/**
 * 
 *
 * @param fname The pointer to the filename to be
 * @return 
 */
char *
A4GL_fullpath_dbpath (char *fname) {
	return A4GL_fullpath_xpath(fname,acl_getenv("DBPATH"));
}
	
FILE * A4GL_open_file_classpath (char *fname)
{
char *ptr;
	ptr=A4GL_fullpath_classpath(fname);
	if (ptr==0) return 0;
	return A4GL_try_to_open("",ptr,1);
}


char *A4GL_fullpath_classpath (char *fname) {
char buff[1024];
	//#ifdef _WIN32_ 4444444
	#if ((defined __WIN32__ ) && (! defined __CYGWIN__))
		//note that CygWin (which alos have _WIN32_ defined needs 
		//unix-like paths
		if (strlen(acl_getenv("A4GL_CLASSPATH"))) {
			sprintf(buff,"%s;%s/etc/import;%s/import",
				acl_getenv("A4GL_CLASSPATH"),acl_getenv("AUBITDIR"),
				acl_getenv("AUBITETC"));
		} else {
			sprintf(buff,"%s/etc/import;%s/import",
				acl_getenv("AUBITDIR"),acl_getenv("AUBITETC"));
		}
	#else
		if (strlen(acl_getenv("A4GL_CLASSPATH"))) {
			sprintf(buff,"%s:%s/etc/import:%s/import",
				acl_getenv("A4GL_CLASSPATH"),acl_getenv("AUBITDIR"),
				acl_getenv("AUBITETC"));
		} else {
			sprintf(buff,"%s/etc/import:%s/import",
			acl_getenv("AUBITDIR"),acl_getenv("AUBITETC"));
		}
	#endif
	A4GL_debug("A4GL_fullpath_classpath:%s %s",fname,buff);
	return A4GL_fullpath_xpath(fname,buff);
}



/**
 * Find a full path to file in DBPATH, or current directory
 *
 * @param fname The pointer to the name of the file to searched for.
 * @return The pointer to the full path including the file name and extension
 *         to file found in DBPATH. 0 otherwise.
 */
static char *
A4GL_fullpath_xpath (char *fname, char *path)
{
  static char str_path[2048], str_path2[2048];
  int cnt, cnt2;
  char *ptr = 0;
  char *ptr2 = 0;
  int str_len;			//, curr_str_len;

  	memset (str_path, 0, 2048);
  	memset (str_path2, 0, 2048);

	if (A4GL_try_to_open ("", fname, 0)) {
		return fname;
    }
	//Are not this two (above and below) efectively the same?
	//is it not a 'filename' always same as './filename' when trying to 
	//open file for writing or reading?
	if (A4GL_try_to_open (".", fname, 0)) {
		strcpy (ptr2, "./");
		strcat (ptr2, fname);
		return ptr2;
    }

	if (path != 0) {
		if (strlen (path)) {
			strcpy (str_path, path);
		} else {
			strcpy (str_path, "");
		}
    }

	str_len = strlen (str_path);
	ptr = str_path;

	A4GL_debug ("ptr path='%s'", ptr);

	for (cnt = 0; cnt < str_len; cnt++)  {
		#ifdef __MINGW32__
			if (str_path[cnt] == ';') {
		#else
			if (str_path[cnt] == ':') {
		#endif
		A4GL_debug ("Found separator at %d", cnt);
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
						ptr = &str_path2[cnt2 + 1];
					} else {
						break;
					}
				}

				//A4GL_debug ("strlen (ptr) > 0, ptr=%s",ptr);

				if (A4GL_try_to_open (ptr, fname, 0))	{
					//printf("ptr=%s\n",ptr);
					sprintf(str_path,"%s/%s",ptr,fname);
					return str_path;
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
			sprintf(str_path,"%s/%s",ptr,fname);
			return str_path;
		}
    }

	return (char *) 0;
	
}

/* ============================= EOF =============================== */
