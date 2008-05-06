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
# $Id: decompile_4gl.c,v 1.1 2008-05-06 20:06:16 mikeaubury Exp $
#
*/

/**
 * @file
 * The main module for form decompiler
 */

 /*
    =====================================================================
    Includes
    =====================================================================
  */

#include "a4gl_fcompile_int.h"

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

int main (int argc, char *argv[])
{
  struct struct_form the_form;
  int offset=1;
  //FILE *f;
//XDR xdrp;
  int a;
  char *module;
  char form[32];

  if (argc < 2)
    {
        printf ("Usage:\n");
	printf (" Using common files :\n");
	printf ("    %s filename [modulename]\n", argv[0]);
	printf ("    When using common files you need two shared 4gl modules which are not form dependant :\n");
      	printf ("       %s --generate-global    Generate the shared helper module 'global.4gl'\n", argv[0]);
      	printf ("       %s --generate-common    Generate the shared helper module 'common.4gl'\n", argv[0]);
	printf ("    for security - these are written to stdout - you should redirect them manually - eg:\n");
	printf ("       %s --generate-global > global.4gl\n",argv[0]);
	printf ("       %s --generate-common > common.4gl\n",argv[0]);
	printf ("\n");
	printf (" Using one single file :\n");
	printf ("    %s --single-file filename [modulename]\n", argv[0]);
        exit (0);
    }

  if (strcmp(argv[1],"--generate-global")==0) {
			dump_global_4gl();
			exit(1);
  }

  if (strcmp(argv[1],"--generate-common")==0) {
			dump_common_4gl();
			exit(1);
  }

  if (strcmp(argv[1],"--single-file")==0) {
		set_single_file_mode();
		offset=2;
		if (argc<3) {
			printf("Expecting some filename and possibly modulename still!\n");
			exit(2);
		}
  }

  memset (&the_form, 0, sizeof (struct_form));

  strcpy(form,argv[offset]);
  strcat(form,".afr");
  A4GL_debug("opening form %s\n",form);
  a = A4GL_read_data_from_file ("struct_form", &the_form, form);

  if (!a)
    {
      printf ("Bad format or file not found\n");
      exit (1);
    }

  if (the_form.fcompile_version != FCOMILE_XDR_VERSION)
    {
      printf ("Error - fdecompiler is compiled for XDR version %d forms\n", FCOMILE_XDR_VERSION);
      printf ("This form appears to be version %ld\n", the_form.fcompile_version);
      exit (1);
    }

  //printf ("Dumping form..\n");
  if (argc ==offset+2 ) {
	module = argv[offset+1];
  } else {
	module = argv[offset];
  }
  printf ("Dumping form %s\n",module);
  dump_form_desc (&the_form,module);
return 0;
}


/* =================================== EOF =========================== */
