#include "a4gl_4glc_int.h"
#include "variables.h"


// CONFIGURABLE...
#define RECORD_LEVELS 128
// 




/******************************************************************************/
// Prototypes of static functions in this module...
static int has_name (struct name_list *namelist, char *name);
static char get_variable_user_system (void);
static struct variable *make_constant (char *name, char *value,
				       char *int_or_char);
static void initialize_v (void);
static void set_arr_subscripts (char *s, int record_cnt);
static int add_to_scope (int record_cnt, int unroll);
static void dump_variable_records (struct variable **v, int cnt, int lvl);
static struct variable *find_variable_in (char *s, struct variable **list,
					  int cnt);

static char get_current_variable_scope (void);

static void make_arr_str (char *s, struct variable *v);
static void strip_bracket (char *s);
static void print_variable (struct variable *v, char scope, int level);
static char *rettype_integer (int n);
static struct record_list *add_to_record_list (struct record_list **list_ptr,
					       char *prefix_buff,
					       struct variable *v);

/******************************************************************************/


void dump_gvars (void);
void set_yytext (char *s);
int isin_command (char *s);
char *rettype (char *s);



#define ASSOC_INTERNAL "Internal"

extern int in_define;

// Are we setting User variables or System Variables ?
char system_or_user = '-';


// Lists for our variables in each scope...
struct variable **list_global = 0;	// Our List
int list_global_cnt = 0;	// Number used in our list
int list_global_alloc = 0;	// Space allocated for our list


struct variable **list_imported_global = 0;	// Our List
int list_imported_global_cnt = 0;	// Number used in our list
int list_imported_global_alloc = 0;	// Space allocated for our list

struct variable **list_module = 0;
int list_module_cnt = 0;
int list_module_alloc = 0;


struct variable **list_local;
int list_local_cnt;
int list_local_alloc;


// Current variable...
struct variable *v[RECORD_LEVELS];
int v_initialized = 0;

struct variable *last_variable_ptr_found = 0;


char variable_scope = 'm';

/******************************************************************************/
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

//static void set_variable_scope(char n)        { scope=n; }
//static char get_variable_scope()              { return scope; }



/******************************************************************************/
static void
initialize_v (void)
{
  int a;
  for (a = 0; a < RECORD_LEVELS; a++)
    {
      v[a] = 0;
    }
  v_initialized = 1;
}



/******************************************************************************/
static void
set_arr_subscripts (char *s_orig, int record_cnt)
{
  int a;
  char *ptr;
  char s[512];


  if (s_orig == 0)
    {
      v[record_cnt]->is_array = 0;
      for (a = 0; a < MAX_ARR_SUB; a++)
	{
	  v[record_cnt]->arr_subscripts[a] = 0;
	}
    }
  else
    {
      int subcnt = 0;
      strcpy (s, s_orig);
      v[record_cnt]->is_array = 1;

      ptr = s;

      for (a = 0; a < strlen (s); a++)
	{
	  if (s[a] == ']')
	    {
	      s[a] = 0;
	      v[record_cnt]->arr_subscripts[subcnt++] = atoi (ptr);
	      ptr = &s[a + 2];
	      a++;		// Skip over '['
	    }
	}
      v[record_cnt]->arr_subscripts[subcnt++] = atoi (ptr);
    }

}



/******************************************************************************/
static void
add_linked_columns (struct linked_variable *linked, char *collist_orig)
{
  struct name_list *ptr_name = 0;
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
	      linked->col_list.name = strdup (ptr);
	      linked->col_list.next = 0;
	      ptr_name = &linked->col_list;
	    }
	  else
	    {
	      ptr_name->next = malloc (sizeof (struct name_list));
	      ptr_name = ptr_name->next;
	      ptr_name->name = strdup (ptr);
	      ptr_name->next = 0;
	    }
	  ptr = &collist[a + 1];

	}
    }
// Last column to add...
  if (ptr_name == 0)
    {
      linked->col_list.name = strdup (ptr);
      linked->col_list.next = 0;
    }
  else
    {
      ptr_name->next = malloc (sizeof (struct name_list));
      ptr_name = ptr_name->next;
      ptr_name->name = strdup (ptr);
      ptr_name->next = 0;
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
	  struct name_list *ptr;
#define MODE_ADD_CONSTANT  	1
#define MODE_ADD_RECORD    	2
#define MODE_ADD_TYPE      	3
#define MODE_ADD_LINK      	4
#define MODE_ADD_ARRAY     	5
#define MODE_ADD_ASSOC_ARRAY  	6
#define MODE_ADD_NAME		7
#define MODE_ADD_ENDRECORD	8
#define MODE_ADD_TO_SCOPE	9
#define MODE_ADD_END_ASSOC	10

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
    "ADD_END_ASSOC"
  };
#endif



  int mode = 0;

  if (!v_initialized)
    initialize_v ();



  scope = get_current_variable_scope ();

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



  debug ("variable_action (%d %s %s %s %s)\n", category, name, type, n,
	 function);

