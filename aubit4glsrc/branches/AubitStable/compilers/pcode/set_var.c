
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


extern module this_module;

static char *
do_lvl (int lvl)
{
  static char buff[256];
  memset (buff, ' ', 255);
  buff[lvl * 3] = 0;
  return buff;
}

long process_add_list (struct use_variable *var_orig, long value, int once,
		       int lvl);

long
add_set_var (struct use_variable *var_orig, long value, int once, int lvl)
{
  struct use_variable *var = 0;
  long pc;
//------------------------------------------------------------


// x1subscript_param_id is set only of x1element = -1

  struct use_variable_sub
  {
    long x1subscript_param_id[3];
    long x1element;
  };


  struct use_variable
  {
    short variable_id;
    short defined_in_block_pc;
    char indirection;
    struct
    {
      u_int sub_len;
      struct use_variable_sub *sub_val;
    } sub;
  };

  struct variable_element
  {
    short name_id;
    long dtype;
    long i_arr_size[3];
    short unit_size;
    long total_size;
    long offset;
    struct
    {
      u_int next_len;
      struct variable_element *next_val;
    } next;
  };

  struct npvariable
  {
    long variable_id;
    long def_block;
    enum var_category category;
    struct variable_element *var;
  };



//------------------------------------------------------------


// We're assigning a list of values...
  if (this_module.params.params_val[value].param_type == PARAM_TYPE_LIST)
    {
      int pc;
      pc = process_add_list (var_orig, value, once, lvl);
#ifdef DEBUG
      printf ("\n\n");
#endif
      return pc;
    }
#ifdef DEBUG
  printf ("%sSimple assignment\n", do_lvl (lvl));
  printf ("\n\n%sAdd set var\n", do_lvl (lvl));
#endif

  var = acl_malloc2 (sizeof (struct use_variable));
  memcpy (var, var_orig, sizeof (struct use_variable));

  if (once)
    {
      struct cmd_set_var1 *v1 = 0;
      v1 = acl_malloc2 (sizeof (struct cmd_set_var1));
      memcpy (&(v1->variable), var, sizeof (struct use_variable));
      v1->value_param_id = value;
      v1->set = 0;
      pc = new_command (CMD_SET_VAR_ONCE, v1);
    }
  else
    {
      struct cmd_set_var *v = 0;
      v = acl_malloc2 (sizeof (struct cmd_set_var));
      memcpy (&(v->variable), var, sizeof (struct use_variable));
      v->value_param_id = value;
      pc = new_command (CMD_SET_VAR, v);
#ifdef DEBUG
	printf("%s",do_lvl(lvl)); print_set_var(v);
#endif
    }
#ifdef DEBUG
  printf ("\n\n");
#endif
  return pc;



}




