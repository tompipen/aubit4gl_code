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
# $Id: sqlconvert.c,v 1.165 2009-04-08 08:36:41 mikeaubury Exp $
#
*/

#include "a4gl_libaubit4gl_int.h"

/*
=====================================================================
                          Definitions
=====================================================================
*/
#include <ctype.h>
#include <string.h>

#define isquote(x) ((x)=='\"'||(x)=='\'')
#define istabcol(x) (isalnum(x)||(x)=='.'||(x)=='_')
#define iswordch(x) (isalnum(x)||(x)=='_')
#define iscmpop(x) ((x)=='='||(x)=='!'||(x)=='>'||(x)=='<')
#define isoperator(x)  (a_strchr("+-*/%|^[,]",(x)) != NULL)
static char *get_dollared_sql_var (char *s);
static char *A4GL_cv_next_token (char *p, int *len, int dot);
static char *A4GL_space_out (char *s);
int is_compile_time_convert = 1;
char lastFieldData[256] = "";

/*
=====================================================================
                    Variable definitions
=====================================================================
*/

/* struct to hold list of functions from conversion file(s) */
/* empty string that can be pointed to */
char empty[] = "";
char *CV_matches (char *typ, char *string, char *esc);
static int set_sql_conv_success;
int is_sqlserver_reserved_word (char *s);
static void load_column_mappings_i (char *ptr);
static void load_table_mappings_i (char *ptr);
char fake_rowid_column[256];
static int loaded_columns = 0;
void chk_loaded_mappings (void);
static char *A4GLSQLCV_datetime_value_internal (char *s, char *from, char *to);
static char *A4GLSQLCV_interval_value_internal (char *s, char *from, char *to);

