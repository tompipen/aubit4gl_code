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
# $Id: funcs_d.c,v 1.82 2007-02-22 16:46:32 mikeaubury Exp $
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
#include <ctype.h>
#include <wchar.h>		/* utf8 */

#if HAVE_STRINGS_H
#include <strings.h>
#endif

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
void *last_esql_db_connection=0;

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

	if (!a_strchr (str, '/')) {
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
  for (a = (int)strlen (fn); a >= 0; a--)
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
  A4GL_assertion(p==0,"Unable to allocate memory");
  A4GL_debug ("alloc %d bytes : %p %s %s %d", size,p,why,f,line);
  return p;
}

char *acl_strdup_full(void *a,char *r,char *f,int l) {
	char *p;
	p=strdup(a);
	A4GL_assertion(p==0,"Unable to allocate memory");
	return p;
}

void *acl_realloc_full(void *a,long b,char *r,char *f,int l) {
	void *p;
	p=realloc(a,b);
	A4GL_assertion(p==0,"Unable to allocate memory");
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
  A4GL_debug ("Free %p %s %d", ptr,f,line);
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
  s=(int)strlen(ptr);
  p=size-s;
  
  if (p>0) {memset(&ptr[s],' ',p);}
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
		A4GL_debug ("digittoc %d",*a);
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
a4gl_using (char *str, int s, char *fmt, double num)
{
  int dig[MAXDIG];
  int pnt[MAXPNT];
  char number[1000];
  char fm1[128], fm2[128];
  char *ptr1, *ptr;
  char *ptr2;
  int has_money;
  char *p;
  char canfloat_head[] = "*-+($";
  char rep_digit[] = "*&#<-+()$";
  char buff[800];
  int isneg = 0;
  int a, variable_called_b;
  int isprnt = 0;
  double ad;
  double num_dec;
  char new_str[256];



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
  if (a_strchr (fmt, '.'))
    {
#else
  if (index (fmt, '.'))
    {
#endif
      strcpy (fm1, fmt);
#if defined (__MINGW32__)
      p = (char *) a_strchr (fm1, '.');
#else
      p = (char *) index (fm1, '.');
#endif
      p[0] = 0;
#if defined (__MINGW32__)
      strcpy (fm2, a_strchr (fmt, '.') + 1);
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

  for (a = 1; a <= (int)strlen (fm2); a++)
    {
      ad = ad / 10;
    }

  num += ad;

  	SPRINTF1 (number, "%64.32f", num);
  if (strlen(number)>64) {
	  	// Its too big...
	    memset (str, '*', a);
		return;
  }
  num_dec=num-floor(num);
  A4GL_debug("Decimal portion = lf",num_dec);

  number[31] = 0;
  strcpy (str, fmt);
  variable_called_b = 30;
  isprnt = 1;

  // first, ensure the format string is wide enough to hold the number
  // if not, try drop trailing decimals, otherwise flag overflow with *'s
  {
    int f_cnt = 0;		// number of digits to left of dec. point in format
    int d_cnt = 0;		// number of digits to right of dec. point
    int n_cnt = isneg;		// number of left-digits needed for number supplied
    // count format string number place holders, up to decimal point
    for (a = 0; a < (int)strlen (fmt); a++)
      {
	if (fmt[a] == '.')
	  break;
	if (a_strchr (rep_digit, fmt[a]))
	  f_cnt++;
      }
    // count format string number place holders, after the decimal point
    while (a < (int)strlen (fmt))
      {
	if (a_strchr (rep_digit, fmt[a]))
	  d_cnt++;
	a++;
      }
	A4GL_debug("ptr1=%s b=%d",ptr1,variable_called_b);
    // count the digits in the integer part of the number
    for (a = variable_called_b; (a > 0 && ptr1[a] != ' '); a--)
      n_cnt++;


	if (strchr(fmt,'$')) has_money=1;
	else has_money=0;

A4GL_debug("f_cnt=%d n_cnt=%d\n",f_cnt,n_cnt);
    if (f_cnt < n_cnt +has_money)
      {
 A4GL_debug ("overflow, f_cnt=%d,d_cnt=%d,n_cnt=%d", f_cnt, d_cnt, n_cnt);
	a = (int)strlen (fmt);
	if (a > s)
	  a = s;


	if (n_cnt > a )
	  {
	    // no way this number can fit, fill with stars ...
	    memset (str, '*', a);
	    return;
	  }

	if (A4GL_aubit_strcasecmp (acl_getenv ("FORMAT_OVERFLOW"), "REFORMAT") == 0
	    || A4GL_aubit_strcasecmp (acl_getenv ("FORMAT_OVERFLOW"), "ROUND") == 0)
	  {
	    // use a compact format that at least can display the number.
	    // round off decimal places only if FORMAT_OVERFLOW allows it
	    if (isneg)
	      {
		memset (fmt, '-', (size_t)a);
		num = 0 - num;
	      }
	    else
	      {
		memset (fmt, '#', (size_t)a);
	      }
	    if (n_cnt < a)
	      fmt[n_cnt] = '.';
	    if ((a - n_cnt > d_cnt) ||
		(A4GL_aubit_strcasecmp (acl_getenv ("FORMAT_OVERFLOW"), "ROUND") == 0))
	      {
	 A4GL_debug ("trying fmt=%s", fmt);
		a4gl_using (str, s, fmt, num);
		return ;
	      }
	  }
	// default is to use the strict I4GL behaviour, stars
	memset (str, '*', a);
	return;
      }
  }

  for (a = (int)strlen (fm1) - 1; a >= 0; a--)
    {
      if (a_strchr (rep_digit, fm1[a]))
	{
	if (variable_called_b>=0) {
	  if (((ptr1[variable_called_b] == '0' && ptr1[variable_called_b - 1] == ' ') || ptr1[variable_called_b] == ' ') && isprnt == 1) isprnt = 0;
	}
	  str[a] = ptr1[variable_called_b--];
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
	      p = a_strchr (canfloat_head, fm1[a]);
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
	  if (ptr1[variable_called_b] == ' ' && str[a] == ',')
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
  variable_called_b = 0;


  SPRINTF2(new_str,"%1.*lf",(int)strlen(fm2)+1,num_dec); 
  ptr2=&new_str[2];
  A4GL_debug("str=%s fm1=%s fm2=%s ptr2=%s",str,fm1,fm2,ptr2);

  for (a = 0; a < (int)strlen (fm2); a++)
    {
      A4GL_debug("a=%d fm[a]=%c",a,fm2[a]);
      if (a_strchr (rep_digit, fm2[a]))
	{
	  if (fm2[a] == ')')
	    {
	      if (isneg)
		{
		  str[a + (int)strlen (fm1) + 1] = ')';
		  continue;
		}
	      else
		{
		  str[a + (int)strlen (fm1) + 1] = ' ';
		  continue;
		}
	    }
	  A4GL_debug("setting str[%d]=%c",a + (int)strlen (fm1) + 1,ptr2[variable_called_b]);
	  str[a + (int)strlen (fm1) + 1] = ptr2[variable_called_b++];
	}
      else
	{
	  A4GL_debug("setting str[%d]=%c",a + (int)strlen (fm1) + 1,fm2[a]);
	  str[a + (int)strlen (fm1) + 1] = fm2[a];
	}
    }
#if defined (__MINGW32__)
  ptr = (char *) strrchr (str, '<');
#else
  ptr = (char *) rindex (str, '<');
#endif

A4GL_debug("str=%s",str);
  // for any unused leading "<" or "-<" format chars,
  // shift the output to the left
  if (ptr)
    {
      variable_called_b = 0;
      for (a = 0; a < (int)strlen (str); a++)
	{
	  if (str[a] == '<')
	    {
	      if (str[a + 1] == ',')
		str[a + 1] = '<';
	      continue;
	    }
	  if (!isneg && str[a] == '-' && str[a + 1] == '<')
	    continue;
	  buff[variable_called_b++] = str[a];
	}
      buff[variable_called_b] = 0;
      strcpy (str, buff);
    }

A4GL_debug("str=%s",str);
   for (a=0;a<(int)strlen(str);a++) {
	if (str[a]==0x01) {

		if (a==0) str[a]=' ';
		else str[a]=str[a-1];


		if (a==1) {
			if (str[a-1]=='$' ) { str[a-1]=' '; }
			if (str[a-1]=='-' ) { str[a-1]=' '; }
			if (str[a-1]=='(' ) { str[a-1]=' '; }
		}

		if (a>=2) {
			if (str[a-1]=='$' && str[a-2]!='$') { str[a-1]=' '; }
			if (str[a-1]=='-' && str[a-2]!='-') { str[a-1]=' '; }
			if (str[a-1]=='(' && str[a-2]!='(') { str[a-1]=' '; }
		}
	}
   }
 if (A4GL_get_decimal_char(0)==',') {
	 char *p;
	int l;
	 p=strdup(str);
	l=strlen(p);
	 for (a=0;a<l;a++) {
		 if (str[a]==',') p[a]='.';
		 if (str[a]=='.') p[a]=',';
	 }
	 strcpy(str,p);
	 free(p);
 }
  A4GL_debug ("using: result str=%s", str);
}



int 
A4GL_esql_db_open(int a,char *src,char *dest,char *dbname) {
	static int dbopen=0;
	if (a==1) {
			dbopen=1;
			A4GLSQLCV_load_convert(src,dest);
			last_esql_db_connection=A4GL_db_connected(dbname);
			return 1;
	}
	if (a==0) {dbopen=0;return 0;}
	return dbopen;
}

void *
A4GL_esql_dbopen_connection(void) {
	return last_esql_db_connection;
}









int 
a_isprint(int a) {
	if (a>0xff) return 0;
	if (isprint(a)) return 1;
	if (a>0x7f) return 1;
	return 0;
}

//replacement for index() function missing on MinGW
char *
a_strchr(char *s,int c) {
int a;
int l;
	if (s==0) return 0;
	l=strlen(s);
	for (a=0;a<l;a++) {
			if (s[a]==c) return &s[a];
	}
	return 0;
}



void 
A4GL_strmaxcpy(char *dest,char *src,int max) {
	strncpy(dest,src,max);
	dest[max]=0;
}


char *
A4GL_get_esql_ext(void) {
char *hr;
	
	hr=acl_getenv("EC_EXT");
	
	if (hr) {
		if ((int)strlen(hr)) return hr;
	}
	
	if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "INFORMIX") == 0) { return ".ec"; }
	if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "POSTGRES") == 0) { return ".cpc"; }
	if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "SAPDB") == 0) { return ".cpc"; }
	if (strcmp (acl_getenv ("A4GL_LEXDIALECT"), "INGRES") == 0) { return ".sc"; }
	
	return ".ec";
}



