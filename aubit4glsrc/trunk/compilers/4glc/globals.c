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
# $Id: globals.c,v 1.14 2003-05-12 14:23:45 mikeaubury Exp $
#
*/

/**
 * @file
 * Processing of 4GL GLOBALS declarations and files
 *
 *
 * @todo Doxygen comments in all functions
 * @todo static in modular variables
 * @todo const in read only strings
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
                    Variables definitions
=====================================================================
*/


/* These are all located in variables.c */

extern struct variable **list_global;	// Our List
extern int list_global_cnt;	// Number used in our list
extern int list_global_alloc;	// Space allocated for our list
extern struct variable **list_imported_global;	// Our List
extern int list_imported_global_cnt;	// Number used in our list
extern int list_imported_global_alloc;	// Space allocated for our list

/* This is from 4glc.c */

extern char *outputfilename;
extern char currinfile_dirname[1024];	//path to 4gl file we are currently compiling

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


/* Externally callable (non-static) functions */



/* static functions declared here */
static void write_variable_header (FILE * f, struct variable *v);
static void write_variable_simple (FILE * f, struct variable *v);
static void write_variable_linked (FILE * f, struct variable *v);
static void write_variable_record (FILE * f, struct variable *v);
static void write_variable_assoc (FILE * f, struct variable *v);
static void write_variable_constant (FILE * f, struct variable *v);
static void read_global_int (FILE * f, char *name, int *val);
static void read_global_string (FILE * f, char *name, char **val, int alloc);
static void read_global_char (FILE * f, char *name, char *val);
static void read_global_float (FILE * f, char *name, double *val);
static void read_variable_header (FILE * f, struct variable *v);
static void read_variable_simple (FILE * f, struct variable *v);
static void read_variable_linked (FILE * f, struct variable *v);
static void read_variable_record (FILE * f, struct variable *v);
static void read_variable_assoc (FILE * f, struct variable *v);
static void read_variable_constant (FILE * f, struct variable *v);
static void generate_globals_for (char *s);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 *
 *
 * @param
 */
static void
write_global_int (FILE * f, char *name, int val)
{
  fprintf (f, "%s=%d\n", name, val);
}

/**
 *
 *
 * @param
 */
static void
write_global_string (FILE * f, char *name, char *val)
{
  fprintf (f, "%s=%s\n", name, val);
}

/**
 *
 *
 * @param
 */
static void
write_global_char (FILE * f, char *name, char val)
{
  fprintf (f, "%s=%c\n", name, val);
}

/**
 *
 *
 * @param
 */
static void
write_global_float (FILE * f, char *name, double val)
{
  fprintf (f, "%s=%f\n", name, val);
}



/**
 *
 *
 * @param
 */
void
dump_gvars (void)
{
  FILE *f;
  int a;
  char ii[64];
  struct variable *v;

  strcpy (ii, outputfilename);
  strcat (ii, ".glb");
  f = mja_fopen (ii, "w");

  if (f == 0)
    {
      fprintf (stderr, "Critical error - couldnt open output file %s\n", ii);
      exit (0);
    }

  write_global_string (f, "DATABASE", get_hdrdbname ());
  write_global_int (f, "NUMVARS", list_global_cnt);

  for (a = 0; a < list_global_cnt; a++)
    {
      v = list_global[a];
      /* Output the standard header stuff */
      debug ("Output Global Entry %d - %p\n", a, v);
      write_variable_header (f, v);
    }


  fclose (f);
}





/**
 *
 *
 * @param
 */
static void
write_variable_header (FILE * f, struct variable *v)
{
  struct name_list *ptr;
  int a;
  int cnt;

  write_global_string (f, "NAME", v->names.name);
  ptr = v->names.next;

  write_global_int (f, "TYPE", v->variable_type);
  write_global_char (f, "USER_SYSTEM", v->user_system);
  write_global_int (f, "IS_ARRAY", v->is_array);
  write_global_string (f, "SRC_MODULE", v->src_module);


  if (v->is_array)
    {
      cnt = 0;
      for (a = 0; a < MAX_ARR_SUB; a++)
	{
	  if (v->arr_subscripts[a])
	    cnt++;
	}
      write_global_int (f, "ARR_SUBSCRIPTS_CNT", cnt);

      for (a = 0; a < cnt; a++)
	{
	  if (v->arr_subscripts[a])
	    write_global_int (f, "ARR_SUBSCRIPT", v->arr_subscripts[a]);
	}
    }

  if (v->variable_type == VARIABLE_TYPE_SIMPLE)
    {
      write_variable_simple (f, v);
    }

  if (v->variable_type == VARIABLE_TYPE_RECORD)
    {
      write_variable_record (f, v);
    }

  if (v->variable_type == VARIABLE_TYPE_ASSOC)
    {
      write_variable_assoc (f, v);
    }

  if (v->variable_type == VARIABLE_TYPE_CONSTANT)
    {
      write_variable_constant (f, v);
    }

}


