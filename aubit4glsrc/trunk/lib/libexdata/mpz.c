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
# $Id: mpz.c,v 1.8 2002-09-26 11:30:15 afalout Exp $
*/

/**
 * @file
 *
 * Mechanism whereby datatypes can be added to the 4GL language.
 * The mpz datatype is a arbitrary precision integer datatype that can handle
 * very very large numbers.
 *
 * API is in lib/libaubit4gl/datatypes.c (to rename to API_exdata.c)
 *
 * See example testmpz.4gl into the tools/test directory.
 *
 */

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#define _NO_FORM_X_H_
#define MPZ_DTYPE_NAME "MPZ"

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_lib_exdata_mpz_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/


/* Just implement mpz for now (large integers) */
int dtype_mpz=0;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


char * 	include_mpz			(void);
char * 	pr_mpz				(void);
void 	init_mpz			(mpz_t *mpz);
int 	a4gl_mpz_setfib		(mpz_t *ptr,int nparam);
int 	a4gl_mpz_nextprime	(mpz_t *ptr,int nparam);
void * 	mpz_alloc			(void);
int 	mpz_from_double 	(double *n,mpz_t *mpz,int szignore);
int 	mpz_from_int 		(long *n,mpz_t *mpz,int szignore);
int		mpz_from_mpz 		(mpz_t *n,mpz_t *mpz,int szignore);
int 	mpz_from_str 		(char *n,mpz_t *mpz,int szignore);
int 	mpz_to_double 		(mpz_t *mpz,double *n,int szignore);
int 	mpz_to_int 			(mpz_t *mpz,long *n,int szignore);
int 	mpz_to_mpz 			(mpz_t *mpz,mpz_t *n,int szignore);
char * 	mpz_str 			(mpz_t *mpz,char *n,int sz);
int 	mpz_to_str 			(mpz_t *mpz,char *n,int sz);
void 	add_mpz				(void);
void 	sub_mpz				(void);
void 	mul_mpz				(void);
void 	pow_mpz				(void);
void 	div_mpz				(void);
void 	mod_mpz				(void);
int 	compare_mpz			(void);
void 	gt_mpz				(void);
void 	gte_mpz				(void);
void 	lt_mpz				(void);
void 	lte_mpz				(void);
void 	e_mpz				(void);
void 	ne_mpz				(void);
void 	mpz_free			(void *ptr);
mpz_t * mpz_copy			(mpz_t *a1);
int 	isnull_mpz			(void);
void 	EXDTYPE_initlib		(void);




/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 *
 *
 * @todo : Describe function
 */
char *
include_mpz(void)
{

	/* 
	FIXME
	 Should really check the language type before printing
	*/
	return "gmp";
}


/**
 *
 *
 * @todo : Describe function
 */
char *
pr_mpz(void)
{
    /*
	FIXME...
	Should really check the language type before printing
    */

	return "mpz_t ";
}

/**
 *
 *
 * @todo : Describe function
 */
void
init_mpz(mpz_t *mpz)
{
	mpz_init(*mpz);
}




/**
 * This is an example of an 'Inplace' function, nothing is pushed onto the stack
 *
 * @todo : Describe function
 */
int
a4gl_mpz_setfib(mpz_t *ptr,int nparam)
{
/*	static mpz_t pout; */
	unsigned long a;
	a=pop_int();

	debug("mpz_setfib ptr=%p nparam=%d a=%d\n",ptr,nparam,a);
	mpz_init(*ptr);
	mpz_fib_ui(*ptr,a);

	return 0;
}


/**
 * This is an example of a stack function - the value is returned onto the
 * stack to be pop'd off using a 'returning' clause
 *
 * @todo : Describe function
 */
int
a4gl_mpz_nextprime(mpz_t *ptr,int nparam)
{
	static mpz_t pout;
	debug("ptr=%p nparam=%d\n",ptr,nparam);
	mpz_init(pout);
	mpz_nextprime(pout,*ptr);
	push_variable(&pout,dtype_mpz);
	return 1;
}




/**
 *
 *
 * @todo : Describe function
 */
void *
mpz_alloc(void)
{
mpz_t *ptr;
	ptr=(mpz_t *)malloc(sizeof(mpz_t));
	mpz_init(*ptr);
	return ptr;
}


