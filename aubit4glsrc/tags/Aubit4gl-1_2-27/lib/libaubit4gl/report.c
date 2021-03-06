/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-2005 Aubit Development Team (See Credits file)    |
# +----------------------------------------------------------------------+
# | This program is free software; you can redistribute it and/or modify |
# | it under the terms of one of the following licenses:                 |
# |                                                                      |
# |  A) the GNU General Public License as published by the Free Software |
# |     Foundation; either version 2 of the License, or (at your option) |
# |     any later version.                                               |
# |                                                                      |
# |  B) the Aubit License as published by the Aubit Development Team and |
# |     included in the distribution in the file: LICENSE                |
# |                                                                      |
# | This program is distributed in the hope that it will be useful,      |
# | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
# | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
# | GNU General Public License for more details.                         |
# |                                                                      |
# | You should have received a copy of both licenses referred to here.   |
# | If you did not, or have any questions about Aubit licensing, please  |
# | contact licensing@aubit.com                                           |
# +----------------------------------------------------------------------+
#
# $Id: report.c,v 1.202 2011-07-22 20:10:00 mikeaubury Exp $
#
*/


/**
 * @file
 * Execute report (text mode) implementation
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

 /*
    =====================================================================
    Includes
    =====================================================================
  */

#include "a4gl_libaubit4gl_int.h"
#include "a4gl_API_sql.h"

// FIXME test and uncomment, if OK
//#ifdef _WIN32
//#include <windows.h>
//#endif

//struct s_sid * A4GLSQL_prepare_select (struct BINDING *ibind, int ni, struct BINDING *obind, int no, char *s);
//int A4GL_call_4gl_dll (char *filename, char *function, int args);
static void A4GL_unload_report_table (struct BINDING *b);
void A4GL_close_report_file (struct rep_structure *rep);
//int A4GL_wcswidth(char *mbs); /* utf8 */

#define ENTRY_START 1
#define ENTRY_BLOCK 2
#define ENTRY_BLOCK_END 3
#define ENTRY_DATA 4
#define ENTRY_ENTRY_START 5
#define ENTRY_ENTRY_END 6
#define TU_END(qual) (qual & 0xf)
#define TU_START(qual) ((qual>>4) & 0xf)
#define TU_LEN(qual) ((qual>>8) & 0xff)


static int email_report (char *fname, char *otype);
static void free_header (struct rep_structure *rep);
static char *cursor_for_rep_tab (void *b);
char pdf_encoding[200] = "winansi";


void print_header_entries (struct rep_structure *rep);


int rs_with_page_length = -1;
int rs_with_left_margin = -1;
int rs_with_right_margin = -1;
int rs_with_top_margin = -1;
int rs_with_bottom_margin = -1;
char *rs_with_top_of_page = "";

struct s_save_header_entry
{
  int page_no;
  int line_no;
  int col_no;
  int entry;
  int rb;
  char *s;
};

struct s_save_header
{
  struct s_save_header_entry *save;
  int save_cnt;
};

static void report_write_entry (struct rep_structure *rep, char type);
static void print_gzlvl (struct rep_structure *rep, int lvl);
static void print_data (struct rep_structure *rep, char *buff, int entry);
int A4GL_push_report_print (struct rep_structure *rep, char *mod, int lineno, char where, char *why, int rb);
void A4GL_pop_report_print (struct rep_structure *rep, int pb, int rb);
//void A4GL_pop_report_section (struct rep_structure *rep, int rb);
static void report_write_string (struct rep_structure *rep, char *s);
static void report_write_int (struct rep_structure *rep, int n);
static void report_write_char (struct rep_structure *rep, unsigned char n);
static void report_write_why (struct rep_structure *rep, char where, char *why);

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void A4GL_aclfgli_skip_lines (struct rep_structure *rep);
void A4GL_fputmanyc (struct rep_structure *rep, int c, int cnt);
void A4GL_set_column (struct rep_structure *rep);
void A4GL_free_duplicate_binding (struct BINDING *b, int n);
//struct BINDING *A4GL_duplicate_binding (struct BINDING *b, int n);
void A4GL_skip_top_of_page (struct rep_structure *rep, int n);
//int A4GL_push_report_section (struct rep_structure *rep, char *mod, char *repname, int lineno, char where, char *why, int rb);

void A4GL_rep_print (struct rep_structure *rep, int no_param, int dontwant_nl, int right_margin, int entry);
void A4GL_rep_print_tag (struct rep_structure *rep, int entry,char *_tag);
void A4GL_need_lines (struct rep_structure *rep);
void A4GL_add_spaces (void);
static char *A4GL_mk_temp_tab (struct BINDING *b, int n);
void A4GL_make_report_table (struct BINDING *b, int n);
void A4GL_add_row_report_table (struct BINDING *b, int n);
int A4GL_init_report_table (struct BINDING *b, int n, struct BINDING *o, int no, struct BINDING **reread, char *asc_desc);
int A4GL_report_table_fetch (struct BINDING *reread, int n, struct BINDING *b);
void A4GL_end_report_table (struct BINDING *b, int n, struct BINDING *reread);
void A4GL_rep_file_print (struct rep_structure *rep, char *fname, int opt_semi);
static char *A4GL_report_char_pop (void);


char *A4GL_decode_datatype (int dtype, int dim);
extern sqlca_struct a4gl_sqlca;
void A4GL_finished_report (void);
static void add_header_entry (struct rep_structure *rep, struct s_save_header *hdr, char *buff, int entry);
//static char *get_end_tag(char *tag_type) ;
//static char *get_start_tag(char *tag_type) ;


int lvl = 0;

void *curr_pdf_report = 0;


/*
=====================================================================
                    Functions definitions
=====================================================================
*/


static char *
top_of_page (char *s, char *why)
{
  int n;
  static char *b = 0;		// Keep it hanging around....
  n = strlen (s) + 1;
  if (n < 20)
    n = 20;
  if (b != 0)
    free (b);
  b = malloc (n);
  strcpy (b, s);
  A4GL_trim (b);
  if (A4GL_aubit_strcasecmp (b, "^L") == 0)
    {				// OK - we had 3 characters alloc'd
      //b[0]=why[0];
      b[0] = 12;		// we're going to use just 2...
      b[1] = 0;
    }
  return b;
}



/*
********************************************************************************
* TEMPORARY REPORT CLEANUP CODE
********************************************************************************
*/

char **repnames = 0;
int nrepnames = 0;


static void
print_rep_header (FILE * f, char *s)
{
  int l;
  int a;
  if (strstr (s, "\\0") == 0 || strlen (s) < 2)
    {
      FPRINTF (f, "%s", s);
      return;
    }
  l = strlen (s);
  for (a = 0; a < l; a++)
    {

      if (a)
	{
	  if (s[a - 1] != '\\' && s[a] == '\\' && s[a + 1] == '0')
	    {
	      fputc (0, f);
	      a++;
	      continue;
	    }
	  if (s[a - 1] == '\\' && s[a] == '\\' && s[a + 1] == '0')
	    {
	      continue;
	    }
	}
      fputc (s[a], f);
    }

}




static char *
report_header_encode (char *s)
{
  static char *buff = 0;
  int l;
  int a;
  int b = 0;

  if (strstr (s, "\\0") == 0)
    return s;
  l = strlen (s);
  buff = realloc (buff, l * 4 + 10);

  for (a = 0; a < l; a++)
    {
      if (s[a] == '\\' && s[a + 1] == '0')
	{
	  buff[b++] = '\\';
	}
      buff[b++] = s[a];
    }
  buff[b] = 0;
  return buff;
}


/* 
Go through a list of uncleaned temp report files
and remove them automatically.
*/
void
A4GL_cleanup_undeleted_files (void)
{
  int a;


  if (repnames == 0)
    return;

  for (a = 0; a < nrepnames; a++)
    {
      if (repnames[a])
	{
#ifdef DEBUG
	  A4GL_debug ("Cleaning up : %s", repnames[a]);
#endif
	  if (!A4GL_isyes (acl_getenv ("LEAVETMPREPORTS")))
	    {
	      unlink (repnames[a]);
	    }
	  repnames[a] = 0;
	}
    }
  nrepnames = 0;
  free (repnames);
  repnames = 0;
}


/* 
Indicate that a temporary report file has
been deleted already 
*/
static void
deleted_rep (char *fname)
{
  int a;
  if (repnames == 0)
    return;
  for (a = 0; a < nrepnames; a++)
    {
      if (repnames[a] == 0)
	continue;
      if (strcmp (fname, repnames[a]) == 0)
	{
	  free (repnames[a]);
	  repnames[a] = 0;
	}
    }
}



/* 
indicate that a temporary report file has
been added - so we can delete it if required.
*/
static void
add_convertible_report (char *fname)
{
  int a;
  if (repnames == 0)
    {
      repnames = malloc (sizeof (char *));
      repnames[0] = 0;
      nrepnames = 1;
    }

  for (a = 0; a < nrepnames; a++)
    {
      if (repnames[a] == 0)
	{
	  // We can use this slot...
	  repnames[a] = strdup (fname);
	  return;
	}
    }

// Theres no free slot..
  nrepnames++;
  repnames = realloc (repnames, nrepnames * sizeof (char *));
  repnames[nrepnames - 1] = strdup (fname);

}




/*
********************************************************************************
*/

void
add_header_entry (struct rep_structure *rep, struct s_save_header *hdr, char *buff, int entry)
{
  char *n;
  char *top;
  int istop;
  top = 0;
  istop = 0;

  if (rep->top_of_page)
    {
      if (strlen (rep->top_of_page))
	{
	  top = top_of_page (rep->top_of_page, "C");
	}
    }



  if (strlen (buff))
    {
      n = acl_strdup (buff);
      A4GL_trim (n);
      if (top)
	{
	  if (strcmp (n, top) == 0)
	    {
	      istop = 1;
	    }
	}
      if (strlen (n) && strcmp (n, "\n") != 0 && istop == 0)
	{
	  hdr->save_cnt++;
	  hdr->save = realloc (hdr->save, sizeof (struct s_save_header_entry) * hdr->save_cnt);
	  hdr->save[hdr->save_cnt - 1].page_no = rep->page_no;
	  hdr->save[hdr->save_cnt - 1].line_no = rep->line_no;
	  hdr->save[hdr->save_cnt - 1].col_no = rep->col_no;
	  hdr->save[hdr->save_cnt - 1].entry = entry;
	  hdr->save[hdr->save_cnt - 1].s = acl_strdup (buff);

	  hdr->save[hdr->save_cnt - 1].rb = rep->curr_rb;

#ifdef DEBUG
	  A4GL_debug ("Add header entry : %d %d %d %d %s\n", rep->page_no, rep->line_no, rep->col_no, entry, buff);
#endif
	}
      free (n);
    }
}


