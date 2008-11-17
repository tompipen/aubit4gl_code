/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-2005 Aubit Development Team (See Credits file)    |
# +----------------------------------------------------------------------+
# | This program is free software; you can redistribute it and/or modify |
# | it under the terms of one of the following licenses:                 |
# |                                                                      |
# |  A) the GNU General Public License as published by the Free Software |
# |     Foundation; either version 2 of the License, or (at your option) |
# |     any later version.                                               |
# |                                                                      |
# |  B) the Aubit License as published by the Aubit Development Team and |
# |     included in the distribution in the file: LICENSE                |
# |                                                                      |
# | This program is distributed in the hope that it will be useful,      |
# | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
# | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
# | GNU General Public License for more details.                         |
# |                                                                      |
# | You should have received a copy of both licenses referred to here.   |
# | If you did not, or have any questions about Aubit licensing, please  |
# | contact licensing@aubit.com                                           |
# +----------------------------------------------------------------------+
#
# $Id: class.c,v 1.18 2008-07-06 11:34:23 mikeaubury Exp $
#
*/

/**
 * @file
 * 
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_4glc_int.h"
#include "variables.h"
#include "commands.h"
#include "parsehelp.h"

/*
=====================================================================
		                    Variables
=====================================================================
*/

/* This is from 4glc.c */
char *allbuff = 0;
int allbuffsize = 0;
char **class_variable_data;
char **class_members;
struct variable **list_parent = 0;
extern struct variable **list_class;	/* Our List */
extern int is_schema;
extern int list_class_cnt;
  //extern int list_class_cnt;	/* Our List */
  extern int list_class_alloc;	/* Our List */

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


/* Externally callable (non-static) functions */


//andrej int read_class (char *s,int is_parent);

/* static functions declared here */
static void write_variable_header (struct variable *v);
static void write_variable_simple (struct variable *v);
static void write_variable_linked (struct variable *v);
static void write_variable_record (struct variable *v);
static void write_variable_object (struct variable *v);
static void write_variable_assoc (struct variable *v);
static void write_variable_constant (struct variable *v);
static void read_class_int (char *name, int *val);
static void read_class_string (char *name, char **val, int alloc);
static void read_class_char (char *name, char *val);
static void read_class_float (char *name, double *val);
static void read_variable_header (struct variable *v);
static void read_variable_simple (struct variable *v);
static void read_variable_linked (struct variable *v);
static void read_variable_record (struct variable *v);
static void read_variable_object (struct variable *v);
static void read_variable_assoc (struct variable *v);
static void read_variable_constant (struct variable *v);
//static void generate_globals_for (char *s);
static void write_variable_function (struct variable *v);
static void read_variable_function (struct variable *v);
static void do_append (void);
//andrej void dump_class (void);
int class_call(char *s,char *f,int args);

struct s_class_definition *this_class;
/*
=====================================================================
                    Functions definitions
=====================================================================
*/

char tmpbuff[1024] = "";

void
do_append (void)
{
  int init = 0;
  if (allbuffsize == 0)
    init = 1;
  allbuffsize += strlen (tmpbuff) + 10;
  allbuff = acl_realloc (allbuff, allbuffsize);
  if (init)
    strcpy (allbuff, tmpbuff);
  else
    strcat (allbuff, tmpbuff);
}

/**
 *
 *
 * @param
 */
static void
write_class_int (char *name, int val)
{
  SPRINTF2 (tmpbuff, "%s=%d\n", name, val);
  do_append ();
}


int 
class_call(char *s,char *f,int args) {
char buff[512];
char *fname;
	strcpy(buff,s);
	strcat(buff,acl_getenv("A4GL_DLL_EXT"));
	fname=A4GL_fullpath_classpath(buff);
	if (fname==0) {
		a4gl_yyerror("Unable to open class file");
		return 0;
	}
#ifndef MSVC
	return A4GL_call_4gl_dll(fname,f,args);
#else
	A4GL_assertion(1,"Not implemented : class_call");
#endif
}





