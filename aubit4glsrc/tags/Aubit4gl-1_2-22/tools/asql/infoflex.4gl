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
#include "simple.h"
#include <fcntl.h>
#include <limits.h>
EXEC SQL include sqltypes;
EXEC SQL BEGIN DECLARE SECTION;
int numberOfColumns=0;
EXEC SQL END DECLARE SECTION;
extern FILE *file_out_result;
static int inited=0;
static const char chexdigit[] = "0123456789abcdef";
extern FILE *exec_out;
extern int outlines;
extern int display_mode;
extern int fetchFirst;
static int get_size(int dtype,int size) ;
static void     outbyte(FILE *unlfile, char *buffer, long len);
#include <datetime.h>
#include <decimal.h>
#include <sqlca.h>
#include <sqlda.h>
#include <sqlstype.h>
#include <sqltypes.h>
/* #include "esqltype.h" */
#define loc_mode        lc_union.lc_file.lc_mode
#define sqlva           sqlvar_struct
#define NIL(x)         ((x)0)


struct sqlda *desc_output;


/* typedef loc_t               Blob; */

typedef struct decimal  Decimal;
typedef struct dtime    Datetime;
typedef struct intrvl   Interval;
int strip( char *str, int len );
int charcpy( unsigned char *target, unsigned char *source, long len );
void *buff_sqld;


off_t bpos = 0;


#define min(a, b ) ((a < b) ? a : b)


int global_length;
/*
int writeit( loc_t *loc, char *buf, int nbytes );
int closeit( loc_t *loc );
int openit( loc_t *loc, int flags, int bsize );
*/
int DetermineEndianNess(void);
int bbsize=0;
char *blobbuff;
#if !defined LITTLE_ENDIAN
#       define LITTLE_ENDIAN 1234
#endif

int EndianNess= -1;
int no_buf=0;
int bufsz=0;
int has_trans=0;
int is_ansi=0;
#ifdef __WIN32__
#ifndef __CYGWIN__
#include <windows.h>
#define USE_REGISTRY_SQLHOSTS
LONG createkey_infx (void);
static HKEY newkey_infx=0;
#endif
#endif


//int pflag=SQLRELOAD;
struct RecLoc
{
        size_t  rownum;     /* Record number */
        size_t  line_1;     /* First line number */
        size_t  line_2;     /* Last  line number */
};

typedef struct RecLoc RecLoc;
typedef unsigned char Uchar;


extern char *delim;
#define syntaxerror()  (sqlca.sqlcode = -201, sql_error("",""))
#define DISPLAY_ACROSS 1
#define DISPLAY_DOWN   2
#define DISPLAY_UNLOAD 3
#define FILENAMESIZE    128
#define ESQLC_PASTE2(x, y)      x ## y
#define ESQLC_PASTE(x, y)       ESQLC_PASTE2(x, y)
#define ESQLC_VERSION_CHECKER   ESQLC_PASTE(esqlc_version_, ESQLC_VERSION)


#ifndef DEFAULT_TMPDIR
#define DEFAULT_TMPDIR  "/tmp"
#endif

/*
enum BlobLocn
{
        BLOB_DEFAULT, BLOB_IN_MEMORY, BLOB_IN_ANONFILE, BLOB_IN_NAMEFILE
};
typedef enum BlobLocn BlobLocn;
*/
int stdin_screen_width= -1;
int colnamesize= -1;


/*
static BlobLocn def_blob_locn = BLOB_IN_MEMORY;
static Blob zero_blob = { 0 };
*/


static char *blob_dir = 0;
int load_ok;
char load_err_msg[256];
int load_err_line;


extern char **columnNames;
extern int *columnWidths;
extern int *columnAlign; // CA1


#define EXEC_MODE_INTERACTIVE   0
#define EXEC_MODE_FILE          1
#define EXEC_MODE_OUTPUT        2
FILE *f_unloadFile=0;

typedef struct sqlca_s  Sqlca;
typedef struct sqlda    Sqlda;
typedef struct sqlva    Sqlva;



#define LOADBUFFSIZE 32000
char loadbuff[LOADBUFFSIZE];
#define SQL_NAMELEN     128
#define SQL_USERLEN     32

#define MAXDBS 100
#define FASIZ (MAXDBS * 256)

#define SQL_TABNAMELEN  (3 * SQL_NAMELEN + SQL_USERLEN + sizeof("@:''."))
#define SQL_COLNAMELEN  (SQL_NAMELEN + 1)






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













endcode

#####################################################################
function get_db_err_msg(lv_code)
define lv_code integer
define lv_err1 char(255)
define lv_err2 char(255)
code
rgetmsg(sqlca.sqlcode,lv_err1,sizeof(lv_err1));
sprintf(lv_err2,lv_err1,sqlca.sqlerrm);
A4GL_trim(lv_err2);
endcode
return lv_err2
end function





#####################################################################
function table_select(lv_prompt)
define lv_prompt char(64)
define lv_tabname char(255)
define lv_cnt integer

let lv_cnt=1

#@ INFORMIX SPECIFIC
declare c_gettables_drop cursor for
        select tabname from systables
        where tabid>99 order by 1

foreach c_gettables_drop into lv_tabname
        call set_pick(lv_cnt,lv_tabname)
        let lv_cnt=lv_cnt+1
end foreach
call set_pick_cnt(lv_cnt-1)

while true
call prompt_pick_and_say(lv_prompt,"","") returning lv_tabname
if lv_tabname is not null then
	select tabname from systables where tabname=lv_tabname
	if sqlca.sqlcode=100 then
		error "Table not found"
	else
		exit while
	end if
else
	exit while
end if
end while

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
         l_coltype    INTEGER,
         l_collength  INTEGER
DEFINE lv_buff char(255)
define l_tabname char(255)
define lv_colname char(19)
define rpaginate integer


   SELECT tabid
     INTO l_tabid
     FROM systables
    WHERE tabname = l_tabname

   IF sqlca.sqlcode !=0 THEN
	IF sqlca.sqlcode=100 THEN
		ERROR "Table ", l_tabname clipped," was not found.."
	END IF
        IF  check_and_report_error() THEN
      	   RETURN  0
        END IF
   END IF


   DECLARE info_curs CURSOR FOR
    SELECT colname,coltype, collength, colno
      FROM syscolumns
     WHERE syscolumns.tabid = l_tabid
     ORDER BY colno

   LET i = 0
   FOREACH info_curs INTO lv_colname,l_coltype, l_collength
      LET i = i + 1

      LET lv_buff = lv_colname," " ,get_type(l_coltype, l_collength)
        CALL add_to_display_file(lv_buff)
   END FOREACH


return 1
END FUNCTION


FUNCTION do_paginate() 
define rpaginate integer
MESSAGE " "
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



#####################################################################
function connection_connect()
define lv_informixdir char(255)
define lv_passwd char(255)
define lv_username char(255)
define lv_cnt integer
define lv_server char(80)
define a,x,y integer
define buff char(255)
let lv_informixdir=fgl_getenv("INFORMIXDIR")
let lv_cnt=1
clear screen
call set_and_display_banner()
#
# In order to find out what connections are available
# Have a look in the sqlhosts file on unix
# or the HKEY_LOCAL_MACHINE/SOFTWARE/INFORMIX/SQLHOSTS
# possibly on an computer specified by INFORMIXSQLHOSTS
#
code
#ifdef USE_REGISTRY_SQLHOSTS
{
char buff[256];
LONG a;
a=createkey_infx();
while (1) {
	if (RegEnumKey(newkey_infx,lv_cnt-1,buff,255)!=ERROR_SUCCESS) break;
endcode
                                call  set_pick(lv_cnt,buff)
code
	lv_cnt++;
}
}

