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
# $Id: memfile.c,v 1.36 2008-01-27 15:15:18 mikeaubury Exp $
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
static long buff_len;
static FILE *in;
static long pos = 0;
//static void reload_comments(void) ;
//FILE *A4GL_mja_fopen (char *name, char *mode);

void A4GL_dump_buffer (char *s, int l);
static void add_comment(int n,int c, char *s,char type) ;


FILE *
A4GL_memfile_fopen (char *f, char *mode)
{

  if (opened > 1)
    {
      PRINTF ("Too many opened!!");
      A4GL_fgl_die (1);
    }

  if (a_strchr (mode, 'w'))
    {
      PRINTF ("Can't use memfile for Writing...");
      A4GL_fgl_die (1);

    }

  opened++;

  in = A4GL_mja_fopen (f, mode);

  if (in == 0)
    return 0;
  else
    {
      fseek (in, 0, SEEK_END);
      buff_len = ftell (in);
      buff = (char *) acl_malloc2 (buff_len + 10);
      //memset(buff,0,buff_len+10);
	buff[buff_len]=0;
      rewind (in);
      if (buff_len!=0) {
      	if (fread (buff, buff_len, 1, in) != 1)
	{
	  PRINTF ("Unable to read file into buffer\n");
	  //FIXME - use exit_with()
	  A4GL_fgl_die (1);
 
	}
	}
    }

while (1) {
	char *ptr;
	// convert any ^m to whitespace.
	ptr=strchr(buff,13);
	if (ptr==0) break;
	*ptr=' ';
}


  pos = 0;
  return in;
}