// Try to determine what we are doing.
// This comes about from the old way of handling variables and
// should be fixed properly sometime...

  if (strcmp (function, "add_constant") == 0 && mode == 0)
    {
      mode = MODE_ADD_CONSTANT;
    }

  if (strcmp (function, "add_link_to") == 0 && mode == 0)
    {
      mode = MODE_ADD_LINK;
    }

  if (strcmp (name, "_RECORD") == 0 && mode == 0)
    {
      mode = MODE_ADD_RECORD;
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

debug("Mode=%d\n",mode);

// We don't need to do the adding of the array for an assoc_array - this will already have been done...
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




// Have we worked it out ?
  if (mode == 0)
    {
      // This shouldn't happen....
      printf ("Don't know what to do...\n");
      printf ("%d Name = %s type = %s n=%s function = %s\n", category, name,
	      type, n, function);
      exit (1);
    }



// Now actually do it...
  switch (mode)
    {
    case MODE_ADD_CONSTANT:
      v[record_cnt] = make_constant (name, type, n);
      mode = MODE_ADD_TO_SCOPE;
      break;


    case MODE_ADD_RECORD:
      v[record_cnt]->variable_type = VARIABLE_TYPE_RECORD;
      v[record_cnt]->data.v_record.variables = 0;
      v[record_cnt]->data.v_record.record_cnt = 0;
      v[record_cnt]->data.v_record.record_alloc = 0;
      v[record_cnt]->data.v_record.linked = 0;
      record_cnt++;
      v[record_cnt] = 0;	// Make sure we're starting fresh...
      break;

    case MODE_ADD_ENDRECORD:
      v[record_cnt] = 0;
      record_cnt--;
      add_to_scope (record_cnt, 0);
      v[record_cnt] = 0;
      break;

    case MODE_ADD_TYPE:
      v[record_cnt]->data.v_simple.datatype = find_type (name);
      v[record_cnt]->data.v_simple.dimensions[0] = atoi (type);
      v[record_cnt]->data.v_simple.dimensions[1] = 0;
      mode = MODE_ADD_TO_SCOPE;
      break;

    case MODE_ADD_ASSOC_ARRAY:
      v[record_cnt]->variable_type = VARIABLE_TYPE_ASSOC;
      v[record_cnt]->data.v_assoc.size = atoi (n);
      v[record_cnt]->data.v_assoc.char_size = atoi (type);
      v[record_cnt]->data.v_assoc.variables = 0;
      print_declare_associate_1 (v[record_cnt]->names.name, n, type);
      record_cnt++;
      v[record_cnt] = malloc (sizeof (struct variable));
      set_arr_subscripts (0, record_cnt);
      v[record_cnt]->names.name = ASSOC_INTERNAL;
      v[record_cnt]->names.next = 0;
      v[record_cnt]->is_static = 0;
      v[record_cnt]->is_extern = 0;
      v[record_cnt]->user_system = get_variable_user_system ();
      set_arr_subscripts (n, record_cnt);

      adding_assoc = 1;
      break;


    case MODE_ADD_END_ASSOC:
      v[record_cnt] = 0;
      record_cnt--;
      add_to_scope (record_cnt, 0);
      v[record_cnt] = 0;
      break;

    case MODE_ADD_LINK:
      {
	struct linked_variable *linked;
	linked = malloc (sizeof (struct linked_variable));
	linked->tabname = strdup (name);
	add_linked_columns (linked, type);
	v[record_cnt - 1]->data.v_record.linked = linked;
	break;
      }



    case MODE_ADD_ARRAY:
      set_arr_subscripts (n, record_cnt);
      break;


    case MODE_ADD_NAME:
      break;			// We'll deal with this later

    default:
      printf ("Run out of actions %d\n", mode);
      printf ("%d Name = %s type = %s n=%s function = %s\n\n", category,
	      name, type, n, function);
      exit (0);
    }


  // We need to do this outside of the switch so that ADD_ASSOC and ADD_LINK can call it too...

  if (mode == MODE_ADD_NAME)
    {
      // Is this the first name at this level ?
      if (v[record_cnt] == 0)
	{
	  debug("First at level");
	  v[record_cnt] = malloc (sizeof (struct variable));
	  v[record_cnt]->names.name = strdup (name);
	  v[record_cnt]->names.next = 0;
	  v[record_cnt]->variable_type = VARIABLE_TYPE_SIMPLE;
	  v[record_cnt]->user_system = get_variable_user_system ();
	  v[record_cnt]->is_static = 0;
	  v[record_cnt]->is_extern = 0;

	  // Reports, menuhandlers & formhandlers
	  // should all maintain their values between calls - hence
	  // they will always be static....
	  if (isin_command ("REPORT") || isin_command ("FORMHANDLER")
	      || isin_command ("MENUHANDLER"))
	    {
	      v[record_cnt]->is_static = 1;
	    }


	  set_arr_subscripts (0, record_cnt);
	}
      else
	{
	  // We've already got one name..
	  // Add some more to the list..

	debug("Already have first at this level");
	  // Walk to the end of the current list of names
	  ptr = &v[record_cnt]->names;
	debug("Walking..");
	  while (ptr->next != 0) {
		debug("Walk..");
	    ptr = ptr->next;
	}

	  ptr->next = malloc (sizeof (struct name_list));
	  ptr = ptr->next;
	  ptr->next = 0;
	  ptr->name = strdup (name);
	}

	

	// some debugging stuff...
  	ptr = &v[record_cnt]->names;
	while (ptr) {
		debug(" --> %s\n",ptr->name);
		ptr=ptr->next;
	}
	
    }

  // v[record_cnt] should now hold the variable we've just generated
  //
  if (mode == MODE_ADD_TO_SCOPE)
    {
      add_to_scope (record_cnt, 0);
      v[record_cnt] = 0;
    }
}



