# +----------------------------------------------------------------------+
# | Aubit SQL Access Program ASQL                                        |
# +----------------------------------------------------------------------+
# | Copyright (c) 2003-7 Aubit Computing Ltd                             |
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

FILE *f_unloadFile=0;
struct BINDING *gen_obind=0;
struct BINDING *gen_obind_copy=0;
int gen_obindcnt=0;
extern int fetchFirst;
int firstFetchInit=0;
int need_cursor_free=0;
#include "simple.h"
#define DISPLAY_ACROSS 1
#define DISPLAY_DOWN   2
#define DISPLAY_UNLOAD 3
#define EXEC_MODE_INTERACTIVE   0
#define EXEC_MODE_FILE          1
#define EXEC_MODE_OUTPUT        2

#define DTYPE_CHAR      0
#define DTYPE_SMINT     1
#define DTYPE_INT       2
#define DTYPE_FLOAT     3
#define DTYPE_SMFLOAT   4
#define DTYPE_DECIMAL   5
#define DTYPE_SERIAL    6
#define DTYPE_DATE      7
#define DTYPE_MONEY     8
#define DTYPE_DTIME     10
#define DTYPE_BYTE      11
#define DTYPE_TEXT      12
#define DTYPE_VCHAR     13
#define DTYPE_INTERVAL  14

int stdin_screen_width=-1;
extern char **columnNames;
extern int *columnWidths;
extern int *columnAlign; // CA1
extern FILE *file_out_result;
extern FILE *exec_out;
extern int outlines;
extern int display_mode;
int numberOfColumns=0;
char **colnames;
int colnamesize=-1;
extern char *LoadUnload_delim;

endcode



function check_db(dbname)
    define dbname char(255)
    return dbname
end function

function connection_connect()
    error "Not Implemented connection_connect"
end function




FUNCTION do_paginate()
  define rpaginate integer
    MESSAGE ""
    
code
    while (1) {
        extern int outlines;

        if (outlines <= 0)
            break;
        aclfgl_paginate(0);
        rpaginate = A4GL_pop_int();
        if (rpaginate != 0)
            break;
    }
endcode

END FUNCTION



function drop_db()
    error "Not implemented drop_db"
end function



function qry_translate()
  define a integer
  define b integer
  define n integer
  define lv_fname char(512)

    let lv_fname=get_tmp_fname("SQL")

code
{
    extern FILE *asql_yyin;
    extern struct element *list;
    extern int list_cnt;
    char *snew;
    char *dialect;
    A4GL_trim(lv_fname);
    dialect = acl_getenv_not_set_as_0("A4GL_TARGETDIALECT");
    if (dialect == 0)
        dialect = "POSTGRES";
    snew = A4GLSQLCV_convert_file(dialect, lv_fname);
    n = fopen(lv_fname, "w");
    if (n)
        fprintf((FILE *)n, "%s\n", snew);
    //free(snew);
    fclose(n);
    //printf("\n\r%s : %s \n\r",snew,lv_fname); fflush(stdout); sleep(5);
}
endcode

call display_tmp_file()


end function




function get_db_err_msg(lv_code)
  define lv_code integer
  define lv_err1 char(255)
  define lv_err2 char(255)
  
code
    A4GLSQL_get_errmsg(lv_code);
    A4GL_trim(lv_err2);
endcode

    return lv_err2
end function


function load_info_columns(lv_tabname)
  define lv_tabname char(37)   # schema + '.' + tabname
  define lv_arr array[1000] of char(18)
  define lv_a integer
  define lv_cnt integer
  define col_list array [1024] of char (18);
  define col_desc array [1024] of char (48);
  define lv_t integer 
  define lv_l char(20)
  define lv_buff char(80)

code
    lv_cnt = A4GLSQL_fill_array (1024, (char *) col_list, 18, col_desc, 48, "COLUMNS", 2, lv_tabname);
endcode

    for lv_a=1 to lv_cnt
        if col_desc[lv_a][2]="(" then
            let lv_t=col_desc[lv_a][1]
            let lv_l=col_desc[lv_a][3,48]
            let lv_l=lv_l[1,length(lv_l)-1]
            let col_desc[lv_a]=get_type(lv_t,lv_l)
        end if
        if col_desc[lv_a][3]="(" then
            let lv_t=col_desc[lv_a][1,2]
            let lv_l=col_desc[lv_a][4,48]
            let lv_l=lv_l[1,length(lv_l)-1]
            let col_desc[lv_a]=get_type(lv_t,lv_l)
        end if

        let col_list[lv_a]=col_list[lv_a]," "
        let lv_buff=col_list[lv_a]," ",col_desc[lv_a]
        
        call add_to_display_file(lv_buff)
    end for
    return 1
