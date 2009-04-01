/* 
 * This module is used for the compiler but is also used to provide extra functions 
 * to the libLEX generation code
 *
 * That code generation can be done 'statically' - so be careful about external calls
 *
 * DO NOT ASSUME ANYTHING ABOUT THE PARSED FILE 
 * DO NOT USE ANY EXTERNs
 * 
 * If you need access to any external data - pass in a reference to it (normally via a module_definition pointer)
 *
*/

#include "a4gl_4glc_int.h"
#include "a4gl_expr.h"
#include "a4gl_API_parse_lib.h"
#include "parsehelp.h"
#include "var_handling.h"
//#include "trim_spaces.h"

char namespace[256] = "aclfgl_";

static void append_record_entries(struct record_variable *rec_var, struct variable_usage *parent, struct expr_str_list *rval) ;
static int encode_size(int dtype, int dim1,int dim2) ;
int A4GL_module_has_function(struct module_definition *module, char *s,char *file,struct flist *ptr); // used in lib/liblex/lex_esqlc/compile_c.c

static int compare_var (struct variable **vv1, struct variable **vv2) {
struct variable *v1;
struct variable *v2;
v1=*vv1;
v2=*vv2;
A4GL_assertion ((v1==0 || v2==0), "Invalid pointer");
return strcmp(v1->names.names.names_val[0].name,v2->names.names.names_val[0].name);
}

void sort_variables(void *ptr, int n) {
	if (n==0) return;
	if (ptr) {
        	qsort(ptr,  n, sizeof( void*), (void *)compare_var);
	}
}


struct variable *find_variable_quick(char *name, struct variable **list, int cnt) {
        struct variable *v;
        struct variable vsearch;
        struct vname names;
	struct variable **vs;
        names.name=name;
        vsearch.names.names.names_val=&names;
        vsearch.names.names.names_len=1;
	v=&vsearch;
	vs=&v;
        vs=bsearch((void*)vs, list, cnt, sizeof(void *), (void *)compare_var);
	if (vs) {
		return *vs;
	} else {
		return 0;
	}
	return 0;
}

 int
has_variable_name (struct vname_name_list *namelist, char *name)
{
  int c;
  if (name == 0)
    return 0;
//printf("has_name : %s namelist : %p %d\n",name,namelist, namelist->names.names_len);

  for (c = 0; c < namelist->names.names_len; c++)
    {
      if (A4GL_aubit_strcasecmp (namelist->names.names_val[c].name, name) == 0)
      //if (strcmp (namelist->names.names_val[c].name, name) == 0)
        return 1;
    }
  return 0;
}



int
attributes_as_int (struct attrib *a)
{
int attr=0;
  if (a==0) return -1;
  if (a->color!=-1) {
  	attr=a->color;
  }
  if (a->normal==EB_TRUE)
    attr += AUBIT_ATTR_NORMAL;
  if (a->reverse==EB_TRUE)
    attr += AUBIT_ATTR_REVERSE;
  if (a->underline==EB_TRUE )
    attr += AUBIT_ATTR_UNDERLINE;
  if (a->bold==EB_TRUE)
    attr += AUBIT_ATTR_BOLD;
  if (a->blink==EB_TRUE)
    attr += AUBIT_ATTR_BLINK;
  if (a->dim==EB_TRUE)
    attr += AUBIT_ATTR_DIM;
  if (a->invisible==EB_TRUE)
    attr += AUBIT_ATTR_INVISIBLE;

  return attr;
}


struct variable_usage *clone_variable_usage(struct variable_usage *vu) {
struct variable_usage *new_usage;
        new_usage=malloc(sizeof(struct variable_usage));
        memcpy(new_usage,vu,sizeof(struct variable_usage));
        new_usage->next=0;
        if (vu->next) {
                new_usage->next=clone_variable_usage(vu->next);
        }
        return new_usage;
}

       
/**
 *  *
 *   * @param s
 *    */
int
is_builtin_func (char *s)
{
  int a;
  extern char *builtin_aclfgl_functions[];

  for (a = 0; builtin_aclfgl_functions[a]; a++)
    {
      if (strcmp (s, builtin_aclfgl_functions[a]) == 0)
        return 1;
    }
  return 0;
}





