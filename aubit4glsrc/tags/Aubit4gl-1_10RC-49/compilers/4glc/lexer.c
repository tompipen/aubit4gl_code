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
# $Id: lexer.c,v 1.135 2009-01-23 18:24:14 mikeaubury Exp $
#*/

/**
 * @file
 * Lexical analisys.
 *
 * It reads the input file (the source.4gl) and returns a token to the
 * parser.
 *
 * A token is a keyword or operator found in the midle of separators.
 * Examples of token(s) are : END, FUNCTION, define, +, > or as an
 * not reserved identifier xpto.
 *
 * Normaly is done with lex.
 * This one is implemented only in C.
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include <ctype.h>

/*prevent a4gl_4glc_int.h from including windows.h that we don't need here, that would*/
/*mess up constants defined in y.tab.h generated with new version of Bison*/
/* To Mike: please resist the urge to name constants like "CHAR" "STRING" "COMMA" etc.*/
/* please use A4GL_ namespace.*/
#define _NO_WINDOWS_H_
#include "a4gl_4glc_int.h"
#ifdef SIMPLIFIED
#include "y_tab.h"
#else
#include "y.tab.h"
#endif

#ifndef FILE_FOR_KW_H
#define FILE_FOR_KW_H "rules/generated/kw.h"
#endif
#ifndef SIMPLIFIED
#include FILE_FOR_KW_H
#else
#include "kw.h"
#endif
//#include "memfile.h"

extern int isin_formhandler;

int always_allow(int id,char *name) ;
/*
=====================================================================
					Constants definitions
=====================================================================
*/

#ifndef KWS_COMMENT
#define KWS_COMMENT COMMENT
#endif

#define stricmp 		A4GL_aubit_strcasecmp
#define TYPE_EOF  		-1
#define TYPE_USTRING  	-2	/* unterminated string */
#define TYPE_NUM 		3

/*
=====================================================================
                    Variables definitions
=====================================================================
*/


extern int sql_mode;
static int chk_word_more (FILE * f, char *buff, char *p, char *str, int t);
int idents_cnt = 0;
FILE *yyin = 0;			/* Pointer to the source file openen being parsed */
FILE *file_out=0;
int yylineno = 1;		/* Current line number */
int lastlex = -2;
int xccode = 0;
int word_cnt = 0;

char yyline[10000] = "";		/* Current line read so far, incl. CR/LF */
int yyline_len = 0;		/* Length of current line */
long yyline_fpos = 0;		/* FIle position of start of current line */
int token_read_on_line=0;
int token_read_on_col=0;


char *lastword;

#define MAX_XWORDS 1024

char xwords[MAX_XWORDS][4096];
char idents[256][256];
long fpos;

struct translate_string
{
  char *from;
  char *to;
  char *identifier;
};

//int is_builtin_func (char *s);
//char *get_namespace (char *s);
int a4gl_yylex (void *pyylval, int yystate, void *yys1, void *yys2);
//char namespace[256] = "aclfgl_";

#define NEWLIST
/* Extern reserved words table */
#ifdef NEWLIST
struct s_kw *kwords;
//extern struct s_kw *hashed_list[];
#else
#error REMOVED
#endif

extern char curr_func[];
extern char infilename[];
extern int yyin_len;
extern int in_define;
extern struct translate_string *translate_list;
extern int translate_list_cnt;
extern int chk4var;

//extern int ccnt;		/* defined in others.c */
static void turn_state_all (int kw, int v, int arr);
static int get_hash_val (char *s);
int current_yylex_state;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

char *A4GL_translate (char *s);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Read and return a new caracter from the input file.
 *
 * @param f The file pointer to the file where the parsing is made
 * @return
 */
int
mja_fgetc (FILE * f)
{
  int a=0;


  a = A4GL_memfile_getc (f);
  if (a==0x0c) a=' ';

  /* UNIX will end the line with 13(CR=\r) and 10(LF=\n); DOS will end it with only 10(LF=\n) */

  if (a == '\n')		/*ASCII 10 = LF*/
    {
      yylineno++;
      fpos = A4GL_memfile_ftell (f);
    }

/* maintain a buffer (yyline) holding current line being scanned*/
  if ((yyline_len == 0) || (yyline[yyline_len - 1] == '\n'))
    /* we're starting a new line - clear and reset*/
    {
      yyline[0] = a;
      yyline_len = 1;
      yyline_fpos = A4GL_memfile_ftell (f);
    }
  else
    /* append char to line buffer - avoid overflow by shifting left*/
    {
      if (yyline_len > 255)
	{
	  memmove (yyline, &yyline[1], --yyline_len);
	}
      yyline[yyline_len++] = a;
    }
  yyline[yyline_len] = '\0';

  return a;
}



char *A4GL_get_yyline(void) {
return yyline;
}
/**
 * @param a The Character to be ungeted
 * @param f The file pointer of file being read
 */
static void
mja_ungetc (int a, FILE * f)
{
  A4GL_memfile_ungetc (a, f);

  if (a == '\n')
    {
      yylineno--;
      fpos = A4GL_memfile_ftell (f);
    }

  /* remove from current line buffer*/
  if (yyline_len > 0)
    yyline[--yyline_len] = '\0';

}

/**
 * Checks if a string is an identifier.
 *
 * @param p The string to be checked
 * @return
 *   - 0 : Its NOT an identifier
 *   - 1 : Its an identifier
 */
static int
isident (char *p)
{
  int a;

  for (a = 0; a < strlen (p); a++)
    {
      if (isalnum (p[a]) || p[a] == '_')
	continue;
      return 0;
    }
  return 1;
}

/*
 *
 * @param a
 * @param instr
 */
