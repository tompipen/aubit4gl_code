define mv_current_module char(256)
define mv_db char(255)

define mv_lastused char(255)
define mv_generated_exe integer




################################################################################
function module_menu()
define lv_ok integer


  	call clear_screen_portion()
	call init_filename()


		MENU "Module"
			command "Modify" "Modify an existing module"
				let mv_generated_exe=false
				call modify_module("",FALSE,"")  RETURNING lv_ok
				if lv_ok then
					if mv_generated_exe then
						next option "Run"
					end if
				end if
			
			command "New" "Create a new empty module"
				let mv_generated_exe=false
				if new_module() then
					if mv_generated_exe then
						next option "Run"
					end if
				end if
		
			command "Compile" "Compile a module"
				let mv_generated_exe=false
				call module_menu_compile()  returning lv_ok
				if lv_ok then
					if mv_generated_exe then
						next option "Run"
					end if
				end if

			command "Program-Compile" "Compile a program"
				call program_compile()
			
			command "Run" "Run a program"
				call program_run()

	{
			command "Drop"  "Delete a module"
				call drop_module()
	}
		
			command "Exit"  "Return to main menu"
				exit menu
		end menu

end function




################################################################################
function modify_module(lv_mname,lv_errfile,lv_initstate)
define lv_mname char(255)
define a integer
define lv_runstr char(512)
define lv_backup char(255)
define lv_errfile integer
define lv_initstate char(30)
define lv_need_backup integer
define lv_need_to_edit integer
define lv_ok integer

