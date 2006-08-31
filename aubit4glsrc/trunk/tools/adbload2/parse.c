#include <stdio.h>
#include "a4gl_dbload_int.h"

extern FILE *yyin;
extern int yylineno;
extern struct filedef *m_filedef;

int aclfgl_process(int n) {
char *a;
int ok;
A4GL_assertion (n!=1,"Process called with wrong number of parameters");

a=(char *)A4GL_char_pop();
A4GL_trim(a);
ok=parse(a);
free(a);
A4GL_push_int(ok);
return 1;

}



int parse(char *lv_cmd_file) {
  yyin = (FILE *) fopen (lv_cmd_file, "r");
  if (yyin == 0) {
        printf ("Error opening file : %s\n", lv_cmd_file);
	return 2;
  }

  if (a4gl_dbload_yyparse()!=0) {
        printf("Failed to parse\n");
  	return 0;
  }
  return 1;
}



void a4gl_dbload_yyerror(char *s) {
	printf("Error in dbload command file : %s @ line %d\n",s,yylineno);
}



int
yywrap (void)
{
  return 1;
  }



int is_column_name(char *s) {
int a;
struct s_field_pos_list *x;

if (m_filedef->delim!=0) {
	if (s[0]!='f'&&s[a]!='F') return 0;
	if (strlen(s)<=2) return 0; // just f, or f?
	
	for (a=1;a<strlen(s);a++) {
		if (s[a]<'0' || s[a]>'9') return 0;
	}

	// Yeah - its a column !
	return 1;
}

// its not a delimited file - so we'll need to go through our list
x=m_filedef->field_pos_list;
A4GL_assertion(x==0,"Invalid field_pos_list");

for (a=0;a<x->npos;a++) {
	if (strcmp(s,x->pos[a]->name)==0) {
		// Hey - got a match !
		sprintf(s,"f%02d",a+1);
		return 1;
	}
}

return 0;
}



char *conv_dbl(char *s) {
if (strchr(s,'"')) {
A4GL_assertion(1,"Not implemented - conv_dbl");
}
return s;
}
