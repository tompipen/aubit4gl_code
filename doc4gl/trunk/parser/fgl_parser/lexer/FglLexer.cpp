
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
 * This one is implemented only as a C++ class.
 * This is a new version of the original great aubit 4gl lexer made 
 * by Mike Aubury.
 *
 * @todo : Understand how this good lexer works.
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include <ctype.h>
#include <string.h>
#include <stdio.h>


#include "MemFile.h"
#include "KeyWord.h"
#include "FglAst.h"
#include "FglLexer.h"
#include "y.tab.h"
// @todo : Remove this after cleaning more
#include "a4gl_4glc_int.h"

#define	AST_STATE	((NodeState *)astState)

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

#define NOT_NUMBER 0
#define DECIMAL_NUMBER 1
#define FRAC_NUMBER 2

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

#define NO_CODE 0
#define C_CODE 1
#define SQL_CODE 2


/*
 * Modules that the lexer depends:
 *   MemFile.cpp
 *   KeyWord.cpp
 */

/*
=====================================================================
                    Functions implementation definition
=====================================================================
*/

/**
 * The default constructor.
 */
FglLexer::FglLexer() 
{
  idents_cnt = 0;
  yylineno = 1;		
  lastlex = -2;
  word_cnt = 0;
  strcpy(yyline,"");
  xccode = NO_CODE; 
  yyline_len = 0;		  
  yyline_fpos = 0;		

	keyWord = new KeyWord();
}

/**
 * Read and return a new caracter from the input file.
 * Use the API that gets each caracter from the input. 
 * Currently each file is loaded to a memory buffer in the begining of
 * the processing.
 *
 * @return The caracter getted from the source file opened.
 */
int FglLexer::getChar(void)
{
  int readedCh;

  readedCh = memFile->getchar();
  if (readedCh == 0x0c) 
	  readedCh=' ';

  /* UNIX will end the line with 13(CR=\r) and 10(LF=\n); 
	 * DOS will end it with only 10(LF=\n) 
	 */

  if (readedCh == '\n')		//ASCII 10 = LF
  {
    yylineno++;
  }

  // maintain a buffer (yyline) holding current line being scanned
  if ((yyline_len == 0) || (yyline[yyline_len - 1] == '\n'))
  {    // we're starting a new line - clear and reset
    yyline[0] = readedCh;
    yyline_len = 1;
    yyline_fpos = memFile->ftell ();
		currSrcColumn = 0;
  }
  else
  {    // append char to line buffer - avoid overflow by shifting left
    if (yyline_len > 255)
	  {
	    memmove (yyline, &yyline[1], --yyline_len);
	  }
    yyline[yyline_len++] = readedCh;
		currSrcColumn++;
  }
  yyline[yyline_len] = '\0';

  return readedCh;
}


/**
 * Unget a allready readed caracter from the source file.
 * Use the memfile API to unget from the buffer.
 * Currently the source file is maimntained in a memory buffer.
 *
 * @param a The Character to be ungeted
 * @param f The file pointer of file being read
 */
void FglLexer::ungetChar (int a)
{
  memFile->ungetchar(a);

  if (a == '\n')
  {
    yylineno--;
  }

  // remove from current line buffer
  if (yyline_len > 0)
    yyline[--yyline_len] = '\0';
	currSrcColumn = yyline_len;
}

/**
 * Checks if a string is possible identifier acording to the rules.
 * A string could be a alfabetical, number or underscore.
 *
 * @param str The string to be checked
 * @return
 *   - 0 : Its NOT an identifier
 *   - 1 : Could be an identifier
 */
int FglLexer::isident (char *str)
{
  int i;
  for (i = 0; i < strlen (str); i++)
  {
    if (isalnum (str[i]) || str[i] == '_')
	    continue;
    return 0;
  }
  return 1;
}

/*
 * Concatenate a character at the end of a string.
 * The string cannot be bigger then 1023.
 * Note : The string should have 3 more spaces to concatenate.
 *
 * @param s A pointer to the string that should be appended.
 * @param a The caracter to be added.
 * @param instr
 */
