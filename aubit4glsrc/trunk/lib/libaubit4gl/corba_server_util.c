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
# $Id: corba_server_util.c,v 1.20 2005-08-24 14:03:29 mikeaubury Exp $
#
*/

/**
 * @file
 * 
 * This file contains 2 sections:
 * 
 * 1) Collections of primitive (or near primitive) functions we need in BOTH
 *    libaubit4gl AND when making CORBA server (to support dlopen functionality)
 * 
 * 2) Collections of utility functions for Aubit CORBA servers, in #ifdef __CAPI__ 
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 */

/*

Files created by ORBIT_IDL from .idl:
-------------------------------------

File				Usage for Client	Usage for Server		TO-DO
-------------------------------------------------------------------------------------
CAPI_*.h			readonly			readonly				do not edit
CAPI_*-common.c		readonly			readonly				do not edit
CAPI_*-stubs.c		readonly			-						do not edit
CAPI_*-skels.c		-					readonly				do not edit
CAPI_*-skelimpl.c	-					template for user code 	add the code of the server methods

Files generated by idlmagic script:
-----------------------------------
CAPI_*.idl			.idl for use by ORBIT_IDL
CAPI_*-client.c		write the client code (with -client : API specific code)
CAPI_*-server.c		write the generic code for servant creation (with -server : API specific code)

Additional objects compiled from lib/libaubit4gl/corba_server_util.c:
----------------------------------------------------------------------
CLIENT_corba_server_util.o	with -D__CSERVER__ (API independent code for client & client utilities)
SERVER_corba_server_util.o  with -D__CCLIENT__ (API independent code for server & server utilities)


How it works - using normal Aubit dlopen() API
-----------------------------------------------

		app							libaubit4gl										plug-in
--------------------------------------------------------------------------------------------------------------------
call A4GLSQLCV_convert_sql()---->	A4GLSQLCV_convert_sql() in API_sqlparse.c ---->	A4GLSQLCV_convert_sql in util.c
																					calls
																					A4GLSQLCV_convert_sql_internal() in same file
									
									
How it works - with CORBA API between Aubit dlopen() API
--------------------------------------------------------

		app							libaubit4gl										CORBA API plug-in CLIENT					CORBA API plug-in SERVER		plug_in
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
call A4GLSQLCV_convert_sql()---->	A4GLSQLCV_convert_sql() in API_sqlparse.c ---->	A4GLSQLCV_convert_sql in CORBA-client.c	--->CORBA_A4GLSQLCV_convert_sql()	A4GLSQLCV_convert_sql in util.c
																																calls 							calls
																																A4GLSQLCV_convert_sql()			A4GLSQLCV_convert_sql_internal() in same file
																																in API_sqlparse.c 										

*/
 
 
/*
=====================================================================
		                    Includes
=====================================================================
*/


#include "a4gl_libaubit4gl_int.h"
#include <ctype.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

#ifndef _ASSERT_H
	#include <assert.h>
#endif

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


#ifdef __CAPI__
//from #include "examples-toolkit.h" /* provides etk_abort_if_exception */ 

//-DORBIT2=1 is defined in pkg-config flags in ORBit version 2
#ifdef ORBIT2
	#include <orbit/orbit.h>
#else
	#include <orb/orbit.h>
#endif

#include <ORBitservices/CosNaming.h>

/* extracts type of exception: Three return Values are possible:
 * CORBA_NO_EXCEPTION, CORBA_USER_EXCEPTION, CORBA_SYSTEM_EXCEPTION:/
*/
#define etk_exception_type(ev) (ev->_major)

/** 
 * test @ev for any exception 
 */
gboolean 
etk_raised_exception (CORBA_Environment *ev);

/** 
 * test @ev for specific exception  @ex
 */
gboolean 
etk_raised_exception_is_a (CORBA_Environment *ev, CORBA_char* ex);

/**
 * in case of any exception this operation will abort the process  
 */
void 
etk_abort_if_exception(CORBA_Environment *ev, const char* mesg); 

/**
 * in case of any exception this operation will only free allocated resources
 */
void 
etk_ignore_if_exception(CORBA_Environment *ev, const char* mesg); 

/**
 *
 */
void
etk_export_object_to_stream (CORBA_ORB          orb,
			     CORBA_Object       servant,
			     FILE              *stream,
			     CORBA_Environment *ev);


