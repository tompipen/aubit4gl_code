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
# $Id: builtin_d.c,v 1.59 2005-01-29 17:29:42 mikeaubury Exp $
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
 * @todo Doxygen A4GL_comments to add to functions
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

int last_was_empty=0;

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
	{"",0,0,0}
*/
  {"", 0, 0, 0}
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
int aclfgl_ord(int n) ;
int aclfgl_time(int n);

static void push_byte (void *ptr);

void A4GL_push_double_str(char *p);
void A4GL_push_empty_char(void);

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
  *ptr = p;
  A4GL_push_param (ptr, DTYPE_INT + DTYPE_MALLOCED);
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
  A4GL_push_param (ptr, DTYPE_BYTE + ENCODE_SIZE (sizeof (struct fgl_int_loc)));
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
A4GL_push_dec (char *p, int ismoney,int size)
{
  char *ptr;
  int l;
  int d;
  int plen ;
  A4GL_debug("push_dec with size=%x\n",size);

  if (p==0) {
	if (ismoney) A4GL_push_param(0,DTYPE_MONEY+  DTYPE_MALLOCED+ENCODE_SIZE(size));
	else         A4GL_push_param(0,DTYPE_DECIMAL+DTYPE_MALLOCED+ENCODE_SIZE(size));
	return;
	
  }
  l=size>>8;
  d=size&255;

#define NUM_DIG(x)               ((x[0])&127 )
#define NUM_DEC(x)               ((x[1]))
#define NUM_BYTES(x)     (NUM_DIG(x)+OFFSET_DEC(x))


  if (p) {
  if (NUM_DIG(p)!=l&&NUM_DEC(p)!=d) {
  	A4GL_init_dec((fgldecimal *)p,l,d);
	A4GL_push_null(DTYPE_DECIMAL,size);
	A4GL_setnull(DTYPE_DECIMAL,p,size);
	return;
  }

  if (NUM_DIG(p)!=l&&NUM_DEC(p)!=d) {
	A4GL_debug("Failed to set to null");
  }
  }

  //plen= (p[0] & 127) + 2;
  plen=sizeof(fgldecimal);
  
  ptr = (char *) acl_malloc (plen, "push dec");
  memcpy (ptr, p, plen);
  if (ismoney)
    {
      A4GL_push_param (ptr, DTYPE_MONEY + DTYPE_MALLOCED+ENCODE_SIZE(size));
    }
  else
    {
      A4GL_push_param (ptr, DTYPE_DECIMAL + DTYPE_MALLOCED+ENCODE_SIZE(size));
    }
}


void A4GL_push_double_str(char *p) {
  double *ptr;
  ptr = (double *) acl_malloc (sizeof (double), "push_double");
  *ptr = atof(p);
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
    A4GL_debug ("Push_double %lf\n", p);
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
last_was_empty=0;
  A4GL_debug ("In A4GL_push_chars - %s\n", A4GL_null_as_null(p));
  ptr = (char *) A4GL_new_string_set (strlen (p), p);
  //push_param(ptr,(DTYPE_CHAR+DTYPE_MALLOCED+ENCODE_SIZE(size)));
  A4GL_debug ("Using dtype : %d",
	 (DTYPE_CHAR + DTYPE_MALLOCED + ENCODE_SIZE (size)));
  A4GL_push_param (ptr, (DTYPE_CHAR + DTYPE_MALLOCED + ENCODE_SIZE (size)));
}


int A4GL_was_last_empty() {
	return last_was_empty;
}

void A4GL_clr_last_was_empty() {
	last_was_empty=0;
}

