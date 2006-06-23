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
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: report.c,v 1.85 2006-06-23 14:08:44 mikeaubury Exp $
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
//struct s_sid * A4GLSQL_prepare_select (struct BINDING *ibind, int ni, struct BINDING *obind, int no, char *s);
//int A4GL_call_4gl_dll (char *filename, char *function, int args);
static void A4GL_unload_report_table (struct BINDING *b);

#define ENTRY_START 1
#define ENTRY_BLOCK 2
#define ENTRY_BLOCK_END 3
#define ENTRY_DATA 4
#define ENTRY_ENTRY_START 5
#define ENTRY_ENTRY_END 6


static int email_report (char *fname, char *otype);
static void free_header (struct rep_structure *rep);
static char *cursor_for_rep_tab (void *b);



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
  char *s;
};

struct s_save_header
{
  struct s_save_header_entry *save;
  int save_cnt;
};

static void report_write_entry (struct rep_structure *rep, char type);
static void print_lvl (struct rep_structure *rep, int lvl);
static void print_data (struct rep_structure *rep, char *buff, int entry);
int A4GL_push_report_print (struct rep_structure *rep, char *mod, int lineno,
			    char where, char *why, int rb);
void A4GL_pop_report_print (struct rep_structure *rep, int pb, int rb);
void A4GL_pop_report_section (struct rep_structure *rep, int rb);
static void report_write_string (struct rep_structure *rep, char *s);
static void report_write_int (struct rep_structure *rep, int n);
static void report_write_char (struct rep_structure *rep, unsigned char n);
static void report_write_why (struct rep_structure *rep, char where,
			      char *why);

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
int A4GL_push_report_section (struct rep_structure *rep, char *mod,
			      char *repname, int lineno, char where,
			      char *why, int rb);

void A4GL_rep_print (struct rep_structure *rep, int no_param, int want_nl, int right_margin, int entry);
void A4GL_need_lines (struct rep_structure *rep);
void A4GL_add_spaces (void);
static char *A4GL_mk_temp_tab (struct BINDING *b, int n);
void A4GL_make_report_table (struct BINDING *b, int n);
void A4GL_add_row_report_table (struct BINDING *b, int n);
int A4GL_init_report_table (struct BINDING *b, int n, struct BINDING *o,
			    int no, struct BINDING **reread);
int A4GL_report_table_fetch (struct BINDING *reread, int n,
			     struct BINDING *b);
void A4GL_end_report_table (struct BINDING *b, int n, struct BINDING *reread);
void A4GL_rep_file_print (struct rep_structure *rep, char *fname,
			  int opt_semi);
static char *A4GL_report_char_pop (void);


char *A4GL_decode_datatype (int dtype, int dim);
extern sqlca_struct a4gl_sqlca;
void A4GL_finished_report (void);
static void add_header_entry (struct rep_structure *rep,
			      struct s_save_header *hdr, char *buff,
			      int entry);


int lvl = 0;

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


static char *top_of_page(char *s,char *why) {
int n;
static char *b=0; // Keep it hanging around....
	n=strlen(s)+1;
	if (n<20) n=20;
	if (b!=0) free(b);
	b=malloc(n);
	strcpy(b,s);
	A4GL_trim(b);
	if (A4GL_aubit_strcasecmp(b,"^L")==0) { // OK - we had 3 characters alloc'd
			b[0]=12;		// we're going to use just 2...
			b[1]=0;
	}
	return b;
}




