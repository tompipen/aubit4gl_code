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
# $Id: barcodelookup.c,v 1.1 2007-10-11 21:19:18 mikeaubury Exp $
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

#include "barcodelookup.h"
static int initialized=0;
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
      A4GL_debug ("XML-RPC Fault: %s (%d) @ line %d\n", env->fault_string, env->fault_code, line);
      A4GL_exitwith ("XMLRPC Error");
      return 1;
    }
  return 0;
}

/* this macro definiton MUST be after the function definition: */
#define die_if_fault_occurred(x) die_if_fault_occurred(x,__LINE__)

/**
 * 
 * Note: proto for this function is printed by dlmagic into API_rpc.c file instead of
 * .h file - so we cant include it here. 
 
 	./incl/a4gl_API_rpc.h
	./incl/a4gl_API_rpc_lib.h
	
 * @todo Describe function
 */
static int initlib (void) {
	if (initialized) return 1;
	initialized++;

  xmlrpc_client_init (XMLRPC_CLIENT_NO_FLAGS, NAME, VERSION);
  xmlrpc_env_init (&env);
  die_if_fault_occurred (&env);
  return 1;
}

static char *xmlrpc_struct_find_str_value(xmlrpc_env *env, xmlrpc_value *result, char *srch) {
  xmlrpc_value *message;
size_t l=0;
char *ptr=0;
int nret;
int a;
a=xmlrpc_value_type(result);

if (a==XMLRPC_TYPE_STRING) {
	xmlrpc_read_string_lp(env,result,&l,&ptr);
	return "";
}


  if (!xmlrpc_struct_has_key(env,result,srch)) {
		die_if_fault_occurred(env);
		printf("%s is Not there\n", srch);
		return "";
	}

  xmlrpc_struct_find_value(env, result, srch, &message) ;

  if (message ) {
		xmlrpc_read_string_lp(env,message,&l,&ptr);
		if (ptr) {
			return ptr;
		}
  } 
return "";

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
aclfgl_a4gl_lookup_barcode (int n) 
{
  int a;
  void *p;
  int d;
  long s;
  int i;
  xmlrpc_value *item_value;
  xmlrpc_value *result;
  xmlrpc_value *array;
  int nret;
  xmlrpc_value *in;

char *host;
 char *func;
 char *str;

 str=A4GL_char_pop();
 func=A4GL_char_pop();
 host=A4GL_char_pop();

	initlib();


	array = xmlrpc_array_new (&env);
      die_if_fault_occurred (&env);


A4GL_trim(str);
	item_value=xmlrpc_string_new(&env, str);
      die_if_fault_occurred (&env);
	xmlrpc_array_append_item (&env, array, item_value);
      die_if_fault_occurred (&env);
      xmlrpc_DECREF (item_value);
      die_if_fault_occurred (&env);


  A4GL_debug ("Calling %s %s with array", host, func);

  result = xmlrpc_client_call_params (&env, host, func, array);

  if (die_if_fault_occurred (&env)) {
    return 0;
	}


 
  if (result == NULL)
    {
      A4GL_exitwith ("Call failed");
      return 0;
    }

   //A4GL_push_char(xmlrpc_struct_find_str_value("message"));
   A4GL_push_char(xmlrpc_struct_find_str_value(&env,result, "description"));
   //A4GL_push_char(xmlrpc_struct_find_str_value(&env,result,"size"));
   //A4GL_push_char(xmlrpc_struct_find_str_value("issuerCountryCode"));


  xmlrpc_DECREF (result);

  return 1;
}




/* ================================ EOF ============================= */
