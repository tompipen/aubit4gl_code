#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
#include "a4gl_memhandling.h"

char **call_list;
int ncalls = 0;
int is_in_function = 0;
long called[1000];

long find_function (char *s);
extern module this_module;
void print_set_var (struct cmd_set_var *v);

#define LABELSCNT 100000
struct label labels[LABELSCNT];
int labels_cnt = 0;
static void resolve_gotos_func (int function_cnt);

long pc = 0;


	// An individual command
struct label
{
  char *str;
  int pc;
};


void *label_tree = 0;

struct npfunction *current_function;






void
set_externs ()
{
  int n;
  int a;
  n = 0;
  for (a = 0; a < ncalls; a++)
    {
      if (find_function (call_list[a]) != -1)
	continue;
      n++;
    }


  if (n == 0)
    return; 


   this_module.external_function_table.external_function_table_val = acl_malloc2 (sizeof (char *) * n);
  this_module.external_function_table.external_function_table_len = n;
  n = 0;


  for (a = 0; a < ncalls; a++)
    {
      if (find_function (call_list[a]) != -1) continue;
      this_module.external_function_table.external_function_table_val[n] = add_id (call_list[a]);
      A4GL_debug ("CALLS : %s\n", call_list[a]);
	printf("%s %ld\n",call_list[a],called[a]);
      n++;
    }
}


void add_called (char *s)
{
  int a;
  for (a = 0; a < ncalls; a++)
    {
      if (strcmp (call_list[a], s) == 0) {
			called[a]++;
			return;
	}
    }
  ncalls++;

  call_list = realloc (call_list, sizeof (char *) * ncalls);
  call_list[ncalls - 1] = acl_strdup (s);
  called[ncalls-1]=1;
}




