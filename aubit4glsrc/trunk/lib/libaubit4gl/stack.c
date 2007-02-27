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
# $Id: stack.c,v 1.168 2007-02-27 16:37:13 mikeaubury Exp $
#
*/

/**
 * @file
 * Stack comunication mechanism.
 *
 * This way of comunication is used to implement:
 *   - Arguments in function calls.
 *   - Return values.
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

#ifdef MSVC
#ifdef HAVE_SYS_TIME_H
#undef HAVE_SYS_TIME_H
#endif
#ifdef HAVE_UNISTD_H
#undef HAVE_UNISTD_H
#endif
#endif
#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#define AInt32 long
#define AInt16 short

//struct s_sid * A4GLSQL_prepare_select (struct BINDING *ibind, int ni, struct BINDING *obind, int no, char *s, int singleton);
//int A4GL_conversion_ok(int);
/*
=====================================================================
                    Platform specific definitions
=====================================================================
*/


#if (defined(WIN32) && ! defined(__CYGWIN__))
struct passwd
{
  char pw_name[20];
};
#endif


//static void A4GL_debug_print_stack_simple(char *msg) ;
/*
=====================================================================
                    Constants definitions
=====================================================================
*/

/* #define DIGIT_ALIGN_LEFT */

#define IGN 0xee
#define UC (unsigned char)
#define LOCAL_BINDINGS 20
int get_null_as_pad_string(void) ;
//void A4GL_process_stack_op_other (int d);
//int A4GL_stof (void *aa, void *zz, int sz_ignore);

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

//extern int errno;

#if defined(__hpux__)
#define BYTE_ALIGN_SET
#define BYTE_ALIGN_HP
#endif

#ifndef BYTE_ALIGN_SET
#define BYTE_ALIGN_x86
#endif 

#ifdef BYTE_ALIGN_x86
int nset[MAX_DTYPE][9] = {
  {0x0, 0x0, IGN, IGN, IGN, IGN, IGN, IGN, IGN}, 	// CHAR
  {0x0, 0x80, IGN, IGN, IGN, IGN, IGN, IGN, IGN}, 	// SMINT
  {0x0, 0x0, 0x0, 0x80, IGN, IGN, IGN, IGN, IGN}, 	// INT
  {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, IGN},// FLOAT
  {0xff, 0xff, 0xff, 0xff, IGN, IGN, IGN, IGN, IGN}, 	// SMFLOAT
  {IGN, IGN, 0x00, 0x00, 0x0, 0x0, IGN, IGN, IGN}, 	// DECIMAL
  {0x0, 0x0, 0x0, 0x80, IGN, IGN, IGN, IGN, IGN}, 	// SERIAL
  {0x0, 0x0, 0x0, 0x80, IGN, IGN, IGN, IGN, IGN}, 	// DATE
  {IGN, IGN, 0x00, 0x00, 0x0, 0x0, IGN, IGN, IGN}, 	// MONEY
  {IGN, IGN, IGN, IGN, IGN, IGN, IGN, IGN, IGN},  	// EMPTY
  {IGN, IGN, 0x0, 0x0, 0xff, 0xff, 0x0, 0x0, IGN}, 	// DTIME
  {IGN, IGN, IGN, IGN, IGN, IGN, IGN, IGN, IGN}, 	// BYTE
  {IGN, IGN, IGN, IGN, IGN, IGN, IGN, IGN, IGN}, 	// TEXT
  {0x0, IGN, IGN, IGN, IGN, IGN, IGN, IGN, IGN}, 	// VCHAR
  {IGN, IGN, 0x0, 0x0, 0xff, 0xff, 0x0, 0x0, IGN} 	// INTERVAL
};
#else
int nset[MAX_DTYPE][9] = {
  {0x0, 0x0, IGN, IGN, IGN, IGN, IGN, IGN, IGN}, 	// CHAR
  {0x80, 0x0, IGN, IGN, IGN, IGN, IGN, IGN, IGN}, 	// SMINT
  {0x80, 0x0, 0x0, 0x00, IGN, IGN, IGN, IGN, IGN}, 	// INT
  {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, IGN},// FLOAT
  {0xff, 0xff, 0xff, 0xff, IGN, IGN, IGN, IGN, IGN}, 	// SMFLOAT
  {IGN, IGN, 0x00, 0x00, 0x0, 0x0, IGN, IGN, IGN}, 	// DECIMAL
  {0x80, 0x0, 0x0, 0x00, IGN, IGN, IGN, IGN, IGN}, 	// SERIAL
  {0x80, 0x0, 0x0, 0x00, IGN, IGN, IGN, IGN, IGN}, 	// DATE
  {IGN, IGN, 0x00, 0x00, 0x0, 0x0, IGN, IGN, IGN}, 	// MONEY
  {IGN, IGN, IGN, IGN, IGN, IGN, IGN, IGN, IGN},  	// EMPTY
  {IGN, IGN, 0x0, 0x0, 0xff, 0xff, 0x0, 0x0, IGN}, 	// DTIME
  {IGN, IGN, IGN, IGN, IGN, IGN, IGN, IGN, IGN}, 	// BYTE
  {IGN, IGN, IGN, IGN, IGN, IGN, IGN, IGN, IGN}, 	// TEXT
  {0x0, IGN, IGN, IGN, IGN, IGN, IGN, IGN, IGN}, 	// VCHAR
  {IGN, IGN, 0x0, 0x0, 0xff, 0xff, 0x0, 0x0, IGN} 	// INTERVAL
};

#endif
static int A4GL_null_other(char *buff,int type) ;

char *
A4GL_char_pop_size (int *sz);
/**
 * Parameter definition type
 */
struct param
{
  void *ptr;
  int dtype;
  int size;
};

/**
 * The parameter stack.
 *
 * @todo Validate if what we want is a ** and not a * and if so make the change
 */
struct param *params = 0;

/**
 * The nuber of elements in the parameter stack
 */
int params_cnt = 0;
int alloc_params_cnt = 0;


/*
 * IN & EXISTS with SQL required some bindings ....
 */
static int local_binding_cnt = 0;
static struct BINDING *local_binding[LOCAL_BINDINGS];
static int num_local_binding[LOCAL_BINDINGS];

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

/* see a4gl_stack.h */


//void *A4GL_pop_binding (int *n);
//void          A4GL_push_ascii                              (void);
//void          A4GL_push_current                    (int a, int b);
//void          A4GL_push_time                               (void);
//void          A4GL_push_disp_bind                  (struct BINDING *b, int n);
//int A4GL_chk_params (struct BINDING *b, int nb, struct BINDING *o, int no);
//static int A4GL_isparamdate (void);
//void        A4GL_set_init                          (struct BINDING *b, int n);
//int A4GL_push_binding (void *ptr, int num);
void dif_add_bind (struct bound_list *list, void *dptr, int dtype, int size);
void dif_add_bind_date (struct bound_list *list, long a);
void dif_add_bind_smint (struct bound_list *list, int a);
void dif_add_bind_smint_ptr (struct bound_list *list, short *a);
void dif_add_bind_dbl_ptr (struct bound_list *list, double *a);
void dif_add_bind_int (struct bound_list *list, long a);
void dif_add_bind_float (struct bound_list *list, double a);
void dif_add_bind_smfloat (struct bound_list *list, float a);
void dif_add_bind_char (struct bound_list *list, char *a);
void dif_free_bind (struct bound_list *list);
void dif_print_bind (struct bound_list *list);
long dif_pop_bind_int (struct bound_list *list);
char *dif_pop_bind_char (struct bound_list *list);
int dif_pop_bind_smint (struct bound_list *list);
int dif_pop_bind_float (struct bound_list *list);
int dif_pop_bind_smfloat (struct bound_list *list);
int dif_pop_bind_dec (struct bound_list *list);
int dif_pop_bind_money (struct bound_list *list);
void A4GL_set_escape (char *s);
int aclfgl_aclfgl_byte_as_str(int n);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 * Pop a boolean value from the stack.
 *
 * @return The boolean value.
 */
int
A4GL_pop_bool (void)
{
  long ptr;
  ptr = 0;
#ifdef DEBUG
  A4GL_debug ("8 Popping boolean..");
#endif

  //debug_print_stack();


  ptr = A4GL_pop_long ();

#ifdef DEBUG
  A4GL_debug("pop bool : ptr=%x\n",ptr);
#endif

  if (A4GL_isnull(DTYPE_INT,(void *)&ptr)) {
		A4GL_debug("8 Null can't be true..");
		return 0;
  }

#ifdef DEBUG
  A4GL_debug ("8 Popping boolean gets %d %x", ptr, ptr);
#endif

  if (ptr != 0 && ptr != 1)
    {
      A4GL_debug ("1 SERIOUS PROBLEM ????? ptr=%d",ptr);
      A4GL_debug_print_stack ();
    }
  if (ptr)
    return 1;
  return 0;
}

/**
 * Pop an integer value from the stack
 *
 * @return The value poped.
 */
short
A4GL_pop_int (void)
{
  short ptr;
  int b;
  b = A4GL_pop_param (&ptr, DTYPE_SMINT, 0);
#ifdef DEBUG
  A4GL_debug ("8 pop_int b=%d\n", b);
#endif
  ptr = ptr & 0xffff;
  return ptr;
}

/**
 * Pop a long value from the stack.
 *
 * @return The long value poped.
 */
long
A4GL_pop_long (void)
{
  long ptr;
  A4GL_pop_param (&ptr, DTYPE_INT, 0);
  return ptr;
}

/**
 * Pop a date value from the stack.
 *
 * @return The date value poped.
 */
long
A4GL_pop_date (void)
{
  long ptr;
  A4GL_pop_param (&ptr, DTYPE_DATE, 0);
  return ptr;
}

/**
 * Pop a float value from the stack.
 *
 * @return The date value poped.
 */
float
A4GL_pop_float (void)
{
  float ptr;
  A4GL_pop_param (&ptr, DTYPE_SMFLOAT, 0);
  return ptr;
}

/**
 * Pop a double value from the stack.
 *
 * @return The date value poped.
 */
double
A4GL_pop_double (void)
{
  double ptr;
  A4GL_pop_param (&ptr, DTYPE_FLOAT, 0);
  return ptr;
}

/**
 * Pop a double value from the stack.
 *
 * @return The date value poped.
 */
void
A4GL_pop_doubleinto (double *ptr)
{
  A4GL_pop_param (&ptr, DTYPE_FLOAT, 0);
}
/**
 * Pop a double value from the stack.
 *
 * @return The date value poped.
 */
void A4GL_pop_into_double (double *d)
{
  A4GL_pop_param (d, DTYPE_FLOAT, 0);
  return ;
}



double A4GL_pop_double_null_as_zero(void ) {
  double ptr;
  A4GL_pop_param (&ptr, DTYPE_FLOAT, 0);
  if (A4GL_isnull(DTYPE_FLOAT,(void *)&ptr)) return 0;
  return ptr;
}

void A4GL_pop_into_double_null_as_zero(double *d ) {
  A4GL_pop_param (d, DTYPE_FLOAT, 0);
  if (A4GL_isnull(DTYPE_FLOAT,(void *)d)) *d=0.0;
}



/**
 *
 *
 * @return
 */