/******************************************************************************/
static struct variable *
make_constant (char *name, char *value, char *int_or_char)
{
  struct variable *local_v;
  int c;
  local_v = (struct variable *) malloc (sizeof (struct variable));
  local_v->names.name = strdup (name);
  local_v->names.next = 0;
  local_v->variable_type = VARIABLE_TYPE_CONSTANT;
  local_v->user_system = get_variable_user_system ();
  local_v->is_static = 0;
  local_v->is_extern = 0;
  local_v->is_array = 0;
  for (c = 0; c < MAX_ARR_SUB; c++)
    {
      local_v->arr_subscripts[c] = 0;
    }
  local_v->is_array = 0;

  if (int_or_char[0] == 'c')
    {
      local_v->data.v_const.consttype = CONST_TYPE_CHAR;
      local_v->data.v_const.data.data_c = strdup (value);
    }

  if (int_or_char[0] == 'i')
    {
      local_v->data.v_const.consttype = CONST_TYPE_INTEGER;
      local_v->data.v_const.data.data_i = atoi (value);
    }
  if (int_or_char[0] == 'f')
    {
      local_v->data.v_const.consttype = CONST_TYPE_FLOAT;
      local_v->data.v_const.data.data_f = atof (value);
    }

  return local_v;
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
  struct name_list *names;
  int a;
  struct variable *v_new;
  char scope;
  struct variable *orig;
  variable_holder = 0;
  scope = get_current_variable_scope ();


/*
  if (unroll == 0)
    {

      orig = v[record_cnt];
      names = v[record_cnt]->names.next;
      v[record_cnt]->names.next = 0;

      if (names)
	{
	  while (names)
	    {
	      v_new = malloc (sizeof (struct variable));
	      memcpy (v_new, v[record_cnt], sizeof (struct variable));
	      v[record_cnt] = v_new;
	      v[record_cnt]->names.name = names->name;
	      v[record_cnt]->names.next = 0;
	      add_to_scope (record_cnt, 1);
	      names = names->next;
	    }
	  v[record_cnt] = orig;
	}
    }

*/
  if (unroll == 0)
    {

      orig = v[record_cnt];
      names = v[record_cnt]->names.next;

      if (names)
	{
      	  names = v[record_cnt];
	  while (names)
	    {
	      v_new = malloc (sizeof (struct variable));
	      memcpy (v_new, v[record_cnt], sizeof (struct variable));
	      v[record_cnt] = v_new;
	      v[record_cnt]->names.name = names->name;
	      v[record_cnt]->names.next = 0;
	      add_to_scope (record_cnt, 1);
	      names = names->next;
	    }
		return 1;
	}
    }


// If record_cnt is set then we're not adding it as a variable 
// to local/module/global scope - but to the record at the level above...


  if (record_cnt)
    {
      // We can add to an associative array - or a record....

      if (v[record_cnt - 1]->variable_type != VARIABLE_TYPE_RECORD
	  && v[record_cnt - 1]->variable_type != VARIABLE_TYPE_ASSOC)
	{
	  // We have a problem...
	  printf ("Last variable level was not a record!\n");
	  assert (0);
	}


      if (v[record_cnt - 1]->variable_type == VARIABLE_TYPE_RECORD)
	{
	  variable_holder = &v[record_cnt - 1]->data.v_record.variables;
	  counter = &v[record_cnt - 1]->data.v_record.record_cnt;
	  alloc = &v[record_cnt - 1]->data.v_record.record_alloc;
	}

      // We can only store one variable here...
      if (v[record_cnt - 1]->variable_type == VARIABLE_TYPE_ASSOC)
	{
	  tmp_1 = 0;
	  tmp_2 = 0;
	  variable_holder = &v[record_cnt - 1]->data.v_assoc.variables;
	  tmp_1 = 0;
	  tmp_2 = 0;
	  counter = &tmp_1;
	  alloc = &tmp_2;
	}

      sprintf (local_scope, "%d", record_cnt);
    }
  else
    {

      if (scope == 'g')
	{
	  sprintf (local_scope, "g");
	  variable_holder = &list_global;
	  counter = &list_global_cnt;
	  alloc = &list_global_alloc;
	}

      if (scope == 'G')
	{
	  sprintf (local_scope, "g");
	  variable_holder = &list_imported_global;
	  counter = &list_imported_global_cnt;
	  alloc = &list_imported_global_alloc;
	}

      if (scope == 'm')
	{
	  sprintf (local_scope, "m");
	  variable_holder = &list_module;
	  counter = &list_module_cnt;
	  alloc = &list_module_alloc;
	}

      if (scope == 'l')
	{
	  sprintf (local_scope, "l");
	  variable_holder = &list_local;
	  counter = &list_local_cnt;
	  alloc = &list_local_alloc;
	}

    }


// Now - we can add to our variables list for our scope...

  if (*variable_holder && unroll == 0)
    {

      ptr = *variable_holder;
      for (a = 0; a < *counter; a++)
	{
	  if (strcasecmp (ptr[a]->names.name, v[record_cnt]->names.name) == 0)
	    {
	      set_yytext (v[record_cnt]->names.name);
	      exitwith ("Variable is already defined");
	      yyerror ("Variable is already defined");
	      return 0;
	    }
	}
    }





  if (*counter >= *alloc)
    {
      long space;
      (*alloc) += 10;
      space = (*alloc) * sizeof (struct variable *);
      *variable_holder = realloc (*variable_holder, space);
    }


  if (variable_holder == 0)
    {
      printf ("No variable holder!");
      assert (0);
    }

  ptr = *variable_holder;
  ptr[*counter] = v[record_cnt];
  (*counter)++;
  return 1;
}



