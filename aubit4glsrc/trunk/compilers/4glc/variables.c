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
# $Id: variables.c,v 1.93 2008-02-11 17:13:07 mikeaubury Exp $
#
*/

/**
 * @file
 *
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_4glc_int.h"
#include "variables.h"
#include <ctype.h>


/* CONFIGURABLE...*/
#define RECORD_LEVELS 128
/* */

extern int token_read_on_line;
extern char *outputfilename;
//#define PRINT_CONSTANTS
char scopes[200];
int scopes_cnt = 0;
//int has_fbind(char *s) ;


int class_cnt = 0;




/******************************************************************************/
/* Prototypes of static functions in this module...*/
static int has_name (struct vname_name_list *namelist, char *name);
static char get_variable_user_system (void);
static struct variable *make_constant (char *name, char *value,
				       char *int_or_char);
static void initialize_v (void);
static void set_arr_subscripts (char *s, int record_cnt);
static int add_to_scope (int record_cnt, int unroll);
//static void dump_variable_records (struct variable **v, int cnt, int lvl);
static struct variable *find_variable_in (char *s, struct variable **list, int cnt);
//struct variable * find_variable_vu_in (char *errbuff, struct variable_usage *vu, struct variable **list, int cnt);

//struct variable * find_variable_vu_in (char *errbuff, struct variable_usage *vu, struct variable **list, int cnt,int err_if_whole_array);

static char get_current_variable_scope (void);

void make_arr_str (char *s, struct variable *v);
void A4GL_strip_bracket (char *s);
char *rettype_integer (int n);
static char * describe_record(struct record_variable *v_record) ;
static struct record_list *add_to_record_list (struct record_list **list_ptr,
					       char *prefix_buff,
					       struct variable *v,
					       char bindtype);
int is_valid_vname(struct variable *v, char scope);
void make_function (char *name, int record_cnt);
//int has_fbind(char *s) ;
int chk_already_defined(char *s, char scope);

int is_system_variable (char *s);

//char find_variable_scope (char *s_in);
//struct variable *find_dim(char *s);

void print_class_variables (void);
//void dump_variable_records (struct variable **v, int cnt, int lvl);
void set_last_class_var (char *s);
/******************************************************************************/

//char *A4GL_unscope(char *s);
int A4GL_findex (char *str, char c);
/*void dump_gvars (void);*/
//void set_yytext (char *s);
//int isin_command (char *s);
//char *rettype (char *s);
int last_record_cnt = 0;
static char last_class_var[1024];
extern int nreturn_values;


#define ASSOC_INTERNAL "Internal"

extern int in_define;

/* Are we setting User variables or System Variables ?*/
char system_or_user = '-';


/* Lists for our variables in each scope...*/
struct variable **list_global = 0;	/* Our List */
int list_global_cnt = 0;	/* Number used in our list */
int list_global_alloc = 0;	/* Space allocated for our list */


struct variable **list_imported_global = 0;	/* Our List */
int list_imported_global_cnt = 0;	/* Number used in our list */
int list_imported_global_alloc = 0;	/* Space allocated for our list */



struct variable **list_external_global = 0;	/* Our List */
int list_external_global_cnt = 0;	/* Number used in our list */
int list_external_global_alloc = 0;	/* Space allocated for our list */

struct variable **list_module = 0;
int list_module_cnt = 0;
int list_module_alloc = 0;

struct variable **list_class = 0;
int list_class_cnt = 0;
int list_class_alloc = 0;


struct variable **list_parent_class = 0;
int list_parent_class_cnt = 0;
int list_parent_class_alloc = 0;

struct variable **list_local;
int list_local_cnt;
int list_local_alloc;

struct variable **list_types;
int list_types_cnt;
int list_types_alloc;

/* Current variable...*/
struct variable *curr_v[RECORD_LEVELS];
int v_initialized = 0;

struct variable *last_variable_ptr_found = 0;


char variable_scope = 'm';



/******************************************************************************/

#ifdef MOVED
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
#endif


void
set_variable_user_system (char n)
{
  system_or_user = n;
}
static char
get_variable_user_system ()
{
  return system_or_user;
}

/*static void set_variable_scope(char n)        { scope=n; }*/
/*static char get_variable_scope()              { return scope; }*/

char *
A4GL_unscope (char *s)
{
  static char buff[1024];
  int sl = -1;
  sl = 0;
  strcpy (buff, s);
  if (s[0] >= 'A' && s[0] <= 'Z' && s[1] == '_')
    {

      if (A4GL_isyes (acl_getenv ("REPORT_VARS_AT_MODULE")) && s[0] == 'R')
	{
	  char b[200];
	  //int c;
	  extern char curr_func[];
	  SPRINTF2 (b, "%s_%s", A4GL_compiling_module_basename (), curr_func);

	  if (strncmp (&s[2], b, strlen (b)) == 0)
	    {
	      strcpy (buff, &s[strlen (b)] + 3);
	      return buff;
	    }
	  else
	    {
	      A4GL_assertion (1, "Didn't start as I'd expect");
	    }

	}

      if (A4GL_isyes (acl_getenv ("MARK_SCOPE_MODULE")) && s[0] == 'M')
	{
	  if (strncmp
	      (&s[2], A4GL_compiling_module_basename (),
	       strlen (A4GL_compiling_module_basename ())) == 0)
	    {
	      sl = strlen (A4GL_compiling_module_basename ()) + 3;
	      strcpy (buff, &s[sl]);
	      return buff;
	    }
	}
      else
	{
	  sl = 2;
	  strcpy (buff, &s[sl]);
	}
    }
  return buff;
}

void
force_curr_v (struct variable *v, int rcnt)
{
  if (rcnt < 0)
    rcnt = last_record_cnt;
  curr_v[rcnt] = v;
}

/******************************************************************************/
static void
initialize_v (void)
{
  int a;
  for (a = 0; a < RECORD_LEVELS; a++)
    {
      curr_v[a] = 0;
    }
  v_initialized = 1;
}


void
push_scope (void)
{
  scopes[scopes_cnt] = get_current_variable_scope ();
  scopes_cnt++;
}

void
pop_scope (void)
{
  scopes_cnt--;
  set_current_variable_scope (scopes[scopes_cnt]);
}


/******************************************************************************/
static void
set_arr_subscripts (char *s_orig, int record_cnt)
{
  int a;
  char *ptr;
  char s[512] = "            ";


  if (s_orig == 0)
    {
      	//curr_v[record_cnt]->is_array = 0;
	curr_v[record_cnt]->arr_subscripts.arr_subscripts_val=0;
	curr_v[record_cnt]->arr_subscripts.arr_subscripts_len=0;
    }
  else
    {
      int subcnt = 0;
      strcpy (s, s_orig);
      //curr_v[record_cnt]->is_array = 1;

      ptr = s;

      for (a = 0; a < strlen (s); a++)
	{
	  if (s[a] == ']')
	    {
	      s[a] = 0;
	      	curr_v[record_cnt]->arr_subscripts.arr_subscripts_len=subcnt+1;
		curr_v[record_cnt]->arr_subscripts.arr_subscripts_val=realloc(curr_v[record_cnt]->arr_subscripts.arr_subscripts_val, 
					sizeof(curr_v[record_cnt]->arr_subscripts.arr_subscripts_val[0]*curr_v[record_cnt]->arr_subscripts.arr_subscripts_len));
	      curr_v[record_cnt]->arr_subscripts.arr_subscripts_val[subcnt++] = atoi (ptr);
	      s[a] = ']';
	      ptr = &s[a + 2];
	      a++;		/* Skip over '[' */
	    }
	}
      curr_v[record_cnt]->arr_subscripts.arr_subscripts_len=subcnt+1;
      curr_v[record_cnt]->arr_subscripts.arr_subscripts_val=realloc(curr_v[record_cnt]->arr_subscripts.arr_subscripts_val, 
			sizeof(curr_v[record_cnt]->arr_subscripts.arr_subscripts_val[0]*curr_v[record_cnt]->arr_subscripts.arr_subscripts_len));
      curr_v[record_cnt]->arr_subscripts.arr_subscripts_val[subcnt++] = atoi (ptr);
    }

}



/******************************************************************************/
static void
add_linked_columns (struct linked_variable *linked, char *collist_orig)
{
  struct vname_name_list *ptr_name = 0;
  char *ptr;
  char collist[1024];
  int a;

  strcpy (collist, collist_orig);
  ptr = collist;

  for (a = 0; a < strlen (collist); a++)
    {

      if (collist[a] == ',')
	{
	  collist[a] = 0;

	  if (ptr_name == 0)
	    {
	      linked->col_list.names.names_len = 1;
	      linked->col_list.names.names_val = malloc (sizeof (vname));
	      linked->col_list.names.names_val[0].name = acl_strdup (ptr);
	      linked->col_list.names.names_val[0].alias = 0;
	    }
	  else
	    {
	      linked->col_list.names.names_len++;
	      linked->col_list.names.names_val =
		realloc (linked->col_list.names.names_val,
			 sizeof (vname) * linked->col_list.names.names_len);
	      linked->col_list.names.names_val[linked->col_list.names.
					       names_len - 1].name =
		acl_strdup (ptr);
	      linked->col_list.names.names_val[linked->col_list.names.
					       names_len - 1].alias = 0;
	    }
	  ptr = &collist[a + 1];

	}
    }
/* Last column to add...*/
  if (ptr_name == 0)
    {
      linked->col_list.names.names_len = 1;
      linked->col_list.names.names_val = malloc (sizeof (vname));
      linked->col_list.names.names_val[0].name = acl_strdup (ptr);
      linked->col_list.names.names_val[0].alias = 0;
    }
  else
    {
      linked->col_list.names.names_len++;
      linked->col_list.names.names_val =
	realloc (linked->col_list.names.names_val,
		 sizeof (vname) * linked->col_list.names.names_len);
      linked->col_list.names.names_val[linked->col_list.names.names_len -
				       1].name = acl_strdup (ptr);
      linked->col_list.names.names_val[linked->col_list.names.names_len -
				       1].alias = 0;
    }
}


/******************************************************************************/
/**
 * Add a variable to the variables list
 * @param category - reserved for future enhancement
 * @param name     - the name of the variable (or datatype depending on call)
 * @param type     - the type of the variable
 * @param n        - array size etc
 * @param function - the calling function
 */
