#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "npcode.h"
#include "npcode_defs.h"

extern module this_module;

void *
malloc_clr (long size)
{
  void *ptr;

  ptr = malloc (size);
  memset (ptr, 0, size);
  return ptr;
}


void
add_cache_param (struct param *p)
{
  int a;
  // If there is anything <= sizeof(long) don't
  // bother caching it - as its not going to save us anything...


return ;


if (p->param_type==PARAM_TYPE_USE_VAR) return;
/*
  switch (p->param_type)
    {
    case PARAM_TYPE_LITERAL_INT:
    case PARAM_TYPE_LITERAL_CHAR:
    case PARAM_TYPE_LITERAL_STRING:
    case PARAM_TYPE_VAR_ID:
    case PARAM_TYPE_EMPTY:
    case PARAM_TYPE_CACHED:
      return;
    }
*/

  for (a = 0; a < this_module.params.params_len; a++)
    {
      printf ("Compare : types (%x %x)",
	      this_module.params.params_val[a].param_type, p->param_type);
      printf ("          data (%lx %lx) \n",
	      this_module.params.params_val[a].param_u.n, p->param_u.n);

      if (p->param_type!=this_module.params.params_val[a].param_type) {
		continue;
      }

      if (memcmp (&this_module.params.params_val[a], p, sizeof (struct param)) == 0)
	{
	  p->param_type = PARAM_TYPE_CACHED;
	  p->param_u.param_cache_id = a;
	  printf ("Param Cache Hit (0) ...\n");
	  return;
	}

	// It doesn't match exactly - but it might still match...
	
	if (p->param_type==PARAM_TYPE_LIST) {
		int z;
		int bad=0;
		if (p->param_u.p_list->list.list_len!=this_module.params.params_val[a].param_u.p_list->list.list_len) continue;
		else {
			for (z=0;z<p->param_u.p_list->list.list_len;z++) {
				if (memcmp(&p->param_u.p_list->list.list_val[a],&this_module.params.params_val[a].param_u.p_list->list.list_val[z],sizeof(struct param))) {
					bad=1;
					break;
				}
			}
		}
		if (bad==1) continue; // Cache hit...

	  	p->param_type = PARAM_TYPE_CACHED;
	  	p->param_u.param_cache_id = a;
	  	printf ("Param Cache Hit (1) ...\n");

		return ; // Cache hit..
	}

	if(p->param_type==PARAM_TYPE_OP) {
		if (memcmp(p->param_u.op->left,this_module.params.params_val[a].param_u.op->left,sizeof(struct param))) continue;
		if (memcmp(p->param_u.op->right,this_module.params.params_val[a].param_u.op->right,sizeof(struct param))) continue;
		if (p->param_u.op->op_i!=this_module.params.params_val[a].param_u.op->op_i) continue;

	  	p->param_type = PARAM_TYPE_CACHED;
	  	p->param_u.param_cache_id = a;
	  	printf ("Param Cache Hit (2)...\n");
		return;
	}

	if(p->param_type==PARAM_TYPE_USE_VAR) {
		int z;
		int bad=0;
		if (p->param_u.uv->variable_id!=this_module.params.params_val[a].param_u.uv->variable_id) continue;
		if (p->param_u.uv->defined_in_block_pc!=this_module.params.params_val[a].param_u.uv->defined_in_block_pc) continue;
		if (p->param_u.uv->indirection!=this_module.params.params_val[a].param_u.uv->indirection) continue;
		if (p->param_u.uv->sub.sub_len!=this_module.params.params_val[a].param_u.uv->sub.sub_len) continue;

		for (z=0;z<p->param_u.uv->sub.sub_len;z++) {
			if (p->param_u.uv->sub.sub_val[z].element!=this_module.params.params_val[a].param_u.uv->sub.sub_val[z].element) {bad=1;break;}
			if (memcmp(p->param_u.uv->sub.sub_val[z].subscript,this_module.params.params_val[a].param_u.uv->sub.sub_val[z].subscript,sizeof(struct param))) {bad=1;break;}
		}
		if (bad) continue;


	  	p->param_type = PARAM_TYPE_CACHED;
	  	p->param_u.param_cache_id = a;
	  	printf ("Param Cache Hit (3)...\n");
		return;
	}


    }
  // Cache miss...

  printf ("\nCache miss %d %p (%d) type %d\n", this_module.params.params_len,
	  this_module.params.params_val, sizeof (struct param),p->param_type);
  this_module.params.params_len++;
  this_module.params.params_val =
    realloc (this_module.params.params_val,
	     this_module.params.params_len * sizeof (struct param));
  memcpy (&this_module.params.params_val[this_module.params.params_len - 1],
	  p, sizeof (struct param));


}

