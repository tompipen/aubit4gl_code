/**
 * @file
 * This is just for compatibility with informix(tm) 4GL.
 *
 * @FIXME : This does not work anymore with C compiled using Informix because 
 * this functions now are macros.
 *
 */
#include "a4gl_libaubit4gl_int.h"

/* Prototypes for functions in here should be added to a4gl_incl_infx.h      */
/* Any C programs using these functions should also include a4gl_incl_infx.h */
#include "a4gl_incl_infx.h"

void trim(char *s);
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
retlong (long x)
{
	A4GL_debug("retlong  %d\n",x);
  A4GL_push_long (x);
}

void
pushquote (char *s, int n)
{
  char *ptr;
  ptr = malloc (n + 1);
  strncpy (ptr, s, n);
  ptr[n] = 0;
  A4GL_push_char (ptr);
  free (ptr);
}




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