void
variable_action (int category, char *name, char *type, char *n,
		 char *function)
{
  static int record_cnt = 0;
  char scope;
  static int adding_assoc = 0;
  struct vname_name_list *ptr;
  struct variable *tmp_var;

#define MODE_ADD_CONSTANT  	1
#define MODE_ADD_RECORD    	2
#define MODE_ADD_TYPE      	3
#define MODE_ADD_LINK      	4
#define MODE_ADD_ARRAY     	5
#define MODE_ADD_ASSOC_ARRAY  	6
#define MODE_ADD_NAME		7
#define MODE_ADD_ENDRECORD	8
#define MODE_ADD_ENDOBJECT	8
#define MODE_ADD_TO_SCOPE	9
#define MODE_ADD_END_ASSOC	10
#define MODE_ADD_FUNCTION	11
#define MODE_ADD_DIM	12
#define MODE_ADD_OBJECT	13
#define MODE_ADD_SRC      14

/* DEBUGGING Stuff for mode settings... */
#ifdef DEBUGGING
  char *modes[] = {
    "",
    "ADD_CONSTANT",
    "ADD_RECORD",
    "ADD_TYPE",
    "ADD_LINK",
    "ADD_ARRAY",
    "ADD_ASSOC_ARRAY",
    "ADD_NAME",
    "ADD_ENDRECORD",
    "ADD_TO_SCOPE",
    "ADD_END_ASSOC",
    "ADD_FUNCTION",
    "ADD_DIM",
    "ADD_OBJECT",
    "ADD_SRC"
  };
#endif



  int mode = 0;

  if (!v_initialized)
    initialize_v ();

  last_record_cnt = record_cnt;

  scope = get_current_variable_scope ();
  A4GL_debug ("scope=%c", scope);
  if (name == 0)
    name = "";
  if (type == 0)
    type = "";
  if (n == 0)
    n = "";
  if (strcmp (name, "----") == 0)
    name = "";
  if (strcmp (type, "----") == 0)
    type = "";
  if (strcmp (n, "----") == 0)
    n = "";



  A4GL_debug
    ("variable_action (category=%d name=%s type=%s n=%s function=%s record_cnt=%d)\n",
     category, name, type, n, function, record_cnt);

/* Try to determine what we are doing.*/
/* This comes about from the old way of handling variables and*/
/* should be fixed properly sometime...*/

  if (strcmp (function, "add_constant") == 0 && mode == 0)
    {
      mode = MODE_ADD_CONSTANT;
    }
  if (strcmp (function, "push_dim") == 0 && mode == 0)
    {
      mode = MODE_ADD_DIM;
    }

  if (strcmp (function, "add_function") == 0 && mode == 0)
    {
      mode = MODE_ADD_FUNCTION;
    }


  if (strcmp (function, "add_src") == 0 && mode == 0)
    {
      mode = MODE_ADD_SRC;
    }

  if (strcmp (function, "add_link_to") == 0 && mode == 0)
    {
      mode = MODE_ADD_LINK;
    }

  if (strcmp (name, "_RECORD") == 0 && mode == 0)
    {
      mode = MODE_ADD_RECORD;
    }
  if (strcmp (name, "_OBJECT") == 0 && mode == 0)
    {
      mode = MODE_ADD_OBJECT;
    }

  if (strcmp (name, "_ASSOCIATE") == 0 && mode == 0)
    {
      mode = MODE_ADD_ASSOC_ARRAY;
    }

  if (strcmp (type, "_ENDASSOC") == 0 && mode == 0)
    {
      mode = MODE_ADD_END_ASSOC;
    }

  if (strcmp (type, "_ENDREC") == 0 && mode == 0)
    {
      mode = MODE_ADD_ENDRECORD;
    }

  if (strlen (n) && strcmp (n, "0") != 0 && mode == 0)
    {
      mode = MODE_ADD_ARRAY;
    }

  if (strcmp (function, "push_type") == 0 && mode == 0)
    {
      mode = MODE_ADD_TYPE;
    }
  if (strlen (name) && !strlen (type) && mode == 0)
    {
      mode = MODE_ADD_NAME;
    }

  A4GL_debug ("Mode=%d\n", mode);

/* We don't need to do the adding of the array for an assoc_array - this will already have been done...*/
  if (mode == MODE_ADD_ARRAY)
    {
      if (adding_assoc == 1)
	{
	  adding_assoc = 0;
	  return;
	}
    }

  if (adding_assoc)
    adding_assoc = 0;




/* Have we worked it out ?*/
  if (mode == 0)
    {
      /* This shouldn't happen.... */
      PRINTF ("Don't know what to do...\n");
      PRINTF ("%d Name = %s type = %s n=%s function = %s\n", category, name,
	      type, n, function);
      exit (1);
    }



/* Now actually do it...*/
  switch (mode)
    {
    case MODE_ADD_CONSTANT:
      curr_v[record_cnt] = make_constant (name, type, n);
      mode = MODE_ADD_TO_SCOPE;
      break;

    case MODE_ADD_FUNCTION:
      make_function (name, record_cnt);
      break;

    case MODE_ADD_DIM:
      ptr = &curr_v[record_cnt]->names;
      tmp_var = find_dim (name);
      curr_v[record_cnt] = acl_malloc2 (sizeof (struct variable));
      memcpy (curr_v[record_cnt], tmp_var, sizeof (struct variable));
      memcpy (&curr_v[record_cnt]->names, ptr, sizeof (struct vname_name_list));
      add_to_scope (record_cnt, 0);
      curr_v[record_cnt] = 0;
      break;

    case MODE_ADD_RECORD:
      curr_v[record_cnt]->var_data.variable_type = VARIABLE_TYPE_RECORD;

      curr_v[record_cnt]->var_data.variable_data_u.v_record.variables.
	variables_len = 0;
      curr_v[record_cnt]->var_data.variable_data_u.v_record.variables.
	variables_val = 0;


      curr_v[record_cnt]->var_data.variable_data_u.v_record.record_alloc = 0;
      curr_v[record_cnt]->var_data.variable_data_u.v_record.linked = 0;
     curr_v[record_cnt]->var_data.variable_data_u.v_record.user_ptr=0;

      curr_v[record_cnt]->var_data.variable_data_u.v_record.object_type = 0;
      record_cnt++;
      curr_v[record_cnt] = 0;	/* Make sure we're starting fresh... */
      break;

    case MODE_ADD_OBJECT:
      curr_v[record_cnt]->var_data.variable_type = VARIABLE_TYPE_OBJECT;
      curr_v[record_cnt]->var_data.variable_data_u.v_record.variables.
	variables_len = 0;
      curr_v[record_cnt]->var_data.variable_data_u.v_record.variables.
	variables_val = 0;
      curr_v[record_cnt]->var_data.variable_data_u.v_record.record_alloc = 0;
      curr_v[record_cnt]->var_data.variable_data_u.v_record.linked = 0;

     curr_v[record_cnt]->var_data.variable_data_u.v_record.user_ptr=0;

      curr_v[record_cnt]->var_data.variable_data_u.v_record.object_type = name;
      record_cnt++;
      curr_v[record_cnt] = 0;	/* Make sure we're starting fresh... */
      break;


    case MODE_ADD_ENDRECORD:	// Also MODE_ADD_ENDOBJECT
      curr_v[record_cnt] = 0;
      record_cnt--;
      add_to_scope (record_cnt, 0);
      curr_v[record_cnt] = 0;
      break;


    case MODE_ADD_SRC:
	//printf("Name=%s\n",name);
      curr_v[record_cnt]->defsrc= strdup(name);
	break;

    case MODE_ADD_TYPE:
      curr_v[record_cnt]->var_data.variable_data_u.v_simple.datatype = A4GL_lexer_find_type (name);
      curr_v[record_cnt]->var_data.variable_data_u.v_simple.dimensions[0] = atoi (type);
      curr_v[record_cnt]->var_data.variable_data_u.v_simple.dimensions[1] = 0; mode = MODE_ADD_TO_SCOPE;
      break;

    case MODE_ADD_ASSOC_ARRAY:
      curr_v[record_cnt]->var_data.variable_type = VARIABLE_TYPE_ASSOC;
      curr_v[record_cnt]->var_data.variable_data_u.v_assoc.size = atoi (n);
      curr_v[record_cnt]->var_data.variable_data_u.v_assoc.char_size =
	atoi (type);
      curr_v[record_cnt]->var_data.variable_data_u.v_assoc.variables.
	variables_len = 0;
      curr_v[record_cnt]->var_data.variable_data_u.v_assoc.variables.
	variables_val = 0;

      //do_print_declare_associate_1 (curr_v[record_cnt]->names.names.  names_val[0].name, n, type); 
      
      record_cnt++;
      curr_v[record_cnt] = acl_malloc2 (sizeof (struct variable));
      set_arr_subscripts (0, record_cnt);
      curr_v[record_cnt]->var_data.variable_type = VARIABLE_TYPE_SIMPLE;

      curr_v[record_cnt]->names.names.names_val = malloc (sizeof (vname));
      curr_v[record_cnt]->names.names.names_len = 1;
      curr_v[record_cnt]->names.names.names_val[0].name = ASSOC_INTERNAL;
      curr_v[record_cnt]->is_static = 0;
      curr_v[record_cnt]->is_extern = 0;
      curr_v[record_cnt]->usage = 0;
      curr_v[record_cnt]->assigned = 0;
      curr_v[record_cnt]->flags = 0;
      curr_v[record_cnt]->lineno = token_read_on_line;
      curr_v[record_cnt]->src_module = outputfilename;
      curr_v[record_cnt]->user_system = get_variable_user_system ();

      curr_v[record_cnt]->defsrc = "";

      set_arr_subscripts (n, record_cnt);

      adding_assoc = 1;
      break;


    case MODE_ADD_END_ASSOC:
      curr_v[record_cnt] = 0;
      record_cnt--;
      add_to_scope (record_cnt, 0);
      curr_v[record_cnt] = 0;
      break;

    case MODE_ADD_LINK:
      {
	struct linked_variable *linked;
	linked = acl_malloc2 (sizeof (struct linked_variable));
	linked->tabname = acl_strdup (name);
	add_linked_columns (linked, type);
	curr_v[record_cnt - 1]->var_data.variable_data_u.v_record.linked = linked;
	break;
      }



    case MODE_ADD_ARRAY:
      set_arr_subscripts (n, record_cnt);
      break;


    case MODE_ADD_NAME:
      break;			/* We'll deal with this later */

    default:
      PRINTF ("Run out of actions %d\n", mode);
      PRINTF ("%d Name = %s type = %s n=%s function = %s\n\n", category,
	      name, type, n, function);
      exit (0);
    }


  /* We need to do this outside of the switch so that ADD_ASSOC and ADD_LINK can call it too... */

  if (mode == MODE_ADD_NAME)
    {
      /* Is this the first name at this level ? */
      if (curr_v[record_cnt] == 0)
	{
	  A4GL_debug ("First at level");
	  curr_v[record_cnt] = acl_malloc2 (sizeof (struct variable));
	  curr_v[record_cnt]->names.names.names_val = malloc (sizeof (vname));
	  curr_v[record_cnt]->names.names.names_len = 1;
	  curr_v[record_cnt]->names.names.names_val[0].name =
	    acl_strdup (name);


	  curr_v[record_cnt]->var_data.variable_type = VARIABLE_TYPE_SIMPLE;
	  curr_v[record_cnt]->user_system = get_variable_user_system ();
          curr_v[record_cnt]->defsrc = "";
	  curr_v[record_cnt]->is_static = 0;
	  curr_v[record_cnt]->is_extern = 0;
	  curr_v[record_cnt]->usage = 0;
	  curr_v[record_cnt]->assigned = 0;
	  curr_v[record_cnt]->flags = 0;
      	curr_v[record_cnt]->lineno = token_read_on_line;

	  curr_v[record_cnt]->src_module = outputfilename;

	  /* Reports, menuhandlers & formhandlers */
	  /* should all maintain their values between calls - hence */
	  /* they will always be static.... */
	  if (isin_command ("REPORT") || isin_command ("FORMHANDLER")
	      || isin_command ("MENUHANDLER"))
	    {
	      curr_v[record_cnt]->is_static = 1;
	    }


	  set_arr_subscripts (0, record_cnt);
	}
      else
	{
	  /* We've already got one name.. */
	  /* Add some more to the list.. */

	  A4GL_debug ("Already have first at this level");
	  curr_v[record_cnt]->names.names.names_len++;
	  curr_v[record_cnt]->names.names.names_val = realloc (curr_v[record_cnt]->names.names.names_val, sizeof (vname) * curr_v[record_cnt]->names.names.names_len);
	  curr_v[record_cnt]->names.names.names_val[curr_v[record_cnt]->names.names.names_len-1].name = acl_strdup (name);
	  curr_v[record_cnt]->names.names.names_val[curr_v[record_cnt]->names.names.names_len-1].alias = 0;
	}
    }

  /* curr_v[record_cnt] should now hold the variable we've just generated */
   /**/ if (mode == MODE_ADD_TO_SCOPE)
    {
      add_to_scope (record_cnt, 0);
      curr_v[record_cnt] = 0;
    }
}



/******************************************************************************/
void
make_function (char *name, int record_cnt)
{
  struct variable *local_v;
  char scope;

  scope = get_current_variable_scope ();

  if (class_cnt == 0)
    set_current_variable_scope ('g');


  //A4GL_debug ("MAKE FUNCTION : %s\n", name);
  local_v = (struct variable *) acl_malloc2 (sizeof (struct variable));
  local_v->names.names.names_val = malloc (sizeof (vname));
  local_v->names.names.names_len = 1;
  local_v->names.names.names_val[0].name = acl_strdup (name);
  local_v->names.names.names_val[0].alias = 0;
  A4GL_convlower (local_v->names.names.names_val[0].name);
  local_v->var_data.variable_type = VARIABLE_TYPE_FUNCTION_DECLARE;
  local_v->user_system = get_variable_user_system ();
  local_v->defsrc = "";
  local_v->is_static = 0;
  local_v->is_extern = 0;
  local_v->usage = 0;
  local_v->assigned = 0;
  local_v->flags = 0;
      local_v->lineno = token_read_on_line;
  //local_v->is_array = 0;
  local_v->src_module = outputfilename;

      local_v->arr_subscripts.arr_subscripts_len=0;
      local_v->arr_subscripts.arr_subscripts_val=0;
  //local_v->is_array = 0;

  curr_v[record_cnt] = local_v;
  add_to_scope (0, 1);
  curr_v[record_cnt] = 0;
  set_current_variable_scope (scope);
}



