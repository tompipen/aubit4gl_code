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
# $Id: map.c,v 1.16 2002-11-10 06:45:19 afalout Exp $
#*/

/**
 * @file
 * Generation of map file.
 *
 * The map file is used to put in a file some mapping between the elements
 * in the 4gl source code and the line number module, etc.
 *
 * It is a file with pipe separated columns and \n separated records
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

static FILE *mapfile = 0; 		/* The map file pointer opened file */
static char outputfile[132]; 	/** The output file name */
static int 	genStackInfo = 1;

extern FILE *yyin;
extern int 	glob_only;
extern long fpos; 				/** current file position for direct fseek */
extern int 	yylineno;
extern char *outputfilename; 	/* Defined in libaubit4gl */
extern char infilename[132];

char 		errbuff[1024] = "";
char 		yytext[] = "";
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

void 		setGenStackInfo		(int _genStackInfo);
static int  compile_4gl			(char c[128],int compile_object, char a[128],char incl_path[128]);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Open the map file.
 *
 * If the environment variable MAP4GL is assigned with Y open the file
 * Downt do nothing otherwise
 *
 * @param s The map file name
 */
void
openmap (char *s)
{
  char buff[256];
  #ifdef DEBUG
	  debug ("openmap...");
  #endif
  if (strcmp (acl_getenv ("MAP4GL"), "Y") == 0 && mapfile==0)
    {
	  #ifdef DEBUG
		  debug ("Opening map file..%s \n", acl_getenv ("MAP4GL"));
    	  debug ("Yep...\n");
      #endif
      sprintf (buff, "%s.map", s);
      mapfile = fopen (buff, "w");

      if (mapfile == 0)
	{
	  #ifdef DEBUG
		  debug ("Unable to open map file");
      #endif
	  printf ("Unable to open map file\n");
	  exit (1);
	}
	  #ifdef DEBUG
		  debug ("Mapfile=%p", mapfile);
      #endif
    }
}

/**
 * Add a new map to the opened file.
 *
 * Just adds if the mapfile was opened (controled by environment variable
 * MAP4GL)
 *
 * @param t The x4gl element type
 * @param s The name of the element
 * @param w The scope where the element was declared
 *    - MAIN 
 *    - MODULE
 *    - Function name
 * @param l The line number in the source code where the implementation was
 *          started.
 * @param m The x4gl module name
 */
void
addmap (char *t, char *s, char *w, int l, char *m)
{
  #ifdef DEBUG
	  debug ("Adding to map... %p", mapfile);
  #endif
  if (mapfile)
    fprintf (mapfile, "%s|%s|%s|%d|%s|\n", t, s, w, l, m);
}

/**
 * Close the map file
 */
void
closemap (void)
{
  if (mapfile)
    fclose (mapfile);
}

/*
=====================================================================
                    Functions moved from 4glc.c
=====================================================================
*/

/**
 * Read and parse the globals file (if found).
 *
 * @param fname The globals file name
 */
int
read_globals (char *fname)
{
FILE *fin;
fin = yyin;

  glob_only = 1;
  rm_quote (fname);
  #ifdef DEBUG
	  debug("Opening %s",fname);
  #endif
  yyin = mja_fopen (fname, "r");

  if (yyin == 0)
    {
      printf ("Error opening globals file : %s\n", fname);
      return -1;
    }

  lex_printc ("/***********************************************************/\n");
  return (yyparse ());
  lex_printc ("/***********************************************************/\n");
  glob_only = 0;
  yyin = fin;
  return 0;
}

/**
 * Remove the quotes from a quoted string.
 *
 * @param s The string to be unquoted
 */
void
rm_quotes (char *s)
{
char buff[256];
int a;
int b = 0;
  
  for (a = 0; a <= strlen (s); a++)
    {
      if (s[a] != '"')
	{
	  buff[b++] = s[a];
	}
    }
  strcpy (s, buff);
}

/**
 * Remove the quotes in the beginning and at the from a quoted string
 *
 * @param s The string to be unquoted
 */
