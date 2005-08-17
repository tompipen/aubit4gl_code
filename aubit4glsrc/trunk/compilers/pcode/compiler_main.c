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
# $Id: compiler_main.c,v 1.17 2005-08-17 13:43:12 mikeaubury Exp $
#*/

/**
 * @file
 *
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include <stdio.h>
#include <string.h>

#if (defined(__CYGWIN__)) || defined(__MINGW32__)
	/* missing from rpcgen generated .h on CygWin: */
#define bool_t int
#define u_int unsigned int
#endif
int do_optimise=0;
#ifdef RPCGEN_HEADERS
	#include "npcode.h"
#else
	#include "npcode.xs.h"
#endif
#include "npcode_defs.h"
#include "a4gl_memhandling.h"
#include "time.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

extern FILE *yyin;
extern int yydebug;

int debug_mode = 0;

static char fout[256] = "a.4pe";

struct module this_module;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

int yyparse (void);


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
main (int argc, char *argv[])
{
  int a;
  int got_input = 0;
  int ignore_next = 0;

  this_module.fglc_magic = FGLC_XDR_MAGIC;
  this_module.fglc_version = FGLC_XDR_VERSION;

  if (argc == 1)
    {
      printf ("\n");
      printf ("Aubit C to P-code compiler. Usage:\n");
      printf ("\n");
      printf (" -d : debug mode\n");
      printf (" -y : debug mode + yydebug\n");
      printf
	(" -D -L -I -o -l -c flags are accepted for compatibility with C compiler, but ignored\n");
      printf ("\n");
      exit (1);
    }

  if (strcmp (argv[1], "-") == 0)
    {
      this_module.module_name = "-";
      yyin = stdin;
      strcpy (fout, "a.4pe");
    }
  else
    {
      char *ptr = 0;
      char arg[256];
      char c12 [3];


      for (a = 1; a < argc; a++)
	{
	  if (ignore_next == 1)
	    {
	      ignore_next = 0;
	      continue;
	    }

	  strcpy (arg, argv[a]);
	  sprintf (c12, "%c%c", arg[0], arg[1]);

	  if (strcmp (argv[a], "-d") == 0)
	    {
	      //printf("got -d\n");
	      debug_mode = 1;
	    }
	  else if (strcmp (argv[a], "-y") == 0)
	    {
	      //printf("got -y\n");
	      debug_mode = 1;
	      yydebug = 1;
	    }
	  else if (strcmp (c12, "-I") == 0)
	    {
	      //printf("got -I\n");
	      // -I flag: ignore
	      continue;
	    }
	  else if ( strcmp (c12, "-O") == 0|| strcmp (c12, "-O1") == 0|| strcmp (c12, "-O2") == 0)
	    {
		do_optimise=1;
	      continue;
	    }


	  else if (strcmp (c12, "-L") == 0)
	    {
	      //printf("got -L\n");
	      // -L flag: ignore
	      continue;
	    }
	  else if (strcmp (c12, "-D") == 0)
	    {
	      //printf("got -D\n");
	      // -D flag: ignore
	      continue;
	    }
	  else if (strcmp (c12, "-o") == 0)
	    {
	      //printf("got -o\n");
	      // -o flag: ignore
	      ignore_next = 1;
	      continue;
	    }
	  else if (strcmp (c12, "-l") == 0)
	    {
	      //printf("got -l\n");
	      // -l flag: ignore
	      continue;
	    }
	  else if (strcmp (c12, "-c") == 0)
	    {
	      //printf("got -c\n");
	      // -c flag: ignore
	      continue;
	    }
	  else
	    {
	      this_module.module_name = acl_strdup (argv[a]);
	      //printf ("Opening input file %s\n",argv[a]);
	      yyin = fopen (this_module.module_name, "r");
	      if (yyin == 0)
		{
		  printf ("Unable to open input file %s\n",
			  this_module.module_name);
		  exit (2);
		}
	      else
		{
		  strcpy (fout, this_module.module_name);
		  ptr = strrchr (fout, '.');
		  if (ptr)
		    {
		      *ptr = 0;
		    }
		  strcat (fout, ".4pe");
		  got_input = 1;
		}
	    }			//end if
	}			//end for
    }

  if (got_input == 0)
    {
      printf ("ERROR: no input file\n");
      exit (13);
    }

  do_compiler_start (argc, argv);

  this_module.compiled_time = time (0);
  this_module.file_size = 0;
  this_module.string_table.string_table_len = 0;
  this_module.string_table.string_table_val = 0;

  this_module.id_table.id_table_len = 0;
  this_module.id_table.id_table_val = 0;

  //this_module.module_variables.c_vars.c_vars_len = 0;
  //this_module.module_variables.c_vars.c_vars_val = 0;

  this_module.functions.functions_len = 0;
  this_module.functions.functions_val = 0;

  this_module.params.params_len = 0;
  this_module.params.params_val = 0;
  {
	int n;
	struct param *p;
  	make_new_param(&n,&p);
	p->param_type=PARAM_TYPE_NULL;
  	make_new_param(&n,&p);
	p->param_type=PARAM_TYPE_EMPTY;
  }

  add_id ("");
  add_function ("__MODULE", 0, 1);
  end_main ();

  {
    char *ptr;
    ptr = acl_malloc2 (1024 * 1024 * 16);
    free (ptr);			// Should speed things up a little...
  }

  this_module.external_function_table.external_function_table_len = 0;
  this_module.external_function_table.external_function_table_val = 0;

  A4GL_debug ("STring table : %d entries\n",
	      this_module.string_table.string_table_len);

  for (a = 0; a < this_module.string_table.string_table_len; a++)
    {
      A4GL_debug ("%d. %s\n", a,
		  this_module.string_table.string_table_val[a].s);
    }


  add_default_named_structs ();	// For things like BINDING...

  if (yyin)
    {
      yyparse ();
    }
  else
    {
      printf ("Unable to open input file\n");
      exit (2);
    }

  end_define_module ();

  set_externs ();
  move_defines ();

  A4GL_debug ("String table has %d entries\n", this_module.string_table.string_table_len);


  a = process_xdr ('O', &this_module, fout);
  if (a)
    {
      A4GL_debug ("Written ok %d\n", a);
    }
  else
    {
      printf ("Failed to write %d\n", a);
      exit (1);
    }


  if (do_optimise) {
  	optimize();
	
  	strcpy(fout,"optimised");
	
  	a = process_xdr ('O', &this_module, fout);
  	if (a)
    	{
      	A4GL_debug ("Written ok %d\n", a);
    	}
  	else
    	{
      	printf ("Failed to write %d\n", a);
      	exit (1);
    	}
  }

  return 0;
}


int
yyerror (char *s)
{
  extern int yylineno;
  printf ("%s @ line %d\n", s, yylineno);
  exit (1);
}


void *
get_var_ptr (struct use_variable *use_var,int *size)
{
  printf ("Shouldn't be using variables during compilation..\n");
  exit (1);
}

long
call_function (long pc, struct npcmd_call *c)
{
  printf ("Shouldn't be calling functions during compilation..\n");
  exit (1);
}


/* ================================= EOF ============================== */
