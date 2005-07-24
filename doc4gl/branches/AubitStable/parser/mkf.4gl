{
Make file manupulation tool

It allows user to:

- Populate Doc4GL tables with information in make files:
    - relates target (program/library) to process (module) based on location
    - relates 4gl source file (module) to target (program/library)
    - relates form file to target (program/library)

    Usage: replace your compiler command with mkf program:
        mkf -db-mydbname -i target[.lib] file1.4gl file2.4gl [...] file1.per [...] file1.msg file1.menu library1.lib /some/path/makefile/was/in

- TODO: create make files based on information stored in Doc4GL database


inserts into tables:
p4gl_process p4gl_program p4gl_module p4gl_module_prog p4gl_form_usage(?)

deletes from tables:
p4gl_module_prog p4gl_program

updates tame: none

selects from tables:
p4gl_process p4gl_program p4gl_module p4gl_module_prog p4gl_function function_calls(?)


Current Doc4GL tables count:

p4gl_table_usage=       	9543
p4gl_program=        		449     *
p4gl_process=         		10      *
p4gl_module_prog=       	4123    *
p4gl_module=       			1001    *
p4gl_function=       		3607
p4gl_fun_parameter=      	10345
Other tables are empty or have only one row

}

database maxdev

globals

	define

    system_name char(10), 		#name of the process (directory) target belongs to
    target char(20), 		#target (program or library) name
    target_type smallint,  	#type of the target (program or library)
    ga_libs array [20]  of char(20), #libraries target needs to be linked with
    ga_4gl 	array [100] of char(20), #all 4gl modules (files)
    ga_per  array [500] of char(20), #all per modules
    ga_msg  array [100] of char(20), #all msg modules
	ga_menu	array [100] of char(20), #amm menu modules

    #array counters:
	ga_libs_cnt, ga_4gl_cnt, ga_per_cnt, ga_msg_cnt, ga_menu_cnt smallint,

    #array sizes:
	ga_libs_size, ga_4gl_size, ga_per_size, ga_msg_size, ga_menu_size smallint,

	#run-time settings:
	verbose,insert_data,debug_on,check_unresolved smallint,

    this_package char (64),

	list_cnt smallint,
	pa_list array [200] of record
		calls_module_name char (64)
    end record,

	func_cnt smallint,
	pa_func array [1000] of record
		function_call_id integer,
		function_name char(64),
		calls_func_name char(64),
		scaned smallint,
		exausted smallint,
        calls_module_name char(64)
    end record




end globals


{**
 * Main function
 *
 *}
main
define
	arg_cnt, counter, counter2, argument_len, real_count smallint,
    argument,argument_basename,db char (100),
    argument_ext char(4),
    tmp_status integer

    let this_package = "."

	let arg_cnt=num_args()

	let ga_libs_size =20
	let ga_4gl_size =100
	let ga_per_size =500
	let ga_msg_size =100
	let ga_menu_size =100

	let ga_libs_cnt = 0
	let ga_4gl_cnt = 0
	let ga_per_cnt = 0
	let ga_msg_cnt = 0
	let ga_menu_cnt = 0
    let real_count = 0

    initialize system_name, target, target_type, verbose, insert_data,debug_on to null

    let check_unresolved = false


    #let verbose=true
    #let insert_data = true

    #get name of database to connect to; connect to it:
	initialize db to null
    ##########################
	for counter = 1 to arg_cnt
    ##########################

		let argument = arg_val(counter)
        let argument_len = length(argument)

        if argument matches "-db-*" then
			let db =  argument [5,argument_len]
			display "Connecting to database >", db clipped, "<..."
			database db
            exit for
        end if

    #######
	end for
    #######

    #if database name was not on command line, try default
	if db is null then
        let db = "maxdev"
		whenever error continue
		database db
        let tmp_status = status
		whenever error stop

		if tmp_status <> 0 then
			display "ERROR: database name was not specified (use '-db-dbname' flag)"
    	    exit program 1
        else
            display "WARNING: connected to the default database 'maxdev'"
		end if
    end if


    #process non-databse name parameters:
	##########################
	for counter = 1 to arg_cnt
    ##########################

		let argument = arg_val(counter)
        let argument_len = length(argument)
		let argument_ext = "null"

        #display "argument=",argument clipped

        #skip databse name - we already processed that
		if argument matches "-db-*" then
            continue for
        end if

        case argument
            when "-v" 		#turn on verbose mode
				let verbose=true
                continue for
            when "-i" 		#insert data in Dbdoc database
				let insert_data=true
                continue for
            when "-d" 		#turn on debug mode
				let debug_on=true
                call debug("Debug is now ON")
                continue for
            when "-clean" 	#clean tables we populate in this program and exit
                delete from p4gl_module_prog
				delete from p4gl_program
                display "All Data in tables p4gl_program p4gl_module_prog deleted"
                exit program

            when "-g" 		#generate target info based on functions data
                call generate_target_info()
                exit program

            when "-m"       #create all make files
                call create_makefile()
                exit program
		end case

