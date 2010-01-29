ifeq "${AUBITDIR}" ""
    AUBITDIR=../..
endif

include ${AUBITDIR}/incl/header.mki

PROG            = test_im

GLOBALS.4gl     = test_im.4gl

#if we soecify .c file, it will be deleted in clean
#FILES.lib       = lib4glim.c
FILES.lib       = lib4glim.o

FILES.4gl       = ${GLOBALS.4gl}

FILES.per       = test_im.per

include ${AUBITDIR}/incl/footer.mki
                 
