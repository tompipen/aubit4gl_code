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
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: class.c,v 1.13 2005-11-21 18:29:37 mikeaubury Exp $
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
  sprintf (tmpbuff, "%s=%d\n", name, val);
  do_append ();
}


int 
class_call(char *s,char *f,int args) {
char buff[512];
char *fname;
	strcpy(buff,s);
	strcat(buff,acl_getenv("A4GL_DLL_EXT"));
	fname=A4GL_fullpath_classpath(buff);
	printf("fname=%p (%s)\n",fname,buff);
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
  sprintf (tmpbuff, "%s=%s\n", name, buff);
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
  sprintf (tmpbuff, "%s=%c\n", name, val);
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
  sprintf (tmpbuff, "%s=%f\n", name, val);
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
  extern int is_schema;
  extern int list_class_cnt;
  extern struct variable **list_class;	/* Our List */

  write_class_string ("DATABASE", get_hdrdbname ());
  write_class_int ("SCHEMA_ONLY", is_schema);
  write_class_int ("NUMVARS", list_class_cnt);
  //printf ("DC\n");
  for (a = 0; a < list_class_cnt; a++)
    {
      v = list_class[a];
      write_variable_header (v);
    }
  //printf ("EDC\n");
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
  struct name_list *ptr;
  int a;
  int cnt;
  write_class_string ("NAME", v->names.name);
  ptr = v->names.next;

  write_class_int ("TYPE", v->variable_type);
  write_class_char ("USER_SYSTEM", v->user_system);
  write_class_int ("IS_ARRAY", v->is_array);
  write_class_string ("SRC_MODULE", v->src_module);


  if (v->is_array)
    {
      cnt = 0;
      for (a = 0; a < MAX_ARR_SUB; a++)
	{
	  if (v->arr_subscripts[a])
	    cnt++;
	}
      write_class_int ("ARR_SUBSCRIPTS_CNT", cnt);

      for (a = 0; a < cnt; a++)
	{
	  if (v->arr_subscripts[a])
	    write_class_int ("ARR_SUBSCRIPT", v->arr_subscripts[a]);
	}
    }

  if (v->variable_type == VARIABLE_TYPE_SIMPLE)
    {
      write_variable_simple (v);
      return;
    }

  if (v->variable_type == VARIABLE_TYPE_RECORD)
    {
      write_variable_record (v);
      return;
    }

  if (v->variable_type == VARIABLE_TYPE_OBJECT)
    {
      write_variable_object (v);
      return;
    }

  if (v->variable_type == VARIABLE_TYPE_ASSOC)
    {
      write_variable_assoc (v);
      return;
    }

  if (v->variable_type == VARIABLE_TYPE_CONSTANT)
    {
      write_variable_constant (v);
      return;
    }

  if (v->variable_type == VARIABLE_TYPE_FUNCTION_DECLARE)
    {
      write_variable_function (v);
      return;
    }
  printf ("Warning - unknown variable type : %d\n", v->variable_type);
}


/**
 *
 *
 * @param
 */
static void
write_variable_simple (struct variable *v)
{
  write_class_int ("DATATYPE", v->data.v_simple.datatype);
  write_class_int ("DIMENSIONS_1", v->data.v_simple.dimensions[0]);
  write_class_int ("DIMENSIONS_2", v->data.v_simple.dimensions[1]);
}



/**
 *
 *
 * @param
 */