/**
 *
 *
 * @param
 */
static void
write_variable_simple (FILE * f, struct variable *v)
{
  write_global_int (f, "DATATYPE", v->data.v_simple.datatype);
  write_global_int (f, "DIMENSIONS_1", v->data.v_simple.dimensions[0]);
  write_global_int (f, "DIMENSIONS_2", v->data.v_simple.dimensions[1]);
}



/**
 *
 *
 * @param
 */
static void
write_variable_linked (FILE * f, struct variable *v)
{
  struct name_list *ptr;
  int cnt;

  write_global_string (f, "LINKTABLE", v->data.v_record.linked->tabname);



  cnt = 1;
  ptr = v->data.v_record.linked->col_list.next;
  while (ptr)
    {
      cnt++;
      ptr = ptr->next;
    }



  write_global_int (f, "LINKCOLUMNS", cnt);

  write_global_string (f, "LINKCOLUMN",
		       v->data.v_record.linked->col_list.name);

  ptr = v->data.v_record.linked->col_list.next;
  while (ptr)
    {
      write_global_string (f, "LINKCOLUMN", ptr->name);
      ptr = ptr->next;
    }

}



/**
 *
 *
 * @param
 */
static void
write_variable_record (FILE * f, struct variable *v)
{
  int a;
  write_global_int (f, "COUNT", v->data.v_record.record_cnt);

  if (v->data.v_record.linked == 0)
    {
      write_global_int (f, "LINKED", 0);
    }
  else
    {
      write_global_int (f, "LINKED", 1);
      write_variable_linked (f, v);
    }

  for (a = 0; a < v->data.v_record.record_cnt; a++)
    {
      write_variable_header (f, v->data.v_record.variables[a]);
    }

}




/**
 *
 *
 * @param
 */
static void
write_variable_assoc (FILE * f, struct variable *v)
{
  struct variable *ptr;
  write_global_int (f, "SIZE", v->data.v_assoc.size);
  write_global_int (f, "CHARSIZE", v->data.v_assoc.char_size);
  ptr = v->data.v_assoc.variables[0];
  write_variable_header (f, ptr);

}


/**
 *
 *
 * @param
 */
static void
write_variable_constant (FILE * f, struct variable *v)
{

  write_global_int (f, "CONSTANT_TYPE", v->data.v_const.consttype);

  if (v->data.v_const.consttype == CONST_TYPE_INTEGER)
    {
      write_global_int (f, "CONSTANT_VALUE", v->data.v_const.data.data_i);
    }


  if (v->data.v_const.consttype == CONST_TYPE_CHAR
      || v->data.v_const.consttype == CONST_TYPE_IDENT)
    {
      write_global_string (f, "CONSTANT_VALUE", v->data.v_const.data.data_c);
    }

  if (v->data.v_const.consttype == CONST_TYPE_FLOAT)
    {
      write_global_float (f, "CONSTANT_VALUE", v->data.v_const.data.data_f);
    }

}

/**
 * Compile the 4gl source with -G option to generate the .glb file
 *
 * This file is then readed to generate the externs in C.
 *
 * @param s The 4gl file name (without extension).
 */
static void
generate_globals_for (char *s)
{
  char buff[1024];
  char dirname[1024];
  char fname[1024];
  char *ptr;
  char nocfile[256];

#ifdef DEBUG
  debug ("In generate_globals_for\n");
#endif

  strcpy (buff, s);


  //NOTE: we will get path in s only if it was specified in GLOBALS declaration
  if (strchr (buff, '/'))
    {
      strcpy (dirname, buff);
      ptr = strrchr (dirname, '/');
      *ptr = 0;
      ptr++;
      strcpy (fname, ptr);
    }
  else
    {
      if (currinfile_dirname)
	{
	  //use path that was passed to 4glc with 4gl file name of main 4gl
	  //source file we are compiling, if any
	  strcpy (dirname, currinfile_dirname);

	}
      else
	{
	  strcpy (dirname, ".");
	}
      strcpy (fname, buff);
    }

  strcpy (nocfile, acl_getenv ("NOCFILE"));
  setenv ("NOCFILE", "Yes", 1);
  ptr = strchr (fname, '.');
  *ptr = 0;
#ifdef DEBUG
  debug ("Trying to compile globals file %s in %s\n", fname, dirname);

  if (strcmp (acl_getenv ("DEBUG"), "ALL") == 0)
    {
      sprintf (buff, "mv debug.out debug1.out");
      debug ("Preserving debug.out: %s\n", buff);
      system (buff);
    }
#endif
  //why cd? just pass the path in file name... */
  //sprintf (buff, "cd %s; 4glc --globals %s.4gl", dirname, fname);
  sprintf (buff, "4glc --globals %s/%s.4gl", dirname, fname);
#ifdef DEBUG
  debug ("Executing system call: %s\n", buff);
#endif
  system (buff);
  setenv ("NOCFILE", nocfile, 1);
#ifdef DEBUG
  if (strcmp (acl_getenv ("DEBUG"), "ALL") == 0)
    {
      sprintf (buff, "mv debug.out debug-globals.out");
      debug ("Preserving debug.out: %s\n", buff);
      system (buff);
      sprintf (buff, "mv debug1.out debug.out");
      debug ("Restoring debug.out: %s\n", buff);
      system (buff);
    }
#endif

}


