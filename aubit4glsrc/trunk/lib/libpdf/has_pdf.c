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
# $Id: has_pdf.c,v 1.9 2002-06-29 13:12:02 afalout Exp $
#*/

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

#ifdef OLD_INCL

	#include <stdio.h>

	#include "pdflib.h"

	#include "a4gl_runtime_tui.h"		/* push_int */
	#include "a4gl_dbform.h"
	#include "a4gl_report.h"
	#include "a4gl_stack.h"
	#include "a4gl_aubit_lib.h"
	#include "a4gl_debug.h"

#else

    #include "a4gl_lib_exreport_pdf_int.h"

#endif

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

/* double 	pdf_size		(double f, char c,struct pdf_rep_structure *p) ; */
void 	pdf_skip_by		(struct pdf_rep_structure *rep,double a) ;
double 	pdf_metric		(int a,char  c,struct pdf_rep_structure *rep);
void 	pdf_aclfgli_skip_lines(struct pdf_rep_structure *rep);
void 	pdf_fputmanyc	(FILE *f,int c,int cnt);
void 	pdf_set_column	(struct pdf_rep_structure *rep);
void 	pdf_move		(struct pdf_rep_structure *p);
void 	pdf_set_info 	(void *p,char *creator);
void 	pdf_skip_top_of_page(struct pdf_rep_structure *rep);
int     pdf_new_page	(struct pdf_rep_structure *p);

void pdf_rep_print (struct pdf_rep_structure *rep, int a, int s,int right_margin);
void pdf_skip_to(struct pdf_rep_structure *rep,double a);
void pdf_need_lines(struct pdf_rep_structure *rep);
void pdf_add_spaces(void);
void pdf_rep_close(struct pdf_rep_structure *p);
int aclpdf(struct pdf_rep_structure *p,char *fname,int n);
int pdf_blob_print(struct pdf_rep_structure *p,struct fgl_int_loc *blob,char *type,int cr);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 *
 * a = number to pop
 * s = semi colon at the end
 *
 * @todo Describe function
 */
void
pdf_rep_print (struct pdf_rep_structure *rep, int a, int s,int right_margin)
{
int b;
char *str;
  
  debug ("In rep_print");
  if (right_margin!=0) {
                debug("***** WARNING ***** wordwrap margin not implemented..");
  }
  if (rep->line_no == 0 && rep->page_no == 0)
    {
      if (rep->output_mode == 'F')
	{
	  if (strcmp (rep->output_loc, "stdout")==0)
	    {
	      push_char("");
	      push_int(-1);
	      push_int(-1);
	      display_at(1,0);
	      rep->output = stdout;
	    }
	  else
	    {
	    	rep->pdf_ptr=PDF_new();
		debug("Opening file: %s\n",rep->output_loc);
		if (PDF_open_file(rep->pdf_ptr,rep->output_loc)==-1) {
			exitwith("Error opening output\n");
			return;
		}
	debug("Set info");
		pdf_set_info(rep->pdf_ptr,"A4GL");
	/* debug("New page");
		pdf_new_page(rep);
        */
	    }
	}
      else
	{
	  rep->output = popen (rep->output_loc, "w");
	  if (rep->output == 0)
	    {
	      exitwith("Could not open report output");
	      return;
	    }
	}
    }

  if (rep->line_no == 0)
    {
	debug("New page...");
      pdf_new_page(rep);
	debug("set line 1");
      rep->line_no = pdf_metric(1,'l',rep);
	debug("Adding to page no...");
      rep->page_no++;
      debug ("Need page header");

      pdf_skip_by(rep,0.0-rep->top_margin);
      rep->report (0, REPORT_PAGEHEADER);
    }

  debug ("Popping %d parameters", a);
  if (a > 0)
    {

    if (rep->col_no==0) {
         rep->col_no+=rep->left_margin;
    }
        for (b = 0; b < a; b++)
	{
	
	  debug("A\n");
	  str = char_pop ();
	  debug ("Popped '%s'...",str);
	  debug ("Popped %s\n", str);
      pdf_move(rep);
	  PDF_show (rep->pdf_ptr, str);
	  debug("Adding %f to col_no\n",pdf_metric(strlen(str),'c',rep));
          rep->col_no+=pdf_metric(strlen(str),'c',rep);
	  acl_free(str);
	}
        pdf_move(rep);
    }
  debug ("Newline : %d", s);

  if (s == 0)
    {
      debug("B\n");
      pdf_move(rep);
      rep->col_no=0;
	debug("CR\n");
      rep->line_no+=pdf_metric(1,'l',rep);

      if (rep->line_no > rep->page_length - rep->bottom_margin)
	{
	  rep->line_no = 0;
	  pdf_rep_print (rep, 0, 0,0);
        }
    }
  fflush(rep->output);
debug("Done\n");
  return ;
}


