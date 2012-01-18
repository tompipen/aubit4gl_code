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
# $Id: binding.c,v 1.82 2012-01-18 19:21:29 mikeaubury Exp $
*/

/**
 * @file
 * 
 * Please describe me here
 */


#include "a4gl_lib_lex_esqlc_int.h"

#include "compile_c.h"
#ifndef lint
	static char const module_id[] =
		"$Id: binding.c,v 1.82 2012-01-18 19:21:29 mikeaubury Exp $";
#endif

//extern int ibindcnt;
//extern int obindcnt;
//dll_import struct binding_comp *ibind; //[NUMBINDINGS];
//dll_import struct binding_comp *obind; //[NUMBINDINGS];

/* these two store the string for converting the data
 * back and forth from our temporary DECLARE SECTION variables
 * and the real deal.
 * We need the temporary variables because we may well store the
 * data differently from the target database (take datetime for example)
 * We also need to be able to handle the differences betwen vendors 
 * ESQL/C types...
 *
*/

#define ONE_NOT_ZERO(x) (x?x:1)

//void print_conversions_g (expr_str_list *bind);

//void make_sql_bind_g (expr_str_list *bind,char type);
//char * make_sql_bind_expr (char *sql, char *type);

static char *get_sql_type (int a, expr_str_list *bind,char type);
//void printc (char *fmt, ...);
//void printh (char *fmt, ...);
//int esql_type (void);
//void liblex_add_ibind(int dtype,char *var) ;
static char* get_sql_type_infx (int a, expr_str_list *bind,char bind_type);
static char *get_sql_type_postgres (int a, expr_str_list *bind,char bind_type);
static char *get_sql_type_sap (int a, expr_str_list *bind,char bind_type);
static char *get_sql_type_ingres (int a, expr_str_list *bind,char bind_type);
static char* get_sql_type_infoflex (int a, expr_str_list *bind,char bind_type);
static void find_non_char(char *s,char *head, char *tail) ;
//char * A4GL_dtype_sz (int d, int s);
//struct binding_comp *ensure_bind(long *a_bindp,long need, struct binding_comp *b) ;




static char *decode_decimal_size_as_string(int n) {
static char buff[256];
int n2;
int n3;


n2=n>>16;
if ((n2&0xff)==0xff) {  n2=n2>>8; SPRINTF1(buff,"%d",n2); return buff; }
n3=n2>>8;
if (n3>32) {
	printf("n=%x n2=%x\n",n,n2);
	printf("n3=%d  (%x) n2=%d(%x)\n",n3,n3,n2,n2);
	A4GL_assertion(1,"n3 > 32...");
}
SPRINTF2(buff,"%d,%d",n2>>8,n2&255);
return buff;
}



