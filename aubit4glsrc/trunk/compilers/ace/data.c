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
# $Id: data.c,v 1.39 2008-02-11 17:55:46 mikeaubury Exp $
#*/

/**
 * @file
 *
 *
 *
 *
 * @todo Doxygen comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_ace_int.h"


//#define A4GL_debug A4GL_set_line(__FILE__,__LINE__);A4GL_debug_full

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

struct report this_report;
extern char *outputfilename;
extern char *ordby[256];
extern int ordbycnt;

#define COLUMNS_METHOD_UNSET -1
#define COLUMNS_METHOD_INTO_TEMP 0
#define COLUMNS_METHOD_DESCRIBE  1

int columns_method=COLUMNS_METHOD_UNSET;
//int columns_method=COLUMNS_METHOD_DESCRIBE;
int need_to_open_cursor=2;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void dif_add_bind_int (void *list, long a);
char *A4GL_decode_datatype (int dtype, int dim);
void yyerror_sql (char *s);
void print_variables (char *s);
char *add_zero_rows_where (struct select_stmts *ptr);
void add_fmt (int cat, struct expr *col, struct acerep_commands commands);
int decode_dtype (char *s);
void dif_add_bind (void *list, void *dptr, int dtype, int size);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 *
 * @todo Describe function
 */
void
init_report (void)
{
  this_report.output.top_margin = 3;
  this_report.output.bottom_margin = 3;
  this_report.output.left_margin = 5;
  this_report.output.right_margin = 132;
  this_report.output.top_of_page = "";
  this_report.output.page_length = 66;
  this_report.output.report_to_where = 0;
  this_report.output.report_to_filename = "";
  this_report.magic = acl_strdup ("AACE");
  this_report.dbname = 0;
  this_report.report_name = outputfilename;
  this_report.variables.variables_len = 0;
  this_report.inputs.inputs_len = 0;
  this_report.fmt.fmt_len = 0;
  this_report.functions.functions_len = 0;
  this_report.variables.variables_val = 0;
  this_report.inputs.inputs_val = 0;
  this_report.fmt.fmt_val = 0;
  this_report.functions.functions_val = 0;
  this_report.ascii.variables.variables_len = 0;
  this_report.ascii.variables.variables_val = 0;
  this_report.output.report_to_where = 0;
  this_report.getdata.get_data_u.selects.selects_len = 0;
  this_report.aggs.aggs_len = 0;
  this_report.aggs.aggs_val = 0;

  ace_add_variable ("pageno", "INTEGER", CAT_BUILTIN, 0, 2, 0);
  ace_add_variable ("lineno", "SMALLINT", CAT_BUILTIN, 0, 1, 0);
  ace_add_variable ("today", "DATE", CAT_BUILTIN, 0, 7, 0);
  ace_add_variable ("time", "CHAR", CAT_BUILTIN, 0, 0, 8);
  ace_add_variable ("date", "CHAR", CAT_BUILTIN, 0, 0, 15);
}


/**
 *
 * @todo Describe function
 */
int
find_variable (char *name)
{
  struct acerep_variable *ptr;
  int a;
  for (a = 0; a < this_report.variables.variables_len; a++)
    {
      ptr = &this_report.variables.variables_val[a];
      if (A4GL_aubit_strcasecmp (ptr->name, name) == 0)
	{
	  return a;
	}
    }

  return -1;
}


#define STRLENEQ(x,y) (strncmp(x,y,strlen(y))==0)

/**
 *
 * @todo Describe function
 */
int
decode_dtype (char *s)
{
  if (STRLENEQ (s, "CHAR"))
    return 0;
  if (STRLENEQ (s, "SMALLINT"))
    return 1;
  if (STRLENEQ (s, "INTEGER"))
    return 2;
  if (STRLENEQ (s, "FLOAT"))
    return 3;
  if (STRLENEQ (s, "SMALLFLOAT"))
    return 4;
  if (STRLENEQ (s, "DECIMAL"))
    return 5;
  if (STRLENEQ (s, "SERIAL"))
    return 6;
  if (STRLENEQ (s, "DATE"))
    return 7;
  if (STRLENEQ (s, "MONEY"))
    return 8;

  if (STRLENEQ (s, "DATETIME"))
    return 10;
  if (STRLENEQ (s, "BYTE"))
    return 11;
  if (STRLENEQ (s, "TEXT"))
    return 12;
  if (STRLENEQ (s, "VARCHAR"))
    return 13;
  if (STRLENEQ (s, "INTERVAL"))
    return 14;

  if (STRLENEQ (s, "NCHAR"))
    return 15;

  printf ("Unknown datatype for %s - assuming char...\n", s);

  return 0;
}

