#if (defined(__CYGWIN__)) || defined(__MINGW32__)
	/* missing from rpcgen generated .h on CygWin: */
	#define bool_t int
	#define u_int unsigned int
#endif

#include "npcode.h"
#include "npcode_defs.h"


struct cmd_block *curr_block = 0;
struct npvariable *master_variable = 0;

int vid = 0;
int m_type;


#define MAXSTACK 100




static struct define_variables *add_default_struct_list (struct
							 define_variables *v,
							 struct
							 variable_element
							 *dv);
static struct variable_element *make_default_struct_element (char *dtype,
							     int arrsize,
							     char *name);




static void end_define_gen (struct cmd_block *block);

struct cmd_block *vstack[MAXSTACK];	// 10 levels for blocks should be enough
int vstack_pc[MAXSTACK];
int vstack_cnt = 0;


struct s_named_structs
{
  char *name;
  struct define_variables *v;
};

struct s_named_structs *named_structs;
int named_structs_cnt = 0;


//int variable_id = 1;
extern module this_module;



//struct variable module_level;



//init_variables ()
//{
  //module_level.next.next_len = 0;
  //module_level.next.next_val = 0;
//}


int
get_dtype (char *s)
{
  if (strcasecmp (s, "char") == 0)
    return DCHAR;
  if (strcasecmp (s, "String") == 0)
    return DSTRING;
  if (strcasecmp (s, "int") == 0)
    return DLONG;
  if (strcasecmp (s, "short") == 0)
    return DINT;
  if (strcasecmp (s, "fgldate") == 0)
    return DLONG;
  if (strcasecmp (s, "long") == 0)
    return DLONG;
  if (strcasecmp (s, "VoidPointer") == 0)
    return DPTR;
  if (strcasecmp (s, "Void") == 0)
    {
      return DVOID;
    }

  if (strcasecmp (s, "fgldecimal") == 0)
    {
      return DDEC;
    }
  if (strcasecmp (s, "fglmoney") == 0)
    {
      return DMON;
    }

  if (strcasecmp (s, "ShortPtr") == 0)
    {
      return DSHORTPTR;
    }

  if (strcasecmp (s, "LongPtr") == 0)
    {
      return DLONGPTR;
    }

  printf ("UNKNOWN DATATYPE : %s\n", s);
  exit (1);
  return DUNKNOWN;
}


void
set_master_type (int type)
{
  //printf("Setting category to %d",type);
  master_variable->category = type;
}

void
set_master_set (long e_i)
{
//struct param *set;

  struct use_variable *uv;
  uv = malloc (sizeof (struct use_variable));
  uv->variable_id = master_variable->variable_id;
  uv->defined_in_block_pc = vstack_pc[vstack_cnt - 1];

  uv->indirection = 0;
  uv->sub.sub_len = 0;
  uv->sub.sub_val = 0;

  if (m_type == 1)
    {
      add_set_var (uv, e_i, 1);
    }
  else
    {
      add_set_var (uv, e_i, 0);
    }
}

void
add_variable (int type, struct variable_element *e, char *id, long set_i) // @todo - set_i - is it used ?
{

  struct npvariable *v;
  struct cmd_block *base;

  v = malloc (sizeof (struct npvariable));
  A4GL_debug ("Add variable .. %s type=%d \n", id, type);

  master_variable = v;
  master_variable->variable_id = vid++;
  master_variable->category = type;

  master_variable->var = e;
  e->name_id = add_id (id);

  if (in_function ())
    {
      //printf ("In function..\n");
      // Add it to the current function..
      base = vstack[vstack_cnt - 1];

      master_variable->def_block = vstack_pc[vstack_cnt - 1];
    }
  else
    {
      A4GL_debug ("Not in function\n");
      master_variable->def_block = -1;
      base = vstack[0];
      //&this_module.module_variables;
    }

  base->c_vars.c_vars_len++;
  base->c_vars.c_vars_val =
    realloc (base->c_vars.c_vars_val,
	     base->c_vars.c_vars_len * sizeof (struct npvariable));
  base->mem_to_alloc += v->var->total_size;

  //master_variable->variable_id = base->c_vars.c_vars_len - 1;

  memcpy (&base->c_vars.c_vars_val[base->c_vars.c_vars_len - 1],
	  master_variable, sizeof (struct npvariable));

  master_variable = &base->c_vars.c_vars_val[base->c_vars.c_vars_len - 1];
  // Add it to the module level variables...


}





