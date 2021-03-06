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
code
EXEC SQL include sqltypes;
EXEC SQL BEGIN DECLARE SECTION;
int numberOfColumns=0;
EXEC SQL END DECLARE SECTION;
extern int fetchFirst;
static int get_size(int dtype,int size) ;

extern char *delim;
#define DISPLAY_ACROSS 1
#define DISPLAY_DOWN   2
#define DISPLAY_UNLOAD 3

int stdin_screen_width=-1;
int colnamesize=-1;

extern char **columnNames;
extern int *columnWidths;
extern int *columnAlign; // CA1

#define EXEC_MODE_INTERACTIVE   0
#define EXEC_MODE_FILE          1
#define EXEC_MODE_OUTPUT        2
FILE *unloadFile=0;
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
call prompt_pick(lv_prompt,"") returning lv_tabname
if lv_tabname is not null then
	select * from systables where tabname=lv_tabname
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

      LET lv_buff = lv_colname,get_type(l_coltype, l_collength)
	# ADD IT TO THE LIST....


   END FOREACH


return 1
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
#clear screen
#call display_banner()
#
# In order to find out what connections are available
# Have a look in the sqlhosts file
#
code
{
char fname[1024];
FILE *f_in;
char *ptr;
A4GL_trim(lv_informixdir);
sprintf(fname,"%s/etc/sqlhosts",lv_informixdir);
f_in=fopen(fname,"r");
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
                        lv_cnt++;
                }
        }
}
fclose(f_in);
}
endcode
call set_pick_cnt(lv_cnt-1)
if lv_cnt=1 then
        error "Either the SQLHOSTS file cannot be read - or it is empty"
end if

let lv_server=prompt_pick("SELECT DATABASE SERVER >>","")

if lv_server is null or lv_server matches " " then
        return
end if

prompt "USER NAME >> " for lv_username

if lv_username is null or lv_username=" " then
else
        prompt "PASSWORD >> " for lv_passwd
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
putenv(buff);
}
endcode
call set_username(lv_username,lv_passwd)
call select_db()
end function




code


void cp_sqlca() {
a4gl_sqlca.sqlcode=sqlca.sqlcode;
}


