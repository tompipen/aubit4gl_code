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
# $Id: dynmem.c,v 1.12 2010-10-06 13:16:43 mikeaubury Exp $
#
*/

#include "a4gl_libaubit4gl_int.h"


struct s_dyn_allocation
{
  int dims[5];
  int total_mem;
  void *var_ptr;
  void *mem_ptr;
};

/*

void *A4GL_alloc_dynarr(void *var_ptr, void *old_ptr,int dim1,int dim2,int dim3,int dim4,int dim5,int total_bytes,int isRealloc)  ;
void A4GL_dynarr_free(void *var_ptr,void *old_ptr);
void A4GL_isdynarr_allocated(void *var_ptr);
void A4GL_dynarr_extent(void *var_ptr,int dim) ;
*/


static char *
dyn_ptr_name (void *var_ptr)
{
  static char buff[128];
  SPRINTF1 (buff, "%p", var_ptr);
  return buff;
}

/*
Allocate a dynamic array...
	var_ptr	    = pointer to variable
	old_ptr     = old value
	dim1..dim5  = dimensions
	total_bytes = total amount of memory requested..
	isRealloc   = resize old memory  (1=normal REALLOC, 2 = appendelement (dont care if it didn't exist - create it)
*/
void *
A4GL_alloc_dynarr (void *var_ptr, void *old_ptr, int dim1, int dim2, int dim3, int dim4, int dim5, int total_bytes, int isRealloc)
{
  void *newPtr;
  struct s_dyn_allocation *a = 0;
  int has_old = 0;

  if (A4GL_has_pointer (dyn_ptr_name (var_ptr), DYNMEMALLOC))
    {
      a = A4GL_find_pointer (dyn_ptr_name (var_ptr), DYNMEMALLOC);
      has_old = 1;
    }
  else
    {
      a = acl_malloc2 (sizeof (struct s_dyn_allocation));
      A4GL_add_pointer (dyn_ptr_name (var_ptr), DYNMEMALLOC, a);
      has_old = 0;
    }

  if (isRealloc==1 && has_old == 0)
    {
      if (a)
	free (a);
      A4GL_del_pointer (dyn_ptr_name (var_ptr), DYNMEMALLOC);
      A4GL_exitwith ("Can't resize a non-allocated dynamic array");
      return 0;
    }

  if (isRealloc == 0 && has_old == 1)
    {
      free (old_ptr);
    }



  if (isRealloc)
    {
      newPtr = realloc (old_ptr, total_bytes);
    }
  else
    {
      newPtr = acl_malloc2 (total_bytes);
    }
  a->dims[1] = dim1;
  a->dims[2] = dim2;
  a->dims[3] = dim3;
  a->dims[4] = dim4;
  //a->dims[5] = dim5;
  //
  //printf("%d %d %d totalbytes=%d\n", dim1,dim2,dim3, total_bytes);

  a->total_mem = total_bytes;
  a->var_ptr = var_ptr;
  a->mem_ptr = newPtr;

  return newPtr;
}


void
A4GL_dynarr_free (void *var_ptr, void *old_ptr)
{
  struct s_dyn_allocation *a;

  if (A4GL_has_pointer (dyn_ptr_name (var_ptr), DYNMEMALLOC))
    {
      a = A4GL_find_pointer (dyn_ptr_name (var_ptr), DYNMEMALLOC);
    }
  else
    {
      A4GL_exitwith ("Dynamic Array has not been allocated or has already been freed");
    }
  A4GL_del_pointer (dyn_ptr_name (var_ptr), DYNMEMALLOC);
  free (old_ptr);
}

void
A4GL_isdynarr_allocated (void *var_ptr)
{
  if (A4GL_has_pointer (dyn_ptr_name (var_ptr), DYNMEMALLOC))
    A4GL_push_int (1);
  else
    A4GL_push_int (0);
}

void
A4GL_dynarr_extent (void *var_ptr, int dim)
{
  struct s_dyn_allocation *a;
  if (!A4GL_has_pointer (dyn_ptr_name (var_ptr), DYNMEMALLOC))
    {
      A4GL_push_int (0);
      return;
    }
  a = A4GL_find_pointer (dyn_ptr_name (var_ptr), DYNMEMALLOC);
  if (!a)
    {
      A4GL_push_int (0);
      return;
    }
  if (dim >= 1 && dim <= 5)
    {
      A4GL_push_long (a->dims[dim]);
      return;
    }
  A4GL_push_int (0);
}

