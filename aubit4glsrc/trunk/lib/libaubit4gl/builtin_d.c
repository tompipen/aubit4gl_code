/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-1 Aubit Development Team (See Credits file)       |
# +----------------------------------------------------------------------+
# | This program is free software; you can redistribute it and/or modify |
# | it under the terms of one of the following licenses:                 |
# |                                                                      |
# |  A) the GNU General Public License as published by the Free Software |
# |     Foundation; either version 2 of the License, or (at your option) |
# |     any later version.                                               |
# |                                                                      |
# |  B) the Aubit License as published by the Aubit Development Team and |
# |     included in the distribution in the file: LICENSE                |
# |                                                                      |
# | This program is distributed in the hope that it will be useful,      |
# | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
# | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
# | GNU General Public License for more details.                         |
# |                                                                      |
# | You should have received a copy of both licenses referred to here.   |
# | If you did not, or have any questions about Aubit licensing, please  |
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: builtin_d.c,v 1.3 2002-05-17 07:08:33 afalout Exp $
#
*/

/**
 * @file
 * Built in functions of x4gl.
 *
 * Contains functions for
 *   - Pushing and poping values from / for functions
 *   - Builtin implemented functions
 *
 *
 * @todo Add Doxygen comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 * @todo -Wmissig-prototypes
 * @todo -Wstrict-prototypes
 * @todo -Wall
 * @todo -pedantic
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include <math.h>
#include <sys/types.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
//#include <unistd.h>
//#include <pwd.h>


#include "a4gl_dbform.h"
#include "a4gl_dates.h"
#include "a4gl_constats.h"
#include "a4gl_stack.h"
#include "a4gl_dtypes.h"
#include "a4gl_debug.h"
#include "a4gl_aubit_lib.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

/* #define DIGIT_ALIGN_LEFT */
extern int errno;

/**
 * Structure that describes the functions used.
 */
struct s_funcs {
	char *fname;    /**< The function name */
	void (*func)(); /**< Pointer to the function too execute */
	int nin;        /**< Number of input parameters */
	int nout;       /**< NUmber of values returned */
};

struct s_funcs builtin_funcs[]= {
/*
	{"today",push_today,0,1},
	{"user",push_user,0,1},
	{"mdy",func_mdy,3,1},
	{"hex",func_hex,1,1},
	{"abs",func_abs,1,1},
	{"mod",func_mod,2,1},
	{"pow",func_pow,2,1},
	{"root",func_root,2,1},
	{"sqrt",func_sqrt,1,1},
	{"trunc",func_trunc,1,1},
	{"round",func_round,1,1},
	{"exp",func_exp,2,1},
	{"logn",func_logn,2,1},
	{"log10",func_log10,1,1},
	{"length",func_length,1,1},
	{"date",func_date,1,1},
	{"day",func_day,1,1},
	{"month",aclfgl_month,1,1},
	{"weekday",c_weekday,1,1},
	{"year",func_year,1,1},
	{"using",func_using,2,1},
	{"clip",func_clip,1,1},
	{"concat",func_concat,2,1},
	{"",0,0,0}
*/
		{"",0,0,0}
};


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

extern char *using_date(int us,char *fmt);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Called at run-time by the generated C code.
 * Its used to push an int to the parameters stack.
 *
 * @param p The integer value to be pushed to the stack
 */
void 
push_int(int p)
{
	int *ptr;
	ptr=(int *)acl_malloc(sizeof(int),"push int");
	*ptr=p;
	push_param(ptr,DTYPE_SMINT+DTYPE_MALLOCED);
}

/**
 * Called at run-time by the generated C code.
 * Its used to push an long to the parameters stack.
 *
 * @param p The long value to be pushed to the stack
 */
void
push_long(long p)
{
	long *ptr;
	ptr=(long *)acl_malloc(sizeof(long),"push long");
	*ptr=p;
	push_param(ptr,DTYPE_INT+DTYPE_MALLOCED);
}

/**
 * Called at run-time by the generated C code.
 * Its used to push a date (long because of julian) to the parameters stack.
 *
 * @param p The date value to be pushed to the stack
 */
void 
push_date(long p)
{
	long *ptr;
	ptr=(long *)acl_malloc(sizeof(long),"push_date");
	*ptr=p;
	push_param(ptr,DTYPE_DATE+DTYPE_MALLOCED);
}

