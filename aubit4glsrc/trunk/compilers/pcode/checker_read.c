#if (defined(__CYGWIN__)) || defined(__MINGW32__)
	/* missing from rpcgen generated .h on CygWin: */
	#define bool_t int
	#define u_int unsigned int
#endif

#include "npcode.h"
#include "npcode_defs.h"
void print_module (void);
module this_module;

char *cmd_type_str[] = {
  "CMD_NULL",
  "CMD_BLOCK",
  "CMD_END_BLOCK",
  "CMD_CALL",
  "CMD_IF",
  "CMD_SET_VAR",
  "CMD_SET_VAR_ONCE",
  "CMD_GOTO_LABEL",
  "CMD_GOTO_PC",
  "CMD_RETURN",
  "CMD_NOP",
  "CMD_PUSH_LONG",
  "CMD_PUSH_INT",
  "CMD_PUSH_CHAR",
  "CMD_CHK_ERR",
  "CMD_PUSH_VARIABLE",
  "CMD_END_4GL_0",
  "CMD_END_4GL_1",
  "CMD_DISPLAY_AT",
  "CMD_PUSH_OP",
  "CMD_CLR_ERR",
  ""
};


char *
get_string (int a)
{
  return this_module.string_table.string_table_val[a].s;
}



int
main (int argc, char *argv[])
{
  int a;

  if (argc != 2)
    {
      printf ("Usage %s filename.4pe\n", argv[0]);
      exit (1);
    }
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
get_var_ptr (struct use_variable *use_var)
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