end function


function before_dot(s)
  define s char(254)

code
    int i;
    int found = 0;
    for (i = 0; i < sizeof(s); ++i)
    {
        if (s[i] == '.')
        {
            s[i] = 0;
            found = 1;
            break;
        }
    }
    if ( ! found)
        s[0] = 0;
endcode

    return s;
end function

function after_dot(s)
  define s char(254)
  define s1 char(254)

code
    int i;
    for (i = 0; i < 254; ++i)
        s1[i] = s[i];
    for (i = 0; i < sizeof(s); ++i)
    {
        if (s[i] == '.')
        {
            int j;
            for (j = 0; i+j+1 < sizeof(s1); ++j)
                s1[j] = s[i+j+1];
            break;
        }
    }
endcode

    return s1;
  
end function

function load_info_indexes(qname)
  define s char(255)
  define qname char(37)   # schema + '.' + tabname
  define tabname char(18)
  define schname char(8)
  define query char(4096)

  define idxname    char(18)
  define idxcols    char(254)
  define idxtype    char(8)


    initialize query to null
    let query = fgl_getenv("A4GL_ASQL_SELECT_INDEXES");

    let s = "Index Name"
    let s[20,28] = "Type"
    let s[30,80] = "Columns"

    CALL add_to_display_file(s)

    call before_dot(qname) returning schname;
    call after_dot (qname) returning tabname;

    prepare iidx from query
    declare cidx cursor for iidx
    foreach cidx using schname, tabname into idxname, idxcols, idxtype 
        let s = ""
        let s = idxname
        let s[20,28] = idxtype
        let s[30,79] = idxcols[1,50]
        CALL add_to_display_file(s)
        if (length(idxcols) > 50) then
            let s = ""
            let s[30,79] = idxcols[51, 100]
            CALL add_to_display_file(s)
        end if
        if (length(idxcols) > 100) then
            let s = ""
            let s[30,79] = idxcols[101, 150]
            CALL add_to_display_file(s)
        end if
    end foreach

    return 1
end function

function load_info_priv()
    error "Not Implemented Yet load_info_priv"
end function

function load_info_status()
    error "Not Implemented Yet load_info_status"
end function

function load_info_tables()
  define lv_tabname char(18)
  define lv_arr array[4000] of char(18)
  define lv_sch array[4000] of char(18)
  define lv_num_tables integer
  define lv_cnt integer
  
code
    lv_num_tables=A4GLSQL_fill_array(1000,(char *)lv_arr,18,(char *)lv_sch,18,"TABLES",0,0);
endcode


    call add_to_display_file("TableName")
    call add_to_display_file(" ")

    for lv_cnt=1 to lv_num_tables
        call add_to_display_file(lv_sch[lv_cnt] || "." || lv_arr[lv_cnt])
    end for

    return 1
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

        CALL set_exec_mode(0)


        let lv_txt="INFO - ",lv_tabname
        call set_info_text(lv_txt)
        while true
            let lv_option=-1

            case info_menu(lv_option)

                when "Columns" 
                    CALL open_display_file()
                    if load_info_columns(lv_tabname) then
                            call do_paginate()
                    end if
                    let lv_option=0

                when "Indexes" 
                    CALL open_display_file()
                    if load_info_indexes(lv_tabname) then
                            call do_paginate()
                    end if
                    let lv_option=0

                when "Table" 
                    let lv_cont=1
                    exit while

                when "Exit" 
                    let lv_cont=0
                    exit while

                otherwise
                    call niy()

            end case
        end while

        if lv_cont=0 then
            exit while
        end if
    end while


end function

function table_select(lv_prompt)
  define lv_prompt char(64)
  define lv_tabname char(255)
  define lv_cnt integer
  define lv_arr array[4000] of char(18)
  define lv_sch array[4000] of char(18)
  define lv_num_tables integer
  define lv_found integer

code
    lv_num_tables=A4GLSQL_fill_array(1000,
                                     (char *)lv_arr,18,
                                     (char *)lv_sch,18,"TABLES",0,0);
endcode


    for lv_cnt=1 to lv_num_tables
        call set_pick(lv_cnt, lv_sch[lv_cnt] || "." || lv_arr[lv_cnt])
    end for
    call set_pick_cnt(lv_cnt-1)

    while true
        call prompt_pick(lv_prompt,"") returning lv_tabname

        if lv_tabname is not null then
            let lv_found=0
            for lv_cnt=1 to lv_num_tables
                if upshift(lv_tabname) = upshift(lv_sch[lv_cnt] || "." || lv_arr[lv_cnt]) then
                    let lv_found=1
                    exit for
                end if
            end for
    
            if lv_found=0 then
                error "Table not found"
            else
                exit while
            end if
        else
            exit while
    end if
