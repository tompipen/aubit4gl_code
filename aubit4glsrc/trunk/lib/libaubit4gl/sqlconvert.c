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
# $Id: sqlconvert.c,v 1.7 2003-05-15 07:10:40 mikeaubury Exp $
#
*/

/**
 * @file
 * SQL syntax conversion functions.
 *
 * The only function that should be called here is:
 *
 *     convert_sql( source_dialect, target_dialect, sql_statement ) 
 *
 * This will (attempt to) convert the SQL statement from the program
 * into a form that the DBMS can handle.
 *
 */

/*
=====================================================================
                           Includes
=====================================================================
*/

#include "a4gl_libaubit4gl_int.h"

/*
=====================================================================
                          Definitions
=====================================================================
*/
#include <ctype.h>

#define isquote(x) ((x)=='\"'||(x)=='\'')
#define istabcol(x) (isalnum(x)||(x)=='.'||(x)=='_')
#define iswordch(x) (isalnum(x)||(x)=='_')
#define iscmpop(x) ((x)=='='||(x)=='!'||(x)=='>'||(x)=='<')
#define isoperator(x)  (strchr("+-*/%|^",(x)) != NULL)

/*
=====================================================================
                    Variable definitions
=====================================================================
*/

/* struct to hold list of functions from conversion file(s) */
typedef void (*func_t) (char *, char *);
struct fnlist
{
  func_t funcp;
  char *args;
  struct fnlist *next;
};
/* struct for list of conversions currently loaded */
struct cvlist
{
  char source[40];
  char target[40];
  struct fnlist *fnlistp;
  struct cvlist *next;
};
struct cvlist *cvlistptr = NULL;

/* empty string that can be pointed to */
char empty[] = "";

/*
=====================================================================
                    Function prototypes
=====================================================================
*/

struct fnlist *A4GL_cv_fnlist (char *source, char *target);
func_t A4GL_cv_str_to_func (char *p, int len);

void A4GL_cvsql_double_single (char *sql, char *args);
void A4GL_cvsql_rowid (char *sql, char *oid);
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
char *A4GL_cv_next_token (char *p, int *len, int dot);
int A4GL_cv_is_clause_word (char *p, int len);
void A4GL_cv_replacestr (char *p, int n, char *s);
void A4GL_cv_inschstr (char *p, char c);
void A4GL_cv_delchstr (char *p, int n);
char *A4GL_cv_unqstrstr (char *str, char *word);
char *A4GL_cv_lastnonblank (char *str);

/*
=====================================================================
                    Function definitions
=====================================================================
*/

/*
 * Converts an SQL command string written for a specific DBMS to
 * a format acceptable to another target DBMS.
 * 
 * @param  source   SQL dialect statement is written in
 * @param  target   SQL dialect understood by the DBMS
 * @param  sql      SQL command string
*/
void
A4GL_convert_sql (char *source_dialect, char *target_dialect, char *sql)
{
  struct fnlist *p = NULL;

  A4GL_debug ("convert_sql: source=%s, target=%s, sql=%s",
	 source_dialect, target_dialect, sql);

  if ((source_dialect == NULL) || (target_dialect == NULL) ||
      (strcmp (source_dialect, target_dialect) == 0))
    {
      return;
    }

  p = A4GL_cv_fnlist (source_dialect, target_dialect);

  while (p)
    {
      if (p->funcp)
	{
	  p->funcp (sql, p->args);
	}
      p = p->next;
    }

  A4GL_debug ("  A4GL_convert_sql returns %s", sql);
}

/*
 * Loads up conversion files and returns a pointer to a
 * linked list of conversion functions to be called.
 *
 * @param  source  source dialect
 * @param  target  target dialect
 */
