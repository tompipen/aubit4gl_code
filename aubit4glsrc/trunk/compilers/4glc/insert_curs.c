#include <stdlib.h>
#include <string.h>
#include "a4gl_4glc_int.h"

extern int yylineno;
struct s_cursors {
	char *name;
	int  type;
	int  usage;
	int  defined;
	char *prep;
	
};

struct s_cursors *curs=0;
int cursors_cnt=0;

void A4GL_cursor_put_or_flush(char *s) ;

static int find_cursor(char *s) {
	int a;
	if (curs==0) return -1;
	for (a=0;a<cursors_cnt;a++) {

		if (strcmp(s,curs[a].name)==0) {
					return a;
		}
	}
	return -1;
}


static int add_cursor(char *s,int type,int u,int d) {
	int lb;
	cursors_cnt++;
	curs=acl_realloc(curs,sizeof (struct s_cursors)* cursors_cnt);
	  lb=cursors_cnt-1;
	  curs[lb].name=acl_strdup(s);
	  curs[lb].type=type;
	  curs[lb].usage=u;
	  curs[lb].defined=d;
	  curs[lb].prep=0;
	 return lb;
}


void A4GL_cursor_fetch(char *s) {
	int a;
	a=find_cursor(s);
	if (a>=0) {
		  curs[a].usage++;
		return;
	}
	add_cursor(s,'S',1,0);
}


void A4GL_cursor_current(char *s) {
	int a;
	a=find_cursor(s);
	if (a>=0) {
		  curs[a].usage++;
		return;
	}
	add_cursor(s,'S',1,0);
}

void A4GL_cursor_flush(char *s) {
	A4GL_cursor_put_or_flush(s);
}

void A4GL_cursor_put_or_flush(char *s) {
	int a;
	a=find_cursor(s);
	if (a>=0) {
		  if (curs[a].type=='S') {
			if (A4GLSQLCV_check_requirement("EMULATE_INSERT_CURSOR")) {
				printf("Warning - cursor %s was previously thought to be a SELECT cursor\n",s);
				printf("but now turns out to be an INSERT cursor.");
				printf("You will need to add \n   PRAGMA EMULATE INSERT CURSOR FOR %s\nto the top of your module\n",s);
				a4gl_yyerror("Change in cursor type - please use PRAGMA EMULATE INSERT CURSOR FOR <cursorname>");
			}
		  }
		  curs[a].type='I';
		  curs[a].usage++;
		  return;
	}
	add_cursor(s,'S',1,0);
}


void A4GL_insert_cursor_prep(char *cname,char *stmt) {
int a;
a=find_cursor(cname);
if (a==-1) return;
curs[a].prep=acl_strdup(stmt);
}

void A4GL_cursor_defined(char *s,char type) {
	int a;
	a=find_cursor(s);
	if (a>=0) {
		curs[a].defined++;
		return;
	}
	add_cursor(s,type,0,1);
}


void A4GL_cursor_is_insert(void) {
	if (curs[cursors_cnt-1].type==0) {
			curs[cursors_cnt-1].type='I';
	}
}

void A4GL_cursor_is_select(void) {
	if (curs[cursors_cnt-1].type==0) curs[cursors_cnt-1].type='S';
}

char A4GL_cursor_type(char *s) {
	int a;
	a=find_cursor(s);
	if (a==-1) return 0;
	return curs[a].type;
}


char *A4GL_get_insert_prep(char *s) {
	int a;
	a=find_cursor(s);
	if (a==-1) return 0;
	return curs[a].prep;
}
