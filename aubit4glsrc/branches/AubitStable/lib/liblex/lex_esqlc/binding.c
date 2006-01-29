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
# $Id: binding.c,v 1.50.2.1 2006-01-26 18:28:57 mikeaubury Exp $
*/

/**
 * @file
 * 
 * Please describe me here
 */


#include "a4gl_lib_lex_esqlc_int.h"
#ifndef lint
	static char const module_id[] =
		"$Id: binding.c,v 1.50.2.1 2006-01-26 18:28:57 mikeaubury Exp $";
#endif

extern int ibindcnt;
extern int obindcnt;
dll_import struct binding_comp *ibind; //[NUMBINDINGS];
dll_import struct binding_comp *obind; //[NUMBINDINGS];

/* these two store the string for converting the data
 * back and forth from our temporary DECLARE SECTION variables
 * and the real deal.
 * We need the temporary variables because we may well store the
 * data differently from the target database (take datetime for example)
 * We also need to be able to handle the differences betwen vendors 
 * ESQL/C types...
 *
*/
char buff_in[100000];
char buff_out[100000];

#define ONE_NOT_ZERO(x) (x?x:1)

void print_conversions (char i);
void make_sql_bind (char *sql, char *type);
char *
make_sql_bind_expr (char *sql, char *type);
static char *get_sql_type (int a, char ioro);
void printc (char *fmt, ...);
void printh (char *fmt, ...);
int esql_type (void);
void liblex_add_ibind(int dtype,char *var) ;
static char* get_sql_type_infx (int a, char ioro);
static char *get_sql_type_postgres (int a, char ioro);
static char *get_sql_type_sap (int a, char ioro);
static char *get_sql_type_ingres (int a, char ioro);
char * A4GL_dtype_sz (int d, int s);
struct binding_comp *ensure_bind(long *a_bindp,long need, struct binding_comp *b) ;


#ifdef NOT_USED
static char *dt_qual(int w,int a) {
	char buff[20];
	sprintf(buff,"%d - %d",w,a);
	return buff;
if (w==1) {
	switch(a) {
		case 0xc: return "YEAR";
		case 2: return "MONTH";
		case 3: return "DAY";
		case 4: return "HOUR";
		case 5: return "MINUTE";
		case 6: return "SECOND";
	}
}

if (w==2) {
	switch(a) {
		case 0xc: return "YEAR";
		case 2: return "MONTH";
		case 3: return "DAY";
		case 4: return "HOUR";
		case 5: return "MINUTE";
		case 6: return "SECOND";
	}
}
	printf("DEFAULT : %d (%x)\n",a,a);
	return "FRACTION(5)";
}
#endif



static char *decode_decimal_size_as_string(int n) {
static char buff[256];
int n2;
int n3;


n2=n>>16;
if ((n2&0xff)==0xff) { printf("n=%d (%x)\n",n2,n2); n2=n2>>8; SPRINTF1(buff,"%d",n2); return buff; }
n3=n2>>8;
if (n3>32) {
	printf("n=%x n2=%x\n",n,n2);
	printf("n3=%d  (%x) n2=%d(%x)\n",n3,n3,n2,n2);
	A4GL_assertion(1,"n3 > 32...");
}
SPRINTF2(buff,"%d,%d",n2>>8,n2&255);
return buff;
}



void
print_conversions (char i)
{
  if (i == 'i')
    {
      printc ("%s /* buff_in */\n", buff_in);
    }
  if (i == 'o')
    {
      printc ("{if (A4GL_get_a4gl_status()==0) { %s } }/* buff_out */\n", buff_out);
    }
  if (i == 'I')
    {
      printh ("%s /* buff_in */\n", buff_in);
    }
  if (i == 'O')
    {
      printh ("{ if (A4GL_get_a4gl_status()==0) { %s } }/* buff_out */\n", buff_out);
    }
  if (i=='0') {
	strcpy(buff_in,"");
	strcpy(buff_out,"");
  }

}