end while

return upshift(lv_tabname)

end function


function select_db()
  define lv_arr array[100] of char(100);
  define lv_num_dbs integer
  define lv_cnt integer
  define lv_curr_db char(255)
  define lv_name char(255)
  define lv_newname char(255)
  define a integer
    let lv_curr_db=get_db();

code
    lv_num_dbs=A4GLSQL_fill_array(100,(char *)lv_arr,100,0,0,"DATABASES",0,0);
endcode

    for a=1 to lv_num_dbs
        call set_pick(a,lv_arr[a])
    end for

    call set_pick_cnt(lv_num_dbs)

    let lv_newname=prompt_pick("SELECT DATABASE >>","")
    if lv_newname is null then
        let lv_newname=lv_curr_db
    end if

    if lv_newname is not null and lv_newname not matches " " then
        whenever error continue

        close database
        database lv_newname
        whenever error stop

        if sqlca.sqlcode=0 then
            call set_curr_db(lv_newname)
            call display_banner()
            message "Database Opened"
        else
            if check_and_report_error() then
                return
            end if
        end if
    end if
end function




function sql_select_db(lv_dbname)
define lv_dbname char(64)
database lv_dbname
end function





code
asql_explain(struct element *e) {
// Not implemented - use set explain on/set explain off instead...
}


int asql_load_data(struct element *e,int *err_at_col) {
	A4GL_assertion("Load data not implemented");
}



int prepare_query_1(char *s,char type,int *err_at_col) {
static int prepared;
char *p;
int qry_type;
p=s;
*err_at_col=1;
free_bind();
   if (strncasecmp(s,"database",8)==0) { return 1; }
   if (type>='1'&&type<='9') return 255;
   qry_type=0;
   if (type!='S'&&type!='s') qry_type=255;

	//A4GL_push_char(s);
	//aclfgl_prepareit(1);
   //P0REPARE stExec from :p;
	A4GL_trim(p);
   A4GLSQL_add_prepare("generic_stexecp",(void *)A4GLSQL_prepare_select(0,0,0,0,s,"__internal_generic",__LINE__,0,0));
   cp_sqlca();


   if (a4gl_sqlca.sqlcode>=0) prepared=1;
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
  err_at_col=1;
   if (prepared) return qry_type;
   return -1;
}


int execute_query_1(int *raffected,int *errat) {
                *raffected=0;
		A4GLSQL_execute_sql("generic_stexecp",0,0);
		if (a4gl_sqlca.sqlcode!=0)  {	
			*errat=1;
			return 0;
		}
                *raffected=a4gl_sqlca.sqlerrd[0];
        	return 1;
}


execute_select_free() {
	aclfgl_execute_select_free(0);
	if (a4gl_sqlca.sqlcode<0) return 0;
	return 1;
}


get_sqlcode() {
	return a4gl_sqlca.sqlcode;
}

set_sqlcode(int a) {
	a4gl_sqlca.sqlcode=a;
}




int execute_select_prepare(int *err_at_col,int type, int *hasrows) {
void *ptr;
static int done_alloc=0;
*hasrows=1;

open_display_file_c();

      ptr=A4GLSQL_find_prepare("generic_stexecp");
      A4GL_assertion(ptr==0,"Unable to find statement to execute...");

      A4GLSQL_declare_cursor(0+0,ptr,0,"generic_crexec");
      cp_sqlca();
      if (a4gl_sqlca.sqlcode<0) {A4GL_debug("Err3"); *err_at_col=1; return 0;}

        need_cursor_free=1;
   	A4GLSQL_open_cursor("generic_crexec",0,0);
        if (a4gl_sqlca.sqlcode<0) {A4GL_debug("Err3"); *err_at_col=1; return 0;}
        need_cursor_free=3;

        firstFetchInit=1;
return 1;
}





free_bind() {
int a;
	if (gen_obind) {
		for (a=0;a<gen_obindcnt;a++) {
			if (gen_obind[a].ptr) {
				free(gen_obind[a].ptr);
			}
		}
	}
	free(gen_obind);
	free(gen_obind_copy);
	gen_obind=0;
	gen_obind_copy=0;
	gen_obindcnt=0;
}