void
add_variable_array (int type, struct variable_element *e, char *id, long *arrsize, long set)
{
int as;
  if (arrsize)
    {
        e->i_arr_size[0] = arrsize[0];
        e->i_arr_size[1] = arrsize[1];
        e->i_arr_size[2] = arrsize[2];
	if (arrsize[0]) as=arrsize[0]; else as=1;
	if (arrsize[1]) as*=arrsize[1]; 
	if (arrsize[2]) as*=arrsize[2]; 
	//printf("Arr dim : %d\n",as);
	//printf("%ld %d\n",e->total_size,e->unit_size);
	if (e->unit_size==0) {
		e->unit_size=e->total_size;
		e->total_size*=as;
		e->as=as;
	}
	//printf("   -> %ld %d\n",e->total_size,e->unit_size);
    }
  else
    {
      e->i_arr_size[0] = 0;
      e->i_arr_size[1] = 0;
      e->i_arr_size[2] = 0;
    }
  add_variable (type, e, id, set);

}



long
do_end_block (void)
{

  vstack_cnt--;
  //printf("ENDING BLOCK : vstack= %d\n",vstack_cnt);
  return vstack_pc[vstack_cnt];
}



void
add_block_var (struct cmd_block *ptr, int pc)
{
  //printf ("*** add_block_var : %p %d\n", ptr, vstack_cnt);

  vstack[vstack_cnt] = ptr;
  vstack_pc[vstack_cnt] = pc;

  vstack_cnt++;
  if (vstack_cnt > MAXSTACK)
    {
      printf ("Too deep...\n");
      exit (10);
    }
}





void
set_pc_vstack_curr (void)
{
  set_pc_vstack (current_pc ());
}


void
set_pc_vstack (int pc)
{
  vstack_pc[vstack_cnt - 1] = pc;
}






int
find_variable (int sid, char *s, short *block_no)
{
  int a;
  int b;
  struct cmd_block *c;
  //static struct variable *var;

  A4GL_debug ("Looking for %s starting @ %d", s, sid);
  if (sid == -1)
    {
      for (a = vstack_cnt - 1; a >= 0; a--)
	{
	  c = vstack[a];
	  for (b = 0; b < c->c_vars.c_vars_len; b++)
	    {
	      if (strcmp (s, GET_ID (c->c_vars.c_vars_val[b].var->name_id)) ==
		  0)
		{
		  A4GL_debug ("Found in block ... %x (%d) %s\n",
			      c->c_vars.c_vars_val[b].variable_id, a,
			      GET_ID (c->c_vars.c_vars_val[b].var->name_id));

		  if (a != 0)
		    *block_no = vstack_pc[a];
		  else
		    *block_no = -1;

		  return c->c_vars.c_vars_val[b].variable_id;
		}
	    }
	}




      // Not there - check module variables...
/*
      for (b = 0; b < this_module.module_variables.c_vars.c_vars_len; b++)
	{

	  //printf ("   -> %s %d\n", s, this_module.module_variables.c_vars.c_vars_val[b].var);
	  if (strcmp
	      (s,
	       GET_ID (this_module.module_variables.c_vars.c_vars_val[b].var-> name_id)) == 0)
	    {
	      *block_no = -1;
	      return this_module.module_variables.c_vars.c_vars_val[b].
		variable_id;
	    }
	}
*/
      // Not found at all...
      printf ("Couldn't find variable : %s\n", s);
      exit (1);
      return 0;
    }


  printf ("SID != -1\n");
  exit (1);


  return 0;
}



