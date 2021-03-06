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
# $Id: builtin_d.c,v 1.111 2010-01-25 21:12:07 mikeaubury Exp $
#
*/

/**
 * @file
 * Builtin functions of x4gl.
 *
 * Contains functions for
 *   - Pushing and poping values from / for functions
 *   - Builtin implemented functions
 *
 *
 * @todo Doxygen comments to add to functions
 * @todo -Wmissig-prototypes
 * @todo -Wstrict-prototypes
 * @todo -Wall
 * @todo -pedantic
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/
#define EXTERN_CONVFMTS
#include "a4gl_libaubit4gl_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

/* #define DIGIT_ALIGN_LEFT */

/*
builtin_d.c:89: warning: function declaration isn't a prototype
builtin_d.c:89: warning: redundant redeclaration of `__errno_location' in same scope
*/

/* extern int errno; */

/**
 * Structure that describes the functions used.
 */
struct s_funcs
{
  char *fname;		/**< The function name */
  void (*func) (void);		/**< Pointer to the function too execute *//*warning: function declaration isn't a prototype */
  int nin;		/**< Number of input parameters */
  int nout;		/**< NUmber of values returned */
};

int last_was_empty = 0;

struct s_funcs builtin_funcs[] = {
/*
	{"today",push_today,0,1},
	{"user",push_user,0,1},
	{"mdy",func_mdy,3,1},
	{"hex",func_hex,1,1},
	{"abs",func_abs,1,1},
	{"mod",func_mod,2,1},
	{"pow",func_pow,2,1},
	{"root",func_root,2,1},
	{"sqrt",func_sqrt,1,1},
	{"trunc",func_trunc,1,1},
	{"round",func_round,1,1},
	{"exp",func_exp,2,1},
	{"logn",func_logn,2,1},
	{"log10",func_log10,1,1},
	{"date",func_date,1,1},
	{"day",func_day,1,1},
	{"month",aclfgl_month,1,1},
	{"weekday",c_weekday,1,1},
	{"year",func_year,1,1},
	{"using",func_using,2,1},
	{"clip",func_clip,1,1},
	{"concat",func_concat,2,1},
	{"",(void *)0,0,0}
*/
  {"", (void *) 0, 0, 0}
};


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void A4GL_func_mod (void);
void func_pow (void);
void A4GL_func_trunc (void);
void A4GL_func_round (void);
void A4GL_func_exp (void);
void A4GL_func_logn (void);
void A4GL_func_log10 (void);
int aclfgl_ord (int n);
int aclfgl_time (int n);

static void push_byte (void *ptr);
static void push_text (void *ptr);

void A4GL_push_double_str (char *p);
//void A4GL_push_empty_char(void);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Called at run-time by the generated C code.
 * Its used to push an int to the parameters stack.
 *
 * @param p The integer value to be pushed to the stack
 */
void
A4GL_push_int (short p)
{
  short *ptr;
  ptr = (short *) acl_malloc (sizeof (short), "push int");
  *ptr = p;
  A4GL_push_param (ptr, DTYPE_SMINT + DTYPE_MALLOCED);
}

/**
 * Called at run-time by the generated C code.
 * Its used to push an long to the parameters stack.
 *
 * @param p The long value to be pushed to the stack
 */
void
A4GL_push_long (long p)
{
  long *ptr;
  ptr = (long *) acl_malloc (sizeof (long), "push long");
  /* memset(ptr,0,sizeof(long)); */
  *ptr = p;
  A4GL_push_param (ptr, DTYPE_INT + DTYPE_MALLOCED);
}

void
A4GL_push_objectID (long p)
{
  long *ptr;
  ptr = (long *) acl_malloc (sizeof (long), "push long");
  /* memset(ptr,0,sizeof(long)); */
  *ptr = p;
  A4GL_push_param (ptr, DTYPE_OBJECT + DTYPE_MALLOCED);
}


void A4GL_push_date_in_char(char *s) {
int l;
A4GL_push_char(s);
l=A4GL_pop_date();
A4GL_push_date(l);
}
/**
 * Called at run-time by the generated C code.
 * Its used to push a date (long because of julian) to the parameters stack.
 *
 * @param p The date value to be pushed to the stack
 */
void
A4GL_push_date (long p)
{
  long *ptr;
  ptr = (long *) acl_malloc (sizeof (long), "push_date");
  *ptr = p;
  A4GL_push_param (ptr, DTYPE_DATE + DTYPE_MALLOCED);
}

/**
 * Called at run-time by the generated C code.
 * Its used to push a byte (identified by a void ptr) to the parameters stack.
 *
 * @param ptr A pointer to the byte stream to be pushed
 */
void
push_byte (void *ptr)
{
  /*
     void *p2;
     p2=acl_malloc(sizeof(struct fgl_int_loc),"push_byte");
     memcpy(p2,ptr,sizeof(struct fgl_int_loc));
   */
  A4GL_push_param (ptr, (int) (DTYPE_BYTE + ENCODE_SIZE (sizeof (struct fgl_int_loc))));
}

