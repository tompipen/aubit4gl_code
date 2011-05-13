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

#include <string.h>
#include "formsproc.h"

int
A4GL_load_form (int nargs)
{
  int num_ent;

  if (nargs != 0)
    {
      printf ("Content-type: text/html%c%c", 10, 10);
      printf ("ERROR: wrong number of arguments in load_form\n");
      exit (1);
    }
  num_ent = load_form_entries ();
  retint (num_ent);
  return (1);
}

int
free_form (int nargs)
{
  if (nargs != 0)
    {
      printf ("Content-type: text/html%c%c", 10, 10);
      printf ("ERROR: wrong number of arguments in free_form\n");
      exit (1);
    }
  free_form_entries ();
  return (0);
}

int
get_entry (int nargs)
{
  char field_name[ENTRY_SIZE];
  char *field_value;

  if (nargs != 1)
    {
      printf ("Content-type: text/html%c%c", 10, 10);
      printf ("ERROR: wrong number of arguments\n");
      exit (1);
    }

  /* Pop field_name */
  popquote (field_name, ENTRY_SIZE);
  A4GL_trim (field_name);

  field_value = retrieve_form_entry (field_name);

  /* Push field value */
  retquote (field_value);
  return (1);
}

int
load_cmdln (int nargs)
{
  int num_ent;

  if (nargs != 0)
    {
      printf ("Content-type: text/html%c%c", 10, 10);
      printf ("ERROR: wrong number of arguments\n");
      exit (1);
    }
  num_ent = load_cmdln_entries ();
  retint (num_ent);
  return (1);
}

int
get_cmdln (int nargs)
{
  char field_name[ENTRY_SIZE];
  char *field_value;

  if (nargs != 1)
    {
      printf ("Content-type: text/html%c%c", 10, 10);
      printf ("ERROR: wrong number of arguments\n");
      exit (1);
    }

  /* Pop field_name */
  popquote (field_name, ENTRY_SIZE);
  A4GL_trim (field_name);

  field_value = retrieve_cmdln_entry (field_name);

  /* Push field value */
  retquote (field_value);
  return (1);
}
