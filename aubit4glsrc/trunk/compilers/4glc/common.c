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
#include "trim_spaces.h"

char namespace[256] = "aclfgl_";

static void append_record_entries(struct record_variable *rec_var, struct variable_usage *parent, struct expr_str_list *rval) ;


static int
has_name (struct vname_name_list *namelist, char *name)
{
  int c;

  if (name == 0)
    return 0;

  for (c = 0; c < namelist->names.names_len; c++)
    {
      if (A4GL_aubit_strcasecmp (namelist->names.names_val[c].name, name) == 0)
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




expr_str_list *expand_parameters(struct variable_list *var_list, expr_str_list *parameters) {
struct expr_str_list *rval;
char errbuff[256];
int a;
struct variable_usage *u;

rval=malloc(sizeof(expr_str_list));
rval->list.list_len=0;
rval->list.list_val=0;

if (!check_parameters(errbuff,var_list, parameters)) {
	A4GL_assertion(1, "Invalid parameter list");
	return 0;
}
if (parameters==0)  return parameters;

for (a=0;a<parameters->list.list_len;a++) {
		int b;
		int found=0;
		for (b=0;b<var_list->variables.variables_len;b++) {
		A4GL_assertion(var_list->variables.variables_val[b]->names.names.names_len>1,"Unexpected number of names");
		if (strcmp(var_list->variables.variables_val[b]->names.names.names_val[0].name, parameters->list.list_val[a]->expr_str_u.expr_string)==0) { // Found it
			switch (var_list->variables.variables_val[b]->var_data.variable_type) {
				case VARIABLE_TYPE_SIMPLE:
					u=new_variable_usage(0,parameters->list.list_val[a]->expr_str_u.expr_string,0);
					A4GL_new_append_ptr_list(rval, A4GL_new_expr_push_variable(u));
					// Cant pass in an array...
					//find_variable_vu_in (errbuff, u, var_list->variables.variables_val, var_list->variables.variables_len,1);
					break;

				case VARIABLE_TYPE_RECORD:
					{
					struct record_variable *rec_var;
					rec_var=&var_list->variables.variables_val[b]->var_data.variable_data_u.v_record;
					u=new_variable_usage(0,parameters->list.list_val[a]->expr_str_u.expr_string,0);
					u->datatype=-2;
					u->scope='L'; /* must be local - its a parameter... */
					append_record_entries(rec_var, u, rval);
					}

					break;
				default:
					A4GL_assertion(1,"Not handled");
			}
			found++;
			break;
			}
		}
}
for (a=0;a<rval->list.list_len;a++) {
find_variable_vu_in (errbuff, rval->list.list_val[a]->expr_str_u.expr_variable_usage , var_list->variables.variables_val, var_list->variables.variables_len,1);
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
		if (strcmp(var_list->variables.variables_val[b]->names.names.names_val[0].name, parameters->list.list_val[a]->expr_str_u.expr_string)==0) { // Found it
			found++;
			break;
		}
	}

	if (!found) {
		set_yytext(parameters->list.list_val[a]->expr_str_u.expr_string);
	        strcpy(errbuff,"Variable has not been defined");
                return 0;
	}
}
return 1;
}





static void append_record_entries(struct record_variable *rec_var, struct variable_usage *parent, struct expr_str_list *rval) {
int c;
struct variable_usage *u;
struct variable_usage *p;


		for (c=0;c<rec_var->variables.variables_len;c++) {
			u=new_variable_usage(0,rec_var->variables.variables_val[c]->names.names.names_val[0].name,0);
			p=A4GL_memdup(parent,sizeof(struct variable_usage));
			p->next=0;
			append_variable_usage(p,u);


			switch  (rec_var->variables.variables_val[c]->var_data.variable_type) {
				case VARIABLE_TYPE_SIMPLE:
					A4GL_new_append_ptr_list(rval, A4GL_new_expr_push_variable(p));
					break;

				case VARIABLE_TYPE_RECORD:
					append_record_entries(&rec_var->variables.variables_val[c]->var_data.variable_data_u.v_record,p,rval);
					break;
				default:
					A4GL_assertion(1,"Not handled");
			}
				
		}
}





struct variable_usage *
new_variable_usage (struct variable_usage *old, char *partname, char prepend)
{
  struct variable_usage *newv;
  int a;
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
  newv->scope = 0;
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



struct variable * find_variable_vu_in (char *errbuff, struct variable_usage *vu, struct variable **list, int cnt,int err_if_whole_array)
{
  char *var_section;
  //char var_nextsection[256];
  int a;
  struct variable *v;

  /* If we have no variables at this level - we can't do anything */
  if (list == 0)
    {
      return 0;
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

      var_section = vu->variable_name;

      /* Can we find the name at this point ? */
      if (!has_name (&v->names, var_section) && !strcmp (var_section, "*") == 0)
	continue;		/* No */

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
	  continue;
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
		  // We have an array variable...
		  if (v->arr_subscripts.arr_subscripts_len != vu->subscripts.subscripts_len && err_if_whole_array)
		    {
		      set_yytext(var_section);
		      sprintf (errbuff, "'%s' subscript count mismatch (1) %d != %d", var_section, v->arr_subscripts.arr_subscripts_len, vu->subscripts.subscripts_len);
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
			  if ((v->var_data.variable_data_u.v_simple.datatype & DTYPE_MASK) == DTYPE_CHAR || (v->var_data.variable_data_u.v_simple.datatype & DTYPE_MASK) == DTYPE_VCHAR)
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


      if (v->var_data.variable_type == VARIABLE_TYPE_RECORD || v->var_data.variable_type == VARIABLE_TYPE_OBJECT)
	{

	  struct variable_usage *next;
	  next = vu->next;

	  vu->variable_id = a;
	  vu->datatype = -2;	// RECORD...


	  if (v->arr_subscripts.arr_subscripts_len != vu->subscripts.subscripts_len && err_if_whole_array) 
		{
			set_yytext(var_section);
		      sprintf (errbuff, "'%s' subscript count mismatch (2)", var_section);
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

	  return find_variable_vu_in (errbuff, next,
				      v->var_data.variable_data_u.v_record.variables.variables_val,
				      v->var_data.variable_data_u.v_record.variables.variables_len, err_if_whole_array);
	}



      
      if (v->var_data.variable_type == VARIABLE_TYPE_ASSOC)
	{
	//  Its an associative array..
		struct assoc_array_variable *avar;
	  	struct variable_usage *next;
		struct variable *vrec;
		next = vu->next;
//A4GL_pause_execution();
		avar=&v->var_data.variable_data_u.v_assoc;
	  	vu->variable_id = a;

		if (avar->variables.variables_len==0) {
			// Its a simple variable..
			struct variable *v2;
			v2= avar->variables.variables_val[0];
			//A4GL_assertion(v2->var_data.variable_type!=VARIABLE_TYPE_SIMPLE,"Expecting a simple type");
			if (v2->var_data.variable_type==VARIABLE_TYPE_SIMPLE) {
	      			vu->datatype = encode_size(
					v2->var_data.variable_data_u.v_simple.datatype, 
					v2->var_data.variable_data_u.v_simple.dimensions[0],
					v2->var_data.variable_data_u.v_simple.dimensions[1])
				;
				return v;
			}
		}

		// Must be a record...
	  	vu->datatype = -2;	
		vrec=v->var_data.variable_data_u.v_assoc.variables.variables_val[0];

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
                                      vrec->var_data.variable_data_u.v_record.variables.variables_len, err_if_whole_array);

		
	}

    }

  return 0;
}




int A4GL_module_has_has_function(struct module_definition *module, char *s,char *file,struct flist *ptr) {
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

int encode_size(int dtype, int dim1,int dim2) {
        switch (dtype) {
                case DTYPE_CHAR:
                case DTYPE_VCHAR:
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

