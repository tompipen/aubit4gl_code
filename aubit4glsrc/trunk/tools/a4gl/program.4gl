define mv_lastused char(256)
define lv_prog_cnt integer
define lv_dynamically_found_libs array[100] of char(32)
define lv_dynamically_found_libs_cnt integer


################################################################################
function program_menu()
call display_banner()

menu "PROGRAM"
	command "Modify"  "Modify a program definition"
		# List from db only
        message ""
		call program_modify()

	command "New"   "Create a new program definition"
        message ""
		call program_new()

	command "Compile" "Compile a program from a makefile"
		# List from db + makefiles
        message ""
		call program_compile()

	command "Run"  "Run a program"
		# *.4ae
        message ""
		call program_run()

	command "Generate"  "Explicitly generate the makefile (should happen automatically)"
		# *.4ae
        message ""
		call program_generate_makefile()


	command "Undefine" "Remove the definition for this program from the database"
		# List from db only
        message ""
		call program_remove()

	command "Exit" "Return to the main menu"
		if get_db()==get_syspgma4gl_dbname() then
			close database
			call set_curr_db("")
		end if
		exit menu
end menu

end function



################################################################################
function program_modify()
define lv_name char(128)
define lv_cnt integer
define lv_user char(8)

	call ensure_syspgma4gl()

	call get_program("modify",mv_lastused) returning lv_name

	if lv_name is null then
		return
	end if

	select count(*) into lv_cnt from program 
	where (justuser is null or justuser matches " " or justuser=user)
	and progname=lv_name

	if lv_cnt=0 then
		error "Program not found"
		return
	end if
    call set_last_used_program(lv_name)

	select justuser into lv_user from program 
	where (justuser is null or justuser matches " " or justuser=user)
	and  progname=lv_name

	call maintain_program(lv_name,lv_user)

end function

################################################################################
function program_generate_makefile()
define lv_name char(128)
define lv_cnt integer
define lv_makefile char(512)

	call ensure_syspgma4gl()

	call get_program("generate",mv_lastused) returning lv_name
	if lv_name is null then
		return
	end if
	

	select count(*) into lv_cnt from program 
	where (justuser is null or justuser matches " " or justuser=user)
	and progname=lv_name

	if lv_cnt=0 then
		error "Program not found"
		return
	end if

    call set_last_used_program(lv_name)


	call get_makefile_for(lv_name) returning lv_makefile

	call generate_makefile(lv_name, lv_makefile)
	message "Generated makefile" 

end function



################################################################################
function program_new()
define lv_name char(128)
define lv_cnt integer
define lv_user char(8)
	let lv_name=prompt_get("New Program >>","Enter the program name you which to use")
	call ensure_syspgma4gl()

	select count(*) into lv_cnt from program 
	where (justuser is null or justuser matches " " or justuser=user)
	and progname=lv_name

	if lv_cnt!=0 then
		error "Program already exists!"
		return
	end if

	if program_edit_program(lv_name) then

		select justuser into lv_user from program 
		where (justuser is null or justuser matches " " or justuser=user)
		and  progname=lv_name

        call set_last_used_program(lv_name)

		call maintain_program(lv_name,lv_user)
	end if

end function

################################################################################
function maintain_program(lv_name,lv_user)
define lv_name char(128)
define lv_user char(8)
define lv_ok integer
define lv_expert_mode integer

let lv_expert_mode=false


menu "Maintin Program"
	before menu
		call display_banner()
		if not lv_expert_mode then
			# Cforms are compiled forms
			# which dont need DBPATH to be found.
			# You do need to call the special function 'form_is_compiled' though
			# to let the compiler know its not to look for it in a real file...
			#
			# See a4gl.4gl for an example...
			#
			hide option "cfoRms"
		end if


	command key(f12)  # Expert mode - we may add more later...
		if lv_expert_mode then
			let lv_expert_mode=false
			hide option "cfoRms"
		else
			let lv_expert_mode=true
			show option "cfoRms"
		end if

	command "Program" "Edit program definition"
		call program_edit_program(lv_name) returning lv_ok

	command "Modules" "Edit modules in this program"
		call program_edit_modules(lv_name,lv_user)
	
	command "Globals" "Edit global modules in this program"
		call program_edit_globals(lv_name,lv_user)

	command "Forms"	"Edit list of forms for this program"
		call program_edit_forms(lv_name,lv_user)

	command "cfoRms" "Edit list of forms for this program"
		call edit_program_entity(lv_name, lv_user,"f")

	command "Libraries" "Edit list of libraries for this program"
		call program_edit_libraries(lv_name,lv_user)

	command "C Modules" "Edit list of C modules for this program"
		call edit_program_entity(lv_name, lv_user,"C")

	command key(Q) "esQl/c Modules" "Edit list of EC for this program (Only for A4GL_LEXTYPE=EC)"
		call edit_program_entity(lv_name, lv_user,"E")

	command "Dependencies" "Edit dependencies in this program"
		call program_edit_dependencies(lv_name,lv_user)

	command "Settings" "Edit A4GL settings used for compilation"
		call program_edit_settings(lv_name,lv_user)

	command "Exit"
		exit menu
end menu

end function


################################################################################
# Try to make sure that syspgma4gl is our current database
################################################################################
function ensure_syspgma4gl()
define lv_name char(1000)
	let lv_name=get_syspgma4gl_dbname()
	if has_db()  then
		if get_db()!=get_syspgma4gl_dbname() then
			whenever error continue
			close database
			whenever error stop
			database lv_name
			call set_curr_db(lv_name)
		end if
	else
			database lv_name
			call set_curr_db(lv_name)
	end if
end function


################################################################################
# Add the list of programs from our database to our pick list
################################################################################
function add_programs_from_db()
define lv_prog char(128)

call ensure_syspgma4gl()

declare c_get_prog cursor for
	select  distinct progname from program	
	where (justuser is null or justuser matches " " or justuser=user)
	order by 1

foreach c_get_prog into lv_prog
	if set_pick_dup(lv_prog_cnt,lv_prog) then
		let lv_prog_cnt=lv_prog_cnt+1
	end if
end foreach
end function



################################################################################
# Add the list of program makefiles in our current directory to our pick list
################################################################################
function add_programs_from_dir()
define lv_fname char(255)

