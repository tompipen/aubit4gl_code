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
# $Id: compile.c,v 1.82 2005-04-22 06:03:23 mikeaubury Exp $
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


#define ANSI_MODE_IGNORE 0
#define ANSI_MODE_WARN   1
#define ANSI_MODE_ERROR  2
#define yydebug a4gl_yydebug

/* -------- static --------- */
static char outputfile[132];		/** The output file name */
static int genStackInfo = 1;


/* -------- extern --------- */
/*FIXME - move in "a4gl_4glc_int.h"*/
extern char *outputfilename;	/* Defined in libaubit4gl */
extern int globals_only;	/* defined in map.c */
extern char infilename[132];
extern FILE *yyin;
extern int glob_only;
extern long fpos;					/** current file position for direct fseek */
extern int yylineno;

/* -------- unknown --------- */
int compiling_system_4gl = 0;
char gcc_exec[128];
char pass_options[1024] = "";
int clean_aftercomp = 0;	/* clean intermediate files after compilation */
char currinfile_dirname[1024] = "";	/* path to 4gl file we are currently compiling - used when compiling global files */
char errbuff[1024] = "";
char yytext[1024] = "";
int globals_only = 0;
int yyin_len;
char *default_database = 0;

#ifdef YYDEBUG
extern int yydebug;		/* defined in y.tab.c _IF_ -DYYDEBUG is set */
#else
int yydebug;			/* if !-DYYDEBUG, we need to define it here */
#endif


  char extra_ccflags[1024] = "";


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

static int compile_4gl (int compile_object, char a[128], char incl_path[128],
			int silent, int verbose, char output_object[128],int win_95_98,
			char informix_esql[128], char pg_esql[128], char extra_ccflags[1024],
			int preserve_warn, int each_obj_to_so, int put_object_in_currdir,
			char *all_objects);
			
			
void printUsage (char *argv[]);
static void printUsage_help (char *argv[]);
int initArguments (int argc, char *argv[]);
void setGenStackInfo (int _genStackInfo);
//void set_yytext (char *s);
int has_default_database (void);
char *get_default_database (void);
int A4GL_db_used(void );
static void add_module_error(int n,char *s) ;



static char *get_rdynamic(void ) {
char *ptr;
ptr=acl_getenv("A4GL_RDYNAMIC");
if (ptr==0) return "-rdynamic";
if (strlen(ptr)==0) return "-rdynamic";

return ptr;
}


struct s_module_error *module_errors=0;
int module_errors_cnt=0;



/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Parse the comand line arguments and acording to the passed values
 * set(s) the properties.
 *
 * see
 *		http://www.gnu.org/software/gengetopt
 *		http://www.gnu.org/manual/glibc-2.2.3/html_node/libc_516.html
 *        for inspiration.
 *
 * @param argc The argument count
 * @param argv The argument values
 */
