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
  fflush (logfile);

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
	      //printf("MALLOC : %d\n",b->c_vars.c_vars_val[a].var->total_size);
	      b->c_vars.c_vars_val[a].var->offset =
		(long) malloc (b->c_vars.c_vars_val[a].var->total_size);
	    }

	  if (b->c_vars.c_vars_val[a].category == CAT_EXTERN)
	    {
	      struct npvariable *n;
	      void *ptr;
	      b->c_vars.c_vars_val[a].category = CAT_ALLOC_EXTERN;

	      // Need to find our variable...
	      // It will be in the module_variables table of another module
	      n = &b->c_vars.c_vars_val[a];
	      ptr = resolve_externs (GET_ID (n->var->name_id));

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
      //printf("MALLOC : %d\n",callstack[callstack_cnt - 1].mem_to_alloc);
      //printf("mem=%p to %p  (%d)\n",
//callstack[callstack_cnt - 1].mem_for_vars, 
//callstack[callstack_cnt - 1].mem_for_vars+ callstack[callstack_cnt - 1].mem_to_alloc,
//callstack[callstack_cnt - 1].mem_to_alloc
//);
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
  fflush (logfile);

}



//static void copy_across_params (struct param *dest, struct param *src) { memcpy (dest, src, sizeof (struct param)); }

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
  long x;
  int found;
  int size;
  struct param *uset_var;
  struct use_variable *use_var;
  long *ptr;
  int call_stack_entry;
  //struct param *nparam;
  int lvl;
  int narr;

  if (sv->value_param_id >= 0)
    {
      uset_var = &PARAM_ID (sv->value_param_id);
    }
  else
    {
      if (sv->value_param_id == -1)
	uset_var = nget_param (0);
      if (sv->value_param_id == -2)
	uset_var = nget_param (1);
    }

  use_var = &sv->variable;


  if (use_var == 0)
    {
      char *ptr = 0;
      printf ("Nothing to set ?\n");
      *ptr = 0;
      exit (2);
    }


  if (sv == 0)
    {
      char *ptr = 0;
      printf ("Nothing to set ?\n");
      *ptr = 0;
      exit (2);

    }
  if (use_var->variable_id < 0)
    {
      printf ("Interal error - some corruption");
      exit (2);
    }





  if (uset_var->param_type == PARAM_TYPE_LIST)
    {
      int a;
      struct npvariable *npvar;
      struct cmd_set_var nsv;



      memset (&nsv, 0, sizeof (nsv));


      // Copy across the basics...
      memcpy (&nsv.variable, use_var, sizeof (struct use_variable));


      printf ("Copy across to new nsv : %p - %d\n", use_var, use_var->sub.sub_len + 1);
      nsv.variable.sub.sub_len = use_var->sub.sub_len + 1;
      nsv.variable.sub.sub_val = malloc (sizeof (struct use_variable_sub) * (use_var->sub.sub_len + 1));
	
	printf("Malloced : %d\n",sizeof (struct use_variable_sub) * (use_var->sub.sub_len + 1));

      if (use_var->defined_in_block_pc == -1)
	{
	  call_stack_entry = 0;
	}
      else
	{
	  call_stack_entry = callstack_cnt - 1;
	}



      found = -1;
      for (a = 0; a < callstack[call_stack_entry].c_vars.c_vars_len; a++)
	{
	  if (use_var->variable_id ==
	      callstack[call_stack_entry].c_vars.c_vars_val[a].variable_id)
	    {
	      found = a;
	      break;
	    }
	}


      if (found >= 0)
	{
	  npvar = &callstack[call_stack_entry].c_vars.c_vars_val[found];

	  //printf ("\n\n\nVAR:\n");
	  //print_variable (0, npvar);
	  //printf ("\n\n\n");
	  //printf ("Levels : %d ****************************************\n", use_var->sub.sub_len);

	}
      else
	{
	  printf ("Variable not found\n");
	  exit (2);
	}



      if (found >= callstack[call_stack_entry].c_vars.c_vars_len)
	{
	  printf ("Corrupt variable id %d >=%d \n", found,
		  callstack[call_stack_entry].c_vars.c_vars_len);
	  printf ("ID=%ld\n", sv->value_param_id);
	  fprintf (logfile, "Corrupt variable id...\n");
	  exit (2);
	}


      memcpy (nsv.variable.sub.sub_val, use_var->sub.sub_val, sizeof (struct use_variable_sub) * use_var->sub.sub_len);



      if (uset_var->param_u.p_list->list_param_id.list_param_id_len == 0)
	{
	  fprintf (logfile, "NO LENGTH\n");
	  fflush (logfile);
	}


      lvl = use_var->sub.sub_len + 1;

      narr = 0;
      if (npvar)
	{
	  if (npvar->var)
	    {
	      if (npvar->var->i_arr_size[0])
		narr = 1;
	      if (npvar->var->i_arr_size[1])
		narr = 2;
	      if (npvar->var->i_arr_size[2])
		narr = 3;
	    }
	  else
	    {
	      printf ("No var->var\n");
	      fprintf (logfile, "ERR : No var->var\n");
	      exit (2);
	    }
	}
      else
	{
	  printf ("No var\n");
	  fprintf (logfile, "ERR : No var\n");
	  exit (2);
	}




      if (narr == 0)
	{
	  // We got a list - but the variable isn't an array..
	  // This seems strange....
	  // 
	  printf ("Unexpected - no array but got a list...");
	  exit (2);
	}




      if (narr == 1)
	{			// Single element.
	  for (a = 0;
	       a < uset_var->param_u.p_list->list_param_id.list_param_id_len;
	       a++)
	    {
	      struct param i;
	      i.param_type = PARAM_TYPE_LITERAL_INT;
	      i.param_u.n = a;
	      nset_param (&i, 0);
	      nsv.variable.sub.sub_val[nsv.variable.sub.sub_len -
				       1].x1subscript_param_id[0] = -1;
	      nsv.variable.sub.sub_val[nsv.variable.sub.sub_len -
				       1].x1subscript_param_id[1] = 0;
	      nsv.variable.sub.sub_val[nsv.variable.sub.sub_len -
				       1].x1subscript_param_id[2] = 0;
	      nsv.variable.sub.sub_val[nsv.variable.sub.sub_len -
				       1].x1element = -1;
	      nsv.value_param_id =
		uset_var->param_u.p_list->list_param_id.list_param_id_val[a];
	      set_var (pc, &nsv);
	      //free (nsv.variable.sub.sub_val);
		printf("Freed\n");

	    }
	}

      if (narr == 2)
	{			// Double element.
	  int b;
	  for (a = 0;
	       a < uset_var->param_u.p_list->list_param_id.list_param_id_len;
	       a++)
	    {
	      int i;
	      struct param *p2;
	      i =
		uset_var->param_u.p_list->list_param_id.list_param_id_val[a];

	      //printf("Got Param ID %d\n",i);

	      p2 = &PARAM_ID (i);
	      if (p2->param_type != PARAM_TYPE_LIST)
		{
		  printf ("Expecting a list\n");
		  exit (2);
		}
	      for (b = 0;
		   b <
		   uset_var->param_u.p_list->list_param_id.list_param_id_len;
		   b++)
		{
		  struct param i;
		  struct param j;
		  i.param_type = PARAM_TYPE_LITERAL_INT;
		  i.param_u.n = a;
		  j.param_type = PARAM_TYPE_LITERAL_INT;
		  j.param_u.n = b;
		  nset_param (&i, 0);
		  nset_param (&j, 1);
		  //printf("i=%d j=%d\n",a,b);
		  nsv.variable.sub.sub_val[nsv.variable.sub.sub_len -
					   1].x1subscript_param_id[0] = -1;
		  nsv.variable.sub.sub_val[nsv.variable.sub.sub_len -
					   1].x1subscript_param_id[1] = -2;
		  nsv.variable.sub.sub_val[nsv.variable.sub.sub_len -
					   1].x1subscript_param_id[2] = 0;
		  nsv.variable.sub.sub_val[nsv.variable.sub.sub_len -
					   1].x1element = -1;
		  nsv.value_param_id =
		    p2->param_u.p_list->list_param_id.list_param_id_val[b];
		  set_var (pc, &nsv);
		  //free (nsv.variable.sub.sub_val);
		printf("Freed\n");
		}
	    }
	}

      if (narr == 3)
	{
	  printf ("3 dim array not implemented yet\n");
	  exit (4);
	}

    }
  else
    {
      evaluate_param_into_integer (uset_var, &x);
      use_var = &sv->variable;
      ptr = get_var_ptr (use_var, &size);

      if (ptr)
	{
	  int done = 0;
	  if (size == 1)
	    {
	      *(char *) ptr = x;
	      done = 1;
	    }
	  if (size == 2)
	    {
	      *(short *) ptr = x;
	      done = 1;
	    }
	  if (size == 4)
	    {
	      *(long *) ptr = x;
	      done = 1;
	    }
	  if (size == 8)
	    {
	      *(double *) ptr = x;
	      done = 1;
	    }
	  if (done == 0)
	    {
	      // Strange - it should be one of those....
	      fprintf (logfile, "Strange size  reported %ld (size=%d)\n", x, size);
	      *(long *) ptr = x;
	    }

	  fprintf (logfile, "Setting =%ld (size=%d)\n", x, size);
	  //*(int *) ptr = x; 
	}


    }



}


