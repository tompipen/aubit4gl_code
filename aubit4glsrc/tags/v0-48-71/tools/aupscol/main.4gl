function main_menu()
         call display_banner()
	call select_db()
	if not has_db() THEN
		exit program
	end if

	menu "AUPSCOL"
	        BEFORE MENU
                	call display_banner()
		command "Validate" "Modify validation settings"
			call handle_validate()
		command "Attributes" "Modify attribute settings"
			call handle_attributes()
		command "Exit" "Exit AUPSCOL"
			exit menu
	end menu
end function



################################################################################
function handle_validate()
define lv_action integer
define lv_str char(1000)
define lv_cnt integer
define lv_thiscnt integer
define lv_tabname,lv_colname char(30)
define lv_rid integer

define lv_rec record
	tabname              char(18) ,
	colname              char(18) ,
	attrname             char(10) ,
	attrval              char(64)
end record
if not cr_validate() then
	return
end if
let lv_action=1

while true

	if lv_action=1 then
		if not choose_table()  then
			return
		end if
		let lv_action=2
	end if
	
	
	if lv_action=2 then
		if not choose_column() then
			return
		end if
	end if

	let lv_tabname=get_tabname()
	let lv_colname=get_colname()

	let lv_str="select count(*) from ",fgl_getenv("A4GL_UPSCOL_VAL")," where tabname=? and colname=?"
	prepare p_hv_cnt from lv_str
	declare c_hv_cnt cursor for p_hv_cnt
	open c_hv_cnt using lv_tabname,lv_colname
	fetch c_hv_cnt into lv_cnt

	if lv_cnt then
		let lv_str="select ",get_rowid(),",* from ",fgl_getenv("A4GL_UPSCOL_VAL")," where tabname=? and colname=?"
		prepare p_hv_get from lv_str

		declare c_hv_get cursor for p_hv_get

		open c_hv_get using lv_tabname,lv_colname

		let lv_thiscnt=1
			fetch c_hv_get into lv_rid,lv_rec.*
			if sqlca.sqlcode=100 then
				exit while
			end if
			call display_validate(lv_rid,lv_rec.*,lv_thiscnt,lv_cnt)
	else
		let lv_rid=-1
	end if



	menu "ACTION"
			command "Add" 		"Add an entry to the data validation table"
				call add_validate(-1)

			command "Update" 	"Change an entry in the data validation table"
				if lv_rid=-1 then
					error "No row to update!"
				else
					call add_validate(lv_rid)
				end if

			command "Remove" 	"Delete an entry from the data validation table"
				call del_validate(lv_rid)
	
			command "Next" 		"Display the next row from the data validation table"
				if lv_cnt then
					fetch c_hv_get into lv_rid,lv_rec.*
					if sqlca.sqlcode=100 then
						error "No more rows..."
						let lv_rid=-1
					else
						let lv_thiscnt=lv_thiscnt+1
						call display_validate(lv_rid,lv_rec.*,lv_thiscnt,lv_cnt)
					end if
				else
					error "No rows.."
				end if

			command "Query" 	"Restart the search"
				let lv_action=3
				exit menu
			command "Table" 	"Change the table"
				let lv_action=1
				exit menu
			command "Column" 	"Change the column"
				let lv_action=2
				exit menu
			command "Exit" 		"Return to the Main Menu"
				let lv_action=0
				exit menu
	
	end menu

	if lv_action=0 then
		exit while
	end if
end while
end function





function handle_attributes()
define lv_action integer
define lv_str char(1000)
define lv_cnt integer
define lv_thiscnt integer
define lv_tabname,lv_colname char(30)
define lv_rid integer
define lv_rec record
	tabname              char(18),
	colname              char(18),
	seqno                serial   ,
	color                smallint ,
	inverse              char(1) ,
	underline            char(1) ,
	blink                char(1) ,
	left                 char(1) ,
	def_format           char(64),
	condition            char(64) 
end record


if not cr_attrib() then
	return
end if
let lv_action=1