/* Writes stringified object reference of @servant to file
 * @filename. If error occures @ev points to exception object on
 * return.
 */
void 
etk_export_object_to_file (CORBA_ORB          orb,
			   CORBA_Object       servant,
			   char              *filename, 
			   CORBA_Environment *ev);

/**
 *
 */
CORBA_Object
etk_import_object_from_stream (CORBA_ORB          orb,
			       FILE              *stream,
			       CORBA_Environment *ev);

/**
 *
 */
CORBA_Object
etk_import_object_from_file (CORBA_ORB          orb,
			     CORBA_char        *filename,
			     CORBA_Environment *ev);


/** resolves default name-service, usually given to application as
 * command line argument "-ORBInitRef NameService=IOR:0100000028..",
 * or since release 2.8.0 corbalocs in form of URL can be used, eg:
 * "-ORBInitRef NameService=corbaloc:iiop:HOSTNAME:PORT/NameService%00"
 */
CosNaming_NamingContext 
etk_get_name_service (CORBA_ORB         orb,
		      CORBA_Environment *ev);


/* binds @servant object reference to unique @name at
 * @name_service. @name is a NULL terminated list of strings
 * (CORBA_char*). If error occures @ev points to exception object on
 * return.
 */
void 
etk_name_service_bind (CosNaming_NamingContext  name_service,
		       CORBA_Object             servant,
		       gchar                   *id_vec[], 
		       CORBA_Environment       *ev);

/* resolves object reference @return with unique @name at
 *  @name_service. @name is a NULL terminated list of strings
 *  (CORBA_char*).  If error occures @ev points to * exception object
 *  on return.
 */
CORBA_Object 
etk_name_service_resolve (CosNaming_NamingContext  name_service,
			  gchar                   *id_vec[], 
			  CORBA_Environment       *ev);

			  
#ifdef __CCLIENT__
	int A4GL_CORBA_client_main (int argc, char* argv[]);
	void client_init (int *argc_ptr,char *argv[],CORBA_ORB *orb, CORBA_Environment *ev);

#endif
			  
			  
#endif //ifdef __CAPI__

#ifndef __CCLIENT__
//CORBA client plug-in allready has access to this via libaubit4gl, so this
//block will be compiled only when this file is compiled
//for use in libaubit4gl _AND_ CORBA server - but NOT CORBA client

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

int dying=0;


/*
=====================================================================
                    Functions definitions
=====================================================================
*/



//--- from funcs_d.c
#ifdef strcpy
#undef strcpy
#endif
char *A4GL_strcpy(char *dest,char *src,char *f,int l,int sd) {
  	int lsrc;
	char buff[256];

	if (src==0) {
		SPRINTF2(buff,"No source for strcpy @ %s line %d",f,l);
		A4GL_assertion(1,buff);
	}

	lsrc=strlen(src);
	if (sd!=sizeof(char *)) {
		if (lsrc>=sd) {
			A4GL_debug("String overflow detected : %s %d (%d>=%d)",f,l,strlen(src),sd);
			SPRINTF2(buff,"String overflow detected @ %s line %d",f,l);
			A4GL_assertion(1,buff);
		}
	}
	strcpy(dest,src);


#ifdef DEBUG
{
// This just adds some debugging stuff - but this 
// isn't applicable when called from the routines in dmy.c 
// as they put some funny characters in the string as placeholders
//
	if (strcmp(f,"dmy.c")==0) return dest;


// Quick - is it big ?
	if (lsrc>255) {
		char buff[3000];
		strncpy(buff,src,2999);
		buff[2999]=0;
		A4GL_debug("Long string : %s\n",buff);
	}

// Does it look Good ?
{
	int a;
	for (a=0;a<lsrc;a++) {
		if (!isprint(src[a])&&src[a]!='\n'&&!ispunct(src[a])) {
			A4GL_debug("Possible bad char @%d for string '%s' (%d)\n",a,src,strlen(src));
		}
	}
}
}
#endif
	
	return dest;
}

#ifdef strcat
#undef strcat
#endif
char *A4GL_strcat(char *dest,char *src,char *f,int l,int sd) {
  	int lsrc;
	char buff[256];

	if (src==0) { SPRINTF2(buff,"No source for strcat @ %s line %d",f,l); A4GL_assertion(1,buff); }
	if (dest==0) { SPRINTF2(buff,"No destination for strcat @ %s line %d",f,l); A4GL_assertion(1,buff); }

	lsrc=strlen(src)+strlen(dest);

	if (sd!=sizeof(char *)) {
		if (lsrc>=sd) {
			A4GL_debug("String overflow detected : %s %d (%d>=%d)",f,l,strlen(src),sd);
			SPRINTF2(buff,"String overflow detected @ %s line %d",f,l);
			A4GL_assertion(1,buff);
		}
	}
	strcat(dest,src);


	return dest;
}


