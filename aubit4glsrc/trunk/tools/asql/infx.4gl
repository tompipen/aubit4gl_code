code
extern FILE *out;
extern FILE *exec_out;
extern int outlines;
extern int display_mode;
#define DISPLAY_ACROSS 1
#define DISPLAY_DOWN   2
extern char **columnNames;
extern int *columnWidths;
#define EXEC_MODE_INTERACTIVE   0
#define EXEC_MODE_FILE          1
#define EXEC_MODE_OUTPUT        2
endcode

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


FUNCTION load_info(l_tabname)
DEFINE   i            INTEGER,
         l_tabid      INTEGER,
         l_coltype    INTEGER,
         l_collength  INTEGER
DEFINE lv_buff char(255)
define l_tabname char(255)
define lv_colname char(19)
define rpaginate integer


while true

   CALL open_display_file()
#@ INFORMIX SPECIFIC....

   MESSAGE "Loading column definitions..."
   SELECT tabid
     INTO l_tabid
     FROM systables
    WHERE tabname = l_tabname

   IF sqlca.sqlcode !=0 THEN
	IF sqlca.sqlcode=100 THEN
		ERROR "Table ", l_tabname clipped," was not found.."
	END IF
        IF  check_and_report_error() THEN
      	   RETURN 
        END IF
   END IF

   MESSAGE "Tabid=",l_tabid

   DECLARE info_curs CURSOR FOR
    SELECT colname,coltype, collength, colno
      FROM syscolumns
     WHERE syscolumns.tabid = l_tabid
     ORDER BY colno

   LET i = 0
   FOREACH info_curs INTO lv_colname,l_coltype, l_collength
      LET i = i + 1
      #IF i = 301 THEN
         #CALL message_prompt("More than 300 columns in table!", "")
         #EXIT FOREACH
      #END IF

      LET lv_buff = lv_colname," " ,get_type(l_coltype, l_collength)
code
	A4GL_debug("INFO : %s",lv_buff);
endcode
        CALL add_to_display_file(lv_buff)
   END FOREACH
   let rpaginate=0
code
{
extern int outlines;

   while (1) {
             if (outlines<=0) break;
             aclfgl_paginate(0);
             rpaginate=A4GL_pop_int();
             if (rpaginate!=0) break;
   }
}
endcode

if rpaginate=1 THEN
	CONTINUE WHILE
ELSE
	EXIT WHILE
END IF

