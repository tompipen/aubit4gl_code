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
# $Id: util.c,v 1.53 2007-02-26 12:54:10 gyver309 Exp $
#
*/

/**
 * @file
 * This file is #include'd into y.tab.c so we can make a lot of these functions static
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_API_sqlparse_lib.h"
#include "a4gl_libaubit4gl.h"


#ifdef SIMPLIFIED
#include "../4glc/lib4glc/fix_insert.c"
#else
#include "../4glc/fix_insert.c"
#endif
//#include "sqlcompiler.h"



// the maintaners of flex (in their infinite wisdom fixed flex 
// so that the following are properly prefixed in later versions
#ifndef yy_delete_buffer
#define DELETE_BUFFER sqlparse_yy_delete_buffer
#define THEYYWRAP sqlparse_yywrap
#define YYSCANSTRING sqlparse_yy_scan_string
#else
#define DELETE_BUFFER yy_delete_buffer
#define THEYYWRAP yywrap
#define YYSCANSTRING yy_scan_string
#endif

/*
=====================================================================
		                    Variables
=====================================================================
*/

void *nbs = 0;
struct sql_stmt
{
  int type;
  char *val;
};
struct sql_stmt *stmts = 0;
int stmts_cnt = 0;
char last_conversion[256];
char m_module[256] = "unknown";
char m_ln = 0;
int write_std_err_on_error = 0;

/*
=====================================================================
		                    Prototypes
=====================================================================
*/

//extern int yydebug; //y.tab.c:3742: warning: previous declaration of `sqlparse_yydebug'
static void add_sql (int n, char *s);

/*
=====================================================================
		                    Functions definitions
=====================================================================
*/

void dummy_prevent_sqlparse_warnings_dummy (void);
void
dummy_prevent_sqlparse_warnings_dummy (void)
{
  void *dummy;

  //dummy=yy_flex_realloc( 0,0 );
  yyunput (0, 0);

}


#ifdef MOVED
/**
 *
 * @todo Describe function
 */
static char *
pop_gen (int a)
{
  /*printf ("Popgen called\n"); */
  /*printf ("UPDVAL2 cnt = %d\n", gen_stack_cnt[UPDVAL2]); */
  /*dump_updvals(); */
  gen_stack_cnt[a]--;
  return gen_stack[a][gen_stack_cnt[a]];

}

#endif

/**
 *
 * @todo Describe function
 */
static char *
make_sql_string_and_free (char *first, ...)
{
  va_list ap;
  char *ptr = 0;
  int l;
  char *next;
  int n;
/*
  extern char *kw_space;
  extern char *kw_comma;
  extern char *kw_ob;
  extern char *kw_cb;
*/

  n = 0;
  va_start (ap, first);
  ptr = acl_strdup (first);


  if (first != kw_comma && first != kw_space && first != kw_ob
      && first != kw_cb)
    {
      //A4GL_debug("FREE %p (%s)\n",first,first);
      if (A4GL_isyes (acl_getenv ("FREE_SQL_MEM")))
	{
	  free (first);
	}
      first = 0;
    }
  l = strlen (ptr);

  while (1)
    {

      n++;
      next = va_arg (ap, char *);
      if (next == 0)
	break;

      if (next == kw_space || (strlen (next) == 1 && next[0] == ' '))
	{
	  if (ptr[strlen (ptr) - 1] == ' ')
	    continue;
	}

      l += strlen (next);
      l++;			/* Extra space... */
      ptr = realloc (ptr, l);
      strcat (ptr, next);

      if (next != kw_comma && next != kw_space && next != kw_ob
	  && next != kw_cb)
	{
	  //A4GL_debug("FREE %p (%s)\n",next,next);
	  if (A4GL_isyes (acl_getenv ("FREE_SQL_MEM")))
	    {
	      free (next);
	    }
	}
    }
  return ptr;
}


#ifdef MOVED

/**
 *
 * @todo Describe function
 */