code
{
    int a;
    char **dir;
    dir=A4GL_read_directory(".",".mk");
    if (dir) {
        for (a=0;dir[a];a++) {
            A4GL_debug("READ FILE: %s",dir[a]);
            strcpy(lv_fname,dir[a]);
endcode
            if set_pick_dup(lv_prog_cnt,lv_fname) then
		# It wasn't already in the list...
		# this probably means a .mk without a program in the database
	    	let lv_prog_cnt=lv_prog_cnt+1
	    end if
code
        }
        A4GL_free_directory();
    }
}
endcode

if file_exists("Makefile") then
            if set_pick_dup(lv_prog_cnt,"Makefile") then
		let lv_prog_cnt=lv_prog_cnt+1
	    end if
else
	if file_exists("makefile") then
            if set_pick_dup(lv_prog_cnt,"makefile") then
		let lv_prog_cnt=lv_prog_cnt+1
	    end if
	end if
end if

end function



################################################################################
# Edit the program header - or insert one if one doesn't already exist
################################################################################
function program_edit_program(lv_name)
define lv_ok integer
define lv_a record
    progname char(128),
    justuser char(8),
    progoutdir char(256),
    progmakefile char(256),
    linkflags char(70),
    compflags char(70),
    lastupd integer,
    genmakefile integer
end record
define lv_name char(128)
define lv_exists integer


	initialize lv_a.* to null

	call ensure_syspgma4gl()

	select 	progname, justuser, progoutdir, progmakefile, linkflags, 
		compflags , lastupd , genmakefile  
	into lv_a.* 
	from program 
	where (justuser is null or justuser matches " " or justuser=user)
	and  progname=lv_name

	if sqlca.sqlcode=100 then
		let lv_a.progname=lv_name
		let lv_exists=false
	else 
		let lv_exists=true
	end if
	
	
	open window w_program at 5,2 with form "prog"
	let int_flag=false
	input by name lv_a.progname thru lv_a.lastupd without defaults

	if int_flag=false then
		if lv_exists=false then
		{
			delete from afglsettings 
			where (justuser is null or justuser matches " " or justuser=user)
        			and  progname=lv_name

			delete from entity
			where (justuser is null or justuser matches " " or justuser=user)
        			and  progname=lv_name
		}

            let lv_a.genmakefile = 0 {genmakefile timestamp} 
			insert into program values(lv_a.*)
			call add_default_settings(lv_a.progname,lv_a.justuser)
		else
			update program set (   
				justuser,
				progoutdir,
    				progmakefile ,
    				linkflags ,
    				compflags )=(lv_a.justuser thru lv_a.compflags) 
			where progname=lv_a.progname
		end if
	
		call updated_program(lv_a.progname,lv_a.justuser)
		let lv_ok=true
	else 
		let int_flag=false
		let lv_ok=false
	end if

	close window w_program
	return lv_ok
end function




################################################################################
# Set the timestamp on the program so we can compare to the makefile
function updated_program(lv_name,lv_user)
define lv_name char(128)
define lv_user char(8)
define lv_now integer
define lv_makefile char(512)

code
lv_now=time(0);
endcode

update program set lastupd=lv_now where progname=lv_name
	and (justuser is null or justuser matches " " or justuser=lv_user)

call get_makefile_for(lv_name) returning lv_makefile

end function


################################################################################
function set_makefiletimestamp(lv_name,lv_user,lv_makefile)
define lv_name char(128)
define lv_user char(8)
define lv_now integer
define lv_makefile char(256)

code
lv_now=time(0);
endcode

end function



################################################################################
function program_compile()
define lv_name char(128)
define lv_makefile char(512)
define lv_cnt integer
define lv_ok integer


	call ensure_syspgma4gl()

	call get_program("compile",mv_lastused) returning lv_name
	if lv_name is null then
		return
	end if

	select count(*) into lv_cnt from program 
	where (justuser is null or justuser matches " " or justuser=user)
	and progname=lv_name

	initialize lv_makefile to null


	if lv_cnt=0 then
		## Is it an explicit Makefile ? 
		if file_exists(lv_name) then
			let lv_makefile=lv_name	
		else
			error "Program not found"
			return
		end if
	end if

    call set_last_used_program(lv_name)

	{select justuser into lv_user from program 
	where (justuser is null or justuser matches " " or justuser=user)
	and  progname=lv_name}

    message "Compiling ..."

	if lv_makefile is null then
		# If its one of ours - call the 'compile' target...
		call get_makefile_for(lv_name) returning lv_makefile
		call run_with_logging(fgl_getenv("A4GL_MAKE")||" -f "||lv_makefile clipped||" compile ") returning lv_ok
	else
		# Just run the makefile then...
		call run_with_logging(fgl_getenv("A4GL_MAKE")||" -f "||lv_makefile clipped) returning lv_ok
	end if


	#run "make -f "||lv_makefile clipped||" compile " returning lv_ok

	if lv_ok >255 then
		let lv_ok=lv_ok/256
	end if

	if lv_ok=0 then
		message "Program compile succeeded"
	else
		if get_use_form() then
			message "Program failed to compile" Wait for key
		else
			display "Program failed to compile - press return"
			call fgl_getkey() returning lv_ok # some key any key
		end if
	end if
	

end function

################################################################################
function program_run()
define lv_prog char(256)
define lv_ok integer

call get_filename_to("run",fgl_getenv("A4GL_EXE_EXT"),mv_lastused) returning lv_prog

if lv_prog is not null and lv_prog not matches " " then
	let mv_lastused=lv_prog
	if lv_prog not matches "*"||fgl_getenv("A4GL_EXE_EXT") then
		let lv_prog=lv_prog clipped,fgl_getenv("A4GL_EXE_EXT")
	end if
	display " " # goto line mode
	run lv_prog

	if get_use_form() then
		message "Program has finished execution" wait for key
	else
		display "Press return to continue"
		call fgl_getkey() returning lv_ok
	end if

end if

end function

################################################################################
function program_remove()
	error "Not implemented yet"
end function



################################################################################
# get a program name from a pick list
################################################################################
function get_program(lv_what,lv_lastused)
define lv_fname char(255)
define lv_what char (20)
define lv_lastused char(255)
define lv_say char(80)

