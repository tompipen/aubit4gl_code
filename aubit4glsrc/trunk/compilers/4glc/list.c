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
# $Id: list.c,v 1.7 2002-05-25 12:12:44 afalout Exp $
#*/

/**
 * @file
 *
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h> //exit()

#include <a4gl_4glc_4glc.h>
#include <a4gl_aubit_lib.h>

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

extern int yylineno;
struct list
{
  char list_id[64];
  int list_count;
  char list_values[512][64];
};


int list_cnt = 0;
struct list lists[256];

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Prompts for user to insert something from standard input.
 *
 * @todo Get rid of gets
 * @param s The string added at the end of the prompt
 */
char *
list_prompt (char *s)
{
  static char buff[256];
  printf ("Please enter %s:\n", s);
  fgets (buff,255,stdin);
  stripnl (buff);
  return buff;
}

/**
 * Makes prompt for the user insert something from standard input.
 * 
 * It receives until the user hit <RETURN> empty string.
 *
 * Insert the values received in a lists array.
 *
 * @param id
 * @param s The string to be added at the end of the prompt
 */
void 
list_prompt_many(char *id, char *s)
{
  char *buff;
  strcpy (lists[list_cnt].list_id, id);
  lists[list_cnt].list_count = 0;
  while (1)
    {
      buff = list_prompt (s);
      if (strlen (buff) == 0)
	break;
      strcpy (lists[list_cnt].list_values[lists[list_cnt].list_count], buff);
      lists[list_cnt].list_count++;
    }
  list_cnt++;
}

/**
 * It prompts for user input from stdin.
 *
 * The string typed is inserted in the lists array
 *
 * @param id
 * @param s The string to be added at the end of the prompt
 */
void 
list_prompt_single (char *id, char *s)
{
  char *buff;
  strcpy (lists[list_cnt].list_id, id);
  lists[list_cnt].list_count = 0;
  buff = list_prompt (s);
  strcpy (lists[list_cnt].list_values[lists[list_cnt].list_count], buff);
  lists[list_cnt].list_count++;
  list_cnt++;
}


/**
 *
 * @todo Describe function
 */
void
list_set_single (char *id, char *s)
{
//  char *buff;
  strcpy (lists[list_cnt].list_id, id);
  lists[list_cnt].list_count = 0;
  strcpy (lists[list_cnt].list_values[lists[list_cnt].list_count], s);
  lists[list_cnt].list_count++;
  list_cnt++;
}

/**
 *
 * @todo Describe function
 */
static int
list_find_id (char *id)
{
  int a;
  char buff[256];

  for (a = 0; a < list_cnt; a++)
    {
      if (strcmp (lists[a].list_id, id) == 0)
	{
	  return a;
	}
    }

  sprintf (buff, "ID %s is unknown to the template", id);
  yyerror (buff);
  exit (0);
}

/**
 *
 * @todo Describe function
 */
/*
static void
list_prepend (char *id, char *id2, char *str)
{
  int a;
  int orig_id;
  int pid;
  pid = list_find_id (str);
  str = lists[pid].list_values[0];
  orig_id = list_find_id (id);
  strcpy (lists[list_cnt].list_id, id2);
  lists[list_cnt].list_count = lists[orig_id].list_count;
  for (a = 0; a < lists[orig_id].list_count; a++)
    {
      strcpy (lists[list_cnt].list_values[a], str);
      strcat (lists[list_cnt].list_values[a], lists[orig_id].list_values[a]);
    }
  list_cnt++;
}
*/

/**
 *
 * @todo Describe function
 */
void
list_append (char *id, char *id2, char *str)
{
  int a;
  int orig_id;
  int pid;
  pid = list_find_id (str);
  str = lists[pid].list_values[0];
  orig_id = list_find_id (id);
  strcpy (lists[list_cnt].list_id, id2);
  lists[list_cnt].list_count = lists[orig_id].list_count;
  for (a = 0; a < lists[orig_id].list_count; a++)
    {
      strcpy (lists[list_cnt].list_values[a], lists[orig_id].list_values[a]);
      strcat (lists[list_cnt].list_values[a], str);
    }
  list_cnt++;
}

/**
 *
 * @todo Describe function
 */
void 
list_copy (char *id, char *id2)
{
  int a;
  int orig_id;
  orig_id = list_find_id (id);
  strcpy (lists[list_cnt].list_id, id2);
  lists[list_cnt].list_count = lists[orig_id].list_count;
  for (a = 0; a < lists[orig_id].list_count; a++)
    {
      strcpy (lists[list_cnt].list_values[a], lists[orig_id].list_values[a]);
    }
  list_cnt++;

}

/**
 *
 * @todo Describe function
 */