static void
write_variable_linked (struct variable *v)
{
  struct name_list *ptr;
  int cnt;

  write_class_string ("LINKTABLE", v->data.v_record.linked->tabname);



  cnt = 1;
  ptr = v->data.v_record.linked->col_list.next;
  while (ptr)
    {
      cnt++;
      ptr = ptr->next;
    }



  write_class_int ("LINKCOLUMNS", cnt);

  write_class_string ("LINKCOLUMN", v->data.v_record.linked->col_list.name);

  ptr = v->data.v_record.linked->col_list.next;
  while (ptr)
    {
      write_class_string ("LINKCOLUMN", ptr->name);
      ptr = ptr->next;
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
  //printf("Count=%d\n", v->data.v_record.record_cnt);
  //printf ("VR\n");
  write_class_int ("COUNT", v->data.v_record.record_cnt);
  if (v->data.v_record.record_cnt == 0)
    return;

  if (v->data.v_record.linked == 0)
    {
      write_class_int ("LINKED", 0);
    }
  else
    {

      if (v->data.v_record.linked->tabname)
	{
	  write_class_int ("LINKED", 1);
	  write_variable_linked (v);
	}
      else
	{
	  write_class_int ("LINKED", 0);
	}
    }


  for (a = 0; a < v->data.v_record.record_cnt; a++)
    {
      //printf ("Writing %s ->%d of %d\n", v->names.name, a, v->data.v_record.record_cnt);
      //fflush(stdout);
      write_variable_header (v->data.v_record.variables[a]);
    }
  //printf ("EVR\n");
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
  //printf("Count=%d\n", v->data.v_record.record_cnt);
  //printf ("VR\n");
  write_class_int ("COUNT", v->data.v_record.record_cnt);
  if (v->data.v_record.record_cnt == 0)
    return;

  if (v->data.v_record.linked == 0)
    {
      write_class_int ("LINKED", 0);
    }
  else
    {

      if (v->data.v_record.linked->tabname)
	{
	  write_class_int ("LINKED", 1);
	  write_variable_linked (v);
	}
      else
	{
	  write_class_int ("LINKED", 0);
	}
    }


  for (a = 0; a < v->data.v_record.record_cnt; a++)
    {
      //printf ("Writing %s ->%d of %d\n", v->names.name, a, v->data.v_record.record_cnt);
      //fflush(stdout);
      write_variable_header (v->data.v_record.variables[a]);
    }
	write_class_string("OBJECT_TYPE",v->data.v_record.object_type);
  //printf ("EVR\n");
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
  write_class_int ("SIZE", v->data.v_assoc.size);
  write_class_int ("CHARSIZE", v->data.v_assoc.char_size);
  ptr = v->data.v_assoc.variables[0];
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

  write_class_int ("CONSTANT_TYPE", v->data.v_const.consttype);

  if (v->data.v_const.consttype == CONST_TYPE_INTEGER)
    {
      write_class_int ("CONSTANT_VALUE", v->data.v_const.data.data_i);
    }


  if (v->data.v_const.consttype == CONST_TYPE_CHAR
      || v->data.v_const.consttype == CONST_TYPE_IDENT)
    {
      write_class_string ("CONSTANT_VALUE", v->data.v_const.data.data_c);
    }

  if (v->data.v_const.consttype == CONST_TYPE_FLOAT)
    {
      write_class_float ("CONSTANT_VALUE", v->data.v_const.data.data_f);
    }

}

static void
write_variable_function (struct variable *v)
{
  //printf ("function : %s\n", v->names.name);
}


int nline = 0;

int
read_class (char *s, int is_parent)
{
  char *dbname;
  int is_schema;
  //int a;
  int pvars;
  int pid = 0;
  extern struct variable **list_class;	/* Our List */
  extern int list_class_cnt;	/* Our List */
  extern int list_class_alloc;	/* Our List */
  struct variable np;
  struct variable *nptr;
  nline = 0;

  printf("read_class : %s - is_parent=%d\n",s,is_parent);

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
	  printf ("Warning - unable to open class file for %s\n", s);
	}
      return 0;
    }


  read_class_string ("DATABASE", &dbname, 1);
  read_class_int ("SCHEMA_ONLY", &is_schema);

  if (strlen (dbname) > 0)
    {
      set_hdrdbname (dbname);
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

	printf("----------------\n");
      if (pvars >= 0)
	{
	  int a;
	  //printf("Allocating space for %d entries\n",pvars + 1+list_class_cnt);
	  list_class = acl_realloc (list_class, sizeof (struct variable *) * (pvars + 1 + list_class_cnt));
	  list_class_alloc += pvars;
	  if (list_class_cnt == 0)
	    {
	      list_class[0] = acl_malloc2 (sizeof (struct variable));
	      list_class[0]->variable_type = VARIABLE_TYPE_RECORD;
	      list_class[0]->names.name = acl_strdup ("this_class_c");
	      list_class[0]->names.next = 0;
	      list_class[0]->user_system = 'U';
	      list_class[0]->scope = 'P';
	      list_class[0]->is_array = 0;
	      list_class[0]->is_static = 0;
	      list_class[0]->is_extern = 0;
	      for (a = 0; a < MAX_ARR_SUB; a++)
		list_class[0]->arr_subscripts[a] = 0;
	      list_class[0]->src_module = acl_strdup ("IMPLICIT");
	      list_class[0]->data.v_record.variables = 0;
	      list_class[0]->data.v_record.record_alloc = 0;
	      list_class[0]->data.v_record.record_cnt = 0;

	    }
	  read_variable_header (&np);



	  list_class[0]->data.v_record.record_alloc++;
	  list_class[0]->data.v_record.record_cnt++;
	  pid = list_class[0]->data.v_record.record_cnt - 1;
	  printf ("pid=%d\n", list_class[0]->data.v_record.record_cnt - 1);
	  list_class[0]->data.v_record.variables =
	    acl_realloc (list_class[0]->data.v_record.variables,
		     sizeof (struct variable *) *
		     list_class[0]->data.v_record.record_alloc);
	  list_class[0]->data.v_record.linked = 0;



	  list_class[0]->data.v_record.variables[pid] =
	    acl_malloc2 (sizeof (struct variable));

//printf("THISCNT= %d\n",list_class[0]->data.v_record.record_cnt);
	  memcpy (list_class[0]->data.v_record.variables[pid], &np,
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
		  if (list_class[a + list_class_cnt]->variable_type == 4)
		    {
		      char buff[1024];
		      sprintf (buff, "%s.%s", s, list_class[a + list_class_cnt]->names.name);
		      list_class[a + list_class_cnt]->names.name =
			acl_strdup (buff);

		    }
		}

	    }
	  list_class_cnt += pvars;
	  list_class_alloc = list_class_cnt;

	}
      else
	{
	  printf ("Nothing to read in...\n");
	}

      dump_variable_records (list_class, list_class_cnt, 0);

    } else {
	int a;
	//struct variable v;
	char buff[256];
	int sz;

        printf ("Reading %d list_class_cnt=%d\n", pvars, list_class_cnt);
       //for (a = 0; a < list_class_cnt; a++) { printf ("    %s \n", list_class[a]->names.name); }


	printf("dim_Set_name : %s\n",s);
	sz=class_call(s,"aclfglclass__sizeof",0);
	printf("sz=%d\n",sz);

	read_variable_header (&np);


	if (strcmp(np.names.name,"parent")!=0) {
		a4gl_yyerror("Not set to parent in class");
		return 0;
	}


	printf("variable_type=%d src_module=%s\n",np.variable_type,np.src_module);


	printf("%s == THIS \n",np.names.name);
	if (np.variable_type!=VARIABLE_TYPE_RECORD) {
		a4gl_yyerror("Not a record in class");
		return 0;
	}



	push_scope();
	sprintf(buff,"%d",sz);
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


	A4GL_pause_execution();

  	//class_members = CLASS_get_members (s);

	printf("class_members=%p\n",class_members);
	if ((long) class_members==-1 || (long) class_members==0) ; 
	else {
		for (a=0;class_members[a];a++) {
			printf("MEMBER : %s\n",class_members[a]);
		}
	}
	printf("class_variable=%p\n",class_variable_data);
	if ((long) class_variable_data==-1 || (long) class_variable_data==0) ; 
	else {
		for (a=0;class_variable_data[a];a++) {
			//printf("VARIABLES : %s\n",class_variable_data[a]);
		}
	}




	//dim_set_name(s);
	//dim_push_record();
	//dim_push_name("_object_data",""); dim_push_type("char","100","");
	//dim_push_name("_object_type",""); dim_push_type("long","4","");
	//dim_pop_record();
    }
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

  sprintf (buff, "%s=%%d\n", name);
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
  sprintf (buff, "%s=%%s\n", name);

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
  sprintf (buff, "%s=%%c\n", name);
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
  sprintf (buff, "%s=%%lf\n", name);
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
 v->names.alias=0;
  memset(v,0, sizeof(struct variable));
  read_class_string ("NAME", &v->names.name, 1);
  if (strcmp (v->names.name, "THIS") == 0)
    {
      v->names.name = acl_strdup ("parent");
    }
  //printf ("-> %s\n", v->names.name);
  v->names.next = 0;
