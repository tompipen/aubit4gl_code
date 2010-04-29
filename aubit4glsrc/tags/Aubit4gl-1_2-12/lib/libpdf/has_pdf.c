/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-2005 Aubit Development Team (See Credits file)    |
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
# | contact licensing@aubit.com                                           |
# +----------------------------------------------------------------------+
#
# $Id: has_pdf.c,v 1.72 2010-03-24 17:51:06 mikeaubury Exp $
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


#define USE_PDFLIB_H
#include "a4gl_lib_exreport_pdf_int.h"
void generate_barcode(PDF *p, double xpos,double ypos,double x,double y,char *str,float p_page_height,int incl_text);
void set_barcode_type(char *s);


#define SECTION_NORMAL 0
#define SECTION_HEADER 1
#define SECTION_TRAILER 2
static char * A4GL_report_char_pop (void);

//int aclpdf (struct pdf_rep_structure *p, char *fname, int n);
void A4GL_pdf_add_spaces (void);
int A4GL_pdf_new_page (struct pdf_rep_structure *p);
double A4GL_pdf_metric (int a, char c, struct pdf_rep_structure *rep);
void A4GL_pdf_move (struct pdf_rep_structure *p);
void A4GLREPORT_initlib (void);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


double fill_color_r=0.0;
double fill_color_g=0.0;
double fill_color_b=0.0;
double stroke_color_r=0.0;
double stroke_color_g=0.0;
double stroke_color_b=0.0;

static void A4GL_setcolor(PDF *p, const char *fstype, const char *colorspace, double c1, double c2, double c3, double c4) {
if (strcmp(colorspace,"rgb")!=0) {
	A4GL_assertion(1,"A4GL_setcolor must be rgb");
}

if (strcmp(fstype,"fill")==0) {
	fill_color_r=c1;
	fill_color_g=c2;
	fill_color_b=c3;
	PDF_setcolor(p,fstype,colorspace,c1,c2,c3,c4);
	return;
}

if (strcmp(fstype,"stroke")==0) {
	stroke_color_r=c1;
	stroke_color_g=c2;
	stroke_color_b=c3;
	PDF_setcolor(p,fstype,colorspace,c1,c2,c3,c4);
	return;
}
if (strcmp(fstype,"both")==0) {
	fill_color_r=c1;
	fill_color_g=c2;
	fill_color_b=c3;
	stroke_color_r=c1;
	stroke_color_g=c2;
	stroke_color_b=c3;
	PDF_setcolor(p,fstype,colorspace,c1,c2,c3,c4);
	return;
}

A4GL_assertion(1,"unexpected fstype");
}


static void A4GL_resetcolor(PDF *p) {
	PDF_setcolor(p,"fill","rgb",fill_color_r, fill_color_g,fill_color_b,0);
	PDF_setcolor(p,"stroke","rgb",stroke_color_r, stroke_color_g,stroke_color_b,0);
}



/**
 *
 * a = number to pop
 * s = semi colon at the end
 *
 * @todo Describe function
 */
