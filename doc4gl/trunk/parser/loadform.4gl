{**
 * This program performs folowing functions:
 *
 * - Loads form file attibutes extracted using Aubit fcompile in databse
 *
 * - Processes loaded data to establish relatinshops between form, table, clumn,
 *   and stores all data in appropriate Doc4GL/DBdoc tables
 *
 * - Interactive mode
 *
 * - cnt, clean, fixup, endrun
 *
 *
 *
 *
 *
 *
 *
 * Inserts into tables:
 *
 *	dd_temp
 *	p4gl_form_attribute_type
 *	p4gl_form
 *	p4gl_form_process
 *	systableext
 *	syscolumnext
 *	p4gl_form_table
 *	p4gl_form_column
 *	p4gl_table_process
 *	p4gl_form_attribute
 *	p4gl_column_process
 *
 *
 *}

{
 *
 * this allows DEFINE LIKE to be used without causing attempt to connect to this
 * database at run-time, but will work only with 4Js and Aubit.
 * replace with DATABASE stmt if you need to
 *
 *}
#schema maxdev
database maxdev

define
	p_p4gl_form record like p4gl_form.*,
	p_p4gl_process record like p4gl_process.*,
    p_p4gl_form_column record like p4gl_form_column.*,
    p_p4gl_table_process record like p4gl_table_process.*,
	p_p4gl_form_table record like p4gl_form_table.*,
	p_p4gl_function_call record like p4gl_function_call.*,
	p_p4gl_function record like p4gl_function.*,
	p_p4gl_module_prog record like p4gl_module_prog.*,
	p_systableext record like systableext.*,
	p_syscolumnext record like syscolumnext.*,

	l_fname, do_one_form char(264),
    debug, debug2, warnings, verbose, interactive,do_insert
        smallint,
    hush
        char(1),
	reason_1,reason_2,reason_3,reason_4,reason_5,reason_6,reason_7,
    exit_on_error, insert_disabled
        smallint


{**
 * Main function
 *
 *}
####
main
####
define
	type, uid, pwd, db char (20)

    let debug = true    	#show debugging messages
    let debug2 = true      #additional deep debugging messages
    let warnings = true     #show warning messages
    let verbose = false     #show details of what you are doing
    let exit_on_error = true #Exit if error occured
    let hush = ""
    #let hush = "#"

	initialize do_one_form to null

	if num_args() >= 5 then
		let l_fname=arg_val(1)
		let uid=arg_val(2)
		let pwd=arg_val(3)
		let db=arg_val(4)
		let type=arg_val(5)

		if num_args() = 6 then
            let do_one_form=arg_val(6)
        end if

		#OPEN SESSION s_ifmx TO DATABASE maxdev as user "informix" password "ifmx"
        #OPEN SESSION s_ifmx TO DATABASE db as user uid password pwd
		#SET SESSION TO s_ifmx
		database db
	    display "Connected to the database."

        let interactive = false

        case type
            when "dd"
                call load_dd()  #Load .unl file with form files attributes into temp table
            when "ddp"
                call process_dd()   #normalise data loaded with load_dd()
			when "cnt"
				call count_data()   #Show row counts for relevant tables
            when "clean"
                call clean() #remove all data from relevant tables
            when "fixup"
				call flag_ext_tables() #flag tables we know are used, but not by this code
                call fixup() #see if we can find references to remaining non-registered tables
				call drop_obsolete() #drop tables marked obsolete
            when "endrun"
				call expand_libs()      #add modules specified by library to modules associated with target using the library
				call function_calls()   #For each function call registeres by p4gl, find function/module called
			otherwise
                display "ERROR: unknown type"
				call show_usage()
                exit program (2)
        end case

		#CLOSE SESSION s_ifmx
        close database

	else #less tehn 5 parameters on the command line
       case arg_val(1)
		when "interactive"  #Interactive mode - show menu of interactive options
	        let interactive = true
			let db = "maxdev"
			database db
			call main_menu()
		when "clean"  #se above - synonim
    		let db = "maxdev"
			database db
            call clean()
		when "cnt"  #see above - synonim
    		let db = "maxdev"
			database db
			call count_data()
	   otherwise
           call show_usage()
		   exit program (2)
       end case
	end if

end main


{**
 * Show program's usage parameters
 *
 *}
function show_usage()

		   display "Usage:"
		   display "loadmap file_name uid pwd db [dd|ddp|clean|cnt|fixup|endrun]"
		   display "loadmap [interactive|clean|cnt]"
		   display ""


end function


{**
 * Get base name of the file out of the full path
 *
 *}
function my_basename(buff)
define
    buff, base_name
        char (300),
    buff_length, pos
        smallint

	let buff_length=length (buff)

	for pos=buff_length to 1 step -1
    	if buff[pos]="/" then
            let base_name= buff[pos+1,buff_length]
            return base_name
        end if
	end for

    return buff
end function

{**
 * Strip (remove) specified string out of the string
 *
 *}
function strip(buff,strip_it)
 define
	buff, strip_it, match_it,stripped
        char (300),
    buff_length, pos,strip_length
        smallint

	let buff_length=length (buff)
	let strip_length=length (strip_it)

    let match_it = strip_it clipped,"*"

	if buff matches match_it then
        let stripped = buff[strip_length+1,buff_length]
        return stripped
	end if

    return buff

end function

{**
 * Clean all Doc4GL tables populated by any tool (p4gl,mkf,loadform,fgldoc)
 *
 *}
function clean()

				delete from p4gl_form_process
				delete from p4gl_form_table
				delete from p4gl_form_column
				delete from p4gl_form_attribute
				delete from p4gl_form
				delete from p4gl_table_process
				delete from p4gl_column_process
				delete from syscolumnext

				delete from p4gl_table_usage #populated by p4gl

				delete from systableext

				delete from p4gl_function_call #populated by p4gl
				delete from p4gl_fun_parameter #populated by plgl

				delete from p4gl_fun_todo
				delete from p4gl_fun_return
				delete from p4gl_fun_process


				delete from p4gl_function #populated by p4gl
				delete from p4gl_module_prog    #populated by mkf
				delete from p4gl_module #populated by p4gl
				delete from p4gl_program        #populated by mkf

				#don't clean p4gl_process
				#don't clean p4gl_package

				display "Cleaned tables."

end function

{**
 * Main menu for interactive mode
 *
 *}
function main_menu()

    menu "loadform"
        command "Reports"

            menu "Reports"

                command "Tables" "Tables reports"

					menu "Tables"
    					command "1Tables by process" "Tables listed alphabeticaly, with all processes they belong to"
		                    call rep_table_process()

		                command "2Process/table" "Tables grouped by process"
		                    call rep_process_table()

		                command "4Unused" "Tables not referenced by 4gl or per files"
		                    call rep_unused_tables()

						command "exit" "Exit program"
				            exit menu
                    end menu

                command "Modules" "Modules reports"

                    menu "Modules"
						command "3Unused" "TODO-Modules not referenced by make files"

						command "exit" "Exit program"
				            exit menu
                    end menu

				command "exit" "Exit program"
		            exit menu
            end menu

        command "Utility"

			menu "Utility"
                command "Drop obsolete" "Drop all tables marked obsolete"
                    call drop_obsolete()

                command "Fix-up" "Add tables flaged with @table tag to systableext"
 					#Needed because p4gl core dumps...
					call flag_ext_tables()
                    call fixup()

				command "exit" "Exit program"
		            exit menu
            end menu

		command "exit" "Exit program"
            exit menu
    end menu

end function

{**
 * Drop all tables marked obsolete from database
 *
 *
 *}
function drop_obsolete()
define
    p_tabname like systableext.tabname


    declare rd1 cursor for
	select tabname
        from systableext
            where tabname not matches "p4gl_*"
            and tabtype = "O" #Doc4GL table types are T=table V=view U=undefined E=tEmporary O=obsolete
            and tabname in (select tabname from systables)

    #######################################
	foreach rd1 into p_systableext.tabname
    #######################################


		display "drop table ",p_systableext.tabname clipped, ";"
        let p_tabname = p_systableext.tabname
#		drop table p_tabname
        drop table p_systableext.tabname
#        drop table p_systableext.tabname
#|_______________________________^
#| Error at line 318, character 33
#| syntax error, unexpected NUMBER_VALUE (.)

    ###########
	end foreach
    ###########


end function


#

{**
 * Some tables are used by code external to our current source code tree-like
 * ASP framework.
 * We will insert them into systableext as 'X'
 *}
function flag_ext_tables()

whenever error continue

	insert into systableext (owner,tabname,tabtype)
		values ("root","asp_activate","X")
			#Doc4GL table types are T=table V=view U=undefined E=tEmporary O=obsolete X=external

	insert into systableext (owner,tabname,tabtype)
		values ("root","asp_connect","X")

	insert into systableext (owner,tabname,tabtype)
		values ("root","asp_pref","X")

	insert into systableext (owner,tabname,tabtype)
		values ("root","asp_contract","X")

whenever error stop

end function



{**
 * Tables listed alphabeticaly, with all processes they belong to
 *
 *}
function rep_table_process()
define
    all_process,report_file,run_string
        char(200),
    total_tables,process_tables
        smallint
{
		declare r1 cursor for
			select id_process, tabname
        	from p4gl_table_process
	#        group by id_process,tabname
			order by id_process, tabname

        start report table_process

        foreach r1 into p_p4gl_table_process.id_process,p_p4gl_table_process.tabname

			declare r1 cursor for
			select count (*), tabname
        		from p4gl_table_process
                where tabname = p_p4gl_table_process.tabname
		        group by tabname
		        having count (*) > 1
        end foreach
}

    let report_file="table_by_process.txt"

    start report table_process to report_file

	select count(*) into total_tables
        from systables
            where tabid > 100
            and tabname not matches "p4gl_*"


    #deduct Doc4GL/DBdoc tables not prefixed with p4gl_ + dd_temp
	let total_tables = total_tables - 11


	let process_tables = 0

    declare r1 cursor for
        select distinct tabname
            from p4gl_table_process
                order by tabname


    foreach r1 into p_p4gl_table_process.tabname

		let process_tables = process_tables + 1

	    declare r2 cursor for
            select id_process
                from p4gl_table_process
                    where tabname = p_p4gl_table_process.tabname
                        order by id_process

        let all_process=""
        foreach r2 into p_p4gl_table_process.id_process
            let all_process=all_process clipped, " ",p_p4gl_table_process.id_process
		end foreach

        output to report table_process(p_p4gl_table_process.tabname,all_process,total_tables,process_tables)


    end foreach

    finish report table_process

    error report_file clipped, " created."
    let run_string= "less ",report_file
    run run_string



end function

{**
 *  Tables listed alphabeticaly, with all processes they belong to
 *
 *}
REPORT table_process(tabname,all_process,total_tables,process_tables)

define
	tabname like p4gl_table_process.tabname,
	all_process
        char (200),
    total_tables,process_tables
        smallint
OUTPUT

	LEFT MARGIN 0
	TOP MARGIN 0
	BOTTOM MARGIN 0
	PAGE LENGTH 65

FORMAT

	#################
	FIRST PAGE HEADER
	#################


		PRINT
	"_________________________________________________________________"
		PRINT
	"Table name                       PROCESSES  ."
	#account                          GL
		PRINT
	"_________________________________________________________________"


	############
	ON EVERY ROW
	############
        print
            tabname,
            all_process clipped



	###########
	ON LAST ROW
	###########

		PRINT
	"_________________________________________________________________"


        print
            "total tables in db:",total_tables using "<<<<"

		PRINT
	"_________________________________________________________________"


END REPORT

{**
 * Tables grouped by process
 *
 *}
function rep_process_table()
define
    all_process,report_file,run_string,disp_process
        char(200),
    total_tables,process_tables,this_process_ref_form,process_ref_form,
    process_ref_module,
	total_mod_refs,total_form_refs,total_refs,this_process_ref_module,
    proc_cnt
        smallint,
    tmp_id_process,root_process
        char(20),
    p_tabtype
        char(1)

    let report_file="process_table.txt"

    start report process_table to report_file

	select count(*) into total_tables
        from systables
            where tabid > 100
            and tabname not matches "p4gl_*"

    #deduct Doc4GL/DBdoc tables not prefixed with p4gl_ + dd_temp
	let total_tables = total_tables - 11

	select count(distinct tabname) into process_tables
		from p4gl_table_process


    #get root process
    let root_process = "ERP"


    declare r3 cursor for
        select distinct id_process
            from p4gl_process
            #where id_process <> "common"
            #where sub_process_of = root_process  TODO?
				order by id_process

    let proc_cnt=0
	############################################
	foreach r3 into p_p4gl_process.id_process
	############################################
	    #For each (first level?) process...

        display "Scanning process ",p_p4gl_process.id_process clipped, "..."

        select p4gl_process.disp_process into disp_process
            from p4gl_process
                where id_process = p_p4gl_process.id_process

	    let proc_cnt=proc_cnt + 1

        {
		if proc_cnt = 2 then
            exit foreach
        end if
        }

		declare r4 cursor for
            select 
				#distinct tabname
                *
                from p4gl_table_process
                    where id_process = p_p4gl_process.id_process
                    and owner matches "*" #TODO?
                        order by tabname

	    ############################################
		foreach r4 into p_p4gl_table_process.* #p_p4gl_table_process.tabname
	    ############################################
			#...find all tables assigned to this process...

			#Doc4GL table types are T=table V=view U=undefined E=tEmporary O=obsolete
			select tabtype into p_tabtype
                from systableext
	                where tabname = p_p4gl_table_process.tabname
                    and owner = p_p4gl_table_process.owner	#"root"

