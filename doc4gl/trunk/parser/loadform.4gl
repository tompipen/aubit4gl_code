{**
 * This program performs folowing functions:
 *
 * - Loads form file attibutes extracted using Aubit fcompile in databse
 *
 * - Processes loaded data to establish relatinshops between form, table, clumn,
 *   and stores all data in appropriate Doc4GL/DBdoc tables
 *
 *

 Inserts into tables:

dd_temp
p4gl_form_attribute_type
p4gl_form
p4gl_form_process
systableext
syscolumnext
p4gl_form_table
p4gl_form_column
p4gl_table_process
p4gl_form_attribute
p4gl_column_process




 *}

#this allows DEFINE LIKE to be used without causing attempt to connect to this
#database at run-time, but will work only with 4Js and Aubit.
#replace with DATABASE stmt if you need to
#schema maxdev
database maxdev

define
	p_p4gl_form record like p4gl_form.*,
	p_p4gl_process record like p4gl_process.*,
    p_p4gl_form_column record like p4gl_form_column.*,
    p_p4gl_table_process record like p4gl_table_process.*,
	p_p4gl_form_table record like p4gl_form_table.*,
	p_systableext record like systableext.*,
	p_syscolumnext record like syscolumnext.*,

	l_fname, do_one_form char(264),
    debug, warnings, verbose
        smallint,
    hush
        char(1)

{**
 * Main function
 *
 *}
####
main
####
define
	type, uid, pwd, db char (20)

	# Change to the database on the following line to point to the
	# database you wish to store your mapfile data in
	#database informix

    let debug = false    	#show debugging messages
    let warnings = true     #show warning messages
    let verbose = false     #show details of what you are doing

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


        case type
            when "dd"
                call load_dd()
            when "ddp"
                call process_dd()
			when "cnt"
				call count_data()
            when "clean"
                call clean()
			otherwise
                display "ERROR: unknown type"
        end case

		#CLOSE SESSION s_ifmx
        close database

	else
       case arg_val(1)
		when "interactive"
    		let db = "maxdev"
			database db
			call main_menu()
		when "clean"
    		let db = "maxdev"
			database db
            call clean()
		when "cnt"
    		let db = "maxdev"
			database db
			call count_data()
	   otherwise
		   display "Usage:"
		   display "loadmap file_name uid pwd db [dd|ddp|clean|cnt]"
		   display "loadmap [interactive|clean|cnt]"
		   display ""
       end case
	end if

	call flag_ext_tables()


end main


{**
 *
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
 *
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
 *
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
 *
 *
 *}
function main_menu()

    menu "loadform"
        command "Reports"

            menu "Reports"
                command "1Tables by process" "Tables listed alphabeticaly, with all processes they belong to"
                    call rep_table_process()

                command "2Process/table" "Tables grouped by process"
                    call rep_process_table()

                command "3Unused" "TODO-Modules not referenced by make files"

                command "4Unused" "Tables not referenced by 4gl or per files"
                    call rep_unused_tables()

				command "exit" "Exit program"
		            exit menu
            end menu

        command "Utility"

			menu "Utility"
                command "Drop obsolete" "Drop all tables marked obsolete"
                    call drop_obsolete()

				command "exit" "Exit program"
		            exit menu
            end menu

		command "exit" "Exit program"
            exit menu
    end menu

end function


function drop_obsolete()


    declare rd1 cursor for
	select tabname
        from systableext
            where tabname not matches "p4gl_*"
            and tabtype = "O" #Doc4GL table types are T=table V=view U=undefined E=tEmporary O=obsolete
            and tabname in (select tabname from systables)


    foreach rd1 into p_systableext.tabname
        display "drop table ",p_systableext.tabname clipped, ";"



	end foreach


end function


#Some tables are used by code external to our current source code tree-like ASP framework

{**
 *
 *
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
 *
 *
 *}
function rep_table_process()
define
    all_process,report_file
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

end function

