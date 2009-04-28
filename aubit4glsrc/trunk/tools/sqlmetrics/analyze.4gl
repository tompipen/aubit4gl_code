################################################################################
function analyze_menu()
  	call clear_screen_portion()
		MENU "Analyze"
			command "Suspicious" "Single SQL with longer time"
				call analyze_suspicious()
			
			command key 'x' "eXpensive" "SQL executed many times with a cumulative time"
				call analyze_expensive()
		
			command "Invalid" "SQL statements with error"
				call analyze_invalid()

			command "Exit"  "Return to main menu"
				exit menu
		end menu
end function

function analyze_suspicious()
define lv_sql char(512)
let lv_sql = "select first 30 avg(elatime), count(*),  sql, max(elatime), min(elatime) from sql_log group by sql order by 1 desc"
call analyze_sql("Avg Time",lv_sql)
end function

function analyze_expensive()
define lv_sql char(512)
let lv_sql = "select first 30 sum(elatime), count(*), sql, max(elatime), min(elatime) from sql_log group by sql order by 1 desc"
call analyze_sql("Load",lv_sql)
end function

function analyze_invalid()
define lv_sql char(512)
let lv_sql = "select first 30 count(*), sql, sql_code  from sql_log  where sql_code <> 0 group by sql, sql_code order by 2 desc"
call analyze_sqlerr(lv_sql)
end function

function analyze_sql(lp_title, lp_sql)
define lp_title varchar(20)
define lp_sql char(512)
define lv_i, lv_j int
define la array[30] of record
         data float,
         count int,
         trap char(1),
         sql char(2048),
         max float,
         min float
     end record,
     lr record
         data float,
         count int,
         sql char(2048),
         max float,
         min float
     end record

open window v_sqls at 3,1 with form "sqls"  attribute(form line 1)
display lp_title to title
prepare ex_sqls from lp_sql
declare c_sqls cursor for ex_sqls
#display "sql=", lp_sql
let lv_i = 0
foreach c_sqls into lr.*
    let lv_i = lv_i + 1
    #display "found ...", lr.data
    let la[lv_i].data = lr.data
    let la[lv_i].count = lr.count
    let la[lv_i].trap = " "
    let la[lv_i].sql = lr.sql
    let la[lv_i].max = lr.max
    let la[lv_i].min = lr.min
    #display "found2 ...", la[lv_i].data
    if lv_i > 29 then exit foreach end if
end foreach
call set_count(lv_i)
#display "total ", lv_i
input array la without defaults from srec1.* 
      attributes(insert row=false, delete row=false)
    before row
       let lv_i = arr_curr()
       let lv_j = scr_line()
       display la[lv_i].* to srec1[lv_j].* attribute(REVERSE)
    after row
       let la[lv_i].trap = " "
       display la[lv_i].* to srec1[lv_j].* attribute(dim)
    after field trap
       if la[lv_i].trap <> " " then
           let la[lv_i].trap = " "
           call extend_sql(la[lv_i].sql)
       end if
end input
close window v_sqls
end function

function analyze_sqlerr(lp_sql)
define lp_sql char(512)
define lv_i, lv_j int
define la array[30] of record
         count int,
         trap char(1),
         sql char(2048),
         sql_code int
     end record,
     lr record
         count int,
         sql char(2048),
         sql_code int
     end record

open window v_sqlerr at 3,1 with form "sqlerr"  attribute(form line 1)
prepare ex_sqlerr from lp_sql
declare c_sqlerr cursor for ex_sqlerr
#display "sql=", lp_sql
let lv_i = 0
foreach c_sqlerr into lr.*
    let lv_i = lv_i + 1
    -- display "found ...", lr.sql_code
    let la[lv_i].count = lr.count
    let la[lv_i].trap = " "
    let la[lv_i].sql = lr.sql
    let la[lv_i].sql_code = lr.sql_code
    -- display "found2 ...", la[lv_i].sql_code
    if lv_i > 29 then exit foreach end if
end foreach
call set_count(lv_i)
#display "total ", lv_i
input array la without defaults from srec1.* 
      attributes(insert row=false, delete row=false)
    before row
       let lv_i = arr_curr()
       let lv_j = scr_line()
       display la[lv_i].* to srec1[lv_j].* attribute(REVERSE)
    after row
       let la[lv_i].trap = " "
       display la[lv_i].* to srec1[lv_j].* attribute(dim)
    after field trap
       if la[lv_i].trap <> " " then
           let la[lv_i].trap = " "
           call extend_sql(la[lv_i].sql)
       end if
end input
close window v_sqlerr
end function

function extend_sql(lp_sql)
define lp_sql char(2048)
define lv_i int
define lr record
           count int,
           app varchar(32),
           module varchar(32),
           lineno int,
           curtime double precision
       end record
define la array[30] of record
           count int,
           app varchar(32),
           module varchar(32),
           lineno int,
           time char(19)
       end record,
       lv_prep char(255)
open window v_sqldeta at 4,4 with form "sqldeta" attribute(border, form line 1)
display lp_sql to sql attribute(bold)
let lv_prep = "select count(*), application, module, lineno, max(curtime) from sql_log where sql = ? group by 2, 3, 4 order by 1 desc"
prepare ex_prep2 from lv_prep
declare c_sqldeta cursor for ex_prep2
#display "sql=", lv_prep
let lv_i = 0
foreach c_sqldeta using lp_sql into lr.*
    let lv_i = lv_i + 1
    #display "found ... ", lr.app
    let la[lv_i].count = lr.count
    let la[lv_i].app = lr.app
    let la[lv_i].module = lr.module
    let la[lv_i].lineno = lr.lineno
    let la[lv_i].time = epoch2str(lr.curtime)
    if lv_i > 29 then exit foreach end if
end foreach
#display "total=", lv_i
call set_count(lv_i)
display array la to srec2.* attribute(underline)
    on key(esc)
        exit display
end display
close window v_sqldeta
end function