static void escape (char *buff) {
char buff2[1024];
int a;
int b=0;
for (a=0;a<strlen(buff);a++) {
	if (buff[a]=='"') buff2[b++]='\\';
	buff2[b++]=buff[a];
}
buff2[b]=0;
strcpy(buff,buff2);

}

/**
 *
 *
 * @param
 */
static void
write_class_string (char *name, char *val)
{
  char buff[1024];
strcpy(buff,val);
	escape(buff);
  SPRINTF2 (tmpbuff, "%s=%s\n", name, buff);
  do_append ();
}

/**
 *
 *
 * @param
 */
static void
write_class_char (char *name, char val)
{
  SPRINTF2 (tmpbuff, "%s=%c\n", name, val);
  do_append ();
}

/**
 *
 *
 * @param
 */
static void
write_class_float (char *name, double val)
{
  SPRINTF2 (tmpbuff, "%s=%f\n", name, val);
  do_append ();

}



/**
 *
 *
 * @param
 */
void
dump_class (void)
{
  int a;
  struct variable *v;

  write_class_string ("DATABASE", get_module_dbname ());
  write_class_int ("SCHEMA_ONLY", get_module_isschema());
  write_class_int ("NUMVARS", list_class_cnt);
  for (a = 0; a < list_class_cnt; a++)
    {
      v = list_class[a];
      write_variable_header (v);
    }
  CLASS_print_class_variable_type (allbuff);

}





/**
 *
 *
 * @param
 */
static void
write_variable_header (struct variable *v)
{
  /* struct name_list *ptr; */
  int a;
  int cnt;
  write_class_string ("NAME", v->names.names.names_val[0].name);
  /* ptr = v->names.next; */

  write_class_int ("TYPE", v->var_data.variable_type);
  write_class_char ("USER_SYSTEM", v->user_system);
  // write_class_int ("IS_ARRAY", v->is_array);
  write_class_string ("SRC_MODULE", v->src_module);


  if (v->arr_subscripts.arr_subscripts_len)
    {
      cnt = 0;

	cnt=v->arr_subscripts.arr_subscripts_len;

      write_class_int ("ARR_SUBSCRIPTS_CNT", cnt);

      for (a = 0; a < cnt; a++)
	{
	  if (v->arr_subscripts.arr_subscripts_val[a])
	    write_class_int ("ARR_SUBSCRIPT", v->arr_subscripts.arr_subscripts_val[a]);
	}
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_SIMPLE)
    {
      write_variable_simple (v);
      return;
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_RECORD)
    {
      write_variable_record (v);
      return;
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_OBJECT)
    {
      write_variable_object (v);
      return;
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_ASSOC)
    {
      write_variable_assoc (v);
      return;
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_CONSTANT)
    {
      write_variable_constant (v);
      return;
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_FUNCTION_DECLARE)
    {
      write_variable_function (v);
      return;
    }
  FPRINTF (stderr,"Warning - unknown variable type : %d\n", v->var_data.variable_type);
}


/**
 *
 *
 * @param
 */
static void
write_variable_simple (struct variable *v)
{
  write_class_int ("DATATYPE", v->var_data.variable_data_u.v_simple.datatype);
  write_class_int ("DIMENSIONS_1", v->var_data.variable_data_u.v_simple.dimensions[0]);
  write_class_int ("DIMENSIONS_2", v->var_data.variable_data_u.v_simple.dimensions[1]);
}



/**
 *
 *
 * @param
 */
