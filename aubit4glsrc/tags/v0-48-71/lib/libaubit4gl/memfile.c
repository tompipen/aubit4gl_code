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
# $Id: memfile.c,v 1.20 2004-09-28 08:58:54 mikeaubury Exp $
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
#include "a4gl_libaubit4gl_int.h"

// Not needed - all already in a4gl_libaubit4gl.h :
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

void A4GL_remove_comments_in_memfile(FILE *f) ;

//#include "memfile.h"  // why is this not in "a4gl_libaubit4gl_int.h" ?

int opened = 0;
static char *buff;
long buff_len;
FILE *in;
long pos = 0;
//FILE *A4GL_mja_fopen (char *name, char *mode);

void A4GL_dump_buffer (char *s, int l);
FILE *
A4GL_memfile_fopen_buffer (char *ptr, int len);

FILE *
A4GL_memfile_fopen (char *f, char *mode)
{

  if (opened > 1)
    {
      printf ("Too many opened!!");
      exit (1);
    }

  if (a_strchr (mode, 'w'))
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
      buff = (char *) malloc (buff_len + 10);
      //memset(buff,0,buff_len+10);
	buff[buff_len]=0;
      rewind (in);
      if (buff_len!=0) {
      	if (fread (buff, buff_len, 1, in) != 1)
	{
	  printf ("Unable to read file into buffer\n");
	  //FIXME - use exit_with()
	  exit (1);
 
	}
	}
    }

  pos = 0;
  return in;
}

void *
A4GL_memdup (void *ptr, int size)
{
  void *p2;
  p2 = malloc (size);
  memcpy (p2, ptr, size);
  return p2;
}


FILE *
A4GL_memfile_fopen_buffer (char *ptr, int len)
{
  pos = 0;
  if (len == -1)
    {
      int l;
      int c1;
      int c2;
      int c3;
      int c4;
      c1 = ((unsigned char) ptr[0]) & 0xff;
      c2 = ((unsigned char) ptr[1]) & 0xff;
      c3 = ((unsigned char) ptr[2]) & 0xff;
      c4 = ((unsigned char) ptr[3]) & 0xff;
      //debug("size=%d %d %d %d",c1,c2,c3,c4);
      l = c4;
      l = l * 256 + c3;
      l = l * 256 + c2;
      l = l * 256 + c1;
      len = l;
      ptr += 4;
    }
  //debug("open_packer - length=%d",len);
  buff_len = len;
  buff = A4GL_memdup (ptr, len);
  A4GL_dump_buffer (ptr, 30);
  in = (FILE *) buff;
  return (FILE *) buff;
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
      if (pos>buff_len) {
		printf("XXX");
		return 0;
	}
      a = buff[pos];
      pos++;
      return a;
    }
return 0;
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
      //debug("pos = %ld buff_len = %ld f=%x in=%x\n",pos,buff_len,f,in);
      strncpy (buffer, &buff[pos], 255);
      buff[255] = 0;
      A4GL_debug
	("Something horrible has gone wrong in the compiler - set DEBUG=ALL, retry and check debug.out");
      printf
	("Something horrible has gone wrong in the compiler - set DEBUG=ALL, retry and check debug.out");
      exit (2);
      return feof (f);
    }
  else
    {
      //printf("pos = %d buff_len = %d f=%x in=%x\n",pos,buff_len,f,in);
      return pos > buff_len;
    }
}

int
A4GL_memfile_fread (char *ptr, int s, int n, FILE * f)
{
  if (f != in)
    {
      A4GL_debug ("Reading from fread with a file...This is bad!!!");
      return fread (ptr, s, n, f);
    }
  else
    {
      int a;
      //debug("Reading from buff start@:%d s=%d n=%d",pos,s,n);
      memcpy (ptr, &buff[pos], s * n);
      for (a = 0; a < s * n; a++)
	{
	  //debug("%02x: %c",
	  //ptr[a]&0xff,
	  //isprint(ptr[a]&0xff)?ptr[a]&0xff:'.'
	  //);
	}

      //debug("And from pos:");
      for (a = 0; a < s * n; a++)
	{
	  //debug("%02x: %c",
	  //buff[pos+a]&0xff,
	  //isprint(buff[pos+a]&0xff)?buff[pos+a]&0xff:'.'
	  //);
	}

      pos += s * n;
      //debug("Reading from buff pos now %d",pos);
      return n;
    }
}

