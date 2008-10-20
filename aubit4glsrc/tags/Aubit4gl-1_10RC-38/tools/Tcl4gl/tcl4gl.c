/* tcl4gl.c
**
**  Copyright (C) 1993 BALTIMORE RH TYPING Laboratory, Inc. All Rights Reserved
**
** Program   :    Tcl4gl library
** File      :    Tcl functions for 4gl
** Functions :
**    NOTE: Some of these functions had to be all lower case because 4GL
**          downshifts function names
**    Tcl4gl_InitInterpList  -- initialize the list of interpreters
**    Tcl4gl_CreateInterp    -- create an interpreter w/ SQL capabilities
**    Tcl4gl_DeleteInterp    -- delete a given interpreter
**    Tcl4gl_Eval            -- evaluate a tcl script
**    Tcl4gl_EvalFile        -- evaluate a file containing a tcl script
**    Tcl4gl_GlobalEval      -- evaluate a tcl script at a global level
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
** $Source: /opt/klaustem/aubit-test/cvs-backup/aubit4gl-backup/aubit4glsrc/tools/Tcl4gl/tcl4gl.c,v $
** $Revision: 1.2 $
** $Date: 2003-05-12 14:24:33 $
**
** $Log: not supported by cvs2svn $
** Revision 1.1  2002/11/28 06:40:46  afalout
** Initial import from IIUG
**
** Revision 1.10  1994/06/06  14:52:29  bkuhn
**   -- added Tcl_DeleteInterp(), typed CheckMalloc()
**
** Revision 1.9  1994/03/25  16:48:42  bkuhn
**   # added Keyed List implentation call
**
** Revision 1.8  1993/12/30  17:06:05  bkuhn
**   -- added Tcl4gl_Init support
**
** Revision 1.7  1993/12/29  16:20:36  bkuhn
**   -- fixed bugs
**
** Revision 1.6  1993/12/29  15:16:09  bkuhn
**   -- commented out delete call
**
** Revision 1.5  1993/12/28  20:31:29  bkuhn
**   -- changed to work w/ Tcl 7.3
**
** Revision 1.4  1993/11/02  16:26:28  bkuhn
**   -- fixed bug for argv processing in tcl_startup
**
** Revision 1.3  1993/11/02  14:32:31  bkuhn
**   -- added support for stripping spaces on tcl_startup
**
** Revision 1.2  1993/11/02  13:18:55  bkuhn
**   -- added Tcl_Startup
**
** Revision 1.1  1993/10/28  17:52:31  bkuhn
**   -- installed version
**
** Revision 0.1  1993/08/23  19:19:42  bkuhn
**   # initial version
**
*/
#include <limits.h>
#include <string.h>
#include "tclExtend.h"
#include "tclsql.h"
#include "tcl4glP.h"

static char rcsid[] = "$Id: tcl4gl.c,v 1.2 2003-05-12 14:24:33 mikeaubury Exp $";

static t_Tcl4glInterp F4glInterp[TCL_INTERP_MAX];
					/* file level global interpreters */

/******************************************************************************
** Tcl4gl_InitInterpList -- initialize the F4glInterp
**   PRECONDITIONS: None
**   POSTCONDITIONS: the F4glInterp array will be initialized
**  This function is private to this file.
*/
static void
Tcl4gl_InitInterpList ()
{
  register int ii;

  for (ii = 0; ii < TCL_INTERP_MAX; ii++)
    {
      F4glInterp[ii].inUse = FALSE;
      F4glInterp[ii].interp = NULL;
    }
  return;
}

