/* hsTcl4gl.c
**
**  Copyright (C) 1993 BALTIMORE RH TYPING Laboratory, Inc. All Rights Reserved
**
** Program   :    HS Tcl4gl library
** File      :    Tcl functions to interface w/ Hogg's Software 4gl libraries
** Functions :
**    Tcl4gl_HsMessageCmd  -- interface to HsMessage
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
** $Source: /opt/klaustem/aubit-test/cvs-backup/aubit4gl-backup/aubit4glsrc/tools/Tcl4gl/hsTcl4gl.c,v $
** $Revision: 1.2 $
** $Date: 2003-05-12 14:24:33 $
**
** $Log: not supported by cvs2svn $
** Revision 1.1  2002/11/28 06:40:46  afalout
** Initial import from IIUG
**
 * Revision 0.1  1993/12/30  17:02:30  bkuhn
 *   #  initial version
 *
*/
#include <tcl.h>
#include <fglapi.h>

static char rcsid[] =
  "$Id: hsTcl4gl.c,v 1.2 2003-05-12 14:24:33 mikeaubury Exp $";

/*****************************************************************************/
int
Tcl4gl_HsMessageCmd (dummy, interp, argc, argv)
     ClientData dummy;		/* Not used. */
     Tcl_Interp *interp;	/* Current interpreter. */
     int argc;			/* Number of arguments. */
     char **argv;		/* Argument strings. */
{

  Tcl_ResetResult (interp);

  if (argc != 4)
    {
      Tcl_AppendResult (interp, "wrong # of args; should be: ", argv[0],
			" msg1 msg2 msg3", NULL);
      return TCL_ERROR;
    }

  pushquote (argv[1], strlen (argv[1]));
  pushquote (argv[2], strlen (argv[2]));
  pushquote (argv[3], strlen (argv[3]));
  fgl_call (hsmessage, 3);

  return TCL_OK;
}
