define mv_db char(255)

define mv_lastused char(255)



function form_generate()
    if not has_db() then 
		call select_db() 
	end if 
		
	let mv_db=get_db()

	if mv_db is null or mv_db matches " " then
	else
		if generate_form() then
			message ""
			return TRUE
		end if
	end if
	return FALSE
end function

################################################################################
function form_menu()
define lv_ok integer


  	call clear_screen_portion()
	call init_filename()


		MENU "Form"
			command "Modify" "Modify an existing form"
				call modify_form("",FALSE)  RETURNING lv_ok
			
			command "Generate" "Generate a new form"
				call form_generate()  returning lv_ok
	
			command "New" "Create a new empty form"
				call new_form()
		
			command "Compile" "Compile a form"
				call form_menu_compile() 
	
			command "Drop"  "Delete a form"
				call drop_form()
		
			command "Exit"  "Return to main menu"
				exit menu
		end menu

end function



################################################################################
function modify_form(lv_fname,lv_errfile)
define lv_fname char(255)
define lv_backup char(255)
define lv_errfile integer
define lv_need_backup integer
define lv_need_to_edit integer

define lv_state char(30)
define lv_next_suggested_state char(30)
define lv_editor char(255)

	let lv_need_to_edit=true
	let lv_need_backup=false

	if lv_fname is null or lv_fname matches "" then
		let lv_fname=get_filename_to("modify",".per",mv_lastused)
		let lv_need_backup=true
		if lv_fname is null or lv_fname = " " then
			return false
		end if
	end if
	
	
	
	if lv_fname not matches "*.[Pp][Ee][Rr]" then
       		let lv_fname=lv_fname clipped,".per"
	end if
	
	if lv_need_backup and lv_errfile then
		error "Internal error - not expecting both lv_need_backup and lv_errfile to be set"
		exit program 99
	end if

	if lv_errfile then
		# We might be editing the error file 
		# but we still want to backup the original .per...
		let lv_need_backup=true
		let lv_need_to_edit=false
	end if
	

	
	if lv_need_backup then
		# lets make a backup if they've just picked the file...
		# if we we're passed in a filename - then there should already be 
		# a backup...
		let lv_backup=aclfgl_replace_in_string(lv_fname,".per",".pbr")

		if file_exists(lv_backup) then
			error "Could not make backup copy of file (",lv_backup clipped," exists)"
			return false
		end if
	
		if file_exists(lv_fname) then
			call copy_file(lv_fname,lv_backup,".per",0)
		end if
	else 
		initialize lv_backup to null
	end if


	if lv_need_to_edit then
		let lv_state="Edit"	
	else
		let lv_state="CorrectExit"
	end if
	

	while true
    		CALL display_banner()

		case lv_state
			when "Edit"
				message " "
				CALL ensure_editor() returning lv_editor
				if lv_editor is null or lv_editor matches " " then
					error "Unable to get EDITOR"
					return FALSE
				end if
				IF form_editfile(lv_fname,FALSE) THEN
					# We dont care about the return code...
				END IF
				if not file_exists(lv_fname) then
					LET lv_state="ExitFalse"
				else
					LET lv_state="ModifyMenu"
					LET lv_next_suggested_state="Compile"
				end if

			when "Correct"
				message " "
				CALL ensure_editor() returning lv_editor
				if lv_need_backup=false then
					let lv_need_backup=true
				                let lv_backup=aclfgl_replace_in_string(lv_fname,".per",".pbr")
                			if file_exists(lv_backup) then
                        			error "Could not make backup copy of file (",lv_backup clipped," exists)"
                        			return false
                			end if
			
                			if file_exists(lv_fname) then
                        			call copy_file(lv_fname,lv_backup,".per",0)
                			end if
				end if



				IF form_editfile(lv_fname,TRUE) THEN
					# We dont care about the return code...
				END IF

				if copy_err_file_back_v2(lv_fname,"|") then
					LET lv_state="ModifyMenu"
					LET lv_next_suggested_state="Compile"
				else
					error "Something horrid happend - I dont want to talk about it.."
					return false
				end if

			when "ModifyMenu"
    				MENU "Modify Form"
					BEFORE MENU
						if lv_next_suggested_state="Save-and-exit" then
							next option "Save-and-exit"
						end if
						if lv_next_suggested_state="Compile" then
							next option "Compile"
						end if

      					COMMAND KEY "c" "Compile" "Compile the form"
						LET lv_state="Compile"
						EXIT MENU
			
      					COMMAND KEY "s" "Save-and-exit" "Save the form"
						LET lv_state="Save-and-exit"
						message " "
						EXIT MENU


      					COMMAND KEY "d" "Discard-and-exit" "Discard the form"
						LET lv_state="Discard-and-exit"
						message " "
						EXIT MENU
				END MENU


			when "Save-and-exit"
				LET lv_state="ExitTrue"

      			when "Compile" 
				IF form_compile(lv_fname)  then
					let lv_errfile=false
					let lv_state="ModifyMenu"
					let lv_next_suggested_state="Save-and-exit"
				ELSE
					let lv_state="CorrectExit"
				END IF

	
			when "CorrectExit"
    				MENU "COMPILE FORM"
      					COMMAND KEY "c" "Correct" "Correct the errors in the form"
						# We need to correct the form..
						let lv_state="Correct"
						exit menu
					COMMAND KEY "e" "Exit" "Exit the compilation"
						let lv_state="ExitFalse"
						exit menu
				end menu
				

    			when "ExitFalse"
				message " "
    					return FALSE
	
			when "ExitTrue"
				message " "
					call remove_file(lv_backup)
					return TRUE

      			when "Discard-and-exit"
				message " "
				call copy_file(lv_backup,lv_fname,".per",0)
				LET lv_state="ExitTrue"
		end case
	END WHILE
