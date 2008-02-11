#include <stdlib.h>
#include <string.h>
#include "a4gl_4glc_int.h"

extern int yylineno;
struct s_cursors {
	char *name;
	int  type;
	int  usage;
	int  defined;
	//char *prep;
};

struct s_cursors *curs=0;
int cursors_cnt=0;

void A4GL_cursor_put_or_flush(struct expr_str *s) ;


char *decode_cursorname(struct expr_str *s_i) {
char *s;
	if (s_i->expr_type==ET_EXPR_IDENTIFIER) {
		s=s_i->expr_str_u.expr_string;
	} else {
		static char buff[256];
		struct expr_str *s2;
		s2=s_i->expr_str_u.expr_expr;
		switch (s2->expr_type) {
			case ET_E_V_OR_LIT_STRING:
				sprintf(buff, "%s",s2->expr_str_u.expr_string);
				s=buff;
				break;
			default: 
				sprintf(buff, "%s",expr_as_string_when_possible(s2));
				s=buff;
				break;
		}
	}
	return s;
}



static int find_cursor(struct expr_str *s_i) {
	int a;
	char *s;
	s="@FIXME";

	s=decode_cursorname(s_i);

	if (curs==0) return -1;
	for (a=0;a<cursors_cnt;a++) {

		if (strcmp(s,curs[a].name)==0) {
					return a;
		}
	}
	return -1;
}


static int add_cursor(struct expr_str *s,int type,int u,int d) {
	int lb;
	cursors_cnt++;
	curs=acl_realloc(curs,sizeof (struct s_cursors)* cursors_cnt);
	  lb=cursors_cnt-1;
	  curs[lb].name= decode_cursorname(s);
	  curs[lb].type=type;
	  curs[lb].usage=u;
	  curs[lb].defined=d;
	  //curs[lb].prep=0;
	 return lb;
}


void A4GL_cursor_fetch(struct expr_str *s,struct s_fetch_place *fp) {
	int a;
	a=find_cursor(s);
	if (a>=0) {
		  curs[a].usage++;
		return;
	}
	add_cursor(s,'S',1,0);
}


void A4GL_cursor_current(struct expr_str *s) {
	int a;
	a=find_cursor(s);
	if (a>=0) {
		  curs[a].usage++;
		return;
	}
	add_cursor(s,'S',1,0);
}

void A4GL_cursor_flush(struct expr_str *s) {
	A4GL_cursor_put_or_flush(s);
}

void A4GL_cursor_put_or_flush(struct expr_str *s) {
	int a;
	a=find_cursor(s);
	if (a>=0) {
		  if (curs[a].type=='S') {
			if (A4GLSQLCV_check_requirement("EMULATE_INSERT_CURSOR")) {
				PRINTF("Warning - cursor was previously thought to be a SELECT cursor\n");
				PRINTF("but now turns out to be an INSERT cursor.");
				PRINTF("You will need to add \n   PRAGMA EMULATE INSERT CURSOR FOR <cursorname>\nto the top of your module\n");
				a4gl_yyerror("Change in cursor type - please use PRAGMA EMULATE INSERT CURSOR FOR <cursorname>");
			}
		  }
		  curs[a].type='I';
		  curs[a].usage++;
		  return;
	}
	add_cursor(s,'S',1,0);
}

/*
void A4GL_insert_cursor_prep(struct expr_str *cname,char *stmt) {
int a;
a=find_cursor(cname);
if (a==-1) return;
curs[a].prep=acl_strdup(stmt);
if (strncasecmp(stmt,"insert",6)==0) {
	curs[a].type='I';
}
}
*/

void A4GL_cursor_defined(struct expr_str *s,char type) {
	int a;
	a=find_cursor(s);
	if (a>=0) {
		curs[a].defined++;
		return;
	}
	add_cursor(s,type,0,1);
}


void A4GL_cursor_is_insert(void) {
	A4GL_assertion(cursors_cnt==0,"No cursor added yet");
	
	if (curs[cursors_cnt-1].type==0) {
			curs[cursors_cnt-1].type='I';
	}
}

void A4GL_cursor_is_select(void) {
	if (curs[cursors_cnt-1].type==0) curs[cursors_cnt-1].type='S';
}

char A4GL_cursor_type(struct expr_str *s) {
	int a;
	
	a=find_cursor(s);
	if (a==-1) return 0;
	return curs[a].type;
}

/*
char *A4GL_get_insert_prep(struct expr_str *s) {
	int a;
	if (curs==0) return 0;
	a=find_cursor(s);
	if (a==-1) {
		return 0;
	}
	return curs[a].prep;
}
*/