long
find_function (char *s)
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
new_command (enum cmd_type cmd_type, void *ptr)
{
//int a;
  if (this_module.functions.functions_len == 0)
    {
      printf ("No current function to add a command to....\n");
      exit (1);
    }

  if (cmd_type == CMD_NULL)
    {
      printf ("CMD NULL PASSED IN\n");
      exit (2);
    }
  current_function =
    &this_module.functions.functions_val[this_module.functions.functions_len -
					 1];
/*
  for (a=0;a<current_function->cmds.cmds_len;a++) {
		if (current_function->cmds.cmds_val[a].cmd_type==CMD_NULL) {
				printf("Whoops - something got splatted\n");
				exit(2);
		}
  }
*/


  current_function->cmds.cmds_len++;
  current_function->cmds.cmds_val =
    realloc (current_function->cmds.cmds_val,
	     sizeof (struct cmd) * current_function->cmds.cmds_len);



#define CURRENT_CMD current_function->cmds.cmds_val[current_function->cmds.cmds_len - 1]

  CURRENT_CMD.cmd_type = cmd_type;

  switch (cmd_type)
    {
    case CMD_BLOCK:
      CURRENT_CMD.cmd_u.c_block = ptr;
      break;

    case CMD_END_BLOCK:
      CURRENT_CMD.cmd_u.c_endblock = ptr;
      break;

    case CMD_CALL:
      CURRENT_CMD.cmd_u.c_call = ptr;
      break;

    case CMD_IF:
      CURRENT_CMD.cmd_u.c_if = ptr;
      break;

    case CMD_SET_VAR:
      CURRENT_CMD.cmd_u.c_setvar = ptr;
      break;

    case CMD_SET_VAR_ONCE:
      CURRENT_CMD.cmd_u.c_setvar1 = ptr;
      break;


    case CMD_GOTO_LABEL:
      CURRENT_CMD.cmd_u.c_goto_str = (long) ptr;
      break;

    case CMD_GOTO_PC:
      CURRENT_CMD.cmd_u.c_goto_pc = (long) ptr;
      break;

    case CMD_RETURN:
      CURRENT_CMD.cmd_u.c_return_param_id = (long) ptr;
      break;

    case CMD_PUSH_LONG:
      CURRENT_CMD.cmd_u.c_push_long = (int) ptr;
      break;

    case CMD_PUSH_OP:
      CURRENT_CMD.cmd_u.c_push_op = (int) ptr;
      break;

    case CMD_SET_STAT:
      CURRENT_CMD.cmd_u.c_setval = (int) ptr;
      break;

    case CMD_SET_LINE:
      CURRENT_CMD.cmd_u.c_cline = (int) ptr;
      break;

    case CMD_ECALL:
      CURRENT_CMD.cmd_u.c_ecall = (struct ecall *) ptr;
      break;

    case CMD_PUSH_CHAR:
      CURRENT_CMD.cmd_u.c_push_char = (int) ptr;
      break;

    case CMD_PUSH_CHARV:
      CURRENT_CMD.cmd_u.c_var_param_id = (long) ptr;
      break;

    case CMD_PUSH_INT:
      CURRENT_CMD.cmd_u.c_push_int = (int) ptr;
      break;

    case CMD_CHK_ERR:
      CURRENT_CMD.cmd_u.c_chk_err_lineno = (long) ptr;
      break;

    case CMD_ERRCHK:
      CURRENT_CMD.cmd_u.c_errchk = (struct cmd_errchk *) ptr;
      break;

    case CMD_ERRCHK_40110:
      CURRENT_CMD.cmd_u.c_errchk_40110 = (struct cmd_errchk_40110 *) ptr;
      break;

    case CMD_ERRCHK_40010:
      CURRENT_CMD.cmd_u.c_errchk_40010 = (struct cmd_errchk_40010 *) ptr;
      break;

    case CMD_ERRCHK_40000:
      CURRENT_CMD.cmd_u.c_errchk_40000 = (struct cmd_errchk_40000 *) ptr;
      break;

    case CMD_POP_ARGS:
      CURRENT_CMD.cmd_u.c_pop_args = (long) ptr;
      break;

    case CMD_CLR_ERR:
	case CMD_PUSH_OP_AND:
        case CMD_PUSH_OP_OR:
        case CMD_PUSH_OP_EQUAL:
        case CMD_PUSH_OP_CONCAT:
        case CMD_PUSH_OP_ISNULL:
      break;

        case CMD_PUSH_FUNCTION:
        case CMD_POP_FUNCTION:
        case CMD_POP_PARAM:
        case CMD_POP_VAR2:
		break;

    default:
      printf ("Unknown Command : %d", cmd_type);
      exit (1);
    }
  //printf("New command : %d in %p -> %d\n",this_module.functions.functions_val[this_module.functions.functions_len-1].cmds.cmds_len-1,&this_module.functions.functions_val[this_module.functions.functions_len-1],cmd_type);
  return this_module.functions.functions_val[this_module.functions.
					     functions_len -
					     1].cmds.cmds_len - 1;
//this_module.functions.functions_len - 1;
}


long add_call (char *funcname, long params_i)
{
  struct npcmd_call *c;
  c = acl_malloc2 (sizeof (struct npcmd_call));
  c->func_id = add_id (funcname);
  c->func_params_param_id = params_i;
  add_called (funcname);
  return new_command (CMD_CALL, c);
}


long add_block (void *ptr_c_vars)
{
  struct cmd_block *blk;
  long pc;
  blk = acl_malloc2 (sizeof (struct cmd_block));
  blk->c_vars.c_vars_len = 0;
  blk->c_vars.c_vars_val = 0;
  blk->mem_for_vars = 0;
  blk->mem_to_alloc = 0;

  pc = new_command (CMD_BLOCK, blk);

  //printf("Adding block ... %ld\n",pc);
  add_block_var (blk, pc);

  return pc;
}