void
add_header_entry (struct rep_structure *rep, struct s_save_header *hdr,
		  char *buff, int entry)
{
  char *n;
  char *top;
  int istop;
  top=0;
  istop=0;

  if (rep->top_of_page) {
	if (strlen(rep->top_of_page)) {
  		top=top_of_page(rep->top_of_page,"C");
	}
  }



  if (strlen (buff))
    {
      n = acl_strdup (buff);
      A4GL_trim (n);
      if (top) {
	      if (strcmp(n,top)==0) {
		      istop=1;
	      }
      }
      if (strlen (n) && strcmp (n, "\n") != 0 && istop==0)
	{
	  hdr->save_cnt++;
	  hdr->save =
	    realloc (hdr->save,
		     sizeof (struct s_save_header_entry) * hdr->save_cnt);
	  hdr->save[hdr->save_cnt - 1].page_no = rep->page_no;
	  hdr->save[hdr->save_cnt - 1].line_no = rep->line_no;
	  hdr->save[hdr->save_cnt - 1].col_no = rep->col_no;
	  hdr->save[hdr->save_cnt - 1].entry = entry;
	  hdr->save[hdr->save_cnt - 1].s = acl_strdup (buff);
	  A4GL_debug ("Add header entry : %d %d %d %d %s\n", rep->page_no, rep->line_no, rep->col_no, entry, buff);
	  if (rep->col_no==0&&entry==0) A4GL_pause_execution();
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

// Save these away - we'll need to change them...

  p = rep->page_no;
  l = rep->line_no;
  c = rep->col_no;
  if (rep->header)
    {
      hdr = (struct s_save_header *) rep->header;
      for (a = 0; a < hdr->save_cnt; a++)
	{
	  rep->page_no = hdr->save[a].page_no;
	  rep->line_no = hdr->save[a].line_no;
	  rep->col_no = hdr->save[a].col_no;
	  print_data (rep, hdr->save[a].s, hdr->save[a].entry);
	  A4GL_debug ("PRINING         : %d %d %d %d %s\n", rep->page_no,
		      rep->line_no, rep->col_no, hdr->save[a].entry,
		      hdr->save[a].s);
	  free (hdr->save[a].s);
	}


      rep->page_no = p;
      rep->line_no = l;
      rep->col_no = c;
      free (hdr->save);
      free (hdr);
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
      A4GL_assertion (rep->output == 0,
		      "Report outfile file closed prematurely ?");
    }
  va_start (ap, fmt);

  if (entry <= 0)
    entry = 0;
  VSPRINTF (buff, fmt, ap);
  A4GL_debug ("'%s' - %d\n", buff, entry);
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
	      FPRINTF (rep->output, "%s", rep->header);
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
	  FPRINTF (rep->output, "%s", buff);
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
	      FPRINTF (rep->output, "%s", buff);
	    }

	}
    }

  if (rep->print_section == SECTION_HEADER)
    {
      if (rep->output_mode == 'C')
	{
	  if (rep->header)
	    {
	      add_header_entry (rep, (struct s_save_header *) rep->header,
				buff, entry);
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
	      rep->header = realloc (rep->header, a + strlen (buff) + 2);
	      rep->header[a] = 0;
	      strcat (rep->header, buff);
	    }
	  else
	    {
	      rep->header = acl_strdup (buff);
	    }


	}
    }




}


/**
 *
 * @todo Describe function
 */
static char *
gen_rep_tab_name (void *p)
{
  int a;
  static char buff_0[256];
  a = (int) p;
  //a=1;
  SPRINTF1 (buff_0, "rtab%x", ((int) a) & 0xfffffff);
  return buff_0;
}



