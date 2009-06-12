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
# $Id: fcompile.c,v 1.69 2009-06-12 11:31:40 mikeaubury Exp $
#*/

/**
 * @file
 * Main module from the form compiler.
 *
 * The form compiler parses a .per file and generates a compiled form
 *
 * The frm is the file used at run-time by x4gl
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/
#define yyparse a4gl_form_yyparse
#include "a4gl_fcompile_int.h"
#define DO_DEBUG
/*
=====================================================================
                    Variables definitions
=====================================================================
*/

//extern int as_c;		/* defined in libaubit4gl */
//int as_c=1;

//#ifdef YYDEBUG
extern int a4gl_form_yydebug;	/* defined in y.tab.c */
//#else /*  */
//      int yydebug;
//#endif /*  */

extern int yylineno;
extern long fileseek;
extern int yyleng;
extern char yytext[];
extern int chk4var;
extern int lcnt;
extern int lineno;
extern FILE *yyin;
extern char *outputfilename;	/* defined in libaubit4gl */
extern struct struct_scr_field *fld;	/* defined in libaubit4gl */
dll_import struct struct_form the_form;	/* defined in libaubit4gl */

int silent=0;
char outputfile[132];
int perform_mode=0;
int ignorekw = 0;
int colno = 0;
int lineno = 0;
int openwith = 0;
char currftag[256];
int fldno;
int scr = 0;
int newscreen = 0;
int fstart;
char *default_database = 0;
//int A4GLF_open_db (char *s);
int opened_db=0;
void usage (char *s);
void a4gl_form_yyerror (char *s);
char *rm_dup_quotes(char *s) ;
void bye(void ) ;

/*
=====================================================================
                    Functions definitions
=====================================================================
*/
int fcompile=0;



void bye(void ) {
  if (opened_db) {
        A4GL_close_database();
  }
}


/**
 * The main entry point to the form compiler
 *
 * @param argc The argument count
 * @param argv The argument values
 */
int
main (int argc, char *argv[])
{
  char a[128];
  char b[128];
  char c[128] = "";
  int waserr;
  char errfile[513];
  char d[128] = "";
  int cnt;
  int cnt_files = 0;

  A4GL_setarg0 (argv[0]);




  if (argc == 1)
    {
      usage (argv[0]);
    }

  A4GL_debug ("Initializing fcompile\n");
  A4GL_setenv("A4GL_UI","CONSOLE",1);
  A4GL_fgl_start(argc,argv);
  default_database=acl_getenv_not_set_as_0("DEFAULT_DATABASE");
  fcompile=0;
  if (strstr(argv[0],"fcompile"))  fcompile=1;


  /* load settings from config file(s): */
  //A4GL_build_user_resources ();
  strcpy (d, "");

  A4GL_set_as_c (0);
  if (A4GL_isyes(acl_getenv("FCOMPILE_SILENT"))) {
	  silent=1;
  }

  for (cnt = 1; cnt < argc; cnt++)
    {


      if (strcmp(argv[cnt],"-q")==0) {
	      	silent=1;
		continue;
      }
      if (strcmp(argv[cnt],"-s")==0) {
	      	silent=1;
		continue;
      }

      if (strcmp(argv[cnt],"-perform")==0) {
	      	perform_mode=1;
		continue;
      }
      if (strcmp(argv[cnt],"-?")==0) {
		usage(argv[0]);
		
      }

      if (strcmp (argv[cnt], "-v") == 0)
	{
	  A4GL_check_and_show_id ("4GL Form Compiler", argv[cnt]);
	  continue;
	}

      if (strcmp (argv[cnt], "-vfull") == 0)
	{
	  A4GL_check_and_show_id ("4GL Form Compiler", argv[cnt]);
	  continue;
	}
      if (strcmp (argv[cnt], "-o") == 0) {
	cnt++;
	A4GL_setenv("A4GL_OVERRIDE_PACKER_OUTPUT",argv[cnt],1);
	continue;
	}

      if (strcmp (argv[cnt], "-c") == 0)
      // compile to C, not to compiled form format
	{
	  A4GL_set_as_c ( 1);
	  continue;
	}

      if (strcmp (argv[cnt], "-d") == 0)
      // secify database name to be used while compiling form
	{
	  cnt++;
	  default_database = acl_strdup (argv[cnt]);
	  continue;
	}

      if (cnt_files == 0)
	{
	  strcpy (c, argv[cnt]);
	  cnt_files++;
	  continue;
	}

      if (cnt_files == 1)
	{
	  strcpy (d, argv[cnt]);
	  cnt_files++;
	  continue;
	}

    }

  if (strlen (c) == 0)
    {
      usage (argv[0]);
    }


  A4GL_bname (c, a, b);

  
  //does not work - attempting to compile form without specifying .per extension will fail:
  if (a[0] == 0)
    {
      strcat (c, ".per");
  	A4GL_bname (c, a, b);
    }


  if (strcmp (d, "") == 0)
    {
      outputfilename = acl_strdup (a);
    }
  else
    {
      outputfilename = acl_strdup (d);
    }


  if (!silent) {
  	A4GL_check_and_show_id ("4GL Form Compiler", "");
	printf("\nThe form '%s' will now be compiled\n\n\n",c);
  }


  yyin = A4GL_mja_fopen (c, "r");

  if (A4GL_isyes(acl_getenv("A4GL_YYDEBUG")) ){
  	a4gl_form_yydebug = 1;
  } else {
  	a4gl_form_yydebug = 0;
  }

  if (yyin == 0)
    {

      printf ("Error opening file : %s\n", c);
      exit (1);

    }
  A4GL_init_form ();

  atexit(bye);

  sprintf (errfile, "%s.err", outputfilename);
  A4GL_delete_file(errfile);
  A4GL_delete_compiled_form_file();

  waserr=a4gl_form_yyparse ();

  if (!silent) {
  	if (waserr) {
		  printf("    The form compilation was ** not ** successful.\nPlease look at the relevant .err file\n\n");
	  } else {
		  printf("    The form compilation was successful.\n\n");
	}
  }

  return waserr;
}

