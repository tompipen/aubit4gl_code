/*
 * Copyright (c) 1995 Brigham Young University.  All rights reserved.
 * 
 * Permission is hereby granted, without written agreement and without
 * license or royalty fees, to use, copy, modify, and distribute this
 * software and its documentation for any purpose, provided that the 
 * above copyright notice and the following two paragraphs appear in 
 * all copies of this software.
 *
 * IN NO EVENT SHALL BRIGHAM YOUNG UNIVERSITY BE LIABLE TO ANY PARTY
 * FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES
 * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN
 * IF BRIGHAM YOUNG UNIVERSITY HAS BEEN ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * BRIGHAM YOUNG UNIVERSITY SPECIFICALLY DISCLAIMS ANY WARRANTIES, 
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER
 * IS ON AN "AS IS" BASIS, AND BRIGHAM YOUNG UNIVERSITY HAS NO OBLIGATION
 * TO PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
 */

/****************************************************************************
 * BRIAN K. HOLMAN             * E-Mail:               brian_holman@byu.edu *
 * Programmer/Systems Analyst  * URL: http://library.byu.edu/staff/bkh.html *
 * Library Information Systems * Mail:           2330 HBLL, Provo, UT 84602 *
 * Brigham Young University    * Phone:                      (801) 378-8162 *
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "formsproc.h"

/* Variable Definitions */

form_entry form_entries[MAX_ENTRIES];
cmdln_entry cmdln_entries[MAX_ENTRIES];
int num_form_entries;
int num_cmdln_entries;

/* CGI Functions */
void
getword (char *word, char *line, char stop)
{
  int x = 0, y;

  for (x = 0; ((line[x]) && (line[x] != stop)); x++)
    word[x] = line[x];

  word[x] = '\0';
  if (line[x])
    ++x;
  y = 0;

  while (line[y++] = line[x++]);
}

char *
makeword (char *line, char stop)
{
  int x = 0, y;
  char *word = (char *) malloc (sizeof (char) * (strlen (line) + 1));

  for (x = 0; ((line[x]) && (line[x] != stop)); x++)
    word[x] = line[x];

  word[x] = '\0';
  if (line[x])
    ++x;
  y = 0;

  while (line[y++] = line[x++]);
  return word;
}

char *
fmakeword (FILE * f, char stop, int *cl)
{
  int wsize;
  char *word;
  int ll;

  wsize = 102400;
  ll = 0;
  word = (char *) malloc (sizeof (char) * (wsize + 1));

  while (1)
    {
      word[ll] = (char) fgetc (f);
      if (ll == wsize)
	{
	  word[ll + 1] = '\0';
	  wsize += 102400;
	  word = (char *) realloc (word, sizeof (char) * (wsize + 1));
	}
      --(*cl);
      if ((word[ll] == stop) || (feof (f)) || (!(*cl)))
	{
	  if (word[ll] != stop)
	    ll++;
	  word[ll] = '\0';
	  return word;
	}
      ++ll;
    }
}

char
x2c (char *what)
{
  register char digit;

  digit = (what[0] >= 'A' ? ((what[0] & 0xdf) - 'A') + 10 : (what[0] - '0'));
  digit *= 16;
  digit += (what[1] >= 'A' ? ((what[1] & 0xdf) - 'A') + 10 : (what[1] - '0'));
  return (digit);
}

void
unescape_url (char *url)
{
  register int x, y;

  for (x = 0, y = 0; url[y]; ++x, ++y)
    {
      if ((url[x] = url[y]) == '%')
	{
	  url[x] = x2c (&url[y + 1]);
	  y += 2;
	}
    }
  url[x] = '\0';
}

void
plustospace (char *str)
{
  register int x;

  for (x = 0; str[x]; x++)
    if (str[x] == '+')
      str[x] = ' ';
}

int
rind (char *s, char c)
{
  register int x;
  for (x = strlen (s) - 1; x != -1; x--)
    if (s[x] == c)
      return x;
  return -1;
}

