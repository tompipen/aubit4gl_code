// This is just for compatibility with informix(tm) 4GL
#include "a4gl_libaubit4gl_int.h"

/* Prototypes for functions in here should be added to a4gl_incl_infx.h      */
/* Any C programs using these functions should also include a4gl_incl_infx.h */
#include "a4gl_incl_infx.h"

//void rsetnull(int d,void *ptr);


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

void pushshort(short a) {
	push_int(a&0xffff);
}

void pushlong(long a) {
	push_long(a);
}

void popvchar(char *x,int y) {
	pop_char(x,y);
}

void retdub(double x) {
	push_double(x);
}



void retflo(float *a) {
	float b;
	b=*a;
	push_float(b);

}


//void rsetnull(int d,void *ptr) {
//	setnull(d,ptr,0);
//}



void strip(char *s) {
	trim(s);
}


void retshort(short x) {
	push_int(x&0xffff);
}

void poplong(long *x) {
long a;
	a=pop_long();
	*x=a;
}

void retlong(long x) {
	push_long(x);
}

void pushquote(char *s,int n) {
	char *ptr;
	ptr=malloc(n+1);
	strncpy(ptr,s,n);
	ptr[n]=0;
	push_char(ptr);
	free(ptr);
}




void popshort(short *x) {
	int a;
	a=pop_int();
	*x=a&0xffff;
}


void retstring(char *s) {
	push_char(s);
}

/*
popbool(x)   
popshort(x) 
poplong(x) 
popdate(x)  
popdub(x)  
popflo(x)  
popdec(x)  
popdecvar(x, y) 
popmon(x)       
popmonvar(x, y)  
popstring(x, y)  
popvchar(x, y)   
poplocator(x)    
popdtime(x, y)   
popinv(x, y)    
pushnull() 
pushshort(x) 
pushlong(x)  
pushdate(x)  
pushmoney(x, y)
pushflo(x)    
pushdub(x)   
pushstrdec(x) 
pushlvqs(x, y, z) 
pushquote(x, y)  
pushvchar(x, y) 
pushdec(x, y)  
pushdtstr(x, y) 
pushivstr(x, y) 
pushlocator(x) 
pushdtime(x)  
pushinv(x)   
retshort(x)
retdate(x)
retdub(x)  
retquote(x) 
retstring(x)
retdec(x)  
retdtime(x)
retinv(x)  
retvchar(x)
retmoney(x)
retmon(x) 
*/