/**
 *
 *
 * @todo : Describe function
 */
int
mpz_from_double (double *n,mpz_t *mpz,int szignore)
{
	debug("mpz_from_double");
	mpz_init(*mpz);
	mpz_set_d(*mpz,*n);
	return 1;
}

/**
 *
 *
 * @todo : Describe function
 */
int
mpz_from_int (long *n,mpz_t *mpz,int szignore)
{
	debug("mpz_from_int");
	mpz_init(*mpz);
	mpz_set_si(*mpz,*n);
	return 1;
}

/**
 *
 *
 * @todo : Describe function
 */
int
mpz_from_mpz (mpz_t *n,mpz_t *mpz,int szignore)
{
	debug("mpz_from_mpz");
	mpz_init(*mpz);
	mpz_set(*mpz,*n);
	return 1;
}

/**
 *
 *
 * @todo : Describe function
 */
int
mpz_from_str (char *n,mpz_t *mpz,int szignore)
{
	debug("mpz_from_str");
	mpz_init(*mpz);
	mpz_set_str(*mpz,n,0);
	return 1;

}

/**
 *
 *
 * @todo : Describe function
 */
int
mpz_to_double (mpz_t *mpz,double *n,int szignore)
{
	debug("mpz_to_double");
	*n=mpz_get_d(*mpz);
	return 1;
}

/**
 *
 *
 * @todo : Describe function
 */
int
mpz_to_int (mpz_t *mpz,long *n,int szignore)
{
	debug("%p %p (%d %d)\n",mpz,n,*(long *)mpz,*(long *)n);
	debug("mpz_to_int");
	*n=mpz_get_si(*mpz);
	return 1;
}

/**
 *
 *
 * @todo : Describe function
 */
int
mpz_to_mpz (mpz_t *mpz,mpz_t *n,int szignore)
{
	debug("mpz_to_mpz");
	mpz_set(*mpz,*n);
	return 1;
}


/**
 *
 *
 * @todo : Describe function
 */
char *
mpz_str (mpz_t *mpz,char *n,int sz)
{
	debug("mpz_str");
	return mpz_get_str(n,10,*mpz);
}

/**
 *
 *
 * @todo : Describe function
 */
int
mpz_to_str (mpz_t *mpz,char *n,int sz)
{
	char *ptr;
	debug("mpz_to_str");

	ptr=mpz_get_str(0,10,*mpz);
	if (strlen(ptr)>sz) {
		free(ptr);
		return 0;
	} else {
		memset(n,' ',sz);
		n[sz-1]=0;
		n[sz-strlen(ptr)]=0;
		strcat(n,ptr);
	}
	return 1;
}

/**
 *
 *
 * @todo : Describe function
 */
void
add_mpz(void)
{
	mpz_t a1;
	mpz_t a2;
	mpz_t *ptr;
	ptr=malloc(sizeof(mpz_t));
	debug("add_mpz");
	pop_param(&a2,dtype_mpz,0);
	pop_param(&a1,dtype_mpz,0);

	mpz_init(*ptr);
	mpz_add(*ptr,a1,a2);

	mpz_clear(a1);
	mpz_clear(a2);

	push_param(ptr,dtype_mpz|DTYPE_MALLOCED);

}

/**
 *
 *
 * @todo : Describe function
 */
void
sub_mpz(void)
{
	mpz_t a1;
	mpz_t a2;
	mpz_t *ptr;
	ptr=malloc(sizeof(mpz_t));
	debug("sub_mpz");

	pop_param(&a2,dtype_mpz,0);
	pop_param(&a1,dtype_mpz,0);

	mpz_init(*ptr);
	mpz_sub(*ptr,a1,a2);
	mpz_clear(a1);
	mpz_clear(a2);
	push_param(ptr,dtype_mpz|DTYPE_MALLOCED);
}

/**
 *
 *
 * @todo : Describe function
 */