/**
 * Called at run-time by the generated C code.
 * Its used to push a byte (identified by a void ptr) to the parameters stack.
 *
 * @param ptr A pointer to the byte stream to be pushed
 */
void
push_text (void *ptr)
{
  /*
     void *p2;
     p2=acl_malloc(sizeof(struct fgl_int_loc),"push_byte");
     memcpy(p2,ptr,sizeof(struct fgl_int_loc));
   */
  A4GL_push_param (ptr, (int) (DTYPE_TEXT + ENCODE_SIZE (sizeof (struct fgl_int_loc))));
}

/**
 * Called at run-time by the generated C code.
 * Its used to push a float to the parameters stack.
 *
 * @param p The float value to be pushed to the stack
 */
void
A4GL_push_float (float p)
{
  float *ptr;
  ptr = (float *) acl_malloc (sizeof (float), "push float");
  *ptr = p;
  A4GL_push_param (ptr, DTYPE_SMFLOAT + DTYPE_MALLOCED);
}



#define NUM_DIG(x)               ((x[0])&127 )
#define NUM_DEC(x)               ((x[1]))
#define NUM_BYTES(x)     (NUM_DIG(x)+OFFSET_DEC(x))

void
A4GL_push_dec_dec (fgldecimal * p, int ismoney, int size)
{
  int size_n;
  int ndig;
  int ndec;
  ndig = NUM_DIG (p->dec_data);
  ndec = NUM_DEC (p->dec_data);
  if (ndig < ndec)
    {
      A4GL_assertion (1, "Insufficent digits");
    }
  size_n = (ndig << 8) + ndec;
  A4GL_push_dec ((char *) p, ismoney, size_n);
}

/**
 * Called at run-time by the generated C code.
 * Its used to push a decimal value to the parameters stack.
 *
 * @param p A pointer to a char containing the decimal value in the string 
 * @param ismoney Flag that identifies if the decimal to be pusshed is money:
 *   - 0 : Its not money
 *   - Otherwise : Its money
 */
void
A4GL_push_dec (char *p, int ismoney, int size)
{
  char *ptr;
  int l;
  int d;
  int plen;
#ifdef DEBUG
  A4GL_debug ("push_dec with size=%x\n", size);
#endif

  if (p == 0)
    {
      if (ismoney)
	A4GL_push_param (0, DTYPE_MONEY + DTYPE_MALLOCED + ENCODE_SIZE (size));
      else
	A4GL_push_param (0, DTYPE_DECIMAL + DTYPE_MALLOCED + ENCODE_SIZE (size));
      return;

    }
  l = size >> 8;
  d = size & 255;



  if (p)
    {
      if (NUM_DIG (p) != l && NUM_DEC (p) != d)
	{
	  (void) A4GL_init_dec ((fgldecimal *) p, l, d);
	  A4GL_push_null (DTYPE_DECIMAL, size);
	  A4GL_setnull (DTYPE_DECIMAL, p, size);
	  return;
	}

      if (NUM_DIG (p) != l && NUM_DEC (p) != d)
	{
#ifdef DEBUG
	  A4GL_debug ("Failed to set to null");
#endif
	}
    }

  //plen= (p[0] & 127) + 2;
  plen = (int) sizeof (fgldecimal);

  ptr = (char *) acl_malloc (plen, "push dec");
  memcpy (ptr, p, (size_t) plen);
  if (ismoney)
    {
      A4GL_push_param (ptr, DTYPE_MONEY + DTYPE_MALLOCED + ENCODE_SIZE (size));
    }
  else
    {
      A4GL_push_param (ptr, DTYPE_DECIMAL + DTYPE_MALLOCED + ENCODE_SIZE (size));
    }
}

void
A4GL_push_decimal_str (char *p)
{
  fgldecimal d;
  int size;
  int ndig;
  int ndec;
  int decpos;
  char buff[2000];
  int l;
  strcpy (buff, p);

  ndig = 64;
  ndec = 32;
  A4GL_remove_trailing_zeros_and_leading_spaces (buff);
#ifdef DEBUG
A4GL_debug("-->%s\n", p);
#endif
  l = strlen (buff);
  if (l)
    {
      int a;
      decpos = -1;
      for (a = 0; a < l; a++)
	{
	  if (buff[a] == '.' || buff[a] == ',')
	    {
	      // we wont break here - we'll just keep looking
	      // because the ',' or '.' might be a thousands separator character
	      decpos = a;
	    }
	}
      if (decpos == -1)
	{
	  // Nothing found - strange given that it was a decimal...
	  ndig = l;
	  ndec = 0;
	}
      else
	{
	  ndec = l - decpos - 1;
	  ndig = l;
	}
      A4GL_assertion (ndec > ndig, "More decimal places than digits");
      if (ndec > 64)
	ndec = 64;
      if (ndig > 32)
	ndig = 32;
    }

  A4GL_init_dec (&d, ndig, ndec);
  A4GL_str_to_dec (buff, &d);

  ndig = NUM_DIG (d.dec_data);
  ndec = NUM_DEC (d.dec_data);
  if (ndig < ndec)
    {
      A4GL_assertion (1, "Insufficent digits");
    }
  size = (ndig << 8) + ndec;
  A4GL_push_dec_dec (&d, 0, size);

}

