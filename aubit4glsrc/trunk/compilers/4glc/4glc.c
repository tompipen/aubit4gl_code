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
# $Id: 4glc.c,v 1.39 2002-10-18 01:56:33 afalout Exp $
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


//#ifdef YYDEBUG
//	extern int yydebug; /* defined in y.tab.c _IF_ -DYYDEBUG is set */
//#else
//	int yydebug; /* if -DYYDEBUG is not set, we need to define it here */
//#endif

extern int yydebug; /* defined in y.tab.c _IF_ -DYYDEBUG is set, otherwise in map.c */

extern 		FILE *ferr;
//m extern int 	yylineno;
extern int 	yyleng;
extern int 	chk4var;
extern int 	lcnt;
//m extern FILE *yyin;
extern FILE *yyin;
//m extern int 	glob_only;
//m extern char *outputfilename; /* Defined in libaubit4gl */
extern char *outputfilename; /* Defined in libaubit4gl */
//m extern char infilename[132];
extern char infilename[132];
//m extern long fpos; /** The current file position for direct fseek */

/**
 * Flag that identifies if the compiler should generate function call stack
 * actualization.
 */
//m static int 	genStackInfo = 1;
//m static char outputfile[132]; /** The output file name */

//m char 		yytext[] = "";
//m int 		yyin_len;
extern int 		yyin_len; //now in map.c
//m char 		errbuff[1024] = "";
//m int 		globals_only = 0;


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

//void 		setGenStackInfo		(int _genStackInfo);

extern void 	initArguments(int argc, char *argv[]);


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
main(int argc, char *argv[])
{
  #ifdef OLD_GETOPT
  char a[128];
  char b[128];
  char c[128];
  int fname_arg_no = 1;
  #endif

  int x;


  /** @todo : Remove things that are to use */
//#if (defined(__MACH__) && defined(__APPLE__))
//  int useGetopt = 0;
//#else
  //int useGetopt = 1;
//#endif
  init_states ();

  yydebug = 0;

  /* load settings from config file(s): */
  build_user_resources();


  //if ( useGetopt )
  #ifndef OLD_GETOPT
    initArguments(argc,argv);
  #else
  else             /** @todo : Remove this code when it works OK */
  {
    if (argc > 1)
    {
      if (strcmp (argv[1], "-G") == 0)
      {
        globals_only = 1;
        fname_arg_no = 2;
      }

      check_and_show_id ("4GL Compiler", argv[fname_arg_no]);

      outputfilename = outputfile;
  
      if (strcmp (acl_getenv ("YYDEBUG"), "") != 0)
      {
        printf ("Yacc Debugging on\n");
        yydebug = 1;
      }
  
      strcpy (c, argv[fname_arg_no]);
      bname (c, a, b);
      if (b[0] == 0)
      {
        strcat (c, ".4gl");
      }
      bname (c, a, b);
      strcpy (outputfilename, a);
      yyin = fopen (c, "r");
  
      strcpy (infilename, c);
    }
    else
    {
      printf ("Usage %s [-G] filename[.4gl]\n", argv[0]);
      exit (1);
    }
  }
  #endif //OLD_GETOPT

  if (yyin == 0)
  {
    printf ("Error opening file : %s\n", infilename);
    exit (1);
  }

	#if YYDEBUG != 0
    	printf ("YYDEBUG was set while compiling\n");
		#ifdef YYPRINT
    		printf ("YYPRINT was set while compiling\n");
		#endif
	#endif

  fseek(yyin,0,SEEK_END);
  yyin_len=ftell(yyin);
  rewind(yyin);

  if (yydebug)
    {
      printf ("Opened : %s\n", infilename); //c);
    }

  openmap(outputfilename);
  if (!A4GLSQL_initlib()) {
	printf("4glc: Error opening SQL Library (A4GL_SQLTYPE=%s)\n", acl_getenv("A4GL_SQLTYPE"));
	exit(1);
  }

  init_datatypes();
  debug("after init_datatypes\n");
  x = yyparse (); /* we core dump here on Darwin */
  debug("after yyparse\n");

  if (yydebug)
    {
      printf ("Closing map : %d\n", x);
    }

  closemap ();
  debug("after closemap");

  if (yydebug)
    {
      printf ("Exit\n");
    }


  exit (x);
}


/* ============================== EOF =============================== */

