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
# $Id: compile.c,v 1.7 2003-02-23 02:32:38 afalout Exp $
#*/

/**
 * @file
 * Processing of command line parameters to 4glc and invocation of
 * 4GL parser.
 *
 * Also contains post-4glc processing, like invocation of C compiler
 * and linker, to produce object, libraries and executable programs,
 * whitch should eventially replace current 4glpc compiler script
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_4glc_int.h"
#include "memfile.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

/* -------- static --------- */
static char outputfile[132]; 	/** The output file name */
static int 	genStackInfo = 1;


/* -------- extern --------- */
//FIXME - move in "a4gl_4glc_int.h"
extern char *outputfilename; 	/* Defined in libaubit4gl */
extern int 	globals_only;       /* defined in map.c */
extern char infilename[132];
extern FILE *yyin;
extern int 	glob_only;
extern long fpos; 				/** current file position for direct fseek */
extern int 	yylineno;

/* -------- unknown --------- */
char 		gcc_exec[128];
char 		pass_options[1024]="";
int         clean_aftercomp = 1; /* clean intermediate files after compilation */
//char 		rm_cmd[10];
char 		currinfile_dirname[1024]="";   //path to 4gl file we are currently compiling - used when compiling global files
char 		errbuff[1024] = "";
char 		yytext[1024] = "";
int 		globals_only = 0;
int 		yyin_len;


#ifdef YYDEBUG
	extern int yydebug; 		/* defined in y.tab.c _IF_ -DYYDEBUG is set */
#else
	int yydebug; 				/* if !-DYYDEBUG, we need to define it here */
#endif


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

//static int  compile_4gl		(char c[128],int compile_object, char a[128],char incl_path[128],int silent, int verbose);
static int  compile_4gl		(int compile_object, char a[128],char incl_path[128],int silent, int verbose,char output_object[128]);
static void printUsage		(char *argv[]);
static void printUsage_help	(char *argv[]);
int         initArguments	(int argc, char *argv[]);
void 		setGenStackInfo	(int _genStackInfo);
void        set_yytext		(char *s);


/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Parse the comand line arguments and acording to the passed values
 * set(s) the properties.
 *
 * @param argc The argument count
 * @param argv The argument values
 */