/* This function converts the SQL into*/
/* SQL INTO etc and converts the place holders back to variables...*/
/**/
/**/
/*          printc ("{&%s,%d,%d}", ibind[a].varname,*/
/*                            (int) ibind[a].dtype & 0xffff, (int) ibind[a].dtype >> 16);*/
/**/
void
make_sql_bind (char *sql, char *type)
{
  char buff_small[256];
  int a;
  if (sql == 0)
    {
      set_suppress_lines ();
      printc ("\nEXEC SQL BEGIN DECLARE SECTION;/*A2*/\n");
      if (strchr (type, 'i'))
	{
	  strcpy (buff_in, "");
	  if (ibindcnt)
	    {

	      if (!A4GLSQLCV_check_requirement ("USE_INDICATOR"))
		{
		  SPRINTF1 (buff_in,
			   "A4GL_copy_native_bind('i',ibind,native_binding_i,0,%d);",
			   ibindcnt);
		}
	      else
		{
		  SPRINTF1 (buff_in,
			   "A4GL_copy_native_bind('i',ibind,native_binding_i,native_binding_i_ind,%d);",
			   ibindcnt);
		}

	      for (a = 0; a < ibindcnt; a++)
		{
		  //char indicat[40];

		  printc ("%s", get_sql_type (a, 'i'));
#ifdef OLDWAY
		  if (!A4GLSQLCV_check_requirement ("USE_INDICATOR"))
		    {
		      strcpy (indicat, "0");
		    }
		  else
		    {
		      SPRINTF1 (indicat, "native_binding_i_ind[%d].ptr", a);
		    }


		  if ((ibind[a].dtype & 0xffff) == 0
		      || (ibind[a].dtype & 0xffff) == DTYPE_VCHAR)
		    {
		      SPRINTF7 (buff_small,
			       "COPY_DATA_IN_%d(ibind[%d].ptr,native_binding_i[%d].ptr,%s,%d,%d,%d); /* SQB */\n",
			       ibind[a].dtype & 0xffff, a, a, indicat,
			       ibind[a].dtype >> 16,
			       ibind[a].start_char_subscript,
			       ibind[a].end_char_subscript);
		    }
		  else
		    {
		      SPRINTF5 (buff_small,
			       "COPY_DATA_IN_%d(ibind[%d].ptr,native_binding_i[%d].ptr,%s,%d); /* SQB2 */\n",
			       ibind[a].dtype & 0xffff,
			       /*ibind[a].varname, */
			       a, a, indicat, ibind[a].dtype >> 16);

		    }
		  strcat (buff_in, buff_small);
#endif
		}
	    }
	}

      if (strchr (type, 'o'))
	{
	  strcpy (buff_out, "");
	  if (obindcnt)
	    {

	      //SPRINTF1 (buff_small, "A4GL_set_init(obind,%d);\n", obindcnt);
	      strcpy (buff_out, "");
	      if (!A4GLSQLCV_check_requirement ("USE_INDICATOR"))
		{
		  SPRINTF1 (buff_small,
			   "A4GL_copy_native_bind('o',obind,native_binding_o,0,%d);",
			   obindcnt);
		}
	      else
		{
		  SPRINTF1 (buff_small,
			   "A4GL_copy_native_bind('o',obind,native_binding_o,native_binding_o_ind,%d);",
			   obindcnt);
		}
	      strcat (buff_out, buff_small);

	      for (a = 0; a < obindcnt; a++)
		{
		  //char indicat[40];
		  printc ("%s", get_sql_type (a, 'o'));

#ifdef OLDWAY
		  if (!A4GLSQLCV_check_requirement ("USE_INDICATOR"))
		    {
		      strcpy (indicat, "0");
		    }
		  else
		    {
		      SPRINTF1 (indicat, "native_binding_o_ind[%d].ptr", a);
		    }
		  if ((obind[a].dtype & 0xffff) == 0
		      || (obind[a].dtype & 0xffff) == DTYPE_VCHAR)
		    {
		      SPRINTF7 (buff_small,
			       "COPY_DATA_OUT_%d(obind[%d].ptr,native_binding_o[%d].ptr,%s,%d,%d,%d);\n",
			       obind[a].dtype & 0xffff,
			       /*obind[a].varname, */
			       a,
			       a,
			       indicat,
			       obind[a].dtype >> 16,
			       obind[a].start_char_subscript,
			       obind[a].end_char_subscript);

		    }
		  else
		    {
		      SPRINTF5 (buff_small,
			       "COPY_DATA_OUT_%d(obind[%d].ptr,native_binding_o[%d].ptr,%s,%d);\n",
			       obind[a].dtype & 0xffff,
			       /*obind[a].varname, */
			       a, a, indicat, obind[a].dtype >> 16);

		    }
		  strcat (buff_out, buff_small);
#endif
		}
	    }

	}
      printc ("\nEXEC SQL END DECLARE SECTION;\n");
      clr_suppress_lines ();


      if (strchr (type, 'i'))
	{

	  char comma = ' ';
	  printc ("struct BINDING native_binding_i[%d]={\n",
		  ONE_NOT_ZERO (ibindcnt));
	  if (ibindcnt == 0)
	    {
	      printc ("{0,0,0,0,0,0}");
	    }
	  for (a = 0; a < ibindcnt; a++)
	    {
	      printc ("   %c{&_vi_%d,%d,%d,0,0,0}", comma, a,
		      ibind[a].dtype & 0xffff, ibind[a].dtype >> 16);
	      comma = ',';
	    }
	  printc ("};\n");
	  if (A4GLSQLCV_check_requirement ("USE_INDICATOR"))
	    {
	      char comma = ' ';
	      printc ("struct BINDING native_binding_i_ind[]={\n");
	      if (ibindcnt == 0)
		{
		  printc ("{0,0,0,0,0,0}");
		}
	      for (a = 0; a < ibindcnt; a++)
		{
		  printc (" %c{&_vii_%d,%d,%d,0,0,0}", comma, a, 2, 4);
		  comma = ',';
		}
	      printc ("};\n");
	    }




	}

      if (strchr (type, 'o'))
	{
	  char comma = ' ';
	  printc ("struct BINDING native_binding_o[%d]={\n",
		  ONE_NOT_ZERO (obindcnt));
	  if (obindcnt == 0)
	    {
	      printc ("{0,0,0,0,0,0}");
	    }
	  for (a = 0; a < obindcnt; a++)
	    {
	      printc (" %c{&_vo_%d,%d,%d,0,0,0}", comma, a,
		      obind[a].dtype & 0xffff, obind[a].dtype >> 16);
	      comma = ',';
	    }
	  printc ("};\n");

	  if (A4GLSQLCV_check_requirement ("USE_INDICATOR"))
	    {
	      char comma = ' ';
	      printc ("struct BINDING native_binding_o_ind[]={\n");
	      if (obindcnt == 0)
		{
		  printc ("{0,0,0,0,0,0}");
		}
	      for (a = 0; a < obindcnt; a++)
		{
		  printc (" %c{&_voi_%d,%d,%d,0,0,0}", comma, a, 2, 4);
		  comma = ',';
		}
	      printc ("};\n");
	    }



	}


    }
}



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