let lv_lastused=remove_ext(lv_lastused) clipped

case lv_what

        when "modify"
		let lv_prog_cnt=1
		
                let lv_say="Choose a program to modify"
		call add_programs_from_db()
		let lv_prog_cnt=lv_prog_cnt-1
		call set_pick_cnt(lv_prog_cnt);

        when "generate"
		let lv_prog_cnt=1
                let lv_say="Choose a program to generate a makefile for"
		call add_programs_from_db()
		let lv_prog_cnt=lv_prog_cnt-1
		call set_pick_cnt(lv_prog_cnt);

        when "compile"
		let lv_prog_cnt=1
                let lv_say="Choose a program to compile"
		# we'll get programs from the database
		# and from the cwd (ending in .mk)
		call add_programs_from_db()
		call add_programs_from_dir()
		let lv_prog_cnt=lv_prog_cnt-1
		call set_pick_cnt(lv_prog_cnt);
		## Because we've taken files from two places
		# we need to sort our picklist...
		call sort_pick()

	when "undefine"
		let lv_prog_cnt=1
                let lv_say="Choose a program to undefine"
		call add_programs_from_db()
		let lv_prog_cnt=lv_prog_cnt-1
		call set_pick_cnt(lv_prog_cnt);

	otherwise
		display "Internal error - not expecting ", lv_what clipped
		exit program 3
end case





call set_picked_option(lv_lastused)
call prompt_pick_and_say("CHOOSE >> ","",lv_say) returning lv_fname
return lv_fname
end function





################################################################################
function edit_program_entity(lv_name, lv_user, lv_type)
define lv_user char(8)
define lv_name char(128)
define lv_type char(1)
define lv_r array[500] of record 
    entity integer,
    entity_type char(1),
    progname char(128),
    justuser char(8),
    name char(60),
    flags char(60)
end record
define lv_formname char(64)
define a integer

define lv_arr array[500] of record
	name char(60),
	flags char(60)
end record


define lv_cnt integer

declare c_load_entities cursor for
	select  distinct * from entity
	where progname=lv_name and entity_type=lv_type
	and (justuser is null or justuser =" " or justuser=lv_user)
    order by name

let lv_cnt=1 

foreach c_load_entities into lv_r[lv_cnt].*
	let lv_arr[lv_cnt].name  = lv_r[lv_cnt].name
	let lv_arr[lv_cnt].flags = lv_r[lv_cnt].flags
	let lv_cnt=lv_cnt+1
end foreach

let lv_cnt=lv_cnt-1
call set_count(lv_cnt)

let lv_formname="entities"

# Just in case we want a different form : 
case lv_type
	when "M" let lv_formname="entities"
	when "G" let lv_formname="entities"
	when "F" let lv_formname="entities"
	when "L" let lv_formname="entities"
	when "E" let lv_formname="entities"
	when "C" let lv_formname="entities"
end case

open window w_edit_entity at 5,7 with form lv_formname #attribute(border)

call aclfgl_set_display_field_delimiters("  ")
case lv_type
	when "M" display "Module"   to fldname
	when "G" display "Global"   to fldname
	when "F" display "Form"     to fldname
	when "f" display "Form"     to fldname # C Form
	when "L" display "Library"  to fldname
	when "E" display "ESQL/C"   to fldname
	when "C" display "C-Module" to fldname
end case
call aclfgl_set_display_field_delimiters("[]")

let int_flag=false
input array lv_arr without defaults from srec1.*
if int_flag=true then
	let int_flag=false
else
	delete from entity where entity_type=lv_type and progname=lv_name and (justuser is null or justuser =" " or justuser=lv_user)
	and progname=lv_name and (justuser is null or justuser =" " or justuser=lv_user)

	for a=1 to arr_count()
		if lv_arr[a].name is null or lv_arr[a].name matches " " then
			continue for
		end if

		insert into entity values(0,lv_type, lv_name,lv_user, lv_arr[a].name, lv_arr[a].flags)
	end for

	call updated_program(lv_name,lv_user)
end if

close window w_edit_entity 
end function

################################################################################
function program_edit_modules(lv_name,lv_user)
define lv_name char(128)
define lv_user char(8)
	call edit_program_entity(lv_name,lv_user, "M")
end function

################################################################################
function program_edit_globals(lv_name,lv_user)
define lv_name char(128)
define lv_user char(8)
	call edit_program_entity(lv_name,lv_user, "G")
end function

################################################################################
function program_edit_forms(lv_name,lv_user)
define lv_name char(128)
define lv_user char(8)
	call edit_program_entity(lv_name,lv_user, "F")
end function

################################################################################
function program_edit_libraries(lv_name,lv_user)
define lv_name char(128)
define lv_user char(8)
	call edit_program_entity(lv_name, lv_user,"L")
end function

################################################################################
function program_edit_c(lv_name,lv_user)
define lv_name char(128)
define lv_user char(8)
	call edit_program_entity(lv_name, lv_user,"C")
end function
################################################################################
function program_edit_ec(lv_name,lv_user)
define lv_name char(128)
define lv_user char(8)
	call edit_program_entity(lv_name, lv_user,"E")
end function

################################################################################
function program_edit_dependencies(lv_name,lv_user)
define lv_name char(128)
define lv_user char(8)
	error "Not implemented yet"
end function

################################################################################
function program_edit_settings(lv_name,lv_user)
define lv_name char(128)
define lv_user char(8)
define lv_n char(32)
define lv_v char(70)
define lv_arr array[100] of record
	name char(32),
	value char(70)
end record
define lv_cnt integer

open window w_edit_settings at 5,7 with form "settings"

call aclfgl_set_display_field_delimiters("  ")
display "Setting" to fldname
call aclfgl_set_display_field_delimiters("[]")


declare c_load_settings cursor for
	select name,value 
	from afglsettings
	where progname=lv_name
	and (justuser is null or justuser matches " " or justuser=user)
	order by 1
let lv_cnt=1



foreach c_load_settings into lv_n,lv_v
	let lv_arr[lv_cnt].name=lv_n
	let lv_arr[lv_cnt].value=lv_v
	let lv_cnt=lv_cnt+1
end foreach

let lv_cnt=lv_cnt-1

call set_count(lv_cnt-1)
let int_flag=false

