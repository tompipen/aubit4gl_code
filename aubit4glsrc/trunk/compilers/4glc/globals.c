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
# $Id: globals.c,v 1.72 2012-07-26 10:06:07 mikeaubury Exp $
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
#include "variables_new.h"

//andrej int A4GL_setenv(char *name, char *value, int overwrite);
int has_default_database (void);
extern module_definition this_module;

char *get_default_database (void);
void A4GLPACKER_clrlibptr (void);
char *expand_env_vars_in_cmdline (char *s, int showerrs);


/*
=====================================================================
                    Variables definitions
=====================================================================
*/


/* These are all located in variables.c */

//extern struct variable **list_global;	/* Our List*/
//extern int list_global_cnt;	/* Number used in our list*/
//extern int list_global_alloc;	/* Space allocated for our list*/
//extern struct variable **list_imported_global;	/* Our List*/
//extern int list_imported_global_cnt;	/* Number used in our list*/
//extern int list_imported_global_alloc;	/* Space allocated for our list*/

/* This is from 4glc.c */

extern char *outputfilename;
extern char currinfile_dirname[1024];	/*path to 4gl file we are currently compiling*/

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


/* Externally callable (non-static) functions */


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

  char nfilename[1024];

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

      			if (strlen(currinfile_dirname))
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


#ifdef __WIN32__
 	SPRINTF2 (nfilename, "%s\\%s",dirname, fname); 
#else
 	SPRINTF2 (nfilename, "%s/%s",dirname, fname); 
#endif


  if (!A4GL_file_exists(nfilename)) { // It doesn't exist as specified
					// Try with a .4gl on the end instead of any current extension
  	ptr = rindex (fname, '.');
	if (ptr) {
  		*ptr = 0;
	}
#ifdef __WIN32__
 	SPRINTF2 (nfilename, "%s\\%s.4gl",dirname, fname); 
#else
 	SPRINTF2 (nfilename, "%s/%s.4gl",dirname, fname); 
#endif
  }
 




#ifdef DEBUG
  A4GL_debug ("Trying to compile globals file %s in %s\n", nfilename);

  if (strcmp (acl_getenv ("DEBUG"), "ALL") == 0)
    {
      SPRINTF0 (buff, "mv debug.out debug1.out");
      A4GL_debug ("Preserving debug.out: %s\n", buff);
      if (fglc_verbosity()) { PRINTF("Executing :%s\n",buff);}
      system (buff);
    }
#endif
  

  if (acl_getenv_not_set_as_0("A4GL_OVERRIDE_PACKER_OUTPUT")) {
      unsetenv("A4GL_OVERRIDE_PACKER_OUTPUT");
  }

  if (acl_getenv_not_set_as_0("OVERRIDE_PACKER_OUTPUT")) {
      unsetenv("OVERRIDE_PACKER_OUTPUT");
  }

// cc 2004.11.24 need to check for -d flag from parent process 
 if (has_default_database ()) 
 { 
 	char db[64]; 
 	strcpy (db, get_default_database ()); 
#ifdef DEBUG
 	A4GL_debug ("Overriding default database with %s", A4GL_null_as_null(db)); 
#endif
 	A4GL_trim (db); 
#ifdef __WIN32__
 	SPRINTF2 (buff, "4glc -d %s --globals %s", db, nfilename); 
#else
 	SPRINTF2 (buff, "4glc -d %s --globals '%s'", db, nfilename); 
#endif
 } 
 else 
 { 
#ifdef __WIN32__
 	SPRINTF1 (buff, "4glc --globals %s", nfilename); 
#else
 	SPRINTF1 (buff, "4glc --globals '%s'", nfilename); 
#endif
 } 


#ifdef DEBUG
  A4GL_debug ("Executing system call: %s\n", buff);
#endif
      if (fglc_verbosity()) { PRINTF("Executing :%s\n",buff);}

//printf("--->%s\n", buff);
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
  //FILE *f;
  char ii[255];
  char ii4gl[255];
  char iiglb[255];
  char iii[256];
  //char override[2000];
  //char *fname;
  char *dbname;
  int schemaonly;
  //int gvars;
  //int start = 0;
  int a=0;
  //int b;
  struct globals_definition g;
  int XMLBEST=0;

  s=expand_env_vars_in_cmdline(s,0);