expr_str_list *
expand_parameters (struct variable_list *var_list, expr_str_list * parameters)
{
  struct expr_str_list *rval;
  char errbuff[256];
  int a;
  struct variable_usage *u;

  rval = malloc (sizeof (expr_str_list));
  rval->list.list_len = 0;
  rval->list.list_val = 0;

  if (!check_parameters (errbuff, var_list, parameters))
    {
      A4GL_assertion (1, "Invalid parameter list");
      return 0;
    }


  if (parameters == 0)
    return parameters;

  for (a = 0; a < parameters->list.list_len; a++)
    {
      int b;
      int found = 0;
      for (b = 0; b < var_list->variables.variables_len; b++)
	{
	  A4GL_assertion (var_list->variables.variables_val[b]->names.names.names_len > 1, "Unexpected number of names");
	  if (strcmp
	      (var_list->variables.variables_val[b]->names.names.names_val[0].name,
	       parameters->list.list_val[a]->expr_str_u.expr_param.expr_string) == 0)
	    {			// Found it


	      if (var_list->variables.variables_val[b]->arr_subscripts.arr_subscripts_len
		  && var_list->variables.variables_val[b]->arr_subscripts.arr_subscripts_val[0] == -1)
		{
		  // Dynamic array..
		  u = new_variable_usage (0, parameters->list.list_val[a]->expr_str_u.expr_param.expr_string, 0);
		  u->datatype = DTYPE_DYNAMIC_ARRAY;
		  u->escope = E_SCOPE_LOCAL;
		  A4GL_new_append_ptr_list (rval, A4GL_new_expr_push_variable (u,current_is_report()));
		  continue;
		}

	      if (parameters->list.list_val[a]->expr_str_u.expr_param.isReference)
		{
		  // We've found it - but its a byte copt so we dont care too much.
		  u = new_variable_usage (0, parameters->list.list_val[a]->expr_str_u.expr_param.expr_string, 0);
		  u->datatype = DTYPE_REFERENCE;
		  u->escope = E_SCOPE_LOCAL;	/* must be local - its a parameter... */
		  A4GL_new_append_ptr_list (rval, A4GL_new_expr_push_variable (u,current_is_report()));
		  found++;
		  break;
		}
	      else
		{

		  switch (var_list->variables.variables_val[b]->var_data.variable_type)
		    {

		    case VARIABLE_TYPE_SIMPLE:
		      u = new_variable_usage (0, parameters->list.list_val[a]->expr_str_u.expr_param.expr_string, 0);
		      A4GL_new_append_ptr_list (rval, A4GL_new_expr_push_variable (u,current_is_report()));
		      // Cant pass in an array...
		      //find_variable_vu_in (errbuff, u, var_list->variables.variables_val, var_list->variables.variables_len,1);
		      break;

		    case VARIABLE_TYPE_RECORD:
		      {
			struct record_variable *rec_var;
			rec_var = &var_list->variables.variables_val[b]->var_data.variable_data_u.v_record;
			u = new_variable_usage (0, parameters->list.list_val[a]->expr_str_u.expr_param.expr_string, 0);
			u->datatype = -2;
			u->datatype_length = 0;
			u->escope = E_SCOPE_LOCAL;	/* must be local - its a parameter... */
			append_record_entries (rec_var, u, rval);
		      }

		      break;
		    default:
		      A4GL_assertion (1, "Not handled");
		    }
		  found++;
		  break;
		}
	    }
	}
    }
  for (a = 0; a < rval->list.list_len; a++)
    {
	struct variable_usage *p;
	p=rval->list.list_val[a]->expr_str_u.expr_variable_usage;
       if (p->datatype!=DTYPE_REFERENCE) {
      		find_variable_vu_in (errbuff, rval->list.list_val[a]->expr_str_u.expr_variable_usage, var_list->variables.variables_val,
			   var_list->variables.variables_len, 1, 0);
	}
    }

  return rval;
}



