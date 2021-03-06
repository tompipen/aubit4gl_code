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
# | contact licensing@aubit.com                                           |
# +----------------------------------------------------------------------+
#
# $Id: decompile.c,v 1.24 2008-11-05 14:23:35 mikeaubury Exp $
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
#include "dump_form.h"

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

int main (int argc, char *argv[])
{
  struct struct_form the_form;
  //FILE *f;
//XDR xdrp;
  int a;
  char *module;
  char form[32];

  if (argc < 2)
    {
      printf ("Usage %s filename [modulename]\n", argv[0]);
      exit (0);
    }

  //f=fopen(argv[1],"rb");

  //if (f==0) {
  //printf("Unable to open file %s\n",argv[1]);
  //exit(2);
  //}

  //xdrstdio_create(&xdrp,f,XDR_DECODE);
  //xdr_int(&xdrp,&a);

  //printf("Magic number : %x\n",a);
  //rewind(f);


  //if (a != FCOMILE_XDR_MAGIC) {
  //printf("This does not appear to be a valid form\n(Bad magic number - got %x rather than %x)\n",a,FCOMILE_XDR_MAGIC);
  //exit(0);
  //}

  memset (&the_form, 0, sizeof (struct_form));

  //A4GL_build_user_resources ();

  //xdrstdio_create(&xdrp,f,XDR_DECODE);

  //a=isolated_xdr_struct_form(&xdrp,&the_form); /* in lib/libform/form_xdr/formwrite2.c */

  //a = A4GL_read_data_from_file ("struct_form", &the_form, argv[1]);
  strcpy(form,argv[1]);
  strcat(form,".afr");
printf("opening form %s\n",form);
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
  if (argc ==3 ) {
	module = argv[2];
  } else {
	module = argv[1];
  }
  printf ("Dumping form %s\n",module);
  dump_form_desc (&the_form,module);
return 0;
}


/* =================================== EOF =========================== */
