#include <stdio.h>
#include <string.h>
#define FILE_VERSION 2
#include "a4gl_lle.h"


FILE *fin=0;
int lvl;
int ok;

int max_page_no = -1;
int max_line_no = -1;
int max_col_no = -1;
static void read_block ();
void free_report() ;

struct r_report *report;


static int read_int ()
{
  int n;
  short s;
  unsigned char c;

  fread (&c, sizeof (c), 1, fin);
  if (c<254) return c;
  if (c==254) {
  	fread (&s, sizeof (s), 1, fin);
	return ntohs(s);
  }
  fread (&n, sizeof (n), 1, fin);

  return ntohl(n);
}

static char read_char ()
{
  char n;
  fread (&n, sizeof (n), 1, fin);
  return n;
}

static char * read_string ()
{
  int n;
  char *p;
  n = read_int ();
  p = (char *) malloc (n + 1);
  fread (p, n, 1, fin);
  p[n] = 0;
  return p;
}

static void trim (char *s)
{
  char *p;
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
  if (max_page_no > 1000)
    {
      char *ptr = 0;
      *ptr = 0;
    }
}





struct r_report *read_report_output(char *fname) {
  int npages;
  char buff[256];
  int buff_i;
  char buff_c;
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

  report=(struct r_report *)malloc(sizeof(struct r_report));

  report->repName=0;
  report->modName=0;
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
	  free_report();
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
	return;
    }

    
}



static void read_block ()
{
  char buff_c;
  int cblock;
  //printf("Read block : %d\n",lvl);
  lvl++;
  cblock = report->nblocks++;
  report->blocks = (struct r_report_block *) realloc (report->blocks, report->nblocks * sizeof (struct r_report_block));
  report->blocks[cblock].why=0;
  report->blocks[cblock].nentries = 0;
  report->blocks[cblock].entries = 0;
  report->blocks[cblock].line = read_int (); if (feof (fin)) { printf ("Unexpected EOF\n"); ok=0; return; }
  report->blocks[cblock].where = read_char (); if (feof (fin)) { printf ("Unexpected EOF\n"); ok=0; return; }
  report->blocks[cblock].why = read_string (); if (feof (fin)) { printf ("Unexpected EOF\n"); ok=0;return; }
  report->blocks[cblock].rb = read_int (); if (feof (fin)) { printf ("Unexpected EOF\n"); ok=0; return; }
  //printf("Got report block : (%s %d %c %s %d)\n", report->blocks[cblock].mod, report->blocks[cblock].line, report->blocks[cblock].where, report->blocks[cblock].why, report->blocks[cblock].rb);

  while (ok)
    {
      buff_c = read_char ();
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



read_entry(struct r_report_block *block) {
      /* If we've got to here - then we must have a valid DATA block.. */
      block->nentries++;
      block->entries = (struct r_report_block_entries *) realloc (block->entries, block->nentries * sizeof (struct r_report_block_entries));

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

void free_report() {
	// need to go through and unallocate all the other stuff too...
	free(report);
}