char *
make_sql_bind_expr (char *sql, char *type)
{
  char buff_small[256];
  char b2[256];
  char *ptr = 0;
  int sz = 0;
  int a;


  ptr = addstr (ptr, &sz, "\nEXEC SQL BEGIN DECLARE SECTION;/* A1*/\n");
  strcpy (b2, "");


  if (sql == 0)
    {
      if (strchr (type, 'i'))
	{
	  strcpy (buff_in, "");
	  if (ibindcnt)
	    {
	      if (!A4GLSQLCV_check_requirement ("USE_INDICATOR"))
		{
		  SPRINTF1 (buff_in,
			   "A4GL_copy_native_bind('i',ibind,native_binding_i,0,%d);",
			   ibindcnt);
		}
	      else
		{
		  SPRINTF1 (buff_in,
			   "A4GL_copy_native_bind('i',ibind,native_binding_i,native_binding_i_ind,%d);",
			   ibindcnt);
		}

	      for (a = 0; a < ibindcnt; a++)
		{
		  //char indicat[40];
		  SPRINTF1 (b2, "%s\n", get_sql_type (a, 'i'));
		  ptr = addstr (ptr, &sz, b2);


#ifdef OLD_WAY
		  if (!A4GLSQLCV_check_requirement ("USE_INDICATOR"))
		    {
		      strcpy (indicat, "0");
		    }
		  else
		    {
		      SPRINTF1 (indicat, "native_binding_i_ind[%d].ptr", a);
		    }


		  if ((ibind[a].dtype & 0xffff) == 0
		      || (ibind[a].dtype & 0xffff) == DTYPE_VCHAR)
		    {
		      SPRINTF7 (buff_small,
			       "COPY_DATA_IN_%d(ibind[%d].ptr,native_binding_i[%d].ptr,%s,%d,%d,%d); /*E*/\n",
			       ibind[a].dtype & 0xffff, a, a, indicat,
			       ibind[a].dtype >> 16,
			       ibind[a].start_char_subscript,
			       ibind[a].end_char_subscript);
		    }
		  else
		    {
		      SPRINTF5 (buff_small,
			       "COPY_DATA_IN_%d(ibind[%d].ptr,native_binding_i[%d].ptr,%s,%d); /*E*/\n",
			       ibind[a].dtype & 0xffff, a, a, indicat,
			       ibind[a].dtype >> 16);

		    }



		  strcat (buff_in, buff_small);

#endif
		}
	    }

	}

      if (strchr (type, 'o'))
	{
	  strcpy (buff_out, "");
	  if (obindcnt)
	    {

	      //SPRINTF1 (buff_small, "A4GL_set_init(obind,%d);\n", obindcnt);
	      strcpy (buff_out, buff_small);
	      for (a = 0; a < obindcnt; a++)
		{
		  //char indicat[40];
		  SPRINTF1 (b2, "%s\n", get_sql_type (a, 'o'));
		  ptr = addstr (ptr, &sz, b2);
		  if (!A4GLSQLCV_check_requirement ("USE_INDICATOR"))
		    {
		      SPRINTF1 (buff_small,
			       "A4GL_copy_native_bind('o',obind,native_binding_o,0,%d);",
			       obindcnt);
		    }
		  else
		    {
		      SPRINTF1 (buff_small,
			       "A4GL_copy_native_bind('o',obind,native_binding_o,native_binding_o_ind,%d);",
			       obindcnt);
		    }
		  strcpy (buff_out, buff_small);

#ifdef OLDWAY
		  if (!A4GLSQLCV_check_requirement ("USE_INDICATOR"))
		    {
		      strcpy (indicat, "0");
		    }
		  else
		    {
		      SPRINTF1 (indicat, "native_binding_o_ind[%d].ptr", a);
		    }
		  if ((obind[a].dtype & 0xffff) == 0
		      || (obind[a].dtype & 0xffff) == DTYPE_VCHAR)
		    {
		      SPRINTF7 (buff_small,
			       "COPY_DATA_OUT_%d(obind[%d].ptr,native_binding_o[%d].ptr,%s,%d,%d,%d);\n",
			       obind[a].dtype & 0xffff,
			       /*obind[a].varname, */
			       a,
			       a,
			       indicat,
			       obind[a].dtype >> 16,
			       obind[a].start_char_subscript,
			       obind[a].end_char_subscript);

		    }
		  else
		    {
		      SPRINTF5 (buff_small,
			       "COPY_DATA_OUT_%d(obind[%d].ptr,native_binding_o[%d].ptr,%s,%d);\n",
			       obind[a].dtype & 0xffff,
			       /*obind[a].varname, */
			       a, a, indicat, obind[a].dtype >> 16);

		    }
		  strcat (buff_out, buff_small);
#endif


		}

	    }
	}


      ptr = addstr (ptr, &sz, "\nEXEC SQL END DECLARE SECTION;\n");


      if (strchr (type, 'i'))
	{

	  char comma = ' ';
	  ptr = addstr (ptr, &sz, "struct BINDING native_binding_i[]={\n");
	  if (ibindcnt == 0)
	    {
	      ptr = addstr (ptr, &sz, "{0,0,0,0,0,0}");
	    }
	  for (a = 0; a < ibindcnt; a++)
	    {
	      char buff[255];
	      SPRINTF4 (buff, "   %c{&_vi_%d,%d,%d}", comma, a,
		       ibind[a].dtype & 0xffff, ibind[a].dtype >> 16);
	      ptr = addstr (ptr, &sz, buff);
	      comma = ',';
	    }

	  ptr = addstr (ptr, &sz, "};\n");

	  if (A4GLSQLCV_check_requirement ("USE_INDICATOR"))
	    {
	      char comma = ' ';
	      ptr =
		addstr (ptr, &sz,
			"struct BINDING native_binding_i_ind[]={\n");
	      if (ibindcnt == 0)
		{
		  ptr = addstr (ptr, &sz, "{0,0,0,0,0,0}");
		}
	      for (a = 0; a < ibindcnt; a++)
		{
		  char buff[255];
		  SPRINTF4 (buff, " %c{&_vii_%d,%d,%d}", comma, a, 2, 4);
		  ptr = addstr (ptr, &sz, buff);
		  comma = ',';
		}
	      ptr = addstr (ptr, &sz, "};\n");
	    }




	}

      if (strchr (type, 'o'))
	{
	  char comma = ' ';
	  ptr = addstr (ptr, &sz, "struct BINDING native_binding_o[]={\n");
	  if (obindcnt == 0)
	    {
	      printc ("{0,0,0,0,0,0}");
	    }
	  for (a = 0; a < obindcnt; a++)
	    {
	      char buff[255];
	      SPRINTF4 (buff, " %c{&_vo_%d,%d,%d,0,0,0}", comma, a,
		       obind[a].dtype & 0xffff, obind[a].dtype >> 16);
	      ptr = addstr (ptr, &sz, buff);
	      comma = ',';
	    }
	  ptr = addstr (ptr, &sz, "};\n");

	  if (A4GLSQLCV_check_requirement ("USE_INDICATOR"))
	    {
	      char comma = ' ';
	      ptr =
		addstr (ptr, &sz,
			"struct BINDING native_binding_o_ind[]={\n");
	      if (obindcnt == 0)
		{
		  ptr = addstr (ptr, &sz, "{0,0,0,0,0,0}");
		}
	      for (a = 0; a < obindcnt; a++)
		{
		  char buff[255];
		  SPRINTF4 (buff, " %c{&_voi_%d,%d,%d,0,0,0}", comma, a, 2, 4);
		  ptr = addstr (ptr, &sz, buff);
		  comma = ',';
		}
	      ptr = addstr (ptr, &sz, "};\n");
	    }

	}
    }
  return ptr;
}