int
initArguments(int argc, char *argv[])
{
int i;
/* extern char *optarg; in /usr/include/getopt.h */
/*  int this_option_optind = optind ? optind : 1; */
int option_index = 0;
int compile_object = 0;
int compile_exec = 0;
int compile_so = 0;
int compile_lib = 0;
int si;
int x = 0;
int ret;
int index;
int silent = 0;
int verbose = 0;
int todo = 0;

char opt_list[40];
char a[128];
char b[128];
char c[128];
char ext[128];
char incl_path[128];
char l_path[128];
char l_libs[128];
char buff[1028];
char all_objects[456];
char output_object[128];
static struct option long_options[] =
  {
    {"globals",     	0, 0, 'G'},
    {"stack_trace", 	1, 0, 's'},
    {"help", 			0, 0, '?'},
    {"silent", 			0, 0, 'S'},
    {"verbose", 		0, 0, 'V'},
    {"version", 		0, 0, 'v'},
    {"version_full",	0, 0, 'f'},
    {"lextype",			0, 0, 't'},
    {0, 0, 0, 0},
  };

	#ifdef DEBUG
		debug ("Parsing the comand line arguments\n");
    #endif

	/* see
		http://www.gnu.org/software/gengetopt
		http://www.gnu.org/manual/glibc-2.2.3/html_node/libc_516.html
        for inspiration.
	*/

	#ifdef DEBUG
		debug("Arg 0 set to >%s<",getarg0());
    #endif

  if (strcmp (acl_getenv ("A4GL_LEXTYPE"), "C") == 0)
  {
    //strcpy(opt_list,"Gs:co::d::l::?hSVvft");
    strcpy(opt_list,"Gs:co::l::?hSVvft");
  }

  if (strcmp (acl_getenv ("A4GL_LEXTYPE"), "PERL") == 0)
  {
    strcpy(opt_list,"Gs:?hSVvft");
  }

  /* this call will intercept -v and -vfull arguments, that can be only
  arguments on command line anyway */
  if (argc > 1) {
	check_and_show_id ("4GL Compiler", argv[1]);
  } else {
	printUsage_help(argv);
    exit(0);
  }

  strcpy (output_object,"");

  while ( ( i = getopt_long (argc, argv, opt_list,
                        long_options, &option_index) ) != -1)
  {
    switch(i)
    {

	  case 'c':              // Compile resulting C file(s) to object
		//if (compile_lib) 	{printf("Cannot specify -l and -c together.\n"); exit(7);}
		//if (compile_exec) 	{printf("Cannot specify -o and -c together.\n"); exit(7);}
		//if (compile_so) 	{printf("Cannot specify -d and -c together.\n"); exit(7);}

        /* this is more or less meaningless, and is here for compatibility with C compiler
        style flags */

		compile_object = 1;
		break;

      case 'o':              /* compile and optionally Link resulting object(s) */
		//if (compile_object) {printf("Cannot specify -c and -o together.\n"); exit(7);}
		//if (compile_so) 	{printf("Cannot specify -d and -o together.\n"); exit(7);}
		//if (compile_lib) 	{printf("Cannot specify -l and -o together.\n"); exit(7);}

		//compile_exec = 1;
		//compile_object = 1;

		sprintf (output_object,"%s",(NULL == optarg) ? "" : optarg);
		//sprintf (output_object,"%s",optarg);

		bname (output_object, a, b);

		/* FIXME: we should no longer assume anything about parameters on command
        line, if we want to be able to pass flags to CC */
		/*
		if (b[0] == 0)
		{
			strcat (c, ".4gl"); 	// assume 4gl file name
			bname (c, a, b);
		}
        */

		// Add dot because bname returns extension without dot, and we define extensions in
        // resource.c with the dot:
		//sprintf (b,".%s",b);
        strcpy (ext,".");
		strcat (ext,b);
        debug ("%s %s %s",b, acl_getenv ("A4GL_EXE_EXT"),ext);

		if (strcmp (ext, acl_getenv ("A4GL_OBJ_EXT")) == 0) {
			compile_object = 1;
        }

		if (strcmp (ext, acl_getenv ("A4GL_EXE_EXT")) == 0) {
			compile_object = 1;
			compile_exec = 1;
        }

		if (strcmp (ext, acl_getenv ("A4GL_LIB_EXT")) == 0) {
			compile_object = 1;
			compile_lib = 1;
        }

		break;
/*
      case 'd':              // Link resulting object(s) into shared library
		if (compile_object) {printf("Cannot specify -c and -d together.\n"); exit(7);}
		//if (compile_exec) 	{printf("Cannot specify -o and -d together.\n"); exit(7);}
		if (compile_lib) 	{printf("Cannot specify -l and -d together.\n"); exit(7);}

		compile_so = 1;
		compile_object = 1;
		sprintf (output_object,"%s",(NULL == optarg) ? "" : optarg);
		break;

      case 'l':              // Link resulting object(s) into static library
		if (compile_object) {printf("Cannot specify -c and -l together.\n"); exit(7);}
		//if (compile_exec) 	{printf("Cannot specify -o and -l together.\n"); exit(7);}
		if (compile_so) 	{printf("Cannot specify -d and -l together.\n"); exit(7);}

		compile_lib = 1;
		compile_object = 1;
		sprintf (output_object,"%s",(NULL == optarg) ? "" : optarg);
		break;
*/
      
      case 'l':              // Extra libraries to link with
		#ifdef DEBUG
			debug("Pass trough option: %s\n",optarg);
        #endif

		//sprintf (output_object,"%s",(NULL == optarg) ? "" : optarg);
		strcat (pass_options,"-l");
		strcat (pass_options,optarg);
		strcat (pass_options," ");
		break;

	  case 'G':              /* generate Globals file only */
		/* call from mod.c:   sprintf (buff, "cd %s; 4glc -G %s", dirname, fname); */
		globals_only = 1;
        break;

      case 's':              /* Stack information inclusion */
		si = atoi(optarg);
        if ( si != 0 && si != 1 )
		{
		  printUsage_help(argv);
		  exit(1);
		}
        setGenStackInfo(si);
        break;

      case '?':             /* Help */
      case 'h':
		printUsage_help(argv);
        exit(0);

      case 'i':             /* do not clean intermedate files */
		clean_aftercomp = 0;
		break;

      case 'S':             /* Silent */
        silent = 1;
        verbose = 0;
        break;

      case 'V':             /* Verbose */
        verbose = 1;
        silent = 0;
        break;

      case 'v':             /* Show version - needed for long opts*/
		check_and_show_id ("4GL Compiler", "-v");
        exit (0);

	  case 'f':             /* Show version - needed for long opts*/
		check_and_show_id ("4GL Compiler", "-vfull");
        exit (0);

       default : 			/* Catch all.  */
		printf("Invalid option=%s\n", argv[optind]);
		printf("Invalid option=%s\n", argv[option_index]);
		exit (1);
    }
  }

	if ( optind >= argc )
	{
		printf("No file name defined\n");
		printUsage_help(argv);
		exit(1);
	}

	#if YYDEBUG != 0
    	#ifdef DEBUG
			debug ("YYDEBUG was set while compiling\n");
    	#endif
		#ifdef YYPRINT
	    	#ifdef DEBUG
				debug ("YYPRINT was set while compiling\n");
            #endif
		#endif
	#endif

	if (strcmp (acl_getenv ("YYDEBUG"), "") != 0)
	{
	   	#ifdef DEBUG
			debug ("Yacc Debugging on\n");
	    #endif
    	yydebug = 1;
	}
	else
	{
		yydebug = 0;
	}

	init_datatypes();

	if (!A4GLSQL_initlib()) {
		printf("4glc: Error opening SQL Library (A4GL_SQLTYPE=%s)\n", acl_getenv("A4GL_SQLTYPE"));
		exit(1);
	}

    /* prepare CC flags */
	strcpy (incl_path,"-I");
	strcat (incl_path,acl_getenv ("AUBITDIR"));
	strcat (incl_path,"/incl");

	strcpy (l_path,"-L");
	strcat (l_path,acl_getenv ("AUBITDIR"));
	strcat (l_path,"/lib");

	strcpy (l_libs,acl_getenv ("A4GL_LINK_LIBS"));
    strcpy (gcc_exec,acl_getenv ("A4GL_C_COMP"));

	//FIXME: move to resource.c
/*
	#ifdef WIN32
		sprintf (rm_cmd,"%s","del");
	#else
		sprintf (rm_cmd,"%s","rm");
    #endif
*/
	strcpy (all_objects,"");
//	strcpy (pass_options,"");

	for (index = optind; index < argc; index++)
    {
    	//printf ("Non-option argument %s\n", argv[index]);

		outputfilename = outputfile; /* set where ? */

		strcpy (c, argv[index]);
		bname (c, a, b);

		/* FIXME: we should no longer assume anything about parameters on command
        line, if we want to be able to pass flags to CC */
		/*
		if (b[0] == 0)
		{
			strcat (c, ".4gl"); 	// assume 4gl file name
			bname (c, a, b);
		}
        */

		if (strcmp (b, "4gl") == 0) {
			strcpy (outputfilename, a);
			strcat (all_objects,a);
			strcat (all_objects,acl_getenv ("A4GL_OBJ_EXT"));
			strcat (all_objects," ");
			strcpy (infilename, c);
			#ifdef DEBUG
				debug ("Compiling %s\n", infilename);
            #endif

			if (strcmp (output_object, "") == 0) {
            /* If user did not name output file explicityl,
            set output file name based on file naem of the first 4gl file
            found on the command line, and set it's extension base on compilation type
            */
				strcpy (output_object,a);

                if (compile_exec) {
					strcat (output_object,acl_getenv ("A4GL_EXE_EXT"));
                }
                if (compile_so) {
					strcat (output_object,acl_getenv ("A4GL_DLL_EXT"));
                }
                if (compile_lib) {
					strcat (output_object,acl_getenv ("A4GL_LIB_EXT"));
					strcat (output_object," ");
                }

            }

            todo++;
		printf("Compiling: %s\n",c);
            x = compile_4gl(compile_object,a,incl_path,silent,verbose,output_object);
			if ( x )
	        {
	            exit (x);
	        }

        } else {
			/* just pass stuff you don't understand to CC */
			#ifdef DEBUG
				debug("Pass trough option: %s\n",c);
            #endif

			strcat (pass_options,c);
			strcat (pass_options," ");
        }



	}

    if (! todo) {
		if (! silent) {
			//printf ("Warning: no 4gl input files - nothing to do.\n");
	    }
	    //exit (1);
        debug ("Linking only - no 4gl input files.\n");
	}



    if (compile_exec)
	{
        debug ("Linking exec\n");
		#ifndef __MINGW32__
			sprintf (buff,"%s -rdynamic %s -o %s %s %s %s",gcc_exec,all_objects,output_object,l_path,l_libs,pass_options);
        #else
			//WARNING: libs must be at the end
			sprintf (buff,"%s %s -o %s %s %s %s",gcc_exec,all_objects,output_object,l_path,pass_options,l_libs);
        #endif
	}

    if (compile_lib)
	{
   		#ifndef __MINGW32__
			debug ("Linking static library\n");
			sprintf (buff,"%s -static %s -o %s %s %s %s",gcc_exec,all_objects,output_object,l_path,l_libs,pass_options);
        #else
            /* On Windows, there can be no unresolved dependencies at link time - so we allways must
            link with libaubit4gl - but we do not make any static Aubit libraries any more, so we
            must link with .dll - meaning that we must force shared linking even when user specified
            static flag */
			debug ("Static linking specified - forcing shared linking on Windows\n");
            compile_lib=0;
			compile_so=1;
		#endif
	}

    if (compile_so)
	{
		debug ("Linking shared library\n");
		#ifndef __MINGW32__
			sprintf (buff,"%s -shared %s -o %s %s %s %s",gcc_exec,all_objects,output_object,l_path,l_libs,pass_options);
        #else

/*
gcc -shared -Wl,--out-implib=TMP.dll.a -Wl,--export-all-symbols -o ../../lib/lib4glc.dll compile.o dim.o
gcc -shared -Wl,--out-implib=TMP.dll.a -Wl,--export-all-symbols  -o invwind.aox cacdwind.ao cashwind.ao centwind.ao creddetl.ao credfunc.ao crhdwind.ao dispgpfunc.ao ientwind.ao inhdwind.ao instwind.ao invdfunc.ao invowind.ao invqwind.ao ishpwind.ao orddfunc.ao orstfunc.ao unapp_pay.ao D:/cygwin/usr/src/aubit/apps/erp/src/utility/glob_GLOBALS.ao  -LD:/cygwin/usr/local/aubit4gl/lib -laubit4gl
*/
			//NOTE: we are acutally making a Window dll here.
			//WARNING: libs must be at the end
			//WARNING: without -L ld on Windows won't find it's own ass!!!! Not even in curren directory!!!
			sprintf (buff,"%s -L. -shared -Wl,--out-implib=%s.a -Wl,--export-all-symbols %s -o %s %s %s %s",
					gcc_exec,output_object,all_objects,output_object,pass_options,l_path,l_libs);
		#endif

	}


    if (compile_exec || compile_so || compile_lib) {
		if (verbose) {
			printf ("%s\n",buff);
	    }
		sprintf (buff,"%s > %s.err 2>&1",buff,output_object);
		#ifdef DEBUG
			debug("Runnung %s",buff);
	    #endif
		ret=system (buff);
		if (ret) {
			printf ("Error compiling %s - check %s.err\n",output_object,output_object);
			printf ("Command was: %s\n",buff);
			//fixme: show err file
            return ret;
	    }
        else
        {
    		if (clean_aftercomp)
			{
				sprintf (buff,"%s %s",acl_getenv("A4GL_RM_CMD"),all_objects);
				#ifdef DEBUG
					debug("Runnung %s\n",buff);
		        #endif
				ret=system (buff);
				if (ret) {
					printf ("Clean of %s intermediate objects failed\n",a);
                    printf ("Command was: %s\n",buff);
	            }
            }


        }
    } else {
	    if (! todo) {
    	    debug ("Somethig wrong here - no 4gl input files and no linking.\n");
		}
	}

  return x;
}




