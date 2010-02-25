#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#include "hpdf.h"
#include "a4gl_lib_exreport_pdf_int.h"


char *A4GL_get_pdf_haru_encoding(void) ;
struct Haru_doc {
	HPDF_Doc  doc;
	HPDF_Page current_page;
};

typedef struct Haru_doc Haru_doc;


#ifdef HPDF_DLL
void  __stdcall
#else
void
#endif
error_handler (HPDF_STATUS   error_no,
               HPDF_STATUS   detail_no,
               void         *user_data)
{
    char buff[2000];
    sprintf (buff, "ERROR: error_no=%04X, detail_no=%u\n", (HPDF_UINT)error_no, (HPDF_UINT)detail_no);
    A4GL_set_errm(buff);
    A4GL_exitwith("PDF Error");
}

#define DOC(x) ((Haru_doc *)(x->pdf_ptr))
#define CURRENT_PAGE(x) DOC(x)->current_page



#define SECTION_NORMAL 0
#define SECTION_HEADER 1
#define SECTION_TRAILER 2
static char * A4GL_report_char_pop (void);
int aclpdf (struct pdf_rep_structure *p, char *fname, int n);
void A4GL_pdf_add_spaces (void);
int A4GL_pdf_new_page (struct pdf_rep_structure *p);
double A4GL_pdf_metric (int a, char c, struct pdf_rep_structure *rep);
void A4GL_pdf_move (struct pdf_rep_structure *p);
void A4GLREPORT_initlib (void);
HPDF_Doc newdoc(void) ;

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
void generate_barcode(Haru_doc * p, double xpos,double ypos,double x,double y,char *str,float p_page_height,int incl_text);
void set_barcode_type(char *s);


static void A4GL_setcolor(Haru_doc * p, const char *fstype, const char *colorspace, double c1, double c2, double c3, double c4) {

if (strcmp(colorspace,"rgb")!=0) {
	A4GL_assertion(1,"A4GL_setcolor must be rgb");
}

if (strcmp(fstype,"fill")==0) {
	fill_color_r=c1;
	fill_color_g=c2;
	fill_color_b=c3;
	HPDF_Page_SetRGBFill(p->current_page,c1,c2,c3);
	return;
}

if (strcmp(fstype,"stroke")==0) {
	stroke_color_r=c1;
	stroke_color_g=c2;
	stroke_color_b=c3;
	HPDF_Page_SetRGBStroke(p->current_page,c1,c2,c3);
	return;
}
if (strcmp(fstype,"both")==0) {
	fill_color_r=c1;
	fill_color_g=c2;
	fill_color_b=c3;
	stroke_color_r=c1;
	stroke_color_g=c2;
	stroke_color_b=c3;
	HPDF_Page_SetRGBStroke(p->current_page,c1,c2,c3);
	HPDF_Page_SetRGBFill(p->current_page,c1,c2,c3);

	return;
}

A4GL_assertion(1,"unexpected fstype");
}


static void ClearOldMode(Haru_doc *doc, HPDF_UINT16 unew) {
	HPDF_UINT16 u;
	u=HPDF_Page_GetGMode  (doc->current_page);
	if (u==unew) return ;

	switch (u) {
		case HPDF_GMODE_PAGE_DESCRIPTION: break;
		case HPDF_GMODE_TEXT_OBJECT: 
                		HPDF_Page_EndText(doc->current_page);
				break;
		case HPDF_GMODE_PATH_OBJECT:
				HPDF_Page_Stroke(doc->current_page);
				break;
	}

}

static void A4GL_resetcolor(Haru_doc *p) {
	HPDF_Page_SetRGBStroke(p->current_page,stroke_color_r,stroke_color_g,stroke_color_b);
	HPDF_Page_SetRGBFill(p->current_page, fill_color_r,fill_color_g,fill_color_b);
}