long xadd_set_var (struct use_variable *var_orig, long value, int once)
{
  struct cmd_set_var *v=0;
  struct cmd_set_var1 *v1=0;
  struct use_variable *var=0;
  struct use_variable *var2 = 0;
  struct  variable_element *var_element=0;
  int pc=0;
  int vid=0;
  int block=0;

printf("\n\nAdd set var\n");
  var = acl_malloc2 (sizeof (struct use_variable));
  memcpy (var, var_orig, sizeof (struct use_variable));

  printf ("In add set var : ");
  print_use_variable (var);
  printf ("\n");

  v = acl_malloc2 (sizeof (struct cmd_set_var));
  v1 = acl_malloc2 (sizeof (struct cmd_set_var1));

  A4GL_debug ("sizes : %d %d\n", sizeof (v->variable),
	      sizeof (struct use_variable));

  memcpy (&(v->variable), var, sizeof (struct use_variable));
  memcpy (&(v1->variable), var, sizeof (struct use_variable));

  if (this_module.params.params_val[value].param_type == PARAM_TYPE_LIST)
    {
      struct cmd_block *base;
      int a;
      struct npvariable *variable;
      int found = -1;
      //
      vid = v->variable.variable_id;
      block = v->variable.defined_in_block_pc;
      printf ("PARAM TYPE LIST IN ASSIGNMENT %d %d\n", vid, block);
      //this_module.
      base = (struct cmd_block *) get_base (block);
      printf ("Base=%p\n", base);

      for (a = 0; a < base->c_vars.c_vars_len; a++)
	{
	  printf ("Bibble\n");
	  printf ("ID : %ld\n", base->c_vars.c_vars_val[a].variable_id);
	  if (base->c_vars.c_vars_val[a].variable_id == vid)
	    {
	      found = a;
	      break;
	    }
	}

      if (found == -1)
	{
	  printf ("VID not found\n");
	  exit (2);
	}

      variable = &base->c_vars.c_vars_val[found];
      printf ("var=%p\n", variable);
      printf ("Variable ID =%ld\n", variable->variable_id);
      printf ("Variable VAR =%p\n", variable->var);
      printf ("Variable NAME =%s\n", GET_ID (variable->var->name_id));

      printf ("Next cnt= %d\n", variable->var->next.next_len);
      printf ("Array Sizes= %ld %ld %ld\n", variable->var->i_arr_size[0],
	      variable->var->i_arr_size[1], variable->var->i_arr_size[2]);


      var_element=variable->var;


      if (var->sub.sub_len==0) {
		printf("Sub_len=0\n");
      } else {
		int a;
 		for (a=0;a<var->sub.sub_len;a++) {

  	printf ("%d   x1=%ld sub1=%ld sub2=%ld sub3=%ld\n", a,var->sub.sub_val[a].x1element, var->sub.sub_val[a].x1subscript_param_id[a], var->sub.sub_val[a].x1subscript_param_id[1], var->sub.sub_val[a].x1subscript_param_id[2]);

		}
	}


      if (var->sub.sub_len)
	{
	int a;
	  	printf ("Got a sub_len on the assignment - so not looking for all of variable - len= %d\n", var->sub.sub_len);
	  	printf ("x1=%ld sub1=%ld sub2=%ld sub3=%ld\n", var->sub.sub_val[0].x1element, var->sub.sub_val[0].x1subscript_param_id[0], var->sub.sub_val[0].x1subscript_param_id[1], var->sub.sub_val[0].x1subscript_param_id[2]);

		if (var->sub.sub_val[0].x1element!=-1) {
	  		a=0;
			while (a<var->sub.sub_len) {
				printf("Assign %d\n",a);
	  			var_element=&var_element->next.next_val[var->sub.sub_val[a].x1element];
				a++;
			}
		}

		
	}





	
	  // Lets play...

	  if (var_element->i_arr_size[0] && var_element->i_arr_size[1] && var_element->i_arr_size[2] == 0)
	    {
	      int a;
	      int b;
	      // Add as 2 dimensional array...
	      a = 0;
	      b = 0;
	      while (1)
		{
		  //struct param *sublist;
		  struct param *subparam;
		  int n;
		  //int sublist_n;
		  int npid_a;

		  var2 = acl_malloc2 (sizeof (struct use_variable));
		  memcpy (var2, var, sizeof (struct use_variable));

		  printf ("---> %d %d\n", a,
			  this_module.params.params_val[value].param_u.
			  p_list->list_param_id.list_param_id_len);
		  if (a >=
		      this_module.params.params_val[value].param_u.p_list->
		      list_param_id.list_param_id_len)
		    break;
		  if (a >= var_element->i_arr_size[0])
		    {
		      printf ("Excess elements ignored (1)\n");
		      break;
		    }

		  n =
		    this_module.params.params_val[value].param_u.p_list->
		    list_param_id.list_param_id_val[a];
		  subparam = acl_malloc2 (sizeof (struct param));
		  memcpy (subparam, &this_module.params.params_val[n],
			  sizeof (struct param));
		  if (subparam->param_type != PARAM_TYPE_LIST)
		    {
		      printf ("Expecting a list containing another list\n");
		      exit (3);
		    }

		  npid_a = new_param_returns_long ('I', (void *) a);
		  printf ("doing b\n");
		  for (b = 0;
		       b <
		       subparam->param_u.p_list->list_param_id.
		       list_param_id_len; b++)
		    {
		      printf ("sub : %d = %ld\n", b,
			      subparam->param_u.p_list->list_param_id.
			      list_param_id_val[b]);
		    }
		  b = 0;

		  while (1)
		    {
		      int npid_b;
		      int nb;
		      printf ("subparam=%p\n", subparam);
		      printf ("sub type1 : %d\n", subparam->param_type);
		      if (subparam->param_type != PARAM_TYPE_LIST)
			{
			  printf
			    ("Got confused... - subparam is not a list\n");
			  exit (2);
			}
		      if (b >=
			  subparam->param_u.p_list->list_param_id.
			  list_param_id_len)
			break;
		      if (b >= var_element->i_arr_size[1])
			{
			  printf ("Excess elements ignored (2)\n");
			  break;
			}
		      printf ("sub type2 : %d\n", subparam->param_type);
		      var2->sub.sub_val =
			acl_malloc2 (sizeof (struct use_variable_sub));
		      var2->sub.sub_len = 1;
		      var2->sub.sub_val[0].x1element = -1;
		      var2->sub.sub_val[0].x1subscript_param_id[0] = 0;
		      var2->sub.sub_val[0].x1subscript_param_id[1] = 0;
		      var2->sub.sub_val[0].x1subscript_param_id[2] = 0;
		      printf ("sub type3 : %d\n", subparam->param_type);

		      npid_b = new_param_returns_long ('I', (void *) b);
		      var2->sub.sub_val[0].x1subscript_param_id[0] = npid_a;
		      var2->sub.sub_val[0].x1subscript_param_id[1] = npid_b;
		      print_use_variable (var2);

		      printf ("\nSetting to param ID %ld (%d, %d) n=%d\n",
			      subparam->param_u.p_list->list_param_id.
			      list_param_id_val[b], a, b, n);
		      if (subparam->param_u.p_list->list_param_id.
			  list_param_id_val[b] == 0)
			{
			  printf ("Invalid param id\n");
			  exit (2);
			}
		      nb =
			subparam->param_u.p_list->list_param_id.
			list_param_id_val[b];
		      printf ("New param=%d\n", nb);
		      printf ("sub type4 : %d\n", subparam->param_type);
		printf("Calling add_set_Var (1)...\n");
		      pc = add_set_var (var2, nb, once,0);
		      printf ("sub type5 : %d\n", subparam->param_type);
		      printf ("PC=%d for %d,%d (%d %d)\n", pc, a, b, npid_a,
			      npid_b);
		      b++;
		    }
		  a++;
		}
	    }


	  if (var_element->i_arr_size[0] && var_element->i_arr_size[1] == 0)
	    {
	      int a;
	      // Add as array...
	      a = 0;
	      while (1)
		{
		  int npid;
		  if (a >= this_module.params.params_val[value].param_u.p_list-> list_param_id.list_param_id_len) break;

		  if (a >= var_element->i_arr_size[0])
		    {
		      printf ("Excess elements ignored (3)\n");
		      break;
		    }
		  var2 = acl_malloc2 (sizeof (struct use_variable));
		  memcpy (var2, var, sizeof (struct use_variable));
		  var2->sub.sub_val = acl_malloc2 (sizeof (struct use_variable_sub));
		  var2->sub.sub_len = 1;
		  var2->sub.sub_val[0].x1element = -1;
		  var2->sub.sub_val[0].x1subscript_param_id[0] = 0;
		  var2->sub.sub_val[0].x1subscript_param_id[1] = 0;
		  var2->sub.sub_val[0].x1subscript_param_id[2] = 0;
		  npid = new_param_returns_long ('I', (void *) a);
		  printf ("npid = %d for %d\n", npid, a);

		  var2->sub.sub_val[0].x1subscript_param_id[0] = npid;
		  print_use_variable (var2);
		printf("Calling add_set_Var (2)... (var_element->x1element=%d)\n",var_element->next.next_len);
		  pc = add_set_var (var2, this_module.params.params_val[value].param_u.  p_list->list_param_id.list_param_id_val[a], once,0);
		  printf ("PC=%d\n", pc);
		  a++;
		}
	    }


	  if (var_element->i_arr_size[0] == 0)
	    { // This is a straight assignment to structure..

		int a;
		a=0;
	      while (1)
		{
		  int npid;
			printf("Straight assign\n");
		  if (a >= this_module.params.params_val[value].param_u.p_list-> list_param_id.list_param_id_len) break;

		if (a>=var_element->next.next_len) {
			printf("Excess elements for structure (4)\n");
			break;
		}
		  var2 = acl_malloc2 (sizeof (struct use_variable));
		  memcpy (var2, var, sizeof (struct use_variable));
		  var2->sub.sub_val = acl_malloc2 (sizeof (struct use_variable_sub));
		  var2->sub.sub_len = 1;

		  var2->sub.sub_val[0].x1element = a;
		  var2->sub.sub_val[0].x1subscript_param_id[0] = 0;
		  var2->sub.sub_val[0].x1subscript_param_id[1] = 0;
		  var2->sub.sub_val[0].x1subscript_param_id[2] = 0;
		  npid = new_param_returns_long ('I', (void *) a);

		printf("Calling add_set_Var (3)...\n");
		  pc = add_set_var (var2, this_module.params.params_val[value].param_u.  p_list->list_param_id.list_param_id_val[a], once,0);
		  printf ("npid = %d for %d for straight assign\n", npid, a);
		a++;
		}
	    }

	  return pc;
	}

    

  v->value_param_id = value;
  v1->value_param_id = value;

  if (once)
    {
      v1->set = 0;
      pc = new_command (CMD_SET_VAR_ONCE, v1);
    }
  else
    {
      pc = new_command (CMD_SET_VAR, v);
    }
  return pc;

}


