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
# $Id: 4glc.c,v 1.50 2004-04-15 21:15:37 mikeaubury Exp $
#
*/

/**
 * @file
 * The main module for the 4gl compiler.
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_4glc_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

extern int a4gl_yydebug;		/* defined in y.tab.c _IF_ -DYYDEBUG is set, otherwise in map.c */
extern FILE *ferr;
extern int yyleng;
extern int chk4var;
extern int lcnt;
extern FILE *yyin;
extern char *outputfilename;	/* Defined in libaubit4gl */
extern char infilename[132];
extern int yyin_len;		/*now in map.c*/

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

extern int initArguments (int argc, char *argv[]);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 * The main entry point function of 4glc compiler.
 *
 * @param argc The argument count
 * @param argv The argument values
 */
int
main (int argc, char *argv[])
{
  int x = 0;
  struct str_resource *user_resource = 0;


  A4GL_setarg0 (argv[0]);
  A4GL_debug ("Initializing 4glc\n");
  init_states ();
  a4gl_yydebug = 1;

  /* load settings from config file(s): */
  user_resource = A4GL_build_user_resources ();
  import_package("default");

  x = initArguments (argc, argv);
  if (a4gl_yydebug)
    {
      printf ("Exit\n");
    }

  /*dump_var_records();*/
  A4GL_debug ("Exiting 4glc");
  exit (x);
}


/* ============================== EOF =============================== */
