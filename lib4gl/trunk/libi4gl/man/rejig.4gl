{
    @(#)@(#)$Id: rejig.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $ 
    @(#)Sphinx Informix Tools
    @(#)Example: Set output parameters of I4GL report dynamically
    @(#)J Leffler
    @(#)(C) Copyright 1989 Sphinx Ltd.
}

MAIN

    DEFINE i INTEGER

    START REPORT rf_rejig

    { Adjust report parameters dynamically }
    CALL set_tmargin(1)     # Top margin
    CALL set_bmargin(1)     # Bottom margin
    CALL set_plength(23)    # Page length
    CALL set_lmargin(0)     # Left margin

    FOR i = 1 TO 30
        OUTPUT TO REPORT rf_rejig(i)
    END FOR

    FINISH REPORT rf_rejig

END MAIN

REPORT rf_rejig(i)

    DEFINE i INTEGER

    OUTPUT
        { Unusual and distinctive settings }
        TOP MARGIN 4
        BOTTOM MARGIN 4
        LEFT MARGIN 15
        PAGE LENGTH 63

    FORMAT

    FIRST PAGE HEADER
        { Reset report parameters }
		{ Top margin of first page already printed }
        CALL set_output()
        PRINT "First Page Header"

    PAGE HEADER
        PRINT "Other Page Header"

    PAGE TRAILER
        PRINT "Page Trailer"
        PAUSE "Hit return to continue"

    ON EVERY ROW
        PRINT "i = ", i

    ON LAST ROW
        SKIP 1 LINE
        PRINT "Number of rows = ", COUNT(*)

END REPORT {rf_rejig}