input array lv_arr without defaults from srec1.*
if int_flag=true then
	let int_flag=false
else
	delete from afglsettings
        where progname=lv_name
        and (justuser is null or justuser matches " " or justuser=user)
	for lv_cnt=1 to arr_count()
		if lv_arr[lv_cnt].name is not null and lv_arr[lv_cnt].name not matches " " then
			insert into afglsettings values(lv_name, lv_user, lv_arr[lv_cnt].name,lv_arr[lv_cnt].value)
		end if
	end for
	call updated_program(lv_name,lv_user)
end if
close window w_edit_settings

end function


function get_last_used_program()
return mv_lastused
end function

function set_last_used_program(lv_lastused)
define lv_lastused char(128)
let mv_lastused=lv_lastused
end function

function has_setting(lv_prog,lv_name)
define lv_prog char(128)
define lv_name char(32)
define lv_val char(70)

        select value into lv_val 
	from afglsettings
        where (justuser is null or justuser matches " " or justuser=user)
        and progname=lv_prog
	and name=lv_name

	if sqlca.sqlcode=100 then
		return false
	else
		return true
	end if

end function

function add_setting_if_missing(lv_prog,lv_name)
define lv_prog chaR(128)
define lv_name char(32)

if not has_setting(lv_prog,lv_name)  then
	call channel::write("make",lv_name clipped||":=$(shell aubit-config "||lv_name clipped||")")
end if
end function

function is_valid_env_var_char(lv_c) 
define lv_c char(1)
let lv_c=upshift(lv_c)

if lv_c>="A" and lv_c<="Z" then
		return true
end if

if lv_c>="0" and lv_c<="9" then
		return true
end if

if lv_c="_" then return true end if

return false

end function

function replace_env_var_with_make_var(lv_str)
define lv_str char(256)
define lv_newstr char(256)
define a,b integer
define lv_mode integer

let lv_newstr=" "
let a=1
let lv_mode=0

for b=1 to length(lv_str)
   if lv_str[b]="$" and lv_str[b+1]="$" then
	         let lv_newstr[a]=lv_str[b] let a=a+1
	         let lv_newstr[a]=lv_str[b] let a=a+1
            let b=b+1
              continue for
      end if

	if lv_str[b]="$"  then
		let lv_newstr[a]="$" let a=a+1
		let lv_newstr[a]="(" let a=a+1
		let lv_mode=1
		continue for
	end if
   
	if lv_mode=1 then
      if not is_valid_env_var_char(lv_str[b]) then
		   let lv_newstr[a]=")" let a=a+1
		   let lv_mode=0
      end if
	end if

	let lv_newstr[a]=lv_str[b] let a=a+1
end for
if lv_mode=1 then 
	let lv_newstr[a]=")"
end if
return lv_newstr
end function

function generate_makefile(lv_prog,lv_makefile)
define lv_prog char(128)
define lv_makefile char(512)
define lv_build_in_db char(256)
define lv_linkflags char(256)
define lv_compflags char(256)
define lv_name char(60),lv_value char(70)
define lv_flags char(70)
define lv_type char(1)
define lv_fullname char(512)
define lv_buildstr char(256)
define lv_uses_4gls integer
define lv_uses_forms integer
define lv_filetime integer
define lv_cnt integer

let lv_dynamically_found_libs_cnt=0

let lv_uses_4gls=false
let lv_uses_forms=false
call ensure_syspgma4gl()

let lv_makefile=aclfgl_expand_env_vars_in_cmdline (lv_makefile)

display  "Generating makefile : " ,lv_makefile clipped

call channel::open_file("make",lv_makefile, "w")

if status<0 then
	display "Unable to open output file:", lv_makefile clipped
	return
end if

# Lets start off with some easy stuff- 
# we'll just dump the BUILDDIR LFLAGS CFLAGS straight from the databse
select progoutdir, linkflags, compflags  into lv_build_in_db,lv_linkflags,lv_compflags
from program
where (justuser is null or justuser matches " " or justuser=user)
and progname=lv_prog

if sqlca.sqlcode=100 then
	initialize lv_build_in_db,lv_linkflags,lv_compflags to null
end if

let lv_build_in_db=replace_env_var_with_make_var(lv_build_in_db)

if lv_build_in_db is not null and lv_build_in_db != " " then
	if lv_build_in_db[length(lv_build_in_db)]="/" then
		let lv_build_in_db=lv_build_in_db[1,length(lv_build_in_db)-1]
	end if
	call channel::write("make","BUILDDIR="||lv_build_in_db clipped)
	let lv_buildstr="$(BUILDDIR)/"
else
	#call channel::write("make","BUILDDIR=.")
	let lv_buildstr=" "
end if



if lv_linkflags is not null and lv_linkflags!= " " then
	call channel::write("make","LFLAGS="||lv_linkflags clipped)
end if
if lv_compflags is not null and lv_compflags!= " " then
	call channel::write("make","CFLAGS="||lv_compflags clipped)
end if

#
# We'll create a 'list' of stuff that needs processing
# this will help keep the file neat and tidy
call channel::write("make","FORMS=")
call channel::write("make","LIBS=")
call channel::write("make","FGLOBJS=")
call channel::write("make","MIFS=")
call channel::write("make","OTHOBJS=")
call channel::write("make","OBJS_CFORMS=")
call channel::write("make","GLOBALS=")
call channel::write("make","GLOBALS_DEFS=")

if fgl_getenv("VMAKE")!=" "  then
	call channel::write("make","A4GL_UI=CONSOLE")
	call channel::write("make","export A4GL_UI")
	call channel::write("make","ALL4GLSRC=")
	call channel::write("make","ALLPERSRC=")
	#call channel::write("make","A4GL_GENERATE_TXXVARS=Y")
	#call channel::write("make","export A4GL_GENERATE_TXXVARS")
end if


