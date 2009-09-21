define mv_curr_db char(256)
define mc_version constant 0.8

main
define lv_dialect char(20)
define lv_makefile char(512) # Used for $ a4gl -p {programname}
defer interrupt

	#if fgl_getenv("A4GL_UI")="HL_GTK" or fgl_getenv("A4GL_UI")="XML" or fgl_getenv("A4GL_USE_FORMS")="Y" then
	#	call aclfgl_setenv("HIDEEMPTYBUTTONS","Y");
        #	call set_use_form()
	#else
        #	call clr_use_form()
	#end if
	#call form_is_compiled(pick10,"MEMPACKED","GENERIC")
	#call form_is_compiled(pick20,"MEMPACKED","GENERIC")
	#call form_is_compiled(pick38,"MEMPACKED","GENERIC")
	#call form_is_compiled(pick78,"MEMPACKED","GENERIC")

	call form_is_compiled(splash,"MEMPACKED","GENERIC")
	call form_is_compiled(warn,"MEMPACKED","GENERIC")

	call form_is_compiled(prog,"MEMPACKED","GENERIC")
	call form_is_compiled(entities,"MEMPACKED","GENERIC")
	call form_is_compiled(settings,"MEMPACKED","GENERIC")


	if upshift(fgl_getenv("A4GL_BANNER"))="N" THEN
	else
		call copyright_banner()
	end if

	options message line last
	options input wrap

	whenever error continue
	database syspgma4gl
	call set_pick_db("syspgma4gl")
	whenever error stop

	if sqlca.sqlcode!=0 then
		message "Creating syspgma4gl database"
		whenever error continue

		let lv_dialect = dbms_dialect()
		if lv_dialect[1,8] = "POSTGRES" then
			database template1
		end if
		execute immediate "create database syspgma4gl"
		database syspgma4gl
		call set_pick_db("syspgma4gl")
		whenever error stop

		if sqlca.sqlcode!=0 then
			display "Error:"
			display "   Unable to connect to or create the syspgma4gl database"
			display "   ------------------------------------------------------"
			display " "
			display "Please manually create a database called 'syspgma4gl'"
			display "and create the tables as in $AUBITDIR/tools/a4gl/create_tables.sql."
			display " "
			display "If the database exists then ensure you have permission to connect to it"
			exit program 1
		end if

		call createtables()
		message "syspgma4gl database created" sleep 1
		message " "
	end if
		
	if num_args()=2 then
		 if arg_val(1)="-p" then
			        call get_makefile_for(arg_val(2)) returning lv_makefile
        			#call generate_makefile(arg_val(2), lv_makefile)
				exit program
		end if
		
	end if
	call main_menu()
end main



function err_createtables()
	display "There was an error creating the database tables"
	display "Please manually create a syspgma4gl with the tables in"
	display "$AUBITDIR/tools/a4gl/create_tables.sql"
	exit program 2
end function

function createtables()
whenever error continue
# We dont care i this one fails...
grant connect to public




create table entity
  (
    entity serial not null ,
    entity_type char(1),
    progname char(128),
    justuser char(8),
    name char(60),
    flags char(60)
  );

if sqlca.sqlcode<0 then
	# Maybe it didn't like the 'serial' ?
	create table entity
  	(
    	entity integer not null ,
    	entity_type char(1),
    	progname char(128),
    	justuser char(8),
    	name char(60),
    	flags char(60)
  	);
end if

if sqlca.sqlcode<0 then
	call err_createtables()
end if


create table dependencies
  (
    entity integer,
    depends_on integer
  );


if sqlca.sqlcode<0 then
	call err_createtables()
end if

create table afglsettings
  (
    progname char(128),
    justuser char(8),
    name char(32),
    value char(70)
  );

if sqlca.sqlcode<0 then
	call err_createtables()
end if

create table program
  (
    progname char(128),
    justuser char(8),
    progoutdir char(256),
    progmakefile char(256),
    linkflags char(70),
    compflags char(70),
    lastupd integer,
    genmakefile integer
  );

if sqlca.sqlcode<0 then
	call err_createtables()
end if

if dbms_dialect()  MATCHES "*POSTGRES*" then

	# Create the trigger to handle the SERIAL on 'entity'
	execute immediate "CREATE OR REPLACE FUNCTION get_next_entity_entity() RETURNS TRIGGER AS $$"||
	" BEGIN"||
    	" IF NEW.entity = 0 then"||
      	" SELECT nextval('entity_entity_seq') into NEW.entity;"||
   	" ELSE"||
      	" IF NEW.entity > 0 THEN"||
         	" PERFORM setval('entity_entity_seq',NEW.entity);"||
   	" END IF;"||
	" END IF;"||
	" RETURN NEW;"||
	" END;"||
	"$$ LANGUAGE plpgsql"

	if sqlca.sqlcode<0 then
		call err_createtables()
	end if

	execute immediate "drop trigger sertrig_entity_entity on entity"
	execute immediate "create trigger sertrig_entity_entity before insert on entity for each row execute procedure get_next_entity_entity()"
