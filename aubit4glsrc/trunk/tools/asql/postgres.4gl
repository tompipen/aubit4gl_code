# +----------------------------------------------------------------------+
# | Aubit SQL Access Program ASQL                                        |
# +----------------------------------------------------------------------+
# | Copyright (c) 2003-7 Aubit Computing Ltd                             |
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
#undef UCHAR
#include "simple.h"
char *A4GL_apisql_strdup (char *sql);
//EXEC SQL include sqltypes;
EXEC sql include sql3types;
EXEC sql include sqlca;
EXEC SQL BEGIN DECLARE SECTION;
int numberOfColumns=0;
EXEC SQL END DECLARE SECTION;
static int field_widths(void);
extern FILE *file_out_result;
extern FILE *exec_out;
char *get_delim_flag(void);
extern int outlines;
extern int display_mode;
extern int fetchFirst;
static int get_size(int dtype,int size) ;
int need_cursor_free=0;
int stdin_screen_width=-1;
int colnamesize=-1;
static int inited=0;

#define DISPLAY_ACROSS 1
#define DISPLAY_DOWN   2
#define DISPLAY_UNLOAD 3
extern char **columnNames;
extern int *columnWidths;
extern int *columnAlign; // CA1
#define EXEC_MODE_INTERACTIVE   0
#define EXEC_MODE_FILE          1
#define EXEC_MODE_OUTPUT        2

#define LOADBUFFSIZE 32000


#define CHAR_SINGLE_QUOTE 39
#define CHAR_BACKSLASH 92  


char loadbuff[LOADBUFFSIZE];

FILE *f_unloadFile=0;
int firstFetchInit=0;
extern char *LoadUnload_delim;// delimiters for load/unload

void cp_sqlca_full() ;
int ec_check_and_report_error();

char mv_errmsg[256]="No Message";

#define cp_sqlca() cp_sqlca_full(__FILE__,__LINE__)

int execute_select_prepare(int *errat,int type, int *hasrows) {
static int done_alloc=0;
*errat=1;
*hasrows=1;
	open_display_file_c();

	EXEC SQL WHENEVER SQLERROR CONTINUE;
if (done_alloc) {
	EXEC SQL deallocate descriptor descExec;
	done_alloc=0;
	if (sqlca.sqlcode<0) {A4GL_debug("Err1");return 0;}
}
	

if (!done_alloc) {
	EXEC SQL allocate descriptor descExec ;cp_sqlca();
	if (sqlca.sqlcode<0) {A4GL_debug("Err2"); return 0;}
	done_alloc=1;
}


if (need_cursor_free) {
		execute_select_free();
}
	
	EXEC SQL declare crExec CURSOR WITH HOLD FOR stExec;cp_sqlca();
       	if (sqlca.sqlcode<0) {A4GL_debug("Err3"); return 0;}

	need_cursor_free=1;

	EXEC SQL open crExec ;cp_sqlca();
	if (sqlca.sqlcode<0) {A4GL_debug("Err3"); return 0;}
	need_cursor_free=3;

	firstFetchInit=1;
return 1;
}




void set_display_mode() {
if (display_mode==DISPLAY_UNLOAD) {
int a;
a=field_widths();
return;
}

if (get_exec_mode_c()==0||get_exec_mode_c()==2) {
        if (field_widths()>A4GL_get_curr_width()) {
                display_mode=DISPLAY_DOWN;
        } else {
                display_mode=DISPLAY_ACROSS;
        }
} else {
        if (stdin_screen_width==-1) {
		stdin_screen_width=set_stdin_width();
		//printf("---> %d width\n",stdin_screen_width);
	}
        if (field_widths () > stdin_screen_width) {
                display_mode=DISPLAY_DOWN;
        } else {
                display_mode=DISPLAY_ACROSS;
        }
}
if (get_heading_flag()==0) {
  display_mode=DISPLAY_ACROSS;
}

}
endcode

function get_db_err_msg(lv_code)
define lv_code integer
define lv_err1 char(255)
define lv_err2 char(255)
code

//printf("3-->%s\n",mv_errmsg);
if (lv_code!=-400) {
	rgetmsg(sqlca.sqlcode,lv_err1,sizeof(lv_err1));
	sprintf(lv_err2,lv_err1,sqlca.sqlerrm);
} else {
	strcpy(lv_err2,mv_errmsg);
}
A4GL_trim(lv_err2);
endcode
return lv_err2
end function





function table_select(lv_prompt)
define lv_prompt char(64)
define lv_tabname char(255)
define lv_cnt integer

define lv_query char(1024)
let lv_cnt=1


let lv_query=" SELECT c.relname FROM pg_catalog.pg_class c",
     " LEFT JOIN pg_catalog.pg_user u ON u.usesysid = c.relowner",
     " LEFT JOIN pg_catalog.pg_namespace n ON n.oid = c.relnamespace",
     " WHERE c.relkind IN ('r','')",
     " AND n.nspname NOT IN ('pg_catalog', 'pg_toast')",
     " AND pg_catalog.pg_table_is_visible(c.oid)",
     "  ORDER BY 1"


prepare p_q from lv_query 

declare c_gettables_drop cursor for p_q

foreach c_gettables_drop into lv_tabname
        call set_pick(lv_cnt,lv_tabname)
        let lv_cnt=lv_cnt+1
end foreach

call set_pick_cnt(lv_cnt-1)
call prompt_pick(lv_prompt,"") returning lv_tabname

return lv_tabname
end function






# These next few functions are from misql.4gl
# MISQL - Kerry's alternative to Informix-ISQL
{
MISQL is the result of work done on behalf of QUANTA SYSTEMS LTD,
AUCKLAND, NEW ZEALAND, and has been placed in the public domain with
their consent. There are no restrictions on how you can use it, but
please always include a reference to QUANTA SYSTEMS LTD and myself
in any derivative of this work.
Cheers,
Kerry Sainsbury (kerry@kcbbs.gen.nz, kerry@quanta.co.nz)
}




FUNCTION load_info_columns(l_tabname)
DEFINE   i            INTEGER,
         l_tabid      INTEGER,
         l_coltype    char(80),
         l_collength  INTEGER
DEFINE lv_buff char(255)
define l_tabname char(255)
define lv_colname char(19)
define rpaginate integer
define lv_query char(1024)


let lv_query=" SELECT c.oid FROM pg_catalog.pg_class c LEFT JOIN pg_catalog.pg_namespace n ON n.oid = c.relnamespace WHERE pg_catalog.pg_table_is_visible(c.oid) AND c.relname ='",l_tabname clipped,"'"

