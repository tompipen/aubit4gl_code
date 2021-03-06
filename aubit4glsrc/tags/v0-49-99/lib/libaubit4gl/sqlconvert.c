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
# $Id: sqlconvert.c,v 1.57 2005-05-15 09:12:47 mikeaubury Exp $
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
static char *get_dollared_sql_var(char *s) ;
static char * A4GL_cv_next_token (char *p, int *len, int dot);
static char *A4GL_space_out (char *s) ;

/*
=====================================================================
                    Variable definitions
=====================================================================
*/

/* struct to hold list of functions from conversion file(s) */
/* empty string that can be pointed to */
char empty[] = "";
char *CV_matches(char *typ,char *string,char *esc) ;

char *cvsql_names[]={
  "CVSQL_NONE",
  "CVSQL_REPLACE",
  "CVSQL_REPLACE_EXPR",
  "CVSQL_REPLACE_CMD",
  "CVSQL_REPLACE_SQLCONST",
  "CVSQL_REPLACE_SQLFUNC",
  "CVSQL_DOUBLE_TO_SINGLE",
  "CVSQL_MATCHES_TO_LIKE",
  "CVSQL_MATCHES_TO_REGEX",
  "CVSQL_MATCHES_TO_GLOB",
  "CVSQL_SUBSTRING_FUNCTION",
  "CVSQL_TABLE_ALIAS_AS",
  "CVSQL_COLUMN_ALIAS_AS",
  "CVSQL_ANSI_UPDATE",
  "CVSQL_MONEY_AS_DECIMAL",
  "CVSQL_MONEY_AS_MONEY",
  "CVSQL_SQL_CURRENT_FUNCTION",
  "CVSQL_STRIP_ORDER_BY_INTO_TEMP",
  "CVSQL_ADD_CASCADE",
  "CVSQL_OMIT_NO_LOG",
  "CVSQL_QUOTE_OWNER",
  "CVSQL_CHAR_TO_DATETIME",
  "CVSQL_CHAR_TO_INTERVAL",
  "CVSQL_NO_OWNER_QUOTE",
  "CVSQL_IGNORE_OWNER",
  "CVSQL_CONSTRAINT_NAME_BEFORE",
  "CVSQL_CONSTRAINT_NAME_AFTER",
  "CVSQL_USE_INDICATOR",
  "CVSQL_USE_DATABASE_STMT",
  "CVSQL_USE_BINDING_FOR_PUT",
  "CVSQL_IGNORE_CLOSE_ERROR",
  "CVSQL_OMIT_INDEX_CLUSTER",
  "CVSQL_OMIT_INDEX_ORDER",
  "CVSQL_ESQL_UNLOAD",
  "CVSQL_ESQL_UNLOAD_FULL_PATH",
  "CVSQL_ESQL_AFTER_INSERT",
  "CVSQL_ESQL_AFTER_UPDATE",
  "CVSQL_ESQL_AFTER_DELETE",
  "CVSQL_IGNORE_DTYPE_VARCHAR_MIN",
  "CVSQL_INTERVAL_EXTEND_FUNCTION",
  "CVSQL_DATETIME_EXTEND_FUNCTION",
  "CVSQL_NO_SERIAL_START_VALUE",
  "CVSQL_SIMPLE_GRANT_UPDATE",
  "CVSQL_SIMPLE_GRANT_SELECT",
  "CVSQL_RENAME_TABLE_AS_ALTER_TABLE",
  "CVSQL_RENAME_COLUMN_AS_ALTER_TABLE",
  "CVSQL_FAKE_IMMEDIATE",
  "CVSQL_TEMP_AS_DECLARE_GLOBAL",
  "CVSQL_TEMP_AS_TEMPORARY",
  "CVSQL_SELECT_INTO_TEMP_AS_DECLARE_GLOBAL",
  "CVSQL_SELECT_INTO_TEMP_AS_CREATE_TEMP_AS",
  "CVSQL_SWAP_SQLCA62",
  "CVSQL_NO_ORDBY_INTO_TEMP",
  "CVSQL_ADD_SESSION_TO_TEMP_TABLE",
  "CVSQL_LIMIT_LINE",
  "CVSQL_NO_DELCARE_INTO",
  "CVSQL_NO_FETCH_WITHOUT_INTO",
  "CVSQL_NO_SELECT_WITHOUT_INTO",
  "CVSQL_NO_PUT",
  "CVSQL_FULL_INSERT",
  "CVSQL_INSERT_ALIAS_VALUE",
  "CVSQL_INSERT_ALIAS_COLUMN",
  "CVSQL_OMIT_SERIAL_COL_FROM_INSERT",
  "CVSQL_OMIT_UPDATE_TABLE",
  "CVSQL_NO_INSERT_CURSOR",
  "CVSQL_EMULATE_INSERT_CURSOR",
  "CVSQL_ESQL_UNLOAD_STRING",
  "CVSQL_ESQL_UNLOAD_LIB_FALLBACK",
  "CVSQL_CLOSE_CURSOR_BEFORE_OPEN",
  
  "CVSQL_DTYPE_ALIAS"
};

struct ilist {
        int i0;
        int i1;
        int i2;
        int i3;
        int i4;
        int i5;
} ;


enum cvsql_type

