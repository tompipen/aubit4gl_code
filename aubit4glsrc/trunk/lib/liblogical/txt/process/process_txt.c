#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "../../common/a4gl_lle.h"
#include "../../processor/API_process.h"
#include "txt_barcode.h"
int term_crnl=0;
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
  buff = acl_malloc2 (w + 1);
  memset (buff, ' ', w);
  buff[w] = 0;

  for (a = 0; a < h; a++)
    {
      strcpy (lines[a], buff);
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



static char *ChkForBarcode(char *s) {
static char barcodeline[10024];
char *barcode;
char *p;
char str[256];
char spaces[2000];
int a;
int c;
char *p2;
double x,y,w,h;
char * sstart;
int len;
x=0.0;
y=0.0;
w=0.0;
h=0.0;

	strcpy(barcodeline,s);
	if (!A4GL_isyes(acl_getenv("EMBEDBARCODE")))  {
		return s;
	}

	memset(spaces,' ',sizeof(spaces));

	p=strstr(barcodeline,"##BARCODE(");
	if (p==0)  {
		return s;
	}
	sstart=p;
	// Blank out the first # - so we can strcpy the initial portion
	*p=0;
	p++;
	a=sscanf(p,"#BARCODE(%lf,%lf,%lf,%lf%n",&x,&y,&w,&h,&c);
	if (a!=4) {
		FPRINTF(stderr,"Invalid barcode description\n");
		return s;
	}
	p+=c; 
	if (*p!=',') {
		FPRINTF(stderr,"Invalid barcode description\n");
		return s;
	}
	p++;
	p2=strstr(p,")##");
	if (p2==0) {
		FPRINTF(stderr,"Invalid barcode description\n");
		return s;
	}
	*p2=0;
	p2+=3;
	len=p2-sstart;
	A4GL_debug("Txt=%s x=%lf y=%lf w=%lf h=%lf\n",p, x,y,w,h);
	A4GL_debug("barcodeline=%s\n",barcodeline);
	p=strdup(p);
        A4GL_trim(p);
	barcode=strdup(generate_barcode(x,y,w,h,p));
	free(p);
	p2=strdup(p2);
	spaces[len]=0;
	strcat(barcodeline,barcode);
	if (A4GL_isyes(acl_getenv("CODEVSPACES"))) {	
		strcat(barcodeline,spaces);
	} 
	if (A4GL_isyes(acl_getenv("CODEVTRIM"))) {
		A4GL_trim(barcodeline);
	}
	free(barcode);
	strcat(barcodeline,p2);
	free(p2);
	
	return barcodeline;

}

static void
output_page (FILE * fout, int w, int h)
{
  int a;
  int hnew;
  char *ptr;

  if (A4GL_isyes (acl_getenv ("USETOPOFPAGE")))
    {
      hnew=h;
      for (a = h-1; a >=0; a--)
	{
	  trim (lines[a]);
	  if (strlen(lines[a])) {hnew=a+1;break;}
	}

      for (a = 0; a < hnew; a++)
	{
	  if (a == hnew-1) {
		ptr=ChkForBarcode(lines[a]);
	  	fprintf (fout, "%s%c", ptr,12);
	  } else {
		ptr=ChkForBarcode(lines[a]);
		if (term_crnl) {
	  		fprintf (fout, "%s\r\n", ptr);
		} else {
	  		fprintf (fout, "%s\n", ptr);
		}
	  }
	}


    }
  else
    {

      for (a = 0; a < h; a++)
	{
	  trim (lines[a]);
	  ptr=ChkForBarcode(lines[a]);
		if (term_crnl) {
	  		fprintf (fout, "%s\r\n", ptr);
		} else {
	  		fprintf (fout, "%s\n", ptr);
		}
	}
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
  int max_page=0;
  int this_page;
  page_touched = 0;

  report=rp;


  if (rep_fout) fclose(rep_fout);
  if (A4GL_isyes(acl_getenv("CONVREPCRLF"))) {
		term_crnl=1;
	}

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
  //printf("Alloc %d bytes\n"); fflush(stdout);
  lines = acl_malloc2 (sz);
  //printf("lines=%p\n",lines);

  for (a = 0; a < report->page_length; a++)
    {
      lines[a] = acl_malloc2 (report->max_col + 1+report->left_margin);	// for the \NULL
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


  if (rep_fout) {
  	if (strcmp(buff,"-")!=0) {
	  	fclose(rep_fout);
	}
  }
return 1;
}
