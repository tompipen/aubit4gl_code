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
# $Id: translate.c,v 1.2 2002-04-24 07:45:59 afalout Exp $
#
*/

/**
 * @file
 *
 * @todo Add Doxygen comments to file
 */

#include <stdio.h>
char *acl_getenv(char *);
#define stricmp strcasecmp


/***************************/
/* Translation definitions */
/***************************/
struct translate_string {
	char *from;
	char *to;
	char *identifier;
};

struct translate_string *translate_list=(void *)-1;
int translate_list_cnt=0;


char *translate(char *s) {
int a;
make_trans_list();
for (a=0;a<translate_list_cnt;a++) {
		if (strcmp(translate_list[a].from,s)==0) {
			debug("TRANSLATION FOUND for %s",s);

			if (translate_list[a].to!=0)         {
				debug("->%s\n",translate_list[a].to);
				return translate_list[a].to;
			}

			if (translate_list[a].identifier!=0) {
					return translate_list[a].identifier;
			}
			debug("Shouldn't happen");
		}
}
//
return 0;
}

#define TRANSLINESIZE 2048

make_trans_list() {
char *filename;
FILE *file;
char buff[TRANSLINESIZE];

 if (translate_list!=(void *)-1) return;
 translate_list=0;
 filename=(char *)acl_getenv("TRANSLATEFILE");

 if (filename==0) return;
 if (strlen(filename)==0) return;
 file=(FILE *)open_file_dbpath(filename);

 if (file==0) {
		printf("Warning: Unable to locate translation file\n");
		return;
 }


 while (1) {
	int a;
	char *ptr;
	char *ptr2;

	fgets(buff,TRANSLINESIZE,file);
	if (feof(file)) break;
	stripnl(buff);
	if (buff[0]=='#') continue;
	
	for (a=1;a<strlen(buff)-1;a++) {
		if (buff[a]==':'&&buff[a+1]=='='&&buff[a-1]!='/') {
			ptr2=&buff[a+2];
			buff[a]=0;
			add_translate(1,buff,ptr2,0);
		}

		if (buff[a]==':'&&buff[a+1]=='>'&&buff[a-1]!='/') {
			ptr2=&buff[a+2];
			buff[a]=0;
			add_translate(2,buff,ptr2,0);
		}


	}
 }
}

char **list_of_strings=0;
int list_of_strings_len=0;


dumpstring(char *s,long n,char *fname) {
static FILE *f;
static int ident=0;
char buff[256];
char buff_str[256];
int id;

int a;

	if (strlen(acl_getenv("DUMPSTRINGS"))) {
		if (f==0) {
			f=fopen("strings.lang","w");
		}
		if (f==0) return;

		for (a=0;a<list_of_strings_len;a++) {
			if (strcmp(list_of_strings[a],s)==0) return;
		}

		list_of_strings_len++;
		list_of_strings=(char **)realloc(list_of_strings,list_of_strings_len*sizeof(char *));
		list_of_strings[list_of_strings_len-1]=s;

		if (stricmp((char *)acl_getenv("DUMPSTRINGS"),"ident")==0) {
			fprintf(f,"%s:>%d\n",s,ident++);
		} else {
			fprintf(f,"%s:=\n",s);
		}
	}
}


//moved from formwrite2.c and lexer.c:

void add_translate(int mode,char * from,char * to, int quote) {
        char buff[2048];

        translate_list_cnt++;
        translate_list=(struct translate_string *)realloc(translate_list,sizeof( struct translate_string)*translate_list_cnt);
        translate_list[translate_list_cnt-1].from=strdup(from);
        debug("Adding %s -> %s mode %d",from,to,mode);
        if (mode==1) {
	        if (quote==0) {
				//formwrite2.c:
				sprintf(buff,"%s",to);
            } else {
                //lexer.c:
				sprintf(buff,"\"%s\"",to);
            }

                translate_list[translate_list_cnt-1].to        =strdup(buff);
                translate_list[translate_list_cnt-1].identifier=0;
        } else {
			if (quote==0) {
				//formwrite2.c:
				sprintf(buff,"get_translated_id:%s",to);
            } else {
				//lexer.c:
				sprintf(buff,"get_translated_id(\"%s\")",to);
            }

                translate_list[translate_list_cnt-1].identifier=strdup(buff);
                translate_list[translate_list_cnt-1].to        =0;
        }
}




