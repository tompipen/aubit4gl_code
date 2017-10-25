
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define FILE_VERSION 3

#include "a4gl_lle.h"



#ifndef A4GL_gzfread
#error A4GL_gzfread should be a macro
#endif



static int debug = 0;

void read_entry (struct r_report_block *block);

#if HAVE_LIBCURL
FILE *gzfin = 0;
#else
A4GL_gzPtr gzfin = 0;
#endif
static int lvl;
int ok;

int max_page_no = -1;
int max_line_no = -1;
int max_col_no = -1;
static void read_block (void);
void free_report (void *report);

static struct r_report *report;

static int
read_int (void)
{
  int n;
  int a;
/* Keep it simple for now */
#if HAVE_LIBCURL
  a = url_fread (&n, sizeof (n), 1, gzfin);
#else
  a = A4GL_gzfread (&n, sizeof (n), 1, gzfin);
#endif
  if (a < 1)
    {
      A4GL_assertion (1, "Failed to read int");
    }
#ifdef DEBUG
  A4GL_debug ("Read : %d", a4gl_ntohl (n));
#endif
  return a4gl_ntohl (n);
}

static char
read_char (void)
{
  char n = 0;
  int p;
  int a;

#if HAVE_LIBCURL
  a = url_fread (&n, sizeof (n), 1, gzfin);
#else
  a = A4GL_gzfread (&n, sizeof (n), 1, gzfin);
#endif

  A4GL_assertion (a < 0, "Failed to read character");
  if (a == 0)
    return 0;			// End of file

  p = (int) n;
  if (!isprint (p))
    {
      if (debug)
	printf ("Suspect read_char (%d %x %c)\n", n, n, n);
    }

  return n;
}

static char *
read_string (void)
{
  int n;
  char *p;
  int a;
  n = read_int ();
  p = (char *) acl_malloc2 (n + 1);

#if HAVE_LIBCURL
  a = url_fread (p, n, 1, gzfin);
#else
  a = A4GL_gzfread (p, n, 1, gzfin);
#endif

  if (a < 1)
    {
      A4GL_assertion (a != n, "Failed to read string");
    }
  p[n] = 0;
#ifdef DEBUG
  A4GL_debug ("Read : %s", p);
#endif
  return p;
}

static void
trim (char *s)
{
  //char *p;
  int a;
  for (a = strlen (s) - 1; a > 0; a--)
    {
      if (A4GL_isblank (s[a]))
	s[a] = 0;
      else
	break;
    }
}