int check_parameters(char *errbuff,struct variable_list *var_list, expr_str_list *parameters) {
int a;
int b;
if (parameters==0) return 1;

for (a=0;a<parameters->list.list_len;a++) {
	int found=0;
	if (parameters->list.list_val[a]->expr_type!=ET_EXPR_PARAMETER) {
		A4GL_assertion(1,"Unexpected expression type");
	}
	if (var_list==0) {
		strcpy(errbuff,"No variables have been defined");
		return 0;
	}

	for (b=0;b<var_list->variables.variables_len;b++) {
		A4GL_assertion(var_list->variables.variables_val[b]->names.names.names_len>1,"Unexpected number of names");
		if (strcmp(var_list->variables.variables_val[b]->names.names.names_val[0].name, parameters->list.list_val[a]->expr_str_u.expr_param.expr_string)==0) { // Found it
			found++;
			break;
		}
	}

	if (!found) {
		set_yytext(parameters->list.list_val[a]->expr_str_u.expr_param.expr_string);
	        strcpy(errbuff,"Variable has not been defined");
                return 0;
	}
}
return 1;
}




static void append_record_entries(struct record_variable *rec_var, struct variable_usage *parent, struct expr_str_list *rval) {
int c;
struct variable_usage *u;
struct variable_usage *unew;
struct variable_usage *p;
//struct record_variable *next_rec;
int dim=0;
int dim1;
int dim2;
int dim3;
int c1;
int c2;
int c3;
		for (c=0;c<rec_var->variables.variables_len;c++) {
			u=new_variable_usage(0,rec_var->variables.variables_val[c]->names.names.names_val[0].name,0);
			p=A4GL_memdup(parent,sizeof(struct variable_usage));
			p->next=0;
			append_variable_usage(p,u);

			dim=0;
			dim1=1;
			dim2=1;
			dim3=1;

			if (rec_var->variables.variables_val[c]->arr_subscripts.arr_subscripts_len>0) {
				if (rec_var->variables.variables_val[c]->arr_subscripts.arr_subscripts_val[0]>0) {
					dim=rec_var->variables.variables_val[c]->arr_subscripts.arr_subscripts_len;
				}
			} 


			if (dim) {
					if (dim==1) {
						dim1=rec_var->variables.variables_val[c]->arr_subscripts.arr_subscripts_val[0];
					}
					if (dim==2) {
						dim1=rec_var->variables.variables_val[c]->arr_subscripts.arr_subscripts_val[0];
						dim2=rec_var->variables.variables_val[c]->arr_subscripts.arr_subscripts_val[1];
					}
					if (dim==3) {
						dim1=rec_var->variables.variables_val[c]->arr_subscripts.arr_subscripts_val[0];
						dim2=rec_var->variables.variables_val[c]->arr_subscripts.arr_subscripts_val[1];
						dim3=rec_var->variables.variables_val[c]->arr_subscripts.arr_subscripts_val[2];
					}
			}


			for (c1=0;c1<dim1;c1++) {
			for (c2=0;c2<dim2;c2++) {
			for (c3=0;c3<dim3;c3++) {

				if (dim) {
					struct variable_usage *vu_bottom;
					unew=clone_variable_usage(p); vu_bottom=unew; while (vu_bottom->next) vu_bottom=vu_bottom->next;

                                        vu_bottom->subscripts.subscripts_val=malloc(sizeof(expr_str *)*dim);
                                        vu_bottom->subscripts.subscripts_len=dim;
                                          vu_bottom->subscripts.subscripts_val[0]=A4GL_new_literal_long_long(c1+1);
                                                        if (dim>1) vu_bottom->subscripts.subscripts_val[1]=A4GL_new_literal_long_long(c2+1);
                                                        if (dim>2) vu_bottom->subscripts.subscripts_val[2]=A4GL_new_literal_long_long(c3+1);

				} else {
					unew=p;
				}

				switch  (rec_var->variables.variables_val[c]->var_data.variable_type) {
					case VARIABLE_TYPE_SIMPLE: A4GL_new_append_ptr_list(rval, A4GL_new_expr_push_variable(unew,current_is_report())); break;
					case VARIABLE_TYPE_RECORD: append_record_entries(&rec_var->variables.variables_val[c]->var_data.variable_data_u.v_record,unew,rval); break;
					default: A4GL_assertion(1,"Not handled");
				}
			}
			}
		}
				
		}
}