void
A4GLPDFREP_A4GL_pdf_rep_print (void *vrep, int a, int s, int right_margin, int why)
{
  int b;
int entry=0;
  char *str;
  struct pdf_rep_structure *rep;
  //static int resetting=0;

  rep = (struct pdf_rep_structure *)vrep;

#ifdef DEBUG
  A4GL_debug ("In rep_print");
#endif
  if (right_margin != 0)
    {
#ifdef DEBUG
      A4GL_debug ("***** WARNING ***** wordwrap margin not implemented..");
#endif
    }
  if (rep->line_no == 0 && rep->page_no == 0)
    {
      if (rep->output_mode == 'C')
	{
	  tmpnam (rep->output_loc_str);
	  rep->output = fopen (rep->output_loc_str, "w");
	  if (rep->output == 0)
	    {
	      A4GL_exitwith ("Could not open report output");
	      return;
	    }

	}
      else
	{

	  if (rep->output_mode == 'F')
	    {
	      if (strcmp (rep->output_loc_str, "stdout") == 0)
		{
		  A4GL_push_empty_char ();
		  A4GL_push_int (-1);
		  A4GL_push_int (-1);
		  A4GL_display_at (1, 0);
		  rep->output = stdout;
		}
	      else
		{
		  rep->pdf_ptr = (void *)PDF_new ();
		  PDF_set_parameter((PDF *)rep->pdf_ptr,"compatibility","1.4");
#ifdef DEBUG
		  A4GL_debug ("Opening file: %s\n", rep->output_loc_str);
#endif
		  if (PDF_open_file ((PDF*)rep->pdf_ptr, rep->output_loc_str) == -1)
		    {
		      A4GL_exitwith ("Error opening output\n");
		      return;
		    }
#ifdef DEBUG
		  A4GL_debug ("Set info");
#endif
		  A4GLPDFREP_A4GL_pdf_set_info (rep->pdf_ptr, "A4GL");
		}
	    }
	  else
	    {
	      rep->output = popen (rep->output_loc_str, "w");
	      if (rep->output == 0)
		{
		  A4GL_exitwith ("Could not open report output");
		  return;
		}
	    }
	}
    }



  if (a < 0)
    {                           // We're just setting up...
      return;
    }



  if (a || s == 0 || rep->finishing || entry == -5)
    {
      if (rep->print_section == SECTION_NORMAL)
        {
          if (rep->line_no >
              rep->page_length -  A4GL_pdf_metric (rep->lines_in_trailer , 'l', rep)   - rep->bottom_margin)
            {
              rep->print_section = SECTION_TRAILER;
              rep->report (0, REPORT_PAGETRAILER);      /* report.c:180: too many arguments to function */
              rep->print_section = SECTION_NORMAL;
            }

          if (rep->line_no > rep->page_length - rep->bottom_margin)
            {
#ifdef DEBUG
			A4GL_debug("setting line_no=0");
#endif
              rep->line_no = 0;
              if (rep->lines_in_trailer)
                {
#ifdef DEBUG
                  A4GL_debug ("Calling rep_print");
#endif
                  A4GL_pdf_rep_print (rep, 0, 1, 0, -10);
                }
            }
        }
    }



  if (rep->line_no == 0 && !rep->finishing)
    {
#ifdef DEBUG
      A4GL_debug ("New page...");
#endif
      A4GL_pdf_new_page (rep);
#ifdef DEBUG
      A4GL_debug ("set line 1");
#endif
      rep->line_no = A4GL_pdf_metric (1, 'l', rep);
#ifdef DEBUG
      A4GL_debug ("Adding to page no...");
#endif
      rep->page_no++;

#ifdef DEBUG
      A4GL_debug ("Need page header");
#endif
     rep->print_section = SECTION_HEADER;


      A4GLPDFREP_A4GL_pdf_skip_by (rep, 0.0 - rep->top_margin);
      rep->report (0, REPORT_PAGEHEADER);
     rep->print_section = SECTION_NORMAL;
	return;
    }

#ifdef DEBUG
  A4GL_debug ("Popping %d parameters", a);
#endif


  if (a > 0)
    {

      if (rep->col_no == 0)
	{
	  rep->col_no += rep->left_margin;
	}
      for (b = 0; b < a; b++)
	{

#ifdef DEBUG
	  A4GL_debug ("A\n");
#endif
	  str =  A4GL_report_char_pop ();
	  A4GL_pdf_move (rep); 
	  PDF_show ((PDF *)rep->pdf_ptr, str);
#ifdef DEBUG
	  A4GL_debug ("Adding %f to col_no\n", A4GL_pdf_metric (strlen (str), 'c', rep));
#endif
	  rep->col_no += A4GL_pdf_metric (strlen (str), 'c', rep);
	  acl_free (str);
	}
      A4GL_pdf_move (rep);
    }

#ifdef DEBUG
  A4GL_debug ("Newline : %d", s);
#endif

  if (s == 0)
    {
#ifdef DEBUG
      A4GL_debug ("B\n");
#endif
      A4GL_pdf_move (rep);
      rep->col_no = 0;
#ifdef DEBUG
      A4GL_debug ("CR lineno was %lf\n",rep->line_no);
#endif
      rep->line_no += A4GL_pdf_metric (1, 'l', rep);
#ifdef DEBUG
      A4GL_debug ("CR lineno now %lf\n",rep->line_no);
#endif

      if (rep->line_no > rep->page_length - rep->bottom_margin)
	{
#ifdef DEBUG
			A4GL_debug("setting line_no=0 lineno=%lf page_length=%lf bottom_margin=%lf", rep->line_no, rep->page_length, rep->bottom_margin);
#endif
	  rep->line_no = 0;
	  A4GL_pdf_rep_print (rep, 0, 0, 0, -1);
	}
    }
  fflush (rep->output);
#ifdef DEBUG
  A4GL_debug ("Done\n");
#endif
  return;
}

/**
 *
 * @todo Describe function
 */



/**
 *
 * @todo Describe function
 */
void
A4GLPDFREP_A4GL_pdf_set_column (void *vrep)
{
  double a;
  double needn;
  double req;
  struct pdf_rep_structure *rep;
  int force_move;
  rep = (struct pdf_rep_structure *)vrep;

#ifdef DEBUG
  A4GL_debug ("Set column");
#endif

  A4GL_push_empty_char();
  A4GL_pdf_rep_print (rep, 1, 1, 0, -2);


  req = (double) A4GL_pop_double ();
  force_move=0;
  if (req<0) {
	  force_move=1;
  }
  a = A4GLPDFREP_A4GL_pdf_size (req, 'c', rep);

  if (rep->col_no == 0.0)
    {
#ifdef DEBUG
      A4GL_debug ("setcol");
#endif
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
	A4GL_debug ("Colno increased by %d", needn);
      }
#endif
    }
  else
    {
	    if (force_move) {
		    rep->col_no=a+rep->left_margin;
	    }
#ifdef DEBUG
      {
	A4GL_debug ("Already past that point");
      }
#endif
    }
  A4GL_push_empty_char ();
  A4GL_pdf_move (rep); 

}


/**
 *
 * @todo Describe function
 */
void
A4GLPDFREP_A4GL_pdf_skip_to (void *vrep, double a)
{
  struct pdf_rep_structure *rep;
  rep = (struct pdf_rep_structure *)vrep;

#ifdef DEBUG
  A4GL_debug ("pdf_skip_by");
#endif
  a = A4GLPDFREP_A4GL_pdf_size (a, 'l', rep);
#ifdef DEBUG
			A4GL_debug("setting line_no=%lf",a);
#endif
  rep->line_no = a;
  rep->col_no = 0;
}


/**
 *
 * @todo Describe function
 */