//printf("s=%s\n",s);

  if (s[0]!='/') {
   char *s2;
   static char buff[2000];
   if (strstr(s,".4gl")) {
      strcpy(buff,s);
      } else {
         sprintf(buff,"%s.4gl",s);
        }
        //printf("Buff=%s\n",buff);
      s2=A4GL_fullpath_dbpath (buff);

      if (s2){  s=s2;
            //printf("s=%s s2=%s\n",s,s2);
            s2=strstr(s,".4gl");
            if (s2) {*s2=0;}
         }
  }



  if (A4GL_isyes(acl_getenv("TRY_LOCAL_GLOBALS_FIRST"))) {
		static char buff[2000]="";
	if (s[0]=='/') {
		char *s2;
		s2=rindex(s,'/')+1;
		sprintf(buff,"%s",s2);
//printf("Here : %s\n",s);
		if (A4GL_file_exists(buff))  {
         printf("Using local version of %s for globals\n",s2);
			s=buff;
         
		} else {
			sprintf(buff,"%s.4gl",s2);
			if (A4GL_file_exists(buff))  {
            //printf("Using local version of %s for globals\n",s2);
				s=buff;
			} else {
            strcpy(buff,"");
            }
		}
        if (strlen(buff)) {
            char *p;
                  p=strstr(buff,".4gl");
                     if (p) {
                        *p=0;
                          }
         }
	}

  }
  /* MJA - NEWVARIABLE*/
  strcpy (ii, s);
  strcat (ii, ".glb");
#ifdef DEBUG
  A4GL_debug ("Trying to open globals file %s\n", ii);
#endif

  strcpy (ii, s);
  strcpy (ii4gl, s);
  strcpy (iiglb, s);
  strcat (ii, ".glb");


  strcat (ii4gl, ".4gl");

  strcpy(iiglb,ii);
  
  if (strcmp(acl_getenv("A4GL_PACKER"),"XMLBEST")==0) {
	A4GLPACKER_clrlibptr();
	A4GL_setenv("A4GL_PACKER","PACKED",1);
	XMLBEST=1;
  }

  if (strcmp(acl_getenv("A4GL_PACKER"),"PACKED")==0) {
  	strcat(iiglb,acl_getenv("A4GL_PACKED_EXT"));
  }
  if (strcmp(acl_getenv("A4GL_PACKER"),"GZPACKED")==0) {
  	strcat(iiglb,acl_getenv("A4GL_PACKED_EXT"));
  }
  if (strcmp(acl_getenv("A4GL_PACKER"),"XML")==0) {
  	strcat(iiglb,acl_getenv("A4GL_XML_EXT"));
  }

  {
	char *s2;
	s2=rindex(iiglb,'/');
	if (s2) {
		s2++;
  		a=A4GL_read_data_from_file_generic("module_definition", "globals_definition",&g,s2);
	}
  }

	if (!a) {
  		if (A4GL_file_exists(iiglb) && A4GL_file_is_newer(iiglb,ii4gl)) {
  			a=A4GL_read_data_from_file_generic("module_definition", "globals_definition",&g,ii);
			
  		}
	}


  aclfgli_clr_err_flg(); A4GL_set_status(0,1);
  if (!a) {
     		generate_globals_for (ii4gl);
  }

  a=A4GL_read_data_from_file_generic("module_definition", "globals_definition",&g,ii);

 // Finally - just try in the local directory...
  if (!a) {
	char *s2;
	s2=rindex(ii,'/');
	if (s2) {
		s2++;
  		a=A4GL_read_data_from_file_generic("module_definition", "globals_definition",&g,s2);
	}
  }

	if (!a) {
		char iii4gl[2000];
		char iiiglb[2000];
  		strcpy (iii, currinfile_dirname);
  		strcat (iii, "/");
		strcpy(iii4gl, iii);
		strcpy(iiiglb, iii);
   		strcat (iii4gl, ii4gl);
   		strcat (iiiglb, iiglb);
      		generate_globals_for (iii4gl);
  		a=A4GL_read_data_from_file_generic("module_definition", "globals_definition",&g,iiiglb);
		aclfgli_clr_err_flg(); A4GL_set_status(0,1);
 }


 if (!a) {
 	FPRINTF (stderr, "Error: Couldnt open globals file %s, in . and %s\n", ii, currinfile_dirname );
	  exit (7);
	}
  A4GL_set_status(0,0);
  dbname=g.mod_dbname;
  schemaonly=g.schema_only;

  if (g.used_object_types.used_object_types_len) {
	int a;
	for (a=0;a<g.used_object_types.used_object_types_len;a++) {
			A4GL_used_object_type(&this_module, g.used_object_types.used_object_types_val[a]);
	}
  }

  if (g.pragmas.pragmas_len) {
	int a;
	for (a=0;a<g.pragmas.pragmas_len;a++) {
		char *val1=NULL;
		char *val2=NULL;

		switch (g.pragmas.pragmas_val[a].pragma_type) {
        		case E_PRAGMA_SYSTEM_4GL:   
        		case E_PRAGMA_NOSQLCLOBBER: 
        		case E_PRAGMA_NOCLOBBER:  
        		case E_PRAGMA_ALWAYSSQLCLOBBER:  
        		case E_PRAGMA_ALWAYSCLOBBER:  
        		case E_PRAGMA_LINTMODULEISLIBRARY: 
				val1=NULL; val2=NULL;
				break;

        		case E_PRAGMA_SQL_FEATURE: 
        		case E_PRAGMA_EMULATE_INSERT_CURSOR_FOR: 
        		case E_PRAGMA_STOP_REPLACE_STRING: 
        		case E_PRAGMA_IGNORE_FUNCTION: 
        		case E_PRAGMA_FORCE_UI: 
        		case E_PRAGMA_DEBUG_FILE: 
        		case E_PRAGMA_SET_POSTGRESQL_SEARCH_PATH: 
				val1=g.pragmas.pragmas_val[a].u_pragmas_u.string_value;
				val2=NULL;
				break;

        		case E_PRAGMA_REPLACE_STRING: 
        		case E_PRAGMA_COLUMN_IS_SERIAL:  
				val1=g.pragmas.pragmas_val[a].u_pragmas_u.two_string_value.string1;
				val1=g.pragmas.pragmas_val[a].u_pragmas_u.two_string_value.string2;
				break;
		} 
		A4GL_set_pragma (&this_module, g.pragmas.pragmas_val[a].pragma_type, val1, val2,1);
	}
  }

  if (strlen (dbname) > 0)
    {
	set_module_dbname(dbname, schemaonly);
      	open_db (dbname);
    }

  if (g.exported_global_variables.variables.variables.variables_len==0) {
		printf("WARNING: No globals variables were read from file %s (Missing GLOBALS.. END GLOBALS?)\n", ii4gl);
  }
  // We need to change the scope on these imported globals - as they'll
  // be marked as 'external globals' in the file that exports them ;-)
  set_variable_scope_for_variable_list(&g.exported_global_variables.variables,E_SCOPE_IMPORTED_GLOBAL);

  merge_variable_list(&this_module.imported_global_variables.variables, &g.exported_global_variables.variables);

  this_module.imported_global_files_hashes.str_list_entry.str_list_entry_len++;
  this_module.imported_global_files_hashes.str_list_entry.str_list_entry_val=realloc(this_module.imported_global_files_hashes.str_list_entry.str_list_entry_val, this_module.imported_global_files_hashes.str_list_entry.str_list_entry_len*sizeof(char *));
  this_module.imported_global_files_hashes.str_list_entry.str_list_entry_val[this_module.imported_global_files_hashes.str_list_entry.str_list_entry_len-1]=strdup(g.hash);


  if (XMLBEST) {
	//printf("Reset\n");
	A4GL_setenv("A4GL_PACKER","XMLBEST",1);
	A4GLPACKER_clrlibptr();
  }

}