int
printField (FILE * outputFile, int idx, char *descName) {
	char buff[2048];
	char fmt[2048];
	char *char_var;


	if (A4GL_isnull(gen_obind[idx-1].dtype,gen_obind[idx-1].ptr)) {
		strcpy(buff,"");
	} else {
		switch (gen_obind[idx-1].dtype) {
			case DTYPE_VCHAR:
			case DTYPE_CHAR: strcpy(buff,gen_obind[idx-1].ptr); A4GL_trim(buff); break;
			case DTYPE_SERIAL:
			case DTYPE_INT: if (display_mode == DISPLAY_DOWN || display_mode == DISPLAY_UNLOAD) { sprintf (buff, "%ld", *(long *)gen_obind[idx-1].ptr); } else { sprintf (buff, "%*ld", columnWidths[idx - 1], *(long *)gen_obind[idx-1].ptr); } break;
			case DTYPE_SMINT: if (display_mode == DISPLAY_DOWN || display_mode == DISPLAY_UNLOAD) { sprintf (buff, "%d", *(short *)gen_obind[idx-1].ptr); } else { sprintf (buff, "%*d", columnWidths[idx - 1], *(short *)gen_obind[idx-1].ptr); } break;
			case DTYPE_SMFLOAT: if (display_mode == DISPLAY_DOWN || display_mode == DISPLAY_UNLOAD) { sprintf (buff, "%f", *(float *)gen_obind[idx-1].ptr); } else { sprintf (buff, "%*f", columnWidths[idx - 1], *(float *)gen_obind[idx-1].ptr); } break;
			case DTYPE_FLOAT: if (display_mode == DISPLAY_DOWN || display_mode == DISPLAY_UNLOAD) { sprintf (buff, "%lf", *(double *)gen_obind[idx-1].ptr); } else { sprintf (buff, "%*lf", columnWidths[idx - 1], *(double *)gen_obind[idx-1].ptr); } break;
			case DTYPE_DATE: 
				{
				char dt_c[200];
				long x;
				x=*(long *)gen_obind[idx-1].ptr;
          			A4GL_dtos (&x, dt_c, 19);
          			A4GL_trim (dt_c);
          			sprintf (buff, "%s",dt_c);
				break;
				}

			case DTYPE_DECIMAL:
				{
          				if (!A4GL_dectos (gen_obind[idx-1].ptr, buff,34)) {
						strcpy(buff,"");
              					A4GL_debug ("Bad decimal");
            				} else {
          					A4GL_trim (buff);
					}
					break;
				
				}

			case DTYPE_DTIME: 
				{

          				if (!A4GL_dttoc (gen_obind[idx-1].ptr, buff,25)) {
						strcpy(buff,"");
              					A4GL_debug ("Bad dtime");
            				} else {
          					A4GL_trim (buff);
					}
					break;
				}

			default :
				sprintf(buff,">Unhandled datatype %d<",gen_obind[idx-1].dtype);
	

		}
		if (strlen(buff)==0) strcpy(buff, " ");

	}


  switch (display_mode) {

 case DISPLAY_DOWN:
	if (get_heading_flag()==1) {
      		sprintf (fmt, "%%-%d.%ds %%s\n", colnamesize + 1, colnamesize + 1);
      		if (get_exec_mode_c () == EXEC_MODE_INTERACTIVE) {
         		fprintf (outputFile, fmt, columnNames[idx - 1], buff);
       		} else {
         		fprintf (exec_out, fmt, columnNames[idx - 1], buff);
       		}
	} else {
      		if (get_exec_mode_c () == EXEC_MODE_INTERACTIVE) {
          		fprintf (outputFile, "%s", buff);
        	} else {
          		fprintf (exec_out, "%s", buff);
        	}
	}
      outlines++; break;

  case DISPLAY_ACROSS:
      if (get_exec_mode_c () == EXEC_MODE_INTERACTIVE)
        {

          A4GL_debug ("EXECO '%s' '%20s' '%-20s'", buff, buff, buff);
          fprintf (outputFile, "%-*s", columnWidths[idx - 1], buff);
        }
      else {
        fprintf (exec_out, "%-*s", columnWidths[idx - 1], buff);
	}


	break;

  case DISPLAY_UNLOAD:
      fprintf (f_unloadFile, "%s", escape_delim (buff));
      fprintf (f_unloadFile, "%s", LoadUnload_delim);
	break;
	}
  return 0;
}

static int
get_size (int dtype, int size)
{
  switch (dtype)
    {
    case DTYPE_CHAR:
      return size;
    case DTYPE_SMINT:
      return 6;
    case DTYPE_INT:
      return 11;
    case DTYPE_FLOAT:
      return 11;
    case DTYPE_SMFLOAT:
      return 11;
    case DTYPE_DECIMAL:
      return 16;
    case DTYPE_SERIAL:
      return 10;
    case DTYPE_DATE:
      return 12;
    case DTYPE_MONEY:
      return 17;
    case DTYPE_DTIME:
      return 19;
    case DTYPE_BYTE:
      return 20;
    case DTYPE_TEXT:
      return 20;
    case DTYPE_VCHAR:
      return size;
    case DTYPE_INTERVAL:
      return 20;
    }
  return 10;
}

