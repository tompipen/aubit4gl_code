
code
/*

struct element {
	int lineno;
	char type;
	char *stmt;
	char *delim;
	char *fname;
};

*/


#include "simple.h"

extern FILE *unloadFile;
char delims[256];
char *delim;

int asql_unload_data(struct element *e) {
int raffected;
int b;
	delim=&delims[0];
	strcpy(delim,"|");

	if (e->delim) {
		if (strlen(e->delim)) {
			strcpy(delim,e->delim);
		}
	}

	unloadFile=fopen(e->fname,"w");

	if (unloadFile==0) {
		return -2;
	}

	raffected=0;
	display_mode_unload(1);
	if (execute_select_prepare()) {
		while (sqlca.sqlcode==0) {
			b=execute_sql_fetch(&raffected);
			if (b!=0) break;
		}
		if (sqlca.sqlcode!=100)  raffected=-1;
	} else {
		raffected=-1;
	}
	if (unloadFile) fclose(unloadFile);
	unloadFile=0;
	display_mode_unload(0);
	return raffected;
}



int asql_load_data(struct element *e) {

}



endcode