int A4GL_sprintf (char *f,int l, char *dest,size_t sdest,char *fmt, ...) {
char buff[256];
int x;
char *c;
va_list args;
char xbuff[10000]; 


// DO NOT CALL A4GL_debug from this function!!!!
// (put that in a few times - just top make sure :-)
/* 

We can end up with problems with overlapping - eg
      sprintf(bibble,"'%s'",bibble);

   so we'll sprintf into a temporary space first, then strcpy across after

*/
        if (fmt==0) {
                sprintf(buff,"No format for sprintf @ %s line %d",f,l);
                A4GL_assertion(1,buff);
        }

// DO NOT CALL A4GL_debug from this function!!!!

	if (sdest>sizeof(char *)) { // We do this one...
	      va_start (args, fmt);
	      c=acl_malloc2(sdest);
	      x=vsnprintf(c,sdest,fmt,args);
	      if (x>=sdest) {
                sprintf(buff,"sprintf trying to exceed allocated space @ %s (line %d)",f,l);
			PRINTF("-->%s (%d>=%d)",fmt,x,sdest);
			A4GL_assertion(1,buff);
	      }
	      strncpy(dest,c,sdest);
	      free(c);
// DO NOT CALL A4GL_debug from this function!!!!
	} else {
	      va_start (args, fmt);
	      x=vsprintf(xbuff,fmt,args);
		if (x>sizeof(xbuff)) {
			A4GL_assertion(1,"sprintf > 10,000 characters when using a pointer...");
		}
	      strcpy(dest,xbuff);
	}
	return x;
// DO NOT CALL A4GL_debug from this function!!!!
}






//--from string.c
char *A4GL_null_as_null(char *s) {
static char *nbuff="(null)";
if (s==0) return nbuff;
return s;
}




// We're quitting - so close down any UI specific stuff
// before we go...
void A4GL_stop_ui(void) {

  if (A4GL_isscrmode ())
    {
#ifdef DEBUG
      A4GL_debug ("In screen mode - ending curses...");
#endif
      A4GL_gotolinemode ();
    }

}




// --- from fglwrap.c
void
A4GL_fgl_die_with_msg (int n, char *s)
{
  if (dying)
    {
      // We're already trying to die...
      return;
    }
  dying++;

  if (dying > 1)
    {
      exit (n);
    }
  if (A4GL_isscrmode ())
    {
#ifdef DEBUG
      A4GL_debug ("In screen mode - ending curses...");
#endif
      A4GL_gotolinemode ();
    }
  A4GL_close_database ();
  A4GL_close_errorlog_file ();
  A4GL_debug ("End of program - exit(%d).", n);
  PRINTF ("%s\n", s);
  exit (n);
}

void
A4GL_fgl_die (int n)
{
  if (dying)
    return;
  dying++;
  if (dying > 1)
    {
      // Die quickly...
      exit (n);
    }



  A4GL_stop_ui();


  if (A4GL_isscrmode ())
    {
#ifdef DEBUG
      A4GL_debug ("In screen mode - ending curses...");
#endif
      A4GL_stop_ui();
      //A4GL_gotolinemode ();
    }
  A4GL_close_database ();
  A4GL_close_errorlog_file ();
  A4GL_debug ("End of program - exit(%d).", n);
  exit (n);
}


// from funcs_d.c
/**
 * Trim the spaces and new lines at the rigth side of a string.
 *
 * @param p The string to be trimmed.
 */
void
A4GL_trim_nl (char *p)
{
  int a;
  for (a = strlen (p) - 1; a >= 0; a--)
    {
      if (p[a] != ' ' && p[a] != '\n' && p[a] != '\r' && p[a] != '\t')
	break;
      p[a] = 0;
    }
}

/**
 * Trim the spaces at the rigth side of a string
 *
 * @param p The string to be trimmed.
 */
void
A4GL_trim (char *p)
{
  int a;
  for (a = strlen (p) - 1; a >= 0; a--)
    {
      if (p[a] != ' ' && p[a] != '\t' && p[a] != '\n' && p[a] != '\r')
	break;
      p[a] = 0;
    }
}

