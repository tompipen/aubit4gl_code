

#include <stdio.h>
#include <getopt.h>

/*

#else
	struct option
	{
	# if (defined __STDC__ && __STDC__) || defined __cplusplus
	  const char *name;
	# else
	  char *name;
	# endif
	  int has_arg;
	  int *flag;
	  int val;
	};

#endif
*/


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

//#ifndef _NO_Y_TAB_H_
	//#include "rules/generated/y.tab.h"
//#endif

/* ==================== from a4gl_4glc_4glc.h ===================== */


/* ============================= in mk_states.c ======================= */
int allow_token_state(int yystate,int yytoken);

	/* ========================= in globals.c =========================== */
void dump_gvars (void);

	/* =========================== Implemented in 4glc.c ================= */
void rm_quote (char *s);
int read_globals (char *fname);
void rm_quotes (char *s);
int isGenStackInfo (void);
void a4gl_yyerror (char *s);


	/* ========================== Implemented in lexer.c ================= */

int mja_fgetc ();
void turn_state (int kw, int v);
void set_namespace (char *s);
	//int   yylex                           (void);

	//int   yylex                           (void *pyylval, int yystate);


    /* --------------------- from a4gl_4glc_compiledefs.h --------------------- */

	/* =========================== wantkw.c ================================= */

int wants_kw_token (int state, int kw);
int is_commandkw (int kw);

	/* ==================== rules/generated/states.c ==================== */
void start_state (char *s, int on_off);
void init_states (void);


	/* =========================== y.tab.c ============================== */
void set_clobber (char *c);

#ifndef _BISON_SIMPLE_INCL_	/* defiend in /usr/lib/bison.simple */
		/* int     yyparse                              (void); */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int a4gl_yyparse (void *);
#else
int a4gl_yyparse (void);
#endif
#endif
#endif

/* ============================= EOF ================================= */
