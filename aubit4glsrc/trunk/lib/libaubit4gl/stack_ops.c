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
# $Id: stack_ops.c,v 1.2 2003-03-02 14:06:58 mikeaubury Exp $
#
*/

#include "a4gl_libaubit4gl_int.h"

void *pop_binding (int *n);
void process_stack_op_other(int d);



void process_stack_op_other(int d) {
  int d1;
  int s1;
  int ptr1;

  if (d == OP_IN || d == OP_NOTIN)
    {
      int a;
      int ok = 0;
      int eql;
      debug ("MJA OP_IN Set");
      a = pop_int ();
      while (a >= 1)
	{
	  debug ("MJA Getting base value from stack.. a=%d", a);
	  get_top_of_stack (a + 1, &d1, &s1, (void **) &ptr1);
	  debug ("MJA Got %p 0x%x %d\n", ptr1, d1, s1);
	  debug (" MJA *ptr1=%d", *(int *) ptr1);
	  push_param ((void *) ptr1, (d1 & DTYPE_MASK) + ENCODE_SIZE (s1));
	  pushop (OP_EQUAL);
	  debug ("MJA Pushed OP_EQUAL");
	  eql = pop_int ();
	  debug ("MJA Got OP_EQUAL  = %d\n", eql);
	  if (eql)
	    ok = 1;
	  a--;
	}
      debug ("MJA Setting ok=%d\n", ok);
      drop_param ();		/* Get rid of the base... */
      if (d == OP_IN)
	push_int (ok);
      else
	push_int (!ok);
      return;
    }

  if (d == OP_IN_SELECT || d == OP_NOTIN_SELECT)
    {
      int a;
      int ok = 0;
      int eql;
      char *s;
      static int cntsql = 0;
      char cname[256];
      char tmpvar[256];
      struct BINDING ibind[] = {
	{&tmpvar, 0, 255}
      };			/* end of binding */
      sprintf (cname, "chkin_%d", cntsql++);

      s = char_pop ();
      get_top_of_stack (1, &d1, &s1, (void **) &ptr1);
      A4GLSQL_set_sqlca_sqlcode (0);
      {
	int n;
	struct BINDING *ibind;
	struct BINDING obind[] = { {0, 0, 0} };	/* end of binding */
	ibind = pop_binding (&n);
	A4GLSQL_declare_cursor (0,
				A4GLSQL_prepare_select (ibind, n, obind, 0,
							s), 0, cname);
      }
      if (status != 0)
	{
	  drop_param ();
	  push_int (0);
	}
	free(s);
      A4GLSQL_set_sqlca_sqlcode (0);
      A4GLSQL_open_cursor (0, cname);
      if (status != 0)
	{
	  drop_param ();
	  push_int (0);
	}
      while (1)
	{
	  A4GLSQL_fetch_cursor (cname, 2, 1, 1, ibind);
	  if (status != 0)
	    break;
	  debug ("MJA tmpvar=%s\n", tmpvar);
	  push_param (tmpvar, 0);
	  push_param ((void *) ptr1, (d1 & DTYPE_MASK) + ENCODE_SIZE (s1));
	  pushop (OP_EQUAL);
	  eql = pop_int ();
	  if (eql)
	    ok = 1;
	  a--;
	}
      drop_param ();		/* Get rid of the base */
      if (d == OP_IN_SELECT)
	push_int (ok);
      else
	push_int (!ok);
      return;
    }

  if (d == OP_EXISTS || d == OP_NOTEXISTS)
    {
      int ok = 0;
      char *s;
      char tmpvar[256];
      static int cntsql = 0;
      char cname[256];

      struct BINDING ibind[] = { {&tmpvar, 0, 255} };	/* end of binding */
      struct BINDING obind[] = { {0, 0, 0} };			/* end of binding */
      struct BINDING *dbind;
      void *prep;

      int n;

      debug("OP_EXISTS - OP_NOTEXISTS...");
      sprintf (cname, "chkex%d", cntsql++);
	debug("Popping binding...");

      dbind = pop_binding (&n);
      debug("poped dbind - Poping Sql");
      s = char_pop ();
      debug ("s=%s\n", s);
      A4GLSQL_set_sqlca_sqlcode (0);
      debug("Prepare seelct...");
      prep=A4GLSQL_prepare_select (dbind, n, obind, 0, s);
      debug("Declare");
	free(s);
      A4GLSQL_declare_cursor (0,  prep , 0, cname);

      if (status != 0)
	{
	  push_int (0);
	  return;
	}
      A4GLSQL_set_sqlca_sqlcode (0);
      A4GLSQL_open_cursor (0, cname);
      debug ("opened cursor");
      if (status != 0)
	{
	  push_int (0);
	  return;
	}
      A4GLSQL_fetch_cursor (cname, 2, 1, 1, ibind);
      debug ("fetched");
      if (status == 0)
	ok = 1;
      if (status == 100)
	ok = 0;
      if (status != 0 && status != 100)
	{
	  debug ("Some error with the exists stuff.");
	  push_int (0);
	  return;
	}
      debug ("ok=%d", ok);
      if (d == OP_EXISTS)
	push_int (ok);
      else
	push_int (!ok);
      return;
    }

}

