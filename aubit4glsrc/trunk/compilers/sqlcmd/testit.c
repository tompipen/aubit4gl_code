#include "a4gl_API_sqlparse_lib.h"
#include "a4gl_libaubit4gl.h"
#include "sql_compiler_util.h"
#include "a4gl_API_sqlparsecmd_lib.h"




struct command *processSQL(char *s);

int main(int argc, char *argv[]) {
struct command *c;
	c=A4GLPARSECMD_processSQL("UPDATE  settlement SET     set_effective_date = set_effective_date + NVL(( SELECT  (a.num - today.num) / 2 FROM    site_settle_issu, tnum a, tnum today WHERE   ssi_seri = set_bacs_from * -1 AND     today.num = ? AND     a.num > today.num AND     substr(ssi_comm_freq, a.num, 1) = 'Y' AND     NOT EXISTS ( SELECT  1 FROM    tnum b WHERE   b.num > today.num AND     substr(ssi_comm_freq, b.num, 1) = 'Y' AND     b.num < a.num ) ), 0) WHERE   set_seri IN ( SELECT  set FROM    tset )");

	if (c) {
		printf("c->cmd_type=%d\n",c->cmd_data.type);
	} else {
		printf("Could not parse SQL\n");
	}
exit(0);
}