/**
 *  * Trim the spaces at the rigth side of a string
 *   *
 *    * @param p The string to be trimmed.
 *     */
void
A4GL_trim_not_nl (char *p)
{
  int a;
  for (a = strlen (p) - 1; a >= 0; a--)
    {
      if (p[a] != ' ')
	break;
      p[a] = 0;
    }
}
// --- from fglwrap.c
/**
 * Checks if the string have some sort of yes (y,Y,1,true).
 *
 * @param s The string to be checked
 * @return - 1 : Is yes
 *         - 0 : Otherwise
 */
int
A4GL_isyes (char *s)
{
  if (s == 0)
    {
      //debug("isyes = false");
      return 0;
    }
  //debug("isyes called with %s\n",s);
  if (s[0] == 0)
    {
      //debug("isyes = false");
      return 0;
    }
  if (s[0] == 'y' || s[0] == 'Y' || s[0] == '1'
      || A4GL_aubit_strcasecmp (s, "true") == 0)
    {
      //debug("isyes = true");
      return 1;
    }
  //debug("isyes = false");
  return 0;
}

//-- from match.c


/**
 *
 * @todo Describe function
 */
int
A4GL_aubit_strcasecmp (char *a, char *b)
{
  int c;
  int l1;
  int l2;
  int m;
   
  l1=strlen(a);
  l2=strlen(b);

  if (l1>l2) m=l2;
	else m=l1;
  
  for (c = 0; c <= m; c++)
    {
      if (toupper (a[c]) > toupper (b[c]))
	return 1;
      if (toupper (a[c]) < toupper (b[c]))
	return -1;
    }

  if (l1 == l2) return 0;
  if (l1 > l2 ) return 1;

  return -1;
}

#endif //ifndef __CCLIENT__


/*
=====================================================================
                    CORBA server support ONLY
=====================================================================
*/

#ifdef __CAPI__
#ifdef __CSERVER__
//CORBA server will need this to support above funstions, since it will 
//not have access to libaubit4gl, which is on the CLIENT side

/* first, dummy finctions we don't need in CORBA server */

//
void A4GL_assertion(int a, char *s) {}
//
int A4GL_isscrmode() { return 0; }
//
void A4GL_gotolinemode() {}
//
void A4GL_close_database() {}
//
void A4GL_close_errorlog_file() {}
//debug.c:
void A4GL_debug_full(char *fmt, ...) {}
//debug.c:
int A4GL_set_line(char *fname, long lineno) {  return 0; }
//sql.c:
void A4GLSQL_set_status (int a, int sql) {}
//API_sql.spec
char* A4GLSQL_get_errmsg( int a) { return 0; } 


/* Then, copies of some functions we DO need, but don't want to move from there
	original .c file, and linking that .c file in causes bunch of new dependencies
	we dont want to introduce
*/


#endif //ifdef __CSERVER__











#ifdef __CCLIENT__
// ------------------------------- client funcs ----------------------------

//Example 5-16. account-client.c

/* account-client.c hacked by Frank Rehberger
 * <F.Rehberger@xtradyne.de>.  */

//#include "account.h"

//static CORBA_ORB  global_orb = CORBA_OBJECT_NIL; /* global orb */
//--not static - needed in CAPI_sqlparse-client.c too 
CORBA_ORB  global_orb = CORBA_OBJECT_NIL; /* global orb */

/* Is called in case of process signals. it invokes CORBA_ORB_shutdown()
 * function, which will terminate the processes main loop.
 */
static
void
client_shutdown (int sig)
{
CORBA_Environment  local_ev[1];
        CORBA_exception_init(local_ev);
 
        if (global_orb != CORBA_OBJECT_NIL)
        {
                 CORBA_ORB_shutdown (global_orb, FALSE, local_ev); 
                etk_abort_if_exception (local_ev, "caught exception");
        }
}
 
        
/* Inits ORB @orb using @argv arguments for configuration. For each
 * ORBit options consumed from vector @argv the counter of @argc_ptr
 * will be decremented. Signal handler is set to call
 * echo_client_shutdown function in case of SIGINT and SIGTERM
 * signals.  If error occures @ev points to exception object on
 * return.
 */
