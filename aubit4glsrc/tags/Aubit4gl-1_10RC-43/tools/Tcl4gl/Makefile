#
#       ----------------------------------------------------------------------
#				makefile
#       ----------------------------------------------------------------------
#
# Program   :	STANDARD C LIBRARY makefile
# Written   :   Gregory F. Hogg         HOGG'S SOFTWARE
#   By                                  1411 My Lady's Drive
#                                       Abingdon, MD 21009
#                                       301-538-7241
# RCS       :
#       $Header: /opt/klaustem/aubit-test/cvs-backup/aubit4gl-backup/aubit4glsrc/tools/Tcl4gl/Makefile,v 1.1 2002-11-28 06:40:46 afalout Exp $
# History   :
#	09/15/90 GFH Create file
#	11/11/90 GFH Copyed unix/4gl files
#

#
#	-----	type, language and default symbols			-----
#	-----	NOTE: must be first and lower case			-----
#
MAKETYPE = lib
MAKELANG = c
include $(MAKEINCLUDE)/symbols.mk

#
#	-----	default FLAGS						-----
#
CC	= cc
CFLAGS	= -I/usr/informix/incl -I/usr5/local/include -I/usr/local/include -O

#
#	-----	library name						-----
#
LIBDIR     = .
LIBNAME    = libtcl4gl
LIBRARY    = $(LIBDIR)/$(LIBNAME).a

.PRECIOUS: $(LIBRARY)

#
#	-----	source files						-----
#
SRCFILES = $(CFILES) $(HFILES) $(LFILES) $(YFILES) \
	$(MKFILES) Makefile

#
#	-----	make library by default					-----
#
first : $(SRCFILES) $(LIBRARY)

#
#	-----	default rules						-----
#	-----	NOTE: must be last					-----
#
include $(MAKEINCLUDE)/rules.mk

