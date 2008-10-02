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
# $Id: funcs_d.c,v 1.104 2008-10-02 17:40:50 mikeaubury Exp $
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

#define EXTERN_CONVFMTS
#include "a4gl_libaubit4gl_int.h"
#include <ctype.h>

#include <wchar.h>		/* utf8 */

#if HAVE_STRINGS_H
#include <strings.h>
#endif

#ifdef HAVE_INDEX
#define CHAR_INDEX index
#else
#define CHAR_INDEX a_strchr
#endif

#include "m_apm.h"

M_APM *m_increment = 0;
int nincrement = 0;
static void add_increment (void);
void acl_apm_set_string (M_APM m1, char *s, int convert);
/*
=====================================================================
                    Variables definitions
=====================================================================
*/

// Most of the time we don't need to know an explicit connection id
// sometimes we do - if one is available at all
// Here - we're storing the last connection ID generated by the ESQL/C helper routine
// when a database is connected to from ESQL/C generated code.
// Its not required for Informix, just postgres ATM...
void *last_esql_db_connection = 0;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

int A4GL_bname2 (char *str, char *str1, char *str2, char *str3);
//void* A4GL_db_connected(char* dbname);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

// left pad a string with spaces..
static void
A4GL_lpad (char *s, int l)
{
  char buff[2000];
  int m;
// its already long enough? 
  if (strlen (s) >= l)
    return;
// how many spaces do we need ?
  m = l - strlen (s);
  memset (buff, ' ', 2000);
  buff[m] = 0;
// now - put our string on the end...
  strcat (buff, s);

// and copy it back..
  strcpy (s, buff);
}



static void
ensure_increment (int n)
{
//int a;
//char buff[200];

  if (nincrement >= n)
    return;

  while (nincrement <= n)
    {
      add_increment ();
    }

  /*
   *      for (a=0;a<nincrement;a++) {
   m_apm_to_fixpt_string(buff,10,m_increment[a]);
   }
   */
}


static void
add_increment ()
{
//static M_APM m_point_5;
  static M_APM m_10;
  static M_APM m_tmp;
  static int inited = 0;
//char buff[300];
//int a;

  nincrement++;
  m_increment = realloc (m_increment, nincrement * sizeof (M_APM));

  if (!inited)
    {
      m_increment[0] = m_apm_init ();
      m_10 = m_apm_init ();
      m_tmp = m_apm_init ();
      m_apm_set_string (m_increment[0], "0.5");
      m_apm_set_string (m_10, "10");
      inited++;
    }

  if (nincrement == 1)
    return;

  m_apm_divide (m_tmp, 32, m_increment[nincrement - 2], m_10);
  m_increment[nincrement - 1] = m_apm_init ();
  m_apm_copy (m_increment[nincrement - 1], m_tmp);

}