/******************************************************************************/
static int
has_name (struct name_list *namelist, char *name)
{
  struct name_list *ptr_name = 0;

  if (name == 0)
    return 0;

  ptr_name = namelist;

  while (ptr_name)
    {
      if (strcasecmp (namelist->name, name) == 0)
	return 1;
      debug ("Check %s against %s nope", namelist->name, name);
      ptr_name = ptr_name->next;
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



  // If we have no variables at this level - we can't do anything
  if (list == 0)
    {
      return 0;
    }

  // Copy across our variable so we can play with it...
  strcpy (var_section, s);
  strip_bracket (var_section);
  // Reset our next section (anything after a '.')
  strcpy (var_nextsection, "");

  ptr_c = strchr (var_section, '.');

  if (ptr_c)
    {
      *ptr_c = 0;
      strcpy (var_nextsection, ptr_c + 1);
    }






  for (a = 0; a < cnt; a++)
    {
      v = list[a];
      // Can we find the name at this point ?
      if (!has_name (&v->names, var_section)
	  && !strcmp (var_section, "*") == 0)
	continue;		// No

      // If we get to here we've found our name!
      // Now we need to know what to do next....


      if (v->variable_type == VARIABLE_TYPE_SIMPLE
	  || v->variable_type == VARIABLE_TYPE_CONSTANT)
	{
	  // This is too easy...
	  return v;
	}


      if (v->variable_type == VARIABLE_TYPE_RECORD)
	{


	  // look for the next portion...
	  trim (var_nextsection);
	  if (strcmp (var_nextsection, "*") == 0)
	    {
	      return v;
	    }


	  if (strlen (var_nextsection) == 0)
	    {
	      return v;
	    }




	  return find_variable_in (var_nextsection,
				   v->data.v_record.variables,
				   v->data.v_record.record_cnt);
	}

      if (v->variable_type == VARIABLE_TYPE_ASSOC)
	{
	  char buff[256];
	  // Associate arrays always have a single record like entry for the
	  // associated variable - and its always called 'internal'

	  // If we're just looking for that - then we're fine...
	  // But if that is a record - we need to carry on doing our nextsection bits
	  if (strlen (var_nextsection))
	    {
	      sprintf (buff, "%s.%s", ASSOC_INTERNAL, var_nextsection);
	    }
	  else
	    {
	      sprintf (buff, "%s", ASSOC_INTERNAL);
	    }
	  return find_variable_in (buff, v->data.v_assoc.variables, 1);
	}

    }

  return 0;
}




/******************************************************************************/
struct variable *
find_variable_ptr (char *s)
{
  struct variable *ptr;


// First we look locally - then at module level - then globally

  ptr = find_variable_in (s, list_local, list_local_cnt);
  if (ptr)
    {
      return ptr;
    }

  ptr = find_variable_in (s, list_module, list_module_cnt);
  if (ptr)
    {
      return ptr;
    }

  ptr = find_variable_in (s, list_global, list_global_cnt);
  if (ptr)
    {
      return ptr;
    }


  ptr = find_variable_in (s, list_imported_global, list_imported_global_cnt);
  if (ptr)
    {
      return ptr;
    }


  debug (" variable NOT FOUND\n");

  return 0;
}



/******************************************************************************/
int
find_variable (char *s_in, int *dtype, int *size, int *is_array,
	       void **var_ptr)
{
  struct variable *ptr;
  char s[1024];

  strcpy (s, s_in);
  strip_bracket (s);

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

  // Do they want the pointer ?
  if (var_ptr)
    {
      *var_ptr = ptr;
    }



  if (ptr->variable_type == VARIABLE_TYPE_ASSOC)
    {
      // They don't want the assoc - they want the referenced variable...
      ptr = ptr->data.v_assoc.variables[0];
      *var_ptr = ptr;		// Carry on working with this one instead...
      last_variable_ptr_found = ptr;
    }

  // We will probably have a simple variables at this point...
  if (ptr->variable_type == VARIABLE_TYPE_SIMPLE)
    {
      if (dtype)
	*dtype = ptr->data.v_simple.datatype;

      if (size)
	*size = ptr->data.v_simple.dimensions[0];

      if (is_array)
	*is_array = ptr->is_array;

      return 1;
    }

  if (ptr->variable_type == VARIABLE_TYPE_RECORD)
    {
      debug ("Got a record - looks complicated..");
      return -2;
    }

  if (ptr->variable_type == VARIABLE_TYPE_CONSTANT)
    {
      debug ("Got a constant - Lexer should have filtered that out...");
      return 0;
    }

  // Don't know how we got to here....
  yyerror ("Internal error in find_variable");
  return 0;

}





#define TEST

#ifdef TEST

/******************************************************************************/
void
dump_var_records (void)
{
  printf ("\n\n\nImported Globals\n");
  dump_variable_records (list_imported_global, list_imported_global_cnt, 0);

  printf ("Globals\n");
  dump_variable_records (list_global, list_global_cnt, 0);

  printf ("Module\n");
  dump_variable_records (list_module, list_module_cnt, 0);
  printf ("Local\n");
  dump_variable_records (list_local, list_local_cnt, 0);
  printf ("END\n\n");
}




/******************************************************************************/
static void
dump_variable_records (struct variable **v, int cnt, int lvl)
{
  int a;
  int c;
  struct name_list *ptr;

  for (a = 0; a < cnt; a++)
    {
      for (c = 0; c < lvl; c++)
	{
	  printf ("  ");
	}
      ptr = &v[a]->names;
      while (ptr)
	{
	  printf ("%s", ptr->name);
	  ptr = ptr->next;
	  if (ptr)
	    printf (",");
	}
      printf (" ");


// If its an array - tell them
      if (v[a]->is_array)
	{
	  for (c = 0; c < MAX_ARR_SUB; c++)
	    {
	      if (v[a]->arr_subscripts[c])
		{
		  if (c == 0)
		    {
		      printf ("ARRAY");
		    }
		  printf ("[%d]", v[a]->arr_subscripts[c]);
		}
	      printf (" ");

	    }
	}

      switch (v[a]->variable_type)
	{
	case VARIABLE_TYPE_ASSOC:
	  printf ("ASSOCIATE CHAR(%d) ARRAY[%d] OF\n",
		  v[a]->data.v_assoc.char_size, v[a]->data.v_assoc.size);
	  dump_variable_records (v[a]->data.v_assoc.variables, 1, lvl + 1);
	  break;

	case VARIABLE_TYPE_SIMPLE:
	  printf ("  %d(%d)\n", v[a]->data.v_simple.datatype,
		  v[a]->data.v_simple.dimensions[0]);
	  break;


	case VARIABLE_TYPE_RECORD:
	  printf ("RECORD\n");
	  dump_variable_records (v[a]->data.v_record.variables,
				 v[a]->data.v_record.record_cnt, lvl + 1);
	  printf ("END RECORD\n");

	  if (v[a]->data.v_record.linked)
	    {
	      struct name_list *ptr;
	      printf ("Linked to %s (", v[a]->data.v_record.linked->tabname);
	      ptr = &v[a]->data.v_record.linked->col_list;

	      while (ptr)
		{
		  printf ("%s", ptr->name);
		  ptr = ptr->next;
		  if (ptr)
		    printf (" , ");
		}
	      printf (")\n");
	    }

	  break;

	case VARIABLE_TYPE_CONSTANT:
	  printf ("CONSTANT - ");
	  if (v[a]->data.v_const.consttype == CONST_TYPE_CHAR)
	    {
	      printf ("%s ", v[a]->data.v_const.data.data_c);
	    }
	  else
	    {
	      printf ("%d ", v[a]->data.v_const.data.data_i);
	    }
	  printf ("\n");
	  break;

	default:
	  printf ("Unknown type : %d\n", v[a]->variable_type);


	}

    }
}

#endif

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

  if (isin_command ("FUNC") || isin_command ("REPORT")
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
      if (variable_scope == 'g')
	{
	  scope = 'g';
	}
      if (variable_scope == 'm')
	{
	  scope = 'm';
	}
    }

  return scope;

}