#else
{
char fname[1024];
FILE *f_in;
char *ptr;
A4GL_trim(lv_informixdir);
sprintf(fname,"%s/etc/sqlhosts",lv_informixdir);
f_in=fopen(fname,"r");
if (f_in==0) {
endcode
	error "Can't get list of database servers"
code
}
if (f_in!=0)  {
        while (1) {
                if (feof(f_in)) break;
                fgets(buff,sizeof(buff),f_in);
                ptr=strchr(buff,'#'); if (ptr) {*ptr=0;}
                ptr=strchr(buff,' '); if (ptr) {*ptr=0;}
                ptr=strchr(buff,'\t'); if (ptr) {*ptr=0;}
                A4GL_trim(buff);
                if (strlen(buff)) {
                        A4GL_debug("SQLHOSTS - buff='%s' (%d)",buff,strlen(buff));
endcode
                                call  set_pick(lv_cnt,buff)
code
                        //strcpy(mv_arr[lv_cnt-1],buff);
                        lv_cnt++;
                }
        }
	
	fclose(f_in);
}
}
#endif
endcode



call set_pick_cnt(lv_cnt-1)

if lv_cnt=1 then
        error "Either the SQLHOSTS file cannot be read - or it is empty"
end if

let lv_server=prompt_pick_and_say("SELECT DATABASE SERVER >>","","")

if lv_server is null or lv_server matches " " then
        return
end if

let lv_username=prompt_get( "USER NAME >> ","Enter the username")
#prompt "USER NAME >> " for lv_username

if lv_username is null or lv_username=" " then
else
	let lv_passwd=prompt_get("PASSWORD >> ","Enter the password")
        #prompt "PASSWORD >> " for lv_passwd attribute(invisible)
        if lv_passwd is null or lv_passwd matches " " then
                initialize lv_username to null
        end if
end if
#
code
{
static char buff[1024];
A4GL_trim(lv_server);
sprintf(buff,"INFORMIXSERVER=%s",lv_server);
A4GL_setenv("INFORMIXSERVER",lv_server,1);
}
endcode
call set_username(lv_username,lv_passwd)
let lv_server="@",lv_server
connect to lv_server user lv_username using lv_passwd

call select_db()
end function




code


void
cp_sqlca ()
{
  a4gl_sqlca.sqlcode = sqlca.sqlcode;
}


int
prepare_query_1 (char *s, char type,int *err_at_col)
{
  EXEC SQL BEGIN DECLARE SECTION;
  char *p;
  EXEC SQL END DECLARE SECTION;
  int qry_type;

*err_at_col=1;
  if (type >= '1' && type <= '9')
    return 255;

  p = s;

//printf("%c %s\n",type,s);

  EXEC SQL PREPARE stExec from:p;
  cp_sqlca ();

  if (ec_check_and_report_error ())
    {
      return -1;
    }



  if (buff_sqld) {
  	free(buff_sqld);
	buff_sqld=0;
  }

  cp_sqlca ();

  cp_sqlca ();
  if (ec_check_and_report_error ())
    {
      return -1;
    }


  EXEC SQL DESCRIBE stExec INTO desc_output;
  buff_sqld=sqdbuf_alloc(&_SQ1,desc_output,0);
  cp_sqlca ();
  qry_type = sqlca.sqlcode;
  return qry_type;
}

char get_delim() {
return '|';
}


/******************************************************************************/

int
execute_query_1 (int *raffected,int *errat)
{
  *raffected = 0;
  EXEC SQL EXECUTE stExec;
  cp_sqlca ();
  if (ec_check_and_report_error ())
    {
      return 0;
    }
  *raffected = sqlca.sqlerrd[2];
  EXEC SQL FREE stExec;
  cp_sqlca ();
  if (ec_check_and_report_error ())
    {
		*errat=1;
      return 0;
    }
  return 1;
}




/******************************************************************************/
static int
get_size (int dtype, int size)
{
  switch (dtype)
    {
    case SQLCHAR:
      return size;
    case SQLSMINT:
      return 6;
    case SQLINT:
      return 11;
    case SQLFLOAT:
      return 11;
    case SQLSMFLOAT:
      return 11;
    case SQLDECIMAL:
      return 16;
    case SQLSERIAL:
      return 10;
    case SQLDATE:
      return 12;
    case SQLMONEY:
      return 17;

    case SQLDTIME:
      return 21;
/*
    case SQLBYTES:
      return 20;
    case SQLTEXT:
      return 20;
*/
    case SQLVCHAR:
      return size;
    case SQLINTERVAL:
      return 20;
    }
  return 10;
}


endcode


#####################################################################
function select_db()
define lv_cnt integer
define lv_curr_db char(255)
define lv_name char(255)
define lv_newname char(255)
define lv_username char(80)
define lv_password char(80)
define ndbs integer
define a integer
let lv_curr_db=get_db();

code
{
//#define MAXDBS 100
//#define FASIZ (MAXDBS * 256)
char *dbsname[MAXDBS+1];
char            dbsarea[FASIZ];
char **list;
ndbs=0;

sqlca.sqlcode=0;

list=A4GL_gen_list_dbpath(".dbs",acl_getenv("DBPATH"));

for (a=0;list[a];a++) {
	ndbs++;
}


sqlca.sqlcode = 0; //sqgetdbs(&ndbs, dbsname, MAXDBS, dbsarea, FASIZ);

endcode

if sqlca.sqlcode!=0 then
	error "Some error getting databases"
	sleep 1 # getting db error
        if check_and_report_error() then
        	return
	end if
end if

for a=1 to ndbs
code
        strcpy(lv_name,list[a-1]);
endcode
        call set_pick(a,lv_name)
end for
code
}
endcode

call set_pick_cnt(ndbs)
let lv_newname=prompt_pick_and_say("SELECT DATABASE >>","","")
if lv_newname is null then
        let lv_newname=lv_curr_db
end if

if lv_newname is not null and lv_newname not matches " " then
        whenever error continue

        close database
	call connect_to_db(lv_newname)
	whenever error stop

        if sqlca.sqlcode=0 then
                call set_curr_db(lv_newname)
                call set_and_display_banner()
                message "Database Opened" 
        else
                if check_and_report_error() then
			whenever error continue
			close database
			whenever error stop
			return
		end if
        end if
end if

end function


#####################################################################
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
//char *dbsname[MAXDBS+1];
char            dbsarea[FASIZ];
char **list;
list=A4GL_gen_list_dbpath(".dbs",acl_getenv("DBPATH"));

if (list) {
	for (a=0;list[a];a++) {
		ndbs++;
	}
} 
 sqlca.sqlcode = 0; // sqgetdbs(&ndbs, dbsname, MAXDBS, dbsarea, FASIZ);

endcode

if sqlca.sqlcode!=0 then
        if check_and_report_error() then
        return
	end if
end if
for a=1 to ndbs
code
        strcpy(lv_name,list[a-1]);
endcode
        call set_pick(a,lv_name)
end for
code
}
endcode


call set_pick_cnt(ndbs)
let lv_newname=prompt_pick_and_say("DROP DATABASE >>","","")
if lv_newname is null then
        let lv_newname=lv_curr_db
end if



if lv_newname is not null and lv_newname not matches " " then

	if confirm_drop_db()= "Yes"  then
        		whenever error continue
                        	let lv_sql="drop database ",lv_newname
                        	prepare p_drop from lv_sql
                        	execute p_drop
			whenever error stop

                        if sqlca.sqlcode=0 then
                                call set_curr_db("")
                                call set_and_display_banner()
                                message "Database dropped..."
                        else
                                if check_and_report_error() then
					# Couldn't drop it...
				end if
                        end if
        end if
end if

end function