void
mul_mpz(void)
{
	mpz_t a1;
	mpz_t a2;
	mpz_t *ptr;
	ptr=malloc(sizeof(mpz_t));
	debug("mul_mpz");

	pop_param(&a2,dtype_mpz,0);
	pop_param(&a1,dtype_mpz,0);

	mpz_init(*ptr);
	mpz_mul(*ptr,a1,a2);
	mpz_clear(a1);
	mpz_clear(a2);
	push_param(ptr,dtype_mpz|DTYPE_MALLOCED);
}

/**
 *
 *
 * @todo : Describe function
 */
void
pow_mpz(void)
{
	mpz_t a1;
	unsigned int a2;
	mpz_t *ptr;

	ptr=malloc(sizeof(mpz_t));
	debug("pow_mpz");
	debug_print_stack();
	pop_param(&a2,DTYPE_INT,0);
	pop_param(&a1,dtype_mpz,0);

	mpz_init(*ptr);
        debug("Raising value to power of %d",a2);
	mpz_pow_ui(*ptr,a1,a2);
	mpz_clear(a1);
	push_param(ptr,dtype_mpz|DTYPE_MALLOCED);
}



/**
 *
 *
 * @todo : Describe function
 */
void
div_mpz(void)
{
	mpz_t a1;
	mpz_t a2;
	mpz_t *ptr;
	ptr=malloc(sizeof(mpz_t));
	debug("div_mpz");

	pop_param(&a2,dtype_mpz,0);
	pop_param(&a1,dtype_mpz,0);

	mpz_init(*ptr);
	mpz_fdiv_q(*ptr,a1,a2);
	mpz_clear(a1);
	mpz_clear(a2);
	push_param(ptr,dtype_mpz|DTYPE_MALLOCED);
}


/**
 *
 *
 * @todo : Describe function
 */
void
mod_mpz(void)
{
	mpz_t a1;
	mpz_t a2;
	mpz_t *ptr;
	ptr=malloc(sizeof(mpz_t));
	debug("mod_mpz");

	pop_param(&a2,dtype_mpz,0);
	pop_param(&a1,dtype_mpz,0);

	mpz_init(*ptr);
	mpz_mod(*ptr,a1,a2);
	mpz_clear(a1);
	mpz_clear(a2);
	push_param(ptr,dtype_mpz|DTYPE_MALLOCED);

}


/**
 *
 *
 * @todo : Describe function
 */
int
compare_mpz(void)
{
	mpz_t a1;
	mpz_t a2;

	pop_param(&a2,dtype_mpz,0);
	pop_param(&a1,dtype_mpz,0);

	return mpz_cmp(a1,a2);

}

/**
 *
 *
 * @todo : Describe function
 */
void
gt_mpz(void)
{
	if (compare_mpz()>0) push_int(1);
	else push_int(0);
}

/**
 *
 *
 * @todo : Describe function
 */
void
gte_mpz(void)
{
	if (compare_mpz()>=0) push_int(1);
	else push_int(0);
}

/**
 *
 *
 * @todo : Describe function
 */
void
lt_mpz(void)
{
	if (compare_mpz()<0) push_int(1);
	else push_int(0);
}

/**
 *
 *
 * @todo : Describe function
 */
void
lte_mpz(void)
{
	if (compare_mpz()<=0) push_int(1);
	else push_int(0);
}

/**
 *
 *
 * @todo : Describe function
 */
void
e_mpz(void)
{
	if (compare_mpz()==0) push_int(1);
	else push_int(0);
}

/**
 *
 *
 * @todo : Describe function
 */
void
ne_mpz(void)
{
	if (compare_mpz()!=0) push_int(1);
	else push_int(0);
}


/**
 *
 *
 * @todo : Describe function
 */
void
mpz_free(void *ptr)
{
	// Nothing special
	free(ptr);
}


/**
 *
 *
 * @todo : Describe function
 */
mpz_t *
mpz_copy(mpz_t *a1)
{
	mpz_t *a2;
	a2=mpz_alloc();
	mpz_set(*a2,*a1);
	return a2;
}


/**
 *
 *
 * @todo : Describe function
 */
int
isnull_mpz(void)
{
	/* Its never null */
	return 0;
}

/**
 *
 *
 * @todo : Describe function
 */
