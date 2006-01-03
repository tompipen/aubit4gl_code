main
define xfname   char(256)
define xupc	char(13)

let xupc = "06810004057"

let     xfname = "rpt.txt"
start   report rpt to xfname
output to report rpt(xupc)
finish  report rpt

end main

report rpt(xupc)
define xupc	char(13)
define xbarcode	char(4000)

	output
                left margin 0
                top margin 0
                bottom margin 0
                page length 1

        format

        on every row
		let xbarcode = xupc
        	print "barcode : ", xbarcode

end report