/**
 * Compile one 4gl file to output language, and optionally to object
 *
 *
 * @param
 * @param
 */
static int
compile_4gl(int compile_object,char a[128],char incl_path[128],int silent,int verbose,char output_object[128])
{
int x, ret;
char buff[1028];
char c[128];
char *ptr;

  /* store the directory part of file name, if any, so we can use it for GLOBALS
  file compilation, if nececery */

  sprintf(c,"%s%s",a,".4gl");
  strcpy (buff, c);

  if (strchr (buff, '/'))
    {
      ptr = strrchr (buff, '/');
  	  strcpy(ptr, ""); // this does NOT leave a slash at the end
      strcpy (currinfile_dirname, buff);
	}
  else
    {
      strcpy (currinfile_dirname, ".");
    }


  #ifdef DEBUG
  	debug ("Set currinfile_dirname to: %s\n", currinfile_dirname);
	debug ("Opening in memory: %s\n", c);
  #endif

  /*
  File MUST be opened in binary mode on Windows, to be able to process
  source file in DOS format - otherwise fpos/ftell gets completely dissoriented:
  */
  yyin = memfile_fopen (c, "rb");

  //printf("Buffer size : %d\n",BUFSIZ);
  //file_buffer=malloc(30000);
  //setbuf(yyin,file_buffer);

  if (yyin == 0)
  {
    #ifdef DEBUG
		debug ("Error opening file : %s\n", c);
    #endif
	printf ("Error opening file : %s\n", c);
    exit (1);
  }


  memfile_fseek(yyin,0,SEEK_END);
  yyin_len=memfile_ftell(yyin);
  memfile_rewind(yyin);

  if (yydebug)
    {
      printf ("Opened : %s\n", c);
    }

  openmap(outputfilename);


  if (! silent) {
    if (globals_only) {
		if (verbose) {
			printf ("Preparing globals file for: %s\n",c);
        }
        #ifdef DEBUG
			debug ("Preparing globals file for: %s\n",c);
        #endif
    } else {
		if (verbose) {
			printf ("Translating to %s: %s\n",acl_getenv ("A4GL_LEXTYPE"),c);
        }
        #ifdef DEBUG
			debug ("Translating to %s: %s\n",acl_getenv ("A4GL_LEXTYPE"),c);
        #endif
    }
  }

  x = yyparse (); /* we core dump here on Darwin */
  #ifdef DEBUG
	  debug("after yyparse\n");
  #endif
  lex_parsed_fgl();

  if (yydebug)
    {
      printf ("Closing map : %d\n", x);
    }

  dump_gvars();
  closemap ();
  #ifdef DEBUG
	  debug("after closemap");
  #endif

  if ( x == 0 )
  {
	if (compile_object)
	{
        if (verbose) {
            printf ("4GL module compiled successfuly.\n");

        }

/*

gcc  -g -O2 -Wall -mms-bitfields  -c -o compile.o compile.c
gcc -shared -Wl,--out-implib=TMP.dll.a -Wl,--export-all-symbols -o ../../lib/lib4glc.dll compile.o dim.o  -L../../lib -laubit4gl

*/

   		#ifndef __MINGW32__
			//sprintf (buff, "%s %s.c -c -o %s%s %s %s",gcc_exec,a,a,acl_getenv ("A4GL_OBJ_EXT"),incl_path,pass_options);
			sprintf (buff, "%s %s.c -c -o %s %s %s",gcc_exec,a,output_object,incl_path,pass_options);
        #else
			sprintf (buff, "%s -mms-bitfields %s.c -c -o %s %s %s",gcc_exec,a,output_object,incl_path,pass_options);
        #endif
		if (verbose) {
			printf ("%s\n",buff);
        }
		sprintf (buff,"%s > %s.c.err 2>&1",buff,a);
		#ifdef DEBUG
			debug("Runnung %s",buff);
        #endif
		ret=system (buff);
        //see function system_run() in fglwrap.c
		if (ret) {
			printf ("Error compiling %s.c - check %s.err\n",a,a);
			printf ("Command was: %s\n",buff);
			//fixme: show err file
            return ret;
        }
		else
		{
			if (clean_aftercomp)
			{
				sprintf (buff,"%s %s.err %s.c.err %s.h %s.c %s.glb",acl_getenv("A4GL_RM_CMD"),a,a,a,a,a);
				#ifdef DEBUG
					debug("Runnung %s",buff);
		        #endif
				ret=system (buff);
				if (ret) {
					printf ("Clean of %s intermediate files failed\n",a);
					printf ("Cpmmand was: %s\n",buff);
	            }
            }
		}
	}
  }

  return x;

}

