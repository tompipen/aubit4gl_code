main
define  dt 	date
define  p_parm 		array[3] of record 
	f1 	char(1),
	f2 	char(1),
	f3 	decimal(4,0)
end record
define i integer
define xrow integer
define xscr integer
define xans 	char(1)

	options accept key f12,
		insert key f36

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
	on key(f1)
		exit input
	after field f3
		prompt "Press Any..." for char xans attribute(white)
		if xans= "Y" then
			exit program 0
		end if
	end input
	exit program 1
end main