/* This function converts the SQL into*/
/* SQL INTO etc and converts the place holders back to variables...*/
/**/
/**/
/**/
char *
make_sql_bind_g (expr_str_list *bind,char bind_type)
{
  char buff_small[256];
  int a;
char *rval=0;

      set_suppress_lines ("B1");
      printc ("\nEXEC SQL BEGIN DECLARE SECTION;\n");
      if (bind_type== 'i')
	{
	char buff_in[100000];
	  strcpy (buff_in, "");
	  if (bind->list.list_len)
	    {

	      if (!A4GLSQLCV_check_requirement ("USE_INDICATOR"))
		{
		  SPRINTF1 (buff_in, "A4GL_copy_native_bind('i',ibind,native_binding_i,0,%d);", bind->list.list_len);
		}
	      else
		{
		  SPRINTF1 (buff_in, "A4GL_copy_native_bind('i',ibind,native_binding_i,native_binding_i_ind,%d);", bind->list.list_len);
		}

	      for (a = 0; a < bind->list.list_len; a++)
		{
		  printc ("static %s", get_sql_type (a, bind,bind_type));
		}
	    }
		rval=strdup(buff_in);
	}

      if (bind_type=='o' || bind_type=='r') 
	{
	char buff_out[100000];
	  strcpy (buff_out, "");
	  if (bind->list.list_len)
	    {

	      strcpy (buff_out, "");
	      if (!A4GLSQLCV_check_requirement ("USE_INDICATOR"))
		{
		if (bind_type=='o') {
		  SPRINTF1 (buff_small, "A4GL_copy_native_bind('o',obind,native_binding_o,0,%d);", bind->list.list_len);
		} else {
		  SPRINTF1 (buff_small, "A4GL_copy_native_bind('o',obind_dup,native_binding_o,0,%d);", bind->list.list_len);
		}
		}
	      else
		{
		if (bind_type=='o') {
		  SPRINTF1 (buff_small, "A4GL_copy_native_bind('o',obind,native_binding_o,native_binding_o_ind,%d);", bind->list.list_len);
		} else {
		  SPRINTF1 (buff_small, "A4GL_copy_native_bind('o',obind_dup,native_binding_o,native_binding_o_ind,%d);", bind->list.list_len);
		}
		}
	      strcat (buff_out, buff_small);

	      for (a = 0; a < bind->list.list_len; a++)
		{
		int static_ok=1;
		char *s;
		s=get_sql_type (a, bind, 'o');

		//  ecpg has a problem with static varchars - so we'll not make those static
		if (strstr(s,"varchar") && esql_type()== E_DIALECT_POSTGRES) static_ok=0;

		if (static_ok) {
		  	printc ("static %s", get_sql_type (a, bind, 'o'));
		} else {
		  	printc ("%s", get_sql_type (a, bind, 'o'));
		}

		}
	    }
		rval=strdup(buff_out);
	}

      printc ("\nEXEC SQL END DECLARE SECTION;\n");
      clr_suppress_lines ();


      set_suppress_lines ("B2");
      if (bind_type=='i')
	{

	  char comma = ' ';
	  printc ("static struct BINDING native_binding_i[%d]={\n", ONE_NOT_ZERO (bind->list.list_len));
	  if (bind->list.list_len == 0)
	    {
	      printc ("{0,0,0,0,0,0}");
	    }
	  for (a = 0; a < bind->list.list_len; a++)
	    {
	      printc ("   %c{NULL,%d,%d,0,0,0}", comma,  get_binding_dtype(bind->list.list_val[a]) & 0xffff, get_binding_dtype(bind->list.list_val[a]) >> 16);
	      comma = ',';
	    }
	  printc ("};\n");
	  if (A4GLSQLCV_check_requirement ("USE_INDICATOR"))
	    {
	      char comma = ' ';
	      printc ("static struct BINDING native_binding_i_ind[%d]={\n", ONE_NOT_ZERO(bind->list.list_len));
	      if (bind->list.list_len == 0)
		{
		  printc ("{0,0,0,0,0,0}");
		}
	      for (a = 0; a < bind->list.list_len; a++)
		{
		  //printc (" %c{&_vii_%d,%d,%d,0,0,0}", comma, a, 2, 4);
		  printc (" %c{NULL,%d,%d,0,0,0}", comma,  2, 4);
		  comma = ',';
		}
	      printc ("};\n");
	    }
	}

      if (bind_type== 'o' || bind_type=='r')
	{
	  char comma = ' ';
	  printc ("static struct BINDING native_binding_o[%d]={\n",
		  ONE_NOT_ZERO (bind->list.list_len));
	  if (bind->list.list_len == 0)
	    {
	      printc ("{0,0,0,0,0,0}");
	    }
	  for (a = 0; a < bind->list.list_len; a++)
	    {
	      printc (" %c{NULL,%d,%d,0,0,0}", comma,  get_binding_dtype(bind->list.list_val[a]) & 0xffff, get_binding_dtype(bind->list.list_val[a]) >> 16);
	      comma = ',';
	    }
	  printc ("};\n");

	  if (A4GLSQLCV_check_requirement ("USE_INDICATOR"))
	    {
	      char comma = ' ';
	      printc ("static struct BINDING native_binding_o_ind[]={\n");
	      if (bind->list.list_len == 0)
		{
		  printc ("{0,0,0,0,0,0}");
		}
	      for (a = 0; a < bind->list.list_len; a++)
		{
		  //printc (" %c{&_voi_%d,%d,%d,0,0,0}", comma, a, 2, 4);
		  printc (" %c{NULL,%d,%d,0,0,0}", comma,  2, 4);
		  comma = ',';
		}
	      printc ("};\n");
	    }
	}
      set_suppress_lines ("B3");



	return rval;
}


/*
static char *addstr(char *p,int *n,char *new) {
int sz;
int isnew;
	if (p) {
		sz=strlen(p)+strlen(new)+2;
		isnew=0;
	} else {
		sz=strlen(new)+2;
		isnew=1;
	}

	if (sz>*n) {
		p=realloc(p,sz);
	}
	*n=sz;
	if (isnew) strcpy(p,new);
	else strcat(p,new);
return p;
}
*/




char *
get_sql_type (int a, expr_str_list *bind,char type)
{

  char *ptr;
char *p;

  ptr=A4GLSQLCV_get_esql_datatype(get_binding_dtype(bind->list.list_val[a]),type);
  if (ptr) {
	static char buff[200];
	char head[200];
	char tail[200];
	char buff_ind[200];
	find_non_char(ptr,head,tail);

  	if (type == 'i')
    	{
      		if (A4GLSQLCV_check_requirement("USE_INDICATOR")) { SPRINTF1(buff_ind," static short _vii_%d;",a); } else { strcpy(buff_ind,""); }
	  	SPRINTF3 (buff,"%s _vi_%d%s;",head,a,tail);
		strcat(buff,buff_ind);
		return buff;
    	}

	if (type=='o') {
 		if (A4GLSQLCV_check_requirement("USE_INDICATOR")) { SPRINTF1(buff_ind,"  static short _voi_%d;",a); } else { strcpy(buff_ind,""); }
	  	SPRINTF3 (buff,"%s _vo_%d%s;",head,a,tail);
		strcat(buff,buff_ind);
		return buff;
	}
  }

  /* Need to do some check to determine which ESQL/C to use...*/
  switch (esql_type()) {
	  case E_DIALECT_NONE:
		  	A4GL_assertion(1,"No ESQL/C Dialect");

	  case E_DIALECT_INFORMIX:
		p= get_sql_type_infx (a, bind,type);
		return p;

	  case E_DIALECT_POSTGRES:
  			return get_sql_type_postgres (a, bind,type);

	  case E_DIALECT_SAPDB:
  			return get_sql_type_sap (a, bind,type);

	  case E_DIALECT_INGRES:
  			return get_sql_type_ingres (a, bind,type);

	  case E_DIALECT_INFOFLEX:
  			return get_sql_type_infoflex (a, bind,type);
  }

return 0;
}