define lv_state char(30)
define lv_next_suggested_state char(30)
define lv_editor char(256)
define lv_makefile,lv_objfile char(512)

	let lv_need_to_edit=true
	let lv_need_backup=false

	if lv_mname is null or lv_mname matches "" then
		let lv_mname=get_filename_to("modify",".4gl",mv_lastused)
		let lv_need_backup=true
		if lv_mname is null or lv_mname = " " then
			return false
		end if
	end if
	
	
	
	if lv_mname not matches "*.4[Gg][Ll]" then
       		let lv_mname=lv_mname clipped,".4gl"
	end if
	
	if lv_need_backup and lv_errfile then
		error "Internal error - not expecting both lv_need_backup and lv_errfile to be set"
		exit program 99
	end if

	if lv_errfile then
		# We might be editing the error file 
		# but we still want to backup the original .4gl...
		let lv_need_backup=true
		let lv_need_to_edit=false
	end if
	

	
	if lv_need_backup then
		# lets make a backup if they've just picked the file...
		# if we we're passed in a filename - then there should already be 
		# a backup...
		let lv_backup=aclfgl_replace_in_string(lv_mname,".4gl",".4bl")

		if file_exists(lv_backup) then
			error "Could not make backup copy of file (",lv_backup clipped," exists)"
			return false
		end if
	
		if file_exists(lv_mname) then
			call copy_file(lv_mname,lv_backup,".4gl",0)
		end if
	else 
		initialize lv_backup to null
	end if


	if lv_initstate is null or lv_initstate=" " then
		if lv_need_to_edit then
			let lv_state="Edit"	
		else
			let lv_state="CorrectExit"
		end if
	else
		let lv_state=lv_initstate
		
	end if
	

	while true
    		CALL display_banner()

		case 
			when lv_state="Edit"
				message " "
				CALL ensure_editor() returning lv_editor
				if lv_editor is null or lv_editor matches " " then
					error "Unable to get EDITOR"
					return FALSE
				end if
				IF module_editfile(lv_mname,FALSE) THEN
					# We dont care about the return code...
				END IF
				if not file_exists(lv_mname) then
					LET lv_state="ExitFalse"
				else
					LET lv_state="ModifyMenu"
					LET lv_next_suggested_state="Compile"
				end if

			when lv_state="Correct"
				message " "
				CALL ensure_editor() returning lv_editor
					if lv_need_backup =false then
                				# lets make a backup if they've just picked the file...
                				# if we we're passed in a filename - then there should already be
                				# a backup...
                				let lv_backup=aclfgl_replace_in_string(lv_mname,".4gl",".4bl")
				
                				if file_exists(lv_backup) then
                        				error "Could not make backup copy of file (",lv_backup clipped," exists)"
                        				return false
                				end if
				
                				if file_exists(lv_mname) then
                        				call copy_file(lv_mname,lv_backup,".4gl",0)
                				end if
						let lv_need_backup=true
					end if

				IF module_editfile(lv_mname,TRUE) THEN
					if copy_err_file_back_v2(lv_mname,"|") then
						LET lv_state="ModifyMenu"
						LET lv_next_suggested_state="Compile"
					else
						error "Something horrid happend - I dont want to talk about it.."
						return false
					end if
				ELSE
					LET lv_state="ModifyMenu"
					LET lv_next_suggested_state="Compile"
				END IF

			when lv_state="ModifyMenu"
    				MENU "Modify Module"
					BEFORE MENU
						if lv_next_suggested_state="Save-and-exit" then
							next option "Save-and-exit"
						end if
						if lv_next_suggested_state="Compile" then
							next option "Compile"
						end if

      					COMMAND KEY "c" "Compile" "Compile the module"
						LET lv_state="Compile"
						EXIT MENU
			
      					COMMAND KEY "s" "Save-and-exit" "Save the module"
						LET lv_state="Save-and-exit"
						message " "
						EXIT MENU


      					COMMAND KEY "d" "Discard-and-exit" "Discard the module"
						LET lv_state="Discard-and-exit"
						message " "
						EXIT MENU
				END MENU


			when lv_state="Save-and-exit"
				LET lv_state="ExitTrue"

      			when lv_state="Compile" 
				menu "Compile Module"
					command "Object" "Compile to an object file"
						let lv_state="CompileObject"
						exit menu

					command "Runable" "Compile to an executable"
						let lv_state="CompileRunable"
						exit menu

					command "Exit" "Return to menu"
						let lv_state="ExitFalse"
						exit menu
				end menu

			when lv_state="CompileObject"
				let mv_generated_exe=false
				call check_program_for_module(lv_mname) returning lv_makefile,lv_objfile
				if lv_makefile = " " or lv_makefile is null then # Couldnt find a real makefile...
					IF module_compile(lv_mname)  then
						let lv_errfile=false
						let lv_next_suggested_state="Save-and-exit"
						if lv_need_backup then
							let lv_state="ModifyMenu"
						else
							let lv_state="ExitTrue"
						end if
					ELSE
						let lv_state="CorrectExit"
					END IF
				else
					display  "Compiling as part of program using  ", lv_makefile clipped at 10,1
					# Use the real makefile
					display " " 
					let lv_runstr="make -f ",lv_makefile clipped," ",lv_objfile
					display "Running : ", lv_runstr clipped
					call run_with_logging( lv_runstr) returning lv_ok

					if lv_ok>255 then 
						let lv_ok=lv_ok/256
					end if

					if lv_ok=0 then # Good!
						let lv_errfile=false
						let lv_next_suggested_state="Save-and-exit"
						if lv_need_backup then
							let lv_state="ModifyMenu"
						else
							let lv_state="ExitTrue"
						end if
					else
						display "Press any key to continue"
						call fgl_getkey() returning lv_ok
						let lv_state="CorrectExit"
					end if
					display  "Compiling as part of program using  ", lv_makefile clipped at 10,1
				end if
	
			when lv_state="CompileRunable"
				let mv_generated_exe=false
				IF module_compile(lv_mname)  then
					let lv_errfile=false
					let lv_state="ModifyMenu"
					let lv_runstr="4glc -o ",remove_ext(lv_mname) clipped,".4ae ", remove_ext(lv_mname),fgl_getenv("A4GL_OBJ_EXT")
					run lv_runstr returning lv_ok

					if lv_ok>255 then
						let lv_ok=lv_ok/256
					end if
					if lv_ok=0 then
						let mv_generated_exe=true
						if lv_need_backup then
							let lv_next_suggested_state="Save-and-exit"
						else
							let lv_state="ExitTrue"
						end if
					else
						message "Some error creating executable"
						let lv_next_suggested_state="Save-and-exit"
					end if

				ELSE
					let lv_state="CorrectExit"
				END IF

	
			when lv_state="CorrectExit"
    				MENU "COMPILE FORM"
      					COMMAND KEY "c" "Correct" "Correct the errors in the module"
						# We need to correct the module..
						let lv_state="Correct"
						exit menu
					COMMAND KEY "e" "Exit" "Exit the compilation"
						let lv_state="ExitFalse"
						exit menu
				end menu
				

    			when lv_state="ExitFalse"
				message " "
    					return FALSE
	
			when lv_state="ExitTrue"
				message " "
					call remove_file(lv_backup)
					return TRUE

      			when lv_state="Discard-and-exit"
				message " "
				call copy_file(lv_backup,lv_mname,".4gl",0)
				LET lv_state="ExitTrue"
		end case
	END WHILE
