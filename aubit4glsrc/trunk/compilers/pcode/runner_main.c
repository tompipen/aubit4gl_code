#if (defined(__CYGWIN__)) || defined(__MINGW32__)
	/* missing from rpcgen generated .h on CygWin: */
	#define bool_t int
	#define u_int unsigned int
#endif
#define NEED_CMD_TYPE_STR

#include <stdio.h>
#include "npcode.h"
#include "npcode_defs.h"
//#include "a4gl_incl_4glhdr.h"
extern module this_module;
#define FglMoney long
#define FglDecimal long
#define fgldate long

//int            *use_block_stack_id;
//struct cmd_block **   use_block_stack=0;
//int            *      use_block_stack_cnt=0;



FILE *logfile;
struct cmd_block *module_vars = 0;


extern long int_flag;
extern long quit_flag;
extern long a4gl_status;
extern struct
{
  long sqlcode;
  char sqlerrm[72 + 1];
  char sqlerrp[8 + 1];
  long sqlerrd[6];
  char sqlawarn[8 + 1];
  char sqlstate[9 + 1];
}
a4gl_sqlca;
extern fgldate today;
extern char user[8 + 1];

extern long pageno;
extern long lineno;
extern long usrtime;
extern long curr_hwnd;
extern long curr_form;
extern char err_file_name[32 + 1];
extern long err_file_no;
extern char curr_file_name[32 + 1];
extern long curr_line_no;
extern long err_status;
extern long aiplib_status;


long run_function_int (int func_no, int module_special, struct param *p);

long
run_function (int func_no, struct param *p)
{
  return run_function_int (func_no, 0, p);
}

long
run_module_init ()
{
  return run_function_int (0, 1, 0);
}


int
run_module ()
{
  int a;
  int pc_for_main;
  struct param main_params;
  struct param main_params_2;

  if (this_module.fglc_magic != FGLC_XDR_MAGIC)
    {
      fprintf (stderr, "This does not appear to be a valid 4GL file\n");
      exit (1);
    }

  if (this_module.fglc_version != FGLC_XDR_VERSION)
    {
      fprintf
	(stderr,
	 "This module was compiled as pcode version %4.2f - this is a version %4.2f runner\n",
	 (((float) this_module.fglc_version) / 100.0),
	 (((float) FGLC_XDR_VERSION) / 100.0));
      exit (1);
    }



  pc_for_main = -1;

  fprintf (logfile, "INITIALIZING MODULE\n");
  run_module_init ();
  fprintf (logfile, "DONE...\n");


// 0  will always be __MODULE - so no point checking that...
//
  for (a = 1; a < this_module.functions.functions_len; a++)
    {
      if (strcmp
	  (GET_ID (this_module.functions.functions_val[a].func_name_id),
	   "main") == 0)
	{
	  pc_for_main = a;
	  break;
	}
    }

  if (pc_for_main == -1)
    {
      fprintf (stderr, "Could not find a 'MAIN'\n");
      exit (11);
    }

  fprintf (logfile, "Running 'main' - function no %d\n", a);

  main_params.param_type = PARAM_TYPE_LIST;
  main_params.param_u.p_list = malloc (sizeof (struct param_list));
  main_params.param_u.p_list->list_param_id.list_param_id_len = 1;
  main_params.param_u.p_list->list_param_id.list_param_id_val = malloc(sizeof(long));
  nset_param(&main_params_2,0);

  main_params.param_u.p_list->list_param_id.list_param_id_val[0]=-1;

  main_params_2.param_type = PARAM_TYPE_LITERAL_INT;
  main_params_2.param_u.n = 0;
  run_function (a, &main_params);
  return 1;
}






long
find_pcode_function (char *s)
{
  int a;
  for (a = 0; a < this_module.functions.functions_len; a++)
    {
      if (strcmp
	  (GET_ID (this_module.functions.functions_val[a].func_name_id),
	   s) == 0)
	{
	  return a;
	}
    }
  return -1;
}