static void find_non_char(char *s,char *head, char *tail) {
char buff1[200];
char buff2[200];
char buff3[200];
int a;
strcpy(buff1,s);
strcpy(buff2,s);
strcpy(buff3,"");
for (a=0;a<strlen(buff1);a++) {
	
	if (buff1[a]>='a'&& buff1[a]<='z') continue;
	if (buff1[a]==' ') continue;
	if (buff1[a]=='_') continue;
	if (buff1[a]>='A'&& buff1[a]<='Z') continue;
	if (buff1[a]>='0'&& buff1[a]<='9') continue;
	buff2[a]=0;
	strcpy(buff3,&buff1[a]);
	break;
}
strcpy(head,buff2);
strcpy(tail,buff3);
}

static char *get_sql_type_infx (int a, expr_str_list *bind, char bind_type)
{
static char buff[255]="<<notset>>";
char buff_ind[255]="";

sprintf(buff,"<<notset:%x:%c>>",get_binding_dtype(bind->list.list_val[a]), bind_type);


  if (bind_type == 'i')
    {

      if (A4GLSQLCV_check_requirement("USE_INDICATOR")) { SPRINTF1(buff_ind," static short _vii_%d;",a); } else { strcpy(buff_ind,""); }

      switch (get_binding_dtype(bind->list.list_val[a]) & 0xffff)
	{
	case 0:
	  SPRINTF2 (buff,"char _vi_%d[%d+1];", a, get_binding_dtype(bind->list.list_val[a]) >> 16);
	  break;
	case 15:
	  SPRINTF2 (buff,"char _vi_%d[%d+1];", a, (get_binding_dtype(bind->list.list_val[a]) >> 16)*4);
	  break;

	case 16: // NVARCHAR
	  SPRINTF2 (buff,"varchar _vi_%d[%d+1];", a, (get_binding_dtype(bind->list.list_val[a]) >> 16)*4);
	  break;

	case 1:
	  SPRINTF1 (buff,"short _vi_%d;", a);
	  break;


	case 6:
	case 2:
	  if (sizeof(int)==sizeof(long)) {
	  	SPRINTF1 (buff,"int _vi_%d;", a);
	  } else {
	  	SPRINTF1 (buff,"long _vi_%d;", a);
	  }
	  break;

	case 7:
	  if (sizeof(int)==sizeof(long) || !(A4GL_isyes(acl_getenv("DATEASLONG")))) {
	  	SPRINTF1 (buff,"date _vi_%d;", a);
	  } else {
	  	SPRINTF1 (buff,"long _vi_%d;", a);
	  }
	  break;

	case 3:
	  SPRINTF1 (buff,"double _vi_%d;", a);
	  break;
	case 4:
	  SPRINTF1 (buff,"float _vi_%d;", a);
	  break;

	case 5:
	  SPRINTF2 (buff,"decimal(%s) _vi_%d;", decode_decimal_size_as_string(get_binding_dtype(bind->list.list_val[a])),a);
	  break;


	case 8:
	  SPRINTF2 (buff,"money(%s) _vi_%d;", decode_decimal_size_as_string(get_binding_dtype(bind->list.list_val[a])),a);
	  break;
	case 9:
	  SPRINTF1 (buff,"Blah _vi_%d;", a);
	  break;
	case 10:
	  SPRINTF2 (buff,"datetime %s _vi_%d;", A4GL_dtype_sz(DTYPE_DTIME,DECODE_SIZE(get_binding_dtype(bind->list.list_val[a]))),a);
	  break;
	case 11:
	  SPRINTF1 (buff,"byte _vi_%d;", a);
	  break;
	case 12:
	  SPRINTF1 (buff,"text _vi_%d;", a);
	  break;
	case 13:
	  SPRINTF2 (buff,"char _vi_%d[%d+1];", a, get_binding_dtype(bind->list.list_val[a]) >> 16);
	  break;
	case 14:
	  SPRINTF1 (buff,"interval _vi_%d;", a);
	  break;
	case DTYPE_INT8:
	  SPRINTF1 (buff,"int8 _vi_%d;", a);
	  break;
	}
	strcat(buff,buff_ind);
    }


  if (bind_type == 'o')
    {

 	if (A4GLSQLCV_check_requirement("USE_INDICATOR")) { SPRINTF1(buff_ind,"  static short _voi_%d;",a); } else { strcpy(buff_ind,""); }

      switch (get_binding_dtype(bind->list.list_val[a]) & 0xffff)
	{
	case 0:
	  SPRINTF2 (buff,"char _vo_%d[%d+1]=\"\";", a, get_binding_dtype(bind->list.list_val[a]) >> 16);
	  break;
	case 15:
	  SPRINTF2 (buff,"char _vo_%d[%d+1]=\"\";", a, (get_binding_dtype(bind->list.list_val[a]) >> 16)*4);
	  break;
	case 16: // NVARCHAR
	  SPRINTF2 (buff,"varchar _vo_%d[%d+1]=\"\";", a, (get_binding_dtype(bind->list.list_val[a]) >> 16)*4);
	  break;
	case 1:
	  SPRINTF1 (buff,"short _vo_%d=0;", a);
	  break;

	case 6:
	case 2:
	  if (sizeof(int)==sizeof(long)) {
	  	SPRINTF1 (buff,"int _vo_%d=0;", a);
	  } else {
	  	SPRINTF1 (buff,"long _vo_%d=0;", a);
	  }
	  break;

	case 3:
	  SPRINTF1 (buff,"double _vo_%d=0.0;", a);
	  break;
	case 4:
	  SPRINTF1 (buff,"float _vo_%d=0.0;", a);
	  break;
	case 5:
	  	SPRINTF2 (buff,"decimal(%s) _vo_%d;", decode_decimal_size_as_string(get_binding_dtype(bind->list.list_val[a])),a);
	  	break;
	case 7:
	  SPRINTF1 (buff,"date _vo_%d=0;", a);
	  break;
	case 8:
	  	SPRINTF2 (buff,"money(%s) _vo_%d;", decode_decimal_size_as_string(get_binding_dtype(bind->list.list_val[a])),a);
	  break;
	case 9:
	  SPRINTF1 (buff,"Blah _vo_%d;", a);
	  break;
	case 10:
	  SPRINTF2 (buff,"datetime %s _vo_%d;",  A4GL_dtype_sz(DTYPE_DTIME,DECODE_SIZE(get_binding_dtype(bind->list.list_val[a]))),a);
	  break;
	case 11:
	  SPRINTF1 (buff,"byte _vo_%d;", a);
	  break;
	case 12:
	  SPRINTF1 (buff,"text _vo_%d;", a);
	  break;
	case 13:
	  SPRINTF2 (buff,"varchar _vo_%d[%d+1]=\"\";", a , get_binding_dtype(bind->list.list_val[a]) >> 16 );
	  break;
	case 14:
	  SPRINTF1 (buff,"interval _vo_%d;", a);
	  break;
	case DTYPE_INT8:
	  SPRINTF1 (buff,"int8 _vo_%d;", a);
	  break;
	}
	strcat(buff,buff_ind);
    }

    return buff;
}



