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
# $Id: mpz.c,v 1.13 2005-03-31 16:45:03 mikeaubury Exp $
*/

/**
 * @file
 *
 * Mechanism whereby datatypes can be added to the 4GL language.
 * The mpz datatype is a arbitrary precision integer datatype that can handle
 * very very large numbers.
 *
 * API is in lib/libaubit4gl/datatypes.c (to rename to API_exdata.c)
 *
 * See example testmpz.4gl into the tools/test directory.
 *
 */

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#define _NO_FORM_X_H_
#define MPZ_DTYPE_NAME "MPZ"

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_lib_exdata_mpz_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/


/* Just implement mpz for now (large integers) */
int dtype_mpz = 0;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


char *A4GL_include_mpz (void);
char *A4GL_pr_mpz (void);
void A4GL_init_mpz (mpz_t * mpz);
int a4gl_mpz_setfib (mpz_t * ptr, int nparam);
int a4gl_mpz_nextprime (mpz_t * ptr, int nparam);
void *A4GL_mpz_alloc (void);
int A4GL_mpz_from_double (double *n, mpz_t * mpz, int szignore);
int A4GL_mpz_from_int (long *n, mpz_t * mpz, int szignore);
int A4GL_mpz_from_mpz (mpz_t * n, mpz_t * mpz, int szignore);
int A4GL_mpz_from_str (char *n, mpz_t * mpz, int szignore);
int A4GL_mpz_to_double (mpz_t * mpz, double *n, int szignore);
int A4GL_mpz_to_int (mpz_t * mpz, long *n, int szignore);
int A4GL_mpz_to_mpz (mpz_t * mpz, mpz_t * n, int szignore);
char *A4GL_mpz_str (mpz_t * mpz, char *n, int sz);
int A4GL_mpz_to_str (mpz_t * mpz, char *n, int sz);
void A4GL_add_mpz (int dummy);
void A4GL_sub_mpz (int dummy);
void A4GL_mul_mpz (int dummy);
void A4GL_pow_mpz (int dummy);
void A4GL_div_mpz (int dummy);
void A4GL_mod_mpz (int dummy);
int A4GL_compare_mpz (void);
void A4GL_gt_mpz (int dummy);
void A4GL_gte_mpz (int dummy);
void A4GL_lt_mpz (int dummy);
void A4GL_lte_mpz (int dummy);
void A4GL_e_mpz (int dummy);
void A4GL_ne_mpz (int dummy);
void A4GL_mpz_free (void *ptr);
mpz_t *A4GL_mpz_copy (mpz_t * a1);
int A4GL_isnull_mpz (void);
void EXDTYPE_initlib (void);




/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 *
 *
 * @todo : Describe function
 */
char *
A4GL_include_mpz (void)
{

  /* 
     FIXME
     Should really check the language type before printing
   */
  return "gmp";
}


/**
 *
 *
 * @todo : Describe function
 */
char *
A4GL_pr_mpz (void)
{
  /*
     FIXME...
     Should really check the language type before printing
   */

  return "mpz_t ";
}

/**
 *
 *
 * @todo : Describe function
 */
void
A4GL_init_mpz (mpz_t * mpz)
{
  mpz_init (*mpz);
}




/**
 * This is an example of an 'Inplace' function, nothing is pushed onto the stack
 *
 * @todo : Describe function
 */
int
a4gl_mpz_setfib (mpz_t * ptr, int nparam)
{
/*	static mpz_t pout; */
  unsigned long a;
  a = A4GL_pop_int ();

  A4GL_debug ("mpz_setfib ptr=%p nparam=%d a=%d\n", ptr, nparam, a);
  mpz_init (*ptr);
  mpz_fib_ui (*ptr, a);

  return 0;
}


/**
 * This is an example of a stack function - the value is returned onto the
 * stack to be pop'd off using a 'returning' clause
 *
 * @todo : Describe function
 */
int
a4gl_mpz_nextprime (mpz_t * ptr, int nparam)
{
  static mpz_t pout;
  A4GL_debug ("ptr=%p nparam=%d\n", ptr, nparam);
  mpz_init (pout);
  mpz_nextprime (pout, *ptr);
  A4GL_push_variable (&pout, dtype_mpz);
  return 1;
}




/**
 *
 *
 * @todo : Describe function
 */
void *
A4GL_mpz_alloc (void)
{
  mpz_t *ptr;
  ptr = (mpz_t *) malloc (sizeof (mpz_t));
  mpz_init (*ptr);
  return ptr;
}


/**
 *
 *
 * @todo : Describe function
 */
int
A4GL_mpz_from_double (double *n, mpz_t * mpz, int szignore)
{
  A4GL_debug ("mpz_from_double");
  mpz_init (*mpz);
  mpz_set_d (*mpz, *n);
  return 1;
}

