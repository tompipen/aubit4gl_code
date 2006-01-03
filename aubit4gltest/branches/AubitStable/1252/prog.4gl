database test1

main
	define x char(1)

	start report r1 to file "out"
	output to report r1('ok')
	finish report r1

	end main

report r1(c)
	define c char(20)
	define vc varchar(20)

	output
		top margin 0
		left margin 0
		bottom margin 0
		page length 30

	format
	page header
		print "HEADER"
		let vc=' '
	on every row
		print c,' ',vc
	on last row
		print "END OF REPORT"
	end report