static char *get_sql_type_postgres (int a, expr_str_list *bind,char bind_type)
{
static char buff[255];
static char buff_ind[255];
  if (bind_type == 'i')
    {
      if (A4GLSQLCV_check_requirement("USE_INDICATOR")) { SPRINTF1(buff_ind,"static   short _vii_%d;",a); } else { strcpy(buff_ind,""); }
      switch (get_binding_dtype(bind->list.list_val[a]) & 0xffff)
	{
	case 0:
	  SPRINTF2 (buff,"char _vi_%d[%d+1];", a, get_binding_dtype(bind->list.list_val[a]) >> 16);
	  break;
	case 1:
	  SPRINTF1 (buff,"short _vi_%d;", a);
	  break;


	case 2:
	case 6:
	  if (sizeof(int)==sizeof(long)) {
	  	SPRINTF1 (buff,"int _vi_%d;", a);
	  } else {
	  	SPRINTF1 (buff,"long _vi_%d;", a);
	  }
	  //SPRINTF1 (buff,"int _vi_%d;", a);
	  break;


	case 3:
	  SPRINTF1 (buff,"double _vi_%d;", a);
	  break;
	case 4:
	  SPRINTF1 (buff,"float _vi_%d;", a);
	  break;

	case 5:
	  SPRINTF2 (buff,"decimal(%s) _vi_%d;", decode_decimal_size_as_string(get_binding_dtype(bind->list.list_val[a])),a);
	  break;


	case 7:
	  SPRINTF1 (buff,"date _vi_%d;", a);
	  break;
	case 8:
	  if (A4GLSQLCV_check_requirement("MONEY_AS_MONEY")) {
	  	SPRINTF1 (buff,"money _vi_%d;", a);
	  } else {
	  	if (A4GLSQLCV_check_requirement("MONEY_AS_DECIMAL")) {
	  		SPRINTF2 (buff,"decimal(%s) _vi_%d;", decode_decimal_size_as_string(get_binding_dtype(bind->list.list_val[a])), a);
		} else {
	  		SPRINTF2 (buff,"money(%s) _vi_%d;", decode_decimal_size_as_string(get_binding_dtype(bind->list.list_val[a])),a);
		}
	  }
	  break;
	case 9:
	  SPRINTF1 (buff,"Blah _vi_%d;", a);
	  break;
	case 10:
	  SPRINTF1 (buff,"datetime _vi_%d;",  a); /* Datetimes can't be qualified in ecpg*/
	  break;
	case 11:
	  SPRINTF1 (buff,"byte _vi_%d;", a);
	  break;
	case 12:
	  SPRINTF1 (buff,"text _vi_%d;", a);
	  break;
	case 13:
	  SPRINTF2 (buff,"char _vi_%d[%d+1];", a, get_binding_dtype(bind->list.list_val[a]) >> 16);
	  break;
	case 14:
	  SPRINTF1 (buff,"char _vi_%d[40];", a);
	  break;
	case DTYPE_INT8:
	  SPRINTF1 (buff,"int8 _vi_%d;", a);
	  break;
	default :
		a4gl_yyerror("Unknown sqltype"); break;
	}
	strcat(buff,buff_ind);
    }


  if (bind_type == 'o')
    {
 	if (A4GLSQLCV_check_requirement("USE_INDICATOR")) {
		SPRINTF1(buff_ind,"  short _voi_%d=0;",a);
	} else {
		strcpy(buff_ind,"");
	}

      switch (get_binding_dtype(bind->list.list_val[a]) & 0xffff)
	{
	case 0:
	  SPRINTF2 (buff,"char _vo_%d[%d+1]=\"\";", a, get_binding_dtype(bind->list.list_val[a]) >> 16);
	  break;
	case 1:
	  SPRINTF1 (buff,"short _vo_%d;", a);
	  break;

	case 2:
	case 6:
	  if (sizeof(int)==sizeof(long)) {
	  	SPRINTF1 (buff,"int _vo_%d=0;", a);
	  } else {
	  	SPRINTF1 (buff,"long _vo_%d=0;", a);
	  }
	  break;

	case 3:
	  SPRINTF1 (buff,"double _vo_%d;", a);
	  break;
	case 4:
	  SPRINTF1 (buff,"float _vo_%d;", a);
	  break;
	case 5:
	  	SPRINTF2 (buff,"decimal(%s) _vo_%d;", decode_decimal_size_as_string(get_binding_dtype(bind->list.list_val[a])),a);
	  break;
	case 7:
	  SPRINTF1 (buff,"date _vo_%d;", a);
	  break;
	case 8:
	  if (A4GLSQLCV_check_requirement("MONEY_AS_MONEY")) {
	  	SPRINTF1 (buff,"money _vo_%d;", a);
	  } else {
	  	if (A4GLSQLCV_check_requirement("MONEY_AS_DECIMAL")) {
	  		SPRINTF2 (buff,"decimal(%s) _vo_%d;", decode_decimal_size_as_string(get_binding_dtype(bind->list.list_val[a])), a);
		} else {
	  		SPRINTF2 (buff,"money(%s) _vo_%d;", decode_decimal_size_as_string(get_binding_dtype(bind->list.list_val[a])),a);
		}
	   }
	  	break;
	case 9:
	  SPRINTF1 (buff,"Blah _vo_%d;", a);
	  break;
	case 10:
	  SPRINTF1 (buff,"datetime _vo_%d;",  a); /* Datetimes can't be qualified in ecpg*/
	  break;
	case 11:
	  SPRINTF1 (buff,"byte _vo_%d;", a);
	  break;
	case 12:
	  SPRINTF1 (buff,"text _vo_%d;", a);
	  break;
	case 13:
	  SPRINTF2 (buff,"varchar _vo_%d[%d+1];", a , get_binding_dtype(bind->list.list_val[a]) >> 16);
	  break;
	case 14:
	  SPRINTF1 (buff,"char _vo_%d[40];", a);
	  break;

	case DTYPE_INT8:
	  SPRINTF1 (buff,"int8 _vo_%d;", a);
	  break;

 	default:
	  SPRINTF1 (buff,"Unknown _vo_%d;", a);
	  break;
		a4gl_yyerror("Unknown datatype");
		break;
	}
	strcat(buff,buff_ind);
    }
	return buff;

}