void
A4GL_push_double_str (char *p)
{
  double *ptr;
  char *cp;
  char *pdot;
  A4GL_push_decimal_str (p);	// push a decimal instead..
  return;
  pdot = strchr (p, '.');
  if (pdot == 0)
    {
      pdot = strchr (p, ',');
    }
  if (pdot)
    {
      int s;
      s = strlen (p) - (pdot - p);
      if (s > 5)
	{
	  A4GL_push_decimal_str (p);	// push a decimal instead..
	  return;
	}

    }
  ptr = (double *) acl_malloc (sizeof (double), "push_double");
  cp = A4GL_decstr_convert (p, a4gl_convfmts.posix_decfmt, a4gl_convfmts.scanf_decfmt, 1, 1, -1);
  *ptr = atof (cp);
  if (sscanf (cp, "%lf", ptr) != 1)
    {
#ifdef DEBUG
      A4GL_debug ("Conversion to double failed for string <%s>", cp);
#endif
      *ptr = 0;
    }
  free (cp);
  A4GL_push_param (ptr, DTYPE_FLOAT + DTYPE_MALLOCED);
}

/**
 * Called at run-time by the generated C code.
 * Its used to push a double to the parameters stack.
 *
 * @param p The double value to be pushed to the stack
 */
void
A4GL_push_double (double p)
{
  double *ptr;
  ptr = (double *) acl_malloc (sizeof (double), "push_double");
  *ptr = p;
#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("Push_double %18.18lf\n", p);
  }
#endif
  A4GL_push_param (ptr, DTYPE_FLOAT + DTYPE_MALLOCED);
}

/**
 * Called at run-time by the generated C code.
 * Its used to push a string to the parameter stack
 *
 * @param p A pointer to the string containing the characters
 * @param dtype Not Used
 * @param size The size of the string
 */
void
A4GL_push_chars (char *p, int dtype, int size)
{
  char *ptr;
  last_was_empty = 0;
#ifdef DEBUG
  A4GL_debug ("In A4GL_push_chars - '%s'\n", A4GL_null_as_null (p));
#endif
  ptr = (char *) A4GL_new_string_set ((int) strlen (p), p);
  //push_param(ptr,(DTYPE_CHAR+DTYPE_MALLOCED+ENCODE_SIZE(size)));
#ifdef DEBUG
  A4GL_debug ("Using dtype : %d", (DTYPE_CHAR + DTYPE_MALLOCED + ENCODE_SIZE (size)));
#endif
  A4GL_push_param (ptr, (DTYPE_CHAR + DTYPE_MALLOCED + ENCODE_SIZE (size)));
}


int
A4GL_was_last_empty ()
{
  return last_was_empty;
}

void
A4GL_clr_last_was_empty ()
{
  last_was_empty = 0;
}

void
A4GL_push_empty_char (void)
{
  char *ptr;
  char buff[2];
  char *p;
  buff[0] = 0;
  buff[1] = 0;
  p = buff;
  last_was_empty = 1;
//A4GL_push_char (buff);
  ptr = (char *) A4GL_new_string_set ((int) strlen (p), p);
  A4GL_push_param (ptr, (DTYPE_CHAR + DTYPE_MALLOCED + ENCODE_SIZE ((int) strlen (p))));

}


void A4GL_push_char_not_null(char *p) {
/* Whan A4GL_push_char is used - the data is read to determine if the string is NULL 
 * because a NULL string will have a 0 followed by a 0
 * whereas a non-null empty string will have a 0 followed by 1
 * Here - we know the data is coming from some C routine that doesn't know anything about DB 'NULLs'
 * so - we need to make sure we're pushing empty strings - not DBNULLs 
 * */
char buff[2]={0,1};
if (p==0) {
	A4GL_push_char(buff);
	return;
}
if (strlen(p)==0) {
	A4GL_push_char(buff);
	return;
}


A4GL_push_char(p);
}

/**
 * Called at run-time by the generated C code.
 * Its used to push a char string to the parameters stack.
 * All the string until the null terminated is pushed.
 *
 * @param p The string value to be pushed to the stack
 */