while true

	if lv_action=1 then
		if not choose_table()  then
			return
		end if
		let lv_action=2
	end if
	
	
	if lv_action=2 then
		if not choose_column() then
			return
		end if
	end if

	let lv_tabname=get_tabname()
	let lv_colname=get_colname()

	let lv_str="select count(*) from ",fgl_getenv("A4GL_UPSCOL_ATT")," where tabname=? and colname=?"
	prepare p_ha_cnt from lv_str
	declare c_ha_cnt cursor for p_ha_cnt
	open c_ha_cnt using lv_tabname,lv_colname
	fetch c_ha_cnt into lv_cnt


        if lv_cnt then
                let lv_str="select ",get_rowid(),",* from ",fgl_getenv("A4GL_UPSCOL_ATT")," where tabname=? and colname=?"
                prepare p_ha_get from lv_str

                declare c_ha_get cursor for p_ha_get

                open c_ha_get using lv_tabname,lv_colname

                let lv_thiscnt=1
                        fetch c_ha_get into lv_rid,lv_rec.*
                        if sqlca.sqlcode=100 then
                                exit while
                        end if
                        call display_attribute(lv_rid,lv_rec.*,lv_thiscnt,lv_cnt)
        else
                let lv_rid=-1
        end if


        menu "ACTION"

           command "Add"           "Add an entry to the display attribute table"
				call add_attribute(-1)

           command "Update"        "Change an entry in the display attribute table"
				if lv_rid=-1 then
					error "No row to update!"
				else
					call add_attribute(lv_rid)
				end if
           command "Remove"        "Delete an entry from the display attribute table"
				call del_attribute(lv_rid)
           command "Next"          "Display the next row from the display attribute table"
				if lv_cnt then
					fetch c_hv_get into lv_rid,lv_rec.*
					if sqlca.sqlcode=100 then
						error "No more rows..."
						let lv_rid=-1
					else
						let lv_thiscnt=lv_thiscnt+1
						call display_attribute(lv_rid,lv_rec.*,lv_thiscnt,lv_cnt)
					end if
				else
					error "No rows.."
				end if

           command "Query"         "Restart the search"
		let lv_action=3
		exit menu
           command "Table"         "Change the table"
		let lv_action=1
		exit menu
           command "Column"        "Change the column"
		let lv_action=2
		exit menu
           command "Exit"          "Return to the Main Menu"
		let lv_action=0
                exit menu
        end menu
	if lv_action=0 then
		exit while
	end if
end while

end function



################################################################################
function cr_validate() 
define lv_ok integer
define lv_str char(2000)
whenever error continue
	let lv_str="select * from ",fgl_getenv("A4GL_UPSCOL_VAL")," where 1=0"
	prepare ptstval from lv_str
	declare ctstval cursor for ptstval
	open ctstval
	fetch ctstval
whenever error stop

	if sqlca.sqlcode!=0 then
		MENU "Create Validation Table ?"
		COMMAND "Yes"

		let lv_str=" create table ",fgl_getenv("A4GL_UPSCOL_VAL")," ( tabname char(18), colname char(18), attrname char(10), attrval char(64))"
		prepare pcrval from lv_str
		execute pcrval

			if sqlca.sqlcode=0 then
				let lv_ok=1
			else
				let lv_ok=0
			end if
			exit menu
		COMMAND "No"
			let lv_ok=0
			exit menu
		END MENU
	else
		let lv_ok=1
	end if

	return lv_ok

end function




################################################################################
function cr_attrib() 
define lv_ok integer
define lv_str char(2000)
whenever error continue
	let lv_str="select * from ",fgl_getenv("A4GL_UPSCOL_ATT")," where 1=0"
	prepare ptstatt from lv_str
	declare ctstatt cursor for ptstatt
	open ctstatt
	fetch ctstatt
whenever error stop

	if sqlca.sqlcode!=0 then
		MENU "Create Attribute Table ?"
		COMMAND "Yes"

		let lv_str=" create table ",fgl_getenv("A4GL_UPSCOL_ATT")," (tabname char(18), colname char(18), seqno serial , color smallint, inverse char(1), underline char(1), blink char(1), left char(1), def_format char(64), condition char(64))"
		prepare pcratt from lv_str
		execute  pcratt

			if sqlca.sqlcode=0 then
				let lv_ok=1
			else
				let lv_ok=0
			end if
			exit menu
		COMMAND "No"
			let lv_ok=0
			exit menu
		END MENU
	else
		let lv_ok=1
	end if

	return lv_ok

end function



function check_and_report_error()
end function
