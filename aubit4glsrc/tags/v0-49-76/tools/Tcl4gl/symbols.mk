# symbols.mk
#
#  Copyright (C) 1993 BALTIMORE RH TYPING Laboratory, Inc. All Rights Reserved
#
# Program   :    Tcl4gl library
# File      :    Symbols for the makefile
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
# $Source: /opt/klaustem/aubit-test/cvs-backup/aubit4gl-backup/aubit4glsrc/tools/Tcl4gl/symbols.mk,v $
# $Revision: 1.1 $
# $Date: 2002-11-28 06:40:46 $
#
# $Log: not supported by cvs2svn $
# Revision 0.1  1993/08/23  18:57:20  bkuhn
#   # initial version
#
#
#	-----	default CFLAGS						-----
#
CFLAGS = -O -I. -I/usr/local/include

#
#       -----   FILES MACROS                                            -----
#
CFILES = tcl4gl.c hsTcl4gl.c init.c
HFILES = tcl4gl.h	\
	tcl4glP.h
LFILES = 
YFILES = 
MKFILES = rules.mk	\
	symbols.mk

#
#       -----   list of files to put in the library			-----
#
LIBFILES = $(LIBRARY)(tcl4gl.o)  $(LIBRARY)(hsTcl4gl.o) $(LIBRARY)(init.o)

#
#	-----	required for uucp					-----
#
UUDIR	= /usr5/src
UUFILE	= tcl4gl.cpz

