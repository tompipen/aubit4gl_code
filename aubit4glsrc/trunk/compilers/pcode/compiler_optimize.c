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

extern module this_module;
int really = 0;


//#define DO_OPTIMIZE



int
compare_uv (struct param *pa, struct param *pb)
{
 struct use_variable *a;
 struct use_variable *b;
  int c;
  a=pa->param_u.uv;
  b=pb->param_u.uv;

  if (a->variable_id!=b->variable_id) return 0;
  if (a->defined_in_block_pc!=b->defined_in_block_pc) return 0;
  if (a->indirection!=b->indirection) return 0;

  if (a->sub.sub_len!=b->sub.sub_len) return 0;
  for(c=0;c<a->sub.sub_len;c++) {
    if (a->sub.sub_val[c].subscript_param_id!=b->sub.sub_val[c].subscript_param_id) return 0;
    if (a->sub.sub_val[c].element!=b->sub.sub_val[c].element) return 0;
  }
  return 1;
}



int
compare_list (struct param *pa, struct param *pb)
{
  int a;
  if (pa->param_u.p_list->list_param_id.list_param_id_len!= pb->param_u.p_list->list_param_id.list_param_id_len) return 0;
  for(a=0;a<pa->param_u.p_list->list_param_id.list_param_id_len;a++) {
  	if (pa->param_u.p_list->list_param_id.list_param_id_val[a]!= pb->param_u.p_list->list_param_id.list_param_id_val[a]) return 0;
  }
  return 1;
}



int
compare_op (struct param *pa, struct param *pb)
{
  if (pa->param_u.op->left_param_id!=pb->param_u.op->left_param_id)  return 0;
  if (pa->param_u.op->op_i!=pb->param_u.op->op_i)  return 0;
  if (pa->param_u.op->right_param_id!=pb->param_u.op->right_param_id)  return 0;
  return 1;
}





void
replace_param_in_list (struct param_list *p_list, int from, int to)
{
  int a;
  for (a = 0; a < p_list->list_param_id.list_param_id_len; a++)
    {
      if (p_list->list_param_id.list_param_id_val[a] == from)
	{
	  p_list->list_param_id.list_param_id_val[a] = to;
	}
    }
}


void
replace_param (int from, int to)
{
  int a;



// Firstly - look through our parameters themselves...
  for (a = 0; a < this_module.params.params_len; a++)
    {
      if (this_module.params.params_val[a].param_type == PARAM_TYPE_CALL)
	{
	  struct param *list;
	if (this_module.params.params_val[a].param_u.c_call-> func_params_param_id==-1) {
	  list=get_param();
	} else {
	  list = &PARAM_ID (this_module.params.params_val[a].param_u.c_call-> func_params_param_id);
	}
	  if (list->param_type != PARAM_TYPE_LIST)
	    {
	      printf ("Odd - was expecting a list\n");
	      exit (3);
	    }
	  replace_param_in_list (list->param_u.p_list, from, to);
	}

      if (this_module.params.params_val[a].param_type == PARAM_TYPE_LIST)
	{
	  replace_param_in_list (this_module.params.params_val[a].param_u.
				 p_list, from, to);
	}

      if (this_module.params.params_val[a].param_type == PARAM_TYPE_OP)
	{
	  if (this_module.params.params_val[a].param_u.op->left_param_id ==
	      from)
	    this_module.params.params_val[a].param_u.op->left_param_id = to;
	  if (this_module.params.params_val[a].param_u.op->right_param_id ==
	      from)
	    this_module.params.params_val[a].param_u.op->right_param_id = to;
	}

      if (this_module.params.params_val[a].param_type == PARAM_TYPE_USE_VAR)
	{
	  int aa;
	  if (this_module.params.params_val[a].param_u.uv)
	    {
	      for (aa = 0;
		   aa <
		   this_module.params.params_val[a].param_u.uv->sub.sub_len;
		   aa++)
		{
		  if (this_module.params.params_val[a].param_u.uv->sub.
		      sub_val[aa].subscript_param_id == from)
		    {
		      this_module.params.params_val[a].param_u.uv->sub.
			sub_val[aa].subscript_param_id = to;
		    }
		}
	    }
	}

    }


// Now go through our functions and fix any commands...

   

}

