# +----------------------------------------------------------------------+
# | Aubit SQL Access Program ASQL                                        |
# +----------------------------------------------------------------------+
# | Copyright (c) 2003-5 Aubit Computing Ltd                             |
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
code
#include <stdio.h>
#include <stdlib.h>


extern int numberOfColumns;


int width;
int display_mode;
int fetchFirst=0;
#define DISPLAY_ACROSS 1
#define DISPLAY_DOWN   2
#define DISPLAY_UNLOAD 3

int display_lines=-1;

void open_display_file_c() ;
void set_outfname(void);


FILE *file_out_result=0;
FILE *exec_out;
int outlines=0;

char outfname[255]="";
int first_open=0;

int field_widths(void) ;
char **columnNames=0;
int *columnWidths=0;
int *columnAlign=0;

#define EXEC_MODE_INTERACTIVE   0
#define EXEC_MODE_FILE          1
#define EXEC_MODE_OUTPUT        2


struct element {
        int lineno;
        char type;
        char *stmt;
        char *delim;
        char *fname;
};

char *get_qry_msg(int qry_type,int n);

extern struct element *list;
extern int list_cnt;

void display_mode_unload(int a) {
	if (a) 
	display_mode=DISPLAY_UNLOAD;
	else display_mode=0;
	
}



int set_outlines_c(char *fname) {
FILE *f;
char buff[300];
A4GL_trim(fname);
f=fopen(fname,"r");
outlines=0;
if (!f)  return;
while (1) {
	fgets(buff,300,f);
	if (feof(f)) break;
	outlines++;
}
fclose(f);
}

endcode



define exec_mode integer
define raffected integer
define beganWork integer


# Set execute mode
#
#    0 = interactive
#    1 = SQL being read from a file
#
function set_exec_mode(em) 
define em integer
let exec_mode=em
code
A4GL_debug("setting exec_mode = %d",em);
endcode
end function

function get_exec_mode()
code
A4GL_debug("getting exec_mode = %d",exec_mode);
endcode
return exec_mode
end function


function get_display_mode()
define lv_a integer
code
lv_a=display_mode;
endcode

return lv_a
end function

function open_display_file() 
code
first_open=1;
open_display_file_c();
endcode
end function


function add_to_display_file(lv_str)
define lv_str char(256)
code
A4GL_trim(lv_str);

if (get_exec_mode_c()==EXEC_MODE_INTERACTIVE)  {
	A4GL_assertion(file_out_result==0,"No output file (2.1)");
	fprintf(file_out_result,"%s\n",lv_str);
} else {
	A4GL_assertion(exec_out==0,"No output file (2.2)");
	fprintf(exec_out,"%s\n",lv_str);
}
outlines++;
endcode
end function


function add_to_display_file_wrapped(lv_str)
define lv_str char(5000)
define lv_smstr char(80)
define lv_col integer
define a integer

let lv_col=1

for a=1 to length(lv_str)

code
	if (lv_str[a-1]=='\n' || lv_str[a-1]=='\r') {
		lv_col=0;
		if (get_exec_mode_c()==EXEC_MODE_INTERACTIVE)  {
	 			fprintf(file_out_result,"\n");
		} else {
	 			fprintf(exec_out,"\n");
		}
	} else {
		if (get_exec_mode_c()==EXEC_MODE_INTERACTIVE)  {
	     		fprintf(file_out_result,"%c",lv_str[a-1]);
		} else {
	     		fprintf(exec_out,"%c",lv_str[a-1]);
		}
	}
endcode
	let lv_col=lv_col+1
	if lv_col=80 then
code
if (get_exec_mode_c()==EXEC_MODE_INTERACTIVE)  {
	 	fprintf(file_out_result,"\n");
} else {
	 	fprintf(exec_out,"\n");
}
		lv_col=1;
endcode
	end if


end for


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


void set_display_lines() {
	if (exec_mode==EXEC_MODE_INTERACTIVE) {
	if (display_lines==-1) {
        	display_lines=A4GL_get_curr_height()-6;
	}
	}
}
endcode


function set_began_work()
let beganWork=0
end function