struct fnlist *
A4GL_cv_fnlist (char *source, char *target)
{
  char buff[201];
  struct cvlist *cv;
  struct fnlist *p = NULL;
  FILE *fh;
  char *t;
  int len;

  /* do we have this conversion loaded ? */
  cv = cvlistptr;
  while (cv)
    {
      if ((strcasecmp (cv->source, source) == 0) &&
	  (strcasecmp (cv->target, target) == 0))
	{
	  return cv->fnlistp;
	}
      cv = cv->next;
    }

  /* no we don't, so malloc a new struct for the conversion
   * info, and load the file (named "source-target.cnv")
   */
  cv = cvlistptr;
  cvlistptr = (struct cvlist *) malloc (sizeof (struct cvlist));
  strcpy (cvlistptr->source, source);
  strcpy (cvlistptr->target, target);
  cvlistptr->fnlistp = NULL;
  if (cv)
    cv->next = cvlistptr;

  strcpy (buff, acl_getenv ("SQLCNVPATH"));

  /* FIXME: use AUBITDIR here, not hard-coded path */

  if (buff[0] == '\0')
    strcpy (buff, "/opt/aubit4gl/etc/convertsql");
  len = strlen (buff);
  sprintf (&buff[len], "/%s-%s.cnv", source, target);

  A4GL_debug ("loading sql conversion file %s", buff);

  if ((fh = fopen (buff, "r")) == NULL)
    {
      A4GL_debug ("failed to open file");
      return cvlistptr->fnlistp;	/* NULL */
    }

  /* each line of the file consists of a function name and
   * optional arguments.  Ignore lines starting with "#".
   */
  while (fgets (buff, 200, fh))
    {
      if ((t = A4GL_cv_next_token (buff, &len, 0)) == NULL)
	continue;
      if (*t == '#')
	continue;
      if (p)
	{
	  p->next = (struct fnlist *) malloc (sizeof (struct fnlist));
	  p = p->next;
	}
      else
	{
	  cvlistptr->fnlistp =
	    (struct fnlist *) malloc (sizeof (struct fnlist));
	  p = cvlistptr->fnlistp;
	}
      p->funcp = A4GL_cv_str_to_func (t, len);
      p->args = &empty[0];
      p->next = NULL;
      /* get the argument list, A4GL_strip off leading = sign */
      t += len;
      t = A4GL_cv_next_token (t, &len, 0);
      if (t && len == 1 && *t == '=')
	t = A4GL_cv_next_token ((t + len), &len, 0);
      if (t)
	{
	  len = strlen (t);
	  while (len > 0 && isspace (t[len - 1]))
	    len--;
	  if (len > 0)
	    {
	      p->args = malloc (len + 1);
	      strncpy (p->args, t, len);
	      p->args[len] = '\0';
	    }
	}
    }
  fclose (fh);

  return cvlistptr->fnlistp;
}

func_t
A4GL_cv_str_to_func (char *p, int len)
{

  if (strncasecmp (p, "REPLACE", len) == 0)
    {
      return &A4GL_cvsql_replace;
    }
  if (strncasecmp (p, "REPLACE_EXPR", len) == 0)
    {
      return &A4GL_cvsql_replace;
    }
  if (strncasecmp (p, "REPLACE_COMMAND", len) == 0)
    {
      return &A4GL_cvsql_replace;
    }
  if (strncasecmp (p, "DOUBLE_TO_SINGLE_QUOTES", len) == 0)
    {
      return &A4GL_cvsql_double_single;
    }
  if (strncasecmp (p, "MATCHES_TO_LIKE", len) == 0)
    {
      return &A4GL_cvsql_matches_like;
    }
  if (strncasecmp (p, "MATCHES_TO_REGEX", len) == 0)
    {
      return &A4GL_cvsql_matches_regex;
    }
  if (strncasecmp (p, "SUBSTRING_FUNCTION", len) == 0)
    {
      return &A4GL_cvsql_substring;
    }
  if (strncasecmp (p, "TABLE_ALIAS_AS", len) == 0)
    {
      return &A4GL_cvsql_tab_alias;
    }
  if (strncasecmp (p, "COLUMN_ALIAS_AS", len) == 0)
    {
      return &A4GL_cvsql_col_alias;
    }
  if (strncasecmp (p, "ANSI_UPDATE_SYNTAX", len) == 0)
    {
      return &A4GL_cvsql_split_update;
    }

  A4GL_debug ("NOT IMPLEMENTED: %s", p);

  return NULL;
}

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
 * Replaces the 'rowid' pseudo-column in a SQL statement
 *
 * @param   sql   string holding SQL statement
 * @param   oid   string to replace "rowid", usually "oid"
 */