#####################################################################
function load_info_priv(lv_tabname)
define lv_tabname char(255)
define lv_tabid integer
define lv_outline char(80)
define lv_grantee char(8)
define lv_tabauth char(8)
let lv_tabid=get_tabid(lv_tabname)
declare c_getpriv cursor for
        select grantee, tabauth
from systabauth where tabid=lv_tabid


let lv_outline="User         Select             Update             Insert  Delete  Index  Alter"
#               1            14                 33                 52      60      68     75
 
call add_to_display_file(lv_outline)
call add_to_display_file(" ")

foreach c_getpriv into lv_grantee,lv_tabauth
	let lv_outline=lv_grantee
	
	if lv_tabauth[1]="S" or lv_tabauth[1]="s" then
		let lv_outline[14,32]="All"
	end if

	if lv_tabauth[2]="U" or lv_tabauth[2]="u" then
		let lv_outline[33,51]="All"
	end if

	if lv_tabauth[4]="I" or lv_tabauth[4]="i" then
		let lv_outline[52,59]="Yes"
	else
		let lv_outline[52,59]="No"
	end if

	if lv_tabauth[5]="D" or lv_tabauth[5]="d" then
		let lv_outline[60,67]="Yes"
	else
		let lv_outline[60,67]="No"
	end if

	if lv_tabauth[6]="x" or lv_tabauth[6]="x" then
		let lv_outline[68,74]="Yes"
	else
		let lv_outline[68,74]="No"
	end if

	if lv_tabauth[7]="A" or lv_tabauth[7]="a" then
		let lv_outline[75,80]="Yes"
	else
		let lv_outline[75,80]="No"
	end if

	if lv_tabauth[3]="*" then
		select distinct colauth[1,1] into lv_tabauth from syscolauth where tabid=lv_tabid
		if lv_tabauth[1]="S" or lv_tabauth[1]="s" then
			let lv_outline[14,32]="Some"
		end if
	
		select distinct colauth[2,2] into lv_tabauth from syscolauth where tabid=lv_tabid
		if lv_tabauth[1]="U" or lv_tabauth[1]="u" then
			let lv_outline[33,51]="Some"
		end if
	end if

	call add_to_display_file(lv_outline)
end foreach

return 1
end function


#####################################################################
function load_info_ref(lv_tabname)
define lv_tabname char(255)
define lv_tabid integer
let lv_tabid=get_tabid(lv_tabname)
error "Not Implemented load_info_ref" 

return 0
end function


#####################################################################
function load_info_status(lv_tabname)
define lv_tabname char(255)
define lv_rec record
	tabname char(20),
	owner char(20),
	rowsize integer,
	nrows integer,
	ncols integer,
	created date
	
end record
define lv_str char(255)
define lv_nrows integer
define lv_outline char(80)

let lv_nrows=0
let lv_str="select count(*) from ",lv_tabname
whenever error continue
prepare p_nrows from lv_str
declare c_get_nrows cursor for p_nrows
open c_get_nrows
fetch c_get_nrows into lv_nrows
close c_get_nrows
whenever error stop
let sqlca.sqlcode=0

select tabname,owner,rowsize,nrows,ncols,created into lv_rec.* 
from systables 
where tabname=lv_tabname

if sqlca.sqlcode=0 then
	call add_to_display_file(" ")
	call add_to_display_file(" ")
	call add_to_display_file(" ")

	let lv_outline="Table Name          ",lv_rec.tabname
	call add_to_display_file(lv_outline)
	let lv_outline="Owner               ",lv_rec.owner 
	call add_to_display_file(lv_outline)
	let lv_outline="Row Size            ",lv_rec.rowsize 
	call add_to_display_file(lv_outline)
	let lv_outline="Number Of Rows      ",lv_nrows," (Last Update Statistics:",lv_rec.nrows using "<<<<<<",")"  
	call add_to_display_file(lv_outline)
	let lv_outline="Number Of Columns   ",lv_rec.ncols  
	call add_to_display_file(lv_outline)
	let lv_outline="Date Created        ",lv_rec.created
	call add_to_display_file(lv_outline)
else
	display "BAD...." 
	sleep 1 # load info status bad
	return 0
end if

return 1
end function


#####################################################################
function load_info_constraints(lv_tabname)
define lv_tabname char(255)
define lv_tabid integer
let lv_tabid=get_tabid(lv_tabname)

error "Not Implemented load_info_constraints"
return  0

end function

#####################################################################
function get_tabid(lv_tabname)
define lv_tabname char(255)
define lv_tabid integer
let lv_tabname=downshift(lv_tabname)
select tabid into lv_tabid from systables
where tabname=lv_tabname
if sqlca.sqlcode=0 then
	return lv_tabid
else
	error "Unable to locate table"
	initialize lv_tabid to null
	return lv_tabid
end if
end function

#####################################################################
function load_info_triggers(lv_tabname)
define lv_tabname char(255)
define lv_trigname char(255)
define lv_text char(256)
define lv_tabid integer
define lv_cnt integer
define lv_systrig record
	trigname char(18),
	event char(1),
	old char(18),
	new char(18)
end record
define lv_str char(5000)
define lv_s1,lv_s2 integer


let lv_tabid=get_tabid(lv_tabname)

if lv_tabid is null then
	return 0
end if


declare c_gettrigs cursor for
	select trigname from systriggers where tabid=lv_tabid

let lv_cnt=1

foreach c_gettrigs into lv_trigname
	call set_pick(lv_cnt,lv_trigname)
	let lv_cnt=lv_cnt+1
end foreach

if lv_cnt=1 then
	error "No triggers defined."
	return 0
end if

call set_pick_cnt(lv_cnt-1)
let int_flag=false

call prompt_pick_and_say("INFO FOR TRIGGER >>","","") returning lv_trigname


if lv_trigname is null or lv_trigname = " " then
	return 0
end if

select trigname,event,old,new into lv_systrig.* from  systriggers
where tabid=lv_tabid
and trigname=lv_trigname
let lv_str="create trigger ",lv_trigname clipped
if lv_systrig.event="U" then
	let lv_str=lv_str clipped," update on ",lv_tabname
end if
if lv_systrig.event="I" then
	let lv_str=lv_str clipped," insert on ",lv_tabname
end if
if lv_systrig.event="D" then
	let lv_str=lv_str clipped," delete on ",lv_tabname
end if

if lv_systrig.old is not null or lv_systrig.new is not null then
	let lv_str=lv_str clipped," referencing "
	if lv_systrig.old is not null then
		let lv_str=lv_str clipped, " old as ",lv_systrig.old
	end if
	if lv_systrig.new is not null then
		let lv_str=lv_str clipped, " new as ",lv_systrig.new
	end if
end if


CALL add_to_display_file(lv_str)

let lv_str=" "
let lv_s1=1
declare c_gettrigb cursor for
select data,seqno from systriggers st,systrigbody stb
where st.trigid=stb.trigid
and   stb.datakey="A"
and  st.trigname=lv_trigname
and st.tabid=lv_tabid
order by 2

foreach c_gettrigb into lv_text
	let lv_s2=lv_s1+255
	let lv_str[lv_s1,lv_s2]=lv_text
	let lv_s1=lv_s1+256
end foreach
code
A4GL_debug("lv_str=%s",lv_str);
endcode
CALL add_to_display_file_wrapped(lv_str)
call add_to_display_file("")
return 1
end function




#####################################################################
function load_info_fragments(lv_tabname)
define lv_tabname char(255)
define lv_tabid integer

let lv_tabid=get_tabid(lv_tabname)
error "Not Implemented load_info_fragments"
return 1

end function


