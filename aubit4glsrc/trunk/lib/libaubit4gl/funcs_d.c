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
# $Id: funcs_d.c,v 1.27 2004-02-10 13:50:20 mikeaubury Exp $
#
*/

/**
 * @file
 * Some functions, like using.
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

struct expr_str
{
  char *expr;
  struct expr_str *next;
};

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

//extern int errno;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

int A4GL_bname2 (char *str, char *str1, char *str2, char *str3);
void A4GL_trim_nl (char *p);

void * A4GL_new_expr (char *value);
void * A4GL_append_expr (struct expr_str *orig_ptr, char *value);
/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Another implementation of basename.
 *
 * @param str
 * @param str1
 * @param str2
 * @param str3
 */
int
A4GL_bname2 (char *str, char *str1, char *str2, char *str3)
{
  char ss[256];
  char b1[10];
  char b2[10];
  char b3[10];

  if (!strchr (str, '/'))
    {
      return 0;
    }

#ifdef DEBUG
  {
    A4GL_debug ("%p %p %p %p", str, str1, str2, str3);
  }
#endif
#ifdef DEBUG
  {
    A4GL_debug ("(1)%s %s %s", str1, str2, str3);
  }
#endif
  strcpy (ss, str);
#ifdef DEBUG
  {
    A4GL_debug ("(1.1)%s %s %s", str1, str2, str3);
  }
#endif
#ifdef DEBUG
  {
    A4GL_debug ("In A4GL_bname2 %s");
  }
#endif
  A4GL_trim (ss);
#ifdef DEBUG
  {
    A4GL_debug ("(2)%s %s %s", str1, str2, str3);
  }
#endif
  A4GL_bnamexxx (ss, b2, b3);
#ifdef DEBUG
  {
    A4GL_debug ("(1) Splits to %s %s", b2, b3);
  }
#endif
#ifdef DEBUG
  {
    A4GL_debug ("(3)%s %s %s", str1, str2, str3);
  }
#endif
  strcpy (ss, b2);
  A4GL_bnamexxx (ss, b1, b2);
#ifdef DEBUG
  {
    A4GL_debug ("(2) Splits to '%s' '%s'", b1, b2);
  }
#endif
#ifdef DEBUG
  {
    A4GL_debug ("(4)%s %s %s", str1, str2, str3);
  }
#endif
#ifdef DEBUG
  {
    A4GL_debug ("'%s' '%s' '%s'", b1, b2, b3);
  }
#endif
#ifdef DEBUG
  {
    A4GL_debug ("%s %s %s", str1, str2, str3);
  }
#endif
  strcpy (str1, b1);
#ifdef DEBUG
  {
    A4GL_debug ("1");
  }
#endif
  strcpy (str2, b2);
#ifdef DEBUG
  {
    A4GL_debug ("1");
  }
#endif
  strcpy (str3, b3);
#ifdef DEBUG
  {
    A4GL_debug ("Copied...");
  }
#endif
  return 1;
}


/**
 * Aubit compiler malloc.
 *
 * It was used to make some A4GL_debug about memory allocations.
 * Right now just encapsulate standard C malloc.
 *
 * @param size The size in bytes to be allocated
 * @param why The reason for memory allocation
 * @param f The source file name where the memory is being alocated
 * @pram line The source file line number where memory being alocated
 * @return A pointer for the memory alocated
 */
void *
acl_malloc_full (int size, char *why, char *f, long line)
{
  void *p;
  //A4GL_debug ("About to alloc %d bytes", size);
  p = malloc (size);
  //A4GL_debug ("alloced");
  return p;
}

/**
 *
 *
 * @param
 */
void
acl_free_full (void *ptr, char *f, long line)
{
  free (ptr);
}

/**
 * Trim the spaces at the rigth side of a string
 *
 * @param p The string to be trimmed.
 */
void
A4GL_trim (char *p)
{
  int a;
  for (a = strlen (p) - 1; a >= 0; a--)
    {
      if (p[a] != ' ' && p[a] != '\t' && p[a] != '\n' && p[a] != '\r')
	break;
      p[a] = 0;
    }
}

/**
 * Trim the spaces and new lines at the rigth side of a string.
 *
 * @param p The string to be trimmed.
 */
