/*
 */

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
 * This is a new version of the original freat aubit 4gl lexer made 
 * by Mike Aubury.
 *
 * @todo : This lexer should be visible to parser just by yylex() function
 * @todo : Understand how this good lexer works.
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "y.tab.h"
#include <ctype.h>
#include <string.h>

//prevent a4gl_4glc_int.h from including windows.h that we don't need here, that would
//mess up constants defined in y.tab.h generated with new version of Bison
// To Mike: please resist the urge to name constants like "CHAR" "STRING" "COMMA" etc.
// please use A4GL_ namespace.
#define _NO_WINDOWS_H_
#include "a4gl_4glc_int.h"

#include "memfile.h"

/*
=====================================================================
					Constants definitions
=====================================================================
*/

#ifndef KWS_COMMENT
#define KWS_COMMENT COMMENT
#endif

#define stricmp 		strcasecmp
#define TYPE_EOF  		-1
#define TYPE_USTRING  	-2	/* unterminated string */
#define TYPE_NUM 		3

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

// This flag should be assigned by a function.

/**
 *  @todo : If we want that the parser is reentrant all global variables 
 *  should be removed.
 *   To do that we need to work with objects (in C or C++) but with objects.
 */
static int sql_mode;

static int idents_cnt = 0;

/**
 * Current 4gl source file line number 
 */
int yylineno = 1;		

/**
 * 
 */
static int lastlex = -2;

#define NO_CODE 0
#define C_CODE 1
#define SQL_CODE 2
/** Flag to help inside c ans SQL code parsing */
static int xccode = NO_CODE; 

/**
 *
 */
static int word_cnt = 0;

/** 
 * Current line read so far, incl. CR/LF 
 */
static char yyline[2000] = "";	

/**
 * Length of current line
 */
static int yyline_len = 0;		  

/**
 * FIle position of start of current line 
 */
static long yyline_fpos = 0;		


#define MAX_XWORDS 1024

/**
 * 
 */
static char xwords[MAX_XWORDS][256];

/**
 *
 */
static char idents[256][256];


/** 
 * Extern reserved words table.
 * The reserved words table is synamicaly generated based on the kwords
 * file.
 * The lexer use it to see wich words are reserved.
 */
struct s_kw *kwords;

/**
 *
 */
extern struct s_kw *hashed_list[];

/** 
 * Current state to help in the identifier problem 
 * @todo : This is just assigned. No other usage.
 */
static int current_yylex_state;


/*
 * Modules that the lexer depends:
 *   memfile.c
 * Other functions that this lexer depends:
 *    a4gl_yyerror ("");
 */

/*
=====================================================================
                    Functions implementation definition
=====================================================================
*/

/**
 * Read and return a new caracter from the input file.
 * Use the API that gets each caracter from the input. 
 * Currently each file is loaded to a memory buffer in the begining of
 * the processing.
 *
 * @return The caracter getted from the source file opened.
 */
int lexer_fgetc (void)
{
  int a;

  a = A4GL_memfile_getc ();
  if (a==0x0c) a=' ';

  /* UNIX will end the line with 13(CR=\r) and 10(LF=\n); 
	 * DOS will end it with only 10(LF=\n) 
	 */

  if (a == '\n')		//ASCII 10 = LF
  {
    yylineno++;
  }

  // maintain a buffer (yyline) holding current line being scanned
  if ((yyline_len == 0) || (yyline[yyline_len - 1] == '\n'))
  {    // we're starting a new line - clear and reset
    yyline[0] = a;
    yyline_len = 1;
    yyline_fpos = A4GL_memfile_ftell ();
  }
  else
  {    // append char to line buffer - avoid overflow by shifting left
    if (yyline_len > 255)
	  {
	    memmove (yyline, &yyline[1], --yyline_len);
	  }
    yyline[yyline_len++] = a;
  }
  yyline[yyline_len] = '\0';

  return a;
}


/**
 * Unget a allready readed caracter from the source file.
 * Use the memfile API to unget from the buffer.
 * Currently the source file is maimntained in a memory buffer.
 *
 * @param a The Character to be ungeted
 * @param f The file pointer of file being read
 */
static void
lexer_ungetc (int a)
{
  A4GL_memfile_ungetc (a);

  if (a == '\n')
  {
    yylineno--;
  }

  // remove from current line buffer
  if (yyline_len > 0)
    yyline[--yyline_len] = '\0';
}

