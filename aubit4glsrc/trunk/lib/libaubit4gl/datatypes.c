/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-1 Aubit Development Team (See Credits file)       |
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
# $Id: datatypes.c,v 1.15 2003-05-12 14:24:03 mikeaubury Exp $
#
*/

/**
 * @file
 * Data type definition functions
 *
 * This is complex stuff
 * What we want to be able to do is add datatypes programatically
 * We therefor maintain a list of available datatypes
 * and their various conversion routines..
 *
 * This is very much a work in progress....
 *
 * This file should be renamed to API_exdata.c
 *
 */

/*
=====================================================================
	   Includes
=====================================================================
*/

#include "a4gl_libaubit4gl_int.h"

/*
=====================================================================
	   Variables definitions
=====================================================================
*/

int inited = 0;

struct dtype_functions
{
  char *name;
  void *function;
};


struct s_datatype
{
  char *name;
  int precision;
  struct dtype_functions **funcs;
  int funcs_len;
};


	/*
	   Functions allowed :
	   alloc           //
	   free            //
	   output_LANG     // normal language representation (eg LANG=C)
	   output_SQL      // SQL representation (eg LANG=ODBC)
	   nset            // Set to null
	   zset            // Set to zero
	   isnull          // returns 1 if value is null, 0 if not
	   conv_to_sql     // Convert to something SQL uses for this datatype
	   conv_from_sql   // Convert from something SQL uses for this datatype
	   >STRING         // Convert to a string
	   <STRING         // Convert from a string
	   compare         // Compare two values
	 */



struct s_datatype dtypes[MAX_DTYPE];

static void *libptr = 0;

/*
=====================================================================
	   Functions prototypes
=====================================================================
*/

int add_datatype_function_i (int a, char *funcname, void *func);
extern void add_default_operations (void);	/* in ops.c */
void add_default_datatypes (void);
static int (*func) (void);
int call_datatype_function_i (void *obj, int dtype, char *funcname,
			      int nparam);


/*
=====================================================================
				   Functions definitions
=====================================================================
*/


/**
 *
 * Load a specified datatype into the system
 */
int
A4GLEXDATA_initlib (char *f)
{

  libptr = (void *) dl_openlibrary ("EXDTYPE", f);
  if (libptr == 0)
    {
      exitwith ("Unable to open EXDTYPE library.");
      return 0;
    }

  func = find_func_allow_missing (libptr, "EXDTYPE_initlib");
  if (func)
    return func ();
  else
    return 1;
}



/**
 * Initialize all the datatypes
 *
 * @todo Describe function
 */
void
init_datatypes (void)
{
  int a;
  if (inited == 0)
    {
      inited = 1;
      for (a = 0; a < MAX_DTYPE; a++)
	{
	  dtypes[a].name = 0;
	  dtypes[a].precision = 0;
	  dtypes[a].funcs = 0;
	  dtypes[a].funcs_len = 0;
	}
      add_default_datatypes ();
    }
  debug ("Finished initializing data types");
}



/**
 * Returns function pointer on success
 * return 0 on failure
 *
 * This function gets finds a datatype function for a given datatype ID
 */
void *
get_datatype_function_i (int a, char *funcname)
{
  int n;
  a = a & DTYPE_MASK;
  if (!inited)
    init_datatypes ();

  for (n = 0; n < dtypes[a].funcs_len; n++)
    {
      if (strcmp (dtypes[a].funcs[n]->name, funcname) == 0)
	return dtypes[a].funcs[n]->function;
    }
  return 0;
}



/**
 * Returns 1 on success
 * return 0 on failure
 *
 * This function checks to see if a function is available for
 * a specified datatype ID
 *
 */
int
has_datatype_function_i (int a, char *funcname)
{
  int n;
  if (!inited)
    init_datatypes ();
  a = a & DTYPE_MASK;
  //debug ("Looking for function %s for datatype %d (%d elements)", funcname, a,
//       dtypes[a].funcs_len);
  for (n = 0; n < dtypes[a].funcs_len; n++)
    {
      //debug ("   %s", dtypes[a].funcs[n]->name);

      //printf("%s %s",dtypes[a].funcs[n]->name, funcname) ;

      if (strcmp (dtypes[a].funcs[n]->name, funcname) == 0)
	{
	  //debug ("Found it");
	  return 1;
	}
    }
  //debug ("Not found");
  return 0;
}

/**
 *
 * add_datatype
 * Name      = name of datatype
 * rq        = requested datatype ID number
 * precision = precisness of the datatype
 *             this will determine which datatype would be used for numeric comparisons
 *      (eg float > smallfloat > int > smallint
 *             Therefore - if you are comparing a smallint to a float - you'd convert both to 'float'
 * returns the datatype  ID if successfull or -1
 *
 * This function allows the dynamic creation of a new datatype
 */
int
add_datatype (char *name, int rq, int precision)
{
  int a;

  if (!inited)
    init_datatypes ();
  if (rq >= 0)
    {
      if (dtypes[rq].name == 0)
	{
	  a = rq;
	  dtypes[a].name = name;
	  dtypes[a].precision = precision;
	  return a;
	}
    }


  for (a = 0; a < MAX_DTYPE; a++)
    {
      if (dtypes[a].name == 0)
	{
	  dtypes[a].name = name;
	  dtypes[a].precision = precision;
	  return a;
	}
    }
  return -1;

}

/**
 *
 * @todo Describe function
 */