void
EXDTYPE_initlib(void)
{
	dtype_mpz=add_datatype(MPZ_DTYPE_NAME, -1, 6);
	add_datatype_function_n(MPZ_DTYPE_NAME,"INCLUDE",include_mpz);
	add_datatype_function_n(MPZ_DTYPE_NAME,"OUTPUT",pr_mpz);

	/* These are used to push onto and off the stack */
	add_datatype_function_n(MPZ_DTYPE_NAME,"ALLOC",mpz_alloc);
	add_datatype_function_n(MPZ_DTYPE_NAME,"COPY",mpz_copy);
	add_datatype_function_n(MPZ_DTYPE_NAME,"FREE",mpz_free);

	/* INITIALIZE */
	add_datatype_function_n(MPZ_DTYPE_NAME,"INIT",init_mpz);

	/* ISNULL */
	add_datatype_function_n(MPZ_DTYPE_NAME,"ISNULL",isnull_mpz);
	
	/*
	Basic string handling
	Note - this is not the same as a string->dtype or dtype->string
	conversion. It is used internally
	Its only used for a char_pop
	which should generate a properly sized string output for the given
	datatype (eg for a smallint - 6 characters (inc sign).
	*/
	add_datatype_function_n(MPZ_DTYPE_NAME,">STRING",mpz_str);


	/* Not sure if we need this one yet */
	add_datatype_function_n(MPZ_DTYPE_NAME,"<STRING",mpz_from_str);


	/*
	These functions are 'class' functions
	a ':' function is callable from 4gl via
	the variable:function() syntax...
	*/
	add_datatype_function_n(MPZ_DTYPE_NAME,":nextprime",a4gl_mpz_nextprime);
	add_datatype_function_n(MPZ_DTYPE_NAME,":setfib",a4gl_mpz_setfib);



	/* These will only apply to TWO MPZ variables */
	add_op_function(dtype_mpz,dtype_mpz,OP_ADD,add_mpz);
	add_op_function(dtype_mpz,dtype_mpz,OP_SUB,sub_mpz);
	add_op_function(dtype_mpz,dtype_mpz,OP_MULT,mul_mpz);

	add_op_function(dtype_mpz,dtype_mpz,OP_POWER,pow_mpz);

    /*
	add_op_function(DTYPE_INT,dtype_mpz,OP_POWER,pow_mpz);
	add_op_function(dtype_mpz,DTYPE_INT,OP_POWER,pow_mpz);
	add_op_function(DTYPE_INT,DTYPE_INT,OP_POWER,pow_mpz);
    */

	add_op_function(dtype_mpz,dtype_mpz,OP_DIV,div_mpz);
	add_op_function(dtype_mpz,dtype_mpz,OP_MOD,mod_mpz);

	add_op_function(dtype_mpz,dtype_mpz,OP_GREATER_THAN     ,gt_mpz);
	add_op_function(dtype_mpz,dtype_mpz,OP_LESS_THAN        ,lt_mpz);

	add_op_function(dtype_mpz,dtype_mpz,OP_GREATER_THAN_EQ  ,gte_mpz);
	add_op_function(dtype_mpz,dtype_mpz,OP_LESS_THAN_EQ     ,gte_mpz);

	add_op_function(dtype_mpz,dtype_mpz,OP_EQUAL        	,e_mpz);
	add_op_function(dtype_mpz,dtype_mpz,OP_NOT_EQUAL        ,ne_mpz);



	/* Conversions to normal datatypes */
	add_conversion("CHAR",MPZ_DTYPE_NAME,		mpz_from_str);
	add_conversion("INTEGER",MPZ_DTYPE_NAME,	mpz_from_int);
	add_conversion("FLOAT",MPZ_DTYPE_NAME,		mpz_from_double);


	add_conversion(MPZ_DTYPE_NAME,MPZ_DTYPE_NAME,	mpz_from_mpz);


	add_conversion(MPZ_DTYPE_NAME,"CHAR",mpz_to_str);
	add_conversion(MPZ_DTYPE_NAME,"INTEGER",mpz_to_int);
	add_conversion(MPZ_DTYPE_NAME,"FLOAT",mpz_to_double);

	/* add_conversion(MPZ_DTYPE_NAME,MPZ_DTYPE_NAME,mpz_to_mpz); */

	debug("Finished EXDTYPE_initlib");

}


/* ================================= EOF =============================== */