void
print_header_entries (struct rep_structure *rep)
{
  int p;
  int l;
  int c;
  int a;
  struct s_save_header *hdr;
  int last_rb = -1;
 int changed_report_section=0;
 

// Save these away - we'll need to change them...

  p = rep->page_no;
  l = rep->line_no;
  c = rep->col_no;
  if (rep->header)
    {
      hdr = (struct s_save_header *) rep->header;
      for (a = 0; a < hdr->save_cnt; a++)
	{

	  if (rep->curr_rb != hdr->save[a].rb )
	    {
	      int rb;
		if (rep->rb_stack_level) {
			last_rb=rep->rb_stack[rep->rb_stack_level-1];
	      		A4GL_pop_report_section (rep, last_rb);
			changed_report_section=1;
		}
	      rb = hdr->save[a].rb;
	      A4GL_push_report_section (rep, rep->modName, rep->repName, rep->blocks[rb].lineno, rep->blocks[rb].where, rep->blocks[rb].why, rb);


	    }

	  rep->page_no = hdr->save[a].page_no;
	  rep->line_no = hdr->save[a].line_no;
	  rep->col_no = hdr->save[a].col_no;
	  print_data (rep, hdr->save[a].s, hdr->save[a].entry);
#ifdef DEBUG
	  A4GL_debug ("PRINING         : %d %d %d %d %s\n", rep->page_no, rep->line_no, rep->col_no, hdr->save[a].entry, hdr->save[a].s);
#endif
	  free (hdr->save[a].s);
	}


      rep->page_no = p;
      rep->line_no = l;
      rep->col_no = c;
      free (hdr->save);
      free (hdr);
    }

	if (changed_report_section) {
		int rb;
      		A4GL_pop_report_section (rep, rep->curr_rb);
      		rb = last_rb;

#ifdef DEBUG
      		A4GL_debug ("rep=%p", rep);
      		A4GL_debug ("rep->modName=%s", rep->modName);
      		A4GL_debug ("rep->repName=%s", rep->repName);
      		A4GL_debug ("rb=%d", rb);
      		A4GL_debug ("lineno=%d", rep->blocks[rb].lineno);
      		A4GL_debug ("where=%c", rep->blocks[rb].where);
      		A4GL_debug ("why=%s", rep->blocks[rb].why);
#endif
      		A4GL_assertion (rb > rep->nblocks, "Corrupt block (rb > rep->nblocks)");
		
      		A4GL_push_report_section (rep, rep->modName, rep->repName, rep->blocks[rb].lineno, rep->blocks[rb].where, rep->blocks[rb].why, rb);
	}


}


void
free_header (struct rep_structure *rep)
{
  struct s_save_header *hdr;
  int a;

  if (rep->header)
    {
      hdr = (struct s_save_header *) rep->header;
      for (a = 0; a < hdr->save_cnt; a++)
	{
	  free (hdr->save[a].s);
	}
      free (hdr->save);
      free (hdr);
    }
}


#define SECTION_NORMAL 0
#define SECTION_HEADER 1
#define SECTION_TRAILER 2



static void
report_print (struct rep_structure *rep, int entry, char *fmt, ...)
{
  va_list ap;
  char buff[20000];

  if (rep->output == 0)
    {
      A4GL_assertion (rep->output == 0, "Report outfile file closed prematurely ?");
    }
  va_start (ap, fmt);

  if (entry <= 0)
    entry = 0;
  VSPRINTF (buff, fmt, ap);

#ifdef DEBUG
  A4GL_debug ("'%s' - %d\n", buff, entry);
#endif
  if (rep->print_section == SECTION_NORMAL)
    {

      if (rep->header)
	{
	  if (rep->output_mode == 'C')
	    {
	      print_header_entries (rep);
	      rep->header = 0;
	    }
	  else
	    {

	      print_rep_header (rep->output, rep->header);

	      // FPRINTF (rep->output, "%s", rep->header);
	      free (rep->header);
	      rep->header = 0;
	    }
	}

      if (rep->output_mode == 'C')
	{
	  print_data (rep, buff, entry);
	}
      else
	{
	  if (strlen (buff) == 0 && A4GL_last_was_ascii_null ())
	    {
	      fputc (0, rep->output);
	    }
	  else
	    {
	      FPRINTF (rep->output, "%s", buff);
	    }
	}

    }

  if (rep->print_section == SECTION_TRAILER)
    {
      if (rep->header)
	{
	  if (rep->output_mode == 'C')
	    {
	      free_header (rep);
	      rep->header = 0;
	    }
	  else
	    {
	      free (rep->header);
	      rep->header = 0;
	    }
	}			// we've got a cached header - don't do anything..
      else
	{
	  if (rep->output_mode == 'C')
	    {
	      print_data (rep, buff, entry);
	    }
	  else
	    {
	      if (strlen (buff) == 0 && A4GL_last_was_ascii_null ())
		{
		  fputc (0, rep->output);
		}
	      else
		{
		  FPRINTF (rep->output, "%s", buff);
		}
	    }

	}
    }

  if (rep->print_section == SECTION_HEADER)
    {
      if (rep->output_mode == 'C')
	{
	  if (rep->header)
	    {
	      add_header_entry (rep, (struct s_save_header *) rep->header, buff, entry);
	    }
	  else
	    {
	      struct s_save_header *hdr;
	      hdr = acl_malloc2 (sizeof (struct s_save_header));
	      hdr->save_cnt = 0;
	      hdr->save = 0;
	      rep->header = (char *) hdr;
	      add_header_entry (rep, hdr, buff, entry);

	    }
	  //print_data (rep, buff, entry);

	}
      else
	{


	  if (rep->header)
	    {
	      int a;
	      a = strlen (rep->header);
	      rep->header = realloc (rep->header, a + strlen (buff) + 10);	// a bit extra...
	      rep->header[a] = 0;

	      if (strlen (buff) == 0 && A4GL_last_was_ascii_null ())
		{
		  strcat (rep->header, "\\0");
		}
	      else
		{
		  strcat (rep->header, report_header_encode (buff));
		}
	    }
	  else
	    {
	      if (strlen (buff) == 0 && A4GL_last_was_ascii_null ())
		{
		  rep->header = acl_strdup ("\\0");
		}
	      else
		{
		  rep->header = acl_strdup (report_header_encode (buff));
		}
	    }


	}
    }




}


/**
 *
 * @todo Describe function
 */
static char *
gen_rep_tab_name (void *p, int isCreateUsage)
{
  static char buf[256];
  char *owner;
  char *sep;

  // A bind pointer seems to be unique in a single process, but it is not
  // across processes. It matters when a temp tables are emulated by a
  // persistent ones. So we use also a PID (currenly POSIX systems only).
  // However, it is still NOT SAFE across operating system instances!
  static long pid = -1;
#ifdef _POSIX_SOURCE
  if (pid == -1)
    pid = getpid () & 0xffffffff;
#else
// FIXME test and uncomment, if OK
// this piece of Win32 code should work, but I can't presently test it, so
// I've commented it, as well as #include line at the top of this file
//#ifdef _WIN32
//    if (pid == -1)
//      pid = (long)GetCurrentProcessId() & 0xffffffff;
//#endif
#endif
  sep = ".";
  owner = acl_getenv ("A4GL_REP_DEFAULT_OWNER");
  if (strlen (owner) == 0 || owner == NULL)
    {
      owner = "";
      sep = "";
    }
  if (isCreateUsage)
    {
      SPRINTF4 (buf, "%s%sRT%08X%08X", owner, sep, (unsigned int) pid, (unsigned int) p & 0xffffffff);
    }
  else
    {
      if (A4GLSQLCV_check_requirement ("CREATE_TEMP_AS_CREATE_HASH"))
	{
	  SPRINTF4 (buf, "#%s%sRT%08X%08X", owner, sep, (unsigned int) pid, (unsigned int) p & 0xffffffff);
	}
      else
	{
	  SPRINTF4 (buf, "%s%sRT%08X%08X", owner, sep, (unsigned int) pid, (unsigned int) p & 0xffffffff);
	}
    }
  return buf;
}


void
A4GL_close_report_file (struct rep_structure *rep)
{
  if (rep->output_mode == 'C')
    {
      if (rep->output)
	{
	  gzfclose (rep->output);
	  rep->output = 0;
	}
    }
  else
    {
      if (rep->output)
	{
	  fflush (rep->output);
	  if (rep->output != stdout)
	    {
	      fclose (rep->output);

	      if (rep->output_mode=='U') {
			A4GL_ui_send_report_to_ui(rep->output_loc_str,rep->page_length,"SCREEN");
			A4GL_delete_file(rep->output_loc_str);
		}

	      if (rep->output_mode == 'M')
		{
		  email_report (rep->output_loc_str, 0);
		}
	    }
	  rep->output = 0;
	}
    }
}

void
A4GL_internal_open_report_file (struct rep_structure *rep, int no_param)
{

  if (rep->line_no == 0 && rep->page_no == 0 && no_param < 0)
    {

      if (rep->output_mode == 'C')
	{
	  tmpnam (rep->output_loc_str);

	  rep->output = gzfopen (rep->output_loc_str, "w");
	  if (rep->output == 0)
	    {
	      A4GL_exitwith ("Could not open report output");
	      return;
	    }
	  add_convertible_report (rep->output_loc_str);

	}
      else
	{

	  if (rep->output_mode == 'F' || rep->output_mode == 'M' || rep->output_mode=='U')
	    {


	      if (strcmp (rep->output_loc_str, "stdout") == 0)
		{
		  A4GL_gotolinemode ();
		  rep->output = stdout;
		  A4GL_gotolinemode ();
		}
	      else
		{
		  rep->output = A4GL_mja_fopen (rep->output_loc_str, "w");
		  if (rep->output == 0)
		    {
		      A4GL_exitwith ("Could not open report output");
		      return;
		    }
		}


	    }
	  else
	    {
	      if (rep->output_mode == 'S')
		{
		  rep->output = stdout;
		}
	      else
		{
#ifdef DEBUG
		  A4GL_debug ("popen '%s'", rep->output_loc_str);
#endif
		  rep->output = popen (rep->output_loc_str, "w");
		  if (rep->output == 0)
		    {
		      A4GL_exitwith ("Could not open report output");
		      return;
		    }
		}
	    }

	}


      if (rep->output_mode == 'C')
	{
	  report_write_entry (rep, ENTRY_START);
	}

    }
}


void
A4GL_rep_print_tag (struct rep_structure *rep, int entry, char *_tag)
{
  char *str;
  char buff[2000];
  //int sl;
  int diff;
  str = A4GL_report_char_pop ();

// We only want to embed the tag if we are generating a convertible report...

  if (rep->output_mode == 'C')
    {
      //colno=rep->col_no;
      sprintf (buff, "##TAG(%s,%s)##",str, _tag);
      diff = strlen (buff) - strlen (str);
      A4GL_push_char (buff);
      A4GL_rep_print (rep, 1, 1, 0, entry);
      rep->col_no -= diff;
      acl_free (str);
    }
  else
    {
  	sprintf(buff,"%s%s%s",A4GL_get_start_tag(_tag),str,A4GL_get_end_tag(_tag));
        diff = strlen (buff) - strlen (str);
        A4GL_push_char (buff);
        A4GL_rep_print (rep, 1, 1, 0, entry);
        rep->col_no -= diff;
        acl_free (str);
    }

}

/**
 *
 * @todo Describe function
 * print something onto a report
 *  rep - report structure to use
 *  a   - number of parameters to print
 *  s   - do we require a newline at the end of this print
 *  right_margin - current right margin (not implemented yet)
 *  entry - unique identifier for this print within this block
 */
