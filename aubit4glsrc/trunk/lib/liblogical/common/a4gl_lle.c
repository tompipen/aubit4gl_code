#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define FILE_VERSION 3
#include "a4gl_lle.h"

int debug=0;

void read_entry(struct r_report_block *block) ;

FILE *fin=0;
int lvl;
int ok;

int max_page_no = -1;
int max_line_no = -1;
int max_col_no = -1;
static void read_block (void);
void free_report(void *report) ;

struct r_report *report;
/*
#if defined (__MINGW32__)

int isblank(int n) {
	if (n==' ') return 1;
	if (n=='\t') return 1;
	return 0;
}


#endif
*/

static int read_int (void)
{
  int n;
  //short s;
  //unsigned char c;


/* Keep it simple for now */
/*
  fread (&c, sizeof (c), 1, fin);
  if (c<254||c==255) return c;
  if (c>=254) {
  	fread (&s, sizeof (s), 1, fin);
	return a4gl_ntohs(s);
  }
*/

  fread (&n, sizeof (n), 1, fin);
  return a4gl_ntohl(n);
}

static char read_char (void)
{
  char n;
  int p;
  	fread (&n, sizeof (n), 1, fin);
	p=(int) n;
	if (!isprint(p)) {
		if (debug) printf("Suspect read_char (%d %x %c)\n",n,n,n);
	}

  return n;
}

static char * read_string (void)
{
  int n;
  char *p;
  n = read_int ();
  p = (char *) acl_malloc2 (n + 1);
  fread (p, n, 1, fin);
  p[n] = 0;
  return p;
}

static void trim (char *s)
{
  //char *p;
  int a, b;
  b = 0;
  for (a = strlen (s) - 1; a > 0; a--)
    {
      if (isblank (s[a])) s[a]=0;
	else break;
    }
}


static void
check_for_max (int p, int l, int c, char *s)
{
  c = c + strlen (s);
  if (p > max_page_no)
    max_page_no = p;
  if (l > max_line_no)
    max_line_no = l;
  if (c > max_col_no)
    max_col_no = c;
  if (max_page_no > 10000)
    {
	printf("Dubious number of pages - I think i'd better stop..\n");
	exit(1);
    }
}





struct r_report *read_report_output(char *fname) {
  //int npages;
  //char buff[256];
  //int buff_i;
  char buff_c;
  char *l;
  fin = fopen (fname, "r");
  max_page_no = -1;
  max_line_no = -1;
  max_col_no = -1;
  lvl=0;
  ok=1;

  if (fin == 0)
    {
        printf ("Unable to open input file : %s\n", fname);
	return 0;
    }

  if (read_char () != ENTRY_START)
    {                           /* First block should always be a 1.. */
      printf ("Looks like a bad file...\n");
	return 0;
    }

  report=(struct r_report *)acl_malloc2(sizeof(struct r_report));

  report->repName=0;
  report->modName=0;
  l=read_string(); // This should be tg

  if (strcmp("LOGICAL REPORT OUTPUT",l)!=0) {
        printf ("Looks like a bad file...\n");
	return 0;
  }
  report->version_no = read_int ();
  report->ctime = read_int ();
  report->top_margin=read_int();
  report->bottom_margin=read_int();
  report->left_margin=read_int();
  report->right_margin=read_int();
  report->page_length=read_int();
  report->repName=read_string();
  report->modName=read_string();

  report->nblocks = 0;
  report->blocks = 0;

  //printf("%s %s\n",report->repName,report->modName);

  if (report->version_no != FILE_VERSION)
    {
      printf
        ("This program was compiled up to accept LLE files version %d, this appears to be version %d\n",
         FILE_VERSION, report->version_no);
	free(report);
	return 0;
    }


  while (ok)
    {
      buff_c = read_char ();
      if (feof (fin)) break;

      if (buff_c != ENTRY_BLOCK)
        {
          printf ("Unexpected block (1) Got %d\n", buff_c);
	  free_report(report);
	  return 0;
        }
      read_block ();
    }

    if (ok) {
	report->max_page=max_page_no;
	report->max_line=max_line_no;
	report->max_col=max_col_no;
	return report;
    } else {
	free_report(report);
	return 0;
    }

    
}



