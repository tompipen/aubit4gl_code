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
# $Id: mkmess.c,v 1.8 2003-02-12 05:53:53 afalout Exp $
#*/

/**
 * @file
 * mkmess - message help file compiler, Informix 4gl style formated.
 *
 * Compile a message file (.msg), and generates a help compiled file
 * for use in Aubit 4gl programs
 *
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_mkmess_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/


FILE *hlp;
FILE *msg;
FILE *tmp;
char fname_hlp[128];
char fname_msg[128];
char fname_tmp[128];
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
int
main(int argc,char *argv[])
{
char pathfilename[128];
char ext[128];

	setarg0(argv[0]);

   	#ifdef DEBUG
		debug ("Starting mkmess");
	#endif

	/* load settings from config file(s): */
	build_user_resources();


  if ( (argc!=2) || (strcmp (argv[1], "--help") == 0) )
  {
    printf("Aubit 4GL compiler - help message compiler\n");
	printf("Usage: mkmess [path]helpfile[.msg]\n");
    exit(0);
  }

	bname (argv[1], pathfilename, ext);

    debug("pathfilename=%s",pathfilename);
    debug("ext=%s",ext);

  if (pathfilename[0] == 0) {
    //no extension was specified
	strcpy(pathfilename,argv[1]);
    ext[0]=0;
  }

  if (ext[0] == 0) {
	  sprintf(fname_msg,"%s.msg",pathfilename);
  } else {
	  sprintf(fname_msg,"%s.%s",pathfilename,ext);
  }

  debug("Input file is %s\n",fname_msg);

  sprintf(fname_hlp,"%s%s",pathfilename,acl_getenv ("A4GL_HLP_EXT"));
  sprintf(fname_tmp,"%s.tmp",pathfilename);

  debug("Input file is %s\n",fname_msg);
  debug("Output file is %s\n",fname_hlp);
  debug("TMP file is %s\n",fname_tmp);

  msg=fopen(fname_msg,"r");
  if (msg==0)
  {
    printf("Error opening File %s\n",fname_msg);
    exit(0);
  } else {
    debug("Opened File %s\n",fname_msg);
  }
  
  hlp=fopen(fname_hlp,"wb");
  if (hlp==0)
  {
    printf("Error opening File %s\n",fname_hlp);
    exit(0);
  } else {
    debug("Opened File %s\n",fname_hlp);
  }

  tmp=fopen(fname_tmp,"wb");
  if (tmp==0)
  {
    printf("Error opening File %s\n",fname_tmp);
    exit(0);
  } else {
    debug("Opened File %s\n",fname_tmp);
  }

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

/* ================================ EOF ========================== */

