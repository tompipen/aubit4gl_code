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




void *
malloc_clr (long size)
{
  void *ptr;

  ptr = acl_malloc2 (size);
  memset (ptr, 0, size);
  return ptr;
}



char *
strdup_with_conv (char *s)
{
  char *buff;
  int a;
  int b = 0;
  buff = acl_strdup (s);
  for (a = 0; a < strlen (s); a++)
    {
      if (s[a] == '\\')
	{
	  a++;
	  switch (s[a])
	    {
	    case 'n':
	      buff[b++] = '\n';
	      break;
	    case 't':
	      buff[b++] = '\t';
	      break;
	    case 'r':
	      buff[b++] = '\r';
	      break;
	    default:
	      buff[b++] = '?';
	      break;
	    }
	  continue;
	}
      else
	{
	  buff[b++] = s[a];
	}

    }
  buff[b] = 0;
  return buff;
}

int
add_string (char *s)
{
  int nsize;
  int a;
  char *nstr;


  nstr = strdup_with_conv (s);

  for (a = 0; a < this_module_ptr->string_table.string_table_len; a++)
    {
      if (strcmp (nstr, this_module_ptr->string_table.string_table_val[a].s) == 0)
	{
	  free (nstr);
	  this_module_ptr->string_table.string_table_val[a].rcnt++;
	  return a;
	}
    }

  this_module_ptr->string_table.string_table_len++;
  nsize = sizeof (struct vstring) * this_module_ptr->string_table.string_table_len;



  this_module_ptr->string_table.string_table_val =
    realloc (this_module_ptr->string_table.string_table_val, nsize);



  this_module_ptr->string_table.string_table_val[this_module_ptr->string_table.
					    string_table_len - 1].s = nstr;
  this_module_ptr->string_table.string_table_val[this_module_ptr->string_table.
					    string_table_len - 1].rcnt = 1;
  return this_module_ptr->string_table.string_table_len - 1;
}


char *
get_string (int a)
{
  return this_module_ptr->string_table.string_table_val[a].s;
}

int
decode_op (char *op)
{

  if (strcmp (op, "==") == 0)
    return EOP_EQUAL;
  if (strcmp (op, "!=") == 0)
    return EOP_NE;
  if (strcmp (op, ">") == 0)
    return EOP_GT;
  if (strcmp (op, ">=") == 0)
    return EOP_GTE;
  if (strcmp (op, "<") == 0)
    return EOP_LT;
  if (strcmp (op, "<=") == 0)
    return EOP_LTE;
  if (strcmp (op, "+") == 0)
    return EOP_PLUS;
  if (strcmp (op, "-") == 0)
    return EOP_MINUS;
  if (strcmp (op, "*") == 0)
    return EOP_MULTIPLY;
  if (strcmp (op, "/") == 0)
    return EOP_DIVIDE;
  if (strcmp (op, "%") == 0)
    return EOP_MOD;

  if (strcmp (op, "&") == 0)
    return EOP_LOGAND;
  if (strcmp (op, "|") == 0)
    return EOP_LOGOR;
  if (strcmp (op, "&&") == 0)
    return EOP_AND;

  if (strcmp (op, "||") == 0)
    return EOP_OR;

  if (strcmp (op, "NOT") == 0)
    return EOP_NOT;

  printf ("Unknown op : %s\n", op);
  exit (1);


}


int allocated_params = 0;

void
make_new_param (int *n, struct param **p)
{
  if (this_module_ptr->params.params_len <= allocated_params)
    {
      allocated_params += 16;
      this_module_ptr->params.params_val =
	realloc (this_module_ptr->params.params_val,
		 sizeof (struct param) * allocated_params);
    }
  memset (&this_module_ptr->params.params_val[this_module_ptr->params.params_len], 0,
	  sizeof (this_module_ptr->params.
		  params_val[this_module_ptr->params.params_len]));
  this_module_ptr->params.params_val[this_module_ptr->params.params_len].param_type =
    PARAM_TYPE_EMPTY;
  if (p)
    {
      *p = &this_module_ptr->params.params_val[this_module_ptr->params.params_len];
    }
  if (n)
    {
      *n = this_module_ptr->params.params_len;
    }
  this_module_ptr->params.params_len++;
}



int
find_param (struct param *p)
{
  int a;
  for (a = 0; a < this_module_ptr->params.params_len; a++)
    {
      if (&this_module_ptr->params.params_val[a] == p)
	return a;
    }
  return -1;
}



int
get_expr_n (int n)
{
  struct param *p;
  if (n != -1)
    {
      p = &PARAM_ID (this_module_ptr, n);
    }
  else
    {
      p = nget_param (0);
    }
  return p->param_u.n;
}

void
set_expr_n (int n, int v)
{
  struct param *p;
  if (n != -1)
    {
      p = &PARAM_ID (this_module_ptr, n);
    }
  else
    {
      p = nget_param (0);
    }
  p->param_u.n = v;
}

struct use_variable *
get_use_variable (int n)
{
  struct param *p;
  if (n != -1)
    {
      p = &PARAM_ID (this_module_ptr, n);
    }
  else
    {
      p = nget_param (0);
    }
  return p->param_u.uv;
}


