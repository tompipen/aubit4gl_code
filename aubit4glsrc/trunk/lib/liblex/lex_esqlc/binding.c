#include "a4gl_lib_lex_esqlc_int.h"
static char *module_id="$Id: binding.c,v 1.27 2004-01-18 12:55:12 mikeaubury Exp $";

extern int ibindcnt;
extern int obindcnt;
dll_import struct binding_comp ibind[NUMBINDINGS];
dll_import struct binding_comp obind[NUMBINDINGS];

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
char * A4GL_dtype_sz (int d, int s);

static char *dt_qual(int a) {
	switch(a) {
	case 1: return "YEAR";
	case 2: return "MONTH";
	case 3: return "DAY";
	case 4: return "HOUR";
	case 5: return "MINUTE";
	case 6: return "SECOND";
	}
	return "FRACTION(5)";
}



static char *decode_decimal_size_as_string(int n) {
static char buff[256];
int n2;
n2=n>>16;
sprintf(buff,"%d,%d",n2>>8,n2&255);
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
      printc ("{extern long a4gl_status; if (a4gl_status==0) { %s } }/* buff_out */\n", buff_out);
    }
  if (i == 'I')
    {
      printh ("%s /* buff_in */\n", buff_in);
    }
  if (i == 'O')
    {
      printh ("{ extern long a4gl_status; if (a4gl_status==0) { %s } }/* buff_out */\n", buff_out);
    }
  if (i=='0') {
	strcpy(buff_in,"");
	strcpy(buff_out,"");
  }

}