void
A4GL_push_char (char *p)
{
  char *ptr;
  last_was_empty = 0;
  A4GL_assertion (p == 0, "pointer was 0 in A4GL_push_char");
#ifdef DEBUG
  A4GL_debug ("Push char...'%s' (%p)", p, p);
#endif
  if (p[0] == 0 && p[1] != 0)
    {
#ifdef DEBUG
      A4GL_debug ("blank first not second ('%s')", p);
#endif
      ptr = (char *) A4GL_new_string_set ((int) strlen (p) + 1, p);
      ptr[0] = 0;
      ptr[1] = 1;
    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("not (blank first not second) '%s'", p);
#endif
      ptr = (char *) A4GL_new_string_set ((int) strlen (p), p);
    }
#ifdef DEBUG
  A4GL_debug ("Created ptr=%p", ptr);
#endif
  A4GL_push_param (ptr, (DTYPE_CHAR + DTYPE_MALLOCED + ENCODE_SIZE ((int) strlen (p))));
}

/**
 * Pop(s) the year, day and month from the stack, convert it into julian
 * and pushes this value to the stack.
 *
 * Used for MDY 4GL function!
 */
int
aclfgl_mdy (int n)
{
  int m, d, y;
  long z;
	if (n!=3) {
		A4GL_set_status(-3002,0);A4GL_pop_args(n);return -1;
	}
  y = A4GL_pop_int ();
  d = A4GL_pop_int ();
  m = A4GL_pop_int ();
  if (y <= 0)
    {
      A4GL_push_null (DTYPE_DATE, 0);
      return 1;
    }
  z = A4GL_gen_dateno (d, m, y);
  A4GL_push_date (z);
  return 1;
}

/**
 * Pops a long value from the stack, convert it to an hexadecimal string and
 * push it to the stack
 *
 * Used for 4GL HEX function
 */
int
aclfgl_hex (int n)
{
  long z;
  char buff[100];
  z = A4GL_pop_long ();
  SPRINTF1 (buff, "0x%x", (int) z);
  A4GL_push_char (buff);
  return 1;
}

/**
 * Pops a long value from the stack, gets the absolute values and 
 * push it to the stack.
 *
 * Used for 4GL ABS function.
 */
int
aclfgl_abs (int n)
{
  double p;
  if (n!=1) {
    A4GL_set_status(-3002,0);A4GL_pop_args(n);return -1;
  }
  p = A4GL_pop_double ();
  if (p < 0)
    p = (double) 0.0 - p;
  A4GL_push_double (p);
  return 1;
}

/**
 * Pops a long value from the stack, gets the mod values and 
 * push it to the stack.
 *
 * Used for 4GL MOD function.
 *
 */
void
A4GL_func_mod (void)
{
  long p;
  long p2;
  long res;


  p = A4GL_pop_long ();
  p2 = A4GL_pop_long ();
  res = p2 % p;
  A4GL_push_long (res);
}


int
aclfgl_ord (int n)
{
  unsigned char *s;
  if (n!=1) {
    A4GL_set_status(-3002,0);A4GL_pop_args(n);return -1;
  }
  s = (unsigned char *) A4GL_char_pop ();
  A4GL_push_long (s[0]);
  free (s);
  return 1;
}

/**
 *
 *
 * @todo Describe function
 */
int
aclfgl_root (int n)
{
  double p, p2, res;
  if (n!=2) {
    A4GL_set_status(-3002,0);A4GL_pop_args(n);return -1;
  }
  p = A4GL_pop_double ();
  p2 = A4GL_pop_double ();
  p = 1.0 / p;
  res = pow (p2, p);
  A4GL_push_double (res);
  return 1;
}

/**
 *
 *
 * @todo Describe function
 */
int
aclfgl_sqrt (int n)
{
  double p, p2, res;
#ifdef DEBUG
  A4GL_debug ("SQRT\n");
#endif
  if (n!=1) {
    A4GL_set_status(-3002,0);A4GL_pop_args(n);return -1;
  }
  p2 = A4GL_pop_double ();
#ifdef DEBUG
  A4GL_debug ("p2=%f\n", p2);
#endif
  p = (double) 1.0 / (double) 2.0;
  res = pow (p2, p);
  A4GL_push_double (res);
#ifdef DEBUG
  A4GL_debug ("--->%f\n", res);
#endif
  return 1;
}

/**
 *
 *
 * @todo Describe function
 */
void
A4GL_func_trunc (void)
{
  A4GL_exitwith ("trunc not implemented\n");
}

/**
 *
 *
 * @todo Describe function
 */
void
A4GL_func_round (void)
{
  A4GL_exitwith ("round not implemented\n");
}

/**
 *
 *
 * @todo Describe function
 */
void
A4GL_func_exp (void)
{
  A4GL_exitwith ("exp not implemented\n");
}

/**
 *
 *
 * @todo Describe function
 */
void
A4GL_func_logn (void)
{
  A4GL_exitwith ("logn not implemented\n");
}

/**
 *
 *
 * @todo Describe function
 */
void
A4GL_func_log10 (void)
{
  A4GL_exitwith ("log not implemented\n");
}



/**
 *
 *
 * @todo Describe function
 */
