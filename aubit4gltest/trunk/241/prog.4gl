main
define  no 	integer
define  dt 	date
define  p_parm 		array[5] of record
	noa 	integer,
	dta 	date
end record

define i integer
define xrow integer
define xscr integer

	options accept key f12

	open window genparmwin at 2, 2 with 16 rows, 46 columns
		attribute (green, border)
	open form gen_form from "p"
	display form gen_form attribute (cyan)

	input no,dt without defaults from sno,sdt #attribute(white)
	on key(f1)
		exit input
	end input


	input array p_parm without defaults from parm_scr.*
	before row
		on key(f1)
			exit input
	end input
	if no=11 and dt="1/1/2002" then
	else
		exit program 1
	end if
	if p_parm[1].noa is null and p_parm[1].dta is null then
	else
		exit program 2
	end if

	if p_parm[2].noa =11 and p_parm[2].dta ="1/1/2002" then
	else
	
		display "**** ", p_parm[2].noa, " ", p_parm[2].dta," ****"
		exit program 3
	end if
	
end main
