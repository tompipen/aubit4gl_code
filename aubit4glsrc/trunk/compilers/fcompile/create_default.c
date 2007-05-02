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
# $Id: 
#*/

/**
 * @file
 * Generate a default source form file (.per)  with all the fields of the 
 * specified table(s) 
 *
 * This file can be then 'compiled' with fcompile
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/
#include <stdio.h>
#include "a4gl_libaubit4gl.h"

#define SCR_LINES 20;  
/*
=====================================================================
                    Variables definitions
=====================================================================
*/
extern struct {
long sqlcode;
char sqlerrm [72+1];
char sqlerrp [8+1];
long sqlerrd[6];
char sqlawarn [8+1];
char sqlstate [9+1];
} a4gl_sqlca;

FILE *file_out=0;
char outfile[256];
char tabname[256][256];
int tabcnt=0;
char dbname[256];
char **attribs;
int attribs_cnt=0;

/*
=====================================================================
                    Function propotypes
=====================================================================
*/
static int get_size(int dtype,int size);
static char *spaces(int dtype,int size,char *id);
void usage(char *progname);
static void incbuff(char *s);
static char *get_id(int dtype,int size);

/**
 *  Calculate the width of the screen field
 *
 *  @param dtype     Type of the field
 *  @param size      Size of the field
 *  @return          Fild width in the screen
 */
static int get_size(int dtype,int size) {
switch(dtype ) {
	case DTYPE_CHAR: 	return size;
	case DTYPE_SMINT: 	return  5;
	case DTYPE_INT: 	return  10;
	case DTYPE_FLOAT: 	return  10;
	case DTYPE_SMFLOAT: 	return  10;
	case DTYPE_DECIMAL: 	return  16;
	case DTYPE_SERIAL: 	return  10;
	case DTYPE_DATE: 	return  12;
	case DTYPE_MONEY: 	return  17;
	case DTYPE_DTIME: 	return  17;
	case DTYPE_BYTE: 	return  20;
	case DTYPE_TEXT: 	return  20;
	case DTYPE_VCHAR: 	return size; 
	case DTYPE_INTERVAL: 	return 20; 
}
return 10;
}

/**
 *  Calculate the spaces needed to pad for the field size
 *
 *  @param dtype     Type of the field
 *  @param size      Size of the field
 *  @param id        Name of the field tag
 *  @return  String with the needed spaces for the width of the field
 */
static char *spaces(int dtype,int size,char *id) {
static char buff[1024];
int n;
n=get_size(dtype,size);   // Size if the field
n-=strlen(id);   // Substract the size of the tag
if (n>=1023) n=1023;
memset(buff,' ',1024);
buff[n]=0;
return buff;
}

/**
 *  Increment the field count by tag size
 *
 *  @param s      Generate next tag number/name
 */
static void incbuff(char *s) {
int a;
int b;
char buff[256];

	if (strlen(s)==1) {
		if (s[0]=='z') {
			printf("Too many one length fields\n");
			exit (1);
		}
		s[0]=s[0]+1;
		return;
	}
	
	b=atoi(&s[1]);
	b++;
	
	sprintf(buff,"%c%*d",s[0],(int)strlen(s)-1,b);
	
	if (strlen(buff)>strlen(s)) {
		if (s[0]=='z') {
			printf("Run out of %d length fields\n",(int)strlen(s));
			exit(1);
		}
		s[0]++;
		b=0;
		sprintf(buff,"%c%*d",s[0],(int)strlen(s)-1,b);
	}

	strcpy(s,buff);
	for (a=0;a<strlen(s);a++) {
		if (s[a]==' ') s[a]='0';
	}

}


/**
 *  Calculate the name of the tag
 *
 *  @param dtype     Type of the field
 *  @param size      Size of the field
 *  @return  String with the name of the screen tag
 */
char * get_id(int dtype,int size) {
static char buff[4][20]={"a","a0","a00","f000"};
static int used[4]={0,0,0,0};
size=get_size(dtype,size);
size--;
if (size>3) size=3;
if (used[size]) incbuff(buff[size]);

used[size]=1;

return buff[size];
}


/**
 *  Show usage information
 *
 *  @param progname      Name of this runable
 */
void usage(char *progname) {
	printf("Usage\n%s -d dbname -t tabname [-t tabname ..] [-o outputfile] [-l maxlines] \n",progname);
	exit(0);
}

/**
 *  Show usage information
 *
 *  @param argc      Number of arguments to this program
 *  @param argv      Array of arguments to this program
 */
