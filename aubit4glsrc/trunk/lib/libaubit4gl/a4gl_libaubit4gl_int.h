/**
 * @file
 *
 * Definition of structures and typedefs necessary
 * for the libaubit4gl library.
 * Definitipns Internal to library (not needed outside of it)
 */

#ifndef _AUBIT_LIB_INCL_INT_
#define _AUBIT_LIB_INCL_INT_

	#include "a4gl_libaubit4gl.h" /* external one */
    
	/* =================== from data_if.h =================== */

	#define GETSETNEW 		-1
	#define GETSETRM 		-2
	#define GETSETGET 		1
	#define GETSETSET 		2
	#define GETSETGETPTR 	3

	#define GETPTR(struct,ptr,element) get_set(struct,ptr,GETSETGETPTR,element,0)
	#define GET(struct,ptr,element) get_set(struct,ptr,GETSETGET,element,0)
	#define SET(struct,ptr,element,value) get_set(struct,ptr,GETSETSET,element,(long)value)
	#define NEW(struct) get_set(struct,0,GETSETNEW,0,0)
	#define RM(struct,ptr) get_set(struct,ptr,GETSETRM,0,0)


	#if HAVE_ERRNO_H
		#include <errno.h>
	#endif

	int dlclose(void *);
#endif /* #ifndef _AUBIT_LIB_INCL_INT_ */


/* ========================== EOF ====================================== */