/**
 * Print the usage message when executing the 4gl compiler.
 * Invoked autometically from inside getopt_long() when invalis option is encountered.
 */
static void
printUsage(char *argv[])
{
  printf("\n");
  printf("Aubit 4GL compiler usage: %s [options] -oOutFile.ext file.ext [file.ext ...]\n", argv[0]);
  printf("  Try -help for more.\n", argv[0]);
  printf("\n");
}

/**
 * Print the usage message when executing the 4gl compiler.
 */
static void
printUsage_help(char *argv[])
{
  /* FIXME: make sure we don't have conflict with GCC options - for pass-trough */
  /* FIXME: verify we have all options of 4glpc script here */

  printf("\n");
  printf("Aubit 4GL compiler usage: %s [options] -oOutFile.ext file.ext [file.ext ...]\n", argv[0]);
  printf("\n");
  printf("Extensions (.ext):\n");
  printf("  In files list, all .4gl files will be compield to C, other files passed to linker.\n");
  printf("  In -o flag, extendion will decide type of linking:\n");
  printf("    ao=object, aox=static library, aso=shared lib, 4ae=executable.\n");
  printf("\n");



  printf("Options:\n");
  printf("\n");
  printf("When A4GL_LEXTYPE=C :\n");
  printf("  -o[outfile] name outpout file\n");
/*
  printf("  -c compile to object(s), do not link\n");
  printf("  -o[outfile] compile to object(s), link into executable\n");
  printf("  -d compile to object(s), link into shared library\n");
  printf("  -l compile to object(s), link into static library\n");
*/

  printf("  (no flags) compile to C only\n");
  printf("\n");

  printf("When A4GL_LEXTYPE=PERL :\n");
  printf("  (no flags) compile to Perl only\n");
  printf("\n");

  printf("Other options :\n");
  printf("  -G     | --globals         : Generate the globals map file\n");
  printf("  -S     | --silent          : no output other then errors\n");
  printf("  -V     | --verbose         : Verbose output\n");
  printf("  -v     | --version         : Show compiler version and exit\n");
  printf("  -f     | --version_full    : Show full compiler version and details\n");
  printf("  -h|-?  | --help            : Show this help and exit\n");
  printf("  -tTYPE | --lextype         : output language, TYPE=C(default) or PERL\n");
  printf("  -s0|1  | --stack_trace 0|1 : Include the stack trace in file:\n");
  printf("                             : 0-Don't generate  1-Generate(Default)\n");
  printf("If 'outfile' was not specified, it is generated from first 4gl file name\n");
  printf("specified. All options that are not recognised, are passed to C compiler,\n");
  printf("if -c -o -d or -l was specified.\n");
  printf("\n");

//FIXME: move this to -vfull

#if ( defined(__MINGW32__) )
  printf("__MINGW32__ ");
#endif

#if ( defined (_WIN32) )
  printf("_WIN32 ");
#endif

#if ( defined(WIN32) )
  printf("WIN32 ");
#endif

#if ( defined(__CYGWIN__) )
  printf("__CYGWIN__ ");
#endif

  printf("\n");
  printf("\n");
}