struct variable_usage *
new_variable_usage (struct variable_usage *old, char *partname, char prepend)
{
  struct variable_usage *newv;
  //int a;
  newv = acl_malloc2 (sizeof (struct variable_usage));

  newv->variable_name = acl_strdup (partname);

  newv->subscripts.subscripts_len = 0;
  newv->subscripts.subscripts_val = 0;

  //for (a = 0; a < 10; a++)
    //{
      //newv->subscripts[a] = 0;
    //}

  //newv->nsubstrings = 0;
  newv->substrings_start = 0;
  newv->substrings_end   = 0;

  newv->variable_id = -1;
  newv->datatype = -1;
  newv->escope = E_SCOPE_NOTSET;
  newv->next = 0;


  if (old)
    {
      if (prepend)
	{
		//A4GL_debug("NEW VARIABLE USAGE RETURNING : %s\n", cmds_get_variable_usage_as_string(newv));
	  return newv;
	}
      else
	{
	 	struct variable_usage *n;	
		n=old;
		while (n->next) n=n->next;
	  	n->next = newv;
		//A4GL_debug("NEW VARIABLE USAGE RETURNING : %s\n", cmds_get_variable_usage_as_string(old));
	  return old;
	}
    }
  else
    {
		//A4GL_debug("NEW VARIABLE USAGE RETURNING : %s\n", cmds_get_variable_usage_as_string(newv));
      return newv;
    }
}


struct variable_usage *
append_variable_usage (struct variable_usage *old,
		       struct variable_usage *new_usg)
{
  struct variable_usage *orig;
  orig = old;
  while (old->next)
    old = old->next;
  old->next = new_usg;
		// A4GL_debug("APPEND VARIABLE USAGE RETURNING : %s\n", cmds_get_variable_usage_as_string(orig));
  return orig;
}




struct variable *find_variable_vu_in_p2(char *errbuff,struct variable *v, char *var_section,  struct variable_usage *vu,int a,int err_if_whole_array,int level) {


      /* If we get to here we've found our name! */
      /* Now we need to know what to do next.... */

      A4GL_debug ("v->var_data.variable_type=%d\n", v->var_data.variable_type);
      if (v->var_data.variable_type > 10 || v->var_data.variable_type < 0)
	{
	  A4GL_assertion (1, "Internal error");
	}

      if (v->var_data.variable_type == VARIABLE_TYPE_FUNCTION_DECLARE)
	{
	  /*debug("Got something .... %s @ %d (%s)\n",s,a,v->names.name); */
	  /*a4gl_yyerror("This is the name of a function!"); */
		return 0;
	}

      if (v->var_data.variable_type == VARIABLE_TYPE_SIMPLE || v->var_data.variable_type == VARIABLE_TYPE_CONSTANT)
	{
	  if (vu->next == 0)
	    {
	      /* This is too easy... */
	      vu->variable_id = a;
	
	      vu->datatype = encode_size(
					v->var_data.variable_data_u.v_simple.datatype, 
					v->var_data.variable_data_u.v_simple.dimensions[0],
					v->var_data.variable_data_u.v_simple.dimensions[1])
				;

	      if (v->arr_subscripts.arr_subscripts_len)
		{
	  		if (v->arr_subscripts.arr_subscripts_len != vu->subscripts.subscripts_len) {
				if (vu->subscripts.subscripts_len==0 && v->arr_subscripts.arr_subscripts_len) {
					if (v->arr_subscripts.arr_subscripts_val[0]==-1) {
						// Its a dynamic array..
						//
	  				vu->datatype = DTYPE_DYNAMIC_ARRAY;
		
					return v;
					}
				}
	  		}
		  // We have an array variable...
		  if (v->arr_subscripts.arr_subscripts_len != vu->subscripts.subscripts_len && err_if_whole_array)
		    {
		      set_yytext(var_section);
		      sprintf (errbuff, "'%s' subscript count mismatch (1.1) %d != %d", var_section, v->arr_subscripts.arr_subscripts_len, vu->subscripts.subscripts_len);
		      return 0;
		    }
		}
	      else
		{
		  // We have a non-array variable...
		  if (vu->subscripts.subscripts_len)
		    {
		      // Can we move it to be a subscript instead ? 
		      if (vu->substrings_start == 0)
			{
			  if ((v->var_data.variable_data_u.v_simple.datatype & DTYPE_MASK) == DTYPE_CHAR || ((v->var_data.variable_data_u.v_simple.datatype & DTYPE_MASK) == DTYPE_VCHAR)  || ((v->var_data.variable_data_u.v_simple.datatype & DTYPE_MASK) == DTYPE_NCHAR))
			    {
			      if (vu->subscripts.subscripts_len <= 2)
				{
				  // move our subscripts to be substrings..
				  vu->substrings_start = vu->subscripts.subscripts_val[0];
				  if (vu->subscripts.subscripts_len > 1)
				    {
				      vu->substrings_end = vu->subscripts.subscripts_val[1];
				    }
				  free (vu->subscripts.subscripts_val);
				  vu->subscripts.subscripts_val = 0;
				  vu->subscripts.subscripts_len = 0;
				}
			      else
				{
				  sprintf (errbuff, "%s is not an array", var_section);
				  return 0;
				}
			    }
			  else
			    {
			      sprintf (errbuff, "%s is not an array or a string", var_section);
			      return 0;
			    }
			}
		      else
			{
			  sprintf (errbuff, "%s already has a substring", var_section);
			  return 0;
			}
		    }
		  else
		    {
		      // Cool - its not a subscript and we dont need one..
		      return v;
		    }
		}

	      return v;
	    }
	  else
	    {
	      sprintf (errbuff, "%s is not a record", var_section);
	      return 0;
	    }
	}

