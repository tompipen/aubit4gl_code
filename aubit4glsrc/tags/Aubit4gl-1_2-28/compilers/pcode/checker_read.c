#if (defined(__CYGWIN__)) || defined(__MINGW32__)
	/* missing from rpcgen generated .h on CygWin: */
	#define bool_t int
	#define u_int unsigned int
#endif

#ifdef RPCGEN_HEADERS
	#include "npcode.h"
#else
	#include "npcode.xs.h"
#endif

#include "npcode_defs.h"
void print_module (void);

module this_module;
module *this_module_ptr=0;



char *
get_string (int a)
{
  return this_module.string_table.string_table_val[a].s;
}



int
main (int argc, char *argv[])
{
  int a;
  this_module_ptr=&this_module;
  if (argc != 2)
    {
      printf ("Usage %s filename.4pe\n", argv[0]);
      exit (1);
    }
do_compiler_start (argc, argv);
  a = process_xdr ('I', &this_module, argv[1]);

  if (a)
    {
      A4GL_debug ("Opened OK\n");
    }
  else
    {
      printf ("Failed to open %s\n", argv[1]);
      exit (1);
    }


  print_module ();
  return 0;
}




void *
get_var_ptr (struct use_variable *use_var,int *size)
{
  printf ("Shouldn't be using variables during checking..\n");
  exit (1);
}

long
call_function (long pc, struct npcmd_call *c)
{
  printf ("Shouldn't be calling functions during checking..\n");
  exit (1);
}