#ifdef DO_DEBUG
typedef union
{
  char str[1024];
  u_expression *expr;
}
YYSTYPE;

YYSTYPE yylval;





#endif


static int reposition_to_line(int lineno, FILE *yyin) {
      static char buff[512];
        int ln=0;
	int ld=0;
        // We've read the file completely - this is a post parse error...
        rewind(yyin);
        while (1) {
                if (feof(yyin)) break;
                memset(buff,0,sizeof(buff));
                fgets(buff,sizeof(buff),yyin);
                if (strchr(buff,'\n')) ln++;
                if (ln>lineno) break;
                ld=ftell (yyin);
                //ld=fpos;
        }
	return ld;

}

/**
 * Executed by the parser when it enconters some error
 *
 * @param s String with error message sended by the parser
 */
void
a4gl_form_yyerror (char *s)
{
  char errfile[256];
  FILE *f;
  long ld;
  ld = ftell(yyin); //buffpos ();
  ld=reposition_to_line(yylineno, yyin);
  sprintf (errfile, "%s.err", outputfilename);
  f = A4GL_write_errfile (yyin, errfile, ld - 1, yylineno);
  fprintf (f, "| %s", s);
  A4GL_write_cont (yyin);
if (!silent) {
  printf ("Error compiling %s.per - check %s.err (xline=%d yline=%d)\n",
	  outputfilename, outputfilename, lineno, yylineno);
#ifdef DO_DEBUG
  printf ("%s\n", yylval.str);
#endif
  }
  exit (2);
}

/********************************** same finction from 4glc.c :

void
yyerror (char *s)
{
  char errfile[256];
  FILE *f;
  long ld;
  char a;

  ld = ftell (yyin);
  sprintf (errfile, "%s.err", outputfile);
  a = 0;
  fseek (yyin, fpos, SEEK_SET);
  f = A4GL_write_errfile (yyin, errfile, ld, yylineno);
  fprintf (f, "| %s%s (%s)", s, errbuff, yytext);
  A4GL_write_cont (yyin);
  printf ("Error compiling %s.4gl - check %s.err\n", outputfile, outputfile);
  exit (2);
}

*********************************************************************/


/**
 *  Executed when the parser arrives the end of parsing 
 *
 *  @return 
 */
int
yywrap (void)
{
  return 1;
}


void clr_status(void) {
  A4GL_set_fcompile_err("");
  A4GL_set_a4gl_status(0);
}


void err_on_status(void) {
  if (A4GL_get_a4gl_status()!=0) {
      	a4gl_form_yyerror (A4GL_get_fcompile_err());
	
  }
                
}

/**
 *
 * @todo Describe function
 */
