/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-1 Aubit Development Team (See Credits file)       |
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
# $Id: report.c,v 1.41 2004-04-21 14:47:01 mikeaubury Exp $
#
*/


/**
 * @file
 * Execute report (text mode) implementation
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen A4GL_comments to add to functions
 */

 /*
    =====================================================================
    Includes
    =====================================================================
  */

#include "a4gl_libaubit4gl_int.h"

#define ENTRY_START 1
#define ENTRY_BLOCK 2
#define ENTRY_BLOCK_END 3
#define ENTRY_DATA 4
#define ENTRY_ENTRY_START 5
#define ENTRY_ENTRY_END 6
static void report_write_entry(struct rep_structure *rep,char type) ;
static void print_lvl(struct rep_structure *rep,int lvl) ;
static void print_data(struct rep_structure *rep,char *buff,int entry) ;
int A4GL_push_report_print(struct rep_structure *rep,char *mod,int lineno,char where,char *why,int rb) ;
void A4GL_pop_report_print(struct rep_structure *rep,int pb, int rb) ;
void A4GL_pop_report_section(struct rep_structure *rep, int rb) ;
static void report_write_string(struct rep_structure *rep, char *s) ;
static void report_write_int(struct rep_structure *rep, int n) ;
static void report_write_char(struct rep_structure *rep, unsigned char n) ;
static void report_write_why(struct rep_structure *rep,char where,char *why) ;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void A4GL_aclfgli_skip_lines (struct rep_structure *rep);
void A4GL_fputmanyc (struct rep_structure *rep, int c, int cnt);
void A4GL_set_column (struct rep_structure *rep);
void A4GL_free_duplicate_binding (struct BINDING *b, int n);
struct BINDING *A4GL_duplicate_binding (struct BINDING *b, int n);
void A4GL_skip_top_of_page (struct rep_structure *rep,int n);
int A4GL_push_report_section(struct rep_structure *rep,char *mod,char *repname,int lineno,char where,char *why,int rb) ;

void A4GL_rep_print (struct rep_structure *rep, int a, int s,
		     int right_margin,int entry);
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


int lvl=0;

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


#define SECTION_NORMAL 0
#define SECTION_HEADER 1
#define SECTION_TRAILER 2



