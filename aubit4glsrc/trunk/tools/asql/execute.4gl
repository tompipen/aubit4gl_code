code
#include <stdio.h>
#include <stdlib.h>


extern int numberOfColumns;


int width;
int display_mode;
int fetchFirst=0;
#define DISPLAY_ACROSS 1
#define DISPLAY_DOWN   2


int display_lines=-1;

void open_display_file_c() ;


FILE *out=0;
FILE *exec_out;
int outlines=0;

char outfname[255]="";
int first_open=0;

int field_widths(void) ;
char **columnNames=0;
int *columnWidths=0;

#define EXEC_MODE_INTERACTIVE   0
#define EXEC_MODE_FILE          1
#define EXEC_MODE_OUTPUT        2


struct element {
        int lineno;
        char type;
        char *stmt;
};

char *get_qry_msg(int qry_type,int n);

extern struct element *list;
extern int list_cnt;


endcode



define exec_mode integer
define raffected integer


# Set execute mode
#
#    0 = interactive
#    1 = SQL being read from a file
#
function set_exec_mode(em) 
define em integer
let exec_mode=em
end function

function get_exec_mode()
return exec_mode
end function

function open_display_file() 
code
first_open=1;
open_display_file_c();
endcode
end function


function add_to_display_file(lv_str)
define lv_str char(255)
code
A4GL_assertion(out==0,"No output file (1)");
A4GL_trim(lv_str);
if (out) fprintf(out,"%s\n",lv_str);
outlines++;
endcode

end function

function confirm(qry_type) 
define qry_type integer

	if exec_mode=1 or exec_mode=2 then
		return 0
	end if

	if qry_type=32 or qry_type=33 then 
		return 1
	end if
	return 0
end function


code
int ec_check_and_report_error() {
	
	if (sqlca.sqlcode<0) {
		aclfgl_check_and_report_error(0);
		return 1;
	} else {
		return 0;
	}


		//return 1;
	//} else {
		//return 0;
	//}
}
endcode


function execute_queries(ofile)
define ofile INTEGER
define a integer
define msg char(512)
define qry_type integer
define lv_cont integer
define rpaginate integer
define l_db char(80)
let msg=""
options message line last
code
first_open=1;
if (display_lines==-1) {
	display_lines=A4GL_get_curr_height()-8;
}

A4GL_debug("%d SQL statements",list_cnt);

if (exec_mode!=EXEC_MODE_INTERACTIVE) {
	if (ofile==0) ofile=(long)stdout;
	exec_out=(FILE *)ofile;
}


	for (a=0;a<list_cnt;a++) {
		char *p;
		qry_type=0;

		raffected=0;

		A4GL_debug("EXEC %d %c - %s\n",list[a].lineno,list[a].type,list[a].stmt);
		p=list[a].stmt;


			qry_type=prepare_query_1(p);
			if (qry_type==-1) { goto end_query; }

			//EXEC SQL PREPARE stExec from :p;
			//if (ec_check_and_report_error()) { goto end_query; }
			//EXEC SQL ALLOCATE DESCRIPTOR "d1";
			//if (ec_check_and_report_error()) { goto end_query; }
        		//EXEC SQL DESCRIBE stExec USING SQL DESCRIPTOR "d1";
			//qry_type=sqlca.sqlcode;


			if (qry_type==1) {
				strcpy(l_db,&p[9]);
			}


endcode
	let lv_cont=1
	IF confirm(qry_type) THEN
		MENU "Confirm "
			command "Yes" "Really do it" 
				let lv_cont=1
				exit menu
			command "No" "Don't do it" 
				return 0
		END MENU
	END IF

code
	

		

			// Is it a select statement ?
			// @todo - this needs refining as a select .. into temp would get caught..
			if (list[a].type!='S') {

				if (!execute_query_1(&raffected)) goto end_query;

				//EXEC SQL EXECUTE stExec;
				//if (ec_check_and_report_error()) { goto end_query; }
				//raffected=sqlca.sqlerrd[0];
				//EXEC SQL FREE stExec;
				//if (ec_check_and_report_error()) { goto end_query; }


			} else {
				rpaginate=0;
repeat_query: ;
	A4GL_debug("EXEC Repeat query out=%p\n",out);
				if (execute_select_prepare()) {
					while (1) {
					int b;
					char buff[244];
						A4GL_debug("Fetching..");
						b=execute_sql_fetch(&raffected);

				
						if (exec_mode==EXEC_MODE_INTERACTIVE) {
							while (outlines>=display_lines || (outlines && b!=0)) {
								aclfgl_paginate(0);
								rpaginate=A4GL_pop_int();
								if (rpaginate!=0) break;
								fetchFirst=1;
							}

							if (rpaginate!=0) break;

							if (b!=0) goto end_query;

						} else {
							rpaginate=0;
							if (b!=0) goto end_query;
						}
					}

					if (rpaginate==1) {
						A4GL_debug("EXEC REPEAT");
						if (out) {fclose(out); out=0;}
						first_open=1;
						goto repeat_query;
					}


					if (rpaginate==2) {
						A4GL_debug("EXEC EXIT");
endcode
						return 0;
code
					}


				A4GL_debug("EXEC CLOSEDOWN - %d",outlines);
	
A4GL_assertion(out==0,"No output file (2)");
					if (out) {fprintf(out,"\n");fclose(out);out=0;}

					if (!execute_select_free()) goto end_query;


					//EXEC SQL CLOSE crExec;
					//EXEC SQL free stExec;
					//EXEC SQL free crExec;
					//if (ec_check_and_report_error()) { A4GL_debug("EXEC ERR3"); goto end_query; }

					
				} else {
					A4GL_push_char("Error executing select");
   					A4GL_display_error(0,0);
					sleep(1);
				}
			}
A4GL_debug("EXEC COMPLETE %d %d",a,list_cnt);
		A4GL_debug("Qry type : %d",qry_type);
end_query: ;
	sprintf(msg,"Q:%d %d - ( %s )",qry_type, raffected,get_qry_msg(qry_type,raffected));

endcode

if sqlca.sqlcode>=0 then
	if exec_mode=0 then
		message msg clipped
	else
		display msg clipped
		display " "
	end if

	if qry_type=1 then
		call set_curr_db(l_db)
		call display_banner()
	end if

	if qry_type=31 then
		call set_curr_db("")
		call display_banner()
	end if

else

	if exec_mode=0 or exec_mode=2 then
		message msg clipped

		# We'll stop after the first error...
		return 0 
	else
		display msg clipped
		display " "
	end if
end if

code
	}
