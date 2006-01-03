
main
define  p_parm 		array[5] of record
	f1 	char(1),
	f2 	char(1),
	f3 	char(1)
end record
define i integer
define xrow integer
define xscr integer
define lv_str char(80)

	options  accept key f12
		#insert key control-b

	call startlog("output")
	open window genparmwin at 2, 2 with 16 rows, 46 columns
		attribute (green, border)
	open form gen_form from "v"
	display form gen_form attribute (cyan)

	let p_parm[1].f1 = "a";
	let p_parm[1].f2 = "1";
	let p_parm[1].f3 = " ";

	let p_parm[2].f1 = "b";
	let p_parm[2].f2 = "2";
	let p_parm[2].f3 = " ";

	let p_parm[3].f1 = "c";
	let p_parm[3].f2 = "3";
	let p_parm[3].f3 = " ";

	call set_count(3)

	input array p_parm without defaults from parm_scr.*
	before row
		let xrow = arr_curr()
		let xscr = scr_line()
		#error "total : ",arr_count()
	after insert
		let xrow = arr_curr()
		let xscr = scr_line()
		#error "total : ",arr_count()
	
	end input
	let lv_str="ARR_CURR=",arr_curr() call errorlog(lv_str clipped)
	let lv_str="ARR_COUNT=",arr_count() call errorlog(lv_str clipped)
	let lv_str="SCR_LINE=",scr_line() call errorlog(lv_str clipped)
	for i=1 to 5
		let lv_str=p_parm[i].f1," ", p_parm[i].f2," ", p_parm[i].f3," "
		call errorlog(lv_str clipped)
	end for

end main