long
current_pc ()
{
  current_function =
    &this_module.functions.functions_val[this_module.functions.functions_len -
					 1];
  return current_function->cmds.cmds_len - 1;
}









long add_goto (char *label)
{
  int a;
  a = find_label (label);

  if (a >= 0)
    {
      return new_command (CMD_GOTO_PC, (void *) a - current_pc () - 1);
    }
  else
    {
      return new_command (CMD_GOTO_LABEL, acl_strdup (label));
    }
}



long
end_function ()
{
  int a;
  do_end_block ();
  if (this_module.params.params_val[1].param_type != PARAM_TYPE_EMPTY)
    {
      printf ("NOT EMPTY\n");
    }
  new_command (CMD_RETURN, (void *) 1);
  is_in_function = 0;
  a = this_module.functions.functions_len - 1;
  resolve_gotos_func (a);

  return 0;
}


long
end_main ()
{
  is_in_function = 0;
  return 0;
}


long
end_block ()
{
  int begin_pc;
  struct cmd_end_block *b;
  b = acl_malloc2 (sizeof (struct cmd_end_block));
  begin_pc = do_end_block ();
  b->pc_start_block = begin_pc;

  return new_command (CMD_END_BLOCK, b);
}

long add_if (long e_i, char *true, char *false)
{
  struct npcmd_if *f;
  f = acl_malloc2 (sizeof (struct npcmd_if));
  f->condition_param_id = e_i;
  f->goto_true = (long) true;
  f->goto_false = (long) false;
  return new_command (CMD_IF, f);

}