struct use_variable *
mk_use_variable (long p_i, long arr_i1,long arr_i2, long arr_i3, char *id, char indirection)
{
  struct use_variable *u;
  struct use_variable_sub *sub = 0;


  u = malloc (sizeof (struct use_variable));
  A4GL_debug ("Use variable... %d\n", p_i);

  u->indirection = indirection;
  u->sub.sub_len=0;
  u->sub.sub_val=0;

  if (p_i == 0)
    {
      u->variable_id = find_variable (-1, id, &u->defined_in_block_pc);

      if (u->variable_id != -1)
	{
	  A4GL_debug ("Variable : %x\n", u->variable_id);
	}
      else
	{
	  printf ("Unable to find variable %s\n", id);
	  exit (13);
	}
      u->sub.sub_len = 0;
      u->sub.sub_val = 0;
      if (arr_i1)
	{
	  sub = malloc (sizeof (struct use_variable_sub));
	  sub->x1element = -1;
	  sub->x1subscript_param_id[0] = arr_i1;
	  sub->x1subscript_param_id[1] = arr_i2;
	  sub->x1subscript_param_id[2] = arr_i3;
	  u->sub.sub_len++;
	  u->sub.sub_val = realloc (u->sub.sub_val, sizeof (struct use_variable_sub) * u->sub.sub_len);
	  memcpy (&u->sub.sub_val[u->sub.sub_len - 1], sub, sizeof (struct use_variable_sub));
	  printf("mk_use_variable arr : %d %d %d\n",arr_i1,arr_i2,arr_i3);
	}

    }
  else
    {
      u = get_use_variable(p_i);
    }






  if (p_i)
    {
      struct use_variable *parent = 0;
      struct variable_element *v;
      int sub_cnt;
      struct cmd_block *base;
      int a;
      int next_element;
      struct cmd *command;
      struct param *p;
	if (p_i!=-1) {
		p=&PARAM_ID(p_i);
	} else {
		p=nget_param(0);
	}

//
// Find out at which level our variable is
// Its either a module variable or defined in a block in the current function
//

      if (p->param_u.uv->defined_in_block_pc == -1)
	{			// Its module level
	 //printf("Module level variable\n");
	  command = &this_module.functions.functions_val[0].cmds.cmds_val[0];
	}
      else
	{

	  //printf("Local variable in block @ PC=%d\n",p->param_u.uv->defined_in_block_pc);
	  command =
	    &this_module.functions.functions_val[this_module.functions.
						 functions_len -
						 1].cmds.cmds_val[p->param_u.
								  uv->
								  defined_in_block_pc];

	}
      if (command->cmd_type != CMD_BLOCK)
	{
	  printf ("I've got confused...\nIt happens...\n");
	  exit (1);
	}
      base = command->cmd_u.c_block;


/*
	    this_module.functions.functions_val[this_module.functions.
						functions_len -
						1].cmds.cmds_val[p->param_u.
								 uv->
								 defined_in_block_pc].
	    cmd_u.c_block;
*/


// We've now found our base - now find our variable
// We need to go down our subs to find the right element
// eg
//   struct {
//        int a;          <---  Element 0
//        struct {
//            int b;      <---- Element 1,0
//        }
//   }
//
      parent = p->param_u.uv;
//printf(" ID :  %s\n",id);
	{
		int a;
		int found=-1;
     		for (a=0;a<base->c_vars.c_vars_len;a++) {
      			if (base->c_vars.c_vars_val[a].variable_id==p->param_u.uv->variable_id) {
				found=a; 
	 		}
		}
     if (found==-1) {
		printf("Messed up somewhere\n");
		exit(32);
	}
      v = base->c_vars.c_vars_val[found].var; // <------
	}

      for (sub_cnt = 0; sub_cnt < parent->sub.sub_len; sub_cnt++)
	{
	  if (parent->sub.sub_val[sub_cnt].x1element != -1)
	    {
	      if (parent->sub.sub_val[sub_cnt].x1element >= v->next.next_len)
		{
		  printf ("Corrupt sub...\n");
		  exit (2);
		}
	      v = &v->next.next_val[parent->sub.sub_val[sub_cnt].x1element];
	    }
	}

      A4GL_debug ("Found our parent : %p\n", v);

      next_element = -1;
      for (a = 0; a < v->next.next_len; a++)
	{
	  if (strcmp (id, GET_ID (v->next.next_val[a].name_id)) == 0)
	    {
	      // We've found it
	      A4GL_debug ("Its the %d element..\n", a);
	      next_element = a;
	      break;
	    }
	}

      parent = p->param_u.uv;
      parent->sub.sub_len++;
      parent->sub.sub_val =
	realloc (parent->sub.sub_val,
		 sizeof (struct use_variable_sub) * parent->sub.sub_len);
      sub = malloc (sizeof (struct use_variable_sub));


      sub->x1element = next_element;
      sub->x1subscript_param_id[0] = 0;
      sub->x1subscript_param_id[1] = 0;
      sub->x1subscript_param_id[2] = 0;


      if (arr_i1)
	{
	  sub->x1subscript_param_id[0] = arr_i1;
	  sub->x1subscript_param_id[1] = arr_i2;
	  sub->x1subscript_param_id[2] = arr_i3;
	}
      printf("Mk2 : %d %d %d\n",arr_i1,arr_i2,arr_i3);
      memcpy (&parent->sub.sub_val[u->sub.sub_len - 1], sub,
	      sizeof (struct use_variable_sub));
      return parent;
    }

  return u;

  A4GL_debug ("Made use_variable %p\n", u);
}




