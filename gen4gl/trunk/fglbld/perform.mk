#	WHATSTR
#
#	@(#)Built by: FGLBLDSTR (Makefile)
#
#	Program: Xprog

include informix.mk

######################
# Definitions
######################

# Directive to RMK -- ignored by MAKE
.AUGMENTED_MAKE:

RANLIB=ranlib
LIBDIR=.
LIBRARY=${LIBDIR}/libdlist.a
LDFLAGS=${LIBRARY} -s

LIBOBJECT=\
	${LIBRARY}(checkint.o)\
	${LIBRARY}(Xdlist.o)\
	${LIBRARY}(dlist.o)\
	${LIBRARY}(getenv.o)\
	${LIBRARY}(interr.o)\
	${LIBRARY}(mkfile.o)\
	${LIBRARY}(nxtfield.o)\
	${LIBRARY}(popstr.o)\
	${LIBRARY}(redraw.o)\
	${LIBRARY}(repdest.o)\
	${LIBRARY}(report.o)\
	${LIBRARY}(reptype.o)\
	${LIBRARY}(scrdump.o)\
	${LIBRARY}(scrndump.o)\
	${LIBRARY}(security.o)\
	${LIBRARY}(shell.o)\
	${LIBRARY}(stdopt.o)\
	${LIBRARY}(translog.o)\
	${LIBRARY}(uname.o)

#
# The complete D-list library would contain the following 4 object
# files instead of just the one listed above.
#	${LIBRARY}(dlistint.o)\
#	${LIBRARY}(dliststr.o)\
#	${LIBRARY}(dlistdec.o)\
#	${LIBRARY}(dlistdbl.o)\
#	This comment is necessary on Xenix -- do not ask why

FILES.o=\
	Xprogg.o\
	Xprogc.o\
	Xprogi.o\
#Xopt_rep	Xprogr.o\
	Xprogm.o

FILES.4go=${FILES.o:.o=.4go}

STDFILES.4go=\
	checkint.4go\
	interr.4go\
	nxtfield.4go\
	repdest.4go\
	reptype.4go\
	scrndump.4go\
	security.4go\
	shell.4go\
	stdopt.4go\
	translog.4go

FILES.frm=\
	Xprog.frm\
	repdest.frm\
	scrndump.frm

FILES.iem=\
	Xprog.iem

######################
# Rules
######################

.PRECIOUS:	${LIBRARY}

all:	${FGLBLD_I4GL} makefile
	@if [ -z "${FGLBLD_I4GL}" ] ; then \
	echo "Use: ${MAKE} -f Xprog.mk rds    for I4GL-RDS" ; \
	echo "Use: ${MAKE} -f Xprog.mk c4gl   for I4GL-C" ; \
	fi

makefile:	Xprog.mk
	if [ ! -f makefile ] ; then ln Xprog.mk makefile ; fi

rds:	Xprog.4gi ${FILES.iem} ${FILES.frm}
	@echo "You must use a custom runner with the D-List code etc. in it"

c4gl: Xprog ${FILES.iem} ${FILES.frm}

Xprog.4gi:	${FILES.4go} ${STDFILES.4go}
	cat ${FILES.4go} ${STDFILES.4go} >$@

Xprog:	${FILES.o}	${LIBRARY}
	${C4GL} -o $@ ${FILES.o} ${LDFLAGS}

Xprogc.4go Xprogc.o:	Xprogg.4gl
Xprogi.4go Xprogi.o:	Xprogg.4gl
Xprogm.4go Xprogm.o:	Xprogg.4gl
#Xopt_repXprogr.4go Xprogr.o:	Xprogg.4gl

${LIBRARY}:	${LIBOBJECT}
	-${RANLIB} ${LIBRARY}

dlist.o		${LIBRARY}(dlist.o):	dlist.h
Xdlist.o	${LIBRARY}(Xdlist.o):	dlist.h
#	${LIBRARY}(dlistint.o):	dlist.h
#	${LIBRARY}(dliststr.o):	dlist.h
#	${LIBRARY}(dlistdec.o):	dlist.h
#	${LIBRARY}(dlistdbl.o):	dlist.h