static void
ccat (char *s, char a, int instr)
{
  char buff[3];
int dm;
  if (strlen (s) >= 1023)
    {
      a4gl_yyerror ("Internal error - word overflow..");
    }

  dm=0;
  if (a=='\t') dm=1;

  if (a=='\t' && A4GL_isyes(acl_getenv("DOING_CM"))) {
	dm=0;
  } 


  if (instr == 0 || (a != '\n' && a != '\r' && !dm)  )
    {
      buff[0] = a;
      buff[1] = 0;
      strcat (s, buff);
    }
  else
    {
      buff[0] = '\\';

      if (a == '\n')
	buff[1] = 'n';
      if (a == '\t')
	buff[1] = 't';
      if (a == '\r')
	buff[1] = 'r';

      buff[2] = 0;

      strcat (s, buff);

    }
}

/**
 * It check if a string represents a number.
 * 
 * @param s
 * @return
 *   - 0 : Its not a number
 *   - 1 : Its a number with just decimal part
 *   - 2 : Its a number with fractionary part
 */
static int
isnum (char *s)
{
  int a;
  int dp = 0;
  int is_e = 0;
  char orig[1024];
  //int exp_n;
  if (strcmp(s,".")==0) return 0;

  strcpy(orig,s);

  for (a = 0; a < strlen (s); a++)
    {
      if (a == 0 && (s[a] == '-' || s[a] == '+')) continue;
      if (s[a] == '.' && dp == 0)
	{
	  dp++;
	  continue;
	}
      if (s[a] >= '0' && s[a] <= '9')
	continue;


      if (a&&(s[a] == 'e' || s[a] == 'E'))

	{
	  if (s[a+1]=='+' || s[a+1]=='-') {a++;}
	  is_e++;
	  continue;
	}


      return 0;
    }

  if (is_e > 1)
    {
      return 0;
    }

  if (is_e == 1)
    {
      char buff[256];
      char *ptr;
      long n=0;
      double a_d = 0;

      strcpy (buff, s);

      ptr = strchr (buff, 'e');

      if (ptr == 0)
	ptr = strchr (buff, 'E');

      if (ptr == 0)
	{
	  a4gl_yyerror ("Internal error - couldn't locate 'e'..");
	}
      *ptr = 0;
      ptr++;

      if (ptr==0) {
		n=0;
	} else {
      sscanf (ptr, "%ld", &n);
	}

	a_d=strtod(orig,0);
	SPRINTF1 (s,"%.8lf",a_d); /* ... */
    }

  if (strchr (s, '.'))
    {
      return 2;
    }

  return 1;
}


/**
 * Continuation of the A4GL_action of read a new word from the source file
 *
 * It reads sequentialy chracters until found a separator, or if
 * reading a operator (such as +) just return it.
 *
 * @param f The file pointer to the source being parsed
 * @param t
 * @return A pointer to a static buffer that contains the token readed
 */