/**
 * Function with same name in mod.c - renamed from add_variable to ace_add_variable
 * @todo Describe function
 */
void
ace_add_variable (char *name, char *dstring, int category, int pno, int dtype,
		  int dim)
{
  struct acerep_variable *ptr;
  char buff[256];
  char *ob;
  char buff2[256];
  char buff3[256];


  if (dtype == -1)
    {
      dtype = decode_dtype (dstring);
    }

  if (dtype == 6)
    {				/* serial */
      dtype = 2;		/* integer */
    }

  if (dstring == 0)
    {
      strcpy (buff, A4GL_decode_datatype (dtype, dim));
      dstring = buff;
    }

  if (dim == 0)
    {
      /*printf ("Decoding datatype %s\n", dstring);*/
      ob = strchr (dstring, '(');
      if (ob)
	{
	  strcpy (buff2, "");
	  strcpy (buff3, "");
	  ob++;
	  strcpy (buff2, ob);
	  ob = strchr (buff2, ')');
	  if (ob)
	    *ob = 0;
	  ob = strchr (buff2, ',');
	  if (ob)
	    {
	      *ob = 0;
	      strcpy (buff3, ob + 1);
	    }

	  if (dtype == 0 || dtype == 13)
	    {			/* char or varchar */
	      dim = atoi (buff2);
	    }

	  if (dtype == 8 || dtype == 5)
	    dim = atoi (buff3) + atoi (buff2) * 256;
	}
    }

  this_report.variables.variables_len++;
  this_report.variables.variables_val =
    realloc (this_report.variables.variables_val,
	     this_report.variables.variables_len * sizeof (struct acerep_variable));

  ptr =
    &this_report.variables.variables_val[this_report.variables.variables_len - 1];
  ptr->name = acl_strdup (name);
  ptr->datatype_string = acl_strdup (dstring);
  ptr->category = category;
  ptr->param_no = pno;
  ptr->datatype = dtype;
  ptr->dim = dim;
  ptr->dataspace = 0;
}



static int has_sql_variable(char *s) {
  struct acerep_variable *ptr;
	int a;
	for (a=0;a<this_report.variables.variables_len;a++) {
		ptr=&this_report.variables.variables_val[a];

		if (ptr->category==CAT_SQL && strcmp(ptr->name,s)==0) {
			// Already got one of these...
			return 1;
		}
	}
	return 0;
}

/**
 *
 * @todo Describe function
 */
void
add_function (char *name)
{
  this_report.functions.functions_len++;

  this_report.functions.functions_val =
    realloc (this_report.functions.functions_val,
	     //this_report.functions.functions_len * sizeof (struct function));
		 this_report.functions.functions_len * sizeof (struct a4gl_report_function));

  this_report.functions.functions_val[this_report.functions.functions_len -
				      1].name = acl_strdup (name);
}




/**
 *
 * @todo Describe function
 */
int
add_agg (struct agg_val agg)
{

  agg.format_id = this_report.fmt.fmt_len;


  this_report.aggs.aggs_len++;
  this_report.aggs.aggs_val = realloc (this_report.aggs.aggs_val,
				       this_report.aggs.aggs_len *
				       sizeof (struct agg_val));

  memcpy (&this_report.aggs.aggs_val[this_report.aggs.aggs_len - 1], &agg,
	  sizeof (struct agg_val));

  return this_report.aggs.aggs_len - 1;

}

/**
 *
 * @todo Describe function
 */