{
        case argument
            when "-v" #verbose
                call debug("-v what the f...?")
                exit program
			when "-i" #insert data
                call debug("-i what the f...?")
                exit program
			when "-d" #debug
                call debug("-d what the f...?")
                exit program
		end case
}
        #Number of parameters AFTER the flags
        let real_count = real_count + 1

		########################################
		for counter2 = argument_len to 1 step -1
        ########################################
            

            #get argument's (file name) extension and basename
			if
				argument[counter2] = "."
            then
				let argument_ext=argument[counter2+1,argument_len]
                let argument_basename=argument[1,counter2-1]
                exit for
            end if

            #get argument's (file name) path
			if
				argument[counter2] = "/"
            then
                let argument_ext="path"
                let argument_basename=argument[counter2+1,argument_len]
                exit for
            end if
        #######
		end for
        #######

		#determine argument's type based on it's extension
		case argument_ext
			when "null" 		#program name
	            call insert_program(argument)
            when "path" 		#path make file was in
                call insert_path(argument_basename)
            when "per"          #form file
                call insert_per(argument_basename)
            when "4gl"          #4gl source module file
                call insert_4gl(argument_basename)
            when "msg"          #help file
                call insert_msg(argument_basename)
            when "menu" 		#Aubit/Plexus Menu file
                call insert_menu(argument_basename)
            when "lib"          #library file
                if
					real_count = 1
                then    #target is a library itself
                    call insert_lib(argument_basename)
                else    #Library required by this target(program)
                    call insert_depend_lib(argument_basename)
                end if
			otherwise
                display "ERROR: extension >", argument_ext clipped,"< was not recognized"
                exit program (1)
    	end case

    #######
	end for
    #######

    #call debug ("about to call output_all")
    call output_all()

end main


{**
 * Show debugging messages (if debug is on)
 *
 *}
function debug(string)
define string char(200)

    if debug_on then
        display "DEBUG:",string clipped
    end if

end function

{**
 * Insert program (target) name in global variable
 *
 *}
function insert_program(prg_name)
define
    prg_name char(20)

    let target = prg_name
    let target_type = 1

    #chech if this target is already defined in modules table

end function

{**
 * Insert system (process) name in global variable
 *
 *}
function insert_path(path_name)
define
    path_name char(10)

    let system_name = upshift(path_name)

    {
	case system_name
        when "UTILITY"
            let system_name = "UTL" #short code used in Doc4GL proces load (.unl) file
    end case
    }

end function


{**
 * Insert form name in global array
 *
 *}
function insert_per(per_name)
define
    per_name char(20)

    let ga_per_cnt = ga_per_cnt + 1

	if ga_per_cnt > ga_per_size then
        display "ERROR: no space left in per array"
        exit program (3)
		#return
    end if

	let ga_per[ga_per_cnt] = per_name

end function

{**
 * Insert module name in global array
 *
 *}
function insert_4gl(fgl_name)
define
    fgl_name char(20)

    let ga_4gl_cnt = ga_4gl_cnt + 1
    
	if ga_4gl_cnt > ga_4gl_size then
        display "ERROR: no space left in 4gl array"
        exit program (3)
        #return
    end if

	let ga_4gl[ga_4gl_cnt] = fgl_name

end function

{**
 * Insert help message file name in global array
 *
 *}
function insert_msg(msg_name)
define
    msg_name char(20)

    let ga_msg_cnt = ga_msg_cnt + 1

	if ga_msg_cnt > ga_msg_size then
        display "ERROR: no space left in msg array"
        exit program (3)
        #return
    end if

	let ga_msg[ga_msg_cnt] = msg_name

end function

{**
 * Insert menu file name in global array
 *
 *}
function insert_menu(menu_name)
define
    menu_name char(20)

    let ga_menu_cnt = ga_menu_cnt + 1

	if ga_menu_cnt > ga_menu_size then
        display "ERROR: no space left in menu array"
        exit program (3)
        #return
    end if

    let ga_menu[ga_menu_cnt] = menu_name

end function

{**
 * Insert target of type library in global variable
 *
 *}
function insert_lib(lib_name)
define
    lib_name char(20)

    let target = lib_name
    let target_type = 2

    #chech if this target is already defined in modules table


end function


{**
 * Insert library dependency name in global array -
 * Library required by this target(program)
 *}
function insert_depend_lib(lib_name)
define
    lib_name char(20)

    let ga_libs_cnt = ga_libs_cnt + 1

	if ga_libs_cnt > ga_libs_size then
        display "ERROR: no space left in libs array"
        exit program (3)
		#return
    end if

    let ga_libs[ga_libs_cnt] = lib_name

end function


{**
 * call all functions needed to perform data output (db insert or display)
 * actions, from data we stored in global arrays
 *
 *}
