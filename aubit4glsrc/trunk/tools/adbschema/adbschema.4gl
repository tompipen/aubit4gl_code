define lv_tabname char(64)
define lv_user char(64)
define lv_srpf char(1)
define lv_procname char(64)
define lv_dbname char(64)
define lv_ss char(1)
define lv_output char(64)
define mv_silent integer


function usage()
	display "adbschema [-t tabname] [-s user] [-p user] [-r rolename] [-f procname]"
	display "          -d dbname [-ss] [filename]"
	exit program 1
end function


function is_ss()
	return lv_ss="Y"
end function


main
define a integer

	let mv_silent=0
	LET lv_ss="N"
	let lv_srpf="-"

	if num_args()=0 then
		call usage()
	end if
	for a=1 to num_Args()

		case arg_Val(a)
			when "-t" 
				let a=a+1
				let lv_tabname=arg_val(a)

			when "-s" 
				let a=a+1
				let lv_user=arg_val(a)
				let lv_srpf="S"

			when "-p" 
				let a=a+1
				let lv_user=arg_val(a)
				let lv_srpf="P"
		

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
		call dump_table(lv_tabname)
	else
		if lv_srpf="-" then # Looks like the whole database
			call dump_dbperms()
			call dump_table("all")
			call dump_procedures()
			call dump_perms("all")
		end if
	end if


end main



function outstr(lv_s)
define lv_s char(20000)
display lv_s clipped
end function