long
process_add_list (struct use_variable *var_orig, long value, int once,
		  int lvl)
{
  struct use_variable *var;
  struct variable_element *var_element = 0;
  int pc = 0;
  int vid = 0;
  int block = 0;
  struct cmd_block *base;
  int a;
  struct npvariable *variable;
  int found = -1;
  int use_array_this_level = 0;


  var = var_orig;
  // Lets find our variable declaration...
  vid = var->variable_id;
  block = var->defined_in_block_pc;
  base = (struct cmd_block *) get_base (block);
  for (a = 0; a < base->c_vars.c_vars_len; a++)
    {
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
  var_element = variable->var;

  // We've now got our base variable - go though any sub levels...

  if (var->sub.sub_len)
    {
      for (a = 0; a < var->sub.sub_len; a++)
	{
	  struct use_variable_sub *s;

	  s = (struct use_variable_sub *) &var->sub.sub_val[a];
#ifdef DEBUG
	  printf ("%s%d. %d %d %d %d\n", do_lvl (lvl), a, s->x1element,
		  s->x1subscript_param_id[0], s->x1subscript_param_id[1],
		  s->x1subscript_param_id[2]);
#endif
	  if (s->x1element == -1)
	    {			// Its an array portion
	      use_array_this_level = 1;
	    }
	  else
	    {			// Its a record item
	      use_array_this_level = 0;
	      if (s->x1element > var_element->next.next_len)
		{
		  printf ("Element in record too high\n");
		  exit (1);
		}
	      var_element = &var_element->next.next_val[s->x1element];
	    }

	}
    }

#ifdef DEBUG
  printf ("%sSET VAR %p\n", do_lvl (lvl), variable);
  printf ("%sVariable ID =%d\n", do_lvl (lvl), variable->variable_id);
  printf ("%sVariable VAR =%p\n", do_lvl (lvl), variable->var);
  printf ("%sVariable NAME =%s\n", do_lvl (lvl),
	  GET_ID (variable->var->name_id));
  printf ("%sNext cnt= %d\n", do_lvl (lvl), var_element->next.next_len);
  printf ("%sArray Sizes= %d %d %d\n", do_lvl (lvl),
	  var_element->i_arr_size[0], var_element->i_arr_size[1],
	  var_element->i_arr_size[2]);

#endif

  // Does our variable look like an array at this point ?
  if (var_element->i_arr_size[0])
    {
      int new_sub_len;
      struct use_variable_sub *new_sub_val=0;

      new_sub_len = var->sub.sub_len + 1;




      if (use_array_this_level == 0)
	{
	  int a, b;
	  int npid_a;
	  int npid_b;
	  int param_id;
	  int param_id2;

	  // I've got a list of values and an array to put them in
	  // looks ok to me....
	  // we've got something like a[]={1,2,3}
#ifdef DEBUG
	  printf ("%sAssign a[]={x,x,x}\n", do_lvl (lvl));
#endif

	  if (var_element->i_arr_size[1] == 0)
	    {			// Single dimension

	      for (a = 0; a < var_element->i_arr_size[0]; a++)
		{		// Go though each subscript of that array
		  struct use_variable *var_new;
		  new_sub_val =
		    acl_malloc2 (sizeof (struct use_variable_sub) * new_sub_len);
		  if (var->sub.sub_len)
		    {
		      memcpy (new_sub_val, var->sub.sub_val,
			      sizeof (struct use_variable_sub) * new_sub_len -
			      1);
		    }
		  new_sub_val[new_sub_len - 1].x1element = -1;
		  new_sub_val[new_sub_len - 1].x1subscript_param_id[0] = 0;
		  new_sub_val[new_sub_len - 1].x1subscript_param_id[1] = 0;
		  new_sub_val[new_sub_len - 1].x1subscript_param_id[2] = 0;


		  // Are we setting all of them - or are we 
		  if (a >=
		      this_module.params.params_val[value].param_u.p_list->
		      list_param_id.list_param_id_len)
		    {
#ifdef DEBUG
		      printf ("Not all subscripts set ([%d] omitted)\n", a);
#endif
		      continue;
		    }

		  var_new = acl_malloc2 (sizeof (struct use_variable));
		  memcpy (var_new, var_orig, sizeof (struct use_variable));

		  npid_a = new_param_returns_long ('I', (void *) a);
		  new_sub_val[new_sub_len - 1].x1subscript_param_id[0] =
		    npid_a;
		  var_new->sub.sub_len = new_sub_len;
		  var_new->sub.sub_val = new_sub_val;
		  param_id =
		    this_module.params.params_val[value].param_u.p_list->
		    list_param_id.list_param_id_val[a];
		  pc = add_set_var (var_new, param_id, once, lvl + 1);
		}

	      if (var_element->i_arr_size[0] <
		  this_module.params.params_val[value].param_u.p_list->
		  list_param_id.list_param_id_len)
		{
		  printf ("%sExcess elements ignored\n", do_lvl (lvl));
		}

	      return pc;
	    }




	  if (var_element->i_arr_size[1] != 0
	      && var_element->i_arr_size[2] == 0)
	    {			// 2 dimensional array
	      for (a = 0; a < var_element->i_arr_size[0]; a++)
		{
		  if (a >=
		      this_module.params.params_val[value].param_u.p_list->
		      list_param_id.list_param_id_len)
		    {
#ifdef DEBUG
		      printf ("Not all subscripts set ([%d][] omitted)\n", a);
#endif
		      continue;
		    }
		  param_id =
		    this_module.params.params_val[value].param_u.p_list->
		    list_param_id.list_param_id_val[a];

		  if (this_module.params.params_val[param_id].param_type !=
		      PARAM_TYPE_LIST)
		    {
		      printf ("Expecting a list(1) (%d %d)\n", param_id2,
			      this_module.params.params_val[param_id].
			      param_type);
		      exit (1);
		    }

		  for (b = 0; b < var_element->i_arr_size[1]; b++)
		    {
		      struct use_variable *var_new;
		      new_sub_val =
			acl_malloc2 (sizeof (struct use_variable_sub) *
				new_sub_len);
		      if (var->sub.sub_len)
			{
			  memcpy (new_sub_val, var->sub.sub_val,
				  sizeof (struct use_variable_sub) *
				  new_sub_len - 1);
			}
		      new_sub_val[new_sub_len - 1].x1element = -1;
		      new_sub_val[new_sub_len - 1].x1subscript_param_id[0] =
			0;
		      new_sub_val[new_sub_len - 1].x1subscript_param_id[1] =
			0;
		      new_sub_val[new_sub_len - 1].x1subscript_param_id[2] =
			0;

		      if (b >=
			  this_module.params.params_val[param_id].param_u.
			  p_list->list_param_id.list_param_id_len)
			{
#ifdef DEBUG
			  printf
			    ("Not all subscripts set ([%d][%d] omitted)\n", a,
			     b);
#endif
			  continue;
			}
		      var_new = acl_malloc2 (sizeof (struct use_variable));
		      memcpy (var_new, var_orig,
			      sizeof (struct use_variable));
		      npid_a = new_param_returns_long ('I', (void *) a);
		      npid_b = new_param_returns_long ('I', (void *) b);

		      new_sub_val[new_sub_len - 1].x1subscript_param_id[0] = npid_a;
		      new_sub_val[new_sub_len - 1].x1subscript_param_id[1] = npid_b;
		      var_new->sub.sub_len = new_sub_len;
		      var_new->sub.sub_val = new_sub_val;
		      param_id2 = this_module.params.params_val[param_id].param_u.  p_list->list_param_id.list_param_id_val[b];

#ifdef DEBUG
		      printf("%sAdding %d,%d\n",do_lvl(lvl),a,b);
#endif

		      pc = add_set_var (var_new, param_id2, once, lvl + 1);
		    }
		}
	      return pc;
	    }



	  if (var_element->i_arr_size[1] != 0
	      && var_element->i_arr_size[2] != 0)
	    {			// 3 dimensional array
	      printf ("3 dimensional arrays not implemented\n");
	    }




	}





      if (use_array_this_level == 1)
	{
	  int new_sub_len;
	  struct use_variable_sub *new_sub_val;

	  new_sub_len = var->sub.sub_len + 1;

	  // I've got a list of values and a spot to put them into - it had better be a record..
	  if (var_element->next.next_len == 0)
	    {
	      // That looks  bad...
	      printf ("Initializer error\n");
	      exit (2);
	    }

	  // OK - we've got  struct {int b;int c} a[]  ={ {x,x}}
#ifdef DEBUG
	  printf ("%sAssign struct {..}a[]={x,x,x}\n", do_lvl (lvl));
#endif
	  for (a = 0; a < var_element->next.next_len; a++)
	    {
	      struct use_variable *var_new;
	      int param_id;
	      new_sub_val =
		acl_malloc2 (sizeof (struct use_variable_sub) * new_sub_len);
	      if (var->sub.sub_len)
		{
		  memcpy (new_sub_val, var->sub.sub_val,
			  sizeof (struct use_variable_sub) * new_sub_len - 1);
		}
	      new_sub_val[new_sub_len - 1].x1element = -1;
	      new_sub_val[new_sub_len - 1].x1subscript_param_id[0] = 0;
	      new_sub_val[new_sub_len - 1].x1subscript_param_id[1] = 0;
	      new_sub_val[new_sub_len - 1].x1subscript_param_id[2] = 0;

	      // Are we setting all of them - or are we 
	      if (a >=
		  this_module.params.params_val[value].param_u.p_list->
		  list_param_id.list_param_id_len)
		{
#ifdef DEBUG
		  printf ("Not all elements set (element %d omitted)\n", a);
#endif
		  continue;
		}
	      var_new = acl_malloc2 (sizeof (struct use_variable));
	      memcpy (var_new, var_orig, sizeof (struct use_variable));
	      new_sub_val[new_sub_len - 1].x1element = a;
	      var_new->sub.sub_len = new_sub_len;
	      var_new->sub.sub_val = new_sub_val;
	      param_id =
		this_module.params.params_val[value].param_u.p_list->
		list_param_id.list_param_id_val[a];
	      pc = add_set_var (var_new, param_id, once, lvl + 1);
	    }




	}
    }

  // Does our variable look like an array at this point ?
  if (var_element->i_arr_size[0] == 0)
    {
      if (use_array_this_level)
	{
	  printf
	    ("Initialiser error - looking to subscript a non array variable\n");
	  exit (2);
	}
      else
	{
	  // If we don't have a record - we're stuffed...
	  if (var_element->next.next_len == 0)
	    {
	      // That looks  bad...
	      printf ("Initializer error\n");
	      exit (2);
	    }
	  printf ("%sAssign struct {..} ={x,x,x}\n", do_lvl (lvl));
	}
    }


  return 0;
}
