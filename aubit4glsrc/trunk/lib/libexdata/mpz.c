#include <stdio.h>
#include <gmp.h>
#include "../libincl/a4gl_debug.h"
#define MPZ_DTYPE_NAME "MPZ"

// Just implement mpz for now (large integers)...
int dtype_mpz;

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
	mpz_set_d(*mpz,*n);
	return 1;
}

int mpz_from_int (long *n,mpz_t *mpz,int szignore) {
	mpz_set_si(*mpz,*n);
	return 1;
}

int mpz_from_mpz (mpz_t *n,mpz_t *mpz,int szignore) {
	mpz_set(*mpz,*n);
	return 1;
}

int mpz_from_str (char *n,mpz_t *mpz,int szignore) {
	mpz_set_str(*mpz,n,0);
	return 1;

}

int mpz_to_double (mpz_t *mpz,double *n,int szignore) {
	*n=mpz_get_d(*mpz);
	return 1;
}

int mpz_to_int (mpz_t *mpz,long *n,int szignore) {
	mpz_set_si(*mpz,*n);
	return 1;
}

int mpz_to_mpz (mpz_t *mpz,mpz_t *n,int szignore) {
	mpz_set(*mpz,*n);
	return 1;
}

char *mpz_to_str (mpz_t *mpz,char *n,int sz) {
	return mpz_get_str(n,10,*mpz);
}

void *add_mpz(mpz_t *a1,mpz_t *a2) {
	mpz_t *ptr;
	ptr=mpz_alloc();
	mpz_add(*ptr,*a1,*a2);
	return ptr;
}

void *minus_mpz(mpz_t *a1,mpz_t *a2) {
	mpz_t *ptr;
	ptr=mpz_alloc();
	mpz_sub(*ptr,*a1,*a2);
	return ptr;
}
void *times_mpz(mpz_t *a1,mpz_t *a2) {
	mpz_t *ptr;
	ptr=mpz_alloc();
	mpz_mul(*ptr,*a1,*a2);
	return ptr;
}

void *div_mpz(mpz_t *a1,mpz_t *a2) {
	mpz_t *ptr;
	ptr=mpz_alloc();
	mpz_tdiv_q(*ptr,*a1,*a2);
	return ptr;
}

void *mod_mpz(mpz_t *a1,mpz_t *a2) {
	mpz_t *ptr;
	ptr=mpz_alloc();
	mpz_tdiv_r(*a1,*a2,*ptr);
	return ptr;
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

// These will only apply to TWO MPZ variables...
	add_datatype_function_n(MPZ_DTYPE_NAME,"+",add_mpz);
	add_datatype_function_n(MPZ_DTYPE_NAME,"-",minus_mpz);
	add_datatype_function_n(MPZ_DTYPE_NAME,"*",times_mpz);
	add_datatype_function_n(MPZ_DTYPE_NAME,"/",div_mpz);
	add_datatype_function_n(MPZ_DTYPE_NAME,"%",mod_mpz);

	add_datatype_function_n(MPZ_DTYPE_NAME,">STRING",mpz_to_str);
	add_datatype_function_n(MPZ_DTYPE_NAME,"<STRING",mpz_from_str);

	debug("Adding conversions....");


	add_conversion("CHAR",MPZ_DTYPE_NAME,mpz_from_str);
	add_conversion("INTEGER",MPZ_DTYPE_NAME,mpz_from_int);
	add_conversion("FLOAT",MPZ_DTYPE_NAME,mpz_from_double);


	add_conversion(MPZ_DTYPE_NAME,MPZ_DTYPE_NAME,mpz_from_double);


	add_conversion(MPZ_DTYPE_NAME,"CHAR",mpz_to_str);
	add_conversion(MPZ_DTYPE_NAME,"INTEGER",mpz_to_int);
	add_conversion(MPZ_DTYPE_NAME,"FLOAT",mpz_to_double);


	add_conversion(MPZ_DTYPE_NAME,MPZ_DTYPE_NAME,mpz_to_double);

}
