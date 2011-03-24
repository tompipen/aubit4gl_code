#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wsdl2fgl.h"

#define MAX_POP_PARAM 10000
char *pop_param_buff[MAX_POP_PARAM];
int npop_param=0;
//void make_named_struct (char *name, struct define_variables *v,int singleton);

int vid=0;


struct npvariable *master_variable = 0;

struct s_named_structs
{
  char *name;
  struct define_variables *v;
};

struct s_named_structs *named_structs;
int named_structs_cnt = 0;


struct s_named_enums
{
  char *name;
  struct enum_elements *v;
	int isPtr;
};


struct s_named_enums *named_enums;
int named_enums_cnt = 0;



int c_vars_len=0;
struct npvariable *c_vars_val=0;


static char *unstar(char *s) ;
int set_4gl_pop (char *old_prefix, struct variable_element *param,int isSingleton);

// Add a placeholder for a forward declaration
struct define_variables *new_blank_struct (char *s) {
	struct define_variables *v;
	v=malloc(sizeof(struct define_variables));
	v->var_len=0;
	v->var_val=0;

	make_named_struct(s,v,0);
	return v;
}


void replace_named_struct(char *s,struct define_variables *v) {
int a;
  for (a = 0; a < named_structs_cnt; a++)
    {
      //printf("Checking %d %s %s\n",a,named_structs[a].name,s);
      if (strcmp (named_structs[a].name, s) == 0)
        {
		if (named_structs[a].v->var_len==0) {
			named_structs[a].v=v;
			return;
		}
		fprintf(stderr,"Struct %s was multiply defined\n",s);
		exit(2);
        }

    }
	fprintf(stderr,"Internal error - couldn't find struct to replace\n");
	exit(2);

}

struct define_variables *
add_named_struct (char *s)
{
  struct define_variables *v;
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



  fprintf (stderr,"Warning: structure %s not found or defined yet - assuming forward declared\n", s);
  return new_blank_struct(s);

  exit (1);
}




int has_named_struct (char *s)
{
  int a;
  for (a = 0; a < named_structs_cnt; a++)
    {
      //printf("Checking %d %s %s\n",a,named_structs[a].name,s);
      if (strcmp (named_structs[a].name, s) == 0)
        {
          // Found our structure...
                return 1;
        }
    }
        return 0;
}


int has_named_enum(char *s) {
  int a;
  for (a = 0; a < named_enums_cnt; a++)
    {
      if (strcmp (named_enums[a].name, s) == 0)
        {
          // Found our structure...
                return 1;
        }
    }
        return 0;
}

struct variable_element *
new_variable_element_string (char *s)
{
  struct variable_element *n;
  n = acl_malloc2 (sizeof (struct variable_element));
  n->name = NULL;
  n->dtype = strdup(s);
  n->unit_size = 0;
  n->total_size = 0;

  n->i_arr_size[0] = 0;
  n->i_arr_size[1] = 0;
  n->i_arr_size[2] = 0;
  n->offset = 0;
  n->next.next_len = 0;
  n->next.next_val = 0;

  return n;
}



void make_named_struct (char *name, struct define_variables *v,int singleton)
{
//printf("make_named_struct Name=%s\n",name);

  if (strstr(name,"*") || strstr(name," ")) {
	static char name2[2000];
	char dtype[2000]="";
	char dtype2[2000]="";
	char *name_ptr;

		strcpy(name2,name);
		name_ptr=name2;
		while (*name_ptr==' ' || *name_ptr=='*') {
       			if (*name_ptr=='*') {
                       			strcat(dtype,"*");
       			}
       			name_ptr++;
		}
		name=name_ptr;
		if (v->var_len!=1) {
			fprintf(stderr,"Not expecting to have to fixup a named struct with more than one entry.... (%d)\n", v->var_len);
			exit(2);
		}
		v->var_val[0].name=strdup(name_ptr);
		sprintf(dtype2,"%s%s",v->var_val[0].dtype,dtype);
		v->var_val[0].dtype=strdup(dtype2);
	}

//printf("Adding : %s\n",name);
  named_structs_cnt++;
  named_structs = realloc (named_structs, sizeof (struct define_variables) * named_structs_cnt);
  named_structs[named_structs_cnt - 1].name = strdup (name);
  v->singleton=singleton;
  named_structs[named_structs_cnt - 1].v = v;

//printf("Added make_name_struct : '%s'\n", name);
}