long
run_function_int (int func_no, int module_special, struct param *p)
{
  long pc = 0;
  struct cmd *c;
  long i;


/* 
First things first - initialize our block 
this should be the first thing in our function, always @ PC=0
*/
  c = &this_module.functions.functions_val[func_no].cmds.cmds_val[pc];
  if (c->cmd_type != CMD_BLOCK)
    {
      fprintf (stderr,
	       "First thing in a function should always be a block...\n");
      exit (74);
    }
  execute_start_block (0, c->cmd_u.c_block);
  pc++;


  fprintf (logfile, "Entering function %s\n",
	   GET_ID (this_module.functions.functions_val[func_no].
		   func_name_id));fflush(logfile);

/* 
Now - did we get any parameters passed in at all 
Normally we should get a value for p - even if it contains a 0 length list
*/

  if (p)
    {
      fprintf (logfile, "Have some parameters...\n");fflush(logfile);
      if (p->param_type != PARAM_TYPE_LIST)
	{
	  fprintf (stderr, "Internal error - param_type (%d) != PARAM_TYPE_LIST\n",p->param_type);
	  exit (82);
	}
      else
	{
	  int got;
	  int expecting;
	  int a;
	  struct cmd_set_var sv;
	  expecting =
	    this_module.functions.functions_val[func_no].param_vars.
	    param_vars_len;
	  got = p->param_u.p_list->list_param_id.list_param_id_len;
	  if (got != expecting)
	    {
	      fprintf (stderr, "Expecting %d parameters - got %d\n",
		       expecting, got);
	      exit (83);
	    }
	  else
	    {
	      fprintf (logfile, "Got %d parameters - as expected\n", got);fflush(logfile);
	    }

	  for (a = 0; a < got; a++)
	    {
	      struct use_variable *sv_var;
	      //long sv_val;
	      sv_var = &sv.variable;
	      sv.value_param_id=p->param_u.p_list->list_param_id.list_param_id_val[a];
	      memcpy (sv_var, &this_module.functions.functions_val[func_no].  param_vars.param_vars_val[a], sizeof (struct use_variable));
	      set_var (0, &sv);
	    }
	}
    }
  else
    {
      fprintf (logfile, "No parameters\n");fflush(logfile);
    }


/* 
Now we've done our function startup - we can get on with actually running it...
*/

  while (1)
    {

      fprintf (logfile, "%04d-%04ld ", func_no, pc);fflush(logfile);

      if (pc >= this_module.functions.functions_val[func_no].cmds.cmds_len)
	{
	  if (module_special)
	    return 0;
	  fprintf (stderr, "FUNCTION OVERFLOW...\n");
	  exit (1);
	}

      c = &this_module.functions.functions_val[func_no].cmds.cmds_val[pc];
      fprintf (logfile, "%-10.10s %03d\n", cmd_type_str[c->cmd_type], c->cmd_type); fflush(logfile);


      switch (c->cmd_type)
	{
	case CMD_NULL:
	  pc++;
	  break;
	case CMD_BLOCK:
	  fprintf (stderr,
		   "Should only be one block in a function and I should have already run that - my head hurt, i'm going to lie down\n");
	  exit (88);
//execute_start_block(pc,c->cmd_u.c_block);pc++; break;
	case CMD_NOP:
	  pc++;
	  break;		// This is a no-op - do nothing...
	case CMD_END_BLOCK:
	  execute_end_block ();
	  pc++;
	  break;
	case CMD_CALL:
	  call_function (pc, c->cmd_u.c_call);
	  pc++;
	  break;
	case CMD_IF:
	  evaluate_param_i_into_integer (c->cmd_u.c_if->condition_param_id, &i);
	  if (i)
	    {
fprintf (logfile,"Condition is true : %ld\n",i);
	      pc = pc + c->cmd_u.c_if->goto_true;
	      if (c->cmd_u.c_if->goto_true == 0)
		pc++;		// NOP GOTO
	    }
	  else
	    {
fprintf (logfile,"Condition is false : %ld\n",i);
	      pc = pc + c->cmd_u.c_if->goto_false;
	      if (c->cmd_u.c_if->goto_false == 0)
		pc++;		// NOP GOTO
	    }
	  break;
	case CMD_SET_VAR:
	  set_var (pc, c->cmd_u.c_setvar);
	  pc++;
	  break;
	case CMD_SET_VAR_ONCE:
	  set_var_once (pc, c->cmd_u.c_setvar1);
	  pc++;
	  break;
	case CMD_GOTO_LABEL:
	  fprintf (stderr, "Unresolved goto remains...\n");
	  exit (1);
	case CMD_GOTO_PC:
	  pc = pc + c->cmd_u.c_goto_pc;
	  if (c->cmd_u.c_goto_pc == 0)
	    pc++;		// NOP GOTO 
	  break;


	case CMD_RETURN:
	  if (c->cmd_u.c_return_param_id>1) {
	  	evaluate_param_i_into_integer (c->cmd_u.c_return_param_id, &i);
	  } else {
		i=0;
	  }

	  if (!module_special)
	    {
	      // Deallocate any variables
	    }

	  fprintf (logfile, "Leaving function\n");fflush(logfile);
	  execute_end_block ();
	  return i;



	default:
	  if (!special_cmd(c)) {
	  	fprintf (stderr, "Unimplemented command in runner_main.c\n");
	  	exit (1);
	  } else {
		pc++;
		break;
	  }
	}
    }
  fprintf (logfile, "Leaving function badly\n");fflush(logfile);
  return 0;
}





int
main (int argc, char *argv[])
{
  if (argc != 2)
    {
      printf ("Usage : %s progname\n", argv[0]);
      exit (1);
    }

  logfile = fopen ("pcode.run", "w");
  if (logfile == 0)
    {
      printf ("Unable to open logfile\n");
      exit (2);
    }
  init_calls (argc, argv);

  exit (open_and_run (argv[1]));
}