static void report_print(struct rep_structure *rep,int entry, char *fmt,...) {
va_list ap;
char buff[20000];
va_start(ap,fmt);
if (entry<=0) entry=0;
vsprintf(buff,fmt,ap);
A4GL_debug("'%s' - %d\n",buff,entry);
if (rep->print_section==SECTION_NORMAL) {

	if (rep->header) {
		fprintf(rep->output,"%s",rep->header);
		free(rep->header);
		rep->header=0;
	}
  	if (A4GL_isyes(acl_getenv("REPORT_TRACE"))) {
		print_data(rep,buff,entry);
  	} else {
		fprintf(rep->output,"%s",buff);
  	}

}

if (rep->print_section==SECTION_TRAILER) {
	if (rep->header) {free(rep->header); rep->header=0;} // we've got a cached header - don't do anything..
	else {
  	if (A4GL_isyes(acl_getenv("REPORT_TRACE"))) {
		print_data(rep,buff,entry);
  	} else {
		fprintf(rep->output,"%s",buff);
  	}

	}
}

if (rep->print_section==SECTION_HEADER) {
  	if (A4GL_isyes(acl_getenv("REPORT_TRACE"))) {
		print_data(rep,buff,entry);
  	} else {
		if (rep->header) {
			int a;
			a=strlen(rep->header);
			rep->header=realloc(rep->header,a+strlen(buff)+2);
			rep->header[a]=0;
			strcat(rep->header,buff);
		} else {
			rep->header=strdup(buff);
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
  sprintf (buff_0, "rtab%d", ((int) a) & 0xfffffff);
  return buff_0;
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
A4GL_rep_print (struct rep_structure *rep, int a, int s, int right_margin,int entry)
{
  int b;
  int cnt;
  char *str;
  A4GL_debug ("In A4GL_rep_print rep=%p rep->report=%p Page=%d Line=%d Col=%d entry=%d", rep, rep->report,rep->page_no,rep->line_no,rep->col_no,entry);
  
  if (right_margin != 0)
    {
      A4GL_debug ("***** WARNING ***** wordwrap margin not implemented..");
    }
  
  if (rep->line_no == 0 && rep->page_no == 0 && a < 0)
    {
      if (rep->output_mode == 'F')
	{
	  if (strcmp (rep->output_loc, "stdout") == 0)
	    {
	      A4GL_gotolinemode ();
	      //A4GL_push_char ("");
	      //A4GL_push_int (-1);
	      //A4GL_push_int (-1);
	      //A4GL_debug ("In A4GL_rep_print rep=%p rep->report=%p", rep, rep->report);
	      //A4GL_display_at (1, 0);
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
	 A4GL_debug("popen '%s'",rep->output_loc);
	  rep->output = popen (rep->output_loc, "w");
	  if (rep->output == 0)
	    {
	      A4GL_exitwith ("Could not open report output");
	      return;
	    }
	}

  	if (A4GL_isyes(acl_getenv("REPORT_TRACE"))) {
		report_write_entry(rep,ENTRY_START);
	}
    }

  if (a < 0)
    {				// We're just setting up...
      return;
    }



  if (rep->line_no == 0 && !rep->finishing)
    {
      rep->line_no = 1;
      rep->page_no++;
      rep->print_section=SECTION_HEADER;
      A4GL_debug ("Need page header ?");

	if (rep->top_margin) {
      		A4GL_debug ("Skip lines...");
      		A4GL_push_int (rep->top_margin);
      		A4GL_aclfgli_skip_lines (rep);
      		A4GL_debug ("Done skip lines");
	}

      if (rep->report == 0)
	{
	  A4GL_debug ("OOPS - no report function!!!");
	  A4GL_exitwith ("Internal error");
	  exit (10);
	}
	//fprintf(rep->output,"FORCE HEADER1 %d\n",entry);
      rep->report (0, REPORT_PAGEHEADER);	/* report.c:180: too many arguments to function */
      rep->print_section=0;
      A4GL_debug ("Done page header");
    }

  A4GL_debug ("Popping %d parameters", a);
  if (a > 0)
    {
      if (rep->col_no == 0)
	{
	  rep->col_no = 1;
	  A4GL_fputmanyc (rep, ' ', rep->left_margin);
	}
      for (b = 0; b < a; b++)
	{
	  str = A4GL_report_char_pop ();
	  A4GL_debug ("Popped '%s'...", str);
	  report_print (rep, entry,"%s", str);
	  rep->col_no += strlen (str);
	  A4GL_debug ("Popped %s\n", str);
	  acl_free (str);
	}
    }
  A4GL_debug ("Newline : %d", s);




  if (s == 0)
    {
      rep->col_no = 0;
      report_print (rep,-1, "\n");
      rep->line_no++;


      if (rep->print_section==SECTION_NORMAL) {
      	if (rep->line_no > rep->page_length - rep->lines_in_trailer-rep->bottom_margin) {
		//printf("Adding trailer..\n");
		rep->print_section=SECTION_TRAILER;
      		rep->report (0, REPORT_PAGETRAILER);	/* report.c:180: too many arguments to function */
		rep->print_section=SECTION_NORMAL;
      	}

      	if (rep->line_no > rep->page_length - rep->bottom_margin)
		{
		//printf("Bottom margin %d",rep->bottom_margin);
	  	for (cnt = 0; cnt < rep->bottom_margin; cnt++) {
	      		report_print (rep, -1,"\n");
			rep->line_no++;
			//printf("--->%d\n",rep->line_no);
	    	}

	  	rep->line_no = 0;
		if (a==0&&s==5)  {
			return;
		} else {
			if (rep->lines_in_trailer) {
				A4GL_debug("Calling rep_print");
				A4GL_rep_print(rep,0,1,0,-10);
			}
		}
	    }
	}
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
  x=malloc(cnt+1);
  memset(x,c,cnt);
  x[cnt]=0;
  report_print(rep,-1,x);
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
A4GL_debug("Calling rep_print");
  A4GL_rep_print (rep, 1, 1, 0,-2);
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
      A4GL_rep_print (rep, 0, 0, 0,-3);
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
  if (rep->line_no > (rep->page_length - rep->bottom_margin - a))
    A4GL_skip_top_of_page (rep,2);
}

/**
 *
 * @todo Describe function
 */
void
A4GL_skip_top_of_page (struct rep_structure *rep,int n)
{
  int z;
  int a;

a=rep->page_length-rep->line_no-rep->bottom_margin-rep->lines_in_trailer;

//printf("pl=%d lineno=%d bm=%d lt=%d\n",
//rep->page_length,rep->line_no,rep->bottom_margin,
	//rep->lines_in_trailer);

//if (n==999 && rep->page_no<=1 && a) {
		//rep->line_no++;
		//A4GL_rep_print(rep,0,1,0);
		//A4GL_rep_print(rep,0,0,0);
//}

  a=rep->page_length-rep->line_no-rep->bottom_margin-rep->lines_in_trailer;

if (n!=1 || rep->page_no) {
  if (rep->header) return;
  if (rep->line_no==0) return;
}

  //if (rep->page_no==1&& rep->lines_in_first_header) {
	//a=a-rep->lines_in_first_header;
  //} else {
	//a=a-rep->lines_in_header;
  //}

//printf("Add %d lines %d %d\n",a,rep->print_section,n);

if (a) {
  for (z=0;z<a;z++) {
      A4GL_rep_print (rep, 0, 0, 0,-4);
    }

    A4GL_rep_print (rep, 0, 0, 0,-5);
}
  //if (n==999&&rep->finishing&&rep->page_no==1) { A4GL_rep_print(rep,0,0,-11);  }


//printf("Done skip top %d %d\n",rep->page_no,rep->line_no);

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
      return "DATETIME";
    case 11:
      return "BYTE";
    case 12:
      return "TEXT";
    case 13:
      return "VARCHAR";
    case 14:
      return "INTERVAL";
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
      return "YEAR TO FRACTION(5)";

    case 8:
    case 5:			/* decimal */
      return "(32,16)";

    case 0:
    case 13:
      sprintf (buff_1, "(%d)", s);
      return buff_1;

    case 14:
      sprintf (buff_1, "year to second(5)");
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
  sprintf (buff_2, "%s %s", nm (dtype), sz (dtype, dim));
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

  sprintf (buff_3, "create temp table %s (\n", gen_rep_tab_name (b));
  //sprintf (buff, "create  table %s (\n", gen_rep_tab_name (b));

  for (a = 0; a < n; a++)
    {
      if (a)
	strcat (buff_3, ",\n");
      sprintf (tmpbuff, "c%d %s %s", a, nm (b[a].dtype),
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
  A4GLSQL_execute_implicit_sql (A4GLSQL_prepare_sql
				(A4GL_mk_temp_tab (b, n)));
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
  sprintf (buff, "INSERT INTO %s VALUES (", gen_rep_tab_name (b));

  for (a = 0; a < n; a++)
    {
      if (a)
	strcat (buff, ",");
      strcat (buff, "?");
    }
  strcat (buff, ")");
  A4GL_debug ("Attempting to execute %s\n", buff);
  x = (void *) A4GLSQL_prepare_glob_sql (buff, n, b);
  A4GL_debug ("x=%p\n", x);
  A4GLSQL_execute_implicit_sql (x);
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
  char tbuff[1024];
  struct BINDING ibind[] = {
    /* ibind 0 */
    {0, 0, 0}
  };				/* end of binding */
  struct BINDING obind[] = {
    {0, 0, 0}
  };				/* end of binding */


  *reread = A4GL_duplicate_binding (b, n);

  sprintf (buff, "select * from %s order by ", gen_rep_tab_name (b));

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
	      sprintf (tbuff, "c%d", a2);
	      strcat (buff, tbuff);
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
  sprintf (tbuff, "_%d", (int) gen_rep_tab_name (b));
  A4GLSQL_declare_cursor (0,
			  A4GLSQL_prepare_select (ibind, 0, obind, 0, buff),
			  0, tbuff);

  if (a4gl_sqlca.sqlcode != 0)
    return 0;
  A4GLSQL_open_cursor (0, tbuff);
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
  char tbuff[1024];

  sprintf (tbuff, "_%d", (int) gen_rep_tab_name (b));
  A4GLSQL_set_sqlca_sqlcode (0);
  A4GLSQL_fetch_cursor (tbuff, 2, 1, n, reread);
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
  rbind = malloc (sizeof (struct BINDING) * n);
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
      rbind[a].ptr = malloc (sz);
      A4GL_debug ("allocated as %p", rbind[a].ptr);

      rbind[a].dtype = b[a].dtype;
      rbind[a].size = b[a].size;
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
  A4GL_debug ("Not implemented");
  A4GL_exitwith ("Not implemented");
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

  ptr =
    function (tos_ptr, tos_size, -1, (struct struct_scr_field *) 0,
	      DISPLAY_TYPE_PRINT);
  if (ptr != 0)
    {
      ptr = strdup (ptr);
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






















static void print_report_block_start(struct rep_structure *rep,char *mod,char *repname,int lineno,char where,char *why,int rb) {
  if (A4GL_isyes(acl_getenv("TRACE_AS_TEXT"))) {
	print_lvl(rep,lvl);
	fprintf(rep->output,"<ACL_ENTRY_BLOCK line=%d where=%c why=\"%s\" block=%d>\n",lineno,where,why,rb);
  } else {
	report_write_entry(rep,ENTRY_BLOCK);

	//report_write_string(rep,mod);
	//report_write_string(rep,repname);

	report_write_int(rep,lineno);
	report_write_why(rep,where,why);
	report_write_int(rep,rb);
  }
}

static void print_report_block_end(struct rep_structure *rep, int rb) {
  if (A4GL_isyes(acl_getenv("TRACE_AS_TEXT"))) {
	print_lvl(rep,lvl);
	fprintf(rep->output,"</ACL_ENTRY_BLOCK block=%d>\n",rb);
   } else {
	report_write_entry(rep,ENTRY_BLOCK_END);
	//report_write_int(rep,rb);
   }

}

/*
int A4GL_push_report_print_entry(struct rep_structure *rep, int lineno, int rb, int entry) {
  if (A4GL_isyes(acl_getenv("REPORT_TRACE"))) {
  	if (A4GL_isyes(acl_getenv("TRACE_AS_TEXT"))) {
		//print_lvl(rep,lvl);
		//fprintf(rep->output,"<ACL_REPORT_PRINT_ENTRY lineno=%d block=%d entry=%d>\n",lineno,rb,entry);
   	} else {
		//report_write_entry(rep,ENTRY_ENTRY_START);
		//report_write_int(rep,lineno);
		//report_write_int(rep,rb);
		//report_write_int(rep,entry);
   	}
   }
  //lvl++;
return rb;
}

int A4GL_pop_report_print_entry(struct rep_structure *rep, int rb, int entry) {
  //lvl--;
  if (A4GL_isyes(acl_getenv("REPORT_TRACE"))) {
  	if (A4GL_isyes(acl_getenv("TRACE_AS_TEXT"))) {
		//print_lvl(rep,lvl);
		//fprintf(rep->output,"</ACL_REPORT_PRINT_ENTRY block=%d entry=%d>\n",rb,entry);
   	} else {
		//report_write_entry(rep,ENTRY_ENTRY_END);
		//report_write_int(rep,rb);
		//report_write_int(rep,entry);
   	}
   }

return 1;
}
*/


int A4GL_push_report_section(struct rep_structure *rep,char *mod,char *repname,int lineno,char where,char *why,int rb) {
/*printf("mod=%s where=%c why=%s\n",mod,where,why); */
  if (A4GL_isyes(acl_getenv("REPORT_TRACE"))) {
		print_report_block_start(rep,mod,repname,lineno,where,why,rb);
  }
  lvl++;
return rb;
}


void A4GL_pop_report_section(struct rep_structure *rep, int rb) {
  if (A4GL_isyes(acl_getenv("REPORT_TRACE"))) {
		lvl--;
		print_report_block_end(rep,rb);
  }
}



static void print_lvl(struct rep_structure *rep,int lvl) {
int a;
	if (lvl==0) return;

	for (a=0;a<lvl;a++) {
		fprintf(rep->output,"  ");
	}
}


static void print_data(struct rep_structure *rep,char *buff,int entry) {
char *s;
if (entry==-1) {
return;
}

s=strdup(buff);
A4GL_trim(s);
  if (A4GL_isyes(acl_getenv("TRACE_AS_TEXT"))) {
		
	if (strlen(s)&& strcmp(s,"\n")!=0) {
		print_lvl(rep,lvl);
		fprintf(rep->output,"<CDATA page=%d line=%d col=%d entry=%d>%s</CDATA>\n",rep->page_no,rep->line_no,rep->col_no,entry,s);
	}
  } else {
	if (strlen(s)&& strcmp(s,"\n")!=0) {
		report_write_entry(rep,ENTRY_DATA);
		report_write_int(rep,rep->page_no);
		report_write_int(rep,rep->line_no);
		report_write_int(rep,rep->col_no);
		report_write_int(rep,entry);
		report_write_string(rep,s);
	}
  }
free(s);
}


static void report_write_int(struct rep_structure *rep, int n) {
//unsigned char c;
short s;
	if (n<254) {
		report_write_char(rep,n);
		return;
	} 

	if (n<32000) {
		s=htons(n);
		report_write_char(rep,254);
		fwrite(&s,sizeof(s),1,rep->output);
	}

	report_write_char(rep,255);
	n=htonl(n);
	fwrite(&n,sizeof(n),1,rep->output);
}

static void report_write_char(struct rep_structure *rep, unsigned char n) {
	fwrite(&n,sizeof(n),1,rep->output);
}

static void report_write_string(struct rep_structure *rep, char *s) {
	int n;
	n=strlen(s);
	report_write_int(rep,n);
	fwrite(s,n,1,rep->output);
}


static void report_write_why(struct rep_structure *rep,char where,char *why) {
	report_write_char(rep,where);
	report_write_string(rep,why);
}



static void report_write_entry(struct rep_structure *rep,char type) {
  if (!A4GL_isyes(acl_getenv("TRACE_AS_TEXT"))) {
	report_write_char(rep,type);

	if (type==ENTRY_START) {
		int version_no=2;
		report_write_int(rep,version_no);
		report_write_int(rep,time(0));
		report_write_int(rep,rep->top_margin);
		report_write_int(rep,rep->bottom_margin);
		report_write_int(rep,rep->left_margin);
		report_write_int(rep,rep->right_margin);
		report_write_int(rep,rep->page_length);
		report_write_string(rep,rep->repName);
		report_write_string(rep,rep->modName);
	}
  } else {
	if (type==ENTRY_START) {
		fprintf(rep->output,"<LAYOUT module=\"%s\" name=\"%s\" top=%d bottom=%d left=%d right=%d length=%d time=%ld />\n",rep->modName,rep->repName,
			rep->top_margin,
			rep->bottom_margin,
			rep->left_margin,
			rep->right_margin,
			rep->page_length,
			(long)time(0));
	}
  }
}

/* ============================= EOF ================================ */