void
A4GL_rep_print (struct rep_structure *rep, int no_param, int dontwant_nl, int right_margin, int entry)
{
  int b;
  int cnt;
  char *str;
#ifdef DEBUG
  A4GL_debug ("In A4GL_rep_print rep=%p rep->report=%p Page=%d Line=%d Col=%d entry=%d", rep, rep->report, rep->page_no,
	      rep->line_no, rep->col_no, entry);
#endif



  if (right_margin > 0)
    {
      char *s;
      int a;
      char *ptr;
      int init_col;
      int orig_r;
      orig_r = right_margin;



      init_col = rep->col_no;

      if (no_param != 1)
	{
	  A4GL_assertion (1, "Expecting single variable for wordwrap margin");
	}
      s = A4GL_report_char_pop ();

      // Informix4GL seems to automatically clip any wordwrap fields - so lets 
      // do the same...
      if (A4GL_isyes (acl_getenv ("TRIMWORDWRAP")))
	{
	  A4GL_trim (s);
	}

      ptr = s;
      if (init_col > right_margin)
	{
	  A4GL_exitwith ("Cant print at this column with that right margin :-(");
	  return;
	}

      if (init_col == 0)
	{
	  right_margin -= rep->left_margin;
	}
      else
	{
	  right_margin -= init_col;
	}



      while (1)
	{
	  A4GL_debug_print_stack ();
	  if (rep->col_no < init_col)
	    {
	      A4GL_push_int (init_col);
	      A4GL_set_column (rep);
	      A4GL_rep_print (rep, 1, 1, 0, -2);

	    }

	  if (strlen (ptr) <= right_margin && strchr (ptr, '\n'))
	    {
	      char *p2;
	      p2 = strchr (ptr, '\n');
	      *p2 = 0;
	      A4GL_push_char (ptr);
	      A4GL_rep_print (rep, 1, 1, 0, entry);
	      A4GL_rep_print (rep, 0, 0, 0, -1);
	      ptr = p2 + 1;
	    }

	  if (strlen (ptr) > right_margin)
	    {
	      int found = 0;
	      // First - look forward - see if there are any '\n' in the next 'rightmargin' characters...
	      for (a = 0; a <= right_margin; a++)
		{
		  //int c;
		  if (ptr[a] == '\n')
		    {		// This will do nicely...
		      ptr[a] = 0;
		      A4GL_push_char (ptr);
		      A4GL_rep_print (rep, 1, 1, 0, entry);
		      A4GL_rep_print (rep, 0, 0, 0, -1);

		      found = 1;
		      ptr += a + 1;
		      if (*ptr == '\r')
			ptr++;
		      break;
		    }
		}


	      if (!found)
		{
		  // We need to split it into smaller groups...
		  for (a = right_margin + 1; a >= 0; a--)
		    {
		      int c;
		      if (ptr[a] == ' ' || ptr[a] == '\t')
			{	// This will do nicely...
			  c = ptr[a + 1];
			  ptr[a + 1] = 0;
			  A4GL_push_char (ptr);
			  ptr[a + 1] = c;
			  A4GL_rep_print (rep, 1, 1, 0, entry);
			  A4GL_rep_print (rep, 0, 0, 0, -1);
			  found = 1;
			  ptr += a + 1;
			  break;
			}
		    }
		}

	      if (!found)
		{
		  char *buff;
		  buff = malloc (right_margin + 1);
		  memset (buff, 0, right_margin + 1);
		  strncpy (buff, ptr, right_margin);
		  buff[right_margin] = 0;
		  A4GL_push_char (buff);
		  A4GL_rep_print (rep, 1, 1, 0, entry);
		  A4GL_rep_print (rep, 0, 0, 0, -1);
		  free (buff);
		  ptr += right_margin;
		}
	    }
	  else
	    {
	      char buff[10000];
	      int psize;
	      // it'll fit...
	      strcpy (buff, ptr);


	      if (init_col)
		{
		  psize = right_margin - rep->left_margin + 1;
		}
	      else
		{
		  psize = orig_r - rep->left_margin + 1;
		  if (init_col == 0)
		    psize--;
		}
	      if (psize > 0)
		{
		  A4GL_assertion (psize > sizeof (buff), "Buffer to small for padspace");
		  A4GL_pad_string (buff, psize);
		}
	      A4GL_push_char (buff);
	      A4GL_rep_print (rep, 1, dontwant_nl, 0, entry);
	      return;
	    }
	}
      return;
    }

  if (rep->line_no == 0 && rep->page_no == 0 && no_param < 0)
    {
      A4GL_internal_open_report_file (rep, no_param);
    }

  if (rep->finishing && entry == -5 && no_param == 0 && strlen (rep->top_of_page))
    {
      int a;
      a = rep->page_length - rep->line_no - rep->bottom_margin - rep->lines_in_trailer + 1;
      // Reports finishing - lets get to the end of our page ...
      if (a || 1)
	report_print (rep, -1, top_of_page (rep->top_of_page, "A"));
      return;
    }

  if (no_param < 0)
    {				// We're just setting up...
      return;
    }






  if (rep->line_no == 0 && !rep->finishing)
    {
      rep->line_no = 1;
      rep->page_no++;
      rep->print_section = SECTION_HEADER;
#ifdef DEBUG
      A4GL_debug ("Need page header ?");
#endif

      if (rep->top_margin)
	{
#ifdef DEBUG
	  A4GL_debug ("Skip lines...");
#endif
	  A4GL_push_int (rep->top_margin);
	  A4GL_aclfgli_skip_lines (rep);
#ifdef DEBUG
	  A4GL_debug ("Done skip lines");
#endif
	}

      if (rep->report == 0)
	{
#ifdef DEBUG
	  A4GL_debug ("OOPS - no report function!!!");
#endif
	  A4GL_assertion (1, "Internal error - no report function");
	  A4GL_fgl_die (10);
	}
      rep->report (0, REPORT_PAGEHEADER);	/* report.c:180: too many arguments to function */
      rep->print_section = 0;
#ifdef DEBUG
      A4GL_debug ("Done page header");
#endif
    }

#ifdef DEBUG
  A4GL_debug ("Popping %d parameters", no_param);
#endif




  if (no_param > 0)
    {
      if (rep->printed_left_margin == 0)
	{
	  rep->printed_left_margin = 1;
	  rep->col_no = 1;

	  A4GL_fputmanyc (rep, ' ', rep->left_margin);
	}


      for (b = 0; b < no_param; b++)
	{
	  str = A4GL_report_char_pop ();
#ifdef DEBUG
	  A4GL_debug ("Popped '%s'...", str);
#endif

	  if (strchr (str, '\n'))
	    {
	      char *left;
	      char *right;
	      left = str;
	      right = strchr (str, '\n');
	      *right = 0;
	      right++;
	      A4GL_push_char (left);
	      A4GL_rep_print (rep, 1, 1, 0, entry);
	      A4GL_rep_print (rep, 0, 0, 0, -1);
	      A4GL_push_char (right);
	      A4GL_rep_print (rep, 1, 1, 0, entry);
	      continue;
	    }
	  else
	    {
	      report_print (rep, entry, "%s", str);
	    }
	  /* rep->col_no += strlen (str); *//* utf8 */
	  if (A4GL_isno (acl_getenv ("NO_UTF8")))
	    {
	      rep->col_no += A4GL_wcswidth (str);
	    }
	  else
	    {
	      rep->col_no += strlen (str);
	    }

#ifdef DEBUG
	  A4GL_debug ("Popped %s\n", str);
#endif
	  acl_free (str);
	}
    }

#ifdef DEBUG
  A4GL_debug ("Newline : %d", dontwant_nl);
#endif




  if (dontwant_nl == 0)
    {
      rep->col_no = 0;
      rep->printed_left_margin = 0;
      report_print (rep, -1, "\n");
      rep->line_no++;

  if (no_param || rep->finishing || entry == -5 || 1)
    {
      if (rep->print_section == SECTION_NORMAL)
	{
	  if (rep->line_no > rep->page_length - rep->lines_in_trailer - rep->bottom_margin)
	    {
	      rep->print_section = SECTION_TRAILER;
	      rep->report (0, REPORT_PAGETRAILER);	/* report.c:180: too many arguments to function */
	      rep->print_section = SECTION_NORMAL;
	    }

	  if (rep->line_no > rep->page_length - rep->bottom_margin)
	    {
	      if (strlen (rep->top_of_page) == 0)
		{
		  for (cnt = 0; cnt < rep->bottom_margin; cnt++)
		    {
		      report_print (rep, -1, "\n");
		      //rep->line_no++;
		    }
		}
	      else
		{
		  report_print (rep, -1, top_of_page (rep->top_of_page, "B"));
		}

	      rep->line_no = 0;

	      if (rep->lines_in_trailer)
		{
#ifdef DEBUG
		  A4GL_debug ("Calling rep_print");
#endif
		  A4GL_rep_print (rep, 0, 1, 0, -10);
		}
	    }
	}
    }
   }
  return;
}


int
A4GL_report_lineno (struct rep_structure *rep)
{
  if (rep->line_no > rep->page_length - rep->bottom_margin || rep->line_no==0)
    {
      return 0;
    }
  return rep->line_no - 1;
}

/**
 *
 * @todo Describe function
 */
void
A4GL_fputmanyc (struct rep_structure *rep, int c, int cnt)
{
  //int a;
  char *x;
  x = acl_malloc2 (cnt + 1);
  memset (x, c, cnt);
  x[cnt] = 0;
  report_print (rep, -1, x);
  free (x);
}

/**
 *
 * @todo Describe function
 */
void
A4GL_set_column (struct rep_structure *rep)
{
  long a;
  long needn;
  a = A4GL_pop_long ();
  if (A4GL_isnull(DTYPE_INT,(void *)&a)) {
	A4GL_push_empty_char();
	return ;
  }
  A4GL_push_empty_char();
#ifdef DEBUG
  A4GL_debug ("in set_column a=%d Calling rep_print", a);
#endif
  A4GL_rep_print (rep, 1, 1, 0, -2);
#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("Popped %ld - print what we have", a);
  }
#endif
#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("Current pos=%d need position %d left_margin=%d", rep->col_no, a, rep->left_margin);
  }
#endif

  if (rep->col_no == 0)
    {
      needn = a + rep->left_margin - 1;
      rep->col_no = 1;
    }
  else
    {
      needn = a - rep->col_no;
    }

#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("needn=%ld", needn);
  }
#endif

  if (needn > 0)
    {

      A4GL_fputmanyc (rep, ' ', (int) needn);
      rep->col_no += needn;
#ifdef DEBUG
      /* {DEBUG} */
      {
	A4GL_debug ("Colno increased by %d", needn);
      }
#endif
    }
  else
    {
#ifdef DEBUG
      /* {DEBUG} */
      {
	A4GL_debug ("Already past that point");
      }
#endif
    }
  A4GL_push_empty_char ();
}

/**
 *
 * @todo Describe function
 */
