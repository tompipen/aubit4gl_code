define mv_lastused char(256)
define lv_prog_cnt integer


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
		if get_db()=="syspgma4gl" then
			close database
			call set_curr_db("")
		end if
		exit menu
end menu

end function



################################################################################
function program_modify()
define lv_name char(16)
define lv_cnt integer
define lv_user char(8)

	call ensure_syspgma4gl()

	call get_program("modify",mv_lastused) returning lv_name

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
define lv_name char(16)
define lv_cnt integer
define lv_makefile char(512)

	call ensure_syspgma4gl()

	call get_program("generate",mv_lastused) returning lv_name

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

end function



################################################################################
function program_new()
define lv_name char(16)
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
define lv_name char(16)
define lv_user char(8)
define lv_ok integer

menu "Maintin Program"
	before menu
		call display_banner()

	command "Program" "Edit program definition"
		call program_edit_program(lv_name) returning lv_ok

	command "Modules" "Edit modules in this program"
		call program_edit_modules(lv_name,lv_user)
	
	command "Globals" "Edit global modules in this program"
		call program_edit_globals(lv_name,lv_user)

	command "Forms"	"Edit list of forms for this program"
		call program_edit_forms(lv_name,lv_user)

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
	if has_db()  then
		if get_db()!="syspgma4gl" then
			whenever error continue
			close database
			whenever error stop
			database syspgma4gl
			call set_curr_db("syspgma4gl")
		end if
	else
			database syspgma4gl
			call set_curr_db("syspgma4gl")
	end if
end function


################################################################################
# Add the list of programs from our database to our pick list
################################################################################
function add_programs_from_db()
define lv_prog char(16)

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
define lv_what char (20)
define lv_ext char(4)
define a integer

code
{
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
        A4GL_free_directory(dir);
    }
}
endcode

end function



################################################################################
# Edit the program header - or insert one if one doesn't already exist
################################################################################
function program_edit_program(lv_name)
define lv_ok integer
define lv_a record
    progname char(16),
    justuser char(8),
    progoutdir char(256),
    progmakefile char(256),
    linkflags char(70),
    compflags char(70),
    lastupd integer,
    genmakefile integer
end record
define lv_name char(16)
define lv_exists integer


	initialize lv_a.* to null

	call ensure_syspgma4gl()

	select * into lv_a.* from program 
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
define lv_name char(16)
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
define lv_name char(16)
define lv_user char(8)
define lv_now integer
define lv_makefile char(256)

code
lv_now=time(0);
endcode

end function



################################################################################
function program_compile()
define lv_name char(16)
define lv_makefile char(512)
define lv_cnt integer
define lv_ok integer


	call ensure_syspgma4gl()

	call get_program("compile",mv_lastused) returning lv_name

	select count(*) into lv_cnt from program 
	where (justuser is null or justuser matches " " or justuser=user)
	and progname=lv_name

	if lv_cnt=0 then
		error "Program not found"
		return
	end if

    call set_last_used_program(lv_name)

	{select justuser into lv_user from program 
	where (justuser is null or justuser matches " " or justuser=user)
	and  progname=lv_name}

    message "Compiling ..."

	call get_makefile_for(lv_name) returning lv_makefile

	call run_with_logging("make -f "||lv_makefile clipped||" compile ") returning lv_ok

	#run "make -f "||lv_makefile clipped||" compile " returning lv_ok

	if lv_ok >255 then
		let lv_ok=lv_ok/256
	end if

	if lv_ok=0 then
		message "Program compile succeeded"
	else
		display "Program failed to compile - press return"
		call fgl_getkey() returning lv_ok # some key any key
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
	display "Press return to continue"
	call fgl_getkey() returning lv_ok
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
define lv_ext char(4)
define lv_lastused char(255)

let lv_lastused=remove_ext(lv_lastused)

case lv_what

        when "modify"
		let lv_prog_cnt=1
                display "Choose a program to modify","" at 2,1
		call add_programs_from_db()
		let lv_prog_cnt=lv_prog_cnt-1
		call set_pick_cnt(lv_prog_cnt);

        when "generate"
		let lv_prog_cnt=1
                display "Choose a program to generate a makefile for","" at 2,1
		call add_programs_from_db()
		let lv_prog_cnt=lv_prog_cnt-1
		call set_pick_cnt(lv_prog_cnt);

        when "compile"
		let lv_prog_cnt=1
                display "Choose a program to compile","" at 2,1
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
                display "Choose a program to undefine","" at 2,1
		call add_programs_from_db()
		let lv_prog_cnt=lv_prog_cnt-1
		call set_pick_cnt(lv_prog_cnt);

end case





call set_picked_option(lv_lastused)
call prompt_pick("CHOOSE >> ","") returning lv_fname
return lv_fname
end function





