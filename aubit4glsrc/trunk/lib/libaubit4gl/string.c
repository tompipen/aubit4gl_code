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
# $Id: string.c,v 1.15 2003-04-07 07:12:22 afalout Exp $
#
*/

/**
 * @file
 * String utility functions.
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
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

/* #define DIGIT_ALIGN_LEFT */
//extern int errno;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


/*
=====================================================================
                    Functions definitions
=====================================================================
*/

int strnullcmp(char *s1,char *s2);



/**
 *
 * @todo Desctibe function
 */
void 
string_set(char *ptr,char *b,int size)
{
	strncpy(ptr,b,size);
        ptr[size]=0; /* MJA 16.08.2001 */
	pad_string(ptr,size);
	debug("..");
	debug("ptr=%p\n",ptr);
}


/**
 * Allocate space for a new string.
 *
 * @param a The size of the string to be created.
 * @return A pointer to the string created.
 */
char *
new_string(int a)
{
char *ptr;
	debug("In new_string %d\n",a);
	ptr=(char *)acl_malloc(a+1,"New string"); /* 1 for NULL */
	debug("Aclmalloc returns %p",ptr);
	return ptr;
}


/**
 * Create a new string set.
 *
 * @param a The size of the string to be created.
 * @param b
 * @return A pointer to the string created.
 */
char *
new_string_set(int a,char *b)
{
	char *ptr;
	debug("new_string_set 0 a=%d",a);
	ptr=new_string(a);
	debug("new_string_set 1");
	string_set(ptr,b,a);
	debug("new_string_set 2");
	#ifdef DEBUG
		{debug("added : '%s' ",ptr);}
	#endif
	debug("new_string_set 3");
	return ptr;
}


/**
 *
 * @todo Describe function
 */
void
modify_size(char *z,int a)
{
char *zzz;
	#ifdef DEBUG
		debug("Modify size has been called !");
	#endif
	zzz=z-sizeof(int);
	*(int *)zzz=a;
}



#if (defined(WIN32) && ! defined(__CYGWIN__) && ! defined(__MINGW32__))
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
int
strncasecmp(char *a,char *b,int c)
{
	return strnicmp(a,b,c);
}
#endif


/**
 *
 * @todo Describe function
 */
int
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
    b = n;                   /* compare only the first n, except where n=0 */
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


int
strnullcmp(char *s1,char *s2)
{
        if (s1==0) return -1;
        if (s2==0) return -1;
        return strcmp(s1,s2);
}

/* =================================== EOF ============================ */

