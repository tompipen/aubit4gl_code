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
# $Id: stack.c,v 1.40 2003-02-26 22:28:11 mikeaubury Exp $
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


/*
=====================================================================
                    Constants definitions
=====================================================================
*/

/* #define DIGIT_ALIGN_LEFT */

#define IGN 0xee
#define UC (unsigned char)
#define LOCAL_BINDINGS 20
void process_stack_op_other(int d);

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

//extern int errno;

int nset[MAX_DTYPE][9] = {
  {0x0, 0x0, IGN, IGN, IGN, IGN, IGN, IGN, IGN},
  {0x0, 0x80, IGN, IGN, IGN, IGN, IGN, IGN, IGN},
  {0x0, 0x0, 0x0, 0x80, IGN, IGN, IGN, IGN, IGN},
  {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, IGN},
  {0xff, 0xff, 0xff, 0xff, IGN, IGN, IGN, IGN, IGN},
  {0x0, 0x0, 0xff, 0xff, 0x0, 0x0, IGN, IGN, IGN},
  {0x0, 0x0, 0x0, 0x80, 0xff, 0xff, 0xff, 0xff, IGN},
  {0x0, 0x0, 0x0, 0x80, 0xff, 0xff, 0xff, 0xff, IGN},
  {0x0, 0x0, 0xff, 0xff, 0x0, 0x0, IGN, IGN, IGN},
  {IGN, IGN, IGN, IGN, IGN, IGN, IGN, IGN, IGN},
  {IGN, IGN, 0x0, 0x0, 0xff, 0xff, 0x0, 0x0, IGN},
  {IGN, IGN, IGN, IGN, IGN, IGN, IGN, IGN, IGN},
  {IGN, IGN, IGN, IGN, IGN, IGN, IGN, IGN, IGN},
  {0x0, IGN, IGN, IGN, IGN, IGN, IGN, IGN, IGN},
  {IGN, IGN, 0x0, 0x0, 0xff, 0xff, 0x0, 0x0, IGN}
};

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
int local_binding_cnt = 0;
int init_local_bindings = 0;
struct BINDING *local_binding[LOCAL_BINDINGS];
int num_local_binding[LOCAL_BINDINGS];

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

/* see a4gl_stack.h */


void * 		pop_binding 			(int *n);
void 		push_ascii 				(void);
void 		push_current 			(int a, int b);
void 		push_time 				(void);
void		push_disp_bind 			(struct BINDING *b, int n);
int			chk_params 				(struct BINDING *b, int nb,
									struct BINDING *o, int no);
void        upshift_stk 			(void);
void        downshift_stk 			(void);
int         isparamdate 			(void);
void        set_init 				(struct BINDING *b, int n, int no);
int         push_binding 			(void *ptr, int num);
void        dif_add_bind 			(struct bound_list *list, void *dptr,
									int dtype, int size);
