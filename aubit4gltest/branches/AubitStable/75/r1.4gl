main
	define	sort_value	integer

	let sort_value = 30
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
	top of page "^L"

format
	page header
	print "H"
		

	on every row
	if true then
		print "E"
	end if
	print ""
	page trailer
	if true then
		skip 1 line
	else
		print "T"
	end if
end report