static void read_block ()
{
  char buff_c;
  int cblock;
  //printf("Read block : %d\n",lvl);
  if (debug) { printf("read block - lvl=%d \n",lvl); }
  lvl++;
  cblock = report->nblocks++;
  report->blocks = (struct r_report_block *) acl_realloc (report->blocks, report->nblocks * sizeof (struct r_report_block));
  report->blocks[cblock].why=0;
  report->blocks[cblock].nentries = 0;
  report->blocks[cblock].entries = 0;
  report->blocks[cblock].line = read_int (); if (feof (fin)) { printf ("Unexpected EOF\n"); ok=0; return; }
	if (debug) printf("line=%d\n",report->blocks[cblock].line);
  report->blocks[cblock].where = read_char (); if (feof (fin)) { printf ("Unexpected EOF\n"); ok=0; return; }
	if (debug) printf("where=%c\n",report->blocks[cblock].where);
  report->blocks[cblock].why = read_string (); if (feof (fin)) { printf ("Unexpected EOF\n"); ok=0;return; }
	if (debug) printf("where=%s\n",report->blocks[cblock].why);
  report->blocks[cblock].rb = read_int (); if (feof (fin)) { printf ("Unexpected EOF\n"); ok=0; return; }

  if (debug) { printf("read block - line=%d where=%c why=%s rb=%d\n", report->blocks[cblock].line,report->blocks[cblock].where,report->blocks[cblock].why,report->blocks[cblock].rb); }

  while (ok)
    {
      buff_c = read_char ();
	if(debug) { printf("buff_c=%c\n",buff_c); }
      if (buff_c == ENTRY_BLOCK_END)
        {
          lvl--;
          return;
        }


      if (buff_c == ENTRY_BLOCK) {
		read_block();
		continue;
	}

      if (buff_c == ENTRY_DATA)
        {
          read_entry (&report->blocks[cblock]);
          continue;
        }

	printf("Unexpected block : %d\n",buff_c);
	exit(2);

    }

}



void read_entry(struct r_report_block *block) {
      /* If we've got to here - then we must have a valid DATA block.. */
      block->nentries++;
      block->entries = (struct r_report_block_entries *) acl_realloc (block->entries, block->nentries * sizeof (struct r_report_block_entries));

      block->entries[block->nentries - 1].string = 0;
      block->entries[block->nentries - 1].page_no = read_int ();
      block->entries[block->nentries - 1].line_no = read_int ();
      block->entries[block->nentries - 1].col_no = read_int ();
      block->entries[block->nentries - 1].entry_id = read_int ();
      block->entries[block->nentries - 1].string = read_string ();

      trim (block->entries[block->nentries - 1].string);

      if (strlen
          (block->entries[block->nentries - 1].
           string) == 0)
        {
          // Theres no point storing spaces - we just want data...
          free (block->entries[block->nentries - 1].string);
          block->nentries--;
        }
      else
        {
          check_for_max (block->entries[block->nentries - 1].page_no,
                         block->entries[block->nentries - 1].line_no,
                         block->entries[block->nentries - 1].col_no,
                         block->entries[block->nentries - 1].string);
        }
}

void free_report(void *report) {
	// need to go through and unallocate all the other stuff too...
	if (report) free(report);
}




