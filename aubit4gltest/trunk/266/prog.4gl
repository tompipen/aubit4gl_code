main
	start   report rpt to "out"
	output to report rpt("abc")
	finish  report rpt
end main

report rpt(xstr)
define	xstr            char(20)

        output  left   margin 0
                top    margin 0
                bottom margin 0
                page   length 1

	format

	on every row
        print "line : ", xstr

end report