static void
write_variable_linked (struct variable *v)
{
int a;
/*
  struct name_list *ptr;
  int cnt;
*/

  write_class_string ("LINKTABLE", v->var_data.variable_data_u.v_record.linked->tabname);


/*
  cnt = 1;
  ptr = v->var_data.variable_data_u.v_record.linked->col_list.next;
  while (ptr)
    {
      cnt++;
      ptr = ptr->next;
    }
*/



  write_class_int ("LINKCOLUMNS", v->var_data.variable_data_u.v_record.linked->col_list.names.names_len);

  for (a=0;a<v->var_data.variable_data_u.v_record.linked->col_list.names.names_len;a++) {
  	write_class_string ("LINKCOLUMN", v->var_data.variable_data_u.v_record.linked->col_list.names.names_val[a].name);
  }


}



/**
 *
 *
 * @param
 */
static void
write_variable_record (struct variable *v)
{
  int a;
#ifdef OLD
  write_class_int ("COUNT", v->var_data.variable_data_u.v_record.variables.variables_len);
  if (v->var_data.variable_data_u.v_record.variables.variables_len == 0)
    return;

  if (v->var_data.variable_data_u.v_record.linked == 0)
    {
      write_class_int ("LINKED", 0);
    }
  else
    {

      if (v->var_data.variable_data_u.v_record.linked->tabname)
	{
	  write_class_int ("LINKED", 1);
	  write_variable_linked (v);
	}
      else
	{
	  write_class_int ("LINKED", 0);
	}
    }


  for (a = 0; a < v->var_data.variable_data_u.v_record.variables.variables_len; a++)
    {
      write_variable_header (v->var_data.variable_data_u.v_record.variables.variables_val[a]);
    }
#endif
}



/**
 *
 *
 * @param
 */
static void
write_variable_object (struct variable *v)
{
  int a;
#ifdef OLD
  write_class_int ("COUNT", v->var_data.variable_data_u.v_record.variables.variables_len);
  if (v->var_data.variable_data_u.v_record.variables.variables_len == 0)
    return;

  if (v->var_data.variable_data_u.v_record.linked == 0)
    {
      write_class_int ("LINKED", 0);
    }
  else
    {

      if (v->var_data.variable_data_u.v_record.linked->tabname)
	{
	  write_class_int ("LINKED", 1);
	  write_variable_linked (v);
	}
      else
	{
	  write_class_int ("LINKED", 0);
	}
    }


  for (a = 0; a < v->var_data.variable_data_u.v_record.variables.variables_len; a++)
    {
      write_variable_header (v->var_data.variable_data_u.v_record.variables.variables_val[a]);
    }
	write_class_string("OBJECT_TYPE",v->var_data.variable_data_u.v_record.object_type);
#endif
}



/**
 *
 *
 * @param
 */
static void
write_variable_assoc (struct variable *v)
{
  struct variable *ptr;
  write_class_int ("SIZE", v->var_data.variable_data_u.v_assoc.size);
  write_class_int ("CHARSIZE", v->var_data.variable_data_u.v_assoc.char_size);
  ptr = v->var_data.variable_data_u.v_assoc.variables.variables_val[0];
  write_variable_header (ptr);

}


/**
 *
 *
 * @param
 */
static void
write_variable_constant (struct variable *v)
{

  write_class_int ("CONSTANT_TYPE", v->var_data.variable_data_u.v_const.consttype);

  if (v->var_data.variable_data_u.v_const.consttype == CONST_TYPE_INTEGER)
    {
      write_class_int ("CONSTANT_VALUE", v->var_data.variable_data_u.v_const.constant_data_u.data_i);
    }


  if (v->var_data.variable_data_u.v_const.consttype == CONST_TYPE_CHAR) 
    {
      write_class_string ("CONSTANT_VALUE", v->var_data.variable_data_u.v_const.constant_data_u.data_c);
    }
  if ( v->var_data.variable_data_u.v_const.consttype == CONST_TYPE_IDENT) {
      write_class_string ("CONSTANT_VALUE", v->var_data.variable_data_u.v_const.constant_data_u.data_ident);
	}

  if (v->var_data.variable_data_u.v_const.consttype == CONST_TYPE_FLOAT)
    {
      write_class_float ("CONSTANT_VALUE", v->var_data.variable_data_u.v_const.constant_data_u.data_f);
    }

}