int field_widths() {
int index;
int datatype;
int size;
char *columnName;
int totsize=0;

numberOfColumns=A4GLSQL_describe_stmt ("generic_stexecp",0,5);

if (numberOfColumns==0) {
	// try the cursor instead...
	numberOfColumns=A4GLSQL_describe_stmt ("generic_crexec",0,5);
}

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

	columnName=A4GLSQL_describe_stmt ("generic_stexecp",index,1);
        datatype=A4GLSQL_describe_stmt ("generic_stexecp",index,0);
        size=A4GLSQL_describe_stmt ("generic_stexecp",index,3);
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
        if (datatype==DTYPE_SMINT || datatype==DTYPE_INT || datatype== DTYPE_FLOAT|| datatype== DTYPE_SMFLOAT ||datatype==DTYPE_SERIAL) {
                columnAlign[index-1]=1; // CA 1
        } else { // CA 1
                columnAlign[index-1]=0; // CA 1
        } // CA 1
        totsize+=size+1;
}

columnNames[numberOfColumns]=0;
return totsize;

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
                        display_mode = DISPLAY_ACROSS;
                }


}

int execute_sql_fetch(int *raffected, int *err_at_col) {
	int coltype;
	int colsize;
	int colname;
	int a;


	if (firstFetchInit) {
                set_display_mode();
                A4GL_debug("Mode = %d\n",display_mode);
                firstFetchInit=0;
	}
	// First things first - how many rows are we dealing with ?

	// Allocate some memory for them...
	

	if (gen_obind==0) {
		gen_obind=acl_malloc2(sizeof(struct BINDING)*numberOfColumns);
		gen_obind_copy=acl_malloc2(sizeof(struct BINDING)*numberOfColumns);
		memset(gen_obind,0, sizeof(struct BINDING)*numberOfColumns);
		memset(gen_obind_copy,0, sizeof(struct BINDING)*numberOfColumns);

		for (a=0;a<numberOfColumns;a++) {
			colname=A4GLSQL_describe_stmt ("generic_stexecp",a+1,1);
			coltype=A4GLSQL_describe_stmt ("generic_stexecp",a+1,0);
			colsize=A4GLSQL_describe_stmt ("generic_stexecp",a+1,3);

			//if (coltype==DTYPE_DATE) { coltype=DTYPE_CHAR; colsize=12; }

			gen_obind[a].dtype=coltype;
			gen_obind[a].size=colsize;
			gen_obind[a].start_char_subscript=0;
			gen_obind[a].end_char_subscript=0;

			if (colsize>1000) {
				gen_obind[a].ptr=malloc(colsize+10); // Leave a little overhead...
			} else {
				gen_obind[a].ptr=malloc(1024);
			}

			gen_obind_copy[a].ptr   = gen_obind[a].ptr;
			gen_obind_copy[a].dtype = gen_obind[a].dtype;
			gen_obind_copy[a].size  = gen_obind[a].size;

			A4GL_debug("DESCRIBED AS %s - %d %d",colname,coltype,colsize);
		}
	}

	A4GL_debug("describe returned numberOfColumns as %d %d\n",numberOfColumns);
	A4GLSQL_fetch_cursor("generic_crexec", 2, 1,numberOfColumns,gen_obind);

  if (a4gl_sqlca.sqlcode == 100)
    {
      if (get_exec_mode_c () == EXEC_MODE_INTERACTIVE)
        {
          if (display_mode != DISPLAY_UNLOAD)
            {
              A4GL_assertion (file_out_result == 0, "No output file (3.0)");
              fprintf (file_out_result, "\n");
            }
        }
		*err_at_col=1;
      return 100;
    }
  (*raffected)++;

  if (fetchFirst == 1)
    {
      if (display_mode != DISPLAY_UNLOAD)
        {
          if (get_exec_mode_c () == EXEC_MODE_INTERACTIVE)
            {
              A4GL_assertion (file_out_result == 0, "No output file (3.1)");
              if (get_heading_flag()==1) fprintf (file_out_result, "\n");
            }
          else
            {
              A4GL_assertion (exec_out == 0, "No output file (3.2)");
              if (get_heading_flag()==1) fprintf (exec_out, "\n");
            }
        }
    }
  if (display_mode == DISPLAY_ACROSS && fetchFirst == 1 && get_heading_flag()==1)
    {
      for (a = 0; a < numberOfColumns; a++)
        {
          if (get_exec_mode_c () == EXEC_MODE_INTERACTIVE)
            {
              A4GL_assertion (file_out_result == 0, "No output file (5)");
              if (a)
                fprintf (file_out_result, " ");
              if (columnAlign[a])
                {               // CA 1
                  fprintf (file_out_result, "%*.*s", columnWidths[a], columnWidths[a], columnNames[a]); // CA 1
                }
              else
                {               // CA 1
                  fprintf (file_out_result, "%-*.*s", columnWidths[a], columnWidths[a], columnNames[a]);        // CA 1
                }               // CA 1
            }
          else
            {
              A4GL_assertion (exec_out == 0, "No output file (6)");
              if (a)
                fprintf (exec_out, " ");
              if (columnAlign[a])
                {               // CA 1
                  fprintf (exec_out, "%*.*s", columnWidths[a], columnWidths[a], columnNames[a]);        // CA 1
                }
              else
                {               // CA 1
                  fprintf (exec_out, "%-*.*s", columnWidths[a], columnWidths[a], columnNames[a]);       // CA 1
                }               // CA 1
            }
        }
      if (get_exec_mode_c () == EXEC_MODE_INTERACTIVE)
        {
          A4GL_assertion (file_out_result == 0, "No output file (7)");
          fprintf (file_out_result, "\n\n");
        }
      else
        {
          A4GL_assertion (exec_out == 0, "No output file (8)");
          fprintf (exec_out, "\n\n");
        }

      outlines += 2;
      fetchFirst = 0;
    }
  for (a = 1; a <= numberOfColumns; a++)
    {
      if (printField (file_out_result, a, "descExec") == 1)
        {
          A4GL_debug ("Break Early %d of %d because I can't print it", a,
                      numberOfColumns);
          break;
        }

      if (a < numberOfColumns && display_mode == DISPLAY_ACROSS)
        {
	if (get_heading_flag()==1) {
          if (get_exec_mode_c () == EXEC_MODE_INTERACTIVE) fprintf (file_out_result, " ");
          else fprintf (exec_out, " ");
	} else {
          if (get_exec_mode_c () == EXEC_MODE_INTERACTIVE) fprintf (file_out_result, "%s",get_delim_flag());
          else fprintf (exec_out, "%s",get_delim_flag());
	}
        }
    }

  if (display_mode == DISPLAY_ACROSS)
    {
      if (get_exec_mode_c () == EXEC_MODE_INTERACTIVE)
        fprintf (file_out_result, "\n");
      else
        fprintf (exec_out, "\n");
      outlines++;
    }


  if (display_mode == DISPLAY_UNLOAD)
    {
      fprintf (f_unloadFile, "\n");

    }
  if (display_mode == DISPLAY_DOWN)
    {
      if (get_exec_mode_c () == EXEC_MODE_INTERACTIVE)
        fprintf (file_out_result, "");
      else
        fprintf (exec_out, "");

      outlines++;
    }


		*err_at_col=1;
	return a4gl_sqlca.sqlcode;
	
}