/*
struct variable_element *
param_variable (char *dtype, char *name, struct param *size)
{
  struct variable_element *n;
  n = malloc (sizeof (struct variable_element));
  n->name_id = add_id (name);
  n->dtype = get_dtype (dtype);
  n->arr_size = size;
  n->alloc_size = 0;
  n->offset = 0;
  n->next.next_len = 0;
  n->next.next_val = 0;
  return n;
}


struct variable_element *
append_param_variable (struct variable_element *orig,
		       struct variable_element *next)
{
  orig->next.next_len++;
  orig->next.next_val =
    realloc (orig->next.next_val,
	     sizeof (struct variable_element) * orig->next.next_len);
  memcpy (&orig->next.next_val[orig->next.next_len - 1], next,
	  sizeof (struct variable_element));
  return orig;
}

*/



struct define_variables *
add_named_struct (char *s)
{
  int a;
  for (a = 0; a < named_structs_cnt; a++)
    {
      //printf("Checking %d %s %s\n",a,named_structs[a].name,s);
      if (strcmp (named_structs[a].name, s) == 0)
	{
	  // Found our structure...
	  return named_structs[a].v;
	}
    }
  printf ("Structure %s not found or defined\n", s);
  exit (1);
}


struct variable_element *
new_variable_element_string (char *s)
{
  struct variable_element *n;
  n = malloc (sizeof (struct variable_element));
  n->name_id = -1;
  n->dtype = get_dtype (s);
  n->unit_size = 0;
  n->total_size = 0;

  switch (n->dtype)
    {
    case DCHAR:
      n->unit_size = 1;
      break;
    case DINT:
      n->unit_size = 2;
      break;
    case DLONG:
      n->unit_size = 4;
      break;

    case DDEC:
      n->unit_size += 64;
      break;			// @ FIXME
    case DMON:
      n->unit_size += 64;
      break;			// @ FIXME

    default:
      n->unit_size = 4;
      break;
    }
  n->i_arr_size[0] = 0;
  n->i_arr_size[1] = 0;
  n->i_arr_size[2] = 0;
  n->offset = 0;
  n->next.next_len = 0;
  n->next.next_val = 0;

  return n;
}

struct variable_element *
new_variable_struct (struct define_variables *v)
{
  struct variable_element *n;
  int a;
  int s = 0;
  n = malloc (sizeof (struct variable_element));
  n->name_id = -1;
  n->dtype = DSTRUCT;
  n->i_arr_size[0] = 0;
  n->i_arr_size[1] = 0;
  n->i_arr_size[2] = 0;
  n->unit_size = 0;
  n->total_size = 0;
  n->offset = 0;
  A4GL_debug ("new_variable_struct : %d %p\n", v->var_len, v);
  n->next.next_len = v->var_len;
  if (v->var_len)
    {
      n->next.next_val =
	malloc (sizeof (struct variable_element) * n->next.next_len);
      for (a = 0; a < v->var_len; a++)
	{
	  int arr;
	  v->var_val[a].offset = s;
	  if (v->var_val[a].i_arr_size[0] == 0)
	    arr = 1;
	  else
	    {
	      arr = v->var_val[a].i_arr_size[0];
	    }
	  if (v->var_val[a].i_arr_size[1] != 0)
	    arr *= v->var_val[a].i_arr_size[1];
	  if (v->var_val[a].i_arr_size[2] != 0)
	    arr *= v->var_val[a].i_arr_size[2];

	  s += v->var_val[a].unit_size * arr;
	  memcpy (&n->next.next_val[a], &v->var_val[a],
		  sizeof (struct variable_element));
	}
    }
  else
    {
      n->next.next_val = 0;
    }
//printf("Setting total_size to %d\n",s);
  n->total_size = s;
  return n;
}