static void
write_variable_function (struct variable *v)
{
}


int nline = 0;

int read_class (char *s, int is_parent)
{
  char *dbname;
  int is_schema;
  //int a;
  int pvars;
  int pid = 0;
  //extern struct variable **list_class;	/* Our List */
  struct variable np;
  struct variable *nptr;
  nline = 0;

#ifdef OLD
  class_variable_data = CLASS_get_variable (s);
  class_members = CLASS_get_members (s);

  if (find_dim(s) && !is_parent) return 1;

  if ((long) class_members != -1)
    {
      nline = 0;
    }
  else
    {
      if (strcmp (s, "default_object") != 0)
	{
	  FPRINTF (stderr,"Warning - unable to open class file for %s\n", s);
	}
      return 0;
    }


  read_class_string ("DATABASE", &dbname, 1);
  read_class_int ("SCHEMA_ONLY", &is_schema);

  if (strlen (dbname) > 0)
    {

	set_module_dbname(dbname, is_schema);
      	open_db (dbname);
    }

  A4GL_debug ("Adding parent record");

  read_class_int ("NUMVARS", &pvars);


  // We know that the first pvars will be the parent...

  if (pvars == 0)
    {
      return 1;
    }

  pvars--;



  if (is_parent )
    {
      // First - read our parent 

      if (pvars >= 0)
	{
	  int a;
	  list_class = acl_realloc (list_class, sizeof (struct variable *) * (pvars + 1 + list_class_cnt));
	  list_class_alloc += pvars;
	  if (list_class_cnt == 0)
	    {
	      list_class[0] = acl_malloc2 (sizeof (struct variable));
	      list_class[0]->var_data.variable_type = VARIABLE_TYPE_RECORD;
	      list_class[0]->names.names.names_val=malloc(sizeof(vname));
	      list_class[0]->names.names.names_len=0;
	      list_class[0]->names.names.names_val[0].name = acl_strdup ("this_class_c");
	      list_class[0]->user_system = 'U';
	      list_class[0]->scope = 'P';
	      //list_class[0]->is_array = 0;
	      list_class[0]->is_static = 0;
	      list_class[0]->is_extern = 0;
	      for (a = 0; a < MAX_ARR_SUB; a++)
		list_class[0]->arr_subscripts[a] = 0;
	      list_class[0]->src_module = acl_strdup ("IMPLICIT");
	      list_class[0]->var_data.variable_data_u.v_record.variables.variables_len = 0;
	      list_class[0]->var_data.variable_data_u.v_record.variables.variables_val = 0;

	      list_class[0]->var_data.variable_data_u.v_record.record_alloc = 0;
	      list_class[0]->var_data.variable_data_u.v_record.variables.variables_len = 0;

	    }
	  read_variable_header (&np);



	  list_class[0]->var_data.variable_data_u.v_record.record_alloc++;
	  list_class[0]->var_data.variable_data_u.v_record.variables.variables_len++;
	  pid = list_class[0]->var_data.variable_data_u.v_record.variables.variables_len - 1;
	  list_class[0]->var_data.variable_data_u.v_record.variables.variables_val = acl_realloc (list_class[0]->var_data.variable_data_u.v_record.variables.variables_val,
		     sizeof (struct variable *) *
		     list_class[0]->var_data.variable_data_u.v_record.record_alloc);
	  list_class[0]->var_data.variable_data_u.v_record.linked = 0;



	  list_class[0]->var_data.variable_data_u.v_record.variables.variables_val[pid] =
	    acl_malloc2 (sizeof (struct variable));

	  memcpy (list_class[0]->var_data.variable_data_u.v_record.variables.variables_val[pid], &np,
		  sizeof (struct variable));


	  if (pvars >= 1)
	    {
	      for (a = 0; a < pvars; a++)
		{
		  list_class[a + list_class_cnt] =
		    acl_malloc2 (sizeof (struct variable));
		  memset (list_class[a + list_class_cnt], 0,
			  sizeof (struct variable));
		  read_variable_header (list_class[a + list_class_cnt]);
		  if (list_class[a + list_class_cnt]->var_data.variable_type == VARIABLE_TYPE_FUNCTION_DECLARE)
		    {
		      char buff[1024];
		      SPRINTF2 (buff, "%s.%s", s, list_class[a + list_class_cnt]->names.names.names_val[0].name);
		      list_class[a + list_class_cnt]->names.names.names_val[0].name =
			acl_strdup (buff);

		    }
		}

	    }
	  list_class_cnt += pvars;
	  list_class_alloc = list_class_cnt;

	}
      else
	{
			/* Does nothing */
	}

      /* dump_variable_records (list_class, list_class_cnt, 0); */

    } else {
	//int a;
	//struct variable v;
	char buff[256];
	int sz;

	sz=class_call(s,"aclfglclass__sizeof",0);

	read_variable_header (&np);


	if (strcmp(np.names.names.names_val[0].name,"parent")!=0) {
		a4gl_yyerror("Not set to parent in class");
		return 0;
	}




	if (np.var_data.variable_type!=VARIABLE_TYPE_RECORD) {
		a4gl_yyerror("Not a record in class");
		return 0;
	}



	push_scope();
	SPRINTF1(buff,"%d",sz);
	set_current_variable_scope('T');
	push_name(s,0);
	push_object(s);
	//for (a=0;class_variable_data[a];a++) { dim_add (int a, char *s1, char *s2, char *s3) }
	//push_name("_object_type",0);
	//push_type("-","4",0);
	//push_name("object_type",0);
	//push_type("long","4",0);
	push_name("object_space",0);
	push_type("char",buff,0);
	pop_record();
	pop_scope();
	nptr=find_dim(s);
	//nptr->data.variables=acl_realloc
	
	//nptr->v_record,np;



  	//class_members = CLASS_get_members (s);
	//
#ifdef DEBUG

	if ((long) class_members==-1 || (long) class_members==0) ; 
	else {
		for (a=0;class_members[a];a++) {
			PRINTF("MEMBER : %s\n",class_members[a]);
		}
	}

	if ((long) class_variable_data==-1 || (long) class_variable_data==0) ; 
	else {
		for (a=0;class_variable_data[a];a++) {
			PRINTF("VARIABLES : %s\n",class_variable_data[a]);
		}
	}

#endif


	//dim_set_name(s);
	//dim_push_record();
	//dim_push_name("_object_data",""); dim_push_type("char","100","");
	//dim_push_name("_object_type",""); dim_push_type("long","4","");
	//dim_pop_record();
    }
#endif
  return 1;
}