int
aclfgl_date (int n)
{
  long d;
  if (n!=1) {
    A4GL_set_status(-3002,0);A4GL_pop_args(n);return -1;
  }
  d = A4GL_pop_date ();
  A4GL_push_date (d);
  return 1;
}

int
aclfgl_time (int n)
{
  struct_dtime a;
  if (n!=1) {
    A4GL_set_status(-3002,0);A4GL_pop_args(n);return -1;
  }
  A4GL_pop_var2 (&a, 10, 0x46);
  A4GL_push_variable (&a, 0x46000a);
  return 1;
}

/**
 *
 *
 * @todo Describe function
 */
int
aclfgl_day (int n)
/* FIXME: why does this function have a parameter, if it's not going to be used?  it should always be 1 - because the fglcall will always pass it one...*/
{
  long d;
  int day, mn, yr;
  int d1;
  int s1;
  char *ptr1;
  if (n!=1) {
    A4GL_set_status(-3002,0);A4GL_pop_args(n);return -1;
  }
  A4GL_get_top_of_stack (1, &d1, &s1, (void *) &ptr1);
  d1 = d1 & DTYPE_MASK;

  if (d1 == DTYPE_DTIME)
    {
	struct_dtime dtd;
	A4GL_setnull(10,&dtd,0x33); /* Day to day */
 	A4GL_pop_var2(&dtd,10,0x33);
   	A4GL_push_variable(&dtd,0x33000a);
	return 1;
    }

  d = A4GL_pop_date ();
  if (A4GL_isnull (DTYPE_DATE, (void *) &d))
    {
      A4GL_push_null (DTYPE_INT, 0);
      return 1;
    }
  A4GL_get_date (d, &day, &mn, &yr);
  A4GL_push_int (day);
  return 1;
}

/**
 *
 *
 * @todo Describe function
 */
int
aclfgl_month (int n)		/* FIXME: why does this function have a parameter, if it's not going to be used?  - it should always be 1 */
{
  long d;
  int day, mn, yr;
  int d1;
  int s1;
  char *ptr1;
  if (n!=1) {
    A4GL_set_status(-3002,0);A4GL_pop_args(n);return -1;
  }
  A4GL_get_top_of_stack (1, &d1, &s1, (void *) &ptr1);
  d1 = d1 & DTYPE_MASK;

  if (d1==DTYPE_DTIME) {
	//
	struct_dtime dtd;
	A4GL_setnull(10,&dtd,0x22); /* month to month */
 	A4GL_pop_var2(&dtd,10,0x22);
   	A4GL_push_variable(&dtd,0x22000a);
	return 1;
  }


  d = A4GL_pop_date ();
  if (A4GL_isnull (DTYPE_DATE, (void *) &d))
    {
      A4GL_push_null (DTYPE_INT, 0);
      return 1;
    }
  A4GL_get_date (d, &day, &mn, &yr);
  A4GL_push_int (mn);
  
  return 1;

  return 0;
}

/**
 *
 *
 * @todo Describe function
 */
int
aclfgl_weekday (int n)		/* FIXME: why does this function have a parameter, if it's not going to be used? it should always be 1 */
{
  long d;
  int day, mn, yr;
  long d2;
  int d1;
  int s1;
  char *ptr1;
  if (n!=1) {
    A4GL_set_status(-3002,0);A4GL_pop_args(n);return -1;
  }
  A4GL_get_top_of_stack (1, &d1, &s1, (void *) &ptr1);
  d1 = d1 & DTYPE_MASK;

  d = A4GL_pop_date ();
  if (A4GL_isnull (DTYPE_DATE, (void *) &d))
    {
      A4GL_push_null (DTYPE_INT, 0);
      return 1;
    }
  A4GL_get_date (d, &day, &mn, &yr);
  d2 = A4GL_day_in_week (day, mn, yr);
  A4GL_push_long (d2);
  return 1;
}

/**
 *
 *
 * @todo Describe function
 */
int
aclfgl_year (int n)
{
  long d;
  int day, mn, yr;

  int d1;
  int s1;
  char *ptr1;
  if (n!=1) {
    A4GL_set_status(-3002,0);A4GL_pop_args(n);return -1;
  }
  A4GL_get_top_of_stack (1, &d1, &s1, (void *) &ptr1);
  d1 = d1 & DTYPE_MASK;

  if (d1 == DTYPE_DTIME)
    {
	struct_dtime dtd;
	A4GL_setnull(10,&dtd,0x11); /* year to year */
 	A4GL_pop_var2(&dtd,10,0x11);
   	A4GL_push_variable(&dtd,0x11000a);
	return 1;
    }


  d = A4GL_pop_date ();
  if (A4GL_isnull (DTYPE_DATE, (void *) &d))
    {
      A4GL_push_null (DTYPE_INT, 0);
      return 1;
    }
  A4GL_get_date (d, &day, &mn, &yr);
  A4GL_push_int (yr);


  return 1;
}

