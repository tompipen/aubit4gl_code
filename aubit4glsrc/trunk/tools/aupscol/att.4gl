function display_attribute(lv_rid,lv_rec,lv_this,lv_cnt)
define lv_rid integer
define lv_this,lv_cnt integer
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

define lv_colour char(20)


case lv_rec.color
	when 0 let lv_colour="WHITE/NORMAL"
	when 1 let lv_colour="YELLOW"
	when 2 let lv_colour="MAGENTA"
	when 3 let lv_colour="RED/BOLD"
	when 4 let lv_colour="CYAN"
	when 5 let lv_colour="GREEN"
	when 6 let lv_colour="LtBLUE/DIM"
	when 7 let lv_colour="BLACK/INVISIBLE"
end case

display "Blink          :",lv_rec.blink 	at 7,10
display "Color          :",lv_colour 		at 8,10
display "Underline      :",lv_rec.underline 	at 9,10
display "Left Justified :",lv_rec.left 		at 10,10
display "Reverse        :",lv_rec.inverse 	at 11,10
display "Format         :",lv_rec.def_format 	at 12,10
display "Where          :",lv_rec.condition 	at 14,10

if lv_this>0 then
	display lv_this using "<<<<","/",lv_cnt using "<<<<" at 5,1
else 
	display "                 " at 5,1
end if

end function


function add_attribute(lv_rid)
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
define lv_str char(1000)
define lv_txt char(80)

if lv_rid<=0 then
	let lv_rec.tabname=get_tabname()
	let lv_rec.colname=get_tabname()
	let lv_rec.seqno=0
	let lv_rec.color=0
	let lv_rec.inverse="n"
	let lv_rec.underline="n"
	let lv_rec.blink="n"
	let lv_rec.left="n"
	initialize lv_rec.def_format to null
	initialize lv_rec.condition to null
else
	let lv_str="select * from ",fgl_getenv("A4GL_SYSCOL_ATT")," where ",get_rowid(),"=",lv_rid
	prepare p_g_att from lv_str
	declare c_g_att cursor for p_g_att
	open c_g_att
	fetch c_g_att into lv_rec.*
end if



call display_attribute(lv_rid,lv_rec.*,0,0)
menu "ATTRIBUTE"
	command "Blink"
		if lv_rec.blink="y" then
			let lv_rec.blink="n"
		else
			let lv_rec.blink="y"
		end if
		call display_attribute(lv_rid,lv_rec.*,0,0)

	command "Color"
		let lv_rec.color=get_color(lv_rec.color)
		call display_attribute(lv_rid,lv_rec.*,0,0)

	command "Fmt"
		let int_flag=false
		prompt "DEFAULT >>" for lv_txt
		if int_flag=false then
			let lv_rec.def_format=lv_txt
		end if
		call display_attribute(lv_rid,lv_rec.*,0,0)

	command "Left"
		if lv_rec.left="y" then
			let lv_rec.left="n"
		else
			let lv_rec.left="y"
		end if
		call display_attribute(lv_rid,lv_rec.*,0,0)
	command "Rev"
		if lv_rec.inverse="y" then
			let lv_rec.inverse="n"
		else
			let lv_rec.inverse="y"
		end if
		call display_attribute(lv_rid,lv_rec.*,0,0)

	command "Under"
		if lv_rec.underline="y" then
			let lv_rec.underline="n"
		else
			let lv_rec.underline="y"
		end if
		call display_attribute(lv_rid,lv_rec.*,0,0)


	command "Where"
		let int_flag=false
		prompt "WHERE >>" for lv_txt
		if int_flag=false then
			let lv_rec.condition=lv_txt
		end if
		call display_attribute(lv_rid,lv_rec.*,0,0)

	command "Dis_Exit"
		exit menu

	command "Exit_set"
		if lv_rid<=0 then
			let lv_str="INSERT INTO ",fgl_getenv("A4GL_SYSCOL_ATT")," values (?,?,?,?,?,?,?,?,?)"
			prepare p_ins_att from lv_str
			execute p_ins_att using lv_rec.*
		else
			let lv_str="UPDATE ",fgl_getenv("A4GL_SYSCOL_ATT")," set (color,inverse,underline,blink,left,def_format,condition)=(?,?,?,?,?,?,?) where ",get_rowid()," = ",lv_rid
			prepare p_ins_att from lv_str
			execute p_ins_att using lv_rec.color,lv_rec.inverse,lv_rec.blink,lv_rec.underline,lv_rec.left,lv_rec.def_format,lv_rec.condition
		end if
		exit menu
end menu
end function


function get_color(lv_oldcolor)
define lv_oldcolor integer
define lv_newcolor integer
menu "COLORS"
	command "Normal" 	let lv_newcolor=0  exit menu
	command "Dim" 		let lv_newcolor=6 exit menu
	command "Bold" 		let lv_newcolor=3 exit menu
	command "Invisible" 	let lv_newcolor=7 exit menu

	command "White"		let lv_newcolor=0 exit menu
	command "Yellow"	let lv_newcolor=1 exit menu
	command "Magenta"	let lv_newcolor=2 exit menu
	command "Red"		let lv_newcolor=3 exit menu
	command "Cyan"		let lv_newcolor=4 exit menu
	command "Green"		let lv_newcolor=5 exit menu
	command "LtBlue"	let lv_newcolor=6 exit menu
	command "Black"		let lv_newcolor=7 exit menu
	command "Exit"		let lv_newcolor=-1 exit menu
end menu
if lv_newcolor>=0 then
	return lv_newcolor
else
	return lv_oldcolor
end if
end function


function del_attribute(lv_rid)
define lv_rid integer
define lv_str char(80)
let lv_str="DELETE FROM ",fgl_getenv("A4GL_SYSCOL_ATT")," WHERE ",get_rowid()," = ",lv_rid
prepare p_del_att from lv_str
execute p_del_att
end function