int
printField (int idx, char *descName,int row)
{
  EXEC SQL BEGIN DECLARE SECTION;
  int dataType;
  int index = idx;
  short indicator;
  char buffer[32000]="";

  char *descriptorName = descName;
  int length;



  char *char_var;
  short smint_var;
  long int_var;
  double float_var;
  float smfloat_var;
  dec_t decimal_var;
  long date_var;
  dec_t money_var;
  dtime_t dtime_var;
  intrvl_t interval_var;
  EXEC SQL END DECLARE SECTION;
  char buff[255];
char fmt[255];
  int rc = 0;


  EXEC SQL GET DESCRIPTOR 'descExec' VALUE:index:indicator =
    INDICATOR,:dataType = TYPE;
cp_sqlca();

//printf("indicator=%d type=%d\n",indicator,dataType);
if (indicator!=-1) {
  switch (dataType&0xf)
    {
    case SQLCHAR:
    case SQLVCHAR:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index:length =
        LENGTH;cp_sqlca();
      if (isSqlError ())
        {
          rc = 1;
          break;
        }
      char_var = (char *)acl_malloc2 (length + 1);
      EXEC SQL GET DESCRIPTOR:descriptorName VALUE:index:char_var = DATA;cp_sqlca();
      A4GL_trim (char_var);
      sprintf (buffer, "%s", char_var);
      free (char_var);
      break;
    case SQLSMINT:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:smint_var =
        DATA;cp_sqlca();
      if (isSqlError ())
        {
          rc = 1;
          break;
        }
      		sprintf (buffer, "%*d", columnWidths[idx-1],smint_var);
      break;

    case 6:
    case SQLINT:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:int_var =
        DATA;cp_sqlca();
      if (isSqlError ())
        {
          rc = 1;
          break;
        }

      		sprintf (buffer, "%*ld", columnWidths[idx-1],int_var);
      break;
    case SQLFLOAT:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:float_var =
        DATA;cp_sqlca();
      if (isSqlError ())
        {
          rc = 1;
          break;
        }
                sprintf (buffer, "%*lf", columnWidths[idx-1],float_var);
      break;
    case SQLSMFLOAT:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:smfloat_var =
        DATA;cp_sqlca();
      if (isSqlError ())
        {
          rc = 1;
          break;
        }
                sprintf (buffer, "%*f", columnWidths[idx-1],smfloat_var);
      break;
    case SQLDECIMAL:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:decimal_var =
        DATA;cp_sqlca();
      if (isSqlError ())
        {
          rc = 1;
          break;
        }

      if (dectoasc (&decimal_var, buff, 32, -1))
        {
                A4GL_debug("BAD DECIMAL");
        /** @todo : Store the error somewhere */
          return 1;
        }
        buff[32]=0;
	A4GL_trim(buff);
                sprintf (buffer, "%*s", columnWidths[idx-1],buff);
      //free (fgl_decimal);
      break;
    case SQLDATE:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:date_var =
        DATA;cp_sqlca();
      if (isSqlError ())
        {
          rc = 1;
          break;
        }
      /** @todo : Print as date field */
      char_var = (char *)acl_malloc2 (sizeof (char) * 10);
      A4GL_dtos (&date_var, char_var, 10);
      sprintf (buffer, "%s", char_var);
      free (char_var);
      break;
    case SQLMONEY:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:money_var =
        DATA;cp_sqlca();
      if (isSqlError ())
        {
          rc = 1;
          break;
        }
      if (dectoasc (&money_var, buff,32, -1))
        {
        /** @todo : Store the error somewhere */
        A4GL_debug("Bad money");
          return 1;
        }
        buff[32]=0;
      sprintf (buffer, "%s", buff);
      break;

    case SQLDTIME:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:dtime_var =
        DATA;cp_sqlca();
      if (isSqlError ())
        {
          rc = 1;
          break;
        }
      if (dttoasc (&dtime_var, buff))
        {
        /** @todo : Store the error somewhere */
        A4GL_debug("Bad dtime");
          return 1;
        }
      sprintf (buffer, "%s", buff);
      break;
    case SQLINTERVAL:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:interval_var =
        DATA;cp_sqlca();
      if (isSqlError ())
        {
          rc = 1;
          break;
        }
      if (intoasc (&interval_var, buff))
        {
        /** @todo : Store the error somewhere */
        A4GL_debug("Bad itime");
          return 1;
        }
      sprintf (buffer, "%s", buff);
      break;
    case SQLBYTES:
      break;
    case SQLTEXT:
      break;
    default:
        A4GL_debug("INVALID DATATYPE %d %x @ %d+++",dataType,dataType,idx);
      A4GL_exitwith ("Invalid data type\n");
    }
	if (strlen(buffer)==0) strcpy(buffer," ");
} else {
        strcpy(buffer,"");
}



A4GL_push_int(idx);
A4GL_push_char(buffer);
A4GL_push_int(row);
aclfgl_add_to_list(3);

	//add_to_list(idx,columnWidths[idx-1],buffer,row);

/*
             A4GL_debug("EXECO '%s' '%20s' '%-20s'",buffer,buffer,buffer);
		printf("add to list %d: ",idx);
             printf("%-*s",columnWidths[idx-1],buffer);
*/


  return 0;
}


int prepare_query_1(char *s,char type) {
EXEC SQL BEGIN DECLARE SECTION;
char *p;
EXEC SQL END DECLARE SECTION;
int qry_type;

fetchFirst=1;
printf("prepare_query_1\n");
if (type>='1'&&type<='9') return 255;

p=s;


                        EXEC SQL PREPARE stExec from :p;cp_sqlca();
                        if (ec_check_and_report_error()) { return -1; }

                        EXEC SQL DEALLOCATE DESCRIPTOR "d1";cp_sqlca();

                        EXEC SQL ALLOCATE DESCRIPTOR "d1";cp_sqlca();
                        if (ec_check_and_report_error()) { return -1; }
                        EXEC SQL DESCRIBE stExec USING SQL DESCRIPTOR "d1"; cp_sqlca();
                        qry_type=sqlca.sqlcode;
			return qry_type;
}



int execute_query_1(int *raffected) {
		*raffected=0;
                         EXEC SQL EXECUTE stExec; cp_sqlca();
                         if (ec_check_and_report_error()) { return 0; }
                         *raffected=sqlca.sqlerrd[0];
                         EXEC SQL FREE stExec; cp_sqlca();
                         if (ec_check_and_report_error()) { return 0; }
	return 1;
}



execute_select_free() {
                          EXEC SQL CLOSE crExec; cp_sqlca();
                          EXEC SQL free stExec; cp_sqlca();
                          EXEC SQL free crExec; cp_sqlca();

                          if (ec_check_and_report_error()) { A4GL_debug("EXEC ERR3"); return 0; }
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

if (columnAlign) { 
	free(columnAlign); 
	columnAlign=0; 
} 

colnamesize=-1;


columnNames=acl_malloc2(sizeof(char*) * (numberOfColumns+1));
columnWidths=acl_malloc2(sizeof(int) * (numberOfColumns+1));
columnAlign=acl_malloc2(sizeof(int) * (numberOfColumns+1));


for(index=1;index<=numberOfColumns;index++) {
        EXEC SQL GET DESCRIPTOR 'descExec' VALUE: index :size=LENGTH , :datatype=TYPE,
                :columnName=NAME
        ; cp_sqlca();
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



	// Is the column header right aligned
	// when displayed across the page ?
	if (datatype==SQLSMINT || datatype==SQLINT || datatype== SQLFLOAT|| datatype== SQLSMFLOAT|| datatype== SQLDECIMAL|| datatype== SQLSERIAL) { // CA 1
		columnAlign[index-1]=1; // CA 1
	} else { // CA 1
		columnAlign[index-1]=0; // CA 1
	} // CA 1
        totsize+=size+1;
}

columnNames[numberOfColumns]=0;
return totsize;

}