################################################################################
function edit_program_entity(lv_name, lv_user, lv_type)
define lv_user char(8)
define lv_name char(16)
define lv_type char(1)
define lv_r array[500] of record 
    entity integer,
    entity_type char(1),
    progname char(16),
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
define lv_name char(16)
define lv_user char(8)
	call edit_program_entity(lv_name,lv_user, "M")
end function

################################################################################
function program_edit_globals(lv_name,lv_user)
define lv_name char(16)
define lv_user char(8)
	call edit_program_entity(lv_name,lv_user, "G")
end function

################################################################################
function program_edit_forms(lv_name,lv_user)
define lv_name char(16)
define lv_user char(8)
	call edit_program_entity(lv_name,lv_user, "F")
end function

################################################################################
function program_edit_libraries(lv_name,lv_user)
define lv_name char(16)
define lv_user char(8)
	call edit_program_entity(lv_name, lv_user,"L")
end function

################################################################################
function program_edit_c(lv_name,lv_user)
define lv_name char(16)
define lv_user char(8)
	call edit_program_entity(lv_name, lv_user,"C")
end function
################################################################################
function program_edit_ec(lv_name,lv_user)
define lv_name char(16)
define lv_user char(8)
	call edit_program_entity(lv_name, lv_user,"E")
end function

################################################################################
function program_edit_dependencies(lv_name,lv_user)
define lv_name char(16)
define lv_user char(8)
	error "Not implemented yet"
end function

################################################################################
function program_edit_settings(lv_name,lv_user)
define lv_name char(16)
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
define lv_lastused char(16)
let mv_lastused=lv_lastused
end function

function has_setting(lv_prog,lv_name)
define lv_prog char(16)
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
define lv_prog chaR(16)
define lv_name char(32)

if not has_setting(lv_prog,lv_name)  then
	call channel::write("make",lv_name clipped||":=$(shell aubit-config "||lv_name clipped||")")
end if
end function



function generate_makefile(lv_prog,lv_makefile)
define lv_prog char(16)
define lv_makefile char(512)
define lv_fout integer
define lv_build char(256)
define lv_linkflags char(256)
define lv_compflags char(256)
define lv_name char(60),lv_value char(70)
define lv_flags char(70)
define lv_type char(1)
define lv_fullname char(512)
define lv_buildstr char(256)
define lv_filetime integer

call ensure_syspgma4gl()

message "Generating makefile..." 
call channel::open_file("make",lv_makefile, "w")

# Lets start off with some easy stuff- 
# we'll just dump the BUILDDIR LFLAGS CFLAGS straight from the databse
select progoutdir, linkflags, compflags  into lv_build,lv_linkflags,lv_compflags
from program
where (justuser is null or justuser matches " " or justuser=user)
and progname=lv_prog

if lv_build is not null and lv_build != " " then
	if lv_build[length(lv_build)]="/" then
		let lv_build=lv_build[1,length(lv_build)-1]
	end if
	call channel::write("make","BUILDDIR="||lv_build clipped)
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
call channel::write("make","OBJS=")
call channel::write("make","GLOBALS=")


call add_setting_if_missing(lv_prog,"A4GL_PACKER")
call add_setting_if_missing(lv_prog,"A4GL_FRM_BASE_EXT")
call add_setting_if_missing(lv_prog,"A4GL_PACKED_EXT")
call add_setting_if_missing(lv_prog,"A4GL_XML_EXT")
call add_setting_if_missing(lv_prog,"A4GL_EXE_EXT")
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
	call channel::write("make",lv_name clipped||"="||lv_value clipped)
	call channel::write("make","export "||lv_name clipped)
end foreach


# We need to set up the extension for the ESQL/C files - 
# we dont normally store them but it easy to work it out..
#
call channel::write("make","ifeq \"$(A4GL_LEXDIALECT)\" \"POSTGRES\"")
call channel::write("make"," A4GL_EC_EXT=.cpc")
call channel::write("make","else")
call channel::write("make"," A4GL_EC_EXT=.ec")
call channel::write("make","endif")
call channel::write("make"," ")
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
call channel::write("make","else")
call channel::write("make"," A4GL_FULL_FORM_EXT=$(A4GL_FRM_BASE_EXT)")
call channel::write("make","endif")
call channel::write("make"," ")


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

		# Globals         Module       C-Code         ESQL/C code
	if lv_type="G" or lv_type="M" or lv_type="C" or lv_type="E" then
		if lv_type="G" then
			if lv_flags is not null and lv_flags != " " then
				call channel::write("make","GLOBALS+="||lv_flags clipped||"/"||lv_name clipped||".4gl")
			else
				call channel::write("make","GLOBALS+="||lv_name clipped||".4gl")
			end if
		end if
		call channel::write("make","OBJS+="||lv_buildstr clipped||lv_name clipped||"$(A4GL_OBJ_EXT)")
	end if

	if lv_type="F" then # Form
		if lv_flags is not null and lv_flags != " " then
			call channel::write("make","FORMS+="||lv_flags clipped||"/"||lv_name clipped||"$(A4GL_FULL_FORM_EXT)")
		else
			call channel::write("make","FORMS+="||lv_name clipped||"$(A4GL_FULL_FORM_EXT)")
		end if
	end if

	if lv_type="L" then # Libraries
		if lv_flags is not null and lv_flags != " " then
			call channel::write("make","LIBS+=-l"||lv_flags clipped||"/"||lv_name clipped)
		else
			call channel::write("make","LIBS+=-l"||lv_name clipped)
		end if
	end if
