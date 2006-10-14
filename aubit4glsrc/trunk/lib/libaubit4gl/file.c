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
# $Id: file.c,v 1.2 2006-10-14 10:09:39 mikeaubury Exp $
#
*/


#include "a4gl_libaubit4gl_int.h"

#ifdef HAVE_SYS_STAT_H
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#endif

#define USE_RENAME  1


int
A4GL_copy_file (char *from, char *to)
{
  FILE *d;
  FILE *s;
  char get;
      s=fopen(from,"r");
      if (s==0) return 0;
      d = fopen (to, "w+");
      if (d==0) {
	      fclose(s);
	      return 0;
	      	}
      do
	{
	  get = fgetc (s);
	  if (get == EOF)
	    {
	      break;
	    }
	  fputc (get, d);
	}
      while (get != EOF);

      fclose (s);
      fclose (d);
return 1;
}


int A4GL_file_length(char *fname) {
FILE *f;
long len;
	f=fopen(fname,"r");
	if (f==0) return -1;
	/* The 'proper' way to do it is with 'stat' - but this isn't
	   too portable (even though it should be). */
	fseek(f,0,SEEK_END);
	len=ftell(f);
	fclose(f);
return len;
}

int A4GL_move_file(char *from,char *to) {
#if USE_RENAME
	if (unlink(to)!=0) return 0;
	rename(from,to);
#else
	if (unlink(to)!=0) return 0;
	if (!A4GL_copy_file(from,to)) return 0;
	if (unlink(from)!=0) return 0;
#endif
	return 1;
}


int A4GL_delete_file(char *fname) {
	if (unlink(fname)==0) return 1;
	return 0;
}


int A4GL_file_exists(char *fname) {
FILE *f=0;
#ifdef HAVE_SYS_STAT_H
struct stat buf;

 if (stat(fname, &buf)==0) return 1;
 return 0;
#else
f=fopen(fname,"r");
if (f) {
	fclose(f); return 1;
} else {
	return 0;

#endif
}
