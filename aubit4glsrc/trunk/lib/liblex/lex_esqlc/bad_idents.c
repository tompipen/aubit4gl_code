#include "a4gl_lib_lex_esqlc_int.h"


int bad_identifiers(char *s) {
        if (strcasecmp(s,"case")==0) return 1;
        if (strcasecmp(s,"switch")==0) return 1;
        if (strcasecmp(s,"continue")==0) return 1;
        if (strcasecmp(s,"if")==0) return 1;
        if (strcasecmp(s,"while")==0) return 1;
        if (strcasecmp(s,"do")==0) return 1;
        if (strcasecmp(s,"short")==0) return 1;
        if (strcasecmp(s,"long")==0) return 1;

	return 0;
}