void
set_var_once (long pc, struct cmd_set_var1 *sv)
{
  long x;
  //struct param *set_var;
  struct use_variable *use_var;
  long *ptr;
  int size;

  if (sv->set)
    return;

  evaluate_param_i_into_integer (sv->value_param_id, &x);

  //A4GL_debug ("=");
  use_var = &sv->variable;

  ptr = get_var_ptr (use_var, &size);

  if (ptr)
    {
      fprintf (logfile, "Setting =%ld (size=%d)", x, size);
      if (size == 1)
	*(char *) ptr = x;
      if (size == 2)
	*(short *) ptr = x;
      if (size == 4)
	*(long *) ptr = x;
      if (size == 8)
	*(double *) ptr = x;
    }
}



long
call_function (long pc, struct npcmd_call *c)
{
  char *x;
  long npc;
  long rval;

  x = GET_ID (c->func_id);
  npc = find_pcode_function (x);
  if (npc != -1)
    {
      fprintf (logfile, "Call PCODE function param=%ld\n",
	       c->func_params_param_id);
      fflush (logfile);
      if (c->func_params_param_id != 0)
	{
	  return run_function (npc, &PARAM_ID (c->func_params_param_id));
	}
      else
	{
	  return run_function (npc, 0);
	}
    }
  fprintf (logfile, "Call C function\n");
  fflush (logfile);

  if (c->func_params_param_id != 0)
    {
      call_c_function (x, &PARAM_ID (c->func_params_param_id), &rval);
    }
  else
    {
      call_c_function (x, 0, &rval);
    }
  fprintf (logfile, "C function returns %ld\n", rval);
  return rval;
}