#####################################################################
function table_info()
define lv_tabname char(255)
define lv_txt char(128)
define lv_cont integer
define lv_last integer
let lv_last= -1
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

			case info_menu(lv_last)

			when "Columns" 
				let lv_last=0
				CALL open_display_file()
                		if load_info_columns(lv_tabname) then
					call do_paginate()
				end if

			when "Indexes" 
				let lv_last=1
				CALL open_display_file()
                		if  load_info_indexes(lv_tabname) then
					call do_paginate()
				end if

			when "Privileges" 
				let lv_last=2
				CALL open_display_file()
				if  load_info_priv(lv_tabname) then
					call do_paginate()
				end if

			when "References" 
				let lv_last=3
				CALL open_display_file()
				if  load_info_ref(lv_tabname) then
					call do_paginate()
				end if

			when "Status" 
				let lv_last=4
				call open_display_file()
				if load_info_status(lv_tabname) then
					call do_paginate()
				end if

			when "cOnstraints"
				let lv_last=5
				CALL open_display_file()
				if  load_info_constraints(lv_tabname)  then
					call do_paginate()
				end if

			when "triGgers" 
				let lv_last=6
				call open_display_file()
				if load_info_triggers(lv_tabname) then
					call do_paginate()
				end if

			when "Table" 
				let lv_last=7
				let lv_cont=1
				exit while

			when "Fragments" 
				let lv_last=8
				call open_display_file()
				if load_info_fragments(lv_tabname) then
					call do_paginate()
				end if

			when "Exit" 
				let lv_last=9
				let lv_cont=0
				exit while

			end case
		end while



	if lv_cont=0 then
		exit while
	end if
        end while

end function


#####################################################################
function load_info_tables() 
define lv_tabname char(18)
declare c_info_tables cursor for 
	select tabname from systables where tabid>99
call add_to_display_file("TableName")
call add_to_display_file(" ")
foreach c_info_tables into lv_tabname
call add_to_display_file(lv_tabname)
end foreach
return 1
end function



#####################################################################
function load_info_indexes(lv_tabname)
define lv_tabname char(255)
define lv_tabid integer
define lv_rec record 
	idx_name char(18),
 	type char(1),
	clust char(1)
end record
define lv_p array[8] of integer
define lv_cnt integer
define lv_colno integer
Define lv_colname char(18)
define lv_outfile char(255)
define lv_outline char(255)
define lv_old_index char(20)

let lv_old_index=" "



let lv_tabid=get_tabid(lv_tabname)

if lv_tabid is null then 
	return 0
end if


declare c_getindex cursor for
select idxname,idxtype,clustered,
	part1,
	part2,
	part3,
	part4,
	part5,
	part6,
	part7,
	part8 
from sysindexes where tabid=lv_tabid
order by idxtype desc,idxname

let lv_outline=" "
let lv_outline="Index Name"
let lv_outline[20,24]="Type"
let lv_outline[30,40]="Cluster"
let lv_outline[40,50]="Columns"

CALL add_to_display_file(lv_outline)
foreach  c_getindex into lv_rec.*, lv_p[1], lv_p[2], lv_p[3], lv_p[4], lv_p[5], lv_p[6], lv_p[7], lv_p[8]

for lv_cnt=1 to 8
	if lv_p[lv_cnt]!=0 then
		let lv_colno=lv_p[lv_cnt]
		select colname into lv_colname from syscolumns where tabid=lv_tabid and colno=lv_colno
		let lv_outline=" "
		if lv_old_index!=lv_rec.idx_name then
			if lv_old_index!=" " then
				CALL add_to_display_file(" ")
			end if
			let lv_old_index=lv_rec.idx_name
			let lv_outline=lv_rec.idx_name

			if lv_rec.type="U" then
				let lv_outline[20,30]="Unique"
			else
				let lv_outline[20,30]="Dupls"
			end if
			if lv_rec.type="C" then
				let lv_outline[30,40]="Yes"
			else
				let lv_outline[30,40]="No"
			end if
		end if
		let lv_outline[40,255]=lv_colname
		CALL add_to_display_file(lv_outline)
	end if
end for
end foreach 
return 1
end function


function connect_to_db(lv_dbname)
define lv_dbname char(64)
define lv_uname,lv_pass char(64)
let lv_uname=get_username()
let lv_pass=get_password()
whenever error continue

IF lv_uname is null OR lv_uname matches " " THEN
	DATABASE lv_dbname
ELSE
	connect to lv_dbname user lv_uname using lv_pass
END IF

whenever error stop
end function

function sql_select_db(lv_dbname)
define lv_dbname char(64)
call connect_to_db(lv_dbname)
end function

code

int ec_check_and_report_error() {

        if (sqlca.sqlcode<0) {
                aclfgl_check_and_report_error(0);
                return 1;
        } else {
                return 0;
        }

}


int get_sqlcode() { return sqlca.sqlcode; }
int local_set_sqlcode(int n) { sqlca.sqlcode=n; }




asql_explain(struct element *e) {
// Not implemented - use set explain on/set explain off instead...
}
endcode


function qry_translate()
error "Can't translate to informix"
return
end function

function check_db(dbname)
define dbname char(255)
if dbname matches "*@*" then
	return dbname
else
	let dbname=dbname 
end if
	return dbname
end function



function set_current_db(lv_name)
define lv_name char(255)
define lv_sn char(255)


return lv_name

end function

code


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
        if (s[a]!='\\')   {p[c++]=s[a];continue;}
        continue;
}
p[c]=0;
p2=strdup(p);

c=0;
// First - escape any quotes
for(a=0;a<strlen(p2);a++) {
                if (p2[a]!='\'') {p[c++]=p2[a];continue;}
                p[c++]='\'';
                p[c++]='\'';
}
p[c]=0;
free(p2);
return p;
}
char delims[256];
char *delim;
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
      if ((loadbuff[a] == delim && loadbuff[a-1]!='\\') || loadbuff[a] == 0)
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





/*
=====================================================================
                    Variables definitions
=====================================================================
*/








/*
** Return number of columns in table, or zero if table name invalid.
** Allow for 'owner'.tablename, "owner".tablename and owner.tablename
** This version does (finally) allow for temporary tables!
**
** The subterfuge with a_stmt circumvents the idiotic ESQL/C
** compiler which does not recognize that even though it cannot evaluate
** the size of an array, the C compiler is able to do so -- so it complains
** with a warning:
** Warning -33208: Runtime error is possible because size of 'stmt'
** is unknown.
*/
static int      cols_in_table(char *tabname)
{
	char            a_stmt[sizeof("SELECT * FROM ") + SQL_TABNAMELEN];
	EXEC SQL BEGIN DECLARE SECTION;
	char           *stmt = a_stmt;
	EXEC SQL END DECLARE SECTION;
	int             n_columns = 0;
	Sqlda          *d;

	sprintf(stmt, "SELECT * FROM %s", tabname);
	EXEC SQL PREPARE p_cols FROM :stmt;
	if (sqlca.sqlcode != 0)
	{
		sqlca.sqlcode = -206;	/* Table is not in database */
		strcpy(sqlca.sqlerrm,  tabname);
		sql_error("","");
	}
	else
	{
		EXEC SQL DESCRIBE p_cols INTO d;
		if (sqlca.sqlcode != 0 || d == 0)
		{
			sprintf(stmt, "Unexpected error on DESCRIBE for table %s\n", tabname);
			sqlca.sqlcode=-746;
        		sqlca.sqlerrd[1] = 0;
        		strcpy(sqlca.sqlerrm,  stmt);


			
		}
		n_columns = d->sqld;
		EXEC SQL FREE p_cols;
		if (sqlca.sqlcode != 0)
		{
			sprintf(stmt, "Unexpected error on FREE for table %s\n",
					tabname);
			sqlca.sqlcode=-746;
        		sqlca.sqlerrd[1] = 0;
        		strcpy(sqlca.sqlerrm, stmt);
		}
	}
	return(n_columns);
}

