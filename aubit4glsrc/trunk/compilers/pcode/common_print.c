#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NEED_CMD_TYPE_STR

#if (defined(__CYGWIN__)) || defined(__MINGW32__)
	/* missing from rpcgen generated .h on CygWin: */
	#define bool_t int
	#define u_int unsigned int
#endif

#include "npcode.h"
#include "npcode_defs.h"

extern module this_module;


char *op_str[]={
        "EOP_EQUAL",
        "EOP_GT",
        "EOP_GTE",
        "EOP_LT",
        "EOP_LTE",
        "EOP_PLUS",
        "EOP_MINUS",
        "EOP_MULTIPLY",
        "EOP_DIVIDE",
        "EOP_AND",
        "EOP_OR",
        "EOP_LOGAND",
        "EOP_LOGOR",
        "EOP_NE",
        "EOP_NOT"
,0

};




void print_push_int(int n)  ;
void print_push_op(int n)  ;
void print_push_long(int n)  ;
void print_set_stat(int n) ;
void print_ecall(struct ecall *e) ;
void print_chk_err(int lineno) ;
void print_push_char(int n)  ;
void print_push_op(int n)  ;
void print_set_stat(int n) ;
static void print_command (long func_id, long pc, struct cmd *cmd);
void  print_clr_err(void) ;

void
print_use_variable (struct use_variable *v)
{
  printf ("UV(%d,%d,%d) : ", v->variable_id, v->defined_in_block_pc, v->indirection);
  if (v->sub.sub_len)
    {
      int a;
      for (a = 0; a < v->sub.sub_len; a++)
	{
	  if (v->sub.sub_val[a].x1element != -1)
	    {
	      printf (".%ld ", v->sub.sub_val[a].x1element);
	    }

	  if (v->sub.sub_val[a].x1subscript_param_id[0] != 0)
	    {
	        printf ("[ "); print_params (v->sub.sub_val[a].x1subscript_param_id[0]); printf ("]");
	      	if (v->sub.sub_val[a].x1subscript_param_id[1]!=0) {
			printf ("["); print_params (v->sub.sub_val[a].x1subscript_param_id[1]); printf ("]");
	      		if (v->sub.sub_val[a].x1subscript_param_id[2]!=0) {
	      			printf ("["); print_params (v->sub.sub_val[a].x1subscript_param_id[2]); printf ("]");
			}
		}
	    }
	}
    }
	printf(")");
}


void
print_call_return (long e)
{
  printf ("Returning ");
  print_params (e);


}

void
print_module_functions ()
{
  int func_cnt;
  int cmd_cnt;
  int a;


  for (func_cnt = 0; func_cnt < this_module.functions.functions_len;
       func_cnt++)
    {
      struct npfunction *f;
      f = &this_module.functions.functions_val[func_cnt];
      printf ("FUNCTION : %s\n",
	      GET_ID (this_module.functions.functions_val[func_cnt].
		      func_name_id));
      printf ("%d parameters\n", f->param_vars.param_vars_len);


      for (a = 0; a < f->param_vars.param_vars_len; a++)
	{
	  print_use_variable (&f->param_vars.param_vars_val[a]);
	}


      for (cmd_cnt = 0;
	   cmd_cnt <
	   this_module.functions.functions_val[func_cnt].cmds.cmds_len;
	   cmd_cnt++)
	{
	  print_command (func_cnt, cmd_cnt,
			 &this_module.functions.functions_val[func_cnt].cmds.
			 cmds_val[cmd_cnt]);
	}
    }


}




void
print_block (struct cmd_block *b)
{
  int a;
  printf ("BLOCK (%d variables) %ld bytes to allocate\n",
	  b->c_vars.c_vars_len, b->mem_to_alloc);
  for (a = 0; a < b->c_vars.c_vars_len; a++)
    {
      printf ("   ");
      print_variable (1, &b->c_vars.c_vars_val[a]);
    }

}



static void
print_goto_label (char *p)
{
  printf ("Goto  %s", p);
}

static void
print_goto_pc (long p)
{
  if (p == 0)
    {
      printf ("NOP");
      return;
    }
  printf ("Goto relative ");

  if (p > 0)
    printf ("+");

  printf ("%ld", p);
}


void
print_set_var (struct cmd_set_var *v)
{
  //printf ("%p",&v->variable);
  print_use_variable (&v->variable);
  printf ("=");
  print_params (v->value_param_id);
}