int
initArguments (int argc, char *argv[])
{
  int i;
/* extern char *optarg; in /usr/include/getopt.h */
/*  int this_option_optind = optind ? optind : 1; */
  int option_index = 0;
  int compile_object = 0;
  int compile_exec = 0;
  int compile_so = 0;
  int preserve_warn = 0; // should we preserve warnings by moving .err file to .warn file when no error occured in compilation
  int compile_lib = 0;
  int win_95_98 = 0;
  int shell_is_bash = 0;
  int si;
  int x = 0;
  int ret;
  int index;
  int silent = 0;
  int verbose = 0;
  int todo = 0;
  int c_to_o = 0;
  int flength = 0;
  int each_obj_to_so = 0; /* compile each 4gl module to shared object (-shared) */
  int put_object_in_currdir = 1; /* Make objects in curent dir regardless if input file had path */
  int input_objects_cnt = 0; /* count of how many input objects there are on command line */
  
  char *chrptr;
  char opt_list[40] = "";
  char mv_cmd[40] = "";  
  char a[128] = "";
  char b[128] = "";
  char c[128] = "";
  char ext[128] = "";
  char incl_path[1028] = "";
  char l_path[1028] = "";
  char l_libs[1028] = "";
  char buff[4000] = "";
  //char all_objects[4000] = "";
  char *all_objects = malloc(4000);
  
  char extra_ldflags[1024] = "";

  static FILE *filep = 0;
  static char output_object[128] = "";
  static struct option long_options[] = {
    {"globals", 0, 0, 'G'},
    {"namespace", 1, 0, 'N'},
    {"stack_trace", 1, 0, 's'},
    {"help", 0, 0, '?'},
    {"silent", 0, 0, 'S'},
    {"debug", 0, 0, 'g'},
    {"shared", 0, 0, 'H'},		//compile each 4gl module to shared object
    {"as-dll", 0, 0, 'h'},		//link all 4gl modules on command line into shared library
    {"verbose", 0, 0, 'V'},
    {"version", 0, 0, 'v'},
    {"version_full", 0, 0, 'f'},
    {"lextype", 0, 0, 't'},
    {"keep", 0, 0, 'k'},
    {"keep-warn", 0, 0, 'w'},	
    {"clean", 0, 0, 'K'},
    {"database", 1, 0, 'd'},
    {"system4gl", 0, 0, '4'},
    {0, 0, 0, 0},
  };
// ========================================================================
// WARNING!!! DO NOT FORGET TO ADJUST opt_list BELOW WHEN ADDING OPTIONS!!!
// Also please update the help descriptions
// ========================================================================
  struct skip_param
  {
    char param[128];
  };
  struct skip_param s_param[128];
  int skip_param_idx = 0;
  int skip_cnt = 0, skipit = 0;
  char informix_esql[128] = "";
  char pg_esql[128] = "";
  char pg_esql_libs[128] = "";  
  strcpy (all_objects,"");
  
//Cant use shell scripts on Windows: esql_wrap ecpg_wrap
//Cant use INFORMIXDIR to locate esqlc because of the CSDK subdir nonsense
//But if I try to use full path, I get "'e:/Program' is not recognized as an 
// internal or external command" even tho ther is NO single quotes on command
//line - I susspect something it translating quotes (maybe esqlc?) 
//	sprintf (informix_esql, "\"%s\" ",acl_getenv ("IFMX_ESQLC"));
	sprintf (informix_esql, "esql ");
	#if ( defined(WIN32) )
		sprintf (informix_esql, "%s -n ",informix_esql);
	#endif
	sprintf (pg_esql, "\"%s/bin/ecpg\"",acl_getenv ("POSTGRESDIR"));  

	sprintf (pg_esql_libs, "-L\"%s/lib\" -lecpg -lecpg_compat -lpgtypes -lpq -lm",
		acl_getenv ("POSTGRESDIR"));	
                            	
#ifdef DEBUG
  A4GL_debug ("Parsing the comand line arguments\n");
  A4GL_debug ("Arg 0 set to >%s<", A4GL_getarg0 ());
  A4GL_debug ("Compiling to %s code\n",acl_getenv ("A4GL_LEXTYPE"));
#endif

	/* set valid options for getopt_long depending on putput language*/
	if (strcmp (acl_getenv ("A4GL_LEXTYPE"), "C") == 0 ||
      	strcmp (acl_getenv ("A4GL_LEXTYPE"), "EC") == 0) {
		strcpy (opt_list, "G4s:N:kwKco::l::W::L::I::?hHSgVvftD:d:");
    } else if (strcmp (acl_getenv ("A4GL_LEXTYPE"), "PERL") == 0) {
		strcpy (opt_list, "G4s:N:?hSgVvftd:");
    } else /* all other A4GL_LEXTYPE types*/ {
		strcpy (opt_list, "G4s:N:kwKco::l::L::?hSgVvftd:");
    }
	sprintf (mv_cmd, "%s", acl_getenv ("A4GL_MV_CMD"));
	if (! strcmp (acl_getenv ("COMSPEC"), "") == 0) {
		//On Windows
		if (! strcmp (acl_getenv ("NUMBER_OF_PROCESSORS"), "") == 0) {
			//printf ("On Windows NT/W2K/XP\n");			
			/*
			On NT, W2K or XP pro (Does home XP also have it?)
			if not use COMSPEC='D:\WINNT\system32\cmd.exe'
			if comspec is cmd.exe, we are on NT
			On W2K pro OS=Windows_NT
			*/
		} else {
			//we are on W95 or 98
			//printf ("On Windows 95/98\n");
			win_95_98=1;
		}
		//printf ("SH=%s\n",acl_getenv ("SH"));
		if ((! strcmp (acl_getenv ("SH"), "") == 0) || (! strcmp (acl_getenv ("SHELL"), "") == 0)) {
			shell_is_bash=1;
			//printf ("yes, shell_is_bash=%d\n"),shell_is_bash;
			//does not seem to work
			//A4GL_setenv("A4GL_MV_CMD","mv",1);
			//NOTE: Windows 'move' cmd is a cmd.exe built-in and will
			//only be available when cmd.exe is shell - NOT when bash is a shell
			sprintf (mv_cmd, "mv");
		}
	}
	
  /* this call will intercept -v and -vfull arguments, that can be only
     arguments on command line anyway */
	if (argc > 1) {
		A4GL_check_and_show_id ("4GL Compiler", argv[1]);
	} else {
		printUsage (argv);
		exit (0);
    }

	while ((i = getopt_long (argc, argv, opt_list,
			   /*  long_options, &option_index)) != -1)*/
			   long_options, &option_index)) != EOF) {
      switch (i) {
		/* 
			TODO = add options:
			* override language output set by A4GL_LEXTYPE
			* override db connectivity set by A4GL_SQLTYPE
			* Compile to C only
			* Run copiled C code with CINT
		*/

    /************************/
	case 'c':		/* Compile resulting C file(s) to object */
		/* 
			this is more or less meaningless, and is here for compatibility with
			C compiler style flags, because we decide linking tipe based on
			extension of the target object.
	   */
		#ifdef DEBUG
			A4GL_debug ("Got -c\n");
		#endif
		compile_object = 1;
		break;

    /************************/
	case 'h':		/* Link resulting object(s) to shared library (--as-dll) */
	  /* 
	  	this is more or less meaningless, and is here for compatibility with
	    C compiler style flags, because we decite linking tipe based on
		extension of the target object.
	   */
	   compile_so = 1;
	   compile_exec = 0;
	   break;;

    /************************/
	case 'H':		/* compile each 4gl module to shared object (--shared) */
		each_obj_to_so=1;
		break;;
	   
	   
    /************************/
	case 'g':		/* -g --debug  (for C compiler flags compatibility */
		//todo: pass -g to C compiler
		break;;

    /************************/
	case 'o':		/* compile and optionally Link resulting object(s) */
		#ifdef DEBUG
		  A4GL_debug ("Got -o flag\n");
		#endif
		sprintf (output_object, "%s", (NULL == optarg) ? "" : optarg);
		if (strcmp (output_object, "") == 0) {
			/* if required parameter to the -o flag was not immediately
	         nex to the flag, and returned in optarg, maybe it was spcified as
	         next parameter, separated from -o flag with space(s):
			*/
			sprintf (output_object, "%s",(NULL == argv[optind]) ? "" : argv[optind]);
			if (strcmp (output_object, "") != 0) {
				sprintf (s_param[skip_param_idx].param, "%s", output_object);
				skip_param_idx++;
			}
		}
		if (strcmp (output_object, "") != 0) {
			A4GL_bname (output_object, a, b);
			strcpy (ext, ".");
			strcat (ext, b);
			/*A4GL_debug ("%s %s %s", b, acl_getenv ("A4GL_EXE_EXT"), ext);*/
			//determine what type is file specified with -o
			if ((strcmp (ext, acl_getenv ("A4GL_OBJ_EXT")) == 0) ||
				(strcmp (ext, ".o") == 0)) { 
				//.ao or .o - static object (no linking)
				compile_object = 1;
			} else if ((strcmp (ext, acl_getenv ("A4GL_EXE_EXT")) == 0) ||
				(strcmp (ext, ".exe") == 0)) { 
				//.4ae or .exe - executable
				compile_object = 1;
				compile_exec = 1;
			} else if ((strcmp (ext, acl_getenv ("A4GL_LIB_EXT")) == 0) ||
				(strcmp (ext, ".a") == 0)){ 
				//.aox or .a - static library (multiple static objects in one file)
				compile_object = 1;
				compile_lib = 1;
			} else if ((strcmp (ext, acl_getenv ("A4GL_SOB_EXT")) == 0) ||
				(strcmp (ext, ".la") == 0)){ 
				//.aso or .la - shared object (object compiled with -PIC 
				//to be linked in shared library)
				//Probably obsolete since by default all GCC compiled objects
				//since GCC V3 are position independent by default
				compile_object = 1;
				compile_lib = 1;
				/* Is that right?
					compile_lib means that we rare to link all created objects into
					shared library. This is to be eddect of --as-dll flag
					--as-dll
				*/
					
				
				
				//TODO: add -PIC to CFLAGS
				// I snot all code position indepentent in GCC by default?
			} else if ((strcmp (ext, acl_getenv ("A4GL_SOL_EXT")) == 0) ||
				(strcmp (ext, ".so") == 0) ||
				(strcmp (ext, ".dll") == 0)) { 
				//.asx or .so or .dll- shared library
				compile_object = 1;
				compile_so = 1;
				compile_exec = 0;
			} else {
				//compile_so can be set with --shared flag allready
				if (! compile_so) { 
					/* we will have to assume executable when there is no
					extension, as this is a common practice on UNIX and 
					also C compilers make executable by default*/
					A4GL_debug
					("assuming executable, there was no extension on -o parameter and no --shared flag");
					compile_object = 1;
					compile_exec = 1;
				}
			}
		} else {
			printf ("Error: -o flag specified with no parameter\n");
			printf ("optind=%s\n", argv[optind]);
			printf ("option_index=%s\n", argv[option_index]);
			exit (5);
		}
		break;

    /************************/
	case '4':       /* System 4gl module -  disables function name checking so it can 
					compile functions for use with the aubit4gl library  */
		compiling_system_4gl = 1;
		break;

	/************************/
	case 'W':		/* Extra flags to C linker (-Wl,--export-dynamic etc.)*/
		#ifdef DEBUG
	  		A4GL_debug ("Pass trough option: %s\n", optarg);
		#endif
		sprintf (extra_ldflags,"%s -W%s ",extra_ldflags,optarg);
		break;

	/************************/
	case 'l':		/* Extra libraries to link with; -l flag*/
		#ifdef DEBUG
	  		A4GL_debug ("Pass trough option: %s\n", optarg);
		#endif
		sprintf (extra_ldflags,"%s -l%s ",extra_ldflags,optarg);
		break;
	case 'D':		/* Define C pre-rocesor variable (-D flag) */
		#ifdef DEBUG
	  		A4GL_debug ("Pass trough option: %s\n", optarg);
		#endif
		sprintf (extra_ldflags,"%s -D%s ",extra_ldflags,optarg);
		break;

    /************************/
	case 'L':		/* LD -L flags for linking extra libraries*/
		#ifdef DEBUG
			A4GL_debug ("Pass trough option: %s\n", optarg);
		#endif
		sprintf (extra_ldflags,"%s -L\"%s\" ",extra_ldflags,optarg);
		break;

    /************************/
	case 'I':		/* CC/ESQL -I flags for include paths*/
		#ifdef DEBUG
		  A4GL_debug ("Pass trough option: %s\n", optarg);
		#endif
		//WARNING: gcc don't like space between -I and qupted strings
		sprintf (extra_ccflags,"%s -I\"%s\" ",extra_ccflags,optarg);
		break;

    /************************/
	case 'd':		/* Name of the database to compile against - for things*/
					/* like DEFINE ... LIKE ...*/
	  printf ("\n\nDB=%s\n\n", optarg);
	  default_database = strdup (optarg);
	  break;


    /************************/
	case 'N':		/* User specified namespace prefix*/
	  if (optarg == 0)
	    optarg = "";
	  A4GL_debug ("Using specified namespace : %s\n", optarg);
	  set_namespace (optarg);
	  break;

    /************************/
	case 'G':		/* generate Globals file only */
	  globals_only = 1;
	  break;

    /************************/
	case 's':		/* Stack information inclusion */
	  si = atoi (optarg);
	  if (si != 0 && si != 1)
	    {
	      printUsage (argv);
	      exit (1);
	    }
	  setGenStackInfo (si);
	  break;

    /************************/
	case '?':		/* Help */
	  printUsage_help (argv);
	  exit (0);

    /************************/
	case 'k':		/* do not clean intermedate files (--keep) */
	  clean_aftercomp = 0;
	  break;

    /************************/
	case 'w':		/* (--keep-warn) Keep warnings outout file if created, 
					by renaming .err files to .warn file  */
		#ifdef DEBUG
			A4GL_debug ("Got -c\n");
		#endif
		preserve_warn = 1;
		break;

    /************************/
	case 'K':		/* clean intermedate files when done (--clean) */

		#ifdef DEBUG
		  A4GL_debug ("Got --clean\n");
		#endif
	  clean_aftercomp = 1;
	  break;

    /************************/
	case 'S':		/* Silent */
	  silent = 1;
	  verbose = 0;
	  break;

    /************************/
	case 'V':		/* Verbose */
	  verbose = 1;
	  silent = 0;
		#ifdef DEBUG
		  A4GL_debug ("Turned on verbose mode\n");
		#endif
		sprintf (informix_esql, "%s -dcmdl ", informix_esql);
		//TODO: add -verbose to GCC and ecpg 
	  break;

    /************************/
	case 'v':		/* Show version - needed for long opts */
	  A4GL_check_and_show_id ("4GL Compiler", "-v");
	  exit (0);

    /************************/
	case 'f':		/* Show version - needed for long opts */
	  A4GL_check_and_show_id ("4GL Compiler", "-vfull");
	  exit (0);

    /************************/
	default:		/* Everything else we did not define - should
				   never happen since getopt_long() should reject
				   all flags not defined in opt_list
				 */
	  printf ("Invalid option=%s\n", argv[optind]);
	  printf ("Invalid option=%s\n", argv[option_index]);
	  exit (1);
	}
    }

	if (optind >= argc) {
		printf ("No file name defined\n");
		printUsage (argv);
		exit (1);
    }

#if YYDEBUG != 0
	#ifdef DEBUG
	  A4GL_debug ("YYDEBUG was set while compiling\n");
	#endif
	#ifdef YYPRINT
		#ifdef DEBUG
		  A4GL_debug ("YYPRINT was set while compiling\n");
		#endif
	#endif
#endif

	if (strcmp (acl_getenv ("YYDEBUG"), "") != 0) {
		#ifdef DEBUG
	    	A4GL_debug ("Yacc Debugging on\n");
		#endif
		yydebug = 1;
    } else {
		yydebug = 0;
    }

	A4GL_init_datatypes ();

	/* prepare CC flags */
	sprintf (incl_path, "-I\"%s/incl\" ",acl_getenv ("AUBITDIR"));
	chrptr = acl_getenv ("GTK_INC_PATH");	/*GTK_INC_PATH is set in aubitrc by Autoconf*/
	/* NOTE: when GTK_INC_PATH was not set, I got core dumps on Windows - this should not happen */

	rm_quotes (chrptr);
	strcat (incl_path, chrptr);
	strcat (incl_path, " ");
	sprintf (l_path, "-L\"%s/lib\" ",acl_getenv ("AUBITDIR"));
	strcpy (l_libs, acl_getenv ("A4GL_LINK_LIBS"));
	
	//what about -g and -O flags?
	strcpy (gcc_exec, acl_getenv ("A4GL_C_COMP"));

	/* ============================================== */
	for (index = optind; index < argc; index++) {
		for (skip_cnt = 0; skip_cnt < skip_param_idx; skip_cnt++) {
			if (strcmp (s_param[skip_cnt].param, argv[index]) == 0) {
				/* skip this param - it was passed as value for an command 
				line flag (like -o) */
				skipit = 1;
				break;
			}
        }

		if (skipit) {
			skipit = 0;
			continue;
        }

		outputfilename = outputfile;	/* C file name - set where ? */
		strcpy (c, argv[index]);
		A4GL_bname (c, a, b);
		/* ============================================== */
		if (strcmp (b, "o") == 0) {
			//not sure about this...
			//check if .o or .ao file exists
			//if not, check if .c file exists, and compile it
		}
		/* ============================================== */
		if (strcmp (b, "c") == 0) {
			input_objects_cnt++;
			//make .o from .c
			#ifndef __MINGW32__
			  sprintf (buff, "%s %s -c -o %s.o %s %s",
				   gcc_exec, c, a, incl_path, pass_options);
			#else
			  sprintf (buff, "%s -mms-bitfields %s -c -o %s.o %s %s",
				   gcc_exec, c, a, incl_path, pass_options);
			#endif

			if (verbose){ printf ("%s\n", buff); }
			if ( ! win_95_98 ) {
				/*this apparently works on NT, but not on W98:*/
				sprintf (buff, "%s > %s.c.err 2>&1", buff, a);
			} else {
				sprintf (buff, "%s > %s.c.err", buff, a);
			}
			#ifdef DEBUG
		  		A4GL_debug ("Runnung %s", buff);
			#endif
			ret = system (buff);
			/*see function system_run() in fglwrap.c*/
			if (ret) {
				printf ("Error compiling %s.c - check %s.c.err\n", a, a);
				printf ("Failed command was: %s\n", buff);
				/*fixme: show err file*/
				exit (ret);
			} else {
				sprintf (all_objects, "%s %s.o ",all_objects,a);
				c_to_o=1;
				/* TODO: if -o specified .o, then we are done - exit here */
			}
			continue;
		}
		/* ============================================== */
		if (strcmp (b, "4gl") == 0) {
			input_objects_cnt++;
			strcpy (outputfilename, a);
			
/*now done in compile_4gl - remove			
			if (each_obj_to_so) {
				sprintf (all_objects, "%s %s%s ",all_objects,a,
					acl_getenv ("A4GL_SOB_EXT"));
			} else {
				sprintf (all_objects, "%s %s%s ",all_objects,a,
					acl_getenv ("A4GL_OBJ_EXT"));				
			}
*/			
//aaaaaa
//			printf ("all_objects=%s\n", all_objects);

			strcpy (infilename, c);
			#ifdef DEBUG
				A4GL_debug ("Compiling %s\n", infilename);
			#endif
			todo++;
			x = compile_4gl (compile_object, a, incl_path, silent, verbose, 
		  			output_object, win_95_98,informix_esql, pg_esql, extra_ccflags,
					preserve_warn, each_obj_to_so, put_object_in_currdir,
					all_objects);
///aaaaaaa
//			printf ("after return all_objects=%s\n", all_objects);
			//exit (1);
			
			if (x) {
				printf ("Exit code is: %d\n", x);
				/*FIXME: if I use x, I get 0 on the shell?????*/
				/*exit (x);*/
				exit (99);
			}
			continue;
		} else {
			/* just pass stuff you don't understand to CC */
			#ifdef DEBUG
				A4GL_debug ("Pass trough option: %s\n", c);
			#endif
			strcat (pass_options, c);
			strcat (pass_options, " ");
		}
	} //end for

    /*
        if (interpreter_run)
        {
			setup environment for "CINT" C intrpreter and
			run C file specified as parameter to this script using "cint" executable

            // add A4GL_CINT to aubitrc from configure so we know if we have 
			// Cint on the system and where
			if acl_getenv ("A4GL_CINT") != "no"
            {
				export CINTSYSDIR=/usr/local/cint
				export PATH=$PATH:$CINTSYSDIR
				cint -p -I$AUBITDIR/incl -l$AUBITDIR/lib/libA4GL_cint.so $1.c
            }
        }
    */

	if (!todo)  {
		if (verbose) {printf ("Linking only - no 4gl input files.\n");}
		#ifdef DEBUG
			A4GL_debug ("Linking only - no 4gl input files.\n");
		#endif
	}

	if (input_objects_cnt == 1) {
		/* there was only one input file (.4gl/.c) on command line 
			If output object is not an executable, then we are done.
			
			 what would a point be in making so or lib from one object?
			 If user wants .so, then he can use --shared flag and get 
			 so compiled directly form that object, without needing a linkling 
			 stage - which is meaningfull only if more then one object needs
			 to be linked or if executable needs to be created
			
			 Beside being pointless, we need to prevent this from happening,
			 otherwise we might have a sittuation where we allready created
			 x.so and the ask linker to make x.so form x.so
		 */
		if (compile_exec == 0) {
			 if (compile_so || compile_lib) {
				 //unless -o was different from input
				 //printf ("output_object=%s\n",output_object);
				 //printf ("all_objects=%s\n",all_objects);
				 if (strcmp (all_objects, output_object) == 0) {
					if (verbose) {printf ("WARNING: compile_so or _lib active with only one input. Disbled.\n");}
					A4GL_debug ("WARNING: compile_so or _lib active with only one input. Disbled.");
					compile_so=0;
					compile_lib=0;
					if (verbose) {printf ("Single input/output not exec - we are done.\n");}
					A4GL_debug ("Single input/output not exec - we are done.");
				 } else {
					// output specified with -o is not the same we allready created - 
					// so we must go troug linking stage even with one object...
				 }
			 }
		}
	}
	
	
#ifdef DEBUG
	A4GL_debug ("gcc_exec=%s", gcc_exec);
	A4GL_debug ("all_objects=%s", all_objects);
	A4GL_debug ("output_object=%s", output_object);
	A4GL_debug ("l_path=%s", l_path);
	A4GL_debug ("l_libs=%s", l_libs);
	A4GL_debug ("pass_options=%s", pass_options);
	A4GL_debug ("extra_ldflags=%s", extra_ldflags);
	A4GL_debug ("incl_path=%s", incl_path);
#endif

	if (compile_exec) {
		A4GL_debug ("Linking exec\n");
		if ((strcmp (acl_getenv ("PRINTPROGRESS"), "Y") == 0) || (verbose)) {
			printf("Linking exec\n");fflush(stdout);
			//This was \r not \n for some reason
		}
	#if ( ! defined (__MINGW32__) && ! defined (__CYGWIN__) )
	      /*We are on UNIX*/
		if (strcmp (acl_getenv ("A4GL_LEXTYPE"), "EC") == 0){
			/* When using Embedded C output, we need to run appropriate ESQL/C
			compiler to do the linking */
			if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "POSTGRES") == 0) {
				sprintf (buff, 
				"%s %s %s -o %s %s %s %s %s %s -L\"%s/lib\"",
					gcc_exec, get_rdynamic(),all_objects, output_object, l_path, 
					l_libs, pass_options, extra_ldflags,pg_esql_libs,
					acl_getenv ("POSTGRESDIR"));
		    }
			else if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "SAPDB") == 0)
			{
				sprintf (buff, "%s %s %s -o %s %s %s %s %s ",
			       acl_getenv ("A4GL_SAPDB_ESQLC"), get_rdynamic(),all_objects, output_object, l_path, l_libs,
			       pass_options, extra_ldflags);
			}
			else if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "QUERIX") == 0)
			{
				  sprintf (buff, "esqlc %s %s -o %s %s %s %s %s ",get_rdynamic(),
			       all_objects, output_object, l_path, l_libs,
			       pass_options, extra_ldflags);
			}
			else /*"A4GL_LEXDIALECT"="INFORMIX" - default*/
			{
				//strcat (l_libs, " -lESQL_INFORMIX");  
				sprintf (buff, "%s %s %s -o %s %s %s %s %s ",
				   informix_esql,get_rdynamic(),
			       all_objects, output_object, l_path, l_libs,
			       pass_options, extra_ldflags );
            }
	    } else { /* Pure C compiler output */
		  sprintf (buff, "%s %s %s -o %s %s %s %s %s",
		       gcc_exec, get_rdynamic(),all_objects, output_object, l_path, l_libs,
		       pass_options, extra_ldflags);
        }
	#else /*We are on Windows*/
		if (strcmp (acl_getenv ("A4GL_LEXTYPE"), "EC") == 0){
            /* When using Embedded C output, we need to run appropriate ESQL/C
            compiler to do the linking */
			if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "POSTGRES") == 0) {
				//WARNING: link libs must be at the end
				sprintf (buff, "%s %s %s -o %s %s %s %s %s %s",
			       gcc_exec, get_rdynamic(), all_objects, output_object, l_path, 
				   pass_options, extra_ldflags, l_libs,pg_esql_libs);
		    } else if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "SAPDB") == 0) {
				sprintf (buff, "%s %s %s -o %s %s %s %s %s ",
			       acl_getenv ("A4GL_SAPDB_ESQLC"), get_rdynamic(),all_objects, output_object, l_path, l_libs,
			       pass_options, extra_ldflags);
			} else if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "QUERIX") == 0) {
				  sprintf (buff, "esqlc %s %s -o %s %s %s %s %s ",get_rdynamic(),
			       all_objects, output_object, l_path, l_libs,
			       pass_options, extra_ldflags);
			} else /*"A4GL_LEXDIALECT"="INFORMIX" - default*/ {
				/* cant use esql on Windows for linking, since it will try 
					to use MSVC C compiler and not MinGW GCC we want
					WARNING: link libs must be at the end
					WARNING: when using GCC on Windows we need to link with 
					.dll's in /bin - NOT with .lib's in /lib (as 'esql -libs' 
					will return)
					WARNING: on binary installation there will be no Autoconf
					and therefore no IFX_LIBS
				*/
				sprintf (buff, 
			  	"%s -mms-bitfields -Wl,--export-all-symbols %s %s -o %s %s %s %s %s",
				gcc_exec, all_objects, acl_getenv ("IFX_LIBS"),output_object, 
				l_path, pass_options, l_libs, extra_ldflags);
            }
	    } else { /* Pure C compiler output */
	      /*WARNING: libs must be at the end*/
	      sprintf (buff, "%s %s -o %s %s %s %s %s",
		       gcc_exec, all_objects, output_object, l_path, pass_options,
		       l_libs, extra_ldflags);
        }
	#endif //Windows/UNIX
    } //compile_exec

	/* ----- make static library by linking static objects together ---- */
	/* Actually...
		gcc and esql don't know how to do that - only thing I can think 
		of that can make archive of static libraries is 'ar'.
		So why do we want to make library of static objects, and not a 
		shared library anyway?
	*/
  if (compile_lib) {
	//override  
	#ifdef DEBUG
		A4GL_debug ("Got compile_lib - changing to compile_so");
	#endif
	compile_lib=0;
	compile_so=1;
  }
  if (compile_lib) {
	if ((strcmp (acl_getenv ("PRINTPROGRESS"), "Y") == 0) || (verbose)) {
		printf("Linking\n");fflush(stdout); //\r
	}
	#ifndef __MINGW32__ /* UNIX */
		A4GL_debug ("Linking static library\n");
		if (strcmp (acl_getenv ("A4GL_LEXTYPE"), "EC") == 0){
            /* When using Embedded C output, we need to run appropriate ESQL/C
            compiler to do the linking */
/*FIXME:*/
			if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "POSTGRES") == 0) {
				sprintf (buff, "%s %s %s -o %s %s %s %s %s ",
			       pg_esql, get_rdynamic(), all_objects, output_object, l_path, 
				   l_libs, pass_options, extra_ldflags);
		    } else if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "SAPDB") == 0) {
				sprintf (buff, "%s %s %s -o %s %s %s %s %s ",
			       acl_getenv ("A4GL_SAPDB_ESQLC"), get_rdynamic(),all_objects, output_object, l_path, l_libs,
			       pass_options, extra_ldflags);
			} else if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "QUERIX") == 0) {
				sprintf (buff, "esqlc %s %s -o %s %s %s %s %s ",get_rdynamic(),
			       all_objects, output_object, l_path, l_libs,
			       pass_options, extra_ldflags);
			} else /*"A4GL_LEXDIALECT"="INFORMIX" - default*/ {
				//strcat (l_libs, " -lESQL_INFORMIX");
				sprintf (buff, "%s %s %s -o %s %s %s %s %s ",
					informix_esql,get_rdynamic(),
					all_objects, output_object, l_path, l_libs,
					pass_options, extra_ldflags);
            }
