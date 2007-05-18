#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "../../common/a4gl_lle.h"
#include "../../processor/API_process.h"

char ***lines;

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
  int x;
  for (a = 0; a < h; a++)
    {
      for (x=0; x<w;x++) {
	if (lines[a][x]) free(lines[a][x]);
      	lines[a][x]=0;
      }
    }
  page_touched = 0;
}


static void
trim (char *s)
{
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
  int hnew;
  int x;
  int last;
      for (a = 0; a < h; a++)
	{
	  int skip=0;
	  fprintf (fout, "<tr>\n");
	  for (x=0;x<w;x++) {
		char *ptr;
	  	if (lines[a][x])  {
			int l;
			if (skip) {
	  			fprintf (fout, "<td colspan=%d style=skip></td>\n", skip);
			}
			l=strlen(lines[a][x]);
			ptr=lines[a][x];
			A4GL_trim(ptr);
			if (ptr[0]==' ') {
				A4GL_lrtrim(ptr);
	  			fprintf (fout, "<td colspan=%d align=left>%s</td>\n", l,ptr);
			} else {
	  			fprintf (fout, "<td colspan=%d align=left>%s</td>\n", l,ptr);
			}
			x+=l-1;
			skip=0;
	  	} else {
	  			//fprintf (fout, "<td>.</td>\n", skip);
			skip++;
		}
	  }
	  fprintf (fout, "</tr>\n");
	
	}
}

static void
set_text (int x, int y, char *s)
{
  char **ptr;
  ptr = &lines[y - 1][x-1];
  *ptr=strdup(s);
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
  int max_page=0;
  int this_page;
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


  if (strcmp(buff,"-")==0) {
	rep_fout=stdout;
  } else {
  	rep_fout=fopen(buff,"w");
  }



  if (rep_fout==0) {
		return 0;
  }
	
  sz =(sizeof (char *) * report->page_length);
  lines = acl_malloc2 (sz);

  for (a = 0; a < report->page_length; a++)
    {
	int x;
      	lines[a] = acl_malloc2 (report->max_col+report->left_margin *sizeof(char *));	
	for (x=0;x<report->max_col+report->left_margin;x++) {
		lines[a][x]=0;
	}
    }



  max_page=0;
  for (block = 0; block < report->nblocks; block++)
    {
      for (entry = 0; entry < report->blocks[block].nentries; entry++)
	{
	  centry = &report->blocks[block].entries[entry];
	  page = centry->page_no;
	  if (page>max_page) max_page=page;
	}
    }


  fprintf(rep_fout,"<html>");
  fprintf(rep_fout,"<body>");
  fprintf(rep_fout,"<table>");

  for (this_page=1;this_page<=max_page;this_page++) {
  	clear_page (report->max_col+report->left_margin, report->page_length);
  	for (block = 0; block < report->nblocks; block++)
    		{
      		for (entry = 0; entry < report->blocks[block].nentries; entry++)
			{
	  		centry = &report->blocks[block].entries[entry];
	  		page = centry->page_no;
	  		if (page == this_page) {
	  			x = centry->col_no+report->left_margin;
	  			y = centry->line_no; //+report->top_margin;
	  			set_text (x, y, centry->string);
			}
    		}
	}
      	output_page (rep_fout, report->max_col, report->page_length);
    }

  fprintf(rep_fout,"</table>");


  if (rep_fout) {
  	if (strcmp(buff,"-")!=0) {
	  	fclose(rep_fout);
	}
  }
return 1;
}