// This function converts the SQL into
// SQL INTO etc and converts the place holders back to variables...
//
//
//          printc ("{&%s,%d,%d}", ibind[a].varname,
//                            (int) ibind[a].dtype & 0xffff, (int) ibind[a].dtype >> 16);
//
void
make_sql_bind (char *sql, char *type)
{
  char buff_small[256];
  int a;
  if (sql == 0)
    {
      printc ("EXEC SQL BEGIN DECLARE SECTION;\n");
      if (strchr (type, 'i'))
	{
	  strcpy (buff_in, "");
	  if (ibindcnt)
	    {
	      for (a = 0; a < ibindcnt; a++)
		{
		  printc("%s",get_sql_type (a, 'i'));
		if ((ibind[a].dtype & 0xffff)==0) {
		  sprintf (buff_small, "COPY_DATA_IN_%d(ibind[%d].ptr,native_binding_i[%d].ptr,%d,%d,%d);\n",
			   ibind[a].dtype & 0xffff, 
					//ibind[a].varname, 
					a,
					
				a,
			   ibind[a].dtype >> 16,
			ibind[a].start_char_subscript,
			ibind[a].end_char_subscript
);
		} else {
		  sprintf (buff_small, "COPY_DATA_IN_%d(ibind[%d].ptr,native_binding_i[%d].ptr,%d);\n",
			   ibind[a].dtype & 0xffff, 
					//ibind[a].varname, 
					a,
					
				a,
			   ibind[a].dtype >> 16
);

		}
		  strcat (buff_in, buff_small);
		}
	      //printc ("/* %s */", buff_in);
	    }
	}

      if (strchr (type, 'o'))
	{
	  strcpy (buff_out, "");
	  if (obindcnt)
	    {

	      sprintf (buff_small, "A4GL_set_init(obind,%d);\n", obindcnt);
	      strcpy (buff_out, buff_small);
	      for (a = 0; a < obindcnt; a++)
		{
		char indicat[40];
		  	printc("%s",get_sql_type (a, 'o'));

 			if (!A4GL_isyes(acl_getenv("USE_INDICATOR"))) {
				strcpy(indicat,"0");
			} else {
				sprintf(indicat,"native_binding_o_ind[%d].ptr",a);
			}
		if ((obind[a].dtype & 0xffff)==0) {
		  sprintf (buff_small, "COPY_DATA_OUT_%d(obind[%d].ptr,native_binding_o[%d].ptr,%s,%d,%d,%d);\n",
			   obind[a].dtype & 0xffff, 
				//obind[a].varname, 
				a,
				a,
				indicat,
			   obind[a].dtype >> 16,
			obind[a].start_char_subscript,
			obind[a].end_char_subscript);

		} else {
		  sprintf (buff_small, "COPY_DATA_OUT_%d(obind[%d].ptr,native_binding_o[%d].ptr,%s,%d);\n",
			   obind[a].dtype & 0xffff, 
				//obind[a].varname, 
				a,
				a,
				indicat,
			   obind[a].dtype >> 16
			);

		}
		  strcat (buff_out, buff_small);
		}
	    }
	}
      printc ("EXEC SQL END DECLARE SECTION;\n");


	if (strchr (type, 'i')) {

		char comma=' ';
      		printc("struct BINDING native_binding_i[%d]={\n",ONE_NOT_ZERO(ibindcnt));
		if(ibindcnt==0) { printc("{0,0,0}"); }
		for (a=0;a<ibindcnt;a++) {
			printc("   %c{&_vi_%d,%d,%d}",comma,a,ibind[a].dtype&0xffff,ibind[a].dtype>>16);
			comma=',';
		}
 		printc("};\n");



	}

	if (strchr (type, 'o')) {
		char comma=' ';
      		printc("struct BINDING native_binding_o[%d]={\n",ONE_NOT_ZERO(obindcnt));
		if(obindcnt==0) { printc("{0,0,0}"); }
		for (a=0;a<obindcnt;a++) {
			printc(" %c{&_vo_%d,%d,%d}",comma,a,obind[a].dtype&0xffff,obind[a].dtype>>16);
			comma=',';
		}
 		printc("};\n");
		
 		if (A4GL_isyes(acl_getenv("USE_INDICATOR"))) {
		char comma=' ';
      		printc("struct BINDING native_binding_o_ind[]={\n");
		if(obindcnt==0) { printc("{0,0,0}"); }
		for (a=0;a<obindcnt;a++) {
			printc(" %c{&_voi_%d,%d,%d}",comma,a,2,4);
			comma=',';
		}
 		printc("};\n");
		
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
  char *ptr=0;
   int sz=0;
  int a;


  ptr=addstr(ptr,&sz,"EXEC SQL BEGIN DECLARE SECTION;\n");
  strcpy(b2,"");


  if (sql == 0)
    {
      if (strchr (type, 'i'))
	{
	  strcpy (buff_in, "");
	  if (ibindcnt)
	    {
	      for (a = 0; a < ibindcnt; a++)
		{
		  sprintf(b2,"%s\n",get_sql_type (a, 'i'));
      			ptr=addstr(ptr,&sz, b2);
		if ((ibind[a].dtype & 0xffff)==0) {
		  sprintf (buff_small, "COPY_DATA_IN_%d(ibind[%d].ptr,native_binding_i[%d].ptr,%d,%d,%d); /*E*/\n",
			   ibind[a].dtype & 0xffff, 
					//ibind[a].varname, 
					a,
					
				a,
			   ibind[a].dtype >> 16,
			ibind[a].start_char_subscript,
			ibind[a].end_char_subscript
);
		} else {
		  sprintf (buff_small, "COPY_DATA_IN_%d(ibind[%d].ptr,native_binding_i[%d].ptr,%d); /*E*/\n",
			   ibind[a].dtype & 0xffff, 
					//ibind[a].varname, 
					a,
					
				a,
			   ibind[a].dtype >> 16
);

		}
		  strcat (buff_in, buff_small);
		}
	      //printc ("/* %s */", buff_in);
	    }
	}

      if (strchr (type, 'o'))
	{
	  strcpy (buff_out, "");
	  if (obindcnt)
	    {

	      sprintf (buff_small, "A4GL_set_init(obind,%d);\n", obindcnt);
	      strcpy (buff_out, buff_small);
	      for (a = 0; a < obindcnt; a++)
		{
		char indicat[40];
		  	sprintf(b2,"%s\n",get_sql_type (a, 'o'));
      			ptr=addstr(ptr,&sz, b2);

 			if (!A4GL_isyes(acl_getenv("USE_INDICATOR"))) {
				strcpy(indicat,"0");
			} else {
				sprintf(indicat,"native_binding_o_ind[%d].ptr",a);
			}
		if ((obind[a].dtype & 0xffff)==0) {
		  sprintf (buff_small, "COPY_DATA_OUT_%d(obind[%d].ptr,native_binding_o[%d].ptr,%s,%d,%d,%d);\n",
			   obind[a].dtype & 0xffff, 
				//obind[a].varname, 
				a,
				a,
				indicat,
			   obind[a].dtype >> 16,
			obind[a].start_char_subscript,
			obind[a].end_char_subscript);

		} else {
		  sprintf (buff_small, "COPY_DATA_OUT_%d(obind[%d].ptr,native_binding_o[%d].ptr,%s,%d);\n",
			   obind[a].dtype & 0xffff, 
				//obind[a].varname, 
				a,
				a,
				indicat,
			   obind[a].dtype >> 16
			);

		}
		  strcat (buff_out, buff_small);
		}
	    }
	}

	
      ptr=addstr(ptr,&sz, "EXEC SQL END DECLARE SECTION;\n");


	if (strchr (type, 'i')) {

		char comma=' ';
      		ptr=addstr(ptr,&sz,"struct BINDING native_binding_i[]={\n");
		if(ibindcnt==0) { ptr=addstr(ptr,&sz,"{0,0,0}"); }
		for (a=0;a<ibindcnt;a++) {
			char buff[255];
			sprintf(buff,"   %c{&_vi_%d,%d,%d}",comma,a,ibind[a].dtype&0xffff,ibind[a].dtype>>16);
			ptr=addstr(ptr,&sz,buff);
			comma=',';
		}
 		ptr=addstr(ptr,&sz,"};\n");



	}

	if (strchr (type, 'o')) {
		char comma=' ';
      		ptr=addstr(ptr,&sz,"struct BINDING native_binding_o[]={\n");
		if(obindcnt==0) { printc("{0,0,0}"); }
		for (a=0;a<obindcnt;a++) {
			char buff[255];
			sprintf(buff," %c{&_vo_%d,%d,%d}",comma,a,obind[a].dtype&0xffff,obind[a].dtype>>16);
			ptr=addstr(ptr,&sz,buff);
			comma=',';
		}
 		ptr=addstr(ptr,&sz,"};\n");
		
 		if (A4GL_isyes(acl_getenv("USE_INDICATOR"))) {
		char comma=' ';
      		ptr=addstr(ptr,&sz,"struct BINDING native_binding_o_ind[]={\n");
		if(obindcnt==0) { ptr=addstr(ptr,&sz,"{0,0,0}"); }
		for (a=0;a<obindcnt;a++) {
			char buff[255];
			sprintf(buff," %c{&_voi_%d,%d,%d}",comma,a,2,4);
			ptr=addstr(ptr,&sz,buff);
			comma=',';
		}
 		ptr=addstr(ptr,&sz,"};\n");
		
		}
	}
    }
	return ptr;
}


char *
get_sql_type (int a, char ioro)
{
  // Need to do some check to determine which ESQL/C to use...
  if (esql_type()==1) {
  	return get_sql_type_infx (a, ioro);
  }
  if (esql_type()==2) {
  	return get_sql_type_postgres (a, ioro);
  }
return 0;
}


static char *
get_sql_type_infx (int a, char ioro)
{
static char buff[255];
char buff_ind[255];

  if (ioro == 'i')
    {
      switch (ibind[a].dtype & 0xffff)
	{
	case 0:
	  sprintf (buff,"char _vi_%d[%d+1];", a, ibind[a].dtype >> 16);
	  break;
	case 1:
	  sprintf (buff,"short _vi_%d;", a);
	  break;
	case 2:
	  sprintf (buff,"int _vi_%d;", a);
	  break;
	case 3:
	  sprintf (buff,"double _vi_%d;", a);
	  break;
	case 4:
	  sprintf (buff,"float _vi_%d;", a);
	  break;

	case 5:
	  sprintf (buff,"decimal(%s) _vi_%d;", decode_decimal_size_as_string(ibind[a].dtype),a);
	  break;

	case 6:
	  sprintf (buff,"int _vi_%d;", a);
	  break;

	case 7:
	  sprintf (buff,"date _vi_%d;", a);
	  break;
	case 8:
	  sprintf (buff,"money(%s) _vi_%d;", decode_decimal_size_as_string(ibind[a].dtype),a);
	  break;
	case 9:
	  sprintf (buff,"Blah _vi_%d;", a);
	  break;
	case 10:
	  sprintf (buff,"datetime %s _vi_%d;", A4GL_dtype_sz(DTYPE_DTIME,DECODE_SIZE(ibind[a].dtype)),a);
	  break;
	case 11:
	  sprintf (buff,"interval _vi_%d;", a);
	  break;
	case 12:
	  sprintf (buff,"text _vi_%d;", a);
	  break;
	case 13:
	  sprintf (buff,"varchar _vi_%d;", a);
	  break;
	case 14:
	  sprintf (buff,"interval _vi_%d;", a);
	  break;
	}
    }


  if (ioro == 'o')
    {
 	if (A4GL_isyes(acl_getenv("USE_INDICATOR"))) {
		sprintf(buff_ind,"  short _voi_%d;",a);
	} else {
		strcpy(buff_ind,"");
	}

      switch (obind[a].dtype & 0xffff)
	{
	case 0:
	  sprintf (buff,"char _vo_%d[%d+1];", a, obind[a].dtype >> 16);
	  break;
	case 1:
	  sprintf (buff,"short _vo_%d;", a);
	  break;
	case 2:
	  sprintf (buff,"int _vo_%d;", a);
	  break;
	case 3:
	  sprintf (buff,"double _vo_%d;", a);
	  break;
	case 4:
	  sprintf (buff,"float _vo_%d;", a);
	  break;
	case 5:
	  	sprintf (buff,"decimal(%s) _vo_%d;", decode_decimal_size_as_string(obind[a].dtype),a);
	  	break;
	case 6:
	  sprintf (buff,"int _vo_%d;", a);
	  break;
	case 7:
	  sprintf (buff,"date _vo_%d;", a);
	  break;
	case 8:
	  	sprintf (buff,"money(%s) _vo_%d;", decode_decimal_size_as_string(obind[a].dtype),a);
	  break;
	case 9:
	  sprintf (buff,"Blah _vo_%d;", a);
	  break;
	case 10:
	  sprintf (buff,"datetime %s _vo_%d;",  A4GL_dtype_sz(DTYPE_DTIME,DECODE_SIZE(obind[a].dtype)),a);
	  break;
	case 11:
	  sprintf (buff,"interval _vo_%d;", a);
	  break;
	case 12:
	  sprintf (buff,"text _vo_%d;", a);
	  break;
	case 13:
	  sprintf (buff,"varchar _vo_%d;", a);
	  break;
	case 14:
	  sprintf (buff,"interval _vo_%d;", a);
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
      switch (ibind[a].dtype & 0xffff)
	{
	case 0:
	  sprintf (buff,"char _vi_%d[%d+1];", a, ibind[a].dtype >> 16);
	  break;
	case 1:
	  sprintf (buff,"short _vi_%d;", a);
	  break;
	case 2:
	  sprintf (buff,"int _vi_%d;", a);
	  break;
	case 3:
	  sprintf (buff,"double _vi_%d;", a);
	  break;
	case 4:
	  sprintf (buff,"float _vi_%d;", a);
	  break;

	case 5:
	  sprintf (buff,"decimal(%s) _vi_%d;", decode_decimal_size_as_string(ibind[a].dtype),a);
	  break;

	case 6:
	  sprintf (buff,"int _vi_%d;", a);
	  break;

	case 7:
	  sprintf (buff,"date _vi_%d;", a);
	  break;
	case 8:
	  if (A4GL_isyes(acl_getenv("MONEY_AS_MONEY"))) {
	  	sprintf (buff,"money _vi_%d;", a);
	  } else {
	  	if (A4GL_isyes(acl_getenv("MONEY_AS_DECIMAL"))) {
	  		sprintf (buff,"decimal(%s) _vi_%d;", decode_decimal_size_as_string(obind[a].dtype), a);
		} else {
	  		sprintf (buff,"money(%s) _vi_%d;", decode_decimal_size_as_string(ibind[a].dtype),a);
		}
	  }
	  break;
	case 9:
	  sprintf (buff,"Blah _vi_%d;", a);
	  break;
	case 10:
	  sprintf (buff,"datetime _vi_%d;",  a); // Datetimes can't be qualified in ecpg
	  break;
	case 11:
	  sprintf (buff,"interval _vi_%d;", a);
	  break;
	case 12:
	  sprintf (buff,"text _vi_%d;", a);
	  break;
	case 13:
	  sprintf (buff,"varchar _vi_%d;", a);
	  break;
	case 14:
	  sprintf (buff,"interval _vi_%d;", a);
	  break;
	}
    }


  if (ioro == 'o')
    {
 	if (A4GL_isyes(acl_getenv("USE_INDICATOR"))) {
		sprintf(buff_ind,"  short _voi_%d;",a);
	} else {
		strcpy(buff_ind,"");
	}

      switch (obind[a].dtype & 0xffff)
	{
	case 0:
	  sprintf (buff,"char _vo_%d[%d+1];", a, obind[a].dtype >> 16);
	  break;
	case 1:
	  sprintf (buff,"short _vo_%d;", a);
	  break;
	case 2:
	  sprintf (buff,"int _vo_%d;", a);
	  break;
	case 3:
	  sprintf (buff,"double _vo_%d;", a);
	  break;
	case 4:
	  sprintf (buff,"float _vo_%d;", a);
	  break;
	case 5:
	  	sprintf (buff,"decimal(%s) _vo_%d;", decode_decimal_size_as_string(obind[a].dtype),a);
	  break;
	case 6:
	  sprintf (buff,"int _vo_%d;", a);
	  break;
	case 7:
	  sprintf (buff,"date _vo_%d;", a);
	  break;
	case 8:
	  if (A4GL_isyes(acl_getenv("MONEY_AS_MONEY"))) {
	  	sprintf (buff,"money _vo_%d;", a);
	  } else {
	  	if (A4GL_isyes(acl_getenv("MONEY_AS_DECIMAL"))) {
	  		sprintf (buff,"decimal(%s) _vo_%d;", decode_decimal_size_as_string(obind[a].dtype), a);
		} else {
	  		sprintf (buff,"money(%s) _vo_%d;", decode_decimal_size_as_string(obind[a].dtype),a);
		}
	   }
	  	break;
	case 9:
	  sprintf (buff,"Blah _vo_%d;", a);
	  break;
	case 10:
	  sprintf (buff,"datetime _vo_%d;",  a); // Datetimes can't be qualified in ecpg
	  break;
	case 11:
	  sprintf (buff,"interval _vo_%d;", a);
	  break;
	case 12:
	  sprintf (buff,"text _vo_%d;", a);
	  break;
	case 13:
	  sprintf (buff,"varchar _vo_%d;", a);
	  break;
	case 14:
	  sprintf (buff,"interval _vo_%d;", a);
	  break;
	}
	strcat(buff,buff_ind);
    }
	return buff;

}


void liblex_add_ibind(int dtype,char *var) {
	strcpy(ibind[ibindcnt].varname,var);
	ibind[ibindcnt].start_char_subscript=0;
	ibind[ibindcnt].end_char_subscript=0;
	ibind[ibindcnt].dtype=dtype;
	ibindcnt++;
}

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
	strcpy(buff, " ");
	strcat(buff,dt_qual(s>>4));
	strcat(buff," TO ");
	strcat(buff,dt_qual(s&0xf));
	return buff;

    case 8:
    case 5:                     /* decimal */
      return "(32,16)";

    case 0:
    case 13:
      sprintf (buff, "(%d)", s);
      return buff;

    case 14:
      sprintf (buff, " year to second(5)");
      return buff;
    }
  return "";
}

