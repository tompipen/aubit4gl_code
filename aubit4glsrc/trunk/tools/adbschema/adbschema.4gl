define lv_tabname char(64)
define lv_user char(64)
define lv_srpf char(1)
define lv_procname char(64)
define lv_dbname char(64)
define lv_ss char(1)
define lv_output char(64)
define mv_silent integer
define mv_mode integer
define mv_perms integer

GLOBALS
	DEFINE gv_systables integer	#true or false, process Informix sys* tables (default=0)
END GLOBALS

function usage()
	display " " 
	display "ADBSCHEMA (c) 2005 Aubit Computing Ltd"
	display " " 
	display "adbschema [-sys] [-noperms] [-fileschema] [-t tabname] [-s user] [-p user] [-r rolename] [-f procname]"
	display "          -d dbname [-ss] [filename]"

	display "   -noperms     Do not include any GRANT/REVOKE"
	display "   -fileschema  Generate a schema suitable for the FILESCHEMA SQL Module"
	display "   -sys         Process Informix system tables with tabid < 99"	
	display " "
	exit program 1
end function


function is_ss()
	return lv_ss="Y"
end function


function get_mode()
	return mv_mode
end function

function get_perms()
	return mv_perms
end function


main
define a integer
define lv_4gl integer
define lv_str char(40)

	let gv_systables = 0
	let mv_silent=0
	LET lv_ss="N"
	let lv_srpf="-"
	let mv_mode=0
	let mv_perms=1
	let lv_4gl=0

	if num_args()=0 then
		call usage()
	end if
	for a=1 to num_Args()

		case arg_val(a)

			when "-fileschema"
				let mv_mode=1

			when "-noperms"
				let mv_perms=0

			when "-t" 
				let a=a+1
				let lv_tabname=arg_val(a)


			when "-U" let lv_srpf="U"
			when "-U4GL" let lv_srpf="U" let lv_4gl=1

			when "-L" let lv_srpf="L"

			when "-L4GL" let lv_srpf="L" let lv_4gl=1

			when "-s" 
				let a=a+1
				let lv_user=arg_val(a)
				let lv_srpf="S"

			when "-p" 
				let a=a+1
				let lv_user=arg_val(a)
				let lv_srpf="P"
		
			when "-sys"
				let a=a+1
				let gv_systables = 1
			
			when "-r" 
				let a=a+1
				let lv_user=arg_val(a)
				let lv_srpf="R"

			when "-f" 
				let a=a+1
				let lv_procname=arg_val(a)
				let lv_srpf="F"

			when "-d" 
				let a=a+1
				let lv_dbname=arg_val(a)

			when "-q" 
				let mv_silent=1
			

			when "-ss" 
				let lv_ss="Y"
			
			otherwise
				if arg_val(a) matches "-*" then
					display "Unknown option"
					call usage()
				else
					if lv_output is null then
						let lv_output=arg_val(a)
					else
						display "Confused - is ",lv_output clipped," or ",arg_val(a) clipped," the filename for the output ?"
						call usage()
					end if
				end if
		end case
	end for

	if lv_dbname is null then
		display "No database specified"
		call usage()
	end if

	database lv_dbname


	if mv_silent=0 then
		display "ADBSCHEMA (c) 2005 Aubit Computing Ltd"
	end if



	if lv_tabname is not null then
		if lv_srpf="-" then
			call dump_table(lv_tabname)
		else
			call dump(lv_srpf,lv_tabname)
		end if
	else
		if lv_srpf="-" then # Looks like the whole database
			if mv_mode=0 then
				call dump_dbperms()
			end if

			call dump_table("all")

			if mv_mode=0 then
				call dump_procedures()
				call dump_perm("all")
			end if
		else
			if lv_4gl then
				let lv_str="DATABASE ",lv_dbname
				call outstr(lv_str)
				call outstr("MAIN")
			end if

			call dump(lv_srpf,"all")

			if lv_4gl then
				call outstr("END MAIN")
			end if
		end if
	end if


end main



function outstr(lv_s)
define lv_s char(20000)
display lv_s clipped
end function

