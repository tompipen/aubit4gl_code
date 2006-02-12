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
# $Id: ltcalldll.c,v 1.2 2006-02-12 09:56:30 mikeaubury Exp $
#
*/

/**
 * @file
 * Implementation of dll calling mechanism
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_libaubit4gl_int.h"

#include <ltdl.h>



#ifndef SO_EXT
	#ifdef WIN32
		#define SO_EXT "dll"
	#else
		#define SO_EXT "so"
	#endif
#endif


/*
=====================================================================
                    Variables definitions
=====================================================================
*/

static char tempbuff[1024];

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

static void badfunc (void);
void *A4GL_find_func_double (void *dllhandle, char *func);
static void inc_usage (char *s);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/



/**
 * When someone try to find a function that does not exist in the dll its
 * returned a pointer to this function.
 *
 * This way if someone try to call a non existent function the program stops.
 */
static void
badfunc (void)
{
  /* A4GL_exitwith ("No DLL Loaded"); */
  A4GL_exitwith ("0: Non-existing function called in DLL\n");
}

/**
 *
 * @todo Describe function
 */
int
A4GL_nullfunc (void)
{
  A4GL_debug ("Calling DLL where no function defined (Allowed)");
  return 1;
}


int A4GL_isnullfunc(void *ptr) {
if (ptr==(void *)A4GL_nullfunc) return 1;
else return 0;
}

/**
 * Open a dynamic library.
 *
 * The name of the .so library is a concatenation of lib, type and name.
 * It have the general format lib<type>_<name>.[dll|so]
 * It tryes to find it in AUBITDIR/lib.
 *
 * @todo : provide more debugging info when load fails
 *
 * @param type The type of the library to open. Examples are:
 *   - SQL - The database connectors.
 *   - MENU
 *   - MSG
 *   - FORM
 * @param p The name of the plugin. Example for SQL:
 *   - esql ; odbc ; pgsql
 * @return A pointer to the dynamic library handle.
 */
void *
A4GL_dl_openlibrary (char *type, char *p)
{
  lt_dlhandle dllhandle;
  static int started=0;
  static char buff[1024];
  char buff2[1024];
  static char tmpbuff[1024];
  //char *soext;
  //char soext_2[256];
  char *plugin_name;
  char *aplugins;
  SPRINTF2 (tmpbuff, "lib%s_%s", type,p);
  plugin_name = tmpbuff;


  if (!started) {
	  int errors;
	  //char buff[256];
	  started++;
	  errors=lt_dlinit();
	  if (errors) { A4GL_debug("lt_dlinit fails : %s",lt_dlerror()); }
	  //LTDL_SET_PRELOADED_SYMBOLS();

#ifndef SIMPLIFIED
	  aplugins=acl_getenv_not_set_as_0("AUBITPLUGINDIR");

	  if (aplugins) {
		  	A4GL_debug("Adding %s to searchpath",aplugins);
		  	errors=lt_dladdsearchdir(aplugins);
	  		if (errors) { A4GL_debug("lt_dladdsearchdir fails : %s",lt_dlerror()); }
	  }


#else
	   aplugins=AUBITPLUGINDIR;
	   if (aplugins) {
	  	if (strlen(aplugins)==0) {
	  		aplugins=0;
	 	}
  	  }
	  if (aplugins) {
		  	A4GL_debug("Adding %s to searchpath",aplugins);

		  	errors=lt_dladdsearchdir(aplugins);
	  		if (errors) { A4GL_debug("lt_dladdsearchdir fails : %s",lt_dlerror()); }
		}
	  if (acl_getenv_not_set_as_0("AUBITDIR")) {
	  	SPRINTF1(buff,"%s/lib/aubit4gl",acl_getenv("AUBITDIR"));
		  	A4GL_debug("Adding %s to searchpath",buff);
	  	errors=lt_dladdsearchdir(buff);
	  	if (errors) { A4GL_debug("lt_dladdsearchdir fails : %s",lt_dlerror()); }
	  }
		  	A4GL_debug("Adding . to searchpath",buff);
  	errors=lt_dladdsearchdir(".");
  	if (errors) { A4GL_debug("lt_dladdsearchdir fails : %s",lt_dlerror()); }
#endif



  }



  dllhandle = lt_dlopenext (plugin_name);
  if (dllhandle == 0)
    {

      /* Sometimes dlerror() returns empty string? */
      /* dllerror is nulled after first call - can't call it twice, so we
         have to store it to be able to use it twice */
      SPRINTF1 (buff2, "%s", lt_dlerror ());

      PRINTF ("Error: can't open DLL %s - STOP\n", A4GL_null_as_null(buff));
      PRINTF ("Error msg: %s\n", A4GL_null_as_null(buff2));

      A4GL_debug ("Error: can't open DLL %s - STOP\n", A4GL_null_as_null(buff));
      A4GL_debug ("Error msg: %s\n", A4GL_null_as_null(buff2));

      A4GL_exitwith ("Error: can't open DLL - STOP. See debug.out");
      //FIXME: why is A4GL_exitwith not exiting???
	A4GL_fgl_die_with_msg(44,"Cannot open DLL");

    }
  A4GL_debug("Associating handle %p with dll %s,%s",dllhandle,type,p);
  return dllhandle;
}






