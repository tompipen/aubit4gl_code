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
# $Id: has_pdf.c,v 1.16 2004-05-19 15:10:03 mikeaubury Exp $
#*/

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

#include "pdflib.h"

#include "a4gl_runtime_tui.h"	/* A4GL_push_int */
#include "a4gl_dbform.h"
#include "a4gl_report.h"
#include "a4gl_stack.h"
#include "a4gl_aubit_lib.h"
#include "a4gl_debug.h"

#else

#include "a4gl_lib_exreport_pdf_int.h"

#endif

#ifdef NOT_REQUIRED
double A4GL_pdf_size (double f, char c, struct pdf_rep_structure *p);
/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

/* double 	pdf_size		(double f, char c,struct pdf_rep_structure *p) ; */
void A4GL_pdf_skip_by (struct pdf_rep_structure *rep, double a);
void A4GL_pdf_aclfgli_skip_lines (struct pdf_rep_structure *rep);
void A4GL_pdf_fputmanyc (FILE * f, int c, int cnt);
void A4GL_pdf_set_column (struct pdf_rep_structure *rep);
void A4GL_pdf_set_info (void *p, char *creator);
void A4GL_pdf_skip_top_of_page (struct pdf_rep_structure *rep);

void A4GL_pdf_rep_print (struct pdf_rep_structure *rep, int a, int s,
		    int right_margin);
void A4GL_pdf_skip_to (struct pdf_rep_structure *rep, double a);
void A4GL_pdf_need_lines (struct pdf_rep_structure *rep);
void A4GL_pdf_add_spaces (void);
void A4GL_pdf_rep_close (struct pdf_rep_structure *p);
int aclpdf (struct pdf_rep_structure *p, char *fname, int n);
int A4GL_pdf_blob_print (struct pdf_rep_structure *p, struct fgl_int_loc *blob,
		    char *type, int cr);
#endif
int A4GL_pdf_new_page (struct pdf_rep_structure *p);
double A4GL_pdf_metric (int a, char c, struct pdf_rep_structure *rep);
void A4GL_pdf_move (struct pdf_rep_structure *p);

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
A4GL_pdf_rep_print (void *vrep, int a, int s, int right_margin,int why)
{
  int b;
  char *str;
struct pdf_rep_structure *rep;
rep=vrep;

  A4GL_debug ("In rep_print");
  if (right_margin != 0)
    {
      A4GL_debug ("***** WARNING ***** wordwrap margin not implemented..");
    }
  if (rep->line_no == 0 && rep->page_no == 0)
    {
      if (rep->output_mode == 'F')
	{
	  if (strcmp (rep->output_loc, "stdout") == 0)
	    {
	      A4GL_push_char ("");
	      A4GL_push_int (-1);
	      A4GL_push_int (-1);
	      A4GL_display_at (1, 0);
	      rep->output = stdout;
	    }
	  else
	    {
	      rep->pdf_ptr = PDF_new ();
	      A4GL_debug ("Opening file: %s\n", rep->output_loc);
	      if (PDF_open_file (rep->pdf_ptr, rep->output_loc) == -1)
		{
		  A4GL_exitwith ("Error opening output\n");
		  return;
		}
	      A4GL_debug ("Set info");
	      A4GL_pdf_set_info (rep->pdf_ptr, "A4GL");
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
	      A4GL_exitwith ("Could not open report output");
	      return;
	    }
	}
    }

  if (rep->line_no == 0)
    {
      A4GL_debug ("New page...");
      A4GL_pdf_new_page (rep);
      A4GL_debug ("set line 1");
      rep->line_no = A4GL_pdf_metric (1, 'l', rep);
      A4GL_debug ("Adding to page no...");
      rep->page_no++;
      A4GL_debug ("Need page header");

      A4GL_pdf_skip_by (rep, 0.0 - rep->top_margin);
      rep->report (0, REPORT_PAGEHEADER);
    }

  A4GL_debug ("Popping %d parameters", a);
  if (a > 0)
    {

      if (rep->col_no == 0)
	{
	  rep->col_no += rep->left_margin;
	}
      for (b = 0; b < a; b++)
	{

	  A4GL_debug ("A\n");
	  str = A4GL_char_pop ();
	  A4GL_debug ("Popped '%s'...", str);
	  A4GL_debug ("Popped %s\n", str);
	  A4GL_pdf_move (rep);
	  PDF_show (rep->pdf_ptr, str);
	  A4GL_debug ("Adding %f to col_no\n",
		 A4GL_pdf_metric (strlen (str), 'c', rep));
	  rep->col_no += A4GL_pdf_metric (strlen (str), 'c', rep);
	  acl_free (str);
	}
      A4GL_pdf_move (rep);
    }
  A4GL_debug ("Newline : %d", s);

  if (s == 0)
    {
      A4GL_debug ("B\n");
      A4GL_pdf_move (rep);
      rep->col_no = 0;
      A4GL_debug ("CR\n");
      rep->line_no += A4GL_pdf_metric (1, 'l', rep);

      if (rep->line_no > rep->page_length - rep->bottom_margin)
	{
	  rep->line_no = 0;
	  A4GL_pdf_rep_print (rep, 0, 0, 0,-1);
	}
    }
  fflush (rep->output);
  A4GL_debug ("Done\n");
  return;
}


