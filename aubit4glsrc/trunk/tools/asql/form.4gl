define mv_lastform char(255)
define mv_editor char(255)
define mv_db char(255)

define mv_lastused char(255)


function form_menu_run()
call run_form("")
end function

function form_menu_modify()
	if modify_form("") then
		message ""
	else
		message ""
	end if
end function


function form_menu_generate()
    if not has_db() then 
		call select_db() 
	end if 
		
	let mv_db=get_db()

	if mv_db is null or mv_db matches " " then
	else
		if generate_form() then
			message ""
			return 1
		end if
	end if
	return 0
end function

################################################################################
function form_menu()
define lv_option integer

	if mv_editor is null then
		let mv_editor=fgl_getenv("DBEDIT") 
	end if

  	call clear_screen_portion()
	call init_filename()

	while true
		
		case form_menu_int(lv_option)
			when "Run" 
				call form_menu_run()
				let lv_option=0
		
			when "Modify" 
				call form_menu_modify()
				let lv_option=1
			
			when "Generate" 
				if form_menu_generate() then
					let lv_option=0
				else
					let lv_option=2
				end if
	
			when "New" 
				call new_form()
				let lv_option=3
		
			when "Compile" 
				if compile_form("") then
					let lv_option=0 # NEXT OPTION "Run"
				else
					let lv_option=4
				end if
	
			when "Drop" 
				let lv_option=5
				call drop_form()
		
			when "Exit" 
				exit while
		end case
	end while

end function



################################################################################
function run_form(lv_ofname)
define lv_ofname char(255)
define lv_fname char(255)
define lv_runstr char(512)
define a integer
define lv_ext char(255)

let lv_ext=work_out_ext()
call display_banner()
display "Choose a file to run","" at 2,1

code
{
    char **dir;
	A4GL_trim(lv_ext);
    dir=A4GL_read_directory(".",lv_ext);
    if (dir) {
        for (a=0;dir[a];a++) {
            strcpy(lv_fname,dir[a]);
endcode
            call set_pick(a+1,lv_fname);
code
        }
        A4GL_free_directory(dir);
   }
}
endcode

call set_pick_cnt(a);

if lv_ofname is null or lv_ofname matches " " then
	#error "SET PICK 1:",mv_lastused
	call set_picked_option(mv_lastused)
else
	#error "SET PICK 2:",lv_ofname
	call set_picked_option(lv_ofname)
end if
sleep 1

call prompt_pick("RUN >> ","") returning lv_fname

if lv_fname is not null then
	let lv_runstr=fgl_getenv("RUNFORMS")
	if lv_runstr is null or lv_runstr matches " " then
		LET lv_runstr=fgl_getenv("AUBITDIR") clipped,"/bin/runforms", fgl_getenv("A4GL_EXE_EXT");
	end if
	LET lv_runstr=lv_runstr clipped," ",lv_fname

	let mv_lastused=lv_fname

	run lv_runstr clipped

end if

end function


################################################################################
function modify_form(lv_fname)
define lv_fname char(255)
define a integer
define lv_runstr char(512)
define lv_backup char(255)

if lv_fname is null or lv_fname matches "" then
	display "Choose a file to modify","" at 2,1

	let a=0
code
{
    char **dir;
    dir=A4GL_read_directory(".",".per");
    if (dir) {
        for (a=0;dir[a];a++) {
            A4GL_debug("READ FILE: %s",dir[a]);
            strcpy(lv_fname,dir[a]);
endcode
            call set_pick(a+1,lv_fname);
code
        }
        A4GL_free_directory(dir);
    }
}
endcode

	call set_pick_cnt(a);
	call prompt_pick("CHOOSE >> ","") returning lv_fname
end if