//static -- not static -- called from CAPI_xxxx-client.c (created by idlmagic)
void
client_init (int *argc_ptr,char *argv[],CORBA_ORB *orb, CORBA_Environment *ev)
{
    /* init signal handling */
	signal(SIGINT,  client_shutdown);
    signal(SIGTERM, client_shutdown);
    /* create Object Request Broker (ORB) */
    (*orb) = CORBA_ORB_init(argc_ptr, argv, "orbit-local-mt-orb", ev); 
    if (etk_raised_exception(ev)) return;
}

/* Releases @servant object and finally destroys @orb. If error
 * occures @ev points to exception object on return.
 */
static void
client_cleanup (CORBA_ORB                 orb,
                CORBA_Object              service,
                CORBA_Environment        *ev)
{
	/* releasing managed object */
    CORBA_Object_release(service, ev); 
    if (etk_raised_exception(ev)) return;
 
    /* tear down the ORB */
    if (orb != CORBA_OBJECT_NIL) {
		/* going to destroy orb.. */
        CORBA_ORB_destroy(orb, ev); 
        if (etk_raised_exception(ev)) return;
    }
}


#ifdef _THIS_IS_JUST_AN_EXAMLE_
/**
 * This is example client code from ORBit manual of how a client should 
 * invoke function in the server.
 * SQLPARSE here is just a name of the API (was 'Account')
 */
static void
client_run (SQLPARSE service, CORBA_long amount, CORBA_Environment *ev) {
CORBA_long balance=0;
	balance = SQLPARSE__get_balance (service, ev);
	if (etk_raised_exception (ev)) return;
	g_print ("balance %5d, ", balance);
    if (amount > 0) {
		SQLPARSE_deposit (service, amount, ev); 
        if (etk_raised_exception (ev)) return;
    } else {
		SQLPARSE_withdraw (service, abs(amount), ev); 
        if (etk_raised_exception (ev)) return;
    }
    balance = SQLPARSE__get_balance (service, ev); 
	if (etk_raised_exception (ev)) return;
    g_print ("new balance %5d\n", balance);
}
#endif //_THIS_IS_JUST_AN_EXAMLE_



// -----------------------end client funcs --------------------------
#endif //ifdef __CCLIENT__
















#ifdef __CSERVER__
// ----------------------- CORBA SERVER funcs --------------------------

//Example 5-20. account-server.c

/*
 * account-server program. Hacked from Frank Rehberger
 * <F.Rehberger@xtradyne.de>.
 */

//#include "account.h"
//#include "account-skelimpl.c"

static CORBA_ORB          global_orb = CORBA_OBJECT_NIL; /* global orb */
static PortableServer_POA root_poa   = CORBA_OBJECT_NIL; /* root POA */
	
/* Is called in case of process signals. it invokes CORBA_ORB_shutdown()
 * function, which will terminate the processes main loop.
 */
static
void
server_shutdown (int sig)
{
	CORBA_Environment  local_ev[1];
	CORBA_exception_init(local_ev);

        if (global_orb != CORBA_OBJECT_NIL)
        {
                 CORBA_ORB_shutdown (global_orb, FALSE, local_ev); 
                etk_abort_if_exception (local_ev, "caught exception");
        }
}

/* Inits ORB @orb using @argv arguments for configuration. For each
 * ORBit options consumed from vector @argv the counter of @argc_ptr
 * will be decremented. Signal handler is set to call
 * echo_server_shutdown function in case of SIGINT and SIGTERM
 * signals.  If error occures @ev points to exception object on
 * return.
 */static 
void 
server_init (int                 *argc_ptr, 
	     char                *argv[],
	     CORBA_ORB           *orb,
	     PortableServer_POA  *poa,
	     CORBA_Environment   *ev)
{
	PortableServer_POAManager  poa_manager = CORBA_OBJECT_NIL; 

	CORBA_Environment  local_ev[1];
	CORBA_exception_init(local_ev);

	/* init signal handling */
	signal(SIGINT,  server_shutdown);
	signal(SIGTERM, server_shutdown);
	
	/* create Object Request Broker (ORB) */
	
         (*orb) = CORBA_ORB_init(argc_ptr, argv, "orbit-local-mt-orb", ev); 
	if (etk_raised_exception(ev)) 
		goto failed_orb;

         (*poa) = (PortableServer_POA) 
		CORBA_ORB_resolve_initial_references(*orb, "RootPOA", ev); 
	if (etk_raised_exception(ev)) 
		goto failed_poa;

         poa_manager = PortableServer_POA__get_the_POAManager(*poa, ev); 
	if (etk_raised_exception(ev)) 
		goto failed_poamanager;

	 PortableServer_POAManager_activate(poa_manager, ev); 
	if (etk_raised_exception(ev)) 
		goto failed_activation;

         CORBA_Object_release ((CORBA_Object) poa_manager, ev); 
	return;

 failed_activation:
 failed_poamanager:
        CORBA_Object_release ((CORBA_Object) poa_manager, local_ev);
 failed_poa:
	CORBA_ORB_destroy(*orb, local_ev);		
 failed_orb:
	return;
}