cp_sqlca() {
// Do nothing - 'cos we don't need too...
}



int can_do_unload() {
return 0;
}


int do_unload(struct element *e) {
return 0;
}


endcode



function execute_select_free()
code
   A4GLSQL_close_cursor("generic_crexec");
   A4GLSQL_free_cursor ("generic_stexecp");
   A4GLSQL_free_cursor ("generic_crexec");
endcode
code
free_bind();
endcode
end function

function prepareit(p)
define p char(20000)
code
	if (need_cursor_free) { 
		printf("----> %d\n",need_cursor_free); 
			execute_select_free(); 
	}
endcode
   PREPARE stExecP from p
end function


function set_current_db(lv_name)
define lv_name char(200)
return lv_name
end function




FUNCTION get_type(l_coltype, l_collength)
DEFINE l_coltype     INTEGER,
       l_collength   INTEGER,
       type_text CHAR(41)

CASE
WHEN l_coltype=0 OR l_coltype=256 LET type_text="CHAR(", l_collength USING "<<<", ")"
WHEN l_coltype=1 OR l_coltype=257 LET type_text="SMALLINT"
WHEN l_coltype=2 OR l_coltype=258 LET type_text="INTEGER"
WHEN l_coltype=3 OR l_coltype=259 LET type_text="FLOAT"
WHEN l_coltype=4 OR l_coltype=260 LET type_text="SMALLFLOAT"
WHEN l_coltype=5 OR l_coltype=261 LET type_text="DECIMAL"
    LET type_text = dec_length(l_collength, type_text)
WHEN l_coltype=6 OR l_coltype=262
    IF l_collength > 1 THEN
        LET type_text="SERIAL(",
            l_collength USING "<<<<<<<<<&", ")"
    ELSE
        LET type_text="SERIAL"
    END IF
