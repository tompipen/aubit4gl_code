schema maxdev

define
	l_fname char(264)

####
main
####
define
	type, uid, pwd, db char (20)

	# Change to the database on the following line to point to the
	# database you wish to store your mapfile data in
	#database informix

	if num_args() = 5 then
		let l_fname=arg_val(1)
		let uid=arg_val(2)
		let pwd=arg_val(3)
		let db=arg_val(4)
		let type=arg_val(5)

		#OPEN SESSION s_ifmx TO DATABASE maxdev as user "informix" password "ifmx"
        #OPEN SESSION s_ifmx TO DATABASE db as user uid password pwd
		#SET SESSION TO s_ifmx
		database db
	    display "Connected to the database."


        case type
			when "map"
	            call load_map()
            when "dd"
                call load_dd()
            when "ddp"
                call process_dd()
			when "cnt"
				call count_data()
			otherwise
                display "ERROR: unknown type"
        end case

		#CLOSE SESSION s_ifmx
        close database

	else
	   display "Usage:"
	   display "loadmap file_name uid pwd db [map|dd|ddp]"
	end if

end main

function load_map()

	   delete from acl_map where map_module=l_fname
	   load from l_fname insert into acl_map
	   if status <> 0 then
	      display "error loading"
	   end if


end function

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
            display "Creating table dd_temp"
			create table dd_temp (load_field char (300))
        else
	       display "Cleaning dd_temp table..."
		   delete from dd_temp #where map_module=l_fname
        end if

	   display "Loading file..."
	   load from l_fname insert into dd_temp
	   if status <> 0 then
	      display "error loading"
          exit program 1
	   end if

       display "Successfully loaded DD."

end function

function process_dd()
define
    tmp_stat, cnt,pos,pos1,pos2,pos3,pos4,buff_length, param integer,
    buff, tmpbuff, curr_form_file,
	desc_text,table_text,field_text
		char (300),
    form_file, module
    	char(20),
    del_char, attrib_type
        char(1),
    attrib_code, formfile_cnt,attrib_cnt,warning_cnt,formonly_cnt,
	is_multiline,lines_cnt,tmpcnt,error_comp_cnt
		smallint,
    pa_lines array [100] of record
		text_line char(80)
    end record



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
	select * from p4gl_form_attribute_type

	if status = notfound then

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
                    continue foreach
                else
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
						let attrib_type=buff[1,pos1-1]
						let attrib_code=buff[pos1+1,pos2-1]
						let desc_text=buff[pos2+1,pos3-1]
    	                let table_text=buff[pos3+1,pos4-1]
        	            let field_text=buff[pos4+1,buff_length]
                        let attrib_cnt=attrib_cnt+1
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
                    let desc_text=desc_text[1,buff_length-1]
                end if

                #remove space(s) at the start of string
				let buff=desc_text
				let buff_length=length (desc_text)
                for pos=1 to 10
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
                if table_text = "formonly" then
					let formonly_cnt=formonly_cnt+1
#should still insert the form in p4gl_form, mark form as FORMONLY and add attributes
					continue foreach
                end if

                ############ now let's load ###############
                call store_data(attrib_type,attrib_code,curr_form_file,form_file,module,desc_text,table_text,field_text)

			else
                display "WARNING: empty line"
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


###########################################################################
function store_data(attrib_type,attrib_code,curr_form_file,form_file,module,
	desc_text,table_text,field_text)
###########################################################################

define
	p_p4gl_form record like p4gl_form.*,
	p_p4gl_process record like p4gl_process.*,
    p_p4gl_form_column record like p4gl_form_column.*,
	p_p4gl_form_table record like p4gl_form_table.*,
	p_systableext record like systableext.*,
	p_syscolumnext record like syscolumnext.*,
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
    tmp char (254)

#TODO: extract DoxyGen comment about form purpose/description from form file


    select owner into table_owner
        from systables
            where tabname = table_text



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
					end if

					#check if we have this module/process
					select * into p_p4gl_process.* from p4gl_process
                        where id_process = module

                    if status = notfound then
                        display "ERROR: process ", module clipped, " not found in process table"
                        exit program
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
                        exit program
                    end if

                end if

                #now we have p4gl_form, p4gl_process, p4gl_form_process

                ###############################################################
                #Check if we have this form in contect of this table/column
                ###############################################################

                select p4gl_form_column.*, p4gl_form_table.* into p_p4gl_form_column.*, p_p4gl_form_table.*
                    from p4gl_form, p4gl_form_column, p4gl_form_table
                        where p4gl_form.form_id = p_p4gl_form.form_id
                        and p4gl_form_table.tabname = table_text
                        and p4gl_column_table.tabname = table_text
                        and p4gl_form_column.colname = field_text
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
	                select p4gl_form_column.*, p4gl_form_table.* into p_p4gl_form_column.*, p_p4gl_form_table.*
	                    from p4gl_form, p4gl_form_column, p4gl_form_table
	                        where p4gl_form.form_id = p_p4gl_form.form_id
	                        and p4gl_form_table.tabname = table_text
	                        and p4gl_column_table.tabname = table_text
	                        and p4gl_form_column.colname = field_text
	                        #join:
	                        and p4gl_form.form_id = p4gl_form_column.form_id
	                        and p4gl_form.form_id = p4gl_form_table.form_id

	                if status = NOTFOUND then
                        display "ERROR: failed to create form/table/column relationship."
                        exit program
                    end if

                else
                    display "ERRROR: duplicate form/table/column relationship"
                    exit program
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
                    insert into table p4gl_table_process (id_process,owner,tabname)
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
                    insert into table p4gl_table_process (id_process,owner,tabname, colname)
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

                            if length (tmp) < 1 then
	                            update syscolumnext set remarks = desc_text
	                                    where owner = table_owner
	                                    and tabname = table_text
	                                    and colname = field_text
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
                            end if

						when 3	#DEFAULT    	FA_S_DEFAULT = 3,
                            insert into p4gl_form_attribute (form_attribute_id,form_id,form_attribute_type_id,text,owner,tabname,colname)
                                values (0,p_p4gl_form.form_id,3,desc_text,table_owner,table_text,field_text)
							#check column default & insert if empty
                            select default into tmp
                                from syscolumnext
                                    where owner = table_owner
                                    and tabname = table_text
                                    and colname = field_text

                            if length (tmp) < 1 then
	                            update syscolumnext set default = desc_text
	                                    where owner = table_owner
	                                    and tabname = table_text
	                                    and colname = field_text
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

							select up_down_shif into tmp
								from syscolumnext
                                    where owner = table_owner
                                    and tabname = table_text
                                    and colname = field_text

                            if tmp is null then
	                            update syscolumnext set up_down_shif = "U"
	                                    where owner = table_owner
	                                    and tabname = table_text
	                                    and colname = field_text
                            end if

						when 8	#    	DOWNSHIFT	FA_B_DOWNSHIFT = 8,
                            insert into p4gl_form_attribute (form_attribute_id,form_id,form_attribute_type_id,owner,tabname,colname)
                                values (0,p_p4gl_form.form_id,7,table_owner,table_text,field_text)
							
							select up_down_shif into tmp
								from syscolumnext
                                    where owner = table_owner
                                    and tabname = table_text
                                    and colname = field_text

                            if tmp is null then
	                            update syscolumnext set up_down_shif = "D"
	                                    where owner = table_owner
	                                    and tabname = table_text
	                                    and colname = field_text
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