{

who is stuffing "unknown" on tables that exist ????

chech that this does not happen any more - maybe it was a bug

owner     unknown
tabname   vendor
extowner
tabalias
remarks
tabtype   U

owner     root
tabname   vendor
extowner
tabalias
remarks
tabtype

owner     unknown
tabname   customer
extowner
tabalias
remarks
tabtype   U

owner     root
tabname   customer
extowner
tabalias
remarks
tabtype



}
			if p_tabtype = "T" or (length(p_tabtype)=0) then
                let p_tabtype = ""
			end if

			#if p_p4gl_table_process.tabname <> "addcharge" then continue foreach end if

			#let process_tables = process_tables + 1

            #number of references to this table in forms of this process
			select count(*) into this_process_ref_form
				from p4gl_form_table, p4gl_form_process
                where p4gl_form_table.tabname = p_p4gl_table_process.tabname
                and p4gl_form_process.id_process = p_p4gl_process.id_process
                and p4gl_form_process.form_id = p4gl_form_table.form_id

            #Number of references to this table in modules of this process
			select count(*) into this_process_ref_module
				from p4gl_table_usage, p4gl_fun_process
                where p4gl_table_usage.tabname = p_p4gl_table_process.tabname
                and p4gl_fun_process.id_process = p_p4gl_process.id_process
                and p4gl_fun_process.function_name = p4gl_table_usage.function_name
                and p4gl_fun_process.module_name = p4gl_table_usage.module_name

			#display "this_process_ref_form=",this_process_ref_form
			#display "this_process_ref_module=",this_process_ref_module


		    declare r5 cursor for
            select id_process
                from p4gl_table_process
                    where tabname = p_p4gl_table_process.tabname
                    and id_process <> p_p4gl_process.id_process
						order by id_process

	        let all_process=""
            let total_mod_refs=0
   	        let total_form_refs=0
			let process_ref_form=0
			let process_ref_module=0

			##############################
			foreach r5 into tmp_id_process
            ##############################
                #and for all OTHER table/process relations of this table (not THIS one)

				#number of references to this table in forms of this process
				select count(*) into process_ref_form
					from p4gl_form_table, p4gl_form_process
        	        where p4gl_form_table.tabname = p_p4gl_table_process.tabname
            	    and p4gl_form_process.id_process = tmp_id_process
					and p4gl_form_process.form_id = p4gl_form_table.form_id

	            #Number of references to this table in modules of this process
				select count(*) into process_ref_module
					from p4gl_table_usage, p4gl_fun_process
	                where p4gl_table_usage.tabname = p_p4gl_table_process.tabname
	                and p4gl_fun_process.id_process = p_p4gl_process.id_process
	                and p4gl_fun_process.function_name = p4gl_table_usage.function_name
	                and p4gl_fun_process.module_name = p4gl_table_usage.module_name


				#display tmp_id_process clipped, " process_ref_form=",process_ref_form
				#display tmp_id_process clipped, " process_ref_module=",process_ref_module

				#Add this process counts to total count
				let total_mod_refs=total_mod_refs+process_ref_module
    	        let total_form_refs=total_form_refs+process_ref_form

		        let all_process=all_process clipped, " ",tmp_id_process clipped,
					"(",
					process_ref_form using "<<<<&","/",
					process_ref_module using "<<<<&",
					")"

			###########
			end foreach
            ###########

            #add group process counts to total count
			let total_mod_refs=total_mod_refs+this_process_ref_module
   	        let total_form_refs=total_form_refs+this_process_ref_form
   	        let total_refs=total_form_refs+total_mod_refs

			#display ">>>>>>total_mod_refs=",total_mod_refs
			#display ">>>>>>total_form_refs=",total_form_refs
			#display "======total_refs=",total_refs

			output to report process_table(p_p4gl_table_process.tabname,
							p_p4gl_process.id_process,total_tables,
							process_tables,all_process,this_process_ref_form,
							total_mod_refs,total_form_refs,total_refs,
							this_process_ref_module,disp_process,p_tabtype
							)
		###########
		end foreach
        ###########
    ###########
    end foreach
    ###########

    finish report process_table

    error report_file clipped, " created."
    let run_string= "less ",report_file
    run run_string


end function

{**
 * Tables grouped by process
 *
 *}
REPORT process_table(tabname,id_process,total_tables,process_tables,all_process,
	this_process_ref_form,total_mod_refs,total_form_refs,total_refs,
	this_process_ref_module,disp_process,p_tabtype)

define
	tabname like p4gl_table_process.tabname,
	id_process like p4gl_process.id_process,
    total_tables,process_tables,this_process_ref_form,group_cnt,
	total_mod_refs,total_form_refs,total_refs,this_process_ref_module,
    sum_total_refs,sum_total_form_refs,sum_total_mod_refs,
	all_form_refs,all_mod_refs
        smallint,
   	all_process,disp_process
		char (200),
    p_tabtype
        char (1)

OUTPUT

	LEFT MARGIN 0
	TOP MARGIN 0
	BOTTOM MARGIN 0
	PAGE LENGTH 65

FORMAT

	#################
	FIRST PAGE HEADER
	#################

	let all_form_refs = 0
	let all_mod_refs = 0



		PRINT
	"_________________________________________________________________"

        print
	"Table Name         |Tot.ref.(form/module)"

		print
	"   TABTYPE         |This proc(form/module) |...other proc...(forms/modules)"


        print
	"Doc4GL table types are: T=table V=view U=undefined E=tEmporary O=obsolete"
		PRINT
	"_________________________________________________________________"



    ##########################
	before group of id_process
    ##########################
        print
		"_________________________________________________________________"
        print
			"                       ",id_process clipped, " tables"
        print column 10, disp_process clipped

		PRINT
		"_________________________________________________________________"

        let group_cnt = 0
        let sum_total_refs = 0
		let sum_total_form_refs = 0
		let sum_total_mod_refs = 0


	############
	ON EVERY ROW
	############


		print tabname clipped,
            column 20,
			total_refs
			using "<<<&"
			,"(",
			total_form_refs
			using "<<<&"
			,"/",
			total_mod_refs
			using "<<<&"
			,")"

		print
            #tabname ,
            column 4,
			p_tabtype clipped,
            column 20,
            id_process clipped,
			#this_process_ref_form + this_process_ref_module using "<<<#",
			"(",
			this_process_ref_form using "<<<&",
            "/",this_process_ref_module using "<<<&",")",
            column 17,
			all_process clipped

        let sum_total_refs=sum_total_refs+total_refs
		let sum_total_form_refs = sum_total_form_refs +  total_form_refs
		let sum_total_mod_refs = sum_total_mod_refs + total_mod_refs
        let group_cnt = group_cnt + 1

    ##########################
	after group of id_process
    ##########################

        skip 1 line
        print "Total tables in process: ",
			group_cnt
			using "<<<&"
        print "Total process references: ", sum_total_refs
			using "<<<&"
			,"(",
            sum_total_form_refs
			using "<<<&"
			,"/",
            sum_total_mod_refs
			using "<<<&"
			,")"

        let all_form_refs=all_form_refs+sum_total_form_refs
        let all_mod_refs=all_mod_refs+sum_total_mod_refs

		skip 1 line
	###########
	ON LAST ROW
	###########

		PRINT
	"____________________________________________________________________________"

    print "Total form references (inc multiple listed tables):",all_form_refs
    print "Total mod. references (inc multiple listed tables):",all_mod_refs
    skip 1 line

    print " NOTE: table is listed under every process it is associated with"


{
        print
            "This application's total tables in db: ",total_tables using "<<<&"


		print
            "tables related/unrelated to process: ",
			process_tables
			using "<<<<"
			,"/",total_tables-process_tables <<<<<< wrong
			# using "<<<<"
			,"(",((total_tables*100)/process_tables)
			# using "<<<<"
			,"%)"
}
		PRINT
	"___________________________________________________________________________"


END REPORT

{**
 * Tables not referenced by 4gl or per files
 *
 *}
function rep_unused_tables()
define
    all_process,report_file,run_string,module_basename,run_string2
        char(400),
    total_tables,total_doc4gl_tables,total_missing_tables,
	tables_with_process,tables_with_function,tables_with_form,
	cnt_process,cnt_function,cnt_form,tmp_stat,found_in_4gl,found_in_per,tmp_cnt,
    counter,obsoleted,total_obsolete_tables,p4gl_parse_error,total_p4gl_parse_error,
    brute_force, output_counter,total_not_exist,total_obsolete_not_removed,
    is_formonly,found_in_tag, buff_length, pos
        smallint,
    tmp_id_process, process
        char(10),
    msg_txt char (180),
    oc char(2)

    let obsoleted = 0
    let total_p4gl_parse_error=0
	let report_file="unused_tables.txt"
    let oc="{}"

    start report unused_tables to report_file

	select count(*) into total_tables
        from systables
            where tabid > 100
            and tabname not matches "p4gl_*"

    #deduct Doc4GL/DBdoc tables not prefixed with p4gl_ + dd_temp
	let total_tables = total_tables - 11


    select count (distinct tabname) into tables_with_process
        from p4gl_table_process

    select count (distinct tabname) into tables_with_function
        from p4gl_table_usage

    select count (distinct tabname) into tables_with_form
		from p4gl_form_table


	select count(*) into total_doc4gl_tables
        from systableext
            where tabname not matches "p4gl_*"

	select count(*) into total_missing_tables
        from systableext
            where tabname not matches "p4gl_*"
            and tabtype = "U"
			#Doc4GL table types are T=table V=view U=undefined E=tEmporary O=obsolete X=external

	select count(*) into total_obsolete_tables
        from systableext
            where tabname not matches "p4gl_*"
            and tabtype = "O"

	select count(*) into total_obsolete_not_removed
        from systableext
            where tabname not matches "p4gl_*"
            and tabtype = "O"
            and tabname in (select tabname from systables)

	select count(*) into total_not_exist from systableext
		where tabname not in (select tabname from systables)

	declare r6 cursor for
		select tabname from systables
			where tabname not in (select tabname from systableext)
			and tabname not matches "p4gl_*"
			and tabid > 100                                         #348-11=337
	        and tabname <> "dd_temp"
	        and tabname <> "process"
	        and tabname <> "ext_table"
	        and tabname <> "ext_database"
	        and tabname <> "ext_column"
	        and tabname <> "table_process"
	        and tabname <> "sysmodules"
	        and tabname <> "d_modulos"
	        and tabname <> "d_mod_tab"
	        and tabname <> "systableext"
	        and tabname <> "syscolumnext"
	            order by tabname


	whenever error continue
        select count(*) into tmp_stat from dd_temp
        let tmp_stat=status
	whenever error stop

    if tmp_stat <> 0 then
            #display "Creating table dd_temp"
			#create table dd_temp (load_field char (300))
    else
	       #display "Cleaning dd_temp table  ."
		   #delete from dd_temp
           drop table dd_temp
    end if

    #must drop/create table every time to maintain line order
	display "Creating table dd_temp"
	create table dd_temp (load_field char (300))

    let counter = 0
    let output_counter = 0
    #######################################
	foreach r6 into p_systableext.tabname
    #######################################
        let counter = counter + 1

{
		if counter = 40 then
            exit foreach
        end if

        if output_counter = 5 then
            exit foreach
        end if
}

		display p_systableext.tabname clipped

        select count(*) into cnt_process
            from p4gl_table_process
                where tabname = p_systableext.tabname

        select count(*) into cnt_function
            from p4gl_table_usage
                where tabname = p_systableext.tabname

        select count(*) into cnt_form
            from p4gl_form_table
                where tabname = p_systableext.tabname



{
    grep flags:

	    #-l just file name where found
    	#-H filename and line in which found
        # -i, --ignore-case

		-E, --extended-regexp
              Interpret PATTERN as an extended regular expression
              (see below).

       	-e PATTERN, --regexp=PATTERN
              Use  PATTERN as the pattern; useful to protect pat­
              terns beginning with -.

		-n, --line-number

		-w, --word-regexp
              Select  only  those  lines  containing matches that
              form whole words.  The test is  that  the  matching
              substring  must  either  be at the beginning of the
              line, or preceded by a non-word constituent charac­
              ter.   Similarly,  it  must be either at the end of
              the line or  followed  by  a  non-word  constituent
              character.   Word-constituent  characters  are let­
              ters, digits, and the underscore.

		-x, --line-regexp
              Select only those matches that  exactly  match  the
              whole line.


        -F, --fixed-strings
              Interpret PATTERN as a list of fixed strings, sepa­
              rated by newlines, any of which is to be matched.

			grep  -l -i "accumulator\|andrej" *.per

}


        #################################################
        #       4gl files
        #################################################


		#Todo: how to avoid searching comment lines?

		let run_string= "find /opt/aubit/apps/erp/src -name '*.4gl' -exec grep -l -i ",
			"'from ",p_systableext.tabname clipped,"\\|",   #delete / select "from x"
			"into ",p_systableext.tabname clipped,"\\|",    #insert "into x"
			"like ",p_systableext.tabname clipped,"\\.\\|", #define ... "like x."
			"update ",p_systableext.tabname clipped,        #"update x"
															#TODO:   create table x
															#TODO:   create unique index zzz on x (...)
			"' ",oc," \\; > tmp.unl"