/******************************************************************************/
static struct variable *
make_constant (char *name, char *value, char *int_or_char)
{
  struct variable *local_v;
  local_v = (struct variable *) acl_malloc2 (sizeof (struct variable));
  local_v->names.names.names_val = malloc (sizeof (vname));
  local_v->names.names.names_len = 1;
  local_v->names.names.names_val[0].name = acl_strdup (name);
  local_v->names.names.names_val[0].alias = 0;


  local_v->var_data.variable_type = VARIABLE_TYPE_CONSTANT;
  local_v->user_system = get_variable_user_system ();
  local_v->defsrc = "";
  local_v->is_static = 0;
  local_v->is_extern = 0;
  local_v->usage = 0;
  local_v->assigned = 0;
  local_v->flags = 0;
      local_v->lineno = token_read_on_line;
  //local_v->is_array = 0;
  local_v->src_module = outputfilename;

      local_v->arr_subscripts.arr_subscripts_val = 0;
      local_v->arr_subscripts.arr_subscripts_len = 0;
  //local_v->is_array = 0;

  if (int_or_char[0] == 'c')
    {
      local_v->var_data.variable_data_u.v_const.consttype = CONST_TYPE_CHAR;
      local_v->var_data.variable_data_u.v_const.constant_data_u.data_c =
	acl_strdup (value);
    }

  if (int_or_char[0] == 'C')
    {
      local_v->var_data.variable_data_u.v_const.consttype = CONST_TYPE_IDENT;
      local_v->var_data.variable_data_u.v_const.constant_data_u.data_ident =
	acl_strdup (value);
    }

  if (int_or_char[0] == 'i')
    {
      local_v->var_data.variable_data_u.v_const.consttype = CONST_TYPE_INTEGER;
      local_v->var_data.variable_data_u.v_const.constant_data_u.data_i =
	atoi (value);
    }
  if (int_or_char[0] == 'f')
    {
      local_v->var_data.variable_data_u.v_const.consttype = CONST_TYPE_FLOAT;
      local_v->var_data.variable_data_u.v_const.constant_data_u.data_f =
	atof (value);
    }

  if (A4GL_aubit_strcasecmp (name, "TRUE") == 0 || strcasecmp (name, "FALSE") == 0
      || A4GL_aubit_strcasecmp (name, "NOTFOUND") == 0);
  else
    {

      if (A4GL_isyes (acl_getenv ("CONSTANT2DEFINES")))
	{
	  char buff[256];
	  strcpy (buff, upshift (name));
	  PRINTF ("#define %s %s\n", buff, value);
	}
    }
  return local_v;
}




int chk_already_defined(char *s, char scope) {
char c;
	c=find_variable_scope(s);
	if (c==0) return 0; // not defined yet at all...

	switch (scope) {
		case 'l':
		case 'R':
			if (c=='m' || c=='M' || c=='g' || c=='G') return 1;
			else return 0;

		case 'm':
			if (c=='g' || c=='G') return 1;
			else return 0;

		case 'g':
			if (c=='G') return 1;
			else return 0;
		
	}
	return 0;
}


/******************************************************************************/
static int
add_to_scope (int record_cnt, int unroll)
{
  char local_scope[10];
  int tmp_1;
  int tmp_2;
  int *counter = 0;
  int *alloc = 0;
  struct variable ***variable_holder;
  struct variable **ptr;
  //struct vname_name_list *names;
  int a;
  struct variable *v_new;
  char scope;
  struct variable *orig;
	
  variable_holder = 0;

  scope = get_current_variable_scope ();
  if (unroll == 0)
    {

      orig = curr_v[record_cnt];
      if (curr_v[record_cnt]->names.names.names_len>1) {
	for (a=0;a<orig->names.names.names_len;a++) {
		
	      v_new = acl_malloc2 (sizeof (struct variable));
	      memcpy (v_new, orig, sizeof (struct variable));

	      curr_v[record_cnt] = v_new;
	      curr_v[record_cnt]->names.names.names_val=malloc(sizeof(vname));
	      curr_v[record_cnt]->names.names.names_len=1;
              curr_v[record_cnt]->names.names.names_val[0].name= strdup(orig->names.names.names_val[a].name);
              curr_v[record_cnt]->names.names.names_val[0].alias= 0;
	      add_to_scope (record_cnt, 1);
	    }
	  return 1;
	}
    }


/* If record_cnt is set then we're not adding it as a variable */
/* to local/module/global scope - but to the record at the level above...*/


  if (record_cnt)
    {
      /* We can add to an associative array - or a record.... */

      if (curr_v[record_cnt - 1]->var_data.variable_type != VARIABLE_TYPE_RECORD
	  && curr_v[record_cnt - 1]->var_data.variable_type !=
	  VARIABLE_TYPE_OBJECT
	  && curr_v[record_cnt - 1]->var_data.variable_type !=
	  VARIABLE_TYPE_ASSOC)
	{
	  /* We have a problem... */
	  PRINTF ("Last variable level was not a record!\n");
	  assert (0);
	}


      if (curr_v[record_cnt - 1]->var_data.variable_type == VARIABLE_TYPE_RECORD
	  || curr_v[record_cnt - 1]->var_data.variable_type ==
	  VARIABLE_TYPE_OBJECT)
	{
	  variable_holder =
	    &curr_v[record_cnt -
		    1]->var_data.variable_data_u.v_record.variables.variables_val;
	  counter = &curr_v[record_cnt - 1]->var_data.variable_data_u.v_record.variables.variables_len;	/* record_cnt; */
	  alloc =
	    &curr_v[record_cnt -
		    1]->var_data.variable_data_u.v_record.record_alloc;
	}

      /* We can only store one variable here... */
      if (curr_v[record_cnt - 1]->var_data.variable_type == VARIABLE_TYPE_ASSOC)
	{
	  tmp_1 = 0;
	  tmp_2 = 0;
	  variable_holder =
	    &curr_v[record_cnt -
		    1]->var_data.variable_data_u.v_assoc.variables.variables_val;
	  tmp_1 = 0;
	  tmp_2 = 0;
	  counter = &tmp_1;
	  alloc = &tmp_2;
	}

      SPRINTF1 (local_scope, "%d", record_cnt);
    }
  else
    {

      if (scope == 'g')
	{
	  SPRINTF0 (local_scope, "g");
	  variable_holder = &list_global;
	  counter = &list_global_cnt;
	  alloc = &list_global_alloc;
		/*
		if (chk_already_defined(curr_v[record_cnt]->names.names.names_val[0].name,scope)) {
				char buff[256];
				sprintf(buff, "Coding Standards: Global variable (%s) hides an imported Global variable", curr_v[record_cnt]->names.names.names_val[0].name);
				A4GL_lint(buff); // COMMENTED OUT
		}
		*/
	}

      if (scope == 'C')
	{
	  SPRINTF0 (local_scope, "C");
	  variable_holder = &list_class;
	  counter = &list_class_cnt;
	  alloc = &list_class_alloc;
	}

      if (scope == 'G')
	{
	  SPRINTF0 (local_scope, "g");
	  variable_holder = &list_imported_global;
	  counter = &list_imported_global_cnt;
	  alloc = &list_imported_global_alloc;
	}

      if (scope == 'm')
	{
	  SPRINTF0 (local_scope, "m");
	  variable_holder = &list_module;
	  counter = &list_module_cnt;
	  alloc = &list_module_alloc;
		/*
		if (chk_already_defined(curr_v[record_cnt]->names.names.names_val[0].name,scope)) {

				char buff[256];
				sprintf(buff, "Coding Standards: Module variable (%s) hides a Global variable", curr_v[record_cnt]->names.names.names_val[0].name);
				A4GL_lint(buff); // COMMENTED OUT
		}
		*/
	}

      if (scope == 'R')
	{
	  SPRINTF0 (local_scope, "R");
	  variable_holder = &list_local;
	  counter = &list_local_cnt;
	  alloc = &list_local_alloc;
		/*
		if (chk_already_defined(curr_v[record_cnt]->names.names.names_val[0].name,scope)) {
				char buff[256];
				sprintf(buff, "Coding Standards: Local variable (%s) hides a Global or Module variable", curr_v[record_cnt]->names.names.names_val[0].name);
				A4GL_lint(buff); // COMMENTED OUT
		}
		*/
	}

      if (scope == 'l')
	{
	  SPRINTF0 (local_scope, "l");
	  variable_holder = &list_local;
	  counter = &list_local_cnt;
	  alloc = &list_local_alloc;
		/*
		if (chk_already_defined(curr_v[record_cnt]->names.names.names_val[0].name,scope)) {
				char buff[256];
				sprintf(buff, "Coding Standards: Local variable (%s) hides a Global or Module variable", curr_v[record_cnt]->names.names.names_val[0].name);
				A4GL_lint(buff); // COMMENTED OUT
		}
		*/
	}

      if (scope == 'T')
	{
	  SPRINTF0 (local_scope, "T");
	  variable_holder = &list_types;
	  counter = &list_types_cnt;
	  alloc = &list_types_alloc;
	}


    }


/* Now - we can add to our variables list for our scope...*/

  if (*variable_holder && unroll == 0)
    {
      ptr = *variable_holder;
      for (a = 0; a < *counter; a++)
	{
	  if (A4GL_aubit_strcasecmp (ptr[a]->names.names.names_val[0].name, curr_v[record_cnt]->names.names.names_val[0].name) == 0)
	    {
	      set_yytext (curr_v[record_cnt]->names.names.names_val[0].name);
	      A4GL_exitwith ("Variable is already defined");
	      a4gl_yyerror ("Variable is already defined");
	      return 0;
	    }
	}
    }

  



  if (*counter >= *alloc)
    {
      long space;
      (*alloc) += 10;
      space = (*alloc) * sizeof (struct variable *);
      *variable_holder = acl_realloc (*variable_holder, space);
    }


  if (variable_holder == 0)
    {
      PRINTF ("No variable holder!");
      assert (0);
    }

  ptr = *variable_holder;



  curr_v[record_cnt]->names.names.names_val[0].alias = 0;

  curr_v[record_cnt]->scope = get_current_variable_scope ();



  if (record_cnt == 0 && get_current_variable_scope () != 'G'
      && (curr_v[record_cnt]->var_data.variable_type == VARIABLE_TYPE_SIMPLE
	  || curr_v[record_cnt]->var_data.variable_type == VARIABLE_TYPE_RECORD
	  || curr_v[record_cnt]->var_data.variable_type == VARIABLE_TYPE_OBJECT
	  || curr_v[record_cnt]->var_data.variable_type == VARIABLE_TYPE_ASSOC))
    {
      char buff[256];
		int issystem;
		issystem=is_system_variable( curr_v[record_cnt]->names.names.names_val[0].name);

		if (strcmp(curr_v[record_cnt]->names.names.names_val[0].name,"int_flag")==0) issystem=1;
		if (strcmp(curr_v[record_cnt]->names.names.names_val[0].name,"quit_flag")==0) issystem=1;
		if (strcmp(curr_v[record_cnt]->names.names.names_val[0].name,"fgl_user")==0) issystem=1;

#ifdef MOVED_TO_LINT
/*
		switch (get_current_variable_scope()) {
			case 'G':
				if ( !issystem) {
				if (  curr_v[record_cnt]->names.names.names_val[0].name[0]!='g' ) {
					sprintf(buff, "Coding Standards: Global variable (%s) does not begin with 'g'", curr_v[record_cnt]->names.names.names_val[0].name);
					A4GL_lint(buff); // COMMENTED OUT
				} else {
					if (!is_valid_vname(curr_v[record_cnt], get_current_variable_scope())) {
						sprintf(buff, "Coding Standards: Variable (%s) is not in the form sn_xxxx ", curr_v[record_cnt]->names.names.names_val[0].name);
						A4GL_lint(buff); // COMMENTED OUT
					}
				}
				}
				break;
			case 'g':
				if ( !issystem) {
				if (  curr_v[record_cnt]->names.names.names_val[0].name[0]!='g'  ) {
					sprintf(buff, "Coding Standards: Global variable (%s) does not begin with 'g'", curr_v[record_cnt]->names.names.names_val[0].name);
					A4GL_lint(buff); // COMMENTED OUT
				}  else {
					if (!is_valid_vname(curr_v[record_cnt], get_current_variable_scope())) {
						sprintf(buff, "Coding Standards: Variable (%s) is not in the form sn_xxxx ", curr_v[record_cnt]->names.names.names_val[0].name);
						A4GL_lint(buff); // COMMENTED OUT
					}
				}
				}
				break;

			case 'm':
			case 'M':
				if ( !issystem) {
				if (  curr_v[record_cnt]->names.names.names_val[0].name[0]!='m' ) {
					sprintf(buff, "Coding Standards: Module variable (%s) does not begin with 'm'", curr_v[record_cnt]->names.names.names_val[0].name);
					A4GL_lint(buff); // COMMENTED OUT
				}  else {
					if (!is_valid_vname(curr_v[record_cnt], get_current_variable_scope())) {
						sprintf(buff, "Coding Standards: Variable (%s) is not in the form sn_xxxx ", curr_v[record_cnt]->names.names.names_val[0].name);
						A4GL_lint(buff); // COMMENTED OUT
					}
				}
				}
				
				break;
			case 'l':
			case 'L':
				if ( !issystem) {
				if (  curr_v[record_cnt]->names.names.names_val[0].name[0]!='l') {
					sprintf(buff, "Coding Standards: Local variable (%s) does not begin with 'l'", curr_v[record_cnt]->names.names.names_val[0].name);
					A4GL_lint(buff); // COMMENTED OUT
				} else {
					if (!is_valid_vname(curr_v[record_cnt], get_current_variable_scope())) {
						sprintf(buff, "Coding Standards: Variable (%s) is not in the form sn_xxxx ", curr_v[record_cnt]->names.names.names_val[0].name);
						A4GL_lint(buff); // COMMENTED OUT
					}
				}
				}
				break;
			default: printf("UNknown scope %c\n", get_current_variable_scope());
		}
*/
#endif



      if (A4GL_isyes (acl_getenv ("MARK_SCOPE"))
	  || A4GL_isyes (acl_getenv ("MARK_SCOPE_MODULE")))
	{
	  if (A4GL_isyes (acl_getenv ("MARK_SCOPE_MODULE")))
	    {
	      SPRINTF2 (buff, "%c_%s_", get_current_variable_scope (),
			A4GL_compiling_module_basename ());
	      buff[0] = toupper (buff[0]);
	    }
	  else
	    {
	      SPRINTF1 (buff, "%c_", get_current_variable_scope ());
	      buff[0] = toupper (buff[0]);
	    }
	  strcat (buff, curr_v[record_cnt]->names.names.names_val[0].name);
	  curr_v[record_cnt]->names.names.names_val[0].alias = acl_strdup (buff);
	}
    } else {

#ifdef MOVED_TO_LINT
/*
	if (record_cnt==0 && (curr_v[record_cnt]->var_data.variable_type == VARIABLE_TYPE_SIMPLE
          || curr_v[record_cnt]->var_data.variable_type == VARIABLE_TYPE_RECORD
          || curr_v[record_cnt]->var_data.variable_type == VARIABLE_TYPE_OBJECT
          || curr_v[record_cnt]->var_data.variable_type == VARIABLE_TYPE_ASSOC)
) {
		int issystem;
		issystem=is_system_variable( curr_v[record_cnt]->names.names.names_val[0].name);

		if (strcmp(curr_v[record_cnt]->names.names.names_val[0].name,"int_flag")==0) issystem=1;
		if (strcmp(curr_v[record_cnt]->names.names.names_val[0].name,"quit_flag")==0) issystem=1;
		if (strcmp(curr_v[record_cnt]->names.names.names_val[0].name,"fgl_user")==0) issystem=1;

		switch (get_current_variable_scope()) {
			case 'G':
				if (  curr_v[record_cnt]->names.names.names_val[0].name[0]!='g'  &&  !issystem) {
					printf("%s %c \n", curr_v[record_cnt]->names.names.names_val[0].name,  curr_v[record_cnt]->user_system);
					A4GL_lint("Global variable does not begin with 'g'"); // COMMENTED OUT
				}
				break;
			case 'g':
				if (  curr_v[record_cnt]->names.names.names_val[0].name[0]!='g'  &&  !issystem) {
					printf("%s %c \n", curr_v[record_cnt]->names.names.names_val[0].name,  curr_v[record_cnt]->user_system);
					A4GL_lint("Global variable does not begin with 'g' ???"); // COMMENTED OUT
				}
				break;
			case 'M':
				printf("Module : %s\n", curr_v[record_cnt]->names.names.names_val[0].name);
				if (  curr_v[record_cnt]->names.names.names_val[0].name[0]!='m'  && !issystem) {
					printf("%s %c \n", curr_v[record_cnt]->names.names.names_val[0].name,  curr_v[record_cnt]->user_system);
					A4GL_lint("Module variable does not begin with 'm'"); // COMMENTED OUT
				}
				break;
			case 'L':
				if (  curr_v[record_cnt]->names.names.names_val[0].name[0]!='l'  &&  !issystem) {
					printf("%s %c \n", curr_v[record_cnt]->names.names.names_val[0].name,  curr_v[record_cnt]->user_system);
					A4GL_lint("Local variable does not begin with 'l'"); // COMMENTED OUT
				}
				break;
			default: printf("UNknown scope\n");
		}
			
	}
*/
#endif
			

   }


  ptr[*counter] = curr_v[record_cnt];
  (*counter)++;

  return 1;
}