void FglLexer::ccat (char *s, char ch, int instr)
{
  char buff[3];
  if (strlen (s) >= 1023)
  {
    a4gl_yyerror ("Internal error - word overflow..");
  }
  if (instr == 0 || (ch != '\n' && ch != '\r' && ch != '\t'))
  {
    buff[0] = ch;
    buff[1] = 0;
    strcat (s, buff);
  }
  else
  {
    buff[0] = '\\';

    if (ch == '\n')
	    buff[1] = 'n';
    if (ch == '\t')
	    buff[1] = 't';
    if (ch == '\r')
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
 * NOT_NUMBER 0
 * DECIMAL_NUMBER 1
 * FRAC_NUMBER 2
 */
int FglLexer::isNum (char *s)
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
    return NOT_NUMBER;
  }

  if (is_e > 1)
  {
    return NOT_NUMBER;
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
    return FRAC_NUMBER;
  }

  return DECIMAL_NUMBER;
}


/**
 * Continuation of the A4GL_action of read a new word from the source file
 *
 * It reads sequentialy chracters until found a separator, or if
 * reading a operator (such as +) just return it.
 *
 * @param f The file pointer to the source being parsed
 * @param tokenType A pointer to a place where this function put the type 
 *        of word founded.
 * @return A pointer to a static buffer that contains the token readed
 */