/*
void liblex_add_ibind(int dtype,char *var) {
	extern long a_ibind;
	ibind=ensure_bind(&a_ibind,ibindcnt+1,ibind);
	strcpy(ibind[ibindcnt].varname,var);
	ibind[ibindcnt].start_char_subscript=0;
	ibind[ibindcnt].end_char_subscript=0;
	ibind[ibindcnt].dtype=dtype;
	ibindcnt++;
}
*/

static char *get_sql_type_sap (int a, expr_str_list *bind,char bind_type)
{
static char buff[255];
static char buff_ind[255];
  if (bind_type == 'i')
    {
      if (A4GLSQLCV_check_requirement("USE_INDICATOR")) { SPRINTF1(buff_ind,"static   short _vii_%d;",a); } else { strcpy(buff_ind,""); }
      switch (get_binding_dtype(bind->list.list_val[a]) & 0xffff)
	{
	case 0:
	  SPRINTF2 (buff,"char _vi_%d[%d+1];", a, get_binding_dtype(bind->list.list_val[a]) >> 16);
	  break;
	case 1:
	  SPRINTF1 (buff,"short _vi_%d;", a);
	  break;
	case 2:
	  SPRINTF1 (buff,"int _vi_%d;", a);
	  break;
	case 3:
	  SPRINTF1 (buff,"double _vi_%d;", a);
	  break;
	case 4:
	  SPRINTF1 (buff,"float _vi_%d;", a);
	  break;

	case 5:
	  SPRINTF2 (buff,"decimal(%s) _vi_%d;", decode_decimal_size_as_string(get_binding_dtype(bind->list.list_val[a])),a);
	  break;

	case 6:
	  SPRINTF1 (buff,"int _vi_%d;", a);
	  break;

	case 7:
	  SPRINTF1 (buff,"date _vi_%d;", a);
	  break;
	case 8:
	  if (A4GLSQLCV_check_requirement("MONEY_AS_MONEY")) {
	  	SPRINTF1 (buff,"money _vi_%d;", a);
	  } else {
	  	if (A4GLSQLCV_check_requirement("MONEY_AS_DECIMAL")) {
	  		SPRINTF2 (buff,"decimal(%s) _vi_%d;", decode_decimal_size_as_string(get_binding_dtype(bind->list.list_val[a])), a);
		} else {
	  		SPRINTF2 (buff,"money(%s) _vi_%d;", decode_decimal_size_as_string(get_binding_dtype(bind->list.list_val[a])),a);
		}
	  }
	  break;
	case 9:
	  SPRINTF1 (buff,"Blah _vi_%d;", a);
	  break;
	case 10:
	  SPRINTF1 (buff,"datetime _vi_%d;",  a); /* Datetimes can't be qualified in ecpg*/
	  break;
	case 11:
	  SPRINTF1 (buff,"byte _vi_%d;", a);
	  break;
	case 12:
	  SPRINTF1 (buff,"text _vi_%d;", a);
	  break;
	case 13:
	  SPRINTF2 (buff,"char _vi_%d[%d+1];", a, get_binding_dtype(bind->list.list_val[a]) >> 16);
	  break;
	case 14:
	  SPRINTF1 (buff,"interval _vi_%d;", a);
	  break;
	case DTYPE_INT8:
	  SPRINTF1 (buff,"int8 _vi_%d;", a);
	  break;
	}
	strcat(buff,buff_ind);
    }


  if (bind_type == 'o')
    {
 	if (A4GLSQLCV_check_requirement("USE_INDICATOR")) {
		SPRINTF1(buff_ind,"  short _voi_%d=0;",a);
	} else {
		strcpy(buff_ind,"");
	}

      switch (get_binding_dtype(bind->list.list_val[a]) & 0xffff)
	{
	case 0:
	  SPRINTF2 (buff,"char _vo_%d[%d+1]=\"\";", a, get_binding_dtype(bind->list.list_val[a]) >> 16);
	  break;
	case 1:
	  SPRINTF1 (buff,"short _vo_%d;", a);
	  break;
	case 2:
	  SPRINTF1 (buff,"int _vo_%d;", a);
	  break;
	case 3:
	  SPRINTF1 (buff,"double _vo_%d;", a);
	  break;
	case 4:
	  SPRINTF1 (buff,"float _vo_%d;", a);
	  break;
	case 5:
	  	SPRINTF2 (buff,"decimal(%s) _vo_%d;", decode_decimal_size_as_string(get_binding_dtype(bind->list.list_val[a])),a);
	  break;
	case 6:
	  SPRINTF1 (buff,"int _vo_%d;", a);
	  break;
	case 7:
	  SPRINTF1 (buff,"date _vo_%d;", a);
	  break;
	case 8:
	  if (A4GLSQLCV_check_requirement("MONEY_AS_MONEY")) {
	  	SPRINTF1 (buff,"money _vo_%d;", a);
	  } else {
	  	if (A4GLSQLCV_check_requirement("MONEY_AS_DECIMAL")) {
	  		SPRINTF2 (buff,"decimal(%s) _vo_%d;", decode_decimal_size_as_string(get_binding_dtype(bind->list.list_val[a])), a);
		} else {
	  		SPRINTF2 (buff,"money(%s) _vo_%d;", decode_decimal_size_as_string(get_binding_dtype(bind->list.list_val[a])),a);
		}
	   }
	  	break;
	case 9:
	  SPRINTF1 (buff,"Blah _vo_%d;", a);
	  break;
	case 10:
	  SPRINTF1 (buff,"datetime _vo_%d;",  a); /* Datetimes can't be qualified in ecpg*/
	  break;
	case 11:
	  SPRINTF1 (buff,"byte _vo_%d;", a);
	  break;
	case 12:
	  SPRINTF1 (buff,"text _vo_%d;", a);
	  break;
	case 13:
	  SPRINTF1 (buff,"varchar _vo_%d=\"\";", a /*, obind[a].dtype >> 16 */);
	  break;
	case 14:
	  SPRINTF1 (buff,"interval _vo_%d;", a);
	  break;
	case DTYPE_INT8:
	  SPRINTF1 (buff,"int8 _vo_%d;", a);
	  break;
	}
	strcat(buff,buff_ind);
    }
	return buff;

}