END FUNCTION





function confirm_drop_form()
    MENU "CONFIRM"
      BEFORE MENU
        CALL display_banner()

      COMMAND KEY "n" "No" "No - I don't want to drop it"
      		RETURN "No"
      COMMAND KEY "y" "Yes" "Yes - I do want to drop it"
      		RETURN "Yes"
    END MENU


end function


FUNCTION form_table_selection()
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
function form_menu_compile()
define lv_fname char(255)
define lv_ok integer

let lv_fname=get_filename_to("compile",".per",mv_lastused)
if lv_fname is null or lv_fname matches " " then
	return
end if

let mv_lastused=remove_ext(lv_fname)

if form_compile(lv_fname) then
	return 
else
	call modify_form(lv_fname,TRUE) returning lv_ok
end if

end function


function form_compile(lv_fname)
define lv_fname char(255)
define a integer
define lv_runstr char(512)


if lv_fname not matches "*.[Pp][Ee][Rr]" then
       	let lv_fname=lv_fname clipped,".per"
end if

let lv_runstr=fgl_getenv("AUBITDIR") clipped,"/bin/fcompile -s ",lv_fname clipped
run lv_runstr returning a
if a>255 then
	let a=a/256
end if

if a=0 then
	message "The screen form specification was successfully compiled." 
	return true
else
	message "Form did not compile successfully"
	return false
end if
end function

################################################################################
function generate_form()
define lv_form char(255)
define lv_tables array[20] of char(255)
define lv_cnt integer
define lv_tabname char(200)
define lv_runstr char(2048)
define lv_i integer
define lv_height integer
define lv_ok integer

let int_flag=false

initialize lv_form to null

let lv_form=prompt_get("Generate Form >>","Enter the formname you which to generate")

if int_flag then
	return false
end if
if file_exists(lv_form clipped||".per") then
	error "A form with that name already exists"
	return false
end if
let lv_cnt=0
while true
	let int_flag=false
	let lv_cnt=lv_cnt+1
    call table_select("SELECT TABLE >>") returning lv_tabname
    if lv_tabname is not null and lv_tabname not matches " " THEN
    else
        let int_flag=true
    end if
	if int_flag then
		if lv_cnt=1 then
			return false
		else
			exit while
		end if
	end if
	let lv_tables[lv_cnt]=lv_tabname
	case form_table_selection()
		when "Table selection complete" exit while
		when "Select more" exit while
		when "Exit" return false
	end case
end while
let lv_runstr=fgl_getenv("AUBITDIR") clipped, "/bin/default_frm -d ", mv_db 
for lv_i = 1 to lv_cnt
    let lv_runstr = lv_runstr clipped, " -t ", lv_tables[lv_i] 
end for
let lv_runstr = lv_runstr clipped, " -o ", lv_form
code
lv_height = A4GL_get_curr_height();
endcode
if lv_height <> 0 then
    let lv_runstr = lv_runstr clipped, " -l ", lv_height - 3
end if

run lv_runstr returning lv_ok

