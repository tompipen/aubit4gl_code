
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
	verbose,insert_data,debug_on smallint

end globals


{**
 * Main function
 *
 *}
main
define
	arg_cnt, counter, counter2, argument_len, real_count smallint,
    argument,argument_basename char (100),
    argument_ext char(4)

    database maxdevdoc

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

    #let verbose=true
    #let insert_data = true

    ##########################
	for counter = 1 to arg_cnt
    ##########################

		let argument = arg_val(counter)
        let argument_len = length(argument)
		let argument_ext = "null"

        #display "argument=",argument clipped

        case argument
            when "-v" #verbose
				let verbose=true
                continue for
            when "-i" #insert data
				let insert_data=true
                continue for
            when "-d" #debug
				let debug_on=true
                call debug("Debug is now ON")
                continue for
            when "-clean"
                delete from p4gl_module_prog
				delete from p4gl_program
                display "Data in tables program module_prog deleted"
                exit program

            when "-g" #generate target info based on functions data
                call generate_target_info()
                exit program

		end case


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

        let real_count = real_count + 1


		########################################
		for counter2 = argument_len to 1 step -1
        ########################################
            if
				argument[counter2] = "."
            then
                let argument_ext=argument[counter2+1,argument_len]
                let argument_basename=argument[1,counter2-1]
                exit for
            end if

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

		case argument_ext

			when "null" 	#program name
	            call insert_program(argument)
            when "path" #path make file was in
                call insert_path(argument_basename)
            when "per"
                call insert_per(argument_basename)
            when "4gl"
                call insert_4gl(argument_basename)
            when "msg"
                call insert_msg(argument_basename)
            when "menu" #Aubit/Plexus Menu file
                call insert_menu(argument_basename)
            when "lib"
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
 * call all functions needed to perform data output (db insert or display) actions
 *
 *}
function output_all()

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

            display "WARNING: process ", system_name clipped, " does not exist in process table - ADDED"

			insert into p4gl_process (id_process,disp_process,den_process,sub_process_of,comments)
	            values (system_name,system_name,system_name,"ERP","")

{
  $rv = $obj->execSql(qq/create table p4gl_process (
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


    if target_type = 2 then
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

				insert into p4gl_module (id_package,module_name,deprecated)
	                values (".",module_name_with_ext,"N")



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
		            values (target_name_with_ext,".",module_name_with_ext)
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
    counter smallint

    if ga_libs_cnt = 0 then return end if

    if verbose then
		display "Libraries:"
    end if

	##############################
	for counter = 1 to ga_libs_cnt
    ##############################
        if verbose then
			display "    ", ga_libs[counter] clipped
        end if

        #FIXME: no libraries dependency table

    #######
	end for
    #######


end function


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

function find_target_modules(target,p_function_name)
define
	target char(64),
    p_function_name char(50),
    r_function_calls record
        function_name char(50)
    end record


    declare c2 cursor for
        select unique function_name
            from function_calls
                where function_name = p_function_name
                and module_name = target

    foreach c2 into r_function_calls.*

        display "Function ", p_function_name clipped, 
				" in module ", target clipped,
                " calls function ", r_function_calls.function_name clipped

    end foreach

    close c2

    exit program

end function

# ================================== EOF ===============================

