define mv_colname char(266)
define mv_coltype integer
define mv_colsize integer
define mv_dbname char(255)
define mv_tabname char(255)
define mv_outfile char(512)

main


define lv_filename CHAR(255)
define a integer
initialize mv_dbname, mv_tabname,mv_outfile to null



for a=1 to num_args()
	if arg_val(a)="-d" then
		let mv_dbname=arg_val(a+1)
		let a=a+1
	end if
		
	if arg_val(a)="-t" then
		let mv_tabname=arg_val(a+1)
		let a=a+1
	end if
	if arg_val(a)="-o" then
		let mv_outfile=arg_val(a+1)
		let a=a+1
	end if
	
end for


if mv_tabname is null or mv_dbname is null then
	display "Usage:  generate_ace -d dbname -t tabname"
	exit program
end if

database mv_dbname

if mv_outfile is not null Then
	#LET lv_filename=mv_tabname clipped,".aace"
	START REPORT r_report TO mv_outfile
else
	START REPORT r_report 
end if

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
PAGE LENGTH 1

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
{
char *ptr;
strcpy(mv_colname,"");
 lv_ok=A4GLSQL_next_column (&ptr, &mv_coltype, &mv_colsize) ;
if (ptr) strcpy(mv_colname,ptr);
}
endcode
return lv_ok
end function