void
rm_quote (char *s)
{
char buff[256];
int a;
int b = 0;
  
  for (a = 0; a <= strlen (s); a++)
    {
      if (s[a] != '"')
	{
	  buff[b++] = s[a];
	}
    }
  for (a = strlen (buff) - 1; a >= 0; a--)
    {
      if (buff[a] == '.')
	{
	  buff[a] = 0;
	  break;
	}
    }
  strcpy (s, buff);
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

  ld = ftell (yyin);
  sprintf (errfile, "%s.err", outputfile);
  a = 0;
  fseek (yyin, fpos, SEEK_SET);
  f = write_errfile (yyin, errfile, ld, yylineno);
  fprintf (f, "| %s%s (%s)", s, errbuff, yytext);
  write_cont (yyin);
  printf ("Error compiling %s.4gl - check %s.err\n", outputfile, outputfile);
  exit (2);
}

/************************* same function from fcompile:

void yyerror(char *s)
{
  char errfile[256];
  FILE *f;
  long ld;

  ld=buffpos();
  sprintf(errfile,"%s.err",outputfile);
  f=write_errfile(yyin,errfile,ld-1,yylineno);
  fprintf (f, "| %s", s);
  write_cont(yyin);
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
 * Print the usage message when executing the 4gl compiler.
 */
static void
printUsage(char *argv[])
{
  printf("Usage %s [options] file.4gl [file.4gl ...]\n", argv[0]);
  printf("Options:\n");
  printf("\n");
  
  printf("When A4GL_LEX=C :\n");
  printf("  -c compile to object(s), do not link\n");
  printf("  -o [outfile] compile to object(s), link into executable\n");
  printf("  -d [outfile] compile to object(s), link into shared library\n");
  printf("  -l [outfile] compile to object(s), link into static library\n");
  printf("  (no flags) compile to C only\n");
  printf("\n");
  
  printf("When A4GL_LEX=PERL :\n");
  printf("  (no flags) compile to Perl only\n");
  printf("\n");

  printf("Other options :\n");
  printf("  -G     | --globals         : Generate the globals map file\n");
  printf("  -s 0|1 | --stack_trace 0|1 : Include the stack trace in file:\n");
  printf("     0 - Don't generate\n");
  printf("     1 - Generate(Default)\n");
  printf("  If 'outfile' was not specified, it is generated from first 4gl file name specified\n");
  printf("\n");
}


/**
 * Parse the comand line arguments and acording to the passed values
 * set(s) the properties.
 *
 * @param argc The argument count
 * @param argv The argument values
 */
