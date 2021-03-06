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

extern module *this_module_ptr;
int really = 1;
void remove_nop_params (void);
int replaced_cnt=0;


void replace_param_id_in_use_var (struct use_variable *uv, int from, int to);


int
compare_uv (struct param *pa, struct param *pb)
{
  struct use_variable *a;
  struct use_variable *b;
  int c;
  a = pa->param_u.uv;
  b = pb->param_u.uv;

  if (a->variable_id != b->variable_id)
    return 0;
  if (a->defined_in_block_pc != b->defined_in_block_pc)
    return 0;
  if (a->indirection != b->indirection)
    return 0;

  if (a->sub.sub_len != b->sub.sub_len)
    return 0;
  for (c = 0; c < a->sub.sub_len; c++)
    {
      if (a->sub.sub_val[c].x1subscript_param_id[0] !=
	  b->sub.sub_val[c].x1subscript_param_id[0])
	return 0;
      if (a->sub.sub_val[c].x1subscript_param_id[1] !=
	  b->sub.sub_val[c].x1subscript_param_id[1])
	return 0;
      if (a->sub.sub_val[c].x1subscript_param_id[2] !=
	  b->sub.sub_val[c].x1subscript_param_id[2])
	return 0;
      if (a->sub.sub_val[c].x1element != b->sub.sub_val[c].x1element)
	return 0;
    }
  return 1;
}



int
compare_list (struct param *pa, struct param *pb)
{
  int a;
  if (pa->param_u.p_list->list_param_id.list_param_id_len !=
      pb->param_u.p_list->list_param_id.list_param_id_len)
    return 0;
  for (a = 0; a < pa->param_u.p_list->list_param_id.list_param_id_len; a++)
    {
      if (pa->param_u.p_list->list_param_id.list_param_id_val[a] !=
	  pb->param_u.p_list->list_param_id.list_param_id_val[a])
	return 0;
    }
  return 1;
}


int
compare_call (struct param *pa, struct param *pb)
{

  if (pa->param_u.c_call->func_id != pb->param_u.c_call->func_id)
    return 0;
  if (pa->param_u.c_call->func_params_param_id !=
      pb->param_u.c_call->func_params_param_id)
    return 0;

  return 1;
}


int
compare_op (struct param *pa, struct param *pb)
{
  if (pa->param_u.op->left_param_id != pb->param_u.op->left_param_id)
    return 0;
  if (pa->param_u.op->op_i != pb->param_u.op->op_i)
    return 0;
  if (pa->param_u.op->right_param_id != pb->param_u.op->right_param_id)
    return 0;
  return 1;
}





void
replace_param_in_list (struct module *mptr, struct param_list *p_list,
		       int from, int to)
{
  int a;
  for (a = 0; a < p_list->list_param_id.list_param_id_len; a++)
    {
      if (p_list->list_param_id.list_param_id_val[a] == from)
	{
	  p_list->list_param_id.list_param_id_val[a] = to;
	  	//printf("RPLCNT Count in list %d\n",from);
	  replaced_cnt++;
	}
    }
}


