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
# $Id: ops.c,v 1.4 2002-09-20 10:06:04 mikeaubury Exp $
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


#include "a4gl_libaubit4gl_int.h"


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void int_int_ops(int op) ;
#ifdef OLD_INCL
	void push_long(long a);
	void push_int(int a);
#endif
void add_default_operations(void) ;
void dt_in_ops(int op);


/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Add all the default operations to the system
 *
 * @return
 */
void
dt_in_ops(int op)
{
struct a4gl_dtime dt;
struct ival in;
	
	#ifdef DEBUG
		debug("In dt_in_ops");
    #endif
	printf("Here\n");
	pop_param(&in,DTYPE_INTERVAL,-1);
	pop_param(&dt,DTYPE_DTIME,-1);

	push_int(0);
}


/**
 *
 *
 * @return
 */
void
int_int_ops(int op) 
{
long a;
long b;
long c;
long d;
	
	b=pop_long();
	a=pop_long();

    #ifdef DEBUG
		debug("int_int_ops : %d %d %d",a,b,op);
    #endif

	switch (op) {
		case OP_ADD: 			push_long(a+b); return;
		case OP_SUB: 			push_long(a-b); return;
		case OP_MULT: 			push_long(a*b); return;
		case OP_DIV: 			push_long(a/b); return;
		case OP_MOD: 			push_long(a%b); return;
		case OP_POWER:
			if (b==0) {push_long(1); return;}
			if (b==1) {push_long(a); return;}
			c=a;
			for (d=1;d<=b;d++) c*=b;
			push_long(c);
			return;

		case OP_LESS_THAN: 		push_int(a<b); return;
		case OP_GREATER_THAN: 		push_int(a>b); return;
		case OP_LESS_THAN_EQ: 		push_int(a<=b); return;
		case OP_GREATER_THAN_EQ: 	push_int(a>=b); return;
		case OP_EQUAL: 			push_int(a<=b); return;
		case OP_NOT_EQUAL: 		push_int(a!=b); return;
	}

	exitwith("Unknown operation");
	push_int(0);
return ;
}



/**
 *
 *
 * @return
 */
void
add_default_operations(void) 
{


/* Integer functions 
this covers all possibilities of
DTYPE_INT
DTYPE_SMINT
DTYPE_DATE
DTYPE_SERIAL
*/

	add_op_function(DTYPE_INT,	DTYPE_INT,	OP_MATH,int_int_ops);

	add_op_function(DTYPE_SMINT,	DTYPE_SMINT,	OP_MATH,int_int_ops);
	add_op_function(DTYPE_INT,	DTYPE_SMINT,	OP_MATH,int_int_ops);
	add_op_function(DTYPE_SMINT,	DTYPE_INT,	OP_MATH,int_int_ops);

	add_op_function(DTYPE_DATE,	DTYPE_DATE,	OP_MATH,int_int_ops);
	add_op_function(DTYPE_INT,	DTYPE_DATE,	OP_MATH,int_int_ops);
	add_op_function(DTYPE_SMINT,	DTYPE_DATE,	OP_MATH,int_int_ops);
	add_op_function(DTYPE_DATE,	DTYPE_SMINT,	OP_MATH,int_int_ops);
	add_op_function(DTYPE_DATE,	DTYPE_INT,	OP_MATH,int_int_ops);

	add_op_function(DTYPE_SERIAL,	DTYPE_SERIAL,	OP_MATH,int_int_ops);
	add_op_function(DTYPE_SERIAL,	DTYPE_INT,	OP_MATH,int_int_ops);
	add_op_function(DTYPE_SERIAL,	DTYPE_SMINT,	OP_MATH,int_int_ops);
	add_op_function(DTYPE_SERIAL,	DTYPE_DATE,	OP_MATH,int_int_ops);
	add_op_function(DTYPE_INT,	DTYPE_SERIAL,	OP_MATH,int_int_ops);
	add_op_function(DTYPE_SMINT,	DTYPE_SERIAL,	OP_MATH,int_int_ops);
	add_op_function(DTYPE_DATE,	DTYPE_SERIAL,	OP_MATH,int_int_ops);

	/* add_op_function(DTYPE_DTIME,	DTYPE_INTERVAL,	OP_MATH,dt_in_ops); */
	add_op_function(DTYPE_INTERVAL,	DTYPE_DTIME,	OP_MATH,dt_in_ops);


}


/* ========================== EOF ========================== */