int execute_select_prepare() {
printf("execute_select_prepare\n");
fetchFirst=1;
EXEC SQL whenever error continue;
EXEC SQL deallocate descriptor 'descExec'; cp_sqlca();

EXEC SQL allocate descriptor 'descExec' ; cp_sqlca();
        if (sqlca.sqlcode<0) return 0;

EXEC SQL describe stExec USING SQL DESCRIPTOR 'descExec'; cp_sqlca();
printf("describe : %d\n",sqlca.sqlcode);
        if (sqlca.sqlcode<0) return 0;

EXEC SQL get descriptor 'descExec' :numberOfColumns=COUNT; cp_sqlca();
        if (sqlca.sqlcode<0) return 0;
        printf("numberOfColumns : %d\n",numberOfColumns);

EXEC SQL declare crExec CURSOR FOR stExec; cp_sqlca();
        if (sqlca.sqlcode<0) return 0;
printf("Declare : %d\n",sqlca.sqlcode);

EXEC SQL open crExec ; cp_sqlca();
printf("Open : %d\n",sqlca.sqlcode);
        if (sqlca.sqlcode<0) return 0;
field_widths ();


return 1;
}

/******************************************************************************/
int execute_sql_fetch(int *raffected) {
int a;

//printf("execute_sql_FETCH\n");

        EXEC SQL FETCH crExec USING SQL DESCRIPTOR 'descExec'; cp_sqlca();

        if (sqlca.sqlcode<0) {
		printf("FETCH ERR : %d\n",sqlca.sqlcode);
                A4GL_push_char("Fetch error...");
                A4GL_display_error(0,0);
                sleep(1);
                return sqlca.sqlcode;
        }

        if (sqlca.sqlcode==100) {
                return 100;
        }
        (*raffected)++;


	if ((*raffected)%100 == 0) {
		A4GL_gui_run_til_no_more();
	}

	if ( fetchFirst==1) {
		
		printf("FETCH FIRST *****************************************************************************************\n");
		set_execute_list(numberOfColumns);
                for (a=0;a<numberOfColumns;a++) {
			A4GL_push_char(columnNames[a]);
			A4GL_push_int(a);
			aclfgl_setup_header(2);

		// Set up headers...
				//if (columnAlign[a]) { 
                                	//printf("%*.*s",columnWidths[a],columnWidths[a],columnNames[a]);  
				//} else { 
                                	//printf("%-*.*s",columnWidths[a],columnWidths[a],columnNames[a]); 
				//} 
                }
                fetchFirst=0;
        }

        for (a=1;a<=numberOfColumns;a++) {
		// Add values...
                if (printField(a,"descExec",*raffected)==1) {
                        A4GL_debug("Break Early %d of %d because I can't print it",a,numberOfColumns);
                        break;
                }

        }


        return sqlca.sqlcode;
}