void A4GL_push_empty_char(void) {
char *ptr;
char buff[2];
char *p;
buff[0]=0;
buff[1]=0;
p=buff;
last_was_empty=1;
//A4GL_push_char (buff);
  ptr = (char *) A4GL_new_string_set (strlen (p), p);
  A4GL_push_param (ptr, (DTYPE_CHAR + DTYPE_MALLOCED + ENCODE_SIZE (strlen (p))));

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
  last_was_empty=0;
  A4GL_assertion(p==0,"pointer was 0 in A4GL_push_char");
  if (p[0] == 0 && p[1] != 0)
    {
      ptr = (char *) A4GL_new_string_set (strlen (p) + 1, p);
      ptr[0] = 0;
      ptr[1] = 1;
    }
  else
    {
      ptr = (char *) A4GL_new_string_set (strlen (p), p);
    }
  A4GL_push_param (ptr, (DTYPE_CHAR + DTYPE_MALLOCED + ENCODE_SIZE (strlen (p))));
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
  y = A4GL_pop_int ();
  d = A4GL_pop_int ();
  m = A4GL_pop_int ();
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
  sprintf (buff, "0x%x", (int) z);
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
  p = A4GL_pop_double ();
  if (p < 0)
    p = 0 - p;
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


int aclfgl_ord(int n) {
unsigned char *s;
s=A4GL_char_pop();
A4GL_push_long(s[0]);
free(s);
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
  A4GL_debug ("SQRT\n");
  p2 = A4GL_pop_double ();
  A4GL_debug ("p2=%f\n", p2);
  p = (double) 1.0 / (double) 2.0;
  res = pow (p2, p);
  A4GL_push_double (res);
  A4GL_debug ("--->%f\n", res);
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
  d = A4GL_pop_date ();
  A4GL_push_date (d);
  return 1;
}

int aclfgl_time(int n) {
   struct_dtime a ;
   A4GL_pop_var2(&a,10,0x46);
   A4GL_push_variable(&a,0x46000a);
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
  d = A4GL_pop_date ();
  if (A4GL_isnull (DTYPE_DATE, (void *) &d)) {A4GL_push_null(DTYPE_INT,0); return 1;}
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
  d = A4GL_pop_date ();
  if (A4GL_isnull (DTYPE_DATE, (void *) &d)) {A4GL_push_null(DTYPE_INT,0); return 1;}
  A4GL_get_date (d, &day, &mn, &yr);
  A4GL_push_int (mn);
  return 1;
}

/**
 *
 *
 * @todo Describe function
 */
int
aclfgl_weekday (int n)		/* FIXME: why does this function have a parameter, if it's not going to be used? it should always be 1*/
{
  long d;
  int day, mn, yr;
  long d2;
  d = A4GL_pop_date ();
  if (A4GL_isnull (DTYPE_DATE, (void *) &d)) {A4GL_push_null(DTYPE_INT,0); return 1;}
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
  d = A4GL_pop_date ();
  if (A4GL_isnull (DTYPE_DATE, (void *) &d)) {A4GL_push_null(DTYPE_INT,0); return 1;}
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
  z = A4GL_char_pop ();

  if (strlen(z)) {
  	A4GL_trim (z);
	if (strlen(z)) {
  		A4GL_push_char (z);
	} else {
		char buff[2];
		buff[0]=0;
		buff[1]=1;
	A4GL_debug("Pushing a zero length non null string");
  		A4GL_push_char (buff);
	A4GL_debug("Done that");
	}
  } else {
	A4GL_push_null(0,0);
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
    A4GL_debug (" CONCAT  '%s' & '%s'", A4GL_null_as_null(p1), A4GL_null_as_null(p2));
  }
#endif
#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("   copy %d %d ", strlen (p1), strlen (p2));
  }
#endif
  a = strlen (p1) + strlen (p2) + 1;
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
    A4GL_debug ("concat returns -> %s", A4GL_null_as_null(z1));
  }