/******************************************************************************
** Tcl4gl_CreateInterp -- create a new 4gl-TCL interpreter.
**    PRECONDITIONS: None
**    POSTCONDITIONS: An interpreter will be created and an ID for it will
**                    be returned.
*/
int
tcl4gl_createinterp (numArgs)
     int numArgs;
{
  static bool firstTime = TRUE;
  int ii;
  bool foundNew;

  if (numArgs != 0)
    {
      fprintf (stderr,
	       "tcl4gl_createinterp: wrong # of args(%d); should be %d\n",
	       numArgs, 0);
      exit (-1);
    }
  if (firstTime)
    {
      Tcl4gl_InitInterpList ();
      firstTime = FALSE;
    }
  for (ii = 0, foundNew = FALSE; ii < TCL_INTERP_MAX; ii++)
    {
      foundNew = (!F4glInterp[ii].inUse);
      if (foundNew)
	break;
    }

  if (!foundNew)
    {
      fprintf (stderr,
	       "Out of Tcl interpreters; maximum is %d...Aborting...\n",
	       TCL_INTERP_MAX);
      exit (-1);
    }

  F4glInterp[ii].inUse = TRUE;
  F4glInterp[ii].interp = Tcl_CreateInterp ();

  Tcl_SetVar (F4glInterp[ii].interp, "argv0", "tcl4gl",
	      TCL_GLOBAL_ONLY | TCL_LEAVE_ERR_MSG);

  Tcl_SetVar (F4glInterp[ii].interp, "argv", "",
	      TCL_GLOBAL_ONLY | TCL_LEAVE_ERR_MSG);

  Tcl_SetVar (F4glInterp[ii].interp, "argc", "0",
	      TCL_GLOBAL_ONLY | TCL_LEAVE_ERR_MSG);

  Tcl_SetVar (F4glInterp[ii].interp, "tcl_interactive", "0",
	      TCL_GLOBAL_ONLY | TCL_LEAVE_ERR_MSG);
  TclX_Init (F4glInterp[ii].interp);

  Tcl_Init_Sql (F4glInterp[ii].interp);
  Tcl_Init_KeyL (F4glInterp[ii].interp);
  Tcl4gl_Init (F4glInterp[ii].interp);

  retint (ii);
  return 1;
}

/******************************************************************************
** Tcl4gl_DeleteInterp -- delete a 4gl-TCL interpreter.
**    PRECONDITIONS: the interpreter, interpID, exists
**    POSTCONDITIONS: the interpreter will be destroyed
*/
int
tcl4gl_deleteinterp (numArgs)
     int numArgs;
{
  int interpID;

  if (numArgs != 1)
    {
      fprintf (stderr, "tcl4gl_deleteinterp: wrong # of args (%d)\n",
	       numArgs);
      exit (-1);
    }

  popint (&interpID);
  if ((interpID < 0) || (interpID >= TCL_INTERP_MAX) ||
      (!F4glInterp[interpID].inUse))
    {
      fprintf (stderr, "tcl4gl_eval: invalid interpreter ID (%d)\n",
	       interpID);
      exit (-1);
    }
/* FIX ME ! I commented out the delete because it wasn't working */
  Tcl_DeleteInterp (F4glInterp[interpID].interp);
  F4glInterp[interpID].inUse = FALSE;
  return 0;
}

/******************************************************************************
** Tcl4gl_Eval -- Evaluate a Tcl script
**    PRECONDITIONS: interpID is a valid interpID; len(script) < TCL_STRING_MAX
**    POSTCONDITIONS: script will be evaluated in interpID, the TCL code and
**                    the result from the interpreter will be returned.
*/
int
tcl4gl_eval (numArgs)
     int numArgs;
{
  int interpID;
  char script[TCL_STRING_MAX];
  int retVal = 0;

  if (numArgs != 2)
    {
      fprintf (stderr, "tcl4gl_eval: wrong # of args (%d)\n", numArgs);
      exit (-1);
    }

  popquote (script, TCL_STRING_MAX);

  popint (&interpID);
  if ((interpID < 0) || (interpID >= TCL_INTERP_MAX) ||
      (!F4glInterp[interpID].inUse))
    {
      fprintf (stderr, "tcl4gl_eval: invalid interpreter ID (%d)\n",
	       interpID);
      exit (-1);
    }

  retVal = Tcl_Eval (F4glInterp[interpID].interp, script);
  pushint (retVal);
  pushquote (F4glInterp[interpID].interp->result);
  return 2;
}

