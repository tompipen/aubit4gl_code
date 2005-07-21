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
# $Id: mkmess.c,v 1.14 2005-07-21 08:13:23 mikeaubury Exp $
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
main (int argc, char *argv[])
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

  A4GL_setarg0 (argv[0]);

#ifdef DEBUG
  A4GL_debug ("Starting mkmess");
#endif

  /* load settings from config file(s): */
  A4GL_build_user_resources ();


  if (argc == 1 || (strcmp (argv[1], "--help") == 0))
    {
      printf ("Aubit 4GL compiler - help message compiler\n");
      printf ("Usage: mkmess [path]helpfile[.msg] [[path]outfile.ext]\n");
      exit (0);
    }

  A4GL_bname (argv[1], pathfilename, ext);

#ifdef DEBUG
  A4GL_debug ("pathfilename=%s", pathfilename);
  A4GL_debug ("ext=%s", ext);
#endif

  if (pathfilename[0] == 0)
    {
      //no extension was specified
      strcpy (pathfilename, argv[1]);
      ext[0] = 0;
    }

  if (ext[0] == 0)
    {
      sprintf (fname_msg, "%s.msg", pathfilename);
    }
  else
    {
      sprintf (fname_msg, "%s.%s", pathfilename, ext);
    }

#ifdef DEBUG
  A4GL_debug ("Input file is %s\n", fname_msg);
#endif

  if (argc == 3)
    {
      /* user specified output file name/path as second parameter on command line */
      sprintf (fname_hlp, "%s", argv[2]);
    }
  else
    {
      sprintf (fname_hlp, "%s%s", pathfilename, acl_getenv ("A4GL_HLP_EXT"));
    }

  sprintf (fname_tmp, "%s.tmp", pathfilename);

#ifdef DEBUG
  A4GL_debug ("Input file is %s\n", fname_msg);
  A4GL_debug ("Output file is %s\n", fname_hlp);
  A4GL_debug ("TMP file is %s\n", fname_tmp);
#endif


  /* open all files we will need */

  msg = fopen (fname_msg, "r");
  if (msg == 0)
    {
      printf ("Error opening File %s\n", fname_msg);
      exit (2);
    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("Opened File %s\n", fname_msg);
#endif
    }

  hlp = fopen (fname_hlp, "wb");
  if (hlp == 0)
    {
      printf ("Error opening File %s\n", fname_hlp);
      exit (2);
    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("Opened File %s\n", fname_hlp);
#endif
    }

  tmp = fopen (fname_tmp, "wb");
  if (tmp == 0)
    {
      printf ("Error opening File %s\n", fname_tmp);
      exit (2);
    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("Opened File %s\n", fname_tmp);
#endif
    }


  /* calculate offset and verify that source file is correctly formated */

  offset = 0;
  while (1)
    {
      if (feof (msg))
	break;
      fgets (tmpbuf, 80, msg);
      if (tmpbuf[0] == '#')
	continue;
      if (tmpbuf[0] == '.')
	offset = offset + 4;
    }

  if (offset == 0)
    {
      printf ("Cannot process this file\nThere are no help numbers\n");
      exit (1);
    }


  retcode = A4GL_writemsg (offset, msg, tmp, hlp);
  fclose(tmp);
  /* append content of tmp file to actual output file, lien by line */
  /* this is because the help file will currently only contain the header... */

  tmp = fopen (fname_tmp, "rb");
  while (1 == 1)
    {
      num = fgetc (tmp);
      if (feof (tmp))
	break;
      fputc (num, hlp);
    }

  fclose (hlp);
  fclose (tmp);
  unlink (fname_tmp);


#ifdef DEBUG
  A4GL_debug ("Exiting mkmess");
#endif

  exit (retcode);

}




/* ================================ EOF ========================== */
