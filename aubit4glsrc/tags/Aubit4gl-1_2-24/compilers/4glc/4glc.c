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
# $Id: 4glc.c,v 1.77 2009-07-04 12:40:09 mikeaubury Exp $
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

extern FILE *ferr;
extern int yyleng;
extern int chk4var;
extern int lcnt;
extern FILE *yyin;
extern char *outputfilename;	/* Defined in libaubit4gl */
extern char infilename[132];
extern int yyin_len;		/*now in map.c*/
//extern char                clobber[64];
//void import_package(char *s);
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

#ifndef WIN32
#define SET_LIMIT
#endif

#undef SET_LIMIT
#ifdef SET_LIMIT
       #include <sys/time.h>
       #include <sys/resource.h>
#endif


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
  char *ptr;
  char *dialect=0;
  struct str_resource *user_resource = 0;
#ifdef SET_LIMIT
    struct rlimit rl;
#endif

#ifdef OPTIMIZED
	A4GL_setenv("DONTSAVECOMMENTS","Y",1); // Dont store the comments in the parse tree - only need for lint etc..
#endif

  A4GL_setarg0 (argv[0]);
#ifdef DEBUG
  A4GL_debug ("Initializing 4glc\n");
#endif
  memset(infilename,0,sizeof(infilename));
   //init_blk();
  //init_states ();
  
  //a4gl_yydebug = 1;

  /* load settings from config file(s): */
  user_resource = A4GL_build_user_resources ();
  //if (A4GL_isno (acl_getenv ("A4GL_NOCLOBBER"))) { set_clobber (outputfilename); }

  //A4GL_initlex();

  A4GL_lexer_import_package("default");

  ptr=acl_getenv_not_set_as_0("NAMESPACE");
  if (ptr!=0) {
		set_namespace(ptr);
  }

  if (A4GL_isyes(acl_getenv("GLOBALCURS"))) {
	// Global cursors need globbing turned off..
	A4GL_setenv("A4GL_NOSQLCLOBBER","Y",1);
  }

  dialect=acl_getenv("A4GL_LEXDIALECT");

  if (strlen(dialect)==0) {
	dialect=0;
  }
	if (strcmp(acl_getenv("PACKER"),"XDR")==0) {
		A4GL_setenv ("A4GL_PACKER", "PACKED", 1);
	}


  if (dialect) {
	  char *transfile;
	  transfile=acl_getenv_not_set_as_0("A4GL_TARGETDIALECT");
	  if (transfile) dialect=transfile;
	// We're only going to load our pack now if we are generating a dialect...
  	A4GLSQLCV_load_convert(A4GL_compiled_sqlpack(),dialect);
  }  else {
  	A4GLSQLCV_load_convert(A4GL_compiled_sqlpack(),"default");
  }


#ifdef SET_LIMIT
      rl.rlim_max = rl.rlim_cur = 512000000;
        if (setrlimit(RLIMIT_AS, &rl)) {
		perror("setrlimit");
	}
#endif


  x = initArguments (argc, argv);
  //if (a4gl_yydebug)
    //{
      //PRINTF ("Exit\n");
    //}

  /* dump_var_records();*/

  //A4GL_write_generated_code(module);

#ifdef DEBUG
  A4GL_debug ("Exiting 4glc");
#endif
  exit (x);
}

#ifdef MOVED
void
set_clobber(char *c)
{
	        char *ptr;
		        //char *ptr2;
		        ptr=strrchr(c,'/');
			        if (ptr) { strcpy(clobber,ptr+1); return; }

				/* Do dos mode ? */
				        ptr=strrchr(c,'\\');
					        if (ptr) { strcpy(clobber,ptr+1); return; }

						        strcpy(clobber,c);
}
#endif


/* ============================== EOF =============================== */
