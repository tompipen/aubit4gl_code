#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if (defined(__CYGWIN__)) || defined(__MINGW32__)
	/* missing from rpcgen generated .h on CygWin: */
	#define bool_t int
	#define u_int unsigned int
#endif

#include "npcode.h"
#include "npcode_defs.h"

char **call_list;
int ncalls = 0;
int is_in_function = 0;

long find_function (char *s);
extern module this_module;
void print_set_var (struct cmd_set_var *v);

#define LABELSCNT 100000
struct label labels[LABELSCNT];
int labels_cnt = 0;
static void resolve_gotos_func (int function_cnt);

long pc = 0;

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
  "CMD_ERRCHK",
  ""
};


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
  this_module.external_function_table.external_function_table_val =
    malloc (sizeof (char *) * n);
  this_module.external_function_table.external_function_table_len = n;
  n = 0;


  for (a = 0; a < ncalls; a++)
    {
      if (find_function (call_list[a]) != -1)
	continue;
      this_module.external_function_table.external_function_table_val[n] =
	add_id (call_list[a]);
      A4GL_debug ("CALLS : %s\n", call_list[a]);
      n++;
    }
}


void
add_called (char *s)
{
  int a;
  for (a = 0; a < ncalls; a++)
    {
      if (strcmp (call_list[a], s) == 0)
	return;
    }
  ncalls++;

  call_list = realloc (call_list, sizeof (char *) * ncalls);
  call_list[ncalls - 1] = strdup (s);
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

  if (this_module.functions.functions_len == 0)
    {
      printf ("No current function to add a command to....\n");
      exit (1);
    }


  current_function =
    &this_module.functions.functions_val[this_module.functions.functions_len - 1];

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
      A4GL_debug ("\n\nADDING CMD_SET_VAR : %p\n\n", ptr);
      A4GL_debug ("variable=%p value=%p\n",
		  &CURRENT_CMD.cmd_u.c_setvar->variable,
		  &CURRENT_CMD.cmd_u.c_setvar->value);
      break;

    case CMD_SET_VAR_ONCE:
      CURRENT_CMD.cmd_u.c_setvar1 = ptr;
      A4GL_debug ("\n\nADDING CMD_SET_VAR : %p\n\n", ptr);
      A4GL_debug ("variable=%p value=%p\n",
		  &CURRENT_CMD.cmd_u.c_setvar->variable,
		  &CURRENT_CMD.cmd_u.c_setvar->value);
      break;


    case CMD_GOTO_LABEL:
      CURRENT_CMD.cmd_u.c_goto_str = (long) ptr;
      break;

    case CMD_GOTO_PC:
      CURRENT_CMD.cmd_u.c_goto_pc = (long) ptr;
      break;

    case CMD_RETURN:
      CURRENT_CMD.cmd_u.c_return = (struct param *) ptr;
      break;

    case CMD_PUSH_LONG:
      CURRENT_CMD.cmd_u.c_push_long = (int) ptr;
      break;

    case CMD_PUSH_CHAR:
      CURRENT_CMD.cmd_u.c_push_char = (int) ptr;
      break;

    case CMD_PUSH_INT:
      CURRENT_CMD.cmd_u.c_push_int = (int)ptr;
      break;

    case CMD_CHK_ERR:
      CURRENT_CMD.cmd_u.c_chk_err_lineno = (long) ptr;
      break;

    case CMD_ERRCHK:
      CURRENT_CMD.cmd_u.c_errchk = (struct cmd_errchk *) ptr;
      break;

    case CMD_CLR_ERR:
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


long
add_call (char *funcname, struct param *params)
{
  struct npcmd_call *c;
  c = malloc (sizeof (struct npcmd_call));
  c->func_id = add_id (funcname);
  c->params = params;
  add_called (funcname);
  return new_command (CMD_CALL, c);
}


long
add_block (void *ptr_c_vars)
{
  struct cmd_block *blk;
  long pc;
  blk = malloc (sizeof (struct cmd_block));
  blk->c_vars.c_vars_len = 0;
  blk->c_vars.c_vars_val = 0;
  blk->mem_for_vars = 0;
  blk->mem_to_alloc = 0;

  pc = new_command (CMD_BLOCK, blk);

  //printf("Adding block ... %ld\n",pc);
  add_block_var (blk, pc);

  return pc;
}


long
add_set_var (struct use_variable *var, struct param *value, int once)
{
  struct cmd_set_var *v;
  struct cmd_set_var1 *v1;
  int pc;

  v = malloc (sizeof (struct cmd_set_var));
  v1 = malloc (sizeof (struct cmd_set_var1));

  A4GL_debug ("sizes : %d %d\n", sizeof (v->variable),
	      sizeof (struct use_variable));

  memcpy (&(v->variable), var, sizeof (struct use_variable));
  memcpy (&(v1->variable), var, sizeof (struct use_variable));


//A4GL_debug("Before copy : ");
  //print_params(value);
  if (value)
    {
      memcpy (&(v->value), value, sizeof (struct param));
      memcpy (&(v1->value), value, sizeof (struct param));
    }
  else
    {
      v->value.param_type = PARAM_TYPE_EMPTY;
      v1->value.param_type = PARAM_TYPE_EMPTY;
    }

//A4GL_debug("After copy : ");
  //print_params(&v->value);

  if ((long) value < 100 && value)
    {
      char *ptr = 0;
      printf ("CORRUPT VALUE\n");
      *ptr = 0;

    }
  if (once)
    {
      v1->set = 0;
      pc = new_command (CMD_SET_VAR_ONCE, v1);
    }
  else
    {
      pc = new_command (CMD_SET_VAR, v);
    }
  //print_set_var(v);
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



/*
void
add_label (char *label)
{
  current_function =
    &this_module.functions.functions_val[this_module.functions.functions_len -
					 1];
  A4GL_debug ("Add label %s %d\n", label, current_function->cmds.cmds_len);


  if (find_label (label) >= 0)
    {
      printf ("Label already exists (%s)\n", label);
      exit (1);
    }
  labels[labels_cnt].str = strdup (label);
  labels[labels_cnt].pc = current_function->cmds.cmds_len;
  labels_cnt++;
  if (labels_cnt >= LABELSCNT)
    {
      printf ("Too many labels");
      exit (11);
    }

  //return new_command(CMD_LABEL,strdup(label));
}
*/



/*
int
find_label (char *label)
{
  int a;


  if (tfind(label,&label_tree,strcmp)) {


  for (a = 0; a < labels_cnt; a++)
    {
      if (strcmp (labels[a].str, label) == 0)
	{
	  return labels[a].pc;
	}
    }
  return -1;
}
*/



long
add_goto (char *label)
{
  int a;
  a = find_label (label);

  if (a >= 0)
    {
      return new_command (CMD_GOTO_PC, (void *) a - current_pc () - 1);
    }
  else
    {
      return new_command (CMD_GOTO_LABEL, strdup (label));
    }
}



long
end_function ()
{
  int a;
  do_end_block ();
  new_command (CMD_RETURN, 0);
  is_in_function = 0;
  a = this_module.functions.functions_len - 1;
  resolve_gotos_func (a);

  //printf("Done..\n");
  return 0;
}


long
end_main ()
{
  //do_end_block ();
  //new_command (CMD_RETURN, 0);
  is_in_function = 0;
  //printf("Done..\n");
  return 0;
}


long
end_block ()
{
  int begin_pc;
  struct cmd_end_block *b;
  b = malloc (sizeof (struct cmd_end_block));
  begin_pc = do_end_block ();
  b->pc_start_block = begin_pc;

  return new_command (CMD_END_BLOCK, b);
}

long
add_if (struct param *e, char *true, char *false)
{
  struct npcmd_if *f;
  f = malloc (sizeof (struct npcmd_if));
  f->condition = e;
  f->goto_true = (long) true;
  f->goto_false = (long) false;
  return new_command (CMD_IF, f);

}

long add_chk_err(int n) {
  return new_command (CMD_CHK_ERR, (void *)n);
}
long add_errchk(void *n) {
  return new_command (CMD_ERRCHK, (void *)n);
}

long add_clr_err(void) {
  return new_command (CMD_CLR_ERR, 0);
}

long add_push_long(int n) {
  return new_command (CMD_PUSH_LONG, (void *)n);
}

long add_push_char(char *s) {
	int n;
        char *ptr;
	char *eptr;
	ptr=strdup(&s[1]);
	eptr=&ptr[strlen(ptr)-1];
	*eptr=0;
	
	n=add_string(ptr);
  	return new_command (CMD_PUSH_CHAR, (void *)n);
}

long add_push_int(int n) {
  return new_command (CMD_PUSH_INT, (void *)n);
}

long
add_break (int a)
{
  char buff[256];
  sprintf (buff, "_while_e_%d", a);
  return add_goto (buff);
}

long
add_continue (int a)
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


int
add_id (char *s)
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
    strdup (s);
  this_module.id_table.id_table_val[this_module.id_table.id_table_len -
				    1].rcnt = 1;

  A4GL_debug ("Created it @ %d\n", this_module.id_table.id_table_len - 1);
  return this_module.id_table.id_table_len - 1;
}



void
add_function (char *function_name, struct define_variables *v, int is_static)
{
//
  int a;
  struct npfunction *curr_func;
  //printf ("Processing :%-80.80s\n", function_name); fflush(stdout);

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
	     sizeof (struct npfunction) * this_module.functions.functions_len);
  curr_func =
    &this_module.functions.functions_val[this_module.functions.functions_len -
					 1];
  curr_func->func_name_id = add_id (function_name);
  curr_func->function_class = is_static;
  curr_func->cmds.cmds_len = 0;
  curr_func->cmds.cmds_val = 0;

  //curr_func->stack.stack_len=0;
  //curr_func->stack.stack_val=0;
  if (v)
    {
      curr_func->param_vars.param_vars_len = v->var_len;
      curr_func->param_vars.param_vars_val =
	malloc (sizeof (struct use_variable) * v->var_len);
      //printf("Adding %d variables as parameters..\n",v->var_len);
      memset (curr_func->param_vars.param_vars_val, 0,
	      (sizeof (struct use_variable) * v->var_len));
    }
  else
    {
      curr_func->param_vars.param_vars_len = 0;
      curr_func->param_vars.param_vars_val = 0;
      //printf("No variables as parameters\n");
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
	      //printf("Adding %d as parameter variable array \n",a);
	      add_variable_array (CAT_NORMAL, &v->var_val[a],
				  GET_ID (v->var_val[a].name_id),
				  &v->var_val[a].i_arr_size[0], 0);
	    }
	}



      for (a = 0; a < v->var_len; a++)
	{
	  struct use_variable *uv;
	  uv = mk_use_variable (0, 0, GET_ID (v->var_val[a].name_id), 0);
	  uv->indirection = 0;
	  //p = malloc (sizeof (struct param));
	  //p->param_type = PARAM_TYPE_USE_VAR;
	  //p->param_u.uv = uv;
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


long
add_return (struct param *r)
{
  return new_command (CMD_RETURN, r);
}