#		display run_string clipped
		run run_string
	    delete from dd_temp
		load from "tmp.unl" insert into dd_temp

		if status <> 0 then
			display "error loading"
			exit program 1
		end if

		select count(*) into found_in_4gl from dd_temp
		if found_in_4gl = 0 then
            #did not find anything the "smart" way, do a brute-force find
			#display "looking for 4gl brute-force"
			let run_string= "find /opt/aubit/apps/erp/src -name '*.4gl' -exec grep -l -i -w ",
				p_systableext.tabname clipped," ",oc," \\; > tmp.unl"

			run run_string
		    delete from dd_temp
			load from "tmp.unl" insert into dd_temp

			if status <> 0 then
				display "error loading"
				exit program 1
			end if
            let brute_force = true

		else
			#display "found 4gl smart way"
		end if

		select count(*) into found_in_4gl from dd_temp
		if found_in_4gl > 0 then
			if brute_force then
                let brute_force=false
				output to report unused_tables(p_systableext.tabname,
						total_tables, total_doc4gl_tables,
                           total_missing_tables,
                       	tables_with_process,tables_with_function,tables_with_form,
                        cnt_process,cnt_function,cnt_form,found_in_per,found_in_4gl,
                        "brute-force",obsoleted,total_obsolete_tables,total_p4gl_parse_error,
                        total_not_exist,total_obsolete_not_removed
				)
            end if

			declare r7 cursor for
                select * from dd_temp

			foreach r7 into run_string
                if length(run_string) < 2 then
                    exit foreach
                end if

	            let module_basename = my_basename(run_string)
				#display run_string clipped, " = ",module_basename clipped

				select count(*) into tmp_cnt
                    from p4gl_module
                        where module_name = module_basename

                if tmp_cnt = 0 then

					let run_string2= "grep -c ",module_basename clipped," /tmp/p4gl.log > /dev/null"
					run run_string2 returning p4gl_parse_error #this is a exit code, not a count that we sent to /dev/null
					if p4gl_parse_error = 0 then
                        #found it
						let msg_txt=strip(run_string,"/opt/aubit/apps/erp") clipped, " not parsed-p4gl error"
                        let total_p4gl_parse_error=total_p4gl_parse_error+1
					else
						let msg_txt=strip(run_string,"/opt/aubit/apps/erp") clipped, " not parsed at all-FIND OUT WHY"
                    end if
				else
                    let msg_txt=strip(run_string,"/opt/aubit/apps/erp") clipped, " not parsed correctly or PREPAREd"
				end if
				output to report unused_tables(p_systableext.tabname,
							total_tables, total_doc4gl_tables,
                            total_missing_tables,
                           	tables_with_process,tables_with_function,tables_with_form,
                            cnt_process,cnt_function,cnt_form,found_in_per,found_in_4gl,
                            msg_txt,obsoleted,total_obsolete_tables,total_p4gl_parse_error,
                            total_not_exist,total_obsolete_not_removed
							)

			end foreach
            close r7
		end if

        #################################################
        #       Form files
        #################################################
        let brute_force = false

		#look for table.column notation
		let run_string= "find /opt/aubit/apps/erp/src -name '*.per' -exec grep -l -i '",
			p_systableext.tabname clipped,"\\.' ",oc," \\; > tmp.unl"
			#TODO: what about ...type like prodsurcharge.x
		#display run_string clipped
		run run_string

		{
		look for table in "tables" section (complete line only)

		There is little point in doing this - table will be liste in "tables"
        section (probably) only if table is actually used (to associate an
        screen fiels with table column. And if it was, above search already
        got it  .

        #unfortunately tab or spaces in front or after table name can mess this one up
		let run_string= "find /opt/aubit/apps/erp/src -name '*.per' -exec grep -l -i -x '",
			p_systableext.tabname clipped,"' " ,oc," \\; >> tmp.unl"
		#display run_string clipped
		run run_string

        }

		delete from dd_temp
		load from "tmp.unl" insert into dd_temp
		if status <> 0 then
	    	display "error loading"
			exit program 1
		end if

        {
        Brute-force: just look for complete word

		There is very little point in doing this - only thing it (might)
        catch is a table name in "tables section where there is a tab or space
		used before or after table name

		select count(*) into found_in_per from dd_temp
		if found_in_per = 0 then
            #we found nothing the "smart" way, so we have to try brute force
			let run_string= "find /opt/aubit/apps/erp/src -name '*.per' -exec grep -l -i -w ",
				p_systableext.tabname clipped," ",oc," \\; > tmp.unl"
			#display run_string clipped
			run run_string

			delete from dd_temp
			load from "tmp.unl" insert into dd_temp
			if status <> 0 then
		    	display "error loading"
				exit program 1
			end if

            let brute_force = true
		end if

        }

		select count(*) into found_in_per from dd_temp
		if found_in_per > 0 then

			if found_in_4gl > 0 then
                #generate empty line between per and 4gl files
				output to report unused_tables(p_systableext.tabname,
						total_tables, total_doc4gl_tables,
                           total_missing_tables,
                       	tables_with_process,tables_with_function,tables_with_form,
                        cnt_process,cnt_function,cnt_form,found_in_per,found_in_4gl,
                        " ",obsoleted,total_obsolete_tables,total_p4gl_parse_error,
                        total_not_exist,total_obsolete_not_removed
				)

            end if

			declare r8 cursor for
                select distinct load_field from dd_temp

			foreach r8 into run_string
                if length(run_string) < 2 then
                    exit foreach
                end if

                #check if this form is formonly
				let run_string2= "grep -i -c 'database formonly' ",run_string clipped," > /dev/null"
				run run_string2 returning is_formonly #this is a exit code, not a count that we sent to /dev/null
				if is_formonly = 0 then
                    #found it - this form is formonly, and is of no interest to us
					#display "was formonly"
                    let found_in_per=found_in_per-1
					continue foreach
                end if

				#display "NOT formonly"

				if brute_force then
	                let brute_force=false
					#show in report that this is result of brute-force search
					output to report unused_tables(p_systableext.tabname,
							total_tables, total_doc4gl_tables,
	                           total_missing_tables,
	                       	tables_with_process,tables_with_function,tables_with_form,
	                        cnt_process,cnt_function,cnt_form,found_in_per,found_in_4gl,
	                        "brute-force",obsoleted,total_obsolete_tables,total_p4gl_parse_error,
	                        total_not_exist,total_obsolete_not_removed
					)
	            end if

				let run_string = ".",strip(run_string,"/opt/aubit/apps/erp")
				select count(*) into tmp_cnt
                    from p4gl_form
                        where path=run_string

                if tmp_cnt = 0 then
                    let msg_txt=hush clipped,run_string clipped, " not parsed at all-FIND OUT WHY"
                    #FIXME: this will happen when NONE of the fields in this
					#form file have any attributes, since we are extracting only
                    #attributes at the momet, so it there are none, form file
                    #wil lnot get processed
				else
                    let msg_txt=hush clipped,run_string clipped, " not parsed correctly"
                    #FIXME: this will happen when field associated with the column
					#in this table has no attributes, since we are extracting only
                    #attributes at the momet
				end if

				output to report unused_tables(p_systableext.tabname,
							total_tables, total_doc4gl_tables,
                            total_missing_tables,
                           	tables_with_process,tables_with_function,tables_with_form,
                            cnt_process,cnt_function,cnt_form,found_in_per,found_in_4gl,
                            msg_txt,obsoleted,total_obsolete_tables,total_p4gl_parse_error,
                            total_not_exist,total_obsolete_not_removed
							)
			end foreach
            close r8
		end if

		if found_in_per=0 and found_in_4gl=0 and cnt_process=0 and cnt_function =0 and cnt_form =0
		then
            #insert it and mark it obsolete
            insert into systableext (owner,tabname,tabtype)
                values ("root",p_systableext.tabname,"O")
				#Doc4GL table types are T=table V=view U=undefined E=tEmporary O=obsolete
            let obsoleted=obsoleted+1
            let total_obsolete_tables=total_obsolete_tables+1
        end if

           #TODO: get count of all errors logged in /tmp/p4gl.log, compare it with total_p4gl_parse_error

        if found_in_per > 0 or found_in_4gl > 0 then
			let output_counter = output_counter + 1
			output to report unused_tables(p_systableext.tabname,
							total_tables, total_doc4gl_tables,
                            total_missing_tables,
                           	tables_with_process,tables_with_function,tables_with_form,
                            cnt_process,cnt_function,cnt_form,found_in_per,found_in_4gl,
                            "",obsoleted,total_obsolete_tables,total_p4gl_parse_error,
                            total_not_exist,total_obsolete_not_removed
							)
        end if
	end foreach

    if output_counter = 0 then
			output to report unused_tables(p_systableext.tabname,
							total_tables, total_doc4gl_tables,
                            total_missing_tables,
                           	tables_with_process,tables_with_function,tables_with_form,
                            cnt_process,cnt_function,cnt_form,found_in_per,found_in_4gl,
                            "",obsoleted,total_obsolete_tables,total_p4gl_parse_error,
                            total_not_exist,total_obsolete_not_removed
							)
    end if

    finish report unused_tables

    error report_file clipped, " created."
    let run_string= "less ",report_file
    run run_string

end function

{**
 *  Report for Tables not referenced by 4gl or per files rep_unused_tables()
 *
 *}
REPORT unused_tables(tabname,total_tables,total_doc4gl_tables,
	total_missing_tables,tables_with_process,tables_with_function,tables_with_form,
	cnt_process,cnt_function,cnt_form,found_in_per,found_in_4gl,msg_txt,obsoleted,
	total_obsolete_tables,total_p4gl_parse_error,total_not_exist,total_obsolete_not_removed)

define
	tabname like p4gl_table_process.tabname,
    total_tables,total_doc4gl_tables,group_cnt,total_missing_tables,
	tables_with_process,tables_with_function,tables_with_form,
	cnt_process,cnt_function,cnt_form,found_in_per,found_in_4gl,obsoleted,
    total_obsolete_tables,total_p4gl_parse_error,total_not_exist,total_obsolete_not_removed
        smallint,
    msg_txt char (180)

OUTPUT

	LEFT MARGIN 0
	TOP MARGIN 0
	BOTTOM MARGIN 0
	PAGE LENGTH 65

FORMAT

	#################
	FIRST PAGE HEADER
	#################


		PRINT
	"_________________________________________________________________"

        print
	#"tablename   cnt_process,cnt_function,cnt_form,found_in_per,found_in_4gl"
	"            Database tables not registered by Doc4GL"

		PRINT
	"_________________________________________________________________"
	skip 3 lines

    #######################
	before group of tabname
    #######################
		PRINT
            hush clipped,
	"_________________________________________________________________"
		print
            hush clipped,
			tabname

	############
	ON EVERY ROW
	############
{
		print
            tabname,
			cnt_process using "<<",
			cnt_function using "<<",
			cnt_form using "<<",
			found_in_per using "<<",
			found_in_4gl using "<<"
}
        print "    ",msg_txt clipped


    ########################
	after group of tabname
    ########################
        skip 1 line
		print
			hush clipped,
			"    process=",cnt_process using "<<#",
			" function=",cnt_function using "<<#",
			" form=",cnt_form using "<<#",
			" per=",found_in_per using "<<#",
			" 4gl=",found_in_4gl using "<<#"


	###########
	ON LAST ROW
	###########

		PRINT
	"___________________________________________________________________"


        print "This application's tables in database:",
				column 65, total_tables using "<<<<"
        print "Unique tables registered by DbDoc:",
				column 65, total_doc4gl_tables using "<<<<"
        print "Obsolete tables:",
				column 65, total_obsolete_tables using "<<<<"
		print "Table references to non-existing tables, temp tables:",
                column 65, total_missing_tables using "<<<<"
		print "Tables in Dbdoc no longer in db (obsoleted,temp,missing...):",
                column 65, total_not_exist using "<<<<"
		skip 1 line
		#print "Tables we need to account for:",
		print "Unique Tables without references in 4gl or per code:",
			column 65,
			(total_tables-
				(total_doc4gl_tables-total_missing_tables-total_obsolete_not_removed)
			) + total_obsolete_tables
				using "<<<<"
		skip 1 line
		print "Unique tables with process(es) assigned:",
				column 65, tables_with_process using "<<<<"
        print "Unique tables referenced in function(s):",
				column 65, tables_with_function using "<<<<"  #?????
        print "Unique Tables referenced in form(s):",
				column 65, tables_with_form using "<<<<"
		skip 1 line
		print "Tables marked obsolete on this run:",
				column 65, obsoleted using "<<<<"
		print "Total p4gl parse errors:",
				column 65, total_p4gl_parse_error using "<<<<"
		PRINT
	"___________________________________________________________________"


END REPORT


{**
 * Load data extracted from form files from file to temp table dd_temp
 *
 *}
function load_dd()
define
    tmp_stat, cnt,pos,pos1,pos2,pos3,pos4,buff_length, param integer,
    buff, curr_form_file,
	desc_text,table_text,field_text
		char (300),
    form_file, module
    	char(20),
    del_char, attrib_type
        char(1),
    attrib_code smallint


    display "Loading DD  ."
	whenever error continue
        select count(*) into tmp_stat from dd_temp
        let tmp_stat=status
	whenever error stop

    #display "Status = ",tmp_stat

        if tmp_stat <> 0 then
            #display "Creating table dd_temp"
			#create table dd_temp (load_field char (300))
        else
	       #display "Cleaning dd_temp table  ."
		   #delete from dd_temp
           drop table dd_temp
        end if

        #must drop/create table every time to maintain line order
		display "Creating table dd_temp"
	 	create table dd_temp (load_field char (300))


	   display "Loading file  ."
	   load from l_fname insert into dd_temp
	   if status <> 0 then
	      display "error loading"
          exit program 1
	   end if

       display "Successfully loaded DD."

end function

{**
 * Process (normalise) each row loaded with function load_dd
 *
 *}
function process_dd()
define
    tmp_stat, cnt,pos,pos1,pos2,pos3,pos4,buff_length, param, tmp_cnt
		integer,
    buff, tmpbuff, curr_form_file,
	desc_text,table_text,field_text, tmp_string
		char (300),
    form_file, module
    	char(20),
    del_char, attrib_type
        char(1),
    attrib_code, formfile_cnt,attrib_cnt,warning_cnt,formonly_cnt,
	is_multiline,lines_cnt,tmpcnt,error_comp_cnt,did_one_form
		smallint,
    pa_lines array [100] of record
		text_line char(80)
    end record


    let did_one_form=false
    let del_char="@"
    display "Processing DD...."
	whenever error continue
        select count(*) into tmp_stat from dd_temp
        let tmp_stat=status
	whenever error stop

    #display "Status = ",tmp_stat

        if tmp_stat <> 0 then
            display "Please load first."
			exit program 2
        end if

	#insert all form attribute types
	select count(*) into tmp_cnt from p4gl_form_attribute_type

	if tmp_cnt = 0 then

		insert into p4gl_form_attribute_type (form_attribute_type_id,form_attribute_name)
		    values (1,"COMMENTS")
		insert into p4gl_form_attribute_type (form_attribute_type_id,form_attribute_name)
		    values (2,"INCLUDE")
		insert into p4gl_form_attribute_type (form_attribute_type_id,form_attribute_name)
		    values (3,"DEFAULT")
		insert into p4gl_form_attribute_type (form_attribute_type_id,form_attribute_name)
		    values (4,"FORMAT")
		insert into p4gl_form_attribute_type (form_attribute_type_id,form_attribute_name)
		    values (5,"PICTURE")
		insert into p4gl_form_attribute_type (form_attribute_type_id,form_attribute_name)
		    values (6,"UPSHIFT")
		insert into p4gl_form_attribute_type (form_attribute_type_id,form_attribute_name)
		    values (7,"DOWNSHIFT")

	end if

		declare c4 cursor for select * from dd_temp

        let cnt=0
        let formfile_cnt=0
        let attrib_cnt=0
        let warning_cnt=0
        let formonly_cnt=0
        let is_multiline = false
        let error_comp_cnt=0

        foreach c4 into buff
            let cnt=cnt+1
            let param = 0
            let pos1 = 0
            let pos2 = 0
            let pos3 = 0
            let pos4 = 0
            let buff_length=length (buff)

			if buff_length=4 and (buff = "S@0@" or buff = "S@3@") then
                let is_multiline = true
                let lines_cnt=1
				let pa_lines[lines_cnt].text_line=buff clipped
				continue foreach
            end if

            if is_multiline then
				if buff matches "*@*" then
	                #end of multi line entry
					let is_multiline = false
					let tmpbuff=""
					for tmpcnt=1 to lines_cnt
						let tmpbuff=tmpbuff clipped,pa_lines[tmpcnt].text_line clipped
                    end for
					let buff=tmpbuff clipped, buff clipped
		            let buff_length=length (buff)
					#display "Multiline:",buff clipped
				else
	                #another line
					let lines_cnt=lines_cnt+1
					let pa_lines[lines_cnt].text_line=buff clipped,"|"
					continue foreach
                end if
            end if

			if buff_length > 1 then

                if buff [1,9] = "FORMFILE=" then
                    let curr_form_file = buff [10,buff_length]
                    let formfile_cnt=formfile_cnt+1

                    if do_one_form is not null then
                        let tmp_string = "*",do_one_form
                        if curr_form_file not matches tmp_string then
                            if did_one_form then
                                display "Processed one form. Exit."
								exit program
                            end if
							continue foreach
                        end if
                    end if

                    display "Formfile #",formfile_cnt,"=",curr_form_file clipped

                    continue foreach
                else

                    if do_one_form is not null then
                        if curr_form_file not matches tmp_string then
                            continue foreach
                        else
                            let did_one_form=true
						end if
                    end if


					for pos=1 to buff_length
                        if buff[pos] = del_char then
                            let param=param + 1
							case param
                                when 1
                                    let pos1=pos
                                when 2
                                    let pos2=pos
                                when 3
                                    let pos3=pos
                                when 4
                                    let pos4=pos
									#exit for
                                otherwise
                                    display "ERROR: Param > 4"
                                    display buff clipped
                                    exit program 3
                            end case
                        end if
                    end for

                    if pos1<>0 and pos2<>0 and pos3<>0 and pos4<>0 then
						#display "-",pos1,"-",pos2,"-",pos3,"-",pos4,"-"
						let attrib_type=buff[1,pos1-1]
						let attrib_code=buff[pos1+1,pos2-1]
						let desc_text=buff[pos2+1,pos3-1]

                        if pos4=pos3+1 then
							let table_text="formonly"
                        else
							let table_text=buff[pos3+1,pos4-1]
                        end if
        	            let field_text=buff[pos4+1,buff_length]
                        let attrib_cnt=attrib_cnt+1
					    
						if length (table_text) < 1 then
					        display "WARNING: empty table name in line:"
                            display buff clipped
                            let table_text = "FORMONLY"
					        #exit program 9
                            #It is apparently OK not to specify table name or FORMONLY
                            #see  src/utility/ENG/U110.per
                            #Apparently this field is FORMONLY by default
					    end if
					else
                        if buff matches "*@*" then
							display "ERROR: ",pos1," ",pos2," ",pos3," ",pos4,":"
                            display "in ",curr_form_file clipped,"(line=",cnt,"):"
							display buff clipped
        	                display ""
							exit program 4
						else
							#this is (probably) fcompile warning
	                        if buff[1,7] = "Warning" then
								let warning_cnt=warning_cnt+1
                                continue foreach
                            end if

                            if buff matches "*not found in database" then
                                let error_comp_cnt=error_comp_cnt+1
                                continue foreach
							end if

                            if buff[1,15] = "Error compiling" then
                                let error_comp_cnt=error_comp_cnt+1
                                continue foreach
                            end if

							display "SKIP:",buff clipped
                            continue foreach
                        end if
					end if


				end if


	            #remove Quotes at start and end od strings
				let buff_length=length (desc_text)
                if desc_text[1] = '"' then
                    let desc_text=desc_text[2,buff_length]
                end if

	            let buff_length=length (desc_text)
                if desc_text[buff_length] = '"' then
                    if buff_length = 1 then
						let desc_text=""
                    else
						let desc_text=desc_text[1,buff_length-1]
                    end if
                end if

                #remove space(s) at the start of string
				let buff=desc_text
				let buff_length=length (buff)
                for pos=1 to buff_length
                	if buff[pos] = " " then
                        let desc_text=desc_text[pos+1,buff_length]
						let buff_length=length (desc_text)
                    else
                        exit for
                    end if
                end for


	            #extract module name and form file name from form file path
				let pos1 = 0
    	        let pos2 = 0
        	    let pos3 = 0
        	    let pos4 = 0
				let buff_length=length (curr_form_file)
                for pos=1 to buff_length
                    if curr_form_file[pos]="/" then
                        let pos3=pos2   # / encountered before that
                        let pos2=pos1   # / encountered before that
						let pos1=pos 	# last encountered /
                    end if
                end for

				let form_file=curr_form_file[pos1+1,buff_length-4]
                let module = upshift(curr_form_file[pos3+1,pos2-1])

                #Except for forms in utility/ENG/setup


                #show row:
				#display cnt, ": ",
				#display table_text clipped, ".",field_text clipped," type=",attrib_type," code=", attrib_code using "#", ":"
				#display " ",desc_text clipped
	            #display curr_form_file clipped
                #display module clipped," ",form_file clipped
				#sleep 5
                #continue foreach

                #skip table_text = "formonly"
                if upshift (table_text) = "FORMONLY" then
					let formonly_cnt=formonly_cnt+1
#should still insert the form in p4gl_form, mark form as FORMONLY and add attributes
					continue foreach
                end if

                # now let's load ###############
                call store_data(attrib_type,attrib_code,curr_form_file,form_file,module,desc_text,table_text,field_text)

			else
                if warnings then
					display "WARNING: empty line"
                end if
			end if

        end foreach

        display ""
        display "Processed ",formfile_cnt," form files,",attrib_cnt, " attributes"
        display "warning_cnt=",warning_cnt," formonly=",formonly_cnt," error comp=",error_comp_cnt
        display ""

{
Processed   1902 form files, 19024 attributes
warning_cnt=  1761 formonly=  3721
}


    #TODO - prompt to drop temp load table


end function #function process_dd()


{**
 * Insert information about form attribute in Doc4GL database
 * Called from function process_dd
 *}
function store_data(attrib_type,attrib_code,curr_form_file,form_file,module,
	desc_text,table_text,field_text)

define
	attrib_type
        char(1),
	curr_form_file,desc_text,table_text,field_text
		char (300),
    form_file,
	module
    	char(20),
	attrib_code
		smallint,
    table_owner
        char (32),
    tmp
		char (254)

#TODO: extract DoxyGen comment about form purpose/description from form file


    select owner into table_owner
        from systables
            where tabname = table_text

    if length (table_text) < 1 then
        display "ERROR: received empty table"
        exit program 9
    end if


                ###############################################################
				#check if we already have this form file in context of this process
                #and in this path:
                ###############################################################
				select p4gl_form.* into p_p4gl_form.*
					from p4gl_form, p4gl_form_process
                    where p4gl_form.form_name = form_file
						and p4gl_form.path = curr_form_file
						and p4gl_form_process.id_process = module
						and p4gl_form_process.form_id = p4gl_form.form_id

                if status = NOTFOUND then

					#check if we have this form file
					select p4gl_form.* into p_p4gl_form.*
						from p4gl_form
        	            where p4gl_form.form_name = form_file
							and p4gl_form.path = curr_form_file

                    if status = NOTFOUND then
                        #create entry for this form file:
						insert into p4gl_form (form_id,form_name,path)
							values (0,form_file,curr_form_file)
                        let p_p4gl_form.form_id=sqlca.sqlerrd[2]

                        if p_p4gl_form.form_id=0 then
                            display "ERROR: serial returned 0"
                            exit program 4
                        end if

					end if

					#check if we have this module/process
					select * into p_p4gl_process.* from p4gl_process
                        where id_process = module

                    if status = notfound then
                        #display "ERROR: process ", module clipped, " not found in process table"
                        #exit program 7


				        #This is expected to be already inserted by Doc4GL, by loading
			            #a process (.unl) file. Therefore, we will just warn if it does not
			            #exist already.

			            if warnings then
							display "WARNING: process ", module clipped, " does not exist in process table - ADDING"
                        end if

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

						insert into p4gl_process (id_process,disp_process,den_process,sub_process_of,comments)
				            values (module,module,module,"ERP","")

                    end if

					#-691	Missing key in referenced table for referential constraint
					#constraint-name.
					if debug then
						display "module=",module clipped," form_id=",p_p4gl_form.form_id
					end if

					#insert relationship to process/module for this form file
                    insert into p4gl_form_process (id_process, form_id)
                        values (module,p_p4gl_form.form_id)


	                #RE-check if we already have this form file in context of this process
	                #and in this path:
					select p4gl_form.* into p_p4gl_form.*
						from p4gl_form, p4gl_form_process
	                    where p4gl_form.form_name = form_file
							and p4gl_form.path = curr_form_file
							and p4gl_form_process.id_process = module
							and p4gl_form_process.form_id = p4gl_form.form_id

	                if status = NOTFOUND then
                        display "ERROR: faild to create form/process relationship"
                        exit program 8
                    end if

                end if

                #now we have p4gl_form, p4gl_process, p4gl_form_process

                ###############################################################
                #Check if we have this form in contect of this table/column
                ###############################################################

{FIXME:


WARNING: Different attributes referencing same column
nter Load Indicator<>Load Indicator
attrib_code=     7 attrib_type=S
loadparms.load_ind form=        648


WARNING: Different attributes referencing same column
nter full name of interface file<>nter full name of interface load file
attrib_code=     7 attrib_type=S
loadparms.file_text form=        660


WARNING: Different attributes referencing same column
nter full UNIX path of interface file<>nter full UNIX path of interface load file/s
attrib_code=     7 attrib_type=S
loadparms.path_text form=        660


WARNING: Different attributes referencing same column
nter Load Indicator<>Load Indicator
attrib_code=     7 attrib_type=S
loadparms.load_ind form=        663

WARNING: Different attributes referencing same column
nter full name of interface file<>Full name of interface load file
attrib_code=     7 attrib_type=S
loadparms.file_text form=        663

WARNING: Different attributes referencing same column
nter full UNIX path of interface file<>Full UNIX path of interface load file/s
attrib_code=     7 attrib_type=S
loadparms.path_text form=        663


}

                select p4gl_form_column.*, p4gl_form_table.* into p_p4gl_form_column.*, p_p4gl_form_table.*
                    from p4gl_form, p4gl_form_column, p4gl_form_table
                        where p4gl_form.form_id = p_p4gl_form.form_id
                        and p4gl_form_table.tabname = table_text
#                        and p4gl_column_table.tabname = table_text
                        and p4gl_form_column.colname = field_text

						and p4gl_form_column.tabname = table_text
                        and p4gl_form_table.owner = table_owner
                        and p4gl_form_column.owner = table_owner


                        #join:
                        and p4gl_form.form_id = p4gl_form_column.form_id
                        and p4gl_form.form_id = p4gl_form_table.form_id

                if status = NOTFOUND then
                    #check if we have this table
	                select * into p_systableext.*
	                    from systableext
	                        where tabname = table_text
	                        and owner = table_owner

                    if status = NOTFOUND then
						{

						-703	Primary key on table table-name has a field with a null key value.

						An attempt was made either to insert a null value into a column that is
						part of a primary key, or to add a primary constraint to a table that
						has a NULL value in one of the key columns.
						}

						if debug then
							display "owner=",table_owner clipped,", table=",table_text clipped
        	            end if

						insert into systableext (owner, tabname)
                            values (table_owner,table_text)
                    end if

                    #check if we have this column for this table
	                select * into p_syscolumnext.*
	                    from syscolumnext
	                        where tabname = table_text
	                        and colname = field_text
							and owner = table_owner

                    if status = NOTFOUND then
                        insert into syscolumnext (owner, tabname, colname)
                            values (table_owner,table_text,field_text)
                    end if


	                #check if we have form/table relationship
					select * into p_p4gl_form_table.*
    	                from p4gl_form_table
        	                where p4gl_form_table.form_id = p_p4gl_form.form_id
            	            and p4gl_form_table.tabname = table_text
                            and p4gl_form_table.owner = table_owner

                    if status = NOTFOUND then
                        insert into p4gl_form_table (owner, tabname, form_id)
                            values (table_owner,table_text,p_p4gl_form.form_id)
                    end if

	                #check if we have form/column relationship
					select * into p_p4gl_form_column.*
    	                from p4gl_form_column
        	                where p4gl_form_column.form_id = p_p4gl_form.form_id
            	            and p4gl_form_column.tabname = table_text
							and p4gl_form_column.colname = field_text
                            and p4gl_form_column.owner = table_owner

                    if status = NOTFOUND then
                        insert into p4gl_form_column (owner, tabname, form_id, colname)
                            values (table_owner,table_text,p_p4gl_form.form_id,field_text)
                    end if

	                #RE-Check if we have this form in contect of this table/column


					#-284	A subquery has returned not exactly one row.
					select p4gl_form_column.*, p4gl_form_table.* into p_p4gl_form_column.*, p_p4gl_form_table.*
	                    from p4gl_form, p4gl_form_column, p4gl_form_table
	                        where p4gl_form.form_id = p_p4gl_form.form_id
	                        and p4gl_form_table.tabname = table_text
#	                        and p4gl_column_table.tabname = table_text
	                        and p4gl_form_column.colname = field_text

							and p4gl_form_column.tabname = table_text
	                        and p4gl_form_table.owner = table_owner
	                        and p4gl_form_column.owner = table_owner

							#join:
	                        and p4gl_form.form_id = p4gl_form_column.form_id
	                        and p4gl_form.form_id = p4gl_form_table.form_id

	                if status = NOTFOUND then
                        display "ERROR: failed to create form/table/column relationship."
                        exit program 9
                    end if

                #This is OK - same field in a form can have multiple attributes
				#else
                #    display "ERRROR: duplicate form/table/column relationship"
				#	display "form_id=",p_p4gl_form.form_id, " table=",table_text clipped,".",field_text clipped
				#	exit program 10
                end if


                #now we have:
				#p4gl_form, p4gl_process, p4gl_form_process,
				#p4gl_form_column, p4gl_form_table,
                #p_systableext, p_syscolumnext

                ##########################################################
				#check if we have this table in context of this process
                ##########################################################

                select * from p4gl_table_process
					where id_process = module
                    and owner = table_owner
                    and tabname = table_text

                if status = NOTFOUND then
                    insert into p4gl_table_process (id_process,owner,tabname)
                        values (module,table_owner,table_text)
                end if


                ##########################################################
				#check if we have this column in context of this process
                ##########################################################

                select * from p4gl_column_process
					where id_process = module
                    and owner = table_owner
                    and tabname = table_text
                    and colname = field_text

                if status = NOTFOUND then
                    insert into p4gl_column_process (id_process,owner,tabname, colname)
                        values (module,table_owner,table_text,field_text)
                end if


				#now we have:
				#p4gl_form, p4gl_process, p4gl_form_process,
				#p4gl_form_column, p4gl_form_table,
                #systableext, syscolumnext,
                #p4gl_table_process, p4gl_column_process

                #finally, insert form field attribute:

                case attrib_type
                    when "S"
                    case attrib_code
                        when 7  #COMMENTS 		FA_S_COMMENTS = 7,
                            insert into p4gl_form_attribute (form_attribute_id,form_id,form_attribute_type_id,text,owner,tabname,colname)
                                values (0,p_p4gl_form.form_id,1,desc_text,table_owner,table_text,field_text)

							#Check table column desc & update if empty
                            select remarks into tmp
                                from syscolumnext
                                    where owner = table_owner
                                    and tabname = table_text
                                    and colname = field_text
#TODO: maybe I need a separate table
#so I can store muliple comments & other attributes for column?
                            if length (tmp) < 1 then
	                            update syscolumnext set remarks = desc_text
	                                    where owner = table_owner
	                                    and tabname = table_text
	                                    and colname = field_text
                            else
                                if tmp <> desc_text then
									if verbose then
									display "WARNING: Different attributes referencing same column"
                                    display tmp clipped , "<>", desc_text clipped
                                    display "attrib_code=",attrib_code," attrib_type=",attrib_type clipped
                                    display table_text clipped ,".",field_text clipped, " form=",p_p4gl_form.form_id
                                    display ""
                                    end if
                                end if
							end if


						when 0	#INCLUDE    	FA_S_INCLUDE = 0,
                            insert into p4gl_form_attribute (form_attribute_id,form_id,form_attribute_type_id,text,owner,tabname,colname)
                                values (0,p_p4gl_form.form_id,2,desc_text,table_owner,table_text,field_text)

							#check table column domain and update if empty
                            select include into tmp
                                from syscolumnext
                                    where owner = table_owner
                                    and tabname = table_text
                                    and colname = field_text

                            if length (tmp) < 1 then
	                            update syscolumnext set include = desc_text
	                                    where owner = table_owner
	                                    and tabname = table_text
	                                    and colname = field_text
                            else
                                if tmp <> desc_text then
									if verbose then
									display "WARNING: Different attributes referencing same column"
                                    display tmp clipped , "<>", desc_text clipped
                                    display "attrib_code=",attrib_code," attrib_type=",attrib_type clipped
                                    display table_text clipped ,".",field_text clipped, " form=",p_p4gl_form.form_id
                                    display ""
                                    end if
								end if
							end if

						when 3	#DEFAULT    	FA_S_DEFAULT = 3,
                            insert into p4gl_form_attribute (form_attribute_id,form_id,form_attribute_type_id,text,owner,tabname,colname)
                                values (0,p_p4gl_form.form_id,3,desc_text,table_owner,table_text,field_text)
							#check column default & insert if empty
                            select default_value into tmp
                                from syscolumnext
                                    where owner = table_owner
                                    and tabname = table_text
                                    and colname = field_text

                            if length (tmp) < 1 then
	                            update syscolumnext set default_value = desc_text
	                                    where owner = table_owner
	                                    and tabname = table_text
	                                    and colname = field_text
                            else
                                if tmp <> desc_text then
                                    if verbose then
									display "WARNING: Different attributes referencing same column"
                                    display tmp clipped , "<>", desc_text clipped
                                    display "attrib_code=",attrib_code," attrib_type=",attrib_type clipped
                                    display table_text clipped ,".",field_text clipped, " form=",p_p4gl_form.form_id
                                    display ""
                                    end if

								end if
							end if

						when 2	#FORMAT 	   	FA_S_FORMAT = 2,
                            insert into p4gl_form_attribute (form_attribute_id,form_id,form_attribute_type_id,text,owner,tabname,colname)
                                values (0,p_p4gl_form.form_id,4,desc_text,table_owner,table_text,field_text)
							#This is apparently only presentation attribute,
							#and does not affect how data is stored in database:
                            #You can use the FORMAT attribute with a DECIMAL,
							#SMALLFLOAT, FLOAT, or DATE field to control the
							#format of output displays.

						when 1	#PICTURE    	FA_S_PICTURE = 1,
                            insert into p4gl_form_attribute (form_attribute_id,form_id,form_attribute_type_id,text,owner,tabname,colname)
                                values (0,p_p4gl_form.form_id,5,desc_text,table_owner,table_text,field_text)

							#The PICTURE attribute specifies a character pattern
							#for data entry into a text field, and prevents entry
							#of values that conflict with the specified pattern.
                            #Literals in PICTURE string will be stored in database
                            #after the input from field using PICTURE attribute.

                            select picture into tmp
                                from syscolumnext
                                    where owner = table_owner
                                    and tabname = table_text
                                    and colname = field_text

                            if length (tmp) < 1 then
	                            update syscolumnext set picture = desc_text
	                                    where owner = table_owner
	                                    and tabname = table_text
	                                    and colname = field_text
                            else
                                if tmp <> desc_text then
                                    if verbose then
									display "WARNING: Different attributes referencing same column"
                                    display tmp clipped , "<>", desc_text clipped
                                    display "attrib_code=",attrib_code," attrib_type=",attrib_type clipped
                                    display table_text clipped ,".",field_text clipped, " form=",p_p4gl_form.form_id
                                    display ""
                                    end if
								end if
							end if


                        otherwise
                            display "ERROR: attrib_code=", attrib_code
                            exit program 5
                    end case
                    when "B"
                    case attrib_code
						when 7	#	    UPSHIFT		FA_B_UPSHIFT = 7,
                            insert into p4gl_form_attribute (form_attribute_id,form_id,form_attribute_type_id,owner,tabname,colname)
                                values (0,p_p4gl_form.form_id,6,table_owner,table_text,field_text)

							select up_down_shift into tmp
								from syscolumnext
                                    where owner = table_owner
                                    and tabname = table_text
                                    and colname = field_text

                            if tmp is null then
	                            update syscolumnext set up_down_shift = "U"
	                                    where owner = table_owner
	                                    and tabname = table_text
	                                    and colname = field_text
                            else
                                if tmp <> "U" then
                                    if verbose then
									display "WARNING: Different attributes referencing same column"
                                    display tmp clipped , "<>", desc_text clipped
                                    display "attrib_code=",attrib_code," attrib_type=",attrib_type clipped
                                    display table_text clipped ,".",field_text clipped, " form=",p_p4gl_form.form_id
                                    display ""
                                    end if

                                end if
                            end if

						when 8	#    	DOWNSHIFT	FA_B_DOWNSHIFT = 8,
                            insert into p4gl_form_attribute (form_attribute_id,form_id,form_attribute_type_id,owner,tabname,colname)
                                values (0,p_p4gl_form.form_id,7,table_owner,table_text,field_text)

							select up_down_shift into tmp
								from syscolumnext
                                    where owner = table_owner
                                    and tabname = table_text
                                    and colname = field_text

                            if tmp is null then
	                            update syscolumnext set up_down_shift = "D"
	                                    where owner = table_owner
	                                    and tabname = table_text
	                                    and colname = field_text
                            else
                                if tmp <> "D" then
                                    if verbose then
									display "WARNING: Different attributes referencing same column"
                                    display tmp clipped , "<>", desc_text clipped
                                    display "attrib_code=",attrib_code," attrib_type=",attrib_type clipped
                                    display table_text clipped ,".",field_text clipped, " form=",p_p4gl_form.form_id
                                    display ""
                                    end if

                                end if
							end if
						otherwise
                            display "ERROR: attrib_code=", attrib_code
                            exit program 6

                    end case

                    otherwise
                        display "ERROR: attribute type is ", attrib_type
                        exit program 7
                end case


end function

{**
 * Count and show counts of rows in all Doc4GL tables
 *
 *}
function count_data()
define
    cnt integer

#total tables listed here = 36 (36 in model)

    display ""
    display "================== jDbdoc ==============="
	select count (*) into cnt from process
    display "process=		", cnt,				"	jDBdoc"
	select count (*) into cnt from ext_table
    display "ext_table=		", cnt,			"	jDBdoc"
	select count (*) into cnt from ext_database
    display "ext_database=		", cnt,			"	jDBdoc"
	select count (*) into cnt from ext_column
    display "ext_column=		", cnt,			"	jDBdoc"
	select count (*) into cnt from table_process
    display "table_process=		", cnt,			"	jDBdoc"

    display ""
    display "================== Dbdoc ================"
	select count (*) into cnt from sysmodules
    display "sysmodules=		", cnt,			"	Dbdoc"
	select count (*) into cnt from d_modulos
    display "d_modulos=		", cnt,			"	Dbdoc"
	select count (*) into cnt from d_mod_tab
    display "d_mod_tab=		", cnt,			"	Dbdoc"

    display ""
	display "================== Doc4GL ==============="
#populated from multiple sources:
	select count (*) into cnt from p4gl_form_process
    display "p4gl_form_process=	", cnt, 			"	p4gl(TODO),loadform(OK)"
# 1380 in db, but Processed 1655 form files # warning_cnt=10 formonly=3033 error comp=0
# 275 forms did not have any attributes, or theywhere formonly?

	select count (*) into cnt from p4gl_form
    display "p4gl_form=		", cnt, 				"	p4gl(TODO),loadform(OK?)"
	select count (*) into cnt from p4gl_table_process
    display "p4gl_table_process=	", cnt,         "	p4gl(OK),loadform(OK)"
	select count (*) into cnt from p4gl_column_process
    display "p4gl_column_process=	", cnt,			"	p4gl(TODO),loadform(OK)"
	select count (*) into cnt from systableext
    display "systableext=		", cnt,			"	p4gl(OK),loadform(OK),Dbdoc(CHECK)"
	select count (*) into cnt from syscolumnext
    display "syscolumnext=		", cnt,			"	p4gl(TODO),loadform(OK),Dbdoc(CHECK)"

#last run: Loaded=1572 Errors=336 Modules=1919 Missing=11 (should be 1583)

	select count (*) into cnt from p4gl_module
    display "p4gl_module=		", cnt,			"	p4gl(OK),mkf(OK)"  #1801 (x-137 not referenced by make files=1999)

#pre-loaded & inserted on-the-fly when found:
	select count (*) into cnt from p4gl_process
    display "p4gl_process=		", cnt,			"	p4gl(OK),loadform(CHECK),mkf(CHECK),fgldoc(OK)"
	select count (*) into cnt from p4gl_package
    display "p4gl_package=		", cnt,			"	p4gl(OK),loadform(CHECK),mkf(CHECK),fgldoc(TODO)"

#populated by loadform only:
	select count (*) into cnt from p4gl_form_attribute
    display "p4gl_form_attribute=	", cnt, 		"	loadform(OK)"
	select count (*) into cnt from p4gl_form_column
    display "p4gl_form_column=	", cnt, 			"	loadform(OK)"
	select count (*) into cnt from p4gl_form_table
    display "p4gl_form_table=	", cnt, 			"	loadform(OK)"
	select count (*) into cnt from p4gl_form_attribute_type
    display "p4gl_form_attribute_type", cnt, 		"	loadform(OK)"

#populated by mkf only:
	select count (*) into cnt from p4gl_module_prog
    display "p4gl_module_prog=	", cnt,			"	mkf(OK)"
	select count (*) into cnt from p4gl_program
    display "p4gl_program=		", cnt,			"	mkf(OK?)"     #1019 (1132 .mk files)

#populated by p4gl only:
	select count (*) into cnt from p4gl_table_usage
    display "p4gl_table_usage=	", cnt,			"	p4gl(OK)"
	select count (*) into cnt from p4gl_function_call
    display "p4gl_function_call=	", cnt, 		"	p4gl(OK)"
	select count (*) into cnt from p4gl_call_parameter
    display "p4gl_call_parameter=	", cnt,			"	p4gl(TODO)"
	select count (*) into cnt from p4gl_globals_usage
    display "p4gl_globals_usage=	", cnt,			"	p4gl(TODO)"
	select count (*) into cnt from p4gl_mod_todo
    display "p4gl_mod_todo=		", cnt,			"	p4gl(CHECK-FIX)"
	select count (*) into cnt from p4gl_function
    display "p4gl_function=		", cnt,			"	p4gl(OK)"
	select count (*) into cnt from p4gl_fun_todo
    display "p4gl_fun_todo=		", cnt,			"	p4gl(OK)"
	select count (*) into cnt from p4gl_fun_return
    display "p4gl_fun_return=	", cnt,			"	p4gl(OK)-ONLY from comment"
	select count (*) into cnt from p4gl_fun_process
    display "p4gl_fun_process=	", cnt,			"	p4gl(OK)-only from comment"
	select count (*) into cnt from p4gl_fun_parameter
    display "p4gl_fun_parameter=	", cnt,			"	p4gl(OK)"
	select count (*) into cnt from p4gl_form_usage
    display "p4gl_form_usage=	", cnt,			"	p4gl(TODO)"

#populated by other methods:
	select count (*) into cnt from p4gl_excel
    display "p4gl_excel=		", cnt,			"	TEMP(OK)"
	select count (*) into cnt from p4gl_func_calls
    display "p4gl_func_calls=	", cnt, 		"	p4gl_endrun(TODO)"
	display ""


{
----------- After loading 4gl:
p4gl_table_usage=         	  0 - (was 9543 - WRONG) TODO - remove need for table_name field
p4gl_form_usage=          	  0 - TODO - why is this not stored?, add reference to p4gl_form, add ref to p4gl_form_process, remove need for field form_name
p4gl_module=		       1564 - OK Loaded=1564 Errors=343 Modules=1919 Missing=12 (should be 1576)


}


end function

{
TODO: create loader for Informix "r4gl" created database "syspgm4gl" :

create table source4gl
  (
    progname char(10),
    ppath char(40),
    fglsourcename char(10),
    spath char(40)
  );

create table sourceother
  (
    progname char(10),
    ppath char(40),
    othersourcename char(10),
    extension char(3),
    spath char(40)
  );

create table libraries
  (
    progname char(10),
    ppath char(40),
    libraries char(9)
  );

create table opts
  (
    progname char(10),
    ppath char(40),
    options char(8)
  );

create table global
  (
    progname char(10),
    ppath char(40),
    globname char(10),
    gpath char(40)
  );

create table runner
  (
    progname char(10),
    ppath char(40),
    fglgoname char(10),
    fpath char(40),
    db4glname char(10),
    dpath char(40)
  );

create table otherobj
  (
    progname char(10),
    ppath char(40),
    othername char(10),
    opath char(40)
  );

create index i_fglspgm on source4gl (ppath,progname);
create index i_fglspgm1 on source4gl (progname);
create index i_fglopgm on sourceother (ppath,progname);
create index i_fglopgm1 on sourceother (progname);
create index i_fgllibpgm on libraries (ppath,progname);
create index i_fgllibpgm1 on libraries (progname);
create index i_fgloptpgm on opts (ppath,progname);
create index i_fgloptpgm1 on opts (progname);
create index i_fglgpgm on global (ppath,progname);
create index i_fglgpgm1 on global (progname);
create index i_fglrpgm on runner (ppath,progname);
create index i_fglrpgm1 on runner (progname);
create index i_fglobpgm on otherobj (ppath,progname);
create index i_fglobpgm1 on otherobj (progname);

}



{**
 * Drop all tables we know are obsolete
 * TODO - move this function in database creation program
 *}
function drop_obsolete_tables()

	drop table  abslic                           ;
	drop table  absmodule                        ;
	drop table  age_group                        ;
	drop table  agreement                        ;
	drop table  appeal                           ;
	drop table  appeal_cost                      ;
	drop table  ar1384head                       ;
	drop table  badacnum                         ;
	drop table  badccnum                         ;
	drop table  bankdraft                        ;
	drop table  bestsells                        ;
	drop table  binding                          ;
	drop table  bor_text                         ;
	drop table  bp_glreports                     ;
	drop table  bri_orderanalysis                ;
	drop table  bri_salesanalysis                ;
	drop table  bsgoodguys                       ;
	drop table  cashflow                         ;
	drop table  cfwdaudit                        ;
	drop table  cmdprogram                       ;
	drop table  cont_91                          ;
	drop table  cont_amt                         ;
	drop table  cont_head                        ;
	drop table  cont_line                        ;
	drop table  cont_stats                       ;
	drop table  cont_trans                       ;
	drop table  creditlog                        ;
	drop table  csfhead                          ;
	drop table  csfnote                          ;
	drop table  csfnote2                         ;
	drop table  custcond                         ;
	drop table  custdocket                       ;
	drop table  dcredit                          ;
	drop table  denomination                     ;
	drop table  deposit_hist                     ;
	drop table  deposit_trans                    ;
	drop table  deprdetl                         ;
	drop table  deprhead                         ;
	drop table  device_type                      ;
	drop table  disposition                      ;
	drop table  driverdetl                       ;
	drop table  drivernote                       ;
	drop table  entitydesc                       ;
	drop table  entitydesc1                      ;
	drop table  entityxref                       ;
	drop table  extrastext                       ;
	drop table  groupstat                        ;
	drop table  htmlparms                        ;
	drop table  introduction                     ;
	drop table  invinst                          ;
	drop table  invoicedetl_ext                  ;
	drop table  invoicenote                      ;
	drop table  item_master                      ;
	drop table  labourates                       ;
	drop table  labourdetl                       ;
	drop table  labourextras                     ;
	drop table  labournote                       ;
	drop table  linetrig                         ;
	drop table  loadinst                         ;
	drop table  mail_disc                        ;
	drop table  manners                          ;
	drop table  mmdr                             ;
	drop table  mtopterm                         ;
	drop table  mtopvmst                         ;
	drop table  ordercancel                      ;
	drop table  orderdetl_ext                    ;
	drop table  orderledg                        ;
	drop table  orderstat                        ;
	drop table  orderterr                        ;
	drop table  ordertrig                        ;
	drop table  ordohstat                        ;
	drop table  payment_type                     ;
	drop table  play                             ;
	drop table  port_config                      ;
	drop table  posactlog                        ;
	drop table  posbarcode                       ;
	drop table  poscacust                        ;
	drop table  poscashdrw                       ;
	drop table  poscdraw                         ;
	drop table  poschqdefs                       ;
	drop table  poscondition                     ;
	drop table  poscustprice                     ;
	drop table  posdatport                       ;
	drop table  posdatswtch                      ;
	drop table  posdebtmess                      ;
	drop table  posdevaltyp                      ;
	drop table  posdocoffers                     ;
	drop table  poseoddetl                       ;
	drop table  poseodhead                       ;
	drop table  posmatprice                      ;
	drop table  posmesstext                      ;
	drop table  posnexttran                      ;
	drop table  posordseq                        ;
	drop table  posparms                         ;
	drop table  posporide                        ;
	drop table  posprinter                       ;
	drop table  posscrpad                        ;
	drop table  posscruom                        ;
	drop table  possegment                       ;
	drop table  posspoffdef                      ;
	drop table  posstatdev                       ;
	drop table  possysmess                       ;
	drop table  postasset                        ;
	drop table  postcontra                       ;
	drop table  postcredit                       ;
	drop table  posterminal                      ;
	drop table  postexchange                     ;
	drop table  postinventory                    ;
	drop table  postinvoice                      ;
	drop table  postjobledg                      ;
	drop table  postpayment                      ;
	drop table  postpurchase                     ;
	drop table  postreceipt                      ;
	drop table  posttaxwh                        ;
	drop table  postvouch                        ;
	drop table  posudfdata                       ;
	drop table  posvaldev                        ;
	drop table  posvernum                        ;
	drop table  pricepend                        ;
	drop table  print_size                       ;
	drop table  productapn                       ;
	drop table  productkey                       ;
	drop table  purchnote                        ;
	drop table  purchrcpdet                      ;
	drop table  purchrcphdr                      ;
	drop table  question_text                    ;
	drop table  quotecancel                      ;
	drop table  rep_stock                        ;
	drop table  rough_demand                     ;
	drop table  saleshistory                     ;
	drop table  salesstat                        ;
	drop table  samtrig                          ;
	drop table  script_category                  ;
	drop table  script_pub                       ;
	drop table  script_trans                     ;
	drop table  shipcost                         ;
	drop table  shipdist                         ;
	drop table  shipnote                         ;
	drop table  shop_orddetl                     ;
	drop table  shop_ordhead                     ;
	drop table  slaccruals                       ;
	drop table  specialprice                     ;
	drop table  subdates                         ;
	drop table  t_cust                           ;
	drop table  tax_trans                        ;
	drop table  tel_ects_int                     ;
	drop table  temp_code                        ;
	drop table  tentrefund                       ;
	drop table  tmpbal                           ;
	drop table  tmprept                          ;
	drop table  transitware                      ;
	drop table  transpextras                     ;
	drop table  transprates                      ;
	drop table  user_cmpy                        ;
	drop view  v_prodhist                       ;
	drop table  v_salstatarea                    ;
	drop table  v_salstatarpr                    ;
	drop table  v_salstatcust                    ;
	drop table  v_salstatmgr                     ;
	drop table  v_salstatpart                    ;
	drop table  v_salstatrept                    ;
	drop table  v_salstatsale                    ;
	drop table  v_salstsalcus                    ;
	drop table  vouchernote                      ;
	drop table  vouchporcphdr                    ;
	drop table  work_center                      ;
	drop table  work_ctr_rate                    ;
	drop table  wwwparms                         ;


	#find this buggers:
	drop table  version                          ;
	drop table  source                           ;
	drop table  confirm                          ;
	drop table  action                           ;

    #found to be obsolete by manual check:

    drop table  assets;
    drop table  budget ;
    drop table  cartage ;
    drop table  deposit  ;
    drop table  disp_stats;
    drop table  faperiod   ;
    drop table  labour      ;
    drop table  maxmenu      ;
    drop table  menupath      ;
    drop table  postcode       ;
    drop table  postdebit       ;
    drop table  prochead         ;
    drop table  rates             ;
    drop table  region             ;
    drop table  relationship        ;
    drop table  uom_convert          ;


    drop table bin_code;
    drop table poslocation;
    drop table posstation;

    #Definitely NOT obsolete:
#    drop table  backup;     #U111.per
#	drop table  batch                            ;  #P24.4gl
#	drop table  asp_activate                     ;
#	drop table  asp_connect                      ;
#	drop table  asp_pref                         ;

end function


{
user	system	elapsed	CPU	text	data	inputs	outputs	major	swaps
______________________________________________________________________________
Command	exited	with	non-zero	status	2	0.99	0.26	0:02.05	60%	0	0	0
0	4089	0	user	system	elapsed	CPU	text	data	inputs	outputs	major	swaps
______________________________________________________________________________
Command	exited	with	non-zero	status	2	1.91	0.55	0:02.97	82%	0	0	0
0	8555	0	user	system	elapsed	CPU	text	data	inputs	outputs	major	swaps
______________________________________________________________________________
1.28	0.24	0:02.16	70%	0	0	0	0	4095	0	user	system	elapsed	CPU
text	data	inputs	outputs	major	swaps
______________________________________________________________________________
Command	exited	with	non-zero	status	2	1.39	0.26	0:01.71	96%	0	0	0
0	4275	0	user	system	elapsed	CPU	text	data	inputs	outputs	major	swaps
______________________________________________________________________________
3.71	1.30	0:07.04	71%	0	0	0	0	19049	0	user	system	elapsed	CPU
text	data	inputs	outputs	major	swaps
______________________________________________________________________________
Command	exited	with	non-zero	status	2	2.05	0.44	0:02.58	96%	0	0	0


after kill diff:


user	system	elapsed	CPU	text	data	inputs	outputs	major	swaps
______________________________________________________________________________
Command	terminated	by	signal	2	14467.01	1532.85	8:10:48	54%	0	0	0
0	6872	0	user	system	elapsed	CPU	text	data	inputs	outputs	major	swaps
______________________________________________________________________________
Command	exited	with	non-zero	status	2	1.58	0.83	0:21.37	11%	0	0	0
0	8972	0	user	system	elapsed	CPU	text	data	inputs	outputs	major	swaps
______________________________________________________________________________
1.59	0.53	0:02.70	78%	0	0	0	0	6423	0	user	system	elapsed	CPU
text	data	inputs	outputs	major	swaps
______________________________________________________________________________
Command	exited	with	non-zero	status	2	2.05	0.53	0:06.31	40%	0	0	0
0	6923	0

}


{**
 * Find all tables not referenced by 4gl (not per?) files as determined by
 * p4gl (fgldoc) (and loadform?) programs, and manually scan 4gl (and NOT per?)
 * files to extract references
 *
 * TODO: Fix p4gl (and loadform?) so that we don't need this function
 *
 *}
function fixup()
define
    all_process,report_file,run_string,module_basename,run_string2,load_string,
        full_path
        char(400),
    total_tables,total_doc4gl_tables,total_missing_tables,
	tables_with_process,tables_with_function,tables_with_form,
	cnt_process,cnt_function,cnt_form,tmp_stat,found_in_4gl,found_in_per,tmp_cnt,
    counter,obsoleted,total_obsolete_tables,p4gl_parse_error,total_p4gl_parse_error,
    brute_force, output_counter,total_not_exist,total_obsolete_not_removed,
    is_formonly,found_in_tag, buff_length, pos,found_function_name
        integer,
    tmp_id_process, process
        char(10),
    msg_txt char (180),
    oc char(2)

    let obsoleted = 0
    let total_p4gl_parse_error=0
	let report_file="fix-up.txt"
    let oc="{}"

    start report unused_tables to report_file

	create temp table dd_temp2(load_field char (300))

	select count(*) into total_tables
        from systables
            where tabid > 100
            and tabname not matches "p4gl_*"

    #deduct Doc4GL/DBdoc tables not prefixed with p4gl_ + dd_temp
	let total_tables = total_tables - 11


    select count (distinct tabname) into tables_with_process
        from p4gl_table_process

    select count (distinct tabname) into tables_with_function
        from p4gl_table_usage

    select count (distinct tabname) into tables_with_form
		from p4gl_form_table


	select count(*) into total_doc4gl_tables
        from systableext
            where tabname not matches "p4gl_*"

	select count(*) into total_missing_tables
        from systableext
            where tabname not matches "p4gl_*"
            and tabtype = "U"
			#Doc4GL table types are T=table V=view U=undefined E=tEmporary O=obsolete X=external

	select count(*) into total_obsolete_tables
        from systableext
            where tabname not matches "p4gl_*"
            and tabtype = "O"

	select count(*) into total_obsolete_not_removed
        from systableext
            where tabname not matches "p4gl_*"
            and tabtype = "O"
            and tabname in (select tabname from systables)

	select count(*) into total_not_exist from systableext
		where tabname not in (select tabname from systables)

	declare r16 cursor for
		select tabname from systables
			where tabname not in (select tabname from systableext)
			and tabname not matches "p4gl_*"
			and tabid > 100
	        and tabname <> "dd_temp"
	        and tabname <> "process"
	        and tabname <> "ext_table"
	        and tabname <> "ext_database"
	        and tabname <> "ext_column"
	        and tabname <> "table_process"
	        and tabname <> "sysmodules"
	        and tabname <> "d_modulos"
	        and tabname <> "d_mod_tab"
	        and tabname <> "systableext"
	        and tabname <> "syscolumnext"
	            order by tabname


	whenever error continue
        select count(*) into tmp_stat from dd_temp
        let tmp_stat=status
	whenever error stop

    if tmp_stat <> 0 then
            #display "Creating table dd_temp"
			#create table dd_temp (load_field char (300))
    else
	       #display "Cleaning dd_temp table  ."
		   #delete from dd_temp
           drop table dd_temp
    end if

    #must drop/create table every time to maintain line order
	display "Creating table dd_temp"
	create table dd_temp (load_field char (300))

    let counter = 0
    let output_counter = 0
    #######################################
	foreach r16 into p_systableext.tabname
    #######################################
        let counter = counter + 1

		display p_systableext.tabname clipped

        select count(*) into cnt_process
            from p4gl_table_process
                where tabname = p_systableext.tabname

        select count(*) into cnt_function
            from p4gl_table_usage
                where tabname = p_systableext.tabname

        select count(*) into cnt_form
            from p4gl_form_table
                where tabname = p_systableext.tabname

        #first see if we have this table flaged somewhere with @table:
		let run_string= "find /opt/aubit/apps/erp/src -name '*.4gl' -exec grep -l -i ",
			"'@table ",p_systableext.tabname clipped,"'",
			" ",oc," \\; > tmp.unl"

		#display run_string clipped
		run run_string
	    delete from dd_temp
		load from "tmp.unl" insert into dd_temp

		if status <> 0 then
			display "error loading"
			exit program 1
		end if

		select count(*) into found_in_tag from dd_temp
		if found_in_tag > 0 then
            #display "    flagged - ",p_systableext.tabname
            #p4gl probably crached on this module, we will fix it now:

			declare r17 cursor for
                select * from dd_temp

            ###########################
			foreach r17 into run_string
            ###########################
                if length(run_string) < 2 then
                    exit foreach
                end if

				let full_path=run_string
				let module_basename = my_basename(full_path)
				#display full_path clipped, " = ",module_basename clipped
				let process=strip(full_path,"/opt/aubit/apps/erp/src")
				#let process=strip(process,module_basename)

				let buff_length=length (process)
                for pos=buff_length to 1 step -1
                    if process[pos]="/" then
                        let process = process[2,pos-1]
                        exit for
                    end if
                end for

                let process = upshift(process)
				#    -accumulator-GW2g.4gl-GL-
                display "    -",p_systableext.tabname clipped, "-",module_basename clipped,"-",process clipped,"-"


                #############################
				#Check if we have this table:
                #Can happen when we find multiple references and already
                #added one or more.
				select * from systableext
                    where tabname = p_systableext.tabname
                if status = NOTFOUND then
	                #Insert table:
					insert into systableext (owner,tabname,tabtype)
						values ("root",p_systableext.tabname,"T")
                        #Doc4GL table types are T=table V=view U=undefined E=tEmporary O=obsolete
                end if


                #############################
				#check if we have this module:
				select * from p4gl_module
					where module_name = module_basename
                if status = NOTFOUND then
					#Insert module:
    	            insert into p4gl_module (module_name, id_package)
						values (module_basename, ".")
                end if

				##############################
				#check if we have this table in context of this process
                select * from p4gl_table_process
					where id_process = process
                    and owner = "root"
                    and tabname = p_systableext.tabname
                if status = NOTFOUND then
                    insert into p4gl_table_process (id_process,owner,tabname)
                        values (process,"root",p_systableext.tabname)
                end if

                ##############################
				#check if we have this table in the context of this module:
                select * from p4gl_table_usage
                    where module_name = module_basename
                    and id_package = "."
					and function_name matches "*" #<<< ???/
                    and owner = "root"
                    and tabname = p_systableext.tabname
                if status = NOTFOUND then
                    #But we don't know the function name - we got this from "grep"!
                    #And this relationship is a property of function - not module.
                    #so we will know there is a reference, but not from where...
                    #untill we no longer need to use this fix-up function (when
                    #p4gl stops crashing...)

					let run_string="grep -i -A 30 '@table ",p_systableext.tabname clipped,
						"' ", full_path clipped, #/opt/aubit/apps/erp/src/",utility/U11.4gl,
						" | grep -i '^function\\|^report' | cut -f 2 -d ' ' | cut -f 1 -d '('",
						" > tmp.unl"

					#display run_string clipped
					run run_string
                    delete from dd_temp2
					load from "tmp.unl" insert into dd_temp2

					if status <> 0 then
						display "error loading"
						exit program 1
					end if

					select count(*) into found_function_name from dd_temp2
					if found_function_name > 0 then

						declare tr17 cursor for
            			    select * from dd_temp2

			            #############################
						foreach tr17 into load_string
			            #############################

                        display "Function name is ",load_string clipped

						#check if we have this function
                        select * from p4gl_function
                            where id_package = "."
                            and module_name = module_basename
                            and function_name = load_string

                        if status = NOTFOUND then
                            insert into p4gl_function
                            (id_package,module_name,function_name)
                            values
                            (".",module_basename,load_string)
                        end if

		                insert into p4gl_table_usage
		                    (id_table_usage,module_name,id_package,function_name,owner,tabname,table_name,operation)
                            values
	                        (0,module_basename,".",load_string,"root",p_systableext.tabname,p_systableext.tabname,"X")
                            #X is for unknown Select Update Insert Delete

                        ###########
                        end foreach
                        ###########

                    else
                        display "Failed to extract function name for ",
                            p_systableext.tabname clipped,
                            " in ",full_path clipped
                    end if

                end if

			###########
			end foreach
            ###########
            continue foreach
        else
{
    >>>>>>>>>>> Not flagged - backup         U111.per
   >>>>>>>>>>> Not flagged - v_prodhist
}

			display "    >>>>>>>>>>> Not flagged - ",p_systableext.tabname

			output to report unused_tables(p_systableext.tabname,
					total_tables, total_doc4gl_tables,
                    total_missing_tables,
                  	tables_with_process,tables_with_function,tables_with_form,
                    cnt_process,cnt_function,cnt_form,found_in_per,found_in_4gl,
                    "Not flagged",obsoleted,total_obsolete_tables,total_p4gl_parse_error,
                    total_not_exist,total_obsolete_not_removed
				)

            continue foreach
		end if


    ###########
	end foreach
    ###########

    finish report unused_tables

	drop table dd_temp2

	if interactive then
		error report_file clipped, " created."
		let run_string= "less ",report_file
		run run_string
    else
        display "Fix-up finished"
	end if

end function #fixup()

{**
 * For each function call registeres by p4gl, find function/module called
 *
 *}
function function_calls()
define
    p_module_name,prog_group,previous_module_name,previous_calls_func_name,
    module_basename
        char(64),
    params_passed, params_to_return,
	params_expected,params_returned,
    in_this_module,function_called_cnt,match_cnt,in_this_process,
    in_this_group, target_match_cnt, same_targets, cnt, this_match_id,
    err_cnt,all_same,calling_target_cnt,prev_mach_id,err_nofunction,
    err_parameters,err_makefile,err_makefile_multi,defined_cnt,tmp_cnt,
    did_match,ret
        smallint,
	still_unresolved_calls,no_called_function,
	resolved_calls,total_calls
        integer,
    calling_func_process
        char (20),
	run_string,load_string
		char (300),
	pa_match array [200] of record
		id_package char(64),
		module_name char(64),
		function_name char(50)
    end record,
	pa_matches array [200] of record
		match_id smallint
    end record


    let do_insert = false
	let err_cnt = 0
	let err_nofunction = 0
	let err_parameters = 0
	let err_makefile = 0
	let err_makefile_multi = 0


    let insert_disabled = 0

	let reason_1 = 0
	let reason_2 = 0
	let reason_3 = 0
	let reason_4 = 0
	let reason_5 = 0
	let reason_6 = 0
	let reason_7 = 0

    initialize previous_module_name to null
	initialize previous_calls_func_name to null


    display "Initiating...please wait..."

	create temp table dd_temp2(load_field char (300))

    declare f1 cursor for
        select * from p4gl_function_call
            where function_call_id not in
				(select function_call_id from p4gl_func_calls)
            #let's not try to resolve calls to function that we failed to
            #register (p4gl probably crashed)
			#...or maybe we can grep for them? Hopefully Sergio will fix p4gl so we don't have to...
			and exists (select * from p4gl_function where
               p4gl_function.function_name = p4gl_function_call.calls_func_name)
            #we need order by for testing if we already processed this call
			order by module_name,calls_func_name

	######################################
	foreach f1 into p_p4gl_function_call.*
    ######################################
        #for each function call registered

        if p_p4gl_function_call.module_name = previous_module_name
        and p_p4gl_function_call.calls_func_name = previous_calls_func_name
        then
            #skip it - we already set all calls to this function originating in
			#that module - or we failed to resolve it
			if debug2 then
                display "Already processed, skip..."
            end if
			continue foreach
        else
        	#new module/called function combination
			if debug2 then
                display "New module/called function combination..."
            end if
			let previous_module_name = p_p4gl_function_call.module_name
			let previous_calls_func_name = p_p4gl_function_call.calls_func_name
        end if


        #Get number of functions with name of the called function
		select count(*) into function_called_cnt from p4gl_function
                where function_name = p_p4gl_function_call.calls_func_name

        #get number of parameters passed in a call
        select count(*) into params_passed from p4gl_call_parameter
            where function_call_id = p_p4gl_function_call.function_call_id

        #get number of parameters expected to be returned by this call
        select count(*) into params_to_return from p4gl_call_returning
            where function_call_id = p_p4gl_function_call.function_call_id

        display "========== ",p_p4gl_function_call.function_name clipped,
        " (",params_passed using "<&","/",params_to_return using "<&",
        ") in ",p_p4gl_function_call.module_name clipped,
		" ==> ",p_p4gl_function_call.calls_func_name clipped

		if function_called_cnt = 1 then
            #we got only one function with this name - great!

            #get module name for the function called
			select module_name into p_module_name
                from p4gl_function
                    where function_name = p_p4gl_function_call.calls_func_name

			call insert_function_calls
   	            (p_p4gl_function_call.function_call_id,
				".",
				p_module_name,
				p_p4gl_function_call.calls_func_name,
				p_p4gl_function_call.function_name,
				p_p4gl_function_call.module_name,
				"only one",1)

				#p_p4gl_function_call.calls_func_name,
				#p_p4gl_function_call.calls_module_name)

            continue foreach
        else
       		if function_called_cnt = 0 then
                #probaly p4gl crashed...
				
                #Maybe we can grep for them - if we disable checking if function 
				#exists at all in cursor definition...

				#we are explicity asking for functions called that DO exist!
				display "Should not happen!!!"
                exit foreach


				#display "cannot find function named ",
					#p_p4gl_function_call.calls_func_name clipped
                let err_cnt = err_cnt + 1
                let err_nofunction = err_nofunction + 1
                continue foreach
            end if

			#there are multiple functions with same name
            display "Found ", function_called_cnt using "<<<&", " functions named ",
                p_p4gl_function_call.calls_func_name

	        declare f2 cursor for
    	        select * from p4gl_function
        	        where function_name = p_p4gl_function_call.calls_func_name
                    and id_package = p_p4gl_function_call.id_package

{
FIXME: p4gl does not track if call was to a function or report!

function_type F R

call_type F

}

			if debug then
                display "FIXME: faking parameters check..."
            end if

			let match_cnt=0
            #################################
			foreach f2 into p_p4gl_function.*
            #################################
            #for each function with called name...

		        #get number of parameters expected by this functions
		        select count(*) into params_expected from p4gl_fun_parameter
        		    where id_package = p_p4gl_function.id_package
                    and module_name = p_p4gl_function.module_name
                    and function_name = p_p4gl_function.function_name

#TODO: p4gl_fun_return table is populated only form commnets, not from code
                #get number of parameters returned by this function
		        select count(*) into params_returned from p4gl_fun_return
        		    where id_package = p_p4gl_function.id_package
                    and module_name = p_p4gl_function.module_name
                    and function_name = p_p4gl_function.function_name

                #FIXME: we should really ignore zero counts for now, because
                #we are not extracting some of this information, but we can't
                #since this would exclude all functions not passing or returning
                #anything...


{ FIXME:

we cannot rely on this: see function show_hold in holdwind.4gl and stopwind.4gl

In first one:
	1) p4gl extracted only first parameter
	2) comment is garbage
 In second one:
	p4gl registered function, but NOT the parameter!

