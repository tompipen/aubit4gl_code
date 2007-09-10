#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../common/common_pdf.h"
#include "pdflib.h"


PDF *p = 0;
extern struct pdf_layout layout;
int font = -1;

float layout_page_width = -1;
float layout_page_height = -1;
  float this_page_width = 0;
  float this_page_height = 0;

int setlinecolor = 0;
float rline = 1.0;
float gline = 1.0;
float bline = 1.0;
float eachline=0;


// Fake music score rule
#define STYLE_NONE 0
#define STYLE_5BAR 1
#define STYLE_RECTANGLE 2

void setupPageSize(int w) {
  int orient;

  if (layout_page_width == -1)
    {
      switch (layout.paper_type)
	{
	case PAPER_TYPE_A0:
	  layout_page_width = a0_width;
	  layout_page_height = a0_height;
	  break;
	case PAPER_TYPE_A1:
	  layout_page_width = a1_width;
	  layout_page_height = a1_height;
	  break;
	case PAPER_TYPE_A2:
	  layout_page_width = a2_width;
	  layout_page_height = a2_height;
	  break;
	case PAPER_TYPE_A3:
	  layout_page_width = a3_width;
	  layout_page_height = a3_height;
	  break;
	case PAPER_TYPE_A4:
	  layout_page_width = a4_width;
	  layout_page_height = a4_height;
	  break;
	case PAPER_TYPE_A5:
	  layout_page_width = a5_width;
	  layout_page_height = a5_height;
	  break;
	case PAPER_TYPE_A6:
	  layout_page_width = a6_width;
	  layout_page_height = a6_height;
	  break;
	case PAPER_TYPE_B5:
	  layout_page_width = b5_width;
	  layout_page_height = b5_height;
	  break;
	case PAPER_TYPE_LETTER:
	  layout_page_width = letter_width;
	  layout_page_height = letter_height;
	  break;
	case PAPER_TYPE_LEGAL:
	  layout_page_width = legal_width;
	  layout_page_height = legal_height;
	  break;
	case PAPER_TYPE_LEDGER:
	  layout_page_width = ledger_width;
	  layout_page_height = ledger_height;
	  break;
	case PAPER_TYPE_P11x17:
	  layout_page_width = p11x17_width;
	  layout_page_height = p11x17_height;
	  break;
	default:
	  fprintf (stderr, "Bad paper size\n");
	}
    }

  if (layout.paper_orient == PAPER_ORIENT_AUTO)
    {
      if (w <= 80)
	orient = PAPER_ORIENT_PORTRAIT;
      else
	orient = PAPER_ORIENT_LANDSCAPE;
    }
  else
    {
      orient = layout.paper_orient;
    }

  if (orient == PAPER_ORIENT_PORTRAIT)
    {
      this_page_width = layout_page_width;
      this_page_height = layout_page_height;
    }

  if (orient == PAPER_ORIENT_LANDSCAPE)
    {
      this_page_height = layout_page_width;
      this_page_width = layout_page_height;
    }

}