int
A4GLF_getdatatype_fcompile (char *col, char *tab)
{
  int a;
  A4GL_set_a4gl_status(0);
  a = A4GL_getdatatype (col, tab);

	err_on_status();
if (a==-1) {
      	a4gl_form_yyerror (A4GL_get_fcompile_err());
}


  A4GL_debug ("DATATYPE : %s.%s = %d (%x)\n", tab, col, a,a);

  if (a==DTYPE_VCHAR) a=DTYPE_CHAR;
  
  return a&0xffff;
}

/**
 *
 * @todo Describe function
 */
void
usage (char *s)
{
  printf ("Usage\n   %s [-c] [-s|-q] [-d dbname] [-v|-vfull] filename[.per] [path/compiledform.ext]\n\n", s);
  printf ("  -?        Display this help message\b\n");
  printf ("  -s,-q     Silent mode\n\n");
  printf ("  -v,-vfull Display version information\n\n");
  printf ("  -d dbname Use 'dbname' rather than the database name in the form\n\n");
  printf ("  -perform  Turn on 'Perform' compatibility (SQL forms)\n");
  printf ("               This doesnt implement the SQL functionality\n");
  printf ("               but still stores the data so it can be used by\n");
  printf ("               other aubit4gl tools (like dump_4gl)\n\n");
  printf ("  -c        Generates a .c file which can be linked with a 4gl program\n");
  printf ("               The 4gl program needs to call 'form_is_compiled' to use the form:\n");
  printf ("                eg.    call form_is_compiled(someform,\"MEMPACKED\",\"GENERIC\");\n");

  exit (0);
}

/**
 *
 * @todo Describe function
 */
int
A4GLF_open_db (char *s)
{

  opened_db=1;
  if (default_database == 0)
    {
      return A4GL_init_connection (s);
    }
  else
    {
      return A4GL_init_connection (default_database);
    }
}


char *rm_dup_quotes(char *s) {
char *x;
int a;
int c;
x=acl_strdup(s);
c=0;
for (a=0;a<strlen(s);a++) {
	if (s[a]=='"'&&s[a+1]=='"') continue;
	x[c++]=s[a];
}
x[c]=0;
return x;
}

int doing_4gl(void) {
	if (perform_mode==1) return 0;
	if (A4GL_isyes(acl_getenv("FGLFRMCOMPILE"))) return 1;
	if (A4GL_isno(acl_getenv("FGLFRMCOMPILE"))) return 0;
	if (fcompile) return 1;
	return 0;
}

int A4GL_check_compiled_form(void) {
int a;
int found;
int b;

if (strcmp(the_form.dbname,"formonly")!=0) {
	if (the_form.tables.tables_len==0) {
		fprintf(stderr,"Warning: DATABASE defined - but no tables used\n");
	}
}


  // Check that all field tags actually relate to things in the
  // attribute section 
  //
  for (a = 0; a < the_form.fields.fields_len; a++)
    {
	found=0;
	if (strcmp(the_form.fields.fields_val[a].tag,"_label")==0) {
	continue;
	}

	for (b=0;b<the_form.attributes.attributes_len;b++) {
		int c;
		int d;

		if (the_form.attributes.attributes_val[b].field_no==a) {
			found++;
			break;
		}

		// Check if its in a lookup instead...
		if (the_form.attributes.attributes_val[b].lookup.lookups.lookups_len==0) continue;

		for (c=0;c<the_form.attributes.attributes_val[b].lookup.lookups.lookups_len;c++) {
			struct s_lookups *s;
			s=the_form.attributes.attributes_val[b].lookup.lookups.lookups_val[c];
			for (d=0;d<s->lookups.lookups_len;d++) {
				if(strcmp(the_form.fields.fields_val[a].tag, s->lookups.lookups_val[d]->fieldtag )==0) {
					found++; break;}
			}


		}
		if (found) break;
	}
	
	if (!found) {
		char buff[256];
		sprintf(buff, "Tag '%s' has not been used", the_form.fields.fields_val[a].tag);
		a4gl_form_yyerror(buff);
		return 0;
        }
    }


return 1;

}


/**
 *  * Downshift a string.
 *   *
 *    * @param a The string to be downshifted.
 *     * @return A pointer to a staic buffer where the string downshifted is putted.
 *      */
