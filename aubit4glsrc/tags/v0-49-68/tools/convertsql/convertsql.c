#include "convertsql.h"

int putbuff (char c);
void clearbuff (void);
void trimbuff (void);

char *buff;			// pointer to statement buffer
int bc;				// buffer counter : current length of buffer
char *bp;			// buffer pointer : points to buff[bc]
int buffsize = 4000;		// initial size of statement buffer
int incrsize = 2000;		// increase by this amount when using realloc()



/*
 * Does the actual work of reading standard input, converting each
 * statement where necessary, and writing the result to stdout.
 */
int
process_stdin (char *dialect_in, char *dialect_out)
{
  char c;
  char quote = 0;
  int slash = 0;
  int n = 0;
  char *ptr;

  buff = malloc (buffsize);
  clearbuff ();

  /* read stdin into the statement buffer, converting and
   * outputting each time we get an unquoted semi-colon.
   */
  while ((c = getchar ()) > 0)
    {
      if (!putbuff (c))
	return 1;
      /* watch out for slash-quoted chars */
      if (slash)
	{
	  slash = 0;
	  continue;
	}
      if (quote == 0 && c == ';')
	{
	  /* we have an unquoted semi-colon; process what we have
	     * in the statement buffer, then clear for the next one
	   */
	  ptr=A4GL_convert_sql_new (dialect_in, dialect_out, buff);
	  strcpy(buff,ptr);
	  trimbuff ();
	  if (strlen(buff)) {
	  	printf("%s;\n",buff);
	  }
	  clearbuff ();
	  continue;
	}
      /* detect sequences inside matched quotes, as we
       * must ignore semi-colons appearing in them
       */
      switch (c)
	{
	case '\\':
	  slash = 1;
	  break;
	case '\"':
	case '\'':
	  if (quote == c)
	    {
	      quote = 0;
	    }
	  else
	    {
	      if (quote == 0)
		{
		  quote = c;
		}
	    }
	}
    }

  /* anything in the buffer but not terminated with semi-colon ? */
  if (bc > 1)
    {
      ptr=A4GL_convert_sql_new (dialect_in, dialect_out, buff);
	  strcpy(buff,ptr);
      trimbuff ();
      printf ("%s\n", buff);
    }

  return 0;
}


/* --------  Functions for manipulating the statement buffer ------------ */

/*
 * Clear the statement buffer and pad it with spaces.
 * Reset the buffer pointer and buffer counter
 */
void
clearbuff ()
{
  memset (buff, 0, buffsize);
  buff[buffsize-1] = '\0';
  bp = buff;
  bc = 0;
}

/*
 * Append the given char to the statement buffer.
 * Realloc() if the buffer is not big enough.
 */
int
putbuff (char c)
{
  /* if the buffer is too small, resize it -  die if this fails ! */
  if (bc > (buffsize * 3 / 4))
    {
      char *p;
      buffsize += incrsize;
      if ((p = realloc (buff, buffsize)) == NULL)
	{
	  fprintf (stderr, "Could not allocate sufficient memory\n");
	  return 0;
	}
      buff = p;
      bp = &buff[bc];
    }
  /* ok, now add the char to the buffer */
  *bp++ = c;
  bc++;
  return 1;
}


void
trimbuff ()
{
A4GL_trim(buff);
}