      if (v->var_data.variable_type == VARIABLE_TYPE_OBJECT)  {
	//  Its an object ..
		struct variable *avar;
	  	struct variable_usage *next;
		struct variable *vrec;
		int vtype;
		next = vu->next;


		avar=v->var_data.variable_data_u.v_object.definition;
	  	vu->variable_id = a;
		vtype=avar->var_data.variable_type;
		A4GL_assertion(vtype!=VARIABLE_TYPE_SIMPLE  && vtype!=VARIABLE_TYPE_RECORD, "Expecting a simple variable or a record");

		if (vtype==VARIABLE_TYPE_SIMPLE) {
				vu->datatype=DTYPE_OBJECT;
				/*
	      			vu->datatype = encode_size(
					avar->var_data.variable_data_u.v_simple.datatype, 
					avar->var_data.variable_data_u.v_simple.dimensions[0],
					avar->var_data.variable_data_u.v_simple.dimensions[1])
				;
				*/
				return v;
		}
		if (vtype==VARIABLE_TYPE_RECORD) {
			A4GL_assertion(1,"Current thinking is we should just store an Object ID - so this should never happen");
			// Must be a record...
	  		vu->datatype = -2;	
			vu->datatype_length = 0;
			vrec=avar;
		}

          if (next == 0)
            {
              return v;
            }

          if (strcmp (next->variable_name, "*") == 0)
            {
              return v;
            }

          return find_variable_vu_in (errbuff, next,
                                      vrec->var_data.variable_data_u.v_record.variables.variables_val,
                                      vrec->var_data.variable_data_u.v_record.variables.variables_len, err_if_whole_array,level+1);

		}