/*FIXME ENDS*/
	    } else { /* Pure C compiler output */
			sprintf (buff, "%s -static %s -o %s %s %s -shared %s %s",
		    	gcc_exec, all_objects, output_object, pass_options, l_path,
				l_libs, extra_ldflags);
        }
	#else /* Windows - MinGW */
	      /* On Windows, there can be no unresolved dependencies at link time - so we allways must
	         link with libaubit4gl - but we do not make any static Aubit libraries any more, so we
	         must link with .dll - meaning that we must force shared linking even when user specified
	         static flag */
	      A4GL_debug ("Static linking specified - forcing shared linking on Windows\n");
	      compile_lib = 0;
	      compile_so = 1;
	#endif /* UNIX or Windows */
    }

  if (compile_so) {
	if ((strcmp (acl_getenv ("PRINTPROGRESS"), "Y") == 0) || (verbose)) {
		printf("Linking Shared Library\n");fflush(stdout); //\r
	}
	A4GL_debug ("Linking shared library\n");
	#ifndef __MINGW32__ /* UNIX */
		if (strcmp (acl_getenv ("A4GL_LEXTYPE"), "EC") == 0){
            /* When using Embedded C output, we need to run appropriate ESQL/C
            compiler to do the linking */
/*FIXME:*/
			if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "POSTGRES") == 0) {
				sprintf (buff, 
				"%s -shared %s %s -o %s %s %s %s %s %s -L\"%s/lib\"",
					gcc_exec, get_rdynamic(),all_objects, output_object, l_path, 
					l_libs, pass_options, extra_ldflags,pg_esql_libs,
					acl_getenv ("POSTGRESDIR"));

				/*		
				sprintf (buff, "%s %s %s -o %s %s %s %s %s ",
			       pg_esql, get_rdynamic(), all_objects, output_object, l_path, 
				   l_libs, pass_options, extra_ldflags);
				  */
		    } else if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "SAPDB") == 0) {
				sprintf (buff, "%s %s %s -o %s %s %s %s %s ",
			       acl_getenv ("A4GL_SAPDB_ESQLC"), get_rdynamic(),all_objects, output_object, l_path, l_libs,
			       pass_options, extra_ldflags);
			} else if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "QUERIX") == 0) {
				  sprintf (buff, "esqlc %s %s -o %s %s %s %s %s ",get_rdynamic(),
			       all_objects, output_object, l_path, l_libs,
			       pass_options, extra_ldflags);
			} else /*"A4GL_LEXDIALECT"="INFORMIX" - default*/ {
					//strcat (l_libs, " -lESQL_INFORMIX");
				  sprintf (buff, "%s -Wl,-shared %s %s -o %s %s %s %s %s ",
				  	informix_esql,get_rdynamic(),
					all_objects, output_object, l_path, l_libs,
					pass_options, extra_ldflags);
            }