struct variable_element *
new_variable_struct (struct define_variables *v,char *struct_name)
{
  struct variable_element *n;
  int a;
  int s = 0;
  n = acl_malloc2 (sizeof (struct variable_element));
  n->name = NULL;
  n->dtype = strdup(struct_name);
  n->i_arr_size[0] = 0;
  n->i_arr_size[1] = 0;
  n->i_arr_size[2] = 0;
  n->unit_size = 0;
  n->total_size = 0;
  n->offset = 0;

  if (v==NULL) {
	
	return n;
  }
  
  A4GL_debug ("new_variable_struct : %d %p\n", v->var_len, v);

  n->next.next_len = v->var_len;
  if (v->var_len)
    {
      n->next.next_val =
        acl_malloc2 (sizeof (struct variable_element) * n->next.next_len);
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




int
get_dtype (char *s)
{
  if (strcasecmp (s, "char") == 0)
    return DCHAR;
  if (strcasecmp (s, "uchar") == 0)
    return DCHAR;
  if (strcasecmp (s, "String") == 0)
    return DSTRING;
  if (strcasecmp (s, "int") == 0)
    return DLONG;
  if (strcasecmp (s, "short") == 0)
    return DINT;
  if (strcasecmp (s, "uint") == 0)
    return DLONG;
  if (strcasecmp (s, "ushort") == 0)
    return DINT;


  if (strcasecmp (s, "fgldate") == 0)
    return DLONG;
  if (strcasecmp (s, "long") == 0)
    return DLONG;
  if (strcasecmp (s, "longlong") == 0)
    return DLONG;
  if (strcasecmp (s, "ulonglong") == 0)
    return DLONG;
  if (strcasecmp (s, "ulong") == 0)
    return DLONG;
  if (strcasecmp (s, "VoidPointer") == 0)
    return DPTR;

  if (strcasecmp (s, "DOUBLE") == 0)
    return DDBL;

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

  if (strcasecmp (s, "struct_dtime") == 0 || strcasecmp (s, "FGLSDTIME") == 0 )
    {
      return DDTIME;
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
add_variable (int type, struct variable_element *e, char *id, long set_i) // @todo - set_i - is it used ?
{

  struct npvariable *v;
  //struct cmd_block *base;

  v = acl_malloc2 (sizeof (struct npvariable));
  A4GL_debug ("Add variable .. %s type=%d \n", id, type);

  master_variable = v;
  //this_module_ptr->max_variable_id=vid;
  master_variable->variable_id = vid++;
  master_variable->category = type;

  master_variable->var = e;

  e->name = strdup (id);

  master_variable->def_block = -1;

  c_vars_len++;
  c_vars_val = realloc (c_vars_val, c_vars_len * sizeof (struct npvariable));
  //base->mem_to_alloc += v->var->total_size;

  memcpy (&c_vars_val[c_vars_len - 1], master_variable, sizeof (struct npvariable));

  master_variable = &c_vars_val[c_vars_len - 1];
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
		//e->as=as;
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

void make_named_enum(char * name, struct enum_elements *elem_list,int isPtr) {
  named_enums_cnt++;
  named_enums =
    realloc (named_enums,
             sizeof (struct define_variables) * named_enums_cnt);
  named_enums[named_enums_cnt - 1].name = strdup (name);
  named_enums[named_enums_cnt - 1].v = elem_list;
  named_enums[named_enums_cnt - 1].isPtr = isPtr;

	
}


struct enum_elements *append_enum_element(struct enum_elements *elem_list, struct enum_element *elem) {
	if(elem_list==NULL) {
		elem_list=malloc(sizeof(struct enum_elements));
		elem_list->nelements=0;
		elem_list->elements=NULL;
	}
	elem_list->nelements++;
	elem_list->elements=realloc(elem_list->elements, sizeof(elem_list->elements[0])*elem_list->nelements);
	elem_list->elements[elem_list->nelements-1]=elem;
	return elem_list;
}

struct enum_element *new_enum_element(char *name, int value) {
	struct enum_element *e;
	e=malloc(sizeof(*e));
	e->element=strdup(name);
	e->n=value;

	return e;
}



struct define_variables *add_variables(struct define_variables *v, struct variable_element * elem) {
char name[2000];
char *name_ptr=0;
char dtype[2000]="";
char dtype2[2000]="";
if (v==NULL) {
		v=acl_malloc2(sizeof(struct define_variables));
		v->var_len=0;
		v->var_val=0;
}


// A variable may be defined with a single datatype - but lots of names - eg.
// int a,b,c
// In the compiler - we just get the name list "a,b,c" - so we need to split
// this and create a separate entry for each one....
if (strchr (elem->name,',')) {
	char buff[10000];
	char *ptr;
	//printf("Got a compound : %s\n",elem->name);
	// If we've got a bunch of names - do each one once...
	strcpy(buff,elem->name);
	ptr=buff;

	while (ptr) {
		char *buff2;
		buff2=strchr(ptr,','); // Find the next ',' - will be 0 if there are no more after this one...
		if (buff2) { *buff2=0; }
		elem->name=strdup(ptr);
		add_variables(v,elem);
		if (!buff2) { break; }
		ptr=buff2+1;
		
	}
	return v;
} 

//printf("Adding variable : %s dtype=%s\n", elem->name,elem->dtype);
strcpy(name,elem->name);
name_ptr=name;
while (*name_ptr==' ' || *name_ptr=='*') {
	if (*name_ptr=='*') {
			strcat(dtype,"*");
	}
	name_ptr++;
}


//printf("Name='%s'\n",name_ptr);
sprintf(dtype2,"%s%s",elem->dtype,dtype);

    v->var_len++;
    v->var_val=realloc(v->var_val, sizeof(struct variable_element)*v->var_len);
    memcpy(&v->var_val[v->var_len-1],elem,sizeof(struct variable_element));
    v->var_val[v->var_len-1].name=strdup(name_ptr);
    v->var_val[v->var_len-1].dtype=strdup(dtype2);

//printf("Added as '%s' : '%s'\n",v->var_val[v->var_len-1].name, v->var_val[v->var_len-1].dtype);


    return v;

}


static void print_indent(int n) {
int a;
for (a=0;a<n;a++) {
 	fprintf(getOuputFile(),"   ");
	}
}

int print_4gl_dtype(int mode, struct variable_element *param,int lvl) {
int a;
char *name;

if (lvl==0) {
	if (mode==1) {
		name="lv_in";
	} else {
		name="lv_out";
	}
} else {
	name=param->name;
}

if (param->next.next_len ) {
		fprintf(getOuputFile(),"struct { /* %d */\n",  param->next.next_len);
		for (a=0;a<param->next.next_len;a++) {
			print_4gl_dtype(mode, &param->next.next_val[a],lvl+1);
			if (a<param->next.next_len-1) {
				fprintf(getOuputFile(),",\n");
			} else {
				fprintf(getOuputFile(),"\n");
			}
		}
		fprintf(getOuputFile(),"} \n");
		return 1;
} else  {
	printf("Looking at : %s\n", param->dtype);
	print_indent(lvl);
	if (strstr(param->dtype,"ENUM:")) 		{ fprintf(getOuputFile(),"%s INTEGER", name); return 1;}
	if (strcasecmp(param->dtype,"long")==0) 	{ fprintf(getOuputFile(),"%s INTEGER", name); return 1;}
	if (strcasecmp(param->dtype,"char")==0) 	{ fprintf(getOuputFile(),"%s CHAR(1)", name); return 1;}
	if (strcasecmp(param->dtype,"char*")==0) 	{ fprintf(getOuputFile(),"%s CHAR(256)", name); return 1;}
	if (strcasecmp(param->dtype,"double")==0) 	{ fprintf(getOuputFile(),"%s FLOAT", name); return 1;}
	if (strcasecmp(param->dtype,"float")==0) 	{ fprintf(getOuputFile(),"%s SMALLFLOAT", name); return 1;}
	if (strcasecmp(param->dtype,"long")==0) 	{ fprintf(getOuputFile(),"%s INTEGER", name); return 1;}
	if (strcasecmp(param->dtype,"longlong")==0) 	{ fprintf(getOuputFile(),"%s INTEGER", name); return 1;}
	if (strcasecmp(param->dtype,"short")==0) 	{ fprintf(getOuputFile(),"%s INTEGER", name); return 1;}
	if (strcasecmp(param->dtype,"time_t")==0) 	{ fprintf(getOuputFile(),"%s INTEGER", name); return 1;}
	if (strcasecmp(param->dtype,"uchar")==0) 	{ fprintf(getOuputFile(),"%s INTEGER", name); return 1;}
	if (strcasecmp(param->dtype,"ulong")==0) 	{ fprintf(getOuputFile(),"%s INTEGER", name); return 1;}
	if (strcasecmp(param->dtype,"ulonglong")==0) 	{ fprintf(getOuputFile(),"%s INTEGER", name); return 1;}
	if (strcasecmp(param->dtype,"ushort")==0) 	{ fprintf(getOuputFile(),"%s INTEGER", name); return 1;}
}
return 1;
}

int set_4gl_pop (char *old_prefix, struct variable_element *param,int isSingleton)
{
  char prefix[20000] = "";
      char name[2000];
  int a;
char buff[400];
  int bad = 0;
  int r=0;


  if (strlen(old_prefix)==0) {
		for (a=0;a<MAX_POP_PARAM;a++) {
			pop_param_buff[a]=0;
		}
		npop_param=0;
  }


  if (param->next.next_len)
    {
      if (strlen (old_prefix))
	{
	  strcpy (prefix, old_prefix);
	}
      strcat (prefix, param->name);

      if (strstr (param->dtype, "**"))
	{
	  // Pointer to a pointer - probably some sort of an array ? 
	  fprintf (getOuputFile (), " /* some values have not been set */\n");
	  fprintf (getOuputFile (), " /* %s */\n", old_prefix);
	  bad++;
	}
      else
	{
		struct define_variables *v;
		v=add_named_struct(unstar(param->dtype));

	  if (strstr (param->dtype, "*"))
	    {
	      char buff[3888];
		if (v) {
			if (v->singleton) {
				isSingleton=1;
				strcpy(buff,"");
			} else {
	      			sprintf (buff, "->"); //, param->dtype,v->singleton);
			}
		} else {
	      		sprintf (buff, "->"); // /* %s */", param->dtype);
		}
	      strcat (prefix, buff);	// or '.' ? ???
	    }
	  else
	    {
		if (v) {
			char buff[2000];	
			
			if (v->singleton) {
				isSingleton=1;
			} else {
	      			sprintf (buff, ". /* %d */", v->singleton);	// or '.' ? ???
	      			strcat (prefix,buff);	// or '.' ? ???
			}
		} else {
	      		strcat (prefix, ". /* NO V */");	// or '.' ? ???
		}
	    }

	  for (a = 0; a < param->next.next_len; a++)
	    {
	      r+=set_4gl_pop (prefix, &param->next.next_val[a],isSingleton);
	    }
	}

	return r;
    }



	if (isSingleton) {
      		sprintf (name, "%s", old_prefix); // Dont worry about the name - its a singleton so it doesn't really have one..
	} else {
      		sprintf (name, "%s%s", old_prefix, param->name);
	}



	fprintf(getOuputFile(),"/* Parameter %d - %s", npop_param+1,  param->name);

      if (strcasecmp (param->dtype, "long") == 0)
	{
	  sprintf (buff, "%s=A4GL_pop_long();\n", name);
		pop_param_buff[npop_param++]=strdup(buff);
			fprintf(getOuputFile()," INTEGER */\n");

	  return 1;
	}
      if (strcasecmp (param->dtype, "char") == 0)
	{
	  sprintf (buff, "%s=A4GL_pop_single_char();\n", name);
	pop_param_buff[npop_param++]=strdup(buff);
			fprintf(getOuputFile()," CHAR(1) */\n");
	  return 1;
	}
      if (strcasecmp (param->dtype, "char*") == 0 || strcasecmp (param->dtype, "xml") == 0)
	{
	  sprintf (buff, "%s=A4GL_char_pop();\n", name);
	pop_param_buff[npop_param++]=strdup(buff);
			fprintf(getOuputFile()," CHAR(...) */\n");
	  return 1;
	}
      if (strcasecmp (param->dtype, "double") == 0)
	{
	  sprintf (buff, "%s=A4GL_pop_double();\n", name);
	pop_param_buff[npop_param++]=strdup(buff);
			fprintf(getOuputFile()," DOUBLE */\n");
	  return 1;
	}
      if (strcasecmp (param->dtype, "float") == 0)
	{
	  sprintf (buff, "%s=A4GL_pop_float();", name);
		pop_param_buff[npop_param++]=strdup(buff);
			fprintf(getOuputFile()," FLOAT */\n");
	  return 1;
	}
      if (strcasecmp (param->dtype, "longlong") == 0)
	{
	  sprintf (buff, "%s=A4GL_pop_long();", name);
		pop_param_buff[npop_param++]=strdup(buff);
			fprintf(getOuputFile()," LONG */\n");
	  return 1;
	}
      if (strcasecmp (param->dtype, "short") == 0)
	{
	  sprintf (buff, "%s=A4GL_pop_long();", name);
		pop_param_buff[npop_param++]=strdup(buff);
			fprintf(getOuputFile()," SHORT */\n");
	  return 1;
	}
      if (strcasecmp (param->dtype, "time_t") == 0)
	{
	  sprintf (buff, "%s=A4GL_pop_time_t();", name);
		pop_param_buff[npop_param++]=strdup(buff);
			fprintf(getOuputFile()," TIME_T */\n");
	  return 1;
	}
      if (strcasecmp (param->dtype, "uchar") == 0)
	{
	  sprintf (buff, "%s=A4GL_pop_single_char();", name);
		pop_param_buff[npop_param++]=strdup(buff);
			fprintf(getOuputFile()," CHAR(1) */\n");
	  return 1;
	}
      if (strcasecmp (param->dtype, "ulong") == 0)
	{
	  sprintf (buff, "%s=A4GL_pop_long();", name);
		pop_param_buff[npop_param++]=strdup(buff);
			fprintf(getOuputFile()," INTEGER */\n");
	  return 1;
	}

      if (strcasecmp (param->dtype, "long*") == 0)
	{
	  sprintf (buff, "{static int plong;plong=A4GL_pop_long();if (A4GL_isnull(2,&plong)) %s=0; else %s=&plong;}", name,name);
		pop_param_buff[npop_param++]=strdup(buff);
			fprintf(getOuputFile()," INTEGER */\n");
	  return 1;
	}
      if (strcasecmp (param->dtype, "short*") == 0)
	{
	  sprintf (buff, "{static int pshort;pshort=A4GL_pop_int();if (A4GL_isnull(1,&plong)) %s=0; %s=&pshort;}", name,name);
		pop_param_buff[npop_param++]=strdup(buff);
			fprintf(getOuputFile()," SMALLINT */\n");
	  return 1;
	}


      if (strcasecmp (param->dtype, "ulonglong") == 0)
	{
	  sprintf (buff, "%s=A4GL_pop_long();", name);
		pop_param_buff[npop_param++]=strdup(buff);
			fprintf(getOuputFile()," INTEGER */\n");
	  return 1;
	}
      if (strcasecmp (param->dtype, "ushort") == 0)
	{
	  sprintf (buff, "%s=A4GL_pop_long();", name);
		pop_param_buff[npop_param++]=strdup(buff);
			fprintf(getOuputFile()," INTEGER */\n");
	  return 1;
	}


	sprintf(buff,"%s=A4GL_op_%s();",name,param->dtype);
	pop_param_buff[npop_param++]=strdup(buff);
			fprintf(getOuputFile()," ?? %s %s */\n", name,param->dtype);
    
	
  return 1;
}

int
print_4gl_push (char *old_prefix, struct variable_element *param,int isSingleton)
{
  char prefix[20000] = "";
      char name[2000];
  int a;
  int bad = 0;
  int r=0;

  if (param->next.next_len)
    {
      if (strlen (old_prefix))
	{
	  strcpy (prefix, old_prefix);
	}
      strcat (prefix, param->name);
      if (strstr (param->dtype, "**"))
	{
	  // Pointer to a pointer - probably some sort of an array ? 
	  fprintf (getOuputFile (), " /* some values have been discarded - returning '0' as a placeholder */\n");
	  fprintf (getOuputFile (), "   A4GL_push_long(0); /* %s */\n", old_prefix);
	  bad++;
	}
      else
	{
		struct define_variables *v;
		v=add_named_struct(unstar(param->dtype));

	  if (strstr (param->dtype, "*"))
	    {
	      char buff[3888];
		if (v) {
			if (v->singleton) {
				isSingleton=1;
				strcpy(buff,"");
			} else {
	      			sprintf (buff, "->"); // , param->dtype,v->singleton);
			}
		} else {
	      		sprintf (buff, "->"); //, param->dtype);
		}
	      strcat (prefix, buff);	// or '.' ? ???
	    }
	  else
	    {
		if (v) {
			char buff[2000];	
			
			if (v->singleton) {
				isSingleton=1;
			} else {
	      			sprintf (buff, ". /* %d */", v->singleton);	// or '.' ? ???
	      			strcat (prefix,buff);	// or '.' ? ???
			}
		} else {
	      		strcat (prefix, ". /* NO V */");	// or '.' ? ???
		}
	    }

	  for (a = 0; a < param->next.next_len; a++)
	    {
	      r+=print_4gl_push (prefix, &param->next.next_val[a],isSingleton);
	    }
	}

	return r;
    }



	if (isSingleton) {
      		sprintf (name, "%s", old_prefix); // Dont worry about the name - its a singleton so it doesn't really have one..
	} else {
      		sprintf (name, "%s%s", old_prefix, param->name);
	}

	 fprintf (getOuputFile (), "/* %s */\n", param->dtype);

      if (strcasecmp (param->dtype, "xsd__boolean") == 0 || strcasecmp(param->dtype,"ENUM:xsd__boolean")==0)
	{
	  fprintf (getOuputFile (), "   A4GL_push_int(%s);\n", name);
	  return 1;
	}
      if (strcasecmp (param->dtype, "long") == 0)
	{
	  fprintf (getOuputFile (), "   A4GL_push_long(%s);\n", name);
	  return 1;
	}
      if (strcasecmp (param->dtype, "char") == 0)
	{
	  fprintf (getOuputFile (), "   A4GL_push_single_char(%s);\n", name);
	  return 1;
	}
      if (strcasecmp (param->dtype, "char*") ==0 || strcasecmp (param->dtype, "xml" ) == 0)
	{
	  fprintf (getOuputFile (), "   A4GL_push_char(%s); //%s\n", name, param->dtype);
	  return 1;
	}
      if (strcasecmp (param->dtype, "double") == 0)
	{
	  fprintf (getOuputFile (), "   A4GL_push_double(%s);\n", name);
	  return 1;
	}
      if (strcasecmp (param->dtype, "float") == 0)
	{
	  fprintf (getOuputFile (), "   A4GL_push_float(%s);", name);
	  return 1;
	}
      if (strcasecmp (param->dtype, "long") == 0)
	{
	  fprintf (getOuputFile (), "   A4GL_push_long(%s);", name);
	  return 1;
	}

      if (strcasecmp (param->dtype, "long*") == 0)
	{
	  fprintf (getOuputFile (), "   A4GL_push_long(*%s);", name);
	  return 1;
	}

      if (strcasecmp (param->dtype, "ENUM:xsd__boolean*") == 0)
	{
	  fprintf (getOuputFile (), "   A4GL_push_int(*%s);", name);
	  return 1;
	}

      if (strcasecmp (param->dtype, "longlong") == 0)
	{
	  fprintf (getOuputFile (), "   A4GL_push_long(%s);", name);
	  return 1;
	}
      if (strcasecmp (param->dtype, "short") == 0)
	{
	  fprintf (getOuputFile (), "   A4GL_push_long(%s);", name);
	  return 1;
	}
      if (strcasecmp (param->dtype, "time_t") == 0)
	{
	  fprintf (getOuputFile (), "   A4GL_push_time_t(%s);", name);
	  return 1;
	}
      if (strcasecmp (param->dtype, "uchar") == 0)
	{
	  fprintf (getOuputFile (), "   A4GL_push_single_char(%s);", name);
	  return 1;
	}
      if (strcasecmp (param->dtype, "ulong") == 0)
	{
	  fprintf (getOuputFile (), "   A4GL_push_long(%s);", name);
	  return 1;
	}
      if (strcasecmp (param->dtype, "ulonglong") == 0)
	{
	  fprintf (getOuputFile (), "   A4GL_push_long(%s);", name);
	  return 1;
	}
      if (strcasecmp (param->dtype, "ushort") == 0)
	{
	  fprintf (getOuputFile (), "   A4GL_push_long(%s);", name);
	  return 1;
	}

	  fprintf (getOuputFile (), "   UNHANDLED : %s", param->dtype);

    
  return 1;
}


static char *downshift(char *s) {
int a;
static char buff[2000];
strcpy(buff,s);
for (a=0;a<strlen(s);a++) {
	buff[a]=tolower(buff[a]);
}
return buff;
}


static char *unstar(char *s) {
static char buff[2000];
char *ptr;
strcpy(buff,s);
ptr=strchr(buff,'*');
if (ptr) *ptr=0;
return buff;

}

void add_function_definition(struct variable_element *rettype, char *s,struct define_variables *params) {
char name[2000];
char dtype[2000]="";
char dtype2[2000];
char *name_ptr;
int a;
char *called_name;
int nparams;
int rvals=0;

strcpy(name,s);
name_ptr=name;

while (*name_ptr==' ' || *name_ptr=='*') {
        if (*name_ptr=='*') {
                        strcat(dtype,"*");
        }
        name_ptr++;
}
sprintf(dtype2,"%s%s",rettype->dtype,dtype);
rettype->dtype=strdup(dtype2);
s=name_ptr;
printf("Function : %s returns %s\n", s,rettype->dtype);
if (params==NULL) {
	printf("Params is null!\n");
	return;
}



called_name=s;
while (strncmp(called_name,"__",2)==0)  called_name++;
called_name=strstr(&s[1],"__");
if (called_name) {
	called_name+=2; 
} else {
	called_name=s;
}
fprintf(getOuputFile(),"/* ---- %s called_name=%s ---- */\n",s, called_name );
fprintf(getOuputFile(),"/* %d declared parameters... */\n", params->var_len);


fprintf(getOuputFile(),"int aclfgl_%s(int nparam) {\n", downshift(s));
fprintf(getOuputFile()," return %s(nparam);\n}\n\n\n", downshift(called_name));
fprintf(getOuputFile(),"int %s(int nparam) {\n",downshift(called_name));
fprintf(getOuputFile(),"static char *url=NULL;\n");

for (a=0;a<params->var_len;a++) {

	struct define_variables *v;

	if (strlen(params->var_val[a].name)==0) {
		char buff[200];
		sprintf(buff,"__r%d", a);
		params->var_val[a].name=strdup(buff);
	}

	if (has_named_struct(unstar(params->var_val[a].dtype)) ) {
		if (strstr(params->var_val[a].dtype,"ENUM:")) {
			A4GL_assertion(1,"Shouldnt happen");
			//fprintf(getOuputFile(),"int %s; // %s\n",  params->var_val[a].name, params->var_val[a].dtype);
		} else {
			// Ok - what type of struct is it ? 
			v=add_named_struct(unstar(params->var_val[a].dtype));
			if (v->singleton) {
				int c;
				char buff[1000];
				strcpy(buff, v->var_val[0].dtype);
				for (c=0;c<strlen(params->var_val[a].dtype);c++) {
					if (params->var_val[a].dtype[c]=='*') strcat(buff,"*");
				}

				fprintf(getOuputFile(),"static %s %s; /* 0 */ \n",buff,  params->var_val[a].name);
			} else {
				fprintf(getOuputFile(),"static struct %s %s; /* 1 */\n", params->var_val[a].dtype,  params->var_val[a].name);
			}
		}
	} else {
		if (strstr(params->var_val[a].dtype,"ENUM:")) {
			char *p;
			p=params->var_val[a].dtype;
			p+=5; // Skip the ENUM:
			
			fprintf(getOuputFile(),"static enum %s %s; /* 3 */\n",  p, params->var_val[a].name);
		} else {
			fprintf(getOuputFile(),"static %s %s; /* 2 */\n", params->var_val[a].dtype,  params->var_val[a].name);
		}
	}
}


fprintf(getOuputFile(),"struct soap *soap;\n");
fprintf(getOuputFile(),"static int _init=0;\n");
// Find the first "__" - skipping any leading "__"
//
//
fprintf(getOuputFile(),"/* url=\"http://localhost:9090\"; //get_url(); */\n");
fprintf(getOuputFile(),"\n#ifdef SRCH_DEFAULT_SERVER\n");
fprintf(getOuputFile(),"url=get_Default_Webserver();\n");
fprintf(getOuputFile(),"#endif\n");


for (a=0;a<params->var_len;a++) {

	struct define_variables *v;

	if (strlen(params->var_val[a].name)==0) {
		char buff[200];
		sprintf(buff,"__r%d", a);
		params->var_val[a].name=strdup(buff);
	}

	if (has_named_struct(unstar(params->var_val[a].dtype)) ) {
		if (strstr(params->var_val[a].dtype,"ENUM:")) {
		} else {
			// Ok - what type of struct is it ? 
			v=add_named_struct(unstar(params->var_val[a].dtype));
			if (!v->singleton) {
				if (strstr(params->var_val[a].dtype,"*")) {
					fprintf(getOuputFile(),"if (!_init) {%s=malloc(sizeof(*%s));} /* 1 */\n", params->var_val[a].name,  params->var_val[a].name);
					fprintf(getOuputFile(),"memset(%s,0,sizeof(*%s)); /* 1 */\n", params->var_val[a].name,  params->var_val[a].name);
				}
			}
		}
	}
}

fprintf(getOuputFile(),"if (!_init) {\n");
fprintf(getOuputFile(),"   _init=1;\n");
fprintf(getOuputFile(),"}\n\n");



fprintf(getOuputFile(),"/* An extra URL parameter can optionally be passed in first */\n");
nparams=set_4gl_pop( "",&params->var_val[0],0);
fprintf(getOuputFile(),"\n\nif (nparam!=%d && nparam!=%d) {\n", nparams, nparams+1);
fprintf(getOuputFile(),"   A4GL_pop_args(nparam); A4GL_set_status(-3002,0);return 0;\n");
fprintf(getOuputFile(),"}\n");
fprintf(getOuputFile(),"\n");
fprintf(getOuputFile(),"/* 4gl Parameters: */\n");

for (a=npop_param-1;a>=0;a--) {
	fprintf(getOuputFile(),"%s\n",pop_param_buff[a]);
}
fprintf(getOuputFile(),"\nif (nparam==%d) {\n", nparams+1) ;
fprintf(getOuputFile(),"   if (url) acl_free(url);\n");
fprintf(getOuputFile(),"   url=A4GL_char_pop();\n") ;
fprintf(getOuputFile(),"}\n") ;
fprintf(getOuputFile(),"\n") ;





fprintf(getOuputFile(),"soap = soap_new();\n");
//fprintf(getOuputFile(),"if (soap_call_%s(soap,url,\"%s\",", s,called_name);
fprintf(getOuputFile(),"if (soap_call_%s(soap,url,NULL,", s);
for (a=0;a<params->var_len;a++) {
	if (a) fprintf( getOuputFile(),",");
	fprintf(getOuputFile(),"%s",  params->var_val[a].name );
}

fprintf(getOuputFile(),")==SOAP_OK) {\n   /* Cool - it worked... */\n");
rvals=print_4gl_push( "", &params->var_val[params->var_len-1],0);

fprintf(getOuputFile(),"   return %d;\n",rvals);
fprintf(getOuputFile(),"}\n");

fprintf(getOuputFile(),"else {soap_print_fault(soap,stderr); return 0;}\n");

/*

printf("Has %d parameters\n", params->var_len);
for (a=0;a<params->var_len;a++) {
	printf("  param %d : Name = %s Type = %s\n", a, params->var_val[a].name,params->var_val[a].dtype);
}

printf("\n");
*/
fprintf(getOuputFile(),"}  /* %s */\n\n\n\n",s);

}