In both cases, returns where not extracted at all (currently p4gl only
extracts returns from comments, not from the code)

even worse, tables p4gl_call_parameter and p4gl_call_returning are not
populated at all at the moment!
}

                if 1=1 then
				#disabled - see FIXME note below
				#if (params_expected = params_passed) then
					if debug2 then
						display "OK: params expected: ",params_expected using "<&",
							" passed: ", params_passed using "<&"
                    end if

	                if 1=1 then
					#disabled - see FIXME note below
					#if (params_returned = params_to_return) then
                        #this function receives and returns exact NUMBER of
                        #parameters as we have in the call
						if debug2 then
            	            display "OK: params returned: ",params_returned using "<&",
								" to return: ",params_to_return using "<&"
                        end if


                        #TODO: now check data types of parameters in call and return
                        #based on item_num
                        if 1=1 then
                            #variable types and there positions in call/return match

                            let match_cnt=match_cnt+1
                            let pa_match[match_cnt].id_package = p_p4gl_function.id_package
                            let pa_match[match_cnt].module_name = p_p4gl_function.module_name
                            let pa_match[match_cnt].function_name = p_p4gl_function.function_name
                        end if

					else
						if debug2 then
							display "WRONG: params returned: ",params_returned using "<&",
								" to return ",params_to_return using "<&",
	                            " in ", p_p4gl_function.module_name clipped
                        end if
					end if
                else
					if debug2 then
					display "WRONG: params expected: ",params_expected using "<&",
						" passed ", params_passed using "<&",
                        " in ", p_p4gl_function.module_name clipped
                    end if
				end if

            ###########
			end foreach
            ###########
       	    close f2
	    	free f2


            if match_cnt = 1 then
                #only one function with this name matches call/return parameters
				
				#should not happen because we disabled this above...

                display "what the ... ????"
                exit program

				call insert_function_calls
	   	            (p_p4gl_function_call.function_call_id,
                    pa_match[match_cnt].id_package,
                    pa_match[match_cnt].module_name,
                    pa_match[match_cnt].function_name,
					p_p4gl_function_call.function_name,
					p_p4gl_function_call.module_name,
					"only one matching parameters",2)

					#p_p4gl_function_call.calls_func_name,
					#p_p4gl_function_call.calls_module_name)
				#exit program
	            continue foreach

            else
	            if match_cnt = 0 then
                    display "Unable to match - no function matches this call's parameters/returns!"
	                let err_cnt = err_cnt + 1
                    let err_parameters = err_parameters + 1
                    if exit_on_error then
						exit foreach
                    else
                        continue foreach
                    end if
                else
					#multiple functions with this name matches call/return parameters

                    #First, see if we have this function name in the same module where call is
                    select count(*) into in_this_module
                        from p4gl_function
                            where module_name = p_p4gl_function_call.module_name
                            and id_package = p_p4gl_function_call.id_package
                            and function_name = p_p4gl_function_call.calls_func_name

                    if in_this_module = 1 then
                        #called function is in the same module as the call

						call insert_function_calls
			    	            (p_p4gl_function_call.function_call_id,
								p_p4gl_function_call.id_package,
								p_p4gl_function_call.module_name,
								p_p4gl_function_call.calls_func_name,
								p_p4gl_function_call.function_name,
								p_p4gl_function_call.module_name,
								"in same module as calling function",3)

                        continue foreach

                    end if

                    #Maybe we can find only one function with this name in same process?

					#Get process of the calling function
                    select id_process into calling_func_process
                        from p4gl_fun_process
                            where id_package = p_p4gl_function_call.id_package
                            and module_name = p_p4gl_function_call.module_name
                            and function_name = p_p4gl_function_call.function_name

					select count(*) into in_this_process
                        from p4gl_fun_process
                            where id_process = calling_func_process
                            and id_package = p_p4gl_function_call.id_package
                            and function_name = p_p4gl_function_call.calls_func_name

                    if in_this_process = 1 then
                        #there is only one function with called name in this process
                        #we can assume (but not be absolutely sure!)
                        #this is the one
						
						#get module name of that one
						select module_name into  p_module_name
	                        from p4gl_fun_process
	                            where id_process = calling_func_process
	                            and id_package = p_p4gl_function_call.id_package
	                            and function_name = p_p4gl_function_call.calls_func_name

						call insert_function_calls
			    	            (p_p4gl_function_call.function_call_id,
								p_p4gl_function_call.id_package,
								p_module_name,
								p_p4gl_function_call.calls_func_name,
								p_p4gl_function_call.function_name,
								p_p4gl_function_call.module_name,
								"only one in same process",4)

						continue foreach

                    end if


                    #Maybe we can find only one function with this name in same
                    #file name prefix? (P12a P12b ...)
					let prog_group = get_group(p_p4gl_function_call.module_name)
					#display prog_group clipped ," = ", p_p4gl_function_call.module_name clipped
                    let prog_group = prog_group clipped, "*"

                    select count(*) into in_this_group
						from p4gl_function
                         where module_name matches prog_group
                         and id_package = p_p4gl_function_call.id_package
                         and function_name = p_p4gl_function_call.calls_func_name

                    if in_this_group = 1 then
                        #there is only one function with name called in this
                        #group of modules (based on file name) so we can assume
                        #(but can not be sure!) this is the one called

						#get module name of that one
						select module_name into  p_module_name
	                        from p4gl_function
	                         where module_name matches prog_group
	                         and id_package = p_p4gl_function_call.id_package
	                         and function_name = p_p4gl_function_call.calls_func_name

						call insert_function_calls
			    	            (p_p4gl_function_call.function_call_id,
								p_p4gl_function_call.id_package,
								p_module_name,
								p_p4gl_function_call.calls_func_name,
								p_p4gl_function_call.function_name,
								p_p4gl_function_call.module_name,
								"only one in module group (based on file name)",5)

						continue foreach
                    else
	                    if in_this_group = 0 then
                            display "No function called ",
								p_p4gl_function_call.calls_func_name clipped,
                                " in module group ",prog_group clipped
                        else
                            display in_this_group using "<<&"," function called ",
								p_p4gl_function_call.calls_func_name clipped,
                                " in module group ",prog_group clipped
                            display "TODO: rename this functions to make then unique!"
                        end if
                    end if

                    #Only thing we can do now (?) is to scan modules belonging to the
                    #same program. But module where call originates can belong
                    #to multiple programs - so which program do we look in?

                    declare f3 cursor for
                        select * from p4gl_module_prog
                            where module_name = p_p4gl_function_call.module_name

                    let target_match_cnt = 0 #here or after FOREACH ?
                    let calling_target_cnt = 0

                    #foreach target module conainining calling function is part of...
					####################################
					foreach f3 into p_p4gl_module_prog.*
                    ####################################

                        display "calling function in module ",
							p_p4gl_function_call.module_name clipped,
                            " is part of target ",
                            p_p4gl_module_prog.program_name clipped

                        let calling_target_cnt=calling_target_cnt+1

						#look for called function(in array of functions macking
						#call/retunr parameters) in same target...
	                    ########################
						for cnt = 1 to match_cnt
                        ########################
                        #for each function macking call/return parameters...
                            {
							if debug2 then
								display "select count(*) same_targets from p4gl_module_prog"
								display "module_name =",pa_match[cnt].module_name clipped,"="
								display "program_name =",p_p4gl_module_prog.program_name clipped,"="
								display "id_package =",pa_match[cnt].id_package clipped,"="
                            end if
                            }

							#See how many targets use this module to define same
                            #target as our calling function is part of
							select count(*) into same_targets from p4gl_module_prog
                            	where module_name = pa_match[cnt].module_name
                                and program_name = p_p4gl_module_prog.program_name
                                and id_package =pa_match[cnt].id_package

	        	            if same_targets = 1 then
                                #function called we found in in this module
                                #is part of EXACTLY ONE target as the function/module
                                #making the call
                                let target_match_cnt = target_match_cnt + 1
                                let pa_matches[target_match_cnt].match_id = cnt

								if debug2 then
									display "function ",
										pa_match[cnt].function_name clipped,
	                                    " in module ", pa_match[cnt].module_name clipped,
	                                    " is part of same target ",
	                                    p_p4gl_module_prog.program_name clipped
                                end if
                            else
                                if same_targets > 1 then
                                    display "should not happen?"
                                    #unless some make file specifies same module more then once...
                                    exit program
                                else
                                    #this function/module has same name and same
                                    #parameters as the one we called, but is not part
                                    #of the same target(s) (as per existing makefiles)
                                    #as the module we made the call from
									if debug2 then
										display "function ",
											pa_match[cnt].function_name clipped,
	                                        " in module ", pa_match[cnt].module_name clipped,
	                                        " is NOT part of target ",
		                                    p_p4gl_module_prog.program_name clipped
                                    end if
								end if
                            end if

	                    #######
						end for
                        #######