static char *
read_word2 (FILE * f, int *t)
{
  static char word[1024] = "";
  int escp = 0;
  int instrs = 0;
  int instrd = 0;
  int a;

  strcpy (word, "");
  *t = NAMED_GEN;

  while (1)
    {
      a = mja_fgetc (f);

      if (A4GL_memfile_feof (f))
	{	
	  *t = TYPE_EOF;
	  return word;
	}

      if (xccode == 2)
	{
	  while (1)
	    {
	      if (A4GL_memfile_feof (f))
		break;
	      if (a == '\n' || a == '\r')
		{
		  if (A4GL_aubit_strcasecmp (word, "endcode") == 0)
		    break;
		  a = mja_fgetc (f);
		  continue;
		}

	      if (a == ';')
		{
		  break;
		}
      		ccat (word, a, instrs || instrd);
	      a = mja_fgetc (f);
	    }
	  *t = CLINE;
	  return word;
	}

      if (xccode == 1)
	{
	  while (1)
	    {
	      if (A4GL_memfile_feof (f))
		break;
	      if (a == '\n' || a == '\r')
		{
		  break;
		}
	      ccat (word, a, instrs || instrd);
	      a = mja_fgetc (f);
	    }
	  *t = CLINE;
	  return word;
	}



      if (a == '#' && instrs == 0 && instrd == 0 && xccode == 0)
	{
	  if (strlen (word) > 0)
	    {
	      mja_ungetc (a, f);
	      return word;
	    }

	  while (1)
	    {
	      a = mja_fgetc (f);
	      if (A4GL_memfile_feof (f))
		break;
	      if (a == '\n' || a == '\r')
		{
		  break;
		}
	      ccat (word, a, instrs || instrd);
	    }
	  *t = KWS_COMMENT;
	  return word;

	}

#ifdef COMMENTS_ARE_NOW_REMOVED_BEFORE_LEXING
      if (a == '-' && instrs == 0 && instrd == 0 && xccode == 0)
	{
	  int z;
	  if (strlen (word) > 0)
	    {
	      mja_ungetc (a, f);
	      return word;
	    }
	  z = mja_fgetc (f);
	  mja_ungetc (z, f);
	  if (z == '-')
	    {
	      while (1)
		{
		  a = mja_fgetc (f);
		  if (A4GL_memfile_feof (f))
		    break;
		  if (a == '\n' || a == '\r')
		    break;
		  ccat (word, a, instrs || instrd);
		}
	      *t = KWS_COMMENT;
	      return word;
	    }
	}


      if (a == '!' && instrs == 0 && instrd == 0 && xccode == 0)
	{
	  char c;
	  c = mja_fgetc (f);
	  if (c == '}')
	    {
	      strcpy (word, "!}");
	      *t = KWS_COMMENT;
	      return word;
	    }
	  else
	    {
	      mja_ungetc (c, f);
	    }
	}

      if (a == '{' && instrs == 0 && instrd == 0 && xccode == 0)
	{
	  if (strlen (word) > 0)
	    {
	      mja_ungetc (a, f);
	      return word;
	    }

	  a = mja_fgetc (f);
	  if (a != '!')
	    {
	      while (1)
		{
		  a = mja_fgetc (f);
		  if (A4GL_memfile_feof (f))
		    break;
		  if (a == '}')
		    break;
		  /* ccat(word,a,instrs||instrd); */
		}
	    }
	  *t = KWS_COMMENT;
	  return word;
	}
#endif

      if ((a == '\n' || a == '\r') && escp == 0)
	{
	  if (instrs || instrd)
	    {
	      FPRINTF (stderr,"Unterminated string escp=%d?\n", escp);
	      *t = TYPE_USTRING;
	    }
	  if (strlen (word) > 0)
	    return word;
	  else {
                token_read_on_line++;
	    continue;
		}
	}


      if (instrs == 0 && instrd == 0 && (a == ' ' || a == '	'))
	{
	  if (strlen (word) > 0)
	    {
	      return word;
	    }
	  else
	    continue;
	}

      if (a=='{' && A4GL_isyes(acl_getenv("DOC4GLCOMMENTS"))) {
	int z1;
	int z2;
	static char buff[64000];
	  z1 = mja_fgetc (f);
	  if (z1!='*') {
	  	mja_ungetc (z1, f);
	  } else {
	  	z2 = mja_fgetc (f);
	  	if (z2!='*') {
	  		mja_ungetc (z2, f);
	  		mja_ungetc (z1, f);
		} else {
			int cnt=0;
			strcpy(buff,"{**");
			cnt=strlen(buff);
			while (1) {
	  			z1 = mja_fgetc (f);
				if (A4GL_memfile_feof (f)) {
			              FPRINTF (stderr,"Unterminated Doc4gl comment\n");
              				*t = TYPE_USTRING;	
					return buff;

				}
				if ( z1=='}') {
					buff[cnt++]=z1;
					buff[cnt]=0;
					*t = KW_DOC4GLCOMMENT;
					break;
				} else {
					buff[cnt++]=z1;
				}
			}
		}
		return buff;
	  }

	
		
      }

      if (ispunct (a) && a != '.' && a != '_' && instrs == 0 && instrd == 0)
	{
		//char *ptr;
	  	if ((a=='+' || a=='-') && strlen(word)>=2 && toupper(word[strlen(word)-1])=='E') {
		char *ptr;
		ptr=acl_strdup(word);
		ptr[strlen(ptr)-1]=0;
		if (isnum(ptr))  {
				free(ptr);
      				ccat (word, a, instrs || instrd);
				continue;

		} else {
		}
		free(ptr);
	} else {

	  if (strlen (word) > 0)
	    {
	      mja_ungetc (a, f);
	      return word;
	    }
	}
	}

      if (instrs == 0 && instrd == 0 && (ispunct (a)) && a != '"' && a != '\''
	  && a != '_')
	{
	  if (strlen (word) > 0)
	    {
	      if (isnum (word) && a == '.');
	      else
		{
		  mja_ungetc (a, f);
		  return word;
		}
	    }
	  else
	    {
	      ccat (word, a, instrs || instrd);
	      return word;
	    }
	}

      if (a == '\\' && !escp)
	{
	  ccat (word, a, instrs || instrd);
	  if (escp == 0)
	    {
	      escp = 1;
	      continue;
	    }
	  else
	    {
	      escp = 0;
	    }
	}

      if (a == '"' && !escp && instrs == 0)
	{
	  if (instrd == 1)
	    {
	      int x;
	      x = mja_fgetc (f);
	      mja_ungetc (x, f);

	      if (x != '"')
		{
		  ccat (word, '"', instrs || instrd);
		  *t = CHAR_VALUE;
		  return word;
		}
	      else
		{
		  x = mja_fgetc (f);
		  ccat (word, '\\', instrs || instrd);
		  ccat (word, '"', instrs || instrd);
		  continue;
		}
	    }
	  ccat (word, '"', instrs || instrd);
	  instrd = 1;
	  continue;
	}

      /*
         if (a == '\"' && instrs == 1)
         {
         ccat (word, '\\', instrs || instrd);
         ccat (word, '\"', instrs || instrd);
         continue;
         }
       */


      if (a == '\'' && !escp && instrd == 0)
	{
	  if (instrs == 1)
	    {
		if (sql_mode) {
	      		ccat (word, '\'', instrs || instrd);
		} else {
	      		ccat (word, '"', instrs || instrd);
		}
	      *t = CHAR_VALUE;
	      return word;
	    }
		if (sql_mode) {
	      		ccat (word, '\'', instrs || instrd);
		 } else {
	  ccat (word, '"', instrs || instrd);
		}
	  instrs = 1;
	  continue;
	}


      if (a == '"' && !escp && instrs == 1)
	{
	  ccat (word, '\\', instrs || instrd);
	}

      ccat (word, a, instrs || instrd);
      escp = 0;

    }				/* while loop ends here*/

}

/**
 * Read a new word from the source file.
 *
 * @param f The file pointer of the source being readed
 * @param t
 * @return A pointer to a static buffer that contains the token readed
 */
static char *
read_word (FILE * f, int *t)
{
  char *ptr;
  char *s2;

 token_read_on_line=yylineno;
  ptr = read_word2 (f, t);
  if (*t == CHAR_VALUE)
    {
      char *s;
      s = acl_strdup (ptr + 1);
      s[strlen (s) - 1] = 0;
      A4GL_dumpstring (s, yylineno, infilename);
      s2 = A4GL_translate (s);
      if (s2) {
	ptr = s2;
		*t=CHAR_VALUE_TRANSLATED;
	}
    }

  /* if (s) ptr=s; */
  if (word_cnt >= MAX_XWORDS)
    {
      a4gl_yyerror ("Internal error - xwords overflow..");
    }
  strcpy (xwords[word_cnt], ptr);
  word_cnt++;

  return ptr;
}