long add_chk_err (int n)
{
  return new_command (CMD_CHK_ERR, (void *) n);
}

long add_errchk (void *n)
{
  return new_command (CMD_ERRCHK, (void *) n);
}
long add_errchk_40110 (void *n)
{
if (n==0) {
	printf("BAD errchk_40110\n");
	exit(4);
}
  return new_command (CMD_ERRCHK_40110, (void *) n);
}

long add_errchk_40010 (void *n)
{
if (n==0) {
	printf("BAD errchk_40010\n");
	exit(4);
}
  return new_command (CMD_ERRCHK_40010, (void *) n);
}


long add_errchk_40000 (void *n)
{
if (n==0) {
	printf("BAD errchk_40000\n");
	exit(4);
}
  return new_command (CMD_ERRCHK_40000, (void *) n);
}


long add_clr_err (void)
{
  return new_command (CMD_CLR_ERR, 0);
}

long add_push_long (int n) {
  return new_command (CMD_PUSH_LONG, (void *) n);
}

long add_push_substr(long e) {
	printf("Not implemented - substr\n");
	exit(2);
}

long add_pop_function() {
  return new_command (CMD_POP_FUNCTION,(void *)0);
}

long add_ecall (char *s, int a, int b)
{
  struct ecall *xptr;
  char *ptr;
  char *eptr;
  xptr = acl_malloc2 (sizeof (struct ecall));
  ptr = acl_strdup (&s[1]);
  eptr = &ptr[strlen (ptr) - 1];
  *eptr = 0;

  xptr->func_id = add_string (ptr);
  xptr->ln = a;
  xptr->nparam = b;
  return new_command (CMD_ECALL, (void *) xptr);
}



