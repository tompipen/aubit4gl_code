/**
 * @file
 *
 * @todo Add Doxygen comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

#include <stdio.h>
#include <stdlib.h>
#include <xmlrpc.h>
#include <xmlrpc_client.h>

#define NAME "XML-RPC Aubit 4GL Client"
#define VERSION "0.1"

#include "../libincl/debug.h"
#include "../libincl/stack.h"

xmlrpc_env env;

double pop_double();
int push_double(double a);
float pop_float();
int push_float(float a);





int die_if_fault_occurred (xmlrpc_env *env,int line)
{
    if (env->fault_occurred) {
        debug("XML-RPC Fault: %s (%d) @ line %d\n", env->fault_string, env->fault_code,line);
        exitwith("XMLRPC Error");
	return 1;
    }
return 0;
}



#define die_if_fault_occurred(x) die_if_fault_occurred(x,__LINE__)


void A4GLRPC_initlib() {
    xmlrpc_client_init(XMLRPC_CLIENT_NO_FLAGS, NAME, VERSION);
    xmlrpc_env_init(&env);
	die_if_fault_occurred(&env);
}

static char* get_string(xmlrpc_env* env, xmlrpc_value* in){
    char* s;
    xmlrpc_parse_value(env, in, "s", &s);
    die_if_fault_occurred(env);
    return(s);
}


static char* get_timestamp(xmlrpc_env* env, xmlrpc_value* in){
    char *s;
   
   xmlrpc_parse_value(env, in, "8", &s);
   die_if_fault_occurred(env);
    return(s);
}



static double get_double(xmlrpc_env* env, xmlrpc_value* in){
   double d;
   xmlrpc_parse_value(env, in, "d", &d);
   die_if_fault_occurred(env);
   return(d);
}


static int get_boolean(xmlrpc_env* env, xmlrpc_value* in){
   int i;
  xmlrpc_parse_value(env, in, "b", &i);
  die_if_fault_occurred(env);
  return(i);
}

static int get_int(xmlrpc_env* env, xmlrpc_value* in){
int i;
 xmlrpc_parse_value(env, in, "i", &i);
 die_if_fault_occurred(env);
 return(i);
}

int fgl_rpc_1( char* host,char *func,int np)
{
double dbl;
int a;
void *p;
int d;
long s;
int i;
xmlrpc_value *array;
xmlrpc_value * item_value ;
xmlrpc_value *result;
int nret;
xmlrpc_value *in;

	array=xmlrpc_build_value(&env,"()");
	die_if_fault_occurred(&env);

				// Build the array element here



	for (a=0;a<np;a++) {
                item_value = 0;
		get_top_of_stack(1,&d,&s,&p);
		debug("Top of stack return %d %d %p (%d)",d,s,p);


		switch (d&15) {
			case 0: 
                 item_value = xmlrpc_build_value(&env,"s",char_pop());break;
			case 1: 
                 item_value = xmlrpc_build_value(&env,"i",pop_long());break;
			case 6:
			case 7:
			case 8:
			case 2: 
                 item_value = xmlrpc_build_value(&env,"i",pop_long());break;
			case 3:
                 item_value = xmlrpc_build_value(&env,"i",pop_double());break;
			case 4:	
                 item_value = xmlrpc_build_value(&env,"d",pop_double());break;
			default :	exitwith("Untransmittable data");
		}


		die_if_fault_occurred(&env);
                xmlrpc_array_append_item( &env, array, item_value);

		die_if_fault_occurred(&env);
                xmlrpc_DECREF(item_value);
	die_if_fault_occurred(&env);
	}


	debug("Calling %s %s with array",host,func);
	result = xmlrpc_client_call(&env,host,func,"()",array);

	if (die_if_fault_occurred(&env)) return 0;


	if (result == NULL) {
	        exitwith("Call failed");
		return 0;
	}
	nret=xmlrpc_array_size(&env,result);

	debug("Got %d values returned");

	for (i=0;i<nret;i++) {
		in = xmlrpc_array_get_item( &env, result, i);


          /* What did we get back? */
          switch (xmlrpc_value_type(in)) {
            case (XMLRPC_TYPE_INT):
              push_long( get_int(&env, in));
              break;
            case (XMLRPC_TYPE_BOOL):
              push_int( get_boolean(&env, in));
              break;
            case (XMLRPC_TYPE_DOUBLE):
              push_double(get_double(&env, in));
              break;
           case (XMLRPC_TYPE_DATETIME):
                      push_dtime(get_timestamp(&env, in));
             break;
           case (XMLRPC_TYPE_STRING):
             push_char(get_string(&env, in));
             break;

           case (XMLRPC_TYPE_BASE64):
		exitwith("Can't Handle Base64 Data");
		return 0;
             break;
           case (XMLRPC_TYPE_ARRAY):
		exitwith("Can't Handle Complex Data");
		return 0;
             	break;
           case (XMLRPC_TYPE_STRUCT):
		exitwith("Can't Handle Complex Data");
		return 0;
             	break;
           case (XMLRPC_TYPE_C_PTR):
		exitwith("Can't Handle Pointers");
		return 0;
             	break;
           case (XMLRPC_TYPE_DEAD):
		exitwith("Got a 0xDEAD");
		return 0;
             	break;
           default:
		exitwith("UNKNOWN XML TYPE");
		return 0;
             	break;
	}
}
xmlrpc_DECREF(result);

return nret;

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
remote_func_call(char *host,int async,char *func,int port,int np)
{
  int a;
  char buff[64];

// Port is unused in XMLRPC

  A4GLSQL_set_status(0);

  if (async) {
    strcpy(buff,"!");
    strcat(buff,func);
  } else {
    strcpy(buff,func);
  }

  debug("Calling host %s func %s on port %ld with %d entries", host,buff,port,np);
  a=fgl_rpc_1(host,buff,np);
  return a;
}















