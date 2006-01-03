MAIN
START REPORT mis_rp to "out"
OUTPUT TO REPORT mis_rp()
FINISH REPORT mis_rp
display time
display date
END MAIN

REPORT mis_rp()
DEFINE w_dt DATETIME YEAR TO SECOND
OUTPUT
    PAGE LENGTH 1
    TOP MARGIN 0
    BOTTOM MARGIN 0
FORMAT
    ON EVERY ROW
        let w_dt = "1970-02-13 01:02:03"
        print "dt=", w_dt
        print "date=", date(w_dt), ", time=", time(w_dt)
END REPORT