/**
 * Treatment of an error ocurred in the parsing.
 *
 * It makes the proper treatment of an syntax error ocurred during the parsing
 *
 * @param s The string that contains the error
 */
void
yyerror (char *s)
{
char errfile[256];
FILE *f;
long ld;
char a;

  ld = memfile_ftell (yyin);
  sprintf (errfile, "%s.err", outputfile);
  a = 0;


/* Need a real fseek here */
  fseek (yyin, fpos, SEEK_SET);
  f = write_errfile (yyin, errfile, ld, yylineno);
  fprintf (f, "| %s%s (%s)", s, errbuff, yytext);
  write_cont (yyin);
  printf ("Error compiling %s.4gl - check %s.err\n", outputfile, outputfile);
  exit (2);
}

/************************* same function from fcompile:

FIXME: merge all yyerror() finction in libaubit4gl

void yyerror(char *s)
{
  char errfile[256];
  FILE *f;
  long ld;

  ld=buffpos();
  sprintf(errfile,"%s.err",outputfile);
  f=write_errfile(memfile_yyin,errfile,ld-1,yylineno);
  fprintf (f, "| %s", s);
  write_cont(memfile_yyin);
  printf("Error compiling %s.per - check %s.err (xline=%d yline=%d)\n",
	  outputfile,outputfile,lineno,yylineno
  );
  exit (2);
}

**************************************************************/