int if_stack[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int if_stack_cnt = 0;

static int match_strncasecmp (char *s1, char *s2, int len);
#include "generated/sql_convert_constants.h"

enum cond_conditions
{
  COND_NOT_SET,
  INT_EQ,
  INT_NE,
  INT_LE,
  INT_GE,
  INT_LT,
  INT_GT,
  STR_EQ,
  STR_NE,
  STR_LE,
  STR_GE,
  STR_LT,
  STR_GT,
};


struct s_replace
{
  char *from;
  char *to;
};

struct cvsql_data
{
  enum cvsql_type type;
  struct s_replace data;

};



struct cvsql_data *current_conversion_rules = 0;
int current_conversion_rules_cnt = 0;


struct table_remap
{
  char *orig_db;
  char *orig_instance;
  char *tabname;
  char *newtabname;
};

struct table_remap *table_mappings = 0;
int ntable_mappings = 0;

struct column_remap
{
  char *tabname;
  char *from_col;
  char *to_col;
};

struct column_remap *column_mappings = 0;
int ncolumn_mappings = 0;

/*
=====================================================================
                    Function prototypes
=====================================================================
*/

static void A4GL_cv_fnlist (char *source, char *target, char *name);
//int A4GL_cv_str_to_func (char *p, int len,int warnifnotfound);
int A4GL_strwscmp (char *a, char *b);
//int A4GL_strcasestr (char *h, char *n);
//void A4GL_cvsql_replace_str (char *buff, char *from, char *to);

void A4GL_cvsql_double_single (char *sql, char *args);
/* void A4GL_cvsql_rowid (char *sql, char *oid); */
void A4GL_cvsql_split_update (char *sql, char *args);
void A4GL_cvsql_matches_like (char *sql, char *args);
void A4GL_cvsql_matches_regex (char *sql, char *args);
void A4GL_cvsql_matches (char *sql, char *typ);
void A4GL_cvsql_substring (char *sql, char *func);
void A4GL_cvsql_tab_alias (char *sql, char *args);
void A4GL_cvsql_col_alias (char *sql, char *args);
void A4GL_cvsql_replace (char *sql, char *args);

char *A4GL_cv_nth_list_item (char *p, int n, int *len);
char *A4GL_cv_find_token (char *p, char *str, int skipb);
char *A4GL_cv_find_closing (char *p);
int A4GL_cv_num_tokens (char *p);
char *A4GL_cv_nth_token (char *p, int n, int *len);
//char *A4GL_cv_next_token (char *p, int *len, int dot);
int A4GL_cv_is_clause_word (char *p, int len);
void A4GL_cv_replacestr (char *p, int n, char *s);
void A4GL_cv_inschstr (char *p, char c);
void A4GL_cv_delchstr (char *p, int n);
char *A4GL_cv_unqstrstr (char *str, char *word);
char *A4GL_cv_lastnonblank (char *str);

long last_cnt = 0;

struct save_queries
{
  char *fromsql;
  char *tosql;
  int last_cnt;
};

int init_saved_queries = 1;


#define NUM_SAVED_QUERIES 100

struct save_queries saved_queries[NUM_SAVED_QUERIES];


/*
=====================================================================
                    Function definitions
=====================================================================
*/


static void
do_init_saved_queries (void)
{
  int a;
  init_saved_queries = 0;
  for (a = 0; a < NUM_SAVED_QUERIES; a++)
    {
      saved_queries[a].fromsql = 0;
      saved_queries[a].tosql = 0;
      saved_queries[a].last_cnt = -1;
    }
}




static void
add_query (char *fromsql, char *tosql)
{
  int a;
  int low_cnt = -1;
  int low_cnt_a = -1;
  for (a = 0; a < NUM_SAVED_QUERIES; a++)
    {
      if (saved_queries[a].fromsql == 0)
	{
	  saved_queries[a].fromsql = acl_strdup (fromsql);
	  saved_queries[a].tosql = acl_strdup (tosql);
	  saved_queries[a].last_cnt = last_cnt++;
	  return;
	}
      if (low_cnt == -1 || saved_queries[a].last_cnt < low_cnt)
	{
	  low_cnt = saved_queries[a].last_cnt;
	  low_cnt_a = a;
	}
    }
  A4GL_assertion (low_cnt_a == -1, "Ooops");
  A4GL_assertion (low_cnt == -1, "Ooops");

  acl_free (saved_queries[low_cnt_a].fromsql);
  acl_free (saved_queries[low_cnt_a].tosql);
  saved_queries[low_cnt_a].fromsql = acl_strdup (fromsql);
  saved_queries[low_cnt_a].tosql = acl_strdup (tosql);
  saved_queries[low_cnt_a].last_cnt = last_cnt++;
}





static int
has_query (char *s, char **cp)
{
  int a;
  if (init_saved_queries)
    {
      do_init_saved_queries ();
      return 0;
    }

  for (a = 0; a < NUM_SAVED_QUERIES; a++)
    {
      if (saved_queries[a].fromsql == 0)
	continue;

      if (strcmp (saved_queries[a].fromsql, s) == 0)
	{
	  saved_queries[a].last_cnt = last_cnt++;
	  *cp = saved_queries[a].tosql;
	  return 1;
	}
    }
  return 0;
}


char *
A4GL_convert_sql_new (char *source_dialect, char *target_dialect, char *sqlx, int converted)
{
  char *sql_new;
  char *sql;
  int cache;
char *sql_duped;
  //int converted=0;

  //int a;
  sql = sqlx;
sql_duped=acl_strdup(sqlx);
  A4GL_debug ("A4GL_convert_sql_new : %s", sql);

  cache = A4GL_isyes (acl_getenv ("A4GL_DISABLE_QUERY_CACHE")) ? 0 : 1;
  if (cache && has_query (sqlx, &sql_new))
    {
      return sql_new;
    }

  if (strcmp (source_dialect, target_dialect) == 0 && (!A4GL_isyes (acl_getenv ("ALWAYS_CONVERT"))))
    {
      return sql;
    }

  if (A4GLSQLCV_check_requirement ("NEVER_CONVERT"))
    {
      return sql;
    }



  // Silently drop source dialect for now - it should be picked up from A4GL_SQLDIALECT anyway...
  //
  A4GL_debug ("sql=%s\n", sql);

  sql = acl_strdup (sqlx);

  A4GL_trim (sql);

  if (strlen (sql))
    {
      sql_new = A4GLSQLCV_convert_sql (target_dialect, sql);

      if (sql_new == 0)
	{
	  A4GL_assertion (1, "Failed to convert SQL (1)");
	}

      A4GL_debug ("Translates to %s", sql_new);
      if (converted != 1)
	{
	  sql_new = A4GLSQLCV_check_sql (sql_new, &converted);
	}
      if (sql_new == 0)
	{
	  A4GL_assertion (1, "Failed to convert SQL (2)");
	}
    }
  else
    {
      sql_new = "";
    }
  //for (a=0;a<strlen(sql_new);a++) { if (sql_new[a]=='\n') sql_new[a]=' '; }
  A4GL_debug ("check_sql.. %s", sql_new);

  if (cache) {
    add_query (sql_duped, sql_new);
  }
  acl_free (sql);
acl_free(sql_duped);
  return sql_new;
}



/*
 * Returns the next token string in a statement
 *
 * @param  p    pointer into SQL statement string
 * @param  *n   points to an int that'll hold the token length
 * @param  dot  treat dot (.) as a separate token
 */
static char *
A4GL_cv_next_token (char *p, int *len, int dot)
{
  char *p2;
  int slash = 0;

  // ignore whitespace
  while (*p > 0 && isspace (*p))
    p++;

  if (*p == '\0')
    {
      if (len > 0)
	*len = 0;
      return (char *) 0;
    }

  p2 = p + 1;

  if (isquote (*p))
    {
      /* starts with a quote, look for (unescaped) closing quote */
      for (; *p2 > 0; p2++)
	{
	  if (slash)
	    {
	      slash--;
	    }
	  else
	    {
	      if (*p2 == '\\')
		{
		  slash++;
		  continue;
		}
	    }
	  if (*p2 == *p)
	    {
	      p2++;
	      break;
	    }
	}
    }
  else
    {
      if (iscmpop (*p))
	{
	  /* comp. operator sequence ( >, >=, !=, ... ) */
	  while (*p2 > 0 && iscmpop (*p2))
	    p2++;
	}
      else
	{
	  /* any sequence comprising table, keyword, number, etc. */
	  if (dot)
	    {
	      if (iswordch (*p))
		{
		  while (*p2 > 0 && iswordch (*p2))
		    p2++;
		}
	    }
	  else
	    {
	      if (istabcol (*p))
		{
		  while (*p2 > 0 && istabcol (*p2))
		    p2++;
		}
	    }
	}
    }
  /* note, if none of the above, then we return a single char
   */
  if (len > 0)
    *len = p2 - p;
  return p;
}

/*
 * Converts an SQL command string written for a specific DBMS to
 * a format acceptable to another target DBMS.
 * 
 * @param  source   SQL dialect statement is written in
 * @param  target   SQL dialect understood by the DBMS
*/
void
A4GLSQLCV_load_convert (char *source_dialect, char *target_dialect)
{
  char buff[256];
//void *p=0;

  SPRINTF2 (buff, "%s_%s", source_dialect, target_dialect);
  A4GL_debug ("Load convert : %s %s", source_dialect, target_dialect);

  if (!A4GL_isno (acl_getenv ("COMPILETIMEFIX")))
    {
      // The following function will return 0 
      // IFF - we're compiling 
      //       AND we're not compiling to ESQL/C code
      if (!A4GL_compile_time_convert ())
	return;
    }
  if (!A4GL_has_pointer (buff, SQL_CONVERSION))
    {
      A4GL_cv_fnlist (source_dialect, target_dialect, buff);
    }


  current_conversion_rules = A4GL_find_pointer (buff, SQL_CONVERSION);
  current_conversion_rules_cnt = (long) A4GL_find_pointer (buff, SQL_CONVERSION_CNT);
}



static FILE *
cnfopen (char *path, char *buff_sm)
{
  FILE *f;
  char buff[512];
  SPRINTF2 (buff, "%s%s", path, buff_sm);
  A4GL_debug ("Trying to cnfopen %s", buff);
  f = fopen (buff, "r");
  A4GL_debug ("Trying to cnfopen %s - f=%p", buff, f);
  return f;
}


static void
read_conversion_file (FILE * fh, char *name)
{
  char buff[201];
  char *t;
  int len;
  int line = 0;
  char thisline[2000];
int sz;
  static struct cvsql_data *conversion_rules = 0;
  static int conversion_rules_cnt = 0;


  /* each line of the file consists of a function name and
   * optional arguments.  Ignore lines starting with "#".
   */
  while (fgets (buff, 200, fh))
    {
      line++;
      if ((t = A4GL_cv_next_token (buff, &len, 0)) == NULL)
	continue;
      if (*t == '#')
	continue;

      SPRINTF2 (thisline, "File %s Line : %d ", name, line);
//printf("t=%s len=%d\n",t,len);
      if (strncmp (t, "IF", len) == 0)
	{
	  char ptest[200] = "<notset>";
	  char pval[200] = "<notset>";
	  char *p1;
	  enum cond_conditions cond = COND_NOT_SET;
	  int ok = 0;
	  t += len;
	  while (*t == ' ')
	    {
	      t++;
	    }
	  // Lets split the IF into its component parts..
	  p1 = A4GL_cv_next_token (t, &len, 0);
	  if (p1 == 0)
	    {
	      FPRINTF (stderr, "%s\n", thisline);
	      A4GL_assertion (1, "Invalid condition in convertion file IF");
	    }
	  strncpy (ptest, p1, len);
	  ptest[len] = 0;
	  t += len;
	  while (*t == ' ')
	    t++;
	  t = A4GL_cv_next_token (t, &len, 0);

	  // String comparisions
	  if (t && len == 1 && strncmp (t, "=", 1) == 0)
	    {
	      cond = STR_EQ;
	      p1 = A4GL_cv_next_token ((t + len), &len, 0);
	    }
	  if (t && len == 1 && strncmp (t, "<", 1) == 0)
	    {
	      cond = STR_LT;
	      p1 = A4GL_cv_next_token ((t + len), &len, 0);
	    }
	  if (t && len == 1 && strncmp (t, ">", 1) == 0)
	    {
	      cond = STR_GT;
	      p1 = A4GL_cv_next_token ((t + len), &len, 0);
	    }

	  if (t && len == 2 && (strncmp (t, "!=", 1) == 0 || strncmp (t, "<>", 1) == 0))
	    {
	      cond = STR_NE;
	      p1 = A4GL_cv_next_token ((t + len), &len, 0);
	    }

	  if (t && len == 2 && (strncmp (t, ">=", 1) == 0))
	    {
	      cond = STR_GE;
	      p1 = A4GL_cv_next_token ((t + len), &len, 0);
	    }
	  if (t && len == 2 && (strncmp (t, "<=", 1) == 0))
	    {
	      cond = STR_LE;
	      p1 = A4GL_cv_next_token ((t + len), &len, 0);
	    }

	  // Integer comparisons
	  if (t && len == 2 && (strncmp (t, "eq", 1) == 0))
	    {
	      cond = INT_EQ;
	      p1 = A4GL_cv_next_token ((t + len), &len, 0);
	    }
	  if (t && len == 2 && (strncmp (t, "ne", 1) == 0))
	    {
	      cond = INT_NE;
	      p1 = A4GL_cv_next_token ((t + len), &len, 0);
	    }
	  if (t && len == 2 && (strncmp (t, "ge", 1) == 0))
	    {
	      cond = INT_GE;
	      p1 = A4GL_cv_next_token ((t + len), &len, 0);
	    }
	  if (t && len == 2 && (strncmp (t, "gt", 1) == 0))
	    {
	      cond = INT_GT;
	      p1 = A4GL_cv_next_token ((t + len), &len, 0);
	    }
	  if (t && len == 2 && (strncmp (t, "le", 1) == 0))
	    {
	      cond = INT_LE;
	      p1 = A4GL_cv_next_token ((t + len), &len, 0);
	    }
	  if (t && len == 2 && (strncmp (t, "lt", 1) == 0))
	    {
	      cond = INT_LT;
	      p1 = A4GL_cv_next_token ((t + len), &len, 0);
	    }

	  if (cond == COND_NOT_SET)
	    {
	      FPRINTF (stderr, "%s\n", thisline);
	      FPRINTF (stderr, "Got : %s, expecteding <,>, =,>=,<=,!=, <>, ne, eq, ge, gt,lt,lr\n", t);
	      A4GL_assertion (1, "No valid condition on an IF when reading conversion file");
	      return;
	    }
	  strncpy (pval, p1, len);
	  pval[len] = 0;

	  if (strcmp (pval, "<notset>") == 0)
	    {
	      FPRINTF (stderr, "%s\n", thisline);
	      A4GL_assertion (1, "Invalid condition in convertion file IF");
	      return;
	    }

	  ok = 0;
	  switch (cond)
	    {
	    case STR_EQ:
	    case STR_NE:
	    case STR_GT:
	    case STR_LT:
	    case STR_GE:
	    case STR_LE:

	      // Test for equality ...
	      if (A4GL_cv_str_to_func (ptest, strlen (ptest), 0) && A4GLSQLCV_check_requirement (ptest))
		{
		  if (A4GL_isyes (pval))
		    {

		      ok = 1;
		    }
		  else
		    {
		      ok = 0;
		    }
		  if (cond == STR_NE)
		    {
		      ok = !ok;
		    }
		}
	      else
		{
		  int comp;
		  comp = strcmp (acl_getenv (ptest), pval);
		  if (cond == STR_EQ)
		    ok = (comp == 0);
		  if (cond == STR_NE)
		    ok = (comp != 0);
		  if (cond == STR_LT)
		    ok = (comp < 0);
		  if (cond == STR_LE)
		    ok = (comp <= 0);
		  if (cond == STR_GT)
		    ok = (comp > 0);
		  if (cond == STR_GE)
		    ok = (comp >= 0);
		}
	      break;
	    case INT_EQ:
	    case INT_NE:
	    case INT_GT:
	    case INT_LT:
	    case INT_GE:
	    case INT_LE:
	      {
		int t1;
		int t2;
		t1 = atoi (acl_getenv (ptest));
		t2 = atoi (pval);
		if (cond == INT_EQ)
		  ok = (t1 == t2);
		if (cond == INT_NE)
		  ok = (t1 != t2);
		if (cond == INT_LT)
		  ok = (t1 < t2);
		if (cond == INT_LE)
		  ok = (t1 <= t2);
		if (cond == INT_GT)
		  ok = (t1 > t2);
		if (cond == INT_GE)
		  ok = (t1 >= t2);
	      }
	      break;
	    default:
	      FPRINTF (stderr, "%s\n", thisline);
	      A4GL_assertion (1, "SHould not happen");

	    }


	  A4GL_debug ("%s %d %s, %d", ptest, cond, pval, ok);
	  // Add it to our if stack...
	  if_stack[if_stack_cnt++] = ok;
	  continue;
	}

      if (strncmp (t, "ELSE", len) == 0)
	{
	  if_stack[if_stack_cnt - 1] = !if_stack[if_stack_cnt - 1];
	  continue;
	}

      if (strncmp (t, "ENDIF", len) == 0)
	{
	  if_stack_cnt--;
	  if (if_stack_cnt < 0)
	    {
	      FPRINTF (stderr, "%s\n", thisline);
	      A4GL_assertion (1, "IF stack confused while reading conversion file");
	    }
	  continue;
	}



      if (if_stack_cnt > 0)
	{
	  int a;
	  int ok = 1;
	  for (a = 0; a < if_stack_cnt; a++)
	    {
	      if (if_stack[a] == 0)
		{
		  ok = 0;
		  break;
		}
	    }
	  if (!ok)
	    continue;		// Get the next line - we're not processing this one..
	}
      if (strncmp (t, "PRINT", len) == 0)
	{
	  char *p1;
	  p1 = strchr (t, ' ');
	  if (p1)
	    {
	      PRINTF ("SQLCONVERT (%s): %s\n", thisline, p1);
	    }
	  continue;
	}

      if (strncmp (t, "DEBUG", len) == 0)
	{
	  char *p1;
	  p1 = strchr (t, ' ');
	  if (p1)
	    {
	      A4GL_debug ("SQLCONVERT (%s): %s\n", thisline, p1);
	    }
	  continue;
	}

      if (strncmp (t, "INCLUDE", len) == 0)
	{
	  char buff_sm[2000];
	  char path[2000];
	  FILE *fh_new;
	  char *p1;
	  t += len;
	  while (*t == ' ')
	    {
	      t++;
	    }
	  p1 = A4GL_cv_next_token (t, &len, 0);
	  A4GL_trim (p1);

	  // first - lets try an explicit file in the DBPATH
	  fh_new = A4GL_open_file_dbpath (p1);
	  if (!fh_new)
	    {			// Explicit file ? 
	      SPRINTF1 (path, "%s/convertsql", acl_getenv ("AUBITETC"));
	      fh_new = cnfopen (path, p1);
	    }
	  if (!fh_new)
	    {
	      SPRINTF1 (path, "%s/etc/convertsql", acl_getenv ("AUBITDIR"));
	      fh_new = cnfopen (path, p1);
	    }
	  if (!fh_new)
	    {			// Let try again - but we'll stick .cnv on the end...
	      strcpy (buff_sm, p1);
	      strcat (buff_sm, ".cnv");
	      SPRINTF1 (path, "%s/convertsql", acl_getenv ("AUBITETC"));
	      fh_new = cnfopen (path, buff_sm);
	    }
	  if (!fh_new)
	    {
	      SPRINTF1 (path, "%s/etc/convertsql", acl_getenv ("AUBITDIR"));
	      fh_new = cnfopen (path, buff_sm);
	    }
	  if (!fh_new)
	    {
	      FPRINTF (stderr, "%s\n", thisline);
	      FPRINTF (stderr, "FILE : %s\n", p1);
	      A4GL_assertion (1, "Unable to open sql convertion file used in an INCLUDE");
	    }
	  // If we get to here - we should be ok to read the file...
	  read_conversion_file (fh_new, name);	// It'll be closed by the time we get back...
	  continue;
	}



      conversion_rules_cnt++;
	//printf("Malloc : %d\n",sz);
	sz=sizeof (conversion_rules[0]) * conversion_rules_cnt;
      conversion_rules = acl_realloc (conversion_rules, sz);



      conversion_rules[conversion_rules_cnt - 1].type = A4GL_cv_str_to_func (t, len, 1);
      conversion_rules[conversion_rules_cnt - 1].data.from = 0;
      conversion_rules[conversion_rules_cnt - 1].data.to = 0;
      if (t)
	{
	  A4GL_debug ("Loaded convertion ---> %d %s\n",
		      conversion_rules[conversion_rules_cnt - 1].type,
		      cvsql_names[conversion_rules[conversion_rules_cnt - 1].type]);
	}
      A4GL_trim (t);
      /* get the argument list, A4GL_strip off leading = sign */
      t += len;
      t = A4GL_cv_next_token (t, &len, 0);

      if (t && len == 1 && *t == '=')
	{
	  t = A4GL_cv_next_token ((t + len), &len, 0);
	}

      if (t)
	{
	  char *left;
	  char *right;
	  char xx[256];

	  len = strlen (t);
	  while (len > 0 && isspace (t[len - 1]))
	    len--;


	  if (len > 0)
	    {
	      strncpy (xx, t, 255);
	      xx[255] = 0;
	      left = &xx[0];
	      right = strchr (xx, '=');


	      if (right)
		{
		  *right = 0;
		  right++;
		  while (*right == '=' || *right == ' ' || *right == '\t')
		    right++;
		  A4GL_trim (right);
		  conversion_rules[conversion_rules_cnt - 1].data.to = acl_strdup (right);
		}
	      else
		{
		  conversion_rules[conversion_rules_cnt - 1].data.to = 0;
		}
	      A4GL_trim (left);
	      conversion_rules[conversion_rules_cnt - 1].data.from = acl_strdup (left);
	    }
	}


    }
  if (if_stack_cnt != 0)
    {
      FPRINTF (stderr, "%s\n", thisline);
      A4GL_assertion (1, "IF stack corrupted");
    }

  fclose (fh);

  A4GL_add_pointer (name, SQL_CONVERSION, (void *) conversion_rules);
  A4GL_add_pointer (name, SQL_CONVERSION_CNT, (void *) conversion_rules_cnt);	// 64Bit OK

  return;
}


static void
A4GL_cv_fnlist (char *source, char *target, char *name)
{
  char path[201];
  char buff_sm[201];
  FILE *fh;


  SPRINTF2 (buff_sm, "/%s-%s.cnv", source, target);


  strcpy (path, acl_getenv ("SQLCNVPATH"));
  fh = cnfopen (path, buff_sm);
  if (!fh)
    {

      //if (buff[0] == '\0') {
#ifdef SIMPLIFIED
      SPRINTF1 (path, "%s", DATADIR);
#else
      SPRINTF1 (path, "%s/convertsql", acl_getenv ("AUBITETC"));
      fh = cnfopen (path, buff_sm);
      if (!fh)
	{
	  SPRINTF1 (path, "%s/etc/convertsql", acl_getenv ("AUBITDIR"));
	  fh = cnfopen (path, buff_sm);
	}
#endif
      //}
    }



  if (fh == NULL)
    {
      A4GL_debug ("failed to open file");
      return;			/* NULL */
    }

  read_conversion_file (fh, name);
}



char *A4GLSQLCV_get_esql_datatype(int dtype,char dir) {
char sbuff[200];
int b;

 // Do we have a specific one for our direction ? 
  
if (dir=='o') { sprintf(sbuff,"OUT_%x",dtype); } 
if (dir=='i') { sprintf(sbuff,"IN_%x",dtype); } 

  for (b = 0; b < current_conversion_rules_cnt; b++)
    {
      if (current_conversion_rules[b].type == CVSQL_ESQL_DATATYPE)
	{
	  if (A4GL_strwscmp (sbuff, current_conversion_rules[b].data.from) == 0)
	    {
		return current_conversion_rules[b].data.to;
	    }
	}
    }


// Nope - what about a non-specific one ? 
  sprintf(sbuff,"%x",dtype);

  for (b = 0; b < current_conversion_rules_cnt; b++)
    {
      if (current_conversion_rules[b].type == CVSQL_ESQL_DATATYPE)
	{
	  if (A4GL_strwscmp (sbuff, current_conversion_rules[b].data.from) == 0)
	    {
		return current_conversion_rules[b].data.to;
	    }
	}
    }



return NULL;
}


//
// This is a workshy version of the SQL parsing stuff - 
// it will be called from the main SQL parser to do the final tidying up....
//
char *
A4GLSQLCV_check_sql (char *s, int *converted)
{
  int b;
  static char *buff = 0;
  char *ptr = 0;
  A4GL_assertion (s == 0, "No pointer");
  A4GL_debug ("check sql : %s\n", s);
  *converted = 1;
	if (buff) {
		acl_free(buff);
		buff=0;
	}
  for (b = 0; b < current_conversion_rules_cnt; b++)
    {
      if (current_conversion_rules[b].type == CVSQL_REPLACE_COMMAND)
	{

	  if (A4GL_strwscmp (s, current_conversion_rules[b].data.from) == 0)
	    {
	      static char buff[2000] = "";
	      char *ptr;
	      ptr = current_conversion_rules[b].data.to;
	      if (ptr && strstr (ptr, "%s"))
		{
		  A4GL_make_downshift (lastFieldData);
		  SPRINTF1 (buff, ptr, lastFieldData);
		  return buff;
		}
	      else
		{
		  return ptr;
		}
	    }
	}
    }

  A4GL_debug ("check sql 2\n");
  ptr = acl_malloc2 (strlen (s) * 2 + 1000);

  strcpy (ptr, s);
  for (b = 0; b < current_conversion_rules_cnt; b++)
    {
      if (current_conversion_rules[b].type == CVSQL_REPLACE)
	{
	  if (A4GL_aubit_strcasestr (ptr, current_conversion_rules[b].data.from) != 0)
	    {
	      A4GL_cvsql_replace_str (ptr, current_conversion_rules[b].data.from, current_conversion_rules[b].data.to);
	    }
	}
    }
  A4GL_debug ("returning\n");

  if (A4GLSQLCV_check_requirement ("LIMIT_LINE"))
    {
      buff = acl_strdup (A4GL_space_out (ptr));
    }
  else
    {
      buff = acl_strdup (ptr);
    }
  acl_free (ptr);

  if (A4GL_isyes (acl_getenv ("A4GL_DUMP_SQL")))
    {
      FILE *fout;
      fout = fopen ("/tmp/sql.log", "a");
      if (fout)
	{
	  FPRINTF (fout, "%s\n", buff);
#ifdef CM
	  PRINTF ("IMMEDIATE %s\n", buff);
#endif
	  fclose (fout);
	}
    }
  return buff;
}





char *
A4GLSQLCV_insert_alias_column (char *t, char *c, char *v, int dtype)
{
  int b;
  char s[256];
  char sv[512];
  SPRINTF2 (s, "%s.%s", t, c);
#ifdef MSVC
  SPRINTF3 (sv, "%s.%s.%s", t, c, v);
#else
  SNPRINTF (sv, 512, "%s.%s.%s", t, c, v);
#endif
  c = A4GL_confirm_colname (t, c);
  sv[511] = 0;
  A4GL_debug ("Alias : '%s'\n", s);

  A4GL_debug ("Alias ? %s %s %s %x\n", t, c, v, dtype);
  if (A4GLSQLCV_check_requirement ("OMIT_SERIAL_COL_FROM_INSERT") && dtype == DTYPE_SERIAL)
    {
      return "";
    }


  for (b = 0; b < current_conversion_rules_cnt; b++)
    {
      if (current_conversion_rules[b].type == CVSQL_INSERT_ALIAS_COLUMN)
	{
	  if (A4GL_strwscmp (sv, current_conversion_rules[b].data.from) == 0)
	    {
	      A4GL_debug ("Substitute : %s\n", current_conversion_rules[b].data.to);
	      return current_conversion_rules[b].data.to;
	    }
	}
    }


  if (strchr (sv, '('))
    {
      static char buff[256];
      static char *ptr = 0;
      char *ptr2;
      if (ptr)
	acl_free (ptr);
      ptr = acl_strdup (sv);
      ptr2 = strchr (ptr, '(');
      *ptr2 = 0;
      ptr2++;
      for (b = 0; b < current_conversion_rules_cnt; b++)
	{
	  if (current_conversion_rules[b].type == CVSQL_INSERT_ALIAS_COLUMN)
	    {
	      if (A4GL_strwscmp (ptr, current_conversion_rules[b].data.from) == 0)
		{
		  A4GL_debug ("Substitute : %s\n", current_conversion_rules[b].data.to);
		  SPRINTF2 (buff, "%s(%s", current_conversion_rules[b].data.to, ptr2);
		  return buff;
		}
	    }
	}
    }


  for (b = 0; b < current_conversion_rules_cnt; b++)
    {
      if (current_conversion_rules[b].type == CVSQL_INSERT_ALIAS_COLUMN)
	{
	  if (A4GL_strwscmp (s, current_conversion_rules[b].data.from) == 0)
	    {
	      A4GL_debug ("Substitute : %s\n", current_conversion_rules[b].data.to);
	      return current_conversion_rules[b].data.to;
	    }
	}
    }


  if (strchr (s, '('))
    {
      static char buff[256];
      static char *ptr = 0;
      char *ptr2;
      if (ptr)
	acl_free (ptr);
      ptr = acl_strdup (s);
      ptr2 = strchr (ptr, '(');
      *ptr2 = 0;
      ptr2++;
      for (b = 0; b < current_conversion_rules_cnt; b++)
	{
	  if (current_conversion_rules[b].type == CVSQL_INSERT_ALIAS_COLUMN)
	    {
	      if (A4GL_strwscmp (ptr, current_conversion_rules[b].data.from) == 0)
		{
		  A4GL_debug ("Substitute : %s\n", current_conversion_rules[b].data.to);
		  SPRINTF2 (buff, "%s(%s", current_conversion_rules[b].data.to, ptr2);
		  return buff;
		}
	    }
	}
    }


  A4GL_debug ("No substitute for '%s'\n", s);
  return c;
}




char *
A4GLSQLCV_insert_alias_value (char *t, char *c, char *v, int dtype)
{
  int b;
  char s[256];
  char sv[512];
  SPRINTF2 (s, "%s.%s", t, c);
#ifdef MSVC
  SPRINTF3 (sv, "%s.%s.%s", t, c, v);
#else
  SNPRINTF (sv, 512, "%s.%s.%s", t, c, v);
#endif
  sv[511] = 0;
  A4GL_debug ("Alias : '%s'\n", s);

  A4GL_debug ("Alias ? %s %s %s %x\n", t, c, v, dtype);

  for (b = 0; b < current_conversion_rules_cnt; b++)
    {
      if (current_conversion_rules[b].type == CVSQL_INSERT_ALIAS_VALUE)
	{
	  if (A4GL_strwscmp (sv, current_conversion_rules[b].data.from) == 0)
	    {
	      A4GL_debug ("Substitute : %s\n", current_conversion_rules[b].data.to);
	      return current_conversion_rules[b].data.to;
	    }
	}
    }


  if (strchr (sv, '('))
    {
      static char buff[256];
      static char *ptr = 0;
      char *ptr2;
      if (ptr)
	acl_free (ptr);
      ptr = acl_strdup (sv);
      ptr2 = strchr (ptr, '(');
      *ptr2 = 0;
      ptr2++;
      for (b = 0; b < current_conversion_rules_cnt; b++)
	{
	  if (current_conversion_rules[b].type == CVSQL_INSERT_ALIAS_VALUE)
	    {
	      if (A4GL_strwscmp (ptr, current_conversion_rules[b].data.from) == 0)
		{
		  A4GL_debug ("Substitute : %s\n", current_conversion_rules[b].data.to);
		  SPRINTF2 (buff, "%s(%s", current_conversion_rules[b].data.to, ptr2);
		  return buff;
		}
	    }
	}
    }


  for (b = 0; b < current_conversion_rules_cnt; b++)
    {
      if (current_conversion_rules[b].type == CVSQL_INSERT_ALIAS_VALUE)
	{
	  if (A4GL_strwscmp (s, current_conversion_rules[b].data.from) == 0)
	    {
	      A4GL_debug ("Substitute : %s\n", current_conversion_rules[b].data.to);
	      return current_conversion_rules[b].data.to;
	    }
	}
    }


  if (strchr (s, '('))
    {
      static char buff[256];
      static char *ptr = 0;
      char *ptr2;
      if (ptr)
	acl_free (ptr);
      ptr = acl_strdup (s);
      ptr2 = strchr (ptr, '(');
      *ptr2 = 0;
      ptr2++;
      for (b = 0; b < current_conversion_rules_cnt; b++)
	{
	  if (current_conversion_rules[b].type == CVSQL_INSERT_ALIAS_VALUE)
	    {
	      if (A4GL_strwscmp (ptr, current_conversion_rules[b].data.from) == 0)
		{
		  A4GL_debug ("Substitute : %s\n", current_conversion_rules[b].data.to);
		  SPRINTF2 (buff, "%s(%s", current_conversion_rules[b].data.to, ptr2);
		  return buff;
		}
	    }
	}
    }


  A4GL_debug ("No substitute for '%s'\n", s);
  return v;
}



char *
A4GLSQLCV_dtype_alias (char *s)
{
  int b;
  A4GL_debug ("Alias : '%s'\n", s);

  for (b = 0; b < current_conversion_rules_cnt; b++)
    {
      if (current_conversion_rules[b].type == CVSQL_DTYPE_ALIAS)
	{
	  if (A4GL_strwscmp (s, current_conversion_rules[b].data.from) == 0)
	    {
	      A4GL_debug ("Substitute : %s\n", current_conversion_rules[b].data.to);
	      return current_conversion_rules[b].data.to;
	    }
	}
    }

  if (strchr (s, '('))
    {
      static char buff[256];
      static char *ptr = 0;
      char *ptr2;
      if (ptr)
	free (ptr);
      ptr = acl_strdup (s);
      ptr2 = strchr (ptr, '(');
      *ptr2 = 0;
      ptr2++;
      for (b = 0; b < current_conversion_rules_cnt; b++)
	{
	  if (current_conversion_rules[b].type == CVSQL_DTYPE_ALIAS)
	    {
	      if (A4GL_strwscmp (ptr, current_conversion_rules[b].data.from) == 0)
		{
		  A4GL_debug ("Substitute : %s\n", current_conversion_rules[b].data.to);
		  SPRINTF2 (buff, "%s(%s", current_conversion_rules[b].data.to, ptr2);
		  return buff;
		}
	    }
	}





    }



  A4GL_debug ("No substitute for '%s'\n", s);
  return s;
}




void
A4GL_cvsql_replace_str (char *buff, char *from, char *to)
{
  int a;
  static char *buff2;
  int l;
  int cnt = 0;
  int sq = 0;
  int dq = 0;
  int ln;
  l = strlen (buff) * 2 + 1000;
  buff2 = acl_realloc (buff2, l);
  A4GL_debug ("replace_str from :%s to %s", from, to);
  strcpy (buff2, "");
  ln = strlen (buff);
  for (a = 0; a <= ln; a++)
    {
      int ok_to_replace;	// We only want to replace whole words...
      ok_to_replace = 0;

      if (a == 0)
	{
	  ok_to_replace = 1;
	}
      else
	{
	  if (!isalnum (buff[a - 1]))
	    ok_to_replace = 1;
	}



      if (sq == 0 && dq == 0 && strncasecmp (&buff[a], from, strlen (from)) == 0 && ok_to_replace == 1)
	{
	  strcat (buff2, to);
	  cnt = strlen (buff2);
	  a = a + strlen (from) - 1;

	}
      else
	{
	  buff2[cnt++] = buff[a];
	  buff2[cnt] = 0;
	  if (buff[a] == '\'' && dq == 0)
	    sq = 1 - sq;
	  if (buff[a] == '"' && sq == 0)
	    dq = 1 - dq;
	}
    }

  if (cnt >= l)
    {
      A4GL_assertion (1, "Not allocated enough space for replace_str");
    }
  A4GL_debug ("New string : %s\n", buff2);
  strcpy (buff, buff2);

}



char *
A4GLSQLCV_check_expr (char *s)
{
  int b;
  static char *buff = 0;

  A4GL_debug ("%s\n", s);

  buff = acl_realloc (buff, strlen (s) * 2 + 1000);
  strcpy (buff, s);

  for (b = 0; b < current_conversion_rules_cnt; b++)
    {
      if (current_conversion_rules[b].type == CVSQL_REPLACE_EXPR)
	{

	  if (A4GL_aubit_strcasestr (buff, current_conversion_rules[b].data.from) != 0)
	    {
	      char *to;
	      if (current_conversion_rules[b].data.to[0] == '$')
		{
		  to = get_dollared_sql_var (current_conversion_rules[b].data.to);
		}
	      else
		{
		  to = current_conversion_rules[b].data.to;
		}
	      A4GL_debug ("Converting %s to %s in %s\n", current_conversion_rules[b].data.from, to, buff);
	      A4GL_cvsql_replace_str (buff, current_conversion_rules[b].data.from, to);
	      A4GL_debug ("Converted: %s\n", buff);
	    }
	}
    }
  A4GL_debug ("Returning %s\n", buff);
  return buff;

}






char *
A4GLSQLCV_generate_current (char *from, char *to)
{
  static char buff[256];
  int hr;
  if (from == 0)
    from = "YEAR";
  if (to == 0)
    to = "SECOND";

  hr = A4GLSQLCV_check_requirement ("SQL_CURRENT_FUNCTION");

  if (hr)
    {
      char *ptr;
      ptr = current_conversion_rules[hr - 1].data.from;
      SPRINTF3 (buff, "%s('%s','%s')", ptr, from, to);
    }
  else
    {
      SPRINTF2 (buff, "CURRENT %s TO %s", from, to);
    }

  return buff;
}


int
A4GLSQLCV_check_runtime_requirement (char *s)
{
  if (!A4GL_compile_time_convert ())
    {
      return 0;
    }
  else
    {
      return A4GLSQLCV_check_requirement (s);
    }
}




static int
check_requirement_i (char *s)
{
  int a;
  int b;
  if (A4GL_isyes (acl_getenv (s)))
    {
      return 1;
    }

  if (A4GL_isno (acl_getenv (s)))
    {
      return 0;
    }


  a = A4GL_cv_str_to_func (s, strlen (s), 1);
  A4GL_debug ("Checking for a type %d\n", a);

  if (a == 0)
    {
      FILE *f;
      f = fopen ("/tmp/Unknown.sqlconversion", "a");
      if (f)
	{
	  fprintf (f, "%s\n", s);
	  fclose (f);
	}
      A4GL_debug ("WARNING : Unknown type : %s", s);
      return 0;			// I don't know what they are talking about...
    }

  if (current_conversion_rules == 0)
    {
      A4GL_debug ("A4GLSQLCV_check_requirement(%s) - No rules", s);
      return 0;
    }

// OK - now go through and have a look....
  for (b = 0; b < current_conversion_rules_cnt; b++)
    {
      if (current_conversion_rules[b].type == a)
	{
	  return b + 1;
	}
    }

  A4GL_debug ("A4GLSQLCV_check_requirement(%s) - no", s);
  return 0;
}




int
A4GLSQLCV_check_requirement (char *s)
{
  int n;
  n = (int) A4GL_find_pointer (s, HASREQUIREMENT);
  if (n == 0)
    {
      n = check_requirement_i (s);
      if (n == 0)
	n = 99999;
      A4GL_add_pointer (s, HASREQUIREMENT, (void *) n);
    }
  if (n == 99999)
    n = 0;
  return n;
}

char *
A4GLSQLCV_check_colname (char *tabname, char *colname)
{
  static char buff[256];
  char *ptr;


  ptr = strchr (colname, '.');
  if (ptr)
    {
      ptr++;
      colname = ptr;
    }

  colname = A4GL_confirm_colname (tabname, colname);

  if (tabname && strlen (tabname))
    {
      SPRINTF2 (buff, "%s.%s", tabname, colname);
    }
  else
    {
      SPRINTF1 (buff, "%s", colname);
    }
  return buff;
}

char *
A4GLSQLCV_check_colname_alias (char *alias, char *tabname, char *colname)
{
  static char buff[256];

  colname = A4GL_confirm_colname (tabname, colname);

  if (tabname)
    {
      SPRINTF2 (buff, "%s.%s", alias, colname);
    }
  else
    {
      SPRINTF1 (buff, "%s", colname);
    }
  return buff;
}

char *
A4GLSQLCV_matches_string (char *not, char *str, char *esc)
{
  static char buff[1024];


  if (1 && A4GLSQLCV_check_requirement ("MATCHES_TO_LIKE"))
    {
      if (strstr (not, "NOT") == 0)
	{
	  SPRINTF1 (buff, " LIKE %s", CV_matches ("LIKE", str, esc));
	}
      else
	{
	  SPRINTF1 (buff, " NOT LIKE %s", CV_matches ("LIKE", str, esc));
	}

      return buff;
    }

  if (1 && A4GLSQLCV_check_requirement ("MATCHES_TO_REGEX"))
    {
      if (strstr (not, "NOT") == 0)
	{
	  SPRINTF1 (buff, " ~ %s", CV_matches ("~", str, esc));
	}
      else
	{
	  SPRINTF1 (buff, " !~ %s", CV_matches ("~", str, esc));
	}
      return buff;
    }
  if (1 && A4GLSQLCV_check_requirement ("MATCHES_TO_REGEXP"))
    {
      if (strstr (not, "NOT") == 0)
	{
	  SPRINTF1 (buff, " REGEXP %s", CV_matches ("~", str, esc));
	}
      else
	{
	  SPRINTF1 (buff, " NOT REGEXP %s", CV_matches ("~", str, esc));
	}
      return buff;
    }


  if (1 && A4GLSQLCV_check_requirement ("MATCHES_TO_GLOB"))
    {
      SPRINTF2 (buff, "%s GLOB %s", not, CV_matches ("~", str, esc));
      return buff;
    }


  if (strlen (esc))
    {
      SPRINTF3 (buff, "%s MATCHES %s %s", not, str, esc);
    }
  else
    {
      SPRINTF2 (buff, "%s MATCHES %s ", not, str);
    }



  return buff;
}


char *
A4GLSQLCV_make_substr_s (char *colname, int n, char *l, char *r)
{
  static char buff[256];
  int rule;
  rule = A4GLSQLCV_check_requirement ("SUBSTRING_FUNCTION");

  strcpy (buff, colname);
  if (!rule || n == 0)
    {
      if (n == 0)
	return buff;
      if (n == 1)
	{
	  SPRINTF2 (buff, "%s[%s]", colname, l);
	  return buff;
	}
      if (n == 2)
	{
	  SPRINTF3 (buff, "%s[%s,%s]", colname, l, r);
	  return buff;
	}
    }
  else
    {
      char *func;
      func = current_conversion_rules[rule - 1].data.from;
      A4GL_assertion (func == 0, "Expecting a substring function");
      if (n == 1)
	{
	  SPRINTF3 (buff, "%s(%s,%s,1)", func, colname, l);
	  return buff;
	}
      if (n == 2)
	{
	  if (strcmp (l, "1") == 0)
	    {
	      SPRINTF4 (buff, "%s(%s,%s,%s)", func, colname, l, r);
	    }
	  else
	    {
	      SPRINTF5 (buff, "%s(%s,%s,(%s)-(%s)+1)", func, colname, l, r, l);
	    }
	  return buff;
	}
    }
  A4GL_debug ("Shouldn't get to here...");
  return "???";
}



char *
A4GLSQLCV_make_substr (char *colname, int i0, int i1, int i2)
{
  static char l[256] = "";
  static char r[256] = "";
  char *s;

  if (i0)
    SPRINTF1 (l, "%d", i1);
  if (i0 >= 2)
    SPRINTF1 (r, "%d", i2);
  s = A4GLSQLCV_make_substr_s (colname, i0, l, r);
  return s;
}


static int
match_strncasecmp (char *s1, char *s2, int len)
{
  char p1[200];
  char p2[200];
  int l1;
  int l2;
  strncpy (p1, s1, len + 1);
  strncpy (p2, s2, len + 1);
  p1[len + 1] = 0;
  p2[len + 1] = 0;
  if (strchr (p1, ' ') || strchr (p1, '\n'))
    {
      A4GL_trim (p1);
    }
  if (strchr (p2, ' ') || strchr (p2, '\n'))
    {
      A4GL_trim (p2);
    }
  l1 = strlen (p1);
  l2 = strlen (p2);

  if (l1 == l2)
    {
      if (strncasecmp (p1, p2, len) == 0)
	return 0;
      else
	return 1;
    }

  if (l1 > l2)
    {
      return strncasecmp (p1, p2, len);
    }

  // If p2 is greater than p1 - it can't match...
  if (l1 < l2)
    {
      return 1;
    }

  A4GL_assertion (1, "Surely this cant happen");
  return 1;
}







#ifdef NOT_PORTED

/*
 * Changes double-quotes in SQL statements to single quotes.
 * Unless the double-quote is escaped with a backslash,
 * or is within single quotes. Also, single quotes within
 * pairs of double-quotes are escaped (with backslash).
 *
 * @param  sql  string holding SQL statement
 */
void
A4GL_cvsql_double_single (char *sql, char *args)
{
  char *p;
  int quote = 0;
  int slash = 0;

  for (p = sql; *p > 0; p++)
    {
      if (slash)
	{
	  slash = 0;
	  continue;
	}
      switch (*p)
	{
	case '\\':
	  slash = 1;
	  break;
	case '\"':
	  if (quote == 2)
	    {
	      *p = '\'';
	      quote = 0;
	    }
	  else
	    {
	      if (quote == 0)
		{
		  *p = '\'';
		  quote = 2;
		}
	    }
	  break;
	case '\'':
	  switch (quote)
	    {
	    case 0:
	      quote = 1;
	      break;
	    case 1:
	      quote = 0;
	      break;
	    case 2:
	      A4GL_cv_inschstr (p, '\\');
	      p++;
	      break;
	    }
	  break;
	}
    }
}


/*
 * Converts an Informix style update to the standard format
 * ie.
 *    update tbl set ( a, b, c, ... ) = ( x, y, z, ... ) 
 * to
 *    update tbl set a = x, b = y, c = z, ... 
 *
 * @param  sql   SQL statement string
 */
void
A4GL_cvsql_split_update (char *sql, char *args)
{
  char *t;
  char *p;
  int n;
  char *ob1;			// first opening bracket
  char *cb1;			// first closing bracket
  char *ob2;			// second opening bracket
  char *cb2;			// second closing bracket
  char *s;			// pointer to temp. buffer

  /* the statement must start with "update tablename set ( " ... 
   */
  t = A4GL_cv_next_token (sql, &n, 0);
  if (strncasecmp (t, "update", n) != 0)
    return;
  t = A4GL_cv_next_token (&t[n], &n, 0);
  t = A4GL_cv_next_token (&t[n], &n, 0);
  if (strncasecmp (t, "set", n) != 0)
    return;
  t = A4GL_cv_next_token (&t[n], &n, 0);
  if (*t != '(')
    return;
  ob1 = t;

  if ((cb1 = A4GL_cv_find_closing (ob1)) == NULL)
    return;
  t = A4GL_cv_next_token (&cb1[1], &n, 0);
  if (*t != '=')
    return;
  t = A4GL_cv_next_token (&t[n], &n, 0);
  if (*t != '(')
    return;
  ob2 = t;
  if ((cb2 = A4GL_cv_find_closing (ob2)) == NULL)
    return;

  /* create a temp. buffer to build the new 'set' clause */
  n = cb2 - ob1;
  s = acl_malloc2 (n);
  s[0] = '\0';

  /* scan each pair of brackets, extracting col = value pairs */
  *ob1 = ' ';
  *cb1 = '\0';
  *ob2 = ' ';
  *cb2 = '\0';

  {
    char *o1 = ob1;
    char *o2 = ob2;
    while ((p = A4GL_cv_find_token (++o1, ",", 1)))
      {
	t = A4GL_cv_find_token (++o2, ",", 1);
	strncat (s, o1, (p - o1));
	strcat (s, "=");
	strncat (s, o2, (t - o2));
	strcat (s, ",");
	o1 = p;
	o2 = t;
      }
    strncat (s, o1, (cb1 - o1));
    strcat (s, "=");
    if (o2++ < cb2)
      strncat (s, o2, (cb2 - o2));
  }

  *cb1 = ' ';
  *cb2 = ' ';

  A4GL_cv_replacestr (ob1, (cb2 - ob1 + 1), s);

  acl_free (s);
}


void
A4GL_cvsql_matches_like (char *sql, char *args)
{
  A4GL_cvsql_matches (sql, "like");
}

void
A4GL_cvsql_matches_regex (char *sql, char *args)
{
  A4GL_cvsql_matches (sql, "~");
}
#endif


char *
CV_matches (char *type, char *string, char *esc)
{
  static char buff[1024];
  int a;

  if (strncmp (string, "'@@VARIABLE[", 12) == 0)
    {
      return string;
    }

  if (strcmp (string, "?") == 0)
    {
      int hr;
      hr = A4GLSQLCV_check_requirement ("MATCHES_VAR_FUNC");
      if (hr)
	{
	  if (strcmp (esc, "?") != 0)
	    {
	      SPRINTF2 (buff, "%s(?,'%s')", current_conversion_rules[hr - 1].data.from, esc);
	    }
	  else
	    {
	      //@ FIXME
	      SPRINTF1 (buff, "%s(?,'?')", current_conversion_rules[hr - 1].data.from);
	    }
	  return buff;
	}


    }


  if (string[0] != '\'')
    {
      // Can't change a string we cant see....
      // maybe if we call a stored procedure or
      // something - but thats outside our scope ATM...
      return string;
    }

  if (type[0] == '~')
    {
      buff[0] = '\'';
      buff[1] = '^';		// Tie it to the beginning of the string
      buff[2] = 0;
    }
  else
    {
      buff[0] = '\'';
      buff[1] = 0;
    }

  for (a = 1; a < strlen (string); a++)
    {
      {
	char smallvar[20];

	if (string[a] == '?')
	  {
	    if (type[0] == '~')
	      strcpy (smallvar, ".");
	    else
	      strcpy (smallvar, "_");
	    strcat (buff, smallvar);
	    continue;
	  }

	if (string[a] == '*')
	  {
	    if (type[0] == '~')
	      strcpy (smallvar, ".*");
	    else
	      strcpy (smallvar, "%");
	    strcat (buff, smallvar);
	    continue;
	  }

	if (type[0] == '~' && (string[a] == '*' || string[a] == '.'))
	  {
	    strcat (buff, "\\");
	  }

	if (type[0] != '~' && (string[a] == '%' || string[a] == '_'))
	  {
	    if (A4GL_isyes (acl_getenv ("DOING_CM")))
	      {
		strcat (buff, "\\\\");
	      }
	    else
	      {
		strcat (buff, "\\");
	      }
	  }



	if (type[0] == '~' && string[a] == '\'')
	  {
	    if (strstr (buff, ".*"))
	      {
		strcat (buff, "$");
	      }
	  }
	smallvar[0] = string[a];
	smallvar[1] = 0;
	strcat (buff, smallvar);
      }
    }

  return buff;
}




/*
 * Replaces a string in a SQL statement. The search string must
 * begin on a token.
 *
 * @param   sql   string holding SQL statement
 * @param   str   search/replace as "before = after"
 */
void
A4GL_cvsql_replace (char *sql, char *args)
{
  char srch[100];
  char *rplc;
  char *t;
  int slen;
  int len;

  /* extract the search and replace strings from args */
  if (args == NULL || args[0] == '\0')
    return;
  if ((t = a_strchr (args, '=')) == NULL)
    return;
  rplc = A4GL_cv_next_token ((t + 1), &len, 0);
  if (rplc == NULL)
    rplc = empty;
  if ((slen = t - args + 1) < 1)
    return;
  strncpy (srch, args, slen);
  srch[--slen] = '\0';
  while (srch[slen - 1] == ' ')
    srch[--slen] = '\0';

  /* locate any token that matches the start of the search string */
  t = sql;
  while ((t = A4GL_cv_next_token (t, &len, 1)) != NULL)
    {
      if (strncasecmp (t, srch, len) == 0)
	{
	  if (strncasecmp (t, srch, slen) == 0)
	    {
	      A4GL_cv_replacestr (t, slen, rplc);
	      t += strlen (rplc) - slen;
	    }
	}
      t += len;
    }

}

/* ----------------------------------------------------------------
 * Functions for manipulating space-padded null terminated strings.
 * Care is taken to avoid any chance of buffer overflow. SQL strings
 * will be truncated if conversion extends beyond the available space.
*/

/*
 * Replace a string inside another string
 * @param p = string to replace into
 * @param n = length of string to replace
 * @param s = string to put in place of the 'n' characters in 'p'.
 */
void
A4GL_cv_replacestr (char *p, int n, char *s)
{
  while (*s > 0)
    {
      if (n-- > 0)
	{
	  *p++ = *s++;
	}
      else
	{
	  A4GL_cv_inschstr (p++, *s++);
	}
    }
  if (n > 0)
    A4GL_cv_delchstr (p, n);
}

/*
 * Insert one char into a string, and drop the last char.
 */
void
A4GL_cv_inschstr (char *p, char c)
{
  char x;
  while ((x = *p) > 0)
    {
      *p++ = c;
      c = x;
    }
}

/*
 * Delete chars from a string, and pad end with spaces
 */
void
A4GL_cv_delchstr (char *str, int n)
{
  char *p;
  while (n-- > 0)
    {
      for (p = str; *p > 0; p++)
	if ((*p = *(p + 1)) == 0)
	  *p = ' ';
    }
}



static void
remove_ws_and_upshift (char *s)
{
  char p[64000];
  int a;
  int c = 0;
  strcpy (p, s);
  for (a = 0; a < strlen (s); a++)
    {
      if (!isspace (s[a]))
	{
	  if (s[a] == '(' || s[a] == ')')
	    {
	      if (!isspace (p[c - 1]))
		{
		  p[c++] = ' ';
		}
	    }
	  p[c++] = toupper (s[a]);
	  if (s[a] == '(' || s[a] == ')')
	    {
	      p[c++] = ' ';
	    }
	  continue;
	}
      if (c == 0)
	continue;
      if (isspace (p[c - 1]))
	continue;
      p[c++] = toupper (s[a]);
    }
  p[c] = 0;
  strcpy (s, p);
}


int
A4GL_strwscmp (char *a, char *b)
{
  int a_i;
  int b_i;
  char o1[64000];
  char o2[64000];
  int lastWasWs;
  char fieldData[256] = "";
  b_i = 0;

  strcpy (o1, a);
  strcpy (o2, b);
  b_i = 0;
  lastWasWs = 0;

  remove_ws_and_upshift (o1);
  remove_ws_and_upshift (o2);

  A4GL_trim (o1);
  A4GL_trim (o2);

  if (strstr (o2, "%S"))
    {
      int r;
      int chars = 0;
      char buff[2000];
      strcpy (buff, o2);
      strcat (buff, "%n");
      a_i = -1;
      r = sscanf (o1, buff, &fieldData, &chars);
      if (r >= 1 && strlen (o1) == chars)
	{
	  a_i = 0;
	}
    }
  else
    {

      a_i = strcmp (o1, o2);
    }

  strcpy (lastFieldData, fieldData);


  return a_i;


}



int
is_fake_rowid_column (char *s)
{
  int hr;

  hr = A4GLSQLCV_check_requirement ("FAKE_ROWID_NAME");

  if (hr)
    {
      char *x;
      x = current_conversion_rules[hr - 1].data.from;
      if (x)
	{
	  if (strcmp (s, x) == 0)
	    {
	      return 1;
	    }
	}
    }
  return 0;
}


char *
A4GLSQLCV_make_ival_extend (char *ival, char *from, char *from_len, char *to, int extend)
{
  static char buff[256];
  int hr;
  char *xx;
  char *ival2;

  ival2 = A4GLSQLCV_interval_value_internal (ival, NULL, NULL);

  hr = A4GLSQLCV_check_requirement ("INTERVAL_EXTEND_FUNCTION");
  if (hr)
    {
      xx = current_conversion_rules[hr - 1].data.from;
      ival2 = A4GLSQLCV_interval_value_internal (ival, from, to);
      if (from_len == 0)
	{
	  SPRINTF4 (buff, "%s(%s,'%s',0,'%s')", xx, ival2, from, to);
	}
      else
	{
	  SPRINTF5 (buff, "%s(%s,'%s',%s,'%s')", xx, ival2, from, from_len, to);
	}

    }
  else
    {
      if (from_len == 0)
	{			// The pointer not the value :-)
	  if (extend)
	    {
	      SPRINTF3 (buff, "EXTEND(%s,%s TO %s)", ival2, from, to);
	    }
	  else
	    {
	      SPRINTF3 (buff, "%s %s TO %s", ival2, from, to);
	    }
	}
      else
	{
	  if (extend)
	    {
	      SPRINTF4 (buff, "EXTEND(%s,%s(%s) TO %s)", ival2, from, from_len, to);
	    }
	  else
	    {
	      SPRINTF4 (buff, "%s %s(%s) TO %s", ival2, from, from_len, to);
	    }
	}
    }
  return buff;
}

char *
A4GLSQLCV_make_dtime_extend (char *dval, char *from, char *to, int extend)
{

  static char buff[256];
  int hr;
  char *xx;
  char *dval2;

  dval2 = A4GLSQLCV_datetime_value (dval);

  hr = A4GLSQLCV_check_requirement ("DATETIME_EXTEND_FUNCTION");
  if (hr)
    {
      dval2 = A4GLSQLCV_datetime_value_internal (dval, from, to);
      xx = current_conversion_rules[hr - 1].data.from;
      SPRINTF4 (buff, "%s(%s,'%s','%s')", xx, dval2, from, to);
    }
  else
    {
      if (extend)
	{
	  SPRINTF3 (buff, "EXTEND(%s,%s TO %s)", dval2, from, to);
	}
      else
	{
	  SPRINTF3 (buff, "%s %s TO %s", dval2, from, to);
	}
    }
  return buff;
}



static char *
A4GLSQLCV_datetime_value_internal (char *s, char *from, char *to)
{
  static char buff[256];
  int hr;
  if (strncasecmp (s, "DATETIME(", 9) == 0)
    {
      if (1)
	{
	  hr = A4GLSQLCV_check_requirement ("CHAR_TO_DATETIME");
	  if (hr)
	    {
	      char *ptr;
	      char *xx;
	      xx = current_conversion_rules[hr - 1].data.from;
	      ptr = acl_strdup (&s[9]);
	      ptr[strlen (ptr) - 1] = 0;
	      if (from == NULL)
		{
		  SPRINTF2 (buff, "%s(\'%s\')", xx, ptr);
		}
	      else
		{
		  SPRINTF4 (buff, "%s_extended(\'%s\','%s','%s')", xx, ptr, from, to);
		}
	      acl_free (ptr);
	      return buff;

	    }
	}

    }
  return s;
}

char *
A4GLSQLCV_datetime_value (char *s)
{
  return A4GLSQLCV_datetime_value_internal (s, NULL, NULL);
}


static char *
A4GLSQLCV_interval_value_internal (char *s, char *from, char *to)
{
  static char buff[256];
  int hr;
  if (strncasecmp (s, "INTERVAL(", 9) == 0)
    {
      if (1)
	{
	  hr = A4GLSQLCV_check_requirement ("CHAR_TO_INTERVAL");
	  if (hr)
	    {
	      char *ptr;
	      char *xx;
	      xx = current_conversion_rules[hr - 1].data.from;
	      ptr = acl_strdup (&s[9]);
	      ptr[strlen (ptr) - 1] = 0;
	      if (from == NULL)
		{
		  SPRINTF2 (buff, "%s(\'%s\')", xx, ptr);
		}
	      else
		{
		  SPRINTF4 (buff, "%s_extended(\'%s\','%s','%s')", xx, ptr, from, to);
		}
	      acl_free (ptr);
	      return buff;
	    }
	}

    }
  return s;
}


char *
A4GLSQLCV_interval_value (char *s)
{
  return A4GLSQLCV_interval_value_internal (s, NULL, NULL);
}


void
A4GLSQLCV_check_fullpath (char *s)
{
  char buff[512];
  char buff2[512];


  if (A4GLSQLCV_check_requirement ("ESQL_UNLOAD_FULL_PATH"))
    {
      if (s[0] != '/')
	{
#ifdef MSVC
	  _getcwd (buff, 512);
#else
	  getcwd (buff, 512);
#endif
	  strcpy (buff2, s);
	  SPRINTF2 (s, "%s/%s", buff, buff2);
	}
    }

}


char *
A4GLSQLCV_select_into_temp (char *sel, char *lp, char *tabname)
{
  static char *ptr = 0;

  if (A4GLSQLCV_check_requirement ("SELECT_INTO_TEMP_AS_DECLARE_GLOBAL"))
    {
      //if (ptr) free(ptr);
      ptr = acl_malloc2 (strlen (sel) + 2000);
      A4GL_debug ("Creating temp table called %s", tabname);
      if (!A4GL_has_pointer (tabname, LOG_TEMP_TABLE))
	{
	  A4GL_debug ("Adding LOG_TEMP_TABLE for %s", tabname);
	  A4GL_add_pointer (tabname, LOG_TEMP_TABLE, (void *) 1);
	}
      SPRINTF2 (ptr, "DECLARE GLOBAL TEMPORARY TABLE SESSION.%s AS %s ON COMMIT PRESERVE ROWS WITH NORECOVERY", tabname, sel);
      return ptr;
    }

  if (A4GLSQLCV_check_requirement ("SELECT_INTO_TEMP_AS_DECLARE_INSERT"))
    {
      //if (ptr) free(ptr);
      ptr = acl_malloc2 (strlen (sel) + 2000);
      A4GL_debug ("Creating temp table called %s (declare+insert) ", tabname);
      if (!A4GL_has_pointer (tabname, LOG_TEMP_TABLE))
	{
	  A4GL_debug ("Adding LOG_TEMP_TABLE for %s", tabname);
	  A4GL_add_pointer (tabname, LOG_TEMP_TABLE, (void *) 1);
	}
      SPRINTF2 (ptr, "INSERT INTO SESSION.%s %s", tabname, sel);
      return ptr;
    }

  if (A4GLSQLCV_check_requirement ("SELECT_INTO_TEMP_AS_CREATE_TEMP_AS"))
    {
      //if (ptr) free(ptr);
      ptr = acl_malloc2 (strlen (sel) + 2000);
      SPRINTF2 (ptr, "CREATE TEMP TABLE %s AS %s ", tabname, sel);
      return ptr;
    }



  if (A4GLSQLCV_check_requirement ("SELECT_INTO_TEMP_AS_CREATE_TEMPORARY_AS"))
    {
      //if (ptr) free(ptr);
      ptr = acl_malloc2 (strlen (sel) + 2000);
      SPRINTF2 (ptr, "CREATE TEMPORARY TABLE %s AS %s ", tabname, sel);
      return ptr;
    }

  if (A4GLSQLCV_check_requirement ("SELECT_INTO_TEMP_AS_CREATE_GLOBAL_TEMPORARY_BRACKETS"))
    {
      //if (ptr) free(ptr);
      ptr = acl_malloc2 (strlen (sel) + 2000);
      SPRINTF2 (ptr, "CREATE GLOBAL TEMPORARY TABLE %s AS ( %s )", tabname, sel);
      return ptr;
    }


  //if (ptr) free(ptr);
  ptr = acl_malloc2 (strlen (sel) + 2000);
  SPRINTF2 (ptr, "%s %s", sel, lp);
  return ptr;
  return 0;
}



void
A4GLSQLCV_add_temp_table (char *tabname)
{
  if (!A4GL_has_pointer (tabname, LOG_TEMP_TABLE))
    {
      A4GL_debug ("Adding LOG_TEMP_TABLE for %s", tabname);
      A4GL_add_pointer (tabname, LOG_TEMP_TABLE, (void *) 1);
    }

}

char *
A4GLSQLCV_create_temp_table (char *tabname, char *elements, char *extra, char *oplog)
{
  static char *ptr = 0;

  //if (ptr) free(ptr);

  ptr = acl_malloc2 (strlen (tabname) + strlen (elements) + strlen (extra) + strlen (oplog) + 1000);

  save_temp_table (tabname, 0);
  if (!A4GL_has_pointer (tabname, LOG_TEMP_TABLE))
    {
      A4GL_add_pointer (tabname, LOG_TEMP_TABLE, (void *) 1);
    }

  if (A4GLSQLCV_check_requirement ("TEMP_AS_DECLARE_GLOBAL"))
    {
      A4GL_debug ("Creating temp table called TABLE : %s", tabname);

      //if (!A4GL_has_pointer (tabname, LOG_TEMP_TABLE)) { A4GL_add_pointer (tabname, LOG_TEMP_TABLE, (void *) 1); }
      if (A4GLSQLCV_check_requirement ("ADD_WITH_OIDS"))
	{
	  SPRINTF2 (ptr, "DECLARE GLOBAL TEMPORARY TABLE SESSION.%s ( %s ) ON COMMIT PRESERVE ROWS WITH NORECOVERY", tabname,
		    A4GL_space_out (elements));
	}
      else
	{
	  SPRINTF2 (ptr, "DECLARE GLOBAL TEMPORARY TABLE SESSION.%s ( %s ) ON COMMIT PRESERVE ROWS WITH NORECOVERY", tabname,
		    A4GL_space_out (elements));
	}
      return ptr;
    }

  if (A4GLSQLCV_check_requirement ("CREATE_TEMP_AS_CREATE_HASH"))
    {
      if (A4GLSQLCV_check_requirement ("ADD_WITH_OIDS"))
	{
	  SPRINTF4 (ptr, "CREATE TABLE #%s (%s) WITH OIDS %s %s", tabname, elements, extra, oplog);
	}
      else
	{
	  SPRINTF4 (ptr, "CREATE TABLE #%s (%s) %s %s", tabname, elements, extra, oplog);
	}
      return ptr;
    }

  if (A4GLSQLCV_check_requirement ("CREATE_TEMP_AS_GLOBAL_TEMP_DELETE"))
    {
      if (A4GLSQLCV_check_requirement ("ADD_WITH_OIDS"))
	{
	  SPRINTF2 (ptr, "CREATE GLOBAL TEMPORARY TABLE %s (%s) WITH OIDS ON COMMIT DELETE ROWS", tabname, elements);
	}
      else
	{
	  SPRINTF2 (ptr, "CREATE GLOBAL TEMPORARY TABLE %s (%s) ON COMMIT DELETE ROWS", tabname, elements);
	}
      return ptr;
    }

  if (A4GLSQLCV_check_requirement ("CREATE_TEMP_AS_GLOBAL_TEMP_PRESERVE"))
    {
      if (A4GLSQLCV_check_requirement ("ADD_WITH_OIDS"))
	{
	  SPRINTF2 (ptr, "CREATE GLOBAL TEMPORARY TABLE %s (%s) WITH OIDS ON COMMIT PRESERVE ROWS", tabname, elements);
	}
      else
	{
	  SPRINTF2 (ptr, "CREATE GLOBAL TEMPORARY TABLE %s (%s) ON COMMIT PRESERVE ROWS", tabname, elements);
	}
      return ptr;
    }

  if (A4GLSQLCV_check_requirement ("TEMP_AS_GLOBAL_TEMPORARY"))
    {
      if (A4GLSQLCV_check_requirement ("ADD_WITH_OIDS"))
	{
	  SPRINTF4 (ptr, "CREATE GLOBAL TEMPORARY TABLE %s (%s) WITH OIDS %s %s", tabname, elements, extra, oplog);
	}
      else
	{
	  SPRINTF4 (ptr, "CREATE GLOBAL TEMPORARY TABLE %s (%s) %s %s", tabname, elements, extra, oplog);
	}
      return ptr;
    }

  if (A4GLSQLCV_check_requirement ("TEMP_AS_TEMPORARY"))
    {
      if (A4GLSQLCV_check_requirement ("ADD_WITH_OIDS"))
	{
	  SPRINTF4 (ptr, "CREATE TEMPORARY TABLE %s (%s) WITH OIDS %s %s", tabname, elements, extra, oplog);
	}
      else
	{
	  SPRINTF4 (ptr, "CREATE TEMPORARY TABLE %s (%s) %s %s", tabname, elements, extra, oplog);
	}
      return ptr;
    }

  if (A4GLSQLCV_check_requirement ("ADD_WITH_OIDS"))
    {
      SPRINTF4 (ptr, "CREATE TEMP TABLE %s (%s) WITH OIDS %s %s", tabname, elements, extra, oplog);
    }
  else
    {
      SPRINTF4 (ptr, "CREATE TEMP TABLE %s (%s) %s %s", tabname, elements, extra, oplog);
    }
  return ptr;
}



char *
A4GLSQLCV_rencol (char *tabname, char *colname, char *ncolname)
{
  static char buff[256];
  if (A4GLSQLCV_check_requirement ("RENAME_COLUMN_AS_ALTER_TABLE"))
    {
      SPRINTF3 (buff, "ALTER TABLE %s RENAME COLUMN %s TO %s", tabname, colname, ncolname);
    }
  else
    {
      SPRINTF3 (buff, "RENAME COLUMN %s.%s TO %s", tabname, colname, ncolname);
    }
  return buff;
}

char *
A4GLSQLCV_rentab (char *tabname, char *ntabname)
{
  static char buff[256];
  if (A4GLSQLCV_check_requirement ("RENAME_TABLE_AS_ALTER_TABLE"))
    {
      SPRINTF2 (buff, "ALTER TABLE %s RENAME TO %s", tabname, ntabname);
    }
  else
    {
      SPRINTF2 (buff, "RENAME TABLE %s TO %s", tabname, ntabname);
    }
  return buff;
}


/*
string can be USER or TODAY - return the equivilent...
*/
char *
A4GLSQLCV_get_sqlconst (char *s)
{
  int b;
//char *c;
//static char buff[200];
  for (b = 0; b < current_conversion_rules_cnt; b++)
    {
      if (current_conversion_rules[b].type == CVSQL_REPLACE_SQLCONST)
	{
	  if (A4GL_aubit_strcasecmp (s, current_conversion_rules[b].data.from) == 0)
	    {
	      char *to;
	      if (current_conversion_rules[b].data.to[0] == '$')
		{
		  to = get_dollared_sql_var (current_conversion_rules[b].data.to);
		}
	      else
		{
		  to = current_conversion_rules[b].data.to;
		}

	      return to;
	    }
	}
    }

  for (b = 0; b < current_conversion_rules_cnt; b++)
    {
      if (current_conversion_rules[b].type == CVSQL_REPLACE_EXPR)
	{
	  if (A4GL_aubit_strcasecmp (s, current_conversion_rules[b].data.from) == 0)
	    {
	      char *to;
	      if (current_conversion_rules[b].data.to[0] == '$')
		{
		  to = get_dollared_sql_var (current_conversion_rules[b].data.to);
		}
	      else
		{
		  to = current_conversion_rules[b].data.to;
		}
	      return to;
	    }
	}
    }
  if (strcmp (s, "TRUE") == 0)
    return "1";
  if (strcmp (s, "FALSE") == 0)
    return "0";
  return s;
}


static int
sql_convert_func (char *srcfmt, char *srcparam, char *dstbuf, int dstbuf_size)
{
  int i, len;
  char *fmt;
  char *param;
  char *tparam[10];
  int dstidx;
  int param_count;
  int param_start;
  int j;

  memset (dstbuf, 0, dstbuf_size);

  if (srcfmt == NULL)
    {
      dstbuf[0] = 0;
      return 0;
    }

  if (strstr (srcfmt, "%s"))	// simple conversion
    {
      SPRINTF1 (dstbuf, srcfmt, srcparam ? srcparam : "");
      return 0;
    }

  memset (tparam, 0, sizeof (tparam));
  param = strdup (srcparam ? srcparam : "");
  len = strlen (param);
  param_start = 0;
  param_count = 0;
  for (i = 0; i < len; ++i)
    {
      if (param_count > 9)
	break;
      if (param[i] == ',' || i == len - 1)
	{
	  if (param[i] == ',')
	    param[i] = 0;
	  tparam[param_count++] = param + param_start;
	  param_start = i + 1;
	}
    }

  fmt = strdup (srcfmt);
  len = strlen (fmt);
  dstbuf[0] = fmt[0];
  dstidx = 0;
  for (i = 0; i < len; ++i)
    {
      if (dstidx >= dstbuf_size - 1)
	{
	  acl_free (param);
	  acl_free (fmt);
	  return 0;
	}
      if (fmt[i] == '%' && fmt[i + 1] >= '1' && fmt[i + 1] <= '9')
	{
	  if (tparam[fmt[i + 1] - '1'] != NULL)
	    {
	      for (j = 0; tparam[fmt[i + 1] - '1'][j] != 0; ++j)
		{
		  if (dstidx >= dstbuf_size - 1)
		    {
		      acl_free (param);
		      acl_free (fmt);
		      return 0;
		    }
		  dstbuf[dstidx++] = tparam[fmt[i + 1] - '1'][j];
		}
	    }
	  ++i;
	}
      else
	dstbuf[dstidx++] = fmt[i];
    }
  acl_free (param);
  acl_free (fmt);
  return 1;
}

char *
A4GLSQLCV_sql_func (char *f, char *param)
{
  static char buff[256];
  int b;

  if (param == 0)
    param = "";
  SPRINTF2 (buff, "%s(%s)", f, param);

  if (!A4GL_compile_time_convert ())
    return buff;

  for (b = 0; b < current_conversion_rules_cnt; b++)
    {
      if (current_conversion_rules[b].type == CVSQL_REPLACE_SQLFUNC)
	{
	  if (A4GL_aubit_strcasecmp (f, current_conversion_rules[b].data.from) == 0)
	    {
	      if (sql_convert_func (current_conversion_rules[b].data.to, param, buff, sizeof (buff)) == 0)
		{
		  A4GL_debug ("Conversion error (CVSQL_REPLACE_SQLFUNC) %s->%s(%s)",
			      current_conversion_rules[b].data.from, current_conversion_rules[b].data.to, param);
		}
	      break;
	    }
	}
    }
  return buff;
}



char *
A4GLSQLCV_make_case (struct s_select *select, struct s_sli_case *i)
{
  struct s_sli_case_element *ii;
  static char buff[10000];
  char small_buff1[1000];
  char small_buff2[1000];
  //char small_buff3[1000];
  struct s_select_list_item *p;
  int a;
  if (A4GLSQLCV_check_requirement ("CASE_AS_PROCEDURE"))
    {
      if (i->elements.elements_len == 2)
	{
	  p = i->elements.elements_val[1];
	  if (p->data.s_select_list_item_data_u.sqlcaseelement.condition == 0)
	    {
	      // Looks like an IF - THEN - ELSE 
	      //
	      SPRINTF3 (buff, "DECODE(%s,%s,%s)",
			get_select_list_item (select,
					      i->elements.elements_val[0]->data.s_select_list_item_data_u.
					      sqlcaseelement.condition),
			get_select_list_item (select,
					      i->elements.elements_val[0]->data.s_select_list_item_data_u.
					      sqlcaseelement.response),
			get_select_list_item (select,
					      i->elements.elements_val[1]->data.s_select_list_item_data_u.sqlcaseelement.response));
	      return buff;
	    }
	}
      SPRINTF0 (buff, "casefunc(");

    }
  else
    {
      strcpy (buff, "CASE");
      for (a = 0; a < i->elements.elements_len; a++)
	{
	  p = i->elements.elements_val[a];
	  ii = &p->data.s_select_list_item_data_u.sqlcaseelement;
	  if (ii->condition)
	    {
	      SPRINTF1 (small_buff1, " WHEN %s THEN ", get_select_list_item (select, ii->condition));
	    }
	  else
	    {
	      SPRINTF0 (small_buff1, " ELSE ");
	    }
	  strcat (buff, small_buff1);
	  strcpy (small_buff2, get_select_list_item (select, ii->response));
	  strcat (buff, small_buff2);
	}
      strcat (buff, " END");
    }

  return buff;
}

char *
A4GLSQLCV_check_tablename (char *t)
{
  static char b2[200];
  static char buff1[2000];
  char *ptr;
  char *codeu;
  A4GL_debug ("TABLE : %s\n", t);

  // runtime mapping of table names
  codeu = strdup (t);
  A4GL_convupper (codeu);
  ptr = A4GL_find_pointer (codeu, RUNTIME_MAPPED_TNAME);
  if (ptr)
    {
      A4GL_debug ("table name mapped: \"%s\"(code) \"%s\"(db)\n", codeu, ptr);
      t = ptr;
    }
  acl_free (codeu);

  if (strstr (t, "amarta") && A4GL_isyes (acl_getenv ("AMARTA_TO_SOAL")))
    {
      int a;
      int b;
      b = 0;
      for (a = 0; a < strlen (t); a++)
	{
	  if (strncmp (&t[a], "amarta", 6) == 0)
	    {
	      buff1[b++] = 's';
	      buff1[b++] = 'o';
	      buff1[b++] = 'a';
	      buff1[b++] = 'l';
	      a += 5;
	    }
	  else
	    {
	      buff1[b++] = t[a];
	    }
	}
      t = buff1;
    }



  if (A4GL_has_pointer (t, LOG_TEMP_TABLE))
    {
      if (A4GLSQLCV_check_requirement ("CREATE_TEMP_AS_CREATE_HASH") ||
	  A4GLSQLCV_check_requirement ("SELECT_INTO_TEMP_INTO_TEMP_HASH") ||
	  A4GLSQLCV_check_requirement ("SELECT_INTO_TEMP_INTO_HASH"))
	{
	  SPRINTF1 (b2, "#%s", t);
	  return b2;
	}
    }


  if (A4GLSQLCV_check_requirement ("ADD_SESSION_TO_TEMP_TABLE"))
    {
      if (A4GL_has_pointer (t, LOG_TEMP_TABLE))
	{
	  SPRINTF1 (b2, "session.%s", t);
	  return b2;
	}
    }

  if (A4GLSQLCV_check_requirement ("ESCAPE_PLAN"))
    {
      if (is_sqlserver_reserved_word (t))
	{
	  static char buff[256];
	  SPRINTF1 (buff, "[%s]", t);
	  return buff;
	}
    }

  return t;
}

char *
A4GLSQLCV_make_tablename (char *t, char *c)
{
  static char buff[400];
  char b2[200];
  int doneSession = 0;
  A4GL_debug ("Make_tablename : %s ", t);
  if (c)
    {
      A4GL_debug ("Alias= %s", c);
    }

  if (A4GLSQLCV_check_requirement ("ADD_SESSION_TO_TEMP_TABLE"))
    {
      if (A4GL_has_pointer (t, LOG_TEMP_TABLE))
	{
	  SPRINTF1 (b2, "session.%s", t);
	  doneSession = 1;
	  if (c == 0 || strlen (c) == 0)
	    {
	      c = t;
	    }
	  t = b2;
	}
    }



  if (c && strlen (c) && A4GL_aubit_strcasecmp (c, t) != 0)
    {
      if (A4GLSQLCV_check_requirement ("TABLE_ALIAS_AS"))
	{
	  SPRINTF2 (buff, "%s AS %s", t, c);
	}
      else
	{
	  SPRINTF2 (buff, "%s %s", t, c);
	}
    }
  else
    {
      SPRINTF1 (buff, "%s", t);
    }
  return buff;
}


#ifdef DOING_CM

static char *
get_dollared_sql_var (char *s)
{
  static char buff[256];
  return "Not";
}
#else

static char *
get_dollared_sql_var (char *s)
{
  static char buff[256];
  char buff2[256];
  char *c;

  if (A4GL_aubit_strcasecmp (s, "$TODAY") == 0)
    {
      A4GL_push_today ();
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }

  if (A4GL_aubit_strcasecmp (s, "$TIME") == 0)
    {
      A4GL_push_time ();
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }

  if (A4GL_aubit_strcasecmp (s, "$USER") == 0)
    {
      A4GL_push_user ();
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }


  if (A4GL_aubit_strcasecmp (s, "$DBUSER") == 0)
    {
      SPRINTF1 (buff, "'%s'", A4GL_get_connection_username ());
      acl_free (c);
      return buff;
    }

  if (A4GL_aubit_strcasecmp (s, "$CURRENT_YEAR_YEAR") == 0)
    {
      A4GL_push_current (1, 1);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_YEAR_MONTH") == 0)
    {
      A4GL_push_current (1, 2);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_YEAR_DAY") == 0)
    {
      A4GL_push_current (1, 3);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_YEAR_HOUR") == 0)
    {
      A4GL_push_current (1, 4);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_YEAR_MINUTE") == 0)
    {
      A4GL_push_current (1, 5);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_YEAR_SECOND") == 0)
    {
      A4GL_push_current (1, 6);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_YEAR_FRACTION1") == 0)
    {
      A4GL_push_current (1, 7);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_YEAR_FRACTION2") == 0)
    {
      A4GL_push_current (1, 8);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_YEAR_FRACTION3") == 0)
    {
      A4GL_push_current (1, 9);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_YEAR_FRACTION4") == 0)
    {
      A4GL_push_current (1, 10);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_YEAR_FRACTION5") == 0)
    {
      A4GL_push_current (1, 10);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s0'", c);
      acl_free (c);
      return buff;
    }				// ,11 aint working yet..

  if (A4GL_aubit_strcasecmp (s, "$CURRENT_MONTH_MONTH") == 0)
    {
      A4GL_push_current (2, 2);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_MONTH_DAY") == 0)
    {
      A4GL_push_current (2, 3);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_MONTH_HOUR") == 0)
    {
      A4GL_push_current (2, 4);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_MONTH_MINUTE") == 0)
    {
      A4GL_push_current (2, 5);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_MONTH_SECOND") == 0)
    {
      A4GL_push_current (2, 6);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_MONTH_FRACTION1") == 0)
    {
      A4GL_push_current (2, 7);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_MONTH_FRACTION2") == 0)
    {
      A4GL_push_current (2, 8);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_MONTH_FRACTION3") == 0)
    {
      A4GL_push_current (2, 9);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_MONTH_FRACTION4") == 0)
    {
      A4GL_push_current (2, 10);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_MONTH_FRACTION5") == 0)
    {
      A4GL_push_current (2, 10);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s0'", c);
      acl_free (c);
      return buff;
    }				// ,11 aint working yet..

  if (A4GL_aubit_strcasecmp (s, "$CURRENT_DAY_DAY") == 0)
    {
      A4GL_push_current (3, 3);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_DAY_HOUR") == 0)
    {
      A4GL_push_current (3, 4);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_DAY_MINUTE") == 0)
    {
      A4GL_push_current (3, 5);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_DAY_SECOND") == 0)
    {
      A4GL_push_current (3, 6);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_DAY_FRACTION1") == 0)
    {
      A4GL_push_current (3, 7);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_DAY_FRACTION2") == 0)
    {
      A4GL_push_current (3, 8);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_DAY_FRACTION3") == 0)
    {
      A4GL_push_current (3, 9);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_DAY_FRACTION4") == 0)
    {
      A4GL_push_current (3, 10);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_DAY_FRACTION5") == 0)
    {
      A4GL_push_current (3, 10);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s0'", c);
      acl_free (c);
      return buff;
    }				// ,11 aint working yet..

  if (A4GL_aubit_strcasecmp (s, "$CURRENT_HOUR_HOUR") == 0)
    {
      A4GL_push_current (4, 4);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_HOUR_MINUTE") == 0)
    {
      A4GL_push_current (4, 5);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_HOUR_SECOND") == 0)
    {
      A4GL_push_current (4, 6);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_HOUR_FRACTION1") == 0)
    {
      A4GL_push_current (4, 7);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_HOUR_FRACTION2") == 0)
    {
      A4GL_push_current (4, 8);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_HOUR_FRACTION3") == 0)
    {
      A4GL_push_current (4, 9);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_HOUR_FRACTION4") == 0)
    {
      A4GL_push_current (4, 10);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_HOUR_FRACTION5") == 0)
    {
      A4GL_push_current (4, 10);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s0'", c);
      acl_free (c);
      return buff;
    }				// ,11 aint working yet..

  if (A4GL_aubit_strcasecmp (s, "$CURRENT_MINUTE_MINUTE") == 0)
    {
      A4GL_push_current (5, 5);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_MINUTE_SECOND") == 0)
    {
      A4GL_push_current (5, 6);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_MINUTE_FRACTION1") == 0)
    {
      A4GL_push_current (5, 7);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_MINUTE_FRACTION2") == 0)
    {
      A4GL_push_current (5, 8);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_MINUTE_FRACTION3") == 0)
    {
      A4GL_push_current (5, 9);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_MINUTE_FRACTION4") == 0)
    {
      A4GL_push_current (5, 10);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_MINUTE_FRACTION5") == 0)
    {
      A4GL_push_current (5, 10);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s0'", c);
      acl_free (c);
      return buff;
    }				// ,11 aint working yet..


  if (A4GL_aubit_strcasecmp (s, "$CURRENT_SECOND_SECOND") == 0)
    {
      A4GL_push_current (6, 6);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_SECOND_FRACTION1") == 0)
    {
      A4GL_push_current (6, 7);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_SECOND_FRACTION2") == 0)
    {
      A4GL_push_current (6, 8);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_SECOND_FRACTION3") == 0)
    {
      A4GL_push_current (6, 9);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_SECOND_FRACTION4") == 0)
    {
      A4GL_push_current (6, 10);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s'", c);
      acl_free (c);
      return buff;
    }
  if (A4GL_aubit_strcasecmp (s, "$CURRENT_SECOND_FRACTION5") == 0)
    {
      A4GL_push_current (6, 10);
      c = A4GL_char_pop ();
      SPRINTF1 (buff, "'%s0'", c);
      acl_free (c);
      return buff;
    }				// ,11 aint working yet..


  SPRINTF0 (buff2, &s[1]);
  if (acl_getenv_not_set_as_0 (buff2))
    {
      strcpy (buff, acl_getenv_not_set_as_0 (buff2));
      return buff;
    }
  strcpy (buff, s);
  return buff;
}
#endif


char *
A4GL_space_out (char *s)
{
  static char *ptr = 0;
  int a;
  int b = 0;
  int in_dbl = 0;
  int in_single = 0;

  if (ptr)
    acl_free (ptr);

  ptr = acl_malloc2 (strlen (s) * 2 + 1);


  for (a = 0; a < strlen (s); a++)
    {
      if (in_dbl)
	{
	  if (s[a] == '\"')
	    in_dbl = 0;
	  ptr[b++] = s[a];
	  continue;
	}

      if (in_single)
	{
	  if (s[a] == '\'')
	    in_single = 0;
	  ptr[b++] = s[a];
	  continue;
	}

      if (s[a] == '\'')
	in_single = 1;
      if (s[a] == '"')
	in_dbl = 1;

      if (s[a] == ',')
	{
	  ptr[b++] = '\n';
	  ptr[b++] = ',';
	}
      else
	{
	  ptr[b++] = s[a];
	}
    }


  ptr[b] = 0;
  return ptr;
}


static void
add_table_mapping (char *db, char *instance, char *tab, char *newtab)
{
  ntable_mappings++;
  A4GL_debug ("ADD MAP db=%s inst=%s tab=%s newtab=%s\n", db, instance, tab, newtab);
  table_mappings = acl_realloc (table_mappings, sizeof (struct table_remap) * ntable_mappings);
  table_mappings[ntable_mappings - 1].orig_db = strdup (db);
  table_mappings[ntable_mappings - 1].orig_instance = strdup (instance);
  table_mappings[ntable_mappings - 1].tabname = strdup (tab);
  table_mappings[ntable_mappings - 1].newtabname = strdup (newtab);
}

static void
load_table_mappings (void)
{
  char *ptr;
  ptr = acl_getenv ("TABLE_MAP");
  if (ptr)
    {
      if (strlen (ptr))
	{
	  load_table_mappings_i (ptr);
	}
    }
  ptr = acl_getenv ("LOCAL_COLUMN_MAP");
  if (ptr)
    {
      if (strlen (ptr))
	{
	  load_table_mappings_i (ptr);
	}
    }
}


static void
load_table_mappings_i (char *ptr)
{
  FILE *f;
  char buff[256];
  char *t;
  char *c1;
  char *c2;
  char *c;
  char db[200];
  char inst[200];
  char tabname[200];

  f = fopen (ptr, "r");
  if (f == 0)
    return;


  while (1)
    {
      char *p_at;
      char *p_colon;
      c1 = 0;
      c2 = 0;
      c = fgets (buff, 256, f);
      if (!c)
	break;
      A4GL_trim_nl (buff);
      if (buff[0] == '*')
	continue;
      t = buff;
      c1 = strchr (buff, ' ');
      if (c1)
	{
	  *c1 = 0;
	  c1++;
	}

      strcpy (db, "");
      strcpy (inst, "");
      strcpy (tabname, "");
      p_at = strchr (t, '@');
      p_colon = strchr (t, ':');

      if (p_at)
	{
	  if (p_colon)
	    {
	      *p_colon = 0;
	      p_colon++;
	      *p_at = 0;
	      p_at++;
	      strcpy (db, buff);
	      strcpy (inst, p_at);
	      strcpy (tabname, p_colon);
	    }
	  else
	    {
	      *p_at = 0;
	      p_at++;
	      strcpy (tabname, buff);
	      strcpy (inst, p_at);
	    }
	}
      else
	{
	  if (strchr (t, ':'))
	    {
	      *p_colon = 0;
	      p_colon++;
	      strcpy (db, buff);
	      strcpy (tabname, p_colon);
	    }
	  else
	    {
	      strcpy (tabname, buff);
	    }
	}

      add_table_mapping (db, inst, tabname, c1);
    }
}


static void
add_mapping (char *t, char *c1, char *c2)
{
  ncolumn_mappings++;
  column_mappings = acl_realloc (column_mappings, sizeof (struct column_remap) * ncolumn_mappings);
  column_mappings[ncolumn_mappings - 1].tabname = strdup (t);
  column_mappings[ncolumn_mappings - 1].from_col = strdup (c1);
  column_mappings[ncolumn_mappings - 1].to_col = strdup (c2);
}

static void
load_column_mappings (void)
{
  char *ptr;
  ptr = acl_getenv ("COLUMN_MAP");
  if (ptr)
    {
      if (strlen (ptr))
	{
	  load_column_mappings_i (ptr);
	}
    }
  ptr = acl_getenv ("LOCAL_COLUMN_MAP");
  if (ptr)
    {
      if (strlen (ptr))
	{
	  load_column_mappings_i (ptr);
	}
    }
}




static void
load_column_mappings_i (char *ptr)
{
  FILE *f;
  char buff[256];
  char *t;
  char *c1;
  char *c2;
  char *c;
  //ptr = acl_getenv ("COLUMN_MAP");

  f = fopen (ptr, "r");
  if (f == 0)
    return;


  while (1)
    {
      c1 = 0;
      c2 = 0;
      c = fgets (buff, 256, f);
      if (!c)
	break;
      A4GL_trim_nl (buff);
      if (buff[0] == '*')
	continue;
      t = buff;
      c1 = strchr (buff, ' ');
      if (c1)
	{
	  *c1 = 0;
	  c1++;
	}
      if (c1)
	{
	  c2 = strchr (c1, ' ');
	  if (c2)
	    {
	      *c2 = 0;
	      c2++;
	    }
	}
      if (c2 == 0)
	continue;
      add_mapping (t, c1, c2);
    }
}







void
chk_loaded_mappings (void)
{
  if (!loaded_columns)
    {
      loaded_columns = 1;
      load_column_mappings ();
      load_table_mappings ();
    }
}



char *
A4GL_confirm_colname (char *t, char *c)
{
  static char buff[256];
  int a;

  chk_loaded_mappings ();
  for (a = 0; a < ncolumn_mappings; a++)
    {
      if (t == 0)
	t = "<NOTSET>";
      if (strcmp (t, column_mappings[a].tabname) == 0 && strcmp (c, column_mappings[a].from_col) == 0)
	{
	  strcpy (buff, column_mappings[a].to_col);
	  return buff;
	}
    }


  strcpy (buff, c);
  return c;
}

void
A4GL_set_sql_conv (int n)
{
  set_sql_conv_success = n;
}

int
A4GL_get_sql_conv (void)
{
  return set_sql_conv_success;
}





char *sql_reserved_words[] = {
  "ADD",
  "ALL",
  "ALTER",
  "AND",
  "ANY",
  "AS",
  "ASC",
  "AUTHORIZATION",
  "BACKUP",
  "BEGIN",
  "BETWEEN",
  "BREAK",
  "BROWSE",
  "BULK",
  "BY",
  "CASCADE",
  "CASE",
  "CHECK",
  "CHECKPOINT",
  "CLOSE",
  "CLUSTERED",
  "COALESCE",
  "COLLATE",
  "COLUMN",
  "COMMIT",
  "COMPUTE",
  "CONSTRAINT",
  "CONTAINS",
  "CONTAINSTABLE",
  "CONTINUE",
  "CONVERT",
  "CREATE",
  "CROSS",
  "CURRENT",
  "CURRENT_DATE",
  "CURRENT_TIME",
  "CURRENT_TIMESTAMP",
  "CURRENT_USER",
  "CURSOR",
  "DATABASE",
  "DBCC",
  "DEALLOCATE",
  "DECLARE",
  "DEFAULT",
  "DELETE",
  "DENY",
  "DESC",
  "DISK",
  "DISTINCT",
  "DISTRIBUTED",
  "DOUBLE",
  "DROP",
  "DUMMY",
  "DUMP",
  "ELSE",
  "END",
  "ERRLVL",
  "ESCAPE",
  "EXCEPT",
  "EXEC",
  "EXECUTE",
  "EXISTS",
  "EXIT",
  "FETCH",
  "FILE",
  "FILLFACTOR",
  "FOR",
  "FOREIGN",
  "FREETEXT",
  "FREETEXTTABLE",
  "FROM",
  "FULL",
  "FUNCTION",
  "GOTO",
  "GRANT",
  "GROUP",
  "HAVING",
  "HOLDLOCK",
  "IDENTITY",
  "IDENTITYCOL",
  "IDENTITY_INSERT",
  "IF",
  "IN",
  "INDEX",
  "INNER",
  "INSERT",
  "INTERSECT",
  "INTO",
  "IS",
  "JOIN",
  "KEY",
  "KILL",
  "LEFT",
  "LIKE",
  "LINENO",
  "LOAD",
  "NATIONAL",
  "NOCHECK",
  "NONCLUSTERED",
  "NOT",
  "NULL",
  "NULLIF",
  "OF",
  "OFF",
  "OFFSETS",
  "ON",
  "OPEN",
  "OPENDATASOURCE",
  "OPENQUERY",
  "OPENROWSET",
  "OPENXML",
  "OPTION",
  "OR",
  "ORDER",
  "OUTER",
  "OVER",
  "PERCENT",
  "PLAN",
  "PRECISION",
  "PRIMARY",
  "PRINT",
  "PROC",
  "PROCEDURE",
  "PUBLIC",
  "RAISERROR",
  "READ",
  "READTEXT",
  "RECONFIGURE",
  "REFERENCES",
  "REPLICATION",
  "RESTORE",
  "RESTRICT",
  "RETURN",
  "REVOKE",
  "RIGHT",
  "ROLLBACK",
  "ROWCOUNT",
  "ROWGUIDCOL",
  "RULE",
  "SAVE",
  "SCHEMA",
  "SELECT",
  "SESSION_USER",
  "SET",
  "SETUSER",
  "SHUTDOWN",
  "SOME",
  "STATISTICS",
  "SYSTEM_USER",
  "TABLE",
  "TEXTSIZE",
  "THEN",
  "TO",
  "TOP",
  "TRAN",
  "TRANSACTION",
  "TRIGGER",
  "TRUNCATE",
  "TSEQUAL",
  "UNION",
  "UNIQUE",
  "UPDATE",
  "UPDATETEXT",
  "USE",
  "USER",
  "VALUES",
  "VARYING",
  "VIEW",
  "WAITFOR",
  "WHEN",
  "WHERE",
  "WHILE",
  "WITH",
  "WRITETEXT",
  0
};

int
is_sqlserver_reserved_word (char *s)
{
  int a;
  for (a = 0; sql_reserved_words[a]; a++)
    {
      int c;
      c = A4GL_aubit_strcasecmp (s, sql_reserved_words[a]);
      if (c < 0)
	{
	  break;
	}
      if (A4GL_aubit_strcasecmp (s, sql_reserved_words[a]) == 0)
	return 1;
    }
  return 0;
}


/*
int  A4GL_aubit_strcasestr (char *h, char *n) {
	char *s1;
	char *s2;
	int rval;
	int l1;
	 int l2;
	int a;

	s1=strdup(h);
	s2=strdup(n);
	l1=strlen(s1);
	l2=strlen(s2);
	for (a=0;a<l1;a++) { s1[a]=toupper(h[a]); }
	for (a=0;a<l2;a++) { s2[a]=toupper(n[a]); }

	if (strstr(s1,s2)) rval=1;
	else rval=0;

	acl_free(s1);
	acl_free(s2);
	return rval;
}*/

void
A4GL_set_compile_time_convert (int a)
{
  is_compile_time_convert = a;
}

int
A4GL_compile_time_convert (void)
{
  return is_compile_time_convert;
}


int
A4GL_new_escape_quote_owner (void)
{
  return 0;

  if (A4GLSQLCV_check_requirement ("QUOTE_OWNER"))

    {
      return 1;
    }
  if (A4GLSQLCV_check_requirement ("NO_OWNER_QUOTE"))
    {
      return 0;
    }
  if (strcmp (acl_getenv ("A4GL_LEXTYPE"), "EC") == 0)
    {
      return 0;
    }
  return 1;
}

char *
A4GLSQLCV_db_tablename (char *dbname, char *instance, char *ownerized_tablename)
{
  static char buff[512];
  int a;
  chk_loaded_mappings ();
  if (A4GL_isyes (acl_getenv ("ALWAYSIGNDBNAMETAB")))
    {
      dbname = NULL;
      instance = NULL;
    }

  if (dbname == NULL && instance == NULL)
    {
      strcpy (buff, ownerized_tablename);
    }
  else
    {
      if (instance == NULL)
	{
	  SPRINTF2 (buff, "%s:%s", dbname, ownerized_tablename);
	}
      else
	{
	  if (dbname == NULL)
	    {
	      SPRINTF2 (buff, "%s@%s", instance, ownerized_tablename);
	    }
	  else
	    {
	      SPRINTF3 (buff, "%s@%s:%s", dbname, instance, ownerized_tablename);
	    }
	}
    }
  if (dbname == 0)
    dbname = "";
  if (instance == 0)
    instance = "";
  for (a = 0; a < ntable_mappings; a++)
    {
      if (strcmp (table_mappings[a].orig_db, dbname) != 0)
	continue;
      if (strcmp (table_mappings[a].orig_instance, instance) != 0)
	continue;
      if (strcmp (table_mappings[a].tabname, ownerized_tablename) != 0)
	continue;
      return table_mappings[a].newtabname;
    }
  return buff;
}

char *
A4GLSQLCV_ownerize_tablename (char *owner, char *table)
{
  static char *buf = NULL;
  static int allocSize = 0;
  static int forceNoQuoteOwner = 0;
  static int ignoreOwner = 0;
  static int escapeQuoteOwner = 0;
  static char *defaultOwner = NULL;
  int newSize;

  chk_loaded_mappings ();

  newSize = (defaultOwner ? strlen (defaultOwner) : 0) + (owner ? strlen (owner) : 0) + strlen (table) + 10;
  if (newSize > allocSize)
    {
      buf = acl_realloc (buf, newSize);
      if (allocSize == 0)	// first pass - initialize statics
	{
	  if (A4GLSQLCV_check_requirement ("STRIP_QUOTES_FROM_OWNER"))
	    forceNoQuoteOwner = 1;
	  if (A4GLSQLCV_check_requirement ("IGNORE_OWNER"))
	    ignoreOwner = 1;
	  if (A4GL_new_escape_quote_owner ())
	    escapeQuoteOwner = 1;
	}
      allocSize = newSize;
    }
  defaultOwner = acl_getenv ("A4GL_DEFAULT_OWNER");
  if (defaultOwner)
    {
      A4GL_trim (defaultOwner);
      if (strlen (defaultOwner) == 0)
	defaultOwner = NULL;
    }

  if (ignoreOwner)
    {
      SPRINTF1 (buf, "%s", table);
      return A4GLSQLCV_check_tablename (buf);
//        return buf;
    }
  else
    {
      if (defaultOwner && !owner)	// default owner given and no owner specified in parameter
	owner = defaultOwner;

      if (forceNoQuoteOwner)
	{
	  if (owner)
	    SPRINTF2 (buf, "%s.%s", A4GL_strip_quotes (owner), table);
	  else
	    SPRINTF1 (buf, "%s", table);
	  return A4GLSQLCV_check_tablename (buf);
//            return buf;
	}
      if (escapeQuoteOwner)
	{
	  if (owner)
	    SPRINTF2 (buf, "\\\"%s\\\".%s", A4GL_strip_quotes (owner), table);
	  else
	    SPRINTF1 (buf, "%s", table);
	  return A4GLSQLCV_check_tablename (buf);
//            return buf;
	}
      else
	{
	  if (owner)
	    SPRINTF2 (buf, "\"%s\".%s", A4GL_strip_quotes (owner), table);
	  else
	    SPRINTF1 (buf, "%s", table);
	  return A4GLSQLCV_check_tablename (buf);
//            return buf;
	}
    }
}


void
A4GL_free_select_stmt (struct s_select *s)
{
  int a;
  if (s->table_elements.tables.tables_len)
    {
      for (a = 0; a < s->table_elements.tables.tables_len; a++)
	{
	  if (s->table_elements.tables.tables_val[a].tabname)
	    free (s->table_elements.tables.tables_val[a].tabname);
	  if (s->table_elements.tables.tables_val[a].alias)
	    free (s->table_elements.tables.tables_val[a].alias);
	}
    }
  free (s->table_elements.tables.tables_val);
  s->table_elements.tables.tables_len = 0;
  s->table_elements.tables.tables_val = 0;
}



char *
A4GLSQLCV_get_forupdate (char *collist)
{
  static char buff[2000];
  if (A4GLSQLCV_check_requirement ("FOR_UPDATE_DROP_COLLIST"))
    {
      collist = NULL;
    }
  if (A4GLSQLCV_check_requirement ("NO_FOR_UPDATE") || A4GLSQLCV_check_requirement ("EMULATE_FOR_UPDATE"))
    {
      strcpy (buff, "");
    }
  else
    {
      if (collist)
	{

	  SPRINTF1 (buff, " FOR UPDATE OF %s", collist);
	}
      else
	{
	  SPRINTF0 (buff, " FOR UPDATE");
	}
    }


  if (A4GLSQLCV_check_requirement ("FOR_UPDATE_NOWAIT"))
    {
      strcat (buff, " NOWAIT");
    }
  return buff;
}


int aclfgl_aclfgl_get_sql_requirement(int n) {
char *p;
int b;
	p=A4GL_char_pop();

  for (b = 0; b < current_conversion_rules_cnt; b++)
    {
      if (current_conversion_rules[b].type == CVSQL_BUILTINSQL)
	{
	  if (A4GL_aubit_strcasecmp (p, current_conversion_rules[b].data.from) == 0)
	    {
		A4GL_push_char(current_conversion_rules[b].data.to);
		free(p);
		return 1;
	    }
	}
    }
A4GL_push_char(acl_getenv(p));

free(p);
return 1;
}


int A4GL_remap_nativeerror(int n, char *sqlstate) {
int b;
  for (b = 0; b < current_conversion_rules_cnt; b++)
    {
      if (current_conversion_rules[b].type == CVSQL_REMAP_ERROR)
        {
	long l;

	if (sqlstate!=NULL) {
          if (A4GL_aubit_strcasecmp (sqlstate, current_conversion_rules[b].data.from) == 0)
            {
		return atol(current_conversion_rules[b].data.to);
            }
	}

	  l=atol(current_conversion_rules[b].data.from);
	  if (l==0) continue;
          if (l==n || l==n*-1) 
            {
		return atol(current_conversion_rules[b].data.to);
            }
	
        }

    }

return n;

}

// call with string, repl, with
// eg aclfgl_replace_in_string("a4gl -d %d", "%d","dbname")
int aclfgl_aclfgl_replace_in_string(int n)  {
char *sub_in;
char *old_string;
char *new_string;
char buff[10000];
int cnt;
new_string=A4GL_char_pop();
old_string=A4GL_char_pop();
sub_in=A4GL_char_pop();
cnt=0;
memset(buff,' ',1000);
strncpy(buff,sub_in,strlen(sub_in));
while (1) {
	char *ptr;
	ptr=strstr(buff,old_string);
	if (ptr==0) break;
	A4GL_cv_replacestr(ptr,strlen(old_string),new_string);
 	if (cnt>100) {A4GL_exitwith("Recurrsive replacement?");}
}
A4GL_trim(buff);
A4GL_push_char(buff);
return 1;
}