END FUNCTION





function confirm_drop_module()
    MENU "CONFIRM"
      BEFORE MENU
        CALL display_banner()

      COMMAND KEY "n" "No" "No - I don't want to drop it"
      		RETURN "No"
      COMMAND KEY "y" "Yes" "Yes - I do want to drop it"
      		RETURN "Yes"
    END MENU


end function


FUNCTION module_table_selection()
	    MENU "Generate"
      BEFORE MENU
        CALL display_banner()

      COMMAND KEY "t" "Table selection complete" "Table selection complete"
      	RETURN "Table selection complete"
      COMMAND KEY "s" "Select more" "Select more"
      	RETURN "Select more"
      COMMAND KEY "e" "Exit" "Exit"
      	RETURN "Exit"
    END MENU


END FUNCTION




################################################################################
function module_menu_compile()
define lv_mname char(255)
define lv_ok integer

let lv_mname=get_filename_to("compile",".4gl",mv_lastused)
if lv_mname is null or lv_mname matches " " then
	return false
end if

let mv_lastused=remove_ext(lv_mname)
return  modify_module(lv_mname,FALSE, "Compile")

end function


function module_compile(lv_mname)
define lv_mname char(255)
define a integer
define lv_runstr char(512)
define lv_backup char(255)


if lv_mname not matches "*.4[Gg][Ll]" then
       	let lv_mname=lv_mname clipped,".4gl"
end if

let lv_runstr=fgl_getenv("AUBITDIR") clipped,"/bin/4glc -c ",lv_mname clipped
run lv_runstr returning a
if a>255 then
	let a=a/256
end if

if a=0 then
	message "The module was successfully compiled." 
	return true
else
	message "The module did not compile successfully"
end if
end function

################################################################################
function new_module()
define lv_mname char(255)
define lv_ok integer


	let int_flag=false
	let lv_mname=prompt_get("Module name >>","Enter the module name")

	if int_flag=true or lv_mname is null or lv_mname matches " " then
		return false
	else
		if lv_mname matches "*.4[Gg][Ll]" then
		else
			let lv_mname=lv_mname clipped,".4gl"
			if file_exists(lv_mname) then
				error "A module already exists with that name"
				return
			end if
		end if
		call modify_module(lv_mname,FALSE,"") returning lv_ok
	end if
	return lv_ok

end function


################################################################################
function drop_module()
define lv_mname char(255)
define lv_mname_obj char(255)
define lv_mname_4gl char(255)
define lv_mname_ec char(255)
define lv_mname_c char(255)
define a integer
display "Choose a file to drop","" at 2,1
code
{
    char **dir;
    dir=A4GL_read_directory(".",".4gl");
    if (dir) {
        for (a=0;dir[a];a++) {
            strcpy(lv_mname,dir[a]);
endcode
            call set_pick(a+1,lv_mname);
code
        }
    A4GL_free_directory(dir);
    }
}
endcode

call set_pick_cnt(a);
call set_picked_option(mv_lastused)

call prompt_pick("DROP >> ","") returning lv_mname

if lv_mname is not null then
     let lv_mname_4gl=lv_mname clipped,".4gl"
     let lv_mname_obj=lv_mname clipped,fgl_getenv("A4GL_OBJ_EXT")
     if fgl_getenv("A4GL_LEXTYPE")="EC" then
	let lv_mname_ec=lv_mname clipped,".ec"
	if fgl_getenv("A4GL_LEXDIALECT")="POSTGRES" then
		let lv_mname_ec=lv_mname clipped,".cpc"
	end if
     else
	let lv_mname_c=lv_mname clipped,".c"

     end if

	
     let lv_mname_obj=lv_mname clipped,fgl_getenv("A4GL_OBJ_EXT")
     let lv_mname_obj=lv_mname clipped,fgl_getenv("A4GL_OBJ_EXT")
     if confirm_drop_module()="Yes" then