/*FIXME ENDS*/
	    } else { /* Pure C compiler output */
			sprintf (buff, "%s -shared %s -o %s %s %s %s %s %s",
		    	gcc_exec, all_objects, output_object, l_path, l_libs,
				pass_options, extra_ldflags, incl_path);
				/*FIXME: add incl_path only if there are .c files in all_objects*/
				/*gcc -shared  -o  -L/usr/src/aubit/aubit4glsrc/lib -laubit4gl helplib.c a4gl_xxhelp.afr.c -o ../libHELP_std.dll   -I/usr/src/aubit/aubit4glsrc/incl -I/usr/include/gtk-2.0 -I/usr/lib/gtk-2.0/include -I/usr/include/atk-1.0 -I/usr/include/pango-1.0 -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include*/
        }
	#else /* MinGW */
	      /*
	         NOTE: we are acutally making a Window dll here.
	         WARNING: libs must be at the end
	         WARNING: without -L ld on Windows won't find it's own ass!!!! Not even in curren directory!!!
	       */

	      /*FIXME: add incl_path only if there are .c files in all_objects*/
	      sprintf (buff,
		       "%s -L. -shared -Wl,--out-implib=%s.a -Wl,--export-all-symbols %s -o %s %s %s %s %s %s %s",
		       gcc_exec, output_object, all_objects, output_object,
		       l_path, extra_ccflags, incl_path, pass_options, extra_ldflags, l_libs);
	#endif /* UNIX or MinGW */
    }

	if (compile_exec || compile_so || compile_lib) {
		if (verbose) { printf ("%s\n", buff); }
		sprintf (buff, "%s > %s.err", buff, output_object);
		if ( ! win_95_98 ) { sprintf (buff, "%s 2>&1", buff); }
		#ifdef DEBUG
		  A4GL_debug ("Runnung %s", buff);
		#endif
		ret = system (buff);
		#ifdef DEBUG
		  A4GL_debug ("Command returned code %d", ret);
		#endif
		if (ret) {
		  printf ("Error compiling %s - check %s.err\n", output_object,
			  output_object);
		  printf ("Failed command was: %s\n", buff);
		  printf ("Exit code is: %d\n", ret);
		  /*fixme: show err file*/
		  /*FIXME: if I exit with ret, I get 0 code on the shell:*/
		  exit (99);
		} else {
			if (preserve_warn) {
				// No error code from linking command - check if there was any output
				sprintf (buff, "%s.err", output_object);
				if (verbose) { printf ("checking for %s\n", buff); }
				filep = fopen (buff, "r");
				/*  f = A4GL_mja_fopen (ii, "r");*/
				fseek (filep, 0, SEEK_END);
				flength = ftell (filep);
				fclose (filep);
				/* The 'proper' way to do it is with 'stat' - but this isn't 
					too portable (even though it should be). */
		
				if (flength) {
					/*
					 Since there was no error code returned from C compiler/linker,
					 *.xxx.err file (when it exist and is not 0 size ) will contain
					 linker warnings only
					*/
					A4GL_debug ("%s file size is not zero %d\n", buff, flength);
					if (verbose) { printf ("%s is non-zero\n", buff); }
	
					//something wrong here - does not show 1 or 0 but large random integer
					//if (verbose) { printf ("shell_is_bash=%d\n"),shell_is_bash;}
					if ( ! win_95_98 ) {
						  sprintf (buff, "%s %s.err %s.warn", mv_cmd,
							   output_object, output_object);
					} else {
						  /*suppress silly message from move command on w98*/
						  sprintf (buff, "%s %s.err %s.warn > nul", mv_cmd,
							   output_object, output_object);
					}
					#ifdef DEBUG
						A4GL_debug ("Runnung %s", buff);
					#endif
					if (verbose) { printf ("Running %s\n", buff); }
					ret = system (buff);
				} else {
				  /*err file will be deleted if clean_aftercomp is set*/
				  /*printf ("%s file size is zero %d\n",buff,flength);*/
				}
			} else {
				//just delete any .err file possibly created - it contains
				// only warnings, and preserve_warn=0
				sprintf (buff, "%s %s.err", acl_getenv ("A4GL_RM_CMD"), output_object);
				#ifdef DEBUG
					A4GL_debug ("Runnung %s\n", buff);
				#endif
				if (verbose) { printf ("Running %s\n", buff); }			
				ret = system (buff);
			}
		if (clean_aftercomp) {
			/*
				 FIXME:
				 do we really want to remove all objects?, that includes libraries,
				 and objects that might be needed for other programs, forcing common
				 shared objects to be compiled over and over again...
				 Maybe just make sure you clean only in current directory?
			*/
			/*sprintf (buff,"%s %s",acl_getenv("A4GL_RM_CMD"),all_objects);*/
			sprintf (buff, "%s %s.err", acl_getenv ("A4GL_RM_CMD"), output_object);
			#ifdef DEBUG
				A4GL_debug ("Runnung %s\n", buff);
			#endif
			if (verbose) { printf ("Running %s\n", buff); }			
			ret = system (buff);
			if (ret) {
			  printf ("Clean of %s intermediate objects failed\n", a);
			  printf ("Failed command was: %s\n", buff);
			}
		}
	}
} else {
	if ((!todo) && (!c_to_o))  {
	  A4GL_debug
	    ("Error in parameters to 4glc - no 4gl input files and no linking.\n");
	  printf
	    ("Error in parameters to 4glc - no 4gl input files and no linking.\n");
	  return (5);
    }
}
  return x;
}