#p11.mk:			stopwind.4gl \

                    ###########
					end foreach
                    ###########
		      	    close f3
    				free f3


                    if target_match_cnt = 1 then
						let this_match_id = pa_matches[target_match_cnt].match_id
						call insert_function_calls
			    	            (p_p4gl_function_call.function_call_id,
								pa_match[this_match_id].id_package,
								pa_match[this_match_id].module_name,
								pa_match[this_match_id].function_name,
								p_p4gl_function_call.function_name,
								p_p4gl_function_call.module_name,
								"only one in program definition based on make file",6)

                        continue foreach

                    else

						if calling_target_cnt > 1 then
                            display "originating module is part of ",
								calling_target_cnt ," targets"
                        end if

                        if target_match_cnt = 0 then
							display "WARNING: unable to match-no makefile uses module ",
								p_p4gl_function_call.module_name clipped
                            display "         together with any of modules containing the function name called."
	                        #display "         target_match_cnt=",target_match_cnt
			                let err_cnt = err_cnt + 1
                            let err_makefile = err_makefile + 1

                            
							#TODO: remove all this grep-ing when p4gl is working properly
							#get list of all files containing function:
							let run_string='find ./src -name "*.4gl" -exec grep -i -l -w "function ',
								pa_match[this_match_id].function_name clipped,'" {} \\; > tmp.unl'

							#display run_string clipped
							run run_string
		                    delete from dd_temp2
							load from "tmp.unl" insert into dd_temp2

							if status <> 0 then
								display "error loading"
								exit program 1
							end if

							select count(*) into defined_cnt from dd_temp2

							if defined_cnt > 0 and defined_cnt <> match_cnt then

								declare ftr17 cursor for
		            			    select * from dd_temp2

					            #############################
								foreach ftr17 into load_string
					            #############################

                                    let did_match = false
				                    ########################
									for cnt = 1 to match_cnt
			                        ########################
			                        #for each function macking call/return parameters...

                                        #./src/common/tablefunc.4gl
                                        let module_basename = my_basename(load_string)

										if module_basename = pa_match[cnt].module_name then
                                            #that module I got from grep is on the list
                                            let did_match = true
											exit for
                                        end if

                                    #######
                                    end for
                                    #######

                                    if not did_match then
			                            #check if p4gl really failed to parse:
										let run_string ="grep -i tablefunc.4gl /tmp/p4gl.log > /dev/null"
                                        run run_string returning ret
										LET ret = ret / 256
										if ret = 0 then
	                                        display "Module ",module_basename clipped,
                                            " failed to parse."
                                        else
	                                        display "Module ",module_basename clipped,
                                            " failed to parse - but NOT in /tmp/p4gl.log!"
                                        end if
                                    end if

                                ###########
								end foreach
                                ###########
                                close ftr17
                                free ftr17


                            end if

                            if 1 = 0 then #disabler
							#get NUMBER of function containing phrase "function CalledFuncName":
                            let run_string = 'x=`find ./src -name "*.4gl" -exec grep -i -l -w "function ',
								pa_match[this_match_id].function_name clipped,
								'" {} \\; | grep -c ".4gl"`; exit $x'
							#display run_string clipped
							run run_string returning defined_cnt
                            {
							4.1.10 Why are RUN's return codes screwy?
							Because return codes have been multiplied by 256.

							exit 1 - check for 256
							exit 2 512 etc...
							so:
							RUN "someprogram" RETURNING l_exit
							LET l_exit = l_exit / 256
							Note that this apparently is not a problem on all hardware platforms :-(
                            }

                            LET defined_cnt = defined_cnt / 256
                            end if #disabler

                            display "scaned function ",pa_match[this_match_id].function_name clipped,": ",match_cnt
							display "defined in modules :",defined_cnt
                            let tmp_cnt =defined_cnt-match_cnt
							display "modules containing ",
								pa_match[this_match_id].function_name clipped,
								" that failed to parse:",tmp_cnt

{ 

p4gl parser creates one temporaty file from 4gl module it's scanning and ALL
files declared as GLOBALS "filename.4gl" BEFORE it parses it.

Therefore, if there are functions defined in GLOBALS file(s), p4gl will think
that function really declared in GLOBALS file(s) are declared in file declaring
GLOBALS statement - WHICH IS FALSE.

Options to fix this:

1) remove all function declarations from files used as GLOBALS. This is generaly
    a good idea, and we might need to do this anyway for OneMaxx, but Doc4GL is
    supposed to work for all valid 4gl programs, and it is perfectly OK by
    rules of 4GL language to have functions in modules used ad GLOBALS

2) change p4gl to include only GLOBALS ... END GLOBALS block in temp file used
    for parsing, and exclude all FUNCTION, MAIN and REPORT blocks.
    I think this is prefered option.


