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
# $Id: pack_xml.c,v 1.5 2012-07-10 11:36:33 mikeaubury Exp $
#*/

/**
 * @file
 *
 * We don't actually do much in here
 * we just use the name of the datatype specified
 * to identify the xdr routine to call
 * and then - call it...
 *
 *
 * @todo Doxygen comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "fgl.xnew.h"
#include "a4gl_API_packer_lib.h"
//#include "a4gl_libaubit4gl.h"
int A4GL_file_exists(char *fname);
int A4GL_delete_file(char *fname);
int A4GL_env_option_set (char *s);
int a_isprint(int a);

#include "a4gl_gzip.h"

FILE *ofile;
void *last_module=0;

void *current_module=0;

static int skip_var(char *s) ;
int yylex (void);


#ifdef __WIN32__
#ifdef strcpy
#undef strcpy
#endif
#ifdef strcat
#undef strcat
#endif
#endif
/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 *
 * @todo Describe function
 */
int
A4GLPACKER_initlib (void)
{
  return 1;
}

/**
 *
 * @todo Describe function
 */
int
A4GLPacker_A4GL_can_pack_all (char *name)
{
    return 1;
}



/*
   We don't need to worry about these two functions
   as we're doing the whole thing in one go using xdr
*/
int
A4GLPacker_A4GL_open_packer (char *fname, char dir,char *packname,char *version)
{
  return 1;
}

void
A4GLPacker_A4GL_close_packer (char dir)
{
  return;
}


/**
 *
 * @todo Describe function
 */
int
A4GLPacker_A4GL_pack_all (char *name, void *s, char *filename)
{
	if (strcmp(name,"module_definition")==0) {
		char buff[256];
		char *override;
			override=acl_getenv_not_set_as_0 ("OVERRIDE_PACKER_OUTPUT");
		if (!override) {
			override=acl_getenv_not_set_as_0("OVERRIDE_OUTPUT");
		}

		if (override) {
			strcpy(buff,override);
		} else {	
			if (!A4GL_env_option_set ("A4GL_LOCALOUTPUT")) {
				strcpy(buff,filename);
			} else {
				char *ptr;
			      ptr = filename;
      				if (rindex (ptr, '/')) {
          				ptr = rindex (ptr, '/') + 1;
        			}
				strcpy(buff,ptr);

			}
			strcat(buff,".xml");
		}
#ifdef HAVE_ZLIB
		if (!strstr(buff,".gz")) {
			strcat(buff,".gz");
		}
		ofile=A4GL_gzfopen(buff,"wb");
#else
		ofile=A4GL_gzfopen(buff,"wb");
#endif

		if (ofile) {
			struct module_definition *m;
			struct variable_list *v;
			struct variable_list *v2;
			int c;
			A4GL_gzfprintf(ofile,"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"); 
			A4GL_gzfprintf(ofile,"<!DOCTYPE module_definition SYSTEM \"module_def.dtd\">\n");
			int b=0;
			
			m=s;
			v=&m->imported_global_variables;
			v2=malloc(sizeof(t_variable_list));
			v2->variables.variables_val=malloc(sizeof(struct variable *) * v->variables.variables_len);
			for (c=0;c<v->variables.variables_len;c++) {
				if (!skip_var(v->variables.variables_val[c]->names.names.names_val[0].name))  {
					v2->variables.variables_val[b++]=v->variables.variables_val[c];
				}
			}
			v2->variables.variables_len=b;
			m->imported_global_variables.variables.variables.variables_val=v2->variables.variables_val;
			m->imported_global_variables.variables.variables.variables_len=v2->variables.variables_len;
			
			
			current_module=m;
	
	
			XMLWrite_module_definition(0,s);
			A4GL_gzfclose(ofile);
		} else {
			return 0;
		}
	}
	return 1;
//if (strcmp(name,"
}


/**
 *
 * @todo Describe function
 */
int
A4GLPacker_A4GL_unpack_all (char *name, void *s, char *filename)
{
	FILE *f;
	extern FILE *yyin;
	if (strcmp(name,"module_definition")==0) {
		char buff[256];
#ifdef USE_LEX_TABLES_FILE
		FILE *fp;
		fp=A4GL_mja_fopen("lexdata","r");

		 if (yytables_fload (fp)!=0) {
				printf("Unable to load lex tables\n");
			return 0;
		}
#endif

		strcpy(buff,filename); 
		f=A4GL_gzfopen(buff,"r"); // try it as it is...

		if (f==0) {
			// Well - that didn't work..
			if (!strstr(buff,".xml")) { // Does it have a '.xml' in it ? 
				// Nope- well - lets try adding one - see if that makes a difference...
				strcat(buff,".xml");
				f=A4GL_gzfopen(buff,"r");
			}
		}

        	if (!f) return 0;
 		yyin=f;
	
		if (!yylex()) {
			memcpy(s,last_module,sizeof(t_module_definition));
			A4GL_gzfclose(f);
			return 1;
        	} else {
			A4GL_gzfclose(f);
			return 0;
        	}
	}
	return 0;
}

