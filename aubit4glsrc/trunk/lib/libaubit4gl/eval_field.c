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
# $Id: eval_field.c,v 1.2 2003-08-25 19:15:50 mikeaubury Exp $
#
*/


#include "a4gl_libaubit4gl_int.h"
#include "a4gl_API_ui.h"



int A4GL_evaluate_field_colour(char *field_contents, struct struct_scr_field *fprop);
static int evaluate_field_expr(char *s,u_expression *expr,long *value,int *is_char) ;
static long field_expr_is_true (char *s, struct u_expression *expr) ;









int A4GL_evaluate_field_colour(char *field_contents, struct struct_scr_field *fprop) {
int a;

A4GL_debug("CHECKING FOR A FIELD EXPRESSION MATCH");
if (fprop->colours.colours_len==0||field_contents==0) {
//A4GL_debug("CHECKING FOR A FIELD EXPRESSION MATCH : %d",fprop->colour);
	return -1;
	//return fprop->colour;
}

A4GL_debug("CHECKING FOR A FIELD EXPRESSION MATCH ...");
for (a=0;a<fprop->colours.colours_len;a++) {
	if (field_expr_is_true(field_contents,fprop->colours.colours_val[a].whereexpr)) {
		A4GL_debug("FOUND EXPRESSION MATCH !!! returning %d",fprop->colours.colours_val[a].colour);
		return fprop->colours.colours_val[a].colour;
	}
}

return -1;
//fprop->colour;
}






static long field_expr_is_true (char *s, struct u_expression *expr) {
  long a;
  int d;

  evaluate_field_expr(s,expr,&a,&d);
  if (a) return 1;
  return 0;
}






static int evaluate_field_expr(char *s,u_expression *expr,long *value,int *is_char) {


A4GL_debug("Evaludate field_expr - s=%s exprtype = %d",s,expr->itemtype);

  if (expr->itemtype == ITEMTYPE_INT)
    {
      	*value=expr->u_expression_u.intval;
	*is_char=0;
	return 1;
    }

  if (expr->itemtype == ITEMTYPE_SPECIAL)
    {
	*is_char=0;
	if (strcmp( expr->u_expression_u.special,"TRUE")==0) {
		*value=1;
		return 1;
	}
	if (strcmp( expr->u_expression_u.special,"FALSE")==0) {
		*value=0;
		return 1;
	}
	A4GL_exitwith("Unknown/non-handled special name in field colour where clause");
    }




  if (expr->itemtype == ITEMTYPE_LIST)
    {
	return 0;
    }


/*
   { LIST
      printf ("[");
      for (a = 0; a < expr->u_expression_u.list.list_len; a++)
        {
          dump_expr (expr->u_expression_u.list.list_val[a], lvl + 1);
        }
      printf ("]");
    }
*/




  if (expr->itemtype == ITEMTYPE_FIELD)
    {
	A4GL_debug("TYPE FIELD %s",s);
	*value=(long )s;
	*is_char=1;
	return 1;
    }

  if (expr->itemtype == ITEMTYPE_CHAR)
    {
	A4GL_debug("TYPE CHAR %s",expr->u_expression_u.charval);
	*value=(long)expr->u_expression_u.charval;
	*is_char=1;
	return 1;
    }

  if (expr->itemtype == ITEMTYPE_NOT)
    {
	long na;
	int nd;
	int ok;
	ok=evaluate_field_expr(s,expr->u_expression_u.notexpr,&na,&nd);
	if (!ok) return 0;
	if (na) *value=0;
	else *value=1;
	*is_char=0;

	return 1;
    }





  if (expr->itemtype == ITEMTYPE_COMPLEX)
    {
	u_expression *left;
  	t_complex_expr *ptr2;
	u_expression *right;
	long na1;
	long na2;
	int nd1;
	int nd2;
	int ok;
	int a;
	int compid=-1;
	int straightforward=0;


	struct s_op {
		char *type;
		int straightforward;
		int id;
	} ops[]={
		{"<",1,0},
		{">",1,1},
		{"!=",1,2},
		{"=",1,3},
		{"<=",1,4},
		{">=",1,5},
		{"MATCHES",1,6},
		{"LIKE",1,7},
	
		{"IN",1,	100},
		{"BETWEEN",1,	101},
		{"AND",1,	102},
		{"OR",1,	103},



		{0,0}
	 };


      	ptr2 = expr->u_expression_u.complex_expr;

	for (a=0;ops[a].type;a++) {
		if (strcasecmp(ops[a].type,ptr2->comparitor)==0) {
			compid=ops[a].id;
			straightforward=ops[a].straightforward;
			break;
		}
	}

	A4GL_debug("Comparison/Complex ID : %d (%s) ",compid,ptr2->comparitor);
	if (compid==0) {
		A4GL_exitwith("Unknown comparison %s");
		return 0;
	}



	left=ptr2->item1;
	right=ptr2->item2;


	if (straightforward) {
		ok=evaluate_field_expr(s,left,&na1,&nd1);
		if (ok==0) return 0;
		ok=evaluate_field_expr(s,right,&na2,&nd2);
		if (ok==0) return 0;

		if (nd1) { A4GL_push_char((char *)na1); } else { A4GL_push_long(na1); }
		if (nd2) { A4GL_push_char((char *)na2); } else { A4GL_push_long(na2); }


		if (compid==6) {
			A4GL_debug("MATCHES : XXXX '%s' matches '%s'",na1,na2);
		}
		switch(compid) {
			case 0: A4GL_pushop(OP_LESS_THAN); break;
			case 1: A4GL_pushop(OP_GREATER_THAN); break;
			case 2: A4GL_pushop(OP_NOT_EQUAL); break;
			case 3: A4GL_pushop(OP_EQUAL); break;
			case 4: A4GL_pushop(OP_LESS_THAN_EQ); break;
			case 5: A4GL_pushop(OP_GREATER_THAN_EQ); break;
			case 6: A4GL_push_char("\\"); A4GL_pushop(OP_MATCHES); break;
			case 7: A4GL_push_char("\\");A4GL_pushop(OP_LIKE); break;
			default: A4GL_exitwith("Internal error - unhandled field comparison"); return 0;
		}

		*value=A4GL_pop_bool();
		*is_char=0;
		return 1;
	}


	if (compid==102) {   // AND
		ok=evaluate_field_expr(s,left,&na1,&nd1);
		if (ok==0) return 0;
		ok=evaluate_field_expr(s,right,&na2,&nd2);
		if (ok==0) return 0;

		if (na1&&na2) *value=1;
		return *value=0;
		*is_char=0;
		return 1;
	}

	if (compid==103) {   // OR
		ok=evaluate_field_expr(s,left,&na1,&nd1);
		if (ok==0) return 0;
		ok=evaluate_field_expr(s,right,&na2,&nd2);
		if (ok==0) return 0;


		if (na1||na2) *value=1;
		return *value=0;
		*is_char=0;
		return 1;
	}


	A4GL_debug("Can't handle it yet - %s",ptr2->comparitor);
	return 0;
    }


A4GL_debug("Unknown expression type %d\n",expr->itemtype);
return 0;
}


/*
   { LIST
      printf ("[");
      for (a = 0; a < expr->u_expression_u.list.list_len; a++)
        {
          dump_expr (expr->u_expression_u.list.list_val[a], lvl + 1);
        }
      printf ("]");
    }
*/