int
find_datatype_out (char *name)
{
  int a;
  if (!inited)
    init_datatypes ();

  for (a = 0; a < MAX_DTYPE; a++)
    {

      if (dtypes[a].name == 0)
	continue;

      if (has_datatype_function_i (a, "OUTPUT"))
	{
	  char *(*function) (void);
	  function = get_datatype_function_i (a, "OUTPUT");
	  debug ("Got function as %p - comparing %s and %s", function,
		 function (), name);
	  if (strcasecmp (function (), name) == 0)
	    return a;
	}
    }
  return -1;

}


/**
 *
 * @todo Describe function
 */
int
find_datatype (char *name)
{
  int a;

  if (!inited)
    init_datatypes ();

  for (a = 0; a < MAX_DTYPE; a++)
    {

      if (dtypes[a].name == 0)
	continue;

      if (strcasecmp (dtypes[a].name, name) == 0)
	{
	  return a;
	}
    }
  return -1;

}

/**
 * Returns 1 on success
 * return 0 on failure
 *
 * @todo Describe function
 */
int
add_datatype_function_i (int a, char *funcname, void *func)
{
  if (!inited)
    init_datatypes ();
  debug ("Adding function %s to datatype %d (%p)", funcname, a, func);

  dtypes[a].funcs = realloc (dtypes[a].funcs,
			     (dtypes[a].funcs_len +
			      1) * sizeof (struct dtype_functions *));

  dtypes[a].funcs[dtypes[a].funcs_len] =
    malloc (sizeof (struct dtype_functions));
  dtypes[a].funcs[dtypes[a].funcs_len]->name = funcname;
  dtypes[a].funcs[dtypes[a].funcs_len]->function = func;

  dtypes[a].funcs_len++;


  return 1;
}

/**
 *
 * @todo Describe function
 */
int
call_datatype_function_i (void *obj, int dtype, char *funcname, int nparam)
{
  int (*ptr) (void *, int);
  char buff[256];
  int nret;

  debug ("in call_datatype_function obj=%p dtype=%d funcname=%s nparam=%d",
	 obj, dtype, funcname, nparam);
  sprintf (buff, ":%s", funcname);

  if (!inited)
    init_datatypes ();


  ptr = get_datatype_function_i (dtype, buff);

  if (ptr == 0)
    {
      exitwith ("Unable to find function");
      return 0;
    }

  nret = ptr (obj, nparam);

  return nret;

}

/**
 * Returns 1 on success
 * return 0 on failure
 *
 * @todo Describe function
 */
int
add_datatype_function_n (char *name, char *funcname, void *func)
{
  int a;
  if (!inited)
    init_datatypes ();
  debug ("Add_datatype_function_n : %s %s %p", name, funcname, func);
  a = find_datatype (name);
  if (a == -1)
    return 0;
  return add_datatype_function_i (a, funcname, func);
}




/**
 * Returns 1 on success
 * return 0 on failure
 *
 *
 * @todo Describe function
 */
int
has_datatype_function_n (char *name, char *funcname)
{
  int a;
  if (!inited)
    init_datatypes ();
  a = find_datatype (name);
  if (a == -1)
    return 0;
  return has_datatype_function_i (a, funcname);
}


/**
 * Returns 1 on success
 * return 0 on failure
 *
 *
 * @todo Describe function
 */
void *
get_datatype_function_n (char *name, char *funcname)
{
  int a;
  if (!inited)
    init_datatypes ();
  a = find_datatype (name);
  if (a == -1)
    return 0;
  return get_datatype_function_i (a, funcname);
}

/**
 *
 * @todo Describe function
 */
void
add_conversion (char *from, char *to, void *func)
{
  int a;
  int b;
  if (!inited)
    init_datatypes ();
  debug ("In Adding conversions... with %p", func);
  a = find_datatype (from);
  b = find_datatype (to);

  if (a == -1 || b == -1)
    {
      debug ("Unable to resolve either from or to");
      return;
    }
  debug ("Adding conversion from %s(%d) to %s(%d) with %p", from, a, to, b,
	 func);
  set_convmatrix (a, b, func);

}


/**
 *
 * @todo Describe function
 */
void
add_default_datatypes (void)
{
  add_datatype ("CHAR", 0, 0);
  add_datatype ("SMALLINT", 1, 1);
  add_datatype ("INTEGER", 2, 2);
  add_datatype ("FLOAT", 3, 4);
  add_datatype ("SMALLFLOAT", 4, 3);
  add_datatype ("DECIMAL", 5, 5);
  add_datatype ("SERIAL", 6, 2);
  add_datatype ("DATE", 7, 0);
  add_datatype ("MONEY", 8, 5);
  add_datatype ("NULL", 9, 0);
  add_datatype ("DATETIME", 10, 0);
  add_datatype ("BYTES", 11, 0);
  add_datatype ("TEXT", 12, 0);
  add_datatype ("VARCHAR", 13, 0);
  add_datatype ("INTERVAL", 14, 0);
  add_datatype ("NCHAR", 15, 0);
  add_default_operations ();

  debug ("Finished adding default data types");
}


/**
 *
 * @todo Describe function
 */
int
aclfgl_load_datatype (int nargs)
{
  char *s;

  s = char_pop ();
  trim (s);

  A4GLEXDATA_initlib (s);

  free (s);
  /* End of code */
  return 0;
}

/* =============================== EOF ================================ */