char *
get_sql_type (int a, char ioro)
{
  /* Need to do some check to determine which ESQL/C to use...*/

  if (esql_type()==1) {
  	return get_sql_type_infx (a, ioro);
  }

  if (esql_type()==2) {
  	return get_sql_type_postgres (a, ioro);
  }

  if (esql_type()==3) {
  	return get_sql_type_sap (a, ioro);
  }
  if (esql_type()==4) {
  	return get_sql_type_ingres (a, ioro);
  }
return 0;
}


static char *get_sql_type_infx (int a, char ioro)
{
static char buff[255];
char buff_ind[255];

  if (ioro == 'i')
    {

      if (A4GLSQLCV_check_requirement("USE_INDICATOR")) { SPRINTF1(buff_ind,"  short _vii_%d;",a); } else { strcpy(buff_ind,""); }

      switch (ibind[a].dtype & 0xffff)
	{
	case 0:
	  SPRINTF2 (buff,"char _vi_%d[%d+1];", a, ibind[a].dtype >> 16);
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
	  SPRINTF2 (buff,"decimal(%s) _vi_%d;", decode_decimal_size_as_string(ibind[a].dtype),a);
	  break;

	case 6:
	  SPRINTF1 (buff,"int _vi_%d;", a);
	  break;

	case 7:
	  SPRINTF1 (buff,"date _vi_%d;", a);
	  break;
	case 8:
	  SPRINTF2 (buff,"money(%s) _vi_%d;", decode_decimal_size_as_string(ibind[a].dtype),a);
	  break;
	case 9:
	  SPRINTF1 (buff,"Blah _vi_%d;", a);
	  break;
	case 10:
	  SPRINTF2 (buff,"datetime %s _vi_%d;", A4GL_dtype_sz(DTYPE_DTIME,DECODE_SIZE(ibind[a].dtype)),a);
	  break;
	case 11:
	  SPRINTF1 (buff,"byte _vi_%d;", a);
	  break;
	case 12:
	  SPRINTF1 (buff,"text _vi_%d;", a);
	  break;
	case 13:
	  SPRINTF2 (buff,"char _vi_%d[%d+1];", a, ibind[a].dtype >> 16);
	  break;
	case 14:
	  SPRINTF1 (buff,"interval _vi_%d;", a);
	  break;
	}
	strcat(buff,buff_ind);
    }


  if (ioro == 'o')
    {

 	if (A4GLSQLCV_check_requirement("USE_INDICATOR")) { SPRINTF1(buff_ind,"  short _voi_%d=-2;",a); } else { strcpy(buff_ind,""); }

      switch (obind[a].dtype & 0xffff)
	{
	case 0:
	  SPRINTF2 (buff,"char _vo_%d[%d+1]=\"\";", a, obind[a].dtype >> 16);
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
	  	SPRINTF2 (buff,"decimal(%s) _vo_%d;", decode_decimal_size_as_string(obind[a].dtype),a);
	  	break;
	case 6:
	  SPRINTF1 (buff,"int _vo_%d=0;", a);
	  break;
	case 7:
	  SPRINTF1 (buff,"date _vo_%d=0;", a);
	  break;
	case 8:
	  	SPRINTF2 (buff,"money(%s) _vo_%d;", decode_decimal_size_as_string(obind[a].dtype),a);
	  break;
	case 9:
	  SPRINTF1 (buff,"Blah _vo_%d;", a);
	  break;
	case 10:
	  SPRINTF2 (buff,"datetime %s _vo_%d;",  A4GL_dtype_sz(DTYPE_DTIME,DECODE_SIZE(obind[a].dtype)),a);
	  break;
	case 11:
	  SPRINTF1 (buff,"byte _vo_%d;", a);
	  break;
	case 12:
	  SPRINTF1 (buff,"text _vo_%d;", a);
	  break;
	case 13:
	  SPRINTF2 (buff,"varchar _vo_%d[%d]=\"\";", a , obind[a].dtype >> 16 );
	  break;
	case 14:
	  SPRINTF1 (buff,"interval _vo_%d;", a);
	  break;
	}
	strcat(buff,buff_ind);
    }

    return buff;
}



