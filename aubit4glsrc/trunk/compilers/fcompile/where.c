/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-2005 Aubit Development Team (See Credits file)    |
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
# $Id: where.c,v 1.17 2007-11-20 14:08:42 mikeaubury Exp $
#
*/

/**
 * @file
 * Functions called by the compiler to set up 'where' clauses
 *
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/


#include "a4gl_fcompile_int.h"

#include <ctype.h>

/*
=====================================================================
                    Variables definitions
=====================================================================
*/


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


void print_lvl (int lvl);
void dump_expr (t_expression * expr, int lvl);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/***********************/
/* Create simple types */
/***********************/

/**
 *
 * @todo Describe function
 */
t_expression *
create_field_expr (char *fieldname)
{
  t_expression *ptr;
  ptr = acl_malloc2 (sizeof (t_expression));
  ptr->itemtype = ITEMTYPE_FIELD;
  ptr->u_expression_u.field = acl_strdup (fieldname);
  return ptr;
}

/**
 *
 * @todo Describe function
 */
t_expression *
create_int_expr (long intval)
{
  t_expression *ptr;
  ptr = acl_malloc2 (sizeof (t_expression));
  ptr->itemtype = ITEMTYPE_INT;
  ptr->u_expression_u.intval = intval;
  return ptr;
}

/**
 *
 * @todo Describe function
 */
t_expression *
create_char_expr (char *charval)
{
  t_expression *ptr;
  ptr = acl_malloc2 (sizeof (t_expression));
  ptr->itemtype = ITEMTYPE_CHAR;

  ptr->u_expression_u.charval = acl_strdup(&charval[1]);
  ptr->u_expression_u.charval[strlen(ptr->u_expression_u.charval)-1]=0;
  return ptr;
}


/* charval will contain :

	USER
	TODAY
	TRUE
	FALSE
etc.
*/
/**
 *
 * @todo Describe function
 */
t_expression *
create_special_expr (char *charval)
{
  t_expression *ptr;
  int a;
  charval=acl_strdup(charval);
  for (a = 0; a < strlen (charval); a++)
    charval[a] = toupper (charval[a]);
  ptr = acl_malloc2 (sizeof (t_expression));
  ptr->itemtype = ITEMTYPE_SPECIAL;
  ptr->u_expression_u.special = charval;
  return ptr;
}


/**
 *
 * @todo Describe function
 */
t_expression *
create_not_expr (t_expression * expr)
{
  t_expression *ptr;
  ptr = acl_malloc2 (sizeof (t_expression));
  ptr->itemtype = ITEMTYPE_NOT;
  ptr->u_expression_u.notexpr = expr;
  return ptr;
}

/**
 *
 * @todo Describe function
 */
t_expression *
create_list_expr (void)
{
  t_expression *ptr;
  ptr = acl_malloc2 (sizeof (t_expression));
  ptr->itemtype = ITEMTYPE_LIST;
  ptr->u_expression_u.listy.listy_len=0;
  ptr->u_expression_u.listy.listy_val=0;
  return ptr;
}

/**
 *
 * @todo Describe function
 */
t_expression *
add_list_expr (t_expression * ptr, t_expression * expr)
{
  int a;
  if (ptr->itemtype != ITEMTYPE_LIST)
    {
      printf ("Internal error - adding a listitem to a non-list\n");
      exit (2);
    }
  ptr->u_expression_u.listy.listy_len++;
  a = ptr->u_expression_u.listy.listy_len;

  ptr->u_expression_u.listy.listy_val = realloc (ptr->u_expression_u.listy.listy_val, sizeof (struct listitemlist) * a);

  ptr->u_expression_u.listy.listy_val[a - 1].listx = expr;
  return ptr;
}



/**
 *
 * @todo Describe function
 */
t_expression *
create_expr_expr (t_complex_expr * expr)
{
  t_expression *ptr;
  ptr = acl_malloc2 (sizeof (t_expression));
  ptr->itemtype = ITEMTYPE_COMPLEX;
  ptr->u_expression_u.complex_expr = expr;
  return ptr;
}

/**
 *
 * @todo Describe function
 */
t_expression *
create_expr_comp_expr (t_expression * expr1, t_expression * expr2, char *comp)
{
  t_expression *ptr;
  t_complex_expr *ptr2;
  ptr = acl_malloc2 (sizeof (t_expression));
  ptr2 = acl_malloc2 (sizeof (t_complex_expr));
  ptr->itemtype = ITEMTYPE_COMPLEX;
  ptr->u_expression_u.complex_expr = ptr2;
  ptr2->item1 = expr1;
  ptr2->item2 = expr2;
  ptr2->comparitor = acl_strdup (comp);
  return ptr;
}


/**
 *
 * @todo Describe function
 */
void
dump_expr (t_expression * expr, int lvl)
{
  t_complex_expr *ptr2;
  int a;

  if (expr->itemtype == ITEMTYPE_INT)
    {
      print_lvl (lvl);
      printf ("%%%d", expr->u_expression_u.intval);
    }

  if (expr->itemtype == ITEMTYPE_SPECIAL)
    {
      print_lvl (lvl);
      printf ("*%p", expr->u_expression_u.special);
    }

  if (expr->itemtype == ITEMTYPE_LIST)
    {
      print_lvl (lvl);
      printf ("[");
      for (a = 0; a < expr->u_expression_u.listy.listy_len; a++)
	{
	  dump_expr (expr->u_expression_u.listy.listy_val[a].listx, lvl + 1);
	}
      printf ("]");
    }

  if (expr->itemtype == ITEMTYPE_FIELD)
    {
      print_lvl (lvl);
      printf ("$%s", expr->u_expression_u.field);
    }

  if (expr->itemtype == ITEMTYPE_CHAR)
    {
      print_lvl (lvl);
      printf ("'%s'", expr->u_expression_u.charval);
    }

  if (expr->itemtype == ITEMTYPE_NOT)
    {
      printf ("!(");
      dump_expr (expr->u_expression_u.notexpr, lvl + 1);
      printf (")");

    }

  if (expr->itemtype == ITEMTYPE_COMPLEX)
    {
      print_lvl (lvl);
      printf ("(");
      ptr2 = expr->u_expression_u.complex_expr;
      dump_expr (ptr2->item1, lvl + 1);
      print_lvl (lvl);
      printf (" %s ", ptr2->comparitor);
      dump_expr (ptr2->item2, lvl + 1);
      printf (")");

    }

  if (lvl == 0)
    printf ("\n");

}

/**
 *
 * @todo Describe function
 */
void
print_lvl (int lvl)
{
  int a;
  return;
  for (a = 0; a < lvl; a++)
    {
      printf ("   ");
    }
}


#ifdef TESTWHERE

/**
 *
 * @todo Describe function
 */
void
main (void)
{
  void *p[10];
  p[0] = create_field_expr ("bibble");
  p[1] = create_int_expr (10);
  p[2] = create_expr_comp_expr (p[0], p[1], ">=");
  p[3] = create_field_expr ("bibble");
  p[4] = create_int_expr (20);
  p[5] = create_expr_comp_expr (p[3], p[4], "<=");

  p[6] = create_expr_comp_expr (p[2], p[5], "AND");
  dump_expr (p[6], 0);
}
#endif


/* ============================== EOF ================================= */