void
A4GL_trim_nl (char *p)
{
  int a;
  for (a = strlen (p) - 1; a >= 0; a--)
    {
      if (p[a] != ' ' && p[a] != '\n' && p[a] != '\r' && p[a] != '\t')
	break;
      p[a] = 0;
    }
}


/**
 * Yet another implementation of basename.
 *
 * @param str
 * @param str1
 * @param str2
 */
void
A4GL_bnamexxx (char *str, char *str1, char *str2)
{
  static char fn[132];
  int a;
  char *ptr;

  strcpy (fn, str);
#ifdef DEBUG
  {
    A4GL_debug ("In A4GL_bnamexxx - splitting %s", str);
  }
#endif
  for (a = strlen (fn); a >= 0; a--)
    {
      if (A4GL_date_sep (fn[a]))
	{
#ifdef DEBUG
	  {
	    A4GL_debug ("separator found at %d", a);
	  }
#endif
	  fn[a] = 0;
	  break;
	}
    }
#ifdef DEBUG
  {
    A4GL_debug ("a=%d", a);
  }
#endif
  ptr = &fn[a];
#ifdef DEBUG
  {
    A4GL_debug ("ptr=%p", ptr);
  }
#endif
  strcpy (str1, fn);
#ifdef DEBUG
  {
    A4GL_debug ("Str1 now = '%s'", str1);
  }
#endif
  if (a >= 0)
    strcpy (str2, ptr + 1);
  else
    str2[0] = 0;
#ifdef DEBUG
  {
    A4GL_debug ("Str2='%s'", str2);
  }
#endif
}

/**
 * Pad a string with spaces until the string reaches a size.
 *
 * @param ptr A pointer to the string being padded.
 * @param The size of the string.
 */
void
A4GL_pad_string (char *ptr, int size)
{
  int a;
  for (a = strlen (ptr); a < size; a++)
    {
      ptr[a] = ' ';
    }
  ptr[size] = 0;
}


/**
 * Convert a digit to 
 *
 * @param a
 * @param z
 * @param fmt
 * @param dtype
 * @param size
 * @param buff
 * @return Allways 1.
 */
int
A4GL_digittoc (int *a, char *z, char *fmt, int dtype, int size)
{
  static char buff[100];



#ifdef DEBUG
  {
    A4GL_debug ("digittoc %d",*a);
  }
#endif
  sprintf (buff, fmt, *a);

#ifdef DEBUG
  {
    A4GL_debug ("digittoc: %s", buff);
  }
#endif



#define DIGIT_ALIGN_LEFT

#ifdef DIGIT_ALIGN_LEFT
  sprintf (buff, "%%-%d%s", size, fmt);
#else
  sprintf (buff, "%%%d%s", size, fmt);
#endif

/*
	if (strlen(buff)>size) {
		memset(z,'*',size);
		pad_string(z,size);
		return 0;
	}
*/


//printf("Format = %s\n",buff);fflush(stdout);

#ifdef DEBUG
  {
    A4GL_debug ("digittoc: buff set to %s", buff);
  }
#endif
  strcpy (fmt, buff);
#ifdef DEBUG
  {
    A4GL_debug ("digittoc: returns");
  }
#endif
  return 1;
}

/**
 * USING 4gl statement implementation.
 *
 * @param str The string where to return the values.
 * @param s   Max. length of string
 * @param fmt The string that contains the format pattern.
 * @param num The (double-float) number to be formated.
 */