/******************************************************************************/
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


/******************************************************************************/
static struct variable *
find_variable_in (char *s, struct variable **list, int cnt)
{
  char var_section[256];
  char var_nextsection[256];
  char *ptr_c;
  int a;
  struct variable *v;



  /* If we have no variables at this level - we can't do anything */
  if (list == 0)
    {
      return 0;
    }

  /* Copy across our variable so we can play with it... */
  strcpy (var_section, s);
  A4GL_strip_bracket (var_section);
  /* Reset our next section (anything after a '.') */
  strcpy (var_nextsection, "");

  ptr_c = strchr (var_section, '.');

  if (ptr_c)
    {
      *ptr_c = 0;
      strcpy (var_nextsection, ptr_c + 1);
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
      if (!has_name (&v->names, var_section)
	  && !strcmp (var_section, "*") == 0)
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

      if (v->var_data.variable_type == VARIABLE_TYPE_SIMPLE
	  || v->var_data.variable_type == VARIABLE_TYPE_CONSTANT)
	{
	  /* This is too easy... */
	  return v;
	}


      if (v->var_data.variable_type == VARIABLE_TYPE_RECORD
	  || v->var_data.variable_type == VARIABLE_TYPE_OBJECT)
	{


	  /* look for the next portion... */
	  A4GL_trim (var_nextsection);
	  if (strcmp (var_nextsection, "*") == 0)
	    {
	      return v;
	    }


	  if (strlen (var_nextsection) == 0)
	    {
	      return v;
	    }




	  return find_variable_in (var_nextsection,
				   v->var_data.variable_data_u.v_record.variables.
				   variables_val,
				   v->var_data.variable_data_u.v_record.variables.
				   variables_len);
	}

      if (v->var_data.variable_type == VARIABLE_TYPE_ASSOC)
	{
	  char buff[256];
	  /* Associate arrays always have a single record like entry for the */
	  /* associated variable - and its always called 'internal' */

	  /* If we're just looking for that - then we're fine... */
	  /* But if that is a record - we need to carry on doing our nextsection bits */
	  if (strlen (var_nextsection))
	    {
	      SPRINTF2 (buff, "%s.%s", ASSOC_INTERNAL, var_nextsection);
	    }
	  else
	    {
	      SPRINTF1 (buff, "%s", ASSOC_INTERNAL);
	    }
	  return find_variable_in (buff,
				   v->var_data.variable_data_u.v_assoc.variables.
				   variables_val, 1);
	}

    }

  return 0;
}

#ifdef MOVED
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
			A4GL_assertion(1,"FIXME");
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
	  A4GL_assertion (1, "FIXME");
	}

    }

  return 0;
}
#endif

/******************************************************************************/
struct variable *
find_variable_ptr (char *s)
{
  char buff[256];
  char buff2[256];
  struct variable *ptr;
  A4GL_debug ("find_variable_ptr : %s", s);

  if (strncmp (s, " ASSOCIATE_", 11) == 0)
    {
      strcpy (buff, &s[11]);
      strcpy (buff2, &s[A4GL_findex (s, ')') + 1]);
      buff[A4GL_findex (buff, '(')] = 0;
      strcat (buff, buff2);
      A4GL_convlower (buff);
      s = buff;
    }




// s=rm_class_copy(s);




  if (strncmp (s, "CLASS_COPY->", 12) == 0)
    {
      strcpy (buff, &s[12]);
      s = buff;
    }

  if (s[0] >= 'A' && s[0] <= 'Z' && s[1] == '_')
    {
      strcpy (s, A4GL_unscope (s));

    }

/* First we look locally - then at module level - then globally*/

  ptr = find_variable_in (s, list_local, list_local_cnt);
  if (ptr)
    {
      A4GL_debug ("local variable");
      return ptr;
    }

  ptr = find_variable_in (s, list_module, list_module_cnt);
  if (ptr)
    {
      A4GL_debug ("Module variable");
      return ptr;
    }

  ptr = find_variable_in (s, list_global, list_global_cnt);
  if (ptr)
    {
      A4GL_debug ("Global variable");
      return ptr;
    }


  ptr = find_variable_in (s, list_class, list_class_cnt);

  if (ptr)
    {
      return ptr;
    }
  else
    {
      char buff[1024];
      char p[1024];
      int levels;
      set_last_class_var ("");
      SPRINTF1 (buff, "this.%s", s);
      ptr = find_variable_in (buff, list_class, list_class_cnt);
      if (ptr)
	{
	  return ptr;
	}
      strcpy (p, "this");

      A4GL_debug ("Looking deeper into the class..");
      for (levels = 0; levels < 20; levels++)
	{
	  strcat (p, ".parent");
	  strcpy (buff, p);
	  A4GL_debug ("Looking to see if it has a parent : %s", buff);
	  ptr = find_variable_in (buff, list_class, list_class_cnt);
	  if (ptr)
	    {
	      strcat (buff, ".");
	      strcat (buff, s);
	      A4GL_debug ("Looking to see if its parent has this : %s", buff);
	      ptr = find_variable_in (buff, list_class, list_class_cnt);

	      if (ptr)
		{
		  set_last_class_var (&buff[5]);
		  return ptr;
		}
	    }
	  else
	    {			// No more parents...
	      break;
	    }
	}


    }


  ptr = find_variable_in (s, list_imported_global, list_imported_global_cnt);
  if (ptr)
    {
      return ptr;
    }


  A4GL_debug ("%s -  variable NOT FOUND\n", s);

  return 0;
}



/******************************************************************************/
int
find_variable (char *s_in, int *dtype, int *size, int *is_array,
	       struct variable **var_ptr)
{
  struct variable *ptr;
  char s[1024];
  if (s_in[0] == ' ')
    return 1;
  strcpy (s, s_in);
  A4GL_strip_bracket (s);
  A4GL_debug ("-->%s", s);


  if (s[0] >= 'A' && s[0] <= 'Z' && s[1] == '_')
    {


      strcpy (s, A4GL_unscope (s));
    }

  ptr = find_variable_ptr (s);


  if (ptr == 0)
    {
      if (dtype)
	*dtype = -1;
      if (size)
	*size = -1;
      if (is_array)
	*is_array = -1;
      return 0;
    }

  last_variable_ptr_found = ptr;

  /* Do they want the pointer ? */
  if (var_ptr)
    {
      *var_ptr = ptr;
    }



  if (ptr->var_data.variable_type == VARIABLE_TYPE_ASSOC)
    {
      /* They don't want the assoc - they want the referenced variable... */
      ptr = ptr->var_data.variable_data_u.v_assoc.variables.variables_val[0];
      *var_ptr = ptr;		/* Carry on working with this one instead... */
      last_variable_ptr_found = ptr;
    }

  /* We will probably have a simple variables at this point... */
  if (ptr->var_data.variable_type == VARIABLE_TYPE_SIMPLE)
    {





      if (dtype)
	*dtype = ptr->var_data.variable_data_u.v_simple.datatype;

      if (size)
	*size = ptr->var_data.variable_data_u.v_simple.dimensions[0];

      if (is_array)
	*is_array = (ptr->arr_subscripts.arr_subscripts_len>0);
      return 1;
    }

  if (ptr->var_data.variable_type == VARIABLE_TYPE_RECORD
      || ptr->var_data.variable_type == VARIABLE_TYPE_OBJECT)
    {
      A4GL_debug ("Got a record - looks complicated..");
      if (var_ptr)
	{
	  *var_ptr = ptr;	/* Carry on working with this one instead... */
	}
      return -2;
    }

  if (ptr->var_data.variable_type == VARIABLE_TYPE_CONSTANT)
    {
      A4GL_debug ("Got a constant - Lexer should have filtered that out...");
      return 0;
    }

  /* Don't know how we got to here.... */
  a4gl_yyerror ("Internal error in find_variable");
  return 0;

}





void
set_current_variable_scope (char n)
{
  variable_scope = n;
}

/******************************************************************************/
static char
get_current_variable_scope (void)
{
  char scope = 'm';
  int is_inreport = 0;
  if (variable_scope == 'T')
    return 'T';

  if (isin_command ("REPORT"))
    {
      is_inreport = 1;
      if (A4GL_isyes (acl_getenv ("REPORT_VARS_AT_MODULE")))
	{
	  is_inreport = 0;
	  return 'R';
	}
      else
	{
	  scope = 'm';
	}
    }


  if (isin_command ("FUNC") || is_inreport
      || isin_command ("FORMHANDLER") || isin_command ("MENUHANDLER")
      || isin_command ("MAIN"))
    {
      scope = 'l';
    }
  else
    {
      if (variable_scope == 'G')
	{
	  scope = 'G';
	}

      if (variable_scope == 'C')	// Class
	{
	  scope = 'C';
	}

      if (variable_scope == 'P')	// Class Parent
	{
	  scope = 'P';
	}

      if (variable_scope == 'g')
	{
	  scope = 'g';
	}
      if (variable_scope == 'm')
	{
	  scope = 'm';
	}
      if (variable_scope == 'R')
	{
	  scope = 'R';
	}
    }

  return scope;

}



#ifdef MOVED

