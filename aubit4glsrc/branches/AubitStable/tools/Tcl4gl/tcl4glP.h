/* tcl4glP.h
**
**  Copyright (C) 1993 BALTIMORE RH TYPING Laboratory, Inc. All Rights Reserved
**
** Program   :    Tcl4gl library
** File      :    Private header file for Tcl4gl
** Functions :
**
** Written   :    Bradley M. Kuhn        Computer Systems Development, Inc.
**   By                                  5916 Glenoak Ave.
**                                       Baltimore, MD 21214-2009
**                                       410-254-7060
**
** Written   :    BALTIMORE RH TYPING Laboratory, Inc.
**   For          400 West Franklin Street
**                Baltimore, MD 21201
**                410-225-9595
**
** RCS        :
** $Source: /opt/klaustem/aubit-test/cvs-backup/aubit4gl-backup/aubit4glsrc/tools/Tcl4gl/tcl4glP.h,v $
** $Revision: 1.2 $
** $Date: 2003-05-12 14:24:33 $
**
** $Log: not supported by cvs2svn $
** Revision 1.1  2002/11/28 06:40:46  afalout
** Initial import from IIUG
**
** Revision 1.2  1993/12/30  16:50:54  bkuhn
**   -- added Tcl4gl_Init support
**
** Revision 1.1  1993/10/28  18:12:47  bkuhn
**   -- installed version
**
** Revision 0.1  1993/08/23  18:24:47  bkuhn
**   # initial version
**
*/
#ifndef TCL4GLP_H
#define TCL4GLP_H

#include "tcl4gl.h"

typedef struct
{
  Tcl_Interp *interp;
  bool inUse;
}
t_Tcl4glInterp;

/* from hsTcl4gl.c */

extern int Tcl4gl_HsMessageCmd ();

/* from init.c */
extern int Tcl4gl_Init ();

#endif