int
A4GL_pop_var (void *p, int d)
{
  int z;
  int s;
  s = DECODE_SIZE (d);
#ifdef DEBUG
  A4GL_debug ("8 pop variable type %d %x (%d) \n", d, d, s);
#endif
  z = A4GL_pop_param (p, d, s);
#ifdef DEBUG
  A4GL_debug ("9 z=%d", z);
#endif
  if (((z) != (1)))
    {
      A4GL_exitwith ("Error in conversion");
      if (A4GL_isyes(acl_getenv("NO_CONV_ERR"))) { A4GL_debug("Ignoreing"); a4gl_status=0; }
#ifdef DEBUG
      A4GL_debug ("1 pop_var: error in conversion %d\n", z);
#endif
      return 0;
    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("8 pop_var: conversion ok");
#endif
    }
  return z;
}

/**
 *
 *
 * @return
 */
int
A4GL_pop_var2 (void *p, int d, int s)
{
  int z;
  char *pl;

#ifdef DEBUG
  //A4GL_debug ("8 pop_var2 : ptr=%p dtype=%d size=%d", p, d, s);
#endif

  if (d == 0)
    {
      pl = A4GL_new_string (s);
      z = A4GL_pop_param (pl, d, s);
#ifdef DEBUG
      A4GL_debug ("8 z=%d\n", z);
#endif
      if (z == 1)
	{
#ifdef DEBUG
	  A4GL_debug ("8 zconv ok");
#endif
	}
      if (z != 1)
	{
#ifdef DEBUG
	  A4GL_debug ("8 zconv bad");
#endif
	}
      if (((z) != (1)))
	{
#ifdef DEBUG
	  A4GL_debug ("8 pop_var2: error in conversion %d d=0 s=%d\n", z, s);
#endif
	}
#ifdef DEBUG
      A4GL_debug ("9 Copying string '%s' to p", A4GL_null_as_null(pl));
#endif
      strncpy ((char *) p, pl,s);
	free(pl);
      pl = (char *) p;
      pl[s] = 0;		/* changed from s+1 to s */
      return z;
    }

  z = A4GL_pop_param (p, d, s);
  if (z != 1)
    {
      A4GL_exitwith ("Error in conversion");
      if (A4GL_isyes(acl_getenv("NO_CONV_ERR"))) { 
		A4GL_debug("Ignoreing"); 
		//if (d!=DTYPE_SMINT) {
			a4gl_status=0; 
		//}
		z=1; 
		A4GL_setnull(d&DTYPE_MASK,p,s); 
	}
#ifdef DEBUG
      A4GL_debug ("2 pop_var2 - error in conversion %d d=%d s=%d\n", z, d, s);
#endif
    }
  return z;
}


/**
 *
 *
 * @return
 */
double
A4GL_ret_var (void *p, int d)
{
#ifdef DEBUG
  /* {DEBUG} */ A4GL_debug ("8 ret_var - %p %d", p, d);
#endif
  return A4GL_pop_param (&p, d, 0);
}

/**
 *
 *
 * @return
 */
int
A4GL_pop_char (char *z, int size)
{
  int a;
  memset(z,0,size);
  a = A4GL_pop_param (z, DTYPE_CHAR, size);
#ifdef DEBUG
  /* {DEBUG} */ A4GL_debug ("8 pop_char returns char ='%s'", A4GL_null_as_null(z));
#endif
  return a;
}




int dtype_alloc_char_size[] = {
  /*datatypes
     0  1  2  3 4 5  6  7  8  9 10 11 12 13 14 15 */
  0, 6, 11, 14, 14, 16, 12, 10, 16, 0, 40, 40, 40, 40, 40, 40
};



char *A4GL_char_pop(void ) {
	int a;
	return A4GL_char_pop_size(&a);
}

/**
 * create a perfectly sized string to hold the info 
 */
char *
A4GL_char_pop_size (int *sz)
{
  int a;
  char *s;
  int f;

#ifdef DEBUG
  A4GL_debug("A4GL_char_pop...");
#endif
  if (params_cnt <= 0)
    {
      A4GL_debug ("Stack got corrupted");
      A4GL_assertion (1, "Stack got corrupted");
      A4GL_fgl_die (1);
    }

  if ((params[params_cnt - 1].dtype & DTYPE_MASK) != DTYPE_CHAR)
    {
      f = params[params_cnt - 1].dtype & DTYPE_MASK;

      if (A4GL_has_datatype_function_i (f, ">STRING"))
	{
	  char *(*function) (void *, int , char *, int);
	  A4GL_debug ("Calling >STRING for datatype");
	  function = A4GL_get_datatype_function_i (f, ">STRING");
	  s = function (params[params_cnt - 1].ptr, params[params_cnt - 1].size,0, 0);
	  A4GL_drop_param ();
	}
      else
	{
	  s = A4GL_new_string (dtype_alloc_char_size[f]);
	if (f==DTYPE_DATE) {
		static int len=0;
		if (len==0) {
			if (strchr(A4GL_get_dbdate(),'4')) {
				len=10;
			} else {
				len=8;
			}
		}
	  	A4GL_pop_char (s, len);
	} else {
	  	A4GL_pop_char (s, dtype_alloc_char_size[f]);
	}
	  if (dtype_alloc_char_size[f]==40) {A4GL_trim(s);}
	}

      //trim (s);
#ifdef DEBUG
      A4GL_debug ("8 char_pop - pushing char : '%s'", A4GL_null_as_null(s));
#endif
      A4GL_push_char (s);
      params[params_cnt - 1].size = strlen (params[params_cnt - 1].ptr);
    }				/* if last entry is not a character string make it one */
  else
    {
#ifdef DEBUG
	    A4GL_debug("Looks like it was a string..'%s'",params[params_cnt - 1].ptr);
#endif
	if (params[params_cnt - 1].ptr)
      		params[params_cnt - 1].size = strlen (params[params_cnt - 1].ptr);
    }


  a = params[params_cnt - 1].size;
  s = A4GL_new_string (a);
#ifdef DEBUG
  A4GL_debug("a=%d\n",a);
#endif
  if (a==0) s[1]=1;
  *sz=a;
  A4GL_pop_param (s, DTYPE_CHAR, a);
#ifdef DEBUG
  A4GL_debug("A4GL_char_pop - returning '%s' (%s)\n",s,(A4GL_isnull(DTYPE_CHAR,s)?"null":"not null"));
#endif

  return s;
}

/**
 *
 *
 * @return
 */
int
A4GL_pop_param (void *p, int d, int size)
{
  int b;
  int d1,s1;
  void *ptr1;
  char *ptr;

A4GL_conversion_ok(1);
  A4GL_assertion(p==0,"No pointer to pop into");
  A4GL_get_top_of_stack (1, &d1, &s1, (void **) &ptr1);
	
  params_cnt--;

  if (params_cnt < 0)
    {
      A4GL_debug ("1 Stack got corrupted");
      A4GL_assertion (1, "Stack got corrupted");
      A4GL_fgl_die (1);
    }


  if (ptr1==0) {
		A4GL_conversion_ok(1);
#ifdef DEBUG
		A4GL_debug("ptr1=0");
#endif
		A4GL_setnull(d&DTYPE_MASK,p,size);
		return 1;
  } else {
  	if (A4GL_isnull(d1,ptr1)) {
		A4GL_conversion_ok(1);
#ifdef DEBUG
		A4GL_debug("Isnull\n");
#endif
		A4GL_setnull(d&DTYPE_MASK,p,size);
		b=1;
  	} else {
		//A4GL_debug("Doing conv");
		A4GL_conversion_ok(1);
  		b = A4GL_conv (params[params_cnt].dtype & DTYPE_MASK, params[params_cnt].ptr, d & DTYPE_MASK, p, size);
		
		if (b==0 ) {
#ifdef DEBUG
			A4GL_debug("d=%d d=%d",params[params_cnt].dtype & DTYPE_MASK, d & DTYPE_MASK);
#endif
			if ((d & DTYPE_MASK) == DTYPE_SMINT)  {
				// Do nothing 
				A4GL_conversion_ok(0);
				A4GL_debug("Bad conversion");
		
				if (A4GL_isyes(acl_getenv("NO_CONV_ERR"))) { 
						A4GL_debug("Ignoreing"); a4gl_status=0; 
				}
			} else {
				A4GL_conversion_ok(0);
				A4GL_debug("Bad conversion");
		
				if (A4GL_isyes(acl_getenv("NO_CONV_ERR"))) { 
						A4GL_debug("Ignoreing"); a4gl_status=0; 
				}
			}

		}
  	}
  }
 //A4GL_debug("99 After A4GL_conv");


  if (params[params_cnt].dtype & DTYPE_MALLOCED)
    {
      if ((params[params_cnt].dtype & DTYPE_MASK) != DTYPE_CHAR)
	{
	  //A4GL_debug ("7 Not Char.. %p", params[params_cnt].ptr);
	  acl_free (params[params_cnt].ptr);
	}
      else
	{
	  ptr = params[params_cnt].ptr;
	  //A4GL_debug ("7 Not Char..%p", ptr);
	  acl_free (ptr);
	}
    }
 //A4GL_debug("99 return %d",b);
  return b;
}

/**
 * Pop parameters from a function call
 *
 * @param b
 * @param n
 */
void
A4GL_pop_params (struct BINDING *b, int n)
{
  int a;
  for (a = n - 1; a >= 0; a--)
    {
	int dtype;
	dtype=b[a].dtype & DTYPE_MASK;
	if (dtype==DTYPE_CHAR || dtype==DTYPE_VCHAR) {
		if ( b[a].start_char_subscript==0 && b[a].end_char_subscript==0)  {
      			A4GL_pop_param (b[a].ptr, b[a].dtype, b[a].size);
		} else {
			if (b[a].start_char_subscript==b[a].end_char_subscript) {
				a4gl_let_substr(b[a].ptr,b[a].dtype+ENCODE_SIZE(b[a].size),b[a].start_char_subscript,0);
			} else {
				a4gl_let_substr(b[a].ptr,b[a].dtype+ENCODE_SIZE(b[a].size),b[a].start_char_subscript,b[a].end_char_subscript,0);
			}
		}
	} else {
      		A4GL_pop_param (b[a].ptr, b[a].dtype, b[a].size);
	}
    }
}

/**
 *
 *
 * @return
 */
void
A4GL_push_params (struct BINDING *b, int n)
{
  int a;
  for (a = 0; a < n; a++)
    {
      A4GL_push_param (b[a].ptr, b[a].dtype);
    }
}



/*  *******************************************************************/
/*  pushes */

/**
 *
 * @param n
 * @return 
 */
void *
A4GL_pop_binding (int *n)
{
  local_binding_cnt--;
  *n = num_local_binding[local_binding_cnt];
  return local_binding[local_binding_cnt];
}

/**
 * Push a parameter in to the parameter stack.
 *
 * The parameter stack is a global pointer to a struct param array
 * dynamically alocated
 *
 * @param p
 * @param d
 *
 */