void replace_param (struct module *mptr, int from, int to)
{
  int a;
  int b;



//printf("Replace param from : %d to %d\n",from,to);



// Firstly - look through our parameters themselves...
  for (a = 0; a < mptr->params.params_len; a++)
    {
      if (mptr->params.params_val[a].param_type == PARAM_TYPE_CALL)
	{
	  struct param *list;
	  if (mptr->params.params_val[a].param_u.c_call->
	      func_params_param_id == from)
	    {
	      mptr->params.params_val[a].param_u.c_call-> func_params_param_id = to;
	  	//printf("RPLCNT Count in CALL %d\n",from);
	      replaced_cnt++;
	    }

	  if (mptr->params.params_val[a].param_u.c_call->
	      func_params_param_id == -1)
	    {
	      list = nget_param (0);
	    }
	  else
	    {



	      //printf("ID : %d\n",mptr->params.params_val[a].param_u.c_call-> func_params_param_id);
	      if (mptr->params.params_val[a].param_u.c_call->
		  func_params_param_id <= 0)
		continue;



	      list =
		&PARAM_ID (mptr,
			   mptr->params.params_val[a].param_u.c_call->
			   func_params_param_id);
	      list = 0;
	    }

	  if (list == 0)
	    continue;

	  if (list->param_type == PARAM_TYPE_NOP)
	    {
	      continue;
	    }


	  /* Dont think this is required... */

	  if (list->param_type == PARAM_TYPE_NULL)
	    {
	      mptr->params.params_val[a].param_u.c_call->
		func_params_param_id = 0;
	    }

	  else
	    {

	      if (list->param_type != PARAM_TYPE_LIST)
		{
		  printf
		    ("Odd - was expecting a list - %d paramID : %ld @ %d in %s (From=%d to =%d\n",
		     list->param_type,
		     mptr->params.params_val[a].param_u.c_call->
		     func_params_param_id, a, mptr->module_name, from, to);
		  exit (3);
		}
	      replace_param_in_list (mptr, list->param_u.p_list, from, to);

	    }



	}



      if (mptr->params.params_val[a].param_type == PARAM_TYPE_LIST)
	{
	  replace_param_in_list (mptr, mptr->params.params_val[a].param_u.  p_list, from, to);
	}

      if (mptr->params.params_val[a].param_type == PARAM_TYPE_OP)
	{
	  if (mptr->params.params_val[a].param_u.op->left_param_id == from) {
	    mptr->params.params_val[a].param_u.op->left_param_id = to;
	  	//printf("RPLCNT Count in OP (left) %d\n",from);
	    replaced_cnt++;
	  }

	  if (mptr->params.params_val[a].param_u.op->right_param_id == from) {
	    mptr->params.params_val[a].param_u.op->right_param_id = to;
	  	//printf("RPLCNT Count in OP (right) %d\n",from);
	    	replaced_cnt++;
	  }
	}

      if (mptr->params.params_val[a].param_type == PARAM_TYPE_USE_VAR)
	{
	  //printf("  Use var @ %d\n",a);
	  replace_param_id_in_use_var (mptr->params.params_val[a].param_u.uv,
				       from, to);
	}
    }




// Now go through our functions and fix any commands...



  for (a = 0; a < mptr->functions.functions_len; a++)
    {
      for (b = 0; b < mptr->functions.functions_val[a].cmds.cmds_len; b++)
	{
	  struct cmd *c;
	  c = &mptr->functions.functions_val[a].cmds.cmds_val[b];

	  switch (c->npcode_cmd_type)
	    {

	    case CMD_CALL:
	      if (c->cmd_u.c_call->func_params_param_id == from)
		{
		  c->cmd_u.c_call->func_params_param_id = to;
	  		//printf("RPLCNT CMD_CALL %d\n",from);
	    		replaced_cnt++;
		}
	      break;


	    case CMD_SET_VAR:
	      if (c->cmd_u.c_setvar->value_param_id == from)
		{
		  c->cmd_u.c_setvar->value_param_id = to;
	  		//printf("RPLCNT CMD_SET %d\n",from);
	    		replaced_cnt++;
		}
	      replace_param_id_in_use_var (&c->cmd_u.c_setvar->variable, from, to);
	      break;
	    case CMD_SET_VAR_ONCE:
	      if (c->cmd_u.c_setvar1->value_param_id == from)
		{
		  c->cmd_u.c_setvar1->value_param_id = to;
	    		replaced_cnt++;
	  		//printf("RPLCNT CMD_SET_1 %d\n",from);
		}
	      replace_param_id_in_use_var (&c->cmd_u.c_setvar1->variable,
					   from, to);
	      break;

	    case CMD_IF:
	      if (c->cmd_u.c_if->condition_param_id == from)
		{
		  c->cmd_u.c_if->condition_param_id = to;
	    		replaced_cnt++;
	  		//printf("RPLCNT CMD_IF %d\n",from);
		}
	      break;

	    case CMD_PUSH_CHARV:
	      if (c->cmd_u.c_var_param_id == from)
		{
		  c->cmd_u.c_var_param_id = to;
	    		replaced_cnt++;
	  		//printf("RPLCNT CMD_PUSH_CHARV %d\n",from);
		}
	      break;

	    case CMD_RETURN:
	      //printf("See cmd_return : %d from =%d(%d-%d)\n",c->cmd_u.c_return_param_id,from,a,b);
	      if (c->cmd_u.c_return_param_id == from)
		{
		  c->cmd_u.c_return_param_id = to;
	    		replaced_cnt++;
	  		////printf("RPLCNT CMD_RETURN %d\n",from);
		}
	      break;

	    }
	}
    }



/*
        CMD_SET_VAR = 5,
        CMD_SET_VAR_ONCE = 6,
        CMD_GOTO_LABEL = 7,
        CMD_GOTO_PC = 8,
        CMD_RETURN = 9,
        CMD_NOP = 10,
        CMD_PUSH_LONG = 11,
        CMD_PUSH_INT = 12,
        CMD_PUSH_CHAR = 13,
        CMD_PUSH_CHARV = 14,
        CMD_CHK_ERR = 15,
        CMD_PUSH_VARIABLE = 16,
        CMD_END_4GL_0 = 17,
        CMD_END_4GL_1 = 18,
        CMD_DISPLAY_AT = 19,
        CMD_PUSH_OP = 20,
        CMD_CLR_ERR = 21,
        CMD_ERRCHK = 22,
        CMD_ECALL = 23,
        CMD_SET_STAT = 24,
        CMD_SET_LINE = 25,
        CMD_PUSH_OP_AND = 26,
        CMD_PUSH_OP_OR = 27,
        CMD_PUSH_OP_EQUAL = 28,
        CMD_PUSH_OP_CONCAT = 29,
        CMD_PUSH_OP_ISNULL = 30,
        CMD_ERRCHK_40110 = 31,
        CMD_ERRCHK_40010 = 32,
        CMD_ERRCHK_40000 = 33,
        CMD_PUSH_FUNCTION = 34,
        CMD_POP_FUNCTION = 35,
        CMD_POP_ARGS = 36,
        CMD_POP_PARAM = 37,
        CMD_POP_VAR2 = 38,
*/


}