static void
trimnl (char *s)
{
  //char *p;
  int a;
  for (a = strlen (s) - 1; a > 0; a--)
    {
      if (A4GL_isblank (s[a]) || s[a] == '\n' || s[a] == '\r')
	s[a] = 0;
      else
	break;
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
  if (max_page_no > 50000)
    {
      printf ("Dubious number of pages - I think i'd better stop..\n");
      exit (1);
    }
}





struct r_report *
read_report_output (char *fname)
{
  char buff_c;
  char *l;
  int c;

#if HAVE_LIBCURL
  gzfin = url_fopen (fname, "rz");
  //curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, 1000);
#else
  gzfin = A4GL_gzfopen (fname, "r");
#endif
  max_page_no = -1;
  max_line_no = -1;
  max_col_no = -1;
  lvl = 0;
  ok = 1;

  if (gzfin == 0)
    {
      char buff[2000];
      //printf ("Unable to open input file : %s\n", fname);
      sprintf (buff, "Unable to open input file : %s", fname);
      A4GL_assertion (1, buff);
      return 0;
    }

  c = read_char ();
  if (c != ENTRY_START)
    {				/* First block should always be a 1.. */

      printf ("Looks like a bad file... Got %d - expecting %d\n", c, ENTRY_START);
      printf ("If you're reading from a URL - make sure that if the file is compressed\n");
      printf ("that it has a .gz extension. By default .loe files *are* compressed - but do\n");
      printf ("not have the .gz extention.");

      return 0;
    }

  report = (struct r_report *) acl_malloc2 (sizeof (struct r_report));

  report->repName = 0;
  report->modName = 0;

  l = read_string ();		// This should be tg

  if (strcmp ("LOGICAL REPORT OUTPUT", l) != 0)
    {
      printf ("Looks like a bad file...\n");
      if (l)
	free (l);
      return 0;
    }
  if (l)
    free (l);
  report->version_no = read_int ();
  report->ctime = read_int ();
  report->top_margin = read_int ();
  report->bottom_margin = read_int ();
  report->left_margin = read_int ();
  report->right_margin = read_int ();
  report->page_length = read_int ();
  report->repName = read_string ();
  report->modName = read_string ();

  report->nblocks = 0;
  report->blocks = 0;

  //printf("%s %s\n",report->repName,report->modName);

  if (report->version_no != FILE_VERSION)
    {
      printf
	("This program was compiled up to accept LLE files version %d, this appears to be version %d\n",
	 FILE_VERSION, report->version_no);
      free (report);
      return 0;
    }


  while (ok)
    {
      buff_c = read_char ();

#if HAVE_LIBCURL
      if (url_feof (gzfin))
	break;
#else
      if (A4GL_gzfeof (gzfin))
	break;
#endif

      if (buff_c != ENTRY_BLOCK)
	{
	  printf ("Unexpected block (1) Got %d\n", buff_c);
	  free_report (report);
	  return 0;
	}
      read_block ();
    }

  if (ok)
    {
      report->max_page = max_page_no;
      report->max_line = max_line_no;
      report->max_col = max_col_no;
      return report;
    }
  else
    {
      free_report (report);
      return 0;
    }


}



static void
read_block ()
{
  char buff_c;
  int cblock;
  //printf("Read block : %d\n",lvl);
  if (debug)
    {
      printf ("read block - lvl=%d \n", lvl);
    }
  lvl++;
  cblock = report->nblocks++;
  report->blocks = (struct r_report_block *) acl_realloc (report->blocks, report->nblocks * sizeof (struct r_report_block));
  report->blocks[cblock].why = 0;
  report->blocks[cblock].nentries = 0;
  report->blocks[cblock].entries = 0;
  report->blocks[cblock].line = read_int ();

#if HAVE_LIBCURL
  if (url_feof (gzfin))
    {
#else
  if (A4GL_gzfeof (gzfin))
    {
#endif
      printf ("Unexpected EOF\n");
      ok = 0;
      return;
    }
  if (debug)
    printf ("line=%d\n", report->blocks[cblock].line);
  report->blocks[cblock].where = read_char ();


#if HAVE_LIBCURL
  if (url_feof (gzfin))
    {
#else
  if (A4GL_gzfeof (gzfin))
    {
#endif
      printf ("Unexpected EOF\n");
      ok = 0;
      return;
    }
  if (debug)
    printf ("where=%c\n", report->blocks[cblock].where);
  report->blocks[cblock].why = read_string ();

#if HAVE_LIBCURL
  if (url_feof (gzfin))
    {
#else
  if (A4GL_gzfeof (gzfin))
    {
#endif

      printf ("Unexpected EOF\n");
      ok = 0;
      return;
    }

  if (debug)
    printf ("where=%s\n", report->blocks[cblock].why);
  report->blocks[cblock].rb = read_int ();

#if HAVE_LIBCURL
  if (url_feof (gzfin))
    {
#else
  if (A4GL_gzfeof (gzfin))
    {
#endif

      printf ("Unexpected EOF\n");
      ok = 0;
      return;
    }

  if (debug)
    {
      printf ("read block - line=%d where=%c why=%s rb=%d\n", report->blocks[cblock].line, report->blocks[cblock].where,
	      report->blocks[cblock].why, report->blocks[cblock].rb);
    }

  while (ok)
    {
      buff_c = read_char ();
      if (debug)
	{
	  printf ("buff_c=%c\n", buff_c);
	}
      if (buff_c == ENTRY_BLOCK_END)
	{
	  lvl--;
	  return;
	}


      if (buff_c == ENTRY_BLOCK)
	{
	  read_block ();
	  continue;
	}

      if (buff_c == ENTRY_DATA)
	{
	  read_entry (&report->blocks[cblock]);
	  continue;
	}

      printf ("Unexpected block : %d\n", buff_c);
      exit (2);

    }

}



void
read_entry (struct r_report_block *block)
{
  /* If we've got to here - then we must have a valid DATA block.. */
  block->nentries++;
  block->entries =
    (struct r_report_block_entries *) acl_realloc (block->entries, block->nentries * sizeof (struct r_report_block_entries));

  block->entries[block->nentries - 1].string = 0;
  block->entries[block->nentries - 1].page_no = read_int ();
  block->entries[block->nentries - 1].line_no = read_int ();
  block->entries[block->nentries - 1].col_no = read_int ();
  block->entries[block->nentries - 1].entry_id = read_int ();
  block->entries[block->nentries - 1].string = read_string ();

  trim (block->entries[block->nentries - 1].string);
  if (strlen (block->entries[block->nentries - 1].string) == 0)
    {
      // Theres no point storing spaces - we just want data...
      free (block->entries[block->nentries - 1].string);
      block->nentries--;
    }
  else
    {
      check_for_max (block->entries[block->nentries - 1].page_no,
		     block->entries[block->nentries - 1].line_no,
		     block->entries[block->nentries - 1].col_no, block->entries[block->nentries - 1].string);
    }
}

void
free_report (void *report)
{
  // need to go through and unallocate all the other stuff too...
  if (report)
    free (report);
}




void
obtain_rbs_rbx (struct r_report *report, int *ptr_rbs, struct s_rbx **ptr_rbx)
{
  int rbs;
  struct s_rbx *rbx;
  int a;
  int block_cnt;
  int rblock_cnt;
  int entry_cnt;
  int found;
  int b;
  rbs = 0;
  rbx = 0;

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

      int max = 0;
      for (rblock_cnt = 0; rblock_cnt < report->nblocks; rblock_cnt++)
	{

	  if (rbx[block_cnt].rb != report->blocks[rblock_cnt].rb)
	    {
	      continue;
	    }

	  // Find the maximum entry_id in the current set of entries
	  // this is set from the report and will be unique for each print
	  for (entry_cnt = 0; entry_cnt < report->blocks[rblock_cnt].nentries; entry_cnt++)
	    {
	      struct r_report_block_entries *entry;
	      entry = &report->blocks[rblock_cnt].entries[entry_cnt];
	      if (entry->entry_id > max)
		{
		  max = entry->entry_id;
		}
	    }
	}


      // Allocate enough space for any entries
      tmp_space_e = acl_malloc2 (sizeof (int) * (max + 1));	// Entries
      tmp_space_s = acl_malloc2 (sizeof (int) * (max + 1));	// Sizes

      // Blank them off
      for (a = 0; a < max + 1; a++)
	{
	  tmp_space_e[a] = -1;
	  tmp_space_s[a] = -1;
	}

      for (rblock_cnt = 0; rblock_cnt < report->nblocks; rblock_cnt++)
	{
	  if (rbx[block_cnt].rb != report->blocks[rblock_cnt].rb)
	    {
	      continue;
	    }

	  // Now - go through and see whats actually used...
	  for (entry_cnt = 0; entry_cnt < report->blocks[rblock_cnt].nentries; entry_cnt++)
	    {
	      struct r_report_block_entries *entry;
	      entry = &report->blocks[rblock_cnt].entries[entry_cnt];
	      tmp_space_e[entry->entry_id] = 1;

	      if (entry->string)
		{
		  int slen = -1;
		  slen = strlen (entry->string);
		  if (slen > tmp_space_s[entry->entry_id])
		    {
		      tmp_space_s[entry->entry_id] = slen;
		    }
		}
	    }

	}


      // Now - work out how many were actually used...
      int cntUsed = 0;
      int entry_id;
      for (entry_id = 0; entry_id < max; entry_id++)
	{
	  if (tmp_space_e[entry_id] >= 0 && tmp_space_s[entry_id] > 0)
	    {
	      cntUsed++;
	    }
	}

      // Create the array to store these
      rbx[block_cnt].entry_nos = acl_malloc2 (cntUsed * sizeof (int));
      rbx[block_cnt].nentry_nos = cntUsed;
      rbx[block_cnt].max_size_entry = acl_malloc2 (cntUsed * sizeof (int));

      cntUsed = 0;
      for (entry_id = 0; entry_id < max; entry_id++)
	{
	  if (tmp_space_e[entry_id] >= 0 && tmp_space_s[entry_id] > 0)
	    {
	      rbx[block_cnt].entry_nos[cntUsed] = entry_id;
	      rbx[block_cnt].max_size_entry[cntUsed] = tmp_space_s[entry_id];
	      cntUsed++;
	    }
	}



      free (tmp_space_e);
      free (tmp_space_s);

    }


  *ptr_rbs = rbs;
  *ptr_rbx = rbx;
}




int
load_filter_file_header (char *fname, FILE ** fin_save, char *msgbuff)
{
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
      *fin_save = fin_filter;

      if (!fin_filter)
	{
	  if (strchr (ptr, '.') == 0)
	    {
	      strcat (fname, ".lrf");
	      fin_filter = fopen (fname, "w");
	    }
	}

      if (!fin_filter)
	{
	  strcpy (msgbuff, "I can't open that file..");
	  return 0;
	}


      fgets (buff, 255, fin_filter);
      if (sscanf (buff, "A4GL_LOGICAL_REPORT %s", logrep))
	{
	  if (strcmp (logrep, (char *) acl_getenv ("LOGREP")) != 0)
	    {
	      strcpy (msgbuff, "This doesn't look like a valid layout file for this engine");
	      return 0;
	    }
	}
      else
	{
	  strcpy (msgbuff, "This doesn't look like a valid layout file");
	  return 0;
	}

      fgets (buff, 255, fin_filter);
      sscanf (buff, "%s %s", rname, mname);

      if (report != NULL)
	{
	  if (strcmp (rname, report->repName) != 0)
	    {
	      sprintf (buff, "This doesn't look like its from the same report (%s != %s)", rname, report->repName);
	      strcpy (msgbuff, buff);
	    }

	  if (strcmp (mname, report->modName) != 0)
	    {
	      sprintf (buff, "This doesn't look like its from the same module (%s != %s)", mname, report->modName);
	      strcpy (msgbuff, buff);
	    }
	}

      fgets (buff, 255, fin_filter);
      sprintf (orig, "Original output filename : %s", buff);
      return 1;

    }
  else
    {
      strcpy (msgbuff, "No load performed...");
      return 0;
    }
  return 0;

}


int
load_filter_file_header_info (char *fname, FILE ** fin_save, char *msgbuff, char *rname, char *mname, char *logrep, char *buff)
{
  //int ok;
  FILE *fin_filter;
  //char buff[255];
  //char logrep[255];
  //char orig[255];
  //char rname[255];
  //char mname[255];
  if (fname)
    {
      char *ptr;
      //printf ("fname==%s\n", fname);
      ptr = strrchr (fname, '/');
      if (ptr == 0)
	ptr = fname;

      fin_filter = fopen (fname, "r");
      *fin_save = fin_filter;

      if (!fin_filter)
	{
	  if (strchr (ptr, '.') == 0)
	    {
	      strcat (fname, ".lrf");
	      fin_filter = fopen (fname, "w");
	    }
	}

      if (!fin_filter)
	{
	  strcpy (msgbuff, "I can't open that file..");
	  return 0;
	}


      fgets (buff, 255, fin_filter);
      trimnl (buff);
      if (!sscanf (buff, "A4GL_LOGICAL_REPORT %s", logrep))
	{
	  strcpy (msgbuff, "This doesn't look like a valid layout file");
	  return 0;
	}

      fgets (buff, 255, fin_filter);
      trimnl (buff);
      sscanf (buff, "%s %s", rname, mname);

      fgets (buff, 255, fin_filter);
      trimnl (buff);
      return 1;

    }
  else
    {
      strcpy (msgbuff, "No load performed...");
      return 0;
    }
  return 0;

}



static int nonprintmode = -1;
static char *
xml_escape_int (char *s)
{
  static char *buff = 0;
  static int last_len = 0;
  int c;
  int a;
  int l;
  int b;
  int allocated;
  int sl;
  if (nonprintmode == -1)
    {
      char *s = acl_getenv ("NONPRINTXMLMODE");
      nonprintmode = 0;
      if (strcmp (s, "1") == 0)
	{
	  nonprintmode = 1;
	}
      if (strcmp (s, "2") == 0)
	{
	  nonprintmode = 2;
	}
    }

  A4GL_assertion (s == NULL, "Null pointer passed to xml_escape_int");

  sl = strlen (s);

  c = 0;
  for (a = 0; a < sl; a++)
    {
      if (s[a] == '&' || s[a] == '<' || s[a] == '>' || s[a] == '"' || s[a] == '\'' || s[a] == '\n' || s[a] == '\r' || s[a] < 31
	  || s[a] > 126)
	{
	  c++;
	  break;
	}

    }



  if (c == 0)
    {
      return s;
    }

  l = strlen (s);
  allocated = (l * 6) + 1;

  if (l > last_len)
    {
      buff = realloc (buff, allocated);
      last_len = l;
    }

  b = 0;
  for (a = 0; a < l; a++)
    {
      if (s[a] == '>')
	{
	  buff[b++] = '&';
	  buff[b++] = 'g';
	  buff[b++] = 't';
	  buff[b++] = ';';
	  continue;
	}
      if (s[a] == '<')
	{
	  buff[b++] = '&';
	  buff[b++] = 'l';
	  buff[b++] = 't';
	  buff[b++] = ';';
	  continue;
	}
      if (s[a] == '&')
	{
	  buff[b++] = '&';
	  buff[b++] = 'a';
	  buff[b++] = 'm';
	  buff[b++] = 'p';
	  buff[b++] = ';';
	  continue;
	}
      if (s[a] == '"')
	{
	  buff[b++] = '&';
	  buff[b++] = 'q';
	  buff[b++] = 'u';
	  buff[b++] = 'o';
	  buff[b++] = 't';
	  buff[b++] = ';';
	  continue;
	}
      if (s[a] == '\'')
	{
	  buff[b++] = '&';
	  buff[b++] = 'a';
	  buff[b++] = 'p';
	  buff[b++] = 'o';
	  buff[b++] = 's';
	  buff[b++] = ';';
	  continue;
	}


      if (s[a] < 31 || s[a] > 126)
	{
	  if (nonprintmode == 1)
	    {
	      int z1;
	      char buff2[20];
	      z1 = ((unsigned char) s[a]);
	      sprintf (buff2, "&#x%02X;", z1);
	      for (z1 = 0; z1 < strlen (buff2); z1++)
		{
		  buff[b++] = buff2[z1];
		}
	      continue;
	    }

	  if (nonprintmode == 2)
	    {
	      int z1;
	      char buff2[20];
	      z1 = ((unsigned char) s[a]);
	      sprintf (buff2, "\\%02X", z1);
	      for (z1 = 0; z1 < strlen (buff2); z1++)
		{
		  buff[b++] = buff2[z1];
		}
	      continue;
	    }
	}


      buff[b++] = s[a];
    }
  if (b >= allocated)
    {

      fprintf (stderr, "b=%d allocated=%d l=%d\n", b, allocated, l);
    }
  if (b >= allocated)
    {
      fprintf (stderr, "XML escape buffer too small");
      exit (2);
    }
  buff[b] = 0;
  return buff;
}


char *
RP_xmlencode (char *s)
{
  char *rval;
  static int n = 0;
  static char *buff[5] = { NULL, NULL, NULL, NULL, NULL };
  A4GL_assertion (n < 0 || n >= 5, "Buffer out of range - memory corruption?");
  if (buff[n])
    {
      free (buff[n]);
      buff[n] = 0;
    }
  if (s == 0)
    return "NULL";

  buff[n] = strdup (xml_escape_int (s));


  rval = buff[n];
  n++;
  if (n >= 5)
    n = 0;
  return rval;

}




char **
RP_split_on_delimiter (char *str, int *nrecords)
{
  int cnt = 1;
  int a;
  int ml;
  char *delim = "|";
  static char *cptr[200];
  char *lbuff = str;

  ml = strlen (lbuff);
  /* Convert to unix format - if its msdos */
  if (lbuff[ml - 2] == '\r' && lbuff[ml - 1] == '\n')
    {
      ml--;
      lbuff[ml - 2] = '\n';
      lbuff[ml - 1] = 0;
    }
  cptr[0] = &lbuff[0];
  for (a = 0; a <= ml; a++)
    {
      if (lbuff[a] == delim[0] || lbuff[a] == 0)
	{
	  cptr[cnt++] = &lbuff[a + 1];
	}
    }

  cnt--;

  for (a = 1; a <= cnt; a++)
    *(cptr[a] - 1) = 0;


/*
  for (a = 0; a < cnt; a++)
    {
      A4GL_push_char (cptr[a]);
    }*/
  *nrecords = cnt;
  return cptr;
}