prepare p_qli1 from lv_query
declare c_qli1 cursor for p_qli1
open c_qli1 
fetch c_qli1 into l_tabid

   IF sqlca.sqlcode !=0 THEN
	IF sqlca.sqlcode=100 THEN
		ERROR "Table ", l_tabname clipped," was not found.."
	END IF

        IF  check_and_report_error() THEN
      	   RETURN  0
        END IF
   END IF
close c_qli1


let lv_query=" SELECT a.attname, pg_catalog.format_type(a.atttypid, a.atttypmod) ",
	" FROM pg_catalog.pg_attribute a ",
	" WHERE a.attrelid = '",l_tabid using "<<<<<<<<<","' AND a.attnum > 0 AND NOT a.attisdropped ",
	" ORDER BY a.attnum "

code
A4GL_debug("TABINFO Query = %s",lv_query);
endcode

   prepare p_qli2 from lv_query


   DECLARE info_curs CURSOR WITH HOLD FOR p_qli2


   LET i = 0
   FOREACH info_curs INTO lv_colname,l_coltype
code
	A4GL_debug("Fetch..");
endcode
      LET i = i + 1

	let lv_colname=lv_colname
      LET lv_buff = lv_colname," " ,l_coltype clipped
code
	A4GL_debug("TABINFO : %s",lv_buff);
endcode
        CALL add_to_display_file(lv_buff)

   END FOREACH
return 1
END FUNCTION


FUNCTION get_type(l_coltype, l_collength)
DEFINE l_coltype     INTEGER,
       l_collength   INTEGER,
       type_text CHAR(41)

    LET type_text=l_coltype using "<<<<", "(",l_collength using "<<<<<<<",")"



RETURN type_text

END FUNCTION




function connection_connect()
define lv_informixdir char(255)
define lv_passwd char(255)
define lv_username char(255)
define lv_cnt integer
define lv_port,lv_server char(80)
define a,x,y integer
define buff char(255)
define lv_ok integer
let lv_cnt=1
clear screen
call display_banner()

CALL use_pghosts() RETURNING lv_server, lv_port, lv_username, lv_passwd

IF lv_server IS NULL OR lv_server MATCHES " " THEN
	let lv_server=prompt_get("SELECT DATABASE SERVER >>","")
	IF lv_server is null or lv_server matches " " then
        	return
	END IF
END IF

IF lv_port IS NULL OR lv_port MATCHES " " THEN
	let lv_port=prompt_get("SELECT PORT (Default : 5432) >>","")
	IF lv_port is null or lv_port matches " " then
		LET lv_port="5432"
	END IF
END IF

IF lv_username IS NULL OR lv_username MATCHES " " THEN
	let lv_username=prompt_get("USER NAME >>","Enter the username")
END IF

IF lv_username is null or lv_username=" " then
ELSE
	IF lv_passwd IS NULL OR lv_passwd MATCHES " " THEN
		let lv_passwd=prompt_get("PASSWORD >>","Enter the password")
	END IF
END IF

IF lv_passwd is null or lv_passwd matches " " THEN
	# No point having a username with no password...
       	initialize lv_username to null
END IF
IF lv_username IS NULL OR lv_username MATCHES " " THEN
	# No point having a password with no username...
	INITIALIZE lv_passwd TO NULL
END IF

code
{
A4GL_trim(lv_server);
A4GL_setenv("PGHOST",lv_server,1);
A4GL_trim(lv_port);
A4GL_setenv("PGPORT",lv_port,1);
}
endcode

call set_username(lv_username,lv_passwd)
LET lv_ok=1

IF NOT connect_to_template1() THEN
	ERROR "Unable to connect to 'template1' to get database list (Error : ", sqlca.sqlcode USING "-<<<<<<<<",")"
	RETURN
END IF


call select_db()
end function




code

void trim_trailing_0(char *buffer) {
int a;
char *ptr;
ptr=strrchr(buffer,'.');
if (ptr==0) return;
for (a=strlen(buffer)-1;a>=0;a--) {
if (&buffer[a]<=ptr) break;
if (buffer[a]=='0') buffer[a]=0;
else break;
}
if (buffer[strlen(buffer)-1]=='.') buffer[strlen(buffer)-1]=0;
}

static void ltrim2(char *s);
static void ltrim(char *s) {
char *ptr;
ltrim2(s);
ptr=strchr(s,'.');
if (ptr) {
	trim_trailing_0(s);
}
}


static void ltrim2(char *s) {
char*ptr;
char *p2;
int a;
p2=0;
for (a=0;a<strlen(s);a++) {
	if (s[a]!=' ') {p2=&s[a];break;}
}

if (p2==0) { // All spaces
	strcpy(s,"");
	return;
}
ptr=strdup(p2);
strcpy(s,ptr);
free(ptr);
}

