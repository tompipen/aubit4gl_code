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
# $Id: calldll.c,v 1.29 2003-02-19 22:28:38 afalout Exp $
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
int 		nullfunc		(void);
int 			call_4gl_dll 	(char *filename, char *function, int args);
void *          find_func_double (void *dllhandle, char *func);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

#if defined(__MINGW32__)

/* ------------ this functions simulate dlopen interface on Windows ---- */


/* <Windows dlfcn.c> */
#include <windows.h>
#include <stdio.h>
/* #include <dlfcn.h> */
/* generic version of dlfcn.h */
#define RTLD_LAZY 1
#define RTLD_NOW  2

void *dlopen(const char *, int);
void *dlsym(void *, const char *);
int dlclose(void *);
char *dlerror(void);
/* end dlfcn.h */

static char errbuf[512];

/**
 * Windows dlopen wraper function.
 *
 * This function simulate the unix dlopen in order to
 * let aubit4gl work.
 *
 * @param name The name of the library to load.
 * @param mode Not used here.
 * @return 
 *   - A pointer to the lib handle 
 *   - NULL if it cant find it
 */
void *dlopen(const char *name, int mode)
{
  HINSTANCE hdll;

  hdll = LoadLibrary(name);
#ifdef _WIN32
  if (! hdll) {
    sprintf(errbuf, "error code %d loading library %s", GetLastError(), name);
    return NULL;
  }
#else
  if ((UINT) hdll < 32) {
    sprintf(errbuf, "error code %d loading library %s", (UINT) hdll, name);
    return NULL;
  }
#endif
  return (void *) hdll;
}

/**
 * Windows specific implementation.
 *
 * Get a pointer to a function loaded in a library
 *
 * @param lib The dll handle.
 * @param name The name of the function to be found.
 * @return A pointer to the function.
 */
void *dlsym(void *lib, const char *name)
{
  HMODULE hdll = (HMODULE) lib;
  void *symAddr;
  symAddr = (void *) GetProcAddress(hdll, name);
  if (symAddr == NULL)
    sprintf(errbuf, "can't find symbol %s", name);
  return symAddr;
}

int dlclose(void *lib)
{
  HMODULE hdll = (HMODULE) lib;

#ifdef _WIN32
  if (FreeLibrary(hdll))
    return 0;
  else {
    sprintf(errbuf, "error code %d closing library", GetLastError());
    return -1;
  }
#else
  FreeLibrary(hdll);
  return 0;
#endif
}

char *dlerror()
{
  return errbuf;
}

#endif /* __MINGW32__ */

/* ====================== end of dl fincs for windows =================== */

#if (defined(WIN32) && ! defined(__CYGWIN__) && ! defined(__MINGW32__))

/*
As per Microsoft's web site, an error value of zero specifies that the
system was out of memory, the file was corrupt, or the relocation data was
invalid.  Further digging through the web site lead me to believe that one
could emulate dlopen,sym,and close with loadlibrary, getprocaddress, and
freelibrary.
*/


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

/*

void *
find_func (void *dllhandle, char *func)
{
int (*func_ptr) (void);

  return func_ptr;
}

void *
find_func_allow_missing (void *dllhandle, char *func)
{
  int (*func_ptr) (void);
  return func_ptr;
}

void *
dl_openlibrary (char *type, char *name)
{
  void *dllhandle;
  return dllhandle;
}

*/

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
int
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
dl_openlibrary (char *type, char *p)
{
void *		dllhandle;
static char buff[1024];
char 		buff2[1024];
static char tmpbuff[1024];

  char *plugin_name;

  //need to hide this pointer, something in the way we read registry is messing it up! >>>>>>>>>STATIC!!!!!!<<<<<<<<<FIX IT!!!!!
  sprintf (tmpbuff, "%s",p);
  plugin_name = tmpbuff;


  if ( (! acl_getenv ("AUBITDIR")) || (strcmp (acl_getenv ("AUBITDIR"), "") == 0) ) {
	exitwith("Error: Cannot determine AUBITDIR - STOP.");
    //FIXME: why is exitwith not exiting???
    exit (43);
  }

	#ifdef __CYGWIN__
	  sprintf (buff, "%s/lib/lib%s_%s.dll", acl_getenv ("AUBITDIR"), type, plugin_name);
	#else
		#if defined(__DARWIN__)
		  sprintf (buff, "%s/lib/lib%s_%s.bundle", acl_getenv ("AUBITDIR"), type, plugin_name);

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
			#if defined(__MINGW32__)

//printf("Mingwin mode %s\n",acl_getenv("AUBITDIR"));
				//printf("dl_openlibrary received %s %s\n",type, plugin_name);
			//printf("1 plugin_name = %s\n",plugin_name);
				char *aubitdirptr;
			//printf("2 plugin_name = %s\n",plugin_name);
				aubitdirptr=acl_getenv("AUBITDIR");
				//sprintf (buff, "%s/lib/lib%s_%s.dll", acl_getenv ("AUBITDIR"), type, plugin_name);
			//printf("3 plugin_name = %s\n",plugin_name); // <<<<<<< FUCKED!!!!
				sprintf (buff2, "%s/lib/lib%s", aubitdirptr, type);
				//printf("buff2 = %s\n",buff2);
			//printf("4 plugin_name = %s\n",plugin_name);
				sprintf (buff, "%s_%s.dll", buff2, plugin_name);
				//printf("buff = %s\n",buff);
			#else
				/* all other platforms: */
				sprintf (buff, "%s/lib/lib%s_%s.so", acl_getenv ("AUBITDIR"), type, plugin_name);
            #endif
        #endif
	#endif

  #ifdef DEBUG
	  debug("Attempting to open shared library : '%s'",buff);
  #endif

  dllhandle = dlopen (buff, RTLD_LAZY);
  if (dllhandle==0) {

		/* Sometimes dlerror() returns empty string? */
		/* dllerror is nulled after first call - can't call it twice, so we
        have to store it to be able to use it twice */
		sprintf (buff2, "%s", dlerror());

		printf("Error: can't open DLL %s - STOP\n",buff);
		printf("Error msg: %s\n",buff2);

		debug("Error: can't open DLL %s - STOP\n",buff);
		debug("Error msg: %s\n",buff2);

		exitwith("Error: can't open DLL - STOP. See debug.out");
	    //FIXME: why is exitwith not exiting???
    	exit (44);

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
	// This is so critical - we're out of here...
	
	gotolinemode();
	printf("Critical error - Unable to find function %s in shared library\n",func);
	fgl_end();
	exit(1);
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

  if ( (! acl_getenv ("AUBITDIR")) || (strcmp (acl_getenv ("AUBITDIR"), "") == 0) ) {
		exitwith("Error: Cannot determine AUBITDIR - STOP.");
	    //FIXME: why is exitwith not exiting???
    	exit (43);

  }

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

