

#include <stdio.h>
#include <getopt.h>

#ifdef __MINGW32__
	/*
	   prevent MinGW headers that are not needed here from re-defining:
	   HIDE_WINDOW ABSOLUTE CONST RELATIVE DELETE ERROR TEXT IN
	   that we defined in rules/generated/kw.h
	 */
#undef HIDE_WINDOW
#undef ABSOLUTE
#undef CONST
#undef RELATIVE
#undef DELETE
#undef ERROR
#undef TEXT
#undef IN

#endif

#include "generated/kw.h"
#include "MemFile.h"

//#ifndef _NO_Y_TAB_H_
	//#include "rules/generated/y.tab.h"
//#endif


/* ==================== from a4gl_4glc_4glc.h ===================== */


/* ============================= in mk_states.c ======================= */
int allow_token_state(int yystate,int yytoken);


/* --------------------- from a4gl_4glc_compiledefs.h --------------------- */

	/* =========================== wantkw.c ================================= */

int wants_kw_token (int state, int kw);
int is_commandkw (int kw);

	/* ==================== rules/generated/states.c ==================== */
void start_state (char *s, int on_off);


	/* =========================== y.tab.c ============================== */
void set_clobber (char *c);

int a4gl_yyparse (void *);
/* ============================= EOF ================================= */