int
printField (FILE * outputFile, int idx, char *descName)
{
  EXEC SQL BEGIN DECLARE SECTION;
  int dataType;
  int index ;
  short indicator;
  char buffer[32000]="";
  int length;
  int COUNT;
  int INTVAR, BOOLVAR;
  int INDICATOR;
  int TYPE,LENGTH,OCTET_LENGTH,PRECISION,SCALE,NULLABLE,RETURNED_OCTET_LENGTH;
  int DATETIME_INTERVAL_CODE;
  char NAME[120];
  char STRINGVAR[1024];
  float FLOATVAR;
  double DOUBLEVAR;
  EXEC SQL END DECLARE SECTION;
  char buff[255];
char fmt[255];
  int rc = 0;
index=idx;

A4GL_debug("Getting details for index %d",index);
 exec sql get descriptor descExec value :index
         :TYPE = type,
         :LENGTH = length, :OCTET_LENGTH=octet_length,
         :RETURNED_OCTET_LENGTH=returned_octet_length,
         :PRECISION = precision, :SCALE=scale,
         :NULLABLE=nullable, :NAME=name,
         :INDICATOR=indicator;cp_sqlca();

 A4GL_debug("%2d\t%s (type: %d length: %d precision: %d scale: %d\n"
 "\toctet_length: %d returned_octet_length: %d nullable: %d)\n\t= "
                 ,index,NAME,TYPE,LENGTH,PRECISION,SCALE
                 ,OCTET_LENGTH,RETURNED_OCTET_LENGTH,NULLABLE);


        if (INDICATOR==-1) sprintf(buffer,"");
        else switch (TYPE)
        {
          case SQL3_BOOLEAN:
                exec sql get descriptor descExec value :index :BOOLVAR=data;cp_sqlca();
		if (display_mode!=DISPLAY_UNLOAD) {
                	sprintf(buffer,"%s",BOOLVAR ? "true":"false");
		} else {
			sprintf(buffer,"%d",BOOLVAR);
		}
                break;


           case SQL3_NUMERIC:
           case SQL3_DECIMAL:
                if (SCALE==0)
                {  exec sql get descriptor descExec value :index :INTVAR=data;cp_sqlca();
                	if (display_mode==DISPLAY_DOWN) {
                        	sprintf (buffer, "%d", INTVAR);
                	} else {
                        	sprintf (buffer, "%*d", columnWidths[idx-1],INTVAR);
                	}
                   //sprintf(buffer,"%-10d",INTVAR);
  			if (display_mode==DISPLAY_UNLOAD) ltrim(buffer);
                }
                else
                {  
		
			exec sql get descriptor descExec value :index :FLOATVAR=data;cp_sqlca();

                	if (display_mode==DISPLAY_DOWN) {
                        	sprintf (buffer, "%f", FLOATVAR);
                	} else {
                        	sprintf (buffer, "%*f", columnWidths[idx-1],FLOATVAR);
                	}
  				if (display_mode==DISPLAY_UNLOAD) ltrim(buffer);
                }
                break;


           case SQL3_INTEGER:
           case SQL3_SMALLINT:
                exec sql get descriptor descExec value :index :INTVAR=data;cp_sqlca();


        	if (display_mode==DISPLAY_DOWN) {
                	sprintf (buffer, "%d", INTVAR);
        	} else {
                	sprintf (buffer, "%*d", columnWidths[idx-1],INTVAR);
        	}
  		if (display_mode==DISPLAY_UNLOAD) ltrim(buffer);
                break;
           case SQL3_FLOAT:
           case SQL3_REAL:
                exec sql get descriptor descExec value :index :FLOATVAR=data;cp_sqlca();
                sprintf(buffer,"%.*f",PRECISION,FLOATVAR);
  		if (display_mode==DISPLAY_UNLOAD) ltrim(buffer);
                break;
           case SQL3_DOUBLE_PRECISION:
                exec sql get descriptor descExec value :index :DOUBLEVAR=data;cp_sqlca();
                sprintf(buffer,"%.*f",PRECISION,DOUBLEVAR);
  			if (display_mode==DISPLAY_UNLOAD) ltrim(buffer);
                break;
           case SQL3_DATE_TIME_TIMESTAMP:
                exec sql get descriptor descExec value :index
                        :DATETIME_INTERVAL_CODE=datetime_interval_code,
                        :STRINGVAR=data;cp_sqlca();
                sprintf(buffer,"%s",STRINGVAR);
                break;
           case SQL3_INTERVAL:
                exec sql get descriptor descExec value :index :STRINGVAR=data;cp_sqlca();
                sprintf(buffer,"%s",STRINGVAR);
                break;
           case SQL3_CHARACTER:
           case SQL3_CHARACTER_VARYING:
                exec sql get descriptor descExec value :index :STRINGVAR=data;cp_sqlca();
                sprintf(buffer,"%s",STRINGVAR);
		A4GL_trim(buffer);
                break;
           default:
                exec sql get descriptor descExec value :index :STRINGVAR=data;cp_sqlca();
                sprintf(buffer,"%s",STRINGVAR);
		if (display_mode==DISPLAY_UNLOAD) A4GL_trim(buffer);
                break;
        }

A4GL_debug("BUFFER=%s",buffer);

if (INDICATOR !=-1 && strlen(buffer)==0 &&display_mode==DISPLAY_UNLOAD) {
	strcpy(buffer," ");
}

        if (display_mode==DISPLAY_DOWN) {
		if (get_heading_flag()==1) {
			sprintf(fmt,"%%-%d.%ds %%s\n",colnamesize+1,colnamesize+1);
	
                	if (get_exec_mode_c()==EXEC_MODE_INTERACTIVE)  {
                        	fprintf(outputFile,fmt,columnNames[idx-1],buffer);
                	} else {
                        	fprintf(exec_out,fmt,columnNames[idx-1],buffer);
                	}
		} else {
	
                	if (get_exec_mode_c()==EXEC_MODE_INTERACTIVE)  {
                        	fprintf(outputFile,"%s",buffer);
                	} else {
                        	fprintf(exec_out,"%s",buffer);
                	}

		}
                	outlines++;
        } 

	if (display_mode==DISPLAY_UNLOAD) {
                        fprintf(f_unloadFile,"%s%s",escape_delim(buffer),LoadUnload_delim);
	}

	if (display_mode==DISPLAY_ACROSS) {
                if (get_exec_mode_c()==EXEC_MODE_INTERACTIVE)  {

                        A4GL_debug("EXECO '%s' '%20s' '%-20s'",buffer,buffer,buffer);
                        fprintf(outputFile,"%-*s",columnWidths[idx-1],buffer);
                }
                else
                        fprintf(exec_out,"%-*s",columnWidths[idx-1],buffer);
        }


  return 0;
}


int prepare_query_1(char *s,char type,int *err_at_col) {
static int prepared;
EXEC SQL BEGIN DECLARE SECTION;
char *p;
EXEC SQL END DECLARE SECTION;
int qry_type;
p=s;
*err_at_col=1;

if (strncasecmp(s,"database",8)==0) {
	return 1;
}

if (type>='1'&&type<='9') return 257;

qry_type=0;

if (type!='S'&&type!='s') qry_type=257;

   if (prepared) {
       EXEC SQL free stExec;cp_sqlca();
       prepared=0;
   }

   EXEC SQL PREPARE stExec from :p;
   //printf("PREPARE sqlca.sqlcode=%d\n",sqlca.sqlcode);
   //printf(" -- %s %d\n",sqlca.sqlerrm.sqlerrmc,sqlca.sqlerrm.sqlerrml);


cp_sqlca();


   if (sqlca.sqlcode>=0) prepared=1;
   else prepared=0;


	if (type=='S') qry_type=0;
	if (type=='s') qry_type=0;

	if (type=='u') qry_type=4;
	if (type=='d') qry_type=5;
	if (type=='I') qry_type=6;

	if (type=='U') qry_type=33;
	if (type=='D') qry_type=32;

	if (type=='T') qry_type=3;
	if (type=='t') qry_type=3;

	if (prepared) return qry_type;
	//printf("2PREPARE - bad\n");
	return -1;
}