void
add_select (char *sql, char *temptabname)
{
  struct select_stmts *ptr;
  char *buff;
  int a;
  int c;
  int whereposcnt = 0;
  char buffer[80];

/*printf(":-> %s\n",sql);*/
  /*
     sql may contain newlines, these signify special data in the select 
     statement...

     \n0 = start of additional "don't get any real data" code
     \n2(n) = start of variable use (variable ID)
   */

  this_report.getdata.select_or_read = 0;
  this_report.getdata.get_data_u.selects.selects_len++;
  this_report.getdata.get_data_u.selects.selects_val =
    realloc (this_report.getdata.get_data_u.selects.selects_val,
	     sizeof (struct select_stmts) *
	     this_report.getdata.get_data_u.selects.selects_len);


  ptr =
    &this_report.getdata.get_data_u.selects.selects_val[this_report.getdata.
							get_data_u.selects.
							selects_len - 1];
  ptr->orderby_list.orderby_list_len = 0;
  ptr->orderby_list.orderby_list_val = 0;
  ptr->temp_tab_name = acl_strdup (temptabname);
  strcpy (temptabname, "");

  ptr->varids.varids_len = 0;
  ptr->varids.varids_val = 0;

  ptr->varpos.varpos_len = 0;
  ptr->varpos.varpos_val = 0;


  ptr->has_where = 0;
  ptr->wherepos1 = 0;
  ptr->wherepos2 = 0;

  buff = acl_strdup (sql);

  c = 0;
  for (a = 0; a < strlen (sql); a++)
    {
      if (sql[a] == '\n')
	{
	  a++;
	  if (sql[a] == '0')
	    {
	      if (whereposcnt == 0)
		{
		  ptr->wherepos1 = c;
		}
	      if (whereposcnt == 1)
		{
		  ptr->wherepos2 = c;
		}
	      whereposcnt++;
	      continue;
	    }

	  if (sql[a] == '2')
	    {
	      a++;
	      if (sql[a] != '(')
		{
		  a4gl_ace_yyerror ("Corrupt...");
		}
	      a++;
	      strcpy (buffer, "");

	      while (sql[a] != ')')
		{
		  int l;
		  l = strlen (buffer);

		  buffer[l + 1] = 0;
		  buffer[l] = sql[a++];
		}

	      ptr->varids.varids_len++;
	      ptr->varids.varids_val =
		realloc (ptr->varids.varids_val,
			 sizeof (int) * ptr->varids.varids_len);
	      ptr->varpos.varpos_len++;
	      ptr->varpos.varpos_val =
		realloc (ptr->varpos.varpos_val,
			 sizeof (int) * ptr->varpos.varpos_len);


	      ptr->varids.varids_val[ptr->varids.varids_len - 1] =
		atoi (buffer);
	      ptr->varpos.varpos_val[ptr->varpos.varpos_len - 1] = c;
	      buff[c++] = '?';
	      continue;
	    }
	  a4gl_ace_yyerror ("Corrupt...");
	}

      if (c && buff[c - 1] == ' ' && sql[a] == ' ');	/* we'll ignore these */
      else
	buff[c++] = sql[a];

      buff[c] = 0;
    }

  ptr->statement = acl_strdup (buff);
  free (buff);


  if (ptr->wherepos1 && ptr->wherepos2)
    ptr->has_where = 1;


  /*printf("Added : %d-%s\n",this_report.getdata.get_data_u.selects.selects_len,ptr->statement);*/
}

/**
 *
 * @todo Describe function
 */
void
add_inputs (char *prompt, char *variable)
{
  int x;
  this_report.inputs.inputs_len++;
  this_report.inputs.inputs_val =
    realloc (this_report.inputs.inputs_val,
	     sizeof (struct input_vals) * this_report.inputs.inputs_len);
  this_report.inputs.inputs_val[this_report.inputs.inputs_len - 1].prompt =
    acl_strdup (prompt);
  this_report.inputs.inputs_val[this_report.inputs.inputs_len -
				1].variable_name = acl_strdup (variable);

  x = find_variable (variable);
  if (x >= 0)
    {
      this_report.inputs.inputs_val[this_report.inputs.inputs_len - 1].varid =
	x;
    }
  else
    {
      printf ("Unknown variable %s\n", variable);
    }
}


/**
 *
 * @todo Describe function
 */