static char *get_sql_type_ingres (int a, expr_str_list *bind,char bind_type)
{
static char buff[255];
static char buff_ind[255];
  if (bind_type == 'i')
    {
      if (A4GLSQLCV_check_requirement("USE_INDICATOR")) { SPRINTF1(buff_ind," static  short _vii_%d;",a); } else { strcpy(buff_ind,""); }
      switch (get_binding_dtype(bind->list.list_val[a]) & 0xffff)
	{
	case 0:
	  SPRINTF2 (buff,"char _vi_%d[%d+1];", a, get_binding_dtype(bind->list.list_val[a]) >> 16);
	  break;
	case 1:
	  SPRINTF1 (buff,"short _vi_%d;", a);
	  break;
	case 2:
	  SPRINTF1 (buff,"int _vi_%d;", a);
	  break;
	case 3:
	  SPRINTF1 (buff,"double _vi_%d;", a);
	  break;
	case 4:
	  SPRINTF1 (buff,"float _vi_%d;", a);
	  break;

	case 5:
	  SPRINTF1 (buff,"double _vi_%d;", a); // Ingres has no decimal
	  break;

	case 6:
	  SPRINTF1 (buff,"int _vi_%d;", a);
	  break;

	case 7:
	  SPRINTF1 (buff,"char _vi_%d[26];", a); // Date
	  break;
	case 8:
	  SPRINTF1 (buff,"double _vi_%d;", a); // Ingres has no money
	  break;
	case 9:
	  SPRINTF1 (buff,"Blah _vi_%d;", a);
	  break;
	case 10:
	  SPRINTF1 (buff,"char _vi_%d[30];",  a); /* Datetimes can't be qualified in ecpg*/
	  break;
	case 11:
	  SPRINTF1 (buff,"byte varying _vi_%d;", a);
	  break;
	case 12:
	  SPRINTF1 (buff,"text _vi_%d;", a);
	  break;
	case 13:
	  SPRINTF2 (buff,"char _vi_%d[%d+1];", a, get_binding_dtype(bind->list.list_val[a]) >> 16);
	  break;
	case 14:
	  SPRINTF1 (buff,"char _vi_%d[30];", a);
	  break;
	case DTYPE_INT8:
	  SPRINTF1 (buff,"int8 _vi_%d;", a);
	  break;
	}
	strcat(buff,buff_ind);
    }


  if (bind_type == 'o')
    {
 	if (A4GLSQLCV_check_requirement("USE_INDICATOR")) {
		SPRINTF1(buff_ind,"  short _voi_%d=0;",a);
	} else {
		strcpy(buff_ind,"");
	}

      switch (get_binding_dtype(bind->list.list_val[a]) & 0xffff)
	{
	case 0:
	  SPRINTF2 (buff,"char _vo_%d[%d+1]=\"\";", a, get_binding_dtype(bind->list.list_val[a]) >> 16);
	  break;
	case 1:
	  SPRINTF1 (buff,"short _vo_%d;", a);
	  break;
	case 2:
	  SPRINTF1 (buff,"int _vo_%d;", a);
	  break;
	case 3:
	  SPRINTF1 (buff,"double _vo_%d;", a);
	  break;
	case 4:
	  SPRINTF1 (buff,"float _vo_%d;", a);
	  break;
	case 5:
	  SPRINTF1 (buff,"double _vo_%d;", a);
	  break;
	case 6:
	  SPRINTF1 (buff,"int _vo_%d;", a);
	  break;
	case 7:
	  SPRINTF1 (buff,"char _vo_%d[26]=\"\";", a);
	  break;
	case 8:
	  SPRINTF1 (buff,"double _vo_%d;", a);
	  	break;
	case 9:
	  SPRINTF1 (buff,"Blah _vo_%d;", a);
	  break;
	case 10:
	  SPRINTF1 (buff,"char _vo_%d[30]=\"\";",  a); 
	  break;
	case 11:
	  SPRINTF1 (buff,"byte varying _vo_%d;", a);
	  break;
	case 12:
	  SPRINTF1 (buff,"text _vo_%d;", a);
	  break;
	case 13:
	  SPRINTF1 (buff,"varchar _vo_%d=\"\";", a /*, obind[a].dtype >> 16 */);
	  break;
	case 14:
	  SPRINTF1 (buff,"char _vo_%d[30]=\"\";", a);
	  break;
	case DTYPE_INT8:
	  SPRINTF1 (buff,"int8 _vo_%d;", a);
	  break;
	}
	strcat(buff,buff_ind);
    }
	return buff;

}