========= process_order (0/0) in E11.4gl ==> write_order

calling function in module E11.4gl is part of target E11

./src/eo/E11h.4gl
./src/qe/Q11h.4gl

function write_order in module po_add.4gl is NOT part of target E11     NOT - po_mod is GLOBALS
function write_order in module po_chng.4gl is NOT part of target E11   NOT - po_mod is GLOBALS


OK:
./src/qe/Q18a.4gl
function write_order in module Q18a.4gl is NOT part of target E11

./src/common/po_mod.4gl
function write_order in module po_mod.4gl is NOT part of target E11

}

                            if tmp_cnt = 0 then
								#Cannot match, and cannot find out why this target function is missing
								display "SHOULD NOT HAPPEN! Is /tmp/p4gl.log empty?"
								if exit_on_error then
			                        exit foreach
	                            else
	                                continue foreach
	                            end if
                            else
	                            if tmp_cnt = 1 then
display "TODO - insert me"
									{
									let this_match_id = pa_matches[1].match_id
									call insert_function_calls
					    	            (p_p4gl_function_call.function_call_id,
										pa_match[this_match_id].id_package,
										pa_match[this_match_id].module_name,
										pa_match[this_match_id].function_name,
										p_p4gl_function_call.function_name,
										p_p4gl_function_call.module_name,
										"only one in target definition based on makefile-multiple targets but all same",7)
                                    }
                                else
                                    display "Multiple modules failed to parse - will NOT insert"
								end if
								continue foreach
                            end if
                        else
							if calling_target_cnt > 1 then
                                #check if they all point to the same one:
                                let all_same=true
								for cnt = 2 to target_match_cnt
	                                let this_match_id=pa_matches[cnt].match_id
                                    let prev_mach_id=pa_matches[cnt-1].match_id
                                    if pa_match[this_match_id].module_name <> pa_match[prev_mach_id].module_name then
										if debug2 then
											display pa_match[this_match_id].module_name clipped,
												"<>", pa_match[prev_mach_id].module_name clipped
                                        end if
										let all_same = false
                                        exit for
                                    end if
                                end for
	                            if all_same then
									#we can pick any one match_id, since data will be the same
									let this_match_id = pa_matches[1].match_id
									call insert_function_calls
					    	            (p_p4gl_function_call.function_call_id,
										pa_match[this_match_id].id_package,
										pa_match[this_match_id].module_name,
										pa_match[this_match_id].function_name,
										p_p4gl_function_call.function_name,
										p_p4gl_function_call.module_name,
										"only one in target definition based on makefile-multiple targets but all same",7)

	                                continue foreach
	                            end if

							end if

							#TODO: what now?
							display "WARNING: unable to match - multiple matches:"
	                        display "         target_match_cnt=",target_match_cnt
	                        display "         SHOULD NOT HAPPEN!"
			                let err_cnt = err_cnt + 1
                            let err_makefile_multi = err_makefile_multi + 1
	                        if exit_on_error then
								exit foreach
                            else
                                continue foreach
                            end if
                        end if
					end if


                end if
            end if

        end if #function_call_cnt = 1

    ###########
	end foreach
    ###########
    close f1
   	free f1

    drop table dd_temp2

    display ""
	display "Total Errors (unable to match):",err_cnt
	display "No matching function name:",err_nofunction
	display "No matching parameters:",err_parameters
	display "No match based on makefile:",err_makefile
	display "No match because of multiple makefiles/targets:",err_makefile_multi
    display ""
	display reason_1 using "####&"," unique"
	display reason_2 using "####&"," unique matching parameters"
	display reason_3 using "####&"," in same module as calling function"
	display reason_4 using "####&"," unique in same process (directory)"
	display reason_5 using "####&"," unique in module group (based on file name)"
	display reason_6 using "####&"," unique in target definition based on makefile"
	display reason_7 using "####&"," unique in target definition based on makefile-multiple targets" # but all same

    display ""

    let reason_1 = reason_6 + reason_7
	display "Had to use makefile to resolve calls ",reason_1 using "###&", 
		" times - not good"
    display ""

		select count (*) into still_unresolved_calls from p4gl_function_call
            where function_call_id not in
				(select function_call_id from p4gl_func_calls)
                #order by function_name
            and exists (select * from p4gl_function where
               p4gl_function.function_name = p4gl_function_call.calls_func_name)

    display still_unresolved_calls using "####&"," calls still unresolved"