/**
 * Compile one 4gl file to output language, and optionally to object
 *
 *
 * @param compile_object
 * @param aa input source file, with path but no extension
 * @param incl_path
 * @param silent
 * @param verbose
 * @param output_object -- not really needed - remove it
 */
static int
compile_4gl (int compile_object, char fgl_basename[128], char incl_path[128],
		int silent, int verbose, char output_object[128],int win_95_98,
		char informix_esql[128], char pg_esql[128], char extra_ccflags[1024],
		int preserve_warn, int each_obj_to_so, int put_object_in_currdir,
		char *all_objects)
{
int need_cc=0, yyparse_ret, ret, flength=0;
char buff[1028];
char single_output_object[128] = "";
char fgl_file[128];			/*The 4gl file*/
char a_part[128], b_part[128];	//for bname()
char *ptr;
static FILE *filep = 0;
char ext[8];
static char local_pass_options[1024] = "";

	/* store the directory part of file name, if any, so we can use it for GLOBALS
    file compilation, if nececery */
	sprintf (fgl_file, "%s%s", fgl_basename, ".4gl");
	strcpy (buff, fgl_file);
	
	//Note: output_object is empty when compilation is invoked because
	//that 4gl file was specified as GLOBALS file
	A4GL_debug ("Compiling: %s to %s\n", fgl_file,output_object);
	if (verbose) {printf ("Compiling: %s to %s\n", fgl_file,output_object);}
	
	if (strchr (buff, '/')) {
		ptr = strrchr (buff, '/');
		strcpy (ptr, "");		/* this does NOT leave a slash at the end*/
		strcpy (currinfile_dirname, buff);
	} else {
		strcpy (currinfile_dirname, ".");
	}

	#ifdef DEBUG
		A4GL_debug ("Set currinfile_dirname to: %s\n", currinfile_dirname);
		A4GL_debug ("Opening in memory: %s\n", fgl_file);
	#endif

	/*
    File MUST be opened in binary mode on Windows, to be able to process
    source file in DOS format - otherwise fpos/ftell gets completely dissoriented:
	*/
	yyin = A4GL_memfile_fopen (fgl_file, "rb");

	/*printf("Buffer size : %d\n",BUFSIZ);*/
	/*file_buffer=malloc(30000);*/
	/*setbuf(yyin,file_buffer);*/

	if (yyin == 0) {
		#ifdef DEBUG
			A4GL_debug ("Error opening file : %s\n", fgl_file);
		#endif
		printf ("Error opening file : %s\n", fgl_file);
		exit (1);
	}

	A4GL_memfile_fseek (yyin, 0, SEEK_END);
	A4GL_remove_comments_in_memfile(yyin);
	yyin_len = A4GL_memfile_ftell (yyin);
	A4GL_memfile_rewind (yyin);
	A4GL_load_features();

	/*
	sprintf (buff, "A4GL_USE_INDICATOR=%s", acl_getenv ("A4GL_USE_INDICATOR"));
	if (verbose){printf ("%s\n", buff);	}
	*/
	/* TODO - make sue that all settings required by ecpg
		are set WHEN WE ARE COMPILING 4GL CODE
	*/

	
	
	if (yydebug) { printf ("Opened : %s\n", fgl_file); }
	openmap (outputfilename);
	if (!silent) {
		if (globals_only) {
			if (verbose) {
				printf ("Preparing globals file for: %s\n", fgl_file);
			}
			#ifdef DEBUG
		  		A4GL_debug ("Preparing globals file for: %s\n", fgl_file);
			#endif
		} else {
			if (verbose) {
				printf ("Translating to %s: %s\n", acl_getenv ("A4GL_LEXTYPE"),fgl_file);
			}
			#ifdef DEBUG
				A4GL_debug ("Translating to %s: %s\n", acl_getenv ("A4GL_LEXTYPE"), fgl_file);
			#endif
		}
    }
	yyparse_ret = a4gl_yyparse ();		/* we core A4GL_dump here on Darwin */
	#ifdef DEBUG
		A4GL_debug ("after yyparse\n");
	#endif
	A4GL_lex_parsed_fgl ();

	if (yydebug) { printf ("Closing map : %d\n", yyparse_ret); }
	dump_gvars ();
	closemap ();
	if (A4GL_db_used()) {
		A4GL_close_database();
	}
	#ifdef DEBUG
		A4GL_debug ("after closemap");
	#endif

	if (module_errors_cnt) {
		char errfile[1024];
		yyparse_ret=-1;
		sprintf (errfile, "%s.err", outputfile);
		rewind(yyin);
		A4GL_write_errfile_many_errors(errfile,yyin,module_errors,module_errors_cnt);
		fclose(yyin);
	        printf ("Error compiling %s.4gl - check %s.err\n", outputfile, outputfile);
 		exit (2);

	}


	if (yyparse_ret == 0) {
		if (verbose) { printf ("4GL module compiled successfuly.\n"); }
		if (compile_object) {
			if (strcmp (acl_getenv ("PRINTPROGRESS"), "Y") == 0) {
				printf("Compiling Object\n");fflush(stdout); //\r
			}
			A4GL_bname (output_object, a_part, b_part);
			strcpy (ext, ".");
			strcat (ext, b_part);

			if ((strcmp (ext, acl_getenv ("A4GL_OBJ_EXT")) == 0) ||
				(strcmp (ext, ".o") == 0)) {
			  /* user specified output file with -o, and output file is object */
			  sprintf (single_output_object, "%s", output_object);
/*			  
			} else if ((strcmp (ext, acl_getenv ("A4GL_SOB_EXT")) == 0) ||
				(strcmp (ext, ".so") == 0)) {
			  // user specified output file with -o, and output file is SHARED object
			  sprintf (single_output_object, "%s", output_object);
*/			  
			  /* This can be wrong because is more then one input file was on 
			  	command line, user can sprify .so as output to indicate that 
				final result of all objects should b elinked into .so -
				AND NOT that each object should be created as shared object.
				
				So we will compile each object (as opposed to link) to .so
				ONLy id --sheared flag was on the command line (as opposed to 
				--as-dll)
			  */
			} else if (each_obj_to_so) {
				// USer specified --shared flag
				sprintf (single_output_object, "%s", output_object);
				   //acl_getenv ("A4GL_SOB_EXT"));
			} else {
			  /* user did not specify output file using -o, or specified output
				 file did not have Aubit object extension */
			  /*FIXME: we can compile shared or static here*/
			  	if (put_object_in_currdir)	{
					/* strip path from input file name, so our object allways and up in
					current directory - otherwise make file will not be able to find it using
					VPATH when making objects for current explicit target.
					FIXME: this should be done ONLY when -o option on command line did not have
					object extension - if it did, and this included path, then this path should
					be used when making object
					*/
					char **ppsz;
					char *psz;
					ppsz = &psz;
					*ppsz = fgl_basename;
					a4gl_basename (ppsz);
					strcpy (single_output_object, *ppsz);
				}
				/* Output name of the single file object allways must be same as
					the 4gl file we are compiling, regardless of what might be set
					on command line with -o
				*/
				sprintf (single_output_object, "%s%s", single_output_object,
				   acl_getenv ("A4GL_OBJ_EXT"));
			}
	
			if (strcmp (acl_getenv ("A4GL_LEXTYPE"), "EC") == 0) {
				/*
				When using Embedded C output, we need to run appropriate ESQL/C
				on generated file to get a .c file and compile object file
				from that
				*/
				if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "POSTGRES") == 0) {
					char buff2[2000];
					
					sprintf (buff, "%s/bin/ecpg -C INFORMIX -t %s.cpc %s %s",
					   acl_getenv ("POSTGRESDIR"), fgl_basename, incl_path, pass_options);
					if (verbose){printf ("%s\n", buff);	}
					if ( ! win_95_98 ) {
						/*this apparently works on NT, but not on W98:*/
						sprintf (buff2, "%s > %s.cpc.err 2>&1", buff, fgl_basename);
						strcpy(buff,buff2);
					} else {
						sprintf (buff2, "%s > %s.cpc.err", buff, fgl_basename);
						strcpy(buff,buff2);
					}
					#ifdef DEBUG
						A4GL_debug ("Runnung %s", buff);
					#endif
					ret = system (buff);
					/*see function system_run() in fglwrap.c*/
					if (ret) {
						printf ("Error compiling %s.cpc - check %s.cpc.err\n", fgl_basename, fgl_basename);
						printf ("Failed command was: %s\n", buff);
						/*fixme: show err file*/
						return ret;
					} else {
						if (verbose) { printf ("PG EC compilation of the object successfull.\n");}
						need_cc=1;
						//WARNING: ORDER IS IMPORTANT! think about /usr/include!
						//why did I have hasd-codes -I\"/usr/include/pgsql\" in here?
						sprintf (incl_path, "%s -I\"%s/include/postgresql/informix/esql\" -I\"%s/include\" ",
							  incl_path, acl_getenv ("POSTGRESDIR"),acl_getenv ("POSTGRESDIR"));
						/* FIXME: this can be in different places - see ./configure
						/opt/ecpg-cvs/include/postgresql/informix/esql/decimal.h
						/usr/include/pgsql/libpq-fe.h
						*/
					}
				} else if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "SAPDB") == 0) {
					/* /opt/sapdb/interfaces/precompiler/bin/cpc hello <<- no .cpc extension ! */
					   sprintf (buff, "%s %s -c -o %s %s %s",
					   acl_getenv ("A4GL_SAPDB_ESQLC"), fgl_basename, single_output_object, incl_path,
					   pass_options);
				} else if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "QUERIX") == 0) {
					  sprintf (buff, "esqlc %s.ec -c -o %s %s %s",
					   fgl_basename, single_output_object, incl_path,
					   pass_options);
				} else if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "INGRES") == 0) {
					  sprintf (buff, "4glpc -V5 -c -o %s %s.sc %s %s",single_output_object,
					   fgl_basename,  incl_path,
					   pass_options);

					printf("--->%s\n",buff);

				} else /*"A4GL_LEXDIALECT"="INFORMIX" - default*/ {
					//we must add this include paths becuse we use qualified 
					//path for decimal.h include, to prevent it from being confused
					//with other files with same name
					/* WARNING: must use double-quotes here! */
					sprintf (incl_path, "%s -I\"%s/incl\" -I\"%s/CSDK/incl\" -I\"%s/incl/esql\" -I\"%s/CSDK/incl/esql\"",
						incl_path, acl_getenv ("INFORMIXDIR"),acl_getenv ("INFORMIXDIR"),
						acl_getenv ("INFORMIXDIR"),acl_getenv ("INFORMIXDIR"));
					#if ( defined (__MINGW32__) || defined (__CYGWIN__) )
						/* 
							On Windows, must do a two step, since ecpg will try to
							invoke MS VC C compiler and not MinGW GCC we want
						*/
						sprintf (buff, "%s -thread -e %s.ec %s %s",
							informix_esql, fgl_basename, incl_path, pass_options);
						if (verbose){printf ("%s\n", buff);	}
						if ( ! win_95_98 ) {
							/*this apparently works on NT, but not on W98:*/
							sprintf (buff, "%s > %s.ec.err 2>&1", buff, fgl_basename);
						} else {
							sprintf (buff, "%s > %s.ec.err", buff, fgl_basename);
						}
						#ifdef DEBUG
							A4GL_debug ("Runnung %s", buff);
						#endif
						ret = system (buff);
						/*see function system_run() in fglwrap.c*/
						if (ret) {
							printf ("Error compiling %s.ec - check %s.ec.err\n", fgl_basename, fgl_basename);
							printf ("Failed command was: %s\n", buff);
							/*fixme: show err file*/
							return ret;
						} else {
							if (verbose) { printf ("IFX EC compilation of the .ec successfull.\n");}
							need_cc=1;
						}
					#else
						//On UNIX
						sprintf (buff, "%s %s.ec %s -c -o %s %s %s",informix_esql,
							fgl_basename, extra_ccflags, single_output_object, incl_path,
							pass_options);
					#endif
				}
			} 

			if ((strcmp (acl_getenv ("A4GL_LEXTYPE"), "C") == 0) || need_cc) {
				/* 
				Pure C compiler output or EC compiler that needs separate CC step
				
				It seems that all do - so we allways enter here
				
				FIXME: should we add C compiler flags -g and/or -O2 -DDEBUG here ?
				create A4GL_CFLAGS in resource.c
				*/
				
				if (each_obj_to_so) {
					sprintf (local_pass_options, "%s -shared ",pass_options);
				} else {
					sprintf (local_pass_options, "%s -c ",pass_options);
				}
				
				#ifndef __MINGW32__
					//UNIX
				  sprintf (buff, "%s %s.c -o %s %s %s %s",
					   gcc_exec, fgl_basename, single_output_object, incl_path,
					   local_pass_options, extra_ccflags);
				#else
					//Windows
				  sprintf (buff, "%s -mms-bitfields %s.c -c -o %s %s %s %s",
					   gcc_exec, fgl_basename, single_output_object, incl_path,
					   local_pass_options, extra_ccflags);
				#endif
			}
			
			if (verbose){ printf ("%s\n", buff); }
			if ( ! win_95_98 ) {
				/*this apparently works on NT, but not on W98:*/
				sprintf (buff, "%s > %s.c.err 2>&1", buff, fgl_basename);
			} else {
				sprintf (buff, "%s > %s.c.err", buff, fgl_basename);
			}
			#ifdef DEBUG
		  		A4GL_debug ("Runnung %s", buff);
			#endif
			ret = system (buff);
			/*see function system_run() in fglwrap.c*/
			if (ret) {
				printf ("Error compiling %s.c - check %s.c.err\n", fgl_basename, fgl_basename);
				printf ("Failed command was: %s\n", buff);
				/*fixme: show err file*/
				return ret;
			} else {
				if (verbose) { printf ("C/EC compilation of the object successfull.\n"); }
///aaaaaa				
//printf ("2 all_objects=%s\n", all_objects);
				//Add this output pbject to the list of all objects, we can use
				//for final linking of library or executable:
				sprintf (all_objects, "%s",single_output_object);
//printf ("3 all_objects=%s\n", all_objects);
				
				if (preserve_warn) {
					/* determine the c.err file size */
					sprintf (buff, "%s.c.err", fgl_basename);
					filep = fopen (buff, "r");
					/*  f = A4GL_mja_fopen (ii, "r");*/
					fseek (filep, 0, SEEK_END);
					flength = ftell (filep);
					fclose (filep);
					/* The 'proper' way to do it is with 'stat' - but this isn't too 
					portable (even though it should be). */
	
					if (flength) {
						/*
						 Since there was no error code returned from C compiler,
						 *.c.err file (when it exist and is not 0 size ) will contain
						 compiler warnings only
						*/
			
						#ifdef DEBUG
							A4GL_debug ("%s file size is not zero %d\n", buff, flength);
						#endif
					  
						if ( ! win_95_98 ) {
							sprintf (buff, "%s %s.c.err %s.c.warn",
							   acl_getenv ("A4GL_MV_CMD"), fgl_basename, fgl_basename);
						} else {
							/*suppress silly message from move command on w98*/
							sprintf (buff, "%s %s.c.err %s.c.warn > nul",
								acl_getenv ("A4GL_MV_CMD"), fgl_basename, fgl_basename);
						}
	
						#ifdef DEBUG
							A4GL_debug ("Runnung %s", buff);
						#endif
						ret = system (buff);
						if (ret) {
							printf ("Error executing: %s\n",buff);
							printf ("%s.c.err file size = %d\n", fgl_basename, flength);
						}
					} else {
						/*c.err file will be deleted if clean_aftercomp is set*/
						/*printf ("%s file size is zero %d\n",buff,flength);*/
					}
				} else {
					//just delete any .err file possibly created - it contains
					// only warnings, and preserve_warn=0
					//FIXME - use A4GL_EC_EXT instead of listing .cpc. ec ...etc
					sprintf (buff, "%s %s.err %s.c.err %s.ec.err %s.cpc.err",
						acl_getenv ("A4GL_RM_CMD"), fgl_basename, fgl_basename,fgl_basename, fgl_basename);
					#ifdef DEBUG
						A4GL_debug ("Runnung %s", buff);
					#endif
					ret = system (buff);
				}
				if (clean_aftercomp) {
					/*is it smart to delete .glb files?*/
					sprintf (buff, "%s %s.err %s.c.err %s.h %s.c ",	/*%s.glb*/
						acl_getenv ("A4GL_RM_CMD"), fgl_basename, fgl_basename, fgl_basename, fgl_basename);	/*,fgl_basename*/
					#ifdef DEBUG
						A4GL_debug ("Runnung %s", buff);
					#endif
					ret = system (buff);
					if (ret) {
						printf ("Clean of %s intermediate files failed\n", fgl_basename);
						printf ("Failed command was: %s\n", buff);
					}
				}
			}
		}
	}

	return yyparse_ret;

}

