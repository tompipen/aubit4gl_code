
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
# $Id: gen_stack.c,v 1.6 2006-09-27 06:53:57 mikeaubury Exp $
#
*/

/**
 * @file
 * It looks like functions to help the parsing of a module (a x4gl one).
 * For that the name mod.c
 *
 * @todo Doxygen comments in all functions
 * @todo static in modular variables
 * @todo const in read only strings
 * @todo -Wmissig-prototypes
 * @todo -Wstrict-prototypes
 * @todo -Wall
 * @todo -pedantic
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#define GEN_STACK_HERE
#include "a4gl_libaubit4gl.h"
#include "a4gl_gen_stack.h"
#define FEATURE_USED            'X'

void A4GL_4glc_clr_gen(int stk_no) {
	int c;
		for (c=0;c<gen_stack_cnt[stk_no];c++) {
				if (gen_stack_ptr[stk_no][c]) {
						free(gen_stack_ptr[stk_no][c]);
						gen_stack_ptr[stk_no][c]=0;
				}
					
		}
	free(gen_stack_ptr[stk_no]);
	gen_stack_ptr[stk_no]=0;
	gen_stack_alloc[stk_no]=0;
	gen_stack_cnt[stk_no]=0;

}

int A4GL_4glc_gen_cnt(int a) {
		return gen_stack_cnt[a];
}

char *A4GL_4glc_get_gen(int a,int n) {
		return gen_stack_ptr[a][n];
}

void A4GL_init_gen_stack(void) {
	int c;
	for (c=0;c<GEN_STACKS;c++) {
			gen_stack_ptr[c]=0;
			gen_stack_cnt[c]=0;
			gen_stack_alloc[c]=0;
	}
}

/**
 *
 * @param a 
 * @param s
 */
void
A4GL_4glc_push_gen (int a, char *s)
{
  int c;
  A4GL_debug ("Push %d %s - %d\n", a, A4GL_null_as_null(s), gen_stack_cnt[a]);
  c=gen_stack_cnt[a];

  if (c>=gen_stack_alloc[a] || gen_stack_ptr[a]==0) { // Allocate some more space...
	  int d;
	  gen_stack_alloc[a]+=1024;
	  A4GL_debug("Allocating more space for generic stack %d (%d rows)",a,gen_stack_alloc[a]);
	  gen_stack_ptr[a]=realloc(gen_stack_ptr[a],gen_stack_alloc[a]*sizeof(char *));
	  for (d=gen_stack_cnt[a];d<gen_stack_alloc[a];d++) gen_stack_ptr[a][d]=0;
  }

  if (s==0) {
  	gen_stack_ptr[a][gen_stack_cnt[a]++]=0;
  } else {
  	gen_stack_ptr[a][gen_stack_cnt[a]++]=strdup(s);
  }
}




void
A4GL_4glc_copy_gen (int a, int b)
{
  int c;

  if (gen_stack_cnt[a] && gen_stack_ptr[a][gen_stack_cnt[a] - 1][0] == '(')
    {
      A4GL_4glc_pop_gen (a);
    }


  for (c = 0; c < gen_stack_cnt[b]; c++)
    {
      A4GL_4glc_push_gen (a, gen_stack_ptr[b][c]);
    }
  gen_stack_cnt[b] = 0;
}

char *
A4GL_4glc_pop_gen (int a)
{
  static char *last=0;
  if (last) free(last);
  gen_stack_cnt[a]--;
  last=strdup(gen_stack_ptr[a][gen_stack_cnt[a]]);
  free(gen_stack_ptr[a][gen_stack_cnt[a]]);
  return last;
}


/**
 *
 * @param a
 * @param s
 */
void
A4GL_4glc_pop_all_gen (int a, char *s)
{
  int z;
  for (z = 0; z < gen_stack_cnt[a]; z++)
    {
      if (z > 0) A4GL_debug ("%s ", A4GL_null_as_null(s));
      A4GL_debug ("%s", A4GL_null_as_null(gen_stack_ptr[a][z]));
    }
  A4GL_4glc_clr_gen(a);
  //gen_stack_cnt[a] = 0;
}

void
A4GL_4glc_dump_updvals (void)
{
  int a;
  PRINTF("UPDCOL=%d UPDVAL=%d UPDVAL2=%d\n",UPDCOL,UPDVAL,UPDVAL2);
  for (a = 0; a < gen_stack_cnt[UPDCOL]; a++)
    {
      PRINTF ("UPDCOL[%d] : %s\n", a, gen_stack_ptr[UPDCOL][a]);
    }

  for (a = 0; a < gen_stack_cnt[UPDVAL]; a++)
    {
      PRINTF ("UPDVAL[%d] : %s\n", a,gen_stack_ptr[UPDVAL][a]);
    }
  for (a = 0; a < gen_stack_cnt[UPDVAL2]; a++)
    {
      PRINTF ("UPDVAL2[%d]: %s\n", a,gen_stack_ptr[UPDVAL2][a]);
    }
}


/* ================================= EOF ============================= */
