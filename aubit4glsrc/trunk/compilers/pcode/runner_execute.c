#if (defined(__CYGWIN__)) || defined(__MINGW32__)
	/* missing from rpcgen generated .h on CygWin: */
	#define bool_t int
	#define u_int unsigned int
#endif

#include <stdio.h>


#include "npcode.h"
#include "npcode_defs.h"
//#include "a4gl_incl_4glhdr.h"
long find_pcode_function (char *s);
extern module this_module;
extern FILE *logfile;

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
extern char user[8 + 1];
extern long pageno;
extern long lineno;
//extern long today;
extern long usrtime;
extern long curr_hwnd;
extern long curr_form;
extern char err_file_name[32 + 1];
extern long err_file_no;
extern char curr_file_name[32 + 1];
extern long curr_line_no;
extern long err_status;
extern long aiplib_status;


int callstack_cnt = 0;
int callstack_alloc = 0;
struct cmd_block *callstack = 0;

static void
add_block_to_stack (int pc, struct cmd_block *b)
{
  int a;
// Do we need to allocate any STATIC or EXTERNS ?
// We need to do this to the original data
// as its only done once...

  //if (callstack_cnt>=STACK_DEPTH) { fprintf(stderr,"Out of stack space..."); exit(2); }


  //callstack_cnt = *pcallstack_cnt;
  //callstack = *pcallstack;

  callstack_cnt++;
  if (callstack_cnt > callstack_alloc)
    {
      callstack_alloc += 10;	// Add 10 onto stack length...
      if (callstack_alloc > 1000)
	{
	  fprintf (stderr, "Warning - heavy recursion or what!\n");
	}
      callstack =
	realloc (callstack, callstack_alloc * sizeof (struct cmd_block));
    }

  fprintf (logfile, "ADDING to stack %p stack length : %d\n", b,
	   callstack_cnt);

  for (a = 0; a < b->c_vars.c_vars_len; a++)
    {

      if (b->c_vars.c_vars_val[a].category == CAT_NORMAL)
	{
	  b->c_vars.c_vars_val[a].category = CAT_ALLOC;
	  continue;
	}


      if (b->c_vars.c_vars_val[a].category == CAT_STATIC
	  || b->c_vars.c_vars_val[a].category == CAT_EXTERN)
	{
	  // Need to allocate it...
	  if (b->c_vars.c_vars_val[a].category == CAT_STATIC)
	    {
	      b->c_vars.c_vars_val[a].category = CAT_ALLOC_STATIC;
	      b->c_vars.c_vars_val[a].var->offset =
		(long) malloc (b->c_vars.c_vars_val[a].var->total_size);
	    }

	  if (b->c_vars.c_vars_val[a].category == CAT_EXTERN)
	    {
	      struct variable *n;
	      void *ptr;
	      b->c_vars.c_vars_val[a].category = CAT_ALLOC_EXTERN;

	      // Need to find our variable...
	      // It will be in the module_variables table of another module
	      n = &b->c_vars.c_vars_val[a];
	      ptr = resolve_externs (GET_ID(n->var->name_id));

	      if (ptr != (void *) -1)
		{
		  n->var->offset = (long) ptr;
		  continue;
		}

	      b->c_vars.c_vars_val[a].category = CAT_EXTERN;
	      fprintf (stderr, "CAT_EXTERN - Not implemented (%s)\n",
		       GET_ID (n->var->name_id));
	      exit (1);
	    }
	}
    }

  memcpy (&callstack[callstack_cnt - 1], b, sizeof (struct cmd_block));
  // Now we've copied it - we
  // need to allocate our non-static/extern variables...
  if (callstack[callstack_cnt - 1].mem_to_alloc)
    {
      callstack[callstack_cnt - 1].mem_for_vars =
	(long) malloc (callstack[callstack_cnt - 1].mem_to_alloc);
    }
  else
    {
      callstack[callstack_cnt - 1].mem_for_vars = 0;
    }
}

static void
remove_block_from_stack ()
{
  callstack_cnt--;
  fprintf (logfile, "Removing from stack - stack length : %d\n",
	   callstack_cnt);

}



