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
# $Id: rpc_server.c,v 1.8 2002-06-06 12:31:28 afalout Exp $
#*/

/**
 * @file
 *
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
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

#include "a4gl_pointers.h"
#include "a4gl_xdr_rpc_stack.h"
#include "a4gl_aubit_lib.h"
#include "a4gl_incl_4glhdr.h"
#include "a4gl_runtime_tui.h"
#include "a4gl_debug.h"


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

static int call_func(char *s,int a);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 *
 * @todo Describe function
 */
return_values *
call_remote_func_1_svc(call arg,  struct svc_req *rqstp)
{
int a;
int z;
int d,s;
call *arg1;
void *p;
int async=0;
char func_name[64];
static return_values result={0,0};
object_data	 *ptr;
arg1=&arg;
	
	strcpy(func_name,arg1->function_name);
	if (func_name[0]=='!') {
	         strcpy(func_name,&arg1->function_name[1]);
		 async=1;
	}

	debug("%s\n",arg1->function_name);
	debug("%d arguments\n", arg1->parameters.parameters_len);
	for (a=arg1->parameters.parameters_len-1;a>=0;a--) {
		ptr=arg1->parameters.parameters_val;
		debug(" %d Type %d : ",a,ptr[a].dtype);
		switch(arg1->parameters.parameters_val[a].dtype) {
		case 0: push_char(ptr[a].single_dtype_u.chardata); break;
		case 1: push_int(ptr[a].single_dtype_u.shortval); break;
		case 2:
		case 6:
		case 7:
		case 8:	push_long(ptr[a].single_dtype_u.longval); break;
		case 3:	
			debug("RPC Double:%lf",ptr[a].single_dtype_u.floatval);
			push_double(ptr[a].single_dtype_u.floatval);
			 break;
		case 4:	push_float(ptr[a].single_dtype_u.smfltval); break;
		default:  exitwith("Unprintable datatype");return 0;
		}
	}


	if (async==1) {
		result.return_values_len=1;
		result.return_values_val=malloc(sizeof(object_data)*1);
		result.return_values_val[0].dtype=2;
		result.return_values_val[0].single_dtype_u.longval=0;
	        
        exitwith ("serious bug in rpc_server.c");

			fgl_rpc_reply((void *)&result); 
			 /*
			 warning: passing arg 1 of `fgl_rpc_reply' from incompatible pointer type

			 so we are passing struct to function expecting char pointer !!!


			 void fgl_rpc_reply(char *result);
             static return_values result={0,0};
             */

			/*
			typedef struct {
				u_int return_values_len;
				object_data *return_values_val;
			} return_values;
			*/



	}


	/************************************************************/

	z=call_func(func_name,arg1->parameters.parameters_len);

	/************************************************************/

	debug("Function returns %d values",z);
	result.return_values_len=z;

        if (result.return_values_val) free(result.return_values_val);

	result.return_values_val=malloc(sizeof(object_data)*z);
	result.return_values_val[0].dtype=2;	
	result.return_values_val[0].single_dtype_u.longval=status;

	for (a=z;a>1;a--) {
		ptr=result.return_values_val;
		get_top_of_stack(1,&d,&s,&p);

		debug("Top of stack return %d %d %p (%d)",d,s,p);
		ptr[a-1].dtype=d&15;

		switch (d&15) {
			case 0: ptr[a-1].single_dtype_u.chardata=(char *)char_pop(); break;
			case 1: ptr[a-1].single_dtype_u.shortval=pop_int();break;
			case 6:
			case 7:
			case 8:
			case 2: ptr[a-1].single_dtype_u.longval=pop_long();break;

			case 3:	ptr[a-1].single_dtype_u.floatval=pop_double();break;
			case 4:	ptr[a-1].single_dtype_u.smfltval=pop_float(); break;
			default :	exitwith("Untransmittable data");
		}
	}

	if (async==1) {
		/* might have returned results but ignore them... */
		result.return_values_len=1;
		return 0;
	}

	return(&result);
}


/**
 * Call a function registred in the pointer tree.
 *
 * @param s The function name to be called.
 * @param a The number of parameters to be passed by the stack.
 * @return 
 *   - 1 : The function was not registered.
 */
static int
call_func(char *s,int a)
{
int z;
int (*func)(int a);
	debug("In call_func");
	if (has_pointer(s,RPC_FUNC)) {
		debug("Function has been registered");
		func=find_pointer(s,RPC_FUNC);
		z=func(a);
		return z+1;
	} else {
		exitwith("Function not registered");
		return 1;
	}
}

/* ============================ EOF ================================= */