/**
 *
 *
 * @param
 */
void
read_glob (char *s)
{
  FILE *f;
  char ii[64];
  char iii[256];
  char *dbname;
  int gvars;
  int start = 0;
  int a;

  // MJA - NEWVARIABLE
  strcpy (ii, s);
  strcat (ii, ".glb");
#ifdef DEBUG
  debug ("Trying to open globals file %s\n", ii);
#endif

  f = mja_fopen (ii, "r");

  if (f == 0)
    {
#ifdef DEBUG
      debug ("Trying to compile globals file %s", ii);
#endif
      generate_globals_for (ii);
      f = mja_fopen (ii, "r");
    }

  if (f == 0)
    {
      /* try with same path supplied with call to 4glc for 4gl file we are actually compiling globals file for */

#ifdef DEBUG
      debug ("Couldnt open globals file %s\n", ii);
#endif
      // add path
      strcpy (iii, currinfile_dirname);
      strcat (iii, "/");
      strcat (iii, ii);
#ifdef DEBUG
      debug ("Trying globals file %s", iii);
#endif
      generate_globals_for (iii);
      f = mja_fopen (iii, "r");
      if (f == 0)
	{
	  fprintf (stderr, "Couldnt open globals file %s, in . and %s\n", ii,
		   currinfile_dirname);
	  exit (7);
	}
    }

  read_global_string (f, "DATABASE", &dbname, 1);

  if (strlen (dbname) > 0)
    {
      set_hdrdbname (dbname);
      open_db (dbname);
    }

  read_global_int (f, "NUMVARS", &gvars);
  start = list_imported_global_cnt;
  list_imported_global_cnt += gvars;

  if (list_imported_global_cnt > list_imported_global_alloc)
    {
      list_imported_global_alloc = list_imported_global_cnt;
    }

  list_imported_global =
    realloc (list_imported_global,
	     sizeof (struct variable *) * list_imported_global_alloc);

  for (a = start; a < list_imported_global_cnt; a++)
    {
      list_imported_global[a] = malloc (sizeof (struct variable));
      read_variable_header (f, list_imported_global[a]);
    }
  fclose (f);
}


/**
 *
 *
 * @param
 */
