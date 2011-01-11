#include "a4gl_API_sqlparse_lib.h"
#include "a4gl_libaubit4gl.h"
#include "sql_compiler_util.h"
#include "a4gl_API_sqlparsecmd_lib.h"




struct command *processSQL(char *s);

int main(int argc, char *argv[]) {
struct command *c;
	c=A4GLPARSECMD_processSQL("UPDATE  tcommission SET     (hfav, hrat, hcom) = (( SELECT  chf_method, CASE chf_method WHEN '#' THEN chf_base WHEN '%' THEN chf_perc ELSE CASE WHEN chf_base + ((valu * chf_perc) / 100) <= DECODE(chf_floor, 0, -99.99, chf_floor) THEN chf_floor WHEN chf_base + ((valu * chf_perc) / 100) >= DECODE(chf_cap, 0, 99.99, chf_cap) THEN chf_cap ELSE chf_perc END END, CASE chf_method WHEN '#' THEN chf_base WHEN '%' THEN (valu * chf_perc) / 100 ELSE CASE WHEN chf_base + ((valu * chf_perc) / 100) <= DECODE(chf_floor, 0, -99.99, chf_floor) THEN chf_floor WHEN chf_base + ((valu * chf_perc) / 100) >= DECODE(chf_cap, 0, 99.99, chf_cap) THEN chf_cap ELSE chf_base + ((valu * chf_perc) / 100) END END FROM    settlement:comgrp_handlingfee a WHERE   chf_seri = hfee AND     chf_mop = mop )) WHERE      hfee IS NOT NULL");


	if (c) {
		printf("c->cmd_type=%d\n",c->cmd_data.type);
	} else {
		printf("Could not parse SQL\n");
	}
exit(0);
}