static char *get_sql_type_infoflex (int a, expr_str_list *bind,char bind_type)
{
static char buff[255];
char buff_ind[255];

  if (bind_type == 'i')
    {

      if (A4GLSQLCV_check_requirement("USE_INDICATOR")) { SPRINTF1(buff_ind,"\n static  short _vii_%d;",a); } else { strcpy(buff_ind,""); }

      switch (get_binding_dtype(bind->list.list_val[a]) & 0xffff)
	{
	case 0:
	  SPRINTF2 (buff,"char _vi_%d[%d+1];", a, get_binding_dtype(bind->list.list_val[a]) >> 16);
	  break;
	case 1:
	  SPRINTF1 (buff,"short _vi_%d;", a);
	  break;
	case 2:
	  SPRINTF1 (buff,"int _vi_%d;", a);
	  break;
	case 3:
	  SPRINTF1 (buff,"double _vi_%d;", a);
	  break;
	case 4:
	  SPRINTF1 (buff,"float _vi_%d;", a);
	  break;

	case 5:
	  SPRINTF2 (buff,"decimal(%s) _vi_%d;", decode_decimal_size_as_string(get_binding_dtype(bind->list.list_val[a])),a);
	  break;

	case 6:
	  SPRINTF1 (buff,"int _vi_%d;", a);
	  break;

	case 7:
	  SPRINTF1 (buff,"date _vi_%d;", a);
	  break;
	case 8:
	  SPRINTF2 (buff,"money(%s) _vi_%d;", decode_decimal_size_as_string(get_binding_dtype(bind->list.list_val[a])),a);
	  break;
	case 9:
	  SPRINTF1 (buff,"Blah _vi_%d;", a);
	  break;
	case 10:
	  SPRINTF2 (buff,"datetime %s _vi_%d;", A4GL_dtype_sz(DTYPE_DTIME,DECODE_SIZE(get_binding_dtype(bind->list.list_val[a]))),a);
	  break;
	case 11:
	  SPRINTF1 (buff,"byte _vi_%d;", a);
	  break;
	case 12:
	  SPRINTF1 (buff,"text _vi_%d;", a);
	  break;
	case 13:
	  SPRINTF2 (buff,"char _vi_%d[%d+1];", a, get_binding_dtype(bind->list.list_val[a]) >> 16);
	  break;
	case 14:
	  SPRINTF1 (buff,"interval _vi_%d;", a);
	  break;
	case DTYPE_INT8:
	  SPRINTF1 (buff,"int8 _vi_%d;", a);
	  break;
	}
	strcat(buff,buff_ind);
    }


  if (bind_type == 'o')
    {

 	if (A4GLSQLCV_check_requirement("USE_INDICATOR")) { SPRINTF1(buff_ind,"\n static short _voi_%d;",a); } else { strcpy(buff_ind,""); }

      switch (get_binding_dtype(bind->list.list_val[a]) & 0xffff)
	{
	case 0:
	  SPRINTF2 (buff,"char _vo_%d[%d+1]=\"\";", a, get_binding_dtype(bind->list.list_val[a]) >> 16);
	  break;
	case 1:
	  SPRINTF1 (buff,"short _vo_%d=0;", a);
	  break;
	case 2:
	  SPRINTF1 (buff,"int _vo_%d=0;", a);
	  break;
	case 3:
	  SPRINTF1 (buff,"double _vo_%d=0.0;", a);
	  break;
	case 4:
	  SPRINTF1 (buff,"float _vo_%d=0.0;", a);
	  break;
	case 5:
	  	SPRINTF2 (buff,"decimal(%s) _vo_%d;", decode_decimal_size_as_string(get_binding_dtype(bind->list.list_val[a])),a);
	  	break;
	case 6:
	  SPRINTF1 (buff,"int _vo_%d=0;", a);
	  break;
	case 7:
	  SPRINTF1 (buff,"date _vo_%d=0;", a);
	  break;
	case 8:
	  	SPRINTF2 (buff,"money(%s) _vo_%d;", decode_decimal_size_as_string(get_binding_dtype(bind->list.list_val[a])),a);
	  break;
	case 9:
	  SPRINTF1 (buff,"Blah _vo_%d;", a);
	  break;
	case 10:
	  SPRINTF2 (buff,"datetime %s _vo_%d;",  A4GL_dtype_sz(DTYPE_DTIME,DECODE_SIZE(get_binding_dtype(bind->list.list_val[a]))),a);
	  break;
	case 11:
	  SPRINTF1 (buff,"byte _vo_%d;", a);
	  break;
	case 12:
	  SPRINTF1 (buff,"text _vo_%d;", a);
	  break;
	case 13:
	  SPRINTF2 (buff,"varchar _vo_%d[%d+1]=\"\";", a , get_binding_dtype(bind->list.list_val[a]) >> 16 );
	  break;
	case 14:
	  SPRINTF1 (buff,"interval _vo_%d;", a);
	  break;
	case DTYPE_INT8:
	  SPRINTF1 (buff,"int8 _vo_%d;", a);
	  break;
	}
	strcat(buff,buff_ind);
    }

    return buff;
}