/* Entering main loop @orb handles incoming request and delegates to
 * servants. If error occures @ev points to exception object on
 * return.
 */
static void 
server_run (CORBA_ORB          orb,
	    CORBA_Environment *ev)
{
        /* enter main loop until SIGINT or SIGTERM */
	
         CORBA_ORB_run(orb, ev); 
	if (etk_raised_exception(ev)) return;

        /* user pressed SIGINT or SIGTERM and in signal handler
	 * CORBA_ORB_shutdown(.) has been called */
}

/* Releases @servant object and finally destroys @orb. If error
 * occures @ev points to exception object on return.
 */
static void 
server_cleanup (CORBA_ORB           orb,
		PortableServer_POA  poa,
		CORBA_Object        ref,
		CORBA_Environment  *ev)
{
	PortableServer_ObjectId   *objid       = NULL;

	 objid = PortableServer_POA_reference_to_id (poa, ref, ev); 
	if (etk_raised_exception(ev)) return;
		
	/* Servant: deactivatoin - will invoke  __fini destructor */
	 PortableServer_POA_deactivate_object (poa, objid, ev); 
	if (etk_raised_exception(ev)) return;

	 PortableServer_POA_destroy (poa, TRUE, FALSE, ev); 
	if (etk_raised_exception(ev)) return;

	CORBA_free (objid);

         CORBA_Object_release ((CORBA_Object) poa, ev); 
	if (etk_raised_exception(ev)) return;
	
         CORBA_Object_release (ref, ev); 
	if (etk_raised_exception(ev)) return;

        /* ORB: tear down the ORB */
        if (orb != CORBA_OBJECT_NIL)
        {
                /* going to destroy orb.. */
                 CORBA_ORB_destroy(orb, ev); 
		if (etk_raised_exception(ev)) return;
        }
}



/* 
 * main for server
 */
int
//main (int argc, char *argv[])
A4GL_CORBA_server_main (int argc, char* argv[])
{
	CORBA_Object servant = CORBA_OBJECT_NIL;
	
	//ref file to write coonection info to - to be used by cliet to find this server
	CORBA_char filename[] = "account.ref";

	CORBA_Environment  ev[1];
	CORBA_exception_init(ev);
	
	 server_init (&argc, argv, &global_orb, &root_poa, ev); 
	etk_abort_if_exception(ev, "failed ORB init");

	 servant = server_activate_service (global_orb, root_poa, ev); 
	etk_abort_if_exception(ev, "failed activating service");

	g_print ("Writing service reference to: %s\n\n", filename);

	 etk_export_object_to_file (global_orb, 
				   servant, 
				   filename, 
				   ev); 
	etk_abort_if_exception(ev, "failed exporting IOR");
	
	 server_run (global_orb, ev); 
	etk_abort_if_exception(ev, "failed entering main loop");

	 server_cleanup (global_orb, root_poa, servant, ev); 
	etk_abort_if_exception(ev, "failed cleanup");

	//exit (0);
	return 0;
}
	

// ----------------------- End CORBA SERVER funcs --------------------------
#endif //ifdef __CSERVER__








//------------ Utility functions from exaples-toolkit.c --------

/** 
 * test @ev for exception 
 */
gboolean 
etk_raised_exception(CORBA_Environment *ev) 
{
	return ((ev)->_major != CORBA_NO_EXCEPTION);
}

/** 
 * test @ev for exception 
 */
gboolean 
etk_raised_exception_is_a (CORBA_Environment *ev, CORBA_char* id) 
{
	return ((ev)->_major != CORBA_NO_EXCEPTION)  &&                 
		strcmp(id, CORBA_exception_id(ev)) == 0;
}

/**
 *  
 */