{

  586 calls still unresolved
23081 calls have no called function registered in Doc4GL db
17039 calls resolved, out of 40706

}

#takes forever....
		select count (*) into no_called_function from p4gl_function_call
            where
				#I don't care if call was resolved or not - it cannot be anyway if function does not exist?
				#function_call_id not in
				#(select function_call_id from p4gl_func_calls)
                #and
            #not exists (select * from p4gl_function where
            #   p4gl_function.function_name = p4gl_function_call.calls_func_name)
            function_name not in
            (select function_name from p4gl_function where
				p4gl_function.function_name = p4gl_function_call.calls_func_name)


    display no_called_function using "####&",
		" calls have no called function registered in Doc4GL db" #p4gl crashed or failed otherwise

		select count (*) into resolved_calls from p4gl_func_calls
		select count (*) into total_calls from p4gl_function_call

    display resolved_calls using "####&"," calls resolved, out of ", 
		total_calls  using "####&"
	display insert_disabled using "####&", " resolved calls not inserted (unsure)"
	display ""

{
select count(*) a, function_name
from p4gl_function
where function_name <> "main"
group by function_name
having count(*) > 1
order by a desc

               a function_name

              53 set_defaults
              43 get_info
              36 afile_status
              36 query
              35 auto_print
              32 doit
              19 scan_orders
              19 select_orders
              19 make_prompt
              16 initialize_ord
              16 process_order
              16 select_cust
              15 disp_hdr
}