void Call_Callback(char *s,char *n,void *data ) {
        if(strcmp(s,"module_definition")==0) {
		last_module=data;
        }
}



void gzoutstr(FILE *o, char *name, char *value) {
char buff[100000];
	sprintf(buff," %s='%s' ",name,value);
	A4GL_gzfwrite(buff,strlen(buff),1,o);
}

char *xml_encode(char *su) {
static char *buff=0;
static int last_len=0;
unsigned char *s;
int c;
int a;
int l;
int b;
s=(unsigned char *)su;
c=0;


l=strlen(su);
if (l>=last_len) {
        buff=realloc(buff, l*10+1);
        last_len=l;
}

b=0;
for (a=0;a<l;a++) {


        if (s[a]=='>') { buff[b++]='&'; buff[b++]='g'; buff[b++]='t'; buff[b++]=';';continue;}
        if (s[a]==0xa3) { buff[b++]='&'; buff[b++]='#'; buff[b++]='x'; buff[b++]='a';buff[b++]='3'; buff[b++]=';';continue;}
        if (s[a]=='\n') { buff[b++]='&'; buff[b++]='#'; buff[b++]='x'; buff[b++]='0';buff[b++]='a'; buff[b++]=';';continue;}
        //if (s[a]=='\t') { buff[b++]=' '; buff[b++]=' '; buff[b++]=' '; continue;}

        if (s[a]=='<') { buff[b++]='&'; buff[b++]='l'; buff[b++]='t'; buff[b++]=';';continue;}
        if (s[a]=='&') { buff[b++]='&'; buff[b++]='a';buff[b++]='m';buff[b++]='p';buff[b++]=';';continue;}
        if (s[a]=='\'') { buff[b++]='&'; buff[b++]='a';buff[b++]='p';buff[b++]='o';buff[b++]='s';buff[b++]=';';continue;}
        if (s[a]=='"') { buff[b++]='&'; buff[b++]='q';buff[b++]='u';buff[b++]='o';buff[b++]='t';buff[b++]=';';continue;}

        buff[b++]=s[a];
}

buff[b]=0;
return buff;

}

static int skip_var(char *s) {
	if (strcmp(s,"int_flag")==0) {return 1;}
	if (strcmp(s,"quit_flag")==0) {return 1;}
	if (strcmp(s,"a4gl_status")==0) {return 1;}
	if (strcmp(s,"time")==0) {return 1;}
	if (strcmp(s,"a4gl_sqlca")==0) {return 1;}
	if (strcmp(s,"notfound")==0) {return 1;}
	if (strcmp(s,"false")==0) {return 1;}
	if (strcmp(s,"true")==0) {return 1;}
	if (strcmp(s,"today")==0) {return 1;}
	if (strcmp(s,"fgl_user")==0) {return 1;}
	if (strcmp(s,"pageno")==0) {return 1;}
	if (strcmp(s,"lineno")==0) {return 1;}
	if (strcmp(s,"usrtime")==0) {return 1;}
	if (strcmp(s,"curr_hwnd")==0) {return 1;}
	if (strcmp(s,"curr_form")==0) {return 1;}
	if (strcmp(s,"err_file_name")==0) {return 1;}
	if (strcmp(s,"err_line_no")==0) {return 1;}
	if (strcmp(s,"curr_file_name")==0) {return 1;}
	if (strcmp(s,"curr_line_no")==0) {return 1;}
	if (strcmp(s,"err_status")==0) {return 1;}
	if (strcmp(s,"aiplib_status")==0) {return 1;}

return 0;
}

#ifdef HAVE_ZLIB
int mja_gzerror(FILE *f) {
int a;
const char *s;
	s=gzerror(f,&a);
	printf("%s\n",s);
	return a;
}
#endif


char *xml_encode_char(char c) {
static char buff[200];
	if (a_isprint(c)) {
		sprintf(buff,"%c",c);
		return buff;
	}
	sprintf(buff,"#%d",c);
	return buff;
}


char *A4GLPacker_A4GL_get_packer_ext(void) {
#ifdef HAVE_ZLIB
	return ".xml.gz";
#else
	return ".xml";
#endif
}

int A4GLPacker_A4GL_pack_remove_file(char* fname) {
char buff[2000];
	sprintf(buff,"%s%s",fname,A4GLPacker_A4GL_get_packer_ext());
	if (A4GL_file_exists(buff)) {
		A4GL_delete_file(buff);
	}
	return 1;
}
void A4GLPacker_A4GL_output_common_header(char* module,char* version) {
        fprintf (ofile,"<!-- Aubit4GL data file Type %s Version %s -->\n",module,version);
}

int A4GLPacker_A4GL_valid_common_header(char* module,char* version) {
         return 1;
}


/* =================================== EOF =========================== */