/**
 * Another implementation of basename. How many do we need?
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

  if (!CHAR_INDEX (str, '/'))
    {
      return 0;
    }

#ifdef DEBUG
  A4GL_debug ("%p %p %p %p", str, str1, str2, str3);
  A4GL_debug ("(1)%s %s %s", str1, str2, str3);
#endif
  strcpy (ss, str);
#ifdef DEBUG
  A4GL_debug ("(1.1)%s %s %s", str1, str2, str3);
  A4GL_debug ("In A4GL_bname2 %s");
#endif
  A4GL_trim (ss);
#ifdef DEBUG
  A4GL_debug ("(2)%s %s %s", str1, str2, str3);
#endif
  A4GL_bnamexxx (ss, b2, b3);
#ifdef DEBUG
  A4GL_debug ("(1) Splits to %s %s", b2, b3);
  A4GL_debug ("(3)%s %s %s", str1, str2, str3);
#endif
  strcpy (ss, b2);
  A4GL_bnamexxx (ss, b1, b2);
#ifdef DEBUG
  A4GL_debug ("(2) Splits to '%s' '%s'", b1, b2);
  A4GL_debug ("(4)%s %s %s", str1, str2, str3);
  A4GL_debug ("'%s' '%s' '%s'", b1, b2, b3);
  A4GL_debug ("%s %s %s", str1, str2, str3);
#endif
  strcpy (str1, b1);
#ifdef DEBUG
  A4GL_debug ("1");
#endif
  strcpy (str2, b2);
#ifdef DEBUG
  A4GL_debug ("1");
#endif
  strcpy (str3, b3);
#ifdef DEBUG
  A4GL_debug ("Copied...");
#endif
  return 1;
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
  for (a = (int) strlen (fn); a >= 0; a--)
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

#ifdef MOVED
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
acl_malloc_full (long size, char *why, char *f, long line)
{
  void *p;
  p = malloc (size);
  A4GL_assertion (p == 0, "Unable to allocate memory");
  A4GL_debug ("alloc %d bytes : %p %s %s %d", size, p, why, f, line);
  return p;
}

char *
acl_strdup_full (void *a, char *r, char *f, int l)
{
  char *p;
  p = strdup (a);
  A4GL_assertion (p == 0, "Unable to allocate memory");
  return p;
}

void *
acl_realloc_full (void *a, long b, char *r, char *f, int l)
{
  void *p;
  p = realloc (a, b);
  A4GL_assertion (p == 0, "Unable to allocate memory");
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
  A4GL_debug ("Free %p %s %d", ptr, f, line);
  free (ptr);
}
#endif

/**
 * Pad a string with spaces until the string reaches a size.
 *
 * @param ptr A pointer to the string being padded.
 * @param The size of the string.
 */
