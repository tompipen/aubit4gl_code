#include <stdlib.h>
#include <stdio.h>
#include "../../common/a4gl_lle.h"
#include "../../processor/API_process.h"

char **lines;

int page_touched = 0;
FILE *rep_fout;


int RP_default_file (void *report,char *errbuff,void *rbx, int rbs) {
	// As there is no file description to mess with!
	return 1;
}


int RP_load_file (void *report, FILE *fin) {
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
output_page (FILE * fout, int w, int h)
{
  int a;
  for (a = 0; a < h; a++)
    {
      trim (lines[a]);
      fprintf (fout, "%s\n", lines[a]);
    }
}


static void
set_text (int x, int y, char *s)
{
  char *ptr;
  ptr = lines[y - 1];
  memcpy (&ptr[x - 1], s, strlen (s));
  page_touched = 1;
}


int RP_process_report (void *rp, char *buff,void *rbx, int rbs) 
{
  int a;
  int block;
  int entry;
  struct r_report *report;
  struct r_report_block_entries *centry;
  int x, y;
  int page;
  int last_page = -1;
  int sz;
  page_touched = 0;

  report=rp;


  if (rep_fout) fclose(rep_fout);

  rep_fout=0;

  if (buff==0) {
		return 0;
  }

  A4GL_trim(buff);
  if (!strlen(buff)) {
	static char lbuff[256];
	buff=lbuff;
	tmpnam(buff);
  }


  rep_fout=fopen(buff,"w");
  if (rep_fout==0) {
		return 0;
  }
	
  sz =(sizeof (char *) * report->page_length);
  //printf("Alloc %d bytes\n"); fflush(stdout);
  lines = malloc (sz);
  //printf("lines=%p\n",lines);

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
		  output_page (rep_fout, report->max_col, report->page_length);
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
      output_page (rep_fout, report->max_col, report->page_length);
    }
return 1;
}