long add_set_stat (int a)
{
  //struct ecall *ptr;
  return new_command (CMD_SET_STAT, (void *) a);
}


long add_set_line (char *module,int line)
{
  	return new_command (CMD_SET_LINE, (void *) line);
}


long add_pop_args (int n)
{
  	return new_command (CMD_POP_ARGS, (void *) n);
}




long add_push_op (char *n)
{
  int ni;
  ni = atoi (n);
#define OP_ISNULL 0x800a
#define OP_AND 0x8007
#define OP_OR 0x8008
#define OP_EQUAL 0x8001
#define OP_CONCAT 0x801

  if (ni==OP_ISNULL) { return new_command (CMD_PUSH_OP_ISNULL,0); }
  if (ni==OP_AND)    { return new_command (CMD_PUSH_OP_AND,0); }
  if (ni==OP_OR)     { return new_command (CMD_PUSH_OP_OR,0); }
  if (ni==OP_EQUAL)  { return new_command (CMD_PUSH_OP_EQUAL,0); }
  if (ni==OP_CONCAT)  { return new_command (CMD_PUSH_OP_CONCAT,0); }
  return new_command (CMD_PUSH_OP, (void *) ni);
}

long add_push_char (char *s)
{
  int n;
  char *ptr;
  char *eptr;
  ptr = acl_strdup (&s[1]);
  eptr = &ptr[strlen (ptr) - 1];
  *eptr = 0;

  n = add_string (ptr);
  return new_command (CMD_PUSH_CHAR, (void *) n);
}

long add_push_charv (long e_i)
{
  return new_command (CMD_PUSH_CHARV, (void *) e_i);
}


long add_push_int (int n)
{
  return new_command (CMD_PUSH_INT, (void *) n);
}

long add_break (int a)
{
  char buff[256];
  sprintf (buff, "_while_e_%d", a);
  return add_goto (buff);
}

long add_continue (int a)
{
  char buff[256];
  sprintf (buff, "_while_c_%d", a);
  return add_goto (buff);
}





char *
cptr (char *s)
{
  if (s)
    return s;
  else
    return "NULL";
}





int
islabel (int a)
{
  int b;
  for (b = 0; b < labels_cnt; b++)
    {
      if (labels[b].pc == a)
	return b;
    }
  return -1;
}