/*
** Process the INSERT part of a LOAD statement
*/
int   asql_load_data(struct element *e,int *err_at_col)
{
A4GL_assertion(1,"load data not implemented yet");
}

int load_err(int row,char *msg) {
	if (load_ok) {
		load_err_line=row;
		if (msg) {
			strcpy(load_err_msg,msg);
		}
	}
	load_ok=0;
}

#ifdef USE_REGISTRY_SQLHOSTS
LONG createkey_infx (void)
{
  LONG a;
  DWORD disp;
  a = RegCreateKeyEx (HKEY_LOCAL_MACHINE,
                      "Software\\Informix\\SQLHOSTS",
                      0,
                      "AclClass",
                      REG_OPTION_NON_VOLATILE,
                      KEY_ALL_ACCESS, NULL, &newkey_infx, &disp);
  return a;
}
#endif

int can_do_unload() {
return 1;
}




int
do_unload (struct element *e,long *raffected)
{
  int b;

  //int lineno;
  //char type;
  //char *stmt;
  //char *delim;
  //char *fname;
  register int pos;
  register char *cp;
  register int len;
  register int i;
  struct sqlda *udesc;
  struct sqlvar_struct *col;
  FILE *unlfile;
  char *fname;
  char delim = '|';
  char *buffer = NULL;
  int counter = 0, filerecs = 0, ret = 0, align;
  char fname2[1025];
  static int fnum = 0;
  int nblobs = 0, flen, rlen, outbsize = 0, blobn;
  int *bbufs[1024];
  char *outbuff, *iptr, *optr, str[100];
  long long filebytes = (long long) 0;
  short *indicators, *qualifiers;
  intrvl_t *ivp;
  EXEC SQL BEGIN DECLARE SECTION;
  char *slctstmt;
  /* loc_t *locator=0; */
  EXEC SQL END DECLARE SECTION;
static char *string=0;
static int string_len=0;


  *raffected=0;


  slctstmt = e->stmt;


if (e->delim) {
  	delim = e->delim[0];
} else {
	delim='|';
}

  fname = e->fname;
  if (EndianNess == -1)
    {
      EndianNess = DetermineEndianNess ();
    }

  EXEC SQL PREPARE usqlobj FROM:slctstmt;

  if (sqlca.sqlcode != 0)
    {
      return 0;
    }

  EXEC SQL DESCRIBE usqlobj INTO udesc;

  if (sqlca.sqlcode != 0)
    {
      return 0;
    }

  unlfile = fopen (fname, "w");

  if (unlfile == NULL)
    {
      local_set_sqlcode (-806);
      return 0;
    }


  if (no_buf)
    setvbuf (unlfile, (char *) NULL, _IONBF, 0);
  else if (bufsz)
    setvbuf (unlfile, (char *) NULL, _IOFBF, bufsz);


  /* Step 1: analyze udesc to determine type and memory requirements
   *         of each item in the select list.  rtypalign() returns a
   *         pointer to the next appropriate boundary (starting at
   *         pos) for the indicated data type.
   */
  pos = 0;

  for (col = udesc->sqlvar, i = 0; i < udesc->sqld; col++, i++)
    {
      long fld_len = col->sqllen;

      switch (col->sqltype)
	{
	case SQLSMFLOAT:
	  col->sqltype = CFLOATTYPE;
	  fld_len = col->sqllen = rtypmsize (col->sqltype, col->sqllen);
	  break;

	case SQLFLOAT:
	  col->sqltype = CDOUBLETYPE;
	  fld_len = col->sqllen = rtypmsize (col->sqltype, col->sqllen);
	  break;

	case SQLMONEY:
	case SQLDECIMAL:
	  col->sqltype = CDECIMALTYPE;
	  fld_len = col->sqllen = rtypmsize (col->sqltype, col->sqllen);
	  break;

	case SQLSERIAL:
	case SQLINT:
	  col->sqltype = CLONGTYPE;
	  fld_len = col->sqllen = rtypmsize (col->sqltype, col->sqllen);
	  break;

	case SQLSMINT:
	  col->sqltype = CSHORTTYPE;
	  fld_len = col->sqllen = rtypmsize (col->sqltype, col->sqllen);
	  break;

	case SQLVCHAR:
	case SQLCHAR:
	  col->sqltype = CFIXCHARTYPE;	/* get all bytes */
	  fld_len = col->sqllen = rtypmsize (col->sqltype, col->sqllen);
	  break;

	case SQLDATE:
	  col->sqltype = CFIXCHARTYPE;
	  col->sqllen=11; //dd-mm-yyyy
	  fld_len = col->sqllen = rtypmsize (col->sqltype, col->sqllen);
	  break;

	case SQLINTERVAL:
	  col->sqltype = CFIXCHARTYPE;
	  fld_len = col->sqllen = rtypmsize (col->sqltype, 25);
	  break;

	case SQLDTIME:
	  col->sqltype = CFIXCHARTYPE;
	  fld_len = col->sqllen = rtypmsize (col->sqltype, 25);
	  break;
/*
	case SQLBYTES:
	case SQLTEXT:
	  col->sqltype = CLOCATORTYPE;
	  fld_len = col->sqllen = sizeof (loc_t);
	  break;
*/

	default:
	  A4GL_assertion (1, "Unsupported data type\n");
	  return 0;
	}
      pos = (int) rtypalign (pos, col->sqltype) + fld_len;
    }

  buffer = (char *) malloc (pos);
  if (buffer == (char *) NULL)
    {
      // Out of memory...
      return 0;
    }

  indicators = (short *) malloc (udesc->sqld * sizeof (short));
  memset (indicators, 0, udesc->sqld * sizeof (short));
  qualifiers = (short *) malloc (udesc->sqld * sizeof (short));
  memset (qualifiers, 0, udesc->sqld * sizeof (short));

  /* Initialize buffer to Nulls */
  memset (buffer, 0, pos);

  /* Step 3: Set pointers in the allocated memory to receive each
   *         item in the select list.
   */
  pos = 0;
  cp = buffer;
  rlen = 0;
  for (col = udesc->sqlvar, i = 0; i < udesc->sqld; col++, i++)
    {
      switch (col->sqltype)
	{
	/*

	case CLOCATORTYPE:
	  locator = (loc_t *) malloc (sizeof (loc_t));
	  align = (int) rtypalign ((int) (cp - buffer), col->sqltype);
	  cp = buffer + align;
	  col->sqldata = (char *) locator;
	  cp += col->sqllen;
	  rlen += 4;		


          locator->loc_status = 0;
          locator->loc_type = SQLTEXT;
          locator->loc_xfercount = 0;

	  locator->loc_loctype = LOCMEMORY;
	  locator->loc_bufsize = -1;
	  locator->loc_buffer = (char *)0;
	  locator->loc_size=0;
	  locator->loc_indicator=0;
	  locator->loc_oflags=0;


	  if (nblobs > 1023)
	    {
	      fprintf (stderr, ">1023 blob columns in record\n");
	      exit (9);
	    }

	  nblobs++;
	  break; */

	case CDOUBLETYPE:
	  break;
	case CSHORTTYPE:
	  align = (int) rtypalign ((int) (cp - buffer), col->sqltype);
	  cp = buffer + align;
	  col->sqldata = cp;
	  cp += col->sqllen;
	  rlen += col->sqllen;
	  break;
	case CDTIMETYPE:
	  align = (int) rtypalign ((int) (cp - buffer), col->sqltype);
	  cp = buffer + align;
	  col->sqldata = cp;
	  ((dtime_t *) (col->sqldata))->dt_qual =
	    TU_ENCODE (TU_LEN (col->sqllen),
		       TU_START (col->sqllen), TU_END (col->sqllen));
	  /* Save the qualifier for later */
	  qualifiers[i] =  (((dtime_t *) (col->sqldata))->dt_qual);
	  col->sqllen = ((dtime_t *) (col->sqldata))->dt_qual;
	  cp += (flen = rtypmsize (col->sqltype, col->sqllen));
	  rlen += flen;
	  break;

	
	case CINVTYPE:
	  align = (int) rtypalign ((int) (cp - buffer), col->sqltype);
	  cp = buffer + align;
	  col->sqldata = cp;
	  ((intrvl_t *) (col->sqldata))->in_qual =
	    TU_IENCODE (TU_LEN (col->sqllen),
			TU_START (col->sqllen), TU_END (col->sqllen));
	  /* Save the qualifier for later */
	  qualifiers[i] =  (((intrvl_t *) (col->sqldata))->in_qual);
	  col->sqllen = ((intrvl_t *) (col->sqldata))->in_qual;
	  cp += (flen = rtypmsize (col->sqltype, col->sqllen));
	  rlen += flen;
	  break;
	default:
	  align = (int) rtypalign ((int) (cp - buffer), col->sqltype);
	  cp = buffer + align;
	  col->sqldata = cp;
	  cp += col->sqllen;
	  rlen += col->sqllen;
	  break;
	}
      col->sqlitype = CSHORTTYPE;
      col->sqlilen = sizeof (short);
      col->sqlidata = (char *) indicators;
      col->sqlind = indicators++;
    }
  pos = (long) cp - (long) buffer;


  /* EXEC SQL WHENEVER ERROR CONTINUE; */

  EXEC SQL DECLARE usqlcurs CURSOR FOR usqlobj;

  if (sqlca.sqlcode < 0)
    {
      return 0;
    }

  if (has_trans && !is_ansi) {
     $BEGIN WORK;
  }

  EXEC SQL OPEN usqlcurs;
  if (sqlca.sqlcode < 0)
    {
	return 0;
    }

  sqlca.sqlcode = 0;
  col = udesc->sqlvar;
  while (sqlca.sqlcode == 0)
    {
      bpos = 0;
      global_length = 0;
      /* Initialize buffer to Nulls */
      /* memset( buffer, 0, pos ); */

      for (col = udesc->sqlvar, i = 0; i < udesc->sqld; col++, i++)
	{
	  switch (col->sqltype)
	    {
	    case CDTIMETYPE:
	      /* Get the saved qualifier. */
	      ((dtime_t *) (col->sqldata))->dt_qual = qualifiers[i];
	      break;
	    case CINVTYPE:
	      /* Get the saved qualifier. */
	      ((intrvl_t *) (col->sqldata))->in_qual = qualifiers[i];
	      break;
	    default:
	      break;
	    }
	}
      EXEC SQL FETCH usqlcurs USING DESCRIPTOR udesc;

      if (sqlca.sqlcode < 0)
	{
	  return 0;
	}

      if (sqlca.sqlcode == 100)
	{
	  break;
	}

      for (col = udesc->sqlvar, i = 0; i < udesc->sqld; col++, i++)
	{
	      long templ, tmplp1, tmplp2;
	      short temps;
	      float tempf;
	      double tempd;



	  if (*col->sqlind == -1) 
	    {
		fprintf(unlfile,"|");
		continue;
	    }



	      switch (col->sqltype)
		{
		case CINTTYPE:
		case CLONGTYPE:
		  fprintf (unlfile,"%ld", *(long *) (col->sqldata));
		  break;
		case CSHORTTYPE:
		  fprintf (unlfile,"%d", *(short *) (col->sqldata));
		  break;


		case CFIXCHARTYPE:
			{
			int alen;
			int flen;
			if (string_len<col->sqllen*3+1) {
				string=realloc(string, col->sqllen*3+1);
				string_len=col->sqllen*3+1;
			}
                	alen = strip( (char *)col->sqldata, col->sqllen );
                	flen = charcpy( (unsigned char *)string, (unsigned char *)col->sqldata, alen );
			if (strlen(string)==0) {
		  		fprintf (unlfile," ");
			} else {
		  		fprintf (unlfile,"%s", string);
			}
			}
		  break;

		case CFLOATTYPE:
		  fprintf (unlfile,"%f", *(float *) (col->sqldata));
		  break;

		case CDECIMALTYPE:
		case CMONEYTYPE:
		  {
		    dec_t *dec = (dec_t *) (col->sqldata);
		     char buff[33];
		    dectoasc (dec, buff, 32, -1);
		    buff[32]=0;
		    A4GL_trim (buff);
		    fprintf (unlfile,"%s", buff);
		    break;
		  }
		case CDOUBLETYPE:
		  fprintf (unlfile,"%lf", *(double *) (col->sqldata));
		  break;

		case CDTIMETYPE:
		  {
		    char buff[33];
		    dtime_t *dtp = (dtime_t *) (col->sqldata);

		    if (dttoasc (dtp, buff))
		      {
		    buff[32]=0;
			A4GL_trim (buff);
			fprintf (unlfile,"%s", buff);
		      }
		    break;
		  }
		

/*
		case CINVTYPE:
		  {
		    char buff[33];
		    intrvl_t *itvl = (intrvl_t *) (col->sqldata);
		    if (intoasc (itvl, buff))
		      {
		    	buff[32]=0;
			A4GL_trim (buff);
			fprintf (unlfile,"%s", buff);

		      }
			break;
		  }
		case CLOCATORTYPE:
			{
			loc_t *blob;
			blob=(loc_t *) (col->sqldata);
                	if (blob->loc_buffer != NIL(char *))
                	{
                        if (blob->loc_type == SQLTEXT)
                                outbyte(unlfile,blob->loc_buffer, blob->loc_size );
                        else
                                outbyte(unlfile,blob->loc_buffer, blob->loc_size);
                	}
			}
			break;
*/

		default :
			{
			fprintf(unlfile,"<<%d>>",col->sqltype);
			}
		} // End of switch

		fprintf(unlfile,"|");

	} // End for (columns)
	fprintf(unlfile,"\n");
	  (*raffected)++;
    }				/* end fetch loop */

  fclose (unlfile);

  if (sqlca.sqlcode && sqlca.sqlcode != SQLNOTFOUND)
    {
return 0;
    }

  free (buffer);
      for (col = udesc->sqlvar, i = 0; i < udesc->sqld; col++, i++)
	{
	/*
	  if (col->sqltype==CLOCATORTYPE) {
			loc_t *blob;
			blob=col->sqldata;
			if (blob->loc_buffer) free(blob->loc_buffer);
			free(col->sqldata);
		}
	*/
	}
  if (sqlca.sqlcode && sqlca.sqlcode != SQLNOTFOUND)
    {
	return 0;
    }
  EXEC SQL CLOSE usqlcurs;
  return 1;
}