/**
 *
 *
 * @todo Describe function
 */
int
A4GL_func_clip (void)
{
  char *z;
  int d1;
  int s1;
  char *ptr1;
  int isnumeric = 0;

  A4GL_get_top_of_stack (1, &d1, &s1, (void *) &ptr1);
  d1 = d1 & DTYPE_MASK;

  switch (d1)
    {
    case DTYPE_SMINT:
    case DTYPE_INT:
    case DTYPE_DECIMAL:
    case DTYPE_FLOAT:
    case DTYPE_SMFLOAT:
    case DTYPE_MONEY:
      isnumeric = 1;
      break;
    default:
      isnumeric = 0;
    }

  if (A4GL_isno (acl_getenv ("NUMERICCLIPPED")))
    {
      isnumeric = 0;
    }

  if (isnumeric)
    {
      return 1;			// does nothing..
    }
  z = A4GL_char_pop ();

  if (strlen (z))
    {
      if (isnumeric)
	{
	  A4GL_lrtrim (z);
	}
      else
	{

	  A4GL_trim_not_nl (z);
	}
      if (strlen (z))
	{
	  A4GL_push_char (z);
	}
      else
	{
	  char buff[2];
	  buff[0] = 0;
	  buff[1] = 1;
#ifdef DEBUG
	  A4GL_debug ("Pushing a zero length non null string");
#endif
	  A4GL_push_char (buff);
#ifdef DEBUG
	  A4GL_debug ("Done that");
#endif
	}
    }
  else
    {
      A4GL_push_null (0, 0);
    }
  free (z);
  return 1;
}

/**
 *
 *
 * @todo Describe function
 */
void
A4GL_func_concat (void)
{
  char *z1;
  char *p1;
  char *p2;
  int a;
#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("func_concat -> Pop-ing chars");
  }
#endif
  p1 = A4GL_char_pop ();
  p2 = A4GL_char_pop ();
#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug (" CONCAT  '%s' & '%s'", A4GL_null_as_null (p1), A4GL_null_as_null (p2));
  }
#endif
#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("   copy %d %d ", strlen (p1), strlen (p2));
  }
#endif
  a = (int) strlen (p1) + (int) strlen (p2) + 1;
  z1 = A4GL_new_string (a);
  strcpy (z1, p2);
  strcat (z1, p1);
#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("Freeing");
  }
#endif
  acl_free (p1);
  acl_free (p2);
  A4GL_push_char (z1);
#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("concat returns -> %s", A4GL_null_as_null (z1));
  }
#endif
  free (z1);
}



/**
 *
 *
 * @todo Describe function
 */
double
A4GL_power (double a, double b)
{
  return 0;
}

/**
 *
 *
 * @todo Describe function
 */