void
replace_param_id_in_use_var (struct use_variable *uv, int from, int to)
{
  int aa;
  if (uv)
    {
      for (aa = 0; aa < uv->sub.sub_len; aa++)
	{
	  if (uv->sub.sub_val[aa].x1subscript_param_id[0] == from)
	    {
	      uv->sub.sub_val[aa].x1subscript_param_id[0] = to;
	    		replaced_cnt++;
	  		//printf("RPLCNT id1 %d\n",from);
	      //printf("  replace lvl 0  %d %d\n",from,to);
	    }
	  if (uv->sub.sub_val[aa].x1subscript_param_id[1] == from)
	    {
	      uv->sub.sub_val[aa].x1subscript_param_id[1] = to;
	    		replaced_cnt++;
	  		//printf("RPLCNT id2 %d\n",from);
	      //printf("  replace lvl 1  %d %d\n",from,to);
	    }
	  if (uv->sub.sub_val[aa].x1subscript_param_id[2] == from)
	    {
	      uv->sub.sub_val[aa].x1subscript_param_id[2] = to;
	    		replaced_cnt++;
	  		//printf("RPLCNT id3 %d\n",from);
	      //printf("  replace lvl 2  %d %d\n",from,to);
	    }
	}
    }
}
void
optimize ()
{
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
  //int match;
  int cnts[255];

#define REMOVE_NOPS
#ifdef REMOVE_NOPS
  //printf ("Optimising NOPs in functions\n");
  for (a = 0; a < this_module_ptr->functions.functions_len; a++)
    {
      func = &this_module_ptr->functions.functions_val[a];
      //printf ("Looking for NOPs in function %d            \n", a);
      pcoff = 0;
      if (old_pc_to_new_pc) free (old_pc_to_new_pc);
      old_pc_to_new_pc = acl_malloc2 (sizeof (long) * func->cmds.cmds_len);

      cmds = acl_malloc2 (sizeof (struct cmd) * func->cmds.cmds_len);
      memset (cmds, 0, sizeof (struct cmd) * func->cmds.cmds_len);

      // First pass - generate our list of old -> new pointers...
      for (b = 0; b < func->cmds.cmds_len; b++)
	{
	  if (func->cmds.cmds_val[b].npcode_cmd_type == CMD_NOP)
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
	if (func->cmds.cmds_val[b].npcode_cmd_type != CMD_NOP)
	  {
	    int new_offset;
	    new_offset = old_pc_to_new_pc[b];

	    if (new_offset < 0)
	      {
		fprintf (stderr,"Newoffset shouldn't be <0 \n");
		fprintf (stderr,"b=%d old_pc_to_new_pc=%d\n", b, old_pc_to_new_pc[b]);
		exit (2);
	      }

	    if (b == 0 && new_offset != 0)
	      {
		fprintf (stderr,"Worry- 00\n");
		exit (2);
	      }

	    memcpy (&cmds[new_offset], &func->cmds.cmds_val[b],
		    sizeof (struct cmd));

	    // Some commands point to PCs or relative PCs - fix them too...
	    if (cmds[new_offset].npcode_cmd_type == CMD_IF)
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

	    if (cmds[new_offset].npcode_cmd_type == CMD_GOTO_PC)
	      {
		cmds[new_offset].cmd_u.c_goto_pc =
		  old_pc_to_new_pc[b + cmds[new_offset].cmd_u.c_goto_pc] -
		  new_offset;
	      }
	  }



      fprintf (stderr,"%d NOPs removed for function %d          \r", pcoff, a);

      // We now have a fixed copy and the original copy...
      if (really)
	{
	  o = func->cmds.cmds_val;
	  func->cmds.cmds_val = cmds;

	  fprintf (stderr,"len was %d pcoff=%d  ", func->cmds.cmds_len, pcoff);

	  func->cmds.cmds_len -= pcoff;

	  fprintf (stderr,"->%p %d\n", cmds, func->cmds.cmds_len);


	  free (o);
	  for (b = 0; b < func->cmds.cmds_len; b++)
	    {
	      if (func->cmds.cmds_val[b].npcode_cmd_type == CMD_NULL)
		{
		  fprintf (stderr,"Something went wrong with %d\n", b);
		  exit (54);
		}
	    }
	}

      tpcoff += pcoff;

    }
  fprintf (stderr,"Total of %d NOPS removed                   \n\n", tpcoff);
#endif


  stage = 0;

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
	      //printf ("CLEAR CNTS\n");
	      cnts[a] = 0;
	    }
	}
      for (a = 0; a < this_module_ptr->params.params_len; a++)
	{
	  int match = -1;
	  if (stage == 1)
	    {
	      cnts[this_module_ptr->params.params_val[a].param_type]++;
	      //printf ("INC CNTS : %d -> %d\n", this_module_ptr->params.params_val[a].param_type, cnts[this_module_ptr->params.params_val[a].param_type]);
	    }


	  if (this_module_ptr->params.params_val[a].param_type == PARAM_TYPE_NOP) continue;

	  for (b = 1; b < a; b++)
	    {
	      // Does it match exactly ?
	      if (this_module_ptr->params.params_val[a].param_type !=
		  this_module_ptr->params.params_val[b].param_type)
		continue;

	      if (memcmp
		  (&this_module_ptr->params.params_val[a],
		   &this_module_ptr->params.params_val[b],
		   sizeof (this_module_ptr->params.params_val[a])) == 0)
		{
		  printf ("Match %d %d on memory check\n", a, b);
		  match = b;
		  break;
		}
	      else
		{

		  // Well its the same type - so it may match...
		  struct param *pa;
		  struct param *pb;
		  pa = &this_module_ptr->params.params_val[a];
		  pb = &this_module_ptr->params.params_val[b];

		  switch (this_module_ptr->params.params_val[a].param_type)
		    {
		    case PARAM_TYPE_NULL:
		      printf ("Matched type null\n");
		      match = b;
		      break;
		    case PARAM_TYPE_EMPTY:
		      match = b;
		      break;

		    case PARAM_TYPE_LITERAL_INT:
		      if (pa->param_u.n == pb->param_u.n)
			{
			  match = b;
			}
		      break;
		    case PARAM_TYPE_LITERAL_CHAR:
		      if (pa->param_u.c == pb->param_u.c)
			{
			  match = b;
			}
		      break;
		    case PARAM_TYPE_LITERAL_STRING:
		      if (pa->param_u.str_entry == pb->param_u.str_entry)
			{
			  match = b;
			}
		      break;
		    case PARAM_TYPE_LITERAL_DOUBLE:
		      if (*pa->param_u.d == *pb->param_u.d)
			{
			  match = b;
			}
		      break;

		    case PARAM_TYPE_USE_VAR:
		      if (compare_uv (pa, pb))
			{
			  match = b;
			}
		      break;
		    case PARAM_TYPE_LIST:
		      if (compare_list (pa, pb))
			{
			  match = b;
			}
		      break;
		    case PARAM_TYPE_CALL:
		      if (compare_call (pa, pb))
			{
			  match = b;
			}
		      break;


		    case PARAM_TYPE_OP:
		      if (compare_op (pa, pb))
			{
			  match = b;
			}
		      break;

		    }

		  if (match != -1)
		    break;
		}
	    }

	  if (match != -1)
	    {
	      rm_params++;
	      replace_param (this_module_ptr, a, 0 - b);
	      this_module_ptr->params.params_val[a].param_type = PARAM_TYPE_NOP;
	    }
	}

      printf ("removed %d params out of %d \n", rm_params,
	      this_module_ptr->params.params_len);
      //rm_params=0;
      if (rm_params == 0)
	break;
      for (b = 1; b < a; b++)
	{
	  replace_param (this_module_ptr, 0 - b, b);
	}

       
      for (b = 1; b < a; b++)
	{
	  replaced_cnt=0;
	  replace_param (this_module_ptr, b, b);
	  if (replaced_cnt==0) {
		  // This doesn't look like its actually used !
		  //printf("Parameter %d isn't even used !\n",b);
		  this_module_ptr->params.params_val[b].param_type = PARAM_TYPE_NOP;
	  }
	  //printf("Param %d used %d times\n",b,replaced_cnt);
	}
    }



  for (a = 0; a < 255; a++)
    {
      if (cnts[a])
	{
	  printf ("PARAM TYPE USED : %d %d times\n", a, cnts[a]);
	}
    }

  remove_nop_params ();
  for (a = 0; a < 255; a++)
    {
      cnts[a] = 0;
    }


  for (a = 0; a < this_module_ptr->params.params_len; a++)
    cnts[this_module_ptr->params.params_val[a].param_type]++;

  for (a = 0; a < 255; a++)
    {
      if (cnts[a])
	{
	  printf ("AFTER PARAM TYPE USED : %d %d times\n", a, cnts[a]);
	}
    }


  //print_module ();


}



void
remove_nop_params (void)
{
  int a;
  int b;
  b = 0;
  for (a = 0; a < this_module_ptr->params.params_len; a++)
    {
      if (this_module_ptr->params.params_val[a].param_type == PARAM_TYPE_NOP)
	{
	  continue;
	}

      if (a != b)
	{
	  memcpy (&this_module_ptr->params.params_val[b],
		  &this_module_ptr->params.params_val[a],
		  sizeof (this_module_ptr->params.params_val[a]));
	  replace_param (this_module_ptr, a, b);
	}
      b++;
    }
  printf ("Now got %d params instead of %d\n", b,
	  this_module_ptr->params.params_len);
  this_module_ptr->params.params_len = b;

}
