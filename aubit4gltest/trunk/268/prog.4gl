main
define  dt 	date
define lv_str char(80)
define  p_parm 		array[3] of record 
	f1 	char(1),
	f2 	char(1),
	f3 	decimal(4,0)
end record
define i integer
define xrow integer
define xscr integer
define xans 	char(1)

	call startlog("out.expected")

	options accept key f12,
		insert key f36
	call errorlog("start")
	open window genparmwin at 2, 2 with 16 rows, 46 columns
		attribute (green, border)
	open form gen_form from "vb"
	display form gen_form attribute (cyan)

	let p_parm[1].f1 = "a";
	let p_parm[1].f2 = "1";

	let p_parm[2].f1 = "b";
	let p_parm[2].f2 = "2";

	let p_parm[3].f1 = "c";
	let p_parm[3].f2 = "3";

	call set_count(3)

	input array p_parm without defaults from parm_scr.*
	on key(control-p)
		exit input
	after row
		let xrow = arr_curr()
		let lv_str="after row : ",xrow
		call errorlog(lv_str clipped)

	on key(control-b)
		let xrow = arr_curr()
		let lv_str= "on key(f5) 1: ",xrow
		call errorlog(lv_str clipped)
		call vc()
		let xrow = arr_curr()
		let lv_str= "on key(f5) 2: ",xrow
		call errorlog(lv_str clipped)
	end input
	call errorlog("finish")
end main

function vc()
define  dt 	date
define  p_parm 		array[3] of record 
	f1 	char(1),
	f2 	char(1),
	f3 	decimal(4,0)
end record
define xrow integer
define xscr integer

	let p_parm[1].f1 = "x";
	let p_parm[1].f2 = "1";

	let p_parm[2].f1 = "y";
	let p_parm[2].f2 = "2";

	let p_parm[3].f1 = "z";
	let p_parm[3].f2 = "3";

	call set_count(3)

	input array p_parm without defaults from parm_scr.*
	on key(control-p)
		exit input
	before row
		let xrow = arr_curr()
		error "before row : ",xrow
	end input
end function