void
A4GL_push_param (void *p, int d)
{
  double doublea = 0, doubleb = 0;
  char *c1;
  char *c2;
  int size;
  int n1, n2;
  int i1, i2;
  char buff[400];
  int zzz;

  int doing_dt_or_int = 0;
  int d1;
  int d2;
  int s1;
  int s2;
  void *ptr1;
  void *ptr2 = 0;
  int dtype_1 = -1;
  int dtype_2 = -1;
  int dn1;
  int dn2;
  int ob;



  size = DECODE_SIZE (d);
  d = d & 0xffff;
  A4GL_debug("50 push_param %p %d size=%d",p,d,size);

  if (params == 0)
    {
	int nbytes=0;
	nbytes=sizeof (struct param) * NUM_PARAM,
      A4GL_debug ("20 Assign stack : %d bytes",nbytes);
      params = (struct param *) acl_malloc (nbytes, "Assign stack");
      alloc_params_cnt = NUM_PARAM;
    }

  if (params != 0 && params_cnt >= alloc_params_cnt)
    {
      A4GL_debug ("15 Allocating more space for stack\n");
      alloc_params_cnt += NUM_PARAM;
      params = (struct param *) realloc (params,
					 sizeof (struct param) *
					 alloc_params_cnt);
    }

  if (params != 0 && params_cnt < alloc_params_cnt - NUM_PARAM
      && params_cnt > 1)
    {
      A4GL_debug ("15 Allocating less space for stack\n");
      alloc_params_cnt -= NUM_PARAM;
      params = (struct param *) realloc (params,
					 sizeof (struct param) *
					 alloc_params_cnt);
    }

A4GL_debug("51 Allocated stack space %d %d",d,OP_MASK_BASE);


  if (d == FUNCTION_OP)
    {
      A4GL_find_function ((char *) p);
      return;
    }

  if (d < OP_MASK_BASE)
    {

A4GL_debug("51 Have data");
#ifdef DEBUG
      /*  A4GL_debug ("7 Adding ptr=%p d=%d (%d masked) to stack %d\n", p, d, d & DTYPE_MASK, params_cnt); */
#endif
      if (params_cnt >= alloc_params_cnt)
	{
	  A4GL_exitwith ("Stack overflow");
	  A4GL_chk_err (-1, "Internal");
	}


      params[params_cnt].ptr = p;
      params[params_cnt].dtype = d;

      if ((d & DTYPE_MASK) == 0 && size == 0)
	{
		if (p) {
	  		size = strlen (p);
		} else {
			size=0;
		}
#ifdef DEBUG
	  A4GL_debug ("7 Defaulting size");
#endif
	}

      if ((d & DTYPE_MASK) == 0)
	{
#ifdef DEBUG
 {
	char *cp;
	cp=(char *)p;
	if (cp) {
	  A4GL_debug ("40 Adding string '%s' size %d %d %d", A4GL_null_as_null(p), size,cp[0],cp[1]);
	} else {
	  A4GL_debug ("40 Adding string '%s' size %d cp=null", A4GL_null_as_null(p), size);
	}
}
#endif
	}

      params[params_cnt].size = size;
      params_cnt++;
	A4GL_debug("99 All done..");
      return;
    }

  n1 = 0;
#ifdef DEBUG
  A4GL_debug ("7 params_cnt=%d\n", params_cnt);
#endif

  dn1=0;
  dn2=0;

  if (params_cnt > 0)
    {
      dtype_1 = params[params_cnt - 1].dtype;
      if (A4GL_isnull (params[params_cnt - 1].dtype, params[params_cnt - 1].ptr))
	{

	dn1=params[params_cnt - 1].dtype;

	  /* I don't remember what this is for - so I'm getting shot for now */
	  //zzz = (params[params_cnt - 1].dtype & DTYPE_MASK) + (strlen (params[params_cnt - 1].ptr)) + (params[params_cnt - 1].size);

	  zzz = 1;

	  A4GL_debug ("9 zzz=%d\n", zzz);

	  if (zzz == 0)
	    {
	      n1 = 0;
	    }
	  else
	    {
	      n1 = 1;
	    }
	}
      else
	n1 = 0;
    }

  n2 = 0;
#ifdef DEBUG
  A4GL_debug ("9 Checking 2nd");
#endif

  if (params_cnt > 1)
    {
      dtype_2 = params[params_cnt - 2].dtype;
      if (A4GL_isnull (params[params_cnt - 2].dtype, params[params_cnt - 2].ptr))
	{
	  dn2=params[params_cnt - 2].dtype;
	  zzz = 1;

	  if (zzz == 0)
	    n2 = 0;
	  else
	    n2 = 1;
	}
      else
	n2 = 0;
    }

#ifdef DEBUG
  A4GL_debug ("7 Checked %d %d", n1, n2);
#endif


  /*
     Have a look see if this condition
     is specifically handled
   */

  if (dtype_2 == -1)
    dtype_2 = dtype_1;

  if (dtype_1 != -1)
    {
      void (*function) (int);
#ifdef DEBUG
      A4GL_debug ("7 Calling OP function ?");
#endif

      function = 0;


#ifdef DEBUG
      if (d==OP_EQUAL) { 
	      	
	      	A4GL_debug("OP_EQUAL"); 
      }

#endif


/* 
	First - lets see if we have a OP_MATH function available
*/
      switch (d)
	{
	case OP_ADD:
	case OP_SUB:
	case OP_MULT:
	case OP_DIV:
	case OP_POWER:
	case OP_MOD:
	case OP_LESS_THAN:
	case OP_GREATER_THAN:
	case OP_LESS_THAN_EQ:
	case OP_GREATER_THAN_EQ:
	case OP_EQUAL:
	case OP_NOT_EQUAL:

       function = A4GL_find_op_function (dtype_2, dtype_1, OP_MATH);


       if (function==0 && ((dtype_1 & DTYPE_MASK) == DTYPE_CHAR || (dtype_1 & DTYPE_MASK) == DTYPE_VCHAR )) {
		int dx;
		int sx;
#ifdef DEBUG

		A4GL_debug("Using a string for the second part : %s op=%d  ",params[params_cnt - 1].ptr,d);
#endif
		A4GL_whats_in_a_string(params[params_cnt - 1].ptr,&dx,&sx);
	
	}

	}




      if (function == 0)
	{
	  /* Nope - try a specific */
	  function = A4GL_find_op_function (dtype_2, dtype_1, d);
	}


      if (function)
	{
	  /* We've got something to play with */
#ifdef DEBUG
	  A4GL_debug ("7 Calling specified function for %d %d, %d", dtype_1 & DTYPE_MASK, dtype_2 & DTYPE_MASK, d);
#endif
	  function (d);
#ifdef DEBUG
	  A4GL_debug ("7 Called function returning");
#endif
	  return;
	}

    }

#ifdef DEBUG
  A4GL_debug("No specific function for this - try the default - dtype1=%d dtype2=%d",dtype_1 & DTYPE_MASK,dtype_2 & DTYPE_MASK);

#endif
  


  if ((d) == (OP_ISNULL))
    {

#ifdef DEBUG
      A4GL_debug ("7 d=%d OP_ISNULL=%d", d, OP_ISNULL);
      A4GL_debug ("10 Checking ISNULL");
#endif
      A4GL_drop_param ();
#ifdef DEBUG
      A4GL_debug ("16 Dropped param");
#endif

      if (n1)
	{
#ifdef DEBUG
	  A4GL_debug ("7 Yep");
#endif
	  A4GL_push_int (1);
	}
      else
	{
#ifdef DEBUG
	  A4GL_debug ("7 Nope");
#endif
	  A4GL_push_int (0);
	}
#ifdef DEBUG
      A4GL_debug ("15 Finished..");
#endif
      return;
    }

  if (d == OP_ISNOTNULL)
    {
      A4GL_pop_char (buff, 79);
      if (n1) A4GL_push_int (0);
      else A4GL_push_int (1);
      return;
    }

  if (d == OP_IN || d == OP_NOTIN)
    {
      int a;
      int ok = 0;
      int eql;
#ifdef DEBUG
	A4GL_debug("OP IN\n");
#endif
      a = A4GL_pop_int ();
      while (a >= 1)
	{
	  A4GL_get_top_of_stack (a + 1, &d1, &s1, (void **) &ptr1);
	  A4GL_push_param ((void *) ptr1, (d1 & DTYPE_MASK) + ENCODE_SIZE (s1));
#ifdef DEBUG
	A4GL_debug("Comparing...");
#endif
	  A4GL_pushop (OP_EQUAL);
	  eql = A4GL_pop_int ();
#ifdef DEBUG
		A4GL_debug("GOT MATCH @ %d = %d\n",a,eql);
#endif
	  if (eql) ok = 1;
	  a--;
	}
      A4GL_drop_param ();		/* Get rid of the base... */
      if (d == OP_IN) {
 		A4GL_push_int (ok);
#ifdef DEBUG
		A4GL_debug("OK=%d\n",ok);
#endif
	} else {
 		A4GL_push_int (!ok);
#ifdef DEBUG
		A4GL_debug("OK=%d\n",!ok);
#endif
	}
      return;
    }

  if (d == OP_IN_SELECT || d == OP_NOTIN_SELECT)
    {
      //int a=0;
      int ok = 0;
      int eql;
      char *s;
      static int cntsql_0 = 0;
      char cname[256];
      char tmpvar[256];
      struct BINDING ibind[] = {
	{&tmpvar, 0, 255,0,0,0}
      };			/* end of binding */
      SPRINTF1 (cname, "chkin_%d", cntsql_0++);

      s = A4GL_char_pop ();
      A4GL_get_top_of_stack (1, &d1, &s1, (void **) &ptr1);
      A4GLSQL_set_sqlca_sqlcode (0);
      {
	int n;
	struct BINDING *ibind;
	struct BINDING obind[] = { {0, 0, 0,0,0,0} };	/* end of binding */
	ibind = A4GL_pop_binding (&n);
	A4GLSQL_declare_cursor (0,(void *)
				A4GLSQL_prepare_select (ibind, n, obind, 0,
							s,"__internal_stack",1,0,0), 0, cname);
      }
      free (s);
      if (a4gl_status != 0)
	{
	  A4GL_drop_param ();
	  A4GL_push_int (0);
	}
      A4GLSQL_set_sqlca_sqlcode (0);
      A4GLSQL_open_cursor (cname,0,0);
      if (a4gl_status != 0)
	{
	  A4GL_drop_param ();
	  A4GL_push_int (0);
	}
      while (1)
	{
	  A4GLSQL_fetch_cursor (cname, 2, 1, 1, ibind);
	  if (a4gl_status != 0)
	    break;
	  A4GL_push_param (tmpvar, 0);
	  A4GL_push_param ((void *) ptr1, (d1 & DTYPE_MASK) + ENCODE_SIZE (s1));
	  A4GL_pushop (OP_EQUAL);
	  eql = A4GL_pop_int ();
	  if (eql)
	    ok = 1;
	  //a--;
	}
      A4GL_drop_param ();		/* Get rid of the base */
      if (d == OP_IN_SELECT)
 A4GL_push_int (ok);
      else
 A4GL_push_int (!ok);
      return;
    }

  if (d == OP_EXISTS || d == OP_NOTEXISTS)
    {
      int ok = 0;
      char *s;
      char tmpvar[256];
      static int cntsql_1 = 0;
      char cname[256];

      struct BINDING ibind[] = { {&tmpvar, 0, 255,0,0,0} };	/* end of binding */
      struct BINDING obind[] = { {0, 0, 0,0,0,0} };	/* end of binding */
      struct BINDING *dbind;
      void *prep;

      int n;

#ifdef DEBUG
      A4GL_debug ("OP_EXISTS - OP_NOTEXISTS...");
#endif
      SPRINTF1 (cname, "chkex%d", cntsql_1++);
      A4GL_debug ("Popping binding...");

      dbind = A4GL_pop_binding (&n);
      A4GL_debug ("poped dbind - Poping Sql");
      s = A4GL_char_pop ();
      A4GL_debug ("s=%s\n", A4GL_null_as_null(s));
      A4GLSQL_set_sqlca_sqlcode (0);
      A4GL_debug ("Prepare seelct...");
      prep = (void *)A4GLSQL_prepare_select (dbind, n, obind, 0, s,"__internal_stack",2,0,0);
      A4GL_debug ("Declare");
      free (s);
      A4GLSQL_declare_cursor (0, prep, 0, cname);

      if (a4gl_status != 0)
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GLSQL_set_sqlca_sqlcode (0);
      A4GLSQL_open_cursor (cname,0,0);
      A4GL_debug ("opened cursor");
      if (a4gl_status != 0)
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GLSQL_fetch_cursor (cname, 2, 1, 1, ibind);
      A4GL_debug ("fetched");
      if (a4gl_status == 0)
	ok = 1;
      if (a4gl_status == 100)
	ok = 0;
      if (a4gl_status != 0 && a4gl_status != 100)
	{
	  A4GL_debug ("Some error with the exists stuff.");
	  A4GL_push_int (0);
	  return;
	}
      A4GL_debug ("ok=%d", ok);
      if (d == OP_EXISTS)
 A4GL_push_int (ok);
      else
 A4GL_push_int (!ok);
      return;
    }

  if (d & NUMERIC_OP_2)
    {

      A4GL_debug ("OP_NUMERIC...");

      if (A4GL_chknull (2, n1, n2,dn1,dn2)) return;

      /* void A4GL_get_top_of_stack (int a, int *d, int *s, void **ptr); */
      A4GL_get_top_of_stack (1, &d1, &s1, (void **) &ptr1);
      A4GL_get_top_of_stack (2, &d2, &s2, (void **) &ptr2);


      if (d1 != DTYPE_INTERVAL || d1 != DTYPE_DTIME || d2 != DTYPE_INTERVAL
	  || d2 != DTYPE_DTIME)
	{
	  doublea = A4GL_pop_double ();
	  doubleb = A4GL_pop_double ();
		A4GL_debug("%lf %lf",doublea,doubleb);
	}
      else
	{
	  doing_dt_or_int = 1;
	}
    }

  switch (d)
    {
      int r;

    case OP_MATCHES:

      if (A4GL_chknull (2, n1, n2,dn1,dn2))
	return;
      c2 = A4GL_char_pop ();
      c1 = A4GL_char_pop ();
	
#ifdef DEBUG
	A4GL_debug("c1=%s c2=%s",A4GL_null_as_null(c1),A4GL_null_as_null(c2));
#endif
      r = A4GL_mja_match (c1, c2, 'M');
      A4GL_debug ("mja_match returns %d\n", r);
      A4GL_push_int (r);
      acl_free (c1);
      acl_free (c2);
      break;

    case OP_LIKE:
      if (A4GL_chknull (2, n1, n2,dn1,dn2))
	return;
      c2 = A4GL_char_pop ();
      c1 = A4GL_char_pop ();
#ifdef DEBUG
	A4GL_debug("Doing OP_LIKE...");
#endif
      A4GL_push_int (A4GL_mja_match (c1, c2, 'L'));
      acl_free (c1);
      acl_free (c2);
      break;


    case OP_EQUAL:
      if (A4GL_chknull_boolean (2, n1, n2,dn1,dn2))
	{
	  return;
	}

#ifdef DEBUG
      A4GL_debug ("OP_EQUAL");
#endif

	ob=A4GL_opboolean ();
	if (ob==-2) {
		A4GL_push_null(DTYPE_INT,0);
		return;
	}
        if (ob == 0) {
#ifdef DEBUG
		A4GL_debug("IS TRUE....");
#endif
 		A4GL_push_int (1);

	} else {
#ifdef DEBUG
		A4GL_debug("IS FALSE....");
#endif
 		A4GL_push_int (0);
	}
      break;

    case OP_NOT_EQUAL:
#ifdef DEBUG
      A4GL_debug ("Checking OP NOT EQUAL");
#endif
      if (A4GL_chknull_boolean (2, n1, n2,dn1,dn2))
	return;

#ifdef DEBUG
        A4GL_debug ("OP_NOT_EQUAL");
#endif
	ob=A4GL_opboolean ();
	if (ob==-2) {
		A4GL_push_null(DTYPE_INT,0);
		return;
	}
	if (ob==-1||ob==1) 
	  {
	    A4GL_push_int (1);
	  }
      	else
	{
	  A4GL_push_int (0);
	}
      break;

    case OP_OR:
#ifdef DEBUG
      A4GL_debug ("OP_OR");
#endif

      if (n1&&n2)  {
      	if (A4GL_chknull (2, n1, n2,dn1,dn2)) { A4GL_debug("One of null..."); return; }
      }

	
      i1 = A4GL_pop_int ();
      i2 = A4GL_pop_int ();
      A4GL_debug("i1=%d i2=%d n1=%d n2=%d",i1,i2,n1,n2);
      if (i1&&!n1) {A4GL_push_int(1);break;}
      if (i2&&!n2) {A4GL_push_int(1);break;}
      A4GL_push_int(0);

      /* dumpstack(); */
      //A4GL_debug ("OP_OR : %d %d\n", i1, i2);

      //A4GL_push_int (i1 || i2);
      break;


    case OP_AND:
      if (A4GL_chknull (2, n1, n2,dn1,dn2))
	return;
#ifdef DEBUG
      A4GL_debug ("OP_AND");
#endif
      i1 = A4GL_pop_int ();
      i2 = A4GL_pop_int ();
#ifdef DEBUG
      A4GL_debug (" OP_AND : %d %d", i1, i2);
#endif
      A4GL_push_int (i1 && i2);
      break;

    case OP_NOT:
      if (A4GL_chknull (1, n1, n2,dn1,dn2)) {
      			i1 = A4GL_pop_int ();
 		A4GL_push_int (1);
	      		return;
      }
      A4GL_debug ("OP_NOT");
      i1 = A4GL_pop_int ();
      if (i1)
 		A4GL_push_int (0);
      else
 		A4GL_push_int (1);
      break;

    case OP_LESS_THAN:
      if (A4GL_chknull_boolean (2, n1, n2,dn1,dn2))
	return;

	ob=A4GL_opboolean ();
	if (ob==-2) {
		A4GL_push_null(DTYPE_INT,0);
		return;
	}
      if (ob == -1)
 		A4GL_push_int (1);
      else
 		A4GL_push_int (0);
      break;

    case OP_GREATER_THAN:
      if (A4GL_chknull_boolean (2, n1, n2,dn1,dn2))
	return;
	ob=A4GL_opboolean ();
	if (ob==-2) {
		A4GL_push_null(DTYPE_INT,0);
		return;
	}

      if (ob == 1)
 		A4GL_push_int (1);
      else
 		A4GL_push_int (0);
      break;

    case OP_GREATER_THAN_EQ:
      if (A4GL_chknull_boolean (2, n1, n2,dn1,dn2))
	return;

	ob=A4GL_opboolean ();
	if (ob==-2) {
		A4GL_push_null(DTYPE_INT,0);
		return;
	}
      if (ob == -1)
 		A4GL_push_int (0);
      else
 		A4GL_push_int (1);
      break;

    case OP_LESS_THAN_EQ:
      if (A4GL_chknull_boolean (2, n1, n2,dn1,dn2))
	return;
	ob=A4GL_opboolean ();
	if (ob==-2) {
		A4GL_push_null(DTYPE_INT,0);
		return;
	}
      if (ob == 1)
 		A4GL_push_int (0);
      else
 		A4GL_push_int (1);
      break;

    case OP_CONCAT:
      A4GL_debug ("In concat %d %d", n1, n2);
      /* if (n1) {drop_param (); return;} */

      if ((n1||n2)) {
	if (!get_null_as_pad_string()) {
      	if (n1 == 1 && n2 == 0)
	{
	  char *s1;
	  char *s2;
	  s1 = A4GL_char_pop ();
	  s2 = A4GL_char_pop ();
	  A4GL_push_char (s2);
	  free (s1);
	  free (s2);
	  return;
	}

      	if (n2 == 1 && n1 == 0)
	{
	  char *s1;
	  char *s2;
	  s1 = A4GL_char_pop ();
	  s2 = A4GL_char_pop ();
	  //push_char ("");
	  A4GL_push_char (s1);
	  free (s1);
	  free (s2);
	  n2 = 0;
	  A4GL_debug ("Fudging...");
	  return;
	}
      } else {
	  char *s1;
	  char *s2;
	  char *z1;
	  int sz1;
	  int sz2;
	  int a;
	  s1 = A4GL_char_pop_size (&sz1);

	  if (s1&&n1 && sz1>0)  { A4GL_pad_string(s1,sz1); }
	  s2 = A4GL_char_pop_size (&sz2);
	  if (s2&&n2 && sz2>0)  { A4GL_pad_string(s2,sz2); }

	    a = (int)strlen (s1) + (int)strlen (s2) + 1;
	      z1 = A4GL_new_string (a);
	        strcpy (z1, s2);
		  strcat (z1, s1);
		      acl_free (s1);
		        acl_free (s2);
			  A4GL_push_char (z1);
	  return;
      }
      }

      //if (A4GL_chknull (2, n1, n2,dn1,dn2)) return;
      
      A4GL_func_concat ();
      break;

    case OP_USING:
      //if (A4GL_chknull (2, n1, n2,dn1,dn2))
	//return;

        A4GL_get_top_of_stack (1, &d1, &s1, (void **) &ptr1);
        A4GL_get_top_of_stack (2, &d2, &s2, (void **) &ptr2);

	A4GL_debug("OP_USING %d %d %d %d s1=%d s2=%d",n1,n2,dn1,dn2,s1,s2);

	if (n1) {
		//int a;
		char *ptr;
		A4GL_drop_param();
		A4GL_drop_param();
		A4GL_debug("PUSHED NULL %d",dn1>>16);
		ptr=acl_malloc2(s1+1);
		memset(ptr,' ',s1);
		ptr[s1]=0;
		A4GL_push_char(ptr);
		free(ptr);

		return;
	}

	if (n2) {
		char *ptr;
		int a;
		int l;
		ptr=A4GL_char_pop();
		A4GL_drop_param();
		A4GL_trim(ptr);
		l=strlen(ptr);
		for (a=0;a<l;a++) {
			ptr[a]=' ';
		}
		A4GL_push_char(ptr);
		free(ptr);
		return;
	}
      A4GL_func_using ();
      break;

    case OP_CLIP:
      A4GL_debug ("OP_CLIP");
      		A4GL_func_clip ();


      break;

    case OP_ADD:
      if (A4GL_chknull (2, n1, n2,dn1,dn2))
	return;
      A4GL_push_double (doublea + doubleb);
      break;

    case OP_SUB:
      if (A4GL_chknull (2, n1, n2,dn1,dn2))
	return;
      A4GL_push_double (doubleb - doublea);
      break;

    case OP_MULT:
      if (A4GL_chknull (2, n1, n2,dn1,dn2))
	return;
      A4GL_push_double (doublea * doubleb);
      break;

    case OP_POWER:
      if (A4GL_chknull (2, n1, n2,dn1,dn2))
	return;
      A4GL_push_double (pow (doublea, doubleb));
      break;

    case OP_MOD:
      if (A4GL_chknull (2, n1, n2,dn1,dn2))
	return;
      A4GL_debug ("OP MOD : %f %f\n", doubleb, doublea);
      {
	int a1, a2;
	a1 = (int) doubleb;
	a2 = (int) doublea;
 A4GL_debug ("a1=%d  a2=%d", a1, a2);
 A4GL_push_long (a1 % a2);
      }
      break;
    case OP_DIV:
      if (A4GL_chknull (2, n1, n2,dn1,dn2))
	return;
      A4GL_push_double (doubleb / doublea);
      break;

    case OP_YEAR:
    case OP_MONTH:
    case OP_DAY:
    case OP_HOUR:
    case OP_MINUTE:
    case OP_SECOND:
			/** @todo Confirm if the return was needed */
      /* return A4GL_conv_to_interval (d); */
      A4GL_conv_to_interval (d);
      break;			/* just to be sure! */
    }
}