if lv_ok>255 then
	let lv_ok=lv_ok/256
end if

if lv_ok=0 then
	message "Form generated ok"
	if form_compile(lv_form) then
		let mv_lastused=lv_form
		return true
	end if
else
	error "Error generating form"
end if


let mv_lastused=lv_form
return true
end function

################################################################################
function new_form()
define lv_fname char(255)
define lv_ok integer


	let int_flag=false
	let lv_fname=prompt_get("Form name >>","Enter the formname")

	if int_flag=true or lv_fname is null or lv_fname matches " " then
		return
	else
		if lv_fname matches "*.[Pp][Ee][Rr]" then
		else
			let lv_fname=lv_fname clipped,".per"
			if file_exists(lv_fname) then
				error "A form already exists with that name"
				return
			end if
		end if
		call modify_form(lv_fname,FALSE) returning lv_ok
	end if

end function


################################################################################
function drop_form()
define lv_fname char(255)
define lv_fname_frm char(255)
define lv_fname_per char(255)
define a integer
#display "Choose a file to drop","" at 2,1
code
{
    char **dir;
    dir=A4GL_read_directory(".",".per");
    if (dir) {
        for (a=0;dir[a];a++) {
            strcpy(lv_fname,dir[a]);
endcode
            call set_pick(a+1,lv_fname);
code
        }
    A4GL_free_directory();
    }
}
endcode

call set_pick_cnt(a);
call set_picked_option(mv_lastused)

call prompt_pick_and_say("DROP >> ","", "Choose a file to drop") returning lv_fname

if lv_fname is not null then
    let lv_fname_per=lv_fname clipped,".per"
    let lv_fname_frm=lv_fname clipped,work_out_ext()

	if confirm_drop_form()="Yes" then
code
        A4GL_trim(lv_fname_per);
        A4GL_trim(lv_fname_frm);
        unlink(lv_fname_per);
        unlink(lv_fname_frm);
endcode
	end if
end if

end function

function work_out_ext()
define lv_formtype char(255)
define lv_packer char(255)
define lv_ext char(255)

let lv_ext=".frm"

let lv_formtype=fgl_getenv("A4GL_FORMTYPE")

if lv_formtype is null or lv_formtype matches " " then
	let lv_formtype=fgl_getenv("FORMTYPE")
end if

if lv_formtype="GENERIC" THEN
	let lv_packer=fgl_getenv("A4GL_PACKER")

	if lv_packer is null or lv_packer matches " " then
		let lv_packer=fgl_getenv("PACKER")
	end if

	case lv_packer
		when "PACKED" 		let lv_ext=fgl_getenv("A4GL_FRM_BASE_EXT") clipped,fgl_getenv("A4GL_PACKED_EXT")
		when "GZPACKED" 	let lv_ext=fgl_getenv("A4GL_FRM_BASE_EXT") clipped,fgl_getenv("A4GL_PACKED_EXT")
		when "XML" 		let lv_ext=fgl_getenv("A4GL_FRM_BASE_EXT") clipped,fgl_getenv("A4GL_XML_EXT")
	end case
else
	# Assume XDR or compatible
	let lv_ext=fgl_getenv("A4GL_FRM_BASE_EXT")
end if

return lv_ext clipped

end function




function form_editfile(lv_fname,lv_errfile)
define lv_fname char(256)
define lv_errfile integer
define lv_runstr char(512)
define a integer
define lv_editor char(255)
                if lv_errfile then
                        if lv_fname matches "*.[Pp][Ee][Rr]" then
                                let lv_fname=lv_fname[1,length(lv_fname)-3],"err"
                        else
                                error "Expecting filename to end with .per at this point"
                                exit program 99
                        end if
                else
                        let mv_lastused=lv_fname
                end if

		let lv_runstr="NOTSET"

		call ensure_editor() returning lv_editor
		if lv_errfile then
			if lv_editor="vi" or lv_editor="vim" or lv_editor="elvis" then
                		let lv_runstr=lv_editor clipped, " +'/^|/' ",lv_fname
			end if
		end if


		if lv_runstr is null or lv_runstr="NOTSET" then
              		let lv_runstr=lv_editor clipped, " ",lv_fname
		end if

                run lv_runstr returning a

                if a>255 then
                        let a=a/256
                end if

                if a=0 then
			return TRUE
                else
			return FALSE
                        ## bad return code from editor - do we care ?
                end if

end function





