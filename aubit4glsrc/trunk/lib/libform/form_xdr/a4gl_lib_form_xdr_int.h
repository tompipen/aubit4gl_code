
	#ifdef __CYGWIN__
	    /* missing from rpcgen generated form_x.h on CygWin: */
		#define bool_t int
		#define u_int unsigned int


		#include <rpc/rpc.h>

	#endif



//prevent form_x.xs.h from including from form_x.x.h
#define  _NO_FORM_X_H_

/* We don't want the xgen .h file we want the
   XDR/rpcgen one instead
*/
#define USE_XDR_H


#include "a4gl_lib_form_int.h"

/* Most of the time we'll want to use the xgen generated .h file - not the rpcgen one */
#ifndef USE_XDR_H
	#include "../../../common/dataio/form_x.x.h"
#else
	#include "../../../common/dataio/form_x.h"
#endif

#ifdef __CYGWIN__
	dll_import struct struct_form the_form;
#else
	extern struct struct_form the_form;
#endif