void
A4GL_dump_buffer (char *s, int l)
{
  int a;
  char buff[256];
  char buffx[256];
  strcpy (buff, "");
  return;
  A4GL_debug ("Dump buffer");
  for (a = 0; a < l; a++)
    {
      sprintf (buffx, "0x%02x,", s[a] & 0xff);
      strcat (buff, buffx);
      if (strlen (buff) >= 80)
	{
	  strcat (buff, ":");
	  A4GL_debug ("%s", buff);
	  strcpy (buff, "");
	}
    }
  A4GL_debug ("%s", buff);
}



void A4GL_remove_comments_in_memfile(FILE *f) {
int a;
int b;
int type=0;
FILE *last;

  if (!A4GL_isyes(acl_getenv("RM_COMMENTS_FIRST"))) return;

  if (f != in)
    {
      A4GL_debug ("pos = %ld buff_len = %ld f=%x in=%x\n", pos, buff_len, f, in);
      //a4gl_yyerror ("Something horrible has gone wrong in the compiler - set DEBUG=ALL, retry and check debug.out");
      return ;
    }


    for (a=0;a<buff_len;a++) {

	if (buff[a]=='\n'&&type!=1) type=0; 	// newlines always reset everything.
					// That way - if we get confused - it won't propagate too far..
					//

        if (strncmp(&buff[a],"\ncode\n",6)==0) {
			type+=1;
	}
        if (strncmp(&buff[a],"\r\ncode\r\n",8)==0) {
		type+=1;
	}
        if (strncmp(&buff[a],"\nendcode\n",9)==0) {
		type-=1;
	}
        if (strncmp(&buff[a],"\r\nendcode\r\n",11)==0) {
		type-=1;
	}

        if (buff[a]=='"'&&buff[a-1]!='\\'&&(type==0||type==2)) {
                 if (type&2) type-=2;
                 else type+=2;
        }

        if (buff[a]=='\''&&buff[a-1]!='\\'&&(type==0||type==4)) {
                 if (type&4) type-=4;
                 else type+=4;
        }

	//printf("%x%c",type,buff[a]);

        if (buff[a]=='-'&&buff[a+1]=='-'&&type==0) {
		if (buff[a+2]!='!') {
                	for (b=a;buff[b]!='\n'&&b<buff_len;b++) {
				buff[b]=' ';
			}
                	a=b-1;
                	continue;
		} else {
			buff[a]=' ';
			buff[a+1]=' ';
			buff[a+2]=' ';
		}
        }

        if (buff[a]=='#'&&type==0) {
		//printf("Found #\n");
                for (b=a;buff[b]!='\n'&&b<buff_len;b++) {
			//printf("Skipping... '%c'\n",buff[b]);
			buff[b]=' ';
		}
                a=b-1;
                continue;
        }
        if (buff[a]=='{'&&type==0&&buff[a+1]!='!') {
                for (b=a;buff[b]!='}'&&b<buff_len;b++) {
			if (buff[b]=='\n') continue;
			buff[b]=' ';
		}
		buff[b]=' ';
                a=b-1;
                continue;
        }


        if (buff[a]=='{'&&type==0&&buff[a+1]=='!') {
		buff[a]=' ';
		buff[a+1]=' ';
                for (b=a;buff[b]!='!'&&buff[b+1]!='}'&&b<buff_len;b++) {
			if (buff[b]=='\n') continue;
		}
		buff[b]=' ';
		buff[b+1]=' ';
                a=b-1;
                continue;
        }





    }

    if (A4GL_isyes(acl_getenv("A4GL_DUMP_LAST"))) {
	last=fopen("last","w");
	fwrite(buff,1,buff_len,last);
	fclose(last);
    }
}

