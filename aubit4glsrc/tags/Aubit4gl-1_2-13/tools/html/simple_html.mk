ifeq "${AUBITDIR}" ""
	AUBITDIR=../..
endif

include ${AUBITDIR}/incl/header.mki

PROG            = simple_html

GLOBALS.4gl     = libahtmllib.4gl


#FILES.lib       =  libpdf-dummy.o

FILES.4gl       = \
                        ${GLOBALS.4gl} \
                        simple_html.4gl

FILES.per       =


include ${AUBITDIR}/incl/footer.mki
