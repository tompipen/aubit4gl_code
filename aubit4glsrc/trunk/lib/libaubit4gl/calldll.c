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
# $Id: calldll.c,v 1.19 2002-10-07 11:06:25 afalout Exp $
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

/*
 **********************************************************************
 * Under Cygwin, we can use the dl family of calls, but we need to jump
 * through some hoops first. Specifically, we need to include
 * <cygwin/cygwin_dll.h> and we need to use the DECLARE_CYGWIN_DLL()
 * macro. During the link phase, we must use __cygwin_dll_entry@12 as
 * the entry point. See http://sources.redhat.com/cygwin/dl-docs.html.
 * http://cygwin.com/faq/faq.html#SEC106
 * http://www.neuro.gatech.edu/users/cwilson/cygutils/V1.1/dll-stuff/
 ***********************************************************************
 */
#if defined(__CYGWIN__)
/*
//    #define BYTE int
	typedef unsigned char BYTE;
    #define BOOLEAN int
//    typedef BYTE BOOLEAN,*PBOOLEAN;
//    typedef BYTE BOOLEAN,*PBOOLEAN;

//	#include <cygwin/cygwin_dll.h>
*/
#endif

#ifndef WIN32
	#include <dlfcn.h>
#endif

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

char tempbuff[1024];

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

static void 	badfunc 		(void);
static int 		nullfunc		(void);
int 			call_4gl_dll 	(char *filename, char *function, int args);
void *          find_func_double (void *dllhandle, char *func);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

#if (defined(WIN32) && ! defined(__CYGWIN__))

/**
 * Loading of 4gl dll for native windows post. CygWin uses same
 * code as UNIX, since it implements dlopen() as warper for Windows native
 * dll loader.
 *
 * Not yet implemented.
 *
 * @param filename
 * @param function
 * @param args
 */
int
call_4gl_dll (char *filename, char *function, int args)
{
  exitwith ("DLL functions not available yet for WIN32 platforms");
  return 0;
}

#else
	/* implementation for UNIX and CygWin */



/**
 * When someone try to find a function that does not exist in the dll its
 * returned a pointer to this function.
 *
 * This way if someone try to call a non existent function the program stops.
 */
static void
badfunc (void)
{
	/* exitwith ("No DLL Loaded"); */
  exitwith ("0: Non-existing function called in DLL\n");
}

/**
 *
 * @todo Describe function
 */