/******************************************************************************/
void
print_variables (void)
{

  char scope;

  /* MJA - NEWVARIABLE */

  A4GL_debug
    ("/**********************************************************/\n");
  A4GL_debug
    ("/******************* Variable definitions *****************/\n");
  A4GL_debug
    ("/**********************************************************/\n");


  scope = get_current_variable_scope ();

  A4GL_debug ("Scope=%c\n", scope);

  if (scope == 'l' || scope == 'R')
    {
      print_local_variables ();
    }

  if (scope == 'g')
    {
      print_global_variables ();
#ifdef DEBUG
      A4GL_debug ("***** DUMP GVARS ****");
#endif

      if (only_doing_globals ())
	{
	  dump_gvars ();
	  exit (0);
	}
    }


  if (scope == 'm')
    {
      print_module_variables ();
    }

  if (scope == 'C')
    {
      print_class_variables ();
    }

}
#endif



#ifdef MOVED
/******************************************************************************/
void
print_local_variables (void)
{
  int a;

  A4GL_debug ("printing local variables\n");
  for (a = 0; a < list_local_cnt; a++)
    {
      print_variable_new (list_local[a], 'L', 0);
    }

}


/******************************************************************************/
void
print_class_variables (void)
{
  int a;

  for (a = 0; a < list_class_cnt; a++)
    {
      print_variable_new (list_class[a], 'C', 0);
    }
}


/******************************************************************************/
void
print_module_variables (void)
{
  int a;

  for (a = 0; a < list_module_cnt; a++)
    {
      print_variable_new (list_module[a], 'M', 0);
    }

}


int
is_external_global (char *s)
{
  int a;
  for (a = 0; a < list_external_global_cnt; a++)
    {
      if (strcmp (list_external_global[a]->names.name, s) == 0)
	return 1;
    }
  return 0;
}


/******************************************************************************/
void
print_global_variables (void)
{
  int a;
  for (a = 0; a < list_imported_global_cnt; a++)
    {
      print_variable_new (list_imported_global[a], 'G', 0);

    }

  for (a = 0; a < list_global_cnt; a++)
    {
      if (!is_external_global (list_global[a]->names.name))
	{
	  print_variable_new (list_global[a], 'g', 0);
	}
    }
}


#endif


#ifdef MOVED

/******************************************************************************/
/**
 * Identifies the data type from a string and convert it to numeric with
 * the goal of being more easyli used.
 *
 * @todo organize some defines to the data types.
 *
 * @param s The string where the data type will be scanned
 * @return The data type in numeric code
 */
int
find_type (char *s)
{
  char errbuff[80];
  static char types[20][80];
  //char buff[20];
  int a;
  //int b;
  static int set_types = 0;
  if (set_types == 0)
    {
      for (a = 0; a < 15; a++)
	{
	  strcpy (types[a], rettype_integer (a));
	}
      set_types = 1;
    }

  for (a = 0; a < 15; a++)
    {
      if (strcmp (types[a], s) == 0)
	{
	  return a;
	}
    }

  A4GL_debug ("Looking for type '%s'", s);

  if (A4GL_find_datatype_out (s) != -1)
    {
      A4GL_debug ("Found it...");
      return A4GL_find_datatype_out (s);
    }

  A4GL_debug ("Not found - keep looking");
  A4GL_debug ("find_type %s\n", s);
  if (strcmp ("char", s) == 0)
    return 0;
  if (strcmp ("long", s) == 0)
    return 2;
  if (strcmp ("integer", s) == 0)
    return 1;
  if (strcmp ("int", s) == 0)
    return 1;
  if (strcmp ("short", s) == 0)
    return 1;
  if (strcmp ("double", s) == 0)
    return 3;
  if (strcmp ("float", s) == 0)
    return 4;
  if (strcmp ("fgldecimal", s) == 0)
    return 5;
  if (strcmp ("serial", s) == 0)
    return 6;
  if (strcmp ("fgldate", s) == 0)
    return 7;
  if (strcmp ("fglmoney", s) == 0)
    return 8;
  if (strcmp ("struct_dtime", s) == 0)
    return 10;
  if (strcmp ("fglbyte", s) == 0)
    return 11;
  if (strcmp ("fgltext", s) == 0)
    return 12;
  if (strcmp ("varchar", s) == 0)
    return 13;
  if (strcmp ("struct_ival", s) == 0)
    return 14;
  if (strcmp ("_RECORD", s) == 0)
    return -2;
  if (strcmp ("form", s) == 0)
    return 9;
  if (strncmp ("struct _class_struct_", s, 21) == 0)
    {
      return -3;
    }
  A4GL_debug ("Invalid type : '%s'\n", s);
  SPRINTF1 (errbuff, "Internal Error (Invalid type : '%s')\n", s);
  a4gl_yyerror (errbuff);
  return 0;
}
#endif



/******************************************************************************/
static long
isvartype (char *s, int mode)
{
  struct variable *v;
  A4GL_debug ("isvartype : %s %d\n", s, mode);
  v = find_variable_ptr (s);
  if (v == 0)
    {
      //extern char *yytext;
      set_yytext (s);
      a4gl_yyerror ("Variable not found");
      return 0;
    }
  if (mode == 1)
    {				/* Isarray */
      return (v->arr_subscripts.arr_subscripts_len>0);
    }



  if (mode == 2)
    {				/* Isrecord */

      if (v->var_data.variable_type == VARIABLE_TYPE_ASSOC)
	{
	  v = v->var_data.variable_data_u.v_assoc.variables.variables_val[0];
	}


      if (v->var_data.variable_type == VARIABLE_TYPE_RECORD
	  || v->var_data.variable_type == VARIABLE_TYPE_RECORD)
	return 1;
      return 0;

    }

  A4GL_debug ("Bad mode in isvartype");
  assert (0);
}

/******************************************************************************/
long
isarrvariable (char *s)
{
  long a;
  A4GL_debug ("isarrvar1");
  a = isvartype (s, 1);
  A4GL_debug ("Checking if %s is an array %d", s, a);
  return a;
}

/******************************************************************************/
long
isrecvariable (char *s)
{
  A4GL_debug ("isrecvar1");
  return isvartype (s, 2);
}



#ifdef MOVED
void
make_arr_str (char *s, struct variable *v)
{
  int a;
  char buff[256];
  strcpy (s, "");
  for (a = 0; a < MAX_ARR_SUB; a++)
    {
      if (v->arr_subscripts[a])
	{
	  if (a)
	    {
	      strcat (s, "][");
	    }
	  SPRINTF1 (buff, "%d", v->arr_subscripts[a]);
	  strcat (s, buff);
	}
      else
	{
	  break;
	}
    }
}
#endif


/******************************************************************************/
long
get_variable_dets (char *s, int *type, int *arrsize, int *size, int *level,
		   char *arr)
{
  char buff[256];
  struct variable *v;


  if (s[0] == '.' && s[1] == 0)
    return -1;
  if (s[0] == 0)
    return -1;

  strcpy (buff, s);
  if (strncmp (buff, " ASSOCIATE_", 11) == 0)
    {
      char s[256];
      char buff2[256];
      strcpy (s, buff);
      strcpy (buff, &s[11]);
      strcpy (buff2, &s[A4GL_findex (s, ')') + 1]);
      buff[A4GL_findex (buff, '(')] = 0;
      strcat (buff, buff2);
      A4GL_convlower (buff);
    }

  A4GL_strip_bracket (buff);
  v = find_variable_ptr (buff);

  if (v == 0)
    return -1;

  if (v->var_data.variable_type != VARIABLE_TYPE_SIMPLE)
    {
      A4GL_debug ("Expecting a simple variable ?");
      *type = 0;
      if (v->arr_subscripts.arr_subscripts_len)
	{
	  *arrsize = v->arr_subscripts.arr_subscripts_val[0];
	}
      *size = 0;
      *level = 0;

      return -2;
    }

  *type =
    v->var_data.variable_data_u.v_simple.datatype +
    ((v->var_data.variable_data_u.v_simple.dimensions[0]) << 16);
  *level = 1;

  if (v->arr_subscripts.arr_subscripts_len)
    {
      *arrsize = v->arr_subscripts.arr_subscripts_val[0];
    }
  else
    {
      *arrsize = 0;
    }

  *size = v->var_data.variable_data_u.v_simple.dimensions[0];

  if (arr)
    {
      A4GL_assertion (1, "Shouldn't be requesting arr");
      //make_arr_str (arr, v);
    }




  return *type;

}

long
get_variable_dets_arr3 (char *s, int *type, int *arrsize1, int *arrsize2, int *arrsize3, int *size, int *level, char *arr)
{
  char buff[256];
  struct variable *v;
  *type = 0;


  if (s[0] == '.' && s[1] == 0)
    return -1;
  if (s[0] == 0)
    return -1;

  strcpy (buff, s);
  if (strncmp (buff, " ASSOCIATE_", 11) == 0)
    {
      char s[256];
      char buff2[256];
      strcpy (s, buff);
      strcpy (buff, &s[11]);
      strcpy (buff2, &s[A4GL_findex (s, ')') + 1]);
      buff[A4GL_findex (buff, '(')] = 0;
      strcat (buff, buff2);
      A4GL_convlower (buff);
    }

  A4GL_strip_bracket (buff);
  v = find_variable_ptr (buff);

  if (v == 0)
    return -1;


  *type =
    v->var_data.variable_data_u.v_simple.datatype +
    ((v->var_data.variable_data_u.v_simple.dimensions[0]) << 16);
  *level = 1;

  if (v->arr_subscripts.arr_subscripts_len)
    {
	*arrsize1=0;
	*arrsize2=0;
	*arrsize3=0;

      	*arrsize1 = v->arr_subscripts.arr_subscripts_val[0];
      	if (v->arr_subscripts.arr_subscripts_len>1) {	
      		*arrsize2 = v->arr_subscripts.arr_subscripts_val[1];
      		if (v->arr_subscripts.arr_subscripts_len>2) {	
      			*arrsize3 = v->arr_subscripts.arr_subscripts_val[2];
		} 
	}
    }
  else
    {
      *arrsize1 = 0;
      *arrsize2 = 0;
      *arrsize3 = 0;
    }

  *size = v->var_data.variable_data_u.v_simple.dimensions[0];

  if (arr)
    {
      A4GL_assertion (1, "Shouldn't be requesting arr");
      //make_arr_str (arr, v);
    }



  if (v->var_data.variable_type != VARIABLE_TYPE_SIMPLE)
    {
      A4GL_debug ("Expecting a simple variable ?");
      return -2;
    }
  return *type;

}


long
get_variable_dets_obj (char *s, int *type, int *arrsize, int *size,
		       int *level, char *arr)
{
  char buff[256];
  struct variable *v;


  if (s[0] == '.' && s[1] == 0)
    return -1;
  if (s[0] == 0)
    return -1;

  strcpy (buff, s);
  if (strncmp (buff, " ASSOCIATE_", 11) == 0)
    {
      char s[256];
      char buff2[256];
      strcpy (s, buff);
      strcpy (buff, &s[11]);
      strcpy (buff2, &s[A4GL_findex (s, ')') + 1]);
      buff[A4GL_findex (buff, '(')] = 0;
      strcat (buff, buff2);
      A4GL_convlower (buff);
    }

  A4GL_strip_bracket (buff);
  v = find_variable_ptr (buff);

  if (v == 0)
    return -1;


  *type =
    v->var_data.variable_data_u.v_simple.datatype +
    ((v->var_data.variable_data_u.v_simple.dimensions[0]) << 16);
  *level = 1;

  if (v->arr_subscripts.arr_subscripts_len)
    {
      *arrsize = v->arr_subscripts.arr_subscripts_val[0];
    }
  else
    {
      *arrsize = 0;
    }

  *size = v->var_data.variable_data_u.v_simple.dimensions[0];

  if (arr)
    {
      A4GL_assertion (1, "Shouldn't be requesting arr");
      //make_arr_str (arr, v);
    }



  if (v->var_data.variable_type != VARIABLE_TYPE_SIMPLE)
    {
      A4GL_debug ("Expecting a simple variable ?");
      return -2;
    }

  return *type;

}