{
  CVSQL_NONE,
  CVSQL_REPLACE,
  CVSQL_REPLACE_EXPR,
  CVSQL_REPLACE_CMD,
  CVSQL_REPLACE_SQLCONST,
  CVSQL_REPLACE_SQLFUNC,
  CVSQL_DOUBLE_TO_SINGLE,
  CVSQL_MATCHES_TO_LIKE,
  CVSQL_MATCHES_TO_REGEX,
  CVSQL_MATCHES_TO_GLOB,
  CVSQL_SUBSTRING_FUNCTION,
  CVSQL_TABLE_ALIAS_AS,
  CVSQL_COLUMN_ALIAS_AS,
  CVSQL_ANSI_UPDATE,
  CVSQL_MONEY_AS_DECIMAL,
  CVSQL_MONEY_AS_MONEY,
  CVSQL_SQL_CURRENT_FUNCTION,
  CVSQL_STRIP_ORDER_BY_INTO_TEMP,
  CVSQL_ADD_CASCADE,
  CVSQL_OMIT_NO_LOG,
  CVSQL_QUOTE_OWNER,
  CVSQL_CHAR_TO_DATETIME,
  CVSQL_CHAR_TO_INTERVAL,
  CVSQL_NO_OWNER_QUOTE,
  CVSQL_IGNORE_OWNER,
  CVSQL_CONSTRAINT_NAME_BEFORE,
  CVSQL_CONSTRAINT_NAME_AFTER,
  CVSQL_USE_INDICATOR,
  CVSQL_USE_DATABASE_STMT,
  CVSQL_USE_BINDING_FOR_PUT,
  CVSQL_IGNORE_CLOSE_ERROR,
  CVSQL_OMIT_INDEX_CLUSTER,
  CVSQL_OMIT_INDEX_ORDER,
  CVSQL_ESQL_UNLOAD,
  CVSQL_ESQL_UNLOAD_FULL_PATH,
  CVSQL_ESQL_AFTER_INSERT,
  CVSQL_ESQL_AFTER_UPDATE,
  CVSQL_ESQL_AFTER_DELETE,
  CVSQL_IGNORE_DTYPE_VARCHAR_MIN,
  CVSQL_INTERVAL_EXTEND_FUNCTION,
  CVSQL_DATETIME_EXTEND_FUNCTION,
  CVSQL_NO_SERIAL_START_VALUE,
  CVSQL_SIMPLE_GRANT_UPDATE,
  CVSQL_SIMPLE_GRANT_SELECT,
  CVSQL_RENAME_TABLE_AS_ALTER_TABLE,
  CVSQL_RENAME_COLUMN_AS_ALTER_TABLE,
  CVSQL_FAKE_IMMEDIATE,
  CVSQL_TEMP_AS_DECLARE_GLOBAL,
  CVSQL_TEMP_AS_TEMPORARY,
  CVSQL_SELECT_INTO_TEMP_AS_DECLARE_GLOBAL,
  CVSQL_SELECT_INTO_TEMP_AS_CREATE_TEMP_AS,
  CVSQL_SWAP_SQLCA62,
  CVSQL_NO_ORDBY_INTO_TEMP,
  CVSQL_ADD_SESSION_TO_TEMP_TABLE,
  CVSQL_LIMIT_LINE,
  CVSQL_NO_DECLARE_INTO,
  CVSQL_NO_FETCH_WITHOUT_INTO,
  CVSQL_NO_SELECT_WITHOUT_INTO,
  CVSQL_NO_PUT,
  CVSQL_FULL_INSERT,
  CVSQL_INSERT_ALIAS_VALUE,
  CVSQL_INSERT_ALIAS_COLUMN,
  CVSQL_OMIT_SERIAL_COL_FROM_INSERT,
  CVSQL_OMIT_UPDATE_TABLE,
  CVSQL_NO_INSERT_CURSOR,
  CVSQL_EMULATE_INSERT_CURSOR,
  CVSQL_ESQL_UNLOAD_STRING,
  CVSQL_ESQL_UNLOAD_LIB_FALLBACK,
  CVSQL_CLOSE_CURSOR_BEFORE_OPEN,
  CVSQL_DTYPE_ALIAS
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



struct cvsql_data *conversion_rules = 0;
int conversion_rules_cnt = 0;




/*
=====================================================================
                    Function prototypes
=====================================================================
*/

static void A4GL_cv_fnlist (char *source, char *target);
int A4GL_cv_str_to_func (char *p, int len);
int A4GL_strwscmp(char *a,char *b) ;
int A4GL_strcasestr(char *h,char *n) ;
static void A4GL_cvsql_replace_str (char *buff, char *from,char *to) ;

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

#define SQL_CONVERSION '@'
#define SQL_CONVERSION_CNT '&'

/*
=====================================================================
                    Function definitions
=====================================================================
*/
char * A4GL_convert_sql_new (char *source_dialect, char *target_dialect, char *sqlx) {
	char *sql_new;
	char *sql;
	//int a;
	sql=sqlx;
	A4GL_debug("A4GL_convert_sql_new : %s",sql);

  	if (strcmp(source_dialect,target_dialect)==0 && (!A4GL_isyes(acl_getenv("ALWAYS_CONVERT")))) {
		return sql;
  	}

  	if (A4GL_isyes(acl_getenv("NEVER_CONVERT"))) {
		return sql;
	}



	// Silently drop source dialect for now - it should be picked up from A4GL_SQLDIALECT anyway...
	//
	A4GL_debug("sql=%s\n",sql);

	sql=strdup(sqlx);

	A4GL_trim(sql);

	if (strlen(sql)) {
		sql_new=A4GLSQLCV_convert_sql(target_dialect,sql);

		if (sql_new==0) {
			A4GL_assertion(1,"Failed to convert SQL (1)");
		}

		A4GL_debug("Translates to %s",sql_new);
		sql_new=A4GLSQLCV_check_sql(sql_new);
		if (sql_new==0) {
			A4GL_assertion(1,"Failed to convert SQL (2)");
		}
	} else {
		sql_new="";
	}
	free(sql);
        //for (a=0;a<strlen(sql_new);a++) { if (sql_new[a]=='\n') sql_new[a]=' '; }
	A4GL_debug("check_sql.. %s",sql_new);
	return sql_new;
}



/*
 * Returns the next token string in a statement
 *
 * @param  p    pointer into SQL statement string
 * @param  *n   points to an int that'll hold the token length
 * @param  dot  treat dot (.) as a separate token
 */
static char * A4GL_cv_next_token (char *p, int *len, int dot)
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
  sprintf (buff, "%s_%s", source_dialect, target_dialect);
  A4GL_debug("Load convert : %s %s",source_dialect,target_dialect);


  //printf("Looking for : %s\n",buff);

  if (A4GL_has_pointer (buff, SQL_CONVERSION))
    {
      conversion_rules = A4GL_find_pointer (buff, SQL_CONVERSION);
      conversion_rules_cnt = (long)A4GL_find_pointer (buff, SQL_CONVERSION_CNT);
    }
  else
    {
      conversion_rules = 0;
      conversion_rules_cnt = 0;
      A4GL_cv_fnlist (source_dialect, target_dialect);
      A4GL_add_pointer (buff, SQL_CONVERSION, (void *)conversion_rules);
      A4GL_add_pointer (buff, SQL_CONVERSION_CNT, (void *)conversion_rules_cnt);
    }

}




static void A4GL_cv_fnlist (char *source, char *target)
{
  char buff[201];
  char buff_sm[201];
  FILE *fh;
  char *t;
  int len;


  strcpy (buff, acl_getenv ("SQLCNVPATH"));

  if (buff[0] == '\0')
    sprintf (buff, "%s/etc/convertsql", acl_getenv ("AUBITDIR"));
  len = strlen (buff);
  sprintf (buff_sm, "/%s-%s.cnv", source, target);
  strcat (buff, buff_sm);

  A4GL_debug ("loading sql conversion file %s", buff);
  if ((fh = fopen (buff, "r")) == NULL)
    {
      A4GL_debug ("failed to open file");
      return;			/* NULL */
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

      conversion_rules_cnt++;
      conversion_rules =
	realloc (conversion_rules,
		 sizeof (*conversion_rules) * conversion_rules_cnt);

      conversion_rules[conversion_rules_cnt - 1].type = A4GL_cv_str_to_func (t, len);
      conversion_rules[conversion_rules_cnt - 1].data.from = 0;
      conversion_rules[conversion_rules_cnt - 1].data.to = 0;
	if (t) {
		A4GL_debug("Loaded convertion ---> %d %s\n",conversion_rules[conversion_rules_cnt - 1].type,cvsql_names[conversion_rules[conversion_rules_cnt - 1].type]);
	}
	A4GL_trim(t);
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


	  //printf ("3. (%s)\n", t);
	  if (len > 0)
	    {
		strncpy(xx,t,255);
		xx[255]=0;
		left=&xx[0];
		right=strchr(xx,'=');


		if (right) {
			*right=0;
			right++;
			//printf("yy %s\n",right);
			while (*right=='='||*right==' '||*right=='\t') right++;
			A4GL_trim(right);
	      		conversion_rules[conversion_rules_cnt - 1].data.to = strdup(right);
			//printf("xx %s\n",right);
		} else {
	      		conversion_rules[conversion_rules_cnt - 1].data.to = 0;
		}
		A4GL_trim(left);
      		conversion_rules[conversion_rules_cnt - 1].data.from = strdup(left);
	    }
	}
    }

  fclose (fh);

  return;
}