void
A4GL_aclfgli_skip_lines (struct rep_structure *rep)
{
  long a;
  long b;
  int o_page;
  a = A4GL_pop_long ();
  o_page = rep->page_no;

  for (b = 0; b < a; b++)
    {
      if (rep->print_section != SECTION_TRAILER)
	{
	  if (rep->line_no - 1 > (rep->page_length - rep->bottom_margin - 1 - rep->lines_in_trailer))
	    break;
	}
      else
	{
	  if (rep->line_no - 1 > (rep->page_length - rep->bottom_margin - 1))
	    break;
	}

      A4GL_rep_print (rep, 0, 0, 0, -3);
    }
}

/**
 *
 * @todo Describe function
 */
void
A4GL_need_lines (struct rep_structure *rep)
{
  int a;
  a = A4GL_pop_int ();
  if (rep->line_no - 1 > (rep->page_length - rep->bottom_margin - a - rep->lines_in_trailer))
    {

      A4GL_skip_top_of_page (rep, 2);
    }
}

/**
 *
 * @todo Describe function
 */
void
A4GL_skip_top_of_page (struct rep_structure *rep, int n)
{
  int z;
  int a;

  a = rep->page_length - rep->line_no - rep->bottom_margin - rep->lines_in_trailer + 1;

  if (n != 1 || rep->page_no)
    {
      if (rep->header)
	return;
      if (rep->line_no == 0 || (rep->line_no==1 && rep->page_length!=1))
	return;
    }

  if (a || n == 999)
    {
      if (strlen (rep->top_of_page) == 0)
	{
	  for (z = 0; z < a; z++)
	    {
	      A4GL_rep_print (rep, 0, 0, 0, -4);
	    }
	}
      else
	{
	  //report_print (rep, -1, top_of_page(rep->top_of_page,"D"));
	  rep->line_no += a;
	}

      if (rep->finishing || n == 0 || n == 999)
	{
	  A4GL_rep_print (rep, 0, 1, 0, -5);
	}
    }
}

/**
 *
 * @todo Describe function
 */
void
A4GL_add_spaces (void)
{
  int a=0;
  char str[1000];
  a = A4GL_pop_int ();
  if (A4GL_isnull (DTYPE_SMINT, (void *)&a)) {
		A4GL_push_char("");
		return;
  }

  if (a<=0) {
	A4GL_push_char("");
	return;
  }

  //A4GL_assertion(a>=sizeof(str), "Attempt to print too many spaces");
  if (a >= 1000)
    a = 999;
  
  memset (str, ' ', a);
  str[a] = 0;
  A4GL_push_char (str);
}



/**
 * ORDER BY
 *
 * @todo Describe function
 */
static char *
nm (int n)
{
  switch (n & DTYPE_MASK)
    {
    case DTYPE_CHAR:
      return "CHAR";
    case DTYPE_SMINT:
      return "SMALLINT";
    case DTYPE_INT:
      return "INTEGER";
    case DTYPE_FLOAT:
      return "FLOAT";
    case DTYPE_SMFLOAT:
      return "SMALLFLOAT";
    case DTYPE_DECIMAL:
      return "DECIMAL";
    case DTYPE_SERIAL:
      return "INTEGER";
    case DTYPE_DATE:
      return "DATE";
    case DTYPE_MONEY:
      return "MONEY";
    case DTYPE_DTIME:
      return "DATETIME ";
    case DTYPE_BYTE:
      return "BYTE";
    case DTYPE_TEXT:
      return "TEXT";
    case DTYPE_VCHAR:
      return "VARCHAR";
    case DTYPE_INTERVAL:
      return "INTERVAL ";
    }
  return "CHAR";
}


char *inparts[] = {
  "",
  "YEAR",
  "MONTH",
  "DAY",
  "HOUR",
  "MINUTE",
  "SECOND",
  "FRACTION(1)",
  "FRACTION(2)",
  "FRACTION(3)",
  "FRACTION(4)",
  "FRACTION(5)"
};



static char *
decode_interval (int a)
{
  static char buff[200];
  int s[3];
  s[2] = a & 0xf;
  a = a >> 4;
  s[1] = a & 0xf;
  a = a >> 4;
  s[0] = a & 0xf;
  a = a >> 4;
  SPRINTF3 (buff, "%s(%d) TO %s\n", inparts[s[1]], s[0], inparts[s[2]]);
  return buff;
}



static char *
decode_dt_elem (int a)
{

  switch (a)
    {
    case 1:
      return "YEAR";
    case 2:
      return "MONTH";
    case 3:
      return "DAY";
    case 4:
      return "HOUR";
    case 5:
      return "MINUTE";
    case 6:
      return "SECOND";
    case 7:
      return "FRACTION(1)";
    case 8:
      return "FRACTION(2)";
    case 9:
      return "FRACTION(3)";
    case 10:
      return "FRACTION(4)";
    case 11:
      return "FRACTION(5)";
    }

  return "UNKNOWN";

}

/**
 *
 * @todo Describe function
 */
static char *
sz (int d, int s)
{
  static char buff_1[256];
  //static char buff_2[256];
  //static char buff_3[256];
  switch (d & DTYPE_MASK)
    {
    case DTYPE_SMINT:
    case DTYPE_INT:
    case DTYPE_FLOAT:
    case DTYPE_SMFLOAT:
    case DTYPE_DATE:
    case DTYPE_SERIAL:
    case DTYPE_BYTE:
    case DTYPE_TEXT:
      return "";

    case DTYPE_DTIME:
      SPRINTF2 (buff_1, "%s TO %s", decode_dt_elem (s >> 4), decode_dt_elem (s & 0xf));
      return buff_1;
      /* return " YEAR TO FRACTION(5)"; */

    case DTYPE_MONEY:
    case DTYPE_DECIMAL:	/* decimal */
      return "(32,16)";

    case DTYPE_CHAR:
    case DTYPE_VCHAR:
    case DTYPE_NCHAR:
    case DTYPE_NVCHAR:
      SPRINTF1 (buff_1, "(%d)", s);
      return buff_1;

    case DTYPE_INTERVAL:
      SPRINTF0 (buff_1, decode_interval (s));
      return buff_1;
    }
  return "";
}


#define TU_YEAR 0
#define TU_MONTH 2
#define TU_DAY 4
#define TU_HOUR 6
#define TU_MINUTE 8
#define TU_SECOND 10
#define TU_FRAC 12
#define TU_F1 11
#define TU_F2 12
#define TU_F3 13
#define TU_F4 14
#define TU_F5 15


static int
Infx_dt_to_A4gl_dt (int n)
{
  switch (n)
    {
    case TU_YEAR:
      return 1;
    case TU_MONTH:
      return 2;
    case TU_DAY:
      return 3;
    case TU_HOUR:
      return 4;
    case TU_MINUTE:
      return 5;
    case TU_SECOND:
      return 6;
    case TU_F1:
      return 7;
    case TU_F2:
      return 8;
    case TU_F3:
      return 9;
    case TU_F4:
      return 10;
    case TU_F5:
      return 11;
    }
  // Shouldn't get to here
     return 3;
}

static long
fixlength (int dtype, int length)
{
  int n1, n2,n3;
  if (dtype > 255)
    dtype -= 256;
#ifdef DEBUG
  A4GL_debug ("Got datatype : %d length %d\n", dtype, length);
#endif
  if (dtype==DTYPE_DECIMAL||dtype==DTYPE_MONEY) {
        int a1,a2;
        a1=length&0xff;
        a2=length>>8;
        if (a1==0xff) {
                a1=2; a2+=5;
                if (a2>32) a2=32;
                length=(a2<<8)+a1;
                return length;
        }

  }


  if (dtype == DTYPE_DTIME)
    {
      n1 = Infx_dt_to_A4gl_dt (TU_START (length));
      n2 = Infx_dt_to_A4gl_dt (TU_END (length));
      return (n1 * 16) + n2;
    }

  if (dtype == DTYPE_INTERVAL)
    {
      n1 = Infx_dt_to_A4gl_dt (TU_START (length));
      n2 = Infx_dt_to_A4gl_dt (TU_END (length));
      n3 = length>>8;

      return (n3<<8)+(n1 * 16) + n2;
    }

  return length;
}



/**
 * Used for AREP compiler 
 * @todo Describe function
 */
char *
A4GL_decode_datatype (int dtype, int dim)
{
  static char buff_2[256];
	dim=fixlength(dtype,dim);
  SPRINTF2 (buff_2, "%s %s", nm (dtype), sz (dtype, dim));
  return buff_2;
}

static char *
A4GL_drop_temp_tab (struct BINDING *b)
{
  static char buff_3[30000];

  SPRINTF1 (buff_3, "drop table %s\n", gen_rep_tab_name (b, 0));
  return buff_3;
}


/**
 *
 * @todo Describe function
 */
static char *
A4GL_mk_temp_tab (struct BINDING *b, int n)
{
  int a;
  static char buff_3[30000];
  char tmpbuff[256];

  /*
     hopefully b should be fairly random within this session..
     as the same report cannot be running twice at the same time.....
     Andrej say: yes it can!
   */

  if ( A4GLSQLCV_check_requirement("USEREALTABLEFORREP"))
    {
      SPRINTF1 (buff_3, "create table %s (\n", gen_rep_tab_name (b, 1));
    }
  else
    {
      SPRINTF1 (buff_3, "create temp table %s (\n", gen_rep_tab_name (b, 1));
    }

  for (a = 0; a < n; a++)
    {
      if (a)
	strcat (buff_3, ",\n");
      SPRINTF3 (tmpbuff, "c%d %s %s", a, nm (b[a].dtype), sz (b[a].dtype, b[a].size));
      strcat (buff_3, tmpbuff);
    }
  strcat (buff_3, ")");

  return buff_3;
}

/**
 *
 * @todo Describe function
 */
void
A4GL_make_report_table (struct BINDING *b, int n)
{
  int a;
  a = aclfgli_get_err_flg ();

  A4GL_execute_implicit_sql (A4GL_prepare_select (0, 0, 0, 0, A4GL_drop_temp_tab (b), "__internal_report", 99, 0, 1), 1, 0, 0);
  if (a == 0)
    {
      aclfgli_clr_err_flg ();	// we don't care if the drop fails...
      A4GLSQL_set_sqlca_sqlcode (0);
    }

  A4GL_execute_implicit_sql (A4GL_prepare_select (0, 0, 0, 0, A4GL_mk_temp_tab (b, n), "__internal_report", 99, 0, 1), 1, 0, 0);

}



static void
A4GL_unload_report_table (struct BINDING *b)
{
  char buff[1024];
  struct BINDING *ibind = 0;
  if (A4GL_isyes (acl_getenv ("UNLOADREPDBG")))
    {
      SPRINTF1 (buff, "SELECT * FROM %s", gen_rep_tab_name (b, 0));
      A4GL_unload_data ("zz9pa", "|", buff, 0, ibind, 0);
    }
}

/**
 *
 * @todo Describe function
 */
