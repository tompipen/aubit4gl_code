// This is just for compatibility with informix(tm) 4GL
#include "a4gl_libaubit4gl_int.h"


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