void
push_gen (int a, char *s)
{
  A4GL_debug ("Push %d %s - %d\n", a, A4GL_null_as_null (s),
	      gen_stack_cnt[a]);
  /*printf ("Push %d %s - %d\n", a, s,gen_stack_cnt[a]); */
  if (gen_stack_cnt[a] >= GEN_STACK_SIZE)
    {
      printf ("Out of stack!\n");
      exit (77);
    }
  strcpy (gen_stack[a][gen_stack_cnt[a]++], s);
}

/**
 *
 * @todo Describe function
 */
void
copy_gen (int a, int b)
{
  int c;


  if (gen_stack_cnt[a] && gen_stack[a][gen_stack_cnt[a] - 1][0] == '(')
    {
      /*printf ("POP\n"); */
      pop_gen (a);
    }


  for (c = 0; c < gen_stack_cnt[b]; c++)
    {
      A4GL_4glc_push_gen (a, gen_stack[b][c]);
    }
  gen_stack_cnt[b] = 0;
}




/**
 *
 * @todo Describe function
 */
static int
gen_cnt (int a)
{
  return gen_stack_cnt[a];
}

/**
 *
 * @todo Describe function
 */
void
pop_all_gen (int a, char *s)
{
  int z;
  for (z = 0; z < gen_stack_cnt[a]; z++)
    {
      if (z > 0)
	A4GL_debug ("%s ", A4GL_null_as_null (s));

      A4GL_debug ("%s", A4GL_null_as_null (gen_stack[a][z]));
    }
  gen_stack_cnt[a] = 0;
}

#endif

static void
ansi_violation (char *s, int n)
{
}

/**
 *
 * @todo Describe function
 */
static char *
fix_update_expr (int mode)
{
  static char big_buff[20000];
  int a;
  int rval;
  int isize = 0;
  int idtype = 0;
  char colname[256] = "";
  /*char csize[20]; */
  /*char cdtype[20]; */
  char buff[1000];
  char *ccol;
  strcpy (big_buff, "SET ");


  if (mode == 1)
    {
      /* It will only be a '*' anyway.... */
      if (db_used == 0)
	{
	  sprintf (buff,
		   "You cannot use update * =  without specifying a database");
	  sqlparse_yyerror (buff);
	  return 0;
	}

      A4GL_4glc_clr_gen (UPDCOL);
      strcpy (colname, "");
      rval =
	A4GLSQL_get_columns (current_upd_table, colname, &idtype, &isize);
      if (rval == 0)
	{
	  sqlparse_yyerror ("Table is not in the database");
	  A4GLSQL_end_get_columns ();
	  return 0;
	}


      while (1)
	{
	  colname[0] = 0;
	  rval = A4GLSQL_next_column (&ccol, &idtype, &isize);
	  strcpy (colname, ccol);
	  if (rval == 0)
	    break;
	  trim_spaces (colname);
	  A4GL_4glc_push_gen (UPDCOL, colname);
	}
      A4GLSQL_end_get_columns ();
    }

  if (A4GL_4glc_gen_cnt (UPDCOL) != A4GL_4glc_gen_cnt (UPDVAL))
    {
      //dump_updvals();
      printf ("%d!=%d\n", A4GL_4glc_gen_cnt (UPDCOL),
	      A4GL_4glc_gen_cnt (UPDVAL));
      sqlparse_yyerror
	("Number of columns in update not the same as number of values");
    }

  for (a = 0; a < A4GL_4glc_gen_cnt (UPDCOL); a++)
    {
      if (strcmp (A4GL_4glc_get_gen (UPDVAL, a), "?") == 0)
	{
	  A4GL_assertion (1, "Failed");
	}
      if (a)
	strcat (big_buff, ",");
      sprintf (buff, "%s=%s ", A4GL_4glc_get_gen (UPDCOL, a),
	       A4GL_4glc_get_gen (UPDVAL, a));
      strcat (big_buff, buff);
    }

  return big_buff;
}



/**
 *
 * @todo Describe function
 */
static char *
A4GL_get_into_part (int a, int b)
{
  return 0;
}

/**
 *
 * @todo Describe function
 */
static char *
A4GL_get_undo_use (void)
{
  return 0;
}

/**
 *
 * @todo Describe function
 */
static void
A4GL_lex_printcomment (char *fmt, ...)
{
}

/**
 *
 * @todo Describe function
 */
