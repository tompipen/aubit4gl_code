#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include "../libincl/a4gl_debug.h"
#include "../libincl/a4gl_dtypes.h"
#include "../libincl/a4gl_stack.h"
#define MPZ_DTYPE_NAME "MPZ"

// Just implement mpz for now (large integers)...
int dtype_mpz=0;

char *include_mpz() {
//
// FIXME...
// Should really check the language type before printing
//
	return "gmp";
}


char *pr_mpz() {
//
// FIXME...
// Should really check the language type before printing
//
	return "mpz_t ";
}

void init_mpz(mpz_t *mpz) {
	mpz_init(*mpz);
}


void *mpz_alloc() {
mpz_t *ptr;
	ptr=(mpz_t *)malloc(sizeof(mpz_t));
	mpz_init(*ptr);
	return ptr;
}


int mpz_from_double (double *n,mpz_t *mpz,int szignore) {
	debug("mpz_from_double");
	mpz_init(*mpz);
	mpz_set_d(*mpz,*n);
	return 1;
}

int mpz_from_int (long *n,mpz_t *mpz,int szignore) {
	debug("mpz_from_int");
	mpz_init(*mpz);
	mpz_set_si(*mpz,*n);
	return 1;
}

int mpz_from_mpz (mpz_t *n,mpz_t *mpz,int szignore) {
	debug("mpz_from_mpz");
	mpz_init(*mpz);
	mpz_set(*mpz,*n);
	return 1;
}

int mpz_from_str (char *n,mpz_t *mpz,int szignore) {
	debug("mpz_from_str");
	mpz_init(*mpz);
	mpz_set_str(*mpz,n,0);
	return 1;

}

int mpz_to_double (mpz_t *mpz,double *n,int szignore) {
	debug("mpz_to_double");
	*n=mpz_get_d(*mpz);
	return 1;
}

int mpz_to_int (mpz_t *mpz,long *n,int szignore) {
	debug("%p %p (%d %d)\n",mpz,n,*(long *)mpz,*(long *)n);
	debug("mpz_to_int");
	*n=mpz_get_si(*mpz);
	return 1;
}

int mpz_to_mpz (mpz_t *mpz,mpz_t *n,int szignore) {
	debug("mpz_to_mpz");
	mpz_set(*mpz,*n);
	return 1;
}


char *mpz_str (mpz_t *mpz,char *n,int sz) {
	debug("mpz_str");
	return mpz_get_str(n,10,*mpz);
}

int mpz_to_str (mpz_t *mpz,char *n,int sz) {
	char *ptr;
	debug("mpz_to_str");

	ptr=mpz_get_str(0,10,*mpz);
	if (strlen(ptr)>sz) {
		free(ptr);
		return 0;
	} else {
		strcpy(n,ptr);
	}
	return 1;
}

