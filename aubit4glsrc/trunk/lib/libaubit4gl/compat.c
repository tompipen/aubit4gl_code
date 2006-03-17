/**
 * @file
 * This is just for compatibility with informix(tm) 4GL.
 *
 * @FIXME : This does not work anymore with C compiled using Informix because 
 * this functions now are macros.  <--- THIS IS WHEN USING THE INFORMIX SUPPLIED HEADER FILE ?
 *
 */
#include "a4gl_libaubit4gl_int.h"


void popdate (long *x);
void retdate (long x);

void popdec_aubit (fgldecimal *x) ;
//fgldecimal * A4GL_str_to_dec (char *str, fgldecimal *dec) ;



/* Prototypes for functions in here should be added to a4gl_incl_infx.h      */
/* Any C programs using these functions should also include a4gl_incl_infx.h */
#include "a4gl_incl_infx.h"

void trim(char *s);
void popflo (float *s);
void retdec_aubit (fgldecimal *x);
//void rsetnull(int d,void *ptr);

int fgl_getkey() {
  return aclfgl_fgl_getkey(-1);
}

void trim(char *s) {
	A4GL_trim(s);
}


void
popint (int *s)
{
  int a;

  a = A4GL_pop_long ();
  *s = (a );
A4GL_debug("popint returning %d\n",*s);
}

void
popdub (double *s)
{
  double a;
  a = A4GL_pop_double ();
  *s = a;

}

void
popflo (float *s)
{
  float a;
  a = A4GL_pop_float ();
  *s = a;
}


void
popquote (char *s, int size)
{
  A4GL_pop_char (s, size-1); // Informix takes includes the terminator in this size, aubit doesn't
}

void
popstring (char *s, int size)
{
  A4GL_pop_char (s, size-1);
}

void
retquote (char *s)
{
  A4GL_push_char (s);
}


void
pushint (int a)
{
	A4GL_debug("pushint  got %d\n",a);
  A4GL_push_long (a);
}

void
retint (int a)
{
	A4GL_debug("retint  %d\n",a);
  A4GL_push_long (a);
}

void
pushshort (short a)
{
	A4GL_debug("push_short  %d\n",a);
  A4GL_push_int (a & 0xffff);
}

void
pushlong (long a)
{
	A4GL_debug("push_long  %d\n",a);
  A4GL_push_long (a);
}

void
popvchar (char *x, int y)
{
  A4GL_pop_char (x, y-1);
}

void
retdub (double *x)
{
  A4GL_push_double (*x);
}



void
retflo (float *a)
{
  float b;
  b = *a;
  A4GL_push_float (b);

}

void retdec_aubit (fgldecimal *x) {
char *ptr;
int size;
#define NUM_DIG(x)               ((x[0])&127 )
#define NUM_DEC(x)               ((x[1]))
#define NUM_BYTES(x)     (NUM_DIG(x)+OFFSET_DEC(x))
ptr=(char *)x;
	size=(NUM_DIG(ptr)<<8);
	size+=NUM_DEC(ptr);
	A4GL_push_dec((void *)x,0,size);
}



//void rsetnull(int d,void *ptr) {
//      setnull(d,ptr,0);
//}



void
A4GL_strip (char *s)
{
  A4GL_trim (s);
}


void
retshort (short x)
{
	A4GL_debug("retshort  %d\n",x);
  A4GL_push_int (x & 0xffff);
}

void
poplong (long *x)
{
  long a;
  a = A4GL_pop_long ();
  *x = a;
	A4GL_debug("poplong  %d\n",*x);
}

void
popdate (long *x)
{
  long a;
  a = A4GL_pop_date ();
  *x = a;
	A4GL_debug("popdate  %d\n",*x);
}

void
retlong (long x)
{
	A4GL_debug("retlong  %d\n",x);
  A4GL_push_long (x);
}

void retdate (long x)
{
	A4GL_debug("retdate  %d\n",x);
  A4GL_push_date (x);
}

void
pushquote (char *s, int n)
{
  char *ptr;
  ptr = acl_malloc2 (n + 1);
  strncpy (ptr, s, n);
  ptr[n] = 0;
  A4GL_push_char (ptr);
  free (ptr);
}


void popdec_aubit (fgldecimal *x) {
	char *ptr;
	char *eptr;
	ptr=A4GL_char_pop();
	eptr=(char *)A4GL_str_to_dec (ptr, x);
	free(ptr);
}


/* this funcs are used in API_esql.spec as
	popdec_native void* vx -> void
	retdec_native void* vx -> void
	popdtime_native void* vx -> void
	retdtime_native void* vx -> void
	
	defined in helper_funcs.ec
	
	no code in Aubit makes calls to this functions in any form:
	(popdtime or popdtime_native or ESQLAPI_popdtime_native)
	so it seems only legacy C code functions used with I-4GL would need it.
	
	Since only header file with this purpose we have is incl/compat/decimal.h
	which we cant include here (because it would conflict with Aubit internals)
	I will declare prototypes here, and let user worry about prototypes for his 
	own C code.
	
	Note: prototypes for ESQLAPI_xxx_native() and xxxx_native() 
	are in generated a4gl_API_esql.h so we will include it here
*/

#include "a4gl_API_esql.h"
//void popdtime(void* vx);
//void retdtime(void* vx);
//void retdec(void* vx);
//void popdec(void* vx);

void popdtime(void* vx) { popdtime_native(vx); }
void retdtime(void* vx) { retdtime_native(vx); }
void retdec(void* vx)   { retdec_native(vx); }
void popdec(void* vx)   { popdec_native(vx); }


void
popshort (short *x)
{
  int a;
  a = A4GL_pop_int ();
  *x = a & 0xffff;
	A4GL_debug("popshort  %d\n",*x);
}


void
retstring (char *s)
{
  A4GL_push_char (s);
}

int rgetkey() {
  return A4GL_get_key(-1);
}

/*
int rdayofweek(int n) {
  int day, mn, yr;
  long d2;
  A4GL_get_date (n, &day, &mn, &yr);
  d2 = A4GL_day_in_week (day, mn, yr);
  return d2;

}
*/
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


void fgl_fatal(char *mod,long ln,long stat) {
	A4GL_fgl_error (ln, mod, stat, stat);
}

int fgl_call( int (*func_ptr) (int),int n) {
	return func_ptr(n);
}

void popdate_native(void *x) {
	long a4gl;
	short indic;
	a4gl=A4GL_pop_date();
	if (A4GL_isnull(DTYPE_DATE,(void *)&a4gl)) {
		indic=-1;
	} else {
		indic=0;
	}
	A4GL_copy_date(x,(void *)&a4gl,&indic,4,'i');
}


void retdate_native(void *x,short indic) {
	long a4gl;

	if (A4GL_isnull(DTYPE_DATE,(void *)&x)) {
		indic=-1;
	} else {
		indic=0;
	}
	
	A4GL_copy_date(x,(void *)&a4gl,&indic,4,'o');

	A4GL_push_date(a4gl);
}



int pushlocator(void *x) {
		A4GL_assertion(1,"push_locator not implemented");
		return 0;
}

int _locate(void*b,int x,int y,char *z) {
		A4GL_assertion(1,"_locate not implemented");
		return 0;
}