END WHILE
MESSAGE ""

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
call display_banner()
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
                        //strcpy(mv_arr[lv_cnt-1],buff);
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
int
printField (FILE * outputFile, int idx, char *descName)
{
  EXEC SQL BEGIN DECLARE SECTION;
  int dataType;
  int index = idx;
  short indicator;
  char buffer[32000]="";

  char *descriptorName = descName;
  int length;

  //loc_t blob;


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
  int rc = 0;

A4GL_assertion(out==0,"No output file (3)");

  EXEC SQL GET DESCRIPTOR 'descExec' VALUE:index:indicator =
    INDICATOR,:dataType = TYPE;

if (indicator!=-1) {
  switch (dataType&0xf)
    {
    case SQLCHAR:
    case SQLVCHAR:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index:length =
        LENGTH;
      if (isSqlError ())
        {
          rc = 1;
          break;
        }
      char_var = (char *)malloc (length + 1);
      EXEC SQL GET DESCRIPTOR:descriptorName VALUE:index:char_var = DATA;
      A4GL_trim (char_var);
      sprintf (buffer, "%s", char_var);
      free (char_var);
      break;
    case SQLSMINT:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:smint_var =
        DATA;
      if (isSqlError ())
        {
          rc = 1;
          break;
        }
      sprintf (buffer, "%d", smint_var);
      break;

    case 6:
    case SQLINT:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:int_var =
        DATA;
      if (isSqlError ())
        {
          rc = 1;
          break;
        }
      sprintf (buffer, "%ld", int_var);
      break;
    case SQLFLOAT:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:float_var =
        DATA;
      if (isSqlError ())
        {
          rc = 1;
          break;
        }
      sprintf (buffer, "%lf", float_var);
      break;
    case SQLSMFLOAT:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:smfloat_var =
        DATA;
      if (isSqlError ())
        {
          rc = 1;
          break;
        }
      sprintf (buffer, "%f", smfloat_var);
      break;
    case SQLDECIMAL:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:decimal_var =
        DATA;
      if (isSqlError ())
        {
          rc = 1;
          break;
        }

      //fgl_decimal = malloc (sizeof (fgldecimal));
      if (dectoasc (&decimal_var, buff, 32, -1))
        {
                A4GL_debug("BAD DECIMAL");
        /** @todo : Store the error somewhere */
          return 1;
        }
        buff[32]=0;
      sprintf (buffer, "%s", buff);
      //free (fgl_decimal);
      break;
    case SQLDATE:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:date_var =
        DATA;
      if (isSqlError ())
        {
          rc = 1;
          break;
        }
      /** @todo : Print as date field */
      char_var = (char *)malloc (sizeof (char) * 10);
      A4GL_dtos (&date_var, char_var, 10);
      sprintf (buffer, "%s", char_var);
      free (char_var);
      break;
    case SQLMONEY:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:money_var =
        DATA;
      if (isSqlError ())
        {
          rc = 1;
          break;
        }
      //fgl_money = malloc (sizeof (fglmoney));
      if (dectoasc (&money_var, buff,32, -1))
        {
        /** @todo : Store the error somewhere */
        A4GL_debug("Bad money");
          return 1;
        }
        buff[32]=0;
      sprintf (buffer, "%s", buff);
      //free (fgl_money);
      break;

    case SQLDTIME:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:dtime_var =
        DATA;
      if (isSqlError ())
        {
          rc = 1;
          break;
        }
      //fgl_dtime = malloc (sizeof (FglDatetime));
      if (dttoasc (&dtime_var, buff))
        {
        /** @todo : Store the error somewhere */
        A4GL_debug("Bad dtime");
          return 1;
        }
      sprintf (buffer, "%s", buff);
      //free (fgl_dtime);
      break;
    case SQLINTERVAL:
    EXEC SQL GET DESCRIPTOR: descriptorName VALUE: index: dataType = TYPE,:interval_var =
        DATA;
      if (isSqlError ())
        {
          rc = 1;
          break;
        }
      //fgl_interval = malloc (sizeof (FglInterval));
      if (intoasc (&interval_var, buff))
        {
        /** @todo : Store the error somewhere */
        A4GL_debug("Bad itime");
          return 1;
        }
      sprintf (buffer, "%s", buff);
      //free (fgl_interval);
      break;
    case SQLBYTES:
      break;
    case SQLTEXT:
      break;
    default:
        A4GL_debug("INVALID DATATYPE %d %x @ %d+++",dataType,dataType,idx);
      A4GL_exitwith ("Invalid data type\n");
    }
} else {
        strcpy(buffer,"");
}



        if (display_mode==DISPLAY_DOWN) {
                if (get_exec_mode_c()==EXEC_MODE_INTERACTIVE)  {
                        fprintf(outputFile,"%-20.20s %s\n",columnNames[idx-1],buffer);
                } else {
                        fprintf(exec_out,"%-20.20s %s\n",columnNames[idx-1],buffer);
                }
                outlines++;
        } else {
                if (get_exec_mode_c()==EXEC_MODE_INTERACTIVE)  {

                        A4GL_debug("EXECO '%s' '%20s' '%-20s'",buffer,buffer,buffer);
                        fprintf(outputFile,"%-*s",columnWidths[idx-1],buffer);
                }
                else
                        fprintf(exec_out,"%-*s",columnWidths[idx-1],buffer);
        }


  return 0;
}
endcode
