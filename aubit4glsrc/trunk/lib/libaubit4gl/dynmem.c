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
# $Id: dynmem.c,v 1.1 2003-11-26 12:26:50 mikeaubury Exp $
#
*/

#include "a4gl_libaubit4gl_int.h"

struct s_dyn_allocation {
	int dims[5];
	int total_mem;
	void *var_ptr;
	void *mem_ptr;
};


static char *dyn_ptr_name(void *var_ptr)  {
static char buff[128];
sprintf(buff,"%p",var_ptr);
return buff;
}

/*
Allocate a dynamic array...
	var_ptr	    = pointer to variable
	old_ptr     = old value
	dim1..dim5  = dimensions
	total_bytes = total amount of memory requested..
	isRealloc   = resize old memory 
*/
void *A4GL_alloc_dynarr(void *var_ptr, void *old_ptr,int dim1,int dim2,int dim3,int dim4,int dim5,int total_bytes,int isRealloc)  {
void *newPtr;
struct s_dyn_allocation *a=0;
int has_old=0;

	if (A4GL_has_pointer(dyn_ptr_name(var_ptr),DYNMEMALLOC)) {
		a=A4GL_find_pointer(dyn_ptr_name(var_ptr),DYNMEMALLOC);
		has_old=1;
	} else {
		a=malloc(sizeof(struct s_dyn_allocation));
		A4GL_add_pointer(dyn_ptr_name(var_ptr),DYNMEMALLOC,a);
		has_old=0;
	}

	if (isRealloc&&has_old==0) {
		if (a) free(a);
		A4GL_del_pointer(dyn_ptr_name(var_ptr),DYNMEMALLOC);
		A4GL_exitwith("Can't resize a non-allocated dynamic array");
		return 0;
	}

	if (isRealloc==0&&has_old==1) {
		free(old_ptr);
	}



	if (isRealloc) 	{
		newPtr=realloc(old_ptr,total_bytes);
	} else {
		newPtr=malloc(total_bytes);
	}

	a->dims[1]=dim1;
	a->dims[2]=dim2;
	a->dims[3]=dim3;
	a->dims[4]=dim4;
	a->dims[5]=dim5;

	a->total_mem=total_bytes;
	a->var_ptr=var_ptr;
	a->mem_ptr=newPtr;

	return newPtr;
}


void A4GL_dynarr_free(void *var_ptr,void *old_ptr) {
struct s_dyn_allocation *a;

	if (A4GL_has_pointer(dyn_ptr_name(var_ptr),DYNMEMALLOC)) {
		a=A4GL_find_pointer(dyn_ptr_name(var_ptr),DYNMEMALLOC);
	} else {
		A4GL_exitwith("Dynamic Array has not been allocated or has already been freed");
	}
	A4GL_del_pointer(dyn_ptr_name(var_ptr),DYNMEMALLOC);
	free(old_ptr);
}

void A4GL_isdynarr_allocated(void *var_ptr) {
	if (A4GL_has_pointer(dyn_ptr_name(var_ptr),DYNMEMALLOC)) A4GL_push_int(1);
	else A4GL_push_int(0);
}

void A4GL_dynarr_extent(void *var_ptr,int dim) {
struct s_dyn_allocation *a;
	if (!A4GL_has_pointer(dyn_ptr_name(var_ptr),DYNMEMALLOC)) {A4GL_push_int(0);return;}
	a=A4GL_find_pointer(dyn_ptr_name(var_ptr),DYNMEMALLOC);
	if (!a) { A4GL_push_int(0);return; }
	if (dim>=1&&dim<=5) {
		A4GL_push_long(a->dims[dim]);
		return;
	}
	A4GL_push_int(0);
}