/**
 *
 * @todo Describe function
 */
void
A4GL_pdf_fputmanyc (FILE * f, int c, int cnt)
{
  int a;
  for (a = 0; a < cnt; a++)
    fputc (c, f);
}

/**
 *
 * @todo Describe function
 */
void
A4GL_pdf_set_column (void *vrep)
{
  double a;
  double needn;
  double req;
struct pdf_rep_structure *rep;
rep=vrep;

  A4GL_debug ("Set column");
  req=(double)A4GL_pop_double ();
  a = A4GL_pdf_size(req , 'c', rep);

  if (rep->col_no == 0.0)
    {
      A4GL_debug ("setcol");
      rep->col_no = A4GL_pdf_metric (1, 'c', rep);
    }

  needn = a - rep->col_no + rep->left_margin;	/* -pdf_metric(1,'c',rep); */


  /* if (rep->col_no==pdf_metric(1,'c',rep)) needn+=pdf_metric(1,'c',rep); */

#ifdef DEBUG
  {
    A4GL_debug ("needn=%ld", needn);
  }
#endif

  if (needn > 0)
    {
      /* fputmanyc(rep->output,' ',(int)needn); */
      rep->col_no += needn;
#ifdef DEBUG
      {
 printf ("Colno increased by %f\n", needn);
 A4GL_debug ("Colno increased by %d", needn);
      }
#endif
    }
  else
    {
#ifdef DEBUG
      {
	      //printf("Already past it\n");
 A4GL_debug ("Already past that point");
      }
#endif
    }
  A4GL_push_char ("");
  A4GL_pdf_move (rep);

}


/**
 *
 * @todo Describe function
 */
void
A4GL_pdf_skip_to (void *vrep, double a)
{
struct pdf_rep_structure *rep;
rep=vrep;

  A4GL_debug ("pdf_skip_by");
  a = A4GL_pdf_size (a, 'l', rep);
  //printf("SKIP TO : %f",a);
  rep->line_no = a;
}


/**
 *
 * @todo Describe function
 */
void
A4GL_pdf_skip_by (void *vrep, double a)
{
struct pdf_rep_structure *rep;
rep=vrep;

  A4GL_debug ("pdf_skip_by");
  a = A4GL_pdf_size (a, 'l', rep);
  rep->line_no += a;
  A4GL_debug ("DOne skip by line_no=%f", rep->line_no);
}

/**
 *
 * @todo Describe function
 */
void
A4GL_pdf_aclfgli_skip_lines (void *vrep)
{
  long a;
struct pdf_rep_structure *rep;
rep=vrep;


  A4GL_debug ("skip lines");
  a = A4GL_pop_long ();
  rep->line_no += A4GL_pdf_metric (a, 'l', rep);
}

/**
 *
 * @todo Describe function
 */
void
A4GL_pdf_need_lines (void *vrep)
{
  int a;
struct pdf_rep_structure *rep;
rep=vrep;

  A4GL_debug ("need lines");
  a = A4GL_pdf_metric (A4GL_pop_int (), 'l', rep);
  if (rep->line_no > (rep->page_length - rep->bottom_margin - a))
    A4GL_pdf_skip_top_of_page (rep);
}

/**
 *
 * @todo Describe function
 */
void
A4GL_pdf_skip_top_of_page (void *vrep)
{
  int z;
struct pdf_rep_structure *rep;
rep=vrep;

  z = rep->page_no;

  while (z == rep->page_no)
    {
      A4GL_push_char ("");
      A4GL_pdf_rep_print (rep, 1, 0, 0,-1);
    }

}

/**
 *
 * @todo Describe function
 */
void
A4GL_pdf_add_spaces (void)
{
  int a;
  char str[1000];
  a = A4GL_pop_int ();
  if (a >= 1000)
    a = 999;
  memset (str, ' ', a);
  str[a] = 0;
  A4GL_push_char (str);
}



/**
 *
 * @todo Describe function
 */
