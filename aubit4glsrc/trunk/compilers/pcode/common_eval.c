#if (defined(__CYGWIN__)) || defined(__MINGW32__)
	/* missing from rpcgen generated .h on CygWin: */
	#define bool_t int
	#define u_int unsigned int
#endif

#include <stdio.h>
#include "npcode.h"
#include "npcode_defs.h"
//#include "a4gl_incl_4glhdr.h"
extern module this_module;
#define FglMoney long
#define FglDecimal long
#define fgldate long

/*
static char *op_str[]={
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
*/


struct param *last_set[10] ;

void nset_param(struct param *p,int n) {
	last_set[n]=p;
}


struct param *nget_param(int n) {
	return last_set[n];
}



int evaluate_param_i_into_integer (long e_i, long *x) {
struct param *e;
int a;
if (e_i<0) {
	if (e_i==-1) e=nget_param(0);
	if (e_i==-2) e=nget_param(1);
} else {
	e=&PARAM_ID(e_i);
}
a=evaluate_param_into_integer(e,x);
//printf("PARAM %d --->%d\n",e_i,a);
return a;
}



int
evaluate_param_into_integer(struct param *e, long *x)
{
  *x = -1;
  if (e == 0)
    {
      return 0;
    }

  if ((long) e < 100 && (long) e >= 0)
    {
      fprintf (stderr, "Corrupt parameter ...\n");
      return 0;
    }

  switch (e->param_type)
    {
    case PARAM_TYPE_LITERAL_INT:
      *x = e->param_u.n;
      return 1;
    case PARAM_TYPE_LITERAL_CHAR:
      *x = e->param_u.c;
      return 1;


    case PARAM_TYPE_LITERAL_STRING:
      *x =
	(int) this_module.string_table.string_table_val[e->param_u.str_entry].
	s;
      A4GL_debug ("EVALUATE Set to %p\n",
		  this_module.string_table.string_table_val[e->param_u.
							    str_entry].s);
      A4GL_debug ("EVALUATE Set to '%s'\n",
		  this_module.string_table.string_table_val[e->param_u.
							    str_entry].s);
      return 1;
    case PARAM_TYPE_LITERAL_DOUBLE:
      *(double *) x = *e->param_u.d;
      return 1;


    case PARAM_TYPE_EMPTY:
      A4GL_debug ("EMPTY\n");
      return 0;


    case PARAM_TYPE_OP:
      {
	long a;
	long b;
	A4GL_debug ("Getting a...\n");
	evaluate_param_i_into_integer (e->param_u.op->left_param_id, &a);
	if (e->param_u.op->right_param_id>0)
	  {
	    evaluate_param_i_into_integer (e->param_u.op->right_param_id, &b);
	    A4GL_debug ("Got b\n");
	  }
	else
	  {
	    b = 0;
	  }


	switch (e->param_u.op->op_i)
	  {

	  case EOP_PLUS:
	    *x = a + b;
	    return 1;
	  case EOP_MINUS:
	    *x = a - b;
	    return 1;
	  case EOP_EQUAL:
	    *x = (a == b);
	    return 1;
	  case EOP_GT:
	    *x = (a > b);
	    return 1;
	  case EOP_LT:
	    *x = (a < b);
	    return 1;
	  case EOP_GTE:
	    *x = (a >= b);
	    return 1;
	  case EOP_LTE:
	    *x = (a <= b);
	    return 1;
	  case EOP_MULTIPLY:
	    *x = (a * b);
	    return 1;
	  case EOP_DIVIDE:
	    *x = (a / b);
	    return 1;
	  case EOP_NOT:
	    *x = (!a);
	    return 1;
	  case EOP_NE:
	    *x = (a != b);
	    return 1;
	  case EOP_LOGOR:
	    *x = (a | b);
	    return 1;
	  case EOP_OR:
	    *x = (a || b);
	    return 1;
	  case EOP_LOGAND:
	    *x = (a & b);
	    return 1;
	  case EOP_AND:
	    *x = (a && b);
	    return 1;

	  }
	fprintf (stderr, "unhandled struct param_op %i\n",
		 e->param_u.op->op_i);
	exit (1);
	return 0;
      }

    case PARAM_TYPE_CALL:
      *x = call_function (0, e->param_u.c_call);
      //fprintf (stderr,"struct param_c_call %p\n", e->param_u.c_call);
      //exit (1);
      return 1;

    case PARAM_TYPE_LIST:
      fprintf (stderr, "Can't evaluate a struct param_list %p\n", e->param_u.p_list);
	{ char *ptr=0; *ptr=0;}
      exit (2);
      return 0;


    case PARAM_TYPE_USE_VAR:
      {
	void *v;
	int size;
	A4GL_debug ("struct use_variable %p\n", e->param_u.uv);
	v = get_var_ptr (e->param_u.uv,&size);
	//printf ("Got variables address as %p\n", v);
	if (v == 0)
	  {
	    fprintf (stderr, "Variable wasn't initialized...\n");
	    exit (2);
	  }
	if (size==1) *x = *(char *) v;
	if (size==2) *x = *(short *) v;
	if (size==4) *x = *(long *) v;
	if (size==8) *x = *(double *) v;

	A4GL_debug ("USE VAR --- > %d", *x);
	return 1;
      }

      //case PARAM_TYPE_VAR:                    e->param_u.v; return 0;
      //case PARAM_TYPE_VAR_ID:                 A4GL_debug("int %x\n",e->param_u.vid); break;


    case PARAM_TYPE_NULL:
    case PARAM_TYPE_VAR:
    case PARAM_TYPE_VAR_ID:
    case PARAM_TYPE_CACHED:
    case PARAM_TYPE_SPECIAL:
    case PARAM_TYPE_ONKEY:
      break;

    }

  fprintf (stderr, "Non-handled param_type... %d\n",e->param_type);
  exit (4);

  return 0;
}