void
A4GL_pad_string (char *ptr, int size)
{
  //int a;
  int p;
  int s;
  s = (int) strlen (ptr);
  p = size - s;

  if (p > 0)
    {
      memset (&ptr[s], ' ', p);
    }
/*
  for (a = (int)strlen (ptr); a < size; a++)
    {
      ptr[a] = ' ';
    }
*/
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
  A4GL_debug ("digittoc %d", *a);
#endif
  SPRINTF1 (buff, fmt, *a);

#ifdef DEBUG
  A4GL_debug ("digittoc: %s", buff);
#endif

#define DIGIT_ALIGN_LEFT

#ifdef DIGIT_ALIGN_LEFT
  SPRINTF2 (buff, "%%-%d%s", size, fmt);
#else
  SPRINTF2 (buff, "%%%d%s", size, fmt);
#endif

#ifdef DEBUG
  A4GL_debug ("digittoc: buff set to %s", buff);
#endif
  strcpy (fmt, buff);
#ifdef DEBUG
  A4GL_debug ("digittoc: returns");
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
a4gl_using_from_string (char *str, int s, char *fmt, char *numeric, int isneg)
{
  //int dig[MAXDIG];
  //int pnt[MAXPNT];
  char *dot;
  //char number[1000]="";
  char fm1[128] = "", fm2[128] = "";
  char *ptr = 0;
  int has_money = 0;
  char *p = 0;
  int num_places = 64;
  char canfloat_head[] = "*-+($";
  char rep_digit[] = "*&#<-+()$";
  char buff[800] = "";
  int v_a = 0, variable_called_b = 0;
  int isprnt = 0;
  char buff_decimal[2000];
  char buff_integer[2000];
  char *ptr_decimal;

  M_APM M_main;
  M_APM M_integer;
  M_APM M_tmp;
  M_APM M_decimal;

  int lb = 0;
  int cb = 0;
//printf("DEBUG %s\n",numeric);

  for (v_a = 0; v_a < strlen (fmt); v_a++)
    {
      if (fmt[v_a] == '(')
	lb++;
      if (fmt[v_a] == ')')
	cb++;
    }

  memset (str, 0, s);

//never_neg=num;
//if (num<0) never_neg=0.0-num;

  if (lb > 1 && cb > 1)
    {
      return;
    }
  if (lb && cb)
    {

      if (lb == 1 && cb == 1)
	{
	  char *buff2;
	  char *ptr;
	  char fmt2[20000];

	  buff2 = malloc (strlen (fmt) + 1);
	  strcpy (buff2, strchr (fmt, '(') + 1);
	  ptr = strchr (buff2, ')');
	  if (ptr == 0)
	    {			// its all gone pete tong...
	      strcpy (str, "");
	      free (buff2);
	      return;
	    }
	  *ptr = 0;
	  for (v_a = 0; v_a < strlen (buff2); v_a++)
	    {
	      if (buff2[v_a] == '(')
		buff2[v_a] = '#';
	      if (buff2[v_a] == ')')
		buff2[v_a] = '#';
	    }
	  //printf("buff2=%s %lf \n",buff2, never_neg);
	  a4gl_using_from_string (fmt2, sizeof (fmt2), buff2, numeric, 0);
	  //printf("fmt2=%s\n",fmt2);
	  strncpy (strchr (fmt, '(') + 1, fmt2, strlen (buff2));
	  if (!isneg)
	    {
	      //printf("fmt=%s fmt2=%s\n",fmt,fmt2);
	      if (strchr (fmt, '(') && strchr (fmt, ')'))
		{
		  ptr = strchr (fmt, '(');
		  *ptr = ' ';
		  ptr = strchr (fmt, ')');
		  *ptr = ' ';
		}
	    }
	  strcpy (str, fmt);
	  free (buff2);

	}

      if (lb > 1 && cb == 1)
	{
	  char *buff2;
	  char *ptr;
	  char fmt2[20000];

	  memset (fmt2, 0, sizeof (fmt2));
	  buff2 = malloc (strlen (fmt) + 1);
	  strcpy (buff2, strchr (fmt, '(') + 1);
	  ptr = strchr (buff2, ')');
	  if (ptr == 0)
	    {			// its all gone pete tong...
	      strcpy (str, "");
	      free (buff2);
	      return;
	    }
	  *ptr = 0;
	  for (v_a = 0; v_a < strlen (buff2); v_a++)
	    {
	      if (buff2[v_a] == '(')
		buff2[v_a] = '#';
	    }

	  //printf("%s %s\n",fmt,fmt2);
	  //a4gl_using(fmt2, sizeof(fmt2),buff2,never_neg);
	  a4gl_using_from_string (fmt2, sizeof (fmt2), buff2, numeric, 0);
	  strncpy (strchr (fmt, '(') + 1, fmt2, strlen (buff2));

	  if (!isneg)
	    {
	      ptr = strchr (fmt, '(');
	      if (ptr)
		{
		  *ptr = ' ';
		}
	      ptr = strchr (fmt, ')');
	      if (ptr)
		{
		  *ptr = ' ';
		}
	    }
	  else
	    {
	      // need to move the '('...
	      for (v_a = 0; v_a < strlen (fmt); v_a++)
		{
		  if (fmt[v_a] == '(' && fmt[v_a + 1] == ' ')
		    {
		      fmt[v_a] = ' ';
		      fmt[v_a + 1] = '(';
		    }
		}
	    }

	  strcpy (str, fmt);
	  free (buff2);
	}


      if (lb == 1 && cb > 1)
	{
	  char *buff2;
	  char *ptr;
	  char fmt2[20000];

	  buff2 = malloc (strlen (fmt) + 1);
	  strcpy (buff2, strchr (fmt, '(') + 1);
	  ptr = strrchr (buff2, ')');
	  if (ptr == 0)
	    {			// its all gone pete tong...
	      strcpy (str, "");
	      free (buff2);
	      return;
	    }
	  *ptr = 0;
	  for (v_a = 0; v_a < strlen (buff2); v_a++)
	    {
	      if (buff2[v_a] == ')')
		buff2[v_a] = '#';
	    }

	  //printf("%s %s\n",fmt,fmt2);
	  //a4gl_using(fmt2, sizeof(fmt2),buff2,never_neg);
	  a4gl_using_from_string (fmt2, sizeof (fmt2), buff2, numeric, 0);
	  strncpy (strchr (fmt, '(') + 1, fmt2, strlen (buff2));

	  if (!isneg)
	    {
	      ptr = strchr (fmt, '(');
	      if (ptr)
		{
		  *ptr = ' ';
		}
	      ptr = strchr (fmt, ')');
	      if (ptr)
		{
		  *ptr = ' ';
		}
	    }
	  else
	    {
	      // need to move the ')'...
	      for (v_a = 0; v_a < strlen (fmt); v_a++)
		{
		  if (fmt[v_a] == ' ' && fmt[v_a + 1] == ')')
		    {
		      fmt[v_a] = ')';
		      fmt[v_a + 1] = ' ';
		    }
		}
	    }

	  strcpy (str, fmt);
	  free (buff2);
	}


      return;
    }

/*
  for (v_a = 0; v_a < MAXPNT; v_a++)
    {
      pnt[v_a] = 0;
    }

  for (v_a = 0; v_a < MAXDIG; v_a++)
    {
      dig[v_a] = 0;
    }
*/


  M_main = m_apm_init ();
  M_tmp = m_apm_init ();
  M_integer = m_apm_init ();
  M_decimal = m_apm_init ();



  acl_apm_set_string (M_main, numeric, 0);



  if (CHAR_INDEX (fmt, '.'))
    {
      char *buff;
      strcpy (fm1, fmt);
      p = (char *) CHAR_INDEX (fm1, '.');
      p[0] = 0;
      strcpy (fm2, CHAR_INDEX (fmt, '.') + 1);
      buff = strdup (fm2);
      A4GL_trim (buff);
      num_places = strlen (buff);
      free (buff);
    }
  else
    {
      strcpy (fm1, fmt);
      strcpy (fm2, "");
      num_places = 0;
    }



  ensure_increment (num_places + 2);
/*
  for (a = 1; a <= (int)strlen (fm2); a++)
    {
      m_apm_divide(m_tmp, strlen(fm2)+3, m_increment,m_10);
      m_apm_copy(m_increment,m_tmp);
    }
*/




  m_apm_add (M_tmp, M_main, m_increment[num_places]);

  m_apm_to_fixpt_string (buff, 32, M_main);
  m_apm_add (M_tmp, M_main, m_increment[num_places]);
  m_apm_to_fixpt_string (buff, 32, m_increment[num_places]);
  m_apm_copy (M_main, M_tmp);


//
// we need to trunc our number to a specific number of decimal places
// this is easiest by converting to a string and back again, because the m_apm_round is to significant digits
// not to decimal places...
  m_apm_to_fixpt_string (buff, 32, M_main);
  dot = strchr (buff, '.');
  if (dot)
    {
      dot += num_places + 1;
      *dot = 0;
    }
  acl_apm_set_string (M_tmp, buff, 0);
  m_apm_copy (M_main, M_tmp);



  m_apm_free (M_tmp);




  m_apm_floor (M_integer, M_main);
  m_apm_subtract (M_decimal, M_main, M_integer);


  m_apm_free (M_main);



  m_apm_to_fixpt_string (buff_integer, 0, M_integer);
  m_apm_free (M_integer);
  m_apm_to_fixpt_string (buff_decimal, num_places, M_decimal);
  m_apm_free (M_decimal);

  // should always start "0."
  if (strcmp (buff_decimal, "0") == 0)
    {
      strcpy (buff_decimal, "0.0");
    }
  ptr_decimal = &buff_decimal[2];
  A4GL_lpad (buff_integer, 31);
  //printf("%s ... %s\n", buff_integer, ptr_decimal);

  if (num_places > 64 || strlen (ptr_decimal) >= 64)
    {
      // Its too big...
      memset (str, '*', s);
      str[s] = 0;

      return;
    }
  strcat (buff_decimal, "000000000000000000000000000000000");
  ptr_decimal[32] = 0;
  strcpy (str, fmt);
  variable_called_b = 30;
  isprnt = 1;
//printf("--->%s\n",buff_decimal);
  // first, ensure the format string is wide enough to hold the number
  // if not, try drop trailing decimals, otherwise flag overflow with *'s
  {
    int f_cnt = 0;		// number of digits to left of dec. point in format
    int d_cnt = 0;		// number of digits to right of dec. point
    int n_cnt = isneg;		// number of left-digits needed for number supplied
    if (isneg)
      {
	if (strchr (fmt, '(') || strchr (fmt, ')') || strchr (fmt, '+') || strchr (fmt, '-'));
	else
	  {
	    // No negative bit to display :-)
	    // so - we dont need to allow extra space for it...
	    n_cnt = 0;
	  }
      }
    else
      {
	if (strchr (fmt, '(') || strchr (fmt, ')') || strchr (fmt, '+') || strchr (fmt, '-'))
	  {
	    if (A4GL_isyes (acl_getenv ("COMPATFMT")))
	      {
		n_cnt = 1;
	      }
	  }
      }
    // count format string number place holders, up to decimal point
    for (v_a = 0; v_a < (int) strlen (fmt); v_a++)
      {
	if (fmt[v_a] == '.')
	  break;
	if (CHAR_INDEX (rep_digit, fmt[v_a]))
	  f_cnt++;
      }
    // count format string number place holders, after the decimal point
    while (v_a < (int) strlen (fmt))
      {
	if (CHAR_INDEX (rep_digit, fmt[v_a]))
	  d_cnt++;
	v_a++;
      }
    // count the digits in the integer part of the number
    for (v_a = variable_called_b; (v_a > 0 && buff_integer[v_a] != ' '); v_a--)
      n_cnt++;


    if (strchr (fmt, '$'))
      has_money = 1;
    else
      has_money = 0;

    A4GL_debug ("f_cnt=%d n_cnt=%d\n", f_cnt, n_cnt);
    if (f_cnt < n_cnt + has_money)
      {
	A4GL_debug ("overflow, f_cnt=%d,d_cnt=%d,n_cnt=%d", f_cnt, d_cnt, n_cnt);
	v_a = (int) strlen (fmt);
	if (v_a > s)
	  v_a = s;


	if (n_cnt > v_a)
	  {
	    // no way this number can fit, fill with stars ...
	    memset (str, '*', s);
	    str[s] = 0;
	    return;
	  }

	if (A4GL_aubit_strcasecmp (acl_getenv ("FORMAT_OVERFLOW"), "REFORMAT") == 0
	    || A4GL_aubit_strcasecmp (acl_getenv ("FORMAT_OVERFLOW"), "ROUND") == 0)
	  {
	    // use a compact format that at least can display the number.
	    // round off decimal places only if FORMAT_OVERFLOW allows it
	    if (isneg)
	      {
		memset (fmt, '-', (size_t) v_a);
		//num = 0 - num;
	      }
	    else
	      {
		memset (fmt, '#', (size_t) v_a);
	      }
	    if (n_cnt < v_a)
	      fmt[n_cnt] = '.';
	    if ((v_a - n_cnt > d_cnt) || (A4GL_aubit_strcasecmp (acl_getenv ("FORMAT_OVERFLOW"), "ROUND") == 0))
	      {
		A4GL_debug ("trying fmt=%s", fmt);
		a4gl_using_from_string (str, s, fmt, numeric, isneg);
		return;
	      }
	  }
	// default is to use the strict I4GL behaviour, stars
	memset (str, '*', s);
	str[s] = 0;
	return;
      }
  }

  for (v_a = (int) strlen (fm1) - 1; v_a >= 0; v_a--)
    {
      if (CHAR_INDEX (rep_digit, fm1[v_a]))
	{
	  if (variable_called_b >= 0)
	    {
	      A4GL_debug ("%c\n", buff_integer[variable_called_b]);
	      if (((buff_integer[variable_called_b] == '0' && buff_integer[variable_called_b - 1] == ' ')
		   || buff_integer[variable_called_b] == ' ') && isprnt == 1)
		isprnt = 0;
	    }
	  str[v_a] = buff_integer[variable_called_b--];
	  if (!isprnt)
	    {
	      if (fm1[v_a] == '#')
		{
		  str[v_a] = ' ';
		  continue;
		}
	      if (fm1[v_a] == '*')
		{
		  str[v_a] = '*';
		  continue;
		}
	      if (fm1[v_a] == '&')
		{
		  str[v_a] = '0';
		  continue;
		}
	      if (fm1[v_a] == '<')
		{
		  str[v_a] = '<';
		  continue;
		}
	      p = CHAR_INDEX (canfloat_head, fm1[v_a]);
	      if (p)
		{
		  p[0] = 1;
		  if (fm1[v_a] == '+' && isneg)
		    {
		      str[v_a] = '-';
		      continue;
		    }
		  if (fm1[v_a] == '+' && !isneg)
		    {
		      str[v_a] = '+';
		      continue;
		    }
		  if (fm1[v_a] == '-' && isneg)
		    {
		      str[v_a] = '-';
		      continue;
		    }
		  if (fm1[v_a] == '-' && !isneg)
		    {
		      str[v_a] = ' ';
		      continue;
		    }
		  if (fm1[v_a] == '(')
		    {
		      if (isneg)
			{
			  str[v_a] = '(';
			  continue;
			}
		      else
			{
			  str[v_a] = ' ';
			  continue;
			}
		    }
		  if (fm1[v_a] == ')' && isneg)
		    {
		      str[v_a] = ')';
		      continue;
		    }
		  str[v_a] = fm1[v_a];
		  continue;
		}
	      else
		{
		  str[v_a] = ' ';
		  continue;
		}
	      str[v_a] = fm1[v_a];
	    }
	}
      else
	{
	  if (buff_integer[variable_called_b] == ' ' && str[v_a] == ',')
	    {
	      if (fm1[v_a + 1] == '<')
		{
		  str[v_a] = '<';
		}
	      else
		{
		  str[v_a] = 0x01;
		}
	    }
	}
    }
  variable_called_b = 0;

  A4GL_debug ("s=%s\n", str);

  for (v_a = 0; v_a < (int) strlen (fm2); v_a++)
    {
      A4GL_debug ("a=%d fm[a]=%c", v_a, fm2[v_a]);
      if (CHAR_INDEX (rep_digit, fm2[v_a]))
	{
	  if (fm2[v_a] == ')')
	    {
	      if (isneg)
		{
		  str[v_a + (int) strlen (fm1) + 1] = ')';
		  continue;
		}
	      else
		{
		  str[v_a + (int) strlen (fm1) + 1] = ' ';
		  continue;
		}
	    }
	  A4GL_debug ("setting str[%d]=%c", v_a + (int) strlen (fm1) + 1, ptr_decimal[variable_called_b]);
	  str[v_a + (int) strlen (fm1) + 1] = ptr_decimal[variable_called_b++];
	}
      else
	{
	  A4GL_debug ("setting str[%d]=%c", v_a + (int) strlen (fm1) + 1, fm2[v_a]);
	  str[v_a + (int) strlen (fm1) + 1] = fm2[v_a];
	}
    }

#ifdef HAVE_RINDEX
  ptr = (char *) rindex (str, '<');
#else
#ifdef HAVE_STRRCHR
  ptr = (char *) strrchr (str, '<');
#else
#error No rindex function
#endif
#endif

  A4GL_debug ("str=%s", str);
  // for any unused leading "<" or "-<" format chars,
  // shift the output to the left
  if (ptr)
    {
      variable_called_b = 0;
      for (v_a = 0; v_a < (int) strlen (str); v_a++)
	{
	  if (str[v_a] == '<')
	    {
	      if (str[v_a + 1] == ',')
		str[v_a + 1] = '<';
	      continue;
	    }
	  if (!isneg && str[v_a] == '-' && str[v_a + 1] == '<')
	    continue;
	  buff[variable_called_b++] = str[v_a];
	}
      buff[variable_called_b] = 0;
      strcpy (str, buff);
    }

  A4GL_debug ("str=%s", str);
  for (v_a = 0; v_a < (int) strlen (str); v_a++)
    {
      A4GL_debug ("Here");
      if (str[v_a] == 0x01)
	{
	  A4GL_debug ("Here as well");

	  if (v_a == 0)
	    str[v_a] = ' ';
	  else
	    str[v_a] = str[v_a - 1];


	  if (v_a == 1)
	    {
	      if (str[v_a - 1] == '$')
		{
		  str[v_a - 1] = ' ';
		}
	      if (str[v_a - 1] == '-')
		{
		  str[v_a - 1] = ' ';
		}
	      if (str[v_a - 1] == '(')
		{
		  str[v_a - 1] = ' ';
		}
	    }

	  if (v_a >= 2)
	    {
	      if (str[v_a - 1] == '$' && str[v_a - 2] != '$')
		{
		  str[v_a - 1] = ' ';
		}
	      if (str[v_a - 1] == '-' && str[v_a - 2] != '-')
		{
		  str[v_a - 1] = ' ';
		}
	      if (str[v_a - 1] == '(' && str[v_a - 2] != '(')
		{
		  str[v_a - 1] = ' ';
		}
	    }
	}
    }
  for (v_a = strlen (str) - 1; v_a >= 0; --v_a)
    {
      if (str[v_a] == '.')
	str[v_a] = a4gl_convfmts.ui_decfmt.decsep;
      else if (str[v_a] == a4gl_convfmts.ui_decfmt.decsep)
	str[v_a] = a4gl_convfmts.ui_decfmt.thsep ? a4gl_convfmts.ui_decfmt.thsep : '.';
    }

  if (has_money && !strchr (str, '$'))
    {
      int first_non_space = -1;
      A4GL_debug ("Lacking money");
      // Lacking money!
      for (v_a = 0; v_a < strlen (str); v_a++)
	{
	  if (str[v_a] != ' ')
	    {
	      first_non_space = v_a;
	      break;
	    }
	}
      if (first_non_space > 0)
	{
	  A4GL_debug ("first_non_space=%d\n", first_non_space);
	  if (str[first_non_space] == '-' || str[first_non_space] == '(' || str[first_non_space] == '+')
	    {
	      str[first_non_space - 1] = str[first_non_space];
	      str[first_non_space] = '$';
	    }
	  else
	    {
	      str[first_non_space - 1] = '$';
	    }
	}
    }
  A4GL_debug ("using: result str=%s", str);

}

void
a4gl_using (char *str, int s, char *fmt, double num)
{
  char buff[2000];

  if (num < 0)
    {
      num *= -1.0;
      SPRINTF1 (buff, "%64.16f", num);
      A4GL_decstr_convert (buff, a4gl_convfmts.printf_decfmt, a4gl_convfmts.posix_decfmt, 0, 1, sizeof (buff));
      a4gl_using_from_string (str, s, fmt, buff, 1);
    }
  else
    {
      SPRINTF1 (buff, "%64.16f", num);
      A4GL_decstr_convert (buff, a4gl_convfmts.printf_decfmt, a4gl_convfmts.posix_decfmt, 0, 1, sizeof (buff));
      a4gl_using_from_string (str, s, fmt, buff, 0);
    }
}

char *
A4GL_get_target_dialect (char *lex_default, char *lex_compile_time_target)
{
  static char buff[2000] = "";
  static int isset = 0;
  char *curr_dialect;

  if (isset)
    {
      return buff;
    }
  curr_dialect = acl_getenv_not_set_as_0 ("A4GL_TARGETDIALECT");
  if (curr_dialect)
    {
      strcpy (buff, curr_dialect);
      isset++;
      return curr_dialect;
    }
  if (lex_compile_time_target && strlen (lex_compile_time_target))
    {
      strcpy (buff, lex_compile_time_target);
      return buff;
    }
  strcpy (buff, lex_default);
  return buff;
}


int
A4GL_esql_db_open (int a, char *src, char *dest, char *dbname)
{
  static int dbopen = 0;
  if (a == 1)
    {
      dbopen = 1;
      A4GLSQLCV_load_convert (src, dest);
      last_esql_db_connection = A4GL_db_connected (dbname);
      return 1;
    }
  if (a == 0)
    {
      dbopen = 0;
      return 0;
    }
  return dbopen;
}

void *
A4GL_esql_dbopen_connection (void)
{
  return last_esql_db_connection;
}









int
a_isprint (int a)
{
  if (a > 0xff)
    return 0;
  if (isprint (a))
    return 1;
  if (a > 0x7f)
    return 1;
  return 0;
}

//replacement for index() function missing on MinGW
char *
a_strchr (char *s, int c)
{
  int a;
  int l;
  if (s == 0)
    return 0;
  l = strlen (s);
  for (a = 0; a < l; a++)
    {
      if (s[a] == c)
	return &s[a];
    }
  return 0;
}



void
A4GL_strmaxcpy (char *dest, char *src, int max)
{
  strncpy (dest, src, max);
  dest[max] = 0;
}


char *
A4GL_get_esql_ext (void)
{
  char *hr;

  hr = acl_getenv ("EC_EXT");

  if (hr)
    {
      if ((int) strlen (hr))
	return hr;
    }

  if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "INFORMIX") == 0)
    {
      return ".ec";
    }
  if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "POSTGRES") == 0)
    {
      return ".cpc";
    }
  if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "SAPDB") == 0)
    {
      return ".cpc";
    }
  if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "INGRES") == 0)
    {
      return ".sc";
    }

  return ".ec";
}



