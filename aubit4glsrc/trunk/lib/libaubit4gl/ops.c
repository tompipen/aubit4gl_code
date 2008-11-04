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
# $Id: ops.c,v 1.140 2008-11-04 17:55:27 mikeaubury Exp $
#
*/

/**
 * @file
 * Data type operations functions
 *
 * This is complex stuff
 * What we want to be able to do is add datatypes programatically
 * We therefor maintain a list of available datatypes
 * and their various conversion routines..
 *
 * This is very much a work in progress....
 *
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#define EXTERN_CONVFMTS
#include "a4gl_libaubit4gl_int.h"
#include "m_apm.h"

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

static void push_dec_op_from_int_int (int a, int b, char op);
void A4GL_push_dec_from_apm (M_APM tmp);
void A4GL_date_date_ops (int op);
void A4GL_date_int_ops (int op);
void A4GL_int_date_ops (int op);
double a4gl_local_trunc (double f);
void A4GL_smfloat_float_ops (int op);
void A4GL_float_smfloat_ops (int op);
void A4GL_smfloat_smfloat_ops (int op);
void A4GL_char_dt_ops (int op);
//void A4GL_add_op_function (int dtype1, int dtype2, int op, void (*function)(int ops));

void A4GL_int_int_ops (int op);
int A4GL_dectos (void *z, void *w, int size);
//char * A4GL_make_using_tostring (char *ptr, int d, int n);

void A4GL_add_default_operations (void);
void A4GL_dt_in_ops (int op);
void A4GL_in_dt_ops (int op);
//void A4GL_decode_datetime (struct A4GLSQL_dtime *d, int *data);
//void A4GL_ltrim(char *s) ;
void A4GL_dt_char_ops (int op);
void A4GL_dt_dt_ops (int op);
//int A4GL_ctodt (void *a, void *b, int size);
//int A4GL_ctoint (void *a, void *b, int size);


char *A4GL_display_int (void *ptr, int size, int string_sz, struct struct_scr_field *field_details, int display_type);
char *A4GL_display_smint (void *ptr, int size, int string_sz, struct struct_scr_field *field_details, int display_type);
char *A4GL_display_float (void *ptr, int size, int string_sz, struct struct_scr_field *field_details, int display_type);
char *A4GL_display_smfloat (void *ptr, int size, int string_sz, struct struct_scr_field *field_details, int display_type);
char *A4GL_display_date (void *ptr, int size, int string_sz, struct struct_scr_field *field_details, int display_type);
char *A4GL_display_char (void *ptr, int size, int string_sz, struct struct_scr_field *field_details, int display_type);
char *A4GL_display_vchar (void *ptr, int size, int string_sz, struct struct_scr_field *field_details, int display_type);
char *A4GL_display_decimal (void *ptr, int size, int string_sz, struct struct_scr_field *field_details, int display_type);
char *A4GL_display_money (void *ptr, int size, int string_sz, struct struct_scr_field *field_details, int display_type);
char *A4GL_display_dtime (void *ptr, int size, int string_sz, struct struct_scr_field *field_details, int display_type);
char *A4GL_display_interval (void *ptr, int size, int string_sz, struct struct_scr_field *field_details, int display_type);
char *A4GL_display_byte (void *ptr, int size, int string_sz, struct struct_scr_field *field_details, int display_type);
char *A4GL_display_text (void *ptr, int size, int string_sz, struct struct_scr_field *field_details, int display_type);


static char *make_using_sz (char *ptr, int sz, int dig, int dec);
char *A4GL_tostring_decimal (void *p, int size, char *s_in, int n_in);

void A4GL_in_date_ops (int op);
void A4GL_dt_date_ops (int op);
void A4GL_date_dt_ops (int op);
int A4GL_days_in_month (int m, int y);

void A4GL_in_int_ops (int op);
void A4GL_int_in_ops (int op);

void A4GL_in_double_ops (int op);
void A4GL_double_in_ops (int op);

#define NUM_DIG(x)               ((x[0])&127 )
#define NUM_DEC(x)               ((x[1]))

/*
=====================================================================
                    Functions definitions
=====================================================================

*/

static int
isCompare (int op)
{
  switch (op)
    {
    case OP_LESS_THAN:
    case OP_GREATER_THAN:
    case OP_LESS_THAN_EQ:
    case OP_GREATER_THAN_EQ:
    case OP_EQUAL:
    case OP_NOT_EQUAL:
      return 1;
    }
  return 0;
}


double
a4gl_local_trunc (double d)
{
  if (d < 0)
    return ceil (d);
  return floor (d);
}




static int
A4GL_dtype_function_char_getlength (char *base, int nparam)
{
  if (nparam != 0)
    {
      return 0;
    }
  A4GL_push_char (base);
  return aclfgl_length (1);
}




char *
A4GL_tostring_decimal (void *p, int size, char *s_in, int n_in)
{
  static char buff_1[256];
//int n,l;
//fgldecimal *p_d;
  char *ptr2;
//int string_sz;
  char *ptr;

  ptr2 = p;
  if (s_in != 0 || n_in != 0)
    {
      A4GL_debug ("EXPECTING s_in=0 and n_in=0\n");
      return 0;
    }

  if (A4GL_isnull (DTYPE_DECIMAL, ptr2))
    {
      int n;
      n = size >> 8;
      if (size & 255)
	n++;
      memset (buff_1, ' ', n);
      buff_1[n] = 0;
      return buff_1;
    }

//size=(NUM_DIG(ptr2)<<8)+NUM_DEC(ptr2);
  A4GL_push_dec (p, 0, size);

//n=NUM_DIG(ptr2);
//l=NUM_DEC(ptr2);
//string_sz=n;
//if (l) string_sz++;


  ptr = A4GL_make_using_tostring (ptr2, size >> 8, size & 255);	//,string_sz,n*2,l);
  A4GL_debug ("Make using returns %s", ptr);
  A4GL_push_char (ptr);
  A4GL_pushop (OP_USING);
  ptr = A4GL_char_pop ();
  strcpy (buff_1, ptr);
  free (ptr);
  A4GL_decstr_convert (buff_1, a4gl_convfmts.using_decfmt, a4gl_convfmts.posix_decfmt, 0, 0, -1);
  return buff_1;
}

/******************************************************************************/

void
A4GL_dec_dec_ops (int op)
{
  fgldecimal a;
  fgldecimal b;
  fgldecimal dc;
  long l1;
  long l2;
  double dbl;
  int d;
  int d1, d2, s1, s2, ndig1, ndec1, ndig2, ndec2;
  char *ptr1;
  char *ptr2;
  int res_dec;
  int res_dig;
  int res1;
  int res2;
  char buff_a[101];
  char buff_b[101];

  A4GL_get_top_of_stack (1, &d1, &s1, (void **) &ptr1);
  A4GL_get_top_of_stack (2, &d2, &s2, (void **) &ptr2);

  ndig1 = s1 >> 8;
  ndec1 = s1 & 0xff;

  ndig2 = s2 >> 8;
  ndec2 = s2 & 0xff;

  //char *a1;
  //char *a2;
  A4GL_pop_var2 (&b, DTYPE_DECIMAL, s1);
  A4GL_pop_var2 (&a, DTYPE_DECIMAL, s2);
  if (ndig2 == 64 && ndec2 == 32)
    {
      int cnt;
      int len;
      A4GL_dectos (&a, buff_a, 100);
      A4GL_remove_trailing_zeros_and_leading_spaces (buff_a);
      len = strlen (buff_a);
      ndig2 = len;
      ndec2 = 0;
      for (cnt = 0; cnt < len; cnt++)
	{
	  if (buff_a[cnt] == '.' || buff_a[cnt]==',')
	    {
	      ndec2 = len - cnt;
	      break;
	    }
	}

    }
  if (ndig1 == 64 && ndec1 == 32)
    {
      int cnt;
      int len;
      A4GL_dectos (&b, buff_b, 100);
      A4GL_remove_trailing_zeros_and_leading_spaces (buff_b);
      len = strlen (buff_a);
      ndig1 = len;
      ndec1 = 0;
      for (cnt = 0; cnt < len; cnt++)
	{
	  if (buff_b[cnt] == '.' || buff_b[cnt]==',')
	    {
	      ndec1 = len - cnt;
	      break;
	    }
	}
    }


  res1 = ndig1 - ndec1;
  res2 = ndig2 - ndec2;
  if (res1 < res2)
    {
      res_dig = res2;
    }
  else
    {
      res_dig = res1;
    }

  if (ndec1 < ndec2)
    {
      res_dec = ndec2;
    }
  else
    {
      res_dec = ndec1;
    }

  res_dig += res_dec;
//printf("%d , %d\n", res_dig, res_dec);
  if (A4GL_isnull (DTYPE_DECIMAL, (void *) &a) || A4GL_isnull (DTYPE_DECIMAL, (void *) &b))
    {
      if (isCompare (op))
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_DECIMAL, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }

  switch (op)
    {
    case OP_ADD:
      if (res_dig > 31)
	res_dig = 31;
      if (res_dec > res_dig)
	res_dec = 0;

      A4GL_init_dec (&dc, res_dig + 1, res_dec);
      a4gl_decadd (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 32);
      return;

    case OP_SUB:
      if (res_dig > 31)
	res_dig = 31;
      if (res_dec > res_dig)
	res_dec = 0;
      A4GL_init_dec (&dc, res_dig + 1, res_dec);
      a4gl_decsub (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 32);
      return;

    case OP_MULT:
      res_dig = ndig1 + ndig2;
      res_dec = ndec1 + ndec2;
      if (res_dig > 31) {
		// If we overflow - try to work out the size later...
		res_dig=0;
		res_dec=0;
      }

      if (res_dec > res_dig)
	{
	  res_dig = 32;
	  res_dec = 16;
	}


	if (res_dig) {
      		A4GL_init_dec (&dc, res_dig + 1, res_dec);
	} else {
      		A4GL_init_dec(&dc,0,0);
	}
      
      a4gl_decmul (&a, &b, &dc);

      
      A4GL_push_dec_dec (&dc, 0, 32);


      return;

    case OP_DIV:
      A4GL_init_dec (&dc, 32, 16);
      a4gl_decdiv (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 32);
      return;

    case OP_MOD:
      if (res_dig > 31)
	res_dig = 31;
      if (res_dec > res_dig)
	res_dec = 0;
      A4GL_init_dec (&dc, res_dig + 1, res_dec);
      a4gl_dectolong (&a, &l1);
      a4gl_dectolong (&b, &l2);
      A4GL_push_long (l1 % l2);
      return;

    case OP_POWER:
      A4GL_init_dec (&dc, 64, 32);
      a4gl_dectolong (&b, &l2);
      if (l2 == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (l2 == 1)
	{
	  a4gl_dectodbl (&a, &dbl);
	  A4GL_push_float (dbl);
	  return;
	}

      a4gl_deccopy (&dc, &a);
      for (d = 1; d < l2; d++)
	a4gl_decmul (&dc, &a, &dc);
      A4GL_push_dec_dec (&dc, 0, 32);
      return;

    case OP_LESS_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) < 0);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) > 0);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) <= 0);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) >= 0);
      return;
    case OP_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) == 0);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) != 0);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}


/******************************************************************************/

static void
A4GL_mon_dec_ops (int op)
{
  fgldecimal a;
  fgldecimal b;
  fgldecimal dc;
  long l1;
  long l2;
  double dbl;
  int d;
  //char *a1;
  //char *a2;
  
//A4GL_pause_execution();
  A4GL_pop_sized_decimal(&b);
  A4GL_pop_sized_decimal(&a);
//
  //A4GL_pop_var2 (&b, 5, 0x2010);
  //A4GL_pop_var2 (&a, 5, 0x2010);

  if (A4GL_isnull (DTYPE_MONEY, (void *) &a) || A4GL_isnull (DTYPE_MONEY, (void *) &b))
    {
      if (isCompare (op))
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_MONEY, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }
  A4GL_init_dec (&dc, 32, 16);

  switch (op)
    {
    case OP_ADD:
      a4gl_decadd (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;
    case OP_SUB:
      a4gl_decsub (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;
    case OP_MULT:
      a4gl_decmul (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;


    case OP_DIV:
      a4gl_decdiv (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;

    case OP_MOD:
      a4gl_dectolong (&a, &l1);
      a4gl_dectolong (&b, &l2);
      A4GL_push_long (l1 % l2);
      return;

    case OP_POWER:
      a4gl_dectolong (&b, &l2);
      if (l2 == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (l2 == 1)
	{
	  a4gl_dectodbl (&a, &dbl);
	  A4GL_push_float (dbl);
	  return;
	}

      a4gl_deccopy (&dc, &a);
      for (d = 1; d < l2; d++)
	a4gl_decmul (&dc, &a, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;

    case OP_LESS_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) < 0);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) > 0);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) <= 0);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) >= 0);
      return;
    case OP_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) == 0);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) != 0);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

/******************************************************************************/

static void
A4GL_dec_mon_ops (int op)
{
  fgldecimal a;
  fgldecimal b;
  fgldecimal dc;
  long l1;
  long l2;
  double dbl;
  int d;
  //char *a1;
  //char *a2;
  A4GL_pop_sized_decimal(&b);
  A4GL_pop_sized_decimal(&a);
  //A4GL_pop_var2 (&b, 5, 0x2010);
  //A4GL_pop_var2 (&a, 5, 0x2010);

  if (A4GL_isnull (DTYPE_MONEY, (void *) &a) || A4GL_isnull (DTYPE_MONEY, (void *) &b))
    {
      if (isCompare (op))
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_MONEY, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }
  A4GL_init_dec (&dc, 32, 16);

  switch (op)
    {
    case OP_ADD:
      a4gl_decadd (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;
    case OP_SUB:
      a4gl_decsub (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;
    case OP_MULT:
      a4gl_decmul (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;


    case OP_DIV:
      a4gl_decdiv (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;

    case OP_MOD:
      a4gl_dectolong (&a, &l1);
      a4gl_dectolong (&b, &l2);
      A4GL_push_long (l1 % l2);
      return;

    case OP_POWER:
      a4gl_dectolong (&b, &l2);
      if (l2 == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (l2 == 1)
	{
	  a4gl_dectodbl (&a, &dbl);
	  A4GL_push_float (dbl);
	  return;
	}

      a4gl_deccopy (&dc, &a);
      for (d = 1; d < l2; d++)
	a4gl_decmul (&dc, &a, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;

    case OP_LESS_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) < 0);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) > 0);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) <= 0);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) >= 0);
      return;
    case OP_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) == 0);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) != 0);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

/******************************************************************************/

static void
A4GL_mon_mon_ops (int op)
{
  fgldecimal a;
  fgldecimal b;
  fgldecimal dc;
  long l1;
  long l2;
  double dbl;
  int d;
  //char *a1;
  //char *a2;
  //A4GL_pop_var2 (&b, 5, 0x2010);
  //A4GL_pop_var2 (&a, 5, 0x2010);
  A4GL_pop_sized_decimal(&b);
  A4GL_pop_sized_decimal(&a);

  if (A4GL_isnull (DTYPE_MONEY, (void *) &a) || A4GL_isnull (DTYPE_MONEY, (void *) &b))
    {
      if (isCompare (op))
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_MONEY, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }
  A4GL_init_dec (&dc, 32, 16);

  switch (op)
    {
    case OP_ADD:
      a4gl_decadd (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;
    case OP_SUB:
      a4gl_decsub (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;
    case OP_MULT:
      a4gl_decmul (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;


    case OP_DIV:
      a4gl_decdiv (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;

    case OP_MOD:
      a4gl_dectolong (&a, &l1);
      a4gl_dectolong (&b, &l2);
      A4GL_push_long (l1 % l2);
      return;

    case OP_POWER:
      a4gl_dectolong (&b, &l2);
      if (l2 == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (l2 == 1)
	{
	  a4gl_dectodbl (&a, &dbl);
	  A4GL_push_float (dbl);
	  return;
	}

      a4gl_deccopy (&dc, &a);
      for (d = 1; d < l2; d++)
	a4gl_decmul (&dc, &a, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;

    case OP_LESS_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) < 0);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) > 0);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) <= 0);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) >= 0);
      return;
    case OP_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) == 0);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) != 0);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

/******************************************************************************/

static void
A4GL_dec_sm_ops (int op)
{
  fgldecimal a;
  fgldecimal b;
  fgldecimal dc;
  long l1;
  long l2;
  double dbl;
  int d;
  //char *a1;
  //char *a2;
  A4GL_pop_var2 (&b, 5, 0x2000);
  //A4GL_pop_var2 (&a, 5, 0x2010);
  A4GL_pop_sized_decimal(&a);

  if (A4GL_isnull (DTYPE_DECIMAL, (void *) &a) || A4GL_isnull (DTYPE_DECIMAL, (void *) &b))
    {
      if (isCompare (op))
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_DECIMAL, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }
  A4GL_init_dec (&dc, 32, 16);

  switch (op)
    {
    case OP_ADD:
      a4gl_decadd (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;
    case OP_SUB:
      a4gl_decsub (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;
    case OP_MULT:
      a4gl_decmul (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;


    case OP_DIV:
      a4gl_decdiv (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;

    case OP_MOD:
      a4gl_dectolong (&a, &l1);
      a4gl_dectolong (&b, &l2);
      A4GL_push_long (l1 % l2);
      return;

    case OP_POWER:
      a4gl_dectolong (&b, &l2);
      if (l2 == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (l2 == 1)
	{
	  a4gl_dectodbl (&a, &dbl);
	  A4GL_push_float (dbl);
	  return;
	}

      a4gl_deccopy (&dc, &a);
      for (d = 1; d < l2; d++)
	a4gl_decmul (&dc, &a, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;

    case OP_LESS_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) < 0);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) > 0);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) <= 0);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) >= 0);
      return;
    case OP_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) == 0);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) != 0);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

/******************************************************************************/

static void
A4GL_mon_sm_ops (int op)
{
  fgldecimal a;
  fgldecimal b;
  fgldecimal dc;
  long l1;
  long l2;
  double dbl;
  int d;
  //char *a1;
  //char *a2;
  A4GL_pop_var2 (&b, 5, 0x2000);
  //A4GL_pop_var2 (&a, 5, 0x2010);
  A4GL_pop_sized_decimal(&a);

  if (A4GL_isnull (DTYPE_MONEY, (void *) &a) || A4GL_isnull (DTYPE_MONEY, (void *) &b))
    {
      if (isCompare (op))
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_MONEY, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }
  A4GL_init_dec (&dc, 32, 16);

  switch (op)
    {
    case OP_ADD:
      a4gl_decadd (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);	// MONEY
      return;
    case OP_SUB:
      a4gl_decsub (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);	// MONEY
      return;
    case OP_MULT:
      a4gl_decmul (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);	// MONEY
      return;


    case OP_DIV:
      a4gl_decdiv (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);	// MONEY
      return;

    case OP_MOD:
      a4gl_dectolong (&a, &l1);
      a4gl_dectolong (&b, &l2);
      A4GL_push_long (l1 % l2);
      return;

    case OP_POWER:
      a4gl_dectolong (&b, &l2);
      if (l2 == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (l2 == 1)
	{
	  a4gl_dectodbl (&a, &dbl);
	  A4GL_push_float (dbl);
	  return;
	}

      a4gl_deccopy (&dc, &a);
      for (d = 1; d < l2; d++)
	a4gl_decmul (&dc, &a, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);	// MONEY
      return;

    case OP_LESS_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) < 0);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) > 0);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) <= 0);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) >= 0);
      return;
    case OP_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) == 0);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) != 0);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

/******************************************************************************/

static void
A4GL_dec_int_ops (int op)
{
  fgldecimal a;
  fgldecimal b;
  fgldecimal dc;
  long l1;
  long l2;
  double dbl;
  int d;
  //char *a1;
  //char *a2;
  A4GL_pop_var2 (&b, 5, 0x2000);
  //A4GL_pop_var2 (&a, 5, 0x2010);
  A4GL_pop_sized_decimal(&a);

  if (A4GL_isnull (DTYPE_DECIMAL, (void *) &a) || A4GL_isnull (DTYPE_DECIMAL, (void *) &b))
    {
      if (isCompare (op))
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_DECIMAL, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }
  A4GL_init_dec (&dc, 32, 16);

  switch (op)
    {
    case OP_ADD:
      a4gl_decadd (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;
    case OP_SUB:
      a4gl_decsub (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;
    case OP_MULT:
      a4gl_decmul (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;


    case OP_DIV:
      a4gl_decdiv (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;

    case OP_MOD:
      a4gl_dectolong (&a, &l1);
      a4gl_dectolong (&b, &l2);
      A4GL_push_long (l1 % l2);
      return;

    case OP_POWER:
      a4gl_dectolong (&b, &l2);
      if (l2 == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (l2 == 1)
	{
	  a4gl_dectodbl (&a, &dbl);
	  A4GL_push_float (dbl);
	  return;
	}

      a4gl_deccopy (&dc, &a);
      for (d = 1; d < l2; d++)
	a4gl_decmul (&dc, &a, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;

    case OP_LESS_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) < 0);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) > 0);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) <= 0);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) >= 0);
      return;
    case OP_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) == 0);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) != 0);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

/******************************************************************************/

