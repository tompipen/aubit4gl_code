main
define	xfname            char(256)
define	xcmd            char(256)

	let     xfname = "rep.data.out"
	start   report rpt to xfname
	 output to report rpt()
	finish  report rpt

	let     xfname = "rep.empty.out"
	start   report rpt to xfname
	 #output to report rpt()
	finish  report rpt

end main

report rpt()

	format

	page header
        print "Header"

	#on every row
        #print "line"

end report