WHEN l_coltype=7 OR l_coltype=263 LET type_text="DATE"
WHEN l_coltype=8 OR l_coltype=264 LET type_text="MONEY"
    LET type_text = dec_length(l_collength, type_text)
WHEN l_coltype=10 OR l_coltype=266
    LET type_text="DATETIME"
    LET type_text = dt_length(l_collength, type_text)
WHEN l_coltype=11 OR l_coltype=267 LET type_text="BYTE"
WHEN l_coltype=12 OR l_coltype=268 LET type_text="TEXT"
WHEN l_coltype=13 OR l_coltype=269 LET type_text="VARCHAR"
    LET type_text = varc_length(l_collength, type_text)
WHEN l_coltype=14 OR l_coltype=270
    LET type_text="INTERVAL"
    LET type_text = dt_length(l_collength, type_text)
OTHERWISE
    LET type_text="????"
END CASE

## Now the not nulls
IF l_coltype > 255 THEN
    LET type_text=type_text CLIPPED, " NOT NULL"
END IF

RETURN type_text

END FUNCTION


FUNCTION dec_length(l_collength, type_text)
# calculate length & precision for DECIMAL & MONEY data types
DEFINE type_text CHAR(41)
DEFINE len, prec INTEGER   # Length & Precision
DEFINE l_collength   INTEGER

LET len = l_collength / 256
LET prec = l_collength mod 256
IF prec > len THEN
    IF type_text = "DECIMAL" THEN
        # floating precision
        INITIALIZE prec TO NULL
    ELSE
        # 0 precision
        LET prec = 0
    END IF
END IF

IF prec IS NULL THEN
    LET type_text = type_text CLIPPED, "(", len USING "<<<<&", ")"
ELSE
    LET type_text = type_text CLIPPED, "(", len USING "<<<<&", ",",
        prec USING "<<<<&", ")"
END IF

RETURN type_text

END FUNCTION

FUNCTION varc_length(l_collength, type_text)
# calculate max & min length for VARCHAR data types
DEFINE l_collength   INTEGER
DEFINE type_text CHAR(41)
DEFINE minl, maxl INTEGER  # Length & Precision

LET maxl = l_collength mod 256
LET minl = l_collength / 256

IF minl < 2 THEN
    LET type_text = type_text CLIPPED, "(", maxl USING "<<<<&", ")"
ELSE
    LET type_text = type_text CLIPPED, "(", maxl USING "<<<<&", ",",
        minl USING "<<<<&", ")"
END IF

RETURN type_text

END FUNCTION


FUNCTION dt_length(l_collength, type_text)
# calculate range for DATETIME & INTERVAL
DEFINE l_collength   INTEGER
DEFINE type_text CHAR(41)

