define mv_curr_db char(256)
define mc_version constant 0.1

main
define lv_dialect char(20)
defer interrupt

	call form_is_compiled(splash,"MEMPACKED","GENERIC")
	call form_is_compiled(sqls,"MEMPACKED","GENERIC")
	call form_is_compiled(sqldeta,"MEMPACKED","GENERIC")

	call copyright_banner()

	options message line last
	options input wrap

	whenever error continue
	database sqlmetrics
	call set_pick_db("sqlmetrics")
	whenever error stop

	if sqlca.sqlcode!=0 then
		message "Creating sqlmetrics database"
		whenever error continue

		let lv_dialect = dbms_dialect()
		if lv_dialect[1,8] = "POSTGRES" then
			database template1
		end if
		execute immediate "create database sqlmetrics"
		database sqlmetrics
		call set_pick_db("sqlmetrics")
		whenever error stop

		if sqlca.sqlcode!=0 then
			display "Error:",sqlca.sqlcode
			display "   Unable to connect to or create the sqlmetrics database"
			display "   ------------------------------------------------------"
			display " "
			display "Please manually create a database called 'sqlmetrics'"
			display "and create the tables as in $AUBITDIR/tools/a4gl/create_tables.sql."
			display " "
			display "If the database exists then ensure you have permission to connect to it"
			exit program 1
		end if

		call createtables()
		message "sqlmetrics database created" sleep 1
		message " "
	end if
		
	call main_menu()
end main


function err_createtables(lv_errcode)
	define lv_errcode integer
	display "There was an error creating the database tables:",lv_errcode
	display "Please manually create a sqlmetrics with the tables in"
	display "$AUBITDIR/tools/sqlmetrics/create_tables.sql"
	exit program 2
end function

function createtables()
whenever error continue
# We dont care i this one fails...
grant connect to public


create table sql_log
  (
   application varchar(30), -- is the program name of the program generating the output
   pid int,    --     is the process ID
   type varchar(10), -- is PREPARE/EXECUTE/OPEN/FETCH/DECLARE/PUT
   cursorname varchar(30), -- is the name of the cursor for a OPEN/FETCH/DECLARE/PUT
   sql varchar(2048), --  is the SQL being processed.
   module varchar(30), --  is the modulename of the 4gl where this SQL is located
   lineno int, --  is the line number in the 4gl where this SQL is located
   elatime float --    is the execution of this statement in seconds
  );

if sqlca.sqlcode<0 then

	-- Some db's dont like a varchar > 255 in size...
	-- so lets try again with a real char (rather than a varchar)
	create table sql_log
  	(
   	application varchar(30), -- is the program name of the program generating the output
   	pid int,    --     is the process ID
   	type varchar(10), -- is PREPARE/EXECUTE/OPEN/FETCH/DECLARE/PUT
   	cursorname varchar(30), -- is the name of the cursor for a OPEN/FETCH/DECLARE/PUT
   	sql char(2048), --  is the SQL being processed.
   	module varchar(30), --  is the modulename of the 4gl where this SQL is located
   	lineno int, --  is the line number in the 4gl where this SQL is located
   	elatime float --    is the execution of this statement in seconds
  	);

	if sqlca.sqlcode<0 then
		call err_createtables(sqlca.sqlcode)
	end if
end if

create index i_sql on sql_log (sql)

whenever error stop
end function

function set_curr_db(p_dbname)
define p_dbname char(255)

call set_current_db(p_dbname) returning p_dbname

if p_dbname is null or length(p_dbname)=0 then
        initialize mv_curr_db to null
else
        let p_dbname=check_db(p_dbname)
        let mv_curr_db=p_dbname
end if
call set_pick_db(mv_curr_db)
end function

function has_db()
        if mv_curr_db is null then
                return 0
        else
                return 1
        end if
end function

function get_db()
        if mv_curr_db is null then
                return ""
        else
                return mv_curr_db
        end if
end function

function check_and_report_error()
if sqlca.sqlcode>=0 then
        return 0
end if
error "Unable to connect to database"
return 1
end function

function get_version()
define lv_str char(80)

let lv_str="SQLMetrics IDE  Version ",mc_version using "##&.&&"
return lv_str
end function

function middle(s)
define s char(255)
define s1 char(255)
define w integer
define a integer
code
w=A4GL_get_curr_width();
endcode
let a=w-length(s)
let a=a/2
let s1[a,255]=s
return s1
end function

function copyright_banner()
clear screen
if get_use_form() then
	open window w_splash at 1,1 with form "splash"
	sleep 2
	close window w_splash
else
	display middle(get_version()) at 7,1
	call display_to_line(9,middle("(c) 2009 Aubit Computing Ltd"))
	call display_to_line(10,middle("http://www.aubit.com"))
	call display_to_line(13,middle("Latest version available at:"))
	call display_to_line(14,middle("http://aubit4gl.sourceforge.net"))
	call display_to_line(16,middle("Development sponsored by Fabrica de Jabon La Corona "))
	call display_to_line(17,middle("http://www.lacorona.com.mx/"))
	sleep 2 # Splash Screen
	clear screen
end if
end function


function display_to_line (lv_line,lv_str)
define lv_line integer
define lv_str char(512)
display lv_str clipped,"" at lv_line,1
end function

function set_and_display_banner() 
	call display_banner()
end function