void
add_fmt (int cat, struct expr *col, struct acerep_commands commands)
{
  this_report.fmt.fmt_len++;
  this_report.fmt.fmt_val =
    realloc (this_report.fmt.fmt_val,
	     sizeof (struct format) * this_report.fmt.fmt_len);

  this_report.fmt.fmt_val[this_report.fmt.fmt_len - 1].category = cat;
  this_report.fmt.fmt_val[this_report.fmt.fmt_len - 1].column=col;

  memcpy (&this_report.fmt.fmt_val[this_report.fmt.fmt_len - 1].commands, &commands, sizeof (struct acerep_commands));



}



/*
add_zero_rows_where

we don't really want to run all the SQLs for real - but
we do need to have the tables/results created for us so we
can determine datatypes and names.

This means that we need to add a little bit to the where clause that
hopefully any optimizier may make use of and return us zero results
fairly quickly
To do this - we're adding (1=0) to the where clause.
When the select statement was parsed - it would have generated some codes, which
are processed by add_select, this sets up three control variables

has_where = SQL Has a where clause
wherepos1 = Start of where clause
wherepos2 = End if where clause
*/

/**
 *
 * @todo Describe function
 */
char *
add_zero_rows_where (struct select_stmts *ptr)
{
  char *buff;
  char *buff1;
  buff = acl_malloc2 (strlen (ptr->statement) + 200);	/* We need a little extra space...*/

  return ptr->statement;
  if (ptr->has_where == 0)
    {
      /* There is no where clause currently */
      /*printf("statement=\n%s\nwherepos1=%d\n",ptr->statement,ptr->wherepos1);*/

      strncpy (buff, ptr->statement, ptr->wherepos1);
      buff[ptr->wherepos1] = 0;
      strcat (buff, " WHERE (1=0) ");
      strcat (buff, &ptr->statement[ptr->wherepos1]);
    }
  else
    {
      buff1 = acl_strdup (&ptr->statement[ptr->wherepos1]);
      strncpy (buff, ptr->statement, ptr->wherepos1);
      buff[ptr->wherepos1] = 0;
      strcat (buff, " (1=0) AND ");
      strcat (buff, buff1);
      free (buff1);

    }
  return buff;
}



/**
 *
 * @todo Describe function
 */
int
find_sql_var (int colno)
{
  struct acerep_variable *ptr;
  int a=0;
  int c = 0;
  for (a = 0; a < this_report.variables.variables_len; a++)
    {
      ptr = &this_report.variables.variables_val[a];
      if (ptr->category == CAT_SQL)
	{
	  c++;
	  if (c == colno)
	    return a;
	}
    }
  fprintf(stderr, "Warning - could not find %d\n", a);
  return -1;

}

/**
 *
 * @todo Describe function
 */