void
print_set_var_once (struct cmd_set_var1 *v)
{
  //printf ("%p",&v->variable);
  print_use_variable (&v->variable);
  printf ("=");
  print_params (v->value_param_id);
}


static void
print_end_block (void *p)
{
  struct cmd_end_block *e;
  e = p;
  if (e)
    {
      printf ("END BLOCK %ld\n", e->pc_start_block);
    }
}

static void
print_call (struct npcmd_call *c)
{
  char *x;
  x = GET_ID (c->func_id);
  printf ("CALL FUNCTION %s : ", x);
  print_params (c->func_params_param_id);
}


static void
print_if (struct npcmd_if *i)
{
  print_params (i->condition_param_id);
  printf ("    True  : ");
  print_goto_pc (i->goto_true);
  printf ("\n");
  printf ("    False : ");
  print_goto_pc (i->goto_false);
}

void print_ecall(struct ecall *e) {
	printf("ECALL %d %d %d",e->func_id,e->ln,e->nparam);
}
void print_set_stat(int n) {
	printf("SET STATUS : %d\n",n);
}
void print_set_line(int n) {
	printf("SET LINE : %d\n",n);
}
void print_push_char(int n)  {
	printf("A4GL_push_char(\"%s\")",GET_ID(n));
}

void print_push_charv(int n)  {
	printf("A4GL_push_chav(%d)",n);
}
void print_push_int(int n)  {
	printf("A4GL_push_int(%d)",n);
}


void print_errchk(struct cmd_errchk *e) {
	printf("ERRCHK %ld %ld\n",e->line,e->module_name);
}

void print_errchk_40110(struct cmd_errchk_40110 *e) {
	if (e) {
		printf("ERRCHK40110 %ld %ld\n",e->line,e->module_name);
	} else {
		printf("ERRCHK40110 is null\n");
	}
}
void print_errchk_40010(struct cmd_errchk_40010 *e) {
	if (e) {
		printf("ERRCHK40010 %ld %ld\n",e->line,e->module_name);
	} else {
		printf("ERRCHK40010 is null\n");
	}
}

void print_errchk_40000(struct cmd_errchk_40000 *e) {
	if (e) {
		printf("ERRCHK40000 %ld %ld\n",e->line,e->module_name);
	} else {
		printf("ERRCHK40000 is null\n");
	}
}


void  print_clr_err(void) {
	printf("aclfgli_clr_err_flg()");
}
void print_chk_err(int lineno) {
	printf("A4GL_chk_err(%d,_modulename)",lineno);
}
void print_push_long(int n)  {
	printf("A4GL_push_long(%d) /* 0x%x */",n,n);
}

void print_push_op(int n)  {
	printf("A4GL push op(%d)",n);
}

void
print_var_element (int lvl, struct variable_element *ve)
{
  int a;
int b;
printf("\n");
  for (a = 0; a < lvl+1; a++)
    {
      printf ("   ");
    }
  printf ("Name ID = %d (%s) ", ve->name_id, GET_ID (ve->name_id));
  printf ("DTYPE= %ld ", ve->dtype);
  if (ve->i_arr_size[0])
    {
      printf ("ARRAY [%d][%d][%d] ", ve->i_arr_size[0], ve->i_arr_size[1],
	      ve->i_arr_size[2]);
    }

  printf ("total_size=%ld ", ve->total_size);
  printf ("unit_size=%d ", ve->unit_size);
  printf ("offset=%ld ", ve->offset);
  if (ve->next.next_len)
    {
      printf("\n");
      for (b = 0; b < lvl+1; b++) { printf ("   "); }
      printf ("Next :\n");
      for (a = 0; a < ve->next.next_len; a++)
	{
          for (b = 0; b < lvl+1; b++) { printf ("   "); }
	  printf ("(%d)", a);
	  print_var_element (lvl + 1, &ve->next.next_val[a]);
	printf("\n");
	}
    }

  printf ("\n");
}


void
print_variable (int lvl, struct npvariable *v)
{
  if (v==0) {printf("No V..\n"); return;}
  printf ("VARIABLE :  ID=%ld CAT=%d BLOCK=%ld ", v->variable_id, v->category, v->def_block);
  if (v->var) print_var_element (0, v->var);
  else {printf("No v->var\n");}
}