void
A4GL_make_downshift (char *s)
{
  int a;
  int l;
  l = strlen (s);
  for (a = 0; a < l; a++)
    {
      s[a] = tolower (s[a]);
    }
}

/**
 * Check a menu option for a match against a 'NEXT OPTION', 'SHOW OPTION', or 'HIDE OPTION'
 * This is important because Informix does a non-case sensitive match for SHOW/HIDE, but a case
 * sensitive match for 'next option'. Here we try to accomodate this behaviour - as well as the 
 * two other possible ways of matching...
 *
 * @param a menu option to match
 * @param b string to match against
 * @param why  either MENU_COMPARE_SHOWHIDE or MENU_COMPARE_NEXT_OPTION
 * @return whether the options match...
 */
int
A4GL_menu_opts_compare (char *a, char *b, int why)
{
  static int option_type = 0;

  if (option_type == 0)
    {
      if (A4GL_env_option_set ("INFORMIXOPTIONS") && option_type == 0)
	{
	  option_type = 1;
	}
      if (A4GL_env_option_set ("CASEOPTIONS") && option_type == 0)
	{
	  option_type = 2;
	}
      if (A4GL_env_option_set ("CASEIGNOPTIONS") && option_type == 0)
	{
	  option_type = 3;
	}
      if (option_type == 0)
	option_type = 1;
    }


  if (option_type == 1)
    {				// Sensitive only for next option
      if (why == MENU_COMPARE_SHOWHIDE)
	{
	  return A4GL_aubit_strcasecmp (a, b);
	}
      return strcmp (a, b);
    }

  if (option_type == 2)
    {
      return strcmp (a, b);
    }				// Always sensitive

  if (option_type == 3)
    {
      return A4GL_aubit_strcasecmp (a, b);
    }				// never sensitive

// Shouldn't happen...
  return 0;
}