static void
addmap_runtime (char *s, char *f)
{
  char buff[1024];
  sprintf (buff, "%s|%s|%s|%d|%s|", s, f, A4GLSTK_topFunction (), m_ln,
	   m_module);
  A4GL_log_sql_prepared_map (buff);
}

/**
 *
 * @todo Describe function
 */
static int
get_bind_cnt (char i)
{
  return 0;
}

/**
 *
 * @todo Describe function
 */
static int
scan_variable (char *S)
{
// Can't be a variable - we don't have 'em
  return 0;
}

/**
 *
 * @todo Describe function
 */
static int
start_bind (char c, int n)
{
  return 0;
}



/**
 *
 * @todo Describe function
 */
static void
rm_quotes (char *s)
{
  char buff[256];
  int a;
  int b = 0;
  buff[0] = 0;
  for (a = 0; a <= strlen (s); a++)
    {
      if (s[a] != '"')
	{
	  buff[b++] = s[a];
	  buff[b] = 0;
	}
    }
  strcpy (s, buff);
}


/**
 *
 * @todo Describe function
 */
static void
mark_sql_start (void)
{
  this_sql_start = sql_string_cnt + 1;

}




/**
 *
 * @todo Describe function
 */
static char *
get_bad_sql (void)
{
  static char buff[2000];
  memset (buff, 0, 2000);
  if (input_from_file)
    {
      return "BAD SQL";
    }
  else
    {
      if (sql_string_cnt - this_sql_start > 0)
	{
	  strncpy (buff, &Sql[this_sql_start],
		   sql_string_cnt - this_sql_start);
	}
    }
  return buff;
}



/**
 *
 * @todo Describe function
 */
static void
A4GLSQLCV_loadbuffer (char *fname)
{
  if (nbs)
    DELETE_BUFFER (nbs);

  if (strcmp (fname, "-") == 0)
    {
      Sql_file = stdin;
      input_from_file = 1;
    }
  else
    {
      input_from_file = 1;
      Sql_file = fopen (fname, "r");
    }

  if (Sql_file == 0)
    {
      printf ("Unable to open input file\n");
    }

  if (stmts)
    {
      free (stmts);
      stmts = 0;
      stmts_cnt = 0;
    }
  Sql = 0;

}


/**
 *
 * @todo Describe function
 */
static void
A4GLSQLCV_setbuffer (char *s)
{
  if (nbs)
    DELETE_BUFFER (nbs);
  if (Sql)
    free (Sql);
  Sql = acl_strdup (s);
  A4GL_trim (Sql);
  nbs = YYSCANSTRING (Sql);
  if (stmts)
    {
      free (stmts);
      stmts = 0;
      stmts_cnt = 0;
    }
  input_from_file = 0;
  Sql_file = 0;
}

/* andrej
static int meminput(char *buf,int maxsize) {
	if (input_from_file) {
		int a;
		a=fgetc(Sql_file);
		buf[0]=a;
		if (feof(Sql_file)) return 0;
	} else {
		buf[0]=Sql[sql_string_cnt++];
		if (buf[0]==0) return 0;
	}
	return 1;
}
*/



void
set_write_std_err_on_error (void)
{
  write_std_err_on_error = 1;
}

/**
 *
 * @todo Describe function
 */
static int
sqlparse_yyerror (char *s)
{
  if (write_std_err_on_error)
    {
      fprintf (stderr, "%s @ %d\n", s, sqlparse_yylineno);
    }

  A4GL_debug ("%s Sql=%p\n", s, Sql);
  if (Sql)
    {
      char buff[200];
      int c;
      A4GL_debug ("Here\n");
      c = sql_string_cnt;
      c -= 20;
      if (c < 0)
	{
	  c = 0;
	}
      strncpy (buff, &Sql[sql_string_cnt], 199);
      buff[199] = 0;
      A4GL_debug ("MEMREAD syntax error: %s\n", buff);
    }
  was_ok = 0;
  return 0;
}


/**
 *
 * @todo Describe function
 */
static char *
convstrsql (char *s)
{
  if (s[0] == '\'')
    return s;
  return convstr_dbl_to_single (s);
}


