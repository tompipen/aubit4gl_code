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
# $Id: rpc_client.c,v 1.5 2002-05-26 08:43:45 afalout Exp $
#*/

/**
 * @file
 *
 * @todo Add Doxygen comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_xdr_rpc_stack.h"
#include "a4gl_aubit_lib.h"
#include "a4gl_stack.h"
#include "a4gl_runtime_tui.h"		//push_long()
#include "a4gl_incl_4glhdr.h" //pop_int()

#ifdef __CYGWIN__
	#define GETENV_OK
	//On Cygwin, stack.h will eventually include stdlib.h, that will have getenv
	//call. Everywhere else, we should use acl_getenv.
#endif
#include "a4gl_debug.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

extern unsigned long serviceport;

/*
=====================================================================
                    Platform specific definitions
=====================================================================
*/

#ifdef WIN32
	#ifndef __CYGWIN__
		return_values *call_remote_func_1(call *argp, CLIENT *clnt);
	#else
		return_values *call_remote_func_1(call argp, CLIENT *clnt);
	#endif
#else
	return_values *call_remote_func_1(call argp, CLIENT *clnt);
#endif


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

double pop_double(void);
//int push_double(double a);
float pop_float(void);
//int push_float(float a);


/*
=====================================================================
                    Functions definitions
=====================================================================
*/



/**
 *
 * @todo Describe function
 */
int
fgl_rpc_1( char* host,char *func,int np)
{
CLIENT *clnt;
return_values  *result_1={0};
//call  call_remote_func_1_arg1={"0",0,0,0,0}; // warning: missing braces around initializer
call  call_remote_func_1_arg1={"0",{0,0},{0,0}};

/*
struct call {
	char *function_name;
	struct {
		u_int parameters_len;
		object_data *parameters_val;
	} parameters;
	struct {
		u_int sizedata_len;
		long *sizedata_val;
	} sizedata;
};
*/



object_data *ptr;
//double dbl;
int a;
void *p;
int d;
long s;

	clnt = clnt_create(host, FGL_RPC, FGL_RPC_VER, "tcp");

	if (clnt == NULL) {
		debug("Failed to connect to host");
		exitwith("Unable to connect to host");
		return 0;
	}

	debug("Setting up...");

	call_remote_func_1_arg1.function_name=func;
	call_remote_func_1_arg1.parameters.parameters_len=np;
	call_remote_func_1_arg1.sizedata.sizedata_len=np;

	if (call_remote_func_1_arg1.sizedata.sizedata_val)
	       free(call_remote_func_1_arg1.sizedata.sizedata_val);

	if (call_remote_func_1_arg1.parameters.parameters_val)
               free(call_remote_func_1_arg1.parameters.parameters_val);

	call_remote_func_1_arg1.sizedata.sizedata_val=malloc(sizeof(long)*np);
	call_remote_func_1_arg1.parameters.parameters_val=malloc(sizeof(object_data)*np);

	ptr=call_remote_func_1_arg1.parameters.parameters_val;

	for (a=0;a<np;a++) {
		get_top_of_stack(1,&d,(int *)&s,&p); // warning: passing arg 3 of `get_top_of_stack' from incompatible pointer type
            //void get_top_of_stack (int a, int *d, int *s, void **ptr);
		debug("Top of stack return %d %d %p (%d)",d,s,p);

		ptr[a].dtype=d&15;

		call_remote_func_1_arg1.sizedata.sizedata_val[a]=s;

		switch (d&15) {
			case 0: ptr[a].single_dtype_u.chardata=(char *)char_pop(); break;
			case 1: ptr[a].single_dtype_u.shortval=pop_int();break;
			case 6:
			case 7:
			case 8:
			case 2: ptr[a].single_dtype_u.longval=pop_long();break;

			case 3:
				ptr[a].single_dtype_u.floatval=pop_double();
				debug("Sending float %f to RPC", ptr[a].single_dtype_u.floatval);
				break;
			case 4:	ptr[a].single_dtype_u.smfltval=pop_float(); break;
			default :	exitwith("Untransmittable data");
		}
	}
	debug("Before RPC Call");

	#ifdef WIN32
	#ifndef __CYGWIN__
		result_1 = call_remote_func_1(&call_remote_func_1_arg1, clnt);
	#else
		result_1 = call_remote_func_1(call_remote_func_1_arg1, clnt);
	#endif
	#else
		result_1 = call_remote_func_1(call_remote_func_1_arg1, clnt);
	#endif

	debug("Program returns status %d",result_1->return_values_val[0].single_dtype_u.longval);
	debug("Number of returned variables=%d",result_1->return_values_len-1);
	
	debug("After RPC Call");

	if (result_1 == NULL) {
	        exitwith("Call failed");
		return 0;
	}

	for (a=1;a<=result_1->return_values_len-1;a++) {
		ptr=result_1->return_values_val;
		debug(" %d Type %d : ",a,ptr[a].dtype);
		switch(result_1->return_values_val[a].dtype) {
		case 0: push_char(ptr[a].single_dtype_u.chardata); break;
		case 1: push_int(ptr[a].single_dtype_u.shortval); break;
		case 2:
		case 6:
		case 7:
		case 8:	push_long(ptr[a].single_dtype_u.longval); break;
		case 3:	push_double(ptr[a].single_dtype_u.floatval); break;
		case 4:	push_float(ptr[a].single_dtype_u.smfltval); break;
		default:  exitwith("Unprintable datatype");return 0;
		}
	}

	clnt_destroy( clnt );
	return result_1->return_values_len-1;
}

/**
 * Call a remote function using RPC protocol.
 *
 * @param host The host where to call the remote function.
 * @param async
 * @param func The name of the remote function to call.
 * @param port The port number to use when making the call.
 * @param np The number of parameters.
 */
int
remote_func_call(char *host,int async,char *func,int port,int np)
{
  int a;
  char buff[64];
  A4GLSQL_set_status(0,0);
  if (async) {
    strcpy(buff,"!");
    strcat(buff,func);
  }
  else {
    strcpy(buff,func);
  }
  serviceport=port+0x2000000;
  debug("Calling host %s func %s on port %ld with %d entries",
    host,buff,port,np
  );
  a=fgl_rpc_1(host,buff,np);
  return a;
}


// ============================== EOF =================================
