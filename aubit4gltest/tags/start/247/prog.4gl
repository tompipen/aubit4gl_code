main
define	q1 char(1)
define  dt 	date
define  p_parm 		array[5] of record
	f1 	char(1),
	f2 	char(1),
	f3 	char(1)
end record

define i integer
define xrow integer
define xscr integer

	options accept key f12,
		input wrap

	open window genparmwin at 2, 2 with 16 rows, 46 columns
		attribute (green, border)
	open form gen_form from "m2"
	display form gen_form attribute (cyan)

	let dt = mdy(2,13,1970)

	display "input f1:next" to msg
	input dt without defaults from sdt1 attribute(white)
	on key(f1)
		exit input
	on key(return)
		prompt "prompt : " for char q1 attribute (white)
		call aclfgl_dump_screen("p1.out")
	end input

	let p_parm[1].f1 = "a";
	let p_parm[1].f2 = "1";

	let p_parm[2].f1 = "b";
	let p_parm[2].f2 = "2";

	let p_parm[3].f1 = "c";
	let p_parm[3].f2 = "3";

	call set_count(3)

	display "input array f1:quit" to msg
	input array p_parm without defaults from parm_scr.*
	before row
		on key(f1)
			exit input
		after field f1
			prompt "prompt : " for char q1 attribute (white)
			call aclfgl_dump_screen("p2.out")
	end input

end main