call add_setting_if_missing(lv_prog,"A4GL_PACKER")
call add_setting_if_missing(lv_prog,"A4GL_FRM_BASE_EXT")
call add_setting_if_missing(lv_prog,"A4GL_PACKED_EXT")
call add_setting_if_missing(lv_prog,"A4GL_XML_EXT")
call add_setting_if_missing(lv_prog,"A4GL_EXE_EXT")
call add_setting_if_missing(lv_prog,"A4GL_EXE_PREFIX")
call add_setting_if_missing(lv_prog,"A4GL_FORMTYPE")
call add_setting_if_missing(lv_prog,"A4GL_HELP_EXT")
call add_setting_if_missing(lv_prog,"A4GL_OBJ_EXT")
call add_setting_if_missing(lv_prog,"A4GL_LEXDIALECT")
call add_setting_if_missing(lv_prog,"A4GL_LEXTYPE")



# Now - just dump the settings for the program
# and export them (this way a program is always compiled
# with the correct environment variables set)
declare c_getsettings cursor for
	select  distinct name,value from afglsettings 
	where (justuser is null or justuser matches " " or justuser=user)
	and progname=lv_prog
    order by 1

foreach c_getsettings  into lv_name,lv_value
	call channel::write("make",lv_name clipped||"="||replace_env_var_with_make_var(lv_value) clipped)
	call channel::write("make","export "||lv_name clipped)
end foreach
call channel::write("make","A4GL_PROGNAME="||lv_prog clipped)
call channel::write("make","export A4GL_PROGNAME")


# We need to set up the extension for the ESQL/C files - 
# we dont normally store them but it easy to work it out..
#
call channel::write("make","ifeq \"$(A4GL_LINTSTYLE)\" \"\"")
call channel::write("make"," A4GL_LINTSTYLE=XML")
call channel::write("make"," export A4GL_LINTSTYLE")
call channel::write("make","endif")

call channel::write("make","ifeq \"$(A4GL_LEXDIALECT)\" \"POSTGRES\"")
call channel::write("make"," A4GL_EC_EXT=.cpc")
call channel::write("make","else")
call channel::write("make"," A4GL_EC_EXT=.ec")
call channel::write("make","endif")
call channel::write("make"," ")
call channel::write("make","FCOMPILE=fcompile")
call channel::write("make","ifeq \"$(A4GL_FORMTYPE)\" \"GENERIC\"")
call channel::write("make"," ifeq \"$(A4GL_PACKER)\" \"PACKED\"")
call channel::write("make","  A4GL_FULL_FORM_EXT=$(A4GL_FRM_BASE_EXT)$(A4GL_PACKED_EXT)")
call channel::write("make"," endif")
call channel::write("make"," ifeq \"$(A4GL_PACKER)\" \"GZPACKED\"")
call channel::write("make","  A4GL_FULL_FORM_EXT=$(A4GL_FRM_BASE_EXT)$(A4GL_PACKED_EXT).gz")
call channel::write("make"," endif")
call channel::write("make"," ifeq \"$(A4GL_PACKER)\" \"XML\"")
call channel::write("make","  A4GL_FULL_FORM_EXT=$(A4GL_FRM_BASE_EXT)$(A4GL_XML_EXT)")
call channel::write("make"," endif")
call channel::write("make"," ")
call channel::write("make"," ifeq \"$(A4GL_USE_FORMXML)\" \"Y\"")
call channel::write("make","  A4GL_FULL_FORM_EXT=.xml")
call channel::write("make","  FCOMPILE=A4GL_PACKER=FORMXML fcompile")
call channel::write("make"," endif")
call channel::write("make","else")
call channel::write("make"," A4GL_FULL_FORM_EXT=$(A4GL_FRM_BASE_EXT)")
call channel::write("make","endif")
call channel::write("make"," ")
call channel::write("make","ifeq  \"$(A4GL_LINTFILE)\" \"\"")
call channel::write("make"," A4GL_LINTFILE=lint_"||lv_prog clipped||".xml")
call channel::write("make"," export A4GL_LINTFILE")
call channel::write("make","endif")











# Default target is 'compile'
call channel::write("make","all: compile")
call channel::write("make"," ")

call channel::write("make"," ")
declare c_get_modules cursor for 
	select distinct entity_type, name,flags from entity where (justuser is null or justuser matches " " or justuser=user)
        and progname=lv_prog
	order by 1,2

# We'll run throigh this list twice - once to add to our lists (FORMS, GLOBALS, OBJS)
# and once to create the rules for the targets themselves.
foreach c_get_modules into lv_type,lv_name,lv_flags

	if lv_flags is not null and lv_flags !=" " then
		let lv_flags=replace_env_var_with_make_var(lv_flags)
		if lv_flags[length(lv_flags)]="/" then
			let lv_flags=lv_flags[1,length(lv_flags)-1]
		end if
	end if


	if lv_flags is null or lv_flags=" " then
		let lv_fullname=lv_name
	else
		let lv_fullname=lv_flags clipped||"/"||lv_name
	end if

	# Globals         Module       C-Code         ESQL/C code
	if lv_type="G" or lv_type="M" then 
      		let lv_uses_4gls=true
		if lv_type="G" then
			if lv_flags is not null and lv_flags != " " then
	         		call channel::write("make","ALL4GLSRC+="||lv_flags clipped||"/"||lv_name clipped||".4gl")
				call channel::write("make","GLOBALS+="  ||lv_flags clipped||"/"||lv_name clipped||".4gl")
				call channel::write("make","GLOBALS_DEFS+="||lv_flags clipped||"/"||lv_name clipped||".glb.dat")
			else
				call channel::write("make","ALL4GLSRC+="||lv_name clipped||".4gl")
				call channel::write("make","GLOBALS+="||lv_name clipped||".4gl")
				call channel::write("make","GLOBALS_DEFS+="||lv_name clipped||".glb.dat")
			end if
		end if

		if isReplaceByLibrary(lv_fullname) then
			call channel::write("make","# "||lv_name clipped||" should be in a library instead")
		else
			call channel::write("make","# "||lv_name clipped||" not in library - need to use it instead")
			call channel::write("make","FGLOBJS+="||lv_buildstr clipped||lv_name clipped||"$(A4GL_OBJ_EXT)")
		end if

		call channel::write("make","MIFS+="||lv_buildstr clipped||lv_name clipped||".mif")
	end if

	if lv_type="C" or lv_type="E" then
		call channel::write("make","OTHOBJS+="||lv_buildstr clipped||lv_name clipped||"$(A4GL_OBJ_EXT)")
	end if

	if lv_type="f" then
		call channel::write("make","OBJS_CFORMS+="||lv_buildstr clipped||lv_name clipped||"$(A4GL_FRM_BASE_EXT)$(A4GL_OBJ_EXT)")
	end if

	if lv_type="F" then # Form
      let lv_uses_forms=true
		call channel::write("make","ALLPERSRC+="||lv_fullname clipped||".per")

		if lv_flags is not null and lv_flags != " " then
			call channel::write("make","FORMS+="||lv_buildstr clipped||lv_name clipped||"$(A4GL_FULL_FORM_EXT)")
		else
			call channel::write("make","FORMS+="||lv_name clipped||"$(A4GL_FULL_FORM_EXT)")
		end if
	end if

   if lv_type="M" then
	         call channel::write("make","ALL4GLSRC+="||lv_fullname clipped||".4gl")
   end if

	if lv_type="L" then # Libraries
		if lv_flags is not null and lv_flags != " " then
			call channel::write("make","LIBS+=-l"||lv_flags clipped||"/"||lv_name clipped)
		else
			call channel::write("make","LIBS+=-l"||lv_name clipped)
		end if
	end if
