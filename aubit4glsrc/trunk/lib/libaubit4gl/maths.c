/*
*
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
# $Id: maths.c,v 1.2 2002-05-23 16:01:15 mikeaubury Exp $
#
*/

/**
 * @file
 * Extensible Maths library
 *
 *
 */
#include "a4gl_stack.h"
#include "a4gl_dtypes.h"
#include "a4gl_debug.h"



struct s_math {
	int op;
	void *function;
	struct s_math *next;
};

static int inited=0;


struct s_math *arr_math[MAX_DTYPE][MAX_DTYPE];

//
// How many parameters are we expecting for these ?
//
static int nparam_op(int op) {
	switch (op) {
	case OP_NOT:
	case OP_ISNOTNULL:
	case OP_ISNULL: 
	    return 1;

	case OP_CONCAT:
	case OP_EQUAL:
	case OP_NOT_EQUAL:
	case OP_OR:
	case OP_AND:
	case OP_LESS_THAN:
	case OP_GREATER_THAN:
	case OP_GREATER_THAN_EQ:
	case OP_LESS_THAN_EQ:
	case OP_LIKE:
	case OP_USING:
	case OP_CLIP:
	case OP_MATCHES:  
	case OP_ADD:
	case OP_SUB:
	case OP_MULT:
	case OP_MOD:
	case OP_DIV: 
	case OP_POWER: 
			return 2;
}

return -1;
}

void init_arr_math() {
int a,b;
if (inited==0) {
inited=1;
for (a=0;a<MAX_DTYPE;a++) {
	for (b=0;b<MAX_DTYPE;b++) {
		arr_math[a][b]=0;
	}
}
}
}


void add_op_function(int dtype1,int dtype2,int op,void *function) {
	struct s_math *ptr_orig;
	struct s_math *ptr_new;

	debug("Adding %x function for %d,%d (%p)",op,dtype1,dtype2,function);

	if (inited==0) init_arr_math();

	if (nparam_op(op)==0) {
		dtype1=0;
		dtype2=0;
	}

	if (nparam_op(op)==1) dtype2=dtype1;


	ptr_orig=arr_math[dtype1][dtype2];

	ptr_new=malloc(sizeof(struct s_math));
	ptr_new->op=op;
	ptr_new->function=function;
	ptr_new->next=0;

	if (ptr_orig==0) {
		arr_math[dtype1][dtype2]=ptr_new;
	} else {
		while (ptr_orig->next!=0) ptr_orig=ptr_orig->next;
		ptr_orig->next=ptr_new;
	}
}



void *find_op_function(int dtype1,int dtype2,int op) {
	struct s_math *ptr_orig;
	if (inited==0) init_arr_math();

	dtype1=dtype1&DTYPE_MASK;
	dtype2=dtype2&DTYPE_MASK;

	debug("Looking for something that will %x %d %d",op,dtype1,dtype2);

	if (nparam_op(op)==0) {
		dtype1=0;
		dtype2=0;
	}

	if (nparam_op(op)==1) dtype2=dtype1;

	ptr_orig=arr_math[dtype1][dtype2];

	if (ptr_orig==0) {
		debug("No ptr_orig - so no...");
		return 0;
	}

	while (ptr_orig!=0) {
		if (ptr_orig->op==op) {
			debug("Got it -> %p",ptr_orig->function);
			return ptr_orig->function;
		}
		ptr_orig=ptr_orig->next;
	}
	debug("Nope - use standard");
	return 0;

}