/**
 * Called at run-time by the generated C code.
 * Its used to push a byte (identified by a void ptr) to the parameters stack.
 *
 * @param ptr A pointer to the byte stream to be pushed
 */
void
push_byte(void *ptr) 
{
	//void *p2;
	//p2=acl_malloc(sizeof(struct fgl_int_loc),"push_byte");
	//memcpy(p2,ptr,sizeof(struct fgl_int_loc));
	push_param(ptr,DTYPE_BYTE+ENCODE_SIZE(sizeof(struct fgl_int_loc)));
}
	
/**
 * Called at run-time by the generated C code.
 * Its used to push a float to the parameters stack.
 *
 * @param p The float value to be pushed to the stack
 */
void
push_float(float p)
{
	float *ptr;
	ptr=(float *)acl_malloc(sizeof(float),"push float");
	*ptr=p;
	push_param(ptr,DTYPE_SMFLOAT+DTYPE_MALLOCED);
}

/**
 * Called at run-time by the generated C code.
 * Its used to push a decimal value to the parameters stack.
 *
 * @param p A pointer to a char containing the decimal value in the string 
 * @param ismoney Flag that identifies if the decimal to be pusshed is money:
 *   - 0 : Its not money
 *   - Otherwise : Its money
 */
void 
push_dec(char *p,int ismoney)
{
  char *ptr;
  ptr=(char *)acl_malloc(p[0]+2,"push dec");
  memcpy(ptr,p,p[0]+2);
  if (ismoney) {
    push_param(ptr,DTYPE_MONEY+DTYPE_MALLOCED);
  }
  else {
    push_param(ptr,DTYPE_DECIMAL+DTYPE_MALLOCED);
  }
}


/**
 * Called at run-time by the generated C code.
 * Its used to push a double to the parameters stack.
 *
 * @param p The double value to be pushed to the stack
 */
void 
push_double(double p)
{
	double *ptr;
	ptr=(double *)acl_malloc(sizeof(double),"push_double");
	*ptr=p;
	#ifdef DEBUG
	/* {DEBUG} */ {        debug("Push_double %lf\n",p);}
	#endif
	push_param(ptr,DTYPE_FLOAT+DTYPE_MALLOCED);
}

/**
 * Called at run-time by the generated C code.
 * Its used to push a string to the parameter stack
 *
 * @param p A pointer to the string containing the characters
 * @param dtype Not Used
 * @param size The size of the string
 */
void 
push_chars(char * p,int dtype,int size)
{
	char *ptr;
	debug("In push_chars\n");
	ptr=(char *)new_string_set(strlen(p),p);
	push_param(ptr,(DTYPE_CHAR+DTYPE_MALLOCED+ENCODE_SIZE(size)));
}

/**
 * Called at run-time by the generated C code.
 * Its used to push a char string to the parameters stack.
 * All the string until the null terminated is pushed.
 *
 * @param p The string value to be pushed to the stack
 */
void
push_char(char * p)
{
	char *ptr;
	if (p[0]==0&&p[1]!=0) {
		ptr=(char *)new_string_set(strlen(p)+1,p);
		ptr[0]=0;
		ptr[1]=1;
	} else {
		ptr=(char *)new_string_set(strlen(p),p);
	}
	push_param(ptr,(DTYPE_CHAR+DTYPE_MALLOCED+ENCODE_SIZE(strlen(p))));
}

/**
 * Pop(s) the year, day and month from the stack, convert it into julian
 * and pushes this value to the stack.
 *
 * Used for MDY 4GL function!
 */
 void 
 aclfgl_mdy(void)
{
  int m,d,y;
  long z;
  y=pop_int();
  d=pop_int();
  m=pop_int();
  z=gen_dateno(d,m,y);
  push_date(z);
}

/**
 * Pops a long value from the stack, convert it to an hexadecimal string and
 * push it to the stack
 *
 * Used for 4GL HEX function
 */
void 
aclfgl_hex(void)
{
  long z;
  char buff[100];
  z=pop_long();
  sprintf(buff,"0x%x",(int)z);  // warning: unsigned int format, long unsigned int arg (arg 3)
  push_char(buff);
}

/**
 * Pops a long value from the stack, gets the absolute values and 
 * push it to the stack.
 *
 * Used for 4GL ABS function.
 */
void 
aclfgl_abs(void) 
{
	double p;
	p=pop_double();
	if (p<0) p=0-p;
	push_double(p);
}

