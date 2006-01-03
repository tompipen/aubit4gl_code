main
define  p_parm 		array[5] of record
	f1 	char(1),
	f2 	char(1),
	f3 	char(1)
end record
define i integer
define xrow integer
define xscr integer

	options accept key f12

	open window genparmwin at 2, 2 with 16 rows, 46 columns
		attribute (green, border)
	open form gen_form from "v"
	display form gen_form attribute (cyan)

	let p_parm[1].f1 = "a";
	let p_parm[1].f2 = "1";

	let p_parm[2].f1 = "b";
	let p_parm[2].f2 = "2";

	let p_parm[3].f1 = "c";
	let p_parm[3].f2 = "3";

	call set_count(3)

	display array p_parm to parm_scr.*
		on key(f1)
			exit display
	end display

	if scr_line() != 3 or arr_curr()!=3 then
		display "Return key for down not working properly"
		exit program 1
	else
		exit program 0
	end if
end main