int always_allow(int id,char *name) {
switch (id)  {
case WHENEVER_ANY_ERROR_CALL:
case WHENEVER_ANY_ERROR_CONTINUE:
case WHENEVER_ANY_ERROR_GOTO:
case WHENEVER_ANY_ERROR_STOP:
case WHENEVER_ERROR_CALL:
case WHENEVER_ERROR_CONTINUE:
case WHENEVER_ERROR_GOTO:
case WHENEVER_ERROR_STOP:
case WHENEVER_NOT_FOUND_CALL:
case WHENEVER_NOT_FOUND_CONTINUE:
case WHENEVER_NOT_FOUND_GOTO:
case WHENEVER_NOT_FOUND_STOP:
case WHENEVER_SQLERROR_CALL:
case WHENEVER_SQLERROR_CONTINUE:
case WHENEVER_SQLERROR_GOTO:
case WHENEVER_SQLERROR_STOP:
case WHENEVER_SQLSUCCESS_CALL:
case WHENEVER_SQLSUCCESS_CONTINUE:
case WHENEVER_SQLSUCCESS_GOTO:
case WHENEVER_SQLSUCCESS_STOP:
case WHENEVER_SQLWARNING_CALL:
case WHENEVER_SQLWARNING_CONTINUE:
case WHENEVER_SQLWARNING_GOTO:
case WHENEVER_SQLWARNING_STOP:
case WHENEVER_SUCCESS_CALL:
case WHENEVER_SUCCESS_CONTINUE:
case WHENEVER_SUCCESS_GOTO:
case WHENEVER_SUCCESS_STOP:
case WHENEVER_WARNING_CALL:
case WHENEVER_WARNING_CONTINUE:
case WHENEVER_WARNING_GOTO:
case WHENEVER_WARNING_STOP: return 1;
}

return 0;
}

/**
 *
 * @param cnt
 * @param pos
 * @param f The file pointer to the file being parsed
 * @param p
 * @return
 */
static int
words (int cnt, int pos, FILE * f, char *p, int t_last)
{
  int z;
  int t;
  char buff[132];
  int states = -1;
  int proc = 0;

  //A4GL_debug("In words...");

  if (cnt > 10000 || cnt < 0)
    {
      char *ptr = 0;
      *ptr = 0;
    }				/* Sanity check */

  if (!always_allow (kwords[cnt].id, kwords[cnt].name))
    {
      if (isin_formhandler)
	{
	  int ok = 0;
	  if (kwords[cnt].id == KW_INPUT)
	    {
	      if (allow_token_state (current_yylex_state, kwords[cnt].id))
		ok = 1;
	      else
		{
		  if (allow_token_state (current_yylex_state, FINPUT))
		    ok = 1;
		}
	      if (!ok) {
      		//A4GL_debug ("Not allowing %d : %d %s '%s'\n",pos, kwords[cnt].id, kwords[cnt].name,p);
		return 0;
	      }
	    }
	}
      else
	{
	  if (!allow_token_state (current_yylex_state, kwords[cnt].id))
	    {
      		//A4GL_debug ("Not allowing %d : %d %s '%s'\n",pos, kwords[cnt].id, kwords[cnt].name,p);
	      return 0;
	    }
	}
      //A4GL_debug ("Allowing %d : %d %s '%s'\n", pos, kwords[cnt].id, kwords[cnt].name,p);
    }


  strcpy (buff, kwords[cnt].vals[pos]);


  if (buff[0] == '*' && strlen (buff) > 1)
    {
      strcpy (buff, &kwords[cnt].vals[pos][1]);
      states = 1;
    }

  if (proc == 0 && stricmp (buff, "<ident>") == 0)
    {

      if (isident (p) == 0)
	return 0;
      strcpy (idents[idents_cnt++], p);
      proc = 1;

    }


  if (proc == 0 && stricmp (buff, "<num>") == 0)
    {
      int a;
      a = isnum (p);
      if (a == 0)
	return 0;
      strcpy (idents[idents_cnt++], p);
      proc = 1;
    }

  if (proc == 0 && stricmp (buff, "<int_num>") == 0)
    {
      int a;
      a = isnum (p);
      if (a != 1)
	return 0;
      strcpy (idents[idents_cnt++], p);
      proc = 1;
    }


  if (proc == 0 && stricmp (buff, "<char_value>") == 0)
    {
      //int a;
      if (t_last == CHAR_VALUE)
	{
	  strcpy (idents[idents_cnt++], p);
	  proc = 1;
	}
      else
	{
	  return 0;
	}
    }



  if (proc == 0)
    {
      if (stricmp (p, buff) != 0)
	{
	  return 0;
	}
    }

  /* if (states != -1) start_state (buff, states); */


  if (cnt > 10000 || cnt < 0)
    {
      char *ptr = 0;
      *ptr = 0;
    }				/* Sanity check */
  if (kwords[cnt].vals[pos + 1] == 0)
    {
      //int a;
      if (cnt > 10000 || cnt < 0)
	{
	  char *ptr = 0;
	  *ptr = 0;
	}			/* Sanity check */
      A4GL_debug ("token = %d %s \n", kwords[cnt].id, kwords[cnt].name);
      return 1;
    }

  p = read_word (f, &t);

  z = words (cnt, pos + 1, f, p, t);

  if (z == 0)
    {
      return 0;
    }
  A4GL_debug("Accepted");
  return 1;
}

/**
 *
 * @param c
 * @return
 */
static char *
mk_word (int c)
{
  static char buff[256];
  int a;
  int icnt = 0;
  int proc=0;
  strcpy (buff, "");

  for (a = 0; kwords[c].vals[a]; a++)
    {
      if (a > 0)  {

		if ((kwords[c].id==DATETIME_VALUE || kwords[c].id==INTERVAL_VALUE))  {
			if (strlen(buff)!=0) {
				char *nstr;
				nstr=kwords[c].vals[a];
				if (stricmp(nstr, "<ident>") == 0) nstr=idents[icnt];
				if (stricmp(nstr, "<char_value>") == 0) nstr=idents[icnt];
				if (stricmp(nstr, "<int_num>") == 0) nstr=idents[icnt];
				if (stricmp(nstr, "<num>") == 0)     nstr=idents[icnt];
			
				if (!ispunct(buff[strlen(buff)-1]) && !isspace(buff[strlen(buff)-1])) {
					if (!ispunct(nstr[0]) && !isspace(nstr[0])) {
						strcat (buff, " ");
					} 
				} 
			}
		} else {
			strcat (buff, " ");
		}
	}
      proc=0;
      if (stricmp (kwords[c].vals[a], "<ident>") == 0) { strcat (buff, idents[icnt++]); proc=1; }
      if (stricmp (kwords[c].vals[a], "<num>") == 0) { strcat (buff, idents[icnt++]); proc=1; }
      if (stricmp (kwords[c].vals[a], "<int_num>") == 0) { strcat (buff, idents[icnt++]); proc=1; }
      if (stricmp (kwords[c].vals[a], "<char_value>") == 0) { strcat (buff, idents[icnt++]); proc=1; }
      if (proc==0) {
	  strcat (buff, kwords[c].vals[a]);
	}
    }
  return buff;
}

