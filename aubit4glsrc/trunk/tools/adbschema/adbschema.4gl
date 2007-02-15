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

DEFINE gv_filter_out_table_prefix char (16)
code
FILE *fout=0;
endcode

main
define 
	a integer,
	lv_4gl integer,
	lv_tmp char(256),
	lv_str char(40),
	lv_systables smallint,	#true or false, process Informix sys* tables (default=false)
	lv_prefix_idx smallint,  #true or false, add prefix to index names (default=false)
	lv_no_owner smallint	#true or false, do not putput object owner (default=false)
	
	let mv_silent=0
	LET lv_ss="N"
	let lv_srpf="-"
	let mv_mode=0
	let mv_perms=1
	let lv_4gl=0
	initialize lv_output to null
	
	let lv_systables = false
	let lv_prefix_idx = false
	let lv_no_owner = false
	initialize gv_filter_out_table_prefix to null
	
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
		
			when "-sys" 		let lv_systables = true

			when "-noowner" 	let lv_no_owner = true
			
			when "-prefix-idx" 	let lv_prefix_idx = true

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

			when "-filter-out-table-prefix"
				let a=a+1
				let gv_filter_out_table_prefix=arg_val(a)
				
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
						let lv_tmp=arg_val(a)
						display "Confused - is ",lv_output clipped," or ",lv_tmp clipped," the filename for the output ?"
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

	if lv_procname is not null then
		call dump_proc(lv_procname)

	else



	if lv_tabname is not null then
		if lv_srpf="-" then
			call dump_table(lv_tabname,lv_systables,lv_prefix_idx,lv_no_owner)
		else
			call dump(lv_srpf,lv_tabname,lv_systables)
		end if
	else
		if lv_srpf="-" then # Looks like the whole database





			if mv_mode=0 then
				call dump_dbperms()
			end if

			call dump_table("all",lv_systables,lv_prefix_idx,lv_no_owner)

			if mv_mode=0 then
				call dump_proc("all")
				call dump_perm("all")
			end if
		else
			if lv_4gl then
				call outstr("MAIN")
				call outstr("DEFINE lv char (600)")
				
				call outstr("let lv=fgl_getenv(\"DB_NAME_TARGET\")")
				call outstr("if lv = \"\" or lv IS NULL then")
					#Use same database name as the one we unloaded from
					let lv_str="	DATABASE ",lv_dbname clipped
					call outstr(lv_str)
					let lv_str="	DISPLAY \"Loading into db ",lv_dbname clipped,"\""
					call outstr(lv_str)
				call outstr("else")
					call outstr("	DATABASE lv")
					call outstr("	DISPLAY \"Loading into db \",lv CLIPPED")
				call outstr("end if")
				
				#TODO - do not hard-code DMY - take if from $DBDATE at unload time
				
				#cant find a setting for DATE delimiter in PG?
				
				call outstr("IF dbms_dialect()='POSTGRESQL' THEN")
				{
				The function current_setting yields the current value of the 
				setting setting_name. It corresponds to the SQL command SHOW
				}
				call outstr("	let lv = \"SELECT current_setting('datestyle');\"")
				call outstr("	PREPARE cur1 FROM lv")
				call outstr("	EXECUTE cur1 INTO lv")
				call outstr("	DISPLAY lv CLIPPED")
				call outstr("	")
				{
				set_config sets the parameter setting_name to new_value. 
				If is_local is true, the new value will only apply to the 
				current transaction. If you want the new value to apply for 
				the current session, use false instead. The function corresponds 
				to the SQL command SET.
				}
				#
				call outstr("	let lv = \"SELECT set_config('datestyle', 'Informix, DMY', false);\"")
				call outstr("	PREPARE cur2 FROM lv")
				call outstr("	EXECUTE cur2")
				call outstr("	")



				call outstr("	let lv = \"SELECT current_setting('datestyle');\"")
				call outstr("	PREPARE cur3 FROM lv")
				call outstr("	EXECUTE cur3 INTO lv")
				call outstr("	DISPLAY lv CLIPPED")
				call outstr("	")

				#call outstr("	EXIT PROGRAM")
				
				call outstr("END IF")
				
			end if

			call dump(lv_srpf,"all",lv_systables)

			if lv_4gl then
				call outstr("	DISPLAY 'Done.'")
				call outstr("END MAIN")
			end if
		end if
	end if
	end if
code
if (fout) {fclose(fout);}
endcode

end main



function outstr(lv_s)
define lv_s char(20000)
define lv_f char(200)
if lv_output is null then
display lv_s clipped
else
	let lv_f=lv_output
code
if (fout==0) {
	A4GL_trim(lv_f);
	fout=fopen(lv_f,"w");
	if (fout==0) {
		printf("Unable to open output file : %s\n",lv_f);
		exit(2);
	}
}
	A4GL_trim(lv_s);
fprintf(fout,"%s\n",lv_s);
endcode
end if

end function



function outstr_n256(lv_s)
define lv_s char(256)
define lv_f char(256)

if lv_output is null then
code
	printf("%s",lv_s);
endcode
else
	let lv_f=lv_output
code

if (fout==0) {
	A4GL_trim(lv_f);
	fout=fopen(lv_f,"w");
	if (fout==0) {
		printf("Unable to open output file : %s\n",lv_f);
		exit(2);
	}
}
fprintf(fout,"%s",lv_s);
endcode
end if

end function

function get_filter_out_table_prefix()
	return gv_filter_out_table_prefix
end function


function usage()
	display " " 
	display "ADBSCHEMA (c) 2005 Aubit Computing Ltd"
	display " " 
	display "adbschema [-sys] [-noperms] [-fileschema] [-t tabname] [-s user] [-p user] "
	display "          [-r rolename] [-f procname] -d dbname [-ss] [filename]"
	display ""
	display "   -noperms     Do not include any GRANT/REVOKE"
	display "   -fileschema  Generate a schema suitable for the FILESCHEMA SQL Module"
	display "   -sys         Process Informix system tables with tabid < 99"
	display "   -prefix-idx  Add prefix to index names (IDX_)"
	display "   -ss          todo"
	display "   -noowner     Do not output object's (table/index/etc) owner information"
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