char *inparts[]={
	"",
		"YEAR",
		"MONTH",
		"DAY",
		"HOUR",
		"MINUTE",
		"SECOND",
		"FRACTION(1)",
		"FRACTION(2)",
		"FRACTION(3)",
		"FRACTION(4)",
		"FRACTION(5)"
	
};

char *dtparts[]={
		"YEAR",
		"MONTH",
		"DAY",
		"HOUR",
		"MINUTE",
		"SECOND",
		"FRACTION"
};

static char *decode_interval(int a) {
	static char buff[200];
	int s[3];
	s[2]=a&0xf;
	a=a>>4;
	s[1]=a&0xf;
	a=a>>4;
	s[0]=a&0xf;
	a=a>>4;
	SPRINTF3(buff, "%s(%d) TO %s\n",inparts[s[1]],s[0],inparts[s[2]]);
	return buff;
}

static char *decode_datetime(int a) {
	int pt1;
	int pt2;
	int fr;
	char ps1[200];
	char ps2[200];
	static char buff[200];

	if (((a/16)%16)<=10)  {
		pt1=(((a/16)%16)-1);
	} else {
		pt1=6;
	}
	strcpy(ps1,dtparts[pt1]);
	
	if ((a%16)<=6) {
		pt2=(a%16)-1;
		//pt2=pt2/2;
		strcpy(ps2,dtparts[pt2]);
	} else {

		pt2=6;
		fr=(a % 16)-6;
		sprintf(ps2,"%s(%d)",dtparts[pt2],fr);
	}
	sprintf(buff," %s TO %s",ps1,ps2);
	return buff;
}


/*
static char *decode_datetime2(int a) {
	int pt1;
	int pt2;
	int fr;
	char ps1[200];
	char ps2[200];
	static char buff[200];

	if (((a/16)%16)<=10)  {
		pt1=(((a/16)%16)/2);
	} else {
		pt1=6;
	}
	strcpy(ps1,dtparts[pt1]);
	
	if ((a%16)<=10) {
		pt2=(a%16)/2;
		strcpy(ps2,dtparts[pt2]);
	} else {
		pt2=6;
		fr=(a % 16)-10;
		sprintf(ps2,"%s(%d)",dtparts[pt2],fr);
	}
	sprintf(buff," %s TO %s",ps1,ps2);
	return buff;
}
*/


char *
A4GL_dtype_sz (int d, int s)
{
  static char buff[256];
  switch (d & 15)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 7:
    case 6:
    case 11:
    case 12:
      return "";

    case 10:
	strcpy(buff, decode_datetime(s));
	return buff;

    case 8:
    case 5:                     /* decimal */
      return "(32,16)";

    case 0:
    case 13:
      SPRINTF1 (buff, "(%d)", s);
      return buff;

    case 14:
	strcpy(buff, decode_interval(s));
	return buff;

      return buff;
    }
  return "";
}


int has_conversions_g (expr_str_list *bind,char dir) {
char *str;
str= get_last_print_bind_dir_definition_g_rval(tolower(dir));
if (str==0) return 0;
if (strlen(str)==0) return 0;
return 1;
}



void print_conversions_g (expr_str_list *bind,char dir) {
char *str;

str= get_last_print_bind_dir_definition_g_rval(tolower(dir));

	printc("/* PRINT CONVERSIONS */");




if (str==0) {
	if (bind->list.list_len==0) return;
	if (dir=='i'||dir=='o') {
		A4GL_assertion(1,"SHOULD THIS HAPPEND ? ");
	} 
	return;
}
  if (dir == 'i')
    {
      printc ("%s /* buff_in */\n", str);
    }

  if (dir == 'o'|| dir=='r')
    {
	if (doing_esql()) {
      		printc ("if (sqlca.sqlcode==0) { %s } /* buff_out */\n", str);
	} else {
      		printc ("{if (A4GL_get_a4gl_status()==0) { %s } }/* buff_out */\n", str);
	}
    }

  if (dir == 'I')
    {
      printh ("%s /* buff_in */\n", str);
    }

  if (dir == 'O')
    {
	if (doing_esql()) {
      		printh (" if (sqlca.sqlcode==0) { %s } /* buff_out */\n", str);
	} else {
      		printh ("{ if (A4GL_get_a4gl_status()==0) { %s } }/* buff_out */\n", str);
	}
    }


}