void
resolve_gotos_func (int function_cnt)
{
  int cmd_cnt;
  int b;



  current_function = &this_module.functions.functions_val[function_cnt];
  for (cmd_cnt = 0; cmd_cnt < current_function->cmds.cmds_len; cmd_cnt++)
    {

      if (current_function->cmds.cmds_val[cmd_cnt].cmd_type == CMD_GOTO_LABEL)
	{
	  b =
	    find_label ((char *) current_function->cmds.cmds_val[cmd_cnt].
			cmd_u.c_goto_str);
	  if (b < 0)
	    {
	      printf ("Unable to locate label : %s",
		      (char *) (current_function->cmds.cmds_val[cmd_cnt].
				cmd_u.c_goto_str));
	      exit (1);
	    }
	  A4GL_debug ("find label returns %d\n", b);
	  current_function->cmds.cmds_val[cmd_cnt].cmd_type = CMD_GOTO_PC;
	  current_function->cmds.cmds_val[cmd_cnt].cmd_u.c_goto_pc =
	    b - cmd_cnt;
	}

      if (current_function->cmds.cmds_val[cmd_cnt].cmd_type == CMD_IF)
	{

	  if (current_function->cmds.cmds_val[cmd_cnt].cmd_u.c_if->goto_false)
	    {
	      b =
		find_label ((char *) current_function->cmds.
			    cmds_val[cmd_cnt].cmd_u.c_if->goto_false);
	      if (b < 0)
		{
		  printf ("Unable to locate label : %s",
			  (char *) (current_function->cmds.
				    cmds_val[cmd_cnt].cmd_u.c_if->
				    goto_false));
		  exit (1);
		}
	      A4GL_debug ("find label returns %d\n", b);
	      current_function->cmds.cmds_val[cmd_cnt].cmd_u.c_if->
		goto_false = b - cmd_cnt;

	    }

	  if (current_function->cmds.cmds_val[cmd_cnt].cmd_u.c_if->goto_true)
	    {
	      b =
		find_label ((char *) current_function->cmds.
			    cmds_val[cmd_cnt].cmd_u.c_if->goto_true);
	      if (b < 0)
		{
		  printf ("Unable to locate label : %s",
			  (char *) (current_function->cmds.
				    cmds_val[cmd_cnt].cmd_u.c_if->goto_true));
		  exit (1);
		}
	      A4GL_debug ("find label returns %d\n", b);
	      current_function->cmds.cmds_val[cmd_cnt].cmd_u.c_if->
		goto_true = b - cmd_cnt;
	    }

	}


    }
}


void
resolve_gotos ()
{
  int function_cnt;
  int cmd_cnt;
  int b;
  return;

  for (function_cnt = 0; function_cnt < this_module.functions.functions_len;
       function_cnt++)
    {
      current_function = &this_module.functions.functions_val[function_cnt];
      for (cmd_cnt = 0; cmd_cnt < current_function->cmds.cmds_len; cmd_cnt++)
	{

	  if (current_function->cmds.cmds_val[cmd_cnt].cmd_type ==
	      CMD_GOTO_LABEL)
	    {
	      b =
		find_label ((char *) current_function->cmds.cmds_val[cmd_cnt].
			    cmd_u.c_goto_str);
	      if (b < 0)
		{
		  printf ("Unable to locate label : %s",
			  (char *) (current_function->cmds.cmds_val[cmd_cnt].
				    cmd_u.c_goto_str));
		  exit (1);
		}
	      A4GL_debug ("find label returns %d\n", b);
	      current_function->cmds.cmds_val[cmd_cnt].cmd_type = CMD_GOTO_PC;
	      current_function->cmds.cmds_val[cmd_cnt].cmd_u.c_goto_pc =
		b - cmd_cnt;
	    }

	  if (current_function->cmds.cmds_val[cmd_cnt].cmd_type == CMD_IF)
	    {

	      if (current_function->cmds.cmds_val[cmd_cnt].cmd_u.c_if->
		  goto_false)
		{
		  b =
		    find_label ((char *) current_function->cmds.
				cmds_val[cmd_cnt].cmd_u.c_if->goto_false);
		  if (b < 0)
		    {
		      printf ("Unable to locate label : %s",
			      (char *) (current_function->cmds.
					cmds_val[cmd_cnt].cmd_u.c_if->
					goto_false));
		      exit (1);
		    }
		  A4GL_debug ("find label returns %d\n", b);
		  current_function->cmds.cmds_val[cmd_cnt].cmd_u.c_if->
		    goto_false = b - cmd_cnt;
		}

	      if (current_function->cmds.cmds_val[cmd_cnt].cmd_u.c_if->
		  goto_true)
		{
		  b =
		    find_label ((char *) current_function->cmds.
				cmds_val[cmd_cnt].cmd_u.c_if->goto_true);
		  if (b < 0)
		    {
		      printf ("Unable to locate label : %s",
			      (char *) (current_function->cmds.
					cmds_val[cmd_cnt].cmd_u.c_if->
					goto_true));
		      exit (1);
		    }
		  A4GL_debug ("find label returns %d\n", b);
		  current_function->cmds.cmds_val[cmd_cnt].cmd_u.c_if->
		    goto_true = b - cmd_cnt;
		}

	    }


	}
    }

}


