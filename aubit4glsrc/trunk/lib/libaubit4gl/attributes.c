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
# $Id: attributes.c,v 1.4 2003-05-12 14:24:02 mikeaubury Exp $
#*/

/**
 * @file
 * This should be a complete list of all possible attributes anything
 * can have - some are not applicable to certain areas.
 *
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_libaubit4gl_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/


/*
CONSTRUCT 
DISPLAY
DISPLAY ARRAY
DISPLAY FORM
INPUT
INPUT ARRAY
MESSAGE
PROMPT
*/
struct s_std_attr
{
  int color;

  int reverse;
  int underline;
  int bold;
  int dim;
  int invisible;

  int normal;
  int help_no;
};

/*
OPEN WINDOW 
*/

struct s_win_attr
{
  int color;

  int normal;
  int bold;
  int dim;
  int reverse;
  int border;

  int comment_line;
  int form_line;
  int menu_line;
  int message_line;
  int prompt_line;
};


/* 
OPTIONS INPUT ATTRIBUTE 
OPTIONS DISPLAY ATTRIBUTE 
*/
struct s_options_inpdisp_attr
{
  int color;
  int reverse;
  int underline;
  int blink;
  int bold;
  int dim;
  int invisible;
  int normal;
  int form;
  int window;
};

/* 
OPTIONS
*/
struct s_options_attr
{
  int comment_line;
  int error_line;
  int form_line;
  int menu_line;
  int message_line;
  int prompt_line;
  int accept_key;
  int delete_key;
  int insert_key;
  int next_key;
  int previous_key;
  int help_key;
  char *helpfile;
  struct s_options_inpdisp_attr *display_attribute;
  struct s_options_inpdisp_attr *input_attribute;
  int input_wrap;
  int field_order;
  int sql_interrupt;
};


struct s_field_attr
{
  int screen_records_subscript;
  struct colours *field_cols;
  int field_cols_len;
};



enum e_attribute_type
{
  ATTR_STD,
  ATTR_WIN,
  ATTR_OPTIONS_INPDISP,
  ATTR_OPTIONS,
  ATTR_FIELD,
  ATTR_STRING
};

struct s_all_attributes
{
  int attribute_type;
  union
  {
    struct s_std_attr;
    struct s_win_attr;
    struct s_options_inpdisp_attr;
    struct s_options_attr;
    struct s_field_attr;
    char *string_summary;
  }
  u_all;
};


/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
* Get a string representation of an attribute
*
* @param attr  Attribute to decode
* @param col_str Pointer to character string to store the colour
* @param col_str Pointer to character string to store the attributes
*/
void
get_strings_from_attr (int attr, char *col_str, char *attr_str)
{
  int col_int;

  strcpy (col_str, "WHITE");
  strcpy (attr_str, "");

  col_int = (attr & 0xf00);
  debug ("col_int=%x\n", col_int);
  /* Work out the colours first */
  switch (col_int)
    {
    case AUBIT_COLOR_BLACK:
      strcpy (col_str, "BLACK");
      break;
    case AUBIT_COLOR_RED:
      strcpy (col_str, "RED");
      break;
    case AUBIT_COLOR_GREEN:
      strcpy (col_str, "GREEN");
      break;
    case AUBIT_COLOR_YELLOW:
      strcpy (col_str, "YELLOW");
      break;
    case AUBIT_COLOR_BLUE:
      strcpy (col_str, "BLUE");
      break;
    case AUBIT_COLOR_MAGENTA:
      strcpy (col_str, "MAGENTA");
      break;
    case AUBIT_COLOR_CYAN:
      strcpy (col_str, "CYAN");
      break;
    case AUBIT_COLOR_WHITE:
      strcpy (col_str, "WHITE");
      break;
    }

  /* Now for the attributes */
  if (attr & AUBIT_ATTR_NORMAL)
    strcat (attr_str, "NORMAL ");
  if (attr & AUBIT_ATTR_REVERSE)
    strcat (attr_str, "REVERSE ");
  if (attr & AUBIT_ATTR_UNDERLINE)
    strcat (attr_str, "UNDERLINE ");
  if (attr & AUBIT_ATTR_BOLD)
    strcat (attr_str, "BOLD ");
  if (attr & AUBIT_ATTR_BLINK)
    strcat (attr_str, "BLINK ");
  if (attr & AUBIT_ATTR_DIM)
    strcat (attr_str, "DIM ");
  debug ("get_strings returning %s %s", col_str, attr_str);
}

/**
 *  Decode a string attribute into an Aubit internal attribute
 *
 *  @param s The string to decode - should contain a single colour or attribute
 *
 */
int
get_attr_from_string (char *s)
{
  if (strcasecmp (s, "BLACK") == 0)
    return AUBIT_COLOR_BLACK;
  if (strcasecmp (s, "RED") == 0)
    return AUBIT_COLOR_RED;
  if (strcasecmp (s, "GREEN") == 0)
    return AUBIT_COLOR_GREEN;
  if (strcasecmp (s, "YELLOW") == 0)
    return AUBIT_COLOR_YELLOW;
  if (strcasecmp (s, "BLUE") == 0)
    return AUBIT_COLOR_BLUE;
  if (strcasecmp (s, "MAGENTA") == 0)
    return AUBIT_COLOR_MAGENTA;
  if (strcasecmp (s, "CYAN") == 0)
    return AUBIT_COLOR_CYAN;
  if (strcasecmp (s, "WHITE") == 0)
    return AUBIT_COLOR_WHITE;

  if (strcasecmp (s, "NORMAL") == 0)
    return AUBIT_ATTR_NORMAL;
  if (strcasecmp (s, "REVERSE") == 0)
    return AUBIT_ATTR_REVERSE;
  if (strcasecmp (s, "UNDERLINE") == 0)
    return AUBIT_ATTR_UNDERLINE;
  if (strcasecmp (s, "BOLD") == 0)
    return AUBIT_ATTR_BOLD;
  if (strcasecmp (s, "BLINK") == 0)
    return AUBIT_ATTR_BLINK;
  if (strcasecmp (s, "DIM") == 0)
    return AUBIT_ATTR_DIM;
  printf ("Unknown attribute : %s\n", s);
  return -1;
}


/* =============================== EOF ================================== */