void obtain_rbs_rbx(struct r_report *report, int *ptr_rbs, struct s_rbx **ptr_rbx) {
int rbs;
struct s_rbx *rbx;
int a;
  int block_cnt;
  int rblock_cnt;
  int entry_cnt;
int found;
int b;
 rbs=0;
 rbx=0;

  for (a = 0; a < report->nblocks; a++)
    {
      found = 0;
      if (rbs)
        {
          for (b = 0; b < rbs; b++)
            {
              if (report->blocks[a].rb == rbx[b].rb)
                {
                  found = 1;
                  break;
                }
            }
        }
      if (found)
        continue;
      rbs++;

      rbx = acl_realloc (rbx, sizeof (struct s_rbx) * rbs);
      rbx[rbs - 1].rb = report->blocks[a].rb;
      rbx[rbs - 1].why = report->blocks[a].why;
      rbx[rbs - 1].where = report->blocks[a].where;
    }
  for (block_cnt = 0; block_cnt < rbs; block_cnt++)
    {
      int *tmp_space_e;
      int *tmp_space_s;
      rbx[block_cnt].max_entry = 0;
      rbx[block_cnt].entry_nos = 0;
      rbx[block_cnt].nentry_nos = 0;
      rbx[block_cnt].max_size_entry = 0;

      for (rblock_cnt = 0; rblock_cnt < report->nblocks; rblock_cnt++)
        {
          if (rbx[block_cnt].rb != report->blocks[rblock_cnt].rb)
            {
              continue;
            }

          for (entry_cnt = 0; entry_cnt < report->blocks[rblock_cnt].nentries;
               entry_cnt++)
            {
		int nval;
              if (report->blocks[rblock_cnt].entries[entry_cnt].entry_id >=
                  rbx[block_cnt].max_entry)
                {
                  int nmax;
                  nmax =
                    report->blocks[rblock_cnt].entries[entry_cnt].entry_id +
                    1;
		nval=nmax;
		if (report->blocks[rblock_cnt].nentries>nval) nval=report->blocks[rblock_cnt].nentries;

                  rbx[block_cnt].entry_nos = acl_realloc (rbx[block_cnt].entry_nos, sizeof (int) * (nval));
                  rbx[block_cnt].max_size_entry = acl_realloc (rbx[block_cnt].max_size_entry, sizeof (int) * (nval));
                  for (a = rbx[block_cnt].max_entry; a < nval; a++)
                    {
                      rbx[block_cnt].entry_nos[a] = -1;
                      rbx[block_cnt].max_size_entry[a] = 0;
                    }
                  rbx[block_cnt].max_entry = nmax;
                }

              if (strlen
                  (report->blocks[rblock_cnt].entries[entry_cnt].string))
                {

			int eid;
			int slen;
		//printf("Have length for %d/%d\n",rblock_cnt,entry_cnt);
                    eid = report->blocks[rblock_cnt].entries[entry_cnt].entry_id;
			/*
			if (entry_cnt>= rbx[block_cnt].max_size_entry) {
				printf("OOPS1\n");
			}
			*/
                    rbx[block_cnt].entry_nos[entry_cnt] = eid;
                    slen=strlen (report->blocks[rblock_cnt].entries[entry_cnt].  string);
                    rbx[block_cnt].max_size_entry[entry_cnt] =slen;
                }
            }
        }
      b = 0;
      tmp_space_e = acl_malloc2 (sizeof (int) * rbx[block_cnt].max_entry);
      tmp_space_s = acl_malloc2 (sizeof (int) * rbx[block_cnt].max_entry);
      for (a = 0; a < rbx[block_cnt].max_entry; a++)
        {
          if (rbx[block_cnt].entry_nos[a] >= 0
              && rbx[block_cnt].max_size_entry[a])
            {
		//printf("Keeping %d\n",rbx[block_cnt].entry_nos[a]);
              tmp_space_e[b] = rbx[block_cnt].entry_nos[a];
              tmp_space_s[b] = rbx[block_cnt].max_size_entry[a];
              b++;
            }
          else
            {
              //printf ("Discarding block %d entry %d - %d %d\n", block_cnt, a, rbx[block_cnt].entry_nos[a], rbx[block_cnt].max_size_entry[a]);
            }
        }
      rbx[block_cnt].nentry_nos = b;
      memcpy (rbx[block_cnt].entry_nos, tmp_space_e,
              sizeof (int) * rbx[block_cnt].nentry_nos);
      memcpy (rbx[block_cnt].max_size_entry, tmp_space_s,
              sizeof (int) * rbx[block_cnt].nentry_nos);
      free (tmp_space_e);
      free (tmp_space_s);
    }
*ptr_rbs=rbs;
*ptr_rbx=rbx;
}





int load_filter_file_header(char *fname, FILE **fin, char*msgbuff) {
  //int ok;
  FILE *fin_filter;
  char buff[255];
  char logrep[255];
  char orig[255];
  char rname[255];
  char mname[255];
  if (fname)
    {
      char *ptr;
      //printf ("fname==%s\n", fname);
      ptr = strrchr (fname, '/');
      if (ptr == 0)
        ptr = fname;

      fin_filter = fopen (fname, "r");
	*fin=fin_filter;

      if (!fin_filter) {
        if (strchr (ptr, '.') == 0) {
                        strcat (fname, ".lrf");
                        fin_filter = fopen (fname, "w");
                }
        }

        if (!fin_filter) {
                strcpy(msgbuff,"I can't open that file..");
                return 0;
        }


        fgets(buff,255,fin_filter);
        if (sscanf(buff,"A4GL_LOGICAL_REPORT %s",logrep)) {
                if (strcmp(logrep,(char *)acl_getenv ("LOGREP"))!=0) {
                        strcpy(msgbuff, "This doesn't look like a valid layout file for this engine");
                        return 0;
                }
        } else {
                        strcpy(msgbuff, "This doesn't look like a valid layout file");
                        return 0;
        }

        fgets(buff,255,fin_filter);
        sscanf(buff,"%s %s",rname,mname);

        if (strcmp(rname,report->repName)!=0) {
                sprintf(buff,"This doesn't look like its from the same report (%s != %s)",rname,report->repName);
                strcpy(msgbuff, buff);
        }

        if (strcmp(mname,report->modName)!=0) {
                sprintf(buff,"This doesn't look like its from the same module (%s != %s)",mname,report->modName);
                strcpy(msgbuff, buff);
        }

        fgets(buff,255,fin_filter);
        sprintf(orig,"Original output filename : %s",buff);
	return 1;

    }
  else
    {
      strcpy(msgbuff,  "No load performed...");
	return 0;
    }
    return 0;

}