int
A4GL_pdf_new_page (struct pdf_rep_structure *p)
{
  A4GL_debug ("NEW PAGE : %d\n", p->page_no);
  /* PDF_begin_page(p->pdf_ptr, width, height); */
  if (p->page_no)
    {
      PDF_end_page (p->pdf_ptr);
    }

  A4GL_debug ("Begin page %lf %lf\n", p->page_width, p->page_length);
  PDF_begin_page (p->pdf_ptr, p->page_width, p->page_length);
  A4GL_debug ("Done\n");
  A4GL_debug ("find font %s\n", p->font_name);
  p->font = PDF_findfont (p->pdf_ptr, p->font_name, "winansi", 0);

  if (p->font < 0)
    {
      A4GL_exitwith ("Unable to locate font");
      return 0;
    }
  else
    {
      A4GL_debug ("findfont ok");
    }

  A4GL_debug ("set font\n");
  PDF_setfont (p->pdf_ptr, p->font, p->font_size);
  A4GL_debug ("ok!\n");
  return 1;
}

/**
 *
 * @todo Describe function
 */
void
A4GL_pdf_set_info (void *p, char *creator)
{
  PDF_set_info (p, "Creator", creator);
  PDF_set_info (p, "Author", "Auto");
  PDF_set_info (p, "Title", "Auto");
}


/**
 *
 * @todo Describe function
 */
void
A4GL_pdf_move (struct pdf_rep_structure *p)
{
  A4GL_debug ("Move to %f %f", p->col_no, p->line_no);
  printf ("Move to %f %f\n", p->col_no, p->line_no);
  PDF_set_text_pos (p->pdf_ptr, p->col_no, p->page_length - p->line_no);
}


/**
 *
 * @todo Describe function
 */
void
A4GL_pdf_rep_close (void *vp)
{
struct pdf_rep_structure *p;
p=vp;

  A4GL_debug ("Closing report %f\n", p->line_no);
  if (p->line_no != 0.0)
    {
      A4GL_debug ("A");
      PDF_end_page (p->pdf_ptr);
      A4GL_debug ("A");
      PDF_close (p->pdf_ptr);
    }
  A4GL_debug ("All done...");
}


/**
 *
 * @todo Describe function
 */
double
A4GL_pdf_size (double f, char c, void *vp)
{
  int size;
struct pdf_rep_structure *p;
p=vp;

  A4GL_debug ("pdf_size (%lf %c %p)", f, c, p);

  if (f < 0)
    {
      A4GL_debug ("Returning 0-%lf", f);
      return 0 - f;		/* This is already in PDF units */
    }

    size=f;
    return A4GL_pdf_metric (size, c, p);	/* This is in lines or chars */

}


/**
 *
 * @todo Describe function
 */
double
A4GL_pdf_metric (int a, char c, struct pdf_rep_structure *p)
{
  A4GL_debug ("pdf_metric a=%d c=%c p=%p", a, c, p);

  if (c == 'c')
    {
      A4GL_debug ("metric C %d %c", a, c);
      return (double) ((double) a *
		       PDF_stringwidth (p->pdf_ptr, "W", p->font,
					p->font_size));
    }
  else
    {
      A4GL_debug ("metric L %d %c", a, c);
      return (double) (a * p->font_size);	/* 18 */
    }
}

/**
 *
 * @todo Describe function
 */
int
aclpdf (struct pdf_rep_structure *p, char *fname, int n)
{
  char *ptr;
  int a;
  double d;

  if (strcmp (fname, "set_parameter") == 0)
    {
      char *ptr1;
      char *ptr2;
      ptr2 = A4GL_char_pop ();
      ptr1 = A4GL_char_pop ();
      PDF_set_parameter (p->pdf_ptr, ptr1, ptr2);
      acl_free (ptr1);
      acl_free (ptr2);
      return 0;
    }
  if (strcmp (fname, "set_value") == 0)
    {
      char *ptr1;
      int a;
      a = A4GL_pop_int ();
      ptr1 = A4GL_char_pop ();
      A4GL_debug ("Setting pdf value %s to %d\n", ptr1, a);
      PDF_set_value (p->pdf_ptr, ptr1, a);
      acl_free (ptr1);
      return 0;
    }


  if (strcmp (fname, "set_font_size") == 0)
    {
      d = A4GL_pop_double ();
      p->font_size = d;
      PDF_setfont (p->pdf_ptr, p->font, p->font_size);
      return 0;
    }

  if (strcmp (fname, "set_font_name") == 0)
    {
      ptr = A4GL_char_pop ();
      strcpy (p->font_name, ptr);
      acl_free (ptr);
      a = PDF_findfont (p->pdf_ptr, p->font_name, "winansi", 0);
      if (a < 0)
	{
	  A4GL_exitwith ("Unable to locate font");
	  return 0;
	}
      else
	{
	  A4GL_debug ("Findfont ok");
	}
      p->font = a;
      PDF_setfont (p->pdf_ptr, p->font, p->font_size);
      return 0;
    }
  return 0;
}