/**
 *
 *
 * @return
 */
void
A4GL_push_user (void)
{
  int a;
  struct passwd *p;
#ifdef MSVC
  A4GL_push_char("XXXX");
#else
#ifndef DOING_CM
#ifndef __MINGW32__

  a = getuid ();
  p = getpwuid (a);
#else
  PRINTF ("FIXME: no getuid() / getpwuid() on MinGW\n");
#endif

  A4GL_push_char (p->pw_name);
#endif
#endif
}

/**
 *
 *
 * @return
 */
void
A4GL_push_ascii ()
{
  int a;
  char buff[3];
  a = A4GL_pop_int ();
  buff[0] = a;
  buff[1] = 0;
  A4GL_push_char (buff);
}


void A4GL_push_date_expr(void) {
long l;
A4GL_push_today();
l=A4GL_pop_long();
A4GL_push_char(A4GL_using_date(l,"ddd mmm dd yyyy"));
}

void A4GL_push_time_expr(void) {
	char *ptr;
	A4GL_push_current( 4 ,6);
	ptr=A4GL_char_pop();
	A4GL_push_char(ptr);
	free(ptr);
}



/**
 *
 *
 * @return
 */
void
A4GL_push_today (void)
{
  long z;
  int mja_day;
  struct tm *local_time;
  time_t now;
  int month, year;		/* ch, yflag; */

  /*      setlocale(LC_ALL,""); */
  (void) time (&now);
  local_time = localtime (&now);
#ifndef DOING_CM
  year = local_time->tm_year + 1900;
  month = local_time->tm_mon + 1;
  mja_day = local_time->tm_mday;

  z = A4GL_gen_dateno (mja_day, month, year);
#endif

#ifdef DEBUG
  A4GL_debug ("Here....%ld %d %d %d", z, mja_day, month, year);
#endif
  A4GL_push_date (z);
}


