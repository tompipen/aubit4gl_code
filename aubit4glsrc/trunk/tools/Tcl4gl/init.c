/* hsTcl4gl.c
**
**  Copyright (C) 1993 BALTIMORE RH TYPING Laboratory, Inc. All Rights Reserved
**
** Program   :    HS Tcl4gl library
** File      :    Tcl functions to interface w/ Hogg's Software 4gl libraries
** Functions :
**    Tcl4gl_Init  --  initialize the Tcl-4gl interpreter
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
** $Source: /opt/klaustem/aubit-test/cvs-backup/aubit4gl-backup/aubit4glsrc/tools/Tcl4gl/init.c,v $
** $Revision: 1.1 $
** $Date: 2002-11-28 06:40:46 $
**
** $Log: not supported by cvs2svn $
 * Revision 0.1  1993/12/30  17:47:39  bkuhn
 *   #  initial version
 *
*/
#include <tcl.h>
#include <tclsql.h>
#include "tcl4glP.h"

static char rcsid[] =
  "$Id: init.c,v 1.1 2002-11-28 06:40:46 afalout Exp $";

/*****************************************************************************/
int Tcl4gl_Init(interp)
    Tcl_Interp *interp;
{
    Tcl_CreateCommand(interp, "Hs:Message", Tcl4gl_HsMessageCmd,
                      (ClientData)NULL, (void (*)())NULL);
    Tcl_SetVar(interp, "TCL4GL", "1",
               TCL_GLOBAL_ONLY | TCL_LEAVE_ERR_MSG);
    return TCL_OK;
}
