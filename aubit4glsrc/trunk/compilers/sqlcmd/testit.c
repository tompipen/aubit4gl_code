#include "a4gl_API_sqlparse_lib.h"
#include "a4gl_libaubit4gl.h"
#include "sql_compiler_util.h"
#include "a4gl_API_sqlparsecmd_lib.h"




struct command *processSQL(char *s);

int main(int argc, char *argv[]) {
struct command *c;
	c=A4GLPARSECMD_processSQL("select * from systables where");
	if (c) {
		printf("c->cmd_type=%d\n",c->cmd_data.type);
	} else {
		printf("Could not parse SQL");
	}
exit(0);
}
