define mv_lastused char(512)

################################################################################
function load_menu()
  	call clear_screen_portion()
		MENU "Load SQLMetrics"
			command "All" "Load all *.log files"
				if load_all() then
					next option "Exit"
				end if
			
			command "Chose" "Chose files to load"
				if load_some() then
					next option "Exit"
				end if
		
			command "Truncate" "Delete all existing SQLMetrics from table"
				if confirm_yes_no() = "Yes" then
					call delete_rows() 
					next option "All"
				end if

			command "Exit"  "Return to main menu"
				exit menu
		end menu
end function

function confirm_yes_no()
    MENU "CONFIRM"
      BEFORE MENU
        CALL display_banner()

      COMMAND KEY "n" "No" "No - I don't want to drop it"
      		RETURN "No"
      COMMAND KEY "y" "Yes" "Yes - I do want to drop it"
      		RETURN "Yes"
    END MENU
end function

FUNCTION more_yes_no()
    MENU "Load More"
      BEFORE MENU
        CALL display_banner()

      COMMAND KEY "n" "No" "No - I don't want to load more"
      		RETURN "No"
      COMMAND KEY "y" "Yes" "Yes - I do want to load more"
      		RETURN "Yes"
    END MENU
END FUNCTION


################################################################################
function load_all()
define lv_file char(512)
define lv_path varchar(512)
define a integer
LET lv_path = fgl_getenv("A4GL_SQLMETRICS") CLIPPED
code
{
    char **dir;
    dir=A4GL_read_directory(lv_path,".log");
    if (dir) {
        for (a=0;dir[a];a++) {
            strcpy(lv_file,dir[a]);
endcode
            call load_file(lv_path,lv_file);
code
        }
    A4GL_free_directory();
    }
}
endcode
return true
end function

################################################################################
function load_some()
define lv_file char(512)
define lv_path varchar(512)
define a integer
define lv_more char(3)
LET lv_path = fgl_getenv("A4GL_SQLMETRICS") CLIPPED
code
{
    char **dir;
    dir=A4GL_read_directory(lv_path,".log");
    if (dir) {
        for (a=0;dir[a];a++) {
            strcpy(lv_file,dir[a]);
endcode
            call set_pick(a+1,lv_file);
code
        }
    A4GL_free_directory();
    }
}
endcode

call set_pick_cnt(a);
let lv_more = "Yes"
while lv_more = "Yes"
    call set_picked_option(mv_lastused)
    call prompt_pick_and_say("Load >> ","","Choose a file to load") returning lv_file
    if lv_file is not null then
         call load_file(lv_path,lv_file);
         let mv_lastused = lv_file
    end if
    call more_yes_no() returning lv_more
end while
return true
end function


function load_file(lv_path,lv_file)
define lv_path char(512)
define lv_file char(512)
define lv_filename varchar(512)
define lr record
    application varchar(30), --	is the program name of the program generating the output
	pid int, --	 is the process ID
	type varchar(12), -- is PREPARE/EXECUTE/OPEN/FETCH/DECLARE/PUT
	cursorname varchar(30), --	is the name of the cursor for a OPEN/FETCH/DECLARE/PUT
	sql char(2048), -- is the SQL being processed.
	module varchar(32), --	 is the modulename of the 4gl where this SQL is located
	lineno int, --	 is the line number in the 4gl where this SQL is located
	elatime float --	 is the execution of this statement in seconds
    end record

let lv_filename = lv_path clipped, "/", lv_file clipped, ".log"
display "loading ... ", lv_filename clipped
call channel::open_file("log",lv_filename,"r")
call channel::set_delimiter("log","|")
while channel::read("log",[lr.*])
    insert into sql_log (application, pid, type, cursorname, sql, module, lineno, elatime) values (lr.*)
end while
call channel::close("log")
end function

function delete_rows()
delete from sql_log
end function