//
// This is a workshy version of the SQL parsing stuff - 
// it will be called from the main SQL parser to do the final tidying up....
//
char *A4GLSQLCV_check_sql(char *s ) {
int b;
static char *buff=0;
char *ptr;
A4GL_assertion(s==0,"No pointer");
A4GL_debug("check sql : %s\n",s);
for (b=0;b<conversion_rules_cnt;b++) {
	if (conversion_rules[b].type==CVSQL_REPLACE_CMD) {
		if (A4GL_strwscmp(s,conversion_rules[b].data.from)==0) {
			return conversion_rules[b].data.to;
		}
	}
}

A4GL_debug("check sql 2\n");
ptr=malloc(strlen(s)*2+1000);
strcpy(ptr,s);
for (b=0;b<conversion_rules_cnt;b++) {
	if (conversion_rules[b].type==CVSQL_REPLACE) {
		if (A4GL_strcasestr(ptr,conversion_rules[b].data.from)!=0 ) {
			A4GL_cvsql_replace_str (ptr, conversion_rules[b].data.from,conversion_rules[b].data.to );
		}
	}
}
A4GL_debug("returning\n");
if (buff) free(buff);

if (A4GLSQLCV_check_requirement("LIMIT_LINE")) {
	buff=strdup(A4GL_space_out(ptr));
} else {
	buff=strdup(ptr);
}
free(ptr);
return buff;
}





char *A4GLSQLCV_insert_alias_column(char *t,char *c,char *v,int dtype) {
int b;
char s[256];
char sv[512];
sprintf(s,"%s.%s",t,c);
#ifdef MSVC
	sprintf(sv,"%s.%s.%s",t,c,v);
#else
	snprintf(sv,512,"%s.%s.%s",t,c,v);
#endif

sv[511]=0;
A4GL_debug("Alias : '%s'\n",s);

printf("Alias ? %s %s %s %x\n",t,c,v,dtype);

if (A4GLSQLCV_check_requirement("OMIT_SERIAL_COL_FROM_INSERT") && dtype==DTYPE_SERIAL) {
	return "";
}


for (b=0;b<conversion_rules_cnt;b++) {
	if (conversion_rules[b].type==CVSQL_INSERT_ALIAS_COLUMN) {
		if (A4GL_strwscmp(sv,conversion_rules[b].data.from)==0) {
			A4GL_debug("Substitute : %s\n",conversion_rules[b].data.to);
			return conversion_rules[b].data.to;
		}
	}
}


if (strchr(sv,'(')) {
	static char buff[256];
	static char *ptr=0;
	char *ptr2;
	if (ptr) free(ptr);
	ptr=strdup(sv);
	ptr2=strchr(ptr,'(');
	*ptr2=0;
	ptr2++;
	for (b=0;b<conversion_rules_cnt;b++) {
		if (conversion_rules[b].type==CVSQL_INSERT_ALIAS_COLUMN) {
			if (A4GL_strwscmp(ptr,conversion_rules[b].data.from)==0) {
				A4GL_debug("Substitute : %s\n",conversion_rules[b].data.to);
				sprintf(buff,"%s(%s",conversion_rules[b].data.to,ptr2);
				return buff;
			}
		}
	}
}


for (b=0;b<conversion_rules_cnt;b++) {
	if (conversion_rules[b].type==CVSQL_INSERT_ALIAS_COLUMN) {
		if (A4GL_strwscmp(s,conversion_rules[b].data.from)==0) {
			A4GL_debug("Substitute : %s\n",conversion_rules[b].data.to);
			return conversion_rules[b].data.to;
		}
	}
}


if (strchr(s,'(')) {
	static char buff[256];
	static char *ptr=0;
	char *ptr2;
	if (ptr) free(ptr);
	ptr=strdup(s);
	ptr2=strchr(ptr,'(');
	*ptr2=0;
	ptr2++;
	for (b=0;b<conversion_rules_cnt;b++) {
		if (conversion_rules[b].type==CVSQL_INSERT_ALIAS_COLUMN) {
			if (A4GL_strwscmp(ptr,conversion_rules[b].data.from)==0) {
				A4GL_debug("Substitute : %s\n",conversion_rules[b].data.to);
				sprintf(buff,"%s(%s",conversion_rules[b].data.to,ptr2);
				return buff;
			}
		}
	}
}


A4GL_debug("No substitute for '%s'\n",s);
return c;
}




char *A4GLSQLCV_insert_alias_value(char *t,char *c,char *v,int dtype) {
int b;
char s[256];
char sv[512];
sprintf(s,"%s.%s",t,c);
#ifdef MSVC
sprintf(sv,"%s.%s.%s",t,c,v);
#else
snprintf(sv,512,"%s.%s.%s",t,c,v);
#endif
sv[511]=0;
A4GL_debug("Alias : '%s'\n",s);

printf("Alias ? %s %s %s %x\n",t,c,v,dtype);

for (b=0;b<conversion_rules_cnt;b++) {
	if (conversion_rules[b].type==CVSQL_INSERT_ALIAS_VALUE) {
		if (A4GL_strwscmp(sv,conversion_rules[b].data.from)==0) {
			A4GL_debug("Substitute : %s\n",conversion_rules[b].data.to);
			return conversion_rules[b].data.to;
		}
	}
}


if (strchr(sv,'(')) {
	static char buff[256];
	static char *ptr=0;
	char *ptr2;
	if (ptr) free(ptr);
	ptr=strdup(sv);
	ptr2=strchr(ptr,'(');
	*ptr2=0;
	ptr2++;
	for (b=0;b<conversion_rules_cnt;b++) {
		if (conversion_rules[b].type==CVSQL_INSERT_ALIAS_VALUE) {
			if (A4GL_strwscmp(ptr,conversion_rules[b].data.from)==0) {
				A4GL_debug("Substitute : %s\n",conversion_rules[b].data.to);
				sprintf(buff,"%s(%s",conversion_rules[b].data.to,ptr2);
				return buff;
			}
		}
	}
}


for (b=0;b<conversion_rules_cnt;b++) {
	if (conversion_rules[b].type==CVSQL_INSERT_ALIAS_VALUE) {
		if (A4GL_strwscmp(s,conversion_rules[b].data.from)==0) {
			A4GL_debug("Substitute : %s\n",conversion_rules[b].data.to);
			return conversion_rules[b].data.to;
		}
	}
}


if (strchr(s,'(')) {
	static char buff[256];
	static char *ptr=0;
	char *ptr2;
	if (ptr) free(ptr);
	ptr=strdup(s);
	ptr2=strchr(ptr,'(');
	*ptr2=0;
	ptr2++;
	for (b=0;b<conversion_rules_cnt;b++) {
		if (conversion_rules[b].type==CVSQL_INSERT_ALIAS_VALUE) {
			if (A4GL_strwscmp(ptr,conversion_rules[b].data.from)==0) {
				A4GL_debug("Substitute : %s\n",conversion_rules[b].data.to);
				sprintf(buff,"%s(%s",conversion_rules[b].data.to,ptr2);
				return buff;
			}
		}
	}
}


A4GL_debug("No substitute for '%s'\n",s);
return v;
}



