/*
 * lib=EXREPORT env=A4GL_PDFTYPE lib_prefix= api_prefix=
 * @file
 * File definition
 *
 * This file was created from .spec file of same name, using dlmagic script
 * - if you need to edit it, edit .spec file instad, and use [make filename.c]
 * to re-create it.
 *
 * @todo Add Doxygen comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

/*******************************************************************
* (c) 1997-2002 Aubit Computing Ltd.
*
*
********************************************************************/


#include "a4gl_libaubit4gl_int.h"

static void *libptr=0;
int A4GLEXREPORT_initlib (void);
void A4GLEXREPORT_clrlibptr (void);
int dlclose (void *__handle);

/**
 * Library init function.
 *
 * @todo : explain ussage and parameters.
 * @return .
 */

void A4GLEXREPORT_clrlibptr (void) {
    if (libptr) {dlclose(libptr);}
    libptr=0;
}

int A4GLEXREPORT_initlib (void) {
int (*func)(void);
   libptr=(void *)A4GL_dl_openlibrary("EXREPORT",acl_getenv("A4GL_PDFTYPE"));
   if (libptr==0) {
      A4GL_exitwith("Unable to open  library...");
      return 0;
   }
   func=A4GL_find_func_allow_missing(libptr,"A4GLEXREPORT_initlib");

   if (func)
      return func();
   else
      return 1;
}


/* void A4GL_pdf_rep_print (void *rep, int a, int s, int right_margin) */
/* void A4GL_pdf_fputmanyc (FILE * f, int c, int cnt) */
/* void A4GL_pdf_set_column (void *rep) */
/* void A4GL_pdf_skip_to (void *rep, double a) */
/* void A4GL_pdf_skip_by (void *rep, double a) */
/* void A4GL_pdf_aclfgli_skip_lines (void *rep) */
/* void A4GL_pdf_need_lines (void *rep) */
/* void A4GL_pdf_skip_top_of_page (void *rep) */
/* void A4GL_pdf_set_info (void *p,char *creator)  */
/* void A4GL_pdf_rep_close (void *p) */
/* double A4GL_pdf_size (double f, char c, struct pdf_rep_structure *p) */
/* void A4GL_pdf_pdffunc (void *p, char *fname, int n) */
/* void A4GL_pdf_blob_print (void *p, void *blob, char *type, int cr) */
void A4GL_pdf_rep_print(void* rep,int a,int s,int right_margin,int why) {
static void (*func_1)(void *  ,int ,int ,int ,int );
#ifdef DEBUG
A4GL_debug("Call to void A4GL_pdf_rep_print(%p,%d,%d,%d,%d)\n",rep,a,s,right_margin,why);
#endif
   if (libptr==0) A4GLEXREPORT_initlib();
   func_1=A4GL_find_func(libptr,"A4GL_pdf_rep_print");
   func_1(rep,a,s,right_margin,why);
}

void A4GL_pdf_fputmanyc(FILE* f,int c,int cnt) {
static void (*func_2)(FILE *  ,int ,int );
#ifdef DEBUG
A4GL_debug("Call to void A4GL_pdf_fputmanyc(%p,%d,%d)\n",f,c,cnt);
#endif
   if (libptr==0) A4GLEXREPORT_initlib();
   func_2=A4GL_find_func(libptr,"A4GL_pdf_fputmanyc");
   func_2(f,c,cnt);
}

void A4GL_pdf_set_column(void* rep) {
static void (*func_3)(void *  );
#ifdef DEBUG
A4GL_debug("Call to void A4GL_pdf_set_column(%p)\n",rep);
#endif
   if (libptr==0) A4GLEXREPORT_initlib();
   func_3=A4GL_find_func(libptr,"A4GL_pdf_set_column");
   func_3(rep);
}

void A4GL_pdf_skip_to(void* rep,double a) {
static void (*func_4)(void *  ,double );
#ifdef DEBUG
A4GL_debug("Call to void A4GL_pdf_skip_to(%p,%p)\n",rep,a);
#endif
   if (libptr==0) A4GLEXREPORT_initlib();
   func_4=A4GL_find_func(libptr,"A4GL_pdf_skip_to");
   func_4(rep,a);
}