#endif
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
A4GL_func_using (void)
{
  int s;
  long d;
  char *z;
  char *fmt;
  double a;
  int f = 0;

  fmt = A4GL_char_pop ();

  if (strstr (fmt, "dd") || strstr (fmt, "mm") || strstr (fmt, "yy")) f = 1;
  if (strstr (fmt, "DD") || strstr (fmt, "MM") || strstr (fmt, "YY")) f = 1;

  if (f == 0)
    {
#ifdef DEBUG
      {
 A4GL_debug ("Number using");
      }
#endif
      A4GL_pop_param (&a, DTYPE_FLOAT, 0);
  if (A4GL_isyes(acl_getenv("TRIMUSINGFMT"))) {
      A4GL_trim (fmt);
  }
      s = strlen (fmt);
      z = A4GL_new_string (s+1);
	A4GL_debug("Calling a4gl_using");
      a4gl_using (z, s, fmt, a);
	A4GL_debug("z=%s\n",A4GL_null_as_null(z));
      A4GL_push_char (z);
    }
  else
    {
      d = A4GL_pop_date ();
#ifdef DEBUG
      {
 A4GL_debug ("Date using...%ld (%s)", d, A4GL_null_as_null(fmt));
      }
#endif

  if (A4GL_isyes(acl_getenv("TRIMUSINGFMT"))) {
      A4GL_trim (fmt);
  }
      A4GL_push_char (A4GL_using_date (d, fmt));
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
A4GL_push_interval (struct ival *p)
{
  struct ival *ptr;
  struct ival *ival;
char buff[256];
  ptr = (struct ival *) acl_malloc (sizeof (struct ival), "push_ival");
  memset(ptr,0,sizeof(struct ival));
  memcpy (ptr, p, sizeof (struct ival));
  A4GL_debug ("Copied - %x %x", ptr->stime, ptr->ltime);
  A4GL_push_param (ptr, DTYPE_INTERVAL + DTYPE_MALLOCED);


ival=ptr;
  sprintf (buff, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
           ival->data[0], ival->data[1], ival->data[2], ival->data[3],
           ival->data[4], ival->data[5],
           ival->data[6], ival->data[7],
           ival->data[8], ival->data[9],
           ival->data[10], ival->data[11],
           ival->data[12], ival->data[13],
           ival->data[14], ival->data[15],
           ival->data[16], ival->data[17], ival->data[18],
           ival->data[19], ival->data[20], ival->data[21],
           ival->data[22], ival->data[23]);
A4GL_debug("buff=%s",buff);

//debug_print_stack();
}

/**
 *
 *
 * @todo Describe function
 */
void
A4GL_push_variable (void *ptr, int dtype)
{


  if (A4GL_isnull(dtype&DTYPE_MASK,ptr)) {
		A4GL_debug("Variable was null dtype=%d %x ptr=%p",dtype&DTYPE_MASK,dtype,ptr);
		A4GL_push_null(dtype&DTYPE_MASK,DECODE_SIZE(dtype));
		return;
  }

  A4GL_debug ("In push variable dtype = %d (%x)", dtype, dtype);

  if ((dtype & 0xff) == 0)
    {
      A4GL_debug ("Value = '%s'\n", A4GL_null_as_null(ptr));
    }
  if (A4GL_isnull (dtype, ptr))
    {
      A4GL_debug ("In push variable... ptr is null");
    }
  else
    {
      A4GL_debug ("In push variable... ptr is not null");
    }

#ifdef DEBUG
  {
    A4GL_debug ("Pushing variable %p dtype %d   %d", ptr, dtype & DTYPE_MASK,
	   dtype);
  }
#endif

  if (A4GL_has_datatype_function_i (dtype, "COPY"))
    {
      void *(*function) (void *);
      void *nptr;
      A4GL_debug ("HAS COPY FUNCTION...");
      function = A4GL_get_datatype_function_i (dtype, "COPY");
      nptr = function (ptr);
      A4GL_push_param (nptr, dtype + DTYPE_MALLOCED);
      return;
    }

  A4GL_debug ("DOING SWITCH");
  switch (dtype & DTYPE_MASK)
    {
    case 0:
      A4GL_push_char (ptr);
      return;
    case DTYPE_VCHAR:
      A4GL_push_char (ptr);
      return;
    case 1:
      A4GL_debug ("SMALLINT= %d\n", *(short *) ptr);
      A4GL_push_int (*(short *) ptr);
      return;
    case 2:
      A4GL_debug ("LONG");
      A4GL_push_long (*(long *) ptr);
      return;
    case 6:
      A4GL_debug ("LONG");
      A4GL_push_long (*(long *) ptr);
      return;
    case 7:
      A4GL_debug ("DATE");
      A4GL_push_date (*(long *) ptr);
      return;
    case 3:
      A4GL_debug ("DOUBLE");
      A4GL_push_double (*(double *) ptr);
      return;
    case 5:
      	A4GL_debug ("DECIMAL");
      	A4GL_push_dec (ptr, 0,dtype>>16);
      return;
    case 8:
      A4GL_debug ("MONEY");
      A4GL_push_dec (ptr, 1,dtype>>16);
      return;
    case 4:
      A4GL_debug ("FLOAT");
      A4GL_push_float (*(float *) ptr);
      return;
    case DTYPE_TEXT:
    case DTYPE_BYTE:
      push_byte (ptr);
      return;

    case DTYPE_DTIME:
      A4GL_debug ("pushing dtime");
      A4GL_push_dtime (ptr);
      return;
    case DTYPE_INTERVAL:
		A4GL_debug("Interval - %d %d",dtype,DTYPE_INTERVAL);
      A4GL_push_interval (ptr);
      return;
    }

  A4GL_debug ("Couldnt process datatype %x", dtype);
  /* exitwith("Internal Error : Couldnt process datatype %x\n",dtype);  too many arguments to function `exitwith' */
  A4GL_exitwith ("Internal Error : Couldnt process datatype \n");


}


/* ============================== EOF =============================== */