/**
 * Checks if a string is possible identifier acording to the rules.
 * A string could be a alfabetical, number or underscore.
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
 * Concatenate a character at the end of a string.
 * The string cannot be bigger then 1023.
 * Note : The string should have 3 more spacesto concatenate.
 *
 * @param s A pointer to the string that should be appended.
 * @param a The caracter to be added.
 * @param instr
 */
static void
ccat (char *s, char a, int instr)
{
  char buff[3];
  if (strlen (s) >= 1023)
  {
    a4gl_yyerror ("Internal error - word overflow..");
  }
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
 * Check if the content of a string represents a number.
 * 
 * @param s The string to be checked
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

    if (a&&(s[a] == 'e' || s[a] == 'E'))
	  {
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
    long n;
    double a_d = 0;
    long a_i = 0;
    int a_mode;

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

    sscanf (ptr, "%ld", &n);

    if (strchr (buff, '.'))
	  {
	    a_mode = 2;
	    sscanf (buff, "%lf", &a_d);
	  }
    else
	  {
	    a_mode = 1;
	    sscanf (buff, "%ld", &a_i);
	  }
    while (n)
	  {
	    if (a_mode == 1)
	      a_i = a_i * 10;
	    else
	      a_d = a_d * 10.0;
	    n--;
	  }
    if (a_mode == 1)
	  {
	    sprintf (s, "%ld", a_i);
	  }
    else
	  {
	    sprintf (s, "%f", a_d);
	  }
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
 * @param t A pointer to a place where this function put the type of word
 *          founded.
 * @return A pointer to a static buffer that contains the token readed
 */
static char *read_word2 (int *t)
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
    a = lexer_fgetc ();

    if (A4GL_memfile_feof ())
	  {
	    *t = TYPE_EOF;
	    return word;
	  }

		// @todo : Refactor this into a separated function.
    if (xccode == SQL_CODE)
	  {
	    while (1)
	    {
	      if (A4GL_memfile_feof ())
		      break;
	      if (a == '\n' || a == '\r')
		    {
		      if (strcasecmp (word, "endcode") == 0)
		        break;
		      a = lexer_fgetc ();
		      continue;
		    }

	      if (a == ';')
		    {
		      break;
		    }
	      ccat (word, a, instrs || instrd);
	      a = lexer_fgetc ();
	    }
	    *t = CLINE;
	    return word;
	  }

		// @todo : Refactor this into a function
    if (xccode == C_CODE)
	  {
	    while (1)
	    {
	      if (A4GL_memfile_feof ())
		      break;
	      if (a == '\n' || a == '\r')
		    {
		      break;
		    }
	      ccat (word, a, instrs || instrd);
	      a = lexer_fgetc ();
	    }
	    *t = CLINE;
	    return word;
	  }
  
  
    /* printf("Read %d = %c\n",a,a); */
  
		// Found a # comment.
		// @todo : Refactor this into a function.
    if (a == '#' && instrs == 0 && instrd == 0 && xccode == NO_CODE)
	  {
	    if (strlen (word) > 0)
	    {
	      lexer_ungetc (a);
	      return word;
	    }
  
	    while (1)
	    {
	      a = lexer_fgetc ();
	      if (A4GL_memfile_feof ())
		      break;
	      if (a == '\n' || a == '\r')
		    {
		      break;
		    }
	      ccat (word, a, instrs || instrd);
	    }
	    *t = KWS_COMMENT;
	    return word;
	  } // Refactor to a function
  
    if (a == '-' && instrs == 0 && instrd == 0 && xccode == NO_CODE)
	  {
	    int z;
      if (strlen (word) > 0) {                  
        lexer_ungetc (a, f);                  
				return word;                
		  }
	    z = lexer_fgetc ();
	    lexer_ungetc (z);
	    if (z == '-')
	    {
	        while (1)
		      {
		        a = lexer_fgetc ();
		        if (A4GL_memfile_feof ())
		          break;
		        if (a == '\n' || a == '\r')
		          break;
		        ccat (word, a, instrs || instrd);
		      }
	        *t = KWS_COMMENT;
	        return word;
	      }
	  }
  
  
    if (a == '!' && instrs == 0 && instrd == 0 && xccode == NO_CODE)
	  {
	    char c;
	    c = lexer_fgetc ();
	    if (c == '}')
	    {
	      strcpy (word, "!}");
	      *t = KWS_COMMENT;
	      return word;
	    }
	    else
	    {
	      lexer_ungetc (c);
	    }
	  }
  
		// Found a { comment.
		// @todo : Refactor this into a function.
    if (a == '{' && instrs == 0 && instrd == 0 && xccode == NO_CODE)
	  {
	    if (strlen (word) > 0)
	    {
	      lexer_ungetc (a);
	      return word;
	    }
  
	    a = lexer_fgetc ();
	    if (a != '!')
	    {
	      while (1)
		    {
		      a = lexer_fgetc ();
		      if (A4GL_memfile_feof ())
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
	      lexer_ungetc (a);
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
		      lexer_ungetc (a);
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
	      x = lexer_fgetc ();
	      lexer_ungetc (x);
  
	      if (x != '"')
		    {
		      ccat (word, '"', instrs || instrd);
		      *t = CHAR_VALUE;
		      return word;
		    }
	      else
		    {
		      x = lexer_fgetc ();
		      ccat (word, '\\', instrs || instrd);
		      ccat (word, '"', instrs || instrd);
		      continue;
		    }
	    }
	    ccat (word, '"', instrs || instrd);
	    instrd = 1;
	    continue;
	  }
  
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
  
  
    if (a == '"' && !escp && instrs == 1)
	  {
	    ccat (word, '\\', instrs || instrd);
	  }

    ccat (word, a, instrs || instrd);
    escp = 0;

  }				// while loop ends here
}

/**
 * Point to add string translation when wanted.
 *
 * @param s The string to be translated
 * @return The translated string.
 */
char *A4GL_translate (char *s) {
  return s;
}

/**
 * Read a new word from the source file.
 *
 * @param t A pointer to the place where to left the type of token 
 *          readed.
 * @return A pointer to a static buffer that contains the token readed
 */
static char *read_word (int *t)
{
  char *ptr;
  char *s2;

  ptr = read_word2 (t);

	// If it is a string take the quotes an try to translate it.
	// This could be in read_word2
	// @todo : This can have a memory leak.
  if (*t == CHAR_VALUE)
  {
    char *s;
    s = strdup (ptr + 1);
    s[strlen (s) - 1] = 0;
    s2 = A4GL_translate (s);
    if (s2)
	    ptr = s2;
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


/**
 * This function is executed several times for the some token readed.
 * This function calls it self.
 * Check if it is a multi word token and reads all the simbols that 
 * expect to find.
 * This function is called by check_word_more
 *
 * @param cnt The kwords array position.
 * @param pos The position in the vals array of the kwords array.
 * @param p The token found.
 * @return
 *    0 - 
 *    1 -
 */
static int
words (int cnt, int pos,char *p)
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

  p = read_word (&t);

  z = words (cnt, pos + 1, p);

  if (z == 0)
  {
    return 0;
  }
  return 1;
}

/**
 * Iterate the kwords.vals array until != 0.
 * @todo : Check if the text variable dimension it is not a problem
 *
 * @param c The index in the kwords array.
 * @return A static buffer containing the concatenation of the values in 
 *         the vals table. If it found <ident> concatenate ???? 
 */
static char *
mk_word (int c)
{
  static char text[256];
  int a;
  int icnt = 0;
  strcpy (text, "");
  for (a = 0; kwords[c].vals[a]; a++)
  {
    if (a > 0)
	    strcat (text, " ");

    if (stricmp (kwords[c].vals[a], "<ident>") == 0)
	  {
	    strcat (text, idents[icnt++]);
	  }
    else
	  {
	    strcat (text, kwords[c].vals[a]);
	  }
  }
  return text;
}

/**
 * Generate an Hash value to a string.
 *
 * @param s The string to wich we generate the hash.
 * @return The hash number that correspond to the string.
 */
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

/**
 * Check if it is a multi symbol reserved word.
 *
 * @param buff
 * @param p
 * @param str
 * @param t The type of the token readed.
 * @return The type of the next token readed.
 */
static int
chk_word_more (char *buff, char *p, char *str, int t)
{
  int cnt = 0;
  int oline;
  int a;
  cnt = 0;
  oline = yylineno;


  a = A4GL_memfile_ftell ();
  /* check if the current word is a known reserved/key word */

  kwords = hashed_list[get_hash_val (p)];

  while (kwords[cnt].id > 0)
  {
    strcpy (p, buff);
    if (kwords[cnt].mode >= 1)
	  {
	    idents_cnt = 0;
	    if (words (cnt, 0, p))
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

	  A4GL_memfile_fseek (yyline_fpos, SEEK_SET);
	  while (A4GL_memfile_ftell () < a)
	    {
	      yyline[yyline_len++] = A4GL_memfile_getc ();
	      yyline[yyline_len] = '\0';
	    }
	  }
    else
	  {
	    A4GL_memfile_fseek (a, SEEK_SET);
	  }

  }

  //A4GL_debug("p=%s buff=%s",p,buff);
  /* check for literal numbers - these cannot be key words or identifiers */
  strcpy (str, p);

  a = isnum (p);
  if (a == 1)
  {
    strcpy (str, p);
    return INT_VALUE;
  }
  if (a == 2)
  {
    strcpy (str, p);
    return NUMBER_VALUE;
  }
  return t;
}

/**
 * Check if a token is a reserved word.
 *
 * If so it returns an integer (wich is defined with #define generated by
 * yacc/bison) that easily identifies the reserved word.
 *
 * If its not a reserved word could be a NUMBER, IDENTIFIER, ???
 *
 * @param f The file pointer that identifies the opened file source.
 * @param str A pointer to a string where ???? its appended.
 * @return The keyword integer identifier (please use the defines).
 */
static int
chk_word (char *str)
{
  char *p;
  int t;
  char buff[256];

  /* read the next word from the 4GL source file */
  p = read_word (&t);
  //A4GL_debug ("chk_word: read_word returns %s\n", p);

  /* C/SQL code can be embedded in 4GL inside code/endcode blocks.
   * These are handled entirely by the lexer, so we test for this
   * here. While we are in such blocks, the compiler will copy the
   * source verbatim without any alterations or error checking.
   * A code block starts with the word 'code' by itself on a line,
   * and ends with the word 'endcode'.
   */

  if ((strcasecmp (p, "--!code") == 0
       || strcasecmp (p, "code") == 0)
      && (xccode == NO_CODE) && (strncmp (yyline, p, strlen (p)) == 0))
  {
    xccode = C_CODE;
    return KW_CSTART;
  }

  if (strcmp (p, "a4gl_start_sql_code") == 0 && xccode == NO_CODE)
  {
    xccode = SQL_CODE;
    return KW_CSTART;
  }

  if (t == TYPE_EOF && xccode)
  {
    printf ("Unexpected end of file - no endcode\n");
    exit (0);
  }

  if (xccode && (strcasecmp (p, "endcode") == 0
		 || strcasecmp (p, "--!endcode") == 0
		 || strcasecmp (p, "--!end code") == 0
		 || strcasecmp (p, "end code") == 0))
  {
    xccode = NO_CODE;
    return KW_CEND;
  }

  if (xccode == C_CODE)
  {
    strcpy (str, p);
    return CLINE;
  }

  if (xccode == SQL_CODE)
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
    return chk_word (str);
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
  return chk_word_more (buff, p, str, t);
}


/**
 * Convert the case of each character (if needed) to lower case.
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
 * @todo : The maximum length of the string should be parametrized.
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

    // We have one '\'

    if(!strchr(allowed_escape,s[a+1])) 
	  {  
		  // Fix \something where something isnt valid..
	    buff[c++] = s[a + 1];
	    a++;
	    continue;
    }

    buff[c++] = '\\';
    buff[c++] = s[a+1];
	  a++;
  }

  buff[c] = 0;
  //A4GL_debug ("Fixstring changed %s to %s", s, buff);
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
 *  Assume that the file is allready opened and this does not need to be tested.
 * @todo - convert identifier to USER_DTYPE if required....
 *
 * @param pyylval
 * @param yystate The current state in the bsion parser.
 * @param yys1 Not used 
 * @param yys2 Not used
 */
int
a4gl_yylex (void *pyylval, int yystate, void *yys1, void *yys2)
{
  int a;
  char text[1024];
  char buffval[20480];
  int allow;
  static int last_pc = 0;

  current_yylex_state = yystate;

  a = A4GL_memfile_ftell();
  if (A4GL_memfile_getLength())
  {
    a = a * 100 / A4GL_memfile_getLength();
    if (a > last_pc)
	  {
	    last_pc = a;
	  }
  }

	// Read and check what word was readed.
  a = chk_word (text);
  //A4GL_debug("chk_word returns token=%d, text=%s state=%d\n", a, text, yystate);

	// Calls the generated from y.output allow token state to see if the word
	// found is to be returned as identifier or TOKEN
  allow = allow_token_state (yystate, a);
  //A4GL_debug ("Allow_token_State = %d state=%d\n", allow, yystate);

	// The bison parser nows that we are in SQL BLOCK. Read until it
	// Threat things diferently
	// @todo : The parser rigth now does not assign sql_mode.
	// @todo : Put this in a separated function.
	// If sql_mode == 0 we are not in sql mode
  if (sql_mode == 0)
  {
    if (allow == 0) {
		  int t;
		  t=isnum(text);
		  if (t==1) a=INT_VALUE;
		  if (t==2) a=NUMBER_VALUE;
		  if (t!=1&&t!=2) {
		 	  if (isident (text)) {
				  a = NAMED_GEN;
			  }
		  }
	  }

	  // Calls the generated from y.output allow token state to see if the word
	  // found is to be returned as identifier or TOKEN
    if (allow_token_state (yystate, USER_DTYPE) && a == NAMED_GEN)
	  {
						/* TO UNCOMENT
	    if (A4GL_find_datatype (upshift (text)))
	    {
	      a = USER_DTYPE;
	    }
			*/
	  }
  }
  else  // SQLMODE
  {
    if (allow == 0)
	    a = SQL_TEXT;
  }

  //A4GL_debug ("-> %d (NAMED_GEN=%d)\n", a, NAMED_GEN);

	// Check if returned  ????
	// I think that it found a constant.
	// @todo : This should go to a separated function.
  if (a == 2 || a == NAMED_GEN)
  {
    //A4GL_debug ("  Constant check returns %d", 
								//check_for_constant (text, buffval));

		//@todo : Uncomment this 
    //switch (check_for_constant (text, buffval))
    switch (10)
	  {
	    case 0:
	      break;

	    case 1:
	      //A4GL_debug (" Constant switch %s Char", buffval);
	      strcpy (text, buffval);
	      a = CHAR_VALUE;
	      break;		/* 'c' */

	    case 2:
	      //A4GL_debug (" Constant switch %s Float", buffval);
	      strcpy (text, buffval);
	      a = NUMBER_VALUE;
	      break;		/* 'f' */
	    case 3:
	      //A4GL_debug (" Constant switch %s Integer", buffval);
	      strcpy (text, buffval);
	      a = INT_VALUE;
	      break;		/* 'i' */
	    case 4:
	      //A4GL_debug (" Constant switch %s ident", buffval);
	      strcpy (text, buffval);
	      a = NAMED_GEN;
	      break;		/* 'C' */
	    default:
	      a4gl_yyerror ("Unexpected Error");
	  }
  }

  /* 4GL identifiers are case insensitive - force to lower case */
  if (a == 2)
  {
    to_lower_str (text);
  }

  fix_bad_strings (text);

  /* call set_str() to send back to the parser the text/value 
   * associated with the token.
   */
  //set_str (text);
	// @todo : Uncomment because it is realy needed.
  //set_str (pyylval, text);

  lastlex = a;
  word_cnt = 0;
  //A4GL_debug ("lexer returns  a=%d, text=%s\n", a, text);

  printf("lexer returns  a=%d, text=%s\n", a, text);
  return a;
}

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
  local_kwords = hashed_list[arr];

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

/**
 * 
 *
 * @param kw
 * @param v
 */
void
turn_state (int kw, int v)
{
  int a;
  for (a = 0; a <= 26; a++)
  {
    turn_state_all (kw, v, a);
  }
}

/**
 * Get an element of the idents array.
 *
 * @param a The index in the array that we want to obtain.
 * @return A pointer to the identifier array.
 */
char *
get_idents (int a)
{
  return idents[a];
}

/* ================================== EOF ========================= */