end foreach

if fgl_getenv("VMAKE")!=" "  then
	#call channel::write("make","G_TXX=$(LFILE_DIR)/g_txx_"||lv_prog clipped)
	call channel::write("make","G_TXX=$(VMAKE)/g_txx_"||lv_prog clipped)
	call channel::write("make","export G_TXX")
   	call channel::write("make"," ifeq \"$(COPYDIR)\" \"\"")
   	call channel::write("make"," COPYDIR=/tmp/"||lv_prog clipped)
   	call channel::write("make","endif")

   if not has_lib("common") then
	   call channel::write("make","GLOBALS+=$(LFILE_DIR)/g_"||lv_prog clipped||"txv.4gl")
	   call channel::write("make","DEFAULT_GLOBALS=$(LFILE_DIR)/g_"||lv_prog clipped||"txv.4gl")
   else
	   call channel::write("make","GLOBALS+=$(V4GL)/dll/g_txv.4gl")
	   call channel::write("make","DEFAULT_GLOBALS=$(V4GL)/dll/g_txv.4gl")
   end if

	call channel::write("make","export DEFAULT_GLOBALS")
end if


if lv_dynamically_found_libs_cnt then
	call channel::write("make","LIBS+= -L$(V4GL)/dll")
	for lv_cnt=1 to lv_dynamically_found_libs_cnt
		call channel::write("make","LIBS+= -l"||lv_dynamically_found_libs[lv_cnt] clipped)
	end for
end if

if fgl_getenv("NEEDLIBAUBIT4GL")!="N" THEN
		call channel::write("make","LIBS+= -laubit4gl")
end if

if fgl_getenv("VMAKE")!= " " then
   if not has_lib("common") then
	   call channel::write("make","OTHOBJS+="||lv_buildstr clipped||"g_"||lv_prog clipped||"txv$(A4GL_OBJ_EXT) ")
	   call channel::write("make","GLOBALS_DEFS+=$(LFILE_DIR)/g_"||lv_prog clipped||"txv.glb.dat")
	   call channel::write("make","OTHOBJS+="||lv_buildstr clipped||"t_"||lv_prog clipped||"$(A4GL_OBJ_EXT) ")
   end if
end if





#call channel::write("make","MIFS=$(subst $(A4GL_OBJ_EXT),.mif,${FGLOBJS})")
call channel::write("make"," ")


if lv_buildstr != " " then
	call channel::write("make","prerequisits: $(BUILDDIR) commonlibs")
	call channel::write("make","	@if [ ! -d $(BUILDDIR) ] ; then mkdir $(BUILDDIR); chmod 777 $(BUILDDIR); fi")
else
	call channel::write("make","prerequisits: commonlibs")
end if

if fgl_getenv("VMAKE")!= " " then
	call channel::write("make","commonlibs: ")
	call channel::write("make","	$(MAKE) -C $(V4GL)/dll -f make_common")
else
	call channel::write("make","commonlibs:")
end if

   


# And the second time through
foreach c_get_modules into lv_type,lv_name,lv_flags

	if lv_flags is not null and lv_flags !=" " then
		let lv_flags=replace_env_var_with_make_var(lv_flags)
		if lv_flags[length(lv_flags)]="/" then
			let lv_flags=lv_flags[1,length(lv_flags)-1] 

		end if
	end if
	if lv_flags is null or lv_flags=" " then
		let lv_fullname=lv_name
	else
		let lv_fullname=lv_flags clipped||"/"||lv_name
	end if

	if lv_type="G" then # Globals
      if fgl_getenv("VMAKE")!= " " then
		   call channel::write("make",lv_buildstr clipped||lv_name clipped||"$(A4GL_OBJ_EXT): "||lv_fullname clipped||".4gl $(DEFAULT_GLOBALS)")
		   call channel::write("make","	4glc -K $(CFLAGS) -o $@ $<")
      else
		   call channel::write("make",lv_buildstr clipped||lv_name clipped||"$(A4GL_OBJ_EXT): "||lv_fullname clipped||".4gl")
		   call channel::write("make","	4glpc -K $(CFLAGS) -o $@ $<")
      end if

		call channel::write("make",lv_buildstr clipped||lv_name clipped||".mif: "||lv_fullname clipped||".4gl")
		call channel::write("make","	A4GL_PACKER_EXT=.mif A4GL_PACKER=PACKED 4glpc -t WRITE -o $@ $<")
	end if

	if lv_type="M"  then # Normal modules
		call channel::write("make",lv_buildstr clipped||lv_name clipped||"$(A4GL_OBJ_EXT): "||lv_fullname clipped||".4gl  $(GLOBALS_DEFS)")
if fgl_getenv("VMAKE")!= " " then
		call channel::write("make","	4glc -K $(CFLAGS) -o $@ $<")
else
		call channel::write("make","	4glpc -K $(CFLAGS) -o $@ $<")
end if
		call channel::write("make",lv_buildstr clipped||lv_name clipped||".mif: "||lv_fullname clipped||".4gl  $(GLOBALS_DEFS)")
		call channel::write("make","	A4GL_PACKER_EXT=.mif A4GL_PACKER=PACKED 4glpc -t WRITE -o $@ $<")
	end if

	if lv_type="C" then # C code
		call channel::write("make",lv_buildstr clipped||lv_name clipped||"$(A4GL_OBJ_EXT): "||lv_fullname clipped||".c")