#ifdef REDUNDANT

int writeit( loc_t *loc, char *buf, int nbytes )
{
    unsigned long toread;

printf("writeit...\n");
    if ((bpos + nbytes) > bbsize) {
        bbsize += (2 * (nbytes < 1024 ? 1024 : nbytes));
        blobbuff = (char *)realloc( blobbuff, bbsize );
    }
    if (loc->loc_size != -1)
        toread = min( nbytes, (loc->loc_size - loc->loc_xfercount) );
    else
        toread = nbytes;
    memcpy( &blobbuff[bpos], buf, toread );
    bpos += toread;

    loc->loc_xfercount += toread;
    global_length += toread;

    return toread;
}
#endif


#ifdef REDUNDANT
int openit( loc_t *loc, int flags, int bsize )
{
    if ((flags & LOC_WONLY) && loc->loc_size < -1) {
        fprintf( stderr, "Blob fetched with length: %d.\n", loc->loc_size );
        return -1;
    }
    loc->loc_status = 0;
    loc->loc_xfercount = 0L;
    global_length = 0 ;

    return 0;
}
#endif



int DetermineEndianNess()
{
    int testint = 0x04030201, ii, result = 0, mult=1000;
    char *p = (char *)&testint;

    for ( ii=0; ii < 4; ii++) {
        result += mult * p[ii];
        mult /= 10;
    }

    return result;
}