/******************************************************************************/
int
check_for_constant (char *name, char *buff)
{
  struct variable *v;
  int dbg = 0;
  /*char buff2[256]; */
  strcpy (buff, name);


  if (dbg)
    {
      if (in_define)
	{
	  PRINTF ("In define..\n");
	}
    }


  if (in_define)
    return 0;


  v = find_variable_ptr (buff);

  if (dbg)
    {
      PRINTF ("v=%p\n", v);
    }

  if (v == 0)
    return 0;

  if (v->var_data.variable_type != VARIABLE_TYPE_CONSTANT)
    return 0;

  if (v->var_data.variable_data_u.v_const.consttype == CONST_TYPE_CHAR
      || v->var_data.variable_data_u.v_const.consttype == CONST_TYPE_IDENT)
    {


      if (v->var_data.variable_data_u.v_const.consttype == CONST_TYPE_CHAR)
	{
	  strcpy (buff,
		  v->var_data.variable_data_u.v_const.constant_data_u.data_c);
	  return 1;
	}

      if (v->var_data.variable_data_u.v_const.consttype == CONST_TYPE_IDENT)
	{
	  strcpy (buff,
		  v->var_data.variable_data_u.v_const.constant_data_u.data_ident);
	  return 4;
	}
    }

  if (v->var_data.variable_data_u.v_const.consttype == CONST_TYPE_FLOAT)
    {
      SPRINTF1 (buff, "%lf",
		v->var_data.variable_data_u.v_const.constant_data_u.data_f);
      return 2;
    }

  if (v->var_data.variable_data_u.v_const.consttype == CONST_TYPE_INTEGER)
    {
      SPRINTF1 (buff, "%d",
		v->var_data.variable_data_u.v_const.constant_data_u.data_i);
      return 3;
    }


/* Shouldn't get to here...*/

  return 0;
}


#ifdef MOVED

/******************************************************************************/
static void
strip_bracket (char *s)
{
  char buff[2048];
  int a;
  int c = 0;
  int f = 0;

  A4GL_debug ("strip_bracket %s\n", s);
  for (a = 0; a <= strlen (s); a++)
    {
      if (s[a] == '[')
	f++;

      if (f == 0 && s[a] != ' ')
	{
	  buff[c++] = s[a];
	  buff[c] = 0;
	  if (c >= sizeof (buff))
	    {
	      A4GL_assertion (1, "buff in strip_bracket too small");
	    }
	}
      if (s[a] == ']')
	f--;
    }
  if (c >= sizeof (buff))
    {
      A4GL_assertion (1, "buff in strip_bracket too small");
    }
  buff[c] = 0;
  strcpy (s, buff);
}


#endif
/******************************************************************************/
int
split_record (char *s, struct variable **v_record, struct variable **v1,
	      struct variable **v2, char bindtype)
{
  char buff[256];
  char endoflist[256];
  char save[256];
  char *ptr;

  /* MJA - NEWVARIABLE */
  A4GL_debug ("SPLIT_RECORD : %s\n", s);

  if (strchr (s, '\n'))
    {
      char *ptr1;
      char *ptr2;

      char r1[256];
      char r2[256];
      /*char buff[256]; */

      A4GL_debug ("Got a thru...");

      strcpy (save, s);
      s = save;

      ptr = strchr (save, '\n');

      *ptr = 0;
      ptr++;

      strcpy (r1, s);
      ptr1 = strrchr (r1, '.');
      *ptr1 = 0;
      ptr1++;

      strcpy (r2, s);
      ptr2 = strrchr (r2, '.');
      *ptr2 = 0;
      ptr2++;

      if (A4GL_aubit_strcasecmp (r1, r2) != 0)
	{
	  a4gl_yyerror ("Records for thru look different...");
	  return 0;
	}


      A4GL_debug ("Record : %s\n", r1);
      strcpy (s, r1);
      strcpy (endoflist, r1);
      strcat (endoflist, ".");
      strcat (endoflist, ptr2);




      strcat (r1, ".*");

      *v_record = find_variable_ptr (r1);


      *v1 = find_variable_ptr (endoflist);

      *v2 = find_variable_ptr (ptr);
    }
  else
    {
      strcpy (buff, s);
      *v_record = find_variable_ptr (buff);

      if (*v_record == 0)
	{
	  PRINTF ("Whoops - %s record not found\n", buff);
	  a4gl_yyerror ("Record not found...");
	  return 0;
	}

      if (strchr (s, '.') == 0)
	{
	  strcat (buff, ".*");
	}
      *v1 =
	(*v_record)->var_data.variable_data_u.v_record.variables.variables_val[0];
      *v2 =
	(*v_record)->var_data.variable_data_u.v_record.variables.
	variables_val[(*v_record)->var_data.variable_data_u.v_record.variables.variables_len -
		      1];
    }

  if ((*v_record)->var_data.variable_type != VARIABLE_TYPE_RECORD
      && (*v_record)->var_data.variable_type != VARIABLE_TYPE_OBJECT)
    {
      PRINTF ("Couldn't identify start as a record\n");
      return 0;
    }

  if ((*v1)->var_data.variable_type != VARIABLE_TYPE_SIMPLE)
    {
      PRINTF ("Variable is not simple\n");
      return 0;
    }

  if ((*v2)->var_data.variable_type != VARIABLE_TYPE_SIMPLE)
    {
      PRINTF ("Variable is not simple\n");
      return 0;
    }

  return 1;
}







static struct record_list *
add_to_record_list (struct record_list **list_ptr, char *prefix_buff,
		    struct variable *v, char bindtype)
{
  char buff[257];
  struct record_list_entry *e;
  struct record_list *list;

  if (v->arr_subscripts.arr_subscripts_len)
    {
      /*a4gl_yyerror ("Can't use a variable containing an array in this context\n"); */
      /*return 0; */
    }

  list = *list_ptr;

  if (list == 0)
    {
      PRINTF ("List is empty\n");
      exit (0);
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_SIMPLE)
    {
      int b0;
      int b1;
      int b2;
      //int b3;
      //int b4;
      int dim;
      char subscript[255];
      char fmt[255];
      /* We've got another bl**dy record - expand this one too... */

      strcpy (subscript, "");
      strcpy (fmt, "");
      dim = v->arr_subscripts.arr_subscripts_len+1;
	/*
      if (v->arr_subscripts.arr_subscripts_val[0])
	{
	  strcat (fmt, "[%d]");
	  dim = 1;
	}
      if (v->arr_subscripts.arr_subscripts_val[1])
	{
	  strcat (fmt, "[%d]");
	  dim = 2;
	}
      if (v->arr_subscripts[2])
	{
	  strcat (fmt, "[%d]");
	  dim = 3;
	}
*/


#ifdef three_is_enough
      if (v->arr_subscripts.arr_subscripts_val[3])
	{
	  strcat (fmt, "[%d]");
	  dim = 4;
	}
      if (v->arr_subscripts.arr_subscripts_val[4])
	{
	  strcat (fmt, "[%d]");
	  dim = 5;
	}
#endif

      if (A4GL_isyes (acl_getenv ("NO_ARRAY_EXPAND")) || bindtype == 'N')
	{
	  dim = 0;
	}


      if (dim == 0)
	{
	  SPRINTF2 (buff, "%s.%s", prefix_buff,
		    v->names.names.names_val[0].name);
	  list->list =
	    acl_realloc (list->list,
			 (list->records_cnt +
			  1) * sizeof (struct record_list_entry *));
	  e = acl_malloc2 (sizeof (struct record_list_entry));
	  e->variable = v;
	  e->name = acl_strdup (buff);
	  list->list[list->records_cnt] = e;
	  list->records_cnt++;
	  *list_ptr = list;
	}

      if (dim == 1)
	{
	  for (b0 = 0; b0 < v->arr_subscripts.arr_subscripts_val[0]; b0++)
	    {
	      SPRINTF1 (subscript, fmt, b0);
	      SPRINTF3 (buff, "%s.%s%s", prefix_buff,
			v->names.names.names_val[0].name, subscript);
	      list->list =
		acl_realloc (list->list,
			     (list->records_cnt +
			      1) * sizeof (struct record_list_entry *));
	      e = acl_malloc2 (sizeof (struct record_list_entry));
	      e->variable = v;
	      e->name = acl_strdup (buff);
	      list->list[list->records_cnt] = e;
	      list->records_cnt++;
	      *list_ptr = list;
	    }
	}


      if (dim == 2)
	{
	  for (b0 = 0; b0 < v->arr_subscripts.arr_subscripts_val[0]; b0++)
	    {
	      for (b1 = 0; b1 < v->arr_subscripts.arr_subscripts_val[1]; b1++)
		{
		  SPRINTF2 (subscript, fmt, b0, b1);
		  SPRINTF3 (buff, "%s.%s%s", prefix_buff,
			    v->names.names.names_val[0].name, subscript);
		  list->list =
		    acl_realloc (list->list,
				 (list->records_cnt +
				  1) * sizeof (struct record_list_entry *));
		  e = acl_malloc2 (sizeof (struct record_list_entry));
		  e->variable = v;
		  e->name = acl_strdup (buff);
		  list->list[list->records_cnt] = e;
		  list->records_cnt++;
		  *list_ptr = list;
		}
	    }
	}

      if (dim == 3)
	{
	  for (b0 = 0; b0 < v->arr_subscripts.arr_subscripts_val[0]; b0++)
	    {
	      for (b1 = 0; b1 < v->arr_subscripts.arr_subscripts_val[1]; b1++)
		{
		  for (b2 = 0; b2 < v->arr_subscripts.arr_subscripts_val[2]; b2++)
		    {
		      SPRINTF3 (subscript, fmt, b0, b1, b2);
		      SPRINTF3 (buff, "%s.%s%s", prefix_buff,
				v->names.names.names_val[0].name, subscript);
		      list->list =
			acl_realloc (list->list,
				     (list->records_cnt +
				      1) *
				     sizeof (struct record_list_entry *));
		      e = acl_malloc2 (sizeof (struct record_list_entry));
		      e->variable = v;
		      e->name = acl_strdup (buff);
		      list->list[list->records_cnt] = e;
		      list->records_cnt++;
		      *list_ptr = list;
		    }
		}
	    }
	}

#ifdef three_is_enough
      if (dim == 4)
	{
	  for (b0 = 0; b0 < v->arr_subscripts[0]; b0++)
	    {
	      for (b1 = 0; b1 < v->arr_subscripts[1]; b1++)
		{
		  for (b2 = 0; b2 < v->arr_subscripts[2]; b2++)
		    {
		      for (b3 = 0; b3 < v->arr_subscripts[3]; b3++)
			{
			  SPRINTF4 (subscript, fmt, b0, b1, b2, b3);
			  SPRINTF3 (buff, "%s.%s%s", prefix_buff,
				    v->names.names.names_val[0].name,
				    subscript);
			  list->list =
			    acl_realloc (list->list,
					 (list->records_cnt +
					  1) *
					 sizeof (struct record_list_entry *));
			  e = acl_malloc2 (sizeof (struct record_list_entry));
			  e->variable = v;
			  e->name = acl_strdup (buff);
			  list->list[list->records_cnt] = e;
			  list->records_cnt++;
			  *list_ptr = list;
			}
		    }
		}
	    }
	}

      if (dim == 5)
	{
	  for (b0 = 0; b0 < v->arr_subscripts[0]; b0++)
	    {
	      for (b1 = 0; b1 < v->arr_subscripts[1]; b1++)
		{
		  for (b2 = 0; b2 < v->arr_subscripts[2]; b2++)
		    {
		      for (b3 = 0; b3 < v->arr_subscripts[3]; b3++)
			{
			  for (b4 = 0; b4 < v->arr_subscripts[4]; b4++)
			    {
			      SPRINTF5 (subscript, fmt, b0, b1, b2, b3, b4);
			      SPRINTF3 (buff, "%s.%s%s", prefix_buff,
					v->names.names.names_val[0].name,
					subscript);
			      list->list =
				acl_realloc (list->list,
					     (list->records_cnt +
					      1) *
					     sizeof (struct record_list_entry
						     *));
			      e =
				acl_malloc2 (sizeof
					     (struct record_list_entry));
			      e->variable = v;
			      e->name = acl_strdup (buff);
			      list->list[list->records_cnt] = e;
			      list->records_cnt++;
			      *list_ptr = list;
			    }
			}
		    }
		}
	    }
	}

#endif
      return list;
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_RECORD
      || v->var_data.variable_type == VARIABLE_TYPE_OBJECT)
    {
      int b0;
      int b1;
      int b2;
      //int b3;
      //int b4;
      int dim;
      char subscript[255];
      char fmt[255];

      /* We've got another bl**dy record - expand this one too... */

      strcpy (subscript, "");
      strcpy (fmt, "");
      dim = 0;
      if (v->arr_subscripts.arr_subscripts_val[0])
	{
	  strcat (fmt, "[%d]");
	  dim = 1;
	}
      if (v->arr_subscripts.arr_subscripts_val[1])
	{
	  strcat (fmt, "[%d]");
	  dim = 2;
	}
      if (v->arr_subscripts.arr_subscripts_val[2])
	{
	  strcat (fmt, "[%d]");
	  dim = 3;
	}
#ifdef three_is_enough
      if (v->arr_subscripts.arr_subscripts_val[3])
	{
	  strcat (fmt, "[%d]");
	  dim = 4;
	}
      if (v->arr_subscripts[4])
	{
	  strcat (fmt, "[%d]");
	  dim = 5;
	}
#endif
      if (A4GL_isyes (acl_getenv ("NO_ARRAY_EXPAND")) || bindtype == 'N')
	{
	  dim = 0;
	}



      if (dim == 0)
	{
	  SPRINTF2 (buff, "%s.%s.*", prefix_buff,
		    v->names.names.names_val[0].name);
	  return split_record_list (buff, buff, list, bindtype);
	}

      if (dim == 1)
	{
	  for (b0 = 0; b0 < v->arr_subscripts.arr_subscripts_val[0]; b0++)
	    {
	      SPRINTF1 (subscript, fmt, b0);
	      SPRINTF3 (buff, "%s.%s%s.*", prefix_buff,
			v->names.names.names_val[0].name, subscript);
	      split_record_list (buff, buff, list, bindtype);
	    }
	}


      if (dim == 2)
	{
	  for (b0 = 0; b0 < v->arr_subscripts.arr_subscripts_val[0]; b0++)
	    {
	      for (b1 = 0; b1 < v->arr_subscripts.arr_subscripts_val[1]; b1++)
		{
		  SPRINTF2 (subscript, fmt, b0, b1);
		  SPRINTF3 (buff, "%s.%s%s.*", prefix_buff,
			    v->names.names.names_val[0].name, subscript);
		  split_record_list (buff, buff, list, bindtype);
		}
	    }
	}

      if (dim == 3)
	{
	  for (b0 = 0; b0 < v->arr_subscripts.arr_subscripts_val[0]; b0++)
	    {
	      for (b1 = 0; b1 < v->arr_subscripts.arr_subscripts_val[1]; b1++)
		{
		  for (b2 = 0; b2 < v->arr_subscripts.arr_subscripts_val[2]; b2++)
		    {
		      SPRINTF3 (subscript, fmt, b0, b1, b2);
		      SPRINTF3 (buff, "%s.%s%s.*", prefix_buff,
				v->names.names.names_val[0].name, subscript);
		      split_record_list (buff, buff, list, bindtype);
		    }
		}
	    }
	}

#ifdef three_is_enough
      if (dim == 4)
	{
	  for (b0 = 0; b0 < v->arr_subscripts[0]; b0++)
	    {
	      for (b1 = 0; b1 < v->arr_subscripts[1]; b1++)
		{
		  for (b2 = 0; b2 < v->arr_subscripts[2]; b2++)
		    {
		      for (b3 = 0; b3 < v->arr_subscripts[3]; b3++)
			{
			  SPRINTF4 (subscript, fmt, b0, b1, b2, b3);
			  SPRINTF3 (buff, "%s.%s%s.*", prefix_buff,
				    v->names.names.names_val[0].name,
				    subscript);
			  split_record_list (buff, buff, list, bindtype);
			}
		    }
		}
	    }
	}

      if (dim == 5)
	{
	  for (b0 = 0; b0 < v->arr_subscripts[0]; b0++)
	    {
	      for (b1 = 0; b1 < v->arr_subscripts[1]; b1++)
		{
		  for (b2 = 0; b2 < v->arr_subscripts[2]; b2++)
		    {
		      for (b3 = 0; b3 < v->arr_subscripts[3]; b3++)
			{
			  for (b4 = 0; b4 < v->arr_subscripts[4]; b4++)
			    {
			      SPRINTF5 (subscript, fmt, b0, b1, b2, b3, b4);
			      SPRINTF3 (buff, "%s.%s%s.*", prefix_buff,
					v->names.names.names_val[0].name,
					subscript);
			      split_record_list (buff, buff, list, bindtype);
			    }
			}
		    }
		}
	    }
	}

#endif

      return list;

    }
  return 0;
}