function count_data()
define
    cnt integer

#new tables
whenever error continue

	select count (*) into cnt from p4gl_form_column
    display "p4gl_form_column=", cnt
	select count (*) into cnt from p4gl_form_table
    display "p4gl_form_table=", cnt
	select count (*) into cnt from p4gl_form_process
    display "p4gl_form_process=", cnt
	select count (*) into cnt from p4gl_form
    display "p4gl_form=", cnt
	select count (*) into cnt from p4gl_form_attribute
    display "p4gl_form_attribute=", cnt
	select count (*) into cnt from p4gl_form_attribute_type
    display "p4gl_form_attribute_type=", cnt
	select count (*) into cnt from p4gl_table_process
    display "p4gl_table_process=", cnt
	select count (*) into cnt from p4gl_column_process
    display "p4gl_column_process=", cnt

whenever error stop

#old tables:
	
	select count (*) into cnt from table_process
    display "table_process=", cnt
	select count (*) into cnt from systableext
    display "systableext=", cnt
	select count (*) into cnt from sysmodules
    display "sysmodules=", cnt
	select count (*) into cnt from syscolumnext
    display "syscolumnext=", cnt
	select count (*) into cnt from process
    display "process=", cnt
	select count (*) into cnt from p4gl_table_usage
    display "p4gl_table_usage=", cnt
	select count (*) into cnt from p4gl_program
    display "p4gl_program=", cnt
	select count (*) into cnt from p4gl_process
    display "p4gl_process=", cnt
	select count (*) into cnt from p4gl_package
    display "p4gl_package=", cnt
	select count (*) into cnt from p4gl_module_prog
    display "p4gl_module_prog=", cnt
	select count (*) into cnt from p4gl_module
    display "p4gl_module=", cnt
	select count (*) into cnt from p4gl_mod_todo
    display "p4gl_mod_todo=", cnt
	select count (*) into cnt from p4gl_function
    display "p4gl_function=", cnt
	select count (*) into cnt from p4gl_fun_todo
    display "p4gl_fun_todo=", cnt
	select count (*) into cnt from p4gl_fun_return
    display "p4gl_fun_return=", cnt
	select count (*) into cnt from p4gl_fun_process
    display "p4gl_fun_process=", cnt
	select count (*) into cnt from p4gl_fun_parameter
    display "p4gl_fun_parameter=", cnt
	select count (*) into cnt from p4gl_form_usage
    display "p4gl_form_usage=", cnt
	select count (*) into cnt from p4gl_excel
    display "p4gl_excel=", cnt
	select count (*) into cnt from ext_table
    display "ext_table=", cnt
	select count (*) into cnt from ext_database
    display "ext_database=", cnt
	select count (*) into cnt from ext_column
    display "ext_column=", cnt
	select count (*) into cnt from d_modulos
    display "d_modulos=", cnt
	select count (*) into cnt from d_mod_tab
    display "d_mod_tab=", cnt

{


----------- Doc4GL ----------------
p4gl_table_usage=       	9543
p4gl_program=        		449
p4gl_process=         		10
p4gl_module_prog=       	4123
p4gl_module=       			1001
p4gl_function=       		3607
p4gl_fun_parameter=      	10345
p4gl_fun_todo=          	1
p4gl_fun_return=          	1
p4gl_fun_process=          	1
p4gl_package=          		1
p4gl_mod_todo=          	0
p4gl_form_usage=          	0
p4gl_excel=          		0

new:
p4gl_form_column
p4gl_form_table
p4gl_form_process
p4gl_form


---------- Dbdoc tables:-----------
systableext=         0
sysmodules=          0
syscolumnext=        0
d_modulos=           0
d_mod_tab=           0



---------jDBdoc tables:------------
ext_table=           0
ext_database=        0
ext_column=          0
process=             0
table_process=       0



}


end function


#---------------------------- EOF --------------------------------