/******************************************************************************/
static int get_size(int dtype,int size) {
        switch(dtype ) {
                case SQLCHAR:   return size;
                case SQLSMINT:  return  6;
                case SQLINT:    return  11;
                case SQLFLOAT:  return  11;
                case SQLSMFLOAT:        return  11;
                case SQLDECIMAL:        return  16;
                case SQLSERIAL:         return  10;
                case SQLDATE:   return  12;
                case SQLMONEY:  return  17;
                case SQLDTIME:  return  17;
                case SQLBYTES:  return  20;
                case SQLTEXT:   return  20;
                case SQLVCHAR:  return size;
                case SQLINTERVAL:       return 20;
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
define ndbs integer
define a integer
let lv_curr_db=get_db();

code
{
#define MAXDBS 100
#define FASIZ (MAXDBS * 19)
char *dbsname[MAXDBS+1];
char            dbsarea[FASIZ];

 sqlca.sqlcode = sqgetdbs(&ndbs, dbsname, MAXDBS, dbsarea, FASIZ);

endcode

if sqlca.sqlcode!=0 then
        call check_and_report_error()
        return
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
let lv_newname=prompt_pick("SELECT DATABASE >>","")

#message "lv_newname=",lv_newname clipped

if lv_newname is null then
        let lv_newname=lv_curr_db
end if

if lv_newname is not null and lv_newname not matches " " then
        whenever error continue

	#message "Opening db"
        close database
        database lv_newname
	whenever error stop

        if sqlca.sqlcode=0 then
                call set_curr_db(lv_newname)
                #call display_banner()
		call sbar("Database Opened")
        else
                call check_and_report_error()
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
#define MAXDBS 100
#define FASIZ (MAXDBS * 19)
char *dbsname[MAXDBS+1];
char            dbsarea[FASIZ];

 sqlca.sqlcode = sqgetdbs(&ndbs, dbsname, MAXDBS, dbsarea, FASIZ);

endcode

if sqlca.sqlcode!=0 then
        call check_and_report_error()
        return
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

        menu "CONFIRM >>"
                command "YES" "Really Drop the database"

        whenever error continue
                        let lv_sql="drop database ",lv_newname
                        prepare p_drop from lv_sql
                        execute p_drop
	whenever error stop

                        if sqlca.sqlcode=0 then
                                call set_curr_db("")
                                #call display_banner()
                                call sbar("Database dropped...")
                        else
                                call check_and_report_error()
                        end if
                        exit menu
                command "NO" "Don't drop it"
                        exit menu
        end menu
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
 
# SETUP HEADERS
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
		select distinct colauth[1] into lv_tabauth from syscolauth where tabid=lv_tabid
		if lv_tabauth[1]="S" or lv_tabauth[1]="s" then
			let lv_outline[14,32]="Some"
		end if
	
		select distinct colauth[2] into lv_tabauth from syscolauth where tabid=lv_tabid
		if lv_tabauth[1]="U" or lv_tabauth[1]="u" then
			let lv_outline[33,51]="Some"
		end if
	end if
	# ADD IT TO THE LIST
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
	# Add it to the list
	let lv_outline="Table Name          ",lv_rec.tabname
	let lv_outline="Owner               ",lv_rec.owner 
	let lv_outline="Row Size            ",lv_rec.rowsize 
	let lv_outline="Number Of Rows      ",lv_nrows," (Last Update Statistics:",lv_rec.nrows using "<<<<<<",")"  
	let lv_outline="Number Of Columns   ",lv_rec.ncols  
	let lv_outline="Date Created        ",lv_rec.created
else
	display "BAD...."
	sleep 1
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

call prompt_pick("INFO FOR TRIGGER >>","") returning lv_trigname


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


# add lv_str to the list

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
# add lv_str to the list
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

                let lv_txt="INFO - ",lv_tabname
                menu lv_txt
			command "Columns"
				CALL open_display_file()
                		if load_info_columns(lv_tabname) then
					call do_paginate()
				end if

			command "Indexes"
				CALL open_display_file()
                		if  load_info_indexes(lv_tabname) then
					call do_paginate()
				end if

			command "Privileges"
				CALL open_display_file()
				if  load_info_priv(lv_tabname) then
					call do_paginate()
				end if

			command "References"
				CALL open_display_file()
				if  load_info_ref(lv_tabname) then
					call do_paginate()
				end if

			command "Status"
				call open_display_file()
				if load_info_status(lv_tabname) then
					call do_paginate()
				end if

			command "cOnstraints"
				CALL open_display_file()
				if  load_info_constraints(lv_tabname)  then
					call do_paginate()
				end if

			command key "G" "triGgers"
				call open_display_file()
				if load_info_triggers(lv_tabname) then
					call do_paginate()
				end if

			command "Table"
				let lv_cont=1
				exit menu

			command "Fragments"
				call open_display_file()
				if load_info_fragments(lv_tabname) then
					call do_paginate()
				end if

			command "Exit"
				let lv_cont=0
				exit menu

		end menu
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

#call add_to_display_file("TableName")
# add tables to the list

foreach c_info_tables into lv_tabname
	# Add lv_tabname to the list
#call add_to_display_file(lv_tabname)
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

#CALL add_to_display_file(lv_outline)
foreach  c_getindex into lv_rec.*, lv_p[1], lv_p[2], lv_p[3], lv_p[4], lv_p[5], lv_p[6], lv_p[7], lv_p[8]

for lv_cnt=1 to 8
	if lv_p[lv_cnt]!=0 then
		let lv_colno=lv_p[lv_cnt]
		select colname into lv_colname from syscolumns where tabid=lv_tabid and colno=lv_colno
		let lv_outline=" "
		if lv_old_index!=lv_rec.idx_name then
			if lv_old_index!=" " then
				#CALL add_to_display_file(" ")
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
		#CALL add_to_display_file(lv_outline)
	end if
end for
end foreach 
return 1
end function

function sql_select_db(lv_dbname)
define lv_dbname char(64)
database lv_dbname
end function


function qry_translate()
error "Can't translate to informix"
return
end function




function do_paginate()
end function

