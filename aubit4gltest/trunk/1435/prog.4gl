
main
define  p_parm 		array[15] of record
	a0 smallint,
	f1 	integer,
	f2 	char(10),
	f3 	float,
	a2 smallint
end record

define i integer
define xrow integer
define xscr integer

	open window genparmwin at 2, 2 with 16 rows, 46 columns
	attribute (green, border)
	open form gen_form from "slice"
	display form gen_form attribute (cyan)

	for i=1 to 10
		let p_parm[i].f1 =i*1
		let p_parm[i].f2 =i*2
		let p_parm[i].f3 =i*3
		let p_parm[i].a0=0
		let p_parm[i].a2=0
		
	end for

	call set_count(10)

	display array p_parm slice(f1 thru f3) to parm_scr.*

end main