char *A4GLSQLCV_dtype_alias(char *s ) {
int b;
A4GL_debug("Alias : '%s'\n",s);

for (b=0;b<conversion_rules_cnt;b++) {
	if (conversion_rules[b].type==CVSQL_DTYPE_ALIAS) {
		if (A4GL_strwscmp(s,conversion_rules[b].data.from)==0) {
			A4GL_debug("Substitute : %s\n",conversion_rules[b].data.to);
			return conversion_rules[b].data.to;
		}
	}
}

if (strchr(s,'(')) {
	static char buff[256];
	char *ptr;
	char *ptr2;
	ptr=strdup(s);
	ptr2=strchr(ptr,'(');
	*ptr2=0;
	ptr2++;
	for (b=0;b<conversion_rules_cnt;b++) {
		if (conversion_rules[b].type==CVSQL_DTYPE_ALIAS) {
			if (A4GL_strwscmp(ptr,conversion_rules[b].data.from)==0) {
				A4GL_debug("Substitute : %s\n",conversion_rules[b].data.to);
				sprintf(buff,"%s(%s",conversion_rules[b].data.to,ptr2);
				return buff;
			}
		}
	}





}



A4GL_debug("No substitute for '%s'\n",s);
return s;
}




void A4GL_cvsql_replace_str (char *buff, char *from,char *to) {
int a;
static char *buff2;
int l;
int cnt=0;
int sq=0;
int dq=0;
l=strlen(buff)*2+1000;
buff2=realloc(buff2,l);
A4GL_debug("replace_str from :%s to %s",from,to);
strcpy(buff2,"");
for (a=0;a<=strlen(buff);a++) {
	int ok_to_replace; // We only want to replace whole words...
	ok_to_replace=0;

	if (a==0) {ok_to_replace=1;}
	else {
		if (!isalnum(buff[a-1])) ok_to_replace=1;
	}
	

	
	if (sq==0&&dq==0&&strncasecmp(&buff[a],from,strlen(from))==0 && ok_to_replace==1 ) {
		strcat(buff2,to);
		cnt=strlen(buff2);
		a=a+strlen(from)-1;

	} else {
		buff2[cnt++]=buff[a];
		buff2[cnt]=0;
		if (buff[a]=='\'' && dq==0) sq=1-sq;
		if (buff[a]=='"' && sq==0) dq=1-dq;
	}
}

if (cnt>=l) {
	A4GL_assertion(1,"Not allocated enough space for replace_str");
}
A4GL_debug("New string : %s\n",buff2);
strcpy(buff,buff2);

}



char *A4GLSQLCV_check_expr(char *s ) {
int b;
static char *buff=0;
buff=realloc(buff,strlen(s)*2+1000);
strcpy(buff,s);

for (b=0;b<conversion_rules_cnt;b++) {
	if (conversion_rules[b].type==CVSQL_REPLACE_EXPR) {
		if (A4GL_strcasestr(buff,conversion_rules[b].data.from)!=0) {
			char *to;
			if (conversion_rules[b].data.to[0]=='$') {
				to=get_dollared_sql_var(conversion_rules[b].data.to);
			} else {
				to=conversion_rules[b].data.to;
			}
			A4GL_cvsql_replace_str (buff, conversion_rules[b].data.from,to );
		}
	}
}

return buff;

}






char *A4GLSQLCV_generate_current(char *from,char *to) {
static char buff[256];
int hr;
if (from==0) from="YEAR";
if (to==0)   to="SECOND";

hr=A4GLSQLCV_check_requirement("SQL_CURRENT_FUNCTION");

                if (hr) {
			char *ptr;
			ptr=conversion_rules[hr-1].data.from;
                        sprintf(buff,"%s('%s','%s')",ptr,from,to);
                } else {
                        sprintf(buff,"CURRENT %s TO %s",from,to);
                }

return buff;
}




int A4GLSQLCV_check_requirement(char *s) {
int a;
int b;
if (A4GL_isyes(acl_getenv(s))) {
	return 1;
}

if (A4GL_isno(acl_getenv(s))) {
	return 0;
}


a=A4GL_cv_str_to_func (s, strlen(s));
A4GL_debug("Checking for a type %d\n",a);

if (a==0) {
	A4GL_debug("WARNING : Unknown type : %s",s);
	return 0; // I don't know what they are talking about...
}

if (conversion_rules==0) {
A4GL_debug("A4GLSQLCV_check_requirement(%s) - No rules",s);
	//printf("No rules loaded\n");
	return 0;
}

// OK - now go through and have a look....
for (b=0;b<conversion_rules_cnt;b++) {
	if (conversion_rules[b].type==a) {
		return b+1;
	}
}

A4GL_debug("A4GLSQLCV_check_requirement(%s) - no",s);
return 0;
}


char *A4GLSQLCV_check_colname(char *tabname,char *colname) {
static char buff[256];
	if (tabname) {
		sprintf(buff,"%s.%s",tabname,colname);
	} else {
		sprintf(buff,"%s",colname);
	}
	return buff;
}


char *A4GLSQLCV_matches_string(char *not, char *str,char *esc) {
static char buff[1024];


if (1&&A4GLSQLCV_check_requirement("MATCHES_TO_LIKE")) {
		if (strstr(not,"NOT")==0) {
		sprintf(buff,"LIKE %s",CV_matches("LIKE",str,esc));
		} else {
		sprintf(buff,"NOT LIKE %s",CV_matches("LIKE",str,esc));
		}

		return buff;
}

if (1&&A4GLSQLCV_check_requirement("MATCHES_TO_REGEX")) {
		if (strstr(not,"NOT")==0) {
			sprintf(buff,"~ %s",CV_matches("~",str,esc));
		} else {
			sprintf(buff,"!~ %s",CV_matches("~",str,esc));
		}
		return buff;
}
if (1&&A4GLSQLCV_check_requirement("MATCHES_TO_GLOB")) {
		sprintf(buff,"%s GLOB %s",not,CV_matches("~",str,esc));
		return buff;
}


if (strlen(esc)) {
		sprintf(buff,"%s MATCHES %s %s",not,str,esc);
} else {
		sprintf(buff,"%s MATCHES %s ",not,str);
}



return buff;
}


char *A4GLSQLCV_make_substr_s(char *colname,int n, char *l,char *r) {
static char buff[256]; 
int rule;
rule=A4GLSQLCV_check_requirement("SUBSTRING_FUNCTION");

strcpy(buff,colname);
if (!rule || n==0) {
	if (n==0) return buff; 
	if (n==1) { sprintf(buff,"%s[%s]",colname,l); return buff; }  
	if (n==2) { sprintf(buff,"%s[%s,%s]",colname,l,r); return buff; } 
} else {
	char *func;
        func=conversion_rules[rule-1].data.from;
	if (n==1) { sprintf(buff,"%s(%s,%s,1)",func,colname,l); return buff; }  
	if (n==2) { sprintf(buff,"%s(%s,%s,(%s)-(%s)+1)",func,colname,l,r,l); return buff; } 
}
A4GL_debug("Shouldn't get to here...");
return "???";
}



char *A4GLSQLCV_make_substr(char *colname,int i0,int i1,int i2) {
static char l[256]="";
static char r[256]="";
char *s;

if (i0) sprintf(l,"%d",i1);
if (i0>=2) sprintf(r,"%d",i2);
s= A4GLSQLCV_make_substr_s(colname,i0,l,r);
return s;
}



