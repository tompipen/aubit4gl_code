#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include "../../common/a4gl_lle.h"
#include "../../processor/API_process.h"
#include "txt_barcode.h"
int term_crnl=0;
char **lines;


struct s_tag {
	char *text;
	char *tag;
};


char *have_tags;
struct s_tag ***tags;

int page_touched = 0;
FILE *rep_fout;
int maxwidth;


int RP_default_file (void *report,char *errbuff,void *rbx, int rbs) {
A4GL_debug("RP_default_file");
	// As there is no file description to mess with!
	return 1;
}


int RP_load_file (void *report, FILE *fin) {
A4GL_debug("RP_load_file");
	// As there is no file description to mess with!
	return 1;
}


static void
clear_page (int w, int h)
{
  int a;
  char *buff;
A4GL_debug("clear_page");
  buff = acl_malloc2 (w + 1);
  memset (buff, ' ', w);
  buff[w] = 0;

  for (a = 0; a < h; a++)
    {
	int b;
      strcpy (lines[a], buff);
	have_tags[a]=0;
	for (b=0;b<w;b++) {
		if (tags[a][b]!=0) {
			free(tags[a][b]->text);
			free(tags[a][b]->tag);
			free(tags[a][b]);
			tags[a][b]=0;
		}
	}
    }
  page_touched = 0;
}


static void
trim (char *s)
{
  int a, b;
  b = 0;
A4GL_debug("trim");
  for (a = strlen (s) - 1; a > 0; a--)
    {
      if (A4GL_isblank (s[a]))
	continue;
      s[a + 1] = 0;
      return;
    }
  s[0] = 0;
}



static char *ChkForBarcode(char *s_orig) {
static char barcodeline[10024];
char *barcode;
char *p;
//char str[256];
char spaces[2000];
int a;
int c;
char *p2;
double x,y,w,h;
char * sstart;
int len;
char *s_new;
x=0.0;
y=0.0;
w=0.0;
h=0.0;
A4GL_debug("ChkForBarcode");

	s_new=A4GL_check_for_tags(s_orig);

	if (strcmp(s_new,s_orig)!=0) {
		//printf("Got %s from %s\n", s_new,s_orig);
		A4GL_debug("Got %s from %s\n", s_new,s_orig);
	}


	strcpy(barcodeline,s_new);

	if (!A4GL_isyes(acl_getenv("EMBEDBARCODE")))  {
		return s_new;
	}

	memset(spaces,' ',sizeof(spaces));

	p=strstr(barcodeline,"##BARCODE(");
	if (p==0)  {
		return s_new;
	}
	sstart=p;
	// Blank out the first # - so we can strcpy the initial portion
	*p=0;
	p++;
	a=sscanf(p,"#BARCODE(%lf,%lf,%lf,%lf%n",&x,&y,&w,&h,&c);
	if (a!=4) {
		FPRINTF(stderr,"Invalid barcode description\n");
		return s_new;
	}
	p+=c; 
	if (*p!=',') {
		FPRINTF(stderr,"Invalid barcode description\n");
		return s_new;
	}
	p++;
	p2=strstr(p,")##");
	if (p2==0) {
		FPRINTF(stderr,"Invalid barcode description\n");
		return s_new;
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

static void dump_tagged_line(FILE *fout, int l,int width, char *s) {
int sl;
int a;

sl=strlen(s);
for (a=0;a<width;a++) {
	if (tags[l][a]!=0) {
		fprintf(fout,"%s%s%s", A4GL_get_start_tag(tags[l][a]->tag), tags[l][a]->text, A4GL_get_end_tag(tags[l][a]->tag));
		a+=strlen(tags[l][a]->text)-1;
	} else {
		if (a<sl)  {
			fprintf(fout,"%c",s[a]);
		} else {
			fprintf(fout," ");
		}
	}
}


}

static void
output_page (FILE * fout, int width, int h)
{
  int a;
  int hnew;
  char *ptr;
A4GL_debug("output_page");

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
			if (have_tags[a]) {
				dump_tagged_line(fout,a,width, ptr);
			} else {
	  			fprintf (fout, "%s", ptr);
			}
	  	fprintf (fout, "%c", 12);
	  } else {
		ptr=ChkForBarcode(lines[a]);
		if (term_crnl) {
			if (have_tags[a]) {
				dump_tagged_line(fout,a,width, ptr);
			} else {
	  			fprintf (fout, "%s", ptr);
			}
	  		fprintf (fout, "\r\n");
		} else {
			if (have_tags[a]) {
				dump_tagged_line(fout,a,width, ptr);
			} else {
	  			fprintf (fout, "%s", ptr);
			}
	  		fprintf (fout, "\n");
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
			if (have_tags[a]) {
				dump_tagged_line(fout,a,width, ptr);
			} else {
	  			fprintf (fout, "%s", ptr);
			}
	  		fprintf (fout, "\r\n");
		} else {
			if (have_tags[a]) {
				dump_tagged_line(fout,a,width, ptr);
			} else {
	  			fprintf (fout, "%s", ptr);
			}
	  		fprintf (fout, "\n");
		}
	}
    }
}



static void
set_text (int x, int y, char *s)
{
  char *ptr;
A4GL_debug("set_text");
  ptr = lines[y - 1];
  memcpy (&ptr[x - 1], s, strlen (s));
  page_touched = 1;
}



static void add_tag(int x,int y,char *tag) {
        static char tagline[10024];
        char *p;
	struct s_tag *s;

	
        strcpy(tagline,tag);
        p=strstr(tagline,"##TAG(");

        if (p) {
                char *comma;
                char buff[20000];
                comma=strrchr(tagline,',');
                if (comma!=NULL) {
                	*comma=0;
                	comma++;
                	p=strstr(comma,")##");
                	if (p!=NULL)  {
                		*p=0;
                		sprintf(buff,"%s",&tagline[6]);
				s=malloc(sizeof(struct s_tag));
				s->tag=strdup(comma);
				s->text=strdup(buff);
				tags[y-1][x-1]=s;
				have_tags[y-1]++;
			}
		}
	}
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
  //int last_page = -1;
  int sz;
  int max_page=0;
  int this_page;
  page_touched = 0;

A4GL_debug("here");
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
  lines = acl_malloc2 (sz);
  have_tags= acl_malloc2 (sz);
  tags = acl_malloc2 (sz);

  for (a = 0; a < report->page_length; a++)
    {
	int b;
	have_tags[a]=0;
      	lines[a] = acl_malloc2 (report->max_col + 1+report->left_margin);	// for the \NULL
  	tags[a] = acl_malloc2 (sizeof(struct s_tag *)*(report->max_col + 1+report->left_margin));
	for (b=0;b<report->max_col + 1+report->left_margin;b++) {
		tags[a][b]=NULL;
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
				if (strstr(centry->string,"##TAG(")) {
					add_tag(x,y,centry->string);
				} else {
	  				set_text (x, y, centry->string);
				}
			}
    		}
	}
      	output_page (rep_fout, report->max_col + 1+report->left_margin, report->page_length);
    }


  if (rep_fout) {
  	if (strcmp(buff,"-")!=0) {
	  	fclose(rep_fout);
	}
  }
return 1;
}
