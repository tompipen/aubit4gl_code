#include <stdio.h>

#if (defined(__CYGWIN__)) || defined(__MINGW32__)
	/* missing from rpcgen generated .h on CygWin: */
	#define bool_t int
	#define u_int unsigned int
#endif

#include "npcode.h"
#include "npcode_defs.h"
extern FILE *yyin;
extern int yydebug;

int yyparse (void);
int debug_mode = 0;

char fout[256]="a.4pe";

struct module this_module;

int
main (int argc, char *argv[])
{
  int a;

//yydebug=1;

  this_module.fglc_magic = FGLC_XDR_MAGIC;
  this_module.fglc_version = FGLC_XDR_VERSION;

  if (strcmp (argv[1], "-") == 0)
    {
      this_module.module_name = "-";
      yyin = stdin;
      strcpy(fout,"a.4pe");
    }
  else
    {
	char *ptr;
      this_module.module_name = strdup (argv[1]);
      yyin = fopen (argv[1], "r");
      strcpy(fout,argv[1]);
      ptr=strrchr(fout,'.');
	if (ptr) {
		*ptr=0;
	}
	strcat(fout,".4pe");
    }

  if (argc > 2)
    {
      if (strcmp (argv[2], "-d") == 0)
	{
	  debug_mode = 1;
	}
      if (strcmp (argv[2], "-D") == 0)
	{
	  debug_mode = 1;
	  yydebug = 1;
	}
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

  add_id ("");
  add_function ("__MODULE", 0, 1);
  end_main ();

  {
    char *ptr;
    ptr = malloc (1024 * 1024 * 16);
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
    yyparse ();
  else
    {
      printf ("Unable to open input file\n");
      exit (2);
    }

  end_define_module ();

  set_externs ();
  //resolve_gotos ();
  move_defines ();


  A4GL_debug ("String table has %d entries\n",
	      this_module.string_table.string_table_len);


  //print_module();

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
  return 0;
}


int
yyerror (char *s)
{
  printf ("%s\n", s);
  exit (1);
}


void *
get_var_ptr (struct use_variable *use_var)
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
