main
define  p_parm 		array[3] of record
	f1 	char(1),
	f2 	integer,
	f3 	char(1)
end record
define i integer
define xrow integer
define xscr integer

	options accept key f12

	open window genparmwin at 2, 2 with 16 rows, 46 columns
		attribute (green, border)
	open form gen_form from "v9"
	display form gen_form attribute (cyan)

	let p_parm[1].f1 = "a";
	let p_parm[1].f2 = "1";

	let p_parm[2].f1 = "b";
	let p_parm[2].f2 = "2";

	let p_parm[3].f1 = "c";
	let p_parm[3].f2 = "3";

	call set_count(3)

	input array p_parm without defaults from parm_scr.*
	{
	before row
		let xrow = arr_curr()
		let xscr = scr_line()
		error "total : ",arr_count()
	}

	on key(f2) 
		if infield(f1) and arr_curr()=1 then
			display "OK"
			exit program 0
		else 
			display "Bad"
			exit program 1
		end if
	on key(f1)
		exit input
	end input
	display "Bad"
	exit program 2

end main
