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
# $Id: API_exreport.c,v 1.17 2004-02-10 13:50:20 mikeaubury Exp $
#
*/

/**
 * @file
 * PDF Report Implementation functions.
 *
 * @todo Add Doxygen A4GL_comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen A4GL_comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/


#ifdef OLD_INCL

#include <stdio.h>

#include "a4gl_dbform.h"
#include "a4gl_report.h"
#include "a4gl_debug.h"
#include "a4gl_stack.h"
#include "a4gl_aubit_lib.h"


#else

#include "a4gl_libaubit4gl_int.h"

#endif

double A4GL_pdf_size (double f, char c, struct pdf_rep_structure *p);
/*
=====================================================================
                    Variables definitions
=====================================================================
*/

static void *libptr = 0;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


static int (*A4GL_func) ();

/* static double 	(*func_d)			(); */
static double (*A4GL_func_d) (double f, char c, struct pdf_rep_structure * p);


/* void *			find_func			(void *p,char *s); in calldll.c */
extern void *A4GL_find_func_double (void *dllhandle, char *func);	/* in calldll.c */
void A4GL_pdf_skip_by (void *rep, double a);
double A4GL_pdf_metric (int a, char c, void *rep);
void A4GL_pdf_aclfgli_skip_lines (void *rep);
void A4GL_pdf_fputmanyc (FILE * f, int c, int cnt);
void A4GL_pdf_set_column (void *rep);
void A4GL_pdf_rep_print (void *rep, int a, int s, int right_margin);
void A4GL_pdf_skip_to (void *rep, double a);
void A4GL_pdf_need_lines (void *rep);
void A4GL_pdf_skip_top_of_page (void *rep);
void A4GL_pdf_add_spaces (void);
void A4GL_pdf_rep_close (void *p);
void A4GL_pdf_pdffunc (void *p, char *fname, int n);
void A4GL_pdf_blob_print (void *p, void *blob, char *type, int cr);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 *
 * @todo Describe function
 */
void
A4GLREPORT_initlib (void)
{

  libptr = (void *) A4GL_dl_openlibrary ("EXREPORT", acl_getenv ("A4GL_PDFTYPE"));

  A4GL_debug ("libptr=%p\n", libptr);
  A4GL_debug ("A4GL_PDFTYPE=%s\n", acl_getenv ("A4GL_PDFTYPE"));

  if (libptr == 0)
    {
      A4GL_exitwith ("Unable to open EXREPORT library.");
      return;
    }

  A4GL_func = A4GL_find_func_allow_missing (libptr, "A4GLREPORT_initlib");

  /*
     if (func)
     return func();
     else
     return 1;
   */

  A4GL_func ();
}


/**
 *
 * @todo Describe function
 */
void
A4GL_pdf_rep_print (void *rep, int a, int s, int right_margin)
{
  if (libptr == 0)
    A4GLREPORT_initlib ();
  A4GL_func = A4GL_find_func (libptr, "A4GL_pdf_rep_print");
  A4GL_func (rep, a, s, right_margin);
}


/**
 *
 * @todo Describe function
 */
void
A4GL_pdf_fputmanyc (FILE * f, int c, int cnt)
{
  if (libptr == 0)
    A4GLREPORT_initlib ();
  A4GL_func = A4GL_find_func (libptr, "A4GL_pdf_fputmanyc");
  A4GL_func (f, c, cnt);
}

/**
 *
 * @todo Describe function
 */
void
A4GL_pdf_set_column (void *rep)
{
  if (libptr == 0)
    A4GLREPORT_initlib ();
  A4GL_func = A4GL_find_func (libptr, "A4GL_pdf_set_column");
  A4GL_func (rep);
}


/**
 *
 * @todo Describe function
 */
void
A4GL_pdf_skip_to (void *rep, double a)
{
  if (libptr == 0)
    A4GLREPORT_initlib ();
  A4GL_func = A4GL_find_func (libptr, "A4GL_pdf_skip_to");
  A4GL_func (rep, a);
}


