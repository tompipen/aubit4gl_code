include ${AUBITDIR}/incl/header.mki

PROG            = test_im

GLOBALS.4gl     = test_im.4gl

FILES.lib       = lib4glim.c

FILES.4gl       = ${GLOBALS.4gl}

FILES.per       = test_im.per

include ${AUBITDIR}/incl/footer.mki
                 