void A4GL_internal_open_report_file(struct rep_structure *rep,int no_param) {

  if (rep->line_no == 0 && rep->page_no == 0 && no_param < 0)
    {

      if (rep->output_mode == 'C')
	{
	  tmpnam (rep->output_loc);
	  rep->output = fopen (rep->output_loc, "w");
	  if (rep->output == 0)
	    {
	      A4GL_exitwith ("Could not open report output");
	      return;
	    }

	}
      else
	{

	  if (rep->output_mode == 'F' || rep->output_mode == 'M')
	    {


	      if (strcmp (rep->output_loc, "stdout") == 0)
		{
		  A4GL_gotolinemode ();
		  rep->output = stdout;
		  A4GL_gotolinemode ();
		}
	      else
		{
		  rep->output = A4GL_mja_fopen (rep->output_loc, "w");
		  if (rep->output == 0)
		    {
		      A4GL_exitwith ("Could not open report output");
		      return;
		    }
		}


	    }
	  else
	    {
	      A4GL_debug ("popen '%s'", rep->output_loc);
	      rep->output = popen (rep->output_loc, "w");
	      if (rep->output == 0)
		{
		  A4GL_exitwith ("Could not open report output");
		  return;
		}
	    }

	}


      if (rep->output_mode == 'C')
	{
	  report_write_entry (rep, ENTRY_START);
	}

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
A4GL_rep_print (struct rep_structure *rep, int no_param, int want_nl, int right_margin,
		int entry)
{
  int b;
  int cnt;
  char *str;
  A4GL_debug
    ("In A4GL_rep_print rep=%p rep->report=%p Page=%d Line=%d Col=%d entry=%d", rep, rep->report, rep->page_no, rep->line_no, rep->col_no, entry);

  if (right_margin != 0)
    {
      A4GL_debug ("***** WARNING ***** wordwrap margin not implemented..");
    }


  if (rep->line_no == 0 && rep->page_no == 0 && no_param < 0) {
  	A4GL_internal_open_report_file(rep,no_param) ;
  }

  if (rep->finishing && entry==-5 && no_param==0 && strlen(rep->top_of_page)) {
	  		// Reports finishing - lets get to the end of our page ...
			  report_print (rep, -1, top_of_page(rep->top_of_page,"A"));
			  return;
  }

  if (no_param < 0)
    {				// We're just setting up...
      return;
    }


  if (no_param || want_nl == 0 || rep->finishing || entry == -5)
    {
      if (rep->print_section == SECTION_NORMAL)
	{
	  if (rep->line_no >
	      rep->page_length - rep->lines_in_trailer - rep->bottom_margin)
	    {
	      rep->print_section = SECTION_TRAILER;
	      rep->report (0, REPORT_PAGETRAILER);	/* report.c:180: too many arguments to function */
	      rep->print_section = SECTION_NORMAL;
	    }

	  if (rep->line_no > rep->page_length - rep->bottom_margin)
	    {
		    if (strlen(rep->top_of_page)==0) {
	      		for (cnt = 0; cnt < rep->bottom_margin; cnt++) {
			  report_print (rep, -1, "\n");
			  rep->line_no++;
			}
		    } else {
			  report_print (rep, -1, top_of_page(rep->top_of_page,"B"));
		    }

	      rep->line_no = 0;

	      if (rep->lines_in_trailer)
		{
		  A4GL_debug ("Calling rep_print");
		  A4GL_rep_print (rep, 0, 1, 0, -10);
		}
	    }
	}
    }




  if (rep->line_no == 0 && !rep->finishing)
    {
      rep->line_no = 1;
      rep->page_no++;
      rep->print_section = SECTION_HEADER;
      A4GL_debug ("Need page header ?");

      if (rep->top_margin)
	{
	  A4GL_debug ("Skip lines...");
	  A4GL_push_int (rep->top_margin);
	  A4GL_aclfgli_skip_lines (rep);
	  A4GL_debug ("Done skip lines");
	}

      if (rep->report == 0)
	{
	  A4GL_debug ("OOPS - no report function!!!");
	  A4GL_assertion (1,"Internal error - no report function");
	  A4GL_fgl_die (10);
	}
      rep->report (0, REPORT_PAGEHEADER);	/* report.c:180: too many arguments to function */
      rep->print_section = 0;
      A4GL_debug ("Done page header");
    }

  A4GL_debug ("Popping %d parameters", no_param);




  if (no_param > 0)
    {
      if (rep->col_no == 0)
	{
	  rep->col_no = 1;
	  A4GL_fputmanyc (rep, ' ', rep->left_margin);
	}
      for (b = 0; b < no_param; b++)
	{
	  str = A4GL_report_char_pop ();
	  A4GL_debug ("Popped '%s'...", str);
	  report_print (rep, entry, "%s", str);
	  rep->col_no += strlen (str);
	  A4GL_debug ("Popped %s\n", str);
	  acl_free (str);
	}
    }
  A4GL_debug ("Newline : %d", want_nl);




  if (want_nl == 0)
    {
      rep->col_no = 0;
      report_print (rep, -1, "\n");
      rep->line_no++;
    }
  return;
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
  free(x);
  //for (a = 0; a < cnt; a++) fputc (c, f);
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
  A4GL_push_char ("");
  A4GL_debug ("Calling rep_print");
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
    A4GL_debug ("Current pos=%d need position %d left_margin=%d", rep->col_no,
		a, rep->left_margin);
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
  A4GL_push_char ("");
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
  a = A4GL_pop_long ();
  for (b = 0; b < a; b++)
    {
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
  if (rep->line_no - 1 >
      (rep->page_length - rep->bottom_margin - a - rep->lines_in_trailer))
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
  a =
    rep->page_length - rep->line_no - rep->bottom_margin -
    rep->lines_in_trailer + 1;

  if (n != 1 || rep->page_no)
    {
      if (rep->header)
	return;
      if (rep->line_no == 0)
	return;
    }

  if (a || n == 999)
    {
	if (strlen(rep->top_of_page)==0) {
      		for (z = 0; z < a; z++) {
	  		A4GL_rep_print (rep, 0, 0, 0, -4);
		}
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
  int a;
  char str[1000];
  a = A4GL_pop_int ();
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
  switch (n & 15)
    {
    case 0:
      return "CHAR";
    case 1:
      return "SMALLINT";
    case 2:
      return "INTEGER";
    case 3:
      return "FLOAT";
    case 4:
      return "SMALLFLOAT";
    case 5:
      return "DECIMAL";
    case 6:
      return "INTEGER";
    case 7:
      return "DATE";
    case 8:
      return "MONEY";
    case 10:
      return "DATETIME ";
    case 11:
      return "BYTE";
    case 12:
      return "TEXT";
    case 13:
      return "VARCHAR";
    case 14:
      return "INTERVAL ";
    }
  return "CHAR";
}

/**
 *
 * @todo Describe function
 */
static char *
sz (int d, int s)
{
  static char buff_1[256];
  switch (d & 15)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 7:
    case 6:
    case 11:
    case 12:
      return "";

    case 10:
      return " YEAR TO FRACTION(5)";

    case 8:
    case 5:			/* decimal */
      return "(32,16)";

    case 0:
    case 13:
      SPRINTF1 (buff_1, "(%d)", s);
      return buff_1;

    case 14:
      SPRINTF0 (buff_1, " year to second(5)");
      return buff_1;
    }
  return "";
}


/**
 * Used for AREP compiler 
 * @todo Describe function
 */
char *
A4GL_decode_datatype (int dtype, int dim)
{
  static char buff_2[256];
  char *s;
  SPRINTF2 (buff_2, "%s %s", nm (dtype), sz (dtype, dim));
  //s=A4GLSQLCV_dtype_alias(buff_2);
  return buff_2;
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


  SPRINTF1 (buff_3, "create temp table %s (\n", gen_rep_tab_name (b));

  for (a = 0; a < n; a++)
    {
      if (a)
	strcat (buff_3, ",\n");
      SPRINTF3 (tmpbuff, "c%d %s %s", a, nm (b[a].dtype),
	       sz (b[a].dtype, b[a].size));
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
  A4GLSQL_execute_implicit_sql (A4GLSQL_prepare_select (0,0,0,0,A4GL_mk_temp_tab (b, n),"__internal_report",99),
				1);
}



static void
A4GL_unload_report_table (struct BINDING *b)
{
  char buff[1024];
  struct BINDING *ibind = 0;
  return;
  SPRINTF1 (buff, "SELECT * FROM %s", gen_rep_tab_name (b));
  A4GLSQL_unload_data ("zz9pa", "|", buff, 0, ibind);
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
  A4GL_debug ("Add row report table");
  SPRINTF1 (buff, "INSERT INTO %s VALUES (", gen_rep_tab_name (b));

  for (a = 0; a < n; a++)
    {
      if (a)
	strcat (buff, ",");
      strcat (buff, "?");
    }
  strcat (buff, ")");
  A4GL_debug ("Attempting to execute %s\n", buff);
  x = (void *) A4GLSQL_prepare_select (b, n, 0, 0, buff,"__internal_report",1);
  A4GL_debug ("x=%p\n", x);
  A4GLSQL_execute_implicit_sql (x, 1);
  A4GL_debug ("a4glsqlca.sqlcode=%d", a4gl_sqlca.sqlcode);
}

/**
 *
 * @todo Describe function
 */
int
A4GL_init_report_table (struct BINDING *b, int n, struct BINDING *o, int no,
			struct BINDING **reread)
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
    {0, 0, 0,0,0,0}
  };				/* end of binding */
  struct BINDING obind[] = {
    {0, 0, 0,0,0,0}
  };				/* end of binding */

  A4GL_debug ("init_rep_table");
  *reread = A4GL_duplicate_binding (b, n);


  SPRINTF1 (buff, "select * from %s order by ", gen_rep_tab_name (b));

  A4GL_unload_report_table (b);	// This is useful for debugging....

  for (a1 = 0; a1 < no; a1++)
    {
      ok = 0;
      A4GL_debug ("Looking for %p", o[a1]);

      if (a1)
	strcat (buff, ",");
      for (a2 = 0; a2 < n; a2++)
	{
	  A4GL_debug ("Checking %p %p", o[a1].ptr, b[a2].ptr);

	  if (o[a1].ptr == b[a2].ptr)
	    {
	      SPRINTF1 (obuff, "c%d", a2);
	      strcat (buff, obuff);
	      ok = 1;
	      break;
	    }
	}
      if (ok == 0)
	{
	  A4GL_debug ("Can't A4GL_match column in orderby....");
	  A4GL_exitwith ("Big Oops");
	  return 0;
	}
    }


  A4GL_debug ("Got select statement as : %s\n", buff);





  A4GL_debug ("prepare...");
  pstmt = A4GLSQL_prepare_select (ibind, 0, obind, 0, buff,"__internal_report",2);
  A4GL_debug ("%d\n", a4gl_sqlca.sqlcode);
  if (a4gl_sqlca.sqlcode != 0)
    {
      A4GL_debug ("prepare failed");
      A4GL_exitwith ("Internal error - unable to prepare statement");
      return 0;
    }
  A4GL_debug ("declare...");
  A4GLSQL_declare_cursor (0, pstmt, 0, cursor_for_rep_tab (b));
  A4GL_debug ("%d\n", a4gl_sqlca.sqlcode);
  if (a4gl_sqlca.sqlcode != 0)
    {
      A4GL_debug ("declare failed");
      A4GL_exitwith ("Internal error - unable to declare statement");
      return 0;
    }


  A4GLSQL_open_cursor (cursor_for_rep_tab (b), 0, 0);
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

  A4GLSQL_fetch_cursor (cursor_for_rep_tab (b), 2, 1, n, reread);
  A4GL_push_params (reread, n);

  if (a4gl_sqlca.sqlcode == 0)
    return 1;
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
  A4GL_free_duplicate_binding (reread, n);
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
  A4GL_debug ("Duplicating bindings....");
  rbind = acl_malloc2 (sizeof (struct BINDING) * n);
  for (a = 0; a < n; a++)
    {
      sz = 0;
      switch (b[a].dtype)
	{
	case 0:
	  sz = b[a].size + 1;
	  break;

	case 1:
	case 2:
	case 6:
	case 7:
	case 4:
	  sz = 4;
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
	case 13:
	  sz = 256;
	  break;
	case 3:
	  sz = 8;
	  break;
	}

      A4GL_debug ("allocing %d bytes\n", sz);
      rbind[a].ptr = acl_malloc2 (sz);
      A4GL_debug ("allocated as %p", rbind[a].ptr);

      rbind[a].dtype = b[a].dtype;
      rbind[a].size = b[a].size;
      rbind[a].libptr = 0;
    }

  A4GL_debug ("All done");
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
  A4GL_debug ("Freeing duplicate..");
  for (a = 0; a < n; a++)
    {
      A4GL_debug ("Freeing %p", b[a].ptr);
      free (b[a].ptr);
    }
  A4GL_debug ("Freeing structure %p", b);
  free (b);
}


/**
 *
 * @todo Describe function
 */
void
A4GL_rep_file_print (struct rep_structure *rep, char *fname, int opt_semi)
{
  FILE *f;
  char buff[10000];
  int has_cr;
  f = fopen (fname, "r");
  if (f == 0)
    {
      A4GL_exitwith ("Unable to open PRINT FILE file");
      return;
    }
  while (!feof (f))
    {
      char *a;
      a = fgets (buff, sizeof (buff) - 1, f);
      if (!a)
	break;
      has_cr = 0;
      // Trim any trailing \n
      while (buff[strlen (buff) - 1] == '\n'
	     || buff[strlen (buff) - 1] == '\r')
	{
	  int c;
	  has_cr++;
	  c = strlen (buff);
	  buff[c - 1] = 0;
	}
      A4GL_push_char (buff);
      if (has_cr)
	A4GL_rep_print (rep, 1, 0, 0, -1);
      else
	A4GL_rep_print (rep, 1, 1, 0, -1);
    }
}


/**
 * Report pause function
 * 
**/
void
A4GL_pause (char *s)
{
  A4GL_push_char (s);
  A4GL_push_int (-1);
  A4GL_push_int (-1);
  A4GL_display_at (1, 0);
  getchar ();			// Not the best idea in the world....
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
  A4GL_assertion (function == 0,
		  "No report display function for this datatype");
  ptr =
    function (tos_ptr, tos_size, -1, (struct struct_scr_field *) 0,
	      DISPLAY_TYPE_PRINT);
  if (ptr != 0)
    {
      ptr = acl_strdup (ptr);
      A4GL_drop_param ();
    }
  else
    {
      ptr = A4GL_char_pop ();
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
print_report_block_start (struct rep_structure *rep, char *mod, char *repname,
			  int lineno, char where, char *why, int rb)
{
  if (A4GL_isyes (acl_getenv ("TRACE_AS_TEXT")))
    {
      print_lvl (rep, lvl);
      FPRINTF (rep->output,
	       "<ACL_ENTRY_BLOCK line=%d where=%c why=\"%s\" block=%d>\n",
	       lineno, where, why, rb);
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
      print_lvl (rep, lvl);
      FPRINTF (rep->output, "</ACL_ENTRY_BLOCK block=%d>\n", rb);
    }
  else
    {
      report_write_entry (rep, ENTRY_BLOCK_END);
      //report_write_int(rep,rb);
    }

}


int
A4GL_push_report_section (struct rep_structure *rep, char *mod, char *repname,
			  int lineno, char where, char *why, int rb)
{
  if (rep->output_mode == 'C')
    {
      print_report_block_start (rep, mod, repname, lineno, where, why, rb);
    }
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
}



static void
print_lvl (struct rep_structure *rep, int lvl)
{
  int a;
  if (lvl == 0)
    return;

  for (a = 0; a < lvl; a++)
    {
      FPRINTF (rep->output, "  ");
    }
}


static void
print_data (struct rep_structure *rep, char *buff, int entry)
{
  char *s;
  char *top;
  int istop;
  top=0;
  istop=0;
  if (entry == -1) { return; }

  if (rep->top_of_page) {
	if (strlen(rep->top_of_page)) {
  		top=top_of_page(rep->top_of_page,"C");
	}
  }



  s = acl_strdup (buff);
  A4GL_trim (s);

      if (top) {
	      if (strcmp(s,top)==0) {
		      istop=1;
	      }
      }

  if (A4GL_isyes (acl_getenv ("TRACE_AS_TEXT")))
    {

      if (strlen (s) && strcmp (s, "\n") != 0 && istop==0)
	{
	  print_lvl (rep, lvl);
	  FPRINTF (rep->output, "<CDATA page=%d line=%d col=%d entry=%d>%s</CDATA>\n",
		   rep->page_no, rep->line_no, rep->col_no, entry, s);
	}
    }
  else
    {
      if (strlen (s) && strcmp (s, "\n") != 0 && istop==0)
	{
	  report_write_entry (rep, ENTRY_DATA);
	  report_write_int (rep, rep->page_no);
	  report_write_int (rep, rep->line_no);
	  report_write_int (rep, rep->col_no);
	  report_write_int (rep, entry);
	  report_write_string (rep, s);
	}
    }
  free (s);
}


static void
report_write_int (struct rep_structure *rep, int n)
{
//unsigned char c;

// Forget optimising for now...
/*
	if (n<254) {
		report_write_char(rep,n);
		return;
	} 

	if (n<32000) {
		s=a4gl_htons(n);
		report_write_char(rep,254);
		fwrite(&s,sizeof(s),1,rep->output);
	}

	report_write_char(rep,255);
*/

  n = a4gl_htonl (n);
  fwrite (&n, sizeof (n), 1, rep->output);
}

static void
report_write_char (struct rep_structure *rep, unsigned char n)
{
  fwrite (&n, sizeof (n), 1, rep->output);
}

static void
report_write_string (struct rep_structure *rep, char *s)
{
  int n;
  n = strlen (s);
  report_write_int (rep, n);
  fwrite (s, n, 1, rep->output);
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
	  report_write_string(rep,"LOGICAL REPORT OUTPUT");
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
	  FPRINTF (rep->output,
		   "<LAYOUT module=\"%s\" name=\"%s\" top=%d bottom=%d left=%d right=%d length=%d time=%ld />\n",
		   rep->modName, rep->repName, rep->top_margin,
		   rep->bottom_margin, rep->left_margin, rep->right_margin,
		   rep->page_length, (long) time (0));
	}
    }
}






void
A4GL_convert_report (struct rep_structure *rep, char *ofile,
		     char *otype, char *layout, int to_pipe)
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
		   acl_getenv ("AUBITDIR"), running_program, ofile, otype,
		   rep->output_loc, layout);
	}
      else
	{
	  SPRINTF5 (buff, "%s/bin/process_report -M '%s' -p '%s' '%s' '%s' ",
		   acl_getenv ("AUBITDIR"), running_program, ofile, otype,
		   rep->output_loc);
	}
    }

  if (to_pipe == 0 || to_pipe == 2)	// File or email
    {
      if (strlen (layout))
	{
	  SPRINTF6 (buff,
		   "%s/bin/process_report -M '%s' -o '%s' '%s' '%s' '%s'",
		   acl_getenv ("AUBITDIR"), running_program, ofile, otype,
		   rep->output_loc, layout);
	}
      else
	{
	  SPRINTF5 (buff, "%s/bin/process_report -M '%s' -o '%s' '%s' '%s' ",
		   acl_getenv ("AUBITDIR"), running_program, ofile, otype,
		   rep->output_loc);
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
      //unlink(rep->output_loc);
    }

  if (rep->output_mode == 'M')
    {
      //email_report(rep->output_loc,0);
      unlink (rep->output_loc);
      rep->output_mode = ' ';
    }

}