/**
 *  Adds the parameters to the error buffer in the assigned with yyerror.
 *
 *  The purpose is to using sprintf with fixed number of parameters.
 *  I Think that this only exists until we start using varargs.
 *
 * @param s The first parameter
 * @param p The second parameter
 * @param q The tird parameter
 */
void
adderr (char *s, char *p, char *q)
{
  sprintf (errbuff, s, p, q);
}


/**
 * Inform if we are just parsing the globals
 *
 * @return
 *   - 1 : if we are just doing globals
 *   - 0 : otherwise
 */
int
only_doing_globals (void)
{
  if (globals_only)
    return 1;
  return 0;
}

/**
 * Assign a value into the global flag that indicate if the compiler should
 * generate function call stack information.
 *
 * @param _genStackInfo The vlaue to assign to the flag
 */
void
setGenStackInfo(int _genStackInfo)
{
  genStackInfo = _genStackInfo;
}

/**
 * Check the value of the global flag that indicate if the compiler should
 * generate function call stack information.
 *
 * @param _genStackInfo The vlaue to assign to the flag
 */
int
isGenStackInfo(void)
{
  return genStackInfo;
}


/**
 *
 *
 * @param s
 */
void
set_yytext(char *s)
{
	strcpy(yytext,s);
}


#define ANSI_MODE_IGNORE 0
#define ANSI_MODE_WARN   1
#define ANSI_MODE_ERROR  2