static void
A4GL_mon_int_ops (int op)
{
  fgldecimal a;
  fgldecimal b;
  fgldecimal dc;
  long l1;
  long l2;
  double dbl;
  int d;
  //char *a1;
  //char *a2;
  A4GL_pop_var2 (&b, 5, 0x2000);
  //A4GL_pop_var2 (&a, 5, 0x2010);
  A4GL_pop_sized_decimal(&a);

  if (A4GL_isnull (DTYPE_MONEY, (void *) &a) || A4GL_isnull (DTYPE_MONEY, (void *) &b))
    {
      if (isCompare (op))
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_MONEY, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }
  A4GL_init_dec (&dc, 32, 16);

  switch (op)
    {
    case OP_ADD:
      a4gl_decadd (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;
    case OP_SUB:
      a4gl_decsub (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;
    case OP_MULT:
      a4gl_decmul (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;


    case OP_DIV:
      a4gl_decdiv (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;

    case OP_MOD:
      a4gl_dectolong (&a, &l1);
      a4gl_dectolong (&b, &l2);
      A4GL_push_long (l1 % l2);
      return;

    case OP_POWER:
      a4gl_dectolong (&b, &l2);
      if (l2 == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (l2 == 1)
	{
	  a4gl_dectodbl (&a, &dbl);
	  A4GL_push_float (dbl);
	  return;
	}

      a4gl_deccopy (&dc, &a);
      for (d = 1; d < l2; d++)
	a4gl_decmul (&dc, &a, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;

    case OP_LESS_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) < 0);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) > 0);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) <= 0);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) >= 0);
      return;
    case OP_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) == 0);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) != 0);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}


/******************************************************************************/

static void
A4GL_dec_float_ops (int op)
{
  fgldecimal a;
  fgldecimal b;
  fgldecimal dc;
  long l1;
  long l2;
  double dbl;
  int d;
  //char *a1;
  //char *a2;
  A4GL_pop_var2 (&b, 5, 0x2005);
  //A4GL_pop_var2 (&a, 5, 0x2010);
  A4GL_pop_sized_decimal(&a);

  if (A4GL_isnull (DTYPE_DECIMAL, (void *) &a) || A4GL_isnull (DTYPE_DECIMAL, (void *) &b))
    {
      if (isCompare (op))
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_DECIMAL, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }
  A4GL_init_dec (&dc, 32, 16);

  switch (op)
    {
    case OP_ADD:
      a4gl_decadd (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;
    case OP_SUB:
      a4gl_decsub (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;
    case OP_MULT:
      a4gl_decmul (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;


    case OP_DIV:
      a4gl_decdiv (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;

    case OP_MOD:
      a4gl_dectolong (&a, &l1);
      a4gl_dectolong (&b, &l2);
      A4GL_push_long (l1 % l2);
      return;

    case OP_POWER:
      a4gl_dectolong (&b, &l2);
      if (l2 == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (l2 == 1)
	{
	  a4gl_dectodbl (&a, &dbl);
	  A4GL_push_float (dbl);
	  return;
	}

      a4gl_deccopy (&dc, &a);
      for (d = 1; d < l2; d++)
	a4gl_decmul (&dc, &a, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;

    case OP_LESS_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) < 0);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) > 0);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) <= 0);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) >= 0);
      return;
    case OP_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) == 0);
      return;
    case OP_NOT_EQUAL:

      A4GL_push_int (a4gl_deccmp (&a, &b) != 0);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

/******************************************************************************/

static void
A4GL_dec_smfloat_ops (int op)
{
  fgldecimal a;
  fgldecimal b;
  fgldecimal dc;
  long l1;
  long l2;
  double dbl;
  int d;
  //char *a1;
  //char *a2;
  A4GL_pop_var2 (&b, 5, 0x2005);
  //A4GL_pop_var2 (&a, 5, 0x2010);
  A4GL_pop_sized_decimal(&a);

  if (A4GL_isnull (DTYPE_DECIMAL, (void *) &a) || A4GL_isnull (DTYPE_DECIMAL, (void *) &b))
    {
      if (isCompare (op))
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_DECIMAL, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }
  A4GL_init_dec (&dc, 32, 16);

  switch (op)
    {
    case OP_ADD:
      a4gl_decadd (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;
    case OP_SUB:
      a4gl_decsub (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;
    case OP_MULT:
      a4gl_decmul (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;


    case OP_DIV:
      a4gl_decdiv (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;

    case OP_MOD:
      a4gl_dectolong (&a, &l1);
      a4gl_dectolong (&b, &l2);
      A4GL_push_long (l1 % l2);
      return;

    case OP_POWER:
      a4gl_dectolong (&b, &l2);
      if (l2 == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (l2 == 1)
	{
	  a4gl_dectodbl (&a, &dbl);
	  A4GL_push_float (dbl);
	  return;
	}

      a4gl_deccopy (&dc, &a);
      for (d = 1; d < l2; d++)
	a4gl_decmul (&dc, &a, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;

    case OP_LESS_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) < 0);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) > 0);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) <= 0);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) >= 0);
      return;
    case OP_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) == 0);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) != 0);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}


/******************************************************************************/

static void
A4GL_mon_float_ops (int op)
{
  fgldecimal a;
  fgldecimal b;
  fgldecimal dc;
  long l1;
  long l2;
  double dbl;
  int d;
  //char *a1;
  //char *a2;
  A4GL_pop_var2 (&b, 5, 0x2005);
  //A4GL_pop_var2 (&a, 5, 0x2010);
  A4GL_pop_sized_decimal(&a);
  if (A4GL_isnull (DTYPE_MONEY, (void *) &a) || A4GL_isnull (DTYPE_MONEY, (void *) &b))
    {
      if (isCompare (op))
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_MONEY, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }
  A4GL_init_dec (&dc, 32, 16);

  switch (op)
    {
    case OP_ADD:
      a4gl_decadd (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;
    case OP_SUB:
      a4gl_decsub (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;
    case OP_MULT:
      a4gl_decmul (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;


    case OP_DIV:
      a4gl_decdiv (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;

    case OP_MOD:
      a4gl_dectolong (&a, &l1);
      a4gl_dectolong (&b, &l2);
      A4GL_push_long (l1 % l2);
      return;

    case OP_POWER:
      a4gl_dectolong (&b, &l2);
      if (l2 == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (l2 == 1)
	{
	  a4gl_dectodbl (&a, &dbl);
	  A4GL_push_float (dbl);
	  return;
	}

      a4gl_deccopy (&dc, &a);
      for (d = 1; d < l2; d++)
	a4gl_decmul (&dc, &a, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;

    case OP_LESS_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) < 0);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) > 0);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) <= 0);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) >= 0);
      return;
    case OP_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) == 0);
      return;
    case OP_NOT_EQUAL:

      A4GL_push_int (a4gl_deccmp (&a, &b) != 0);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

/******************************************************************************/

static void
A4GL_mon_smfloat_ops (int op)
{
  fgldecimal a;
  fgldecimal b;
  fgldecimal dc;
  long l1;
  long l2;
  double dbl;
  int d;
  //char *a1;
  //char *a2;
  A4GL_pop_var2 (&b, 5, 0x2005);
  //A4GL_pop_var2 (&a, 5, 0x2010);
  A4GL_pop_sized_decimal(&a);

  if (A4GL_isnull (DTYPE_MONEY, (void *) &a) || A4GL_isnull (DTYPE_MONEY, (void *) &b))
    {
      if (isCompare (op))
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_MONEY, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }
  A4GL_init_dec (&dc, 32, 16);

  switch (op)
    {
    case OP_ADD:
      a4gl_decadd (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);	// MONEY
      return;
    case OP_SUB:
      a4gl_decsub (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);	// MONEY
      return;
    case OP_MULT:
      a4gl_decmul (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);	// MONEY
      return;


    case OP_DIV:
      a4gl_decdiv (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);	// MONEY
      return;

    case OP_MOD:
      a4gl_dectolong (&a, &l1);
      a4gl_dectolong (&b, &l2);
      A4GL_push_long (l1 % l2);
      return;

    case OP_POWER:
      a4gl_dectolong (&b, &l2);
      if (l2 == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (l2 == 1)
	{
	  a4gl_dectodbl (&a, &dbl);
	  A4GL_push_float (dbl);
	  return;
	}

      a4gl_deccopy (&dc, &a);
      for (d = 1; d < l2; d++)
	a4gl_decmul (&dc, &a, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);	// MONEY
      return;

    case OP_LESS_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) < 0);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) > 0);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) <= 0);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) >= 0);
      return;
    case OP_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) == 0);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) != 0);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}


/******************************************************************************/

static void
A4GL_sm_dec_ops (int op)
{
  fgldecimal a;
  fgldecimal b;
  fgldecimal dc;
  long l1;
  long l2;
  double dbl;
  int d;
  //char *a1;
  //char *a2;
  //A4GL_pop_var2 (&b, 5, 0x2010);
  A4GL_pop_sized_decimal(&b);
  A4GL_pop_var2 (&a, 5, 0x2005);

  if (A4GL_isnull (DTYPE_DECIMAL, (void *) &a) || A4GL_isnull (DTYPE_DECIMAL, (void *) &b))
    {
      if (isCompare (op))
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_DECIMAL, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }
  A4GL_init_dec (&dc, 32, 16);

  switch (op)
    {
    case OP_ADD:
      a4gl_decadd (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;
    case OP_SUB:
      a4gl_decsub (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;
    case OP_MULT:
      a4gl_decmul (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;


    case OP_DIV:
      a4gl_decdiv (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;

    case OP_MOD:
      a4gl_dectolong (&a, &l1);
      a4gl_dectolong (&b, &l2);
      A4GL_push_long (l1 % l2);
      return;

    case OP_POWER:
      a4gl_dectolong (&b, &l2);
      if (l2 == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (l2 == 1)
	{
	  a4gl_dectodbl (&a, &dbl);
	  A4GL_push_float (dbl);
	  return;
	}

      a4gl_deccopy (&dc, &a);
      for (d = 1; d < l2; d++)
	a4gl_decmul (&dc, &a, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;

    case OP_LESS_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) < 0);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) > 0);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) <= 0);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) >= 0);
      return;
    case OP_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) == 0);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) != 0);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

/******************************************************************************/

static void
A4GL_int_dec_ops (int op)
{
  fgldecimal a;
  fgldecimal b;
  fgldecimal dc;
  long l1;
  long l2;
  double dbl;
  int d;
  //char *a1;
  //char *a2;
  //A4GL_pop_var2 (&b, 5, 0x2010);
  A4GL_pop_sized_decimal(&b);
  A4GL_pop_var2 (&a, 5, 0x2000);

  if (A4GL_isnull (DTYPE_DECIMAL, (void *) &a) || A4GL_isnull (DTYPE_DECIMAL, (void *) &b))
    {
      if (isCompare (op))
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_DECIMAL, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }
  A4GL_init_dec (&dc, 32, 16);

  switch (op)
    {
    case OP_ADD:
      a4gl_decadd (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;
    case OP_SUB:
      a4gl_decsub (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;
    case OP_MULT:
      a4gl_decmul (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;


    case OP_DIV:
      a4gl_decdiv (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;

    case OP_MOD:
      a4gl_dectolong (&a, &l1);
      a4gl_dectolong (&b, &l2);
      A4GL_push_long (l1 % l2);
      return;

    case OP_POWER:
      a4gl_dectolong (&b, &l2);
      if (l2 == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (l2 == 1)
	{
	  a4gl_dectodbl (&a, &dbl);
	  A4GL_push_float (dbl);
	  return;
	}

      a4gl_deccopy (&dc, &a);
      for (d = 1; d < l2; d++)
	a4gl_decmul (&dc, &a, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;

    case OP_LESS_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) < 0);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) > 0);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) <= 0);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) >= 0);
      return;
    case OP_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) == 0);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) != 0);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

/******************************************************************************/

static void
A4GL_float_dec_ops (int op)
{
  fgldecimal a;
  fgldecimal b;
  fgldecimal dc;
  long l1;
  long l2;
  double dbl;
  int d;
  //char *a1;
  //char *a2;
  //A4GL_pop_var2 (&b, 5, 0x2010);
  A4GL_pop_sized_decimal(&b);
  A4GL_pop_var2 (&a, 5, 0x2005);

  if (A4GL_isnull (DTYPE_DECIMAL, (void *) &a) || A4GL_isnull (DTYPE_DECIMAL, (void *) &b))
    {
      if (isCompare (op))
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_DECIMAL, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }
  A4GL_init_dec (&dc, 32, 16);

  switch (op)
    {
    case OP_ADD:
      a4gl_decadd (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;
    case OP_SUB:
      a4gl_decsub (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;
    case OP_MULT:
      a4gl_decmul (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;


    case OP_DIV:
      a4gl_decdiv (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;

    case OP_MOD:
      a4gl_dectolong (&a, &l1);
      a4gl_dectolong (&b, &l2);
      A4GL_push_long (l1 % l2);
      return;

    case OP_POWER:
      a4gl_dectolong (&b, &l2);
      if (l2 == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (l2 == 1)
	{
	  a4gl_dectodbl (&a, &dbl);
	  A4GL_push_float (dbl);
	  return;
	}

      a4gl_deccopy (&dc, &a);
      for (d = 1; d < l2; d++)
	a4gl_decmul (&dc, &a, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;

    case OP_LESS_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) < 0);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) > 0);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) <= 0);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) >= 0);
      return;
    case OP_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) == 0);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) != 0);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

/******************************************************************************/

static void
A4GL_smfloat_dec_ops (int op)
{
  fgldecimal a;
  fgldecimal b;
  fgldecimal dc;
  long l1;
  long l2;
  double dbl;
  int d;
  //char *a1;
  //char *a2;
  //A4GL_pop_var2 (&b, 5, 0x2010);
  A4GL_pop_sized_decimal(&b);
  A4GL_pop_var2 (&a, 5, 0x2005);

  if (A4GL_isnull (DTYPE_DECIMAL, (void *) &a) || A4GL_isnull (DTYPE_DECIMAL, (void *) &b))
    {
      if (isCompare (op))
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_DECIMAL, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }
  A4GL_init_dec (&dc, 32, 16);

  switch (op)
    {
    case OP_ADD:
      a4gl_decadd (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;
    case OP_SUB:
      a4gl_decsub (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;
    case OP_MULT:
      a4gl_decmul (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;


    case OP_DIV:
      a4gl_decdiv (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;

    case OP_MOD:
      a4gl_dectolong (&a, &l1);
      a4gl_dectolong (&b, &l2);
      A4GL_push_long (l1 % l2);
      return;

    case OP_POWER:
      a4gl_dectolong (&b, &l2);
      if (l2 == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (l2 == 1)
	{
	  a4gl_dectodbl (&a, &dbl);
	  A4GL_push_float (dbl);
	  return;
	}

      a4gl_deccopy (&dc, &a);
      for (d = 1; d < l2; d++)
	a4gl_decmul (&dc, &a, &dc);
      A4GL_push_dec_dec (&dc, 0, 16);
      return;

    case OP_LESS_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) < 0);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) > 0);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) <= 0);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) >= 0);
      return;
    case OP_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) == 0);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) != 0);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}


/******************************************************************************/

static void
A4GL_sm_mon_ops (int op)
{
  fgldecimal a;
  fgldecimal b;
  fgldecimal dc;
  long l1;
  long l2;
  double dbl;
  int d;
  //char *a1;
  //char *a2;
  //A4GL_pop_var2 (&b, 5, 0x2010);
  A4GL_pop_sized_decimal(&b);
  A4GL_pop_var2 (&a, 5, 0x2005);

  if (A4GL_isnull (DTYPE_MONEY, (void *) &a) || A4GL_isnull (DTYPE_MONEY, (void *) &b))
    {
      if (isCompare (op))
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_MONEY, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }
  A4GL_init_dec (&dc, 32, 16);

  switch (op)
    {
    case OP_ADD:
      a4gl_decadd (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;
    case OP_SUB:
      a4gl_decsub (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;
    case OP_MULT:
      a4gl_decmul (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;


    case OP_DIV:
      a4gl_decdiv (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;

    case OP_MOD:
      a4gl_dectolong (&a, &l1);
      a4gl_dectolong (&b, &l2);
      A4GL_push_long (l1 % l2);
      return;

    case OP_POWER:
      a4gl_dectolong (&b, &l2);
      if (l2 == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (l2 == 1)
	{
	  a4gl_dectodbl (&a, &dbl);
	  A4GL_push_float (dbl);
	  return;
	}

      a4gl_deccopy (&dc, &a);
      for (d = 1; d < l2; d++)
	a4gl_decmul (&dc, &a, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;

    case OP_LESS_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) < 0);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) > 0);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) <= 0);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) >= 0);
      return;
    case OP_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) == 0);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) != 0);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

/******************************************************************************/

static void
A4GL_int_mon_ops (int op)
{
  fgldecimal a;
  fgldecimal b;
  fgldecimal dc;
  long l1;
  long l2;
  double dbl;
  int d;
  //char *a1;
  //char *a2;
  //A4GL_pop_var2 (&b, 5, 0x2010);
  A4GL_pop_sized_decimal(&b);
  A4GL_pop_var2 (&a, 5, 0x2000);

  if (A4GL_isnull (DTYPE_MONEY, (void *) &a) || A4GL_isnull (DTYPE_MONEY, (void *) &b))
    {
      if (isCompare (op))
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_MONEY, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }
  A4GL_init_dec (&dc, 32, 16);

  switch (op)
    {
    case OP_ADD:
      a4gl_decadd (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;
    case OP_SUB:
      a4gl_decsub (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;
    case OP_MULT:
      a4gl_decmul (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;


    case OP_DIV:
      a4gl_decdiv (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;

    case OP_MOD:
      a4gl_dectolong (&a, &l1);
      a4gl_dectolong (&b, &l2);
      A4GL_push_long (l1 % l2);
      return;

    case OP_POWER:
      a4gl_dectolong (&b, &l2);
      if (l2 == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (l2 == 1)
	{
	  a4gl_dectodbl (&a, &dbl);
	  A4GL_push_float (dbl);
	  return;
	}

      a4gl_deccopy (&dc, &a);
      for (d = 1; d < l2; d++)
	a4gl_decmul (&dc, &a, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;

    case OP_LESS_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) < 0);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) > 0);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) <= 0);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) >= 0);
      return;
    case OP_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) == 0);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) != 0);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

/******************************************************************************/

static void
A4GL_float_mon_ops (int op)
{
  fgldecimal a;
  fgldecimal b;
  fgldecimal dc;
  long l1;
  long l2;
  double dbl;
  int d;
  //char *a1;
  //char *a2;
  //A4GL_pop_var2 (&b, 5, 0x2010);
  A4GL_pop_sized_decimal(&b);
  A4GL_pop_var2 (&a, 5, 0x2005);

  if (A4GL_isnull (DTYPE_MONEY, (void *) &a) || A4GL_isnull (DTYPE_MONEY, (void *) &b))
    {
      if (isCompare (op))
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_MONEY, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }
  A4GL_init_dec (&dc, 32, 16);

  switch (op)
    {
    case OP_ADD:
      a4gl_decadd (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;
    case OP_SUB:
      a4gl_decsub (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;
    case OP_MULT:
      a4gl_decmul (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;


    case OP_DIV:
      a4gl_decdiv (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;

    case OP_MOD:
      a4gl_dectolong (&a, &l1);
      a4gl_dectolong (&b, &l2);
      A4GL_push_long (l1 % l2);
      return;

    case OP_POWER:
      a4gl_dectolong (&b, &l2);
      if (l2 == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (l2 == 1)
	{
	  a4gl_dectodbl (&a, &dbl);
	  A4GL_push_float (dbl);
	  return;
	}

      a4gl_deccopy (&dc, &a);
      for (d = 1; d < l2; d++)
	a4gl_decmul (&dc, &a, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;

    case OP_LESS_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) < 0);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) > 0);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) <= 0);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) >= 0);
      return;
    case OP_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) == 0);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) != 0);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

/******************************************************************************/

static void
A4GL_smfloat_mon_ops (int op)
{
  fgldecimal a;
  fgldecimal b;
  fgldecimal dc;
  long l1;
  long l2;
  double dbl;
  int d;
  //char *a1;
  //char *a2;
  //A4GL_pop_var2 (&b, 5, 0x2010);
  A4GL_pop_sized_decimal(&b);
  A4GL_pop_var2 (&a, 5, 0x2005);

  if (A4GL_isnull (DTYPE_MONEY, (void *) &a) || A4GL_isnull (DTYPE_MONEY, (void *) &b))
    {
      if (isCompare (op))
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_MONEY, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }
  A4GL_init_dec (&dc, 32, 16);

  switch (op)
    {
    case OP_ADD:
      a4gl_decadd (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;
    case OP_SUB:
      a4gl_decsub (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;
    case OP_MULT:
      a4gl_decmul (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;


    case OP_DIV:
      a4gl_decdiv (&a, &b, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;

    case OP_MOD:
      a4gl_dectolong (&a, &l1);
      a4gl_dectolong (&b, &l2);
      A4GL_push_long (l1 % l2);
      return;

    case OP_POWER:
      a4gl_dectolong (&b, &l2);
      if (l2 == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (l2 == 1)
	{
	  a4gl_dectodbl (&a, &dbl);
	  A4GL_push_float (dbl);
	  return;
	}

      a4gl_deccopy (&dc, &a);
      for (d = 1; d < l2; d++)
	a4gl_decmul (&dc, &a, &dc);
      A4GL_push_dec_dec (&dc, 1, 16);
      return;

    case OP_LESS_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) < 0);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (a4gl_deccmp (&a, &b) > 0);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) <= 0);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (a4gl_deccmp (&a, &b) >= 0);
      return;
    case OP_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) == 0);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int (a4gl_deccmp (&a, &b) != 0);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}


/******************************************************************************/

/**
 *
 *
 * @return
 */