static void
copy_across_params (struct param *dest, struct param *src)
{
  memcpy (dest, src, sizeof (struct param));
}

void
execute_start_block (long pc, struct cmd_block *c)
{
  add_block_to_stack (pc, c);
}

void
execute_end_block (void)
{
  remove_block_from_stack ();
}





void
set_var (long pc, struct cmd_set_var *sv)
{
  int x;
  struct param *uset_var;
  struct use_variable *use_var;
  long *ptr;
  struct param *nparam;
  struct cmd_set_var nsv;

  uset_var = &sv->value;
  use_var = &sv->variable;

  if (uset_var->param_type == PARAM_TYPE_LIST)
    {
      int a;
      memset (&nsv, 0, sizeof (nsv));
      // Copy across the basics...
      memcpy (&nsv.variable, use_var, sizeof (struct use_variable));

      nsv.variable.sub.sub_len = use_var->sub.sub_len + 1;
      nsv.variable.sub.sub_val =
	malloc (sizeof (struct use_variable_sub) * use_var->sub.sub_len + 1);
      memcpy (nsv.variable.sub.sub_val, use_var->sub.sub_val,
	      sizeof (struct use_variable_sub) * use_var->sub.sub_len);

      if (uset_var->param_u.p_list->list.list_len == 0)
	{
	  fprintf (logfile, "NO LENGTH\n");
	}

      for (a = 0; a < uset_var->param_u.p_list->list.list_len; a++)
	{
	  struct param i;
	  i.param_type = PARAM_TYPE_LITERAL_INT;
	  i.param_u.n = a;

	  nsv.variable.sub.sub_val[nsv.variable.sub.sub_len - 1].subscript =
	    &i;
	  nsv.variable.sub.sub_val[nsv.variable.sub.sub_len - 1].element = -1;

	  nparam = &uset_var->param_u.p_list->list.list_val[a];
	  copy_across_params (&nsv.value,
			      &uset_var->param_u.p_list->list.list_val[a]);
	  set_var (pc, &nsv);
	}
      free (nsv.variable.sub.sub_val);


    }
  else
    {
      evaluate_param (uset_var, &x);
      A4GL_debug ("=");
      use_var = &sv->variable;
      ptr = get_var_ptr (use_var);
      if (ptr)
	{
	  *(int *) ptr = x;
	}
    }



}


void
set_var_once (long pc, struct cmd_set_var1 *sv)
{
  int x;
  //struct param *set_var;
  struct use_variable *use_var;
  long *ptr;

  if (sv->set)
    return;
  evaluate_param (&sv->value, &x);
  A4GL_debug ("=");
  use_var = &sv->variable;

  ptr = get_var_ptr (use_var);

  if (ptr)
    {
      *(int *) ptr = x;
    }

}

long
call_function (long pc, struct cmd_call *c)
{
  char *x;
  long npc;
  long rval;

  x = GET_ID (c->func_id);
  A4GL_debug (" --> %s\n", x);
  npc = find_pcode_function (x);
  if (npc != -1)
    {
      return run_function (npc, c->params);
    }
  A4GL_debug ("Not a 4gl function - must be C\n");
  call_c_function (x, c->params, &rval);
  return rval;
}