void *
A4GL_memdup (void *ptr, int size)
{
  void *p2;

  A4GL_assertion(ptr==0,"No pointer to copy");
  A4GL_assertion(size<=0,"Invalid side for memdup");

  A4GL_debug("A4GL_memdup - ptr=%p size=%p",ptr,size);
  p2 = acl_malloc2 (size);
  memcpy (p2, ptr, size);
  A4GL_debug("Done");
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


static void A4GL_trimnl(char *s) {
int a;
for (a=strlen(s)-1;a>=0;a--) {
	if (s[a]=='\n') {s[a]=0; continue;}
	if (s[a]=='\r') {s[a]=0; continue;}
	break;

}
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
      PRINTF
	("Something horrible has gone wrong in the compiler - set DEBUG=ALL, retry and check debug.out");
      A4GL_fgl_die (2);
      return feof (f);
    }
  else
    {
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
      SPRINTF1 (buffx, "0x%02x,", s[a] & 0xff);
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



struct s_comments {
	int lineno;
	int colno;
	char *comment;
	int printed;
	int type;
};


struct s_comments *load_comments=0;
int ncomments=0;



void A4GL_remove_comments_in_memfile(FILE *f) {
int a;
int b;
int type=0;
FILE *last;
//FILE *save_comment=0;
//char *save=0;
static int lineno=1;
char cmbuff[20000];
int cmcnt=0;
int colno=0;

/*
  save=acl_getenv("SAVE_COMMENTS");

  if (save) {
	if (strlen(save)) {
		save_comment=fopen(save,"w");
	}
  }
*/

  if (!A4GL_isyes(acl_getenv("RM_COMMENTS_FIRST"))) {
		//printf("Not removing comments!");
		return;
	}

  if (f != in)
    {
      A4GL_debug ("pos = %ld buff_len = %ld f=%x in=%x\n", pos, buff_len, f, in);
      //a4gl_yyerror ("Something horrible has gone wrong in the compiler - set DEBUG=ALL, retry and check debug.out");
      return ;
    }


    for (a=0;a<buff_len;a++) {
	if (buff[a]=='\n') {lineno++; colno=0;}
	colno++;

	if (buff[a]=='\n'&&type!=1) type=0; 	// newlines always reset everything.
					// That way - if we get confused - it won't propagate too far..
					//
        if (strncmp(&buff[a],"code\n",5)==0 && a==0) {
			type+=1;
	}

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


        if (buff[a]=='-'&&buff[a+1]=='-'&&type==0) {
		int no_comment_char=0;

		if (no_comment_char==0) {
			if (A4GL_isyes(acl_getenv("HASHNOCOMMENT"))) {
				no_comment_char='#'; // some 'other' non-comment character...
			} else {
				no_comment_char='!'; // aubit non-comment character...
			}
		}

		if (buff[a+2]!=no_comment_char) {

			cmcnt=0;
                	for (b=a;buff[b]!='\n'&&b<buff_len;b++) {

				if (b>a+1) {
					cmbuff[cmcnt++]=buff[b];
				}
				buff[b]=' ';
			}
			cmbuff[cmcnt]=0;
			add_comment(lineno,colno,cmbuff,'-');
                	a=b-1;
			colno=0;
                	continue;
		} else {
			buff[a]=' ';
			buff[a+1]=' ';
			buff[a+2]=' ';
		}
        }

        if (buff[a]=='#'&&type==0) {
		cmcnt=0;
                for (b=a;buff[b]!='\n'&&b<buff_len;b++) {
			if (b>a) {
				cmbuff[cmcnt++]=buff[b];
			}

			buff[b]=' ';
		}
		cmbuff[cmcnt]=0;
		add_comment(lineno,colno,cmbuff,'#');
		colno=0;
		
                a=b-1;
                continue;
        }

        if (buff[a]=='{'&&type==0&&buff[a+1]!='!') {
		char pr='{';
		cmcnt=0;
                for (b=a;buff[b]!='}'&&b<buff_len;b++) {
			colno++;
			if (buff[b]=='\n') {
				cmbuff[cmcnt]=0;
				add_comment(lineno, colno,cmbuff,pr);
				pr='.';
				cmcnt=0;
				colno=0;
				lineno++;
				continue;
			}
			if (b!=a) {
			cmbuff[cmcnt++]=buff[b];
			}
			buff[b]=' ';
		}
		cmbuff[cmcnt]=0;
		if (strlen(cmbuff)) {
				add_comment(lineno, colno,cmbuff,pr);
				strcpy(cmbuff,"");
		}
		add_comment(lineno, colno,cmbuff,'}');
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
		colno++;
                continue;
        }





    }

    if (A4GL_isyes(acl_getenv("A4GL_DUMP_LAST"))) {
	last=fopen("last","w");
	fwrite(buff,1,buff_len,last);

    }

#ifdef DEBUG
for (a=0;a<ncomments;a++) {
A4GL_debug("%d %d - %s\n", 
		load_comments[a].lineno,
		load_comments[a].colno,
		load_comments[a].comment);
}
#endif
}


int A4GL_GetNumberOfComments(void) {
	return ncomments;
}

int A4GL_GetComment(int a, char **s, int *l, int *c, char *type) {
	if (a<ncomments) {
		*s=load_comments[a].comment;
		*l=load_comments[a].lineno;
		*c=load_comments[a].colno;
		*type=load_comments[a].type;
	}
	return 1;
}

char *A4GL_has_comment(int n,int c) {
	int a;
	for (a=0;a<ncomments;a++) {
		if ( load_comments[a].printed) continue;

		if (load_comments[a].lineno<n) {
			load_comments[a].printed++;
			return load_comments[a].comment;
		}
		if (load_comments[a].lineno==n && c< load_comments[a].colno) {
			load_comments[a].printed++;
			return load_comments[a].comment;
		}
	}
	return 0;
}

static void add_comment(int n,int c, char *s, char type) {
	ncomments++;
	load_comments=realloc(load_comments,sizeof(struct s_comments)*ncomments);
	load_comments[ncomments-1].printed=0;
	load_comments[ncomments-1].lineno=n;
	load_comments[ncomments-1].colno=c;
	load_comments[ncomments-1].comment=strdup(s);
	A4GL_trimnl(load_comments[ncomments-1].comment);
	load_comments[ncomments-1].type=type;
}

#ifdef OBSOLETE
static void reload_comments(void) {
char buff[2048];
int lineno;
char *load;
char str[2048];
FILE *load_comment=0;
load=acl_getenv("SAVE_COMMENTS");

if (load) {
	if (strlen(load)) {
		load_comment=fopen(load,"r");
	}
}


if (load_comment==0) return;

while(1) {
	char *ptr;
	if (feof(load_comment)) break;
	fgets(buff,sizeof(buff)-1,load_comment);
	if (feof(load_comment)) break;
	A4GL_trim(buff);
	ptr=strchr(buff,'|');
	if (!ptr) continue;
	*ptr=0;
	ptr++;
	strcpy(str,ptr);
	lineno=atoi(buff);
	add_comment(lineno,str);
}
fclose(load_comment);

}
#endif
