main
	define	sort_value	integer

	let sort_value = 30
display "sort_value in main: ", sort_value
	start report prilog to "p.rpt"
	output to report prilog(sort_value)
	finish report prilog
end main
##############################################################################
report prilog(psort)

define	psort	integer

output
	left margin 0
	page length 60
	#top of page "^L"

format
	page header
display "sort_value on header: ", psort

	on every row
display "sort_value on every row : ", psort
end report