/**
 * Print the usage message when executing the 4gl compiler.
 * Invoked autometically from inside getopt_long() when invalis option
 * is encountered.
 */
void
printUsage (char *argv[])
{
  printf ("\n");
  printf ("Aubit 4GL compiler usage:\n");
  printf (" %s [options] -oOutFile.ext file.ext [file.ext ...]\n", argv[0]);
  printf ("  Try -help for more.\n");
  printf ("\n");
}

/**
 * Print the usage message when executing the 4gl compiler.
 */
static void
printUsage_help (char *argv[])
{
  /* FIXME: make sure we don't have conflict with GCC options - for pass-trough */
  /* FIXME: verify we have all options of 4glpc script here */

  printf ("\n");
  printf
    ("Aubit 4GL compiler usage: %s [options] -oOutFile.ext file.ext [file.ext ...]\n",
     argv[0]);
  printf ("\n");
  printf ("Extensions (.ext):\n");
  printf
    ("  In files list, all .4gl files will be compield to C, other files passed to linker.\n");
  printf ("  In -o flag, extendion will decide type of linking:\n");
  printf
    ("    ao=object, aox=static library, aso=shared lib, 4ae=executable.\n");
  printf ("\n");

  printf ("Options:\n");
  printf ("\n");
  printf ("When A4GL_LEXTYPE=C :\n");
  printf ("  -o[outfile] name outpout file\n");
  printf ("  (no flags) compile to C only\n");
  printf ("\n");

  printf ("When A4GL_LEXTYPE=PERL :\n");
  printf ("  (no flags) compile to Perl only\n");
  printf ("\n");

  printf ("Other options :\n");
  printf ("  -I -L -l : ");
  printf ("  -G     | --globals         : Generate the globals map file\n");
  printf ("  -S     | --silent          : no output other then errors\n");
  printf ("  -V     | --verbose         : Verbose output\n");
  printf ("  -N name| --namespace name         : Prefix all functions with name (default 'aclfgl_')\n");
  printf ("  -v     | --version         : Show compiler version and exit\n");
  printf ("  -f     | --version_full    : Show full compiler version and details\n");
  printf ("  -?     | --help            : Show this help and exit\n");
  printf ("  -tTYPE | --lextype         : output language, TYPE=C(default) or PERL\n");
  printf ("  -k     | --keep            : keep intermediate files (default)\n");
  printf ("  -w     | --keep-warn       : keep warnings output file [.warn](default=do not)\n");  
  printf ("  -K     | --clean           : clean intermediate files when done\n");
  printf ("  -s0|1  | --stack_trace 0|1 : Include the stack trace in file:\n");
  printf ("  -h     | --as-dll          : Make -o by linking all resulting object into shared library\n");
  printf ("  -H     | --shared          : Compile each input object into shared object (.so/.aso/.dll)\n");  
  
  printf ("                             : 0-Don't generate  1-Generate(Default)\n");
  
  
  printf ("If 'outfile' was not specified, it is generated from first 4gl file name\n");
  printf ("specified. All options that are not recognised, are passed to C compiler,\n");
  printf ("if -c -o -d or -l was specified.\n");
  printf ("\n");

/*FIXME: move this to -vfull*/


  printf ("Compiled with platform settings:\n");
  #if ( defined(__MINGW32__) )
  	printf ("__MINGW32__ ");
  #endif

  #if ( defined (_WIN32) )
  	printf ("_WIN32 ");
  #endif

  #if ( defined(WIN32) )
  	printf ("WIN32 ");
  #endif

  #if ( defined(__CYGWIN__) )
  	printf ("__CYGWIN__ ");
  #endif

  printf ("\n");
  printf ("\n");

  /*command line options parser (opt_long()) will call this function */
  /*automatically when it encounters an error in options, so we must exit*/
  /*here with an error code to let the calling proglams (like 'make') know*/
  /* to stop:*/
  exit (2);

}