//static
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
int x;
int ret;
char opt_list[40];
char a[128];
char b[128];
char c[128];
char incl_path[128];
char l_path[128];
char l_libs[128];
char buff[456];
static struct option long_options[] =
  {
    {"globals",     0, 0, 'G'},
    {"stack_trace", 1, 0, 's'},
    {"help", 		0, 0, '?'},
    {0, 0, 0, 0},
  };

	#ifdef DEBUG
		debug ("Parsing the comand line arguments\n");
    #endif

	/* see http://www.gnu.org/software/gengetopt for inspiration */

  if (strcmp (acl_getenv ("A4GL_LEX"), "C") == 0)
  {
    strcpy(opt_list,"Gs:codl?h");
  }

  if (strcmp (acl_getenv ("A4GL_LEX"), "PERL") == 0)
  {
    strcpy(opt_list,"Gs:?h");
  }

  while ( ( i = getopt_long (argc, argv, opt_list,
                        long_options, &option_index) ) != -1)
  {
    switch(i)
    {
      case 'G':              /* Global generate only */
		globals_only = 1;
        break;

      case 's':              /* Stack information inclusion */
		si = atoi(optarg);
        if ( si != 0 && si != 1 )
		{
		  printUsage(argv);
		  exit(1);
		}
        setGenStackInfo(si);
        break;

      case 'c':              /* Compile resulting C file(s) to object */
		compile_object = 1;
		break;

      case 'o':              /* Link resulting object(s) into executable */
		compile_exec = 1;
		compile_object = 1;
		break;

      case 'd':              /* Link resulting object(s) into shared library */
		compile_so = 1;
		compile_object = 1;
		break;

      case 'l':              /* Link resulting object(s) into static library */
		compile_lib = 1;
		compile_object = 1;
		break;

      case '?':             /* Help */
      case 'h':
		printUsage(argv);
        exit(0);
    }
  }

  if ( optind >= argc )
  {
    printf("No file name defined\n");
    printUsage(argv);
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
  #ifdef DEBUG
	  debug("after init_datatypes\n");
  #endif

  if (!A4GLSQL_initlib()) {
	printf("4glc: Error opening SQL Library (A4GL_SQLTYPE=%s)\n", acl_getenv("A4GL_SQLTYPE"));
	exit(1);
  }

  check_and_show_id ("4GL Compiler", argv[optind]);
  outputfilename = outputfile; /* set in check_and_show_id ? */
  strcpy (c, argv[optind]);
  bname (c, a, b);

  /* whe now have to specify extensions, since we can put multiple source files
    on command line.
  if (b[0] == 0)
  {
    strcat (c, ".4gl");  // use ommited the extension
	bname (c, a, b);
  }
  */

  	strcpy (outputfilename, a);
	strcpy (infilename, c);

    /* prepare CC flags */
    /* FIXME: migrate this to user resources */
	strcpy (incl_path,"-I");
	strcat (incl_path,acl_getenv ("AUBITDIR"));
	strcat (incl_path,"/incl");
    strcpy (l_path,"-L");
	strcat (l_path,acl_getenv ("AUBITDIR"));
	strcat (l_path,"/lib");
    strcpy (l_libs,"-laubit4gl");


    //fixme: put all 4gl files on command line in array, and loop here:
    //while (1) 
	//{
		x = compile_4gl(c,compile_object,a,incl_path);
    //}

  debug("after compile_4gl()");

  if ( x == 0 )
  {
    if (compile_exec)
	{
		//FIXME: change this to linking
		sprintf (buff,"gcc %s.c -o %s %s %s %s",a,a,incl_path,l_path,l_libs);
		printf ("%s\n",buff);
		sprintf (buff,"%s > %s.err 2>&1",buff,a);
		debug("Runnung $s",buff);
		ret=system (buff);
		if (ret) {
			printf ("Error compiling %s.c - check %s.err\n",a,a);
			//fixme: show err file
        }

	}

    if (compile_so)
	{
		printf ("Shared lib linking not implemented");
	}

    if (compile_lib)
	{
		printf ("Static lib linking not implemented");
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
compile_4gl(char c[128],int compile_object,char a[128],char incl_path[128])
{
int x, ret;
char buff[456];

  /*
  File MUST be opened in binary mode on Windows, to be able to process
  source file in DOS format - otherwise fpos/ftell gets completely dissoriented:
  */
  yyin = mja_fopen (c, "rb");

  if (yyin == 0)
  {
    printf ("Error opening file : %s\n", c);
    exit (1);
  }

  fseek(yyin,0,SEEK_END);
  yyin_len=ftell(yyin);
  rewind(yyin);

  if (yydebug)
    {
      printf ("Opened : %s\n", c);
    }

  openmap(outputfilename);

  x = yyparse (); /* we core dump here on Darwin */
  #ifdef DEBUG
	  debug("after yyparse\n");
  #endif

  if (yydebug)
    {
      printf ("Closing map : %d\n", x);
    }

  closemap ();
  #ifdef DEBUG
	  debug("after closemap");
  #endif

  if ( x == 0 )
  {
	if (compile_object)
	{
		sprintf (buff, "gcc %s.c -c -o %s.o %s",a,a,incl_path);
		printf ("%s\n",buff);
		sprintf (buff,"%s > %s.err 2>&1",buff,a);
		#ifdef DEBUG
			debug("Runnung $s",buff);
        #endif
		ret=system (buff);
        //see function system_run() in fglwrap.c
		if (ret) {
			printf ("Error compiling %s.c - check %s.err\n",a,a);
			//fixme: show err file
            return ret;
        }
	}
  }

  return x;

}


/* ================================ EOF ============================== */