void
A4GLPDFREP_A4GL_pdf_skip_by (void *vrep, double a)
{
  struct pdf_rep_structure *rep;
  rep = (struct pdf_rep_structure *)vrep;

#ifdef DEBUG
  A4GL_debug ("pdf_skip_by");
#endif
  a = A4GLPDFREP_A4GL_pdf_size (a, 'l', rep);
  rep->line_no += a;
#ifdef DEBUG
  A4GL_debug ("DOne skip by line_no=%f", rep->line_no);
#endif
}

/**
 *
 * @todo Describe function
 */
void
A4GLPDFREP_A4GL_pdf_aclfgli_skip_lines (void *vrep)
{
  long a;
  struct pdf_rep_structure *rep;
  rep = (struct pdf_rep_structure *)vrep;


#ifdef DEBUG
  A4GL_debug ("skip lines");
#endif
  a = A4GL_pop_long ();
  rep->line_no += A4GL_pdf_metric (a, 'l', rep);
}

/**
 *
 * @todo Describe function
 */
void
A4GLPDFREP_A4GL_pdf_need_lines (void *vrep)
{
  int a;
  struct pdf_rep_structure *rep;
  rep = (struct pdf_rep_structure *)vrep;

#ifdef DEBUG
  A4GL_debug ("need lines");
#endif
  a = A4GL_pdf_metric (A4GL_pop_int (), 'l', rep);
  if (rep->line_no > (rep->page_length - rep->bottom_margin - a)) {
#ifdef DEBUG
			A4GL_debug("need forcing new page");
#endif
    		A4GL_pdf_skip_top_of_page (rep, 2);
	}
}

/**
 *
 * @todo Describe function
 */
