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
# $Id: lexer.c,v 1.45 2003-02-05 00:05:00 mikeaubury Exp $
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

#include "a4gl_4glc_int.h"
#include "y.tab.h"


/*
=====================================================================
					Constants definitions
=====================================================================
*/

#ifndef KWS_COMMENT
	#define KWS_COMMENT COMMENT
#endif

#define stricmp 		aubit_strcasecmp
#define TYPE_EOF  		-1
#define TYPE_USTRING  	-2	/* unterminated string */
#define TYPE_NUM 		3

/*
=====================================================================
                    Variables definitions
=====================================================================
*/


int 			idents_cnt 	= 0;
FILE *			yyin 		= 0;	/* Pointer to the source file openen being parsed */
int 			yylineno 	= 1;	/* Current line number */
int 			lastlex 	= -2;
int 			xccode 		= 0;
int 			word_cnt 	= 0;

char   yyline[256]   ="";  /* Current line read so far, incl. CR/LF */
int    yyline_len    = 0;  /* Length of current line */
long   yyline_fpos   = 0;  /* FIle position of start of current line */


char *			lastword;

char 			xwords[256][256];
char 			idents[256][256];
long 			fpos;

struct translate_string {
	char *from;
	char *to;
	char *identifier;
};

/* Extern reserved words table */
extern struct 	s_kw kwords[];
extern char 	curr_func[];
extern char 	infilename[];
extern int 		yyin_len;
extern int 		in_define;
extern struct 	translate_string *translate_list;
extern int 		translate_list_cnt;
extern int 		chk4var;

extern int 		ccnt; 				/* defined in others.c */

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

char *	translate	(char *s);

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
int a;


	a = getc (f);

  /* UNIX will end the line with 13(CR=\r) and 10(LF=\n); DOS will end it with only 10(LF=\n) */
  
  if (a == '\n') //ASCII 10 = LF
	{
		yylineno++;
		fpos = ftell (f);
    }

// maintain a buffer (yyline) holding current line being scanned
   if ( (yyline_len == 0) || (yyline[yyline_len-1] == '\n') )
    // we're starting a new line - clear and reset
   {
       yyline[0] = a;
       yyline_len = 1;
       yyline_fpos = ftell(f);
   }
   else
    // append char to line buffer - avoid overflow by shifting left
   {
       if ( yyline_len > 255 ) { memmove(yyline, &yyline[1], --yyline_len); }
       yyline[yyline_len++] = a;
   }
   yyline[yyline_len] = '\0';

  return a;
}


/**
 * @param a The Character to be ungeted
 * @param f The file pointer of file being read
 */