/**
 * Try to find a function in a dll loaded.
 *
 * @param dllhandle The dynamic library handler.
 * @param func The function name.
 * @return - A pointer to the loaded function if it exist in the dll.
 *         - A pointer to the function badfunc if did not find it.
 */
void *
A4GL_find_func (void *v_dllhandle, char *func)
{
	char tempbuff[256];
	lt_dlhandle handle;
	handle=v_dllhandle;

  	int (*func_ptr) (void);


/*
 FIXME:
 We should be using system independent dlopen wrapper provided by
 libtool 1.4, which is fully integrated with Autoconf/Automake, and did I say,
 platform independent?
 see $AUBITDIR/libltdl/ltdl.c
*/

  strcpy(tempbuff,func);
  inc_usage(func);

  A4GL_debug ("35 find_func: Finding pointer to DLL function %s\n", A4GL_null_as_null(tempbuff));

  if (handle == 0)
    {
      A4GL_debug ("Not found - bad handle (%s)",func);
      A4GL_exitwith ("Could not open shared library");
      return badfunc;
    }

  A4GL_debug("Finding %s in %p",tempbuff,handle);

  func_ptr = lt_dlsym (handle, tempbuff);
  A4GL_debug ("35 Got %p", func_ptr);
  if ((void *)func_ptr == (void *)0)
    {
	char buff[256];
      	A4GL_debug ("1 Function Not found : %s dll : %p",tempbuff,handle);
	A4GL_debug("-->%s\n",lt_dlerror());
      	A4GL_exitwith ("Could not find function in shared library");
	SPRINTF1(buff,"Error:Could not find function in shared library (%s)- STOP",func);
      	A4GL_fgl_die_with_msg(43,buff);
	return badfunc;
    }


  return (void *)func_ptr;
}

/**
 * Try to find a function in a dll loaded.
 *
 * @param dllhandle The dynamic library handler.
 * @param func The function name.
 * @return - A pointer to the loaded function if it exist in the dll.
 *         - A pointer to the function badfunc if did not find it.
 */
void *
A4GL_find_func_double (void *v_dllhandle, char *func)
{
  double (*func_ptr) (void);
	lt_dlhandle handle;
	handle=v_dllhandle;
inc_usage(func);
  A4GL_debug
    ("find_func_double: Finding pointer to DLL function %s which returns a double\n",
     func);

  SPRINTF1 (tempbuff, "%s", func);


  if (handle == 0)
    {
      A4GL_debug ("Not found - bad handle");
      A4GL_exitwith ("Could not open share library");
      return (void *)badfunc;
    }


  A4GL_debug("Finding %s in %p",tempbuff,handle);
  func_ptr = lt_dlsym (handle, tempbuff);

  A4GL_debug ("Got %p", func_ptr);
  if (func_ptr == NULL)
    {
      A4GL_debug ("Function Not found");
      A4GL_exitwith ("Could not find function in shared library");
      return (void *)badfunc;
    }
  return (void *)func_ptr;
}

/**
 *
 * @todo Describe function
 */
void *
A4GL_find_func_allow_missing (void *v_dllhandle, char *func)
{
  int (*func_ptr) (void);
	lt_dlhandle handle;
	handle=v_dllhandle;

  inc_usage(func);
  strcpy(tempbuff,func);

  A4GL_debug ("find_func_allow_missing: Finding pointer to DLL function %s\n",
	 A4GL_null_as_null(func));


  if (handle == 0)
    {
      /*  A4GL_exitwith ("2: Non-existing function (%s) called in DLL",func); */
      return (void *)&badfunc;
    }
  A4GL_debug("Finding %s in %p",tempbuff,handle);
  func_ptr = lt_dlsym (handle, tempbuff);

  if ((void *)func_ptr == (void *)0) {
	  A4GL_debug("Not found - but I don't care");
    return (void *)&A4GL_nullfunc;
    }
  A4GL_debug("Found !");
  return (void *)func_ptr;
}


