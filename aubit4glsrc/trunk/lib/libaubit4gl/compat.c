// This is just for compatibility with informix(tm) 4GL
#include "a4gl_libaubit4gl_int.h"

/* Prototypes for functions in here should be added to a4gl_incl_infx.h      */
/* Any C programs using these functions should also include a4gl_incl_infx.h */
#include "a4gl_incl_infx.h"

void popquote(char *s,int size) {
	pop_char(s,size);
}


void retquote(char *s) {
	push_char(s);
}

void retint(int a) {
	push_int(a);
}

void retflo(float *a) {
	float b;
	b=*a;
	push_float(b);

}


void rsetnull(int d,void *ptr) {
	setnull(d,ptr,0);
}