void
A4GL_add_row_report_table (struct BINDING *b, int n)
{
  char buff[1024];
  int a;
  void *x;
  char b2[200];

  SPRINTF2 (b2, "a4glrp_%lx%d", (long) (b), n);
  x = A4GL_find_prepare (b2);
  if (x == NULL)
    {
#ifdef DEBUG
      A4GL_debug ("Add row report table");
#endif
      SPRINTF1 (buff, "INSERT INTO %s VALUES (", gen_rep_tab_name (b, 0));

      for (a = 0; a < n; a++)
	{
	  if (a)
	    strcat (buff, ",");
	  strcat (buff, "?");
	}
      strcat (buff, ")");

#ifdef DEBUG
      A4GL_debug ("Attempting to execute %s\n", buff);
#endif
      x = (void *) A4GL_prepare_select (b, n, 0, 0, buff, "__internal_report", 1, 0, 0);
#ifdef DEBUG
      A4GL_debug ("x=%p\n", x);
#endif
      A4GL_add_prepare (b2, x);
    }
  A4GL_execute_implicit_sql (x, 0, 0, 0);
  //A4GLSQL_free_prepare(x);
#ifdef DEBUG
  A4GL_debug ("a4glsqlca.sqlcode=%d", a4gl_sqlca.sqlcode);
#endif
}

/**
 *
 * @todo Describe function
 */
int
A4GL_init_report_table (struct BINDING *b, int n, struct BINDING *o, int no, struct BINDING **reread, char *asc_desc)
{
  int a1;
  int a2;
  int ok;
  char buff[1024];
  //char tbuff[1024];
  char obuff[1024];
  struct s_sid *pstmt;
  struct BINDING ibind[] = {
    /* ibind 0 */
    {0, 0, 0, 0, 0, 0}
  };				/* end of binding */
  struct BINDING obind[] = {
    {0, 0, 0, 0, 0, 0}
  };				/* end of binding */

#ifdef DEBUG
  A4GL_debug ("init_rep_table");
#endif
  *reread = A4GL_duplicate_binding (b, n);


if (no) {
  SPRINTF1 (buff, "select * from %s order by ", gen_rep_tab_name (b, 0));
} else {
  SPRINTF1 (buff, "select * from %s", gen_rep_tab_name (b, 0));
}

  A4GL_unload_report_table (b);	// This is useful for debugging....

  for (a1 = 0; a1 < no; a1++)
    {
      ok = 0;
#ifdef DEBUG
      A4GL_debug ("Looking for %p", o[a1]);
#endif

      if (a1)
	strcat (buff, ",");
      for (a2 = 0; a2 < n; a2++)
	{
#ifdef DEBUG
	  A4GL_debug ("Checking %p %p", o[a1].ptr, b[a2].ptr);
#endif

	  if (o[a1].ptr == b[a2].ptr)
	    {
	      if (asc_desc[a1] == 'D')
		{
		  SPRINTF1 (obuff, "c%d DESC", a2);
		}
	      else
		{
		  SPRINTF1 (obuff, "c%d", a2);
		}
	      strcat (buff, obuff);
	      ok = 1;
	      break;
	    }
	}
      if (ok == 0)
	{
#ifdef DEBUG
	  A4GL_debug ("Can't A4GL_match column in orderby....");
#endif
	  A4GL_exitwith ("Big Oops");
	  return 0;
	}
    }


#ifdef DEBUG
  A4GL_debug ("Got select statement as : %s\n", buff);
#endif




#ifdef DEBUG
  A4GL_debug ("prepare...");
#endif
  pstmt = A4GL_prepare_select (ibind, 0, obind, 0, buff, "__internal_report", 2, 0, 0);
#ifdef DEBUG
  A4GL_debug ("%d\n", a4gl_sqlca.sqlcode);
#endif
  if (a4gl_sqlca.sqlcode != 0)
    {
#ifdef DEBUG
      A4GL_debug ("prepare failed");
#endif
      A4GL_exitwith ("Internal error - unable to prepare statement");
      return 0;
    }
#ifdef DEBUG
  A4GL_debug ("declare...");
#endif
  A4GL_declare_cursor (2, pstmt, 0, cursor_for_rep_tab (b));
#ifdef DEBUG
  A4GL_debug ("%d\n", a4gl_sqlca.sqlcode);
#endif
  if (a4gl_sqlca.sqlcode != 0)
    {
#ifdef DEBUG
      A4GL_debug ("declare failed");
#endif
      A4GL_exitwith ("Internal error - unable to declare statement");
      return 0;
    }


  A4GL_open_cursor (cursor_for_rep_tab (b), 0, 0);
  if (a4gl_sqlca.sqlcode != 0)
    return 0;


  return 0;
}


/**
 *
 * @todo Describe function
 */
int
A4GL_report_table_fetch (struct BINDING *reread, int n, struct BINDING *b)
{
  A4GLSQL_set_sqlca_sqlcode (0);

  A4GL_fetch_cursor (cursor_for_rep_tab (b), 2, 1, n, reread);

  if (a4gl_sqlca.sqlcode == 0) {
  	A4GL_push_params (reread, n);
    	return 1;
  }

  A4GLSQL_set_sqlca_sqlcode (0);
  return 0;
}

/**
 *
 * @todo Describe function
 */
void
A4GL_end_report_table (struct BINDING *b, int n, struct BINDING *reread)
{
  char b2[200];
  A4GL_close_cursor (cursor_for_rep_tab (b),1);
  A4GL_execute_implicit_sql (A4GL_prepare_select (0, 0, 0, 0, A4GL_drop_temp_tab (b), "__internal_report", 99, 0, 0), 1, 0,
				0);
  A4GL_free_duplicate_binding (reread, n);
  SPRINTF2 (b2, "a4glrp_%lx%d", (long) (b), n);
  if (A4GL_find_prepare(b2)) {
  	A4GL_free_cursor (b2,0);	// Actually a free prepare - but its the same function ;-)
  }

}

/**
 *
 * @todo Describe function
 */
struct BINDING *
A4GL_duplicate_binding (struct BINDING *b, int n)
{
  struct BINDING *rbind;
  int a;
  int sz;
#ifdef DEBUG
  A4GL_debug ("Duplicating bindings....");
#endif
  rbind = acl_malloc2 (sizeof (struct BINDING) * n);

  for (a = 0; a < n; a++)
    {
      sz = 0;
      switch (b[a].dtype)
	{
	case 0:
	case DTYPE_NCHAR:
	  sz = b[a].size + 1;
	  break;

	case 1:

	case 2:
	case 6:
	case 7:
	case 4:
	  sz = sizeof (long);
	  break;

	case 8:
	case 14:
	case 10:
	case 5:
	  sz = 64;
	  break;

	case 11:
	  sz = sizeof (fglbyte);
	  break;
	case 12:
	  sz = sizeof (fgltext);
	  break;
	case DTYPE_VCHAR:
	case DTYPE_NVCHAR:
	  	sz = b[a].size + 1;
		if (sz<256) sz = 256;
	  break;
	case 3:
	  sz = 8;
	  break;
	}

#ifdef DEBUG
      A4GL_debug ("allocing %d bytes\n", sz);
#endif
      rbind[a].ptr = acl_malloc2 (sz);
      memset (rbind[a].ptr, 0, sz);
#ifdef DEBUG
      A4GL_debug ("allocated as %p", rbind[a].ptr);
#endif

      rbind[a].dtype = b[a].dtype;
      rbind[a].size = b[a].size;
      rbind[a].libptr = 0;
    }

#ifdef DEBUG
  A4GL_debug ("All done");
#endif
  return rbind;
}

/**
 *
 * @todo Describe function
 */
void
A4GL_free_duplicate_binding (struct BINDING *b, int n)
{
  int a;
#ifdef DEBUG
  A4GL_debug ("Freeing duplicate..");
#endif
  for (a = 0; a < n; a++)
    {
#ifdef DEBUG
      A4GL_debug ("Freeing %p", b[a].ptr);
#endif
      if (b[a].ptr)
	free (b[a].ptr);
    }
#ifdef DEBUG
  A4GL_debug ("Freeing structure %p", b);
#endif
  free (b);
}


/**
 *
 * @todo Describe function
 */
void
A4GL_rep_file_print (struct rep_structure *rep, char *fname_x, int opt_semi)
{
  FILE *f;
  char buff[10000];
  char *fname;
  int has_cr;

  fname = strdup (fname_x);
  A4GL_trim (fname);
  f = fopen (fname, "r");
  free (fname);
  fname = 0;

  if (f == 0)
    {
      A4GL_exitwith ("Unable to open PRINT FILE file");
      return;
    }
  while (!feof (f))
    {
      char *a;
      memset (buff, 0, sizeof (buff));
      a = fgets (buff, sizeof (buff) - 1, f);
      if (!a)
	break;
      has_cr = 0;

      if (strlen (buff))
	{
	  // Trim any trailing \n
	  
	  while (buff[strlen (buff) - 1] == '\n' || buff[strlen (buff) - 1] == '\r')
	    {
	      int c;
	      has_cr++;
	      c = strlen (buff);
	      buff[c - 1] = 0;
		if (strlen(buff)==0) break;
	    }
	}
      A4GL_push_char (buff);
      if (has_cr)
	A4GL_rep_print (rep, 1, 0, 0, -1);
      else
	A4GL_rep_print (rep, 1, 1, 0, -1);
    }
  fclose (f);
}

/**
 *
 * @todo Describe function
 */
void
pdf_A4GL_rep_file_print (struct pdf_rep_structure *rep, char *fname_x, int opt_semi)
{
  char buff[10000];
  static char *fname=0;
  int lineno=0;
  int has_cr;
  long colno;

FILE *f;

  if (fname) free(fname);
  fname = strdup (fname_x);
  A4GL_trim (fname);
  f = fopen (fname, "r");

  colno=rep->col_no;


  if (f == 0)
    {
      A4GL_exitwith ("Unable to open PRINT FILE file");
      return;
    }
//printf("%p\n",f);

  while (1) 
    {
      char *a;

//printf("..%p\n",f);
	if (feof (f))  {
		break;
	}
	buff[0]=0;
      //memset (buff, 0, sizeof (buff));
      a = fgets (buff, sizeof (buff) - 1, f);
      if (!a)
	break;
      has_cr = 0;

      if (strlen (buff))
	{
	  // Trim any trailing \n
	  while (buff[strlen (buff) - 1] == '\n' || buff[strlen (buff) - 1] == '\r')
	    {
	      int c;
	      has_cr++;
	      c = strlen (buff);
	      buff[c - 1] = 0;
	    }
	}

	if (lineno && rep->col_no!=colno) { rep->col_no=colno; }

      A4GL_push_char (buff);
      if (has_cr)
	A4GL_pdf_rep_print (rep, 1, 0, 0, -1);
      else
	A4GL_pdf_rep_print (rep, 1, 1, 0, -1);


     //A4GL_pdf_rep_print(rep,0,1,0,-1);


      lineno++;
    }
  fclose (f);
 f=0;
}

/**
 * Report pause function
 * 
**/
void
A4GL_pause (char *s)
{
  int a;
  A4GL_push_char (s);
  A4GL_push_int (-1);
  A4GL_push_int (-1);
  A4GL_display_at (1, 0);
  //getchar ();                 // Not the best idea in the world....
  a = A4GL_get_key (-1);
}


