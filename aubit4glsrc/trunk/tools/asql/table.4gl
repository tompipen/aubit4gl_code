function table_menu()
        if not has_db() then
                call select_db()
        end if

	MENU "TABLE"
		command "Create" "Create a new Table (not implemented)"
			error "Not Implemented"

		command "Alter" "Alter a table (not implemented)"
			error "Not Implemented"

		command "Info" "Info for a table"
			call table_info()
		
		command "Drop" "Drop a table"
			call table_drop()

		command "Exit" "Return to ADBACCESS Menu"
			exit menu
	END MENU
end function




function table_drop()
define lv_tabname char(255)
define lv_rval INTEGER
call table_Select("DROP TABLE >>") returning lv_tabname
let lv_tabname="DROP TABLE ",lv_tabname clipped
MENU "CONFIRM:"
	command "No"
		let lv_rval=0
		exit menu
		RETURN 0

	command "Yes"
		PREPARE p_droptable FROM lv_tabname
		IF check_and_report_error() THEN
			LET lv_rval=1
		else
			EXECUTE p_droptable
			LET lv_rval=check_and_report_error() 
		END IF
		exit menu
END MENU
return lv_rval
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




function table_info()
define lv_tabname char(255)
	call table_select("INFO FOR TABLE >>") returning lv_tabname

	if lv_tabname is not null and lv_tabname not matches " " THEN
		call load_info(lv_tabname)
	end if

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
WHEN l_coltype=0 OR l_coltype=256
    LET type_text="CHAR(", l_collength USING "<<<", ")"
WHEN l_coltype=1 OR l_coltype=257
    LET type_text="SMALLINT"
WHEN l_coltype=2 OR l_coltype=258
    LET type_text="INTEGER"
WHEN l_coltype=3 OR l_coltype=259
    LET type_text="FLOAT"
WHEN l_coltype=4 OR l_coltype=260
    LET type_text="SMALLFLOAT"
WHEN l_coltype=5 OR l_coltype=261
    LET type_text="DECIMAL"
    LET type_text = dec_length(l_collength, type_text)
WHEN l_coltype=6 OR l_coltype=262
    IF l_collength > 1 THEN
        LET type_text="SERIAL(",
            l_collength USING "<<<<<<<<<&", ")"
    ELSE
        LET type_text="SERIAL"
    END IF
WHEN l_coltype=7 OR l_coltype=263
    LET type_text="DATE"
WHEN l_coltype=8 OR l_coltype=264
    LET type_text="MONEY"
    LET type_text = dec_length(l_collength, type_text)
WHEN l_coltype=10 OR l_coltype=266
    LET type_text="DATETIME"
    LET type_text = dt_length(l_collength, type_text)
WHEN l_coltype=11 OR l_coltype=267
    LET type_text="BYTE"
WHEN l_coltype=12 OR l_coltype=268
    LET type_text="TEXT"
WHEN l_coltype=13 OR l_coltype=269
    LET type_text="VARCHAR"
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
WHEN l_collength = 459
    LET type_text = type_text CLIPPED, " FRACTION TO FRACTION(1)"
WHEN l_collength = 546
    LET type_text = type_text CLIPPED, " MONTH TO MONTH"
WHEN l_collength = 580
    LET type_text = type_text CLIPPED, " DAY TO DAY"
WHEN l_collength = 614
    LET type_text = type_text CLIPPED, " HOUR TO HOUR"
WHEN l_collength = 648
    LET type_text = type_text CLIPPED, " MINUTE TO MINUTE"
WHEN l_collength = 682
    LET type_text = type_text CLIPPED, " SECOND TO SECOND"
WHEN l_collength = 716
    LET type_text = type_text CLIPPED, " FRACTION TO FRACTION(2)"
WHEN l_collength = 939
    LET type_text = type_text CLIPPED, " SECOND TO FRACTION(1)"
WHEN l_collength = 973
    # default fraction is 3, so no need for ()
    LET type_text = type_text CLIPPED, " FRACTION TO FRACTION"
WHEN l_collength = 1024
    LET type_text = type_text CLIPPED, " YEAR TO YEAR"
WHEN l_collength = 1060
    LET type_text = type_text CLIPPED, " MONTH TO DAY"
WHEN l_collength = 1094
    LET type_text = type_text CLIPPED, " DAY TO HOUR"
WHEN l_collength = 1128
    LET type_text = type_text CLIPPED, " HOUR TO MINUTE"
WHEN l_collength = 1162
    LET type_text = type_text CLIPPED, " MINUTE TO SECOND"
WHEN l_collength = 1196
    LET type_text = type_text CLIPPED, " SECOND TO FRACTION(2)"
WHEN l_collength = 1230
    LET type_text = type_text CLIPPED, " FRACTION TO FRACTION(4)"