/**
 * Treatment of an error ocurred in the parsing.
 *
 * It makes the proper treatment of an syntax error ocurred during the parsing
 *
 * @param s The string that contains the error
 */
void
a4gl_yyerror (char *s)
{
  char errfile[256];
  FILE *f;
  long ld;
  char a;
  const char *matchstr="unexpected NAMED_GEN";
  
  if (strstr(s,matchstr)) {
	char buff[1024];
	char *ptr;
	strcpy(buff,s);
	ptr=strstr(s,matchstr);

	buff[ptr-s]=0;
	ptr+=strlen( matchstr);

	strcat(buff,"unexpected '");
	strcat(buff,yytext);
	strcat(buff,"' ");
	if (*ptr) strcat(buff,ptr);
	s=buff;
  }

  if (A4GL_isyes(acl_getenv("LIST_ERRS"))) {
	if (strcmp(s,"Variable not found")==0) return;
	add_module_error(yylineno,s);
  	//printf("Line %d - %s\n",yylineno,s);
  	return;
  }

  ld = A4GL_memfile_ftell (yyin);
  sprintf (errfile, "%s.err", outputfile);
  a = 0;


/* Need a real fseek here */
  fseek (yyin, fpos, SEEK_SET);
  f = A4GL_write_errfile (yyin, errfile, ld, yylineno);


  fprintf (f, "| %s%s (%s)", s, errbuff, yytext);

  if (atoi(acl_getenv("RUNNING_TEST"))) {
        char buff[256];
        FILE *f;
        char *ptr;
        ptr=acl_getenv("LOG_TEXT");

        if (ptr&&strlen(ptr)) {
                sprintf(buff,"%s/test_fail/%s/%s.err",acl_getenv("AUBITDIR"),ptr,acl_getenv("RUNNING_TEST"));
        } else {
                sprintf(buff,"%s/test_fail/%s.err",acl_getenv("AUBITDIR"),acl_getenv("RUNNING_TEST"));
        }
        f=fopen(buff,"w");

        if (f) {
                fprintf(f,"%s%s (%s)\n",s,errbuff,yytext);
                fclose(f);
        }
  }
  A4GL_write_cont (yyin);
  printf ("Error compiling %s.4gl - check %s.err\n", outputfile, outputfile);
 exit (2);
}