void
execute_selects (void)
{
  int a;
  int mx;
  struct select_stmts *ptr;
  void *xi = 0;
  void *xo = 0;
  void *psql;
  int b;
  char nstatement[30000];
  char *cptr;
  int oby_cnt;

  int xic = 0;
  int xoc = 0;

  int colsize;
  int coltype;
  /*char colname[256]; */
  char *colname;
  int vid = 0;

  /* char * nval; */
  void **nvals = 0;

  
  if (columns_method==COLUMNS_METHOD_UNSET) {

	columns_method=COLUMNS_METHOD_DESCRIBE;
	if (strcmp(acl_getenv("COLUMNS_METHOD"),"DESCRIBE")==0) {
		columns_method=COLUMNS_METHOD_DESCRIBE;
	}

	if (strcmp(acl_getenv("COLUMNS_METHOD"),"INTO")==0) {
		columns_method=COLUMNS_METHOD_INTO_TEMP;
	}
  }


  /* printf("Execute selects...\n"); */
  mx = this_report.getdata.get_data_u.selects.selects_len - 1;

  /*
     see stack.c :

     void
     dif_start_bind (void)
     {...

   */
  xi = (void *) dif_start_bind ();
  xo = (void *) dif_start_bind ();


  /* We need 1 null value */
  /* A4GL_setnull (2, &nval, 4); */
  /*  warning: passing arg 2 of `setnull' from incompatible pointer type
     void       A4GL_setnull                         (int type, char *buff, int size);
   */


  for (a = 0; a <= mx; a++)
    {
	char *translated;
      xic = 0;
      xoc = 0;
      ptr = &this_report.getdata.get_data_u.selects.selects_val[a];

      if (a != mx)
	{			/*  this isn't the last SQL  */
	  if (strstr (ptr->statement, " INTO TEMP ") == 0)
	    {
	      /* printf ("%s\n", ptr->statement); */
	      a4gl_ace_yyerror ("An SQL statement which is not the last statement must be into a temporary table");
	    }
	}

      nvals = malloc (sizeof (void *) * ptr->varids.varids_len);

      for (b = 0; b < ptr->varids.varids_len; b++)
	{
	  int varid;
	  int null_dtype;
	  varid = ptr->varids.varids_val[b];
	  switch (this_report.variables.variables_val[varid].datatype & DTYPE_MASK)
	    {
	    case DTYPE_VCHAR:
	    case DTYPE_CHAR:
	      {
		nvals[b] = malloc (10);
		memset (nvals[b], 0, 10);
		A4GL_setnull (DTYPE_CHAR, nvals[b], 1);
		null_dtype = DTYPE_CHAR;
	      }
	      break;

	    default:
	      nvals[b] = malloc (sizeof (long));
	      null_dtype = DTYPE_INT;
	      A4GL_setnull (DTYPE_INT, nvals[b], 4);
	      break;
	    }
	  dif_add_bind (xi, nvals[b], null_dtype, 0);
	  xic++;

	}
      strcpy (nstatement, add_zero_rows_where (ptr));

      if (a == mx && columns_method == COLUMNS_METHOD_INTO_TEMP)
	{
	  strcat (nstatement, " INTO TEMP a4gl_drep1234");
	}

      A4GL_debug ("1");
      A4GL_debug ("Executing select..");
      A4GL_debug ("%s", nstatement);
	translated= A4GLSQL_translate (nstatement);
	printf("%s\n", translated);
      A4GL_debug ("%s", translated);
      psql = (void *) A4GLSQL_prepare_select (dif_get_bind (xi), xic, dif_get_bind (xo), 0, translated, "__internal_data", 1, 0, 0);
      a4gl_status = 0;
      if (psql == 0)
	{
	  printf ("Some error preparing SQL (Error %d)\n", A4GLSQL_get_status ());
	  if (A4GLSQL_get_status () == -217)
	    {
	      printf
		("This can happen if you have not put a $ in front of a variable in a\nselect statement, or if a column does not exist in the listed tables\n");
	    }
	  a4gl_ace_yyerror ("SQL error");
	}



	if ( columns_method == COLUMNS_METHOD_INTO_TEMP) {
      		/* printf("Executing... %s",nstatement); */
      		if (A4GLSQL_execute_implicit_select (psql, 1) != 0)
			{
	  			printf ("Some error executing SQL (Error %d)\n", A4GLSQL_get_status ());
	  			yyerror_sql ("SQL Error");
			}
	}


      if (a == mx)
	{
	  if (columns_method == COLUMNS_METHOD_DESCRIBE) {
		int no_cols;
		int a;
			A4GLSQL_add_prepare("p1_p1",psql);

			if (need_to_open_cursor ) {
				A4GLSQL_declare_cursor(0+0,A4GLSQL_find_prepare("p1_p1"),0,"p1_c1");
				A4GLSQL_open_cursor("p1_c1",0,0);
				if (need_to_open_cursor==2) {
					A4GLSQL_fetch_cursor("p1_c1",2,1,0,0);
				}
			}

			no_cols=A4GLSQL_describe_stmt ("p1_p1", 0, 5);

			if (no_cols==0) {
				printf("Internal error - unable to get number of columns\n");
				exit(3);
				//printf("%s\n", A4GLSQL_describe_stmt ("p1_p1", 1, 0));
			}

			for (a=0;a<no_cols;a++) {
				char buff[200];
				char cname[256];
				char *p;
				int type, scale,len;
				p=(char *)A4GLSQL_describe_stmt ("p1_p1",a+1, 1);
				if (p) {strcpy(cname,p);} else {strcpy(cname,"");}
				A4GL_trim(cname);
				type=A4GLSQL_describe_stmt ("p1_p1", a+1, 0); // 4,5 7
				scale=A4GLSQL_describe_stmt ("p1_p1",a+1, 2); // 4,5 7
				len=A4GLSQL_describe_stmt ("p1_p1", a+1, 3); // 4,5 7
				A4GL_debug("-->%s %d %d %d\n",cname, type,scale,len);
				if (strlen(cname)==0) {
					printf("Internal error - unable to get the name... %s %d %d %d\n",cname, type,scale,len);
				}
				if (!has_sql_variable(cname)) {
		  			ace_add_variable (cname, 0, CAT_SQL, 0, type, scale);
				} else {
					static int dup_cnt=0;
					// Its a duplicate column name
					 sprintf(buff,"a4gl_dup%d_%s",dup_cnt++, cname);
		  			ace_add_variable (buff, 0, CAT_SQL, 0, type, scale);
				}
			}
	  }


	  if (columns_method == COLUMNS_METHOD_INTO_TEMP)
	    {
	      /* This is the last select - we lied a little and forced this
	         into a temporary table too, so that we could easily get
	         at its columns
	       */

	      /* too few arguments to function `A4GLSQL_get_columns'
	         int A4GLSQL_get_columns (char *tabname, char *colname, int *dtype, int *size);

	         if (A4GLSQL_get_columns ("a4gl_drep1234") == 0)
	       */
	      if (A4GLSQL_get_columns ("a4gl_drep1234", "", 0, 0) == 0)
		{
		  a4gl_ace_yyerror ("Unable to get column types for a temporary table");
		}

	      /*
	         passing arg 1 of `A4GLSQL_next_column' from incompatible pointer type
	         int A4GLSQL_next_column(char **colname, int *dtype,int *size); 
	       */
	      while (A4GLSQL_next_column (&colname, &coltype, &colsize))
		{
		  A4GL_trim (colname);
		  ace_add_variable (colname, 0, CAT_SQL, 0, coltype, colsize);
		}
	}

	      /* printf ("ordbycnt=%d\n", ordbycnt); */

	      if (ordbycnt)
		{
		  ptr->orderby_list.orderby_list_len = ordbycnt;
		  ptr->orderby_list.orderby_list_val = acl_malloc2 (sizeof (int) * ordbycnt);
		  for (oby_cnt = 0; oby_cnt < ordbycnt; oby_cnt++)
		    {
		      /* printf("---> %d %d\n",oby_cnt,ordbycnt); */

		      cptr = ordby[oby_cnt];

		      /*
		         printf ("cptr=%p\n", cptr);
		         printf ("cptr=%s\n", cptr);
		       */
		      if (cptr[0] == 'I')
			{
			  vid = find_sql_var (atoi (&cptr[1]));
			  if (vid < 0)
			    {
			      a4gl_ace_yyerror ("Order by column number too high for select statement");
			    }
			}
		      else
			{
			  vid = find_variable (&cptr[1]);
			}

		      ptr->orderby_list.orderby_list_val[oby_cnt] = vid;
		      /* printf("Adding %d to orderby list @ %d\n",vid,oby_cnt); */
		    }
		}
	    }


    }
}

/**
 *
 * @todo Describe function
 */
void
print_variables (char *s)
{
  struct acerep_variable *ptr;
  int a;
  /* printf("---> %s\n",s); */
  for (a = 0; a < this_report.variables.variables_len; a++)
    {
      ptr = &this_report.variables.variables_val[a];
      /* printf("%s\n",ptr->name); */
    }
/* printf("----------------------------------------------------------\n"); */


}


/**
 *
 * @todo Describe function
 */
void
yyerror_sql (char *s)
{
  char buff[256];
  sprintf (buff, "%s - %d", s, (int) a4gl_status);	/*  warning: int format, long int arg (arg 4)
							 */
  a4gl_ace_yyerror (buff);
}


/**
 *
 * @todo Describe function
 */
void
print_lexpr (struct expr_list *l)
{
  printf ("elem_len=%d\n", l->elem.elem_len);
  printf ("elem_val=%p\n", l->elem.elem_val);
}


/* ========================== EOF ================================= */