/**
 *
 *
 * @todo : Describe function
 */
int
A4GL_mpz_from_int (long *n, mpz_t * mpz, int szignore)
{
  A4GL_debug ("mpz_from_int");
  mpz_init (*mpz);
  mpz_set_si (*mpz, *n);
  return 1;
}

/**
 *
 *
 * @todo : Describe function
 */
int
A4GL_mpz_from_mpz (mpz_t * n, mpz_t * mpz, int szignore)
{
  A4GL_debug ("mpz_from_mpz");
  mpz_init (*mpz);
  mpz_set (*mpz, *n);
  return 1;
}

/**
 *
 *
 * @todo : Describe function
 */
int
A4GL_mpz_from_str (char *n, mpz_t * mpz, int szignore)
{
  A4GL_debug ("mpz_from_str");
  mpz_init (*mpz);
  mpz_set_str (*mpz, n, 0);
  return 1;

}

/**
 *
 *
 * @todo : Describe function
 */
int
A4GL_mpz_to_double (mpz_t * mpz, double *n, int szignore)
{
  A4GL_debug ("mpz_to_double");
  *n = mpz_get_d (*mpz);
  return 1;
}

/**
 *
 *
 * @todo : Describe function
 */
int
A4GL_mpz_to_int (mpz_t * mpz, long *n, int szignore)
{
  A4GL_debug ("%p %p (%d %d)\n", mpz, n, *(long *) mpz, *(long *) n);
  A4GL_debug ("mpz_to_int");
  *n = mpz_get_si (*mpz);
  return 1;
}

/**
 *
 *
 * @todo : Describe function
 */
int
A4GL_mpz_to_mpz (mpz_t * mpz, mpz_t * n, int szignore)
{
  A4GL_debug ("mpz_to_mpz");
  mpz_set (*mpz, *n);
  return 1;
}


/**
 *
 *
 * @todo : Describe function
 */
char *
A4GL_mpz_str (mpz_t * mpz, char *n, int sz)
{
  A4GL_debug ("mpz_str");
  return mpz_get_str (n, 10, *mpz);
}

/**
 *
 *
 * @todo : Describe function
 */
int
A4GL_mpz_to_str (mpz_t * mpz, char *n, int sz)
{
  char *ptr;
  A4GL_debug ("mpz_to_str");

  ptr = mpz_get_str (0, 10, *mpz);
  if (strlen (ptr) > sz)
    {
      free (ptr);
      return 0;
    }
  else
    {
      memset (n, ' ', sz);
      n[sz - 1] = 0;
      n[sz - strlen (ptr)] = 0;
      strcat (n, ptr);
    }
  return 1;
}

/**
 *
 *
 * @todo : Describe function
 */
void
A4GL_add_mpz (int dummy)
{
  mpz_t a1;
  mpz_t a2;
  mpz_t *ptr;
  ptr = malloc (sizeof (mpz_t));
  A4GL_debug ("add_mpz");
  A4GL_pop_param (&a2, dtype_mpz, 0);
  A4GL_pop_param (&a1, dtype_mpz, 0);

  mpz_init (*ptr);
  mpz_add (*ptr, a1, a2);

  mpz_clear (a1);
  mpz_clear (a2);

  A4GL_push_param (ptr, dtype_mpz | DTYPE_MALLOCED);

}

/**
 *
 *
 * @todo : Describe function
 */
void
A4GL_sub_mpz (int dummy)
{
  mpz_t a1;
  mpz_t a2;
  mpz_t *ptr;
  ptr = malloc (sizeof (mpz_t));
  A4GL_debug ("sub_mpz");

  A4GL_pop_param (&a2, dtype_mpz, 0);
  A4GL_pop_param (&a1, dtype_mpz, 0);

  mpz_init (*ptr);
  mpz_sub (*ptr, a1, a2);
  mpz_clear (a1);
  mpz_clear (a2);
  A4GL_push_param (ptr, dtype_mpz | DTYPE_MALLOCED);
}

/**
 *
 *
 * @todo : Describe function
 */
void
A4GL_mul_mpz (int dummy)
{
  mpz_t a1;
  mpz_t a2;
  mpz_t *ptr;
  ptr = malloc (sizeof (mpz_t));
  A4GL_debug ("mul_mpz");

  A4GL_pop_param (&a2, dtype_mpz, 0);
  A4GL_pop_param (&a1, dtype_mpz, 0);

  mpz_init (*ptr);
  mpz_mul (*ptr, a1, a2);
  mpz_clear (a1);
  mpz_clear (a2);
  A4GL_push_param (ptr, dtype_mpz | DTYPE_MALLOCED);
}

/**
 *
 *
 * @todo : Describe function
 */