static char *mkhash(char *name, struct variable_list *vlist) {
static char buff[300];
char nm[300];
int b=0;
int a;
int sl;
long hash=0;
sl=strlen(name);

for (a=0;a<sl;a++) {
	if (name[a]=='/' || name[a]=='\\') {
		// reset on any leading path separator
		b=0; continue;
	}
	if (name[a]>='a' && name[a]<='z') {
		nm[b++]=name[a];
	}
	if (name[a]>='A' && name[a]<='Z') {
		nm[b++]=name[a];
	}
	if (name[a]>='0' && name[a]<='9') {
		nm[b++]=name[a];
	}
}
nm[b]=0;
hash=vlist->variables.variables_len;
for(a=0;a<vlist->variables.variables_len;a++) {
	char *p;
	p=vlist->variables.variables_val[a]->names.names.names_val[0].name;
	for (b=0;b<strlen(p);b++) {
		hash+=p[b]*(b+1);
	}
	
}

sprintf(buff,"%s_%lx",nm,hash);
return strdup(buff);
}

/**
 *
 *
 * @param
 */
void
dump_gvars (void)
{
  //FILE *f;
  //int a;
  char ii[FNAMESIZE];
  //struct variable *v;
  struct globals_definition *g;

  this_module.hash= mkhash(this_module.module_name, &this_module.exported_global_variables.variables);

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
  g->hash=this_module.hash;

  g->external_datatypes.external_datatypes_len=this_module.external_datatypes.external_datatypes_len;
  g->external_datatypes.external_datatypes_val=this_module.external_datatypes.external_datatypes_val;
  g->schema_only=this_module.schema_only;
  g->compiled_time=this_module.compiled_time;
  g->exported_global_variables.variables.variables.variables_len=this_module.exported_global_variables.variables.variables.variables_len;
  g->exported_global_variables.variables.variables.variables_val=this_module.exported_global_variables.variables.variables.variables_val;
	g->pragmas.pragmas_len=this_module.pragmas.pragmas_len;
	g->pragmas.pragmas_val=this_module.pragmas.pragmas_val;

	if (g->mod_dbname==0) g->mod_dbname="";

  	if (!A4GL_write_data_to_file_generic("module_definition", "globals_definition",g,ii)) {
		printf("Unable to write GLOBALs data\n");
		exit(2);
	}

}


static int _has_globals=0;

void set_has_globals(void) {
_has_globals=1;
}

int has_globals(void)  {
return _has_globals;
}


/* ================================ EOF =================================== */
