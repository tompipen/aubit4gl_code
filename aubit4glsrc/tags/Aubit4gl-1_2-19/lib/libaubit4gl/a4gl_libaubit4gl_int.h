/**
 * @file
 *
 * Definition of structures and typedefs necessary
 * for the libaubit4gl library.
 * Definitipns Internal to library (not needed outside of it)
 */

#ifndef _AUBIT_LIB_INCL_INT_
	#define _AUBIT_LIB_INCL_INT_
	
	#include "a4gl_libaubit4gl.h"	/* external one */
	
	#define GETSETNEW 		-1
	#define GETSETRM 		-2
	#define GETSETGET 		1
	#define GETSETSET 		2
	#define GETSETGETPTR 	3
	
	#if HAVE_ERRNO_H
		#include <errno.h>
	#endif
	
	int A4GL_dlclose (void *);
	
	/* Prototypes from funcs_d.c */
	char *a_strchr(char *s,int c);
	
	
	/* Prototypes from compat.c */
	int fgl_getkey(void);
	void popdub (double *s);
	int rgetkey(void);
	int A4GL_apm_str_detect_overflow(char *s1, char *s2,int op,int overflow_dtype);
	/* Prototypes from builtin.c */
	int aclfgl_fgl_getkey(int n) ;
	int aclfgl_fgl_getkey_wait(int n) ;
	//char *A4GL_strcpy(char *d,char *s,char *fname,int l,int sdest);
	
	/* Most of the time sizeof(d) will be 4 (size of a pointer) - */
	/* but sometimes it'll be useful... */
	//#define strcpy(d,s) A4GL_strcpy(d,s,__FILE__,__LINE__,(long)sizeof(d))
	//#define strcat(d,s) A4GL_strcat(d,s,__FILE__,__LINE__,(long)sizeof(d))
void add_base_channel_support(void) ;
void add_ui_interface_support(void) ;
void add_ui_window_support(void) ;
void add_ui_combobox_support(void) ;
void add_ui_curses_support(void);
void add_dyn_support(void) ;
char *getSigForTopOfStack(int numberOfObjectsOnStack) ;
struct s_save_binding {
        struct BINDING *b;
        int nbind;
};
struct sObject *new_object(char *type) ;
int getObject(long objectId, struct sObject **o,char *preferredObjectType) ;
int ensureObject(char *type,long objectId, struct sObject **o) ;
void A4GL_push_objectID (long p);
void A4GL_object_dispose(long objectId);
void A4GL_add_object_type(char *s);
void A4GL_set_setdtype (int dtype, void *ptr);
void A4GL_clear_current_conversion_rules(void);
#endif /* #ifndef _AUBIT_LIB_INCL_INT_ */


/* ========================== EOF ====================================== */