/**
 *
 * @todo Describe function
 */
static char *
convstr_dbl_to_single (char *s)
{
  static char buff[1024];
  int a;
  int b = 0;
  A4GL_debug ("Convstrsql ... %s", s);
  for (a = 0; a <= strlen (s); a++)
    {
      if (s[a] == '"')
	{
	  if (a == 0 || (s[a]=='"' && a == strlen (s) - 1))
	    {
	      buff[b++] = '\'';
	    }
	  else
	    {
	      if (s[a - 1] != '\\')
		{
		  buff[b++] = '\'';
		}
	      else
		{
		  buff[b++] = '"';
		}
	    }

	  continue;
	}

      if (s[a] == '\'' && a && a != strlen (s) - 1)
	{
	  buff[b++] = '\'';
	  buff[b++] = '\'';
	  continue;
	}
      buff[b++] = s[a];

    }
  return buff;
}



/**
 *
 * @todo Describe function
 */
//andrej static 
int
THEYYWRAP ()
{
  return 1;
}


/* andrej
static void a4gl_char_cpy(char *dest,char *src,int dbl) {
		strcpy(dest,src);
}
*/



/**
 *
 * @todo Describe function
 */
static void
A4GL_CV_print_exec_sql (char *s)
{
  sql_type = 1;
  if (sql_string)
    sql_string = 0;
  sql_string = acl_strdup (s);
  add_sql (sql_type, sql_string);
}


/**
 *
 * @todo Describe function
 */
static void
A4GL_CV_print_exec_sql_bound (char *s)
{
  sql_type = 2;
  if (sql_string)
    sql_string = 0;
  sql_string = acl_strdup (s);
  add_sql (sql_type, sql_string);
}

/* andrej 
static void print_exec_sql_bound (char *s) {
	add_sql(8,acl_strdup(s));
        free(s);
}
*/

/* andrej 
static void print_set_conn(char *conn) {
char s[256];

	if (A4GLSQLCV_check_requirement("USE_DATABASE_STMT")) {
		sprintf(s,"DATABASE %s",conn);
		sql_type=3;
		if (sql_string) sql_string=0;
		sql_string=acl_strdup(s);
		add_sql(sql_type,sql_string);
	} else {
		sprintf(s,"DATABASE %s",conn);
		sql_type=3;
		if (sql_string) sql_string=0;
		sql_string=acl_strdup(s);
		add_sql(sql_type,sql_string);
	}
}
*/


/**
 *
 * @todo Describe function
 */
static void
print_load (char *fname, char *delim, char *tab, char *cols)
{
  printf ("Load can't be prepared...");
}

/**
 *
 * @todo Describe function
 */
static void
print_load_str (char *fname, char *delim, char *sql)
{
  printf ("Invalid syntax for a prepare statement");
}

/**
 *
 * @todo Describe function
 */
static void
print_sql_commit (int n)
{
  char *s = 0;
  if (n == -1)
    {
      sql_type = 3;
      s = acl_strdup ("BEGIN WORK");
      add_sql (sql_type, s);
    }
  if (n == 0)
    {
      sql_type = 4;
      s = acl_strdup ("ROLLBACK WORK");
      add_sql (sql_type, s);
    }
  if (n == 1)
    {
      sql_type = 5;
      s = acl_strdup ("COMMIT WORK");
      add_sql (sql_type, s);
    }

}



/**
 *
 * @todo Describe function
 */
/* andrej
static void 
print_select_all (char *s) {
	add_sql(6,acl_strdup(s));
    	free(s);
}
*/

/**
 *
 * @todo Describe function
 */
static void
print_exec_sql (char *s)
{
  add_sql (7, acl_strdup (s));
  free (s);
}

/**
 *
 * @todo Describe function
 */
static void
print_exec_select (char *s)
{
  add_sql (9, acl_strdup (s));
  free (s);
}



/**
 *
 * @todo Describe function
 */
static void
print_undo_use (char *s)
{
  printf ("Invalid in prepare");
}

/**
 *
 * @todo Describe function
 */
static void
print_unload_g (char *f, char *d, char *sql,void *binding)
{
}

/**
 *
 * @todo Describe function
 */
