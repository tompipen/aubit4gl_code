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
# $Id: mkmess.c,v 1.10 2003-03-23 07:19:42 afalout Exp $
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
int retcode;
char tmpbuf[80];
FILE *hlp;
FILE *msg;
FILE *tmp;
char fname_hlp[128];
char fname_msg[128];
char fname_tmp[128];
int offset;
//char tmpnum[6];
int num;

	setarg0(argv[0]);

   	#ifdef DEBUG
		debug ("Starting mkmess");
	#endif

	/* load settings from config file(s): */
	build_user_resources();


	if ( argc == 1 || (strcmp (argv[1], "--help") == 0) )
	{
		printf("Aubit 4GL compiler - help message compiler\n");
		printf("Usage: mkmess [path]helpfile[.msg] [[path]outfile.ext]\n");
		exit(0);
	}

	bname (argv[1], pathfilename, ext);

   	#ifdef DEBUG
		debug("pathfilename=%s",pathfilename);
    	debug("ext=%s",ext);
    #endif

	if (pathfilename[0] == 0)
    {
		//no extension was specified
		strcpy(pathfilename,argv[1]);
		ext[0]=0;
	}

	if (ext[0] == 0) {
		sprintf(fname_msg,"%s.msg",pathfilename);
	} else {
		sprintf(fname_msg,"%s.%s",pathfilename,ext);
	}

	#ifdef DEBUG
		debug("Input file is %s\n",fname_msg);
    #endif

	if (argc==3) {
		/* user specified output file name/path as second parameter on command line */
		sprintf(fname_hlp,"%s",argv[2]);
	} else {
		sprintf(fname_hlp,"%s%s",pathfilename,acl_getenv ("A4GL_HLP_EXT"));
	}

	sprintf(fname_tmp,"%s.tmp",pathfilename);

	#ifdef DEBUG
		debug("Input file is %s\n",fname_msg);
		debug("Output file is %s\n",fname_hlp);
		debug("TMP file is %s\n",fname_tmp);
    #endif


	/* open all files we will need */

	msg=fopen(fname_msg,"r");
	if (msg==0)
	{
    	printf("Error opening File %s\n",fname_msg);
	    exit(2);
	} else {
		#ifdef DEBUG
			debug("Opened File %s\n",fname_msg);
	    #endif
	}

	hlp=fopen(fname_hlp,"wb");
	if (hlp==0)
	{
	    printf("Error opening File %s\n",fname_hlp);
    	exit(2);
	} else {
   		#ifdef DEBUG
			debug("Opened File %s\n",fname_hlp);
	    #endif
	}

	tmp=fopen(fname_tmp,"wb");
	if (tmp==0)
	{
		printf("Error opening File %s\n",fname_tmp);
	    exit(2);
	} else {
	   	#ifdef DEBUG
			debug("Opened File %s\n",fname_tmp);
	    #endif
	}


	/* calculate offset and verify that source file is correctly formated */

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
		exit(1);
	}


	retcode = writemsg(offset,msg,tmp,hlp);

	/* copy content of tmp file to actual output file, lien by line */
    /* FIXME: why are we not writing directly to output file? */

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

	exit (retcode);

}


#ifdef _MOVED_TO_WRITEMSG_C_

int
writemsg(int offset2)
{
int flg=0;

  rewind(msg);
  tmpbuf[0]=0;

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


  return (1);

}

#endif


/* ================================ EOF ========================== */