void
A4GL_func_using ()
{
  int fmtlen;
  char *fmt;
  int dt;
  int s1;
  fgldecimal *ptr1;

  fmt = A4GL_char_pop ();
  A4GL_get_top_of_stack (1, &dt, NULL, NULL);
  dt &= DTYPE_MASK;

  if (A4GL_isyes (acl_getenv ("A4GL_TRIMUSINGFMT")))
    A4GL_trim (fmt);
  fmtlen = (int) strlen (fmt);

  switch (dt)
    {
    case DTYPE_DECIMAL:
    case DTYPE_MONEY:
      {
	char *z;
	char *p;
	char pold[2000];
	int a;
	int isneg = 0;
	z = A4GL_new_string (fmtlen + 1);
	A4GL_get_top_of_stack (1, &dt, &s1, (void **) &ptr1);
	p = acl_strdup (A4GL_dec_to_str (ptr1, 0));
	strcpy (pold, p);

	A4GL_drop_param ();
	// clean the string...
	//printf("p=%s\n",p);
	for (a = 0; a < strlen (p); a++)
	  {
	    if (p[a] >= '0' && p[a] <= '9')
	      continue;
	    if (p[a] == '.')
	      {
		p[a] = '.';
		continue;
	      }
	    if (p[a] == '-')
	      {
		p[a] = ' ';
		isneg++;
		continue;
	      }
	    p[a] = ' ';
	  }
	//printf("p=%s\n",p);
	a4gl_using_from_string (z, fmtlen, fmt, p, isneg);

	//a4gl_using (z, fmtlen, fmt, dbl);
#ifdef DEBUG
	A4GL_debug ("z=%s\n", A4GL_null_as_null (z));
#endif
	A4GL_push_char (z);
	acl_free (p);
	acl_free (z);
      }
      break;

    case DTYPE_BYTE:
    case DTYPE_SMINT:
    case DTYPE_INT:
    case DTYPE_SERIAL:
    case DTYPE_SMFLOAT:
    case DTYPE_FLOAT:
      {
	char *z;
	double dbl;
	A4GL_pop_param (&dbl, DTYPE_FLOAT, 0);
	z = A4GL_new_string (fmtlen + 1);
#ifdef DEBUG
	A4GL_debug ("Calling a4gl_using a=%lf fmt=%s ", dbl, fmt);
#endif

	a4gl_using (z, fmtlen, fmt, dbl);
#ifdef DEBUG
	A4GL_debug ("z=%s\n", A4GL_null_as_null (z));
#endif
	A4GL_push_char (z);
	acl_free (z);
      }
      break;
    case DTYPE_DATE:
      {
	long d;
	char *ptr;
	d = A4GL_pop_date ();
#ifdef DEBUG
	A4GL_debug ("Date using...%ld (%s)", d, A4GL_null_as_null (fmt));
#endif
	ptr = A4GL_using_date (d, fmt);
	// Did it convert nicely ? 
	if (ptr)
	  {
	    A4GL_push_char (ptr);
	  }
	else
	  {
	    char buff[200];
	    char *z;
	    // No - it didnt convert nicely..
	    z = A4GL_new_string (fmtlen + 1);
	    strcpy (z, fmt);

	    //@ENV FMTDATETONUMBER formats a date to number when using a numeric format
	    if (A4GL_isyes (acl_getenv ("FMTDATETONUMBER")))
	      {
		SPRINTF1 (buff, "%ld", d);
		a4gl_using_from_string (z, fmtlen, fmt, buff, 0);
	      }
	    A4GL_push_char (z);
	    acl_free (z);
	  }
      }
      break;
    case DTYPE_CHAR:
    case DTYPE_NULL:
    case DTYPE_DTIME:
    case DTYPE_TEXT:
    case DTYPE_VCHAR:
    case DTYPE_INTERVAL:
    case DTYPE_NVCHAR:
    case DTYPE_NCHAR:
    default:
      {				// I hope this piece of code will be unneeded some day, so I copy-pasted it...
#ifdef DEBUG
	A4GL_debug ("WARNING: USING handled old way, data type will be determined by the format string");
#endif

	if (strstr (fmt, "dd") || strstr (fmt, "mm") || strstr (fmt, "yy") ||
	    strstr (fmt, "DD") || strstr (fmt, "MM") || strstr (fmt, "YY"))
	  {
	    long d;
	    d = A4GL_pop_date ();
#ifdef DEBUG
	    A4GL_debug ("Date using...%ld (%s)", d, A4GL_null_as_null (fmt));
#endif
	    A4GL_push_char (A4GL_using_date (d, fmt));
	  }
	else
	  {
	    char *z;
	    double dbl;
	    A4GL_pop_param (&dbl, DTYPE_FLOAT, 0);
	    z = A4GL_new_string (fmtlen + 1);
#ifdef DEBUG
	    A4GL_debug ("Calling a4gl_using a=%lf fmt=%s ", dbl, fmt);
#endif
	    a4gl_using (z, fmtlen, fmt, dbl);
#ifdef DEBUG
	    A4GL_debug ("z=%s\n", A4GL_null_as_null (z));
#endif
	    A4GL_push_char (z);
	    acl_free (z);
	  }
      }
      break;
    }
  acl_free (fmt);
}


/***********************************************************************/
/*                          built in functions                         */
/***********************************************************************/

/**
 *
 *
 * @todo Describe function
 */
int
A4GL_find_function (char *a)
{
  int z;
  int found = 0;
  for (z = 0; builtin_funcs[z].fname[0] != 0; z++)
    {
      if (strcmp (a, builtin_funcs[z].fname) == 0)
	{
	  found = 1;
	  builtin_funcs[z].func ();
	  break;
	}
    }
  return found;
}


/**
 *
 *
 * @todo Describe function
 */
void
A4GL_push_dtime (struct A4GLSQL_dtime *p)
{
  char *ptr;
  struct A4GLSQL_dtime *d;
  ptr = (char *) acl_malloc (sizeof (struct A4GLSQL_dtime), "push_dtime");
  d = (struct A4GLSQL_dtime *) ptr;
  //d->stime=p->stime;
  //d->ltime=p->ltime;
  //memcpy(d->data,p->data,32);
  memcpy (d, p, sizeof (struct A4GLSQL_dtime));

  //A4GL_debug ("Pushing dtime block %x %x\n", p->stime, p->ltime);
  A4GL_push_param (ptr, DTYPE_DTIME + DTYPE_MALLOCED);
}

/**
 *
 *
 * @todo Describe function
 */
void
A4GL_push_interval (struct ival *p, int size)
{
  struct ival *ptr;
  struct ival *ival;
#ifdef DEBUG
  A4GL_debug ("in push interval");
#endif
  ptr = (struct ival *) acl_malloc (sizeof (struct ival), "push_ival");
  memset (ptr, 0, sizeof (struct ival));
  memcpy (ptr, p, sizeof (struct ival));

#ifdef DEBUG
  A4GL_debug ("Copied - %x %x", ptr->stime, ptr->ltime);
#endif

  A4GL_push_param (ptr, DTYPE_INTERVAL + DTYPE_MALLOCED + ENCODE_SIZE (size));

  ival = ptr;
}