/**
 * Loading of 4gl dll for UNIX systems.
 * Called from 4gl code
 *
 * @param filename The dynamic library file name.
 * @param function The function name.
 * @param args The arguments ???
 */
int
A4GL_call_4gl_dll (char *filename, char *function, int args)
{
  //char buff[512];
  char nfunc[256];
  char nfile[256];
  int (*func_ptr) (int);
  int a;
  lt_dlhandle handle;


  A4GL_debug("Call 4gl dll : %s %s %d",filename,function,args);

  A4GLSQL_set_status (0, 0);
  strcpy (nfile, filename);

  if (strncmp(nfile,"a4gl_",5)==0) { /* Do upshift on A4GL */
	nfile[0]='A';
	nfile[1]='4';
	nfile[2]='G';
	nfile[3]='L';
  }
A4GL_debug("nfile=%s\n",A4GL_null_as_null(nfile));

strcpy(nfunc,"");
if (strncmp(function,"aclfglclass",11)!=0)  {
  strcpy (nfunc, "aclfgl_");
}

  strcat (nfunc, function);
  A4GL_trim (nfunc);
  A4GL_trim (nfile);
  A4GL_debug ("Calling %s in file %s with %d args", A4GL_null_as_null(nfunc), A4GL_null_as_null(nfile), args);

  A4GL_debug ("Trying %s", A4GL_null_as_null(filename));

  handle = lt_dlopen (filename);

  if (handle == 0)
    {
      A4GL_debug ("No library handle");
      A4GL_exitwith ("Unable to load shared library file");
      return -1;
    }

  A4GL_debug("Finding %s in %p",nfunc,handle);
  func_ptr = lt_dlsym (handle, nfunc);

  if (func_ptr == NULL)
    {
      A4GL_debug ("No function handle");
      A4GL_exitwith ("Unable to load function from shared libary");
      return -1;
    }

  A4GL_debug ("Calling function");
  a = func_ptr (args);
  return a;

}



/**
 * Loading of 4gl dll for UNIX systems.
 * Called from 4gl code
 *
 * @param filename The dynamic library file name.
 * @param function The function name.
 * @param args The arguments ???
 */
int
A4GL_call_4gl_dll_bound (char *filename, char *function, int ni,struct BINDING *ibind,int no,struct BINDING *obind)
{
  lt_dlhandle handle;
  //char buff[512];
  char nfunc[256];
  char nfile[256];
  int (*func_ptr_b) (int,void*,int,void*);
  int a;
  A4GL_debug("Call 4gl dll bound : %s %s %d %d",filename,function,ni,no);

  A4GLSQL_set_status (0, 0);
  strcpy (nfile, filename);

  if (strncmp(nfile,"a4gl_",5)==0) { /* Do upshift on A4GL */
	nfile[0]='A';
	nfile[1]='4';
	nfile[2]='G';
	nfile[3]='L';
  }
A4GL_debug("nfile=%s\n",A4GL_null_as_null(nfile));

strcpy(nfunc,"");
if (strncmp(function,"aclfglclass",11)!=0)  {
  strcpy (nfunc, "aclfgl_");
}
  strcat (nfunc, function);
  A4GL_trim (nfunc);
  A4GL_trim (nfile);

  A4GL_debug ("Trying %s", A4GL_null_as_null(filename));
  handle = lt_dlopenext (filename);


  if (handle == 0)
    {
      A4GL_debug ("No library handle");
      A4GL_exitwith ("Unable to load shared library file");
      return -1;
    }

  A4GL_debug("Finding %s in %p",nfunc,handle);
  func_ptr_b = lt_dlsym (handle, nfunc);

  if (func_ptr_b == NULL)
    {
      A4GL_debug ("No function handle");
      A4GL_exitwith ("Unable to load function from shared libary");
      return -1;
    }

  A4GL_debug ("Calling function");
  a = func_ptr_b (ni,ibind,no,obind);
  return a;

}




#define TRACE_DLL_CALLS
void inc_usage (char *s) {
static FILE *usg=0;
#ifdef TRACE_DLL_CALLS
if (A4GL_isyes(acl_getenv("TRACEDLL"))) {
	if (usg==0) {
		usg=fopen("trace.txt","w");
	}

	if (usg!=0) {
		FPRINTF(usg,"%s\n",s);
	}
}
#endif
}


/* ============================= EOF ================================== */