int execute_query_1(int *raffected,int *errat) {
		*raffected=0;
                         EXEC SQL EXECUTE stExec;cp_sqlca();
                         if (ec_check_and_report_error()) { return 0; }
                         *raffected=sqlca.sqlerrd[2];
	A4GL_debug("SQLERRD : %d %d %d %d %d %d\n", sqlca.sqlerrd[0], sqlca.sqlerrd[1], sqlca.sqlerrd[2], sqlca.sqlerrd[3], sqlca.sqlerrd[4], sqlca.sqlerrd[5]);
                         EXEC SQL FREE stExec;cp_sqlca();
                         if (ec_check_and_report_error()) { *errat=1; return 0; }
	return 1;
}



execute_select_free() {
	A4GL_debug("execute_select_free");
	
                          if (need_cursor_free==3) EXEC SQL CLOSE crExec;  cp_sqlca();

                          if (need_cursor_free>=1) EXEC SQL FREE crExec;  cp_sqlca();

                          if (ec_check_and_report_error()) { A4GL_debug("EXEC ERR3"); return 0; }
	need_cursor_free=0;
	return 1;
}


int asql_explain_mode(int a) {
static int em=0;
if (a==1) em=1;
if (a==0) em=0;
if (a==-1) return em;
}


int asql_explain(struct element *e) {
EXEC SQL BEGIN DECLARE SECTION;
static char lv_str[256];
EXEC SQL END DECLARE SECTION;

EXEC SQL EXECUTE stExec INTO :lv_str;
//printf("----->%s\n",lv_str);
                if (get_exec_mode_c()==EXEC_MODE_INTERACTIVE)  {
			if (file_out_result==0) {open_display_file_c(); }
                        fprintf(file_out_result,"%s\n",lv_str);
			outlines++;
			aclfgl_do_paginate(0);
                } else {
                        fprintf(exec_out,"%s\n",lv_str);
			outlines++;
                }
	
return 1;
}

static int field_widths() {
EXEC SQL BEGIN DECLARE SECTION;
int index;
int datatype;
int size;
char columnName[64];
EXEC SQL END DECLARE SECTION;
int totsize=0;
exec sql get descriptor descExec :numberOfColumns = count;cp_sqlca();

A4GL_assertion(numberOfColumns==0,"No number of columns found...");
if (columnNames) {
        int a;
        for (a=0;columnNames[a];a++) free(columnNames[a]);
        free(columnNames);
        columnNames=0;
}

if (columnWidths) {
        free(columnWidths);
        columnWidths=0;
}

if (columnAlign) { // CA1
        free(columnAlign); // CA1
        columnAlign=0; //CA1
} // CA1

colnamesize=-1;
columnNames=acl_malloc2(sizeof(char*) * (numberOfColumns+1));
columnWidths=acl_malloc2(sizeof(int) * (numberOfColumns+1));
columnAlign=acl_malloc2(sizeof(int) * (numberOfColumns+1));

for(index=1;index<=numberOfColumns;index++) {
        EXEC SQL GET DESCRIPTOR descExec VALUE:index:size=LENGTH,:datatype=TYPE,:columnName=NAME;cp_sqlca();
        A4GL_trim(columnName);
        columnNames[index-1]=strdup(columnName);

        size=get_size(datatype,size);
        if (size<strlen(columnNames[index-1])) size=strlen(columnNames[index-1]);

        if (strlen(columnName)>size) {
                size=strlen(columnName);
        }

	if (strlen(columnName)>colnamesize || colnamesize<=0) {
		colnamesize=strlen(columnName);
	}
        columnWidths[index-1]=size;
        if (datatype==SQL3_SMALLINT || datatype==SQL3_INTEGER || datatype== SQL3_FLOAT|| datatype== SQL3_REAL||datatype==SQL3_NUMERIC) {
                columnAlign[index-1]=1; // CA 1
        } else { // CA 1
                columnAlign[index-1]=0; // CA 1
        } // CA 1
        totsize+=size+1;
}

columnNames[numberOfColumns]=0;
return totsize;
}

/******************************************************************************/
int execute_sql_fetch(int *raffected, int *errat) {
int a;
*errat=1;

        EXEC SQL FETCH crExec INTO SQL DESCRIPTOR descExec; cp_sqlca();
	A4GL_debug("Fetched");

        if (sqlca.sqlcode==100) {
                        if (get_exec_mode_c()==EXEC_MODE_INTERACTIVE)  {
				if (get_heading_flag()==1) {
                                	fprintf(file_out_result,"\n");
				}
                        }
                return 100;
        }

	if (firstFetchInit) {
		A4GL_debug("Calcualting how to display");
		set_display_mode();
		A4GL_debug("Mode = %d\n",display_mode);
		firstFetchInit=0;
	}


        if (sqlca.sqlcode<0) {
                A4GL_push_char("Fetch error...");
                A4GL_display_error(0,0);
                sleep(1);
                return sqlca.sqlcode;
        }



        (*raffected)++;

        if (fetchFirst==1) {
                        if (get_exec_mode_c()==EXEC_MODE_INTERACTIVE)  {
				if (display_mode!=DISPLAY_UNLOAD) {
                                	if (get_heading_flag()==1) fprintf(file_out_result,"\n");
					
				}
                        }
                        else {
				if (display_mode!=DISPLAY_UNLOAD) {
                                	if (get_heading_flag()==1) fprintf(exec_out,"\n");
				}
                        }
        }

        if (display_mode==DISPLAY_ACROSS&&fetchFirst==1 && get_heading_flag()==1) {
                for (a=0;a<numberOfColumns;a++) {
                        if (get_exec_mode_c()==EXEC_MODE_INTERACTIVE)  {

                                A4GL_assertion(file_out_result==0,"No output file (5)");
                                if (a) fprintf(file_out_result," ");
                                if (columnAlign[a]) { // CA 1
                                        fprintf(file_out_result,"%*.*s",columnWidths[a],columnWidths[a],columnNames[a]);  // CA 1
                                } else { // CA 1
                                        fprintf(file_out_result,"%-*.*s",columnWidths[a],columnWidths[a],columnNames[a]); // CA 1
                                } // CA 1
                        }
                        else {
                                A4GL_assertion(exec_out==0,"No output file (6)");
                                if (a) fprintf(exec_out," ");
                                if (columnAlign[a]) { // CA 1
                                        fprintf(exec_out,"%*.*s",columnWidths[a],columnWidths[a],columnNames[a]); // CA 1
                                } else { // CA 1
                                        fprintf(exec_out,"%-*.*s",columnWidths[a],columnWidths[a],columnNames[a]); // CA 1
                                } // CA 1
                        }
                }
                if (get_exec_mode_c()==EXEC_MODE_INTERACTIVE)  {
                        A4GL_assertion(file_out_result==0,"No output file (7)");
				if (display_mode!=DISPLAY_UNLOAD) {
                        		fprintf(file_out_result,"\n\n");
				}
                } else {
                        A4GL_assertion(exec_out==0,"No output file (8)");
				if (display_mode!=DISPLAY_UNLOAD) {
                        		fprintf(exec_out,"\n\n");
				}
                }

                outlines+=2;
                fetchFirst=0;
        }
        for (a=1;a<=numberOfColumns ;a++) {
                if (printField(file_out_result,a,"descExec")==1) {
                        A4GL_debug("Break Early %d of %d ",a,numberOfColumns);
                        break;
                }

                if (a<numberOfColumns && display_mode==DISPLAY_ACROSS) {
			if (get_heading_flag()==1) {
                        	if (get_exec_mode_c()==EXEC_MODE_INTERACTIVE)
                                	fprintf(file_out_result," ");
                        	else
                                	fprintf(exec_out," ");
			} else {
                        	if (get_exec_mode_c()==EXEC_MODE_INTERACTIVE)
                                	fprintf(file_out_result,"%s",get_delim_flag());
                        	else
                                	fprintf(exec_out,"%s",get_delim_flag());
			}
                }
        }

        if (display_mode==DISPLAY_ACROSS) {
                if (get_exec_mode_c()==EXEC_MODE_INTERACTIVE)
                        fprintf(file_out_result,"\n");
                else
                        fprintf(exec_out,"\n");
                outlines++;
        }

        if (display_mode==DISPLAY_UNLOAD) {
		fprintf(f_unloadFile,"\n");
	}

        if (display_mode==DISPLAY_DOWN) {
                if (get_exec_mode_c()==EXEC_MODE_INTERACTIVE)
                        fprintf(file_out_result,"");
                else
                        fprintf(exec_out,"");

                outlines++;
        }

        return sqlca.sqlcode;
}