void        dif_add_bind_date 		(struct bound_list *list, long a);
void        dif_add_bind_smint 		(struct bound_list *list, int a);
void        dif_add_bind_smint_ptr 	(struct bound_list *list, int *a);
void        dif_add_bind_dbl_ptr 	(struct bound_list *list, double *a);
void        dif_add_bind_int 		(struct bound_list *list, long a);
void        dif_add_bind_float 		(struct bound_list *list, double a);
void        dif_add_bind_smfloat 	(struct bound_list *list, float a);
void        dif_add_bind_char 		(struct bound_list *list, char *a);
void        dif_free_bind 			(struct bound_list *list);
void        dif_print_bind 			(struct bound_list *list);
long        dif_pop_bind_int 		(struct bound_list *list);
char *      dif_pop_bind_char 		(struct bound_list *list);
int         dif_pop_bind_smint 		(struct bound_list *list);
int         dif_pop_bind_float 		(struct bound_list *list);
int         dif_pop_bind_smfloat 	(struct bound_list *list);
int         dif_pop_bind_dec 		(struct bound_list *list);
int         dif_pop_bind_money 		(struct bound_list *list);

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
pop_bool (void)
{
  int ptr;
  ptr=0;

  debug ("Popping boolean..");
	//debug_print_stack();
  ptr=pop_int();
  //pop_param (&ptr, DTYPE_SMINT, 0);
  debug ("Popping boolean gets %d %x",ptr,ptr);

	if (ptr!=0&&ptr!=1) {
			debug("SERIOUS PROBLEM ?????");
			debug_print_stack();
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
pop_int (void)
{
  short ptr;
  int b;
  b = pop_param (&ptr, DTYPE_SMINT, 0);
#ifdef DEBUG
  debug ("pop_int b=%d\n", b);
#endif
  ptr=ptr&0xffff;
  return ptr;
}

/**
 * Pop a long value from the stack.
 *
 * @return The long value poped.
 */
long
pop_long (void)
{
  long ptr;
  pop_param (&ptr, DTYPE_INT, 0);
  return ptr;
}

/**
 * Pop a date value from the stack.
 *
 * @return The date value poped.
 */
long
pop_date (void)
{
  long ptr;
  pop_param (&ptr, DTYPE_DATE, 0);
  return ptr;
}

/**
 * Pop a float value from the stack.
 *
 * @return The date value poped.
 */
float
pop_float (void)
{
  float ptr;
  pop_param (&ptr, DTYPE_SMFLOAT, 0);
  return ptr;
}

/**
 * Pop a double value from the stack.
 *
 * @return The date value poped.
 */
double
pop_double (void)
{
  double ptr;
  pop_param (&ptr, DTYPE_FLOAT, 0);
  return ptr;
}

/**
 *
 *
 * @return
 */
int
pop_var (void *p, int d)
{
  int z;
  int s;
  s = DECODE_SIZE (d);
#ifdef DEBUG
	debug ("pop variable type %d %x (%d) \n", d, d, s);
#endif
  z = pop_param (p, d, s);
#ifdef DEBUG
	debug ("z=%d", z);
#endif
  if (((z) != (1)))
    {
      exitwith ("Error in conversion");
#ifdef DEBUG
	debug ("pop_var: error in conversion %d\n", z);
#endif
      return 0;
    }
  else
    {
#ifdef DEBUG
	debug ("pop_var: conversion ok");
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
pop_var2 (void *p, int d, int s)
{
  int z;
  char *pl;

	#ifdef DEBUG
  		debug ("pop_var2 : ptr=%p dtype=%d size=%d", p, d, s);
	#endif

  if (d == 0)
    {
      pl = new_string (s);
      z = pop_param (pl, d, s);
	#ifdef DEBUG
    	debug ("z=%d\n", z);
	#endif
      if (z == 1)
	{
	#ifdef DEBUG
		debug ("zconv ok");
	#endif
	}
      if (z != 1)
	{
	#ifdef DEBUG
		debug ("zconv bad");
	#endif
	}
      if (((z) != (1)))
	{
	#ifdef DEBUG
		debug ("pop_var2: error in conversion %d d=0 s=%d\n",z, s);
	#endif
	}
      debug ("Copying string '%s' to p", pl);
      strcpy ((char *) p, pl);
      pl = (char *) p;
      pl[s] = 0;		/* changed from s+1 to s */
      return z;
    }

  z = pop_param (p, d, s);
  if (z != 1)
    {
      exitwith ("Error in conversion");
	#ifdef DEBUG
    	debug ("pop_var2 - error in conversion %d d=%d s=%d\n", z,d, s);
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
ret_var (void *p, int d)
{
#ifdef DEBUG
  /* {DEBUG} */ debug ("ret_var - %p %d", p, d);
#endif
  return pop_param (&p, d, 0);
}

/**
 *
 *
 * @return
 */
int
pop_char (char *z, int size)
{
  int a;
  a = pop_param (z, DTYPE_CHAR, size);
#ifdef DEBUG
  /* {DEBUG} */ debug ("pop_char returns char ='%s'", z);
#endif
  return a;
}




int dtype_alloc_char_size[] = {
  /*datatypes
     0 1  2  3 4 5  6  7  8  9 10 11 12 13 14 15 */
  0, 6, 11, 14, 14, 16, 12, 10, 16, 0, 20, 20, 20, 20, 20, 20
};



/**
 * create a perfectly sized string to hold the info 
 */
char *
char_pop (void)
{
  int a;
  char *s;
  int f;


  if ((params[params_cnt - 1].dtype & DTYPE_MASK) != 0)
    {
      f = params[params_cnt - 1].dtype & DTYPE_MASK;


      if (has_datatype_function_i (f, ">STRING"))
	{
	  char *(*function) (void *, char *, int);
	debug("Calling >STRING for datatype");
	  function = get_datatype_function_i (f, ">STRING");
	  s = function (params[params_cnt - 1].ptr, 0, 0);
	  drop_param();
	}
      else
	{
	  s = new_string (dtype_alloc_char_size[f]);
	  pop_char (s, dtype_alloc_char_size[f]);
	}

      trim (s);
      push_char (s);
      params[params_cnt - 1].size = strlen (params[params_cnt - 1].ptr);
    }		/* if last entry is not a character string make it one */
  else
    {
      params[params_cnt - 1].size = strlen (params[params_cnt - 1].ptr);
    }

  a = params[params_cnt - 1].size;
  s = new_string (a);
  a = pop_param (s, DTYPE_CHAR, a);
  return s;
}

/**
 *
 *
 * @return
 */
int
pop_param (void *p, int d, int size)
{
  int b;
  char *ptr;
  params_cnt--;
////printf("pop_param....\n");
  if (params_cnt<0) {
	  	debug("Stack got corrupted");
	  	assertion(1,"Stack got corrupted");
		exit(0);
  }
  debug ("pop_param... %d %d %d", params[params_cnt].dtype & DTYPE_MASK,
	 d & DTYPE_MASK, size);
  debug ("             %p %p ", params[params_cnt].ptr, p);


  b = conv (params[params_cnt].dtype & DTYPE_MASK,
	    params[params_cnt].ptr, d & DTYPE_MASK, p, size);

#ifdef DEBUG
  /* {DEBUG} */ debug ("Conversion returns %d", b);
#endif

  if (params[params_cnt].dtype & DTYPE_MALLOCED)
    {
      debug ("Malloced ");
      /*printf("Datatype=%d\n",params[params_cnt].dtype&DTYPE_MASK); */
      if ((params[params_cnt].dtype & DTYPE_MASK) != 0)
	{
	  debug ("Not Char.. %p", params[params_cnt].ptr);
	  acl_free (params[params_cnt].ptr);
	}
      else
	{
	  ptr = params[params_cnt].ptr;
	  debug ("Not Char..%p", ptr);
	  acl_free (ptr);
	}
    }
  debug ("Returning %d\n", b);
  return b;
}

/**
 * Pop parameters from a function call
 *
 * @param b
 * @param n
 */
void
pop_params (struct BINDING *b, int n)
{
  int a;
  for (a = n - 1; a >= 0; a--)
    {
      pop_param (b[a].ptr, b[a].dtype, b[a].size);
    }
}

/**
 *
 *
 * @return
 */
void
push_params (struct BINDING *b, int n)
{
  int a;
  for (a = 0; a < n; a++)
    {
      push_param (b[a].ptr, b[a].dtype);
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
pop_binding (int *n)
{
  local_binding_cnt--;
  *n = num_local_binding[local_binding_cnt];
  debug ("MJA - returning binding %p", local_binding[local_binding_cnt]);
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
push_param (void *p, int d)
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
  int ptr1;
  int ptr2 = 0;
  int dtype_1=-1;
  int dtype_2=-1;


  size = DECODE_SIZE (d);
  d = d & 0xffff;


  if (params == 0)
    {
      debug ("Assign stack");
      params = (struct param *) acl_malloc (sizeof (struct param) * NUM_PARAM,
					    "Assign stack");
      alloc_params_cnt = NUM_PARAM;
    }

  if (params != 0 && params_cnt >= alloc_params_cnt)
    {
      debug ("Allocating more space for stack\n");
      alloc_params_cnt += NUM_PARAM;
      params = (struct param *) realloc (params,
					 sizeof (struct param) *
					 alloc_params_cnt);
    }

  if (params != 0 && params_cnt < alloc_params_cnt - NUM_PARAM && params_cnt>1)
    {
      debug ("Allocating less space for stack\n");
      alloc_params_cnt -= NUM_PARAM;
      params = (struct param *) realloc (params,
					 sizeof (struct param) *
					 alloc_params_cnt);
    }



  if (d == FUNCTION_OP)
    {
      find_function ((char *) p);
      return;
    }

  if (d < OP_MASK_BASE)
    {

#ifdef DEBUG
      /*  debug ("Adding ptr=%p d=%d (%d masked) to stack %d\n", p, d, d & DTYPE_MASK, params_cnt); */
#endif
      if (params_cnt >= alloc_params_cnt)
	{
	  exitwith ("Stack overflow");
	  chk_err (-1, "Internal");
	}
      params[params_cnt].ptr = p;
      params[params_cnt].dtype = d;

      if ((d & DTYPE_MASK) == 0 && size == 0)
	{
	  size = strlen (p);
#ifdef DEBUG
	debug ("Defaulting size");
#endif
	}

      if ((d & DTYPE_MASK) == 0)
	{
#ifdef DEBUG
	debug ("Adding string '%s' size %d", p, size);
#endif
	}

      params[params_cnt].size = size;
      params_cnt++;
      return;
    }

  n1 = 0;
  debug ("params_cnt=%d\n", params_cnt);
  if (params_cnt > 0)
    {
      dtype_1=params[params_cnt - 1].dtype;
      if (isnull (params[params_cnt - 1].dtype, params[params_cnt - 1].ptr))
	{

	  debug ("MJA1 %d", strlen (params[params_cnt - 1].ptr));

	  /* I don't remember what this is for - so I'm getting shot for now */
	  zzz = (params[params_cnt - 1].dtype & DTYPE_MASK) +
	    (strlen (params[params_cnt - 1].ptr)) +
	    (params[params_cnt - 1].size);

	  zzz = 1;

	  debug ("zzz=%d\n", zzz);

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
  debug ("Checking 2nd");
  if (params_cnt > 1)
    {
      dtype_2=params[params_cnt - 2].dtype;
      if (isnull (params[params_cnt - 2].dtype, params[params_cnt - 2].ptr))
	{
	  debug ("MJA2");
	  zzz =
	    ((params[params_cnt - 2].dtype & DTYPE_MASK) +
	     (strlen (params[params_cnt - 2].ptr)));	/* + params[params_cnt - 2].size; */
	  zzz = 1;

	  if (zzz == 0)
	    n2 = 0;
	  else
	    n2 = 1;
	}
      else
	n2 = 0;
    }

  debug ("Checked %d %d", n1, n2);


	/*
	Have a look see if this condition
	is specifically handled
    	*/

  if (dtype_2==-1) dtype_2=dtype_1;

  if (dtype_1!=-1) {
	void (*function) (int);
	debug("Calling OP function");

	function=0;


/* 
	First - lets see if we have a OP_MATH function available
*/
	switch(d) {
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
			function=find_op_function(dtype_2,dtype_1,OP_MATH);
	}

	debug("Looked for GENERIC MATH handing - %d %d %d - got %p\n",dtype_2,dtype_1,OP_MATH,function);

	if (function==0) {
	/* Nope - try a specific */
		function=find_op_function(dtype_2,dtype_1,d);
		debug("Looked for SPECIFIC handing - %d %d %d - got %p\n",dtype_2,dtype_1,d,function);
	}


	if (function) {
		/* We've got something to play with*/
		debug("Calling specified function for %d %d, %d",dtype_1&DTYPE_MASK,dtype_2&DTYPE_MASK,d);
		function(d);
		return;
	}

  }



  if ((d) == (OP_ISNULL))
    {
      debug ("d=%d OP_ISNULL=%d", d, OP_ISNULL);
      debug ("Checking ISNULL");
      drop_param ();
      if (n1)
	{
	  debug ("Yep");
	  push_int (1);
	}
      else
	{
	  debug ("Nope");
	  push_int (0);
	}
      debug ("Finished..");
      return;
    }

  if (d == OP_ISNOTNULL)
    {
      pop_char (buff, 79);
      if (n1)
	push_int (0);
      else
	push_int (1);
      return;
    }

  if (d == OP_IN || d == OP_NOTIN)
    {
      int a;
      int ok = 0;
      int eql;
      debug ("MJA OP_IN Set");
      a = pop_int ();
      while (a >= 1)
	{
	  debug ("MJA Getting base value from stack.. a=%d", a);
	  get_top_of_stack (a + 1, &d1, &s1, (void **) &ptr1);
	  debug ("MJA Got %p 0x%x %d\n", ptr1, d1, s1);
	  debug (" MJA *ptr1=%d", *(int *) ptr1);
	  push_param ((void *) ptr1, (d1 & DTYPE_MASK) + ENCODE_SIZE (s1));
	  pushop (OP_EQUAL);
	  debug ("MJA Pushed OP_EQUAL");
	  eql = pop_int ();
	  debug ("MJA Got OP_EQUAL  = %d\n", eql);
	  if (eql)
	    ok = 1;
	  a--;
	}
      debug ("MJA Setting ok=%d\n", ok);
      drop_param ();		/* Get rid of the base... */
      if (d == OP_IN)
	push_int (ok);
      else
	push_int (!ok);
      return;
    }

  if (d == OP_IN_SELECT || d == OP_NOTIN_SELECT)
    {
      int a;
      int ok = 0;
      int eql;
      char *s;
      static int cntsql = 0;
      char cname[256];
      char tmpvar[256];
      struct BINDING ibind[] = {
	{&tmpvar, 0, 255}
      };			/* end of binding */
      sprintf (cname, "chkin_%d", cntsql++);

      s = char_pop ();
      get_top_of_stack (1, &d1, &s1, (void **) &ptr1);
      A4GLSQL_set_sqlca_sqlcode (0);
      {
	int n;
	struct BINDING *ibind;
	struct BINDING obind[] = { {0, 0, 0} };	/* end of binding */
	ibind = pop_binding (&n);
	A4GLSQL_declare_cursor (0,
				A4GLSQL_prepare_select (ibind, n, obind, 0,
							s), 0, cname);
      }
      if (status != 0)
	{
	  drop_param ();
	  push_int (0);
	}
      A4GLSQL_set_sqlca_sqlcode (0);
      A4GLSQL_open_cursor (0, cname);
      if (status != 0)
	{
	  drop_param ();
	  push_int (0);
	}
      while (1)
	{
	  A4GLSQL_fetch_cursor (cname, 2, 1, 1, ibind);
	  if (status != 0)
	    break;
	  debug ("MJA tmpvar=%s\n", tmpvar);
	  push_param (tmpvar, 0);
	  push_param ((void *) ptr1, (d1 & DTYPE_MASK) + ENCODE_SIZE (s1));
	  pushop (OP_EQUAL);
	  eql = pop_int ();
	  if (eql)
	    ok = 1;
	  a--;
	}
      drop_param ();		/* Get rid of the base */
      if (d == OP_IN_SELECT)
	push_int (ok);
      else
	push_int (!ok);
      return;
    }

  if (d == OP_EXISTS || d == OP_NOTEXISTS)
    {
      int ok = 0;
      char *s;
      char tmpvar[256];
      static int cntsql = 0;
      char cname[256];

      struct BINDING ibind[] = { {&tmpvar, 0, 255} };	/* end of binding */
      struct BINDING obind[] = { {0, 0, 0} };			/* end of binding */
      struct BINDING *dbind;
      void *prep;

      int n;

      debug("OP_EXISTS - OP_NOTEXISTS...");
      sprintf (cname, "chkex%d", cntsql++);
	debug("Popping binding...");

      dbind = pop_binding (&n);
      debug("poped dbind - Poping Sql");
      s = char_pop ();
      debug ("s=%s\n", s);
      A4GLSQL_set_sqlca_sqlcode (0);
      debug("Prepare seelct...");
      prep=A4GLSQL_prepare_select (dbind, n, obind, 0, s);
      debug("Declare");
      A4GLSQL_declare_cursor (0,  prep , 0, cname);

      if (status != 0)
	{
	  push_int (0);
	  return;
	}
      A4GLSQL_set_sqlca_sqlcode (0);
      A4GLSQL_open_cursor (0, cname);
      debug ("opened cursor");
      if (status != 0)
	{
	  push_int (0);
	  return;
	}
      A4GLSQL_fetch_cursor (cname, 2, 1, 1, ibind);
      debug ("fetched");
      if (status == 0)
	ok = 1;
      if (status == 100)
	ok = 0;
      if (status != 0 && status != 100)
	{
	  debug ("Some error with the exists stuff.");
	  push_int (0);
	  return;
	}
      debug ("ok=%d", ok);
      if (d == OP_EXISTS)
	push_int (ok);
      else
	push_int (!ok);
      return;
    }

  if (d & NUMERIC_OP_2)
    {

	debug("OP_NUMERIC...");

      if (chknull (2, n1, n2))
	return;
      /* void get_top_of_stack (int a, int *d, int *s, void **ptr); */
      get_top_of_stack (1, &d1, &s1, (void **) &ptr1);
      get_top_of_stack (2, &d2, &s2, (void **) &ptr2);
      if (d1 != DTYPE_INTERVAL || d1 != DTYPE_DTIME || d2 != DTYPE_INTERVAL
	  || d2 != DTYPE_DTIME)
	{
	  doublea = pop_double ();
	  doubleb = pop_double ();
	}
      else
	{
	  doing_dt_or_int = 1;
	}
    }

  switch (d)
    {

    case OP_MATCHES:
      if (chknull (2, n1, n2))
	return;
      c2 = char_pop ();
      c1 = char_pop ();

#ifdef DEBUG
	debug ("Check for %s matches %s", c1, c2);
#endif
      push_int (mja_match (c1, c2, 'M'));
      acl_free (c1);
      acl_free (c2);
      break;

    case OP_LIKE:
      if (chknull (2, n1, n2))
	return;
      c2 = char_pop ();
      c1 = char_pop ();
      push_int (mja_match (c1, c2, 'L'));
      acl_free (c1);
      acl_free (c2);
      break;


    case OP_EQUAL:
      if (chknull_boolean (2, n1, n2))
	{
	  return;
	}

      debug ("OP_EQUAL");

      if (opboolean () == 0)
	push_int (1);
      else
	push_int (0);
      break;

    case OP_NOT_EQUAL: 
	debug("Checking OP NOT EQUAL");
      if (chknull_boolean (2, n1, n2))
	return;

      debug ("OP_NOT_EQUAL");
      if (opboolean () == 0) {
	push_int (0);
	}
      else {
	push_int (1);
	}
      break;

    case OP_OR:
      if (chknull (2, n1, n2))
	return;
      debug ("OP_OR");
      i1 = pop_int ();
      i2 = pop_int ();

      /* dumpstack(); */
      debug ("OP_OR : %d %d\n", i1, i2);

      push_int (i1 || i2);
      break;


    case OP_AND:
      if (chknull (2, n1, n2))
	return;
      debug ("OP_AND");
      i1 = pop_int ();
      i2 = pop_int ();
      debug (" OP_AND : %d %d", i1, i2);
      push_int (i1 && i2);
      break;

    case OP_NOT:
      if (chknull (1, n1, n2))
	return;
      debug ("OP_NOT");
      i1 = pop_int ();
      if (i1)
	push_int (0);
      else
	push_int (1);
      break;

    case OP_LESS_THAN:
      if (chknull_boolean (2, n1, n2))
	return;
      if (opboolean () == -1)
	push_int (1);
      else
	push_int (0);
      break;

    case OP_GREATER_THAN:
      if (chknull_boolean (2, n1, n2))
	return;
      if (opboolean () == 1)
	push_int (1);
      else
	push_int (0);
      break;

    case OP_GREATER_THAN_EQ:
      if (chknull_boolean (2, n1, n2))
	return;
      if (opboolean () == -1)
	push_int (0);
      else
	push_int (1);
      break;

    case OP_LESS_THAN_EQ:
      if (chknull_boolean (2, n1, n2))
	return;
      if (opboolean () == 1)
	push_int (0);
      else
	push_int (1);
      break;

    case OP_CONCAT:
      debug ("In concat %d %d", n1, n2);
      /* if (n1) {drop_param (); return;} */
      if (n2 == 1 && n1 == 0)
	{
	  char *s;
	  s = char_pop ();
	  drop_param ();
	  push_char ("");
	  push_char (s);
	  n2 = 0;
	  debug ("Fudging...");
	}

      if (chknull (2, n1, n2))
	return;
      func_concat ();
      break;

    case OP_USING:
      if (chknull (2, n1, n2))
	return;
      func_using ();
      break;

    case OP_CLIP:
      debug ("OP_CLIP");
      if (n1)
	{
	  debug ("Parameter is null..");
	  drop_param ();
	  push_null ();		/*  FIXME FIXME */
	  break;
	}
      func_clip ();
      break;

    case OP_ADD:
      if (chknull (2, n1, n2))
	return;
      push_double (doublea + doubleb);
      break;

    case OP_SUB:
      if (chknull (2, n1, n2))
	return;
      push_double (doubleb - doublea);
      break;

    case OP_MULT:
      if (chknull (2, n1, n2))
	return;
      push_double (doublea * doubleb);
      break;

    case OP_POWER:
      if (chknull (2, n1, n2))
	return;
      push_double (pow(doublea , doubleb));
      break;

    case OP_MOD:
      if (chknull (2, n1, n2))
	return;
      debug ("OP MOD : %f %f\n", doubleb, doublea);
      {
	int a1, a2;
	a1 = (int) doubleb;
	a2 = (int) doublea;
	debug ("a1=%d  a2=%d", a1, a2);
	push_long (a1 % a2);
      }
      break;
    case OP_DIV:
      if (chknull (2, n1, n2))
	return;
      push_double (doubleb / doublea);
      break;

    case OP_YEAR:
    case OP_MONTH:
    case OP_DAY:
    case OP_HOUR:
    case OP_MINUTE:
    case OP_SECOND:
			/** @todo Confirm if the return was needed */
      /* return conv_to_interval (d); */
      conv_to_interval (d);
      break;			/* just to be sure! */
    }
}

/**
 *
 *
 * @return
 */
void
push_user (void)
{
  int a;
  struct passwd *p;
#ifndef __MINGW32__
  a = getuid ();
  p = getpwuid (a);
#endif
  //printf ("User=%s\n", p->pw_name);
  push_char (p->pw_name);
}

/**
 *
 *
 * @return
 */
void
push_ascii () 
{
int a;
  char buff[3];
  a=pop_int();
  buff[0] = a;
  buff[1] = 0;
  push_char (buff);
}


/**
 *
 *
 * @return
 */
void
push_today (void)
{
  long z;
  int mja_day;
  struct tm *local_time;
  time_t now;
  int month, year;		/* ch, yflag; */

	/*      setlocale(LC_ALL,""); */
  (void) time (&now);
  local_time = localtime (&now);
  year = local_time->tm_year + 1900;
  month = local_time->tm_mon + 1;
  mja_day = local_time->tm_mday;

  z = gen_dateno (mja_day, month, year);

#ifdef DEBUG
  debug ("Here....%ld %d %d %d", z, mja_day, month, year);
#endif
  push_date (z);
}

/**
 *
 *
 * @return
 */
void
push_current (int a, int b)
{
  int mja_day;
  struct tm *local_time;
  time_t now;
  int month, year;		/* ch, yflag; */
  char buff[50];
  char buff2[50];
  int n;
int ptrs[]={-1, 0, 5, 8, 11, 14, 17, 20,21,22,23,24,25 };
int ptrs2[]={-1, 3, 6, 9, 12, 15, 18, 21,22,23,24,25,26 };
int pstart;


  debug("push_current %d %d\n",a,b);
/*  setlocale(LC_ALL,""); */
  debug ("In push_current");
  (void) time (&now);
  debug ("Called time...");
  local_time = localtime (&now);
  debug ("Got local time");
  year = local_time->tm_year + 1900;
  month = local_time->tm_mon + 1;
  mja_day = local_time->tm_mday;
/*
       0000000000111111111122222
       0123456789012345678901234
       YYYY-MM-DD hh:mm:ss.fffff
*/
  sprintf (buff, "%04d-%02d-%02d %02d:%02d:%02d.%d000000000000",
	   year, month, mja_day, local_time->tm_hour,
	   local_time->tm_min, local_time->tm_sec, local_time->tm_sec	/* , 0 */
	   /* no support for fractions of a second yet */
    );
  debug ("Time is %s", buff);

  debug ("a=%d b=%d ",a,b);
  pstart=ptrs2[b]+1;
  debug("pstart=%d buff=%s\n",pstart,buff);
  buff[pstart]=0;

debug("Set buff to %s\n",buff);
  strcpy (buff2, &buff[ptrs[a]]);
debug("Set buff2 to %s\n",buff2);

  n=(a<<4)+b;

  debug("push_current -Pushing %s - n = %d (%x)",buff2,n,n);
  acli_datetime(buff2,n);
  debug ("All done - push_current...");
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
  sprintf (buff, "%d",local_time->tm_sec);
  debug ("Time is %s", buff);
	return local_time->tm_sec;
}
*/



/**
 *
 *
 * @return
 */
void
push_time (void)
{
  struct tm *local_time;
  time_t now;
  char buff[20];
/* setlocale(LC_ALL,""); */
  debug ("In push_time");
  (void) time (&now);
  debug ("Called time...");
  local_time = localtime (&now);
  debug ("Got local time");
  sprintf (buff, "%02d:%02d:%02d",
	   local_time->tm_hour, local_time->tm_min, local_time->tm_sec);
  debug ("Time is %s", buff);
  push_char (buff);
}


/**
 *
 *
 * @return
 */
void
pushop (int a)
{
  debug("PUSHOP : %d",a);
	if (
		a==OP_IN||a==OP_NOTIN
		||a == OP_IN_SELECT || a == OP_NOTIN_SELECT
		||a == OP_EXISTS || a == OP_NOTEXISTS) {
			process_stack_op_other(a);
		return;
	}

  push_param (0, a);
}


/**
 *
 *
 * @return
 */
int
opboolean (void)
{
  int d1, d2;
  char *z1;
  char *z2;
  double a, b;
  int cmp;
  int adate;
  d1 = params[params_cnt - 1].dtype & DTYPE_MASK;
  d2 = params[params_cnt - 2].dtype & DTYPE_MASK;

#ifdef DEBUG
  debug ("compare Data types %d %d \n", d1, d2);
#endif
  if (d1 == d2 || (d1 != d2 && d1 != 0 && d2 != 0))
    {
      if (d1 == 0 && d2 == 0)
	{
	  z1 = char_pop ();
	  trim (z1);
	  z2 = char_pop ();
	  trim (z2);
#ifdef DEBUG
	  /* {DEBUG} */ debug ("String Compare : '%s' and '%s'", z1, z2);
	  /* {DEBUG} */ debug (" = %d\n", strcmp (z1, z2));
#endif
	  cmp = strcmp (z1, z2) * -1;
	  if (cmp < 0)
	    cmp = -1;
	  if (cmp > 0)
	    cmp = 1;
	  acl_free (z1);
	  acl_free (z2);
	  debug ("String compare gives %d\n", cmp);
	  return cmp;
	}
      else
	{
	  a = pop_double ();
	  b = pop_double ();
#ifdef DEBUG
	  debug ("check %lf %lf", a, b);
#endif
	  if (b > a)
	    {
	      return 1;
	    }
	  if (b < a)
	    {
	      return -1;
	    }
	  debug ("Equal");
	  return 0;
	}
    }

  /* comparison of char to number/date */

#ifdef DEBUG
  /* {DEBUG} */ debug ("Dont know how to compare a %d to a %d\n", d1, d2);
#endif

  if (d1 == 0)
    {
      debug ("First is string");
      z1 = char_pop ();
      a = pop_double ();
      b = atof (z1);
      debug ("1 --> %s %lf", z1, a);
    }
  else
    {
      debug ("second is string");
      a = pop_double ();
      z1 = char_pop ();
      b = atof (z1);
      debug ("2 --> %s %lf", z1, a);
    }

  if (stod (z1, &adate, 0) == 1)
    {
      debug ("String is a date...");
      b = (double) adate;

    }

  acl_free (z1);

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
pop_args (int a)
{
  char *s = 0;
  int z = 0;
  if (z > 0)
    {
      for (z = 0; z < a; z++)
	s = char_pop ();

      acl_free (s);
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
debug_print_stack (void)
{
  int a;
  char *buff;
  buff = new_string (2000);
#ifdef DEBUG
  debug ("\n");
#endif
#ifdef DEBUG
  debug ("**************************************************************\n");
#endif
#ifdef DEBUG
  /* {DEBUG} */ debug ("Call stack has %d entries:\n", params_cnt);
#endif
  for (a = 0; a < params_cnt; a++)
    {
      conv (params[a].dtype & DTYPE_MASK, params[a].ptr, 0, buff, 20);
#ifdef DEBUG
      /* {DEBUG} */ debug (" %d Dtype (%d)='%s' size=%d\n", a,
			   params[a].dtype & DTYPE_MASK, buff,
			   params[a].size);
#endif
    }
#ifdef DEBUG
  debug ("**************************************************************\n");
#endif
}


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
  buff = new_string (20);
  printf ("\n\n\n\n\n\n\n\n\n");
  printf ("Call stack has %d entries:\n", params_cnt);
  for (a = 0; a < params_cnt; a++)
    {
      conv (params[a].dtype & DTYPE_MASK, params[a].ptr, 0, buff, 8);
      /* int conv (int dtype1, void *p1, int dtype2, void *p2, int size); */
      printf (" %d Dtype (%d) %s\n", a, params[a].dtype & DTYPE_MASK, buff);
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
      z = strdup ("");
    }

  debug ("Adding '%s' to '%s'", s, z);
  ptr = strdup (z);

  l = strlen (z) + strlen (s) + 1;

  debug ("New size=%d", l);

  z = (char *) realloc (z, l);
  strcpy (z, ptr);
  strcat (z, s);

  free (ptr);
  debug ("z=%s", z);

  return z;
}

/**
 *
 *
 * @return
 */
char *
params_on_stack (char *_paramnames[], int n)
{
  int a;
  char *buff;
  char *buff2;
  char *z = 0;
  int sz;

  if (n == 0)
    return 0;

  debug ("Generating parameter list n=%d", n);

  for (a = 0; a < n; a++)
    {

      if ((params[a].dtype & DTYPE_MASK) != 0)
	{
	  sz = 20;
	  debug ("not char - sz=30");
	}
      else
	{
	  sz = params[a].size;
	  debug ("char - sz=%d", sz);
	}

      buff = malloc (sz + 1);
      debug ("Calling conv...");

      conv (params[a].dtype & DTYPE_MASK, params[a].ptr, 0, buff, sz);


      debug ("Conv gives us '%s'", buff);

      buff2 = buff;
      buff2 = lrtrim (buff);

      if (a)
	{
	  z = add_to_z (z, ",");
	}

      debug ("1. z=%s", z);
      z = add_to_z (z, _paramnames[a]);

      debug ("2. z=%s", z);
      z = add_to_z (z, "=");
      debug ("3. z=%s", z);
      z = add_to_z (z, buff2);
      debug ("4. z=%s", z);

      free (buff);
    }
  debug ("Generated : %s", z);
  return z;
}

/**
 *
 *
 * @return
 */
void
push_bind (struct BINDING *b, int n, int no, int elemsize)
{
  int a;
#ifdef DEBUG
  /* {DEBUG} */ debug ("push_bind");
#endif
  for (a = n - 1; a >= 0; a--)
    {
#ifdef DEBUG
      /* {DEBUG} */ debug ("Push param %d -> %p %lx", a, b[a].ptr,
			   b[a].dtype + ENCODE_SIZE (b[a].size));
#endif
      push_param ((char *) b[a].ptr + elemsize * (no - 1), b[a].dtype);
    }
}


/**
 *
 *
 * @return
 */
void
push_disp_bind (struct BINDING *b, int n)
{
  int a;
#ifdef DEBUG
  /* {DEBUG} */ debug ("push_disp_bind");
#endif
  for (a = 0; a < n; a++)
    {
#ifdef DEBUG
      /* {DEBUG} */ debug ("Push param %d -> %p %lx", a, b[a].ptr,
			   b[a].dtype + ENCODE_SIZE (b[a].size));
#endif
      push_param ((char *) b[a].ptr, b[a].dtype + ENCODE_SIZE (b[a].size));
    }
}


/**
 *
 *
 * @return
 */
int
chk_params (struct BINDING *b, int nb, struct BINDING *o, int no)
{
  int i;
  int ca, cb;
  char *mptr[2048];


  for (ca = 0; ca < no; ca++)
    {
#ifdef DEBUG
      /* {DEBUG} */ debug ("ca=%d", ca);
#endif
      for (cb = 0; cb < nb; cb++)
	{
#ifdef DEBUG
	  /* {DEBUG} */ debug ("   cb=%d", cb);
#endif
	  if (b[cb].ptr == o[ca].ptr)
	    {
#ifdef DEBUG
	      /* {DEBUG} */ debug ("   pointers %d %d are equal", cb, ca);
#endif
	      /* check value in o.ptr against that on the stack */
#ifdef DEBUG
	      /* {DEBUG} */ debug ("nb=%d cb=%d ca=%d\n", nb, cb, ca);
#endif
	      read_param (mptr, b[cb].dtype, b[cb].size, nb - cb);
#ifdef DEBUG
	      /* {DEBUG} */
	      debug
		("   pushing last data-------------------------------------------------");
#endif
	      push_param (b[cb].ptr, b[cb].dtype);
#ifdef DEBUG
	      /* {DEBUG} */ debug ("   pushing this data");
#endif
	      push_param (mptr, b[cb].dtype);
#ifdef DEBUG
	      /* {DEBUG} */
	      debug
		("   checking for equallity--------------------------------------------");
#endif
	      pushop (OP_EQUAL);
	      i = pop_bool ();
#ifdef DEBUG
	      /* {DEBUG} */ debug ("   i=%d", i);
#endif
	      if (i == 0)
		{
#ifdef DEBUG
		  /* {DEBUG} */
		  debug ("Param %d has changed in order by binding", ca);
#endif
		  return ca + 1;
		}
	    }
	}
    }
#ifdef DEBUG
  /* {DEBUG} */ debug ("No change");
#endif
  return -1;
}


/**
 *
 *
 * @return
 */
int
read_param (void *p, int d, int size, int c)
{
  int b;
//  char *ptr;
#ifdef DEBUG
  /* {DEBUG} */ debug ("Stack pointer=%d c=%d", params_cnt, c);
  /* {DEBUG} */ debug ("read param pointer =%p datatype=%x size=%d count=%d",
		       p, d, size, c);
#endif
  b = conv (params[params_cnt - c].dtype & DTYPE_MASK,
	    params[params_cnt - c].ptr, d & DTYPE_MASK, p, size);
  return b;
}

/**
 *
 *
 * @return
 */
void
upshift_stk (void)
{
  char *ptr;
  ptr = char_pop ();
  convupper (ptr);
  push_char (ptr);
  acl_free (ptr);
}

/**
 *
 *
 * @return
 */
void
downshift_stk (void)
{
  char *ptr;
  ptr = char_pop ();
  convlower (ptr);
  push_char (ptr);
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

int				//should be boll
isparamdate (void)
{
  if ((params[params_cnt - 1].dtype) & (DTYPE_MASK == DTYPE_DATE))
    return TRUE;
  return FALSE;
}


/**
 * Assign an aubit 4gl variable with a value that marks it as null.
 *
 * @param type The data type of the variable.
 * @param buff A pointer to the buffer where the variable is located.
 * @param size The size of the variable in bytes.
 */
void
setnull (int type, char *buff, int size)
{
  int a;
  char c;
  debug ("Set null");

  if (has_datatype_function_i (type, "INIT"))
    {
      void (*function) (char *);
	debug("Calling INIT for datatype");
      function = get_datatype_function_i (type, "INIT");
      function (buff);
      return;
    }

  if (type == DTYPE_BYTE || type == DTYPE_TEXT)
    {
      struct fgl_int_loc *ptr;
      ptr = (struct fgl_int_loc *) buff;
      if (ptr->where == 'M')
	{
	  free (ptr->ptr);
	  ptr->ptr = 0;
	}
      ptr->where = 'N';
      return;
    }
  if (type == DTYPE_DTIME)
    {
      struct a4gl_dtime *i;
      i = (struct a4gl_dtime *) buff;
      i->data[0] = 0;
      return;
    }

  if (type == DTYPE_INTERVAL)
    {
      struct ival *i;
      i = (struct ival *) buff;
      i->data[0] = 0;
      return;
    }

  for (a = 0; a < 9; a++)
    {
      c = nset[type & DTYPE_MASK][a];
      if (UC (c) != UC (IGN))
	{
	  debug ("Setting byte %d to %d", a, c);
	  buff[a] = c;
	}
    }

  if (!(isnull (type, buff)))
    {
      debug ("Opps");
      exitwith ("Could not initialize variable to null");
    }
    if (type==0) {
		debug("Set buff to %s\n",buff);
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
isnull (int type, char *buff)
{
  int a;
  type = type & DTYPE_MASK;

  //debug ("ISNULL - %d %p\n", type, buff);

  if (has_datatype_function_i (type, "ISNULL"))
    {
      int (*function) (char *);
	debug("Calling ISNULL for datatype");
      function = get_datatype_function_i (type, "ISNULL");
      return function (buff);
    }


  if (type == DTYPE_BYTE || type == DTYPE_TEXT)
    {
      struct fgl_int_loc *ptr;
      ptr = (struct fgl_int_loc *) buff;
      return ptr->where == 'N';
    }
  if (type == DTYPE_DTIME)
    {
      struct a4gl_dtime *i;
      i = (struct a4gl_dtime *) buff;
      if (i->data[0] == 0)
	return 1;
      else
	return 0;
    }

  if (type == DTYPE_CHAR)
    {
      if (buff[0] == 0)
	return 1;
      else
	return 0;
    }

  if (type == DTYPE_INTERVAL)
    {
      struct ival *i;
      i = (struct ival *) buff;
      if (i->data[0] == 0)
	return 1;
      else
	return 0;
    }


  for (a = 0; a < 9; a++)
    {
      if ((unsigned char) (nset[type][a]) != (unsigned char) IGN)
	{
	  if ((unsigned char) (buff[a]) != (unsigned char) (nset[type][a]))
	    {
	      return 0;
	    }
	}
    }
  return 1;
}





/**
 *
 *
 * @return
 */
void
locate_var (struct fgl_int_loc *p, char where, char *filename)
{

  debug ("locate_var p=%p %c", p, p->where);

  if (p->where == 'M' && p->ptr > 0)
    {
      debug ("Freeing\n");
      //free(p->ptr); //bugger...
    }

  init_blob (p);

  debug ("inited");

  p->ptr = 0;
  p->memsize = -1;

  if (where == 'M')
    {
      debug ("Locating blob in memory");
      p->where = 'M';
      p->filename[0] = 0;
    }
  else
    {
      debug ("Locating blob in file %s", filename);
      p->where = 'F';
      strcpy (p->filename, filename);
      trim (p->filename);
    }
  debug ("Located at %c %s", p->where, p->filename);
}


/**
 *
 *
 * @return
 */
void
init_blob (struct fgl_int_loc *p)
{
  debug ("Init blob\n");
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
push_null (void)
{
  static int a = 0;
  debug ("** Pushing null");
  if (a == 0)
    setnull (2, (char *) &a, 0);
  push_long (a);
}


/**
 *
 *
 * @return
 */
int
chknull (int n, int n1, int n2)
{
  debug ("CHecking first %d of %d %d", n, n1, n2);

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
      drop_param ();
      drop_param ();
      debug ("Dropped 2");
      push_null ();
      debug ("Pushed null");
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
drop_param (void)
{
  char buff[80];
  pop_char (buff, 1);
}


/**
 *
 *
 * @return
 */
void
set_init (struct BINDING *b, int n, int no)
{
  int a;
  for (a = 0; a < n; a++)
    {
      setnull (b[a].dtype, (char *) b[a].ptr, b[a].size);
    }
}


/**
 *
 *
 * @return
 */
void
get_top_of_stack (int a, int *d, int *s, void **ptr)
{
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
chknull_boolean (int n, int n1, int n2)
{
  if (n == 2 && (n1 || n2))
    {
      drop_param ();
      drop_param ();
      push_int (0);
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
conv_to_interval (int a)
{
  double d;
  struct ival i;
  char buff[256];

  debug ("Conv to interval - %d\n", a);
  d = pop_double ();
  debug ("Got d as %lf\n", d);
  switch (a)
    {
    case (OP_YEAR):
      sprintf (buff, "%d-00", (int) d);
      break;
    case (OP_MONTH):
      sprintf (buff, "0000-%d", (int) d);
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
    }
  debug ("D now set to %lf", d);
  debug ("a=%d %d %d %d\n", a, OP_YEAR, OP_MONTH, OP_HOUR);

  // d will now be a number of years or a number of seconds.
  if ((a == (OP_YEAR)) || (a == (OP_MONTH)))
    {
      debug ("%d %d", (a == (OP_YEAR)), (a == (OP_MONTH)));
	debug("Calling acli_interval for year to month");
      acli_interval(buff,1042); // YEAR(4) TO MONTH
    }
  else
    {
      sprintf (buff, "%f", d);
	debug("Calling acli_interval for second to fraction");
      acli_interval(buff,0x46b); // SECOND(4) TO FRACTION(5)
	debug("Done acli_interval second to fraction MJA...");
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
push_binding (void *ptr, int num)
{
//int n;

  if (local_binding_cnt >= LOCAL_BINDINGS)
    {
      exitwith ("Too many bindings");
      return 0;
    }
  debug ("MJA - Adding binding to %p", ptr);

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
  debug ("STarting bind");
  list = malloc (sizeof (struct bound_list));
  list->ptr = 0;
  list->cnt = 0;
  list->popped = -1;
  return (void *)list;
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
  z = malloc (sizeof (int));
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
  int *z;
  z = malloc (sizeof (int));
  *z = a;
  dif_add_bind (list, z, DTYPE_SMINT, 0);
}

/**
 *
 *
 * @return
 */
void
dif_add_bind_smint_ptr (struct bound_list *list, int *a)
{
  //printf ("a=%p", a);
  //printf ("*a=%x\n", *a);
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
  //printf ("a=%p", a);
  //printf ("*a=%f\n", *a);
  dif_add_bind (list, a, DTYPE_SMINT, 0);
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
  z = malloc (sizeof (long));
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
  z = malloc (sizeof (double));
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
  z = malloc (sizeof (int));
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
  z = strdup (a);
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
  debug ("free bind");
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
  debug ("get bind");
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
      debug ("%p(%x) %d %d\n",
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
  return (int) list->ptr[list->popped].ptr;
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
  return (int) list->ptr[list->popped].ptr;
}


/**
 *
 *
 * @return
 */
char *
lrtrim (char *z)
{
  static char rstr[2000];
  int a;
  strcpy (rstr, "");
  debug ("COpied");

  for (a = 0; a < strlen (z); a++)
    {
      if (z[a] != ' ')
	{
	  strcpy (rstr, &z[a]);
	  break;
	}
    }
  debug ("Searched..");

  trim (rstr);
  debug ("lrtrim : All done - returning '%s'", rstr);
  return rstr;
}


// ================================ EOF ================================