function output_all()
define
    target_name_with_ext char(20)

    if target_type = 2 then #target is library
        let target_name_with_ext = target clipped, ".lib"
    else
		let target_name_with_ext = target clipped
	end if

    if insert_data then
        delete from p4gl_module_prog
            where program_name = target_name_with_ext

		delete from p4gl_program
            where program_name = target_name_with_ext

        if verbose then
	        display "Data in tables p4gl_program p4gl_module_prog for target ",
    	        target_name_with_ext clipped,
				" deleted"
        end if

    end if

    call db_process()
    call db_target()
    call db_module()
    call db_form()
    call db_help()
    call db_menu()
    call db_libs()

    if insert_data then
        display "Inserted ", target clipped
    end if


end function


{**
 * perform db insert and/or display of process name
 *
 *}
function db_process()

    if verbose then
	    display "Proces: ",system_name clipped
    end if

    if insert_data then
		select * from p4gl_process
	        where id_process = system_name

	    if
	        status = NOTFOUND
	    then
	        #This is expected to be already inserted by Doc4GL, by loading
            #a process (.unl) file. Therefore, we will just warn if it does not
            #exist already.

            display "WARNING: process ", system_name clipped, " does not exist in process table - ADDING"

			select * from p4gl_process
		        where id_process = "ERP"

		    if
		        status = NOTFOUND
	    	then
                display "ERROR: top-level process 'ERP' does not exist"
                display "Please load process table first, using command:"
                display " fgldoc --process_file=my_process_file.unl"
                exit program 3
            end if


			#-691	Missing key in referenced table for referential constraint
			#constraint-name.


			insert into p4gl_process (id_process,disp_process,den_process,sub_process_of,comments)
	            values (system_name,system_name,system_name,"ERP","")