CASE
WHEN l_collength = 459 LET type_text = type_text CLIPPED, " FRACTION TO FRACTION(1)"
WHEN l_collength = 546 LET type_text = type_text CLIPPED, " MONTH TO MONTH"
WHEN l_collength = 580 LET type_text = type_text CLIPPED, " DAY TO DAY"
WHEN l_collength = 614 LET type_text = type_text CLIPPED, " HOUR TO HOUR"
WHEN l_collength = 648 LET type_text = type_text CLIPPED, " MINUTE TO MINUTE"
WHEN l_collength = 682 LET type_text = type_text CLIPPED, " SECOND TO SECOND"
WHEN l_collength = 716 LET type_text = type_text CLIPPED, " FRACTION TO FRACTION(2)"
WHEN l_collength = 939 LET type_text = type_text CLIPPED, " SECOND TO FRACTION(1)"
WHEN l_collength = 973 LET type_text = type_text CLIPPED, " FRACTION TO FRACTION"
WHEN l_collength = 1024 LET type_text = type_text CLIPPED, " YEAR TO YEAR"
WHEN l_collength = 1060 LET type_text = type_text CLIPPED, " MONTH TO DAY"
WHEN l_collength = 1094 LET type_text = type_text CLIPPED, " DAY TO HOUR"
WHEN l_collength = 1128 LET type_text = type_text CLIPPED, " HOUR TO MINUTE"
WHEN l_collength = 1162 LET type_text = type_text CLIPPED, " MINUTE TO SECOND"
WHEN l_collength = 1196 LET type_text = type_text CLIPPED, " SECOND TO FRACTION(2)"
WHEN l_collength = 1230 LET type_text = type_text CLIPPED, " FRACTION TO FRACTION(4)"
WHEN l_collength = 1419 LET type_text = type_text CLIPPED, " MINUTE TO FRACTION(1)"
WHEN l_collength = 1453 LET type_text = type_text CLIPPED, " SECOND TO FRACTION"
WHEN l_collength = 1487 LET type_text = type_text CLIPPED, " FRACTION TO FRACTION(5)"
WHEN l_collength = 1538 LET type_text = type_text CLIPPED, " YEAR TO MONTH"
WHEN l_collength = 1574 LET type_text = type_text CLIPPED, " MONTH TO HOUR"
WHEN l_collength = 1608 LET type_text = type_text CLIPPED, " DAY TO MINUTE"
WHEN l_collength = 1642 LET type_text = type_text CLIPPED, " HOUR TO SECOND"
WHEN l_collength = 1676 LET type_text = type_text CLIPPED, " MINUTE TO FRACTION(2)"
WHEN l_collength = 1710 LET type_text = type_text CLIPPED, " SECOND TO FRACTION(4)"
WHEN l_collength = 1899 LET type_text = type_text CLIPPED, " HOUR TO FRACTION(1)"
WHEN l_collength = 1933 LET type_text = type_text CLIPPED, " MINUTE TO FRACTION"
WHEN l_collength = 1967 LET type_text = type_text CLIPPED, " SECOND TO FRACTION(5)"
WHEN l_collength = 2052 LET type_text = type_text CLIPPED, " YEAR TO DAY"
WHEN l_collength = 2088 LET type_text = type_text CLIPPED, " MONTH TO MINUTE"
WHEN l_collength = 2122 LET type_text = type_text CLIPPED, " DAY TO SECOND"
WHEN l_collength = 2156 LET type_text = type_text CLIPPED, " HOUR TO FRACTION(2)"
WHEN l_collength = 2190 LET type_text = type_text CLIPPED, " MINUTE TO FRACTION(4)"
WHEN l_collength = 2379 LET type_text = type_text CLIPPED, " DAY TO FRACTION(1)"
WHEN l_collength = 2413 LET type_text = type_text CLIPPED, " HOUR TO FRACTION"
WHEN l_collength = 2447 LET type_text = type_text CLIPPED, " MINUTE TO FRACTION(5)"
WHEN l_collength = 2566 LET type_text = type_text CLIPPED, " YEAR TO HOUR"
WHEN l_collength = 2602 LET type_text = type_text CLIPPED, " MONTH TO SECOND"
WHEN l_collength = 2636 LET type_text = type_text CLIPPED, " DAY TO FRACTION(2)"
WHEN l_collength = 2670 LET type_text = type_text CLIPPED, " HOUR TO FRACTION(4)"
WHEN l_collength = 2859 LET type_text = type_text CLIPPED, " MONTH TO FRACTION(1)"
WHEN l_collength = 2893 LET type_text = type_text CLIPPED, " DAY TO FRACTION"
WHEN l_collength = 2927 LET type_text = type_text CLIPPED, " HOUR TO FRACTION(5)"
WHEN l_collength = 3080 LET type_text = type_text CLIPPED, " YEAR TO MINUTE"
WHEN l_collength = 3116 LET type_text = type_text CLIPPED, " MONTH TO FRACTION(2)"
WHEN l_collength = 3150 LET type_text = type_text CLIPPED, " DAY TO FRACTION(4)"
WHEN l_collength = 3373 LET type_text = type_text CLIPPED, " MONTH TO FRACTION"
WHEN l_collength = 3407 LET type_text = type_text CLIPPED, " DAY TO FRACTION(5)"
WHEN l_collength = 3594 LET type_text = type_text CLIPPED, " YEAR TO SECOND"
WHEN l_collength = 3630 LET type_text = type_text CLIPPED, " MONTH TO FRACTION(4)"
WHEN l_collength = 3851 LET type_text = type_text CLIPPED, " YEAR TO FRACTION(1)"
WHEN l_collength = 3887 LET type_text = type_text CLIPPED, " MONTH TO FRACTION(5)"
WHEN l_collength = 4108 LET type_text = type_text CLIPPED, " YEAR TO FRACTION(2)"
WHEN l_collength = 4365 LET type_text = type_text CLIPPED, " YEAR TO FRACTION"
WHEN l_collength = 4622 LET type_text = type_text CLIPPED, " YEAR TO FRACTION(4)"
WHEN l_collength = 4879 LET type_text = type_text CLIPPED, " YEAR TO FRACTION(5)"
OTHERWISE LET type_text = type_text CLIPPED, " ????"
END CASE

RETURN type_text

END FUNCTION


function init_sql()
end function
function find_table_col(lv_tab, lv_col)
define lv_tab,lv_t char(20)
define lv_col,lv_c char(20)
call start_table_col()
call finish_table_col()
end function


function find_table_nocol(lv_tab)
define lv_tab,lv_t char(20)
define lv_col,lv_c char(20)
call start_table_nocol()
call finish_table_nocol()
end function

