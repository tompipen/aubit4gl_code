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

FILE *unloadFile=0;
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
extern char *delim;

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

             if (outlines<=0) break;
             aclfgl_paginate(0);
             rpaginate=A4GL_pop_int();
             if (rpaginate!=0) break;
   }
endcode

END FUNCTION



function drop_db()
	error "Not implemented drop_db"
end function

function qry_translate()
	error "Not Implemented qry_translate"
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


function load_info_columns()
error "Not Implemented Yet load_info_columns"
end function

function load_info_indexes()
error "Not Implemented Yet load_info_indexes"
end function

function load_info_priv()
error "Not Implemented Yet load_info_priv"
end function

function load_info_status()
error "Not Implemented Yet load_info_status"
end function

function load_info_tables()
error "Not Implemented Yet load_info_tables"
end function

function table_info()
error "Not Implemented Yet table_info"
end function

function table_select()
error "Not Implemented Yet table_select"
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


int asql_load_data(struct element *e) {
}



int prepare_query_1(char *s,char type) {
static int prepared;
char *p;
int qry_type;
p=s;

   if (strncasecmp(s,"database",8)==0) { return 1; }
   if (type>='1'&&type<='9') return 255;
   qry_type=0;
   if (type!='S'&&type!='s') qry_type=255;

	//A4GL_push_char(s);
	//aclfgl_prepareit(1);
   //P0REPARE stExec from :p;
	A4GL_trim(p);
   A4GLSQL_add_prepare("generic_stexec",(void *)A4GLSQL_prepare_select(0,0,0,0,s));
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

   if (prepared) return qry_type;
   return -1;
}


int execute_query_1(int *raffected) {
                *raffected=0;
		A4GLSQL_execute_sql("m1_stexec",0,0);
		if (a4gl_sqlca.sqlcode!=0)  return 0;
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




int execute_select_prepare() {
void *ptr;
static int done_alloc=0;


open_display_file_c();
if (need_cursor_free) {
    execute_select_free();
}
ptr=A4GLSQL_find_prepare("generic_stexec");
A4GL_assertion(ptr==0,"Unable to find statement to execute...");

A4GLSQL_declare_cursor(0+0,ptr,0,"generic_crexec");
cp_sqlca();
      if (a4gl_sqlca.sqlcode<0) {A4GL_debug("Err3"); return 0;}

      need_cursor_free=1;
   	A4GLSQL_open_cursor("generic_crexec",0,0);
        if (a4gl_sqlca.sqlcode<0) {A4GL_debug("Err3"); return 0;}
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
			case DTYPE_CHAR: strcpy(buff,gen_obind[idx-1].ptr); A4GL_trim(buff); break;
			case DTYPE_INT: if (display_mode == DISPLAY_DOWN || display_mode == DISPLAY_UNLOAD) { sprintf (buff, "%ld", *(long *)gen_obind[idx-1].ptr); } else { sprintf (buff, "%*ld", columnWidths[idx - 1], *(long *)gen_obind[idx-1].ptr); } break;
			case DTYPE_SMINT: if (display_mode == DISPLAY_DOWN || display_mode == DISPLAY_UNLOAD) { sprintf (buff, "%d", *(short *)gen_obind[idx-1].ptr); } else { sprintf (buff, "%*d", columnWidths[idx - 1], *(short *)gen_obind[idx-1].ptr); } break;
			case DTYPE_SMFLOAT: if (display_mode == DISPLAY_DOWN || display_mode == DISPLAY_UNLOAD) { sprintf (buff, "%f", *(float *)gen_obind[idx-1].ptr); } else { sprintf (buff, "%*f", columnWidths[idx - 1], *(float *)gen_obind[idx-1].ptr); } break;
			case DTYPE_FLOAT: if (display_mode == DISPLAY_DOWN || display_mode == DISPLAY_UNLOAD) { sprintf (buff, "%lf", *(double *)gen_obind[idx-1].ptr); } else { sprintf (buff, "%*lf", columnWidths[idx - 1], *(double *)gen_obind[idx-1].ptr); } break;
			case DTYPE_DATE: 
          			char_var = (char *) acl_malloc2 (sizeof (char) * 20);
          			A4GL_dtos (gen_obind_copy[idx-1].ptr, char_var, 19);
          			A4GL_trim (char_var);
          			sprintf (buff, "%s", char_var);
          			free (char_var);
				break;

			default :
				sprintf(buff,">%d<",gen_obind[idx-1].dtype);
	

		}
		if (strlen(buff)==0) strcpy(buff, " ");

	}

  if (display_mode == DISPLAY_DOWN)
    {
      sprintf (fmt, "%%-%d.%ds %%s\n", colnamesize + 1, colnamesize + 1);
      if (get_exec_mode_c () == EXEC_MODE_INTERACTIVE)
        {
          fprintf (outputFile, fmt, columnNames[idx - 1], buff);
        }
      else
        {
          fprintf (exec_out, fmt, columnNames[idx - 1], buff);
        }
      outlines++;
    }

  if (display_mode == DISPLAY_ACROSS)
    {
      if (get_exec_mode_c () == EXEC_MODE_INTERACTIVE)
        {

          A4GL_debug ("EXECO '%s' '%20s' '%-20s'", buff, buff, buff);
          fprintf (outputFile, "%-*s", columnWidths[idx - 1], buff);
        }
      else
        fprintf (exec_out, "%-*s", columnWidths[idx - 1], buff);
    }

  if (display_mode == DISPLAY_UNLOAD)
    {
      fprintf (unloadFile, "%s", escape_delim (buff));
      fprintf (unloadFile, "%s", delim);
    }

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
      return 17;
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

numberOfColumns=A4GLSQL_describe_stmt ("generic_stexec",0,5);
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

	columnName=A4GLSQL_describe_stmt ("generic_stexec",index,1);
        datatype=A4GLSQL_describe_stmt ("generic_stexec",index,0);
        size=A4GLSQL_describe_stmt ("generic_stexec",index,3);
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


}

int execute_sql_fetch(int *raffected) {
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
		for (a=0;a<numberOfColumns;a++) {
			colname=A4GLSQL_describe_stmt ("generic_stexec",a+1,1);
			coltype=A4GLSQL_describe_stmt ("generic_stexec",a+1,0);
			colsize=A4GLSQL_describe_stmt ("generic_stexec",a+1,3);
			if (coltype==DTYPE_DATE) {
				coltype=DTYPE_CHAR; colsize=12;
			}
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
              fprintf (file_out_result, "\n");
            }
          else
            {
              A4GL_assertion (exec_out == 0, "No output file (3.2)");
              fprintf (exec_out, "\n");
            }
        }
    }
  if (display_mode == DISPLAY_ACROSS && fetchFirst == 1)
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
          if (get_exec_mode_c () == EXEC_MODE_INTERACTIVE)
            fprintf (file_out_result, " ");
          else
            fprintf (exec_out, " ");
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
      fprintf (unloadFile, "\n");

    }
  if (display_mode == DISPLAY_DOWN)
    {
      if (get_exec_mode_c () == EXEC_MODE_INTERACTIVE)
        fprintf (file_out_result, "");
      else
        fprintf (exec_out, "");

      outlines++;
    }


	return a4gl_sqlca.sqlcode;
	
}

cp_sqlca() {
// Do nothing - 'cos we don't need too...
}

endcode



function execute_select_free()
          CLOSE crexec
          FREE stExec;
          FREE crexec; 
code
free_bind();
endcode
end function

function prepareit(p)
define p char(20000)
   PREPARE stExec from p
end function


function set_current_db(lv_name)
define lv_name char(200)
return lv_name
end function