#ifdef REDUNDANT
int closeit( loc_t *loc )
{
    unsigned long count;

    loc->loc_status = 0;
    if (loc->loc_oflags & LOC_WONLY) {
        /* Fetching, cleanup. */
        loc->loc_indicator = 0;
        loc->loc_size = loc->loc_xfercount;
    }

    return 0;
}
#endif



int charcpy( unsigned char *target, unsigned char *source, long len )
{
    int rlen = 0;
char ldelim;
ldelim=get_delim();

    while (len) {
        if (*source == ldelim) {
            *target++ = '\\';
            *target++ = ldelim;
        } else if ((*source < ' ' || *source > '~') && *source!=0xa3 && *source!='\t') {
            /* Non-printable, convert to hex. */
            target += sprintf( (char *)target, "\\%2.2x", *source );
        } else {
		if (*source=='\\') {
            		*target++ = '\\';
            		*target = *source;
            		target++;
		} else {
            		*target = *source;
            		target++;
		}
        }
        source++;
        len--;
        rlen++;
    }
    /*    *target++ = *delim; */
    *target = (char)0;
    rlen++;

    return rlen;
}

int do_mode_1() {
 if (get_exec_mode_c () == 1) return 1;
 return 0;
}

int strip( char *str, int len )
{
    char *p;
    int alen = len;

    for (p = (str + len - 1); p > str; p--, alen--) {
        if (*p == ' ' || *p == (char)0)
            *p = (char)0;
        else
            break;
    }
    return alen;
}


static void     outbyte(FILE *unlfile, char *buffer, long len)
{
        static char *spc_orig=0;
        char *spc=0;
        static int slen=0;
        char            c;
        char           *dst;
        char           *src;
        char           *end;
        if (len>slen) {
                spc_orig = (char *)realloc(spc_orig, 2 * len + 1);
                slen=len;
        }
	spc=spc_orig;
        src = buffer;
        dst = spc;
        end = buffer + len;
        while (src < end)
        {
                c = *src++;
                *dst++ = chexdigit[(c >> 4)& 0xF];
                *dst++ = chexdigit[c & 0xF];
        }
        *dst = '\0';
        fprintf(unlfile,"%s",spc) ;
}


endcode

function init_sql()
define lv_server char(60)
define lv_uname,lv_passwd char(50)
define lv_hasacl integer
let lv_server=fgl_getenv("INFORMIXSERVER")

if lv_server is null or lv_server matches " " then
	return
end if

code
if (inited) {
	// don't reconnect if we've already connected
	lv_hasacl=0;
} else {
	inited++;
	lv_hasacl=A4GL_sqlid_from_aclfile("default",lv_uname,lv_passwd,NULL);
}
endcode

if lv_hasacl then
	let lv_server="@",lv_server
	connect to lv_server user lv_uname using lv_passwd
end if

end function



code



int
printField (FILE * outputFile, int idx, char *descName)
{
  char buffer[40000];
  char fmt[255];
  short smint_var;
  int int_var;
  long date_var;
  char *char_var;
  double float_var;
  float smfloat_var;


  dec_t *decimal_var;
  dec_t *money_var;
  dtime_t *dtime_var;
char buff[255];


  struct sqlvar_struct *psqlvar = &desc_output->sqlvar[idx - 1];

  if (risnull (psqlvar->sqltype, psqlvar->sqldata))
    {
      strcpy (buffer, "");
    }
  else
    {
      switch (psqlvar->sqltype & 0xf)
	{

	case SQLCHAR:
	case SQLVCHAR:
	  sprintf (buffer, "%s", psqlvar->sqldata);
	  A4GL_trim (buffer);

	  break;


	case SQLSMINT:
	  smint_var = *(short *) psqlvar->sqldata;

	  if (display_mode == DISPLAY_DOWN || display_mode == DISPLAY_UNLOAD)
	    {
	      sprintf (buffer, "%d", smint_var);
	    }
	  else
	    {
	      sprintf (buffer, "%*d", columnWidths[idx - 1], smint_var);
	    }
	  break;

	case 6:
	case SQLINT:
	  int_var = *(int *) psqlvar->sqldata;

	  if (display_mode == DISPLAY_DOWN || display_mode == DISPLAY_UNLOAD)
	    {
	      sprintf (buffer, "%ld", int_var);
	    }
	  else
	    {
	      sprintf (buffer, "%*ld", columnWidths[idx - 1], int_var);
	    }
	  break;


	case SQLDATE:
	  if (sizeof (int) == 4)
	    {
	      date_var = *(int *) psqlvar->sqldata;
	    }
	  else
	    {
	      date_var = *(long *) psqlvar->sqldata;
	    }

	  char_var = (char *) acl_malloc2 (sizeof (char) * 20);
	  A4GL_dtos (&date_var, char_var, 19);
	  A4GL_trim (char_var);
	  sprintf (buffer, "%s", char_var);
	  free (char_var);
	  break;

	   case SQLFLOAT:
		float_var=*(double *)psqlvar->sqldata;
          if (display_mode == DISPLAY_DOWN || display_mode == DISPLAY_UNLOAD)
            {
              sprintf (buffer, "%lf", float_var);
              if (display_mode == DISPLAY_UNLOAD)
                trim_trailing_0 (buffer);
            }
          else
            {
              sprintf (buffer, "%*lf", columnWidths[idx - 1], float_var);
            }
          break;



        case SQLSMFLOAT:
		smfloat_var=*(float *)psqlvar->sqldata;
          if (display_mode == DISPLAY_DOWN || display_mode == DISPLAY_UNLOAD)
            {
              sprintf (buffer, "%f", smfloat_var);
              if (display_mode == DISPLAY_UNLOAD)
                trim_trailing_0 (buffer);
            }
          else
            {
              sprintf (buffer, "%*f", columnWidths[idx - 1], smfloat_var);
            }
          break;

        case SQLDECIMAL:
		
	  decimal_var =psqlvar->sqldata;
          if (dectoasc (decimal_var, buff, 32, -1))
            {
              A4GL_debug ("BAD DECIMAL");
              return 1;
            }
          buff[32] = 0;
          A4GL_trim (buff);
          if (display_mode == DISPLAY_DOWN || display_mode == DISPLAY_UNLOAD)
            {
              sprintf (buffer, "%s", buff);
              if (display_mode == DISPLAY_UNLOAD)
                trim_trailing_0 (buffer);
            }
          else
            {
              sprintf (buffer, "%*s", columnWidths[idx - 1], buff);
            }
          break;


        case SQLMONEY:
	  money_var =psqlvar->sqldata;
          if (dectoasc (money_var, buff, 32, -1))
            {
        /** @todo : Store the error somewhere */
              A4GL_debug ("Bad money");
              return 1;
            }
          buff[32] = 0;
          sprintf (buffer, "%s", buff);
          if (display_mode == DISPLAY_UNLOAD)
            trim_trailing_0 (buffer);
          //free (fgl_money);
          break;

        case SQLDTIME:
		
		dtime_var =psqlvar->sqldata;
          if (dttoasc (dtime_var, buff))
            {
              A4GL_debug ("Bad dtime");
              return 1;
            }
          sprintf (buffer, "%s", buff);
          break;


	default:
	  sprintf (buffer, "Unhandled datatype : %d", psqlvar->sqltype);
	}
    }



/*
        printf("%-20s: (%d, %2d, %s) (%d, %2d, %ld) %d\n",
                 psqlvar->sqlname,
                 psqlvar->sqltype,
                 psqlvar->sqllen,
                 psqlvar->sqldata,
                 psqlvar->sqlitype,
                 psqlvar->sqlilen,
                 psqlvar->sqlidata,
                 risnull(psqlvar->sqltype, psqlvar->sqldata));
*/

  if (display_mode == DISPLAY_DOWN)
    {
      sprintf (fmt, "%%-%d.%ds %%s\n", colnamesize + 1, colnamesize + 1);
      if (get_exec_mode_c () == EXEC_MODE_INTERACTIVE)
	{
	  fprintf (outputFile, fmt, columnNames[idx - 1], buffer);
	}
      else
	{
	  fprintf (exec_out, fmt, columnNames[idx - 1], buffer);
	}
      outlines++;
    }

  if (display_mode == DISPLAY_ACROSS)
    {
      if (get_exec_mode_c () == EXEC_MODE_INTERACTIVE)
	{

	  A4GL_debug ("EXECO '%s' '%20s' '%-20s'", buffer, buffer, buffer);
	  fprintf (outputFile, "%-*s", columnWidths[idx - 1], buffer);
	}
      else
	fprintf (exec_out, "%-*s", columnWidths[idx - 1], buffer);
    }

  if (display_mode == DISPLAY_UNLOAD)
    {
      fprintf (f_unloadFile, "%s", escape_delim (buffer));
      fprintf (f_unloadFile, "%s", delim);
    }



  return 0;


}