void
optimize ()
{
#ifdef DO_OPTIMIZE
  struct cmd *cmds = 0;
  struct cmd *o = 0;
  int a;
  int b;
  struct npfunction *func;
  int pcoff = 0;
  int tpcoff = 0;
  int *old_pc_to_new_pc = 0;
  int rm_params;
  int stage;
  int *map_param;
  int match;
  int cnts[255];


  printf ("Optimising NOPs in functions\n");
  for (a = 0; a < this_module.functions.functions_len; a++)
    {
      func = &this_module.functions.functions_val[a];
      printf ("Looking for NOPs in function %d            \r", a);
      pcoff = 0;
      if (old_pc_to_new_pc)
	free (old_pc_to_new_pc);
      old_pc_to_new_pc = malloc (sizeof (long) * func->cmds.cmds_len);

      cmds = malloc (sizeof (struct cmd) * func->cmds.cmds_len);
      memset (cmds, 0, sizeof (struct cmd) * func->cmds.cmds_len);

      // First pass - generate our list of old -> new pointers...
      for (b = 0; b < func->cmds.cmds_len; b++)
	{
	  if (func->cmds.cmds_val[b].cmd_type == CMD_NOP)
	    {
	      old_pc_to_new_pc[b] = b - pcoff;
	      pcoff++;
	    }
	  else
	    {
	      if (b - pcoff >= 0)
		{
		  old_pc_to_new_pc[b] = b - pcoff;
		}
	      else
		{
		  old_pc_to_new_pc[b] = 0;
		}
	    }
	}

      if (pcoff == 0)
	{
	  // Theres nothing to do...
	  continue;
	}



// Ok - we know they're are some no-ops there - shuffle them out of the way...
      for (b = 0; b < func->cmds.cmds_len; b++)
	if (func->cmds.cmds_val[b].cmd_type != CMD_NOP)
	  {
	    int new_offset;
	    new_offset = old_pc_to_new_pc[b];

	    if (new_offset < 0)
	      {
		printf ("Newoffset shouldn't be <0 \n");
		printf ("b=%d old_pc_to_new_pc=%d\n", b, old_pc_to_new_pc[b]);
		exit (2);
	      }

	    if (b == 0 && new_offset != 0)
	      {
		printf ("Worry- 00\n");
		exit (2);
	      }

	    memcpy (&cmds[new_offset], &func->cmds.cmds_val[b],
		    sizeof (struct cmd));

	    // Some commands point to PCs or relative PCs - fix them too...
	    if (cmds[new_offset].cmd_type == CMD_IF)
	      {
		cmds[new_offset].cmd_u.c_if->goto_true =
		  old_pc_to_new_pc[b +
				   cmds[new_offset].cmd_u.c_if->goto_true] -
		  new_offset;
		cmds[new_offset].cmd_u.c_if->goto_false =
		  old_pc_to_new_pc[b +
				   cmds[new_offset].cmd_u.c_if->
				   goto_false] - new_offset;
	      }

	    if (cmds[new_offset].cmd_type == CMD_GOTO_PC)
	      {
		cmds[new_offset].cmd_u.c_goto_pc =
		  old_pc_to_new_pc[b + cmds[new_offset].cmd_u.c_goto_pc] -
		  new_offset;
	      }
	  }



      printf ("%d NOPs removed for function %d          \r", pcoff, a);

      // We now have a fixed copy and the original copy...
      if (really)
	{
	  o = func->cmds.cmds_val;
	  func->cmds.cmds_val = cmds;

	  printf ("len was %d pcoff=%d  ", func->cmds.cmds_len, pcoff);

	  func->cmds.cmds_len -= pcoff;

	  printf ("->%p %d\n", cmds, func->cmds.cmds_len);


	  free (o);
	  for (b = 0; b < func->cmds.cmds_len; b++)
	    {
	      if (func->cmds.cmds_val[b].cmd_type == CMD_NULL)
		{
		  printf ("Something went wrong with %d\n", b);
		  exit (54);
		}
	    }
	}

      tpcoff += pcoff;

    }
  printf ("Total of %d NOPS removed                   \n\n", tpcoff);



  stage = 0;

  map_param = malloc (this_module.params.params_len * sizeof (long));
  for (a = 0; a < this_module.params.params_len; a++)
    map_param[a] = a;
  while (1)
    {
      rm_params = 0;
      printf ("Parameter optimization - stage %d\n", stage++);
      if (stage > 5)
	break;
      if (stage <= 1)
	{
	  for (a = 0; a < 255; a++)
	    {
	      printf ("CLEAR CNTS\n");
	      cnts[a] = 0;
	    }
	}
      for (a = 0; a < this_module.params.params_len; a++)
	{
	  int match = -1;
	  if (stage == 1)
	    {
	      cnts[this_module.params.params_val[a].param_type]++;
	      printf ("INC CNTS : %d -> %d\n",
		      this_module.params.params_val[a].param_type,
		      cnts[this_module.params.params_val[a].param_type]);
	    }
	  if (this_module.params.params_val[a].param_type == PARAM_TYPE_NULL)
	    continue;

	  for (b = 1; b < a; b++)
	    {
	      // Does it match exactly ?
	      if (this_module.params.params_val[a].param_type !=
		  this_module.params.params_val[b].param_type)
		continue;

	      if (memcmp
		  (&this_module.params.params_val[a],
		   &this_module.params.params_val[b],
		   sizeof (this_module.params.params_val[a])) == 0)
		{
		  match = b;
		  break;
		}
	      else
		{
		  
		     // Well its the same type - so it may match...
		     struct param *pa;
		     struct param *pb;
		  	pa=&this_module.params.params_val[a];
		  	pb=&this_module.params.params_val[b];
		     switch (this_module.params.params_val[a].param_type) {
		     case PARAM_TYPE_NULL:                match=b; break;
		     case PARAM_TYPE_EMPTY:               match=b; break;

		     case PARAM_TYPE_LITERAL_INT:         if (pa->param_u.n==pb->param_u.n) {match=b;} break;
		     case PARAM_TYPE_LITERAL_CHAR:           if (pa->param_u.c==pb->param_u.c) {match=b;} break;
		     case PARAM_TYPE_LITERAL_STRING:         if (pa->param_u.str_entry==pb->param_u.str_entry) {match=b;} break;
		     case PARAM_TYPE_LITERAL_DOUBLE:         if (*pa->param_u.d==*pb->param_u.d) {match=b;} break;

		     case PARAM_TYPE_USE_VAR: 			if (compare_uv(pa,pb)) {match=b;} break;
		     case PARAM_TYPE_LIST:    			if (compare_list(pa,pb)) {match=b;} break; 
		     case PARAM_TYPE_OP:      			if (compare_op(pa,pb)) {match=b;} break;    

		     }
		   
		  if (match != -1)
		    break;
		}

	    }
	  if (match != -1)
	    {
	      map_param[b] = a;
	      this_module.params.params_val[a].param_type = PARAM_TYPE_NULL;
	      rm_params++;
	      replace_param (b, a);
	    }
	}

      printf ("removed %d params out of %d \n", rm_params,
	      this_module.params.params_len);
      //rm_params=0;
      if (rm_params == 0)
	break;
    }

  for (a = 0; a < 255; a++)
    {
      if (cnts[a])
	{
	  printf ("PARAM TYPE USED : %d %d times\n", a, cnts[a]);
	}
    }
  //print_module ();
#endif


}