/**
 * Check if a token is a reserved word.
 *
 * If so it returns an integer (wich is defined with #define generated by
 * yacc/bison) that easily identifies the reserved word.
 *
 * If its not a reserved word could be a NUMBER, IDENTIFIER, ???
 *
 * @param f The file pointer that identifies the opened file source
 * @param str
 * @return The keyword integer identifier (please use the defines)
 */
static int
chk_word (FILE * f, char *str)
{
  char *p;
  int t;
  char buff[1024];
  char trimmed[1024];

  /* read the next word from the 4GL source file */
  p = read_word (f, &t);
  set_yytext(p);

  strcpy(trimmed,p);
  A4GL_trim(trimmed);

  A4GL_debug ("chk_word: read_word returns %s\n", p);

  /* C/SQL code can be embedded in 4GL inside code/endcode blocks.
   * These are handled entirely by the lexer, so we test for this
   * here. While we are in such blocks, the compiler will copy the
   * source verbatim without any alterations or error checking.
   * A code block starts with the word 'code' by itself on a line,
   * and ends with the word 'endcode'.
   */

  if ((A4GL_aubit_strcasecmp (trimmed, "--!code") == 0
       || A4GL_aubit_strcasecmp (trimmed, "code") == 0)
      && (xccode == 0) && (A4GL_mja_strncmp (yyline, p, strlen (p)) == 0))
    {
      xccode = 1;
      return KW_CSTART;
    }

  if (strcmp (p, "a4gl_start_sql_code") == 0 && xccode == 0)
    {
      xccode = 2;
      return KW_CSTART;
    }

  if (t == TYPE_EOF && xccode)
    {
      FPRINTF (stderr, "Unexpected end of file - no endcode (xccode=%d)\n",xccode);
      exit (1);
    }

  if (xccode && (A4GL_aubit_strcasecmp (trimmed, "endcode") == 0
		 || A4GL_aubit_strcasecmp (trimmed, "--!endcode") == 0
		 || A4GL_aubit_strcasecmp (trimmed, "--!end code") == 0
		 || A4GL_aubit_strcasecmp (trimmed, "end code") == 0))
    {
      xccode = 0;
      return KW_CEND;
    }

  if (xccode == 1)
    {
      strcpy (str, p);
      return CLINE;
    }

  if (xccode == 2)
    {
      strcpy (str, p);
      strcat (str, "*");
      return SQLLINE;
    }
  /* end of code/endcode block handling */


  /* skip comments, do not return these to parser */
  if (t == KWS_COMMENT)
    {
      strcpy (str, p);
      return chk_word (f, str);
    }

  /* the special end of file token indicates we have reached the end */
  if (t == TYPE_EOF)
    {
      strcpy (str, "");
      return -1;
    }
  

  /* save the current input file location, as we have to do some
   * reading ahead when checking for multi-word keywords
   */
  strcpy (buff, p);

  t=chk_word_more (f, buff, p, str, t);

  switch(t) {
	case WHENEVER_ERROR_CONTINUE:  		set_whento_store(""); 		set_whenever_store(WHEN_ERROR+WHEN_CONTINUE,0);		t=KW_WHENEVER_SET;break;
	case WHENEVER_ERROR_STOP:  		set_whento_store(""); 		set_whenever_store(WHEN_ERROR+WHEN_STOP,0);		t=KW_WHENEVER_SET;break;
	case WHENEVER_ERROR_GOTO:  		set_whento_store(idents[0]); 	set_whenever_store(WHEN_ERROR+WHEN_GOTO,0);		t=KW_WHENEVER_SET;break;
	case WHENEVER_ERROR_CALL:  		set_whento_store(idents[0]); 	set_whenever_store(WHEN_ERROR+WHEN_CALL,0);		t=KW_WHENEVER_SET;break;

	case WHENEVER_ANY_ERROR_CONTINUE:  	set_whento_store(""); 		set_whenever_store(WHEN_ANYERROR+WHEN_CONTINUE,0);	t=KW_WHENEVER_SET;break;
	case WHENEVER_ANY_ERROR_STOP:  		set_whento_store(""); 		set_whenever_store(WHEN_ANYERROR+WHEN_STOP,0);		t=KW_WHENEVER_SET;break;
	case WHENEVER_ANY_ERROR_GOTO:  		set_whento_store(idents[0]); 	set_whenever_store(WHEN_ANYERROR+WHEN_GOTO,0);		t=KW_WHENEVER_SET;break;
	case WHENEVER_ANY_ERROR_CALL:  		set_whento_store(idents[0]); 	set_whenever_store(WHEN_ANYERROR+WHEN_CALL,0);		t=KW_WHENEVER_SET;break;

	case WHENEVER_NOT_FOUND_CONTINUE:  	set_whento_store(""); 		set_whenever_store(WHEN_NOTFOUND+WHEN_CONTINUE,0);	t=KW_WHENEVER_SET;break;
	case WHENEVER_NOT_FOUND_STOP:  		set_whento_store(""); 		set_whenever_store(WHEN_NOTFOUND+WHEN_STOP,0);		t=KW_WHENEVER_SET;break;
	case WHENEVER_NOT_FOUND_GOTO:  		set_whento_store(idents[0]); 	set_whenever_store(WHEN_NOTFOUND+WHEN_GOTO,0);		t=KW_WHENEVER_SET;break;
	case WHENEVER_NOT_FOUND_CALL:  		set_whento_store(idents[0]); 	set_whenever_store(WHEN_NOTFOUND+WHEN_CALL,0);		t=KW_WHENEVER_SET;break;

	case WHENEVER_SQLSUCCESS_CONTINUE:  	set_whento_store(""); 		set_whenever_store(WHEN_SQLSUCCESS+WHEN_CONTINUE,0);	t=KW_WHENEVER_SET;break;
	case WHENEVER_SQLSUCCESS_STOP:  	set_whento_store(""); 		set_whenever_store(WHEN_SQLSUCCESS+WHEN_STOP,0);	t=KW_WHENEVER_SET;break;
	case WHENEVER_SQLSUCCESS_GOTO:  	set_whento_store(idents[0]); 	set_whenever_store(WHEN_SQLSUCCESS+WHEN_GOTO,0);	t=KW_WHENEVER_SET;break;
	case WHENEVER_SQLSUCCESS_CALL:  	set_whento_store(idents[0]); 	set_whenever_store(WHEN_SQLSUCCESS+WHEN_CALL,0);	t=KW_WHENEVER_SET;break;

	case WHENEVER_SUCCESS_CONTINUE:  	set_whento_store(""); 		set_whenever_store(WHEN_SUCCESS+WHEN_CONTINUE,0);	t=KW_WHENEVER_SET;break;
	case WHENEVER_SUCCESS_STOP:  		set_whento_store(""); 		set_whenever_store(WHEN_SUCCESS+WHEN_STOP,0);		t=KW_WHENEVER_SET;break;
	case WHENEVER_SUCCESS_GOTO:  		set_whento_store(idents[0]); 	set_whenever_store(WHEN_SUCCESS+WHEN_GOTO,0);		t=KW_WHENEVER_SET;break;
	case WHENEVER_SUCCESS_CALL:  		set_whento_store(idents[0]); 	set_whenever_store(WHEN_SUCCESS+WHEN_CALL,0);		t=KW_WHENEVER_SET;break;

	case WHENEVER_SQLERROR_CONTINUE:  	set_whento_store(""); 		set_whenever_store(WHEN_SQLERROR+WHEN_CONTINUE,0);	t=KW_WHENEVER_SET;break;
	case WHENEVER_SQLERROR_STOP:  		set_whento_store(""); 		set_whenever_store(WHEN_SQLERROR+WHEN_STOP,0);		t=KW_WHENEVER_SET;break;
	case WHENEVER_SQLERROR_GOTO:  		set_whento_store(idents[0]); 	set_whenever_store(WHEN_SQLERROR+WHEN_GOTO,0);		t=KW_WHENEVER_SET;break;
	case WHENEVER_SQLERROR_CALL:  		set_whento_store(idents[0]); 	set_whenever_store(WHEN_SQLERROR+WHEN_CALL,0);		t=KW_WHENEVER_SET;break;

	case WHENEVER_SQLWARNING_CONTINUE:  	set_whento_store(""); 		set_whenever_store(WHEN_SQLWARNING+WHEN_CONTINUE,0);	t=KW_WHENEVER_SET;break;
	case WHENEVER_SQLWARNING_STOP:  	set_whento_store(""); 		set_whenever_store(WHEN_SQLWARNING+WHEN_STOP,0);	t=KW_WHENEVER_SET;break;
	case WHENEVER_SQLWARNING_GOTO:  	set_whento_store(idents[0]); 	set_whenever_store(WHEN_SQLWARNING+WHEN_GOTO,0);	t=KW_WHENEVER_SET;break;
	case WHENEVER_SQLWARNING_CALL:  	set_whento_store(idents[0]); 	set_whenever_store(WHEN_SQLWARNING+WHEN_CALL,0);	t=KW_WHENEVER_SET;break;

	case WHENEVER_WARNING_CONTINUE:  	set_whento_store(""); 		set_whenever_store(WHEN_WARNING+WHEN_CONTINUE,0);	t=KW_WHENEVER_SET;break;
	case WHENEVER_WARNING_STOP:  		set_whento_store(""); 		set_whenever_store(WHEN_WARNING+WHEN_STOP,0);		t=KW_WHENEVER_SET;break;
	case WHENEVER_WARNING_GOTO:  		set_whento_store(idents[0]); 	set_whenever_store(WHEN_WARNING+WHEN_GOTO,0);		t=KW_WHENEVER_SET;break;
	case WHENEVER_WARNING_CALL:  		set_whento_store(idents[0]); 	set_whenever_store(WHEN_WARNING+WHEN_CALL,0);		t=KW_WHENEVER_SET;break;
   }

A4GL_debug("t=%d\n",t);
  if (t == KWS_COMMENT)
    {
      strcpy (str, p);
      return chk_word (f, str);
    }
A4GL_debug("returning t=%d\n",t);

  return t;
}



