
database test1

main
	start report test_rpt to 'test_319.rpt'
	output to report test_rpt('Record 2', 'Line 2')
	output to report test_rpt('Record 1', 'Line 1')
	output to report test_rpt('Record 3', 'Line 3')
	finish report test_rpt

	start report test_rpt to 'test_319.rpt2'
	output to report test_rpt('Record 2', 'Line 2')
	output to report test_rpt('Record 3', 'Line 3')
	output to report test_rpt('Record 1', 'Line 1')
	finish report test_rpt


end main

report test_rpt(col_a, col_b)

	define	col_a		char(10),
		col_b		char(10)

        output  left margin 7
                page length 60

	order	by col_a
#	order	external by col_a

	format
	on every row
		print	"Line:  ", col_a," ", col_b

	on last row
		print	"End of Report"
end report