void
class_set_parent (void)
{
  //int a;
  //struct variable *v;
  //int s;


  // Does nothing ?
}


/**
 *
 *
 * @param
 */
static void
read_class_int (char *name, int *val)
{
  char buff[256];
  char buff2[256];

  SPRINTF1 (buff, "%s=%%d\n", name);
  *val = 0;
  strcpy (buff2, class_variable_data[nline++]);
  A4GL_debug ("buff2=%s", buff2);

  if (sscanf (buff2, buff, val) != 1)
    {
      a4gl_yyerror ("Error in .glb file (int) - is it an old version ?");
    }
}

/**
 *
 *
 * @param
 */
static void
read_class_string (char *name, char **val, int alloc)
{
  char buff[256];
  int a;
  char buff2[2000];
  char buff3[2000];
  strcpy (buff3, class_variable_data[nline++]);
  A4GL_debug ("buff3=%s", buff3);
  strcpy (buff2, "");
  SPRINTF1 (buff, "%s=%%s\n", name);

  a = sscanf (buff3, buff, buff2);
  if (a == 0 && strcmp (buff, buff3) != 0)
    {
      a4gl_yyerror ("Error in .glb file (string)- is it an old version ?");
    }

  if (alloc)
    {
      *val = acl_strdup (buff2);
    }
  else
    {
      strcpy ((char *) val, buff2);
    }

}

