#if (defined(__CYGWIN__)) || defined(__MINGW32__)
	/* missing from rpcgen generated .h on CygWin: */
#define bool_t int
#define u_int unsigned int
#endif

#include <stdio.h>


#ifdef RPCGEN_HEADERS
	#include "npcode.h"
#else
	#include "npcode.xs.h"
#endif

#include "npcode_defs.h"

void A4GL_breakpoint (void);

//#define DO_DEBUG


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
  fprintf (logfile, "     Removing from stack - stack length : %d\n",
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
  int param_id1;

#ifdef DO_DEBUG
  printf ("set var %ld\n", sv->value_param_id);
#endif
  if (sv->value_param_id >= 0)
    {
      uset_var = &PARAM_ID (sv->value_param_id);
    }
  else
    {
	uset_var = nget_param (sv->value_param_id);
    }

  if (sv->value_param_id == 61)
    {
      A4GL_breakpoint ();
    }
  use_var = &sv->variable;


  if (use_var == 0)
    {
      char *ptr = 0;
#ifdef DO_DEBUG
      printf ("Nothing to set ?\n");
#endif
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


      //// Copy across the basics...
      memcpy (&nsv.variable, use_var, sizeof (struct use_variable));


      nsv.variable.sub.sub_len = use_var->sub.sub_len + 1;
      nsv.variable.sub.sub_val =
	malloc (sizeof (struct use_variable_sub) *
		(use_var->sub.sub_len + 1));


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
	  fprintf (logfile, "     Corrupt variable id...\n");
	  exit (2);
	}


      memcpy (nsv.variable.sub.sub_val, use_var->sub.sub_val,
	      sizeof (struct use_variable_sub) * use_var->sub.sub_len);



      if (uset_var->param_u.p_list->list_param_id.list_param_id_len == 0)
	{
	  fprintf (logfile, "     NO LENGTH\n");
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
	      fprintf (logfile, "     ERR : No var->var\n");
	      exit (2);
	    }
	}
      else
	{
	  printf ("No var\n");
	  fprintf (logfile, "     ERR : No var\n");
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
	      //int b;
	      i.param_type = PARAM_TYPE_LITERAL_INT;
	      i.param_u.n = a;
	      param_id1 = nset_param (&i, 99);
	      nsv.variable.sub.sub_val[nsv.variable.sub.sub_len -
				       1].x1subscript_param_id[0] = param_id1;
	      nsv.variable.sub.sub_val[nsv.variable.sub.sub_len -
				       1].x1subscript_param_id[1] = 0;
	      nsv.variable.sub.sub_val[nsv.variable.sub.sub_len -
				       1].x1subscript_param_id[2] = 0;
	      nsv.variable.sub.sub_val[nsv.variable.sub.sub_len -
				       1].x1element = -1;
	      nsv.value_param_id =
		uset_var->param_u.p_list->list_param_id.list_param_id_val[a];

#ifdef DO_DEBUG
	      {
		long bx;
		evaluate_param_i_into_integer (nsv.value_param_id, &bx);
		printf ("Single element.. %d = %ld\n", a, bx);
	      }
#endif

	      set_var (pc, &nsv);
	      nset_param (0, param_id1);

	    }
	}

      if (narr == 2)
	{			// Double element.
	  int b;
#ifdef DO_DEBUG
	  printf ("Double element\n");
#endif
	  for (a = 0;
	       a < uset_var->param_u.p_list->list_param_id.list_param_id_len;
	       a++)
	    {
	      int i;
	      //int c;
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
		  int l1;
		  int l2;
		  i.param_type = PARAM_TYPE_LITERAL_INT;
		  i.param_u.n = a;
		  j.param_type = PARAM_TYPE_LITERAL_INT;
		  j.param_u.n = b;
		  l1 = nset_param (&i, 99);
		  l2 = nset_param (&j, 99);
		  nsv.variable.sub.sub_val[nsv.variable.sub.sub_len -
					   1].x1subscript_param_id[0] = l1;
		  nsv.variable.sub.sub_val[nsv.variable.sub.sub_len -
					   1].x1subscript_param_id[1] = l2;
		  nsv.variable.sub.sub_val[nsv.variable.sub.sub_len -
					   1].x1subscript_param_id[2] = 0;
		  nsv.variable.sub.sub_val[nsv.variable.sub.sub_len -
					   1].x1element = -1;
		  nsv.value_param_id =
		    p2->param_u.p_list->list_param_id.list_param_id_val[b];
		  set_var (pc, &nsv);
		  nset_param (0, l1);
		  nset_param (0, l2);
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
      size = 0;
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
	      printf ("Strange size  reported %ld (size=%d)\n", x, size);
	      fprintf (logfile,
		       "     Strange size reported value to assign =%ld size=%d ptr=%p\n",
		       x, size, ptr);
	      printf ("     Odd : ");
	      print_use_variable (use_var);
	      printf (" = %ld\n", x);
	      exit (2);
	      *(long *) ptr = x;
	    }

	  //fprintf (logfile, "     Setting =%ld (size=%d)\n", x, size);
	  //*(int *) ptr = x; 
	}


    }