/******************************************************************************
** Tcl4gl_EvalFile -- evaluate a file with a given interpreter
**    PRECONDITIONS: interpID is a valid interpID; len(fname) < PATH_MAX
**    POSTCONDITIONS: file will be evaluated in interpID, the TCL code and
**                    the result from the interpreter will be returned.
*/
int
tcl4gl_evalfile (numArgs)
     int numArgs;
{
  char fname[PATH_MAX];
  int interpID;
  int retVal;
  char *ptr = NULL;

  popquote (fname, PATH_MAX);
  ptr = strchr (fname, ' ');	/* remove spaces off the end */
  if (ptr != NULL)
    *ptr = '\0';

  popint (&interpID);
  if ((interpID < 0) || (interpID >= TCL_INTERP_MAX) ||
      (!F4glInterp[interpID].inUse))
    {
      fprintf (stderr, "tcl4gl_evalfile: invalid interpreter ID (%d)\n",
	       interpID);
      exit (-1);
    }

  retVal = Tcl_EvalFile (F4glInterp[interpID].interp, fname);
  retint (retVal);
  retquote (F4glInterp[interpID].interp->result);
  return 2;
}

/******************************************************************************
** Tcl4gl_GlobalEval -- Evaluate a Tcl script globally
**    PRECONDITIONS: interpID is a valid interpID; len(script) < TCL_STRING_MAX
**    POSTCONDITIONS: script will be evaluated in interpID at the global level,
**                    the TCL code and the result from the interpreter will be
**                    returned.
*/
int
tcl4gl_globaleval (numArgs)
     int numArgs;
{
  int interpID;
  char script[TCL_STRING_MAX];
  int retVal;

  if (numArgs != 2)
    {
      fprintf (stderr, "tcl4gl_globaleval: wrong # of args (%d)\n", numArgs);
      exit (-1);
    }

  popquote (script, TCL_STRING_MAX);

  popint (&interpID);
  if ((interpID < 0) || (interpID >= TCL_INTERP_MAX) ||
      (!F4glInterp[interpID].inUse))
    {
      fprintf (stderr, "tcl4gl_globaleval: invalid interpreter ID (%d)\n",
	       interpID);
      exit (-1);
    }

  retVal = Tcl_GlobalEval (F4glInterp[interpID].interp, script);
  pushint (retVal);
  pushquote (F4glInterp[interpID].interp->result);
  return 2;
}

/******************************************************************************
** Tcl4gl_Startup -- Startup a tcl command loop
**    PRECONDITIONS: interpID is a valid interpID.
**    POSTCONDITIONS: a command loop will have been started and executed
*/
int
tcl4gl_startup (numArgs)
     int numArgs;
{
  int interpID;
  char **argv = NULL, *ptr = NULL;
  int argc = 0;
  int ii;

  if (numArgs < 1)
    {
      fprintf (stderr, "tcl4gl_startup: wrong # of args (%d)", numArgs);
      exit (-1);
    }

  argv = (char **) CheckMalloc (numArgs * sizeof (char *));

  while (argc < (numArgs - 1))
    {
      argv[argc++] = (char *) CheckMalloc (TCL_ARG_MAX * sizeof (char));
    }
  argv[argc] = NULL;

  for (ii = argc - 1; ii >= 0; ii--)
    {
      popquote (argv[ii], TCL_ARG_MAX);
      ptr = strchr (argv[ii], ' ');	/* remove spaces off the end */
      if (ptr != NULL)
	*ptr = '\0';
    }

  popint (&interpID);

  if ((interpID < 0) || (interpID >= TCL_INTERP_MAX) ||
      (!F4glInterp[interpID].inUse))
    {
      fprintf (stderr, "tcl4gl_startup: invalid interpreter ID (%d)",
	       interpID);
      exit (-1);
    }

  Tcl_CommandLoop (F4glInterp[interpID].interp, isatty (0));

  for (ii = 0; ii < argc; ii++)
    CheckFree (argv[ii]);
  CheckFree (argv);

  pushquote (F4glInterp[interpID].interp->result);
  return 1;
}
