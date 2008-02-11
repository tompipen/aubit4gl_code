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
# $Id: globals.c,v 1.42 2008-02-11 17:13:06 mikeaubury Exp $
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

//andrej int A4GL_setenv(char *name, char *value, int overwrite);
int has_default_database (void);
extern module_definition this_module;

char *get_default_database (void);
/*
=====================================================================
                    Variables definitions
=====================================================================
*/


/* These are all located in variables.c */

extern struct variable **list_global;	/* Our List*/
extern int list_global_cnt;	/* Number used in our list*/
extern int list_global_alloc;	/* Space allocated for our list*/
extern struct variable **list_imported_global;	/* Our List*/
extern int list_imported_global_cnt;	/* Number used in our list*/
extern int list_imported_global_alloc;	/* Space allocated for our list*/

/* This is from 4glc.c */

extern char *outputfilename;
extern char currinfile_dirname[1024];	/*path to 4gl file we are currently compiling*/

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
static void write_variable_object (FILE * f, struct variable *v);
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
static void read_variable_object (FILE * f, struct variable *v);
static void generate_globals_for (char *s);
static void write_variable_function (FILE * f, struct variable *v) ;
static void read_variable_function (FILE * f, struct variable *v) ;

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
  FPRINTF (f, "%s=%d\n", name, val);
}

/**
 *
 *
 * @param
 */
static void
write_global_string (FILE * f, char *name, char *val)
{
  FPRINTF (f, "%s=%s\n", name, val);
}

/**
 *
 *
 * @param
 */
static void
write_global_char (FILE * f, char *name, char val)
{
  FPRINTF (f, "%s=%c\n", name, val);
}

/**
 *
 *
 * @param
 */
static void
write_global_float (FILE * f, char *name, double val)
{
  FPRINTF (f, "%s=%f\n", name, val);
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
  char ii[FNAMESIZE];
  struct variable *v;
  struct globals_definition *g;


  if (!only_doing_globals() ) return;

  if (!A4GL_env_option_set("A4GL_LOCALOUTPUT")) {
        strcpy (ii, outputfilename);
  } else {
          char *ptr;
          // Local output will strip any directory from the output
          // files and create them in the local directory instead...
          ptr=outputfilename;
#ifdef __WIN32__
          if (rindex(ptr,'\\')) { ptr=rindex(ptr,'\\')+1; }
	  else {
			// No windows style path - maybe unix style ? 
          	if (rindex(ptr,'/')) { ptr=rindex(ptr,'/')+1; }
	  }
#else
          if (rindex(ptr,'/')) { ptr=rindex(ptr,'/')+1; }
#endif

          strcpy (ii, ptr);
  }

  strcat (ii, ".glb");
  g=malloc(sizeof(globals_definition));
  memset(g,0,sizeof(*g));

  g->mod_dbname=this_module.mod_dbname;
  g->external_datatypes.external_datatypes_len=this_module.external_datatypes.external_datatypes_len;
  g->external_datatypes.external_datatypes_val=this_module.external_datatypes.external_datatypes_val;
  g->schema_only=this_module.schema_only;
  g->compiled_time=this_module.compiled_time;
  g->exported_global_variables.variables.variables_len=this_module.exported_global_variables.variables.variables_len;
  g->exported_global_variables.variables.variables_val=this_module.exported_global_variables.variables.variables_val;

  A4GL_write_data_to_file_generic("module_definition", "globals_definition",g,ii);

/*
  f = A4GL_mja_fopen (ii, "w");
  if (f == 0)
    {
      FPRINTF (stderr, "Critical error - couldnt open output file %s\n", ii);
      exit (0);
    }

  if (get_module_dbname()) {
  	write_global_string (f, "DATABASE", get_module_dbname ());
  } else {
  	write_global_string (f, "DATABASE","");
  }
  write_global_int (f, "SCHEMA_ONLY", get_module_isschema());
  write_global_int (f, "NUMVARS", list_global_cnt);

  for (a = 0; a < list_global_cnt; a++)
    {
      v = list_global[a];
      A4GL_debug ("Output Global Entry %d - %p\n", a, v);
      write_variable_header (f, v);
    }


  fclose (f);
*/
}





