function user_menu()
	menu "User Menu"
		command "Run"
			call run_user_menu()

		command "Modify"
			call modify_user_menu()

		command "Exit"
			exit menu
	end menu
end function



function run_user_menu()
	error "Not implemented run_user_menu"
end function


function modify_user_menu()
define lv_str char(255)
define lv_ut1,lv_ut2 char(30)
define bad integer
whenever error continue

let lv_ut1=fgl_getenv("SYSMENUS")
let lv_ut2=fgl_getenv("SYSMENUITEMS")
if lv_ut1 is null or lv_ut1 matches " " then
	let lv_ut1="sysmenus"
end if
if lv_ut2 is null or lv_ut2 matches " " then
	let lv_ut2="sysmenuitems"
end if


let bad=1


let lv_str="select * from ",lv_ut1
prepare p1_um from lv_str
if sqlca.sqlcode=0 then
		declare c1_um cursor for p1_um

		if sqlca.sqlcode=0 then
			open c1_um
			if sqlca.sqlcode=0 then
				fetch c1_um
				if sqlca.sqlcode>=0 then
					let bad=0
				end if
			end if
		end if
end if
whenever error stop

if bad then
	let lv_str="create table ",lv_ut1 clipped," (menuname char(18), title char(60))"
	prepare p_cr_um from lv_str
	execute p_cr_um
	
	let lv_str="create table ",lv_ut2 clipped," (imenuname char(18), itemnum integer, mtext char(60),mtype char(1),progname char(60),title char(60))"
	prepare p_cr_umi from lv_str
	execute p_cr_umi
end if

end function