/******************************************************************************/
void
print_variables (void)
{

  char scope;

  // MJA - NEWVARIABLE

  debug ("/**********************************************************/\n");
  debug ("/******************* Variable definitions *****************/\n");
  debug ("/**********************************************************/\n");


  scope = get_current_variable_scope ();



  if (scope == 'l')
    {
      print_local_variables ();
    }

  if (scope == 'g')
    {
      print_global_variables ();
#ifdef DEBUG
      debug ("***** DUMP GVARS ****");
#endif

      dump_gvars ();

      if (only_doing_globals ())
	exit (0);
    }


  if (scope == 'm')
    {
      print_module_variables ();
    }

}



/******************************************************************************/
void
print_local_variables (void)
{
  int a;

  for (a = 0; a < list_local_cnt; a++)
    {
      print_variable (list_local[a], 'L', 0);
    }

}



/******************************************************************************/
void
print_module_variables (void)
{
  int a;

  for (a = 0; a < list_module_cnt; a++)
    {
      print_variable (list_module[a], 'M', 0);
    }

}



/******************************************************************************/
void
print_global_variables (void)
{
  int a;
  for (a = 0; a < list_imported_global_cnt; a++)
    {
      print_variable (list_imported_global[a], 'G', 0);

    }

  for (a = 0; a < list_global_cnt; a++)
    {
      print_variable (list_global[a], 'g', 0);
    }
}



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

  debug ("Looking for type '%s'", s);


  if (find_datatype_out (s) != -1)
    {
      debug ("Found it...");
      return find_datatype_out (s);
    }

  debug ("Not found - keep looking");
  debug ("find_type %s\n", s);


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

  debug ("Invalid type : '%s'\n", s);
  sprintf (errbuff, "Internal Error (Invalid type : '%s')\n", s);
  yyerror (errbuff);
  return 0;
}



/******************************************************************************/
static long
isvartype (char *s, int mode)
{
  struct variable *v;
  v = find_variable_ptr (s);

  if (mode == 1)
    {				// Isarray
      return v->is_array;
    }



  if (mode == 2)
    {				// Isrecord

      if (v->variable_type == VARIABLE_TYPE_ASSOC)
	{
	  v = v->data.v_assoc.variables[0];
	}


      if (v->variable_type == VARIABLE_TYPE_RECORD)
	return 1;
      return 0;

    }

  debug ("Bad mode in isvartype");
  assert (0);
}

/******************************************************************************/
long
isarrvariable (char *s)
{
  long a;
  a = isvartype (s, 1);
  debug ("Checking if %s is an array %d", s, a);
  return a;
}

/******************************************************************************/
long
isrecvariable (char *s)
{
  return isvartype (s, 2);
}


static void
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
	  sprintf (buff, "%d", v->arr_subscripts[a]);
	  strcat (s, buff);
	}
      else
	{
	  break;
	}
    }
}