/**
 *
 * @todo Describe function
 */


void A4GL_pdf_blob_print (void *vp, void *vblob, char *type, int cr)
{
  int n;
  double sx;
  double sy;
  int x, y;
struct pdf_rep_structure *p;
struct fgl_int_loc *blob;
p=vp;
blob=vblob;


  sx = A4GL_pop_double ();
  sy = A4GL_pop_double ();
  A4GL_debug ("Scaling by %f %f", sx, sy);
  if (blob->where != 'F' && blob->where != 'M')
    {
      A4GL_exitwith ("Blob not located");
      return ;
    }

  if (blob->where != 'F')
    {
      A4GL_exitwith ("Not implemented yet...\n");
      return ;
    }

  A4GL_debug ("Opening blob\n");
  n = PDF_open_image_file (p->pdf_ptr, type, blob->filename, "", 0);
  A4GL_debug ("Image handle=%d\n", n);

  if (n < 0)
    {
      /* exitwith("Unable to open file %s %s",type,blob->filename); */
      A4GL_exitwith ("Unable to open file.");
      return ;
    }

  y = PDF_get_value (p->pdf_ptr, "imageheight", n);
  x = PDF_get_value (p->pdf_ptr, "imagewidth", n);

  y = (int) ((double) y * sy);
  x = (int) ((double) x * sx);

  A4GL_debug ("Placing heght of image =%d line=%f length=%f",
	 y, p->line_no, p->page_length);

  if (p->col_no == 0)
    {
      p->col_no += p->left_margin;
    }
  A4GL_debug ("x=%lf y=%lf", p->col_no, p->page_length - p->line_no - y);

  PDF_place_image (p->pdf_ptr, n, p->col_no, p->page_length - p->line_no - y,
		   sx);

  A4GL_debug ("Closing");
  PDF_close_image (p->pdf_ptr, n);
  p->line_no = p->line_no + (double) y;
  p->col_no = p->col_no + (double) x;
  A4GL_push_char ("");
  A4GL_pdf_rep_print (p, 1, cr, 0,-1);
  return;
}



int A4GL_pdf_pdffunc (void *vp,char *fname,int n) {
char *ptr;
int a;
double d;
struct pdf_rep_structure *p;
p=vp;


        if (strcmp(fname,"set_parameter")==0) {
                char *ptr1;
                char *ptr2;
                ptr2=A4GL_char_pop();
                ptr1=A4GL_char_pop();
                PDF_set_parameter(p->pdf_ptr,ptr1,ptr2);
                acl_free(ptr1);
                acl_free(ptr2);
                return 0;
        }
        if (strcmp(fname,"moveto")==0) {
                float f1;
                float f2; 
                f2=A4GL_pop_double();
                f1=A4GL_pop_double();
                PDF_moveto(p->pdf_ptr,f1,f2);
                return 0;
        }
        if (strcmp(fname,"stroke")==0) {
                PDF_stroke(p->pdf_ptr);
                return 0;
        }


        if (strcmp(fname,"lineto")==0) {
                float f1;
                float f2; 
                f2=A4GL_pop_double();
                f1=A4GL_pop_double();
                PDF_lineto(p->pdf_ptr,f1,f2);
                return 0;
        }



        if (strcmp(fname,"set_value")==0) {
                char *ptr1;
                int a;
                a=A4GL_pop_int();
                ptr1=A4GL_char_pop();
                A4GL_debug("Setting pdf value %s to %d\n",ptr1,a);
                PDF_set_value(p->pdf_ptr,ptr1,a);
                acl_free(ptr1);
                return 0;
        }


        if (strcmp(fname,"set_font_size")==0) {
                d=A4GL_pop_double();
                p->font_size=d;
                PDF_setfont(p->pdf_ptr, p->font,p->font_size);
        return 0;
        }

        if (strcmp(fname,"set_font_name")==0) {
                ptr=A4GL_char_pop();
                strcpy(p->font_name,ptr);
                acl_free(ptr);
                a= PDF_findfont(p->pdf_ptr, p->font_name, "winansi",0  );
                if (a<0) {
                        A4GL_exitwith("Unable to locate font");
                        return 0;
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
void
A4GLREPORT_initlib (void)
{
  A4GL_debug ("Calling PDF_boot");
  PDF_boot ();
}

/* ================================ EOF ============================== */
