define lines array[30] of char(80)
code


#include <stdio.h>


extern FILE *out;
extern int outlines;
extern char outfname[255];
#define DISPLAY_LINES 19

endcode

FUNCTION paginate() 
define buff char(255)
define lv_cnt integer
define lv_a integer
define lv_action integer

let lv_cnt=0

set pause mode on

code
{
FILE *in;
FILE *out2;
if (out) {
	fclose(out);
	out=0;
}
in=fopen(outfname,"r");

rewind(in);
while (1) {

	if (lv_cnt>=DISPLAY_LINES) break;
	strcpy(buff,"");
	fgets(buff,sizeof(buff),in);
	if (feof(in)) break;
	A4GL_debug("PAGINATE : %s",buff);
	strcpy(lines[lv_cnt],buff);
	lv_cnt++;
	outlines--;
endcode
	DISPLAY lines[lv_cnt] at lv_cnt+5,1
code
}

if (lv_cnt==0) outlines=0;
endcode
code
	if (lv_cnt>=DISPLAY_LINES) {
		aclfgl_display_menu(0);
		lv_action=A4GL_pop_int();


		if(lv_action==2) { // EXIT
				fclose(in);
endcode
	return 2
code
		}

		if (lv_action==1) { // RESTART
				fclose(in);
		
endcode
	return 1
code
		}

		if (lv_action==0) {
			char nfname[256];
			sprintf(nfname,"%s.tmp",outfname);
			outlines-=DISPLAY_LINES;
			out2=fopen(nfname,"w");
			while (1) {
				fgets(buff,sizeof(buff),in);
				if (feof(in)) break;
				fprintf(out2,"%s",buff);
			}
			fclose(in);
			fclose(out2);
			rename(nfname,outfname);
			out=fopen(outfname,"a");
endcode
	return 0
code
		}
	}
}
endcode
return 0
END FUNCTION


FUNCTION display_menu()
define lv_action integer
set pause mode off
		MENU "DISPLAY"
			COMMAND "NEXT" "Display next page of information"
				let lv_action=0 exit menu

			COMMAND "RESTART" "Restart the query"
				let lv_action=1 exit menu

			COMMAND "EXIT" "Exit the query"
				let lv_action=2 exit menu
		END MENU

return lv_action
END FUNCTION