void setfont(struct pdf_rep_structure *rep) {
  if (rep->pdf_ptr==NULL) {
                  rep->pdf_ptr = malloc(sizeof(Haru_doc));
                  ((Haru_doc *)rep->pdf_ptr)->doc = newdoc();
#ifdef DEBUG
                  A4GL_debug ("Opening file: %s\n", rep->output_loc_str);
                  A4GL_debug ("Set info");
#endif

  }
  //rep->fontptr = HPDF_GetFont (DOC(rep)->doc, rep->font_name, A4GL_get_pdf_encoding());
  rep->fontptr = HPDF_GetFont (DOC(rep)->doc, rep->font_name, A4GL_get_pdf_haru_encoding());

  if (rep->fontptr==NULL)
    {
      A4GL_exitwith ("Unable to locate font");
      return ;
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
  HPDF_Page_SetFontAndSize (CURRENT_PAGE(rep) , rep->fontptr, rep->font_size);
}



HPDF_Doc newdoc(void) {
HPDF_Doc doc;
	doc = HPDF_New (error_handler, NULL);
	if (doc) {
		HPDF_SetInfoAttr (doc,HPDF_INFO_AUTHOR, "Auto");
		HPDF_SetInfoAttr (doc,HPDF_INFO_CREATOR, "A4GL");
		HPDF_SetInfoAttr (doc,HPDF_INFO_TITLE, "Auto");
		HPDF_SetCompressionMode (doc, HPDF_COMP_ALL);
	}
	return doc;
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

  rep = vrep;

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
		  rep->pdf_ptr = malloc(sizeof(Haru_doc));

		  ((Haru_doc *)rep->pdf_ptr)->doc = newdoc(); 
				/* HPDF_New (error_handler, NULL);
		  		A4GL_debug ("Opening file: %s\n", rep->output_loc_str);
		  		A4GL_debug ("Set info");
		  		A4GLPDFREP_A4GL_pdf_set_info (rep->pdf_ptr, "A4GL"); */
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
              rep->page_length - rep->lines_in_trailer - rep->bottom_margin)
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

	  if (HPDF_Page_GetGMode  (CURRENT_PAGE(rep)) !=  HPDF_GMODE_TEXT_OBJECT) {
	    	HPDF_Page_BeginText(CURRENT_PAGE(rep));
		setfont(rep);
	  }

	  A4GL_pdf_move (rep); 
	  HPDF_Page_ShowText (CURRENT_PAGE(rep) , str);
	  HPDF_Page_EndText(CURRENT_PAGE(rep));

	  //printf("Putting %s\n",str);


#ifdef DEBUG
	  A4GL_debug ("Adding %f to col_no\n", A4GL_pdf_metric (strlen (str), 'c', rep));
#endif
	  rep->col_no += A4GL_pdf_metric (strlen (str), 'c', rep);
	  acl_free (str);
	}
      //A4GL_pdf_move (rep);
    }

#ifdef DEBUG
  A4GL_debug ("Newline : %d", s);
#endif

  if (s == 0)
    {
#ifdef DEBUG
      A4GL_debug ("B\n");
#endif
      //A4GL_pdf_move (rep);
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
  rep = vrep;

#ifdef DEBUG
  A4GL_debug ("Set column");
#endif
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
  //A4GL_pdf_move (rep); 

}


/**
 *
 * @todo Describe function
 */
