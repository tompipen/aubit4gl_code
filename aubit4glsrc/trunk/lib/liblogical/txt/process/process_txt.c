#include <stdlib.h>
#include <stdio.h>
#include "../../common/a4gl_lle.h"
#include "../../layout_engine/API_layout.h"

char **lines;

int page_touched = 0;
FILE *rep_fout;


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

extern struct r_report *report;


struct r_report *r;
int RP_process_report (char *buff) 
{
  int a;
  int block;
  int entry;
  struct r_report_block_entries *centry;
  int x, y;
  int page;
  int last_page = -1;
  r=report;
  page_touched = 0;

  if (rep_fout) fclose(rep_fout);

  rep_fout=0;

  if (buff==0) {
		return 0;
  }

  A4GL_trim(buff);
  if (!strlen(buff)) {
	tmpnam(buff);
  }


  rep_fout=fopen(buff,"w");
  if (rep_fout==0) {
		return 0;
  }
	
  lines = malloc (sizeof (char *) * r->page_length);

  for (a = 0; a < r->page_length; a++)
    {
      lines[a] = malloc (r->max_col + 1+r->left_margin);	// for the \NULL
    }

  clear_page (r->max_col+r->left_margin, r->page_length);

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
		  output_page (rep_fout, r->max_col, r->page_length);
		  clear_page (r->max_col+r->left_margin, r->page_length);
		}
	      last_page = page;
	    }


	  x = centry->col_no+r->left_margin;
	  y = centry->line_no; //+r->top_margin;
	  set_text (x, y, centry->string);
	}
    }

  if (page_touched)
    {
      output_page (rep_fout, r->max_col, r->page_length);
    }

}
