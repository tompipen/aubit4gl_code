/**
 * @file
 * String utility functions.
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

/*  ***************************************************************************
* (c) 1997-1998 Aubit Computing Ltd.
*
* $Id: string.c,v 1.1 2002-04-17 00:01:36 afalout Exp $
*
* Project : Part Of Aubit 4GL Library Functions
*
* Change History :
*	$Log: not supported by cvs2svn $
*	Revision 1.4  2002/03/01 07:41:45  mikeaubury
*	DL UI
*	
*	Revision 1.3  2002/02/22 22:50:58  saferreira
*	Comments and prototypes.
*	
*	Revision 1.2  2001/11/29 22:27:00  saferreira
*	Some more warnings fixed and Doxygen comments added
*	
*	Revision 1.1.1.1  2001/08/20 02:36:41  afalout
*	Initial import to SF
*	
*	Revision 1.6  2001/08/17 08:59:26  maubury
*	gtk updates
*	
*	Revision 1.5  2001/08/13 01:07:06  afalout
*	CygWin merge
*	
*	Revision 1.4  2001/06/12 03:37:33  afalout
*	make install, make clean
*	
*	Revision 1.3  2001/06/04 11:48:46  maubury
*	Try 3
*	
*	Revision 1.2  2000/09/28 02:42:23  afalout
*	*** empty log message ***
*	
*	Revision 1.1.1.1  2000/01/29 03:11:52  cvs
*	Initial import of compiler sources using jCVS client
*	
*	Revision 1.3  1998/12/17 20:59:02  fglcomp
*	171298
*
*	Revision 1.2  1998/08/09 11:51:48  fglcomp
*	Added ID classifications
*
*
*******************************************************************************/

#include <math.h> 
#include "../libincl/dbform.h"
#include "../libincl/dates.h"
#include "../libincl/constats.h"
#include "../libincl/stack.h"
#include "../libincl/dtypes.h"
#include "../libincl/debug.h"
extern int errno;
#include <sys/types.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <unistd.h>
//#include <pwd.h>
#include <locale.h>
/* #define DIGIT_ALIGN_LEFT */
#include <time.h>


void string_set(char *ptr,char *b,int size)
{
	strncpy(ptr,b,size);
        ptr[size]=0; // MJA 16.08.2001
	pad_string(ptr,size);
#ifdef DEBUG
/*  {        debug("string_set to : '%s' ",ptr);  } */

#endif
}


/**
 * Allocate space for a new string.
 *
 * @param a The size of the string to be created.
 * @return A pointer to the string created.
 */
char *new_string(int a) 
{
	char *ptr;
	char *ptr2;
	ptr=(char *)acl_malloc(a+1,"New string"); /* 1 for NULL */
	return ptr; 
}


/**
 * Create a new string set.
 *
 * @param a The size of the string to be created.
 * @param b
 * @return A pointer to the string created.
 */
char *new_string_set(int a,char *b)
{
	char *ptr;
	ptr=new_string(a);
	string_set(ptr,b,a);
#ifdef DEBUG
/* {DEBUG} */ {        debug("added : '%s' ",ptr);
}
#endif
	return ptr;
}


void modify_size(char *z,int a) {
char *zzz;
#ifdef DEBUG
/* {DEBUG} */ {debug("Modify size has been called !");
}
#endif
zzz=z-sizeof(int);
*(int *)zzz=a;
}




#ifdef WIN32
#ifndef __CYGWIN__
/**
 * Windows implementation of strncasecmp().
 * 
 * @param a A string to be compared.
 * @param b A string to be compared.
 * @param c The number of characters to be compared.
 * @return
 *   - 0 : The strings are equal.
 *   - Otherwise : They are not equal.
 */
strncasecmp(char *a,char *b,int c) {
	return strnicmp(a,b,c);
}
#endif
#endif



mja_strncmp (char *str1, char *str2, int n)
{
  int a, b;
  int len1, len2;
  char c1, c2;
  len1 = strlen (str1);
  len2 = strlen (str2);
  if (len1 > len2)
    b = len1;
  else
    b = len2;
  if (b > n && n != 0)
    b = n;                      /* compare only the first n, except where n=0 */
  for (a = 0; a < b; a++)
    {
      c1 = toupper (str1[a]);
      c2 = toupper (str2[a]);
      if (c1 < c2)
        return -1;
      if (c1 > c2)
        return 1;
    }
  return 0;
}