static void
read_global_int (FILE * f, char *name, int *val)
{
  char buff[256];
  char buff2[256];

  sprintf (buff, "%s=%%d\n", name);
  *val = 0;
  fgets (buff2, 255, f);

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
read_global_string (FILE * f, char *name, char **val, int alloc)
{
  char buff[256];
  int a;
  char buff2[2000];
  char buff3[2000];

  fgets (buff3, 2000, f);
  strcpy (buff2, "");
  sprintf (buff, "%s=%%s\n", name);
  a = sscanf (buff3, buff, buff2);
  if (a == 0 && strcmp (buff, buff3) != 0)
    {
      a4gl_yyerror ("Error in .glb file (string)- is it an old version ?");
    }

  if (alloc)
    {
      *val = strdup (buff2);
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
read_global_char (FILE * f, char *name, char *val)
{
  char buff[256];
  char buff3[256];

  fgets (buff3, 255, f);
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
read_global_float (FILE * f, char *name, double *val)
{
  char buff[256];
  char buff3[256];

  fgets (buff3, 255, f);
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
read_variable_header (FILE * f, struct variable *v)
{
//struct name_list *ptr;
  int a;
  int cnt;

  read_global_string (f, "NAME", &v->names.name, 1);
  v->names.next = 0;
#ifdef DEBUG
  debug ("Read variable : %s", v->names.name);
#endif

  read_global_int (f, "TYPE", &v->variable_type);
  read_global_char (f, "USER_SYSTEM", &v->user_system);
  read_global_int (f, "IS_ARRAY", &v->is_array);
  read_global_string (f, "SRC_MODULE", &v->src_module, 1);


  for (a = 0; a < MAX_ARR_SUB; a++)
    {
      v->arr_subscripts[a] = 0;
    }

  if (v->is_array)
    {
      read_global_int (f, "ARR_SUBSCRIPTS_CNT", &cnt);

      for (a = 0; a < cnt; a++)
	{
	  read_global_int (f, "ARR_SUBSCRIPT", &v->arr_subscripts[a]);
	}
    }

  if (v->variable_type == VARIABLE_TYPE_SIMPLE)
    {
      read_variable_simple (f, v);
    }
  if (v->variable_type == VARIABLE_TYPE_RECORD)
    {
      read_variable_record (f, v);
    }
  if (v->variable_type == VARIABLE_TYPE_ASSOC)
    {
      read_variable_assoc (f, v);
    }
  if (v->variable_type == VARIABLE_TYPE_CONSTANT)
    {
      read_variable_constant (f, v);
    }

}

/**
 *
 *
 * @param
 */
static void
read_variable_simple (FILE * f, struct variable *v)
{
  read_global_int (f, "DATATYPE", &v->data.v_simple.datatype);
  read_global_int (f, "DIMENSIONS_1", &v->data.v_simple.dimensions[0]);
  read_global_int (f, "DIMENSIONS_2", &v->data.v_simple.dimensions[1]);
}

/**
 *
 *
 * @param
 */
static void
read_variable_linked (FILE * f, struct variable *v)
{
  int cnt;
  struct name_list *ptr;

  read_global_string (f, "LINKTABLE", &v->data.v_record.linked->tabname, 1);
  read_global_int (f, "LINKCOLUMNS", &cnt);
  read_global_string (f, "LINKCOLUMN",
		      &v->data.v_record.linked->col_list.name, 1);

  ptr = &v->data.v_record.linked->col_list;

  while (cnt > 1)
    {
      ptr->next = malloc (sizeof (struct name_list));
      ptr = ptr->next;
      ptr->next = 0;
      read_global_string (f, "LINKCOLUMN", &ptr->name, 1);
      cnt--;
    }
}

/**
 *
 *
 * @param
 */
static void
read_variable_record (FILE * f, struct variable *v)
{
  int a;
  int is_linked;

  read_global_int (f, "COUNT", &v->data.v_record.record_cnt);
  read_global_int (f, "LINKED", &is_linked);


  if (is_linked)
    {
      v->data.v_record.linked = malloc (sizeof (struct linked_variable));
      read_variable_linked (f, v);
    }

  v->data.v_record.variables =
    malloc (sizeof (struct variable *) * v->data.v_record.record_cnt);

  for (a = 0; a < v->data.v_record.record_cnt; a++)
    {
      v->data.v_record.variables[a] = malloc (sizeof (struct variable));
      read_variable_header (f, v->data.v_record.variables[a]);
    }

}

/**
 *
 *
 * @param
 */
static void
read_variable_assoc (FILE * f, struct variable *v)
{
  struct variable *ptr;

  read_global_int (f, "SIZE", &v->data.v_assoc.size);
  read_global_int (f, "CHARSIZE", &v->data.v_assoc.char_size);
  v->data.v_assoc.variables = malloc (sizeof (struct variable *) * 1);
  ptr = v->data.v_assoc.variables[0];
  read_variable_header (f, ptr);
}

/**
 *
 *
 * @param
 */
static void
read_variable_constant (FILE * f, struct variable *v)
{
  read_global_int (f, "CONSTANT_TYPE", &v->data.v_const.consttype);

  if (v->data.v_const.consttype == CONST_TYPE_INTEGER)
    {
      read_global_int (f, "CONSTANT_VALUE", &v->data.v_const.data.data_i);
    }

  if (v->data.v_const.consttype == CONST_TYPE_CHAR)
    {
      read_global_string (f, "CONSTANT_VALUE",
			  &v->data.v_const.data.data_c, 1);
    }

  if (v->data.v_const.consttype == CONST_TYPE_IDENT)
    {
      read_global_string (f, "CONSTANT_VALUE",
			  &v->data.v_const.data.data_c, 1);
    }

  if (v->data.v_const.consttype == CONST_TYPE_FLOAT)
    {
      read_global_float (f, "CONSTANT_VALUE", &v->data.v_const.data.data_f);
    }

}

/* ================================ EOF =================================== */