static int
nullfunc(void)
{
	debug("Calling DLL where no function defined (Allowed)");
	return 1;
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
 * @param type The type of the library to open.
 * @param name The name of the library to open.
 * @return A pointer to the dynamic library handle.
 */
void *
dl_openlibrary (char *type, char *name)
{
  void *dllhandle;
  char buff[1024];

	#ifdef __CYGWIN__
	  sprintf (buff, "%s/lib/lib%s_%s.dll", acl_getenv ("AUBITDIR"), type, name);
	#else
		#if (defined(__MACH__) && defined(__APPLE__))
		  sprintf (buff, "%s/lib/lib%s_%s.bundle", acl_getenv ("AUBITDIR"), type, name);

          /*
	        void *handle;
	        void (*hw)(void);
	        void (*hh)(void);
	        printf("Loading \"libhello.dylib\" .....\n");
	        handle = dlopen("/Users/fujiik/sandbox/mypkg/src/libdl/test/libhello.dylib",RTLD_LAZY);

	        hw = dlsym(handle,"_helloworld");
	        (*hw)();
	        hh = dlsym(handle,"_hellohoge");
	        (*hh)();

	        dlclose(handle);

        */


        #else
		  sprintf (buff, "%s/lib/lib%s_%s.so", acl_getenv ("AUBITDIR"), type, name);
        #endif
	#endif

  debug("Attempting to open shared library : '%s'",buff);

  dllhandle = dlopen (buff, RTLD_LAZY);
  if (dllhandle==0) {

		/* Sometimes dlerror() returns empty string? */
		debug("Error: can't open DLL %s - %s - STOP",buff,dlerror());
		exitwith("Error: can't open DLL - STOP. See debug.out");

  }
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
find_func (void *dllhandle, char *func)
{
int (*func_ptr) (void);

/*
 FIXME:
 We should be using system independent dlopen wrapper provided by
 libtool 1.4, which is fully integrated with Autoconf/Automake, and did I say,
 platform independent?
 see $AUBITDIR/libltdl/ltdl.c
*/


	#if (defined(__MACH__) && defined(__APPLE__))
		sprintf (tempbuff, "_%s",func);
	#else
		sprintf (tempbuff, "%s",func);
	#endif

  debug("find_func: Finding pointer to DLL function %s\n",tempbuff);

  if (dllhandle == 0)
  {
	debug("Not found - bad handle");
	exitwith("Could not open shared library");
    	/* return badfunc; */
  }
  func_ptr = dlsym (dllhandle, tempbuff);
	debug("Got %p",func_ptr);
  if (func_ptr == 0)
  {
	debug("Function Not found");
	exitwith("Could not find function in shared library");
		/* return badfunc; */
  }

	/*  debug("calldll.c: before return func=%s\n",func); */

  return func_ptr;
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
find_func_double (void *dllhandle, char *func)
{
  double (*func_ptr) (void);
  debug("find_func_double: Finding pointer to DLL function %s which returns a double\n",func);

	#if (defined(__MACH__) && defined(__APPLE__))
		sprintf (tempbuff, "_%s",func);
	#else
		sprintf (tempbuff, "%s",func);
	#endif


  if (dllhandle == 0)
  {
	debug("Not found - bad handle");
	exitwith("Could not open share library");
    	return badfunc;
  }
  func_ptr = dlsym (dllhandle, tempbuff);
	debug("Got %p",func_ptr);
  if (func_ptr == 0)
  {
	debug("Function Not found");
	exitwith("Could not find function in shared library");
    	return badfunc;
  }
  return func_ptr;
}

/**
 *
 * @todo Describe function
 */
void *
find_func_allow_missing (void *dllhandle, char *func)
{
  int (*func_ptr) (void);
  debug("find_func_allow_missing: Finding pointer to DLL function %s\n",func);
  
 	#if (defined(__MACH__) && defined(__APPLE__))
		sprintf (tempbuff, "_%s",func);
	#else
		sprintf (tempbuff, "%s",func);
	#endif


  if (dllhandle == 0)
  {
	/*  exitwith ("2: Non-existing function (%s) called in DLL",func); */
	return &badfunc;
  }
  func_ptr = dlsym (dllhandle, tempbuff);

  if (func_ptr==0) return &nullfunc;
  return func_ptr;
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
call_4gl_dll (char *filename, char *function, int args)
{
void *dllhandle;
char buff[512];
char nfunc[256];
char nfile[256];
int (*func_ptr) (int);
int a;
  
  A4GLSQL_set_status (0,0);
  strcpy (nfile, filename);
  
	#if (defined(__MACH__) && defined(__APPLE__))
		strcpy (nfunc, "aclfgl__");
	#else
		strcpy (nfunc, "aclfgl_");
	#endif

  strcat (nfunc, function);
  trim (nfunc);
  trim (nfile);
  debug ("Calling %s in file %s with %d args", nfunc, nfile, args);

	debug("Trying %s",filename);
  dllhandle = dlopen (filename, RTLD_LAZY);
	if (dllhandle==0) debug("Opps - can't open DLL - %s",dlerror());

  if (dllhandle == 0)
    {
    sprintf (buff, "%s/lib/lib%s.so", acl_getenv ("AUBITDIR"),filename);
	debug("Trying %s",buff);
    dllhandle = dlopen (buff, RTLD_LAZY);
	if (dllhandle==0) debug("Opps - can't open DLL - %s",dlerror());
    }

  if (dllhandle == 0)
    {
    sprintf (buff, "./lib%s.so",  filename);
	debug("Trying %s",buff);
    dllhandle = dlopen (buff, RTLD_LAZY);
	if (dllhandle==0) debug("Opps - can't open DLL - %s",dlerror());
    }

  if (dllhandle == 0)
    {
    sprintf (buff, "./%s.so", filename);
	debug("Trying %s",buff);
    dllhandle = dlopen (buff, RTLD_LAZY);
	if (dllhandle==0) debug("Opps - can't open DLL - %s",dlerror());
    }



  if (dllhandle == 0)
    {
      debug ("No library handle");
      exitwith ("Unable to load shared library file");
      return 0;
    }

  func_ptr = dlsym (dllhandle, nfunc);

  if (func_ptr == 0)
    {
      debug ("No function handle");
      exitwith ("Unable to load function from shared libary");
      return 0;
    }

  debug ("Calling function");
  a = func_ptr (args);
  debug ("Closing handle");
  dlclose (dllhandle);
  return a;

}
#endif /* #if (defined(WIN32) && ! defined(__CYGWIN__)) */


/* ============================= EOF ================================== */

