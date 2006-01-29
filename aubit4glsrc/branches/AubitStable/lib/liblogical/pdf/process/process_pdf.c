#include <stdlib.h>
#include <stdio.h>
#include "pdflib.h"
#include "../../common/a4gl_lle.h"
#include "../common/common_pdf.h"
#include "../../processor/API_process.h"

char **lines;
int max_pages;
int page_cnt;
extern struct pdf_layout layout;


int page_touched = 0;
PDF *p;
void output_page (PDF *p, int w, int h,char **lines);



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


static
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



static void
set_text (int x, int y, char *s)
{
  char *ptr;
  ptr = lines[y - 1];
  memcpy (&ptr[x - 1], s, strlen (s));
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
  int last_page = -1;
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

  for (page_cnt=1;page_cnt<=max_pages;page_cnt++) {
  clear_page (report->max_col+report->left_margin, report->page_length);


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
	  set_text (x, y, centry->string);
	}
    }
      output_page (p, report->max_col, report->page_length,lines);
  }


PDF_close(p);
PDF_delete(p);
return 1;
}