struct record_list *
split_record_list (char *s, char *prefix, struct record_list *list,
		   char bindtype)
{
  char *ptr;
  char record1[256];
  char record2[256];
  char subrecord1[256];
  char subrecord2[256];
  char *dot[2];
  char prefix_buff[256];
  int a;
  int record_start = -1;
  int record_end = -1;
  struct variable *v_record;
  A4GL_debug ("Split_record_list... %s", s);

  if (strchr (s, '\n'))
    {
      strcpy (record1, s);
      ptr = strchr (record1, '\n');
      *ptr = 0;
      ptr++;
      strcpy (record2, ptr);

      if (record2[0] >= 'A' && record2[0] <= 'Z' && record2[1] == '_')
	{
	  strcpy (record2, A4GL_unscope (ptr));
	}

      A4GL_debug ("Looking for dot in record1 : %s", record1);
      dot[0] = strrchr (record1, '.');
      A4GL_debug ("Looking for dot in record2 : %s", record2);
      dot[1] = strrchr (record2, '.');

      if (dot[0] == 0 || dot[1] == 0)
	{
	  /* Can't find a dot in a thru ? */
	  a4gl_yyerror
	    ("At least one of the entries in the 'thru' is not part of a record");
	  return 0;
	}
      *dot[0] = 0;
      *dot[1] = 0;
      if (A4GL_aubit_strcasecmp (record1, record2) != 0)
	{
	  A4GL_debug ("Thru is bad : '%s' '%s'", record1, record2);
	  a4gl_yyerror ("The 'thru' contains different records..");
	  return 0;
	}

      A4GL_debug ("record1=%s record2=%s\n", record1, record2);

      A4GL_debug ("prefix=%s\n", prefix);

      if (prefix != 0 && strlen (prefix))
	{
	  SPRINTF1 (prefix_buff, "%s.", prefix);
	}
      else
	{
	  strcpy (prefix_buff, "");
	}

      strcat (prefix_buff, record1);

      dot[0]++;
      dot[1]++;

      strcpy (subrecord1, dot[0]);
      strcpy (subrecord2, dot[1]);

      A4GL_debug ("subrecord1=%s subrecord2=%s\n", subrecord1, subrecord2);

      /* At this point record1 and record2 should be the same... */
      /* We'll get rid of any crud from record2 (any brackets etc) to find it */
      /* in our variables list */
      /* We'll keep record1 intact.. */

      A4GL_strip_bracket (record2);
      v_record = find_variable_ptr (record2);

      /* Can we find it - is it declared ? */
      if (v_record == 0)
	{
	  PRINTF ("Whoops - record not found for %s (1)\n", record2);
	  a4gl_yyerror ("Record not found");
	  return 0;
	}

      record_start = -1;
      record_end = -1;

      A4GL_assertion (v_record->var_data.variable_data_u.v_record.variables.
		      variables_len !=
		      v_record->var_data.variable_data_u.v_record.variables.variables_len, "Mismatch");

      for (a = 0;
	   a < v_record->var_data.variable_data_u.v_record.variables.variables_len;
	   a++)
	{
	  A4GL_debug ("Record @ %d = %s", a,
		      v_record->var_data.variable_data_u.v_record.variables.
		      variables_val[a]->names.names.names_val[0].name);
	  if (A4GL_aubit_strcasecmp
	      (v_record->var_data.variable_data_u.v_record.variables.
	       variables_val[a]->names.names.names_val[0].name,
	       subrecord1) == 0)
	    {
	      A4GL_debug ("Record start @ %d\n", a);
	      record_start = a;
	    }
	  if (A4GL_aubit_strcasecmp
	      (v_record->var_data.variable_data_u.v_record.variables.
	       variables_val[a]->names.names.names_val[0].name,
	       subrecord2) == 0)
	    {
	      A4GL_debug ("Record end @ %d\n", a);
	      record_end = a;
	    }
	}

    }
  else
    {
      strcpy (record1, s);
      dot[0] = strrchr (record1, '.');
      if (dot[0])
	*dot[0] = 0;
      strcpy (prefix_buff, record1);

      v_record = find_variable_ptr (record1);

      if (v_record == 0)
	{
	  PRINTF ("Whoops - record not found for %s(2)\n", record1);
	  a4gl_yyerror ("Record not found");
	  return 0;
	}

      record_start = 0;
      record_end =
	v_record->var_data.variable_data_u.v_record.variables.variables_len - 1;
    }



  if (v_record->var_data.variable_type != VARIABLE_TYPE_RECORD
      && v_record->var_data.variable_type != VARIABLE_TYPE_OBJECT)
    {

      if (strstr (s, ".*") != 0 && strlen (prefix) == 0)
	{
	  /*extern int yyline; */
	  char buff[255];
	  char buff2[255];
	  char *ptr;
	  struct record_list_entry *e;
	  FPRINTF (stderr, "WARNING : Using a .* on a non-record - %s\n", s);
	  strcpy (buff, s);
	  A4GL_strip_bracket (buff);
	  ptr = strstr (buff, ".*");
	  *ptr = 0;
	  v_record = find_variable_ptr (buff);
	  strcpy (buff, s);
	  ptr = strstr (buff, ".*");
	  *ptr = 0;
	  list = acl_malloc2 (sizeof (struct record_list));
	  list->list = 0;
	  list->records_cnt = 0;
	  list->list = acl_malloc2 (sizeof (struct record_list_entry *));
	  e = acl_malloc2 (sizeof (struct record_list_entry));
	  SPRINTF1 (buff2, "%s", buff);
	  e->variable = (struct variable *) curr_v;
	  e->name = acl_strdup (buff2);
	  list->list[list->records_cnt] = e;
	  list->records_cnt++;

	  return list;
	}

      a4gl_yyerror ("ERROR: Variable is not a record!\n");
      return 0;
    }

  if (record_start == -1)
    {
      a4gl_yyerror ("Couldn't find start variable");
      return 0;
    }

  if (record_end == -1)
    {
      a4gl_yyerror ("Couldn't find end variable");
      return 0;
    }
  if (record_start > record_end)
    {
      a4gl_yyerror ("Starting point in THRU is after the end point");
      return 0;
    }

  if (list == 0)
    {
      list = acl_malloc2 (sizeof (struct record_list));
      list->list = 0;
      list->records_cnt = 0;
    }


  /* Now - we'll start scanning through our record entries - looking for the first one... */


  for (a = record_start; a <= record_end; a++)
    {

      	if (add_to_record_list (&list, prefix_buff, v_record->var_data.variable_data_u.v_record.variables.variables_val[a], bindtype) == 0)
	{
	  PRINTF ("Bugger -  something went wrong...\n");
	  /* Should free list here... */
	  return 0;
	}
    }
	if (list->list==0) {
			A4GL_assertion(1,"No list");
	}
  return list;
}



#ifdef OLD
/******************************************************************************/
int
push_bind_rec (char *s, char bindtype)
{
  int a;
/*int dtype;*/
/*int size;*/
/*char buff[256];*/
  struct record_list *list;
  A4GL_debug ("In push_bind_rec : '%s'", s);

  list = split_record_list (s, "", 0, bindtype);
  A4GL_debug ("Got list : %p", list);

  if (list == 0)
    {
      a4gl_yyerror ("OOps\n");
      return -1;
    }


  for (a = 0; a < list->records_cnt; a++)
    {
      add_bind (bindtype, list->list[a]->name);
    }

  return 1;
}

#endif


/******************************************************************************/
/* 
* This function does a look through from a starting variable to a finishing variable
* within a record
*/
/******************************************************************************/

struct variable *
get_next_variable (struct variable *record, struct variable *v1,
		   struct variable *v2)
{
  struct variable *v_return;
  int a;

  if (v1 == v2)
    return 0;

  for (a = 0;
       a < record->var_data.variable_data_u.v_record.variables.variables_len; a++)
    {
      if (record->var_data.variable_data_u.v_record.variables.variables_val[a] ==
	  v1)
	{
	  a++;
	  v_return =
	    record->var_data.variable_data_u.v_record.variables.variables_val[a];
	  return v_return;
	}
    }
  a4gl_yyerror ("Can't find variable in record...");
  return 0;
}

#ifdef OLD
struct expr_str *
print_push_rec (char *s, void **b, int always_list)
{
  int a;
  int dtype;
  int size;
  //char buff[256];
  struct record_list *list;
  struct expr_str *vlist;


  list = split_record_list (s, "", 0, ' ');


  if (list == 0 || list->records_cnt==0)
    {
      a4gl_yyerror ("OOps\n");
      return 0;
    }

  if (list->records_cnt > 1 || always_list)
    {
      vlist = A4GL_new_expr_list ();
      for (a = 0; a < list->records_cnt; a++)
	{
	  struct expr_str *p;
	  dtype =
	    list->list[a]->variable->var_data.variable_data_u.v_simple.datatype;
	  size =
	    list->list[a]->variable->var_data.variable_data_u.v_simple.
	    dimensions[0];
	  dtype += size << 16;

	  p = A4GL_new_expr_push_variable (list->list[a]->name, dtype, find_variable_scope(list->list[a]->name)); inc_var_usage(list->list[a]->name);


	  //
	  A4GL_new_append_ptr_list (vlist->expr_str_u.expr_list, p);
	}
      return vlist;
    }
  else
    {
      struct expr_str *p;
      dtype = list->list[0]->variable->var_data.variable_data_u.v_simple.datatype;
      size =
	list->list[0]->variable->var_data.variable_data_u.v_simple.dimensions[0];
      dtype += size << 16;
      p = A4GL_new_expr_push_variable (list->list[0]->name, dtype, find_variable_scope(list->list[0]->name)); inc_var_usage(list->list[0]->name);
      return p;

    }

  //return list->records_cnt;

}
#endif