if fgl_getenv("VMAKE")!= " " then
		call channel::write("make","	4glc $(CFLAGS) -o $@ $^")
else
		call channel::write("make","	4glpc $(CFLAGS) -o $@ $^")
end if
	end if

	if lv_type="f" then # C Form code
		call channel::write("make",lv_buildstr clipped||lv_name clipped||"$(A4GL_FRM_BASE_EXT)$(A4GL_OBJ_EXT): "||lv_fullname clipped||".per")
		call channel::write("make","	$(FCOMPILE) -o "||lv_buildstr clipped||lv_name clipped||"$(A4GL_FRM_BASE_EXT) -c $^")
		call channel::write("make","	4glpc -o $@ -c "||lv_buildstr clipped||lv_name clipped||"$(A4GL_FRM_BASE_EXT).c")
	end if

	if lv_type="E" then # ESQL/C code
		call channel::write("make",lv_buildstr clipped||lv_name clipped||"$(A4GL_OBJ_EXT): "||lv_fullname clipped||"$(A4GL_EC_EXT)")
if fgl_getenv("VMAKE")!= " " then
		call channel::write("make","	4glc $(CFLAGS) -o $@ $^")
else
		call channel::write("make","	4glpc $(CFLAGS) -o $@ $^")
end if
	end if

	if lv_type="F" then # Form
		call channel::write("make",lv_buildstr clipped||lv_name clipped||"$(A4GL_FULL_FORM_EXT): "||lv_fullname clipped||".per")
		call channel::write("make","	$(FCOMPILE) -o $@ $^")
	end if
	call channel::write("make"," ")
end foreach





# Not a full clean - just the intermediates...
call channel::write("make","tidy:")
call channel::write("make","	rm -f $(FGLOBJS) $(OTHOBJS) $(MIFS) $(GLOBALS_DEFS)")
call channel::write("make"," ")

if fgl_getenv("VMAKE")!= " " then
   call channel::write("make","cleantxx:")
   call channel::write("make","	rm -f $(G_TXX) $(LFILE_DIR)/g_"||lv_prog clipped||"txv.4gl  $(LFILE_DIR)/t_"||lv_prog clipped||".4gl")
end if

call channel::write("make","tidy_globals_dats:")
call channel::write("make","	@rm -f $(GLOBALS_DEFS)")

if lv_uses_4gls then
   if lv_uses_forms then
      call channel::write("make","compile: prerequisits phony.globals "||lv_buildstr clipped||"$(A4GL_EXE_PREFIX)"||lv_prog clipped||"$(A4GL_EXE_EXT) $(FORMS)")
   else
      call channel::write("make","compile: prerequisits phony.globals "||lv_buildstr clipped||"$(A4GL_EXE_PREFIX)"||lv_prog clipped||"$(A4GL_EXE_EXT)")
   end if
else
   if lv_uses_forms then
      call channel::write("make","compile: prerequisits $(FORMS)")
   else
      call channel::write("make","compile: prerequisits ")
   end if
end if

call channel::write("make"," ")
call channel::write("make","run: compile")

if lv_buildstr is not null and lv_buildstr != " " then
	call channel::write("make","	cd ",lv_buildstr," &&  ./$(A4GL_EXE_PREFIX)"||lv_prog clipped||"$(A4GL_EXE_EXT)")
else
	call channel::write("make","	./$(A4GL_EXE_PREFIX)"||lv_prog clipped||"$(A4GL_EXE_EXT)")
end if
call channel::write("make"," ")

call channel::write("make",lv_buildstr clipped||"$(A4GL_EXE_PREFIX)"||lv_prog clipped||"$(A4GL_EXE_EXT): $(FGLOBJS) $(OTHOBJS) $(OBJS_CFORMS) ")

if fgl_getenv("VMAKE")!= " " then
call channel::write("make","	4glc $(LFLAGS) -o $@ $(FGLOBJS) $(OTHOBJS) $(OBJS_CFORMS) $(LIBS)")
else
call channel::write("make","	4glpc $(LFLAGS) -o $@ $(FGLOBJS) $(OTHOBJS) $(OBJS_CFORMS) $(LIBS)")
end if

call channel::write("make"," ")
call channel::write("make","clean:")
call channel::write("make","	rm -f $(FGLOBJS) $(OTHOBJS) $(OBJS_CFORMS) $(FORMS) ${MIFS} $(GLOBALS_DEFS)  "||lv_buildstr clipped||"$(A4GL_EXE_PREFIX)"||lv_prog clipped||"$(A4GL_EXE_EXT) ")

if fgl_getenv("VMAKE")!= " " then
	call channel::write("make","	rm -f $(G_TXX) $(LFILE_DIR)/g_"||lv_prog clipped||"txv.4gl $(LFILE_DIR)/t_"||lv_prog clipped||".4gl")
end if


if fgl_getenv("VMAKE")!=" " then
	   #call channel::write("make","phony.globals: $(G_TXX) $(LFILE_DIR)/g_vkopftxv.4gl $(GLOBALS_DEFS)")
	   call channel::write("make","phony.g_"||lv_prog clipped||"txv: $(LFILE_DIR)/g_"||lv_prog clipped||"txv.4gl")
	   call channel::write("make","phony.globals: $(GLOBALS_DEFS)")
else
	   call channel::write("make","phony.globals: $(GLOBALS_DEFS)")
end if
call channel::write("make"," ")
call channel::write("make","%.glb.dat: %.4gl")
call channel::write("make","	4glc -G $<")

call channel::write("make"," ")

