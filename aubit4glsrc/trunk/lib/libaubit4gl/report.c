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
# $Id: report.c,v 1.12 2003-01-30 11:54:38 afalout Exp $
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

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void 				aclfgli_skip_lines	(struct rep_structure *rep);
void 				fputmanyc			(FILE *f,int c,int cnt);
void 				set_column			(struct rep_structure *rep);
void 				free_duplicate_binding( struct BINDING *b,int n) ;
struct BINDING *	duplicate_binding	(struct BINDING *b,int n) ;
void 				skip_top_of_page	(struct rep_structure *rep);

void 				rep_print 			(struct rep_structure *rep, int a,
										int s,int right_margin);
void 				need_lines			(struct rep_structure *rep);
void 				add_spaces			(void);
char * 				mk_temp_tab			(struct BINDING *b,int n);
void 				make_report_table	(struct BINDING *b,int n);
void 				add_row_report		(struct BINDING *b,int n);
int 				init_report_table	(struct BINDING *b,int n,
										struct BINDING *o,int no,
										struct BINDING **reread);
int 				report_table_fetch	(struct BINDING *reread,int n,
										struct BINDING *b);
void 				end_report_table	(struct BINDING *b,int n,
										struct BINDING *reread);
void 				rep_file_print		(struct rep_structure *rep,
										char *fname, int opt_semi);

char *              decode_datatype		(int dtype,int dim);
extern sqlca_struct sqlca;


/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 *
 * @todo Describe function
 */
static char *
gen_rep_tab_name(void *p)
{
int a;
static char buff[256];
	a=(int)p;
	sprintf(buff,"rtab%d",((int )a)&0xfffffff);
	return buff;
}



/**
 *
 * @todo Describe function
 */
void
rep_print (struct rep_structure *rep, int a, int s,int right_margin)
{
  int b;
  int cnt;
  char *str;
  debug ("In rep_print rep=%p rep->report=%p",rep,rep->report);

  if (right_margin!=0) {
		debug("***** WARNING ***** wordwrap margin not implemented..");
  }

  debug ("In rep_print rep=%p rep->report=%p",rep,rep->report);
  if (rep->line_no == 0 && rep->page_no == 0)
    {
      if (rep->output_mode == 'F')
	{
	  if (strcmp (rep->output_loc, "stdout")==0)
	    {
	      push_char("");
	      push_int(-1);
	      push_int(-1);
			debug ("In rep_print rep=%p rep->report=%p",rep,rep->report);
	      display_at(1,0);
			debug ("In rep_print rep=%p rep->report=%p",rep,rep->report);
	      rep->output = stdout;
			debug ("In rep_print rep=%p rep->report=%p",rep,rep->report);
	    }
	  else
	    {
	      rep->output = mja_fopen (rep->output_loc, "w");
	      if (rep->output == 0)
		{
		  exitwith("Could not open report output");
		  return;
		}

	    }
	}
      else
	{
	  rep->output = popen (rep->output_loc, "w");
	  if (rep->output == 0)
	    {
	      exitwith("Could not open report output");
	      return;
	    }
	}
    }

  debug ("In rep_print rep=%p rep->report=%p",rep,rep->report);
  if (rep->line_no == 0)
    {
      rep->line_no = 1;
      rep->page_no++;
      debug ("Need page header");
  debug ("In rep_print rep=%p rep->report=%p",rep,rep->report);
      push_int(rep->top_margin);
	debug("Skip lines...");
  debug ("In rep_print rep=%p rep->report=%p",rep,rep->report);
      aclfgli_skip_lines(rep);
	debug("Done skip lines");
	if (rep->report==0) {
			debug("OOPS - no report function!!!");
			exitwith("Internal error");
			exit(10);
	}
  debug ("In rep_print rep=%p rep->report=%p",rep,rep->report);
      rep->report (0, REPORT_PAGEHEADER); /* report.c:180: too many arguments to function */
  debug ("In rep_print rep=%p rep->report=%p",rep,rep->report);
	debug("Done page header");
    }

  debug ("In rep_print rep=%p rep->report=%p",rep,rep->report);
  debug ("Popping %d parameters", a);
  if (a > 0)
    {
    if (rep->col_no==0) {
         rep->col_no = 1;
         fputmanyc(rep->output,' ',rep->left_margin);
    }
      for (b = 0; b < a; b++)
	{
	  str = char_pop ();
	  debug ("Popped '%s'...",str);
          rep->col_no+=strlen(str);
	  debug ("Popped %s\n", str);
	  fprintf (rep->output,"%s", str);
	  acl_free(str);
	}
    }
  debug ("Newline : %d", s);

  if (s == 0)
    {
      fprintf (rep->output,"\n");
      rep->col_no=0;
      rep->line_no++;

      if (rep->line_no > rep->page_length - rep->bottom_margin)
	{
          for (cnt=0;cnt<rep->bottom_margin;cnt++) {
	         fprintf (rep->output,"\n");
          }
	  rep->line_no = 0;
	  rep_print (rep, 0, 0,0);
        }
    }
  fflush(rep->output);
  return ;
}


