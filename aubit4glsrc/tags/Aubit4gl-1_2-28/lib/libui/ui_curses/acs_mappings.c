#include "a4gl_lib_ui_tui_int.h"


static int decode_acs_name(char *s) ;

struct s_acs_remapping {
        int from_ascii;
        int to_acs;
};

struct s_acs_remapping *A4GL_acs_remapping =0;
int nmappings=0;

#define DECODE_ACS(y,x) if (strcmp(s,y)==0) { return x;}

static void add_mapping(int ascii_val, int to_acs) {
	nmappings++;
	A4GL_acs_remapping=realloc(A4GL_acs_remapping, sizeof(A4GL_acs_remapping[0])*nmappings);
	A4GL_acs_remapping[nmappings-1].from_ascii=ascii_val;
	A4GL_acs_remapping[nmappings-1].to_acs=to_acs;
}

int A4GL_has_acs_mapping(int ascii_val) {
int a;
for (a=0;a<nmappings;a++) {
	if (A4GL_acs_remapping[a].from_ascii==ascii_val) {
		return A4GL_acs_remapping[a].to_acs;
	}
}
return 0;
}


int UILIB_aclfgl_aclfgl_add_acs_mapping(int n) {
int asciival;
char *to_str;
int to_acs;
 A4GL_chkwin ();
if (n!=2) {
	return 0;
}
asciival=A4GL_pop_int();
A4GL_upshift_stk();
to_str=A4GL_char_pop();
to_acs=decode_acs_name(to_str);
if (to_acs==0) {return 0;}
add_mapping(asciival, to_acs);
free(to_str);
return 0;
}


static int decode_acs_name(char *s) {
	if (A4GL_strstartswith(s,"ACS_")) {
		s+=4;
	}

	DECODE_ACS( "ULCORNER", ACS_ULCORNER )
	DECODE_ACS(  "LLCORNER", ACS_LLCORNER )
	DECODE_ACS(  "URCORNER", ACS_URCORNER )
	DECODE_ACS(  "LRCORNER", ACS_LRCORNER )
	DECODE_ACS(  "LTEE", ACS_LTEE )
	DECODE_ACS(  "RTEE", ACS_RTEE )
	DECODE_ACS(  "BTEE", ACS_BTEE)
	DECODE_ACS(  "TTEE", ACS_TTEE )
	DECODE_ACS(  "HLINE", ACS_HLINE )
	DECODE_ACS(  "VLINE", ACS_VLINE )
	DECODE_ACS(  "PLUS", ACS_PLUS )
	DECODE_ACS(  "S1", ACS_S1 )
	DECODE_ACS(  "S9", ACS_S9 )
	DECODE_ACS(  "DIAMOND", ACS_DIAMOND )
	DECODE_ACS(  "CKBOARD", ACS_CKBOARD )
	DECODE_ACS(  "DEGREE", ACS_DEGREE )
	DECODE_ACS(  "PLMINUS", ACS_PLMINUS )
	DECODE_ACS(  "BULLET", ACS_BULLET )
	DECODE_ACS(  "LARROW", ACS_LARROW )
	DECODE_ACS(  "RARROW", ACS_RARROW )
	DECODE_ACS(  "DARROW", ACS_DARROW )
	DECODE_ACS(  "UARROW", ACS_UARROW )
	DECODE_ACS(  "BOARD", ACS_BOARD )
	DECODE_ACS(  "LANTERN", ACS_LANTERN )
	DECODE_ACS(  "BLOCK", ACS_BLOCK )
#ifdef ACS_S3
	DECODE_ACS(  "S3", ACS_S3 )
	DECODE_ACS(  "S7", ACS_S7 )
	DECODE_ACS(  "LEQUAL", ACS_LEQUAL )
	DECODE_ACS(  "GEQUAL", ACS_GEQUAL )
	DECODE_ACS(  "PI", ACS_PI )
	DECODE_ACS(  "NEQUAL", ACS_NEQUAL )
	DECODE_ACS(  "STERLING", ACS_STERLING )
#endif

return 0;
}