/**
 *
 *
 * @param
 */
static void
write_variable_header (FILE * f, struct variable *v)
{
  /* struct name_list *ptr; */
  int a;
  int cnt;

  write_global_string (f, "NAME", v->names.names.names_val[0].name);
  /* ptr = v->names.next; */

  write_global_int (f, "TYPE", v->var_data.variable_type);
  write_global_char (f, "USER_SYSTEM", v->user_system);


  //write_global_int (f, "IS_ARRAY", v->is_array);
  write_global_string (f, "SRC_MODULE", v->src_module);
  write_global_string (f, "DEFSRC", v->defsrc);


  if (v->arr_subscripts.arr_subscripts_len)
    {
      cnt = 0;
	cnt=v->arr_subscripts.arr_subscripts_len;

      write_global_int (f, "ARR_SUBSCRIPTS_CNT", cnt);

      for (a = 0; a < cnt; a++)
	{
	    write_global_int (f, "ARR_SUBSCRIPT", v->arr_subscripts.arr_subscripts_val[a]);
	}
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_SIMPLE)
    {
      write_variable_simple (f, v);
	return ;
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_RECORD)
    {
      write_variable_record (f, v);
	return;
    }
  if (v->var_data.variable_type == VARIABLE_TYPE_OBJECT)
    {
      write_variable_object (f, v);
	return;
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_ASSOC)
    {
      write_variable_assoc (f, v);
	return;
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_CONSTANT)
    {
      write_variable_constant (f, v);
	return;
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_FUNCTION_DECLARE)
    {
      write_variable_function (f, v);
	return;
    }
  FPRINTF(stderr,"Warning - unknown variable type : %d\n",v->var_data.variable_type);
}


/**
 *
 *
 * @param
 */
static void
write_variable_simple (FILE * f, struct variable *v)
{
  write_global_int (f, "DATATYPE", v->var_data.variable_data_u.v_simple.datatype);
  write_global_int (f, "DIMENSIONS_1", v->var_data.variable_data_u.v_simple.dimensions[0]);
  write_global_int (f, "DIMENSIONS_2", v->var_data.variable_data_u.v_simple.dimensions[1]);
}



/**
 *
 *
 * @param
 */