void
A4GL_pow_mpz (int dummy)
{
  mpz_t a1;
  unsigned int a2;
  mpz_t *ptr;

  ptr = malloc (sizeof (mpz_t));
  A4GL_debug ("pow_mpz");
  A4GL_debug_print_stack ();
  A4GL_pop_param (&a2, DTYPE_INT, 0);
  A4GL_pop_param (&a1, dtype_mpz, 0);

  mpz_init (*ptr);
  A4GL_debug ("Raising value to A4GL_power of %d", a2);
  mpz_pow_ui (*ptr, a1, a2);
  mpz_clear (a1);
  A4GL_push_param (ptr, dtype_mpz | DTYPE_MALLOCED);
}



/**
 *
 *
 * @todo : Describe function
 */
void
A4GL_div_mpz (int dummy)
{
  mpz_t a1;
  mpz_t a2;
  mpz_t *ptr;
  ptr = malloc (sizeof (mpz_t));
  A4GL_debug ("div_mpz");

  A4GL_pop_param (&a2, dtype_mpz, 0);
  A4GL_pop_param (&a1, dtype_mpz, 0);

  mpz_init (*ptr);
  mpz_fdiv_q (*ptr, a1, a2);
  mpz_clear (a1);
  mpz_clear (a2);
  A4GL_push_param (ptr, dtype_mpz | DTYPE_MALLOCED);
}


/**
 *
 *
 * @todo : Describe function
 */
void
A4GL_mod_mpz (int dummy)
{
  mpz_t a1;
  mpz_t a2;
  mpz_t *ptr;
  ptr = malloc (sizeof (mpz_t));
  A4GL_debug ("mod_mpz");

  A4GL_pop_param (&a2, dtype_mpz, 0);
  A4GL_pop_param (&a1, dtype_mpz, 0);

  mpz_init (*ptr);
  mpz_mod (*ptr, a1, a2);
  mpz_clear (a1);
  mpz_clear (a2);
  A4GL_push_param (ptr, dtype_mpz | DTYPE_MALLOCED);

}


/**
 *
 *
 * @todo : Describe function
 */
int
A4GL_compare_mpz (void)
{
  mpz_t a1;
  mpz_t a2;

  A4GL_pop_param (&a2, dtype_mpz, 0);
  A4GL_pop_param (&a1, dtype_mpz, 0);

  return mpz_cmp (a1, a2);

}

/**
 *
 *
 * @todo : Describe function
 */
void
A4GL_gt_mpz (int dummy)
{
  if (A4GL_compare_mpz () > 0)
    A4GL_push_int (1);
  else
    A4GL_push_int (0);
}

/**
 *
 *
 * @todo : Describe function
 */
void
A4GL_gte_mpz (int dummy)
{
  if (A4GL_compare_mpz () >= 0)
    A4GL_push_int (1);
  else
    A4GL_push_int (0);
}

/**
 *
 *
 * @todo : Describe function
 */
void
A4GL_lt_mpz (int dummy)
{
  if (A4GL_compare_mpz () < 0)
    A4GL_push_int (1);
  else
    A4GL_push_int (0);
}

/**
 *
 *
 * @todo : Describe function
 */
void
A4GL_lte_mpz (int dummy)
{
  if (A4GL_compare_mpz () <= 0)
    A4GL_push_int (1);
  else
    A4GL_push_int (0);
}

/**
 *
 *
 * @todo : Describe function
 */
void
A4GL_e_mpz (int dummy)
{
  if (A4GL_compare_mpz () == 0)
    A4GL_push_int (1);
  else
    A4GL_push_int (0);
}

/**
 *
 *
 * @todo : Describe function
 */
void
A4GL_ne_mpz (int dummy)
{
  if (A4GL_compare_mpz () != 0)
    A4GL_push_int (1);
  else
    A4GL_push_int (0);
}


/**
 *
 *
 * @todo : Describe function
 */
void
A4GL_mpz_free (void *ptr)
{
  // Nothing special
  free (ptr);
}


/**
 *
 *
 * @todo : Describe function
 */
mpz_t *
A4GL_mpz_copy (mpz_t * a1)
{
  mpz_t *a2;
  a2 = A4GL_mpz_alloc ();
  mpz_set (*a2, *a1);
  return a2;
}


/**
 *
 *
 * @todo : Describe function
 */
int
A4GL_isnull_mpz (void)
{
  /* Its never null */
  return 0;
}

/**
 *
 *
 * @todo : Describe function
 */
