function add_validate(lv_rid) 
define lv_rid integer
MENU "VALIDATE"
	COMMAND "Autonext" "Automatically go to the next field when this one is full"
		call val_autonext(lv_rid)
	COMMAND "Comment" "Add a comment for the field"
		call val_comment(lv_Rid)
	COMMAND "Default" "Default value for the field"
		call val_default(lv_rid)
	COMMAND "Include"  "Specify permissible values for data entry"
		call val_include(lv_rid)
	COMMAND "Picture"  "Specify a mask for the field"
		call val_picture(lv_rid)
	COMMAND "Shift"    "Specify Upshift/Downshift for a field"
		call val_shift(lv_rid)
	COMMAND "Verify"   "Specify verification is required for the data"
		call val_verify(lv_rid)
	COMMAND "Exit" exit menu
END MENU
END FUNCTION


FUNCTION val_autonext(lv_rid)
define lv_rid integer
MENU "AUTONEXT"
	command "Yes" "Add autonext to the field"
		call add_val(lv_rid,"AUTONEXT","YES")
		exit menu
	command "No"  "Set no autonext for the field"
		call add_val(lv_rid,"AUTONEXT","NO")
		exit menu
	command "Exit" exit menu
END MENU

END FUNCTION


FUNCTION val_verify(lv_rid)
define lv_rid integer
MENU "VERIFY"
	command "Yes" "Add user verification to the field"
		call add_val(lv_rid,"VERIFY","YES")
		exit menu
	command "No"  "Set no user verification for the field"
		call add_val(lv_rid,"VERIFY","NO")
		exit menu
	command "Exit" exit menu
END MENU

END FUNCTION


FUNCTION val_comment(lv_rid)
define lv_rid integer
define lv_txt char(80)
let int_flag=false
PROMPT "COMMENT >>" FOR lv_txt
LET lv_txt="\"",lv_txt clipped,"\""
IF int_flag=false THEN
	call add_val(lv_rid,"COMMENT",lv_txt)
END IF
END FUNCTION



FUNCTION val_default(lv_rid)
define lv_rid integer
define lv_txt char(80)
let int_flag=false
PROMPT "DEFAULT >>" FOR lv_txt
IF int_flag=false THEN
	call add_val(lv_rid,"DEFAULT",lv_txt)
END IF
END FUNCTION



FUNCTION val_include(lv_rid)
define lv_rid integer
define lv_txt char(80)
let int_flag=false
PROMPT "INCLUDE >>" FOR lv_txt
LET lv_txt="\"",lv_txt clipped,"\""
IF int_flag=false THEN
	call add_val(lv_rid,"INCLUDE",lv_txt)
END IF
END FUNCTION

FUNCTION val_picture(lv_rid)
define lv_rid integer
define lv_txt char(80)
let int_flag=false
PROMPT "PICTURE >>" FOR lv_txt
IF int_flag=false THEN
	call add_val(lv_rid,"PICTURE",lv_txt)
END IF
END FUNCTION

FUNCTION val_shift(lv_rid)
define lv_rid integer
MENU "SHIFT"
	command "Up" "UPSHIFT the field"
		call add_val(lv_rid,"SHIFT","UP")
		exit menu
	command "Down"  "DOWNSHIFT field"
		call add_val(lv_rid,"SHIFT","DOWN")
		exit menu
	command "None"  "Apply no shifting to the field"
		call add_val(lv_rid,"SHIFT","NO")
		exit menu
	command "Exit" exit menu
END MENU

END FUNCTION



FUNCTION add_val(lv_rid,lv_type,lv_value)
DEFINE lv_str CHAR(255)
DEFINE lv_rid INTEGER
DEFINE lv_type CHAR(40)
DEFINE lv_value CHAR(80)
DEFINE lv_tabname,lv_colname CHAR(30)
LET lv_tabname=get_tabname()
LET lv_colname=get_colname()
if lv_rid<=0 then
	# Insert
	LET lv_str="INSERT INTO ",fgl_getenv("A4GL_UPSCOL_VAL")," VALUES (?,?,?,?)      "
	PREPARE p_ins_add_val FROM lv_str
	DISPLAY lv_str at 19,1
	display lv_tabname," ",lv_colname," ",lv_type," ",lv_value at 20,1
	sleep 2
	EXECUTE p_ins_add_val USING lv_tabname,lv_colname,lv_type,lv_value
ELSE
	LET lv_str="UPDATE ",fgl_getenv("A4GL_UPSCOL_VAL")," SET attrname=?, attrval=? WHERE ",get_rowid(),"=?"
	PREPARE p_upd_add_val FROM lv_str
	EXECUTE p_upd_add_val USING lv_type,lv_value,lv_rid
END IF
END FUNCTION
	


FUNCTION display_validate(lv_rid,lv_rec,lv_this,lv_cnt) 
define lv_rid,lv_this,lv_cnt INTEGER
define lv_rec RECORD
        tabname              char(18) ,
        colname              char(18) ,
        attrname             char(10) ,
        attrval              char(64)
end record
display "Row:",lv_this using "<<<<","/",lv_cnt using "<<<<" at 5,1

display "Attribute Name  : ",lv_rec.attrname at 8,3
display "Attribute Value : ",lv_rec.attrval[1,60] at 9,3
END FUNCTION



FUNCTION del_validate(lv_rid)
DEFINE lv_rid INTEGER
DEFINE lv_str CHAR(255)
LET lv_str="DELETE FROM ",fgl_getenv("A4GL_UPSCOL_VAL")," WHERE ",get_rowid(),"=?"
PREPARE p_del_val FROM lv_str
EXECUTE lv_str using lv_rid
END FUNCTION
