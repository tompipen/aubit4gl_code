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
 * This is a new version of the original aubit 4gl lexer.
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "y.tab.h"
#include <ctype.h>

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


int sql_mode;
// @todo Uncomment if needed
//extern int sql_mode;

int idents_cnt = 0;
FILE *yyin = 0;			/* Pointer to the source file openen being parsed */
int yylineno = 1;		/* Current line number */
int lastlex = -2;
int xccode = 0;     /* Flag to help insice ccode parsing */
int word_cnt = 0;

char yyline[2000] = "";	/* Current line read so far, incl. CR/LF */
int yyline_len = 0;		  /* Length of current line */
long yyline_fpos = 0;		/* FIle position of start of current line */


char *lastword;         /* The last word founded */

#define MAX_XWORDS 1024

char xwords[MAX_XWORDS][256];
char idents[256][256];

/** @todo : Understand if this variable is realy necessary */
long fpos;             /* The position in the file */



/* Extern reserved words table */
struct s_kw *kwords;
extern struct s_kw *hashed_list[];

extern char infilename[];
extern int yyin_len;
extern int chk4var;

extern int ccnt;		/* defined in others.c */

/** Current state to help in the identifier problem */
int current_yylex_state;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

static int chk_word_more (FILE * f, char *buff, char *p, char *str, int t);
//char *A4GL_translate (char *s);
static void turn_state_all (int kw, int v, int arr);
static int get_hash_val (char *s);
/* The lexer entry point */
int a4gl_yylex (void *pyylval, int yystate, void *yys1, void *yys2);

/*
 * Functions that this lexer depends:
 *    A4GL_memfile_getc (f);
 *    A4GL_memfile_ftell (f);
 *    a4gl_yyerror ("");
 */

/*
=====================================================================
                    Functions implementation definition
=====================================================================
*/

/**
 * Read and return a new caracter from the input file.
 *
 * @param f The file pointer to the file where the parsing is made.
 * @return The caracter getted from the source file opened.
 */