int A4GL_cv_str_to_func (char *p, int len)
{

  if (strncasecmp (p, "REPLACE", len) == 0)
    return CVSQL_REPLACE;
  if (strncasecmp (p, "REPLACE_EXPR", len) == 0)
    return CVSQL_REPLACE_EXPR;
  if (strncasecmp (p, "REPLACE_COMMAND", len) == 0)
    return CVSQL_REPLACE_CMD;
  if (strncasecmp (p, "REPLACE_SQLCONST", len) == 0)
    return CVSQL_REPLACE_SQLCONST;
  if (strncasecmp (p, "REPLACE_SQLFUNC", len) == 0)
    return CVSQL_REPLACE_SQLFUNC;
  if (strncasecmp (p, "DOUBLE_TO_SINGLE_QUOTES", len) == 0)
    return CVSQL_DOUBLE_TO_SINGLE;
  if (strncasecmp (p, "MATCHES_TO_LIKE", len) == 0)
    return CVSQL_MATCHES_TO_LIKE;
  if (strncasecmp (p, "MATCHES_TO_REGEX", len) == 0)
    return CVSQL_MATCHES_TO_REGEX;
  if (strncasecmp (p, "MATCHES_TO_GLOB", len) == 0)
    return CVSQL_MATCHES_TO_GLOB;
  if (strncasecmp (p, "SUBSTRING_FUNCTION", len) == 0)
    return CVSQL_SUBSTRING_FUNCTION;
  if (strncasecmp (p, "TABLE_ALIAS_AS", len) == 0)
    return CVSQL_TABLE_ALIAS_AS;
  if (strncasecmp (p, "COLUMN_ALIAS_AS", len) == 0)
    return CVSQL_COLUMN_ALIAS_AS;
  if (strncasecmp (p, "ANSI_UPDATE_SYNTAX", len) == 0)
    return CVSQL_ANSI_UPDATE;

  if (strncasecmp (p, "MONEY_AS_DECIMAL", len) == 0) return CVSQL_MONEY_AS_DECIMAL;
  if (strncasecmp (p, "MONEY_AS_MONEY", len) == 0) return CVSQL_MONEY_AS_MONEY;
  if (strncasecmp (p, "SQL_CURRENT_FUNCTION", len) == 0) return CVSQL_SQL_CURRENT_FUNCTION;
  if (strncasecmp (p, "STRIP_ORDER_BY_INTO_TEMP", len) == 0) return CVSQL_STRIP_ORDER_BY_INTO_TEMP;
  if (strncasecmp (p, "ADD_CASCADE", len) == 0) return CVSQL_ADD_CASCADE;
  if (strncasecmp (p, "OMIT_NO_LOG", len) == 0) return CVSQL_OMIT_NO_LOG;
  if (strncasecmp (p, "QUOTE_OWNER", len) == 0) return CVSQL_QUOTE_OWNER;
  if (strncasecmp (p, "CHAR_TO_DATETIME", len) == 0) return CVSQL_CHAR_TO_DATETIME;
  if (strncasecmp (p, "CHAR_TO_INTERVAL", len) == 0) return CVSQL_CHAR_TO_INTERVAL;
  if (strncasecmp (p, "NO_OWNER_QUOTE", len) == 0) return CVSQL_NO_OWNER_QUOTE;
  if (strncasecmp (p, "IGNORE_OWNER", len) == 0) return CVSQL_IGNORE_OWNER;
  if (strncasecmp (p, "CONSTRAINT_NAME_BEFORE", len) == 0) return CVSQL_CONSTRAINT_NAME_BEFORE;
  if (strncasecmp (p, "CONSTRAINT_NAME_AFTER", len) == 0) return CVSQL_CONSTRAINT_NAME_AFTER;
  if (strncasecmp (p, "USE_INDICATOR", len) == 0) return CVSQL_USE_INDICATOR;
  if (strncasecmp (p, "USE_DATABASE_STMT", len) == 0) return CVSQL_USE_DATABASE_STMT;
  if (strncasecmp (p, "USE_BINDING_FOR_PUT", len) == 0) return CVSQL_USE_BINDING_FOR_PUT;
  if (strncasecmp (p, "IGNORE_CLOSE_ERROR", len) == 0) return CVSQL_IGNORE_CLOSE_ERROR;
  if (strncasecmp (p, "OMIT_INDEX_CLUSTER", len) == 0) return CVSQL_OMIT_INDEX_CLUSTER;
  if (strncasecmp (p, "OMIT_INDEX_ORDER", len) == 0) return CVSQL_OMIT_INDEX_ORDER;

  if (strncasecmp (p, "ESQL_UNLOAD", len) == 0) return CVSQL_ESQL_UNLOAD;
  if (strncasecmp (p, "ESQL_UNLOAD_FULL_PATH", len) == 0) return CVSQL_ESQL_UNLOAD_FULL_PATH;
  if (strncasecmp (p, "ESQL_AFTER_INSERT", len) == 0) return CVSQL_ESQL_AFTER_INSERT;
  if (strncasecmp (p, "ESQL_AFTER_UPDATE", len) == 0) return CVSQL_ESQL_AFTER_UPDATE;
  if (strncasecmp (p, "ESQL_AFTER_DELETE", len) == 0) return CVSQL_ESQL_AFTER_DELETE;
  if (strncasecmp (p, "IGNORE_DTYPE_VARCHAR_MIN", len) == 0) return CVSQL_IGNORE_DTYPE_VARCHAR_MIN;
  if (strncasecmp (p, "INTERVAL_EXTEND_FUNCTION", len) == 0) return CVSQL_INTERVAL_EXTEND_FUNCTION;
  if (strncasecmp (p, "DATETIME_EXTEND_FUNCTION", len) == 0) return CVSQL_DATETIME_EXTEND_FUNCTION;
  if (strncasecmp (p, "IGNORE_DTYPE_VARCHAR_MIN", len) == 0) return CVSQL_IGNORE_DTYPE_VARCHAR_MIN;
  if (strncasecmp (p, "NO_SERIAL_START_VALUE", len) == 0) return CVSQL_NO_SERIAL_START_VALUE;
  if (strncasecmp (p, "SIMPLE_GRANT_UPDATE", len) == 0) return CVSQL_SIMPLE_GRANT_UPDATE;
  if (strncasecmp (p, "SIMPLE_GRANT_SELECT", len) == 0) return CVSQL_SIMPLE_GRANT_SELECT;
  if (strncasecmp (p, "RENAME_TABLE_AS_ALTER_TABLE", len) == 0) return CVSQL_RENAME_TABLE_AS_ALTER_TABLE;
  if (strncasecmp (p, "RENAME_COLUMN_AS_ALTER_TABLE", len) == 0) return CVSQL_RENAME_COLUMN_AS_ALTER_TABLE;
  if (strncasecmp (p, "FAKE_IMMEDIATE", len) == 0) return CVSQL_FAKE_IMMEDIATE;
  if (strncasecmp (p, "TEMP_AS_DECLARE_GLOBAL", len) == 0) return CVSQL_TEMP_AS_DECLARE_GLOBAL;
  if (strncasecmp (p, "TEMP_AS_TEMPORARY", len) == 0) return CVSQL_TEMP_AS_TEMPORARY;
  if (strncasecmp (p, "SELECT_INTO_TEMP_AS_DECLARE_GLOBAL", len) == 0) return CVSQL_SELECT_INTO_TEMP_AS_DECLARE_GLOBAL;
  if (strncasecmp (p, "SELECT_INTO_TEMP_AS_CREATE_TEMP_AS", len) == 0) return CVSQL_SELECT_INTO_TEMP_AS_CREATE_TEMP_AS;
  //if (strncasecmp (p, "", len) == 0) return CVSQL_;


  if (strncasecmp (p, "SWAP_SQLCA62", len) == 0) return CVSQL_SWAP_SQLCA62;
  if (strncasecmp (p, "NO_ORDBY_INTO_TEMP", len) == 0) return CVSQL_NO_ORDBY_INTO_TEMP;
  if (strncasecmp (p, "ADD_SESSION_TO_TEMP_TABLE", len) == 0) return CVSQL_ADD_SESSION_TO_TEMP_TABLE;
  if (strncasecmp (p, "LIMIT_LINE", len) == 0) return CVSQL_LIMIT_LINE;
  if (strncasecmp (p, "NO_DECLARE_INTO", len) == 0) return CVSQL_NO_DECLARE_INTO;
  if (strncasecmp (p, "NO_FETCH_WITHOUT_INTO", len) == 0) return CVSQL_NO_FETCH_WITHOUT_INTO;
  if (strncasecmp (p, "NO_SELECT_WITHOUT_INTO", len) == 0) return CVSQL_NO_SELECT_WITHOUT_INTO;
  if (strncasecmp (p, "NO_PUT", len) == 0) return CVSQL_NO_PUT;
  if (strncasecmp (p, "FULL_INSERT", len) == 0) return CVSQL_FULL_INSERT;
  if (strncasecmp (p, "INSERT_ALIAS_VALUE", len) == 0) return CVSQL_INSERT_ALIAS_VALUE;
  if (strncasecmp (p, "INSERT_ALIAS_COLUMN", len) == 0) return CVSQL_INSERT_ALIAS_COLUMN;
  if (strncasecmp (p, "OMIT_SERIAL_COL_FROM_INSERT", len) == 0) return CVSQL_OMIT_SERIAL_COL_FROM_INSERT;
  if (strncasecmp (p, "OMIT_UPDATE_TABLE", len) == 0) return CVSQL_OMIT_UPDATE_TABLE;
  if (strncasecmp (p, "NO_INSERT_CURSOR", len) == 0) return CVSQL_NO_INSERT_CURSOR;
  if (strncasecmp (p, "EMULATE_INSERT_CURSOR", len) == 0) return CVSQL_EMULATE_INSERT_CURSOR;
  if (strncasecmp (p, "ESQL_UNLOAD_STRING", len) == 0) return CVSQL_ESQL_UNLOAD_STRING;
  if (strncasecmp (p, "ESQL_UNLOAD_LIB_FALLBACK", len) == 0) return CVSQL_ESQL_UNLOAD_LIB_FALLBACK;
  if (strncasecmp (p, "DTYPE_ALIAS", len) == 0) return CVSQL_DTYPE_ALIAS;
  if (strncasecmp (p, "CLOSE_CURSOR_BEFORE_OPEN", len) == 0) return CVSQL_CLOSE_CURSOR_BEFORE_OPEN;

  A4GL_debug ("NOT IMPLEMENTED: %s", p);


printf("Unknown : %s\n",p);
  return 0;
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
#endif


char *CV_matches(char *type,char *string,char *esc) {
static char buff[1024];
int a;

	if (string[0]!='\'') {
		// Can't change a string we cant see....
		// maybe if we call a stored procedure or
		// something - but thats outside our scope ATM...
		return string;
	}

	if (type[0]=='~') {
		buff[0]='\'';
		buff[1]='^'; // Tie it to the beginning of the string
		buff[2]=0;
	} else {
		buff[0]='\'';
		buff[1]=0;
	}

	for (a=1;a<strlen(string);a++) {
		{
			char smallvar[20];
	
			if (string[a]=='?') {
				if (type[0]=='~') strcpy(smallvar,".");
				else strcpy(smallvar,"_");
				strcat(buff,smallvar);
				continue;
			}
	
			if (string[a]=='*') {
				if (type[0]=='~') strcpy(smallvar,".*");
				else strcpy(smallvar,"%");
				strcat(buff,smallvar);
				continue;
			}
	
			if (type[0]=='~'&&(string[a]=='*'||string[a]=='.')) { strcat(buff,"\\"); }
			if (type[0]!='~'&&(string[a]=='%'||string[a]=='_')) { strcat(buff,"\\"); }
	
			smallvar[0]=string[a];
			smallvar[1]=0;
			strcat(buff,smallvar);
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



int A4GL_strwscmp(char *a,char *b) {
int a_i;
int b_i;
char *o1;
char *o2;
b_i=0;
o1=strdup(a);
o2=strdup(b);
b_i=0;
for (a_i=0;a_i<strlen(a);a_i++) {
	if (a[a_i]==' '||a[a_i]=='\t') continue;
	o1[b_i++]=toupper(a[a_i]);
}
o1[b_i]=0;
b_i=0;
for (a_i=0;a_i<strlen(b);a_i++) {
	if (b[a_i]==' '||b[a_i]=='\t') continue;
	o2[b_i++]=toupper(b[a_i]);
}
o2[b_i]=0;
a_i=strcmp(o1,o2);
free(o1);
free(o2);
return a_i;
	

}


int A4GL_strcasestr(char *h,char *n) {
char *h1;
char *n1;
int r;
A4GL_push_char(h);
A4GL_upshift_stk();
h1=A4GL_char_pop();

A4GL_push_char(n);
A4GL_upshift_stk();
n1=A4GL_char_pop();
if (strstr(h1,n1)) r=1; else r=0;
free(h1);
free(n1);
return r;
}





char *A4GLSQLCV_make_ival_extend(char *ival,char *from,char *from_len,char *to,int extend) {
        static char buff[256];
	int hr;
	char *xx;
	hr= A4GLSQLCV_check_requirement("INTERVAL_EXTEND_FUNCTION");
        if (hr) {
		xx=conversion_rules[hr-1].data.from;
		if (from_len==0) {
                sprintf(buff,"%s(%s,'%s',0,'%s')",xx, ival,from,to);
		} else {
                sprintf(buff,"%s(%s,'%s',%s,'%s')",xx, ival,from,from_len,to);
		}

        } else {
        	if (from_len==0) { // The pointer not the value :-)
			if (extend) {
                		sprintf(buff,"EXTEND(%s,%s TO %s)",ival,from,to);
			} else {
                		sprintf(buff,"%s %s TO %s",ival,from,to);
			}
        	} else {
			if (extend) {
                		sprintf(buff,"EXTEND(%s,%s(%s) TO %s)",ival,from,from_len,to);
			} else {
                		sprintf(buff,"%s %s(%s) TO %s",ival,from,from_len,to);
			}
        	}
        }
        return buff;
}

char *A4GLSQLCV_make_dtime_extend(char *dval,char *from,char *to,int extend) {

        static char buff[256];
	int hr;
	char *xx;

        hr=A4GLSQLCV_check_requirement("DATETIME_EXTEND_FUNCTION");
        if (hr) {
		xx=conversion_rules[hr-1].data.from;
                sprintf(buff,"%s(%s,'%s','%s')",xx, dval,from,to);
        } else {
		if (extend) {
        	sprintf(buff,"EXTEND(%s,%s TO %s)",dval,from,to);
		} else {
        	sprintf(buff,"%s %s TO %s",dval,from,to);
		}
        }
        return buff;
}



char *A4GLSQLCV_datetime_value(char *s) {
static char buff[256];
int hr;
if (strncasecmp(s,"DATETIME(",9)==0) {
        if (s[9]!='"') {
		hr= A4GLSQLCV_check_requirement("CHAR_TO_DATETIME");
                if (hr) {
                        char *ptr;
			char *xx;
			xx=conversion_rules[hr-1].data.from;
                        ptr=strdup(&s[9]);
                        ptr[strlen(ptr)-1]=0;
                        sprintf(buff,"%s(\"%s\")",xx,ptr);
                        free(ptr);
                        return buff;
			
                }
        }

}
return s;
}

char *A4GLSQLCV_interval_value(char *s) {
static char buff[256];
int hr;
if (strncasecmp(s,"INTERVAL(",9)==0) {
        if (s[9]!='"') {
                hr=A4GLSQLCV_check_requirement("CHAR_TO_INTERVAL");
                if (hr) {
                        char *ptr;
			char *xx;
			xx=conversion_rules[hr-1].data.from;
                        ptr=strdup(&s[9]);
                        ptr[strlen(ptr)-1]=0;
                        sprintf(buff,"%s(\"%s\")",xx,ptr);
                        free(ptr);
                        return buff;
                }
        }

}
return s;
}




void A4GLSQLCV_check_fullpath(char *s)  {
char buff[512];
char buff2[512];


if (A4GLSQLCV_check_requirement("ESQL_UNLOAD_FULL_PATH")) {
	if (s[0]!='/') {
#ifdef MSVC
		_getcwd(buff,512);
#else
		getcwd(buff,512);
#endif
		strcpy(buff2,s);
		sprintf(s,"%s/%s",buff,buff2);
	}
}

}


char *A4GLSQLCV_select_into_temp(char *sel,char *lp,char *tabname)  {
char *ptr;

if (A4GLSQLCV_check_requirement("SELECT_INTO_TEMP_AS_DECLARE_GLOBAL")) {
	ptr=malloc(strlen(sel)+2000);
	A4GL_debug("Creating temp table called %s",tabname);
	if (!A4GL_has_pointer(tabname,LOG_TEMP_TABLE)) { A4GL_add_pointer(tabname,LOG_TEMP_TABLE,(void *)1); }
	sprintf(ptr,"DECLARE GLOBAL TEMPORARY TABLE SESSION.%s AS %s ON COMMIT PRESERVE ROWS WITH NORECOVERY",tabname,sel);
	return ptr;
}

if (A4GLSQLCV_check_requirement("SELECT_INTO_TEMP_AS_CREATE_TEMP_AS")) {
	ptr=malloc(strlen(sel)+2000);
	sprintf(ptr,"CREATE TEMP TABLE %s AS %s ",tabname,sel);
	return ptr;
}




ptr=malloc(strlen(sel)+2000);
sprintf(ptr,"%s %s",sel,lp);
return ptr;
return 0;
}



void A4GLSQLCV_add_temp_table(char *tabname) {
	if (!A4GL_has_pointer(tabname,LOG_TEMP_TABLE)) { A4GL_add_pointer(tabname,LOG_TEMP_TABLE,(void *)1); }
	
}

char *A4GLSQLCV_create_temp_table(char *tabname,char *elements,char *extra,char *oplog) {
char *ptr;
ptr=malloc(strlen(tabname)+strlen(elements)+strlen(extra)+strlen(oplog)+1000);

if (A4GLSQLCV_check_requirement("TEMP_AS_DECLARE_GLOBAL")) {
	A4GL_debug("Creating temp table called TABLE : %s",tabname);

	if (!A4GL_has_pointer(tabname,LOG_TEMP_TABLE)) { A4GL_add_pointer(tabname,LOG_TEMP_TABLE,(void *)1); }
	sprintf(ptr,"DECLARE GLOBAL TEMPORARY TABLE SESSION.%s ( %s ) ON COMMIT PRESERVE ROWS WITH NORECOVERY",tabname,A4GL_space_out(elements));
	return ptr;
} 

if (A4GLSQLCV_check_requirement("TEMP_AS_TEMPORARY")) {
	sprintf(ptr,"CREATE TEMPORARY TABLE %s (%s) %s %s",tabname,elements,extra,oplog);
	return ptr;
}

sprintf(ptr,"CREATE TEMP TABLE %s (%s) %s %s",tabname,elements,extra,oplog);
return ptr;
}



char *A4GLSQLCV_rencol(char *tabname,char *colname,char *ncolname) {
static char buff[256];
if (A4GLSQLCV_check_requirement("RENAME_COLUMN_AS_ALTER_TABLE")) {
	sprintf(buff,"ALTER TABLE %s RENAME COLUMN %s TO %s",tabname,colname,ncolname);
} else {
	sprintf(buff,"RENAME COLUMN %s.%s TO %s",tabname,colname,ncolname);
}
return buff;
}

char *A4GLSQLCV_rentab(char *tabname,char *ntabname) {
static char buff[256];
if (A4GLSQLCV_check_requirement("RENAME_TABLE_AS_ALTER_TABLE")) {
	sprintf(buff,"ALTER TABLE %s RENAME TO %s",tabname,ntabname);
} else {
	sprintf(buff,"RENAME TABLE %s TO %s",tabname,ntabname);
}
return buff;
}


/*
string can be USER or TODAY - return the equivilent...
*/
char *A4GLSQLCV_get_sqlconst(char *s) {
int b;
//char *c;
//static char buff[200];
for (b=0;b<conversion_rules_cnt;b++) {
	if (conversion_rules[b].type==CVSQL_REPLACE_SQLCONST) {
		if (A4GL_aubit_strcasecmp(s,conversion_rules[b].data.from)==0) {
			char *to;
			if (conversion_rules[b].data.to[0]=='$') {
				to=get_dollared_sql_var(conversion_rules[b].data.to);
			} else {
				to=conversion_rules[b].data.to;
			}

			return to;
		}
	}
}

for (b=0;b<conversion_rules_cnt;b++) {
	if (conversion_rules[b].type==CVSQL_REPLACE_EXPR) {
		if (A4GL_aubit_strcasecmp(s,conversion_rules[b].data.from)==0) {
			char *to;
			if (conversion_rules[b].data.to[0]=='$') {
				to=get_dollared_sql_var(conversion_rules[b].data.to);
			} else {
				to=conversion_rules[b].data.to;
			}
			return to;
		}
	}
}

return s;
}




char *A4GLSQLCV_sql_func(char *f,char *param) {
static char buff[256];
int b;
sprintf(buff,"%s(%s)",f,param);
for (b=0;b<conversion_rules_cnt;b++) {
	if (conversion_rules[b].type==CVSQL_REPLACE_SQLFUNC) {
		if (A4GL_aubit_strcasecmp(f,conversion_rules[b].data.from)==0) {
			//printf("Here...\n");
			sprintf(buff,conversion_rules[b].data.to,param);
			break;
		}
	}
}
return buff;
}





char *A4GLSQLCV_check_tablename(char *t) {
static char b2[200];
A4GL_debug("TABLE : %s\n",t);
if (A4GLSQLCV_check_requirement("ADD_SESSION_TO_TEMP_TABLE")) {
	if (A4GL_has_pointer(t,LOG_TEMP_TABLE)) {
		sprintf(b2,"session.%s",t);
		return b2;
	}
}
		

return t;
}

char *A4GLSQLCV_make_tablename(char *t,char *c) {
static char buff[400];
char b2[200];
int doneSession=0;
A4GL_debug("Make_tablename : %s ",t);
if (c) {
	A4GL_debug("Alias= %s",c);
}

if (A4GLSQLCV_check_requirement("ADD_SESSION_TO_TEMP_TABLE")) {
	if (A4GL_has_pointer(t,LOG_TEMP_TABLE)) {
		sprintf(b2,"session.%s",t);
		doneSession=1;
		if (c==0 || strlen(c)==0) {
			c=t;
		}
		t=b2;
	}
}



	if (c&&strlen(c) && A4GL_aubit_strcasecmp(c,t)!=0) {
                	if (A4GLSQLCV_check_requirement("TABLE_ALIAS_AS")) {
                        	sprintf(buff,"%s AS %s",t,c);
                	} else {
                        	sprintf(buff,"%s %s",t,c);
                	}
        } else {
                	sprintf(buff,"%s",t);
	}
return buff;
}

/*
char *A4GL_strcasestr(char *s,char *t) {
	char *p1;
	char *p2;
	char *a;
	int b;
	p1=strdup(s);
	p2=strdup(t);
	a4gl_upshift(p1);
	a4gl_upshift(p2);
	a=strstr(p1,p2);
	b=a-p1;
	free(p1);
	free(p2);
	return &s[b];

}
*/



static char *get_dollared_sql_var(char *s) {
static char buff[256];
char *c;
	if (A4GL_aubit_strcasecmp(s,"$TODAY")==0)                    { A4GL_push_today(); c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; } 
	if (A4GL_aubit_strcasecmp(s,"$USER")==0)                     { A4GL_push_user(); c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }

	if (A4GL_aubit_strcasecmp(s,"$CURRENT_YEAR_YEAR")==0)        { A4GL_push_current(1,1);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_YEAR_MONTH")==0)       { A4GL_push_current(1,2);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_YEAR_DAY")==0)         { A4GL_push_current(1,3);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_YEAR_HOUR")==0)        { A4GL_push_current(1,4);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_YEAR_MINUTE")==0)      { A4GL_push_current(1,5);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_YEAR_SECOND")==0)      { A4GL_push_current(1,6);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_YEAR_FRACTION1")==0)   { A4GL_push_current(1,7);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_YEAR_FRACTION2")==0)   { A4GL_push_current(1,8);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_YEAR_FRACTION3")==0)   { A4GL_push_current(1,9);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_YEAR_FRACTION4")==0)   { A4GL_push_current(1,10);  c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_YEAR_FRACTION5")==0)   { A4GL_push_current(1,10);  c=A4GL_char_pop(); sprintf(buff,"'%s0'",c); free(c); return buff; } // ,11 aint working yet..
  
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_MONTH_MONTH")==0)      { A4GL_push_current(2,2);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_MONTH_DAY")==0)        { A4GL_push_current(2,3);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_MONTH_HOUR")==0)       { A4GL_push_current(2,4);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_MONTH_MINUTE")==0)     { A4GL_push_current(2,5);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_MONTH_SECOND")==0)     { A4GL_push_current(2,6);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_MONTH_FRACTION1")==0)  { A4GL_push_current(2,7);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_MONTH_FRACTION2")==0)  { A4GL_push_current(2,8);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_MONTH_FRACTION3")==0)  { A4GL_push_current(2,9);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_MONTH_FRACTION4")==0)  { A4GL_push_current(2,10);  c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_MONTH_FRACTION5")==0)  { A4GL_push_current(2,10);  c=A4GL_char_pop(); sprintf(buff,"'%s0'",c); free(c); return buff; } // ,11 aint working yet..

	if (A4GL_aubit_strcasecmp(s,"$CURRENT_DAY_DAY")==0)          { A4GL_push_current(3,3);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_DAY_HOUR")==0)         { A4GL_push_current(3,4);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_DAY_MINUTE")==0)       { A4GL_push_current(3,5);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_DAY_SECOND")==0)       { A4GL_push_current(3,6);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_DAY_FRACTION1")==0)    { A4GL_push_current(3,7);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_DAY_FRACTION2")==0)    { A4GL_push_current(3,8);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_DAY_FRACTION3")==0)    { A4GL_push_current(3,9);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
 	if (A4GL_aubit_strcasecmp(s,"$CURRENT_DAY_FRACTION4")==0)    { A4GL_push_current(3,10);  c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
 	if (A4GL_aubit_strcasecmp(s,"$CURRENT_DAY_FRACTION5")==0)    { A4GL_push_current(3,10);  c=A4GL_char_pop(); sprintf(buff,"'%s0'",c); free(c); return buff; } // ,11 aint working yet..
 
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_HOUR_HOUR")==0)        { A4GL_push_current(4,4);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_HOUR_MINUTE")==0)      { A4GL_push_current(4,5);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_HOUR_SECOND")==0)      { A4GL_push_current(4,6);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_HOUR_FRACTION1")==0)   { A4GL_push_current(4,7);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_HOUR_FRACTION2")==0)   { A4GL_push_current(4,8);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_HOUR_FRACTION3")==0)   { A4GL_push_current(4,9);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_HOUR_FRACTION4")==0)   { A4GL_push_current(4,10);  c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_HOUR_FRACTION5")==0)   { A4GL_push_current(4,10);  c=A4GL_char_pop(); sprintf(buff,"'%s0'",c); free(c); return buff; } // ,11 aint working yet..

	if (A4GL_aubit_strcasecmp(s,"$CURRENT_MINUTE_MINUTE")==0)    { A4GL_push_current(5,5);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_MINUTE_SECOND")==0)    { A4GL_push_current(5,6);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_MINUTE_FRACTION1")==0) { A4GL_push_current(5,7);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_MINUTE_FRACTION2")==0) { A4GL_push_current(5,8);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_MINUTE_FRACTION3")==0) { A4GL_push_current(5,9);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_MINUTE_FRACTION4")==0) { A4GL_push_current(5,10);  c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_MINUTE_FRACTION5")==0) { A4GL_push_current(5,10);  c=A4GL_char_pop(); sprintf(buff,"'%s0'",c); free(c); return buff; } // ,11 aint working yet..


	if (A4GL_aubit_strcasecmp(s,"$CURRENT_SECOND_SECOND")==0)    { A4GL_push_current(6,6);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_SECOND_FRACTION1")==0) { A4GL_push_current(6,7);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_SECOND_FRACTION2")==0) { A4GL_push_current(6,8);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_SECOND_FRACTION3")==0) { A4GL_push_current(6,9);   c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_SECOND_FRACTION4")==0) { A4GL_push_current(6,10);  c=A4GL_char_pop(); sprintf(buff,"'%s'",c); free(c); return buff; }
	if (A4GL_aubit_strcasecmp(s,"$CURRENT_SECOND_FRACTION5")==0) { A4GL_push_current(6,10);  c=A4GL_char_pop(); sprintf(buff,"'%s0'",c); free(c); return buff; } // ,11 aint working yet..



	strcpy(buff,s);
	return s;
}


char *A4GL_space_out (char *s) {
static char *ptr=0;
int a;
int b=0;
int in_dbl=0;
int in_single=0;

if (ptr) free(ptr);

ptr=malloc(strlen(s)*2+1);


for (a=0;a<strlen(s);a++) {
	if (in_dbl) {
		if (s[a]=='\"') in_dbl=0;
		ptr[b++]=s[a];
		continue;
	}

	if (in_single) {
		if (s[a]=='\'') in_single=0;
		ptr[b++]=s[a];
		continue;
	}

	if (s[a]=='\'') in_single=1;
	if (s[a]=='"')  in_dbl=1;
	
	if (s[a]==',') {
			ptr[b++]='\n';
			ptr[b++]=',';
	} else {
			ptr[b++]=s[a];
	}
}


ptr[b]=0;
return ptr;
}