static void
mja_ungetc (int a, FILE * f)
{
	ungetc (a, f);

	if (a == '\n')
    {
	  yylineno--;
      fpos = ftell (f);
    }

 // remove from current line buffer
   if ( yyline_len > 0 ) yyline[--yyline_len] = '\0';

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
  if (instr == 0 || (a != '\n' && a != '\r' && a != '\t'))
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
isnum(char *s)
{
  int a;
  int dp = 0;

  for (a = 0; a < strlen (s); a++)
  {
    if (a == 0 && (s[a] == '-' || s[a] == '+'))
	    continue;
    if (s[a] == '.' && dp == 0)
	  {
	    dp++;
	    continue;
	  }
    if (s[a] >= '0' && s[a] <= '9')
	    continue;
    return 0;
  }
  if (strchr (s, '.'))
    return 2;
  return 1;
}


/**
 * Continuation of the action of read a new word from the source file
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

		if (feof (f))
        {
		  *t = TYPE_EOF;
		  return word;
		}

		if (xccode == 2)
		{
			while (1)
		    {
		      if (feof (f))
				break;
		      if (a == '\n' || a == '\r')
				{
				  if (aubit_strcasecmp (word, "endcode") == 0)
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
		      if (feof (f))
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


        /* printf("Read %d = %c\n",a,a); */

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
		      if (feof (f))
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

	    if (a == '-' && instrs == 0 && instrd == 0 && xccode == 0)
		{
		  int z;
		  z = mja_fgetc (f);
		  mja_ungetc (z, f);
		  if (z == '-')
		    {
		      while (1)
			{
			  a = mja_fgetc (f);
			  if (feof (f))
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
			a = mja_fgetc (f);
			if (a != '!')
		    {
				while (1)
	            {
					a = mja_fgetc (f);
					if (feof (f))
						break;
					if (a == '}')
						break;
					/* ccat(word,a,instrs||instrd); */
				}
			}
			*t = KWS_COMMENT;
			return word;
		}

	    if ((a == '\n' || a == '\r') && escp == 0)
		{
		  if (instrs || instrd)
		    {
		      printf ("Unterminated string escp=%d?\n", escp);
		      *t = TYPE_USTRING;
		    }
		  if (strlen (word) > 0)
		    return word;
		  else
		    continue;
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

	    if (ispunct (a) && a != '.' && a != '_' && instrs == 0 && instrd == 0)
		{
		  if (strlen (word) > 0)
		    {
		      mja_ungetc (a, f);
		      return word;
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
		      ccat (word, '"', instrs || instrd);
		      *t = CHAR_VALUE;
		      return word;
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
		      ccat (word, '"', instrs || instrd);
		      *t = CHAR_VALUE;
		      return word;
		    }
		  ccat (word, '"', instrs || instrd);
		  instrs = 1;
		  continue;
		}


	    if (a=='"' && !escp && instrs==1) 
		{
		  ccat (word, '\\', instrs || instrd);
	    }

      ccat (word, a, instrs || instrd);
      escp = 0;
    
	} // while loop ends here

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
  
  ptr = read_word2 (f, t);
  if (*t==CHAR_VALUE) {
		char *s;
		s=strdup(ptr+1);
		s[strlen(s)-1]=0;
		dumpstring(s,yylineno,infilename);
		s2=translate(s);
		if (s2) ptr=s2;
  }

  /* if (s) ptr=s; */
  strcpy (xwords[word_cnt], ptr);
  word_cnt++;

  return ptr;
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
words (int cnt, int pos, FILE * f, char *p)
{
int z;
int t;
char buff[132];
int states = -1;

  strcpy (buff, kwords[cnt].vals[pos]);

  if (buff[0] == '*' && strlen (buff) > 1)
    {
      strcpy (buff, &kwords[cnt].vals[pos][1]);
      states = 1;
    }

  if (stricmp (buff, "<ident>") == 0)
    {

      /* printf("check %s\n",p); */
      if (isident (p) == 0)
	return 0;
      strcpy (idents[idents_cnt++], p);

    }
  else
    {
      if (stricmp (p, buff) != 0)
	{
	  return 0;
	}
    }
  if (states != -1)
    start_state (buff, states);

  if (kwords[cnt].vals[pos + 1] == 0)
    {
      return 1;
    }

  p = read_word (f, &t);

  z = words (cnt, pos + 1, f, p);

  if (z == 0)
    {
      /* fseek(f,f_pos,SEEK_SET); */
      return 0;
    }
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
  strcpy (buff, "");
  for (a = 0; kwords[c].vals[a]; a++)
    {
      if (a > 0)
	strcat (buff, " ");

      if (stricmp (kwords[c].vals[a], "<ident>") == 0)
	{
	  strcat (buff, idents[icnt++]);
	}
      else
	{
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
chk_word (FILE * f, char *str )
{
long a;
int cnt;
char *p;
int t;
char buff[256];
int oline;
cnt = 0;

  /* read the next word from the 4GL source file */
  p = read_word (f, &t);

  debug("chk_word: read_word returns %s\n",p);

  /* C/SQL code can be embedded in 4GL inside code/endcode blocks.
   * These are handled entirely by the lexer, so we test for this
   * here. While we are in such blocks, the compiler will copy the
   * source verbatim without any alterations or error checking.
   * A code block starts with the word 'code' by itself on a line,
   * and ends with the word 'endcode'.
   */

  if ( ( aubit_strcasecmp (p, "--!code") == 0
	 || aubit_strcasecmp (p, "code") == 0
	)
	 && (xccode == 0)
	 && (mja_strncmp(yyline,p,strlen(p)) == 0 )
     )
    {
      xccode = 1;
      return KW_CSTART;
    }

  if (strcmp (p, "sql_code") == 0 && xccode == 0)
    {
      xccode = 2;
      return KW_CSTART;
    }

  if (t==TYPE_EOF && xccode) {
	printf("Unexpected end of file - no endcode\n");
	exit(0);
  }

  if ( xccode && (
        aubit_strcasecmp (p, "endcode") == 0
        || aubit_strcasecmp (p, "--!endcode") == 0
        || aubit_strcasecmp (p, "--!end code") == 0
        || aubit_strcasecmp (p, "end code") == 0 )
     )
    {
      lex_printc ("/* End of code */");
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
  oline = yylineno;
  a = ftell (f);
  strcpy (buff, p);

  /* check if the current word is a known reserved/key word */
  while (kwords[cnt].id > 0)
	{
		strcpy (p, buff);
		if (kwords[cnt].mode >= 1)
		{
	  		idents_cnt = 0;
			if (words (cnt, 0, f, p))
		    {
		      strcpy (str, mk_word (cnt));
		      return kwords[cnt].id;
	    	}
		}

		/* restore current input file position, in case of read-ahead */
		/* also, restore current line buffer */
		yylineno = oline;
		cnt++;
        yyline[0]='\0';
        yyline_len=0;
        if (yyline_fpos < a ) {
          fseek (f, yyline_fpos, SEEK_SET);
          while (ftell(f) < a ) {
            yyline[yyline_len++]= getc(f);
            yyline[yyline_len]='\0';
          }
        }
        else {
          fseek (f, a, SEEK_SET);
        }

	}

  /* check for literal numbers - these cannot be key words or identifiers */
  strcpy (str, p);
  a = isnum (str);
  if (a == 1)
    t = INT_VALUE;
  if (a == 2)
    t = NUMBER_VALUE;

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

      if (s[a + 1] == '[' || s[a + 1] == ']' || s[a + 1] == '^'
	  || s[a + 1] == '/')
	{
	  buff[c++] = s[a + 1];
	  a++;
	  continue;
	}
      buff[c++] = '\\';
    }

  buff[c] = 0;
  debug ("Fixstring changed %s to %s", s, buff);
  strcpy (s, buff);
  return;
}

/**
 *  Lexical analysis entry point.
 *
 *  Called by yyparse() from yacc when the parser wants to be feeded with
 *  more tokens.
 *
 *  The purpose is give tokens to the syntatic parser (made in yacc/bison).
 *
 */
int
//yylex (void)
yylex (void *pyylval, int yystate)
{
  int a;
  char buff[1024];
  char buffval[20480];
  static int last_pc=0;
  int r;

  debug ("In yylex ... yystate=%d", yystate);

  if (yyin == 0)
    {
      printf ("No input...\n");
      exit (0);
    }

  a=ftell(yyin);
  a=a*100/yyin_len;
  if (a>last_pc) {
		last_pc=a;
		if (strcmp(acl_getenv("PRINTPROGRESS"),"Y")==0)
			printf("%d %% complete\n",last_pc);
  }

  a = chk_word (yyin, buff);

  debug("chk_word returns token=%d, buff=%s", a, buff);

  //if (chk4var)
     //a = NAMED_GEN;

  /* variables/identifiers with the same names as 4GL keywords 
   * can easily be confused - any keyword tokens (they start from 1000) 
   * need to be checked. If the current parser state is expecting an
   * identifier but not this keyword, then assume it's an identifier
   */
  if ( a >= 1000 && isident(buff) && a != KW_TRUE &&
       a != KW_FALSE && a != KW_NULL &&
       (strcmp(acl_getenv("RESERVEWORDS"),"YES")!=0) )
  {
    r = wants_kw_token(yystate,a);
    debug("wants_kw_token -> %d", r);
    switch ( r )
     {
      case 0:
        /* use the keyword token */
           break;
      case 1:
        /* identifier only if defined variable */
           to_lower_str(buff);
	   if ( scan_variable(buff) == -1 ) break;
      case 2:
      case 3:
        /* treat as identifier, unless token starts a command */
           if ( is_commandkw(a) == 0 ) a = NAMED_GEN;
     }
  }

  if (a == 2 || a == NAMED_GEN)
    {
      debug ("  Constant check returns %d", check_for_constant(buff, buffval));
      switch (check_for_constant (buff, buffval))
	{
	case 0:
	  break;
	case 1:
	  debug (" Constant switch %s Char", buffval);
	  strcpy (buff, buffval);
	  a = CHAR_VALUE;
	  break;		/* 'c' */
	case 2:
	  debug (" Constant switch %s Float", buffval);
	  strcpy (buff, buffval);
	  a = NUMBER_VALUE;
	  break;		/* 'f' */
	case 3:
	  debug (" Constant switch %s Integer", buffval);
	  strcpy (buff, buffval);
	  a = INT_VALUE;
	  break;		/* 'i' */
	}
    }

  /* 4GL identifiers are case insensitive - force to lower case */
  if (a == 2)
    {
      to_lower_str (buff);
    }

  fix_bad_strings (buff);

  /* call set_str() to send back to the parser the text/value 
   * associated with the token.
   */
  //set_str (buff);
  set_str (pyylval, buff);

  lastword = buff;
  lastlex = a;
  if (acl_getenv ("DEBUG"))
    {
      debug (">>>>>%04d %d (%4d) %s code=%d fpos=%d chk4var=%d",
		yylineno, ccnt, a, buff, xccode, fpos, chk4var);
    }
  word_cnt = 0;

  debug("lexer returns  a=%d, buff=%s\n", a, buff);

  return a;
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
/* debug("State changes %d to %d\n",kw,v); */
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
}


/**
 *
 * @param a
 */
char *
get_idents(int a)
{
	return idents[a];
}


/* ================================== EOF ========================= */