/**
 *
 *
 * @todo Describe function
 */
void
A4GL_push_variable (void *ptr, int dtype)
{
int dont_push_null=0;
int dtype_masked;

  dtype_masked=dtype & DTYPE_MASK;

  if (dtype_masked==DTYPE_TEXT || dtype_masked==DTYPE_BYTE) {
	// We'll push the actual values onto the stack for blobs
	// even if they are null
	dont_push_null++;
  }

  if (A4GL_isnull (dtype_masked, ptr) && ! dont_push_null) // We'll normally just push a null of the required datatype...
    {
#ifdef DEBUG
      A4GL_debug ("Variable was null dtype=%d %x ptr=%p", dtype & DTYPE_MASK, dtype, ptr);
#endif
      A4GL_push_null (dtype & DTYPE_MASK, DECODE_SIZE (dtype));
      return;
    }

#ifdef DEBUG
  A4GL_debug ("In push variable dtype = %d (%x)", dtype, dtype);

  if ((dtype & DTYPE_MASK) == DTYPE_CHAR)
    {
#ifdef DEBUG
      A4GL_debug ("Value = '%s'\n", A4GL_null_as_null (ptr));
#endif
    }

  if (A4GL_isnull (dtype, ptr))
    {
#ifdef DEBUG
      A4GL_debug ("In push variable... ptr is null");
#endif
    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("In push variable... ptr is not null");
#endif
    }
#endif

#ifdef DEBUG
  {
    A4GL_debug ("Pushing variable %p dtype %d   %d", ptr, dtype & DTYPE_MASK, dtype);
  }
#endif

  if (A4GL_has_datatype_function_i (dtype, "COPY"))
    {
      void *(*function) (void *);
      void *nptr;
#ifdef DEBUG
      A4GL_debug ("HAS COPY FUNCTION...");
#endif
      function = A4GL_get_datatype_function_i (dtype, "COPY");
      nptr = function (ptr);
      A4GL_push_param (nptr, dtype + DTYPE_MALLOCED);
      return;
    }

#ifdef DEBUG
  A4GL_debug ("DOING SWITCH");
#endif
  switch (dtype & DTYPE_MASK)
    {

    case DTYPE_NCHAR:
    case DTYPE_NVCHAR:
    case DTYPE_CHAR:
      A4GL_push_char (ptr);
      return;

    case DTYPE_VCHAR:
      A4GL_push_char (ptr);
      return;
    case 1:
#ifdef DEBUG
      A4GL_debug ("SMALLINT= %d\n", *(short *) ptr);
#endif
      A4GL_push_int (*(short *) ptr);
      return;

case DTYPE_OBJECT:
      A4GL_push_objectID (*(long *) ptr);
      return;

    case 2:
#ifdef DEBUG
      A4GL_debug ("LONG");
#endif
      A4GL_push_long (*(long *) ptr);
      return;
    case 6:
#ifdef DEBUG
      A4GL_debug ("LONG");
#endif
      A4GL_push_long (*(long *) ptr);
      return;
    case 7:
#ifdef DEBUG
      A4GL_debug ("DATE");
#endif
      A4GL_push_date (*(long *) ptr);
      return;
    case 3:
#ifdef DEBUG
      A4GL_debug ("DOUBLE");
#endif
      A4GL_push_double (*(double *) ptr);
      return;
    case 5:
#ifdef DEBUG
      A4GL_debug ("DECIMAL");
#endif
      A4GL_push_dec (ptr, 0, dtype >> 16);
      return;
    case 8:
#ifdef DEBUG
      A4GL_debug ("MONEY");
#endif
      A4GL_push_dec (ptr, 1, dtype >> 16);
      return;
    case 4:
#ifdef DEBUG
      A4GL_debug ("FLOAT");
#endif
      A4GL_push_float (*(float *) ptr);
      return;
    case DTYPE_TEXT:
      push_text (ptr);
      return;

    case DTYPE_BYTE:
      push_byte (ptr);
      return;

    case DTYPE_DTIME:
#ifdef DEBUG
      A4GL_debug ("pushing dtime");
#endif
      A4GL_push_dtime (ptr);
      return;
    case DTYPE_INTERVAL:
#ifdef DEBUG
      A4GL_debug ("Interval - %d %d", dtype, DTYPE_INTERVAL);
#endif
      //printf("%x\n", dtype);
      A4GL_push_interval (ptr, dtype >> 16);
      return;
    }

#ifdef DEBUG
  A4GL_debug ("Couldnt process datatype %x", dtype);
#endif
  /* exitwith("Internal Error : Couldnt process datatype %x\n",dtype);  too many arguments to function `exitwith' */
  A4GL_exitwith ("Internal Error : Couldn't process datatype \n");


}


/* ============================== EOF =============================== */
