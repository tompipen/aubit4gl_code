
#ifdef __CYGWIN__
#include <rpc/rpc.h>
#endif

//prevent form_x.xs.h from including from form_x.x.h
#define  _NO_FORM_X_H_

#include "a4gl_lib_form_int.h"

dll_import struct struct_form the_form;

/* 
	We don't want the xgen .h file we want the XDR/rpcgen one instead
	Most of the time we'll want to use the xgen generated .h file - not the rpcgen one
*/
#define USE_XDR_H
#ifndef USE_XDR_H
#include "../../../common/dataio/form_x.x.h"
#else
#include "../../../common/dataio/form_x.h"
#endif