char *FglLexer::read_word2 (int *tokenType)
{
  static char word[1024] = "";
  int escp = 0;
  int instrs = 0;
  int instrd = 0;
  int a;

  strcpy (word, "");
  *tokenType = NAMED_GEN;

  while (1)
  {
    a = getChar ();

    if (memFile->feof ())
	  {
	    *tokenType = TYPE_EOF;
	    return word;
	  }

		// @todo : Refactor this into a separated function.
    if (xccode == SQL_CODE)
	  {
	    while (1)
	    {
	      if (memFile->feof ())
		      break;
	      if (a == '\n' || a == '\r')
		    {
		      if (strcasecmp (word, "endcode") == 0)
		        break;
		      a = getChar ();
		      continue;
		    }

	      if (a == ';')
		    {
		      break;
		    }
	      ccat (word, a, instrs || instrd);
	      a = getChar ();
	    }
	    *tokenType = CLINE;
	    return word;
	  }

		// @todo : Refactor this into a function
    if (xccode == C_CODE)
	  {
	    while (1)
	    {
	      if (memFile->feof ())
		      break;
	      if (a == '\n' || a == '\r')
		    {
		      break;
		    }
	      ccat (word, a, instrs || instrd);
	      a = getChar ();
	    }
	    *tokenType = CLINE;
	    return word;
	  }
  
  
    /* printf("Read %d = %c\n",a,a); */
  
		// Found a # comment.
		// @todo : Refactor this into a function.
    if (a == '#' && instrs == 0 && instrd == 0 && xccode == NO_CODE)
	  {
	    if (strlen (word) > 0)
	    {
	      ungetChar (a);
	      return word;
	    }
  
	    while (1)
	    {
	      a = getChar ();
	      if (memFile->feof ())
		      break;
	      if (a == '\n' || a == '\r')
		    {
		      break;
		    }
	      ccat (word, a, instrs || instrd);
	    }
	    *tokenType = KWS_COMMENT;
	    return word;
	  } // Refactor to a function
  
    if (a == '-' && instrs == 0 && instrd == 0 && xccode == NO_CODE)
	  {
	    int z;
      if (strlen (word) > 0) {                  
        ungetChar (a);                  
				return word;                
		  }
	    z = getChar ();
	    ungetChar (z);
	    if (z == '-')
	    {
	        while (1)
		      {
		        a = getChar ();
		        if (memFile->feof ())
		          break;
		        if (a == '\n' || a == '\r')
		          break;
		        ccat (word, a, instrs || instrd);
		      }
	        *tokenType = KWS_COMMENT;
	        return word;
	      }
	  }
  
  
    if (a == '!' && instrs == 0 && instrd == 0 && xccode == NO_CODE)
	  {
	    char c;
	    c = getChar ();
	    if (c == '}')
	    {
	      strcpy (word, "!}");
	      *tokenType = KWS_COMMENT;
	      return word;
	    }
	    else
	    {
	      ungetChar (c);
	    }
	  }
  
		// Found a open bracket comment.
		// @todo : Refactor this into a function.
		// @todo : Fgldoc comment
    if (a == '{' && instrs == 0 && instrd == 0 && xccode == NO_CODE)
	  {
	    if (strlen (word) > 0)
	    {
	      ungetChar (a);
	      return word;
	    }
  
	    a = getChar ();
	    if (a != '!')
	    {
	      while (1)
		    {
		      a = getChar ();
		      if (memFile->feof ())
		        break;
		      if (a == '}')
		        break;
		      /* ccat(word,a,instrs||instrd); */
		    }
	    }
	    *tokenType = KWS_COMMENT;
	    return word;
	  }
  
    if ((a == '\n' || a == '\r') && escp == 0)
	  {
	    if (instrs || instrd)
	    {
	      printf ("Unterminated string escp=%d?\n", escp);
	      *tokenType = TYPE_USTRING;
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
	      ungetChar (a);
	      return word;
	    }
	  }
  
    if (instrs == 0 && instrd == 0 && (ispunct (a)) && a != '"' && a != '\''
	      && a != '_')
	  {
	    if (strlen (word) > 0)
	    {
	      if (isNum (word) && a == '.');
	      else
		    {
		      ungetChar (a);
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
	      x = getChar ();
	      ungetChar (x);
  
	      if (x != '"')
		    {
		      ccat (word, '"', instrs || instrd);
		      *tokenType = CHAR_VALUE;
	        if ( traceTokens )
					  printf("TOKEN STRING %s\n",word);
		      return word;
		    }
	      else
		    {
		      x = getChar ();
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
	      *tokenType = CHAR_VALUE;
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
 * @todo : This should be a plugin
 *
 * @param s The string to be translated
 * @return The translated string.
 */
char *FglLexer::A4GL_translate (char *s) {
  return s;
}

/**
 * Read a new word from the source file.
 *
 * @param t A pointer to the place where to left the type of token 
 *          readed.
 * @return A pointer to a static buffer that contains the token readed
 */
char *FglLexer::read_word (int *tokenType)
{
  char *ptr;
  char *s2;

  ptr = read_word2 (tokenType);

	// If it is a string take the quotes an try to translate it.
	// This could be in read_word2
	// @todo : This can have a memory leak.
  if (*tokenType == CHAR_VALUE)
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
 * @param pos The position in the words array of the kwords array.
 * @param p The token found.
 * @return
 *    0 - 
 *    1 -
 */
int FglLexer::words (int cnt, int pos,char *word)
{
  int z;
  int t;
  char buff[132];
  int states = -1;

	// Que estranho. Ele vem aqui mesmo que seja string
  strcpy (buff, kwords[cnt].vals[pos]);

	// Se encontrou *
  if (buff[0] == '*' && strlen (buff) > 1)
  {
    strcpy (buff, &kwords[cnt].vals[pos][1]);
    states = 1;
  }

	// Se encontro a dizer que quer um identificador verifica se recebeu uma
	// coisa que pode ser identificador e copia para o array de 
	// identificadores (idents).
	// É estranho porque mesmo que seja string vem aqui
  if (stricmp (buff, "<ident>") == 0)
  {

    //printf("check %s\n",word);
    if (isident (word) == 0)
		{
	    return 0;
		}
    strcpy (idents[idents_cnt++], word);

  }
  else
  {
    if (stricmp (word, buff) != 0)
	  {
	    return 0;
	  }
  }

	// Se chegou ao fim da tabela de palavras 
  if (kwords[cnt].vals[pos + 1] == 0)
  {
    return 1;
  }

  word = read_word (&t);

	//printf("word = %s\n", word);
  z = words (cnt, pos + 1, word);

  if (z == 0)
  {
    return 0;
  }
  return 1;
}

/**
 * Iterate the kwords.vals array it arrives to the end.
 * @todo : Check if the text variable dimension it is not a problem
 *
 * @param c The index in the kwords array.
 * @return A static buffer containing the concatenation of the values in 
 *         the vals table. If it found <ident> concatenate ???? 
 */
char *FglLexer::mk_word (int c)
{
  static char text[256];
  int a;
  int icnt = 0;
  strcpy (text, "");
	// Iterate in the the words of the current multiword keyword
  for (a = 0; kwords[c].vals[a]; a++)
  {
    if (a > 0)
	    strcat (text, " ");

		// If the word tells that should be an identifier
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
 * Check if it is a multi symbol reserved word.
 *
 * @param buff
 * @param p The current keyword readed
 * @param str The next word (lookahead)
 * @param tokenType The type of the token readed.
 * @return The type of the next token readed.
 */
int FglLexer::chk_word_more (char *buff, char *p, char *str, int tokenType)
{
  int cnt = 0;
  int oline;
  int a;
  cnt = 0;

  oline = yylineno;

  a = memFile->ftell ();
  /* check if the current word is a known reserved/key word */

	if ( traceTokens )
	  printf("p = %s, str = %s\n",p,str);

	kwords = keyWord->getKwords(p);

	// Pesquisa no array de keywords até chegar ao fim
	// ou encontrar  ???
  while (kwords[cnt].id > 0)
  {
    strcpy (p, buff);
    if (kwords[cnt].mode >= 1)
	  {
	    idents_cnt = 0;
	    if (words (cnt, 0, p))  // If it arrives to the end of the array and OK
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

	  memFile->fseek (yyline_fpos, SEEK_SET);
	  while (memFile->ftell () < a)
	    {
	      yyline[yyline_len++] = memFile->getchar();
	      yyline[yyline_len] = '\0';
	    }
	  }
    else
	  {
	    memFile->fseek (a, SEEK_SET);
	  }

  }

  //A4GL_debug("p=%s buff=%s",p,buff);
  /* check for literal numbers - these cannot be key words or identifiers */
  strcpy (str, p);

  a = isNum (p);
  if (a == DECIMAL_NUMBER)
  {
    strcpy (str, p);
    return INT_VALUE;
  }
  if (a == FRAC_NUMBER)
  {
    strcpy (str, p);
    return NUMBER_VALUE;
  }
  return tokenType;
}

/**
 * Read and check what kind of word was readed.
 * Check if a token is a reserved word (even with multi-word symbols).
 *
 * If so it returns an integer (wich is defined with #define generated by
 * yacc/bison) that easily identifies the reserved word.
 *
 * If its not a reserved word could be a NUMBER, IDENTIFIER, ???
 *
 * @param str A pointer to a string where the symbol found is returned.
 * @return The keyword integer identifier (please use the defines).
 *         The string readed in str
 */
int FglLexer::chk_word (char *str)
{
  char *p;
  int tokenType;
  char buff[256];

  /* read the next word from the 4GL source file */
  p = read_word (&tokenType);
  //set_yytext(p);
  //A4GL_debug ("chk_word: read_word returns %s\n", p);

  /* C/SQL code can be embedded in 4GL inside code/endcode blocks.
   * These are handled entirely by the lexer, so we test for this
   * here. While we are in such blocks, the compiler will copy the
   * source verbatim without any alterations or error checking.
   * A code block starts with the word 'code' by itself on a line,
   * and ends with the word 'endcode'.
   */

	// Adicionado por sérgio para corrigir ">"
	if ( tokenType == CHAR_VALUE )
	  return CHAR_VALUE;
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

  if (tokenType == TYPE_EOF && xccode)
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
  if (tokenType == KWS_COMMENT)
  {
    strcpy (str, p);
    return chk_word (str);
  }

  /* the special end of file token indicates we have reached the end */
  if (tokenType == TYPE_EOF)
  {
    strcpy (str, "");
    return -1;
  }

  /* save the current input file location, as we have to do some
   * reading ahead when checking for multi-word keywords
   */
  strcpy (buff, p);
  return chk_word_more (buff, p, str, tokenType);
}


/**
 * Convert the case of each character (if needed) to lower case.
 *
 * @param c The string to be lowered
 */
void FglLexer::to_lower_str (char *s)
{
  int a;
  for (a = 0; a < strlen (s); a++)
  {
    s[a] = tolower (s[a]);
  }
}

/**
 * Fixes up back-slash quoting in source code strings.
 * @todo : The maximum length of the string should be parametrized or dynamic.
 *
 * @param s The string to be fixed
 */
void FglLexer::fix_bad_strings (char *s)
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
 * @param pyylval A pointer to the union where the diferent values are stored.
 * @param yystate The current state in the bsion parser.
 * @param yys1 Not used 
 * @param yys2 Not used
 * @return The type of the token found. It corresponds to the %token defined 
 *         and used in the parser.
 */
int FglLexer::yyLex (void *pyylval, int yystate, short *yys1, short *yys2,
                     NodeState *astState)
{
  int tokenType;
  char text[1024];
  char buffval[20480];
  int allow;
	YYSTYPE *yylval = (YYSTYPE *)pyylval;

  current_yylex_state = yystate;

	// Read and check what kind of word was readed.
  tokenType = chk_word(text);

	// See if the kind of keyword is alowed acording to the parser state.
  allow = allow_token_state (yystate, tokenType);

	// The bison parser nows that we are in SQL BLOCK. Read until it
	// Threat things diferently
	// @todo : The parser rigth now does not assign sql_mode.
	// @todo : Put this in a separated function.
	// If sql_mode == 0 we are not in sql mode
  if (sql_mode == 0)
  {
    if (allow == 0) {
		  int t;
		  t = isNum(text);
		  if (t == DECIMAL_NUMBER) 
			  tokenType=INT_VALUE;
		  if (t == FRAC_NUMBER) 
			  tokenType=NUMBER_VALUE;
		  if (t != DECIMAL_NUMBER && t!= FRAC_NUMBER) {
		 	  if (isident (text)) {
				  tokenType = NAMED_GEN;
			  }
		  }
	  }

	  // Calls the generated from y.output allow token state to see if the word
	  // found is to be returned as identifier or TOKEN
    if (allow_token_state (yystate, USER_DTYPE) && tokenType == NAMED_GEN)
	  {
						/* @todo : Uncomment.
	    if (A4GL_find_datatype (upshift (text)))
	    {
	      tokenType = USER_DTYPE;
	    }
			*/
	  }
  }
  else  // SQLMODE
  {
    if (allow == 0)
	    tokenType = SQL_TEXT;
  }

  /* 4GL identifiers are case insensitive - force to lower case */
  if (tokenType == 2)
  {
    to_lower_str (text);
  }

  fix_bad_strings (text);
  lastlex = tokenType;
  word_cnt = 0;
  //A4GL_debug ("lexer returns  tokenType=%d, text=%s\n", tokenType, text);

	// @todo : Return diferent things if identifier or other things.
	// Assign the value to send it to the parser.
	yylval->node = AST_STATE->FglIdentifierCreate(strdup(text));
	if ( traceTokens )
    printf("lexer returns  tokenType=%d, text=%s, line=%d\n", 
			tokenType, text, yylineno);
  return tokenType;
}

/**
 * Setter function to the trace token(s) property.
 * This is used mainly for debugging purposes.
 *
 * @param _traceTokens Flag to indicate that we want to trace tokens.
 *        0 - Do not trace
 *        otherwise - trace / log tokens
 */
void FglLexer::setTraceTokens(char _traceTokens) {
  traceTokens = _traceTokens;
}

/**
 * Setter to the memfile object 
 *
 * @param _memFile A reference to the MemFile object.
 */
void FglLexer::setMemFile(MemFile *_memFile) {
  memFile = _memFile;
}

/**
 * Assign the error handler.
 *
 * @param _parserError A pointer to the error handler.
 */
void FglLexer::setParserError(ParserError *_parserError)
{
	parserError = _parserError;
}

/**
 * Get the parser error handler.
 *
 * @return A pointer to the error handler.
 */
ParserError *FglLexer::getParserError(void)
{
	return parserError;
}

/**
 * @return the current line where the lexer was reading the tokens.
 */
int FglLexer::getLine() 
{
	return yylineno;
}

/* ================================== EOF ========================= */
