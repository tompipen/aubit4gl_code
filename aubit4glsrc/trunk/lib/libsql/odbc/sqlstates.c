#include "a4gl_lib_sql_odbc_int.h"

struct s_state_lookup {
char *sqlstate;
int errno;
};

static struct s_state_lookup slookups[]={
{"24000",-11031},
{0,0}
};

int get_fake_error(char *sqlstate) {
int a;
for (a=0;slookups[a].sqlstate;a++) {
	if (strcmp(slookups[a].sqlstate,sqlstate)==0) {
			return slookups[a].errno;
	}
}
if (sqlstate[0]=='0' && sqlstate[1]=='0') return 0;
if (sqlstate[0]=='0' && sqlstate[1]=='1') return 0;

return -1;
}