function need_commit_rollback()
if beganWork then
	menu "COMMIT ?"
		command "Commit" "Commit work"
			commit work
			exit menu
		command "Rollback" "Rollback work"
			rollback work
			exit menu
	end menu
	let beganWork=0
end if

end function


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
set_display_lines();

A4GL_debug("%d SQL statements - mode=%d",list_cnt,exec_mode);

if (exec_mode!=EXEC_MODE_INTERACTIVE) {
	if (ofile==0) {
		ofile=(long)stdout;
	}
	exec_out=(FILE *)ofile;

}


	for (a=0;a<list_cnt;a++) {
		char *p;
		qry_type=0;

		raffected=0;

		if (exec_mode!=EXEC_MODE_INTERACTIVE) {
			if (is_echo_c()) {
				fprintf(exec_out,"\n%s\n",list[a].stmt);
			}
		}


		A4GL_debug("EXEC %d %c - %s\n",list[a].lineno,list[a].type,list[a].stmt);
		p=list[a].stmt;

		display_mode_unload(0);
		if (list[a].type!='L'&&list[a].type!='l') {
			qry_type=prepare_query_1(p,list[a].type);
			if (list[a].type=='C'||list[a].type=='c') qry_type=255;
		} else {
			qry_type=255;
		}
			if (qry_type==-1) { goto end_query; }


			if (qry_type==1) {
				strcpy(l_db,&p[9]);
				
			}


endcode

	if get_exec_mode()=0 then
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

	
	MESSAGE "Please wait.."
	end if
code
	

		

			// Is it a select statement ?
			// @todo - this needs refining as a select .. into temp would get caught..
			if (list[a].type!='S'&&list[a].type!='s') {
				if (list[a].type=='C'|| list[a].type=='c') raffected=asql_unload_data(&list[a]);
				else {
					if (list[a].type=='L'|| list[a].type=='l') {raffected=asql_load_data(&list[a]);}
					else {
						if (list[a].type>='1'&&list[a].type<='9') {
							if (!asql_info(&list[a])) goto end_query;
						} else {
							if (list[a].type=='E'||list[a].type=='e') {
								raffected=asql_explain(&list[a]); 
							} else {
								if (qry_type==1) {
									A4GL_debug("display_mode=%d exec_mode=%d\n",display_mode,exec_mode);
									A4GL_push_char(l_db);
									aclfgl_sql_select_db(1);
								} else {
									if (!execute_query_1(&raffected)) goto end_query;
								}
							}

						}
					}
				}
			} else {
				rpaginate=0;
				if (a==0) {
					if (file_out_result) fprintf(file_out_result,"\n\n");
				}
repeat_query: ;
	A4GL_debug("EXEC Repeat query out=%p\n",file_out_result);
				if (execute_select_prepare()) {

					if (get_sqlcode()<0) goto end_query;

					while (1) {
					int b;
					int done_once=0;
					char buff[244];
						A4GL_debug("Fetching..");
						b=execute_sql_fetch(&raffected);

				
						if (exec_mode==EXEC_MODE_INTERACTIVE) {
							rpaginate=0;
							while (outlines>=display_lines || (outlines && b!=0)) {
								done_once=1;
								aclfgl_paginate(0);
								rpaginate=A4GL_pop_int();
								if (rpaginate!=0) break;
								fetchFirst=1;
							}

							if (outlines && done_once &&rpaginate==0) {
								aclfgl_paginate_always(0);
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
						if (file_out_result) {fclose(file_out_result); file_out_result=0;}
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
	
A4GL_assertion(file_out_result==0,"No output file (2)");
					if (file_out_result) {fprintf(file_out_result,")\n");fclose(file_out_result);file_out_result=0;}

					if (!execute_select_free()) goto end_query;
					
				} else {
					A4GL_debug("Error with %s - %d",p,get_sqlcode());
					goto end_query;
					
				}
			}
A4GL_debug("EXEC COMPLETE %d %d",a,list_cnt);
		A4GL_debug("Qry type : %d",qry_type);
end_query: ;
	sprintf(msg,"Q:%d %d - ( %s )",qry_type, raffected, get_qry_msg(qry_type,raffected));

endcode

if sqlca.sqlcode>=0 then
	if exec_mode=0 or exec_mode=2 then
		message msg clipped
	else
code
		fprintf(stderr,"%s\n",msg);
endcode

		display " "
	end if

	if qry_type=1 and get_exec_mode()!=1 then
		call set_curr_db(l_db)
		call display_banner()
	end if

	if qry_type=31 then
		call set_curr_db("")
		call display_banner()
	end if

	if qry_type=34 then let beganWork=1 end if
	if qry_type=35 then let beganWork=0 end if
	if qry_type=36 then let beganWork=0 end if

else

	if exec_mode=0 or exec_mode=2 then
		message msg clipped

		# We'll stop after the first error...
		return 0 
	else
code
	fprintf(stderr,"%s\n",msg);
endcode
		display " "
	end if
end if

code
	}
endcode


# Everything is fine...
return 1



end function


function set_outlines(fname)
define fname char(255)
define a integer
code
set_outlines_c(fname);
a=outlines;
endcode
end function


function get_out_fname()
define lv_out char(300)
code
set_outfname();
strcpy(lv_out,outfname);
endcode
let lv_out=lv_out
return lv_out
end function




code



int isSqlError () {
	if (get_sqlcode()<0) return 1;
	return 0;
}


int get_exec_mode_c() {
	return exec_mode;
}

void set_outfname(void) {
	static int have_made_dir=0;
	if (have_made_dir==0) {
		char buff[1024];
		sprintf(buff,"%s/tmp",acl_getenv("AUBITDIR"));
		mkdir(buff,0777);
		chmod (buff,0777);
		have_made_dir=1;
	}
	sprintf(outfname,"%s/tmp/out%d.txt",acl_getenv("AUBITDIR"),getpid());
}




/******************************************************************************/
void open_display_file_c() {
int cnt;
fetchFirst=1;

set_outfname();

if (file_out_result) {
	fclose(file_out_result);
	file_out_result=0;
}


if (file_out_result==0) {
	if (!first_open) {
		file_out_result=fopen(outfname,"a");
	} else {
		file_out_result=fopen(outfname,"w");
		first_open=0;
	}
	A4GL_debug("Open file : %s failed  ? %p",outfname,file_out_result);
	
	A4GL_assertion((file_out_result==0),"Unable to open output file (4)");
	
}

A4GL_debug("open_display_file_c succeeded - %s",outfname);



}



int asql_info(struct element *e) {
int a;

if (file_out_result==0) {open_display_file_c();
}

if (e->type=='3') {
		aclfgl_load_info_tables(0);
		a=A4GL_pop_int();
		return a;
}

A4GL_push_char(e->fname);

switch (e->type) {
		case '1': aclfgl_load_info_columns(1);break;
		case '2': aclfgl_load_info_status(1);break;
		case '4': aclfgl_load_info_priv(1);break;
		case '5': aclfgl_load_info_indexes(1);break;
}
a=A4GL_pop_int();
if (exec_mode==EXEC_MODE_INTERACTIVE) {
	aclfgl_do_paginate(0);
}
return a;
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



int set_stdin_width() {
char buff[256];
char *ptr;
int w;
ptr=acl_getenv("COLUMNS");
if (ptr==0) return 132;
if (strlen(ptr)==0) return 132;
w=atoi(ptr);
if (w<=20) return 132;
return w;
}


char *get_qry_msg(int qry_type,int n) {
static char buff[256];
if (get_sqlcode()>=0) {
	if (qry_type<=MAX_QRY) {
		sprintf(buff,qry_strings[qry_type],n);
	} else {
		sprintf(buff,"Operation successed (%d) rows affected",n);
	}
} else {
	char *ptr;
	A4GL_push_int(get_sqlcode());
	aclfgl_get_db_err_msg(1);
	ptr=A4GL_char_pop();
	A4GL_trim(ptr);
	sprintf(buff,"Error %d : %s",get_sqlcode(),ptr);
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
	sleep 1 # After an error...
end if

return lv_rval
	

end function

		