if sqlca.sqlcode<0 then
	call err_createtables()
end if

end if


whenever error stop

end function







{
function has_prompt_action()
return false
end function

function get_prompt_action()
return  ""
end function
}

################################################################################
function set_curr_db(p_dbname)
define p_dbname char(255)

call set_current_db(p_dbname) returning p_dbname

if p_dbname is null or length(p_dbname)=0 then
        initialize mv_curr_db to null
else
        let p_dbname=check_db(p_dbname)
        let mv_curr_db=p_dbname
end if
call set_pick_db(mv_curr_db)
end function

function has_db()
        if mv_curr_db is null then
                return 0
        else
                return 1
        end if
end function


function get_db()
        if mv_curr_db is null then
                return ""
        else
                return mv_curr_db
        end if
end function



function check_and_report_error()
#define lv_err1 char(255)
#define lv_err2 char(255)
#define lv_isam_err integer
if sqlca.sqlcode>=0 then
        return 0
end if
error "Unable to connect to database"
return 1
end function


function get_version()
define lv_str char(80)

let lv_str="ACL A4GL IDE  Version ",mc_version using "##&.&&"
return lv_str
end function




function middle(s)
define s char(255)
define s1 char(255)
define w integer
define a integer
code
w=A4GL_get_curr_width();
endcode
let a=w-length(s)
let a=a/2
let s1[a,255]=s
return s1
end function

function add_default_setting(lv_name,lv_user,lv_s)
define lv_name char(128)
define lv_user char(8)
define lv_s char(32)
define lv_v char(70)
let lv_v=fgl_getenv(lv_s) 

delete from afglsettings where name=lv_s
insert into afglsettings values(lv_name,lv_user,lv_s,lv_v)

end function



function add_default_settings(lv_name,lv_user)
define lv_name char(128)
define lv_user char(8)

call add_default_setting(lv_name,lv_user,"A4GL_EXE_EXT")
call add_default_setting(lv_name,lv_user,"A4GL_HLP_EXT")
call add_default_setting(lv_name,lv_user,"A4GL_FRM_BASE_EXT")
call add_default_setting(lv_name,lv_user,"A4GL_PACKED_EXT")
call add_default_setting(lv_name,lv_user,"A4GL_XML_EXT")
call add_default_setting(lv_name,lv_user,"A4GL_OBJ_EXT")
call add_default_setting(lv_name,lv_user,"A4GL_FORMTYPE")
call add_default_setting(lv_name,lv_user,"A4GL_PACKER")

if fgl_getenv("A4GL_LEXTYPE")="EC" then
	call add_default_setting(lv_name,lv_user,"A4GL_LEXTYPE")
	call add_default_setting(lv_name,lv_user,"A4GL_LEXDIALECT")
else
	call add_default_setting(lv_name,lv_user,"A4GL_LEXTYPE")
end if

end function

function get_setting(lv_prog,lv_name)
define lv_prog char(128)
define lv_name char(32)
define lv_v char(70)

	select value into lv_v from afglsettings 
	where progname=lv_prog
	and name=lv_name

	if sqlca.sqlcode=100 then
		initialize lv_v to null
		return lv_v
	else
		return lv_v
	end if
end function






# DISPLAY ATs.....

{
function clear_screen_portion()
define lv_y integer
define lv_maxy integer
let lv_maxy=aclfgl_get_curr_height()

set pause mode on

for lv_y=6 to lv_maxy
        display " ","" at lv_y,1
end for

set pause mode off
end function
}


function copyright_banner()

clear screen

if get_use_form() then
	open window w_splash at 1,1 with form "splash"
	sleep 2
	close window w_splash
else
	display middle(get_version()) at 7,1
	call display_to_line(9,middle("(c) 2008 Aubit Computing Ltd"))
	call display_to_line(10,middle("http://www.aubit.com"))
	call display_to_line(13,middle("Latest version available at:"))
	call display_to_line(14,middle("http://aubit4gl.sourceforge.net"))
	call display_to_line(16,middle("Development sponsored by Fabrica de Jabon La Corona "))
	call display_to_line(17,middle("http://www.lacorona.com.mx/"))
	sleep 2 # Splash Screen
	clear screen
end if


end function


{
function display_banner()
define lv_curr_db char(255)
set pause mode on
        display "------------------------------------------------ Press CTRL-W for Help --------" at 4,1
        let lv_curr_db=get_db()
        if lv_curr_db is not null then
                display " ",lv_curr_db clipped," " at 4,25
        end if
set pause mode off

end function
}

function display_to_line (lv_line,lv_str)
define lv_line integer
define lv_str char(512)
display lv_str clipped,"" at lv_line,1
end function

function set_and_display_banner() 
	call display_banner()
end function