static void
make_named_struct (char *name, struct define_variables *v)
{
  named_structs_cnt++;
  named_structs =
    realloc (named_structs,
	     sizeof (struct define_variables) * named_structs_cnt);
  named_structs[named_structs_cnt - 1].name = strdup (name);
  named_structs[named_structs_cnt - 1].v = v;

}


void
add_default_named_structs ()
{
  struct define_variables *v;

/* Struct BINDING */
  v = add_default_struct_list (0, make_default_struct_element ("VoidPointer", 0, "ptr"));
  add_default_struct_list (v, make_default_struct_element ("LONG", 0, "dtype"));
  add_default_struct_list (v, make_default_struct_element ("LONG", 0, "size"));
  add_default_struct_list (v, make_default_struct_element ("LONG", 0, "start_char_subscript"));
  add_default_struct_list (v, make_default_struct_element ("LONG", 0, "end_char_subscript"));
  make_named_struct ("BINDING", v);

  v = add_default_struct_list (0, make_default_struct_element ("LONG", 0, "event_type"));
  add_default_struct_list (v, make_default_struct_element ("LONG", 0, "block"));
  add_default_struct_list (v, make_default_struct_element ("LONG", 0, "keycode"));
  add_default_struct_list (v, make_default_struct_element ("VoidPointer", 0, "field"));
  make_named_struct ("aclfgl_event_list", v);


/* All Done... */
}


static struct variable_element *
make_default_struct_element (char *dtype, int arrsize, char *name)	// @FIXME - Allow multiple arrsize
{
  struct variable_element *dv;
  dv = new_variable_element_string (dtype);
  dv->name_id = add_id (name);
  if (arrsize)
    {
      dv->i_arr_size[0] = arrsize;
      dv->i_arr_size[1] = 0;
      dv->i_arr_size[2] = 0;
    }
  return dv;
}



static struct define_variables *
add_default_struct_list (struct define_variables *v,
			 struct variable_element *dv)
{
//printf("dv:%p\n",dv);
//printf("Name ID : %ld\n",dv->name_id);
//printf("dtype   : %d\n",dv->dtype);
//printf("arr_size : %p\n",dv->arr_size);
//printf("alloc_size : %ld\n",dv->alloc_size);
//printf("offset : %ld\n",dv->offset);
//printf("next len: %d\n",dv->next.next_len);
//printf("\n\n\n");


  if (v == 0)
    {
      v = malloc (sizeof (struct define_variables));
      v->var_len = 1;
      v->var_val = malloc (sizeof (struct variable_element));
    }
  else
    {
      v->var_len++;
      v->var_val =
	realloc (v->var_val, sizeof (struct variable_element) * v->var_len);
    }
  memcpy (&v->var_val[v->var_len - 1], dv, sizeof (struct variable_element));
  return v;
}



void
end_define (void)
{
  struct cmd_block *block;
  block = vstack[vstack_cnt - 1];
  end_define_gen (block);
}

void
end_define_module (void)
{
  struct cmd_block *block;
  block = vstack[0];
  end_define_gen (block);
}


