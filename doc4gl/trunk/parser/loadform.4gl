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

	# Change to the database on the following line to point to the
	# database you wish to store your mapfile data in
	#database informix

    let debug = false    	#show debugging messages
    let warnings = true     #show warning messages
    let verbose = false     #show details of what you are doing

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


end main


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
        command "reports"

            menu "Reports"
                command "1Tables by process"
                    call rep_table_process()

                command "2Process/table"
                    call rep_process_table()

                command "3Unused" "Modules not referenced by make files"

                command "4Unused" "Tables not referenced by 4gl or per files"
                    call rep_unused_tables()

				command "exit" "Exit program"
		            exit menu
            end menu

		command "exit" "Exit program"
            exit menu
    end menu

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
"Table name                       PROCESSES..."
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
"tablename            # of forms ref. PROCESS(# of forms referencing) ..."
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
    all_process,report_file,run_string
        char(200),
    total_tables,total_doc4gl_tables,total_missing_tables
        smallint,
    tmp_id_process
        char(10)

    let report_file="unused_tables.txt"

    start report unused_tables to report_file

	select count(*) into total_tables
        from systables
            where tabid > 100
            and tabname not matches "p4gl_*"

    #deduct Doc4GL/DBdoc tables not prefixed with p4gl_ + dd_temp
	let total_tables = total_tables - 11

	select count(*) into total_doc4gl_tables
        from systablesext
            where tabname not matches "p4gl_*"

	select count(*) into total_missing_tables
        from systablesext
            where tabname not matches "p4gl_*"
            and tabtype = "U" #Doc4GL table types are T=table V=view U=undefined E=tEmporary

    declare r6 cursor for
        select systables.tabname
			from systables, systableext
            where systables.tabname not in
                (select tabname from systableext)

    foreach r6 into p_systableext.tabname

			output to report unused_tables(p_systableext.tabname,
							total_tables, total_doc4gl_tables,
                            total_missing_tables
							)

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
REPORT unused_tables(tabname,total_tables,total_doc4gl_tables,total_missing_tables)

define
	tabname like p4gl_table_process.tabname,
    total_tables,total_doc4gl_tables,group_cnt,total_missing_tables
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

        print
"tablename           "

		PRINT
"_________________________________________________________________"



	############
	ON EVERY ROW
	############
        print
            tabname

	###########
	ON LAST ROW
	###########

		PRINT
"_________________________________________________________________"


        print
            "total tables in db:",total_tables using "<<<<"
        print
            "total tables in DbDoc:",total_doc4gl_tables using "<<<<"
        print
            "tables without references in 4gl or per code:",
			(total_tables-total_doc4gl_tables) using "<<<<"
        print
            "Table references to non-existing tables, temp tables:",
                total_missing_tables


		PRINT
"_________________________________________________________________"


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


    display "Loading DD..."
	whenever error continue
        select count(*) into tmp_stat from dd_temp
        let tmp_stat=status
	whenever error stop

    #display "Status = ",tmp_stat

        if tmp_stat <> 0 then
            #display "Creating table dd_temp"
			#create table dd_temp (load_field char (300))
        else
	       #display "Cleaning dd_temp table..."
		   #delete from dd_temp
           drop table dd_temp
        end if

        #must drop/create table every time to maintain line order
		display "Creating table dd_temp"
	 	create table dd_temp (load_field char (300))


	   display "Loading file..."
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
    display "Processing DD..."
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
    display "p4gl_table_process=	", cnt,         "   p4gl(OK),loadform(OK)"
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
	select count (*) into cnt from p4gl_form_attribute
    display "p4gl_form_attribute=	", cnt, 		"	loadform(OK),fgldoc(TODO)"

#populated by loadform only:
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
    display "p4gl_mod_todo=		", cnt,			"	p4gl(CHECK)"
	select count (*) into cnt from p4gl_function
    display "p4gl_function=		", cnt,			"	p4gl(OK)"
	select count (*) into cnt from p4gl_fun_todo
    display "p4gl_fun_todo=		", cnt,			"	p4gl(CHECK)"
	select count (*) into cnt from p4gl_fun_return
    display "p4gl_fun_return=	", cnt,			"	p4gl(CHECK)"
	select count (*) into cnt from p4gl_fun_process
    display "p4gl_fun_process=	", cnt,			"	p4gl(CHECK)"
	select count (*) into cnt from p4gl_fun_parameter
    display "p4gl_fun_parameter=	", cnt,			"	p4gl(CHECK)"
	select count (*) into cnt from p4gl_form_usage
    display "p4gl_form_usage=	", cnt,			"	p4gl(CHECK)"

#populated by other methods:
	select count (*) into cnt from p4gl_excel
    display "p4gl_excel=		", cnt,			"	TEMP(OK)"
	select count (*) into cnt from p4gl_function_calls
    display "p4gl_function_calls=	", cnt, 		"	p4gl_endrun(TODO)"
	display ""


{
----------- After loading 4gl:
p4gl_table_usage=         	  0 - (was 9543 - WRONG) TODO - remove need for table_name field
p4gl_mod_todo=          	  0 - TODO - why is this not stored?
p4gl_form_usage=          	  0 - TODO - why is this not stored?, add reference to p4gl_form, add ref to p4gl_form_process, remove need for field form_name
p4gl_function_calls=          0 - TODO - store this
p4gl_process=		         20 - OK
p4gl_package=		          1 - OK
p4gl_module=		       1564 - OK Loaded=1564 Errors=343 Modules=1919 Missing=12 (should be 1576)
p4gl_function=		       2685 - was 3607 - WRONG
p4gl_fun_todo=		          1 - OK
p4gl_fun_return=	          1 - OK
p4gl_fun_process=	          1 - OK (maybe add process from directory, not only from comment?)
p4gl_fun_parameter=	       3541 - was 10345 - WRONG



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


#---------------------------- EOF --------------------------------
