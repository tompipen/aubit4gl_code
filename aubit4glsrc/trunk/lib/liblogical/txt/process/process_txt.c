#include <stdlib.h>
#include <stdio.h>
#include "../../common/a4gl_lle.h"
#include "../../layout_engine/API_layout.h"

char **lines;

int page_touched = 0;


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

void
LR_process_report (FILE * fout, FILE *filter,void *rv)
{
  int a;
  int block;
  int entry;
  struct r_report_block_entries *centry;
  int x, y;
  int page;
  int last_page = -1;
  struct r_report *r;
  r=rv;
  
  page_touched = 0;



  lines = malloc (sizeof (char *) * r->page_length);

  for (a = 0; a < r->page_length; a++)
    {
      lines[a] = malloc (r->max_col + 1+r->left_margin);	// for the \NULL
    }

  clear_page (r->max_col, r->page_length);

  for (block = 0; block < r->nblocks; block++)
    {
      for (entry = 0; entry < r->blocks[block].nentries; entry++)
	{
	  centry = &r->blocks[block].entries[entry];
	  page = centry->page_no;
	  if (page != last_page)
	    {
	      if (page_touched && last_page != -1)
		{
		  output_page (fout, r->max_col, r->page_length);
		  clear_page (r->max_col, r->page_length);
		}
	      last_page = page;
	    }


	  x = centry->col_no+r->left_margin;
	  y = centry->line_no+r->top_margin;
	  set_text (x, y, centry->string);
	}
    }

  if (page_touched)
    {
      output_page (fout, r->max_col, r->page_length);
    }

}