void
EXDTYPE_initlib (void)
{
  dtype_mpz = A4GL_add_datatype (MPZ_DTYPE_NAME, -1, 6);
  A4GL_add_datatype_function_n (MPZ_DTYPE_NAME, "INCLUDE", A4GL_include_mpz);
  A4GL_add_datatype_function_n (MPZ_DTYPE_NAME, "OUTPUT", A4GL_pr_mpz);

  /* These are used to push onto and off the stack */
  A4GL_add_datatype_function_n (MPZ_DTYPE_NAME, "ALLOC", A4GL_mpz_alloc);
  A4GL_add_datatype_function_n (MPZ_DTYPE_NAME, "COPY", A4GL_mpz_copy);
  A4GL_add_datatype_function_n (MPZ_DTYPE_NAME, "FREE", A4GL_mpz_free);

  /* INITIALIZE */
  A4GL_add_datatype_function_n (MPZ_DTYPE_NAME, "INIT", A4GL_init_mpz);

  /* ISNULL */
  A4GL_add_datatype_function_n (MPZ_DTYPE_NAME, "ISNULL", A4GL_isnull_mpz);

  /*
     Basic string handling
     Note - this is not the same as a string->dtype or dtype->string
     conversion. It is used internally
     Its only used for a char_pop
     which should generate a properly sized string output for the given
     datatype (eg for a smallint - 6 characters (inc sign).
   */
  A4GL_add_datatype_function_n (MPZ_DTYPE_NAME, ">STRING", A4GL_mpz_str);


  /* Not sure if we need this one yet */
  A4GL_add_datatype_function_n (MPZ_DTYPE_NAME, "<STRING", A4GL_mpz_from_str);


  /*
     These functions are 'class' functions
     a ':' function is callable from 4gl via
     the variable:function() syntax...
   */
  A4GL_add_datatype_function_n (MPZ_DTYPE_NAME, ":nextprime", a4gl_mpz_nextprime);
  A4GL_add_datatype_function_n (MPZ_DTYPE_NAME, ":setfib", a4gl_mpz_setfib);



  /* These will only apply to TWO MPZ variables */
  A4GL_add_op_function (dtype_mpz, dtype_mpz, OP_ADD, A4GL_add_mpz);


  A4GL_add_op_function (dtype_mpz, dtype_mpz, OP_SUB, A4GL_sub_mpz);
  A4GL_add_op_function (dtype_mpz, dtype_mpz, OP_MULT, A4GL_mul_mpz);

  A4GL_add_op_function (dtype_mpz, dtype_mpz, OP_POWER, A4GL_pow_mpz);

  /*
     A4GL_add_op_function(DTYPE_INT,dtype_mpz,OP_POWER,A4GL_pow_mpz);
     A4GL_add_op_function(dtype_mpz,DTYPE_INT,OP_POWER,A4GL_pow_mpz);
     A4GL_add_op_function(DTYPE_INT,DTYPE_INT,OP_POWER,A4GL_pow_mpz);
   */

  A4GL_add_op_function (dtype_mpz, dtype_mpz, OP_DIV, A4GL_div_mpz);
  A4GL_add_op_function (dtype_mpz, dtype_mpz, OP_MOD, A4GL_mod_mpz);

  A4GL_add_op_function (dtype_mpz, dtype_mpz, OP_GREATER_THAN, A4GL_gt_mpz);
  A4GL_add_op_function (dtype_mpz, dtype_mpz, OP_LESS_THAN, A4GL_lt_mpz);

  A4GL_add_op_function (dtype_mpz, dtype_mpz, OP_GREATER_THAN_EQ, A4GL_gte_mpz);
  A4GL_add_op_function (dtype_mpz, dtype_mpz, OP_LESS_THAN_EQ, A4GL_gte_mpz);

  A4GL_add_op_function (dtype_mpz, dtype_mpz, OP_EQUAL, A4GL_e_mpz);
  A4GL_add_op_function (dtype_mpz, dtype_mpz, OP_NOT_EQUAL, A4GL_ne_mpz);



  /* Conversions to normal datatypes */
  A4GL_add_conversion ("CHAR", MPZ_DTYPE_NAME, A4GL_mpz_from_str);
  A4GL_add_conversion ("INTEGER", MPZ_DTYPE_NAME, A4GL_mpz_from_int);
  A4GL_add_conversion ("FLOAT", MPZ_DTYPE_NAME, A4GL_mpz_from_double);


  A4GL_add_conversion (MPZ_DTYPE_NAME, MPZ_DTYPE_NAME, A4GL_mpz_from_mpz);


  A4GL_add_conversion (MPZ_DTYPE_NAME, "CHAR", A4GL_mpz_to_str);
  A4GL_add_conversion (MPZ_DTYPE_NAME, "INTEGER", A4GL_mpz_to_int);
  A4GL_add_conversion (MPZ_DTYPE_NAME, "FLOAT", A4GL_mpz_to_double);

  /* add_conversion(MPZ_DTYPE_NAME,MPZ_DTYPE_NAME,A4GL_mpz_to_mpz); */

  A4GL_debug ("Finished EXDTYPE_initlib");

}


/* ================================= EOF =============================== */