void
A4GL_make_downshift (char *s)
{
  int a;
int l;
l=strlen (s);
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
int A4GL_menu_opts_compare(char *a,char *b,int why) {
	static int option_type=0;

	if (option_type==0) {
		if (A4GL_env_option_set("INFORMIXOPTIONS")&&option_type==0) 	{ option_type=1; }
		if (A4GL_env_option_set("CASEOPTIONS")&&option_type==0) 	{ option_type=2; }
		if (A4GL_env_option_set("CASEIGNOPTIONS")&&option_type==0) 	{ option_type=3; }
		if (option_type==0) option_type=1;
	}


	if (option_type==1) { // Sensitive only for next option
			if (why==MENU_COMPARE_SHOWHIDE) { return A4GL_aubit_strcasecmp(a,b); }
			return strcmp(a,b);
	}

	if (option_type==2) { return strcmp(a,b); } // Always sensitive

	if (option_type==3) { return A4GL_aubit_strcasecmp(a,b); } // never sensitive

// Shouldn't happen...
	return 0;
}



#ifdef QUERY
int A4GL_strcasestr(char *h,char *n) {
char *h1;
char *n1;
int r;
A4GL_push_char(h);
A4GL_upshift_stk();
h1=A4GL_char_pop();

A4GL_push_char(n);
A4GL_upshift_stk();
n1=A4GL_char_pop();
if (strstr(h1,n1)) r=1; else r=0;
free(h1);
free(n1);
return r;
}
#endif

/* compute screen width (columns occupied) of utf-8 character string
 * (multi-byte sequence). For ascii string, it should be the same as strlen()
 */
int A4GL_wcswidth(char *mbs) {
  wchar_t *wstr;
  size_t retc, mlen, wlen, width;
  mlen = strlen(mbs);
#ifdef WIN32
	return mlen;
#else
  wstr = acl_malloc2((mlen+1)*sizeof(wchar_t));
  retc = mbstowcs(wstr, mbs, mlen+1);
  if (!retc) {
    free(wstr);
    return 0;
  }
  wlen = wcslen(wstr);

  width = wcswidth(wstr, wlen);

  if (width==-1) width=mlen; // not a wide character ? 
  free(wstr);
  return width;
#endif
}

/* ============================== EOF ========================== */



