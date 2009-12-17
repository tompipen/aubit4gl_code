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
# $Id: string.c,v 1.34 2009-12-17 17:36:11 mikeaubury Exp $
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
#include <ctype.h>


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

int A4GL_strnullcmp (char *s1, char *s2);



/**
 *
 * @todo Desctibe function
 */
void
A4GL_string_set (char *ptr, char *b, int size)
{
  static char buff[50000];

  A4GL_assertion (b == 0, "No source string");
  A4GL_assertion (ptr == 0, "No destination string");
  A4GL_assertion (size < 0, "Invalid size");

  if (size == 0)
    {
      strcpy (ptr, b);
      return;
    }
  if (size > 50000)
    {
      A4GL_assertion (1, "Buff not big enough in string_set");
    }
  memset (&buff[0], 0, size);
  strncpy (buff, b, size);
  strncpy (ptr, buff, size);
  ptr[size] = 0;		/* MJA 16.08.2001 */
  A4GL_pad_string (ptr, size);
  ////A4GL_debug ("..");
  //A4GL_debug ("ptr=%p\n", ptr);
}


/**
 * Allocate space for a new string.
 *
 * @param a The size of the string to be created.
 * @return A pointer to the string created.
 */
char *
A4GL_new_string (int a)
{
  char *ptr;
  //A4GL_debug ("In A4GL_new_string %d (%x)\n", a,a);
  if (a > 65000)
    {
      A4GL_exitwith ("Dubious string size");
      return "";
    }
  ptr = (char *) acl_malloc (a + 2, "New string");	/* 1 for NULL 1 for extra */
  memset (ptr, 0, a + 2);
  //A4GL_debug ("Aclmalloc returns %p", ptr);
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
A4GL_new_string_set (int a, char *b)
{
  char *ptr;
  //A4GL_debug ("new_string_set 0 a=%d", a);
  ptr = A4GL_new_string (a);
  //A4GL_debug ("new_string_set 1");
  A4GL_string_set (ptr, b, a);
  //A4GL_debug ("new_string_set 2");
#ifdef DEBUG
  {
    //A4GL_debug ("added : '%s' ", ptr);
  }
#endif
  //A4GL_debug ("new_string_set 3");
  return ptr;
}


/**
 *
 * @todo Describe function
 */
void
A4GL_modify_size (char *z, int a)
{
  char *zzz;
#ifdef DEBUG
  //A4GL_debug ("Modify size has been called !");
#endif
  zzz = z - sizeof (int);
  *(int *) zzz = a;
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
strncasecmp (char *a, char *b, int c)
{
  return strnicmp (a, b, c);
}
#endif


/**
 *
 * @todo Describe function
 */
int
A4GL_mja_strncmp (char *str1, char *str2, int n)
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
    b = n;			/* compare only the first n, except where n=0 */
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
A4GL_strnullcmp (char *s1, char *s2)
{
  if (s1 == 0)
    return -1;
  if (s2 == 0)
    return -1;
  return strcmp (s1, s2);
}






static void
insert_character (char *string, int pos, char c)
{
  char *buff;
  char smbuff[2];
  buff = malloc (strlen (string) + 2);

  if (pos > 0)
    {
      strncpy (buff, string, pos);
      buff[pos] = 0;
    }
  else
    {
      strcpy (buff, "");
    }
  smbuff[0] = c;
  smbuff[1] = 0;
  strcat (buff, smbuff);
  strcat (buff, &string[pos]);
  strcpy (string, buff);
  free (buff);
}


int
A4GL_wordwrap_text (char *in, char *out, int width, int maxsize)
{
  char buff[10000];
//int lines=0;
  int cnt;

  cnt = width;
  memset(buff,0,sizeof(buff));
  strcpy (buff, in);
  A4GL_trim (buff);




  while (cnt < strlen (buff))
    {
      int a;
      int have_blanked = 0;
      if (buff[cnt - 1] == ' ' || buff[cnt] == ' ')
	{
	  cnt += width;
		continue;
	}
      // Need to pad out...
      for (a = 1; a < width; a++)
	{
	  if (A4GL_isblank (buff[cnt - a - 1]))
	    {
	      int b;
	      for (b = 0; b < a; b++)
		{
		  insert_character (buff, cnt - a - 1, ' ');

		}
	      have_blanked++;
	      break;
	    }
	}
      if (!have_blanked)
	{
	  break;
	}
	printf("Buff=%s\n",buff);
      cnt += width;
    }
  A4GL_trim (buff);
  if (strlen (buff) > maxsize)
    {
      A4GL_debug ("Too large to fit... %s (%d) %d", buff, strlen (buff), maxsize);
      strcpy (out, in);
      return 0;			// We're too long to fit...
    }

  A4GL_debug ("fits %s", buff);
  strcpy (out, buff);
  return 1;
}

/* ============================= EOF ================================ */
