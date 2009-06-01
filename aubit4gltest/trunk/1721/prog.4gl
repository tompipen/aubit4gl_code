main
	define
		a char(1),
		b char(1),
		c char(1)

	open form test_form from "scrn_arr"
	display form test_form
	input a,b,c from 
		sr_test_field[1].test_field,
		sr_test_field[2].test_field,
		sr_test_field[3].test_field

	on key (f1)
		next field sr_test_field[3].test_field
	
	end input
end main