int main(int argc,char *argv[]) {
int a;
int lineno;
int max_lines=0;

int scr_height = atoi (acl_getenv ("LINES"));

if (scr_height < 10) max_lines = SCR_LINES
else max_lines = scr_height - 4;


strcpy(outfile,"");
strcpy(dbname,"");

for (a=0;a<255;a++) {
	strcpy(tabname[a],"");
}
	
if (argc==1) {
	usage(argv[0]);
}

for (a=1;a<argc;a++) {
	if (strcmp(argv[a],"-?")==0) {
		usage(argv[0]);
	}

	if (strcmp(argv[a],"-d")==0) {
			strcpy(dbname,argv[a+1]);
			a++;
			continue;
	}

	if (strcmp(argv[a],"-o")==0) {
			strcpy(outfile,argv[a+1]);
			a++;
			continue;
	}

	if (strcmp(argv[a],"-t")==0) {
			strcpy(tabname[tabcnt++],argv[a+1]);
			a++;
			continue;
	}

	if (strcmp(argv[a],"-l")==0) {
            if (sscanf(argv[a+1], "%d", &max_lines) != 1) max_lines=SCR_LINES;
			a++;
			continue;
	}

	printf("Unknown option : %s\n",argv[a]);
	exit(1);
}


if (strlen(dbname)==0) {
	printf("No database specified\n");
	exit(1);
}

if (tabcnt==0) {
	printf("No tables specified\n");
	exit(1);
}



if (strlen(outfile)) {
    if (!strstr(outfile,".per")) {
        strcat(outfile,".per");
    }
	file_out=fopen(outfile,"w");
	if (file_out==0) {
		printf("Unable to open output file (%s)\n",outfile);
		exit(2);
	}
} else {
	file_out=stdout;
}

A4GL_fgl_start(argc,argv);

A4GLSQL_init_connection(dbname);
if (a4gl_sqlca.sqlcode!=0) {
	printf("Unable to open database(%s)\n",dbname);
	exit(1);
}

A4GL_trim(dbname);
fprintf(file_out,"database %s\n",dbname);

lineno=0;

for (a=0;a<tabcnt;a++) {
	int idtype;
	int isize;
	char *ccol;
	char *id;
	char buff[256];
	int rval;

	rval = A4GLSQL_get_columns (tabname[a], "", &idtype, &isize);
	if (rval==0) {
		printf("Can't find table %s in database\n",tabname[a]);
		exit(0);
	}
	fprintf(file_out,"screen\n");
	fprintf(file_out,"{\n");

	while (1) {
		int use_wordwrap=0;
		char *p;
		rval = A4GLSQL_next_column (&ccol, &idtype, &isize);
		A4GL_trim(ccol);
		if (rval==0) break;
        lineno++;
        if (lineno >= max_lines) {
	        fprintf(file_out,"}\n");
	        fprintf(file_out,"screen\n");
	        fprintf(file_out,"{\n");
            lineno=1;
        }
		fprintf(file_out,"%-19.19s",ccol);
		fprintf(file_out,"[");
		id=get_id(idtype,isize);
		p=spaces(idtype,isize,id);
		while (strlen(p)>43) {
			char buff[2000];
			strncpy(buff,p,43);
			buff[43]=0;
			p+=43;
			strncpy(buff,id,strlen(id));
			fprintf(file_out,"%s]\n",buff);
			fprintf(file_out,"                   [");
			use_wordwrap++;
			if (strlen(p)<43) {
				p=strdup("                                       ");
			}
            lineno++;
		}
	
		fprintf(file_out,"%s",id);
		fprintf(file_out,"%s]\n",p);
		if (use_wordwrap) {
			sprintf(buff,"%s = %s.%s, wordwrap;",id,tabname[a],ccol);
		} else {
			sprintf(buff,"%s = %s.%s;",id,tabname[a],ccol);
		}
		attribs_cnt++;
		attribs=realloc(attribs,sizeof(char *)*attribs_cnt);
		attribs[attribs_cnt-1]=acl_strdup(buff);
	}
	A4GLSQL_end_get_columns ();

	fprintf(file_out,"}\n");

}


fprintf(file_out,"end\n");
fprintf(file_out,"tables\n");

for (a=0;a<tabcnt;a++) {
	fprintf(file_out,"%s\n",tabname[a]);
}
fprintf(file_out,"attributes\n");
for (a=0;a<attribs_cnt;a++) {
	fprintf(file_out,"%s\n",attribs[a]);
}
fprintf(file_out,"end\n");
if (strlen(outfile)) { fclose(file_out); }
return 0;
}