static char *get_sql_type_postgres (int a, char ioro)
{
static char buff[255];
static char buff_ind[255];
  if (ioro == 'i')
    {
      if (A4GLSQLCV_check_requirement("USE_INDICATOR")) { SPRINTF1(buff_ind,"  short _vii_%d;",a); } else { strcpy(buff_ind,""); }
      switch (ibind[a].dtype & 0xffff)
	{
	case 0:
	  SPRINTF2 (buff,"char _vi_%d[%d+1];", a, ibind[a].dtype >> 16);
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
	  SPRINTF2 (buff,"decimal(%s) _vi_%d;", decode_decimal_size_as_string(ibind[a].dtype),a);
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
	  		SPRINTF2 (buff,"decimal(%s) _vi_%d;", decode_decimal_size_as_string(ibind[a].dtype), a);
		} else {
	  		SPRINTF2 (buff,"money(%s) _vi_%d;", decode_decimal_size_as_string(ibind[a].dtype),a);
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
	  SPRINTF2 (buff,"char _vi_%d[%d+1];", a, ibind[a].dtype >> 16);
	  break;
	case 14:
	  SPRINTF1 (buff,"interval _vi_%d;", a);
	  break;
	}
	strcat(buff,buff_ind);
    }


  if (ioro == 'o')
    {
 	if (A4GLSQLCV_check_requirement("USE_INDICATOR")) {
		SPRINTF1(buff_ind,"  short _voi_%d=0;",a);
	} else {
		strcpy(buff_ind,"");
	}

      switch (obind[a].dtype & 0xffff)
	{
	case 0:
	  SPRINTF2 (buff,"char _vo_%d[%d+1]=\"\";", a, obind[a].dtype >> 16);
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
	  	SPRINTF2 (buff,"decimal(%s) _vo_%d;", decode_decimal_size_as_string(obind[a].dtype),a);
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
	  		SPRINTF2 (buff,"decimal(%s) _vo_%d;", decode_decimal_size_as_string(obind[a].dtype), a);
		} else {
	  		SPRINTF2 (buff,"money(%s) _vo_%d;", decode_decimal_size_as_string(obind[a].dtype),a);
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
	  SPRINTF2 (buff,"varchar _vo_%d[%d]=\"\";", a , obind[a].dtype >> 16);
	  break;
	case 14:
	  SPRINTF1 (buff,"interval _vo_%d;", a);
	  break;
	}
	strcat(buff,buff_ind);
    }
	return buff;

}


