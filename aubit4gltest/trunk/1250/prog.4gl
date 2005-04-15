database test1
main
define tempdiv integer,
       tempacct char(20),
       tempamt decimal(16,2),
       tempcomnt char(50),
       filename_out char(120)

let filename_out = "out"

start report cash_report to filename_out

let tempdiv = 1120
let tempamt = 123456.78

    output to report cash_report(tempdiv,"cash", tempamt, "")

#    this line works properly
#    output to report cash_report(tempdiv,"cash", tempamt, " ")

finish report cash_report


end main
--report function
REPORT cash_report (r)
DEFINE r RECORD
           tempdiv integer,
           tempacct char(20),
           tempamt decimal(16,2),
           tempcomnt char(50)
         end record

OUTPUT
    TOP MARGIN 0
    BOTTOM MARGIN 0
    PAGE LENGTH 10
    LEFT MARGIN 0

ORDER BY  r.tempdiv, r.tempacct

FORMAT

ON EVERY ROW

    print column 01, r.tempdiv using "####", "-", r.tempacct[1,4],
          column 15, r.tempamt using "---,---,---,--&.&&",
          column 35, r.tempcomnt clipped

AFTER GROUP OF r.tempdiv
    print column 01, r.tempdiv using "####",
          column 05, "total",
          column 15, group sum (r.tempamt) using "---,---,---,--&.&&"
    skip 1 line

ON LAST ROW

    print "Report total",
          column 15, sum (r.tempamt) using "---,---,---,--&.&&"
    SKIP 1 line

    PRINT "** END OF REPORT **"

END REPORT
