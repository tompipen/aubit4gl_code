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
# $Id: io.c,v 1.5 2002-05-30 06:25:19 afalout Exp $
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

#include <stdio.h>

#include "a4gl_dbform.h"
#include "a4gl_tunable.h"
#include "a4gl_aubit_lib.h"     //acl_getenv()
#include "a4gl_debug.h"


/*
=====================================================================
                    Variables definitions
=====================================================================
*/

FILE *oufile=0;

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
 * Read an int from a file.
 *
 * @param ofile Pointer to the file to be readed. If 0 use global oufile.
 * @return The int readed.
 */
int 
read_int (FILE * ofile)
{

//    unsigned char c;
    int a;
//    int f;
//    short sa;
	if (ofile==0) ofile=oufile;
    fread (&a, 1, sizeof (int), ofile);
    //a=(int)sa;
debug("read_int returns %d",a);
    return a;

}

/**
 * Write an int to a file.
 *
 * @param ofile A pointer to the opened file. If 0 use oufile.
 * @param la The integer to be writed in the file.
 */
void
write_int (FILE * ofile, int la)
{
//    short a;
//    unsigned char c;
	static int locala;
	int sizeo;
	if (ofile==0) ofile=oufile;
	debug("File=%p",ofile);
	debug("&locala=%p",&locala);
	sizeo=sizeof(locala);
	locala=la;

    fwrite (&locala,sizeo,1, ofile);
}

/**
 * @todo : Remove if not used.
 * @deprecated Not used anywhere.
 */
/*
int
form_out_open(char *fname)
{
	oufile=mja_fopen(fname,"wb");
	if (oufile==0) return 0;
	else return 1;
}
*/

/**
 * @todo : Remove if not used.
 * @deprecated Not used anywhere.
 */
/*
FILE *
form_out_file()
{
	return oufile;
}
*/

/**
 * @todo : Remove if not used.
 * @deprecated Not used anywhere.
 */
/*
void
form_out_close()
{
	fclose(oufile);
}
*/

/**
 * @todo : Remove if not used.
 * @deprecated Not used anywhere.
 */
/*
read_hasmore (FILE * ofile)
{
  if (ofile==0) ofile=oufile;
    return read_int (ofile);

}
*/

/**
 * @todo : Remove if not used.
 * @deprecated Not used anywhere.
 */
/*
write_hasmore (FILE * ofile)
{
  if (ofile==0) ofile=oufile;
    write_int (ofile, 255);

}
*/

/**
 * @todo : Remove if not used.
 * @deprecated Not used anywhere.
 */
/*
write_nomore (FILE * ofile)
{
  if (ofile==0) ofile=oufile;
    write_int (ofile, 0);

}
*/

/**
 * @todo : Remove if not used.
 * @deprecated Not used anywhere.
 */
/*
char *
read_string_dup (FILE * ofile)
{
    int c;

    char *a;
  if (ofile==0) ofile=oufile;
    c = read_int (ofile);

    if (c == 0)
    {
	a = 0;

	return 0;
    }

    a = (char *) acl_malloc (c + 1,"Read string dup");
    fread (a, 1, c, ofile);
    return a;
}
*/

/**
 * @todo : Remove if not used.
 * @deprecated Not used anywhere.
 */
/*
read_string (FILE * ofile, char *a)
{

    int c;
  if (ofile==0) ofile=oufile;
    c = read_int (ofile);

    if (c == 0)
    {

	a[0] = 0;

	return;

    }

    fread (a, 1, c, ofile);

}
*/

/**
 * @todo : Remove if not used.
 * @deprecated Not used anywhere.
 */
/*
write_string (FILE * ofile, char *a)
{

    int c;
if (ofile==0) ofile=oufile;

    if (a == 0 || a[0] == 0)
    {

	write_int (ofile, 0);

	return;

    }

    c = strlen (a) + 1;		//include 0x0

    write_int (ofile, c);	//store length first

  //fwrite(&c,1,1,ofile);
    fwrite (a, 1, strlen (a) + 1, ofile);

}
*/

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
bname (char *str, char *str1, char *str2)
{
  
    static char fn[FNAMESIZE];
  
    int a;
  
    char *ptr;
  
    strcpy (fn, str);
  
    for (a = strlen (fn); a >= 0; a--)
    {
      
	if (fn[a] == '.')
	{
	  
	    fn[a] = 0;
	  
	    break;
	  
	}
      
    }
  
    ptr = &fn[a];
  
    strcpy (str1, fn);
  
    if (a > 0)
    {
      
	strcpy (str2, ptr + 1);
      
    }
  else
    {
      
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
try_to_open(char *path,char *name,int keepopen)
{
  char buff[2048];
  FILE *f;

  #ifndef WIN32
  sprintf(buff,"%s/%s",path,name);
  #else
  sprintf(buff,"%s\\%s",path,name);
  #endif
  debug("Opening path '%s'",buff);
  if (strlen(name)==0) return 0;

  /* Does it exist and can we read it ? */
  f=fopen(buff,"r");
  if (f==0) return (FILE *)0;
  
  if (!keepopen)  {  /* We just wanted to check.. */
	  fclose(f);
	  return (FILE *)1;
  }
  debug("opened file %s in path %s",name,path);
  return f; /* We want it opened.. */
}

/**
 * Open a file from the DBPATH (always for reading...)
 *
 * @param fname The pointer to the filename to be opened.
 * @return The pointer to the file opened. 0 otherwise.
 */
FILE *
open_file_dbpath(char *fname)
{
  char str_path[2048];
  int cnt;
  char *ptr;
  int str_len;
  memset(str_path,0,2048);

  if (try_to_open(".",fname,0)) {
	  return try_to_open(".",fname,1);
  }

  if (strlen(acl_getenv("DBPATH"))) {
	strcpy(str_path,acl_getenv("DBPATH"));
  }

  str_len=strlen(str_path);
  ptr=str_path;

  for (cnt=0;cnt<str_len;cnt++) {
	if (str_path[cnt]==':') {
		str_path[cnt]=0;
		if (strlen(ptr)) {
			if (try_to_open(ptr,fname,0)) {
				return try_to_open(ptr,fname,1);
			} else {
				cnt++;
				ptr=&str_path[cnt];
			}
		}
	}
  }

  if (strlen(ptr)) {
	if (try_to_open(ptr,fname,0)) {
		return try_to_open(ptr,fname,1);
	} 
  }

  return (FILE *)0;
}


// ============================= EOF ===============================