static void
print_command (long func_id, long pc, struct cmd *cmd)
{
  printf ("%04ld-%04ld %02d %-10s\n   ", func_id, pc, cmd->cmd_type,
	  cmd_type_str[(int) cmd->cmd_type]);

  switch (cmd->cmd_type)
    {
    case CMD_BLOCK:
      print_block (cmd->cmd_u.c_block);
      break;
    case CMD_NOP:
	printf("CMD_NOP\n");
      break;
    case CMD_END_BLOCK:
      print_end_block (cmd->cmd_u.c_endblock);
      break;
    case CMD_CALL:
      print_call (cmd->cmd_u.c_call);
      break;
    case CMD_IF:
      print_if (cmd->cmd_u.c_if);
      break;
    case CMD_SET_VAR:
      print_set_var (cmd->cmd_u.c_setvar);
      break;
    case CMD_SET_VAR_ONCE:
      print_set_var_once (cmd->cmd_u.c_setvar1);
      break;
    case CMD_GOTO_LABEL:
      print_goto_label ((char *) cmd->cmd_u.c_goto_str);
      break;
    case CMD_GOTO_PC:
      print_goto_pc (cmd->cmd_u.c_goto_pc);
      break;
    case CMD_RETURN:
      print_call_return (cmd->cmd_u.c_return_param_id);
      break;

    case CMD_PUSH_LONG: 
	print_push_long(cmd->cmd_u.c_push_long);
	break;

    case CMD_PUSH_CHAR: 
	print_push_char(cmd->cmd_u.c_push_char);
	break;

    case CMD_PUSH_CHARV: 
	print_push_charv(cmd->cmd_u.c_var_param_id);
	break;

    case CMD_PUSH_INT: 
	print_push_int(cmd->cmd_u.c_push_int);
	break;
    case CMD_PUSH_OP: 
	print_push_op(cmd->cmd_u.c_push_int);
	break;

    case CMD_CHK_ERR:
	print_chk_err(cmd->cmd_u.c_chk_err_lineno);
	break;

    case CMD_CLR_ERR:
	print_clr_err();
	break;

    case CMD_ECALL :
	print_ecall(cmd->cmd_u.c_ecall);
  	break;

    case CMD_ERRCHK:
	print_errchk(cmd->cmd_u.c_errchk);
	break;

    case CMD_ERRCHK_40110:
	print_errchk_40110(cmd->cmd_u.c_errchk_40110);
	break;
    case CMD_ERRCHK_40000:
	print_errchk_40000(cmd->cmd_u.c_errchk_40000);
	break;
    case CMD_ERRCHK_40010:
	print_errchk_40010(cmd->cmd_u.c_errchk_40010);
	break;
    case CMD_NULL:
      fprintf (stderr, "NULL COMMAND - SHOULDN'T HAPPEN\n");
      exit (2);
   case CMD_SET_STAT:
	print_set_stat(cmd->cmd_u.c_setval);
	break;
   case CMD_SET_LINE:
	print_set_line(cmd->cmd_u.c_cline);
	break;
   case CMD_PUSH_OP_ISNULL: printf("pushop(ISNULL)\n"); break;
   case CMD_PUSH_OP_AND: printf("pushop(AND)\n"); break;
   case CMD_PUSH_OP_OR: printf("pushop(OR)\n"); break;
   case CMD_PUSH_OP_EQUAL: printf("pushop(EQUAL)\n"); break;
   case CMD_PUSH_OP_CONCAT: printf("pushop(CONCAT)\n"); break;

   case CMD_PUSH_FUNCTION : printf("pushFunction\n");break;

      case CMD_POP_FUNCTION: printf("popfunction\n"); break;
        case CMD_POP_ARGS: printf("popargs\n"); break;
        case CMD_POP_PARAM: printf("popparam\n"); break;
        case CMD_POP_VAR2: printf("popvar2\n"); break;


    default: 
		printf("Unknown command : %d\n",cmd->cmd_type);
		exit(2);
    }

  printf ("\n");

}



