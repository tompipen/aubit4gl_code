# rules.mk
#
#  Copyright (C) 1993 BALTIMORE RH TYPING Laboratory, Inc. All Rights Reserved
#
# Program   :    Tcl4gl library
# File      :    Rules for the makefile
#
# Written   :    Bradley M. Kuhn        Computer Systems Development, Inc.
#   By                                  5916 Glenoak Ave.
#                                       Baltimore, MD 21214-2009
#                                       410-254-7060
#
# Written   :    BALTIMORE RH TYPING Laboratory, Inc.
#   For          400 West Franklin Street
#                Baltimore, MD 21201
#                410-225-9595
#
# RCS        :
# $Source: /opt/klaustem/aubit-test/cvs-backup/aubit4gl-backup/aubit4glsrc/tools/Tcl4gl/rules.mk,v $
# $Revision: 1.1 $
# $Date: 2002-11-28 06:40:46 $
#
# $Log: not supported by cvs2svn $
# Revision 0.1  1993/08/23  18:55:32  bkuhn
#   # initial version
#
#
#	-----	local rules						-----
#

#
#	-----	START H FILES						-----
#
tcl4glP.h	:  tcl4gl.h
tcl4gl.o	: tcl4gl.c 
#
#	-----	STOP H FILES						-----
#

install:
	cp $(LIBRARY) /usr/local/lib
	chmod 644 /usr/local/lib/$(LIBRARY)
	cp tcl4gl.h /usr/local/include
	chmod 644 /usr/local/include/tcl4gl.h

ci:
	ci -d -M $(CFILES) $(ECFILES) $(HFILES) $(TCLLIBS)

co:
	co -M $(CFILES) $(ECFILES) $(HFILES) $(TCLLIBS)
cico:
	ci -d -M -u $(CFILES) $(ECFILES) $(HFILES) $(TCLLIBS)
tags:
	etags -t $(CFILES) $(ECFILES) $(HFILES) $(TCLLIBS)