/******************************************************************************/
static int get_size(int dtype,int size) {
	switch(dtype) {
		case SQL3_DATE_TIME_TIMESTAMP: return 12;
		case SQL3_CHARACTER_VARYING:
                case SQL3_CHARACTER:   return size;
		case SQL3_BOOLEAN: return 5;
                case SQL3_SMALLINT:  return  6;
                case SQL3_INTEGER:    return  11;
                case SQL3_FLOAT:  return  11;
                case SQL3_REAL:        return  11;
                case SQL3_DOUBLE_PRECISION:        return  11;
                case SQL3_DECIMAL:        return  16;
                case SQL3_INTERVAL:       return 20;
	}
	return 10;
}



void cp_sqlca_full(char *file, int line) {
//printf("CHECK %s %d - %d (%s)\n",file,line,sqlca.sqlcode,mv_errmsg);
a4gl_sqlca.sqlcode=sqlca.sqlcode;
a4gl_sqlca.sqlerrd[0]=sqlca.sqlerrd[0];
a4gl_sqlca.sqlerrd[1]=sqlca.sqlerrd[1];
a4gl_sqlca.sqlerrd[2]=sqlca.sqlerrd[2];
a4gl_sqlca.sqlerrd[3]=sqlca.sqlerrd[3];
a4gl_sqlca.sqlerrd[4]=sqlca.sqlerrd[4];
a4gl_sqlca.sqlerrd[5]=sqlca.sqlerrd[5];
if (sqlca.sqlcode<0) {
	char *ptr;
	strcpy(mv_errmsg,sqlca.sqlerrm.sqlerrmc);
	//printf("--->%s\n",mv_errmsg);
	ptr=strstr(mv_errmsg,"in line");
	if (ptr) *ptr=0;
	//printf("2-->%s\n",mv_errmsg);
}



}
endcode


function connect_to_template1()
define lv_uname,lv_pass char(80)
define lv_connstr char(256)
let lv_uname	=get_username()
let lv_pass	=get_password()

if lv_uname is not null and length(lv_uname)>0 then
code
	EXEC SQL BEGIN DECLARE SECTION;
	char *e_uname;
	char *e_passwd;
	EXEC SQL END DECLARE SECTION;
	e_uname=lv_uname;
	e_passwd=lv_pass;	
	A4GL_trim(e_uname);
	A4GL_trim(e_passwd);
	EXEC SQL CONNECT TO template1 USER :e_uname USING :e_passwd;		// AS 'default';  ecpg 8.1.5
endcode
else
code
	EXEC SQL CONNECT TO template1;		// AS 'default';  ecpg 8.1.5
endcode
end if

if sqlca.sqlcode=0 then
	return TRUE
else
	return FALSE
end if
end function


function connect_to_db(lv_dbname)
define lv_dbname char(80)
define lv_uname,lv_pass char(80)
define lv_connstr char(256)

let lv_uname	=get_username()
let lv_pass	=get_password()

# If theres nothing been set explicitly - 
# see if theres anything in the ACL file for
# this database.
IF lv_uname IS NULL OR lv_uname MATCHES " " THEN
code
	A4GL_trim(lv_dbname);
	A4GL_sqlid_from_aclfile(lv_dbname, lv_uname, lv_pass);
endcode
END IF

if lv_uname is not null and length(lv_uname)>0 then
code
	EXEC SQL BEGIN DECLARE SECTION;
	char *e_uname;
	char *e_passwd;
	char *e_dbname;
	EXEC SQL END DECLARE SECTION;
	e_uname=lv_uname;
	e_passwd=lv_pass;	
	e_dbname=lv_dbname;
	A4GL_trim(e_uname);
	A4GL_trim(e_passwd);
	A4GL_trim(e_dbname);
	EXEC SQL CONNECT TO :e_dbname USER :e_uname USING :e_passwd;		// AS 'default';  ecpg 8.1.5
endcode
else
code
	EXEC SQL BEGIN DECLARE SECTION;
	char *e_dbname;
	EXEC SQL END DECLARE SECTION;
	e_dbname=lv_dbname;
	A4GL_trim(e_dbname);
	EXEC SQL CONNECT TO :e_dbname;		// AS 'default';  ecpg 8.1.5
endcode
end if

if sqlca.sqlcode=0 then
	return TRUE
else
	return FALSE
end if
end function




function select_db()
define lv_cnt integer
define lv_curr_db char(255)
define lv_name char(255)
define lv_newname char(255)
define ndbs integer
define a integer
define lv_Err integer
let lv_curr_db=get_db();

