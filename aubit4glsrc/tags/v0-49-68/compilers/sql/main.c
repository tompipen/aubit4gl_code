#include <stdio.h>
#ifdef NDEF
#include "ilist.h"
#include "y.tab.h"
extern char* yytext;

extern FILE *yyin;
int process(void) ;
char *sql_string;
int sql_type;

extern int was_ok=0;
#endif

extern int asql_yydebug;

main(int argc,char *argv[]) {
	char *snew;
	if (argc!=2) {
		printf("Usage : %s filename\n",argv[0]);
		exit(2);
	}
	snew=A4GLSQLCV_convert_file("POSTGRES",argv[1]);

	printf("%s\n",snew);
}