WHEN l_collength = 1419
    LET type_text = type_text CLIPPED, " MINUTE TO FRACTION(1)"
WHEN l_collength = 1453
    LET type_text = type_text CLIPPED, " SECOND TO FRACTION"
WHEN l_collength = 1487
    LET type_text = type_text CLIPPED, " FRACTION TO FRACTION(5)"
WHEN l_collength = 1538
    LET type_text = type_text CLIPPED, " YEAR TO MONTH"
WHEN l_collength = 1574
    LET type_text = type_text CLIPPED, " MONTH TO HOUR"
WHEN l_collength = 1608
    LET type_text = type_text CLIPPED, " DAY TO MINUTE"
WHEN l_collength = 1642
    LET type_text = type_text CLIPPED, " HOUR TO SECOND"
WHEN l_collength = 1676
    LET type_text = type_text CLIPPED, " MINUTE TO FRACTION(2)"
WHEN l_collength = 1710
    LET type_text = type_text CLIPPED, " SECOND TO FRACTION(4)"
WHEN l_collength = 1899
    LET type_text = type_text CLIPPED, " HOUR TO FRACTION(1)"
WHEN l_collength = 1933
    LET type_text = type_text CLIPPED, " MINUTE TO FRACTION"
WHEN l_collength = 1967
    LET type_text = type_text CLIPPED, " SECOND TO FRACTION(5)"
WHEN l_collength = 2052
    LET type_text = type_text CLIPPED, " YEAR TO DAY"
WHEN l_collength = 2088
    LET type_text = type_text CLIPPED, " MONTH TO MINUTE"
WHEN l_collength = 2122
    LET type_text = type_text CLIPPED, " DAY TO SECOND"
WHEN l_collength = 2156
    LET type_text = type_text CLIPPED, " HOUR TO FRACTION(2)"
WHEN l_collength = 2190
    LET type_text = type_text CLIPPED, " MINUTE TO FRACTION(4)"
WHEN l_collength = 2379
    LET type_text = type_text CLIPPED, " DAY TO FRACTION(1)"
WHEN l_collength = 2413
    LET type_text = type_text CLIPPED, " HOUR TO FRACTION"
WHEN l_collength = 2447
    LET type_text = type_text CLIPPED, " MINUTE TO FRACTION(5)"
WHEN l_collength = 2566
    LET type_text = type_text CLIPPED, " YEAR TO HOUR"
WHEN l_collength = 2602
    LET type_text = type_text CLIPPED, " MONTH TO SECOND"
WHEN l_collength = 2636
    LET type_text = type_text CLIPPED, " DAY TO FRACTION(2)"
WHEN l_collength = 2670
    LET type_text = type_text CLIPPED, " HOUR TO FRACTION(4)"
WHEN l_collength = 2859
    LET type_text = type_text CLIPPED, " MONTH TO FRACTION(1)"
WHEN l_collength = 2893
    LET type_text = type_text CLIPPED, " DAY TO FRACTION"
WHEN l_collength = 2927
    LET type_text = type_text CLIPPED, " HOUR TO FRACTION(5)"
WHEN l_collength = 3080
    LET type_text = type_text CLIPPED, " YEAR TO MINUTE"
WHEN l_collength = 3116
    LET type_text = type_text CLIPPED, " MONTH TO FRACTION(2)"
WHEN l_collength = 3150
    LET type_text = type_text CLIPPED, " DAY TO FRACTION(4)"
WHEN l_collength = 3373
    LET type_text = type_text CLIPPED, " MONTH TO FRACTION"
WHEN l_collength = 3407
    LET type_text = type_text CLIPPED, " DAY TO FRACTION(5)"
WHEN l_collength = 3594
    LET type_text = type_text CLIPPED, " YEAR TO SECOND"
WHEN l_collength = 3630
    LET type_text = type_text CLIPPED, " MONTH TO FRACTION(4)"
WHEN l_collength = 3851
    LET type_text = type_text CLIPPED, " YEAR TO FRACTION(1)"
WHEN l_collength = 3887
    LET type_text = type_text CLIPPED, " MONTH TO FRACTION(5)"
WHEN l_collength = 4108
    LET type_text = type_text CLIPPED, " YEAR TO FRACTION(2)"
WHEN l_collength = 4365
    LET type_text = type_text CLIPPED, " YEAR TO FRACTION"
WHEN l_collength = 4622
    LET type_text = type_text CLIPPED, " YEAR TO FRACTION(4)"
WHEN l_collength = 4879
    LET type_text = type_text CLIPPED, " YEAR TO FRACTION(5)"
OTHERWISE
    LET type_text = type_text CLIPPED, " ????"
END CASE

RETURN type_text

END FUNCTION
