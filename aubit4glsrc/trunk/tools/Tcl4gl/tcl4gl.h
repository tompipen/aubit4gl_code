/* tcl4gl.h
**
**  Copyright (C) 1993 BALTIMORE RH TYPING Laboratory, Inc. All Rights Reserved
**
** Program   :    Tcl4gl library
** File      :    Header file for Tcl4gl
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
** $Source: /opt/klaustem/aubit-test/cvs-backup/aubit4gl-backup/aubit4glsrc/tools/Tcl4gl/tcl4gl.h,v $
** $Revision: 1.1 $
** $Date: 2002-11-28 06:40:46 $
**
** $Log: not supported by cvs2svn $
** Revision 1.2  1993/11/02  13:24:26  bkuhn
**   -- added Tcl_Startup
**
** Revision 1.1  1993/10/28  18:12:32  bkuhn
**   -- installed version
**
** Revision 0.1  1993/08/23  18:59:08  bkuhn
**   # initial version
**
*/
#ifndef TCL4GL_H
#define TCL4GL_H

#define TCL_INTERP_MAX 20       /* arbitrary maximum number of Tcl_Interps */
#define TCL_STRING_MAX 512      /* arbitrary maximum for Tcl string from 4gl */
#define TCL_ARG_MAX    128      /* arbitrary maximum for args for startup */

/*  function headers */
extern int tcl4gl_deleteinterp();
extern int tcl4gl_eval();
extern int tcl4gl_evalfile();
extern int tcl4gl_globaleval();
extern int tcl4gl_createinterp();
extern int tcl4gl_startup();

#endif
