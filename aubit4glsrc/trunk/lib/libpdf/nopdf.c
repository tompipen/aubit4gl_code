/**
 * @file
 * PDF Report Implementation functions used in absence of PDF libraries on system.
 *
 * @todo Add Doxygen comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */
/******************************************************************************
* (c) 1997-1998 Aubit Computing Ltd.
*
*
*******************************************************************************/
#include <stdio.h>


//#if (defined(WIN32) || defined(__CYWIN__)) && defined DLL_EXPORT
#if (defined(WIN32) && ! defined(__CYGWIN__))
	#include <windows.h>
	int WINAPI

	libPDF_NOPDF_init(HANDLE h, DWORD reason, void *foo)
	{
	  return 1;
	}


	char
	libPDF_NOPDF_is_dll (void)
	{
	  return 1;
	}
#endif /* WIN32 && DLL_EXPORT */

/*
    man dlltool :

   The  first  file  is  a  .def  file  which specifies which
   functions are exported from the DLL, which  functions  the
   DLL  imports,  and  so on.  This is a text file and can be
   created by hand, or dlltool can be used to create it using
   the  -z option.  In this case dlltool will scan the object
   files specified on its  command  line  looking  for  those
   functions  which  have  been  specially  marked  as  being
   exported and put entries for them  in  the  .def  file  it
   creates.

   In  order to mark a function as being exported from a DLL,
   it needs to have an  -export:<name_of_function>  entry  in
   the .drectve section of the object file.  This can be done
   in C by using the asm() operator:

             asm (".section .drectve");
             asm (".ascii \"-export:my_func\"");

             int my_func (void) { ... }



*/

extern void A4GLPDF_initlib (void);

void A4GLPDF_initlib () {
	/* Does nothing */
}
