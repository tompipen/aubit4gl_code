#database syspgma4gl

main
define lv_name char(64)
define lv_dbname char(64)

let lv_dbname=get_syspgma4gl_dbname()
database lv_dbname

whenever error continue
   select count(*) from  z_functioncount

   whenever error stop

   if sqlca.sqlcode!=0 then

     create table z_functioncount (
       programname CHAR(64),
       modulename  CHAR(64),
       lineno INTEGER,
       functionname CHAR(64),
       used CHAR(1)
     )
 
  end if

  LET lv_name=fgl_getenv("PROGNAME")
  
  if lv_name is null or lv_name = " " then
		let lv_name=arg_val(1)
  end if


  if lv_name is null or lv_name = " " then
	
      display "No programname specified by $PROGNAME"
        exit program 1
  end if

  DISPLAY "Deleting current data for ",lv_name

  DELETE from z_functioncount WHERE programname=lv_name

  LOAD FROM "calltree.unl" INSERT INTO z_functioncount
  DISPLAY "Data loaded"
end main