#if defined (_WIN32) && !defined (__CYGWIN__)

#include <sys/timeb.h>
#include <sys/types.h>
#ifndef DOING_CM
#include <winsock.h>
#endif

void
gettimeofday (struct timeval *t, void *timezone)
{
#ifndef DOING_CM
  struct _timeb timebuffer;
  _ftime (&timebuffer);
  t->tv_sec = timebuffer.time;
  t->tv_usec = 1000 * timebuffer.millitm;
#endif
}

#endif



#ifdef ANOTHER_EXAMPLE_OF_GETTIMEOFDAY

// see http://sources.redhat.com/ml/gdb/2001-05/msg00076.html
// http://www.linuxjournal.com/article.php?sid=5574
// see http://lists.ntop.org/pipermail/ntop-dev/2001-November/000227.html

/*  winbase.h definitions */
typedef struct _FILETIME
{
  unsigned long dwLowDateTime;
  unsigned long dwHighDateTime;
}
FILETIME;

void __stdcall GetSystemTimeAsFileTime (FILETIME *);

/*time from 1 Jan 1601 to 1 Jan 1970 in 100ns units */
#define _W32_FT_OFFSET (116444736000000000LL)

typedef union
{
  long long ns100;		/*time since 1 Jan 1601 in 100ns units */
  FILETIME ft;
}
w32_ftv;

void
nt_gettimeofday (struct timeval *p, struct timezone *tz /* IGNORED */ )
{
  w32_ftv _now;
  GetSystemTimeAsFileTime (&(_now.ft));
  p->tv_usec = (long) ((_now.ns100 / 10LL) % 1000000LL);
  p->tv_sec = (long) ((_now.ns100 - _W32_FT_OFFSET) / 10000000LL);
  return;
}
#endif


/**
 *
 *
 * @return
 */
void
A4GL_push_current (int a, int b)
{
  int mja_day;
  struct tm *local_time;
  //time_t now;
  int month, year;		/* ch, yflag; */
  char buff[50];
  char buff2[50];
  int n;
  int ptrs[] = { -1, 0, 5, 8, 11, 14, 17, 20, 21, 22, 23, 24, 25 };
  int ptrs2[] = { -1, 3, 6, 9, 12, 15, 18, 21, 22, 23, 24, 25, 26 };
  int pstart;
#ifndef DOING_CM
  struct timeval tv1;


  gettimeofday (&tv1, 0);

  local_time = localtime (&tv1.tv_sec);
  year = local_time->tm_year + 1900;
  month = local_time->tm_mon + 1;
  mja_day = local_time->tm_mday;

/*
       0000000000111111111122222
       0123456789012345678901234
       YYYY-MM-DD hh:mm:ss.fffff
*/
  SPRINTF7 (buff, "%04d-%02d-%02d %02d:%02d:%02d.%06ld",
	   year, month, mja_day, local_time->tm_hour,
	   local_time->tm_min, local_time->tm_sec, tv1.tv_usec
	   /* , 0 */
	   /* no support for fractions of a second yet */
    );
  buff[27] = 0;
  A4GL_debug ("Time is %s", A4GL_null_as_null(buff));
  A4GL_assertion(b<0||b>12, "push_current parameter out of range") ;
  pstart = ptrs2[b] + 1;
  buff[pstart] = 0;

  A4GL_assertion(a<0||a>12, "push_current parameter out of range") ;
  strcpy (buff2, &buff[ptrs[a]]);

  n = (a << 4) + b;

  acli_datetime (buff2, n);
  A4GL_debug ("All done - push_current...");
#endif
}



/* this is just for some testong - remove it */
/*
int
current_second (void)
{
struct tm *local_time;
time_t now;
char buff[50];

  (void) time (&now);
  local_time = localtime (&now);
  SPRINTF1 (buff, "%d",local_time->tm_sec);
  A4GL_debug ("Time is %s", A4GL_null_as_null(buff));
	return local_time->tm_sec;
}
*/



/**
 *
 *
 * @return
 */
void
A4GL_push_time (void)
{
#ifndef DOING_CM
  struct tm *local_time;
  time_t now;
  char buff[20];
/* setlocale(LC_ALL,""); */
  A4GL_debug ("In push_time");
  (void) time (&now);
  A4GL_debug ("Called time...");
  local_time = localtime (&now);
  A4GL_debug ("Got local time");
  SPRINTF3 (buff, "%02d:%02d:%02d",
	   local_time->tm_hour, local_time->tm_min, local_time->tm_sec);
  A4GL_debug ("Time is %s", A4GL_null_as_null(buff));
  A4GL_push_char (buff);
#endif
}


/**
 *
 *
 * @return
 */
void
A4GL_pushop (int a)
{

  if (a == (OP_MATCHES) || a == (OP_LIKE))
    {
      char *s;
      s = A4GL_char_pop ();
      A4GL_set_escape (s);
      free (s);
    }


#ifdef DEBUG
  A4GL_debug ("PUSHOP : %x", a);
#endif
  if (a == OP_IN || a == OP_NOTIN
      || a == OP_IN_SELECT || a == OP_NOTIN_SELECT
      || a == OP_EXISTS || a == OP_NOTEXISTS)
    {
      A4GL_process_stack_op_other (a);
      return;
    }

  A4GL_push_param (0, a);
}


/**
 *
 *
 * @return
 */
int
A4GL_opboolean (void)
{
  int d1, d2;
  char *z1 = 0;
  char *z2 = 0;
  double a, b;
  double diff;
  int cmp;
  int adate;
int first;
  d1 = params[params_cnt - 1].dtype & DTYPE_MASK;
  d2 = params[params_cnt - 2].dtype & DTYPE_MASK;

#ifdef DEBUG
  A4GL_debug ("compare Data types %d %d \n", d1, d2);
#endif
  if (d1 == d2 || (d1 != d2 && d1 != DTYPE_CHAR && d2 != DTYPE_CHAR))
    {
      if (d1 == DTYPE_CHAR && d2 == DTYPE_CHAR)
	{
	  z1 = A4GL_char_pop ();
	  A4GL_trim (z1);
	  z2 = A4GL_char_pop ();
	  A4GL_trim (z2);
#ifdef DEBUG
	  /* {DEBUG} */ A4GL_debug ("String Compare : '%s' and '%s'", A4GL_null_as_null(z1),A4GL_null_as_null( z2));
	  /* {DEBUG} */ A4GL_debug (" = %d\n", strcmp (z1, z2));
#endif
	  cmp = strcmp (z1, z2) * -1;
	  if (cmp < 0) cmp = -1;
	  if (cmp > 0) cmp = 1;
	  acl_free (z1);
	  acl_free (z2);
	  z1 = 0;
	  z2 = 0;
	  A4GL_debug ("String compare gives %d\n", cmp);
	  return cmp;
	}
	if (d1==DTYPE_VCHAR ||d2==DTYPE_VCHAR) {
		if ((d1==DTYPE_VCHAR||d1==DTYPE_CHAR)  && (d2==DTYPE_VCHAR||d2==DTYPE_CHAR)  ) {
	  		z1 = A4GL_char_pop ();
	  		z2 = A4GL_char_pop ();
			if (d1==DTYPE_CHAR||d2==DTYPE_CHAR) {
	  			A4GL_trim (z1);
	  			A4GL_trim (z2);
			}
	  		cmp = strcmp (z1, z2) * -1;
	  		if (cmp < 0) cmp = -1;
	  		if (cmp > 0) cmp = 1;
	  		acl_free (z1);
	  		acl_free (z2);
	  		z1 = 0;
	  		z2 = 0;
	  		A4GL_debug ("String compare gives %d\n", cmp);
	  		return cmp;
		}
	}

	
	  a = A4GL_pop_double ();
	  b = A4GL_pop_double ();
	  A4GL_debug("%lf %lf",a,b);
	  diff=b-a;
	  if (diff<0) diff=0.0-diff;
#ifdef DEBUG
	  A4GL_debug ("check %.8lf %.8lf %.8lf ", a, b,diff);
#endif
	
	  if (diff<0.00000001 && a!=b) {
		A4GL_debug("Near as dammit equal..");
		return 0;
	  }
	  if (b > a)
	    {
	      return 1;
	    }
	  if (b < a)
	    {
	      return -1;
	    }
	  A4GL_debug ("Equal");
	  return 0;
	
    }

  /* comparison of char to number/date */





  if (d1 == DTYPE_CHAR)
    {
	//double aa;
      //A4GL_debug ("First is string");	
	first=1;
      z1 = A4GL_char_pop ();
      b = A4GL_pop_double ();
	if (A4GL_stof (z1, &a, 0)) {
		//A4GL_debug("OK as a float");
	} else {
		A4GL_debug("Doesn't look much like a float to me (%s)",A4GL_null_as_null(z1));
		return -2;
	}
      //b = strtod (z1,&ptr);
      //A4GL_debug ("1 --> %s %lf ", z1, b);
    }
  else
    {
	first=0;
      A4GL_debug ("second is string");
      a = A4GL_pop_double ();
      z1 = A4GL_char_pop ();
      //b = strtod (z1,&ptr);
	if (A4GL_stof (z1, &b, 0)) {
		//A4GL_debug("OK as a float..");
	} else {
		A4GL_debug("Doesn't look much like a float to me (%s)",A4GL_null_as_null(z1));
		return -2;
	}
      //A4GL_debug ("2 --> %s %lf", z1, a);
    }

  if (a_strchr(z1,'/') && A4GL_stod (z1, &adate, 0) == 1) // Looks a bit like a date...
    {

	if (!A4GL_isnull(DTYPE_DATE,(void *)&adate)) {
      		A4GL_debug ("String looks like it is a date...");

		if (first==0) 
      			b = (double) adate;
		else
      			a = (double) adate;
	}
    }

  if (z1)
    acl_free (z1);
  if (z2)
    acl_free (z2);

  if (b > a)
    {
      return 1;
    }
  if (b < a)
    {
      return -1;
    }
  return 0;			/* equality */
}