/**
 *
 * @todo Describe function
 */
void
A4GL_pdf_skip_by (void *rep, double a)
{
  if (libptr == 0)
    A4GLREPORT_initlib ();
  A4GL_func = A4GL_find_func (libptr, "A4GL_pdf_skip_by");
  A4GL_func (rep, a);
}

/**
 *
 * @todo Describe function
 */
void
A4GL_pdf_aclfgli_skip_lines (void *rep)
{
  if (libptr == 0)
    A4GLREPORT_initlib ();
  A4GL_func = A4GL_find_func (libptr, "A4GL_pdf_aclfgli_skip_lines");
  A4GL_func (rep);
}

/**
 *
 * @todo Describe function
 */
void
A4GL_pdf_need_lines (void *rep)
{
  if (libptr == 0)
    A4GLREPORT_initlib ();
  A4GL_func = A4GL_find_func (libptr, "A4GL_pdf_need_lines");
  A4GL_func (rep);
}

/**
 *
 * @todo Describe function
 */
void
A4GL_pdf_skip_top_of_page (void *rep)
{
  if (libptr == 0)
    A4GLREPORT_initlib ();
  A4GL_func = A4GL_find_func (libptr, "A4GL_pdf_skip_top_of_page");
  A4GL_func (rep);
}

/**
 *
 * @todo Describe function
 */
void
A4GL_pdf_add_spaces (void)
{
  if (libptr == 0)
    A4GLREPORT_initlib ();
  A4GL_func = A4GL_find_func (libptr, "A4GL_pdf_add_spaces");
  A4GL_func ();
}

/*
** Fairly sure these are internal functions

So define them as static then.

void pdf_new_page(void *p) {
  if (libptr==0) A4GLREPORT_initlib();
  func=find_func(libptr,"A4GL_pdf_new_page");
  func(p);
}



void A4GL_pdf_set_info (void *p,char *creator) {
  if (libptr==0) A4GLREPORT_initlib();
  func=find_func(libptr,"A4GL_pdf_set_info");
  func(p,creator);
}

pdf_move(void *p) {
  if (libptr==0) A4GLREPORT_initlib();
  func=find_func(libptr,"A4GL_pdf_move");
  func(f,c,cnt);
}
*/


/**
 *
 * @todo Describe function
 */
void
A4GL_pdf_rep_close (void *p)
{
  if (libptr == 0)
    A4GLREPORT_initlib ();
  A4GL_func = A4GL_find_func (libptr, "A4GL_pdf_rep_close");
  A4GL_func (p);
}


/**
 *
 * @todo Describe function
 */
/* pdf_size(double f, char c,void *p) */
double
A4GL_pdf_size (double f, char c, struct pdf_rep_structure *p)
{
  double d;
  A4GL_debug ("Trying to find A4GL_pdf_size - libptr=%p", libptr);
  if (libptr == 0)
    A4GLREPORT_initlib ();
  A4GL_func_d = A4GL_find_func_double (libptr, "A4GL_pdf_size");

  d = A4GL_func_d (f, c, p);
  A4GL_debug ("Got size as : %lf", d);
  return d;
}



/**
 *
 * @todo Describe function
 */
void
A4GL_pdf_pdffunc (void *p, char *fname, int n)
{
  if (libptr == 0)
    A4GLREPORT_initlib ();
  A4GL_func = A4GL_find_func (libptr, "A4GL_pdf_pdffunc");
  A4GL_func (p, fname, n);
}



/**
 *
 * @todo Describe function
 */
void
A4GL_pdf_blob_print (void *p, void *blob, char *type, int cr)
{
  if (libptr == 0)
    A4GLREPORT_initlib ();
  A4GL_func = A4GL_find_func (libptr, "A4GL_pdf_blob_print");
  A4GL_func (p, blob, type, cr);
}

/* ================================= EOF ============================= */