void A4GL_pdf_skip_by(void* rep,double a) {
static void (*func_5)(void *  ,double );
#ifdef DEBUG
A4GL_debug("Call to void A4GL_pdf_skip_by(%p,%p)\n",rep,a);
#endif
   if (libptr==0) A4GLEXREPORT_initlib();
   func_5=A4GL_find_func(libptr,"A4GL_pdf_skip_by");
   func_5(rep,a);
}

void A4GL_pdf_aclfgli_skip_lines(void* rep) {
static void (*func_6)(void *  );
#ifdef DEBUG
A4GL_debug("Call to void A4GL_pdf_aclfgli_skip_lines(%p)\n",rep);
#endif
   if (libptr==0) A4GLEXREPORT_initlib();
   func_6=A4GL_find_func(libptr,"A4GL_pdf_aclfgli_skip_lines");
   func_6(rep);
}

void A4GL_pdf_need_lines(void* rep) {
static void (*func_7)(void *  );
#ifdef DEBUG
A4GL_debug("Call to void A4GL_pdf_need_lines(%p)\n",rep);
#endif
   if (libptr==0) A4GLEXREPORT_initlib();
   func_7=A4GL_find_func(libptr,"A4GL_pdf_need_lines");
   func_7(rep);
}

void A4GL_pdf_skip_top_of_page(void* rep,int n) {
static void (*func_8)(void *  ,int );
#ifdef DEBUG
A4GL_debug("Call to void A4GL_pdf_skip_top_of_page(%p,%d)\n",rep,n);
#endif
   if (libptr==0) A4GLEXREPORT_initlib();
   func_8=A4GL_find_func(libptr,"A4GL_pdf_skip_top_of_page");
   func_8(rep,n);
}

void A4GL_pdf_set_info(void* p,char* creator) {
static void (*func_9)(void *  ,char *  );
#ifdef DEBUG
A4GL_debug("Call to void A4GL_pdf_set_info(%p,(%s)))\n",p,A4GL_null_as_null(creator));
#endif
   if (libptr==0) A4GLEXREPORT_initlib();
   func_9=A4GL_find_func(libptr,"A4GL_pdf_set_info");
   func_9(p,creator);
}

void A4GL_pdf_rep_close(void* p) {
static void (*func_10)(void *  );
#ifdef DEBUG
A4GL_debug("Call to void A4GL_pdf_rep_close(%p)\n",p);
#endif
   if (libptr==0) A4GLEXREPORT_initlib();
   func_10=A4GL_find_func(libptr,"A4GL_pdf_rep_close");
   func_10(p);
}

double A4GL_pdf_size(double f,char c,void* p) {
double rval;
static double (*func_11)(double ,char ,void *  );
#ifdef DEBUG
A4GL_debug("Call to double A4GL_pdf_size(%p,(%c),%p)\n",f,c,p);
#endif
   if (libptr==0) A4GLEXREPORT_initlib();
   func_11=A4GL_find_func(libptr,"A4GL_pdf_size");
   rval=(double)func_11 (f,c,p);
#ifdef DEBUG
A4GL_debug("Returning Unknown %p",rval);

#endif
return rval;
}

int A4GL_pdf_pdffunc(void* p,char* fname,int n) {
int rval;
static int (*func_12)(void *  ,char *  ,int );
#ifdef DEBUG
A4GL_debug("Call to int A4GL_pdf_pdffunc(%p,(%s)),%d)\n",p,A4GL_null_as_null(fname),n);
#endif
   if (libptr==0) A4GLEXREPORT_initlib();
   func_12=A4GL_find_func(libptr,"A4GL_pdf_pdffunc");
   rval=(int)func_12 (p,fname,n);
#ifdef DEBUG
A4GL_debug("Returning %d",rval);

#endif
return rval;
}

void A4GL_pdf_blob_print(void* p,void* blob,char* type,int cr) {
static void (*func_13)(void *  ,void *  ,char *  ,int );
#ifdef DEBUG
A4GL_debug("Call to void A4GL_pdf_blob_print(%p,%p,(%s)),%d)\n",p,blob,A4GL_null_as_null(type),cr);
#endif
   if (libptr==0) A4GLEXREPORT_initlib();
   func_13=A4GL_find_func(libptr,"A4GL_pdf_blob_print");
   func_13(p,blob,type,cr);
}