static void
print_use_session (char *s)
{
}


/**
 *
 * @todo Describe function
 */
static void
conn_db (char *s)
{
  char buff[256];
  if (A4GLSQLCV_check_requirement ("USE_DATABASE_STMT"))
    {
      sprintf (buff, "DATABASE %s", s);
      add_sql (10, acl_strdup (buff));
    }
  else
    {
// Fixme? ecpg 8.1.5
      sprintf (buff, "CONNECT TO  %s AS 'default'", s);
      add_sql (10, acl_strdup (buff));
    }
}

/**
 *
 * @todo Describe function
 */
static void
print_unable_to_parse ()
{
  char *s;
  s = get_bad_sql ();
  add_sql (11, acl_strdup (s));

}


/**
 *
 * @todo Describe function
 */
static void
add_sql (int n, char *s)
{
  static int last_was_err = 0;
  static char *last_s = 0;

  if (n == -1)
    {
      last_s = 0;
      return;
    }
  if (n != 11)
    {
      if (last_was_err && last_s)
	{
	  last_was_err = 0;
	  add_sql (12, last_s);
	  last_was_err = 0;
	}
      if (stmts == 0)
	{
	  stmts_cnt = 0;
	}

      stmts_cnt++;
      stmts = realloc (stmts, sizeof (struct sql_stmt) * stmts_cnt);
      stmts[stmts_cnt - 1].type = n;
      stmts[stmts_cnt - 1].val = s;
      mark_sql_start ();
    }
  else
    {
      last_was_err = 1;
      last_s = s;
    }


}



/**
 *
 * @todo Describe function
 */
static char *
A4GLSQLCV_convert_sql_internal (char *source_dialect, char *target_dialect,
				char *sql, int from_file)
{
  char buff[255];
  int a;
  static char *ptr = 0;
  int l;
  add_sql (-1, "");
  if (A4GL_isyes (acl_getenv ("YYDEBUG")))
    {
      yydebug = 1;
    }

  A4GL_debug ("A4GLSQLCV_convert_sql_internal %s %s %s %d", source_dialect,
	      target_dialect, sql, from_file);

  sprintf (buff, "%s_%s", source_dialect, target_dialect);
  if (strcmp (last_conversion, buff) != 0)
    {
      A4GLSQLCV_load_convert (source_dialect, target_dialect);
      strcpy (last_conversion, buff);
    }


  if (from_file)
    {
      A4GLSQLCV_loadbuffer (sql);
    }
  else
    {
      if (A4GL_isyes (acl_getenv ("YYDEBUG")))
	{
	  fprintf (stderr, "SQL:%s\n", sql);
	}
      A4GLSQLCV_setbuffer (sql);
    }

  A4GL_debug ("stmts=%p stmts_cnt=%d Sql=%s", stmts, stmts_cnt, Sql);

  if (A4GLSQLCV_process ())
    {
      if (A4GL_isyes (acl_getenv ("YYDEBUG")))
	{
	  fprintf (stderr, "Success\n");
	}
      A4GL_set_sql_conv (1);
      // All ok !
      A4GL_debug ("SQL processed OK (%d statements)", stmts_cnt);
    }
  else
    {
      A4GL_set_sql_conv (0);
      if (A4GL_isyes (acl_getenv ("YYDEBUG")))
	{
	  fprintf (stderr, "Error\n");
	}
      // Some sql error....
      A4GL_debug ("Possible issue with the SQL", stmts_cnt);
      if (from_file)
	return "<err>";
      else
      {
	  if (A4GL_isyes(acl_getenv("EXIT_ON_BAD_SQL")))
	  {
	      A4GL_debug("Bad SQL: %s", sql);
	      A4GL_set_errm(sql);
	      A4GL_exitwith("Bad SQL: %s");
	  }
	return sql;
      }

    }

  l = 0;
  if (ptr)
    {
      free (ptr);
    }
  ptr = 0;
  if (stmts_cnt == 0)
    return "";
  for (a = 0; a < stmts_cnt; a++)
    {
      l += strlen (stmts[a].val) + 1;
      if (a + 1 != stmts_cnt)
	l += 2;
      if (ptr == 0)
	{
	  ptr = malloc (l);
	  strcpy (ptr, "");
	}
      else
	{
	  ptr = realloc (ptr, l);
	}
      A4GL_debug ("Statement %d = %s", a, stmts[a].val);
      strcat (ptr, stmts[a].val);
      if (a + 1 != stmts_cnt)
	strcat (ptr, ";\n");
    }

  A4GL_debug ("-->%s\n", ptr);
  return ptr;
}