/**
 *
 *
 * @param
 */
static void
read_class_char (char *name, char *val)
{
  char buff[256];
  char buff3[256];

  strcpy (buff3, class_variable_data[nline++]);
  A4GL_debug ("buff3=%s", buff3);
  SPRINTF1 (buff, "%s=%%c\n", name);
  if (sscanf (buff3, buff, val) != 1)
    {
      a4gl_yyerror ("Error in .glb file (char)- is it an old version ?");
    }
}

/**
 *
 *
 * @param
 */
static void
read_class_float (char *name, double *val)
{
  char buff[256];
  char buff3[256];

  strcpy (buff3, class_variable_data[nline++]);
  A4GL_debug ("buff3=%s", buff3);
  SPRINTF1 (buff, "%s=%%lf\n", name);
  if (sscanf (buff3, buff, val) != 1)
    {
      a4gl_yyerror ("Error in .glb file (float)- is it an old version ?");

    }

}



/**
 *
 *
 * @param
 */
static void
read_variable_header (struct variable *v)
{
/*struct name_list *ptr;*/
  int a;
  int cnt;
  int vt;
v->names.names.names_val=malloc(sizeof(vname));
v->names.names.names_len=1;

 v->names.names.names_val[0].alias=0;
  memset(v,0, sizeof(struct variable));
  read_class_string ("NAME", &v->names.names.names_val[0].name, 1);

  if (strcmp (v->names.names.names_val[0].name, "THIS") == 0)
    {
      v->names.names.names_val[0].name = acl_strdup ("parent");
    }

#ifdef DEBUG
  A4GL_debug ("Read variable : %s", v->names.names.names_val[0].name);
#endif
  v->is_static = 0;

  read_class_int ("TYPE", &vt);
  v->var_data.variable_type=vt;
  read_class_char ("USER_SYSTEM", &v->user_system);
  //read_class_int ("IS_ARRAY", &v->is_array);
  read_class_string ("SRC_MODULE", &v->src_module, 1);
  v->scope = 'P';

v->arr_subscripts.arr_subscripts_len=0;
v->arr_subscripts.arr_subscripts_val=0;

      read_class_int ("ARR_SUBSCRIPTS_CNT", &cnt);

	v->arr_subscripts.arr_subscripts_len=cnt;
	if (cnt) {
		v->arr_subscripts.arr_subscripts_val=malloc(cnt*sizeof (v->arr_subscripts.arr_subscripts_val[0]));
	
      		for (a = 0; a < cnt; a++)
		{
	  	read_class_int ("ARR_SUBSCRIPT", &v->arr_subscripts.arr_subscripts_val[a]);
		}
	}

  if (v->var_data.variable_type == VARIABLE_TYPE_SIMPLE)
    {
      read_variable_simple (v);
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_RECORD)
    {
      read_variable_record (v);
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_OBJECT)
    {
      read_variable_object (v);
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_ASSOC)
    {
      read_variable_assoc (v);
    }
  if (v->var_data.variable_type == VARIABLE_TYPE_CONSTANT)
    {
      read_variable_constant (v);
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_FUNCTION_DECLARE)
    {
      read_variable_function (v);
    }

}

/**
 *
 *
 * @param
 */
static void
read_variable_simple (struct variable *v)
{
  read_class_int ("DATATYPE", &v->var_data.variable_data_u.v_simple.datatype);
  read_class_int ("DIMENSIONS_1", &v->var_data.variable_data_u.v_simple.dimensions[0]);
  read_class_int ("DIMENSIONS_2", &v->var_data.variable_data_u.v_simple.dimensions[1]);
}

/**
 *
 *
 * @param
 */
