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
# $Id: mkmess.c,v 1.6 2002-09-24 04:40:02 afalout Exp $
#*/

/**
 * @file
 * mkmess - message help file compiler, Informix 4gl style formated.
 *
 * Compile a message file (.msg) in ??? format, and generates a help 
 * compiled file (.hlp)
 *
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_fcompile_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/


FILE *hlp;
FILE *msg;
FILE *tmp;
char fname_hlp[20];
char fname_msg[20];
char fname_tmp[20];
int offset;
int offset2;
int flg;
int num;
char tmpbuf[80];
char tmpnum[6];

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * The main entry function to mkmess compiler
 *
 * @param argc The arg count
 * @param argv The arguments values
 */
main(int argc,char *argv[])
{

   	#ifdef DEBUG
		debug ("Starting mkmess");
	#endif


	/* load settings from config file(s): */
	build_user_resources();


  if (argc!=2)
  {
    printf("Usage: mkmess help-file (no .msg extension)\n");
    exit(0);
  }
  sprintf(fname_msg,"%s.msg",argv[1]);
  sprintf(fname_hlp,"%s.hlp",argv[1]);
  sprintf(fname_tmp,"%s.tmp",argv[1]);
  msg=fopen(fname_msg,"r");
  if (msg==0)
  {
    printf("Error opening File %s\n",fname_msg);
    exit(0);
  }
  hlp=fopen(fname_hlp,"wb");
  tmp=fopen(fname_tmp,"wb");
  offset=0;
  while (1)
  {
    if (feof(msg)) break;
      fgets(tmpbuf,80,msg);
    if (tmpbuf[0]=='#') continue;
    if (tmpbuf[0]=='.') offset=offset+4;
  }
  if (offset==0)
  {
    printf("Cannot process this file\nThere are no help numbers\n");
    exit(0);
  }
  rewind(msg);
  tmpbuf[0]=0;
  offset2=offset;
  flg=0;
  while (1)
  {
    if(feof(msg)) 
    {
      if (flg==1) 
      {
        if (tmpbuf[strlen(tmpbuf)]!='\n'&& tmpbuf[0]!='#')
	{
          fprintf(tmp,"\n");   
        }
        offset++;
      }
      break;
    }
    tmpbuf[0]=0;
    fgets(tmpbuf,80,msg);
    if (feof(msg)) break;
    if (tmpbuf[0]=='.')
    {
      if (flg==1) {fprintf(tmp,"%c",127);}
      offset++;
      num=atoi(&tmpbuf[1]);
      fwrite(&num,2,1,hlp);
      fwrite(&offset,2,1,hlp);
      flg=1;
      continue;
    }
    if (flg==1)
    {
      fprintf(tmp,"%s",tmpbuf);
      offset=offset+strlen(tmpbuf);
    }
  }

  num=-1;
  fwrite(&num,2,1,hlp);
  fwrite(&offset,2,1,hlp);
  fclose(tmp);
  tmp=fopen(fname_tmp,"rb");
  while (1==1)
  {
    num=fgetc(tmp);
    if (feof(tmp)) break;
    fputc(num,hlp);
  }
  fclose(hlp);
  fclose(tmp);
  unlink(fname_tmp);

   	#ifdef DEBUG
		debug ("Exiting mkmess");
	#endif

  exit (0);

}

/**
 * This functions is not used
 *
 * @todo If not used remove it
 */
/*
static void read_help_f(int no)
{
  int pos;
  hlp=fopen(fname_hlp,"rb");
  while (1)
  {
    fread(&pos,2,1,hlp);
    if (pos==-1 || pos>no) break;
    if (feof(hlp)) break;
    fread(&num,2,1,hlp);
    if (pos==no)
    {
      fseek(hlp,(long)num+3,SEEK_SET);
      while(1==1)
      {
        if (feof(hlp)) break;
        fgets(tmpbuf,80,hlp);
        printf("%s",tmpbuf);
        num=fgetc(hlp);
        if (num==127) break;
        else
        ungetc(num,hlp);
      }
    }
  if (pos==no) break;
  }
}

*/

/* ================================ EOF ========================== */