code
        A4GL_trim(lv_mname_4gl);
        A4GL_trim(lv_mname_obj);
	A4GL_trim(lv_mname_ec);
	A4GL_trim(lv_mname_c);
	
        unlink(lv_mname_4gl);
        unlink(lv_mname_obj);
	if (strlen(lv_mname_ec)) unlink(lv_mname_ec);
	if (strlen(lv_mname_c)) unlink(lv_mname_c);
endcode
	end if
end if

end function



#
# Returns True if we need to copy over the errfile
# if we dont want to copy back the errfile returns false
# eg - if we dont have an errfile - or its missing
# 
function module_editfile(lv_mname,lv_errfile)
define lv_mname char(256)
define lv_errfile integer
define lv_runstr char(512)
define a integer
define lv_editor char(512)
define lv_ename char(512)
define lv_copyerrfile integer


                if lv_errfile then
                        if lv_mname matches "*.4[Gg][Ll]" then
                                let lv_ename=lv_mname[1,length(lv_mname)-3],"err"
				if file_exists(lv_ename) then
					let lv_mname=lv_ename
					let lv_copyerrfile=true
				else
					error "Cant see an error file - please manually review any .c.err or .ec.err etc"
					let lv_errfile=FALSE
					let lv_copyerrfile=false
				end if
                        else
                                error "Expecting filename to end with .4gl at this point"
		
                                exit program 99
                        end if
                else
			let lv_copyerrfile=false
                        let mv_lastused=lv_mname
                end if

		let lv_runstr="NOTSET"

		call ensure_editor() returning lv_editor
		if lv_errfile then
			if lv_editor="vi" or lv_editor="vim" or lv_editor="elvis" then
                		let lv_runstr=lv_editor clipped, " +'/^|/' ",lv_mname
			end if
		end if


		if lv_runstr is null or lv_runstr="NOTSET" then
              		let lv_runstr=lv_editor clipped, " ",lv_mname
		end if

                run lv_runstr returning a

                if a>255 then
                        let a=a/256
                end if

		return lv_copyerrfile

end function



##
# This function checks to see where a module is used
# (if at all)
# We do this so we can make sure we use the right 'makefile'
# or compile from the command line as required
##
function check_program_for_module(lv_mname)
define lv_mname char(256)
define lv_cwd char(256)
define lv_cnt integer
define lv_prog char(16),lv_user char(8)
define lv_last_used_prog char(16)
define lv_have_last_used integer

let lv_cnt=1

# Make sure we dont have any extensions
let lv_mname=remove_ext(lv_mname) 
let lv_cwd=aclfgl_getcwd()
let lv_last_used_prog=get_last_used_program()

call ensure_syspgma4gl()

declare c_chk_prog cursor for 
	select progname
	from entity where entity_type in ("M","G") 
	and (flags matches " " or flags is null or flags=lv_cwd)
	and (justuser is null or justuser matches " " or justuser=user)
	and name=lv_mname
	order by progname

let lv_have_last_used=false
foreach c_chk_prog into lv_prog
	call set_pick(lv_cnt,lv_prog)
	let lv_cnt=lv_cnt+1
	if lv_prog=lv_last_used_prog then
		let lv_have_last_used=true
	end if
end foreach

let lv_cnt=lv_cnt-1

if lv_cnt=0 then
	# No programs were found - compile from command line
	return " ", " "
end if

if lv_cnt=1 then
	return get_makefile_for(lv_prog), get_object_file_for(lv_last_used_prog,lv_mname)
end if

if lv_cnt>1 then
	if lv_have_last_used then
		return get_makefile_for(lv_last_used_prog),get_object_file_for(lv_last_used_prog,lv_mname)
	end if
end if

call set_pick_cnt(lv_cnt)

