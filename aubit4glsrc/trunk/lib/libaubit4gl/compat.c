// This is just for compatibility with informix(tm) 4GL
#include "a4gl_libaubit4gl_int.h"

/* Prototypes for functions in here should be added to a4gl_incl_infx.h      */
/* Any C programs using these functions should also include a4gl_incl_infx.h */
#include "a4gl_incl_infx.h"


void popint(int *s) {
	int a;
	a=pop_int();
	*s=(a&0xffff);
	
}

void popquote(char *s,int size) {
	pop_char(s,size);
}


void retquote(char *s) {
	push_char(s);
}


void pushint(int a ) {
	push_int(a);
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


void retlong(long a) {
	push_long(a);
}

void strip(char *s) {
	trim(s);
}