if fgl_getenv("VMAKE") !=" " then
	# Special code for Ventas to generate the global txt file
	   call channel::write("make","phony.globals.old: $(G_TXX) $(LFILE_DIR)/g_"||lv_prog clipped||"txv.4gl $(LFILE_DIR)/t_"||lv_prog clipped||".4gl $(GLOBALS_DEFS)")
	   call channel::write("make","$(LFILE_DIR)/g_"||lv_prog clipped||"txv.4gl $(LFILE_DIR)/t_"||lv_prog clipped||".4gl:  $(G_TXX)")
	   #call channel::write("make","$(LFILE_DIR)/g_"||lv_prog clipped||"txv.4gl $(LFILE_DIR)/t_"||lv_prog clipped||".4gl: $(G_TXX)")
	   call channel::write("make","	mktxx $(G_TXX) $(LFILE_DIR)/g_"||lv_prog clipped||"txv.4gl $(LFILE_DIR)/t_"||lv_prog clipped||".4gl '$(LFILE_DIR_NOT_EXPANDED)/g_"||lv_prog clipped||"txv.4gl'")
	   call channel::write("make","")


		call channel::write("make", lv_buildstr clipped||"g_"||lv_prog clipped||"txv$(A4GL_OBJ_EXT): "|| "$(LFILE_DIR)/g_"||lv_prog clipped||"txv.4gl")
if fgl_getenv("VMAKE")!= " " then
		call channel::write("make","	4glc -K $(CFLAGS) -o $@ $<")
else
		call channel::write("make","	4glpc -K $(CFLAGS) -o $@ $<")
end if
		call channel::write("make", lv_buildstr clipped||"t_"||lv_prog clipped||"$(A4GL_OBJ_EXT): "|| "$(LFILE_DIR)/t_"||lv_prog clipped||".4gl")
if fgl_getenv("VMAKE")!= " " then
		call channel::write("make","	unset DEFAULT_GLOBALS; DBPATH=$(DBPATH):$(V4GL):$(LFILE_DIR) 4glc -K $(CFLAGS) -o $@ $<")
else
		call channel::write("make","	unset DEFAULT_GLOBALS; DBPATH=$(DBPATH):$(V4GL):$(LFILE_DIR) 4glpc -K $(CFLAGS) -o $@ $<")
end if

		call channel::write("make","$(G_TXX):  $(ALL4GLSRC)")
  		call channel::write("make","	mktxx_grep $(ALL4GLSRC) > $(G_TXX)")
                                                       

      if lv_prog not matches "*_tmp" then
         # Rule to copy all the source 4gl and forms etc into the COPYDIR directory
         # Replicates the copytmp for Ventas...
         call channel::write("make","$(COPYDIR):")
		   call channel::write("make","	mkdir $(COPYDIR)")
		   call channel::write("make","")
         call channel::write("make","copy: $(COPYDIR)")
		   call channel::write("make","	cp $(ALL4GLSRC) $(ALLPERSRC) $(COPYDIR)")
		   call channel::write("make","	cp $(LFILE_DIR)/make_"||lv_prog clipped||"_tmp $(COPYDIR)/Makefile")
		   call channel::write("make","	cp $(LFILE_DIR)/g_"||lv_prog clipped||"txv.4gl $(COPYDIR) || exit 0")
		   call channel::write("make","")
      end if

end if


call channel::write("make","lint : ${A4GL_LINTFILE}")
call channel::write("make","$(A4GL_LINTFILE) : ${MIFS}")
call channel::write("make","	A4GL_PACKED_EXT=.mif A4GL_PACKER=PACKED fgllint ${MIFS}")

call channel::write("make"," ")
call channel::write("make","calltree : ${MIFS}")
call channel::write("make","	A4GL_PACKED_EXT=.mif A4GL_PACKER=PACKED fglcalltree ${MIFS}")
call channel::write("make","	dot -T pdf -Lg calltree.dot -o"||lv_buildstr clipped||lv_prog clipped||".pdf")

call channel::write("make","calltree_load : ${MIFS}")
call channel::write("make","	A4GL_PACKED_EXT=.mif A4GL_PACKER=PACKED fglcalltree ${MIFS}")
call channel::write("make","	load_calltree")




call channel::close("make")

let lv_filetime=get_file_time(lv_makefile)
update program set genmakefile=lv_filetime
where progname=lv_prog
and (justuser is null or justuser matches " " or justuser=user)


end function



function run_with_logging(lv_runstr)
define lv_runstr char(512)
define lv_ok integer

	display " " # goto line mode

    display lv_runstr clipped

	run lv_runstr clipped returning lv_ok

	return lv_ok


{
	let lv_logfile=get_tmp_fname("ERR")
	let lv_runstr=lv_runstr clipped," > ",lv_logfile clipped, " 2>&1"

	call load_logging(lv_logfile)
	call remove_tmp_files("ERR")
}
end function



function isReplaceByLibrary(lv_name)
define lv_name char(200)
define lv_libs char(200)

if fgl_getenv("VMAKE")!=" "  then
	#display "Searching for ",lv_name clipped

	select libname into lv_libs from inLibrary where module=lv_name
	if sqlca.sqlcode =0 then
		call add_lib(lv_libs)
		return true
	end if

	# Is it just missing a .4gl extension ? 
	if lv_name not matches "*.4gl" then
		let lv_name=lv_name clipped,".4gl"
		select libname into lv_libs from inLibrary where module=lv_name
		if sqlca.sqlcode =0 then
			call add_lib(lv_libs)
			return true
		end if
	end if



end if
return false
end function
	


# This function maintains a list of libraries which need to be included
# These are determined dynamically by any modules listed in the 'inlibrary' table
# this is currently only used for Ventas build...
function add_lib(lv_libname)
define lv_libname char(32)
define a integer
#Have we already added it ? 
if lv_dynamically_found_libs_cnt then
	for a=1 to lv_dynamically_found_libs_cnt
			if lv_dynamically_found_libs[a]=lv_libname then
				return
			end if
	end for
end if

let lv_dynamically_found_libs_cnt=lv_dynamically_found_libs_cnt+1
let lv_dynamically_found_libs[lv_dynamically_found_libs_cnt]=lv_libname
end function


function has_lib(lv_libname) 
define lv_libname char(32)
define a integer
#Have we already added it ? 
if lv_dynamically_found_libs_cnt then
	for a=1 to lv_dynamically_found_libs_cnt
			if lv_dynamically_found_libs[a]=lv_libname then
				return true
			end if
	end for
end if
return false
end function


function get_syspgma4gl_dbname()
if length(fgl_getenv("SYSPGMA4GL"))>0 then
	return fgl_getenv("SYSPGMA4GL") 
else
	return "syspgma4gl"
end if
end function