void liblex_add_ibind(int dtype,char *var) {
	extern long a_ibind;
	ibind=ensure_bind(&a_ibind,ibindcnt+1,ibind);
	strcpy(ibind[ibindcnt].varname,var);
	ibind[ibindcnt].start_char_subscript=0;
	ibind[ibindcnt].end_char_subscript=0;
	ibind[ibindcnt].dtype=dtype;
	ibindcnt++;
}

static char *get_sql_type_sap (int a, char ioro)
{
static char buff[255];
static char buff_ind[255];
  if (ioro == 'i')
    {
      if (A4GLSQLCV_check_requirement("USE_INDICATOR")) { SPRINTF1(buff_ind,"  short _vii_%d;",a); } else { strcpy(buff_ind,""); }
      switch (ibind[a].dtype & 0xffff)
	{
	case 0:
	  SPRINTF2 (buff,"char _vi_%d[%d+1];", a, ibind[a].dtype >> 16);
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
	  SPRINTF2 (buff,"decimal(%s) _vi_%d;", decode_decimal_size_as_string(ibind[a].dtype),a);
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
	  		SPRINTF2 (buff,"decimal(%s) _vi_%d;", decode_decimal_size_as_string(obind[a].dtype), a);
		} else {
	  		SPRINTF2 (buff,"money(%s) _vi_%d;", decode_decimal_size_as_string(ibind[a].dtype),a);
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
	  SPRINTF2 (buff,"char _vi_%d[%d+1];", a, ibind[a].dtype >> 16);
	  break;
	case 14:
	  SPRINTF1 (buff,"interval _vi_%d;", a);
	  break;
	}
	strcat(buff,buff_ind);
    }


  if (ioro == 'o')
    {
 	if (A4GLSQLCV_check_requirement("USE_INDICATOR")) {
		SPRINTF1(buff_ind,"  short _voi_%d=0;",a);
	} else {
		strcpy(buff_ind,"");
	}

      switch (obind[a].dtype & 0xffff)
	{
	case 0:
	  SPRINTF2 (buff,"char _vo_%d[%d+1]=\"\";", a, obind[a].dtype >> 16);
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
	  	SPRINTF2 (buff,"decimal(%s) _vo_%d;", decode_decimal_size_as_string(obind[a].dtype),a);
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
	  		SPRINTF2 (buff,"decimal(%s) _vo_%d;", decode_decimal_size_as_string(obind[a].dtype), a);
		} else {
	  		SPRINTF2 (buff,"money(%s) _vo_%d;", decode_decimal_size_as_string(obind[a].dtype),a);
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
	}
	strcat(buff,buff_ind);
    }
	return buff;

}