LET lv_err=0
LET ndbs=0
IF NOT connect_to_template1() THEN
	ERROR "Unable to connect to 'template1' to get database list (Error : ", sqlca.sqlcode USING "-<<<<<<<<",")"
	RETURN
END IF

code
{
EXEC SQL BEGIN DECLARE SECTION;
char dbsname[80];
EXEC SQL END DECLARE SECTION;
EXEC SQL DECLARE c_getdbs CURSOR WITH HOLD FOR select datname from pg_catalog.pg_database order by datname;
if (sqlca.sqlcode!=0) {
	lv_err=sqlca.sqlcode;
	A4GL_debug("Error : %d", sqlca.sqlcode);
	goto here;
}
EXEC SQL  open c_getdbs;
if (sqlca.sqlcode!=0) {
	lv_err=sqlca.sqlcode;
	A4GL_debug("Error : %d", sqlca.sqlcode);
	goto here;
}
while (1)  {
	EXEC SQL FETCH c_getdbs INTO :dbsname;
	if (sqlca.sqlcode!=0) {
		lv_err=sqlca.sqlcode;
		break;
	}
	strcpy(lv_name,dbsname);
	ndbs++;
endcode
        call set_pick(ndbs,lv_name)
code
}
here:
; /* to make gcc-3.4 happy (avoid label at end of compound statement error) */
}
exec sql close c_getdbs;
endcode
if lv_err<0 then
	error "Error getting databases : ",lv_err
	return
end if

call set_pick_cnt(ndbs)

let lv_newname=prompt_pick("SELECT DATABASE >>","")

if lv_newname is null then
        let lv_newname=lv_curr_db
end if

if lv_newname is not null and lv_newname not matches " " then
        whenever error continue
        close database
        whenever error stop
code
	need_cursor_free=0;
endcode
        whenever error continue
        database lv_newname
        whenever error stop

        if sqlca.sqlcode=0 then
                call set_curr_db(lv_newname)
                call display_banner()
                message "Database Opened (",lv_newname clipped,")"
        else
		message "Database not opened..." attribute(reverse)
		sleep 1
                if check_and_report_error() then
			sleep 1
			call clear_screen_portion()
			return
		end if
        end if
end if
call clear_screen_portion()
end function


function drop_db()
define lv_cnt integer
define lv_curr_db char(255)
define lv_name char(255)
define lv_newname char(255)
define ndbs integer
define lv_sql char(255)
define a integer
let lv_curr_db=get_db();

code
{
#define MAXDBS 100
#define FASIZ (MAXDBS * 19)
char *dbsname[MAXDBS+1];
char            dbsarea[FASIZ];

 //sqlca.sqlcode = sqgetdbs(&ndbs, dbsname, MAXDBS, dbsarea, FASIZ);
 sqlca.sqlcode=0;
endcode

let ndbs=0
if sqlca.sqlcode!=0 then
        if check_and_report_error() then
        return
	end if
end if
for a=1 to ndbs
code
        strcpy(lv_name,dbsname[a-1]);
endcode
        call set_pick(a,lv_name)
end for
code
}



endcode


call set_pick_cnt(ndbs)
let lv_newname=prompt_pick("DROP DATABASE >>","")
if lv_newname is null then
        let lv_newname=lv_curr_db
end if



if lv_newname is not null and lv_newname not matches " " then

	if confirm_drop_db()="Yes" then
                        let lv_sql="drop database ",lv_newname
                        prepare p_drop from lv_sql
        whenever error continue
                        execute p_drop
        whenever error stop

                        if sqlca.sqlcode=0 then
                                call set_curr_db("")
                                call display_banner()
                                message "Database dropped..."
                        else
                                if check_and_report_error() then
					return
					# can't drop...
				end if
                        end if
        end if
end if

end function


function load_info_indexes(lv_tabname)
define lv_tabname char(255)
return 0
end function


function load_info_priv(lv_tabname)
define lv_tabname char(255)
error "Not Implemented load_info_priv"
return 0
end function


function load_info_ref(lv_tabname)
define lv_tabname char(255)
error "Not Implemented load_info_ref"
return 0
end function


function load_info_status(lv_tabname)
define lv_tabname char(255)
return 0
end function


function load_info_constraints(lv_tabname)
define lv_tabname char(255)
error "Not Implemented load_info_constraints"
return 0
end function


function load_info_triggers(lv_tabname)
define lv_tabname char(255)
return 0
end function


function load_info_fragments(lv_tabname)
define lv_tabname char(255)
error "Not Implemented load_info_fragments"
return 0
end function

function table_info()
define lv_tabname char(255)
define lv_txt char(128)
define lv_cont integer
define lv_option integer

        if not has_db() then
                call select_db()
        end if


        if not has_db() then
                return
        end if


        while true
                call table_select("INFO FOR TABLE >>") returning lv_tabname

                if lv_tabname is not null and lv_tabname not matches " " THEN
                else
                        return
                end if


                let lv_cont=0

		call set_exec_mode(0)
                let lv_txt="INFO - ",lv_tabname

		call set_info_text(lv_txt)

		while true
			case info_menu(lv_option)

                        when "Columns"
				CALL open_display_file()
                                if load_info_columns(lv_tabname) then
					CALL do_paginate()
				end if
				let lv_option=0

                        when "Indexes"
				CALL open_display_file()
                                if load_info_indexes(lv_tabname) then
					CALL do_paginate()
				end if
				let lv_option=1

                        when "Privileges"
				CALL open_display_file()
                                if load_info_priv(lv_tabname) then
					CALL do_paginate()
				end if
				let lv_option=2

                        when "References"
				CALL open_display_file()
                                if load_info_ref(lv_tabname) then
					CALL do_paginate()
				end if
				let lv_option=3

                        when "Status"
				CALL open_display_file()
                                if load_info_status(lv_tabname) then
					CALL do_paginate()
				end if
				let lv_option=4

                        when "cOnstraints"
				CALL open_display_file()
                                if load_info_constraints(lv_tabname) then
					CALL do_paginate()
				end if
				let lv_option=5

                        when "triGgers"
				CALL open_display_file()
                                if load_info_triggers(lv_tabname) then
					CALL do_paginate()
				end if
				let lv_option=6

                        when "Table"
                                let lv_cont=1
                                exit while

                        when "Fragments"
				CALL open_display_file()
                                if load_info_fragments(lv_tabname) then
					CALL do_paginate()
				end if
				let lv_option=8

                        when "Exit"
                                let lv_cont=0
                                exit while

		end case
                end while
        if lv_cont=0 then
                exit while
        end if
        end while