static void
read_variable_linked (struct variable *v)
{
  int cnt;
  int a;

  read_class_string ("LINKTABLE", &v->var_data.variable_data_u.v_record.linked->tabname, 1);
  read_class_int ("LINKCOLUMNS", &cnt);

  v->var_data.variable_data_u.v_record.linked->col_list.names.names_len=cnt;
  v->var_data.variable_data_u.v_record.linked->col_list.names.names_val=malloc(sizeof(vname)*cnt);
  v->var_data.variable_data_u.v_record.linked->col_list.names.names_val[0].alias=0;

  for (a=0;a<cnt;a++) {
  	read_class_string ("LINKCOLUMN", &v->var_data.variable_data_u.v_record.linked->col_list.names.names_val[a].name, 1);
  }


}

/**
 *
 *
 * @param
 */
static void
read_variable_record (struct variable *v)
{
  int a;
  int is_linked;
#ifdef OLD
  v->var_data.variable_data_u.v_record.linked = 0;
  read_class_int ("COUNT", &v->var_data.variable_data_u.v_record.variables.variables_len);
  if (v->var_data.variable_data_u.v_record.variables.variables_len == 0)
    {

      return;
    }

  read_class_int ("LINKED", &is_linked);


  if (is_linked)
    {
      v->var_data.variable_data_u.v_record.linked = acl_malloc2 (sizeof (struct linked_variable));
      read_variable_linked (v);
    }

  v->var_data.variable_data_u.v_record.variables.variables_val =
    acl_malloc2 (sizeof (struct variable *) * v->var_data.variable_data_u.v_record.variables.variables_len + 1);

  for (a = 0; a < v->var_data.variable_data_u.v_record.variables.variables_len; a++)
    {
      v->var_data.variable_data_u.v_record.variables.variables_val[a] = acl_malloc2 (sizeof (struct variable));
      read_variable_header (v->var_data.variable_data_u.v_record.variables.variables_val[a]);
    }
#endif
}


/**
 *
 *
 * @param
 */
static void
read_variable_object (struct variable *v) {
int a;
int is_linked;
char buff[255];
#ifdef OLD
  v->var_data.variable_data_u.v_record.linked = 0;
  read_class_int ("COUNT", &v->var_data.variable_data_u.v_record.variables.variables_len);
  if (v->var_data.variable_data_u.v_record.variables.variables_len == 0)
    {

      return;
    }

  read_class_int ("LINKED", &is_linked);


  if (is_linked)
    {
      v->var_data.variable_data_u.v_record.linked = acl_malloc2 (sizeof (struct linked_variable));
      read_variable_linked (v);
    }

  v->var_data.variable_data_u.v_record.variables.variables_val =
    acl_malloc2 (sizeof (struct variable *) * v->var_data.variable_data_u.v_record.variables.variables_len + 1);

  for (a = 0; a < v->var_data.variable_data_u.v_record.variables.variables_len; a++)
    {
      v->var_data.variable_data_u.v_record.variables.variables_val[a] = acl_malloc2 (sizeof (struct variable));
      read_variable_header (v->var_data.variable_data_u.v_record.variables.variables_val[a]);
    }

	read_class_string ("OBJECT_TYPE", (char **)buff,255);
	v->var_data.variable_data_u.v_record.object_type=acl_strdup(buff);
#endif
}


/**
 *
 *
 * @param
 */
static void
read_variable_assoc (struct variable *v)
{
  struct variable *ptr;

  read_class_int ("SIZE", &v->var_data.variable_data_u.v_assoc.size);
  read_class_int ("CHARSIZE", &v->var_data.variable_data_u.v_assoc.char_size);
  v->var_data.variable_data_u.v_assoc.variables.variables_val = acl_malloc2 (sizeof (struct variable *) * 1);
  ptr = v->var_data.variable_data_u.v_assoc.variables.variables_val[0];
  read_variable_header (ptr);
}