/**
 * Pops a long value from the stack, gets the mod values and 
 * push it to the stack.
 *
 * Used for 4GL MOD function.
 *
 */
//static void  // warning: `func_mod' defined but not used
void
func_mod(void)

{
	long p;
	long p2;
	long res;


	p=pop_long();
	p2=pop_long();
	res=p2%p;
	push_long(res);
}

/**
 * Used for 4GL MOD function.
 *
 * Not implemented.
 *
 * @todo Understand if not used and if not remove it
 */
// static void //warning: `func_pow' defined but not used
void
func_pow(void)
{
	exitwith("Pow not implemented");
/*
	double p,p2,res;
	p=pop_double();
	p2=pop_double();
	res=pow(p2,p);
	push_double(res);
*/
}

/**
 *
 *
 * @todo Describe function
 */
void 
aclfgl_root(void)
{
	double p,p2,res;
	p=pop_double();
	p2=pop_double();
	p=1/p;
	res=pow(p2,p);
	push_double(res);
}

/**
 *
 *
 * @todo Describe function
 */
//static void // warning: `aclfgl_sqrt' defined but not used
void
aclfgl_sqrt(void)
{
	double p,p2,res;
	p2=pop_double();
	p=1/2;
	res=pow(p2,p);
	push_double(res);
}

/**
 *
 *
 * @todo Describe function
 */
//static void
void 
func_trunc(void)
{
	exitwith("trunc not implemented\n");
}

/**
 *
 *
 * @todo Describe function
 */
//static void
void
func_round(void)
{
	exitwith("round not implemented\n");
}

/**
 *
 *
 * @todo Describe function
 */
//static void
void
func_exp(void)
{
	exitwith("exp not implemented\n");
}

/**
 *
 *
 * @todo Describe function
 */
//static void
void
func_logn(void)  
{
	exitwith("logn not implemented\n");
}

/**
 *
 *
 * @todo Describe function
 */
//static void
void
func_log10(void)
{
	exitwith("log not implemented\n");
}

/**
 *
 *
 * @todo Describe function
 */
//static void
void
func_length(void)
{
	exitwith("length not implemented\n");
}


/**
 *
 *
 * @todo Describe function
 */
void 
aclfgl_date(void)
{
  long d;
  d=pop_date();
  push_date(d);
}

/**
 *
 *
 * @todo Describe function
 */
int 
aclfgl_day(void)
{
  long d;
  int day,mn,yr;
  d=pop_date();
  get_date(d,&day,&mn,&yr);
  push_int(day);
  return 1;
}

/**
 *
 *
 * @todo Describe function
 */
int 
aclfgl_month(void)
{
	long d;
	int day,mn,yr;
	d=pop_date();
	get_date(d,&day,&mn,&yr);
	push_int(mn);
	return 1;
}

/**
 *
 *
 * @todo Describe function
 */
int 
aclfgl_weekday(void)
{
	long d;
	int day,mn,yr;
	long d2;
	d=pop_date();
	get_date(d,&day,&mn,&yr);
	d2=day_in_week(day,mn,yr);
	push_long(d2);
	return 1;
}

/**
 *
 *
 * @todo Describe function
 */
int 
aclfgl_year(void)
{
	long d;
	int day,mn,yr;
	d=pop_date();
	get_date(d,&day,&mn,&yr);
	push_int(yr);
	return 1;
}

/**
 *
 *
 * @todo Describe function
 */
int
func_clip(void)
{
char *z;
	z=char_pop();
	trim(z);
	push_char(z);
	free(z);
	return 1;
}

/**
 *
 *
 * @todo Describe function
 */
void 
func_concat(void)
{
  char *z1;
  char *p1;
  char *p2;
  int a;
  #ifdef DEBUG
    /* {DEBUG} */ {debug("func_concat -> Pop-ing chars"); }
  #endif
  p1=char_pop();
  p2=char_pop();
  #ifdef DEBUG
    /* {DEBUG} */ {debug("   '%s' & '%s'",p1,p2); }
  #endif
  #ifdef DEBUG
    /* {DEBUG} */ {debug("   copy %d %d ",strlen(p1),strlen(p2)); }
  #endif
  a=strlen(p1)+strlen(p2)+1;
  z1=new_string(a);
  strcpy(z1,p2);
  strcat(z1,p1);
  #ifdef DEBUG
    /* {DEBUG} */ {debug("Freeing"); }
  #endif
  acl_free(p1);
  acl_free(p2);
  push_char(z1);
  #ifdef DEBUG
    /* {DEBUG} */ {debug("concat returns -> %s",z1); }
  #endif
}