end foreach

call channel::write("make","MIFS=$(subst $(A4GL_OBJ_EXT),.mif,${OBJS})")
call channel::write("make"," ")

# And the second time through
foreach c_get_modules into lv_type,lv_name,lv_flags

	if lv_flags is null or lv_flags=" " then
		let lv_fullname=lv_name
	else
		let lv_fullname=lv_flags clipped||"/"||lv_name
	end if

	if lv_type="G" then # Globals
		call channel::write("make",lv_buildstr clipped||lv_name clipped||"$(A4GL_OBJ_EXT): "||lv_fullname clipped||".4gl")
		call channel::write("make","	4glpc -K $(CFLAGS) -o $@ $^")
		call channel::write("make",lv_buildstr clipped||lv_name clipped||".mif: "||lv_fullname clipped||".4gl")
		call channel::write("make","	A4GL_PACKER_EXT=.mif A4GL_PACKER=PACKED 4glpc -t WRITE -o $@ $^")
	end if

	if lv_type="M"  then # Normal modules
		call channel::write("make",lv_buildstr clipped||lv_name clipped||"$(A4GL_OBJ_EXT): "||lv_fullname clipped||".4gl $(GLOBALS)")
		call channel::write("make","	4glpc -K $(CFLAGS) -o $@ $<")
		call channel::write("make",lv_buildstr clipped||lv_name clipped||".mif: "||lv_fullname clipped||".4gl $(GLOBALS)")
		call channel::write("make","	A4GL_PACKER_EXT=.mif A4GL_PACKER=PACKED 4glpc -t WRITE -o $@ $^")
	end if

	if lv_type="C" then # C code
		call channel::write("make",lv_buildstr clipped||lv_name clipped||"$(A4GL_OBJ_EXT): "||lv_fullname clipped||".c")
		call channel::write("make","	4glpc $(CFLAGS) -o $@ $^")
	end if

	if lv_type="E" then # ESQL/C code
		call channel::write("make",lv_buildstr clipped||lv_name clipped||"$(A4GL_OBJ_EXT): "||lv_fullname clipped||"$(A4GL_EC_EXT)")
		call channel::write("make","	4glpc $(CFLAGS) -o $@ $^")
	end if

	if lv_type="F" then # Form
		call channel::write("make",lv_buildstr clipped||lv_name clipped||"$(A4GL_FULL_FORM_EXT): "||lv_fullname clipped||".per")
		call channel::write("make","	fcompile -o $@ $^")
	end if
	call channel::write("make"," ")
end foreach

call channel::write("make","compile: "||lv_buildstr clipped||lv_prog clipped||"$(A4GL_EXE_EXT) $(FORMS)")
call channel::write("make"," ")
call channel::write("make","run: compile")
if lv_build is not null and lv_build != " " then
	call channel::write("make","	cd "||lv_build||" && ./"||lv_prog clipped||"$(A4GL_EXE_EXT)")
else
	call channel::write("make","	./"||lv_prog clipped||"$(A4GL_EXE_EXT)")
end if
call channel::write("make"," ")

call channel::write("make",lv_buildstr clipped||lv_prog clipped||"$(A4GL_EXE_EXT): $(OBJS) ")
call channel::write("make","	4glpc $(LFLAGS) -o $@ $(OBJS) $(LIBS)")

call channel::write("make"," ")
call channel::write("make","clean:")
call channel::write("make","	echo rm $(OBJS) $(FORMS) ${MIFS}"||lv_buildstr clipped||lv_prog clipped||"$(A4GL_EXE_EXT)")


call channel::write("make"," ")
call channel::write("make","lint : ${MIFS}")
call channel::write("make","	A4GL_PACKED_EXT=.mif A4GL_PACKER=PACKED fgllint ${MIFS}")

call channel::write("make"," ")
call channel::write("make","calltree : ${MIFS}")
call channel::write("make","	A4GL_PACKED_EXT=.mif A4GL_PACKER=PACKED fglcalltree ${MIFS}")
call channel::write("make","	dot -T pdf -Lg calltree.dot -o"||lv_buildstr clipped||lv_prog clipped||".pdf")




call channel::close("make")

let lv_filetime=get_file_time(lv_makefile)
update program set genmakefile=lv_filetime
where progname=lv_prog
and (justuser is null or justuser matches " " or justuser=user)

message "Generated makefile" 

end function



function run_with_logging(lv_runstr)
define lv_runstr char(512)
define lv_logfile char(512)
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