void *
get_var_ptr (struct use_variable *uv)
{
  int a;
  int found = -1;
  struct variable *var;
  struct variable_element *ve_main;
  struct variable_element *ve_sub;
  int call_stack_entry;
  char pointer_or_offset = 'N';
  char *rptr = 0;
//int *rptr_i=0;


  if (uv->defined_in_block_pc == -1)
    {
      call_stack_entry = 0;
    }
  else
    {
      call_stack_entry = callstack_cnt - 1;
    }

  for (a = 0; a < callstack[call_stack_entry].c_vars.c_vars_len; a++)
    {
      //printf("Examining %d %d\n",uv->variable_id,callstack[call_stack_entry].c_vars.c_vars_val[a].variable_id);
      if (uv->variable_id ==
	  callstack[call_stack_entry].c_vars.c_vars_val[a].variable_id)
	{
	  found = a;
	  break;
	}
    }

  if (found == -1)
    {
      fprintf (stderr, "Unable to find variable id %d in stack:\n",
	       uv->variable_id);
      //print_use_variable(uv);
      fprintf (stderr, "\n");
      exit (2);
    }

  var = &callstack[call_stack_entry].c_vars.c_vars_val[found];
  switch (var->category)
    {
    case CAT_NULL:
    case CAT_NORMAL:
    case CAT_EXTERN:
    case CAT_STATIC:
      fprintf (stderr, "Variable not allocated... %d\n", var->category);
      exit (2);

    case CAT_ALLOC:
      pointer_or_offset = 'O';
      break;
    case CAT_ALLOC_STATIC:
      pointer_or_offset = 'P';
      break;
    case CAT_ALLOC_EXTERN:
      pointer_or_offset = 'P';
      break;
    case CAT_SUBSTRUCT:
      pointer_or_offset = 'O';
      break;
    case CAT_PARAMETER:
      pointer_or_offset = 'O';
      break;
    case CAT_PARAMETER_SET:
      pointer_or_offset = 'O';
      break;
    }

  if (pointer_or_offset == 'P')
    {
      //printf("P--->%p\n",(char *)var->var->offset);
      rptr = (void *) var->var->offset;
    }


  if (pointer_or_offset == 'O')
    {
      char *ptr;
      ptr = (char *) callstack[call_stack_entry].mem_for_vars;
      //printf("entry=%d memforvars=%p",call_stack_entry,(char *)callstack[call_stack_entry].mem_for_vars);
      ptr = (void *) &ptr[var->var->offset];
      //printf("O--->%p\n",ptr);
      rptr = ptr;
    }

  if (!rptr)
    {
      fprintf (logfile, "****** Variable pointer not found\n");

      print_use_variable (uv);
      fflush (stdout);

      fprintf (logfile, "\n");
      return 0;
    }

  ve_main = var->var;
  //printf ("-->%s", GET_ID (ve_main->name_id));
  //printf (" offset		=%ld", ve_main->offset);
  //printf (" total_size	=%ld", ve_main->total_size);
  //printf (" unit_size	=%ld", ve_main->unit_size);
  //printf (" rptrbase	=%p", rptr);
  //printf ("\n");


  A4GL_debug ("-->%s", GET_ID (ve_main->name_id));
  A4GL_debug (" offset		=%ld", ve_main->offset);
  A4GL_debug (" total_size	=%ld", ve_main->total_size);
  A4GL_debug (" unit_size	=%ld", ve_main->unit_size);
  A4GL_debug ("\n");

// If we've got to here we've found our top level variable

  if (uv->sub.sub_len)
    {				// Darn - we've got more to do yet...
      int a;
      for (a = 0; a < uv->sub.sub_len; a++)
	{
	  ve_sub = &ve_main->next.next_val[a];
	  if (uv->sub.sub_val[a].element != -1)
	    {
	      A4GL_debug ("Sub : STRUCT (%ld)\n", uv->sub.sub_val[a].element);
	    }
	  else
	    {
	      int x;
		//printf("Looking to get subscript\n");
	      evaluate_param (uv->sub.sub_val[a].subscript, &x);
	      //printf ("Sub :ARRAY (%d) +=%d\n", x,ve_main->unit_size*x);
	      rptr += ve_main->unit_size * x;
	    }
	}
    }

//fprintf(stderr,"Indirection=%d ptr=%p\n",uv->indirection,rptr);
  if (uv->indirection == -1)
    {
	static void *ptr;
	ptr=rptr;
      return &ptr;
    }
  if (uv->indirection == 1)
    {
      return (void *) *(int *) rptr;
    }
  if (rptr == 0)
    {
      printf ("Uninitialized : ");
      print_use_variable (uv);
    }
  if (uv->indirection == 0)
    {
      return rptr;
    }
  fprintf (stderr, "Unknown indirection : %d\n", uv->indirection);
  exit (10);
}