static int get_ansi_mode(void ) {
static int ansi_mode=-1;
	if (ansi_mode==-1) {

		ansi_mode=ANSI_MODE_IGNORE;

		if (isyes(acl_getenv("ANSI_WARN"))) {
			ansi_mode=ANSI_MODE_WARN;
		}

		if (isyes(acl_getenv("ANSI_ERROR"))) {
			ansi_mode=ANSI_MODE_ERROR;
		}
	}
	return ansi_mode;
}

/**
 * Warn about syntax which is a violation of ANSI 
 *
 * @param s - string containing a description of the warning
 * @param severity - 0 for only a warning  (where the compiler could correct)
 *                   1 for an error (where the compiler can't fix it to ansi)
 *
 */
void ansi_violation(char *s,int severity) {
char buff[256];
	switch (get_ansi_mode()) {
		case ANSI_MODE_IGNORE: return ;
		case ANSI_MODE_WARN:   
				if (severity==0) {
					printf("Warning : Corrected ANSI violation : %s @ line %d\n",s,yylineno); 
				} else {
					printf("Warning : ANSI violation : %s @ line %d\n",s,yylineno); 
				}
					return ;
	}
// Must be an ansi error....

	if (severity==0) {
	 	printf("Warning : Corrected ANSI violation : %s @ line %d\n",s,yylineno) ; return ;
	}
	sprintf(buff,"Error: ANSI violation - %s",s);
	yyerror(buff);
}

/* ==================================== EOF =============================== */