/**
 *
 *
 * @return
 */
void
A4GL_pop_args (int a)
{
  char *s = 0;
  int z = 0;
  if (z > 0)
    {
      for (z = 0; z < a; z++)
	{
	  s = A4GL_char_pop ();
	  acl_free (s);
	}
    }
}


/********************************************************************/
/* debugging */

/**
 *
 *
 * @return
 */
void
A4GL_debug_print_stack (void)
{
  int a;
  char *buff;
return;
  buff = A4GL_new_string (2000);



#ifdef DEBUG
  A4GL_debug ("\n");
#endif
#ifdef DEBUG
  A4GL_debug ("**************************************************************:");
#endif
#ifdef DEBUG
  /* {DEBUG} */ A4GL_debug ("Call stack has %d entries:\n", params_cnt);
#endif
  for (a = 0; a < params_cnt; a++)
    {
	strcpy(buff,"Not displayable");

	if (A4GL_isnull((params[a].dtype&DTYPE_MASK),params[a].ptr)) {
		strcpy(buff,"NULL");
	} else {
		A4GL_debug("Not null");
 	
	switch(params[a].dtype&DTYPE_MASK) {
		case DTYPE_CHAR:
		case DTYPE_SMINT:
		case DTYPE_INT:
		case DTYPE_SERIAL:
		case DTYPE_FLOAT:
		case DTYPE_SMFLOAT:
		case DTYPE_DATE:
      			A4GL_conv (params[a].dtype, params[a].ptr, DTYPE_CHAR, buff, 40);
			break;
	}
	}
	A4GL_debug("*    %d %p %s",params[a].dtype&DTYPE_MASK,params[a].ptr,A4GL_null_as_null(buff));
    }

#ifdef DEBUG
  A4GL_debug ("**************************************************************");
#endif
}

#ifdef DBG_PRINT_STACK_SIMPLE
void A4GL_debug_print_stack_simple(char *msg) {
char buff[20];
int a;
PRINTF("* Stack has : %d entries --- %s\n",params_cnt,msg);
  for (a = 0; a < params_cnt; a++)
    {

	if (A4GL_isnull((params[a].dtype&DTYPE_MASK),params[a].ptr)) {
		strcpy(buff,"NULL");
	} else {
		strcpy(buff,"NOT NULL");
	}


	A4GL_debug("*    %d %p %s",params[a].dtype&DTYPE_MASK,params[a].ptr,A4GL_null_as_null(buff));
	PRINTF("*    %d %p %s\n",params[a].dtype&DTYPE_MASK,params[a].ptr,A4GL_null_as_null(buff));

    }

}
#endif

/**
 *
 *
 * @return
 */
void
print_stack (void)
{
  int a;
  char *buff;
  buff = A4GL_new_string (20);
  PRINTF ("\n\n\n\n\n\n\n\n\n");
  PRINTF ("Call stack has %d entries:\n", params_cnt);
  for (a = 0; a < params_cnt; a++)
    {
      A4GL_conv (params[a].dtype & DTYPE_MASK, params[a].ptr, 0, buff, 8);
      PRINTF (" %d Dtype (%d) %s\n", a, params[a].dtype & DTYPE_MASK, buff);
    }
}


/**
 *
 *
 * @return
 */
static char *
add_to_z (char *z, char *s)
{
  char *ptr;
  int l;
  if (z == 0)
    {
      z = acl_strdup ("");
    }

  A4GL_debug ("Adding '%s' to '%s'", A4GL_null_as_null(s), A4GL_null_as_null(z));
  ptr = acl_strdup (z);

  l = strlen (z) + strlen (s) + 1;

  A4GL_debug ("New size=%d", l);

  z = (char *) realloc (z, l);
  strcpy (z, ptr);
  strcat (z, s);

  free (ptr);
  A4GL_debug ("z=%s", A4GL_null_as_null(z));

  return z;
}

/**
 *
 *
 * @return
 */
char *
A4GL_params_on_stack (char *_paramnames[], int n)
{
  int a;
  char *buff;
  char *buff2;
  char *z = 0;
  int sz;

  if (n == 0)
    return 0;

  A4GL_debug ("Generating parameter list n=%d", n);

  for (a = 0; a < n; a++)
    {

	// If there are more than 20 parameters -
	// ignore the rest....

	if (a&&_paramnames[a]==0) {
		A4GL_debug("Ran out of parameters");
      		z=add_to_z(z," + MORE");
		return z;
	}
      if (n>20) {z=add_to_z(z,"...");break;}


      if ((params[a].dtype & DTYPE_MASK) != DTYPE_CHAR)
	{
	  sz = 30;
	  A4GL_debug ("not char - sz=30");
	}
      else
	{
	  sz = params[a].size;
	  A4GL_debug ("char - sz=%d", sz);
	}

      buff = acl_malloc2 (sz + 10);
      A4GL_debug ("Calling conv...");

      A4GL_conv (params[a].dtype & DTYPE_MASK, params[a].ptr, 0, buff, sz);


      A4GL_debug ("Conv gives us '%s'", A4GL_null_as_null(buff));

      buff2 = buff;
      buff2 = A4GL_lrtrim (buff);
	A4GL_debug("buff2=%s\n",buff2);

      if (a)
	{
	  z = add_to_z (z, ",");
	}

      A4GL_debug ("1. z=%s", A4GL_null_as_null(z));
      z = add_to_z (z, _paramnames[a]);

      A4GL_debug ("2. z=%s", A4GL_null_as_null(z));
      z = add_to_z (z, "=");
      A4GL_debug ("3. z=%s", A4GL_null_as_null(z));
      z = add_to_z (z, buff2);
      A4GL_debug ("4. z=%s", A4GL_null_as_null(z));

      free (buff);
    }
  A4GL_debug ("Generated : %s", A4GL_null_as_null(z));
  return z;
}

/**
 *
 *
 * @return
 */
void
A4GL_push_bind (struct BINDING *b, int n, int no, int elemsize)
{
  int a;
#ifdef DEBUG
  /* {DEBUG} */ A4GL_debug ("push_bind");
#endif
  for (a = n - 1; a >= 0; a--)
    {
#ifdef DEBUG
      /* {DEBUG} */ A4GL_debug ("Push param %d -> %p %lx", a, b[a].ptr,
			   b[a].dtype + ENCODE_SIZE (b[a].size));
#endif
      A4GL_push_param ((char *) b[a].ptr + elemsize * (no - 1), b[a].dtype);
    }
}

/**
 *
 *
 * @return
 */
void
A4GL_push_bind_reverse (struct BINDING *b, int n, int no, int elemsize)
{
  int a;
  for (a = 0; a < n; a++)
    {
      A4GL_push_param ((char *) b[a].ptr + elemsize * (no - 1), b[a].dtype);
    }
}


/**
 *
 *
 * @return
 */
void
A4GL_push_disp_bind (void *vb, int n)
{
  struct BINDING *b;
  int a;
  b = (struct BINDING *) vb;

#ifdef DEBUG
  /* {DEBUG} */ A4GL_debug ("push_disp_bind");
#endif
  for (a = 0; a < n; a++)
    {
#ifdef DEBUG
      /* {DEBUG} */ A4GL_debug ("Push param %d -> %p %lx", a, b[a].ptr,
			   b[a].dtype + ENCODE_SIZE (b[a].size));
#endif
      A4GL_push_param ((char *) b[a].ptr, b[a].dtype + ENCODE_SIZE (b[a].size));
    }
}


#ifdef MOVED
/**
 *
 *
 * @return
 */
int
A4GL_chk_params (struct BINDING *b, int nb, struct BINDING *o, int no)
{
  int i;
  int ca, cb;
  char mptr[2048];


  for (ca = 0; ca < no; ca++)
    {
#ifdef DEBUG
      /* {DEBUG} */ A4GL_debug ("ca=%d", ca);
#endif
      for (cb = 0; cb < nb; cb++)
	{
#ifdef DEBUG
	  /* {DEBUG} */ A4GL_debug ("   cb=%d", cb);
#endif
	  if (b[cb].ptr == o[ca].ptr)
	    {
#ifdef DEBUG
	      /* {DEBUG} */ A4GL_debug ("11   pointers %d %d are equal", cb, ca);
#endif
	      /* check value in o.ptr against that on the stack */
#ifdef DEBUG
	      /* {DEBUG} */ A4GL_debug ("11 nb=%d cb=%d ca=%d\n", nb, cb, ca);
#endif
	      A4GL_read_param (mptr, b[cb].dtype, b[cb].size, nb - cb);
#ifdef DEBUG
	      /* {DEBUG} */
	      A4GL_debug
		("11   pushing last data-------------------------------------------------");
#endif
	      A4GL_push_param (b[cb].ptr, b[cb].dtype);
#ifdef DEBUG
	      /* {DEBUG} */ A4GL_debug ("   pushing this data");
#endif
	      A4GL_push_param (mptr, b[cb].dtype);
#ifdef DEBUG
	      if (b[cb].dtype==DTYPE_VCHAR ) {
		      	A4GL_debug(" : '%s' '%s'",b[cb].ptr,mptr);
	      }
	      /* {DEBUG} */
	      A4GL_debug
		("11   checking for equallity--------------------------------------------");
#endif
	      A4GL_pushop (OP_EQUAL);
	      i = A4GL_pop_bool ();
#ifdef DEBUG
	      /* {DEBUG} */ A4GL_debug ("11   i=%d", i);
#endif
	      if (i == 0)
		{
#ifdef DEBUG
		  /* {DEBUG} */
		  A4GL_debug ("10 Param %d has changed in order by binding", ca);
#endif
		  return ca + 1;
		}
	    }
	}
    }
#ifdef DEBUG
  /* {DEBUG} */ A4GL_debug ("10 No change");
#endif
  return -1;
}
#endif

/**
 *
 *
 * @return
 */
int
A4GL_read_param (void *p, int d, int size, int c)
{
  int b;
//  char *ptr;
#ifdef DEBUG
  /* {DEBUG} */ A4GL_debug ("10 Stack pointer=%d c=%d", params_cnt, c);
  /* {DEBUG} */ A4GL_debug ("10 read param pointer =%p datatype=%x size=%d count=%d",
		       p, d, size, c);
#endif
  b = A4GL_conv (params[params_cnt - c].dtype & DTYPE_MASK,params[params_cnt - c].ptr, d & DTYPE_MASK, p, size);
  return b;
}

/**
 *
 *
 * @return
 */
