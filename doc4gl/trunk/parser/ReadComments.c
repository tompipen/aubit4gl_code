
/**
 * @file
 * Methods to read 4gl comments from the source input stream.
 *
 * Because they use the parser function p4glLexInput() they need to be coupled
 * to it.
 *
 * @todo : Mechanism to use standard comments as doc comments (for refactorings)
 *
 */

/*
 * @author : Sergio Ferreira
 * $Date: 2003-02-05 12:45:12 $
 * $Id: ReadComments.c,v 1.2 2003-02-05 12:45:12 saferreira Exp $
 */

#include "stdio.h"
#include "StringBuffer.h"
#include "p4gl_lex.h"

/**
 * The lexer found the begining of documentation comment from the input
 * source file.
 *
 * @todo : The storing of the comment somewhere.
 * @todo : It should return a char * instead a StringBuffer
 *
 * This function reads it until it found the end of the comment "}" character
 * marker.
 *
 * @return A StringBuffer with the complete text of the comment readed.
 */
char *readDocComment(void)
{
	int ch;
	int inComment = 0;
	char *textComment;
	StringBuffer *docComment;

	docComment = newStringBuffer();
  while ( inComment == 0 )
	{
		ch = p4glLexInput();
		switch (ch)
		{
		  case EOF:
			  inComment = 1;
		  case '}':
			  inComment = 1;
			  break;
			case '\n':
				appendCharStringBuffer(docComment,ch);
			  incrementLineno();
			  break;
      default:
				appendCharStringBuffer(docComment,ch);
			  break;
		}
  }
	textComment = strdup(docComment->buffer);
	destroyStringBuffer(docComment);
	return textComment;
}

/*
 * Read a block comment from yyin
 * It uses the syntax of 4gl { } and i have a block comment of my own 
 * thath does not coment the block to 4gl. It starts with {IGNORE } and
 * finishes with { IGNORE}.
 *
 * @todo : The storing of the comment somewhere.
 *
 * @return A string with the readed comment. Null if an IGNORE comment
 */
char *readBlockComment(void)
{ 
  char str[80];
  int  j, ch = 1;


	if ( lexgets(str,7) != NULL && strcmp("IGNORE",str) == 0 )
  {
    /* ignorar ate proximo IGNORE */
		/* printf("IGNORE : \n"); */
			fprintf(stderr,"IGNORE FOUND %d\n",getLineno());
    while (lexgets (str, 80) != NULL) 
    {
			incrementLineno();
      j = strlen(str);
			/*printf(str); */
      if (j > 8 && strstr(&str[j -8], "/IGNORE}"))
        break;
      /* Leu IGNORE */
    }
			fprintf(stderr,"IGNORE END %d\n",getLineno());
  }
  else
  {
    /* Voltar atras n caracteres */
		lexunput(str,strlen(str));

		/* Ignorar comentário */
	  if ( (!isLoadStdComments()) || (!isInLimbo()))
		{
      while (ch != EOF)
			{
        ch = p4glLexInput();
				if ( ch == '}' || ch == EOF)
				  break;
        if ( ch == '\n' )
			    incrementLineno();
	    }
		  return;
		}

		/* Ler comentário normal para documentação (refactorings) */
		{
	  /* TODO - Tornar isto mais dinâmico */
	  char *comment = (char *)malloc(512);
		char *oldComment;
    register int i=0;
		int commentTerminated = 0;
    while (commentTerminated == 0)
		{
			ch = p4glLexInput();
			oldComment = comment;
			comment = (char *)ensureCapacity(oldComment,512,i);
			switch ( ch )
			{
			  case '\n':
					comment[i] = ch;
					i++;
			    incrementLineno();
					break;
			  case '}':
					commentTerminated = 1;
				  break;
			  case EOF:
					commentTerminated = 1;
				  break;
			  case 0:
					comment[i] = 32;
					i++;
					break;
			  default:
					comment[i] = ch;
					i++;
					break;
		  }
	  }
		  comment[i] = '\0';
			/** @todo : Take this processing from here
		  P4glCb.currFglDoc->buffer = (char *)appendStr(
		    P4glCb.currFglDoc->buffer,comment
		  );
			*/
			return comment;
		}
  }
	return NULL;
}

/**
 * Read a line comment from the source file input stream.
 *
 * @todo : Refactoring of this function
 *
 * @return The comment readed. Null if the comment is not to be readed
 */
char *readLineComment()
{
  int ch;
	static char lcStr[256];
	register int i=0;

    while ((ch=p4glLexInput()) != '\n' && ch != EOF);
			incrementLineno();
		return;

	if ( (!isLoadStdComments()) || (!isInLimbo()))
	{
    while ((ch=p4glLexInput()) != '\n' && ch != EOF);
			incrementLineno();
  }
	else
	{
		int commentTerminated = 0;
		/*
	  lcStr = malloc(256);
		*/
		if ( i >= 255 )
		  fprintf(stderr,"ERRO COMENTÁRIO DE LINHA > 256");
    while (commentTerminated == 0)
		{
		  ch = p4glLexInput();
			switch ( ch )
			{
			  case '\n':
					commentTerminated = 1;
			    incrementLineno();
					break;
				case EOF:
					commentTerminated = 1;
					break;
			  default:
			    lcStr[i] = ch;
			    i++;
					break;
			}
		}
		/* @todo : Inserir num buffer de linhas */
		/*
		P4glCb.currFglDoc->buffer = appendStr(P4glCb.currFglDoc->buffer,lcStr);
		printf("&&&&&&&&&&&&&&&&&&&&&&&&& Estragar currFgldoc\n");
		*/
		/*free(lcStr);*/
		return lcStr;
	}
	return NULL;
}