/**
 *
 * @todo Describe function
 */
void 
fputmanyc(FILE *f,int c,int cnt) 
{
int a;
	for (a=0;a<cnt;a++) fputc(c,f);
}

/**
 *
 * @todo Describe function
 */
void 
set_column(struct rep_structure *rep) 
{
long a;
long needn;
	a=pop_long();
	push_char("");
	rep_print(rep,1,1,0);
	#ifdef DEBUG
	/* {DEBUG} */ {debug("Popped %ld - print what we have",a);
	}
	#endif
	#ifdef DEBUG
	/* {DEBUG} */ {debug("Current pos=%d need position %d left_margin=%d",rep->col_no,a,rep->left_margin);
	}
	#endif

  	if ( rep->col_no == 0 ) {
  	     needn = a + rep->left_margin - 1;
  	     rep->col_no = 1;
  	}
  	else {
  	     needn = a - rep->col_no;
  	}

	#ifdef DEBUG
	/* {DEBUG} */ {debug("needn=%ld",needn);
	}
	#endif

	if (needn>0) {

	        fputmanyc(rep->output,' ',(int)needn);
	        rep->col_no+=needn;
	#ifdef DEBUG
	/* {DEBUG} */ {        debug("Colno increased by %d",needn);
	}
	#endif
	} else {
	#ifdef DEBUG
	/* {DEBUG} */ {debug("Already past that point");
	}
	#endif
	}
	push_char("");
}

/**
 *
 * @todo Describe function
 */
void 
aclfgli_skip_lines(struct rep_structure *rep) 
{
long a;
long b;
	a=pop_long();
	for (b=0;b<a;b++) {
	push_char("");
	rep_print (rep, 1, 0,0);
	}
}

/**
 *
 * @todo Describe function
 */
void
need_lines(struct rep_structure *rep)
{
int a;
	a=pop_int();
	if (rep->line_no > (rep->page_length - rep->bottom_margin -a))
	      skip_top_of_page(rep);
}

/**
 *
 * @todo Describe function
 */
void
skip_top_of_page(struct rep_structure *rep)
{
int z;
	z=rep->page_no;

	while (z==rep->page_no) {
	     push_char("");
	     rep_print(rep,1,0,0);
	}

}

/**
 *
 * @todo Describe function
 */
void
add_spaces(void)
{
int a;
char str[1000];
	a=pop_int();
	if (a>=1000) a=999;
	memset(str,' ',a);
	str[a]=0;
	push_char(str);
}



/**
 * ORDER BY
 *
 * @todo Describe function
 */
static char *
nm(int n) 
{
	switch(n&15) {
		case 0: return "CHAR";
		case 1: return "SMALLINT";
		case 2: return "INTEGER";
		case 3: return "FLOAT";
		case 4: return "SMALLFLOAT";
		case 5: return "DECIMAL";
		case 6: return "INTEGER";
		case 7: return "DATE";
		case 8: return "MONEY";
		case 10: return "DATETIME";
		case 11: return "BYTE";
		case 12: return "TEXT";
		case 13: return "VARCHAR";
		case 14: return "INTERVAL";
	}
	return "CHAR";
}

/**
 *
 * @todo Describe function
 */
static char *
sz(int d,int s) 
{
static char buff[256];
	switch(d&15) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 7:
		case 6:
		case 11:
		case 12:
			 return "";

		case 10: return "YEAR TO FRACTION(5)";

		case 8:
		case 5: /* decimal */
			return "(16,32)";

		case 0:
		case 13: sprintf(buff,"(%d)",s); return buff;

		case 14: sprintf(buff,"year to second(5)");
			return buff;
	}
return "";
}


/**
 * Used for AREP compiler 
 * @todo Describe function
 */
char *
decode_datatype(int dtype,int dim)
{
static char buff[256];
	sprintf(buff,"%s %s",nm(dtype),sz(dtype,dim));
	return buff;
}

/**
 *
 * @todo Describe function
 */
char *
mk_temp_tab(struct BINDING *b,int n)
{
int a;
static char buff[30000];
char tmpbuff[256];

	 /*
	 hopefully b should be fairly random within this session..
	 as the same report cannot be running twice at the same time.....
     Andrej say: yes it can!
     */
	sprintf(buff,"create temp table %s (\n",gen_rep_tab_name(b));

	for (a=0;a<n;a++) {
		if (a) strcat(buff,",\n");
		sprintf(tmpbuff,"c%d %s %s",a,nm(b[a].dtype),sz(b[a].dtype,b[a].size));
		strcat(buff,tmpbuff);
	}
	strcat(buff,")");
return buff;
}