static char *
A4GL_report_char_pop (void)
{
  int tos_size;
  int tos_dtype;
  void *tos_ptr;
  char *ptr;
  char *(*function) (void *, int, int, struct struct_scr_field *, int);
  A4GL_get_top_of_stack (1, &tos_dtype, &tos_size, (void **) &tos_ptr);

  function = A4GL_get_datatype_function_i (tos_dtype & DTYPE_MASK, "DISPLAY");
  A4GL_assertion (function == 0, "No report display function for this datatype");

  ptr = function (tos_ptr, tos_size, -1, (struct struct_scr_field *) 0, DISPLAY_TYPE_PRINT);

  if (ptr != 0)
    {
      ptr = acl_strdup (ptr);
      A4GL_drop_param ();
    }
  else
    {
      ptr = A4GL_char_pop ();

      if ((tos_dtype & DTYPE_MASK) == DTYPE_CHAR && strlen (ptr) < tos_size)
	{
	  // probably null - we still need it padding..
	  char *b;
	  b = malloc (tos_size + 1);
	  strcpy (b, ptr);
	  A4GL_pad_string (b, tos_size);
	  free (ptr);
	  ptr = b;
	}

      if ((tos_dtype & DTYPE_MASK) == DTYPE_NCHAR && nchar_strlen (ptr) < tos_size)
	{
	  // probably null - we still need it padding..
	  char *b;
	  b = malloc (tos_size + 1);
	  strcpy (b, ptr);
	  A4GL_pad_nstring (b, tos_size);
	  free (ptr);
	  ptr = b;
	}


      if ((tos_dtype & DTYPE_MASK) == DTYPE_VCHAR && strlen (ptr) == 0)
	{
	  free (ptr);
	  ptr = strdup (" ");
	}

      if ((tos_dtype & DTYPE_MASK) == DTYPE_NVCHAR && nchar_strlen (ptr) == 0)
	{
	  free (ptr);
	  ptr = strdup (" ");
	}

    }

  return ptr;

}

void
A4GL_finished_report (void)
{
// after a report has finished the screen
// maybe left in line mode...
}






















static void
print_report_block_start (struct rep_structure *rep, char *mod, char *repname, int lineno, char where, char *why, int rb)
{
  if (A4GL_isyes (acl_getenv ("TRACE_AS_TEXT")))
    {
      print_gzlvl (rep, lvl);
      A4GL_assertion(rb<0,"rb<0");
      gzfprintf (rep->output, "<ACL_ENTRY_BLOCK line=%d where=%c why=\"%s\" block=%d>\n", lineno, where, why, rb);
    }
  else
    {
      report_write_entry (rep, ENTRY_BLOCK);

      //report_write_string(rep,mod);
      //report_write_string(rep,repname);

      report_write_int (rep, lineno);
      report_write_why (rep, where, why);
      report_write_int (rep, rb);
    }
}

static void
print_report_block_end (struct rep_structure *rep, int rb)
{
  if (A4GL_isyes (acl_getenv ("TRACE_AS_TEXT")))
    {
      print_gzlvl (rep, lvl);
      gzfprintf (rep->output, "</ACL_ENTRY_BLOCK block=%d>\n", rb);
    }
  else
    {
      report_write_entry (rep, ENTRY_BLOCK_END);
    }

}

void
A4GL_pdf_pop_report_section (struct pdf_rep_structure *rep, int rb)
{
	rep->curr_rb =-1;


#ifdef DOWENEEDTHIS
  if (rep->rb_stack_level>0) {
  	rep->curr_rb = rep->rb_stack[rep->rb_stack_level-1];
  	rep->rb_stack_level--;
  } else {
	/* Lost track - set it to something .. */
	rep->curr_rb =-1;
  }
#endif


}

int
A4GL_pdf_push_report_section (struct pdf_rep_structure *rep, char *mod, char *repname, int lineno, char where, char *why, int rb)
{

#ifdef DOWENEEDTHIS
  // Maintain the report block (rb) stack - normally this is just needed for when the PAGE HEADER
  // or PAGE TRAILER triggers in the middle of print in an ON EVERY ROW or BEFORE/AFTER GROUP etc
  // Although - this is only used for CONVERTIBLE reports anyway...
  rep->rb_stack_level++;
  rep->rb_stack[rep->rb_stack_level-1]=rb;
#endif


  if (rb >= rep->nblocks)
    {
      rep->nblocks = rb + 1;
      rep->blocks = realloc (rep->blocks, sizeof (struct rb_blocks) * rep->nblocks);
      rep->blocks[rb].lineno = lineno;
      rep->blocks[rb].where = where;
      strcpy (rep->blocks[rb].why, why);
    }
  return 1;
}



int
A4GL_push_report_section (struct rep_structure *rep, char *mod, char *repname, int lineno, char where, char *why, int rb)
{

  // Maintain the report block (rb) stack - normally this is just needed for when the PAGE HEADER
  // or PAGE TRAILER triggers in the middle of print in an ON EVERY ROW or BEFORE/AFTER GROUP etc
  // Although - this is only used for CONVERTIBLE reports anyway...
  rep->rb_stack_level++;
  rep->rb_stack[rep->rb_stack_level-1]=rb;

  if (rb >= rep->nblocks)
    {
      rep->nblocks = rb + 1;
      rep->blocks = realloc (rep->blocks, sizeof (struct rb_blocks) * rep->nblocks);
      rep->blocks[rb].lineno = lineno;
      rep->blocks[rb].where = where;
      strcpy (rep->blocks[rb].why, why);
    }


  if (rep->output_mode == 'C')
    {
      print_report_block_start (rep, mod, repname, lineno, where, why, rb);
    }

  rep->curr_rb = rb;

  lvl++;
  return rb;
}


void
A4GL_pop_report_section (struct rep_structure *rep, int rb)
{
  if (rep->output_mode == 'C')
    {
      lvl--;
      print_report_block_end (rep, rb);
    }

  if (rep->rb_stack_level>0) {
  	rep->rb_stack_level--;
  } else {
	/* Lost track - set it to something .. */
	rep->curr_rb =-1;
  }


  rep->curr_rb =-1;

}



static void
print_gzlvl (struct rep_structure *rep, int lvl)
{
  int a;
  if (lvl == 0)
    return;

  for (a = 0; a < lvl; a++)
    {
      gzfprintf (rep->output, "  ");
    }
}


static void
print_data (struct rep_structure *rep, char *buff, int entry)
{
  char *s;
  char *top;
  int istop;
  top = 0;
  istop = 0;
  if (entry == -1)
    {
      return;
    }

  if (rep->top_of_page)
    {
      if (strlen (rep->top_of_page))
	{
	  top = top_of_page (rep->top_of_page, "C");
	}
    }



  s = acl_strdup (buff);
  A4GL_trim (s);

  if (top)
    {
      if (strcmp (s, top) == 0)
	{
	  istop = 1;
	}
    }

  if (A4GL_isyes (acl_getenv ("TRACE_AS_TEXT")))
    {

      if (strlen (s) && strcmp (s, "\n") != 0 && istop == 0)
	{
	  print_gzlvl (rep, lvl);
	  gzfprintf (rep->output, "<CDATA page=%d line=%d col=%d entry=%d>%s</CDATA>\n",
		     rep->page_no, rep->line_no, rep->col_no, entry, s);
	}
    }
  else
    {
      if (strlen (s) && strcmp (s, "\n") != 0 && istop == 0)
	{
	  report_write_entry (rep, ENTRY_DATA);
	  report_write_int (rep, rep->page_no);
	  report_write_int (rep, rep->line_no);
	  report_write_int (rep, rep->col_no);
	  A4GL_assertion (entry < 0, "Invalid entry");
	  report_write_int (rep, entry);
	  report_write_string (rep, s);
	}
    }
  free (s);
}


static void
report_write_int (struct rep_structure *rep, int n)
{
// Forget optimising for now...

  n = a4gl_htonl (n);
  gzfwrite (&n, sizeof (n), 1, rep->output);
}

static void
report_write_char (struct rep_structure *rep, unsigned char n)
{
  gzfwrite (&n, sizeof (n), 1, rep->output);
}

static void
report_write_string (struct rep_structure *rep, char *s)
{
  int n;
  n = strlen (s);
  report_write_int (rep, n);
  gzfwrite (s, n, 1, rep->output);
}


static void
report_write_why (struct rep_structure *rep, char where, char *why)
{
  report_write_char (rep, where);
  report_write_string (rep, why);
}



static void
report_write_entry (struct rep_structure *rep, char type)
{
  if (!A4GL_isyes (acl_getenv ("TRACE_AS_TEXT")))
    {
      report_write_char (rep, type);

      if (type == ENTRY_START)
	{
	  int version_no = 3;
	  report_write_string (rep, "LOGICAL REPORT OUTPUT");
	  report_write_int (rep, version_no);
	  report_write_int (rep, time (0));
	  report_write_int (rep, rep->top_margin);
	  report_write_int (rep, rep->bottom_margin);
	  report_write_int (rep, rep->left_margin);
	  report_write_int (rep, rep->right_margin);
	  report_write_int (rep, rep->page_length);
	  report_write_string (rep, rep->repName);
	  report_write_string (rep, rep->modName);
	}
    }
  else
    {
      if (type == ENTRY_START)
	{
	  gzfprintf (rep->output,
		     "<LAYOUT module=\"%s\" name=\"%s\" top=%d bottom=%d left=%d right=%d length=%d time=%ld />\n",
		     rep->modName, rep->repName, rep->top_margin,
		     rep->bottom_margin, rep->left_margin, rep->right_margin, rep->page_length, (long) time (0));
	}
    }
}


// Push onto the stack the current position down the page..
void
A4GL_get_current_pdf_y (struct pdf_rep_structure *rep)
{
  double d;
  d = rep->line_no;
  A4GL_push_double (d);
}

// Push onto the stack the current position across the page..
void
A4GL_get_current_pdf_x (struct pdf_rep_structure *rep)
{
  double d;
  d = rep->col_no; //  + rep->left_margin;
  A4GL_push_double (d);
}




void
A4GL_convert_report (struct rep_structure *rep, char *ofile, char *otype, char *layout, int to_pipe)
{
  char buff[1024];
  char *running_program;
  A4GL_trim (ofile);
  A4GL_trim (otype);
  A4GL_trim (layout);

  running_program = A4GL_get_running_program ();


  if (to_pipe == 1)
    {

      if (strlen (layout))
	{
	  SPRINTF6 (buff,
		    "%s/bin/process_report -M '%s' -p '%s' '%s' '%s' '%s'",
		    acl_getenv ("AUBITDIR"), running_program, ofile, otype, rep->output_loc_str, layout);
	}
      else
	{
	  SPRINTF5 (buff, "%s/bin/process_report -M '%s' -p '%s' '%s' '%s' ",
		    acl_getenv ("AUBITDIR"), running_program, ofile, otype, rep->output_loc_str);
	}
    }

  if (to_pipe == 0 || to_pipe == 2)	// File or email
    {
      if (strlen (layout))
	{
	  SPRINTF6 (buff,
		    "%s/bin/process_report -M '%s' -o '%s' '%s' '%s' '%s'",
		    acl_getenv ("AUBITDIR"), running_program, ofile, otype, rep->output_loc_str, layout);
	}
      else
	{
	  SPRINTF5 (buff, "%s/bin/process_report -M '%s' -o '%s' '%s' '%s' ",
		    acl_getenv ("AUBITDIR"), running_program, ofile, otype, rep->output_loc_str);
	}
    }

  system (buff);

  if (to_pipe == 2)
    {
      email_report (ofile, otype);
    }

  free (ofile);
  free (otype);
  free (layout);
}