/**
 *
 * @todo Describe function
 */
void 
pdf_fputmanyc(FILE *f,int c,int cnt) 
{
int a;
	for (a=0;a<cnt;a++) fputc(c,f);
}

/**
 *
 * @todo Describe function
 */
void 
pdf_set_column(struct pdf_rep_structure *rep)
{
double a;
double needn;

	debug("Set column");
	a=pdf_size(pop_double(),'c',rep);

	if (rep->col_no==0.0) {
	debug("setcol");
	     rep->col_no=pdf_metric(1,'c',rep);
	}

	needn=a - rep->col_no + rep->left_margin; /* -pdf_metric(1,'c',rep); */


	/* if (rep->col_no==pdf_metric(1,'c',rep)) needn+=pdf_metric(1,'c',rep); */

	#ifdef DEBUG
		{debug("needn=%ld",needn);	}
	#endif

	if (needn>0) {
	        /* fputmanyc(rep->output,' ',(int)needn); */
	        rep->col_no+=needn;
	#ifdef DEBUG
		{debug("Colno increased by %d",needn);}
	#endif
	} else {
	#ifdef DEBUG
		{debug("Already past that point");}
	#endif
	}
	push_char("");
}


/**
 *
 * @todo Describe function
 */
void
pdf_skip_to(struct pdf_rep_structure *rep,double a)
{
	debug("pdf_skip_by");
	a=pdf_size(a,'l',rep);
	rep->line_no=a;
}


/**
 *
 * @todo Describe function
 */
void 
pdf_skip_by(struct pdf_rep_structure *rep,double a) 
{
	debug("pdf_skip_by");
	a=pdf_size(a,'l',rep);
	rep->line_no+=a;
	debug("DOne skip by line_no=%f",rep->line_no);
}

/**
 *
 * @todo Describe function
 */
void 
pdf_aclfgli_skip_lines(struct pdf_rep_structure *rep)
{
long a;

	debug("skip lines");
	a=pop_long();
	rep->line_no+=pdf_metric(a,'l',rep);
}

/**
 *
 * @todo Describe function
 */
void
pdf_need_lines(struct pdf_rep_structure *rep)
{
int a;
	debug("need lines");
	a=pdf_metric(pop_int(),'l',rep);
	if (rep->line_no > (rep->page_length - rep->bottom_margin -a))
	      pdf_skip_top_of_page(rep);
}

/**
 *
 * @todo Describe function
 */
void
pdf_skip_top_of_page(struct pdf_rep_structure *rep)
{
int z;
	z=rep->page_no;

	while (z==rep->page_no) {
	     push_char("");
	     pdf_rep_print(rep,1,0,0);
	}

}

/**
 *
 * @todo Describe function
 */
void
pdf_add_spaces(void)
{
int a;
char str[1000];
	a=pop_int();
	if (a>=1000) a=999;
	memset(str,' ',a);
	str[a]=0;
	push_char(str);
}



/**
 *
 * @todo Describe function
 */
int
pdf_new_page(struct pdf_rep_structure *p)
{
	debug("NEW PAGE : %d\n",p->page_no);
	/* PDF_begin_page(p->pdf_ptr, width, height); */
	if (p->page_no) {
		PDF_end_page(p->pdf_ptr);
	}

	debug("Begin page %lf %lf\n",p->page_width,p->page_length);
		PDF_begin_page(p->pdf_ptr, p->page_width, p->page_length);
	debug("Done\n");
	debug("find font %s\n",p->font_name);
		p->font = PDF_findfont(p->pdf_ptr, p->font_name, "winansi",0  );

		if (p->font<0) {
			exitwith("Unable to locate font");
			return 0;
		} else {
			debug("findfont ok");
		}

	debug("set font\n");
		PDF_setfont(p->pdf_ptr, p->font, p->font_size);
	debug("ok!\n");
return 1;
}

/**
 *
 * @todo Describe function
 */
void
pdf_set_info (void *p,char *creator)
{
  PDF_set_info (p, "Creator",  creator);
  PDF_set_info (p, "Author",   "Auto");
  PDF_set_info (p, "Title",    "Auto");
}


/**
 *
 * @todo Describe function
 */
void
pdf_move(struct pdf_rep_structure *p)
{
      debug("Move to %f %f",p->col_no,p->line_no);
      PDF_set_text_pos(p->pdf_ptr,p->col_no, p->page_length-p->line_no);
}


/**
 *
 * @todo Describe function
 */