void 
etk_abort_if_exception (CORBA_Environment *ev, const char* mesg) 
{
	if (etk_raised_exception (ev)) {
		g_error ("%s %s", mesg, CORBA_exception_id (ev));
		CORBA_exception_free (ev); 
		abort(); 
	}
}

/**
 *  
 */
void 
etk_ignore_if_exception (CORBA_Environment *ev, const char* mesg) 
{
	if (etk_raised_exception (ev)) {
		g_warning ("%s %s", mesg, CORBA_exception_id (ev));
		CORBA_exception_free (ev); 
	}
}


/**
 *
 */
void
etk_export_object_to_stream (CORBA_ORB          orb,
			     CORBA_Object       servant,
			     FILE              *stream,
			     CORBA_Environment *ev)
{
        CORBA_char *objref = NULL;
 
        /* write objref to file */
         
        objref = CORBA_ORB_object_to_string (orb, servant, ev);
        if (etk_raised_exception(ev)) return;
 
        /* print ior to terminal */
        fprintf (stream, "%s\n", objref);
        fflush (stream);
 
        CORBA_free (objref);
}


/* Writes stringified object reference of @servant to file
 * @filename. If error occures @ev points to exception object on
 * return.
 */
void 
etk_export_object_to_file (CORBA_ORB          orb,
			   CORBA_Object       servant,
			   char              *filename, 
			   CORBA_Environment *ev)
{
//CORBA_char *objref = NULL;
FILE       *file   = NULL;

	/* write objref to file */
	if ((file=fopen(filename, "w"))==NULL) 
		g_error ("could not open %s\n", filename);
	
	/* print ior to stream */
	etk_export_object_to_stream (orb, servant, file, ev);
	fclose (file);
}


/**
 *
 */
static gchar*
etk_read_string_from_stream (FILE *stream)
{
gulong length = 4*1024; /* should suffice ordinary IOR string */
gchar *objref = g_malloc0 (length*sizeof(gchar)); /* empty string */
int c = 0;
int i = 0;

        /* skip leading white space */
        while((c=fgetc(stream))!=EOF && g_ascii_isspace(c));
        /* POST: c==EOF or c=first character */

        if (c!=EOF)
          /* PRE: c=first character */
          /* append c to string while more c exist and c not white space */
          do {
            /* check size */
            if (i>=(length-1)) {
              length*=2;
              objref=g_realloc (objref, length);
            }
            objref[i++] = c;
          } while ((c=fgetc(stream))!=EOF && !g_ascii_isspace(c));
          /* POST: first string read */

        /* terminate string with \0 */
        objref[i] = '\0';

        /* INV: objref valid string, #objref>=0 */

        return objref;
}

/**
 *
 */
CORBA_Object
etk_import_object_from_stream (CORBA_ORB          orb,
			       FILE              *stream,
			       CORBA_Environment *ev)
{
	CORBA_Object obj = CORBA_OBJECT_NIL;
	gchar *objref=etk_read_string_from_stream (stream);

	if (!objref || strlen (objref)==0) {
		g_warning ("empty object reference");
		if (objref) 
			g_free (objref);
		return CORBA_OBJECT_NIL;		
	}

	obj = (CORBA_Object) CORBA_ORB_string_to_object (orb,
							 objref, 
							 ev);
	free (objref);
	
	return obj;
}

/**
 *
 */
CORBA_Object
etk_import_object_from_file (CORBA_ORB          orb,
			      CORBA_char        *filename,
			      CORBA_Environment *ev)
{
        CORBA_Object  obj    = NULL;
        FILE         *file   = NULL;
  
        /* write objref to file */
          
        if ((file=fopen(filename, "r"))==NULL)
                g_error ("could not open %s\n", filename);
     
        obj= etk_import_object_from_stream (orb, file, ev);
         
	if (obj==CORBA_OBJECT_NIL) 
		g_warning ("object is NIL");

        fclose (file);
 
        return obj;
}
 
/**
 */
CosNaming_NamingContext 
etk_get_name_service (CORBA_ORB orb, CORBA_Environment *ev)
{
//CORBA_char   *str=NULL;
CORBA_Object  ref = (CORBA_Object) CORBA_ORB_resolve_initial_references(orb,
								      "NameService", ev);
    if (etk_raised_exception(ev)) return CORBA_OBJECT_NIL;
	return (CosNaming_NamingContext) ref;
}

/** calculate length of NULL terminated string vector */
static guint 
id_vec_len (char *id_vec[]) 
{ 
gint i=0; 
	for (i = 0; id_vec[i]; ++i); 
	return i;
} 