{
  table p4gl_process (
    id_process char(20) not null primary key,
    disp_process char(20) not null,
    den_process char(64) not null,
    sub_process_of char(20) references p4gl_process(id_process),
    comments varchar(255)
}

	    end if
    end if

end function

{**
 * perform db insert and/or display of target (program or library) name
 *
 *}
function db_target()
define
    target_name_with_ext char(20)

    if target_type = 2 then #target is library
        let target_name_with_ext = target clipped, ".lib"
    else
		let target_name_with_ext = target clipped
	end if


    if verbose then
		display "Target: ", target_name_with_ext clipped
	    case target_type
	        when 1
	            display "Target type: program"
	        when 2
	            display "Target type: library"
	        otherwise
	            display "ERROR"
	    end case
	end if

    if insert_data then

        select * from p4gl_program
            where program_name = target_name_with_ext

        if status = NOTFOUND then
			insert into p4gl_program (program_name, comments)
		        values (target_name_with_ext, "")
        end if


    end if


end function

{**
 * perform db insert and/or display of module (4gl file) name
 *
 *}
function db_module()
define
    counter smallint,
    module_name_with_ext char(20),
    target_name_with_ext char(20)


    if target_type = 2 then
        #target is a library
        let target_name_with_ext = target clipped, ".lib"
    else
		let target_name_with_ext = target clipped
	end if


    if ga_4gl_cnt = 0 then return end if

    if verbose then
		display "Modules:"
    end if

    #############################
	for counter = 1 to ga_4gl_cnt
    #############################

        let module_name_with_ext=ga_4gl[counter] clipped,".4gl"

		if verbose then
			display "    ", module_name_with_ext clipped
        end if

        if insert_data then

			#Doc4gl inserts module names with extension, so we must too:
			select * from p4gl_module
	            where module_name = module_name_with_ext

	        if
				status = NOTFOUND
			then
				#We would expect that this should never happen, but it DOES,
                #since Doc4GL p4gl core dumps or fails in parsing, and does
                #not insert all modules it should...


				#-691	Missing key in referenced table for referential constraint
				#constraint-name.
                select * from p4gl_package
                    where id_package = this_package

                if status = NOTFOUND then
                    insert into p4gl_package (id_package, comments)
                        values (this_package,"Default package - automatically generated")
                    display "WARNING: added default package ", this_package
                end if




				insert into p4gl_module (id_package,module_name,deprecated)
	                values (this_package,module_name_with_ext,"N")



			end if

            #check for cases when make file includes same module twice. SQL
            #will fail with not very usefull constraint violation message, that
            #will not tell us much, so we have to do this manually here
            #FIXME: do a status chech instead if we fail, and then show SQL.

            select * from p4gl_module_prog where
                     program_name = target_name_with_ext
                     and
                     module_name = module_name_with_ext

            if status = NOTFOUND then
		        insert into p4gl_module_prog (program_name, id_package, module_name)
		            values (target_name_with_ext,this_package,module_name_with_ext)
            else
                display "ERROR:", target_name_with_ext clipped, " already has ",module_name_with_ext clipped, " relation"
                exit program (5)

            end if
        end if

    #######
	end for
    #######

end function

{**
 * perform db insert and/or display of form file (per) name
 *
 *}
function db_form()
define
    counter smallint

    if ga_per_cnt = 0 then return end if

    if verbose then
	    display "Forms:"
    end if

	#############################
	for counter = 1 to ga_per_cnt
    #############################
        if verbose then
			display "    ", ga_per[counter] clipped
        end if

        #FIXME: comming from make file, I don't know which module and function is using a form
        #file - only which target is...but I need this info to do the insert!

        #doc4gl will pick this up anyway - any point in doing this? Only for cases
        #when form file name is composed at run-time, or returned by a function,
        #in which cases only way we will know that this program need some form
        #is if it's hard-coded in make file

        if insert_data then
	        #insert into p4gl_form_usage (id_package,module_name,function_name,item_num,form_name)
 			#	values ("","","",null,ga_per[counter])
        end if
    #######
	end for
    #######

end function


{**
 * perform db insert and/or display of help file (msg) name
 *
 *}
function db_help()
define
    counter smallint

    if ga_msg_cnt = 0 then return end if

    if verbose then
		display "Help:"
    end if

    #############################
	for counter = 1 to ga_msg_cnt
    #############################
        if verbose then
			display "    ", ga_msg[counter] clipped
        end if

        #SEE: comment in db_form()

        #FIXME: no table for help files

    #######
	end for
    #######

end function


{**
 * perform db insert and/or display of menu file (menu) name
 *
 *}
function db_menu()
define
    counter smallint

    if ga_menu_cnt = 0 then return end if

    if verbose then
		display "Menus:"
    end if

    ##############################
	for counter = 1 to ga_menu_cnt
    ##############################
        if verbose then
			display "    ", ga_menu[counter] clipped
        end if

        #SEE: comment in db_form()

		#FIXME: no table for menu files

    #######
	end for
    #######


end function

{**
 * perform db insert and/or display of libraries dependencies name
 *
 *}
function db_libs()
define
    counter smallint,
    p_p4gl_module_prog record
        program_name char(64),
        id_package char(64),
        module_name char(64)
    end record,
    module_name_with_ext char(20),
    target_name_with_ext char(20),
    tmp_cnt integer

    if ga_libs_cnt = 0 then return end if

    if target_type = 2 then
        #target is a library
        let target_name_with_ext = target clipped, ".lib"
    else
		let target_name_with_ext = target clipped
	end if

    if verbose then
		display "Libraries:"
    end if

	##############################
	for counter = 1 to ga_libs_cnt
    ##############################

	    let module_name_with_ext=ga_libs[counter] clipped,".lib"

		if verbose then
			display "    ", module_name_with_ext clipped
        end if

        #FIXME: no libraries dependency table - do we really want it?

        #if we have this library modules already, just expand it immediately
        #I can think of no benefit of using libraries like this anyway,
        #and we really need to know which modules are in use by which programs
        #to track function calls, tables ussage, etc.
        select count(*) into tmp_cnt
			from p4gl_module_prog
            	where program_name = module_name_with_ext

        if tmp_cnt > 0 then
            declare lib1 cursor for
                select * from p4gl_module_prog
		            where program_name = module_name_with_ext

            ######################################
			foreach lib1 into p_p4gl_module_prog.*
            ######################################
				#We can skip all constraints checks because we did that when inserting the library itself

				if verbose then
					display "    ", p_p4gl_module_prog.module_name clipped
		        end if

		        if insert_data then
		            #check for cases when make file includes same module twice. SQL
		            #will fail with not very usefull constraint violation message, that
		            #will not tell us much, so we have to do this manually here
		            #FIXME: do a status chech instead if we fail, and then show SQL.

		            select * from p4gl_module_prog where
		                     program_name = target_name_with_ext
		                     and
		                     module_name = p_p4gl_module_prog.module_name

		            if status = NOTFOUND then
				        insert into p4gl_module_prog (program_name, id_package, module_name)
				            values (target_name_with_ext,this_package,p_p4gl_module_prog.module_name)
		            else
		                display "WARNING:", target_name_with_ext clipped,
							" already has ",p_p4gl_module_prog.module_name clipped,
							" relation"
		                #So what? Somebody listed same module more then once by mistake,
                        #or it was duplicated in library...continue
						#exit program (5)
		            end if
		        end if
            ###########
			end foreach
            ###########
            close lib1
            free lib1

            continue for
        end if


        ########################################################################
        #if we don't just insert it - we will expand later when we execute "endrun"

		#if verbose then
			display "    Did not find library"
        #end if

        if insert_data then

			#Doc4gl inserts module names with extension, so we must too:
			select * from p4gl_module
	            where module_name = module_name_with_ext

	        if
				status = NOTFOUND
			then
                #we must insert xxx.lib as a module, because of referential integrity

				select * from p4gl_package
                    where id_package = this_package

                if status = NOTFOUND then
                    insert into p4gl_package (id_package, comments)
                        values (this_package,"Default package - automatically generated")
                    display "WARNING: added default package ", this_package
                end if

				insert into p4gl_module (id_package,module_name,deprecated)
	                values (this_package,module_name_with_ext,"Y") #Yes/No

			end if

            #check for cases when make file includes same module twice. SQL
            #will fail with not very usefull constraint violation message, that
            #will not tell us much, so we have to do this manually here
            #FIXME: do a status chech instead if we fail, and then show SQL.

            select * from p4gl_module_prog where
                     program_name = target_name_with_ext
                     and
                     module_name = module_name_with_ext

            if status = NOTFOUND then
		        insert into p4gl_module_prog (program_name, id_package, module_name)
		            values (target_name_with_ext,this_package,module_name_with_ext)
            else
                display "ERROR:", target_name_with_ext clipped, " already has ",module_name_with_ext clipped, " relation"
                exit program (5)
            end if
        end if

    #######
	end for
    #######


end function

{**
 * Generate target (program,library) info based on functions data
 * Not finished
 *}
function generate_target_info()
define
    r_functions record
        module_name char(64),
        function_type char(1)
    end record,
    counter smallint

	declare c1 cursor for
		select module_name, function_type
            from p4gl_function
	    	    where function_name = "main"
                and function_type = "F"


    let counter = 0

    foreach c1 into r_functions.*

        let counter = counter + 1

		#display
		#	r_functions.module_name clipped, " ",
        #    r_functions.function_type clipped

        call find_target_modules(r_functions.module_name,"main")

    end foreach

    display "total=", counter

	close c1

end function

{**
 * Find all functions called by function passed as parameter
 * Not finished
 *}
{
Andrej Falout wrote:

>Hello Sergio,
>
>I'm trying to make a program that will create program definitions, based on functions data in fgldoc database.
>
>I start from functions "main" and look for modules that define functions called from "main". Then I look for modules
>defining functions called from there, and so on...
>
>I see table holding function's forms usage: p4gl_form_usage
>I see table holding function's database table usage: p4gl_table_usage
>
>But, I do not see the table that holds function calls in the function body;
>
>Looking at HTML code generated by "p4gl -c", I see that the parser DOES record all functions called from an function.
>
>But it looks like this data is not stored in the database, and there is no table for it?
>
>

It was stored in a diferent repository version.
How hard dfo you need this ?.. If hard enough i think that i can do it
in 3 days.

Cheers
Sérgio
}
function find_target_modules(target,p_function_name)
define
	target char(64),
    p_function_name char(50),
    r_function_calls record
        function_name char(50),
        calls_function_name char (50)
    end record

    declare c2 cursor for
        select distinct function_name
			from p4gl_func_calls
                where function_name = p_function_name
                and module_name = target
                and id_package = this_package

    foreach c2 into r_function_calls.*

        display "Function ", p_function_name clipped,
				" in module ", target clipped,
                " calls function ", r_function_calls.calls_function_name clipped

    end foreach

    close c2

    exit program

end function

{**
 *
 *
 *}
function create_makefile()
define
	p_p4gl_function record like p4gl_function.*,
	p_p4gl_function_call record like  p4gl_function_call.*,
    p_p4gl_func_calls record like p4gl_func_calls.*,
    this_func_cnt, cnt, p_call_cnt,all_exausted,has_existing_mkf,
    unresolved_top_cnt, unresolved_cnt, tmp_cnt
        smallint,
    p_program_name,p_id_package
        char(64),
    p_call record
		function_call_id like	 	p4gl_function_call.function_call_id,
        id_package like         p4gl_function_call.id_package,
        module_name like        p4gl_function_call.module_name,
        function_name like         p4gl_function_call.function_name,
        line like         p4gl_function_call.line,
        call_type like        p4gl_function_call.call_type,
        calls_func_name   like      p4gl_func_calls.calls_func_name,
        calls_module_name like         p4gl_func_calls.calls_module_name
    end record

    let unresolved_top_cnt = 0
    let unresolved_top_cnt = 0
    let tmp_cnt = 0

	declare m1 cursor for
        select * from p4gl_function
            where function_name = "main"

    #################################
	foreach m1 into p_p4gl_function.*
    #################################
    #for each function called "main"... (target)

	    #new modules list
		let list_cnt = 0

        let unresolved_cnt=0
        let unresolved_top_cnt=0

		#add module of main function to modules list
		call add_to_list(p_p4gl_function.module_name)

        #See if we have name for this target:
        select program_name into p_program_name
            from p4gl_module_prog
            where id_package = p_p4gl_function.id_package
            and module_name = p_p4gl_function.module_name

        if status = NOTFOUND then
            #we do not have this program in existing make files,
            #we will assume target name is same as module containing MAIN.
            #we know it can't be library since libraries do not have MAIN block
			let p_program_name = p_p4gl_function_call.module_name clipped
            let has_existing_mkf = false
        else
            let has_existing_mkf = true
		end if

        display "========================= ",p_program_name clipped

        #get list of all calls made from this main block
		declare m2 cursor for
            {
			select p4gl_func_calls.* from
				#p4gl_function_call
                p4gl_func_calls, p4gl_function_call
            where p4gl_function_call.id_package = p_p4gl_function.id_package
            and p4gl_function_call.module_name = p_p4gl_function.module_name
            and p4gl_function_call.function_name = p_p4gl_function.function_name #main
            and p4gl_function_call.function_call_id = p4gl_func_calls.function_call_id
            }
			select
			 	p4gl_function_call.function_call_id,
                p4gl_function_call.id_package,
                p4gl_function_call.module_name,
                p4gl_function_call.function_name,
                p4gl_function_call.line,
                p4gl_function_call.call_type,
                p4gl_func_calls.calls_func_name,
                p4gl_func_calls.calls_module_name
			from
			     p4gl_function_call,p4gl_func_calls
			where p4gl_function_call.id_package = p_p4gl_function.id_package
			 and p4gl_function_call.module_name = p_p4gl_function.module_name
			 and p4gl_function_call.function_name = p_p4gl_function.function_name #main only in this case
			 #we want this join to get only associated/resolved calls
             #there is little point persuing unresolved calls since they will not
             #be able to provide module name of called function
			 and p4gl_function_call.function_call_id = p4gl_func_calls.function_call_id

            if check_unresolved then
				#Find out if there are unsresolved calls on top level
				select count(*) into unresolved_top_cnt
				from p4gl_function_call #,p4gl_func_calls
				where p4gl_function_call.id_package = p_p4gl_function.id_package
				 and p4gl_function_call.module_name = p_p4gl_function.module_name
				 and p4gl_function_call.function_name = p_p4gl_function.function_name #main only in this case
				 and p4gl_function_call.function_call_id  not in
					 (select function_call_id from p4gl_func_calls)
            end if

			#new function list
			let func_cnt = 0
			######################################
			#foreach m2 into p_p4gl_function_call.*
            foreach m2 into p_call.*
            ######################################
            #for each function call made in this "main" block...

                if debug_on then
					display "MAIN calls ", p_call.calls_func_name clipped
                end if

                #populate initial function list
				call add_to_func_list(
					p_call.function_call_id,
					p_call.function_name,
                	p_call.calls_func_name,
					p_call.calls_module_name)

           		call add_to_list(p_call.calls_module_name)

                let p_id_package = p_call.id_package

            ###########
            end foreach
            ###########
		    close m2
    		free m2

            if func_cnt = 0 then
                if debug_on then
					display "Main did not make any calls!"
                end if
                #completely possible... do not exit
				#exit program
            end if


            #########
			while 1=1
            #########
            #loop untill all functions are scanned or exausted

                if verbose then
					display "func_cnt = ",func_cnt
                end if

                #prevent counter from expanding while we are in the FOR loop
				let this_func_cnt=func_cnt
                ############################
                for cnt = 1 to this_func_cnt
                ############################
                #for each function call in array...

                if pa_func[cnt].scaned = false then
                #if not already scaned...

                    if debug_on then
						display "looking for calls from function ",
							#pa_func[cnt].function_name clipped
	                        pa_func[cnt].calls_func_name clipped
	                        #," in ",pa_func[cnt].module_name
                    end if

					#get all calls made in function that was called
					declare m3 cursor for
                        {
                        select p4gl_func_calls.* from p4gl_func_calls,p4gl_function_call
                        #where function_call_id = pa_func[cnt].function_call_id
                        where p4gl_function_call.function_call_id = p4gl_func_calls.function_call_id
                        and p4gl_function_call.function_name = pa_func[cnt].calls_func_name
                        }

					select
					 	p4gl_function_call.function_call_id,
		                p4gl_function_call.id_package,
		                p4gl_function_call.module_name,
		                p4gl_function_call.function_name,
		                p4gl_function_call.line,
		                p4gl_function_call.call_type,
		                p4gl_func_calls.calls_func_name,
		                p4gl_func_calls.calls_module_name
					from
					     p4gl_function_call,p4gl_func_calls
					where p4gl_function_call.id_package = p_id_package
					 and p4gl_function_call.module_name = pa_func[cnt].calls_module_name
					 and p4gl_function_call.function_name = pa_func[cnt].calls_func_name
					 #we want this join to get only associated/resolved calls
		             #there is little point persuing unresolved calls since they will not
		             #be able to provide module name of called function
					 and p4gl_function_call.function_call_id = p4gl_func_calls.function_call_id

                    if check_unresolved then
						#count unresolved calls from that calling function
						select count (*) into tmp_cnt
						from p4gl_function_call #,p4gl_func_calls
						where p4gl_function_call.id_package = p_id_package
						 and p4gl_function_call.module_name = pa_func[cnt].calls_module_name
						 and p4gl_function_call.function_name = pa_func[cnt].calls_func_name
						 and p4gl_function_call.function_call_id not in
						 (select function_call_id from p4gl_func_calls)

	                     let unresolved_cnt = unresolved_cnt + tmp_cnt
                    end if

					if debug_on and tmp_cnt > 0 then
						display tmp_cnt using "<<&", " unresolved call(s) from ",
							pa_func[cnt].calls_func_name clipped, " in ",
						    pa_func[cnt].calls_module_name clipped
                    end if

                    let p_call_cnt = 0
					###################################
                    #foreach m3 into p_p4gl_func_calls.*
                    foreach m3 into p_call.*
                    ###################################
                    #for each function call made by this function...
                        let p_call_cnt=p_call_cnt+1

                        {
						display "Function ",pa_func[cnt].calls_func_name clipped,
                            " calls ", p_p4gl_func_calls.calls_func_name clipped,
                            " in ", p_p4gl_func_calls.calls_module_name

						call add_to_func_list(
							p_p4gl_func_calls.function_call_id, #id of the function call made
							pa_func[cnt].function_name,  #name of the function making the call
							p_p4gl_func_calls.calls_func_name #name of the function called
		                	)

						#Add module called function is in to modules list
						call add_to_list(p_p4gl_func_calls.calls_module_name)
                        }

						if debug_on then
							display "Function ",pa_func[cnt].calls_func_name clipped,
	                            " calls ", p_call.calls_func_name clipped,
	                            " in ", p_call.calls_module_name
                        end if

						call add_to_func_list(
							p_call.function_call_id, #id of the function call made
							p_call.function_name,  #name of the function making the call
							p_call.calls_func_name, #name of the function called
	       					p_call.calls_module_name) #name of the module where called function is

						#Add module called function is in to modules list
						call add_to_list(p_call.calls_module_name)



                    ###########
                    end foreach
                    ###########
                    close m3
                    free m3

					let pa_func[cnt].scaned = true
                    if p_call_cnt = 0 then
                        #This function made no calls, therefore it's the dead end
						let pa_func[cnt].exausted = true
                        if debug_on then
							display "Function ",pa_func[cnt].function_name clipped,
    	                        " has no calls to other functions"
                        end if
					end if
                end if #already scanned

				#######
				end for
                #######

				let all_exausted = true

                #######################
                for cnt = 1 to func_cnt
                #######################
                #for each function call in array...
					#check if it's scaned
					if pa_func[cnt].scaned = false then
                        let all_exausted = false
                        if debug_on then
							display "more work to do..."
                        end if
						exit for
                    end if
				#######
				end for
                #######

                if all_exausted then
                    if debug_on then
						display "all exausted"
                    end if
					exit while
                end if

            #########
			end while
            #########

            call output_makefile(p_program_name,has_existing_mkf,unresolved_cnt,unresolved_top_cnt)

#for now, exit after first target make file is assembled
exit foreach


    ###########
	end foreach
    ###########

    close m1
    free m1

end function

{**
 *
 *
 *}
function add_to_list(p_calls_module_name)
define
	p_calls_module_name like p4gl_func_calls.calls_module_name,
    cnt
        smallint


    for cnt = 1 to list_cnt
        if pa_list[cnt].calls_module_name = p_calls_module_name then
            #already have it
			if debug_on then
				display "module ",p_calls_module_name clipped,
    	            " is already on the moduled list"
            end if
			return
        end if
    end for

    if debug_on then
		display "new module ",p_calls_module_name clipped
    end if

    #add it
	let list_cnt = list_cnt + 1
    if list_cnt > 200 then
        display "module list exausted. Stop."
        exit program
    end if

	let pa_list[list_cnt].calls_module_name = p_calls_module_name clipped

end function

{**
 * id of the function call made
 * name of the function making the call
 * name of the function called
 *}
function add_to_func_list(p_function_call_id,p_function_name,p_calls_func_name,p_calls_module_name)
define
    p_function_call_id
        integer,
	p_function_name,p_calls_func_name,p_calls_module_name
        char(64),
    cnt smallint

    {
    if p_function_name = "main" then
        display "ERROR - attempted to add 'main' to function list as caller..."
        exit program
    end if
    }

    if p_calls_func_name = "main" then
        display "ERROR - attempted to add 'main' to function list as called..."
        exit program
    end if

    for cnt = 1 to func_cnt
        if pa_func[func_cnt].calls_func_name=p_calls_func_name then
            #already have this function in the functions list
			if debug_on then
				display "function ",p_calls_func_name clipped,
    	            " is already on the function list"
            end if
			return
        end if
    end for

	if debug_on then
		display "new call from ",p_function_name clipped, " to ", p_calls_func_name clipped
    end if

	#Add new function
	let func_cnt=func_cnt+1

    if func_cnt > 1000 then
        display "function list exausted. Stop."
        exit program
    end if

	let pa_func[func_cnt].function_call_id=p_function_call_id
	let pa_func[func_cnt].function_name=p_function_name
	let pa_func[func_cnt].calls_func_name=p_calls_func_name
	let pa_func[func_cnt].scaned=false
	let pa_func[func_cnt].exausted=false
	let pa_func[func_cnt].calls_module_name = p_calls_module_name

end function


{**
 *
 *
 *
 *}
function output_makefile(p_program_name,has_existing_mkf,unresolved_cnt,unresolved_top_cnt)
define
	cnt,has_existing_mkf,found_it,orig_make_modules_cnt,unresolved_cnt,
	unresolved_top_cnt,ret
    	smallint,
    p_program_name, mkf_file, p_id_process
        char (64),
    run_string
        char (400),
    no_match
        char(1),
    p_p4gl_module_prog record like p4gl_module_prog.*

    for cnt = 1 to func_cnt

		if debug_on then
			display "Function ",
			pa_func[cnt].function_name clipped,
	        " calls ",
			pa_func[cnt].calls_func_name clipped,
	        " in ",
	       	pa_func[cnt].calls_module_name clipped,
			" (",
			pa_func[cnt].scaned using "&",
	        "/",
			pa_func[cnt].exausted using "&",")"
        end if
    end for

    if debug_on then
		display "=============================================== ",
			p_program_name clipped, ".amk"
    end if

    for cnt = 1 to list_cnt
        if has_existing_mkf then
            select * from p4gl_module_prog
                where program_name = p_program_name
                and module_name = pa_list[cnt].calls_module_name
                #and id_package =
            if status = NOTFOUND then
                let no_match = "*"
            else
                let no_match = ""
			end if

        end if

		if debug_on then
			display
			pa_list[cnt].calls_module_name clipped,
        	" ",
			no_match clipped
        end if
    end for

    #check if all modules from existing makefile are listed
	if has_existing_mkf then

        declare x1 cursor for
            select * from p4gl_module_prog
                where program_name = p_program_name
                #and id_package =

		let orig_make_modules_cnt = 0
		foreach x1 into p_p4gl_module_prog.*
        #for each module as per make file

            let orig_make_modules_cnt = orig_make_modules_cnt + 1
		    
			let found_it = false
			for cnt = 1 to list_cnt
            #for each module as we determined

                if pa_list[cnt].calls_module_name = p_p4gl_module_prog.module_name
                then
					let found_it = true
                    exit for
                end if

            end for

            if found_it = false then
				if debug_on then
					display "Module ",p_p4gl_module_prog.module_name clipped,
                    	" is in make file but not on list"
                end if
            end if

        end foreach
    end if

    #When we found module that was not in original make file, this can be
    #an error, but it also can mean that orignal make file used libraries
    #If it's an error, it is not fatal - program will still compile

    #when there is an module in original make file, that we did not detect,
    #it can be an error (due to unresolved call or maybe even complete module
    #failed to parse because p4gl choked) or it can mean that originam make file
    #had redundant module in it.

	display "Original makefile has ",orig_make_modules_cnt using "<<&",
        " modules, created makefile has ",list_cnt using "<<&",
        " modules."

    if check_unresolved then
		let cnt = unresolved_cnt + unresolved_top_cnt
		display "Total ",
	            cnt using "<<&",
	            " unresolved calls (",
				unresolved_cnt using "<<&",
				"/",
				unresolved_top_cnt using "<<&",")"
    else
	    #for testing:
		let cnt = 0
    end if

	if cnt>0 then
        display "Make file would probably be invalid - will not create"
    else

        #There is no path in p4gl_module
        #get process of MAIN block
        select id_process into p_id_process
           from p4gl_fun_process
           where id_package = "."
           and module_name = pa_list[1].calls_module_name
           and function_name = "main"

        let mkf_file = "/opt/aubit/apps/erp/src/",
			downshift(p_id_process) clipped,"/"

        #check if that path exists
        let run_string ="ls ",mkf_file clipped," > /dev/null 2>&1"
        run run_string returning ret

        if ret then
            display "ERROR: directory ",mkf_file," does not exist - wil not create makefile"
            return
		end if

        let mkf_file = mkf_file clipped,p_program_name clipped,".amk"

{
TODO - we can probably speed-up stuff if we acouid multiple calls to same function
IN THE WHOLE MODULE - there is no way on earth they would leed to a different
called function....

same when resolving function calls in loadform.4gl - when you get one resolved,
just point the remaining calls in that module to the same destination function
}

		start report rep_mkf to mkf_file
        output to report rep_mkf(p_program_name)
        finish report rep_mkf
        display "Make file ",mkf_file clipped," created."

        let mkf_file = "less ",mkf_file clipped
        #run mkf_file

	end if


end function


{**
 *
 *
 *
 *}
report rep_mkf(p_program_name)
define
    p_program_name
        char (64),
    cnt
        smallint

OUTPUT

	LEFT MARGIN 0
	TOP MARGIN 0
	BOTTOM MARGIN 0
	#PAGE LENGTH 65
    PAGE LENGTH 5 #1

FORMAT

	#################
	FIRST PAGE HEADER
	#################

    print "PROG		= ",p_program_name clipped

	#FIXME: this will actually be MAIN module, not GLOBALS
	print "GLOBALS.4gl	= ",pa_list[1].calls_module_name clipped


	print "FILES.4gl	= \\"

	print "		${GLOBALS.4gl} \\"


	############
	ON EVERY ROW
	############

		for cnt = 2 to list_cnt
	        print
    	    "		",pa_list[cnt].calls_module_name clipped, " \\"
        end for

	###########
	ON LAST ROW
	###########

#TODO get forms/help files ussage
#todo when all is working, clean existing data in p4gl_module_prog and insert new one.

        print ""
		print "FILES.per	= ${ALLFORMS.per}"
        print ""

end report


# ================================== EOF ===============================