/******************************************************************************/
long
get_variable_dets (char *s, int *type, int *arrsize,
		   int *size, int *level, char *arr)
{
  char buff[256];
  struct variable *v;


  if (s[0] == '.' && s[1] == 0)
    return -1;
  if (s[0] == 0)
    return -1;
  strcpy (buff, s);
  strip_bracket (buff);
  v = find_variable_ptr (buff);


  if (v == 0)
    return -1;


  *type =
    v->data.v_simple.datatype + ((v->data.v_simple.dimensions[0]) << 16);
  *level = 1;

  if (v->is_array)
    {
      *arrsize = v->arr_subscripts[0];
    }
  else
    {
      *arrsize = 0;
    }

  *size = v->data.v_simple.dimensions[0];

  if (arr)
    {
      make_arr_str (arr, v);
    }

  if (v->variable_type != VARIABLE_TYPE_SIMPLE)
    {
      debug ("Expecting a simple variable ?");
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


  if (dbg)
    {
      if (in_define)
	{
	  printf ("In define..");
	}
    }


  if (in_define)
    return 0;


  v = find_variable_ptr (name);

  if (dbg)
    {
      printf ("v=%p\n", v);
    }

  if (v == 0)
    return 0;

  if (v->variable_type != VARIABLE_TYPE_CONSTANT)
    return 0;

  if (v->data.v_const.consttype == CONST_TYPE_CHAR)
    {
      strcpy (buff, v->data.v_const.data.data_c);
      return 1;
    }

  if (v->data.v_const.consttype == CONST_TYPE_FLOAT)
    {
      sprintf (buff, "%f", v->data.v_const.data.data_f);
      return 2;
    }

  if (v->data.v_const.consttype == CONST_TYPE_INTEGER)
    {
      sprintf (buff, "%d", v->data.v_const.data.data_i);
      return 3;
    }


// Shouldn't get to here...

  return 0;
}



/******************************************************************************/
static void
strip_bracket (char *s)
{
  char buff[256];
  int a;
  int c = 0;
  int f = 0;

  debug ("strip_bracket\n");
  for (a = 0; a <= strlen (s); a++)
    {
      if (s[a] == '[')
	f++;
      if (f == 0)
	buff[c++] = s[a];
      if (s[a] == ']')
	f--;
    }
  strcpy (s, buff);
}



/******************************************************************************/
int
split_record (char *s, struct variable **v_record, struct variable **v1,
	      struct variable **v2)
{
  char buff[256];
  char endoflist[256];
  char save[256];
  char *ptr;

  // MJA - NEWVARIABLE
debug("SPLIT_RECORD : %s\n",s);

  if (strchr (s, '\n'))
    {
      char *ptr1;
      char *ptr2;

      char r1[256];
      char r2[256];
      //char buff[256];

	debug("Got a thru...");

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

      if (strcasecmp (r1, r2) != 0)
	{
	  yyerror ("Records for thru look different...");
	  return 0;
	}


	debug("Record : %s\n",r1);
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
	  printf ("Whoops - %s record not found\n", buff);
	  yyerror ("Record not found...");
	  return 0;
	}

      if (strchr (s, '.') == 0)
	{
	  strcat (buff, ".*");
	}
      *v1 = (*v_record)->data.v_record.variables[0];
      *v2 =
	(*v_record)->data.v_record.variables[(*v_record)->data.v_record.
					     record_cnt - 1];
    }

  if ((*v_record)->variable_type != VARIABLE_TYPE_RECORD)
    {
      printf ("Couldn't identify start as a record\n");
      return 0;
    }

  if ((*v1)->variable_type != VARIABLE_TYPE_SIMPLE)
    {
      printf ("Variable is not simple\n");
      return 0;
    }

  if ((*v2)->variable_type != VARIABLE_TYPE_SIMPLE)
    {
      printf ("Variable is not simple\n");
      return 0;
    }

  printf ("All done here - v_record=%p v1=%p v2=%p\n", *v_record, *v1, *v2);
  printf ("v_record->names.name=%s\n", (*v_record)->names.name);
  printf ("v1->names.name=%s\n", (*v1)->names.name);
  printf ("v2->names.name=%s\n", (*v2)->names.name);
  return 1;
}







static struct record_list *
add_to_record_list (struct record_list **list_ptr, char *prefix_buff,
		    struct variable *v)
{
  char buff[257];
  struct record_list_entry *e;
  struct record_list *list;



  if (v->is_array)
    {
      yyerror ("Can't use a variable containing an array in this context\n");
      return 0;
    }

  list = *list_ptr;

  if (list == 0)
    {
      printf ("List is empty\n");
      exit (0);
    }

  if (v->variable_type == VARIABLE_TYPE_SIMPLE)
    {
      list->list = realloc (list->list,
			    (list->records_cnt +
			     1) * sizeof (struct record_list_entry *));
      e = malloc (sizeof (struct record_list_entry));
      sprintf (buff, "%s.%s", prefix_buff, v->names.name);
      e->variable = v;
      e->name = strdup (buff);

      list->list[list->records_cnt] = e;
      list->records_cnt++;

      *list_ptr = list;
      return list;
    }

  if (v->variable_type == VARIABLE_TYPE_RECORD)
    {
      // We've got another bl**dy record - expand this one too...
      printf ("IS ARRAY  : %d\n", v->is_array);
      printf ("Add next level...\n");
      sprintf (buff, "%s.%s.*", prefix_buff, v->names.name);
      return split_record_list (buff, buff, list);
      *list_ptr = list;
    }

  printf ("Reached end of add_to_Record_list... bugger...\n");
  return 0;
}