int
getline (char *s, int n, FILE * f)
{
  register int i = 0;

  while (1)
    {
      s[i] = (char) fgetc (f);

      if (s[i] == CR)
	s[i] = fgetc (f);

      if ((s[i] == 0x4) || (s[i] == LF) || (i == (n - 1)))
	{
	  s[i] = '\0';
	  return (feof (f) ? 1 : 0);
	}
      ++i;
    }
}

void
send_fd (FILE * f, FILE * fd)
{
  int num_chars = 0;
  char c;

  while (1)
    {
      c = fgetc (f);
      if (feof (f))
	return;
      fputc (c, fd);
    }
}

int
ind (char *s, char c)
{
  register int x;

  for (x = 0; s[x]; x++)
    if (s[x] == c)
      return x;

  return -1;
}

void
escape_shell_cmd (char *cmd)
{
  register int x, y, l;

  l = strlen (cmd);
  for (x = 0; cmd[x]; x++)
    {
      if (ind ("&;`'\"|*?~<>^()[]{}$\\", cmd[x]) != -1)
	{
	  for (y = l + 1; y > x; y--)
	    cmd[y] = cmd[y - 1];
	  l++;			/* length has been increased */
	  cmd[x] = '\\';
	  x++;			/* skip the character */
	}
    }
}

int
load_form_entries ()
{
  register int index;
  int content_length;

  num_form_entries = 0;
  if (strcmp (getenv ("REQUEST_METHOD"), "POST"))
    {
      /* Can't proceed if not a post */
      return 0;
    }
  if (strcmp (getenv ("CONTENT_TYPE"), "application/x-www-form-urlencoded"))
    {
      printf ("Content-type: text/html%c%c", 10, 10);
      printf ("This function can only be used to decode form results.\n");
      exit (1);
    }
  content_length = atoi (getenv ("CONTENT_LENGTH"));

  for (index = 0; content_length && (!feof (stdin)); index++)
    {
      num_form_entries = index;
      form_entries[index].val = fmakeword (stdin, '&', &content_length);
      plustospace (form_entries[index].val);
      unescape_url (form_entries[index].val);
      form_entries[index].name = makeword (form_entries[index].val, '=');
    }
  return num_form_entries;
}

void
free_form_entries ()
{
  register int index;

  for (index = 0; index <= num_form_entries; index++)
    {
      free (form_entries[index].name);
      free (form_entries[index].val);
    }
}

char *
retrieve_form_entry (char *field_name)
{
  register int index;

  for (index = 0;
       (index <= num_form_entries)
       && (strcmp (form_entries[index].name, field_name)); index++);
  if (index > num_form_entries)
    return NULL;
  return form_entries[index].val;
}

int
load_cmdln_entries ()
{
  register int index;
  char *cl;

  num_cmdln_entries = 0;
  cl = getenv ("QUERY_STRING");
  if (cl == NULL)
    {
      /* No query information to decode */
      return 0;
    }
  for (index = 0; cl[0] != '\0'; index++)
    {
      num_cmdln_entries = index;
      getword (cmdln_entries[index].val, cl, '&');
      plustospace (cmdln_entries[index].val);
      unescape_url (cmdln_entries[index].val);
      getword (cmdln_entries[index].name, cmdln_entries[index].val, '=');
    }
  return num_cmdln_entries;
}

char *
retrieve_cmdln_entry (char *field_name)
{
  register int index;

  for (index = 0;
       (index <= num_cmdln_entries)
       && (strcmp (cmdln_entries[index].name, field_name)); index++);
  if (index > num_cmdln_entries)
    return NULL;
  return cmdln_entries[index].val;
}

char *
trim (char *trim_str)
{
  int index;

  for (index = strlen (trim_str) - 1; index >= 0; index--)
    if (trim_str[index] != ' ' && trim_str[index] != '\t'
	&& trim_str[index] != '\n')
      break;
  trim_str[index + 1] = '\0';
  return trim_str;
}