void
A4GL_free_report (struct rep_structure *rep)
{
  if (rep->output_mode == 'C')
    {
      rep->output_mode = ' ';
      unlink (rep->output_loc_str);
      deleted_rep (rep->output_loc_str);
    }

  if (rep->output_mode == 'M')
    {
      //email_report(rep->output_loc_str,0);
      rep->output_mode = ' ';
    }

}


void
A4GL_set_report_dim (int with_page_length, int with_left_margin,
		     int with_right_margin, int with_top_margin, int with_bottom_margin, char *with_top_of_page)
{
  rs_with_page_length = with_page_length;
  rs_with_left_margin = with_left_margin;
  rs_with_right_margin = with_right_margin;
  rs_with_top_margin = with_top_margin;
  rs_with_bottom_margin = with_bottom_margin;
  rs_with_top_of_page = with_top_of_page;
}



int
A4GL_set_report_dim_int (char *type, int value)
{
  if (strcmp (type, "PAGE LENGTH") == 0)
    {
      if (rs_with_page_length != -1)
	return rs_with_page_length;
      return value;
    }

  if (strcmp (type, "LEFT MARGIN") == 0)
    {
      if (rs_with_left_margin != -1)
	return rs_with_left_margin;
      return value;
    }
  if (strcmp (type, "RIGHT MARGIN") == 0)
    {
      if (rs_with_right_margin != -1)
	return rs_with_right_margin;
      return value;
    }

  if (strcmp (type, "TOP MARGIN") == 0)
    {
      if (rs_with_top_margin != -1)
	return rs_with_top_margin;
      return value;
    }

  if (strcmp (type, "BOTTOM MARGIN") == 0)
    {
      if (rs_with_bottom_margin != -1)
	return rs_with_bottom_margin;
      return value;
    }
  return 0;
}


char *
A4GL_find_report_dim_string (char *type, int value)
{
// not implemented yet...
  return "";
}



static int
email_report (char *fname, char *fhint)
{
  char *email;
  if (fhint)
    {
      A4GL_push_char (fhint);
    }
  else
    {
      A4GL_push_char (" ");
    }

  A4GL_push_char (fname);

  email = acl_getenv ("EMAIL_RECIPIENT");
  if (email)
    {
      if (strlen (email) == 0)
	email = 0;
    }
  if (email == 0)
    {
      A4GL_push_user ();
    }
  else
    {
      A4GL_push_char (email);
    }

  //A4GL_push_char("mike.aubury@aubit.com"); // Normally username...
  A4GL_call_4gl_dll ("fgl_smtp", "send_report", 3);
  return 1;
}



char *
A4GL_get_tmp_rep (char *mod, char *f)
{
  static char buff[256];
  tmpnam (buff);
  return buff;
}



static char *
cursor_for_rep_tab (void *b)
{
  static char tbuff[256];
  SPRINTF1 (tbuff, "c_%lx", (unsigned long) b);
  return tbuff;
}


int
A4GL_via_functionname (char *repname, void *vr, void *vfunction)
{
  char *layout;
  char *type;
  char *filename;
  int (*repfunction) (int);
  int (*rep) (int, int);
  int n;
  int iscmd;

  rep = vr;
  repfunction = vfunction;

  // Call a 4gl report to do the real work...
  A4GL_push_char (repname);
  n = repfunction (1);		// Should return 3 values, file, type and layout...

  if (n != 4)
    {
      return 0;			// wrong number of parameters
    }

  iscmd = A4GL_pop_int ();
  layout = A4GL_char_pop ();
  type = A4GL_char_pop ();
  filename = A4GL_char_pop ();
  A4GL_trim (layout);
  A4GL_trim (type);
  A4GL_trim (filename);
  A4GL_push_int (iscmd);
  A4GL_push_char (filename);
  A4GL_push_char (type);
  A4GL_push_char (layout);

  rep (4, REPORT_CONVERT);

  return 1;
}



/**
 *
 *
 * @return
 */
int
A4GL_chk_params (struct BINDING *b, int nb, struct BINDING *o, int no)
{
  int i;
  int ca, cb;
  static char mptr[100000];


if (no) {
	A4GL_assertion(o==NULL, "No binding passed in");
}
if (nb) {
	A4GL_assertion(b==NULL, "No binding passed in");
}


  for (ca = 0; ca < no; ca++)
    {
#ifdef DEBUG
      /* {DEBUG} */ A4GL_debug ("ca=%d", ca);
#endif
      for (cb = 0; cb < nb; cb++)
	{
#ifdef DEBUG
	  /* {DEBUG} */ A4GL_debug ("   cb=%d", cb);
#endif
	  if (b[cb].ptr == o[ca].ptr)
	    {
	      int isnull1;
	      int isnull2;
	      /* check value in o.ptr against that on the stack */

	      A4GL_read_param (mptr, b[cb].dtype, b[cb].size, nb - cb);
	      isnull1 = A4GL_isnull (b[cb].dtype, b[cb].ptr);
	      isnull2 = A4GL_isnull (b[cb].dtype, mptr);

	      if (isnull1 && isnull2)
		{
		  i = 1;
		}
	      else
		{
		  A4GL_push_param (b[cb].ptr, b[cb].dtype);

#ifdef DEBUG
		  /* {DEBUG} */ A4GL_debug ("   pushing this data");
#endif
		  A4GL_push_param (mptr, b[cb].dtype);
#ifdef DEBUG
		  /* {DEBUG} */
		  A4GL_debug ("11   checking for equallity--------------------------------------------");
#endif


		  A4GL_pushop (OP_EQUAL);
		  i = A4GL_pop_bool ();

		}


#ifdef DEBUG
	      if ((b[cb].dtype & DTYPE_MASK) == DTYPE_VCHAR)
		{
		  A4GL_debug (" VARCHAR: '%s' '%s' i=%d", b[cb].ptr, mptr, i);
		}
	      /* {DEBUG} */ A4GL_debug ("   i=%d", i);
#endif
	      if (i == 0)
		{
#ifdef DEBUG
		  /* {DEBUG} */
		  A4GL_debug ("10 Param %d has changed in order by binding", ca);
#endif
		  return ca + 1;
		}
	    }
	}
    }
#ifdef DEBUG
  /* {DEBUG} */ A4GL_debug ("10 No change");
#endif
  return -1;
}

/*  Here we return the current pdf report, which is stored so that 
 *  we can call pdf_functions outside of our PDF report 
 */

void *
A4GL_get_curr_report (void)
{
  return curr_pdf_report;
}

void
A4GL_set_curr_report (void *c)
{
  curr_pdf_report = c;
}

int
A4GL_pdf_pdffunc (void *p, char *fname, int n)
{
  if (p == 0)
    {
      p = curr_pdf_report;
    }
  return A4GL_pdf_pdffunc_internal (p, fname, n);
}

int
A4GL_always_output_report (struct rep_structure *rep)
{
  int force_print;
  force_print = A4GL_isyes (acl_getenv ("ALWAYSOUTPUTREPORT"));
  if (!force_print)
    return 0;
  if (rep->line_no != 0 || rep->col_no != 0 || rep->page_no != 0)
    {
      return 0;
    }
  // Need to do something...
  A4GL_push_int (1);
  A4GL_aclfgli_skip_lines (rep);
  return 1;
}



int
A4GL_push_agg (char type, long agg_type, void *agg, long aggcnt)
{
  switch (type)
    {

    case 'A':
      A4GL_push_param (agg, agg_type);
      A4GL_push_double ((double) aggcnt);
      A4GL_pushop (OP_DIV);

      switch (agg_type & DTYPE_MASK)
	{
	case DTYPE_INT:
	  A4GL_cast_top_of_stack_to_dtype (DTYPE_DECIMAL + ENCODE_SIZE (((31 << 8) + 2)));
	  break;
	case DTYPE_SMINT:
	  A4GL_cast_top_of_stack_to_dtype (DTYPE_DECIMAL + ENCODE_SIZE (((30 << 8) + 2)));
	  break;
	case DTYPE_INTERVAL:
	  A4GL_cast_top_of_stack_to_dtype (DTYPE_INTERVAL + ENCODE_SIZE (agg_type >> 16));
	  break;
	}

      break;

    case 'S':
      if (aggcnt)
	{
	  A4GL_push_param (agg, agg_type);
	  //A4GL_cast_top_of_stack_to_dtype(DTYPE_FLOAT);
	  switch (agg_type & DTYPE_MASK)
	    {
	    case DTYPE_INT:
	      A4GL_cast_top_of_stack_to_dtype (DTYPE_DECIMAL + ENCODE_SIZE (((16 << 8) + 3)));
	      break;
	    case DTYPE_SMINT:
	      A4GL_cast_top_of_stack_to_dtype (DTYPE_DECIMAL + ENCODE_SIZE (((15 << 8) + 3)));
	      break;
	    }
	}
      else
	{
	  A4GL_push_null (1, 0);
	}
      break;


    case 'N':
      A4GL_push_param (agg, agg_type);
      break;

    case 'X':
      A4GL_push_param (agg, agg_type);
      break;

    case 'C':
      A4GL_push_long (*(long *) agg);
      A4GL_cast_top_of_stack_to_dtype (DTYPE_DECIMAL + ENCODE_SIZE (((16 << 8) + 3)));
      break;


    case 'P':
      A4GL_push_double ((double) (*(long *) agg * 100) / (double) aggcnt);
      A4GL_cast_top_of_stack_to_dtype (DTYPE_DECIMAL + ENCODE_SIZE (((35 << 8) + 2)));
      break;

    default:
      printf ("%c\n", type); // IGNORE WHEN GREPPING FOR PRINTFs
      A4GL_assertion (1, "Not implemented yet");
    }
  return 1;
}

