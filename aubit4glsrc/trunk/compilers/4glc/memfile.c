
#ifdef MOVED_TO_LIBAUBIT4GL
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
# $Id: memfile.c,v 1.8 2004-01-29 08:33:46 mikeaubury Exp $
#
*/

/**
 * @file
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
#include <stdlib.h>
#include <string.h>
#include "memfile.h"

int opened = 0;
char *buff;
long buff_len;
FILE *in;
long pos = 0;
FILE *A4GL_mja_fopen (char *name, char *mode);


FILE *
A4GL_memfile_fopen (char *f, char *mode)
{

  if (opened > 1)
    {
      printf ("Too many opened!!");
      exit (1);
    }

  if (strchr (mode, 'w'))
    {
      printf ("Can't use memfile for Writing...");
      exit (1);

    }

  opened++;

  in = A4GL_mja_fopen (f, mode);

  if (in == 0)
    return 0;
  else
    {
      fseek (in, 0, SEEK_END);
      buff_len = ftell (in);
      buff = (char *) malloc (buff_len + 1);
      rewind (in);

      if (fread (buff, buff_len, 1, in) != 1)
	{
	  printf ("Unable to read file into buffer\n");
	}
    }

  pos = 0;
  return in;
}



int
A4GL_memfile_fseek (FILE * f, long offset, int whence)
{
  if (f != in)
    {
      return fseek (f, offset, whence);
    }
  else
    {
      if (whence == SEEK_SET)
	{
	  pos = offset;
	  return 0;
	}
      if (whence == SEEK_END)
	{
	  pos = buff_len - offset;
	  return 0;
	}
      if (whence == SEEK_CUR)
	{
	  pos += offset;
	  return 0;
	}
    }
  return 1;
}


int
A4GL_memfile_getc (FILE * f)
{
  int a;
  if (f != in)
    {
      return getc (f);
    }
  else
    {
      a = buff[pos];
      pos++;
      return a;
    }
}


void
A4GL_memfile_fclose (FILE * f)
{
  if (f != in)
    {
      fclose (f);
    }
  else
    {
      opened--;
      free (buff);
    }
}

void
A4GL_memfile_rewind (FILE * f)
{
  if (f != in)
    {
      rewind (f);
    }
  else
    {
      pos = 0;
    }
}

long
A4GL_memfile_ftell (FILE * f)
{
  if (f != in)
    {
      return ftell (f);
    }
  else
    {
      return pos;
    }
}

int
A4GL_memfile_ungetc (int c, FILE * f)
{
  if (f != in)
    {
      return ungetc (c, f);
    }
  else
    {
      pos--;
    }
  return 0;
}

int
A4GL_memfile_feof (FILE * f)
{
  char buffer[255];
  if (f != in)
    {
      A4GL_debug ("pos = %ld buff_len = %ld f=%x in=%x\n", pos, buff_len, f, in);
      strncpy (buffer, &buff[pos], 255);
      buff[255] = 0;
      a4gl_yyerror
	("Something horrible has gone wrong in the compiler - set DEBUG=ALL, retry and check debug.out");
      return feof (f);
    }
  else
    {
      /*printf("pos = %d buff_len = %d f=%x in=%x\n",pos,buff_len,f,in);*/
      return pos > buff_len;
    }
}

int
A4GL_memfile_fread (char *ptr, int s, int n, FILE * f)
{
  if (f != in)
    {
      return fread (ptr, s, n, f);
    }
  else
    {
      memcpy (ptr, &buff[pos], s * n);
      pos += s * n;
      return 0;
    }
}


void A4GL_remove_comments_in_memfile(FILE *f) {
int a;
int b;
int type=0;


  if (f != in)
    {
      A4GL_debug ("pos = %ld buff_len = %ld f=%x in=%x\n", pos, buff_len, f, in);
      strncpy (buffer, &buff[pos], 255);
      buff[255] = 0;
      a4gl_yyerror
        ("Something horrible has gone wrong in the compiler - set DEBUG=ALL, retry and check debug.out");
      return feof (f);
    }


    for (a=0;a<buff_len;a++) {
	if (strncmp(&buff[a],"\ncode\n",6)==0) type+=1;
	if (strncmp(&buff[a],"\r\ncode\r\n",8)==0) type+=1;
	if (strncmp(&buff[a],"\nendcode\n",9)==0) type-=1;
	if (strncmp(&buff[a],"\r\nendcode\r\n",11)==0) type-=1;

	if (buff[a]=='"'&&buff[a-1]!='\\') {
		 if (type&2) type-=2;
		 else type+=2;
	}


	if (buff[a]=='\''&&buff[a-1]!='\\') {
		 if (type&4) type-=4;
		 else type+=4;
	}


	if (buff[a]=='{'&&type==0) {
		for (b=a;buff[b]!='}';b++) buff[b]=' ';
		a=b;
		continue;
	}

	if (buff[a]=='-'&&buff[a+1]=='-'&&type==0) {
		for (b=a;buff[b]!='\n';b++) buff[b]=' ';
		a=b;
		continue;
	}

	if (buff[a]=='#'&&type==0) {
		for (b=a;buff[b]!='\n';b++) buff[b]=' ';
		a=b;
		continue;
	}

    }

}

#endif