int mja_fgetc (FILE * f)
{
  int a;

  a = A4GL_memfile_getc (f);

  /* UNIX will end the line with 13(CR=\r) and 10(LF=\n); 
	 * DOS will end it with only 10(LF=\n) 
	 */

  if (a == '\n')		//ASCII 10 = LF
  {
    yylineno++;
    fpos = A4GL_memfile_ftell(f);
  }

  // maintain a buffer (yyline) holding current line being scanned
  if ((yyline_len == 0) || (yyline[yyline_len - 1] == '\n'))
  {    // we're starting a new line - clear and reset
    yyline[0] = a;
    yyline_len = 1;
    yyline_fpos = A4GL_memfile_ftell (f);
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
 *
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

  // remove from current line buffer
  if (yyline_len > 0)
    yyline[--yyline_len] = '\0';
}

/**
 * Checks if a string is possible identifier.
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
		      if (strcasecmp (word, "endcode") == 0)
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
  if (*t == CHAR_VALUE)
  {
    char *s;
    s = strdup (ptr + 1);
    s[strlen (s) - 1] = 0;
		// @todo : Uncomment if needed
    //A4GL_dumpstring (s, yylineno, infilename);
		// @todo : Uncomment if needed
    //s2 = A4GL_translate (s);
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
 *
 * @param cnt
 * @param pos
 * @param f The file pointer to the file being parsed
 * @param p
 * @return
 *    0 - 
 *    1 -
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
    return 0;
  }
  return 1;
}

/**
 * Iterate the kwords.vals array until != 0.
 *
 * @param c The index in the kwords array.
 * @return A static buffer containing the concatenation of the values in 
 *         the vals table. If it found <ident> concatenate ???? 
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
 * @param f The file pointer that identifies the opened file source.
 * @param str A pointer to a string where ???? its appended.
 * @return The keyword integer identifier (please use the defines).
 */
static int
chk_word (FILE * f, char *str)
{
  char *p;
  int t;
  char buff[256];

  /* read the next word from the 4GL source file */
  p = read_word (f, &t);
  set_yytext(p);
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
      && (xccode == 0) && (strncmp (yyline, p, strlen (p)) == 0))
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
    printf ("Unexpected end of file - no endcode\n");
    exit (0);
  }

  if (xccode && (strcasecmp (p, "endcode") == 0
		 || strcasecmp (p, "--!endcode") == 0
		 || strcasecmp (p, "--!end code") == 0
		 || strcasecmp (p, "end code") == 0))
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
  return chk_word_more (f, buff, p, str, t);
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
 * @param f
 * @param buff
 * @param p
 * @param str
 * @param t
 * @return
 */
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

  kwords = hashed_list[get_hash_val (p)];

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
    yyline[0] = '\0';
    yyline_len = 0;
    if (yyline_fpos < a)
	  {

#ifndef OLDWAY
	  int tl;
	  static char tmpbuff[2000];
	  A4GL_memfile_fseek (f, yyline_fpos, SEEK_SET);
	  tl = A4GL_memfile_ftell (f);
	  //printf("a-tl = %d\n",a-tl);
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
 * @todo - convert identifier to USER_DTYPE if required....
 *
 * @param pyyval
 * @param yystate
 * @param yys1
 * @param yys2
 */
int
a4gl_yylex (void *pyylval, int yystate, void *yys1, void *yys2)
{
  int a;
  char buff[1024];
  char buffval[20480];
  int allow;
  static int last_pc = 0;

  current_yylex_state = yystate;

  if (yyin == 0)
    {
      printf ("No input...\n");
      exit (0);
    }

  a = A4GL_memfile_ftell (yyin);
  if (yyin_len)
  {
    a = a * 100 / yyin_len;
    if (a > last_pc)
	  {
	    last_pc = a;
	  }
  }
  a = chk_word (yyin, buff);
  //A4GL_debug("chk_word returns token=%d, buff=%s state=%d\n", a, buff, yystate);

  allow = allow_token_state (yystate, a);
  //A4GL_debug ("Allow_token_State = %d state=%d\n", allow, yystate);

  if (sql_mode == 0)
  {
    if (allow == 0) {
		  int t;
		  t=isnum(buff);
		  if (t==1) a=INT_VALUE;
		  if (t==2) a=NUMBER_VALUE;
		  if (t!=1&&t!=2) {
		 	  if (isident (buff)) {
				  a = NAMED_GEN;
			  }
		  }
	  }

    if (allow_token_state (yystate, USER_DTYPE) && a == NAMED_GEN)
	  {
						/* TO UNCOMENT
	    if (A4GL_find_datatype (upshift (buff)))
	    {
	      a = USER_DTYPE;
	    }
			*/
	  }
  }
  else
  {
    if (allow == 0)
	    a = SQL_TEXT;
  }

  //A4GL_debug ("-> %d (NAMED_GEN=%d)\n", a, NAMED_GEN);

  if (a == 2 || a == NAMED_GEN)
  {
    //A4GL_debug ("  Constant check returns %d", 
								//check_for_constant (buff, buffval));

		//@todo : Uncomment this 
    //switch (check_for_constant (buff, buffval))
    switch (10)
	  {
	    case 0:
	      break;

	    case 1:
	      //A4GL_debug (" Constant switch %s Char", buffval);
	      strcpy (buff, buffval);
	      a = CHAR_VALUE;
	      break;		/* 'c' */

	    case 2:
	      //A4GL_debug (" Constant switch %s Float", buffval);
	      strcpy (buff, buffval);
	      a = NUMBER_VALUE;
	      break;		/* 'f' */
	    case 3:
	      //A4GL_debug (" Constant switch %s Integer", buffval);
	      strcpy (buff, buffval);
	      a = INT_VALUE;
	      break;		/* 'i' */
	    case 4:
	      //A4GL_debug (" Constant switch %s ident", buffval);
	      strcpy (buff, buffval);
	      a = NAMED_GEN;
	      break;		/* 'C' */
	    default:
	      a4gl_yyerror ("Unexpected Error");
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
	// @todo : Uncomment because it is realy needed.
  //set_str (pyylval, buff);

  lastword = buff;
  lastlex = a;
  word_cnt = 0;
  //A4GL_debug ("lexer returns  a=%d, buff=%s\n", a, buff);

  return a;
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
 * @param a
 */
char *
get_idents (int a)
{
  return idents[a];
}


/*
chk_for_kw_in(short *yys1,short *yys2,int a,char *buff) {
short *stack_cnt;
int r;
int could_be;
could_be=0;

  for (stack_cnt=yys2;stack_cnt>=yys1;stack_cnt--) {
      		r = wants_kw_token (*stack_cnt, a);
		if (r==1) {
			if (scan_variable (buff) == -1) r=0;
			else return a;
		}
		printf("r=%d\n",r);
		if (r==2) {
			printf("Y");
			could_be++;
		}
		if (r==3) {
			printf("X");
			could_be++;
		}
 }
 if (could_be) return 2;
 return 0;

		if (r==0) {
			return a;
		}

		if (r==2) {
			//return NAMED_GEN;
			continue;
		}

		if (r==3) {
			continue;
		}

 		if (r==1) {
			if (scan_variable (buff) != -1) return NAMED_GEN;
			else return a;
		}
  }

  return NAMED_GEN;
}
*/

/* ================================== EOF ========================= */