int
A4GL_set_agg (char type, long *agg_type, void **aggptr, long *aggused)
{
  int d1;
  int s1;
  void *ptr1;
  void *agg;
  agg = *aggptr;

  A4GL_get_top_of_stack (1, &d1, &s1, (void **) &ptr1);
  if (agg == 0)
    {
      *agg_type = d1 + ENCODE_SIZE (s1);
      if (*agg_type & DTYPE_MALLOCED)
	{
	  *agg_type -= DTYPE_MALLOCED;
	}
      *aggused = 0;
      switch (d1 & DTYPE_MASK)
	{
	case DTYPE_CHAR:
	case DTYPE_VCHAR:
	  agg = malloc (s1 + 1);
	  break;

	case DTYPE_NCHAR:
	case DTYPE_NVCHAR:
	  agg = malloc ((s1*4) + 1);
	break;

	case DTYPE_SERIAL:
	case DTYPE_DATE:
	case DTYPE_INT:
	  agg = malloc (sizeof (long));
	  *(long *) agg = 0;
	  break;

	case DTYPE_SMINT:
	  agg = malloc (sizeof (short));
	  *(short *) agg = 0;
	  break;

	case DTYPE_SMFLOAT:
	  agg = malloc (sizeof (float));
	  *(float *) agg = 0.0;
	  break;

	case DTYPE_FLOAT:
	  agg = malloc (sizeof (double));
	  *(double *) agg = 0.0;
	  break;

	case DTYPE_INTERVAL:
	  {
	    struct ival *i;
	    agg = malloc (sizeof (struct ival));
	    A4GL_setnull (d1 & DTYPE_MASK, agg, s1);
	    i = (struct ival *) agg;
	    i->ltime = ((struct ival *) ptr1)->ltime;
	    i->stime = ((struct ival *) ptr1)->stime;
	  }
	  break;

	case DTYPE_MONEY:
	  if (type == 'S')
	    {
	      int ndig;
	      ndig = s1 & 0xff;
	      agg = malloc (sizeof (fglmoney));
	      A4GL_push_int (0);
	      A4GL_pop_var2 (agg, DTYPE_MONEY, 0x2000 + ndig);
	      *agg_type = DTYPE_MONEY + ENCODE_SIZE ((0x2000 + ndig));
	    }
	  else
	    {
	      agg = malloc (255);
	      memset (agg, 0, 255);
	      A4GL_setnull (d1 & DTYPE_MASK, agg, s1);
	    }
	  break;

	case DTYPE_DECIMAL:
	  if (type == 'S')
	    {
	      int ndig;
	      ndig = s1 & 0xff;
	      if (ndig > 16)
		ndig = 16;
	      agg = malloc (sizeof (fgldecimal));
	      A4GL_push_int (0);
	      A4GL_pop_var2 (agg, DTYPE_DECIMAL, 0x2000 + ndig);
	      *agg_type = DTYPE_DECIMAL + ENCODE_SIZE ((0x2000 + ndig));
	    }
	  else
	    {
	      agg = malloc (255);
	      memset (agg, 0, 255);
	      A4GL_setnull (d1 & DTYPE_MASK, agg, s1);
	    }
	  break;

	default:
	  agg = malloc (255);
	  memset (agg, 0, 255);
	  A4GL_setnull (d1 & DTYPE_MASK, agg, s1);
	  break;		/* should be enough for most */
	}
      *aggptr = agg;
    }

  switch (type)
    {
    case 'S':			/* SUM */
      if (!A4GL_isnull (d1, ptr1))
	{
	  /* We only add it on - if its not null */
	  if (*aggused == 0)
	    {

	      A4GL_push_param (ptr1, (d1 & DTYPE_MASK) + ENCODE_SIZE (s1));
	    }
	  else
	    {
	      A4GL_push_param (agg, *agg_type);
	      A4GL_push_param (ptr1, (d1 & DTYPE_MASK) + ENCODE_SIZE (s1));
	      A4GL_pushop (OP_ADD);
	    }
	  A4GL_pop_var2 (agg, (*agg_type) & DTYPE_MASK, DECODE_SIZE ((*agg_type)));
	}
      A4GL_drop_param ();
      /* But - we count it anyway */
      (*aggused)++;
      break;

    case 'A':			/* AVERAGE */

      if (!A4GL_isnull (d1, ptr1))
	{
	  if (*aggused == 0)
	    {
	      A4GL_push_param (ptr1, (d1 & DTYPE_MASK) + ENCODE_SIZE (s1));
	    }
	  else
	    {
	      A4GL_push_param (agg, *agg_type);
	      A4GL_push_param (ptr1, (d1 & DTYPE_MASK) + ENCODE_SIZE (s1));
	      A4GL_pushop (OP_ADD);
	    }
	  A4GL_pop_var2 (agg, d1, s1);
	  (*aggused)++;
	}
      A4GL_drop_param ();
      break;

    case 'N':			/* MIN */
      if (!A4GL_isnull (d1, ptr1))
	{
	  // Have we got any value set yet ? 
	  if (*aggused == 0)
	    {
	      /* Nope - so this must be the minimum ! */
	      (*aggused)++;
	      A4GL_push_long (1);
	    }
	  else
	    {
	      /* Yes - check see if we're less */
	      A4GL_push_param (ptr1, (d1 & DTYPE_MASK) + ENCODE_SIZE (s1));
	      A4GL_push_param (agg, (d1 & DTYPE_MASK) + ENCODE_SIZE (s1));
	      A4GL_pushop (OP_LESS_THAN);
	    }

	  if (A4GL_pop_bool ())
	    {
	      A4GL_push_param (ptr1, (d1 & DTYPE_MASK) + ENCODE_SIZE (s1));
	      A4GL_pop_var2 (agg, (d1 & DTYPE_MASK), s1);
	    }
	}
      A4GL_drop_param ();
      break;
    case 'X':			/* MAX */
      if (!A4GL_isnull (d1, ptr1))
	{
	  // Have we got any value set yet ? 
	  if (*aggused == 0)
	    {
	      /* Nope - so this must be the maximum ! */
	      (*aggused)++;
	      A4GL_push_long (1);
	    }
	  else
	    {
	      /* Yes - check see if we're more */
	      A4GL_push_param (ptr1, (d1 & DTYPE_MASK) + ENCODE_SIZE (s1));
	      A4GL_push_param (agg, (d1 & DTYPE_MASK) + ENCODE_SIZE (s1));
	      A4GL_pushop (OP_GREATER_THAN);
	    }

	  if (A4GL_pop_bool ())
	    {
	      A4GL_push_param (ptr1, (d1 & DTYPE_MASK) + ENCODE_SIZE (s1));
	      A4GL_pop_var2 (agg, (d1 & DTYPE_MASK), s1);
	    }
	}
      A4GL_drop_param ();
      break;



    default:
      A4GL_assertion (1, "Not implemented yet");
      break;
    }

  return 1;
}

int
A4GL_init_agg (void **aggptr, int type)
{
  void *agg;
  agg = *aggptr;

  if (agg)
    {
      free (agg);
      agg = 0;
      *aggptr = 0;
    }

  return 1;
}

int
aclfgl_aclfgl_set_pdf_encoding (int n)
{
  char *p;
  p = A4GL_char_pop ();
  strcpy (pdf_encoding, p);
  free (p);
  return 0;
}


int
aclfgl_aclfgl_get_pdf_encoding (int n)
{
  A4GL_push_char (pdf_encoding);
  return 1;
}

char *
A4GL_get_pdf_encoding (void)
{
  return pdf_encoding;
}


int A4GL_rep_is_stdout ( struct rep_structure *rep) {

if (rep->output_mode=='F') {
	if (strcmp(rep->output_loc_str,"stdout")==0) {
		return 1;
	}
}
return 0;
}


void A4GL_ensure_let_column(void) {
int len;
char *p;
char *buff;
int spaces;
int sp;
// something is on the stack - and we need to make sure its long
// enough..
len=A4GL_pop_int();
p=A4GL_char_pop();
sp=strlen(p)+1;
if (sp>=len) {
	A4GL_push_char(p);
	A4GL_push_empty_char();
	free(p);
	return;
}
spaces=len-sp;
buff=malloc(spaces+1);
memset(buff,' ',spaces);
buff[spaces]=0;
A4GL_push_char(p);
A4GL_push_char(buff);
free(buff);
free(p);
}


static char *convTagExpr(char t, char *s) {
char lbuff[200];
static char lbuff_e[200];
static char lbuff_s[200];
int a;
int b=0;
int sl;
sl=strlen(s);
for (a=0;a<sl;a++) {
	if (s[a]=='^') {
		a++;
		lbuff[b++]=a4gl_tolower(s[a])-'a'+1;
		continue;
	}
	lbuff[b++]=s[a];
}
lbuff[b]=0;
if (t=='s') {
	strcpy(lbuff_s,s);
	return lbuff_s;
}
if (t=='e') {
	strcpy(lbuff_e,s);
	return lbuff_e;
}
A4GL_assertion(1,"Unhandled tag..");
return "";
}

// Read the start and end tags 
// from a file for report generation
static char *get_tag(char *convFile, char t, char *s) {
FILE *cfile;
char ebuff[200];
#ifdef DEBUG
A4GL_debug("Get tag : %s\n",s);
#endif
//
//      bold=101
//      /bold=101
cfile=fopen(convFile,"r");
if (cfile==NULL) return "";

if (t=='e') {
	if (s[0]=='<') {
		sprintf(ebuff,"</%s",&s[1]);
	} else {
		sprintf(ebuff,"/%s",s);
	}
} else {
	sprintf(ebuff,"%s",s);
}

while (1) {
	char *ptr;
	char buff[300];
	int sl;
	if (feof(cfile)) break;
	strcpy(buff,"");
	fgets(buff,256,cfile);
	sl=strlen(buff);
	if (sl) {
		if (buff[sl-1]=='\n') {buff[sl-1]=0; sl--;}
		if (buff[sl-1]=='\r') {buff[sl-1]=0; sl--;}
	}
	ptr=strchr(buff,'=');
	if (ptr==0) continue;
	*ptr=0;
	ptr++;
	if (A4GL_aubit_strcasecmp(buff,ebuff)==0) {
		char *ptr2;
		fclose(cfile);
		ptr2= convTagExpr(t, ptr);
#ifdef DEBUG
		A4GL_debug("Got : %s\n",ptr2);
#endif
		return ptr2;
	}
	
}
		fclose(cfile);

return "";
}


char *A4GL_get_start_tag(char *tag_type) {
char buff_tag[200];
char *rval;
char *convFile;
	convFile=acl_getenv("A4GL_TAGCONVFILE");
	sprintf(buff_tag,"TAG_%s_S%s",convFile,tag_type);
	if (A4GL_has_pointer(buff_tag, REPORT_TAG)) {
		return A4GL_find_pointer(buff_tag,REPORT_TAG);
	}
	rval=get_tag(convFile, 's',tag_type);
	A4GL_add_pointer(buff_tag,REPORT_TAG,strdup(rval));
	return rval;

}

char *A4GL_get_end_tag(char *tag_type) {
char buff_tag[200];
char *convFile;
char *rval;
	convFile=acl_getenv("A4GL_TAGCONVFILE");
	sprintf(buff_tag,"TAG_%s_E%s",convFile,tag_type);

	if (A4GL_has_pointer(buff_tag, REPORT_TAG)) {
		return A4GL_find_pointer(buff_tag,REPORT_TAG);
	}
	rval=get_tag(convFile, 'e',tag_type);
	A4GL_add_pointer(buff_tag,REPORT_TAG,strdup(rval));
	return rval;
}




char *A4GL_check_for_tags(char *s) {
	static char tagline[10024];
	char *p;

	strcpy(tagline,s);
        p=strstr(tagline,"##TAG(");

        if (p) {
                char *comma;
                char buff[20000];
                comma=strrchr(tagline,',');
                if (comma==NULL) return s;
                *comma=0;
                comma++;
                p=strstr(comma,")##");
                if (p==NULL) return s;
                *p=0;
                sprintf(buff,"%s",&tagline[6]);
                sprintf(tagline,"%s%s%s",A4GL_get_start_tag(comma),buff,A4GL_get_end_tag(comma));
                //strcpy(tagline,buff);
                return tagline;
        }
	return s;
}




/*
DO NOT REMOVE THESE COMMENTS -  this sets up the error codes for some reporting functions
There is a script which looks for a4gl_exitwith's in the code - and adds them to our error numbers

A4GL_exitwith("A report cannot accept data as it has not been started");
A4GL_exitwith("You cannot FINISH REPORT - because the report has not been started");
*/



/* ============================= EOF ================================ */