void
A4GL_upshift_stk (void)
{
  char *ptr;
  ptr = A4GL_char_pop ();
  A4GL_convupper (ptr);
  A4GL_push_char (ptr);
  acl_free (ptr);
}

/**
 *
 *
 * @return
 */
void
A4GL_downshift_stk (void)
{
  char *ptr;
  ptr = A4GL_char_pop ();
  A4GL_convlower (ptr);
  A4GL_push_char (ptr);
  acl_free (ptr);
}

/**
 *
 *
 * @return
 */

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif



/**
 * Assign an aubit 4gl variable with a value that marks it as null.
 *
 * @param type The data type of the variable.
 * @param buff A pointer to the buffer where the variable is located.
 * @param size The size of the variable in bytes.
 */
void
A4GL_setnull (int type, void *vbuff, int size)
{
  int a;
  char c;
  char *buff;


if (type>255) {
	PRINTF("Bad..: %d %x\n",type,type);
	A4GL_assertion(1,"expecting type <= 255 + a size"); 
}




#ifdef DEBUG
  A4GL_debug ("Set nulli %d %p %d",type,vbuff,size);
#endif
  buff = (char *) vbuff;

  if (A4GL_has_datatype_function_i (type, "INIT"))
    {
      void (*function) (char *);
      A4GL_debug ("10 Calling INIT for datatype");
      function = A4GL_get_datatype_function_i (type, "INIT");
      function (buff);
      return;
    }




  if (type == DTYPE_BYTE || type == DTYPE_TEXT)
    {
      struct fgl_int_loc *ptr;
      ptr = (struct fgl_int_loc *) buff;
      //if (ptr->where == 'M')
	//{
	A4GL_free_associated_mem(ptr);
	  //free (ptr->ptr);
      ptr->ptr = 0;
	//}
      ptr->where = 'N';
      return;
    }

  if (type == DTYPE_DTIME)
    {
      struct A4GLSQL_dtime *i;
#ifdef DEBUG
	A4GL_debug("Setting : %p",buff);
#endif
      i = (struct A4GLSQL_dtime *) buff;
      i->data[0] = 0;
      return;
    }

  if (type == DTYPE_INTERVAL)
    {
      struct ival *i;
      i = (struct ival *) buff;
      i->stime = 0;
      i->ltime = 0;
      //i->data[0] = 0;
      return;
    }

  for (a = 0; a < 9; a++)
    {
      c = nset[type & DTYPE_MASK][a];
      if (UC (c) != UC (IGN))
	{
	  A4GL_debug ("20 Setting byte %d to %d", a, c);
	  buff[a] = c;
	}
    }


  if (type == 0)
    {
      A4GL_debug ("20 Set buff to %s\n", buff);
    }


  if (type==DTYPE_DECIMAL || type==DTYPE_MONEY) {
	int h;
	int t;
  	h = size;
  	t = h;
  	h = h / 256;
  	t = t - h * 256;
  	errno = 0;
	if (h||t) {
  		A4GL_init_dec ((void *)buff, h, t);
	}

  }



  if (!(A4GL_isnull (type, buff)))
    {
        A4GL_debug ("1 Opps - can't init to null");
	A4GL_assertion(1,"Could not initialize variable to null");
    }

}

/**
 * Check if an aubit 4gl variable contains a null value.
 *
 * @param type The data type of the variable.
 * @param buff A pointer to the the buffer where the value is stored.
 *
 * @return 
 *   - 1 : The variable contains a null value.
 *   - 0 : The variable does not contain null value.
 */
int
A4GL_isnull (int type, char *buff)
{
  //int a;
  struct A4GLSQL_dtime *i;
  struct ival *iv;
  struct fgl_int_loc *ptr;
  static AInt16 i_int=0;
  static AInt32 i_long=0;


  static void *nullfuncs[]={
	  	(void *)-1,
	  	(void *)-1,
	  	(void *)-1,
	  	(void *)-1,
	  	(void *)-1,
	  	(void *)-1,
	  	(void *)-1,
	  	(void *)-1,
	  	(void *)-1,
	  	(void *)-1,
	  	(void *)-1,
	  	(void *)-1,
	  	(void *)-1,
	  	(void *)-1,
	  	(void *)-1,
	  	(void *)-1,
	  	(void *)-1,
	  	(void *)-1,
	  	(void *)-1};
  type = type & DTYPE_MASK;
  //A4GL_debug ("20 ISNULL - %d %p\n", type, buff);

  if (buff==0) return 1;

  if (nullfuncs[type]==(void *)-1) {
	 // We've never seen this type before...
  	if (A4GL_has_datatype_function_i (type, "ISNULL")) {
      		int (*function) (char *);
      		function = A4GL_get_datatype_function_i (type, "ISNULL");
		// has function
		nullfuncs[type]=function;
      		return function (buff);
    	}
	// No function
	nullfuncs[type]=0;
  } else {
  	if (nullfuncs[type]!=0) {
      		int (*function) (char *);
      		function = nullfuncs[type];
      		return function (buff);
  	}
  }



  switch (type) {
	  case DTYPE_BYTE:
	  case DTYPE_TEXT:
      		ptr = (struct fgl_int_loc *) buff;
      		return ptr->where == 'N';
    

	  case DTYPE_DTIME:
     			i = (struct A4GLSQL_dtime *) buff;
      			if (i->data[0] == 0)
				return 1;
      			else
				return 0;

	  case DTYPE_CHAR:
      			if (buff[0] == 0 && buff[1]==0)
				return 1;
      			else
				return 0;

	  case DTYPE_INTERVAL:
      			iv = (struct ival *) buff;
      			if (iv->stime==0 && iv->ltime==0) return 1;
      			else return 0;

	  case DTYPE_SMINT:
			if (i_int==0) {
				if (A4GL_null_other(buff,type)==1 && i_int==0) { 
					i_int=*(AInt16 *)buff;
					return 1;
				}
				return 0;
			} else {
				if (i_int==*(AInt16 *)buff) {
					if (A4GL_null_other(buff,type)!=1) { A4GL_assertion(1,"Null test failed 31"); }
					return 1;
				} else  {
					if (A4GL_null_other(buff,type)!=0) { A4GL_assertion(1,"Null test failed 32"); }
					return 0;
				}
			}

	  case DTYPE_INT:
			if (i_long==0) {
				if (A4GL_null_other(buff,type)==1 && i_long==0) { 
					i_long=*(AInt32 *)buff;
					return 1;
				}
				return 0;
			} else {
				long i1;
				long i2;
				i1=i_long&0xffffffff;
				A4GL_debug("i1=%d\n",i1);
				i2=*(AInt32 *)buff&0xffffffff;
				A4GL_debug("i2=%d\n",i2);
				if (i1==i2) {
					if (A4GL_null_other(buff,type)!=1) { A4GL_assertion(1,"Null test failed 3.11"); }
					return 1;
				} else  {
					A4GL_debug("i_long=%d buff=%d type=%d",i_long,*(AInt32 *)buff,type);
					if (A4GL_null_other(buff,type)!=0) { A4GL_assertion(1,"Null test failed 3.12"); }
					return 0;
				}
			}
  }


  return A4GL_null_other(buff,type);
}




static int A4GL_null_other(char *buff,int type) {
int a;
  A4GL_debug("25 Checking byte %d",type);

  for (a = 0; a < 9; a++)
    {

	if (type==DTYPE_SMINT && a>sizeof(short)) break;
	if (type==DTYPE_INT&& a>sizeof(long)) break;
	if (type==DTYPE_SERIAL&& a>sizeof(long)) break;
	if (type==DTYPE_DATE&& a>sizeof(long)) break;

      if ((unsigned char) (nset[type][a]) != (unsigned char) IGN)
	{
	  if ((unsigned char) (buff[a]) != (unsigned char) (nset[type][a]))
	    {
		    A4GL_debug("40 %d != %d", (unsigned char) (buff[a]) , (unsigned char) (nset[type][a]));
	      return 0;
	    }
	}
    }
		    A4GL_debug("40 Null other - OK!");
  return 1;
}





/**
 *
 *
 * @return
 */
void
A4GL_locate_var (struct fgl_int_loc *p, char where, char *filename)
{

  A4GL_debug ("20 locate_var p=%p %c", p, p->where);

  if (p->where == 'M' && p->ptr > 0)
    {
      A4GL_debug ("20 Freeing\n");
      //free(p->ptr); //bugger...
    }

  A4GL_init_blob (p);

  A4GL_debug ("20 inited");

  p->ptr = 0;
  p->memsize = -1;

  if (where == 'M')
    {
      A4GL_debug ("8 Locating blob in memory");
      p->where = 'M';
      p->filename[0] = 0;
    }
  else
    {
      A4GL_debug ("8 Locating blob in file %s", filename);
      p->where = 'F';
      strcpy (p->filename, filename);
      A4GL_trim (p->filename);
    }
  A4GL_debug ("7 Located at %c %s", p->where, p->filename);
}


int aclfgl_aclfgl_byte_as_str(int n) {
	fglbyte b;
        static char *buff=0;
	A4GL_pop_param(&b,0xb,0);
	if (b.where=='F') {
		long l;
		FILE *f;
                f=fopen(b.filename,"r");
                if (f==0) {
                        A4GL_exitwith("Unable to load blob file");
			A4GL_push_char("");
                        return 1;
                }
                fseek(f,0,SEEK_END);
                l=ftell(f);
                buff=malloc(l+1);
                memset(buff,0,l+1);
                rewind(f);
                fread(buff,1,l,f);
		fclose(f);
		if (b.ptr) A4GL_push_char(buff);
		free(buff);
		buff=0;
                return 1;
	}
	
	if (b.ptr) A4GL_push_char(b.ptr);
	else A4GL_push_char("NULL");

	//A4GL_push_long(1);
	return 1;
}

/**
 *
 *
 * @return
 */
void
A4GL_init_blob (struct fgl_int_loc *p)
{
  A4GL_debug ("7 Init blob\n");
  p->ptr = 0;
  p->memsize = -1;
  p->filename[0] = 0;
  p->where = 'N';
  p->f = 0;
}



/**
 *
 *
 * @return
 */
void
A4GL_push_null (int dtype,int size)
{
  A4GL_debug ("7 ** Pushing null");

  A4GL_push_param (0, dtype+ENCODE_SIZE(size));

}


/**
 *
 *
 * @return
 */
int
A4GL_chknull (int n, int n1, int n2,int d1,int d2)
{
  A4GL_debug ("15 CHecking first %d of %d %d", n, n1, n2);

  if (n == 1)
    {
      if (n1)
	{
	  return 1;
	}
      else
	return 0;
    }

  if (n == 2 && (n1 || n2))
    {
      A4GL_drop_param ();
      A4GL_drop_param ();
      A4GL_debug ("20 Dropped 2");
      A4GL_push_null (d1&DTYPE_MASK,DECODE_SIZE(d1)); /* FIXME - need to check what this should be based on d1 and d2 */
      A4GL_debug ("7 Pushed null");
      return 1;
    }
  return 0;
}

/**
 *
 *
 * @return
 */
void
A4GL_drop_param (void)
{
  char *ptr;
  params_cnt--;
  if (params_cnt < 0)
    {
      A4GL_debug ("1 Stack got corrupted");
      A4GL_assertion (1, "Stack got corrupted");
      A4GL_fgl_die (1);
    }

  if (params[params_cnt].dtype & DTYPE_MALLOCED)
    {
      if ((params[params_cnt].dtype & DTYPE_MASK) != DTYPE_CHAR)
        {
          acl_free (params[params_cnt].ptr);
        }
      else
        {
          ptr = params[params_cnt].ptr;
          A4GL_debug ("15 Not Char..%p", ptr);
          acl_free (ptr);
        }
    }
}