/* binds @servant object reference to unique @name at
 * @name_service. If error occures @ev points to exception object on
 * return.
 */
void 
etk_name_service_bind (CosNaming_NamingContext  name_service,
		       CORBA_Object             servant,
		       gchar                   *id_vec[], 
		       CORBA_Environment       *ev)
{
gint i = 0;
gint len = id_vec_len (id_vec);

	/* Allocate a CosNaming::Name (sequence of CosNaming::NameComponent) */
	CosNaming_Name *name = CosNaming_Name__alloc();

	name->_buffer = CORBA_sequence_CosNaming_NameComponent_allocbuf(len);
	name->_maximum = len;
	name->_length  = 0;
	
	/* Relinquish ownership of the NameComponent to the
         * sequence. When CORBA_free is called on it later, the
         * NameComponent will be freed */	
	CORBA_sequence_set_release (name, TRUE);

	/* iterate components of name and create sub-context
	 * (directory) if needed */ 
	for (i = 0; i < len; ++i) {
		name->_length = i+1;
		name->_buffer[i].id   = CORBA_string_dup(id_vec[i]);
		name->_buffer[i].kind = CORBA_string_dup(""); 
		/* don't know what 'kind' shall be good for */ 

		if (name->_length < len) {
			/* create a sub-context */ 
			CosNaming_NamingContext nc = 
				CosNaming_NamingContext_bind_new_context (name_service, 
									  name, ev);	
			if (etk_raised_exception_is_a (ev, 
						       ex_CosNaming_NamingContext_AlreadyBound))
			{
				/* ignore - ctx allread exists, this
				 * is not dramatic */
				CORBA_exception_free (ev);
			} else if (etk_raised_exception (ev)) {
				/* critical - unexpected exception  */ 
				CORBA_free (name); 
				return;
			}
		} else {
			/* Bind object to last context - use 'rebind'
			 * operation in case the name has been
			 * registered allready in context - note, this
			 * might interfere with other service choosing
			 * same name */ 
			CosNaming_NamingContext_rebind (name_service, 
							name, 
							servant,
							ev);
			if (etk_raised_exception(ev)) {
				/* critical - can not bind object */ 
				CORBA_free (name);
				return;
			}
		}
	}

	CORBA_free (name);
	return;
}

CORBA_Object 
etk_name_service_resolve (CosNaming_NamingContext  name_service,
			  gchar                   *id_vec[], 
			  CORBA_Environment       *ev)
{
	CORBA_Object retval = CORBA_OBJECT_NIL;
	gint i = 0;
	gint len = id_vec_len (id_vec);

	/* Allocate a CosNaming::Name (sequence of CosNaming::NameComponent) */
	CosNaming_Name *name = CosNaming_Name__alloc();

	g_assert (id_vec_len (id_vec) > 0);

	name->_buffer = CORBA_sequence_CosNaming_NameComponent_allocbuf(len);
	name->_maximum = len;
	name->_length  = 0;
	
	/* Relinquish ownership of the NameComponent to the
         * sequence. When CORBA_free is called on it later, the
         * NameComponent will be freed */	
	CORBA_sequence_set_release (name, TRUE);

	/* iterate components of name and create sub-context
	 * (directory) if needed */ 
	for (i = 0; i < len; ++i) {
		name->_length = i+1;
		name->_buffer[i].id   = CORBA_string_dup(id_vec[i]);
		name->_buffer[i].kind = CORBA_string_dup(""); 
		/* don't know what 'kind' shall be good for */ 
	}
	
	retval = CosNaming_NamingContext_resolve (name_service, 
						  name, 
						  ev);
	
	if (etk_raised_exception (ev)) { 
		CORBA_free (name);
		return CORBA_OBJECT_NIL;
	}
	
	return retval;
}











//------------ end utility functions from exaples-toolkit.c --------



#endif //__CAPI__

/*
missing in server exec:

`impl_SQLPARSE__create'
`CORBA_ORB_destroy'
`server_activate_service'
`g_ascii_isspace'
`CosNaming_Name__alloc'
`CORBA_sequence_CosNaming_NameComponent_allocbuf'
`CosNaming_NamingContext_bind_new_context'
`CosNaming_NamingContext_rebind'
`CosNaming_NamingContext_resolve'
*/


// ---------------------------------- EOF ---------------------------------