struct record_list *
split_record_list (char *s, char *prefix, struct record_list *list)
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
debug("Split_record_list... %s",s);

  if (strchr (s, '\n'))
    {
      strcpy (record1, s);
      ptr = strchr (record1, '\n');
      *ptr = 0;
      ptr++;
      strcpy (record2, ptr);
      dot[0] = strrchr (record1, '.');
      dot[1] = strrchr (record2, '.');
      if (dot[0] == 0 || dot[1] == 0)
	{
	  // Can't find a dot in a thru ?
	  yyerror
	    ("At least one of the entries in the 'thru' is not part of a record");
	  return 0;
	}
      *dot[0] = 0;
      *dot[1] = 0;
      if (strcasecmp (record1, record2) != 0)
	{
	  yyerror ("The 'thru' contains different records..");
	  return 0;
	}

	debug("record1=%s record2=%s\n",record1,record2);

	debug("prefix=%s\n",prefix);

      if (prefix != 0 && strlen(prefix))
	{
	  sprintf (prefix_buff, "%s.", prefix);
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
	
debug("subrecord1=%s subrecord2=%s\n",subrecord1,subrecord2);

      // At this point record1 and record2 should be the same...
      // We'll get rid of any crud from record2 (any brackets etc) to find it 
      // in our variables list
      // We'll keep record1 intact..

      strip_bracket (record2);
      v_record = find_variable_ptr (record2);

      // Can we find it - is it declared ?
      if (v_record == 0)
	{
	  printf ("Whoops - record not found for %s\n", record2);
	  yyerror ("Record not found");
	  return 0;
	}

      record_start = -1;
      record_end = -1;

      for (a = 0; a < v_record->data.v_record.record_cnt; a++)
	{
	      debug("Record @ %d = %s",a,v_record->data.v_record.variables[a]->names.name);
	  if (strcasecmp
	      (v_record->data.v_record.variables[a]->names.name,
	       subrecord1) == 0)
	    {
		debug("Record start @ %d\n",a);
	      record_start = a;
	    }
	  if (strcasecmp
	      (v_record->data.v_record.variables[a]->names.name,
	       subrecord2) == 0)
	    {
		debug("Record end @ %d\n",a);
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
	  printf ("Whoops - record not found for %s\n", record1);
	  yyerror ("Record not found");
	  return 0;
	}

      record_start = 0;
      record_end = v_record->data.v_record.record_cnt - 1;
    }



  if (v_record->variable_type != VARIABLE_TYPE_RECORD)
    {

      if (strstr(s,".*")!=0 && strlen(prefix)==0) {
		extern int yyline;
		char buff[255];
		char buff2[255];
		char *ptr;
		struct record_list_entry *e;
		printf("WARNING : Using a .* on a non-record - %s\n",s);
		strcpy(buff,s);
		strip_bracket(buff);
		ptr=strstr(buff,".*");
		*ptr=0;
      		v_record = find_variable_ptr (buff);
		strcpy(buff,s);
		ptr=strstr(buff,".*");
		*ptr=0;
      		list = malloc (sizeof (struct record_list));
      		list->list = 0;
      		list->records_cnt = 0;
      		list->list = malloc (sizeof (struct record_list_entry *)); 
		e = malloc (sizeof (struct record_list_entry));
      		sprintf (buff2, "%s", buff);
      		e->variable = v;
      		e->name = strdup (buff2);
      		list->list[list->records_cnt] = e;
      		list->records_cnt++;

	return list;
      }
	printf("S=%s\n",s);
      yyerror ("ERROR: Variable is not a record!\n");
      return 0;
    }

  if (record_start == -1)
    {
      yyerror ("Couldn't find start variable");
      return 0;
    }

  if (record_end == -1)
    {
      yyerror ("Couldn't find end variable");
      return 0;
    }
  if (record_start>record_end) {
	yyerror("Starting point in THRU is after the end point");
	return 0;
  }

  if (list == 0)
    {
      list = malloc (sizeof (struct record_list));
      list->list = 0;
      list->records_cnt = 0;
    }


  // Now - we'll start scanning through our record entries - looking for the first one...


  for (a = record_start; a <= record_end; a++)
    {
      if (add_to_record_list
	  (&list, prefix_buff, v_record->data.v_record.variables[a]) == 0)
	{
	  printf ("Bugger -  something went wrong...\n");
	  // Should free list here...
	  return 0;
	}
    }
  return list;
}




/******************************************************************************/
int
push_bind_rec (char *s, char bindtype)
{
  int a;
//int dtype;
//int size;
//char buff[256];
  struct record_list *list;
debug("In push_bind_rec : '%s'",s);

  list = split_record_list (s, "", 0);
debug("Got list : %p",list);

  if (list == 0)
    {
      yyerror ("OOps\n");
      return -1;
    }


  for (a = 0; a < list->records_cnt; a++)
    {
      add_bind (bindtype, list->list[a]->name);
    }

  return 1;
}



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

  for (a = 0; a < record->data.v_record.record_cnt; a++)
    {
      if (record->data.v_record.variables[a] == v1)
	{
	  a++;
	  v_return = record->data.v_record.variables[a];
	  return v_return;
	}
    }
  yyerror ("Can't find variable in record...");
  return 0;
}


int
print_push_rec (char *s, void **b)
{
  int a;
  int dtype;
  int size;
  char buff[256];
  struct record_list *list;


  list = split_record_list (s, "", 0);


  if (list == 0)
    {
      yyerror ("OOps\n");
      return 0;
    }

//printf("list->records_cnt=%d\n",list->records_cnt);

  for (a = 0; a < list->records_cnt; a++)
    {
      //printf("a=%d\n",a);
      dtype = list->list[a]->variable->data.v_simple.datatype;
      size = list->list[a]->variable->data.v_simple.dimensions[0];
      dtype += size << 16;

      sprintf (buff, "push_variable(&%s,0x%x);", list->list[a]->name, dtype);
      //printf("**** %s\n",buff);
      append_expr (*b, buff);
      //printf("a=%d list->records_cnt=%d\n",a,list->records_cnt);
    }
  return list->records_cnt;

}


#ifdef USE_CRAP
/******************************************************************************/
int
recursive_print_push_rec (char *s, void **b, char *stem_orig)
{
  struct variable *v_record;
  struct variable *v_start;
  struct variable *v_end;
  struct variable *v_loop;
  char buff[20000];
  char stem[256];
  int dtype;
  int size;
  int is_array;
  int vtype;
  int c = 0;


  if (strchr (s, '\n') == 0)
    {				// Ie - its not a range....
      vtype = find_variable (s, &dtype, &size, &is_array, 0);
    }
  else
    {
      vtype = -2;
    }


  // Variable not found...
  if (vtype == 0)
    {
      printf ("Variable not found - should have been picked up already - %s",
	      s);
      exit (0);
    }

  // Normal variable
  if (vtype == 1)
    {
      dtype += size << 16;
      sprintf (buff, "push_variable(&%s,0x%x);\n", s, dtype);
      append_expr (*b, buff);
      return 1;
    }

  if (vtype == -2)
    {
      printf ("Splitting...'%s'\n", s);

      if (split_record (s, &v_record, &v_start, &v_end))
	{
	  char *ptr;

	  if (v_record == 0)
	    {
	      printf ("Couldn't find record! (%s)\n", s);
	      exit (0);
	    }

	  printf ("START LOOPING\n");
	  v_loop = v_start;

	  ptr = strchr (s, '\n');
	  if (ptr)
	    {
	      *ptr = 0;
	      ptr = strchr (ptr, '.');
	      if (ptr)
		{
		  *ptr = 0;
		}
	    }

	  printf ("s=%s\n", s);

	  while (v_loop)
	    {
	      char bbz[256];
	      //if (strchr(s,'*')) { // Get rid of the .*
	      //strcpy(bbz,s); bbz[strlen(bbz)-2]=0; 
	      //}  else {
	      strcpy (bbz, s);
	      //strcat(bbz,".");
	      //}

	      //strcat(bbz,v_loop->names.name); // Get the propper name

	      printf ("Looking again for '%s'\n", bbz);
	      c += recursive_print_push_rec (bbz, b, stem);
	      v_loop = get_next_variable (v_record, v_loop, v_end);
	    }
	  printf ("END LOOPING\n");
	  return c;

	}
      else
	{
	  // Couldn't split the record - shouldn't happen...
	  printf ("Couldn't split record : %s\n", s);
	}
    }

  exit (0);
}
#endif