end function


FUNCTION do_paginate()
define rpaginate integer
MESSAGE ""
code
   while (1) {
        extern int outlines;

             if (outlines<=0) break;
             aclfgl_paginate(0);
             rpaginate=A4GL_pop_int();
             if (rpaginate!=0) break;
   }
endcode

END FUNCTION

FUNCTION load_info_tables()
	display "Not implemented load_info_tables" at 24,1
	sleep 1
end function



function sql_select_db(lv_dbname)
define lv_dbname char(64)
database lv_dbname
code
	need_cursor_free=0;
endcode
end function


function qry_translate()
define a integer
define b integer
define n integer
call open_tmpfile("SQL","r");
code
{
extern FILE *asql_yyin;
extern struct element *list;
extern int list_cnt;
asql_yyin=(FILE *)get_curr_mvfin("SQL");
clr_stmt();

a=my_pretend_yyparse();
a=list_cnt;
endcode
call close_tmpfile("SQL")

call open_tmpfile("SQL","w")
code
n=(long)get_curr_mvfin("SQL");
for (b=0;b<=a-1;b++) {
	char *s;
	char *p;
	s = A4GL_apisql_strdup (list[b].stmt);
	A4GL_debug("s=%s",s);
	A4GL_trim(s);
	p=A4GL_convert_sql_new("INFORMIX","POSTGRES8",s,0);
	A4GL_debug("p=%s",p);
	A4GL_debug("s=%s",s);
	if (n) fprintf((FILE *)n,"%s;\n\n",p);
	free(s);
	}
}
endcode

call close_tmpfile("SQL")
	
end function

function check_db(dbname) 
define dbname char(255)
return dbname
end function

code

int get_sqlcode(void ) {
	return sqlca.sqlcode;
}

void set_sqlcode(int n) {
	sqlca.sqlcode=n;
}


int ec_check_and_report_error() {
        if (sqlca.sqlcode<0) {
                aclfgl_check_and_report_error(0);
                return 1;
        } else {
                return 0;
        }

}



static char *safe_quotes(char *s) {
static char *p=0;
char *p2=0;
static int plen=0;
int a;
int c=0;

if(strlen(s)>plen) {
        plen=strlen(s);
        p=realloc(p,plen+1000);
}

c=0;
for (a=0;a<strlen(s);a++) {
        if (s[a]!=CHAR_BACKSLASH)   {p[c++]=s[a];continue;}
        continue;
}
p[c]=0;
p2=strdup(p);

c=0;
// First - escape any quotes
for(a=0;a<strlen(p2);a++) {
                if (p2[a]!=CHAR_SINGLE_QUOTE) {p[c++]=p2[a];continue;}
                p[c++]=CHAR_BACKSLASH;
                p[c++]=CHAR_SINGLE_QUOTE;
}
p[c]=0;
free(p2);
return p;
}



char delims[256];
//char *local_delim;
FILE *loadFile=0;



#define MAXLOADCOLS 256
#define MAXCOLLENGTH 32
/* Column name list where information is to be loaded */
char col_list[MAXLOADCOLS][MAXCOLLENGTH];
/* Array with pointers to each delimiter in current load line */
char *colptr[MAXLOADCOLS];


static int
find_delims (char delim)
{
  int cnt = 1;
  int a;
  colptr[0] = &loadbuff[0];

  for (a = 0; a < strlen (loadbuff); a++)
    {
      if ((loadbuff[a] == delim && loadbuff[a-1]!=CHAR_BACKSLASH) || loadbuff[a] == 0)
        {
          colptr[cnt++] = &loadbuff[a + 1];
        }
    }

  cnt--;

  for (a = 1; a <= cnt; a++)
    *(colptr[a] - 1) = 0;

  for (a = 0; a < cnt; a++)
    {
      A4GL_debug ("Field %d = %s", a, colptr[a]);
    }
  return cnt;
}


int asql_load_data(struct element *e,int *err_at_col) {
EXEC SQL BEGIN DECLARE SECTION;
char ins_str[32000];
EXEC SQL END DECLARE SECTION;
int raffected;
int b;
int a;
int ok;
char smbuff[2048];
int nfields;
int lineno=0;
        LoadUnload_delim=&delims[0];
        strcpy(LoadUnload_delim,"|");
*err_at_col=1;
        if (loadFile) fclose(loadFile);
        if (e->delim) { if (strlen(e->delim)) { strcpy(LoadUnload_delim,e->delim); } }
        loadFile=fopen(e->fname,"r");
        if (loadFile==0) { set_sqlcode(-805); return 0; }
        ok=0;
        while (1) {
                fgets (loadbuff, LOADBUFFSIZE - 1, loadFile);
                if (feof (loadFile)) {
                        A4GL_debug ("Got to end of the file");
                        break;
                }
                lineno++;
                stripnlload (loadbuff, LoadUnload_delim[0]);
                nfields = find_delims (LoadUnload_delim[0]);
                sprintf(ins_str,e->stmt);
                strcat(ins_str," values (");
                for (a=0;a<nfields;a++) {
                        if (a) strcat(ins_str,",");
                        sprintf(smbuff,"'%s'",safe_quotes(colptr[a]));
                        if (strcmp(smbuff,"''")==0) {strcpy(smbuff,"NULL");}
                        strcat(ins_str,smbuff);
                }
                strcat(ins_str,")");
		A4GLSQL_set_sqlerrm("",""); 
                EXEC SQL prepare p_loadit from :ins_str;

                if (get_sqlcode()!=0) { 
			A4GLSQL_set_sqlerrm(sqlca.sqlerrm.sqlerrmc,sqlca.sqlerrp); 
			break; 
		} else {
                	EXEC SQL execute p_loadit;
                	if (get_sqlcode()!=0) { 
				A4GLSQL_set_sqlerrm(sqlca.sqlerrm.sqlerrmc,sqlca.sqlerrp); 
				break; 
			}
		}
        }
        fclose(loadFile);
        loadFile=0;
        return lineno;

}


int can_do_unload() {
return 0;
}

int do_unload(struct element *e) {
return 0;
}


endcode


function set_current_db(lv_name)
define lv_name char(200)
return lv_name
end function



function init_sql()
define lv_server char(60)
define lv_uname,lv_passwd char(50)
define lv_hasacl integer

code
if (inited) {
        // don't reconnect if we've already connected
        lv_hasacl=0;
} else {
        inited++;
        lv_hasacl=A4GL_sqlid_from_aclfile("default",lv_uname,lv_passwd);
}
endcode