void add_mpz() {
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

void sub_mpz() {
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

void mul_mpz() {
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

void pow_mpz() {
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



void div_mpz() {
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


void mod_mpz() {
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


compare_mpz() {
	mpz_t a1;
	mpz_t a2;
	int s;

	pop_param(&a2,dtype_mpz,0);
	pop_param(&a1,dtype_mpz,0);

	return mpz_cmp(a1,a2);

}

gt_mpz() {
	if (compare_mpz()>0) push_int(1);
	else push_int(0);
}

gte_mpz() {
	if (compare_mpz()>=0) push_int(1);
	else push_int(0);
}

lt_mpz() {
	if (compare_mpz()<0) push_int(1);
	else push_int(0);
}

lte_mpz() {
	if (compare_mpz()<=0) push_int(1);
	else push_int(0);
}

e_mpz() {
	if (compare_mpz()==0) push_int(1);
	else push_int(0);
}

ne_mpz() {
	if (compare_mpz()!=0) push_int(1);
	else push_int(0);
}


mpz_free(void *ptr) {
	// Nothing special
	free(ptr);
}




mpz_copy(mpz_t *a1) {
	mpz_t *a2;
	a2=mpz_alloc();
	mpz_set(*a2,*a1);
	return a2;
}


int isnull_mpz() {
// Its never null....
	return 0;
}

int EXDTYPE_initlib() {
	dtype_mpz=add_datatype(MPZ_DTYPE_NAME, -1, 6);
	add_datatype_function_n(MPZ_DTYPE_NAME,"INCLUDE",include_mpz);
	add_datatype_function_n(MPZ_DTYPE_NAME,"OUTPUT",pr_mpz);

// These are used to push onto and off the stack
	add_datatype_function_n(MPZ_DTYPE_NAME,"ALLOC",mpz_alloc);
	add_datatype_function_n(MPZ_DTYPE_NAME,"COPY",mpz_copy);
	add_datatype_function_n(MPZ_DTYPE_NAME,"FREE",mpz_free);

// INITIALIZE ...
	add_datatype_function_n(MPZ_DTYPE_NAME,"INIT",init_mpz);

// ISNULL
	add_datatype_function_n(MPZ_DTYPE_NAME,"ISNULL",isnull_mpz);

// Basic string handling
// Note - this is not the same as a string->dtype or dtype->string
// conversion. It is used internally
// Its only used for a char_pop
// which should generate a properly sized string output for the given
// datatype (eg for a smallint - 6 characters (inc sign).
	add_datatype_function_n(MPZ_DTYPE_NAME,">STRING",mpz_str);


// Not sure if we need this one yet
	add_datatype_function_n(MPZ_DTYPE_NAME,"<STRING",mpz_from_str);




// These will only apply to TWO MPZ variables...
	add_op_function(dtype_mpz,dtype_mpz,OP_ADD,add_mpz);
	add_op_function(dtype_mpz,dtype_mpz,OP_SUB,sub_mpz);
	add_op_function(dtype_mpz,dtype_mpz,OP_MULT,mul_mpz);

	add_op_function(dtype_mpz,dtype_mpz,OP_POWER,pow_mpz);

	//add_op_function(DTYPE_INT,dtype_mpz,OP_POWER,pow_mpz);
	//add_op_function(dtype_mpz,DTYPE_INT,OP_POWER,pow_mpz);
	//add_op_function(DTYPE_INT,DTYPE_INT,OP_POWER,pow_mpz);

	add_op_function(dtype_mpz,dtype_mpz,OP_DIV,div_mpz);
	add_op_function(dtype_mpz,dtype_mpz,OP_MOD,mod_mpz);

	add_op_function(dtype_mpz,dtype_mpz,OP_GREATER_THAN     ,gt_mpz);
	add_op_function(dtype_mpz,dtype_mpz,OP_LESS_THAN        ,lt_mpz);

	add_op_function(dtype_mpz,dtype_mpz,OP_GREATER_THAN_EQ  ,gte_mpz);
	add_op_function(dtype_mpz,dtype_mpz,OP_LESS_THAN_EQ     ,gte_mpz);

	add_op_function(dtype_mpz,dtype_mpz,OP_EQUAL        	,e_mpz);
	add_op_function(dtype_mpz,dtype_mpz,OP_NOT_EQUAL        ,ne_mpz);



// Conversions to normal datatypes...
	add_conversion("CHAR",MPZ_DTYPE_NAME,		mpz_from_str);
	add_conversion("INTEGER",MPZ_DTYPE_NAME,	mpz_from_int);
	add_conversion("FLOAT",MPZ_DTYPE_NAME,		mpz_from_double);


	add_conversion(MPZ_DTYPE_NAME,MPZ_DTYPE_NAME,	mpz_from_mpz);


	add_conversion(MPZ_DTYPE_NAME,"CHAR",mpz_to_str);
	add_conversion(MPZ_DTYPE_NAME,"INTEGER",mpz_to_int);
	add_conversion(MPZ_DTYPE_NAME,"FLOAT",mpz_to_double);

	//add_conversion(MPZ_DTYPE_NAME,MPZ_DTYPE_NAME,mpz_to_mpz);

}