      if (v->var_data.variable_type == VARIABLE_TYPE_RECORD)
	{

	  struct variable_usage *next;
	  next = vu->next;

	  vu->variable_id = a;
	  vu->datatype = -2;	// RECORD...
		vu->datatype_length = 0;
	  if (v->arr_subscripts.arr_subscripts_len != vu->subscripts.subscripts_len) {
		if (vu->subscripts.subscripts_len==0 && v->arr_subscripts.arr_subscripts_len) {
			if (v->arr_subscripts.arr_subscripts_val[0]==-1) {
				// Its a dynamic array..
				//
	  		vu->datatype = DTYPE_DYNAMIC_ARRAY;

			return v;
			}
		}
	  }

	  if (v->arr_subscripts.arr_subscripts_len != vu->subscripts.subscripts_len && err_if_whole_array ) 
		{
		      set_yytext(var_section);
		      sprintf (errbuff, "'%s' subscript count mismatch (2.1) [%d subscripts - expecting %d]", var_section, vu->subscripts.subscripts_len, v->arr_subscripts.arr_subscripts_len);
		      return 0;
		}
			
	if (v->arr_subscripts.arr_subscripts_len && vu->subscripts.subscripts_len!=v->arr_subscripts.arr_subscripts_len && next) {
			set_yytext(var_section);
		      sprintf (errbuff, "'%s' is an array and cant be used like this without selecting a subscript", var_section);
		      return 0;
	}

	  if (next == 0)
	    {
	      return v;
	    }

	  if (strcmp (next->variable_name, "*") == 0)
	    {
	      return v;
	    }

	  return find_variable_vu_in (errbuff, next, v->var_data.variable_data_u.v_record.variables.variables_val, v->var_data.variable_data_u.v_record.variables.variables_len, 0,level+1);
	}



      
      if (v->var_data.variable_type == VARIABLE_TYPE_ASSOC)
	{
	//  Its an associative array..
		struct assoc_array_variable *avar;
	  	struct variable_usage *next;
		struct variable *vrec;
		int vtype;
		next = vu->next;
		avar=&v->var_data.variable_data_u.v_assoc;
	  	vu->variable_id = a;
		vtype=avar->variable->var_data.variable_type;
		A4GL_assertion(vtype!=VARIABLE_TYPE_SIMPLE  && vtype!=VARIABLE_TYPE_RECORD, "Expecting a simple variable or a record");

		if (vtype==VARIABLE_TYPE_SIMPLE) {
	      			vu->datatype = encode_size(
					avar->variable->var_data.variable_data_u.v_simple.datatype, 
					avar->variable->var_data.variable_data_u.v_simple.dimensions[0],
					avar->variable->var_data.variable_data_u.v_simple.dimensions[1])
				;
				return v;
		}
		if (vtype==VARIABLE_TYPE_RECORD) {
			// Must be a record...
	  		vu->datatype = -2;	
	  		vu->datatype_length=0;
			vrec=avar->variable;
		}

          if (next == 0)
            {
              return v;
            }

          if (strcmp (next->variable_name, "*") == 0)
            {
              return v;
            }

          return find_variable_vu_in (errbuff, next,
                                      vrec->var_data.variable_data_u.v_record.variables.variables_val,
                                      vrec->var_data.variable_data_u.v_record.variables.variables_len, err_if_whole_array,level+1);

		
	}


  return NULL;
}


struct variable *
find_variable_vu_in (char *errbuff, struct variable_usage *vu, struct variable **list, int cnt, int err_if_whole_array, int level)
{
  char *var_section;
  //char var_nextsection[256];
  int a;
  struct variable *v;
  struct variable *r;

  /* If we have no variables at this level - we can't do anything */
  if (list == 0)
    {
      return 0;
    }

  var_section = vu->variable_name;
  if (!A4GL_isno (acl_getenv ("VARSRCHOPTIMISE")))
    {
      if (level == 0)
	{
	  r = find_variable_quick (var_section, list, cnt);
	  if (r)
	    {
	      int b;
	      a = -1;
	      for (b = 0; b < cnt; b++)
		{
		  if (list[b] == r)
		    {
		      a = b;
		      break;
		    }
		}
	      if (a != -1)
		{
		  r = find_variable_vu_in_p2 (errbuff, r, var_section, vu, a, err_if_whole_array, level);
		  if (r)
		    return r;
		}
	    }


	  return 0;
	}
    }




  for (a = 0; a < cnt; a++)
    {
      if (list == 0)
	{
	  A4GL_assertion (1, "find_variable_in passed an invalid list");
	}




      v = list[a];


      if (v == 0)
	{
	  A4GL_assertion (1, "find_variable_in passed an invalid list");
	}

      /* Can we find the name at this point ? */
      if (!has_variable_name (&v->names, var_section) && !strcmp (var_section, "*") == 0)
	continue;		/* No */

      // Hopefully - we've found the start of it...
      r = find_variable_vu_in_p2 (errbuff, v, var_section, vu, a, err_if_whole_array, level);
      if (r)
	{
	  if (level == 0)
	    {
	      if (!A4GL_isno (acl_getenv ("VARSRCHOPTIMISE")))
		{
		  A4GL_assertion (1, "Found it the long way - not the short way\n");
		}
	    }
	  return r;
	}
    }
  return NULL;
}