void *
get_var_ptr (struct use_variable *uv, int *size)
{
  int a;
  int found = -1;
  struct npvariable *var;
  struct variable_element *ve_main;
  struct variable_element *ve_sub;
  int call_stack_entry;
  int indirect;
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
	printf("E1\n");
      exit (2);
    }

  //printf("Found @ %d\n",a);
  var = &callstack[call_stack_entry].c_vars.c_vars_val[found];
  switch (var->category)
    {
    case CAT_NULL:
    case CAT_NORMAL:
    case CAT_EXTERN:
    case CAT_STATIC:
      fprintf (stderr, "Variable not allocated... %d\n", var->category);
	printf("E2\n");
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


  //printf("Cat = %c\n",pointer_or_offset);
  if (pointer_or_offset == 'P')
    {
      //printf("P--->%p\n",(char *)var->var->offset);
      rptr = (void *) var->var->offset;
    }


  if (pointer_or_offset == 'O')
    {
      char *ptr;
      ptr = (char *) callstack[call_stack_entry].mem_for_vars;
      //printf("entry=%d memforvars=%p\n",call_stack_entry,(char *)callstack[call_stack_entry].mem_for_vars);
      //printf("offset=%d\n",var->var->offset);
      ptr = (void *) &ptr[var->var->offset];
      //printf("O--->%p\n",ptr);
      rptr = ptr;
    }



  if (!rptr)
    {
      fprintf (logfile, "****** Variable pointer not found\n");
      fflush (logfile);

      print_use_variable (uv);
      fflush (stdout);

      fprintf (logfile, "\n");
      fflush (logfile);
      return 0;
    }

  ve_main = var->var;

  //printf ("-->%s", GET_ID (ve_main->name_id));
  //printf (" offset            =%ld", ve_main->offset);
  //printf (" total_size        =%ld", ve_main->total_size);
  //printf (" unit_size =%ld", ve_main->unit_size);
  //printf (" rptrbase  =%p", rptr);
  //printf ("sub.sub_len=%d\n", uv->sub.sub_len);

/*
  {
    int a;
    for (a = 0; a < uv->sub.sub_len; a++)
      {
	printf ("SUB %d. e=%d s1=%d s2=%d s3=%d\n", a,
		uv->sub.sub_val[a].x1element,
		uv->sub.sub_val[a].x1subscript_param_id[0],
		uv->sub.sub_val[a].x1subscript_param_id[1],
		uv->sub.sub_val[a].x1subscript_param_id[2]);
      }
  }
*/


  A4GL_debug ("-->%s", GET_ID (ve_main->name_id));
  A4GL_debug (" offset		=%ld", ve_main->offset);
  A4GL_debug (" total_size	=%ld", ve_main->total_size);
  A4GL_debug (" unit_size	=%ld", ve_main->unit_size);
  A4GL_debug ("\n");
  A4GL_debug ("sub.sub_len=%d", uv->sub.sub_len);

// If we've got to here we've found our top level variable


  if (uv->sub.sub_len)
    {				// Darn - we've got more to do yet...
      int a;
      for (a = 0; a < uv->sub.sub_len; a++)
	{

	  ve_sub = 0;		// &ve_main->next.next_val[a];
	  if (uv->sub.sub_val[a].x1element != -1)
	    {
	      if (uv->sub.sub_val[a].x1element >= ve_main->next.next_len)
		{
		  printf
		    ("Internal error - looking for variable %d when there are only %d\n",
		     uv->sub.sub_val[a].x1element, ve_main->next.next_len);
		  exit (2);
		}
	      ve_sub = &ve_main->next.next_val[uv->sub.sub_val[a].x1element];
	      //printf("ELEMENT :  %d\n",uv->sub.sub_val[a].x1element);
	      //printf(" offset               =%ld\n", ve_sub->offset);
	      //printf(" name         =%s\n", GET_ID(ve_sub->name_id));
	      rptr += ve_sub->offset;
	      A4GL_debug ("Sub : STRUCT (%ld)\n",
			  uv->sub.sub_val[a].x1element);
	    }
	  else
	    {
	      long x1 = 0;
	      long x2 = 0;
	      long x3 = 0;
	      long x = 0;
	      long max = 0;
	      //printf("subscripts : %d %d %d\n", uv->sub.sub_val[a].x1subscript_param_id[0], uv->sub.sub_val[a].x1subscript_param_id[1], uv->sub.sub_val[a].x1subscript_param_id[2]);
	      if (uv->sub.sub_val[a].x1subscript_param_id[0] != 0)
		{
		  evaluate_param_i_into_integer (uv->sub.sub_val[a].
						 x1subscript_param_id[0],
						 &x1);
		}
	      if (uv->sub.sub_val[a].x1subscript_param_id[1] != 0)
		{
		  evaluate_param_i_into_integer (uv->sub.sub_val[a].
						 x1subscript_param_id[1],
						 &x2);
		}
	      if (uv->sub.sub_val[a].x1subscript_param_id[2] != 0)
		{
		  evaluate_param_i_into_integer (uv->sub.sub_val[a].
						 x1subscript_param_id[2],
						 &x3);
		}



	      x = x1;
	      max = ve_main->i_arr_size[0];
	      if (ve_main->i_arr_size[1] > 1)
		{
		  x *= ve_main->i_arr_size[0];
		  x += x2;
		  max *= ve_main->i_arr_size[1];
		}
	      if (ve_main->i_arr_size[2] > 1)
		{
		  x *= ve_main->i_arr_size[1];
		  x += x3;
		  max *= ve_main->i_arr_size[2];
		}

	      //printf("%d of %d - %d %d %d : ",x,max,x1,x2,x3);

	      if (x < 0 || x > max)
		{
		  A4GL_debug ("RANGE CHECK FAILED CHECK\n");
		  if (max)
		    {
		      fprintf (logfile, "Evaluate gives bounds check failure = %ld of %d\n", x, max);
		      //exit (2);
		    }
		}
	      rptr += ve_main->unit_size * x;
	    }
	}
    }

  indirect = uv->indirection;
// Are we looking at an array ?
//printf("A\n");


  if (ve_main->i_arr_size[0])
    {
      // Are we looking at the variable for the array - with no subscripts
      // eg char buff[245];
      //   printf("%s",buff)
      // This should return &buff which should be the same as &buff[0]
      //


      if (uv->sub.sub_len == 0)
	{
	  printf ("Variable indirection.. %d indirect=%d\n", uv->sub.sub_len,
		  indirect);
	  indirect = -1;
	}
    }
  //printf ("Indirection=%d ptr=%p \n", indirect, rptr);

  *size = ve_main->unit_size;
  if (indirect == -1)
    {
      static void *ptr;
      ptr = rptr;
      A4GL_debug ("indirection -1 : %p", &ptr);
      *size = 4;
      return &ptr;
    }

  if (indirect == 1)
    {
      A4GL_debug ("indirection 1 : %p", *(int *) rptr);

      return (void *) *(int *) rptr;
    }

  if (rptr == 0)
    {
      printf ("Uninitialized : ");
      print_use_variable (uv);
    }

  if (indirect == 0)
    {
      A4GL_debug ("indirection 0 : %p", rptr);
      return rptr;
    }

  fprintf (stderr, "Unknown indirection : %d\n", indirect);

  exit (10);
}
