#include <stdlib.h>
#include <stdio.h>
#include "pdflib.h"
#include "../../common/a4gl_lle.h"
#include "../../layout_engine/API_layout.h"

char **lines;

int page_touched = 0;
PDF *p;
void output_page (PDF *p, int w, int h,char **lines);

int RP_default_file (void) {
	// As there is no file description to mess with!
	return 1;
}


int RP_load_file (FILE *fin) {
	// As there is no file description to mess with!
	return 1;
}


static void
clear_page (int w, int h)
{
  int a;
  char *buff;
  buff = malloc (w + 1);
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

extern struct r_report *report;


int RP_process_report (char *buff) 
{
  int a;
  int block;
  int entry;
  struct r_report_block_entries *centry;
  int x, y;
  int page;
  int last_page = -1;
  page_touched = 0;
 

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

  lines = malloc (sizeof (char *) * report->page_length);

  for (a = 0; a < report->page_length; a++)
    {
      lines[a] = malloc (report->max_col + 1+report->left_margin);	// for the \NULL
    }

  clear_page (report->max_col+report->left_margin, report->page_length);

  for (block = 0; block < report->nblocks; block++)
    {
      for (entry = 0; entry < report->blocks[block].nentries; entry++)
	{
	  centry = &report->blocks[block].entries[entry];
	  page = centry->page_no;
	  if (page != last_page)
	    {
	      if (page_touched && last_page != -1)
		{
		  output_page (p, report->max_col, report->page_length,lines);
		  clear_page (report->max_col+report->left_margin, report->page_length);
		}
	      last_page = page;
	    }


	  x = centry->col_no+report->left_margin;
	  y = centry->line_no; //+report->top_margin;
	  set_text (x, y, centry->string);
	}
    }

  if (page_touched)
    {
      output_page (p, report->max_col, report->page_length,lines);
    }
PDF_close(p);
PDF_delete(p);
return 1;
}