/**
 *
 * @todo Describe function
 */
char *
A4GLPARSE_A4GLSQLCV_convert_sql_ml (char *target_dialect, char *sql,
				    char *module, int ln)
{
  char *ptr;
  sql = acl_strdup (sql);
  strcpy (m_module, module);
  m_ln = ln;
  A4GL_logsql (ln, module, sql);
  ptr = A4GLSQLCV_convert_sql_internal ("INFORMIX", target_dialect, sql, 0);
  if (ptr != sql)
    free (sql);
  strcpy (m_module, "unknown");
  m_ln = 0;
  return ptr;
}


/**
 *
 * @todo Describe function
 */
char *
A4GLPARSE_A4GLSQLCV_convert_file (char *target_dialect, char *sql)
{
  return A4GLSQLCV_convert_sql_internal ("INFORMIX", target_dialect, sql, 1);
}

/**
 *
 * @todo Describe function
 */
static int
A4GLSQLCV_process (void)
{
  was_ok = 1;
  sql_string_cnt = 0;
  this_sql_start = 0;
  if (Sql_file)
    {
      sqlparse_yyin = Sql_file;
    }
  sqlparse_yyparse ();
  return was_ok;
}



/**
 *
 * @todo Describe function
 */
void
A4GL_add_feature (char *feature)
{
  /* Reserved for future use */
}

//opbsolte note - remove:
/* prototype is in API_sqlparse.c that is generated by dlmagic - it should be
 in a header file so we can include it here, instead duplication the prototype */
//int A4GLSQLPARSE_initlib (void);
/**
 *
 * @todo Describe function
 */
int
A4GLPARSE_SQLPARSE_initlib (void)
{
  return 0;
}

/**
 *
 * @todo Describe function
 */
char *
A4GLSQLCV_generate_ins_string (char *current_ins_table, char *s)
{
  char buff[40000];
  if (A4GLSQLCV_check_requirement ("FULL_INSERT"))
    {
      char *p;
      if (strstr (s, " VALUES "))
	{
	  p = fix_insert_expr (1);
	  if (p)
	    {
	      sprintf (buff, "INSERT INTO %s %s", current_ins_table, p);
	      free (s);
	    }
	  else
	    {
	      sprintf (buff, "%s", s);
	    }
	  return acl_strdup (buff);
	}
    }
  return s;

}






int
A4GL_db_used (void)
{
  return db_used;
}

int
A4GL_cursor_current (char *s)
{
  return 0;
}


void
do_yyerror (char *s)
{
  sqlparse_yyerror (s);
}


int
A4GL_4glc_push_gen_expand (int n, char *v)
{
  A4GL_4glc_push_gen (n, v);
  return 1;
}

void
add_sql_function (char *s)
{
  FILE *f;
    if (A4GL_isyes(acl_getenv("LOGSQLFUNCTIONS"))) {
  f = fopen ("/tmp/sqlcall.log", "a");
  if (!f)
    return;
  fprintf (f, "%s SQLCOMPILE\n", s);
  fclose (f);
    }

}

void
A4GL_warn (char *s)
{
  // Does nothing
}


void
addmap (char *t, char *s, char *w, int l, char *m) {
// Does nothing but is required...
}


void map_select_stmt (char *main_statement_type, struct s_select *select) {
}

void
map_delete_update (char *main_statement_type, char *table, struct s_select_list_item *i)
{
}


void *copy_togenbind(char c) {
	return 0;
}

void fail_on_select_ibind(void) {
}

void map_create_temp(char *tab, char *src) {
}

int set_ignore_indicators(void) {
	// required ...
}

int clr_ignore_indicators(void) {
	// required ...
}
/* ====================================== EOF ============================ */
