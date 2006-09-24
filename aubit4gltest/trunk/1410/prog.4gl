main
	define
		input_str char(100),
		junk_str char(1)

	open form test_form from "test_form"
	display form test_form

	input
		input_str,
		junk_str
	from
		formonly.test_field,
		formonly.other_field
	on key (control-b)
		call aclfgl_dump_screen("out")
	end input
end main