if lv_fname is not null then
	let lv_backup=get_tmp_fname("PER")
	call copy_file(lv_fname,lv_backup,".per",0)

	if lv_fname not matches "*.[Pp][Ee][Rr]" then
        	let lv_fname=lv_fname clipped,".per"
	end if

	if mv_editor is null or mv_editor=" " then
		let mv_editor=prompt_get("Editor ?","Please enter the editor you wish to use")
	end if

	if mv_editor is null or mv_editor=" " then
		return 0
	end if

	let lv_runstr=mv_editor clipped, " ",lv_fname
	run lv_runstr returning a

	let a=a/256

	if a=0 then
		display "OK " at 24,1
	else
		display "Bad" at 24,1
	end if


	let mv_lastused=lv_fname

	case modify_compile()

		when "Compile" 
			return compile_form(lv_fname) 

		when "Save-and-exit" 
			call remove_tmp_files("PER")
			return 1

		when "Discard-and-exit"
			call copy_file(lv_backup,lv_fname,".per",0)
			return 1
	end case
	return 1
end if

return 0
end function


################################################################################
function compile_form(lv_fname)
define lv_fname char(255)
define a integer
define lv_runstr char(512)
define lv_backup char(255)

if lv_fname is null or lv_fname matches " " then
	display "Choose a file to compile","" at 2,1
	let a=0

code
{
    char **dir;
    dir=A4GL_read_directory(".",".per");
    if (dir) {
        for (a=0;dir[a];a++) {
            A4GL_debug("READ FILE: %s",dir[a]);
            strcpy(lv_fname,dir[a]);
endcode
            call set_pick(a+1,lv_fname);
code
        }
        A4GL_free_directory(dir);
    }
}
endcode

	call set_pick_cnt(a);
	call prompt_pick("CHOOSE >> ","") returning lv_fname
end if

if lv_fname is null or lv_fname matches " " then
	return 0
end if


if lv_fname is not null then
	let mv_lastused=lv_fname
	let lv_backup=get_tmp_fname("PER")
	call copy_file(lv_fname,lv_backup,".per",0)

	if lv_fname not matches "*.[Pp][Ee][Rr]" then
        	let lv_fname=lv_fname clipped,".per"
	end if

	let lv_runstr=fgl_getenv("AUBITDIR") clipped,"/bin/fcompile ",lv_fname
	run lv_runstr returning a

	let a=a/256

	if a=0 then
		display "The screen form specification was successfully compiled." at 24,1 attribute(reverse)
		return 1
	else
		case correct_compile_form()
			when "Correct" return modify_form(lv_fname)
			when "Exit" return 0
		end case
	end if
end if
return 0
end function

################################################################################
function generate_form()
define lv_form char(255)
define lv_tables array[20] of char(255)
define lv_cnt integer
define lv_tabname char(200)
define lv_runstr char(2048)
define lv_i integer

let int_flag=false

initialize lv_form to null
if has_prompt_action() then
	let lv_form=get_prompt_action()
end if

if lv_form = "" or lv_form is null then
	let lv_form=prompt_get("Generate Form >>","Enter the formname you which to generate")
	#prompt "Generate Form > " for lv_form
end if

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

let lv_runstr=fgl_getenv("AUBITDIR") clipped,
              "/bin/default_frm -d ", mv_db 
for lv_i = 1 to lv_cnt
    let lv_runstr = lv_runstr clipped, " -t ", lv_tables[lv_i] 
end for
let lv_runstr = lv_runstr clipped, " -o ", lv_form
#display lv_runstr)
run lv_runstr

let mv_lastused=lv_form
return true
end function

################################################################################
function new_form()
define lv_fname char(255)
	let int_flag=false
	let lv_fname=prompt_get("Form name >>","Enter the formname")
	#prompt "Form name >>" for lv_fname

	if int_flag=true or lv_fname is null or lv_fname matches " " then
		return
	else
		call modify_form(lv_fname)
	end if

end function


################################################################################
function drop_form()
define lv_fname char(255)
define lv_fname_frm char(255)
define lv_fname_per char(255)
define a integer
display "Choose a file to drop","" at 2,1
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
    A4GL_free_directory(dir);
    }
}
endcode

call set_pick_cnt(a);

call prompt_pick("DROP >> ","") returning lv_fname

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
