#include <stdio.h>
#include <stdlib.h>
#include "pdflib.h"
PDF *p=0;

#define PAGE_LAYOUT_WIDTH a4_width
#define PAGE_LAYOUT_HEIGHT a4_height

#define DEFAULT_FONT "Helvetica"
#define DEFAULT_FONT_SIZE 12

float x_max;
float y_max;
int font=-1;
#define YSIZE ((y_max/h))
#define XSIZE ((x_max/w))

void
output_page (PDF *p, int w, int h,char **lines)
{
  int a;

  if (w<=80) { // Portrait
	x_max=PAGE_LAYOUT_WIDTH;
	y_max=PAGE_LAYOUT_HEIGHT;
  } else {     // Landscape
	x_max=PAGE_LAYOUT_HEIGHT;
	y_max=PAGE_LAYOUT_WIDTH;
  }

  PDF_begin_page(p,x_max,y_max);

  if (font==-1) {
		font=PDF_load_font(p,DEFAULT_FONT,0,"host","");
  }

  PDF_setfont(p,font,DEFAULT_FONT_SIZE);

  for (a = 0; a < h; a++)
    {
	char *ptr;
	ptr=lines[a];
        trim (ptr);
	PDF_set_text_pos(p,1,y_max-(a*YSIZE));
	PDF_show(p,ptr);
    }
    PDF_end_page(p);
}


