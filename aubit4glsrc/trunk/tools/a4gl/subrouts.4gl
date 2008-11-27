define mv_editor_master char(255)


function ensure_editor()
	if mv_editor_master is null then
		let mv_editor_master=fgl_getenv("DBEDIT") 
	end if
	if mv_editor_master is null or mv_editor_master=" " then
		let mv_editor_master=prompt_get("Editor ?","Please enter the editor you wish to use")
	end if

	return mv_editor_master
end function



function get_filename_to(lv_what,lv_ext,lv_lastused)
define lv_fname char(255)
define lv_what char (20)
define lv_ext char(4)
define a integer
define lv_lastused char(255)
define lv_say char(80)

let lv_lastused=remove_ext(lv_lastused)
case lv_what
	when "modify" 
		let lv_say="Choose a file to modify"
	when "compile" 
		let lv_say="Choose a file to compile"
	when "run" 
		let lv_say="Choose a file to run"
	otherwise
		display "Internal error : Unexpected ", lv_what
		exit program 4
end case

let a=0
code
{
    char **dir;
    dir=A4GL_read_directory(".",lv_ext);
    if (dir) {
        for (a=0;dir[a];a++) {
            A4GL_debug("READ FILE: %s",dir[a]);
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
call set_picked_option(lv_lastused)
#message "lv_lastused=", lv_lastused sleep 4
call prompt_pick_and_say("CHOOSE >> ","",lv_say) returning lv_fname
return lv_fname
end function