void
set_indirection (int n, int up_down)
{
  PARAM_ID (this_module_ptr, n).param_u.uv->indirection += up_down;
}


long
new_param_returns_long (char s, void *ptr)
{
  struct param px;
  struct param *p;
  int n;
  int a;
  p = &px;
  memset (&px, 0, sizeof (px));

  switch (s)
    {
    case 's':
      p->param_type = PARAM_TYPE_LITERAL_STRING;
      p->param_u.str_entry = (long) add_string ((char *) ptr);
      break;

    case 'v':
      p->param_type = PARAM_TYPE_VAR;
      p->param_u.v = acl_strdup (ptr);
      break;

    case 'I':
      p->param_type = PARAM_TYPE_LITERAL_INT;
      p->param_u.n = (long) ptr;
      break;

    case 'V':
      p->param_type = PARAM_TYPE_USE_VAR;
      p->param_u.uv = (struct use_variable *) ptr;
      break;

    case 'S':
      p->param_type = PARAM_TYPE_SPECIAL;
      p->param_u.special = (char *) ptr;
      break;

    case 'K':
      p->param_type = PARAM_TYPE_ONKEY;
      p->param_u.keys = (char *) ptr;
      break;


    default:
      printf ("Unknown type : %c\n", s);
      exit (12);
      break;
    }

  for (a = 0; a < this_module_ptr->params.params_len; a++)
    {
      if (memcmp
	  (&this_module_ptr->params.params_val[a], p,
	   sizeof (this_module_ptr->params.params_val[a])) == 0)
	{
	  return a;
	}
      if (this_module_ptr->params.params_val[a].param_type == p->param_type)
	{


	  if (p->param_type == PARAM_TYPE_LITERAL_INT)
	    {
	      if (p->param_u.n == this_module_ptr->params.params_val[a].param_u.n)
		return a;
	    }

	  /*
	     if (p->param_type==PARAM_TYPE_VAR) {
	     if (strcmp(p->param_u.v,this_module_ptr->params.params_val[a].param_u.v)==0) return a;
	     }
	   */



	}



    }

  make_new_param (&n, &p);
  memcpy (p, &px, sizeof (px));
  return n;

}




long
new_param_op_returns_long (long l, char *op, long r)
{
  struct param *pnew;
  struct param_op *pop;
  int n;
  make_new_param (&n, &pnew);
  pnew->param_type = PARAM_TYPE_OP;
  pop = malloc_clr (sizeof (struct param_op));
  pop->left_param_id = l;
  pop->right_param_id = r;
  pop->op_i = decode_op (op);
  pnew->param_u.op = pop;
  return check_for_duplicate_param (n);
}




long
new_param_fcall_returns_long (char *fname, long plist)
{
  struct param *pnew;
  struct npcmd_call *pcall;
  int n;
  make_new_param (&n, &pnew);

  //pnew = malloc_clr (sizeof (struct param));

  pcall = malloc_clr (sizeof (struct npcmd_call));
  pnew->param_type = PARAM_TYPE_CALL;
  pnew->param_u.c_call = pcall;
  pcall->func_id = add_id (fname);
  pcall->func_params_param_id = plist;
  return check_for_duplicate_param (n);
}


long
new_param_list_returns_long (long p)
{
  struct param *pnew;
  int n;
  make_new_param (&n, &pnew);
  pnew->param_type = PARAM_TYPE_LIST;
  pnew->param_u.p_list = 0;
  append_param_list (n, p);

  return n;
}


void
append_param_list (long plist_i, long newparam)
{
  struct param_list *ptr;
  struct param *plist;
  if (newparam > 30000)
    {
      char *ptr = 0;
      printf ("Sanity check failed (%ld)\n", newparam);
      *ptr = 0;
    }
  plist = &PARAM_ID (this_module_ptr, plist_i);

  if (plist->param_type != PARAM_TYPE_LIST)
    {
      printf ("appending to a non-list\n");
      exit (1);
    }

  if (plist->param_u.p_list == 0)
    {
      ptr = malloc_clr (sizeof (struct param_list));
      ptr->list_param_id.list_param_id_val = 0;
      ptr->list_param_id.list_param_id_len = 0;
      plist->param_u.p_list = ptr;
    }
  else
    {
      ptr = plist->param_u.p_list;
    }

  ptr->list_param_id.list_param_id_len++;
  ptr->list_param_id.list_param_id_val =
    realloc (ptr->list_param_id.list_param_id_val,
	     sizeof (long) * ptr->list_param_id.list_param_id_len);
  ptr->list_param_id.list_param_id_val[ptr->list_param_id.list_param_id_len -
				       1] = newparam;

}







int
check_for_duplicate_param (int n)
{
  int a;
  int b;
  int match;


  a = this_module_ptr->params.params_len - 1;
  if (this_module_ptr->params.params_len <= 1) return 0;
  // Here - we're going to check that the parameter that we've just added doesn't already exist
  match = -1;
  for (b = 0; b < this_module_ptr->params.params_len - 1; b++)
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
      //
      // pretend like it never happend - cos its already there..
      // 
      a = this_module_ptr->params.params_len--;
      return match;
    }
  return n;
}