{**
 *
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
        print
            "tables related/unrelated to process:", process_tables using "<<<<","/",total_tables-process_tables using "<<<<",
            "(",((process_tables*100)/total_tables) using "<<<<","%)"

		PRINT
"_________________________________________________________________"


END REPORT

{**
 *
 *
 *}
function rep_process_table()
define
    all_process,report_file
        char(200),
    total_tables,process_tables,this_process_ref_form,process_ref_form
        smallint,
    tmp_id_process
        char(10)

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


    declare r3 cursor for
        select distinct id_process
            from p4gl_process
                order by id_process

    foreach r3 into p_p4gl_process.id_process

	    declare r4 cursor for
            select distinct tabname
                from p4gl_table_process
                    where id_process = p_p4gl_process.id_process
                        order by tabname

        foreach r4 into p_p4gl_table_process.tabname

			#let process_tables = process_tables + 1

            select count(*) into this_process_ref_form
				from p4gl_form_table, p4gl_form_process
                where p4gl_form_table.tabname = p_p4gl_table_process.tabname
                and p4gl_form_process.id_process = p_p4gl_process.id_process
                and p4gl_form_process.form_id = p4gl_form_table.form_id

		    declare r5 cursor for
            select id_process
                from p4gl_table_process
                    where tabname = p_p4gl_table_process.tabname
                    and id_process <> p_p4gl_process.id_process
						order by id_process

	        let all_process=""
			foreach r5 into tmp_id_process
	            select count(*) into process_ref_form
					from p4gl_form_table, p4gl_form_process
        	        where p4gl_form_table.tabname = p_p4gl_table_process.tabname
            	    and p4gl_form_process.id_process = tmp_id_process
					and p4gl_form_process.form_id = p4gl_form_table.form_id

		            let all_process=all_process clipped, " ",tmp_id_process clipped,"(",process_ref_form using "<<<<<",")"

			end foreach


			output to report process_table(p_p4gl_table_process.tabname,
							p_p4gl_process.id_process,total_tables,
							process_tables,all_process,this_process_ref_form)
		end foreach

    end foreach

    finish report process_table

    error report_file clipped, " created."

end function

{**
 *
 *
 *}
REPORT process_table(tabname,id_process,total_tables,process_tables,all_process,this_process_ref_form)

define
	tabname like p4gl_table_process.tabname,
	id_process like p4gl_process.id_process,
    total_tables,process_tables,this_process_ref_form,group_cnt
        smallint,
   	all_process
		char (200)

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
"tablename            # of forms ref. PROCESS(# of forms referencing)   ."
        print
"                     in this process "
#carriercost                     1    AR(1) SS(2)

		PRINT
"_________________________________________________________________"



    ##########################
	before group of id_process
    ##########################
        print
		"_________________________________________________________________"
        print

			"                       ",id_process clipped, " tables"
		PRINT
		"_________________________________________________________________"

        let group_cnt = 0

	############
	ON EVERY ROW
	############
        print
            tabname ,this_process_ref_form using "<<<",
            column 37,
			all_process clipped

        let group_cnt = group_cnt + 1

    ##########################
	after group of id_process
    ##########################

        print "Total tables in process", group_cnt using "<<<<"

	###########
	ON LAST ROW
	###########

		PRINT
"_________________________________________________________________"


        print
            "total tables in db:",total_tables
        print
            "tables related/unrelated to process:", process_tables using "<<<<","/",total_tables-process_tables using "<<<<",
            "(",((process_tables*100)/total_tables) using "<<<<","%)"

		PRINT
"_________________________________________________________________"


END REPORT

{**
 *
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
    is_formonly
        smallint,
    tmp_id_process
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

{

                                                                    distinct
systableext=		        380	p4gl(OK),loadform(OK),Dbdoc(CHECK)  380
systables                                                           692 	(after deductions)

p4gl_table_process=         649 p4gl(OK),loadform(OK)               379

p4gl_table_usage=	        555	p4gl(OK)                            158     (actually p4gl_function_table)
p4gl_form_table=	       2337	loadform(OK)                        342


    select systables.tabname
			from systables
            where systables.tabid > 100
			and not exists
                 (select systableext.tabname from systableext, systables
			where
			systableext.tabname = systables.tabname)
                order by systables.tabname

 drop   table alltables;
   select distinct tabname from p4gl_table_usage
   union
   select distinct tabname from p4gl_table_process
   union
   select distinct tabname from p4gl_form_table
   into temp alltables;

select count(*) from alltables;                           380
select count (distinct tabname) from alltables;             380


select count(*) from systables
where tabname not in (select tabname from systableext)
and tabname not matches "p4gl_*"
and tabid > 100                                             348-11=337

}




	select count(*) into total_doc4gl_tables
        from systableext
            where tabname not matches "p4gl_*"

	select count(*) into total_missing_tables
        from systableext
            where tabname not matches "p4gl_*"
            and tabtype = "U" #Doc4GL table types are T=table V=view U=undefined E=tEmporary O=obsolete


	select count(*) into total_obsolete_tables
        from systableext
            where tabname not matches "p4gl_*"
            and tabtype = "O" #Doc4GL table types are T=table V=view U=undefined E=tEmporary O=obsolete

	select count(*) into total_obsolete_not_removed
        from systableext
            where tabname not matches "p4gl_*"
            and tabtype = "O" #Doc4GL table types are T=table V=view U=undefined E=tEmporary O=obsolete
            and tabname in (select tabname from systables)

	select count(*) into total_not_exist from systableext
		where tabname not in (select tabname from systables)

	declare r6 cursor for
{
		select systables.tabname
			from systables, systableext
            where systables.tabid > 100
			and systables.tabname not in
                (select tabname from systableext)
                order by systables.tabname
}
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
		if cnt_process = 0 then initialize cnt_process to null end if
		if cnt_function = 0 then initialize cnt_function to null end if
		if cnt_form = 0 then initialize cnt_form to null end if
}

	    #-l just file name where found
    	#-H filename and line in which found
        # -i, --ignore-case

{
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

}
#if 1=2 then

        {




             -F, --fixed-strings
              Interpret PATTERN as a list of fixed strings, sepa­
              rated by newlines, any of which is to be matched.

			grep  -l -i "accumulator\|andrej" *.per

		}


        #Todo: how to avoid searching comment lines?

		let run_string= "find /opt/aubit/apps/erp/src -name '*.4gl' -exec grep -l -i ",
			"'from ",p_systableext.tabname clipped,"\\|",   #delete / select "from x"
			"into ",p_systableext.tabname clipped,"\\|",    #insert "into x"
			"like ",p_systableext.tabname clipped,"\\.\\|", #define ... "like x."
			"update ",p_systableext.tabname clipped,"'",    #"update x"
			" ",oc," \\; > tmp.unl"
#   create table faperiod
#   create unique index faperiod_key on faperiod (cmpy_code, book_code,


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
#end if

		#let run_string= "find /opt/aubit/apps/erp/src -name '*.per' -exec grep -l -i -w ",
		#	p_systableext.tabname clipped," ",oc," \\; > tmp.unl"
#what about ...type like prodsurcharge.x
		#look for table.column notation
		let run_string= "find /opt/aubit/apps/erp/src -name '*.per' -exec grep -l -i '",
			p_systableext.tabname clipped,"\\.' ",oc," \\; > tmp.unl"
		#display run_string clipped
		run run_string

        {
        There is little point in doing this - table will be liste in "tables"
        section (probably) only if table is actually used (to associate an
        screen fiels with table column. And if it was, above search already
        got it  .


		#look for table in "tables" section (complete line only)
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

        { There is very little point in doing this - only thing it (might)
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

				{
				let msg_txt="c:/progra~1/GWD/gte.exe //APTIVA/ROOT/opt/aubit/apps/erp/",
						run_string clipped

				output to report unused_tables(p_systableext.tabname,
							total_tables, total_doc4gl_tables,
                            total_missing_tables,
                           	tables_with_process,tables_with_function,tables_with_form,
                            cnt_process,cnt_function,cnt_form,found_in_per,found_in_4gl,
                            msg_txt,obsoleted,total_obsolete_tables,total_p4gl_parse_error,
                            total_not_exist,total_obsolete_not_removed
							)

                }

			end foreach
            close r8
		end if

		if found_in_per=0 and found_in_4gl=0 and cnt_process=0 and cnt_function =0 and cnt_form =0
		then
            #insert it and mark it obsolete
#            insert into systableext (owner,tabname,tabtype)
#                values ("root",p_systableext.tabname,"O")#Doc4GL table types are T=table V=view U=undefined E=tEmporary O=obsolete
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

    finish report unused_tables

    error report_file clipped, " created."
    let run_string= "less ",report_file
    run run_string

end function

{**
 *
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
#		print "Tables we need to account for:",
		print "Unique Tables without references in 4gl or per code:",
			column 65, (total_tables-(total_doc4gl_tables-total_missing_tables-total_obsolete_not_removed)) using "<<<<"
			#column 65, (total_tables-total_doc4gl_tables-total_obsolete_tables) using "<<<<"

		skip 1 line

		print "Unique tables with process(es) assigned:",
				column 65, tables_with_process using "<<<<"
        print "Unique tables referenced in function(s):",
				column 65, tables_with_function using "<<<<"
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
 *
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
 *
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


end function


{**
 *
 *
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
 *
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
	select count (*) into cnt from p4gl_function_calls
    display "p4gl_function_calls=	", cnt, 		"	p4gl_endrun(TODO)"
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
 *
 *
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
	drop table  v_prodhist                       ;
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


    #Definitely NOT obsolete:
#    drop table  backup;     #U111.per
#	drop table  batch                            ;  #P24.4gl
#	drop table  asp_activate                     ;
#	drop table  asp_connect                      ;
#	drop table  asp_pref                         ;

end function

#---------------------------- EOF --------------------------------