##########################################################
#FIXME: mkf.4gl is not processing libraries - see P21.mk
#after this is done, we will have to, when using make files to determine function
#calls, first expand file list of targets to inslude files as specified by .lib
#target(s) !!!!
##########################################################


end function #function function_calls()


{**
 * insert function call relationship in the database
 *
 *}
function insert_function_calls(function_call_id,calls_id_package,calls_module_name,
	calls_func_name,calling_function_name,calling_module_name,explain_txt,explain_type)
define
	function_call_id
		integer,
	calls_id_package
        char (64),
	calls_module_name, calling_module_name
        char(64),
	calls_func_name,calling_function_name
        char(50),
    explain_txt
        char(80),
    explain_type
        smallint

	display "function ",calling_function_name clipped," in ",
		calling_module_name clipped, " calls ",
		calls_func_name clipped, " in ",
        calls_module_name clipped

    display "   ",explain_txt clipped

	let do_insert = false

    case explain_type
        when 1  #" only one"
            #certenty: 100% (unless all functions failed to register with p4gl)
            let do_insert = true
			let reason_1 = reason_1 + 1
        when 2  #" only one matching parameters"
            #certenty: 0% (p4gl currently does not extract all information)
			#let do_insert = true
			let reason_2 = reason_2 + 1
        when 3  #" in same module as calling function"
            #certenty: 100%
			let do_insert = true
			let reason_3 = reason_3 + 1
        when 4  #" only one in same process"
            #certenty: moderate
			let do_insert = true
			let reason_4 = reason_4 + 1
        when 5  #" only one in module group (based on file name)"
            #certenty: moderate
			let do_insert = true
			let reason_5 = reason_5 + 1
#TODO: after parameters checking is working, we should be able to disable the
#following two:
		when 6  #" only one in program definition based on make file"
            #certenty: 100% but we should not use it to remove dependency on make files
			let do_insert = true
			let reason_6 = reason_6 + 1
        when 7  #"only one in program definition based on make file-multiple targets but all the same"
            #certenty: 100% but we should not use it to remove dependency on make files
			let do_insert = true
			let reason_7 = reason_7 + 1
        otherwise
            display "Invalid reason ",explain_type
            exit program
    end case



	if do_insert then
		
		{
		insert into p4gl_func_calls
	    (function_call_id,calls_id_package,calls_module_name,calls_func_name)
	    values
	    (function_call_id,calls_id_package,
		calls_module_name,calls_func_name)
        }

        #Now we know that all function calls made to function calls_func_name
        #from module calling_module_name will be callint calls_func_name in
        #calls_module_name - so insert this relationship for them all:

        declare i1 cursor for
        select * from p4gl_function_call
            where p4gl_function_call.id_package = calls_id_package
            and p4gl_function_call.module_name = calling_module_name
            and p4gl_function_call.calls_func_name = calls_func_name

		######################################
		foreach i1 into p_p4gl_function_call.*
        ######################################
        #for each call to function calls_func_name originating in module calling_module_name

			insert into p4gl_func_calls
		    (function_call_id,calls_id_package,calls_module_name,calls_func_name)
		    values
		    (p_p4gl_function_call.function_call_id,p_p4gl_function_call.id_package,
			calls_module_name,p_p4gl_function_call.calls_func_name)

        ###########
		end foreach
        ###########
	    close i1
   		free i1

    else
        let insert_disabled = insert_disabled + 1
	end if

	let do_insert = false


end function


{**
 * Get program group module belongs to based on file name (P11a, P11b, ...)
 *
 *}
function get_group(module_name)
define
    module_group, module_name
        char (64),
    module_name_lenght, cnt, reached_numbers
        smallint

    let module_name = upshift(module_name)
    let module_name_lenght = length(module_name)

	#strip .4gl extension
    if module_name[module_name_lenght-4,module_name_lenght] = ".4GL" then
        let module_name = module_name[1,module_name_lenght-4]
	    let module_name_lenght = length(module_name)
    end if

    #strip ALL characters after numbers
    let reached_numbers = false
    initialize module_group to null
	for cnt = 1 to module_name_lenght
        if module_name[cnt] matches "[0-9]" then
            let reached_numbers = true
        else
            if reached_numbers then
                #already passed numbers
                let module_group = module_name[1,cnt-1]
                exit for
            end if
        end if
    end for

    if module_group is not null then
	    return module_group
    else
        return module_name
    end if

end function

{**
 * Add modules specified by library to modules associated with target using the library
 *
 *}
function expand_libs()
define
    p_module_name, p_program_name, p_id_package
        char(64),
    counter, tmp_cnt
        smallint

    declare l1 cursor for
    select distinct program_name, id_package
        from p4gl_module_prog
            where module_name matches "*.lib"

    let counter = 0
    ############################################
	foreach l1 into p_program_name, p_id_package
    ############################################
    #for each target that have .lib in it's definition....

        let counter = counter + 1
        display "Target ", p_program_name clipped," uses library(es):"

        declare l2 cursor for
            select distinct module_name
                from p4gl_module_prog
	            where module_name matches "*.lib"
                and program_name = p_program_name

        #############################
		foreach l2 into p_module_name
        #############################
        #for each library that is used by that target...


            display "      ",p_module_name clipped

            declare l3 cursor for
                select * from p4gl_module_prog
                where program_name = p_module_name #library name (.lib)

            ####################################
			foreach l3 into p_p4gl_module_prog.*
            ####################################
            #for each module specified by this library...

                #check if this module is already associated with this target
				select count(*) into tmp_cnt
                    from p4gl_module_prog
                        where program_name = p_program_name
                        and module_name = p_p4gl_module_prog.module_name

                if tmp_cnt = 0 then
                    display "Inserting module ",p_p4gl_module_prog.module_name clipped,
                        " to target ",p_program_name clipped

                    #check if we have this module
                    select * from p4gl_module
                        where module_name = p_p4gl_module_prog.module_name

                    if status = NOTFOUND then
                        #Add module to satisfy the constraint
						insert into p4gl_module
                            (id_package,module_name)
                            values (p_id_package,p_p4gl_module_prog.module_name)

                    end if

                    #insert this module in this target's definition
                    insert into p4gl_module_prog
                        (program_name,id_package,module_name)
                        values (p_program_name,p_id_package,p_p4gl_module_prog.module_name)

                else
                    display "WARNING: module ",p_p4gl_module_prog.module_name clipped,
                        " already in definition of target ",p_program_name clipped
                end if

            ###########
            end foreach
            ###########
            close l3
            free l3

            #remove .lib module from that target:
			delete from p4gl_module_prog
                where module_name = p_module_name  #library name (.lib)
                and program_name = p_program_name
                and id_package = p_id_package


        ###########
		end foreach
        ###########
        close l2
        free l2
    ###########
	end foreach
    ###########
    close l1
    free l1

    display "Expanded ",counter using "<<<&"," targets using libraries."

end function #expand_libs()

# =============================== EOF ==================================
