database test1

main
	define
		test_var integer

	open form form1 from "default"
	display form form1
	input test_var from test_col
if test_var!=1 then
	exit program 1
else
	exit program 0
end if
end main