void
A4GL_smfloat_smfloat_ops (int op)
{
  float a;
  float b;
  double dc;
  float d;

  b = A4GL_pop_float ();
  a = A4GL_pop_float ();
  A4GL_debug ("smfloat smfloat\n");
  A4GL_debug ("%f %f\n", a, b);
  if (A4GL_isnull (DTYPE_SMFLOAT, (void *) &a) || A4GL_isnull (DTYPE_SMFLOAT, (void *) &b))
    {
      A4GL_debug ("smflot_smfloat- one is null");
      if (isCompare (op))
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_SMFLOAT, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }

#ifdef DEBUG
  A4GL_debug ("int_int_ops : %d %d %d", a, b, op);
#endif

  switch (op)
    {
    case OP_ADD:
      A4GL_push_float (a + b);
      return;
    case OP_SUB:
      A4GL_push_float ((a - b));
      return;
    case OP_MULT:
      A4GL_push_double ((double) (a * b));	// SMFLOAT BASE
      return;


    case OP_DIV:
      if (b == 0)
	{
	  A4GL_push_null (DTYPE_SMFLOAT, 0);
	  return;
	}
      A4GL_push_double ((double) a / (double) b);	// SMFLOAT BASE
      return;

    case OP_MOD:
      A4GL_push_long ((int) a % (int) b);
      return;

    case OP_POWER:
      if (b == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (b == 1)
	{
	  A4GL_push_float (a);
	  return;
	}

      dc = a;
      for (d = 1; d < b; d++)
	dc *= (double) a;
      A4GL_push_double (dc);	// SMFLOAT BASE
      return;

    case OP_LESS_THAN:
      A4GL_push_int (a < b);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (a > b);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (a <= b);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (a >= b);
      return;
    case OP_EQUAL:
      A4GL_push_int (a == b);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int (a != b);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}


/******************************************************************************/

static void
A4GL_char_char_ops (int op)
{
  char *a;
  char *b;
  //double d1;
  //double d2;
  //double dc;
  int dt1;
  int dt2;
  int sz1;
  int sz2;
  //int l1;
  //int l2;
  int done1;
  int done2;

  int d1;
  int d2;
  int s1;
  int s2;
  char *ptr1;
  char *ptr2;

  A4GL_get_top_of_stack (1, &d1, &s1, (void **) &ptr1);
  A4GL_get_top_of_stack (2, &d2, &s2, (void **) &ptr2);

#ifdef DEBUG
  A4GL_debug (" About to pop '%s'(%s) '%s'(%s)", A4GL_null_as_null (ptr1),
	      A4GL_isnull (d1, ptr1) ? "null" : "not null", A4GL_null_as_null (ptr2), A4GL_isnull (d2, ptr2) ? "null" : "not null");
#endif

  b = A4GL_char_pop ();
  a = A4GL_char_pop ();

#ifdef DEBUG
  A4GL_debug ("a='%s' b='%s' op=%d\n", A4GL_null_as_null (a), A4GL_null_as_null (b), op);
#endif

  if (A4GL_isnull (DTYPE_CHAR, (void *) a) || A4GL_isnull (DTYPE_CHAR, (void *) b))
    {
      A4GL_debug ("One of them is null...");
      if (isCompare (op))
	{
	  free (a);
	  free (b);
	  A4GL_push_int (0);
	  return;
	}
      else
	{
	  A4GL_push_null (DTYPE_CHAR, 0);
	}
    }

  else
    {
#ifdef DEBUG
      A4GL_debug ("OK - neither is null");
#endif
    }

  A4GL_trim (b);
  A4GL_trim (a);


#ifdef DEBUG
  A4GL_debug ("a='%s' b='%s' op=%d and they're trimmed\n", A4GL_null_as_null (a), A4GL_null_as_null (b), op);
#endif

  switch (op)
    {
    case OP_ADD:
    case OP_SUB:
    case OP_MULT:
    case OP_DIV:
    case OP_MOD:
    case OP_POWER:

      // Not normal to add two strings...
      A4GL_whats_in_a_string (a, &dt1, &sz1);
      A4GL_whats_in_a_string (b, &dt2, &sz2);

      done1 = 0;
      done2 = 0;
      if (dt1 == DTYPE_CHAR)
	{
	  free (a);
	  free (b);
	  A4GL_exitwith ("Invalid operation on a character string (1)");
	  return;
	}
      if (dt2 == DTYPE_CHAR)
	{
	  free (a);
	  free (b);
	  A4GL_exitwith ("Invalid operation on a character string (2)");
	  return;
	}


      if (dt1 == DTYPE_DECIMAL)
	{
	  fgldecimal c;
	  A4GL_push_char (a);
	  A4GL_pop_var2 (&c, 5, 0x2010);
	  A4GL_push_variable (&c, 0x20100005);
	  done1 = 1;
	}
      if (dt1 == DTYPE_INT)
	{
	  long c;
	  A4GL_push_char (a);
	  A4GL_pop_var2 (&c, 2, 0);
	  A4GL_push_variable (&c, 0x2);
	  done1 = 1;
	}
      if (dt1 == DTYPE_DATE)
	{
	  long c;
	  A4GL_push_char (a);
	  A4GL_pop_var2 (&c, 7, 0);
	  A4GL_push_variable (&c, 0x7);
	  done1 = 1;
	}
      if (!done1)
	{
	  A4GL_assertion (1, "Unhandled character operation");
	}

      if (dt2 == DTYPE_DECIMAL)
	{
	  fgldecimal c;
	  A4GL_push_char (b);
	  A4GL_pop_var2 (&c, 5, 0x2010);
	  A4GL_push_variable (&c, 0x20100005);
	  done2 = 1;
	}
      if (dt2 == DTYPE_INT)
	{
	  long c;
	  A4GL_push_char (b);
	  A4GL_pop_var2 (&c, 2, 0);
	  A4GL_push_variable (&c, 0x2);
	  done2 = 1;
	}
      if (dt2 == DTYPE_DATE)
	{
	  long c;
	  A4GL_push_char (b);
	  A4GL_pop_var2 (&c, 7, 0);
	  A4GL_push_variable (&c, 0x7);
	  done2 = 1;
	}
      if (!done2)
	{
	  A4GL_assertion (1, "Unhandled character operation");
	}
      A4GL_pushop (op);
      return;




    case OP_LESS_THAN:
      A4GL_push_int (strcmp (a, b) < 0);
      free (a);
      free (b);
      return;

    case OP_GREATER_THAN:
      A4GL_push_int (strcmp (a, b) > 0);
      free (a);
      free (b);
      return;

    case OP_LESS_THAN_EQ:
      A4GL_push_int (strcmp (a, b) <= 0);
      free (a);
      free (b);
      return;

    case OP_GREATER_THAN_EQ:
      A4GL_push_int (strcmp (a, b) >= 0);
      free (a);
      free (b);
      return;

    case OP_EQUAL:
      //if (strcmp(a,"journal")==0 && strcmp(b,"all")==0) { A4GL_assertion(1,"Testing"); }
      A4GL_debug ("Comparing %s %s - gives %d\n", A4GL_null_as_null (a), A4GL_null_as_null (b), (strcmp (a, b) == 0));
      A4GL_push_int (strcmp (a, b) == 0);
      A4GL_debug ("Freeing my two popped strings %p and %p", a, b);
      free (a);
      free (b);
      return;

    case OP_NOT_EQUAL:
      A4GL_push_int (strcmp (a, b) != 0);
      free (a);
      free (b);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  free (a);
  free (b);
  return;
}


/**
 *
 *
 * @return
 */
void
A4GL_float_smfloat_ops (int op)
{
  double a;
  float b;
  double c;
  float d;

  b = A4GL_pop_float ();
  a = A4GL_pop_double ();
  A4GL_debug ("float smfloat\n");
  A4GL_debug ("%f %f\n", a, b);
  if (A4GL_isnull (DTYPE_SMFLOAT, (void *) &a) || A4GL_isnull (DTYPE_SMFLOAT, (void *) &b))
    {
      A4GL_debug ("float_smallflt - one is null");
      if (isCompare (op))
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_SMFLOAT, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }

#ifdef DEBUG
  A4GL_debug ("int_int_ops : %d %d %d", a, b, op);
#endif

  switch (op)
    {
    case OP_ADD:
      A4GL_push_double (a + b);	// FLOAT/SMFLOAT BASE
      return;
    case OP_SUB:
      A4GL_push_double ((a - b));	// FLOAT/SMFLOAT BASE
      return;
    case OP_MULT:
      A4GL_push_double ((double) (a * b));	// FLOAT/SMFLOAT BASE
      return;


    case OP_DIV:
      if (b == 0)
	{
	  A4GL_push_null (DTYPE_SMFLOAT, 0);
	  return;
	}
      A4GL_push_double ((double) a / (double) b);	// FLOAT/SMFLOAT BASE
      return;

    case OP_MOD:
      A4GL_push_long ((int) a % (int) b);
      return;

    case OP_POWER:
      if (b == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (b == 1)
	{
	  A4GL_push_double (a);	// FLOAT/SMFLOAT BASE
	  return;
	}

      c = a;

      for (d = 1; d < b; d++)
	c *= a;
      A4GL_push_double (c);	// FLOAT/SMFLOAT BASE
      return;

    case OP_LESS_THAN:
      A4GL_push_int ((float) a < (float) b);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int ((float) a > (float) b);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int ((float) a <= (float) b);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int ((float) a >= (float) b);
      return;
    case OP_EQUAL:
      A4GL_push_int ((float) a == (float) b);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int ((float) a != (float) b);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

/**
 *
 *
 * @return
 */
void
A4GL_smfloat_float_ops (int op)
{
  float a;
  double b;
  double c;
  float d;

  b = A4GL_pop_double ();
  a = A4GL_pop_float ();
  A4GL_debug ("smfloat float\n");
  A4GL_debug ("%f %f\n", a, b);
  if (A4GL_isnull (DTYPE_SMFLOAT, (void *) &a) || A4GL_isnull (DTYPE_SMFLOAT, (void *) &b))
    {
      A4GL_debug ("smfloat_float - one is null");
      if (isCompare (op))
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_SMFLOAT, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }

#ifdef DEBUG
  A4GL_debug ("int_int_ops : %d %d %d", a, b, op);
#endif

  switch (op)
    {
    case OP_ADD:
      A4GL_push_double (a + b);	// FLOAT/SMFLOAT BASE
      return;
    case OP_SUB:
      A4GL_push_double ((a - b));	// FLOAT/SMFLOAT BASE
      return;
    case OP_MULT:
      A4GL_push_double ((double) (a * b));	// FLOAT/SMFLOAT BASE
      return;


    case OP_DIV:
      if (b == 0)
	{
	  A4GL_push_null (DTYPE_SMFLOAT, 0);
	  return;
	}
      A4GL_push_double ((double) a / (double) b);	// FLOAT/SMFLOAT BASE
      return;

    case OP_MOD:
      A4GL_push_long ((int) a % (int) b);
      return;

    case OP_POWER:
      if (b == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (b == 1)
	{
	  A4GL_push_double (a);	// FLOAT/SMFLOAT BASE
	  return;
	}

      c = a;

      for (d = 1; d < b; d++)
	c *= (double) a;
      A4GL_push_double (c);	// FLOAT/SMFLOAT BASE
      return;

    case OP_LESS_THAN:
      A4GL_push_int ((float) a < (float) b);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int ((float) a > (float) b);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int ((float) a <= (float) b);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int ((float) a >= (float) b);
      return;
    case OP_EQUAL:
      A4GL_push_int ((float) a == (float) b);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int ((float) a != (float) b);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

/* ========================== EOF ========================== */


/**
 * Add all the default operations to the system
 *
 * @return
 */
void
A4GL_int_in_ops (int op)
{
  int a;
  struct ival in2;
  struct ival *pi2;
  int ival_data[10];
  int se2;
  int d2;
  int s2;
  int ok = 0;
  char buff_6[256];
  int isneg_ival;


#ifdef DEBUG
  A4GL_debug ("In dt_in_ops");
#endif

  A4GL_pop_param (&a, DTYPE_INT, -1);




  A4GL_get_top_of_stack (1, &d2, &s2, (void *) &pi2);

  if ((d2 & DTYPE_MASK) != DTYPE_INTERVAL)
    {
      PRINTF ("Confused... %d != %d\n", d2 & DTYPE_MASK, DTYPE_INTERVAL);
      A4GL_assertion (1, "Invalid datatype");
    }

  se2 = pi2->stime & 0xf;


  if (se2 == 1 || se2 == 2)
    {
      se2 = 2;
    }


  if (se2 != 2)
    {
      se2 = 6;
    }


  if (se2 == 2)
    {
      in2.stime = 0x82;
      in2.ltime = 2;

    }
  else
    {
      in2.stime = 0x86;
      in2.ltime = 11;
    }

  A4GL_debug ("in_in.....");
  A4GL_debug_print_stack ();

  A4GL_pop_param (&in2, DTYPE_INTERVAL, in2.stime * 16 + in2.ltime);

  if (in2.stime == 0 || in2.ltime == 0)
    {
      A4GL_assertion (1, "Interval looks empty");
    }

  A4GL_decode_interval (&in2, ival_data, &isneg_ival);	//@FIXME negative intervals


  switch (op)
    {
    case OP_ADD:
      if (se2 == 6)
	{
	  double f;
	  f = ival_data[5] + (double) (ival_data[6]) / 100000.0;
	  ok = 1;
	  SPRINTF1 (buff_6, "%lf", f);
	  A4GL_decstr_convert (buff_6, a4gl_convfmts.printf_decfmt, a4gl_convfmts.posix_decfmt, 0, 1, -1);
	  acli_interval (buff_6, 0x867);
	  return;
	}
      else
	{

	  double f;
	  f = ival_data[1] + a;
	  ok = 1;
	  SPRINTF1 (buff_6, "%d", (int) f);
	  acli_interval (buff_6, 0x822);
	  return;
	}

    case OP_SUB:
      if (se2 == 6)
	{
	  double f;
	  f = ival_data[5] + (double) (ival_data[6]) / 100000.0;
	  f = f - a;
	  ok = 1;
	  SPRINTF1 (buff_6, "%lf", f);
	  A4GL_decstr_convert (buff_6, a4gl_convfmts.printf_decfmt, a4gl_convfmts.posix_decfmt, 0, 1, -1);
	  acli_interval (buff_6, 0x867);
	  return;
	}
      else
	{
	  double f;
	  f = ival_data[1] - a;
	  ok = 1;
	  SPRINTF1 (buff_6, "%d", (int) f);
	  acli_interval (buff_6, 0x822);
	  return;
	}
    case OP_DIV:
      if (se2 == 6)
	{
	  double f;
	  f = ival_data[5] + (double) (ival_data[6]) / 100000.0;
	  f = f / a;
	  ok = 1;
	  SPRINTF1 (buff_6, "%lf", f);
	  A4GL_decstr_convert (buff_6, a4gl_convfmts.printf_decfmt, a4gl_convfmts.posix_decfmt, 0, 1, -1);
	  acli_interval (buff_6, 0x867);
	  return;
	}
      else
	{
	  double f;
	  f = ival_data[1] / a;
	  ok = 1;
	  SPRINTF1 (buff_6, "%d", (int) f);
	  acli_interval (buff_6, 0x822);
	  return;
	}

    case OP_MULT:
      if (se2 == 6)
	{
	  double f;
	  f = ival_data[5] + (double) (ival_data[6]) / 100000.0;
	  f = f * a;
	  ok = 1;
	  SPRINTF1 (buff_6, "%lf", f);
	  A4GL_decstr_convert (buff_6, a4gl_convfmts.printf_decfmt, a4gl_convfmts.posix_decfmt, 0, 1, -1);
	  acli_interval (buff_6, 0x867);
	  return;
	}
      else
	{
	  double f;
	  f = ival_data[1] * a;
	  ok = 1;
	  SPRINTF1 (buff_6, "%d", (int) f);
	  acli_interval (buff_6, 0x822);
	  return;
	}

    case OP_GREATER_THAN:
    case OP_GREATER_THAN_EQ:
    case OP_EQUAL:
    case OP_NOT_EQUAL:
    case OP_LESS_THAN:
    case OP_LESS_THAN_EQ:
      {
	double f = 0.0;
	double ad;
	if (se2 == 6)
	  {
	    f = ival_data[5] + (double) (ival_data[6]) / 100000.0;
	    //f=ival_data[6]*a;
	  }
	else
	  {
	    f = ival_data[1];
	  }

	if (isneg_ival)
	  f *= -1.0;

	ad = (double) a;

	if (op == OP_GREATER_THAN)
	  {
	    A4GL_push_int (f > ad);
	    return;
	  }
	if (op == OP_GREATER_THAN_EQ)
	  {
	    A4GL_push_int (f >= ad);
	    return;
	  }
	if (op == OP_LESS_THAN_EQ)
	  {
	    A4GL_push_int (f <= ad);
	    return;
	  }
	if (op == OP_LESS_THAN)
	  {
	    A4GL_push_int (f < ad);
	    return;
	  }
	if (op == OP_EQUAL)
	  {
	    A4GL_push_int (f == ad);
	    return;
	  }
	if (op == OP_NOT_EQUAL)
	  {
	    A4GL_push_int (f != ad);
	    return;
	  }
      }
      break;

    }

  A4GL_assertion (1, "Unimplemented int_in operation");
  fflush (stdout);
  A4GL_push_int (0);
}

/**
 * Add all the default operations to the system
 *
 * @return
 */
void
A4GL_in_int_ops (int op)
{
  int a;
  struct ival in;
  int ival_data[10];
  int isneg_ival;

#ifdef DEBUG
  A4GL_debug ("In dt_in_ops");
#endif
  A4GL_pop_param (&a, DTYPE_INT, -1);
  A4GL_pop_param (&in, DTYPE_INTERVAL, -1);

  A4GL_decode_interval (&in, &ival_data[0], &isneg_ival);

  A4GL_assertion (1, "Here");
  fflush (stdout);
  A4GL_push_int (0);
}




/**
 * Add all the default operations to the system
 *
 * @return
 */
void
A4GL_double_in_ops (int op)
{
  double a_double;
  struct ival in2;
  struct ival *pi2;
  int ival_data[10];
  int se2;
  int d2;
  int s2;
  int ok = 0;
  char buff_6[256];
  int isneg_ival;


#ifdef DEBUG
  A4GL_debug ("In dt_in_ops");
#endif

  A4GL_pop_param (&a_double, DTYPE_FLOAT, -1);




  A4GL_get_top_of_stack (1, &d2, &s2, (void *) &pi2);

  if ((d2 & DTYPE_MASK) != DTYPE_INTERVAL)
    {
      PRINTF ("Confused... %d != %d\n", d2 & DTYPE_MASK, DTYPE_INTERVAL);
      A4GL_assertion (1, "Invalid datatype");
    }

  se2 = pi2->stime & 0xf;


  if (se2 == 1 || se2 == 2)
    {
      se2 = 2;
    }


  if (se2 != 2)
    {
      se2 = 6;
    }


  if (se2 == 2)
    {
      in2.stime = 0x82;
      in2.ltime = 2;

    }
  else
    {
      in2.stime = 0x86;
      in2.ltime = 11;
    }

  A4GL_debug ("in_in.....");
  A4GL_debug_print_stack ();

  A4GL_pop_param (&in2, DTYPE_INTERVAL, in2.stime * 16 + in2.ltime);

  if (in2.stime == 0 || in2.ltime == 0)
    {
      A4GL_assertion (1, "Interval looks empty");
    }

  A4GL_decode_interval (&in2, ival_data, &isneg_ival);	//@FIXME negative intervals


  switch (op)
    {
    case OP_ADD:
      if (se2 == 6)
	{
	  double f;
	  f = ival_data[5] + (double) (ival_data[6]) / 100000.0;
	  ok = 1;
	  SPRINTF1 (buff_6, "%lf", f);
	  A4GL_decstr_convert (buff_6, a4gl_convfmts.printf_decfmt, a4gl_convfmts.posix_decfmt, 0, 1, -1);
	  acli_interval (buff_6, 0x867);
	  return;
	}
      else
	{

	  double f;
	  f = ival_data[1] + a_double;
	  ok = 1;
	  SPRINTF1 (buff_6, "%d", (int) f);
	  acli_interval (buff_6, 0x822);
	  return;
	}

    case OP_SUB:
      if (se2 == 6)
	{
	  double f;
	  f = ival_data[5] + (double) (ival_data[6]) / 100000.0;
	  f = f - a_double;
	  ok = 1;
	  SPRINTF1 (buff_6, "%lf", f);
	  A4GL_decstr_convert (buff_6, a4gl_convfmts.printf_decfmt, a4gl_convfmts.posix_decfmt, 0, 1, -1);
	  acli_interval (buff_6, 0x867);
	  return;
	}
      else
	{
	  double f;
	  f = ival_data[1] - a_double;
	  ok = 1;
	  SPRINTF1 (buff_6, "%d", (int) f);
	  acli_interval (buff_6, 0x822);
	  return;
	}
    case OP_DIV:
      if (se2 == 6)
	{
	  double f;
	  f = ival_data[5] + (double) (ival_data[6]) / 100000.0;
	  f = f / a_double;
	  ok = 1;
	  SPRINTF1 (buff_6, "%lf", f);
	  A4GL_decstr_convert (buff_6, a4gl_convfmts.printf_decfmt, a4gl_convfmts.posix_decfmt, 0, 1, -1);
	  acli_interval (buff_6, 0x867);
	  return;
	}
      else
	{
	  double f;
	  f = ival_data[1] / a_double;
	  ok = 1;
	  SPRINTF1 (buff_6, "%d", (int) f);
	  acli_interval (buff_6, 0x822);
	  return;
	}

    case OP_MULT:
      if (se2 == 6)
	{
	  double f;
	  f = ival_data[5] + (double) (ival_data[6]) / 100000.0;
	  f = f * a_double;
	  ok = 1;
	  SPRINTF1 (buff_6, "%lf", f);
	  A4GL_decstr_convert (buff_6, a4gl_convfmts.printf_decfmt, a4gl_convfmts.posix_decfmt, 0, 1, -1);
	  acli_interval (buff_6, 0x867);
	  return;
	}
      else
	{
	  double f;
	  f = ival_data[1] * a_double;
	  ok = 1;
	  SPRINTF1 (buff_6, "%d", (int) f);
	  acli_interval (buff_6, 0x822);
	  return;
	}

    case OP_GREATER_THAN:
    case OP_GREATER_THAN_EQ:
    case OP_EQUAL:
    case OP_NOT_EQUAL:
    case OP_LESS_THAN:
    case OP_LESS_THAN_EQ:
      {
	double f = 0.0;
	double ad;
	if (se2 == 6)
	  {
	    f = ival_data[5] + (double) (ival_data[6]) / 100000.0;
	    //f=ival_data[6]*a;
	  }
	else
	  {
	    f = ival_data[1];
	  }

	if (isneg_ival)
	  f *= -1.0;

	ad = (double) a_double;

	if (op == OP_GREATER_THAN)
	  {
	    A4GL_push_int (f > ad);
	    return;
	  }
	if (op == OP_GREATER_THAN_EQ)
	  {
	    A4GL_push_int (f >= ad);
	    return;
	  }
	if (op == OP_LESS_THAN_EQ)
	  {
	    A4GL_push_int (f <= ad);
	    return;
	  }
	if (op == OP_LESS_THAN)
	  {
	    A4GL_push_int (f < ad);
	    return;
	  }
	if (op == OP_EQUAL)
	  {
	    A4GL_push_int (f == ad);
	    return;
	  }
	if (op == OP_NOT_EQUAL)
	  {
	    A4GL_push_int (f != ad);
	    return;
	  }
      }
      break;

    }

  A4GL_assertion (1, "Unimplemented int_in operation");
  fflush (stdout);
  A4GL_push_int (0);
}

/**
 * Add all the default operations to the system
 *
 * @return
 */
void
A4GL_in_double_ops (int op)
{
  double a;
  struct ival in;
  int ival_data[10];
  int isneg_ival;

#ifdef DEBUG
  A4GL_debug ("In dt_in_ops");
#endif
  A4GL_pop_param (&a, DTYPE_FLOAT, -1);
  A4GL_pop_param (&in, DTYPE_INTERVAL, -1);

  A4GL_decode_interval (&in, &ival_data[0], &isneg_ival);

  A4GL_assertion (1, "Here");
  fflush (stdout);
  A4GL_push_int (0);
}


/**
 * Add all the default operations to the system
 *
 * @return
 */
void
A4GL_dt_in_ops (int op)
{
  struct A4GLSQL_dtime dt;
  struct ival in;
  int ival_data[10];
  int isneg;

#ifdef DEBUG
  A4GL_debug ("In dt_in_ops");
#endif
  A4GL_pop_param (&in, DTYPE_INTERVAL, -1);
  A4GL_pop_param (&dt, DTYPE_DTIME, -1);

  A4GL_assertion (1, "Here");
  A4GL_decode_interval (&in, &ival_data[0], &isneg);
  fflush (stdout);
  A4GL_push_int (0);
}

void
A4GL_dt_date_ops (int op)
{
  struct A4GLSQL_dtime dt2;
  void *ptr1;
  void *ptr2;
  int dtype1;
  int dtype2;
  int sz1;
  int sz2;

  A4GL_get_top_of_stack (1, &dtype1, &sz1, (void *) &ptr1);
  A4GL_get_top_of_stack (2, &dtype2, &sz2, (void *) &ptr2);
  dtype1 = dtype1 & DTYPE_MASK;
  dtype2 = dtype2 & DTYPE_MASK;

  A4GL_pop_param (&dt2, DTYPE_DTIME, 0x13);
  A4GL_push_variable (&dt2, 0x13000a);
  A4GL_dt_dt_ops (op);
}


void
A4GL_char_dt_ops (int op)
{
  int dtype1;
  int dtype2;
  int sz1;
  int sz2;
  struct A4GLSQL_dtime *pdt2;
  void *pdt1;
  struct A4GLSQL_dtime dt1;
  struct A4GLSQL_dtime dt2;
  char *p;

  A4GL_get_top_of_stack (1, &dtype2, &sz2, (void *) &pdt2);
  A4GL_get_top_of_stack (2, &dtype1, &sz1, (void *) &pdt1);

  dt1.stime = pdt2->stime;
  dt1.ltime = pdt2->ltime;
  A4GL_pop_param (&dt1, DTYPE_DTIME, dt1.stime * 16 + dt1.ltime);
  p = A4GL_char_pop ();

  A4GL_debug ("popped everything off...");
// Lets try converting our string to a datetime with the same units as our datetime...
  A4GL_push_char (p);
  dt2.stime = dt1.stime;
  dt2.ltime = dt1.ltime;
  A4GL_debug ("Pushed our character back on - converting to a datetime...");

  if (A4GL_pop_param (&dt2, DTYPE_DTIME, dt2.stime * 16 + dt2.ltime))
    {
      // Success !
      A4GL_debug ("Converted ok");
      A4GL_push_variable (&dt2, (ENCODE_SIZE (((dt2.stime * 16) + dt2.ltime))) + DTYPE_DTIME);
      A4GL_push_variable (&dt1, (ENCODE_SIZE (((dt1.stime * 16) + dt1.ltime))) + DTYPE_DTIME);
      A4GL_dt_dt_ops (op);
      return;
    }
  else
    {
      // OK - we cant do that...
      A4GL_push_null (DTYPE_CHAR, 0);
      return;
    }


// Should never get here!
  A4GL_push_null (DTYPE_CHAR, 0);
  return;

}


void
A4GL_dt_char_ops (int op)
{
  int dtype1;
  int dtype2;
  int sz1;
  int sz2;
  struct A4GLSQL_dtime *pdt2;
  void *pdt1;
  struct A4GLSQL_dtime dt1;
  struct A4GLSQL_dtime dt2;
  char *p;
  A4GL_debug ("in A4GL_dt_char_ops");
  A4GL_get_top_of_stack (1, &dtype1, &sz1, (void *) &pdt1);
  A4GL_get_top_of_stack (2, &dtype2, &sz2, (void *) &pdt2);

  if (pdt2)
    {
      dt1.stime = pdt2->stime;
      dt1.ltime = pdt2->ltime;
    }
  else
    {
      // we've not been passed the datetime..
      dt1.stime = sz2 >> 4;
      dt1.ltime = sz2 & 15;
    }
  p = A4GL_char_pop ();
  A4GL_pop_param (&dt1, DTYPE_DTIME, dt1.stime * 16 + dt1.ltime);

  A4GL_debug ("popped everything off...");
// Lets try converting our string to a datetime with the same units as our datetime...
  A4GL_push_char (p);

  dt2.stime = dt1.stime;
  dt2.ltime = dt1.ltime;
  A4GL_debug ("Pushed our character back on - converting to a datetime...");


  if (A4GL_pop_param (&dt2, DTYPE_DTIME, dt2.stime * 16 + dt2.ltime))
    {
      // Success !
      A4GL_trim (p);
      if (strlen (p))
	{			// They might just be checking its not blank...
	  A4GL_debug ("Converted ok");
	  A4GL_push_variable (&dt1, (ENCODE_SIZE (((dt1.stime * 16) + dt1.ltime))) + DTYPE_DTIME);
	  A4GL_push_variable (&dt2, (ENCODE_SIZE (((dt2.stime * 16) + dt2.ltime))) + DTYPE_DTIME);
	  A4GL_dt_dt_ops (op);
	}
      else
	{
	  A4GL_push_variable (&dt1, (ENCODE_SIZE (((dt1.stime * 16) + dt1.ltime))) + DTYPE_DTIME);
	  A4GL_push_char (" ");
	  A4GL_char_char_ops (op);
	}
      return;
    }
  else
    {
      // OK - we cant do that...
      A4GL_push_null (DTYPE_CHAR, 0);
      return;
    }


// Should never get here!
  A4GL_push_null (DTYPE_CHAR, 0);
  return;

}

void
A4GL_date_dt_ops (int op)
{
  struct A4GLSQL_dtime dt1;
  struct A4GLSQL_dtime *pdt1;
  void *ptr2;
  struct A4GLSQL_dtime dt2;	// Was formerly the date...
  int dtype1;
  int dtype2;
  int sz1;
  int sz2;
  A4GL_get_top_of_stack (1, &dtype1, &sz1, (void *) &pdt1);
  A4GL_get_top_of_stack (2, &dtype2, &sz2, (void *) &ptr2);

  dtype1 = dtype1 & DTYPE_MASK;
  dtype2 = dtype2 & DTYPE_MASK;
  A4GL_assertion ((dtype1 & DTYPE_MASK) != DTYPE_DTIME, "Internal error - expecting a datetime");
  dt1.stime = pdt1->stime;
  dt1.ltime = pdt1->ltime;
  A4GL_pop_param (&dt1, DTYPE_DTIME, dt1.stime * 16 + dt1.ltime);
  A4GL_pop_param (&dt2, DTYPE_DTIME, 0x13);
  A4GL_push_variable (&dt2, 0x13000a);
  A4GL_push_dtime (&dt1);
  A4GL_dt_dt_ops (op);
}



void
A4GL_in_date_ops (int op)
{
  struct ival *pi;
  int x_date;
  //struct A4GLSQL_dtime *pd;
  int d1;
  int d2;
  int s1;
  int s2;
  struct A4GLSQL_dtime dt;
  struct ival in;

  A4GL_get_top_of_stack (2, &d1, &s1, (void *) &x_date);
  A4GL_get_top_of_stack (1, &d2, &s2, (void *) &pi);

  memset (&in, 0, sizeof (in));
  in.stime = pi->stime;
  in.ltime = pi->ltime;

  dt.stime = 1;
  dt.ltime = 3;
  A4GL_pop_var2 (&in, DTYPE_INTERVAL, in.stime * 16 + in.ltime);
  if (A4GL_isnull (DTYPE_INTERVAL, (void *) &in))
    {
      A4GL_debug ("INTERVAL IS NULL\n");
      A4GL_drop_param ();
      A4GL_push_null (DTYPE_CHAR, 0);
      return;
    }

  A4GL_pop_param (&dt, DTYPE_DTIME, dt.stime * 16 + dt.ltime);
  if (A4GL_isnull (DTYPE_DTIME, (void *) &dt))
    {
      A4GL_debug ("DATE IS NULL\n");
      A4GL_push_null (DTYPE_CHAR, 0);
      return;
    }
  A4GL_push_variable (&dt, 0x13000a);
  A4GL_push_variable (&in, ((in.stime * 16 + in.ltime) < 16) + DTYPE_INTERVAL);
  A4GL_debug_print_stack ();

// Now do it as a datetime/interval...
  A4GL_in_dt_ops (op);

}

/**
 * Add all the default operations to the system
 *
 * @return
 */
void
A4GL_in_dt_ops (int op)
{
  struct A4GLSQL_dtime dt;
  struct ival in;
  int ival_data[10];
  int dtime_data[10];
  int d1;
  int d2;
  int s1;
  int mdy_m, mdy_d, mdy_y;
  int s2;
  int isneg;

  long dt_days;
  double dt_seconds;
  long in_months;
  //long in_days;
  double in_seconds;


  //void *ptr1;
  struct ival *pi;
  struct A4GLSQL_dtime *pd;
  int ok = 0;
  char buff_2[256];
  int start;
  char *ptr;

  A4GL_debug ("in_dt_ops op=%d", op);
  A4GL_get_top_of_stack (2, &d1, &s1, (void *) &pd);
  A4GL_get_top_of_stack (1, &d2, &s2, (void *) &pi);


  if ((d1 & DTYPE_MASK) != DTYPE_DTIME)
    {

      PRINTF ("Confused... %d != %d\n", d1 & DTYPE_MASK, DTYPE_DTIME);
      A4GL_assertion (1, "Invalid datatype");
    }

  if ((d2 & DTYPE_MASK) != DTYPE_INTERVAL)
    {
      PRINTF ("Confused... %d != %d\n", d1 & DTYPE_MASK, DTYPE_INTERVAL);
      A4GL_assertion (1, "Invalid datatype");
    }


  memset (&in, 0, sizeof (in));

  if (pi)
    {
      in.stime = pi->stime;
      in.ltime = pi->ltime;
    }

  dt.stime = -1;
  dt.ltime = -1;

  if (pd)
    {
      dt.stime = pd->stime;
      dt.ltime = pd->ltime;
    }

  A4GL_pop_var2 (&in, DTYPE_INTERVAL, in.stime * 16 + in.ltime);

  if (A4GL_isnull (DTYPE_INTERVAL, (void *) &in))
    {
      A4GL_debug ("INTERVAL IS NULL\n");
      A4GL_drop_param ();
      A4GL_push_null (DTYPE_CHAR, 0);
      return;
    }


  A4GL_setnull (10, &dt, dt.stime * 16 + dt.ltime);

  A4GL_pop_param (&dt, DTYPE_DTIME, dt.stime * 16 + dt.ltime);

  if (A4GL_isnull (DTYPE_DTIME, (void *) &dt))
    {
      A4GL_debug ("DATETIME IS NULL\n");
      A4GL_push_null (DTYPE_CHAR, 0);
      return;

    }


  A4GL_decode_interval (&in, &ival_data[0], &isneg);


  A4GL_debug ("\n\nInterval : Y=%d\n", ival_data[0]);
  A4GL_debug ("Interval : M=%d\n", ival_data[1]);
  A4GL_debug ("Interval : D=%d\n", ival_data[2]);
  A4GL_debug ("Interval : H=%d\n", ival_data[3]);
  A4GL_debug ("Interval : M=%d\n", ival_data[4]);
  A4GL_debug ("Interval : S=%d\n", ival_data[5]);
  A4GL_debug ("Interval : F=%d\n", ival_data[6]);



  A4GL_decode_datetime (&dt, &dtime_data[0]);



  A4GL_debug ("Datetime : Y=%d\n", dtime_data[0]);
  A4GL_debug ("Datetime : M=%d\n", dtime_data[1]);
  A4GL_debug ("Datetime : D=%d\n", dtime_data[2]);
  A4GL_debug ("Datetime : H=%d\n", dtime_data[3]);
  A4GL_debug ("Datetime : M=%d\n", dtime_data[4]);
  A4GL_debug ("Datetime : S=%d\n", dtime_data[5]);
  A4GL_debug ("Datetime : F=%d\n", dtime_data[6]);



  dt_days = A4GL_gen_dateno (dtime_data[2], dtime_data[1], dtime_data[0]);	// As a date....

  //dt_seconds= (double)dtime_data[2]*24.0*60.0*60.0; // Days
  dt_seconds = 0;
  dt_seconds += (double) dtime_data[3] * 60.0 * 60.0;	// Hours
  dt_seconds += (double) dtime_data[4] * 60.0;	// Minutes
  dt_seconds += (double) dtime_data[5];
  dt_seconds += (double) dtime_data[6] / 100000.0;	// Seconds

  in_months = ival_data[0] * 12 + ival_data[1];
  in_seconds = 0;


  A4GL_debug (":::1 %d %lf %d -  %s", dt_days, dt_seconds, in_months, (op == OP_ADD) ? "Add" : "Subtract");

  if (in_months)
    {				// We're dealing with month information...
      if (isneg)
	in_months *= -1;
      if (op == OP_ADD)
	{
	  dtime_data[1] += in_months;
	  ok = 1;
	}

      if (op == OP_SUB)
	{
	  dtime_data[1] -= in_months;
	  ok = 1;
	}

      while (dtime_data[1] < 1)
	{
	  dtime_data[1] += 12;
	  dtime_data[0]--;
	}
      while (dtime_data[1] > 12)
	{
	  dtime_data[1] -= 12;
	  dtime_data[0]++;
	}

      if (dtime_data[1] < 1 || dtime_data[1] > 12)
	{
	  A4GL_assertion (1, "Month out of range...");
	}

      if (A4GL_days_in_month (dtime_data[1], dtime_data[0]) < dtime_data[2])
	{
	  // We've done something like 30/01/2001 -> 30/02/2001 which isn't valid
	  A4GL_debug ("dim=%d data[2]=%d data[1]=%d data[0]=%d\n", A4GL_days_in_month (dtime_data[1], dtime_data[0]), dtime_data[2],
		      dtime_data[1], dtime_data[0]);
	  ok = 0;
	  A4GL_push_null (DTYPE_CHAR, 0);
	  return;
	}
    }

  if (in_months == 0)
    {
      in_seconds = (double) ival_data[2] * 24.0 * 60.0 * 60.0;	// Days
      in_seconds += (double) ival_data[3] * 60.0 * 60.0;	// Hours
      in_seconds += (double) ival_data[4] * 60.0;	// Minutes
      in_seconds += ival_data[5] + (double) ival_data[6] / 100000.0;	// Seconds

      if (isneg)
	in_seconds *= -1.0;
      A4GL_debug (":::2 %d %lf %d %lf %s", dt_days, dt_seconds, in_months, in_seconds, (op == OP_ADD) ? "Add" : "Subtract");

      if (op == OP_ADD)
	{
	  long d;
	  double dt;
	  dtime_data[2] = 0;
	  dtime_data[3] = 0;
	  dtime_data[4] = 0;
	  dtime_data[5] = 0;
	  dtime_data[6] = 0;
	  ok = 1;

	  dt_seconds += in_seconds;
	  dt = a4gl_local_trunc (dt_seconds);
	  d = (long) dt;
	  dtime_data[5] = d;
	  dt_seconds -= dt - 0.000005;
	  dt_seconds *= 100000;
	  d = dt_seconds;
	  dtime_data[6] = d;

	  while (dtime_data[6] > 99999)
	    {
	      dtime_data[5]++;
	      dtime_data[6] -= 100000;
	    }
	  while (dtime_data[5] >= 60)
	    {
	      dtime_data[4]++;
	      dtime_data[5] -= 60;
	    }
	  // Minutes
	  while (dtime_data[4] >= 60)
	    {
	      dtime_data[3]++;
	      dtime_data[4] -= 60;
	    }
	  // Hours
	  while (dtime_data[3] >= 24)
	    {
	      dtime_data[2]++;
	      dtime_data[3] -= 24;
	    }


	  // Days

	  dt_days += dtime_data[2];

	  A4GL_get_date (dt_days, &mdy_d, &mdy_m, &mdy_y);
	  dtime_data[2] = mdy_d;
	  dtime_data[1] = mdy_m;
	  dtime_data[0] = mdy_y;


	}


      if (op == OP_SUB)
	{
	  long d;
	  double dt;


	  dtime_data[2] = 0;
	  dtime_data[3] = 0;
	  dtime_data[4] = 0;
	  ok = 1;

	  dt_seconds -= in_seconds;
	  dt = a4gl_local_trunc (dt_seconds);
	  d = (long) dt;
	  dtime_data[5] = d;
	  dt_seconds -= dt - 0.000005;
	  dt_seconds *= 100000;
	  d = dt_seconds;
	  dtime_data[6] = d;


	  if (dtime_data[6] < 0)
	    {
	      dtime_data[5]--;
	      dtime_data[6] += 100000;
	    }

	  // Seconds
	  while (dtime_data[5] < 0)
	    {
	      dtime_data[4]--;
	      dtime_data[5] += 60;
	    }


	  // Minutes
	  while (dtime_data[4] < 0)
	    {
	      dtime_data[3]--;
	      dtime_data[4] += 60;
	    }


	  // Hours
	  while (dtime_data[3] < 0)
	    {
	      dtime_data[2]--;
	      dtime_data[3] += 24;
	    }

	  while (dtime_data[6] > 99999)
	    {
	      dtime_data[5]++;
	      dtime_data[6] -= 100000;
	    }
	  while (dtime_data[5] >= 60)
	    {
	      dtime_data[4]++;
	      dtime_data[5] -= 60;
	    }
	  // Minutes
	  while (dtime_data[4] >= 60)
	    {
	      dtime_data[3]++;
	      dtime_data[4] -= 60;
	    }
	  // Hours
	  while (dtime_data[3] >= 24)
	    {
	      dtime_data[2]++;
	      dtime_data[3] -= 24;
	    }


	  dt_days += dtime_data[2];
	  A4GL_get_date (dt_days, &mdy_d, &mdy_m, &mdy_y);
	  dtime_data[2] = mdy_d;
	  dtime_data[1] = mdy_m;
	  dtime_data[0] = mdy_y;




	}

    }




  if (ok)
    {
      A4GL_debug ("Datetime : Y=%d\n", dtime_data[0]);
      A4GL_debug ("Datetime : M=%d\n", dtime_data[1]);
      A4GL_debug ("Datetime : D=%d\n", dtime_data[2]);
      A4GL_debug ("Datetime : H=%d\n", dtime_data[3]);
      A4GL_debug ("Datetime : M=%d\n", dtime_data[4]);
      A4GL_debug ("Datetime : S=%d\n", dtime_data[5]);
      A4GL_debug ("Datetime : F=%d\n", dtime_data[6]);

      A4GL_debug ("I reckon thats ok...");
      SPRINTF7 (buff_2, "%04d-%02d-%02d %02d:%02d:%02d.%05d",
		dtime_data[0], dtime_data[1], dtime_data[2], dtime_data[3], dtime_data[4], dtime_data[5], dtime_data[6]);

      A4GL_debug ("Buff = %s", buff_2);
      start = 0;
      if (dtime_data[0] > 0 && !start)
	start = 1;
      if (dtime_data[1] > 0 && !start)
	start = 2;
      if (dtime_data[2] > 0 && !start)
	start = 3;
      if (dtime_data[3] > 0 && !start)
	start = 4;
      if (dtime_data[4] > 0 && !start)
	start = 4;
      if (dtime_data[5] > 0 && !start)
	start = 4;
      if (dtime_data[6] > 0 && !start)
	start = 4;


      //0123456789012345678901234
      //0000-MM-30 23:57:10.00000
      ptr = 0;
      switch (start)
	{
	case 1:
	  ptr = &buff_2[0];
	  break;
	case 2:
	  ptr = &buff_2[5];
	  break;
	case 3:
	  ptr = &buff_2[8];
	  break;
	case 4:
	  ptr = &buff_2[11];
	  break;
	case 5:
	  ptr = &buff_2[14];
	  break;
	case 6:
	  ptr = &buff_2[17];
	  break;
	case 7:
	  ptr = &buff_2[18];
	  break;
	}
      if (ptr == 0)
	{
	  A4GL_assertion (1, "Internal error in_dt_ops");
	  return;
	}

      dt.stime = start;


      if (A4GL_ctodt (ptr, &dt, dt.stime * 16 + dt.ltime))
	{
	  A4GL_push_dtime (&dt);
	}
      else
	{
	  A4GL_push_null (DTYPE_DTIME, dt.stime * 16 + dt.ltime);
	}
      return;
    }



  A4GL_push_int (0);		// Or maybe push a null...
}


#ifdef NOT_YET
static void
A4GL_in_string_ops (int op)
{
  //struct ival in;
  struct ival *pi;
  char *ps;
  int d1, d2;
  int s1, s2;

  // Basically - we need to identify whats in our string..
  A4GL_get_top_of_stack (2, &d1, &s1, (void *) &ps);
  A4GL_get_top_of_stack (1, &d2, &s2, (void *) &pi);

}
#endif

/**
 *
 *
 * @return
 */
void
A4GL_int_int_ops (int op)
{
  long a;
  long b;
  long c;
  //double dc;
  long d;

  b = A4GL_pop_long ();
  a = A4GL_pop_long ();

  if (A4GL_isnull (DTYPE_INT, (void *) &a) || A4GL_isnull (DTYPE_INT, (void *) &b))
    {
#ifdef DEBUG
      A4GL_debug ("int_int - one is null");
#endif
      if (isCompare (op))
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_INT, 0);
      return;
    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("OK - neither is null");
#endif
    }

#ifdef DEBUG
  A4GL_debug ("int_int_ops : %d %d %d", a, b, op);
#endif

  switch (op)
    {
    case OP_ADD:
      A4GL_push_long (a + b);
      return;
    case OP_SUB:
      A4GL_push_long (a - b);
      return;
    case OP_MULT:
      A4GL_push_long (a * b);
      return;


    case OP_DIV:
      if (b == 0)
	{
	  A4GL_push_null (DTYPE_INT, 0);
	  return;
	}
      if (a % b == 0)
	{
	  A4GL_push_long (a / b);
	  return;
	}
      else
	{
	  push_dec_op_from_int_int (a, b, '/');
	  return;
	}

    case OP_MOD:
      A4GL_push_long (a % b);
      return;

    case OP_POWER:
      {
	M_APM a1;
	M_APM b1;
	M_APM tmp;
	if (b == 0)
	  {
	    A4GL_push_long (1);
	    return;
	  }
	if (b == 1)
	  {
	    A4GL_push_long (a);
	    return;
	  }


	a1 = m_apm_init ();
	b1 = m_apm_init ();
	tmp = m_apm_init ();

	m_apm_set_long (b1, a);
	c = a;

	for (d = 1; d < b; d++)
	  {
	    m_apm_multiply (tmp, b1, a1);
	    m_apm_copy (b1, tmp);
	    c *= a;
	  }
	if ((c > 0 && c < 1000000000) || (c < 0 && c > -1000000000))
	  A4GL_push_long (c);
	else
	  A4GL_push_dec_from_apm (b1);
      }

      return;

    case OP_LESS_THAN:
      A4GL_push_int (a < b);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (a > b);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (a <= b);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (a >= b);
      return;
    case OP_EQUAL:
      A4GL_push_int (a == b);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int (a != b);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

void
A4GL_date_date_ops (int op)
{
  long a;
  long b;
  long c;
  long d;

  b = A4GL_pop_long ();
  a = A4GL_pop_long ();

  A4GL_debug ("MATH ROUTINE : date_date");
  if (A4GL_isnull (DTYPE_INT, (void *) &a) || A4GL_isnull (DTYPE_INT, (void *) &b))
    {
      A4GL_debug ("date_date - one is null");
      if (isCompare (op))
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_INT, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }

#ifdef DEBUG
  A4GL_debug ("int_int_ops : %d %d %d", a, b, op);
#endif

  switch (op)
    {
    case OP_ADD:
      a += b;
      if (a <= 2958464)
	A4GL_push_date (a);
      else
	A4GL_push_date (0);

      return;
    case OP_SUB:
      A4GL_push_long (a - b);
      return;
    case OP_MULT:
      A4GL_push_long (a * b);
      return;


    case OP_DIV:
      if (b == 0)
	{
	  A4GL_push_null (DTYPE_INT, 0);
	  return;
	}
      if (a % b == 0)
	{
	  A4GL_push_long (a / b);
	  return;
	}
      else
	{
	  push_dec_op_from_int_int (a, b, '/');
	  return;
	}

    case OP_MOD:
      A4GL_push_long (a % b);
      return;
    case OP_POWER:
      if (b == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (b == 1)
	{
	  A4GL_push_long (a);
	  return;
	}
      c = a;
      for (d = 1; d < b; d++)
	c *= a;
      A4GL_push_long (c);
      return;

    case OP_LESS_THAN:
      A4GL_push_int (a < b);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (a > b);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (a <= b);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (a >= b);
      return;
    case OP_EQUAL:
      A4GL_push_int (a == b);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int (a != b);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

/******************************************************************************/

static void
A4GL_date_char_ops (int op)
{
  long a;
  char *ptr;
  long c;
  long d;
  char buff[256];
  int was_ok;
  int b;

  ptr = A4GL_char_pop ();
  a = A4GL_pop_long ();
  strncpy (buff, ptr, 255);
  buff[255] = 0;

  if (A4GL_isnull (DTYPE_INT, (void *) &a) || A4GL_isnull (DTYPE_CHAR, (void *) &ptr))
    {
      free (ptr);
      A4GL_debug ("int_date - one is null");
      if (isCompare (op))
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_INT, 0);
      return;
    }

  free (ptr);


  // Comparisons would normally be to another date....
  if (op == OP_LESS_THAN || op == OP_GREATER_THAN || op == OP_LESS_THAN_EQ || op == OP_GREATER_THAN_EQ || op == OP_EQUAL
      || op == OP_NOT_EQUAL)
    {
      // Firstly - is our string a date ?
      was_ok = A4GL_conversion_ok (-1);
      A4GL_conversion_ok (1);
      A4GL_push_char (buff);
      c = A4GL_pop_date ();
      if (!A4GL_conversion_ok (-1) || A4GL_isnull (DTYPE_DATE, (void *) &c))
	{			// Its not a date..
	  // Try as an integer ?
	  A4GL_push_char (buff);
	  b = A4GL_pop_long ();
	}
      else
	{
	  b = c;
	}

      A4GL_conversion_ok (was_ok);
    }
  else
    {
      A4GL_push_char (buff);
      b = A4GL_pop_long ();

    }

  switch (op)
    {
    case OP_ADD:
      a += b;
      if (a <= 2958464)
	A4GL_push_date (a);
      else
	A4GL_push_date (0);

      return;
    case OP_SUB:
      A4GL_push_date (a - b);
      return;
    case OP_MULT:
      A4GL_push_date (a * b);
      return;


    case OP_DIV:
      if (b == 0)
	{
	  A4GL_push_null (DTYPE_INT, 0);
	  return;
	}
      if (a % b == 0)
	{
	  A4GL_push_long (a / b);
	  return;
	}
      else
	{
	  push_dec_op_from_int_int (a, b, '/');
	  return;
	}

    case OP_MOD:
      A4GL_push_long (a % b);
      return;
    case OP_POWER:
      if (b == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (b == 1)
	{
	  A4GL_push_long (a);
	  return;
	}
      c = a;
      for (d = 1; d < b; d++)
	c *= a;
      A4GL_push_long (c);
      return;

    case OP_LESS_THAN:
      A4GL_push_int (a < b);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (a > b);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (a <= b);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (a >= b);
      return;
    case OP_EQUAL:
      A4GL_push_int (a == b);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int (a != b);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}


/******************************************************************************/

void
A4GL_date_int_ops (int op)
{
  long a;
  long b;
  long c;
  long d;



  b = A4GL_pop_long ();
  a = A4GL_pop_long ();

  A4GL_debug ("MATH ROUTINE : date_int %d %d", a, b);

  if (A4GL_isnull (DTYPE_INT, (void *) &a) || A4GL_isnull (DTYPE_INT, (void *) &b))
    {
      A4GL_debug ("int_date - one is null");
      if (isCompare (op))
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_INT, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }

#ifdef DEBUG
  A4GL_debug ("int_int_ops : %d %d %d", a, b, op);
#endif

  switch (op)
    {
    case OP_ADD:
      a += b;
      if (a <= 2958464)
	A4GL_push_date (a);
      else
	A4GL_push_date (0);

      return;
    case OP_SUB:
      A4GL_push_date (a - b);
      return;
    case OP_MULT:
      A4GL_push_date (a * b);
      return;


    case OP_DIV:
      if (b == 0)
	{
	  A4GL_push_null (DTYPE_INT, 0);
	  return;
	}
      if (a % b == 0)
	{
	  A4GL_push_long (a / b);
	  return;
	}
      else
	{
	  push_dec_op_from_int_int (a, b, '/');
	  return;
	}

    case OP_MOD:
      A4GL_push_long (a % b);
      return;
    case OP_POWER:
      if (b == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (b == 1)
	{
	  A4GL_push_long (a);
	  return;
	}
      c = a;
      for (d = 1; d < b; d++)
	c *= a;
      A4GL_push_long (c);
      return;

    case OP_LESS_THAN:
      A4GL_push_int (a < b);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (a > b);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (a <= b);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (a >= b);
      return;
    case OP_EQUAL:
      A4GL_push_int (a == b);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int (a != b);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

/******************************************************************************/

void
A4GL_int_date_ops (int op)
{
  long a;
  long b;
  long c;
  long d;

  b = A4GL_pop_long ();
  a = A4GL_pop_long ();

  A4GL_debug ("MATH ROUTINE : int_date");

  if (A4GL_isnull (DTYPE_INT, (void *) &a) || A4GL_isnull (DTYPE_INT, (void *) &b))
    {
      A4GL_debug ("int_int - one is null");
      if (isCompare (op))
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_push_null (DTYPE_INT, 0);
      return;
    }
  else
    {
      A4GL_debug ("OK - neither is null");
    }

#ifdef DEBUG
  A4GL_debug ("int_int_ops : %d %d %d", a, b, op);
#endif

  switch (op)
    {
    case OP_ADD:
      A4GL_push_date (a + b);
      return;
    case OP_SUB:
      A4GL_push_date (a - b);
      return;
    case OP_MULT:
      A4GL_push_date (a * b);
      return;


    case OP_DIV:
      if (b == 0)
	{
	  A4GL_push_null (DTYPE_INT, 0);
	  return;
	}
      if (a % b == 0)
	{
	  A4GL_push_long (a / b);
	  return;
	}
      else
	{
	  A4GL_push_double ((double) a / (double) b);
	  return;
	}

    case OP_MOD:
      A4GL_push_long (a % b);
      return;
    case OP_POWER:
      if (b == 0)
	{
	  A4GL_push_long (1);
	  return;
	}
      if (b == 1)
	{
	  A4GL_push_long (a);
	  return;
	}
      c = a;
      for (d = 1; d < b; d++)
	c *= a;
      A4GL_push_long (c);
      return;

    case OP_LESS_THAN:
      A4GL_push_int (a < b);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (a > b);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (a <= b);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (a >= b);
      return;
    case OP_EQUAL:
      A4GL_push_int (a == b);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int (a != b);
      return;
    }

  A4GL_exitwith ("Unknown operation");
  A4GL_push_int (0);
  return;
}

/******************************************************************************/

/**
 * Add all the default operations to the system
 *
 * @return
 */
void
A4GL_in_in_ops (int op)
{
  struct ival in2;
  struct ival in1;
  int ival_data1[10];
  int ival_data2[10];
  int d1, d2;
  int s1, s2;
  int isneg_1;
  int isneg_2;
  //void *ptr1;
  struct ival *pi1;
  struct ival *pi2;
  struct ival in;
  //int ok = 0;
  //char buff[256];
  //int start;
  //char *ptr;
  int se1;
  int se2;
  double d_i1;
  double d_i2;
  int a;
  for (a = 0; a < 10; a++)
    {
      ival_data1[a] = 0;
      ival_data2[a] = 0;
    }

  A4GL_debug ("in_in_ops - op=%d", op);
// d2 op d1

  A4GL_get_top_of_stack (2, &d2, &s2, (void *) &pi2);
  A4GL_get_top_of_stack (1, &d1, &s1, (void *) &pi1);

//printf("Here d1=%d s1=%x d2=%d s2=%x\n",d1,s1,d2,s2);

  A4GL_debug_print_stack ();

  if ((d1 & DTYPE_MASK) != DTYPE_INTERVAL)
    {
      PRINTF ("Confused... %d != %d\n", d1 & DTYPE_MASK, DTYPE_INTERVAL);
      A4GL_assertion (1, "Invalid datatype");
    }

  if ((d2 & DTYPE_MASK) != DTYPE_INTERVAL)
    {
      PRINTF ("Confused... %d != %d\n", d2 & DTYPE_MASK, DTYPE_INTERVAL);
      A4GL_assertion (1, "Invalid datatype");
    }

  //A4GL_assertion(pi1==0,"First interval is 0 (2)");
  //A4GL_assertion(pi2==0,"Second interval is 0");
  //
  if (pi1)
    {
      if (pi1->stime == 0 && pi1->ltime == 0)
	pi1 = 0;
    }				// A null by any other name - would still be as null
  if (pi2)
    {
      if (pi2->stime == 0 && pi2->ltime == 0)
	pi2 = 0;
    }				// A null by any other name - would still be as null
  if (pi1 == 0 || pi2 == 0)
    {
      A4GL_drop_param ();
      A4GL_drop_param ();
      if (pi1 != 0)
	{
	  A4GL_push_null (DTYPE_INTERVAL, s1);
	  return;
	}
      if (pi2 != 0)
	{
	  A4GL_push_null (DTYPE_INTERVAL, s2);
	  return;
	}
      A4GL_push_null (DTYPE_INTERVAL, 0);
      return;

      //A4GL_pop_param (&in1, DTYPE_INTERVAL, in1.stime * 16 + in1.ltime);
      //A4GL_pop_param (&in2, DTYPE_INTERVAL, in1.stime * 16 + in2.ltime);

    }

  se1 = pi1->stime & 0xf;
  se2 = pi2->stime & 0xf;


  //se1 = 6;
  //se2 = 6;


  if (se1 == 1 || se1 == 2)
    {
      se1 = 2;
    }
  if (se2 == 1 || se2 == 2)
    {
      se2 = 2;
    }

  if (se1 != 2)
    {
      se1 = 6;
      se2 = 6;
    }


  if (se1 != se2)
    {
      A4GL_exitwith ("Can't use interval YEAR-MONTH and DAY-FRACTION together");
      return;
    }



  A4GL_debug ("se1=%d\n", se1);
  if (se1 == 2)
    {
      in1.stime = 0x82;		// MONTH(8)
      in1.ltime = 2;		// MONTH
      in2.stime = 0x82;
      in2.ltime = 2;
      in.stime = in1.stime;
      in.ltime = in1.ltime;

    }
  else
    {
      in1.stime = 0x86;		// SECOND(8)
      in1.ltime = 11;		// FRACTION(5)
      in2.stime = 0x86;
      in2.ltime = 11;
      in.stime = in1.stime;
      in.ltime = in1.ltime;
    }

  A4GL_debug ("in_in.....");
  A4GL_debug_print_stack ();
  A4GL_pop_param (&in1, DTYPE_INTERVAL, in1.stime * 16 + in1.ltime);
  A4GL_pop_param (&in2, DTYPE_INTERVAL, in1.stime * 16 + in2.ltime);
  if (in1.stime == 0 || in1.ltime == 0 || in2.stime == 0 || in2.ltime == 0)
    {
      A4GL_assertion (1, "Interval looks empty");
    }

  A4GL_decode_interval (&in1, ival_data1, &isneg_1);
  A4GL_decode_interval (&in2, ival_data2, &isneg_2);


  if (se1 == 2)
    {
      d_i1 = (double) ival_data1[1];
      d_i2 = (double) ival_data2[1];
    }
  else
    {
      double df1;
      double df2;
      d_i1 = (double) ival_data1[5];
      d_i2 = (double) ival_data2[5];

      df1 = (double) ival_data1[6];
      df2 = (double) ival_data2[6];
      df1 /= 100000.0;
      df2 /= 100000.0;
      d_i1 += df1;
      d_i2 += df2;
      //printf ("d_i1=%f d_i2=%f", d_i1, d_i2);
      A4GL_debug ("d_i1=%f d_i2=%f", d_i1, d_i2);
    }


  if (isneg_1)
    {
      d_i1 *= -1.0;
    }
  if (isneg_2)
    {
      d_i2 *= -1.0;
    }



  switch (op)
    {
    case OP_ADD:
      d_i1 = d_i2 + d_i1;
      if (se1 == 2)
	{
	  char buff_3[256];
	  SPRINTF1 (buff_3, "%f", d_i1);
	  A4GL_decstr_convert (buff_3, a4gl_convfmts.printf_decfmt, a4gl_convfmts.posix_decfmt, 0, 1, -1);
	  acli_interval (buff_3, 0x822);
	  A4GL_cast_top_of_stack_to_dtype (DTYPE_INTERVAL + ENCODE_SIZE (0x512));
	  return;
	}
      else
	{
	  char buff_4[256];
	  SPRINTF1 (buff_4, "%f", d_i1);
	  A4GL_decstr_convert (buff_4, a4gl_convfmts.printf_decfmt, a4gl_convfmts.posix_decfmt, 0, 1, -1);
	  A4GL_debug ("Converting : %s to interval second to second", buff_4);
	  acli_interval (buff_4, 0x867);	// was 866
	  A4GL_cast_top_of_stack_to_dtype (DTYPE_INTERVAL + ENCODE_SIZE (0x249));
	  return;
	}



    case OP_SUB:

      d_i1 = d_i2 - d_i1;

      if (se1 == 2)
	{
	  char buff_5[256];
	  int yrs;
	  yrs = (int) d_i1;
	  yrs = (yrs - (yrs % 12)) / 12;
	  d_i1 -= yrs * 12;
	  SPRINTF2 (buff_5, "%d-%d", yrs, (int) d_i1);
	  acli_interval (buff_5, 0x812);
	  A4GL_cast_top_of_stack_to_dtype (DTYPE_INTERVAL + ENCODE_SIZE (0x512));
	  return;
	}
      else
	{
	  char buff_6[256];
	  SPRINTF1 (buff_6, "%f", d_i1);
	  A4GL_decstr_convert (buff_6, a4gl_convfmts.printf_decfmt, a4gl_convfmts.posix_decfmt, 0, 1, -1);
	  A4GL_debug ("Converting : %s to interval second to second", buff_6);
	  acli_interval (buff_6, 0x867);	// Was 866
	  A4GL_cast_top_of_stack_to_dtype (DTYPE_INTERVAL + ENCODE_SIZE (0x249));
	  return;
	}



    case OP_MULT:		// Multiplying two Intervals ?
      A4GL_exitwith ("You can't multiply two intervals...");
      return;


    case OP_DIV:
      if (d_i1 == 0)
	{
	  A4GL_push_null (DTYPE_INT, 0);
	  return;
	}
      d_i1 = d_i2 / d_i1;
      A4GL_push_double (d_i1);	// This should be a number - not an interval
      return;

    case OP_MOD:
      A4GL_exitwith ("You can't mod two intervals...");
      return;

    case OP_POWER:
      A4GL_exitwith ("You can't raise the power of intervals...");
      return;

    case OP_LESS_THAN:
      A4GL_push_int (d_i2 < d_i1);
      return;
    case OP_GREATER_THAN:
      A4GL_push_int (d_i2 > d_i1);
      return;
    case OP_LESS_THAN_EQ:
      A4GL_push_int (d_i2 <= d_i1);
      return;
    case OP_GREATER_THAN_EQ:
      A4GL_push_int (d_i2 >= d_i1);
      return;
    case OP_EQUAL:
      A4GL_push_int (d_i2 == d_i1);
      return;
    case OP_NOT_EQUAL:
      A4GL_push_int (d_i2 != d_i1);
      return;
    }

  PRINTF ("In in_in_ops.... op=%x d_i1=%f d_i2=%f\n", op, d_i1, d_i2);

  A4GL_assertion (1, "in_in - operation not implemented yet...");
}
















static void
A4GL_in_char_ops (int op)
{
  struct ival in1;
  //struct ival in2;
  int ival_data1[10];
  int d1, d2;
  int s1;
  struct ival *pi1;
  //struct ival in;
  //int se1;
  //double d_i1;
  int s2;
  int a;
  char *ptr;
  int done1;
//extern int params_cnt;

  for (a = 0; a < 10; a++)
    {
      ival_data1[a] = 0;
    }

  A4GL_debug ("in_in_ops - op=%d", op);
// d2 op d1

  A4GL_get_top_of_stack (1, &d2, &s2, (void *) &ptr);
  A4GL_get_top_of_stack (2, &d1, &s1, (void *) &pi1);

  if ((d1 & DTYPE_MASK) != DTYPE_INTERVAL)
    {
      A4GL_assertion (1, "Confused... Expecting an interval");
    }
  if ((d2 & DTYPE_MASK) != DTYPE_CHAR && (d2 & DTYPE_MASK) != DTYPE_VCHAR)
    {
      A4GL_assertion (1, "Confused... Expecting a string");
    }


  if (A4GL_isnull (d1, (void *) pi1))
    {
      A4GL_drop_param ();
      A4GL_drop_param ();
      A4GL_push_null (DTYPE_INT, 0);
      return;
    }

  if (A4GL_isnull (DTYPE_CHAR, ptr))
    {
      A4GL_drop_param ();
      A4GL_drop_param ();
      A4GL_push_null (DTYPE_INT, 0);
      return;
    }




  A4GL_assertion (pi1 == 0, "First interval is 0 (1)");


  memcpy (&in1, pi1, sizeof (struct ival));

  ptr = A4GL_char_pop ();
  A4GL_drop_param ();		// We've already memcpy'd this across...

  A4GL_debug ("Got stuff off stack...");

  // Not normal to add two strings...
  A4GL_whats_in_a_string (ptr, &d2, &s2);



  A4GL_push_interval (&in1, s1);

  done1 = 0;
  if (d2 == DTYPE_CHAR)
    {
      free (ptr);
      A4GL_exitwith ("Invalid operation on a character string (1)");
      return;
    }
  if (d2 == DTYPE_DECIMAL)
    {
      fgldecimal c;
      A4GL_push_char (ptr);
      A4GL_pop_var2 (&c, 5, 0x2010);
      A4GL_push_variable (&c, 0x20100005);
      done1 = 1;
    }
  if (d2 == DTYPE_INT)
    {
      long c;
      A4GL_push_char (ptr);
      A4GL_pop_var2 (&c, 2, 0);
      A4GL_push_variable (&c, 0x2);
      done1 = 1;
    }
  if (d2 == DTYPE_DATE)
    {
      long c;
      A4GL_push_char (ptr);
      A4GL_pop_var2 (&c, 7, 0);
      A4GL_push_variable (&c, 0x7);
      done1 = 1;
    }
  if (d2 == DTYPE_INTERVAL)
    {
      acli_interval (ptr, s2);
      done1 = 1;
    }
  if (d2 == DTYPE_DTIME)
    {
      A4GL_assertion (1, "Failed to used a character string which looks like a datetime with an interval");
    }
  if (!done1)
    {
      A4GL_assertion (1, "Unhandled character operation");
    }

  A4GL_pushop (op);
  return;
}



/**
 * Add all the default operations to the system
 *
 * @return
 */
void
A4GL_dt_dt_ops (int op)
{
  struct A4GLSQL_dtime dt2;
  struct A4GLSQL_dtime dt1;
  int dtime_data1[10];
  int dtime_data2[10];
  int d1, d2;
  int s1, s2;
  //void *ptr1;
  struct A4GLSQL_dtime *pi;
  struct A4GLSQL_dtime *pd;
  struct ival in;
  //int ok = 0;
  char buff_7[256];
  int cnt;
  //int start;
  //char *ptr;
  //double d_d1;
  //double d_d2;

  memset (&in, 0, sizeof (in));
  if (op != (OP_SUB) && op != (OP_EQUAL) && op != (OP_NOT_EQUAL)
      && op != (OP_LESS_THAN) && op != (OP_GREATER_THAN) && op != (OP_LESS_THAN_EQ) && op != (OP_GREATER_THAN_EQ))
    {

      A4GL_drop_param ();
      A4GL_drop_param ();

      A4GL_debug ("Can only subtract, ==, != , <, <=, >,>= datetimes at the minute...");
      A4GL_push_int (0);
      return;
    }

// d2 - d1
  A4GL_get_top_of_stack (2, &d1, &s1, (void *) &pd);
  A4GL_get_top_of_stack (1, &d2, &s2, (void *) &pi);


  if ((d1 & DTYPE_MASK) != DTYPE_DTIME)
    {
      PRINTF ("Confused... %d != %d\n", d1 & DTYPE_MASK, DTYPE_DTIME);
      A4GL_assertion (1, "Invalid datatype");
    }


  if (A4GL_isnull (DTYPE_DTIME, (void *) pd))
    {
      // First is null...
      A4GL_drop_param ();
      A4GL_drop_param ();
      A4GL_push_null (DTYPE_DTIME, s1);
      return;
    }


  if (A4GL_isnull (DTYPE_DTIME, (void *) pi))
    {
      // Second is null...
      A4GL_drop_param ();
      A4GL_drop_param ();
      A4GL_push_null (DTYPE_INT, 0);
      return;
    }

  dt1.stime = pi->stime;
  dt1.ltime = pi->ltime;

  dt2.stime = pd->stime;
  dt2.ltime = pd->ltime;

  A4GL_pop_param (&dt1, DTYPE_DTIME, dt1.stime * 16 + dt1.ltime);
  A4GL_pop_param (&dt2, DTYPE_DTIME, dt2.stime * 16 + dt2.ltime);


  memset (dtime_data1, 0, sizeof (dtime_data1));
  memset (dtime_data2, 0, sizeof (dtime_data2));

  A4GL_decode_datetime (&dt1, &dtime_data1[0]);
  A4GL_decode_datetime (&dt2, &dtime_data2[0]);

  A4GL_debug ("Dtime1=%d %d %d %d %d %d %d",
	      dtime_data1[0], dtime_data1[1], dtime_data1[2], dtime_data1[3], dtime_data1[4], dtime_data1[5], dtime_data1[6]);

  A4GL_debug ("Dtime2=%d %d %d %d %d %d %d",
	      dtime_data2[0], dtime_data2[1], dtime_data2[2], dtime_data2[3], dtime_data2[4], dtime_data2[5], dtime_data2[6]);



  if (op == (OP_EQUAL) || op == (OP_NOT_EQUAL))
    {
      int eq = 1;
      if (dtime_data2[0] != dtime_data1[0])
	eq = 0;
      if (dtime_data2[1] != dtime_data1[1])
	eq = 0;
      if (dtime_data2[2] != dtime_data1[2])
	eq = 0;
      if (dtime_data2[3] != dtime_data1[3])
	eq = 0;
      if (dtime_data2[4] != dtime_data1[4])
	eq = 0;
      if (dtime_data2[5] != dtime_data1[5])
	eq = 0;
      if (dtime_data2[6] != dtime_data1[6])
	eq = 0;

      if (op == (OP_EQUAL))
	{
	  if (eq)
	    A4GL_push_int (1);
	  else
	    A4GL_push_int (0);
	}
      else
	{
	  if (eq)
	    A4GL_push_int (0);
	  else
	    A4GL_push_int (1);
	}
      return;
    }



  if (op == (OP_SUB) || op == (OP_LESS_THAN) || op == (OP_GREATER_THAN) || op == (OP_LESS_THAN_EQ) || op == (OP_GREATER_THAN_EQ))
    {
      int s1;
      int s2;
      int inverted;
      s1 = -1;
      s2 = -1;

      if (dtime_data1[0] && s1 == -1)
	s1 = 0;
      if (dtime_data1[1] && s1 == -1)
	s1 = 1;
      if (dtime_data1[2] && s1 == -1)
	s1 = 2;
      if (dtime_data1[3] && s1 == -1)
	s1 = 3;
      if (dtime_data1[4] && s1 == -1)
	s1 = 4;
      if (dtime_data1[5] && s1 == -1)
	s1 = 5;
      if (dtime_data1[6] && s1 == -1)
	s1 = 6;

      if (dtime_data2[0] && s2 == -1)
	s2 = 0;
      if (dtime_data2[1] && s2 == -1)
	s2 = 1;
      if (dtime_data2[2] && s2 == -1)
	s2 = 2;
      if (dtime_data2[3] && s2 == -1)
	s2 = 3;
      if (dtime_data2[4] && s2 == -1)
	s2 = 4;
      if (dtime_data2[5] && s2 == -1)
	s2 = 5;
      if (dtime_data2[6] && s2 == -1)
	s2 = 6;

/* We need to make sure we're comparing like for like... */
      if (s1 > 0 || s2 > 0)
	{
	  dtime_data1[0] = 0;
	  dtime_data2[0] = 0;
	}
      if (s1 > 1 || s2 > 1)
	{
	  dtime_data1[1] = 0;
	  dtime_data2[1] = 0;
	}
      if (s1 > 2 || s2 > 2)
	{
	  dtime_data1[2] = 0;
	  dtime_data2[2] = 0;
	}
      if (s1 > 3 || s2 > 3)
	{
	  dtime_data1[3] = 0;
	  dtime_data2[3] = 0;
	}
      if (s1 > 4 || s2 > 4)
	{
	  dtime_data1[4] = 0;
	  dtime_data2[4] = 0;
	}
      if (s1 > 5 || s2 > 5)
	{
	  dtime_data1[5] = 0;
	  dtime_data2[5] = 0;
	}
      if (s1 > 6 || s2 > 6)
	{
	  dtime_data1[6] = 0;
	  dtime_data2[6] = 0;
	}

      inverted = 0;
      for (cnt = 0; cnt < 6; cnt++)
	{
	  if (dtime_data2[cnt] > dtime_data1[cnt])
	    break;
	  if (dtime_data2[cnt] < dtime_data1[cnt])
	    {
	      inverted++;
	      break;
	    }
	  // Same - look lower down..
	}

      if (inverted)
	{
	  int a;
	  int b;
	  for (a = 0; a <= 6; a++)
	    {
	      b = dtime_data1[a];
	      dtime_data1[a] = dtime_data2[a];
	      dtime_data2[a] = b;
	    }
	}

      A4GL_debug ("Op LT : %d (-%d <%d >%d", op, OP_SUB, OP_LESS_THAN, OP_GREATER_THAN);

      A4GL_debug ("%d %d %d %d %d %d %d", dtime_data1[0], dtime_data1[1], dtime_data1[2], dtime_data1[3], dtime_data1[4],
		  dtime_data1[5], dtime_data1[6]);
      A4GL_debug ("%d %d %d %d %d %d %d", dtime_data2[0], dtime_data2[1], dtime_data2[2], dtime_data2[3], dtime_data2[4],
		  dtime_data2[5], dtime_data2[6]);

      dtime_data2[0] -= dtime_data1[0];	// Y
      dtime_data2[1] -= dtime_data1[1];	//
      dtime_data2[2] -= dtime_data1[2];
      dtime_data2[3] -= dtime_data1[3];
      dtime_data2[4] -= dtime_data1[4];
      dtime_data2[5] -= dtime_data1[5];
      dtime_data2[6] -= dtime_data1[6];

      A4GL_debug ("%d %d %d %d %d %d %d", dtime_data2[0], dtime_data2[1], dtime_data2[2], dtime_data2[3], dtime_data2[4],
		  dtime_data2[5], dtime_data2[6]);
// Borrow some seconds for fractions
      while (dtime_data2[6] < 0)
	{
	  dtime_data2[6] += 100000;
	  dtime_data2[5]--;
	}

      A4GL_debug ("%d %d %d %d %d %d %d", dtime_data2[0], dtime_data2[1], dtime_data2[2], dtime_data2[3], dtime_data2[4],
		  dtime_data2[5], dtime_data2[6]);
// Borrow some minutes for seconds
      while (dtime_data2[5] < 0)
	{
	  dtime_data2[5] += 60;
	  dtime_data2[4]--;
	}

      A4GL_debug ("%d %d %d %d %d %d %d", dtime_data2[0], dtime_data2[1], dtime_data2[2], dtime_data2[3], dtime_data2[4],
		  dtime_data2[5], dtime_data2[6]);
// Borrow some hours for minutes
      while (dtime_data2[4] < 0)
	{
	  dtime_data2[4] += 60;
	  dtime_data2[3]--;
	}

      A4GL_debug ("%d %d %d %d %d %d %d", dtime_data2[0], dtime_data2[1], dtime_data2[2], dtime_data2[3], dtime_data2[4],
		  dtime_data2[5], dtime_data2[6]);
// Borrow some days for some hours..
      while (dtime_data2[3] < 0)
	{
	  dtime_data2[3] += 24;
	  dtime_data2[2]--;
	}

      A4GL_debug ("%d %d %d %d %d %d %d", dtime_data2[0], dtime_data2[1], dtime_data2[2], dtime_data2[3], dtime_data2[4],
		  dtime_data2[5], dtime_data2[6]);
// Borrow some months for some days. @ FIXME @todo fix days in months
      while (dtime_data2[2] < 0)
	{
	  if (dtime_data2[0] < 0 || dtime_data2[1] < 0)
	    {
	      dtime_data2[2] += 31;
	      dtime_data2[1]--;
	    }
	  else
	    {
	      dtime_data2[2] += A4GL_days_in_month (dtime_data2[1], dtime_data2[0]);
	      dtime_data2[1]--;
	    }
	}


      A4GL_debug ("%d %d %d %d %d %d %d", dtime_data2[0], dtime_data2[1], dtime_data2[2], dtime_data2[3], dtime_data2[4],
		  dtime_data2[5], dtime_data2[6]);
// Borrow some years for some months.
      while (dtime_data2[1] < 0)
	{
	  dtime_data2[1] += 12;
	  dtime_data2[0]--;
	}
      A4GL_debug ("%d %d %d %d %d %d %d", dtime_data2[0], dtime_data2[1], dtime_data2[2], dtime_data2[3], dtime_data2[4],
		  dtime_data2[5], dtime_data2[6]);

      A4GL_debug ("Y %d M %d D %d H %d M %d S %d", dtime_data2[0],
		  dtime_data2[1], dtime_data2[2], dtime_data2[3], dtime_data2[4], dtime_data2[5], dtime_data2[6]);




      if (op == (OP_SUB))
	{
	  if (dtime_data2[0] || dtime_data2[1])
	    {
	      // YEAR TO MONTH interval
	      SPRINTF2 (buff_7, "%4d-%02d", dtime_data2[0], dtime_data2[1]);
	      A4GL_ctoint (buff_7, &in, 1298);
	      if (inverted)
		{
		  in.is_neg = 1;
		}
	      A4GL_push_interval (&in, 1298);
	    }
	  else
	    {
	      SPRINTF5 (buff_7, "%d %02d:%02d:%02d.%05d", dtime_data2[2],
			dtime_data2[3], dtime_data2[4], dtime_data2[5], dtime_data2[6]);
	      A4GL_debug ("Got buff as : %s - op=%d\n", buff_7, op);
	      A4GL_ctoint (buff_7, &in, 0x53b);
	      A4GL_debug ("Pushing Interval - %p - s=%x e=%x made from %s", &in, in.stime, in.ltime);
	      A4GL_debug ("Buff = %s %x %x", buff_7);
	      if (inverted)
		{
		  in.is_neg = 1;
		}
	      A4GL_push_interval (&in, 1298);
	    }
	}
      else
	{
	  int eq;
	  int lt;
	  int gt;
	  eq = 0;
	  lt = 0;
	  gt = 0;

	  if (dtime_data2[0] || dtime_data2[1])
	    {
	      int y;
	      y = dtime_data2[0] * 12 + dtime_data2[1];
	      if (y > 0)
		gt = 1;
	      if (y < 0)
		lt = 1;
	      if (y == 0)
		eq = 1;
	    }
	  else
	    {
	      long d;
	      d = 0;
	      d += dtime_data2[2];
	      d *= 32;
	      d += dtime_data2[3];
	      d *= 24;
	      d += dtime_data2[4];
	      d *= 60;
	      d += dtime_data2[5];
	      if (d > 0)
		gt = 1;
	      if (d == 0)
		eq = 1;
	      if (d < 0)
		lt = 1;
	    }

	  if (inverted)
	    {
	      if (gt)
		{
		  gt = 0;
		  lt = 1;
		}
	      else
		{
		  if (lt)
		    {
		      gt = 1;
		      lt = 0;
		    }
		}
	    }


	  A4GL_debug (" Boolean values ->    %d %d %d", lt, eq, gt);

	  if (op == (OP_LESS_THAN))
	    {
	      if (lt)
		A4GL_push_int (1);
	      else
		A4GL_push_int (0);
	      return;
	    }
	  if (op == (OP_GREATER_THAN))
	    {
	      if (gt)
		A4GL_push_int (1);
	      else
		A4GL_push_int (0);
	      return;
	    }

	  if (op == (OP_LESS_THAN_EQ))
	    {
	      if (lt || eq)
		A4GL_push_int (1);
	      else
		A4GL_push_int (0);
	      return;
	    }
	  if (op == (OP_GREATER_THAN_EQ))
	    {
	      if (gt || eq)
		A4GL_push_int (1);
	      else
		A4GL_push_int (0);
	      return;
	    }

	  A4GL_push_int (0);



	}


    }


}


/*
	display_...

	these accept 4 parameters

	ptr  		= pointer to original data
	size 		= size of data (for decimal etc)
	string_sz		= size of character string to return into
	field_details 	= pointer to a field (or '0' for a normal 'display')
	display_type	=
				DISPLAY_TYPE_DISPLAY
				DISPLAY_TYPE_DISPLAY_AT
				DISPLAY_TYPE_DISPLAY_TO

		This allows the routine to differenciate between different DISPLAY types...

*/


char *
A4GL_display_int (void *ptr, int size, int string_sz, struct struct_scr_field *field_details, int display_type)
{
  long a;
  long value_in_ptr = 0;
  static char buff_8[256];
  A4GL_debug ("A4GL_display_int..");

  if (!A4GL_isnull (DTYPE_INT, ptr))
    {
      if (sizeof (long) > 4)
	{
	  value_in_ptr = *(int *) ptr;
	}
      else
	{
	  value_in_ptr = *(long *) ptr;
	}
    }

  if (display_type == DISPLAY_TYPE_DISPLAY || display_type == DISPLAY_TYPE_PRINT)
    {
      if (A4GL_isnull (DTYPE_INT, ptr))
	{
	  strcpy (buff_8, "           ");
	}
      else
	{
	  a = value_in_ptr;
	  SPRINTF1 (buff_8, "%11ld", a);
	}
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_AT)
    {
      if (A4GL_isnull (DTYPE_INT, ptr))
	{
	  strcpy (buff_8, "");
	}
      else
	{
	  a = value_in_ptr;
	  SPRINTF1 (buff_8, "%ld", a);
	}
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_TO)
    {
      char using_buff[256];
      if (ptr)
	{
	  A4GL_debug ("DISPLAY_TYPE_DISPLAY_TO : %d", *(int *) ptr);
	}

      if (ptr == 0 || A4GL_isnull (DTYPE_INT, ptr))
	{
	  A4GL_debug ("Int value is null");
	  strcpy (buff_8, "");
	  return buff_8;
	}

      a = value_in_ptr;

      if (A4GL_isnull (DTYPE_INT, (void *) &a))
	{
	  A4GL_debug ("Int value is null");
	  strcpy (buff_8, "");
	  return buff_8;
	}

      if (A4GL_has_str_attribute (field_details, FA_S_FORMAT))
	{
	  strcpy (using_buff, (A4GL_get_str_attribute (field_details, FA_S_FORMAT)));
	}
      else
	{
	  memset (using_buff, '-', 255);
	  using_buff[string_sz] = 0;
	  using_buff[string_sz - 1] = '&';
	}

      A4GL_push_long (a);
      A4GL_push_char (using_buff);
      A4GL_pushop (OP_USING);
      A4GL_pop_char (buff_8, string_sz);
      A4GL_debug ("display_int Got '%s'", buff_8);
      return buff_8;
    }

  A4GL_debug ("Returning '%s'", buff_8);

  return buff_8;
}

char *
A4GL_display_smint (void *ptr, int size, int string_sz, struct struct_scr_field *field_details, int display_type)
{
  short a;
  static char buff_9[256];


  A4GL_debug ("A4GL_display_smint..");

  if (display_type == DISPLAY_TYPE_DISPLAY || display_type == DISPLAY_TYPE_PRINT)
    {
      if (A4GL_isnull (DTYPE_SMINT, ptr))
	{
	  strcpy (buff_9, "      ");
	}
      else
	{
	  a = *(short *) ptr;
	  SPRINTF1 (buff_9, "%6d", a);
	}
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_AT)
    {
      if (A4GL_isnull (DTYPE_SMINT, ptr))
	{
	  strcpy (buff_9, "");
	}
      else
	{
	  a = *(short *) ptr;
	  SPRINTF1 (buff_9, "%d", a);
	}
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_TO)
    {
      char using_buff[256];
      if (A4GL_isnull (DTYPE_SMINT, ptr))
	{
	  strcpy (buff_9, "");
	  return buff_9;
	}
      a = *(short *) ptr;
      A4GL_debug ("display_smint a=%d", a);
      if (A4GL_has_str_attribute (field_details, FA_S_FORMAT))
	{
	  strcpy (using_buff, (A4GL_get_str_attribute (field_details, FA_S_FORMAT)));
	}
      else
	{
	  memset (using_buff, '-', 255);
	  using_buff[string_sz] = 0;
	  using_buff[string_sz - 1] = '&';
	}
      A4GL_push_int (a);
      A4GL_push_char (using_buff);
      A4GL_pushop (OP_USING);
      A4GL_pop_char (buff_9, string_sz);
      A4GL_debug ("display_smint Got '%s'", buff_9);
      return buff_9;
    }

  return buff_9;

}

char *
A4GL_display_float (void *ptr, int size, int string_sz, struct struct_scr_field *field_details, int display_type)
{
  double a;
  static char buff_10[256];
  //int len=14;


  if (display_type == DISPLAY_TYPE_DISPLAY || display_type == DISPLAY_TYPE_PRINT)
    {
      if (A4GL_isnull (DTYPE_FLOAT, ptr))
	{
	  strcpy (buff_10, "");
	  return buff_10;
	}
      a = *(double *) ptr;
      SPRINTF1 (buff_10, "%14.2f", a);
      A4GL_decstr_convert (buff_10, a4gl_convfmts.printf_decfmt, a4gl_convfmts.ui_decfmt, 0, 0, 14);
      if (!strchr (buff_10, '*'))
	{
	  return buff_10;
	}

      SPRINTF1 (buff_10, "%14.1f", a);
      A4GL_decstr_convert (buff_10, a4gl_convfmts.printf_decfmt, a4gl_convfmts.ui_decfmt, 0, 0, 14);
      if (!strchr (buff_10, '*'))
	{
	  return buff_10;
	}

      SPRINTF1 (buff_10, "%14.0f", a);
      A4GL_decstr_convert (buff_10, a4gl_convfmts.printf_decfmt, a4gl_convfmts.ui_decfmt, 0, 0, 14);
      if (!strchr (buff_10, '*'))
	{
	  return buff_10;
	}

      if (a >= 0)
	{
	  SPRINTF1 (buff_10, "%14.8e", a);
	  //A4GL_decstr_convert(buff_10, a4gl_convfmts.printf_decfmt, a4gl_convfmts.ui_decfmt, 0, 0, 14);
	  if (!strchr (buff_10, '*'))
	    {
	      char *ptr;
	      char buff2[200];
	      ptr = strstr (buff_10, "e+");
	      if (ptr)
		{
		  SPRINTF1 (buff_10, "%14.9e", a);
		  ptr = strstr (buff_10, "e+");
		  *ptr = 0;
		  strcpy (buff2, buff_10);
		  strcat (buff2, "e");
		  strcat (buff2, ptr + 2);
		  strcpy (buff_10, buff2);
		}
	      return buff_10;
	    }
	}
      else
	{
	  SPRINTF1 (buff_10, "%14.7e", a);
	  //A4GL_decstr_convert(buff_10, a4gl_convfmts.printf_decfmt, a4gl_convfmts.ui_decfmt, 0, 0, 14);
	  if (!strchr (buff_10, '*'))
	    {
	      char *ptr;
	      char buff2[200];
	      ptr = strstr (buff_10, "e+");
	      if (ptr)
		{
		  SPRINTF1 (buff_10, "%14.8e", a);
		  ptr = strstr (buff_10, "e+");
		  *ptr = 0;
		  strcpy (buff2, buff_10);
		  strcat (buff2, "e");
		  strcat (buff2, ptr + 2);
		  strcpy (buff_10, buff2);
		}
	      return buff_10;
	    }
	}



    }

  if (display_type == DISPLAY_TYPE_DISPLAY_AT)
    {
      int cnt;
      if (A4GL_isnull (DTYPE_FLOAT, ptr))
	{
	  strcpy (buff_10, "");
	  return buff_10;
	}
      a = *(double *) ptr;
      SPRINTF1 (buff_10, "%f", a);
      A4GL_decstr_convert (buff_10, a4gl_convfmts.printf_decfmt, a4gl_convfmts.ui_decfmt, 0, 1, -1);
      for (cnt = strlen (buff_10) - 1; cnt > 0; cnt--)
	{
	  if (cnt <= 1)
	    break;
	  if (buff_10[cnt - 1] == a4gl_convfmts.ui_decfmt.decsep)
	    break;
	  if (buff_10[cnt] != '0')
	    break;
	  if (buff_10[cnt] == '0')
	    buff_10[cnt] = 0;

	}
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_TO)
    {
      char using_buff[256];
      if (A4GL_isnull (DTYPE_FLOAT, ptr))
	{
	  strcpy (buff_10, "");
	  return buff_10;
	}
      a = *(double *) ptr;
      if (A4GL_has_str_attribute (field_details, FA_S_FORMAT))
	{
	  strcpy (using_buff, (A4GL_get_str_attribute (field_details, FA_S_FORMAT)));
	}
      else
	{
	  memset (using_buff, '-', 255);
	  using_buff[string_sz] = 0;
	  using_buff[string_sz - 4] = '&';
	  using_buff[string_sz - 3] = '.';
	  using_buff[string_sz - 2] = '&';
	  using_buff[string_sz - 1] = '&';
	}
      A4GL_push_double (a);
      A4GL_push_char (using_buff);
      A4GL_pushop (OP_USING);
      A4GL_pop_char (buff_10, string_sz);
      A4GL_decstr_convert (buff_10, a4gl_convfmts.using_decfmt, a4gl_convfmts.ui_decfmt, 0, 0, string_sz);
      return buff_10;
    }
  return buff_10;

}

char *
A4GL_display_smfloat (void *ptr, int size, int string_sz, struct struct_scr_field *field_details, int display_type)
{
  float a;
  static char buff_11[256];

  if (display_type == DISPLAY_TYPE_DISPLAY || display_type == DISPLAY_TYPE_PRINT)
    {
      if (A4GL_isnull (DTYPE_SMFLOAT, ptr))
	{
	  strcpy (buff_11, "");
	  return buff_11;
	}
      a = *(float *) ptr;
      SPRINTF1 (buff_11, "%14.2f", a);
      A4GL_decstr_convert (buff_11, a4gl_convfmts.printf_decfmt, a4gl_convfmts.ui_decfmt, 0, 0, 14);
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_AT)
    {
      int cnt;
      if (A4GL_isnull (DTYPE_SMFLOAT, ptr))
	{
	  strcpy (buff_11, "");
	  return buff_11;
	}
      a = *(float *) ptr;
      SPRINTF1 (buff_11, "%f", a);
      A4GL_decstr_convert (buff_11, a4gl_convfmts.printf_decfmt, a4gl_convfmts.ui_decfmt, 0, 1, -1);
      for (cnt = strlen (buff_11) - 1; cnt > 0; cnt--)
	{
	  if (cnt <= 1)
	    break;
	  if (buff_11[cnt - 1] == a4gl_convfmts.ui_decfmt.decsep)
	    break;
	  if (buff_11[cnt] != '0')
	    break;
	  if (buff_11[cnt] == '0')
	    buff_11[cnt] = 0;

	}
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_TO)
    {
      char using_buff[256];
      if (A4GL_isnull (DTYPE_SMFLOAT, ptr))
	{
	  strcpy (buff_11, "");
	  return buff_11;
	}
      a = *(float *) ptr;
      if (A4GL_has_str_attribute (field_details, FA_S_FORMAT))
	{
	  strcpy (using_buff, (A4GL_get_str_attribute (field_details, FA_S_FORMAT)));
	}
      else
	{
	  memset (using_buff, '-', 255);
	  using_buff[string_sz] = 0;
	  using_buff[string_sz - 4] = '&';
	  using_buff[string_sz - 3] = '.';
	  using_buff[string_sz - 2] = '&';
	  using_buff[string_sz - 1] = '&';
	}
      A4GL_push_float (a);
      A4GL_push_char (using_buff);
      A4GL_pushop (OP_USING);
      A4GL_pop_char (buff_11, string_sz);
      A4GL_decstr_convert (buff_11, a4gl_convfmts.using_decfmt, a4gl_convfmts.ui_decfmt, 0, 0, string_sz);
    }

  return buff_11;

}

char *
A4GL_display_date (void *ptr, int size, int string_sz, struct struct_scr_field *field_details, int display_type)
{
  long a;
  static char buff_12[256];

  if (A4GL_isyes (acl_getenv ("IGNORE_DATEFMT")))
    {
      return 0;
    }


  A4GL_debug ("A4GL_display_date..");

  if (display_type == DISPLAY_TYPE_DISPLAY || display_type == DISPLAY_TYPE_PRINT)
    {
      if (A4GL_isnull (DTYPE_DATE, ptr))
	{
	  if (strchr (A4GL_get_dbdate (), '4'))
	    {
	      strcpy (buff_12, "          ");
	    }
	  else
	    {
	      strcpy (buff_12, "        ");
	    }
	}
      else
	{
	  a = *(long *) ptr;
	  A4GL_push_date (a);
	  if (string_sz > 0)
	    {
	      A4GL_pop_char (buff_12, string_sz);
	    }
	  else
	    {
	      char *ptr;
	      ptr = A4GL_char_pop ();
	      strcpy (buff_12, ptr);
	      free (ptr);
	    }
	}
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_AT)
    {
      if (A4GL_isnull (DTYPE_INT, ptr))
	{
	  strcpy (buff_12, "");
	}
      else
	{
	  a = *(long *) ptr;
	  A4GL_push_date (a);
	  if (string_sz > 0)
	    {
	      A4GL_pop_char (buff_12, string_sz);
	    }
	  else
	    {
	      char *ptr;
	      ptr = A4GL_char_pop ();
	      strcpy (buff_12, ptr);
	      free (ptr);
	    }
	}
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_TO)
    {
      char using_buff[256];
      if (ptr)
	{
	  A4GL_debug ("DISPLAY_TYPE_DISPLAY_TO : DATE(%d)", *(int *) ptr);
	}

      if (ptr == 0 || A4GL_isnull (DTYPE_INT, ptr))
	{
	  A4GL_debug ("Date value is null");
	  strcpy (buff_12, "");
	  return buff_12;
	}

      a = *(long *) ptr;

      if (A4GL_isnull (DTYPE_DATE, (void *) &a))
	{
	  A4GL_debug ("Date value is null");
	  strcpy (buff_12, "");
	  return buff_12;
	}

      if (A4GL_has_str_attribute (field_details, FA_S_FORMAT))
	{
	  strcpy (using_buff, (A4GL_get_str_attribute (field_details, FA_S_FORMAT)));
	  A4GL_push_date (a);
	  A4GL_push_char (using_buff);
	  A4GL_pushop (OP_USING);
	  A4GL_pop_char (buff_12, string_sz);
	}
      else
	{
	  char *ptr;
	  A4GL_push_date (a);
	  ptr = A4GL_char_pop ();
	  strcpy (buff_12, ptr);
	  free (ptr);
	  if (strlen (buff_12) > string_sz)
	    {
	      char dbdate[200];
	      char format[200];
	      if (strlen (buff_12) == strlen ("01/01/2001"))
		{		// we tried a 4 digit year - and it failed..
		  // try a 2 digit year instead...
		  strcpy (dbdate, A4GL_get_dbdate ());
		  if (dbdate[0] == 'D' || dbdate[0] == 'd')
		    {		// DMY...
		      strcpy (format, "dd/mm/yy");
		    }
		  else
		    {
		      strcpy (format, "mm/dd/yy");
		    }
		  A4GL_push_date (a);
		  A4GL_push_char (format);
		  A4GL_pushop (OP_USING);
		  A4GL_pop_char (buff_12, string_sz);
		}
	    }
	}

      A4GL_debug ("display_date Got '%s'", buff_12);
      /* pascal_v. Display stars when date does not fit in field as Informix */
      if (strlen (buff_12) > string_sz)
	{
	  A4GL_debug ("This does not fit in field (length = %d)", string_sz);
	  memset (buff_12, '*', string_sz);
	  buff_12[string_sz] = 0;
	}
      A4GL_debug ("Returning '%s'", buff_12);
      return buff_12;
    }

  A4GL_debug ("Returning '%s'", buff_12);

  return buff_12;
}

char *
A4GL_display_char (void *ptr, int size, int string_sz, struct struct_scr_field *field_details, int display_type)
{
  return 0;
}

char *
A4GL_display_vchar (void *ptr, int size, int string_sz, struct struct_scr_field *field_details, int display_type)
{
  return 0;
}


char *
A4GL_display_decimal (void *ptr, int size, int string_sz, struct struct_scr_field *field_details, int display_type)
{
  static char s_x0[256];
  static char buff_13[256];
  char *tmpptr;

  A4GL_debug ("Display_decimal size=%d", size);
  //if (string_sz==-1) { return 0; }

  if (display_type == DISPLAY_TYPE_DISPLAY || display_type == DISPLAY_TYPE_PRINT)
    {
      if (A4GL_isnull (DTYPE_DECIMAL, ptr))
	{
	  int szptr;
	  strcpy (buff_13, "");
	  szptr = size >> 8;
	  szptr += 2;

	  if (szptr > 0 && szptr < 255)
	    {
	      memset (buff_13, ' ', sizeof (buff_13));
	      buff_13[szptr] = 0;
	    }

	  return buff_13;
	}
      A4GL_push_dec (ptr, 0, size);


      if (string_sz == -1)
	{
	  char *ptr2 = 0;
	  int n, l;
	  //char buff[256];
	  //char buff2[256];
	  ptr2 = ptr;
	  n = NUM_DIG (ptr2);
	  l = NUM_DEC (ptr2);
	  n = n - l + 1;
	  string_sz = n + 1;
	}

//A4GL_debug("Calling make_using.. ptr=%p");
      A4GL_push_char (A4GL_make_using_tostring (ptr, size >> 8, size & 255));
      A4GL_pushop (OP_USING);
      ptr = A4GL_char_pop ();
      if (a4gl_convfmts.ui_decfmt.thsep != 0)
	{
	  char *tmpptr;
	  tmpptr = A4GL_decstr_convert (ptr, a4gl_convfmts.using_decfmt, a4gl_convfmts.ui_decfmt, 1, 0, strlen (ptr));	//try to preserve length
	  if (tmpptr[0] == '*')	//overflow, length cannot be preserved
	    {
	      free (tmpptr);
	      tmpptr = A4GL_decstr_convert (ptr, a4gl_convfmts.using_decfmt, a4gl_convfmts.ui_decfmt, 1, 0, -1);
	    }
	  strcpy (s_x0, tmpptr);
	  free (tmpptr);
	}
      else
	strcpy (s_x0, ptr);
      free (ptr);
      return s_x0;
    }


  if (display_type == DISPLAY_TYPE_DISPLAY_AT)
    {
      A4GL_push_dec (ptr, 0, size);
      if (string_sz == -1)
	{
	  char *ptr;
	  ptr = A4GL_char_pop ();
	  tmpptr = A4GL_decstr_convert (ptr, a4gl_convfmts.posix_decfmt, a4gl_convfmts.ui_decfmt, 1, 0, -1);
	  strcpy (s_x0, tmpptr);
	  free (tmpptr);
	  free (ptr);
	}
      else
	{
	  A4GL_pop_char (s_x0, string_sz);
	  tmpptr = A4GL_decstr_convert (s_x0, a4gl_convfmts.posix_decfmt, a4gl_convfmts.ui_decfmt, 1, 0, string_sz);
	  strcpy (s_x0, tmpptr);
	  free (tmpptr);
	}

      A4GL_trim (s_x0);
      A4GL_ltrim (s_x0);
      return s_x0;
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_TO)
    {
      char using_buff[256];
      if (A4GL_isnull (DTYPE_DECIMAL, ptr))
	{
	  strcpy (buff_13, "");
	  return buff_13;
	}

      if (A4GL_has_str_attribute (field_details, FA_S_FORMAT))
	{
	  strcpy (using_buff, (A4GL_get_str_attribute (field_details, FA_S_FORMAT)));
	}
      else
	{
	  fgldecimal *fgldec;
	  int ndig;
	  int ndec;
	  fgldec = (fgldecimal *) ptr;
	  ndig = NUM_DIG (fgldec->dec_data);
	  ndec = NUM_DEC (fgldec->dec_data);
	  strcpy (using_buff, make_using_sz (ptr, string_sz, ndig, ndec));
	}
      A4GL_push_dec (ptr, 0, size);
      A4GL_push_char (using_buff);
      A4GL_pushop (OP_USING);
      A4GL_pop_char (buff_13, string_sz);
      A4GL_decstr_convert (buff_13, a4gl_convfmts.using_decfmt, a4gl_convfmts.ui_decfmt, 0, 0, string_sz);
      return buff_13;
    }

  return 0;
}

char *
A4GL_display_money (void *ptr, int size, int string_sz, struct struct_scr_field *field_details, int display_type)
{
  static char s_x1[256];
  static char buff_14[256];
  char *ubuff;
  int a;
  int has_neg = 0;
  char *offbuff;
  fgldecimal *fgldec;
  fgldec = ptr;

  A4GL_debug ("Display_money");

  if (display_type == DISPLAY_TYPE_DISPLAY || display_type == DISPLAY_TYPE_PRINT)
    {
      if (A4GL_isnull (DTYPE_DECIMAL, ptr))
	{
	  int szptr;
	  strcpy (buff_14, "");
	  szptr = size >> 8;
	  szptr += 3;		//(size&255);
	  //if (size&255) szptr++;
	  //if (size&255) szptr++;
	  if (szptr > 0 && szptr < 255)
	    {
	      memset (buff_14, ' ', sizeof (buff_14));
	      buff_14[szptr] = 0;
	    }
	  return buff_14;
	}
      A4GL_push_dec (ptr, 1, size);


      if (string_sz == -1)
	{
	  char *ptr2;
	  int n, l;
	  ptr2 = ptr;
	  n = NUM_DIG (ptr2);
	  l = NUM_DEC (ptr2);
	  n = n - l + 1;
	  string_sz = n + 1;
	  A4GL_debug ("Forcing size : %x (dig=%d dec=%d)", string_sz, n,l);
	}

      A4GL_debug ("Calling make_using.. ");
      strcpy (buff_14, "-");

      ubuff=A4GL_make_using_tostring (ptr, (size >> 8), size & 255);

      strcat (buff_14, ubuff);

      if (fgldec->dec_data[0] & 128)
	{
	  has_neg = 1;
	}

      for (a = 0; a < strlen (buff_14); a++)
	{
	  if (buff_14[a] == '-')
	    {
	      buff_14[a] = '$';
	    }
	}

      if (has_neg)
	{
	  for (a = strlen (buff_14) - 1; a >= 0; a--)
	    {
	      if (buff_14[a] == '$')
		{
		  buff_14[a] = '-';
		}
	    }
	}

      A4GL_push_char (buff_14);
      A4GL_pushop (OP_USING);

      offbuff = A4GL_char_pop ();

      if (has_neg)
	{
	  for (a = 0; a < strlen (offbuff); a++)
	    {
	      if (offbuff[a] == ' ' && offbuff[a + 1] == '-')
		{
		  offbuff[a] = '$';
		  break;
		}
	    }

	}
      strcpy (s_x1, offbuff);
      free (offbuff);
      return s_x1;
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_AT)
    {
      A4GL_push_dec (ptr, 1, size);
      if (string_sz == -1)
	{
	  char *ptr;
	  ptr = A4GL_char_pop ();
	  strcpy (s_x1, ptr);
	  free (ptr);
	}
      else
	{
	  A4GL_pop_char (s_x1, string_sz);
	}

      A4GL_trim (s_x1);
      A4GL_ltrim (s_x1);
      return s_x1;
    }
  if (display_type == DISPLAY_TYPE_DISPLAY_TO)
    {
      char using_buff[256];
      if (A4GL_isnull (DTYPE_MONEY, ptr))
	{
	  strcpy (buff_14, "");
	  return buff_14;
	}
      if (A4GL_has_str_attribute (field_details, FA_S_FORMAT))
	{
	  strcpy (using_buff, (A4GL_get_str_attribute (field_details, FA_S_FORMAT)));
	}
      else
	{
	  char *ptr2;
	  ptr2 = ptr;
	  //memset(using_buff,'-',255);
	  //using_buff[string_sz]=0;
	  //using_buff[string_sz-4]='&';
	  //using_buff[string_sz-3]='.';
	  //using_buff[string_sz-2]='&';
	  //using_buff[string_sz-1]='&';
	  strcpy (using_buff, make_using_sz (ptr2, string_sz, NUM_DIG (ptr2) * 2, NUM_DEC (ptr2)));
	}
      A4GL_push_dec (ptr, 0, size);
      A4GL_push_char (using_buff);
      A4GL_pushop (OP_USING);
      A4GL_pop_char (buff_14, string_sz);
      return buff_14;
    }

  return 0;

}

char *
A4GL_display_dtime (void *ptr, int size, int string_sz, struct struct_scr_field *field_details, int display_type)
{
static char p[100];
struct_dtime dm;
struct_dtime *dm2;
dm2=ptr;
  if (display_type==DISPLAY_TYPE_DISPLAY_TO)  {
	if (dm2->stime==1 && dm2->ltime>=6) { // Year to second..
		switch (string_sz) {
			case 10: // Convert to Year to day
				   	A4GL_push_int(0x13); 
					aclfgli_extend();
					ptr=A4GL_char_pop();
					strcpy(p,ptr); free(ptr);
					A4GL_push_char("<SOMETHING TO DROP AS WE'VE ALREADY POPPED IT>");
					return p;

			case 13: // Convert to Year to hour
				   A4GL_push_int(0x14); aclfgli_extend();
					ptr=A4GL_char_pop();
					strcpy(p,ptr); free(ptr);
					A4GL_push_char("<SOMETHING TO DROP AS WE'VE ALREADY POPPED IT>");
					return p;
			case 16: // Convert to Year to minute
				   A4GL_push_int(0x15); aclfgli_extend();
					ptr=A4GL_char_pop();
					strcpy(p,ptr); free(ptr);
					A4GL_push_char("<SOMETHING TO DROP AS WE'VE ALREADY POPPED IT>");
				return p;
		}
        }
  }
  return 0;
}

char *
A4GL_display_interval (void *ptr, int size, int string_sz, struct struct_scr_field *field_details, int display_type)
{
  return 0;
}

char *
A4GL_display_byte (void *ptr, int size, int string_sz, struct struct_scr_field *field_details, int display_type)
{
  A4GL_debug ("display byte");
  return 0;
}

char *
A4GL_display_text (void *ptr, int size, int string_sz, struct struct_scr_field *field_details, int display_type)
{
  fglbyte *p;
  p = ptr;

  if (A4GL_isnull (DTYPE_TEXT, ptr))
    {
      return "";
    }

  if (display_type == DISPLAY_TYPE_DISPLAY_AT)
    {
      if (p->where == 'F')
	{
	  long l;
	  FILE *f;
	  static char *b = 0;
	  f = fopen (p->filename, "r");
	  if (f == 0)
	    {
	      A4GL_exitwith ("Unable to load blob file");
	      return "";
	    }
	  fseek (f, 0, SEEK_END);
	  l = ftell (f);
	  b = realloc (b, l + 1);
	  memset (b, 0, l + 1);
	  rewind (f);
	  fread (b, 1, l, f);
	  return b;
	}
      else
	{
	  static char *lptr = 0;
	  if (lptr)
	    free (lptr);
	  lptr = malloc (p->memsize + 1);
	  if (ptr)
	    {
	      memcpy (lptr, p->ptr, p->memsize);
	      lptr[p->memsize] = 0;
	      return lptr;
	    }
	  else
	    {
	      A4GL_exitwith ("Unread blob");
	      return 0;
	    }
	}
    }

  if (display_type == DISPLAY_TYPE_DISPLAY || display_type == DISPLAY_TYPE_PRINT)
    {
      if (p->where == 'F')
	{
	  long l;
	  FILE *f;
	  static char *b = 0;
	  f = fopen (p->filename, "r");
	  if (f == 0)
	    {
	      A4GL_exitwith ("Unable to load blob file");
	      return "";
	    }
	  fseek (f, 0, SEEK_END);
	  l = ftell (f);
	  b = realloc (b, l + 1);
	  memset (b, 0, l + 1);
	  rewind (f);
	  fread (b, 1, l, f);
	  return b;
	}
      else
	{
	  static char *lptr = 0;
	  if (lptr)
	    free (lptr);
	  lptr = malloc (p->memsize + 1);
	  if (ptr)
	    {
	      char *xptr;
	      /* Make sure we're not overwriting ourselves */
	      xptr = A4GL_memdup (p->ptr, p->memsize);
	      memcpy (lptr, xptr, p->memsize);
	      lptr[p->memsize] = 0;
	      free (xptr);
	      return lptr;
	    }
	  else
	    {
	      A4GL_exitwith ("Unread blob");
	      return 0;
	    }

	}
    }

  return 0;
}

/**
 *
 *
 * @return
 */
void
A4GL_add_default_operations (void)
{


/* Integer functions
this covers all possibilities of
DTYPE_INT
DTYPE_SMINT
DTYPE_DATE
DTYPE_SERIAL
*/
//void *ptr;

  A4GL_add_op_function (DTYPE_INT, DTYPE_INT, OP_MATH, A4GL_int_int_ops);
  A4GL_add_op_function (DTYPE_SMFLOAT, DTYPE_SMFLOAT, OP_MATH, A4GL_smfloat_smfloat_ops);
  A4GL_add_op_function (DTYPE_CHAR, DTYPE_CHAR, OP_MATH, A4GL_char_char_ops);

  A4GL_add_op_function (DTYPE_INTERVAL, DTYPE_CHAR, OP_MATH, A4GL_in_char_ops);

  A4GL_add_op_function (DTYPE_SMFLOAT, DTYPE_FLOAT, OP_MATH, A4GL_smfloat_float_ops);
  A4GL_add_op_function (DTYPE_FLOAT, DTYPE_SMFLOAT, OP_MATH, A4GL_float_smfloat_ops);
  A4GL_add_op_function (DTYPE_SMINT, DTYPE_SMINT, OP_MATH, A4GL_int_int_ops);
  A4GL_add_op_function (DTYPE_INT, DTYPE_SMINT, OP_MATH, A4GL_int_int_ops);
  A4GL_add_op_function (DTYPE_SMINT, DTYPE_INT, OP_MATH, A4GL_int_int_ops);

  A4GL_add_op_function (DTYPE_DATE, DTYPE_DATE, OP_MATH, A4GL_date_date_ops);

  A4GL_add_op_function (DTYPE_INT, DTYPE_DATE, OP_MATH, A4GL_int_date_ops);
  A4GL_add_op_function (DTYPE_SMINT, DTYPE_DATE, OP_MATH, A4GL_int_date_ops);
  A4GL_add_op_function (DTYPE_DATE, DTYPE_SMINT, OP_MATH, A4GL_date_int_ops);
  A4GL_add_op_function (DTYPE_DATE, DTYPE_INT, OP_MATH, A4GL_date_int_ops);

  //A4GL_add_op_function (DTYPE_DATE, DTYPE_FLOAT, OP_MATH, A4GL_date_dbl_ops);
  //A4GL_add_op_function (DTYPE_FLOAT, DTYPE_DATE, OP_MATH, A4GL_dbl_date_ops);


  A4GL_add_op_function (DTYPE_SERIAL, DTYPE_SERIAL, OP_MATH, A4GL_int_int_ops);
  A4GL_add_op_function (DTYPE_SERIAL, DTYPE_INT, OP_MATH, A4GL_int_int_ops);
  A4GL_add_op_function (DTYPE_SERIAL, DTYPE_SMINT, OP_MATH, A4GL_int_int_ops);
  A4GL_add_op_function (DTYPE_SERIAL, DTYPE_DATE, OP_MATH, A4GL_int_date_ops);

  A4GL_add_op_function (DTYPE_INT, DTYPE_SERIAL, OP_MATH, A4GL_int_int_ops);
  A4GL_add_op_function (DTYPE_SMINT, DTYPE_SERIAL, OP_MATH, A4GL_int_int_ops);
  A4GL_add_op_function (DTYPE_DATE, DTYPE_SERIAL, OP_MATH, A4GL_date_int_ops);


  A4GL_add_op_function (DTYPE_DATE, DTYPE_CHAR, OP_MATH, A4GL_date_char_ops);

  A4GL_add_op_function (DTYPE_INTERVAL, DTYPE_INTERVAL, OP_MATH, A4GL_in_in_ops);
  A4GL_add_op_function (DTYPE_INTERVAL, DTYPE_DTIME, OP_MATH, A4GL_dt_in_ops);


  A4GL_add_op_function (DTYPE_INTERVAL, DTYPE_INT, OP_MATH, A4GL_int_in_ops);
  A4GL_add_op_function (DTYPE_INT, DTYPE_INTERVAL, OP_MATH, A4GL_in_int_ops);

  A4GL_add_op_function (DTYPE_INTERVAL, DTYPE_FLOAT, OP_MATH, A4GL_double_in_ops);
  A4GL_add_op_function (DTYPE_FLOAT, DTYPE_INTERVAL, OP_MATH, A4GL_in_double_ops);

  A4GL_add_op_function (DTYPE_DTIME, DTYPE_INTERVAL, OP_MATH, A4GL_in_dt_ops);
  A4GL_add_op_function (DTYPE_DATE, DTYPE_INTERVAL, OP_MATH, A4GL_in_date_ops);

  A4GL_add_op_function (DTYPE_DTIME, DTYPE_DTIME, OP_MATH, A4GL_dt_dt_ops);


  A4GL_add_op_function (DTYPE_DATE, DTYPE_DTIME, OP_MATH, A4GL_date_dt_ops);
  A4GL_add_op_function (DTYPE_DTIME, DTYPE_DATE, OP_MATH, A4GL_dt_date_ops);


  A4GL_add_op_function (DTYPE_CHAR, DTYPE_DTIME, OP_MATH, A4GL_char_dt_ops);
  A4GL_add_op_function (DTYPE_DTIME, DTYPE_CHAR, OP_MATH, A4GL_dt_char_ops);


  A4GL_add_op_function (DTYPE_DECIMAL, DTYPE_DECIMAL, OP_MATH, A4GL_dec_dec_ops);
  A4GL_add_op_function (DTYPE_DECIMAL, DTYPE_SMINT, OP_MATH, A4GL_dec_sm_ops);
  A4GL_add_op_function (DTYPE_DECIMAL, DTYPE_INT, OP_MATH, A4GL_dec_int_ops);
  A4GL_add_op_function (DTYPE_DECIMAL, DTYPE_FLOAT, OP_MATH, A4GL_dec_float_ops);
  A4GL_add_op_function (DTYPE_DECIMAL, DTYPE_SMFLOAT, OP_MATH, A4GL_dec_smfloat_ops);

  A4GL_add_op_function (DTYPE_SMINT, DTYPE_DECIMAL, OP_MATH, A4GL_sm_dec_ops);
  A4GL_add_op_function (DTYPE_INT, DTYPE_DECIMAL, OP_MATH, A4GL_int_dec_ops);
  A4GL_add_op_function (DTYPE_FLOAT, DTYPE_DECIMAL, OP_MATH, A4GL_float_dec_ops);
  A4GL_add_op_function (DTYPE_SMFLOAT, DTYPE_DECIMAL, OP_MATH, A4GL_smfloat_dec_ops);

  A4GL_add_op_function (DTYPE_DECIMAL, DTYPE_MONEY, OP_MATH, A4GL_dec_mon_ops);
  A4GL_add_op_function (DTYPE_MONEY, DTYPE_DECIMAL, OP_MATH, A4GL_mon_dec_ops);

  A4GL_add_op_function (DTYPE_MONEY, DTYPE_MONEY, OP_MATH, A4GL_mon_mon_ops);
  A4GL_add_op_function (DTYPE_MONEY, DTYPE_SMINT, OP_MATH, A4GL_mon_sm_ops);
  A4GL_add_op_function (DTYPE_MONEY, DTYPE_INT, OP_MATH, A4GL_mon_int_ops);
  A4GL_add_op_function (DTYPE_MONEY, DTYPE_FLOAT, OP_MATH, A4GL_mon_float_ops);
  A4GL_add_op_function (DTYPE_MONEY, DTYPE_SMFLOAT, OP_MATH, A4GL_mon_smfloat_ops);

  A4GL_add_op_function (DTYPE_SMINT, DTYPE_MONEY, OP_MATH, A4GL_sm_mon_ops);
  A4GL_add_op_function (DTYPE_INT, DTYPE_MONEY, OP_MATH, A4GL_int_mon_ops);
  A4GL_add_op_function (DTYPE_FLOAT, DTYPE_MONEY, OP_MATH, A4GL_float_mon_ops);
  A4GL_add_op_function (DTYPE_SMFLOAT, DTYPE_MONEY, OP_MATH, A4GL_smfloat_mon_ops);




  A4GL_debug ("Finished adding default operations");


  A4GL_add_datatype_function_i (DTYPE_INT, "DISPLAY", (void *) A4GL_display_int);
  A4GL_add_datatype_function_i (DTYPE_SERIAL, "DISPLAY", (void *) A4GL_display_int);
  A4GL_add_datatype_function_i (DTYPE_SMINT, "DISPLAY", (void *) A4GL_display_smint);
  A4GL_add_datatype_function_i (DTYPE_FLOAT, "DISPLAY", (void *) A4GL_display_float);
  A4GL_add_datatype_function_i (DTYPE_SMFLOAT, "DISPLAY", (void *) A4GL_display_smfloat);
  A4GL_add_datatype_function_i (DTYPE_DATE, "DISPLAY", (void *) A4GL_display_date);
  A4GL_add_datatype_function_i (DTYPE_CHAR, "DISPLAY", (void *) A4GL_display_char);
  A4GL_add_datatype_function_i (DTYPE_VCHAR, "DISPLAY", (void *) A4GL_display_vchar);
  A4GL_add_datatype_function_i (DTYPE_DECIMAL, "DISPLAY", (void *) A4GL_display_decimal);
  A4GL_add_datatype_function_i (DTYPE_MONEY, "DISPLAY", (void *) A4GL_display_money);
  A4GL_add_datatype_function_i (DTYPE_DTIME, "DISPLAY", (void *) A4GL_display_dtime);
  A4GL_add_datatype_function_i (DTYPE_INTERVAL, "DISPLAY", (void *) A4GL_display_interval);
  A4GL_add_datatype_function_i (DTYPE_BYTE, "DISPLAY", (void *) A4GL_display_byte);
  A4GL_add_datatype_function_i (DTYPE_TEXT, "DISPLAY", (void *) A4GL_display_text);

  A4GL_add_datatype_function_i (DTYPE_CHAR, ":getlength", (void *) A4GL_dtype_function_char_getlength);

  add_int8_support ();
  add_reference_support ();



#ifndef CSCC
  A4GL_add_datatype_function_i (DTYPE_DECIMAL, ">STRING", (void *) A4GL_tostring_decimal);
#endif


  //A4GL_add_datatype_function_i (DTYPE_DTIME,  ">STRING", A4GL_tostring_dtime);


}


void
A4GL_ltrim (char *s)
{
  int a;
  char *buff;
  char *ptr = 0;
  char *ptr2 = 0;
  int l;
  buff = acl_strdup (s);
  l = strlen (buff);
  for (a = 0; a < l; a++)
    {
      if (buff[a] == ' ')
	continue;
      ptr = &buff[a];
      break;
    }

  if (ptr == 0)
    return;
  ptr2 = acl_strdup (ptr);
  strcpy (s, ptr2);
  free (ptr2);
  free (buff);
}





char *
A4GL_make_using_tostring (char *ptr, int d, int n)
{
  static char buff_ts[256];
  char buff2[256];
  int dig;
  int dec;
  int another = 0;

  A4GL_assertion (ptr == 0, "make_using has been passed a null pointer..");

  strcpy (buff_ts,
	  "-------------------------------------------------------------------------------------------------------------------");
//dig=NUM_DIG(ptr)*2;
//dec=NUM_DEC(ptr);
  dig = d;
  dec = n;

//if (dig%2==1) another=1;

  buff_ts[dig - dec - another] = 0;

  if (dec)
    strcat (buff_ts, "&.");
  else
    strcat (buff_ts, "-&");

  memset (buff2, '&', 255);
  buff2[dec] = 0;
  strcat (buff_ts, buff2);
  return buff_ts;
}


static char *
make_using_sz (char *ptr, int sz, int dig, int dec)
{
  static char buff_sz[256];
  int a;
  int c;
  int l;
  A4GL_debug ("make_using_sz - size=%d num dec = %d dig=%d", sz, dec, dig);

  //if (dec<0) dec=5;

  l = 1;			// '-'
  l += dec;
  if (dec)
    l++;			// '.'
  l += dig - dec;

  if (l > sz)
    {
      //A4GL_dectos (ptr, buff_sz, 64);
      strcpy (buff_sz, A4GL_dec_to_str ((fgldecimal *) ptr, 0));
      A4GL_ltrim (buff_sz);
      A4GL_trim (buff_sz);

      A4GL_debug ("make_using_sz dectos returns ---> %s", buff_sz);
      if (buff_sz[0] == '-' && buff_sz[1] == '.')
	{
	  char buff[200];
	  strcpy (buff, "-0");
	  strcat (buff, &buff_sz[1]);
	  strcpy (buff_sz, buff);
	}
      if (buff_sz[0] == '.')
	{
	  char buff[200];
	  strcpy (buff, "0");
	  strcat (buff, buff_sz);
	  strcpy (buff_sz, buff);
	}


      if (strlen (buff_sz) > sz)
	{
	  char *ptr;
	  // It doesn't fit -
	  // what happens if we remove all the decimal places ?
	  ptr = a_strchr (buff_sz, '.');

	  if (ptr)
	    *ptr = 0;

	  if (strlen (buff_sz) > sz)
	    {
	      // Still doesn't fit - we're stuffed...
	      memset (buff_sz, '*', sz);
	      buff_sz[sz] = 0;
	      A4GL_debug ("make_using_sz - doesn't fit buff_sz=%s", buff_sz);
	      return buff_sz;
	    }

	  dig = strlen (buff_sz);
	  // Trim the decimals..
	  if (dec > sz - 1 - dig)
	    {
	      dec = sz - 1 - dig;
	    }

	  dig = sz - 1 - dec;
	  if (dec < 0)
	    dec = 0;
	  return make_using_sz (ptr, sz, dig, dec);
	}
    }


  memset (buff_sz, '-', 255);
  buff_sz[sz] = 0;		// Maximum length
  c = sz - 1;
  a = 0;
  if (dec)
    {
      while (a++ < dec)
	{
	  buff_sz[c--] = '&';
	}
      buff_sz[c--] = '.';
    }
  buff_sz[c--] = '&';
  return buff_sz;
}


/*
returns *d=

	DTYPE_DECIMAL
	DTYPE_INT
	DTYPE_DATE
	DTYPE_DTIME
	DTYPE_INTERVAL
*/

void
A4GL_whats_in_a_string (char *s, int *d, int *sz)
{
  int orig_conv_ok = 0;
//int is_ok;
  int a, b;
  char buff[2000];
  int val;
  int orig_stat;


  if (s == 0)
    return;
  orig_stat = a4gl_status;

  *d = DTYPE_CHAR;
  *sz = strlen (s);

  orig_conv_ok = A4GL_conversion_ok (-1);

  if (strchr (s, a4gl_convfmts.ui_decfmt.decsep))
    {
      // Check for a decimal

      A4GL_conversion_ok (1);
      val = A4GL_stodec (s, buff, 32 * 256 + 16);
      if (!A4GL_conversion_ok (-1))
	val = 0;
      if (val == 1)
	{
	  A4GL_debug ("Its a decimal");
	  *d = DTYPE_DECIMAL;
	  *sz = 32 * 256 + 16;	// Could work out a proper size here...
	  A4GL_conversion_ok (orig_conv_ok);
	  a4gl_status = orig_stat;
	  return;
	}
    }
  else
    {
      // Check for integer
      A4GL_conversion_ok (1);
      val = A4GL_stol (s, buff, 4);
      if (!A4GL_conversion_ok (-1))
	val = 0;
      if (val == 1)
	{
	  *d = DTYPE_INT;
	  *sz = 4;
	  A4GL_debug ("Its an integer");
	  A4GL_conversion_ok (orig_conv_ok);
	  a4gl_status = orig_stat;
	  return;
	}
    }


  a4gl_status = orig_stat;
  A4GL_conversion_ok (orig_conv_ok);

  // Check for date
  A4GL_conversion_ok (1);
  val = A4GL_stod (s, buff, 4);
  if (!A4GL_conversion_ok (-1))
    val = 0;
  if (val == 1)
    {
      *d = DTYPE_DATE;
      *sz = 4;
      A4GL_debug ("Its a date");
      A4GL_conversion_ok (orig_conv_ok);
      a4gl_status = orig_stat;
      return;
    }



  a4gl_status = orig_stat;
  A4GL_conversion_ok (orig_conv_ok);
// Check for a datetime...
  for (a = 0; a <= 10; a++)
    {
      for (b = a; b <= 10; b++)
	{
	  if (a == b)
	    continue;		// Year year, month month etc = integer
	  A4GL_conversion_ok (1);
	  val = A4GL_ctodt (s, buff, (a << 4) + b);
	  if (val)
	    {
	      if (A4GL_isnull (DTYPE_DTIME, buff))
		val = 0;
	      if (!A4GL_conversion_ok (-1))
		val = 0;
	      if (val)
		{
		  A4GL_debug ("Possible DATETIME %d to %d", a, b);
		  *d = DTYPE_DTIME;
		  *sz = (a << 4) + b;
		  return;
		}
	    }

	}
    }


// Lets put right what might have gone wrong..
  a4gl_status = orig_stat;
  A4GL_conversion_ok (orig_conv_ok);

  for (a = 0; a <= 10; a++)
    {
      int size_b;
      for (b = a; b <= 10; b++)
	{
	  char str[256];
	  int ibuff[30];
	  strcpy (str, s);

	  if (a == b)
	    continue;		// Year year, month month etc = integer
	  size_b = 0x600 + ((a + 1) << 4) + (b + 1);
	  if ((a == 0 || a == 1) && b > 1)
	    continue;

	  if (A4GL_valid_int (str, ibuff, size_b))
	    {
	      A4GL_debug ("Possible INTERVAL %d to %d", a, b);
	      *d = DTYPE_INTERVAL;
	      *sz = size_b;
	      return;
	    }

	}
    }


  // Lets put right what might have gone wrong..
  a4gl_status = orig_stat;
  A4GL_conversion_ok (orig_conv_ok);

}


static void
push_dec_op_from_int_int (int a, int b, char op)
{
  M_APM a1;
  M_APM b1;
  M_APM tmp;
  a1 = m_apm_init ();
  b1 = m_apm_init ();
  tmp = m_apm_init ();

  m_apm_set_long (a1, a);
  m_apm_set_long (b1, b);

  switch (op)
    {
    case '/':
      m_apm_divide (tmp, 16, a1, b1);
      break;
    default:
      A4GL_assertion (1, "Unknown op");
    }

  A4GL_push_dec_from_apm (tmp);
  m_apm_free (a1);
  m_apm_free (b1);
  m_apm_free (tmp);
}