void
A4GLPDFREP_A4GL_pdf_skip_top_of_page (void *vrep, int n)
{
  struct pdf_rep_structure *rep;
  int z;
  int a;
  double ad;

  rep = (struct pdf_rep_structure *)vrep;

#ifdef DEBUG
			A4GL_debug("pdf_skip_top_of_page");
#endif

  /* a = rep->page_length - rep->line_no - rep->bottom_margin - rep->lines_in_trailer; */

  a = rep->page_length - rep->line_no - rep->bottom_margin - A4GL_pdf_metric (rep->lines_in_trailer , 'l', rep) ;
//  ad = rep->page_length - rep->line_no - rep->bottom_margin - rep->lines_in_trailer;
  ad = rep->page_length - rep->bottom_margin - A4GL_pdf_metric (rep->lines_in_trailer , 'l', rep)  ;

  if (n != 1 || rep->page_no)
    {
      if (rep->header)
	return;
      if (rep->line_no == 0)
	return;
    }

  //A4GLPDFREP_A4GL_pdf_skip_to (vrep,  ad+0);
  rep->line_no = ad;
  
  A4GL_pdf_rep_print (rep, 0, 0, 0, -5);

  if (a &&0)
    {
    //double b;
      for (z = 0; z < a; z++)
	{
  		//b = rep->page_length - rep->line_no - rep->bottom_margin - rep->lines_in_trailer;

	  A4GL_pdf_rep_print (rep, 0, 0, 0, -4);
	}

      A4GL_pdf_rep_print (rep, 0, 0, 0, -5);
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
#ifdef DEBUG
  A4GL_debug ("NEW PAGE : %d\n", p->page_no);
#endif
  /* PDF_begin_page((PDF *)p->pdf_ptr, width, height); */
  if (p->page_no)
    {
      PDF_end_page ((PDF *)p->pdf_ptr);
    }

#ifdef DEBUG
  A4GL_debug ("Begin page width = %lf length=%lf\n", p->page_width, p->page_length);
#endif
  PDF_begin_page ((PDF *)p->pdf_ptr, p->page_width, p->page_length);
#ifdef DEBUG
  A4GL_debug ("Done\n");
  A4GL_debug ("find font %s\n", p->font_name);
#endif
     p->font = PDF_load_font ((PDF *)p->pdf_ptr, p->font_name, 0, A4GL_get_pdf_encoding(), ""); //"embedding=true");

  if (p->font < 0)
    {
      A4GL_exitwith ("Unable to locate font");
      return 0;
    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("findfont ok");
#endif
    }

#ifdef DEBUG
  A4GL_debug ("set font\n");
#endif
  PDF_setfont ((PDF *)p->pdf_ptr, p->font, p->font_size);

// do we need bluebars ? 
  if (p->bluebar_style!=E_BLUEBAR_NONE) {
	//double printable;
	double eachline;
		double ypos;

	//printable = p->page_height - (p->top_margin);
  	//eachline = printable / h;
  	eachline = A4GLPDFREP_A4GL_pdf_size (1, 'l', p);
  	PDF_setcolor ((PDF *)p->pdf_ptr, "both", "rgb", p->bluebar_r, p->bluebar_g, p->bluebar_b, 0);
  	PDF_setlinewidth ((PDF *)p->pdf_ptr, eachline / 20);

    if (p->bluebar_style == E_BLUEBAR_5LINE)
        {
		int a;
	ypos=p->page_length-p->top_margin;
          for (a = 0; ; a += 2)
            {
              //char *ptr;
              int bb;
	      //double ypos_spacing;
              float spacing;
              spacing = 0;
              spacing -= 2.0 * (float) eachline / 10;
              for (bb = 0; bb < 5; bb++)
                {
                  spacing -= 2.0 * (float) eachline / 10;
                  PDF_moveto ((PDF *)p->pdf_ptr, (0), ypos + spacing);
                  PDF_lineto ((PDF *)p->pdf_ptr, (p->page_width),ypos+spacing);
                }
		ypos=ypos-(eachline*2);
		if (ypos+eachline<p->bottom_margin) break;
            }
      PDF_stroke ((PDF *)p->pdf_ptr);
        }

      if (p->bluebar_style == E_BLUEBAR_RECTANGLE)
        {
	int a;
	ypos=p->page_length-(p->top_margin+eachline);

          for (a = 0; ; a += 2)
            {
              //char *ptr;
              //int bb;
              float offset;
		//ypos=a * eachline;
              //spacing -= (float) eachline / 10;
              offset = 2.0 * (float) eachline / 10;
		if (ypos+eachline>(p->page_length)) break;
                PDF_rect ((PDF *)p->pdf_ptr, (0), ypos -offset , p->page_width, eachline*0.9); 
		PDF_fill_stroke ((PDF *)p->pdf_ptr);
		ypos=ypos-(eachline*2);
		if (ypos+eachline<p->bottom_margin) break;
            }
        }


	A4GL_resetcolor((PDF *)p->pdf_ptr);

  }

#ifdef DEBUG
  A4GL_debug ("ok!\n");
#endif
  return 1;
}

/**
 *
 * @todo Describe function
 */
void
A4GLPDFREP_A4GL_pdf_set_info (void *p, char *creator)
{
  PDF_set_info ((PDF*)p, "Creator", creator);
  PDF_set_info ((PDF*)p, "Author", "Auto");
  PDF_set_info ((PDF*)p, "Title", "Auto");
}


/**
 *
 * @todo Describe function
 */
void
A4GL_pdf_move (struct pdf_rep_structure *p)
{
#ifdef DEBUG
  A4GL_debug ("Move to %f %f", p->col_no, p->line_no);
#endif
  //printf ("Move to %f %f\n", p->col_no, p->page_length -p->line_no);
  PDF_set_text_pos ((PDF *)p->pdf_ptr, p->col_no, p->page_length - p->line_no);
}


/**
 *
 * @todo Describe function
 */
void
A4GLPDFREP_A4GL_pdf_rep_close (void *vp)
{
  struct pdf_rep_structure *p;
  p = (struct pdf_rep_structure *)vp;

#ifdef DEBUG
  A4GL_debug ("Closing report %f\n", p->line_no);
#endif
  if (p->line_no != 0.0)
    {
#ifdef DEBUG
      A4GL_debug ("A");
#endif
      PDF_end_page ((PDF *)p->pdf_ptr);
#ifdef DEBUG
      A4GL_debug ("A");
#endif
      PDF_close ((PDF *)p->pdf_ptr);
    }
      p->pdf_ptr=0;
#ifdef DEBUG
  A4GL_debug ("All done...");
#endif
}


/**
 *
 * @todo Describe function
 */
double
A4GLPDFREP_A4GL_pdf_size (double f, char c, void *vp)
{
  int size;
  struct pdf_rep_structure *p;
  p = ( struct pdf_rep_structure *)vp;

#ifdef DEBUG
  A4GL_debug ("pdf_size (%lf %c %p)", f, c, p);
#endif

  if (f < 0)
    {
#ifdef DEBUG
      A4GL_debug ("Returning 0-%lf", f);
#endif
      return 0 - f;		/* This is already in PDF units */
    }

  size = f;
  return A4GL_pdf_metric (size, c, p);	/* This is in lines or chars */

}


/**
 *
 * @todo Describe function
 */
double
A4GL_pdf_metric (int a, char c, struct pdf_rep_structure *p)
{
#ifdef DEBUG
  A4GL_debug ("pdf_metric a=%d c=%c p=%p", a, c, p);
#endif

  if (c == 'c')
    {
#ifdef DEBUG
      A4GL_debug ("metric C %d %c", a, c);
#endif
      if (p->pdf_ptr) {
      	return (double) ((double) a * PDF_stringwidth ((PDF *)p->pdf_ptr, "W", p->font, p->font_size));
      } else {
      	return (double) ((double) a * 8);
      }

    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("metric L %d %c", a, c);
#endif
      return (double) (a * p->font_size);	/* 18 */
    }
}



/**
 *
 * @todo Describe function
 */


void
A4GLPDFREP_A4GL_pdf_blob_print (void *vp, void *vblob, char *type, int cr)
{
  int n;
  double sx;
  double sy;
  int x, y;
double ox;
double oy;
  struct pdf_rep_structure *p;
  struct fgl_int_loc *blob;
  p = (struct pdf_rep_structure *)vp;
  blob = (struct fgl_int_loc *)vblob;


  sx = A4GL_pop_double ();
  sy = A4GL_pop_double ();
#ifdef DEBUG
  A4GL_debug ("Scaling by %f %f", sx, sy);
#endif
  if (blob->where != 'F' && blob->where != 'M')
    {
      A4GL_exitwith ("Blob not located");
      return;
    }

  if (blob->where != 'F')
    {
      A4GL_exitwith ("Not implemented yet...\n");
      return;
    }

#ifdef DEBUG
  A4GL_debug ("Opening blob\n");
#endif
  n = PDF_open_image_file ((PDF *)p->pdf_ptr, type, blob->filename, "", 0);
#ifdef DEBUG
  A4GL_debug ("Image handle=%d\n", n);
#endif

  if (n < 0)
    {
      /* exitwith("Unable to open file %s %s",type,blob->filename); */
      /* An empty blob or invalid type (bmp) is also error,
         so just ignore and continue */
      /* A4GL_exitwith ("Unable to open file."); */
      return;
    }

  y = PDF_get_value ((PDF *)p->pdf_ptr, "imageheight", n);
  x = PDF_get_value ((PDF *)p->pdf_ptr, "imagewidth", n);

  ox=(double)x;
  oy=(double)y;
  sy=sx;
  y = (int) ((double) y * sy);
  x = (int) ((double) x * sx);

// If its just way to large to fit on the page - scale it back...
// this doesn't care if we're too far down the page etc - thats a different problem :-)
	while (y > (int)p->page_length) {
#ifdef DEBUG
			A4GL_debug("Too high %d %lf",y,p->page_length);
#endif
			sx*=0.99;
			sy*=0.99;
  			y = (int) (oy * sy);
  			x = (int) (ox * sx);
	}

	while (x > (int)p->page_width) {
#ifdef DEBUG
			A4GL_debug("Too wide %d %lf",x,p->page_width);
#endif
			sx*=0.99;
			sy*=0.99;
  			y = (int) (oy * sy);
  			x = (int) (ox * sx);
	}

#ifdef DEBUG
  A4GL_debug ("Placing heght of image =%d col=%f line=%f length=%f scale=%lf", y, p->col_no, p->line_no, p->page_length,sx);
#endif

  if (p->col_no == 0)
    {
      p->col_no += p->left_margin;
    }
#ifdef DEBUG
  A4GL_debug ("x=%lf y=%lf", p->col_no, p->page_length - p->line_no - y);
#endif

  PDF_place_image ((PDF *)p->pdf_ptr, n, p->col_no, p->page_length - p->line_no - y, sx);

#ifdef DEBUG
  A4GL_debug ("Closing");
#endif
  PDF_close_image ((PDF *)p->pdf_ptr, n);

#ifdef DEBUG
A4GL_debug("lineno (%lf) +=  %lf", p->line_no,(double)y);
A4GL_debug("colno (%lf) +=  %lf", p->col_no,(double)x);
#endif

  p->line_no = p->line_no + (double) y;
  p->col_no = p->col_no + (double) x;
  A4GL_push_empty_char ();
  A4GL_pdf_rep_print (p, 1, cr, 0, -1);
  return;
}


void
A4GLPDFREP_A4GL_pdf_image_print (void *vp, char *type, int cr)
{
  int n;
  double sx;
  double sy;
  int x, y;
  double ox;
  double oy;
  char *filename;
  struct pdf_rep_structure *p;
  p = (struct pdf_rep_structure *)vp;


  filename=A4GL_char_pop();
  A4GL_trim(filename);

  sx = A4GL_pop_double ();
  sy = A4GL_pop_double ();

  n = PDF_open_image_file ((PDF *)p->pdf_ptr, type, filename, "", 0);

  if (n < 0)
    {
      /* exitwith("Unable to open file %s %s",type,blob->filename); */
      /* An empty blob or invalid type (bmp) is also error,
         so just ignore and continue */
      /* A4GL_exitwith ("Unable to open file."); */
      return;
    }

  y = PDF_get_value ((PDF *)p->pdf_ptr, "imageheight", n);
  x = PDF_get_value ((PDF *)p->pdf_ptr, "imagewidth", n);

  ox=(double)x;
  oy=(double)y;
  sy=sx;
  y = (int) ((double) y * sy);
  x = (int) ((double) x * sx);

// If its just way to large to fit on the page - scale it back...
// this doesn't care if we're too far down the page etc - thats a different problem :-)
	while (y > (int)p->page_length) {
#ifdef DEBUG
			A4GL_debug("Too high %d %lf",y,p->page_length);
#endif
			sx*=0.99;
			sy*=0.99;
  			y = (int) (oy * sy);
  			x = (int) (ox * sx);
	}

	while (x > (int)p->page_width) {
#ifdef DEBUG
			A4GL_debug("Too wide %d %lf",x,p->page_width);
#endif
			sx*=0.99;
			sy*=0.99;
  			y = (int) (oy * sy);
  			x = (int) (ox * sx);
	}

#ifdef DEBUG
  A4GL_debug ("Placing heght of image =%d col=%f line=%f length=%f scale=%lf", y, p->col_no, p->line_no, p->page_length,sx);
#endif

  if (p->col_no == 0)
    {
      p->col_no += p->left_margin;
    }
#ifdef DEBUG
  A4GL_debug ("x=%lf y=%lf", p->col_no, p->page_length - p->line_no - y);
#endif

  PDF_place_image ((PDF *)p->pdf_ptr, n, p->col_no, p->page_length - p->line_no - y, sx);

#ifdef DEBUG
  A4GL_debug ("Closing");
#endif
  PDF_close_image ((PDF *)p->pdf_ptr, n);

#ifdef DEBUG
A4GL_debug("lineno (%lf) +=  %lf", p->line_no,(double)y);
A4GL_debug("colno (%lf) +=  %lf", p->col_no,(double)x);
#endif

  p->line_no = p->line_no + (double) y;
  p->col_no = p->col_no + (double) x;
  A4GL_push_empty_char ();
  A4GL_pdf_rep_print (p, 1, cr, 0, -1);
  return;
}

int
A4GLPDFREP_A4GL_pdf_pdffunc_internal (void *vp, char *fname, int nargs)
{
  char *ptr;
  int a;
  double d;
  struct pdf_rep_structure *p;
  p = (struct pdf_rep_structure  *)vp;


  if (strcmp (fname, "EmbedFont") == 0)
    {

	char *ptr1;
        ptr1 = A4GL_char_pop ();
        a = PDF_load_font ((PDF *)p->pdf_ptr, ptr1, 0, A4GL_get_pdf_encoding(), "embedding");
	acl_free(ptr1);
	return 0;
    }
 

  if (strcmp (fname, "set_parameter") == 0)
    {
      char *ptr1;
      char *ptr2;
      ptr2 = A4GL_char_pop ();
      ptr1 = A4GL_char_pop ();
      PDF_set_parameter ((PDF *)p->pdf_ptr, ptr1, ptr2);
      acl_free (ptr1);
      acl_free (ptr2);
      return 0;
    }

  if (strcmp (fname, "moveto") == 0 || strcmp (fname, "moveto_top") == 0)
    {
      float f1;
      float f2;
      f2 = A4GL_pop_double ();
      f1 = A4GL_pop_double ();
		if (strcmp (fname, "moveto_top") == 0) {
			f2=p->page_length-f2;
		}


      PDF_moveto ((PDF *)p->pdf_ptr, f1, f2);
      return 0;
    }

  if (strcmp (fname, "setcolor") == 0)
    {
      float f1;
      float f2;
      float f3;
      f3 = A4GL_pop_double ();
      f2 = A4GL_pop_double ();
      f1 = A4GL_pop_double ();
      A4GL_setcolor ((PDF*)p->pdf_ptr, "both","rgb",f1, f2,f3,0);
      return 0;
    }
  if (strcmp (fname, "setstrokecolor") == 0)
    {
      float f1;
      float f2;
      float f3;
      f3 = A4GL_pop_double ();
      f2 = A4GL_pop_double ();
      f1 = A4GL_pop_double ();
      A4GL_setcolor ((PDF*)p->pdf_ptr, "stroke","rgb",f1, f2,f3,0);
      return 0;
    }

   if (strcmp(fname,"bookmark")==0) {
	char *buf;
	buf=A4GL_char_pop();
	PDF_create_bookmark((PDF *)p->pdf_ptr, buf, 0, "");
	free(buf);
   }

   if (strcmp(fname,"add_bookmark")==0) {
	char *buf;
	int a;
	a=A4GL_pop_int();
	buf=A4GL_char_pop();
	a=PDF_add_bookmark((PDF *)p->pdf_ptr, buf, a, 0);
	A4GL_push_int(a);
	free(buf);
	return 1;
	}
   if (strcmp(fname,"add_bookmark_no_ret")==0) {
	char *buf;
	int a;
	a=A4GL_pop_int();
	buf=A4GL_char_pop();
	a=PDF_add_bookmark((PDF *)p->pdf_ptr, buf, a, 0);
	//A4GL_push_int(a);
	//free(buf);
	return 0;
	}

  if (strcmp (fname, "setfillcolor") == 0)
    {
      float f1;
      float f2;
      float f3;
      f3 = A4GL_pop_double ();
      f2 = A4GL_pop_double ();
      f1 = A4GL_pop_double ();
      A4GL_setcolor ((PDF*)p->pdf_ptr, "fill","rgb",f1, f2,f3,0);
      return 0;
    }

  if (strcmp (fname, "stroke") == 0)
    {
      PDF_stroke ((PDF *)p->pdf_ptr);
      return 0;
    }

  if (strcmp (fname, "barcode") == 0)
    {
	double x,y,w,h;
	char *str;
	str=A4GL_char_pop();
	h=A4GL_pop_double();
	w=A4GL_pop_double();

	// These should probably always be <0 - but we'll correct it anyway...
	if (w<0) w=0-w;
	if (h<0) h=0-h;

	y=A4GL_pop_double();
	x=A4GL_pop_double();
	y=y+h;

	generate_barcode((PDF*)p->pdf_ptr, x,y,w,h,str,p->page_length,1);

	free(str);
      return 0;
    }

  if (strcmp (fname, "barcode_type") == 0)
    {
	char *str;
	str=A4GL_char_pop();
	set_barcode_type(str);
	free(str);
	return 0;
    }

  if (strcmp (fname, "barcode_no_text") == 0)
    {
	double x,y,w,h;
	char *str;
	str=A4GL_char_pop();
	h=A4GL_pop_double();
	w=A4GL_pop_double();
	// These should probably always be <0 - but we'll correct it anyway...
	if (w<0) w=0-w;
	if (h<0) h=0-h;

	y=A4GL_pop_double();
	x=A4GL_pop_double();
	y=y+h;
	generate_barcode((PDF*)p->pdf_ptr, x,y,w,h,str,p->page_length,0);
	free(str);
      return 0;
    }

  if (strcmp (fname, "fill_stroke") == 0)
    {
      PDF_fill_stroke ((PDF *)p->pdf_ptr);
      return 0;
    }

  if (strcmp (fname, "fill") == 0)
    {
      PDF_fill ((PDF *)p->pdf_ptr);
      return 0;
    }

  if (strcmp (fname, "lineto") == 0 || strcmp (fname, "lineto_top") == 0)
    {
      float f1;
      float f2;
      f2 = A4GL_pop_double ();
      f1 = A4GL_pop_double ();
		if (strcmp (fname, "lineto_top") == 0) {
			f2=p->page_length-f2;
		}
      PDF_lineto ((PDF *)p->pdf_ptr, f1, f2);
      return 0;
    }

  if (strcmp(fname,"add_table_cell")==0) {
		int table;
		int column;
		int row;
		char *text;
		char *optlist="";

		if (nargs>=5) {
			optlist=A4GL_char_pop();
		}
		text=A4GL_char_pop();
		row=A4GL_pop_long();
		column=A4GL_pop_long();
		table=A4GL_pop_long();
		table=PDF_add_table_cell((PDF *)p->pdf_ptr, table,column,row,text,strlen(text),optlist);
		A4GL_push_int(table);
		return 1;
  }

  if (strcmp(fname,"fit_table")==0) {
		int table;
		double llx;
		double lly;
		double urx;
		double ury;
		char *optlist="";
		const char *rval;

		if (nargs>=5) {
			optlist=A4GL_char_pop();
		}
		ury=A4GL_pop_double();
		urx=A4GL_pop_double();
		lly=A4GL_pop_double();
		llx=A4GL_pop_double();
		table=A4GL_pop_long();

		rval=PDF_fit_table((PDF *)p->pdf_ptr, table, llx,lly,urx,ury,optlist);
		A4GL_push_char((char *)rval);
		return 1;
  }


  if (strcmp(fname,"fit_textline")==0) {
	char *text;
		double llx;
		double lly;
		char *optlist="";

		if (nargs>=4) {
			optlist=A4GL_char_pop();
		}

		lly=A4GL_pop_double();
		llx=A4GL_pop_double();
		text=A4GL_char_pop();
		PDF_fit_textline((PDF *)p->pdf_ptr, text,strlen(text),llx,lly,optlist);
	return 0;
}

  if (strcmp(fname,"texturl")==0) {
		char *url;
		char *text;
		char optlist[20000];
		url=A4GL_char_pop();
		text=A4GL_char_pop();
		double lly1;
		double lly2;
		double llx1;
		double llx2;
		int d;
		//lly=A4GL_pop_double();
		//llx=A4GL_pop_double();
		A4GL_trim(url);
	        sprintf(optlist,"url {%s}",url );
	//printf("url=       %s\n",url);
	//printf("optlist=   %s\n",optlist);

		d=PDF_create_action((PDF *)p->pdf_ptr,"URI",optlist);

		lly1=p->page_length - p->line_no;
		lly2=lly1+A4GLPDFREP_A4GL_pdf_size (1,'l',p);
		llx1=p->col_no;
		llx2=llx1+ PDF_stringwidth ((PDF *)p->pdf_ptr, text, p->font, p->font_size);


		//PDF_setcolor(p->pdf_ptr,"both","rgb",0,0,1,0);

	        PDF_fit_textline((PDF *)p->pdf_ptr, text, strlen(text),llx1, lly1, "");
		sprintf(optlist , "action={activate %d } linewidth=0",d);
		PDF_create_annotation((PDF *)p->pdf_ptr,
						llx1,
						lly1,
						llx2,lly2,
					 	"Link", optlist);

		//A4GL_resetcolor(p->pdf_ptr);

		return 0;
  }

  if (strcmp(fname,"page_col_inches")==0) {
	  double f1;
      	f1 = A4GL_pop_double ();
	f1*=72.0;
	A4GL_push_double(p->left_margin+f1);
	return 1;
  }

  if (strcmp(fname,"page_line_inches")==0) {
	  double f1;
      	f1 = A4GL_pop_double ();
	f1*=72.0;
	A4GL_push_double(p->page_length-f1);
	return 1;
  }

  if (strcmp(fname,"line_height")==0) {
	  double f1;
      	f1 = A4GL_pop_double ();
  	a = A4GLPDFREP_A4GL_pdf_size (f1, 'l', p);
	A4GL_push_double(a);
	return 1;
  }

  if (strcmp(fname,"char_width")==0) {
	  double f1;
      	f1 = A4GL_pop_double ();
  	a = A4GLPDFREP_A4GL_pdf_size (f1, 'c', p);
	A4GL_push_double(a);
	return 1;
  }


  if (strcmp (fname, "set_value") == 0)
    {
      char *ptr1;
      int a;
      a = A4GL_pop_int ();
      ptr1 = A4GL_char_pop ();
#ifdef DEBUG
      A4GL_debug ("Setting pdf value %s to %d\n", ptr1, a);
#endif
      PDF_set_value ((PDF *)p->pdf_ptr, ptr1, a);
      acl_free (ptr1);
      return 0;
    }


  if (strcmp (fname, "set_font_size") == 0)
    {
      d = A4GL_pop_double ();
      p->font_size = d;
      PDF_setfont ((PDF *)p->pdf_ptr, p->font, p->font_size);
      return 0;
    }

  if (strcmp (fname, "set_font_name") == 0)
    {
      ptr = A4GL_char_pop ();
      strcpy (p->font_name, ptr);
      acl_free (ptr);

      a = PDF_load_font ((PDF *)p->pdf_ptr, p->font_name, 0, A4GL_get_pdf_encoding(), "");
	//printf("a=%d\n", p->font);

		//a=PDF_load_font((PDF *)p->pdf_ptr, p->font_name,A4GL_get_pdf_encoding(),"embedding");
	if (a<0) {
	  A4GL_exitwith ("Unable to locate font");
	  return 0;
	}

      p->font = a;
      PDF_setfont ((PDF *)p->pdf_ptr, p->font, p->font_size);
      return 0;
    }

// page_line(lineno), convert lineno to pdf metric, need -1 to align properly
  if (strcmp(fname,"page_line")==0) {
	  double f1;
      	f1 = A4GL_pop_double ();
	A4GL_push_double(p->page_length-f1 - 1);
	return 1;
  }

// skip_to(lineno), need +1 to get to corrent line_no ???
  if (strcmp(fname,"skip_to")==0) {
	  double f1;
      	f1 = A4GL_pop_double ();
	p->line_no = f1 + 1;
	return 0;
  }

// rect(x, y, w, h);
  if (strcmp (fname, "rect") == 0 || strcmp (fname, "rect_top") == 0)
    {
      float fx, fy, fw, fh;
      fh = A4GL_pop_double ();
      fw = A4GL_pop_double ();
      fy = A4GL_pop_double ();
	if (strcmp (fname, "rect_top") == 0) {
		fy=p->page_length-fy;
	}
      fx = A4GL_pop_double ();
      PDF_rect ((PDF *)p->pdf_ptr, fx, fy, fw, fh);
      PDF_stroke ((PDF *)p->pdf_ptr);
      return 0;
    }

  if (strcmp (fname, "show_text_pos") == 0 || strcmp (fname, "show_text_pos_top") == 0)
    {
      float fx, fy;
	char *ptr;
	ptr=A4GL_char_pop();
      fy = A4GL_pop_double ();
	if (strcmp (fname, "set_text_pos_top") == 0) {
		fy=p->page_length-fy;
	}
      fx = A4GL_pop_double ();
       PDF_set_text_pos ((PDF *)p->pdf_ptr, fx, fy - p->font_size);
        PDF_show ((PDF *)p->pdf_ptr, ptr);
	free(ptr);
      return 0;
    }

  if (strcmp(fname,"currpos")==0) {
		int n;
		n=A4GL_pop_int();
		if (n==1) {
			A4GL_push_double( p->col_no);
			return 1;
		}
		if (n==2) {
			A4GL_push_double( p->page_length - p->line_no);
			return 1;
		}
		if (n==3) {
			A4GL_push_double( p->page_length - p->line_no);
			A4GL_push_double( p->col_no);
			return 2;
		}
		return 0;
  }

  if (strcmp(fname,"textwidth")==0) {
		char *s;
		double d;
		s=A4GL_char_pop();
		d=PDF_stringwidth ((PDF *)p->pdf_ptr, s, p->font, p->font_size);
		A4GL_push_double(d);
		return 1;
		
  }

// show_boxed(text, x, y, w, h, mode, feature) returning rc;
// mode=(left, right, center, justify, fulljustify);
// if w=h=0, x,y is anchor point for left,right,center single line formatting
// feature=blind used for testing if text fit. rc is no of chars not fit.
  if (strcmp (fname, "show_boxed") == 0 || strcmp (fname, "show_boxed_top") == 0)
    {
      float fx, fy, fw, fh;
      char *text, *mode, *feature;
      int c;
	if (nargs==7) {
      		feature = A4GL_char_pop ();
	} else {
		feature="";
	}
      mode = A4GL_char_pop ();
      fh = A4GL_pop_double ();
      fw = A4GL_pop_double ();
      fy = A4GL_pop_double ();
      fx = A4GL_pop_double ();
      text = A4GL_char_pop ();
	if (strcmp (fname, "show_boxed_top") == 0) {
		fy=p->page_length-fy;
	}
      if (strcmp (mode, "left") != 0
	&& strcmp (mode, "right") !=0
	&& strcmp (mode, "center") !=0
	&& strcmp (mode, "justify") !=0
	&& strcmp (mode, "fulljustify") !=0) mode = "justify";

      if (strcmp (feature, "blind") != 0) feature = "";
	//printf("fx=%f, fy=%f, fw=%f, fh=%f\n",fx, fy, fw, fh);
      c = PDF_show_boxed ((PDF *)p->pdf_ptr, text, fx, fy, fw, fh, mode, feature);
      A4GL_push_double ((double) c);
      return 1;
    }

  A4GL_assertion(1,"Unknown PDF function");

  return 0;
}


static char *
A4GL_report_char_pop (void)
{
  int tos_size;
  int tos_dtype;
  void *tos_ptr;
  char *ptr;
  char *(*function) (void *, int, int, struct struct_scr_field *, int);
  A4GL_get_top_of_stack (1, &tos_dtype, &tos_size, (void **) &tos_ptr);

  function = (char* (*)(void*, int, int, struct_scr_field*, int)) A4GL_get_datatype_function_i (tos_dtype & DTYPE_MASK, "DISPLAY");
  A4GL_assertion (function == 0,
                  "No report display function for this datatype");
  ptr =
    function (tos_ptr, tos_size, -1, (struct struct_scr_field *) 0,
              DISPLAY_TYPE_PRINT);
  if (ptr != 0)
    {
      ptr = strdup (ptr);
      A4GL_drop_param ();
    }
  else
    {
      ptr = A4GL_char_pop ();
    }


  return ptr;

}



/**
 *
 * @todo Describe function
 */
int  A4GLPDFREP_EXREPORT_initlib(void)
{
#ifdef DEBUG
  A4GL_debug ("Calling PDF_boot");
#endif
  PDF_boot ();
  return 1;
}

/* ================================ EOF ============================== */
