head	1.2;
access;
symbols;
locks; strict;
comment	@# @;


1.2
date	89.08.02.15.46.15;	author john;	state Exp;
branches;
next	1.1;

1.1
date	88.04.21.15.35.33;	author john;	state Exp;
branches;
next	;


desc
@@


1.2
log
@Remove stray tabs
@
text
@{
    @@(#)@@(#)$Id: rejig.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $ 
    @@(#)Sphinx Informix Tools
    @@(#)Example: Set output parameters of I4GL report dynamically
    @@(#)J Leffler
    @@(#)(C) Copyright 1989 Sphinx Ltd.
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
@


1.1
log
@Initial revision
@
text
@d3 1
a3 1
	@@(#)Sphinx Informix Tools
d5 2
a6 2
	@@(#)J Leffler
	@@(#)(C) Copyright 1988 Sphinx Ltd.
@