#ifdef DEBUG
  A4GL_debug ("Read variable : %s", v->names.name);
#endif
  v->is_static = 0;
  read_class_int ("TYPE", &v->variable_type);
  //printf ("Type=%d\n", v->variable_type);
  read_class_char ("USER_SYSTEM", &v->user_system);
  read_class_int ("IS_ARRAY", &v->is_array);
  read_class_string ("SRC_MODULE", &v->src_module, 1);
  v->scope = 'P';

  for (a = 0; a < MAX_ARR_SUB; a++)
    {
      v->arr_subscripts[a] = 0;
    }

  if (v->is_array)
    {
      read_class_int ("ARR_SUBSCRIPTS_CNT", &cnt);

      for (a = 0; a < cnt; a++)
	{
	  read_class_int ("ARR_SUBSCRIPT", &v->arr_subscripts[a]);
	}
    }

  if (v->variable_type == VARIABLE_TYPE_SIMPLE)
    {
      read_variable_simple (v);
    }

  if (v->variable_type == VARIABLE_TYPE_RECORD)
    {
      read_variable_record (v);
    }

  if (v->variable_type == VARIABLE_TYPE_OBJECT)
    {
      read_variable_object (v);
    }

  if (v->variable_type == VARIABLE_TYPE_ASSOC)
    {
      read_variable_assoc (v);
    }
  if (v->variable_type == VARIABLE_TYPE_CONSTANT)
    {
      read_variable_constant (v);
    }

  if (v->variable_type == VARIABLE_TYPE_FUNCTION_DECLARE)
    {
      //printf ("READ FUNCTION\n");
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
  read_class_int ("DATATYPE", &v->data.v_simple.datatype);
  read_class_int ("DIMENSIONS_1", &v->data.v_simple.dimensions[0]);
  read_class_int ("DIMENSIONS_2", &v->data.v_simple.dimensions[1]);
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
  struct name_list *ptr;

  read_class_string ("LINKTABLE", &v->data.v_record.linked->tabname, 1);
  read_class_int ("LINKCOLUMNS", &cnt);
  read_class_string ("LINKCOLUMN",
		     &v->data.v_record.linked->col_list.name, 1);

  ptr = &v->data.v_record.linked->col_list;

  while (cnt > 1)
    {
      ptr->next = acl_malloc2 (sizeof (struct name_list));
      ptr = ptr->next;
      ptr->next = 0;
      read_class_string ("LINKCOLUMN", &ptr->name, 1);
      cnt--;
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
  v->data.v_record.linked = 0;
  read_class_int ("COUNT", &v->data.v_record.record_cnt);
  if (v->data.v_record.record_cnt == 0)
    {

      return;
    }

  read_class_int ("LINKED", &is_linked);

  //printf("Read record : %d %d\n",v->data.v_record.record_cnt, is_linked);

  if (is_linked)
    {
      v->data.v_record.linked = acl_malloc2 (sizeof (struct linked_variable));
      read_variable_linked (v);
    }

  v->data.v_record.variables =
    acl_malloc2 (sizeof (struct variable *) * v->data.v_record.record_cnt + 1);

  for (a = 0; a < v->data.v_record.record_cnt; a++)
    {
      v->data.v_record.variables[a] = acl_malloc2 (sizeof (struct variable));
      read_variable_header (v->data.v_record.variables[a]);
    }

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

  v->data.v_record.linked = 0;
  read_class_int ("COUNT", &v->data.v_record.record_cnt);
  if (v->data.v_record.record_cnt == 0)
    {

      return;
    }

  read_class_int ("LINKED", &is_linked);

  //printf("Read record : %d %d\n",v->data.v_record.record_cnt, is_linked);

  if (is_linked)
    {
      v->data.v_record.linked = acl_malloc2 (sizeof (struct linked_variable));
      read_variable_linked (v);
    }

  v->data.v_record.variables =
    acl_malloc2 (sizeof (struct variable *) * v->data.v_record.record_cnt + 1);

  for (a = 0; a < v->data.v_record.record_cnt; a++)
    {
      v->data.v_record.variables[a] = acl_malloc2 (sizeof (struct variable));
      read_variable_header (v->data.v_record.variables[a]);
    }

	read_class_string ("OBJECT_TYPE", (char **)buff,255);
	v->data.v_record.object_type=acl_strdup(buff);

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

  read_class_int ("SIZE", &v->data.v_assoc.size);
  read_class_int ("CHARSIZE", &v->data.v_assoc.char_size);
  v->data.v_assoc.variables = acl_malloc2 (sizeof (struct variable *) * 1);
  ptr = v->data.v_assoc.variables[0];
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
  read_class_int ("CONSTANT_TYPE", &v->data.v_const.consttype);

  if (v->data.v_const.consttype == CONST_TYPE_INTEGER)
    {
      read_class_int ("CONSTANT_VALUE", &v->data.v_const.data.data_i);
    }

  if (v->data.v_const.consttype == CONST_TYPE_CHAR)
    {
      read_class_string ("CONSTANT_VALUE", &v->data.v_const.data.data_c, 1);
    }

  if (v->data.v_const.consttype == CONST_TYPE_IDENT)
    {
      read_class_string ("CONSTANT_VALUE", &v->data.v_const.data.data_c, 1);
    }

  if (v->data.v_const.consttype == CONST_TYPE_FLOAT)
    {
      read_class_float ("CONSTANT_VALUE", &v->data.v_const.data.data_f);
    }

}


char *
rm_class_copy (char *s)
{
  static char buff[1024];
  char *ptr = 0;
//printf("Cleaning %s\n",s);
  if (strncmp (s, "CLASS_COPY->", 12) != 0)
    return s;
  strcpy (buff, &s[12]);
  ptr = buff;
//printf("used to return : %s as clean\n",ptr);
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

	if (ptr->variable_type != VARIABLE_TYPE_OBJECT) {
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
	if (ptr->variable_type != VARIABLE_TYPE_OBJECT) {
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


/* ================================ EOF =================================== */