void
print_params (long e_l)
{
static int lvl=0;
int pa;
struct param *e;

if (e_l<0) e=nget_param(e_l);
else e=&PARAM_ID(e_l);


for (pa=0;pa<lvl;pa++) printf("  ");

  if (e == 0)
    {
      printf ("Param : Null\n");
      return;
    }



  switch (e->param_type)
    {
    case PARAM_TYPE_LITERAL_INT:
      printf ("INT %ld", e->param_u.n);
      break;
    case PARAM_TYPE_LITERAL_CHAR:
      printf ("char %c\n", e->param_u.c);
      break;
    case PARAM_TYPE_LITERAL_STRING:
      printf ("string[%ld] - %s\n", e->param_u.str_entry,
	      this_module.string_table.string_table_val[e->param_u.str_entry].
	      s);
      break;
    case PARAM_TYPE_LITERAL_DOUBLE:
      printf ("double %f\n", *e->param_u.d);
      break;
    case PARAM_TYPE_EMPTY:
      printf ("EMPTY\n");
      break;
    case PARAM_TYPE_VAR:
      printf ("string  %s\n", e->param_u.v);
      break;
    case PARAM_TYPE_VAR_ID:
      printf ("int %x\n", e->param_u.vid);
      break;
    case PARAM_TYPE_CALL:
		print_call(e->param_u.c_call);
      //printf ("struct param_c_call %p\n", e->param_u.c_call);
      break;
    case PARAM_TYPE_LIST:
      {
	struct param_list *p;
	int a;
	p = e->param_u.p_list;
	printf ("LIST [ ");
	lvl++;
	for (a = 0; a < p->list_param_id.list_param_id_len; a++)
	  {
	    for (pa=0;pa<lvl;pa++) printf("  ");
	    printf ("%d ) ", a);
	    print_params (p->list_param_id.list_param_id_val[a]);
	    if (pa<lvl-1) printf(",");

	  }
	lvl--;
	    for (pa=0;pa<lvl;pa++) printf("  ");
	printf ("]");

      }
      break;
    case PARAM_TYPE_OP:
	printf(" OP (");
      print_params (e->param_u.op->left_param_id);
      printf ("%d (%s)", e->param_u.op->op_i,op_str[e->param_u.op->op_i]);
      print_params (e->param_u.op->right_param_id);
	printf(") ");
      break;
    case PARAM_TYPE_USE_VAR:
      print_use_variable (e->param_u.uv);
      //printf ("struct use_variable %p\n", e->param_u.uv);
      break;
    case PARAM_TYPE_NULL:
      printf ("NULL\n");
      break;
    case PARAM_TYPE_NOP:
      printf ("NOP - REMOVE\n");
      break;
    case PARAM_TYPE_CACHED:
      printf ("CACHED\n");
      break;
    case PARAM_TYPE_SPECIAL:
      printf ("SPECIAL\n");
      break;
    case PARAM_TYPE_ONKEY:
      printf ("ONKEY\n");
      break;



    }
}





void
print_module ()
{
  int a;
  int tbytes;

  printf ("MAGIC   : %lx VERSION : %ld SIZE : %ld\n", this_module.fglc_magic,
	  this_module.fglc_version, this_module.file_size);
  printf ("NAME    : %s\n", this_module.module_name);
  printf ("CREATED : %s\n", ctime (&this_module.compiled_time));
  printf ("\n\nString Table\n\n");
  tbytes=0;

  for (a = 0; a < this_module.string_table.string_table_len; a++)
    {
      printf ("%d. \"%s\" %d references\n", a,
	      this_module.string_table.string_table_val[a].s,
	      this_module.string_table.string_table_val[a].rcnt);
	tbytes+=strlen(this_module.string_table.string_table_val[a].s)+4+4;
    }

  printf("Bytes=%d\n",tbytes);


tbytes=0;
  printf ("\n\nID Table\n\n");
  for (a = 0; a < this_module.id_table.id_table_len; a++)
    {
      printf ("%d. %s %d references\n", a,
	      this_module.id_table.id_table_val[a].s,
	      this_module.id_table.id_table_val[a].rcnt);
	tbytes+=strlen(this_module.id_table.id_table_val[a].s)+4+4;
    }
  printf("Bytes=%d\n",tbytes);

  printf ("\n\nExternal Function Call Table\n\n");
  for (a = 0;
       a < this_module.external_function_table.external_function_table_len;
       a++)
    {
      printf ("%d. %s\n", a,
	      GET_ID (this_module.external_function_table.
		      external_function_table_val[a]));
    }


  printf("\n\n%d parameters\n\n",this_module.params.params_len);
  for (a=0;a<this_module.params.params_len;a++) {
		printf("%d.",a);
		print_params(a);
		printf("\n");
  }

  //printf ("\n\nModule Level variables\n\n");
  //for (a = 0; a < this_module.module_variables.c_vars.c_vars_len; a++)
  //{
  //print_variable (1, &this_module.module_variables.c_vars.c_vars_val[a]);
  //}

  //for (a = 0; a < this_module.commands.commands_len; a++)
  //{
  //print_command (a, &this_module.commands.commands_val[a]);
  //}

  print_module_functions ();

}
