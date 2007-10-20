#include <stdlib.h>
#include <stdio.h>
#include "pdflib.h"
#include "../../common/a4gl_lle.h"
#include "../common/common_pdf.h"
#include "../../processor/API_process.h"
#include "pdf_barcode.h"
#include "pdf_handling.h"

extern int default_font_no;
extern int default_font_size;

char **lines;
int max_pages;
int page_cnt;
extern struct pdf_layout layout;
float get_eachline(void);

int page_touched = 0;
PDF *p;

extern float this_page_width;
extern float this_page_height;


int RP_default_file (void *report,char *errbuff,void *rbx, int rbs) {
	pdf_default_file();
	return 1;
}


int RP_load_file (void *report, FILE *fin) {
	return pdf_load_file(fin);
}


static void
clear_page (int w, int h)
{
  int a;
  char *buff;
  buff = acl_malloc2 (w + 1);
  memset (buff, ' ', w);
  buff[w] = 0;

  for (a = 0; a < h; a++)
    {
      strcpy (lines[a], buff);
    }
  page_touched = 0;
}

/*
static void
trim (char *s)
{
  char *p;
  int a, b;
  b = 0;
  for (a = strlen (s) - 1; a > 0; a--)
    {
      if (isblank (s[a]))
	continue;
      s[a + 1] = 0;
      return;
    }
    

  s[0] = 0;
}
*/



static int isBarcode(char *s,double *x,double *y, double *w,double *h, char  *str) {
char *p;
char *p2;
int c;
int a;
char barcodeline[3000];

	strcpy(barcodeline,s);

        if (!A4GL_isyes(acl_getenv("EMBEDBARCODE")))  {
                return 0;
        }

	p=strstr(barcodeline,"##BARCODE(");
	if (p==0) {
		return 0;
	}
	p++;
	a=sscanf(p,"#BARCODE(%lf,%lf,%lf,%lf%n",x,y,w,h,&c);	
	if (a!=4) {
		return 0;
	}
        p+=c;
        if (*p!=',') {
                return 0;
        }
        p++;
        p2=strstr(p,")##");        
	if (p2==0) {
                return 0;
        }
        *p2=0;
        p2+=3;
        if (p2==0) {
                return 0;
        }
        *p2=0;
        p2+=3;
	strcpy(str,p);
	a4gl_upshift(str);
	return 1;
}

static void
set_text (int x, int y, char *s,int use_default)
{
  char *ptr;
/*int w;*/
/*int h; */
char str[256];
char str_img[256];
char buff[2000];
int image;
double xd,yd,wd,hd;
    if (!isBarcode(s, &xd,&yd,&wd,&hd,str)) {
		if (use_default ) {
  			ptr = lines[y - 1];
  			memcpy (&ptr[x - 1], s, strlen (s));
		} else {
	                double y2;
			double x2;
			strcpy(buff,lines[y-1]);
			buff[x-1]=0;
			x2=PDF_stringwidth(p,buff,default_font_no,default_font_size);
                	y2=this_page_height - ((float) (y-1) * get_eachline()) - (layout.topmargin * 72.0);
                	y2=y2-get_eachline();
			PDF_set_text_pos (p, (layout.leftmargin * 72.0)+x2, y2);
			PDF_show (p, s);
		}
    } else {


	// We've got a barcode!
	
	strcpy(str_img,str);
	strcat(str_img,".png");
        if ((image = PDF_load_image (p, "auto", str_img, 0, "")) == -1)
        {
          	A4GL_debug ("Couldn't read image file for barcode(%s) - generating lines instead\n",str);
		// Try drawing it instead...
		generate_barcode(p, xd*72.0,(yd*72),wd*72.0,hd*72.0,str,this_page_height,1);

        }
      else
        {
	  char buff[200];
          wd=wd*72.0;
          hd=hd*72.0;
          xd=((layout.leftmargin+xd) * 72.0);
	  yd=this_page_height - ((layout.topmargin+yd) * 72.0)-hd;
	   sprintf(buff,"boxsize {%lf %lf} fitmethod meet", wd,hd);
	
           PDF_fit_image (p, image, xd, yd, buff);
           PDF_close_image (p, image);
        }

    }


  page_touched = 1;
}

//extern struct r_report *report;


int RP_process_report (void *vreport, char *buff,void *rbx,int rbs) 
{
  int a;
  int block;
  int entry;
  struct r_report *report;
  struct r_report_block_entries *centry;
  int x, y;
  int page;
  int uses_default_font=0;
  //int last_page = -1;
  page_touched = 0;
  report=vreport;
 

  if ((p=PDF_new()) == (PDF *)0) {
	return 0;
  }



  if (buff==0) {
		printf("No buffer\n");
		return 0;
  }

  A4GL_trim(buff);
  if (!strlen(buff)) {
	tmpnam(buff);
  }

  if (PDF_open_file(p,buff)==-1) {
		printf("Can't open output\n");
		// Can't open the output file
		return 0;
  }

  PDF_set_info(p,"Creator","Aubit 4GL");
  PDF_set_info(p,"Author","Liblogical PDF output");
  PDF_set_info(p,"Title",report->repName);
  PDF_set_info(p,"Subject",report->modName);

  lines = acl_malloc2 (sizeof (char *) * report->page_length);

  for (a = 0; a < report->page_length; a++)
    {
      lines[a] = acl_malloc2 (report->max_col + 1+report->left_margin);	// for the \NULL
    }

  for (block = 0; block < report->nblocks; block++)
    {
      for (entry = 0; entry < report->blocks[block].nentries; entry++)
	{
          centry = &report->blocks[block].entries[entry];
          page = centry->page_no;
		if (page>max_pages) max_pages=page;
	}
    }

  setupPageSize(report->max_col);

  for (page_cnt=1;page_cnt<=max_pages;page_cnt++) {
  clear_page (report->max_col+report->left_margin, report->page_length);
  start_pdf_page(p, report->max_col, report->page_length);


  for (block = 0; block < report->nblocks; block++)
    {
      for (entry = 0; entry < report->blocks[block].nentries; entry++)
	{
	  centry = &report->blocks[block].entries[entry];
	  page = centry->page_no;
	  if (page!=page_cnt) continue;

		  //output_page (p, report->max_col, report->page_length,lines);
		  //clear_page (report->max_col+report->left_margin, report->page_length);
	  x = centry->col_no+report->left_margin;
	  y = centry->line_no; //+report->top_margin;
	  uses_default_font=select_font_for(report->blocks[block].rb,centry->entry_id);
	  //uses_default_font=0;
	  set_text (x, y, centry->string,uses_default_font);
	}
    }

    //select_font_for(-1,-1); // Wont be found - so it'll use the default..
    output_page (p, report->max_col, report->page_length,lines);
  }


PDF_close(p);
PDF_delete(p);
return 1;
}
