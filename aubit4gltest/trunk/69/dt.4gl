main
define  phone_num 	char(12)
define  dt 	date

        options input no wrap,
	accept key f12

	open window genparmwin at 2, 2 with 16 rows, 46 columns
		attribute (green, border)
	open form gen_form from "dt"
	display form gen_form attribute (cyan)

initialize phone_num,dt to null

	input by name phone_num,dt without defaults
	on key(f1)
		exit input
	end input
	display "phone : ",phone_num," date=",dt

end main