/******************************************************************************/
void
clr_function_constants ()
{
  // Here - we need to clear down the current 'locals' lists...
  // as a quick fix - we'll just zero everything
  // but these *really* should be 'freed' properly.....
  list_local_cnt = 0;
  list_local_alloc = 0;
  list_local = 0;
}


/******************************************************************************/
static void
print_variable (struct variable *v, char scope, int level)
{
  int static_extern_flg;
  char arrbuff[256];
  static_extern_flg = 0;
  strcpy (arrbuff, "-1");
  // are we dealing with the sqlca variable ?
  if (level == 0 && strcmp (v->names.name, "sqlca") == 0)
    {
#ifdef DEBUG
      debug ("SQLCA!!!\n");
#endif
      if (strcmp (acl_getenv ("LEXTYPE"), "EC") == 0)
	{
	  return;
	}
    }

  if (scope == 'G' && strcasecmp (v->names.name, "time") == 0 && level == 0)
    {
#ifdef DEBUG
      debug ("Ignore time....\n");
#endif
      return;
    }


  if (v->is_array)
    {
      make_arr_str (arrbuff, v);
    }
  else
    {
      strcpy (arrbuff, "-1");
    }




  if (level == 0)		// We only print 'static' or 'extern' at the start of a record/variable - not a nested record
    {
      if (scope == 'G')
	{
	  static_extern_flg += 2;
	}

      if (v->is_static == 1)
	{
	  static_extern_flg += 1;
	}
    }



  if (v->variable_type == VARIABLE_TYPE_SIMPLE)
    {
      char tmpbuff[256];
      sprintf (tmpbuff, "%s %s", rettype_integer (v->data.v_simple.datatype),
	       v->names.name);

      if (v->is_array)
	{
	  strcat (tmpbuff, "[");
	  strcat (tmpbuff, arrbuff);
	  strcat (tmpbuff, "]");
	}

      if (v->data.v_simple.datatype == 0)
	{			// Its a 'char' (may need varchar & friends too...
	  print_define_char (tmpbuff, v->data.v_simple.dimensions[0],
			     static_extern_flg);
	}
      else
	{
	  print_define (tmpbuff, static_extern_flg);
	}

      return;
    }

  if (v->variable_type == VARIABLE_TYPE_RECORD)
    {
      int a;
      print_start_record (static_extern_flg, v->names.name);
      for (a = 0; a < v->data.v_record.record_cnt; a++)
	{
	  struct variable *next_v;
	  next_v = v->data.v_record.variables[a];
	  print_variable (next_v, scope, level + 1);
	}
      print_end_record (v->names.name, arrbuff);
      return;
    }

  if (v->variable_type == VARIABLE_TYPE_ASSOC)
    {
      struct variable v2;
      char buff1[20];
      char buff2[20];

      sprintf (buff1, "%d", v->data.v_assoc.char_size);
      sprintf (buff2, "%d", v->data.v_assoc.size);

      //print_declare_associate_2 (v->names.name,buff1,buff2);

      memcpy (&v2, v->data.v_assoc.variables[0], sizeof (struct variable));

      v2.names.next = 0;
      v2.names.name = v->names.name;

      print_variable (&v2, scope, level + 1);
      return;
    }

  if (v->variable_type == VARIABLE_TYPE_CONSTANT)
    {
      // Maybe we should print out #define's for these ?
      // Maybe not - they should already have been converted by lexer.c
    }


}




/**
 * Gets the C data type corresponding to 4gl data type
 *
 * @param s A string with the numeric 4gl data type (@see find_type())
 * @return The string (static) with the C declaration
 */
static char *
rettype_integer (int n)
{
  char s[200];

  //static char rs[20] = "long";
  //int a;

  debug ("rettype_integer : %d\n", n);

  sprintf (s, "%d", n);
  return rettype (s);
}



static char *
make_pk_list (struct name_list *nlist)
{
  static char buff[1024];
  strcpy (buff, nlist->name);
  nlist = nlist->next;
  while (nlist)
    {
      strcat (buff, ",");
      strcat (buff, nlist->name);
      nlist = nlist->next;
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
  // MJA - NEWVARIABLE
  strcpy (pklist, "");
  strcpy (tabname, "");

  if (last_variable_ptr_found
      && last_variable_ptr_found->variable_type == VARIABLE_TYPE_RECORD
      && last_variable_ptr_found->data.v_record.linked)
    {


      strcpy (tabname,
	      last_variable_ptr_found->data.v_record.linked->tabname);
      strcpy (pklist,
	      make_pk_list (&last_variable_ptr_found->data.v_record.linked->
			    col_list));
    }


  if (strcasecmp (tabname, "") == 0)
    return 0;
  else
    return 1;
}