if lv_hasacl then
	call set_username(lv_uname,lv_passwd)
end if

end function



function find_table_col(lv_tab, lv_col)
define lv_tab,lv_t char(20)
define lv_col,lv_c char(20)
define lv_query char(2000)
define lv_tabid integer
call start_table_nocol()

let lv_query=" SELECT c.relname,c.oid FROM pg_catalog.pg_class c",
     " LEFT JOIN pg_catalog.pg_user u ON u.usesysid = c.relowner",
     " LEFT JOIN pg_catalog.pg_namespace n ON n.oid = c.relnamespace",
     " WHERE c.relkind IN ('r','')",
     " AND n.nspname NOT IN ('pg_catalog', 'pg_toast')",
     " AND pg_catalog.pg_table_is_visible(c.oid)",
     " AND c.relname LIKE '",lv_tab clipped,"'",
     "  ORDER BY 1"

	prepare p_qxc from lv_query
	declare c_gettables_findc cursor for p_qxc
	foreach c_gettables_findc into lv_t,lv_tabid
        	let lv_query=" SELECT a.attname ",
                	" FROM pg_catalog.pg_attribute a ",
                	" WHERE a.attrelid = '",lv_tabid using "<<<<<<<<<","' AND a.attnum > 0 AND NOT a.attisdropped and a.attname LIKE '",lv_col clipped,"'",
                	" ORDER BY a.attname "

        	prepare p_qli21 from lv_query
        	DECLARE info_curs_fc CURSOR WITH HOLD FOR p_qli21
        	foreach info_curs_fc into lv_c
        		call add_table_col(lv_t,lv_c)
		end foreach
end foreach


call finish_table_col()
end function


function find_table_nocol(lv_tab)
define lv_tab,lv_t char(20)
define lv_col,lv_c char(20)
define lv_query char(2000)
call start_table_nocol()

let lv_query=" SELECT c.relname FROM pg_catalog.pg_class c",
     " LEFT JOIN pg_catalog.pg_user u ON u.usesysid = c.relowner",
     " LEFT JOIN pg_catalog.pg_namespace n ON n.oid = c.relnamespace",
     " WHERE c.relkind IN ('r','')",
     " AND n.nspname NOT IN ('pg_catalog', 'pg_toast')",
     " AND pg_catalog.pg_table_is_visible(c.oid)",
     " AND c.relname LIKE '",lv_tab clipped,"'",
     "  ORDER BY 1"


prepare p_qx from lv_query 

declare c_gettables_find cursor for p_qx
foreach c_gettables_find into lv_t
	call add_table_nocol(lv_t)
end foreach

call finish_table_nocol()
end function

################################################################################
#
# This function will read a $A4GL_PGHOSTS (if specified)
# which can be used to provide a 'pick list' of servers.
# Each host is defined using  : 
#
#        ServerName Host Port [username [password]]
#
# If any of these are not set - they will be prompted for
#
# Storing Usernames/Passwords in the PGHOSTS file is not recommended
# Its much better to set these in an ACL file (A4GL_SQLACL)..
# You can do this by putting in an entry in the form :
#
#      server:username:password
#
# (you can also specify the username/password at the database level)
#
################################################################################
function use_pghosts() 
DEFINE lv_host_file char(300)
DEFINE lv_server,lv_host,lv_port,lv_username,lv_password CHAR(80)
DEFINE lv_Records ARRAY[1000] OF RECORD
	lv_server,lv_host,lv_port,lv_username,lv_password CHAR(80)
END RECORD
DEFINE lv_a INTEGER
DEFINE lv_cnt INTEGER

#@ENV A4GL_PGHOSTS Specify a PGHOSTS file which works in a similar way to the SQLHOSTS file for informix for the 'CONNECT' option in asql
LET lv_host_file=fgl_getenv("A4GL_PGHOSTS")

IF lv_host_file IS NULL OR lv_host_file matches " " THEN
	RETURN NULL,NULL,NULL,NULL
END IF

LET lv_cnt=0

code
{
FILE *f_in;
char *ptr;
char buff[512];
A4GL_trim(lv_host_file);
f_in=fopen(lv_host_file,"r");
if (f_in==0) {
endcode
	# File doesn't exist
	ERROR "Invalid PGHOSTS setting"
	RETURN  NULL,NULL,NULL,NULL
code
}

while (1) {
		int a;
                if (feof(f_in)) break;
		strcpy(buff,"#");
                fgets(buff,sizeof(buff),f_in);
                A4GL_trim(buff);
                ptr=strchr(buff,'#'); if (ptr) {*ptr=0;}
		strcpy(lv_server,"");
		strcpy(lv_host,"");
		strcpy(lv_port,"");
		strcpy(lv_username,"");
		strcpy(lv_password,"");
                if (strlen(buff)==0) continue;
		a=sscanf(buff,"%s %s %s %s %s", lv_server, lv_host, lv_port, lv_username, lv_password);
		if (a<3) continue;

		if (strlen(lv_username)==0 && strlen(lv_password)==0) {
			// We might have the username/password in the aclfile..
			A4GL_trim(lv_server);
			A4GL_sqlid_from_aclfile(lv_server, lv_username, lv_password);
		}

		strcpy(lv_records[lv_cnt].lv_server, lv_server);
		strcpy(lv_records[lv_cnt].lv_host, lv_host);
		strcpy(lv_records[lv_cnt].lv_port, lv_port);
		strcpy(lv_records[lv_cnt].lv_username, lv_username);
		strcpy(lv_records[lv_cnt].lv_password, lv_password);
		lv_cnt++;
                }
fclose(f_in);

}
endcode

IF lv_cnt=0 THEN
	ERROR "No entries in PGHOSTS"
	RETURN  NULL,NULL,NULL,NULL
END IF
FOR lv_a=1 TO lv_cnt
         call  set_pick(lv_a,lv_records[lv_a].lv_server)
END FOR
call set_pick_cnt(lv_cnt)
call prompt_pick("SELECT SERVER >>","") returning lv_server
IF lv_server IS NULL OR lv_server MATCHES " " THEN
	RETURN  NULL,NULL,NULL,NULL
END IF

for lv_a=1 to lv_cnt
	IF lv_server=lv_records[lv_a].lv_server THEN
		RETURN lv_records[lv_a].lv_host, lv_records[lv_a].lv_port, lv_records[lv_a].lv_username, lv_records[lv_a].lv_password
	END IF
END FOR

ERROR "Strange : Couldn't find server PGHOSTS"
RETURN  NULL,NULL,NULL,NULL

end function
