/*
@(#)File:            $RCSfile: pattern.c,v $
@(#)Version:         $Revision: 1.2 $
@(#)Last changed:    $Date: 2002-06-14 09:23:16 $
@(#)Purpose:         I4GL Interface to Regular Expressions
@(#)Author:          J Leffler, JLSS
*/

/*
**  Uses UNIX System V Release 4.0 function REGEXPR(3G).
**
**  If you do not have this available, contact JLSS for an emulation.
**
**  The I4GL function cannot easily provide the full functionality of
**  the underlying C code because of the difficulty of communicating
**  pointers and such like back to I4GL code.  It does, however, accept
**  the full regular expression syntax for input.  You cannot get at the
**  bracketed sub-expressions.
**
**  Calling:
**      CALL patt_scan(string, "[A-Z][a-z]*") RETURNING loc1, loc2
**      IF patt_match(string, "[A-Z][a-z]*") THEN ...
**
**  loc1 and loc2 are both integers; loc1 is -1 if there is an error in
**  the calling sequence or in the regular expression.  It is 0 if there
**  is no match.  Loc1 is the index where the match starts when there is
**  an index, and loc2 is the index of the last character in the string
**  which matches.  This means that string[loc1, loc2] is the matching
**  substring.  Patt_match returns false on failure to compile or on
**  failure to match; it only returns true when the pattern matches.
**
**	Note: because of the way I4GL handles strings, it is difficult to
**	look for trailing blanks.  Trailing blanks are removed from both the
**	pattern and the searched string.  Trailing blanks in the pattern can
**  be specified using the character class "[ ]".
**
**  Efficiency:
**  The expression is compiled every time the function is called.  If
**  this becomes a big overhead, the interface will need to be redefined.
**  An appropriate interface would be:
**      LET patt_no = patt_compile(pattern)
**      CALL patt_search(patt_no, string) RETURNING loc1, loc2
**      IF patt_check(patt_no, string) THEN ...
**      CALL patt_release(patt_no)
**  Internally, the program would maintain an array of compiled patterns,
**  indexed by pattern number minus 1 (or some larger constant).
**
**  The code could also make available some I4GL accessible global variables.
**  A suitable structure would be:
**  I4GL:
**  patt_match      RECORD
**                  loc1        INTEGER,
**                  loc2        INTEGER,
**                  locs        INTEGER,
**                  nbra        INTEGER,
**                  braslist    ARRAY[10] OF INTEGER,
**                  braelist    ARRAY[10] OF INTEGER,
**                  reglength   INTEGER,
**                  regerrno    INTEGER
**                  END RECORD
**  C:
**  struct
**  {
**      loc1        long;
**      loc2        long;
**      locs        long;
**      nbra        long;
**      braslist    long[10];
**      braelist    long[10];
**      reglength   long;
**      regerrno    long;
**  }   patt_match;
**
**  You would need to pay careful attention to the semantics of this
**  data.  Not only do you have to translate the C pointers into indexes,
**  but locs in particular affects the way the search continues.  Note
**  that REGEXPR(3G) uses pointers to the start and one-beyond-the-end of
**  the matched strings, whereas for I4GL, it is better to return the
**  start and end indexes of the matched strings.
**
**  The patt_ prefix could be changed if required.
*/

#include <regexpr.h>

#ifndef BUFSIZ
#define BUFSIZ	512
#endif

#define I4GL_C	int

#ifndef lint
static	char	sccs[] = "@(#)$Id: pattern.c,v 1.2 2002-06-14 09:23:16 afalout Exp $";
#endif

I4GL_C	patt_scan(n)
int		n;
{
	char	buffer[BUFSIZ];
	char	pattern[BUFSIZ];
	char	*regexp;

	if (n != 2)
	{
		retint(-1);
		retint(-1);
	}
	else
	{
		popstring(pattern, sizeof(pattern));
		popstring(buffer,  sizeof(buffer));
		regexp = compile(pattern, (char *)0, (char *)0);
		if (regexp == (char *)0)
		{
			/* Failed to compile */
			retint(-1);
			retint(-1);
		}
		else if (step(buffer, regexp) != 0)
		{
			/* Got a match */
			retint(loc1 - buffer + 1);
			retint(loc2 - buffer);
			free(regexp);
		}
		else
		{
			/* No match */
			retint(0);
			retint(0);
			free(regexp);
		}
	}
	return(2);
}

I4GL_C	patt_match(n)
int		n;
{
	char	buffer[BUFSIZ];
	char	pattern[BUFSIZ];
	char	*regexp;

	if (n != 2)
		retint(0);
	else
	{
		popstring(pattern, sizeof(pattern));
		popstring(buffer,  sizeof(buffer));
		regexp = compile(pattern, (char *)0, (char *)0);
		if (regexp == (char *)0)
			/* Failed to compile */
			retint(0);
		else if (step(buffer, regexp) != 0)
		{
			/* Got a match */
			retint(1);
			free(regexp);
		}
		else
		{
			/* No match */
			retint(0);
			free(regexp);
		}
	}
	return(1);
}
