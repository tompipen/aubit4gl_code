main
	define  f001		char(4),
		f002		char(4),
		f003		char(4)

	clear screen
	open window rptwin at 3, 2 with 20 rows, 78 columns
		attribute (form line first + 1, green, border,
			   prompt line last, comment line last,
			   message line last)

	open form rptform from "test_257"
	display form rptform attribute (cyan)

#	options input no wrap
	options input wrap
	options accept key f12

	let f001 = ""
	let f002 = ""
	let f003 = ""
	input by name f001, f002, f003 without defaults

		after field f001
		after field f002
		after field f003
			
		after input
			if f001 = "a" then
				next field f002
			end if
			if f001 = "b" then
				continue input
			end if

		on key (f1)
			exit input
	end input
end main