void
start_pdf_page (PDF * p, int w, int h)
{
  int a;
  float printable;
  int image;
  int style=STYLE_NONE;

  if (setlinecolor == 0)
    {
      char *str;
      char str_b[260];
      long l;
      style = 0;
      strcpy(str_b,layout.bluebar);

      A4GL_trim(str_b);
      str=str_b;

      if (strlen(str)==0) {
      	str = acl_getenv ("BLUEBAR");
      }

      if (acl_getenv_not_set_as_0 ("BLUEBAR") != 0)
	{
      	str = acl_getenv ("BLUEBAR");

	  if (str[0]=='#') {
	  	l=0xf0f0f0;
	  	a=sscanf(&str[1],"%x,%s",&l,&style);
		if (a!=2) {
	  		a=sscanf(&str[1],"%xs",&l);
	      		style = STYLE_RECTANGLE;
		}

		rline=((l&0xff0000)>>16)/255;
		gline=((l&0xff00)>>8)/255;
		bline=((l&0xff))/255;

	  } else {
	  	a = sscanf (str, "%f,%f,%f,%d", &rline, &gline, &bline, &style);
	  	if (a != 4)
	    	{
	      	a = sscanf (str, "%f,%f,%f", &rline, &gline, &bline);
	      	if (a==3) {
	      		style = STYLE_RECTANGLE;
	      	} 
	    }
	  }
	  setlinecolor = 1;
	}
      else
	{
	  rline = 1.0;
	  gline = 1.0;
	  bline = 1.0;
	  setlinecolor = 2;
	}
    }


  setupPageSize(w);

/*
  if (layout.paper_orient == PAPER_ORIENT_AUTO)
    {
      if (w <= 80)
	orient = PAPER_ORIENT_PORTRAIT;
      else
	orient = PAPER_ORIENT_LANDSCAPE;
    }
  else
    {
      orient = layout.paper_orient;
    }

  if (orient == PAPER_ORIENT_PORTRAIT)
    {
      this_page_width = layout_page_width;
      this_page_height = layout_page_height;
    }
  if (orient == PAPER_ORIENT_LANDSCAPE)
    {
      this_page_height = layout_page_width;
      this_page_width = layout_page_height;
    }
*/


  PDF_begin_page (p, this_page_width, this_page_height);



  A4GL_trim (layout.img_src);

  if (strlen (layout.img_src))
    {
      char img_class[200] = "auto";

      if (strstr (layout.img_src, ".gif"))
	{
	  strcpy (img_class, "gif");
	}
      if (strstr (layout.img_src, ".jpg"))
	{
	  strcpy (img_class, "jpeg");
	}
      if (strstr (layout.img_src, ".png"))
	{
	  strcpy (img_class, "png");
	}

      if ((image =
	   PDF_load_image (p, img_class, layout.img_src, 0, "")) == -1)
	{
	  fprintf (stderr, "Error: Couldn't read image file.\n");
	}
      else
	{
	  double x;
	  double y;
	  x = layout.img_x;
	  y = layout.img_y;

	  PDF_fit_image (p, image, x, y, "fitmethod auto");
	  PDF_close_image (p, image);
	}
    }


  if (font == -1)
    {
      A4GL_trim (layout.fontname);
      font = PDF_load_font (p, layout.fontname, 0, "host", "");
      if (font < 0)
	{
	  font = PDF_load_font (p, "Courier", 0, "host", "");	// Couldn't load there one - so default it..
	}

    }

  PDF_setfont (p, font, layout.fontsize);
  printable = this_page_height - (layout.topmargin * 72.0);
  eachline = printable / h;


  if (setlinecolor && style != STYLE_NONE)
    {				// FAKE music rule/bluebar...

  PDF_setcolor (p, "both", "rgb", rline, gline, bline, 0);
  PDF_setlinewidth (p, eachline / 20);

      if (style == STYLE_5BAR)
	{
	  for (a = 0; a < h; a += 2)
	    {
	      char *ptr;
	      int bb;
	      float spacing;
	      spacing = 0;
	      spacing -= 2.0 * (float) eachline / 10;
	      for (bb = 0; bb < 5; bb++)
		{
		  spacing -= 2.0 * (float) eachline / 10;
		  PDF_moveto (p, (0),
			      this_page_height - ((float) a * eachline) -
			      (layout.topmargin * 72.0) + spacing);
		  PDF_lineto (p, (this_page_width),
			      this_page_height - ((float) a * eachline) -
			      (layout.topmargin * 72.0) + spacing);
		}
	    }
      PDF_stroke (p);
	}

      if (style == STYLE_RECTANGLE)
	{
	  for (a = 0; a <= h; a += 2)
	    {
	      char *ptr;
	      int bb;
	      float offset;
	      offset = 2.0 * (float) eachline / 10;
	      //spacing -= (float) eachline / 10;
	      PDF_rect (p, (0),
			this_page_height - ((float) a * eachline) -offset-
			(layout.topmargin * 72.0), this_page_width, eachline*0.9);
      			PDF_fill_stroke (p);
	    }
	}

      PDF_setcolor (p, "both", "rgb", 0.0, 0.0, 0.0, 0);
    }

}

void output_page (PDF * p, int w, int h, char **lines) {

int a;

  for (a = 0; a < h; a++)
    {
      char *ptr;
      ptr = lines[a];
      A4GL_trim (ptr);
      if (strlen(ptr)) {
		double y;
		y=this_page_height - ((float) a * eachline) - (layout.topmargin * 72.0);
		y=y-eachline;
      	PDF_set_text_pos (p, (layout.leftmargin * 72.0), y);
      	PDF_show (p, ptr);
      }
    }

  PDF_end_page (p);
}