static char *get_sql_type_ingres (int a, char ioro)
{
static char buff[255];
static char buff_ind[255];
  if (ioro == 'i')
    {
      if (A4GLSQLCV_check_requirement("USE_INDICATOR")) { SPRINTF1(buff_ind,"  short _vii_%d;",a); } else { strcpy(buff_ind,""); }
      switch (ibind[a].dtype & 0xffff)
	{
	case 0:
	  SPRINTF2 (buff,"char _vi_%d[%d+1];", a, ibind[a].dtype >> 16);
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
	  SPRINTF2 (buff,"char _vi_%d[%d+1];", a, ibind[a].dtype >> 16);
	  break;
	case 14:
	  SPRINTF1 (buff,"char _vi_%d[30];", a);
	  break;
	}
	strcat(buff,buff_ind);
    }


  if (ioro == 'o')
    {
 	if (A4GLSQLCV_check_requirement("USE_INDICATOR")) {
		SPRINTF1(buff_ind,"  short _voi_%d=0;",a);
	} else {
		strcpy(buff_ind,"");
	}

      switch (obind[a].dtype & 0xffff)
	{
	case 0:
	  SPRINTF2 (buff,"char _vo_%d[%d+1]=\"\";", a, obind[a].dtype >> 16);
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
	}
	strcat(buff,buff_ind);
    }
	return buff;

}



char *dtparts[]={
		"YEAR",
		"MONTH",
		"DAY",
		"HOUR",
		"MINUTE",
		"SECOND",
		"FRACTION"
};


static char *decode_datetime(int a) {
	int pt1;
	int pt2;
	int fr;
	char ps1[200];
	char ps2[200];
	static char buff[200];

	//printf("Decode : %x\n",a);
	if (((a/16)%16)<=10)  {
		pt1=(((a/16)%16)-1);
	} else {
		pt1=6;
	}
	//printf("pt1=%d\n",pt1);
	strcpy(ps1,dtparts[pt1]);
	
	if ((a%16)<=6) {
		pt2=(a%16)-1;
		//pt2=pt2/2;
		strcpy(ps2,dtparts[pt2]);
	} else {

		pt2=6;
		fr=(a % 16)-6;
		//printf("pt2=%d x2\n",pt2);
		sprintf(ps2,"%s(%d)",dtparts[pt2],fr);
	}
	sprintf(buff," %s TO %s",ps1,ps2);
	//printf("%d to %d\n",pt1,pt2);
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

	//printf("Decode : %d\n",a);
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
      SPRINTF0 (buff, " year to second(5)");
      return buff;
    }
  return "";
}