static void
write_variable_linked (FILE * f, struct variable *v)
{
int cnt;
  //struct name_list *ptr;

  write_global_string (f, "LINKTABLE", v->var_data.variable_data_u.v_record.linked->tabname);


/*
  cnt = 1;

  ptr = v->var_data.variable_data_u.v_record.linked->col_list.next;
  while (ptr)
    {
      cnt++;
      ptr = ptr->next;
    }
*/


  write_global_int (f, "LINKCOLUMNS", v->var_data.variable_data_u.v_record.linked->col_list.names.names_len);

  for (cnt=0;cnt<v->var_data.variable_data_u.v_record.linked->col_list.names.names_len;cnt++) {
  	write_global_string (f, "LINKCOLUMN", v->var_data.variable_data_u.v_record.linked->col_list.names.names_val[cnt].name);
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
  write_global_int (f, "COUNT", v->var_data.variable_data_u.v_record.variables.variables_len);

  if (v->var_data.variable_data_u.v_record.linked == 0)
    {
      write_global_int (f, "LINKED", 0);
    }
  else
    {
      write_global_int (f, "LINKED", 1);
      write_variable_linked (f, v);
    }

  for (a = 0; a < v->var_data.variable_data_u.v_record.variables.variables_len; a++)
    {
      write_variable_header (f, v->var_data.variable_data_u.v_record.variables.variables_val[a]);
    }

}


/**
 *
 *
 * @param
 */
static void
write_variable_object (FILE * f, struct variable *v)
{
  int a;
  write_global_int (f, "COUNT", v->var_data.variable_data_u.v_record.variables.variables_len);

  if (v->var_data.variable_data_u.v_record.linked == 0)
    {
      write_global_int (f, "LINKED", 0);
    }
  else
    {
      write_global_int (f, "LINKED", 1);
      write_variable_linked (f, v);
    }

  for (a = 0; a < v->var_data.variable_data_u.v_record.variables.variables_len; a++)
    {
      write_variable_header (f, v->var_data.variable_data_u.v_record.variables.variables_val[a]);
    }

    write_global_string(f,"OBJECT_TYPE",v->var_data.variable_data_u.v_record.object_type);
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
  write_global_int (f, "SIZE", v->var_data.variable_data_u.v_assoc.size);
  write_global_int (f, "CHARSIZE", v->var_data.variable_data_u.v_assoc.char_size);
  ptr = v->var_data.variable_data_u.v_assoc.variables.variables_val[0];
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

  write_global_int (f, "CONSTANT_TYPE", v->var_data.variable_data_u.v_const.consttype);

  if (v->var_data.variable_data_u.v_const.consttype == CONST_TYPE_INTEGER)
    {
      write_global_int (f, "CONSTANT_VALUE", v->var_data.variable_data_u.v_const.constant_data_u.data_i);
    }


  if (v->var_data.variable_data_u.v_const.consttype == CONST_TYPE_CHAR
      || v->var_data.variable_data_u.v_const.consttype == CONST_TYPE_IDENT)
    {
      write_global_string (f, "CONSTANT_VALUE", v->var_data.variable_data_u.v_const.constant_data_u.data_c);
    }

  if (v->var_data.variable_data_u.v_const.consttype == CONST_TYPE_FLOAT)
    {
      write_global_float (f, "CONSTANT_VALUE", v->var_data.variable_data_u.v_const.constant_data_u.data_f);
    }

}

static void
write_variable_function (FILE * f, struct variable *v)
{


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
  A4GL_debug ("In generate_globals_for\n");
#endif

  strcpy (buff, s);



  /*NOTE: we will get path in s only if it was specified in GLOBALS declaration*/
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
#ifdef __WIN32__
  		if (strchr (buff, '\\'))
#else
  		if (0) 
#endif
    		{
      			strcpy (dirname, buff);
      			ptr = strrchr (dirname, '\\');
      			*ptr = 0;
      			ptr++;
      			strcpy (fname, ptr);
			
    		}  else {

      			if (currinfile_dirname)
				{
	  			/*use path that was passed to 4glc with 4gl file name of main 4gl*/
	  			/*source file we are compiling, if any*/
	  			strcpy (dirname, currinfile_dirname);
			
			} else {
	  			strcpy (dirname, ".");
			}
      			strcpy (fname, buff);
		}
    }




  strcpy (nocfile, acl_getenv ("A4GL_NOCFILE"));
#ifdef MSVC
  putenv("A4GL_NOCFILE=Yes");
#else
  A4GL_setenv ("A4GL_NOCFILE", "Yes", 1);
#endif
  ptr = strchr (fname, '.');
  *ptr = 0;
#ifdef DEBUG
  A4GL_debug ("Trying to compile globals file %s in %s\n", fname, dirname);

  if (strcmp (acl_getenv ("DEBUG"), "ALL") == 0)
    {
      SPRINTF0 (buff, "mv debug.out debug1.out");
      A4GL_debug ("Preserving debug.out: %s\n", buff);
      if (fglc_verbosity()) { PRINTF("Executing :%s\n",buff);}
      system (buff);
    }
#endif
  /*why cd? just pass the path in file name... */
  

#ifdef __WIN32__
// cc 2004.11.24 need to check for -d flag from parent process 
 if (has_default_database ()) 
 { 
 	char db[64]; 
 	strcpy (db, get_default_database ()); 
 	A4GL_debug ("Overriding default database with %s", A4GL_null_as_null(db)); 
 	A4GL_trim (db); 
 	SPRINTF3 (buff, "4glc -d %s --globals \"%s\\%s.4gl\"", db, dirname, fname); 
 } 
 else 
 { 
 	SPRINTF2 (buff, "4glc --globals \"%s\\%s.4gl\"", dirname, fname); 
 } 
#else
// cc 2004.11.24 need to check for -d flag from parent process 
 if (has_default_database ()) 
 { 
 	char db[64]; 
 	strcpy (db, get_default_database ()); 
 	A4GL_debug ("Overriding default database with %s", A4GL_null_as_null(db)); 
 	A4GL_trim (db); 
 	SPRINTF3 (buff, "4glc -d %s --globals '%s/%s.4gl'", db, dirname, fname); 
 } 
 else 
 { 
 	SPRINTF2 (buff, "4glc --globals '%s/%s.4gl'", dirname, fname); 
 } 
#endif
 // cc end change 


#ifdef DEBUG
  A4GL_debug ("Executing system call: %s\n", buff);
#endif
      if (fglc_verbosity()) { PRINTF("Executing :%s\n",buff);}
  system (buff);
#ifdef MSVC
  putenv("A4GL_NOCFILE=Y");
#else
  A4GL_setenv ("A4GL_NOCFILE", nocfile, 1);
#endif
#ifdef DEBUG
  if (strcmp (acl_getenv ("DEBUG"), "ALL") == 0)
    {
      SPRINTF (buff, "mv debug.out debug-globals.out");
      A4GL_debug ("Preserving debug.out: %s\n", buff);
      if (fglc_verbosity()) { PRINTF("Executing :%s\n",buff);}
      system (buff);
      SPRINTF (buff, "mv debug1.out debug.out");
      A4GL_debug ("Restoring debug.out: %s\n", buff);
      if (fglc_verbosity()) { PRINTF("Executing :%s\n",buff);}
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
  char ii[255];
  char iii[256];
  char *fname;
  char *dbname;
  int schemaonly;
  int gvars;
  int start = 0;
  int a;
int b;
  struct globals_definition g;

  /* MJA - NEWVARIABLE*/
  strcpy (ii, s);
  strcat (ii, ".glb");
#ifdef DEBUG
  A4GL_debug ("Trying to open globals file %s\n", ii);
#endif

  strcpy (ii, s);
  strcat (ii, ".glb");
  a=A4GL_read_data_from_file_generic("module_definition", "globals_definition",&g,ii);
		aclfgli_clr_err_flg(); A4GLSQL_set_status(0,1);
  if (!a) {
     		generate_globals_for (ii);
  }
  a=A4GL_read_data_from_file_generic("module_definition", "globals_definition",&g,ii);
	if (!a) {
  		strcpy (iii, currinfile_dirname);
  		strcat (iii, "/");
   		strcat (iii, ii);
      		generate_globals_for (iii);
  		a=A4GL_read_data_from_file_generic("module_definition", "globals_definition",&g,iii);
		aclfgli_clr_err_flg(); A4GLSQL_set_status(0,1);
 }

 if (!a) {
 	FPRINTF (stderr, "Error: Couldnt open globals file %s, in . and %s\n", ii, currinfile_dirname);
	  exit (7);
	}
A4GLSQL_set_status(0,0);
  dbname=g.mod_dbname;
  schemaonly=g.schema_only;

  if (strlen (dbname) > 0)
    {
	set_module_dbname(dbname, schemaonly);
      	open_db (dbname);
    }

  gvars=g.exported_global_variables.variables.variables_len;
  start = list_imported_global_cnt;
  list_imported_global_cnt += gvars;

  if (list_imported_global_cnt > list_imported_global_alloc)
    {
      list_imported_global_alloc = list_imported_global_cnt;
    }

  list_imported_global =
    acl_realloc (list_imported_global,
	     sizeof (struct variable *) * list_imported_global_alloc);

  b=0;
  for (a = start; a < list_imported_global_cnt; a++)
    {
      //list_imported_global[a] = acl_malloc2 (sizeof (struct variable));
	list_imported_global[a]=g.exported_global_variables.variables.variables_val[b++];
      //read_variable_header (f, list_imported_global[a]);
    }
  //fclose (f);
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

  SPRINTF1 (buff, "%s=%%d\n", name);
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
read_global_char (FILE * f, char *name, char *val)
{
  char buff[256];
  char buff3[256];

  fgets (buff3, 255, f);
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
read_global_float (FILE * f, char *name, double *val)
{
  char buff[256];
  char buff3[256];

  fgets (buff3, 255, f);
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
read_variable_header (FILE * f, struct variable *v)
{
/*struct name_list *ptr;*/
  int a;
  int cnt;
  int vt;
  

 
  v->names.names.names_val=malloc(sizeof(vname));
  v->names.names.names_val[0].alias=0;
  v->names.names.names_len=0;
  v->usage=0;
  v->assigned=0;
  v->lineno=0;
  v->is_extern=0;
  v->flags=0;
  read_global_string (f, "NAME", &v->names.names.names_val[0].name, 1);
	v->names.names.names_len=1;

#ifdef DEBUG
  A4GL_debug ("Read variable : %s", v->names.name);
#endif
  v->is_static=0;

  read_global_int (f, "TYPE", &vt);
 v->var_data.variable_type=vt;
  read_global_char (f, "USER_SYSTEM", &v->user_system);
  //read_global_int (f, "IS_ARRAY", &v->is_array);
  read_global_string (f, "SRC_MODULE", &v->src_module, 1);
  read_global_string (f, "DEFSRC", &v->defsrc, 1);
  v->scope='G';
  v->defsrc="";

      v->arr_subscripts.arr_subscripts_val = 0;
      v->arr_subscripts.arr_subscripts_len = 0;

      read_global_int (f, "ARR_SUBSCRIPTS_CNT", &cnt);

  if (cnt)
    {
	v->arr_subscripts.arr_subscripts_len=cnt;
	v->arr_subscripts.arr_subscripts_val=malloc(cnt*sizeof(v->arr_subscripts.arr_subscripts_val[0]));

      for (a = 0; a < cnt; a++)
	{
	  read_global_int (f, "ARR_SUBSCRIPT", &v->arr_subscripts.arr_subscripts_val[a]);
	}
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_SIMPLE)
    {
      read_variable_simple (f, v);
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_RECORD)
    {
      read_variable_record (f, v);
    }
  if (v->var_data.variable_type == VARIABLE_TYPE_OBJECT)
    {
      read_variable_object (f, v);
    }

  if (v->var_data.variable_type == VARIABLE_TYPE_ASSOC)
    {
      read_variable_assoc (f, v);
    }
  if (v->var_data.variable_type == VARIABLE_TYPE_CONSTANT)
    {
      read_variable_constant (f, v);
    }

  if (v->var_data.variable_type ==  VARIABLE_TYPE_FUNCTION_DECLARE)
    {
      read_variable_function (f, v);
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
  read_global_int (f, "DATATYPE", &v->var_data.variable_data_u.v_simple.datatype);
  read_global_int (f, "DIMENSIONS_1", &v->var_data.variable_data_u.v_simple.dimensions[0]);
  read_global_int (f, "DIMENSIONS_2", &v->var_data.variable_data_u.v_simple.dimensions[1]);
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
  //struct name_list *ptr;

  read_global_string (f, "LINKTABLE", &v->var_data.variable_data_u.v_record.linked->tabname, 1);
  read_global_int (f, "LINKCOLUMNS", &cnt);

  v->var_data.variable_data_u.v_record.linked->col_list.names.names_len=cnt;
  v->var_data.variable_data_u.v_record.linked->col_list.names.names_val=malloc(sizeof(vname)*cnt);
  for (cnt=0;cnt<v->var_data.variable_data_u.v_record.linked->col_list.names.names_len;cnt++) {
	v->var_data.variable_data_u.v_record.linked->col_list.names.names_val[cnt].alias=0;
  	read_global_string (f, "LINKCOLUMN", &v->var_data.variable_data_u.v_record.linked->col_list.names.names_val[cnt].name, 1);
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

  read_global_int (f, "COUNT", &v->var_data.variable_data_u.v_record.variables.variables_len);
  read_global_int (f, "LINKED", &is_linked);

   v->var_data.variable_data_u.v_record.record_alloc=0;
   v->var_data.variable_data_u.v_record.linked=0;
   v->var_data.variable_data_u.v_record.object_type=0;
   strcpy(v->var_data.variable_data_u.v_record.user_ptr,"");

  if (is_linked)
    {
      v->var_data.variable_data_u.v_record.linked = acl_malloc2 (sizeof (struct linked_variable));
      read_variable_linked (f, v);
    }

  v->var_data.variable_data_u.v_record.variables.variables_val =
    acl_malloc2 (sizeof (struct variable *) * v->var_data.variable_data_u.v_record.variables.variables_len);

  for (a = 0; a < v->var_data.variable_data_u.v_record.variables.variables_len; a++)
    {
      v->var_data.variable_data_u.v_record.variables.variables_val[a] = acl_malloc2 (sizeof (struct variable));
      read_variable_header (f, v->var_data.variable_data_u.v_record.variables.variables_val[a]);
    }

}

/**
 *
 *
 * @param
 */
static void
read_variable_object (FILE * f, struct variable *v)
{
  int a;
  int is_linked;

  read_global_int (f, "COUNT", &v->var_data.variable_data_u.v_record.variables.variables_len);
  read_global_int (f, "LINKED", &is_linked);


  if (is_linked)
    {
      v->var_data.variable_data_u.v_record.linked = acl_malloc2 (sizeof (struct linked_variable));
      read_variable_linked (f, v);
    }

  v->var_data.variable_data_u.v_record.variables.variables_val =
    acl_malloc2 (sizeof (struct variable *) * v->var_data.variable_data_u.v_record.variables.variables_len);

  for (a = 0; a < v->var_data.variable_data_u.v_record.variables.variables_len; a++)
    {
      v->var_data.variable_data_u.v_record.variables.variables_val[a] = acl_malloc2 (sizeof (struct variable));
      read_variable_header (f, v->var_data.variable_data_u.v_record.variables.variables_val[a]);
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

  read_global_int (f, "SIZE", &v->var_data.variable_data_u.v_assoc.size);
  read_global_int (f, "CHARSIZE", &v->var_data.variable_data_u.v_assoc.char_size);
  v->var_data.variable_data_u.v_assoc.variables.variables_val = acl_malloc2 (sizeof (struct variable *) * 1);
  ptr = v->var_data.variable_data_u.v_assoc.variables.variables_val[0];
  read_variable_header (f, ptr);
}

static void
read_variable_function (FILE * f, struct variable *v) {
/* Does nothing - reserved for future use...*/
}



/**
 *
 *
 * @param
 */
static void
read_variable_constant (FILE * f, struct variable *v)
{
int a;

  read_global_int (f, "CONSTANT_TYPE", &a); 
   v->var_data.variable_data_u.v_const.consttype=a;

  if (v->var_data.variable_data_u.v_const.consttype == CONST_TYPE_INTEGER)
    {
      read_global_int (f, "CONSTANT_VALUE", &v->var_data.variable_data_u.v_const.constant_data_u.data_i);
    }

  if (v->var_data.variable_data_u.v_const.consttype == CONST_TYPE_CHAR)
    {
      read_global_string (f, "CONSTANT_VALUE",
			  &v->var_data.variable_data_u.v_const.constant_data_u.data_c, 1);
    }

  if (v->var_data.variable_data_u.v_const.consttype == CONST_TYPE_IDENT)
    {
      read_global_string (f, "CONSTANT_VALUE",
			  &v->var_data.variable_data_u.v_const.constant_data_u.data_ident, 1);
    }

  if (v->var_data.variable_data_u.v_const.consttype == CONST_TYPE_FLOAT)
    {
      read_global_float (f, "CONSTANT_VALUE", &v->var_data.variable_data_u.v_const.constant_data_u.data_f);
    }

}

/* ================================ EOF =================================== */