void
pdf_rep_close(struct pdf_rep_structure *p)
{
	debug("Closing report %f\n",p->line_no);
		if (p->line_no!=0.0) {
	debug("A");
			PDF_end_page(p->pdf_ptr);
	debug("A");
			PDF_close(p->pdf_ptr);
		}
	debug("All done...");
}


/**
 *
 * @todo Describe function
 */
double 
pdf_size(double f, char c,struct pdf_rep_structure *p) 
{
	debug("pdf_size (%lf %c %p)",f,c,p);

	if (f<0) {
		debug("Returning 0-%lf",f);
		return 0-f; /* This is already in PDF units */
	}
	else return pdf_metric((int)f,c,p); /* This is in lines or chars */

}


/**
 *
 * @todo Describe function
 */
double 
pdf_metric(int a,char  c,struct pdf_rep_structure *p) 
{
	debug("pdf_metric a=%d c=%c p=%p",a,c,p);

	if (c=='c') {
			debug("metric C %d %c",a,c);
			return (double)((double)a*PDF_stringwidth(p->pdf_ptr,"W",p->font,p->font_size));
	} else {
		debug("metric L %d %c",a,c);
			return (double)(a*p->font_size); /* 18 */
	}
}

/**
 *
 * @todo Describe function
 */
int
aclpdf(struct pdf_rep_structure *p,char *fname,int n)
{
char *ptr;
int a;
double d;

	if (strcmp(fname,"set_parameter")==0) {
		char *ptr1;
		char *ptr2;
		ptr2=char_pop();
		ptr1=char_pop();
		PDF_set_parameter(p->pdf_ptr,ptr1,ptr2);
		acl_free(ptr1);
		acl_free(ptr2);
		return 0;
	}
	if (strcmp(fname,"set_value")==0) {
		char *ptr1;
		int a;
		a=pop_int();
		ptr1=char_pop();
		debug("Setting pdf value %s to %d\n",ptr1,a);
		PDF_set_value(p->pdf_ptr,ptr1,a);
		acl_free(ptr1);
		return 0;
	}


	if (strcmp(fname,"set_font_size")==0) {
		d=pop_double();
		p->font_size=d;
		PDF_setfont(p->pdf_ptr, p->font,p->font_size); 
	return 0;
	}

	if (strcmp(fname,"set_font_name")==0) { 
		ptr=char_pop();
		strcpy(p->font_name,ptr);
		acl_free(ptr);
		a= PDF_findfont(p->pdf_ptr, p->font_name, "winansi",0  );
		if (a<0) {
			exitwith("Unable to locate font");
			return 0;
		} else {
		debug ("Findfont ok");
	}
		p->font =a;
		PDF_setfont(p->pdf_ptr, p->font, p->font_size); 
	return 0;
	}
return 0;
}



/**
 *
 * @todo Describe function
 */
int
pdf_blob_print(struct pdf_rep_structure *p,struct fgl_int_loc *blob,char *type,int cr)
{
int n;
double sx;
double sy;
int x,y;

	sx=pop_double();
	sy=pop_double();
	debug("Scaling by %f %f",sx,sy);
  if (blob->where != 'F' && blob->where != 'M')
    {
      exitwith ("Blob not located");
      return 0;
    }

  if (blob->where!='F') {
	exitwith("Not implemented yet...\n");
	return 0;
  }

	debug("Opening blob\n");
	n=PDF_open_image_file(p->pdf_ptr,type,blob->filename,"",0);
	debug("Image handle=%d\n",n);

	if (n<0) {
		/* exitwith("Unable to open file %s %s",type,blob->filename); */
        exitwith("Unable to open file.");
		return 0;
	}

  	y = PDF_get_value (p->pdf_ptr, "imageheight", n);
  	x = PDF_get_value (p->pdf_ptr, "imagewidth", n);

	y=(int)((double)y * sy);
	x=(int)((double)x * sx);

	debug("Placing heght of image =%d line=%f length=%f",
		y,p->line_no,
		p->page_length);

    	if (p->col_no==0) {
         p->col_no+=p->left_margin;
    	}
	debug("x=%lf y=%lf",p->col_no,p->page_length-p->line_no-y);

	PDF_place_image(p->pdf_ptr,n,p->col_no,p->page_length-p->line_no-y,sx);

	debug("Closing");
	PDF_close_image(p->pdf_ptr,n);
	p->line_no=p->line_no+(double)y;
	p->col_no=p->col_no+(double)x;
	push_char("");
	pdf_rep_print (p, 1, cr,0);
return 1;
}


/**
 *
 * @todo Describe function
 */
void
A4GLREPORT_initlib (void)
{
	debug("Calling PDF_boot");
	PDF_boot();
}

/* ================================ EOF ============================== */