void
A4GL_cvsql_rowid (char *sql, char *oid)
{
  char *t;
  int len;

  t = sql;
  while ((t = A4GL_cv_next_token (t, &len, 0)) != NULL)
    {
      char *p = 0;
      if (strncasecmp (t, "rowid", len) == 0)
	{
	  p = t;
	}
      else
	{
	  if (strncasecmp (&t[len - 6], ".rowid", 6) == 0)
	    p = &t[len - 5];
	}
      if (p > 0)
	{
	  A4GL_cv_replacestr (p, 5, oid);
	  t += strlen ("rowid") - strlen (oid);
	}
      t += len;
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
  s = malloc (n);
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

  free (s);
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

/*
 * Converts 'matches' phrase into one with 'like', or a postgresql regexp.
 *
 * eg. sql[] ="select .... where ... foo matches 'x?[a-z]*' ..."
 *  "like" -> "select .... where ... foo like 'x_y%' ..."
 *   "~"   -> "select .... where ... foo like '^x.[a-z].*' ..."
 *
 * @param   sql   string holding SQL statement
 * @param   typ   "like" or "~"
 */
void
A4GL_cvsql_matches (char *sql, char *typ)
{
  char *t_matches;
  char *t_string;
  char *p;
  int len;

  while ((t_matches = A4GL_cv_find_token (sql, "matches", 0)))
    {
      /* found 'matches', proceed only if next token is a quoted string
       */
      sql = &t_matches[7];
      if (!(t_string = A4GL_cv_next_token (sql, &len, 0)))
	break;
      sql = &t_string[len];
      if (!isquote (*t_string))
	continue;

      if (typ[0] == '~')
	{
	  /* regex: pattern must start with "^" anchor */
	  A4GL_cv_inschstr (t_string + 1, '^');
	}

      /* replace "matches" with "like" or "~",
         sql has changed, so find quoted string again
       */
      A4GL_cv_replacestr (t_matches, 7, typ);
      sql = &t_matches[strlen (typ)];
      t_string = A4GL_cv_next_token (sql, &len, 0);
      sql = &t_string[len];

      /* convert the quoted string ... */
      for (p = t_string + 1; len > 2; p++, len--)
	{
	  if (typ[0] == '~')
	    {
	      /* regex: "*" -> ".*" , "?" -> "."
	       */
	      switch (*p)
		{
		case '*':
		  A4GL_cv_inschstr (p++, '.');
		  break;
		case '?':
		  if (typ[0] == '~')
		    {
		      *p = '.';
		    }
		  else
		    {
		      *p = 'x';
		    }
		}
	    }
	  else
	    {
	      /* like:  "*" -> "%" , "?" -> "_",  escape existing "_","%"
	       */
	      switch (*p)
		{
		case '%':
		case '_':
		  A4GL_cv_inschstr (p++, '\\');
		  break;
		case '*':
		  *p = '%';
		  break;
		case '?':
		  *p = '_';
		}
	    }
	}
    }

}

/*
 * Converts col[a,b] style column subscripts to substr(col,a,b-a+1)
 *
 * @param  sql   SQL statement string
 * @param  A4GL_func  name of substring function
 */
void
A4GL_cvsql_substring (char *sql, char *func)
{
  char *t, *p;
  char *t_col = 0;
  char *t_left = 0;
  int len;

  /* seek and convert anything like  " (table.)column [ ... ] " */
  while ((t = A4GL_cv_next_token (sql, &len, 0)))
    {
      sql = &t[len];

      if (istabcol (*t))
	{
	  // we have found a possible column name, save pointer
	  if (!t_left)
	    t_col = t;
	}
      else
	{
	  if (*t == '[')
	    {
	      // we have found a left bracket, save pointer
	      if (t_col && !t_left)
		t_left = t;
	    }
	}
      if (*t == ']' && t_col && t_left)
	{
	  /* we have a closing right bracket with a previous 
	   * (table.)column name and an opening left bracket
	   * column [a,b] -> A4GL_func (column,a,b)
	   */
	  *t = ')';
	  /* assume [a,1] if we have [a] instead of [a,b] */
	  if ((p = index (t_left, ',')) == NULL || p > t)
	    {
	      A4GL_cv_replacestr (t, 0, ",1");
	    }
	  else
	    {
	      A4GL_cv_replacestr (t, 0, "+1");
	      *p = '\0';
	      A4GL_cv_replacestr (t, 0, &t_left[1]);
	      *p = ',';
	      A4GL_cv_replacestr (t, 0, "-");
	    }
	  *t_left = ',';
	  A4GL_cv_inschstr (t_col, '(');
	  A4GL_cv_replacestr (t_col, 0, func);
	  t_col = 0;
	  t_left = 0;
	}
    }

}

/*
 * Inserts 'as' between tables and alias names in a from clause
 *
 * @param  sql   SQL statement string
 */
void
A4GL_cvsql_tab_alias (char *sql, char *args)
{
  char *t;
  int len;
  int state = 0;

  /* main loop scans entire string because multiple 'from' clauses
   * are possible in 'union' selects
   */
  t = sql;
  while ((t = A4GL_cv_next_token (t, &len, 0)))
    {
      /* don't start alias checking until we reach a 'from' clause */
      if (state == 0)
	{
	  if (strncasecmp (t, "from", len) == 0)
	    state = 1;
	  t += len;
	  continue;
	}
      /* a comma or 'outer' means to expect a table name next */
      if (*t == ',' || strncasecmp (t, "outer", len) == 0)
	{
	  state = 1;
	}
      else
	{
	  /* check for any keyword that marks the end of the from clause */
	  if (A4GL_cv_is_clause_word (t, len))
	    {
	      state = 0;
	    }
	  else
	    {
	      /* this must be a table name, so expect an alias next */
	      if (state == 1)
		{
		  state = 2;
		}
	      else
		{
		  /* we already had the table name, so if this word is
		   * not "as", then it must be an alias so we insert "as"
		   */
		  if (strncasecmp (t, "as", len) == 0)
		    {
		      t = A4GL_cv_next_token ((t + len), &len, 0);
		    }
		  else
		    {
		      A4GL_cv_replacestr (t, 0, "as ");
		      t += 3;
		    }
		  state = 1;
		}
	    }
	}
      t += len;
    }

}


/*
 * Inserts 'as' before alias names in the expressions in a select list
 * eg.
 *     select code, sum(total_cost/purch_qty) unit_price, ...
 * to
 *     select code, sum(total_cost/purch_qty) AS unit_price, ...
 *
 * @param  sql   SQL statement string
 */
void
A4GL_cvsql_col_alias (char *sql, char *args)
{
  char *t;
  char *p;
  char *from;
  int len, n;

  /* main loop scans entire string because 'select' clauses
   * can appear more than once, in unions and sub-queries.
   */
  t = sql;
  while ((t = A4GL_cv_next_token (t, &len, 0)))
    {
      /* don't start alias checking until we reach a 'select' clause */

      if (strncasecmp (t, "select", len) != 0)
	{
	  t += len;
	  continue;
	}

      t += len;

      /* presumably in a select, so locate the terminating 'from'
       * */
      if ((from = A4GL_cv_find_token (t, "from", 1)) == NULL)
	continue;

      /* temporarily null-terminate up to the 'from', and look
       * for any comma-separated columns/expressions 
       */
      *from = '\0';
      n = 0;
      while ((p = A4GL_cv_nth_list_item (t, ++n, &len)))
	{
	  if (len > 2)
	    {
	      char c;
	      char *a = NULL;
	      char *b = NULL;
	      int i, l;
	      c = p[len];
	      p[len] = '\0';
	      /* expect more than 1 token, the last is a valid column
	       * identifier and the second last is anything except an
	       * operator (+,-,/, etc.) */
	      if ((i = A4GL_cv_num_tokens (p)) > 1)
		{
		  a = A4GL_cv_nth_token (p, i, &l);
		  if (isalnum (*a))
		    {
		      b = A4GL_cv_nth_token (p, (i - 1), &l);
		      if (isoperator (*b) || (strncasecmp (b, "as", l) == 0))
			{
			  b = NULL;
			}
		      else
			{
			  b = a;
			}
		    }
		}
	      p[len] = c;
	      if (b)
		{
		  *from = 'f';
		  A4GL_cv_replacestr (b, 0, "as ");
		  from += 3;
		  *from = '\0';
		}
	    }
	}

      /* remove the temporary null-termination */
      *from = 'f';

      t = from;
    }

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
  if ((t = strchr (args, '=')) == NULL)
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
 * Helper functions for reading SQL strings and processing them
 * as a sequence of 'tokens'. A token in this context is any of:
 * - quoted string, including the opening and closing quotes ('")
 * - integer or decimal number
 * - operator ( +, -, = , !=, >= )
 * - reserved word or function identifier
 * - any word consisting of valid column/table name characters
 * - table.column is regarded a single token
*/


/*
 * Returns pointer to the nth element (string) in a comma separated
 * list, such as 'select column/expression' lists or 'from table ...'
 * If there is no such item, return NULL
 *
 * @param  p    pointer into SQL statement string
 * @param  n    1,2,3... which item
 * @param  *len   points to an int that'll hold the string length
 */
char *
A4GL_cv_nth_list_item (char *p, int n, int *len)
{
  char *p2 = NULL;

  while (n-- > 0)
    {
      if ((p2 = A4GL_cv_find_token (p, ",", 1)) == NULL)
	{
	  p2 = A4GL_cv_lastnonblank (p);
	  p2--;
	  break;
	}
      if (n == 0)
	break;
      p = p2 + 1;
    }

  if (n == 0 && p2 >= p)
    {
      *len = p2 - p;
      return p;
    }

  *len = 0;
  return (char *) 0;
}

/*
 * Locates the next occurence of a given token string in a statement
 *
 * @param  p      pointer into SQL statement string
 * @param  str    the string to look for
 * @param  skipb  set to true to skip over text inside brackets
 */
char *
A4GL_cv_find_token (char *p, char *str, int skipb)
{
  int len = 0;
  int l = strlen (str);
  while ((p = A4GL_cv_next_token (p, &len, 0)))
    {
      if (len == l && strncasecmp (p, str, len) == 0)
	return p;
      if (skipb && *p == '(')
	{
	  p = A4GL_cv_find_closing (p);
	  if (p == NULL)
	    return p;
	  len = 1;
	}
      p += len;
    }
  return (char *) 0;
}

/*
 * Locates an opening bracket's matching (closing) bracket
 *
 * @param  p    points to opening bracket ([{
 */
char *
A4GL_cv_find_closing (char *p)
{
  int len = 0;
  char ob, cb;
  int lv;

  ob = *p++;
  switch (ob)
    {
    case '(':
      cb = ')';
      break;
    case '[':
      cb = ']';
      break;
    case '{':
      cb = '}';
      break;
    default:
      return (char *) 0;
    }

  lv = 1;
  while ((p = A4GL_cv_next_token (p, &len, 0)))
    {
      if (*p == cb)
	{
	  lv--;
	  if (lv < 1)
	    return p;
	}
      if (*p == ob)
	lv++;
      p += len;
    }

  return (char *) 0;
}


/*
 * Counts the number of tokens in a string
 *
 * @param  p     pointer into SQL statement string
 */
int
A4GL_cv_num_tokens (char *p)
{
  int n = 0;
  int len;
  while (p && (p = A4GL_cv_next_token (p, &len, 0)))
    {
      p += len;
      n++;
    }
  return n;
}

/*
 * Locates the nth token in a string
 *
 * @param  p     pointer into SQL statement string
 * @param  n     the number of the token (1,2,3,...)
 * @param  *len  pointer to location to store token length
 */
char *
A4GL_cv_nth_token (char *p, int n, int *len)
{
  while (n-- > 0)
    {
      if ((p = A4GL_cv_next_token (p, len, 0)) == NULL)
	break;
      if (n == 0)
	return p;
      p += *len;
    }
  return (char *) 0;
}

/*
 * Returns the next token string in a statement
 *
 * @param  p    pointer into SQL statement string
 * @param  *n   points to an int that'll hold the token length
 * @param  dot  treat dot (.) as a separate token
 */
char *
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
 * Returns true if token pointed to in a keyword marks
 * the start of a SQL clause
 *
 * @param  p    pointer into SQL statement string
 * @param  len  length of token string
 */
int
A4GL_cv_is_clause_word (char *p, int len)
{

  if (strncasecmp (p, "select", 6) == 0 || strncasecmp (p, "from", 4) == 0 ||
      strncasecmp (p, "where", 5) == 0 || strncasecmp (p, "having", 6) == 0 ||
      strncasecmp (p, "union", 5) == 0 || strncasecmp (p, "into", 4) == 0)
    {
      return 1;
    }
  if (strncasecmp (p, "group", 5) == 0 || strncasecmp (p, "order", 5) == 0)
    {
      if (strncasecmp (A4GL_cv_next_token (p, NULL, 0), "by", 2) == 0)
	return 1;
    }
  return 0;
}


/* ----------------------------------------------------------------
 * Functions for manipulating space-padded null terminated strings.
 * Care is taken to avoid any chance of buffer overflow. SQL strings
 * will be truncated if conversion extends beyond the available space.
*/

/*
 * Replace a string inside another string
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

/*
 * Locate first occurence of a word in a string, but ignore
 * quoted strings.  Used for finding unquoted keywords.
 *
 * @param  str    The string to be searched
 * @param  word   The word/string to locate
 * @return p      Pointer to start of word
 */
char *
A4GL_cv_unqstrstr (char *str, char *word)
{
  char *p;
  char w1;
  int quote = 0;
  int slash = 0;

  w1 = toupper (word[0]);

  for (p = str; *p > 0; p++)
    {
      if (slash)
	{
	  slash = 0;
	  continue;
	}
      if (quote == 0 && toupper (*p) == w1)
	{
	  if (strncasecmp (p, word, strlen (word)) == 0)
	    {
	      /* found it ... */
	      return p;
	    }
	  continue;
	}
      switch (*p)
	{
	case '\\':
	  slash = 1;
	  break;
	case '\"':
	case '\'':
	  if (quote == *p)
	    {
	      quote = 0;
	    }
	  else
	    {
	      if (quote == 0)
		{
		  quote = *p;
		}
	    }
	}
    }
  return ((char *) 0);
}

/*
 * Returns a pointer to the last non-blank char in a string,
 * or to the start of string if there isn't one.
 *
 * @param  str   A null terminated string
 */
char *
A4GL_cv_lastnonblank (char *str)
{
  char *p;
  int n;

  p = str;
  if ((n = strlen (str)) > 0)
    {
      p += n;
      while ((p > str) && (isspace (*p)))
	p--;
    }

  return (p);
}

/* ============================= EOF ================================ */
