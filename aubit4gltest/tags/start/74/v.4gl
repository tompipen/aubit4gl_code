main
define  p_parm 		array[5] of record
	f1 	char(1),
	f2 	char(1),
	f3 	char(1)
end record
define i integer

	options accept key f12

	open window genparmwin at 2, 2 with 16 rows, 46 columns attribute (green, border)
	open form gen_form from "v"
	display form gen_form attribute (cyan)


	for i = 1 to 5
		initialize p_parm[i].* to null
	end for

	let p_parm[1].f1 = "a";
	let p_parm[1].f2 = "1";

	let p_parm[2].f1 = "b";
	let p_parm[2].f2 = "2";

	let p_parm[3].f1 = "c";
	let p_parm[3].f2 = "3";

	call set_count(3)

	input array p_parm without defaults from parm_scr.*
	after row
		display "After row" at 1,1
	on key(f1)
		call aclfgl_dump_screen("scr.out",0)
	end input
		call aclfgl_dump_screen("scr2.out",0)

	
end main
