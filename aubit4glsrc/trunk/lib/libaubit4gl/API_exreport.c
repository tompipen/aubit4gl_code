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
# $Id: API_exreport.c,v 1.6 2002-05-20 11:41:12 afalout Exp $
#
*/

/**
 * @file
 * PDF Report Implementation functions.
 *
 * @todo Add Doxygen comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include <stdio.h>

#include "a4gl_dbform.h"
#include "a4gl_report.h"
#include "a4gl_debug.h"
#include "a4gl_stack.h"
#include "a4gl_aubit_lib.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

static void *libptr=0;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

static int (*func)();
static double (*func_d)();
void *find_func(void *p,char *s);
void *find_func_allow_missing(void *p,char *s);
double pdf_size(double f, char c,void  *p) ;
void pdf_skip_by(void *rep,double a) ;
double pdf_metric(int a,char  c,void *rep);
void pdf_aclfgli_skip_lines(void *rep);
void pdf_fputmanyc(FILE *f,int c,int cnt);
void pdf_set_column(void *rep);
extern void *find_func_double (void *dllhandle, char *func); //in calldll.c

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 *
 * @todo Describe function
 */
int
A4GLREPORT_initlib (void)
{

        libptr=(void *)dl_openlibrary("EXREPORT",acl_getenv("A4GL_PDFTYPE"));

        debug("libptr=%p\n",libptr);
        debug("A4GL_PDFTYPE=%s\n",acl_getenv("A4GL_PDFTYPE"));

        if (libptr==0) {
                exitwith("Unable to open EXREPORT library.");
                return 0;
        }

        func=find_func_allow_missing(libptr,"A4GLREPORT_initlib");

        if (func)
                return func();
        else
                return 1;
}


/**
 *
 * @todo Describe function
 */
void 
pdf_rep_print (void *rep, int a, int s,int right_margin) 
{
  if (libptr==0) A4GLREPORT_initlib();
  func=find_func(libptr,"pdf_rep_print");
  func(rep,a,s,right_margin);
}


/**
 *
 * @todo Describe function
 */
void 
pdf_fputmanyc(FILE *f,int c,int cnt) 
{
  if (libptr==0) A4GLREPORT_initlib();
  func=find_func(libptr,"pdf_fputmanyc");
  func(f,c,cnt);
}

/**
 *
 * @todo Describe function
 */
void
pdf_set_column(void *rep)
{
  if (libptr==0) A4GLREPORT_initlib();
  func=find_func(libptr,"pdf_set_column");
  func(rep);
}


/**
 *
 * @todo Describe function
 */
void 
pdf_skip_to(void *rep,double a) 
{
  if (libptr==0) A4GLREPORT_initlib();
  func=find_func(libptr,"pdf_skip_to");
  func(rep,a);
}


/**
 *
 * @todo Describe function
 */
void 
pdf_skip_by(void *rep,double a) 
{
  if (libptr==0) A4GLREPORT_initlib();
  func=find_func(libptr,"pdf_skip_by");
  func(rep,a);
}

/**
 *
 * @todo Describe function
 */
void 
pdf_aclfgli_skip_lines(void *rep) 
{
  if (libptr==0) A4GLREPORT_initlib();
  func=find_func(libptr,"pdf_aclfgli_skip_lines");
  func(rep);
}

/**
 *
 * @todo Describe function
 */
void 
pdf_need_lines(void *rep) 
{
  if (libptr==0) A4GLREPORT_initlib();
  func=find_func(libptr,"pdf_need_lines");
  func(rep);
}

/**
 *
 * @todo Describe function
 */
void 
pdf_skip_top_of_page(void *rep) 
{
  if (libptr==0) A4GLREPORT_initlib();
  func=find_func(libptr,"pdf_skip_top_of_page");
  func(rep);
}

/**
 *
 * @todo Describe function
 */
void 
pdf_add_spaces(void)
{
  if (libptr==0) A4GLREPORT_initlib();
  func=find_func(libptr,"pdf_add_spaces");
  func();
}

/*
** Fairly sure these are internal functions

So define them as static then.

void pdf_new_page(void *p) {
  if (libptr==0) A4GLREPORT_initlib();
  func=find_func(libptr,"pdf_new_page");
  func(p);
}



void pdf_set_info (void *p,char *creator) {
  if (libptr==0) A4GLREPORT_initlib();
  func=find_func(libptr,"pdf_set_info");
  func(p,creator);
}

pdf_move(void *p) {
  if (libptr==0) A4GLREPORT_initlib();
  func=find_func(libptr,"pdf_move");
  func(f,c,cnt);
}
*/


/**
 *
 * @todo Describe function
 */
void 
pdf_rep_close(void *p) 
{
  if (libptr==0) A4GLREPORT_initlib();
  func=find_func(libptr,"pdf_rep_close");
  func(p);
}


/**
 *
 * @todo Describe function
 */
double 
pdf_size(double f, char c,void *p) 
{
double d;
	debug("Trying to find pdf_size - libptr=%p",libptr);
  	if (libptr==0) A4GLREPORT_initlib();
  	func_d=find_func_double(libptr,"pdf_size");

        d=func_d(f,c,p);
	debug("Got size as : %lf",d);
return d;
}



/**
 *
 * @todo Describe function
 */
void 
pdf_pdffunc(void *p,char *fname,int n) 
{
  if (libptr==0) A4GLREPORT_initlib();
  func=find_func(libptr,"pdf_pdffunc");
  func(p,fname,n);
}



/**
 *
 * @todo Describe function
 */
void 
pdf_blob_print(void *p,void *blob,char *type,int cr) 
{
  if (libptr==0) A4GLREPORT_initlib();
  func=find_func(libptr,"pdf_blob_print");
  func(p,blob,type,cr);
}

// ================================= EOF =============================