int A4GL_module_has_function(struct module_definition *module, char *s,char *file,struct flist *ptr) {
int a;
int b;
static char buff[256];
for (a=0;a<module->imported_files.imported_files_len;a++) {
        for (b=0;b<module->imported_files.imported_files_val[a].list.list_len;b++) {
                if (A4GL_aubit_strcasecmp(s,module->imported_files.imported_files_val[a].list.list_val[b].name)==0) {
                        if (file) {
                                if (module->imported_files.imported_files_val[a].name[0]!=':') SPRINTF1 (buff,"\"%s\"",module->imported_files.imported_files_val[a].name);
                                else SPRINTF1 (buff,"%s",&module->imported_files.imported_files_val[a].name[1]);
                                strcpy(file,buff);
                        }
                        if (ptr) ptr=&module->imported_files.imported_files_val[a].list.list_val[b];
                        return 1;
                }
        }
}
return 0;
}

static int encode_size(int dtype, int dim1,int dim2) {
        switch (dtype) {
                case DTYPE_CHAR:
                case DTYPE_VCHAR:
                case DTYPE_NCHAR:
                        return dtype+(dim1<<16);
                default:
                        return dtype+(dim1<<16);
                        return dtype;
        }
}


/**
 *  *
 *   * @param s
 *    */
void
set_namespace (char *s)
{
  strcpy (namespace, s);
}



/**
 *
 * @param s
 */
char * get_namespace (char *s)
{
//printf("get namespace for %s : ",s);
  if (is_builtin_func (s)) {

                //printf("aclfgl_\n");
    return "aclfgl_";           /* Always has aclfgl_...*/
  }

//printf("%s\n",namespace);
  return namespace;
}

int match_variable_usage(variable_usage *u1, variable_usage *u2) {
int s1;
int s2;
	if (strcmp(u1->variable_name, u2->variable_name)!=0) {
			return 0;
	}

	s1=-1;
	s2=-1;
	if (u1->substrings_start) {
		A4GL_assertion(u1->substrings_start->expr_type==ET_EXPR_LITERAL_LONG ,"Expecting a ET_EXPR_LITERAL_LONG");
		s1=u1->substrings_start->expr_str_u.expr_long;
	}
	if (u2->substrings_start) {
		A4GL_assertion(u2->substrings_start->expr_type==ET_EXPR_LITERAL_LONG,"Expecting a ET_EXPR_LITERAL_LONG");
		s2=u2->substrings_start->expr_str_u.expr_long;
	}
	if (s1!=s2) return 0; /* different on the substring start.. */
	s1=-1;
	s2=-1;
	if (u1->substrings_end) {
		A4GL_assertion(u1->substrings_end->expr_type==ET_EXPR_LITERAL_LONG ,"Expecting a ET_EXPR_LITERAL_LONG");
		s1=u1->substrings_start->expr_str_u.expr_long;
	}
	if (u2->substrings_end) {
		A4GL_assertion(u2->substrings_end->expr_type==ET_EXPR_LITERAL_LONG ,"Expecting a ET_EXPR_LITERAL_LONG");
		s2=u2->substrings_end->expr_str_u.expr_long;
	}
	if (s1!=s2) return 0; /* different on the substring end.. */


	if (u1->next==0 && u2->next==0) return 1;

	return match_variable_usage(u1->next,u2->next);

// Looks good...
	return 1;
}



/**
 * Downshift a string.
 *
 * @param a The string to be downshifted.
 * @return A pointer to a staic buffer where the string downshifted is putted.
 */
char *
downshift (char *a)
{
  int i;
  static char buff[256];
  strcpy (buff, a);
  for (i = 0; i < strlen (buff); i++)
    {
      buff[i] = tolower (buff[i]);
    }
  return buff;
}


/**
 * Upshift a string.
 *
 * @param a The string to be upshifted.
 * @return A static buffer with a copy of the string upshifted.
 */
char *
upshift (char *a)
{
  int i;
  static char buff[256];
  strcpy (buff, a);
  for (i = 0; i < strlen (buff); i++)
    {
      buff[i] = toupper (buff[i]);
    }
  return buff;
}

