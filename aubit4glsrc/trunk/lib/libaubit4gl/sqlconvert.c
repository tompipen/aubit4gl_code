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
# $Id: sqlconvert.c,v 1.1 2003-01-14 06:27:08 psterry Exp $
#
*/

/**
 * @file
 * SQL syntax conversion functions.
 *
 * The only function that should be called here is:
 *
 *     convert_sql( dbms_type, sql_statement ) 
 *
 * This will (attempt to) convert the Informix/A4GL style
 * SQL statement into a form that the DBMS can handle.
 *
 * The dbms_type codes are defined in ../../incl/a4gl_API_sql.h
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

#define isquote(x) ((x)=='\"'||(x)=='\'')
#define istabcol(x) (isalnum(x)||(x)=='.'||(x)=='_')
#define iscmpop(x) ((x)=='='||(x)=='!'||(x)=='>'||(x)=='<')

/*
=====================================================================
                    Function prototypes
=====================================================================
*/

void cvsql_double_to_single( char *sql );
void cvsql_rowid( char *sql, char *oid );
void cvsql_matches( char *sql, char *typ );
void cvsql_substring( char *sql, char *func );
void cvsql_alias_as( char *sql );

char * cv_find_token( char *p, char *str );
char * cv_next_token( char *p, int *n );
int cv_is_clause_word( char *p, int n );
void cv_replacestr( char *p, int n, char *s ) ;
void cv_inschstr( char *p, char c ) ;
void cv_delchstr( char *p, int n ) ;
char * cv_unqstrstr( char *str, char *word );

/*
=====================================================================
                    Function definitions
=====================================================================
*/