static int
get_hash_val (char *s)
{
  int c;
  c = toupper (s[0]);
  if (c >= 'A' && c <= 'Z')
    {

      c = c - 'A' + 1;
    }
  else
    {
      c = 0;
    }

  return c;
}


static int
chk_word_more (FILE * f, char *buff, char *p, char *str, int t)
{
  int cnt = 0;
  int oline;
  int a;
  cnt = 0;
  oline = yylineno;


  a = A4GL_memfile_ftell (f);
  /* check if the current word is a known reserved/key word */

#ifdef NEWLIST
  kwords = A4GL_lexer_get_hashed_list(get_hash_val (p));
#endif
 
  while (kwords[cnt].id > 0)
    {
      strcpy (p, buff);
      if (kwords[cnt].mode >= 1)
	{
	  idents_cnt = 0;
	  if (words (cnt, 0, f, p,t))
	    {
	      strcpy (str, mk_word (cnt));
	      return kwords[cnt].id;
	    }
	}

      /* restore current input file position, in case of read-ahead */
      /* also, restore current line buffer */
      yylineno = oline;
      cnt++;
      yyline[0] = '\0';
      yyline_len = 0;
      if (yyline_fpos < a)
	{

#ifndef OLDWAY
	  int tl;
	  static char tmpbuff[20000];
	  A4GL_memfile_fseek (f, yyline_fpos, SEEK_SET);
	  tl = A4GL_memfile_ftell (f);
	  A4GL_memfile_fread (tmpbuff, a - tl, 1, f);
	  tmpbuff[a - tl] = 0;
	  strcpy (&yyline[yyline_len], tmpbuff);
	  yyline_len += a - tl;

#else
	  A4GL_memfile_fseek (f, yyline_fpos, SEEK_SET);
	  while (A4GL_memfile_ftell (f) < a)
	    {
	      yyline[yyline_len++] = A4GL_memfile_getc (f);
	      yyline[yyline_len] = '\0';
	    }
#endif




	}
      else
	{
	  A4GL_memfile_fseek (f, a, SEEK_SET);
	}

    }

A4GL_debug("p=%s buff=%s",p,buff);
  /* check for literal numbers - these cannot be key words or identifiers */
  strcpy (str, p);

  a = isnum (p);
  if (a == 1)
    {
      strcpy (str, p);
      return INT_VALUE;
    }

  if (a == 2 && strcmp(p,".")!=0) // Just a dot...
    {
      strcpy (str, p);
      return NUMBER_VALUE;
    }

  return t;
}