/**
 *
 *
 * @return
 */
void
A4GL_set_init (struct BINDING *b, int n)
{
static int ln;
  int a;
  ln=n;
  for (a = 0; a < n; a++)
    {
	if (n!=ln||n>10000||a>=n||a>=ln) {
		PRINTF("n=%d ln=%d\n",n,ln);
		A4GL_assertion(1,"internal corruption");
	}

      A4GL_setnull (b[a].dtype &DTYPE_MASK, (char *) b[a].ptr, b[a].size);
    }
}


/**
 *
 *
 * @return
 */
void
A4GL_get_top_of_stack (int a, int *d, int *s, void **ptr)
{
	A4GL_assertion(params_cnt-a<0,"internal stack corruption");

  *d = params[params_cnt - a].dtype;
  *s = params[params_cnt - a].size;
  *ptr = params[params_cnt - a].ptr;
}

/**
 *
 *
 * @return
 */
int
A4GL_chknull_boolean (int n, int n1, int n2,int d1,int d2)
{
  if (n == 2 && (n1 || n2))
    {
      A4GL_drop_param ();
      A4GL_drop_param ();
      A4GL_push_int (0);
      return 1;
    }
  return 0;
}

/**
 *
 *
 * @return
 */
int
A4GL_conv_to_interval (int a)
{
  double d;
  //struct ival i;
  char buff[256];

  memset(buff,0,255);
  A4GL_debug ("Conv to interval - %d\n", a);
  d = A4GL_pop_double ();
  A4GL_debug ("Got d as %lf\n", d);
  switch (a)
    {
    case (OP_YEAR):
      SPRINTF1 (buff, "%d-00", (int) d);
      break;
    case (OP_MONTH):
      SPRINTF1 (buff, "0000-%d", (int) d);
      break;
    }

  switch (a)
    {
      // There are no breaks so that the
      // effect is cummulative
    case OP_DAY:
      d = d * 24;
    case OP_HOUR:
      d = d * 60;
    case OP_MINUTE:
      d = d * 60;
    case OP_SECOND:
      d = d;
	SPRINTF1(buff,"%f",d);
    }
  A4GL_debug ("11 D now set to %lf", d);
  A4GL_debug ("11 a=%d %d %d %d\n", a, OP_YEAR, OP_MONTH, OP_HOUR);


 A4GL_debug("Buff = %s",A4GL_null_as_null(buff));
  // d will now be a number of years or a number of seconds.
  if ((a == (OP_YEAR)) || (a == (OP_MONTH)))
    {
      A4GL_debug ("%d %d", (a == (OP_YEAR)), (a == (OP_MONTH)));
      A4GL_debug ("11 Calling acli_interval for year to month");
      acli_interval (buff, 1042);	// YEAR(4) TO MONTH
    }
  else
    {
      SPRINTF1 (buff, "%f", d);
      A4GL_debug ("11 Calling acli_interval for second to fraction");
      acli_interval (buff, 0x46b);	// SECOND(4) TO FRACTION(5)
    }

  return 1;
}

/*  *************************************************
* IN & EXISTS with SQL required some bindings ....
***************************************************/


/**
 *
 *
 * @return
 */
int
A4GL_push_binding (void *ptr, int num)
{
//int n;

  if (local_binding_cnt >= LOCAL_BINDINGS)
    {
      A4GL_exitwith ("Too many bindings");
      return 0;
    }

  local_binding[local_binding_cnt] = ptr;
  num_local_binding[local_binding_cnt] = num;
  local_binding_cnt++;

  return 0;
}

/**
 *
 *
 * @return
 */
void *
dif_start_bind (void)
{
  struct bound_list *list;
  A4GL_debug ("10 STarting bind");
  list = acl_malloc2 (sizeof (struct bound_list));
  list->ptr = 0;
  list->cnt = 0;
  list->popped = -1;
  return (void *) list;
}

/**
 *
 *
 * @return
 */
void
dif_add_bind (struct bound_list *list, void *dptr, int dtype, int size)
{
  int a;
//int l;
//struct BINDING *b;
//struct BINDING **pp;

  a = list->cnt + 1;
  list->ptr = realloc (list->ptr, sizeof (struct BINDING) * a);
  list->ptr[a - 1].ptr = dptr;
  list->ptr[a - 1].dtype = dtype;
  list->ptr[a - 1].size = size;
  list->cnt++;
}


/**
 *
 *
 * @return
 */
void
dif_add_bind_date (struct bound_list *list, long a)
{
  int *z;
  z = acl_malloc2 (sizeof (int));
  *z = a;
  dif_add_bind (list, z, DTYPE_DATE, 0);
}

/**
 *
 *
 * @return
 */
void
dif_add_bind_smint (struct bound_list *list, int a)
{
  short *z;
  z = acl_malloc2 (sizeof (short));
  *z = a;
  dif_add_bind (list, z, DTYPE_SMINT, 0);
}

/**
 *
 *
 * @return
 */
void
dif_add_bind_smint_ptr (struct bound_list *list, short *a)
{
  dif_add_bind (list, a, DTYPE_SMINT, 0);
}

/**
 *
 *
 * @return
 */
void
dif_add_bind_dbl_ptr (struct bound_list *list, double *a)
{
  dif_add_bind (list, a, DTYPE_FLOAT, 0);
  *a = 3.142;
}

/**
 *
 *
 * @return
 */
void
dif_add_bind_int (struct bound_list *list, long a)
{
  long *z;
  z = acl_malloc2 (sizeof (long));
  *z = a;
  dif_add_bind (list, z, DTYPE_INT, 0);
}

/**
 *
 *
 * @return
 */
void
dif_add_bind_float (struct bound_list *list, double a)
{
  double *z;
  z = acl_malloc2 (sizeof (double));
  *z = a;
  dif_add_bind (list, z, DTYPE_FLOAT, 0);
}

/**
 *
 *
 * @return
 */
void
dif_add_bind_smfloat (struct bound_list *list, float a)
{
  float *z;
  z = acl_malloc2 (sizeof (int));
  *z = a;
  dif_add_bind (list, z, DTYPE_SMFLOAT, 0);
}

/**
 *
 *
 * @return
 */
void
dif_add_bind_char (struct bound_list *list, char *a)
{
  char *z;
  z = acl_strdup (a);
  dif_add_bind (list, z, DTYPE_CHAR, strlen (z));
}


/**
 *
 *
 * @return
 */
void
dif_free_bind (struct bound_list *list)
{
//int a;
  A4GL_debug ("10 free bind");
  free (list->ptr);
  free (list);
}

/**
 *
 *
 * @return
 */
void *
dif_get_bind (struct bound_list *list)
{
  A4GL_debug ("10 get bind");
  return list->ptr;
}

/**
 *
 *
 * @return
 */
void
dif_print_bind (struct bound_list *list)
{
  int a;
  for (a = 0; a < list->cnt; a++)
    {
      A4GL_debug ("10 %p(%x) %d %d\n",
	     list->ptr[a].ptr,
	     *((int *) list->ptr[a].ptr),
	     list->ptr[a].dtype, list->ptr[a].size);
    }
}


/**
 *
 *
 * @return
 */
long
dif_pop_bind_int (struct bound_list *list)
{
  long a;
  if (list->popped == -1)
    list->popped = list->cnt - 1;
  a = *(long *) list->ptr[list->popped].ptr;
  return a;
}

/**
 *
 *
 * @return
 */
char *
dif_pop_bind_char (struct bound_list *list)
{
  char *a;
  if (list->popped == -1)
    list->popped = list->cnt - 1;
  a = list->ptr[list->popped].ptr;
  return a;
}

/**
 *
 *
 * @return
 */
int
dif_pop_bind_smint (struct bound_list *list)
{
  int a;
  if (list->popped == -1)
    list->popped = list->cnt - 1;
  a = *(int *) list->ptr[list->popped].ptr;
  return a;
}

/**
 *
 *
 * @return
 */
int
dif_pop_bind_float (struct bound_list *list)
{
  double a;
  if (list->popped == -1)
    list->popped = list->cnt - 1;
  a = *(double *) list->ptr[list->popped].ptr;
  return a;
}

/**
 *
 *
 * @return
 */
int
dif_pop_bind_smfloat (struct bound_list *list)
{
  float a;
  if (list->popped == -1)
    list->popped = list->cnt - 1;
  a = *(float *) list->ptr[list->popped].ptr;
  return a;
}

/**
 * Pop a bind to decimal data type.
 *
 * @todo This function is returning a ptr and is declared to return an int
 * We must understand why this is like this and fixed to the compiler
 * does not give warnings
 *
 * @param list
 */
int
dif_pop_bind_dec (struct bound_list *list)
{
//  char *a;

  if (list->popped == -1)
    list->popped = list->cnt - 1;
  //return (int) list->ptr[list->popped].ptr;
  return (int)(long) list->ptr[list->popped].ptr;
}

/**
 * @todo This function is returning a ptr and is declared to return an int
 * We must undestartand why this is like this and fixed to the compiler
 * does not give warnings
 *
 * @param list
 */
int
dif_pop_bind_money (struct bound_list *list)
{
//  char *a;
  if (list->popped == -1)
    list->popped = list->cnt - 1;
  return (int)(long) list->ptr[list->popped].ptr;
}




char *A4GL_lrtrim (char *str)
{
      char *obuf;
	char *s=0;
A4GL_debug("new lrtrim");
      if (str)
      {
            for (obuf = str; *obuf && isspace(*obuf); ++obuf)
                  ;
            if (str != obuf) {
		s=acl_strdup(obuf);
		strcpy(str,s);
		free(s);
	    }
  	   A4GL_trim(str);
      }
	A4GL_debug("Trimmed :'%s'",str);
      return str;
}




static char escape_chr;
void
A4GL_set_escape (char *s)
{
  escape_chr = s[0];
}

int
A4GL_get_escape_chr (void)
{
  return (int) escape_chr;
}


int A4GL_conversion_ok(int a) {
	static int ok=0;
	if (a==1) {ok=1;return 1;}
	if (a==0) {ok=0;return 0;}
	return ok;
}




/* This function enables debugging - basically you can 
put in a call to A4GL_pause_execution in the library then set a gdb breakpoint for this
function call - this allows code like :

if (a==1 || a==2) A4GL_pause_execution() // I wasn't expected a 1 or a 2 

to be debugged...

*/
void A4GL_pause_execution(void) {
	A4GL_pause_execution_msg("");
}

void A4GL_pause_execution_msg(char *s) {
	PRINTF("--PAUSE EXECUTION->%s\n",s);
}

void a4gl_upshift(char *s) {
	int a;
	int l;
	l=strlen(s);
	for (a=0;a<l;a++) {
		s[a]=toupper(s[a]);
	}
}


int get_null_as_pad_string() {
	static int x=-1;
	if (x==-1) {
		if (A4GL_isno(acl_getenv("PADNULLSTRING"))) {
			x=0;
		} else {
			x=1;
		}
	}
	return x;
}
 
double get_now_as_double(void) {
	  struct timeval tv1;
	    double d;
	      gettimeofday (&tv1, 0);
	        d=(double)tv1.tv_sec+(((double)tv1.tv_usec)/1000000.0);
		  return d;

}



// ================================ EOF ================================
