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
# $Id: rpc_client.c,v 1.14 2003-12-18 20:41:46 mikeaubury Exp $
#*/

/**
 * @file
 *
 * @todo Add Doxygen A4GL_comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen A4GL_comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_lib_rpc_xdr_int.h"

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


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

int A4GL_fgl_rpc_1 (char *host, char *func, int np);
//int remote_func_call(char *host,int async,char *func,int port,int np);

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
A4GL_fgl_rpc_1 (char *host, char *func, int np)
{
  CLIENT *clnt;
  return_values *result_1 = { 0 };
  call call_remote_func_1_arg1 = { "0", {0, 0}, {0, 0} };
  object_data *ptr;
  int a;
  void *p;
  int d;
  long s;

  clnt = clnt_create (host, FGL_RPC, FGL_RPC_VER, "tcp");

  if (clnt == NULL)
    {
      A4GL_debug ("Failed to connect to host");
      A4GL_exitwith ("Unable to connect to host");
      return 0;
    }

  A4GL_debug ("Setting up...");

  call_remote_func_1_arg1.function_name = func;
  call_remote_func_1_arg1.parameters.parameters_len = np;
  call_remote_func_1_arg1.sizedata.sizedata_len = np;

  if (call_remote_func_1_arg1.sizedata.sizedata_val)
    free (call_remote_func_1_arg1.sizedata.sizedata_val);

  if (call_remote_func_1_arg1.parameters.parameters_val)
    free (call_remote_func_1_arg1.parameters.parameters_val);

  call_remote_func_1_arg1.sizedata.sizedata_val = malloc (sizeof (long) * np);
  call_remote_func_1_arg1.parameters.parameters_val =
    malloc (sizeof (object_data) * np);

  ptr = call_remote_func_1_arg1.parameters.parameters_val;

  for (a = 0; a < np; a++)
    {
      A4GL_get_top_of_stack (1, &d, (int *) &s, &p);
      A4GL_debug ("Top of stack return %d %d %p (%d)", d, s, p);

      ptr[a].dtype = d & 15;

      call_remote_func_1_arg1.sizedata.sizedata_val[a] = s;

      switch (d & 15)
	{
	case 0:
	  ptr[a].single_dtype_u.chardata = (char *) A4GL_char_pop ();
	  break;
	case 1:
	  ptr[a].single_dtype_u.shortval = A4GL_pop_int ();
	  break;
	case 6:
	case 7:
	case 8:
	case 2:
	  ptr[a].single_dtype_u.longval = A4GL_pop_long ();
	  break;

	case 3:
	  ptr[a].single_dtype_u.floatval = A4GL_pop_double ();
	  A4GL_debug ("Sending float %f to RPC", ptr[a].single_dtype_u.floatval);
	  break;
	case 4:
	  ptr[a].single_dtype_u.smfltval = A4GL_pop_float ();
	  break;
	default:
	  A4GL_exitwith ("Untransmittable data");
	}
    }
  A4GL_debug ("Before RPC Call");

#ifdef WIN32
#ifndef __CYGWIN__
  result_1 = A4GL_call_remote_func_1 (&call_remote_func_1_arg1, clnt);
#else
  result_1 = A4GL_call_remote_func_1 (call_remote_func_1_arg1, clnt);
#endif
#else
  result_1 = A4GL_call_remote_func_1 (call_remote_func_1_arg1, clnt);
#endif

  A4GL_debug ("After RPC Call");

  if (result_1 == NULL)
    {
      A4GL_exitwith ("Call failed");
      return 0;
    }

  A4GL_debug ("Program returns status %d", result_1->return_values_val[0].single_dtype_u.longval);
  A4GL_debug ("Number of returned variables=%d", result_1->return_values_len - 1);

  for (a = 1; a <= result_1->return_values_len - 1; a++)
    {
      ptr = result_1->return_values_val;
      A4GL_debug (" %d Type %d : ", a, ptr[a].dtype);
      switch (result_1->return_values_val[a].dtype)
	{
	case 0:
	  A4GL_push_char (ptr[a].single_dtype_u.chardata);
	  break;
	case 1:
	  A4GL_push_int (ptr[a].single_dtype_u.shortval);
	  break;
	case 2:
	case 6:
	case 7:
	case 8:
	  A4GL_push_long (ptr[a].single_dtype_u.longval);
	  break;
	case 3:
	  A4GL_push_double (ptr[a].single_dtype_u.floatval);
	  break;
	case 4:
	  A4GL_push_float (ptr[a].single_dtype_u.smfltval);
	  break;
	default:
	  A4GL_exitwith ("Unprintable datatype");
	  return 0;
	}
    }

  clnt_destroy (clnt);
  return result_1->return_values_len - 1;
}

/**
 * Call a remote function using RPC protocol.
 *
 * @param host The host where to call the remote function.
 * @param async
 * @param A4GL_func The name of the remote function to call.
 * @param port The port number to use when making the call.
 * @param np The number of parameters.
 */
int
A4GL_remote_func_call (char *host, int async, char *func, int port, int np)
{
  int a;
  char buff[64];
  A4GLSQL_set_status (0, 0);
  if (async)
    {
      strcpy (buff, "!");
      strcat (buff, func);
    }
  else
    {
      strcpy (buff, func);
    }
  serviceport = port + 0x2000000;
  A4GL_debug ("Calling host %s A4GL_func %s on port %ld with %d entries",
	 host, buff, port, np);
  a = A4GL_fgl_rpc_1 (host, buff, np);
  return a;
}


/* ============================== EOF ================================= */