int add_id (char *s)
{
  int a;
  A4GL_debug ("Finding %s\n", s);
  for (a = 0; a < this_module.id_table.id_table_len; a++)
    {
      if (strcmp (s, this_module.id_table.id_table_val[a].s) == 0)
	{
	  A4GL_debug ("Found it %d\n", a);
	  this_module.id_table.id_table_val[a].rcnt++;
	  return a;
	}
    }

// Its new....
  this_module.id_table.id_table_len++;
  this_module.id_table.id_table_val =
    realloc (this_module.id_table.id_table_val,
	     sizeof (struct vstring) * this_module.id_table.id_table_len);
  this_module.id_table.id_table_val[this_module.id_table.id_table_len - 1].s =
    acl_strdup (s);
  this_module.id_table.id_table_val[this_module.id_table.id_table_len -
				    1].rcnt = 1;

  A4GL_debug ("Created it @ %d\n", this_module.id_table.id_table_len - 1);
  return this_module.id_table.id_table_len - 1;
}



void add_function (char *function_name, struct define_variables *v, int is_static)
{
  int a;
  struct npfunction *curr_func;

  if (labels_cnt)
    {
      for (a = 0; a < labels_cnt; a++)
	{
	  free (labels[a].str);
	}
      labels_cnt = 0;
    }

  this_module.functions.functions_len++;
  this_module.functions.functions_val =
    realloc (this_module.functions.functions_val,
	     sizeof (struct npfunction) *
	     this_module.functions.functions_len);
  curr_func =
    &this_module.functions.functions_val[this_module.functions.functions_len -
					 1];
  curr_func->func_name_id = add_id (function_name);
  curr_func->function_class = is_static;
  curr_func->cmds.cmds_len = 0;
  curr_func->cmds.cmds_val = 0;

  if (v)
    {
      curr_func->param_vars.param_vars_len = v->var_len;
      curr_func->param_vars.param_vars_val =
	acl_malloc2 (sizeof (struct use_variable) * v->var_len);
      memset (curr_func->param_vars.param_vars_val, 0,
	      (sizeof (struct use_variable) * v->var_len));
    }
  else
    {
      curr_func->param_vars.param_vars_len = 0;
      curr_func->param_vars.param_vars_val = 0;
    }

// Add our function block...
  add_block (0);
  if (strcmp (function_name, "__MODULE") != 0)
    {
      is_in_function = 1;
    }

  if (v)
    {
// Add our parameters to the function block
      for (a = 0; a < v->var_len; a++)
	{
	  if (v->var_val[a].i_arr_size[0] == 0)
	    {
	      //printf("Adding %d as parameter variable\n",a);
	      add_variable (CAT_NORMAL, &v->var_val[a],
			    GET_ID (v->var_val[a].name_id), 0);
	    }
	  else
	    {
	      long xx[3];
	      xx[0] = v->var_val[a].i_arr_size[0];
	      xx[1] = v->var_val[a].i_arr_size[1];
	      xx[2] = v->var_val[a].i_arr_size[2];

	      add_variable_array (CAT_NORMAL,
				  &v->var_val[a],
				  GET_ID (v->var_val[a].name_id), xx, 0);
	    }
	}



      for (a = 0; a < v->var_len; a++)
	{
	  struct use_variable *uv;
	  uv =
	    mk_use_variable (0, 0, 0, 0, GET_ID (v->var_val[a].name_id), 0);
	  uv->indirection = 0;
	  memcpy (&curr_func->param_vars.param_vars_val[a], uv,
		  sizeof (struct use_variable));
	}
    }
}


int
in_function (void)
{
  return is_in_function;
}


long add_return (long r)
{
  return new_command (CMD_RETURN, (void *) r);
}