char *
strdup_with_conv (char *s)
{
  char *buff;
  int a;
  int b = 0;
  buff = strdup (s);
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


nstr=strdup_with_conv (s);

  for (a = 0; a < this_module.string_table.string_table_len; a++)
    {
      if (strcmp (nstr, this_module.string_table.string_table_val[a].s) == 0)
	{
	free(nstr);
	  this_module.string_table.string_table_val[a].rcnt++;
	  return a;
	}
    }

  this_module.string_table.string_table_len++;
  nsize = sizeof (struct vstring) * this_module.string_table.string_table_len;



  this_module.string_table.string_table_val =
    realloc (this_module.string_table.string_table_val, nsize);



  this_module.string_table.string_table_val[this_module.string_table.  string_table_len - 1].s = nstr;
  this_module.string_table.string_table_val[this_module.string_table.  string_table_len - 1].rcnt=1;
  return this_module.string_table.string_table_len - 1;
}


char *
get_string (int a)
{
  return this_module.string_table.string_table_val[a].s;
}

struct param *
new_param (char s, void *ptr)
{
  struct param *p;

  p = malloc_clr (sizeof (struct param));

  switch (s)
    {
    case 's':
      p->param_type = PARAM_TYPE_LITERAL_STRING;
      p->param_u.str_entry = (long) add_string ((char *) ptr);
      break;

    case 'v':
      p->param_type = PARAM_TYPE_VAR;
      p->param_u.v = strdup (ptr);
      break;

    case 'V':
      p->param_type = PARAM_TYPE_USE_VAR;
      p->param_u.uv = (struct use_variable *) ptr;
      break;

    case 'S':
      p->param_type = PARAM_TYPE_SPECIAL;
      p->param_u.special= (char *) ptr;
      break;

    case 'K':
      p->param_type = PARAM_TYPE_ONKEY;
      p->param_u.keys= (char *) ptr;
      break;


    default:
      printf ("Unknown type : %c\n", s);
      exit (12);
      break;
    }

  add_cache_param (p);

  return p;

}



struct param *
append_param_list (struct param *plist, struct param *newparam)
{
  struct param_list *ptr;
  if (plist->param_type != PARAM_TYPE_LIST)
    {
      printf ("appending to a non-list\n");
      exit (1);
    }
  if (plist->param_u.p_list == 0)
    {
      ptr = malloc_clr (sizeof (struct param_list));
      ptr->list.list_val = 0;
      ptr->list.list_len = 0;
      plist->param_u.p_list = ptr;
    }
  else
    {
      ptr = plist->param_u.p_list;
    }

  ptr->list.list_len++;
  ptr->list.list_val =
    realloc (ptr->list.list_val, sizeof (struct param) * ptr->list.list_len);
  memcpy (&ptr->list.list_val[ptr->list.list_len - 1], newparam,
	  sizeof (struct param));

  add_cache_param (plist);
  return plist;

}

struct param *
new_param_list (struct param *p)
{
  struct param *pnew;
  pnew = malloc_clr (sizeof (struct param));
  pnew->param_type = PARAM_TYPE_LIST;

  pnew->param_u.p_list = 0;
  pnew = append_param_list (pnew, p);

  add_cache_param (pnew);
  return pnew;
}


struct param *
new_param_fcall (char *fname, struct param *plist)
{
  struct param *pnew;
  struct cmd_call *pcall;
  pnew = malloc_clr (sizeof (struct param));
  pcall = malloc_clr (sizeof (struct cmd_call));
  pnew->param_type = PARAM_TYPE_CALL;
  pnew->param_u.c_call = pcall;
  pcall->func_id = add_id (fname);
  pcall->params = plist;
  if (plist && (long) plist < 100)
    {
      printf ("CORRUPT 3\n");
    }

  add_cache_param (pnew);
  return pnew;
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

struct param *
new_param_op (struct param *l, char *op, struct param *r)
{
  struct param *pnew;
  struct param_op *pop;
  pnew = malloc_clr (sizeof (struct param));
  pnew->param_type = PARAM_TYPE_OP;
  pop = malloc_clr (sizeof (struct param_op));
	add_cache_param(l);
	add_cache_param(r);
  pop->left = l;
  pop->right = r;
  pop->op_i = decode_op (op);
  pnew->param_u.op = pop;
  add_cache_param (pnew);
  return pnew;
}
