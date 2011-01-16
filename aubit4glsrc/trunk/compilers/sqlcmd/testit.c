#include "a4gl_API_sqlparse_lib.h"
#include "a4gl_libaubit4gl.h"
#include "sql_compiler_util.h"
#include "a4gl_API_sqlparsecmd_lib.h"

extern int sqlparse_yydebug;


struct command *processSQL(char *s);

int main(int argc, char *argv[]) {
struct command *c;

//sqlparse_yydebug=1;

	c=A4GLPARSECMD_processSQL("SELECT site_tab.sit_site,site_tab.sit_name,site_tab.sit_add1, site_tab.sit_add2,site_tab.sit_add3,site_tab.sit_add4, site_tab.sit_phon,site_tab.sit_outc,site_tab.sit_dire, site_tab.sit_paus,site_tab.sit_aqui,site_tab.sit_padr, owner_tab.own_name,bureau.bur_buro,bureau.bur_name, commsdef.com_desc,till_tab.*,software.* FROM till_tab,site_tab,bureau,owner_tab,software,OUTER commsdef WHERE till_tab.til_till in {{{{{{{(,}using(mtilllist[pcounter].til_till)},}using(mtilllist[pcounter].til_till)},},}using(mtilllist[pcounter].til_till)}) AND site_tab.sit_site = till_tab.til_site AND bureau.bur_buro = site_tab.sit_buro AND owner_tab.own_owne = site_tab.sit_owne AND software.sof_appl = till_tab.til_appl AND commsdef.com_numm = site_tab.sit_comm ORDER BY site_tab.sit_site, till_tab.til_till");

	//c=A4GLPARSECMD_processSQL("SELECT  sit_site,  sit_add1,  sit_add2,  sit_add3,  sit_name,  sit_pcode,  dis_real  FROM site_tab, distributer  WHERE sit_site = ?  AND sit_disid = dis_id  AND sit_bilo NOT IN (SELECT ste_bilo FROM stor_excep)");


	if (c) {
		printf("c->cmd_type=%d\n",c->cmd_data.type);
	} else {
		printf("Could not parse SQL\n");
	}
exit(0);
}