/**
 * It converts the case (if needed) to lower case
 *
 * @param c The string to be lowered
 */
static void
to_lower_str (char *s)
{
  int a;
  for (a = 0; a < strlen (s); a++)
    {
      s[a] = tolower (s[a]);
    }
}

/**
 * Fixes up back-slash quoting in source code strings.
 *
 * @param s The string to be fixed
 */
 static void
fix_bad_strings (char *s)
{
  char buff[10000];
  int c;
  int a;
  char *allowed_escape="nrtfbae0xc\\\""; // We can have \n\r\t etc
  if (s[0] != '"')
    return;

  buff[0] = s[0];
  c = 1;

  for (a = 1; a < strlen (s); a++)
    {
      if (s[a] != '\\')
	{
	  buff[c++] = s[a];
	  continue;
	}

/* We have one '\'*/

      if(!strchr(allowed_escape,s[a+1])) {  /* Fix \something where something isnt valid..*/
	  buff[c++] = s[a + 1];
	  a++;
	  continue;
      }

      buff[c++] = '\\';
      buff[c++] = s[a+1];
	a++;
    }

  buff[c] = 0;
  A4GL_debug ("Fixstring changed %s to %s", s, buff);
  strcpy (s, buff);
  return;
}

/*static int sql_kword(int a) {*/
/*switch (a) {*/
	/*case WHERE:*/
	/*case FROM:*/
	/*case SELECT:*/
		/*return 1;*/
/*}*/
/*return 0;*/
/*}*/


/**
 *  Lexical analysis entry point.
 *
 *  Called by yyparse() from yacc when the parser wants to be feeded with
 *  more tokens.
 *
 *  The purpose is give tokens to the syntatic parser (made in yacc/bison).
 * @todo - convert identifier to USER_DTYPE if required....
 */
int
/*yylex (void)*/
a4gl_yylex (void *pyylval, int yystate, void *yys1, void *yys2)
{
  int a;
  char buff[10240];
  char buffval[20480];
  int allow;
  static int last_pc = 0;
/*int r;*/
/*short *stack_cnt;*/
  strcpy(buff,"");


  current_yylex_state = yystate;

  if (yyin == 0)
    {
      FPRINTF (stderr, "No input...\n");
      exit (0);
    }

  a = A4GL_memfile_ftell (yyin);

  if (A4GL_isyes(acl_getenv("DUMP4GL"))) {
		if (file_out==0) {
			file_out=fopen("/tmp/file.out","w");
		}
  }
  if (yyin_len)
    {
      a = a * 100 / yyin_len;
      if (a > last_pc)
	{
	  last_pc = a;
	  if (strcmp (acl_getenv ("PRINTPROGRESS"), "Y") == 0)
	    PRINTF ("%d %% complete\r", last_pc);fflush(stdout);
	
	}
    }

  a = chk_word (yyin, buff);













  A4GL_debug ("chk_word returns token=%d, buff=%s state=%d sql_mode=%d\n", a, buff, yystate,sql_mode);

  /*if (chk4var)*/
  /*a = NAMED_GEN;*/

  if (isin_formhandler) { if (a==KW_INPUT) {a=FINPUT;} }
  allow = allow_token_state (yystate, a);
  A4GL_debug ("Allow_token_State = %d state=%d\n", allow, yystate);


  if (sql_mode == 0)
    {
      if (allow == 0) {
		int t;
		t=isnum(buff);
		if (t==1) a=INT_VALUE;
		if (t==2) {
				a=NUMBER_VALUE;
				//printf("SETTING TO NUMBER VALUE 2 : %s\n",buff);
			}
		if (t!=1&&t!=2) {
		 	if (isident (buff)) {
				a = NAMED_GEN;
			}
		}
	}



      if (allow_token_state (yystate, USER_DTYPE_NEW) && a == NAMED_GEN)
	{

	  if (find_dim (downshift (buff))) {
	      a = USER_DTYPE_ORIG;
	    }
	}


      if (allow_token_state (yystate, USER_DTYPE_ORIG) && a == NAMED_GEN) {
	  if (A4GL_find_datatype(upshift(buff))!=-1) {

	      a = USER_DTYPE_ORIG;
	  }
	}






    }
  else
    {
	if (!is_sql_kw(a)) {
		a = SQL_TEXT;
	}
    }


  A4GL_debug ("-> %d (NAMED_GEN=%d)\n", a, NAMED_GEN);

  if (a == 2 || a == NAMED_GEN)
    {
      A4GL_debug ("  Constant check returns %d", check_for_constant (buff, buffval));

      switch (check_for_constant (buff, buffval))
	{
	case 0:
	  break;

	case 1:
	  A4GL_debug (" Constant switch %s Char", buffval);
	  strcpy (buff, buffval);
	  a = CHAR_VALUE;
	  break;		/* 'c' */

	case 2:
	  A4GL_debug (" Constant switch %s Float", buffval);
	  strcpy (buff, buffval);
				//printf("SETTING TO NUMBER VALUE 3\n");
	  a = NUMBER_VALUE;
	  break;		/* 'f' */
	case 3:
	  A4GL_debug (" Constant switch %s Integer", buffval);
	  strcpy (buff, buffval);
	  a = INT_VALUE;
	  break;		/* 'i' */
	case 4:
	  A4GL_debug (" Constant switch %s ident", buffval);
	  strcpy (buff, buffval);
	  a = NAMED_GEN;
	  break;		/* 'C' */

	default:
	  a4gl_yyerror ("Unexpected Error");
	return -1;
	}
    }

  /* 4GL identifiers are case insensitive - force to lower case */
  if (a == 2)
    {
      to_lower_str (buff);
    }

  if (strlen(buff)) fix_bad_strings (buff);

  /* call set_str() to send back to the parser the text/value 
   * associated with the token.
   */
  /*set_str (buff);*/

  if (a==CONCAT_PIPES) { strcpy(buff,"||"); }

  if (a==NAMED_GEN||a==CHAR_VALUE) ; else { 
		/* a4gl_upshift(buff);  */ /* This would appear to be a bad idea... */
	}

  A4GL_lexer_set_str (pyylval, buff);

  lastword = buff;
  lastlex = a;
  A4GL_debug (">>>>>%04d %d (%4d) %s code=%d fpos=%d chk4var=%d", yylineno, A4GL_get_ccnt(), a, buff, xccode, fpos, chk4var);
  word_cnt = 0;
  if (file_out) { 
		char*buff2;
		buff2=acl_strdup(buff);
		if (a==NAMED_GEN) {
			downshift(buff2);
		} else {
			upshift(buff2);
		}
		FPRINTF(file_out,":%s\n",buff2);
		free(buff2);
	}
  A4GL_debug ("lexer returns  a=%d, buff=%s\n", a, buff);

  return a;
}