/************************* same function from fcompile:

FIXME: merge all yyerror() finction in libaubit4gl

void a4gl_yyerror(char *s)
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
setGenStackInfo (int _genStackInfo)
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
isGenStackInfo (void)
{
  return genStackInfo;
}


/**
 *
 *
 * @param s
 */
void
set_yytext (char *s)
{
  strcpy (yytext, s);
}

/**
 *
 *
 *
 */
static int
get_ansi_mode (void)
{
  static int ansi_mode = -1;
  if (ansi_mode == -1)
    {

      ansi_mode = ANSI_MODE_IGNORE;

      if (A4GL_isyes (acl_getenv ("ANSI_WARN")))
	{
	  ansi_mode = ANSI_MODE_WARN;
	}

      if (A4GL_isyes (acl_getenv ("ANSI_ERROR")))
	{
	  ansi_mode = ANSI_MODE_ERROR;
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
void
ansi_violation (char *s, int severity)
{
char buff[256];
	switch (get_ansi_mode ()) {
		case ANSI_MODE_IGNORE:
			return;
		case ANSI_MODE_WARN:
			if (severity == 0) {
				printf ("Warning : Corrected ANSI violation : %s @ line %d\n", s,
					yylineno);
			} else {
				printf ("Warning : ANSI violation : %s @ line %d\n", s, yylineno);
			}
			return;
    }
	
	/* Must be an ansi error....*/
	if (severity == 0) {
		printf ("Warning : Corrected ANSI violation : %s @ line %d\n", s,
	      	yylineno);
		return;
    }
	sprintf (buff, "Error: ANSI violation - %s", s);
	a4gl_yyerror (buff);
}

/**
 *
 *
 *
 */
int
has_default_database (void)
{
  if (default_database != 0)
    return 1;
  return 0;
}

/**
 *
 *
 *
 */
char *
get_default_database (void)
{
  return default_database;
}


void add_module_error(int n,char *s) {
	module_errors_cnt++;
	if (module_errors_cnt<=20)  {
		module_errors=realloc(module_errors,sizeof(module_errors[0])*module_errors_cnt);
		module_errors[module_errors_cnt-1].lineno=n;
		module_errors[module_errors_cnt-1].err_str=strdup(s);
	}
}

/* ==================================== EOF =============================== */