let lv_prog=prompt_pick("Program >> ","") 
if lv_prog is not null and lv_prog != " " then
	call set_last_used_program(lv_prog)
	return get_makefile_for(lv_prog),get_object_file_for(lv_prog,lv_mname)
end if

# No program select - just compile at command line
return " "," "
end function


function get_object_file_for(lv_prog,lv_mname)
define lv_prog char(16)
define lv_mname char(256)
define lv_builddir char(512)
define lv_objext char(10)

call ensure_syspgma4gl()

select progoutdir into lv_builddir 
from program
where progname=lv_prog
and (justuser is null or justuser matches " " or justuser=user)

if sqlca.sqlcode=100 then
	# Its a .mk
	return remove_ext(lv_mname),fgl_getenv("A4GL_OBJ_EXT")
end if

if lv_builddir is not null and lv_builddir != " " then
	let lv_objext= get_setting(lv_prog,"A4GL_OBJ_EXT")
	if lv_objext is null or lv_objext matches " " then
		let lv_objext=fgl_getenv("A4GL_OBJ_EXT")
	end if
	return lv_builddir clipped, "/", remove_ext(lv_mname) clipped, lv_objext
end if

end function




function get_makefile_for(lv_prog)
define lv_prog char(16)
define lv_progoutdir, lv_progmakefile char(256)
define lv_makefile char(512)
define lv_genmakefile 	integer
define lv_lastupd 	integer
define lv_filetime integer
call ensure_syspgma4gl()

select progoutdir, progmakefile,genmakefile , lastupd
into  lv_progoutdir, lv_progmakefile,lv_genmakefile,lv_lastupd
from program 
where progname=lv_prog
and (justuser is null or justuser matches " " or justuser=user)

if sqlca.sqlcode=100 then
	return lv_prog clipped || ".mk"
end if

if lv_progoutdir is null or lv_progoutdir matches " " then
	let lv_progoutdir="./"
end if

if lv_progmakefile is null or lv_progmakefile matches " " then
	let lv_progmakefile=lv_prog clipped,".mk"
end if

if lv_lastupd is null then
	let lv_lastupd=0
end if

if lv_genmakefile is null then
	let lv_genmakefile=0
end if

let lv_makefile=lv_progoutdir clipped,lv_progmakefile

if file_exists(lv_makefile) then
	#
	# Ok - we've got a makefile
	#
	# Has the project description changed since the 
	# makefile was last modified ? 
	#
	let lv_filetime=get_file_time(lv_makefile)
	
	if lv_lastupd>lv_filetime then
		if lv_genmakefile<lv_filetime then
			open window w_warn at 10,5 with 6 rows, 70 columns attribute (border,menu line 2)
	
			 #       1234567890123456789012345678901234567890123456789012345678901234567890
			display "   Makefile has been changed outside of a4gl IDE  (not overwriting)   " at 1,1 attribute (reverse,cyan)
			#
			display "lv_lastupd=",lv_lastupd," lv_filetime=",lv_filetime," lv_genmakefile=", lv_genmakefile at 4,1
			display "The project has been updated since the makefile was last changed." at 5,1
			display "You can 'touch' the makefile to remove this warning in future    " at 6,1

			menu "Continue" 
				command "Reset" "Ignore the error by using the Makefiles timestamp "
					update program 
					set (lastupd, genmakefile)=(lv_filetime ,lv_filetime)
					where progname=lv_prog
					and (justuser is null or justuser matches " " or justuser=user)
					exit menu

				command "Overwrite makefile" "Regenerate the makefile and remove any changes"
					call generate_makefile(lv_prog,lv_makefile)
					exit menu

				command "Ignore Once" "Igore this time only"
					exit menu
			end menu
			close window w_warn
		else
			call generate_makefile(lv_prog,lv_makefile)
		end if

		#let lv_filetime=get_file_time(lv_makefile)
		#update program set genmakefile=lv_filetime 
		#where progname=lv_prog
		#and (justuser is null or justuser matches " " or justuser=user)

	else
		# Its already up to date..
	end if
else
	# File doesn't exist at all - so generate it.
	call generate_makefile(lv_prog,lv_makefile)
end if
return lv_makefile
end function

function touch(lv_fname)
define lv_fname char(512)
	run "touch "||lv_fname clipped
end function