/*
static void
list_use (char *id1, char *id2, char *str, char *idnew)
{
  int iid1;
  int iid2;
  int iid3;
  int a;
  char buff[256];
  iid1 = list_find_id (id1);
  iid2 = list_find_id (id2);
  iid3 = list_find_id (str);
  str = lists[iid3].list_values[0];
  if (lists[iid1].list_count != lists[iid2].list_count)
    {
      yyerror ("List are different length....\n");
      exit (0);
    }
  strcpy (lists[list_cnt].list_id, idnew);
  lists[list_cnt].list_count = lists[iid1].list_count;

  for (a = 0; a < lists[iid1].list_count; a++)
    {
      sprintf (buff, "%s%s%s", lists[iid1].list_values[a], str,
	       lists[iid2].list_values[a]);
      strcpy (lists[list_cnt].list_values[a], buff);
    }
  list_cnt++;
}
*/

/**
 *
 * @todo Describe function
 */
/*
static void
list_gen (char *id, char *newid, char *sep)
{
  char buff[256];
  int a;
  int orig_id;
  int ppid;
  orig_id = list_find_id (id);
  ppid = list_find_id (sep);
  sep = lists[ppid].list_values[0];
  strcpy (lists[list_cnt].list_id, newid);
  lists[list_cnt].list_count = 1;
  strcpy (buff, "");
  strcpy (lists[list_cnt].list_values[0], "");
  for (a = 0; a < lists[orig_id].list_count; a++)
    {
      if (a > 0)
	strcat (lists[list_cnt].list_values[0], sep);
      strcat (lists[list_cnt].list_values[0], lists[orig_id].list_values[a]);
    }
  list_cnt++;

}
*/

/**
 *
 * @todo Describe function
 */
void 
list_print_all(void)
{
  int id;
  int a;
  for (id = 0; id < list_cnt; id++)
    {
      printf (" List '%s' - %d has %d elements\n", lists[id].list_id, id,
	      lists[id].list_count);
      for (a = 0; a < lists[id].list_count; a++)
	{
	  printf ("    %s\n", lists[id].list_values[a]);
	}
      printf ("---------------------------------\n");
    }
}


/**
 *
 * @todo Describe function
 */
/*
static void
list_print (char *cid)
{
  int id;
  int a;
  id = list_find_id (cid);
  for (a = 0; a < lists[id].list_count; a++)
    {
      if (a > 0)
	printf (" ");
      printf ("%s", lists[id].list_values[a]);
    }
}
*/

/**
 *
 * @todo Describe function
 */
char *
new_id (void)
{
  static char buff[256];
  sprintf (buff, "_list_%d", list_cnt);
  return buff;
}

/**
 *
 * @todo Describe function
 */
void 
list_columns (char *id, char *s)
{
  list_set_single (id, s);
}


/**
 *
 * @todo Describe function
 */
void 
list_set_plus (char *newid, char *cid1, char *cid2)
{
  int id1, id2;
  int a, b;
  int found;
  int c = 0;
  id1 = list_find_id (cid1);
  id2 = list_find_id (cid2);
  list_copy (cid1, newid);
  list_cnt--;
  strcpy (lists[list_cnt].list_id, newid);
  c = lists[list_cnt].list_count;

  for (a = 0; a < lists[id2].list_count; a++)
    {
      found = 0;
      for (b = 0; b < lists[list_cnt].list_count; b++)
	{
	  if (strcmp
	      (lists[id2].list_values[a],
	       lists[list_cnt].list_values[b]) == 0) found = 1;
	}
      if (found == 1)
	continue;
      strcpy (lists[list_cnt].list_values[c], lists[id2].list_values[a]);
      c++;
    }
  lists[list_cnt].list_count = c;
  list_cnt++;
}


/**
 *
 * @todo Describe function
 */
void 
list_set_minus (char *newid, char *cid1, char *cid2)
{
  int id1, id2;
  int a, b;
  int found;
  int c = 0;
  id1 = list_find_id (cid1);
  id2 = list_find_id (cid2);
  strcpy (lists[list_cnt].list_id, newid);
  lists[list_cnt].list_count = 0;

  for (a = 0; a < lists[id1].list_count; a++)
    {
      found = 0;
      for (b = 0; b < lists[id2].list_count; b++)
	{
	  if (strcmp (lists[id1].list_values[a], lists[id2].list_values[b]) ==
	      0) found = 1;
	}
      if (found == 1)
	continue;
      strcpy (lists[list_cnt].list_values[c], lists[id1].list_values[a]);
      c++;
    }
  lists[list_cnt].list_count = c;
  list_cnt++;
}


/**
 *
 * @todo Describe function
 */

void
list_in(void)
{
};


// =============================== EOF ============================
