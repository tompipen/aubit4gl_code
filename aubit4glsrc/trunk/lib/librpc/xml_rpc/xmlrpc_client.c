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
# $Id: xmlrpc_client.c,v 1.11 2005-03-28 20:23:24 mikeaubury Exp $
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

#include "a4gl_lib_rpc_rpcxml_int.h"

/*
=====================================================================
                    Constants definitions
=====================================================================
*/


#define NAME "XML-RPC Aubit 4GL Client"
#define VERSION "0.1"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

xmlrpc_env env;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

int A4GL_fgl_rpc_1 (char *host, char *func, int np);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 *
 * @todo Describe function
 */
static int
die_if_fault_occurred (xmlrpc_env * env, int line)
{
  if (env->fault_occurred)
    {
      A4GL_debug ("XML-RPC Fault: %s (%d) @ line %d\n", env->fault_string,
	     env->fault_code, line);
      A4GL_exitwith ("XMLRPC Error");
      return 1;
    }
  return 0;
}

/* this macro definiton MUST be after the function definition: */
#define die_if_fault_occurred(x) die_if_fault_occurred(x,__LINE__)

/**
 *
 * @todo Describe function
 */
int
A4GLRPC_initlib (void)
{
  xmlrpc_client_init (XMLRPC_CLIENT_NO_FLAGS, NAME, VERSION);
  xmlrpc_env_init (&env);
  die_if_fault_occurred (&env);
  return 1;
}

/**
 *
 * @todo Describe function
 */
static char *
get_string (xmlrpc_env * env, xmlrpc_value * in)
{
  char *s;
  xmlrpc_parse_value (env, in, "s", &s);
  die_if_fault_occurred (env);
  return (s);
}


/**
 *
 * @todo Describe function
 */
static char *
get_timestamp (xmlrpc_env * env, xmlrpc_value * in)
{
  char *s;

  xmlrpc_parse_value (env, in, "8", &s);
  die_if_fault_occurred (env);
  return (s);
}



/**
 *
 * @todo Describe function
 */
static double
get_double (xmlrpc_env * env, xmlrpc_value * in)
{
  double d;
  xmlrpc_parse_value (env, in, "d", &d);
  die_if_fault_occurred (env);
  return (d);
}


/**
 *
 * @todo Describe function
 */
static int
get_boolean (xmlrpc_env * env, xmlrpc_value * in)
{
  int i;
  xmlrpc_parse_value (env, in, "b", &i);
  die_if_fault_occurred (env);
  return (i);
}

/**
 *
 * @todo Describe function
 */
static int
get_int (xmlrpc_env * env, xmlrpc_value * in)
{
  int i;
  xmlrpc_parse_value (env, in, "i", &i);
  die_if_fault_occurred (env);
  return (i);
}

/**
 *
 * @todo Describe function
 */
int
A4GL_fgl_rpc_1 (char *host, char *func, int np)
{
  int a;
  void *p;
  int d;
  long s;
  int i;
  xmlrpc_value *array;
  xmlrpc_value *item_value;
  xmlrpc_value *result;
  int nret;
  xmlrpc_value *in;

  array = xmlrpc_build_value (&env, "()");
  die_if_fault_occurred (&env);

  /* Build the array element here */



  for (a = 0; a < np; a++)
    {
      item_value = 0;
      /* void A4GL_get_top_of_stack (int a, int *d, int *s, void **ptr); */
      A4GL_get_top_of_stack (1, &d, (int *) &s, &p);
      A4GL_debug ("Top of stack return %d %d %p (%d)", d, s, p);


      switch (d & 15)
	{
	case 0:
	  item_value = xmlrpc_build_value (&env, "s", A4GL_char_pop ());
	  break;
	case 1:
	  item_value = xmlrpc_build_value (&env, "i", A4GL_pop_long ());
	  break;
	case 6:
	case 7:
	case 8:
	case 2:
	  item_value = xmlrpc_build_value (&env, "i", A4GL_pop_long ());
	  break;
	case 3:
	  item_value = xmlrpc_build_value (&env, "i", A4GL_pop_double ());
	  break;
	case 4:
	  item_value = xmlrpc_build_value (&env, "d", A4GL_pop_double ());
	  break;
	default:
	  A4GL_exitwith ("Untransmittable data");
	}


      die_if_fault_occurred (&env);
      xmlrpc_array_append_item (&env, array, item_value);

      die_if_fault_occurred (&env);
      xmlrpc_DECREF (item_value);
      die_if_fault_occurred (&env);
    }


  A4GL_debug ("Calling %s %s with array", host, func);
  result = xmlrpc_client_call (&env, host, func, "()", array);

  if (die_if_fault_occurred (&env))
    return 0;


  if (result == NULL)
    {
      A4GL_exitwith ("Call failed");
      return 0;
    }
  nret = xmlrpc_array_size (&env, result);

  A4GL_debug ("Got %d values returned");

  for (i = 0; i < nret; i++)
    {
      in = xmlrpc_array_get_item (&env, result, i);


      /* What did we get back? */
      switch (xmlrpc_value_type (in))
	{
	case (XMLRPC_TYPE_INT):
	  A4GL_push_long (get_int (&env, in));
	  break;
	case (XMLRPC_TYPE_BOOL):
	  A4GL_push_int (get_boolean (&env, in));
	  break;
	case (XMLRPC_TYPE_DOUBLE):
	  A4GL_push_double (get_double (&env, in));
	  break;
	case (XMLRPC_TYPE_DATETIME):
	  /* void push_dtime(struct a4gl_dtime *p); */
	  A4GL_push_char (get_timestamp (&env, in));
	  break;
	case (XMLRPC_TYPE_STRING):
	  A4GL_push_char (get_string (&env, in));
	  break;

	case (XMLRPC_TYPE_BASE64):
	  A4GL_exitwith ("Can't Handle Base64 Data");
	  return 0;
	  break;
	case (XMLRPC_TYPE_ARRAY):
	  A4GL_exitwith ("Can't Handle Complex Data");
	  return 0;
	  break;
	case (XMLRPC_TYPE_STRUCT):
	  A4GL_exitwith ("Can't Handle Complex Data");
	  return 0;
	  break;
	case (XMLRPC_TYPE_C_PTR):
	  A4GL_exitwith ("Can't Handle Pointers");
	  return 0;
	  break;
	case (XMLRPC_TYPE_DEAD):
	  A4GL_exitwith ("Got a 0xDEAD");
	  return 0;
	  break;
	default:
	  A4GL_exitwith ("UNKNOWN XML TYPE");
	  return 0;
	  break;
	}
    }

  xmlrpc_DECREF (result);

  return nret;
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

/* Port is unused in XMLRPC */

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

  A4GL_debug ("Calling host %s A4GL_func %s on port %ld with %d entries", host, buff,
	 port, np);
  a = A4GL_fgl_rpc_1 (host, buff, np);
  return a;
}



/* ================================ EOF ============================= */