static int
field_widths ()
{
  EXEC SQL BEGIN DECLARE SECTION;
  int index;
  int datatype;
  int size;
  char columnName[64];
  EXEC SQL END DECLARE SECTION;
  int totsize = 0;
struct sqlvar_struct *psqlvar ;


if (columnNames)
    {
      int a;
      for (a = 0; columnNames[a]; a++)
	free (columnNames[a]);
      free (columnNames);
      columnNames = 0;
    }

  if (columnWidths)
    {
      free (columnWidths);
      columnWidths = 0;
    }

  if (columnAlign)
    {				// CA1
      free (columnAlign);	// CA1
      columnAlign = 0;		//CA1
    }				// CA1

  colnamesize = -1;


  columnNames = acl_malloc2 (sizeof (char *) * (numberOfColumns + 1));
  columnWidths = acl_malloc2 (sizeof (int) * (numberOfColumns + 1));
  columnAlign = acl_malloc2 (sizeof (int) * (numberOfColumns + 1));


  for (index = 1; index <= numberOfColumns; index++)
    {


    /* EXEC SQL GET DESCRIPTOR 'descExec' VALUE:index:size = LENGTH,: datatype = TYPE,:columnName = NAME; */


	psqlvar= &desc_output->sqlvar[index-1];
	strcpy(columnName,psqlvar->sqlname);
	size=psqlvar->sqllen;
	datatype=psqlvar->sqltype;



      cp_sqlca ();
      A4GL_trim (columnName);
      columnNames[index - 1] = strdup (columnName);

      size = get_size (datatype, size);
      if (size < strlen (columnNames[index - 1]))
	size = strlen (columnNames[index - 1]);


      if (strlen (columnName) > size)
	{
	  size = strlen (columnName);
	}
      if (strlen (columnName) > colnamesize || colnamesize <= 0)
	{
	  colnamesize = strlen (columnName);
	}
      columnWidths[index - 1] = size;



      // Is the column header right aligned
      // when displayed across the page ?
      if (datatype == SQLSMINT || datatype == SQLINT || datatype == SQLFLOAT
	  || datatype == SQLSMFLOAT || datatype == SQLDECIMAL
	  || datatype == SQLSERIAL)
	{			// CA 1
	  columnAlign[index - 1] = 1;	// CA 1
	}
      else
	{			// CA 1
	  columnAlign[index - 1] = 0;	// CA 1
	}			// CA 1
      totsize += size + 1;
    }

  columnNames[numberOfColumns] = 0;
  return totsize;

}

int
execute_select_prepare (int *err_at_col,int type , int *hasrows)
{

  open_display_file_c ();
*err_at_col=1;
*hasrows=1








  cp_sqlca ();


  if (sqlca.sqlcode < 0)
    return 0;

  EXEC SQL describe stExec into desc_output;
  cp_sqlca ();
  if (sqlca.sqlcode < 0)
    return 0;


  buff_sqld=sqdbuf_alloc(&_SQ1,desc_output,0);

  numberOfColumns=desc_output->sqld;

  //EXEC SQL get descriptor 'descExec':numberOfColumns = COUNT;


  cp_sqlca ();
  if (sqlca.sqlcode < 0)
    return 0;
  A4GL_debug ("numberOfColumns : %d\n", numberOfColumns);

  EXEC SQL declare crExec CURSOR FOR stExec;
  cp_sqlca ();
  if (sqlca.sqlcode < 0)
    return 0;

  EXEC SQL open crExec;
  cp_sqlca ();
  if (sqlca.sqlcode < 0)
    return 0;


  if (display_mode != DISPLAY_UNLOAD)
    {
      if (get_exec_mode_c () == EXEC_MODE_INTERACTIVE || get_exec_mode_c () == EXEC_MODE_OUTPUT)
	{
	  if (field_widths () > A4GL_get_curr_width ())
	    {
	      display_mode = DISPLAY_DOWN;
	    }
	  else
	    {
	      display_mode = DISPLAY_ACROSS;
	    }
	}
      else
	{

	  if (stdin_screen_width == -1)
	    stdin_screen_width = set_stdin_width ();
	  if (field_widths () > stdin_screen_width)
	    {
	      display_mode = DISPLAY_DOWN;
	    }
	  else
	    {
	      display_mode = DISPLAY_ACROSS;
	    }
	}
    }
  return 1;
}

execute_select_free ()
{
  EXEC SQL CLOSE crExec;
  cp_sqlca ();
  EXEC SQL free stExec;
  cp_sqlca ();
  EXEC SQL free crExec;
  cp_sqlca ();

  if (ec_check_and_report_error ())
    {
      A4GL_debug ("EXEC ERR3");
      return 0;
    }
  return 1;
}



/******************************************************************************/
int
execute_sql_fetch (int *raffected,int *err_at_col)
{
  int a;
*err_at_col=1;


  EXEC SQL FETCH crExec using descriptor desc_output;
  cp_sqlca ();

  if (sqlca.sqlcode < 0)
    {
      A4GL_push_char ("Fetch error...");
      A4GL_display_error (0, 0);
      sleep (1);		// Fetch error
      return sqlca.sqlcode;
    }

  if (sqlca.sqlcode == 100)
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
		{		// CA 1
		  fprintf (file_out_result, "%*.*s", columnWidths[a], columnWidths[a], columnNames[a]);	// CA 1
		}
	      else
		{		// CA 1
		  fprintf (file_out_result, "%-*.*s", columnWidths[a], columnWidths[a], columnNames[a]);	// CA 1
		}		// CA 1
	    }
	  else
	    {
	      A4GL_assertion (exec_out == 0, "No output file (6)");
	      if (a)
		fprintf (exec_out, " ");
	      if (columnAlign[a])
		{		// CA 1
		  fprintf (exec_out, "%*.*s", columnWidths[a], columnWidths[a], columnNames[a]);	// CA 1
		}
	      else
		{		// CA 1
		  fprintf (exec_out, "%-*.*s", columnWidths[a], columnWidths[a], columnNames[a]);	// CA 1
		}		// CA 1
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

  return sqlca.sqlcode;
}






endcode