/*
 * Converts an Informix/A4GL style SQL string
 * to one acceptable to the target DBMS
 * 
 * @param  dbms   identifier for database server
 * @param  sql    SQL command string
 * @param  size   max. length of string buffer (0 = null-terminated)
*/
void
convert_sql( int dbms, char *sql )
{

debug("convert_sql: dbms=%d, sql=%s", dbms, sql);

 switch (dbms)
 { 
   case DBMS_INFORMIX:
   case DBMS_OTHER:
   	return;
   case DBMS_POSTGRESQL:
	cvsql_double_to_single( sql );
	cvsql_matches( sql, "~" );
	cvsql_substring( sql, "substr" );
	cvsql_rowid( sql, "oid" );
	//cvsql_outer_to_left( sql );
	break;
   case DBMS_ORACLE:
	cvsql_matches( sql, "like" );
	cvsql_rowid( sql, "oid" );
	//cvsql_outer_to_star( sql );
	break;
 }

 debug("  convert_sql returns %s", sql);
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
cvsql_double_to_single( char *sql )
{
  char *p;
  int quote=0;
  int slash=0;

  for (p=sql; *p > 0; p++)
  {
    if (slash) {
        slash = 0;
        continue;
    }
    switch (*p)
    {
    case '\\':
        slash = 1;
        break;
    case '\"':
        if (quote == 2) {
	    *p = '\'';
	    quote = 0;
	}
        else {
         if (quote == 0) {
	     *p = '\'';
	     quote = 2;
	 }
	}
      break;
    case '\'':
        switch(quote) {
	  case 0:
	    quote = 1;
	    break;
          case 1:
	    quote = 0;
	    break;
          case 2:
	    cv_inschstr( p, '\\' );
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
cvsql_rowid( char *sql, char *oid ) {
 char *t;
 int n;

 t=sql;
 while ( (t = cv_next_token(t, &n)) != NULL )
 {
   char *p = 0;
   if ( strncasecmp(t,"rowid",n)==0 ) {
	   p = t;
   }
   else {
     if ( strncasecmp(&t[n-6],".rowid",6)==0 ) p = &t[n-5];
   }
   if ( p > 0 ) {
       cv_replacestr( p, 5, oid);
       t += strlen("rowid") - strlen(oid);
   }
   t += n;
 }
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
cvsql_matches( char *sql, char *typ ) {
 char *t_matches;
 char *t_string;
 char *p;
 int n;

 while ( (t_matches = cv_find_token(sql,"matches") ) )
 {
   /* found 'matches', proceed only if next token is a quoted string
    */
   sql = &t_matches[7];
   if (! (t_string = cv_next_token(sql, &n)) ) break;
   sql = &t_string[n];
   if (! isquote(*t_string) ) continue;

   if ( typ[0] == '~' ) {
      /* regex: pattern must start with "^" anchor */
      cv_inschstr(t_string+1,'^');
   }
   
   /* replace "matches" with "like" or "~",
      sql has changed, so find quoted string again
   */
   cv_replacestr(t_matches,7,typ);
   sql = &t_matches[strlen(typ)];
   t_string = cv_next_token( sql, &n );
   sql = &t_string[n];

   /* convert the quoted string ... */
   for ( p=t_string+1; n > 2; p++, n-- )
   {
     if ( typ[0]=='~' ) {
        /* regex: "*" -> ".*" , "?" -> "."
	 */
        switch (*p) {
         case '*':
           cv_inschstr( p++, '.');
           break;
         case '?':
           if ( typ[0] == '~' ) { *p = '.'; }
	   else { *p = 'x'; }
	}
     }
     else {
        /* like:  "*" -> "%" , "?" -> "_",  escape existing "_","%"
	 */
        switch (*p) {
         case '%':
         case '_':
           cv_inschstr( p++, '\\');
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
 * Converts col[a,b] style column subscripts to substr(col,a,b)
 *
 * @param  sql   SQL statement string
 * @param  func  name of substring function
 */
void
cvsql_substring( char *sql, char *func ) {
 char *t, *p;
 char *t_col=0;
 char *t_left=0;
 int n;

 /* seek and convert anything like  " (table.)column [ ... ] " */
 while ( (t = cv_next_token(sql, &n) ) )
 {
   sql = &t[n];

   if ( istabcol(*t) ) {
      // we have found a possible column name, save pointer
      if (!t_left) t_col = t;
   }
   else {
     if ( *t == '[' ) {
        // we have found a left bracket, save pointer
        if (t_col && !t_left) t_left = t;
     }
   }
   if ( *t == ']' && t_col && t_left )
   {
      /* we have a closing right bracket with a previous 
       * (table.)column name and an opening left bracket
       * column [a,b] -> func (column,a,b)
       */
      *t = ')';
      /* assume [a,1] if we have [a] instead of [a,b] */
      if ( (p=index(t_left,',')) == NULL || p > t )
	      cv_replacestr( t, 0, ",1");
      *t_left = ',';
      cv_inschstr( t_col, '(');
      cv_replacestr( t_col, 0, func );
      t_col=0;
      t_left=0;
   }
 }

}

/*
 * Inserts 'as' between tables and alias names in a from clause
 *
 * @param  sql   SQL statement string
 */
void
cvsql_alias_as( char *sql ) {
 char *t;
 int n;
 int state = 0;

 /* main loop scans entire string because multiple 'from' clauses
  * are possible in 'union' selects
 */
 t=sql;
 while ( (t = cv_next_token(t,&n) ) )
 {
   /* don't start alias checking until we reach a 'from' clause */
   if ( state==0 ) {
      if (strncasecmp(t,"from",n)==0 ) state = 1;
      t += n;
      continue;
   }
   /* a comma or 'outer' means to expect a table name next */
   if (*t == ',' || strncasecmp(t,"outer",n)==0 ) {
       state = 1;
   }
   else {
     /* check for any keyword that marks the end of the from clause */
     if ( cv_is_clause_word(t,n) ) { state = 0;
     }
     else {
       /* this must be a table name, so expect an alias next */
       if (state==1) { state = 2;
       }
       else {
          /* we already had the table name, so if this word is
	   * not "as", then it must be an alias so we insert "as"
	   */
          if ( strncasecmp(t,"as",n)==0 ) {
               t = cv_next_token( (t+n), &n );
          }
	  else {
             cv_replacestr( t, 0, "as ");
	     t += 3;
          }
          state = 1;
       }
     }
   }
    t += n;
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
 * Locates the next occurence of a given token string in a statement
 *
 * @param  p    pointer into SQL statement string
 * @param  str  the string to look for
 */
char *
cv_find_token( char *p, char *str )
{
 int n = 0;
 int l = strlen(str);
 while ( (p = cv_next_token(p,&n) ) )
 {
   if ( n==l && strncasecmp(p,str,n)==0 ) return p;
   p += n;
 }
 return (char *) 0;
}

/*
 * Returns the next token string in a statement
 *
 * @param  p    pointer into SQL statement string
 * @param  *n   points to an int that'll hold the token length
 */
char *
cv_next_token( char *p, int *n )
{
 char *p2;
 int slash=0;

 // ignore whitespace
 while ( *p > 0 && isspace(*p) ) p++;

 if (*p == '\0') {
      if (n>0) *n = 0;
      return (char *) 0;
 }

 p2 = p+1;

 if ( isquote(*p) )
 {
   /* starts with a quote, look for (unescaped) closing quote */
   for (; *p2 > 0; p2++)
   {
     if (slash) { slash--; }
     else {
       if (*p2=='\\') {
          slash++;
          continue;
       }
     }
     if (*p2==*p) { p2++; break; }
   }
 }
 else {
   if ( iscmpop(*p) )
   {
     /* comp. operator sequence ( >, >=, !=, ... ) */
     while ( *p2>0 && iscmpop(*p2) ) p2++;
   }
   else {
     /* any sequence comprising table, keyword, number, etc. */ 
     if ( istabcol(*p) )
     {
       while ( *p2>0 && istabcol(*p2) ) p2++;
     }
   }
 }
 /* note, if none of the above, then we return a single char
  */
  if (n>0) *n = p2 - p;
  return p;
}

/*
 * Returns true if token pointed to in a keyword marks
 * the start of a SQL clause
 *
 * @param  p   pointer into SQL statement string
 * @param  n   length of token string
 */
int
cv_is_clause_word( char *p, int n ) {

  if ( strncasecmp(p,"select",n)==0  || strncasecmp(p,"from",n)==0 ||
       strncasecmp(p,"where",n)==0  || strncasecmp(p,"having",n)==0 ||
       strncasecmp(p,"union",n)==0  || strncasecmp(p,"into",n)==0 )
  {
       return 1;
  }
  if ( strncasecmp(p,"group",n)==0 || strncasecmp(p,"order",n)==0 )
  {
     if (strncasecmp( cv_next_token(p,NULL), "by", 2)==0) return 1;
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
cv_replacestr( char *p, int n, char *s ) {
  while ( *s > 0 )
  {
    if ( n-- > 0 ) {
        *p++ = *s++;
    }
    else {
	cv_inschstr( p++, *s++ );
    }
  }
  if ( n > 0 ) cv_delchstr( p, n );
}

/*
 * Insert one char into a string, and drop the last char.
 */
void
cv_inschstr( char *p, char c ) {
 char x;
 while ( (x=*p) > 0 ) {
   *p++ = c;
   c = x;
 }
}

/*
 * Delete chars from a string, and pad end with spaces
 */
void
cv_delchstr( char *str, int n ) {
 char *p;
  while ( n-- > 0 )
  {
    for ( p=str; *p > 0; p++ )
	if ( (*p = *(p+1)) == 0 ) *p = ' ';
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
cv_unqstrstr( char *str, char *word )
{
 char *p;
 char w1;
 int quote=0;
 int slash=0;

 w1 = toupper(word[0]);

 for (p=str; *p > 0; p++)
  {
    if (slash) {
        slash = 0;
        continue;
    }
    if ( quote == 0 && toupper(*p) == w1 ) {
        if (strncasecmp(p, word, strlen(word))==0) {
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
        if (quote == *p) {
            quote = 0;
        }
        else {
           if (quote == 0) {
               quote = *p;
           }
        }
    }
 }
 return ( (char *) 0);
}

/* ============================= EOF ================================ */

