#include "a4gl_libaubit4gl.h"

//should we use xgen created header here instead?
//try it:  (in common/dataio)
#ifndef _USE_RPCGEN_HEADERS_
	#include "menu_x.xs.h" //seems to work OK
#else
	#include "menu_x.h"
#endif