void
A4GLPDFREP_A4GL_pdf_skip_to (void *vrep, double a)
{
  struct pdf_rep_structure *rep;
  rep = vrep;

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
  rep = vrep;

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
  rep = vrep;


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
  rep = vrep;

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

  rep = vrep;

#ifdef DEBUG
			A4GL_debug("pdf_skip_top_of_page");
#endif

  /* a = rep->page_length - rep->line_no - rep->bottom_margin - rep->lines_in_trailer; */

  a = rep->page_length - rep->line_no - rep->bottom_margin - rep->lines_in_trailer;
//  ad = rep->page_length - rep->line_no - rep->bottom_margin - rep->lines_in_trailer;
  ad = rep->page_length - rep->bottom_margin - rep->lines_in_trailer;

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
    double b;
      for (z = 0; z < a; z++)
	{
  		b = rep->page_length - rep->line_no - rep->bottom_margin - rep->lines_in_trailer;

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
 struct Haru_doc *doc;
#ifdef DEBUG
  A4GL_debug ("NEW PAGE : %d\n", p->page_no);
#endif
  /* PDF_begin_page(p->pdf_ptr, width, height); */

  doc=p->pdf_ptr;

  if (p->page_no)
    {
     // clear any pending stokes or text placements...
     printf("Clear mode\n");
      ClearOldMode(DOC(p), HPDF_GMODE_PAGE_DESCRIPTION);
      //PDF_end_page (CURRENT_PAGE(p));
    }

#ifdef DEBUG
  A4GL_debug ("Begin page %lf %lf\n", p->page_width, p->page_length);
#endif
  
  doc->current_page = HPDF_AddPage (DOC(p)->doc);
  HPDF_Page_SetWidth(doc->current_page, p->page_width);
  HPDF_Page_SetHeight(doc->current_page, p->page_length);

  //PDF_begin_page (p->pdf_ptr, p->page_width, p->page_length);
#ifdef DEBUG
  A4GL_debug ("Done\n");
  A4GL_debug ("find font %s\n", p->font_name);
#endif




// do we need bluebars ? 
  if (p->bluebar_style!=E_BLUEBAR_NONE) {
	//double printable;
	double eachline;
		double ypos;

	//printable = p->page_height - (p->top_margin);
  	//eachline = printable / h;
  	eachline = A4GLPDFREP_A4GL_pdf_size (1, 'l', p);
  	A4GL_setcolor (doc, "both", "rgb", p->bluebar_r, p->bluebar_g, p->bluebar_b,0);

 	ClearOldMode(DOC(p) , HPDF_GMODE_PAGE_DESCRIPTION);

  	HPDF_Page_SetLineWidth (doc->current_page, eachline / 20);

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

                  HPDF_Page_MoveTo (doc->current_page, (0), ypos + spacing);
                  HPDF_Page_LineTo (doc->current_page, (p->page_width),ypos+spacing);
                }
		ypos=ypos-(eachline*2);
		if (ypos+eachline<p->bottom_margin) break;
            }
      		HPDF_Page_Stroke (doc->current_page);
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
                HPDF_Page_Rectangle (doc->current_page, (0), ypos -offset , p->page_width, eachline*0.9); 
		HPDF_Page_FillStroke (doc->current_page);
		ypos=ypos-(eachline*2);
		if (ypos+eachline<p->bottom_margin) break;
            }
        }


	A4GL_resetcolor(p->pdf_ptr);

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
Haru_doc  *pp;
pp=(Haru_doc *)p;
HPDF_SetInfoAttr (pp->doc,HPDF_INFO_AUTHOR, "Auto");
HPDF_SetInfoAttr (pp->doc,HPDF_INFO_CREATOR, creator);
HPDF_SetInfoAttr (pp->doc,HPDF_INFO_TITLE, "Auto");
}


static void ensure_text_mode(struct pdf_rep_structure *rep) {
	if (HPDF_Page_GetGMode  (CURRENT_PAGE(rep)) !=HPDF_GMODE_TEXT_OBJECT)  {
  		ClearOldMode(DOC(rep) , HPDF_GMODE_TEXT_OBJECT);
		HPDF_Page_BeginText(CURRENT_PAGE(rep));
	}
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
  //printf ("Move to %f %f\n", p->col_no, p->line_no);
  ensure_text_mode(p);
//printf("Move to %lf %lf\n", p->col_no, p->page_length - p->line_no);
  HPDF_Page_MoveTextPos (CURRENT_PAGE(p) , p->col_no, p->page_length - p->line_no);
}