#ifdef DO_DEBUG
  printf ("Done\n");
#endif

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
      fprintf (logfile, "     Setting =%ld (size=%d)", x, size);
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
      fprintf (logfile, "     Call PCODE function param=%ld\n",
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
  fprintf (logfile, "     Call C function\n");
  fflush (logfile);

  if (c->func_params_param_id != 0)
    {
      call_c_function (x, &PARAM_ID (c->func_params_param_id), &rval);
    }
  else
    {
      call_c_function (x, 0, &rval);
    }
  fprintf (logfile, "     C function returns %ld\n", rval);
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
  *size = -1;
  //fprintf(logfile,"     1.Setting size to %d\n",*size);


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
      printf ("E1\n");
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
      printf ("E2\n");
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
      fprintf (logfile, "     ****** Variable pointer not found\n");
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


#ifdef DO_DEBUG
  {
    int a;
    for (a = 0; a < uv->sub.sub_len; a++)
      {
	printf ("SUB %d. e=%ld s1=%ld s2=%ld s3=%ld\n", a,
		uv->sub.sub_val[a].x1element,
		uv->sub.sub_val[a].x1subscript_param_id[0],
		uv->sub.sub_val[a].x1subscript_param_id[1],
		uv->sub.sub_val[a].x1subscript_param_id[2]);
      }
  }
  printf ("-->%s", GET_ID (ve_main->name_id));
  printf (" offset		=%ld", ve_main->offset);
  printf (" total_size	=%ld", ve_main->total_size);
  printf (" unit_size	=%d", ve_main->unit_size);
  printf ("\n");
  printf ("sub.sub_len=%d", uv->sub.sub_len);

#endif



  A4GL_debug ("-->%s", GET_ID (ve_main->name_id));
  A4GL_debug (" offset		=%ld", ve_main->offset);
  A4GL_debug (" total_size	=%ld", ve_main->total_size);
  A4GL_debug (" unit_size	=%ld", ve_main->unit_size);
  A4GL_debug ("\n");
  A4GL_debug ("sub.sub_len=%d\n", uv->sub.sub_len);


  *size = ve_main->unit_size;
  //fprintf(logfile,"     4.Setting size to %d\n",*size);


// If we've got to here we've found our top level variable

  //fprintf(logfile,"     sub_len= %d\n",uv->sub.sub_len);
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
		    ("Internal error - looking for variable %ld when there are only %d\n",
		     uv->sub.sub_val[a].x1element, ve_main->next.next_len);
		  exit (2);
		}
	      ve_sub = &ve_main->next.next_val[uv->sub.sub_val[a].x1element];
	      *size = ve_sub->unit_size;
	      //fprintf(logfile,"     2.Setting size to %d\n",*size);
	      fprintf (logfile, "ELEMENT :  %ld\n",
		       uv->sub.sub_val[a].x1element);
	      fprintf (logfile, " offset               =%ld\n",
		       ve_sub->offset);
	      fprintf (logfile, " name         =%s\n",
		       GET_ID (ve_sub->name_id));
	      A4GL_debug ("ELEMENT :  %ld\n", uv->sub.sub_val[a].x1element);
	      A4GL_debug (" offset               =%ld\n", ve_sub->offset);
	      A4GL_debug (" name         =%s\n", GET_ID (ve_sub->name_id));
	      rptr += ve_sub->offset;
	      A4GL_debug ("Sub : STRUCT (%ld)\n",
			  uv->sub.sub_val[a].x1element);
	    }
	  else
	    {
	      long x1 = -1;
	      long x2 = -1;
	      long x3 = -1;
	      long x = 0;
	      long max = 0;
	      //printf("subscripts : %d %d %d\n", uv->sub.sub_val[a].x1subscript_param_id[0], uv->sub.sub_val[a].x1subscript_param_id[1], uv->sub.sub_val[a].x1subscript_param_id[2]);
	      A4GL_debug ("Start : rptr=%p x1element=%d \n", rptr,
			  uv->sub.sub_val[a].x1element);
	      // We've got an element....
		if (uv->sub.sub_val[a].x1element!=-1) {
		if (uv->sub.sub_val[a].x1element>=ve_main->next.next_len) {
			printf("Got confused - too many elements %d %d\n",uv->sub.sub_val[a].x1element,ve_main->next.next_len);
			exit(4);
		}
	      ve_sub = &ve_main->next.next_val[uv->sub.sub_val[a].x1element];
	      *size = ve_sub->unit_size;
	      A4GL_debug ("5.Setting size to %d\n", *size);
		}

	      fprintf (logfile, "     5.Setting size to %d\n", *size);

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

#ifdef DO_DEBUG
	      printf ("x1=%ld x2=%ld x3=%ld\n", x1, x2, x3);
#endif

	      x = x1;

	      max = ve_main->i_arr_size[0];
	      if (ve_main->i_arr_size[1] > 1) {max*=ve_main->i_arr_size[1]; }
	      if (ve_main->i_arr_size[2] > 1) {max*=ve_main->i_arr_size[2]; }

	      if (ve_main->i_arr_size[1] > 1)
		{
		  x *= ve_main->i_arr_size[1];
		  x += x2;
		}

	      if (ve_main->i_arr_size[2] > 1)
		{
		  x *= ve_main->i_arr_size[2];
		  x += x3;
		}

	      //printf("%d of %d - %d %d %d : ",x,max,x1,x2,x3);

	      if (x < 0 || x > max)
		{
		  A4GL_debug ("RANGE CHECK FAILED CHECK\n");
		  if (max)
		    {
			char *ptr=0;
		        fprintf (logfile, "     Evaluate gives bounds check failure = %ld of %ld\n", x, max);
			printf("Bounds check failed\n");
			*ptr=0;
			
		      exit (2);
		    }
		}
	      rptr += ve_main->unit_size * x;
#ifdef DO_DEBUG
	      printf ("End : rptr=%p - %d %ld\n", rptr, ve_main->unit_size,
		      x);
#endif
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
#ifdef DO_DEBUG
	  printf ("Variable indirection.. %d indirect=%d\n", uv->sub.sub_len,
		  indirect);
#endif
	  indirect = -1;
	}
    }


#ifdef DO_DEBUG
  printf ("Indirection=%d ptr=%p \n", indirect, rptr);
  printf ("Setting size to %d\n", ve_main->unit_size);
#endif



  if (indirect == -1)
    {
      static void *ptr;
      ptr = rptr;
      A4GL_debug ("indirection -1 : %p", &ptr);
      *size = 4;
      //fprintf(logfile,"     3.Setting size to %d\n",*size);
      return &ptr;
    }

  if (indirect == 1)
    {
      A4GL_debug ("I1");
      A4GL_debug ("indirection 1 : %p", *(int *) rptr);
      return (void *) *(int *) rptr;
    }

  if (rptr == 0)
    {
      A4GL_debug ("Uninitialized..");
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


void
A4GL_breakpoint (void)
{
  printf ("Break here\n");
}
