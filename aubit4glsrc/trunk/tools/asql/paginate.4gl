# +----------------------------------------------------------------------+
# | Aubit SQL Acess Program ASQL                                         |
# +----------------------------------------------------------------------+
# | Copyright (c) 2003 Aubit Computing Ltd                               |
# +----------------------------------------------------------------------+
# | Production of this software was sponsored by                         |
# |                 Cassens Transport Company                            |
# +----------------------------------------------------------------------+
# | This program is free software; you can redistribute it and/or modify |
# | it under the terms of one of the following licenses:                 |
# |                                                                      |
# |  A) the GNU General Public License as published by the Free Software |
# |     Foundation; either version 2 of the License, or (at your option) |
# |     any later version.                                               |
# |                                                                      |
# |  B) the Aubit License as published by the Aubit Development Team and |
# |     included in the distribution in the file: LICENSE                |
# |                                                                      |
# | This program is distributed in the hope that it will be useful,      |
# | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
# | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
# | GNU General Public License for more details.                         |
# |                                                                      |
# | You should have received a copy of both licenses referred to here.   |
# | If you did not, or have any questions about Aubit licensing, please  |
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
define lines array[255] of char(80)
code


#include <stdio.h>


extern FILE *out;
extern int outlines;
extern char outfname[255];
extern int display_lines;
endcode

FUNCTION paginate() 
	return paginate_internal(0)
END FUNCTION

FUNCTION paginate_always() 
	return paginate_internal(1)
END FUNCTION



FUNCTION paginate_internal(lv_always) 
define lv_always integer
define buff char(255)
define lv_cnt integer
define lv_a integer
define lv_action integer

let lv_cnt=0

set pause mode on
MESSAGE ""
call clear_screen_portion()
call set_exec_mode(0)
code
{
FILE *in;
FILE *out2;
set_display_lines();
if (out) {
	fclose(out);
	out=0;
}
in=fopen(outfname,"r");
A4GL_debug("READING IN %s...",outfname);
lv_cnt=0;
rewind(in);
while (1) {
	strcpy(buff,"");
	if (feof(in)) {
		A4GL_debug("END OF FILE");
		break;
	}
	if (lv_cnt>=display_lines) break;
	fgets(buff,sizeof(buff),in);

	A4GL_debug("PAGINATE : %s",buff);
	strcpy(lines[lv_cnt],buff);
	lv_cnt++;
	outlines--;
endcode
	DISPLAY lines[lv_cnt] at lv_cnt+5,1
code
}

if (outlines<0) outlines=0;
if (lv_cnt==0) outlines=0;
endcode
set pause mode off
code
	if (lv_cnt>=display_lines || lv_always) {

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
			out2=fopen(nfname,"w");
			outlines=0;
			while (1) {
				fgets(buff,sizeof(buff),in);
				if (feof(in)) break;
				outlines++;
				fprintf(out2,"%s",buff);
			}
			fclose(in);
			fclose(out2);
			rename(nfname,outfname);
	
			open_display_file_c();
endcode
#set pause mode off
	return 0
code
		}
	}
}
			open_display_file_c();
endcode
#set pause mode off
return 0
END FUNCTION


FUNCTION display_menu()
define lv_action integer
		MENU "DISPLAY"
			COMMAND "Next" "Display next page of information"
				let lv_action=0 exit menu

			COMMAND "Restart" "Restart the query"
				let lv_action=1 exit menu

			COMMAND "Exit" "Exit the query"
				let lv_action=2 exit menu
		END MENU

return lv_action
END FUNCTION
