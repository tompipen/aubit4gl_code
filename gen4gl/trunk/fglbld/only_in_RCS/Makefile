#	@(#)$Id: Makefile,v 1.1.1.1 2002-06-15 05:07:13 afalout Exp $
#
#	Makefile for FGLBLD program

include informix.mk

.AUGMENTED_MAKE:

FORMBUILD.SQL=form4gl
CFLAGS=-O -I${INFORMIXDIR}/incl
RANLIB=ranlib
MOVE=mv

FGLBLDDIR=.

ETCDIR=${FGLBLDDIR}/etc
BINDIR=${FGLBLDDIR}/bin
DOCDIR=${FGLBLDDIR}/doc
LIBDIR=${FGLBLDDIR}/lib
FRMDIR=${FGLBLDDIR}/forms

PROGRAM=fglbld.4ge

ALTFILES=\
	cpopup.alt\
	fglbld.alt\
	mkselect.alt\
	upopup.alt

LIBFILES=\
	dlist.c\
	dlist.h\
	dlistdbl.c\
	dlistdec.c\
	dlistint.c\
	dliststr.c

ETCFILES=\
	informix.mk\
	nxtfield.4gl\
	perfaux.4gl\
	perform.mk\
	perform.msg\
	performc.4gl\
	performg.4gl\
	performm.4gl\
	performr.4gl\
	popstr.c\
	repdest.4gl\
	report.c

BINFILES=\
	fglbld.dst

DOCFILES=\
	dlist.man\
	dlistdbl.man\
	dlistdec.man\
	dlistint.man\
	dliststr.man\
	fglbld.man\
	fglbld.notes

IEMFILES=\
	fglbld.iem

FRMFILES=\
	fglbld.frm\
	fglcpop.frm\
	fglsel.frm\
	fglupop.frm\
	getdbase.frm\
	syscol.frm\
	systab.frm

#
#----------------------------------------------------------------------------
#

all:	${PROGRAM}	directories	install

directories:	${ETCDIR}	${BINDIR}	${LIBDIR}	${DOCDIR}	${FRMDIR}

${ETCDIR} ${BINDIR} ${LIBDIR} ${DOCDIR} ${FRMDIR}:
	if [ ! -d $@ ] ; then mkdir $@ ; fi

install:	${BINFILES} ${ETCFILES} ${LIBFILES} \
			${DOCFILES} ${ALTFILES} ${PROGRAM} ${FRMFILES} ${IEMFILES}
	cd ${ETCDIR} ; rm -f ${ETCFILES} ${LIBFILES}
	${MOVE} ${ETCFILES} ${LIBFILES} ${ETCDIR}
	cd ${ETCDIR} ; chmod 444 ${ETCFILES}
	ln etc/informix.mk .
	cd ${BINDIR} ; rm -f ${BINFILES} ${ALTFILES} ${PROGRAM}
	${MOVE} ${BINFILES} ${ALTFILES} ${PROGRAM} ${BINDIR}
	cd ${BINDIR} ; chmod 555 ${BINFILES} ${ALTFILES} ${PROGRAM}
	cd ${FRMDIR} ; rm -f ${FRMFILES} ${IEMFILES}
	${MOVE} ${FRMFILES} ${IEMFILES} ${FRMDIR}
	cd ${FRMDIR} ; chmod 444 ${FRMFILES} ${IEMFILES}
	cd ${DOCDIR} ; rm -f ${DOCFILES}
	${MOVE} ${DOCFILES} ${DOCDIR}
	cd ${DOCDIR} ; chmod 444 ${DOCFILES}
	chmod 644 Makefile
	@echo
	@echo
	@echo "You should edit the environment variable \$$FGLBLDDIR in fglbld.dst"
	@echo "and install it in your main bin directory as fglbld"
	@echo
	@echo

${PROGRAM}: .FORCE
	${MAKE} -f fglbld.mk $@

.FORCE:

.DEFAULT:
	${MAKE} -f fglbld.mk $@