/******************************************************************************/
void
clr_function_constants ()
{
  /* Here - we need to clear down the current 'locals' lists... */
  /* as a quick fix - we'll just zero everything */
  /* but these *really* should be 'freed' properly..... */
  list_local_cnt = 0;
  list_local_alloc = 0;
  list_local = 0;

  nreturn_values = -1;
}





static char *
make_pk_list (struct vname_name_list *nlist)
{
  static char buff[1024];
  int a;

  for (a = 0; a < nlist->names.names_len; a++)
    {
      if (a == 0)
	{
	  strcpy (buff, nlist->names.names_val[0].name);
	}
      else
	{
	  strcat (buff, ",");
	  strcat (buff, nlist->names.names_val[a].name);
	}

    }
  return buff;
}

/**
 *
 * @param tabname
 * @param pklist
 * @return
 */
int
last_var_is_linked (char *tabname, char *pklist)
{
  /* MJA - NEWVARIABLE */
  strcpy (pklist, "");
  strcpy (tabname, "");

  if (last_variable_ptr_found
      && (last_variable_ptr_found->var_data.variable_type ==
	  VARIABLE_TYPE_RECORD
	  || last_variable_ptr_found->var_data.variable_type ==
	  VARIABLE_TYPE_OBJECT)
      && last_variable_ptr_found->var_data.variable_data_u.v_record.linked)
    {


      strcpy (tabname,
	      last_variable_ptr_found->var_data.variable_data_u.v_record.
	      linked->tabname);
      strcpy (pklist,
	      make_pk_list (&last_variable_ptr_found->var_data.variable_data_u.
			    v_record.linked->col_list));
    }


  if (A4GL_aubit_strcasecmp (tabname, "") == 0)
    return 0;
  else
    return 1;
}





char
find_variable_scope (char *s_in)
{
  struct variable *ptr;
  char s[1024];
  strcpy (s, s_in);

  if (s[0] >= 'A' && s[0] <= 'Z' && s[1] == '_')
    {
      strcpy (s, A4GL_unscope (s));
    }

  if (is_system_variable (s))
    {
      return 'S';
    }

  A4GL_strip_bracket (s);


  ptr = find_variable_ptr (s);

  if (ptr == 0)
    {
      return 0;
    }

  if (ptr->scope == 0)
    {
      return 'G';
    }
  return toupper (ptr->scope);
}

/*
int inc_var_usage_from_binding_list(binding_comp_list *l) {
int a;
	if (l==0) return 1;
	for (a=0;a<l->bindings.bindings_len;a++) {
		inc_var_usage(l->bindings.bindings_val[a].varname);
	}
return 1;
}
*/


/*
int inc_var_assigned_from_binding_list(binding_comp_list *l) {
int a;
	if (l==0) return 1;
	for (a=0;a<l->bindings.bindings_len;a++) {
		inc_var_assigned(l->bindings.bindings_val[a].varname);
	}
	return 1;

}
*/

int inc_var_usage(expr_str *s) {
struct variable *v;
struct variable_usage *u;
struct variable_usage *utop;
if (s->expr_type!=ET_EXPR_VARIABLE_USAGE) return;
u=s->expr_str_u.expr_variable_usage;

utop=u;
while (1) {
	char errbuff[256];
	char scope;
	struct variable_usage *unext;
	unext=u->next;
	u->next=0;
	v=find_variable_vu_ptr(errbuff,utop,&scope,0);
	if (v) {
		v->usage++;
		if (!v->assigned) {
		if (tolower(scope)=='l') { v->flags|=1; }
		}
	} else {
		break;
	}
	if (unext==0) break;
	u->next=unext;
	u=unext;
}
return 1;
}


int inc_var_assigned(expr_str *s) {
struct variable *v;
struct variable_usage *u;
struct variable_usage *utop;
if (s==0) return 1;
if (s->expr_type!=ET_EXPR_VARIABLE_USAGE) return 1;
u=s->expr_str_u.expr_variable_usage;

utop=u;
while (1) {
	char errbuff[256];
	char scope;
	struct variable_usage *unext;
	unext=u->next;
	u->next=0;
	v=find_variable_vu_ptr(errbuff,utop,&scope,0);
	if (v) {
		v->assigned++;
	} else {
		break;
	}
	if (unext==0) break;
	u->next=unext;
	u=unext;
}
return 1;
}

int
is_system_variable (char *s)
{
  //if (strcmp (s, "int_flag") == 0) return 1;
  //if (strcmp (s, "quit_flag") == 0) return 1;

  if (strcmp (s, "a4gl_status") == 0)
    return 1;
  if (strncmp (s, "a4gl_sqlca", 10) == 0)
    return 1;
  if (strcmp (s, "notfound") == 0)
    return 1;
  if (strcmp (s, "false") == 0)
    return 1;
  if (strcmp (s, "true") == 0)
    return 1;
  if (strcmp (s, "today") == 0)
    return 1;
  if (strcmp (s, "user") == 0)
    return 1;
  if (strcmp (s, "pageno") == 0)
    return 1;
  if (strcmp (s, "lineno") == 0)
    return 1;
  if (strcmp (s, "time") == 0)
    return 1;
  if (strcmp (s, "usrtime") == 0)
    return 1;
  if (strcmp (s, "curr_hwnd") == 0)
    return 1;
  if (strcmp (s, "curr_form") == 0)
    return 1;
  if (strcmp (s, "err_file_name") == 0)
    return 1;
  if (strcmp (s, "err_line_no") == 0)
    return 1;
  if (strcmp (s, "curr_file_name") == 0)
    return 1;
  if (strcmp (s, "curr_line_no") == 0)
    return 1;
  if (strcmp (s, "err_status") == 0)
    return 1;
  if (strcmp (s, "aiplib_status") == 0)
    return 1;
  return 0;
}



void
set_last_class_var (char *s)
{
  strcpy (last_class_var, s);
}

char *
get_last_class_var (void)
{
  return last_class_var;
}




struct variable *
find_dim (char *s)
{
  struct variable *p;
  p = find_variable_in (s, list_types, list_types_cnt);
  return p;
}




void
push_dim (char *s)
{
  struct variable *ptr;
  ptr = find_dim (s);
  if (!ptr)
    {
      a4gl_yyerror ("Invalid datatype");
      return;
    }

  variable_action (0, s, 0, 0, "push_dim");
}

/*
int
has_fbind (char *s)
{
  int a;
  extern int fbindcnt;
  extern struct binding_comp *fbind;
  for (a = 0; a < fbindcnt; a++)
    {
      char buff[256];
      char *ptr;
      strcpy (buff, A4GL_unscope (fbind[a].varname));
      ptr = strchr (buff, '.');
      if (ptr)
	{
	  *ptr = 0;
	}
      if (strcmp (buff, s) == 0)
	return 1;
    }
  return 0;
}
*/

struct variable_usage *check_var_usage (struct variable_usage *v) {
if (strcmp(v->variable_name,"sqlca")==0) {
	v->variable_name="a4gl_sqlca";
}
if (strcmp(v->variable_name,"status")==0) {
	v->variable_name="a4gl_status";
}
return v;
}





char *describe_subscripts(int n, int *nvals ){ 
static char buff[2000];
int a;
if (n==0) return "";
strcpy(buff,"[");
for (a=0;a<n;a++) {
	char smbuff[256];
	if (a)strcat(buff,",");
	sprintf(smbuff,"%d",nvals[a]);
	strcat(buff,smbuff);
}
strcat(buff,"]");
return buff;

}

// This function 'describes' a variable so we can compare if two record structures are alike
// The format does not bother with variable names - just datatypes and array sizes
// the format is 
//              {DTYPE:DTYPESIZE}
//      we use [ARRSIZE,ARRSIZE] for an array
//      we use ( ... ) for a record
//
// If we dont think we can copy any part - we'll just return 0...
//
char *
describe_variable (struct variable *v)
{
  char buff[20000];
  char *ptr;
  strcpy (buff, "");
  switch (v->var_data.variable_type)
    {
    case VARIABLE_TYPE_SIMPLE:
      sprintf (buff, "{%d:%d}%s", v->var_data.variable_data_u.v_simple.datatype & DTYPE_MASK,
	       v->var_data.variable_data_u.v_simple.dimensions[0]);
      break;

    case VARIABLE_TYPE_OBJECT:
      return 0;

    case VARIABLE_TYPE_RECORD:
      ptr = describe_record (&v->var_data.variable_data_u.v_record);
      if (ptr)
	{
	  sprintf (buff, "(%s)%s", ptr,
		   describe_subscripts (v->arr_subscripts.arr_subscripts_len, v->arr_subscripts.arr_subscripts_val));
	  free (ptr);
	}
      else
	{
	  return 0;
	}

    case VARIABLE_TYPE_ASSOC:
      return 0;

    case VARIABLE_TYPE_CONSTANT:
      sprintf (buff, "CONSTANT");
	break;

    case VARIABLE_TYPE_LINKED:
      return 0;

    case VARIABLE_TYPE_FUNCTION_DECLARE:
      sprintf (buff, "");
      break;
    }

  return strdup (buff);
}



static char *
describe_record (struct record_variable *v_record)
{
  int a;
  char buff[20000];
  char *ptr;
  strcpy (buff, "(");
  for (a = 0; a < v_record->variables.variables_len; a++)
    {
      ptr = describe_variable (v_record->variables.variables_val[a]);
      if (ptr)
	{
	  if (a)
	    strcat (buff, ",");
	  strcat (buff, ptr);
	  free (ptr);
	}
      else
	{
	  return 0;
	}
    }
  strcat (buff, "}");
  return strdup (buff);
}




char *describe_variable_usage(variable_usage *u) {
	struct variable *v;
	char scope;
	char errbuff[256];
	v=find_variable_vu_ptr(errbuff,u,&scope,0);
	if (v==0) return 0;
	

}

/* 
 * 
 * v = variable usage to look for
 * scope = pointer to character to store the scope..
 *
 */
struct variable *find_variable_vu_ptr(char *errbuff, struct variable_usage *v, char *scope, int err_if_whole_array) {
  struct variable *ptr;
  strcpy(errbuff,"");
  ptr = find_variable_vu_in (errbuff, v, list_local, list_local_cnt, err_if_whole_array);
  if (ptr)
    {
	v->scope='L';
	*scope='L';
      A4GL_debug ("local variable");
      return ptr;
    }

  ptr = find_variable_vu_in (errbuff, v, list_module, list_module_cnt, err_if_whole_array);
  if (ptr)
    {
	v->scope='M';
	*scope='M';
      A4GL_debug ("Module variable");
      return ptr;
    }

  ptr = find_variable_vu_in (errbuff, v, list_global, list_global_cnt, err_if_whole_array);
  if (ptr)
    {
	v->scope='G';
	*scope='G';
      A4GL_debug ("Global variable");
      return ptr;
    }

  ptr = find_variable_vu_in (errbuff, v, list_imported_global, list_imported_global_cnt, err_if_whole_array);
  if (ptr)
    {
	v->scope='g';
	*scope='g';
      A4GL_debug ("Global variable");
      return ptr;
    }
  return ptr; /* Will be NULL - or it would have been returned already... */
}





#ifdef MOVED

	int is_valid_vname(struct variable *v,char scope) { 
	char *nm;
	nm=v->names.names.names_val[0].name; 

	if (strlen(nm)<4)  return 0; // too short for sn_
	if (nm[2]!='_') return 0;

	if (nm[1]=='v') {
			return 1;
	}

	switch (v->var_data.variable_type) {
		case VARIABLE_TYPE_SIMPLE:
			switch (v-> var_data.variable_data_u.v_simple.datatype & DTYPE_MASK) {
				case DTYPE_CHAR: if (nm[1]!='c') return 0; else return 1;
				case DTYPE_SMINT: if (nm[1]!='b' && nm[1]!='s') return 0; else return 1;
				case DTYPE_SERIAL: 
				case DTYPE_INT: if (nm[1]!='n') return 0; else return 1;
				case DTYPE_DATE: if (nm[1]!='d') return 0; else return 1;
				case DTYPE_DECIMAL: if (nm[1]!='l') return 0; else return 1;
				case DTYPE_INTERVAL: if (nm[1]!='i') return 0; else return 1;
			} 
			// No specific rule - so must be ok...
			return 1;

		case VARIABLE_TYPE_RECORD:
				if (nm[1]!='r') return 0; else return 1;



		case VARIABLE_TYPE_ASSOC:
		case VARIABLE_TYPE_CONSTANT:
		case VARIABLE_TYPE_FUNCTION_DECLARE:
		case VARIABLE_TYPE_OBJECT:
		case VARIABLE_TYPE_LINKED: return 1;


		//case VARIABLE_TYPE_ARRAY:
		//if (nm[1]!='a') return 0; else return 1;
	}

	return 1;
}
#endif