endcode


# Everything is fine...
return 1



end function




code
int isSqlError () {
	if (sqlca.sqlcode<0) return 1;
	return 0;
}


int get_exec_mode_c() {
	return exec_mode;
}

/******************************************************************************/
void open_display_file_c() {
int cnt;
fetchFirst=1;
sprintf(outfname,"/tmp/out%d.txt",getpid());

if (out) {
	fclose(out);
	out=0;
}


if (out==0) {
	if (!first_open) {
		out=fopen(outfname,"a");
	} else {
		out=fopen(outfname,"w");
		first_open=0;
	}
	A4GL_assertion(out==0,"Unable to open output file (4)");
}



}





/******************************************************************************/











#define MAX_QRY  50


char *qry_strings[255]={

"%d Rows found", // 0
"Database selected",
"%d Rows found",
"%d rows selected into temp table",
"%d rows updated",
"%d rows deleted",
"row inserted",
0,
0,
0,
"Table Locked", // 10



"Table Unlocked",
"Database Created",
"Database Dropped",
"Table Created",
"Table Dropped",
"Index Created",
"Index Dropped",
"Permissions granted",
"Permissions revoked",
"Table renamed", // 20

"Column renamed",
0,
0,
0,
0,
0,
0,
0,
"Table altered",
"Statistics updated", // 30


"Database closed",
"%d rows deleted",
"%d rows updated",
"Transaction started",
"Transaction committed",
"Transaction rolled back",
0,
0,
0,
"View Created", //40


"View Dropped",
0,
"Synonym created",
"Synonym dropped",
"Temp table created",
"Lock mode set",
"Index Altered",
"Isolation set",
"Log set"
"Explain mode set", // 50





0};





char *get_qry_msg(int qry_type,int n) {
static char buff[256];
if (sqlca.sqlcode>=0) {
	if (qry_type<=MAX_QRY) {
		sprintf(buff,qry_strings[qry_type],n);
	} else {
		sprintf(buff,"Operation successed (%d) rows affected",n);
	}
} else {
	char *ptr;
	A4GL_push_int(sqlca.sqlcode);
	aclfgl_get_db_err_msg(1);
	ptr=A4GL_char_pop();
	A4GL_trim(ptr);
	sprintf(buff,"Error %d : %s",sqlca.sqlcode,ptr);
	free(ptr);
}
	return buff;
}
endcode



function execute_output(lv_name,lv_fmode,lv_amode)
define lv_name char(255)
define lv_fmode char(1)
define lv_amode char(1)
define lv_out integer
define lv_rval integer
Call set_exec_mode(2)

if lv_fmode="p" then
	display "" # go into line mode...
end if

code
A4GL_trim(lv_name);

if (lv_fmode[0]=='f')  {
	A4GL_debug("OUTPUT fopen(%s,%s)",lv_name,lv_amode);
	lv_out=(long)fopen(lv_name,lv_amode);
} else {
	A4GL_push_char("DISPLAY");
	A4GL_push_int(-1);
	A4GL_push_int(-1);
       	A4GL_display_at(1,0x0);
	A4GL_debug("OUTPUT popen(%s,%s)",lv_name,lv_amode);
	lv_out=(long)popen(lv_name,lv_amode);
}
endcode

if lv_out=0 then
	error "Unable to open output"
	return
end if

let lv_rval=execute_queries(lv_out) 

code
	fclose((FILE *)lv_out);
	if (lv_fmode[0]=='p') {
		A4GL_push_char("DISPLAY");
		A4GL_push_int(1);
		A4GL_push_int(1);
        	A4GL_display_at(1,0x0);
		aclfgl_display_banner(0);
	}
endcode

if lv_rval=0 then
	error "ERROR!!!"
	sleep 2
end if

return lv_rval
	

end function

		