char *
downshift (char *a)
{
  int i;
  static char buff[256];
  strcpy (buff, a);
  for (i = 0; i < strlen (buff); i++)
    {
      buff[i] = a4gl_tolower (buff[i]);
    }
  return buff;
}



// Process an 'INCLUDE' - typically used on a SYSCOLVAL 'INCLUDE' value
// as it would normally be parsed by the form compiler...
// 
//  test with something like 
//
// 	printf("'%s'\n", process_include("1,2, 3"));
// 	printf("'%s'\n", process_include("Null, \"Y\", \"N\""));
// 	printf("'%s'\n", process_include("NULL, -9999999 to 99999999"));
//
char *process_include(char *s) {
int a;
int b;
char inquote=0;
static char origbuff[20000];
static char buff[20000];
b=0;
memset(origbuff,0,sizeof(origbuff));
strcpy(origbuff,s);
s=origbuff;

buff[b++]='\n';
for (a=0;a<strlen(s);a++) {
	if (s[a]=='\'') {
		 if (inquote==0) { inquote='\''; continue; }
		 if (inquote=='\'') inquote=0; continue;
	}

	if (s[a]=='"') {
		if (inquote==0) { inquote='"'; continue; }
		if (inquote=='"') { inquote=0; continue; }
	}

	if (s[a]==' ' && s[a+1]=='t' && s[a+2]=='o' && s[a+3]==' ') {
			buff[b++]='\t';
			a+=3;	
			continue;
	}

	if (s[a]==' ' && ! inquote) continue;  // Skip any whitespace if not quoted...

	if (s[a]==',' && !inquote) {
			buff[b++]='\n';
			continue;
	}

	if (!inquote) {
		if (a4gl_tolower(s[a])=='n' && a4gl_tolower(s[a+1])=='u' && a4gl_tolower(s[a+2])=='l' && a4gl_tolower(s[a+3])=='l' ) {
			buff[b++]='N';
			buff[b++]='U';
			buff[b++]='L';
			buff[b++]='L';
			a+=3;
			continue;
		}
	}

	buff[b++]=s[a];
}
buff[b]=0;
return buff;
}



//********************************************************************************
//               LAYOUT ATTRIBUTE HANDLING
//********************************************************************************
// Rather than 'reinvent the wheel' - we'll use a pretend field 
// and add attributes to that for the layout attributes because
// we already have all the routines for doing that..
// What we'll then do - is copy these into a layout_attributes structure when
// we need to use those values..
struct struct_scr_field f_holder_for_layout_attributes;

void add_child(struct s_layout *parent, struct s_layout *child) {
	if (parent->children.children_len==0) {
		parent->children.children_val=NULL; /* just to make sure... */
	}
	parent->children.children_len++;
	parent->children.children_val=realloc(parent->children.children_val, sizeof(struct s_layout *)*parent->children.children_len);
	parent->children.children_val[parent->children.children_len-1]=child;
	
}

void add_bool_layout_attrib(enum FIELD_ATTRIBUTES_BOOL attrib) {
	A4GL_add_bool_attr(&f_holder_for_layout_attributes, attrib);
}
	

void add_str_layout_attrib(enum FA_ATTRIBUTES_STRING attrib, char *value)  {
	A4GL_add_str_attr(&f_holder_for_layout_attributes, attrib, strdup(value));
}

struct s_layout_attributes *get_layout_attrib(void ) {
	struct s_layout_attributes *la;
	la=malloc(sizeof(struct s_layout_attributes));
	la->str_attribs.str_attribs_len=f_holder_for_layout_attributes.str_attribs.str_attribs_len;
	la->str_attribs.str_attribs_val=f_holder_for_layout_attributes.str_attribs.str_attribs_val;
	la->bool_attribs.bool_attribs_len=f_holder_for_layout_attributes.bool_attribs.bool_attribs_len;
	la->bool_attribs.bool_attribs_val=f_holder_for_layout_attributes.bool_attribs.bool_attribs_val;
	return la;
}

void new_layout_attribs(void) {
	f_holder_for_layout_attributes.str_attribs.str_attribs_len=0;
	f_holder_for_layout_attributes.str_attribs.str_attribs_val=0;
	f_holder_for_layout_attributes.bool_attribs.bool_attribs_len=0;
	f_holder_for_layout_attributes.bool_attribs.bool_attribs_val=0;
}




//********************************************************************************
//            END OF LAYOUT ATTRIBUTE HANDLING
//********************************************************************************




/* ================================== EOF ============================= */