void file_out_nl(char *why) {
if (file_out) {
	FPRINTF(file_out,"NL %s\n",why);
}
}

void file_out_indent(int cnt) {
if (file_out) {
	FPRINTF(file_out,"INDENT %d\n",cnt);
}
}




/**
 *
 * @param kw
 * @param v
 */
void
turn_state (int kw, int v)
{
  int a;
#ifdef NEWLIST
  for (a = 0; a <= 26; a++)
    {
      turn_state_all (kw, v, a);
    }
#else
  for (a = 0; kwords[a].id > 0; a++)
    {
      if (kwords[a].id == kw)
	{

	  /* debug("a=%d kw=%d\n",a,kw); */
	  if (v)
	    kwords[a].mode++;
	  else
	    kwords[a].mode--;
	  /* return; */
	}
    }
#endif
}


#ifdef MOVED
/**
 *
 * @param s
 */
void
set_namespace (char *s)
{
  strcpy (namespace, s);
}

/**
 *
 * @param s
 */
char *
get_namespace (char *s)
{
//printf("get namespace for %s : ",s);
  if (is_builtin_func (s)) {

		//printf("aclfgl_\n");
    return "aclfgl_";		/* Always has aclfgl_...*/
  }

//printf("%s\n",namespace);
  return namespace;
}
#endif


#ifdef MOVED

/**
 *
 * @param s
 */
int
is_builtin_func (char *s)
{
  int a;
  extern char *builtin_aclfgl_functions[];

  for (a = 0; builtin_aclfgl_functions[a]; a++)
    {
      if (strcmp (s, builtin_aclfgl_functions[a]) == 0)
	return 1;
    }
  return 0;
}
#endif




#ifdef NEWLIST
/**
 *
 * @param kw
 * @param v
 * @param arr
 */
static void
turn_state_all (int kw, int v, int arr)
{
  struct s_kw *local_kwords;
  int a;
  local_kwords = A4GL_lexer_get_hashed_list(arr);

/* debug("State changes %d to %d\n",kw,v); */
  for (a = 0; local_kwords[a].id > 0; a++)
    {
      if (local_kwords[a].id == kw)
	{

	  /* debug("a=%d kw=%d\n",a,kw); */
	  if (v)
	    local_kwords[a].mode++;
	  else
	    local_kwords[a].mode--;
	  /* return; */
	}
    }

}
#endif

/**
 *
 * @param a
 */
char *
get_idents (int a)
{
  return idents[a];
}



// Anything allowed in here needs to be added to the sqlblock.rule function as a possible sql_block_entry
// (with the obvious exceptions...)
int is_sql_kw(int a) {
	if (a==INSERT_INTO) return 1;
	if (a==INTO) return 1;
	if (a==KW_COMMA) return 1;
	if (a==COLON) return 1;
	if (a==OPEN_SQUARE) return 1;
	if (a==CLOSE_SQUARE) return 1;
	if (a==OPEN_BRACKET) return 1;
	if (a==DOLLAR) return 1;
	if (a==KW_MULTIPLY) return 1;
	if (a==KW_DOT) return 1;
	if (a==NAMED_GEN) return 1;
	if (a==END_SQL) return 1;
	if (a==GREATER_THAN_EQ) return 1;
	if (a==LESS_THAN_EQ) return 1;
	if (a==NOT_EQUAL) return 1;
	if (a==CONCAT_PIPES) return 1;
	if (a==END_SQL) return 1;
	if (a==-1) return 1;


return 0;
}
/* ================================== EOF ========================= */