static void
read_variable_function (struct variable *v)
{
/* Does nothing - reserved for future use...*/
}



/**
 *
 *
 * @param
 */
static void
read_variable_constant (struct variable *v)
{
int a;

  read_class_int ("CONSTANT_TYPE", &a);
  v->var_data.variable_data_u.v_const.consttype=a;

  if (v->var_data.variable_data_u.v_const.consttype == CONST_TYPE_INTEGER)
    {
      read_class_int ("CONSTANT_VALUE", &v->var_data.variable_data_u.v_const.constant_data_u.data_i);
    }

  if (v->var_data.variable_data_u.v_const.consttype == CONST_TYPE_CHAR)
    {
      read_class_string ("CONSTANT_VALUE", &v->var_data.variable_data_u.v_const.constant_data_u.data_c, 1);
    }

  if (v->var_data.variable_data_u.v_const.consttype == CONST_TYPE_IDENT)
    {
      read_class_string ("CONSTANT_VALUE", &v->var_data.variable_data_u.v_const.constant_data_u.data_ident, 1);
    }

  if (v->var_data.variable_data_u.v_const.consttype == CONST_TYPE_FLOAT)
    {
      read_class_float ("CONSTANT_VALUE", &v->var_data.variable_data_u.v_const.constant_data_u.data_f);
    }

}


char *
rm_class_copy (char *s)
{
  static char buff[1024];
  char *ptr = 0;
  if (strncmp (s, "CLASS_COPY->", 12) != 0)
    return s;
  strcpy (buff, &s[12]);
  ptr = buff;
  return ptr;
  while (strncmp (s, "parent", 6) == 0)
    ptr += 6;
  return ptr;
}



int isclassvariable(char *s) {
	int dtype;
	int size;
	int vval;
	struct variable *ptr;

	vval=find_variable (s, &dtype, &size, 0, &ptr);

	if (vval!=-2) {
		return 0; // We're expecting a record/object
	}

	if (ptr->var_data.variable_type != VARIABLE_TYPE_OBJECT) {
		return 0; // We're expecting an object
	}

	return 1;
}

int isclassmember(char *s,char *f) {
	int dtype;
	int size;
	int vval;
	int a;
	struct variable *ptr;

	vval=find_variable (s, &dtype, &size, 0, &ptr);

	if (vval!=-2) {
		return 0; // We're expecting a record/object
	}
	if (ptr->var_data.variable_type != VARIABLE_TYPE_OBJECT) {
		return 0; // We're expecting an object
	}

	//
	
  	class_members = CLASS_get_members (s);


	// Second - is this a method of a  'superclass'
	if ((long) class_members==-1 || (long) class_members==0) ; 
	else {
		for (a=0;class_members[a];a++) {if (A4GL_aubit_strcasecmp(f,class_members[a])==0) return 1;}
	}
	return 0;
}

void add_class_module_entry(void) {
	struct module_entry *e;
	e=new_module_entry(E_MET_CLASS_DEFINITION);
	memcpy(&e->module_entry_u.class_definition, this_class,sizeof(struct s_class_definition));
	add_module_entry(e);
	this_class=0;
}

void add_class_entry(struct module_entry *e) {
	this_class->class_entries.class_entries_len++;
	this_class->class_entries.class_entries_val=realloc(this_class->class_entries.class_entries_val, sizeof(struct module_entry *)* this_class->class_entries.class_entries_len);
	this_class->class_entries.class_entries_val[this_class->class_entries.class_entries_len-1]=e;
}

void new_class(char *cname, char *pname) {
	this_class=malloc(sizeof(struct s_class_definition));
	/* this_class->classname=strdup(cname);
	this_class->parentname=strdup(pname); */
	this_class->public_variables.variables.variables_len=0;
	this_class->private_variables.variables.variables_len=0;
	this_class->class_entries.class_entries_len=0;
	this_class->class_entries.class_entries_val=0;
}


/* ================================ EOF =================================== */
