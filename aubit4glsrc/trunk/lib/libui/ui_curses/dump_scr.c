#include <stdio.h>
#include "a4gl_lib_ui_tui_int.h"
int screen_height(void);


FILE *f;


int aclfgl_aclfgl_dump_screen(int n) {
int sh;
int sw;
int x,y;
int attr;
char *ptr=0;
WINDOW *w;
int mode=1;
char *buff;

//w=find_pointer ("screen", WINCODE);
w=curscr;

if (n==1) {
	ptr=char_pop();
}

if (n==2) {
	mode=pop_int();
	ptr=char_pop();
}

trim(ptr);

if (mode==3) {
	scr_dump(ptr);
	return 0;
}

sh=screen_height();
sw=screen_width();

f=fopen(ptr,"w");
if (f==0) {
	debug("Unable to open dump file");
	return 0;
}

for (y=0;y<sh;y++) {
	for (x=0;x<sw;x++) {

		attr=mvwinch(w,y,x);

		if (mode==0) {
			buff=(char *)&attr;
			/* @todo - Fix for different ENDISMS */
			fprintf(f,"%c%c",buff[2],attr&255);
		}

		if (mode==1) {
			if (attr==ACS_VLINE) { attr=(int)'|'; }
			if (attr==ACS_HLINE) { attr=(int)'-'; }
			if (attr==ACS_LLCORNER) { attr=(int)'+'; }
			if (attr==ACS_LRCORNER) { attr=(int)'+'; }
			if (attr==ACS_URCORNER) { attr=(int)'+'; }
			if (attr==ACS_ULCORNER) { attr=(int)'+'; }
			fprintf(f,"%c",attr&255);
		}
	}
	fprintf(f,"\n");
}
fclose(f);
return 0;
}
