#include "a4gl_lib_lex_esqlc_int.h"

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


void print_conversions (char i);
void make_sql_bind (char *sql, char *type);
void print_sql_type (int a, char ioro);
void print_sql_type_infx (int a, char ioro);
void printc (char *fmt, ...);
void printh (char *fmt, ...);
int esql_type (void);

static void print_sql_type_postgres (int a, char ioro);

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
		  print_sql_type (a, 'i');
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
		  	print_sql_type (a, 'o');

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
      		printc("struct BINDING native_binding_i[]={\n");
		if(ibindcnt==0) { printc("{0,0,0}"); }
		for (a=0;a<ibindcnt;a++) {
			printc("   %c{&_vi_%d,%d,%d}",comma,a,ibind[a].dtype&0xffff,ibind[a].dtype>>16);
			comma=',';
		}
 		printc("};\n");



	}

	if (strchr (type, 'o')) {
		char comma=' ';
      		printc("struct BINDING native_binding_o[]={\n");
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



void
print_sql_type (int a, char ioro)
{
  // Need to do some check to determine which ESQL/C to use...
  if (esql_type()==1) {
  	print_sql_type_infx (a, ioro);
  }
  if (esql_type()==2) {
  	print_sql_type_postgres (a, ioro);
  }
}


static void
print_sql_type_infx (int a, char ioro)
{

  if (ioro == 'i')
    {
      switch (ibind[a].dtype & 0xffff)
	{
	case 0:
	  printc ("char _vi_%d[%d+1];", a, ibind[a].dtype >> 16);
	  break;
	case 1:
	  printc ("short _vi_%d;", a);
	  break;
	case 2:
	  printc ("int _vi_%d;", a);
	  break;
	case 3:
	  printc ("double _vi_%d;", a);
	  break;
	case 4:
	  printc ("float _vi_%d;", a);
	  break;

	case 5:
	  printc ("decimal(%s) _vi_%d;", decode_decimal_size_as_string(ibind[a].dtype),a);
	  break;

	case 6:
	  printc ("int _vi_%d;", a);
	  break;

	case 7:
	  printc ("int _vi_%d;", a);
	  break;
	case 8:
	  printc ("money(%s) _vi_%d;", decode_decimal_size_as_string(ibind[a].dtype),a);
	  break;
	case 9:
	  printc ("Blah _vi_%d;", a);
	  break;
	case 10:
	  printc ("datetime _vi_%d;", a);
	  break;
	case 11:
	  printc ("interval _vi_%d;", a);
	  break;
	case 12:
	  printc ("text _vi_%d;", a);
	  break;
	case 13:
	  printc ("varchar _vi_%d;", a);
	  break;
	case 14:
	  printc ("interval _vi_%d;", a);
	  break;
	}
    }


  if (ioro == 'o')
    {
 	if (A4GL_isyes(acl_getenv("USE_INDICATOR"))) {
		printc("  short _voi_%d;",a);
	}

      switch (obind[a].dtype & 0xffff)
	{
	case 0:
	  printc ("char _vo_%d[%d+1];", a, obind[a].dtype >> 16);
	  break;
	case 1:
	  printc ("short _vo_%d;", a);
	  break;
	case 2:
	  printc ("int _vo_%d;", a);
	  break;
	case 3:
	  printc ("double _vo_%d;", a);
	  break;
	case 4:
	  printc ("float _vo_%d;", a);
	  break;
	case 5:
	  	printc ("decimal(%s) _vo_%d;", decode_decimal_size_as_string(obind[a].dtype),a);
	  	break;
	case 6:
	  printc ("int _vo_%d;", a);
	  break;
	case 7:
	  printc ("int _vo_%d;", a);
	  break;
	case 8:
	  	printc ("money(%s) _vo_%d;", decode_decimal_size_as_string(obind[a].dtype),a);
	  break;
	case 9:
	  printc ("Blah _vo_%d;", a);
	  break;
	case 10:
	  printc ("datetime _vo_%d;", a);
	  break;
	case 11:
	  printc ("interval _vo_%d;", a);
	  break;
	case 12:
	  printc ("text _vo_%d;", a);
	  break;
	case 13:
	  printc ("varchar _vo_%d;", a);
	  break;
	case 14:
	  printc ("interval _vo_%d;", a);
	  break;
	}
    }
  printc ("\n");

}



static void print_sql_type_postgres (int a, char ioro)
{

  if (ioro == 'i')
    {
      switch (ibind[a].dtype & 0xffff)
	{
	case 0:
	  printc ("char _vi_%d[%d+1];", a, ibind[a].dtype >> 16);
	  break;
	case 1:
	  printc ("short _vi_%d;", a);
	  break;
	case 2:
	  printc ("int _vi_%d;", a);
	  break;
	case 3:
	  printc ("double _vi_%d;", a);
	  break;
	case 4:
	  printc ("float _vi_%d;", a);
	  break;

	case 5:
	  printc ("decimal(%s) _vi_%d;", decode_decimal_size_as_string(ibind[a].dtype),a);
	  break;

	case 6:
	  printc ("int _vi_%d;", a);
	  break;

	case 7:
	  printc ("date _vi_%d;", a);
	  break;
	case 8:
	  printc ("money(%s) _vi_%d;", decode_decimal_size_as_string(ibind[a].dtype),a);
	  break;
	case 9:
	  printc ("Blah _vi_%d;", a);
	  break;
	case 10:
	  printc ("datetime _vi_%d;", a);
	  break;
	case 11:
	  printc ("interval _vi_%d;", a);
	  break;
	case 12:
	  printc ("text _vi_%d;", a);
	  break;
	case 13:
	  printc ("varchar _vi_%d;", a);
	  break;
	case 14:
	  printc ("interval _vi_%d;", a);
	  break;
	}
    }


  if (ioro == 'o')
    {
 	if (A4GL_isyes(acl_getenv("USE_INDICATOR"))) {
		printc("  short _voi_%d;",a);
	}

      switch (obind[a].dtype & 0xffff)
	{
	case 0:
	  printc ("char _vo_%d[%d+1];", a, obind[a].dtype >> 16);
	  break;
	case 1:
	  printc ("short _vo_%d;", a);
	  break;
	case 2:
	  printc ("int _vo_%d;", a);
	  break;
	case 3:
	  printc ("double _vo_%d;", a);
	  break;
	case 4:
	  printc ("float _vo_%d;", a);
	  break;
	case 5:
	  	printc ("decimal(%s) _vo_%d;", decode_decimal_size_as_string(obind[a].dtype),a);
	  break;
	case 6:
	  printc ("int _vo_%d;", a);
	  break;
	case 7:
	  printc ("date _vo_%d;", a);
	  break;
	case 8:
	  	printc ("money(%s) _vo_%d;", decode_decimal_size_as_string(obind[a].dtype),a);
	  	break;
	case 9:
	  printc ("Blah _vo_%d;", a);
	  break;
	case 10:
	  printc ("datetime _vo_%d;", a);
	  break;
	case 11:
	  printc ("interval _vo_%d;", a);
	  break;
	case 12:
	  printc ("text _vo_%d;", a);
	  break;
	case 13:
	  printc ("varchar _vo_%d;", a);
	  break;
	case 14:
	  printc ("interval _vo_%d;", a);
	  break;
	}
    }
  printc ("\n");

}