void
a4gl_using (char *str, int s, char *fmt, double num)
{
  int dig[MAXDIG];
  int pnt[MAXPNT];
  char number[65];
  char fm1[64], fm2[64];
  char *ptr1, *ptr;
  char *ptr2;
  char *p;
  char canfloat_head[] = "*-+($";
  char rep_digit[] = "*&#<-+()$";
  char buff[800];
  int isneg = 0;
  int a, b;
  int isprnt = 0;
  double ad;

  A4GL_debug ("In using... fmt=%s, num=%lf", fmt, num);
  for (a = 0; a < MAXPNT; a++)
    {
      pnt[a] = 0;
    }
  for (a = 0; a < MAXDIG; a++)
    {
      dig[a] = 0;
    }

  ptr1 = &number[0];
  ptr2 = &number[32];

  if (num < 0)
    {
      isneg = 1;
      num = 0.0 - num;
    }

#if defined (__MINGW32__)
  if (strchr (fmt, '.'))
    {
#else
  if (index (fmt, '.'))
    {
#endif
      strcpy (fm1, fmt);
#if defined (__MINGW32__)
      p = (char *) strchr (fm1, '.');
#else
      p = (char *) index (fm1, '.');
#endif
      p[0] = 0;
#if defined (__MINGW32__)
      strcpy (fm2, strchr (fmt, '.') + 1);
#else
      strcpy (fm2, index (fmt, '.') + 1);
#endif
    }
  else
    {
      strcpy (fm1, fmt);
      strcpy (fm2, "");
    }
  ad = 0.5;
  A4GL_trim (fm2);

  for (a = 1; a <= strlen (fm2); a++)
    {
      ad = ad / 10;
    }
  num += ad;
  sprintf (number, "%64.32f", num);
  number[31] = 0;
  strcpy (str, fmt);
  b = 30;
  isprnt = 1;

  // first, ensure the format string is wide enough to hold the number
  // if not, try drop trailing decimals, otherwise flag overflow with *'s
  {
    int f_cnt = 0;		// number of digits to left of dec. point in format
    int d_cnt = 0;		// number of digits to right of dec. point
    int n_cnt = isneg;		// number of left-digits needed for number supplied
    // count format string number place holders, up to decimal point
    for (a = 0; a < strlen (fmt); a++)
      {
	if (fmt[a] == '.')
	  break;
	if (strchr (rep_digit, fmt[a]))
	  f_cnt++;
      }
    // count format string number place holders, after the decimal point
    while (a < strlen (fmt))
      {
	if (strchr (rep_digit, fmt[a]))
	  d_cnt++;
	a++;
      }
    // count the digits in the integer part of the number
    for (a = b; (a > 0 && ptr1[a] > '0'); a--)
      n_cnt++;

    if (f_cnt < n_cnt)
      {
 A4GL_debug ("overflow, f_cnt=%d,d_cnt=%d,n_cnt=%d", f_cnt, d_cnt, n_cnt);
	a = strlen (fmt);
	if (a > s)
	  a = s;
	if (n_cnt > a)
	  {
	    // no way this number can fit, fill with stars ...
	    memset (str, '*', a);
	    return;
	  }
	if (strcasecmp (acl_getenv ("FORMAT_OVERFLOW"), "REFORMAT") == 0
	    || strcasecmp (acl_getenv ("FORMAT_OVERFLOW"), "ROUND") == 0)
	  {
	    // use a compact format that at least can display the number.
	    // round off decimal places only if FORMAT_OVERFLOW allows it
	    if (isneg)
	      {
		memset (fmt, '-', a);
		num = 0 - num;
	      }
	    else
	      {
		memset (fmt, '#', a);
	      }
	    if (n_cnt < a)
	      fmt[n_cnt] = '.';
	    if ((a - n_cnt > d_cnt) ||
		(strcasecmp (acl_getenv ("FORMAT_OVERFLOW"), "ROUND") == 0))
	      {
	 A4GL_debug ("trying fmt=%s", fmt);
		return (a4gl_using (str, s, fmt, num));
	      }
	  }
	// default is to use the strict I4GL behaviour, stars
	memset (str, '*', a);
	return;
      }
  }

  for (a = strlen (fm1) - 1; a >= 0; a--)
    {
      if (strchr (rep_digit, fm1[a]))
	{
	  if (((ptr1[b] == '0' && ptr1[b - 1] == ' ') || ptr1[b] == ' ')
	      && isprnt == 1)
	    isprnt = 0;
	  str[a] = ptr1[b--];
	  if (!isprnt)
	    {
	      if (fm1[a] == '#')
		{
		  str[a] = ' ';
		  continue;
		}
	      if (fm1[a] == '*')
		{
		  str[a] = '*';
		  continue;
		}
	      if (fm1[a] == '&')
		{
		  str[a] = '0';
		  continue;
		}
	      if (fm1[a] == '<')
		{
		  str[a] = '<';
		  continue;
		}
	      p = strchr (canfloat_head, fm1[a]);
	      if (p)
		{
		  p[0] = 1;
		  if (fm1[a] == '+' && isneg)
		    {
		      str[a] = '-';
		      continue;
		    }
		  if (fm1[a] == '+' && !isneg)
		    {
		      str[a] = '+';
		      continue;
		    }
		  if (fm1[a] == '-' && isneg)
		    {
		      str[a] = '-';
		      continue;
		    }
		  if (fm1[a] == '-' && !isneg)
		    {
		      str[a] = ' ';
		      continue;
		    }
		  if (fm1[a] == '(')
		    {
		      if (isneg)
			{
			  str[a] = '(';
			  continue;
			}
		      else
			{
			  str[a] = ' ';
			  continue;
			}
		    }
		  if (fm1[a] == ')' && isneg)
		    {
		      str[a] = ')';
		      continue;
		    }
		  str[a] = fm1[a];
		  continue;
		}
	      else
		{
		  str[a] = ' ';
		  continue;
		}
	      str[a] = fm1[a];
	    }
	}
      else
	{
	  if (ptr1[b] == ' ' && str[a] == ',')
	    {
	      if (fm1[a + 1] == '<')
		{
		  str[a] = '<';
		}
	      else
		{
		   str[a]=0x01; 
		}
	    }
	}
    }
  b = 0;

  for (a = 0; a < strlen (fm2); a++)
    {
      if (strchr (rep_digit, fm2[a]))
	{
	  if (fm2[a] == ')')
	    {
	      if (isneg)
		{
		  str[a + strlen (fm1) + 1] = ')';
		  continue;
		}
	      else
		{
		  str[a + strlen (fm1) + 1] = ' ';
		  continue;
		}
	    }

	  str[a + strlen (fm1) + 1] = ptr2[b++];
	}
      else
	{
	  str[a + strlen (fm1) + 1] = fm2[a];
	}
    }
#if defined (__MINGW32__)
  ptr = (char *) strrchr (str, '<');
#else
  ptr = (char *) rindex (str, '<');
#endif

  // for any unused leading "<" or "-<" format chars,
  // shift the output to the left
  if (ptr)
    {
      b = 0;
      for (a = 0; a < strlen (str); a++)
	{
	  if (str[a] == '<')
	    {
	      if (str[a + 1] == ',')
		str[a + 1] = '<';
	      continue;
	    }
	  if (!isneg && str[a] == '-' && str[a + 1] == '<')
	    continue;
	  buff[b++] = str[a];
	}
      buff[b] = 0;
      strcpy (str, buff);
    }

   for (a=0;a<strlen(str);a++) {
	if (str[a]==0x01) {
		if (a==0) str[a]=' ';
		else str[a]=str[a-1];
		if (a>=2) {
			if (str[a-1]=='$' && str[a-2]!='$') { str[a-1]=' '; }
			if (str[a-1]=='-' && str[a-2]!='-') { str[a-1]=' '; }
		}
	}
   }

  A4GL_debug ("using: result str=%s", str);
}



int A4GL_esql_db_open(int a) {
	static int dbopen=0;
	if (a==1) {dbopen=1;return 1;}
	if (a==0) {dbopen=0;return 0;}
	return dbopen;
}


void * A4GL_new_expr (char *value)
{
  struct expr_str *ptr;
  A4GL_debug ("new_expr - %s", value);
  ptr = malloc (sizeof (struct expr_str));
  ptr->next = 0;
  ptr->expr = strdup (value);
  A4GL_debug ("newexpr : %s -> %p\n", value, ptr);
  //dump_expr(ptr);
  return ptr;
}

/**
 * Insert a new value to the expression.
 *
 * @param orig_expr
 * @param value
 * @return
 */
void * A4GL_append_expr (struct expr_str *orig_ptr, char *value)
{
  struct expr_str *ptr;
  struct expr_str *start;
  start = orig_ptr;

  A4GL_debug ("MJA A4GL_append_expr %p (%s)", orig_ptr, value);

  ptr = A4GL_new_expr (value);
  if (orig_ptr->next != 0)
    {
      while (orig_ptr->next != 0)
        orig_ptr = orig_ptr->next;
    }
  orig_ptr->next = ptr;
  A4GL_debug ("Appended expr");
  //dump_expr(start);
  return start;
}
/* ============================== EOF ========================== */
