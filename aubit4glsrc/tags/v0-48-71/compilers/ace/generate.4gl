define mv_colname char(266)
define mv_coltype integer
define mv_colsize integer
define mv_dbname char(255)
define mv_tabname char(255)


main


define lv_filename CHAR(255)

if num_args()!=2 then
	display "Usage generate_ace dbname tabname"
	exit program
end if

let mv_dbname=arg_val(1)
let mv_tabname=arg_val(2)

database mv_dbname

LET lv_filename=mv_tabname clipped,".aace"


START REPORT r_report TO lv_filename

IF start_get_cols(mv_tabname)=0 THEN
	DISPLAY "Unable to get columns for table ",mv_tabname clipped
	EXIT PROGRAM
END IF

WHILE get_cols() 
		OUTPUT TO REPORT r_report (mv_colname)
END WHILE
FINISH REPORT r_report

end main


REPORT r_report(r_colname)
DEFINE r_colname CHAR(30)
DEFINE lv_printed INTEGER
OUTPUT LEFT MARGIN 0 
RIGHT MARGIN 0
TOP MARGIN 0
BOTTOM MARGIN 0
PAGE LENGTH 66

FORMAT
FIRST PAGE HEADER
	LET lv_printed=0

ON EVERY ROW
	IF lv_printed THEN 
		PRINT ","
	ELSE
		PRINT "DATABASE ",mv_dbname clipped, " END"
		PRINT ""
		PRINT "SELECT "
		LET lv_printed=1
		PRINT ""
	END IF
	
	PRINT "    ",r_colname clipped;

ON LAST ROW
	PRINT ""
	PRINT "FROM ",mv_tabname clipped," END"
	PRINT ""
	PRINT "FORMAT EVERY ROW END"


END REPORT 






function start_get_cols(lv_tabname) 
define lv_tabname char(256)
define lv_ok integer
code
 trim(lv_tabname);
 //A4GLSQL_get_columns char* tabname char* colname int* dtype int* size -> int
 lv_ok=A4GLSQL_get_columns (lv_tabname,"",0,0);
endcode
return lv_ok
end function


function get_cols() 
define lv_ok INTEGER
code
 lv_ok=A4GLSQL_next_column (mv_colname, &mv_coltype, &mv_colsize) ;
endcode
return lv_ok
end function