/**
 *
 *
 * @todo Describe function
 */
double 
power(double a,double b)
{
	return 0;
}

/**
 *
 *
 * @todo Describe function
 */
void
func_using(void)
{
int s;
long d;
char *z;
char *fmt;
double a;
int f=0;

	fmt=char_pop();
	if (strstr(fmt,"dd")||strstr(fmt,"mm")||strstr(fmt,"yy")) f=1;
	if (f==0) 
	{
		#ifdef DEBUG
			{       debug("Number using");	}
		#endif
       pop_param(&a,DTYPE_FLOAT,0);
       trim(fmt);
       s=strlen(fmt);
       z=new_string(s);
       using(z,s,fmt,a);
       push_char(z);
	} else {
		d=pop_long();
		#ifdef DEBUG
			{debug("Date using...%ld (%s)",d,fmt);}
		#endif
		trim(fmt);
		push_char(using_date(d,fmt));
	}
	acl_free(fmt);
}


/***********************************************************************/
/*                          built in functions                         */
/***********************************************************************/

/**
 *
 *
 * @todo Describe function
 */
int 
find_function(char *a)
{
	int z;
	int found=0;
	for (z=0;builtin_funcs[z].fname[0]!=0;z++) {
		if (strcmp(a,builtin_funcs[z].fname)==0) {
			found=1;
			builtin_funcs[z].func();
			break;
		}
	}
	return found;
}


/**
 *
 *
 * @todo Describe function
 */
void 
push_dtime(struct a4gl_dtime *p)
{
        char *ptr;
        struct a4gl_dtime *d;
        ptr=(char *)acl_malloc(sizeof(struct a4gl_dtime),"push_dtime");
        d=(struct a4gl_dtime *)ptr;
        d->stime=p->stime;
        d->ltime=p->ltime;
        memcpy(d->data,p->data,32);
        debug("Pushing dtime block\n");
        push_param(ptr,DTYPE_DTIME+DTYPE_MALLOCED);
}

/**
 *
 *
 * @todo Describe function
 */
void 
push_interval(struct ival *p) 
{
        char *ptr;
        struct ival *d;
        ptr=(char *)acl_malloc(sizeof(struct ival),"push_ival");
        d=(struct ival *)ptr;
        d->stime=p->stime;
        d->ltime=p->ltime;
        memcpy(d->data,p->data,32);
        push_param(ptr,DTYPE_INTERVAL+DTYPE_MALLOCED);
} 

/**
 *
 *
 * @todo Describe function
 */
void 
push_variable(void *ptr,int dtype)
{
  debug("In push variable");
  if (isnull(dtype,ptr)) 
  {
    debug("In push variable... ptr is null");
  }
  else
  {
    debug("In push variable... ptr is not null");
  }

	#ifdef DEBUG
		{debug("Pushing variable %p dtype %d   %d",ptr,dtype&DTYPE_MASK,dtype); }
	#endif

	switch (dtype&DTYPE_MASK) 
	{
		case 0: push_chars(ptr,dtype,DECODE_SIZE(dtype));return;break;
		case 1: push_int(*(int *)ptr);return;break;
		case 2:
		debug("LONG");
		push_long(*(long *)ptr);return;break;
		case 6:
		debug("LONG");
		push_long(*(long *)ptr);return;break;
		case 7:
		debug("DATE");
		push_date(*(long *)ptr);return;break;
		case 3:
		debug("DOUBLE");
		push_double(*(double *)ptr);return;break;
		case 5:
		debug("DECIMAL");
		push_dec(ptr,0);return;break;
		case 8:
		debug("MONEY");
			push_dec(ptr,1);return;break;
		case 4: debug("FLOAT");
			 push_float(*(float *)ptr);return;break;
		case DTYPE_TEXT:
		case DTYPE_BYTE: push_byte(ptr); break;

		case DTYPE_DTIME:
		        debug("pushing dtime");
		        push_dtime(ptr);
		        return;
		case DTYPE_INTERVAL:
		        push_interval(ptr);
		        return;
	}

	debug("Couldnt process datatype %x",dtype);
	//exitwith("Internal Error : Couldnt process datatype %x\n",dtype);  too many arguments to function `exitwith'
    exitwith("Internal Error : Couldnt process datatype \n");


}


// ============================== EOF ===============================

