/*
    dbbeauty.c - 4GL program beautifier
    Copyright (C) 1991,1992,1994  David A. Snyder

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; version 2 of the License.
 
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
 
    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

/* this program Upshifts all Informix 4gl keywords, and nothing else */

#ifndef lint
	static char const module_id[] =
		"@(#) dbbeauty.c 1.1  94/04/15 21:37:37";
#endif /* not lint */


#include <stdio.h>
#include <string.h>
#include "keyword.h"

/* ARGSUSED */
main (argc, argv)
     int argc;
     char *argv[];
{
  void perror (), process ();

#ifdef DEBUG
  /* Print copyright message */
  (void) fprintf (stderr,
		  "DBBEAUTY version 1.1, Copyright (C) 1991,1992,1994 David A. Snyder\n\n");
#endif

  /* Process each file on command line or stdin */
  if (!*++argv)
    process ();
  else
    do
      {
	if (!freopen (*argv, "r", stdin))
	  {
	    perror (*argv);
	    continue;
	  }
	process ();
      }
    while (*++argv);
  return (0);
}


void
process ()
{
  char *bsearch (), s[100], tmp_s[100];
  int delimiter, getword (), node_compare ();
  struct node *node_ptr, node;
  void upshift ();

  /* Because node.string is a pointer, this will allocate memory for it */
  node.string = tmp_s;

  while ((delimiter = getword (s)) != EOF)
    {
      (void) strcpy (node.string, s);
      node_ptr = (struct node *) bsearch ((char *) (&node),
					  (char *) word_table, WORD_TABSIZE,
					  sizeof (struct node), node_compare);

      if (node_ptr != NULL)
	{
	  (void) strcpy (s, node_ptr->string);
	  upshift (s);
	}
      (void) printf ("%s%c", s, delimiter);
    }
}


getword (s)
     char *s;
{
  char *sptr;
  int c, fglalpha ();

  sptr = s;
  while ((c = getchar ()) != EOF)
    {
      switch (c)
	{
	case '-':
	  if ((c = getchar ()) == '-')
	    {
	      (void) putchar ('-');
	      (void) putchar (c);
	      while ((c = getchar ()) != '\n' && !feof (stdin))
		(void) putchar (c);
	    }
	  else
	    {
	      (void) ungetc (c, stdin);
	      c = '-';
	      break;
	    }
	  (void) putchar (c);
	  continue;
	case '#':
	  (void) putchar (c);
	  while ((c = getchar ()) != '\n' && !feof (stdin))
	    (void) putchar (c);
	  if (!feof (stdin))
	    (void) putchar (c);
	  continue;
	case '{':
	  (void) putchar (c);
	  while ((c = getchar ()) != '}' && !feof (stdin))
	    (void) putchar (c);
	  if (!feof (stdin))
	    (void) putchar (c);
	  continue;
	case '"':
	  (void) putchar (c);
	  while ((c = getchar ()) != '"' && c != '\n' && !feof (stdin))
	    (void) putchar (c);
	  if (!feof (stdin))
	    (void) putchar (c);
	  continue;
	}
      if (!fglalpha (c))
	break;
      *sptr++ = (char) c;
    }
  *sptr = '\0';

  return (c);
}


fglalpha (c)
     int c;
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_')
      || (c >= '0' && c <= '9'))
    return (1);

  return (0);
}


node_compare (node1, node2)
     struct node *node1, *node2;
{
  return strcmp (node1->string, node2->string);
}


void
upshift (s)
     char *s;
{
  int toupper ();

  while (*s)
    *s++ = (char) toupper (*s);
}