#ifdef QUERY
int
A4GL_strcasestr (char *h, char *n)
{
  char *h1;
  char *n1;
  int r;
  A4GL_push_char (h);
  A4GL_upshift_stk ();
  h1 = A4GL_char_pop ();

  A4GL_push_char (n);
  A4GL_upshift_stk ();
  n1 = A4GL_char_pop ();
  if (strstr (h1, n1))
    r = 1;
  else
    r = 0;
  free (h1);
  free (n1);
  return r;
}
#endif

/* compute screen width (columns occupied) of utf-8 character string
 * (multi-byte sequence). For ascii string, it should be the same as strlen()
 */
int
A4GL_wcswidth (char *mbs)
{
  wchar_t *wstr;
  size_t retc, mlen, wlen, width;
  mlen = strlen (mbs);

#ifdef WIN32
  return mlen;
#else
  wstr = acl_malloc2 ((mlen + 1) * sizeof (wchar_t));

  retc = mbstowcs (wstr, mbs, mlen + 1);
  if (!retc)
    {
      free (wstr);
      return 0;
    }
  wlen = wcslen (wstr);
  if (wlen < mlen)
    wlen = mlen;

  width = wcswidth (wstr, wlen);
  if (width == -1 || width < mlen)
    width = mlen;		// not a wide character ? 
  free (wstr);
  return width;
#endif
}

/* ============================== EOF ========================== */