void
A4GL_push_dynamic_array (void *p, int sz)
{
  A4GL_assertion (1, "passing dynamic arrays is not implemented yet");
}






struct s_arr {
	void **ptr;
	int size;
	int d1;
	int d2;
	int d3;
};



// This function converts from a A4GL_call_dynarr_function_i_as_int to a A4GL_call_datatype_function_i_as_int
// by creating a "struct s_arr" to pass in instead.
// this holds the unit size of the array elements - and the dimension we're applying it to...
//

int A4GL_call_dynarr_function_i_as_int(void *arr, int d1,int d2,int d3, int sz,char *func,int nparam) {
	struct s_arr arr_ptr;
	arr_ptr.ptr=arr;
	arr_ptr.size=sz;
	arr_ptr.d1=d1;
	arr_ptr.d2=d2;
	arr_ptr.d3=d3;
	return A4GL_call_datatype_function_i_as_int(&arr_ptr,DTYPE_DYNAMIC_ARRAY,func,nparam);
}

int A4GL_call_dynarr_function_i(void *arr, int d1,int d2,int d3, int sz,char *func,int nparam) {
	struct s_arr arr_ptr;
	arr_ptr.ptr=arr;
	arr_ptr.size=sz;
	//if (d1==0) d1=1;
	//if (d2==0) d2=1;
	//if (d3==0) d3=1;
	arr_ptr.d1=d1;
	arr_ptr.d2=d2;
	arr_ptr.d3=d3;
	return A4GL_call_datatype_function_i(&arr_ptr,DTYPE_DYNAMIC_ARRAY,func,nparam);
}


static int dsize(int a1,int a2,int a3) {
	if (a1==0) a1=1;
	if (a2==0) a2=1;
	if (a3==0) a3=1;
	return a1*a2*a3;
}


static int dynamic_array_appendelement(void *arr, int n) {
	struct s_arr *a;
	void *ptr;
	int d1;
	int d2;
	int d3;
	a=arr;

	A4GL_dynarr_extent (a->ptr, 1); d1=A4GL_pop_long();
	A4GL_dynarr_extent (a->ptr, 2); d2=A4GL_pop_long();
	A4GL_dynarr_extent (a->ptr, 3); d3=A4GL_pop_long();

	if (n==0) {
		d1++;
	} else {
		int l;
		l=A4GL_pop_int();
		switch (l) {
			case 1: d1++;
			case 2: d2++;
			case 3: d3++;
		}
	}

	ptr=A4GL_alloc_dynarr(a->ptr,*a->ptr,d1,d2,d3,0,0,dsize(d1,d2,d3) * a->size,2);
	*a->ptr=ptr;
	return 0;
}


static int dynamic_array_clear(void *arr, int n) {
	struct s_arr *a;
	void *ptr;
	a=arr;


	ptr=A4GL_alloc_dynarr(a->ptr,*a->ptr,0,0,0,0,0,0,2);
	*a->ptr=ptr;
	return 0;
}

static void dynamic_array_deleteelement(void *arr, int n) {
	struct s_arr *a;
	a=arr;

	A4GL_assertion(1,"Not implemented");
}

static void dynamic_array_insertelement(void *arr, int n) {
	struct s_arr *a;
	a=arr;
	
	A4GL_assertion(1,"Not implemented");
}


static int dynamic_array_getlength(void *arr, int n) {
	int p=1;
	struct s_arr *a;
	a=arr;

  	if (n==1) {
		p=A4GL_pop_int();
  	} else {
		if (a->d1>=1) { p=1; }
		if (a->d2>1) { p=2; }
		if (a->d3>1) { p=3; }
	}

  	A4GL_dynarr_extent(a->ptr,p);

	return 1;
}




void add_dyn_support(void) {
	A4GL_add_datatype_function_i (DTYPE_DYNAMIC_ARRAY, ":getlength", (void *) dynamic_array_getlength);
	A4GL_add_datatype_function_i (DTYPE_DYNAMIC_ARRAY, ":appendelement", (void *) dynamic_array_appendelement);
	A4GL_add_datatype_function_i (DTYPE_DYNAMIC_ARRAY, ":insertelement", (void *) dynamic_array_insertelement);
	A4GL_add_datatype_function_i (DTYPE_DYNAMIC_ARRAY, ":deleteelement", (void *) dynamic_array_deleteelement);
	A4GL_add_datatype_function_i (DTYPE_DYNAMIC_ARRAY, ":clear", (void *) dynamic_array_clear);
}


