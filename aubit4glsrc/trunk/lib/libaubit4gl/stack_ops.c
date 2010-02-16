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
# | contact licensing@aubit.com                                           |
# +----------------------------------------------------------------------+
#
# $Id: stack_ops.c,v 1.25 2010-02-16 13:16:42 mikeaubury Exp $
#
*/

#include "a4gl_libaubit4gl_int.h"

//void *A4GL_pop_binding (int *n);
//void A4GL_process_stack_op_other (int d);
//struct s_sid * A4GLSQL_prepare_select (struct BINDING *ibind, int ni, struct BINDING *obind, int no, char *s, int singleton);



void
A4GL_process_stack_op_other (int d)
{
  int d1;
  int s1;
  //int ptr1;
  long ptr1;
#ifdef DEBUG
  A4GL_debug ("A4GL_process_stack_op_other");
#endif
  if (d == OP_IN || d == OP_NOTIN)
    {
      int a;
      int ok = 0;
      int eql;
#ifdef DEBUG
      A4GL_debug ("OP_IN Set");
#endif
      a = A4GL_pop_int ();
#ifdef DEBUG
      A4GL_debug ("OP_IN Set checking against %d values", a);
#endif
      while (a >= 1)
	{
#ifdef DEBUG
	  A4GL_debug ("Getting base value from stack.. a=%d", a);
#endif
	  A4GL_get_top_of_stack (a + 1, &d1, &s1, (void *) &ptr1);
#ifdef DEBUG
	  A4GL_debug ("Got %p 0x%x %d\n", ptr1, d1, s1);
#endif
	  //A4GL_debug (" *ptr1=%d", *(int *) ptr1);
	  A4GL_push_param ((void *) ptr1, (d1 & DTYPE_MASK) + ENCODE_SIZE (s1));
	  A4GL_pushop (OP_EQUAL);
#ifdef DEBUG
	  A4GL_debug ("Pushed OP_EQUAL");
#endif
	  eql = A4GL_pop_long ();
	  if (A4GL_isnull (DTYPE_INT, (void *) &eql))
	    eql = 0;
	  if (eql)
	    ok = 1;
#ifdef DEBUG
	  A4GL_debug ("Got OP_EQUAL  = %d (%x) ok=%d\n", eql, eql, ok);
#endif

	  a--;
	}
#ifdef DEBUG
      A4GL_debug ("Setting ok=%d\n", ok);
#endif
      A4GL_drop_param ();	/* Get rid of the base... */
      if (d == OP_IN)
	A4GL_push_int (ok);
      else
	A4GL_push_int (!ok);
      return;
    }

  if (d == OP_IN_SELECT || d == OP_NOTIN_SELECT)
    {
      int a;
      int ok = 0;
      int eql;
      char *s;
      static int cntsql_0 = 0;
      char cname[256];
      char tmpvar[256];
      struct BINDING ibind[] = {
	{&tmpvar, 0, 255, 0, 0, 0}
      };			/* end of binding */
      SPRINTF1 (cname, "chkin_%d", cntsql_0++);
      memset (tmpvar, 0, 255);
      s = A4GL_char_pop ();
      A4GL_get_top_of_stack (1, &d1, &s1, (void *) &ptr1);
      A4GLSQL_set_sqlca_sqlcode (0);
      {
	int n;
	struct BINDING *ibind;
	struct BINDING obind[] = { {0, 0, 0, 0, 0, 0} };	/* end of binding */
	ibind = A4GL_pop_binding (&n);
#ifdef DEBUG
	A4GL_debug ("declare - binding : %d\n", n);
#endif
	A4GL_declare_cursor (0, A4GL_prepare_select (ibind, n, obind, 0, s, "__internal_stackops", 1, 0, 0), 0, cname);
      }
      if (a4gl_status != 0)
	{
	  A4GL_drop_param ();
	  A4GL_push_int (0);
	}
      free (s);
      A4GLSQL_set_sqlca_sqlcode (0);
      A4GL_open_cursor (cname, 0, 0);
      if (a4gl_status != 0)
	{
	  A4GL_drop_param ();
	  A4GL_push_int (0);
	}
      while (1)
	{
	  A4GL_fetch_cursor (cname, 2, 1, 1, ibind);
	  if (a4gl_status != 0)
	    break;
#ifdef DEBUG
	  A4GL_debug ("tmpvar=%s\n", tmpvar);
#endif
	  A4GL_push_param (tmpvar, 0);
	  A4GL_push_param ((void *) ptr1, (d1 & DTYPE_MASK) + ENCODE_SIZE (s1));
	  A4GL_pushop (OP_EQUAL);
	  eql = A4GL_pop_int ();
	  if (eql)
	    ok = 1;
	  a--;
	}
      A4GL_drop_param ();	/* Get rid of the base */
      if (d == OP_IN_SELECT)
	A4GL_push_int (ok);
      else
	A4GL_push_int (!ok);
      return;
    }

  if (d == OP_EXISTS || d == OP_NOTEXISTS)
    {
      int ok = 0;
      char *s;
      char tmpvar[256];
      static int cntsql_1 = 0;
      char cname[256];

      struct BINDING ibind[] = { {&tmpvar, 0, 255, 0, 0, 0} };	/* end of binding */
      struct BINDING obind[] = { {0, 0, 0, 0, 0, 0} };	/* end of binding */
      struct BINDING *dbind;
      void *prep;

      int n;

#ifdef DEBUG
      A4GL_debug ("OP_EXISTS - OP_NOTEXISTS...");
#endif
      SPRINTF1 (cname, "chkex%d", cntsql_1++);
#ifdef DEBUG
      A4GL_debug ("Popping binding...");
#endif

      dbind = A4GL_pop_binding (&n);
#ifdef DEBUG
      A4GL_debug ("poped dbind - Poping Sql");
#endif
      s = A4GL_char_pop ();
#ifdef DEBUG
      A4GL_debug ("s=%s\n", s);
#endif
      A4GLSQL_set_sqlca_sqlcode (0);
#ifdef DEBUG
      A4GL_debug ("Prepare seelct...");
#endif
      prep = A4GL_prepare_select (dbind, n, obind, 0, s, "__internal_stackops", 2, 0, 0);
#ifdef DEBUG
      A4GL_debug ("Declare");
#endif
      free (s);
      A4GL_declare_cursor (0, prep, 0, cname);

      if (a4gl_status != 0)
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GLSQL_set_sqlca_sqlcode (0);
      A4GL_open_cursor (cname, 0, 0);
#ifdef DEBUG
      A4GL_debug ("opened cursor");
#endif
      if (a4gl_status != 0)
	{
	  A4GL_push_int (0);
	  return;
	}
      A4GL_fetch_cursor (cname, 2, 1, 1, ibind);
#ifdef DEBUG
      A4GL_debug ("fetched");
#endif
      if (a4gl_status == 0)
	ok = 1;
      if (a4gl_status == 100)
	ok = 0;
      if (a4gl_status != 0 && a4gl_status != 100)
	{
#ifdef DEBUG
	  A4GL_debug ("Some error with the exists stuff.");
#endif
	  A4GL_push_int (0);
	  return;
	}
#ifdef DEBUG
      A4GL_debug ("ok=%d", ok);
#endif
      if (d == OP_EXISTS)
	A4GL_push_int (ok);
      else
	A4GL_push_int (!ok);
      return;
    }

}



struct BINDING *
bind_recopy (struct BINDING *b, int n, struct BINDING *c)
{
  static char *tmpcp = 0;
  if (n == 0 || c == 0)
    {
      free (b);
      return 0;
    }

  //
  // Make sure that if the source and destination overlap that we do no harm
  // by copying to a temp area first...
  //
  tmpcp = realloc (tmpcp, sizeof (struct BINDING) * n);
  memcpy (tmpcp, c, sizeof (struct BINDING) * n);

  b = realloc (b, sizeof (struct BINDING) * n);
  memcpy (b, tmpcp, sizeof (struct BINDING) * n);

  return b;
}