/**
 *
 * @todo Describe function
 */
void
A4GLPDFREP_A4GL_pdf_rep_close (void *vp)
{
  struct pdf_rep_structure *p;
  p = vp;


#ifdef DEBUG
  A4GL_debug ("Closing report %f\n", p->line_no);
#endif
  if (p->line_no != 0.0)
    {
//printf("CLose\n");
	ClearOldMode(DOC(p), HPDF_GMODE_PAGE_DESCRIPTION);
#ifdef DEBUG
      A4GL_debug ("A");
      //PDF_end_page (p->pdf_ptr);
      A4GL_debug ("A");
#endif
      //PDF_close (p->pdf_ptr);
    }

  if (HPDF_SaveToFile (DOC(p)->doc, p->output_loc_str)!=HPDF_OK) 
    {
      A4GL_exitwith ("Error opening output\n");
      return;
    }


  HPDF_Free (DOC(p)->doc);

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
  p = vp;

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
  
setfont(p);

  if (c == 'c')
    {
#ifdef DEBUG
      A4GL_debug ("metric C %d %c", a, c);
#endif
      if (p->pdf_ptr && CURRENT_PAGE(p)) {
      	return (double) ((double) a * HPDF_Page_TextWidth(CURRENT_PAGE(p), "W"));
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

      //PDF_set_parameter (p->pdf_ptr, ptr1, ptr2);
      A4GL_assertion(1,"set_parameter not available in HARU");

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
#ifdef DEBUG
      A4GL_debug ("Setting pdf value %s to %d\n", ptr1, a);
#endif
      A4GL_assertion(1,"set_value not available in HARU");
      //PDF_set_value (p->pdf_ptr, ptr1, a);
      acl_free (ptr1);
      return 0;
    }


  if (strcmp (fname, "set_font_size") == 0)
    {
      d = A4GL_pop_double ();
      p->font_size = d;
      HPDF_Page_SetFontAndSize (CURRENT_PAGE(p), p->fontptr, p->font_size);
      return 0;
    }

  if (strcmp (fname, "set_font_name") == 0)
    {
	HPDF_Font a;
      ptr = A4GL_char_pop ();
      strcpy (p->font_name, ptr);
      acl_free (ptr);
      a = HPDF_GetFont (p->pdf_ptr, p->font_name, A4GL_get_pdf_haru_encoding());
      if (a ==NULL)
	{
	  A4GL_exitwith ("Unable to locate font");
	  return 0;
	}
      else
	{
#ifdef DEBUG
	  A4GL_debug ("Findfont ok");
#endif
	}
      p->fontptr = a;
      HPDF_Page_SetFontAndSize (CURRENT_PAGE(p), p->fontptr, p->font_size);
      return 0;
    }
  return 0;
}



/**
 *
 * @todo Describe function
 */


void
A4GLPDFREP_A4GL_pdf_blob_print (void *vp, void *vblob, char *type, int cr)
{
  //int n;
  double sx;
  double sy;
  int x, y;
double ox;
double oy;
  struct pdf_rep_structure *p;
  struct fgl_int_loc *blob;
  HPDF_Image i;


  p = vp;
  blob = vblob;


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

  i=NULL;

  if (A4GL_has_pointer(blob->filename,HARU_IMAGE)) {
	i=A4GL_find_pointer(blob->filename,HARU_IMAGE);

  }  

  if (i==NULL) {
  	if (A4GL_aubit_strcasecmp(type,"PNG")==0) {
		i=HPDF_LoadPngImageFromFile(DOC(p)->doc,blob->filename);
  	}

  	if (A4GL_aubit_strcasecmp(type,"JPG")==0 || A4GL_aubit_strcasecmp(type,"JPEG")==0) {
		i=HPDF_LoadJpegImageFromFile(DOC(p)->doc,blob->filename);
  	}
  }
  if (i) {
		A4GL_add_pointer(blob->filename,HARU_IMAGE,i);
  }
  //n = PDF_open_image_file (p->pdf_ptr, type, blob->filename, "", 0);
#ifdef DEBUG
  A4GL_debug ("Image handle=%p\n", i);
#endif

  if (i==NULL)
    {
      /* exitwith("Unable to open file %s %s",type,blob->filename); */
      /* An empty blob or invalid type (bmp) is also error,
         so just ignore and continue */
      /* A4GL_exitwith ("Unable to open file."); */
      return;
    }
  
   x=HPDF_Image_GetWidth(i);
   y=HPDF_Image_GetHeight(i);


  //y = PDF_get_value (p->pdf_ptr, "imageheight", n);
  //x = PDF_get_value (p->pdf_ptr, "imagewidth", n);

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

  ClearOldMode(DOC(p), HPDF_GMODE_PATH_OBJECT);

  HPDF_Page_DrawImage (CURRENT_PAGE(p), i, p->col_no, p->page_length - p->line_no - y, HPDF_Image_GetWidth(i)*sx, HPDF_Image_GetHeight(i)*sy);

#ifdef DEBUG
  A4GL_debug ("Closing");
#endif
  //PDF_close_image (p->pdf_ptr, n);

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
  //int n;
  double sx;
  double sy;
  int x, y;
double ox;
double oy;
  struct pdf_rep_structure *p;
char *filename;
  HPDF_Image i;


  p = vp;

  filename=A4GL_char_pop();
  sx = A4GL_pop_double ();
  sy = A4GL_pop_double ();
#ifdef DEBUG
  A4GL_debug ("Scaling by %f %f", sx, sy);
#endif

#ifdef DEBUG
  A4GL_debug ("Opening blob\n");
#endif

  i=NULL;

  if (A4GL_has_pointer(filename,HARU_IMAGE)) {
	i=A4GL_find_pointer(filename,HARU_IMAGE);

  }  

  if (i==NULL) {
  	if (A4GL_aubit_strcasecmp(type,"PNG")==0) {
		i=HPDF_LoadPngImageFromFile(DOC(p)->doc,filename);
  	}

  	if (A4GL_aubit_strcasecmp(type,"JPG")==0 || A4GL_aubit_strcasecmp(type,"JPEG")==0) {
		i=HPDF_LoadJpegImageFromFile(DOC(p)->doc,filename);
  	}
  }
  if (i) {
		A4GL_add_pointer(filename,HARU_IMAGE,i);
  }
  //n = PDF_open_image_file (p->pdf_ptr, type, blob->filename, "", 0);
#ifdef DEBUG
  A4GL_debug ("Image handle=%p\n", i);
#endif

  if (i==NULL)
    {
      /* exitwith("Unable to open file %s %s",type,blob->filename); */
      /* An empty blob or invalid type (bmp) is also error,
         so just ignore and continue */
      /* A4GL_exitwith ("Unable to open file."); */
      return;
    }
  
   x=HPDF_Image_GetWidth(i);
   y=HPDF_Image_GetHeight(i);


  //y = PDF_get_value (p->pdf_ptr, "imageheight", n);
  //x = PDF_get_value (p->pdf_ptr, "imagewidth", n);

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

  ClearOldMode(DOC(p), HPDF_GMODE_PATH_OBJECT);

  HPDF_Page_DrawImage (CURRENT_PAGE(p), i, p->col_no, p->page_length - p->line_no - y, HPDF_Image_GetWidth(i)*sx, HPDF_Image_GetHeight(i)*sy);

#ifdef DEBUG
  A4GL_debug ("Closing");
#endif
  //PDF_close_image (p->pdf_ptr, n);

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
  p = vp;


  if (strcmp (fname, "set_parameter") == 0)
    {
      char *ptr1;
      char *ptr2;
      ptr2 = A4GL_char_pop ();
      ptr1 = A4GL_char_pop ();
      //PDF_set_parameter (p->pdf_ptr, ptr1, ptr2);
      A4GL_assertion(1,"set_parameter not available in HARU");
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


 	ClearOldMode(DOC(p) , HPDF_GMODE_PAGE_DESCRIPTION);
      HPDF_Page_MoveTo (CURRENT_PAGE(p), f1, f2);
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
      A4GL_setcolor (p->pdf_ptr, "both","rgb",f1, f2,f3,0);
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
      A4GL_setcolor (p->pdf_ptr, "stroke","rgb",f1, f2,f3,0);
      return 0;
    }

   if (strcmp(fname,"bookmark")==0) {
	char *buf;
	buf=A4GL_char_pop();
	//PDF_create_bookmark(p->pdf_ptr, buf, 0, "");
	free(buf);
	A4GL_assertion(1,"Bookmarks not available in HARU");
   }

   if (strcmp(fname,"add_bookmark")==0) {
	char *buf;
	int a;
	a=A4GL_pop_int();
	buf=A4GL_char_pop();
	//a=PDF_add_bookmark(p->pdf_ptr, buf, a, 0);
	A4GL_assertion(1,"Bookmarks not available in HARU");
	A4GL_push_int(a);
	free(buf);
	return 1;
	}
   if (strcmp(fname,"add_bookmark_no_ret")==0) {
	char *buf;
	int a;
	a=A4GL_pop_int();
	buf=A4GL_char_pop();
	//a=PDF_add_bookmark(p->pdf_ptr, buf, a, 0);
	A4GL_assertion(1,"Bookmarks not available in HARU");
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
      A4GL_setcolor (p->pdf_ptr, "fill","rgb",f1, f2,f3,0);
      return 0;
    }

  if (strcmp (fname, "stroke") == 0)
    {
      HPDF_Page_Stroke (CURRENT_PAGE(p));
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

	generate_barcode(p->pdf_ptr, x,y,w,h,str,p->page_length,1);

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
	generate_barcode(p->pdf_ptr, x,y,w,h,str,p->page_length,0);
	free(str);
      return 0;
    }

  if (strcmp (fname, "fill_stroke") == 0)
    {
      HPDF_Page_FillStroke (CURRENT_PAGE(p));
      return 0;
    }

  if (strcmp (fname, "fill") == 0)
    {
      HPDF_Page_Fill (CURRENT_PAGE(p));
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
      HPDF_Page_LineTo (CURRENT_PAGE(p), f1, f2);
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

		//table=PDF_add_table_cell(p->pdf_ptr, table,column,row,text,strlen(text),optlist);

		A4GL_assertion(1,"add_table_cell not implemented for HARU");
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
		char *rval;

		if (nargs>=5) {
			optlist=A4GL_char_pop();
		}
		ury=A4GL_pop_double();
		urx=A4GL_pop_double();
		lly=A4GL_pop_double();
		llx=A4GL_pop_double();
		table=A4GL_pop_long();

		A4GL_assertion(1,"Fit Table not implemented for HARU");
		//rval=PDF_fit_table(p->pdf_ptr, table, llx,lly,urx,ury,optlist);
		//A4GL_push_char(rval);
		//return 1;
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
      A4GL_assertion(1,"set_value not available in HARU");
      //PDF_set_value (p->pdf_ptr, ptr1, a);
      acl_free (ptr1);
      return 0;
    }


  if (strcmp (fname, "set_font_size") == 0)
    {
      d = A4GL_pop_double ();
      p->font_size = d;
      HPDF_Page_SetFontAndSize (CURRENT_PAGE(p), p->fontptr, p->font_size);
      return 0;
    }

  if (strcmp (fname, "set_font_name") == 0)
    {
	HPDF_Font a;
      ptr = A4GL_char_pop ();
      strcpy (p->font_name, ptr);
      acl_free (ptr);
      a = HPDF_GetFont (DOC(p)->doc, p->font_name, A4GL_get_pdf_haru_encoding());
      if (a == NULL)
	{
	  A4GL_exitwith ("Unable to locate font");
	  return 0;
	}
      p->fontptr = a;
      HPDF_Page_SetFontAndSize (CURRENT_PAGE(p), p->fontptr, p->font_size);
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
      HPDF_Page_Rectangle (CURRENT_PAGE(p), fx, fy, fw, fh);
      HPDF_Page_Stroke (CURRENT_PAGE(p));
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
        HPDF_Page_MoveTextPos (CURRENT_PAGE(p), fx, fy - p->font_size);
        HPDF_Page_ShowText (CURRENT_PAGE(p), ptr);
	free(ptr);
      return 0;
    }


  if (strcmp(fname,"textwidth")==0) {
                char *s;
                double d;
                s=A4GL_char_pop();
      		d=HPDF_Page_TextWidth(CURRENT_PAGE(p), s);
                A4GL_push_double(d);
                return 1;
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

	A4GL_assertion(1," show_boxed not implemented for HARU");
      A4GL_push_double ((double) c);
      return 1;
    }


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

  function = A4GL_get_datatype_function_i (tos_dtype & DTYPE_MASK, "DISPLAY");
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
  return 1;
}

char *A4GL_get_pdf_haru_encoding(void) {
char *s;
	s=A4GL_get_pdf_encoding();
if (strcmp(s,"winansi")==0) {
	return "WinAnsiEncoding";
}
return s;
printf("s= %s\n",s);
}




void PDF_fill_stroke(void *pv) {
	 struct Haru_doc *p;
	 p=(Haru_doc *)pv;
	 if (HPDF_Page_GetGMode  (p->current_page) ==HPDF_GMODE_TEXT_OBJECT)  {
  		ClearOldMode(p , HPDF_GMODE_PAGE_DESCRIPTION);
	 }
      	 HPDF_Page_FillStroke (p->current_page);
}

void PDF_rect(void *pv, double x, double y, double width, double height) {
	 struct Haru_doc *p;
	 p=(Haru_doc *)pv;

	 if (HPDF_Page_GetGMode  (p->current_page) ==HPDF_GMODE_TEXT_OBJECT)  {
  		ClearOldMode(p , HPDF_GMODE_PAGE_DESCRIPTION);
	 }
		
	HPDF_Page_Rectangle(p->current_page,x,y,width,height);
}

void PDF_set_text_pos(void *pv,double x, double y) {
	struct Haru_doc *p;
	p=(Haru_doc *)pv;
	if (HPDF_Page_GetGMode  (p->current_page) !=HPDF_GMODE_TEXT_OBJECT)  {
  		ClearOldMode(p , HPDF_GMODE_TEXT_OBJECT);
		HPDF_Page_BeginText(p->current_page);
	}
  	HPDF_Page_MoveTextPos (p->current_page , x, y);
}


void PDF_setlinewidth(void *pv, double width) {
	 struct Haru_doc *p;
	 p=(Haru_doc *)pv;
	 if (HPDF_Page_GetGMode  (p->current_page) ==HPDF_GMODE_TEXT_OBJECT)  {
  		ClearOldMode(p , HPDF_GMODE_PAGE_DESCRIPTION);
	 }

	HPDF_Page_SetLineWidth (p->current_page, width);
}
void PDF_show(void *pv,char *text) {
	struct Haru_doc *p;
	p=(Haru_doc *)pv;
	if (HPDF_Page_GetGMode  (p->current_page) !=HPDF_GMODE_TEXT_OBJECT)  {
  		ClearOldMode(p , HPDF_GMODE_TEXT_OBJECT);
		HPDF_Page_BeginText(p->current_page);
	}
        HPDF_Page_ShowText (p->current_page, text);
	HPDF_Page_EndText(p->current_page);
}



/* ================================ EOF ============================== */