void
end_define_gen (struct cmd_block *block)
{
  int a;
  int size = 0;
// We must be in a block..
//printf("end_define_gen\n");
//printf("This block has %d elements %d bytes\n",block->c_vars.c_vars_len,block->mem_to_alloc);


  for (a = 0; a < block->c_vars.c_vars_len; a++)
    {
      A4GL_debug ("Catagory = %d\n", block->c_vars.c_vars_val[a].category);
      //printf("Rendering %d - %s current : %d\n",a,GET_ID(block->c_vars.c_vars_val[a].var->name_id),block->c_vars.c_vars_val[a].var->total_size);
      if (block->c_vars.c_vars_val[a].var->total_size == 0)
	{
	  if (block->c_vars.c_vars_val[a].var->i_arr_size[0] == 0)
	    {
	      block->c_vars.c_vars_val[a].var->total_size =
		block->c_vars.c_vars_val[a].var->unit_size;
	    }
	  else
	    {
	      int arr;
	      arr = block->c_vars.c_vars_val[a].var->i_arr_size[0];
	      if (block->c_vars.c_vars_val[a].var->i_arr_size[1])
		arr *= block->c_vars.c_vars_val[a].var->i_arr_size[1];
	      if (block->c_vars.c_vars_val[a].var->i_arr_size[2])
		arr *= block->c_vars.c_vars_val[a].var->i_arr_size[2];
	      block->c_vars.c_vars_val[a].var->total_size =
		(block->c_vars.c_vars_val[a].var->unit_size) * arr;
	    }
	}
      if (block->c_vars.c_vars_val[a].category == CAT_NORMAL
	  || block->c_vars.c_vars_val[a].category == CAT_PARAMETER)
	{
	  block->c_vars.c_vars_val[a].var->offset = size;
	  size += block->c_vars.c_vars_val[a].var->total_size;
	}



    }
  block->mem_to_alloc = size;
  A4GL_debug ("Non-static/externs take up %d bytes...\n", size);
}





void
set_type (int a)
{
  m_type = a;
}

void
move_define (struct cmd_block *from, struct cmd_block *to)
{
  int a;
  if (from->c_vars.c_vars_len == 0)
    return;			/* Nothing to copy */

  for (a = 0; a < from->c_vars.c_vars_len; a++)
    {
      to->c_vars.c_vars_len++;
      to->c_vars.c_vars_val =
	realloc (to->c_vars.c_vars_val,
		 (to->c_vars.c_vars_len) * sizeof (struct npvariable));

//printf("Copying variable id : %d\n",from->c_vars.c_vars_val[a].variable_id);


      to->c_vars.c_vars_val[to->c_vars.c_vars_len - 1].variable_id =
	from->c_vars.c_vars_val[a].variable_id;
      to->c_vars.c_vars_val[to->c_vars.c_vars_len - 1].def_block =
	from->c_vars.c_vars_val[a].def_block;
      to->c_vars.c_vars_val[to->c_vars.c_vars_len - 1].category =
	from->c_vars.c_vars_val[a].category;
//to->c_vars.c_vars_val[to->c_vars.c_vars_len-1].alloc_size=from->c_vars.c_vars_val[a].alloc_size;
//to->c_vars.c_vars_val[to->c_vars.c_vars_len-1].offset=from->c_vars.c_vars_val[a].offset;
      to->c_vars.c_vars_val[to->c_vars.c_vars_len - 1].var =
	from->c_vars.c_vars_val[a].var;

    }
  from->c_vars.c_vars_len = 0;
//free(from->c_vars.c_vars_val);
  from->c_vars.c_vars_val = 0;
end_define_gen (to);

}

/* 
Convert all internal blocks to 'void' blocks..
ie blocks with no variables attached to them
*/
void
move_defines ()
{
  int a;
  int b;
  int nop = 0;
  struct npfunction *func;

  for (a = 0; a < this_module.functions.functions_len; a++)
    {
      func = &this_module.functions.functions_val[a];
      // 0 will always be the functions block...
      if (func->cmds.cmds_val[0].cmd_type != CMD_BLOCK)
	{
	  printf ("Confused - expecting first command to be a block");
	}

      for (b = 1; b < func->cmds.cmds_len; b++)
	{
	  if (func->cmds.cmds_val[b].cmd_type == CMD_BLOCK)
	    {

	      move_define (func->cmds.cmds_val[b].cmd_u.c_block,
			   func->cmds.cmds_val[0].cmd_u.c_block);
	      func->cmds.cmds_val[b].cmd_type = CMD_NOP;
	      nop++;
	    }

	  if (func->cmds.cmds_val[b].cmd_type == CMD_END_BLOCK)
	    {
	      if (func->cmds.cmds_val[b].cmd_u.c_endblock->pc_start_block !=
		  0)
		{
		  func->cmds.cmds_val[b].cmd_type = CMD_NOP;
		  nop++;
		}
	    }
	}
    }
  printf ("Generated %d NOPs\n", nop);
}
