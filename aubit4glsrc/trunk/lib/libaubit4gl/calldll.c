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
# $Id: calldll.c,v 1.2 2002-04-24 07:45:59 afalout Exp $
#
*/

/**
 * @file
 * Implementation of dll calling mechanism
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 */
#include "a4gl_debug.h"


  char tempbuff[1024];

/************************************************************************/
/* Under Cygwin, we can use the dl family of calls, but we need to jump */
/* through some hoops first. Specifically, we need to include           */
/* <cygwin/cygwin_dll.h> and we need to use the DECLARE_CYGWIN_DLL()    */
/* macro. During the link phase, we must use __cygwin_dll_entry@12 as   */
/* the entry point. See http://sources.redhat.com/cygwin/dl-docs.html. */
/* http://cygwin.com/faq/faq.html#SEC106 */
/* http://www.neuro.gatech.edu/users/cwilson/cygutils/V1.1/dll-stuff/   */
/************************************************************************/

#if defined(__CYGWIN__)

#include <cygwin/cygwin_dll.h>

// declaration macro: DECLARE_CYGWIN_DLL(<your entry point>);
//DECLARE_CYGWIN_DLL(dll_entry);

//In the link phase use "__cygwin_dll_entry@12" as entry point. Note that 
//you may have to perform 3 link passes.


/*
int WINAPI
dll_entry(
  HANDLE ,
  DWORD reason,
  void *)
{
  switch (reason)
  {
      case DLL_PROCESS_ATTACH: break;
      case DLL_PROCESS_DETACH: break;
      case DLL_THREAD_ATTACH:  break;
      case DLL_THREAD_DETACH:  break;
  }
  return 1;
}

*/

#endif /* defined(__CYGWIN__) */



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
call_4gl_dll (char *filename, char *function, int args)
{
  exitwith ("DLL functions not available yet for WIN32 platforms");
  return 0;
}

#else
/* implementation for UNIX and CygWin */

#include <dlfcn.h>

/**
 * When someone try to find a function that does not exist in the dll its
 * returned a pointer to this function.
 *
 * This way if someone try to call a non existent function the program stops.
 */
void badfunc (void)
{
//  exitwith ("No DLL Loaded");
  exitwith ("0: Non-existing function (%s) called in DLL\n",tempbuff);
}

int nullfunc(void) {
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
void *dl_openlibrary (char *type, char *name)
{
  void *dllhandle;
  char buff[1024];

#ifdef __CYGWIN__
  sprintf (buff, "%s/lib/lib%s_%s.dll", acl_getenv ("AUBITDIR"), type, name);
#else
  sprintf (buff, "%s/lib/lib%s_%s.so", acl_getenv ("AUBITDIR"), type, name);
#endif

  debug("Attempting to open shared library : '%s'",buff);


  dllhandle = dlopen (buff, RTLD_LAZY);
  if (dllhandle==0) {
//	 	printf("Opps 1 - can't open DLL - %s\n",dlerror());

  //FIXME: %s is not replaced with value of dllerror(), and in debug.out
  //all we will see is "Opps - can't open DLL - %s", which is less
  //then helpfull. Hmmm, it seems to be working now, or maybe sometimes
  //dlerror() returns empty string?


		debug("Opps - can't open DLL - %s",dlerror());

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
void *find_func (void *dllhandle, char *func)
{
  int (*func_ptr) ();
  debug("Finding pointer to DLL function %s\n",func);
  
 sprintf (tempbuff, "%s",func);

  if (dllhandle == 0)
  {
	debug("Not found - bad handle");
	exitwith("Could not open share library");
    	return badfunc;
  }
  func_ptr = dlsym (dllhandle, func);
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
 * Try to find a function in a dll loaded.
 *
 * @param dllhandle The dynamic library handler.
 * @param func The function name.
 * @return - A pointer to the loaded function if it exist in the dll.
 *         - A pointer to the function badfunc if did not find it.
 */
void *find_func_double (void *dllhandle, char *func)
{
  double (*func_ptr) ();
  debug("Finding pointer to DLL function %s which returns a double\n",func);
  
 sprintf (tempbuff, "%s",func);

  if (dllhandle == 0)
  {
	debug("Not found - bad handle");
	exitwith("Could not open share library");
    	return badfunc;
  }
  func_ptr = dlsym (dllhandle, func);
	debug("Got %p",func_ptr);
  if (func_ptr == 0)
  {
	debug("Function Not found");
	exitwith("Could not find function in shared library");
    	return badfunc;
  }
  return func_ptr;
}



void *find_func_allow_missing (void *dllhandle, char *func)
{
  int (*func_ptr) ();
  debug("Finding pointer to DLL function %s\n",func);
  
 sprintf (tempbuff, "%s",func);

  if (dllhandle == 0)
  {
//  exitwith ("2: Non-existing function (%s) called in DLL",func);
	return &badfunc;
  }
  func_ptr = dlsym (dllhandle, func);

  if (func_ptr==0) return &nullfunc;
  return func_ptr;
}


/**
 * Loading of 4gl dll for windows systems.
 *
 * @param filename The dynamic library file name.
 * @param function The function name.
 * @param args The arguments ???
 */
call_4gl_dll (char *filename, char *function, int args)
{
  void *dllhandle;
  char buff[512];
  char nfunc[256];
  char nfile[256];
  int (*func_ptr) (int);
  int a;
  A4GLSQL_set_status (0);
  strcpy (nfile, filename);
  strcpy (nfunc, "aclfgl_");
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
#endif