/**
 *
 * @todo Describe function
 */
void
make_report_table(struct BINDING *b,int n)
{
   A4GLSQL_execute_implicit_sql(A4GLSQL_prepare_sql(mk_temp_tab(b,n)));
}


/**
 *
 * @todo Describe function
 */
void
add_row_report(struct BINDING *b,int n)
{
  char buff[1024];
  int a;
  void *x;
  sprintf(buff,"INSERT INTO %s VALUES (",gen_rep_tab_name(b));

  for (a=0;a<n;a++) {
		if (a) strcat(buff,",");
		  strcat(buff,"?");
  }
  strcat(buff,")");
  debug("Attempting to execute %s\n",buff);
  x = (void *)A4GLSQL_prepare_glob_sql(buff,n,b);
  debug("x=%p\n",x);
  A4GLSQL_execute_implicit_sql(x);
}

/**
 *
 * @todo Describe function
 */
int
init_report_table(struct BINDING *b,int n,struct BINDING *o,int no,
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
    };                          /* end of binding */
    struct BINDING obind[] = {
      {0, 0, 0}
    };                          /* end of binding */


	*reread=duplicate_binding(b,n);

	sprintf(buff,"select * from %s order by ", gen_rep_tab_name(b));

	for (a1=0;a1<no;a1++) {
	ok=0;
		debug("Looking for %p",o[a1]);
		if (a1) strcat(buff,",");
		for (a2=0;a2<n;a2++) {
			debug("Checking %p %p",o[a1].ptr,b[a2].ptr);
			if (o[a1].ptr==b[a2].ptr) {
				sprintf(tbuff,"c%d",a2);
				strcat(buff,tbuff);
				ok=1;
				break;
			}
		}
		if (ok==0) {
				debug("Can't match column in orderby....");
				exitwith("Big Opps");
				return 0;
		}
	}
	debug("Got select statement as : %s\n",buff);
	sprintf(tbuff,"_%d",(int)gen_rep_tab_name(b));
	A4GLSQL_declare_cursor (0, A4GLSQL_prepare_select (ibind, 0, obind, 0, buff), 0, tbuff);

	if (sqlca.sqlcode!=0) return 0;
	A4GLSQL_open_cursor (0, tbuff);
	if (sqlca.sqlcode!=0) return 0;


return 0;
}


/**
 *
 * @todo Describe function
 */
int
report_table_fetch(struct BINDING *reread,int n,struct BINDING *b)
{
char tbuff[1024];

	sprintf(tbuff,"_%d",(int)gen_rep_tab_name(b));
	A4GLSQL_set_sqlca_sqlcode (0);
	A4GLSQL_fetch_cursor (tbuff, 2, 1, n, reread);
	push_params(reread,n);

	if (sqlca.sqlcode==0) return 1;
	A4GLSQL_set_sqlca_sqlcode (0);
	return 0;
}

/**
 *
 * @todo Describe function
 */
void
end_report_table (struct BINDING *b,int n,struct BINDING *reread)
{
	free_duplicate_binding(reread,n);
}

/**
 *
 * @todo Describe function
 */
struct BINDING *
duplicate_binding(struct BINDING *b,int n)
{
struct BINDING *rbind;
int a;
int sz;
	debug("Duplicating bindings....");
	rbind=malloc(sizeof(struct BINDING)*n);
	for (a=0;a<n;a++) {
		sz=0;
		switch (b[a].dtype) {
			case 0: sz=b[a].size+1;break;

			case 1: 
			case 2: 
			case 6:
			case 7: 
			case 4: sz=4;break;

			case 8: 
			case 14:
			case 10: 
			case 5: sz=64;break;

			case 11: sz=sizeof(fglbyte);break;
			case 12: sz=sizeof(fgltext);break;
			case 13: sz=256;break;
			case 3: sz=8;break;
		}

		debug("allocing %d bytes\n",sz);
		rbind[a].ptr=malloc(sz);
		debug("allocated as %p",rbind[a].ptr);

		rbind[a].dtype=b[a].dtype;
		rbind[a].size=b[a].size;
	}
	
	debug("All done");
return rbind;
}

/**
 *
 * @todo Describe function
 */
void 
free_duplicate_binding( struct BINDING *b,int n) 
{
int a;
	debug("Freeing duplicate..");
	for (a=0;a<n;a++) {
		debug("Freeing %p",b[a].ptr);
		free(b[a].ptr);
	}
	debug("Freeing structure %p",b);
	free(b);
}


/**
 *
 * @todo Describe function
 */
void
rep_file_print(struct rep_structure *rep, char *fname, int opt_semi)
{
	debug("Not implemented");
	exitwith("Not implemented");
}

/* ============================= EOF ================================ */