void
A4GL_set_report_dim (int with_page_length, int with_left_margin,
		     int with_right_margin, int with_top_margin,
		     int with_bottom_margin, char *with_top_of_page)
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
  SPRINTF1 (tbuff, "c_%lx", (unsigned long)b);
  return tbuff;
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
  char *mptr[2048];


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
#ifdef DEBUG
              /* {DEBUG} */ A4GL_debug ("11   pointers %d %d are equal", cb, ca);
#endif
              /* check value in o.ptr against that on the stack */
#ifdef DEBUG
              /* {DEBUG} */ A4GL_debug ("11 nb=%d cb=%d ca=%d\n", nb, cb, ca);
#endif
              A4GL_read_param (mptr, b[cb].dtype, b[cb].size, nb - cb);
              A4GL_push_param (b[cb].ptr, b[cb].dtype);
#ifdef DEBUG
              /* {DEBUG} */ A4GL_debug ("   pushing this data");
#endif
              A4GL_push_param (mptr, b[cb].dtype);
#ifdef DEBUG
              /* {DEBUG} */
              A4GL_debug
                ("11   checking for equallity--------------------------------------------");
#endif
              A4GL_pushop (OP_EQUAL);
              i = A4GL_pop_bool ();
#ifdef DEBUG
              if ((b[cb].dtype & DTYPE_MASK)==DTYPE_VCHAR ) {
                        A4GL_debug(" VARCHAR: '%s' '%s' i=%d",b[cb].ptr,mptr,i);
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


/* ============================= EOF ================================ */
